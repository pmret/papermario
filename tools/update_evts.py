#!/usr/bin/python3

from disasm_script import ScriptDisassembler

NAMESPACES = {
    "src/battle/item/thunder_bolt.c": "battle_item_thunder_bolt",
    "src/battle/item/strange_cake.c": "battle_item_strange_cake",
    "src/battle/item/tasty_tonic.c": "battle_item_tasty_tonic",
    "src/battle/item/egg_missile.c": "battle_item_egg_missile",
}

class Range:
    def __init__(self, start: int, end: int, symbol_name: str):
        self.start = start
        self.end = end
        self.symbol_name = symbol_name

def parse_symbol_addrs():
    with open("ver/us/symbol_addrs.txt", "r") as f:
        lines = f.readlines()

    symbol_addrs = {}

    for line in lines:
        name = line[:line.find(" ")]

        attributes = line[line.find("//"):].split(" ")
        rom_addr = next((int(attr.split(":")[1], base=0) for attr in attributes if attr.split(":")[0] == "rom"), None)

        symbol_addrs[name] = rom_addr

    return symbol_addrs

def find_old_script_ranges(lines, filename):
    """
    Finds all ranges that contain the old SCRIPT macro.
    """

    start_line_no = None
    symbol_name = None
    namespace = NAMESPACES.get(filename, "UNK_NAMESPACE")

    for line_no, line_content in enumerate(lines):
        if "#define NAMESPACE " in line_content:
            namespace = line_content.split(" ")[2].strip()

        if "SCRIPT({" in line_content:
            start_line_no = line_no
            symbol_name = eval_namespace(line_content.split(" ")[1], namespace)
        elif "});" in line_content and start_line_no is not None:
            yield Range(start_line_no, line_no, symbol_name)
            start_line_no = None

def eval_namespace(sym, namespace):
    if sym.startswith("N("):
        return namespace + "_" + sym[2:-1]
    else:
        return sym

def all_source_files():
    from glob import glob

    return glob("src/**/*.c", recursive=True)

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
            rom_addr = symbol_addrs[range.symbol_name]

            if not rom_addr:
                raise Exception(f"Symbol {range.symbol_name} lacks a rom address in symbol_addrs")

            # Disassemble the script
            rom.seek(rom_addr)
            evt_code = ScriptDisassembler(rom,
                script_name=range.symbol_name,
                romstart=rom_addr,
                prelude=False,
            ).disassemble()
            lines.insert(range.start + 1, f"{evt_code}}};\n")

            num_scripts_replaced += 1
            print(range.symbol_name)

    if num_scripts_replaced > 0:
        with open(filename, "w") as f:
            f.writelines(lines)

    return num_scripts_replaced

if __name__ == "__main__":
    symbol_addrs = parse_symbol_addrs()

    for filename in all_source_files():
        print(f"Updating {filename}")
        num_scripts_replaced = replace_old_script_macros(filename, symbol_addrs)
        #if num_scripts_replaced > 0:
        #    break
