import os
import re
from dataclasses import dataclass
from functools import lru_cache
from pathlib import Path
from typing import Dict, List, OrderedDict, Set, Tuple, Union
from segtypes.n64.palette import N64SegPalette

from util import options

from segtypes.segment import Segment
from util.symbols import to_cname


# clean 'foo/../bar' to 'bar'
@lru_cache(maxsize=None)
def clean_up_path(path: Path) -> Path:
    path_resolved = path.resolve()
    base_resolved = options.opts.base_path.resolve()
    try:
        return path_resolved.relative_to(base_resolved)
    except ValueError:
        pass

    # If the path wasn't relative to the splat file, use the working directory instead
    cwd = Path(os.getcwd())
    try:
        return path_resolved.relative_to(cwd)
    except ValueError:
        pass

    # If it wasn't relative to that too, then just return the path as-is
    return path


def path_to_object_path(path: Path) -> Path:
    path = clean_up_path(path)
    if options.opts.use_o_as_suffix:
        full_suffix = ".o"
    else:
        full_suffix = path.suffix + ".o"
    return clean_up_path(options.opts.build_path / path.with_suffix(full_suffix))


def write_file_if_different(path: Path, new_content: str):
    if path.exists():
        old_content = path.read_text()
    else:
        old_content = ""

    if old_content != new_content:
        path.parent.mkdir(parents=True, exist_ok=True)
        with path.open("w") as f:
            f.write(new_content)


def segment_cname(segment: Segment) -> str:
    name = segment.name
    if segment.parent:
        name = segment.parent.name + "_" + name

    if isinstance(segment, N64SegPalette):
        name += "_pal"

    return to_cname(name)


def get_segment_vram_end_symbol_name(segment: Segment) -> str:
    return segment_cname(segment) + "_VRAM_END"


@dataclass
class LinkerSection:
    name: str
    started: bool = False
    ended: bool = False

    @property
    def section_type(self) -> str:
        if self.name == ".rdata":
            return ".rodata"
        return self.name


class LinkerEntry:
    def __init__(
        self, segment: Segment, src_paths: List[Path], object_path: Path, section: str
    ):
        self.segment = segment
        self.src_paths = [clean_up_path(p) for p in src_paths]
        self.section = section
        if self.section == "linker" or self.section == "linker_offset":
            self.object_path = None
        elif self.segment.type == "lib":
            self.object_path = object_path
        else:
            self.object_path = path_to_object_path(object_path)

    @property
    def section_type(self) -> str:
        if self.section == ".rdata":
            return ".rodata"
        else:
            return self.section


