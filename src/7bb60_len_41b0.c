#include "common.h"
#include "world/partners.h"

extern f32 D_8010C928;
extern f32 D_8010C984;

void func_800E315C(s32 colliderID);
s32 collision_check_player_intersecting_world(s32 mode, s32 arg1, f32 arg2);
s8 get_current_partner_id(void);

void record_jump_apex(void) {
    gPlayerStatus.jumpApexHeight = gPlayerStatus.position.y;
}

s32 can_trigger_loading_zone(void) {
    PlayerData* playerData = &gPlayerData;
    s32 actionState = gPlayerStatusPtr->actionState;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;

    if (actionState == ACTION_STATE_IDLE ||
        actionState == ACTION_STATE_WALK ||
        actionState == ACTION_STATE_RUN ||
        actionState == ACTION_STATE_USE_TWEESTER ||
        actionState == ACTION_STATE_SPIN
       ) {
        return TRUE;
    }

    if (actionState == ACTION_STATE_RIDE) {
        if (playerData->currentPartner == PARTNER_LAKILESTER || playerData->currentPartner == PARTNER_BOW) {
            if (partnerActionStatus->actionState.b[0] != 0) {
                return TRUE;
            } else {
                gPlayerStatusPtr->animFlags |= PLAYER_STATUS_ANIM_FLAGS_4;
                return FALSE;
            }
        } else {
            if (partnerActionStatus->actionState.b[3] == 6 || partnerActionStatus->actionState.b[3] == 7) {
                return partnerActionStatus->actionState.b[0] != 0;
            }
            if (partnerActionStatus->actionState.b[3] == 4) {
                gPlayerStatusPtr->animFlags |= PLAYER_STATUS_ANIM_FLAGS_4;
                return FALSE;
            }
        }
    }
    return FALSE;
}

void move_player(s32 duration, f32 heading, f32 speed) {
    gPlayerStatus.flags |= PLAYER_STATUS_FLAGS_4000;
    gPlayerStatus.heading = heading;
    gPlayerStatus.moveFrames = duration;
    gPlayerStatus.currentSpeed = speed;

    if (!(gPlayerStatus.animFlags & PLAYER_STATUS_ANIM_FLAGS_400000)) {
        set_action_state(speed > gPlayerStatus.walkSpeed ? ACTION_STATE_RUN : ACTION_STATE_WALK);
    }
}

INCLUDE_ASM(s32, "7bb60_len_41b0", collision_main_above);

INCLUDE_ASM(s32, "7bb60_len_41b0", func_800E29C8);

INCLUDE_ASM(s32, "7bb60_len_41b0", func_800E2BB0);

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_update_jump);


#ifdef NON_EQUIVALENT
// Rodata issue.
extern s32 GravityParamsStartJump;

void phys_init_integrator_for_current_state(void) {
    f32* temp_a0;
    s8 temp_v0;
    PlayerStatus* playerStatus = &gPlayerStatus;

    temp_v0 = playerStatus->actionState - 3;
    switch (temp_v0) {
    case 4:
        playerStatus->gravityIntegrator[0] = 10.0f;
        playerStatus->gravityIntegrator[1] = -5.0f;
        playerStatus->gravityIntegrator[2] = 1.5f;
        playerStatus->gravityIntegrator[3] = -0.3f;
        return;
    case 0:
    case 10:
    case 11:
    case 12:
    case 13:
    case 18:
    case 20:
            temp_a0 = &GravityParamsStartJump ;
        if ((playerStatus->flags & 0x40000) == 0) {
            playerStatus->gravityIntegrator[0] = *temp_a0++;
            playerStatus->gravityIntegrator[1] = *temp_a0++;
            playerStatus->gravityIntegrator[2] = *temp_a0++;
            playerStatus->gravityIntegrator[3] = *temp_a0++;
            return;
        }

        playerStatus->gravityIntegrator[0] = *temp_a0++ * 0.5f;
        playerStatus->gravityIntegrator[1] = *temp_a0++ * 0.5f;
        playerStatus->gravityIntegrator[2] = *temp_a0++ * 0.5f;
        playerStatus->gravityIntegrator[3] = *temp_a0++ * 0.5f;
    default:
        return;
    }
}
#else
INCLUDE_ASM(void, "7bb60_len_41b0", phys_init_integrator_for_current_state, void);
#endif // NON_EQUIVALENT

