#include "pause_common.h"
#include "message_ids.h"

void pause_items_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_items_init(MenuPanel* panel);
void pause_items_handle_input(MenuPanel* panel);
void pause_items_update(MenuPanel* panel);
void pause_items_cleanup(MenuPanel* panel);

static s16 gPauseItemsItemIDs[100];
static s32 gPauseItemsCurrentPage;
static s32 D_802704CC;
static PauseItemPage gPauseItemsPages[20];
static s32 gPauseItemsSelectedIndex;
static u32 D_802705C4;
static s32 gPauseItemsSelectedItem;
static s16 gPauseItemsNumItems;
static s32 D_802705D0;
static s32 gPauseItemsCurrentScrollPos;
static s32 gPauseItemsTargetScrollPos;
static s32 gPauseItemsTargetScrollIndex;
static s32 gPauseItemsLevel;
static s32 gPauseItemsCurrentTab;
static s32 gPauseItemsIconIDs[20];

#define ITEM_NONE_STANDIN 0x7FFE
#define ITEM_INVALID 0x7FFF

HudScript* gPauseItemsElements[] = {
    &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp,
    &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp,
    &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp, &HES_StatBp,
    &HES_StatBp, &HES_ListPrevPage, &HES_ListNextPage, &HES_Dash,
    &HES_StatusStar1
};
MenuWindowBP gPauseItemsWindowBPs[] = {
    {
        .windowID = WINDOW_ID_PAUSE_ITEMS,
        .unk_01 = 0,
        .pos = { .x = 3, .y = 16 },
        .width = 289,
        .height = 154,
        .priority = WINDOW_PRIORITY_1,
        .fpDrawContents = &pause_items_draw_contents,
        .tab = NULL,
        .parentID = WINDOW_ID_PAUSE_MAIN,
        .fpUpdate = { WINDOW_UPDATE_HIDE },
        .extraFlags = 0,
        .style = { .customStyle = &gPauseWS_19 }
    }
};
MenuPanel gPausePanelItems = {
    .initialized = FALSE,
    .col = 0,
    .row = 0,
    .selected = 0,
    .page = 0,
    .numCols = 0,
    .numRows = 0,
    .numPages = 0,
    .gridData = NULL,
    .fpInit = &pause_items_init,
    .fpHandleInput = &pause_items_handle_input,
    .fpUpdate = &pause_items_update,
    .fpCleanup = &pause_items_cleanup
};

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
    if (y < gPauseItemsCurrentScrollPos - 32) {
        return FALSE;
    }
    return y < gPauseItemsCurrentScrollPos + 128;
}

s32 pause_items_scroll_offset_y(s32 beforeY) {
    return beforeY - gPauseItemsCurrentScrollPos;
}

s32 pause_items_scroll_offset_x(s32 beforeX) {
    return beforeX;
}