class LinkerWriter:
    def __init__(self):
        self.linker_discard_section: bool = options.opts.ld_discard_section
        # Used to store all the linker entries - build tools may want this information
        self.entries: List[LinkerEntry] = []

        self.buffer: List[str] = []
        self.header_symbols: Set[str] = set()

        self._indent_level = 0

        self._writeln("SECTIONS")
        self._begin_block()
        self._writeln("__romPos = 0;")

        if options.opts.gp is not None:
            self._writeln("_gp = " + f"0x{options.opts.gp:X};")

    # Write a series of statements which compute a symbol that represents the highest address among a list of segments' end addresses
    def write_max_vram_end_sym(self, symbol: str, overlays: List[Segment]):
        for segment in overlays:
            if segment == overlays[0]:
                self._writeln(
                    f"{symbol} = {get_segment_vram_end_symbol_name(segment)};"
                )
            else:
                self._writeln(
                    f"{symbol} = MAX({symbol}, {get_segment_vram_end_symbol_name(segment)});"
                )

    # Adds all the entries of a segment to the linker script buffer
    def add(self, segment: Segment, max_vram_syms: List[Tuple[str, List[Segment]]]):
        entries = segment.get_linker_entries()
        self.entries.extend(entries)

        seg_name = segment_cname(segment)

        for sym, segs in max_vram_syms:
            self.write_max_vram_end_sym(sym, segs)

        section_labels: OrderedDict[str, LinkerSection] = OrderedDict(
            {
                l: LinkerSection(l)
                for l in options.opts.section_order
                if l in options.opts.ld_section_labels
            }
        )

        # Start the first linker section

        self._write_symbol(f"{seg_name}_ROM_START", "__romPos")

        if entries[0].section_type == ".bss":
            self._begin_bss_segment(segment, is_first=True)
            self._write_symbol(f"{seg_name}_BSS_START", ".")
            if ".bss" in section_labels:
                section_labels[".bss"].started = True
        else:
            self._begin_segment(segment)

        last_seen_sections: Dict[LinkerEntry, str] = {}

        # Find where sections are last seen
        for entry in reversed(entries):
            if (
                entry.section_type in section_labels.keys()
                and entry.section_type not in last_seen_sections.values()
            ):
                last_seen_sections[entry] = entry.section_type

        cur_section = None
        prev_section = None
        for entry in entries:
            entering_bss = False
            leaving_bss = False
            cur_section = entry.section_type

            if cur_section == "linker_offset":
                self._write_symbol(f"{segment_cname(entry.segment)}_OFFSET", ".")
                continue

            for i, section in enumerate(section_labels.values()):
                # If we haven't seen this section yet
                if not section.started and section.section_type == entry.section_type:
                    if prev_section == ".bss":
                        leaving_bss = True
                    elif cur_section == ".bss":
                        entering_bss = True

                    if not (
                        entering_bss or leaving_bss
                    ):  # Don't write a START symbol if we are about to end the section
                        self._write_symbol(
                            f"{seg_name}{entry.section_type.upper()}_START", "."
                        )
                        section_labels[entry.section_type].started = True

            if (
                entry.object_path
                and cur_section == ".data"
                and entry.segment.type != "lib"
            ):
                path_cname = re.sub(
                    r"[^0-9a-zA-Z_]",
                    "_",
                    str(entry.segment.dir / entry.segment.name)
                    + ".".join(entry.object_path.suffixes[:-1]),
                )
                self._write_symbol(path_cname, ".")

            wildcard = "*" if options.opts.ld_wildcard_sections else ""

            # Create new linker section for BSS
            if entering_bss or leaving_bss:
                # If this is the last entry of its type, add the END marker for the section we're ending
                if (
                    entry in last_seen_sections
                    and section_labels[entry.section_type].started
                ):
                    seg_name_section = to_cname(
                        f"{seg_name}{last_seen_sections[entry].upper()}"
                    )
                    self._write_symbol(f"{seg_name_section}_END", ".")
                    self._write_symbol(
                        f"{seg_name_section}_SIZE",
                        f"ABSOLUTE({seg_name_section}_END - {seg_name_section}_START)",
                    )
                    section_labels[last_seen_sections[entry]].ended = True

                self._end_block()

                if entering_bss:
                    self._begin_bss_segment(segment)
                else:
                    self._begin_segment(segment)

                self._write_symbol(f"{seg_name}{entry.section_type.upper()}_START", ".")
                section_labels[cur_section].started = True

                # Write THIS linker entry
                self._writeln(f"{entry.object_path}({entry.section}{wildcard});")
            else:
                # Write THIS linker entry
                if entry.section == ".bss" and entry.segment.bss_contains_common:
                    self._writeln(f"{entry.object_path}(.bss COMMON .scommon);")
                else:
                    self._writeln(f"{entry.object_path}({entry.section}{wildcard});")

                # If this is the last entry of its type, add the END marker for the section we're ending
                if entry in last_seen_sections:
                    seg_name_section = to_cname(f"{seg_name}{cur_section.upper()}")
                    self._write_symbol(f"{seg_name_section}_END", ".")
                    self._write_symbol(
                        f"{seg_name_section}_SIZE",
                        f"ABSOLUTE({seg_name_section}_END - {seg_name_section}_START)",
                    )
                    section_labels[cur_section].ended = True

            prev_section = cur_section

        # End all un-ended sections
        for section in section_labels.values():
            if section.started and not section.ended:
                seg_name_section = to_cname(f"{seg_name}{section.name.upper()}")
                self._write_symbol(f"{seg_name_section}_END", ".")
                self._write_symbol(
                    f"{seg_name_section}_SIZE",
                    f"ABSOLUTE({seg_name_section}_END - {seg_name_section}_START)",
                )

        all_bss = all(e.section == ".bss" for e in entries)
        self._end_segment(segment, all_bss)

    def save_linker_script(self):
        if self.linker_discard_section:
            self._writeln("/DISCARD/ :")
            self._begin_block()
            self._writeln("*(*);")
            self._end_block()

        self._end_block()  # SECTIONS

        assert self._indent_level == 0

        write_file_if_different(
            options.opts.ld_script_path, "\n".join(self.buffer) + "\n"
        )

    def save_symbol_header(self):
        path = options.opts.ld_symbol_header_path

        if path:
            write_file_if_different(
                path,
                "#ifndef _HEADER_SYMBOLS_H_\n"
                "#define _HEADER_SYMBOLS_H_\n"
                "\n"
                '#include "common.h"\n'
                "\n"
                + "".join(f"extern Addr {symbol};\n" for symbol in self.header_symbols)
                + "\n"
                "#endif\n",
            )

    def _writeln(self, line: str):
        if len(line) == 0:
            self.buffer.append(line)
        else:
            self.buffer.append("    " * self._indent_level + line)

    def _begin_block(self):
        self._writeln("{")
        self._indent_level += 1

    def _end_block(self):
        self._indent_level -= 1
        self._writeln("}")

    def _write_symbol(self, symbol: str, value: Union[str, int]):
        symbol = to_cname(symbol)

        if isinstance(value, int):
            value = f"0x{value:X}"

        self._writeln(f"{symbol} = {value};")

        self.header_symbols.add(symbol)

    def _begin_segment(self, segment: Segment):
        if options.opts.ld_use_follows and segment.vram_of_symbol:
            vram_str = segment.vram_of_symbol + " "
        else:
            vram_str = (
                f"0x{segment.vram_start:X} "
                if isinstance(segment.vram_start, int)
                else ""
            )

        name = segment_cname(segment)

        self._write_symbol(f"{name}_VRAM", f"ADDR(.{name})")

        line = f".{name} {vram_str}: AT({name}_ROM_START)"
        if segment.subalign != None:
            line += f" SUBALIGN({segment.subalign})"

        self._writeln(line)
        self._begin_block()

    def _begin_bss_segment(self, segment: Segment, is_first: bool = False):
        if options.opts.ld_use_follows and segment.vram_of_symbol:
            vram_str = segment.vram_of_symbol + " "
        else:
            vram_str = (
                f"0x{segment.vram_start:X} "
                if isinstance(segment.vram_start, int)
                else ""
            )

        name = segment_cname(segment) + "_bss"

        self._write_symbol(f"{name}_VRAM", f"ADDR(.{name})")

        if is_first:
            addr_str = vram_str + "(NOLOAD)"
        else:
            addr_str = "(NOLOAD)"

        line = f".{name} {addr_str} :"
        if segment.subalign != None:
            line += f" SUBALIGN({segment.subalign})"

        self._writeln(line)
        self._begin_block()

    def _end_segment(self, segment: Segment, all_bss=False):
        self._end_block()

        name = segment_cname(segment)

        if not all_bss:
            self._writeln(f"__romPos += SIZEOF(.{name});")

        # Align directive
        if not options.opts.segment_end_before_align:
            if segment.align:
                self._writeln(f"__romPos = ALIGN(__romPos, {segment.align});")

        self._write_symbol(f"{name}_ROM_END", "__romPos")
        self._write_symbol(get_segment_vram_end_symbol_name(segment), ".")

        # Align directive
        if options.opts.segment_end_before_align:
            if segment.align:
                self._writeln(f"__romPos = ALIGN(__romPos, {segment.align});")

        self._writeln("")
