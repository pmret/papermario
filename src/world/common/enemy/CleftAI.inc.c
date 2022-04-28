#include "common.h"
#include "npc.h"
#include "effects.h"

enum AiStateCleft {
    AI_STATE_CLEFT_0                    = 0,
    AI_STATE_CLEFT_1                    = 1,    // rock form idle
    AI_STATE_CLEFT_2                    = 2,
    AI_STATE_CLEFT_3                    = 3,
    AI_STATE_CLEFT_4                    = 4,
    AI_STATE_CLEFT_5                    = 5,
    AI_STATE_CLEFT_12                   = 12,
    AI_STATE_CLEFT_13                   = 13,
    AI_STATE_CLEFT_14                   = 14,
    AI_STATE_CLEFT_20                   = 20,
    AI_STATE_CLEFT_21                   = 21,
    AI_STATE_CLEFT_22                   = 22,
    AI_STATE_CLEFT_40                   = 40,
    AI_STATE_CLEFT_41                   = 41,
    AI_STATE_CLEFT_50                   = 50,
    AI_STATE_CLEFT_51                   = 51,
    AI_STATE_CLEFT_52                   = 52
};

s32 N(CleftAI_CanSeePlayer)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Camera* camera = &gCameras[gCurrentCamID];
    f32 playerX, playerZ;
    f32 angle;
    s32 seesPlayer = FALSE;

    if (func_800493EC(enemy, 0, aiSettings->alertRadius, aiSettings->unk_10.f)) {
        seesPlayer = TRUE;
    }
    if (clamp_angle(get_clamped_angle_diff(camera->currentYaw, npc->yaw)) < 180.0) {
        angle = 90.0f;
    } else {
        angle = 270.0f;
    }

    playerX = gPlayerStatusPtr->position.x;
    playerZ = gPlayerStatusPtr->position.z;
    if (fabsf(get_clamped_angle_diff(angle, atan2(npc->pos.x, npc->pos.z, playerX, playerZ))) > 75.0) {
        seesPlayer = FALSE;
    }
    if (fabsf(npc->pos.y - gPlayerStatusPtr->position.y) >= 40.0f) {
        seesPlayer = FALSE;
    }
    if (gPartnerActionStatus.actingPartner == PARTNER_BOW) {
        seesPlayer = FALSE;
    }
    return seesPlayer;
}

void N(CleftAI_00)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    disable_npc_shadow(npc);
    npc->collisionHeight = 22;
    npc->collisionRadius = 24;
    script->functionTemp[1] = 0;
    npc->duration = 0;
    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_MELEE_PRE];
    script->AI_TEMP_STATE = AI_STATE_CLEFT_1;
}

void N(CleftAI_01)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 emoteTemp;

    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = aiSettings->playerSearchInterval;
        if (basic_ai_try_detect_player(volume, enemy, aiSettings->alertRadius * 0.85, aiSettings->unk_10.f, FALSE)) {
            npc->currentAnim.w = enemy->animList[9];
            fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteTemp);
            ai_enemy_play_sound(npc, SOUND_2F4, 0x200000);
            npc->duration = 12;
            script->AI_TEMP_STATE = AI_STATE_CLEFT_2;
        }
    }

    script->functionTemp[1]--;
}

void N(CleftAI_02)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        enable_npc_shadow(npc);
        npc->currentAnim.w = enemy->animList[10];
        npc->duration = 8;
        script->AI_TEMP_STATE = AI_STATE_CLEFT_3;
    }
}

void N(CleftAI_03)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* volume) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        npc->collisionHeight = 26;
        npc->collisionRadius = 24;
        script->AI_TEMP_STATE = AI_STATE_CLEFT_4;
    }
}

void N(CleftAI_04)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->yaw = clamp_angle(npc->yaw + rand_int(180) - 90.0f);
    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_IDLE];
    script->functionTemp[1] = rand_int(1000) % 2 + 2;
    script->AI_TEMP_STATE = AI_STATE_CLEFT_5;
}

void N(CleftAI_05)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if (basic_ai_try_detect_player(volume, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 0)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        script->AI_TEMP_STATE = AI_STATE_CLEFT_12;
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
                script->AI_TEMP_STATE = AI_STATE_CLEFT_40;
            }
        }
    }
}

