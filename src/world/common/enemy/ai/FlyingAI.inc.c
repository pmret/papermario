// This AI is used by:
// - Paragoomba + variants
// - Paratroopa + variants
// - Sky Guy
// - Bzzap

#ifndef _AI_FLYING_INC_
#define _AI_FLYING_INC_ 0

#include "common.h"
#include "npc.h"
#include "effects.h"

f32 N(FlyingAI_JumpVels)[] = {
    4.5, 3.5, 2.6, 2.0, 1.5, 20.0,
};

void N(FlyingAI_WanderInit)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = aiSettings->moveTime / 2 + rand_int(aiSettings->moveTime / 2 + 1);
    if (is_point_within_region(enemy->territory->wander.wanderShape,
            enemy->territory->wander.centerPos.x, enemy->territory->wander.centerPos.z,
            npc->pos.x, npc->pos.z,
            enemy->territory->wander.wanderSize.x, enemy->territory->wander.wanderSize.z)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.centerPos.x, enemy->territory->wander.centerPos.z);
    } else {
        npc->yaw = clamp_angle((npc->yaw + rand_int(60)) - 30.0f);
    }
    npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_WALK];
    script->functionTemp[1] = 0;
    if (enemy->territory->wander.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
    }
    enemy->varTable[4] = npc->pos.y * 100.0;
    script->functionTemp[0] = AI_STATE_WANDER;
}

void N(FlyingAI_Wander)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 cond = FALSE;
    f32 vt7 = (f32)enemy->varTable[7] / 100.0;
    f32 vt3 = (f32)enemy->varTable[3] / 100.0;
    f32 vt4 = (f32)enemy->varTable[4] / 100.0;
    f32 vt1 = (f32)enemy->varTable[1] / 100.0;
    f32 posX, posY, posZ, posW;
    f32 temp_f24;

    enemy->varTable[4] = npc->pos.y * 100.0;

    temp_f24 = vt3 + vt7;

    if ((enemy->varTable[0] & 0x11) == 1) {
        if (npc->flags & NPC_FLAG_FLYING) {
            if (vt1 < temp_f24 - npc->pos.y) {
                enemy->varTable[0] |= 0x10;
            }
        } else {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &posW);
            if (vt1 < (vt3 - posW)) {
                enemy->varTable[0] |= 0x10;
            }
        }
    }

    if ((enemy->varTable[0] & 0x11) == 0x11) {
        f64 test;
        f32 yTemp;

        do {
            if (npc->flags & NPC_FLAG_FLYING) {
                yTemp = temp_f24;
                test = vt4 + ((temp_f24 - vt4) * 0.09);
                npc->pos.y = test;
            } else {
                posX = npc->pos.x;
                posY = vt4;
                posZ = npc->pos.z;
                posW = 1000.0f;
                npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &posW);

                yTemp = posY;
                yTemp += vt3;
                test = vt4 + ((yTemp - vt4) * 0.09);
                npc->pos.y = test;
            }

            if (fabsf(yTemp - npc->pos.y) < 1.0) {
                npc->pos.y = yTemp;
                enemy->varTable[0] &= ~0x10;
            }
        } while (0); // required to match
    } else {
        f32 vt1temp = vt1; // required to match

        if (enemy->varTable[1] > 0) {
            f32 sinTemp = sin_deg(enemy->varTable[2]);
            s32 hit;

            if (npc->flags & NPC_FLAG_FLYING) {
                hit = FALSE;
            } else {
                posX = npc->pos.x;
                posY = npc->pos.y;
                posZ = npc->pos.z;
                posW = 1000.0f;
                hit = npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &posW);
            }

            if (hit) {
                npc->pos.y = posY + vt3 + (sinTemp * vt1temp);
            } else {
                npc->pos.y = temp_f24 + (sinTemp * vt1temp);
            }

            enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 10);
        }
    }

    if (enemy->varTable[9] <= 0) {
        if (aiSettings->playerSearchInterval >= 0) {
            if (script->functionTemp[1] <= 0) {
                script->functionTemp[1] = aiSettings->playerSearchInterval;
                if (gPlayerStatusPtr->pos.y < (npc->pos.y + npc->collisionHeight) + 10.0 &&
                    basic_ai_check_player_dist(territory, enemy, aiSettings->alertRadius, aiSettings->alertOffsetDist, 0) != 0)
                {
                    EffectInstance* emoteTemp;
                    fx_emote(EMOTE_EXCLAMATION, npc, 0, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xC, &emoteTemp);
                    npc->moveToPos.y = npc->pos.y;
                    ai_enemy_play_sound(npc, SOUND_AI_ALERT_A, SOUND_PARAM_MORE_QUIET);

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
    } else {
        enemy->varTable[9]--;
    }

    if (is_point_within_region(enemy->territory->wander.wanderShape,
                               enemy->territory->wander.centerPos.x,
                               enemy->territory->wander.centerPos.z,
                               npc->pos.x, npc->pos.z,
                               enemy->territory->wander.wanderSize.x, enemy->territory->wander.wanderSize.z)) {
        posW = dist2D(enemy->territory->wander.centerPos.x, enemy->territory->wander.centerPos.z, npc->pos.x, npc->pos.z);
        if (npc->moveSpeed < posW) {
            npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.centerPos.x, enemy->territory->wander.centerPos.z);
            cond = TRUE;
        }
    }

    if (enemy->territory->wander.wanderSize.x | enemy->territory->wander.wanderSize.z | cond) {
        if (npc->turnAroundYawAdjustment != 0) {
            return;
        }
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }

    enemy->varTable[4] = npc->pos.y * 100.0;
    if (aiSettings->moveTime > 0) {
        if ((npc->duration <= 0) || (--npc->duration <= 0)) {
            script->AI_TEMP_STATE = AI_STATE_LOITER_INIT;
            script->functionTemp[1] = (rand_int(1000) % 3) + 2;
            if (aiSettings->unk_AI_2C <= 0 || aiSettings->waitTime <= 0 || script->functionTemp[1] < 3) {
                script->AI_TEMP_STATE = AI_STATE_WANDER_INIT;
            }
        }
    }
}

void N(FlyingAI_LoiterInit)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = (aiSettings->waitTime / 2) + rand_int((aiSettings->waitTime / 2) + 1);
    npc->yaw = clamp_angle(npc->yaw + rand_int(180) - 90.0f);
    npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
    script->functionTemp[0] = 3;
}

