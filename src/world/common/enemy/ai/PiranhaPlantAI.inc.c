// visual enemy
#include "common.h"
#include "npc.h"
#include "effects.h"

// hitbox enemy
#include "world/common/enemy/ai/WanderMeleeAI.inc.c"

void N(PiranhaPlantAI_00)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    if (npc->duration > 0) {
        npc->duration--;
    } else {
        enemy->varTable[0] = 0;
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        script->functionTemp[1] = 0;
        script->functionTemp[0] = 1;
    }
}

void N(PiranhaPlantAI_01)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EffectInstance* temp;

    if (basic_ai_check_player_dist(territory, enemy, aiSettings->alertRadius, aiSettings->alertOffsetDist, 0)) {
        ai_enemy_play_sound(npc, SOUND_BURROW_DIG, 0);
        fx_emote(EMOTE_EXCLAMATION, npc, 0, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 10, &temp);
        ai_enemy_play_sound(npc, SOUND_2F4, SOUND_PARAM_MORE_QUIET);
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_MELEE_PRE];
        npc->duration = enemy->varTable[8];
        script->functionTemp[0] = 10;
    }
}

void N(PiranhaPlantAI_10)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 phi_s7 = FALSE;
    s32 phi_fp = FALSE;
    f32 sp38;
    f32 yaw;
    f32 yaw2;
    f32 moveSpeed;
    f32 posRadius;
    s32 cond1;
    s32 cond2;
    f32 terSize;
    f32 sp20;
    f32 sp24;
    f32 sp28;
    f32 sp2C;
    f32 sp30;
    f32 sp34;

    npc->duration--;
    if (enemy->varTable[9] >= npc->duration) {
        enemy->flags |= (ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP |
                         ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER);
    }

    if (npc->duration == 0) {
        if (clamp_angle(gPlayerStatusPtr->spriteFacingAngle) < 180.0f) {
            yaw2 = clamp_angle(gCameras[gCurrentCameraID].curYaw - 90.0f);
        } else {
            yaw2 = clamp_angle(gCameras[gCurrentCameraID].curYaw + 90.0f);
        }

        yaw = clamp_angle(yaw2 + 180.0f);
        if (enemy->varTable[7] == 0) {
            moveSpeed = 32.0f;

            if (gPlayerStatusPtr->actionState != 0) {
                moveSpeed = 100.0f;
                if (gPlayerStatusPtr->actionState == 1) {
                    moveSpeed = 90.0f;
                }
            }
        } else {
            moveSpeed = 38.0f;

            if (gPlayerStatusPtr->actionState != 0) {
                moveSpeed = 90.0f;
                if (gPlayerStatusPtr->actionState == 1) {
                    moveSpeed = 75.0f;
                }
            }
        }

        npc->pos.x = gPlayerStatusPtr->pos.x;
        npc->pos.z = gPlayerStatusPtr->pos.z;
        add_vec2D_polar(&npc->pos.x, &npc->pos.z, npc->collisionDiameter, yaw);
        npc_move_heading(npc, moveSpeed + npc->collisionDiameter, yaw2);

        if (enemy->varTable[7] == 0) {
            if (npc->pos.x > 380.0) {
                npc->pos.x = 380.0f;
            }
            if (npc->pos.x < -380.0) {
                npc->pos.x = -380.0f;
            }
            if (npc->pos.z > 380.0) {
                npc->pos.z = 380.0f;
            }
            if (npc->pos.z < -380.0) {
                npc->pos.z = -380.0f;
            }

            sp38 = sqrtf(SQ(npc->pos.x) + SQ(npc->pos.z));
            yaw2 = atan2(0.0f, 0.0f, npc->pos.x, npc->pos.z);

            if (sp38 < 305.0) {
                npc->pos.x = 0.0f;
                npc->pos.z = 0.0f;
                add_vec2D_polar(&npc->pos.x, &npc->pos.z, 305.0f, yaw2);
            } else if (sp38 > 375.0) {
                npc->pos.x = 0.0f;
                npc->pos.z = 0.0f;
                add_vec2D_polar(&npc->pos.x, &npc->pos.z, 375.0f, yaw2);
            }
        } else {
            if (!(npc->flags & NPC_FLAG_IGNORE_WORLD_COLLISION)) {
                sp20 = gPlayerStatusPtr->pos.x;
                sp24 = gPlayerStatusPtr->pos.y + 18.0;
                sp28 = gPlayerStatusPtr->pos.z;
                if (npc_test_move_simple_with_slipping(npc->collisionChannel, &sp20, &sp24, &sp28, moveSpeed, yaw2, npc->collisionHeight, npc->collisionDiameter)) {
                    sp20 = gPlayerStatusPtr->pos.x;
                    sp24 = gPlayerStatusPtr->pos.y + 45.0;
                    sp28 = gPlayerStatusPtr->pos.z;
                    cond1 = npc_test_move_simple_with_slipping(npc->collisionChannel, &sp20, &sp24, &sp28, moveSpeed, yaw2, npc->collisionHeight, npc->collisionDiameter);
                    sp2C = npc->pos.x;
                    sp30 = npc->pos.y + 100.0;
                    sp34 = npc->pos.z;
                    sp38 = 200.0f;
                    cond2 = npc_raycast_down_sides(npc->collisionChannel, &sp2C, &sp30, &sp34, &sp38);
                    if (!cond1 && cond2 && sp38 > 80.0 && sp38 < 120.0 && npc->pos.y != sp30) {
                        phi_fp = TRUE;
                    } else {
                        sp20 = gPlayerStatusPtr->pos.x;
                        sp24 = gPlayerStatusPtr->pos.y + 10.0;
                        sp28 = gPlayerStatusPtr->pos.z;
                        npc_test_move_simple_with_slipping(npc->collisionChannel, &sp20, &sp24, &sp28, moveSpeed, yaw2, npc->collisionHeight, npc->collisionDiameter);
                        posRadius = dist2D(gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z, sp20, sp28);
                        npc->pos.x = gPlayerStatusPtr->pos.x;
                        npc->pos.z = gPlayerStatusPtr->pos.z;
                        add_vec2D_polar(&npc->pos.x, &npc->pos.z, npc->collisionDiameter, yaw);
                        npc_move_heading(npc, posRadius + npc->collisionDiameter, yaw2);
                        phi_s7 = TRUE;
                    }
                }
            } else {
                sp20 = gPlayerStatusPtr->pos.x;
                sp24 = gPlayerStatusPtr->pos.y + 18.0;
                sp28 = gPlayerStatusPtr->pos.z;
                if (npc_test_move_simple_with_slipping(npc->collisionChannel, &sp20, &sp24, &sp28, moveSpeed, yaw2, npc->collisionHeight, npc->collisionDiameter)) {
                    posRadius = dist2D(gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z, sp20, sp28);
                    npc->pos.x = gPlayerStatusPtr->pos.x;
                    npc->pos.z = gPlayerStatusPtr->pos.z;
                    add_vec2D_polar(&npc->pos.x, &npc->pos.z, npc->collisionDiameter, yaw);
                    npc_move_heading(npc, posRadius + npc->collisionDiameter, yaw2);
                }
            }
        }

        if (is_point_within_region(territory->shape, territory->pointX, territory->pointZ, npc->pos.x, npc->pos.z, territory->sizeX, territory->sizeZ)) {
            switch (territory->shape) {
                case SHAPE_CYLINDER:
                    sp38 = dist2D(npc->pos.x, npc->pos.z, territory->pointX, territory->pointZ);

                    if (territory->sizeX < sp38) {
                        terSize = atan2(territory->pointX, territory->pointZ, npc->pos.x, npc->pos.z);
                        npc->pos.x = territory->pointX;
                        npc->pos.z = territory->pointZ;
                        add_vec2D_polar(&npc->pos.x, &npc->pos.z, territory->sizeX, terSize);
                    }
                    break;
                case SHAPE_RECT:
                    terSize = territory->pointX + territory->sizeX;
                    if (npc->pos.x > terSize) {
                        npc->pos.x = terSize;
                    }

                    terSize = territory->pointX - territory->sizeX;
                    if (npc->pos.x < terSize) {
                        npc->pos.x = terSize;
                    }

                    terSize = territory->pointZ + territory->sizeZ;
                    if (npc->pos.z > terSize) {
                        npc->pos.z = terSize;
                    }

                    terSize = territory->pointZ - territory->sizeZ;
                    if (npc->pos.z < terSize) {
                        npc->pos.z = terSize;
                    }
                    break;
            }
        }

        if (!phi_s7 && (!(npc->flags & NPC_FLAG_8) || phi_fp)) {
            sp20 = npc->pos.x;
            sp38 = 400.0f;
            sp28 = npc->pos.z;
            sp24 = npc->pos.y + 150.0;

            if (npc_raycast_down_sides(npc->collisionChannel, &sp20, &sp24, &sp28, &sp38) != 0) {
                npc->pos.y = sp24;
            }
        }

        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z);
        ai_enemy_play_sound(npc, SOUND_BURROW_SURFACE, 0);
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_MELEE_HIT];
        npc->duration = enemy->varTable[10];
        script->functionTemp[0] = 11;
    }
}

