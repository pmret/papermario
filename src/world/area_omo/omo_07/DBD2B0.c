#include "omo_07.h"

static char* N(exit_str_0) = "omo_06";
static char* N(exit_str_1) = "";

INCLUDE_ASM(s32, "world/area_omo/omo_07/DBD2B0", func_80240000_DBD2B0);

INCLUDE_ASM(s32, "world/area_omo/omo_07/DBD2B0", func_80240070_DBD320);

INCLUDE_ASM(s32, "world/area_omo/omo_07/DBD2B0", func_80240140_DBD3F0);

#include "world/common/UnkNpcDurationAnimationFunc.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_07/DBD2B0", func_80240238_DBD4E8);

#include "world/common/UnkNpcAIFunc24.inc.c"

#include "world/common/UnkFunc13.inc.c"

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc14.inc.c"

#include "world/common/UnkNpcAIFunc25.inc.c"

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

#if 0 // NON_MATCHING
ApiStatus N(func_80241100_DBE3B0)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);
    f32 posX, posY, posZ, posW;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->patrol.detectShape;
    territory.pointX = enemy->territory->patrol.detect.x;
    territory.pointZ = enemy->territory->patrol.detect.z;
    territory.sizeX = enemy->territory->patrol.detectSizeX;
    territory.sizeZ = enemy->territory->patrol.detectSizeZ;
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || enemy->unk_B0 & 4) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->patrol.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 8;
        }

        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->unk_B0 &= ~4;
        } else if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->functionTemp[0] = 12;
            enemy->flags &= ~ENEMY_FLAGS_40000000;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        posW = 100.0f;

        if (npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW)) {
            npc->pos.y = posY;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
#include "world/common/UnkNpcAIFunc24.inc.c"
        case 1:
            N(func_802406C4_DBD974)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, npcAISettings, territoryPtr);
        case 3:
            N(func_80240A2C_DBDCDC)(script, npcAISettings, territoryPtr);
            break;
        case 4:
#include "world/common/UnkNpcAIFunc25.inc.c"
            break;
        case 10:
            N(NpcJumpFunc2)(script, npcAISettings, territoryPtr);
        case 11:
            N(NpcJumpFunc)(script, npcAISettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc13)(script, npcAISettings, territoryPtr);
        case 13:
            N(func_80240EB8_DBE168)(script, npcAISettings, territoryPtr);
            break;
        case 14:
            N(UnkNpcDurationFlagFunc)(script, npcAISettings, territoryPtr);
            break;
        case 15:
            N(func_80241040_DBE2F0)(script, npcAISettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
    }
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_omo/omo_07/DBD2B0", func_80241100_DBE3B0);
#endif

INCLUDE_ASM(s32, "world/area_omo/omo_07/DBD2B0", func_802413FC_DBE6AC);

INCLUDE_ASM(s32, "world/area_omo/omo_07/DBD2B0", func_8024146C_DBE71C);

INCLUDE_ASM(s32, "world/area_omo/omo_07/DBD2B0", func_8024153C_DBE7EC);

#define NAMESPACE dup_omo_07
#include "world/common/UnkNpcDurationAnimationFunc.inc.c"
#define NAMESPACE omo_07

INCLUDE_ASM(s32, "world/area_omo/omo_07/DBD2B0", func_80241634_DBE8E4);

#include "world/common/UnkNpcAIFunc23.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_07/DBD2B0", func_80241B28_DBEDD8);

#define NAMESPACE dup_omo_07
#include "world/common/UnkNpcAIFunc1.inc.c"
#define NAMESPACE omo_07

#include "world/common/UnkFunc4.inc.c"

#include "world/common/UnkNpcAIFunc2.inc.c"

#if 0 // NON_MATCHING
void N(func_802425CC_DBF87C)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(D_80243A14_DC0CC4)[npc->duration++];
    if (npc->duration >= 5) {
        script->functionTemp[0] = 12;
    }
}
#else
INCLUDE_ASM(s32, "world/area_omo/omo_07/DBD2B0", func_802425CC_DBF87C);
#endif

#include "world/common/UnkNpcAIFunc14.inc.c"

#include "world/common/UnkNpcAIFunc3.inc.c"

#include "world/common/UnkFunc6.inc.c"

#include "world/common/UnkFunc5.inc.c"

#if 0 // NON_MATCHING
ApiStatus N(func_80242C84_DBFF34)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = evt_get_variable(script, *args);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(func_80242B60_DBFE10)(npc, enemy, script, aiSettings);
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
            N(func_80241B28_DBEDD8)(script, aiSettings, territoryPtr);
            break;
        case 2:
            dup_UnkNpcAIFunc1(script, aiSettings, territoryPtr);
        case 3:
            N(func_80242210_DBF4C0)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(func_802425CC_DBF87C)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
            break;
        case 13:
            N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(func_802427D0_DBFA80)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_omo/omo_07/DBD2B0", func_80242C84_DBFF34);
#endif

static char* N(exit_str_2) = "omo_07";

#include "world/common/SetCamera0Flag1000.inc.c"

#include "world/common/UnsetCamera0Flag1000.inc.c"

INCLUDE_ASM(s32, "world/area_omo/omo_07/DBD2B0", func_80242EA8_DC0158);
