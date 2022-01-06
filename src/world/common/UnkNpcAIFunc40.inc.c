#include "common.h"
#include "npc.h"

void N(UnkNpcAIFunc40)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    func_800495A0(script, aiSettings, territory);
    npc->jumpVelocity = rand_int(5) + 8.0;
    npc->jumpScale = 1.5f;
}

void N(UnkNpcAIFunc41)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    func_80049F7C(script, aiSettings, territory);
    npc->jumpVelocity = rand_int(5) + 5.0;
    npc->jumpScale = 1.5f;
}
