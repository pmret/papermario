#!/usr/bin/python3

import glob
import os
import re
import sys
import subprocess
from pathlib import Path

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = os.path.abspath(os.path.join(script_dir, ".."))

import glob, os
os.chdir(root_dir)

for f in Path(root_dir).rglob("*.bin"):
    if "papermario" in f.name:
        continue
    if f.name in ["bin_11A440.bin", "code_71430.bin", "bootcode_font.bin", "bin_E20110.bin"]:
        continue

    ras = []
    result = subprocess.run(["mips-linux-gnu-objdump", "-Dz",  "-bbinary", "-mmips", "-EB" , f], stdout=subprocess.PIPE)
    output = result.stdout.decode().split("\n")

    for line in output:
        if re.match(r".*jr.*ra.*", line):
            ras.append(line)

    if len(ras) > 0:
        print(f"{f.name} : {len(ras)}")
        for line in ras:
            print(line)
        print("")
