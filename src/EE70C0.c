#include "dead.h"
#include "common.h"

#define NAMESPACE EE70C0

extern f32 D_802444F0_EEAAA0[];

INCLUDE_ASM(s32, "EE70C0", func_80240B10_EE70C0);

INCLUDE_ASM(s32, "EE70C0", func_80240CC0_EE7270);

#include "world/common/DeadUnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

void func_80241764_EE7D14(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += D_802444F0_EEAAA0[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}

#include "world/common/DeadUnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

INCLUDE_ASM(s32, "EE70C0", func_80241E1C_EE83CC);

INCLUDE_ASM(s32, "EE70C0", func_80242034_EE85E4);

INCLUDE_ASM(s32, "EE70C0", func_80242090_EE8640);

INCLUDE_ASM(s32, "EE70C0", func_80242260_EE8810);

INCLUDE_ASM(s32, "EE70C0", func_802422B4_EE8864);

INCLUDE_ASM(s32, "EE70C0", func_802422EC_EE889C);
