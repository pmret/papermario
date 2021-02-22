#!/usr/bin/python3

import os
import sys
import subprocess
from pathlib import Path

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = os.path.abspath(os.path.join(script_dir, ".."))
src_dir = root_dir + "/src/"
asm_dir = root_dir + "/ver/current/asm/"

common_files = []

for root, dirs, files in os.walk(os.path.join(src_dir, "world", "common")):
    for fname in files:
        if fname.endswith(".inc.c"):
            common_files.append(fname[:-6])

for root, dir, files in os.walk(os.path.join(asm_dir, "nonmatchings", "world")):
    for fname in files:
        if fname.endswith(".s"):
            prefix = Path(root).parent.name + "_"
            with open(os.path.join(root, fname)) as f:
                orig_text = f.read()
            new_text = orig_text
            for common in common_files:
                new_text = new_text.replace(" " + common, " " + prefix + common)
            if new_text != orig_text:
                with open(os.path.join(root, fname), "w", newline="\n") as f:
                    f.write(new_text)
