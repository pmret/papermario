#include "dead.h"
#include "common.h"

// Copy of flo_16 (CD2C80.c)

#define NAMESPACE EEDF50

extern f32 D_80244070_EF1170[];

#include "world/common/UnkNpcAIFunc23.inc.c"

INCLUDE_ASM(s32, "EEDF50", func_80241000_EEE100);

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

void func_80241AA4_EEEBA4(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += D_80244070_EF1170[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

INCLUDE_ASM(s32, "EEDF50", func_8024215C_EEF25C);

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkNpcAIFunc34.inc.c"

#include "world/common/UnkFunc45.inc.c"

INCLUDE_ASM(s32, "EEDF50", func_80242780_EEF880);
