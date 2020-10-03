#include "common.h"

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E26B0);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E26C4);

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

INCLUDE_ASM(s32, "code_7bb60_len_41b0", collision_main_above);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E29C8);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E2BB0);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", update_fall_state);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E2F60);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", gravity_use_fall_parms);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E3100);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E315C);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", phys_player_land);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", integrate_gravity);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E34D8);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E3514);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", collision_main_lateral);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", collision_check_player_intersecting_world);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E4404);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E4508);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E45E0);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E46C8);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E4744);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E4AD8);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E4B40);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E4BB8);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E4F10);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", check_input_midair_jump);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", get_current_partner_id);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5098);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5150);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5174);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E52F8);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5348);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E546C);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", save_ground_pos);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5520);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5530);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E58F0);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5938);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E59A0);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5A2C);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E5C78);

void set_action_state(s32 actionState) {
    PlayerStatus* player_status = &gPlayerStatus;
    PlayerData* player_data = &gPlayerData;
    UNK_TYPE* unknown_struct = &D_8010F250;

    if (player_status->flags & 0x200) {
        player_status->flags &= ~0x200;
        enable_player_input();
    }

    if (player_status->animFlags & 0x4000) {
        if (actionState < ActionState_CONVERSATION) {
            if (actionState >= 0) {
                player_status->prevActionState = player_status->actionState;
                player_status->actionState = actionState;
                player_status->flags |= 0x80000000;
            }
        }
        return;
    }

    if (actionState == ActionState_HIT_HAZARD || actionState == ActionState_HIT_LAVA) {
        u8 partner;

        if (player_status->unk_BF == 3) {
            actionState = ActionState_HIT_HAZARD;
        }

        // Whilst Lakilester, Bow, or Parakarry's ability is active, hazards have no effect.
        partner = player_data->currentPartner;
        if ((partner - 7) < 2u || (s8)partner == PartnerId_PARAKARRY) {
            if (D_8010EBB0) {
                player_status->animFlags |= 0x4;
                player_status->flags |= 0x800;
                return;
            }
        }
    }

    if (actionState == ActionState_SLIDING) {
        player_status->flags |= 0x10;
        player_status->moveFrames = 0;
        player_status->flags &= ~0x4000;
    }

    player_status->prevActionState = player_status->actionState;
    if (actionState == ActionState_USE_TWEESTER) {
        player_status->prevActionState = ActionState_IDLE;
    }

    if (actionState == ActionState_ENEMY_FIRST_STRIKE) {
        player_status->animFlags |= 4;
    }
    player_status->actionState = actionState;
    player_status->flags |= 0x80000000;

    if (player_status->actionState == ActionState_SPIN) {
        return;
    }

    player_status->flags &= 0xFFFDFFFF;
    player_status->animFlags &= 0xFFFEFFFF;

    if (unknown_struct[0xC]) {
        stop_sound(unknown_struct[0xC]);
    }

    if (player_status->unk_D8) {
        player_status->unk_D8[3][9] = 0xA;
        player_status->unk_D8 = NULL;
    }
}

INCLUDE_ASM(s32, "code_7bb60_len_41b0", update_locomotion_state);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", start_falling);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", start_bounce_a);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", start_bounce_b);

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

INCLUDE_ASM(s32, "code_7bb60_len_41b0", check_input_jump);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", check_input_spin);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E636C);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E63A4);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E6428);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E6500);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", make_disguise_npc);

INCLUDE_ASM(s32, "code_7bb60_len_41b0", func_800E66C4);
