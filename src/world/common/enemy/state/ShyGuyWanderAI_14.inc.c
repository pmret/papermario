#include "common.h"
#include "npc.h"

void N(ShyGuyWanderAI_14)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territoryPtr) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    
    npc->moveSpeed *= 0.6;
    npc->currentAnim.w = enemy->animList[12];
    npc->duration = 5;
    script->functionTemp[0] = 0xF;
}
