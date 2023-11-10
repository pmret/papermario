import os
import re
from functools import lru_cache
from pathlib import Path
from typing import Dict, List, OrderedDict, Set, Tuple, Union

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

    if not str(path).startswith(str(options.opts.build_path)):
        path = options.opts.build_path / path
    return clean_up_path(path.with_suffix(full_suffix))


def write_file_if_different(path: Path, new_content: str):
    if path.exists():
        old_content = path.read_text()
    else:
        old_content = ""

    if old_content != new_content:
        path.parent.mkdir(parents=True, exist_ok=True)
        with path.open("w") as f:
            f.write(new_content)


def get_segment_rom_start(cname: str) -> str:
    if options.opts.segment_symbols_style == "makerom":
        return f"_{cname}SegmentRomStart"
    return f"{cname}_ROM_START"


def get_segment_rom_end(cname: str) -> str:
    if options.opts.segment_symbols_style == "makerom":
        return f"_{cname}SegmentRomEnd"
    return f"{cname}_ROM_END"


def get_segment_vram_start(cname: str) -> str:
    if options.opts.segment_symbols_style == "makerom":
        return f"_{cname}SegmentStart"
    return f"{cname}_VRAM"


def get_segment_vram_end(cname: str) -> str:
    if options.opts.segment_symbols_style == "makerom":
        return f"_{cname}SegmentEnd"
    return f"{cname}_VRAM_END"


def convert_section_name_to_linker_format(section_type: str) -> str:
    assert section_type.startswith(".")
    if options.opts.segment_symbols_style == "makerom":
        if section_type == ".rodata":
            return "RoData"
        return section_type[1:].capitalize()

    return to_cname(section_type.upper())


def get_segment_section_start(segment_name: str, section_type: str) -> str:
    sec = convert_section_name_to_linker_format(section_type)
    if options.opts.segment_symbols_style == "makerom":
        return f"_{segment_name}Segment{sec}Start"
    return f"{segment_name}{sec}_START"


def get_segment_section_end(segment_name: str, section_type: str) -> str:
    sec = convert_section_name_to_linker_format(section_type)
    if options.opts.segment_symbols_style == "makerom":
        return f"_{segment_name}Segment{sec}End"
    return f"{segment_name}{sec}_END"


def get_segment_section_size(segment_name: str, section_type: str) -> str:
    sec = convert_section_name_to_linker_format(section_type)
    if options.opts.segment_symbols_style == "makerom":
        return f"_{segment_name}Segment{sec}Size"
    return f"{segment_name}{sec}_SIZE"


def get_segment_vram_end_symbol_name(segment: Segment) -> str:
    return get_segment_vram_end(segment.get_cname())


class LinkerEntry:
    def __init__(
        self,
        segment: Segment,
        src_paths: List[Path],
        object_path: Path,
        section_order: str,
        section_link: str,
        noload: bool = False,
    ):
        self.segment = segment
        self.src_paths = [clean_up_path(p) for p in src_paths]
        self.section_order = section_order
        self.section_link = section_link
        self.noload = noload
        self.bss_contains_common = segment.bss_contains_common
        if self.section_link == "linker" or self.section_link == "linker_offset":
            self.object_path = None
        elif self.segment.type == "lib":
            self.object_path = object_path
        else:
            self.object_path = path_to_object_path(object_path)

    @property
    def section_order_type(self) -> str:
        if self.section_order == ".rdata":
            return ".rodata"
        else:
            return self.section_order

    @property
    def section_link_type(self) -> str:
        if self.section_link == ".rdata":
            return ".rodata"
        else:
            return self.section_link


