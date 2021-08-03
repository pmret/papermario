#include "common.h"
#include "map.h"

void N(UnkNpcDurationAnimationFunc)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        npc->currentAnim.w = *enemy->animList;
        script->functionTemp[0] = 0;
    }
}
