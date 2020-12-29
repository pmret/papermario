#include "common.h"
#include "map.h"

void M(UnkNpcAIFunc9)(ScriptInstance* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Enemy* enemy2 = get_enemy(enemy->npcID + 1);
    Npc* npc2 = get_npc_unsafe(enemy2->npcID);

    npc->yaw = atan2(npc->pos.x, npc->pos.z, npc2->pos.x, npc2->pos.z);
    if (enemy2->varTable[0] == 0) {
        npc->currentAnim = enemy->animList[0];
        npc->duration = enemy->varTable[2];
        script->functionTemp[0].s = 33;
    }
}
