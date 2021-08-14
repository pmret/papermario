#include "common.h"
#include "world/actions.h"

s32 D_802B6910_E23FF0[] = {0x000A0002, 0x000A002B, 0x000A002D, 0x000A002F, 0x000A0031, 0x000A0033, 0x000A0035, 0x000A0037, 0x000A0039, 0x000A003B, 0x000A003D, 0x000A003F,
                           0x000A0041, 0x000A0043, 0x000A0045, 0x000A0047, 0x000A0049, 0x000A004B, 0x000A004D, 0x00000000 };

// walk
INCLUDE_ASM(void, "world/action/walk", func_802B6000_E236E0, void);

// run
void func_802B6288_E23968() {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    f32 sp14;
    f32 sp10;
    s32 temp_v1;
    s32 phi_a0;
    f32 phi_f2;
    s32 phi_s3;
    s32 xAxis;
    s32 yAxis;

    phi_s3 = 0;
    if (playerStatus->animFlags & PLAYER_ANIM_FLAG_PEACH_PHYSICS) {
        func_802B6738_E23E18();
        return;
    }

    if (playerStatus->flags < 0) {
        playerStatus->flags &= ~0x80880000;
        D_8010C980 = 0;
        playerStatus->unk_60 = 0;
        phi_s3 = 1;

        if (!(playerStatus->flags & 0x00004000)) {
            playerStatus->currentSpeed = playerStatus->runSpeed;
        }
        if (playerStatus->animFlags & PLAYER_ANIM_FLAG_8BIT_MARIO) {
            phi_a0 = 0x90003;
        } else {
            if (!(playerStatus->animFlags & PLAYER_ANIM_FLAG_HOLDING_ITEM)) {
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
    player_input_to_move_vector(&sp10, &sp14);
    phys_update_interact_collider();
    if (check_input_jump() == FALSE) {
        if (phi_s3 == 0) {
            if (check_input_hammer()) {
                return;
            }
        }

        player_input_to_move_vector(&sp10, &sp14);
        if (sp14 == 0.0f) {
            set_action_state(ACTION_STATE_IDLE);
            return;
        }

        if (fabsf(D_800F7B40 - sp10) <= 90.0f) {
            temp_v1 = playerStatus->animFlags;
            if (temp_v1 >= 0) {
                playerStatus->targetYaw = sp10;
            }
           playerStatus->animFlags &= ~0x80000000;
        } else {
            temp_v1 = playerStatus->animFlags;
            if (temp_v1 < 0) {
                playerStatus->targetYaw = sp10;
            } else {
                xAxis = 0x80000000;
                playerStatus->animFlags |= xAxis;
            }

        }

        if (!is_ability_active(0xB)) {
            xAxis = playerStatus->stickAxis[0] * playerStatus->stickAxis[0];
            yAxis = playerStatus->stickAxis[1] * playerStatus->stickAxis[1];
            if (55.0f >= sqrtf(xAxis + yAxis)) {
                set_action_state(ACTION_STATE_WALK);
                return;
            }
        } else {
            set_action_state(ACTION_STATE_WALK);
            return;
        }
        try_player_footstep_sounds(4);
        playerData->unk_2B0++;
    }
}

void func_802B6550_E23C30(void) {
    if (!(gPlayerStatus.animFlags & PLAYER_ANIM_FLAG_IN_DISGUISE)) {
        if (!(gGameStatusPtr->peachFlags & 0x10)) {
            suggest_player_anim_clearUnkFlag(D_802B6910_E23FF0[gGameStatusPtr->peachAnimIdx]);
            return;
        }
        suggest_player_anim_clearUnkFlag(0xD000D);
        return;
    }
    peach_set_disguise_anim(world_actions_peachDisguises[gPlayerStatus.peachDisguise].unk_04);
}

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

void func_802B6738_E23E18(void)
{
    PlayerStatus* playerStatus = &gPlayerStatus;
    GameStatus* gameStatus;
    f32 sp14;
    f32 sp10;

    if (playerStatus->flags < 0) {
        playerStatus->flags &= ~0x80000000;
        playerStatus->unk_60 = 0;
        if (!(playerStatus->flags & 0x00004000)) {
            playerStatus->currentSpeed = playerStatus->runSpeed;
        }

        if (!(playerStatus->animFlags & PLAYER_ANIM_FLAG_IN_DISGUISE))
        {
            gameStatus = gGameStatusPtr;
            if (!(gameStatus->peachFlags & 0x10)) {
                if (!gameStatus->peachAnimIdx) {
                    suggest_player_anim_clearUnkFlag(0xA0003);
                } else {
                    suggest_player_anim_clearUnkFlag(D_802B6910_E23FF0[gameStatus->peachAnimIdx]);
                }
            } else {
                suggest_player_anim_clearUnkFlag(0xD000D);
            }

        } else {
          peach_set_disguise_anim(world_actions_peachDisguises[playerStatus->peachDisguise].unk_08);
        }
    }

    if (playerStatus->flags & 0x00004000) {
        playerStatus->targetYaw = playerStatus->heading;
        try_player_footstep_sounds(4);
        return;
    }

    playerStatus->currentSpeed = playerStatus->runSpeed;
    player_input_to_move_vector(&sp10, &sp14);
    phys_update_interact_collider();
    if (sp14 == 0.0f) {
        set_action_state(ACTION_STATE_IDLE);
        return;
    }

    playerStatus->targetYaw = sp10;

    if (sqrtf(playerStatus->stickAxis[0] * playerStatus->stickAxis[0] +
              playerStatus->stickAxis[1] * playerStatus->stickAxis[1]) < 55.0f) {
        set_action_state(ACTION_STATE_WALK);
        return;
    } else {
        try_player_footstep_sounds(4);
    }
}