void N(PiranhaPlantAI_11)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (enemy->varTable[11] >= npc->duration) {
        enemy->flags &= ~(ENEMY_FLAG_100000 | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP | ENEMY_FLAG_IGNORE_HAMMER | ENEMY_FLAG_CANT_INTERACT | ENEMY_FLAG_IGNORE_PARTNER);
    }
    if (npc->duration == 0) {
        npc->curAnim = enemy->animList[10];
        npc->duration = 0;
        script->functionTemp[0] = 12;
    }
}

void N(PiranhaPlantAI_12)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EffectInstance* temp;

    npc->duration++;
    if (npc->duration == enemy->varTable[13]) {
        npc->curAnim = enemy->animList[11];
    }
    if (npc->duration == enemy->varTable[14]) {
        enemy->varTable[0] = 3;
    }
    if (npc->duration >= enemy->varTable[12]) {
        enemy->varTable[0] = 4;
        npc->duration = 8;
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];
        fx_emote(EMOTE_FRUSTRATION, npc, 0, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 10, &temp);
        script->functionTemp[0] = 13;
    }
}

void N(PiranhaPlantAI_13)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        npc->duration = enemy->varTable[15];
        script->functionTemp[0] = 14;
    }
}

void N(PiranhaPlantAI_LosePlayer)(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EffectInstance* retVal;

    npc->duration--;
    if (npc->duration == 0) {
        if (basic_ai_check_player_dist(territory, enemy, aiSettings->alertRadius, aiSettings->alertOffsetDist, 0) == 0) {
            fx_emote(EMOTE_QUESTION, npc, 0, npc->collisionHeight, 1, 2, -20, 15, &retVal);
        }
        npc->duration = 0;
        script->functionTemp[0] = 0;
    }
}

