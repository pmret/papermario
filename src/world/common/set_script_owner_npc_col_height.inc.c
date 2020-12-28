#include "common.h"
#include "map.h"

void N(set_script_owner_npc_col_height)(ScriptInstance* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration++;
    if (npc->duration == 3) {
        npc->collisionHeight = enemy->varTable[6];
    }

    if (npc->duration < enemy->varTable[5]) {
        return;
    }

    npc->collisionHeight = enemy->varTable[6];
    script->functionTemp[0].s = 0;
}
