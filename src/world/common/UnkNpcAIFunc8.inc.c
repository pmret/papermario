#include "common.h"
#include "map.h"

static void UnkNpcAIFunc8(ScriptInstance* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if ((npc->duration << 0x10) <= 0) {
        enemy->varTable[0] = 4;
        npc->currentAnim = enemy->animList[0];
        npc->duration = enemy->varTable[3];
        if (enemy->varTable[3] >= 8) {
            s32 something;

            fx_emote(3, npc, 0, npc->collisionHeight, 1.0f, 2.0f, -20.0f, enemy->varTable[3] - 1, &something);
        }
        script->functionTemp[0].s = 33;
    }
}
