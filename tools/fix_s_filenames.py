#!/usr/bin/python3

# Renames asm/nonmatchings/ files to match the glabel they hold.

import argparse
import os
import re

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = script_dir + "/../"
asm_dir = root_dir + "asm/nonmatchings/"

for root, dirs, files in os.walk(asm_dir):
    for f_name in files:
        if f_name.endswith(".s"):
            f_path = os.path.join(root, f_name)

            with open(f_path, "r") as f:
                line = f.readlines()[3]

            if not line.startswith("glabel "):
                print(f"??? {f_path}")
                continue

            func_name = line.split(" ")[1].rstrip()
            parent_path = os.path.split(f_path)[:-1]
            new_f_path = os.path.join(*parent_path, func_name + ".s")

            if f_path != new_f_path:
                print(f"{f_path} => {new_f_path}")
                os.rename(f_path, new_f_path)