void N(CleftAI_20)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = enemy->varTable[10];
    npc->currentAnim.w = enemy->animList[13];
    script->AI_TEMP_STATE = AI_STATE_CLEFT_21;
}

void N(CleftAI_21)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
    if (npc->duration % 3 == 0) {
        fx_walking_dust(2, npc->pos.x, npc->pos.y, npc->pos.z + 2.0f, 0, 0);
    }

    npc->duration--;
    if (npc->duration <= 0) {
        enemy->unk_10.x = npc->pos.x;
        enemy->unk_10.y = npc->pos.y;
        enemy->unk_10.z = npc->pos.z;
        enemy->unk_07 = 1;
        npc->moveSpeed = aiSettings->chaseSpeed;
        npc->duration = dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x,
                               gPlayerStatusPtr->position.z) / npc->moveSpeed + 0.9;
        if (npc->duration < 15) {
            npc->duration = 15;
        }
        script->AI_TEMP_STATE = AI_STATE_CLEFT_22;
    }
}

void N(CleftAI_22)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ;
    s32 phi_s1;

    func_8003D660(npc, 1);
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    phi_s1 = 0;
    if (is_point_within_region(enemy->territory->wander.detectShape,
                               enemy->territory->wander.detect.x, enemy->territory->wander.detect.z,
                               npc->pos.x, npc->pos.z, enemy->territory->wander.detectSizeX,
                               enemy->territory->wander.detectSizeZ)) {
        phi_s1 = 1;
    }

    posX = npc->pos.x;
    posY = npc->pos.y;
    posZ = npc->pos.z;

    if (npc_test_move_simple_with_slipping(npc->collisionChannel, &posX, &posY, &posZ,
                      1.0f, npc->yaw, npc->collisionHeight, npc->collisionRadius)) {
        phi_s1 = 1;
    }

    npc->duration--;
    if (npc->duration <= 0) {
        phi_s1 = 1;
    }
    if (phi_s1) {
        script->AI_TEMP_STATE = AI_STATE_CLEFT_4;
        enemy->unk_07 = 0;
    }
}

void N(CleftAI_40)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->currentAnim.w = enemy->animList[ENEMY_ANIM_WALK];
        if (enemy->territory->wander.moveSpeedOverride < 0) {
            npc->moveSpeed = aiSettings->moveSpeed;
        } else {
            npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
        }
        script->AI_TEMP_STATE = AI_STATE_CLEFT_41;
    }
}

void N(CleftAI_41)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (basic_ai_try_detect_player(volume, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 0)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        script->AI_TEMP_STATE = AI_STATE_CLEFT_12;
    } else if (dist2D(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x,
                      enemy->territory->wander.point.z) <= npc->moveSpeed) {
        npc->duration = 10;
        script->AI_TEMP_STATE = AI_STATE_CLEFT_50;
    } else if (npc->turnAroundYawAdjustment == 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }
}

void N(CleftAI_50)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (npc->duration > 0) {
        npc->duration--;
    }

    if (npc->turnAroundYawAdjustment == 0 && npc->duration <= 0) {
        npc->duration = 8;
        npc->currentAnim.w = enemy->animList[11];
        script->AI_TEMP_STATE = AI_STATE_CLEFT_51;
    }
}

void N(CleftAI_51)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->duration = 8;
        npc->currentAnim.w = enemy->animList[14];
        script->AI_TEMP_STATE = AI_STATE_CLEFT_52;
    }
}

void N(CleftAI_52)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* volume) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        script->AI_TEMP_STATE = AI_STATE_CLEFT_0;
    }
}

