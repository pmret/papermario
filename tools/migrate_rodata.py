#!/usr/bin/python3

import os
from pathlib import Path

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = script_dir + "/../"
asm_dir = root_dir + "ver/current/asm/"
asm_world_dir = asm_dir + "nonmatchings/world/"
asm_data_dir = asm_dir + "data/"

def handle_symbol(area, symbol):
    for root, dirs, files in os.walk(asm_world_dir + area[0] + "/" + area[1]):
        for f_name in files:
            if f_name.endswith(".s"):
                f_path = os.path.join(root, f_name)

                with open(f_path) as f:
                    asm_lines = f.readlines()

                has_rodata_section = False
                for line in asm_lines:
                    if ".section .rodata" in line:
                        has_rodata_section = True
                        continue
                    if symbol[1] in line:
                        if not has_rodata_section:
                            asm_lines.insert(3, ".section .rodata\n")
                            asm_lines.insert(4, "\n")
                            asm_lines.insert(5, ".section .text\n")
                            asm_lines.insert(6, "\n")
                        asm_lines.insert(5, f"glabel {symbol[1]}\n")
                        asm_lines.insert(6, f"{symbol[2]}\n")
                        asm_lines.insert(7, "\n")

                        with open(f_path, "w", newline="\n") as f:
                            f.write("".join(asm_lines))

                        return True
    return False


def handle_file(f_path):
    with open(f_path) as f:
        rodata_lines = f.readlines()[4:]

    area = Path(f_path).parent.parts[-2:]

    symbols = []
    for i in range(0, len(rodata_lines), 3):
        l1 = rodata_lines[i].strip()
        l2 = rodata_lines[i + 1].strip()
        symbols.append((i + 4, l1.split()[1], l2))

    for symbol in reversed(symbols):
        migrated = handle_symbol(area, symbol)

# Walk through asm files and rename stuff
print("Walking through asm files")
for root, dirs, files in os.walk(asm_data_dir):
    for f_name in files:
        if f_name.endswith(".rodata.s"):
            f_path = os.path.join(root, f_name)

            handle_file(f_path)