void N(FlyingAI_Loiter)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 hoverHeight = (f32)enemy->varTable[3] / 100.0;
    f32 temp_f26 = hoverHeight + (f32)((f32)enemy->varTable[7] / 100.0);
    EffectInstance* var;

    if (npc->duration > 0) {
        npc->duration--;
    }

    if (enemy->varTable[1] > 0) {
        f32 undulateAmplitude = (f32)enemy->varTable[1] / 100.0;
        f32 undulateAmount = sin_deg(enemy->varTable[2]);
        s32 hitResult;

        if (npc->flags & NPC_FLAG_FLYING) {
            hitResult = FALSE;
        } else {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            hitResult = npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &posW);
        }

        if (hitResult) {
            npc->pos.y = posY + hoverHeight + (undulateAmount * undulateAmplitude);
        } else {
            npc->pos.y = temp_f26 + (undulateAmount * undulateAmplitude);
        }

        enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 10);
    }

    if (enemy->varTable[9] <= 0) {
        if ((gPlayerStatusPtr->pos.y < npc->pos.y + npc->collisionHeight + 10.0)
            && basic_ai_check_player_dist(territory, enemy, aiSettings->chaseRadius, aiSettings->chaseOffsetDist, 1)) {
            fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
            npc->moveToPos.y = npc->pos.y;
            ai_enemy_play_sound(npc, SOUND_AI_ALERT_A, SOUND_PARAM_MORE_QUIET);
            if (enemy->npcSettings->actionFlags & AI_ACTION_JUMP_WHEN_SEE_PLAYER) {
                script->AI_TEMP_STATE = AI_STATE_ALERT_INIT;
            } else {
                script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
            }
            return;
        }
    } else {
        enemy->varTable[9]--;
    }

    if ((npc->turnAroundYawAdjustment == 0) && (npc->duration <= 0)) {
        script->functionTemp[1]--;
        if (script->functionTemp[1] > 0) {
            if (!(enemy->npcSettings->actionFlags & AI_ACTION_LOOK_AROUND_DURING_LOITER)) {
                npc->yaw = clamp_angle(npc->yaw + 180.0f);
            }
            npc->duration = (rand_int(1000) % 11) + 5;
        } else {
            script->AI_TEMP_STATE = AI_STATE_WANDER_INIT;
        }
    }
}

