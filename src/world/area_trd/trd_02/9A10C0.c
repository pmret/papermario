#include "trd_02.h"

#include "world/common/set_script_owner_npc_anim.inc.c"

INCLUDE_ASM(s32, "world/area_trd/trd_02/9A10C0", func_8024015C_9A113C);
/*
void N(func_8024015C_9A113C)(ScriptInstance *script, NpcAISettings *aiSettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if ((npc->duration <= 0) || (--npc->duration <= 0)) {
        if (npc->turnAroundYawAdjustment == 0) {
            npc->currentAnim = enemy->animList[9];
            npc->moveSpeed = aiSettings->chaseSpeed;
            if ((enemy->varTable[7] == 5) || (enemy->varTable[7] == 0) || (enemy->varTable[7] == 1)) {
                npc->collisionHeight = enemy->varTable[6] / 2;
            }
            npc->duration = (dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z) / npc->moveSpeed) + 0.8;
            if (npc->duration < enemy->varTable[3]) {
                npc->duration = enemy->varTable[3];
            }
            enemy->varTable[4] = npc->duration;
            script->functionTemp[0].s = 14;
        }
    }
}
*/

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

INCLUDE_ASM(s32, "world/area_trd/trd_02/9A10C0", func_80240474_9A1454);

INCLUDE_ASM(s32, "world/area_trd/trd_02/9A10C0", func_802408B4_9A1894);
/*
ApiStatus N(func_802408B4_9A1894)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    f32 ret;
    f32 max;
    f32 posX;
    f32 posZ;
    s32 i;
    s32 j;

    script->functionTemp[1].s = 0;
    max = 32767.0f;
    posX = npc->pos.x;
    posZ = npc->pos.z;
    script->functionTemp[2].s = 0;

    for (i = 0, j = 0; i < enemy->territory->patrol.numPoints; i++, j++) {
        ret = dist2D(posX, posZ, i[enemy->territory->patrol.points].x, i[enemy->territory->patrol.points].z);
        if (ret < max) {
            max = ret;
            script->functionTemp[2].s = j;
        }
    }

    npc->currentAnim = enemy->animList[1];
    if (enemy->territory->patrol.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->patrol.moveSpeedOverride / 32767.0;
    }

    script->functionTemp[0].s = 1;
    return ApiStatus_DONE1;
}
*/

#include "world/common/UnkFunc13.inc.c"

#include "world/common/UnkNpcAIFunc1.inc.c"

#include "world/common/UnkFunc14.inc.c"

INCLUDE_ASM(s32, "world/area_trd/trd_02/9A10C0", func_80240F30_9A1F10);
/*
ApiStatus N(func_80240F30_9A1F10)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    script->functionTemp[2].s++;
    if (script->functionTemp[2].s >= enemy->territory->patrol.numPoints) {
        script->functionTemp[2].s = 0;
    }
    npc->currentAnim = enemy->animList[1];
    if (enemy->territory->patrol.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->patrol.moveSpeedOverride / 32767.0;
    }
    script->functionTemp[0].s = 1;
    return ApiStatus_DONE1;
}
*/

#include "world/common/NpcJumpFunc2.inc.c"

#include "world/common/NpcJumpFunc.inc.c"

#include "world/common/UnkNpcAIFunc13.inc.c"

#include "world/common/UnkFunc15.inc.c"

#include "world/common/UnkNpcDurationFlagFunc.inc.c"

#include "world/common/UnkFunc16.inc.c"

INCLUDE_ASM(s32, "world/area_trd/trd_02/9A10C0", func_80241448_9A2428);
/*
ApiStatus N(func_80241448_9A2428)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)get_variable(script, *args++);
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
        script->functionTemp[0].s = 0;
        npc->duration = 0;
        npc->currentAnim = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->patrol.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 8;
        }

        if (enemy->unk_B0 & 4) {
            script->functionTemp[0].s = 99;
            script->functionTemp[1].s = 0;
            enemy->unk_B0 &= ~4;
        } else if (enemy->flags & 0x40000000) {
            script->functionTemp[0].s = 12;
            enemy->flags &= ~0x40000000;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        posW = 100.0f;

        if (npc_raycast_down_sides(npc->unk_80, &posX, &posY, &posZ, &posW)) {
            npc->pos.y = posY;
        }
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_802408B4_9A1894)(script, npcAISettings, territoryPtr);
        case 1:
            N(func_80240A0C_9A19EC)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, npcAISettings, territoryPtr);
        case 3:
            N(func_80240D74_9A1D54)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(func_80240F30_9A1F10)(script, npcAISettings, territoryPtr);
            break;
        case 10:
            N(NpcJumpFunc2)(script, npcAISettings, territoryPtr);
        case 11:
            N(NpcJumpFunc)(script, npcAISettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc13)(script, npcAISettings, territoryPtr);
        case 13:
            N(func_80241200_9A21E0)(script, npcAISettings, territoryPtr);
            break;
        case 14:
            N(UnkNpcDurationFlagFunc)(script, npcAISettings, territoryPtr);
            break;
        case 15:
            N(func_80241388_9A2368)(script, npcAISettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
    }
    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_trd/trd_02/9A10C0", func_80241744_9A2724);
