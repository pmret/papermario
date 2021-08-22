#include "common.h"
#include "map.h"

void N(DeadUnkNpcAIFunc1)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = dead_get_npc_unsafe(enemy->npcID);

    npc->duration = (aiSettings->waitTime / 2) + dead_rand_int((aiSettings->waitTime / 2) + 1);
    npc->yaw = dead_clamp_angle(npc->yaw + dead_rand_int(180) - 90.0f);
    npc->currentAnim.w = *enemy->animList;
    script->functionTemp[0] = 3;
}
