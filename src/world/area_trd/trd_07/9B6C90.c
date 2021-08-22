#include "trd_07.h"

#include "world/common/set_script_owner_npc_anim.inc.c"

#include "world/common/UnkDistFunc.inc.c"

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

INCLUDE_ASM(s32, "world/area_trd/trd_07/9B6C90", func_802406A4_9B7024);

#include "world/common/UnkNpcAIFunc23.inc.c"

INCLUDE_ASM(s32, "world/area_trd/trd_07/9B6C90", func_80240C94_9B7614);

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_trd/trd_07/9B6C90", func_80241738_9B80B8);
/*
void N(func_80241738_9B80B8)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_80242EAC_9B982C)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}
*/

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_trd/trd_07/9B6C90", func_80241DF0_9B8770);
/*
ApiStatus N(func_80241DF0_9B8770)(Evt* script, s32 isInitialCall) {
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
        N(func_80241CCC_9B864C)(npc, enemy, script, aiSettings);
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
            N(func_80240C94_9B7614)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(func_8024137C_9B7CFC)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80241738_9B80B8)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            break;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(func_8024193C_9B82BC)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_trd/trd_07/9B6C90", func_80241FDC_9B895C);

INCLUDE_ASM(s32, "world/area_trd/trd_07/9B6C90", func_80242104_9B8A84);

INCLUDE_ASM(s32, "world/area_trd/trd_07/9B6C90", func_802421C0_9B8B40);

#include "world/common/UnkDurationCheck.inc.c"

INCLUDE_ASM(s32, "world/area_trd/trd_07/9B6C90", func_8024231C_9B8C9C);

INCLUDE_ASM(s32, "world/area_trd/trd_07/9B6C90", func_8024256C_9B8EEC);

INCLUDE_ASM(s32, "world/area_trd/trd_07/9B6C90", func_80242600_9B8F80);

INCLUDE_ASM(s32, "world/area_trd/trd_07/9B6C90", func_802427FC_9B917C);
