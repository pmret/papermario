#include "common.h"
#include "npc.h"
#include "effects.h"

#ifdef _DEAD_H_
#include "dead_structs.h"
#endif

ApiStatus N(FlyingAI_Main)(Evt* script, s32 isInitialCall) {
    #ifdef _DEAD_H_
    DeadEnemy* enemy = (DeadEnemy*)script->owner1.enemy;
    #else
    Enemy* enemy = script->owner1.enemy;
    #endif
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = (NpcAISettings*) evt_get_variable(script, *args);

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
    }

    npc->verticalRenderOffset = -2;

    if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
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
