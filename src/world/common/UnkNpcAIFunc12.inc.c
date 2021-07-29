#include "common.h"
#include "map.h"

void N(UnkNpcAIFunc12)(ScriptInstance* script, NpcAISettings* aiSettings, s32 arg2) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 temp;
    f32 f1;
    f32 f2;
    f32 f3;

    if (npc->duration == enemy->varTable[4] - 1) {
        enemy->unk_10.x = npc->pos.x;
        enemy->unk_10.y = npc->pos.y;
        enemy->unk_10.z = npc->pos.z;
        enemy->unk_07 = 1;
    }

    f1 = npc->pos.x;
    f2 = npc->pos.y;
    f3 = npc->pos.z;

    temp = npc_test_move_simple_with_slipping(npc->unk_80, &f1, &f2, &f3, npc->moveSpeed, npc->yaw, npc->collisionHeight, npc->collisionRadius);
    if (temp == 0) {
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
    }

    if ((npc->duration <= 0) || (--npc->duration <= 0) || (temp != 0)) {
        enemy->unk_07 = 0;
        npc->currentAnim.w = enemy->animList[10];
        npc->duration = 0;
        script->functionTemp[0] = 15;
    }
}
