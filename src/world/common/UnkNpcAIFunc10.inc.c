#include "common.h"
#include "map.h"

void N(UnkNpcAIFunc10)(Evt* script) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        script->functionTemp[0] = 15;
    }
}
