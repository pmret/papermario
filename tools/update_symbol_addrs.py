#!/usr/bin/env python3

import argparse
import dataclasses
import json
import logging
import pathlib
import re
import subprocess
import sys
import typing

import tqdm
import mapfile_parser

# Always the same
LOGGER = logging.getLogger("update_symbol_addrs")

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
    file: str
    ram: int
    size: int
    rom: typing.Optional[int]


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


def read_ignores() -> typing.Set[str]:
    with open(IGNORES_PATH) as f:
        lines = f.readlines()

    ignores: typing.Set[str] = set()

    for line in lines:
        ignore = IGNORE_RE.match(line)

        if ignore:
            ignores.add(ignore.group("symbol"))

    return ignores


def scan_map(map_file: mapfile_parser.MapFile):
    map_symbols: typing.Dict[str, MapSymbol] = {}

    for segment in map_file:
        for section in segment:
            for symbol in section:
                map_symbols[symbol.name] = MapSymbol(
                    file=str(section.filepath),
                    ram=symbol.vram,
                    size=symbol.size,
                    rom=symbol.vrom,
                )

    return map_symbols


def read_symbol_addrs(symbol_addrs_path: pathlib.Path) -> typing.Tuple[typing.List[ELFSymbol], typing.List[ELFSymbol]]:
    unique_lines: typing.Set[str] = set()

    symbol_addrs: typing.List[ELFSymbol] = []
    dead_symbols: typing.List[ELFSymbol] = []

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

    return (symbol_addrs, dead_symbols)


def read_elf(elf_path: pathlib.Path, map_symbols: typing.Dict[str, MapSymbol]) -> typing.List[ELFSymbol]:
    elf_symbols: typing.List[ELFSymbol] = []

    try:
        result = subprocess.run(["mips-linux-gnu-objdump", "-x", elf_path], stdout=subprocess.PIPE)
        objdump_lines = result.stdout.decode().split("\n")
    except Exception:
        LOGGER.error(f"Error: Could not run objdump on {elf_path} - make sure that the project is built")
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

    return elf_symbols


def reconcile_symbols(
    elf_symbols: typing.List[ELFSymbol],
    symbol_addrs: typing.List[ELFSymbol],
):
    LOGGER.info(f"Processing {str(len(elf_symbols))} elf symbols...")

    for elf_sym in tqdm.tqdm(elf_symbols, total=len(elf_symbols)):
        name_match: typing.Optional[ELFSymbol] = None
        rom_match: typing.Optional[ELFSymbol] = None

        for known_sym in symbol_addrs:
            # Name
            if not name_match:
                if elf_sym.name == known_sym.name:
                    name_match = known_sym

                    if elf_sym.addr != known_sym.addr:
                        LOGGER.debug(
                            f"Ram mismatch! {elf_sym.name} is 0x{elf_sym.addr:X} in the elf and 0x{known_sym.addr:X} in symbol_addrs"
                        )

            # Rom
            if not rom_match:
                # Todo account for either or both syms not containing a rom addr
                if elf_sym.rom:
                    if elf_sym.rom == known_sym.rom:
                        rom_match = known_sym

        if not name_match:
            if not rom_match:
                LOGGER.debug(f"Creating new symbol {elf_sym.name}")
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
                LOGGER.debug(f"Renaming identical rom address symbol {rom_match.name} to {elf_sym.name}")
                rom_match.name = elf_sym.name

        elif not rom_match and elf_sym.rom:
            if name_match.rom:
                LOGGER.debug(f"Correcting rom address {name_match.rom} to {elf_sym.rom} for symbol {name_match.name}")
            else:
                LOGGER.debug(f"Adding rom address {elf_sym.rom} to symbol {name_match.name}")
            name_match.rom = elf_sym.rom


def write_new_symbol_addrs(
    symbol_addrs_path: pathlib.Path,
    symbol_addrs: typing.List[ELFSymbol],
    dead_symbols: typing.List[ELFSymbol],
):
    with open(symbol_addrs_path, "w", newline="\n") as f:
        for symbol in sorted(symbol_addrs, key=ELFSymbol.ordering):
            f.write(symbol.format() + "\n")

        for symbol in sorted(dead_symbols, key=ELFSymbol.ordering):
            f.write(symbol.format() + "\n")


if __name__ == "__main__":
    # Parse arguments
    parser = argparse.ArgumentParser(description="Updates symbol_addrs.txt files")

    parser.add_argument("version", type=str, help="The version to use (e.g. 'pal')")
    parser.add_argument("-v", "--verbose", action="store_true", help="Enable verbose output")
    parser.add_argument("--output-csv", type=str, default=None, help="An optional path to output a map file CSV to.")
    parser.add_argument("--output-json", type=str, default=None, help="An optional path to output a map file CSV to.")

    args = parser.parse_args()

    version: str = args.version
    verbose: bool = args.verbose

    # Initialize logging
    logging.basicConfig(level=logging.DEBUG if verbose else logging.INFO)

    # Version-specific files
    current_ver_dir = VERSION_DIRECTORY / version
    assert (
        current_ver_dir.is_dir()
    ), f"first argument passed (`{version}`) should be a valid version, available: {', '.join(AVAILABLE_VERSIONS)}"

    symbol_addrs_path = current_ver_dir / "symbol_addrs.txt"
    elf_path = current_ver_dir / "build" / "papermario.elf"
    map_path = current_ver_dir / "build" / "papermario.map"

    # Runtime
    map_file = mapfile_parser.MapFile.newFromMapFile(map_path)

    if args.output_csv:
        with open(args.output_csv, "w", encoding="utf-8") as fp:
            fp.write(map_file.toCsv())

    if args.output_json:
        with open(args.output_json, "w", encoding="utf-8") as fp:
            json.dump(map_file.toJson(), fp)

    ignores = read_ignores()
    map_symbols = scan_map(map_file)

    symbol_addrs, dead_symbols = read_symbol_addrs(symbol_addrs_path)
    elf_symbols = read_elf(elf_path, map_symbols)

    reconcile_symbols(elf_symbols, symbol_addrs)
    write_new_symbol_addrs(symbol_addrs_path, symbol_addrs, dead_symbols)
