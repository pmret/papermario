#include "common.h"
#include "npc.h"

s32 N(PiranhaAI_Main)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* npcAISettings = (NpcAISettings*)evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 200.0f;
    territory.unk_1C = 0;
    
    if ((isInitialCall != 0) || ((enemy->aiFlags & 4) != 0)) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        enemy->varTable[0] = 0;
        if ((enemy->aiFlags & 4) != 0) {
            script->functionTemp[0] = 0x63;
            script->functionTemp[1] = 0;
            enemy->aiFlags &= -5;
        }
    }

    switch (script->functionTemp[0]) {
    case AI_STATE_PIRANHA_PLANT_00:
        N(PiranhaPlantAI_00)(script, npcAISettings, territoryPtr);
    case AI_STATE_PIRANHA_PLANT_01:
        N(PiranhaPlantAI_01)(script, npcAISettings, territoryPtr);
        break;
    case AI_STATE_PIRANHA_PLANT_10:
        N(PiranhaPlantAI_10)(script, npcAISettings, territoryPtr);
        if (script->functionTemp[0] != AI_STATE_PIRANHA_PLANT_11) {
             break;
        }
    case AI_STATE_PIRANHA_PLANT_11:
        N(PiranhaPlantAI_11)(script, npcAISettings, territoryPtr);
        if (script->functionTemp[0] != AI_STATE_PIRANHA_PLANT_12) {
             break;
        }
    case AI_STATE_PIRANHA_PLANT_12:
        N(PiranhaPlantAI_12)(script, npcAISettings, territoryPtr);
        if (script->functionTemp[0] != AI_STATE_PIRANHA_PLANT_13) {
             break;
        }
    case AI_STATE_PIRANHA_PLANT_13:
        N(PiranhaPlantAI_13)(script, npcAISettings, territoryPtr);
        if (script->functionTemp[0] != AI_STATE_PIRANHA_PLANT_14) {
             break;
        }
    case AI_STATE_PIRANHA_PLANT_14:
        N(PiranhaPlantAI_14)(script, npcAISettings, territoryPtr);
        break;
    case AI_STATE_PIRANHA_PLANT_SUSPEND:
        basic_ai_suspend(script);
        break;
    }
    return 0;
}
