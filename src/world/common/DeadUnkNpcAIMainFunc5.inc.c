#include "dead.h"
#include "common.h"
#include "npc.h"
#include "effects.h"
#include "dead_structs.h"

ApiStatus N(DeadUnkNpcAIMainFunc5)(Evt* script, s32 isInitialCall) {
    DeadEnemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = (NpcAISettings*)evt_get_variable(script, *args++);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 100.0f;
    territory.unk_1C = 0;

    enemy->unk_108.x = npc->pos.x;
    enemy->unk_108.y = npc->pos.y;
    enemy->unk_108.z = npc->pos.z;
    enemy->unk_114 = 0.01f;
    enemy->unk_118 = 0.01f;

    if (isInitialCall) {
        enemy->varTable[6] = npc->collisionHeight;
        enemy->varTable[8] = 0;
        enemy->unk_B5 = 0;
        enemy->unk_B0 |= 8;
    }

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        enemy->unk_07 = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~NPC_FLAG_NO_Y_MOVEMENT;
        npc->collisionHeight = enemy->varTable[6];
        enemy->varTable[9] = 0;

        if (!enemy->territory->wander.isFlying) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
        }

        if (enemy->unk_B0 & 4) {
            s32 emoteTemp;

            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            fx_emote(2, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0x28, &emoteTemp);
            enemy->unk_B0 &= ~4;
        } else if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->functionTemp[0] = 12;
            enemy->flags &= ~ENEMY_FLAGS_40000000;
        }
    }

    if (enemy->varTable[9] > 0) {
        enemy->varTable[9]--;
        if (enemy->varTable[9] == 0) {
            if (npc->currentAnim.w == 0x55002E || npc->currentAnim.w == 0x55002F) {
                npc->currentAnim.w = 0x55000C;
            }
        } else {
            return ApiStatus_BLOCK;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            func_800495A0(script, aiSettings, territoryPtr);
            npc->collisionHeight = enemy->varTable[6];
        case 1:
            func_800496B8(script, aiSettings, territoryPtr);
            break;
        case 2:
            base_UnkNpcAIFunc1(script, aiSettings, territoryPtr);
            if (enemy->varTable[7] == 6) {
                if (rand_int(100) < 33) {
                    if (enemy->varTable[8] != 0) {
                        enemy->varTable[8] = 0;
                        enemy->unk_B5 = 0;
                        npc->currentAnim.w = 0x55002F;
                    } else {
                        enemy->varTable[8] = 1;
                        enemy->unk_B5 = 1;
                        npc->currentAnim.w = 0x55002E;
                    }
                    enemy->varTable[9] = 7;
                    return ApiStatus_BLOCK;
                }
            }
        case 3:
            func_80049C04(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(set_script_owner_npc_anim)(script, aiSettings, territoryPtr);
        case 13:
            N(UnkDistFunc)(script, aiSettings, territoryPtr);
            break;
        case 14:
            N(UnkNpcAIFunc12)(script, aiSettings, territoryPtr);
            break;
        case 15:
            N(set_script_owner_npc_col_height)(script, aiSettings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
            break;
    }

    if (enemy->varTable[7] == 6) {
        if (enemy->varTable[8] != 0) {
            enemy->unk_B5 = 1;
        } else {
            enemy->unk_B5 = 0;
        }
        if (enemy->varTable[8] != 0) {
            switch (npc->currentAnim.w - 0x550004) {
                case 0:
                case 8:
                case 10:
                case 12:
                case 14:
                case 18:
                case 20:
                    npc->currentAnim.w++;
                    break;
            }
        }
    }

    return ApiStatus_BLOCK;
}
