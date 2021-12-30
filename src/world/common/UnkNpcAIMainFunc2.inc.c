#include "common.h"
#include "npc.h"

ApiStatus N(UnkNpcAIMainFunc2)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    NpcAISettings* aiSettings = (NpcAISettings*)evt_get_variable(script, *args++);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr;
    
    enemy->varTable[10] = evt_get_variable(script, *args++);
    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 100.0f;
    territory.unk_1C = 0;
    territoryPtr = &territory;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        script->functionTemp[1] = 0;
        npc->flags &= ~NPC_FLAG_NO_Y_MOVEMENT;
        npc->flags &= ~NPC_FLAG_GRAVITY;
        npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;

        enemy->unk_B0 |= 0x18;
        if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->functionTemp[0] = 12;
            enemy->flags &= ~ENEMY_FLAGS_40000000;
        }
    }

    if (enemy->unk_B0 & 4) {
        if (enemy->unk_B4 != 0) {
            return ApiStatus_BLOCK;
        }
        enemy->unk_B0 &= ~4;
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc36)(script, aiSettings, territoryPtr);
        case 1:
            N(UnkNpcAIFunc37)(script, aiSettings, territoryPtr);
            break;
        case 2:
            N(UnkNpcAIFunc1)(script, aiSettings, territoryPtr);
            if (script->functionTemp[0] != 3) {
                break;
            }
        case 3:
            N(UnkNpcAIFunc38)(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(UnkNpcAIFunc15)(script, aiSettings, territoryPtr);
        case 13:
            N(UnkNpcAIFunc39)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(UnkDurationCheck)(script, aiSettings, territoryPtr);
            break;
    }
    return ApiStatus_BLOCK;
}
