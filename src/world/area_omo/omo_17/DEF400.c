#include "omo_17.h"

INCLUDE_ASM(s32, "world/area_omo/omo_17/DEF400", func_80240560_DEF400);

INCLUDE_ASM(s32, "world/area_omo/omo_17/DEF400", func_802405D0_DEF470);

INCLUDE_ASM(s32, "world/area_omo/omo_17/DEF400", func_802406A0_DEF540);

INCLUDE_ASM(s32, "world/area_omo/omo_17/DEF400", func_80240738_DEF5D8);

INCLUDE_ASM(s32, "world/area_omo/omo_17/DEF400", func_80240798_DEF638);

#include "world/common/UnkNpcAIFunc4.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_17/DEF400", func_80240B1C_DEF9BC);

INCLUDE_ASM(s32, "world/area_omo/omo_17/DEF400", func_80240CE0_DEFB80);

INCLUDE_ASM(s32, "world/area_omo/omo_17/DEF400", func_80240FB4_DEFE54);
/*
void N(func_80240FB4_DEFE54)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

INCLUDE_ASM(s32, "world/area_omo/omo_17/DEF400", func_80241164_DF0004);

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_17/DEF400", func_80241C08_DF0AA8);
/*
void N(func_80241C08_DF0AA8)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

INCLUDE_ASM(s32, "world/area_omo/omo_17/DEF400", func_802422C0_DF1160);
/*
ApiStatus N(func_802422C0_DF1160)(ScriptInstance* script, s32 isInitialCall) {
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
        N(func_8024219C_DF103C)(npc, enemy, script, aiSettings);
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
            N(func_80240FB4_DEFE54)(script, aiSettings, territoryPtr);
        case 1:
            N(func_80241164_DF0004)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        case 3:
            N(func_8024184C_DF06EC)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_80241C08_DF0AA8)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            break;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(func_80241E0C_DF0CAC)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_omo/omo_17/DEF400", func_802424AC_DF134C);

INCLUDE_ASM(s32, "world/area_omo/omo_17/DEF400", func_8024269C_DF153C);

INCLUDE_ASM(s32, "world/area_omo/omo_17/DEF400", func_802427E0_DF1680);

#include "world/common/UnkSetDurationFunc.inc.c"

#include "world/common/UnkNpcAIFunc9.inc.c"

#include "world/common/UnkDurationCheck.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_17/DEF400", func_80242A08_DF18A8);

INCLUDE_ASM(s32, "world/area_omo/omo_17/DEF400", func_80242F44_DF1DE4);

INCLUDE_ASM(s32, "world/area_omo/omo_17/DEF400", func_802433A0_DF2240);

INCLUDE_ASM(s32, "world/area_omo/omo_17/DEF400", func_802436C0_DF2560);

#include "world/common/GetEncounterEnemyIsOwner.inc.c"
