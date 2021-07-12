#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc7)(ScriptInstance* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Enemy* enemy2;
    Npc* npc2;
    f32 posX, posZ;
    s32 func;

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0].s = 0;
        npc->duration = 0;
        npc->flags |= 0x102;
        enemy->flags |= 0x1F300000;
        npc->pos.x = 0.0f;
        npc->pos.y = -1000.0f;
        npc->pos.z = 0.0f;
        if (enemy->unk_B0 & 4) {
            enemy->unk_B0 &= ~4;
        }
    }

    func = script->functionTemp[0].s;
    switch (func) {
        case 0:
            enemy2 = get_enemy(enemy->npcID - 1);
            npc2 = get_npc_unsafe(enemy2->npcID);
            enemy->unk_07 = 1;
            if (enemy2->varTable[0] == 3) {
                if (enemy->varTable[15] != 0) {
                    ai_enemy_play_sound(npc2, enemy->varTable[15], 0);
                }
                posX = npc2->pos.x;
                posZ = npc2->pos.z;
                add_vec2D_polar(&posX, &posZ, enemy->varTable[1], 270.0f - npc2->renderYaw);

                npc->pos.x = posX;
                enemy->unk_10.x = npc->pos.x;

                npc->pos.y = npc2->pos.y + enemy->varTable[0];
                enemy->unk_10.y = npc->pos.y;

                npc->pos.z = posZ;
                enemy->unk_10.z = npc->pos.z;

                npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
                enemy->flags &= 0xE0EFFFFF;
                npc->duration = 0;
                script->functionTemp[0].s = 1;
            }
            break;

        case 1:
            enemy2 = get_enemy(enemy->npcID - 1);
            get_npc_unsafe(enemy2->npcID);
            npc->duration++;
            if (npc->duration >= enemy->varTable[4]) {
                enemy->unk_07 = 0;
            }
            if (enemy2->varTable[0] == 4) {
                enemy->flags |= 0x1F100000;
                npc->pos.x = 0.0f;
                npc->pos.y = -1000.0f;
                npc->pos.z = 0.0f;
                enemy->unk_07 = func;
                script->functionTemp[0].s = 0;
            }
            break;
    }

    return ApiStatus_BLOCK;
}
