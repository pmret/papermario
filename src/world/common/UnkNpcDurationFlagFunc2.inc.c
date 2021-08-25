#include "common.h"
#include "map.h"

void N(UnkNpcDurationFlagFunc2)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        npc->duration = enemy->varTable[15];
        script->functionTemp[0] = 14;
    }
}
