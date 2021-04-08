from pathlib import Path

FUNC="""    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 temp_f0_2;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f2;
    s32 phi_v0;
    f32 phi_f20;
    f32 a = enemy->varTable[3];
    f32 b = enemy->varTable[7];

    npc->jumpVelocity += npc->jumpScale;
    temp_f20 = a / 100.0;
    temp_f22 = b / 100.0;
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    if (npc->jumpVelocity >= 0.0) {
        npc->pos.y += npc->jumpVelocity;
        npc->currentAnim = enemy->animList[9];
        enemy->unk_07 = 0;
        if (!(npc->flags & 8)) {
            posX = npc->pos.x;
            posY = npc->pos.y; 
            posZ = npc->pos.z; 
            posW = 1000.0f;
            phi_v0 = func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW);
        } else {
            phi_v0 = FALSE;
        }
        if (phi_v0) {
            temp_f2 = posY + temp_f20;
            if (temp_f2 <= npc->pos.y) {
                npc->pos.y = temp_f2;
                script->functionTemp[0].s = 0;
            }
        } else if (npc->pos.y >= npc->moveToPos.y) {
            script->functionTemp[0].s = 0;
        }
    } else if (npc->jumpVelocity < 0.0) {
        npc->duration++;
        if (npc->duration >= aiSettings->unk_20) {
            npc->duration = 0;
            phi_f20 = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
            temp_f0_2 = get_clamped_angle_diff(npc->yaw, phi_f20);
            if (aiSettings->unk_1C.s < fabsf(temp_f0_2)) {
                phi_f20 = npc->yaw;
                if (temp_f0_2 < 0.0f) {
                    phi_f20 += -aiSettings->unk_1C.s;
                } else {
                    phi_f20 += aiSettings->unk_1C.s;
                }
            }
            npc->yaw = clamp_angle(phi_f20);
        }

        if (npc->flags & 8) {
            if (npc->pos.y + npc->jumpVelocity < temp_f22) {
                npc->pos.y = temp_f22;
                npc->jumpVelocity = 0.0f;
            } else {
                npc->pos.y += npc->jumpVelocity;
            }
            return;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight; 
        posZ = npc->pos.z; 
        posW = (fabsf(npc->jumpVelocity) + npc->collisionHeight) + 10.0;
        if (func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW)) {
            if (posW <= (npc->collisionHeight + fabsf(npc->jumpVelocity))) {
                npc->jumpVelocity = 0.0f;
                npc->pos.y = posY;
            } else {
                npc->pos.y += npc->jumpVelocity;
            }
            return;
        } else if (fabsf(npc->jumpVelocity) < ((npc->pos.y - temp_f22) + npc->collisionHeight)) {
            npc->pos.y = npc->pos.y + npc->jumpVelocity;
            return;
        }
        npc->jumpVelocity = 0.0f;
    }
}""".splitlines()

#include "world/common/UnkNpcAIFunc1.inc.c"

NEW_FUNC_NAME = f"UnkFunc6"
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
