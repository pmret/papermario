#include "common.h"

struct struct8024F5C0 {
    char unk00[0x10];
    s32* unk10;
    char unk14[0x10];
};

extern struct struct8024F5C0 D_8024F5C0[1];
extern s32 D_8024F570[];

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

INCLUDE_ASM(s32, "pause/pause_items", pause_items_draw_contents);

extern u32 D_802705C4;

#ifdef NON_MATCHING
void pause_items_load_items(s32 invItems) {
    PlayerData* playerData = &gPlayerData;
    s32 i;
    s16* itemIDs;
    s32 pageNum;
    s16* itemMenuNumItems;
    s32 totalItems = 0;
    PauseItemPage* page;
    s32 items;
    s16* itemMenuItemIDs;

    D_802705D0 = 0;
    if (invItems == TRUE) {
        for (i = 0, itemIDs = &gItemMenuItemIDs; i < ARRAY_COUNT(playerData->invItems); i++) {
            if (playerData->invItems[i] != 0) {
                itemIDs[totalItems] = playerData->invItems[i];
                totalItems++;
            }
        }
    } else {
        for (i = 0, itemIDs = &gItemMenuItemIDs; i < ARRAY_COUNT(playerData->keyItems); i++) {
            if (playerData->keyItems[i] != 0) {
                itemIDs[totalItems] = playerData->keyItems[i];
                totalItems++;
            }
        }
    }

    if (totalItems == 0) {
        gItemMenuItemIDs[0] = 0x7FFE;
        totalItems = 1;
    } else {
        pause_sort_item_list(&gItemMenuItemIDs, totalItems, pause_items_comparator);
    }

    gItemMenuNumItems = totalItems;

    for (items = totalItems; items < 100; items++) {
        itemMenuItemIDs = &gItemMenuItemIDs;
        itemMenuItemIDs[items] = 0x7FFF;
    }

    page = &gItemMenuPages;
    pageNum = 0;
    itemMenuNumItems = &gItemMenuNumItems;
    gItemMenuSelectedIndex = 0;
    gItemMenuSelectedItemID = 0;
    D_802705C4 = 0;
    D_802705DC = 0;
    gItemMenuCurrentPage = 0;

    while (pageNum < *itemMenuNumItems / 8) {
        page->listStart = pageNum * 8;
        page->numCols = 1;
        page->numRows = 8;
        page->enabled = 1;
        page->startIndex =  pageNum * 8;
        page->count = 8;
        pageNum++;
        page++;
    }

    if ((*itemMenuNumItems % 8) != 0) {
        page->listStart = pageNum * 8;
        page->numCols = 1;
        page->enabled = 1;
        page->startIndex = pageNum * 8;
        page->count = *itemMenuNumItems % 8;
        page->numRows = (u8) page->count;
        pageNum++;
        page++;
    }

    while (pageNum < ARRAY_COUNT(gItemMenuPages)) {
        page->enabled = NULL;
        pageNum++;
        page++;
    }

    gItemMenuTargetScrollPos = gItemMenuCurrentScrollPos = pause_items_get_pos_y(0, 0);
}
#else
INCLUDE_ASM(s32, "pause/pause_items", pause_items_load_items);
#endif

void pause_items_init(s8* arg0) {
    s32 i;

    gItemMenuLevel = 0;
    gItemMenuCurrentTab = 0;
    pause_items_load_items(FALSE);

    for (i = 0; i < ARRAY_COUNT(gItemIcons); i++) {
        gItemIcons[i] = create_icon(D_8024F570[i]);
        set_icon_flags(gItemIcons[i], 0x80);
    }

    for (i = 0; i < ARRAY_COUNT(D_8024F5C0); i++) {
        D_8024F5C0[i].unk10 = arg0;
    }

    setup_pause_menu_tab(&D_8024F5C0, 1);
    *arg0 = 1;
}

INCLUDE_ASM(s32, "pause/pause_items", pause_items_handle_input);

void pause_items_update(void) {
    PauseItemPage* menuPage = &gItemMenuPages[gItemMenuCurrentPage];
    s32 selectedIndex = (gItemMenuSelectedIndex / menuPage->numCols) - menuPage->listStart;

    if (selectedIndex < 2 || menuPage->numRows < 9) {
        D_802705DC = 0;
    } else if (selectedIndex >= (menuPage->numRows - 2)) {
        D_802705DC = menuPage->numRows - 8;
    } else if ((selectedIndex - D_802705DC) > 6) {
        D_802705DC = selectedIndex - 6;
    } else if ((selectedIndex - D_802705DC) < 1) {
        D_802705DC = selectedIndex - 1;
    }

    gItemMenuTargetScrollPos = pause_items_get_pos_y(gItemMenuCurrentPage, D_802705DC * menuPage->numCols);
    gItemMenuCurrentScrollPos += pause_interp_vertical_scroll(gItemMenuTargetScrollPos - gItemMenuCurrentScrollPos);
}

void pause_items_cleanup(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gItemIcons); i++) {
        free_icon(gItemIcons[i]);
    }
}
