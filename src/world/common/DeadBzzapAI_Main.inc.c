#include "common.h"
#include "npc.h"
#include "dead_structs.h"

ApiStatus N(DeadBzzapAI_Main)(Evt* script, s32 isInitialCall) {
    DeadEnemy* enemy = (DeadEnemy*)script->owner1.enemy;
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

    enemy->unk_108.x = npc->pos.x;
    enemy->unk_108.y = npc->pos.y;
    enemy->unk_108.z = npc->pos.z;
    enemy->unk_114 = 0.0001f;
    enemy->unk_118 = 0.0001f;

    if (isInitialCall) {
        N(UnkFunc5)(npc, (Enemy*)enemy, script, aiSettings);
    }

    npc->unk_AB = -2;

    if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
    }
    switch (script->functionTemp[0]) {
    case 0:
        N(BzzapAI_00)(script, aiSettings, territoryPtr);
        /* fallthrough */
    case 1:
        N(BzzapAI_01)(script, aiSettings, territoryPtr);
        return 0;
    case 2:
        N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
        /* fallthrough */
    case 3:
        N(UnkFunc4)(script, aiSettings, territoryPtr);
        return 0;
    case 10:
        N(UnkNpcAIFunc2)(script, aiSettings, territoryPtr);
        /* fallthrough */
    case 11:
        N(SixFloatsFunc)(script, aiSettings, territoryPtr);
        return 0;
    case 12:
        N(UnkNpcAIFunc14)(script, aiSettings, territoryPtr);
        return 0;
    case 13:
        N(UnkNpcAIFunc3)(script, aiSettings, territoryPtr);
        return 0;
    case 14:
        N(UnkFunc6)(script, aiSettings, territoryPtr);
        /* fallthrough */
    default:
        return 0;
    }
}