#include "common.h"
#include "npc.h"

#ifdef _DEAD_H_
void func_8004D8E0(Enemy*);
#endif

s32 N(PiranhaPlantAI_Main)(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    EnemyDetectVolume territory;
    #ifdef _DEAD_H_
    MobileAISettings* npcAISettings = (MobileAISettings*)evt_get_variable(script, *args++);
    EnemyDetectVolume* territoryPtr = &territory;
    #else
    EnemyDetectVolume* territoryPtr = &territory;
    MobileAISettings* npcAISettings = (MobileAISettings*)evt_get_variable(script, *args++);
    #endif

    territory.skipPlayerDetectChance = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detectPos.x;
    territory.pointZ = enemy->territory->wander.detectPos.z;
    territory.sizeX = enemy->territory->wander.detectSize.x;
    territory.sizeZ = enemy->territory->wander.detectSize.z;
    territory.halfHeight = 200.0f;
    territory.detectFlags = 0;

    #ifdef _DEAD_H_
    // this function doesn't seem to have a known counterpart, perhaps related to the difference in the Enemy struct
    func_8004D8E0(enemy);
    if (enemy->flags & ENEMY_FLAG_100000) {
        enemy->unk_114 = 10.0f;
        enemy->unk_118 = 0.7f;
    }
    #endif

    if (isInitialCall || (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND)) {
        script->AI_TEMP_STATE = AI_STATE_PIRANHA_PLANT_00;
        npc->duration = 0;
        npc->curAnim = enemy->animList[ENEMY_ANIM_INDEX_IDLE];

        enemy->AI_VAR_ATTACK_STATE = MELEE_HITBOX_STATE_NONE;
        if (enemy->aiFlags & ENEMY_AI_FLAG_SUSPEND) {
            script->AI_TEMP_STATE = AI_STATE_SUSPEND;
            script->functionTemp[1] = AI_STATE_PIRANHA_PLANT_00;
            enemy->aiFlags &= ~ENEMY_AI_FLAG_SUSPEND;
        }
    }

    switch (script->AI_TEMP_STATE) {
        case AI_STATE_PIRANHA_PLANT_00:
            N(PiranhaPlantAI_00)(script, npcAISettings, territoryPtr);
        case AI_STATE_PIRANHA_PLANT_01:
            N(PiranhaPlantAI_01)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_PIRANHA_PLANT_10:
            N(PiranhaPlantAI_10)(script, npcAISettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_PIRANHA_PLANT_11) {
                break;
            }
        case AI_STATE_PIRANHA_PLANT_11:
            N(PiranhaPlantAI_11)(script, npcAISettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_PIRANHA_PLANT_12) {
                break;
            }
        case AI_STATE_PIRANHA_PLANT_12:
            N(PiranhaPlantAI_12)(script, npcAISettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_PIRANHA_PLANT_13) {
                break;
            }
        case AI_STATE_PIRANHA_PLANT_13:
            N(PiranhaPlantAI_13)(script, npcAISettings, territoryPtr);
            if (script->AI_TEMP_STATE != AI_STATE_LOSE_PLAYER) {
                break;
            }
        case AI_STATE_LOSE_PLAYER:
            N(PiranhaPlantAI_LosePlayer)(script, npcAISettings, territoryPtr);
            break;
        case AI_STATE_SUSPEND:
            basic_ai_suspend(script);
            break;
    }
    return ApiStatus_BLOCK;
}

