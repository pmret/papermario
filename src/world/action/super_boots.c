#include "common.h"

extern f32 D_802B6730;

s32 func_802B6648_E27428(void);

void func_802B6000_E26DE0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    Entity* entity;
    HiddenPanelsData* panels;
    s32 belowColliderID;
    s32 tempCondition;
    f32 temp_f20;
    u32 entityType;
    s32 surfaceType;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED | PLAYER_STATUS_FLAGS_JUMPING | PLAYER_STATUS_FLAGS_FALLING);
        playerStatus->flags |= (PLAYER_STATUS_FLAGS_JUMPING | PLAYER_STATUS_FLAGS_FLYING);

        playerStatus->fallState = 0;
        playerStatus->currentSpeed = 0.0f;
        D_802B6730 = 0.0f;
        playerStatus->gravityIntegrator[0] = 5.2f;
        suggest_player_anim_clearUnkFlag(ANIM_Mario_1000A);
        disable_player_input();
        playerStatus->flags |= PLAYER_STATUS_FLAGS_200;
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
        sfx_play_sound_at_player(SOUND_SPIN_JUMP, 0);
    }

    tempCondition = 0;
    switch (playerStatus->fallState) {
        case 0:
            D_802B6730 = 40.0f;
            playerStatus->pitch += 40.0f;
            if (playerStatus->pitch >= 360.0f) {
                playerStatus->pitch = 360.0f;
            }
            if (playerStatus->gravityIntegrator[0] >= 0.0f) {
                playerStatus->gravityIntegrator[0] -= 0.54;
                if (collisionStatus->currentCeiling < 0) {
                    playerStatus->position.y += playerStatus->gravityIntegrator[0];
                } else if (collisionStatus->currentCeiling & COLLISION_WITH_ENTITY_BIT) {
                    entity = get_entity_by_index(collisionStatus->currentCeiling);
                    if (entity != NULL) {
                        playerStatus->position.y = entity->position.y - (playerStatus->colliderHeight * 0.5);
                    }
                }
            }
            if (playerStatus->pitch == 360.0f) {
                if (playerStatus->gravityIntegrator[0] <= 0.0f) {
                    playerStatus->currentStateTime = 5;
                    playerStatus->fallState = 2;
                    playerStatus->gravityIntegrator[0] = 2.0f;
                }
            }
            collisionStatus->currentCeiling = -1;
            break;
        case 2:
            if (playerStatus->gravityIntegrator[0] >= 0.0f) {
                playerStatus->gravityIntegrator[0] -= 1.4;
                if (collisionStatus->currentCeiling < 0) {
                    playerStatus->position.y += playerStatus->gravityIntegrator[0];
                }
            }
            if (--playerStatus->currentStateTime <= 0) {
                playerStatus->fallState++;
            }
            break;
        case 3:
            playerStatus->position.y = player_check_collision_below(0.0f, &belowColliderID);
            D_802B6730 = 45.0f;
            playerStatus->pitch += 45.0f;
            if (playerStatus->pitch >= 360.0) {
                playerStatus->pitch = 0.0f;
                playerStatus->fallState++;
                playerStatus->gravityIntegrator[1] = -3.4744f;
                playerStatus->gravityIntegrator[2] = 0.4704f;
                playerStatus->gravityIntegrator[3] = -1.1904f;
                playerStatus->gravityIntegrator[0] = playerStatus->gravityIntegrator[1];
                suggest_player_anim_clearUnkFlag(ANIM_Mario_1000B);
            }
            break;
        case 4:
            temp_f20 = func_800E34D8();
            playerStatus->position.y = player_check_collision_below(temp_f20, &belowColliderID);
            if (temp_f20 < -100.0f) {
                playerStatus->gravityIntegrator[3] = 0.0f;
                playerStatus->gravityIntegrator[2] = 0.0f;
                playerStatus->gravityIntegrator[1] = 0.0f;
                playerStatus->gravityIntegrator[0] = -100.0f;
            }
            if (belowColliderID >= 0) {
                if (collisionStatus->currentFloor & COLLISION_WITH_ENTITY_BIT && (entityType = get_entity_type(collisionStatus->currentFloor),
                        entityType == ENTITY_TYPE_RED_SWITCH || entityType == ENTITY_TYPE_BLUE_SWITCH)) {
                    get_entity_by_index(collisionStatus->currentFloor)->collisionFlags |= ENTITY_COLLISION_PLAYER_TOUCH_FLOOR;
                    playerStatus->fallState = 0xB;
                    playerStatus->flags &= ~PLAYER_STATUS_FLAGS_FLYING;
                    break;
                } else {
                    surfaceType = get_collider_flags(belowColliderID) & 0xFF;
                    if (surfaceType == SURFACE_TYPE_LAVA) {
                        playerStatus->unk_BF = 1;
                        set_action_state(ACTION_STATE_HIT_LAVA);
                        playerStatus->flags |= PLAYER_STATUS_FLAGS_800;
                        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_FLYING;
                        return;
                    } else if (surfaceType == SURFACE_TYPE_SPIKES) {
                        set_action_state(ACTION_STATE_HIT_LAVA);
                        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_FLYING;
                        return;
                    } else {
                        playerStatus->gravityIntegrator[1] = -3.4744f;
                        playerStatus->gravityIntegrator[2] = 0.4704f;
                        playerStatus->gravityIntegrator[3] = -1.1904f;
                        playerStatus->gravityIntegrator[0] = 10.0f;
                        suggest_player_anim_clearUnkFlag(ANIM_Mario_1000B);
                        playerStatus->actionState = ACTION_STATE_GROUND_POUND;
                        playerStatus->timeInAir = 0;
                        playerStatus->unk_280 = 0xC;
                        playerStatus->pitch = 0.0f;
                        playerStatus->fallState++;
                        exec_ShakeCam1(0, 0, 4);
                        sfx_play_sound_at_player(SOUND_149, 0);
                        start_rumble(0x80, 0x19);
                        panels = &gCurrentHiddenPanels;
                        panels->tryFlipTrigger = TRUE;
                        panels->flipTriggerPosY = playerStatus->position.y;
                        playerStatus->flags |= PLAYER_STATUS_FLAGS_400;
                    }
                }
            }
            break;
        case 5:
            temp_f20 = integrate_gravity();
            if (temp_f20 == 0.0f) {
                tempCondition = 1;
            } else {
                if (playerStatus->gravityIntegrator[0] > 0.0f) {
                    playerStatus->position.y += temp_f20;
                } else {
                    playerStatus->position.y = player_check_collision_below(temp_f20, &belowColliderID);
                    if (playerStatus->gravityIntegrator[0] < 0.0f && belowColliderID >= 0) {
                        playerStatus->fallState++;
                    }
                }
                playerStatus->position.y = player_check_collision_below(0.0f, &belowColliderID);
            }
            break;
        case 6:
            playerStatus->position.y = player_check_collision_below(0.0f, &belowColliderID);
            if (belowColliderID >= 0) {
                playerStatus->gravityIntegrator[0] = 0.0f;
                playerStatus->gravityIntegrator[1] = 0.0f;
                playerStatus->gravityIntegrator[2] = 0.0f;
                playerStatus->gravityIntegrator[3] = 0.0f;
            }
        case 7:
            if (--playerStatus->unk_280 <= 0) {
                tempCondition = 1;
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

    if (tempCondition != 0) {
        set_action_state(ACTION_STATE_LAND);
        playerStatus->flags &= ~0x8;
    }
    if (playerStatus->gravityIntegrator[0] < 0.0f) {
        belowColliderID = func_802B6648_E27428();
        if (belowColliderID >= 0) {
            collisionStatus->lastTouchedFloor = -1;
            collisionStatus->currentFloor = belowColliderID;
        }
    }
}

s32 func_802B6648_E27428(void) {
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
