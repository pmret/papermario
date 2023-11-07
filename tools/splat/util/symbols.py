from dataclasses import dataclass
import re
from typing import Dict, List, Optional, Set, TYPE_CHECKING

import spimdisasm

from intervaltree import IntervalTree
from disassembler import disassembler_instance
from pathlib import Path

# circular import
if TYPE_CHECKING:
    from segtypes.segment import Segment

from util import log, options, progress_bar

all_symbols: List["Symbol"] = []
all_symbols_dict: Dict[int, List["Symbol"]] = {}
all_symbols_ranges = IntervalTree()
ignored_addresses: Set[int] = set()
to_mark_as_defined: Set[str] = set()

# Initialize a spimdisasm context, used to store symbols and functions
spim_context = spimdisasm.common.Context()

TRUEY_VALS = ["true", "on", "yes", "y"]
FALSEY_VALS = ["false", "off", "no", "n"]

splat_sym_types = {"func", "jtbl", "jtbl_label", "label"}


def check_valid_type(typename: str) -> bool:
    if typename[0].isupper():
        return True

    if typename in splat_sym_types:
        return True

    if typename in disassembler_instance.get_instance().known_types():
        return True

    return False


def is_truey(str: str) -> bool:
    return str.lower() in TRUEY_VALS


def is_falsey(str: str) -> bool:
    return str.lower() in FALSEY_VALS


def add_symbol(sym: "Symbol"):
    all_symbols.append(sym)
    if sym.vram_start is not None:
        if sym.vram_start not in all_symbols_dict:
            all_symbols_dict[sym.vram_start] = []
        all_symbols_dict[sym.vram_start].append(sym)

    # For larger symbols, add their ranges to interval trees for faster lookup
    if sym.size > 4:
        all_symbols_ranges.addi(sym.vram_start, sym.vram_end, sym)


def to_cname(symbol_name: str) -> str:
    symbol_name = re.sub(r"[^0-9a-zA-Z_]", "_", symbol_name)

    if symbol_name[0] in ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]:
        symbol_name = "_" + symbol_name

    return symbol_name