// This function is wack. This weird stuff is needed to match
void gravity_use_fall_parms(void) {
    f32* floats = GravityParamsStartFall;
    PlayerStatus* playerStatus;
    do {} while (0);
    playerStatus = &gPlayerStatus;

    if (playerStatus->flags & 0x40000) {
        playerStatus->gravityIntegrator[0] = *floats++ / 12.0f;
        playerStatus->gravityIntegrator[1] = *floats++ / 12.0f;
        playerStatus->gravityIntegrator[2] = *floats++ / 12.0f;
        playerStatus->gravityIntegrator[3] = *floats++ / 12.0f;
    } else {
        playerStatus->gravityIntegrator[0] = *floats++;
        playerStatus->gravityIntegrator[1] = *floats++;
        playerStatus->gravityIntegrator[2] = *floats++;
        playerStatus->gravityIntegrator[3] = *floats++;
    }
}

void phys_update_falling(void) {
    if (gPlayerStatus.actionState != ACTION_STATE_LANDING_ON_SWITCH &&
        gPlayerStatus.actionState != ACTION_STATE_BOUNCE)
    {
        s32 colliderID;

        gPlayerStatus.position.y = player_check_collision_below(func_800E34D8(), &colliderID);

        func_800E315C(colliderID);
    }
}

void func_800E315C(s32 colliderID) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;

    if (colliderID >= 0) {
        u8 colliderType = get_collider_type_by_id(colliderID);

        switch (colliderType) {
            case 1:
            case 4:
            case 5:
                set_action_state(ACTION_STATE_LAND);
                break;
            case 3:
                if ((partnerActionStatus->actionState.i & 0xFF0000FF) != 0x01000009) {
                    if (playerStatus->blinkTimer == 0) {
                        if (playerStatus->actionState != ACTION_STATE_HIT_LAVA) {
                            playerStatus->unk_BF = 1;
                            set_action_state(ACTION_STATE_HIT_LAVA);
                        }
                    } else {
                        set_action_state(ACTION_STATE_KNOCKBACK);
                    }
                }
                break;
            case 2:
                if ((partnerActionStatus->actionState.i & 0xFF0000FF) != 0x01000009) {
                    if (playerStatus->blinkTimer == 0) {
                        if (playerStatus->actionState != ACTION_STATE_HIT_FIRE) {
                            playerStatus->unk_BF = 2;
                            set_action_state(ACTION_STATE_HIT_LAVA);
                        }
                        break;
                    }
                    set_action_state(ACTION_STATE_KNOCKBACK);
                }
                break;
            default:
                phys_player_land();
                break;
        }
    }
}

static const f32 padding = 0.0f; // remove when the rest of the functions match

INCLUDE_ASM(void, "7bb60_len_41b0", phys_player_land, void);

f32 integrate_gravity(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_40000) {
        playerStatus->gravityIntegrator[2] += playerStatus->gravityIntegrator[3] / 1.7f;
        playerStatus->gravityIntegrator[1] += playerStatus->gravityIntegrator[2] / 1.7f;
        playerStatus->gravityIntegrator[0] += playerStatus->gravityIntegrator[1] / 1.7f;
    } else {
        playerStatus->gravityIntegrator[2] += playerStatus->gravityIntegrator[3];
        playerStatus->gravityIntegrator[1] += playerStatus->gravityIntegrator[2];
        playerStatus->gravityIntegrator[0] += playerStatus->gravityIntegrator[1];
    }
    return playerStatus->gravityIntegrator[0];
}

