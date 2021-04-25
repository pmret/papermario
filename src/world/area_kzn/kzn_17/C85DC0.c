#include "kzn_17.h"

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80240518_C85FC8);
/*
s32 N(func_80240518_C85FC8)(ScriptInstance *script) {
    PlayerStatus** playerStatus = &gPlayerStatusPtr;
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Camera* camera = CAM(gCurrentCamID);
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

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_8024092C_C863DC);
/*
ApiStatus N(func_8024092C_C863DC)(ScriptInstance *script, s32 isInitialCall) {
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
    territory.unk_34 = 65.0f;
    territory.unk_1C = 0;

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0].s = 0;
        npc->duration = 0;
        npc->currentAnim = enemy->animList[0];
        npc->flags &= ~0x800;
        if (!enemy->territory->wander.isFlying) {
            npc->flags = (npc->flags | 0x200) & ~0x8;
        } else {
            npc->flags = (npc->flags & ~0x200) | 0x8;
        }
        if (enemy->unk_B0 & 4) {
            script->functionTemp[0].s = 99;
            script->functionTemp[1].s = 0;
            enemy->unk_B0 &= ~4;
        }
        enemy->varTable[0] = 0;
    }

    if ((script->functionTemp[0].s < 30) && (enemy->varTable[0] == 0) && N(func_80240518_C85FC8)(script)) {
        script->functionTemp[0].s = 30;
    }

    switch (script->functionTemp[0].s) {
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
            if (script->functionTemp[0].s != 32) {
                break;
            }
        case 32:
            N(UnkNpcAIFunc8)(script);
            if (script->functionTemp[0].s != 33) {
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

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80240BE0_C86690);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80240C4C_C866FC);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80240D48_C867F8);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80241788_C87238);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80241818_C872C8);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80241918_C873C8);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80241978_C87428);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80241A64_C87514);

#include "world/common/set_script_owner_npc_anim.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80241D30_C877E0);

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80242048_C87AF8);

#include "world/common/AwaitPlayerNearNpc.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_8024259C_C8804C);
/*
ApiStatus N(func_8024259C_C8804C)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80244074_C89B24) == NULL) {
        N(D_80244074_C89B24) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80244074_C89B24)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80244074_C89B24)[i];
        }
        heap_free(N(D_80244074_C89B24));
        N(D_80244074_C89B24) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_802428E0_C88390);
/*
ApiStatus N(func_802428E0_C88390)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_802440D8_C89B88) = FALSE;
    }

    if (N(D_802440D8_C89B88)) {
        N(D_802440D8_C89B88) = FALSE;
        set_variable(script, *args, N(D_802440DC_C89B8C));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80242934_C883E4);
/*
ApiStatus N(func_80242934_C883E4)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_802440DC_C89B8C) = get_variable(script, *args);
    N(D_802440D8_C89B88) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_8024296C_C8841C);
/*
ApiStatus N(func_8024296C_C8841C)(ScriptInstance* script, s32 isInitialCall) {
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
            N(D_80244A20)[0x70] = 0;
        }
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80242C84_C88734);
/*
ApiStatus N(func_80242C84_C88734)(ScriptInstance *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80242CC8_C88778);
/*
ApiStatus N(func_80242CC8_C88778)(ScriptInstance *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
*/
