#include "common.h"
#include "npc.h"
#include "effects.h"

ApiStatus N(UnkNpcAIMainFunc10)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings =(NpcAISettings*) evt_get_variable(script, *args);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 120.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        N(UnkFunc5)(npc, enemy, script, aiSettings);
        script->functionTemp[0] = 0;
    }
    npc->unk_AB = -2;

    if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
        if (enemy->unk_B4) {
            return ApiStatus_BLOCK;
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(BzzapAI_00)(script, aiSettings, territoryPtr);
        case 1:
            N(BzzapAI_01)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(BzzapAI_02)(script, aiSettings, territoryPtr);
        case 3:
            N(UnkFunc4)(script, aiSettings, territoryPtr);
            break;
        case 10:
            N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        case 11:
            N(SixFloatsFunc)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc13)(script, aiSettings, territoryPtr);
        case 13:
            N(BzzapAI_13)(script, aiSettings, territoryPtr);
            break;
        case 20:
            N(BzzapAI_20)(script, aiSettings, territoryPtr);
            break;
    }

    return ApiStatus_BLOCK;
}
