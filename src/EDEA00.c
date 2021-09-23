#include "dead.h"
#include "common.h"

#define NAMESPACE EDEA00

extern f32 D_802441DC_EE2B9C[];

INCLUDE_ASM(s32, "EDEA00", func_80240040_EDEA00);

#include "world/common/UnkNpcAIFunc23.inc.c"

INCLUDE_ASM(s32, "EDEA00", func_80240374_EDED34);

#include "world/common/DeadUnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

void func_80240E18_EDF7D8(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += D_802441DC_EE2B9C[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}

#include "world/common/DeadUnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

INCLUDE_ASM(s32, "EDEA00", func_802414D0_EDFE90);

INCLUDE_ASM(s32, "EDEA00", func_802416E8_EE00A8);

INCLUDE_ASM(s32, "EDEA00", func_80241730_EE00F0);

INCLUDE_ASM(s32, "EDEA00", func_80241B94_EE0554);

INCLUDE_ASM(s32, "EDEA00", func_80241DE4_EE07A4);

INCLUDE_ASM(s32, "EDEA00", func_802422F0_EE0CB0);

INCLUDE_ASM(s32, "EDEA00", func_8024236C_EE0D2C);

INCLUDE_ASM(s32, "EDEA00", func_802424A0_EE0E60);

INCLUDE_ASM(s32, "EDEA00", func_80242604_EE0FC4);

INCLUDE_ASM(s32, "EDEA00", func_80242684_EE1044);

INCLUDE_ASM(s32, "EDEA00", func_80242AF0_EE14B0);

INCLUDE_ASM(s32, "EDEA00", pause_interp_text_scroll_EE1DD8);

INCLUDE_ASM(s32, "EDEA00", func_80243470_EE1E30);

INCLUDE_ASM(s32, "EDEA00", func_80243584_EE1F44);