void N(FlyingAI_JumpInit)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    PlayerStatus* playerStatus = gPlayerStatusPtr;

    npc->duration = 0;
    npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->pos.x, playerStatus->pos.z);
    npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_MELEE_PRE];
    script->functionTemp[0] = AI_STATE_ALERT;
}

void N(FlyingAI_Jump)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->pos.y += N(FlyingAI_JumpVels)[npc->duration++];
    if (npc->duration >= 5) {
        script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
    }
}

void N(FlyingAI_ChaseInit)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 jumpVel = (f32)enemy->varTable[5] / 100.0;
    f32 jumpScale = (f32)enemy->varTable[6] / 100.0;

    npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_MELEE_PRE];
    npc->jumpVel = jumpVel;
    npc->jumpScale = jumpScale;
    npc->moveSpeed = aiSettings->chaseSpeed;
    npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);

    enemy->varTable[2] = 0;

    if (enemy->npcSettings->actionFlags & AI_ACTION_02) {
        npc->duration = 3;
        script->AI_TEMP_STATE = AI_STATE_CHASE;
    } else {
        npc->duration = 1;
        script->AI_TEMP_STATE = AI_STATE_LOSE_PLAYER;
        enemy->unk_10.x = npc->pos.x;
        enemy->unk_10.y = npc->pos.y;
        enemy->unk_10.z = npc->pos.z;
        enemy->hitboxIsActive = TRUE;
    }
}

void N(FlyingAI_Chase)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    if ((npc->duration <= 0) || (--npc->duration <= 0)) {
        if (npc->turnAroundYawAdjustment == 0) {
            npc->duration = 0;
            script->AI_TEMP_STATE = AI_STATE_LOSE_PLAYER;
        }
    }
}

void N(FlyingAI_LosePlayer)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 deltaAngle;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f2;
    s32 hitBelow;
    f32 angle;
    f32 a = enemy->varTable[3];
    f32 b = enemy->varTable[7];

    npc->jumpVel += npc->jumpScale;
    temp_f20 = a / 100.0;
    temp_f22 = b / 100.0;
    npc_move_heading(npc, npc->moveSpeed, npc->yaw);

    if (npc->jumpVel >= 0.0) {
        npc->pos.y += npc->jumpVel;
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_MELEE_HIT];
        enemy->hitboxIsActive = FALSE;
        if (!(npc->flags & NPC_FLAG_FLYING)) {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            hitBelow = npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &posW);
        } else {
            hitBelow = FALSE;
        }
        if (hitBelow) {
            temp_f2 = posY + temp_f20;
            if (temp_f2 <= npc->pos.y) {
                npc->pos.y = temp_f2;
                script->functionTemp[0] = 0;
            }
        } else if (npc->pos.y >= npc->moveToPos.y) {
            script->functionTemp[0] = 0;
        }
    } else if (npc->jumpVel < 0.0) {
        npc->duration++;
        if (npc->duration >= aiSettings->chaseUpdateInterval) {
            npc->duration = 0;
            angle = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
            deltaAngle = get_clamped_angle_diff(npc->yaw, angle);
            if (aiSettings->chaseTurnRate < fabsf(deltaAngle)) {
                angle = npc->yaw;
                if (deltaAngle < 0.0f) {
                    angle += -aiSettings->chaseTurnRate;
                } else {
                    angle += aiSettings->chaseTurnRate;
                }
            }
            npc->yaw = clamp_angle(angle);
        }

        if (npc->flags & NPC_FLAG_FLYING) {
            if (npc->pos.y + npc->jumpVel < temp_f22) {
                npc->pos.y = temp_f22;
                npc->jumpVel = 0.0f;
            } else {
                npc->pos.y += npc->jumpVel;
            }
            return;
        }

        posX = npc->pos.x;
        posY = npc->pos.y + npc->collisionHeight;
        posZ = npc->pos.z;
        posW = (fabsf(npc->jumpVel) + npc->collisionHeight) + 10.0;
        if (npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &posW)) {
            if (posW <= (npc->collisionHeight + fabsf(npc->jumpVel))) {
                npc->jumpVel = 0.0f;
                npc->pos.y = posY;
            } else {
                npc->pos.y += npc->jumpVel;
            }
            return;
        } else if (fabsf(npc->jumpVel) < ((npc->pos.y - temp_f22) + npc->collisionHeight)) {
            npc->pos.y = npc->pos.y + npc->jumpVel;
            return;
        }
        npc->jumpVel = 0.0f;
    }
}

