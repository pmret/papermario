#include "common.h"
#include "world/partners.h"
#include "sprite/player.h"

SHIFT_BSS CollisionStatus gCollisionStatus;
SHIFT_BSS f32 D_8010C928;
SHIFT_BSS f32 JumpedOnSwitchX;
SHIFT_BSS f32 JumpedOnSwitchZ;
SHIFT_BSS f32 D_8010C984;

extern f32 GravityParamsStartJump[];

s32 collision_check_player_intersecting_world(s32 mode, s32 arg1, f32 yaw);
s32 phys_check_interactable_collision(void);
void phys_save_ground_pos(void);

void record_jump_apex(void) {
    gPlayerStatus.jumpApexHeight = gPlayerStatus.pos.y;
}

s32 can_trigger_loading_zone(void) {
    PlayerData* playerData = &gPlayerData;
    s32 actionState = gPlayerStatusPtr->actionState;
    PartnerStatus* partnerStatus = &gPartnerStatus;

    if (actionState == ACTION_STATE_IDLE ||
        actionState == ACTION_STATE_WALK ||
        actionState == ACTION_STATE_RUN ||
        actionState == ACTION_STATE_USE_TWEESTER ||
        actionState == ACTION_STATE_SPIN
       ) {
        return TRUE;
    }

    if (actionState == ACTION_STATE_RIDE) {
        if (playerData->curPartner == PARTNER_LAKILESTER || playerData->curPartner == PARTNER_BOW) {
            if (partnerStatus->partnerActionState != PARTNER_ACTION_NONE) {
                return TRUE;
            } else {
                gPlayerStatusPtr->animFlags |= PA_FLAG_INTERRUPT_USE_PARTNER;
                return FALSE;
            }
        } else {
            if (partnerStatus->actingPartner == PARTNER_WATT || partnerStatus->actingPartner == PARTNER_SUSHIE) {
                return partnerStatus->partnerActionState != PARTNER_ACTION_NONE;
            }
            if (partnerStatus->actingPartner == PARTNER_PARAKARRY) {
                gPlayerStatusPtr->animFlags |= PA_FLAG_INTERRUPT_USE_PARTNER;
                return FALSE;
            }
        }
    }
    return FALSE;
}

