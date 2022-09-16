#include "common.h"

enum {
    SUBSTATE_SPIN           = 0,
    SUBSTATE_RISE           = 2,
    SUBSTATE_HOVER          = 3,
    SUBSTATE_DESCEND        = 4,
    SUBSTATE_IMPACT         = 5,
    SUBSTATE_HOLD           = 6,
    SUBSTATE_ABORT          = 7,
    SUBSTATE_HIT_SWITCH     = 11,
    SUBSTATE_DONE_SWITCH    = 12
};

static s32 get_collider_below_spin_jump(void);

void action_update_spin_jump(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    HiddenPanelsData* panels;
    Entity* entity;
    s32 belowColliderID;
    s32 landed;
    f32 velocity;
    u32 entityType;
    s32 surfaceType;

    static f32 RotationRate;

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PS_FLAGS_ACTION_STATE_CHANGED | PS_FLAGS_JUMPING | PS_FLAGS_FALLING);
        playerStatus->flags |= (PS_FLAGS_JUMPING | PS_FLAGS_FLYING);

        playerStatus->actionSubstate = SUBSTATE_SPIN;
        playerStatus->currentSpeed = 0.0f;
        RotationRate = 0.0f;
        playerStatus->gravityIntegrator[0] = 5.2f;
        suggest_player_anim_clearUnkFlag(ANIM_Mario_1000A);
        disable_player_input();
        playerStatus->flags |= PS_FLAGS_200;
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
        sfx_play_sound_at_player(SOUND_SPIN_JUMP, 0);
    }

    landed = FALSE;
    switch (playerStatus->actionSubstate) {
        case SUBSTATE_SPIN:
            RotationRate = 40.0f;
            playerStatus->pitch += RotationRate;
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
                    playerStatus->actionSubstate = SUBSTATE_RISE;
                    playerStatus->gravityIntegrator[0] = 2.0f;
                }
            }
            collisionStatus->currentCeiling = -1;
            break;
        case SUBSTATE_RISE:
            if (playerStatus->gravityIntegrator[0] >= 0.0f) {
                playerStatus->gravityIntegrator[0] -= 1.4;
                if (collisionStatus->currentCeiling < 0) {
                    playerStatus->position.y += playerStatus->gravityIntegrator[0];
                }
            }
            if (--playerStatus->currentStateTime <= 0) {
                playerStatus->actionSubstate++;
            }
            break;
        case SUBSTATE_HOVER:
            playerStatus->position.y = player_check_collision_below(0.0f, &belowColliderID);
            RotationRate = 45.0f;
            playerStatus->pitch += RotationRate;
            if (playerStatus->pitch >= 360.0) {
                playerStatus->pitch = 0.0f;
                playerStatus->actionSubstate++;
                playerStatus->gravityIntegrator[1] = -3.4744f;
                playerStatus->gravityIntegrator[2] = 0.4704f;
                playerStatus->gravityIntegrator[3] = -1.1904f;
                playerStatus->gravityIntegrator[0] = playerStatus->gravityIntegrator[1];
                suggest_player_anim_clearUnkFlag(ANIM_Mario_1000B);
            }
            break;
        case SUBSTATE_DESCEND:
            velocity = func_800E34D8();
            playerStatus->position.y = player_check_collision_below(velocity, &belowColliderID);
            if (velocity < -100.0f) {
                playerStatus->gravityIntegrator[3] = 0.0f;
                playerStatus->gravityIntegrator[2] = 0.0f;
                playerStatus->gravityIntegrator[1] = 0.0f;
                playerStatus->gravityIntegrator[0] = -100.0f;
            }
            if (belowColliderID >= 0) {
                if (collisionStatus->currentFloor & COLLISION_WITH_ENTITY_BIT && (entityType = get_entity_type(collisionStatus->currentFloor),
                        entityType == ENTITY_TYPE_RED_SWITCH || entityType == ENTITY_TYPE_BLUE_SWITCH)) {
                    get_entity_by_index(collisionStatus->currentFloor)->collisionFlags |= ENTITY_COLLISION_PLAYER_TOUCH_FLOOR;
                    playerStatus->actionSubstate = SUBSTATE_HIT_SWITCH;
                    playerStatus->flags &= ~PS_FLAGS_FLYING;
                    break;
                } else {
                    surfaceType = get_collider_flags(belowColliderID) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
                    if (surfaceType == SURFACE_TYPE_LAVA) {
                        playerStatus->hazardType = HAZARD_TYPE_LAVA;
                        set_action_state(ACTION_STATE_HIT_LAVA);
                        playerStatus->flags |= PS_FLAGS_800;
                        playerStatus->flags &= ~PS_FLAGS_FLYING;
                        return;
                    } else if (surfaceType == SURFACE_TYPE_SPIKES) {
                        set_action_state(ACTION_STATE_HIT_LAVA);
                        playerStatus->flags &= ~PS_FLAGS_FLYING;
                        return;
                    } else {
                        playerStatus->gravityIntegrator[1] = -3.4744f;
                        playerStatus->gravityIntegrator[2] = 0.4704f;
                        playerStatus->gravityIntegrator[3] = -1.1904f;
                        playerStatus->gravityIntegrator[0] = 10.0f;
                        suggest_player_anim_clearUnkFlag(ANIM_Mario_1000B);
                        playerStatus->actionState = ACTION_STATE_SPIN_POUND;
                        playerStatus->timeInAir = 0;
                        playerStatus->poundImpactDelay = 12;
                        playerStatus->pitch = 0.0f;
                        playerStatus->actionSubstate++;
                        exec_ShakeCam1(0, 0, 4);
                        sfx_play_sound_at_player(SOUND_149, 0);
                        start_rumble(128, 25);
                        panels = &gCurrentHiddenPanels;
                        panels->tryFlipTrigger = TRUE;
                        panels->flipTriggerPosY = playerStatus->position.y;
                        playerStatus->flags |= PS_FLAGS_400;
                    }
                }
            }
            break;
        case SUBSTATE_IMPACT:
            velocity = integrate_gravity();
            if (velocity == 0.0f) {
                landed = TRUE;
            } else {
                if (playerStatus->gravityIntegrator[0] > 0.0f) {
                    playerStatus->position.y += velocity;
                } else {
                    playerStatus->position.y = player_check_collision_below(velocity, &belowColliderID);
                    if (playerStatus->gravityIntegrator[0] < 0.0f && belowColliderID >= 0) {
                        playerStatus->actionSubstate++;
                    }
                }
                playerStatus->position.y = player_check_collision_below(0.0f, &belowColliderID);
            }
            break;
        case SUBSTATE_HOLD:
            playerStatus->position.y = player_check_collision_below(0.0f, &belowColliderID);
            if (belowColliderID >= 0) {
                playerStatus->gravityIntegrator[0] = 0.0f;
                playerStatus->gravityIntegrator[1] = 0.0f;
                playerStatus->gravityIntegrator[2] = 0.0f;
                playerStatus->gravityIntegrator[3] = 0.0f;
            }
            // fallthrough
        case SUBSTATE_ABORT:
            if (--playerStatus->poundImpactDelay <= 0) {
                landed = TRUE;
            }
            break;
        case SUBSTATE_HIT_SWITCH:
            set_action_state(ACTION_STATE_LANDING_ON_SWITCH);
            playerStatus->actionSubstate++;
            enable_player_input();
            break;
        case SUBSTATE_DONE_SWITCH:
            break;
    }

    if (landed) {
        set_action_state(ACTION_STATE_LAND);
        playerStatus->flags &= ~PA_FLAGS_8;
    }
    if (playerStatus->gravityIntegrator[0] < 0.0f) {
        belowColliderID = get_collider_below_spin_jump();
        if (belowColliderID >= 0) {
            collisionStatus->lastTouchedFloor = -1;
            collisionStatus->currentFloor = belowColliderID;
        }
    }
}

static s32 get_collider_below_spin_jump(void) {
    f32 posX, posY, posZ, height;
    f32 hitRx, hitRz, hitDirX, hitDirZ;

    posX = gPlayerStatus.position.x;
    posZ = gPlayerStatus.position.z;
    height = gPlayerStatus.colliderHeight;
    posY = gPlayerStatus.position.y + (height * 0.5f);
    return player_raycast_below_cam_relative(&gPlayerStatus, &posX, &posY, &posZ, &height, &hitRx, &hitRz, &hitDirX, &hitDirZ);
}
