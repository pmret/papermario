#include "common.h"
#include "world/partners.h"

// prerequisites
#include "world/common/enemy/ai/MeleeHitbox.inc.c"

enum AiStateNappingClubba {
    AI_STATE_NAPPING_CLUBBA_INIT                = 0,
    AI_STATE_NAPPING_CLUBBA_SLEEP               = 1,
    AI_STATE_NAPPING_CLUBBA_WAKE_UP             = 2,
    AI_STATE_NAPPING_CLUBBA_LOITER_INIT         = 3,
    AI_STATE_NAPPING_CLUBBA_LOITER              = 4,
    AI_STATE_NAPPING_CLUBBA_50                  = 50,
};

void N(ClubbaNappingAI_Init)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (npc->duration > 0) {
        npc->duration--;
    }

    if (npc->duration == 1) {
        npc->curAnim = enemy->animList[12];
    } else if (npc->duration <= 0) {
        npc->curAnim = enemy->animList[10];
        npc->duration = 0;
        script->AI_TEMP_STATE = AI_STATE_NAPPING_CLUBBA_SLEEP;
    }
}

void N(ClubbaNappingAI_Sleep)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    PlayerData* playerData = get_player_data();
    s32 shouldWakeUp = FALSE;
    EffectInstance* emoteTemp;
    f32 posX, posZ;

    if (basic_ai_check_player_dist(territory, enemy, 80.0f, 0.0f, 0)) {
        if (   gPlayerStatusPtr->actionState == ACTION_STATE_RUN
            || gPlayerStatusPtr->actionState == ACTION_STATE_SPIN
            || gPlayerStatusPtr->actionState == ACTION_STATE_JUMP
            || gPlayerStatusPtr->actionState == ACTION_STATE_SPIN_POUND
            || gPlayerStatusPtr->actionState == ACTION_STATE_TORNADO_POUND
            || gPlayerStatusPtr->actionState == ACTION_STATE_STEP_DOWN_LAND
            || gPlayerStatusPtr->actionState == ACTION_STATE_LAND
            || gPlayerStatusPtr->actionState == ACTION_STATE_HAMMER
            || gPlayerStatusPtr->actionState == ACTION_STATE_13
            || gPlayerStatusPtr->actionState == ACTION_STATE_INVALID_25) {
            shouldWakeUp = TRUE;
        }

        if (playerData->curPartner == PARTNER_KOOPER) {
            if (gPartnerStatus.partnerActionState == playerData->curPartner) {
                shouldWakeUp = TRUE;
            }
        }
    }

    if (((playerData->curPartner == PARTNER_GOOMBARIO) && (gPartnerStatus.partnerActionState != PARTNER_ACTION_NONE)) ||
        ((playerData->curPartner == PARTNER_BOMBETTE) && (gPartnerStatus.partnerActionState == PARTNER_ACTION_BOMBETTE_2))) {
        posX = npc->pos.x;
        posZ = npc->pos.z;
        add_vec2D_polar(&posX, &posZ, 0.0f, npc->yaw);
        if (dist2D(posX, posZ, wPartnerNpc->pos.x, wPartnerNpc->pos.z) <= 80.0f) {
            shouldWakeUp = TRUE;
        }
    }

    if (shouldWakeUp) {
        ai_enemy_play_sound(npc, SOUND_SEQ_SNAP_AWAKE, 0);
        npc->curAnim = enemy->animList[11];
        npc->duration = 10;
        fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteTemp);
        ai_enemy_play_sound(npc, SOUND_AI_ALERT_A, SOUND_PARAM_MORE_QUIET);
        script->AI_TEMP_STATE = AI_STATE_NAPPING_CLUBBA_WAKE_UP;
    }

    npc->duration++;
    if (npc->duration == 27) {
        ai_enemy_play_sound(npc, SOUND_SEQ_SNORE_INHALE, 0);
    } else if (npc->duration == 57) {
        ai_enemy_play_sound(npc, SOUND_SEQ_SNORE_EXHALE, 0);
    } else if (npc->duration == 59) {
        npc->curAnim = enemy->animList[12];
    } else if (npc->duration == 60) {
        npc->curAnim = enemy->animList[10];
        npc->duration = 0;
    }
}

void N(ClubbaNappingAI_WakeUp)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->duration = 1;
        enemy->AI_VAR_NEXT_STATE = AI_RETURN_HOME_INIT;
        script->AI_TEMP_STATE = AI_STATE_NAPPING_CLUBBA_LOITER_INIT;
    }
}

void N(ClubbaNappingAI_LoiterInit)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->yaw = clamp_angle((npc->yaw + rand_int(180)) - 90.0f);
    npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
    script->functionTemp[1] = (rand_int(1000) % 2) + 2; // chose random number 2-3
    script->AI_TEMP_STATE = AI_STATE_NAPPING_CLUBBA_LOITER;
}

void N(ClubbaNappingAI_Loiter)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 nextState;

    // try to catch sight of player
    if (basic_ai_check_player_dist(territory, enemy, aiSettings->chaseRadius, aiSettings->chaseOffsetDist, 0)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
        script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
        return;
    }

    npc->duration--;
    if (npc->duration <= 0) {
        // try to turn around and check the other direction
        script->functionTemp[1]--;
        if (script->functionTemp[1] > 0) {
            npc->yaw = clamp_angle(npc->yaw + 180.0f);
            npc->duration = aiSettings->waitTime / 2 + rand_int(aiSettings->waitTime / 2 + 1);
            return;
        }

        // didnt see player, continue to next state
        nextState = enemy->AI_VAR_NEXT_STATE;
        if (nextState == AI_RETURN_HOME_INIT) {
            npc->duration = 20;
            script->AI_TEMP_STATE = nextState;
        } else if (nextState == AI_STATE_NAPPING_CLUBBA_50) {
            npc->duration = 25;
            script->AI_TEMP_STATE = nextState;
        }
    }
}

