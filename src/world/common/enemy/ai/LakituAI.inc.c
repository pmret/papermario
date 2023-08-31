#include "common.h"
#include "npc.h"
#include "sprite/npc/Lakitu.h"

// required include args
#ifndef AI_LAKITU_FIRST_SPINY_ID
#error  AI_LAKITU_FIRST_SPINY_ID must be defined for LakituAI
#define AI_LAKITU_FIRST_SPINY_ID 0
#endif
#ifndef AI_LAKITU_LAST_SPINY_ID
#error  AI_LAKITU_LAST_SPINY_ID must be defined for LakituAI
#define AI_LAKITU_LAST_SPINY_ID 0
#endif

// prerequisites
#include "world/common/enemy/ai/FlyingAI.inc.c"

s32 N(LakituAI_GetAvailableSpiny)(void) {
    s32 npcID;

    for (npcID = AI_LAKITU_FIRST_SPINY_ID; npcID <= AI_LAKITU_LAST_SPINY_ID; npcID++) {
        if (get_enemy(npcID)->varTable[10] == 0) {
            return npcID;
        }
    }

    return -1;
}

void N(LakituAI_Wander)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, y, z, w;
    EffectInstance* emoteTemp;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 var1 = enemy->varTable[4];
    f32 var2 = enemy->varTable[3];
    f32 var3;

    temp_f22 = var1 / 100.0;
    temp_f24 = var2 / 100.0;
    if (npc->duration > 0) {
        npc->duration--;
    }
    var3 = enemy->varTable[1];
    temp_f20 = var3 / 100.0;

    x = npc->pos.x;
    y = npc->pos.y;
    z = npc->pos.z;
    w = 1000.0f;

    npc_raycast_down_sides(npc->collisionChannel, &x, &y, &z, &w);
    npc->pos.y = y + temp_f24 + (sin_deg(enemy->varTable[2]) * temp_f20);
    enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 12);

    if (aiSettings->playerSearchInterval >= 0) {
        if (script->functionTemp[1] <= 0) {
            script->functionTemp[1] = aiSettings->playerSearchInterval;
            if (basic_ai_check_player_dist(territory, enemy, aiSettings->alertRadius, aiSettings->alertOffsetDist, 0) != 0) {
                fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteTemp);
                ai_enemy_play_sound(npc, SOUND_AI_ALERT_A, SOUND_PARAM_MORE_QUIET);
                x = npc->pos.x;
                y = npc->pos.y;
                z = npc->pos.z;
                w = 1000.0f;
                npc_raycast_down_sides(npc->collisionChannel, &x, &y, &z, &w);
                npc->moveToPos.y = y + temp_f24;
                script->functionTemp[0] = 12;
                return;
            }
        }
        script->functionTemp[1]--;
    }

    if (is_point_within_region(enemy->territory->wander.wanderShape, enemy->territory->wander.centerPos.x,
                               enemy->territory->wander.centerPos.z, npc->pos.x, npc->pos.z, enemy->territory->wander.wanderSize.x,
                               enemy->territory->wander.wanderSize.z) != 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.centerPos.x, enemy->territory->wander.centerPos.z);
    }

    if (npc->turnAroundYawAdjustment == 0) {
        if (npc->duration > 0) {
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            if (enemy->varTable[0] & 1) {
                x = npc->pos.x;
                y = temp_f22;
                z = npc->pos.z;
                w = 1000.0f;
                npc_raycast_down_sides(npc->collisionChannel, &x, &y, &z, &w);
                y += temp_f24;
                w = y - temp_f22;
                if (w > 2.0) {
                    temp_f22 += 2.0;
                } else if (w < -2.0) {
                    temp_f22 -= 2.0;
                } else {
                    temp_f22 = y;
                }
                enemy->varTable[4] = (temp_f22 * 100.0);
            }
            if (npc->duration > 0) {
                return;
            }
        }
        script->functionTemp[0] = 2;
        script->functionTemp[1] = (rand_int(1000) % 3) + 2;
        if ((aiSettings->unk_AI_2C <= 0) || (aiSettings->moveTime <= 0) || (script->functionTemp[1] == 0)) {
            script->functionTemp[0] = 0;
        }
    }
}

void N(LakituAI_Loiter)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, hitDepth;
    EffectInstance* emoteTemp;
    f32 var1 = enemy->varTable[3];
    f32 var2;
    f32 temp_f20;
    f32 temp_f22;

    temp_f22 = var1 / 100.0;
    if (npc->duration > 0) {
        npc->duration--;
    }
    var2 = enemy->varTable[1];
    temp_f20 = var2 / 100.0;

    posX = npc->pos.x;
    posY = npc->pos.y;
    posZ = npc->pos.z;
    hitDepth = 1000.0f;

    npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &hitDepth);
    npc->pos.y = posY + temp_f22 + (sin_deg(enemy->varTable[2]) * temp_f20);
    enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 12);
    if (basic_ai_check_player_dist(territory, enemy, aiSettings->chaseRadius, aiSettings->chaseOffsetDist, 1) != 0) {
        fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteTemp);
        ai_enemy_play_sound(npc, SOUND_AI_ALERT_A, SOUND_PARAM_MORE_QUIET);
        script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
        return;
    }

    if ((npc->turnAroundYawAdjustment == 0) && (npc->duration <= 0)) {
        script->functionTemp[1]--;
        if (script->functionTemp[1] > 0) {
            npc->yaw = clamp_angle(npc->yaw + 180.0f);
            npc->duration = (rand_int(1000) % 11) + 5;
            return;
        }
        script->AI_TEMP_STATE = AI_STATE_WANDER_INIT;
    }
}