f32 func_800E34D8(void) {
    f32 ret = integrate_gravity();

    if (func_800E0208()) {
        ret = 0.0f;
    }
    return ret;
}

INCLUDE_ASM(f32, "7bb60_len_41b0", player_check_collision_below, f32 arg0, s32* colliderID);

void collision_main_lateral(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    f32 playerX, playerY, playerZ;
    f32 test1X, test1Y, test1Z;
    f32 test2X, test2Y, test2Z;
    f32 yaw;
    f32 yaw2;
    f32 speed;
    f32 sinTheta;
    f32 cosTheta;
    s32 result;
    s32 test1;
    s32 test2;
    f32 xBump;
    f32 zBump;

    gCollisionStatus.pushingAgainstWall = -1;
    if (playerStatus->flags & PLAYER_STATUS_FLAGS_4000) {
        speed = playerStatus->currentSpeed;
        if (playerStatus->flags & PLAYER_STATUS_FLAGS_40000) {
            speed *= 0.5f;
        }
        add_vec2D_polar(&playerStatus->position.x, &playerStatus->position.z, speed, playerStatus->heading);
        return;
    }

    switch (playerStatus->actionState) {
        case ACTION_STATE_STEP_UP:
            collision_check_player_intersecting_world(0, 0,
                playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].currentYaw);
            break;
        case ACTION_STATE_RIDE:
            if (get_current_partner_id() == PARTNER_BOW) {
                playerStatus->position.x += playerStatus->extraVelocity.x;
                playerStatus->position.y += playerStatus->extraVelocity.y;
                playerStatus->position.z += playerStatus->extraVelocity.z;

                if (playerStatus->extraVelocity.x != 0.0f ||
                    playerStatus->extraVelocity.y != 0.0f ||
                    playerStatus->extraVelocity.z != 0.0f)
                {
                    gCameras->targetPos.x = playerStatus->position.x;
                    gCameras->targetPos.y = playerStatus->position.y;
                    gCameras->targetPos.z = playerStatus->position.z;
                    if (playerStatus->alpha1 != 128) {
                        collision_check_player_intersecting_world(0, 0,
                            atan2(0.0f, 0.0f, playerStatus->extraVelocity.x, playerStatus->extraVelocity.z));
                    }
                }
            }
            break;
        case ACTION_STATE_GROUND_POUND:
        case ACTION_STATE_ULTRA_POUND:
            playerStatus->position.x += playerStatus->extraVelocity.x;
            playerStatus->position.y += playerStatus->extraVelocity.y;
            playerStatus->position.z += playerStatus->extraVelocity.z;
            if (playerStatus->extraVelocity.x != 0.0f ||
                playerStatus->extraVelocity.y != 0.0f ||
                playerStatus->extraVelocity.z != 0.0f)
            {
                gCameras->targetPos.x = playerStatus->position.x;
                gCameras->targetPos.y = playerStatus->position.y;
                gCameras->targetPos.z = playerStatus->position.z;
            }
            if (playerStatus->extraVelocity.x != 0.0f ||
                playerStatus->extraVelocity.y != 0.0f ||
                playerStatus->extraVelocity.z != 0.0f)
            {
                collision_check_player_intersecting_world(0, 0,
                    playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].currentYaw);
            }
            break;
        case ACTION_STATE_HAMMER:
            playerStatus->position.x += playerStatus->extraVelocity.x;
            playerStatus->position.y += playerStatus->extraVelocity.y;
            playerStatus->position.z += playerStatus->extraVelocity.z;
            if (playerStatus->extraVelocity.x != 0.0f ||
                playerStatus->extraVelocity.y != 0.0f ||
                playerStatus->extraVelocity.z != 0.0f)
            {
                gCameras->targetPos.x = playerStatus->position.x;
                gCameras->targetPos.y = playerStatus->position.y;
                gCameras->targetPos.z = playerStatus->position.z;
            }

            playerX = playerStatus->position.x;
            playerY = playerStatus->position.y;
            playerZ = playerStatus->position.z;
            if (playerStatus->currentSpeed != 0.0f) {
                yaw = playerStatus->targetYaw;
            } else {
                yaw = playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].currentYaw;
            }
            collisionStatus->currentWall =
                player_test_move_with_slipping(playerStatus, &playerX, &playerY, &playerZ,
                                               playerStatus->colliderDiameter * 0.5f, yaw);

            if (playerStatus->extraVelocity.x != 0.0f ||
                playerStatus->extraVelocity.y != 0.0f ||
                playerStatus->extraVelocity.z != 0.0f)
            {
                collision_check_player_intersecting_world(0, 0,
                    playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].currentYaw);
            }
            break;
        default:
            if (!(playerStatus->flags & PLAYER_STATUS_FLAGS_FLYING)) {
                f32 new_var;

                speed = 0.0f;
                if (!(playerStatus->flags & (PLAYER_STATUS_FLAGS_800000 | PLAYER_STATUS_FLAGS_INPUT_DISABLED))) {
                    player_input_to_move_vector(&yaw, &speed);
                    if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_SPINNING)) {
                        speed *= 0.03125f;
                        if (!(playerStatus->flags & (PLAYER_STATUS_FLAGS_FALLING | PLAYER_STATUS_FLAGS_JUMPING))) {
                            speed *= 0.25;
                        }
                        if (playerStatus->actionState == ACTION_STATE_LAUNCH) {
                            speed *= 1.5;
                        }
                        if (playerStatus->flags & PLAYER_STATUS_FLAGS_40000) {
                            speed *= 0.5f;
                        }
                    }
                    sin_cos_rad(yaw * TAU / 360.0f, &sinTheta, &cosTheta);

                    if (playerStatus->actionState == ACTION_STATE_14) {
                        if (fabsf(sinTheta) > fabsf(cosTheta)) {
                            xBump = speed * sinTheta;
                            zBump = 0.0f;
                        } else {
                            xBump = 0.0f;
                            zBump = -speed * cosTheta;
                        }
                    } else if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_SPINNING)) {
                        xBump = speed * sinTheta;
                        zBump = -speed * cosTheta;
                    } else {
                        xBump = 0.0f;
                        zBump = 0.0f;
                    }

                    sin_cos_rad(playerStatus->targetYaw * TAU / 360.0f, &sinTheta, &cosTheta);
                    speed = playerStatus->currentSpeed;
                    if (playerStatus->flags & PLAYER_STATUS_FLAGS_40000) {
                        speed *= 0.5f;
                    }
                    playerX = xBump + (speed * sinTheta);
                    playerZ = zBump - (speed * cosTheta);
                    yaw = atan2(0.0f, 0.0f, playerX, playerZ);
                    speed = sqrtf(SQ(playerX) + SQ(playerZ));
                    if (playerStatus->flags & (PLAYER_STATUS_FLAGS_FALLING | PLAYER_STATUS_FLAGS_JUMPING)) {
                        if (speed > playerStatus->runSpeed) {
                            speed = playerStatus->runSpeed;
                        }
                    }
                }

                playerStatus->position.x += playerStatus->extraVelocity.x;
                playerStatus->position.z += playerStatus->extraVelocity.z;
                if (playerStatus->decorationList == 0) {
                    playerStatus->position.y += playerStatus->extraVelocity.y;
                }

                if (
                    playerStatus->extraVelocity.x != 0.0f ||
                    playerStatus->extraVelocity.y != 0.0f ||
                    playerStatus->extraVelocity.z != 0.0f)
                {
                    gCameras->targetPos.x = playerStatus->position.x;
                    gCameras->targetPos.y = playerStatus->position.y;
                    gCameras->targetPos.z = playerStatus->position.z;
                }

                playerX = playerStatus->position.x;
                playerY = playerStatus->position.y;
                playerZ = playerStatus->position.z;
                result = player_test_move_with_slipping(playerStatus, &playerX, &playerY, &playerZ,
                                                        playerStatus->colliderDiameter * 0.5f, playerStatus->targetYaw);
                if (speed == 0.0f && result < 0) {
                    yaw2 = playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].currentYaw;
                    sin_cos_rad((yaw2 + 180.0f) * TAU / 360.0f, &sinTheta, &cosTheta);
                    playerX = playerStatus->position.x + (sinTheta * playerStatus->colliderDiameter * 0.5f);
                    playerY = playerStatus->position.y;
                    playerZ = playerStatus->position.z - (cosTheta * playerStatus->colliderDiameter * 0.5f);
                    result = player_test_move_with_slipping(playerStatus, &playerX, &playerY, &playerZ,
                                                            playerStatus->colliderDiameter, yaw2);
                }
                collisionStatus->currentWall = result;
                if (!(playerStatus->flags & 0x400000) && playerStatus->actionState != ACTION_STATE_HAMMER) {

                    if (speed == 0.0f) {
                        collision_check_player_intersecting_world(0, 0,
                            playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].currentYaw);
                        break;
                    }

                    playerX = playerStatus->position.x;
                    playerZ = playerStatus->position.z;
                    playerY = playerStatus->position.y;
                    yaw2 = yaw;

                    if (speed > 4.0f) {
                        result = player_test_move_with_slipping(playerStatus, &playerX, &playerY, &playerZ, 4.0f, yaw2);
                        if (result < 0) {
                            result = player_test_move_with_slipping(playerStatus, &playerX, &playerY, &playerZ, speed - 4.0f, yaw2);
                        }
                        collisionStatus->pushingAgainstWall = result;
                    } else {
                        collisionStatus->pushingAgainstWall =
                            player_test_move_with_slipping(playerStatus, &playerX, &playerY, &playerZ, speed, yaw2);
                    }

                    test1X = playerX;
                    test1Y = playerY;
                    test1Z = playerZ;
                    yaw = clamp_angle(yaw2 - 35.0);
                    test1 = player_test_lateral_overlap(0, playerStatus, &test1X, &test1Y, &test1Z, 0.0f, yaw);
                    test2X = playerX;
                    test2Z = playerY;
                    test2Y = playerZ;
                    yaw = clamp_angle(yaw2 + 35.0);
                    test2 = player_test_lateral_overlap(0, playerStatus, &test2X, &test2Z, &test2Y, 0.0f, yaw);

                    if (test1 < 0) {
                        if (test2 < 0) {
                            playerStatus->position.x = playerX;
                            playerStatus->position.z = playerZ;
                        } else {
                            playerStatus->position.x = test1X;
                            playerStatus->position.z = test1Z;
                        }
                    } else if (test2 < 0) {
                        playerStatus->position.x = test2X;
                        playerStatus->position.z = test2Y;
                    }

                    if (playerStatus->enableCollisionOverlapsCheck == 0) {
                        if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_SPINNING) {
                            yaw2 = playerStatus->targetYaw;
                        } else {
                            yaw2 = playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].currentYaw;
                        }
                        if (collision_check_player_intersecting_world(0, 0, yaw2) < 0) {
                            collision_check_player_intersecting_world(1, playerStatus->colliderHeight * 0.75f, yaw2);
                        }
                    }
                }
            }
            break;
        case ACTION_STATE_LANDING_ON_SWITCH:
        case ACTION_STATE_LAND:
        case ACTION_STATE_STEP_DOWN_LAND:
        case ACTION_STATE_ULTRA_JUMP:
        case ACTION_STATE_SLIDING:
        case ACTION_STATE_HIT_FIRE:
        case ACTION_STATE_HIT_LAVA:
        case ACTION_STATE_USE_SNEAKY_PARASOL:
        case ACTION_STATE_USE_SPRING:
            break;
    }
}