void N(FlyingAI_Init)(Npc* npc, Enemy* enemy, Evt* script, MobileAISettings* aiSettings) {
    f32 posX, posY, posZ, depth;

    script->functionTemp[0] = 0;
    npc->duration = 0;

    npc->flags &= ~NPC_FLAG_GRAVITY;
    npc->flags |= NPC_FLAG_JUMPING;
    if (enemy->territory->wander.isFlying) {
        npc->flags |= NPC_FLAG_FLYING;
    } else {
        npc->flags &= ~NPC_FLAG_FLYING;
    }

    posX = npc->pos.x;
    posY = npc->pos.y;
    posZ = npc->pos.z;
    depth = 1000.0f;
    npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &depth);
    enemy->varTable[2] = 0;
    enemy->varTable[9] = 0;
    enemy->varTable[3] = (depth * 100.0) + 0.5;
    enemy->varTable[7] = (posY * 100.0) + 0.5;
    script->functionTemp[1] = aiSettings->playerSearchInterval;
    enemy->aiFlags |= ENEMY_AI_FLAG_10;
}

API_CALLABLE(N(FlyingAI_Main)) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    MobileAISettings* aiSettings = (MobileAISettings*) evt_get_variable(script, *args);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detectPos.x;
    territory.pointZ = enemy->territory->wander.detectPos.z;
    territory.sizeX = enemy->territory->wander.detectSize.x;
    territory.sizeZ = enemy->territory->wander.detectSize.z;
    territory.halfHeight = 120.0f;
    territory.detectFlags = 0;

    #ifdef _DEAD_H_
    enemy->unk_108.x = npc->pos.x;
    enemy->unk_108.y = npc->pos.y;
    enemy->unk_108.z = npc->pos.z;
    enemy->unk_114 = 0.0001f;
    enemy->unk_118 = 0.0001f;
    #endif

    if (isInitialCall) {
        #ifdef _DEAD_H_
        N(FlyingAI_Init)(npc, (Enemy*)enemy, script, aiSettings);
        #else
        N(FlyingAI_Init)(npc, enemy, script, aiSettings);
        #endif
    }

    npc->verticalRenderOffset = -2;

    if (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND) {
        if (enemy->aiSuspendTime != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAG_SUSPEND;
    }

    switch (script->AI_TEMP_STATE) {
        case AI_STATE_WANDER_INIT:
            N(FlyingAI_WanderInit)(script, aiSettings, territoryPtr);
        case AI_STATE_WANDER:
            N(FlyingAI_Wander)(script, aiSettings, territoryPtr);
            break;
        case AI_STATE_LOITER_INIT:
            N(FlyingAI_LoiterInit)(script, aiSettings, territoryPtr);
        case AI_STATE_LOITER:
            N(FlyingAI_Loiter)(script, aiSettings, territoryPtr);
            break;
        case AI_STATE_ALERT_INIT:
            N(FlyingAI_JumpInit)(script, aiSettings, territoryPtr);
        case AI_STATE_ALERT:
            N(FlyingAI_Jump)(script, aiSettings, territoryPtr);
            break;
        case AI_STATE_CHASE_INIT:
            N(FlyingAI_ChaseInit)(script, aiSettings, territoryPtr);
            break;
        case AI_STATE_CHASE:
            N(FlyingAI_Chase)(script, aiSettings, territoryPtr);
            break;
        case AI_STATE_LOSE_PLAYER:
            N(FlyingAI_LosePlayer)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}

#endif
