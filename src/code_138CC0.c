#include "common.h"

INCLUDE_ASM(s32, "code_138CC0", pause_stats_draw_contents);

INCLUDE_ASM(s32, "code_138CC0", pause_stats_init);

INCLUDE_ASM(s32, "code_138CC0", pause_stats_handle_input);

void pause_stats_cleanup(void) {
    s32* iconIDs = gStatsMenuIconIDs;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gStatsMenuIconIDs); i++) {
        free_icon(iconIDs[i]);
    }
}

INCLUDE_ASM(s32, "code_138CC0", pause_badges_comparator);

INCLUDE_ASM(s32, "code_138CC0", pause_badges_count_all);

INCLUDE_ASM(s32, "code_138CC0", pause_badges_count_equipped);

INCLUDE_ASM(s32, "code_138CC0", pause_badges_get_pos_x);

INCLUDE_ASM(s32, "code_138CC0", pause_badges_get_pos_y);

s32 pause_badges_get_column(s32 page, s32 itemIdx) {
    return itemIdx % gBadgeMenuPages[page].numCols;
}

INCLUDE_ASM(s32, "code_138CC0", pause_badges_get_row);

s32 pause_badges_is_visible(s32 y) {
    if (y < gBadgeMenuCurrentScrollPos - 32) {
        return FALSE;
    } else {
        return y < gBadgeMenuCurrentScrollPos + 128;
    }
}

s32 pause_badges_scroll_offset_y(s32 offset) {
    return offset - gBadgeMenuCurrentScrollPos;
}

s32 pause_badges_scroll_offset_x(s32 x) {
    return x;
}

INCLUDE_ASM(s32, "code_138CC0", pause_badges_try_remove);

INCLUDE_ASM(s32, "code_138CC0", pause_badges_try_equip);

INCLUDE_ASM(s32, "code_138CC0", pause_badges_draw_bp_orbs);

INCLUDE_ASM(s32, "code_138CC0", pause_badges_draw_contents);

INCLUDE_ASM(s32, "code_138CC0", pause_badges_load_badges);

INCLUDE_ASM(s32, "code_138CC0", pause_badges_init);

INCLUDE_ASM(s32, "code_138CC0", pause_badges_handle_input);

INCLUDE_ASM(s32, "code_138CC0", pause_badges_update);

INCLUDE_ASM(s32, "code_138CC0", pause_badges_cleanup);
