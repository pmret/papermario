#include "common.h"
#include "map.h"

static void UnkNpcAIFunc5(ScriptInstance* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if ((npc->duration << 0x10) <= 0) {
        enemy->varTable[0] = 0;
        script->functionTemp[0].s = 12;
    }
}
