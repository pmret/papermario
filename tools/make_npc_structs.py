from pathlib import Path
import argparse
from struct import unpack_from

CONSTANTS = {}
def get_constants():
    global CONSTANTS
    valid_enums = { "StoryProgress", "ItemIDs", "PlayerAnims",
        "ActorIDs", "Events", "SoundIDs", "SongIDs", "Locations",
        "AmbientSounds", "NpcIDs", "Emotes" }
    for enum in valid_enums:
        CONSTANTS[enum] = {}
    CONSTANTS["NPC_SPRITE"] = {}

    include_path = Path(Path(__file__).resolve().parent.parent / "include")
    enums = Path(include_path / "enums.h").read_text().splitlines()

    # defines
    '''
    for line in enums.splitlines():
        this_enum = ""
        for enum in valid_enums:
            if f"#define {enum}_" in line:
                this_enum = enum
                break;

        if this_enum:
            name = line.split(" ",2)[1]
            id_ = line.split("0x", 1)[1]
            if " " in id_:
                id_ = id_.split(" ",1)[0]
            CONSTANTS[this_enum][int(id_, 16)] = name

    '''

    # enums
    for i,line in enumerate(enums):
        if line.startswith("enum "):
            enum_name = line.split(" ",1)[1].split(" {",1)[0]
            if enum_name in valid_enums:
                CONSTANTS[enum_name] = {}
                last_num = 0
                i += 1
                while "}" not in enums[i]:
                    if not enums[i]:
                        i += 1
                        continue

                    name = enums[i].strip()
                    val = last_num+1
                    if "=" in name:
                        name, val = name.split(" = ")
                        val = int(val[:-1], 0)
                        if val >= 0x80000000:
                            val -= 0x100000000
                    else:
                        name = name[:-1]
                    name = name.strip()
                    #print("\"" + name + "\"", "===", val)

                    CONSTANTS[enum_name][val] = name.strip()
                    i += 1
                    last_num = val

    # sprites
    sprite_path = Path(Path(__file__).resolve().parent.parent / "ver" / "current" / "build" / "include" / "sprite" / "npc")
    for file in sprite_path.iterdir():
        fd = file.read_text()
        for line in fd.splitlines():
            if "#define _NPC_SPRITE_" in line:
                enum = "NPC_SPRITE"
            elif "#define _NPC_PALETTE_" in line:
                enum = "NPC_PALETTE"
            elif "#define _NPC_ANIM_" in line:
                enum = "NPC_ANIM"
            else:
                continue

            name = line.split(" ",2)[1]
            id_ = line.split("0x", 1)[1]
            if " " in id_:
                id_ = id_.split(" ",1)[0]
            name = name.split(f"_{enum}_", 1)[1]
            if enum == "NPC_SPRITE":
                saved_name = name
                saved_id = id_
            else:
                name = name.rsplit(f"{saved_name}_")[1]

            if enum == "NPC_SPRITE":
                if int(id_, 16) not in CONSTANTS["NPC_SPRITE"]:
                    CONSTANTS[enum][int(id_, 16)] = {"name":"", "palettes":{}, "anims":{}}
                CONSTANTS[enum][int(id_, 16)]["name"] = name
            elif enum == "NPC_PALETTE":
                CONSTANTS["NPC_SPRITE"][int(saved_id, 16)]["palettes"][int(id_, 16)] = name
            elif enum == "NPC_ANIM":
                CONSTANTS["NPC_SPRITE"][int(saved_id, 16)]["anims"][int(id_, 16)] = name
    return

STRUCTS = {}