#if VERSION_PAL
INCLUDE_ASM(void, "pause/pause_items", pause_items_draw_contents);
#else
void pause_items_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    s32 i, pageIndex, itemIndex;
    s32 totalItemIndex;
    s32 currentItemRow;
    s32 currentItemColumn;
    s32 style;
    s32 palette;
    s32 posX, posY;
    s32 sp6C;
    s32 sp70;
    s32 isNone;
    s32* sp78;
    PauseItemPage* page;
    s32 x1, y1, x2, y2;
    s16 itemID;
    s32 isSelected, itemOffsetX, itemOffsetY;
    s32* iconIDs;
    s32 itemIcon;
    s32 msg, msgX, msgY, opacity1;
    s32 selectedPosX, selectedPosY;
    s32 cursorOffsetX, cursorOffsetY;

    style = DRAW_MSG_STYLE_MENU;
    palette = MSG_PAL_STANDARD;
    currentItemColumn = gPauseItemsSelectedIndex / gPauseItemsPages[gPauseItemsCurrentPage].numCols;
    currentItemRow = gPauseItemsSelectedIndex % gPauseItemsPages[gPauseItemsCurrentPage].numCols;
    draw_box(DRAW_FLAG_NO_CLIP, &gPauseWS_18, baseX + 68, baseY, 0, width - 68, height, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    x1 = baseX + 1;
    y1 = baseY + 7;
    x2 = baseX + width - 1;
    y2 = baseY + height - 7;

    if (x1 <= 0) {
        x1 = 1;
    }
    if (y1 <= 0) {
        y1 = 1;
    }

    if (x2 <= 0 || y2 <= 0 || x1 >= SCREEN_WIDTH - 1 || y1 >= SCREEN_HEIGHT - 1) {
        return;
    }

    if (x2 >= SCREEN_WIDTH - 1) {
        x2 = SCREEN_WIDTH - 1;
    }
    if (y2 >= SCREEN_HEIGHT - 1) {
        y2 = SCREEN_HEIGHT - 1;
    }

    totalItemIndex = 0;
    sp6C = baseX + 119;
    sp70 = baseY + 17;

    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, x1, y1, x2, y2);

    for (i = 0; i < 3; i++) {
        for (pageIndex = 0; pageIndex < 20; pageIndex++) {
            iconIDs = gPauseItemsIconIDs;

            page = &gPauseItemsPages[pageIndex];
            if (!page->enabled) {
                break;
            }

            pause_items_get_pos_y(pageIndex, 0);

            for (itemIndex = 0; itemIndex < page->count; itemIndex++) {
                itemID = gPauseItemsItemIDs[page->startIndex + itemIndex];
                isSelected = FALSE;
                if (itemID == ITEM_INVALID) {
                    continue;
                }

                posX = pause_items_get_pos_x(pageIndex, itemIndex);
                posY = pause_items_get_pos_y(pageIndex, itemIndex);

                isNone = itemID == ITEM_NONE_STANDIN;

                if (gPauseMenuCurrentTab == 3 &&
                    gPauseItemsLevel == 1 &&
                    pause_items_get_column(pageIndex, itemIndex) == currentItemRow &&
                    pause_items_get_row(pageIndex, itemIndex) == currentItemColumn) {
                    isSelected = TRUE;
                }

                itemOffsetX = 0;
                itemOffsetY = 0;
                if (isSelected) {
                    itemOffsetX = -1;
                    itemOffsetY = -1;
                }

                if (i == 0) {
                    style = DRAW_MSG_STYLE_MENU;
                    palette = MSG_PAL_STANDARD;

                    if (isSelected) {
                        style = DRAW_MSG_STYLE_MENU | DRAW_MSG_STYLE_DROP_SHADOW;
                    }
                }

                if (!pause_items_is_visible(posY)) {
                    continue;
                }

                if (i == 0) {
                    if (isNone) {
                        draw_msg(pause_get_menu_msg(PAUSE_MSG_BAGDE_DESC_NONE), sp6C + pause_items_scroll_offset_x(posX) + itemOffsetX,
                                sp70 + pause_items_scroll_offset_y(posY) + itemOffsetY, 255, palette, style);
                    } else {
                        if (gItemTable[itemID].nameMsg) {
                            if (gItemTable[itemID].nameMsg > 0) {
                                draw_msg(gItemTable[itemID].nameMsg, sp6C + pause_items_scroll_offset_x(posX) + itemOffsetX,
                                        sp70 + pause_items_scroll_offset_y(posY) + itemOffsetY, 255, palette, style);
                            }
                        }
                    }
                }

                if (i == 1) {
                    itemIcon = iconIDs[totalItemIndex];
                    hud_element_clear_flags(itemIcon, HUD_ELEMENT_FLAG_DROP_SHADOW);
                    hud_element_set_flags(itemIcon, HUD_ELEMENT_FLAG_FILTER_TEX);
                    if (isNone) {
                        itemIcon = gPauseItemsIconIDs[19];
                    } else {
                        if (isSelected) {
                            hud_element_set_flags(itemIcon, HUD_ELEMENT_FLAG_DROP_SHADOW);
                            gPauseCurrentDescIconScript = gItemHudScripts[gItemTable[itemID].hudElemID].enabled;
                        }

                        hud_element_set_script(itemIcon, gItemHudScripts[gItemTable[itemID].hudElemID].enabled);
                        hud_element_set_scale(itemIcon, 0.670816f);
                    }

                    hud_element_set_render_pos(itemIcon, baseX + 105 + pause_items_scroll_offset_x(posX) + itemOffsetX,
                                                baseY + 23 + pause_items_scroll_offset_y(posY) + itemOffsetY);
                    if (totalItemIndex == 0) {
                        hud_element_draw_without_clipping(itemIcon);
                    } else {
                        hud_element_draw_next(itemIcon);
                    }

                    totalItemIndex++;
                }
            }
        }
    }

    x1 = baseX + 1;
    y1 = baseY + 1;
    x2 = baseX + width - 1;
    y2 = baseY + height - 1;
    gDPPipeSync(gMainGfxPos++);

    if (x1 <= 0) {
        x1 = 1;
    }
    if (y1 <= 0) {
        y1 = 1;
    }

    if (x2 <= 0 || y2 <= 0 || x1 >= SCREEN_WIDTH - 1 || y1 >= SCREEN_HEIGHT - 1) {
        return;
    }

    if (x2 >= SCREEN_WIDTH - 1) {
        x2 = SCREEN_WIDTH - 1;
    }
    if (y2 >= SCREEN_HEIGHT - 1) {
        y2 = SCREEN_HEIGHT - 1;
    }

    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, x1, y1, x2, y2);

    if (gPauseMenuCurrentTab == 3 && gPauseItemsLevel == 1) {
        if (gPauseItemsCurrentPage > 0) {
            hud_element_set_render_pos(gPauseItemsIconIDs[16], baseX + 278, baseY + 14);
            hud_element_draw_without_clipping(gPauseItemsIconIDs[16]);
        }

        if (gPauseItemsPages [gPauseItemsCurrentPage + 1].enabled) {
            hud_element_set_render_pos(gPauseItemsIconIDs[17], baseX + 278, baseY + 146);
            hud_element_draw_without_clipping(gPauseItemsIconIDs[17]);
        }
    }

    draw_box(DRAW_FLAG_NO_CLIP, &gPauseWS_17, gPauseItemsCurrentTab == 0 ? baseX + 9 : baseX, baseY + 7, 0,
         91, 34, 255, gPauseItemsCurrentTab == 1 ? 128 : 0, 0, 0,
         0, 0, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    msg = pause_get_menu_msg(PAUSE_MSG_KEY_ITEMS);
    msgX = baseX + 12;
    if (gPauseItemsCurrentTab == 0) {
        msgX = baseX + 21;
    }
    opacity1 = 255;
    msgY = baseY + 17;
    if (gPauseItemsCurrentTab == 1) {
        opacity1 = 191;
    }
    draw_msg(msg, msgX, msgY, opacity1, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);

    draw_box(DRAW_FLAG_NO_CLIP, &gPauseWS_17, gPauseItemsCurrentTab == 1 ? baseX + 9 : baseX, baseY + 39, 0,
         91, 34, 255, gPauseItemsCurrentTab == 0 ? 128 : 0, 0, 0,
         0, 0, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    msg = pause_get_menu_msg(PAUSE_MSG_CONSUMABLES);
    msgX = baseX + 25;
    if (gPauseItemsCurrentTab == 1) {
        msgX = baseX + 34;
    }
    opacity1 = 255;
    msgY = baseY + 49;
    if (gPauseItemsCurrentTab == 0) {
        opacity1 = 191;
    }
    draw_msg(msg, msgX, msgY, opacity1, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);

    if (gPauseMenuCurrentTab == 3) {
         if (gPauseItemsLevel == 0) {
             pause_set_cursor_pos(WINDOW_ID_PAUSE_ITEMS, baseX + 12, baseY + 26 + gPauseItemsCurrentTab * 32);
         } else {
             selectedPosX = pause_items_get_pos_x(gPauseItemsCurrentPage, gPauseItemsSelectedIndex  - gPauseItemsPages[gPauseItemsCurrentPage].listStart * gPauseItemsPages[gPauseItemsCurrentPage].numCols);
             selectedPosY = pause_items_get_pos_y(gPauseItemsCurrentPage, gPauseItemsSelectedIndex  - gPauseItemsPages[gPauseItemsCurrentPage].listStart * gPauseItemsPages[gPauseItemsCurrentPage].numCols);
             cursorOffsetX = pause_items_scroll_offset_x(selectedPosX);
             cursorOffsetY = pause_items_scroll_offset_y(selectedPosY);
             if (cursorOffsetY < 0) {
                 cursorOffsetY = 0;
             } else if (cursorOffsetY > 112) {
                 cursorOffsetY = 112;
             }

             if (gPauseItemsCurrentScrollPos  != gPauseItemsTargetScrollPos) {
                 pause_set_cursor_pos_immediate(WINDOW_ID_PAUSE_ITEMS, baseX + 85 + cursorOffsetX, baseY + 23 + cursorOffsetY);
             } else {
                 pause_set_cursor_pos(WINDOW_ID_PAUSE_ITEMS, baseX + 85 + cursorOffsetX, baseY + 23 + cursorOffsetY);
             }
         }
    }
}
#endif

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
        for (i = 0; i < ARRAY_COUNT(playerData->invItems); i++) {
            if (playerData->invItems[i] != ITEM_NONE) {
                gPauseItemsItemIDs[totalItems] = playerData->invItems[i];
                totalItems++;
            }
        }
    } else {
        for (i = 0; i < ARRAY_COUNT(playerData->keyItems); i++) {
            if (playerData->keyItems[i] != ITEM_NONE) {
                gPauseItemsItemIDs[totalItems] = playerData->keyItems[i];
                totalItems++;
            }
        }
    }

    if (totalItems == 0) {
        gPauseItemsItemIDs[0] = ITEM_NONE_STANDIN;
        totalItems = 1;
    } else {
        pause_sort_item_list(gPauseItemsItemIDs, totalItems, pause_items_comparator);
    }

    gPauseItemsNumItems = totalItems;

    for (i = totalItems; i < ARRAY_COUNT(gPauseItemsItemIDs); i++) {
        gPauseItemsItemIDs[i] = ITEM_INVALID;
    }

    page = gPauseItemsPages;
    gPauseItemsSelectedIndex = 0;
    gPauseItemsSelectedItem = 0;
    D_802705C4 = 0;
    gPauseItemsTargetScrollIndex = 0;
    gPauseItemsCurrentPage = 0;

    for (i = 0; i < gPauseItemsNumItems / 8; i++, page++) {
        page->listStart = i * 8;
        page->numCols = 1;
        page->numRows = 8;
        page->enabled = TRUE;
        page->startIndex =  i * 8;
        page->count = 8;
    }

    if ((gPauseItemsNumItems % 8) != 0) {
        page->listStart = i * 8;
        page->numCols = 1;
        page->enabled = TRUE;
        page->startIndex = i * 8;
        page->count = gPauseItemsNumItems % 8;
        page->numRows = page->count;
        i++;
        page++;
    }

    for (; i < ARRAY_COUNT(gPauseItemsPages); i++, page++) {
        page->enabled = FALSE;
    }

    gPauseItemsTargetScrollPos = gPauseItemsCurrentScrollPos = pause_items_get_pos_y(0, 0);
}

