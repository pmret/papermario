#include "common.h"
#include "map.h"
#include "effects.h"

void N(UnkNpcAIFunc33)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 temp;

    npc->duration++;
    if (npc->duration == enemy->varTable[13]) {
        npc->currentAnim.w = enemy->animList[11];
    }
    if (npc->duration == enemy->varTable[14]) {
        enemy->varTable[0] = 3;
    }
    if (npc->duration >= enemy->varTable[12]) {
        enemy->varTable[0] = 4;
        npc->duration = 8;
        npc->currentAnim.w = enemy->animList[0];
        fx_emote(3, npc, 0, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 10, &temp);
        script->functionTemp[0] = 13;
    }
}