//something weird with hitID
#ifdef NON_EQUIVALENT
s32 collision_check_player_intersecting_world(s32 mode, s32 arg1, f32 arg2) {
    f32 angle = 0.0f;
    s32 ret = -1;
    s32 i;

    for (i = 0; i < 4; i++) {
        f32 x = gPlayerStatusPtr->position.x;
        f32 y = gPlayerStatusPtr->position.y + arg1;
        f32 z = gPlayerStatusPtr->position.z;
        s32 hitID = player_test_lateral_overlap(mode, gPlayerStatusPtr, &x, &y, &z, 0, angle);

        if (hitID >= 0) {
            ret = hitID;
        }

        gPlayerStatusPtr->position.x = x;
        gPlayerStatusPtr->position.z = z;
        angle += 90.0f;
    }

    return ret;
}
#else
INCLUDE_ASM(s32, "7bb60_len_41b0", collision_check_player_intersecting_world, s32 mode, s32 arg1, f32 arg2);
#endif

s32 func_800E4404(s32 mode, s32 arg1, f32 arg2, f32* outX, f32* outY, f32* outZ) {
    f32 angle = 0.0f;
    s32 ret = -1;
    s32 i;

    for (i = 0; i < 4; i++) {
        f32 x = *outX;
        f32 y = *outY + arg1;
        f32 z = *outZ;
        s32 hitID = player_test_lateral_overlap(mode, gPlayerStatusPtr, &x, &y, &z, 0, angle);

        if (hitID >= 0) {
            ret = hitID;
        }

        *outX = x;
        *outZ = z;
        angle += 90.0f;
    }

    return ret;
}

