#include "pause_common.h"

void pause_items_init(MenuPanel* panel);
void pause_items_handle_input(MenuPanel* panel);
void pause_items_update(MenuPanel* panel);
void pause_items_cleanup(MenuPanel* panel);

HudScript* D_8024F570[] = {
    HudScript_StatBp, HudScript_StatBp, HudScript_StatBp, HudScript_StatBp, HudScript_StatBp,
    HudScript_StatBp, HudScript_StatBp, HudScript_StatBp, HudScript_StatBp, HudScript_StatBp,
    HudScript_StatBp, HudScript_StatBp, HudScript_StatBp, HudScript_StatBp, HudScript_StatBp,
    HudScript_StatBp, HudScript_ListPrevPage, HudScript_ListNextPage, HudScript_Dash,
    HudScript_StatusStar1 };
MenuWindowBP D_8024F5C0[] = { { .windowID = WINDOW_ID_33,
                                         .unk_01 = 0,
                                         .pos = { .x = 3,
                                                  .y = 16 },
                                         .width = 289,
                                         .height = 154,
                                         .unk_0A = { 1, 0},
                                         .fpDrawContents = &pause_items_draw_contents,
                                         .tab = NULL,
                                         .parentID = WINDOW_ID_PAUSE_MAIN,
                                         .fpUpdate = { 2 },
                                         .unk_1C = 0,
                                         .style = &gPauseWS_19 } };
MenuPanel gPausePanelItems = { .initialized = FALSE, .col = 0, .row = 0, .selected = 0,
                         .page = 0,
                         .numCols = 0,
                         .numRows = 0,
                         .numPages = 0,
                         .gridData = NULL,
                         .fpInit = &pause_items_init,
                         .fpHandleInput = &pause_items_handle_input,
                         .fpUpdate = &pause_items_update,
                         .fpCleanup = &pause_items_cleanup };

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

