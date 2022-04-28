#include "common.h"
#include "npc.h"
#include "effects.h"

void N(HoppingAI_Loiter)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (aiSettings->playerSearchInterval >= 0 && basic_ai_try_detect_player(territory, enemy, aiSettings->chaseRadius, aiSettings->unkChase, 0) != 0) {
        s32 emoteTemp;
        fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteTemp);
        ai_enemy_play_sound(npc, SOUND_2F4, 0x200000);
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        script->AI_TEMP_STATE = 12;
    } else if (npc->turnAroundYawAdjustment == 0) {
        npc->duration--;
        if (npc->duration <= 0) {
            script->functionTemp[1]--;
            if (script->functionTemp[1] > 0) {
                npc->yaw = clamp_angle(npc->yaw + 180.0f);
                npc->duration = (rand_int(1000) % 11) + 5;
            } else {
                script->AI_TEMP_STATE = 0;
            }
        }
    }
}
