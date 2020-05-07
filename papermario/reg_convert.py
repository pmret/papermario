#!/usr/bin/python3
import fileinput
import os
import re

script_dir = os.path.dirname(os.path.realpath(__file__))
asm_dir = script_dir + "/asm/"

regs = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3", "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7", "s0",
        "s1", "s2", "s3", "s4", "s5", "s6", "s7", "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]


for line in fileinput.input():
    for reg in regs:
        regex = re.compile("\\$" + reg)
        line = re.sub(regex, "$" + str(regs.index(reg)), line)
    print(line.rstrip())
