from pathlib import Path

FUNC="""    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 i;

    for (i = script->functionTemp[2].s; i < enemy->territory->patrol.numPoints; i++) {
        if (i[enemy->territory->patrol.points].y <= npc->pos.y) {
            script->functionTemp[2].s = i;
            break;
        }
    }

    npc->moveSpeed = aiSettings->moveSpeed;
    npc->currentAnim = enemy->animList[1];
    script->functionTemp[1].s = 0;
    script->functionTemp[0].s = 1;
}""".splitlines()

NEW_FUNC_NAME = f"UnkFunc16"
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
            if (i+2 < len(fd) and 
                fd[i].startswith("INCLUDE_ASM") and
                fd[i+1] == "/*"):

                for func, test in zip(fd[i+3:], FUNC):
                    if func != test:
                        break
                else:
                    print(f"Found a match in {entry}: {fd[i]}")
                    #print("\n".join(fd[i:i+3+len(FUNC)+1]))
                    #print("\n".join(fd))

                    include_path = Path("src/world/common/") / (NEW_FUNC_NAME + ".inc.c")
                    if not include_path.is_file():
                        name_start = fd[i+2].find("N(")
                        name_end = fd[i+2].find("(",name_start+2)
                        new_file_name = fd[i+2][:name_start] + "N(" + NEW_FUNC_NAME + ")" + fd[i+2][name_end:]
                        
                        new_fd = ["#include \"common.h\"",
                                  "#include \"map.h\"",
                                  "",
                                  new_file_name,
                                  ]
                        new_fd.extend(FUNC)
                        include_path.write_text("\n".join(new_fd))

                    old_func_name = fd[i].split(",")[2].strip().replace(");", "")
                    RENAMED.append({"name":old_func_name, "area":area_name})

                    fd = fd[:i] + [NEW_INCLUDE] + fd[i+3+len(FUNC)+1:]

                    if fd[-1] != "":
                        fd.append("")

                    entry.write_text("\n".join(fd))
                    break

            i += 1

parse_folder(Path("src/world"))

def do_renames(path):
    for entry in path.iterdir():
        if entry.is_dir():
            do_renames(entry)
            continue

        fd = entry.read_text()
        for rename in RENAMED:
            if rename["name"] in fd:
                fd = fd.replace(rename["name"], f"{rename['area']}_{NEW_FUNC_NAME}")
                entry.write_text(fd)
do_renames(Path("ver/us/asm"))
