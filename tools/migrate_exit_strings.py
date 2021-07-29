#!/usr/bin/python3

import os
from pathlib import Path

import pylibyaml
import yaml

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = script_dir + "/../"
asm_dir = root_dir + "ver/current/asm/"
asm_world_dir = asm_dir + "nonmatchings/world/"
asm_data_dir = asm_dir + "data/"
src_dir = root_dir + "src/"

with open(root_dir + "ver/current/splat.yaml") as f:
    config = yaml.load(f.read(), Loader=yaml.SafeLoader)

for segment in config["segments"]:
    if "dir" in segment and "world/area_" in segment["dir"]:
        c_file_path = f"{src_dir}{segment['dir']}/{segment['subsegments'][0][0]:X}.c"

        if not os.path.exists(c_file_path):
            continue

        with open(c_file_path) as f:
            c_lines = f.readlines()

        if len(c_lines[1].strip()) != 0:
            c_lines.insert(1, "\n")

        # Skip if there already are some
        if "exit_str" in c_lines[2]:
            continue

        # Skip if subsegments don't end in data end marker
        if len(segment["subsegments"][-1]) != 1:
            continue

        asm_file_path = f"{asm_data_dir}{segment['dir']}/{segment['subsegments'][-1][0]:X}.rodata.s"

        if not os.path.exists(asm_file_path):
            continue

        with open(asm_file_path) as f:
            asm_lines = f.readlines()

        exit_data = asm_lines[5].strip()

        if not exit_data.startswith(".word") or "L" in exit_data:
            continue

        exit_data = exit_data.replace(", 0x", "")[8:]

        exit_strings = []
        for i in range(0, len(exit_data), 16):
            exit_string = exit_data[i : i + 16]
            decoded = bytearray.fromhex(exit_string).replace(b"\0", b"").decode("EUC-JP")
            exit_strings.append(decoded)

        for i in range(len(exit_strings)):
            c_lines.insert(2 + i, f'static char* N(exit_str_{i}) = "{exit_strings[i]}";\n')
        c_lines.insert(2 + len(exit_strings), "\n")

        with open(c_file_path, "w", newline="\n") as f:
            f.write("".join(c_lines))

