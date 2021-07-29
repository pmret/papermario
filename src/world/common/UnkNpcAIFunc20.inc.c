#include "common.h"
#include "map.h"

void N(UnkNpcAIFunc20)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        npc->collisionHeight = 26;
        npc->collisionRadius = 24;
        script->functionTemp[0] = 4;
    }
}
