#include "common.h"

static f32 SlideAcceleration;
static f32 MaxSlideAccel;
static f32 MaxSlideVelocity;
static f32 SlideLaunchSpeed;
static f32 D_802B6790;
static f32 D_802B6794;
static f32 D_802B6798;
static s32 D_802B679C;

enum {
    SUBSTATE_SLIDING     = 0,
    SUBSTATE_STOP        = 1,
    SUBSTATE_LAUNCH      = 2,
    SUBSTATE_FALL        = 3,
    SUBSTATE_CRASH       = 4,
    SUBSTATE_GET_UP      = 5,
    SUBSTATE_DUST_OFF    = 6,
    SUBSTATE_DONE        = 7,
};

void func_802B6000_E27510(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    SlideParams* slide = playerStatus->slideParams;

    playerStatus->gravityIntegrator[0] = slide->integrator[0];
    playerStatus->gravityIntegrator[1] = slide->integrator[1];
    playerStatus->gravityIntegrator[2] = slide->integrator[2];
    playerStatus->gravityIntegrator[3] = slide->integrator[3];
    playerStatus->heading = slide->heading;
    MaxSlideAccel = slide->maxDescendAccel;
    SlideLaunchSpeed = slide->launchVelocity;
    MaxSlideVelocity = slide->maxDescendVelocity;
}

