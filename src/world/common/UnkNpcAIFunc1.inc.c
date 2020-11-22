#include "common.h"
#include "map.h"

static void UnkNpcAIFunc1(ScriptInstance* script, NpcAISettings* aiSettings) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = (aiSettings->waitTime / 2) + rand_int((aiSettings->waitTime / 2) + 1);
    npc->yaw = clamp_angle(npc->yaw + rand_int(180) - 90.0f);
    npc->currentAnim = *enemy->animList;
    script->functionTemp[0].s = 3;
}
