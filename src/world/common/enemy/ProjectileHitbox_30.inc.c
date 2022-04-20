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
            Enemy* hitboxEnemy;

            npc->currentAnim.w = enemy->animList[9];
            hitboxEnemy = get_enemy(npcID);
            hitboxEnemy->varTable[4] = enemy->npcID;
            hitboxEnemy->varTable[0] = 1;
        }
        npc->duration = enemy->varTable[2];
        script->functionTemp[0] = AI_STATE_PROJECTILE_HITBOX_33;
    }
}
