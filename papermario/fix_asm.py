#!/usr/bin/python3

import os
import re

script_dir = os.path.dirname(os.path.realpath(__file__))
asm_dir = script_dir + "/asm/"

regs = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7", "s0",
        "s1", "s2", "s3", "s4", "s5", "s6", "s7", "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]

for root, dirs, files in os.walk(asm_dir):
    for file in files:
        if file.endswith(".s"):
            with open(os.path.join(root, file)) as f:
                file_text_orig = f.read()
                file_text = file_text_orig
                for reg in regs:
                    regex = re.compile("\\$" + reg)
                    file_text = re.sub(regex, "$" + str(regs.index(reg)), file_text)
                if file_text != file_text_orig:
                    with open(os.path.join(root, file), "w") as f:
                        f.write(file_text)