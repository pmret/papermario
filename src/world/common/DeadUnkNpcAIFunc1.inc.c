#include "common.h"
#include "map.h"

void N(DeadUnkNpcAIFunc1)(ScriptInstance* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = func_8003E4BC(enemy->npcID);

    npc->duration = (aiSettings->waitTime / 2) + func_8002ACEC((aiSettings->waitTime / 2) + 1);
    npc->yaw = func_8002AE14(npc->yaw + func_8002ACEC(180) - 90.0f);
    npc->currentAnim.w = *enemy->animList;
    script->functionTemp[0] = 3;
}
