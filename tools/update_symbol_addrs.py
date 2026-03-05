#!/usr/bin/env python3

import pathlib
import re
import subprocess
import sys
import typing

import tqdm


# Always the same
SCRIPT_DIRECTORY = pathlib.Path(__file__).parent
ROOT_DIRECTORY = SCRIPT_DIRECTORY.parent
VERSION_DIRECTORY = ROOT_DIRECTORY / 'ver'
AVAILABLE_VERSIONS = [item.name for item in VERSION_DIRECTORY.iterdir() if item.is_dir()]

ASM_DIRECTORY = ROOT_DIRECTORY / 'asm' / 'nonmatchings'
IGNORES_PATH = ROOT_DIRECTORY / 'tools' / 'ignored_funcs.txt'

IGNORE_RE = re.compile(r"(?P<symbol>\S+)\s*=\s*0[xX](?P<address>[0-9a-fA-F]+);")
MAP_BLOCK_RE = re.compile(r"(?:\.(?P<label>\S+))?\s+0[xX](?P<ram>[0-9a-fA-F]+)\s+0[xX](?P<size>[0-9a-fA-F]+) load address 0[xX](?P<rom>[0-9a-fA-F]+)")
MAP_ENTRY_RE = re.compile(r"(?:\.(?P<bss_label>\S+))?\s+0[xX](?P<ram>[0-9a-fA-F]+)\s+(?:0[xX](?P<bss_size>[0-9a-fA-F]+)\s+)?(?P<label>\S+)")
SYMBOL_ADDR_RE = re.compile(r"(?:(?P<symbol>\S+))?\s*=\s*0[xX](?P<addr>[0-9a-fA-F]+);(?:\s*//\s*(?P<opts>.+?)\s*)?$")
SYMBOL_ADDR_OPT_RE = re.compile(r"(?P<key>\S+):(?P<value>\S*)")

# Varies on version
current_ver = sys.argv[1] if len(sys.argv) > 1 else 'current'
current_ver_dir = VERSION_DIRECTORY / current_ver
assert current_ver_dir.is_dir(), f"first argument passed (`{current_ver}`) should be a valid version, available: {', '.join(AVAILABLE_VERSIONS)}"

symbol_addrs_path = current_ver_dir / 'symbol_addrs.txt'
elf_path = current_ver_dir / 'build' / 'papermario.elf'
map_path = current_ver_dir / 'build' / 'papermario.map'

# Runtime
map_symbols = {}
symbol_addrs = []
dead_symbols = []
elf_symbols = []

ignores: typing.Set[str] = set()

verbose = False


def read_ignores():
    with open(IGNORES_PATH) as f:
        lines = f.readlines()

    for line in lines:
        ignore = IGNORE_RE.match(line)

        if ignore:
            ignores.add(ignore.group('symbol'))


def scan_map():
    ram_offset = None
    cur_file = "<no file>"

    with open(map_path) as f:
        for line in f:
            if "load address" in line:
                block = MAP_BLOCK_RE.match(line)

                if block is None:
                    continue

                ram = int(block.group('ram'), 16)
                rom = int(block.group('rom'), 16)
                ram_offset = ram - rom
                continue

            if ram_offset is None or "=" in line or "*fill*" in line or " 0x" not in line:
                continue

            entry = MAP_ENTRY_RE.match(line)

            if entry is None:
                continue

            ram = int(entry.group('ram'), 16)
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
    unique_lines: typing.Set[str] = set()

    with open(symbol_addrs_path, "r") as f:
        for line in f.readlines():
            unique_lines.add(line)

        for line in unique_lines:
            if "_ROM_START" in line or "_ROM_END" in line:
                continue

            entry = SYMBOL_ADDR_RE.match(line)

            if entry is None:
                continue

            name = entry.group('symbol')
            addr = int(entry.group('addr'), 16)
            opts_group = entry.group('opts')
            opts: typing.Dict[str, str] = {}

            if opts_group is not None:
                for opt_group in SYMBOL_ADDR_OPT_RE.finditer(opts_group):
                    opts[opt_group.group('key')] = opt_group.group('value')

            dead = 'dead' in opts
            type = opts.get('type', '')
            rom = int(opts['rom'], 16) if 'rom' in opts else -1

            if not dead:
                symbol_addrs.append([name, addr, type, rom, opts])
            else:
                dead_symbols.append([name, addr, type, rom, opts])


