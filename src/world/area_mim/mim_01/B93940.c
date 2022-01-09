#include "mim_01.h"

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

#include "world/common/UnkNpcAIFunc26.inc.c"

#include "world/common/UnkFunc7.inc.c"

#include "world/common/UnkNpcAIFunc27.inc.c"

#include "world/common/UnkNpcAIFunc31.inc.c"

#include "world/common/UnkNpcAIFunc32.inc.c"

//INCLUDE_ASM(s32, "world/area_mim/mim_01/B93940", func_80240F38_B94378);
void func_80240F38_B94378(Evt* script, NpcAISettings* aiSettings, EnemyTerritoryThing* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    PlayerStatus* playerStatus = gPlayerStatusPtr;
    f32 moveSpeed;
    f32* posX;
    s8 actionState;

    f32 sp20;
    f32 sp24;
    f32 sp28;
    f32 sp2C;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    Vec3f* temp_s0;
    Vec3f* temp_s0_3;
    f32 temp_a3;
    f32 theta;
    f32 temp_a3_4;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 yaw2;
    f32 yaw;
    f32 temp_f2;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f2_6;
    f32 temp_f2_7;
    f32* temp_a1;
    f32* temp_a1_2;
    f32* temp_a1_3;
    f32* temp_a1_4;
    f32* temp_a2;
    f32* temp_a2_2;
    f32* temp_a3_3;
    f32* temp_s0_2;
    f32* posZ;
    f32* temp_s3_2;
    f32* temp_s3_3;
    f32* temp_s4;
    f32* temp_v0_10;
    f32* temp_v1_4;
    f64 radius;
    f64 temp_f2_3;
    s32 temp_v0_5;
    s32 temp_v1_7;
    s8 temp_v1_2;
    u16 temp_v0_2;
    f32 phi_f12;
    f32 phi_a2;
    f32 phi_f20_2;
    s32 phi_s7;
    s32 phi_fp;

    npc->duration--;
    phi_s7 = 0;
    phi_fp = 0;
    phi_s7 = 0;

    if (enemy->varTable[9] >= (s32) (s16) npc->duration) {
        enemy->flags |= 0x1F100000;
    }

    if (npc->duration == 0) {
        if (clamp_angle(gPlayerStatusPtr->spriteFacingAngle) < 180.0f) {
            yaw2 = clamp_angle(gCurrentCameraID[&gCameras]->currentYaw - 90.0f);
        } else {
            yaw2 = clamp_angle(gCurrentCameraID[&gCameras]->currentYaw + 90.0f);
        }

        yaw = clamp_angle(yaw2 + 180.0f);
        if (enemy->varTable[7] == 0) {
            actionState = gPlayerStatusPtr->actionState;
            moveSpeed = 32.0f;

            if (actionState != 0) {
                moveSpeed = 100.0f;
                if (actionState == 1) {
                    moveSpeed = 90.0f;
                }
            }

            posX = &npc->pos.x;
        } else {
            actionState = gPlayerStatusPtr->actionState;
            moveSpeed = 38.0f;

            if (actionState != 0) {
                moveSpeed = 90.0f;
                if (actionState == 1) {
                    moveSpeed = 75.0f;
                }
            }

            posX = &npc->pos.x;
        }

        playerStatus = gPlayerStatusPtr;
        posZ = &npc->pos.z;
        npc->pos.x = playerStatus->position.x;
        npc->pos.z = playerStatus->position.z;
        add_vec2D_polar(posX, posZ, npc->collisionRadius, yaw);
        npc_move_heading(npc, moveSpeed + npc->collisionRadius, yaw2);

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

            radius = sqrtf(SQ(npc->pos.x) + SQ(npc->pos.z));
            if (radius < 305.0) {
                radius = 305.0f;
            }
            if (radius > 375.0) {
                radius = 375.0f;
            }

            theta = atan2(0.0f, 0.0f, npc->pos.x, npc->pos.z);
            npc->pos.x = 0.0f;
            npc->pos.z = 0.0f;
            add_vec2D_polar(posX, posZ, radius, theta);
            /*
            if (radius < 305.0) {
                phi_a2 = 305.0f;
                goto block_28;
            } else if (radius > 375.0) {
                phi_a2 = 375.0f;
block_28:
                theta = atan2(0.0f, 0.0f, npc->pos.x, npc->pos.z);
                npc->pos.x = 0.0f;
                npc->pos.z = 0.0f;
                add_vec2D_polar(posX, posZ, phi_a2, theta);
            }
            */
        } else {
            temp_a1 = &sp20;
            if ((npc->flags & 0x40) == 0) {
                temp_s4 = &sp20;
                temp_a1_2 = temp_s4;
                temp_s3_2 = &sp24;
                playerStatus = gPlayerStatusPtr;
                sp20 = playerStatus->position.x;
                sp28 = playerStatus->position.z;
                sp24 = (f32) ((f64) playerStatus->position.y + 18.0);
                temp_s0_2 = &sp28;
                if (npc_test_move_simple_with_slipping(npc->collisionChannel, temp_a1_2, temp_s3_2, temp_s0_2, moveSpeed, yaw2, (f32) npc->collisionHeight, (f32) npc->collisionRadius) != 0) {
                    playerStatus = gPlayerStatusPtr;
                    sp20 = playerStatus->position.x;
                    sp28 = playerStatus->position.z;
                    sp24 = (f32) ((f64) playerStatus->position.y + 45.0);
                    temp_v0_5 = npc_test_move_simple_with_slipping(npc->collisionChannel, temp_s4, temp_s3_2, temp_s0_2, moveSpeed, yaw2, (f32) npc->collisionHeight, (f32) npc->collisionRadius);
                    temp_a1_3 = &sp2C;
                    temp_a2 = &sp30;
                    temp_a3_3 = &sp34;
                    temp_v1_4 = &sp38;
                    sp2C = npc->pos.x;
                    sp38 = 200.0f;
                    sp34 = npc->pos.z;
                    sp30 = (f32) ((f64) npc->pos.y + 100.0);
                    if ((temp_v0_5 == 0) && (npc_raycast_down_sides(npc->collisionChannel, temp_a1_3, temp_a2, temp_a3_3, temp_v1_4) != 0) && (temp_f2_3 = (f64) sp38, (temp_f2_3 > 80.0)) && (temp_f2_3 < 120.0) && (npc->pos.y != sp30)) {
                        phi_fp = 1;
                    } else {
                        playerStatus = gPlayerStatusPtr;
                        sp20 = playerStatus->position.x;
                        sp28 = playerStatus->position.z;
                        sp24 = (f32) ((f64) playerStatus->position.y + 10.0);
                        npc_test_move_simple_with_slipping(npc->collisionChannel, &sp20, &sp24, &sp28, moveSpeed, yaw2, (f32) npc->collisionHeight, (f32) npc->collisionRadius);
                        playerStatus = gPlayerStatusPtr;
                        temp_f20 = dist2D(playerStatus->position.x, playerStatus->position.z, sp20, sp28);
                        playerStatus = gPlayerStatusPtr;
                        npc->pos.x = playerStatus->position.x;
                        npc->pos.z = playerStatus->position.z;
                        add_vec2D_polar(&npc->pos.x, &npc->pos.z, (f32) npc->collisionRadius, yaw);
                        phi_f20_2 = temp_f20 + (f32) npc->collisionRadius;
                        phi_s7 = 1;
                        npc_move_heading(npc, phi_f20_2, yaw2);
                    }
                }
            } else {
                playerStatus = gPlayerStatusPtr;
                sp20 = playerStatus->position.x;
                sp28 = playerStatus->position.z;
                sp24 = (f32) ((f64) playerStatus->position.y + 18.0);
                if (npc_test_move_simple_with_slipping(npc->collisionChannel, temp_a1, &sp24, &sp28, moveSpeed, yaw2, (f32) npc->collisionHeight, (f32) npc->collisionRadius) != 0) {
                    playerStatus = gPlayerStatusPtr;
                    temp_f20_2 = dist2D(playerStatus->position.x, playerStatus->position.z, sp20, sp28);
                    playerStatus = gPlayerStatusPtr;
                    npc->pos.x = playerStatus->position.x;
                    npc->pos.z = playerStatus->position.z;
                    add_vec2D_polar(posX, posZ, (f32) npc->collisionRadius, yaw);
                    phi_f20_2 = temp_f20_2 + (f32) npc->collisionRadius;
                    npc_move_heading(npc, phi_f20_2, yaw2);
                }
            }
        }
        temp_s0_3 = &npc->pos;
        temp_s3_3 = &npc->pos.z;
        if (is_point_within_region(territory->shape, (f32) territory->pointX, (f32) territory->pointZ, npc->pos.x, npc->pos.z, (f32) territory->sizeX, (f32) territory->sizeZ) != 0) {
            temp_v1_7 = territory->shape;
            switch (temp_v1_7) {                    /* irregular */
            case 0:
                temp_f0_2 = dist2D(npc->pos.x, npc->pos.z, (f32) territory->pointX, (f32) territory->pointZ);
                sp38 = temp_f0_2;
                if ((f32) territory->sizeX < temp_f0_2) {
                    temp_a3_4 = atan2((f32) territory->pointX, (f32) territory->pointZ, npc->pos.x, npc->pos.z);
                    npc->pos.x = (f32) territory->pointX;
                    npc->pos.z = (f32) territory->pointZ;
                    add_vec2D_polar(&temp_s0_3->x, temp_s3_3, (f32) territory->sizeX, temp_a3_4);
                }
                break;
            case 1:
                temp_f2_4 = (f32) (territory->pointX + territory->sizeX);
                if (temp_f2_4 < npc->pos.x) {
                    npc->pos.x = temp_f2_4;
                }
                temp_f2_5 = (f32) (territory->pointX - territory->sizeX);
                if (npc->pos.x < temp_f2_5) {
                    npc->pos.x = temp_f2_5;
                }
                temp_f2_6 = (f32) (territory->pointZ + territory->sizeZ);
                if (temp_f2_6 < npc->pos.z) {
                    npc->pos.z = temp_f2_6;
                }
                temp_f2_7 = (f32) (territory->pointZ - territory->sizeZ);
                if (npc->pos.z < temp_f2_7) {
                    npc->pos.z = temp_f2_7;
                }
                break;
            }
        }
        if ((phi_s7 == 0) && ((temp_a1_4 = &sp20, ((npc->flags & 8) == 0)) || (phi_fp != 0))) {
            temp_a2_2 = &sp24;
            temp_v0_10 = &sp38;
            sp20 = npc->pos.x;
            sp38 = 400.0f;
            sp28 = npc->pos.z;
            sp24 = (f32) ((f64) npc->pos.y + 150.0);
            if (npc_raycast_down_sides(npc->collisionChannel, temp_a1_4, temp_a2_2, &sp28, temp_v0_10) != 0) {
                npc->pos.y = sp24;
            }
        }
        playerStatus = gPlayerStatusPtr;
        npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
        ai_enemy_play_sound(npc, 0x321, 0);
        npc->currentAnim.w = enemy->animList[9];
        npc->duration = (s16) enemy->varTable[10];
        script->functionTemp[0] = 0xB;
    }
}

