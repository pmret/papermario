#include "common.h"
#include "map.h"

static void UnkNpcAIFunc7(ScriptInstance* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        enemy->varTable[0] = 3;
        npc->duration = enemy->varTable[2];
        npc->currentAnim = enemy->animList[9];
        script->functionTemp[0].s = 32;
    }
}
