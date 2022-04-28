#include "common.h"
#include "npc.h"
#include "effects.h"

void N(FlyingAI_Loiter)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 hoverHeight = (f32)enemy->varTable[3] / 100.0;
    f32 temp_f26 = hoverHeight + (f32)((f32)enemy->varTable[7] / 100.0);
    s32 var;

    if (npc->duration > 0) {
        npc->duration--;
    }

    if (enemy->varTable[1] > 0) {
        f32 undulateAmplitude = (f32)enemy->varTable[1] / 100.0;
        f32 undulateAmount = sin_deg(enemy->varTable[2]);
        s32 hitResult;

        if (npc->flags & NPC_FLAG_ENABLE_HIT_SCRIPT) {
            hitResult = 0;
        } else {
            posX = npc->pos.x;
            posY = npc->pos.y;
            posZ = npc->pos.z;
            posW = 1000.0f;
            hitResult = npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &posW);
        }

        if (hitResult) {
            npc->pos.y = posY + hoverHeight + (undulateAmount * undulateAmplitude);
        } else {
            npc->pos.y = temp_f26 + (undulateAmount * undulateAmplitude);
        }

        enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 10);
    }

    if (enemy->varTable[9] <= 0) {
        if ((gPlayerStatusPtr->position.y < npc->pos.y + npc->collisionHeight + 10.0)
            && basic_ai_check_player_dist(territory, enemy, aiSettings->chaseRadius, aiSettings->unkChase, 1)) {
            fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 12, &var);
            npc->moveToPos.y = npc->pos.y;
            ai_enemy_play_sound(npc, SOUND_2F4, 0x200000);
            if (enemy->npcSettings->unk_2A & AI_ACTION_JUMP_WHEN_SEE_PLAYER) {
                script->AI_TEMP_STATE = AI_STATE_ALERT_INIT;
            } else {
                script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
            }
            return;
        }
    } else {
        enemy->varTable[9]--;
    }

    if ((npc->turnAroundYawAdjustment == 0) && (npc->duration <= 0)) {
        script->functionTemp[1]--;
        if (script->functionTemp[1] > 0) {
            if (!(enemy->npcSettings->unk_2A & AI_ACTION_LOOK_AROUND_DURING_LOITER)) {
                npc->yaw = clamp_angle(npc->yaw + 180.0f);
            }
            npc->duration = (rand_int(1000) % 11) + 5;
        } else {
            script->AI_TEMP_STATE = AI_STATE_WANDER_INIT;
        }
    }
}
