#include "common.h"
#include "npc.h"
#include "effects.h"

void N(UnkNpcAIFunc49)(Evt* script, f32 arg1, f32 arg2, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 npcID;

    npc->duration--;
    if (npc->duration <= 0) {
        npcID = N(UnkFunc61)(script);
        if (npcID < 0) {
            s32 sp28;

            fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &sp28);
            npc->currentAnim.w = enemy->animList[0];
        } else {
            Enemy* enemy2;

            npc->currentAnim.w = enemy->animList[9];
            enemy2 = get_enemy(npcID);
            enemy2->varTable[4] = enemy->npcID;
            enemy2->varTable[0] = 1;
        }
        npc->duration = enemy->varTable[2];
        script->functionTemp[0] = 33;
    }
}
