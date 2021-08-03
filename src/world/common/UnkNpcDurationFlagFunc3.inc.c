#include "common.h"
#include "map.h"

void N(UnkNpcDurationFlagFunc3)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration -= 1;
    if (enemy->varTable[11] >= npc->duration) {
        enemy->flags &= ~0x1F100000;
    }
    if (npc->duration == 0) {
        npc->currentAnim.w = enemy->animList[10];
        npc->duration = 0;
        script->functionTemp[0] = 12;
    }
}
