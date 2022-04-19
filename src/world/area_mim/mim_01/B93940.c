#include "mim_01.h"

#include "world/common/AttackAheadHitboxAI_30.inc.c"

#include "world/common/AttackAheadHitboxAI_31.inc.c"

#include "world/common/AttackAheadHitboxAI_32.inc.c"

#include "world/common/AttackAheadHitboxAI_33.inc.c"

#include "world/common/AttackAheadHitbox_CanSeePlayer.inc.c"

#include "world/common/AttackAheadHitbox_Control.inc.c"

#include "world/common/AttackAheadHitbox_Main.inc.c"

#include "world/common/atomic/enemy/PiranhaPlant_States.inc.c"

ApiStatus func_80241C54_B95094(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;    
    NpcAISettings* settings = (NpcAISettings*) evt_get_variable(script, *script->ptrReadPos);

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.halfHeight = 200.0f;
    territory.unk_1C = 0;

    if (isInitialCall || enemy->aiFlags & ENEMY_AI_FLAGS_4) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        enemy->varTable[0] = 0;

        if (enemy->aiFlags & ENEMY_AI_FLAGS_4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->aiFlags &= ~ENEMY_AI_FLAGS_4;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(PiranhaPlantAI_00)(script, settings, territoryPtr);
            /* fallthrough */
        case 1:
            N(PiranhaPlantAI_01)(script, settings, territoryPtr);
            break;
        case 10:
            N(PiranhaPlantAI_10)(script, settings, territoryPtr);
            if (script->functionTemp[0] != 11) {
                break;
            }
        case 11:
            N(PiranhaPlantAI_11)(script, settings, territoryPtr);
            if (script->functionTemp[0] != 12) {
                break;
            }
        case 12:
            N(PiranhaPlantAI_12)(script, settings, territoryPtr);
            if (script->functionTemp[0] != 13) {
                break;
            }
        case 13:
            N(PiranhaPlantAI_13)(script, settings, territoryPtr);
            if (script->functionTemp[0] != 14) {
                break;
            }
        case 14:
            N(PiranhaPlantAI_14)(script, settings, territoryPtr);
            break;
        case 99:
            basic_ai_suspend(script);
            break;
    }

    return ApiStatus_BLOCK;
}
