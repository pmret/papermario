#include "common.h"
#include "npc.h"

void N(ShyGuyWanderAI_15)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe((s32) enemy->npcID);
    f32 yaw = npc->yaw;
    
    if (ai_check_fwd_collisions(npc, npc->moveSpeed, &yaw, NULL, NULL, NULL) == 0) {
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }
    
    npc->duration--;
    if (npc->duration == 0) {
        npc->moveSpeed *= 0.6;

        npc->currentAnim.w = enemy->animList[11];
        npc->duration = 10;
        script->functionTemp[0] = 16;
    }
}
