#include "common.h"
#include "npc.h"

void N(PatrolAI_LosePlayer)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        if (enemy->aiFlags & ENEMY_AI_FLAGS_80) {
            script->AI_TEMP_STATE = AI_STATE_PATROL_15;
        } else {
            script->AI_TEMP_STATE = AI_STATE_WANDER_INIT;
        }
    }
}