void N(ClubbaNappingAI_ReturnHomeInit)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_WALK];
        if (enemy->territory->wander.moveSpeedOverride < 0) {
            npc->moveSpeed = aiSettings->moveSpeed;
        } else {
            npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
        }
        script->AI_TEMP_STATE = AI_RETURN_HOME;
    }
}

void N(ClubbaNappingAI_ReturnHome)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 currentYaw;

    if (basic_ai_check_player_dist(territory, enemy, aiSettings->chaseRadius, aiSettings->chaseOffsetDist, 0)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
        script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
    } else if (dist2D(npc->pos.x, npc->pos.z, enemy->territory->wander.centerPos.x,
                      enemy->territory->wander.centerPos.z) <= npc->moveSpeed) {
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        npc->duration = 15;
        enemy->AI_VAR_NEXT_STATE = AI_STATE_NAPPING_CLUBBA_50;
        script->AI_TEMP_STATE = AI_STATE_NAPPING_CLUBBA_LOITER_INIT;
    } else if (npc->turnAroundYawAdjustment == 0) {
        currentYaw = npc->yaw;
        ai_check_fwd_collisions(npc, 5.0f, &currentYaw, 0, 0, 0);
        npc->yaw = currentYaw;
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.centerPos.x, enemy->territory->wander.centerPos.z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }
}

void N(ClubbaNappingAI_FallAsleep)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (npc->turnAroundYawAdjustment == 0) {
        npc->duration--;
        if (npc->duration <= 0) {
            npc->duration = 0;
            script->AI_TEMP_STATE = AI_STATE_NAPPING_CLUBBA_INIT;
        }
    }
}

API_CALLABLE(N(ClubbaNappingAI_Main)) {
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
    territory.halfHeight = 40.0f;
    territory.detectFlags = 0;

    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND)) {
        script->AI_TEMP_STATE = AI_STATE_NAPPING_CLUBBA_INIT;
        npc->duration = 30;
        npc->curAnim = enemy->animList[10];
        npc->flags &= ~NPC_FLAG_JUMPING;
        enemy->AI_VAR_ATTACK_STATE = MELEE_HITBOX_STATE_NONE;
        if (!enemy->territory->wander.isFlying) {
            npc->flags = (npc->flags | NPC_FLAG_GRAVITY) & ~NPC_FLAG_FLYING;
        } else {
            npc->flags = (npc->flags & ~NPC_FLAG_GRAVITY) | NPC_FLAG_FLYING;
        }
        if (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND) {
            script->AI_TEMP_STATE = AI_STATE_SUSPEND;
            script->AI_TEMP_STATE_AFTER_SUSPEND = AI_RETURN_HOME_INIT;
            npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAG_SUSPEND;
    }

    if (script->AI_TEMP_STATE >= AI_STATE_ALERT_INIT
            && script->AI_TEMP_STATE < AI_STATE_MELEE_HITBOX_INIT
            && enemy->AI_VAR_ATTACK_STATE == MELEE_HITBOX_STATE_NONE
            && N(MeleeHitbox_CanSeePlayer)(script)) {
        script->AI_TEMP_STATE = AI_STATE_MELEE_HITBOX_INIT;
    }

    switch (script->AI_TEMP_STATE) {
        case AI_STATE_NAPPING_CLUBBA_INIT:
            N(ClubbaNappingAI_Init)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_NAPPING_CLUBBA_SLEEP:
            N(ClubbaNappingAI_Sleep)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_NAPPING_CLUBBA_WAKE_UP:
            N(ClubbaNappingAI_WakeUp)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_NAPPING_CLUBBA_LOITER_INIT:
            N(ClubbaNappingAI_LoiterInit)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_NAPPING_CLUBBA_LOITER:
            N(ClubbaNappingAI_Loiter)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_CHASE_INIT:
            basic_ai_chase_init(script, npcAISettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_CHASE) {
                break;
            }
        case AI_STATE_CHASE:
            basic_ai_chase(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_LOSE_PLAYER:
            // LOSE PLAYER
            basic_ai_lose_player(script, npcAISettings, territoryPtr);
            npc->duration = 15;
            enemy->AI_VAR_NEXT_STATE = AI_RETURN_HOME_INIT;
            script->AI_TEMP_STATE = AI_STATE_NAPPING_CLUBBA_LOITER_INIT;
            break;
        case AI_STATE_MELEE_HITBOX_INIT: // pre swing
            N(MeleeHitbox_30)(script);
            if (script->AI_TEMP_STATE != AI_STATE_MELEE_HITBOX_PRE) {
                break;
            }
        case AI_STATE_MELEE_HITBOX_PRE: // raise club
            N(MeleeHitbox_31)(script);
            if (script->AI_TEMP_STATE != AI_STATE_MELEE_HITBOX_ACTIVE) {
                break;
            }
        case AI_STATE_MELEE_HITBOX_ACTIVE: // swing club
            N(MeleeHitbox_32)(script);
            break;
        case AI_STATE_MELEE_HITBOX_MISS:
            N(MeleeHitbox_33)(script);
            break;
        case AI_RETURN_HOME_INIT:
            // START RETURN HOME
            N(ClubbaNappingAI_ReturnHomeInit)(script, npcAISettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_RETURN_HOME) {
                break;
            }
        case AI_RETURN_HOME:
            // RETURN HOME
            N(ClubbaNappingAI_ReturnHome)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_NAPPING_CLUBBA_50:
            // WAIT TO NAP
            N(ClubbaNappingAI_FallAsleep)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_SUSPEND:
            basic_ai_suspend(script);
    }

    return ApiStatus_BLOCK;
}
