#include "common.h"
#include "map.h"

void N(UnkNpcAIFunc2)(ScriptInstance* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    PlayerStatus* playerStatus = gPlayerStatusPtr;

    npc->duration = 0;
    npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
    npc->currentAnim = enemy->animList[8];
    script->functionTemp[0].s = 11;
}
