#!/usr/bin/python3

import argparse
import os
import re

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = script_dir + "/../"
asm_dir = root_dir + "asm/nonmatchings/"

symbol_addrs_txt = os.path.join(script_dir, "symbol_addrs.txt")

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
                    print(f"??? {f_path}")
                    continue

                func_name = line.split(" ")[1].rstrip()

                if not func_name in symbols:
                    symbol_addrs.write(f"{func_name} = 0x{addr}; // type:func\n")
