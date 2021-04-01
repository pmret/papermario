import sys
from pathlib import Path

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

if "found no matches" in files[0]:
    print(f"Could not find any matching functions")
    exit()

#first get the decomped code
function_text = ""

function, file_path, decomp = find_file_path(files[0])
if decomp:
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

    if not function:
        print(f"Failed to find {file}")
        continue

    print(f"Func:\"{function}\" path:\"{file_path}\" Decomped: {decomp}")

    file_path = (Path(__file__).parent.parent / file_path).resolve()
    
    # don't want to try and replace already-decompiled functions
    if decomp:
        print(f"{file_path} already has this function decompiled")
        continue

    func_file = file_path.read_text().splitlines()
    new_func_file = []
    for i,line in enumerate(func_file):
        if line:
            stripped_line = line.strip()
            split_line = stripped_line.split(" ")

            if len(split_line) > 2 and "INCLUDE_ASM" in split_line[0] and function in split_line[2] and i+1 < len(func_file) and "/*" not in func_file[i+1]:
                new_func_file.append(stripped_line)
                temp = function_text.splitlines()
                temp[1] = temp[1].replace("N()", f"N({function})")
                new_func_file.append("\n".join(temp))
            elif len(split_line) > 2 and "INCLUDE_ASM" in split_line[0] and function in split_line[2] and i+1 < len(func_file) and "/*" in func_file[i+1]:
                print(f"{file_path} already has this function commented out")
                new_func_file.append(line)
            else:
                new_func_file.append(line)
        else:
            new_func_file.append(line)

    #print(f"Altering {file_path}")
    #print("\n".join(new_func_file))
    file_path.write_text("\n".join(new_func_file))
