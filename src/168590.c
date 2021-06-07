#include "common.h"

INCLUDE_ASM(s32, "168590", func_80247D30);

INCLUDE_ASM(s32, "168590", func_80247FD0);

INCLUDE_ASM(s32, "168590", func_80248024);

void func_80248160(void) {
}

void func_80248168(void) {
}

void func_80248170(s32 arg0) {
    UIPanel* panel = &gUIPanels[arg0];

    if (panel->unk_1C == 0x8) {
        panel->flags &= ~0x8;
        set_window_update(arg0, 1);
    }
}

INCLUDE_ASM(s32, "168590", func_802481B8);

INCLUDE_ASM(s32, "168590", func_8024830C);

INCLUDE_ASM(s32, "168590", func_80248A80);

INCLUDE_ASM(s32, "168590", func_80248BF4);

void func_80249324(void) {
}

INCLUDE_ASM(s32, "168590", func_8024932C);
