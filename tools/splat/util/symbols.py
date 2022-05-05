from dataclasses import dataclass
from typing import Dict, List, Optional

from capstone import CsInsn
from util import options, log

all_symbols: "List[Symbol]" = []
symbol_ranges: "List[Symbol]" = []
sym_isolated_map: "Dict[Symbol, bool]" = {}

TRUEY_VALS = ["true", "on", "yes", "y"]
FALSEY_VALS = ["false", "off", "no", "n"]


def is_truey(str: str) -> bool:
    return str.lower() in TRUEY_VALS


def is_falsey(str: str) -> bool:
    return str.lower() in FALSEY_VALS


def initialize(all_segments):
    global all_symbols
    global symbol_ranges

    all_symbols = []
    symbol_ranges = []

    # Manual list of func name / addrs
    for path in options.get_symbol_addrs_paths():
        if path.exists():
            with open(path) as f:
                sym_addrs_lines = f.readlines()
                for line_num, line in enumerate(sym_addrs_lines):
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

                        if line_ext:
                            for info in line_ext.split(" "):
                                if ":" in info:
                                    if info.count(':') > 1:
                                        log.parsing_error_preamble(path, line_num, line)
                                        log.write(f"Too many ':'s in '{info}'")
                                        log.error("")

                                    attr_name, attr_val = info.split(":")
                                    if attr_name == "":
                                        log.parsing_error_preamble(path, line_num, line)
                                        log.write(f"Missing attribute name in '{info}', is there extra whitespace?")
                                        log.error("")
                                    if attr_val == "":
                                        log.parsing_error_preamble(path, line_num, line)
                                        log.write(f"Missing attribute value in '{info}', is there extra whitespace?")
                                        log.error("")


                                    # Non-Boolean attributes
                                    try:
                                        if attr_name == "type":
                                            type = attr_val
                                            sym.type = type
                                            continue
                                        if attr_name == "size":
                                            size = int(attr_val, 0)
                                            sym.size = size
                                            continue
                                        if attr_name == "rom":
                                            rom_addr = int(attr_val, 0)
                                            sym.rom = rom_addr
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

                                    if attr_name == "dead":
                                        sym.dead = tf_val
                                        continue
                                    if attr_name == "defined":
                                        sym.defined = tf_val
                                        continue
                                    if attr_name == "extract":
                                        sym.extract = tf_val
                                        continue
                        all_symbols.append(sym)

                        # Symbol ranges
                        if sym.size > 4:
                            symbol_ranges.append(sym)

                        is_symbol_isolated(sym, all_segments)


def is_symbol_isolated(symbol, all_segments):
    if symbol in sym_isolated_map:
        return sym_isolated_map[symbol]

    relevant_segs = 0

    for segment in all_segments:
        if segment.contains_vram(symbol.vram_start):
            relevant_segs += 1
            if relevant_segs > 1:
                break

    sym_isolated_map[symbol] = relevant_segs < 2
    return sym_isolated_map[symbol]


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


@dataclass
class Instruction:
    instruction: CsInsn
    mnemonic: str
    op_str: str
    rom_addr: int
    is_gp: bool = False
    is_hi: bool = False
    is_lo: bool = False
    hi_lo_sym: Optional["Symbol"] = None
    sym_offset_str: str = ""
    hi_lo_reg: str = ""


class Symbol:
    @property
    def default_name(self) -> str:
        suffix = f"_{self.vram_start:X}"

        if self.in_overlay:
            suffix += f"_{self.rom:X}"

        if self.type == "func":
            prefix = "func"
        elif self.type == "jtbl":
            prefix = "jtbl"
        else:
            prefix = "D"

        return prefix + suffix

    @property
    def rom_end(self):
        return None if not self.rom else self.rom + self.size

    @property
    def vram_end(self):
        return self.vram_start + self.size

    @property
    def name(self) -> str:
        return self.given_name if self.given_name else self.default_name

    def contains_vram(self, offset):
        return offset >= self.vram_start and offset < self.vram_end

    def contains_rom(self, offset):
        return offset >= self.rom and offset < self.rom_end

    def __init__(
        self,
        vram,
        given_name: str = "",
        rom=None,
        type="unknown",
        in_overlay=False,
        size=4,
    ):
        self.defined = False
        self.referenced = False
        self.vram_start = vram
        self.rom = rom
        self.type = type
        self.in_overlay = in_overlay
        self.size = size
        self.given_name: str = given_name
        self.insns: List[Instruction] = []
        self.access_mnemonic = None
        self.disasm_str = None
        self.dead = False
        self.extract = True
