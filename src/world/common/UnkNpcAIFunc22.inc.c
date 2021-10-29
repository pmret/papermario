#include "common.h"
#include "npc.h"

void N(UnkNpcAIFunc22)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->yaw = clamp_angle(npc->yaw + rand_int(180) - 90.0f);
    npc->currentAnim.w = enemy->animList[0];
    script->functionTemp[1] = rand_int(1000) % 2 + 2;
    script->functionTemp[0] = 5;
}
