#!/usr/bin/python3

import argparse
import difflib
from collections import Counter, OrderedDict
import os
import sys

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = script_dir + "/../"
asm_dir = root_dir + "asm/nonmatchings/"
build_dir = root_dir + "build/"

def read_rom():
    with open("baserom.z64", "rb") as f:
        return f.read()


def find_dir(query):
    for root, dirs, files in os.walk(asm_dir):
        for d in dirs:
            if d == query:
                return os.path.join(root, d)
    return None


def get_all_s_files():
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
    bs = rom_bytes[start:end][0::4]
    ret = []
    for ins in bs:
        ret.append(ins >> 2)

    while len(ret) > 0 and ret[-1] == 0:
        ret.pop()

    return ret


def parse_map(fname):
    ram_offset = None
    cur_file = "<no file>"
    syms = {}
    prev_sym = None
    prev_line = ""
    with open(fname) as f:
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
                syms[fn] = (rom, cur_file, prev_sym, ram)
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
    if len(tb) < 8:
        return 0

    return difflib.SequenceMatcher(None, qb, tb).ratio()


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
        if symbol == "func_802A10A4_74AE34":
            dog = 5
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
        match_str = "{:.2f} - {}".format(matches[match], match)
        if match not in s_files:
           match_str += " (decompiled)"
        print(match_str)
        i += 1
    print()


def do_cross_query():
    ccount = Counter()
    clusters = []

    for sym_name in map_syms:
        if not sym_name.startswith("_binary"):
            if get_symbol_length(sym_name) > 16:
                query_bytes = get_symbol_bytes(map_offsets, sym_name)

                cluster_match = False
                for cluster in clusters:
                    cluster_first = cluster[0]
                    cluster_score = get_pair_score(query_bytes, cluster_first)
                    if cluster_score >= args.threshold:
                        cluster_match = True
                        if sym_name.startswith("func") and not cluster_first.startswith("func"):
                            ccount[sym_name] = ccount[cluster_first]
                            del ccount[cluster_first]
                            cluster_first = sym_name
                            cluster.insert(0, cluster_first)
                        else:
                            cluster.append(sym_name)

                        if cluster_first.startswith("func"):
                            ccount[cluster_first] += 1

                        if len(cluster) % 10 == 0 and len(cluster) >= 50:
                            print(f"Cluster {cluster_first} grew to size {len(cluster)}")
                        break
                if not cluster_match:
                    clusters.append([sym_name])
    print(ccount.most_common(100))


parser = argparse.ArgumentParser(description="Tools to assist with decomp")
parser.add_argument("query", help="function or file")
parser.add_argument("--threshold", help="score threshold between 0 and 1 (higher is more restrictive)", type=float, default=0.9, required=False)
parser.add_argument("--num-out", help="number of functions to display", type=int, default=100, required=False)

args = parser.parse_args()

rom_bytes = read_rom()
map_syms = parse_map(build_dir + "papermario.map")
map_offsets = get_map_offsets(map_syms)

s_files = get_all_s_files()

query_dir = find_dir(args.query)

if query_dir is not None:
    files = os.listdir(query_dir)
    for f_name in files:
        do_query(f_name[:-2])
else:
    if args.query == "cross":
        args.threshold = 0.985
        do_cross_query()
    else:
        do_query(args.query)