def parse_var(line):
    #print(f"Parsing {line}")
    if "*/ " in line:
        line = line.split("*/ ",1)[1]
    line = line.split(";",1)[0].strip()

    if "," in line or "(*" in line:
        return (None, None, None, None)
    elif "union " in line:
        return ("union", None, None, None)

    #print(f"Parsed {line}")
    if " " in line:
        if line.startswith("struct "):
            struct, type_, name = line.split(" ")
        else:
            type_, name = line.split(" ")
    else:
        type_ = "function"
        name = line.split("(", 1)[0]
    count = 1
    if "[" in name:
        name, *count = name.split("[")
        counts = 1
        count.reverse()
        for dim in count:
            counts *= int(dim[:-1], 0)
        count = counts

    is_ptr = "*" in type_ or type_ == "UNK_PTR"
    return (type_, name, count, is_ptr)

def parse_file(filename):
    fd = filename.read_text().splitlines()
    i = 0
    while i < len(fd):
        #supported = [f"typedef struct {x}" in fd[i] for x in SUPPORTED_STRUCTS]
        #if any(supported):
        if "typedef struct " in fd[i]:
            #supported_name = [SUPPORTED_STRUCTS[i] for i,x in enumerate(supported) if x][0]
            supported_name = fd[i].split("typedef struct ", 1)[1].split(" {", 1)[0]
            if supported_name == "{":
                supported_name = ""
            #print(f"Parsing struct \"{supported_name}\"")

            struct_to_add = []
            i += 1
            while ("} " + f"{supported_name.upper()}") not in fd[i].split(";",1)[0].upper():
                type_, name, count, ptr = parse_var(fd[i])

                if type_ == None:
                    i += 1
                    continue

                union = []
                if type_ == "union":
                    i += 1
                    while "}" not in fd[i]:
                        type_, name, count, ptr = parse_var(fd[i])
                        union.append({"type":type_, "name": name, "num":count, "ptr":ptr})
                        i += 1
                    name = fd[i].split("}", 1)[1].split(";", 1)[0]

                #print(supported_name, type_, name, count)
                struct_to_add.append({"type":type_, "name": name, "num":count, "ptr":ptr, "union":union})

                i += 1
            #print(f"Broke on line {fd[i]}")
            #print()
            if supported_name == "":
                supported_name = fd[i].split("} ",1)[1].split(";",1)[0]
                if "[" in supported_name:
                    supported_name = supported_name[:-2]
            STRUCTS[supported_name] = struct_to_add
        i += 1

def get_structs():
    parse_file(Path(Path(__file__).parent.parent / "include" / "map.h"))
    parse_file(Path(Path(__file__).parent.parent / "include" / "common_structs.h"))

def get_vals(fd, offset, var):
    global STRUCTS

    out = []
    arr = []
    for i in range(var["num"]):
        if var["type"] in STRUCTS:
            type_ = "struct"
            fmt = "s"
            data = []
            for var2 in STRUCTS[var["type"]]:
                out3, offset = get_vals(fd, offset, var2)
                data.extend(out3)
            #if var["num"] == 1:
            #    out.extend(out2)
            #else:
            #out.append(out2)
        else:
            type_ = "int"
            fmt = "d"
            if var["type"]  == "s8" or var["type"]  == "char":
                if var["type"]  == "char":
                    type_ = "hex"
                    fmt = "X"
                data = unpack_from('>b', fd, offset)[0]
                offset += 1
            elif var["type"]  == "u8":
                data = unpack_from('>B', fd, offset)[0]
                fmt = "d"
                offset += 1
            elif var["type"]  == "s16" or var["type"] in ("ItemID"):
                offset += offset % 2
                data = unpack_from('>h', fd, offset)[0]
                fmt = "d"
                offset += 2
            elif var["type"]  == "u16":
                offset += offset % 2
                data = unpack_from('>H', fd, offset)[0]
                fmt = "d"
                offset += 2
            elif var["type"]  == "s32" or var["type"] in ("NpcID", "NpcAnimID", "MessageID", "BattleID"):
                poff = offset
                offset += offset % 4
                data = unpack_from('>i', fd, offset)[0]
                fmt = "d"
                offset += 4
            elif var["type"]  == "u32":
                offset += offset % 4
                data = unpack_from('>I', fd, offset)[0]
                fmt = "d"
                offset += 4
            elif var["type"]  == "f32":
                offset += offset % 4
                data = unpack_from('>f', fd, offset)[0]
                type_ = "float"
                fmt = ".01f"
                offset += 4
            elif var["type"] == "X32":
                offset += offset % 4
                data = unpack_from('>f', fd, offset)[0]
                type_ = "Xfloat"
                fmt = ".01f"
                if data < -1000.0 or data > 1000.0:
                    type_ = "Xint"
                    fmt = "d"
                    data = unpack_from('>i', fd, offset)[0]
                offset += 4
            elif var["ptr"]:
                offset += offset % 4
                data = unpack_from('>I', fd, offset)[0]
                type_ = "ptr"
                fmt = "08X"
                offset += 4
            else:
                print(f"Unknown data type \"{var['type']}\"")
                exit()
        if var["num"] == 1:
            out.append({"name":var["name"], "type":type_, "fmt":fmt, "data":data})
        else:
            arr.append({"name":var["name"], "type":type_, "fmt":fmt, "data":data})

    if var["num"] > 1:
        out.append(arr)
    return out, offset