void collision_check_player_overlaps(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 overlapPush = playerStatus->overlapPushAmount;

    if (overlapPush != 0.0f) {
        f32 x = playerStatus->position.x;
        f32 y = playerStatus->position.y;
        f32 z = playerStatus->position.z;

        player_test_lateral_overlap(0, &gPlayerStatus, &x, &y, &z, overlapPush, playerStatus->overlapPushYaw);

        overlapPush -= playerStatus->runSpeed / 10.0f;
        playerStatus->position.x = x;
        playerStatus->position.y = y;
        playerStatus->position.z = z;

        if (overlapPush < 0.0f) {
            overlapPush = 0.0f;
        }

        playerStatus->overlapPushAmount = overlapPush;
    }
}

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_should_player_be_sliding);

s32 phys_is_on_sloped_ground(void) {
    Shadow* playerShadow = get_shadow_by_index(gPlayerStatus.shadowID);
    f32 rotZ = playerShadow->rotation.z + 180.0;
    f32 rotX = playerShadow->rotation.x + 180.0;
    s32 ret = TRUE;

    if (fabsf(rotZ) < 20.0f && fabsf(rotX) < 20.0f) {
        ret = FALSE;
    }

    return ret;
}

void phys_main_collision_below(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    f32 collHeightHalf = playerStatus->colliderHeight * 0.5f;
    f32 playerX = playerStatus->position.x;
    f32 playerY = playerStatus->position.y + collHeightHalf;
    f32 playerZ = playerStatus->position.z;
    f32 outLength = playerStatus->colliderHeight;
    f32 temp_f24 = (2.0f * playerStatus->colliderHeight) / 7.0f;
    f32 hitRx, hitRz;
    f32 hitDirX, hitDirZ;
    s32 result;
    s32 cond;

    result = player_raycast_below_cam_relative(playerStatus, &playerX, &playerY, &playerZ, &outLength, &hitRx, &hitRz,
                                               &hitDirX, &hitDirZ);
    playerStatus->groundNormalPitch = get_player_normal_pitch();

    if (collHeightHalf + (temp_f24 * 0.5f) < outLength) {
        result = -1;
    }
    if (playerStatus->decorationList == 0) {
        collisionStatus->currentFloor = result;
    }
    if (result >= 0) {
        playerStatus->groundAnglesXZ.x = hitDirX;
        playerStatus->groundAnglesXZ.y = hitDirZ;
    }

    if (func_800E0208()) {
        return;
    }

    if (playerStatus->flags & (PLAYER_STATUS_FLAGS_FLYING | PLAYER_STATUS_FLAGS_FALLING | PLAYER_STATUS_FLAGS_JUMPING)) {
        return;
    }

    if (playerStatus->actionState == ACTION_STATE_SLIDING) {
        return;
    }

    if ((!(playerStatus->flags & PLAYER_STATUS_FLAGS_10) ||
        (phys_adjust_cam_on_landing(), !phys_should_player_be_sliding()) ||
        (set_action_state(ACTION_STATE_SLIDING), (playerStatus->actionState != ACTION_STATE_SLIDING))))
    {
        if (result >= 0) {
            switch (get_collider_type_by_id(result) & 0xFF) {
                case 2:
                    if (partnerActionStatus->actionState.b[0] == 0 || partnerActionStatus->actionState.b[3] != 9) {
                        if (playerStatus->blinkTimer == 0) {
                            if (playerStatus->actionState != ACTION_STATE_HIT_LAVA) {
                                playerStatus->unk_BF = 2;
                                set_action_state(ACTION_STATE_HIT_LAVA);
                            }
                        } else {
                            set_action_state(ACTION_STATE_KNOCKBACK);
                        }
                    }
                    break;
                case 3:
                    if (partnerActionStatus->actionState.b[0] == 0 || partnerActionStatus->actionState.b[3] != 9) {
                        if (playerStatus->blinkTimer == 0) {
                            if (playerStatus->actionState != ACTION_STATE_HIT_LAVA) {
                                playerStatus->unk_BF = 1;
                                set_action_state(ACTION_STATE_HIT_LAVA);
                            }
                        } else {
                            set_action_state(ACTION_STATE_KNOCKBACK);
                        }
                    }
                    break;
                default:
                    cond = FALSE;
                    if (collisionStatus->currentFloor & 0x4000) {
                        cond = get_entity_type(collisionStatus->currentFloor) == ENTITY_TYPE_HIDDEN_PANEL;
                    }

                    if (playerStatus->actionState != ACTION_STATE_STEP_UP && !cond) {
                        if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS)) {
                            if (playerY - playerStatus->position.y < 6.0f) {
                                playerStatus->position.y = playerY;
                            } else {
                                set_action_state(ACTION_STATE_STEP_UP);
                                D_8010C928 = playerY;
                                D_8010C984 = playerStatus->targetYaw;
                            }
                        } else {
                            playerStatus->position.y = playerY;
                        }
                        phys_save_ground_pos();
                    }
                    break;
            }
        } else if (!(playerStatus->flags & PLAYER_STATUS_FLAGS_FLYING) &&
                    playerStatus->actionState != ACTION_STATE_USE_SPINNING_FLOWER)
        {
            if (outLength <= collHeightHalf + temp_f24 && hitDirX == 0.0f && hitDirZ == 0.0f) {
                set_action_state(ACTION_STATE_STEP_DOWN);
            } else {
                set_action_state(ACTION_STATE_FALLING);
            }
            gravity_use_fall_parms();
        }
    }
}

