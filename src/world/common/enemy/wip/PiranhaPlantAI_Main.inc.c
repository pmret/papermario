#include "common.h"
#include "npc.h"

s32 N(PiranhaPlantAI_Main)(Evt* script, s32 isInitialCall) {
    #ifdef _DEAD_H_
    DeadEnemy* enemy = (DeadEnemy*)script->owner1.enemy;
    #else
    Enemy* enemy = script->owner1.enemy;
    #endif
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    MobileAISettings* npcAISettings = (MobileAISettings*)evt_get_variable(script, *args++);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detectPos.x;
    territory.pointZ = enemy->territory->wander.detectPos.z;
    territory.sizeX = enemy->territory->wander.detectSize.x;
    territory.sizeZ = enemy->territory->wander.detectSize.z;
    territory.halfHeight = 200.0f;
    territory.detectFlags = 0;

    #ifdef _DEAD_H_
    // Dead Func that doesn't seem to have an alive counterpart, probably because of the
    // difference in the Enemy and DeadEnemy struct.
    func_8004D8E0(enemy);
    if (enemy->flags & ENEMY_FLAGS_100000) {
        enemy->unk_114 = 10.0f;
        enemy->unk_118 = 0.7f;
    }
    #endif
    
    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAGS_4)) {
        script->AI_TEMP_STATE = AI_STATE_PIRANHA_PLANT_00;
        npc->duration = 0;
        npc->currentAnim = enemy->animList[ENEMY_ANIM_IDLE];

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
