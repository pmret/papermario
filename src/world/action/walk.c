#include "common.h"

// walk
INCLUDE_ASM(void, "world/action/walk", func_802B6000_E236E0, void);

// run
INCLUDE_ASM(void, "world/action/walk", func_802B6288_E23968, void);

// same as func_802B6198_E24768 but requires data stuff
INCLUDE_ASM(void, "world/action/walk", func_802B6550_E23C30, void);

void func_802B65E8_E23CC8(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 magnitude;
    f32 angle;

    if (playerStatus->flags & 0x80000000) {
        playerStatus->flags &= ~0x80000000;
        playerStatus->unk_60 = 0;
        if (!(playerStatus->flags & 0x4000)) {
            playerStatus->currentSpeed = playerStatus->walkSpeed;
        }
        func_802B6550_E23C30();
    }

    if (playerStatus->flags & 0x4000) {
        playerStatus->targetYaw = playerStatus->heading;
        try_player_footstep_sounds(8);
        return;
    }
    player_input_to_move_vector(&angle, &magnitude);
    phys_update_interact_collider();

    if (magnitude == 0.0f) {
        set_action_state(ACTION_STATE_IDLE);
        return;
    }

    playerStatus->targetYaw = angle;
    if (gGameStatusPtr->peachAnimIdx == 0 && sqrtf(SQ(playerStatus->stickAxis[0]) + SQ(playerStatus->stickAxis[1])) > 55.0f) {
        set_action_state(ACTION_STATE_RUN);
        return;
    }

    try_player_footstep_sounds(8);
}

INCLUDE_ASM(void, "world/action/walk", func_802B6738_E23E18, void);
