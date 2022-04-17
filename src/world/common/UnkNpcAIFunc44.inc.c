#include "common.h"
#include "npc.h"
#include "effects.h"

void N(UnkNpcAIFunc44)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (aiSettings->waitTime >= 0 && (basic_ai_try_detect_player(territory, enemy, aiSettings->chaseSpeed, aiSettings->unk_1C.f, 0) != 0)) {
        s32 emoteTemp;

        fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &emoteTemp);
        ai_enemy_play_sound(npc, 0x2F4, 0x200000);
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);

        if (!(enemy->npcSettings->unk_2A & 1)) {
            script->functionTemp[0] = 12;
        } else {
            script->functionTemp[0] = 10;
        }
    }
}