#include "world/common/UnkNpcDurationFlagFunc3.inc.c"

#include "world/common/UnkNpcAIFunc33.inc.c"

#include "world/common/UnkNpcDurationFlagFunc2.inc.c"

#include "world/common/UnkNpcAIFunc30.inc.c"

ApiStatus func_80241C54_B95094(Evt* script, s32 isInitialCall) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    EnemyTerritoryThing territory;
    EnemyTerritoryThing* territoryPtr = &territory;    
    NpcAISettings* settings = evt_get_variable(script, *script->ptrReadPos);

    territory.unk_00 = 0;
    territory.shape = enemy->territory->wander.detectShape;
    territory.pointX = enemy->territory->wander.detect.x;
    territory.pointZ = enemy->territory->wander.detect.z;
    territory.sizeX = enemy->territory->wander.detectSizeX;
    territory.sizeZ = enemy->territory->wander.detectSizeZ;
    territory.unk_18 = 200.0f;
    territory.unk_1C = 0;

    if (isInitialCall || enemy->unk_B0 & 4) {
        script->functionTemp[0] = 0;
        npc->duration = 0;
        npc->currentAnim.w = enemy->animList[0];
        enemy->varTable[0] = 0;

        if (enemy->unk_B0 & 4) {
            script->functionTemp[0] = 99;
            script->functionTemp[1] = 0;
            enemy->unk_B0 &= ~4;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            N(UnkNpcAIFunc31)(script, settings, territoryPtr);
            /* fallthrough */
        case 1:
            N(UnkNpcAIFunc32)(script, settings, territoryPtr);
            break;
        case 10:
            func_80240F38_B94378(script, settings, territoryPtr);
            if (script->functionTemp[0] != 11) {
                break;
            }
        case 11:
            N(UnkNpcDurationFlagFunc3)(script, settings, territoryPtr);
            if (script->functionTemp[0] != 12) {
                break;
            }
        case 12:
            N(UnkNpcAIFunc33)(script, settings, territoryPtr);
            if (script->functionTemp[0] != 13) {
                break;
            }
        case 13:
            N(UnkNpcDurationFlagFunc2)(script, settings, territoryPtr);
            if (script->functionTemp[0] != 14) {
                break;
            }
        case 14:
            N(UnkNpcAIFunc30)(script, settings, territoryPtr);
            break;
        case 99:
            func_8004A73C(script);
            break;
    }

    return ApiStatus_BLOCK;
}
