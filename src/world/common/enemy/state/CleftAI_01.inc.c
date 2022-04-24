#include "common.h"
#include "npc.h"
#include "effects.h"

void N(CleftAI_01)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 var;

    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = aiSettings->unk_14;
        if (basic_ai_try_detect_player(territory, enemy, aiSettings->alertRadius * 0.85, aiSettings->unk_10.f, 0)) {
            npc->currentAnim.w = enemy->animList[9];
            fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &var);
            ai_enemy_play_sound(npc, SOUND_2F4, 0x200000);
            npc->duration = 12;
            script->functionTemp[0] = 2;
        }
    }

    script->functionTemp[1]--;
}
