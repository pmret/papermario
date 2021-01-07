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

for root, dirs, files in os.walk(src_dir):
    for dir_name in dirs:
        dir_path = os.path.join(root, dir_name)
        map_name = Path(dir_path).parent.name
        if map_name.startswith("area_"):
            common_funcs = []

            for c_file in os.scandir(dir_path):
                if c_file.name.endswith(".c"):
                    with open(c_file) as f:
                        c_lines = f.readlines()
                    for line in c_lines:
                        if "world/common" in line:
                            common_funcs.append(line.split("/")[-1].split(".")[0])

            header_name = dir_name + ".h"
            guard_name = f"_{dir_name.upper()}_"

            out_lines = []
            # out_lines.append(f"#ifndef {guard_name}")
            # out_lines.append(f"#define {guard_name}")
            # out_lines.append("")
            out_lines.append("#include \"common.h\"")
            out_lines.append("#include \"map.h\"")
            out_lines.append("")
            out_lines.append(f"#define NAMESPACE {dir_name}")
            out_lines.append("")

            # if len(common_funcs) > 0:
            #     for func_name in common_funcs:
            #         out_lines.append(f"#include \"world/common/{func_name}.h\"")
            # out_lines.append("#endif")
            # out_lines.append("")

            with open(os.path.join(dir_path, header_name), "w", newline="\n") as f:
                f.write("\n".join(out_lines))

# for root, dirs, files in os.walk(src_dir):
#     for f_name in files:
#         if f_name.endswith(".c"):
#             f_path = os.path.join(root, f_name)
#             area_name = Path(f_path).parent.name
#             with open(f_path) as f:
#                 f_text_orig = f.readlines()
            
#             f_text = []
#             f_text.append(f"#include \"{area_name}.h\"\n")

#             for line in f_text_orig:
#                 if not line.startswith("#include") or line.startswith("#include \"world"):
#                     f_text.append(line)
#                 #new_line = re.sub(r"INCLUDE_ASM.*\);", sub_func, line)

#             if f_text != f_text_orig:
#                 with open(f_path, "w", newline="\n") as f:
#                     f.writelines(f_text)
            
