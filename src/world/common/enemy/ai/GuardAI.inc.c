#ifndef _AI_GUARD_H_
#define _AI_GUARD_H_

// Used in:
// - kmr_02 Toad
// - kmr_07 GoombaBros
// - kmr_11 GoombaBros/King
// - sbk_30 (unused)
// - trd_01 Bobomb <-- only real use case!
// - nok_01 (unused)
// - omo_02 (unused)

// custom states for this AI
enum AiStateGuard {
    AI_STATE_GUARD_IDLE_INIT           = 0,
    AI_STATE_GUARD_IDLE                = 1,
    AI_STATE_GUARD_RETURN_HOME_INIT    = 15,
    AI_STATE_GUARD_RETURN_HOME         = 16
};

#include "common.h"
#include "npc.h"
#include "effects.h"

void N(GuardAI_IdleInit)(Evt* script, GuardAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
    script->AI_TEMP_STATE = AI_STATE_GUARD_IDLE;

    if (enemy->flags & ENEMY_FLAG_100000) {
        npc->yaw = enemy->varTable[0];
    }

    if (enemy->territory->wander.moveSpeedOverride <= 0) {
        npc->moveSpeed = aiSettings->chaseSpeed;
    } else {
        npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
    }
}

void N(GuardAI_Idle)(Evt* script, GuardAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EffectInstance* emoteTemp;

    if (aiSettings->playerSearchInterval >= 0 && basic_ai_check_player_dist(territory, enemy, aiSettings->chaseRadius, aiSettings->chaseOffsetDist, 0)) {
        fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteTemp);
        ai_enemy_play_sound(npc, SOUND_2F4, SOUND_PARAM_MORE_QUIET);
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);

        if (!(enemy->npcSettings->actionFlags & AI_ACTION_JUMP_WHEN_SEE_PLAYER)) {
            script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
        } else {
            script->AI_TEMP_STATE = AI_STATE_ALERT_INIT;
        }
    }
}

void N(GuardAI_AlertInit)(Evt* script, GuardAISettings* aiSettings, EnemyDetectVolume* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->jumpVel = 10.0f;
    npc->jumpScale = 2.0f;
    npc->moveToPos.y = npc->pos.y;
    npc->flags |= NPC_FLAG_JUMPING;
    script->AI_TEMP_STATE = AI_STATE_ALERT;
}

void N(GuardAI_Alert)(Evt* script, GuardAISettings* aiSettings, EnemyDetectVolume* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->pos.y += npc->jumpVel;
    npc->jumpVel -= npc->jumpScale;

    if (!(npc->pos.y > npc->moveToPos.y)) {
        npc->pos.y = npc->moveToPos.y;
        npc->jumpVel = 0.0f;
        npc->flags &= ~NPC_FLAG_JUMPING;
        script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
    }
}

void N(GuardAI_ChaseInit)(Evt* script, GuardAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 tempAngle;
    f32 angleDiff;

    npc->duration = (aiSettings->chaseUpdateInterval / 2) + rand_int(aiSettings->chaseUpdateInterval / 2 + 1);
    npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_CHASE];
    npc->moveSpeed = aiSettings->chaseSpeed;

    tempAngle = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
    angleDiff = get_clamped_angle_diff(npc->yaw, tempAngle);

    if (aiSettings->chaseTurnRate < fabsf(angleDiff)) {
        tempAngle = npc->yaw;

        if (angleDiff < 0.0f) {
            tempAngle += -aiSettings->chaseTurnRate;
        } else {
            tempAngle += aiSettings->chaseTurnRate;
        }
    }

    npc->yaw = clamp_angle(tempAngle);
    script->AI_TEMP_STATE = AI_STATE_CHASE;
}

void N(GuardAI_Chase)(Evt* script, GuardAISettings* aiSettings, EnemyDetectVolume* arg2) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EffectInstance* emoteTemp;

    if (!basic_ai_check_player_dist(arg2, enemy, aiSettings->chaseRadius, aiSettings->chaseOffsetDist, 1)) {
        fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteTemp);
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        npc->duration = 25;
        script->AI_TEMP_STATE = AI_STATE_LOSE_PLAYER;
    } else {
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        spawn_surface_effects(npc, SURFACE_INTERACT_RUN);
        npc->duration--;
        if (npc->duration == 0) {
            script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
        }
    }
}

void N(GuardAI_LosePlayer)(Evt* script, GuardAISettings* aiSettings, EnemyDetectVolume* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        script->AI_TEMP_STATE = AI_STATE_GUARD_RETURN_HOME_INIT;
    }
}

