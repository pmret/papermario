#include "dead.h"
#include "common.h"
#include "npc.h"
#include "effects.h"
#include "dead_structs.h"
#include "sprite/npc/bony_beetle.h"

ApiStatus N(UnkNpcAIMainFunc6)(Evt* script, s32 isInitialCall) {
    DeadEnemy* enemy = (DeadEnemy*)script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;
    NpcAISettings* aiSettings = (NpcAISettings*)evt_get_variable(script, *args);
    u32 x, y, z;
    f32 x2, y2, z2, w2;
    Npc* npc2;

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 65.0f;
    territory.unk_1C = 0;

    enemy->unk_108.x = npc->pos.x;
    enemy->unk_108.y = npc->pos.y;
    enemy->unk_108.z = npc->pos.z;
    enemy->unk_114 = 0.0001f;
    enemy->unk_118 = 0.0001f;

    if (isInitialCall) {
        enemy->varTable[6] = npc->collisionHeight;
        enemy->unk_B0 |= ENEMY_AI_FLAGS_8;
    }

    if (isInitialCall || (enemy->varTable[10] == 100)) {
        script->functionTemp[0] = 100;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[ENEMY_ANIM_IDLE];
        npc->flags &= ~NPC_FLAG_NO_Y_MOVEMENT;
        enemy->flags |= ENEMY_FLAGS_200000;
        npc->flags &= ~NPC_FLAG_GRAVITY;
        npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
        enemy->varTable[10] = 0;
        enemy->varTable[11] = -1;
        npc->pos.x = 0.0f;
        npc->pos.y = -1000.0f;
        npc->pos.z = 0.0f;
    }

    if (enemy->unk_B0 & ENEMY_AI_FLAGS_4) {
        npc->duration = 0;
        npc->collisionHeight = enemy->varTable[6];
        enemy->unk_B0 &= ~ENEMY_AI_FLAGS_4;
        if (npc->flags & NPC_FLAG_NO_Y_MOVEMENT) {
            npc->currentAnim.w = 0x4A0018;
            npc->moveSpeed = 0.0f;
            npc->jumpVelocity = 0.0f;
            npc->jumpScale = 1.0f;
            script->functionTemp[0] = 102;
        } else {
            s32 emoteTemp;

            fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0x28, &emoteTemp);
            npc->currentAnim.w = enemy->animList[ENEMY_ANIM_IDLE];
            script->functionTemp[1] = 0;
            script->functionTemp[0] = 200;
        }
    }
    get_screen_coords(0, npc->pos.x, npc->pos.y, npc->pos.z, &x, &y, &z);
    if (script->functionTemp[0] < 100 && x + 50 >= 421) {
        script->functionTemp[0] = 110;
    }

    switch (script->functionTemp[0]) {
        case 0:
            func_800495A0(script, aiSettings, territoryPtr);
            npc->collisionHeight = enemy->varTable[6];
            if (enemy->varTable[13] != 0) {
                if (npc->pos.y <= 0.0) {
                    npc->flags &= ~NPC_FLAG_GRAVITY;
                    npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
                } else {
                    npc->flags |= NPC_FLAG_GRAVITY;
                    npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
                }
            }
            func_800496B8(script, aiSettings, territoryPtr);
            break;
        case 1:
            func_800496B8(script, aiSettings, territoryPtr);
            break;
        case 2:
            base_PatrolAI_LoiterInit(script, aiSettings, territoryPtr);
        case 3:
            func_80049C04(script, aiSettings, territoryPtr);
            break;
        case 12:
            N(set_script_owner_npc_anim)(script, aiSettings, territoryPtr);
        case 13:
            N(UnkDistFunc)(script, aiSettings, territoryPtr);
            npc->collisionHeight = enemy->varTable[6];
            break;
        case 14:
            N(UnkNpcAIFunc12)(script, aiSettings, territoryPtr);
            break;
        case 15:
            N(set_script_owner_npc_col_height)(script, aiSettings, territoryPtr);
            break;
        case 100:
            if (enemy->varTable[10] != 2) {
                break;
            }
            npc2 = get_npc_unsafe(get_enemy(enemy->varTable[11])->npcID);
            if (npc2->yaw < 180.0) {
                npc->pos.x = npc2->pos.x + 12.0;
            } else {
                npc->pos.x = npc2->pos.x - 12.0;
            }
            npc->pos.y = npc2->pos.y + 25.0;
            npc->pos.z = npc2->pos.z + 1.0;
            npc->rotation.y = 0.0f;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
            npc->flags &= ~NPC_FLAG_2;
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->renderYaw = 0.0f;
            npc->currentAnim.w = 0x4A0018;
            script->functionTemp[0] = 101;
        case 101:
            if (enemy->varTable[10] != 3) {
                break;
            }
            enemy->varTable[10] = 4;
            npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
            npc->moveSpeed = 2.5f;
            npc->jumpVelocity = 8.0f;
            npc->jumpScale = 0.8f;
            npc->flags |= NPC_FLAG_NO_Y_MOVEMENT;
            script->functionTemp[0] = 102;
        case 102:
            if (npc->moveSpeed > 0.0) {
                x2 = npc->pos.x;
                y2 = npc->pos.y;
                z2 = npc->pos.z;
                if (npc_test_move_simple_with_slipping(npc->collisionChannel, &x2, &y2, &z2, npc->moveSpeed, npc->yaw, npc->collisionHeight,
                                  npc->collisionRadius) == 0) {
                    npc_move_heading(npc, npc->moveSpeed, npc->yaw);
                } else {
                    npc->moveSpeed = 0.0f;
                }
            }
            if (npc->jumpVelocity < 0.0) {
                x2 = npc->pos.x;
                y2 = npc->pos.y + 13.0;
                z2 = npc->pos.z;
                w2 = fabsf(npc->jumpVelocity) + 16.0;
                if ((npc_raycast_down_sides(npc->collisionChannel, &x2, &y2, &z2, &w2) != 0) && (w2 <= (fabsf(npc->jumpVelocity) + 13.0))) {
                    npc->pos.y = y2;
                    enemy->territory->wander.point.x = npc->pos.x;
                    enemy->territory->wander.point.y = npc->pos.y;
                    enemy->territory->wander.point.z = npc->pos.z;
                    enemy->territory->wander.detect.x = npc->pos.x;
                    enemy->territory->wander.detect.y = npc->pos.y;
                    enemy->territory->wander.detect.z = npc->pos.z;
                    enemy->varTable[10] = 5;
                    if (enemy->varTable[13] != 0) {
                        if (npc->pos.y <= 0.0) {
                            npc->flags &= ~NPC_FLAG_GRAVITY;
                            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
                        } else {
                            npc->flags |= NPC_FLAG_GRAVITY;
                            npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
                        }
                    } else if (!enemy->territory->wander.isFlying) {
                        npc->flags |= NPC_FLAG_GRAVITY;
                        npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
                    } else {
                        npc->flags &= ~NPC_FLAG_GRAVITY;
                        npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT;
                    }
                    npc->flags |= NPC_FLAG_40000;
                    npc->flags &= ~NPC_FLAG_NO_Y_MOVEMENT;
                    npc->jumpVelocity = 0.0f;
                    npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
                    npc->currentAnim.w = 0x4A001A;
                    npc->duration = 3;
                    script->functionTemp[0] = 103;
                    break;
                }
            }
            npc->pos.y += npc->jumpVelocity;
            npc->jumpVelocity -= npc->jumpScale;
            break;
        case 103:
            npc->duration--;
            if (npc->duration <= 0) {
                npc->flags &= ~NPC_FLAG_40000;
                npc->currentAnim.w = 0x4A0001;
                script->functionTemp[0] = 0;
            }
            break;
        case 110:
            npc->duration = 30;
            npc->pos.x = 0.0f;
            npc->pos.z = 0.0f;
            npc->pos.y = -1000.0f;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_2;
            npc->flags &= ~NPC_FLAG_GRAVITY;
            script->functionTemp[0] = 111;
        case 111:
            npc->duration--;
            if (npc->duration <= 0) {
                enemy->varTable[10] = 0;
                script->functionTemp[0] = 100;
            }
            break;
        case 200:
            func_8004A73C(script);
            break;
    }
    return ApiStatus_BLOCK;
}
