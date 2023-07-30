#!/usr/bin/env python3

import os.path
import argparse

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = os.path.abspath(os.path.join(script_dir, ".."))

parser = argparse.ArgumentParser(description="Display various information about a symbol or address.")
parser.add_argument("name", type=str, default="", help="symbol name or ROM/RAM address to lookup")
parser.add_argument(
    "-e",
    "--expected",
    dest="use_expected",
    action="store_true",
    help="use the map file in expected/build/ instead of build/",
)


def get_map(expected: bool = False):
    mymap = os.path.join(root_dir, "ver", "current", "build", "papermario.map")
    if expected:
        mymap = os.path.join(root_dir, "ver", "current", "expected", "build", "papermario.map")
    return mymap


def search_address(target_addr, map=get_map()):
    is_ram = target_addr & 0x80000000
    ram_offset = None
    prev_ram = 0
    prev_rom = 0
    prev_sym = "<start of rom>"
    cur_file = "<no file>"
    prev_file = cur_file
    prev_line = ""
    with open(map) as f:
        for line in f:
            if "load address" in line:
                # Ignore .bss sections if we're looking for a ROM address
                if not is_ram and (".bss" in line or ".bss" in prev_line):
                    ram_offset = None
                    continue
                ram = int(line[16 : 16 + 18], 0)
                rom = int(line[59 : 59 + 18], 0)
                ram_offset = ram - rom
                continue

            prev_line = line

            if ram_offset is None or "=" in line or "*fill*" in line or " 0x" not in line:
                continue

            ram = int(line[16 : 16 + 18], 0)
            rom = ram - ram_offset
            sym = line.split()[-1]

            if "0x" in sym:
                ram_offset = None
                continue
            if "/" in sym:
                cur_file = sym
                continue

            if rom == target_addr or (is_ram and ram == target_addr):
                return f"{sym} (RAM 0x{ram:X}, ROM 0x{rom:X}, {cur_file})"
            if rom > target_addr or (is_ram and ram > target_addr):
                offset = target_addr - prev_ram if is_ram else target_addr - prev_rom
                return f"at 0x{offset:X} bytes inside {prev_sym} (RAM 0x{prev_ram:X}, ROM 0x{prev_rom:X}, {prev_file})"

            prev_ram = ram
            prev_rom = rom
            prev_sym = sym
            prev_file = cur_file

    return "at end of rom?"


def search_symbol(target_sym, map=get_map()):
    ram_offset = None
    cur_file = "<no file>"
    prev_line = ""
    with open(map) as f:
        for line in f:
            if "load address" in line:
                ram = int(line[16 : 16 + 18], 0)
                rom = int(line[59 : 59 + 18], 0)
                ram_offset = ram - rom
                continue

            prev_line = line

            if ram_offset is None or "=" in line or "*fill*" in line or " 0x" not in line:
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

            if sym == target_sym:
                return (rom, cur_file, ram)

    return None


if __name__ == "__main__":
    args = parser.parse_args()

    map = get_map(args.use_expected)

    if not os.path.isfile(map):
        print(f"{map} must exist.")
        exit(1)

    try:
        target_addr = int(args.name, 0)
        print(args.name, "is", search_address(target_addr))
    except ValueError:
        sym_info = search_symbol(args.name)
        if sym_info is not None:
            sym_rom = sym_info[0]
            sym_file = sym_info[1]
            sym_ram = sym_info[2]
            print(f"Symbol {args.name} (RAM: 0x{sym_ram:08X}, ROM: 0x{sym_rom:06X}, {sym_file})")
        else:
            print(f"Symbol {args.name} not found in map file {map}")
