#include "common.h"
#include "map.h"

void N(UnkNpcAIFunc22)(ScriptInstance* script, NpcAISettings* aiSettings, s32 arg2) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->yaw = clamp_angle(npc->yaw + rand_int(180) - 90.0f);
    npc->currentAnim = enemy->animList[0];
    script->functionTemp[1].s = rand_int(1000) % 2 + 2;
    script->functionTemp[0].s = 5;
}
