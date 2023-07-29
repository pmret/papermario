#include "common.h"
#include "npc.h"
#include "effects.h"

enum AiStateCleft {
    AI_STATE_CLEFT_HIDING_INIT          = 0,
    AI_STATE_CLEFT_HIDING               = 1,
    AI_STATE_CLEFT_PRE_AMBUSH           = 2,
    AI_STATE_CLEFT_AMBUSH               = 3,
    AI_STATE_CLEFT_FIND_PLAYER_INIT     = 4,
    AI_STATE_CLEFT_FIND_PLAYER          = 5,
    AI_STATE_CLEFT_CHASE_INIT           = 12,
    AI_STATE_CLEFT_CHASE                = 13,
    AI_STATE_CLEFT_CHASE_COOLDOWN       = 14,
    AI_STATE_CLEFT_REV_UP_INIT          = 20,
    AI_STATE_CLEFT_REV_UP               = 21,
    AI_STATE_CLEFT_TACKLE               = 22,
    AI_STATE_CLEFT_LOSE_PLAYER          = 40,
    AI_STATE_RETURN_HOME                = 41,
    AI_STATE_CLEFT_DISGUISE_INIT        = 50,
    AI_STATE_CLEFT_DISGUISE             = 51,
    AI_STATE_CLEFT_POST_DISGUISE        = 52
};

s32 N(CleftAI_CanSeePlayer)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Camera* camera = &gCameras[gCurrentCamID];
    f32 playerX, playerZ;
    f32 angle;
    s32 seesPlayer = FALSE;

    if (ai_check_player_dist(enemy, 0, aiSettings->alertRadius, aiSettings->alertOffsetDist)) {
        seesPlayer = TRUE;
    }
    if (clamp_angle(get_clamped_angle_diff(camera->curYaw, npc->yaw)) < 180.0) {
        angle = 90.0f;
    } else {
        angle = 270.0f;
    }

    playerX = gPlayerStatusPtr->pos.x;
    playerZ = gPlayerStatusPtr->pos.z;
    if (fabsf(get_clamped_angle_diff(angle, atan2(npc->pos.x, npc->pos.z, playerX, playerZ))) > 75.0) {
        seesPlayer = FALSE;
    }
    if (fabsf(npc->pos.y - gPlayerStatusPtr->pos.y) >= 40.0f) {
        seesPlayer = FALSE;
    }
    if (gPartnerStatus.actingPartner == PARTNER_BOW) {
        seesPlayer = FALSE;
    }
    return seesPlayer;
}

void N(CleftAI_HidingInit)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    disable_npc_shadow(npc);
    npc->collisionHeight = 22;
    npc->collisionDiameter = 24;
    script->functionTemp[1] = 0;
    npc->duration = 0;
    npc->curAnim = enemy->animList[8];
    script->AI_TEMP_STATE = AI_STATE_CLEFT_HIDING;
}

void N(CleftAI_Hiding)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EffectInstance* emoteTemp;

    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = aiSettings->playerSearchInterval;
        if (basic_ai_check_player_dist(volume, enemy, aiSettings->alertRadius * 0.85, aiSettings->alertOffsetDist, FALSE)) {
            npc->curAnim = enemy->animList[9];
            fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteTemp);
            ai_enemy_play_sound(npc, SOUND_2F4, SOUND_PARAM_MORE_QUIET);
            npc->duration = 12;
            script->AI_TEMP_STATE = AI_STATE_CLEFT_PRE_AMBUSH;
        }
    }

    script->functionTemp[1]--;
}

void N(CleftAI_PreAmbush)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
        enable_npc_shadow(npc);
        npc->curAnim = enemy->animList[10];
        npc->duration = 8;
        script->AI_TEMP_STATE = AI_STATE_CLEFT_AMBUSH;
    }
}

void N(CleftAI_Ambush)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* volume) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
        npc->collisionHeight = 26;
        npc->collisionDiameter = 24;
        script->AI_TEMP_STATE = AI_STATE_CLEFT_FIND_PLAYER_INIT;
    }
}

void N(CleftAI_FindPlayerInit)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->yaw = clamp_angle(npc->yaw + rand_int(180) - 90.0f);
    npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
    script->functionTemp[1] = rand_int(1000) % 2 + 2;
    script->AI_TEMP_STATE = AI_STATE_CLEFT_FIND_PLAYER;
}

void N(CleftAI_FindPlayer)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EffectInstance* var;

    if (basic_ai_check_player_dist(volume, enemy, aiSettings->chaseRadius, aiSettings->chaseOffsetDist, 0)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
        script->AI_TEMP_STATE = AI_STATE_CLEFT_CHASE_INIT;
    } else {
        npc->duration--;
        if (npc->duration <= 0) {
            script->functionTemp[1]--;
            if (script->functionTemp[1] > 0) {
                npc->yaw = clamp_angle(npc->yaw + 180.0f);
                npc->duration = aiSettings->waitTime / 2 + rand_int(aiSettings->waitTime / 2 + 1);
            } else {
                fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
                npc->duration = 15;
                script->AI_TEMP_STATE = AI_STATE_CLEFT_LOSE_PLAYER;
            }
        }
    }
}

