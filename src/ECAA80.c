#include "dead.h"
#include "common.h"
#include "dead_structs.h"

// Copy of flo_08 (CAFAC0.c)

#define NAMESPACE ECAA80

extern s32 D_802462F0[];
extern s32 D_80246460_EC9D00[91];
extern s32 D_802465CC;

void func_80240D80_ECAA80(Evt* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    f32 temp_f0;
    f32 temp_f20;
    f64 temp_f2;
    f32 phi_f22;
    f32 phi_f24;
    f32 phi_f26;
    s32 phi_s3;

    f32 subroutine_arg8;
    f32 subroutine_arg9;
    f32 subroutine_argA;
    f32 subroutine_argB;
    f32 subroutine_argC;
    f32 subroutine_argD;
    f32 subroutine_argE;
    f32 subroutine_argF;
    f32 subroutine_arg10;

    npc->duration = npcAISettings->unk_20 / 2 + rand_int(npcAISettings->unk_20 / 2 + 1);
    npc->currentAnim.w = enemy->animList[3];
    npc->moveSpeed = npcAISettings->chaseSpeed;
    phi_s3 = FALSE;

    temp_f20 = clamp_angle(atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x,
                                 gPlayerStatusPtr->position.z) + 180.0f);
    temp_f0 = get_clamped_angle_diff(npc->yaw, temp_f20);
    if (npcAISettings->unk_1C.s < fabsf(temp_f0)) {
        temp_f20 = npc->yaw;
        if (temp_f0 < 0.0f) {
            temp_f20 += -npcAISettings->unk_1C.s;
        } else {
            temp_f20 += npcAISettings->unk_1C.s;
        }
    }

    npc->yaw = clamp_angle(temp_f20);

    subroutine_arg8 = npc->pos.x;
    subroutine_arg9 = npc->pos.y;
    subroutine_argA = npc->pos.z;

    temp_f20 = clamp_angle(atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x,
                                 gPlayerStatusPtr->position.z) + 180.0f);
    phi_f22 = 0.0f;
    phi_f24 = 0.0f;
    phi_f26 = 0.0f;

    if (npc_test_move_simple_without_slipping(npc->collisionChannel, &subroutine_arg8, &subroutine_arg9, &subroutine_argA, npc->moveSpeed * 4.5, temp_f20,
                      npc->collisionHeight, npc->collisionRadius)) {
        phi_f22 = dist2D(npc->pos.x, npc->pos.z, subroutine_arg8, subroutine_argA);

        subroutine_argB = npc->pos.x;
        subroutine_argC = npc->pos.y;
        subroutine_argD = npc->pos.z;

        if (npc_test_move_simple_without_slipping(npc->collisionChannel, &subroutine_argB, &subroutine_argC, &subroutine_argD, npc->moveSpeed * 4.5,
                          clamp_angle(temp_f20 + 35.0f), npc->collisionHeight, npc->collisionRadius)) {
            phi_f24 = dist2D(npc->pos.x, npc->pos.z, subroutine_argB, subroutine_argD);
        }

        subroutine_argE = npc->pos.x;
        subroutine_argF = npc->pos.y;
        subroutine_arg10 = npc->pos.z;

        if (npc_test_move_simple_without_slipping(npc->collisionChannel, &subroutine_argE, &subroutine_argF, &subroutine_arg10, npc->moveSpeed * 4.5,
                          clamp_angle(temp_f20 - 35.0f), npc->collisionHeight, npc->collisionRadius)) {
            phi_f26 = dist2D(npc->pos.x, npc->pos.z, subroutine_argE, subroutine_arg10);
        }

        dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);

        if ((phi_f22 < npc->moveSpeed * 1.5) && (phi_f24 < npc->moveSpeed * 1.5) && (phi_f26 < npc->moveSpeed * 1.5) &&
            (func_800490B4(territory, enemy, npcAISettings->alertRadius, npcAISettings->unk_10.f, 0))) {
            phi_s3 = TRUE;
        }

        if (!phi_s3) {
            if ((phi_f24 < phi_f22) && (phi_f26 < phi_f24)) {
                temp_f20 = atan2(npc->pos.x, npc->pos.z, subroutine_arg8, subroutine_argA);
            } else if ((phi_f24 < phi_f22) && (phi_f24 < phi_f26)) {
                temp_f20 = atan2(npc->pos.x, npc->pos.z, subroutine_arg8, subroutine_argA);
            } else if ((phi_f22 < phi_f24) && (phi_f26 < phi_f22)) {
                temp_f20 = atan2(npc->pos.x, npc->pos.z, subroutine_argB, subroutine_argD);
            } else if ((phi_f26 < phi_f24) && (phi_f22 < phi_f26)) {
                temp_f20 = atan2(npc->pos.x, npc->pos.z, subroutine_argB, subroutine_argD);
            } else if ((phi_f22 < phi_f26) && (phi_f24 < phi_f22)) {
                temp_f20 = atan2(npc->pos.x, npc->pos.z, subroutine_argE, subroutine_arg10);
            } else if ((phi_f24 < phi_f26) && (phi_f22 < phi_f24)) {
                temp_f20 = atan2(npc->pos.x, npc->pos.z, subroutine_argE, subroutine_arg10);
            }

            temp_f0 = get_clamped_angle_diff(npc->yaw, temp_f20);
            if (npcAISettings->unk_1C.s < fabsf(temp_f0)) {
                temp_f20 = npc->yaw;
                if (temp_f0 < 0.0f) {
                    temp_f20 += -npcAISettings->unk_1C.s;
                } else {
                    temp_f20 += npcAISettings->unk_1C.s;
                }
            }
            npc->yaw = clamp_angle(temp_f20);
        }
    }
    if (phi_s3) {
        npc->duration = 0xA;
        npc->currentAnim.w = enemy->animList[8];
    }
    script->functionTemp[0] = 0xD;
}

