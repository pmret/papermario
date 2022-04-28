#include "common.h"
#include "npc.h"
#include "effects.h"

void N(HoppingAI_Hop)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, hitDepth;

    if (aiSettings->playerSearchInterval >= 0) {
        if (script->functionTemp[1] <= 0) {
            do {
                script->functionTemp[1] = aiSettings->playerSearchInterval;
                if (basic_ai_try_detect_player(territory, enemy, aiSettings->alertRadius, aiSettings->unk_10.f, 0) != 0) {
                    s32 emoteTemp;
                    fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteTemp);
                    ai_enemy_play_sound(npc, 0x2F4, 0x200000);
                    npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
                    script->AI_TEMP_STATE = 12;
                    return;
                }
            } while (0); // required to match
        }
        script->functionTemp[1]--;
    }

    if (npc->moveSpeed > 0.0) {
        f32 collRadius;
        f32 collHeight;
        f32 moveSpeed;

        posX = npc->pos.x;
        posY = npc->pos.y;
        posZ = npc->pos.z;
        moveSpeed = npc->moveSpeed;
        collHeight = npc->collisionHeight;
        collRadius = npc->collisionRadius;

        if (npc_test_move_simple_with_slipping(npc->collisionChannel, &posX, &posY, &posZ, moveSpeed, npc->yaw, collHeight,
                                               collRadius * 1.2) == 0) 
        {
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        } else {
            npc->moveSpeed = 0.0f;
        }
    }

    if (npc->jumpVelocity < 0.0) {
        posX = npc->pos.x;
        posY = npc->pos.y + 13.0;
        posZ = npc->pos.z;
        hitDepth = fabsf(npc->jumpVelocity) + 16.0;

        if (npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &hitDepth) != 0 && 
            hitDepth <= fabsf(npc->jumpVelocity) + 13.0) 
        {
            npc->jumpVelocity = 0.0f;
            npc->pos.y = posY;
            npc->flags &= ~NPC_FLAG_JUMPING;
            script->AI_TEMP_STATE = 2;
            script->functionTemp[1] = (rand_int(1000) % 3) + 2;

            if (aiSettings->unk_2C <= 0) {
                script->AI_TEMP_STATE = 0;
            } else if (aiSettings->moveTime <= 0) {
                script->AI_TEMP_STATE = 0;
            } else if (script->functionTemp[1] == 0) {
                script->AI_TEMP_STATE = 0;
            }
            return;
        }
    } 
    npc->pos.y += npc->jumpVelocity;
    npc->jumpVelocity -= npc->jumpScale;
}
