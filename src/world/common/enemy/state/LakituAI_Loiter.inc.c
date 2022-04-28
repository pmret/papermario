#include "common.h"
#include "npc.h"

void N(LakituAI_Loiter)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, hitDepth;
    s32 emoteTemp;
    f32 var1 = enemy->varTable[3];
    f32 var2;
    f32 temp_f20;
    f32 temp_f22;

    temp_f22 = var1 / 100.0;
    if (npc->duration > 0) {
        npc->duration--;
    }
    var2 = enemy->varTable[1];
    temp_f20 = var2 / 100.0;

    posX = npc->pos.x;
    posY = npc->pos.y;
    posZ = npc->pos.z;
    hitDepth = 1000.0f;

    npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &hitDepth);
    npc->pos.y = posY + temp_f22 + (sin_deg(enemy->varTable[2]) * temp_f20);
    enemy->varTable[2] = clamp_angle(enemy->varTable[2] + 12);
    if (basic_ai_try_detect_player(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 1) != 0) {
        fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteTemp);
        ai_enemy_play_sound(npc, SOUND_2F4, 0x200000);
        script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
        return;
    }

    if ((npc->turnAroundYawAdjustment == 0) && (npc->duration <= 0)) {
        script->functionTemp[1]--;
        if (script->functionTemp[1] > 0) {
            npc->yaw = clamp_angle(npc->yaw + 180.0f);
            npc->duration = (rand_int(1000) % 11) + 5;
            return;
        }
        script->AI_TEMP_STATE = AI_STATE_WANDER_INIT;
    }
}
