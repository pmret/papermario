#! /usr/bin/python3

import sys
import os
import yaml
import json
from struct import unpack, unpack_from
from copy import deepcopy
import argparse
from pathlib import Path

import disasm_script
import sjis

DIR = os.path.dirname(__file__)

INCLUDED = {}
INCLUDED["functions"] = set()
INCLUDED["includes"] = set()
INCLUDES_NEEDED = {}
INCLUDES_NEEDED["include"] = []
INCLUDES_NEEDED["forward"] = []
INCLUDES_NEEDED["npcs"] = {}
INCLUDES_NEEDED["sprites"] = set()
INCLUDES_NEEDED["tattle"] = []

def get_flag_name(arg):
    v = arg - 2**32 # convert to s32
    if v > -250000000:
        if v <= -220000000: return str((v + 230000000) / 1024)
        elif v <= -200000000: return f"EVT_ARRAY_FLAG({v + 210000000})"
        elif v <= -180000000: return f"EVT_ARRAY({v + 190000000})"
        elif v <= -160000000:
            if v + 170000000 == 0:
                return "EVT_STORY_PROGRESS"
            elif v + 170000000 == 425:
                return "EVT_WORLD_LOCATION"
            else:
                return f"EVT_SAVE_VAR({v + 170000000})"
        elif v <= -140000000: return f"EVT_AREA_VAR({v + 150000000})"
        elif v <= -120000000: return f"EVT_SAVE_FLAG({v + 130000000})"
        elif v <= -100000000: return f"EVT_AREA_FLAG({v + 110000000})"
        elif v <= -80000000: return f"EVT_MAP_FLAG({v + 90000000})"
        elif v <= -60000000: return f"EVT_FLAG({v + 70000000})"
        elif v <= -40000000: return f"EVT_MAP_VAR({v + 50000000})"
        elif v <= -20000000: return f"EVT_VAR({v + 30000000})"

    if arg == 0xFFFFFFFF:
        return "-1"
    elif (arg & 0xFF000000) == 0x80000000:
        return f"0x{arg:X}"
    elif arg >= 0x80000000:
        return f"{arg - 0x100000000}"
    else:
        return f"{arg}"

def get_function_list(area_name, map_name, rom_offset):
    map_file = (Path(__file__).parent.parent / "ver" / "current" / "build" / "papermario.map").read_text().splitlines()
    i = 0
    firstFind = False
    functions = {}
    while i < len(map_file):
        if map_file[i].startswith(f".{map_name}"):
            firstFind = True
            i += 1
            while not map_file[i].startswith(" .data"):
                if map_file[i].startswith("  ") and " = ." not in map_file[i]:
                    line = map_file[i].strip()
                    vram, *_, func = line.split()
                    vram = int(vram, 16)
                    func = func.replace(f"{map_name}_", "")
                    if func.count("_") == 2:
                        func = func.rsplit("_",1)[0]
                    functions[vram] = func
                i += 1
        if firstFind:
            break
        i += 1

    return functions

def get_include_list(area_name, map_name):
    include_path = Path(__file__).parent.parent / "src" / "world" / "common"
    includes = set()
    for file in include_path.iterdir():
        if file.is_file() and ".inc.c" in file.parts[-1]:
            with open(file, "r", encoding="utf8") as f:
                for line in f:
                    if (line.startswith("void N(") or line.startswith("ApiStatus N(")) and "{" in line:
                        func_name = line.split("N(",1)[1].split(")",1)[0]
                        includes.add(func_name)
    return includes

def read_flags(flags: int, constants_name: str) -> str:
    enabled = []
    for x in range(32):
        val = flags & (1 << x)
        if val:
            if val in disasm_script.CONSTANTS[constants_name]:
                enabled.append(disasm_script.CONSTANTS[constants_name][val])
            else:
                print(f"0x{val:08X} missing from enum {constants_name}!")
                enabled.append(f"0x{val:08X}")
    if not enabled:
        enabled.append("0")

    return " | ".join(enabled)

def read_ptr(addr: int, symbol_map: dict, needs_ampersand: bool = False) -> str:
    if addr == 0:
        return "NULL"
    elif addr in symbol_map:
        if needs_ampersand:
            return f"&{symbol_map[addr][0][1]}"
        else:
            return f"{symbol_map[addr][0][1]}"
    else:
        return f"(void*) 0x{addr:08X}"

