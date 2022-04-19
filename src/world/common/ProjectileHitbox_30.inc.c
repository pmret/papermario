#include "common.h"
#include "npc.h"
#include "effects.h"

void N(ProjectileHitbox_30)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 npcID;

    npc->duration--;
    if (npc->duration <= 0) {
        npcID = N(ProjectileHitbox_GetUsableProjectileID)(script);
        if (npcID < 0) {
            s32 emoteTemp;

            fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteTemp);
            npc->currentAnim.w = enemy->animList[0];
        } else {
            Enemy* enemy2;

            npc->currentAnim.w = enemy->animList[9];
            enemy2 = get_enemy(npcID);
            enemy2->varTable[4] = enemy->npcID;
            enemy2->varTable[0] = 1;
        }
        npc->duration = enemy->varTable[2];
        script->functionTemp[0] = AI_STATE_PROJECTILE_HITBOX_33;
    }
}
