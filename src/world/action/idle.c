#include "idle.h"

// Awkward func_800DFEFC (set player anim?) branching
#ifndef NON_MATCHING
INCLUDE_ASM(void, "world/action/idle", world_action_idle_update, void);
#else
void input_to_move_vector(f32* angle, f32* magnitude);
s32 check_input_jump(void);
s32 check_input_hammer(void);

void world_action_idle_update(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    f32 moveX;
    f32 moveZ;
    s32 phi_s1;

    if (playerStatus->animFlags & 0x1000) {
        func_802B61E4_E23444();
        return;
    }

    playerStatus->framesOnGround++;
    phi_s1 = 0;
    if (playerStatus->flags < 0) {
        playerStatus->flags &= ~0x8008000E;
        playerStatus->fallState = 0;
        phi_s1 = 1;
        playerStatus->framesOnGround = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->unk_8C = 0;

        if (playerStatus->animFlags & 0x4000) {
            func_800DFEFC(0x90002);
        } else {
            if (playerStatus->animFlags & 1) {
                if ((s8)playerStatus->prevActionState == ACTION_STATE_IDLE) {
                    func_800DFEFC(0x60007);
                } else {
                    func_800DFEFC(0x60005);

                }

            } else {
                func_800DFEFC(0x10002);
            }

        }

    }

    if (playerStatus->animFlags & 0x200) {
        set_action_state(ACTION_STATE_1C);
        return;
    }

    input_to_move_vector(&moveX, &moveZ);
    func_800E5150();
    if (check_input_jump()) {
        if (moveZ != 0.0f || playerStatus->targetYaw != moveX) {
            playerStatus->targetYaw = moveX;
            return;
        }

    } else {
        if (phi_s1 || (!check_input_hammer())) {
            if (moveZ == 0.0f) {
                playerData->idleFrameCounter++;
                return;
            }

            playerStatus->framesOnGround = 0;
            set_action_state(ACTION_STATE_WALK);
            if (moveZ) {
                playerStatus->targetYaw = moveX;
                playerStatus->animFlags &= ~0x80000000;
            }
        }
    }
}
#endif

INCLUDE_ASM(void, "world/action/idle", func_802B61E4_E23444, void);
