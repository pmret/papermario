#include "common.h"

// this is definitely wrong but I had issues trying to use an array accessor
void clear_windows(void) {
    UIPanel* panelIt = gUIPanels;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gUIPanels); i++, panelIt++) {
        panelIt->flags = 0;
    }
}

INCLUDE_ASM(s32, "code_ddaf0_len_c50", update_windows);

INCLUDE_ASM(s32, "code_ddaf0_len_c50", basic_window_update);

INCLUDE_ASM(s32, "code_ddaf0_len_c50", basic_hidden_window_update);

INCLUDE_ASM(s32, "code_ddaf0_len_c50", main_menu_window_update);

INCLUDE_ASM(s32, "code_ddaf0_len_c50", render_windows);

INCLUDE_ASM(s32, "code_ddaf0_len_c50", render_window_root);

INCLUDE_ASM(s32, "code_ddaf0_len_c50", set_window_properties);

INCLUDE_ASM(s32, "code_ddaf0_len_c50", update_window_hierarchy);

void replace_window_update(s32 panelIndex, s8 arg1, s32 arg2) {
    UIPanel* panels = gUIPanels;

    if (panels[panelIndex].flags & 1) {
        panels[panelIndex].flags |= 0xA;
        panels[panelIndex].unk_08 = arg2;
        panels[panelIndex].unk_02 = arg1;
    }
}

void set_window_update(s32 panelIndex, s32 arg1) {
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

INCLUDE_ASM(s32, "code_ddaf0_len_c50", set_windows_visible);

INCLUDE_ASM(s32, "code_ddaf0_len_c50", setup_pause_menu_tab);