void pause_items_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    s32 i, j, k;
    s32 sp54;
    s32 sp58;
    s32 sp5C;
    s32 sp60;
    s32 sp64;
    s32 posX, posY;
    s32 sp6C;
    s32 sp70;
    s32 sp74;
    s32* sp78;
    PauseItemPage* sp7C;
    s32 x1, y1, x2, y2;
    s16 itemID;
    s32 s5, s2, s4;
    s32* iconIDs;
    s32 el;
    s32 msg, dx, dy, opacity1;
    s32 posX1, posY1;
    s32 offsetX, offsetY;

    sp60 = 1;
    sp64 = 0xA;
    sp5C = gPauseItemsSelectedIndex / gPauseItemsPages[gPauseItemsCurrentPage].numCols;
    sp58 = gPauseItemsSelectedIndex % gPauseItemsPages[gPauseItemsCurrentPage].numCols;
    draw_box(4, &gPauseWS_18, baseX + 0x44, baseY, 0, width - 0x44, height, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x140, 0xF0, 0);

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

    if (x2 <= 0 || y2 <= 0 || x1 >= 319 || y1 >= 239) {
        return;
    }

    if (x2 >= 319) {
        x2 = 319;
    }
    if (y2 >= 239) {
        y2 = 239;
    }

    sp54 = 0;
    sp6C = baseX + 0x77;
    sp70 = baseY + 0x11;

    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, x1, y1, x2, y2);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 20; j++) {
            iconIDs = gPauseItemsIconIDs;

            sp7C = &gPauseItemsPages[j];
            if (!sp7C->enabled) {
                break;
            }

            pause_items_get_pos_y(j, 0);

            for (k = 0; k < sp7C->count; k++) {
                itemID = gPauseItemsItemIDs[sp7C->startIndex + k];
                s5 = FALSE;
                if (itemID == 0x7FFF) {
                    continue;
                }

                posX = pause_items_get_pos_x(j, k);
                posY = pause_items_get_pos_y(j, k);

                sp74 = itemID == 0x7FFE;

                if (gPauseMenuCurrentTab == 3 &&
                    gPauseItemsLevel  == 1 &&
                    pause_items_get_column(j, k) == sp58 &&
                    pause_items_get_row(j, k) == sp5C) {
                    s5 = TRUE;
                }

                s2 = 0;
                s4 = 0;
                if (s5) {
                    s2 = -1;
                    s4 = -1;
                }

                if (i == 0) {
                    sp60 = 1;
                    sp64 = 10;

                    if (s5) {
                        sp60 = 9;
                    }
                }

                if (!pause_items_is_visible(posY)) {
                    continue;
                }

                if (i == 0) {
                    if (sp74) {
                        draw_msg(pause_get_menu_msg(0x4E), sp6C + pause_items_scroll_offset_x(posX) + s2,
                                sp70 + pause_items_scroll_offset_y(posY) + s4, 0xFF, sp64, sp60);
                    } else {
                        if (gItemTable[itemID].nameMsg) {
                            if (gItemTable[itemID].nameMsg > 0) {
                                draw_msg(gItemTable[itemID].nameMsg, sp6C + pause_items_scroll_offset_x(posX) + s2,
                                        sp70 + pause_items_scroll_offset_y(posY) + s4, 0xFF, sp64, sp60);
                            }
                        }
                    }
                }

                if (i == 1) {

                    el = iconIDs[sp54];
                    clear_hud_element_flags(el, 0x20000000);
                    set_hud_element_flags(el, 0x8000);
                    if (sp74) {
                        el = gPauseItemsIconIDs[19];
                    } else {
                        if (s5) {
                            set_hud_element_flags(el, 0x20000000);
                            gPauseCurrentDescIconScript = gItemHudScripts[gItemTable[itemID].iconID].enabled;
                        }

                        set_hud_element_anim(el, gItemHudScripts[gItemTable[itemID].iconID].enabled);
                        set_hud_element_scale(el, 0.670816f);
                    }

                    set_hud_element_render_pos(el, baseX + 0x69 + pause_items_scroll_offset_x(posX) + s2,
                                                baseY + 0x17 + pause_items_scroll_offset_y(posY) + s4);
                    if (sp54 == 0) {
                        draw_hud_element_3(el);
                    } else {
                        draw_hud_element_2(el);
                    }

                    sp54++;
                }
            }
        }
    }

    x1 = baseX + 1;
    y1 = baseY + 1;
    x2 = baseX + width - 1;
    y2 = baseY + height - 1;
    gDPPipeSync(gMasterGfxPos++);

    if (x1 <= 0) {
        x1 = 1;
    }
    if (y1 <= 0) {
        y1 = 1;
    }

    if (x2 <= 0 || y2 <= 0 || x1 >= 319 || y1 >= 239) {
        return;
    }

    if (x2 >= 319) {
        x2 = 319;
    }
    if (y2 >= 239) {
        y2 = 239;
    }

    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, x1, y1, x2, y2);

    if (gPauseMenuCurrentTab == 3 && gPauseItemsLevel == 1) {
        if (gPauseItemsCurrentPage > 0) {
            set_hud_element_render_pos(gPauseItemsIconIDs[16], baseX + 278, baseY + 14);
            draw_hud_element_3(gPauseItemsIconIDs[16]);
        }

        if (gPauseItemsPages [gPauseItemsCurrentPage + 1].enabled) {
            set_hud_element_render_pos(gPauseItemsIconIDs[17], baseX + 278, baseY + 146);
            draw_hud_element_3(gPauseItemsIconIDs[17]);
        }
    }

    draw_box(4, &gPauseWS_17, gPauseItemsCurrentTab == 0 ? baseX + 9 : baseX, baseY + 7, 0,
         0x5B, 0x22, 0xFF, gPauseItemsCurrentTab == 1 ? 0x80 : 0x00, 0, 0,
         0, 0, 0, 0, 0, 0, 0x140, 0xF0, 0);

    msg = pause_get_menu_msg(0x4F);
    dx = baseX + 12;
    if (gPauseItemsCurrentTab == 0) {
        dx = baseX + 21;
    }
    opacity1 = 0xFF;
    dy = baseY + 0x11;
    if (gPauseItemsCurrentTab == 1) {
        opacity1 = 0xBF;
    }
    draw_msg(msg, dx, dy, opacity1, 0, 1);

    draw_box(4, &gPauseWS_17, gPauseItemsCurrentTab == 1 ? baseX + 9 : baseX, baseY + 0x27, 0,
         0x5B, 0x22, 0xFF, gPauseItemsCurrentTab == 0 ? 0x80 : 0x00, 0, 0,
         0, 0, 0, 0, 0, 0, 0x140, 0xF0, 0);

    msg = pause_get_menu_msg(0x50);
    dx = baseX + 0x19;
    if (gPauseItemsCurrentTab == 1) {
        dx = baseX + 0x22;
    }
    opacity1 = 0xFF;
    dy = baseY + 0x31;
    if (gPauseItemsCurrentTab == 0) {
        opacity1 = 0xBF;
    }
    draw_msg(msg, dx, dy, opacity1, 0, 1);

    if (gPauseMenuCurrentTab == 3) {
         if (gPauseItemsLevel  == 0) {
             pause_set_cursor_pos(0x21, baseX + 0xC , baseY + 0x1A + gPauseItemsCurrentTab  * 32);
         } else {
             posX1 = pause_items_get_pos_x(gPauseItemsCurrentPage, gPauseItemsSelectedIndex  - gPauseItemsPages[gPauseItemsCurrentPage].listStart * gPauseItemsPages[gPauseItemsCurrentPage].numCols);
             posY1 = pause_items_get_pos_y(gPauseItemsCurrentPage, gPauseItemsSelectedIndex  - gPauseItemsPages[gPauseItemsCurrentPage].listStart * gPauseItemsPages[gPauseItemsCurrentPage].numCols);
             offsetX = pause_items_scroll_offset_x(posX1);
             offsetY = pause_items_scroll_offset_y(posY1);
             if (offsetY < 0) {
                 offsetY = 0;
             } else if (offsetY > 112) {
                 offsetY = 112;
             }

             if (gPauseItemsCurrentScrollPos  != gPauseItemsTargetScrollPos) {
                 pause_set_cursor_pos_immediate(0x21, baseX + 0x55 + offsetX, baseY + 0x17 + offsetY);
             } else {
                 pause_set_cursor_pos(0x21, baseX + 0x55 + offsetX, baseY + 0x17 + offsetY);
             }
         }
    }
}

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
            if (playerData->invItems[i] != 0) {
                gPauseItemsItemIDs[totalItems] = playerData->invItems[i];
                totalItems++;
            }
        }
    } else {
        for (i = 0; i < ARRAY_COUNT(playerData->keyItems); i++) {
            if (playerData->keyItems[i] != 0) {
                gPauseItemsItemIDs[totalItems] = playerData->keyItems[i];
                totalItems++;
            }
        }
    }

    if (totalItems == 0) {
        gPauseItemsItemIDs[0] = 0x7FFE;
        totalItems = 1;
    } else {
        pause_sort_item_list(gPauseItemsItemIDs, totalItems, pause_items_comparator);
    }

    gPauseItemsNumItems = totalItems;

    for (i = totalItems; i < 100; i++) {
        gPauseItemsItemIDs[i] = 0x7FFF;
    }

    page = gPauseItemsPages;
    gPauseItemsSelectedIndex = 0;
    gPauseItemsSelectedItem = 0;
    D_802705C4 = 0;
    D_802705DC = 0;
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
        gPauseItemsIconIDs[i] = create_hud_element(D_8024F570[i]);
        set_hud_element_flags(gPauseItemsIconIDs[i], 0x80);
    }

    for (i = 0; i < ARRAY_COUNT(D_8024F5C0); i++) {
        D_8024F5C0[i].tab = panel;
    }

    setup_pause_menu_tab(D_8024F5C0, 1);
    panel->initialized = TRUE;
}

