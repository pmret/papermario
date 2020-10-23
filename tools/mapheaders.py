#!/usr/bin/python3

import argparse
from collections import OrderedDict
import os
import re
import pickle
import sys
from pathlib import Path

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = script_dir + "/../"
src_dir = root_dir + "src/world/"
asm_dir = root_dir + "asm/nonmatchings/world/"


def sub_func(match):
    m_str = match.group()
    m_str_split = m_str.split(", ")
    func_name = m_str_split[-1][:-2]

    path_elems = m_str_split[-2].split("/")[1:]

    asmd = os.path.join(asm_dir, path_elems[0], path_elems[1], path_elems[2][:-1])

    for root, dirs, files in os.walk(asmd):
        for f_name in files:
            f_name = f_name[:-2]
            if f_name.startswith(func_name) and len(f_name) > len(func_name):
                return m_str.replace(func_name, f_name)
    return m_str


for root, dirs, files in os.walk(src_dir):
    for f_name in files:
        if f_name.endswith(".c"):
            f_path = os.path.join(root, f_name)
            area_name = Path(f_path).parent.name
            with open(f_path) as f:
                f_text_orig = f.readlines()
            
            f_text = []

            if f_name == "DF6A20.c":
                dog = 5

            for line in f_text_orig:
                new_line = re.sub(r"INCLUDE_ASM.*\);", sub_func, line)
                f_text.append(new_line)

            if f_text != f_text_orig:
                with open(f_path, "w", newline="\n") as f:
                    f.writelines(f_text)
            
