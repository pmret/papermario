#include "common.h"
#include "sprite/player.h"

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

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PS_FLAG_ACTION_STATE_CHANGED | PS_FLAG_JUMPING | PS_FLAG_FALLING);
        playerStatus->flags |= (PS_FLAG_JUMPING | PS_FLAG_FLYING);

        playerStatus->actionSubstate = SUBSTATE_SPIN;
        playerStatus->curSpeed = 0.0f;
        RotationRate = 0.0f;
        playerStatus->gravityIntegrator[0] = 5.2f;
        suggest_player_anim_allow_backward(ANIM_Mario1_Sit);
        disable_player_input();
        playerStatus->flags |= PS_FLAG_SPECIAL_JUMP;
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_IGNORE_PLAYER_Y;
        sfx_play_sound_at_player(SOUND_SPIN_JUMP, SOUND_SPACE_DEFAULT);
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
                if (collisionStatus->curCeiling < 0) {
                    playerStatus->pos.y += playerStatus->gravityIntegrator[0];
                } else if (collisionStatus->curCeiling & COLLISION_WITH_ENTITY_BIT) {
                    entity = get_entity_by_index(collisionStatus->curCeiling);
                    if (entity != NULL) {
                        playerStatus->pos.y = entity->pos.y - (playerStatus->colliderHeight * 0.5);
                    }
                }
            }
            if (playerStatus->pitch == 360.0f) {
                if (playerStatus->gravityIntegrator[0] <= 0.0f) {
                    playerStatus->curStateTime = 5;
                    playerStatus->actionSubstate = SUBSTATE_RISE;
                    playerStatus->gravityIntegrator[0] = 2.0f;
                }
            }
            collisionStatus->curCeiling = -1;
            break;
        case SUBSTATE_RISE:
            if (playerStatus->gravityIntegrator[0] >= 0.0f) {
                playerStatus->gravityIntegrator[0] -= 1.4;
                if (collisionStatus->curCeiling < 0) {
                    playerStatus->pos.y += playerStatus->gravityIntegrator[0];
                }
            }
            if (--playerStatus->curStateTime <= 0) {
                playerStatus->actionSubstate++;
            }
            break;
        case SUBSTATE_HOVER:
            playerStatus->pos.y = player_check_collision_below(0.0f, &belowColliderID);
            RotationRate = 45.0f;
            playerStatus->pitch += RotationRate;
            if (playerStatus->pitch >= 360.0) {
                playerStatus->pitch = 0.0f;
                playerStatus->actionSubstate++;
                playerStatus->gravityIntegrator[1] = -3.4744f;
                playerStatus->gravityIntegrator[2] = 0.4704f;
                playerStatus->gravityIntegrator[3] = -1.1904f;
                playerStatus->gravityIntegrator[0] = playerStatus->gravityIntegrator[1];
                suggest_player_anim_allow_backward(ANIM_Mario1_SpinJump);
            }
            break;
        case SUBSTATE_DESCEND:
            velocity = player_fall_distance();
            playerStatus->pos.y = player_check_collision_below(velocity, &belowColliderID);
            if (velocity < -100.0f) {
                playerStatus->gravityIntegrator[3] = 0.0f;
                playerStatus->gravityIntegrator[2] = 0.0f;
                playerStatus->gravityIntegrator[1] = 0.0f;
                playerStatus->gravityIntegrator[0] = -100.0f;
            }
            if (belowColliderID >= 0) {
                if (collisionStatus->curFloor & COLLISION_WITH_ENTITY_BIT && (entityType = get_entity_type(collisionStatus->curFloor),
                        entityType == ENTITY_TYPE_RED_SWITCH || entityType == ENTITY_TYPE_BLUE_SWITCH)) {
                    get_entity_by_index(collisionStatus->curFloor)->collisionFlags |= ENTITY_COLLISION_PLAYER_TOUCH_FLOOR;
                    playerStatus->actionSubstate = SUBSTATE_HIT_SWITCH;
                    playerStatus->flags &= ~PS_FLAG_FLYING;
                    break;
                } else {
                    surfaceType = get_collider_flags(belowColliderID) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
                    if (surfaceType == SURFACE_TYPE_LAVA) {
                        playerStatus->hazardType = HAZARD_TYPE_LAVA;
                        set_action_state(ACTION_STATE_HIT_LAVA);
                        playerStatus->flags |= PS_FLAG_HIT_FIRE;
                        playerStatus->flags &= ~PS_FLAG_FLYING;
                        return;
                    } else if (surfaceType == SURFACE_TYPE_SPIKES) {
                        set_action_state(ACTION_STATE_HIT_LAVA);
                        playerStatus->flags &= ~PS_FLAG_FLYING;
                        return;
                    } else {
                        playerStatus->gravityIntegrator[1] = -3.4744f;
                        playerStatus->gravityIntegrator[2] = 0.4704f;
                        playerStatus->gravityIntegrator[3] = -1.1904f;
                        playerStatus->gravityIntegrator[0] = 10.0f;
                        suggest_player_anim_allow_backward(ANIM_Mario1_SpinJump);
                        playerStatus->actionState = ACTION_STATE_SPIN_POUND;
                        playerStatus->timeInAir = 0;
                        playerStatus->poundImpactDelay = 12;
                        playerStatus->pitch = 0.0f;
                        playerStatus->actionSubstate++;
                        exec_ShakeCam1(0, 0, 4);
                        sfx_play_sound_at_player(SOUND_LAND_SPIN_JUMP, SOUND_SPACE_DEFAULT);
                        start_rumble(128, 25);
                        panels = &gCurrentHiddenPanels;
                        panels->tryFlipTrigger = TRUE;
                        panels->flipTriggerPosY = playerStatus->pos.y;
                        playerStatus->flags |= PS_FLAG_SPECIAL_LAND;
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
                    playerStatus->pos.y += velocity;
                } else {
                    playerStatus->pos.y = player_check_collision_below(velocity, &belowColliderID);
                    if (playerStatus->gravityIntegrator[0] < 0.0f && belowColliderID >= 0) {
                        playerStatus->actionSubstate++;
                    }
                }
                playerStatus->pos.y = player_check_collision_below(0.0f, &belowColliderID);
            }
            break;
        case SUBSTATE_HOLD:
            playerStatus->pos.y = player_check_collision_below(0.0f, &belowColliderID);
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
        playerStatus->flags &= ~PS_FLAG_FLYING;
    }
    if (playerStatus->gravityIntegrator[0] < 0.0f) {
        belowColliderID = get_collider_below_spin_jump();
        if (belowColliderID >= 0) {
            collisionStatus->lastTouchedFloor = -1;
            collisionStatus->curFloor = belowColliderID;
        }
    }
}

static s32 get_collider_below_spin_jump(void) {
    f32 posX, posY, posZ, height;
    f32 hitRx, hitRz, hitDirX, hitDirZ;

    posX = gPlayerStatus.pos.x;
    posZ = gPlayerStatus.pos.z;
    height = gPlayerStatus.colliderHeight;
    posY = gPlayerStatus.pos.y + (height * 0.5f);
    return player_raycast_below_cam_relative(&gPlayerStatus, &posX, &posY, &posZ, &height, &hitRx, &hitRz, &hitDirX, &hitDirZ);
}
