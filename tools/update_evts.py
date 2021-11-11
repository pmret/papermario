#!/usr/bin/env python3

from .disasm_script import ScriptDisassembler, get_constants
from glob import glob

NAMESPACES = {
    "src/battle/area_kmr_part_1/stage/clouds.inc.c": "b_area_kmr_part_1_kmr_03",
    "src/world/common/foliage.inc.c": "kmr_03",
}

for filename in glob("src/battle/item/*.c"):
    parts = filename.split("/")[1:]
    parts[-1] = parts[-1].split(".")[0]
    NAMESPACES[filename] = "_".join(parts)

NAMESPACES["src/battle/item/UseItem.inc.c"] = "battle_item_food"

for filename in glob("src/world/*/*/*.c"):
    map_name = filename.split("/")[3]
    NAMESPACES[filename] = map_name

class UserException(Exception):
    pass

class Range:
    def __init__(self, start: int, end: int, symbol_name: str, namespace: str):
        self.start = start
        self.end = end
        self.symbol_name = symbol_name
        self.namespace = namespace

class Symbol:
    def __init__(self, ram_addr, rom_addr):
        self.ram_addr = ram_addr
        self.rom_addr = rom_addr

def parse_symbol_addrs():
    with open("ver/us/symbol_addrs.txt", "r") as f:
        lines = f.readlines()

    symbol_addrs = {}

    for line in lines:
        name = line[:line.find(" ")]

        attributes = line[line.find("//"):].split(" ")
        ram_addr = int(line[:line.find(";")].split("=")[1].strip(), base=0)
        rom_addr = next((int(attr.split(":")[1], base=0) for attr in attributes if attr.split(":")[0] == "rom"), None)

        symbol_addrs[name] = Symbol(ram_addr, rom_addr)

    return symbol_addrs

def find_old_script_ranges(lines, filename):
    """
    Finds all ranges that contain the old SCRIPT macro.
    """

    start_line_no = None
    symbol_name = None
    namespace = NAMESPACES.get(filename, filename.split("/")[-1].split(".")[0])

    for line_no, line_content in enumerate(lines):
        if "#define NAMESPACE " in line_content:
            namespace = line_content.split(" ")[2].strip()

        if "SCRIPT({" in line_content:
            start_line_no = line_no
            symbol_name = eval_namespace(line_content.split(" ")[1], namespace)
        elif "});" in line_content and start_line_no is not None:
            yield Range(start_line_no, line_no, symbol_name, namespace)
            start_line_no = None

def eval_namespace(sym, namespace):
    if sym.startswith("N("):
        return namespace + "_" + sym[2:-1]
    else:
        return sym

def replace_old_script_macros(filename, symbol_addrs):
    with open(filename, "r") as f:
        lines = f.readlines()

    with open("ver/us/baserom.z64", "rb") as rom:
        num_scripts_replaced = 0

        while True:
            try:
                range = next(find_old_script_ranges(lines, filename))
            except StopIteration:
                break

            # Replace initial line
            macro_start_idx = lines[range.start].find("SCRIPT({\n")
            if macro_start_idx == -1:
                raise Exception("Could not find SCRIPT macro start")
            lines[range.start] = lines[range.start][:macro_start_idx] + "{\n"

            # Remove other lines
            lines = lines[:range.start + 1] + lines[range.end + 1:]

            # Find the symbol
            try:
                range_sym = symbol_addrs[range.symbol_name]
            except KeyError:
                raise UserException(f"Symbol {range.symbol_name} is not in symbol_addrs")

            if not range_sym.rom_addr:
                raise UserException(f"Symbol {range.symbol_name} lacks a rom address in symbol_addrs")

            # Make local symbol map, replacing namespaced symbols with N(sym)
            local_symbol_map = {}
            for sym in symbol_addrs:
                if sym.startswith(range.namespace):
                    key = "N(" + sym[len(range.namespace)+1:] + ")"
                else:
                    key = sym

                symbol = symbol_addrs[sym]

                if symbol.ram_addr in local_symbol_map:
                    cur_sym_name = local_symbol_map[symbol.ram_addr][0][1]
                    if cur_sym_name.startswith("N("):
                        continue

                local_symbol_map[symbol.ram_addr] = [[symbol.ram_addr, key]]

            # Disassemble the script
            rom.seek(range_sym.rom_addr)
            evt_code = ScriptDisassembler(rom,
                script_name=range.symbol_name,
                romstart=range_sym.rom_addr,
                prelude=False,
                symbol_map=local_symbol_map,
            ).disassemble()
            lines.insert(range.start + 1, f"{evt_code}}};\n")

            num_scripts_replaced += 1

    if num_scripts_replaced > 0:
        with open(filename, "w") as f:
            f.writelines(lines)

    return num_scripts_replaced

if __name__ == "__main__":
    import sys

    symbol_addrs = parse_symbol_addrs()
    get_constants()

    num_errors = 0

    if len(sys.argv) > 1:
        for filename in sys.argv[1:]:
            try:
                num_scripts_replaced = replace_old_script_macros(filename, symbol_addrs)
                if num_scripts_replaced > 0:
                    print(f"{num_scripts_replaced} old scripts replaced in {filename}")
            except UserException as e:
                print(f"{filename} ERROR: {e}")
                num_errors += 1

        if num_errors > 0:
            print(f"ERROR: {num_errors} files had errors.")
            exit(1)
    else:
        print("warning: no files specified")
        print("usage: ./tools/update_evts.c <files to modify>")
