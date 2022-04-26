#include "common.h"
#include "npc.h"

s32 N(PiranhaPlantAI_Main)(Evt* script, s32 isInitialCall) {
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
    
    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAGS_4)) {
        script->AI_TEMP_STATE = AI_STATE_PIRANHA_PLANT_00;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[ENEMY_ANIM_IDLE];

        enemy->AI_VAR_ATTACK_STATE = MELEE_HITBOX_STATE_NONE;
        if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
            script->AI_TEMP_STATE = AI_STATE_SUSPEND;
            script->functionTemp[1] = AI_STATE_PIRANHA_PLANT_00;
            enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
        }
    }

    switch (script->AI_TEMP_STATE) {
        case AI_STATE_PIRANHA_PLANT_00:
            N(PiranhaPlantAI_00)(script, npcAISettings, territoryPtr);
        case AI_STATE_PIRANHA_PLANT_01:
            N(PiranhaPlantAI_01)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_PIRANHA_PLANT_10:
            N(PiranhaPlantAI_10)(script, npcAISettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_PIRANHA_PLANT_11) {
                break;
            }
        case AI_STATE_PIRANHA_PLANT_11:
            N(PiranhaPlantAI_11)(script, npcAISettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_PIRANHA_PLANT_12) {
                break;
            }
        case AI_STATE_PIRANHA_PLANT_12:
            N(PiranhaPlantAI_12)(script, npcAISettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_PIRANHA_PLANT_13) {
                break;
            }
        case AI_STATE_PIRANHA_PLANT_13:
            N(PiranhaPlantAI_13)(script, npcAISettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_PIRANHA_PLANT_14) {
                break;
            }
        case AI_STATE_PIRANHA_PLANT_14:
            N(PiranhaPlantAI_14)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_SUSPEND:
            basic_ai_suspend(script);
            break;
    }
    return ApiStatus_BLOCK;
}
