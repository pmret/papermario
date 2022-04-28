#include "common.h"
#include "npc.h"

void N(PiranhaPlantAI_13)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        npc->duration = enemy->varTable[15];
        script->functionTemp[0] = 14;
    }
}
