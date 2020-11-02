#include "common.h"

static void SetNpcColHeight(ScriptInstance* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (npc->duration++ == 2) {
        npc->collisionHeight = enemy->varTable[6];
    }

    if (npc->duration < enemy->varTable[5]) {
        return;
    }

    npc->collisionHeight =  enemy->varTable[6];
    script->functionTemp[0].s = 0;
}
