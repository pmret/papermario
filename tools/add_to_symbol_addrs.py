#!/usr/bin/python3

import os
import re
import subprocess
import sys

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = script_dir + "/../"
asm_dir = root_dir + "asm/nonmatchings/"

symbol_addrs_path = os.path.join(script_dir, "symbol_addrs.txt")
elf_path = os.path.join(root_dir, "build", "papermario.elf")
map_path = os.path.join(root_dir, "build", "papermario.map")

map_symbols = {}
symbol_addrs = []
elf_symbols = []

def scan_map():
    ram_offset = None
    cur_file = "<no file>"
    prev_line = ""
    with open(map_path) as f:
        for line in f:
            if "load address" in line:
                ram = int(line[16 : 16 + 18], 0)
                rom = int(line[59 : 59 + 18], 0)
                ram_offset = ram - rom
                continue

            prev_line = line

            if (
                ram_offset is None
                or "=" in line
                or "*fill*" in line
                or " 0x" not in line
            ):
                continue

            ram = int(line[16 : 16 + 18], 0)
            rom = ram - ram_offset
            sym = line.split()[-1]

            if "0x" in sym:
                ram_offset = None
                continue
            elif "/" in sym:
                cur_file = sym
                continue

            map_symbols[sym] = (rom, cur_file, ram)

def read_symbol_addrs():
    unique_lines = set()

    with open(symbol_addrs_path, "r") as f:
        for line in f.readlines():
                unique_lines.add(line)

        for line in unique_lines:
            main, ext = line.rstrip().split(";")
            args = ext.split("//")[-1].strip().split(" ")
            name, addr = main.split(" = ")
            symbol_addrs.append((name, int(addr, 0), args))

def read_elf():
    try:
        result = subprocess.run(['objdump', '-x', elf_path], stdout=subprocess.PIPE)
        objdump_lines = result.stdout.decode().split("\n")
    except:
        print(f"Error: Could not run objdump on {elf_path} - make sure that the project is built")
        sys.exit(1)

    for line in objdump_lines:
        if " F " in line or " O " in line or " *ABS*" in line:
            components = line.split()
            name = components[-1]

            if "/" in name or \
               name.startswith("_") or \
               name.startswith("jtbl_") or \
               re.match(r"L[0-9A-F]{8}", name):
                continue

            addr = int(components[0], 16)
            if " F " in line:
                type = "func"
            else:
                type = "data"

            opts = [f"type:{type}"]

            if name in map_symbols:
                opts.append(f"rom:0x{map_symbols[name][0]:X}")
            elif re.match(".*_[0-9A-F]{8}_[0-9A-F]{6}", name):
                rom = name.split("_")[-1]
                opts.append(f"rom:0x{rom}")

            elf_symbols.append((name, addr, opts))

def reconcile_symbols():
    print(f"Processing {str(len(elf_symbols))} elf symbols...")

    for i, sym in enumerate(elf_symbols):
        if i % 1000 == 0:
            print(i)
        name_match = None
        rom_match = None

        for sym2 in symbol_addrs:

            # Name
            if not name_match:
                if sym[0] == sym2[0]:
                    name_match = sym2

                    if sym[1] != sym2[1]:
                        print(f"Address mismatch! {sym[0]} is 0x{sym[1]:X} in the elf and 0x{sym2[1]} in symbol_addrs")

                    if not rom_match:
                        if sym[2] == sym2[2]:
                            rom_match = sym2

            # Rom
            if not rom_match:
                # Todo account for either or both syms not containing a rom addr
                if sym[2] == sym2[2]:
                    rom_match = sym2

                    if not name_match:
                        if sym[0] == sym2[1]:
                            name_match = sym2

        if not name_match and not rom_match:
            # Todo add new symbol to symbol_addrs
            pass
        elif not name_match:
            #todo rename symbol in symbol_addrs
            pass
        elif not rom_match:
            # todo add rom addr in symbol_addrs
            pass


scan_map()
read_symbol_addrs()
read_elf()
reconcile_symbols()
