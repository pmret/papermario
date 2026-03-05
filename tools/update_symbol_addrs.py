#!/usr/bin/env python3

import dataclasses
import pathlib
import re
import subprocess
import sys
import typing

import tqdm

# Always the same
SCRIPT_DIRECTORY = pathlib.Path(__file__).parent
ROOT_DIRECTORY = SCRIPT_DIRECTORY.parent
VERSION_DIRECTORY = ROOT_DIRECTORY / "ver"
AVAILABLE_VERSIONS = [item.name for item in VERSION_DIRECTORY.iterdir() if item.is_dir()]

ASM_DIRECTORY = ROOT_DIRECTORY / "asm" / "nonmatchings"
IGNORES_PATH = ROOT_DIRECTORY / "tools" / "ignored_funcs.txt"

IGNORE_RE = re.compile(r"(?P<symbol>\S+)\s*=\s*0[xX](?P<address>[0-9a-fA-F]+);")
MAP_BLOCK_RE = re.compile(
    r"(?:\.(?P<label>\S+))?\s+0[xX](?P<ram>[0-9a-fA-F]+)\s+0[xX](?P<size>[0-9a-fA-F]+) load address 0[xX](?P<rom>[0-9a-fA-F]+)"
)
MAP_ENTRY_RE = re.compile(
    r"(?:\.(?P<bss_label>\S+))?\s+0[xX](?P<ram>[0-9a-fA-F]+)\s+(?:0[xX](?P<bss_size>[0-9a-fA-F]+)\s+)?(?P<label>\S+)"
)
SYMBOL_ADDR_RE = re.compile(r"(?:(?P<symbol>\S+))?\s*=\s*0[xX](?P<addr>[0-9a-fA-F]+);(?:\s*//\s*(?P<opts>.+?)\s*)?$")
SYMBOL_ADDR_OPT_RE = re.compile(r"(?P<key>\S+):(?P<value>\S*)")


# Dataclass definitions
@dataclasses.dataclass
class MapSymbol:
    rom: int
    file: str
    ram: int


@dataclasses.dataclass
class ELFSymbol:
    name: str
    addr: int
    type: str
    rom: typing.Optional[int]
    opts: typing.Dict[str, str]

    def ordering(self):
        return (not self.rom, self.rom, self.addr, self.name)

    def format(self) -> str:
        line = f"{self.name} = 0x{self.addr:X}; //"

        if self.type and len(self.type) > 0:
            line += f" type:{self.type}"
        if self.rom:
            line += f" rom:0x{self.rom:X}"
        if self.opts:
            for key, value in self.opts.items():
                line += f" {key}:{value}"

        return line


# Varies on version
current_ver = sys.argv[1] if len(sys.argv) > 1 else "current"
current_ver_dir = VERSION_DIRECTORY / current_ver
assert (
    current_ver_dir.is_dir()
), f"first argument passed (`{current_ver}`) should be a valid version, available: {', '.join(AVAILABLE_VERSIONS)}"

symbol_addrs_path = current_ver_dir / "symbol_addrs.txt"
elf_path = current_ver_dir / "build" / "papermario.elf"
map_path = current_ver_dir / "build" / "papermario.map"


# Runtime
map_symbols: typing.Dict[str, MapSymbol] = {}
symbol_addrs: typing.List[ELFSymbol] = []
dead_symbols: typing.List[ELFSymbol] = []
elf_symbols: typing.List[ELFSymbol] = []

ignores: typing.Set[str] = set()

verbose = False


def read_ignores():
    with open(IGNORES_PATH) as f:
        lines = f.readlines()

    for line in lines:
        ignore = IGNORE_RE.match(line)

        if ignore:
            ignores.add(ignore.group("symbol"))