def handle_sym_addrs(
    path: Path, sym_addrs_lines: List[str], all_segments: "List[Segment]"
):
    def get_seg_for_name(name: str) -> Optional["Segment"]:
        for segment in all_segments:
            if segment.name == name:
                return segment
        return None

    def get_seg_for_rom(rom: int) -> Optional["Segment"]:
        for segment in all_segments:
            if segment.contains_rom(rom):
                return segment
        return None

    seen_symbols: Dict[str, "Symbol"] = dict()
    prog_bar = progress_bar.get_progress_bar(sym_addrs_lines)
    prog_bar.set_description(f"Loading symbols ({path.stem})")
    line: str
    for line_num, line in enumerate(prog_bar):
        line = line.strip()
        if not line == "" and not line.startswith("//"):
            comment_loc = line.find("//")
            line_main = line
            line_ext = ""

            if comment_loc != -1:
                line_ext = line[comment_loc + 2 :].strip()
                line_main = line[:comment_loc].strip()

            try:
                assert line.count(";") == 1, "Line must contain a single semi-colon"
                line_split = line_main.split("=")
                name = line_split[0].strip()
                addr = int(line_split[1].strip()[:-1], 0)
            except:
                log.parsing_error_preamble(path, line_num, line)
                log.write("Line must be of the form")
                log.write("<function_name> = <address>; // attr0:val0 attr1:val1 [...]")
                log.write("with <address> in hex preceded by 0x, or dec")
                log.write("")
                raise

            sym = Symbol(addr, given_name=name)

            ignore_sym = False
            if line_ext:
                for info in line_ext.split(" "):
                    if ":" in info:
                        if info.count(":") > 1:
                            log.parsing_error_preamble(path, line_num, line)
                            log.write(f"Too many ':'s in '{info}'")
                            log.error("")

                        attr_name, attr_val = info.split(":")
                        if attr_name == "":
                            log.parsing_error_preamble(path, line_num, line)
                            log.write(
                                f"Missing attribute name in '{info}', is there extra whitespace?"
                            )
                            log.error("")
                        if attr_val == "":
                            log.parsing_error_preamble(path, line_num, line)
                            log.write(
                                f"Missing attribute value in '{info}', is there extra whitespace?"
                            )
                            log.error("")

                        # Non-Boolean attributes
                        try:
                            if attr_name == "type":
                                if not check_valid_type(attr_val):
                                    log.parsing_error_preamble(path, line_num, line)
                                    log.write(
                                        f"Unrecognized symbol type in '{info}', it should be one of"
                                    )
                                    log.write(
                                        [
                                            *splat_sym_types,
                                            *spimdisasm.common.gKnownTypes,
                                        ]
                                    )
                                    log.write(
                                        "You may use a custom type that starts with a capital letter"
                                    )
                                    log.error("")
                                type = attr_val
                                sym.type = type
                                continue
                            if attr_name == "size":
                                size = int(attr_val, 0)
                                sym.given_size = size
                                continue
                            if attr_name == "rom":
                                rom_addr = int(attr_val, 0)
                                sym.rom = rom_addr
                                continue
                            if attr_name == "segment":
                                seg = get_seg_for_name(attr_val)
                                if seg is None:
                                    log.parsing_error_preamble(path, line_num, line)
                                    log.write(f"Cannot find segment '{attr_val}'")
                                    log.error("")
                                else:
                                    # Add segment to symbol
                                    sym.segment = seg
                                continue
                            if attr_name == "name_end":
                                sym.given_name_end = attr_val
                                continue
                        except:
                            log.parsing_error_preamble(path, line_num, line)
                            log.write(
                                f"value of attribute '{attr_name}' could not be read:"
                            )
                            log.write("")
                            raise

                        # Boolean attributes
                        tf_val = (
                            True
                            if is_truey(attr_val)
                            else False
                            if is_falsey(attr_val)
                            else None
                        )
                        if tf_val is None:
                            log.parsing_error_preamble(path, line_num, line)
                            log.write(
                                f"Invalid Boolean value '{attr_val}' for attribute '{attr_name}', should be one of"
                            )
                            log.write([*TRUEY_VALS, *FALSEY_VALS])
                            log.error("")
                        else:
                            if attr_name == "defined":
                                sym.defined = tf_val
                                continue
                            if attr_name == "extract":
                                sym.extract = tf_val
                                continue
                            if attr_name == "ignore":
                                ignore_sym = tf_val
                                continue
                            if attr_name == "force_migration":
                                sym.force_migration = tf_val
                                continue
                            if attr_name == "force_not_migration":
                                sym.force_not_migration = tf_val
                                continue
                            if attr_name == "allow_addend":
                                sym.allow_addend = tf_val
                                continue
                            if attr_name == "dont_allow_addend":
                                sym.dont_allow_addend = tf_val
                                continue

            if ignore_sym:
                if sym.given_size is None or sym.given_size == 0:
                    ignored_addresses.add(sym.vram_start)
                else:
                    spim_context.addBannedSymbolRangeBySize(
                        sym.vram_start, sym.given_size
                    )

                continue

            if sym.segment is None and sym.rom is not None:
                sym.segment = get_seg_for_rom(sym.rom)

            if sym.segment:
                sym.segment.add_symbol(sym)

            sym.user_declared = True

            if sym.name in seen_symbols:
                log.parsing_error_preamble(path, line_num, line)
                log.error(
                    f"Duplicate symbol detected! {sym.name} has already been defined at 0x{seen_symbols[sym.name].vram_start:X}"
                )

            if addr in all_symbols_dict:
                items = all_symbols_dict[addr]
                for item in items:
                    if (
                        sym.rom == item.rom
                        or None in (sym.rom, item.rom)
                        or sym.segment == item.segment
                        or None in (sym.segment, item.rom)
                    ):
                        log.parsing_error_preamble(path, line_num, line)
                        log.error(
                            f"Duplicate symbol detected! {sym.name} clashes with {item.name} defined at 0x{addr:X}"
                        )

            seen_symbols[sym.name] = sym

            add_symbol(sym)


def initialize(all_segments: "List[Segment]"):
    global all_symbols
    global all_symbols_dict
    global all_symbols_ranges

    all_symbols = []
    all_symbols_dict = {}
    all_symbols_ranges = IntervalTree()

    # Manual list of func name / addrs
    for path in options.opts.symbol_addrs_paths:
        if path.exists():
            with open(path) as f:
                sym_addrs_lines = f.readlines()
                handle_sym_addrs(path, sym_addrs_lines, all_segments)