void action_update_sliding(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus;
    s32 surfaceType;
    f32 sinA, cosA;
    f32 speed;
    f32 posX, posY, posZ, depth;
    f32 hitRx, hitRy, hitDirX, hitDirZ;
    s32 hitID;

    if (playerStatus->flags & PS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->actionSubstate = SUBSTATE_SLIDING;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->animFlags |= 4;
        func_802B6000_E27510();
        SlideAcceleration = 0.0f;
        D_802B6790 = 0.0f;
        D_802B6794 = 0.0f;
        D_802B6798 = 0.0f;
        D_802B679C = 0;
        suggest_player_anim_clearUnkFlag(ANIM_Mario_1000A);
        sfx_play_sound_at_player(SOUND_167, 0);
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
    }
    speed = playerStatus->currentSpeed;
    posX = playerStatus->position.x;
    posY = playerStatus->position.y;
    posZ = playerStatus->position.z;
    hitID = player_test_move_with_slipping(playerStatus, &posX, &posY, &posZ, speed, playerStatus->heading);
    playerStatus->position.x = posX;
    playerStatus->position.z = posZ;
    playerStatus->position.y = posY;

    switch (playerStatus->actionSubstate) {
        case SUBSTATE_SLIDING:
            SlideAcceleration += 0.1;
            if (MaxSlideAccel <= SlideAcceleration) {
                SlideAcceleration = MaxSlideAccel;
            }
            playerStatus->currentSpeed += SlideAcceleration;
            if (MaxSlideVelocity <= playerStatus->currentSpeed) {
                playerStatus->currentSpeed = MaxSlideVelocity;
            }
            posX = playerStatus->position.x;
            depth = 100.0f;
            posZ = playerStatus->position.z;
            D_802B6794 = D_802B6798;
            posY = playerStatus->position.y + (playerStatus->colliderHeight * 0.5f);
            hitID = player_raycast_below_cam_relative(playerStatus, &posX, &posY, &posZ, &depth, &hitRx, &hitRy, &hitDirX, &hitDirZ);
            D_802B6798 = hitRy;
            if (hitID >= 0) {
                collisionStatus = &gCollisionStatus;
                surfaceType = get_collider_flags(hitID) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
                if (surfaceType == SURFACE_TYPE_SLIDE) {
                    collisionStatus->currentFloor = hitID;
                    playerStatus->position.y = posY;
                    D_802B6790 = hitRy + 180.0f;
                    break;
                }
                if (!(fabs(D_802B6794 - D_802B6798) >= 50.0)) {
                    playerStatus->actionSubstate = SUBSTATE_STOP;
                } else {
                    playerStatus->actionSubstate = SUBSTATE_LAUNCH;
                }
            } else {
                playerStatus->actionSubstate = SUBSTATE_LAUNCH;
            }
            sin_cos_rad(DEG_TO_RAD(D_802B6790), &sinA, &cosA);
            playerStatus->position.y += fabsf((sinA / cosA) * playerStatus->currentSpeed);
            snd_stop_sound(SOUND_167);
            break;
        case SUBSTATE_STOP:
            posX = playerStatus->position.x;
            depth = 50.0f;
            posZ = playerStatus->position.z;
            posY = playerStatus->position.y + (playerStatus->colliderHeight * 0.5f);
            hitID = player_raycast_below_cam_relative(playerStatus, &posX, &posY, &posZ, &depth, &hitRx, &hitRy, &hitDirX, &hitDirZ);
            if (hitID >= 0) {
                speed = playerStatus->currentSpeed / 3.0f;
                if (speed < 0.01) {
                    playerStatus->currentSpeed = 0.0f;
                }
                playerStatus->currentSpeed -= speed;
                if (playerStatus->currentSpeed <= 0.0f) {
                    sfx_play_sound_at_player(SOUND_DUST_OFF, 0);
                    suggest_player_anim_setUnkFlag(ANIM_Mario_DustOff);
                    playerStatus->actionSubstate = SUBSTATE_DUST_OFF;
                    playerStatus->currentStateTime = 15;
                    playerStatus->currentSpeed = 0.0f;
                    playerStatus->position.y = posY;
                }
                break;
            }
        case SUBSTATE_LAUNCH:
            playerStatus->currentSpeed += SlideLaunchSpeed;
            if (playerStatus->currentSpeed <= 0.0f) {
                playerStatus->currentSpeed = 0.0f;
            }
            playerStatus->gravityIntegrator[0] += playerStatus->gravityIntegrator[1];
            playerStatus->position.y += playerStatus->gravityIntegrator[0];
            if (playerStatus->gravityIntegrator[0] <= 0.0f) {
                playerStatus->actionSubstate = SUBSTATE_FALL;
                LOAD_INTEGRATOR_FALL(playerStatus->gravityIntegrator);
            }
            break;
        case SUBSTATE_FALL:
            playerStatus->currentSpeed += SlideLaunchSpeed;
            if (playerStatus->currentSpeed <= 0.0f) {
                playerStatus->currentSpeed = 0.0f;
            }
            playerStatus->position.y = player_check_collision_below(func_800E34D8(), &hitID);
            if (hitID >= 0) {
                SlideLaunchSpeed = -1;
                suggest_player_anim_setUnkFlag(ANIM_Mario_80003);
                sfx_play_sound_at_player(SOUND_162, 0);
                playerStatus->actionSubstate++; // SUBSTATE_CRASH
            }
            break;
        case SUBSTATE_CRASH:
            playerStatus->currentSpeed += SlideLaunchSpeed;
            if (playerStatus->currentSpeed <= 0.0f) {
                playerStatus->currentSpeed = 0.0f;
            }
            if (playerStatus->animNotifyValue != 0) {
                suggest_player_anim_setUnkFlag(ANIM_Mario_GetUp);
                playerStatus->actionSubstate++; // SUBSTATE_GET_UP
            }
            break;
        case SUBSTATE_GET_UP:
            playerStatus->currentSpeed += SlideLaunchSpeed;
            if (playerStatus->currentSpeed <= 0.0f) {
                playerStatus->currentSpeed = 0.0f;
            }
            if (playerStatus->animNotifyValue != 0) {
                suggest_player_anim_setUnkFlag(ANIM_Mario_DustOff);
                sfx_play_sound_at_player(SOUND_DUST_OFF, 0);
                playerStatus->currentStateTime = 15;
                playerStatus->actionSubstate++; // SUBSTATE_DUST_OFF
            }
            break;
        case SUBSTATE_DUST_OFF:
            playerStatus->currentSpeed += SlideLaunchSpeed;
            if (playerStatus->currentSpeed <= 0.0f) {
                playerStatus->currentSpeed = 0.0f;
            }
            if (--playerStatus->currentStateTime == 0) {
                playerStatus->actionSubstate++; // SUBSTATE_DONE
            }
            break;
        case SUBSTATE_DONE:
            speed = playerStatus->currentSpeed / 3.0f;
            if (speed < 0.01) {
                playerStatus->currentSpeed = 0.0f;
            }
            playerStatus->currentSpeed -= speed;
            if (playerStatus->currentSpeed <= 0.0f) {
                playerStatus->currentSpeed = 0.0f;
                set_action_state(ACTION_STATE_IDLE);
            }
            break;
    }
}
