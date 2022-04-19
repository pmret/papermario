#include "common.h"
#include "npc.h"
#include "effects.h"

void N(UnkNpcAIFunc48)(Evt* script, f32 arg1, f32 arg2, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (basic_ai_try_detect_player(territory, enemy, arg1, arg2, 1) == 0) {
        s32 sp28;

        fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &sp28);
        npc->currentAnim.w = enemy->animList[0];
        npc->duration = 20;
        script->functionTemp[0] = 33;
    } else {
        s32 npcID = N(ProjectileHitbox_GetUsableProjectileID)(script);

        if (npcID != NPC_SELF && get_enemy(npcID)->varTable[0] == 0 && npc->turnAroundYawAdjustment == 0) {
            npc->currentAnim.w = enemy->animList[8];
            npc->duration = enemy->varTable[1];
            script->functionTemp[0] = 30;
        }
    }
}
