#include "common.h"
#include "npc.h"
#include "effects.h"

void N(Unk4AI_16)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (aiSettings->waitTime >= 0) {
        if (script->functionTemp[1] <= 0) {
            script->functionTemp[1] = aiSettings->waitTime;
            if (basic_ai_check_player_dist(territory, enemy, aiSettings->chaseSpeed, aiSettings->unk_AI_1C.f, 0) != 0) {
                s32 emoteTemp;

                fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, (f32) npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &emoteTemp);
                ai_enemy_play_sound(npc, 0x2F4, 0x200000);
                npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
                if (enemy->npcSettings->unk_2A & AI_ACTION_JUMP_WHEN_SEE_PLAYER) {
                    script->AI_TEMP_STATE = 10;
                } else {
                    script->AI_TEMP_STATE = 12;
                }
                return;
            }
        }
        script->functionTemp[1]--;
    }

    if (dist2D(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z) < npc->moveSpeed) {
        npc->pos.x = enemy->territory->wander.point.x;
        npc->pos.z = enemy->territory->wander.point.z;
        npc->yaw = enemy->territory->wander.wanderSizeX;
        script->AI_TEMP_STATE = 0;
    }

    if (npc->turnAroundYawAdjustment == 0) {
        npc->yaw = atan2(npc->pos.x, npc->pos.z, enemy->territory->wander.point.x, enemy->territory->wander.point.z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }
}

