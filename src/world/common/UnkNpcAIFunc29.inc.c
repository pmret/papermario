#include "common.h"
#include "map.h"
#include "effects.h"

void N(UnkNpcAIFunc29)(ScriptInstance *script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 d100;

    if (enemy->varTable[0] == 0) {
        if (rand_int(100) >= 50) {
            enemy->varTable[0] = 3;
        } else {
            enemy->varTable[0] = 1;
        }
        set_npc_yaw(npc, 270.0f);
    }

    switch (enemy->varTable[0]) {
        case 1:
            enemy->varTable[0] = 2;
            enemy->varTable[1] = 0;
            npc->currentAnim.w = 0x42000F;
        case 2:
            enemy->varTable[1]++;
            if (enemy->varTable[1] > 50) {
                enemy->varTable[0] = 5;
            }
            break;
        case 3:
            enemy->varTable[0] = 4;
            enemy->varTable[1] = 0;
            npc->currentAnim.w = 0x420010;
        case 4:
            enemy->varTable[1]++;
            if (enemy->varTable[1] == 0x19) {
                npc->yaw = 90.0f;
            }
            if (enemy->varTable[1] > 60) {
                enemy->varTable[0] = 5;
            }
            break;
        case 5:
            enemy->varTable[0] = 6;
            enemy->varTable[1] = 0;
            npc->currentAnim.w = 0x420003;
            fx_sweat(0, npc->pos.x, npc->pos.y, npc->pos.z, npc->collisionHeight, 0, 0xA);
        case 6:
            enemy->varTable[1]++;
            if (enemy->varTable[1] > 10) {
                d100 = rand_int(100);

                if (d100 < 90) {
                    enemy->varTable[0] = 7;
                } else if (d100 >= 95) {
                    enemy->varTable[0] = 3;
                } else {
                    enemy->varTable[0] = 1;
                }
            }
            break;
    }

    if (enemy->varTable[0] == 7) {
        script->functionTemp[0] = 0;
    }
}
