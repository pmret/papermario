#include "common.h"
#include "map.h"

void N(UnkNpcAIFunc6)(ScriptInstance* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    enemy->varTable[0] = 1;
    if (npc->unk_8C == 0) {
        enemy->varTable[0] = 2;
        npc->duration = enemy->varTable[1];
        npc->currentAnim = enemy->animList[8];
        script->functionTemp[0].s = 31;
    }
}
