#include "common.h"
#include "npc.h"
#include "effects.h"

ApiStatus N(UnkNpcAIMainFunc7)(Evt* script, s32 isInitialCall) {
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    Enemy* enemy = script->owner1.enemy;
    Bytecode* args = script->ptrReadPos;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    NpcAISettings* settings = (NpcAISettings*) evt_get_variable(script, *args++);
    f32 dist;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 40.0f;
    territory.unk_1C = 0;

    if (isInitialCall || (enemy->unk_B0 & 4)) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        npc->flags &= ~NPC_FLAG_NO_Y_MOVEMENT;

        if (!enemy->territory->wander.isFlying) {
            npc->flags |= NPC_FLAG_GRAVITY;
            npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
        } else {
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
        }

        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->unk_B0 &= ~4;
        } else if (enemy->flags & ENEMY_FLAGS_40000000) {
            script->functionTemp[0] = 12;
        }
        enemy->unk_B0 &= ~4;
        enemy->flags &= ~ENEMY_FLAGS_40000000;
    }

    switch (script->functionTemp[0]) {
        case 0:
            func_800495A0(script, settings, territoryPtr);
            /* fallthrough */
        case 1:
            func_800496B8(script, settings, territoryPtr);
            break;
        case 2:
            base_UnkNpcAIFunc1(script, settings, territoryPtr);
            /* fallthrough */
        case 3:
            func_80049C04(script, settings, territoryPtr);
            break;
        case 10:
            func_80049E3C(script, settings, territoryPtr);
            /* fallthrough */
        case 11:
            func_80049ECC(script, settings, territoryPtr);
            break;
        case 12:
            dist = dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
            if (enemy->varTable[0] == 0 || enemy->varTable[0] < dist) {
                N(UnkNpcAIFunc48)(script, settings->chaseRadius, settings->unk_28.f, territoryPtr);
                if (script->functionTemp[0] != 12) {
                    break;
                }
            }
            func_80049F7C(script, settings, territoryPtr);
            /* fallthrough */
        case 13:
            func_8004A124(script, settings, territoryPtr);
            break;
        case 14:
            func_8004A3E8(script, settings, territoryPtr);
            break;
        case 30:
            N(UnkNpcAIFunc49(script));
            break;
        case 31:
            N(UnkSetDurationFunc(script));
            break;
        case 32:
            N(UnkNpcAIFunc9(script));
            break;
        case 33:
            N(UnkDurationCheckNoArgs(script));
            break;
        case 99:
            func_8004A73C(script);
            break;
    }
    return ApiStatus_BLOCK;
}
