#include "common.h"
#include "npc.h"

#include "world/common/enemy/ai/MagikoopaSpellAI.inc.c"

void N(FlyingMagikoopaAI_10)(Evt* script, MobileAISettings* arg1, EnemyDetectVolume* arg2) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = 30;
    script->AI_TEMP_STATE = 11;
}

void N(FlyingMagikoopaAI_11)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* volume) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 basePosY = (f32)enemy->varTable[1] / 100.0;
    EffectInstance* emoteTemp;

    npc->pos.y = basePosY + sin_deg(enemy->varTable[0]) * 6.0;
    enemy->varTable[0] = clamp_angle(enemy->varTable[0] + 10);

    if (N(MagikoopaAI_CanShootSpell)(script, aiSettings->chaseRadius, aiSettings->chaseOffsetDist, volume) == 1) {
        fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteTemp);
        ai_enemy_play_sound(npc, SOUND_AI_ALERT_A, SOUND_PARAM_MORE_QUIET);
        npc->duration = 50;
        script->AI_TEMP_STATE = 20;
    } else {
        npc->duration--;
        if (npc->duration <= 0) {
            npc->duration = 5;
            script->AI_TEMP_STATE = 15;
        }
    }
}

enum MagikoopaMoveResult {
    RESULT_SEARCHING       = 0,
    RESULT_OK_BLOCKED      = 1,
    RESULT_OK_CLEAR        = 2,
    RESULT_NONE_FOUND      = 3
};

void N(FlyingMagikoopaAI_15)(Evt* arg0, MobileAISettings* arg1, EnemyDetectVolume* arg2) {
    f32 dist;
    f32 distToHit;
    f32 randomDist;
    f32 baseYaw;
    s32 isCCW;
    f32 moveDist;
    s32 angleAdjust;

    Enemy* enemy = arg0->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ;
    s32 result = RESULT_SEARCHING;
    s32 iterations = 0;

    npc->duration--;
    if (npc->duration <= 0) {
        randomDist = rand_int(30) + 180.0;
        isCCW = FALSE;
        if (is_point_outside_territory(enemy->territory->wander.wanderShape, enemy->territory->wander.centerPos.x, enemy->territory->wander.centerPos.z, npc->pos.x, npc->pos.z, enemy->territory->wander.wanderSize.x, enemy->territory->wander.wanderSize.z)) {
            npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.centerPos.x, enemy->territory->wander.centerPos.z) - iterations;
            moveDist = dist2D(npc->pos.x, npc->pos.z, enemy->territory->wander.centerPos.x, enemy->territory->wander.centerPos.z);
            if (randomDist > moveDist) {
                randomDist = moveDist;
            }
        } else {
            npc->yaw  = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
            if (npc->yaw  < 180.0) {
                baseYaw = (rand_int(10) + 90.0) - 5.0;
            } else {
                baseYaw = (rand_int(10) + 270.0) - 5.0;
            }
            angleAdjust = iterations * 5;
            while (TRUE) {
                if (isCCW) {
                    npc->yaw = baseYaw + angleAdjust;
                } else {
                    npc->yaw = baseYaw - angleAdjust;
                }
                posX = npc->pos.x;
                posY = npc->pos.y;
                posZ = npc->pos.z;
                if (npc_test_move_taller_with_slipping(0, &posX, &posY, &posZ,
                        randomDist, npc->yaw, npc->collisionHeight, npc->collisionDiameter)) {
                    moveDist = dist2D(npc->pos.x, npc->pos.z, posX, posZ);
                    distToHit = moveDist;
                    if (distToHit > 160.0) {
                        if (distToHit < randomDist) {
                            randomDist = distToHit;
                        }
                        result = RESULT_OK_BLOCKED;
                    }
                } else {
                    result = RESULT_OK_CLEAR;
                }

                if (result != RESULT_SEARCHING) {
                    break;
                }

                if (!isCCW) {
                    isCCW = TRUE;
                } else {
                    angleAdjust += 5;
                    iterations++;
                    isCCW = FALSE;
                }

                if (iterations >= 7) {
                    result = RESULT_NONE_FOUND;
                }
            }
        }
        posX = npc->pos.x;
        posZ = npc->pos.z;
        add_vec2D_polar(&posX, &posZ, randomDist, npc->yaw);
        npc->moveToPos.x = posX;
        npc->moveToPos.y = npc->pos.y;
        npc->moveToPos.z = posZ;
        enemy->varTable[4] = npc->pos.x * 100.0;
        enemy->varTable[6] = npc->pos.z * 100.0;
        enemy->varTable[3] = rand_int(10) + 35;
        npc->duration = 0;
        npc->moveSpeed = 3.0f;
        npc->jumpVel = 1.4f;
        npc->jumpScale = 0.2f;
        arg0->functionTemp[0] = 0x10;
    }
}

