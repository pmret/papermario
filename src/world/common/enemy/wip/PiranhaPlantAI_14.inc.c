#include "common.h"
#include "npc.h"
#include "effects.h"

void N(PiranhaPlantAI_14)(Evt *script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 retVal;

    npc->duration--;
    if (npc->duration == 0) {
        if (basic_ai_check_player_dist(territory, enemy, aiSettings->alertRadius, aiSettings->alertOffsetDist.f, 0) == 0) {
            fx_emote(EMOTE_QUESTION, npc, 0, npc->collisionHeight, 1, 2, -20, 15, &retVal);
        }
        npc->duration = 0;
        script->functionTemp[0] = 0;
    }
}
