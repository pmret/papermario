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

void func_802B6060_E27570(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus;
    f32 sp50;
    f32 sp4C;
    s32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 tempCurrentSpeed;
    u8 colliderTemp;

    if (playerStatus->flags & (1 << 31)) {
        playerStatus->flags &= ~0x80000000;
        playerStatus->fallState = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->animFlags |= 4;
        func_802B6000_E27510();
        D_802B6780 = 0.0f;
        D_802B6790 = 0.0f;
        D_802B6794 = 0.0f;
        D_802B6798 = 0.0f;
        D_802B679C = 0;
        suggest_player_anim_clearUnkFlag(0x1000A);
        sfx_play_sound_at_player(SOUND_167, 0);
        gCameras[0].moveFlags |= 1;
    }
    tempCurrentSpeed = playerStatus->currentSpeed;
    sp28 = playerStatus->position.x;
    sp2C = playerStatus->position.y;
    sp30 = playerStatus->position.z;
    sp48 = player_test_move_with_slipping(playerStatus, &sp28, &sp2C, &sp30, tempCurrentSpeed, playerStatus->heading);
    playerStatus->position.x = sp28;
    playerStatus->position.z = sp30;
    playerStatus->position.y = sp2C;

    switch (playerStatus->fallState) {
        case 0:
            D_802B6780 += 0.1;
            if (D_802B6784 <= D_802B6780) {
                D_802B6780 = D_802B6784;
            }
            playerStatus->currentSpeed += D_802B6780;
            if (D_802B6788 <= playerStatus->currentSpeed) {
                playerStatus->currentSpeed = D_802B6788;
            }
            sp28 = playerStatus->position.x;
            sp34 = 100.0f;
            sp30 = playerStatus->position.z;
            D_802B6794 = D_802B6798;
            sp2C = playerStatus->position.y + (playerStatus->colliderHeight * 0.5f);
            sp48 = player_raycast_below_cam_relative(playerStatus, &sp28, &sp2C, &sp30, &sp34, &sp38, &sp3C, &sp40, &sp44);
            D_802B6798 = sp3C;
            if (sp48 >= 0) {
                collisionStatus = &gCollisionStatus;
                colliderTemp = get_collider_type_by_id(sp48);
                if (colliderTemp == 5) {
                    collisionStatus->currentFloor = sp48;
                    playerStatus->position.y = sp2C;
                    D_802B6790 = sp3C + 180.0f;
                    break;
                }
                if (!(fabs(D_802B6794 - D_802B6798) >= 50.0)) {
                    playerStatus->fallState = 1;
                } else {
                    playerStatus->fallState = 2;
                }
            } else {
                playerStatus->fallState = 2;
            }
            sin_cos_rad((D_802B6790 * TAU) / 360.0f, &sp4C, &sp50);
            playerStatus->position.y += fabsf((sp4C / sp50) * playerStatus->currentSpeed);
            snd_stop_sound(SOUND_167);
            break;
        case 1:
            sp28 = playerStatus->position.x;
            sp34 = 50.0f;
            sp30 = playerStatus->position.z;
            sp2C = playerStatus->position.y + (playerStatus->colliderHeight * 0.5f);
            sp48 = player_raycast_below_cam_relative(playerStatus, &sp28, &sp2C, &sp30, &sp34, &sp38, &sp3C, &sp40, &sp44);
            if (sp48 >= 0) {
                tempCurrentSpeed = playerStatus->currentSpeed / 3.0f;
                if (tempCurrentSpeed < 0.01) {
                    playerStatus->currentSpeed = 0.0f;
                }
                playerStatus->currentSpeed -= tempCurrentSpeed;
                if (playerStatus->currentSpeed <= 0.0f) {
                    sfx_play_sound_at_player(SOUND_172, 0);
                    suggest_player_anim_setUnkFlag(0x10031);
                    playerStatus->fallState = 6;
                    playerStatus->framesOnGround = 15;
                    playerStatus->currentSpeed = 0.0f;
                    playerStatus->position.y = sp2C;
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
                playerStatus->fallState = 3;
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
            playerStatus->position.y = player_check_collision_below(func_800E34D8(), &sp48);
            if (sp48 >= 0) {
                D_802B678C = -1;
                suggest_player_anim_setUnkFlag(0x80003);
                sfx_play_sound_at_player(SOUND_162, 0);
                playerStatus->fallState++;
            }
            break;
        case 4:
            playerStatus->currentSpeed += D_802B678C;
            if (playerStatus->currentSpeed <= 0.0f) {
                playerStatus->currentSpeed = 0.0f;
            }
            if (playerStatus->unk_BC != 0) {
                suggest_player_anim_setUnkFlag(0x10030);
                playerStatus->fallState++;
            }
            break;
        case 5:
            playerStatus->currentSpeed += D_802B678C;
            if (playerStatus->currentSpeed <= 0.0f) {
                playerStatus->currentSpeed = 0.0f;
            }
            if (playerStatus->unk_BC != 0) {
                suggest_player_anim_setUnkFlag(0x10031);
                sfx_play_sound_at_player(SOUND_172, 0);
                playerStatus->framesOnGround = 15;
                playerStatus->fallState++;
            }
            break;
        case 6:
            playerStatus->currentSpeed += D_802B678C;
            if (playerStatus->currentSpeed <= 0.0f) {
                playerStatus->currentSpeed = 0.0f;
            }
            if (--playerStatus->framesOnGround == 0) {
                playerStatus->fallState++;
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
