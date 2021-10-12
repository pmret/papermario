#!/usr/bin/python3

import os
import re
from pathlib import Path

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = script_dir + "/../"
asm_dir = root_dir + "ver/current/asm/"
asm_effects_dir = asm_dir + "nonmatchings/effects/"

renames = []

# Walk through asm files and rename stuff
print("Walking through asm files")
for root, dirs, files in os.walk(asm_effects_dir):
    for f_name in files:
        if f_name.endswith("_main.s"):
            f_path = os.path.join(root, f_name)

            effect_num = f_name.split("_")[1]

            with open(f_path) as f:
                asm_text = f.read()

            funcs = []
            for m in re.finditer(r"func_[0-9A-F]{8}", asm_text):
                func_name = m.group(0)
                if func_name not in funcs:
                    funcs.append(func_name)
                if len(funcs) == 3:
                    break

            if len(funcs) != 3:
                print("Error: Couldn't find all functions in effect " + effect_num)
                continue

            renames.append(f"{funcs[0]} fx_{effect_num}_init\n")
            renames.append(f"{funcs[1]} fx_{effect_num}_update\n")
            renames.append(f"{funcs[2]} fx_{effect_num}_render\n")

with open("tools/to_rename.txt", "w", newline="\n") as f:
    f.writelines(renames)