void N(CleftAI_RevUpInit)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = enemy->varTable[10];
    npc->curAnim = enemy->animList[13];
    script->AI_TEMP_STATE = AI_STATE_CLEFT_REV_UP;
}

void N(CleftAI_RevUp)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
    if (npc->duration % 3 == 0) {
        fx_walking_dust(2, npc->pos.x, npc->pos.y, npc->pos.z + 2.0f, 0, 0);
    }

    npc->duration--;
    if (npc->duration <= 0) {
        enemy->unk_10.x = npc->pos.x;
        enemy->unk_10.y = npc->pos.y;
        enemy->unk_10.z = npc->pos.z;
        enemy->hitboxIsActive = TRUE;
        npc->moveSpeed = aiSettings->chaseSpeed;
        npc->duration = dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x,
                               gPlayerStatusPtr->pos.z) / npc->moveSpeed + 0.9;
        if (npc->duration < 15) {
            npc->duration = 15;
        }
        script->AI_TEMP_STATE = AI_STATE_CLEFT_TACKLE;
    }
}

void N(CleftAI_Tackle)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ;
    s32 phi_s1 = FALSE;

    spawn_surface_effects(npc, SURFACE_INTERACT_RUN);
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    if (is_point_within_region(enemy->territory->wander.detectShape,
            enemy->territory->wander.detectPos.x, enemy->territory->wander.detectPos.z,
            npc->pos.x, npc->pos.z,
            enemy->territory->wander.detectSize.x, enemy->territory->wander.detectSize.z)) {
        phi_s1 = TRUE;
    }

    posX = npc->pos.x;
    posY = npc->pos.y;
    posZ = npc->pos.z;
    if (npc_test_move_simple_with_slipping(npc->collisionChannel,
            &posX, &posY, &posZ,
            1.0f, npc->yaw, npc->collisionHeight, npc->collisionDiameter)) {
        phi_s1 = TRUE;
    }

    npc->duration--;
    if (npc->duration <= 0) {
        phi_s1 = TRUE;
    }
    if (phi_s1) {
        script->AI_TEMP_STATE = AI_STATE_CLEFT_FIND_PLAYER_INIT;
        enemy->hitboxIsActive = FALSE;
    }
}

void N(CleftAI_LosePlayer)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* volume) {
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
        script->AI_TEMP_STATE = AI_STATE_RETURN_HOME;
    }
}

void N(CleftAI_ReturnHome)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (basic_ai_check_player_dist(volume, enemy, aiSettings->chaseRadius, aiSettings->chaseOffsetDist, 0)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
        script->AI_TEMP_STATE = AI_STATE_CLEFT_CHASE_INIT;
    } else if (dist2D(npc->pos.x, npc->pos.z, enemy->territory->wander.centerPos.x, enemy->territory->wander.centerPos.z) <= npc->moveSpeed) {
        npc->duration = 10;
        script->AI_TEMP_STATE = AI_STATE_CLEFT_DISGUISE_INIT;
    } else if (npc->turnAroundYawAdjustment == 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.centerPos.x, enemy->territory->wander.centerPos.z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }
}

void N(CleftAI_DisguiseInit)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (npc->duration > 0) {
        npc->duration--;
    }

    if (npc->turnAroundYawAdjustment == 0 && npc->duration <= 0) {
        npc->duration = 8;
        npc->curAnim = enemy->animList[11];
        script->AI_TEMP_STATE = AI_STATE_CLEFT_DISGUISE;
    }
}

void N(CleftAI_Disguise)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->duration = 8;
        npc->curAnim = enemy->animList[14];
        script->AI_TEMP_STATE = AI_STATE_CLEFT_POST_DISGUISE;
    }
}

void N(CleftAI_PostDisguise)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        script->AI_TEMP_STATE = AI_STATE_CLEFT_HIDING_INIT;
    }
}

