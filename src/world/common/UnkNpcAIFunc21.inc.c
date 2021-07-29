#include "common.h"
#include "map.h"

void N(UnkNpcAIFunc21)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        enable_npc_shadow(npc);
        npc->currentAnim.w = enemy->animList[10];
        npc->duration = 8;
        script->functionTemp[0] = 3;
    }
}
