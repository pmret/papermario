#include "common.h"
#include "sprite/player.h"

BSS f32 SlideAcceleration;
BSS f32 MaxSlideAccel;
BSS f32 MaxSlideVelocity;
BSS f32 SlideLaunchSpeed;
BSS f32 D_802B6790;
BSS f32 D_802B6794;
BSS f32 D_802B6798;
BSS s32 D_802B679C;

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
    SlideLaunchSpeed = slide->launchVel;
    MaxSlideVelocity = slide->maxDescendVel;
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

    if (playerStatus->flags & PS_FLAG_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PS_FLAG_ACTION_STATE_CHANGED;
        playerStatus->actionSubstate = SUBSTATE_SLIDING;
        playerStatus->curSpeed = 0.0f;
        playerStatus->animFlags |= PA_FLAG_INTERRUPT_USE_PARTNER;
        func_802B6000_E27510();
        SlideAcceleration = 0.0f;
        D_802B6790 = 0.0f;
        D_802B6794 = 0.0f;
        D_802B6798 = 0.0f;
        D_802B679C = 0;
        suggest_player_anim_allow_backward(ANIM_Mario1_Sit);
        sfx_play_sound_at_player(SOUND_167, SOUND_SPACE_MODE_0);
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_IGNORE_PLAYER_Y;
    }
    speed = playerStatus->curSpeed;
    posX = playerStatus->pos.x;
    posY = playerStatus->pos.y;
    posZ = playerStatus->pos.z;
    hitID = player_test_move_with_slipping(playerStatus, &posX, &posY, &posZ, speed, playerStatus->heading);
    playerStatus->pos.x = posX;
    playerStatus->pos.z = posZ;
    playerStatus->pos.y = posY;

    switch (playerStatus->actionSubstate) {
        case SUBSTATE_SLIDING:
            SlideAcceleration += 0.1;
            if (MaxSlideAccel <= SlideAcceleration) {
                SlideAcceleration = MaxSlideAccel;
            }
            playerStatus->curSpeed += SlideAcceleration;
            if (MaxSlideVelocity <= playerStatus->curSpeed) {
                playerStatus->curSpeed = MaxSlideVelocity;
            }
            posX = playerStatus->pos.x;
            depth = 100.0f;
            posZ = playerStatus->pos.z;
            D_802B6794 = D_802B6798;
            posY = playerStatus->pos.y + (playerStatus->colliderHeight * 0.5f);
            hitID = player_raycast_below_cam_relative(playerStatus, &posX, &posY, &posZ, &depth, &hitRx, &hitRy, &hitDirX, &hitDirZ);
            D_802B6798 = hitRy;
            if (hitID >= 0) {
                collisionStatus = &gCollisionStatus;
                surfaceType = get_collider_flags(hitID) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
                if (surfaceType == SURFACE_TYPE_SLIDE) {
                    collisionStatus->curFloor = hitID;
                    playerStatus->pos.y = posY;
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
            playerStatus->pos.y += fabsf((sinA / cosA) * playerStatus->curSpeed);
            snd_stop_sound(SOUND_167);
            break;
        case SUBSTATE_STOP:
            posX = playerStatus->pos.x;
            depth = 50.0f;
            posZ = playerStatus->pos.z;
            posY = playerStatus->pos.y + (playerStatus->colliderHeight * 0.5f);
            hitID = player_raycast_below_cam_relative(playerStatus, &posX, &posY, &posZ, &depth, &hitRx, &hitRy, &hitDirX, &hitDirZ);
            if (hitID >= 0) {
                speed = playerStatus->curSpeed / 3.0f;
                if (speed < 0.01) {
                    playerStatus->curSpeed = 0.0f;
                }
                playerStatus->curSpeed -= speed;
                if (playerStatus->curSpeed <= 0.0f) {
                    sfx_play_sound_at_player(SOUND_DUST_OFF, SOUND_SPACE_MODE_0);
                    suggest_player_anim_always_forward(ANIM_Mario1_DustOff);
                    playerStatus->actionSubstate = SUBSTATE_DUST_OFF;
                    playerStatus->curStateTime = 15;
                    playerStatus->curSpeed = 0.0f;
                    playerStatus->pos.y = posY;
                }
                break;
            }
        case SUBSTATE_LAUNCH:
            playerStatus->curSpeed += SlideLaunchSpeed;
            if (playerStatus->curSpeed <= 0.0f) {
                playerStatus->curSpeed = 0.0f;
            }
            playerStatus->gravityIntegrator[0] += playerStatus->gravityIntegrator[1];
            playerStatus->pos.y += playerStatus->gravityIntegrator[0];
            if (playerStatus->gravityIntegrator[0] <= 0.0f) {
                playerStatus->actionSubstate = SUBSTATE_FALL;
                LOAD_INTEGRATOR_FALL(playerStatus->gravityIntegrator);
            }
            break;
        case SUBSTATE_FALL:
            playerStatus->curSpeed += SlideLaunchSpeed;
            if (playerStatus->curSpeed <= 0.0f) {
                playerStatus->curSpeed = 0.0f;
            }
            playerStatus->pos.y = player_check_collision_below(player_fall_distance(), &hitID);
            if (hitID >= 0) {
                SlideLaunchSpeed = -1;
                suggest_player_anim_always_forward(ANIM_MarioW2_Collapse);
                sfx_play_sound_at_player(SOUND_162, SOUND_SPACE_MODE_0);
                playerStatus->actionSubstate++; // SUBSTATE_CRASH
            }
            break;
        case SUBSTATE_CRASH:
            playerStatus->curSpeed += SlideLaunchSpeed;
            if (playerStatus->curSpeed <= 0.0f) {
                playerStatus->curSpeed = 0.0f;
            }
            if (playerStatus->animNotifyValue != 0) {
                suggest_player_anim_always_forward(ANIM_Mario1_GetUp);
                playerStatus->actionSubstate++; // SUBSTATE_GET_UP
            }
            break;
        case SUBSTATE_GET_UP:
            playerStatus->curSpeed += SlideLaunchSpeed;
            if (playerStatus->curSpeed <= 0.0f) {
                playerStatus->curSpeed = 0.0f;
            }
            if (playerStatus->animNotifyValue != 0) {
                suggest_player_anim_always_forward(ANIM_Mario1_DustOff);
                sfx_play_sound_at_player(SOUND_DUST_OFF, SOUND_SPACE_MODE_0);
                playerStatus->curStateTime = 15;
                playerStatus->actionSubstate++; // SUBSTATE_DUST_OFF
            }
            break;
        case SUBSTATE_DUST_OFF:
            playerStatus->curSpeed += SlideLaunchSpeed;
            if (playerStatus->curSpeed <= 0.0f) {
                playerStatus->curSpeed = 0.0f;
            }
            if (--playerStatus->curStateTime == 0) {
                playerStatus->actionSubstate++; // SUBSTATE_DONE
            }
            break;
        case SUBSTATE_DONE:
            speed = playerStatus->curSpeed / 3.0f;
            if (speed < 0.01) {
                playerStatus->curSpeed = 0.0f;
            }
            playerStatus->curSpeed -= speed;
            if (playerStatus->curSpeed <= 0.0f) {
                playerStatus->curSpeed = 0.0f;
                set_action_state(ACTION_STATE_IDLE);
            }
            break;
    }
}
