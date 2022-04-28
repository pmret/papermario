#include "common.h"
#include "npc.h"

void N(Unk4AI_14)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        script->functionTemp[0] = 15;
    }
}
