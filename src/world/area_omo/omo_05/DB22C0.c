#include "omo_05.h"

static char* N(exit_str_0) = "omo_17";
static char* N(exit_str_1) = "";

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80240000_DB22C0);

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80240070_DB2330);

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80240140_DB2400);

#include "world/common/UnkNpcDurationAnimationFunc.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80240238_DB24F8);

#include "world/common/UnkNpcAIFunc4.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_802405BC_DB287C);

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80240780_DB2A40);

#include "world/common/UnkNpcAIFunc23.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80240C04_DB2EC4);

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_802416A8_DB3968);
/*
void N(func_802416A8_DB3968)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_80242F88_DB5248)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}
*/

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80241D60_DB4020);
/*
ApiStatus N(func_80241D60_DB4020)(Evt* script, s32 isInitialCall) {
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
        N(func_80241C3C_DB3EFC)(npc, enemy, script, aiSettings);
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
            N(func_80240C04_DB2EC4)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(func_802412EC_DB35AC)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_802416A8_DB3968)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            break;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(func_802418AC_DB3B6C)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}
*/

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80242178_DB4438);
/*
ApiStatus N(func_80242178_DB4438)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80243098_DB5358) = FALSE;
    }

    if (N(D_80243098_DB5358)) {
        N(D_80243098_DB5358) = FALSE;
        set_variable(script, *args, N(D_8024309C_DB535C));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_802421CC_DB448C);
/*
ApiStatus N(func_802421CC_DB448C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_8024309C_DB535C) = get_variable(script, *args);
    N(D_80243098_DB5358) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80242204_DB44C4);
/*
ApiStatus N(func_80242204_DB44C4)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_80244A20)[i] = ptr[i];
        }
        N(D_80244A20)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(D_80244A20)[i] = i + 16;
            N(D_80244A20)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_802422A0_DB4560);

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80242328_DB45E8);

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_802423C8_DB4688);
/*
ApiStatus N(func_802423C8_DB4688)(Evt *script, s32 isInitialCall) {
    s32 i;

    for (i = 0; i <= 90; i++) {
        N(D_802457C0)[i] = 128 + i;
    }

    N(D_8024592C) = 0;
    return ApiStatus_DONE2;
}
*/
