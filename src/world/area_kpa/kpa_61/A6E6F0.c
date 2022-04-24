#include "kpa_61.h"

#include "world/common/atomic/enemy/UnkAI_5.inc.c"

#include "world/common/UnkNpcAIFunc47.inc.c"

#include "world/common/UnkFunc57.inc.c"

void func_802411C4_A6F5A4(Evt* script) {
    get_npc_unsafe(script->owner1.enemy->npcID)->duration = 30;
    script->functionTemp[0] = 11;
}

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_80241200_A6F5E0);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_8024138C_A6F76C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_8024177C_A6FB5C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_80241870_A6FC50);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_80241AB4_A6FE94);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_80241AF0_A6FED0);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_80241CBC_A7009C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_80241D28_A70108);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_80241E5C_A7023C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_80241F4C_A7032C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", update_heroes_start_turn_A70404);

#include "world/common/GetEncounterEnemyIsOwner.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_61/A6E6F0", func_802422F0_A706D0);
