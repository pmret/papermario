#include "kmr_05.h"

static char* N(exit_str_0) = "kmr_03";
static char* N(exit_str_1) = "kmr_02";

#include "world/common/UnkNpcAIFunc23.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_05/8CE070", func_802401B0_8CE220);

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_05/8CE070", func_80240C54_8CECC4);
/*
void N(func_80240C54_8CECC4)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_80241B2C_8CFB9C)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}
*/

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_kmr/kmr_05/8CE070", func_8024130C_8CF37C);