def INDENT(depth):
    return f"    " * depth

def print_data(vals, indent, needs_name, is_array=False, is_struct=False):
    out = []
    for val in vals:
        line = ""
        if needs_name:
            line = INDENT(indent)
        #print(val)
        # array
        if type(val) is list:
            line += f".{val[0]['name']} = " + "{ "
            struct = type(val[0]["data"]) is list
            line += ", ".join(print_data(val, indent + 1, needs_name=False, is_array=True, is_struct=struct))
            if struct:
                line += "\n" + INDENT(indent) + "},"
            else:
                line += " },"
        else:
            if needs_name:
                line += f".{val['name']} = "
            if type(val["data"]) is list:
                if is_struct:
                    line += "\n"
                    line += INDENT(indent)
                line += "{ "
                for x,val2 in enumerate(val["data"]):
                    if x > 0:
                        line += ", "
                    #line += f".{val2['name']} = "
                    fmt = val2["fmt"]
                    if val2["type"] == "float":
                        line += f"{val2['data']:{fmt}}f"
                    elif val["type"] == "Xfloat":
                        line += "{ .f = " + f"{val['data']:{fmt}}f" + " }"
                    elif val["type"] == "Xint":
                        line += "{ .s = " + f"{val['data']:{fmt}}" + " }"
                    elif val2["type"] == "hex":
                        line += f"0x{val2['data']:{fmt}}"
                    elif val2["type"] == "ptr":
                        if val2["data"] == 0:
                            line += f"NULL"
                        else:
                            line += f"0x{val2['data']:{fmt}}"
                    else:
                        line += f"{val2['data']}"
                line += " }"
                if not is_array:
                    line += ","
            else:

                if "flags" in val["name"].lower() or "animations" in val["name"].lower():
                    if val["name"] == "flags":
                        val["fmt"] = "08X"
                        val["type"] = "hex"
                    elif "flag" in val["name"].lower():
                        val["type"] = "hex"
                        val["fmt"] = "X"
                    val["data"] = abs(val["data"])
                elif "tattle" in val["name"]:
                    val["fmt"] = "06X"
                    val["type"] = "hex"

                fmt = val["fmt"]
                if val["type"] == "float":
                    line += f"{val['data']:{fmt}}f"
                elif val["type"] == "Xfloat":
                    line += "{ .f = " + f"{val['data']:{fmt}}f" + " }"
                elif val["type"] == "Xint":
                    line += "{ .s = " + f"{val['data']:{fmt}}" + " }"
                elif val["type"] == "hex":
                    line += f"0x{val['data']:{fmt}}"
                elif val["type"] == "ptr":
                   if val["data"] == 0:
                       line += f"NULL"
                   else:
                       line += f"0x{val['data']:{fmt}}"
                else:
                    line += f"{val['data']}"

                if not (is_array or is_struct):
                    line += ","

        out.append(line)

    return out

