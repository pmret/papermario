#! /usr/bin/python3

import glob
import os

print_funcs = True

sizes = {}

funcs = {}

def calc_insns(f_path):
    ret = 0
    with open(f_path) as f:
        f_lines = f.readlines()
    for line in f_lines:
        if line.startswith("/* "):
            ret += 1
    funcs[f_path.split("/")[-1][:-2]] = ret
    return ret

def do_dir(root, dir):
    max = 0
    min = None
    total = 0

    files = glob.glob(os.path.join(root, dir) + "/*.s")

    for f in files:
        amt = calc_insns(f)
        if amt > max:
            max = amt
        if min is None or amt < min:
            min = amt
        total += amt

    avg = 0 if len(files) == 0 else total / len(files)

    sizes[dir] = ((min, max, total, avg))


script_dir = os.path.dirname(os.path.realpath(__file__))
asm_dir = script_dir + "/../ver/current/asm/nonmatchings"

for root, dirs, files in os.walk(asm_dir):
    for asm_dir in dirs:
        if "/os" not in root and "/world/" not in root and "/battle/" not in root:
            do_dir(root, asm_dir)

for thing in sorted(sizes.keys(), key=lambda x: sizes[x][2]):
    val = sizes[thing][2]
    if val > 0:
        print(thing.ljust(25) + str(val))

if print_funcs:
    print(dict(sorted(funcs.items(), key=lambda f: f[1])))
