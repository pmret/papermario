#include "common.h"
#include "npc.h"

void N(ShyGuyWanderAI_17)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        npc->currentAnim.w = *enemy->animList;
        script->functionTemp[0] = 0;
    }
}
