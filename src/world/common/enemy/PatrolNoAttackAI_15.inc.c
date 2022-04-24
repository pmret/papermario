#include "common.h"
#include "npc.h"

void N(PatrolNoAttackAI_15)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 i;

    // get next patrol point
    for (i = script->AI_PATROL_GOAL_INDEX; i < enemy->territory->patrol.numPoints; i++) {
        if (i[enemy->territory->patrol.points].y <= npc->pos.y) {
            script->AI_PATROL_GOAL_INDEX = i;
            break;
        }
    }

    npc->moveSpeed = aiSettings->moveSpeed;
    npc->currentAnim.w = enemy->animList[1];
    script->functionTemp[1] = 0;
    script->AI_TEMP_STATE = AI_STATE_PATROL;
}