void move_player(s32 duration, f32 heading, f32 speed) {
    gPlayerStatus.flags |= PS_FLAG_CUTSCENE_MOVEMENT;
    gPlayerStatus.heading = heading;
    gPlayerStatus.moveFrames = duration;
    gPlayerStatus.curSpeed = speed;

    if (!(gPlayerStatus.animFlags & PA_FLAG_RIDING_PARTNER)) {
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
    x = playerStatus->pos.x;
    y = playerStatus->pos.y + new_var;
    z = playerStatus->pos.z;

    player_input_to_move_vector(&moveAngle, &moveMagnitude);

    if (moveMagnitude != 0.0f) {
        phi_f2 = playerStatus->targetYaw;
    } else {
        phi_f2 = playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].curYaw;
    }

    moveAngle = phi_f2;
    hitResult = player_raycast_up_corners(playerStatus, &x, &y, &z, &sp2C, moveAngle);
    collisionStatus->curCeiling = hitResult;

    if (hitResult >= 0) {
        if (playerStatus->actionState != ACTION_STATE_FALLING
            && playerStatus->actionState != ACTION_STATE_STEP_DOWN
            && collisionStatus->curFloor <= NO_COLLIDER
        ) {
            if (sp2C <= fabsf(new_var + playerStatus->gravityIntegrator[0])) {
                do {
                    if ((hitResult & COLLISION_WITH_ENTITY_BIT) && get_entity_type(hitResult) == ENTITY_TYPE_BRICK_BLOCK) {
                        return hitResult;
                    }
                } while (0);

                playerStatus->pos.y = y - ((playerStatus->colliderHeight / 5.0f) * 3.0f);
                if (playerStatus->actionState != ACTION_STATE_TORNADO_JUMP
                    && playerStatus->actionState != ACTION_STATE_SPIN_JUMP
                ) {
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

void handle_switch_hit(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 colliderID;
    f32 groundPosY;
    AnimID anim;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
        playerStatus->actionSubstate = LANDING_ON_SWITCH_SUBSTATE_0;
    }

    if (playerStatus->actionSubstate == LANDING_ON_SWITCH_SUBSTATE_0) {
        if (dist2D(JumpedOnSwitchX, JumpedOnSwitchZ, playerStatus->pos.x, playerStatus->pos.z) <= 22.0f) {
            add_vec2D_polar(&playerStatus->pos.x, &playerStatus->pos.z, 5.0f, playerStatus->targetYaw);
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
        playerStatus->pos.y += playerStatus->gravityIntegrator[0];
    } else if (playerStatus->actionSubstate == LANDING_ON_SWITCH_SUBSTATE_2) {
        if (dist2D(JumpedOnSwitchX, JumpedOnSwitchZ, playerStatus->pos.x, playerStatus->pos.z) <= 22.0f) {
            add_vec2D_polar(&playerStatus->pos.x, &playerStatus->pos.z, 5.0f, playerStatus->targetYaw);
        }
        groundPosY = player_check_collision_below(player_fall_distance(), &colliderID);
        player_handle_floor_collider_type(colliderID);
        playerStatus->pos.y = groundPosY;
        if (colliderID >= 0) {
            if (!(playerStatus->animFlags & PA_FLAG_USING_WATT)) {
                anim = ANIM_Mario1_Land;
            } else {
                anim = ANIM_MarioW1_LandWatt;
            }
            suggest_player_anim_allow_backward(anim);
            enable_player_input();
            phys_player_land();
        }
    }
}

void func_800E2BB0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 cond = FALSE;

    if (playerStatus->pos.y < playerStatus->gravityIntegrator[3] + playerStatus->gravityIntegrator[2]) {
        f32 phi_f6 = (playerStatus->gravityIntegrator[3] - playerStatus->pos.y) / 777.0f;

        if (phi_f6 < -0.47) {
            phi_f6 = -0.47f;
        }
        if (phi_f6 > 0.001) {
            phi_f6 = 0.001f;
        }
        playerStatus->gravityIntegrator[0] += phi_f6;
        playerStatus->pos.y += playerStatus->gravityIntegrator[0];
        if (playerStatus->gravityIntegrator[0] <= 0.0f) {
            cond = TRUE;
        }
    } else {
        playerStatus->gravityIntegrator[0] += -1.2;
        if (playerStatus->gravityIntegrator[0] <= 0.0f) {
            cond = TRUE;
        }
        playerStatus->pos.y += playerStatus->gravityIntegrator[0];
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
                handle_switch_hit();
                return;
            case ACTION_STATE_BOUNCE:
                integrate_gravity();
                playerStatus->pos.y += playerStatus->gravityIntegrator[0];
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
                playerStatus->pos.y += playerStatus->gravityIntegrator[0];
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
                if (!(playerStatus->curButtons & BUTTON_A)) {
                    record_jump_apex();
                    set_action_state(ACTION_STATE_HOP);
                    integrate_gravity();
                    if (playerStatus->flags & PS_FLAG_ENTERING_BATTLE) {
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
    playerStatus->pos.y += playerStatus->gravityIntegrator[0];
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
            if (!(playerStatus->flags & PS_FLAG_ENTERING_BATTLE)) {
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

    if (playerStatus->flags & PS_FLAG_ENTERING_BATTLE) {
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
    if (gPlayerStatus.actionState != ACTION_STATE_LANDING_ON_SWITCH
    && gPlayerStatus.actionState != ACTION_STATE_BOUNCE
    ) {
        s32 colliderID;
        gPlayerStatus.pos.y = player_check_collision_below(player_fall_distance(), &colliderID);
        player_handle_floor_collider_type(colliderID);
    }
}

void player_handle_floor_collider_type(s32 colliderID) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;

    if (colliderID >= 0) {
        s32 surfaceType = get_collider_flags(colliderID) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
        switch (surfaceType) {
            case SURFACE_TYPE_WATER:
            case SURFACE_TYPE_DOCK_WALL:
            case SURFACE_TYPE_SLIDE:
                set_action_state(ACTION_STATE_LAND);
                break;
            case SURFACE_TYPE_LAVA:
                if ((*(s32*)(&partnerStatus->partnerActionState) & 0xFF0000FF) != 0x01000009) {
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
                if ((*(s32*)(&partnerStatus->partnerActionState) & 0xFF0000FF) != 0x01000009) {
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
    playerStatus->peakJumpTime = 0;
    playerStatus->flags &= ~PS_FLAG_SCRIPTED_FALL;
    playerStatus->landPos.x = playerStatus->pos.x;
    playerStatus->landPos.z = playerStatus->pos.z;
    playerStatus->flags &= ~PS_FLAG_AIRBORNE;
    sfx_play_sound_at_player(SOUND_SOFT_LAND, SOUND_SPACE_MODE_0);
    if (!(collisionStatus->curFloor & COLLISION_WITH_ENTITY_BIT)) {
        phys_adjust_cam_on_landing();
    }

    collisionStatus->lastTouchedFloor = -1;
    if (collisionStatus->curFloor & COLLISION_WITH_ENTITY_BIT) {
        s32 entityType = get_entity_type(collisionStatus->curFloor);

        if (entityType <= ACTION_STATE_FALLING) {
            if (entityType >= ACTION_STATE_LANDING_ON_SWITCH) {
                Entity* entity = get_entity_by_index(collisionStatus->curFloor);

                entity->collisionFlags |= ENTITY_COLLISION_PLAYER_TOUCH_FLOOR;
                if (playerStatus->actionState != ACTION_STATE_TORNADO_JUMP
                    && playerStatus->actionState != ACTION_STATE_TORNADO_POUND
                    && playerStatus->actionState != ACTION_STATE_SPIN_JUMP
                    && playerStatus->actionState != ACTION_STATE_SPIN_POUND
                ) {
                    set_action_state(ACTION_STATE_LANDING_ON_SWITCH);
                } else {
                    disable_player_input();
                    playerStatus->actionSubstate = 11;
                }
                return;
            }
        }
    }

    if (playerStatus->flags & PS_FLAG_CUTSCENE_MOVEMENT) {
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

    if (playerStatus->flags & PS_FLAG_ENTERING_BATTLE) {
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

f32 player_fall_distance(void) {
    f32 velocity = integrate_gravity();

    if (game_scripts_disabled()) {
        velocity = 0.0f;
    }
    return velocity;
}

f32 player_check_collision_below(f32 offset, s32* colliderID) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    f32 temp_f4 = playerStatus->colliderHeight * 0.5f;
    f32 outLength = fabsf(offset) + temp_f4;
    f32 x = playerStatus->pos.x;
    f32 y = playerStatus->pos.y + temp_f4;
    f32 z = playerStatus->pos.z;
    f32 sp38, sp3C, sp40, sp44;
    s32 hit = *colliderID = player_raycast_below_cam_relative(&gPlayerStatus, &x, &y, &z, &outLength,
                                                              &sp38, &sp3C, &sp40, &sp44);

    if (hit < 0) {
        if (offset >= 0.0f && collisionStatus->curCeiling >= 0) {
            return playerStatus->pos.y;
        }
        y = playerStatus->pos.y + offset;
    } else {
        collisionStatus->curFloor = hit;
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

    gCollisionStatus.pushingAgainstWall = NO_COLLIDER;
    if (playerStatus->flags & PS_FLAG_CUTSCENE_MOVEMENT) {
        speed = playerStatus->curSpeed;
        if (playerStatus->flags & PS_FLAG_ENTERING_BATTLE) {
            speed *= 0.5f;
        }
        add_vec2D_polar(&playerStatus->pos.x, &playerStatus->pos.z, speed, playerStatus->heading);
        return;
    }

    switch (playerStatus->actionState) {
        case ACTION_STATE_STEP_UP:
            collision_check_player_intersecting_world(0, 0,
                playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].curYaw);
            break;
        case ACTION_STATE_RIDE:
            if (get_current_partner_id() == PARTNER_BOW) {
                playerStatus->pos.x += playerStatus->pushVel.x;
                playerStatus->pos.y += playerStatus->pushVel.y;
                playerStatus->pos.z += playerStatus->pushVel.z;

                if (playerStatus->pushVel.x != 0.0f ||
                    playerStatus->pushVel.y != 0.0f ||
                    playerStatus->pushVel.z != 0.0f)
                {
                    gCameras[CAM_DEFAULT].targetPos.x = playerStatus->pos.x;
                    gCameras[CAM_DEFAULT].targetPos.y = playerStatus->pos.y;
                    gCameras[CAM_DEFAULT].targetPos.z = playerStatus->pos.z;
                    if (playerStatus->alpha1 != 128) {
                        collision_check_player_intersecting_world(0, 0,
                            atan2(0.0f, 0.0f, playerStatus->pushVel.x, playerStatus->pushVel.z));
                    }
                }
            }
            break;
        case ACTION_STATE_SPIN_POUND:
        case ACTION_STATE_TORNADO_POUND:
            playerStatus->pos.x += playerStatus->pushVel.x;
            playerStatus->pos.y += playerStatus->pushVel.y;
            playerStatus->pos.z += playerStatus->pushVel.z;
            if (playerStatus->pushVel.x != 0.0f ||
                playerStatus->pushVel.y != 0.0f ||
                playerStatus->pushVel.z != 0.0f)
            {
                gCameras[CAM_DEFAULT].targetPos.x = playerStatus->pos.x;
                gCameras[CAM_DEFAULT].targetPos.y = playerStatus->pos.y;
                gCameras[CAM_DEFAULT].targetPos.z = playerStatus->pos.z;
            }
            if (playerStatus->pushVel.x != 0.0f ||
                playerStatus->pushVel.y != 0.0f ||
                playerStatus->pushVel.z != 0.0f)
            {
                collision_check_player_intersecting_world(0, 0,
                    playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].curYaw);
            }
            break;
        case ACTION_STATE_HAMMER:
            playerStatus->pos.x += playerStatus->pushVel.x;
            playerStatus->pos.y += playerStatus->pushVel.y;
            playerStatus->pos.z += playerStatus->pushVel.z;
            if (playerStatus->pushVel.x != 0.0f ||
                playerStatus->pushVel.y != 0.0f ||
                playerStatus->pushVel.z != 0.0f)
            {
                gCameras[CAM_DEFAULT].targetPos.x = playerStatus->pos.x;
                gCameras[CAM_DEFAULT].targetPos.y = playerStatus->pos.y;
                gCameras[CAM_DEFAULT].targetPos.z = playerStatus->pos.z;
            }

            playerX = playerStatus->pos.x;
            playerY = playerStatus->pos.y;
            playerZ = playerStatus->pos.z;
            if (playerStatus->curSpeed != 0.0f) {
                yaw = playerStatus->targetYaw;
            } else {
                yaw = playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].curYaw;
            }
            collisionStatus->curWall =
                player_test_move_with_slipping(playerStatus, &playerX, &playerY, &playerZ,
                                               playerStatus->colliderDiameter * 0.5f, yaw);

            if (playerStatus->pushVel.x != 0.0f ||
                playerStatus->pushVel.y != 0.0f ||
                playerStatus->pushVel.z != 0.0f)
            {
                collision_check_player_intersecting_world(0, 0,
                    playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].curYaw);
            }
            break;
        default:
            if (!(playerStatus->flags & PS_FLAG_FLYING)) {
                f32 new_var;

                speed = 0.0f;
                if (!(playerStatus->flags & (PS_FLAG_SCRIPTED_FALL | PS_FLAG_INPUT_DISABLED))) {
                    player_input_to_move_vector(&yaw, &speed);
                    if (!(playerStatus->animFlags & PA_FLAG_SPINNING)) {
                        speed *= 0.03125f;
                        if (!(playerStatus->flags & (PS_FLAG_FALLING | PS_FLAG_JUMPING))) {
                            speed *= 0.25;
                        }
                        if (playerStatus->actionState == ACTION_STATE_LAUNCH) {
                            speed *= 1.5;
                        }
                        if (playerStatus->flags & PS_FLAG_ENTERING_BATTLE) {
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
                    } else if (!(playerStatus->animFlags & PA_FLAG_SPINNING)) {
                        xBump = speed * sinTheta;
                        zBump = -speed * cosTheta;
                    } else {
                        xBump = 0.0f;
                        zBump = 0.0f;
                    }

                    sin_cos_rad(DEG_TO_RAD(playerStatus->targetYaw), &sinTheta, &cosTheta);
                    speed = playerStatus->curSpeed;
                    if (playerStatus->flags & PS_FLAG_ENTERING_BATTLE) {
                        speed *= 0.5f;
                    }
                    playerX = xBump + (speed * sinTheta);
                    playerZ = zBump - (speed * cosTheta);
                    yaw = atan2(0.0f, 0.0f, playerX, playerZ);
                    speed = sqrtf(SQ(playerX) + SQ(playerZ));
                    if (playerStatus->flags & (PS_FLAG_FALLING | PS_FLAG_JUMPING)) {
                        if (speed > playerStatus->runSpeed) {
                            speed = playerStatus->runSpeed;
                        }
                    }
                }

                playerStatus->pos.x += playerStatus->pushVel.x;
                playerStatus->pos.z += playerStatus->pushVel.z;
                if (playerStatus->timeInAir == 0) {
                    playerStatus->pos.y += playerStatus->pushVel.y;
                }

                if (
                    playerStatus->pushVel.x != 0.0f ||
                    playerStatus->pushVel.y != 0.0f ||
                    playerStatus->pushVel.z != 0.0f)
                {
                    gCameras[CAM_DEFAULT].targetPos.x = playerStatus->pos.x;
                    gCameras[CAM_DEFAULT].targetPos.y = playerStatus->pos.y;
                    gCameras[CAM_DEFAULT].targetPos.z = playerStatus->pos.z;
                }

                playerX = playerStatus->pos.x;
                playerY = playerStatus->pos.y;
                playerZ = playerStatus->pos.z;
                result = player_test_move_with_slipping(playerStatus, &playerX, &playerY, &playerZ,
                                                        playerStatus->colliderDiameter * 0.5f, playerStatus->targetYaw);
                if (speed == 0.0f && result < 0) {
                    yaw2 = playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].curYaw;
                    sin_cos_rad(DEG_TO_RAD(yaw2 + 180.0f), &sinTheta, &cosTheta);
                    playerX = playerStatus->pos.x + (sinTheta * playerStatus->colliderDiameter * 0.5f);
                    playerY = playerStatus->pos.y;
                    playerZ = playerStatus->pos.z - (cosTheta * playerStatus->colliderDiameter * 0.5f);
                    result = player_test_move_with_slipping(playerStatus, &playerX, &playerY, &playerZ,
                                                            playerStatus->colliderDiameter, yaw2);
                }
                collisionStatus->curWall = result;
                if (!(playerStatus->flags & PS_FLAG_MOVEMENT_LOCKED) && playerStatus->actionState != ACTION_STATE_HAMMER) {
                    if (speed == 0.0f) {
                        collision_check_player_intersecting_world(0, 0,
                            playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].curYaw);
                        break;
                    }

                    playerX = playerStatus->pos.x;
                    playerZ = playerStatus->pos.z;
                    playerY = playerStatus->pos.y;
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
                            playerStatus->pos.x = playerX;
                            playerStatus->pos.z = playerZ;
                        } else {
                            playerStatus->pos.x = test1X;
                            playerStatus->pos.z = test1Z;
                        }
                    } else if (test2 < 0) {
                        playerStatus->pos.x = test2X;
                        playerStatus->pos.z = test2Y;
                    }

                    if (playerStatus->enableCollisionOverlapsCheck == 0) {
                        if (playerStatus->animFlags & PA_FLAG_SPINNING) {
                            yaw2 = playerStatus->targetYaw;
                        } else {
                            yaw2 = playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].curYaw;
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

s32 collision_check_player_intersecting_world(s32 mode, s32 arg1, f32 yaw) {
    f32 angle = 0.0f;
    s32 ret = -1;
    s32 i;

    for (i = 0; i < 4; i++) {
        f32 x = gPlayerStatusPtr->pos.x;
        f32 y = gPlayerStatusPtr->pos.y + arg1;
        f32 z = gPlayerStatusPtr->pos.z;
        s32 hitID, hitID2;

        hitID = player_test_lateral_overlap(mode, gPlayerStatusPtr, &x, &y, &z, 0.0f, angle);

        // required to match
        if (hitID > 0 || hitID == 0) {
            hitID2 = hitID;
        } else if (hitID == -1) {
            hitID2 = hitID;
        } else {
            hitID2 = hitID;
        }

        if (hitID2 >= 0) {
            ret = hitID2;
        }
        gPlayerStatusPtr = gPlayerStatusPtr;

        gPlayerStatusPtr->pos.x = x;
        gPlayerStatusPtr->pos.z = z;
        angle += 90.0f;
    }

    return ret;
}

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
        f32 x = playerStatus->pos.x;
        f32 y = playerStatus->pos.y;
        f32 z = playerStatus->pos.z;

        player_test_lateral_overlap(0, &gPlayerStatus, &x, &y, &z, overlapPush, playerStatus->overlapPushYaw);

        overlapPush -= playerStatus->runSpeed / 10.0f;
        playerStatus->pos.x = x;
        playerStatus->pos.y = y;
        playerStatus->pos.z = z;

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
        f32 temp_f0 = shadow->rot.z + 180.0;

        if (temp_f0 != 0.0f) {
            ret = TRUE;
            switch (gGameStatusPtr->mapID) {
                case 0:
                    if (fabsf(temp_f0) < 20.0f) {
                        ret = FALSE;
                    }
                    break;
                case 1:
                    if (playerStatus->pos.x >= -300.0f && playerStatus->pos.x <= -140.0f) {
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
    f32 rotZ = playerShadow->rot.z + 180.0;
    f32 rotX = playerShadow->rot.x + 180.0;
    s32 ret = TRUE;

    if (fabsf(rotZ) < 20.0f && fabsf(rotX) < 20.0f) {
        ret = FALSE;
    }

    return ret;
}

void phys_main_collision_below(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    f32 collHeightHalf = playerStatus->colliderHeight * 0.5f;
    f32 playerX = playerStatus->pos.x;
    f32 playerY = playerStatus->pos.y + collHeightHalf;
    f32 playerZ = playerStatus->pos.z;
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
        colliderID = NO_COLLIDER;
    }
    if (playerStatus->timeInAir == 0) {
        collisionStatus->curFloor = colliderID;
    }
    if (colliderID >= 0) {
        playerStatus->groundAnglesXZ.x = hitDirX;
        playerStatus->groundAnglesXZ.y = hitDirZ;
    }

    if (game_scripts_disabled()) {
        return;
    }

    if (playerStatus->flags & PS_FLAG_AIRBORNE) {
        return;
    }

    if (playerStatus->actionState == ACTION_STATE_SLIDING) {
        return;
    }

    if ((!(playerStatus->flags & PS_FLAG_SLIDING) ||
        (phys_adjust_cam_on_landing(), !phys_should_player_be_sliding()) ||
        (set_action_state(ACTION_STATE_SLIDING), (playerStatus->actionState != ACTION_STATE_SLIDING))))
    {
        if (colliderID >= 0) {
            s32 surfaceType = get_collider_flags(colliderID) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
            switch (surfaceType) {
                case SURFACE_TYPE_SPIKES:
                    if (partnerStatus->partnerActionState == PARTNER_ACTION_NONE || partnerStatus->actingPartner != PARTNER_BOW) {
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
                    if (partnerStatus->partnerActionState == PARTNER_ACTION_NONE || partnerStatus->actingPartner != PARTNER_BOW) {
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
                    if (collisionStatus->curFloor & COLLISION_WITH_ENTITY_BIT) {
                        cond = get_entity_type(collisionStatus->curFloor) == ENTITY_TYPE_HIDDEN_PANEL;
                    }

                    if (playerStatus->actionState != ACTION_STATE_STEP_UP && !cond) {
                        if (!(playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS)) {
                            if (playerY - playerStatus->pos.y < 6.0f) {
                                playerStatus->pos.y = playerY;
                            } else {
                                set_action_state(ACTION_STATE_STEP_UP);
                                D_8010C928 = playerY;
                                D_8010C984 = playerStatus->targetYaw;
                            }
                        } else {
                            playerStatus->pos.y = playerY;
                        }
                        phys_save_ground_pos();
                    }
                    break;
            }
        } else if (!(playerStatus->flags & PS_FLAG_FLYING)
             && playerStatus->actionState != ACTION_STATE_USE_SPINNING_FLOWER
        ) {
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

    collision_check_player_intersecting_world(mode, 0, gPlayerStatus.spriteFacingAngle - 90.0f + currentCamera->curYaw);
}

void func_800E4B40(s32 mode, f32* arg1, f32* arg2, f32* arg3) {
    Camera* currentCamera = &gCameras[gCurrentCameraID];

    func_800E4404(mode, 0, gPlayerStatus.spriteFacingAngle - 90.0f + currentCamera->curYaw, arg1, arg2, arg3);
}

void collision_lava_reset_check_additional_overlaps(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 x, y, z;
    f32 temp_f0;

    if (playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS) {
        collision_lateral_peach();
        return;
    }

    temp_f0 = clamp_angle(playerStatus->targetYaw - 30.0);
    y = playerStatus->pos.y + (playerStatus->colliderHeight * 0.75f);
    x = playerStatus->pos.x;
    z = playerStatus->pos.z;
    player_test_lateral_overlap(0, &gPlayerStatus, &x, &y, &z, 0.0f, temp_f0);
    playerStatus->pos.x = x;
    playerStatus->pos.z = z;

    temp_f0 = clamp_angle(playerStatus->targetYaw + 30.0);
    y = playerStatus->pos.y + (playerStatus->colliderHeight * 0.75f);
    x = playerStatus->pos.x;
    z = playerStatus->pos.z;
    player_test_lateral_overlap(0, &gPlayerStatus, &x, &y, &z, 0.0f, temp_f0);
    playerStatus->pos.x = x;
    playerStatus->pos.z = z;

    temp_f0 = clamp_angle(playerStatus->targetYaw - 30.0);
    x = playerStatus->pos.x;
    y = playerStatus->pos.y;
    z = playerStatus->pos.z;
    player_test_lateral_overlap(0, &gPlayerStatus, &x, &y, &z, 0.0f, temp_f0);
    playerStatus->pos.x = x;
    playerStatus->pos.z = z;

    temp_f0 = clamp_angle(playerStatus->targetYaw + 30.0);
    x = playerStatus->pos.x;
    y = playerStatus->pos.y;
    z = playerStatus->pos.z;
    player_test_lateral_overlap(0, &gPlayerStatus, &x, &y, &z, 0.0f, temp_f0);
    playerStatus->pos.x = x;
    playerStatus->pos.z = z;

    temp_f0 = clamp_angle(playerStatus->targetYaw + 90.0);
    x = playerStatus->pos.x;
    y = playerStatus->pos.y;
    z = playerStatus->pos.z;
    player_test_lateral_overlap(0, &gPlayerStatus, &x, &y, &z, 0.0f, temp_f0);
    playerStatus->pos.x = x;
    playerStatus->pos.z = z;
    temp_f0 = clamp_angle(playerStatus->targetYaw - 90.0);

    x = playerStatus->pos.x;
    y = playerStatus->pos.y;
    z = playerStatus->pos.z;
    player_test_lateral_overlap(0, &gPlayerStatus, &x, &y, &z, 0.0f, temp_f0);
    playerStatus->pos.x = x;
    playerStatus->pos.z = z;

    temp_f0 = clamp_angle(playerStatus->targetYaw + 180.0);
    x = playerStatus->pos.x;
    y = playerStatus->pos.y;
    z = playerStatus->pos.z;
    player_test_lateral_overlap(0, &gPlayerStatus, &x, &y, &z, 0.0f, temp_f0);
    playerStatus->pos.x = x;
    playerStatus->pos.z = z;
}

void collision_lateral_peach(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 climbableStep = FALSE;
    f32 yaw = playerStatus->targetYaw;
    f32 x = playerStatus->pos.x;
    f32 y = playerStatus->pos.y;
    f32 z = playerStatus->pos.z;
    s32 wall = player_test_move_without_slipping(&gPlayerStatus, &x, &y, &z, 0, yaw, &climbableStep);

    playerStatus->pos.x = x;
    playerStatus->pos.z = z;

    // If there was a climbable step in this direction, but no wall, we can climb up it
    if (climbableStep
        && wall < 0
        && playerStatus->actionState != ACTION_STATE_STEP_UP_PEACH
        &&  playerStatus->curSpeed != 0.0f
    ) {
        set_action_state(ACTION_STATE_STEP_UP_PEACH);
    }
}

void check_input_midair_jump(void) {
    if (!(gPlayerStatus.flags & (PS_FLAG_SCRIPTED_FALL | PS_FLAG_SLIDING | PS_FLAG_FLYING))
        && !(gPlayerStatus.animFlags & (PA_FLAG_8BIT_MARIO | PA_FLAG_USING_WATT))
        && gPlayerStatus.peakJumpTime >= 6
        && gPlayerStatus.timeInAir < 18
        && gPlayerStatus.pressedButtons & BUTTON_A
    ) {
        switch (gPlayerData.bootsLevel) {
            case 0:
                break;
            case 1:
                set_action_state(ACTION_STATE_SPIN_JUMP);
                gPlayerStatus.flags |= PS_FLAG_FLYING;
                break;
            case 2:
                set_action_state(ACTION_STATE_TORNADO_JUMP);
                gPlayerStatus.flags |= PS_FLAG_FLYING;
                break;
        }
    }
}

s8 get_current_partner_id(void) {
    return gPlayerData.curPartner;
}

void try_player_footstep_sounds(s32 interval) {
    if (gGameStatusPtr->frameCounter % interval == 0) {
        s32 surfaceType = get_collider_flags(gCollisionStatus.curFloor) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
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

        sfx_play_sound_at_player(soundID, SOUND_SPACE_MODE_0);
        FootstepSoundSelector ^= 1;
    }
}

void phys_update_interact_collider(void) {
    gCollisionStatus.curInspect = phys_check_interactable_collision();
}

s32 phys_check_interactable_collision(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 x, y, z, yaw;
    s32 ret = -1;

    if (playerStatus->flags & PS_FLAG_INPUT_DISABLED) {
        return ret;
    }

    if (playerStatus->pressedButtons & BUTTON_A) {
        yaw = playerStatus->targetYaw;
        x = playerStatus->pos.x;
        y = playerStatus->pos.y;
        z = playerStatus->pos.z;
        ret = player_test_move_with_slipping(playerStatus, &x, &y, &z, playerStatus->colliderDiameter * 0.5f, yaw);

        if (ret < 0 && playerStatus->curSpeed == 0.0f) {
            yaw = playerStatus->spriteFacingAngle - 90.0f + gCameras[gCurrentCameraID].curYaw;
            x = playerStatus->pos.x;
            y = playerStatus->pos.y;
            z = playerStatus->pos.z;
            ret = player_test_move_with_slipping(playerStatus, &x, &y, &z, playerStatus->colliderDiameter * 0.5f, yaw);
        }
    }

    return ret;
}

s32 phys_can_player_interact(void) {
    PartnerStatus* partnerStatus = &gPartnerStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 ret = TRUE;

    if (gPartnerStatus.partnerActionState != PARTNER_ACTION_NONE) {
        if (gPartnerStatus.actingPartner == PARTNER_BOMBETTE) {
            if (gPartnerStatus.partnerActionState <= PARTNER_ACTION_BOMBETTE_2) {
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
    f32 deltaYaw = get_clamped_angle_diff(gCameras[gCurrentCameraID].curYaw, gPlayerStatus.curYaw);

    if (deltaYaw < -5.0f && deltaYaw > -175.0f) {
        deltaYaw = 0.0f;
    } else if (deltaYaw > 5.0f && deltaYaw < 175.0f) {
        deltaYaw = 180.0f;
    } else {
        deltaYaw = PrevPlayerCamRelativeYaw;
    }
    return clamp_angle(deltaYaw - 90.0f + gCameras[gCurrentCameraID].curYaw);
}

f32 player_get_camera_facing_angle(void) {
    f32 angle = 0.0f;

    if (gPlayerStatus.spriteFacingAngle >= 90.0f && gPlayerStatus.spriteFacingAngle < 270.0f) {
        angle = 180.0f;
    }

    angle = angle + gCameras[CAM_DEFAULT].curYaw + 90.0f;

    return clamp_angle(angle);
}

void phys_save_ground_pos(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->lastGoodPos.x = playerStatus->pos.x;
    playerStatus->lastGoodPos.y = playerStatus->pos.y;
    playerStatus->lastGoodPos.z = playerStatus->pos.z;
}