void N(FlyingMagikoopaAI_16)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 basePosY = (f32)enemy->varTable[1] / 100.0;

    enemy->varTable[0] = clamp_angle(enemy->varTable[0] + 10);
    npc->pos.y = basePosY + sin_deg(enemy->varTable[0]) * 6.0;

    if (npc->turnAroundYawAdjustment == 0) {
        enemy->varTable[5] = npc->pos.y * 100.0;
        script->functionTemp[0] = 17;
    }
}

void N(FlyingMagikoopaAI_17)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 limitY = (f32)enemy->varTable[1] / 100.0;
    f32 basePosY = (f32)enemy->varTable[5] / 100.0;
    f32 startX = (f32)enemy->varTable[4] / 100.0;
    f32 startZ = (f32)enemy->varTable[6] / 100.0;
    f32 lerpX = update_lerp(EASING_SIN_OUT, startX, npc->moveToPos.x, npc->duration, enemy->varTable[3]);
    f32 lerpZ = update_lerp(EASING_SIN_OUT, startZ, npc->moveToPos.z, npc->duration, enemy->varTable[3]);

    npc->pos.x = lerpX;
    npc->pos.z = lerpZ;
    npc->pos.y = basePosY + sin_deg((s32)(npc->duration * (180.0 / (f32)enemy->varTable[3])) + 180) * 25.0;

    npc->duration++;
    if (npc->duration == (enemy->varTable[3] - 8)) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
    }
    if (limitY <= npc->pos.y) {
        npc->pos.y = limitY;
        enemy->varTable[0] = 0;
        script->functionTemp[0] = 10;
    } else if (npc->duration >= enemy->varTable[3]) {
        if (enemy->varTable[0] >= 180.0) {
            if (enemy->varTable[0] < 270.0) {
                enemy->varTable[0] = clamp_angle(540 - enemy->varTable[0]);
            }
        }
        script->functionTemp[0] = 10;
    }
}

void N(FlyingMagikoopaAI_20)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = 40;
    script->functionTemp[0] = 21;
}

void N(FlyingMagikoopaAI_21)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ;
    EffectInstance* emoteTemp;

    npc->duration--;
    if (npc->duration == 0) {
        npc->curAnim = enemy->animList[0];
        fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &emoteTemp);
        npc->curAnim = enemy->animList[0];
        npc->duration = 15;
        script->functionTemp[0] = 50;
    } else if ((N(MagikoopaAI_CanShootSpell)(script, aiSettings->chaseRadius, aiSettings->chaseOffsetDist, territory) == 1) && (npc->turnAroundYawAdjustment == 0)) {
        ai_enemy_play_sound(npc, 0x20D4, 0);
        npc->curAnim = enemy->animList[8];
        posX = npc->pos.x;
        posY = npc->pos.y + 29.0f;
        posZ = npc->pos.z + 1.0f;
        add_vec2D_polar(&posX, &posZ, 30.0f, 270.0f - npc->renderYaw);
        fx_gather_energy_pink(0, posX, posY, posZ, 0.1f, 13);
        npc->duration = 15;
        script->functionTemp[0] = 22;
    }
}

void N(FlyingMagikoopaAI_22)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->curAnim = enemy->animList[9];
        npc->duration = 7;
        script->functionTemp[0] = 0x17;
    }
}

