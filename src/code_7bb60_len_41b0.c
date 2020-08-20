#include "common.h"

INCLUDE_ASM("code_7bb60_len_41b0", func_800E26B0);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E26C4);

void set_action_state(s32 actionState);

void move_player(s16 duration, f32 heading, f32 speed) {
    PlayerStatus* player_status = &gPlayerStatus;

    player_status->flags = player_status->flags | 0x4000;
    player_status->heading = heading;
    player_status->moveFrames = duration;
    player_status->currentSpeed = speed;

    if (!(player_status->animFlags & 0x00400000)) {
        set_action_state(speed > player_status->walkSpeed ? ActionState_RUN : ActionState_WALK);
    }
}

INCLUDE_ASM("code_7bb60_len_41b0", func_800E27E0);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E29C8);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E2BB0);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E2D18);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E306C);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E3100);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E315C);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E3278);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E3448);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E34D8);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E3514);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E363C);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E4308);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E4404);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E4508);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E45E0);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E4744);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E4BB8);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E4F10);

INCLUDE_ASM("code_7bb60_len_41b0", check_input_midair_jump);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E5088);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E5174);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E52F8);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E5348);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E546C);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E54E0);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E5520);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E5530);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E5938);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E59A0);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E5A2C);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E5C78);

#ifdef NON_MATCHING
void set_action_state(s32 actionState) {
    PlayerStatus* player_status = &gPlayerStatus;
    PlayerData* player_data = &gPlayerData;
    UNK_TYPE* unknown_struct = &D_8010F250;

    //s32 player_status->animFlags;
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 isMovementAllowed;
    s32 temp_v0_4;
    //s32 player_status->flags;
    SoundId sound;
    u8 partner;
    u8 partnerIgnoresHazards;
    UNK_PTR** temp_v0_5;
    s32 phi_return;

    if (player_status->flags & 0x200) {
        player_status->flags &= -0x201;
        func_800E01A4();
    }

    //player_status->animFlags = player_status->animFlags;
    isMovementAllowed = actionState < ActionState_CONVERSATION;
    if (player_status->animFlags & 0x4000) {
        if (isMovementAllowed && actionState >= 0) {
            player_status->prevActionState = player_status->actionState;
            player_status->actionState = actionState;
            player_status->flags |= 0x80000000;
        }
    } else {
        //if () {
        //    goto hit_hazard;
        //}
        if (player_status->unk_BF == 3) {
            actionState = ActionState_HIT_HAZARD;
        }
        if (actionState == ActionState_HIT_HAZARD || actionState == ActionState_HIT_LAVA) {
        hit_hazard:

            partner = player_data->currentPartner;
            partnerIgnoresHazards = (partner - 7) < 2u; // Lakilester or Bow
            if (partnerIgnoresHazards || (s8)partner == PartnerId_PARAKARRY) {
                if (D_8010EBB0) {
                    player_status->animFlags |= 0x4;
                    player_status->flags |= 0x800;
                    return;
                }
                //actionState = ActionState_HIT_HAZARD; // u8
            }
        }
        if (actionState == ActionState_SLIDING) {
            player_status->moveFrames = 0;
            player_status->flags |= 0x10;
            player_status->flags &= -0x4001;
        }

        player_status->prevActionState = player_status->actionState;
        if (actionState != ActionState_USE_TWEESTER) {
            // ???
        }
        player_status->prevActionState = ActionState_IDLE;
        if (actionState == ActionState_ENEMY_FIRST_STRIKE) {
            player_status->animFlags |= 4;
        }
        player_status->actionState = actionState;
        player_status->flags |= 0x80000000;
        //phi_return = 0x1A;
        if (player_status->actionState != ActionState_SPIN) {
            player_status->flags &= 0xFFFDFFFF;
            sound = unknown_struct[0x30];
            player_status->animFlags &= 0xFFFEFFFF;
            if (sound) stop_sound(sound);

            temp_v0_5 = player_status->unk_D8;
            //phi_return = (s32) temp_v0_5;
            if (temp_v0_5) {
                temp_v0_5[0x0C][0x24] = 0xA;
                player_status->unk_D8 = NULL;
                //phi_return = 0xA;
            }
        }
    }
}
#else
void INCLUDE_ASM("code_7bb60_len_41b0", set_action_state, s32 actionState);
#endif

INCLUDE_ASM("code_7bb60_len_41b0", update_locomotion_state);

INCLUDE_ASM("code_7bb60_len_41b0", start_falling);

INCLUDE_ASM("code_7bb60_len_41b0", start_bounce_a);

INCLUDE_ASM("code_7bb60_len_41b0", start_bounce_b);

s32 check_input_hammer(void) {
    PlayerStatus* player_status = &gPlayerStatus;
    PlayerData* player_data = &gPlayerData;

    if (player_status->pressedButtons & Buttons_B) {
        if (!(player_status->flags & 4)) {
            if (D_8010EBB0 != 1 || player_data->currentPartner != PartnerId_WATT) {
                if (player_data->hammerLevel != -1) {
                    set_action_state(ActionState_HAMMER);
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

INCLUDE_ASM("code_7bb60_len_41b0", check_input_jump);

INCLUDE_ASM("code_7bb60_len_41b0", check_input_spin);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E636C);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E6428);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E6500);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E657C);