def initialize_spim_context(all_segments: "List[Segment]") -> None:
    global_vrom_start = None
    global_vrom_end = None
    global_vram_start = None
    global_vram_end = None
    overlay_segments: Set[spimdisasm.common.SymbolsSegment] = set()

    spim_context.bannedSymbols |= ignored_addresses

    from segtypes.common.code import CommonSegCode

    for segment in all_segments:
        if not isinstance(segment, CommonSegCode):
            # We only care about the VRAMs of code segments
            continue

        if segment.special_vram_segment:
            # Special segments which should not be accounted in the global VRAM calculation, like N64's IPL3
            continue

        if (
            not isinstance(segment.vram_start, int)
            or not isinstance(segment.vram_end, int)
            or not isinstance(segment.rom_start, int)
            or not isinstance(segment.rom_end, int)
        ):
            continue

        ram_id = segment.get_exclusive_ram_id()

        if ram_id is None:
            if global_vram_start is None:
                global_vram_start = segment.vram_start
            elif segment.vram_start < global_vram_start:
                global_vram_start = segment.vram_start

            if global_vram_end is None:
                global_vram_end = segment.vram_end
            elif global_vram_end < segment.vram_end:
                global_vram_end = segment.vram_end

            if global_vrom_start is None:
                global_vrom_start = segment.rom_start
            elif segment.rom_start < global_vrom_start:
                global_vrom_start = segment.rom_start

            if global_vrom_end is None:
                global_vrom_end = segment.rom_end
            elif global_vrom_end < segment.rom_end:
                global_vrom_end = segment.rom_end

        else:
            spim_segment = spim_context.addOverlaySegment(
                ram_id,
                segment.rom_start,
                segment.rom_end,
                segment.vram_start,
                segment.vram_end,
            )
            # Add the segment-specific symbols first
            for symbols_list in segment.seg_symbols.values():
                for sym in symbols_list:
                    add_symbol_to_spim_segment(spim_segment, sym)

            overlay_segments.add(spim_segment)

    if (
        global_vram_start is not None
        and global_vram_end is not None
        and global_vrom_start is not None
        and global_vrom_end is not None
    ):
        spim_context.changeGlobalSegmentRanges(
            global_vrom_start, global_vrom_end, global_vram_start, global_vram_end
        )

        # Check the vram range of the global segment does not overlap with any overlay segment
        for ovl_segment in overlay_segments:
            assert (
                ovl_segment.vramStart <= ovl_segment.vramEnd
            ), f"{ovl_segment.vramStart:X} {ovl_segment.vramEnd:X}"
            if (
                ovl_segment.vramEnd > global_vram_start
                and global_vram_end > ovl_segment.vramStart
            ):
                log.write(
                    f"Warning: the vram range ([0x{ovl_segment.vramStart:X}, 0x{ovl_segment.vramEnd:X}]) of the non-global segment at rom address 0x{ovl_segment.vromStart:X} overlaps with the global vram range ([0x{global_vram_start:X}, 0x{global_vram_end:X}])",
                    status="warn",
                )

    # pass the global symbols to spimdisasm
    for segment in all_segments:
        if not isinstance(segment, CommonSegCode):
            # We only care about the VRAMs of code segments
            continue

        ram_id = segment.get_exclusive_ram_id()
        if ram_id is not None:
            continue

        for symbols_list in segment.seg_symbols.values():
            for sym in symbols_list:
                add_symbol_to_spim_segment(spim_context.globalSegment, sym)


