#include "common.h"
#include "npc.h"

void N(UnkNpcDurationFlagFunc)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        if (enemy->unk_B0 & ENEMY_AI_FLAGS_80) {
            script->functionTemp[0] = 15;
        } else {
            script->functionTemp[0] = 0;
        }
    }
}
