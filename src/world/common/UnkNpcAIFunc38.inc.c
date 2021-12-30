#include "common.h"
#include "npc.h"
#include "effects.h"

void N(UnkNpcAIFunc38)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (aiSettings->unk_14 >= 0 && func_800490B4(territory, enemy, aiSettings->chaseRadius, aiSettings->unk_28.f, 0) != 0) {
        s32 emoteTemp;

        fx_emote(0, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &emoteTemp);
        ai_enemy_play_sound(npc, 0x2F4, 0x200000);
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        script->functionTemp[0] = 12;
    } else if (npc->turnAroundYawAdjustment == 0) {
        npc->duration--;
        if (npc->duration <= 0) {
            script->functionTemp[1]--;
            if (script->functionTemp[1] > 0) {
                npc->yaw = clamp_angle(npc->yaw + 180.0f);
                npc->duration = (rand_int(1000) % 11) + 5;
            } else {
                script->functionTemp[0] = 0;
            }
        }
    }
}
