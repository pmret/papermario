#include "idle.h"

void input_to_move_vector(f32* angle, f32* magnitude);
s32 check_input_jump(void);
s32 check_input_hammer(void);

void world_action_idle_update(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    s32 wasMoving = FALSE;

    if (playerStatus->animFlags & PLAYER_ANIM_FLAG_PEACH_PHYSICS) {
        func_802B61E4_E23444();
        return;
    }

    playerStatus->framesOnGround++;

    if (playerStatus->flags & 0x80000000) {
        s32 anim;

        playerStatus->flags &= ~0x8008000E;
        wasMoving = TRUE;
        playerStatus->fallState = 0;
        playerStatus->framesOnGround = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->unk_8C = 0;

        if (playerStatus->animFlags & PLAYER_ANIM_FLAG_8BIT_MARIO) {
            anim = 0x90002;
        } else if (!(playerStatus->animFlags & PLAYER_ANIM_FLAG_HOLDING_ITEM)) {
            anim = 0x10002;
        } else if ((s8)playerStatus->prevActionState == ACTION_STATE_IDLE) {
            anim = 0x60005;
        } else {
            anim = 0x60007;
        }
        func_800DFEFC(anim);
    }

    if (playerStatus->animFlags & PLAYER_ANIM_FLAG_GET_STAR_SPIRIT) {
        set_action_state(ACTION_STATE_GET_STAR_SPIRIT);
    } else {
        f32 angle;
        f32 magnitude;

        input_to_move_vector(&angle, &magnitude);
        func_800E5150();

        if (check_input_jump()) {
            if (magnitude != 0.0f || playerStatus->targetYaw != angle) {
                playerStatus->targetYaw = angle;
            }
        } else if (wasMoving || !check_input_hammer()) {
            if (magnitude == 0.0f) {
                playerData->idleFrameCounter++;
            } else {
                playerStatus->framesOnGround = 0;
                set_action_state(ACTION_STATE_WALK);
                if (magnitude != 0.0f) {
                    playerStatus->targetYaw = angle;
                    playerStatus->animFlags &= ~0x80000000;
                }
            }
        }
    }
}

// peach
INCLUDE_ASM(void, "world/action/idle", func_802B61E4_E23444, void);