void func_800E4AD8(s32 mode) {
    Camera* currentCamera = &gCameras[gCurrentCameraID];

    collision_check_player_intersecting_world(mode, 0, gPlayerStatus.spriteFacingAngle - 90.0f + currentCamera->currentYaw);
}

void func_800E4B40(s32 mode, f32* arg1, f32* arg2, f32* arg3) {
    Camera* currentCamera = &gCameras[gCurrentCameraID];

    func_800E4404(mode, 0, gPlayerStatus.spriteFacingAngle - 90.0f + currentCamera->currentYaw, arg1, arg2, arg3);
}

INCLUDE_ASM(s32, "7bb60_len_41b0", collision_lava_reset_check_additional_overlaps);

void func_800E4F10(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 tempB = 0;
    f32 yaw = playerStatus->targetYaw;
    f32 x = playerStatus->position.x;
    f32 y = playerStatus->position.y;
    f32 z = playerStatus->position.z;
    s32 temp = player_test_move_without_slipping(&gPlayerStatus, &x, &y, &z, 0, yaw, &tempB);

    playerStatus->position.x = x;
    playerStatus->position.z = z;

    if (tempB != 0 &&
        temp < 0 &&
        playerStatus->actionState != ACTION_STATE_STEP_UP_PEACH &&
        playerStatus->currentSpeed != 0.0f)
    {
        set_action_state(ACTION_STATE_STEP_UP_PEACH);
    }
}

