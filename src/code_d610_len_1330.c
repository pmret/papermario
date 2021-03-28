#include "common.h"

extern s16 D_800A08F0;
extern s32 D_80077850[];

INCLUDE_ASM(s32, "code_d610_len_1330", func_80032210);

INCLUDE_ASM(s32, "code_d610_len_1330", func_800322DC);

INCLUDE_ASM(s32, "code_d610_len_1330", func_800325E4);

INCLUDE_ASM(s32, "code_d610_len_1330", func_800328A4);

INCLUDE_ASM(s32, "code_d610_len_1330", func_80032970);

INCLUDE_ASM(s32, "code_d610_len_1330", func_80032C64);

INCLUDE_ASM(s32, "code_d610_len_1330", create_camera_lead_player_mtx);

void func_800334E8(void) {
}

void set_game_mode(s16 idx) {
    D_800A08F0 = idx;
    set_game_mode_slot(0, D_80077850[idx]);
}

s16 get_game_mode(void) {
    return D_800A08F0;
}
