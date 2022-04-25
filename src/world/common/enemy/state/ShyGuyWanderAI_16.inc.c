#include "common.h"
#include "npc.h"

void N(ShyGuyWanderAI_16)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 yaw = npc->yaw;
    
    if (ai_check_fwd_collisions(npc, npc->moveSpeed, &yaw, NULL, NULL, NULL) == 0) {
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }
    
    npc->duration--;
    if (npc->duration == 0) {
        npc->duration = 30;
        script->functionTemp[0] = 17;
    }
}
