#include "common.h"
#include "../actions.h"

void player_input_to_move_vector(f32* angle, f32* magnitude);
s32 check_input_jump(void);
s32 check_input_hammer(void);

void func_802B61E4_E23444(void);

NpcAnimID world_action_idle_peachAnims[] = {
    0x000A0001, // Idle

    // Cooking:
    0x000A0007, 0x000A0009, 0x000A000B, 0x000A000D, 0x000A000F, 0x000A0011, 0x000A0013,
    0x000A0015, 0x000A0017, 0x000A0019, 0x000A001B, 0x000A001D, 0x000A001F, 0x000A0021, 0x000A0023,
    0x000A0025, 0x000A0027, 0x000A0029, 0x00000000,
};

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
        NpcAnimID anim;

        playerStatus->flags &= ~0x8008000E;
        wasMoving = TRUE;
        playerStatus->fallState = 0;
        playerStatus->framesOnGround = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->unk_8C = 0.0f;

        if (playerStatus->animFlags & PLAYER_ANIM_FLAG_8BIT_MARIO) {
            anim = 0x90002;
        } else if (!(playerStatus->animFlags & PLAYER_ANIM_FLAG_HOLDING_ITEM)) {
            anim = 0x10002;
        } else if ((s8)playerStatus->prevActionState == ACTION_STATE_IDLE) {
            anim = 0x60005;
        } else {
            anim = 0x60007;
        }
        suggest_player_anim_clearUnkFlag(anim);
    }

    if (playerStatus->animFlags & PLAYER_ANIM_FLAG_GET_STAR_SPIRIT) {
        set_action_state(ACTION_STATE_GET_STAR_SPIRIT);
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

#ifndef NON_MATCHING
INCLUDE_ASM(void, "world/action/idle", func_802B61E4_E23444, void);
#else
void func_802B61E4_E23444(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;

    if (playerStatus->flags & 0x80000000) {
        playerStatus->flags &= ~0x80000000;
        playerStatus->fallState = 0;
        playerStatus->framesOnGround = 0;
        playerStatus->decorationList = 0;
        playerStatus->unk_C2 = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->flags &= ~0xE;

        if (!(playerStatus->animFlags & PLAYER_ANIM_FLAG_IN_DISGUISE)) {
            if (!(gGameStatusPtr->peachFlags & 0x10)) {
                suggest_player_anim_clearUnkFlag(world_action_idle_peachAnims[gGameStatusPtr->peachAnimIdx]);
            } else {
                suggest_player_anim_clearUnkFlag(world_actions_peachDisguises[playerStatus->peachDisguise].idle);
            }
        } else {
            suggest_player_anim_clearUnkFlag(0xC000E);
        }
    }

    if (!(playerStatus->animFlags & 0x2000)) {
        switch (playerStatus->fallState) {
            case 0:
                if (((playerStatus->flags & 0x3000) == 0) && (playerStatus->unk_C4 == 0)) {
                    if (playerStatus->framesOnGround > 1800) {
                        playerStatus->fallState++;
                        suggest_player_anim_clearUnkFlag(0xC0003);
                        return;
                    }
                    playerStatus->framesOnGround++;
                }
                break;
            case 1:
                if (playerStatus->unk_BC != 0) {
                    playerStatus->fallState++;
                    playerStatus->framesOnGround = 0;
                    suggest_player_anim_clearUnkFlag(0xA0001);
                }
                break;
            case 2: {
                playerStatus->framesOnGround++;
                if (playerStatus->framesOnGround > 200) {
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

    {
        f32 angle;
        f32 magnitude;

        player_input_to_move_vector(&angle, &magnitude);
        phys_update_interact_collider();

        if (magnitude != 0.0f) {
            playerStatus->framesOnGround = 0;
            playerStatus->targetYaw = angle;
            set_action_state(ACTION_STATE_WALK);
        }
    }
}
#endif
