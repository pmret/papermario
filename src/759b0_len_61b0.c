#include "common.h"

PlayerStatus* gPlayerStatusPtr = &gPlayerStatus; // maybe wPlayerStatus

INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_down);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_down_ahead);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_down_sides, s32 arg0, f32* arg1, f32* arg2, f32* arg3, f32* arg4);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_up);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_up_corner);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_up_corners);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_general);

void npc_get_slip_vector(f32* arg0, f32* arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 temp = (arg2 * arg4) + (arg3 * arg5);

    *arg0 = (arg2 - (temp * arg4)) * 0.5f;
    *arg1 = (arg3 - (temp * arg5)) * 0.5f;
}

INCLUDE_ASM(s32, "759b0_len_61b0", npc_test_move_with_slipping);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_test_move_without_slipping);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_test_move_taller_with_slipping);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_test_move_simple_with_slipping, s32 arg0, f32* arg1, f32* arg2, f32* arg3, f32 arg4, f32 arg5,
            f32 arg6, f32 arg7);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_test_move_simple_without_slipping);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_test_move_complex_with_slipping);
