#!/usr/bin/python3

import argparse
import os
import re

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = script_dir + "/../"
src_dir = root_dir + "src/"
asm_dir = root_dir + "asm/"

with open(os.path.join(script_dir, "manual_renames.txt")) as f:
    renames_text = f.readlines()

to_line = renames_text[0].strip()
func_name = to_line[to_line.rfind("/") + 1:to_line.find(".")]


for root, dirs, files in os.walk(asm_dir):
    for f_name in files:
        if f_name.endswith(".s"):
            f_path = os.path.join(root, f_name)
            with open(f_path) as f:
                f_text_orig = f.read()

            f_text = f_text_orig
            for rename_text in renames_text:
                r_from = rename_text[rename_text.find("+") + 1 : rename_text.rfind("+")]
                r_to = rename_text[rename_text.find("-") + 1 : rename_text.rfind("-")]
                f_text = f_text.replace(r_from, r_to)
            if f_text != f_text_orig:
                with open(f_path, "w", newline="\n") as f:
                    f.write(f_text)
