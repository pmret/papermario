#include "common.h"
#include "world/partners.h"

extern f32 GravityParamsStartJump[];
extern f32 D_8010C928;
extern f32 JumpedOnSwitchX;
extern f32 JumpedOnSwitchZ;
extern f32 D_8010C984;

void func_800E315C(s32 colliderID);
s32 collision_check_player_intersecting_world(s32 mode, s32 arg1, f32 arg2);
s32 phys_check_interactable_collision(void);
void phys_save_ground_pos(void);

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
            if (partnerActionStatus->partnerActionState != PARTNER_ACTION_NONE) {
                return TRUE;
            } else {
                gPlayerStatusPtr->animFlags |= PA_FLAGS_4;
                return FALSE;
            }
        } else {
            if (partnerActionStatus->actingPartner == PARTNER_WATT || partnerActionStatus->actingPartner == PARTNER_SUSHIE) {
                return partnerActionStatus->partnerActionState != PARTNER_ACTION_NONE;
            }
            if (partnerActionStatus->actingPartner == PARTNER_PARAKARRY) {
                gPlayerStatusPtr->animFlags |= PA_FLAGS_4;
                return FALSE;
            }
        }
    }
    return FALSE;
}

void move_player(s32 duration, f32 heading, f32 speed) {
    gPlayerStatus.flags |= PS_FLAGS_4000;
    gPlayerStatus.heading = heading;
    gPlayerStatus.moveFrames = duration;
    gPlayerStatus.currentSpeed = speed;

    if (!(gPlayerStatus.animFlags & PA_FLAGS_400000)) {
        set_action_state(speed > gPlayerStatus.walkSpeed ? ACTION_STATE_RUN : ACTION_STATE_WALK);
    }
}

s32 collision_main_above(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    f32 x, y, z;
    f32 new_var;
    f32 moveAngle;
    f32 moveMagnitude;
    f32 sp2C;
    s32 hitResult;
    f32 phi_f2;

    new_var = sp2C = playerStatus->colliderHeight * 0.5f;
    x = playerStatus->position.x;
    y = playerStatus->position.y + new_var;
    z = playerStatus->position.z;

    player_input_to_move_vector(&moveAngle, &moveMagnitude);

    if (moveMagnitude != 0.0f) {
        phi_f2 = playerStatus->targetYaw;
    } else {
        phi_f2 = playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].currentYaw;
    }

    moveAngle = phi_f2;
    hitResult = player_raycast_up_corners(playerStatus, &x, &y, &z, &sp2C, moveAngle);
    collisionStatus->currentCeiling = hitResult;

    if (hitResult >= 0) {
        if (playerStatus->actionState != ACTION_STATE_FALLING &&
            playerStatus->actionState != ACTION_STATE_STEP_DOWN &&
            collisionStatus->currentFloor < 0)
        {
            if (sp2C <= fabsf(new_var + playerStatus->gravityIntegrator[0])) {
                do {
                    if ((hitResult & COLLISION_WITH_ENTITY_BIT) && get_entity_type(hitResult) == ENTITY_TYPE_BRICK_BLOCK) {
                        return hitResult;
                    }
                } while (0);

                playerStatus->position.y = y - ((playerStatus->colliderHeight / 5.0f) * 3.0f);
                if (playerStatus->actionState != ACTION_STATE_TORNADO_JUMP &&
                    playerStatus->actionState != ACTION_STATE_SPIN_JUMP)
                    {
                    playerStatus->gravityIntegrator[0] = 0.0f;
                    playerStatus->gravityIntegrator[1] = 0.0f;
                    playerStatus->gravityIntegrator[2] = 0.0f;
                    playerStatus->gravityIntegrator[3] = 0.0f;
                }
            }
        }
    }

    return hitResult;
}

