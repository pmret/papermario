#include "common.h"

// Needs .data section
#ifdef NON_MATCHING
s32 pause_get_menu_string(s32 index) {
    return gPauseMenuStrings[index];
}
#else
INCLUDE_ASM(s32, "pause/1421C0", pause_get_menu_string);
#endif

INCLUDE_ASM(s32, "pause/1421C0", pause_draw_menu_label);
