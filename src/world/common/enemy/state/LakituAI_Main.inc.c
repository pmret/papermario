#include "common.h"
#include "npc.h"

#ifdef _DEAD_H_
#include "dead_structs.h"
#endif

s32 N(LakituAI_Main)(Evt* script, s32 isInitialCall) {
    #ifdef _DEAD_H_
    DeadEnemy* enemy = (DeadEnemy*)script->owner1.enemy;
    #else
    Enemy* enemy = script->owner1.enemy;
    #endif
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = (NpcAISettings*)evt_get_variable(script, *args);
    Enemy* spinyEnemy;

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 120.0f;
    territory.unk_1C = 0;

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

    if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
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
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        enemy->varTable[4] = N(LakituAI_GetAvailableSpiny)();
        if (enemy->varTable[4] >= 0) {
            spinyEnemy = get_enemy(enemy->varTable[4]);
            spinyEnemy->varTable[10] = 1;
            spinyEnemy->varTable[11] = enemy->npcID;
            npc->duration = 15;
            npc->currentAnim.w = 0x490014;
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
        case 30:
            npc->duration--;
            if (npc->duration > 0) {
                break;
            }
            spinyEnemy = get_enemy(enemy->varTable[4]);
            spinyEnemy->varTable[10] = 2;
            npc->duration = 5;
            script->AI_TEMP_STATE = 31;
            // fallthrough
        case 31:
            npc->duration--;
            if (npc->duration > 0) {
                break;
            }
            npc->currentAnim.w = 0x490015;
            spinyEnemy = get_enemy(enemy->varTable[4]);
            spinyEnemy->varTable[10] = 3;
            npc->duration = 10;
            script->AI_TEMP_STATE = 32;
            // fallthrough
        case 32:
            npc->duration--;
            if (npc->duration > 0) {
                break;
            }
            npc->duration = 3;
            script->AI_TEMP_STATE = 33;
            // fallthrough
        case 33:
            npc->duration--;
            if (npc->duration <= 0) {
                script->AI_TEMP_STATE = AI_STATE_WANDER_INIT;
            }
            break;
    }

    if ((script->AI_TEMP_STATE - 30) < 2U) {
        f32 playerDist;
        f32 lerpDist;
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        playerDist = dist2D(gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z, npc->pos.x, npc->pos.z);
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
