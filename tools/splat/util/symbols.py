from typing import Dict, List, Optional, TYPE_CHECKING, Set
import spimdisasm
import rabbitizer
import tqdm

# circular import
if TYPE_CHECKING:
    from segtypes.segment import Segment

from util import options, log

all_symbols: List["Symbol"] = []
all_symbols_dict: Dict[int, List["Symbol"]] = {}
ignored_addresses: Set[int] = set()
symbol_ranges: List["Symbol"] = []

# Initialize a spimdisasm context, used to store symbols and functions
spim_context = spimdisasm.common.Context()

TRUEY_VALS = ["true", "on", "yes", "y"]
FALSEY_VALS = ["false", "off", "no", "n"]


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


def initialize(all_segments: "List[Segment]"):
    global all_symbols
    global all_symbols_dict
    global symbol_ranges

    all_symbols = []
    all_symbols_dict = {}
    symbol_ranges = []

    def get_seg_for_name(name: str) -> Optional["Segment"]:
        for segment in all_segments:
            if segment.name == name:
                return segment
        return None

    # Manual list of func name / addrs
    for path in options.get_symbol_addrs_paths():
        if path.exists():
            with open(path) as f:
                sym_addrs_lines = f.readlines()
                for line_num, line in enumerate(
                    tqdm.tqdm(sym_addrs_lines, desc=f"Loading symbols ({path.stem})")
                ):
                    line = line.strip()
                    if not line == "" and not line.startswith("//"):
                        comment_loc = line.find("//")
                        line_main = line
                        line_ext = ""

                        if comment_loc != -1:
                            line_ext = line[comment_loc + 2 :].strip()
                            line_main = line[:comment_loc].strip()

                        try:
                            line_split = line_main.split("=")
                            name = line_split[0].strip()
                            addr = int(line_split[1].strip()[:-1], 0)
                        except:
                            log.parsing_error_preamble(path, line_num, line)
                            log.write("Line should be of the form")
                            log.write(
                                "<function_name> = <address> // attr0:val0 attr1:val1 [...]"
                            )
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
                                                log.parsing_error_preamble(
                                                    path, line_num, line
                                                )
                                                log.write(
                                                    f"Cannot find segment '{attr_val}'"
                                                )
                                                log.error("")
                                            else:
                                                # Add segment to symbol, symbol to segment
                                                sym.segment = seg
                                                seg.add_symbol(sym)
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
                                        if attr_name == "dead":
                                            sym.dead = tf_val
                                            continue
                                        if attr_name == "defined":
                                            sym.defined = tf_val
                                            continue
                                        if attr_name == "extract":
                                            sym.extract = tf_val
                                            continue
                                        if attr_name == "ignore":
                                            ignore_sym = tf_val
                                            continue
                        if ignore_sym:
                            ignored_addresses.add(sym.vram_start)
                            ignore_sym = False
                            continue

                        sym.user_declared = True
                        add_symbol(sym)

                        # Symbol ranges
                        if sym.size > 4:
                            symbol_ranges.append(sym)


def initialize_spim_context(all_segments: "List[Segment]") -> None:
    global_vrom_start = None
    global_vrom_end = None
    global_vram_start = None
    global_vram_end = None

    spim_context.bannedSymbols |= ignored_addresses

    for segment in all_segments:
        if segment.type == "code":
            # We only care about the VRAMs of code segments
            if isinstance(segment.vram_start, int) and isinstance(
                segment.vram_end, int
            ):
                ram_id = segment.get_exclusive_ram_id()
                if ram_id is None:
                    if global_vram_start is None:
                        global_vram_start = segment.vram_start
                    else:
                        if segment.vram_start < global_vram_start:
                            global_vram_start = segment.vram_start

                    if global_vram_end is None:
                        global_vram_end = segment.vram_end
                    else:
                        if global_vram_end < segment.vram_end:
                            global_vram_end = segment.vram_end

                    if isinstance(segment.rom_start, int):
                        if global_vrom_start is None:
                            global_vrom_start = segment.rom_start
                        else:
                            if segment.rom_start < global_vrom_start:
                                global_vrom_start = segment.rom_start

                    if isinstance(segment.rom_end, int):
                        if global_vrom_end is None:
                            global_vrom_end = segment.rom_end
                        else:
                            if global_vrom_end < segment.rom_end:
                                global_vrom_end = segment.rom_end

                else:
                    spim_context.addOverlaySegment(
                        ram_id,
                        segment.rom_start,
                        segment.rom_end,
                        segment.vram_start,
                        segment.vram_end,
                    )

    if (
        global_vram_start is not None
        and global_vram_end is not None
        and global_vrom_start is not None
        and global_vrom_end is not None
    ):
        spim_context.globalSegment.changeRanges(
            global_vrom_start, global_vrom_end, global_vram_start, global_vram_end
        )


def add_symbol_to_spim_section(
    section: spimdisasm.common.ElementBase, sym: "Symbol"
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
        if sym.type and sym.type != "unknown":
            context_sym.type = sym.type

    if sym.user_declared:
        context_sym.isUserDeclared = True
    if sym.defined:
        context_sym.isDefined = True
    if sym.rom is not None:
        context_sym.vromAddress = sym.rom
    if sym.given_size is not None:
        context_sym.size = sym.size
    context_sym.setNameGetCallbackIfUnset(lambda _: sym.name)

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


def retrieve_from_ranges(vram, rom=None):
    rom_matches = []
    ram_matches = []

    for symbol in symbol_ranges:
        if symbol.contains_vram(vram):
            if symbol.rom and rom and symbol.contains_rom(rom):
                rom_matches.append(symbol)
            else:
                ram_matches.append(symbol)

    ret = rom_matches + ram_matches

    if len(ret) > 0:
        return ret[0]
    else:
        return None


class Symbol:
    def __init__(
        self,
        vram: int,
        given_name: Optional[str] = None,
        rom: Optional[int] = None,
        type: Optional[str] = "unknown",
        given_size: Optional[int] = None,
        segment: Optional["Segment"] = None,
    ):
        self.defined: bool = False
        self.referenced: bool = False
        self.vram_start = vram
        self.rom = rom
        self.type = type
        self.given_size = given_size
        self.given_name = given_name
        self.access_mnemonic: Optional[rabbitizer.Enum] = None
        self.disasm_str: Optional[str] = None
        self.dead: bool = False
        self.extract: bool = True
        self.user_declared: bool = False
        self.segment: Optional["Segment"] = segment

    def __str__(self):
        return self.name

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
        if self.segment:
            if isinstance(self.rom, int):
                suffix = self.format_name(self.segment.symbol_name_format)
            else:
                suffix = self.format_name(self.segment.symbol_name_format_no_rom)
        else:
            if isinstance(self.rom, int):
                suffix = self.format_name(options.get_symbol_name_format())
            else:
                suffix = self.format_name(options.get_symbol_name_format_no_rom())

        if self.type == "func":
            prefix = "func"
        elif self.type == "jtbl":
            prefix = "jtbl"
        elif self.type == "jtbl_label":
            return f"L{suffix}"
        elif self.type == "label":
            return f".L{suffix}"
        else:
            prefix = "D"

        return f"{prefix}_{suffix}"

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