void pause_items_init(MenuPanel* panel) {
    s32 i;

    gPauseItemsLevel = 0;
    gPauseItemsCurrentTab = 0;
    pause_items_load_items(FALSE);

    for (i = 0; i < ARRAY_COUNT(gPauseItemsIconIDs); i++) {
        gPauseItemsIconIDs[i] = hud_element_create(gPauseItemsElements[i]);
        hud_element_set_flags(gPauseItemsIconIDs[i], HUD_ELEMENT_FLAG_80);
    }

    for (i = 0; i < ARRAY_COUNT(gPauseItemsWindowBPs); i++) {
        gPauseItemsWindowBPs[i].tab = panel;
    }

    setup_pause_menu_tab(gPauseItemsWindowBPs, ARRAY_COUNT(gPauseItemsWindowBPs));
    panel->initialized = TRUE;
}

void pause_items_handle_input(MenuPanel* panel) {
    s32 oldTab;
    s32 oldSelectedIndex = gPauseItemsSelectedIndex;
    s32 row = gPauseItemsSelectedIndex / gPauseItemsPages[gPauseItemsCurrentPage].numCols;
    s32 column = gPauseItemsSelectedIndex % gPauseItemsPages[gPauseItemsCurrentPage].numCols;

    if ((gPausePressedButtons & BUTTON_A) && gPauseItemsLevel == 0) {
        if (gPauseItemsItemIDs[gPauseItemsSelectedIndex] == ITEM_NONE_STANDIN) {
            sfx_play_sound(SOUND_MENU_ERROR);
        } else {
            gPauseItemsLevel = 1;
            sfx_play_sound(SOUND_MENU_NEXT);
        }
        return;
    }

    if (gPauseItemsNumItems != 0) {
        if (gPauseItemsLevel == 0) {
            oldTab = gPauseItemsCurrentTab;
            if (gPauseHeldButtons & (BUTTON_STICK_UP|BUTTON_STICK_DOWN)) {
                gPauseItemsCurrentTab ^= 1;
            }

            if (oldTab != gPauseItemsCurrentTab) {
                sfx_play_sound(SOUND_MENU_CHANGE_TAB);
                pause_items_load_items(gPauseItemsCurrentTab);
            }
        } else {
            if (gPauseHeldButtons & (BUTTON_STICK_UP|BUTTON_Z)) {
                row--;
                if (gPauseHeldButtons & BUTTON_STICK_UP) {
                    if (row < 0) {
                        row = 0;
                    }

                    if (row < gPauseItemsPages[gPauseItemsCurrentPage].listStart) {
                        gPauseItemsCurrentPage--;
                    }
                } else {
                    gPauseItemsCurrentPage--;
                    if (gPauseItemsCurrentPage < 0) {
                        gPauseItemsCurrentPage = 0;
                    }
                    row = gPauseItemsPages[gPauseItemsCurrentPage].listStart;
                }
            }

            if (gPauseHeldButtons & (BUTTON_STICK_DOWN|BUTTON_R)) {
                if (gPauseHeldButtons & BUTTON_STICK_DOWN) {
                    row++;
                    if (row >= gPauseItemsPages[gPauseItemsCurrentPage].listStart + gPauseItemsPages[gPauseItemsCurrentPage].numRows) {
                        gPauseItemsCurrentPage++;

                        if (!gPauseItemsPages[gPauseItemsCurrentPage].enabled) {
                            gPauseItemsCurrentPage--;
                            row--;
                        }
                    }
                } else {
                    gPauseItemsCurrentPage++;

                    if (!gPauseItemsPages[gPauseItemsCurrentPage].enabled) {
                        gPauseItemsCurrentPage--;
                    } else {
                        row = gPauseItemsPages[gPauseItemsCurrentPage].listStart;
                    }
                }
            }

            if (gPauseItemsItemIDs[row * gPauseItemsPages[gPauseItemsCurrentPage].numCols] != ITEM_NONE_STANDIN) {
                if (gPauseHeldButtons & BUTTON_STICK_LEFT) {
                    column--;

                    if (column < 0) {
                        column = gPauseItemsPages[gPauseItemsCurrentPage].numCols - 1;
                    }
                } else if (gPauseHeldButtons & BUTTON_STICK_RIGHT) {
                    column++;
                    if (column >= gPauseItemsPages[gPauseItemsCurrentPage].numCols) {
                        column = 0;
                    }
                }
            } else {
                column = 0;
            }

            gPauseItemsSelectedIndex = column + row * gPauseItemsPages[gPauseItemsCurrentPage].numCols;
            if (gPauseItemsSelectedIndex != oldSelectedIndex) {
                sfx_play_sound(SOUND_MENU_CHANGE_SELECTION);
            }

            gPauseItemsSelectedItem = gPauseItemsItemIDs[gPauseItemsSelectedIndex];
        }
    }

    if (gPauseItemsLevel == 1) {
        if (gPauseItemsSelectedItem != ITEM_NONE_STANDIN && gPauseItemsSelectedItem != ITEM_INVALID && gPauseItemsSelectedItem != 0) {
            gPauseCurrentDescMsg = gItemTable[gPauseItemsSelectedItem].fullDescMsg;
        } else {
            gPauseCurrentDescMsg = MSG_NONE;
            gPauseCurrentDescIconScript = NULL;
        }
    } else {
        if (gPauseItemsCurrentTab == 1) {
            gPauseCurrentDescMsg = pause_get_menu_msg(PAUSE_MSG_DESC_CONSUMABLES);
        } else {
            gPauseCurrentDescMsg = pause_get_menu_msg(PAUSE_MSG_DESC_KEY_ITEMS);
        }

        gPauseCurrentDescIconScript = NULL;
    }

    if (gPausePressedButtons & BUTTON_B) {
        if (gPauseItemsLevel == 0) {
            sfx_play_sound(SOUND_MENU_BACK);
            gPauseMenuCurrentTab = 0;
        } else {
            sfx_play_sound(SOUND_MENU_BACK);
            gPauseItemsLevel = 0;
        }
    }
}