def output_type2(fd, count, offset, var):
    ultra_out = []
    for i in range(count):
        out = [f"{args.type} = " + "{"]
        vals = []
        for var in STRUCTS[args.type]:
            tmp, offset = get_vals(fd, offset, var)
            vals.extend(tmp)

        out.extend(print_data(vals, 1, True))
        out.append("};")
        ultra_out.append(out)
    return offset, ultra_out #"\n".join(out)

def check_list(vals, depth = 0):
    for x,val in enumerate(vals):
        if type(val) == list:
            if check_list(val, depth + 1):
                return True
        elif val != 0:
            return True
    return False

def recurse_check_list(vals):
    res = 0
    for x,val in enumerate(vals):
        if type(val) == list:
            if check_list(val, 1):
                return len(vals) - x
        elif val != 0:
            return len(vals) - x
    return -1

def get_single_struct_vals(fd, i):
    vals = []
    if not fd[i].rstrip().endswith("},"):
        # must be a sub-struct over multiple lines
        old_i = i
        i += 1
        while not ("}," in fd[i] and "." in fd[i+1]):
            temp = fd[i].split("{",1)[1].split("}",1)[0].split(", ")
            a = []
            for x in temp:
                x = x.strip()
                if x != "":
                    if "." in x:
                        a.append(float(x[:-1]))
                    else:
                        a.append(int(x, 0))
            vals.append(a)
            i += 1
    else:
        # single line
        temp = fd[i].split("{",1)[1].split("}",1)[0].split(", ")
        a = []
        for x in temp:
            x = x.strip()
            if x != "":
                if "." in x:
                    a.append(float(x[:-1]))
                else:
                    a.append(int(x, 0))
        vals.extend(a)
    return vals, i

def cull_struct(fd, i, entirely=False):
    out = []
    vals = []
    #print(f"Culling Starting at {fd[i]}")
    if not fd[i].rstrip().endswith("},"):
        # must be a sub-struct over multiple lines
        old_i = i
        vals, i = get_single_struct_vals(fd, i)

        # reverse and cull entries of only zeros
        x = recurse_check_list(vals[::-1])
        #print(f"Found first index of empty values at idx {x}, vals: {vals}")
        if x < 0:
            #print(f"Ending at {fd[i]}")
            return None, i

        out.append(fd[old_i])
        old_i += 1
        if entirely:
            x = len(vals)
        for y in range(x):
            out.append(fd[old_i])
            old_i += 1

        #print(f"Ending at {fd[i]}")
    else:
        prefix = fd[i].split("{",1)[0] + "{ "
        suffix = " },"

        vals, i = get_single_struct_vals(fd, i)

        # reverse and cull entries of only zeros
        x = recurse_check_list(vals[::-1])
        #print(f"Found first index of empty values at idx {x}, vals: {vals}")
        if x < 0:
            #print(f"Ending at {fd[i]}")
            return None, i

        #out.append(prefix)
        if entirely:
            x = len(vals)
        temp = ""
        for z,y in enumerate(range(x)):
            if z > 0:
                prefix += ", "
            prefix += f"{vals[y]}"
        out.append(prefix + suffix)
        #print(f"Ending at {fd[i]}")
    return "\n".join(out), i

