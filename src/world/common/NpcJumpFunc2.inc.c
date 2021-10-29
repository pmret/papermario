#include "common.h"
#include "npc.h"

void N(NpcJumpFunc2)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->currentAnim.w = enemy->animList[4];
    npc->jumpVelocity = 10.0f;
    npc->jumpScale = 2.0f;
    npc->moveToPos.y = npc->pos.y;
    npc->flags |= 0x800;
    script->functionTemp[0] = 11;
}
