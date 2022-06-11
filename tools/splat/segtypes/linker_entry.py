from typing import Union, List
from pathlib import Path
from segtypes.common.data import CommonSegData
from segtypes.common.linker_section import LinkerSection, dotless_type
from segtypes.n64.img import N64SegImg
from segtypes.n64.palette import N64SegPalette
from util import options
from segtypes.segment import Segment
import os
import re

# clean 'foo/../bar' to 'bar'
def clean_up_path(path: Path) -> Path:
    path_resolved = path.resolve()
    base_resolved = options.get_base_path().resolve()
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
    if options.use_o_as_suffix():
        full_suffix = ".o"
    else:
        full_suffix = path.suffix + ".o"
    return clean_up_path(options.get_build_path() / path.with_suffix(full_suffix))


def write_file_if_different(path: Path, new_content: str):
    if path.exists():
        old_content = path.read_text()
    else:
        old_content = ""

    if old_content != new_content:
        path.parent.mkdir(parents=True, exist_ok=True)
        with path.open("w") as f:
            f.write(new_content)


def to_cname(symbol: str) -> str:
    symbol = re.sub(r"[^0-9a-zA-Z_]", "_", symbol)

    if symbol[0] in ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]:
        symbol = "_" + symbol

    return symbol


def get_segment_cname(segment: Segment) -> str:
    name = segment.name
    if segment.parent:
        name = segment.parent.name + "_" + name

    if isinstance(segment, N64SegPalette):
        name += "_pal"

    return to_cname(name)


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


class LinkerWriter:
    def __init__(self):
        self.shiftable: bool = options.get_shiftable()
        self.linker_discard_section: bool = options.linker_discard_section()
        self.entries: List[LinkerEntry] = []

        self.buffer: List[str] = []
        self.symbols: List[str] = []

        self._indent_level = 0

        self._writeln("SECTIONS")
        self._begin_block()

        if options.get_gp() is not None:
            self._writeln("_gp = " + f"0x{options.get_gp():X};")

    def add(self, segment: Segment):
        entries = segment.get_linker_entries()
        self.entries.extend(entries)

        self._begin_segment(segment)

        seg_name = get_segment_cname(segment)

        section_labels = [
            LinkerSection(l)
            for l in options.ld_section_labels()
            if l in options.get_section_order()
        ]

        force_new_section = False
        cur_section = None

        for i, entry in enumerate(entries):
            cur_section = entry.section

            if cur_section == "linker":  # TODO: isinstance is preferable
                self._end_block()
                self._begin_segment(entry.segment)
                continue
            elif cur_section == "linker_offset":
                self._write_symbol(
                    f"{get_segment_cname(entry.segment)}_OFFSET",
                    f". - {get_segment_cname(segment)}_ROM_START",
                )
                continue

            for i, section in enumerate(section_labels):
                if not section.started and section.name == cur_section:
                    if i > 0:
                        if not section_labels[i - 1].ended:
                            section_labels[i - 1].ended = True
                            self._write_symbol(
                                f"{seg_name}{section_labels[i - 1].name.upper()}_END",
                                ".",
                            )
                    section.started = True
                    self._write_symbol(f"{seg_name}{section.name.upper()}_START", ".")

            if options.enable_ld_alignment_hack():
                start = entry.segment.rom_start
                if isinstance(start, int):
                    # Create new sections for non-subalign alignment (hack)
                    if start % 0x10 != 0 and i != 0 or force_new_section:
                        self._end_block()
                        self._begin_segment(entry.segment, mid_segment=True)
                        force_new_section = False

                    if start % 0x10 != 0 and i != 0:
                        force_new_section = True

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

            # Write out manual entries for images inside .data segments
            seg = entry.segment
            if isinstance(seg, CommonSegData):
                for subseg in seg.subsegments:
                    if isinstance(subseg, N64SegImg):
                        self._write_symbol(
                            get_segment_cname(subseg), f"0x{subseg.rom_start:X}"
                        )

            self._writeln(f"{entry.object_path}({cur_section});")

        for section in section_labels:
            if section.started and not section.ended:
                self._write_symbol(
                    f"{seg_name}_{dotless_type(section.name).upper()}_END", "."
                )

        self._end_segment(segment)

    def save_linker_script(self):
        if self.linker_discard_section:
            self._writeln("/DISCARD/ :")
            self._begin_block()
            self._writeln("*(*);")
            self._end_block()

        self._end_block()  # SECTIONS

        assert self._indent_level == 0

        write_file_if_different(
            options.get_ld_script_path(), "\n".join(self.buffer) + "\n"
        )

    def save_symbol_header(self):
        path = options.get_linker_symbol_header_path()

        if path:
            write_file_if_different(
                path,
                "#ifndef _HEADER_SYMBOLS_H_\n"
                "#define _HEADER_SYMBOLS_H_\n"
                "\n"
                '#include "common.h"\n'
                "\n"
                + "".join(f"extern Addr {symbol};\n" for symbol in self.symbols)
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

        if symbol not in self.symbols:
            self.symbols.append(symbol)

    def _begin_segment(self, segment: Segment, mid_segment=False):
        # force location if not shiftable/auto
        if not self.shiftable and isinstance(segment.rom_start, int):
            self._writeln(f"__romPos = 0x{segment.rom_start:X};")
        else:
            # TODO: align 0x10, preferably
            pass

        self._writeln(f". = __romPos;")

        vram = segment.vram_start
        vram_str = f"0x{vram:X} " if isinstance(vram, int) else ""

        name = get_segment_cname(segment)

        if mid_segment:
            name += to_cname(segment.type)

        self._write_symbol(f"{name}_ROM_START", "__romPos")
        self._write_symbol(f"{name}_VRAM", f"ADDR(.{name})")

        self._writeln(
            f".{name} {vram_str}: AT({name}_ROM_START) SUBALIGN({segment.subalign})"
        )
        self._begin_block()

    def _end_segment(self, segment: Segment):
        self._end_block()

        name = get_segment_cname(segment)

        # force end if not shiftable/auto
        if (
            not self.shiftable
            and isinstance(segment.rom_start, int)
            and isinstance(segment.rom_end, int)
        ):
            self._write_symbol(f"{name}_ROM_END", segment.rom_end)
            self._writeln(f"__romPos = 0x{segment.rom_end:X};")
        else:
            self._writeln(f"__romPos += SIZEOF(.{name});")
            self._write_symbol(f"{name}_ROM_END", "__romPos")

        self._writeln("")
