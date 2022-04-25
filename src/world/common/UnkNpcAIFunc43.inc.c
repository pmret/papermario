#include "common.h"
#include "npc.h"

void N(UnkNpcAIFunc43)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_IDLE];
    script->functionTemp[0] = 1;

    if (enemy->flags & ENEMY_FLAGS_100000) {
        npc->yaw = enemy->varTable[0];
    }

    if (enemy->territory->wander.moveSpeedOverride <= 0) {
        npc->moveSpeed = aiSettings->alertRadius;
    } else {
        npc->moveSpeed = enemy->territory->wander.moveSpeedOverride / 32767.0;
    }
}