def MacroReplaceStaticNPC(fd):
    structs = { "unk_1C":True, "movement":False, "unk_1E0":True }
    #replace_cull_struct = { "unk_1C", "movement", "unk_1E0" }
    #replace_cull = { "tattle", "extraAnimations", "itemDropChance" }
    fd = fd.splitlines()
    out = []
    i = 0
    while i < len(fd):
        found = ""
        for x in structs:
            if f".{x}" in fd[i]:
                found = x
                break;
        if found:
            # just cull it if possible
            vals, i = cull_struct(fd, i, structs[found])
            if vals:
                out.append(vals)

            i += 1
            continue

        name = fd[i].split(" = ",1)[0].strip()[1:]
        if name not in structs and "{" not in fd[i] and name != ";":
            val = fd[i].split(" = ",1)[1][:-1]
            if "0x" in val:
                val = int(val, 16)
            elif "NULL" in val:
                val = 0
            elif "." in val:
                val = float(val)
            else:
                val = int(val, 10)
            if val == 0 and name != "id":
                i += 1
                continue

        if ".itemDrops" in fd[i]:
            vals, x = cull_struct(fd, i)

            indent = len(fd[i].split(".",1)[0]) // 4
            new_line = fd[i].split("{",1)[0] + "{\n"

            if not vals:
                i = x
                i += 1
                continue

            vals += "\n},\n."
            vals, _ = get_single_struct_vals(vals.splitlines(), 0)

            added_item = False
            for item in vals:
                if item[0] == 0:
                    continue

                added_item = True
                item_name = CONSTANTS["ItemIDs"][item[0]]
                new_line += "    " * (indent+1) + "{ " + item_name + f", {item[1]}, {item[2]}" + " },\n"

            if added_item:
                new_line += "    " * indent + "},"

            out.append(new_line)
            i = x

        elif ".animations" in fd[i]:
            indent = len(fd[i].split(".",1)[0]) // 4
            new_line = fd[i].split("{",1)[0] + "{\n"

            vals, x = get_single_struct_vals(fd, i)
            for val in vals:
                sprite_id =  (val & 0x00FF0000) >> 16
                palette_id = (val & 0x0000FF00) >> 8
                anim_id =    (val & 0x000000FF) >> 0
                sprite =  CONSTANTS["NPC_SPRITE"][sprite_id]["name"]
                palette = CONSTANTS["NPC_SPRITE"][sprite_id]["palettes"][palette_id]
                anim =    CONSTANTS["NPC_SPRITE"][sprite_id]["anims"][anim_id]
                new_line += "    " * (indent+1) + f"NPC_ANIM({sprite}, {palette}, {anim}),\n"
            new_line += "    " * indent + "},"
            out.append(new_line)
            i = x

        elif ".heartDrops" in fd[i] or ".flowerDrops" in fd[i]:
            vals, x = get_single_struct_vals(fd, i)

            new_line = fd[i].split("{",1)[0]

            attempts = vals[0][2]

            if ".heartDrops" in fd[i]:
                if round(vals[0][1] / 327.67, 2) == 70 and round(vals[0][3] / 327.67, 2) == 50:
                    new_line += f"STANDARD_HEART_DROPS({attempts}),"
                elif round(vals[0][1] / 327.67, 2) == 80 and round(vals[0][3] / 327.67, 2) == 50:
                    new_line += f"GENEROUS_HEART_DROPS({attempts}),"
                elif round(vals[0][1] / 327.67, 2) == 80 and round(vals[0][3] / 327.67, 2) == 60:
                    new_line += f"GENEROUS_WHEN_LOW_HEART_DROPS({attempts}),"
                elif round(vals[0][0] / 327.67, 2) == 100 and round(vals[0][1] / 327.67, 2) == 0 and round(vals[0][2] / 327.67, 2) == 0:
                    new_line += f"NO_DROPS,"
                else:
                    print(f"Unknown heart drop macro, values were {round(vals[0][1] / 327.67, 2)} and {round(vals[0][3] / 327.67, 2)}")
                    exit()
            else:
                if round(vals[0][1] / 327.67, 2) == 50 and round(vals[0][3] / 327.67, 2) == 40:
                    new_line += f"STANDARD_FLOWER_DROPS({attempts}),"
                elif round(vals[0][1] / 327.67, 2) == 70 and round(vals[0][3] / 327.67, 2) == 50:
                    new_line += f"GENEROUS_WHEN_LOW_FLOWER_DROPS({attempts}),"
                elif round(vals[0][1] / 327.67, 2) == 40 and round(vals[0][3] / 327.67, 2) == 40:
                    new_line += f"REDUCED_FLOWER_DROPS({attempts}),"
                elif round(vals[0][0] / 327.67, 2) == 100 and round(vals[0][1] / 327.67, 2) == 0 and round(vals[0][2] / 327.67, 2) == 0:
                    new_line += f"NO_DROPS,"
                else:
                    print(f"Unknown flower drop macro, values were {round(vals[0][1] / 327.67, 2)} and {round(vals[0][3] / 327.67, 2)}")
                    exit()

            out.append(new_line)
            i = x

        else:
            out.append(fd[i])
        i += 1
    return "\n".join(out)

