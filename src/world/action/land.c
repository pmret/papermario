#include "common.h"
#include "functions.h"

void func_802B6000_E24920(void) {
    f32 sp14;
    f32 sp10;
    s32 temp_v0;
    s32 temp_v1;
    s32 phi_a0;
    u32 temp_a1;
    CollisionStatus* currentCollisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* currentCameras = &gCameras;
    
    temp_a1 = playerStatus->animFlags;
    if ((temp_a1 & 0x1000) != 0) {
        func_802B62CC_E24BEC();
        return;
    }
    temp_v1 = playerStatus->flags;
    if (temp_v1 < 0) {
        playerStatus->flags = temp_v1 & 0x7F77FFF1;
        playerStatus->fallState = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->decorationPos[0] = playerStatus->position.x;
        playerStatus->decorationPos[1] = playerStatus->position.z;
        if ((temp_a1 & 0x4000) != 0) {
            phi_a0 = 0x9 << 16;
            phi_a0 |= 0x2;

        } else {
            phi_a0 = 0x6000B;
            if ((temp_a1 & 1) == 0) {
                
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
    player_input_to_move_vector(&sp10, &sp14);
    temp_v0 = check_input_jump();
    if ((temp_v0 != 0) || (temp_v0 < (s32) playerStatus->fallState)) {
        if (sp14 == 0.0f) {
            set_action_state(0);
            return;
        }
        if (sp14 != 0.0f) {
            playerStatus->targetYaw = sp10;
        }
        update_locomotion_state();
    }
}

void func_802B61C0_E24AE0(void) {
    f32 sp14;
    f32 sp10;
    s32 temp_a0;
    CollisionStatus* currentCollisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;

    if ((playerStatus->animFlags & 0x1000) != 0) {
        func_802B644C_E24D6C();
        return;
    }
    temp_a0 = playerStatus->flags;
    if (temp_a0 < 0) {
        playerStatus->flags = temp_a0 & 0x7F77FFF1;
        playerStatus->fallState = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->decorationPos[0] = playerStatus->position.x;
        playerStatus->decorationPos[1] = playerStatus->position.z;
        if (((u16) currentCollisionStatus->currentFloor & 0x4000) == 0) {
            phys_adjust_cam_on_landing();
        }
        currentCollisionStatus->lastTouchedFloor = -1;
    }
    playerStatus->fallState = (u8) playerStatus->fallState + 1;
    playerStatus->currentSpeed *= 0.6f;
    player_input_to_move_vector(&sp10, &sp14);
    check_input_jump();
    if (sp14 != 0.0f) {
        playerStatus->targetYaw = sp10;
    }
    update_locomotion_state();
}

void func_802B62CC_E24BEC(void) {
    CollisionStatus* currentCollisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sp14;
    f32 sp10;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 phi_a0;
    f32 argVal;
    s32 temp2;

    if (playerStatus->flags < 0) {
        temp_v0 = playerStatus->flags & 0x7FFFFFFF;
        playerStatus->flags = temp_v0;
        playerStatus->fallState = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->flags = temp_v0 & ~0xE;
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
    player_input_to_move_vector(&sp10, &sp14);
    if (sp14 != 0.0f) {
        
        if (sp14 != 0.0f) {
            playerStatus->targetYaw = sp10;
        }

        temp_v0_2 = SQ(playerStatus->stickAxis[0]);

        temp_v0_3 = SQ(playerStatus->stickAxis[1]);

        if (!(sqrtf(temp_v0_2 + temp_v0_3) > 55.0f)) {
            set_action_state(ACTION_STATE_WALK);
            return;
        }
        set_action_state(ACTION_STATE_RUN);
    }
    else
    {
        set_action_state(ACTION_STATE_IDLE);
    }
}

void func_802B644C_E24D6C(void) {
    CollisionStatus* currentCollisionStatus = &gCollisionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sp14;
    f32 sp10;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    

    temp_v0 = playerStatus->flags;
    if (temp_v0 < 0) {
        temp_v1 = temp_v0 & 0x7FFFFFFF;
        playerStatus->flags = temp_v1;
        playerStatus->fallState = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->flags = temp_v1 & ~0xE;
        playerStatus->decorationPos[0] = playerStatus->position.x;
        playerStatus->decorationPos[1] = playerStatus->position.z;
        if (( currentCollisionStatus->currentFloor & 0x4000) == 0) {
            phys_adjust_cam_on_landing();
        }
        currentCollisionStatus->lastTouchedFloor = -1;
    }
    playerStatus->fallState = playerStatus->fallState + 1;
    playerStatus->currentSpeed *= 0.6f;
    player_input_to_move_vector(&sp10, &sp14);
    if (sp14 != 0.0f) {
        playerStatus->targetYaw = sp10;
    }
    temp_v0_2 = playerStatus->stickAxis[0] * playerStatus->stickAxis[0];
    temp_v0_3 = playerStatus->stickAxis[1] * playerStatus->stickAxis[1];
    
    if ((sqrtf(temp_v0_2 + temp_v0_3) > 55.0f)) {
        set_action_state(ACTION_STATE_RUN);
    }
    else
    {
        set_action_state(ACTION_STATE_WALK);
    }
}
