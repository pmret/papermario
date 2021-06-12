#include "mac_00.h"

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80242570_7ED280);
/*
ApiStatus N(func_80242570_7ED280)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80242BEC_7ED8FC);
/*
ApiStatus N(func_80242BEC_7ED8FC)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
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

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80243104_7EDE14);
/*
ApiStatus N(func_80243104_7EDE14)(ScriptInstance* script, s32 isInitialCall) {
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

        if (func_800DCB7C(npc->unk_80, &posX, &posY, &posZ, &posW)) {
            npc->pos.y = posY;
        }
    }

    switch (script->functionTemp[0].s) {
        case 0:
            N(func_80242570_7ED280)(script, npcAISettings, territoryPtr);
        case 1:
            N(func_802426C8_7ED3D8)(script, npcAISettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, npcAISettings, territoryPtr);
        case 3:
            N(func_80242A30_7ED740)(script, npcAISettings, territoryPtr);
            break;
        case 4:
            N(func_80242BEC_7ED8FC)(script, npcAISettings, territoryPtr);
            break;
        case 10:
            N(NpcJumpFunc2)(script, npcAISettings, territoryPtr);
        case 11:
            N(NpcJumpFunc)(script, npcAISettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc13)(script, npcAISettings, territoryPtr);
        case 13:
            N(func_80242EBC_7EDBCC)(script, npcAISettings, territoryPtr);
            break;
        case 14:
            N(UnkNpcDurationFlagFunc)(script, npcAISettings, territoryPtr);
            break;
        case 15:
            N(func_80243044_7EDD54)(script, npcAISettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
    }
    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80243400_7EE110);
/*
ApiStatus N(func_80243400_7EE110)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_8024ECE8_7F99F8) == NULL) {
        N(D_8024ECE8_7F99F8) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_8024ECE8_7F99F8)[i] = script->varTable[i].s;
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i].s = N(D_8024ECE8_7F99F8)[i];
        }
        heap_free(N(D_8024ECE8_7F99F8));
        N(D_8024ECE8_7F99F8) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#define NAMESPACE dup_mac_00
#include "world/common/GetItemName.inc.c"
#define NAMESPACE mac_00

#define NAMESPACE dup_mac_00
#include "world/common/GetNpcCollisionHeight.inc.c"
#define NAMESPACE mac_00

#define NAMESPACE dup_mac_00
#include "world/common/AddPlayerHandsOffset.inc.c"
#define NAMESPACE mac_00

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80243744_7EE454);
/*
ApiStatus N(func_80243744_7EE454)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_8024ED4C_7F9A5C) = FALSE;
    }

    if (N(D_8024ED4C_7F9A5C)) {
        N(D_8024ED4C_7F9A5C) = FALSE;
        set_variable(script, *args, N(D_8024ED50_7F9A60));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80243798_7EE4A8);
/*
ApiStatus N(func_80243798_7EE4A8)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_8024ED50_7F9A60) = get_variable(script, *args);
    N(D_8024ED4C_7F9A5C) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_802437D0_7EE4E0);
/*
ApiStatus N(func_802437D0_7EE4E0)(ScriptInstance* script, s32 isInitialCall) {
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

#define NAMESPACE dup_mac_00
#include "world/common/SetManyVars.inc.c"
#define NAMESPACE mac_00

#define NAMESPACE dup_mac_00
#include "world/common/UnkYawFunc.inc.c"
#define NAMESPACE mac_00

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80243AE8_7EE7F8);
/*
ApiStatus N(func_80243AE8_7EE7F8)(ScriptInstance *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2].s);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4].s;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_mac/mac_00/7ED280", func_80243B2C_7EE83C);
/*
ApiStatus N(func_80243B2C_7EE83C)(ScriptInstance *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2].s)->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
*/
