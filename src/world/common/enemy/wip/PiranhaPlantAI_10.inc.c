#include "common.h"
#include "npc.h"

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
        enemy->flags |= (ENEMY_FLAGS_100000 | ENEMY_FLAGS_IGNORE_TOUCH | ENEMY_FLAGS_IGNORE_JUMP |
                         ENEMY_FLAGS_IGNORE_HAMMER | ENEMY_FLAGS_8000000 | ENEMY_FLAGS_10000000);
    }

    if (npc->duration == 0) {
        if (clamp_angle(gPlayerStatusPtr->spriteFacingAngle) < 180.0f) {
            yaw2 = clamp_angle(gCameras[gCurrentCameraID].currentYaw - 90.0f);
        } else {
            yaw2 = clamp_angle(gCameras[gCurrentCameraID].currentYaw + 90.0f);
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

        npc->pos.x = gPlayerStatusPtr->position.x;
        npc->pos.z = gPlayerStatusPtr->position.z;
        add_vec2D_polar(&npc->pos.x, &npc->pos.z, npc->collisionRadius, yaw);
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
            if (!(npc->flags & NPC_FLAG_40)) {
                sp20 = gPlayerStatusPtr->position.x;
                sp24 = gPlayerStatusPtr->position.y + 18.0;
                sp28 = gPlayerStatusPtr->position.z;
                if (npc_test_move_simple_with_slipping(npc->collisionChannel, &sp20, &sp24, &sp28, moveSpeed, yaw2, npc->collisionHeight, npc->collisionRadius) != 0) {
                    sp20 = gPlayerStatusPtr->position.x;
                    sp24 = gPlayerStatusPtr->position.y + 45.0;
                    sp28 = gPlayerStatusPtr->position.z;
                    cond1 = npc_test_move_simple_with_slipping(npc->collisionChannel, &sp20, &sp24, &sp28, moveSpeed, yaw2, npc->collisionHeight, npc->collisionRadius);
                    sp2C = npc->pos.x;
                    sp30 = npc->pos.y + 100.0;
                    sp34 = npc->pos.z;
                    sp38 = 200.0f;
                    cond2 = npc_raycast_down_sides(npc->collisionChannel, &sp2C, &sp30, &sp34, &sp38);
                    if (!cond1 && cond2 && sp38 > 80.0 && sp38 < 120.0 && npc->pos.y != sp30) {
                        phi_fp = TRUE;
                    } else {
                        sp20 = gPlayerStatusPtr->position.x;
                        sp24 = gPlayerStatusPtr->position.y + 10.0;
                        sp28 = gPlayerStatusPtr->position.z;
                        npc_test_move_simple_with_slipping(npc->collisionChannel, &sp20, &sp24, &sp28, moveSpeed, yaw2, npc->collisionHeight, npc->collisionRadius);
                        posRadius = dist2D(gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z, sp20, sp28);
                        npc->pos.x = gPlayerStatusPtr->position.x;
                        npc->pos.z = gPlayerStatusPtr->position.z;
                        add_vec2D_polar(&npc->pos.x, &npc->pos.z, npc->collisionRadius, yaw);
                        npc_move_heading(npc, posRadius + npc->collisionRadius, yaw2);
                        phi_s7 = TRUE;
                    }
                }
            } else {
                sp20 = gPlayerStatusPtr->position.x;
                sp24 = gPlayerStatusPtr->position.y + 18.0;
                sp28 = gPlayerStatusPtr->position.z;
                if (npc_test_move_simple_with_slipping(npc->collisionChannel, &sp20, &sp24, &sp28, moveSpeed, yaw2, npc->collisionHeight, npc->collisionRadius) != 0) {
                    posRadius = dist2D(gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z, sp20, sp28);
                    npc->pos.x = gPlayerStatusPtr->position.x;
                    npc->pos.z = gPlayerStatusPtr->position.z;
                    add_vec2D_polar(&npc->pos.x, &npc->pos.z, npc->collisionRadius, yaw);
                    npc_move_heading(npc, posRadius + npc->collisionRadius, yaw2);
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

        if (!phi_s7 && (!(npc->flags & 8) || phi_fp)) {
            sp20 = npc->pos.x;
            sp38 = 400.0f;
            sp28 = npc->pos.z;
            sp24 = npc->pos.y + 150.0;

            if (npc_raycast_down_sides(npc->collisionChannel, &sp20, &sp24, &sp28, &sp38) != 0) {
                npc->pos.y = sp24;
            }
        }

        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        ai_enemy_play_sound(npc, SOUND_MOLE_SURFACE, 0);
        npc->currentAnim = enemy->animList[ENEMY_ANIM_MELEE_HIT];
        npc->duration = enemy->varTable[10];
        script->functionTemp[0] = 11;
    }
}

