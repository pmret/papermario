#include "common.h"

INCLUDE_ASM(s32, "code_13CAF0", pause_items_comparator);

INCLUDE_ASM(s32, "code_13CAF0", pause_items_get_pos_x);

INCLUDE_ASM(s32, "code_13CAF0", pause_items_get_pos_y);

INCLUDE_ASM(s32, "code_13CAF0", pause_items_get_column);

INCLUDE_ASM(s32, "code_13CAF0", pause_items_get_row);

INCLUDE_ASM(s32, "code_13CAF0", pause_items_is_visible);

INCLUDE_ASM(s32, "code_13CAF0", pause_items_scroll_offset_y);

s32 pause_items_scroll_offset_x(s32 beforeX) {
    return beforeX;
}

INCLUDE_ASM(s32, "code_13CAF0", pause_items_draw_contents);

INCLUDE_ASM(s32, "code_13CAF0", pause_items_load_items);

INCLUDE_ASM(s32, "code_13CAF0", pause_items_init);

INCLUDE_ASM(s32, "code_13CAF0", pause_items_handle_input);

INCLUDE_ASM(s32, "code_13CAF0", pause_items_update);

INCLUDE_ASM(s32, "code_13CAF0", pause_items_cleanup);

INCLUDE_ASM(s32, "code_13CAF0", pause_partners_load_portrait);

INCLUDE_ASM(s32, "code_13CAF0", pause_partners_draw_contents);

INCLUDE_ASM(s32, "code_13CAF0", pause_partners_draw_title);

INCLUDE_ASM(s32, "code_13CAF0", pause_partners_draw_movelist);

INCLUDE_ASM(s32, "code_13CAF0", pause_partners_draw_movelist_title);

INCLUDE_ASM(s32, "code_13CAF0", pause_partners_draw_movelist_flower);

INCLUDE_ASM(s32, "code_13CAF0", pause_partners_init);

INCLUDE_ASM(s32, "code_13CAF0", pause_partners_handle_input);

INCLUDE_ASM(s32, "code_13CAF0", pause_partners_update);

INCLUDE_ASM(s32, "code_13CAF0", pause_partners_cleanup);