void N(GuardAI_ReturnHomeInit)(Evt* script, GuardAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_WALK];
    if (enemy->territory->wander.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->chaseSpeed * 0.3;
    } else {
        npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
    }
    script->functionTemp[1] = 0;
    script->AI_TEMP_STATE = AI_STATE_GUARD_RETURN_HOME;
}

void N(GuardAI_ReturnHome)(Evt* script, GuardAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EffectInstance* emoteTemp;

    if (aiSettings->playerSearchInterval >= 0) {
        if (script->functionTemp[1] <= 0) {
            script->functionTemp[1] = aiSettings->playerSearchInterval;
            if (basic_ai_check_player_dist(territory, enemy, aiSettings->chaseRadius, aiSettings->chaseOffsetDist, 0)) {
                fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, (f32) npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteTemp);
                ai_enemy_play_sound(npc, SOUND_2F4, SOUND_PARAM_MORE_QUIET);
                npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
                if (enemy->npcSettings->actionFlags & AI_ACTION_JUMP_WHEN_SEE_PLAYER) {
                    script->AI_TEMP_STATE = AI_STATE_ALERT_INIT;
                } else {
                    script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
                }
                return;
            }
        }
        script->functionTemp[1]--;
    }

    if (dist2D(npc->pos.x, npc->pos.z, enemy->territory->wander.centerPos.x, enemy->territory->wander.centerPos.z) < npc->moveSpeed) {
        npc->pos.x = enemy->territory->wander.centerPos.x;
        npc->pos.z = enemy->territory->wander.centerPos.z;
        npc->yaw = enemy->territory->wander.wanderSize.x;
        script->AI_TEMP_STATE = AI_STATE_GUARD_IDLE_INIT;
    }

    if (npc->turnAroundYawAdjustment == 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.centerPos.x, enemy->territory->wander.centerPos.z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }
}

API_CALLABLE(N(GuardAI_Main)) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    GuardAISettings* aiSettings = (GuardAISettings*)evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detectPos.x;
    territory.pointZ = enemy->territory->wander.detectPos.z;
    territory.sizeX = enemy->territory->wander.detectSize.x;
    territory.sizeZ = enemy->territory->wander.detectSize.z;
    territory.halfHeight = 65.0f;
    territory.detectFlags = 0;

    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND)) {
        script->AI_TEMP_STATE = AI_STATE_GUARD_IDLE_INIT;
        npc->duration = 0;
        enemy->varTable[0] = npc->yaw;
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        npc->flags &= ~NPC_FLAG_JUMPING;

        if (!(enemy->territory->wander.isFlying)) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_8;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_8;
        }

        if (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND) {
            script->AI_TEMP_STATE = AI_STATE_SUSPEND;
            script->functionTemp[1] = 15;
            enemy->aiFlags &= ~ENEMY_AI_FLAG_SUSPEND;
        } else if (enemy->flags & ENEMY_FLAG_BEGIN_WITH_CHASING) {
            script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
            enemy->flags &= ~ENEMY_FLAG_BEGIN_WITH_CHASING;
        }
    }

    switch (script->AI_TEMP_STATE) {
        case AI_STATE_GUARD_IDLE_INIT:
            N(GuardAI_IdleInit)(script, aiSettings, territoryPtr);
        case AI_STATE_GUARD_IDLE:
            N(GuardAI_Idle)(script, aiSettings, territoryPtr);
            break;

        case AI_STATE_ALERT_INIT:
            N(GuardAI_AlertInit)(script, aiSettings, territoryPtr);
        case AI_STATE_ALERT:
            N(GuardAI_Alert)(script, aiSettings, territoryPtr);
            break;

        case AI_STATE_CHASE_INIT:
            N(GuardAI_ChaseInit)(script, aiSettings, territoryPtr);
        case AI_STATE_CHASE:
            N(GuardAI_Chase)(script, aiSettings, territoryPtr);
            break;

        case AI_STATE_LOSE_PLAYER:
            N(GuardAI_LosePlayer)(script, aiSettings, territoryPtr);
            break;

        case AI_STATE_GUARD_RETURN_HOME_INIT:
            N(GuardAI_ReturnHomeInit)(script, aiSettings, territoryPtr);
        case AI_STATE_GUARD_RETURN_HOME:
            N(GuardAI_ReturnHome)(script, aiSettings, territoryPtr);
            break;

        case AI_STATE_SUSPEND:
            basic_ai_suspend(script);
            break;
    }
    return ApiStatus_BLOCK;
}

#endif
