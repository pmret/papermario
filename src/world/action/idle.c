#include "common.h"
#include "../actions.h"

s32 world_action_idle_peachAnims[] = {
    0x000A0001, // Idle

    // Cooking:
    0x000A0007, 0x000A0009, 0x000A000B, 0x000A000D, 0x000A000F, 0x000A0011, 0x000A0013,
    0x000A0015, 0x000A0017, 0x000A0019, 0x000A001B, 0x000A001D, 0x000A001F, 0x000A0021, 0x000A0023,
    0x000A0025, 0x000A0027, 0x000A0029, 0x00000000,
};

void func_802B61E4_E23444(void);

void world_action_idle_update(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    s32 wasMoving = FALSE;

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS) {
        func_802B61E4_E23444();
        return;
    }

    playerStatus->currentStateTime++;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        s32 anim;

        playerStatus->flags &= ~0x8008000E;
        wasMoving = TRUE;
        playerStatus->fallState = 0;
        playerStatus->currentStateTime = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->pitch = 0.0f;

        if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_8BIT_MARIO) {
            anim = 0x90002;
        } else if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT)) {
            anim = 0x10002;
        } else if ((s8)playerStatus->prevActionState == ACTION_STATE_IDLE) {
            anim = 0x60005;
        } else {
            anim = 0x60007;
        }
        suggest_player_anim_clearUnkFlag(anim);
    }

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_RAISED_ARMS) {
        set_action_state(ACTION_STATE_RAISE_ARMS);
    } else {
        f32 angle;
        f32 magnitude;

        player_input_to_move_vector(&angle, &magnitude);
        phys_update_interact_collider();

        if (check_input_jump()) {
            if (magnitude != 0.0f || playerStatus->targetYaw != angle) {
                playerStatus->targetYaw = angle;
            }
        } else if (wasMoving || !check_input_hammer()) {
            if (magnitude == 0.0f) {
                playerData->idleFrameCounter++;
            } else {
                playerStatus->currentStateTime = 0;
                set_action_state(ACTION_STATE_WALK);
                if (magnitude != 0.0f) {
                    playerStatus->targetYaw = angle;
                    playerStatus->animFlags &= ~0x80000000;
                }
            }
        }
    }
}

void func_802B61E4_E23444(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    f32 angle;
    f32 magnitude;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->fallState = 0;
        playerStatus->currentStateTime = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->flags &= ~0xE;

        if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_IN_DISGUISE)) {
            if (!(gGameStatusPtr->peachFlags & 0x10)) {
                suggest_player_anim_clearUnkFlag(world_action_idle_peachAnims[gGameStatusPtr->peachAnimIdx]);
            } else {
                suggest_player_anim_clearUnkFlag(0xC000E);
            }
        } else {
            peach_set_disguise_anim(world_actions_peachDisguises[gPlayerStatus.peachDisguise].idle);
        }
    }

    if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_IN_DISGUISE)) {
        switch (playerStatus->fallState) {
            case 0:
                if (((playerStatus->flags & 0x3000) == 0) && (playerStatus->unk_C4 == 0)) {
                    if (playerStatus->currentStateTime > 1800) {
                        playerStatus->fallState++;
                        suggest_player_anim_clearUnkFlag(0xC0003);
                        return;
                    }
                    playerStatus->currentStateTime++;
                }
                break;
            case 1:
                if (playerStatus->unk_BC != 0) {
                    playerStatus->fallState++;
                    playerStatus->currentStateTime = 0;
                    suggest_player_anim_clearUnkFlag(0xA0001);
                }
                break;
            case 2: {
                playerStatus->currentStateTime++;
                if (playerStatus->currentStateTime > 200) {
                    playerStatus->fallState++;
                    suggest_player_anim_clearUnkFlag(0xC0003);
                }
                break;
            }
            case 3:
                if ((playerStatus->flags & 0x3000) != 0) {
                    suggest_player_anim_clearUnkFlag(0xA0001);
                    playerStatus->fallState = 0;
                } else if (playerStatus->unk_BC != 0) {
                    suggest_player_anim_clearUnkFlag(0xC0004);
                }
                break;
        }
    }

    player_input_to_move_vector(&angle, &magnitude);
    phys_update_interact_collider();

    if (magnitude != 0.0f) {
        playerStatus->currentStateTime = 0;
        playerStatus->targetYaw = angle;
        set_action_state(ACTION_STATE_WALK);
    }
}
