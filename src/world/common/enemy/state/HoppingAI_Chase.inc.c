#include "common.h"
#include "npc.h"
#include "effects.h"

void N(HoppingAI_Chase)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 posX, posY, posZ, posW;
    f32 sp34;

    if (npc->moveSpeed > 0.0) {
        posX = npc->pos.x;
        posY = npc->pos.y;
        posZ = npc->pos.z;
        if (npc_test_move_simple_with_slipping(npc->collisionChannel, &posX, &posY, &posZ, npc->moveSpeed, npc->yaw,
                                               npc->collisionHeight, npc->collisionRadius))
        {
            npc->moveSpeed = 0.0f;
        } else {
            npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        }
    }

    if (npc->jumpVelocity < 0.0) {
        posX = npc->pos.x;
        sp34 = 100.0f;
        posZ = npc->pos.z;
        posW = 1000.0f;
        npc_raycast_down_sides(npc->collisionChannel, &posX, &sp34, &posZ, &posW);

        posX = npc->pos.x;
        posY = npc->pos.y + 13.0;
        posZ = npc->pos.z;
        posW = fabsf(npc->jumpVelocity) + 16.0;
        if (npc_raycast_down_sides(npc->collisionChannel, &posX, &posY, &posZ, &posW) && posW <= fabsf(npc->jumpVelocity) + 13.0) {
            npc->jumpVelocity = 0.0f;
            npc->pos.y = posY;
            npc->flags &= ~NPC_FLAG_JUMPING;
            fx_walking_dust(2, npc->pos.x, npc->pos.y, npc->pos.z, 0.0f, 0.0f);
            script->functionTemp[0] = 12;

            if (basic_ai_try_detect_player(territory, enemy, aiSettings->chaseRadius, aiSettings->unkChase, 1) == 0) {
                s32 emoteTemp;

                fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &emoteTemp);
                npc->duration = 25;
                script->functionTemp[0] = 14;
            }
            return;
        }
    }
    npc->pos.y += npc->jumpVelocity;
    npc->jumpVelocity -= npc->jumpScale;
}
