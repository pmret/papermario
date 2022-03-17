#include "common.h"

void N(UnkFunc58)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~2;
        npc->duration = 0;
        script->functionTemp[0] = 1;
    }
}
