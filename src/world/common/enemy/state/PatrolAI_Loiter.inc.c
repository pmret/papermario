#include "common.h"
#include "npc.h"

void N(PatrolAI_Loiter)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 emoteTemp;

    if ((aiSettings->playerSearchInterval >= 0) && basic_ai_try_detect_player(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 0)) {
        fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &emoteTemp);
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        ai_enemy_play_sound(npc, SOUND_2F4, 0x200000);
        if (!(enemy->npcSettings->unk_2A & AI_ACTION_JUMP_WHEN_SEE_PLAYER)) {
            script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
        } else {
            script->AI_TEMP_STATE = AI_STATE_ALERT_INIT;
        }
        return;
    }

    // look around randomly
    if (npc->turnAroundYawAdjustment == 0) {
        npc->duration--;
        if (npc->duration == 0) {
            script->functionTemp[1]--;
            if (script->functionTemp[1] != 0) {
                if (!(enemy->npcSettings->unk_2A & AI_ACTION_LOOK_AROUND_DURING_LOITER)) {
                    npc->yaw = clamp_angle(npc->yaw + 180.0f);
                }
                npc->duration = aiSettings->waitTime / 2 + rand_int(aiSettings->waitTime / 2 + 1);
            } else {
                script->AI_TEMP_STATE = AI_STATE_LOITER_POST;
            }
        }
    }
}