void func_800E29C8(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 colliderID;
    f32 groundPosY;
    AnimID anim;

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->actionSubstate = LANDING_ON_SWITCH_SUBSTATE_0;
    }

    if (playerStatus->actionSubstate == LANDING_ON_SWITCH_SUBSTATE_0) {
        if (dist2D(JumpedOnSwitchX, JumpedOnSwitchZ, playerStatus->position.x, playerStatus->position.z) <= 22.0f) {
            add_vec2D_polar(&playerStatus->position.x, &playerStatus->position.z, 5.0f, playerStatus->targetYaw);
        }
        integrate_gravity();
        if (playerStatus->gravityIntegrator[0] <= 0.0f) {
            record_jump_apex();
            gravity_use_fall_parms();
            integrate_gravity();
            playerStatus->actionSubstate = LANDING_ON_SWITCH_SUBSTATE_1;
        }
        if (playerStatus->gravityIntegrator[0] > playerStatus->maxJumpSpeed) {
            playerStatus->gravityIntegrator[0] = playerStatus->maxJumpSpeed;
        }
        playerStatus->position.y += playerStatus->gravityIntegrator[0];
    } else if (playerStatus->actionSubstate == LANDING_ON_SWITCH_SUBSTATE_2) {
        if (dist2D(JumpedOnSwitchX, JumpedOnSwitchZ, playerStatus->position.x, playerStatus->position.z) <= 22.0f) {
            add_vec2D_polar(&playerStatus->position.x, &playerStatus->position.z, 5.0f, playerStatus->targetYaw);
        }
        groundPosY = player_check_collision_below(func_800E34D8(), &colliderID);
        func_800E315C(colliderID);
        playerStatus->position.y = groundPosY;
        if (colliderID >= 0) {
            if (!(playerStatus->animFlags & PA_FLAGS_HOLDING_WATT)) {
                anim = ANIM_Mario_10009;
            } else {
                anim = ANIM_Mario_6000B;
            }
            suggest_player_anim_clearUnkFlag(anim);
            enable_player_input();
            phys_player_land();
        }
    }
}

void func_800E2BB0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 cond = FALSE;

    if (playerStatus->position.y < playerStatus->gravityIntegrator[3] + playerStatus->gravityIntegrator[2]) {
        f32 phi_f6 = (playerStatus->gravityIntegrator[3] - playerStatus->position.y) / 777.0f;

        if (phi_f6 < -0.47) {
            phi_f6 = -0.47f;
        }
        if (phi_f6 > 0.001) {
            phi_f6 = 0.001f;
        }
        playerStatus->gravityIntegrator[0] += phi_f6;
        playerStatus->position.y += playerStatus->gravityIntegrator[0];
        if (playerStatus->gravityIntegrator[0] <= 0.0f) {
            cond = TRUE;
        }
    } else {
        playerStatus->gravityIntegrator[0] += -1.2;
        if (playerStatus->gravityIntegrator[0] <= 0.0f) {
            cond = TRUE;
        }
        playerStatus->position.y += playerStatus->gravityIntegrator[0];
    }

    if (cond) {
        record_jump_apex();
        LOAD_INTEGRATOR_FALL(playerStatus->gravityIntegrator);
        set_action_state(ACTION_STATE_FALLING);
    }
}

void phys_update_jump(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->timeInAir != 0) {
        switch (playerStatus->actionState) {
            case ACTION_STATE_LAUNCH:
                func_800E2BB0();
                return;
            case ACTION_STATE_LANDING_ON_SWITCH:
                func_800E29C8();
                return;
            case ACTION_STATE_BOUNCE:
                integrate_gravity();
                playerStatus->position.y += playerStatus->gravityIntegrator[0];
                if (playerStatus->gravityIntegrator[0] <= 0.0f) {
                    record_jump_apex();
                    if (is_starting_conversation()) {
                        playerStatus->gravityIntegrator[0] = 0.154343f;
                        playerStatus->gravityIntegrator[1] = -0.35008f;
                        playerStatus->gravityIntegrator[2] = 0.0f;
                        playerStatus->gravityIntegrator[3] = 0.0f;
                    } else {
                        gravity_use_fall_parms();
                    }
                    integrate_gravity();
                    set_action_state(ACTION_STATE_FALLING);
                }
                return;
            case ACTION_STATE_HOP:
                playerStatus->gravityIntegrator[0] -= 4.5;
                playerStatus->position.y += playerStatus->gravityIntegrator[0];
                if (playerStatus->gravityIntegrator[0] <= 0.0f) {
                    record_jump_apex();
                    gravity_use_fall_parms();
                    integrate_gravity();
                    set_action_state(ACTION_STATE_FALLING);
                }
                return;
            case ACTION_STATE_HIT_FIRE:
            case ACTION_STATE_HIT_LAVA:
                return;
            default:
                if (!(playerStatus->currentButtons & BUTTON_A)) {
                    record_jump_apex();
                    set_action_state(ACTION_STATE_HOP);
                    integrate_gravity();
                    if (playerStatus->flags & PS_FLAGS_40000) {
                        playerStatus->gravityIntegrator[1] *= 0.5f;
                        playerStatus->gravityIntegrator[2] *= 0.5f;
                        playerStatus->gravityIntegrator[3] *= 0.5f;
                    }
                }
                break;
        }
    }

    integrate_gravity();
    if (playerStatus->gravityIntegrator[0] <= 0.0f) {
        record_jump_apex();
        gravity_use_fall_parms();
        integrate_gravity();
        set_action_state(ACTION_STATE_FALLING);
    }

    if (playerStatus->gravityIntegrator[0] > playerStatus->maxJumpSpeed) {
        playerStatus->gravityIntegrator[0] = playerStatus->maxJumpSpeed;
    }
    playerStatus->position.y += playerStatus->gravityIntegrator[0];
}

