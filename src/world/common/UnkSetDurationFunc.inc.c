#include "common.h"
#include "npc.h"

void N(UnkSetDurationFunc)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;

    get_npc_unsafe(enemy->npcID)->duration = enemy->varTable[2];
    script->functionTemp[0] = 33;
}
