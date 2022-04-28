#include "common.h"
#include "npc.h"
#include "effects.h"

ApiStatus N(FlyingNoAttackAI_Main)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    NpcAISettings* aiSettings =(NpcAISettings*) evt_get_variable(script, *args);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 120.0f;
    territory.detectFlags = 0;

    if (isInitialCall) {
        N(FlyingAI_Init)(npc, enemy, script, aiSettings);
        script->functionTemp[0] = 0;
    }
    npc->verticalRenderOffset = -2;

    if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
        if (enemy->aiPaused) {
            return ApiStatus_BLOCK;
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(FlyingAI_WanderInit)(script, aiSettings, territoryPtr);
        case 1:
            N(FlyingAI_Wander)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(FlyingAI_LoiterInit)(script, aiSettings, territoryPtr);
        case 3:
            N(FlyingAI_Loiter)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(FlyingAI_JumpInit)(script, aiSettings, territoryPtr);
        case 11:
            N(FlyingAI_Jump)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(FlyingNoAttackAI_12)(script, aiSettings, territoryPtr);
        case 13:
            N(FlyingNoAttackAI_13)(script, aiSettings, territoryPtr);
            break;
        case 20:
            N(FlyingNoAttackAI_20)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}
