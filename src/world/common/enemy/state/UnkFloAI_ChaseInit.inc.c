#include "common.h"
#include "npc.h"

void N(UnkFloAI_ChaseInit)(Evt* script, NpcAISettings* npcAISettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    f32 deltaYaw;
    f32 yawFwd;
    f32 distFwd;
    f32 distCW;
    f32 distCCW;
    f32 distToPlayer;
    s32 detectedPlayer;

    f32 posXFwd;
    f32 posYFwd;
    f32 posZFwd;
    f32 posXCW;
    f32 posYCW;
    f32 posZCW;
    f32 posXCCW;
    f32 posYCCW;
    f32 posZCCW;
    
    npc->duration = npcAISettings->unk_AI_20 / 2 + rand_int(npcAISettings->unk_AI_20 / 2 + 1);
    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_CHASE];
    npc->moveSpeed = npcAISettings->chaseSpeed;
    detectedPlayer = FALSE;

    yawFwd = clamp_angle(atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x,
                                 gPlayerStatusPtr->position.z) + 180.0f);
    deltaYaw = get_clamped_angle_diff(npc->yaw, yawFwd);
    if (npcAISettings->unk_AI_1C.s < fabsf(deltaYaw)) {
        yawFwd = npc->yaw;
        if (deltaYaw < 0.0f) {
            yawFwd += -npcAISettings->unk_AI_1C.s;
        } else {
            yawFwd += npcAISettings->unk_AI_1C.s;
        }
    }

    npc->yaw = clamp_angle(yawFwd);

    posXFwd = npc->pos.x;
    posYFwd = npc->pos.y;
    posZFwd = npc->pos.z;

    yawFwd = clamp_angle(atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z) + 180.0f);
    distFwd = 0.0f;
    distCW = 0.0f;
    distCCW = 0.0f;

    if (npc_test_move_simple_without_slipping(npc->collisionChannel,
            &posXFwd, &posYFwd, &posZFwd, npc->moveSpeed * 4.5,
            yawFwd, npc->collisionHeight, npc->collisionRadius)) {
        distFwd = dist2D(npc->pos.x, npc->pos.z, posXFwd, posZFwd);

        // check 'whisker' 35 degrees CW
        posXCW = npc->pos.x;
        posYCW = npc->pos.y;
        posZCW = npc->pos.z;
        if (npc_test_move_simple_without_slipping(npc->collisionChannel,
                &posXCW, &posYCW, &posZCW, npc->moveSpeed * 4.5,
                clamp_angle(yawFwd + 35.0f), npc->collisionHeight, npc->collisionRadius)) {
            distCW = dist2D(npc->pos.x, npc->pos.z, posXCW, posZCW);
        }

        // check 'whisker' 35 degrees CCW
        posXCCW = npc->pos.x;
        posYCCW = npc->pos.y;
        posZCCW = npc->pos.z;
        if (npc_test_move_simple_without_slipping(npc->collisionChannel,
                &posXCCW, &posYCCW, &posZCCW, npc->moveSpeed * 4.5,
                clamp_angle(yawFwd - 35.0f), npc->collisionHeight, npc->collisionRadius)) {
            distCCW = dist2D(npc->pos.x, npc->pos.z, posXCCW, posZCCW);
        }

        // unused
        distToPlayer = dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);

        if ((distFwd < npc->moveSpeed * 1.5) && (distCW < npc->moveSpeed * 1.5) && (distCCW < npc->moveSpeed * 1.5) &&
            (basic_ai_check_player_dist(territory, enemy, npcAISettings->alertRadius, npcAISettings->unk_AI_10.f, 0))) {
            detectedPlayer = TRUE;
        }

        if (!detectedPlayer) {
            if ((distCW < distFwd) && (distCCW < distCW)) {
                yawFwd = atan2(npc->pos.x, npc->pos.z, posXFwd, posZFwd);
            } else if ((distCW < distFwd) && (distCW < distCCW)) {
                yawFwd = atan2(npc->pos.x, npc->pos.z, posXFwd, posZFwd);
            } else if ((distFwd < distCW) && (distCCW < distFwd)) {
                yawFwd = atan2(npc->pos.x, npc->pos.z, posXCW, posZCW);
            } else if ((distCCW < distCW) && (distFwd < distCCW)) {
                yawFwd = atan2(npc->pos.x, npc->pos.z, posXCW, posZCW);
            } else if ((distFwd < distCCW) && (distCW < distFwd)) {
                yawFwd = atan2(npc->pos.x, npc->pos.z, posXCCW, posZCCW);
            } else if ((distCW < distCCW) && (distFwd < distCW)) {
                yawFwd = atan2(npc->pos.x, npc->pos.z, posXCCW, posZCCW);
            }

            deltaYaw = get_clamped_angle_diff(npc->yaw, yawFwd);
            if (npcAISettings->unk_AI_1C.s < fabsf(deltaYaw)) {
                yawFwd = npc->yaw;
                if (deltaYaw < 0.0f) {
                    yawFwd += -npcAISettings->unk_AI_1C.s;
                } else {
                    yawFwd += npcAISettings->unk_AI_1C.s;
                }
            }
            npc->yaw = clamp_angle(yawFwd);
        }
    }
    if (detectedPlayer) {
        npc->duration = 10;
        npc->currentAnim.w = enemy->animList[ENEMY_ANIM_MELEE_PRE];
    }
    script->AI_TEMP_STATE = AI_STATE_CHASE;
}
