#include "common.h"

// Need data segment and vars declared above
#ifdef NON_MATCHING
void pause_set_cursor_opacity(s32 val) {
    gPauseMenuCursorTargetOpacity = val;
}
#else
INCLUDE_ASM(s32, "code_135EE0", pause_set_cursor_opacity);
#endif

INCLUDE_ASM(s32, "code_135EE0", func_80242BAC);

INCLUDE_ASM(s32, "code_135EE0", func_80242D04);

INCLUDE_ASM(s32, "code_135EE0", pause_interp_cursor);

INCLUDE_ASM(s32, "code_135EE0", func_80242F90);

INCLUDE_ASM(s32, "code_135EE0", func_80242FBC);

INCLUDE_ASM(s32, "code_135EE0", func_80242FF4);

INCLUDE_ASM(s32, "code_135EE0", func_80243090);

INCLUDE_ASM(s32, "code_135EE0", func_802430E4);

INCLUDE_ASM(s32, "code_135EE0", func_8024313C);

INCLUDE_ASM(s32, "code_135EE0", func_80243188);

INCLUDE_ASM(s32, "code_135EE0", func_80243238);

INCLUDE_ASM(s32, "code_135EE0", func_802432E8);

INCLUDE_ASM(s32, "code_135EE0", func_80243388);

INCLUDE_ASM(s32, "code_135EE0", pause_interp_text_scroll);

INCLUDE_ASM(s32, "code_135EE0", pause_interp_vertical_scroll);

INCLUDE_ASM(s32, "code_135EE0", pause_update_cursor);

void func_80243568(void) {
}

INCLUDE_ASM(s32, "code_135EE0", pause_textbox_draw_contents);

INCLUDE_ASM(s32, "code_135EE0", pause_tutorial_draw_contents);

INCLUDE_ASM(s32, "code_135EE0", pause_init);

INCLUDE_ASM(s32, "code_135EE0", pause_tutorial_input);

INCLUDE_ASM(s32, "code_135EE0", pause_handle_input);

INCLUDE_ASM(s32, "code_135EE0", pause_cleanup);

INCLUDE_ASM(s32, "code_135EE0", pause_get_total_equipped_bp_cost);

INCLUDE_ASM(s32, "code_135EE0", pause_draw_rect);

INCLUDE_ASM(s32, "code_135EE0", pause_sort_item_list);

void pause_tabs_draw_invis(void) {
}

INCLUDE_ASM(s32, "code_135EE0", pause_tabs_draw_stats);

INCLUDE_ASM(s32, "code_135EE0", pause_tabs_draw_badges);

INCLUDE_ASM(s32, "code_135EE0", pause_tabs_draw_items);

INCLUDE_ASM(s32, "code_135EE0", pause_tabs_draw_party);

INCLUDE_ASM(s32, "code_135EE0", pause_tabs_draw_spirits);

INCLUDE_ASM(s32, "code_135EE0", pause_tabs_draw_map);

INCLUDE_ASM(s32, "code_135EE0", pause_tabs_init);

INCLUDE_ASM(s32, "code_135EE0", pause_tabs_handle_input);

INCLUDE_ASM(s32, "code_135EE0", pause_tabs_update);

INCLUDE_ASM(s32, "code_135EE0", pause_tabs_cleanup);

INCLUDE_ASM(s32, "code_135EE0", pause_stats_draw_contents);

INCLUDE_ASM(s32, "code_135EE0", pause_stats_init);

INCLUDE_ASM(s32, "code_135EE0", pause_stats_handle_input);

INCLUDE_ASM(s32, "code_135EE0", pause_stats_cleanup);

INCLUDE_ASM(s32, "code_135EE0", pause_badges_comparator);

INCLUDE_ASM(s32, "code_135EE0", pause_badges_count_all);

INCLUDE_ASM(s32, "code_135EE0", pause_badges_count_equipped);

INCLUDE_ASM(s32, "code_135EE0", pause_badges_get_pos_x);

INCLUDE_ASM(s32, "code_135EE0", pause_badges_get_pos_y);

INCLUDE_ASM(s32, "code_135EE0", pause_badges_get_column);

INCLUDE_ASM(s32, "code_135EE0", pause_badges_get_row);

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

INCLUDE_ASM(s32, "code_135EE0", pause_badges_try_remove);

INCLUDE_ASM(s32, "code_135EE0", pause_badges_try_equip);

INCLUDE_ASM(s32, "code_135EE0", pause_badges_draw_bp_orbs);

INCLUDE_ASM(s32, "code_135EE0", pause_badges_draw_contents);

INCLUDE_ASM(s32, "code_135EE0", pause_badges_load_badges);

INCLUDE_ASM(s32, "code_135EE0", pause_badges_init);

INCLUDE_ASM(s32, "code_135EE0", pause_badges_handle_input);

INCLUDE_ASM(s32, "code_135EE0", pause_badges_update);

INCLUDE_ASM(s32, "code_135EE0", pause_badges_cleanup);
