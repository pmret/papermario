#include "common.h"
#include "map.h"
#include "effects.h"

void N(UnkNpcAIFunc30)(Evt *script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 retVal;

    npc->duration--;
    if (npc->duration == 0) {
        if (func_800490B4(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0) == 0) {
            fx_emote(2, npc, 0, npc->collisionHeight, 1, 2, -20, 15, &retVal);
        }
        npc->duration = 0;
        script->functionTemp[0] = 0;
    }
}
