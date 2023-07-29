#!/usr/bin/env python3

import os
import re

syms = []
groups = {}

with open("tools/symz.txt") as f:
    for line in f.readlines():
        if line.strip() and not line.startswith("//"):
            name, addr = line.strip().strip(";").split(" = ")
            try:
                addr = int(addr, 0)
            except ValueError:
                continue
            syms.append(
                {"name": name, "address": addr, "found_in": set(), "dead": False}
            )

# Search src for syms
for root, dirs, files in os.walk("src"):
    for file in files:
        if file.endswith(".c") and "bss" not in file:
            with open(os.path.join(root, file)) as f:
                text = f.read()
                for sym in syms:
                    if sym["name"] in text:
                        sym["found_in"].add(
                            os.path.join(root, file).replace("src/", "")
                        )

# Search asm for syms
for root, dirs, files in os.walk("ver/us/asm"):
    for file in files:
        if file.endswith(".s"):
            with open(os.path.join(root, file)) as f:
                text = f.read()
                for sym in syms:
                    if sym["name"] in text:
                        sym["found_in"].add(
                            os.path.join(root, file).replace(
                                "ver/us/asm/nonmatchings/", ""
                            )
                        )
                        if re.match(r"E[A-F][0-9A-F]{4}", root.split("/")[-1]):
                            sym["dead"] = True
                        else:
                            sym["dead"] = False

for sym in syms:
    if len(sym["found_in"]) == 0:
        group = ""
    elif sym["dead"]:
        group = "dead"
    elif len(sym["found_in"]) > 1:
        group = "multig"
    else:
        group = next(iter(sym["found_in"]))

    if group not in groups:
        groups[group] = []
    groups[group].append(sym)

for group in groups:
    if group == "":
        print("// The following symbols can be simply removed from undefined_syms:")
    elif group == "multig":
        print("// The following symbols are found in multiple locations:")
    elif group == "dead":
        print("// The following symbols are dead:")
    else:
        print("// " + group + ":")

    sorted_syms = sorted(groups[group], key=lambda tup: tup["address"])

    for sym in sorted_syms:
        print(f"{sym['name']} = 0x{sym['address']:X}")
    print()