void pause_items_update(MenuPanel* panel) {
    PauseItemPage* page = &gPauseItemsPages[gPauseItemsCurrentPage];
    s32 selectedIndex = (gPauseItemsSelectedIndex / page->numCols) - page->listStart;

    if (selectedIndex < 2 || page->numRows < 9) {
        gPauseItemsTargetScrollIndex = 0;
    } else if (selectedIndex >= page->numRows - 2) {
        gPauseItemsTargetScrollIndex = page->numRows - 8;
    } else if (selectedIndex - gPauseItemsTargetScrollIndex > 6) {
        gPauseItemsTargetScrollIndex = selectedIndex - 6;
    } else if (selectedIndex - gPauseItemsTargetScrollIndex < 1) {
        gPauseItemsTargetScrollIndex = selectedIndex - 1;
    }

    gPauseItemsTargetScrollPos = pause_items_get_pos_y(gPauseItemsCurrentPage, gPauseItemsTargetScrollIndex * page->numCols);
    gPauseItemsCurrentScrollPos += pause_interp_vertical_scroll(gPauseItemsTargetScrollPos - gPauseItemsCurrentScrollPos);
}

void pause_items_cleanup(MenuPanel* panel) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPauseItemsIconIDs); i++) {
        hud_element_free(gPauseItemsIconIDs[i]);
    }
}
