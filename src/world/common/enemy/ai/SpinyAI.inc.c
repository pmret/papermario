// spiny AI

#include "common.h"
#include "npc.h"
#include "effects.h"
#include "sprite/npc/Spiny.h"

// prerequisites
#include "world/common/enemy/ai/TackleAI.inc.c"

API_CALLABLE(N(SpinyAI_Main)) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyDetectVolume territory;
    EnemyDetectVolume* territoryPtr = &territory;
    MobileAISettings* aiSettings = (MobileAISettings*)evt_get_variable(script, *args);
    u32 x, y, z;
    f32 x2, y2, z2, w2;
    Npc* npc2;

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detectPos.x;
    territory.pointZ = enemy->territory->wander.detectPos.z;
    territory.sizeX = enemy->territory->wander.detectSize.x;
    territory.sizeZ = enemy->territory->wander.detectSize.z;
    territory.halfHeight = 65.0f;
    territory.detectFlags = 0;

    #ifdef _DEAD_H_
    enemy->unk_108.x = npc->pos.x;
    enemy->unk_108.y = npc->pos.y;
    enemy->unk_108.z = npc->pos.z;
    enemy->unk_114 = 0.0001f;
    enemy->unk_118 = 0.0001f;
    #endif

    if (isInitialCall) {
        enemy->varTable[6] = npc->collisionHeight;
        enemy->aiFlags |= ENEMY_AI_FLAG_8;
    }

    if (isInitialCall || (enemy->varTable[10] == 100)) {
        script->AI_TEMP_STATE = 100;
        npc->duration = 0;
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        npc->flags &= ~NPC_FLAG_JUMPING;
        enemy->flags |= ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN;
        npc->flags &= ~NPC_FLAG_GRAVITY;
        npc->flags |= NPC_FLAG_8;
        enemy->varTable[10] = 0;
        enemy->varTable[11] = -1;
        npc->pos.x = NPC_DISPOSE_POS_X;
        npc->pos.y = NPC_DISPOSE_POS_Y;
        npc->pos.z = NPC_DISPOSE_POS_Z;
    }

    if (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND) {
        npc->duration = 0;
        npc->collisionHeight = enemy->varTable[6];
        enemy->aiFlags &= ~ENEMY_AI_FLAG_SUSPEND;
        if (npc->flags & NPC_FLAG_JUMPING) {
            npc->curAnim = ANIM_Spiny_Anim18;
            npc->moveSpeed = 0.0f;
            npc->jumpVel = 0.0f;
            npc->jumpScale = 1.0f;
            script->AI_TEMP_STATE = 102;
        } else {
            EffectInstance* emoteTemp;
            fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0x28, &emoteTemp);
            npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
            script->functionTemp[1] = 0;
            script->AI_TEMP_STATE = 200;
        }
    }
    get_screen_coords(0, npc->pos.x, npc->pos.y, npc->pos.z, &x, &y, &z);
    if (script->AI_TEMP_STATE < 100 && x + 50 >= 421) {
        script->AI_TEMP_STATE = 110;
    }

    switch (script->AI_TEMP_STATE) {
        case 0:
            basic_ai_wander_init(script, aiSettings, territoryPtr);
            npc->collisionHeight = enemy->varTable[6];
            if (enemy->varTable[13] != 0) {
                if (npc->pos.y <= 0.0) {
                    npc->flags &= ~NPC_FLAG_GRAVITY;
                    npc->flags |= NPC_FLAG_8;
                } else {
                    npc->flags |= NPC_FLAG_GRAVITY;
                    npc->flags &= ~NPC_FLAG_8;
                }
            }
            basic_ai_wander(script, aiSettings, territoryPtr);
            break;
        case 1:
            basic_ai_wander(script, aiSettings, territoryPtr);
            break;
        case 2:
            basic_ai_loiter_init(script, aiSettings, territoryPtr);
        case 3:
            basic_ai_loiter(script, aiSettings, territoryPtr);
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
            npc->rot.y = 0.0f;
            npc->flags |= NPC_FLAG_8;
            npc->flags &= ~NPC_FLAG_INVISIBLE;
            npc->flags &= ~NPC_FLAG_GRAVITY;
            npc->renderYaw = 0.0f;
            npc->curAnim = ANIM_Spiny_Anim18;
            script->AI_TEMP_STATE = 101;
        case 101:
            if (enemy->varTable[10] != 3) {
                break;
            }
            enemy->varTable[10] = 4;
            npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
            npc->moveSpeed = 2.5f;
            npc->jumpVel = 8.0f;
            npc->jumpScale = 0.8f;
            npc->flags |= NPC_FLAG_JUMPING;
            script->AI_TEMP_STATE = 102;
        case 102:
            if (npc->moveSpeed > 0.0) {
                x2 = npc->pos.x;
                y2 = npc->pos.y;
                z2 = npc->pos.z;
                if (npc_test_move_simple_with_slipping(npc->collisionChannel, &x2, &y2, &z2, npc->moveSpeed, npc->yaw, npc->collisionHeight,
                                  npc->collisionDiameter) == 0) {
                    npc_move_heading(npc, npc->moveSpeed, npc->yaw);
                } else {
                    npc->moveSpeed = 0.0f;
                }
            }
            if (npc->jumpVel < 0.0) {
                x2 = npc->pos.x;
                y2 = npc->pos.y + 13.0;
                z2 = npc->pos.z;
                w2 = fabsf(npc->jumpVel) + 16.0;
                if ((npc_raycast_down_sides(npc->collisionChannel, &x2, &y2, &z2, &w2) != 0) && (w2 <= (fabsf(npc->jumpVel) + 13.0))) {
                    npc->pos.y = y2;
                    enemy->territory->wander.centerPos.x = npc->pos.x;
                    enemy->territory->wander.centerPos.y = npc->pos.y;
                    enemy->territory->wander.centerPos.z = npc->pos.z;
                    enemy->territory->wander.detectPos.x = npc->pos.x;
                    enemy->territory->wander.detectPos.y = npc->pos.y;
                    enemy->territory->wander.detectPos.z = npc->pos.z;
                    enemy->varTable[10] = 5;
                    if (enemy->varTable[13] != 0) {
                        if (npc->pos.y <= 0.0) {
                            npc->flags &= ~NPC_FLAG_GRAVITY;
                            npc->flags |= NPC_FLAG_8;
                        } else {
                            npc->flags |= NPC_FLAG_GRAVITY;
                            npc->flags &= ~NPC_FLAG_8;
                        }
                    } else if (!enemy->territory->wander.isFlying) {
                        npc->flags |= NPC_FLAG_GRAVITY;
                        npc->flags &= ~NPC_FLAG_8;
                    } else {
                        npc->flags &= ~NPC_FLAG_GRAVITY;
                        npc->flags |= NPC_FLAG_8;
                    }
                    npc->flags |= NPC_FLAG_IGNORE_CAMERA_FOR_YAW;
                    npc->flags &= ~NPC_FLAG_JUMPING;
                    npc->jumpVel = 0.0f;
                    npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
                    npc->curAnim = ANIM_Spiny_Anim1A;
                    npc->duration = 3;
                    script->AI_TEMP_STATE = 103;
                    break;
                }
            }
            npc->pos.y += npc->jumpVel;
            npc->jumpVel -= npc->jumpScale;
            break;
        case 103:
            npc->duration--;
            if (npc->duration <= 0) {
                npc->flags &= ~NPC_FLAG_IGNORE_CAMERA_FOR_YAW;
                npc->curAnim = ANIM_Spiny_Anim01;
                script->AI_TEMP_STATE = 0;
            }
            break;
        case 110:
            npc->duration = 30;
            npc->pos.x = NPC_DISPOSE_POS_X;
            npc->pos.y = NPC_DISPOSE_POS_Y;
            npc->pos.z = NPC_DISPOSE_POS_Z;
            npc->flags |= NPC_FLAG_8 | NPC_FLAG_INVISIBLE;
            npc->flags &= ~NPC_FLAG_GRAVITY;
            script->AI_TEMP_STATE = 111;
        case 111:
            npc->duration--;
            if (npc->duration <= 0) {
                enemy->varTable[10] = 0;
                script->AI_TEMP_STATE = 100;
            }
            break;
        case 200:
            basic_ai_suspend(script);
            break;
    }
    return ApiStatus_BLOCK;
}

