#include "common.h"
#include "map.h"

void N(UnkNpcDurationFlagFunc)(ScriptInstance* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        if (enemy->unk_B0 & 0x80) {
            script->functionTemp[0].s = 15;
        } else {
            script->functionTemp[0].s = 0;
        }
    }
}
