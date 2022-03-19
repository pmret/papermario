#include "common.h"
#include "functions.h"

void func_802B6000_E24920(void) {
    f32 inputMoveMagnitude;
    f32 inputMoveAngle;
    s32 jumpInputCheck;
    s32 phi_a0;
    CollisionStatus* currentCollisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* currentCameras = &gCameras;
    
    if ((playerStatus->animFlags & 0x1000) != 0) {
        func_802B62CC_E24BEC();
        return;
    }

    if (playerStatus->flags < 0) {
        playerStatus->flags = playerStatus->flags & 0x7F77FFF1;
        playerStatus->fallState = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->decorationPos[0] = playerStatus->position.x;
        playerStatus->decorationPos[1] = playerStatus->position.z;

        if ((playerStatus->animFlags & 0x4000) != 0) {
            phi_a0 = 0x9 << 16;
            phi_a0 |= 0x2;

        } else {
            phi_a0 = 0x6000B;
            if ((playerStatus->animFlags & 1) == 0) {
                phi_a0 = 0x1 << 16;
                phi_a0 |= 0x9;
            }
        }
        
        suggest_player_anim_clearUnkFlag(phi_a0);
        sfx_play_sound_at_player(0x8161, 0);
        sfx_play_sound_at_player(0x148, 0);

        if (((u16) currentCollisionStatus->currentFloor & 0x4000) == 0) {
            phys_adjust_cam_on_landing();
        }

        currentCollisionStatus->lastTouchedFloor = -1;
        playerStatus->animFlags &= 0xFFFB0000 | 0xFFFF;
        currentCameras->moveFlags = (u16) currentCameras->moveFlags & 0xFFFB;
    }
    playerStatus->fallState = (u8) playerStatus->fallState + 1;
    playerStatus->currentSpeed *= 0.6f;

    player_input_to_move_vector(&inputMoveAngle, &inputMoveMagnitude);
    jumpInputCheck = check_input_jump();
    
    if ((jumpInputCheck != 0) || (jumpInputCheck < (s32) playerStatus->fallState)) {
        if (inputMoveMagnitude == 0.0f) {
            set_action_state(0);
            return;
        }
        if (inputMoveMagnitude != 0.0f) {
            playerStatus->targetYaw = inputMoveAngle;
        }
        update_locomotion_state();
    }
}

void func_802B61C0_E24AE0(void) {
    CollisionStatus* currentCollisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 inputMoveMagnitude;
    f32 inputMoveAngle;

    if ((playerStatus->animFlags & 0x1000) != 0) {
        func_802B644C_E24D6C();
        return;
    }

    if (playerStatus->flags < 0) {
        playerStatus->flags = playerStatus->flags & 0x7F77FFF1;
        playerStatus->fallState = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->decorationPos[0] = playerStatus->position.x;
        playerStatus->decorationPos[1] = playerStatus->position.z;

        if ((currentCollisionStatus->currentFloor & 0x4000) == 0) {
            phys_adjust_cam_on_landing();
        }

        currentCollisionStatus->lastTouchedFloor = -1;
    }

    playerStatus->fallState = (u8) playerStatus->fallState + 1;
    playerStatus->currentSpeed *= 0.6f;

    player_input_to_move_vector(&inputMoveAngle, &inputMoveMagnitude);
    check_input_jump();

    if (inputMoveMagnitude != 0.0f) {
        playerStatus->targetYaw = inputMoveAngle;
    }
    
    update_locomotion_state();
}

void func_802B62CC_E24BEC(void) {
    CollisionStatus* currentCollisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 inputMoveMagnitude;
    f32 inputMoveAngle;
    s32 playerFlagsModified;
    s32 squaredStick0;
    s32 squaredStick1;

    if (playerStatus->flags < 0) {
        playerFlagsModified = playerStatus->flags & 0x7FFFFFFF;
        playerStatus->flags = playerFlagsModified;
        playerStatus->fallState = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->flags = playerFlagsModified & ~0xE;
        playerStatus->decorationPos[0] = playerStatus->position.x;
        playerStatus->decorationPos[1] = playerStatus->position.z;

        sfx_play_sound_at_player(0x148, 0);

        if (((u16) currentCollisionStatus->currentFloor & 0x4000) == 0) {
            phys_adjust_cam_on_landing();
        }

        currentCollisionStatus->lastTouchedFloor = -1;
    }

    playerStatus->fallState = (u8) playerStatus->fallState + 1;
    playerStatus->currentSpeed *= 0.6f;

    player_input_to_move_vector(&inputMoveAngle, &inputMoveMagnitude);

    if (inputMoveMagnitude != 0.0f) {
        
        if (inputMoveMagnitude != 0.0f) {
            playerStatus->targetYaw = inputMoveAngle;
        }

        squaredStick0 = SQ(playerStatus->stickAxis[0]);
        squaredStick1 = SQ(playerStatus->stickAxis[1]);

        if (!(sqrtf(squaredStick0 + squaredStick1) > 55.0f)) {
            set_action_state(ACTION_STATE_WALK);
            return;
        }

        set_action_state(ACTION_STATE_RUN);
    } else {
        set_action_state(ACTION_STATE_IDLE);
    }
}

void func_802B644C_E24D6C(void) {
    CollisionStatus* currentCollisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 inputMoveMagnitude;
    f32 inputMoveAngle;
    s32 squaredStick0;
    s32 squaredStick1;
    s32 playerFlagsModified;
    
    if (playerStatus->flags < 0) {
        playerFlagsModified = playerStatus->flags & 0x7FFFFFFF;
        playerStatus->flags = playerFlagsModified;
        playerStatus->fallState = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->flags = playerFlagsModified & ~0xE;
        playerStatus->decorationPos[0] = playerStatus->position.x;
        playerStatus->decorationPos[1] = playerStatus->position.z;

        if (( currentCollisionStatus->currentFloor & 0x4000) == 0) {
            phys_adjust_cam_on_landing();
        }

        currentCollisionStatus->lastTouchedFloor = -1;
    }

    playerStatus->fallState = playerStatus->fallState + 1;
    playerStatus->currentSpeed *= 0.6f;

    player_input_to_move_vector(&inputMoveAngle, &inputMoveMagnitude);

    if (inputMoveMagnitude != 0.0f) {
        playerStatus->targetYaw = inputMoveAngle;
    }

    squaredStick0 = playerStatus->stickAxis[0] * playerStatus->stickAxis[0];
    squaredStick1 = playerStatus->stickAxis[1] * playerStatus->stickAxis[1];
    
    if ((sqrtf(squaredStick0 + squaredStick1) > 55.0f)) {
        set_action_state(ACTION_STATE_RUN);
    } else {
        set_action_state(ACTION_STATE_WALK);
    }
}
