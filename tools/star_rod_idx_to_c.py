#! /usr/bin/python3

import sys
import os
import yaml
import json
from struct import unpack, unpack_from
import argparse

import disasm_script

DIR = os.path.dirname(__file__)

INCLUDED = {}
INCLUDED["functions"] = set()
INCLUDES_NEEDED = {}
INCLUDES_NEEDED["include"] = []
INCLUDES_NEEDED["forward"] = []

def disassemble(bytes, midx, symbol_map={}, comments=True, romstart=0):
    global INCLUDES_NEEDED, INCLUDED
    out = ""

    entry_list_name = None
    main_script_name = None

    INDENT = f"    "

    while len(midx) > 0:
        struct = midx.pop(0)
        name = "N(" + struct["name"] + ")"

        INCLUDED["functions"].add(name)

        if comments:
            out += f"// {romstart+struct['start']:X}-{romstart+struct['end']:X} (VRAM: {struct['vaddr']:X})\n"

        # format struct
        if struct["type"].startswith("Script"):
            if struct["type"] == "Script_Main":
                main_script_name = name

            pos = bytes.tell()
            try:
                out += disasm_script.ScriptDSLDisassembler(bytes, name, symbol_map, romstart, INCLUDES_NEEDED, INCLUDED).disassemble()
            except disasm_script.UnsupportedScript as e:
                out += f"// Unable to use DSL: {e}\n"

                bytes.seek(pos)
                out += disasm_script.ScriptDisassembler(bytes, name, symbol_map, romstart, INCLUDES_NEEDED, INCLUDED).disassemble()
        elif struct["type"] == "EntryList":
            entry_list_name = name
            out += f"EntryList {name} = {{"
            for i in range(0, struct["length"], 4 * 4):
                x,y,z,yaw = unpack(">ffff", bytes.read(4 * 4))
                out += f"\n    {{ {x}f, {y}f, {z}f, {yaw}f }},"
            out += f"\n}};\n"
        elif struct["type"] == "NpcSettings":
            tmp_out = f"NpcSettings {name} = {{\n"
            npcSettings = bytes.read(struct["length"])

            i = 0 
            while i < struct["length"]:
                if i == 0x0 or i == 0x24:
                    var_names = ["unk_00", "unk_24"]
                    data = unpack_from(">4B", npcSettings, i)
                    if not sum(data) == 0:
                        tmp_out += INDENT + f".{var_names[0] if i == 0 else var_names[1]} = {{ " + ", ".join(f"{x:02X}" for x in unk_00) + f" }},\n"
                elif i == 0x4 or i == 0x28:
                    var_names = ["height", "radius", "level", "unk_2A"]
                    for x,var in enumerate(unpack_from(">2h", npcSettings, i)):
                        var_name = var_names[x if i == 0x4 else x+2]
                        if not var == 0:
                            tmp_out += INDENT + f".{var_name} = {var},\n"
                elif i == 0x8:
                    var_names = ["otherAI", "onInteract", "ai", "onHit", "aux", "onDefeat", "flags"]
                    for x,var in enumerate(unpack_from(f">7I", npcSettings, i)):
                        var_name = var_names[x]
                        if not var == 0:
                            if var == 0x80077F70:
                                tmp_out += INDENT + f".{var_name} = EnemyNpcHit,\n"
                            elif var == 0x8007809C:
                                tmp_out += INDENT + f".{var_name} = EnemyNpcDefeat,\n"
                            elif var_name != "flags" and var in symbol_map:
                                tmp_out += INDENT + f".{var_name} = &N({symbol_map[var][0][1]}),\n"
                                if f"N({symbol_map[var][0][1]})" not in INCLUDED["functions"]:
                                    INCLUDES_NEEDED["forward"].append(f"N({symbol_map[var][0][1]})")
                            else:
                                tmp_out += INDENT + f".{var_name} = 0x{var:08X},\n"
                i += 1

            tmp_out += "};\n"
            out += tmp_out
        elif struct["type"] == "AISettings":
            tmp_out = f"NpcAISettings {name} = {{\n"
            npcAISettings = bytes.read(struct["length"])

            i = x = 0
            var_names = ["moveSpeed", "moveTime", "waitTime", "alertRadius", "unk_10", "unk_14",
                         "chaseSpeed", "unk_1C", "unk_20", "chaseRadius", "unk_28", "unk_2C"]
            while i < struct["length"]:
                var_f, var_i1, var_i2 = unpack_from(f">fii", npcAISettings, i)
                if not var_f == 0: 
                    tmp_out += INDENT + f".{var_names[x]} = {var_f:.01f}f,\n"
                if not var_i1 == 0:
                    # account for X32
                    if var_names[x + 1] == "unk_10" or var_names[x + 1] == "unk_28":
                        ftest = float(unpack_from(">f", npcAISettings, i+4)[0])
                        if ftest >= -1000.0 and ftest <= 1000:
                            tmp_out += INDENT + f".{var_names[x + 1]} = {{ .f = {ftest:.01f}f }},\n"
                        else:
                            tmp_out += INDENT + f".{var_names[x + 1]} = {{ .s = {var_i1} }},\n"
                    else:
                        tmp_out += INDENT + f".{var_names[x + 1]} = {var_i1},\n"
                if not var_i2 == 0:
                    tmp_out += INDENT + f".{var_names[x + 2]} = {var_i2},\n"
                i += 12
                x += 3

            tmp_out += "};\n"
            out += tmp_out
        elif struct["type"] == "NpcGroup":
            staticNpc = bytes.read(struct["length"])
            curr_base = 0
            numNpcs = struct['length'] // 0x1F0
            tmp_out = f"StaticNpc {name}" + ("[]" if numNpcs > 1 else "") + f" = {{\n"

            for z in range(struct['length'] // 0x1F0):
                i = 0
                var_names = ["id", "settings", "pos", "flags", 
                             "init", "unk_1C", "yaw", "dropFlags", 
                             "itemDropChance", "itemDrops", "heartDrops", "flowerDrops", 
                             "minCoinBonus", "maxCoinBonus", "movement", "animations", 
                             "unk_1E0", "extraAnimations", "tattle"]

                if numNpcs > 1:
                    tmp_out += INDENT + f"{{\n"
                    INDENT = INDENT*2

                while i < 0x1F0:
                    if i == 0x0 or i == 0x24:
                        var_name = var_names[0] if i == 0x0 else var_names[6]
                        var = unpack_from(f">i", staticNpc, curr_base+i)[0]
                        tmp_out += INDENT + f".{var_name} = {var},\n"
                    elif i == 0x4 or i == 0x14 or i == 0x18 or i == 0x1E8:
                        var_name = var_names[1] if i == 0x4 else var_names[3] if i == 0x14 else var_names[4] if i == 0x18 else var_names[17]
                        addr = unpack_from(f">I", staticNpc, curr_base+i)[0]
                        if not addr == 0:
                            if var_name != "flags" and addr in symbol_map:
                                tmp_out += INDENT + f".{var_name} = &N({symbol_map[addr][0][1]}),\n"
                                if f"N({symbol_map[addr][0][1]})" not in INCLUDED["functions"]:
                                    INCLUDES_NEEDED["forward"].append(f"N({symbol_map[addr][0][1]})")
                            else:
                                tmp_out += INDENT + f".{var_name} = 0x{addr:08X},\n"
                    elif i == 0x8:
                        pos = unpack_from(f">fff", staticNpc, curr_base+i)
                        if not sum(pos) == 0:
                            tmp_out += INDENT + f".pos = {{ {pos[0]:.01f}f, {pos[1]:.01f}f, {pos[2]:.01f}f }},\n"
                    elif i == 0x1C or i == 0x1E0:
                        var_name = var_names[5] if i == 0x1C else var_names[16]
                        data = unpack_from(f">8B", staticNpc, curr_base+i)
                        if not sum(data) == 0:
                            tmp_out += INDENT + f".{var_name} = {{ " + ", ".join(f"{x:02X}" for x in data) + f"}},\n"
                    elif i == 0x28 or i == 0x29:
                        var_name = var_names[7] if i == 0x28 else var_names[8]
                        var = unpack_from(f">b", staticNpc, curr_base+i)[0]
                        if not var == 0:
                            if var_name == "dropFlags":
                                tmp_out += INDENT + f".{var_name} = 0x{abs(var):02X},\n"
                            else:
                                tmp_out += INDENT + f".{var_name} = {var},\n"
                    elif i == 0x2A:
                        var_name = var_names[9]
                        for x in range(8):
                            item, weight, unk_08 = unpack_from(f">3h", staticNpc, curr_base+i)
                            if not (item == 0 and weight == 0 and unk_08 == 0):
                                item = disasm_script.CONSTANTS["ItemIDs"][item] if item in disasm_script.CONSTANTS["ItemIDs"] else f"{item}"
                                tmp_out += INDENT*2 + f"{{ {item}, {weight}, {unk_08} }},\n"
                            i += 0x6
                        i -= 1
                    elif i == 0x5A or i == 0x9A:
                        var_name = var_names[10] if i == 0x5A else var_names[11]
                        drops = []
                        for x in range(8):
                            cutoff, generalChance, attempts, chancePerAttempt = unpack_from(f">4h", staticNpc, curr_base+i)
                            if not (cutoff == 0 and generalChance == 0 and attempts == 0 and chancePerAttempt == 0):
                                drops.append([cutoff, generalChance, attempts, chancePerAttempt])
                            i += 0x8
                        i -= 1
                        if drops:
                            tmp_out += INDENT + f".{var_name} = "
                            if var_name == "heartDrops":
                                if round(drops[0][1] / 327.67, 2) == 70 and round(drops[0][3] / 327.67, 2) == 50:
                                    tmp_out += f"STANDARD_HEART_DROPS({attempts})"
                                elif round(drops[0][1] / 327.67, 2) == 80 and round(drops[0][3] / 327.67, 2) == 50:
                                    tmp_out += f"GENEROUS_HEART_DROPS({attempts})"
                                elif round(drops[0][1] / 327.67, 2) == 80 and round(drops[0][3] / 327.67, 2) == 60:
                                    tmp_out += f"GENEROUS_WHEN_LOW_HEART_DROPS({attempts})"
                                elif round(drops[0][0] / 327.67, 2) == 100 and round(drops[0][1] / 327.67, 2) == 0 and round(drops[0][2] / 327.67, 2) == 0:
                                    tmp_out += f"NO_DROPS"
                                else:
                                    print(f"Unknown heart drop macro, values were {round(drops[0][1] / 327.67, 2)} and {round(drops[0][3] / 327.67, 2)}")
                                    exit()
                            else:
                                if round(drops[0][1] / 327.67, 2) == 50 and round(drops[0][3] / 327.67, 2) == 40:
                                    tmp_out += f"STANDARD_FLOWER_DROPS({attempts})"
                                elif round(drops[0][1] / 327.67, 2) == 70 and round(drops[0][3] / 327.67, 2) == 50:
                                    tmp_out += f"GENEROUS_WHEN_LOW_FLOWER_DROPS({attempts})"
                                elif round(drops[0][1] / 327.67, 2) == 40 and round(drops[0][3] / 327.67, 2) == 40:
                                    tmp_out += f"REDUCED_FLOWER_DROPS({attempts})"
                                elif round(drops[0][0] / 327.67, 2) == 100 and round(drops[0][1] / 327.67, 2) == 0 and round(drops[0][2] / 327.67, 2) == 0:
                                    tmp_out += f"NO_DROPS"
                                else:
                                    print(f"Unknown flower drop macro, values were {round(drops[0][1] / 327.67, 2)} and {round(drops[0][3] / 327.67, 2)}")
                                    exit()

                            tmp_out += f",\n"
                    elif i == 0xDA or i == 0xDC:
                        var_name = var_names[12] if i == 0xDA else var_names[13]
                        var = unpack_from(">h", staticNpc, curr_base+i)[0]
                        if not var == 0:
                            tmp_out += INDENT + f".{var_name} = {var},\n"
                    elif i == 0xE0:
                        data = unpack_from(">48i", staticNpc, curr_base+i)
                        if not sum(data) == 0:
                            end_pos = len(data)
                            for x,datum in enumerate(data):
                                if not datum == 0:
                                    end_pos = x
                            tmp_out += INDENT + f".movement = {{ " + ", ".join(f"{x}" for x in data[:end_pos+1]) + f" }},\n"
                    elif i == 0x1A0:
                        tmp_out += INDENT + f".{var_names[15]} = {{\n"
                        for x in range(16):
                            anim = unpack_from(">I", staticNpc, curr_base+i)[0]
                            if not anim == 0:
                                sprite_id =  (anim & 0x00FF0000) >> 16
                                palette_id = (anim & 0x0000FF00) >> 8
                                anim_id =    (anim & 0x000000FF) >> 0
                                sprite =  disasm_script.CONSTANTS["NPC_SPRITE"][sprite_id]["name"]
                                palette = disasm_script.CONSTANTS["NPC_SPRITE"][sprite_id]["palettes"][palette_id]
                                anim =    disasm_script.CONSTANTS["NPC_SPRITE"][sprite_id]["anims"][anim_id]
                                if numNpcs > 1:
                                    tmp_out += INDENT + "    " + f"NPC_ANIM({sprite}, {palette}, {anim}),\n"
                                else:
                                    tmp_out += INDENT*2 + f"NPC_ANIM({sprite}, {palette}, {anim}),\n"
                            i += 4
                        tmp_out += INDENT + f"}},\n"
                        i -= 1
                    elif i == 0x1EC:
                        var = unpack_from(">I", staticNpc, curr_base+i)[0]
                        if not var == 0:
                            tmp_out += INDENT + f".{var_names[18]} = {var},\n"

                    i += 1

                if numNpcs > 1:
                    INDENT = INDENT[:len(INDENT)//2]
                    tmp_out += INDENT + f"}},\n"
                if z+1 == numNpcs:
                    tmp_out += "};\n"

                curr_base += 0x1F0
            out += tmp_out
        elif struct["type"] == "ExtraAnimationList":
            tmp_out = f"NpcAnimID {name}[] = {{\n"
            extraAnimations = bytes.read(struct["length"])

            i = 0
            while i < struct["length"]:
                anim = unpack_from(">I", extraAnimations, i)[0]
                if anim == 0xFFFFFFFF:
                    tmp_out += INDENT + f"ANIM_END,\n"
                elif not anim == 0:
                    sprite_id =  (anim & 0x00FF0000) >> 16
                    palette_id = (anim & 0x0000FF00) >> 8
                    anim_id =    (anim & 0x000000FF) >> 0
                    sprite =  disasm_script.CONSTANTS["NPC_SPRITE"][sprite_id]["name"]
                    palette = disasm_script.CONSTANTS["NPC_SPRITE"][sprite_id]["palettes"][palette_id]
                    anim =    disasm_script.CONSTANTS["NPC_SPRITE"][sprite_id]["anims"][anim_id]
                    tmp_out += INDENT + f"NPC_ANIM({sprite}, {palette}, {anim}),\n"
                i += 4
            tmp_out += f"}};\n"
            out += tmp_out
        elif struct["type"] == "NpcGroupList":
            tmp_out = f"NpcGroupList {name} = {{\n"
            npcGroupList = bytes.read(struct["length"])
            
            i = 0
            while i < struct["length"]:
                npcCount, npcs, battle = unpack_from(">3I", npcGroupList, i)
                if not (npcCount == 0 and npcs == 0 and battle == 0):
                    battle_a = (battle & 0xFF000000) >> 24
                    battle_b = (battle & 0x00FF0000) >> 16
                    battle_c = (battle & 0x0000FF00) >> 8
                    battle_d = (battle & 0x000000FF) >> 0
                    tmp_out += INDENT + f"NPC_GROUP(N({symbol_map[npcs][0][1]}), BATTLE_ID({battle_a}, {battle_b}, {battle_c}, {battle_d})),\n"
                    if f"N({symbol_map[npcs][0][1]})" not in INCLUDED["functions"]:
                        INCLUDES_NEEDED["forward"].append(f"N({symbol_map[npcs][0][1]})")
                i += 0xC
            tmp_out += INDENT + f"{{}},\n"
            tmp_out += f"}};\n"
            out += tmp_out
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
            if struct["type"] == "Padding":
                out += "static "
            out += f"s32 {name}[] = {{"
            for i in range(0, struct["length"], 4):
                if (i % 0x20) == 0:
                    out += f"\n   "

                word = int.from_bytes(bytes.read(4), byteorder="big")

                if word in symbol_map:
                    out += f" {symbol_map[word][0][1]},"
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
        symbol_map[struct["vaddr"]] = [[struct["vaddr"], struct["name"]]]

    disasm_script.get_constants()

    with open(os.path.join(DIR, "../ver/current/baserom.z64"), "rb") as romfile:
        romfile.seek(eval(args.offset))
        disasm = disassemble(romfile, midx, symbol_map, args.comments, eval(args.offset))
        print(disasm.rstrip())

        if INCLUDES_NEEDED["forward"]:
            print()
            print("========== Forward declares needed: ==========\n")

            for forward in INCLUDES_NEEDED["forward"]:
                print(forward)
            print()
