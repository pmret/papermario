#include "common.h"
#include "map.h"

void N(UnkNpcAIFunc8)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration <= 0) {
        enemy->varTable[0] = 4;
        npc->currentAnim.w = enemy->animList[0];
        npc->duration = enemy->varTable[3];
        if (enemy->varTable[3] >= 8) {
            s32 something;

            fx_emote(3, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, enemy->varTable[3] - 1, &something);
        }
        script->functionTemp[0] = 33;
    }
}
