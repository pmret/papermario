#include "omo_01.h"

static char* N(exit_str_0) = "omo_13";

INCLUDE_ASM(s32, "world/area_omo/omo_01/D9B150", func_80240260_D9B150);
/*
void N(func_80240260_D9B150)(Evt *script, NpcAISettings *npcAISettings, EnemyTerritoryThing *territory) {
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
    npc->currentAnim = enemy->animList[3];
    npc->moveSpeed = npcAISettings->chaseSpeed;
    phi_s3 = FALSE;

    temp_f20 = clamp_angle(atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z) + 180.0f);
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

    temp_f20 = clamp_angle(atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z) + 180.0f);
    phi_f22 = 0.0f;
    phi_f24 = 0.0f;
    phi_f26 = 0.0f;

    if (npc_test_move_simple_without_slipping(npc->unk_80, &subroutine_arg8, &subroutine_arg9, &subroutine_argA, npc->moveSpeed * 4.5, temp_f20, npc->collisionHeight, npc->collisionRadius) != 0) {
        phi_f22 = dist2D(npc->pos.x, npc->pos.z, subroutine_arg8, subroutine_argA);

        subroutine_argB = npc->pos.x;
        subroutine_argC = npc->pos.y;
        subroutine_argD = npc->pos.z;

        if (npc_test_move_simple_without_slipping(npc->unk_80, &subroutine_argB, &subroutine_argC, &subroutine_argD, npc->moveSpeed * 4.5, clamp_angle(temp_f20 + 35.0f), npc->collisionHeight, npc->collisionRadius) != 0) {
            phi_f24 = dist2D(npc->pos.x, npc->pos.z, subroutine_argB, subroutine_argD);
        }

        subroutine_argE = npc->pos.x;
        subroutine_argF = npc->pos.y;
        subroutine_arg10 = npc->pos.z;

        if (npc_test_move_simple_without_slipping(npc->unk_80, &subroutine_argE, &subroutine_argF, &subroutine_arg10, npc->moveSpeed * 4.5, clamp_angle(temp_f20 - 35.0f), npc->collisionHeight, npc->collisionRadius) != 0) {
            phi_f26 = dist2D(npc->pos.x, npc->pos.z, subroutine_argE, subroutine_arg10);
        }

        dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);

        if ((phi_f22 < npc->moveSpeed * 1.5) && (phi_f24 < npc->moveSpeed * 1.5) && (phi_f26 < npc->moveSpeed * 1.5) &&
            (func_800490B4(territory, enemy, npcAISettings->alertRadius, npcAISettings->unk_10.f, 0) != 0)) {
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
        npc->currentAnim = enemy->animList[8];
    }
    script->functionTemp[0] = 0xD;
}
*/

INCLUDE_ASM(s32, "world/area_omo/omo_01/D9B150", func_80240844_D9B734);
/*
void N(func_80240844_D9B734)(Evt *script, NpcAISettings *npcAISettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if (func_800490B4(territory, enemy, npcAISettings->chaseRadius, npcAISettings->unk_28.f, 1) == 0) {
        fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &var);
        npc->currentAnim = enemy->animList[0];
        npc->duration = 25;
        script->functionTemp[0] = 14;
    } else {
        if (npc->currentAnim != enemy->animList[8]) {
            if (npc->moveSpeed < 4.0) {
                func_8003D660(npc, 0);
            } else {
                func_8003D660(npc, 1);
            }
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        }
        if (npc->duration > 0) {
            npc->duration--;
            return;
        } else {
            script->functionTemp[0] = 12;
        }
    }
}
*/

INCLUDE_ASM(s32, "world/area_omo/omo_01/D9B150", func_802409A8_D9B898);
/*
void N(func_802409A8_D9B898)(Evt *script, NpcAISettings *npcAISettings, EnemyTerritoryThing *territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc *npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        script->functionTemp[0] = NULL;
    }
}
*/

INCLUDE_ASM(s32, "world/area_omo/omo_01/D9B150", func_802409EC_D9B8DC);
