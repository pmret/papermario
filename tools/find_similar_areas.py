#!/usr/bin/python3

import argparse
from collections import OrderedDict
from dataclasses import dataclass
from pathlib import Path

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
    rom: int
    ram: int
    current_file: str
    prev_sym: str
    is_decompiled: bool

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


def get_symbol_length(sym_name):
    if "end" in map_offsets[sym_name] and "start" in map_offsets[sym_name]:
        return map_offsets[sym_name]["end"] - map_offsets[sym_name]["start"]
    return 0


def get_symbol_bytes(offsets, func):
    if func not in offsets or "start" not in offsets[func] or "end" not in offsets[func]:
        return None
    start = offsets[func]["start"]
    end = offsets[func]["end"]
    bs = list(rom_bytes[start:end])

    while len(bs) > 0 and bs[-1] == 0:
        bs.pop()

    insns = bs[0::4]

    ret = []
    for ins in insns:
        ret.append(ins >> 2)

    return bytes(ret).decode('utf-8'), bs



def parse_map():
    ram_offset = None
    cur_file = "<no file>"
    syms = {}
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
                    rom=rom,
                    ram=ram,
                    current_file=cur_file,
                    prev_sym=prev_sym,
                    is_decompiled=False
                )
                prev_sym = fn
    return syms


def get_map_offsets(syms):
    offsets = {}
    for sym in syms:
        prev_sym = syms[sym][2]
        if sym not in offsets:
            offsets[sym] = {}
        if prev_sym not in offsets:
            offsets[prev_sym] = {}
        offsets[sym]["start"] = syms[sym][0]
        offsets[prev_sym]["end"] = syms[sym][0]
    return offsets


def is_zeros(vals):
    for val in vals:
        if val != 0:
            return False
    return True


def diff_syms(qb, tb):
    if len(tb[1]) < 8:
        return 0

    # The minimum edit distance for two strings of different lengths is `abs(l1 - l2)`
    # Quickly check if it's impossible to beat the threshold. If it is, then return 0
    l1, l2 = len(qb[0]), len(tb[0])
    if abs(l1 - l2) / (l1 + l2) > 1.0 - args.threshold:
        return 0
    r = ratio(qb[0], tb[0])

    if r == 1.0 and qb[1] != tb[1]:
        r = 0.99
    return r


def get_pair_score(query_bytes, b):
    b_bytes = get_symbol_bytes(map_offsets, b)

    if query_bytes and b_bytes:
        return diff_syms(query_bytes, b_bytes)
    return 0


def get_matches(query):
    query_bytes = get_symbol_bytes(map_offsets, query)
    if query_bytes is None:
        sys.exit("Symbol '" + query + "' not found")

    ret = {}
    for symbol in map_offsets:
        if symbol is not None and query != symbol:
            score = get_pair_score(query_bytes, symbol)
            if score >= args.threshold:
                ret[symbol] = score
    return OrderedDict(sorted(ret.items(), key=lambda kv: kv[1], reverse=True))


def do_query(query):
    matches = get_matches(query)
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
        if match not in unmatched_functions:
           match_str += " (decompiled)"
        print(match_str)
        i += 1
    print()

parser = argparse.ArgumentParser(description="Tool to find duplicate portions of code from one function in code across the codebase")
parser.add_argument("query", help="function")
parser.add_argument("-t", "--threshold", help="score threshold between 0 and 1 (higher is more restrictive)", type=float, default=0.9, required=False)
parser.add_argument("-n", "--num-out", help="number of results to display", type=int, default=100, required=False)

args = parser.parse_args()

if __name__ == "__main__":
    rom_bytes = read_rom()
    unmatched_functions = get_all_unmatched_functions()
    map_syms = parse_map()
    map_offsets = get_map_offsets(map_syms)

    do_query(args.query)
