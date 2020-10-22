#! /usr/bin/python3

import sys
import os
import yaml
from struct import unpack
from disasm_script import disassemble as disassemble_script

def disassemble(bytes, offset, midx, symbol_map = {}, map_name = "map"):
    out = ""
    found_data = False

    while len(midx) > 0:
        struct = midx.pop(0)
        name = struct["name"]
        if name == "Script_Main": name = f"M(Main)"

        #print(f"{offset:X} ({name}, start = {struct['start']:X}, len = {struct['length']:X})")

        if struct["start"] == offset:
            found_data = True

            if struct["start"] != offset:
                # end of data / padding
                break

            # format struct
            if struct["type"].startswith("Script"):
                out += disassemble_script(bytes, f"M({name})", symbol_map)
            elif struct["type"] == "Padding":
                # nops at end of file
                bytes.seek(offset % 4, 1)
                return out
            elif struct["type"] == "EntryList":
                out += f"EntryList M(entryList) = {{"
                for i in range(0, struct["length"], 4 * 4):
                    x,y,z,yaw = unpack(">ffff", bytes.read(4 * 4))
                    out += f"\n    {{ {x}f, {y}f, {z}f, {yaw}f }},"
                out += f"\n}};\n"
            elif struct["type"] == "Header":
                out += f"MapConfig M(config) = {{\n"

                bytes.read(0x10)

                main,entry_list,entry_count = unpack(">IIi", bytes.read(4 * 3))
                out += f"    .main = M(Main)\n"
                out += f"    .entryList = M(entryList)\n"
                out += f"    .entryCount = {entry_count}, // prefer ENTRY_COUNT(M(entryList)) if it matches\n"

                bytes.read(0x1C)

                bg,tattle = unpack(">II", bytes.read(4 * 2))
                out += f"    .background = {'&gBackgroundImage' if bg == 0x80200000 else 'NULL'},\n"
                out += f"    .tattle = {tattle:X},\n"

                out += f"}};\n"
            else: # unknown type of struct
                out += f"s32 M({name})[] = {{"
                for i in range(0, struct["length"], 4):
                    if (i % 0x20) == 0:
                        out += f"\n   "

                    word = int.from_bytes(bytes.read(4), byteorder="big")

                    if word in symbol_map:
                        out += f" M({symbol_map[word]}),"
                    else:
                        out += f" 0x{word:08X},"

                out += f"\n}};\n"

            out += "\n"
        elif found_data:
            if struct["type"] != "Padding":
                # put struct back on list
                midx.insert(0, struct)

            # nops at end of file
            bytes.seek(offset % 4, 1)

            return out

        if struct["type"] != "Function" and not struct["type"] == "Padding" and not (struct["type"] == "Missing" and not found_data):
            offset += struct["length"]

    # end of data
    return out

def parse_midx(file, prefix = ""):
    structs = []

    for line in file.readlines():
        s = line.split("#")
        if len(s) == 5:
            if s[0] == "$Start": continue
            if s[0] == "$End": continue
            structs.append({
                "name": prefix + name_struct(s[0]),
                "type": s[1],
                "start": int(s[2], 16),
                "vaddr": int(s[3], 16),
                "length": int(s[4], 16),
                "end": int(s[2], 16) + int(s[4], 16),
            })
        elif "Missing" in s:
            start = int(s[1], 16)
            end = int(s[2], 16)
            vaddr = start + 0x80240000
            structs.append({
                "name": f"{prefix}unk_missing_{vaddr:X}",
                "type": "Missing",
                "start": start,
                "vaddr": vaddr,
                "length": end - start,
                "end": end,
            })
        elif "Padding" in s:
            start = int(s[1], 16)
            end = int(s[2], 16)
            vaddr = start + 0x80240000
            structs.append({
                "name": f"{prefix}__padding__",
                "type": "Padding",
                "start": start,
                "vaddr": vaddr,
                "length": end - start,
                "end": end,
            })

    structs.sort(key=lambda s: s["start"])
    return structs

def name_struct(s):
    s = s[1:].replace("???", "unk")

    # use ThisCase for scripts
    if s.startswith("$Script"):
        return s[0].upper() + s[1:]

    return s[0].lower() + s[1:]

if __name__ == "__main__":
    if len(sys.argv) == 1:
        print("usage: ./disasm_map.py <file.midx>")
        print("Converts split map data into C files using a .midx file from Star Rod.")
        exit()

    map_name = os.path.splitext(os.path.basename(sys.argv[1]))[0]
    area_name = "area_" + map_name.split("_")[0]
    if len(area_name) > 8:
        area_name = area_name[:8]

    with open(sys.argv[1], "r") as f:
        midx = parse_midx(f)

    symbol_map = {}
    for struct in midx:
        symbol_map[struct["vaddr"]] = struct["name"]

    bin_dir = f"bin/world/{area_name}/{map_name}"
    src_dir = f"src/world/{area_name}/{map_name}"

    splits = []
    rom_start = 0
    with open(os.path.join(os.path.dirname(__file__), "splat.yaml")) as splat:
        splat = yaml.safe_load(splat)

        for segment in splat["segments"]:
            if type(segment) == dict and segment.get("name") == f"world/{area_name}/{map_name}/":
                rom_start = segment.get("start", 0)
                splits = segment.get("files", [])
                continue
    if len(splits) == 0:
        print(f"unable to find {map_name} in splat.yaml")
        exit(1)

    # advance to the EntryList (start of data)
    while midx[0]["type"] != "EntryList":
        midx.pop(0)

    for split in splits:
        rom_addr = split[0]
        filetype = split[1]

        if filetype == "bin":
            with open(f"{bin_dir}/{rom_addr:X}.bin", "rb") as bytes:
                print(f"// {rom_addr:X}")
                print(disassemble(bytes, rom_addr - rom_start, midx, symbol_map, map_name))
