#!/usr/bin/python3

import argparse
import os
import re

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = script_dir + "/../"
asm_dir = root_dir + "asm/"


parser = argparse.ArgumentParser(description="Replace many functions with one")
parser.add_argument("from_list", help="path to line-separated file of functions to be replaced. first line is the string to replace them with")

args = parser.parse_args()

from_funcs = []

with open(args.from_list) as f:
    from_text = f.readlines()

to_line = from_text[0].strip()

for from_line in from_text[1:]:
    if len(from_line.strip()) > 0:
        from_funcs.append(from_line.rstrip().split(" ")[-1])

for root, dirs, files in os.walk(asm_dir):
    for f_name in files:
        if f_name.endswith(".s"):
            f_path = os.path.join(root, f_name)
            with open(f_path) as f:
                f_text_orig = f.read()

            f_text = f_text_orig
            for func in from_funcs:
                f_text = f_text.replace(func, to_line)
            if f_text != f_text_orig:
                with open(f_path, "w", newline="\n") as f:
                    f.write(f_text)

