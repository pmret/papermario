#!/usr/bin/python3

import argparse
from collections import OrderedDict
from dataclasses import dataclass
from pathlib import Path
from typing import Optional

from Levenshtein import ratio
import os
import sys

script_dir = Path(os.path.dirname(os.path.realpath(__file__)))
root_dir = script_dir / ".."
asm_dir = root_dir / "ver/current/asm/nonmatchings/"
map_file_path = root_dir / "ver/current/build/papermario.map"
rom_path = root_dir / "ver/current/baserom.z64"


@dataclass
class Symbol:
    name: str
    rom_start: int
    ram: int
    current_file: str
    prev_sym: str
    is_decompiled: bool
    rom_end: Optional[int] = None

    def size(self):
        assert(self.rom_end is not None)
        return self.rom_end - self.rom_start

@dataclass
class Bytes:
    offset: int
    normalized: str
    bytes: list[int]


def read_rom() -> bytes:
    with open(rom_path, "rb") as f:
        return f.read()

def get_all_unmatched_functions():
    ret = set()
    for root, dirs, files in os.walk(asm_dir):
        for f in files:
            if f.endswith(".s"):
                ret.add(f[:-2])
    return ret


def get_symbol_bytes(func: str) -> Optional[Bytes]:
    if func not in syms or syms[func].rom_end is None:
        return None
    sym = syms[func]
    bs = list(rom_bytes[sym.rom_start:sym.rom_end])

    while len(bs) > 0 and bs[-1] == 0:
        bs.pop()

    insns = bs[0::4]

    ret = []
    for ins in insns:
        ret.append(ins >> 2)

    return Bytes(0, bytes(ret).decode('utf-8'), bs)


def parse_map() -> OrderedDict[str, Symbol]:
    ram_offset = None
    cur_file = "<no file>"
    syms: OrderedDict[str, Symbol] = OrderedDict()
    prev_sym = ""
    prev_line = ""
    with open(map_file_path) as f:
        for line in f:
            if "load address" in line:
                if "noload" in line or "noload" in prev_line:
                    ram_offset = None
                    continue
                ram = int(line[16 : 16 + 18], 0)
                rom = int(line[59 : 59 + 18], 0)
                ram_offset = ram - rom
                continue
            prev_line = line

            if (
                ram_offset is None
                or "=" in line
                or "*fill*" in line
                or " 0x" not in line
            ):
                continue
            ram = int(line[16 : 16 + 18], 0)
            rom = ram - ram_offset
            fn = line.split()[-1]
            if "0x" in fn:
                ram_offset = None
            elif "/" in fn:
                cur_file = fn
            else:
                syms[fn] = Symbol(
                    name=fn,
                    rom_start=rom,
                    ram=ram,
                    current_file=cur_file,
                    prev_sym=prev_sym,
                    is_decompiled=not fn in unmatched_functions,
                )
                prev_sym = fn

    # Calc end offsets
    for sym in syms:
        prev_sym = syms[sym].prev_sym
        if prev_sym:
            syms[prev_sym].rom_end = syms[sym].rom_start

    return syms



@dataclass
class Match:
    query_offset: int
    target_offset: int
    length: int

    def __str__(self):
        return f"{self.query_offset} {self.target_offset} {self.length}"

def get_pair_matches(query_hashes: list[int], sym_hashes: list[int]) -> list[Match]:
    ret = []

    matching_hashes = set(query_hashes).intersection(sym_hashes)
    for hash in matching_hashes:
        ret.append(Match(query_hashes.index(hash), sym_hashes.index(hash), 1))
    return ret


def get_hashes(bytes: Bytes, window_size: int) -> list[int]:
    ret = []
    for i in range(0, len(bytes.normalized) - window_size):
        ret.append(bytes.normalized[i : i + window_size])
    return ret

def get_matches(query: str, window_size: int):
    query_bytes: Optional[Bytes] = get_symbol_bytes(query)

    if query_bytes is None:
        sys.exit("Symbol '" + query + "' not found")

    query_hashes = get_hashes(query_bytes, window_size)

    ret: dict[str, float] = {}
    for symbol in syms:
        if query == symbol:
            continue

        sym_bytes: Optional[Bytes] = get_symbol_bytes(symbol)
        if not sym_bytes:
            continue

        if len(sym_bytes.bytes) < window_size:
            continue

        sym_hashes = get_hashes(sym_bytes, window_size)

        matches: list[Match] = get_pair_matches(query_hashes, sym_hashes)
        for match in matches:
            print(f"{query} {symbol} {match}")

    return OrderedDict(sorted(ret.items(), key=lambda kv: kv[1], reverse=True))


def do_query(query, window_size):
    matches = get_matches(query, window_size)
    num_matches = len(matches)

    if num_matches == 0:
        print(query + " - found no matches")
        return

    i = 0
    more_str = ":"
    if args.num_out < num_matches:
        more_str = " (showing only " + str(args.num_out) + "):"

    print(query + " - found " + str(num_matches) + " matches total" + more_str)
    for match in matches:
        if i == args.num_out:
            break
        match_str = "{:.3f} - {}".format(matches[match], match)
        if syms[match].is_decompiled:
           match_str += " (decompiled)"
        print(match_str)
        i += 1
    print()

parser = argparse.ArgumentParser(description="Tool to find duplicate portions of code from one function in code across the codebase")
parser.add_argument("query", help="function")
parser.add_argument("-t", "--threshold", help="score threshold between 0 and 1 (higher is more restrictive)", type=float, default=0.9, required=False)
parser.add_argument("-n", "--num-out", help="number of results to display", type=int, default=100, required=False)
parser.add_argument("-w", "--window-size", help="number of bytes to compare", type=int, default=20, required=False)

args = parser.parse_args()

if __name__ == "__main__":
    rom_bytes = read_rom()
    unmatched_functions = get_all_unmatched_functions()
    syms = parse_map()

    do_query(args.query, args.window_size)
