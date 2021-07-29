#include "common.h"
#include "map.h"

void N(UnkNpcAIFunc6)(ScriptInstance* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    enemy->varTable[0] = 1;
    if (npc->turnAroundYawAdjustment == 0) {
        enemy->varTable[0] = 2;
        npc->duration = enemy->varTable[1];
        npc->currentAnim.w = enemy->animList[8];
        script->functionTemp[0] = 31;
    }
}
