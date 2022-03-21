#include "common.h"

void func_802B62CC_E24BEC(void);
void func_802B644C_E24D6C(void);

void func_802B6000_E24920(void) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* camera = &gCameras[CAM_DEFAULT];
    f32 yaw;
    f32 magnitude;
    s32 temp_v0;
    s32 phi_a0;

    if (playerStatus->animFlags & 0x1000) {
        func_802B62CC_E24BEC();
        return;
    }

    if (playerStatus->flags < 0) {
        playerStatus->flags &= ~(
            PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED | PLAYER_STATUS_FLAGS_800000 | PLAYER_STATUS_FLAGS_80000 |
            PLAYER_STATUS_FLAGS_8 | PLAYER_STATUS_FLAGS_FALLING | PLAYER_STATUS_FLAGS_JUMPING
        );
        playerStatus->fallState = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->decorationPos[0] = playerStatus->position.x;
        playerStatus->decorationPos[1] = playerStatus->position.z;

        if (playerStatus->animFlags & 0x4000) {
            phi_a0 = 0x90002;
        } else {
            if (!(playerStatus->animFlags & 1)) {
                phi_a0 = 0x10009;
            } else {
                phi_a0 = 0x6000B;
            }
        }
        suggest_player_anim_clearUnkFlag(phi_a0);

        sfx_play_sound_at_player(0x8161, 0);
        sfx_play_sound_at_player(SOUND_SOFT_LAND, 0);
        if (!(collisionStatus->currentFloor & 0x4000)) {
            phys_adjust_cam_on_landing();
        }
        collisionStatus->lastTouchedFloor = -1;
        playerStatus->animFlags &= ~0x40000;
        camera->moveFlags &= ~0x4;
    }

    playerStatus->fallState++;
    playerStatus->currentSpeed *= 0.6f;
    player_input_to_move_vector(&yaw, &magnitude);

    temp_v0 = check_input_jump();
    if (temp_v0 != 0 || temp_v0 < playerStatus->fallState) {
        if (magnitude == 0.0f) {
            set_action_state(ACTION_STATE_IDLE);
            return;
        }
        if (magnitude != 0.0f) {
            playerStatus->targetYaw = yaw;
        }
        update_locomotion_state();
    }
}

void func_802B61C0_E24AE0(void) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 yaw;
    f32 magnitude;

    if (playerStatus->animFlags & 0x1000) {
        func_802B644C_E24D6C();
        return;
    }

    if (playerStatus->flags < 0) {
        playerStatus->flags &= ~(
            PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED | PLAYER_STATUS_FLAGS_800000 | PLAYER_STATUS_FLAGS_80000 |
            PLAYER_STATUS_FLAGS_8 | PLAYER_STATUS_FLAGS_FALLING | PLAYER_STATUS_FLAGS_JUMPING
        );
        playerStatus->fallState = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->decorationPos[0] = playerStatus->position.x;
        playerStatus->decorationPos[1] = playerStatus->position.z;
        if (!(collisionStatus->currentFloor & 0x4000)) {
            phys_adjust_cam_on_landing();
        }
        collisionStatus->lastTouchedFloor = -1;
    }
    playerStatus->fallState++;
    playerStatus->currentSpeed *= 0.6f;
    player_input_to_move_vector(&yaw, &magnitude);
    check_input_jump();
    if (magnitude != 0.0f) {
        playerStatus->targetYaw = yaw;
    }
    update_locomotion_state();
}

void func_802B62CC_E24BEC(void) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 yaw;
    f32 magnitude;

    if (playerStatus->flags < 0) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->fallState = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_8 | PLAYER_STATUS_FLAGS_FALLING | PLAYER_STATUS_FLAGS_JUMPING);
        playerStatus->decorationPos[0] = playerStatus->position.x;
        playerStatus->decorationPos[1] = playerStatus->position.z;
        sfx_play_sound_at_player(SOUND_SOFT_LAND, 0);
        if (!(collisionStatus->currentFloor & 0x4000)) {
            phys_adjust_cam_on_landing();
        }
        collisionStatus->lastTouchedFloor = -1;
    }

    playerStatus->fallState++;
    playerStatus->currentSpeed *= 0.6f;
    player_input_to_move_vector(&yaw, &magnitude);

    if (magnitude == 0.0f) {
        set_action_state(ACTION_STATE_IDLE);
    } else {
        if (magnitude != 0.0f) {
            playerStatus->targetYaw = yaw;
        }

        if (sqrtf(SQ(playerStatus->stickAxis[0]) + SQ(playerStatus->stickAxis[1])) > 55.0f) {
            set_action_state(ACTION_STATE_RUN);
        } else {
            set_action_state(ACTION_STATE_WALK);
        }
    }
}

void func_802B644C_E24D6C(void) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 yaw;
    f32 magnitude;

    if (playerStatus->flags < 0) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->fallState = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_8 | PLAYER_STATUS_FLAGS_FALLING | PLAYER_STATUS_FLAGS_JUMPING);
        playerStatus->decorationPos[0] = playerStatus->position.x;
        playerStatus->decorationPos[1] = playerStatus->position.z;
        if (!(collisionStatus->currentFloor & 0x4000)) {
            phys_adjust_cam_on_landing();
        }
        collisionStatus->lastTouchedFloor = -1;
    }

    playerStatus->fallState++;
    playerStatus->currentSpeed *= 0.6f;
    player_input_to_move_vector(&yaw, &magnitude);

    if (magnitude != 0.0f) {
        playerStatus->targetYaw = yaw;
    }

    if (sqrtf(SQ(playerStatus->stickAxis[0]) + SQ(playerStatus->stickAxis[1])) > 55.0f) {
        set_action_state(ACTION_STATE_RUN);
    } else {
        set_action_state(ACTION_STATE_WALK);
    }
}