def add_symbol_to_spim_segment(
    segment: spimdisasm.common.SymbolsSegment, sym: "Symbol"
) -> spimdisasm.common.ContextSymbol:
    if sym.type == "func":
        context_sym = segment.addFunction(
            sym.vram_start, isAutogenerated=not sym.user_declared, vromAddress=sym.rom
        )
    elif sym.type == "jtbl":
        context_sym = segment.addJumpTable(
            sym.vram_start, isAutogenerated=not sym.user_declared, vromAddress=sym.rom
        )
    elif sym.type == "jtbl_label":
        context_sym = segment.addJumpTableLabel(
            sym.vram_start, isAutogenerated=not sym.user_declared, vromAddress=sym.rom
        )
    elif sym.type == "label":
        context_sym = segment.addBranchLabel(
            sym.vram_start, isAutogenerated=not sym.user_declared, vromAddress=sym.rom
        )
    else:
        context_sym = segment.addSymbol(
            sym.vram_start, isAutogenerated=not sym.user_declared, vromAddress=sym.rom
        )
        if sym.type is not None:
            context_sym.type = sym.type

    if sym.user_declared:
        context_sym.isUserDeclared = True
    if sym.defined:
        context_sym.isDefined = True
    if sym.rom is not None:
        context_sym.vromAddress = sym.rom
    if sym.given_size is not None:
        context_sym.size = sym.size
    if sym.force_migration:
        context_sym.forceMigration = True
    if sym.force_not_migration:
        context_sym.forceNotMigration = True
    if sym.allow_addend:
        context_sym.allowedToReferenceAddends = True
    if sym.dont_allow_addend:
        context_sym.notAllowedToReferenceAddends = True
    context_sym.setNameGetCallbackIfUnset(lambda _: sym.name)
    if sym.given_name_end:
        context_sym.nameEnd = sym.given_name_end

    return context_sym


def add_symbol_to_spim_section(
    section: spimdisasm.mips.sections.SectionBase, sym: "Symbol"
) -> spimdisasm.common.ContextSymbol:
    if sym.type == "func":
        context_sym = section.addFunction(
            sym.vram_start, isAutogenerated=not sym.user_declared, symbolVrom=sym.rom
        )
    elif sym.type == "jtbl":
        context_sym = section.addJumpTable(
            sym.vram_start, isAutogenerated=not sym.user_declared, symbolVrom=sym.rom
        )
    elif sym.type == "jtbl_label":
        context_sym = section.addJumpTableLabel(
            sym.vram_start, isAutogenerated=not sym.user_declared, symbolVrom=sym.rom
        )
    elif sym.type == "label":
        context_sym = section.addBranchLabel(
            sym.vram_start, isAutogenerated=not sym.user_declared, symbolVrom=sym.rom
        )
    else:
        context_sym = section.addSymbol(
            sym.vram_start, isAutogenerated=not sym.user_declared, symbolVrom=sym.rom
        )
        if sym.type is not None:
            context_sym.type = sym.type

    if sym.user_declared:
        context_sym.isUserDeclared = True
    if sym.defined:
        context_sym.isDefined = True
    if sym.rom is not None:
        context_sym.vromAddress = sym.rom
    if sym.given_size is not None:
        context_sym.size = sym.size
    if sym.force_migration:
        context_sym.forceMigration = True
    if sym.force_not_migration:
        context_sym.forceNotMigration = True
    context_sym.setNameGetCallbackIfUnset(lambda _: sym.name)
    if sym.given_name_end:
        context_sym.nameEnd = sym.given_name_end

    return context_sym


def create_symbol_from_spim_symbol(
    segment: "Segment", context_sym: spimdisasm.common.ContextSymbol
) -> "Symbol":
    in_segment = False

    sym_type = None
    if context_sym.type == spimdisasm.common.SymbolSpecialType.jumptable:
        in_segment = True
        sym_type = "jtbl"
    elif context_sym.type == spimdisasm.common.SymbolSpecialType.function:
        sym_type = "func"
    elif context_sym.type == spimdisasm.common.SymbolSpecialType.branchlabel:
        in_segment = True
        sym_type = "label"
    elif context_sym.type == spimdisasm.common.SymbolSpecialType.jumptablelabel:
        in_segment = True
        sym_type = "jtbl_label"

    if not in_segment:
        if (
            context_sym.overlayCategory is None
            and segment.get_exclusive_ram_id() is None
        ):
            in_segment = segment.contains_vram(context_sym.vram)
        elif context_sym.overlayCategory == segment.get_exclusive_ram_id():
            if context_sym.vromAddress is not None:
                in_segment = segment.contains_rom(context_sym.vromAddress)
            else:
                in_segment = segment.contains_vram(context_sym.vram)

    sym = segment.create_symbol(
        context_sym.vram, in_segment, type=sym_type, reference=True
    )

    if sym.given_name is None and context_sym.name is not None:
        sym.given_name = context_sym.name

    # To keep the symbol name in sync between splat and spimdisasm
    context_sym.setNameGetCallback(lambda _: sym.name)

    if context_sym.size is not None:
        sym.given_size = context_sym.getSize()
    if context_sym.vromAddress is not None:
        sym.rom = context_sym.getVrom()
    if context_sym.isDefined:
        sym.defined = True
    if context_sym.referenceCounter > 0:
        sym.referenced = True

    return sym


