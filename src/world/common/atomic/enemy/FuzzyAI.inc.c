#include "world/common/UnkNpcAIFunc36.inc.c"

#include "world/common/UnkNpcAIFunc37.inc.c"

// used in 38 files
//#include "world/common/UnkNpcAIFunc1.inc.c"
void N(UnkNpcAIFunc1)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = (aiSettings->waitTime / 2) + rand_int((aiSettings->waitTime / 2) + 1);
    npc->yaw = clamp_angle(npc->yaw + rand_int(180) - 90.0f);
    npc->currentAnim.w = *enemy->animList;
    script->functionTemp[0] = 3;
}

#include "world/common/UnkNpcAIFunc38.inc.c"

#include "world/common/UnkNpcAIFunc15.inc.c"

#include "world/common/UnkNpcAIFunc39.inc.c"

// used in 11 files
// #include "world/common/UnkDurationCheck.inc.c"
void N(UnkDurationCheck)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        script->functionTemp[0] = 0;
    }
}

#include "world/common/UnkNpcAIMainFunc2.inc.c"
