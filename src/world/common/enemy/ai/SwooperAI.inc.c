#include "common.h"
#include "npc.h"

API_CALLABLE(N(SwooperAI_Main)) {
    EnemyDetectVolume detectVolume;
    PlayerStatus* playerStatus = &gPlayerStatus;
    EnemyDetectVolume* detectVolumePtr = &detectVolume;
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    MobileAISettings* aiSettings = (MobileAISettings*)evt_get_variable(script, *args++);
    f32 x, y, z, hitDepth;
    f32 y2;

    detectVolumePtr->skipPlayerDetectChance = 0;
    detectVolumePtr->shape = enemy->territory->wander.detectShape;
    detectVolumePtr->pointX = enemy->territory->wander.detectPos.x;
    detectVolumePtr->pointZ = enemy->territory->wander.detectPos.z;
    detectVolumePtr->sizeX = enemy->territory->wander.detectSize.x;
    detectVolumePtr->sizeZ = enemy->territory->wander.detectSize.z;
    detectVolumePtr->halfHeight = 500.0f;
    detectVolumePtr->detectFlags = 0;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        enemy->aiFlags |= ENEMY_AI_FLAG_10;
        hitDepth = 1000.0f;
        x = npc->pos.x;
        y = npc->pos.y;
        z = npc->pos.z;
        npc_raycast_down_sides(npc->collisionChannel, &x, &y, &z, &hitDepth);
        enemy->varTable[1] = y;
    }

    if (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND) {
        if (enemy->aiSuspendTime == 0) {
            enemy->aiFlags &= ~ENEMY_AI_FLAG_SUSPEND;
        } else {
            return ApiStatus_BLOCK;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            npc->currentAnim = enemy->animList[0];
            npc->verticalRenderOffset = npc->collisionHeight;
            npc->flags |= NPC_FLAG_UPSIDE_DOWN;
            script->functionTemp[1] = 0;
            script->functionTemp[0] = 1;
        case 1:
            if (aiSettings->playerSearchInterval >= 0) {
                if (script->functionTemp[1] <= 0) {
                    script->functionTemp[1] = aiSettings->playerSearchInterval;
                    if (basic_ai_check_player_dist(detectVolumePtr, enemy, aiSettings->alertRadius, aiSettings->alertOffsetDist, 0) != 0) {
                        ai_enemy_play_sound(npc, SOUND_2F4, SOUND_PARAM_MORE_QUIET);
                        script->functionTemp[0] = 10;
                    }
                }
                script->functionTemp[1]--;
            }
            if (script->functionTemp[0] != 10) {
                break;
            }
        case 10:
            npc->currentAnim = enemy->animList[3];
            npc->planarFlyDist = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
            npc->jumpScale = 1.3f;
            npc->jumpVelocity = 0.0f;
            npc->moveSpeed = aiSettings->moveSpeed;
            x = npc->pos.x;
            y = npc->pos.y;
            z = npc->pos.z;
            hitDepth = 1000.0f;
            if (npc_raycast_down_sides(npc->collisionChannel, &x, &y, &z, &hitDepth) != 0) {
                y = enemy->varTable[1];
                npc->moveToPos.y = y + ((npc->pos.y - y) * 0.7);
            } else {
                npc->moveToPos.y = playerStatus->position.y + ((npc->pos.y - playerStatus->position.y) * 0.7);
            }
            npc->moveToPos.z = npc->pos.y;
            script->functionTemp[0] = 11;
        case 11:
            if (npc->moveSpeed > 0.0) {
                x = npc->pos.x;
                y = npc->pos.y;
                z = npc->pos.z;
                if (npc_test_move_simple_with_slipping(npc->collisionChannel, &x, &y, &z, npc->moveSpeed, npc->yaw, npc->collisionHeight, npc->collisionDiameter)) {
                    npc->moveSpeed = 0.0f;
                }
                npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
                npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            }

            npc->jumpVelocity -= npc->jumpScale;
            npc->pos.y += npc->jumpVelocity;
            if (npc->pos.y < npc->moveToPos.y) {
                npc->pos.y = npc->moveToPos.y;
                script->functionTemp[0] = 12;
            } else {
                break;
            }
        case 12:
            npc->planarFlyDist = dist2D(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
            if (npc->planarFlyDist < 60.0f) {
                npc->planarFlyDist = 60.0f;
            }

            y = enemy->varTable[1];
            y2 = (y + 10.0) - npc->pos.y;

            npc->moveSpeed = aiSettings->chaseSpeed;
            npc->duration = npc->planarFlyDist / npc->moveSpeed;
            if (npc->duration == 0) {
                npc->duration = 1;
            }
            npc->jumpScale = -fabsf(-(2.0f * ((-npc->jumpVelocity * npc->duration) + y2)) / SQ(npc->duration));
            npc->verticalRenderOffset = 0;
            npc->flags &= ~NPC_FLAG_UPSIDE_DOWN;
            enemy->varTable[0] = 5;
            npc->duration = 0;
            script->functionTemp[0] = 13;
        case 13:
            npc->jumpVelocity -= npc->jumpScale;
            if (npc->jumpVelocity < 0.0f) {
                x = npc->pos.x;
                y = npc->pos.y;
                z = npc->pos.z;
                hitDepth = -npc->jumpVelocity;
                if (npc_raycast_down_sides(npc->collisionChannel, &x, &y, &z, &hitDepth) != 0) {
                    npc->jumpVelocity = 0.0f;
                }
            }

            npc->pos.y += npc->jumpVelocity;
            if (npc->moveSpeed > 0.0) {
                x = npc->pos.x;
                y = npc->pos.y;
                z = npc->pos.z;
                if (npc_test_move_simple_with_slipping(npc->collisionChannel, &x, &y, &z, npc->moveSpeed, npc->yaw,
                                                       npc->collisionHeight, npc->collisionDiameter) != 0)
                {
                    npc->moveSpeed = 0.0f;
                } else if (npc->jumpVelocity < -2.5) {
                    npc->duration++;
                    if (npc->duration >= aiSettings->chaseUpdateInterval) {
                        f32 yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
                        f32 angleDiff = get_clamped_angle_diff(npc->yaw, yaw);

                        if (aiSettings->chaseTurnRate < fabsf(angleDiff)) {
                            yaw = npc->yaw;
                            if (angleDiff < 0.0f) {
                                yaw += -aiSettings->chaseTurnRate;
                            } else {
                                yaw += aiSettings->chaseTurnRate;
                            }
                        }
                        npc->yaw = clamp_angle(yaw);
                        npc->duration = 0;
                    }
                }
                npc_move_heading(npc, npc->moveSpeed, npc->yaw);
            }
            enemy->varTable[0]--;
            if (enemy->varTable[0] <= 0) {
                enemy->varTable[0] = 5;
            }

            if (npc->pos.y > npc->moveToPos.z) {
                npc->pos.y = npc->moveToPos.z;
                script->functionTemp[0] = 14;
            } else {
                break;
            }
        case 14:
            npc->currentAnim = enemy->animList[8];
            npc->verticalRenderOffset = npc->collisionHeight;
            npc->flags |= NPC_FLAG_UPSIDE_DOWN;
            npc->duration = 15;
            script->functionTemp[0] = 15;
        case 15:
            npc->duration--;
            if (npc->duration <= 0) {
                script->functionTemp[0] = 0;
            }
    }
    return ApiStatus_BLOCK;
}
