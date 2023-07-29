#include "common.h"
#include "npc.h"
#include "effects.h"

void N(AvoidPlayerAI_ChaseInit)(Evt* script, MobileAISettings* npcAISettings, EnemyDetectVolume* territory) {
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

    npc->duration = npcAISettings->chaseUpdateInterval / 2 + rand_int(npcAISettings->chaseUpdateInterval / 2 + 1);
    npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_CHASE];
    npc->moveSpeed = npcAISettings->chaseSpeed;
    detectedPlayer = FALSE;

    yawFwd = clamp_angle(atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x,
                                 gPlayerStatusPtr->pos.z) + 180.0f);
    deltaYaw = get_clamped_angle_diff(npc->yaw, yawFwd);
    if (npcAISettings->chaseTurnRate < fabsf(deltaYaw)) {
        yawFwd = npc->yaw;
        if (deltaYaw < 0.0f) {
            yawFwd += -npcAISettings->chaseTurnRate;
        } else {
            yawFwd += npcAISettings->chaseTurnRate;
        }
    }

    npc->yaw = clamp_angle(yawFwd);

    posXFwd = npc->pos.x;
    posYFwd = npc->pos.y;
    posZFwd = npc->pos.z;

    yawFwd = clamp_angle(atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z) + 180.0f);
    distFwd = 0.0f;
    distCW = 0.0f;
    distCCW = 0.0f;

    if (npc_test_move_simple_without_slipping(npc->collisionChannel,
            &posXFwd, &posYFwd, &posZFwd, npc->moveSpeed * 4.5,
            yawFwd, npc->collisionHeight, npc->collisionDiameter)) {
        distFwd = dist2D(npc->pos.x, npc->pos.z, posXFwd, posZFwd);

        // check 'whisker' 35 degrees CW
        posXCW = npc->pos.x;
        posYCW = npc->pos.y;
        posZCW = npc->pos.z;
        if (npc_test_move_simple_without_slipping(npc->collisionChannel,
                &posXCW, &posYCW, &posZCW, npc->moveSpeed * 4.5,
                clamp_angle(yawFwd + 35.0f), npc->collisionHeight, npc->collisionDiameter)) {
            distCW = dist2D(npc->pos.x, npc->pos.z, posXCW, posZCW);
        }

        // check 'whisker' 35 degrees CCW
        posXCCW = npc->pos.x;
        posYCCW = npc->pos.y;
        posZCCW = npc->pos.z;
        if (npc_test_move_simple_without_slipping(npc->collisionChannel,
                &posXCCW, &posYCCW, &posZCCW, npc->moveSpeed * 4.5,
                clamp_angle(yawFwd - 35.0f), npc->collisionHeight, npc->collisionDiameter)) {
            distCCW = dist2D(npc->pos.x, npc->pos.z, posXCCW, posZCCW);
        }

        // unused
        distToPlayer = dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);

        if ((distFwd < npc->moveSpeed * 1.5) && (distCW < npc->moveSpeed * 1.5) && (distCCW < npc->moveSpeed * 1.5) &&
            (basic_ai_check_player_dist(territory, enemy, npcAISettings->alertRadius, npcAISettings->alertOffsetDist, 0))) {
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
            if (npcAISettings->chaseTurnRate < fabsf(deltaYaw)) {
                yawFwd = npc->yaw;
                if (deltaYaw < 0.0f) {
                    yawFwd += -npcAISettings->chaseTurnRate;
                } else {
                    yawFwd += npcAISettings->chaseTurnRate;
                }
            }
            npc->yaw = clamp_angle(yawFwd);
        }
    }
    if (detectedPlayer) {
        npc->duration = 10;
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_MELEE_PRE];
    }
    script->AI_TEMP_STATE = AI_STATE_CHASE;
}

void N(AvoidPlayerAI_Chase)(Evt* script, MobileAISettings* npcAISettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EffectInstance* emoteTemp;

    if (!basic_ai_check_player_dist(territory, enemy, npcAISettings->chaseRadius, npcAISettings->chaseOffsetDist, 1)) {
        fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteTemp);
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        npc->duration = 25;
        script->AI_TEMP_STATE = AI_STATE_LOSE_PLAYER;
    } else {
        if (npc->curAnim != enemy->animList[ENEMY_ANIM_INDEX_MELEE_PRE]) {
            if (npc->moveSpeed < 4.0) {
                spawn_surface_effects(npc, SURFACE_INTERACT_WALK);
            } else {
                spawn_surface_effects(npc, SURFACE_INTERACT_RUN);
            }
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        }
        if (npc->duration > 0) {
            npc->duration--;
            return;
        }
        script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
    }
}

void N(AvoidPlayerAI_LosePlayer)(Evt* script, MobileAISettings* npcAISettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        script->AI_TEMP_STATE = AI_STATE_WANDER_INIT;
    }
}

API_CALLABLE(N(AvoidPlayerAI_Main)) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    MobileAISettings* npcAISettings = (MobileAISettings*)evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detectPos.x;
    territory.pointZ = enemy->territory->wander.detectPos.z;
    territory.sizeX = enemy->territory->wander.detectSize.x;
    territory.sizeZ = enemy->territory->wander.detectSize.z;
    territory.halfHeight = 100.0f;
    territory.detectFlags = 0;

    #ifdef _DEAD_H_
    enemy->unk_108.x = npc->pos.x;
    enemy->unk_108.y = npc->pos.y;
    enemy->unk_108.z = npc->pos.z;
    enemy->unk_114 = 0.01f;
    enemy->unk_118 = 0.01f;
    #endif

    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND)) {
        script->functionTemp[0] = AI_STATE_WANDER_INIT;
        npc->duration = 0;
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        npc->flags &= ~NPC_FLAG_JUMPING;
        if (!enemy->territory->wander.isFlying) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_8;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_8;
        }
        if (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND) {
            script->functionTemp[0] = AI_STATE_SUSPEND;
            script->functionTemp[1] = AI_STATE_WANDER_INIT;
            enemy->aiFlags &= ~ENEMY_AI_FLAG_SUSPEND;
        }
    }

    switch (script->functionTemp[0]) {
        case AI_STATE_WANDER_INIT:
            basic_ai_wander_init(script, npcAISettings, territoryPtr);
        case AI_STATE_WANDER:
            basic_ai_wander(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_LOITER_INIT:
            basic_ai_loiter_init(script, npcAISettings, territoryPtr);
        case AI_STATE_LOITER:
            basic_ai_loiter(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_ALERT_INIT:
            basic_ai_found_player_jump_init(script, npcAISettings, territoryPtr);
        case AI_STATE_ALERT:
            basic_ai_found_player_jump(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_CHASE_INIT:
            N(AvoidPlayerAI_ChaseInit)(script, npcAISettings, territoryPtr);
        case AI_STATE_CHASE:
            N(AvoidPlayerAI_Chase)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_LOSE_PLAYER:
            N(AvoidPlayerAI_LosePlayer)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_SUSPEND:
            basic_ai_suspend(script);
            break;
    }

    return ApiStatus_BLOCK;
}

