#include "kzn_03.h"

#include "world/common/set_script_owner_npc_anim.inc.c"

#include "world/common/UnkDistFunc.inc.c"

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_802406A4_C613B4);

#include "world/common/AwaitPlayerNearNpc.inc.c"

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80240E00_C61B10);
/*
s32 N(func_80240E00_C61B10)(ScriptInstance *script) {
    PlayerStatus** playerStatus = &gPlayerStatusPtr;
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Camera* camera = &gCameras[gCurrentCamID];
    Enemy* enemy2 = get_enemy(enemy->npcID + 1);
    f32 phi_f20;
    s32 ret = TRUE;

    if (dist2D(npc->pos.x, npc->pos.z, (*playerStatus)->position.x, (*playerStatus)->position.z) > enemy2->varTable[2]) {
        ret = FALSE;
    }

    if (clamp_angle(get_clamped_angle_diff(camera->currentYaw, npc->yaw)) < 180.0) {
        phi_f20 = 90.0f;
    } else {
        phi_f20 = 270.0f;
    }

    if (fabsf(get_clamped_angle_diff(phi_f20, atan2(npc->pos.x, npc->pos.z, (*playerStatus)->position.x, (*playerStatus)->position.z))) > enemy2->varTable[3]) {
        ret = FALSE;
    }

    if ((2.0 * npc->collisionHeight) <= fabsf(npc->pos.y - (*playerStatus)->position.y)) {
        ret = FALSE;
    }

    if (D_8010EBB0.unk_03 == 9) {
        ret = FALSE;
    }

    if (D_8010EBB0.unk_03 == 7) {
        ret = FALSE;
    }

    return ret;
}
*/

#include "world/common/UnkFunc7.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80241214_C61F24);
/*
ApiStatus N(func_80241214_C61F24)(ScriptInstance *script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->wander.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~0x8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 0x8;
        }
        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->unk_B0 &= ~4;
        }
        enemy->varTable[0] = 0;
    }

    if ((script->functionTemp[0] < 30) && (enemy->varTable[0] == 0) && N(func_80240E00_C61B10)(script)) {
        script->functionTemp[0] = 30;
    }

    switch (script->functionTemp[0]) {
        case 0:
            func_800495A0(script, npcAISettings, territoryPtr);
        case 1:
            func_800496B8(script, npcAISettings, territoryPtr);
            break;
        case 2:
            base_UnkNpcAIFunc1(script, npcAISettings, territoryPtr);
        case 3:
            func_80049C04(script, npcAISettings, territoryPtr);
            break;
        case 10:
            func_80049E3C(script, npcAISettings, territoryPtr);
        case 11:
            func_80049ECC(script, npcAISettings, territoryPtr);
            break;
        case 12:
            func_80049F7C(script, npcAISettings, territoryPtr);
        case 13:
            func_8004A124(script, npcAISettings, territoryPtr);
            break;
        case 14:
            func_8004A3E8(script, npcAISettings, territoryPtr);
            break;
        case 30:
            N(UnkNpcAIFunc6)(script);
        case 31:
            N(UnkNpcAIFunc7)(script);
            if (script->functionTemp[0] != 32) {
                break;
            }
        case 32:
            N(UnkNpcAIFunc8)(script);
            if (script->functionTemp[0] != 33) {
                break;
            }
        case 33:
            N(UnkNpcAIFunc5)(script);
            break;
        case 99:
            func_8004A73C(script);
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_802414C8_C621D8);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80241534_C62244);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80241630_C62340);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242070_C62D80);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242100_C62E10);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242200_C62F10);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242260_C62F70);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_8024234C_C6305C);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_8024259C_C632AC);
/*
ApiStatus N(func_8024259C_C632AC)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_802441A0_C64EB0) == NULL) {
        N(D_802441A0_C64EB0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_802441A0_C64EB0)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_802441A0_C64EB0)[i];
        }
        heap_free(N(D_802441A0_C64EB0));
        N(D_802441A0_C64EB0) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_802428E0_C635F0);
/*
ApiStatus N(func_802428E0_C635F0)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80244204_C64F14) = FALSE;
    }

    if (N(D_80244204_C64F14)) {
        N(D_80244204_C64F14) = FALSE;
        set_variable(script, *args, N(D_80244208_C64F18));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242934_C63644);
/*
ApiStatus N(func_80242934_C63644)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80244208_C64F18) = get_variable(script, *args);
    N(D_80244204_C64F14) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_8024296C_C6367C);
/*
ApiStatus N(func_8024296C_C6367C)(ScriptInstance* script, s32 isInitialCall) {
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

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242C84_C63994);
/*
ApiStatus N(func_80242C84_C63994)(ScriptInstance *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242CC8_C639D8);
/*
ApiStatus N(func_80242CC8_C639D8)(ScriptInstance *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
*/