void pause_items_handle_input(MenuPanel* panel) {
    s32 oldTab;
    s32 oldSelectedIndex = gPauseItemsSelectedIndex;
    s32 row = gPauseItemsSelectedIndex / gPauseItemsPages[gPauseItemsCurrentPage].numCols;
    s32 column = gPauseItemsSelectedIndex % gPauseItemsPages[gPauseItemsCurrentPage].numCols;

    if ((gPausePressedButtons & BUTTON_A) && gPauseItemsLevel == 0) {
        if (gPauseItemsItemIDs[gPauseItemsSelectedIndex] == 0x7FFE) {
            sfx_play_sound(0x21D);
        } else {
            gPauseItemsLevel = 1;
            sfx_play_sound(0xC9);
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
                sfx_play_sound(0xC8);
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

            if (gPauseItemsItemIDs[row * gPauseItemsPages[gPauseItemsCurrentPage].numCols] != 0x7FFE) {
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
                sfx_play_sound(0xC7);
            }

            gPauseItemsSelectedItem = gPauseItemsItemIDs[gPauseItemsSelectedIndex];
        }
    }

    if (gPauseItemsLevel == 1) {
        if (gPauseItemsSelectedItem != 0x7FFE && gPauseItemsSelectedItem != 0x7FFF && gPauseItemsSelectedItem != 0) {
            gPauseCurrentDescMsg = gItemTable[gPauseItemsSelectedItem].menuMsg;
        } else {
            gPauseCurrentDescMsg = 0;
            gPauseCurrentDescIconScript  = NULL;
        }
    } else {
        if (gPauseItemsCurrentTab == 1) {
            gPauseCurrentDescMsg = pause_get_menu_msg(0x51);
        } else {
            gPauseCurrentDescMsg = pause_get_menu_msg(0x52);
        }

        gPauseCurrentDescIconScript = NULL;
    }

    if (gPausePressedButtons & BUTTON_B) {
        if (gPauseItemsLevel == 0) {
            sfx_play_sound(0xCA);
            gPauseMenuCurrentTab = 0;
        } else {
            sfx_play_sound(0xCA);
            gPauseItemsLevel = 0;
        }
    }
}

void pause_items_update(MenuPanel* panel) {
    PauseItemPage* menuPage = &gPauseItemsPages[gPauseItemsCurrentPage];
    s32 selectedIndex = (gPauseItemsSelectedIndex / menuPage->numCols) - menuPage->listStart;

    if (selectedIndex < 2 || menuPage->numRows < 9) {
        D_802705DC = 0;
    } else if (selectedIndex >= (menuPage->numRows - 2)) {
        D_802705DC = menuPage->numRows - 8;
    } else if ((selectedIndex - D_802705DC) > 6) {
        D_802705DC = selectedIndex - 6;
    } else if ((selectedIndex - D_802705DC) < 1) {
        D_802705DC = selectedIndex - 1;
    }

    gPauseItemsTargetScrollPos = pause_items_get_pos_y(gPauseItemsCurrentPage, D_802705DC * menuPage->numCols);
    gPauseItemsCurrentScrollPos += pause_interp_vertical_scroll(gPauseItemsTargetScrollPos - gPauseItemsCurrentScrollPos);
}

void pause_items_cleanup(MenuPanel* panel) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPauseItemsIconIDs); i++) {
        free_hud_element(gPauseItemsIconIDs[i]);
    }
}