void check_input_midair_jump(void) {
    if (!(gPlayerStatus.flags & (PLAYER_STATUS_FLAGS_800000 | PLAYER_STATUS_FLAGS_10 | PLAYER_STATUS_FLAGS_FLYING)) &&
        !(gPlayerStatus.animFlags & 0x4001) &&
        gPlayerStatus.unk_C2 >= 6 &&
        gPlayerStatus.decorationList < 0x12 &&
        gPlayerStatus.pressedButtons & A_BUTTON) {

        switch (gPlayerData.bootsLevel) {
            case 0:
                break;
            case 1:
                set_action_state(ACTION_STATE_SPIN_JUMP);
                gPlayerStatus.flags |= 8;
                break;
            case 2:
                set_action_state(ACTION_STATE_ULTRA_JUMP);
                gPlayerStatus.flags |= 8;
                break;
        }
    }
}

s8 get_current_partner_id(void) {
    return gPlayerData.currentPartner;
}

void try_player_footstep_sounds(s32 arg0) {
    if (gGameStatusPtr->frameCounter % arg0 == 0) {
        u8 colliderType = get_collider_type_by_id(gCollisionStatus.currentFloor);
        s32 soundID;
        s32 soundID2;

        if (colliderType == 6 || colliderType == 9) {
            soundID = SOUND_143;
            soundID2 = SOUND_144;
        } else {
            soundID = SOUND_STEP1;
            soundID2 = SOUND_STEP2;
        }

        if (D_800F7B80 == 0) {
            soundID = soundID2;
        }

        sfx_play_sound_at_player(soundID, 0);
        D_800F7B80 ^= 1;
    }
}

