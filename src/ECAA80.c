#include "dead.h"
#include "common.h"
#include "dead_structs.h"

// Copy of flo_08 (CAFAC0.c)

#define NAMESPACE ECAA80

extern s32 N(ItemChoiceList)[];
extern s32 N(FlowerGuard_ItemChoiceList)[91];

void func_80241364_ECB064(Evt* script, NpcAISettings* npcAISettings, EnemyTerritoryThing* territory);

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
    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_CHASE];
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
            (basic_ai_try_detect_player(territory, enemy, npcAISettings->alertRadius, npcAISettings->unk_10.f, 0))) {
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
        npc->currentAnim.w = enemy->animList[ENEMY_ANIM_MELEE_PRE];
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
    DeadEnemy* enemy = (DeadEnemy*) script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 100.0f;
    territory.unk_1C = 0;

    enemy->unk_108.x = npc->pos.x;
    enemy->unk_108.y = npc->pos.y;
    enemy->unk_108.z = npc->pos.z;
    enemy->unk_114 = 0.01f;
    enemy->unk_118 = 0.01f;

    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAGS_4)) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[ENEMY_ANIM_IDLE];
        npc->flags &= ~NPC_FLAG_JUMPING;
        if (!enemy->territory->wander.isFlying) {
            npc->flags = (npc->flags | NPC_FLAG_GRAVITY) & ~NPC_FLAG_ENABLE_HIT_SCRIPT;
        } else {
            npc->flags = (npc->flags & ~NPC_FLAG_GRAVITY) | NPC_FLAG_ENABLE_HIT_SCRIPT;
        }
        if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            basic_ai_wander_init(script, npcAISettings, territoryPtr);
        case 1:
            basic_ai_wander(script, npcAISettings, territoryPtr);
            break;
        case 2:
            basic_ai_loiter_init(script, npcAISettings, territoryPtr);
        case 3:
            basic_ai_loiter(script, npcAISettings, territoryPtr);
            break;
        case 10:
            basic_ai_found_player_jump_init(script, npcAISettings, territoryPtr);
        case 11:
            basic_ai_found_player_jump(script, npcAISettings, territoryPtr);
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
            basic_ai_suspend(script);
    }

    return ApiStatus_BLOCK;
}

// following four functions can be folded into this combined include when the last two are done
// #include "world/common/atomic/ItemChoice_PartA.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

// ECAA80_ItemChoice_WaitForSelection (needs data?)
INCLUDE_ASM(s32, "ECAA80", func_8024199C_ECB69C);

// ECAA80_ItemChoice_SaveSelected (needs data?)
INCLUDE_ASM(s32, "ECAA80", func_802419F0_ECB6F0);

#include "world/common/atomic/MakeConsumableChoice.inc.c"

#include "world/common/atomic/ItemChoice_FlowerGuard.inc.c"
