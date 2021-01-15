#!/usr/bin/python3

import argparse
import os
import re

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = script_dir + "/../"
src_dir = root_dir + "src/"
asm_dir = root_dir + "asm/"

symbol = "gMasterGfxPos"

smallest_file = None
smallest_len = 1000

for root, dirs, files in os.walk(asm_dir):
    for f_name in files:
        if f_name.endswith(".s") and not f_name.startswith("func_E") and len(f_name) < 20 and f_name not in ["func_8011800C.s", "func_E011A3BC.s", "func_8024F768.s", "func_800271A0.s", "func_80240448_B141B8.s"]:
            f_path = os.path.join(root, f_name)
            with open(f_path) as f:
                f_text = f.read()

            if symbol in f_text:
                num_lines = len(f_text.split("\n"))
                if num_lines <= smallest_len:
                    print(f"{f_name}: {int(num_lines)}")
                    smallest_len = num_lines
                    smallest_file = f_name

print("\n" + smallest_file)
