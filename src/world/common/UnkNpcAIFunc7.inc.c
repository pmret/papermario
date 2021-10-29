#include "common.h"
#include "npc.h"

void N(UnkNpcAIFunc7)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        enemy->varTable[0] = 3;
        npc->duration = enemy->varTable[2];
        npc->currentAnim.w = enemy->animList[9];
        script->functionTemp[0] = 32;
    }
}
