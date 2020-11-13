#include "common.h"

// this is definitely wrong but I had issues trying to use an array accessor
void func_801473F0(void) {
    UIPanel* panelIt = gUIPanels;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gUIPanels); i++, panelIt++) {
        panelIt->flags = 0;
    }
}

INCLUDE_ASM(s32, "code_ddaf0_len_c50", func_80147414);

INCLUDE_ASM(s32, "code_ddaf0_len_c50", func_80147474);

INCLUDE_ASM(s32, "code_ddaf0_len_c50", func_80147574);

INCLUDE_ASM(s32, "code_ddaf0_len_c50", func_80147650);

INCLUDE_ASM(s32, "code_ddaf0_len_c50", func_80147698);

INCLUDE_ASM(s32, "code_ddaf0_len_c50", func_80147AC4);

INCLUDE_ASM(s32, "code_ddaf0_len_c50", set_ui_panel_properties);

INCLUDE_ASM(s32, "code_ddaf0_len_c50", func_80147D70);

void func_80147E48(s32 panelIndex, s8 arg1, s32 arg2) {
    UIPanel* panels = gUIPanels;

    if (panels[panelIndex].flags & 1) {
        panels[panelIndex].flags |= 0xA;
        panels[panelIndex].unk_08 = arg2;
        panels[panelIndex].unk_02 = arg1;
    }
}

void func_80147E7C(s32 panelIndex, s32 arg1) {
    UIPanel* panels = gUIPanels;

    if (panels[panelIndex].flags & 1) {
        if (arg1 == panels[panelIndex].unk_04) {
            panels[panelIndex].flags &= ~0x2;
        } else {
            panels[panelIndex].flags |= 0xA;
            panels[panelIndex].unk_08 = arg1;
        }
    }
}

INCLUDE_ASM(s32, "code_ddaf0_len_c50", func_80147EC4);

INCLUDE_ASM(s32, "code_ddaf0_len_c50", func_80147F30);
