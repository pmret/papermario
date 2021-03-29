from pathlib import Path
import argparse
from struct import unpack_from

constants = {}
def get_constants():
    global constants
    valid_enums = { "ItemId", "PlayerAnim", "ActorID", "Event", "SoundId" }
    for enum in valid_enums:
        constants[enum] = {}
    constants["NPC_SPRITE"] = {}

    include_path = Path(Path(__file__).resolve().parent.parent / "include")
    enums = Path(include_path / "enums.h").read_text()

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
            constants[this_enum][int(id_, 16)] = name

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
                if int(id_, 16) not in constants["NPC_SPRITE"]:
                    constants[enum][int(id_, 16)] = {"name":"", "palettes":{}, "anims":{}}
                constants[enum][int(id_, 16)]["name"] = name
            elif enum == "NPC_PALETTE":
                constants["NPC_SPRITE"][int(saved_id, 16)]["palettes"][int(id_, 16)] = name
            elif enum == "NPC_ANIM":
                constants["NPC_SPRITE"][int(saved_id, 16)]["anims"][int(id_, 16)] = name
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
    out = []
    arr = []
    for i in range(var["num"]):
        if var["type"] in STRUCTS:
            type_ = "struct"
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
            if var["type"]  == "s8" or var["type"]  == "char":
                if var["type"]  == "char":
                    type_ = "hex"
                data = unpack_from('>b', fd, offset)[0]
                offset += 1
            elif var["type"]  == "u8":
                data = unpack_from('>B', fd, offset)[0]
                offset += 1
            elif var["type"]  == "s16" or var["type"] in ("ItemId"):
                offset += offset % 2
                data = unpack_from('>h', fd, offset)[0]
                offset += 2
            elif var["type"]  == "u16":
                offset += offset % 2
                data = unpack_from('>H', fd, offset)[0]
                offset += 2
            elif var["type"]  == "s32" or var["type"] in ("NpcId", "NpcAnimID", "MessageID"):
                poff = offset
                offset += offset % 4
                data = unpack_from('>i', fd, offset)[0]
                offset += 4
            elif var["type"]  == "u32":
                offset += offset % 4
                data = unpack_from('>I', fd, offset)[0]
                offset += 4
            elif var["type"]  == "f32":
                offset += offset % 4
                data = unpack_from('>f', fd, offset)[0]
                type_ = "float"
                offset += 4
            elif var["type"] == "X32":
                offset += offset % 4
                data = unpack_from('>f', fd, offset)[0]
                type_ = "float"
                if data < -1000.0 or data > 1000.0:
                    type_ = "int"
                    data = unpack_from('>i', fd, offset)[0]
                offset += 4
            elif var["ptr"]:
                offset += offset % 4
                data = unpack_from('>I', fd, offset)[0]
                type_ = "ptr"
                offset += 4
            else:
                print(f"Unknown data type \"{var['type']}\"")
                exit()
        if var["num"] == 1:
            out.append({"name":var["name"], "type":type_, "data":data})
        else:
            arr.append({"name":var["name"], "type":type_, "data":data})

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
                    if val2["type"] == "float":
                        line += f"{val2['data']:.01f}f"
                    elif val2["type"] == "hex":
                        line += f"0x{val2['data']:X}"
                    elif val2["type"] == "ptr":
                        if val2["data"] == 0:
                            line += f"NULL"
                        else:
                            line += f"0x{val2['data']:08X}"
                    else:
                        line += f"{val2['data']}"
                line += " }"
                if not is_array:
                    line += ","
            else:

                if "flags" in val["name"].lower() or "animations" in val["name"].lower():
                    if val["name"] == "flags":
                        val["type"] = "ptr"
                    elif val["name"] == "dropFlags":
                        val["type"] = "hex"
                    val["data"] = abs(val["data"])

                if val["type"] == "float":
                    line += f"{val['data']:.01f}f"
                elif val["type"] == "hex":
                    line += f"0x{val['data']:X}"
                elif val["type"] == "ptr":
                   if val["data"] == 0:
                       line += f"NULL"
                   else:
                       line += f"0x{val['data']:08X}"
                else:
                    line += f"{val['data']}"

                if not (is_array or is_struct):
                    line += ","

        out.append(line)

    return out

def output_type2(fd, offset, var):
    vals = []
    for var in STRUCTS[args.type]:
        tmp, offset = get_vals(fd, offset, var)
        vals.extend(tmp)

    #print(vals)
    #print()
    out = [f"{args.type} = " + "{"]
    out.extend(print_data(vals, 1, True))
    out.append("};")
    #print("END======")
    #print("\n".join(out))
    return "\n".join(out)

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
                a.append(int(x, 0))
        vals.extend(a)
    return vals, i

def cull_struct(fd, i):
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
        temp = ""
        for z,y in enumerate(range(x)):
            if z > 0:
                prefix += ", "
            prefix += f"{vals[y]}"
        out.append(prefix + suffix)
        #print(f"Ending at {fd[i]}")
    return "\n".join(out), i

def MacroReplaceStaticNPC(fd):
    replace_cull = { "unk_1C", "movement" }
    fd = fd.splitlines()
    out = []
    i = 0
    while i < len(fd):
        if any(f".{x}" in fd[i] for x in replace_cull):
            vals, i = cull_struct(fd, i)
            if vals:
                out.append(vals)

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
                item_name = constants["ItemId"][item[0]]
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
                sprite =  constants["NPC_SPRITE"][sprite_id]["name"]
                palette = constants["NPC_SPRITE"][sprite_id]["palettes"][palette_id]
                anim =    constants["NPC_SPRITE"][sprite_id]["anims"][anim_id]
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
                else:
                    print(f"Unknown heart drop macro, values were {round(vals[0][1] / 327.67, 2)} and {round(vals[0][3] / 327.67, 2)}")
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

parser = argparse.ArgumentParser()
parser.add_argument("file", type=str, help="File to decompile struct from")
parser.add_argument("offset", type=lambda x: int(x, 0), help="Offset to decompile struct from")
parser.add_argument("type", type=str, help="Struct type to decompile")
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

fd = Path(args.file).resolve().read_bytes()
out = output_type2(fd, args.offset, STRUCTS[args.type])

if args.type.lower() == "staticnpc":
    print(MacroReplaceStaticNPC(out))
elif args.type.lower() == "npcaisettings":
    print(out)
elif args.type.lower() == "npcsettings":
    print(MacroReplaceNpcSettings(out))
else:
    print(f"Add me type: {args.type}")
