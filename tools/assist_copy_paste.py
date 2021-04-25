import sys
from pathlib import Path
import re

WRITE_FILE = False
DO_OVERWRITE = True

def get_file_name(name):
    out = ""
    decomp = False
    if name:
        if "matches total" in name:
            name = name.split(" - ",1)[0]
            decomp = True
            if name[3] == "_":
                name = name[7:]
        else:
            name = name.split(" - ",1)[1]
            if "(decompiled)" in name:
                decomp = True
                name = name.split(" ",1)[0]
                if name[3] == "_":
                    name = name[7:]
        name = name.strip()
        out = name
    return out, decomp

def find_file_path(looking_for):
    global map_
    file_name, decomp = get_file_name(looking_for)
    file_path = ""
    if file_name:
        for i,line in enumerate(map_):
            if file_name in line:
                x = i
                while not map_[x].startswith(" .text"):
                    x -= 1
                x -= 1
                file_path = map_[x].split(".o",1)[0].split("build/",1)[1].strip()
                break
    if not "src/world/area_" in file_path:
        file_path = ""
    return file_name, file_path, decomp



map_file = (Path(__file__).parent.parent / "ver" / "current" / "build" / "papermario.map").read_text().splitlines()
# cut out half the map
map_ = []
found_header = False
for line in map_file:
    if line.startswith(".header"):
        found_header = True
    if found_header:
        map_.append(line)

del map_file

files = sys.stdin.read().splitlines()

if not files or "found no matches" in files[0]:
    print(f"Could not find any matching functions")
    exit()

#first get the decomped code
function_text = ""

function, file_path, decomp = find_file_path(files[0])
if decomp and file_path != "":
    file_path = (Path(__file__).parent.parent / file_path).resolve()
    func_file = file_path.read_text().splitlines()
    for i,line in enumerate(func_file):
        if line:
            line = line.strip()
            split_line = line.split(" ")
            if len(split_line) > 2 and function in split_line[1] and (split_line[0] == "void" or split_line[0] == "s32" or split_line[0] == "ApiStatus"):
                out = ["/*"]
                while not func_file[i].startswith("}"):
                    out.append(func_file[i])
                    i += 1
                out.append("}")
                out.append("*/")

                func_name_start = out[1].find("N(")
                func_name_end = out[1].find(")")
                out[1] = out[1][:func_name_start+2] + out[1][func_name_end:]

                function_text = "\n".join(out)

if function_text == "":
    print(f"Unable to find a decompiled function to copy code from")
    exit()

for file in files[1:]:
    if not file:
        continue
    function, file_path, decomp = find_file_path(file)

    if file_path == "":
        continue

    if not function:
        print(f"Failed to find {file}")
        continue

    if function[3] == "_" and function[6] == "_" and function.startswith(Path(file_path).parts[3]):
        function = function[len("xxx_yy_"):]

    print(f"Func:\"{function}\" path:\"{file_path}\" Decomped: {decomp}")

    asm_path = Path(__file__).parent.parent / "ver" / "us" / "asm" / "nonmatchings"
    fixed = list(Path(file_path).parts[1:])
    fixed[-1] = fixed[-1][:-2]
    asm_path = asm_path / "/".join(fixed) / function
    asm_path = asm_path.with_suffix(".s")

    file_path = (Path(__file__).parent.parent / file_path).resolve()
    
    # don't want to try and replace already-decompiled functions
    if decomp and not DO_OVERWRITE:
        print(f"{file_path} already has this function decompiled and not overwriting")
        continue

    func_file = file_path.read_text().splitlines()
    new_func_file = []
    i = 0
    while i < len(func_file):
        line = func_file[i]
        if line:
            stripped_line = line.strip()
            split_line = stripped_line.split(" ")

            if len(split_line) > 2 and decomp and function in split_line[1]:
                if DO_OVERWRITE:
                    x = i
                    while not (func_file[x] == "}"):
                        x += 1
                    x += 1

                    old_data_name = ""
                    new_data_name = ""

                    if "ptr" in func_file[i+1]:
                        new_func_data = function_text.splitlines()[1:-1]
                        old_data_name = new_func_data[3].split("if (",1)[1].split(" == ",1)[0]
                        new_data_name = func_file[i+1].split(" = ",1)[1][1:-1]

                    func_data = function_text.replace(old_data_name, new_data_name)

                    func_data = func_data.splitlines()[1:-1]
                    func_data[0] = func_data[0].replace("N()", f"N({function})")
                    new_func_file.append("\n".join(func_data))

                    i = x-1
                    #print("\n".join(temp))
                    #print()
                else:
                    new_func_file.append(line)

            elif len(split_line) > 2 and "INCLUDE_ASM" in split_line[0] and function in split_line[2] and ((i+1 < len(func_file) and "/*" not in func_file[i+1] and not func_file[i+1].startswith("#endif")) or (i+1 == len(func_file))):
                new_func_file.append(stripped_line)
                func_data = function_text.splitlines()
                func_data[1] = func_data[1].replace("N()", f"N({function})")
                new_func_file.append("\n".join(func_data))
            
            elif len(split_line) > 2 and "INCLUDE_ASM" in split_line[0] and function in split_line[2] and func_file[i+1].startswith("#endif"):
                if DO_OVERWRITE:
                    #a NON_MATCHING func
                    x = i
                    while not func_file[x].startswith("#ifdef NON_MATCHING"):
                        x -= 1
                    # strip away lines already added
                    new_func_file = new_func_file[:x]
                    new_func_file.append(stripped_line)
                    func_data = function_text.splitlines()
                    func_data[1] = func_data[1].replace("N()", f"N({function})")
                    new_func_file.append("\n".join(func_data))
                    i += 1
                else:
                    new_func_file.append(line)

            elif len(split_line) > 2 and "INCLUDE_ASM" in split_line[0] and function in split_line[2] and i+1 < len(func_file) and "/*" in func_file[i+1]:
                if DO_OVERWRITE:
                    while not (func_file[i] == "}" and func_file[i+1] == "*/"):
                        i += 1
                    i += 1

                    func_data = function_text.splitlines()
                    
                    if asm_path.is_file():
                        asm_data = asm_path.read_text().splitlines()
                        for asm_line in asm_data:
                            if "lui" in asm_line and "D_" in asm_line:
                                new_data_name = asm_line.split("(",1)[1].split(")",1)[0]
                                break
                        old_data_name = func_data[4].split("if (",1)[1].split(" == ",1)[0]
                        func_data = function_text.replace(old_data_name, "N(" + new_data_name + ")").splitlines()

                    new_func_file.append(stripped_line)
                    func_data[1] = func_data[1].replace("N()", f"N({function})")
                    new_func_file.append("\n".join(func_data))

                    #print("\n".join(func_data))
                    #print()
                else:
                    print(f"{file_path} already has this function commented out")
                    new_func_file.append(line)
            else:
                new_func_file.append(line)
        else:
            new_func_file.append(line)
        i += 1

    if new_func_file[-1] != "":
        new_func_file.append("")

    #print("===========")
    #print(f"Altering {file_path}")
    #print("\n".join(new_func_file))
    #print("===========")
    if WRITE_FILE:
        file_path.write_text("\n".join(new_func_file))
    #if "dro_02" in str(file_path):
    #    exit()
