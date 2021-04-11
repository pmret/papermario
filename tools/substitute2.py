from pathlib import Path

FUNC="""    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);

    set_transition_stencil_color(0, var1, var2, var3);
    return ApiStatus_DONE2;
}""".splitlines()

NEW_FUNC_NAME = f"UnkFunc35"
NEW_INCLUDE = f"#include \"world/common/{NEW_FUNC_NAME}.inc.c\""

RENAMED = []
def parse_folder(path):
    for entry in path.iterdir():
        if entry.is_dir():
            parse_folder(entry)
            continue

        if not "area" in str(entry):
            continue

        area_name = entry.parts[3]
        fd = entry.read_text().splitlines()

        i = 0
        while i < len(fd):
            if (#i+2 < len(fd) and 
                fd[i].startswith("INCLUDE_ASM") or 
                fd[i].startswith("ApiStatus N(") or
                fd[i].startswith("void N(")):
                #and fd[i+1] == "/*"):
                if fd[i].startswith("INCLUDE_ASM"):
                    base_fd = i+3
                    base_name = i+2
                elif fd[i].startswith("ApiStatus N(") or fd[i].startswith("void N("):
                    base_fd = i+1
                    base_name = i

                if len(fd[base_fd:]) < len(FUNC):
                    i += 1
                    continue

                #print(f"Starting from {fd[base_fd]}")

                for func, test in zip(fd[base_fd:], FUNC):
                    if func != test:
                        break
                else:
                    print(f"Found a match in {entry}: {fd[i]}")
                    #print("\n".join(fd[i:i+3+len(FUNC)+1]))
                    #print("\n".join(fd))

                    include_path = Path("src/world/common/") / (NEW_FUNC_NAME + ".inc.c")
                    if not include_path.is_file():
                        name_start = fd[base_name].find("N(")
                        name_end = fd[base_name].find("(",name_start+2)
                        new_file_name = fd[base_name][:name_start] + "N(" + NEW_FUNC_NAME + ")" + fd[base_name][name_end:]
                        
                        new_fd = ["#include \"common.h\"",
                                  "#include \"map.h\"",
                                  "",
                                  new_file_name,
                                  ]
                        new_fd.extend(FUNC)
                        include_path.write_text("\n".join(new_fd))

                    if fd[i].startswith("INCLUDE_ASM"):
                        old_func_name = fd[i].split(",")[2].strip().replace(");", "")
                    else:
                        old_func_name = fd[i].split("N(",1)[1].split(")",1)[0]

                    RENAMED.append({"name":old_func_name, "area":area_name})

                    fd = fd[:i] + [NEW_INCLUDE] + fd[base_fd+len(FUNC)+1:]

                    if i+1 < len(fd) and fd[i+1] != "":
                        fd = fd[:i+1] + [""] + fd[i+1:]

                    if fd[-1] != "":
                        fd.append("")

                    #print("\n".join(fd))

                    entry.write_text("\n".join(fd))

                    break

            i += 1

parse_folder(Path("src/world"))

def do_renames_asm(path):
    for entry in path.iterdir():
        if entry.is_dir():
            do_renames_asm(entry)
            continue

        fd = entry.read_text()
        for rename in RENAMED:
            if rename["name"] in fd:
                fd = fd.replace(rename["name"], f"{rename['area']}_{NEW_FUNC_NAME}")
                entry.write_text(fd)
do_renames_asm(Path("ver/us/asm"))

def do_renames_src(path):
    for entry in path.iterdir():
        if entry.is_dir():
            do_renames_src(entry)
            continue

        fd = entry.read_text().splitlines()
        i = 0
        renamed = False
        while i < len(fd):
            for rename in RENAMED:
                start = fd[i].find(rename["name"])
                if start > -1:
                    renamed = True
                    if fd[i][start-1] == "(":
                        fd[i] = fd[i].replace(rename["name"], f"{NEW_FUNC_NAME}")
                    else:
                        fd[i] = fd[i].replace(rename["name"], f"N({NEW_FUNC_NAME})")
            i += 1
        if renamed:
            entry.write_text("\n".join(fd))
do_renames_src(Path("src/world"))
