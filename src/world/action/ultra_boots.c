#include "common.h"

extern s32 gSpinHistoryBufferPos;
extern s32 gSpinHistoryPosY[5];
extern s16 gSpinHistoryPosAngle[5];

s32 func_802B65F8_E26D08(void);

void func_802B6000_E26710(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    f32 temp_f0;
    f32 temp_f20;
    u8 colliderType;
    f32 phi_f4;
    s32 sp10;
    u32 entityType;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->flags |= 0x2000A;
        phys_clear_spin_history();
        playerStatus->fallState = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->gravityIntegrator[0] = 16.0f;
        playerStatus->gravityIntegrator[1] = -7.38624f;
        playerStatus->gravityIntegrator[2] = 3.44694f;
        playerStatus->gravityIntegrator[3] = -0.75f;
        suggest_player_anim_setUnkFlag(0x80000);
        disable_player_input();
        playerStatus->flags |= 0x200;
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
        temp_f0 = clamp_angle(playerStatus->targetYaw - gCameras[gCurrentCameraID].currentYaw);
        phi_f4 = -60.0f;
        if (temp_f0 <= 180.0f) {
            phi_f4 = 60.0f;
        }
        playerStatus->spinRate = phi_f4;
    }
    if (playerStatus->fallState < 4) {
        if (playerStatus->spinRate >= 0.0f) {
            playerStatus->spriteFacingAngle += playerStatus->spinRate;
            if (playerStatus->spriteFacingAngle >= 360.0f) {
                playerStatus->spriteFacingAngle -= 360.0f;
            }
        } else {
            playerStatus->spriteFacingAngle += playerStatus->spinRate;
            if (playerStatus->spriteFacingAngle < 0.0f) {
                playerStatus->spriteFacingAngle += 360.0f;
            }
        }
    }
    if (playerStatus->gravityIntegrator[0] <= 0.0f) {
        gSpinHistoryPosY[gSpinHistoryBufferPos] = playerStatus->position.y;
    }

    gSpinHistoryPosAngle[gSpinHistoryBufferPos++] = playerStatus->spriteFacingAngle;

    if (gSpinHistoryBufferPos >= 6) {
        gSpinHistoryBufferPos = 0;
    }

    switch (playerStatus->fallState) {
        case 0:
            temp_f20 = integrate_gravity();
            playerStatus->position.y = player_check_collision_below(temp_f20, &sp10);
            if (sp10 >= 0 && collisionStatus->currentFloor & COLLISION_WITH_ENTITY_BIT ) {
                entityType = get_entity_type(collisionStatus->currentFloor);
                if (entityType == ENTITY_TYPE_BLUE_SWITCH || entityType == ENTITY_TYPE_RED_SWITCH) {
                    get_entity_by_index(collisionStatus->currentFloor)->collisionFlags |= 1;
                    disable_player_input();
                    playerStatus->fallState = 0xB;
                    break;
                }
            }
            if (temp_f20 <= 0.0f) {
                record_jump_apex();
                playerStatus->currentStateTime = 3;
                playerStatus->flags |= 4;
                playerStatus->fallState++;
                sfx_play_sound_at_player(SOUND_TORNADO_JUMP, 0);
            }
            if (sp10 >= 0) {
                playerStatus->flags &= ~0x00020008;
                set_action_state(ACTION_STATE_LAND);
            }
            break;
        case 1:
            if (--playerStatus->currentStateTime <= 0) {
                playerStatus->fallState++;
            }
            break;
        case 2:
            temp_f20 = integrate_gravity();
            playerStatus->position.y = player_check_collision_below(temp_f20, &sp10);
            if (temp_f20 < -100.0f) {
                playerStatus->gravityIntegrator[3] = 0.0f;
                playerStatus->gravityIntegrator[2] = 0.0f;
                playerStatus->gravityIntegrator[1] = 0.0f;
                playerStatus->gravityIntegrator[0] = -100.0f;
            }
            if (sp10 >= 0) {
                if (collisionStatus->currentFloor & COLLISION_WITH_ENTITY_BIT) {
                    entityType = get_entity_type(collisionStatus->currentFloor);
                    if (entityType == ENTITY_TYPE_SIMPLE_SPRING || entityType == ENTITY_TYPE_SCRIPT_SPRING) {
                        playerStatus->flags &= ~0x00020008;
                        set_action_state(ACTION_STATE_LAND);
                        return;
                    } else if (entityType == ENTITY_TYPE_BLUE_SWITCH || entityType == ENTITY_TYPE_RED_SWITCH) {
                        playerStatus->flags &= ~0x00020008;
                        phys_player_land();
                        exec_ShakeCam1(0, 0, 4);
                        sfx_play_sound_at_player(SOUND_14A, 0);
                        start_rumble(0x100, 0x32);

                        D_8015A578.unk_00 = 1;
                        D_8015A578.unk_08 = playerStatus->position.y;
                        playerStatus->flags |= 0x400;
                        return;
                    }
                }

                colliderType = get_collider_type_by_id(sp10);
                if (colliderType == 3) {
                    playerStatus->unk_BF = 1;
                    playerStatus->flags &= ~0x00020008;
                    set_action_state(ACTION_STATE_HIT_LAVA);
                    playerStatus->flags |= 0x800;
                    return;
                } else if (colliderType == 2) {
                    set_action_state(ACTION_STATE_HIT_LAVA);
                    playerStatus->flags &= ~0x00020008;
                    return;
                }
                playerStatus->currentStateTime = 8;
                playerStatus->timeInAir = 0;
                playerStatus->actionState = 0x10;
                playerStatus->fallState++;
                exec_ShakeCam1(0, 0, 4);
                sfx_play_sound_at_player(SOUND_14A, 0);
                start_rumble(0x100, 0x32);

                D_8015A578.unk_00 = 1;
                D_8015A578.unk_08 = playerStatus->position.y;
                playerStatus->flags |= 0x400;
            }
            break;
        case 3:
            if (--playerStatus->currentStateTime == 0) {
                playerStatus->fallState++;
                playerStatus->flags &= ~0x00020008;
                set_action_state(ACTION_STATE_LAND);
            }
            break;
        case 11:
            set_action_state(ACTION_STATE_LANDING_ON_SWITCH);
            playerStatus->fallState++;
            enable_player_input();
            break;
        case 12:
            break;
    }

    if (playerStatus->gravityIntegrator[0] < 0.0f) {
        sp10 = func_802B65F8_E26D08();
        if (sp10 >= 0) {
            collisionStatus->lastTouchedFloor = -1;
            collisionStatus->currentFloor = sp10;
        }
    }
}

s32 func_802B65F8_E26D08(void) {
    f32 sp28;
    f32 sp2C;
    f32 sp30;
    f32 sp34;
    f32 sp38;
    f32 sp3C;
    f32 sp40;
    f32 sp44;

    sp28 = gPlayerStatus.position.x;
    sp34 = gPlayerStatus.colliderHeight;
    sp30 = gPlayerStatus.position.z;
    sp2C = gPlayerStatus.position.y + (sp34 * 0.5f);
    return player_raycast_below_cam_relative(&gPlayerStatus, &sp28, &sp2C, &sp30, &sp34, &sp38, &sp3C, &sp40, &sp44);
}
