#include "common.h"

s32 pause_items_comparator(s16* a, s16* b) {
    if (*a > *b) {
        return 1;
    } else {
        return -1;
    }
}

s32 pause_items_get_pos_x(s32 page, s32 itemIndex) {
    return (itemIndex % ITEM_MENU_PAGE(page)->numCols) * 98;
}

s32 pause_items_get_pos_y(s32 page, s32 itemIndex) {
    return ((page + 1) * 11) + (ITEM_MENU_PAGE(page)->listStart * 16) + ((itemIndex / ITEM_MENU_PAGE(page)->numCols) * 16);
}

s32 pause_items_get_column(s32 page, s32 itemIdx) {
    return itemIdx % ITEM_MENU_PAGE(page)->numCols;
}

s32 pause_items_get_row(s32 page, s32 itemIdx) {
    return ITEM_MENU_PAGE(page)->listStart + (itemIdx / ITEM_MENU_PAGE(page)->numCols);
}

s32 pause_items_is_visible(s32 y) {
    if (y < gItemMenuCurrentScrollPos - 32) {
        return FALSE;
    }
    return y < gItemMenuCurrentScrollPos + 128;
}

s32 pause_items_scroll_offset_y(s32 beforeY) {
    return beforeY - gItemMenuCurrentScrollPos;
}

s32 pause_items_scroll_offset_x(s32 beforeX) {
    return beforeX;
}

INCLUDE_ASM(s32, "code_13CAF0", pause_items_draw_contents);

INCLUDE_ASM(s32, "code_13CAF0", pause_items_load_items);

INCLUDE_ASM(s32, "code_13CAF0", pause_items_init);

INCLUDE_ASM(s32, "code_13CAF0", pause_items_handle_input);

INCLUDE_ASM(s32, "code_13CAF0", pause_items_update);

INCLUDE_ASM(s32, "code_13CAF0", pause_items_cleanup);