def mark_c_funcs_as_defined():
    for symbol in all_symbols:
        if len(to_mark_as_defined) == 0:
            return
        sym_name = symbol.name
        if sym_name in to_mark_as_defined:
            symbol.defined = True
            to_mark_as_defined.remove(sym_name)


@dataclass
class Symbol:
    vram_start: int

    given_name: Optional[str] = None
    given_name_end: Optional[str] = None
    rom: Optional[int] = None
    type: Optional[str] = None
    given_size: Optional[int] = None
    segment: Optional["Segment"] = None

    defined: bool = False
    referenced: bool = False
    extract: bool = True
    user_declared: bool = False

    force_migration: bool = False
    force_not_migration: bool = False

    allow_addend: bool = False
    dont_allow_addend: bool = False

    linker_section: Optional[str] = None

    _generated_default_name: Optional[str] = None
    _last_type: Optional[str] = None

    def __str__(self):
        return self.name

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, Symbol):
            return False
        return self.vram_start == other.vram_start and self.segment == other.segment

    # https://stackoverflow.com/a/56915493/6292472
    def __hash__(self):
        return hash((self.vram_start, self.segment))

    def format_name(self, format: str) -> str:
        ret = format

        ret = ret.replace("$VRAM", f"{self.vram_start:08X}")

        if "$ROM" in ret:
            if not isinstance(self.rom, int):
                log.error(
                    f"Attempting to rom-name a symbol with no ROM address: {self.vram_start:X} typed {self.type}"
                )
            ret = ret.replace("$ROM", f"{self.rom:X}")

        if "$SEG" in ret:
            if self.segment is None:
                # This probably is fine - we can't expect every symbol to have a segment. Fall back to just the ram address
                return f"{self.vram_start:X}"
            assert self.segment is not None
            ret = ret.replace("$SEG", self.segment.name)

        return ret

    @property
    def default_name(self) -> str:
        if self._generated_default_name is not None:
            if self.type == self._last_type:
                return self._generated_default_name

        if self.segment:
            if isinstance(self.rom, int):
                suffix = self.format_name(self.segment.symbol_name_format)
            else:
                suffix = self.format_name(self.segment.symbol_name_format_no_rom)
        else:
            if isinstance(self.rom, int):
                suffix = self.format_name(options.opts.symbol_name_format)
            else:
                suffix = self.format_name(options.opts.symbol_name_format_no_rom)

        if self.type == "func":
            prefix = "func"
        elif self.type == "jtbl":
            prefix = "jtbl"
        elif self.type in {"jtbl_label", "label"}:
            return f".L{suffix}"
        else:
            prefix = "D"

        self._last_type = self.type
        self._generated_default_name = f"{prefix}_{suffix}"
        return self._generated_default_name

    @property
    def rom_end(self):
        return None if not self.rom else self.rom + self.size

    @property
    def vram_end(self):
        return self.vram_start + self.size

    @property
    def name(self) -> str:
        return self.given_name if self.given_name else self.default_name

    @property
    def size(self) -> int:
        if self.given_size is not None:
            return self.given_size
        return 4

    def contains_vram(self, offset):
        return offset >= self.vram_start and offset < self.vram_end

    def contains_rom(self, offset):
        return offset >= self.rom and offset < self.rom_end


def get_all_symbols():
    global all_symbols
    return all_symbols


def reset_symbols():
    global all_symbols
    global all_symbols_dict
    global all_symbols_ranges
    global ignored_addresses
    global to_mark_as_defined
    all_symbols = []
    all_symbols_dict = {}
    all_symbols_ranges = IntervalTree()
    ignored_addresses = set()
    to_mark_as_defined = set()