def disassemble(bytes, midx, symbol_map={}, comments=True, romstart=0):
    global INCLUDES_NEEDED, INCLUDED
    out = ""

    entry_list_name = None
    main_script_name = None

    INDENT = f"    "
    afterHeader = False
    treePrint = False

    while len(midx) > 0:
        struct = midx.pop(0)

        name = struct["name"]

        #INCLUDED["functions"].add(name)

        if comments:
            out += f"// {romstart+struct['start']:X}-{romstart+struct['end']:X} (VRAM: {struct['vaddr']:X})\n"

        if struct["type"] == "ASCII" or struct["type"] == "SJIS" or struct["type"] == "ConstDouble":
            # rodata string hopefully inlined elsewhere
            out += f"// rodata: {struct['name']}\n"

        # format struct
        if struct["type"].startswith("Script"):
            if struct["type"] == "Script_Main":
                name = "N(main)"
                INCLUDES_NEEDED["forward"].append(f"EvtSource " + name + ";")
                main_script_name = name

            # For PlayMusic script if using a separate header file
            #if afterHeader:
            #    INCLUDES_NEEDED["forward"].append(f"EvtSource " + name + ";")
            #    afterHeader = False

            script_text = disasm_script.ScriptDisassembler(bytes, name, symbol_map, romstart, INCLUDES_NEEDED, INCLUDED).disassemble()

            if "shakeTree" in name or "searchBush" in name:
                symbol_map[struct["vaddr"]][0][1] = name.split("_",1)[0] + ")"
                if not treePrint:
                    out += f"=======================================\n"
                    out += f"==========BELOW foliage.inc.c==========\n"
                    out += f"=======================================\n\n"
                    treePrint = True
                continue

            if "exitWalk" in name:
                script_text = script_text.splitlines()
                walkDistance = exitIdx = map_ = entryIdx = ""
                if "UseExitHeading" in script_text[2]:
                    walkDistance, exitIdx = script_text[2].split("(",1)[1].split(")",1)[0].split(",")
                if "GotoMap" in script_text[4]:
                    map_, entryIdx = script_text[4].split("(",1)[1].split(")",1)[0].split(",")
                if walkDistance and exitIdx and map_ and entryIdx:
                    out += f"EvtSource {name} = EXIT_WALK_SCRIPT({walkDistance}, {exitIdx}, {map_}, {entryIdx});\n"
                else:
                    print(f"Unable to macro replace exit script {name}")
                    out += "\n".join(script_text) + "\n"
            else:
                out += script_text

        elif struct["type"] == "EntryList":
            entry_list_name = name
            out += f"EntryList {name} = {{"
            entry_list = bytes.read(struct["length"])
            entry_count = len(entry_list) // 16
            pos = 0
            x = []
            y = []
            z = []
            w = []
            for _ in range(entry_count):
                a,b,c,d = unpack_from(">ffff", entry_list, pos)
                x.append(f"{a:.01f}"); y.append(f"{b:.01f}"); z.append(f"{c:.01f}"); w.append(f"{d:.01f}")
                pos += 16

            x_size = max([len(a) for a in x])
            y_size = max([len(a) for a in y])
            z_size = max([len(a) for a in z])
            w_size = max([len(a) for a in w])

            for a,b,c,d in zip(x,y,z,w):
                out += f"\n    {{ {a:>{x_size}}f, {b:>{y_size}}f, {c:>{z_size}}f, {d:>{w_size}}f }},"

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
                        tmp_out += INDENT + f".{var_names[0] if i == 0 else var_names[1]} = {{ " + ", ".join(f"0x{x:02X}" for x in data) + f" }},\n"
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
                                tmp_out += INDENT + f".{var_name} = &{symbol_map[var][0][1]},\n"
                                if symbol_map[var][0][1] not in INCLUDED["functions"]:
                                    INCLUDES_NEEDED["forward"].append(symbol_map[var][0][1])
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
                    if var_names[x + 1] in ["unk_10", "unk_1C", "unk_28"]:
                        if var_i1 < -100000 or var_i1 > 100000:
                            tmp_out += INDENT + f".{var_names[x + 1]} = {{ .f = {unpack_from('>f', npcAISettings, i+4)[0]:.01f}f }},\n"
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

            for z in range(numNpcs):
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
                        if var_name == "id":
                            tmp_out += INDENT + f".{var_name} = {disasm_script.CONSTANTS['MAP_NPCS'][var]},\n"
                        else:
                            tmp_out += INDENT + f".{var_name} = {var},\n"
                    elif i == 0x4 or i == 0x14 or i == 0x18 or i == 0x1E8:
                        var_name = var_names[1] if i == 0x4 else var_names[3] if i == 0x14 else var_names[4] if i == 0x18 else var_names[17]
                        addr = unpack_from(f">I", staticNpc, curr_base+i)[0]
                        if not addr == 0:
                            if var_name != "flags" and addr in symbol_map:
                                if var_name == "extraAnimations":
                                    tmp_out += INDENT + f".{var_name} = {symbol_map[addr][0][1]},\n"
                                else:
                                    tmp_out += INDENT + f".{var_name} = &{symbol_map[addr][0][1]},\n"

                                if symbol_map[addr][0][1] not in INCLUDED["functions"]:
                                    INCLUDES_NEEDED["forward"].append(symbol_map[addr][0][1])
                            else:
                                enabled = []
                                for x in range(32):
                                    val = addr & (1 << x)
                                    if val:
                                        if val in disasm_script.CONSTANTS["NpcFlags"]:
                                            enabled.append(disasm_script.CONSTANTS["NpcFlags"][val])
                                        else:
                                            print(f"NpcFlag 0x{val:08X} missing from NpcFlag enums!")
                                            enabled.append(f"0x{val:08X}")
                                if not enabled:
                                    enabled.append(0)
                                tmp_out += INDENT + f".{var_name} = " + " | ".join(enabled) + f",\n"
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
                        tmp_tmp = ""
                        for x in range(8):
                            item, weight, unk_08 = unpack_from(f">3h", staticNpc, curr_base+i)
                            if not (item == 0 and weight == 0 and unk_08 == 0):
                                item = disasm_script.CONSTANTS["ItemIDs"][item] if item in disasm_script.CONSTANTS["ItemIDs"] else f"{item}"
                                tmp_tmp += INDENT*2 + f"{{ {item}, {weight}, {unk_08} }},\n"
                            i += 0x6

                        if tmp_tmp:
                            tmp_out += INDENT + f".{var_name} = {{\n"
                            tmp_out += tmp_tmp
                            tmp_out += INDENT + f"}},\n"

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
                                    tmp_out += f"STANDARD_HEART_DROPS({drops[0][2]})"
                                elif round(drops[0][1] / 327.67, 2) == 80 and round(drops[0][3] / 327.67, 2) == 50:
                                    tmp_out += f"GENEROUS_HEART_DROPS({drops[0][2]})"
                                elif round(drops[0][1] / 327.67, 2) == 80 and round(drops[0][3] / 327.67, 2) == 60:
                                    tmp_out += f"GENEROUS_WHEN_LOW_HEART_DROPS({drops[0][2]})"
                                elif round(drops[0][0] / 327.67, 2) == 100 and round(drops[0][1] / 327.67, 2) == 0 and round(drops[0][2] / 327.67, 2) == 0:
                                    tmp_out += f"NO_DROPS"
                                else:
                                    print(f"Unknown heart drop macro, values were {round(drops[0][1] / 327.67, 2)} and {round(drops[0][3] / 327.67, 2)}")
                                    exit()
                            else:
                                if round(drops[0][1] / 327.67, 2) == 50 and round(drops[0][3] / 327.67, 2) == 40:
                                    tmp_out += f"STANDARD_FLOWER_DROPS({drops[0][2]})"
                                elif round(drops[0][1] / 327.67, 2) == 70 and round(drops[0][3] / 327.67, 2) == 50:
                                    tmp_out += f"GENEROUS_WHEN_LOW_FLOWER_DROPS({drops[0][2]})"
                                elif round(drops[0][1] / 327.67, 2) == 40 and round(drops[0][3] / 327.67, 2) == 40:
                                    tmp_out += f"REDUCED_FLOWER_DROPS({drops[0][2]})"
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
                                    tmp_out += INDENT + "    " + f"NPC_ANIM_{sprite}_{palette}_{anim},\n"
                                else:
                                    tmp_out += INDENT*2 + f"NPC_ANIM_{sprite}_{palette}_{anim},\n"
                                INCLUDES_NEEDED["sprites"].add(sprite)
                            i += 4
                        tmp_out += INDENT + f"}},\n"
                        i -= 1
                    elif i == 0x1EC:
                        var = unpack_from(">I", staticNpc, curr_base+i)[0]
                        if not var == 0:
                            tmp_out += INDENT + f".{var_names[18]} = MESSAGE_ID(0x{(var & 0xFF0000) >> 16:02X}, 0x{var & 0xFFFF:04X}),\n"

                    i += 1

                if numNpcs > 1:
                    INDENT = INDENT[:len(INDENT)//2]
                    tmp_out += INDENT + f"}},\n"
                if z+1 == numNpcs:
                    tmp_out += "};\n"

                curr_base += 0x1F0
            out += tmp_out
        elif struct["type"] == "ExtraAnimationList":
            tmp_out = f"s32 {name}[] = {{\n"
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
                    tmp_out += INDENT + f"NPC_ANIM_{sprite}_{palette}_{anim},\n"
                    INCLUDES_NEEDED["sprites"].add(sprite)
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
                    tmp_out += INDENT + f"NPC_GROUP({symbol_map[npcs][0][1]}, BATTLE_ID({battle_a}, {battle_b}, {battle_c}, {battle_d})),\n"
                    if symbol_map[npcs][0][1] not in INCLUDED["functions"]:
                        INCLUDES_NEEDED["forward"].append(symbol_map[npcs][0][1])
                i += 0xC
            tmp_out += INDENT + f"{{}},\n"
            tmp_out += f"}};\n"
            out += tmp_out
        elif struct["type"] == "ItemList":
            out += f"s32 {name}[] = {{\n"

            items = unpack(f">{struct['length']//4}I", bytes.read(struct["length"]))
            for item in items:
                out += f"    {disasm_script.CONSTANTS['ItemIDs'][item]},\n"
            out += f"}};\n"
        elif struct["type"] == "TreeDropList":
            new_name = "N(" + name.split('_',1)[1][:-1].lower() + "_Drops)"
            symbol_map[struct["vaddr"]][0][1] = new_name

            out += f"FoliageDropList {new_name} = {{\n"

            data = bytes.read(struct["length"])
            count = unpack_from(">I", data, 0)[0]

            out += f"{INDENT}.count = {count},\n"

            if count > 0:
                out += f"{INDENT}.drops = {{\n"

            pos = 4
            for _ in range(count):
                entry = list(unpack_from(">7I", data, pos))
                pos += 7*4

                entry[1] = entry[1] - 0x100000000 if entry[1] >= 0x80000000 else entry[1]
                entry[2] = entry[2] - 0x100000000 if entry[2] >= 0x80000000 else entry[2]
                entry[3] = entry[3] - 0x100000000 if entry[3] >= 0x80000000 else entry[3]

                flag1 = get_flag_name(entry[5])
                flag2 = get_flag_name(entry[6])

                out += f"{INDENT * 2}{{\n"
                out += f"{INDENT * 3}.itemID = {disasm_script.CONSTANTS['ItemIDs'][entry[0]]},\n"
                out += f"{INDENT * 3}.pos = {{ {entry[1]}, {entry[2]}, {entry[3]} }},\n"
                if entry[4] != 0:
                    out += f"{INDENT * 3}.spawnMode = 0x{entry[4]:X},\n"
                if flag1 != '0':
                    out += f"{INDENT * 3}.pickupFlag = {flag1},\n"
                if flag2 != '0':
                    out += f"{INDENT * 3}.spawnFlag = {flag2},\n"
                out += f"{INDENT * 2}}},\n"

            if count > 0:
                out += f"{INDENT}}}\n"

            out += f"}};\n"

        elif struct["type"] == "TreeModelList" or struct["type"] == "TreeEffectVectors":
            isModelList = struct["type"] == "TreeModelList"

            name_parts = name.split('_')
            if isModelList:
                new_name = "N(" + name_parts[1].lower() + "_" + name_parts[2]
            else:
                new_name = "N(" + name_parts[1][:-1].lower() + "_Vectors)"
            symbol_map[struct["vaddr"]][0][1] = new_name

            if isModelList:
                out += f"FoliageModelList {new_name} = {{\n"
            else:
                out += f"TreeEffectVectors {new_name} = {{\n"

            data = bytes.read(struct["length"])
            count = unpack_from(">I", data, 0)[0]

            out += f"{INDENT}.count = {count},\n"

            if isModelList:
                if count > 0:
                    out += f"{INDENT}.models = {{ "

                pos = 4
                for _ in range(count):
                    entry = unpack_from(">I", data, pos)[0]
                    pos += 4

                    out += f"{entry}, "

                if count > 0:
                    out = out[:-2]
                    out += f" }}\n"

            else:
                if count > 0:
                    out += f"{INDENT}.vectors = {{\n"

                pos = 4
                for _ in range(count):
                    entry = list(unpack_from(">3I", data, pos))

                    entry[0] = entry[0] - 0x100000000 if entry[0] >= 0x80000000 else entry[0]
                    entry[1] = entry[1] - 0x100000000 if entry[1] >= 0x80000000 else entry[1]
                    entry[2] = entry[2] - 0x100000000 if entry[2] >= 0x80000000 else entry[2]

                    pos += 3*4

                    out += f"{INDENT * 2}{{ {entry[0]}, {entry[1]}, {entry[2]} }},\n"

                if count > 0:
                    out += f"{INDENT}}}\n"

            out += f"}};\n"

        elif struct["type"] == "SearchBushEvent":
            new_name = "N(" + name.split('_',1)[1].lower()
            symbol_map[struct["vaddr"]][0][1] = new_name

            num = int(new_name.split("bush",1)[1][:-1])
            out += f"SearchBushConfig {new_name} = {{\n"

            data = bytes.read(struct["length"])
            entry = unpack_from(">4I", data, 0)

            if entry[0] != 0:
                out += f"{INDENT}.bush = &N(bush{num}_Bush),\n"
            if entry[1] != 0:
                out += f"{INDENT}.drops = &N(bush{num}_Drops),\n"
            if entry[2] != 0:
                out += f"{INDENT}.vectors = &N(bush{num}_Vectors),\n"
            if entry[3] != 0:
                out += f"{INDENT}.callback = &N(bush{num}_Callback),\n"

            out += f"}};\n"

        elif struct["type"] == "ShakeTreeEvent":
            new_name = "N(" + name.split('_',1)[1].lower()
            symbol_map[struct["vaddr"]][0][1] = new_name

            num = int(new_name.split("tree",1)[1][:-1])
            out += f"ShakeTreeConfig {new_name} = {{\n"

            data = bytes.read(struct["length"])
            entry = unpack_from(">5I", data, 0)

            if entry[0] != 0:
                out += f"{INDENT}.leaves = &N(tree{num}_Leaves),\n"
            if entry[1] != 0:
                out += f"{INDENT}.trunk = &N(tree{num}_Trunk),\n"
            if entry[2] != 0:
                out += f"{INDENT}.drops = &N(tree{num}_Drops),\n"
            if entry[3] != 0:
                out += f"{INDENT}.vectors = &N(tree{num}_Vectors),\n"
            if entry[4] != 0:
                out += f"{INDENT}.callback = &N(tree{num}_Callback),\n"

            out += f"}};\n"

        elif struct["type"] == "TriggerCoord":
            out += f"Vec4f {name} = {{"

            data = bytes.read(struct["length"])
            entry = unpack_from(">4f", data, 0)

            out += f" {entry[0]:.01f}f, {entry[1]:.01f}f, {entry[2]:.01f}f, {entry[3]:.01f}f }};\n"

        elif struct["type"] == "Header":
            out += f"MapConfig N(config) = {{\n"

            bytes.read(0x10)

            main,entry_list,entry_count = unpack(">IIi", bytes.read(4 * 3))
            out += f"    .main = &N(main),\n"
            out += f"    .entryList = &{entry_list_name},\n"
            out += f"    .entryCount = ENTRY_COUNT({entry_list_name}),\n"

            bytes.read(0x1C)

            bg,tattle = unpack(">II", bytes.read(4 * 2))
            if bg == 0x80200000:
                out += f"    .background = &gBackgroundImage,\n"
            elif bg != 0:
                raise Exception(f"unknown MapConfig background {bg:X}")
            #out += f"    .tattle = 0x{tattle:X},\n"
            INCLUDES_NEEDED["tattle"].append(f"- [0x{(tattle & 0xFF0000) >> 16:02X}, 0x{tattle & 0xFFFF:04X}, {map_name}_tattle]")
            out += f"    .tattle = {{ MSG_{map_name}_tattle }},\n"

            out += f"}};\n"
            afterHeader = True
        elif struct["type"].startswith("Function"):
            bytes.read(struct["length"])
            out += f"s32 {name}();\n"
        elif struct["type"] == "FloatTable":
            vram = int(name.split("_",1)[1][:-1], 16)
            name = f"N(D_{vram:X}_{(vram - 0x80240000) + romstart:X})"
            struct["name"] = name
            out += f"f32 {name}[] = {{"
            for i in range(0, struct["length"], 4):
                if (i % (4 * 4)) == 0:
                    out += f"\n   "

                word = unpack(">f", bytes.read(4))[0]
                out += f" {word:.01f}f,"

            out += f"\n}};\n"
        elif struct["type"] == "VectorList":
            data = bytes.read(struct["length"])
            if len(data) > 0:
                out += f"Vec3f {name}[] = {{\n"
                out += f"\t"
            for i,pos in enumerate(range(0, len(data), 0xC)):
                x, y, z = unpack_from(">fff", data, pos)
                out += f" {{ {x:.01f}, {y:.01f}, {z:.01f} }},"
                if (i+1) % 2 == 0:
                    out += f"\n\t"
            out += f"\n}};\n"

        elif struct["type"] == "Formation":
            out += f"Formation {struct['name']} = {{\n"

            num_bytes_remaining = struct["length"]
            while num_bytes_remaining > 0:
                actor, position, priority, var0, var1, var2, var3 = unpack(">IIIIIII", bytes.read(0x1C))
                num_bytes_remaining -= 0x1C

                out += "    { "

                if actor in symbol_map:
                    out += f"&{symbol_map[actor][0][1]}, "

                    s = f"ActorDesc {symbol_map[actor][0][1]};"
                    if s not in INCLUDES_NEEDED["forward"]:
                        INCLUDES_NEEDED["forward"].append(s)
                else:
                    out += f"{actor}, "


                if position in symbol_map:
                    out += f".position = &{symbol_map[position][0][1]}"

                    s = f"Vec3f {symbol_map[position][0][1]};"
                    if s not in INCLUDES_NEEDED["forward"]:
                        INCLUDES_NEEDED["forward"].append(s)
                else:
                    out += f".position = {position}"

                out += f", .priority = {priority}"

                if var0 == 0 and var1 == 0 and var2 == 0 and var3 == 0:
                    pass
                else:
                    out += f", {var1}, {var2} {var3}, {var4}"

                out += " },\n"

            out += f"}};\n"
        elif struct["type"] == "FormationTable":
            out += f"BattleList {struct['name']} = {{\n"

            num_bytes_remaining = struct["length"]
            while num_bytes_remaining > 0:
                name, formation_length, ptr, stage_ptr, zero = unpack(">IIIII", bytes.read(4 * 5))
                num_bytes_remaining -= 4 * 5

                if name == 0:
                    out += "    {},\n"
                else:
                    out += "    BATTLE("
                    out += f"{symbol_map[name][0][1]}, "
                    out += f"&{symbol_map[ptr][0][1]}, "
                    out += f"&{symbol_map[stage_ptr][0][1]}"
                    out += "),\n"

            out += f"}};\n"
        elif struct["type"] == "StageTable":
            out += f"StageList {struct['name']} = {{\n"

            num_bytes_remaining = struct["length"]
            while num_bytes_remaining > 0:
                name, ptr = unpack(">II", bytes.read(0x8))
                num_bytes_remaining -= 0x8

                if name == 0 and ptr == 0:
                    out += "    {},\n"
                else:
                    out += "    { "
                    out += f"{symbol_map[name][0][1]}, "
                    out += f"&{symbol_map[ptr][0][1]} "
                    out += "},\n"

            out += f"}};\n"
        elif struct["type"] == "DefenseTable":
            out += f"s32 {struct['name']}[] = {{\n"

            num_bytes_remaining = struct["length"]
            while num_bytes_remaining > 0:
                if num_bytes_remaining == 4:
                    bytes.read(0x4)
                    out += "    ELEMENT_END,\n"
                    break

                element, value = unpack(">II", bytes.read(0x8))
                num_bytes_remaining -= 0x8

                element = disasm_script.CONSTANTS["Elements"][element]

                out += f"    {element}, "
                out += f"{value},\n"

            out += f"}};\n"
        elif struct["type"] == "StatusTable":
            out += f"s32 {struct['name']}[] = {{\n"

            num_bytes_remaining = struct["length"]
            while num_bytes_remaining > 0:
                if num_bytes_remaining == 4:
                    bytes.read(0x4)
                    out += "    STATUS_END,\n"
                    break

                element, value = unpack(">Ii", bytes.read(0x8))
                num_bytes_remaining -= 0x8

                element = disasm_script.CONSTANTS["Statuses"][element]

                out += f"    {element}, "
                out += f"{value},\n"

            out += f"}};\n"
        elif struct["type"] == "IdleAnimations":
            out += f"s32 {struct['name']}[] = {{\n"

            num_bytes_remaining = struct["length"]
            while num_bytes_remaining > 0:
                if num_bytes_remaining == 4:
                    bytes.read(0x4)
                    out += "    STATUS_END,\n"
                    break

                element, anim = unpack(">II", bytes.read(0x8))
                num_bytes_remaining -= 0x8

                element = disasm_script.CONSTANTS["Statuses"][element]

                sprite_id =  (anim & 0x00FF0000) >> 16
                palette_id = (anim & 0x0000FF00) >> 8
                anim_id =    (anim & 0x000000FF) >> 0
                sprite =  disasm_script.CONSTANTS["NPC_SPRITE"][sprite_id]["name"]
                palette = disasm_script.CONSTANTS["NPC_SPRITE"][sprite_id]["palettes"][palette_id]
                anim =    disasm_script.CONSTANTS["NPC_SPRITE"][sprite_id]["anims"][anim_id]
                anim = f"NPC_ANIM_{sprite}_{palette}_{anim}"
                INCLUDES_NEEDED["sprites"].add(sprite)

                out += f"    {element}, "
                out += " " * (16 - len(element))
                out += f"{anim},\n"

            out += f"}};\n"
        elif struct["type"] == "PartsTable":
            out += f"ActorPartDesc {struct['name']}[] = {{\n"

            for _ in range(0, struct["length"] // 36):
                d = unpack(">IbbbbbbhIIIIxxxxxxxx", bytes.read(36))

                out += INDENT + "{\n"
                out += INDENT + INDENT + f".flags = {read_flags(d[0], 'ActorPartFlags')},\n"
                out += INDENT + INDENT + f".index = {d[1]},\n"
                out += INDENT + INDENT  + f".posOffset = {{ {d[2]}, {d[3]}, {d[4]} }},\n"
                out += INDENT + INDENT  + f".targetOffset = {{ {d[5]}, {d[6]} }},\n"
                out += INDENT + INDENT  + f".opacity = {d[7]},\n"
                out += INDENT + INDENT  + f".idleAnimations = {read_ptr(d[8], symbol_map)},\n"
                out += INDENT + INDENT  + f".defenseTable = {read_ptr(d[9], symbol_map)},\n"
                out += INDENT + INDENT  + f".eventFlags = {read_flags(d[10], 'ActorEventFlags')},\n"
                out += INDENT + INDENT  + f".elementImmunityFlags = {d[11]},\n" # TODO flags
                out += INDENT + "},\n"

            out += f"}};\n"
        elif struct["type"] == "Actor":
            out += f"ActorDesc {struct['name']} = {{\n"

            d = unpack(">IxBBBhxxIIIBBBBBBBBbbbbbbbb", bytes.read(struct["length"]))

            out += INDENT + f".flags = {read_flags(d[0], 'ActorFlags')},\n"
            out += INDENT + f".type = {d[1]},\n" # TODO enum
            out += INDENT + f".level = {d[2]},\n"
            out += INDENT + f".maxHP = {d[3]},\n"
            out += INDENT + f".partCount = ARRAY_COUNT({read_ptr(d[5], symbol_map)}),\n"
            out += INDENT + f".partsData = {read_ptr(d[5], symbol_map)},\n"
            out += INDENT + f".script = {read_ptr(d[6], symbol_map)},\n"
            out += INDENT + f".statusTable = {read_ptr(d[7], symbol_map)},\n"
            out += INDENT + f".escapeChance = {d[8]},\n"
            out += INDENT + f".airLiftChance = {d[9]},\n"
            out += INDENT + f".spookChance = {d[10]},\n"
            out += INDENT + f".baseStatusChance = {d[11]},\n"
            out += INDENT + f".upAndAwayChance = {d[12]},\n"
            out += INDENT + f".spinSmashReq = {d[13]},\n"
            out += INDENT + f".powerBounceChance = {d[14]},\n"
            out += INDENT + f".coinReward = {d[15]},\n"
            out += INDENT + f".size = {{ {d[16]}, {d[17]} }},\n"
            out += INDENT + f".hpBarOffset = {{ {d[18]}, {d[19]} }},\n"
            out += INDENT + f".statusIconOffset = {{ {d[20]}, {d[21]} }},\n"
            out += INDENT + f".statusMessageOffset = {{ {d[22]}, {d[23]} }},\n"

            out += f"}};\n"

            pass
        elif struct["type"] == "Stage":
            out += f"Stage {struct['name']} = {{\n"

            texture, shape, hit, preBattle, postBattle, bg, unk_18, unk_1C, unk_20, unk_24 = unpack(">IIIIIIIIII", bytes.read(struct["length"]))

            if texture != 0:
                out += f"    .texture = {symbol_map[texture][0][1]},\n"

            if shape != 0:
                out += f"    .shape = {symbol_map[shape][0][1]},\n"

            if hit != 0:
                out += f"    .hit = {symbol_map[hit][0][1]},\n"

            if bg != 0:
                out += f"    .bg = {symbol_map[bg][0][1]},\n"

            if preBattle != 0:
                out += f"    .preBattle = {symbol_map[preBattle][0][1]},\n"

            if postBattle != 0:
                out += f"    .postBattle = {symbol_map[postBattle][0][1]},\n"

            if unk_18 != 0:
                out += f"    .foregroundModelList = {symbol_map[unk_18][0][1]},\n"

            if unk_1C != 0:
                out += f"    .unk_1C = {unk_1C:X},\n"

            if unk_20 != 0:
                out += f"    .unk_20 = {unk_20:X},\n"

            if unk_24 != 0:
                out += f"    .unk_24 = {unk_24:X},\n"

            out += f"}};\n"
        else: # unknown type of struct
            if struct["name"].startswith("N(unk_802"):
                vram = int(name.split("_",1)[1][:-1], 16)
                name = f"N(D_{vram:X}_{(vram - 0x80240000) + romstart:X})"
                struct["name"] = name

            if struct["type"] == "Padding":
                out += "static "
            if struct["length"] // 4 > 1:
                out += f"s32 {name}[] = {{"
            else:
                out += f"s32 {name} = {{"

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
        if not struct["type"] == "Function":
            INCLUDED["functions"].add(name)

    # end of data
    return out

def parse_midx(file, prefix="", vram=0x80240000):
    structs = []

    for line in file.readlines():
        s = line.split("#")
        if len(s) == 5 or len(s) == 6:
            if s[0] == "$Start": continue
            if s[0] == "$End": continue

            structs.append({
                "name": "N(" + prefix + name_struct(s[0]) + ")",
                "type": s[1],
                "start": int(s[2], 16),
                "vaddr": int(s[3], 16),
                "length": int(s[4], 16),
                "end": int(s[2], 16) + int(s[4], 16),
            })
        elif "Missing" in s:
            start = int(s[1], 16)
            end = int(s[2], 16)
            vaddr = start + vram
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
            vaddr = start + vram
            structs.append({
                "name": f"{prefix}pad_{start:X}",
                "type": "Padding",
                "start": start,
                "vaddr": vaddr,
                "length": end - start,
                "end": end,
            })
        else:
            raise Exception(str(s))

    structs.sort(key=lambda s: s["start"])
    return structs

def name_struct(s):
    s = s[1:].replace("???", "unk")

    s = s.replace("Function", "func")

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
    parser.add_argument("--comments", action="store_true", help="Write offset/vaddr comments")

    args = parser.parse_args()

    base, ext = os.path.splitext(os.path.basename(args.idxfile))
    if ext == ".midx":
        map_name = base
        area_name, _ = map_name.split("_")
        segment_name = f"world/area_{area_name}/{map_name}"
        is_battle = False
    else:
        battle_area = "_".join(base.lower().split(" ")[1:])

        if "partner" in base:
            segment_name = f"battle/partners/{battle_area}"
        elif "/starpower/src/" in args.idxfile:
            segment_name = f"battle/star/{battle_area}"
        else:
            segment_name = f"battle_partner_{battle_area}"

        is_battle = True

    symbol_map = {}
    def add_to_symbol_map(addr, pair):
        if addr in symbol_map:
            symbol_map[addr].append(pair)
        else:
            symbol_map[addr] = [pair]

    disasm_script.get_constants()

    with open(os.path.join(DIR, "../ver/current/splat.yaml")) as f:
        splat_config = yaml.safe_load(f.read())

        rom_offset = -1
        for segment in splat_config["segments"]:
            if isinstance(segment, dict) and (segment.get("dir") == segment_name or segment.get("name") == segment_name):
                rom_offset = segment["start"]
                vram = segment["vram"]
                break

    if rom_offset == -1:
        print(f"can't find segment with dir or name '{segment_name}' in splat.yaml")
        exit(1)

    if ext == ".midx":
        function_replacements = get_function_list(area_name, map_name, rom_offset)
        INCLUDED["includes"] = get_include_list(area_name, map_name)
    else:
        function_replacements = {}

    with open(args.idxfile, "r") as f:
        midx = parse_midx(f, vram=vram)

    with open(os.path.join(DIR, "../ver/current/baserom.z64"), "rb") as romfile:
        name_fixes = {
                       "script_NpcAI": "npcAI",
                       "aISettings": "npcAISettings",
                       "script_ExitWalk": "exitWalk",
                       "script_MakeEntities": "makeEntities",
                     }
        total_npc_counts = {}
        for struct in midx:
            romfile.seek(struct["start"] + rom_offset)

            name = struct["name"]

            if name.startswith("N("):
                name = name[2:-1]

            if struct['vaddr'] in function_replacements:
                name = function_replacements[struct['vaddr']]

            if name.split("_",1)[0] in name_fixes:
                name = name_fixes[name.split("_",1)[0]] + "_" + name.rsplit("_",1)[1]
            elif name.startswith("script_"):
                name = name.split("script_",1)[1]
            elif "_Main_" in name:
                name = "main"
            elif "ASCII" in name:
                name = name.replace("ASCII", "ascii")

            if name not in INCLUDED["includes"]:
                name = name[0].lower() + name[1:]

            name = "N(" + name + ")"
            struct["name"] = name

            # decode rodata stuff so it can be written inline instead of by pointer (which wouldn't match)
            if struct["type"] == "ASCII":
                string_data = romfile.read(struct["length"]).decode("ascii")

                # strip null terminator(s)
                while string_data[-1] == "\0":
                    string_data = string_data[:-1]

                string_literal = json.dumps(string_data)
                add_to_symbol_map(struct["vaddr"], [struct["vaddr"], string_literal])
            elif struct["type"] == "SJIS":
                string_data = sjis.decode(romfile.read(struct["length"]))

                string_literal = '"' + string_data + '"'
                add_to_symbol_map(struct["vaddr"], [struct["vaddr"], string_literal])
            elif struct["type"] == "ConstDouble":
                double = unpack_from(">d", romfile.read(struct["length"]), 0)[0]
                double_literal = f"{double}"
                add_to_symbol_map(struct["vaddr"], [struct["vaddr"], double_literal])
            elif struct["type"] == "NpcGroup":
                for z in range(struct["length"]//0x1F0):
                    npc = romfile.read(0x1F0)
                    npc_id = unpack_from(">I", npc, 0)[0]
                    if npc_id >= 0:
                        anim = unpack_from(">I", npc, 0x1A0)[0]
                        if not anim == 0:
                            sprite_id =  (anim & 0x00FF0000) >> 16
                            sprite =  disasm_script.CONSTANTS["NPC_SPRITE"][sprite_id]["name"].upper()
                            if npc_id not in total_npc_counts:
                                total_npc_counts[npc_id] = sprite
                add_to_symbol_map(struct["vaddr"], [struct["vaddr"], struct["name"]])
            else:
                add_to_symbol_map(struct["vaddr"],  [struct["vaddr"], struct["name"]])

        # fix NPC names
        curr_counts = {}
        for id_, name in total_npc_counts.items():
            if sum(x == name for x in total_npc_counts.values()) > 1:
                if name not in curr_counts:
                    curr_counts[name] = 0
                nname = name
                name = name + f"{curr_counts[name]}"
                curr_counts[nname] += 1
            name = f"NPC_{name}"
            disasm_script.CONSTANTS["MAP_NPCS"][id_] = name
            INCLUDES_NEEDED["npcs"][id_] = name

        for id_, name in disasm_script.CONSTANTS["NpcIDs"].items():
            disasm_script.CONSTANTS["MAP_NPCS"][id_] = name

        romfile.seek(rom_offset, 0)

        disasm = disassemble(romfile, midx, symbol_map, args.comments, rom_offset)

        print("========== Includes needed: ===========\n")
        if is_battle:
            print(f"#include \"battle/battle.h\"")
        else:
            print(f"#include \"map.h\"")
        print(f"#include \"message_ids.h\"")
        if INCLUDES_NEEDED["sprites"]:
            for npc in sorted(INCLUDES_NEEDED["sprites"]):
                print(f"#include \"sprite/npc/{npc}.h\"")
        print()

        if INCLUDES_NEEDED["forward"]:
            print("========== Forward declares: ==========\n")
            for forward in sorted(INCLUDES_NEEDED["forward"]):
                if not (forward.startswith("ApiStatus") or forward.startswith("void")):
                    print("extern " + forward)
                else:
                    print(forward)
            print()

        if INCLUDES_NEEDED["npcs"]:
            print("========== NPCs needed: ===========\n")
            print(f"enum {{")
            lastnum = -1
            for i, (k, v) in enumerate(sorted(INCLUDES_NEEDED["npcs"].items())):
                print(f"    {v}" + (f" = {k}" if ((k > 0 and i == 0) or (k != lastnum+1)) else "") + ",")
                lastnum = k
            print(f"}};")
            print()

        [print(x) for x in INCLUDES_NEEDED["tattle"]]
        print()

        print("=======================================\n")
        print(disasm.rstrip())


