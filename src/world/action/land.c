#include "common.h"

void func_802B62CC_E24BEC(void);
void func_802B644C_E24D6C(void);

void func_802B6000_E24920(void) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* camera = &gCameras[CAM_DEFAULT];
    f32 inputMoveMagnitude;
    f32 inputMoveAngle;
    s32 jumpInputCheck;
    s32 phi_a0;

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS) {
        func_802B62CC_E24BEC();
        return;
    }

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(
            PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED |
            PLAYER_STATUS_FLAGS_800000 |
            PLAYER_STATUS_FLAGS_80000 |
            PLAYER_STATUS_FLAGS_FLYING |
            PLAYER_STATUS_FLAGS_FALLING |
            PLAYER_STATUS_FLAGS_JUMPING
        );
        playerStatus->fallState = 0;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->landPos.x = playerStatus->position.x;
        playerStatus->landPos.z = playerStatus->position.z;

        if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_8BIT_MARIO) {
            phi_a0 = 0x90002;
        } else if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT)) {
            phi_a0 = 0x10009;
        } else {
            phi_a0 = 0x6000B;
        }

        suggest_player_anim_clearUnkFlag(phi_a0);
        sfx_play_sound_at_player(0x8161, 0);
        sfx_play_sound_at_player(0x148, 0);

        if (!(collisionStatus->currentFloor & COLLISION_WITH_ENTITY_BIT)) {
            phys_adjust_cam_on_landing();
        }

        collisionStatus->lastTouchedFloor = -1;
        playerStatus->animFlags &= ~PLAYER_STATUS_ANIM_FLAGS_40000;
        camera->moveFlags &= ~CAMERA_MOVE_FLAGS_4;
    }
    playerStatus->fallState++;
    playerStatus->currentSpeed *= 0.6f;

    player_input_to_move_vector(&inputMoveAngle, &inputMoveMagnitude);
    jumpInputCheck = check_input_jump();

    if (jumpInputCheck != 0 || jumpInputCheck < playerStatus->fallState) {
        if (inputMoveMagnitude == 0.0f) {
            set_action_state(ACTION_STATE_IDLE);
            return;
        }
        if (inputMoveMagnitude != 0.0f) {
            playerStatus->targetYaw = inputMoveAngle;
        }
        update_locomotion_state();
    }
}

void func_802B61C0_E24AE0(void) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 inputMoveMagnitude;
    f32 inputMoveAngle;

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS) {
        func_802B644C_E24D6C();
        return;
    }

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
         playerStatus->flags &= ~(
            PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED |
            PLAYER_STATUS_FLAGS_800000 |
            PLAYER_STATUS_FLAGS_80000 |
            PLAYER_STATUS_FLAGS_FLYING |
            PLAYER_STATUS_FLAGS_FALLING |
            PLAYER_STATUS_FLAGS_JUMPING
        );
        playerStatus->fallState = 0;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->landPos.x = playerStatus->position.x;
        playerStatus->landPos.z = playerStatus->position.z;

        if (!(collisionStatus->currentFloor & COLLISION_WITH_ENTITY_BIT)) {
            phys_adjust_cam_on_landing();
        }

        collisionStatus->lastTouchedFloor = -1;
    }

    playerStatus->fallState++;
    playerStatus->currentSpeed *= 0.6f;

    player_input_to_move_vector(&inputMoveAngle, &inputMoveMagnitude);
    check_input_jump();

    if (inputMoveMagnitude != 0.0f) {
        playerStatus->targetYaw = inputMoveAngle;
    }

    update_locomotion_state();
}

void func_802B62CC_E24BEC(void) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 inputMoveMagnitude;
    f32 inputMoveAngle;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->fallState = 0;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_FLYING | PLAYER_STATUS_FLAGS_FALLING | PLAYER_STATUS_FLAGS_JUMPING);
        playerStatus->landPos.x = playerStatus->position.x;
        playerStatus->landPos.z = playerStatus->position.z;

        sfx_play_sound_at_player(SOUND_SOFT_LAND, 0);

        if (!(collisionStatus->currentFloor & COLLISION_WITH_ENTITY_BIT)) {
            phys_adjust_cam_on_landing();
        }

        collisionStatus->lastTouchedFloor = -1;
    }

    playerStatus->fallState++;
    playerStatus->currentSpeed *= 0.6f;

    player_input_to_move_vector(&inputMoveAngle, &inputMoveMagnitude);

    if (inputMoveMagnitude == 0.0f) {
        set_action_state(ACTION_STATE_IDLE);
    } else {
        if (inputMoveMagnitude != 0.0f) {
            playerStatus->targetYaw = inputMoveAngle;
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
    f32 inputMoveMagnitude;
    f32 inputMoveAngle;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->fallState = 0;
        playerStatus->timeInAir = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_FLYING | PLAYER_STATUS_FLAGS_FALLING | PLAYER_STATUS_FLAGS_JUMPING);
        playerStatus->landPos.x = playerStatus->position.x;
        playerStatus->landPos.z = playerStatus->position.z;

        if (!(collisionStatus->currentFloor & COLLISION_WITH_ENTITY_BIT)) {
            phys_adjust_cam_on_landing();
        }
        collisionStatus->lastTouchedFloor = -1;
    }

    playerStatus->fallState++;
    playerStatus->currentSpeed *= 0.6f;
    player_input_to_move_vector(&inputMoveAngle, &inputMoveMagnitude);

    if (inputMoveMagnitude != 0.0f) {
        playerStatus->targetYaw = inputMoveAngle;
    }

    if (sqrtf(SQ(playerStatus->stickAxis[0]) + SQ(playerStatus->stickAxis[1])) > 55.0f) {
        set_action_state(ACTION_STATE_RUN);
    } else {
        set_action_state(ACTION_STATE_WALK);
    }
}
