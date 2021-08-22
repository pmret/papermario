#include "common.h"
#include "map.h"

void N(UnkNpcAIFunc17)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->duration = 8;
        npc->currentAnim.w = enemy->animList[14];
        script->functionTemp[0] = 52;
    }
}