API_CALLABLE(N(LakituAI_Main)) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    MobileAISettings* aiSettings = (MobileAISettings*)evt_get_variable(script, *args);
    Enemy* spinyEnemy;

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
        script->AI_TEMP_STATE = AI_STATE_WANDER_INIT;
    }
    npc->verticalRenderOffset = -3;

    if (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND) {
        if (enemy->aiSuspendTime != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAG_SUSPEND;
    }

    switch (script->AI_TEMP_STATE) {
        case AI_STATE_WANDER_INIT:
            N(FlyingAI_WanderInit)(script, aiSettings, territoryPtr);
            // fallthrough
        case AI_STATE_WANDER:
            N(LakituAI_Wander)(script, aiSettings, territoryPtr);
            break;
        case AI_STATE_LOITER_INIT:
            N(FlyingAI_LoiterInit)(script, aiSettings, territoryPtr);
            // fallthrough
        case AI_STATE_LOITER:
            N(LakituAI_Loiter)(script, aiSettings, territoryPtr);
            break;
    }

    if (script->AI_TEMP_STATE == AI_STATE_CHASE_INIT) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
        enemy->varTable[4] = N(LakituAI_GetAvailableSpiny)();
        if (enemy->varTable[4] >= 0) {
            spinyEnemy = get_enemy(enemy->varTable[4]);
            spinyEnemy->varTable[10] = 1;
            spinyEnemy->varTable[11] = enemy->npcID;
            npc->duration = 15;
            npc->curAnim = ANIM_Lakitu_Anim14;
            script->AI_TEMP_STATE = 30;
        }
    }

    switch (script->AI_TEMP_STATE) {
        case AI_STATE_CHASE_INIT:
            N(FlyingAI_ChaseInit)(script, aiSettings, territoryPtr);
            // fallthrough
        case AI_STATE_CHASE:
            N(FlyingAI_Chase)(script, aiSettings, territoryPtr);
            break;
        case AI_STATE_LOSE_PLAYER:
            N(FlyingAI_LosePlayer)(script, aiSettings, territoryPtr);
            break;
    }

    switch (script->AI_TEMP_STATE) {
        case AI_STATE_PROJECTILE_HITBOX_30:
            npc->duration--;
            if (npc->duration > 0) {
                break;
            }
            spinyEnemy = get_enemy(enemy->varTable[4]);
            spinyEnemy->varTable[10] = 2;
            npc->duration = 5;
            script->AI_TEMP_STATE = AI_STATE_PROJECTILE_HITBOX_31;
            // fallthrough
        case AI_STATE_PROJECTILE_HITBOX_31:
            npc->duration--;
            if (npc->duration > 0) {
                break;
            }
            npc->curAnim = ANIM_Lakitu_Anim15;
            spinyEnemy = get_enemy(enemy->varTable[4]);
            spinyEnemy->varTable[10] = 3;
            npc->duration = 10;
            script->AI_TEMP_STATE = AI_STATE_PROJECTILE_HITBOX_32;
            // fallthrough
        case AI_STATE_PROJECTILE_HITBOX_32:
            npc->duration--;
            if (npc->duration > 0) {
                break;
            }
            npc->duration = 3;
            script->AI_TEMP_STATE = AI_STATE_PROJECTILE_HITBOX_33;
            // fallthrough
        case AI_STATE_PROJECTILE_HITBOX_33:
            npc->duration--;
            if (npc->duration <= 0) {
                script->AI_TEMP_STATE = AI_STATE_WANDER_INIT;
            }
            break;
    }

    if (script->AI_TEMP_STATE == AI_STATE_PROJECTILE_HITBOX_30 || script->AI_TEMP_STATE == AI_STATE_PROJECTILE_HITBOX_31) {
        f32 playerDist;
        f32 lerpDist;

        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
        playerDist = dist2D(gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z, npc->pos.x, npc->pos.z);
        if (!is_point_within_region(territoryPtr->shape,
                territoryPtr->pointX, territoryPtr->pointZ,
                npc->pos.x, npc->pos.z,
                territoryPtr->sizeX, territoryPtr->sizeZ)) {
            if ((playerDist > 30.0) && (npc->turnAroundYawAdjustment == 0)) {
                lerpDist = playerDist - 20.0;
                if (lerpDist < 0.0) {
                    lerpDist = 0.0f;
                }
                if (lerpDist > 200.0) {
                    lerpDist = 200.0f;
                }
                npc->moveSpeed = update_lerp(EASING_LINEAR, aiSettings->moveSpeed, aiSettings->chaseSpeed, lerpDist, 200);
                npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            }
        }
    }

    return ApiStatus_BLOCK;
}