void phys_init_integrator_for_current_state(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32* params;

    switch (playerStatus->actionState) {
        case ACTION_STATE_LANDING_ON_SWITCH:
            playerStatus->gravityIntegrator[0] = 10.0f;
            playerStatus->gravityIntegrator[1] = -5.0f;
            playerStatus->gravityIntegrator[2] = 1.5f;
            playerStatus->gravityIntegrator[3] = -0.3f;
            break;
        case ACTION_STATE_JUMP:
        case ACTION_STATE_SPIN_JUMP:
        case ACTION_STATE_SPIN_POUND:
        case ACTION_STATE_TORNADO_JUMP:
        case ACTION_STATE_TORNADO_POUND:
        case ACTION_STATE_HIT_FIRE:
        case ACTION_STATE_HIT_LAVA:
            params = GravityParamsStartJump;
            if (!(playerStatus->flags & PS_FLAGS_40000)) {
                playerStatus->gravityIntegrator[0] = *params++;
                playerStatus->gravityIntegrator[1] = *params++;
                playerStatus->gravityIntegrator[2] = *params++;
                playerStatus->gravityIntegrator[3] = *params++;
            } else {
                playerStatus->gravityIntegrator[0] = *params++ * 0.5f;
                playerStatus->gravityIntegrator[1] = *params++ * 0.5f;
                playerStatus->gravityIntegrator[2] = *params++ * 0.5f;
                playerStatus->gravityIntegrator[3] = *params++ * 0.5f;
            }
            break;
    }
}

static const f32 padding = 0.0f;

