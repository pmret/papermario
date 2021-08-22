#include "common.h"
#include "map.h"

void N(UnkFunc45)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        enemy->varTable[2] = 0;
        npc->duration = 0;
        script->functionTemp[0] = 0;
    }
}
