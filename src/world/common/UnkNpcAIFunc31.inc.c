#include "common.h"
#include "map.h"
#include "effects.h"

void N(UnkNpcAIFunc31)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (npc->duration > 0) {
        npc->duration--;
        return;
    }

    enemy->varTable[0] = 0;
    npc->currentAnim.w = *enemy->animList;
    script->functionTemp[1] = 0;
    script->functionTemp[0] = 1;
}
