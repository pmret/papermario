#include "common.h"
#include "npc.h"

void N(PatrolAI_Jump)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->pos.y += npc->jumpVelocity;
    npc->jumpVelocity -= npc->jumpScale;

    if (!(npc->pos.y > npc->moveToPos.y)) {
        npc->pos.y = npc->moveToPos.y;
        npc->jumpVelocity = 0.0f;
        npc->flags &= ~NPC_FLAG_JUMPING;
        script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
    }
}