def MacroReplaceNpcSettings(fd):
    replace_cull = { "unk_00", "unk_24" }
    fd = fd.splitlines()
    out = []
    i = 0
    while i < len(fd):
        if any(f".{x}" in fd[i] for x in replace_cull):
            vals, i = cull_struct(fd, i)
            if vals:
                out.append(vals)
        else:
            out.append(fd[i])
        i += 1
    return "\n".join(out)

def MacroReplaceNpcGroupList(fd):
    fd = fd.splitlines()
    out = []
    vals = []
    i = 1
    while i < len(fd):
        fd[i] = fd[i].strip()
        if ";" not in fd[i]:
            if "NULL" in fd[i]:
                val = 0
            else:
                if "0x" in fd[i]:
                    val = int(fd[i].split(" = ",1)[1][:-1], 16)
                else:
                    val = int(fd[i].split(" = ",1)[1][:-1], 10)

            vals.append(val)
        i += 1

    out.append(f"    NPC_GROUP(N(D_{vals[1]:X}), BATTLE_ID({(vals[2] & 0xFF000000) >> 24}, {(vals[2] & 0xFF0000) >> 16}, {(vals[2] & 0xFF00) >> 8}, {vals[2] & 0xFF})),")
    return "\n".join(out)

parser = argparse.ArgumentParser()
parser.add_argument("file", type=str, help="File to decompile struct from")
parser.add_argument("type", type=str, help="Struct type to decompile")
parser.add_argument("offset", type=lambda x: int(x, 0), help="Offset to decompile struct from")
parser.add_argument("--count", "-c", "--c", type=int, default=0, help="Num to try and decompile (NpcGroupList)")
args = parser.parse_args()

get_constants()
get_structs()

if args.type not in STRUCTS:
    print(f"Unknown struct type {args.type}")
    exit()

'''
out = [f"{args.type} = " + "{\n"]
offset = args.offset
for var in STRUCTS[args.type]:
    line, offset = output_type(fd, offset, var, 1)
    out.append(line)
out.append("};")
'''

if args.count == 0:
    args.count = 1

fd = Path(args.file).resolve().read_bytes()
offset, out = output_type2(fd, args.count, args.offset, STRUCTS[args.type])

for i,entry in enumerate(out):
    out[i] = "\n".join(entry)

print(f"EvtSource range 0x{args.offset:08X} - 0x{offset:08X}")
print()

if args.type.lower() == "staticnpc":
    print(MacroReplaceStaticNPC(out[0]))
elif args.type.lower() == "npcaisettings":
    print(out[0])
elif args.type.lower() == "npcsettings":
    print(MacroReplaceNpcSettings(out[0]))
elif args.type.lower() == "npcgrouplist":
    print("NpcGroupList N(npcGroupList) = {")
    for i in range(args.count):
        print(MacroReplaceNpcGroupList(out[i]))
    print("};")
else:
    print(f"Add me type: {args.type}")
