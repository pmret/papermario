#include "common.h"

INCLUDE_ASM("code_7bb60_len_41b0", func_800E26B0);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E26C4);

INCLUDE_ASM("code_7bb60_len_41b0", move_player);

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

INCLUDE_ASM("code_7bb60_len_41b0", set_action_state);

INCLUDE_ASM("code_7bb60_len_41b0", update_locomotion_state);

INCLUDE_ASM("code_7bb60_len_41b0", start_falling);

INCLUDE_ASM("code_7bb60_len_41b0", start_bounce_a);

INCLUDE_ASM("code_7bb60_len_41b0", start_bounce_b);

INCLUDE_ASM("code_7bb60_len_41b0", check_input_hammer);

INCLUDE_ASM("code_7bb60_len_41b0", check_input_jump);

INCLUDE_ASM("code_7bb60_len_41b0", check_input_spin);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E636C);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E6428);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E6500);

INCLUDE_ASM("code_7bb60_len_41b0", func_800E657C);
