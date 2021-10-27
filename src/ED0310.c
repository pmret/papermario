#include "dead.h"
#include "common.h"

// Copy of flo_09 (CB5320.c)

#define NAMESPACE ED0310

extern f32 D_8024365C_ED364C[];

#include "world/common/UnkNpcAIFunc23.inc.c"

INCLUDE_ASM(s32, "ED0310", func_802404D0_ED04C0);

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

void func_80240F74_ED0F64(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += D_8024365C_ED364C[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

INCLUDE_ASM(s32, "ED0310", func_8024162C_ED161C);
