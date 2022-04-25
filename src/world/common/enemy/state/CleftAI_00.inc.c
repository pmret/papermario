#include "common.h"
#include "npc.h"

void N(CleftAI_00)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    disable_npc_shadow(npc);
    npc->collisionHeight = 22;
    npc->collisionRadius = 24;
    script->functionTemp[1] = 0;
    npc->duration = 0;
    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_MELEE_PRE];
    script->functionTemp[0] = 1;
}
