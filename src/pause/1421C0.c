#include "common.h"

extern s32 D_8026F8D4[];

// Needs .data section
#ifdef NON_MATCHING
s32 pause_get_menu_string(s32 index) {
    return gPauseMenuStrings[index];
}
#else
INCLUDE_ASM(s32, "pause/1421C0", pause_get_menu_string);
#endif

void pause_draw_menu_label(s32 index, s32 x, s32 y) {
    s32 xOffset = 64;

    if (index == 8) {
        xOffset = 128;
    }
    if (index == 3) {
        xOffset = 48;
    }
    if (index == 4) {
        xOffset = 48;
    }
    if (index == 5) {
        xOffset = 48;
    }
    if (index == 6) {
        xOffset = 160;
    }

    gSPDisplayList(gMasterGfxPos++, D_8026F8D4[index]);
    pause_draw_rect(x * 4, y * 4, (x + xOffset) * 4, (y + 16) * 4, 0, 0, 0, 0x400, 0x400);
}