void phys_update_interact_collider(void) {
    gCollisionStatus.unk_0A = phys_check_interactable_collision();
}

INCLUDE_ASM(s32, "7bb60_len_41b0", phys_check_interactable_collision);

s32 phys_can_player_interact(void) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 ret = TRUE;

    if (gPartnerActionStatus.actionState.b[0] != 0) {
        if (gPartnerActionStatus.actionState.b[3] == 3) {
            if (gPartnerActionStatus.actionState.b[0] < 3) {
                ret = FALSE;
            }
        } else {
            ret = FALSE;
        }
    } else if (!(gPlayerStatus.actionState == ACTION_STATE_IDLE ||
                 gPlayerStatus.actionState == ACTION_STATE_WALK ||
                 gPlayerStatus.actionState == ACTION_STATE_RUN)) {
        ret = FALSE;
    }
    return ret;
}

INCLUDE_ASM(f32, "7bb60_len_41b0", func_800E5348, void);

void player_get_camera_facing_angle(void) {
    f32 angle = 0.0f;

    if (gPlayerStatus.spriteFacingAngle >= 90.0f && gPlayerStatus.spriteFacingAngle < 270.0f) {
        angle = 180.0f;
    }

    angle = angle + gCameras[CAM_DEFAULT].currentYaw + 90.0f;

    clamp_angle(angle);
}

void phys_save_ground_pos(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->lastGoodPosition.x = playerStatus->position.x;
    playerStatus->lastGoodPosition.y = playerStatus->position.y;
    playerStatus->lastGoodPosition.z = playerStatus->position.z;
}
