#include "common.h"
#include "sprite/player.h"

extern s32 gSpinHistoryBufferPos;
extern s32 gSpinHistoryPosY[5];
extern s16 gSpinHistoryPosAngle[5];

void phys_clear_spin_history(void);
void record_jump_apex(void);

enum {
    SUBSTATE_ASCEND         = 0,
    SUBSTATE_HOVER          = 1,
    SUBSTATE_DESCEND        = 2,
    SUBSTATE_IMPACT         = 3,
    SUBSTATE_HIT_SWITCH     = 11,
    SUBSTATE_DONE_SWITCH    = 12,
};

static s32 get_collider_below_tornado_jump(void);

void action_update_tornado_jump(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    f32 cameraRelativeYaw;
    f32 fallVelocity;
    s32 surfaceType;
    f32 spinRate;
    s32 colliderBelow;
    u32 entityType;

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
        playerStatus->flags |= (PS_FLAG_SPINNING | PS_FLAG_FLYING | PS_FLAG_JUMPING);
        phys_clear_spin_history();
        playerStatus->actionSubstate = SUBSTATE_ASCEND;
        playerStatus->curSpeed = 0.0f;
        playerStatus->gravityIntegrator[0] = 16.0f;
        playerStatus->gravityIntegrator[1] = -7.38624f;
        playerStatus->gravityIntegrator[2] = 3.44694f;
        playerStatus->gravityIntegrator[3] = -0.75f;
        suggest_player_anim_always_forward(ANIM_MarioW2_Carried);
        disable_player_input();
        playerStatus->flags |= PS_FLAG_SPECIAL_JUMP;
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_IGNORE_PLAYER_Y;
        cameraRelativeYaw = clamp_angle(playerStatus->targetYaw - gCameras[gCurrentCameraID].curYaw);
        if (cameraRelativeYaw <= 180.0f) {
            spinRate = 60.0f;
        } else {
            spinRate = -60.0f;
        }
        playerStatus->spinRate = spinRate;
    }
    if (playerStatus->actionSubstate <= SUBSTATE_IMPACT) {
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
        gSpinHistoryPosY[gSpinHistoryBufferPos] = playerStatus->pos.y;
    }

    gSpinHistoryPosAngle[gSpinHistoryBufferPos++] = playerStatus->spriteFacingAngle;

    if (gSpinHistoryBufferPos >= 6) {
        gSpinHistoryBufferPos = 0;
    }

    switch (playerStatus->actionSubstate) {
        case SUBSTATE_ASCEND:
            fallVelocity = integrate_gravity();
            playerStatus->pos.y = player_check_collision_below(fallVelocity, &colliderBelow);
            if (colliderBelow >= 0 && collisionStatus->curFloor & COLLISION_WITH_ENTITY_BIT ) {
                entityType = get_entity_type(collisionStatus->curFloor);
                if (entityType == ENTITY_TYPE_BLUE_SWITCH || entityType == ENTITY_TYPE_RED_SWITCH) {
                    get_entity_by_index(collisionStatus->curFloor)->collisionFlags |= ENTITY_COLLISION_PLAYER_TOUCH_FLOOR;
                    disable_player_input();
                    playerStatus->actionSubstate = SUBSTATE_HIT_SWITCH;
                    break;
                }
            }
            if (fallVelocity <= 0.0f) {
                record_jump_apex();
                playerStatus->curStateTime = 3;
                playerStatus->flags |= PS_FLAG_FALLING;
                playerStatus->actionSubstate++;
                sfx_play_sound_at_player(SOUND_TORNADO_JUMP, SOUND_SPACE_MODE_0);
            }
            if (colliderBelow >= 0) {
                playerStatus->flags &= ~(PS_FLAG_SPINNING | PS_FLAG_FLYING);
                set_action_state(ACTION_STATE_LAND);
            }
            break;
        case SUBSTATE_HOVER:
            if (--playerStatus->curStateTime <= 0) {
                playerStatus->actionSubstate++;
            }
            break;
        case SUBSTATE_DESCEND:
            fallVelocity = integrate_gravity();
            playerStatus->pos.y = player_check_collision_below(fallVelocity, &colliderBelow);
            if (fallVelocity < -100.0f) {
                playerStatus->gravityIntegrator[3] = 0.0f;
                playerStatus->gravityIntegrator[2] = 0.0f;
                playerStatus->gravityIntegrator[1] = 0.0f;
                playerStatus->gravityIntegrator[0] = -100.0f;
            }
            if (colliderBelow >= 0) {
                if (collisionStatus->curFloor & COLLISION_WITH_ENTITY_BIT) {
                    entityType = get_entity_type(collisionStatus->curFloor);
                    if (entityType == ENTITY_TYPE_SIMPLE_SPRING || entityType == ENTITY_TYPE_SCRIPT_SPRING) {
                        playerStatus->flags &= ~(PS_FLAG_SPINNING | PS_FLAG_FLYING);
                        set_action_state(ACTION_STATE_LAND);
                        return;
                    } else if (entityType == ENTITY_TYPE_BLUE_SWITCH || entityType == ENTITY_TYPE_RED_SWITCH) {
                        playerStatus->flags &= ~(PS_FLAG_SPINNING | PS_FLAG_FLYING);
                        phys_player_land();
                        exec_ShakeCam1(0, 0, 4);
                        sfx_play_sound_at_player(SOUND_14A, SOUND_SPACE_MODE_0);
                        start_rumble(256, 50);

                        gCurrentHiddenPanels.tryFlipTrigger = TRUE;
                        gCurrentHiddenPanels.flipTriggerPosY = playerStatus->pos.y;
                        playerStatus->flags |= PS_FLAG_SPECIAL_LAND;
                        return;
                    }
                }

                surfaceType = get_collider_flags(colliderBelow) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
                if (surfaceType == SURFACE_TYPE_LAVA) {
                    playerStatus->hazardType = HAZARD_TYPE_LAVA;
                    playerStatus->flags &= ~(PS_FLAG_SPINNING | PS_FLAG_FLYING);
                    set_action_state(ACTION_STATE_HIT_LAVA);
                    playerStatus->flags |= PS_FLAG_HIT_FIRE;
                    return;
                } else if (surfaceType == SURFACE_TYPE_SPIKES) {
                    set_action_state(ACTION_STATE_HIT_LAVA);
                    playerStatus->flags &= ~(PS_FLAG_SPINNING | PS_FLAG_FLYING);
                    return;
                }
                playerStatus->curStateTime = 8;
                playerStatus->timeInAir = 0;
                playerStatus->actionState = ACTION_STATE_TORNADO_POUND;
                playerStatus->actionSubstate++;
                exec_ShakeCam1(0, 0, 4);
                sfx_play_sound_at_player(SOUND_14A, SOUND_SPACE_MODE_0);
                start_rumble(256, 50);

                gCurrentHiddenPanels.tryFlipTrigger = TRUE;
                gCurrentHiddenPanels.flipTriggerPosY = playerStatus->pos.y;
                playerStatus->flags |= PS_FLAG_SPECIAL_LAND;
            }
            break;
        case SUBSTATE_IMPACT:
            if (--playerStatus->curStateTime == 0) {
                playerStatus->actionSubstate++;
                playerStatus->flags &= ~(PS_FLAG_SPINNING | PS_FLAG_FLYING);
                set_action_state(ACTION_STATE_LAND);
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

    if (playerStatus->gravityIntegrator[0] < 0.0f) {
        colliderBelow = get_collider_below_tornado_jump();
        if (colliderBelow >= 0) {
            collisionStatus->lastTouchedFloor = -1;
            collisionStatus->curFloor = colliderBelow;
        }
    }
}

static s32 get_collider_below_tornado_jump(void) {
    f32 posX, posY, posZ, height;
    f32 hitRx, hitRz, hitDirX, hitDirZ;

    posX = gPlayerStatus.pos.x;
    posZ = gPlayerStatus.pos.z;
    height = gPlayerStatus.colliderHeight;
    posY = gPlayerStatus.pos.y + (height * 0.5f);
    return player_raycast_below_cam_relative(&gPlayerStatus, &posX, &posY, &posZ, &height, &hitRx, &hitRz, &hitDirX, &hitDirZ);
}
