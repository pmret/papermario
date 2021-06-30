#include "common.h"

INCLUDE_ASM(void, "cd180_len_38f0", _render_transition_stencil, s32 arg0, f32 arg1, s32 arg2);

INCLUDE_ASM(void, "cd180_len_38f0", set_screen_overlay_params_front, u8 arg0, f32 arg1);

INCLUDE_ASM(void, "cd180_len_38f0", set_screen_overlay_params_back, s32 arg0, f32 arg1);

INCLUDE_ASM(void, "cd180_len_38f0", get_screen_overlay_params, s32 arg0, f32* arg1, f32* arg2);

INCLUDE_ASM(s32, "cd180_len_38f0", set_screen_overlay_color, s32 arg0, u8 arg1, u8 arg2, u8 arg3);

INCLUDE_ASM(void, "cd180_len_38f0", set_screen_overlay_center, s32 arg0, s32 arg1, s32 arg2, s32 arg3);

INCLUDE_ASM(s32, "cd180_len_38f0", set_screen_overlay_center_worldpos);

INCLUDE_ASM(void, "cd180_len_38f0", set_screen_overlay_alpha, s32 arg0, f32 arg1);

INCLUDE_ASM(s32, "cd180_len_38f0", clear_screen_overlays);

INCLUDE_ASM(s32, "cd180_len_38f0", func_80138188);

void func_80138198(void) {
}

INCLUDE_ASM(s32, "cd180_len_38f0", render_screen_overlay_frontUI);

INCLUDE_ASM(s32, "cd180_len_38f0", render_screen_overlay_backUI);

INCLUDE_ASM(s32, "cd180_len_38f0", set_map_transition_effect);

INCLUDE_ASM(s32, "cd180_len_38f0", update_exit_map_screen_overlay);

INCLUDE_ASM(s32, "cd180_len_38f0", update_enter_map_screen_overlay);
