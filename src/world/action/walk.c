#include "common.h"
#include "world/actions.h"

s32 WalkPeachAnims[] = { 
    0x000A0002,	// none
    0x000A002B,	// cream
    0x000A002D,	// strawberry
    0x000A002F,	// butter
    0x000A0031,	// cleanser
    0x000A0033,	// water
    0x000A0035,	// milk
    0x000A0037,	// flour
    0x000A0039,	// egg
    0x000A003B,	// complete cake
    0x000A003D,	// cake bowl
    0x000A003F,	// cake mixed
    0x000A0041,	// cake pan
    0x000A0043,	// cake batter
    0x000A0045,	// cake bare
    0x000A0047,	// salt
    0x000A0049,	// sugar
    0x000A004B,	// cake with icing
    0x000A004D,	// cake with berries
    0x00000000
};

void action_run_update_peach(void);

// walk
INCLUDE_ASM(void, "world/action/walk", func_802B6000_E236E0, void);

// run
void action_run_update(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    f32 moveX;
    f32 moveY;
    s32 temp_v1;
    s32 phi_a0;
    f32 phi_f2;
    s32 phi_s3;

    phi_s3 = 0;
    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS) {
        action_run_update_peach();
        return;
    }

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~0x80880000;
        D_8010C980 = 0;
        playerStatus->unk_60 = 0;
        phi_s3 = 1;

        if (!(playerStatus->flags & PLAYER_STATUS_FLAGS_4000)) {
            playerStatus->currentSpeed = playerStatus->runSpeed;
        }
        if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_8BIT_MARIO) {
            phi_a0 = 0x90003;
        } else {
            if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT)) {
                phi_a0 = 0x10005;
            } else {
                phi_a0 = 0x60002;
            }
        }
        suggest_player_anim_clearUnkFlag(phi_a0);
    }

    if (playerStatus->flags & 0x00004000) {
        playerStatus->targetYaw = playerStatus->heading;
        try_player_footstep_sounds(4);
        return;
    }

    D_8010C980++;
    phi_f2 = 1.0f;

    if (playerStatus->animFlags & 0x10000) {
        phi_f2 = 1.5f;
    }

    playerStatus->currentSpeed = playerStatus->runSpeed * phi_f2;
    player_input_to_move_vector(&moveX, &moveY);
    phys_update_interact_collider();
    if (check_input_jump() == FALSE) {
        if (phi_s3 == 0) {
            if (check_input_hammer()) {
                return;
            }
        }

        player_input_to_move_vector(&moveX, &moveY);
        if (moveY == 0.0f) {
            set_action_state(ACTION_STATE_IDLE);
            return;
        }

        if (fabsf(D_800F7B40 - moveX) <= 90.0f) {
            temp_v1 = playerStatus->animFlags;
            if (temp_v1 >= 0) {
                playerStatus->targetYaw = moveX;
            }
           playerStatus->animFlags &= ~0x80000000;
        } else {
            temp_v1 = playerStatus->animFlags;
            temp_v1 = temp_v1 < 0;
            if (temp_v1) {
                playerStatus->targetYaw = moveX;
            } else {
                playerStatus->animFlags |= 0x80000000;
            }
        }

        if (!is_ability_active(ABILITY_SLOW_GO)) {
            if (sqrtf(SQ(playerStatus->stickAxis[0]) + SQ(playerStatus->stickAxis[1])) <= 55.0f) {
                set_action_state(ACTION_STATE_WALK);
                return;
            }
        } else {
            set_action_state(ACTION_STATE_WALK);
            return;
        }
        try_player_footstep_sounds(4);
        playerData->runningStepsTaken++;
    }
}

void func_802B6550_E23C30(void) {
    if (!(gPlayerStatus.animFlags & PLAYER_STATUS_ANIM_FLAGS_IN_DISGUISE)) {
        if (!(gGameStatusPtr->peachFlags & 0x10)) {
            suggest_player_anim_clearUnkFlag(WalkPeachAnims[gGameStatusPtr->peachCookingIngredient]);
            return;
        }
        suggest_player_anim_clearUnkFlag(0xD000D);
        return;
    }
    peach_set_disguise_anim(BasicPeachDisguiseAnims[gPlayerStatus.peachDisguise].walk);
}

void func_802B65E8_E23CC8(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 magnitude;
    f32 angle;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->unk_60 = 0;
        if (!(playerStatus->flags & PLAYER_STATUS_FLAGS_4000)) {
            playerStatus->currentSpeed = playerStatus->walkSpeed;
        }
        func_802B6550_E23C30();
    }

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_4000) {
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
    if (gGameStatusPtr->peachCookingIngredient == 0 && sqrtf(SQ(playerStatus->stickAxis[0]) + SQ(playerStatus->stickAxis[1])) > 55.0f) {
        set_action_state(ACTION_STATE_RUN);
        return;
    }

    try_player_footstep_sounds(8);
}

void action_run_update_peach(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    GameStatus* gameStatus;
    f32 moveX;
    f32 moveY;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->unk_60 = 0;
        if (!(playerStatus->flags & PLAYER_STATUS_FLAGS_4000)) {
            playerStatus->currentSpeed = playerStatus->runSpeed;
        }

        if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_IN_DISGUISE)) {
            gameStatus = gGameStatusPtr;
            if (!(gameStatus->peachFlags & PEACH_STATUS_FLAG_HAS_INGREDIENT)) {
                if (!gameStatus->peachCookingIngredient) {
                    suggest_player_anim_clearUnkFlag(0xA0003);
                } else {
                    suggest_player_anim_clearUnkFlag(WalkPeachAnims[gameStatus->peachCookingIngredient]);
                }
            } else {
                suggest_player_anim_clearUnkFlag(0xD000D);
            }
        } else {
            peach_set_disguise_anim(BasicPeachDisguiseAnims[playerStatus->peachDisguise].run);
        }
    }

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_4000) {
        playerStatus->targetYaw = playerStatus->heading;
        try_player_footstep_sounds(4);
        return;
    }

    playerStatus->currentSpeed = playerStatus->runSpeed;
    player_input_to_move_vector(&moveX, &moveY);
    phys_update_interact_collider();
    if (moveY == 0.0f) {
        set_action_state(ACTION_STATE_IDLE);
        return;
    }

    playerStatus->targetYaw = moveX;
    if (sqrtf(SQ(playerStatus->stickAxis[0]) + SQ(playerStatus->stickAxis[1])) < 55.0f) {
        set_action_state(ACTION_STATE_WALK);
        return;
    } else {
        try_player_footstep_sounds(4);
    }
}
