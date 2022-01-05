#include "common.h"
#include "npc.h"

void N(UnkNpcAIFunc10)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        script->functionTemp[0] = 15;
    }
}
