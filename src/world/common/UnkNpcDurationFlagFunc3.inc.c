#include "common.h"
#include "npc.h"

void N(UnkNpcDurationFlagFunc3)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (enemy->varTable[11] >= npc->duration) {
        enemy->flags &= ~(ENEMY_FLAGS_100000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_IGNORE_JUMP | ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_8000000 | ENEMY_FLAGS_10000000);
    }
    if (npc->duration == 0) {
        npc->currentAnim.w = enemy->animList[10];
        npc->duration = 0;
        script->functionTemp[0] = 12;
    }
}
