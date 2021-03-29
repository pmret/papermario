#include "common.h"

s32 D_8014F150[] = { 0x00000003, 0x00000003, 0x0000000B, 0x0000000C, 0x0000000D, 0x0000000E, 0x00000003, 0x00000015,
                     0x00000003, 0x00000000, 0x00000009, 0x00000003, 0x00000000, 0x00000001, 0x00000003, 0x00000009,
                     0x0000000A, 0x00000007, 0x00000008, 0x00000003, 0x00000003, 0x00000000, 0x00000000, 0x00000000,
                     0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
                     0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000003, 0x0000000B, 0x0000000C, 0x00000000,
                     0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
                     0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
                     0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001,
                   };

s32 D_8014F250[] = { 0x00000800, 0x0000000C, 0x00000004, 0x08000001, 0x00080000, 0x04000864, 0x00040008, 0x00000200,
                     0x0800B802, 0x000800FF, 0x02000C00, 0xB804000C, 0x64000000, 0x00000000, 0x00000000, 0x00000000,
                     0x00000000, 0x00000000,
                   };

s32 D_8014F298[] = { 0x32506469, 0x64000000, };

s8 D_8014F2A0[] = { 0x01, 0x01, 0x01, 0x01, };

s8 D_8014F2A4[] = { 0x00, 0x00, 0x00, 0x00, };

s32 D_8014F2A8[] = { 0x69644D39, 0x281B1008, 0x03000000, };

s8 D_8014F2B4[] = { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 };

s8 D_8014F2BD = 0;

s32 D_8014F2C0[] = { 0x003F0809, 0x162B2C3F, 0x00000000, 0x00000000, };

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
