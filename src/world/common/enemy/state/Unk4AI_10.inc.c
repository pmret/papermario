#include "common.h"
#include "npc.h"

void N(Unk4AI_10)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->jumpVelocity = 10.0f;
    npc->jumpScale = 2.0f;
    npc->moveToPos.y = npc->pos.y;
    npc->flags |= 0x800;
    script->functionTemp[0] = 11;
}
