#include "common.h"

extern f32 D_802B6780;
extern f32 D_802B6784;
extern f32 D_802B6788;
extern f32 D_802B678C;
extern f32 D_802B6790;
extern f32 D_802B6794;
extern f32 D_802B6798;
extern s32 D_802B679C;

void func_802B6000_E27510(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32* temp_v0 = playerStatus->unk_D0;

    playerStatus->gravityIntegrator[0] = temp_v0[4];
    playerStatus->gravityIntegrator[1] = temp_v0[5];
    playerStatus->gravityIntegrator[2] = temp_v0[6];
    playerStatus->gravityIntegrator[3] = temp_v0[7];
    playerStatus->heading = *temp_v0;
    D_802B6784 = temp_v0[1];
    D_802B678C = temp_v0[2];
    D_802B6788 = temp_v0[3];
}

void action_update_sliding(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus;
    s32 surfaceType;
    f32 cosA;
    f32 sinA;
    s32 hitID;
    f32 hitDirZ;
    f32 hitDirX;
    f32 hitRy;
    f32 hitRx;
    f32 depth;
    f32 posZ;
    f32 posY;
    f32 posX;
    f32 tempCurrentSpeed;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->actionSubstate = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->animFlags |= 4;
        func_802B6000_E27510();
        D_802B6780 = 0.0f;
        D_802B6790 = 0.0f;
        D_802B6794 = 0.0f;
        D_802B6798 = 0.0f;
        D_802B679C = 0;
        suggest_player_anim_clearUnkFlag(ANIM_Mario_1000A);
        sfx_play_sound_at_player(SOUND_167, 0);
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
    }
    tempCurrentSpeed = playerStatus->currentSpeed;
    posX = playerStatus->position.x;
    posY = playerStatus->position.y;
    posZ = playerStatus->position.z;
    hitID = player_test_move_with_slipping(playerStatus, &posX, &posY, &posZ, tempCurrentSpeed, playerStatus->heading);
    playerStatus->position.x = posX;
    playerStatus->position.z = posZ;
    playerStatus->position.y = posY;

    switch (playerStatus->actionSubstate) {
        case 0:
            D_802B6780 += 0.1;
            if (D_802B6784 <= D_802B6780) {
                D_802B6780 = D_802B6784;
            }
            playerStatus->currentSpeed += D_802B6780;
            if (D_802B6788 <= playerStatus->currentSpeed) {
                playerStatus->currentSpeed = D_802B6788;
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
                    playerStatus->actionSubstate = 1;
                } else {
                    playerStatus->actionSubstate = 2;
                }
            } else {
                playerStatus->actionSubstate = 2;
            }
            sin_cos_rad((D_802B6790 * TAU) / 360.0f, &sinA, &cosA);
            playerStatus->position.y += fabsf((sinA / cosA) * playerStatus->currentSpeed);
            snd_stop_sound(SOUND_167);
            break;
        case 1:
            posX = playerStatus->position.x;
            depth = 50.0f;
            posZ = playerStatus->position.z;
            posY = playerStatus->position.y + (playerStatus->colliderHeight * 0.5f);
            hitID = player_raycast_below_cam_relative(playerStatus, &posX, &posY, &posZ, &depth, &hitRx, &hitRy, &hitDirX, &hitDirZ);
            if (hitID >= 0) {
                tempCurrentSpeed = playerStatus->currentSpeed / 3.0f;
                if (tempCurrentSpeed < 0.01) {
                    playerStatus->currentSpeed = 0.0f;
                }
                playerStatus->currentSpeed -= tempCurrentSpeed;
                if (playerStatus->currentSpeed <= 0.0f) {
                    sfx_play_sound_at_player(SOUND_172, 0);
                    suggest_player_anim_setUnkFlag(ANIM_Mario_DustOff);
                    playerStatus->actionSubstate = 6;
                    playerStatus->currentStateTime = 15;
                    playerStatus->currentSpeed = 0.0f;
                    playerStatus->position.y = posY;
                }
                break;
            }
        case 2:
            playerStatus->currentSpeed += D_802B678C;
            if (playerStatus->currentSpeed <= 0.0f) {
                playerStatus->currentSpeed = 0.0f;
            }
            playerStatus->gravityIntegrator[0] += playerStatus->gravityIntegrator[1];
            playerStatus->position.y += playerStatus->gravityIntegrator[0];
            if (playerStatus->gravityIntegrator[0] <= 0.0f) {
                playerStatus->actionSubstate = 3;
                playerStatus->gravityIntegrator[0] = 0.1143f;
                playerStatus->gravityIntegrator[1] = -0.2871f;
                playerStatus->gravityIntegrator[2] = -0.1823f;
                playerStatus->gravityIntegrator[3] = 0.01152f;
            }
            break;
        case 3:
            playerStatus->currentSpeed += D_802B678C;
            if (playerStatus->currentSpeed <= 0.0f) {
                playerStatus->currentSpeed = 0.0f;
            }
            playerStatus->position.y = player_check_collision_below(func_800E34D8(), &hitID);
            if (hitID >= 0) {
                D_802B678C = -1;
                suggest_player_anim_setUnkFlag(ANIM_Mario_80003);
                sfx_play_sound_at_player(SOUND_162, 0);
                playerStatus->actionSubstate++;
            }
            break;
        case 4:
            playerStatus->currentSpeed += D_802B678C;
            if (playerStatus->currentSpeed <= 0.0f) {
                playerStatus->currentSpeed = 0.0f;
            }
            if (playerStatus->unk_BC != 0) {
                suggest_player_anim_setUnkFlag(ANIM_Mario_GetUp);
                playerStatus->actionSubstate++;
            }
            break;
        case 5:
            playerStatus->currentSpeed += D_802B678C;
            if (playerStatus->currentSpeed <= 0.0f) {
                playerStatus->currentSpeed = 0.0f;
            }
            if (playerStatus->unk_BC != 0) {
                suggest_player_anim_setUnkFlag(ANIM_Mario_DustOff);
                sfx_play_sound_at_player(SOUND_172, 0);
                playerStatus->currentStateTime = 15;
                playerStatus->actionSubstate++;
            }
            break;
        case 6:
            playerStatus->currentSpeed += D_802B678C;
            if (playerStatus->currentSpeed <= 0.0f) {
                playerStatus->currentSpeed = 0.0f;
            }
            if (--playerStatus->currentStateTime == 0) {
                playerStatus->actionSubstate++;
            }
            break;
        case 7:
            tempCurrentSpeed = playerStatus->currentSpeed / 3.0f;
            if (tempCurrentSpeed < 0.01) {
                playerStatus->currentSpeed = 0.0f;
            }
            playerStatus->currentSpeed -= tempCurrentSpeed;
            if (playerStatus->currentSpeed <= 0.0f) {
                playerStatus->currentSpeed = 0.0f;
                set_action_state(ACTION_STATE_IDLE);
            }
            break;
    }
}
