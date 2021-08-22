#include "omo_04.h"

static char* N(exit_str_0) = "omo_03";
static char* N(exit_str_1) = "";

INCLUDE_ASM(s32, "world/area_omo/omo_04/DAD400", func_80240000_DAD400);
/*
ApiStatus N(func_80240000_DAD400)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80242630_DAFA30) == NULL) {
        N(D_80242630_DAFA30) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80242630_DAFA30)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80242630_DAFA30)[i];
        }
        heap_free(N(D_80242630_DAFA30));
        N(D_80242630_DAFA30) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

#include "world/common/UnsetCamera0MoveFlag1.inc.c"

#include "world/common/SetCamera0MoveFlag1.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_04/DAD400", func_802402F4_DAD6F4);

#include "world/common/UnkNpcAIFunc23.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_04/DAD400", func_80240550_DAD950);

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_04/DAD400", func_80240FF4_DAE3F4);
/*
void N(func_80240FF4_DAE3F4)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_80242EF0_DB02F0)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}
*/

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_04/DAD400", func_802416AC_DAEAAC);
/*
ApiStatus N(func_802416AC_DAEAAC)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = get_variable(script, *args);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(func_80241588_DAE988)(npc, enemy, script, aiSettings);
    }

    npc->unk_AB = -2;

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }

    switch (script->functionTemp[0]) {
        case 0:
#include "world/common/UnkNpcAIFunc23.inc.c"
        case 1:
            N(func_80240550_DAD950)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(func_80240C38_DAE038)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80240FF4_DAE3F4)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            break;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(func_802411F8_DAE5F8)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_omo/omo_04/DAD400", func_80241898_DAEC98);

INCLUDE_ASM(s32, "world/area_omo/omo_04/DAD400", func_80241908_DAED08);

INCLUDE_ASM(s32, "world/area_omo/omo_04/DAD400", func_802419D8_DAEDD8);

#include "world/common/UnkNpcDurationAnimationFunc.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_04/DAD400", func_80241AD0_DAEED0);

static char* N(exit_str_2) = "omo_04";

#include "world/common/SetCamera0Flag1000.inc.c"

#include "world/common/UnsetCamera0Flag1000.inc.c"
