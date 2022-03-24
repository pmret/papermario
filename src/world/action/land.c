#include "common.h"
#include "functions.h"

void func_802B62CC_E24BEC(void);
void func_802B644C_E24D6C(void);

void func_802B6000_E24920(void) {
    CollisionStatus* currentCollisionStatus = &gCollisionStatus;
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
            PLAYER_STATUS_FLAGS_KNOCKBACK |
            PLAYER_STATUS_FLAGS_FALLING | 
            PLAYER_STATUS_FLAGS_JUMPING
        );
        playerStatus->fallState = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->decorationPos[0] = playerStatus->position.x;
        playerStatus->decorationPos[1] = playerStatus->position.z;

        if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_8BIT_MARIO) {
            phi_a0 = 0x90000;
            phi_a0 |= 0x2;

        } else {
            phi_a0 = 0x6000B;
            if (!(playerStatus->animFlags & 1)) {
                phi_a0 = 0x10000;
                phi_a0 |= 0x9;
            }
        }
        
        suggest_player_anim_clearUnkFlag(phi_a0);
        sfx_play_sound_at_player(0x8161, 0);
        sfx_play_sound_at_player(0x148, 0);

        if (!(currentCollisionStatus->currentFloor & 0x4000)) {
            phys_adjust_cam_on_landing();
        }

        currentCollisionStatus->lastTouchedFloor = -1;
        playerStatus->animFlags &= ~PLAYER_STATUS_ANIM_FLAGS_40000;
        camera->moveFlags &= ~0x4;
    }
    playerStatus->fallState++;
    playerStatus->currentSpeed *= 0.6f;

    player_input_to_move_vector(&inputMoveAngle, &inputMoveMagnitude);
    jumpInputCheck = check_input_jump();

    if (jumpInputCheck != 0 || jumpInputCheck < playerStatus->fallState) {
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

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS) {
        func_802B644C_E24D6C();
        return;
    }

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
         playerStatus->flags &= ~(
            PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED | 
            PLAYER_STATUS_FLAGS_800000 | 
            PLAYER_STATUS_FLAGS_80000 | 
            PLAYER_STATUS_FLAGS_KNOCKBACK |
            PLAYER_STATUS_FLAGS_FALLING | 
            PLAYER_STATUS_FLAGS_JUMPING
        );
        playerStatus->fallState = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->decorationPos[0] = playerStatus->position.x;
        playerStatus->decorationPos[1] = playerStatus->position.z;

        if (!(currentCollisionStatus->currentFloor & 0x4000)) {
            phys_adjust_cam_on_landing();
        }

        currentCollisionStatus->lastTouchedFloor = -1;
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
    CollisionStatus* currentCollisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 inputMoveMagnitude;
    f32 inputMoveAngle;
    s32 squaredStick0;
    s32 squaredStick1;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->fallState = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_KNOCKBACK | PLAYER_STATUS_FLAGS_FALLING | PLAYER_STATUS_FLAGS_JUMPING);
        playerStatus->decorationPos[0] = playerStatus->position.x;
        playerStatus->decorationPos[1] = playerStatus->position.z;

        sfx_play_sound_at_player(0x148, 0);

        if (!(currentCollisionStatus->currentFloor & 0x4000)) {
            phys_adjust_cam_on_landing();
        }

        currentCollisionStatus->lastTouchedFloor = -1;
    }

    playerStatus->fallState++;
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
    
    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->fallState = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_KNOCKBACK | PLAYER_STATUS_FLAGS_FALLING | PLAYER_STATUS_FLAGS_JUMPING);
        playerStatus->decorationPos[0] = playerStatus->position.x;
        playerStatus->decorationPos[1] = playerStatus->position.z;

        if (!(currentCollisionStatus->currentFloor & 0x4000)) {
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
    
    if (sqrtf(squaredStick0 + squaredStick1) > 55.0f) {
        set_action_state(ACTION_STATE_RUN);
    } else {
        set_action_state(ACTION_STATE_WALK);
    }
}
