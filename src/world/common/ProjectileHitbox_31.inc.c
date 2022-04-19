#include "common.h"
#include "npc.h"

void N(ProjectileHitbox_31)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;

    get_npc_unsafe(enemy->npcID)->duration = enemy->varTable[2];
    script->functionTemp[0] = AI_STATE_PROJECTILE_HITBOX_33;
}