s32 N(CleftAI_Main)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);
    EnemyDetectVolume curVolume;
    EnemyDetectVolume* volume = &curVolume;

    enemy->varTable[10] = evt_get_variable(script, *args++);

    curVolume.skipPlayerDetectChance = 0;
    curVolume.shape = enemy->territory->wander.detectShape;
    curVolume.pointX = enemy->territory->wander.detect.x;
    curVolume.pointZ = enemy->territory->wander.detect.z;
    curVolume.sizeX = enemy->territory->wander.detectSizeX;
    curVolume.sizeZ = enemy->territory->wander.detectSizeZ;
    curVolume.halfHeight = 40.0f;
    curVolume.detectFlags = 0;

    if (isInitialCall) {
        script->AI_TEMP_STATE = AI_STATE_WANDER_INIT;
        npc->duration = 0;

        npc->flags &= ~NPC_FLAG_JUMPING;
        if (!enemy->territory->wander.isFlying) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
        }
    }

    if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
        if (enemy->aiPaused) {
            return ApiStatus_BLOCK;
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
    }

    if (((script->AI_TEMP_STATE == AI_STATE_CLEFT_12)
            || (script->AI_TEMP_STATE == AI_STATE_CLEFT_13)
            || (script->AI_TEMP_STATE == AI_STATE_CLEFT_14))
            && N(CleftAI_CanSeePlayer)(script, npcAISettings, volume)) {
        script->AI_TEMP_STATE = 20;
    }

    switch (script->AI_TEMP_STATE) {
        case AI_STATE_CLEFT_0:
            N(CleftAI_00)(script, npcAISettings, volume);
            // fallthrough
        case AI_STATE_CLEFT_1:
            N(CleftAI_01)(script, npcAISettings, volume);
            if (script->AI_TEMP_STATE != AI_STATE_CLEFT_2) {
                return ApiStatus_BLOCK;
            }
            // fallthrough
        case AI_STATE_CLEFT_2:
            N(CleftAI_02)(script, npcAISettings, volume);
            if (script->AI_TEMP_STATE != AI_STATE_CLEFT_3) {
                return ApiStatus_BLOCK;
            }
            // fallthrough
        case AI_STATE_CLEFT_3:
            N(CleftAI_03)(script, npcAISettings, volume);
            if (script->AI_TEMP_STATE != AI_STATE_CLEFT_4) {
                return ApiStatus_BLOCK;
            }
            // fallthrough
        case AI_STATE_CLEFT_4:
            N(CleftAI_04)(script, npcAISettings, volume);
            // fallthrough
        case AI_STATE_CLEFT_5:
            N(CleftAI_05)(script, npcAISettings, volume);
            return ApiStatus_BLOCK;
        case AI_STATE_CLEFT_12:
            basic_ai_chase_init(script, npcAISettings, volume);
            if (script->AI_TEMP_STATE != AI_STATE_CLEFT_13) {
                return ApiStatus_BLOCK;
            }
            // fallthrough
        case AI_STATE_CLEFT_13:
            basic_ai_chase(script, npcAISettings, volume);
            if (script->AI_TEMP_STATE != AI_STATE_CLEFT_14) {
                return ApiStatus_BLOCK;
            }
            // fallthrough
        case AI_STATE_CLEFT_14:
            npc->duration--;
            if (npc->duration == 0) {
                script->AI_TEMP_STATE = AI_STATE_CLEFT_40;
            }
            return ApiStatus_BLOCK;
        case AI_STATE_CLEFT_20:
            N(CleftAI_20)(script, npcAISettings, volume);
            // fallthrough
        case AI_STATE_CLEFT_21:
            N(CleftAI_21)(script, npcAISettings, volume);
            return ApiStatus_BLOCK;
        case AI_STATE_CLEFT_22:
            N(CleftAI_22)(script, npcAISettings, volume);
            return ApiStatus_BLOCK;
        case AI_STATE_CLEFT_40:
            N(CleftAI_40)(script, npcAISettings, volume);
            if (script->AI_TEMP_STATE != AI_STATE_CLEFT_41) {
                return ApiStatus_BLOCK;
            }
            // fallthrough
        case AI_STATE_CLEFT_41:
            N(CleftAI_41)(script, npcAISettings, volume);
            return ApiStatus_BLOCK;
        case AI_STATE_CLEFT_50:
            N(CleftAI_50)(script, npcAISettings, volume);
            // fallthrough
        case AI_STATE_CLEFT_51:
            N(CleftAI_51)(script, npcAISettings, volume);
            if (script->AI_TEMP_STATE != AI_STATE_CLEFT_52) {
                return ApiStatus_BLOCK;
            }
            // fallthrough
        case AI_STATE_CLEFT_52:
            N(CleftAI_52)(script, npcAISettings, volume);
            return ApiStatus_BLOCK;
    }

    return ApiStatus_BLOCK;
}
