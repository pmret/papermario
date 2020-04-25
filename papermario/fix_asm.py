#!/usr/bin/python3

import os
import re

script_dir = os.path.dirname(os.path.realpath(__file__))
asm_dir = script_dir + "/asm/"

# regs = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7", "s0",
#         "s1", "s2", "s3", "s4", "s5", "s6", "s7", "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]


def replace_func(match):
    match = match.group()
    match = re.sub("\\s+", " ", match)
    match_split = match.split(" ")
    ret = "daddu " + match_split[1] + " " + match_split[2] + ", $zero"
    return ret


for root, dirs, files in os.walk(asm_dir):
    for file in files:
        if file.endswith(".s"):
            with open(os.path.join(root, file)) as f:
                file_text_orig = f.read()
                file_text = file_text_orig

                # Rename registers to numbers
                # for reg in regs:
                #     regex = re.compile("\\$" + reg)
                #     file_text = re.sub(regex, "$" + str(regs.index(reg)), file_text)

                # Fix instructions
                regex = re.compile("move\\s+\\$.+,\\s\\$.+")
                file_text = re.sub(regex, replace_func, file_text)

                if file_text != file_text_orig:
                    with open(os.path.join(root, file), "w") as f:
                        f.write(file_text)