def read_elf():
    try:
        result = subprocess.run(["mips-linux-gnu-objdump", "-x", elf_path], stdout=subprocess.PIPE)
        objdump_lines = result.stdout.decode().split("\n")
    except Exception:
        print(f"Error: Could not run objdump on {elf_path} - make sure that the project is built")
        sys.exit(1)

    for line in objdump_lines:
        if " F " in line or " O " in line or " *ABS*" in line:
            components = line.split()
            name = components[-1]

            if "_ROM_START" in name or "_ROM_END" in name:
                continue

            if (
                "/" in name
                or "." in name
                or name in ignores
                or name.startswith("_")
                or name.startswith("jtbl_")
                or name.endswith(".o")
                or re.match(r"L[0-9A-F]{8}", name)
            ):
                continue

            addr = int(components[0], 16)
            if " F " in line or name.startswith("func_"):
                type = "func"
            else:
                type = "data"

            rom = None

            if name in map_symbols:
                rom = map_symbols[name][0]
            elif re.match(".*_[0-9A-F]{8}_[0-9A-F]{6}", name):
                rom = int(name.split("_")[-1], 16)

            elf_symbols.append((name, addr, type, rom))


def log(s):
    if verbose:
        print(s)


def reconcile_symbols():
    print(f"Processing {str(len(elf_symbols))} elf symbols...")

    for i, elf_sym in tqdm.tqdm(enumerate(elf_symbols), total=len(elf_symbols)):
        name_match = None
        rom_match = None

        for known_sym in symbol_addrs:
            # Name
            if not name_match:
                if elf_sym[0] == known_sym[0]:
                    name_match = known_sym

                    if elf_sym[1] != known_sym[1]:
                        log(
                            f"Ram mismatch! {elf_sym[0]} is 0x{elf_sym[1]:X} in the elf and 0x{known_sym[1]} in symbol_addrs"
                        )

            # Rom
            if not rom_match:
                # Todo account for either or both syms not containing a rom addr
                if elf_sym[3]:
                    if elf_sym[3] == known_sym[3]:
                        rom_match = known_sym

        if not name_match and not rom_match:
            log(f"Creating new symbol {elf_sym[0]}")
            symbol_addrs.append(
                [
                    elf_sym[0],
                    elf_sym[1],
                    elf_sym[2],
                    elf_sym[3] if elf_sym[3] else -1,
                    [],
                ]
            )
        elif not name_match:
            log(f"Renaming identical rom address symbol {rom_match[0]} to {elf_sym[0]}")
            rom_match[0] = elf_sym[0]
        elif not rom_match and elf_sym[3]:
            if name_match[3] >= 0:
                log(f"Correcting rom address {name_match[3]} to {elf_sym[3]} for symbol {name_match[0]}")
            else:
                log(f"Adding rom address {elf_sym[3]} to symbol {name_match[0]}")
            name_match[3] = elf_sym[3]


def write_new_symbol_addrs():
    with open(symbol_addrs_path, "w", newline="\n") as f:
        for symbol in sorted(symbol_addrs, key=lambda x: (x[3] == -1, x[3], x[1], x[0])):
            line = f"{symbol[0]} = 0x{symbol[1]:X}; //"
            if symbol[2] and len(symbol[2]) > 0:
                line += f" type:{symbol[2]}"
            if symbol[3] >= 0:
                line += f" rom:0x{symbol[3]:X}"
            if len(symbol[4]) > 0:
                for thing in symbol[4]:
                    line += f" {thing}"
            f.write(line + "\n")
        for symbol in sorted(dead_symbols, key=lambda x: (x[3] == -1, x[3], x[1], x[0])):
            line = f"{symbol[0]} = 0x{symbol[1]:X}; //"
            if symbol[2] and len(symbol[2]) > 0:
                line += f" type:{symbol[2]}"
            if symbol[3] >= 0:
                line += f" rom:0x{symbol[3]:X}"
            if len(symbol[4]) > 0:
                for thing in symbol[4]:
                    line += f" {thing}"
            f.write(line + "\n")


read_ignores()
scan_map()
read_symbol_addrs()

# chicken scratch cod to print out new / renamed symbols
# with open("tools/new_syms.txt") as f:
#     new_syms = f.readlines()

# new_sym_dict = {}
# for sym_line in new_syms:
#     sym_line = sym_line.strip()
#     if sym_line:
#         name, rest = sym_line.split(" = ")
#         vram = int(rest.split(";")[0], 0)
#         new_sym_dict[vram] = name

# renames = []
# adds = []
# for addr in new_sym_dict:
#     found = False
#     for thing in symbol_addrs:
#         if thing[1] == addr and not thing[0].startswith("func_") and not thing[0].startswith("D_"):
#             if new_sym_dict[addr] != thing[0]:
#                 renames.append(f"{thing[0]} -> {new_sym_dict[addr]}")
#             found = True
#             break
#     if not found:
#         adds.append(f"{new_sym_dict[addr]} = {addr:X}")

# for r in renames:
#     print(r)
# for a in adds:
#     print(a)

read_elf()
reconcile_symbols()
write_new_symbol_addrs()