void N(FlyingMagikoopaAI_23)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 temp_s1;
    EffectInstance* emoteTemp;

    npc->duration--;
    if (npc->duration <= 0) {
        temp_s1 = N(MagikoopaAI_CanShootSpell)(script, aiSettings->chaseRadius, aiSettings->chaseOffsetDist, territory);
        if (temp_s1 != 1) {
            fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &emoteTemp);
            npc->curAnim = enemy->animList[0];
            npc->duration = 15;
            script->functionTemp[0] =  50;
        } else {
            ai_enemy_play_sound(npc, SOUND_SPELL_CAST2, 0);
            get_enemy(enemy->npcID + 1)->varTable[0] = temp_s1;
            npc->duration = 20;
            script->functionTemp[0] = 24;
        }
    }
}

void N(FlyingMagikoopaAI_24)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 basePosY = (f32)enemy->varTable[1] / 100.0;

    npc->pos.y = basePosY + sin_deg(enemy->varTable[0]) * 6.0;
    enemy->varTable[0] = clamp_angle(enemy->varTable[0] + 10);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->curAnim = enemy->animList[0];
        npc->duration = 3;
        script->AI_TEMP_STATE = 50;
    }
}

void N(FlyingMagikoopaAI_50)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 basePosY = (f32)enemy->varTable[1] / 100.0;

    npc->pos.y = basePosY + sin_deg(enemy->varTable[0]) * 6.0;
    enemy->varTable[0] = clamp_angle(enemy->varTable[0] + 10);

    npc->duration--;
    if (npc->duration <= 0) {
        script->AI_TEMP_STATE = 10;
    }
}

API_CALLABLE(N(FlyingMagikoopaAI_Main)) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    MobileAISettings* aiSettings = (MobileAISettings*)evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detectPos.x;
    territory.pointZ = enemy->territory->wander.detectPos.z;
    territory.sizeX = enemy->territory->wander.detectSize.x;
    territory.sizeZ = enemy->territory->wander.detectSize.z;
    territory.halfHeight = 120.0f;
    territory.detectFlags = 0;

    if (isInitialCall) {
        npc->flags &= ~NPC_FLAG_GRAVITY;
        npc->flags |= NPC_FLAG_FLYING;
        npc->flags |= NPC_FLAG_FLIP_INSTANTLY;
        enemy->flags |= ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN;
        enemy->varTable[1] = npc->pos.y * 100.0;
        enemy->varTable[0] = 0;
        enemy->varTable[2] = 0;
        npc->duration = 0;
        script->AI_TEMP_STATE = 10;
    }

    npc->verticalRenderOffset = -5;

    if (enemy->aiFlags & AI_FLAG_SUSPEND) {
        if (enemy->aiSuspendTime != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->aiFlags &= ~AI_FLAG_SUSPEND;
    }

    switch (script->AI_TEMP_STATE) {
        case 10:
            N(FlyingMagikoopaAI_10)(script, aiSettings, territoryPtr);
            // fallthrough
        case 11:
            N(FlyingMagikoopaAI_11)(script, aiSettings, territoryPtr);
            break;
        case 15:
            N(FlyingMagikoopaAI_15)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != 16) {
                break;
            }
        case 16:
            N(FlyingMagikoopaAI_16)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != 17) {
                break;
            }
        case 17:
            N(FlyingMagikoopaAI_17)(script, aiSettings, territoryPtr);
            break;
        case 20:
            N(FlyingMagikoopaAI_20)(script, aiSettings, territoryPtr);
            break;
        case 21:
            N(FlyingMagikoopaAI_21)(script, aiSettings, territoryPtr);
            break;
        case 22:
            N(FlyingMagikoopaAI_22)(script, aiSettings, territoryPtr);
            break;
        case 23:
            N(FlyingMagikoopaAI_23)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != 24) {
                break;
            }
        case 24:
            N(FlyingMagikoopaAI_24)(script, aiSettings, territoryPtr);
            break;
        case 50:
            N(FlyingMagikoopaAI_50)(script, aiSettings, territoryPtr);
            break;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(FlyingMagikoopaAI_OnHitInit)) {
    Enemy* enemy = script->owner1.enemy;

    evt_set_variable(script, LVar0, gCurrentEncounter.curEnemy == enemy);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(FlyingMagikoopaAI_OnHit)) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (enemy->varTable[0] == 2) {
        npc->jumpVel = 0.0f;
        npc->moveSpeed = 0.0f;
    }
    return ApiStatus_DONE2;
}

