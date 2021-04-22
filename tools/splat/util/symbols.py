import os
from typing import Dict, List
from util import options

all_symbols: "List[Symbol]" = []
symbol_ranges: "List[Symbol]" = []
sym_isolated_map: "Dict[Symbol, bool]" = {}

def initialize(all_segments):
    global all_symbols
    global symbol_ranges

    all_symbols = []
    symbol_ranges = []

    symbol_addrs_path = options.get_symbol_addrs_path()
    
    # Manual list of func name / addrs
    if os.path.exists(symbol_addrs_path):
        with open(symbol_addrs_path) as f:
            func_addrs_lines = f.readlines()

        for line in func_addrs_lines:
            line = line.strip()
            if not line == "" and not line.startswith("//"):
                comment_loc = line.find("//")
                line_ext = ""

                if comment_loc != -1:
                    line_ext = line[comment_loc + 2:].strip()
                    line = line[:comment_loc].strip()

                line_split = line.split("=")
                name = line_split[0].strip()
                addr = int(line_split[1].strip()[:-1], 0)

                sym = Symbol(addr, given_name=name)

                if line_ext:
                    for info in line_ext.split(" "):
                        if info.startswith("type:"):
                            type = info.split(":")[1]
                            sym.type = type
                        if info.startswith("size:"):
                            size = int(info.split(":")[1], 0)
                            sym.size = size
                        if info.startswith("rom:"):
                            rom_addr = int(info.split(":")[1], 0)
                            sym.rom = rom_addr
                        if info.startswith("dead:"):
                            sym.dead = True
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

class Symbol:
    @property
    def default_name(self):
        suffix = f"_{self.vram_start:X}"

        if self.in_overlay:
            suffix += f"_{self.rom:X}"

        if self.type == "func":
            prefix = "func"
        elif self.type =="jtbl":
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

    def set_in_overlay(self):
        self.in_overlay = True

    @property
    def name(self):
        return self.given_name if self.given_name else self.default_name

    def contains_vram(self, offset):
        return offset >= self.vram_start and offset < self.vram_end

    def contains_rom(self, offset):
        return offset >= self.rom and offset < self.rom_end

    def __init__(self, vram, given_name=None, rom=None, type="unknown", in_overlay=False, size=4):
        self.defined = False
        self.referenced = False
        self.vram_start = vram
        self.rom = rom
        self.type = type
        self.in_overlay = in_overlay
        self.size = size
        self.given_name = given_name
        self.access_mnemonic = None
        self.disasm_str = None
        self.dead = False
