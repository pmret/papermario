#include "common.h"
#include "npc.h"

// TODO same as ParatroopaAI_Reset, but removes the extra args since it affects codegen...?
void N(ProjectileHitbox_33)(Evt* script) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        script->functionTemp[0] = AI_STATE_WANDER_INIT;
    }
}
