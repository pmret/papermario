#!/usr/bin/python3

from collections import OrderedDict
import os
import sys

script_dir = os.path.dirname(os.path.realpath(__file__))

syms = {}

for version in ["us", "jp"]:
    file_path = os.path.join(script_dir, f"ver/{version}/symbol_addrs.txt")

    with open(file_path) as f:
        symbol_lines = f.readlines()

    for line in symbol_lines:
        addr_text = line.split(" = ")[1][:10]
        addr = int(addr_text, 0)
        if addr in syms:
            print("Duplicate address: " + addr_text)
            sys.exit(55)
        syms[addr] = line

    with open(file_path, newline="\n", mode="w") as f:
        for addr in sorted(syms):
            f.write(syms[addr])