// This function is wack. This weird stuff is needed to match
void gravity_use_fall_parms(void) {
    f32* params = GravityParamsStartFall;
    PlayerStatus* playerStatus;
    do {} while (0);
    playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PS_FLAGS_40000) {
        playerStatus->gravityIntegrator[0] = *params++ / 12.0f;
        playerStatus->gravityIntegrator[1] = *params++ / 12.0f;
        playerStatus->gravityIntegrator[2] = *params++ / 12.0f;
        playerStatus->gravityIntegrator[3] = *params++ / 12.0f;
    } else {
        playerStatus->gravityIntegrator[0] = *params++;
        playerStatus->gravityIntegrator[1] = *params++;
        playerStatus->gravityIntegrator[2] = *params++;
        playerStatus->gravityIntegrator[3] = *params++;
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
        s32 surfaceType = get_collider_flags(colliderID) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
        switch (surfaceType) {
            case SURFACE_TYPE_WATER:
            case SURFACE_TYPE_DOCK_WALL:
            case SURFACE_TYPE_SLIDE:
                set_action_state(ACTION_STATE_LAND);
                break;
            case SURFACE_TYPE_LAVA:
                if ((*(s32*)(&partnerActionStatus->partnerActionState) & 0xFF0000FF) != 0x01000009) {
                    if (playerStatus->blinkTimer == 0) {
                        if (playerStatus->actionState != ACTION_STATE_HIT_LAVA) {
                            playerStatus->hazardType = HAZARD_TYPE_LAVA;
                            set_action_state(ACTION_STATE_HIT_LAVA);
                        }
                    } else {
                        set_action_state(ACTION_STATE_KNOCKBACK);
                    }
                }
                break;
            case SURFACE_TYPE_SPIKES:
                if ((*(s32*)(&partnerActionStatus->partnerActionState) & 0xFF0000FF) != 0x01000009) {
                    if (playerStatus->blinkTimer == 0) {
                        if (playerStatus->actionState != ACTION_STATE_HIT_FIRE) {
                            playerStatus->hazardType = HAZARD_TYPE_SPIKES;
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

void phys_player_land(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    f32 moveAngle;
    f32 moveMagnitude;

    playerStatus->timeInAir = 0;
    playerStatus->unk_C2 = 0;
    playerStatus->flags &= ~PS_FLAGS_800000;
    playerStatus->landPos.x = playerStatus->position.x;
    playerStatus->landPos.z = playerStatus->position.z;
    playerStatus->flags &= ~PS_FLAGS_AIRBORNE;
    sfx_play_sound_at_player(SOUND_SOFT_LAND, 0);
    if (!(collisionStatus->currentFloor & COLLISION_WITH_ENTITY_BIT)) {
        phys_adjust_cam_on_landing();
    }

    collisionStatus->lastTouchedFloor = -1;
    if (collisionStatus->currentFloor & COLLISION_WITH_ENTITY_BIT) {
        s32 entityType = get_entity_type(collisionStatus->currentFloor);

        if (entityType <= ACTION_STATE_FALLING) {
            if (entityType >= ACTION_STATE_LANDING_ON_SWITCH) {
                Entity* entity = get_entity_by_index(collisionStatus->currentFloor);

                entity->collisionFlags |= ENTITY_COLLISION_PLAYER_TOUCH_FLOOR;
                if (playerStatus->actionState != ACTION_STATE_TORNADO_JUMP &&
                    playerStatus->actionState != ACTION_STATE_TORNADO_POUND &&
                    playerStatus->actionState != ACTION_STATE_SPIN_JUMP &&
                    playerStatus->actionState != ACTION_STATE_SPIN_POUND)
                {
                    set_action_state(ACTION_STATE_LANDING_ON_SWITCH);
                } else {
                    disable_player_input();
                    playerStatus->actionSubstate = 11;
                }
                return;
            }
        }
    }

    if (playerStatus->flags & PS_FLAGS_4000) {
        set_action_state(ACTION_STATE_RUN);
        return;
    }

    if (playerStatus->actionState == ACTION_STATE_LANDING_ON_SWITCH) {
        set_action_state(ACTION_STATE_BOUNCE_OFF_SWITCH);
        return;
    }

    player_input_to_move_vector(&moveAngle, &moveMagnitude);
    if (moveMagnitude == 0.0f) {
        if (playerStatus->actionState != ACTION_STATE_STEP_DOWN) {
            set_action_state(ACTION_STATE_LAND);
        } else {
            set_action_state(ACTION_STATE_STEP_DOWN_LAND);
        }
        return;
    }

    if (moveMagnitude != 0.0f) {
        playerStatus->targetYaw = moveAngle;
    }
    update_locomotion_state();
}

f32 integrate_gravity(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PS_FLAGS_40000) {
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
    f32 velocity = integrate_gravity();

    if (func_800E0208()) {
        velocity = 0.0f;
    }
    return velocity;
}

f32 player_check_collision_below(f32 offset, s32* colliderID) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    f32 temp_f4 = playerStatus->colliderHeight * 0.5f;
    f32 outLength = fabsf(offset) + temp_f4;
    f32 x = playerStatus->position.x;
    f32 y = playerStatus->position.y + temp_f4;
    f32 z = playerStatus->position.z;
    f32 sp38, sp3C, sp40, sp44;
    s32 hit = *colliderID = player_raycast_below_cam_relative(&gPlayerStatus, &x, &y, &z, &outLength,
                                                              &sp38, &sp3C, &sp40, &sp44);

    if (hit < 0) {
        if (offset >= 0.0f && collisionStatus->currentCeiling >= 0) {
            return playerStatus->position.y;
        }
        y = playerStatus->position.y + offset;
    } else {
        collisionStatus->currentFloor = hit;
        collisionStatus->lastTouchedFloor = -1;
    }
    return y;
}

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
    if (playerStatus->flags & PS_FLAGS_4000) {
        speed = playerStatus->currentSpeed;
        if (playerStatus->flags & PS_FLAGS_40000) {
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
                    gCameras[CAM_DEFAULT].targetPos.x = playerStatus->position.x;
                    gCameras[CAM_DEFAULT].targetPos.y = playerStatus->position.y;
                    gCameras[CAM_DEFAULT].targetPos.z = playerStatus->position.z;
                    if (playerStatus->alpha1 != 128) {
                        collision_check_player_intersecting_world(0, 0,
                            atan2(0.0f, 0.0f, playerStatus->extraVelocity.x, playerStatus->extraVelocity.z));
                    }
                }
            }
            break;
        case ACTION_STATE_SPIN_POUND:
        case ACTION_STATE_TORNADO_POUND:
            playerStatus->position.x += playerStatus->extraVelocity.x;
            playerStatus->position.y += playerStatus->extraVelocity.y;
            playerStatus->position.z += playerStatus->extraVelocity.z;
            if (playerStatus->extraVelocity.x != 0.0f ||
                playerStatus->extraVelocity.y != 0.0f ||
                playerStatus->extraVelocity.z != 0.0f)
            {
                gCameras[CAM_DEFAULT].targetPos.x = playerStatus->position.x;
                gCameras[CAM_DEFAULT].targetPos.y = playerStatus->position.y;
                gCameras[CAM_DEFAULT].targetPos.z = playerStatus->position.z;
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
                gCameras[CAM_DEFAULT].targetPos.x = playerStatus->position.x;
                gCameras[CAM_DEFAULT].targetPos.y = playerStatus->position.y;
                gCameras[CAM_DEFAULT].targetPos.z = playerStatus->position.z;
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
            if (!(playerStatus->flags & PS_FLAGS_FLYING)) {
                f32 new_var;

                speed = 0.0f;
                if (!(playerStatus->flags & (PS_FLAGS_800000 | PS_FLAGS_INPUT_DISABLED))) {
                    player_input_to_move_vector(&yaw, &speed);
                    if (!(playerStatus->animFlags & PA_FLAGS_SPINNING)) {
                        speed *= 0.03125f;
                        if (!(playerStatus->flags & (PS_FLAGS_FALLING | PS_FLAGS_JUMPING))) {
                            speed *= 0.25;
                        }
                        if (playerStatus->actionState == ACTION_STATE_LAUNCH) {
                            speed *= 1.5;
                        }
                        if (playerStatus->flags & PS_FLAGS_40000) {
                            speed *= 0.5f;
                        }
                    }
                    sin_cos_rad(DEG_TO_RAD(yaw), &sinTheta, &cosTheta);

                    if (playerStatus->actionState == ACTION_STATE_PUSHING_BLOCK) {
                        if (fabsf(sinTheta) > fabsf(cosTheta)) {
                            xBump = speed * sinTheta;
                            zBump = 0.0f;
                        } else {
                            xBump = 0.0f;
                            zBump = -speed * cosTheta;
                        }
                    } else if (!(playerStatus->animFlags & PA_FLAGS_SPINNING)) {
                        xBump = speed * sinTheta;
                        zBump = -speed * cosTheta;
                    } else {
                        xBump = 0.0f;
                        zBump = 0.0f;
                    }

                    sin_cos_rad(DEG_TO_RAD(playerStatus->targetYaw), &sinTheta, &cosTheta);
                    speed = playerStatus->currentSpeed;
                    if (playerStatus->flags & PS_FLAGS_40000) {
                        speed *= 0.5f;
                    }
                    playerX = xBump + (speed * sinTheta);
                    playerZ = zBump - (speed * cosTheta);
                    yaw = atan2(0.0f, 0.0f, playerX, playerZ);
                    speed = sqrtf(SQ(playerX) + SQ(playerZ));
                    if (playerStatus->flags & (PS_FLAGS_FALLING | PS_FLAGS_JUMPING)) {
                        if (speed > playerStatus->runSpeed) {
                            speed = playerStatus->runSpeed;
                        }
                    }
                }

                playerStatus->position.x += playerStatus->extraVelocity.x;
                playerStatus->position.z += playerStatus->extraVelocity.z;
                if (playerStatus->timeInAir == 0) {
                    playerStatus->position.y += playerStatus->extraVelocity.y;
                }

                if (
                    playerStatus->extraVelocity.x != 0.0f ||
                    playerStatus->extraVelocity.y != 0.0f ||
                    playerStatus->extraVelocity.z != 0.0f)
                {
                    gCameras[CAM_DEFAULT].targetPos.x = playerStatus->position.x;
                    gCameras[CAM_DEFAULT].targetPos.y = playerStatus->position.y;
                    gCameras[CAM_DEFAULT].targetPos.z = playerStatus->position.z;
                }

                playerX = playerStatus->position.x;
                playerY = playerStatus->position.y;
                playerZ = playerStatus->position.z;
                result = player_test_move_with_slipping(playerStatus, &playerX, &playerY, &playerZ,
                                                        playerStatus->colliderDiameter * 0.5f, playerStatus->targetYaw);
                if (speed == 0.0f && result < 0) {
                    yaw2 = playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].currentYaw;
                    sin_cos_rad(DEG_TO_RAD(yaw2 + 180.0f), &sinTheta, &cosTheta);
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
                        if (playerStatus->animFlags & PA_FLAGS_SPINNING) {
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
        case ACTION_STATE_TORNADO_JUMP:
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

s32 phys_should_player_be_sliding(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Shadow* shadow = get_shadow_by_index(playerStatus->shadowID);
    s32 ret = FALSE;

    if (gGameStatusPtr->areaID == AREA_IWA) {
        f32 temp_f0 = shadow->rotation.z + 180.0;

        if (temp_f0 != 0.0f) {
            ret = TRUE;
            switch (gGameStatusPtr->mapID) {
                case 0:
                    if (fabsf(temp_f0) < 20.0f) {
                        ret = FALSE;
                    }
                    break;
                case 1:
                    if (playerStatus->position.x >= -300.0f && playerStatus->position.x <= -140.0f) {
                        ret = FALSE;
                    }
                    break;
            }
        }
    }
    return ret;
}

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
    s32 colliderID;
    s32 cond;

    colliderID = player_raycast_below_cam_relative(playerStatus, &playerX, &playerY, &playerZ, &outLength, &hitRx, &hitRz,
                                               &hitDirX, &hitDirZ);
    playerStatus->groundNormalPitch = get_player_normal_pitch();

    if (collHeightHalf + (temp_f24 * 0.5f) < outLength) {
        colliderID = -1;
    }
    if (playerStatus->timeInAir == 0) {
        collisionStatus->currentFloor = colliderID;
    }
    if (colliderID >= 0) {
        playerStatus->groundAnglesXZ.x = hitDirX;
        playerStatus->groundAnglesXZ.y = hitDirZ;
    }

    if (func_800E0208()) {
        return;
    }

    if (playerStatus->flags & PS_FLAGS_AIRBORNE) {
        return;
    }

    if (playerStatus->actionState == ACTION_STATE_SLIDING) {
        return;
    }

    if ((!(playerStatus->flags & PS_FLAGS_10) ||
        (phys_adjust_cam_on_landing(), !phys_should_player_be_sliding()) ||
        (set_action_state(ACTION_STATE_SLIDING), (playerStatus->actionState != ACTION_STATE_SLIDING))))
    {
        if (colliderID >= 0) {
            s32 surfaceType = get_collider_flags(colliderID) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
            switch (surfaceType) {
                case SURFACE_TYPE_SPIKES:
                    if (partnerActionStatus->partnerActionState == PARTNER_ACTION_NONE || partnerActionStatus->actingPartner != PARTNER_BOW) {
                        if (playerStatus->blinkTimer == 0) {
                            if (playerStatus->actionState != ACTION_STATE_HIT_LAVA) {
                                playerStatus->hazardType = HAZARD_TYPE_SPIKES;
                                set_action_state(ACTION_STATE_HIT_LAVA);
                            }
                        } else {
                            set_action_state(ACTION_STATE_KNOCKBACK);
                        }
                    }
                    break;
                case SURFACE_TYPE_LAVA:
                    if (partnerActionStatus->partnerActionState == PARTNER_ACTION_NONE || partnerActionStatus->actingPartner != PARTNER_BOW) {
                        if (playerStatus->blinkTimer == 0) {
                            if (playerStatus->actionState != ACTION_STATE_HIT_LAVA) {
                                playerStatus->hazardType = HAZARD_TYPE_LAVA;
                                set_action_state(ACTION_STATE_HIT_LAVA);
                            }
                        } else {
                            set_action_state(ACTION_STATE_KNOCKBACK);
                        }
                    }
                    break;
                default:
                    cond = FALSE;
                    if (collisionStatus->currentFloor & COLLISION_WITH_ENTITY_BIT) {
                        cond = get_entity_type(collisionStatus->currentFloor) == ENTITY_TYPE_HIDDEN_PANEL;
                    }

                    if (playerStatus->actionState != ACTION_STATE_STEP_UP && !cond) {
                        if (!(playerStatus->animFlags & PA_FLAGS_USING_PEACH_PHYSICS)) {
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
        } else if (!(playerStatus->flags & PS_FLAGS_FLYING) &&
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

void collision_lava_reset_check_additional_overlaps(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 x, y, z;
    f32 temp_f0;

    if (playerStatus->animFlags & PA_FLAGS_USING_PEACH_PHYSICS) {
        func_800E4F10();
        return;
    }

    temp_f0 = clamp_angle(playerStatus->targetYaw - 30.0);
    y = playerStatus->position.y + (playerStatus->colliderHeight * 0.75f);
    x = playerStatus->position.x;
    z = playerStatus->position.z;
    player_test_lateral_overlap(0, &gPlayerStatus, &x, &y, &z, 0.0f, temp_f0);
    playerStatus->position.x = x;
    playerStatus->position.z = z;

    temp_f0 = clamp_angle(playerStatus->targetYaw + 30.0);
    y = playerStatus->position.y + (playerStatus->colliderHeight * 0.75f);
    x = playerStatus->position.x;
    z = playerStatus->position.z;
    player_test_lateral_overlap(0, &gPlayerStatus, &x, &y, &z, 0.0f, temp_f0);
    playerStatus->position.x = x;
    playerStatus->position.z = z;

    temp_f0 = clamp_angle(playerStatus->targetYaw - 30.0);
    x = playerStatus->position.x;
    y = playerStatus->position.y;
    z = playerStatus->position.z;
    player_test_lateral_overlap(0, &gPlayerStatus, &x, &y, &z, 0.0f, temp_f0);
    playerStatus->position.x = x;
    playerStatus->position.z = z;

    temp_f0 = clamp_angle(playerStatus->targetYaw + 30.0);
    x = playerStatus->position.x;
    y = playerStatus->position.y;
    z = playerStatus->position.z;
    player_test_lateral_overlap(0, &gPlayerStatus, &x, &y, &z, 0.0f, temp_f0);
    playerStatus->position.x = x;
    playerStatus->position.z = z;

    temp_f0 = clamp_angle(playerStatus->targetYaw + 90.0);
    x = playerStatus->position.x;
    y = playerStatus->position.y;
    z = playerStatus->position.z;
    player_test_lateral_overlap(0, &gPlayerStatus, &x, &y, &z, 0.0f, temp_f0);
    playerStatus->position.x = x;
    playerStatus->position.z = z;
    temp_f0 = clamp_angle(playerStatus->targetYaw - 90.0);

    x = playerStatus->position.x;
    y = playerStatus->position.y;
    z = playerStatus->position.z;
    player_test_lateral_overlap(0, &gPlayerStatus, &x, &y, &z, 0.0f, temp_f0);
    playerStatus->position.x = x;
    playerStatus->position.z = z;

    temp_f0 = clamp_angle(playerStatus->targetYaw + 180.0);
    x = playerStatus->position.x;
    y = playerStatus->position.y;
    z = playerStatus->position.z;
    player_test_lateral_overlap(0, &gPlayerStatus, &x, &y, &z, 0.0f, temp_f0);
    playerStatus->position.x = x;
    playerStatus->position.z = z;
}

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
    if (!(gPlayerStatus.flags & (PS_FLAGS_800000 | PS_FLAGS_10 | PS_FLAGS_FLYING)) &&
        !(gPlayerStatus.animFlags & (PA_FLAGS_8BIT_MARIO | PA_FLAGS_HOLDING_WATT)) &&
        gPlayerStatus.unk_C2 >= 6 &&
        gPlayerStatus.timeInAir < 18 &&
        gPlayerStatus.pressedButtons & A_BUTTON) {

        switch (gPlayerData.bootsLevel) {
            case 0:
                break;
            case 1:
                set_action_state(ACTION_STATE_SPIN_JUMP);
                gPlayerStatus.flags |= PS_FLAGS_FLYING;
                break;
            case 2:
                set_action_state(ACTION_STATE_TORNADO_JUMP);
                gPlayerStatus.flags |= PS_FLAGS_FLYING;
                break;
        }
    }
}

s8 get_current_partner_id(void) {
    return gPlayerData.currentPartner;
}

void try_player_footstep_sounds(s32 interval) {
    if (gGameStatusPtr->frameCounter % interval == 0) {
        s32 surfaceType = get_collider_flags(gCollisionStatus.currentFloor) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
        s32 soundID, altSoundID;

        if (surfaceType == SURFACE_TYPE_FLOWERS || surfaceType == SURFACE_TYPE_HEDGES) {
            soundID = SOUND_STEP_CRUNCHY1;
            altSoundID = SOUND_STEP_CRUNCHY2;
        } else {
            soundID = SOUND_STEP_NORMAL1;
            altSoundID = SOUND_STEP_NORMAL2;
        }

        if (FootstepSoundSelector == 0) {
            soundID = altSoundID;
        }

        sfx_play_sound_at_player(soundID, 0);
        FootstepSoundSelector ^= 1;
    }
}

void phys_update_interact_collider(void) {
    gCollisionStatus.currentInspect = phys_check_interactable_collision();
}

s32 phys_check_interactable_collision(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 x, y, z, yaw;
    s32 ret = -1;

    if (playerStatus->flags & PS_FLAGS_INPUT_DISABLED) {
        return ret;
    }

    if (playerStatus->pressedButtons & BUTTON_A) {
        yaw = playerStatus->targetYaw;
        x = playerStatus->position.x;
        y = playerStatus->position.y;
        z = playerStatus->position.z;
        ret = player_test_move_with_slipping(playerStatus, &x, &y, &z, playerStatus->colliderDiameter * 0.5f, yaw);

        if (ret < 0 && playerStatus->currentSpeed == 0.0f) {
            yaw = playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].currentYaw;
            x = playerStatus->position.x;
            y = playerStatus->position.y;
            z = playerStatus->position.z;
            ret = player_test_move_with_slipping(playerStatus, &x, &y, &z, playerStatus->colliderDiameter * 0.5f, yaw);
        }
    }

    return ret;
}

s32 phys_can_player_interact(void) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 ret = TRUE;

    if (gPartnerActionStatus.partnerActionState != PARTNER_ACTION_NONE) {
        if (gPartnerActionStatus.actingPartner == PARTNER_BOMBETTE) {
            if (gPartnerActionStatus.partnerActionState <= PARTNER_ACTION_BOMBETTE_2) {
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

f32 func_800E5348(void) {
    f32 deltaYaw = get_clamped_angle_diff(gCameras[gCurrentCameraID].currentYaw, gPlayerStatus.currentYaw);

    if (deltaYaw < -5.0f && deltaYaw > -175.0f) {
        deltaYaw = 0.0f;
    } else if (deltaYaw > 5.0f && deltaYaw < 175.0f) {
        deltaYaw = 180.0f;
    } else {
        deltaYaw = PrevPlayerCamRelativeYaw;
    }
    return clamp_angle(deltaYaw - 90.0f + gCameras[gCurrentCameraID].currentYaw);
}

f32 player_get_camera_facing_angle(void) {
    f32 angle = 0.0f;

    if (gPlayerStatus.spriteFacingAngle >= 90.0f && gPlayerStatus.spriteFacingAngle < 270.0f) {
        angle = 180.0f;
    }

    angle = angle + gCameras[CAM_DEFAULT].currentYaw + 90.0f;

    return clamp_angle(angle);
}

void phys_save_ground_pos(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->lastGoodPosition.x = playerStatus->position.x;
    playerStatus->lastGoodPosition.y = playerStatus->position.y;
    playerStatus->lastGoodPosition.z = playerStatus->position.z;
}