s32 N(CleftAI_Main)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    MobileAISettings* npcAISettings = (MobileAISettings*)evt_get_variable(script, *args++);
    EnemyDetectVolume curVolume;
    EnemyDetectVolume* volume = &curVolume;

    enemy->varTable[10] = evt_get_variable(script, *args++);

    curVolume.skipPlayerDetectChance = 0;
    curVolume.shape = enemy->territory->wander.detectShape;
    curVolume.pointX = enemy->territory->wander.detectPos.x;
    curVolume.pointZ = enemy->territory->wander.detectPos.z;
    curVolume.sizeX = enemy->territory->wander.detectSize.x;
    curVolume.sizeZ = enemy->territory->wander.detectSize.z;
    curVolume.halfHeight = 40.0f;
    curVolume.detectFlags = 0;

    if (isInitialCall) {
        script->AI_TEMP_STATE = AI_STATE_WANDER_INIT;
        npc->duration = 0;

        npc->flags &= ~NPC_FLAG_JUMPING;
        if (!enemy->territory->wander.isFlying) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_8;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_8;
        }
    }

    if (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND) {
        if (enemy->aiSuspendTime) {
            return ApiStatus_BLOCK;
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAG_SUSPEND;
    }

    if (((script->AI_TEMP_STATE == AI_STATE_CLEFT_CHASE_INIT)
            || (script->AI_TEMP_STATE == AI_STATE_CLEFT_CHASE)
            || (script->AI_TEMP_STATE == AI_STATE_CLEFT_CHASE_COOLDOWN))
            && N(CleftAI_CanSeePlayer)(script, npcAISettings, volume)) {
        script->AI_TEMP_STATE = 20;
    }

    switch (script->AI_TEMP_STATE) {
        case AI_STATE_CLEFT_HIDING_INIT:
            N(CleftAI_HidingInit)(script, npcAISettings, volume);
        case AI_STATE_CLEFT_HIDING:
            N(CleftAI_Hiding)(script, npcAISettings, volume);
            if (script->AI_TEMP_STATE != AI_STATE_CLEFT_PRE_AMBUSH) {
                return ApiStatus_BLOCK;
            }
        case AI_STATE_CLEFT_PRE_AMBUSH:
            N(CleftAI_PreAmbush)(script, npcAISettings, volume);
            if (script->AI_TEMP_STATE != AI_STATE_CLEFT_AMBUSH) {
                return ApiStatus_BLOCK;
            }
        case AI_STATE_CLEFT_AMBUSH:
            N(CleftAI_Ambush)(script, npcAISettings, volume);
            if (script->AI_TEMP_STATE != AI_STATE_CLEFT_FIND_PLAYER_INIT) {
                return ApiStatus_BLOCK;
            }
        case AI_STATE_CLEFT_FIND_PLAYER_INIT:
            N(CleftAI_FindPlayerInit)(script, npcAISettings, volume);
        case AI_STATE_CLEFT_FIND_PLAYER:
            N(CleftAI_FindPlayer)(script, npcAISettings, volume);
            return ApiStatus_BLOCK;

        case AI_STATE_CLEFT_CHASE_INIT:
            basic_ai_chase_init(script, npcAISettings, volume);
            if (script->AI_TEMP_STATE != AI_STATE_CLEFT_CHASE) {
                return ApiStatus_BLOCK;
            }
        case AI_STATE_CLEFT_CHASE:
            basic_ai_chase(script, npcAISettings, volume);
            if (script->AI_TEMP_STATE != AI_STATE_CLEFT_CHASE_COOLDOWN) {
                return ApiStatus_BLOCK;
            }
        case AI_STATE_CLEFT_CHASE_COOLDOWN:
            npc->duration--;
            if (npc->duration == 0) {
                script->AI_TEMP_STATE = AI_STATE_CLEFT_LOSE_PLAYER;
            }
            return ApiStatus_BLOCK;

        case AI_STATE_CLEFT_REV_UP_INIT:
            N(CleftAI_RevUpInit)(script, npcAISettings, volume);
        case AI_STATE_CLEFT_REV_UP:
            N(CleftAI_RevUp)(script, npcAISettings, volume);
            return ApiStatus_BLOCK;

        case AI_STATE_CLEFT_TACKLE:
            N(CleftAI_Tackle)(script, npcAISettings, volume);
            return ApiStatus_BLOCK;

        case AI_STATE_CLEFT_LOSE_PLAYER:
            N(CleftAI_LosePlayer)(script, npcAISettings, volume);
            if (script->AI_TEMP_STATE != AI_STATE_RETURN_HOME) {
                return ApiStatus_BLOCK;
            }
        case AI_STATE_RETURN_HOME:
            N(CleftAI_ReturnHome)(script, npcAISettings, volume);
            return ApiStatus_BLOCK;

        case AI_STATE_CLEFT_DISGUISE_INIT:
            N(CleftAI_DisguiseInit)(script, npcAISettings, volume);
        case AI_STATE_CLEFT_DISGUISE:
            N(CleftAI_Disguise)(script, npcAISettings, volume);
            if (script->AI_TEMP_STATE != AI_STATE_CLEFT_POST_DISGUISE) {
                return ApiStatus_BLOCK;
            }
        case AI_STATE_CLEFT_POST_DISGUISE:
            N(CleftAI_PostDisguise)(script, npcAISettings, volume);
            return ApiStatus_BLOCK;
    }

    return ApiStatus_BLOCK;
}
