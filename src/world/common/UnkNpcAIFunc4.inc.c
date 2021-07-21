#include "common.h"
#include "map.h"

void N(UnkNpcAIFunc4)(ScriptInstance* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = 0;
    set_npc_yaw(npc, 270.0f);
    enemy->varTable[0] = 0;
    script->functionTemp[0] = 3;
}
