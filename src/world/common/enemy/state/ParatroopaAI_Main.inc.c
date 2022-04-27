#include "common.h"
#include "npc.h"

ApiStatus N(ParatroopaAI_Main)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = (NpcAISettings*)evt_get_variable(script, *args++);
    
    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 120.0f;
    territory.unk_1C = 0;
    
    if (isInitialCall != 0) {
        N(FlyingAI_Init)(npc, enemy, script, aiSettings);
        enemy->varTable[8] = npc->collisionHeight;
        script->AI_TEMP_STATE = 0;
    }

    npc->unk_AB = -3;

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
            N(FlyingAI_Wander)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != 2) {
                break;
            }
            // fallthrough
        case AI_STATE_LOITER_INIT:
            N(FlyingAI_LoiterInit)(script, aiSettings, territoryPtr);
            // fallthrough
        case AI_STATE_LOITER:
            N(FlyingAI_Loiter)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_ALERT_INIT) {
                break;
            }
            // fallthrough
        case AI_STATE_ALERT_INIT:
            N(FlyingAI_JumpInit)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_ALERT) {
                break;
            }
            // fallthrough
        case AI_STATE_ALERT:
            N(FlyingAI_Jump)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_CHASE_INIT) {
                break;
            }
            // fallthrough
        case AI_STATE_CHASE_INIT:
            N(ParatroopaAI_ChaseInit)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_CHASE) {
                break;
            }
            // fallthrough
        case AI_STATE_CHASE:
            N(ParatroopaAI_Chase)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_LOSE_PLAYER) {
                break;
            }
            // fallthrough
        case AI_STATE_LOSE_PLAYER:
            N(ParatroopaAI_LosePlayer)(script, aiSettings, territoryPtr);
            if (script->AI_TEMP_STATE != 0xF) {
                break;
            }
            // fallthrough
        case 15:
            N(ParatroopaAI_15)(script, aiSettings, territoryPtr);
            break;
    }
    return ApiStatus_BLOCK;
}
