#include "common.h"
#include "npc.h"

void N(MeleeHitbox_30)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    enemy->varTable[0] = 1;
    if (npc->turnAroundYawAdjustment == 0) {
        enemy->varTable[0] = 2;
        npc->duration = enemy->varTable[1];
        npc->currentAnim.w = enemy->animList[ENEMY_ANIM_MELEE_PRE];
        script->functionTemp[0] = 31;
    }
}
