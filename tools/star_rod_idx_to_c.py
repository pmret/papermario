#! /usr/bin/python3

import sys
import os
import yaml
import json
from struct import unpack
import argparse

import disasm_script

DIR = os.path.dirname(__file__)

def disassemble(bytes, midx, symbol_map={}, comments=True, romstart=0):
    out = ""

    entry_list_name = None
    main_script_name = None

    while len(midx) > 0:
        struct = midx.pop(0)
        name = struct["name"]

        if comments:
            out += f"// {romstart+struct['start']:X}-{romstart+struct['end']:X} (VRAM: {struct['vaddr']:X})\n"

        # format struct
        if struct["type"].startswith("Script"):
            if struct["type"] == "Script_Main":
                main_script_name = name

            pos = bytes.tell()
            try:
                out += disasm_script.ScriptDSLDisassembler(bytes, name, symbol_map).disassemble()
            except disasm_script.UnsupportedScript as e:
                out += f"// Unable to use DSL: {e}\n"

                bytes.seek(pos)
                out += disasm_script.ScriptDisassembler(bytes, name, symbol_map).disassemble()
        elif struct["type"] == "EntryList":
            entry_list_name = name
            out += f"EntryList {name} = {{"
            for i in range(0, struct["length"], 4 * 4):
                x,y,z,yaw = unpack(">ffff", bytes.read(4 * 4))
                out += f"\n    {{ {x}f, {y}f, {z}f, {yaw}f }},"
            out += f"\n}};\n"
        elif struct["type"] == "Header":
            out += f"MapConfig {name} = {{\n"

            bytes.read(0x10)

            main,entry_list,entry_count = unpack(">IIi", bytes.read(4 * 3))
            out += f"    .main = {main_script_name},\n"
            out += f"    .entryList = {entry_list_name},\n"
            out += f"    .entryCount = ENTRY_COUNT({entry_list_name}),\n"

            bytes.read(0x1C)

            bg,tattle = unpack(">II", bytes.read(4 * 2))
            if bg == 0x80200000:
                out += f"    .background = &gBackgroundImage,\n"
            elif bg != 0:
                raise Exception(f"unknown MapConfig background {bg:X}")
            out += f"    .tattle = 0x{tattle:X},\n"

            out += f"}};\n"
        elif struct["type"] == "ASCII":
            string_data = bytes.read(struct["length"]).decode("ascii")

            # strip null terminator(s)
            while string_data[-1] == "\0":
                string_data = string_data[:-1]

            string_literal = json.dumps(string_data)
            out += f"const char {struct['name']}[] = {string_literal};\n"
        elif struct["type"].startswith("Function"):
            bytes.read(struct["length"])
            out += f"// function: {name}\n"
        elif struct["type"] == "FloatTable":
            out += f"f32 {name}[] = {{"
            for i in range(0, struct["length"], 4):
                if (i % 0x20) == 0:
                    out += f"\n   "

                word = unpack(">f", bytes.read(4))[0]
                out += " %ff," % word

            out += f"\n}};\n"
        else: # unknown type of struct
            out += f"s32 {name}[] = {{"
            for i in range(0, struct["length"], 4):
                if (i % 0x20) == 0:
                    out += f"\n   "

                word = int.from_bytes(bytes.read(4), byteorder="big")

                if word in symbol_map:
                    out += f" {symbol_map[word]},"
                else:
                    out += f" 0x{word:08X},"

            out += f"\n}};\n"

        out += "\n"

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
                "name": f"{prefix}pad_{start:X}",
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

    """
    # use ThisCase for scripts
    if s.startswith("Script_"):
        s = s[7].upper() + s[8:]

        # if `s` is hex, prefix it with Script_ again
        try:
            int(s, 16)
            return "Script_" + s
        except Exception:
            pass

        if s.startswith("Main"):
            return "Main"

        return s
    """

    if s.startswith("ASCII"):
        return s

    return s[0].lower() + s[1:]

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Converts split data to C using a Star Rod idx file")
    parser.add_argument("idxfile", help="Input .*idx file from Star Rod dump")
    parser.add_argument("offset", help="Starting ROM offset")
    parser.add_argument("--comments", action="store_true", help="Write offset/vaddr comments")

    args = parser.parse_args()

    with open(args.idxfile, "r") as f:
        midx = parse_midx(f)

    symbol_map = {}
    for struct in midx:
        symbol_map[struct["vaddr"]] = struct["name"]

    with open(os.path.join(DIR, "../baserom.z64"), "rb") as romfile:
        romfile.seek(eval(args.offset))
        disasm = disassemble(romfile, midx, symbol_map, args.comments, eval(args.offset))
        print(disasm.rstrip())
