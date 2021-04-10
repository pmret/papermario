#include "omo_05.h"

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80240000_DB22C0);

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80240070_DB2330);

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80240140_DB2400);

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_802401D8_DB2498);

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80240238_DB24F8);

#include "world/common/UnkNpcAIFunc4.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_802405BC_DB287C);

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80240780_DB2A40);

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80240A54_DB2D14);
/*
void N(func_80240A54_DB2D14)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = aiSettings->moveTime / 2 + rand_int(aiSettings->moveTime / 2 + 1);
    if (is_point_within_region(enemy->territory->wander.wanderShape, 
            enemy->territory->wander.point.x, enemy->territory->wander.point.z, 
            npc->pos.x, npc->pos.z, 
            enemy->territory->wander.wanderSizeX, enemy->territory->wander.wanderSizeZ)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
    } else {
        npc->yaw = clamp_angle((npc->yaw + rand_int(60)) - 30.0f);
    }
    npc->currentAnim = enemy->animList[1];
    script->functionTemp[1].s = 0;
    if (enemy->territory->wander.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
    }
    enemy->varTable[4] = npc->pos.y * 100.0;
    script->functionTemp[0].s = 1;
}
*/

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80240C04_DB2EC4);

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_802416A8_DB3968);
/*
void N(func_802416A8_DB3968)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_802436DC_BE6E8C)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0].s = 12;
    }
}
*/

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80241D60_DB4020);
/*
ApiStatus N(func_80241D60_DB4020)(ScriptInstance* script, s32 isInitialCall) {
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
    territory.unk_34 = 120.0f;
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

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80240A54_DB2D14)(script, aiSettings, territoryPtr);
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

#include "world/common/SomeXYZFuncTodoRename.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80242178_DB4438);
/*
ApiStatus N(func_80242178_DB4438)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr;

    if (isInitialCall) {
        ptr = &D_80241CCC_BE0A5C;
        *ptr = 0;
    }

    ptr = &D_80241CCC_BE0A5C;
    if (*ptr != NULL) {
        ptr = &D_80241CCC_BE0A5C;
        *ptr = 0;
        set_variable(script, *args, D_80241CD0_BE0A60);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_802421CC_DB448C);
/*
ApiStatus N(func_802421CC_DB448C)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80242204_DB44C4);

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_802422A0_DB4560);

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_80242328_DB45E8);

INCLUDE_ASM(s32, "world/area_omo/omo_05/DB22C0", func_802423C8_DB4688);
