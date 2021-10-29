#include "common.h"
#include "npc.h"
#include "effects.h"

void N(UnkNpcAIFunc11)(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* arg2) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (func_800490B4(arg2, enemy, aiSettings->chaseSpeed, aiSettings->unk_1C.f, 1) == 0) {
        s32 something;

        fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &something);
        npc->currentAnim.w = enemy->animList[0];
        npc->duration = 25;
        script->functionTemp[0] = 14;
    } else {
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        func_8003D660(npc, 1);
        npc->duration--;
        if (npc->duration == 0) {
            script->functionTemp[0] = 12;
        }
    }
}
