#!/usr/bin/python3

import argparse
import os
import re

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = script_dir + "/../"
asm_dir = root_dir + "asm/nonmatchings/"

symbol_addrs_txt = os.path.join(script_dir, "symbol_addrs.txt")
papermario_map = os.path.join(root_dir, "build/papermario.map")

with open(symbol_addrs_txt, "r") as f:
    symbols = set()

    for line in f.readlines():
        line = line.split(";")[0]

        s = [s.strip() for s in line.split("=", 1)]
        name = s[0]

        symbols.add(name)

with open(symbol_addrs_txt, "a") as symbol_addrs:
    for root, dirs, files in os.walk(asm_dir):
        for f_name in files:
            if f_name.endswith(".s"):
                f_path = os.path.join(root, f_name)

                with open(f_path, "r") as f:
                    lines = f.readlines()
                    line = lines[3]
                    try:
                        addr = lines[4].split(" ")[2]
                    except:
                        addr = ""

                if not line.startswith("glabel ") or not addr.startswith("80"):
                    #print(f"??? {f_path}")
                    continue

                func_name = line.split(" ")[1].rstrip()

                if not func_name in symbols:
                    symbol_addrs.write(f"{func_name} = 0x{addr}; // type:func\n")
                    symbols.add(func_name)
                    print(func_name)

    with open(papermario_map, "r") as f:
        for match in re.compile(f"^\s+0x([a-f0-9]+)\s+([_a-zA-Z0-9]+)$", re.MULTILINE).finditer(f.read()):
            addr = int(match.group(1), 16)
            func = match.group(2)

            if func.startswith("0") or func.startswith("_binary_"):
                continue

            if func not in symbols:
                symbol_addrs.write(f"{func} = 0x{addr:X};\n")
                symbols.add(func)
                print(func)
