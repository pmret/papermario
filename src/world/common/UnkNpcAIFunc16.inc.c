#include "common.h"
#include "npc.h"

void N(UnkNpcAIFunc16)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = enemy->varTable[10];
    npc->currentAnim.w = enemy->animList[13];
    script->functionTemp[0] = 21;
}
