#include "common.h"
#include "npc.h"
#include "effects.h"

void N(PatrolAI_Move)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, z;
    s32 emoteTemp;

    if (aiSettings->playerSearchInterval >= 0) {
        if (script->functionTemp[1] <= 0) {
            script->functionTemp[1] = aiSettings->playerSearchInterval;
            if (basic_ai_try_detect_player(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0)) {
                fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &emoteTemp);
                ai_enemy_play_sound(npc, SOUND_2F4, 0x200000);
                if (enemy->npcSettings->unk_2A & AI_ACTION_JUMP_WHEN_SEE_PLAYER) {
                    script->AI_TEMP_STATE = AI_STATE_ALERT_INIT;
                } else {
                    script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
                }
                return;
            }
        }
        script->functionTemp[1]--;
    }

    if (npc->turnAroundYawAdjustment == 0) {
        if (npc->moveSpeed < 4.0) {
            func_8003D660(npc, 0);
        } else {
            func_8003D660(npc, 1);
        }
        //TODO strange match -- index and array are backwards!
        x = script->AI_PATROL_GOAL_INDEX[enemy->territory->patrol.points].x;
        z = script->AI_PATROL_GOAL_INDEX[enemy->territory->patrol.points].z;
        npc->yaw = atan2(npc->pos.x, npc->pos.z, x, z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        if (dist2D(npc->pos.x, npc->pos.z, x, z) <= npc->moveSpeed) {
            script->AI_TEMP_STATE = AI_STATE_LOITER_INIT;
            script->functionTemp[1] = (rand_int(1000) % 3) + 2;
            if ((aiSettings->unk_2C <= 0) || (aiSettings->moveTime <= 0) ||
                (aiSettings->waitTime <= 0) || (script->functionTemp[1] == 0)) {
                script->AI_TEMP_STATE = AI_STATE_LOITER_POST;
            }
            if (rand_int(10000) % 100 < aiSettings->moveTime) {
                script->AI_TEMP_STATE = AI_STATE_LOITER_POST;
            }
        }
    }
}
