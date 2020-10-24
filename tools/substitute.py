#!/usr/bin/python3

import argparse
from collections import OrderedDict
import os
import re
import pickle
import sys

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = script_dir + "/../"
src_dir = root_dir + "src/"


parser = argparse.ArgumentParser(description="Replace many functions with one")
parser.add_argument("from_list", help="path to line-separated file of functions to be replaced")

args = parser.parse_args()

from_funcs = []

with open(args.from_list) as f:
    from_text = f.readlines()

to_line = from_text[0].strip()

for from_line in from_text[1:]:
    if len(from_line.strip()) > 0:
        from_funcs.append(from_line.rstrip().split(" ")[-1])

for root, dirs, files in os.walk(src_dir):
    for f_name in files:
        if f_name.endswith(".c"):
            if f_name == "D8FBA0.c":
                dog = 5

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
            