class LinkerWriter:
    def __init__(self, is_partial: bool = False):
        self.linker_discard_section: bool = options.opts.ld_discard_section
        self.sections_allowlist: List[str] = options.opts.ld_sections_allowlist
        self.sections_denylist: List[str] = options.opts.ld_sections_denylist
        # Used to store all the linker entries - build tools may want this information
        self.entries: List[LinkerEntry] = []
        self.dependencies_entries: List[LinkerEntry] = []

        self.buffer: List[str] = []
        self.header_symbols: Set[str] = set()

        self.is_partial: bool = is_partial

        self._indent_level = 0

        self._writeln("SECTIONS")
        self._begin_block()

        if not self.is_partial:
            self._writeln(f"__romPos = {options.opts.ld_rom_start};")

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
        self.dependencies_entries.extend(entries)

        seg_name = segment.get_cname()

        for sym, segs in max_vram_syms:
            self.write_max_vram_end_sym(sym, segs)

        if options.opts.ld_legacy_generation:
            self.add_legacy(segment, entries)
            return

        section_entries: OrderedDict[str, List[LinkerEntry]] = OrderedDict()
        for l in segment.section_order:
            if l in options.opts.ld_section_labels:
                section_entries[l] = []

        # Add all entries to section_entries
        prev_entry = None
        for entry in entries:
            if entry.section_order_type in section_entries:
                # Search for the very first section type
                # This is required in case the very first entry is a type that's not listed on ld_section_labels (like linker_offset) because it would be dropped
                prev_entry = entry.section_order_type
                break

        any_load = False
        any_noload = False
        for entry in entries:
            if entry.section_order_type in section_entries:
                section_entries[entry.section_order_type].append(entry)
            elif prev_entry is not None:
                # If this section is not present in section_order or ld_section_labels then pretend it is part of the last seen section, mainly for handling linker_offset
                section_entries[prev_entry].append(entry)
            any_load = any_load or not entry.noload
            any_noload = any_noload or entry.noload
            prev_entry = entry.section_order_type

        seg_rom_start = get_segment_rom_start(seg_name)
        self._write_symbol(seg_rom_start, "__romPos")

        is_first = True
        if any_load:
            # Only emit normal segment if there's at least one normal entry
            self._write_segment_sections(
                segment, seg_name, section_entries, noload=False, is_first=is_first
            )
            is_first = False

        if any_noload:
            # Only emit NOLOAD segment if there is at least one noload entry
            self._write_segment_sections(
                segment, seg_name, section_entries, noload=True, is_first=is_first
            )
            is_first = False

        self._end_segment(segment, all_bss=not any_load)

    def add_legacy(self, segment: Segment, entries: List[LinkerEntry]):
        seg_name = segment.get_cname()

        # To keep track which sections has been started
        started_sections: Dict[str, bool] = {
            l: False for l in options.opts.ld_section_labels
        }

        # Find where sections are last seen
        last_seen_sections: Dict[LinkerEntry, str] = {}
        for entry in reversed(entries):
            if (
                entry.section_order_type in options.opts.ld_section_labels
                and entry.section_order_type not in last_seen_sections.values()
            ):
                last_seen_sections[entry] = entry.section_order_type

        seg_rom_start = get_segment_rom_start(seg_name)
        self._write_symbol(seg_rom_start, "__romPos")

        self._begin_segment(segment, seg_name, noload=False, is_first=True)

        i = 0
        for entry in entries:
            if entry.noload:
                break

            started = started_sections.get(entry.section_order_type, True)
            if not started:
                self._begin_section(seg_name, entry.section_order_type)
                started_sections[entry.section_order_type] = True

            self._write_linker_entry(entry)

            if entry in last_seen_sections:
                self._end_section(seg_name, entry.section_order_type)

            i += 1

        if any(entry.noload for entry in entries):
            self._end_block()

            self._begin_segment(segment, seg_name, noload=True, is_first=False)

            for entry in entries[i:]:
                started = started_sections.get(entry.section_order_type, True)
                if not started:
                    self._begin_section(seg_name, entry.section_order_type)
                    started_sections[entry.section_order_type] = True

                self._write_linker_entry(entry)

                if entry in last_seen_sections:
                    self._end_section(seg_name, entry.section_order_type)

        self._end_segment(segment, all_bss=False)

    def add_referenced_partial_segment(
        self, segment: Segment, max_vram_syms: List[Tuple[str, List[Segment]]]
    ):
        entries = segment.get_linker_entries()
        self.entries.extend(entries)

        segments_path = options.opts.ld_partial_build_segments_path
        assert segments_path is not None

        seg_name = segment.get_cname()

        for sym, segs in max_vram_syms:
            self.write_max_vram_end_sym(sym, segs)

        seg_rom_start = get_segment_rom_start(seg_name)
        self._write_symbol(seg_rom_start, "__romPos")

        any_load = any(not e.noload for e in entries)
        is_first = True
        if any_load:
            # Only emit normal segment if there's at least one normal entry

            self._begin_segment(segment, seg_name, noload=False, is_first=is_first)

            for l in segment.section_order:
                if l not in options.opts.ld_section_labels:
                    continue
                if l == ".bss":
                    continue

                entry = LinkerEntry(
                    segment, [], segments_path / f"{seg_name}.o", l, l, noload=False
                )
                self.dependencies_entries.append(entry)
                self._write_linker_entry(entry)
            is_first = False

        if any(e.noload for e in entries):
            # Only emit NOLOAD segment if there is at least one noload entry

            if not is_first:
                self._end_block()

            self._begin_segment(segment, seg_name, noload=True, is_first=is_first)

            # Check if any section has the bss_contains_common option
            bss_contains_common = False
            for entry in entries:
                if entry.segment.bss_contains_common:
                    bss_contains_common = True
                    break

            entry = LinkerEntry(
                segment,
                [],
                segments_path / f"{seg_name}.o",
                ".bss",
                ".bss",
                noload=True,
            )
            entry.bss_contains_common = bss_contains_common
            self.dependencies_entries.append(entry)
            self._write_linker_entry(entry)

        self._end_segment(segment, all_bss=not any_load)

    def add_partial_segment(self, segment: Segment):
        entries = segment.get_linker_entries()
        self.entries.extend(entries)
        self.dependencies_entries.extend(entries)

        seg_name = segment.get_cname()

        section_entries: OrderedDict[str, List[LinkerEntry]] = OrderedDict()
        for l in segment.section_order:
            if l in options.opts.ld_section_labels:
                section_entries[l] = []

        # Add all entries to section_entries
        prev_entry = None
        for entry in entries:
            if entry.section_order_type in section_entries:
                section_entries[entry.section_order_type].append(entry)
            elif prev_entry is not None:
                # If this section is not present in section_order or ld_section_labels then pretend it is part of the last seen section, mainly for handling linker_offset
                section_entries[prev_entry].append(entry)
            prev_entry = entry.section_order_type

        for section_name, entries in section_entries.items():
            if len(entries) == 0:
                continue
            first_entry = entries[0]

            self._begin_partial_segment(section_name, segment, first_entry.noload)

            self._begin_section(seg_name, section_name)

            for entry in entries:
                self._write_linker_entry(entry)

            self._end_section(seg_name, section_name)

            self._end_partial_segment(section_name)

    def save_linker_script(self, output_path: Path):
        if len(self.sections_allowlist) > 0:
            address = " 0"
            if self.is_partial:
                address = ""
            for sect in self.sections_allowlist:
                self._writeln(f"{sect}{address} :")
                self._begin_block()
                self._writeln(f"*({sect});")
                self._end_block()

            self._writeln("")

        if self.linker_discard_section or len(self.sections_denylist) > 0:
            self._writeln("/DISCARD/ :")
            self._begin_block()
            for sect in self.sections_denylist:
                self._writeln(f"*({sect});")
            if self.linker_discard_section:
                self._writeln("*(*);")
            self._end_block()

        self._end_block()  # SECTIONS

        assert self._indent_level == 0

        write_file_if_different(output_path, "\n".join(self.buffer) + "\n")

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
                + "".join(
                    f"extern Addr {symbol};\n" for symbol in sorted(self.header_symbols)
                )
                + "\n"
                "#endif\n",
            )

    def save_dependencies_file(self, output_path: Path, target_elf_path: Path):
        output = f"{target_elf_path}:"

        for entry in self.dependencies_entries:
            if entry.object_path is None:
                continue
            output += f" \\\n    {entry.object_path}"

        output += "\n"
        for entry in self.dependencies_entries:
            if entry.object_path is None:
                continue
            output += f"{entry.object_path}:\n"
        write_file_if_different(output_path, output)

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

    def _begin_segment(
        self, segment: Segment, seg_name: str, noload: bool, is_first: bool
    ):
        if (
            options.opts.ld_use_symbolic_vram_addresses
            and segment.vram_symbol is not None
        ):
            vram_str = segment.vram_symbol + " "
        else:
            vram_str = (
                f"0x{segment.vram_start:X} "
                if isinstance(segment.vram_start, int)
                else ""
            )

        addr_str = " "
        if is_first:
            addr_str += f"{vram_str}"
        if noload:
            seg_name += "_bss"
            addr_str += "(NOLOAD) "

        seg_vram_start = get_segment_vram_start(seg_name)
        self._write_symbol(seg_vram_start, f"ADDR(.{seg_name})")

        line = f".{seg_name}{addr_str}:"
        if not noload:
            seg_rom_start = get_segment_rom_start(seg_name)
            line += f" AT({seg_rom_start})"
        if segment.subalign != None:
            line += f" SUBALIGN({segment.subalign})"

        self._writeln(line)
        self._begin_block()

        if segment.ld_fill_value is not None:
            self._writeln(f"FILL(0x{segment.ld_fill_value:08X});")

    def _end_segment(self, segment: Segment, all_bss=False):
        self._end_block()

        name = segment.get_cname()

        if not all_bss:
            self._writeln(f"__romPos += SIZEOF(.{name});")

        # Align directive
        if not options.opts.segment_end_before_align:
            if segment.align:
                self._writeln(f"__romPos = ALIGN(__romPos, {segment.align});")

        seg_rom_end = get_segment_rom_end(name)
        self._write_symbol(seg_rom_end, "__romPos")
        self._write_symbol(get_segment_vram_end_symbol_name(segment), ".")

        # Align directive
        if options.opts.segment_end_before_align:
            if segment.align:
                self._writeln(f"__romPos = ALIGN(__romPos, {segment.align});")

        self._writeln("")

    def _begin_partial_segment(self, section_name: str, segment: Segment, noload: bool):
        line = f"{section_name}"
        if noload:
            line += " (NOLOAD)"
        line += " :"
        if segment.subalign != None:
            line += f" SUBALIGN({segment.subalign})"

        self._writeln(line)
        self._begin_block()

    def _end_partial_segment(self, section_name: str, all_bss=False):
        self._end_block()

        self._writeln("")

    def _begin_section(self, seg_name: str, cur_section: str) -> None:
        section_start = get_segment_section_start(seg_name, cur_section)
        self._write_symbol(section_start, ".")

    def _end_section(self, seg_name: str, cur_section: str) -> None:
        section_start = get_segment_section_start(seg_name, cur_section)
        section_end = get_segment_section_end(seg_name, cur_section)
        section_size = get_segment_section_size(seg_name, cur_section)
        self._write_symbol(section_end, ".")
        self._write_symbol(
            section_size,
            f"ABSOLUTE({section_end} - {section_start})",
        )

    def _write_linker_entry(self, entry: LinkerEntry):
        if entry.section_link_type == "linker_offset":
            self._write_symbol(f"{entry.segment.get_cname()}_OFFSET", ".")
            return

        # TODO: option to turn this off?
        if (
            entry.object_path
            and entry.section_link_type == ".data"
            and entry.segment.type != "lib"
        ):
            path_cname = re.sub(
                r"[^0-9a-zA-Z_]",
                "_",
                str(entry.segment.dir / entry.segment.name)
                + ".".join(entry.object_path.suffixes[:-1]),
            )
            self._write_symbol(path_cname, ".")

        if entry.noload and entry.bss_contains_common:
            self._writeln(f"{entry.object_path}(.bss COMMON .scommon);")
        else:
            wildcard = "*" if options.opts.ld_wildcard_sections else ""

            self._writeln(f"{entry.object_path}({entry.section_link}{wildcard});")

    def _write_segment_sections(
        self,
        segment: Segment,
        seg_name: str,
        section_entries: OrderedDict[str, List[LinkerEntry]],
        noload: bool,
        is_first: bool,
    ):
        if not is_first:
            self._end_block()

        self._begin_segment(segment, seg_name, noload=noload, is_first=is_first)

        for section_name, entries in section_entries.items():
            if len(entries) == 0:
                continue

            first_entry = entries[0]
            if first_entry.noload != noload:
                continue

            self._begin_section(seg_name, section_name)
            for entry in entries:
                self._write_linker_entry(entry)
            self._end_section(seg_name, section_name)
