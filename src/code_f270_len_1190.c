#include "common.h"

extern s8 D_800A0920;
extern s8 D_800A0921;
extern s16 D_800A0922;

void func_800343A4();

INCLUDE_ASM(s32, "code_f270_len_1190", begin_state_logos);

INCLUDE_ASM(s32, "code_f270_len_1190", step_logos);

void func_80034388(void) {
    func_800343A4();
}

INCLUDE_ASM(void, "code_f270_len_1190", func_800343A4);

void begin_state_pause_menu(void) {
    D_800A0921 = 0;
    D_800A0922 = 0;
    disable_player_input();
    func_80027088(3);
    set_windows_visible(2);
}

INCLUDE_ASM(s32, "code_f270_len_1190", step_pause_menu);

void func_80034BF4(void) {
}

void func_80034BFC(void) {
    if (D_800A0922 > 0) {
        D_800A0921 = 0;
    } else {
        D_800A0921 = 1;
    }
    D_800A0920 = 4;
}

INCLUDE_ASM(s32, "code_f270_len_1190", func_80034C3C);

void func_80034FF0(void) {
}