def scan_map():
    ram_offset = None
    cur_file = "<no file>"

    with open(map_path) as f:
        for line in f:
            if "load address" in line:
                block = MAP_BLOCK_RE.match(line)

                if block is None:
                    continue

                ram = int(block.group("ram"), 16)
                rom = int(block.group("rom"), 16)
                ram_offset = ram - rom
                continue

            if ram_offset is None or "=" in line or "*fill*" in line or " 0x" not in line:
                continue

            entry = MAP_ENTRY_RE.match(line)

            if entry is None:
                continue

            ram = int(entry.group("ram"), 16)
            rom = ram - ram_offset
            sym = line.split()[-1]

            if "0x" in sym:
                ram_offset = None
                continue
            elif "/" in sym:
                cur_file = sym
                continue

            map_symbols[sym] = MapSymbol(rom=rom, file=cur_file, ram=ram)


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

            name = entry.group("symbol")
            addr = int(entry.group("addr"), 16)
            opts_group = entry.group("opts")
            opts: typing.Dict[str, str] = {}

            if opts_group is not None:
                for opt_group in SYMBOL_ADDR_OPT_RE.finditer(opts_group):
                    opts[opt_group.group("key")] = opt_group.group("value")

            dead = "dead" in opts
            type = opts.pop("type", "")
            rom = int(opts.pop("rom"), 16) if "rom" in opts else None

            if not dead:
                symbol_addrs.append(ELFSymbol(name=name, addr=addr, type=type, rom=rom, opts=opts))
            else:
                dead_symbols.append(ELFSymbol(name=name, addr=addr, type=type, rom=rom, opts=opts))


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
                rom = map_symbols[name].rom
            elif re.match(".*_[0-9A-F]{8}_[0-9A-F]{6}", name):
                rom = int(name.split("_")[-1], 16)

            elf_symbols.append(ELFSymbol(name=name, addr=addr, type=type, rom=rom, opts={}))


def log(s: str):
    if verbose:
        print(s)


def reconcile_symbols():
    print(f"Processing {str(len(elf_symbols))} elf symbols...")

    for elf_sym in tqdm.tqdm(elf_symbols, total=len(elf_symbols)):
        name_match: typing.Optional[ELFSymbol] = None
        rom_match: typing.Optional[ELFSymbol] = None

        for known_sym in symbol_addrs:
            # Name
            if not name_match:
                if elf_sym.name == known_sym.name:
                    name_match = known_sym

                    if elf_sym.addr != known_sym.addr:
                        log(
                            f"Ram mismatch! {elf_sym.name} is 0x{elf_sym.addr:X} in the elf and 0x{known_sym.addr} in symbol_addrs"
                        )

            # Rom
            if not rom_match:
                # Todo account for either or both syms not containing a rom addr
                if elf_sym.rom:
                    if elf_sym.rom == known_sym.rom:
                        rom_match = known_sym

        if not name_match:
            if not rom_match:
                log(f"Creating new symbol {elf_sym.name}")
                symbol_addrs.append(
                    ELFSymbol(
                        name=elf_sym.name,
                        addr=elf_sym.addr,
                        type=elf_sym.type,
                        rom=elf_sym.rom,
                        opts={},
                    )
                )
            else:
                log(f"Renaming identical rom address symbol {rom_match.name} to {elf_sym.name}")
                rom_match.name = elf_sym.name

        elif not rom_match and elf_sym.rom:
            if name_match.rom:
                log(f"Correcting rom address {name_match.rom} to {elf_sym.rom} for symbol {name_match.name}")
            else:
                log(f"Adding rom address {elf_sym.rom} to symbol {name_match.name}")
            name_match.rom = elf_sym.rom


def write_new_symbol_addrs():
    with open(symbol_addrs_path, "w", newline="\n") as f:
        for symbol in sorted(symbol_addrs, key=ELFSymbol.ordering):
            f.write(symbol.format() + "\n")

        for symbol in sorted(dead_symbols, key=ELFSymbol.ordering):
            f.write(symbol.format() + "\n")


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
