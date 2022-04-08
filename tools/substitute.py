#!/usr/bin/python3

import argparse
import os
import re
from pathlib import Path
from unicodedata import name

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = script_dir + "/../"
src_dir = root_dir + "src/"
asm_dir = root_dir + "ver/current/asm/"

parser = argparse.ArgumentParser(description="Replace many functions with one")
parser.add_argument("from_list", help="path to line-separated file of functions to be replaced. first line is the string to replace them with")

args = parser.parse_args()

from_funcs = []

with open(args.from_list) as f:
    from_text = f.readlines()

to_line = from_text[0].strip()
func_name = to_line[to_line.rfind("/") + 1:to_line.find(".")]

for from_line in from_text[1:]:
    if len(from_line.strip()) > 0:
        from_funcs.append(from_line.rstrip().split(" ")[-1])

for root, dirs, files in os.walk(src_dir):
    for f_name in files:
        if f_name.endswith(".c"):
            f_path = os.path.join(root, f_name)
            with open(f_path) as f:
                f_text_orig = f.read()

            f_text = f_text_orig
            for func in from_funcs:
                search_pattern = re.compile("\n.*" + func + "\).*\n")
                f_text = re.sub(search_pattern, "\n" + to_line + "\n", f_text)
            if f_text != f_text_orig:
                with open(f_path, "w", newline="\n") as f:
                    f.write(f_text)

# # Rename symbols in from_funcs to namespace equivalents
# for root, dirs, files in os.walk

for root, dirs, files in os.walk(asm_dir):
    for f_name in files:
        if f_name.endswith(".s"):
            f_path = os.path.join(root, f_name)
            with open(f_path) as f:
                f_text_orig = f.read()

            f_text = f_text_orig

            if Path(f_path).parent.parent.name == "nonmatchings":
                namespace = Path(f_path).parent.name
            else:
                namespace = Path(f_path).parent.parent.name

            # TODO refactor into new func
            if f_name[:-2] in from_funcs:
                syms = list(set(re.findall(r"D_[0-9A-F]{8}_[0-9A-F]{6}", f_text)))
                print(f"{syms[0]} {namespace}_varTable")

            for func in from_funcs:
                f_text = f_text.replace(func, namespace + "_" + func_name)
            if f_text != f_text_orig:
                with open(f_path, "w", newline="\n") as f:
                    f.write(f_text)
