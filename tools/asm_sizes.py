#!/usr/bin/env python3

import json
import glob
import os
import argparse
from enum import IntEnum


script_dir = os.path.dirname(os.path.realpath(__file__))
asm_dir = script_dir + "/../ver/current/asm/nonmatchings"

modes = ["min", "max", "avg", "total", "size"]

sizes = {}

funcs = {}


# Calculate the number of instructions in a .s file
def calc_insns(f_path):
    ret = 0
    with open(f_path) as f:
        f_lines = f.readlines()
    for line in f_lines:
        if line.startswith("/* "):
            ret += 1
    funcs[f_path.split("/")[-1][:-2]] = ret
    return ret


# Calculate different data points for each .c files and store them as a Tuple
def do_dir(root, dir):
    max = 0
    min = 0
    total = 0

    files = glob.glob(os.path.join(root, dir) + "/*.s")

    for f in files:
        amt = calc_insns(f)
        if amt > max:
            max = amt
        if min == 0 or amt < min:
            min = amt
        total += amt

    avg = 0 if len(files) == 0 else total / len(files)

    sizes[root + "/" + dir] = (min, max, total, avg, len(files))


parser = argparse.ArgumentParser(
    description="A tool to receive information about the number of non-matching .s files "
    + "per .c file, or the size of .s files, measured by their number of instructions. "
    + "Option -p is used by default if no option is specified."
)
group = parser.add_mutually_exclusive_group()
group.add_argument(
    "-f",
    "--files",
    help="Default. Print the number of non-matching .s files per .c file, ordered by size.",
    action="store_true",
    required=False,
)
group.add_argument(
    "-a",
    "--alphabetical",
    help="Print the size of .s files, ordered by name.",
    action="store_true",
    required=False,
)
group.add_argument(
    "-s",
    "--size",
    help="Print the size of .s files, ordered by size.",
    action="store_true",
    required=False,
)
parser.add_argument(
    "-l",
    "--limit",
    help="Only print the .c --files that are greater than or equal to the value.",
    type=int,
    default=0,
    required=False,
)
parser.add_argument(
    "-m",
    "--mode",
    help="Switches between output modes for --files. Allowed values are: {min, max, avg, total, size}.",
    choices=modes,
    default="size",
    metavar="",
    required=False,
)

args = parser.parse_args()


if __name__ == "__main__":
    for root, dirs, files in os.walk(asm_dir):
        for asm_dir in dirs:
            do_dir(root, asm_dir)

    if args.alphabetical:
        print(json.dumps(dict(sorted(funcs.items(), key=lambda f: f[0])), indent=4))
    elif args.size:
        print(json.dumps(dict(sorted(funcs.items(), key=lambda f: f[1])), indent=4))
    else:
        for thing in sorted(sizes.keys(), key=lambda x: sizes[x][modes.index(args.mode)]):
            val = sizes[thing][modes.index(args.mode)]
            if val > args.limit:
                print(thing.split("nonmatchings/")[1].ljust(50) + str(val))