INCLUDE_ASM(s32, "ECAA80", func_80241364_ECB064);

void func_802414C8_ECB1C8(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        script->functionTemp[0] = 0;
    }
}

ApiStatus func_8024150C_ECB20C(Evt* script, s32 isInitialCall) {
    DeadEnemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 100.0f;
    territory.unk_1C = 0;

    enemy->unk_108.x = npc->pos.x;
    enemy->unk_108.y = npc->pos.y;
    enemy->unk_108.z = npc->pos.z;
    enemy->unk_114 = 0.01f;
    enemy->unk_118 = 0.01f;

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
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
            func_80240D80_ECAA80(script, npcAISettings, territoryPtr);
        case 13:
            func_80241364_ECB064(script, npcAISettings, territoryPtr);
            break;
        case 14:
            func_802414C8_ECB1C8(script, npcAISettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
    }

    return ApiStatus_BLOCK;
}

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "ECAA80", func_8024199C_ECB69C);

INCLUDE_ASM(s32, "ECAA80", func_802419F0_ECB6F0);

ApiStatus func_80241A28_ECB728(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_802462F0[i] = ptr[i];
        }
        D_802462F0[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            D_802462F0[i] = i + 128;
            D_802462F0[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

ApiStatus func_80241AC4_ECB7C4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemIdx = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    ItemEntity* item = get_item_entity(itemIdx);

    item->position.x = var1;
    item->position.y = var2;
    item->position.z = var3;

    return ApiStatus_DONE2;
}

ApiStatus func_80241B88_ECB888(Evt* script, s32 isInitialCall) {
    s32 itemId = evt_get_variable(script, *script->ptrReadPos);
    StaticItem* item = &gItemTable[itemId];

    if (itemId == ITEM_YUMMY_MEAL) {
        script->varTable[9] = 2;
    } else if (item->typeFlags & 0x80) {
        script->varTable[9] = 1;
    } else {
        script->varTable[9] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80241BF8_ECB8F8(Evt* script, s32 isInitialCall) {
    s32 i;

    for (i = 0; i <= 90; i++) {
        D_80246460_EC9D00[i] = 128 + i;
    }

    D_802465CC = 0;
    return ApiStatus_DONE2;
}
