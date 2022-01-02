#include "common.h"
#include "npc.h"

ApiStatus N(UnkNpcAIMainFunc3)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = (NpcAISettings*)evt_get_variable(script, *args);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 100.0f;
    territory.unk_1C = 0;

    if (isInitialCall) {
        npc->duration = 0;
        npc->flags &= ~NPC_FLAG_NO_Y_MOVEMENT;
        npc->flags &= ~NPC_FLAG_GRAVITY;
        npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
        script->functionTemp[1] = 0;
        script->functionTemp[0] = 0;
        if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->functionTemp[0] = 12;
            enemy->flags &= ~ENEMY_FLAGS_40000000;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            isk_05_UnkNpcAIFunc40(script, aiSettings, territoryPtr);
        case 1:
            isk_05_UnkNpcAIFunc37(script, aiSettings, territoryPtr);
            break;
        case 2:
            isk_05_UnkNpcAIFunc1(script, aiSettings, territoryPtr);
        case 3:
            isk_05_UnkNpcAIFunc38(script, aiSettings, territoryPtr);
            break;
        case 12:
            isk_05_UnkNpcAIFunc41(script, aiSettings, territoryPtr);
        case 13:
            isk_05_UnkNpcAIFunc39(script, aiSettings, territoryPtr);
            break;
        case 14:
            isk_05_UnkDurationCheck(script, aiSettings, territoryPtr);
            break;
    }
    return 0;
}
