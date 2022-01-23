#include "common.h"
#include "hud_element.h"

typedef struct {
    HudScript* q1;
    HudScript* q2;
} HudElStruct;

extern HudScript HudScript_StatBp;
extern HudScript HudScript_ListPrevPage;
extern HudScript HudScript_ListNextPage;
extern HudScript HudScript_Dash;
extern HudScript HudScript_StatusStar1;
extern u32 D_802705C4;
extern s32 D_8026FCF0;
extern s32 D_80270634;
extern HudElStruct gItemHudScripts[];
extern s32 D_8026FCB8;

void pause_items_draw_contents(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void pause_items_init(MenuPanel* panel);
void pause_items_handle_input(MenuPanel* panel);
void pause_items_update(MenuPanel* panel);
void pause_items_cleanup(MenuPanel* panel);

HudScript* D_8024F570[] = { HudScript_StatBp, HudScript_StatBp, HudScript_StatBp, HudScript_StatBp, HudScript_StatBp,
                            HudScript_StatBp, HudScript_StatBp, HudScript_StatBp, HudScript_StatBp, HudScript_StatBp,
                            HudScript_StatBp, HudScript_StatBp, HudScript_StatBp, HudScript_StatBp, HudScript_StatBp,
                            HudScript_StatBp, HudScript_ListPrevPage, HudScript_ListNextPage, HudScript_Dash,
                            HudScript_StatusStar1 };
MenuWindowBP D_8024F5C0[] = { { .windowID = 33,
                                         .unk_01 = 0,
                                         .pos = { .x = 3,
                                                  .y = 16 },
                                         .height = 289,
                                         .width = 154,
                                         .unk_0A = { 1, 0},
                                         .fpDrawContents = &pause_items_draw_contents,
                                         .tab = NULL,
                                         .parentID = 0x16000000,
                                         .fpUpdate = 2,
                                         .unk_1C = 0,
                                         .style = 0x8026FD28 } };
MenuPanel D_8024F5E4 = { .unk_00 = {
                            .s = 0 },
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

void pause_items_draw_contents(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
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
    s32 msg, dx, dy, opacity;
    s32 posX1, posY1;
    s32 offsetX, offsetY;

    sp60 = 1;
    sp64 = 0xA;
    sp5C = gItemMenuSelectedIndex / gItemMenuPages[gItemMenuCurrentPage].numCols;
    sp58 = gItemMenuSelectedIndex % gItemMenuPages[gItemMenuCurrentPage].numCols;
    draw_box(4, &D_8026FCF0, arg1 + 0x44, arg2, 0, arg3 - 0x44, arg4, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x140, 0xF0, 0);

    x1 = arg1 + 1;
    y1 = arg2 + 7;
    x2 = arg1 + arg3 - 1;
    y2 = arg2 + arg4 - 7;

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
    sp6C = arg1 + 0x77;
    sp70 = arg2 + 0x11;

    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, x1, y1, x2, y2);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 20; j++) {
            iconIDs = gItemIcons;

            sp7C = &gItemMenuPages[j];
            if (!sp7C->enabled) {
                break;
            }

            pause_items_get_pos_y(j, 0);

            for (k = 0; k < sp7C->count; k++) {
                itemID = gItemMenuItemIDs[sp7C->startIndex + k];
                s5 = FALSE;
                if (itemID == 0x7FFF) {
                    continue;
                }

                posX = pause_items_get_pos_x(j, k);
                posY = pause_items_get_pos_y(j, k);

                sp74 = itemID == 0x7FFE;

                if (gPauseMenuCurrentTab == 3 &&
                    gItemMenuLevel  == 1 &&
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
                        el = D_80270634;
                    } else {
                        if (s5) {
                            set_hud_element_flags(el, 0x20000000);
                            gPauseMenuCurrentDescIconScript = gItemHudScripts[gItemTable[itemID].iconID].q1;
                        }

                        set_hud_element_anim(el, gItemHudScripts[gItemTable[itemID].iconID].q1);
                        set_hud_element_scale(el, 0.670816f);
                    }

                    set_hud_element_render_pos(el, arg1 + 0x69 + pause_items_scroll_offset_x(posX) + s2,
                                                arg2 + 0x17 + pause_items_scroll_offset_y(posY) + s4);
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

    x1 = arg1 + 1;
    y1 = arg2 + 1;
    x2 = arg1 + arg3 - 1;
    y2 = arg2 + arg4 - 1;
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

    if (gPauseMenuCurrentTab == 3 && gItemMenuLevel == 1) {
        if (gItemMenuCurrentPage > 0) {
            set_hud_element_render_pos(gItemIcons[16], arg1 + 278, arg2 + 14);
            draw_hud_element_3(gItemIcons[16]);
        }

        if (gItemMenuPages [gItemMenuCurrentPage + 1].enabled) {
            set_hud_element_render_pos(gItemIcons[17], arg1 + 278, arg2 + 146);
            draw_hud_element_3(gItemIcons[17]);
        }
    }

    draw_box(4, &D_8026FCB8, gItemMenuCurrentTab == 0 ? arg1 + 9 : arg1, arg2 + 7, 0,
         0x5B, 0x22, 0xFF, gItemMenuCurrentTab == 1 ? 0x80 : 0x00, 0, 0,
         0, 0, 0, 0, 0, 0, 0x140, 0xF0, 0);

    msg = pause_get_menu_msg(0x4F);
    dx = arg1 + 12;
    if (gItemMenuCurrentTab == 0) {
        dx = arg1 + 21;
    }
    opacity = 0xFF;
    dy = arg2 + 0x11;
    if (gItemMenuCurrentTab == 1) {
        opacity = 0xBF;
    }
    draw_msg(msg, dx, dy, opacity, 0, 1);

    draw_box(4, &D_8026FCB8, gItemMenuCurrentTab == 1 ? arg1 + 9 : arg1, arg2 + 0x27, 0,
         0x5B, 0x22, 0xFF, gItemMenuCurrentTab == 0 ? 0x80 : 0x00, 0, 0,
         0, 0, 0, 0, 0, 0, 0x140, 0xF0, 0);

    msg = pause_get_menu_msg(0x50);
    dx = arg1 + 0x19;
    if (gItemMenuCurrentTab == 1) {
        dx = arg1 + 0x22;
    }
    opacity = 0xFF;
    dy = arg2 + 0x31;
    if (gItemMenuCurrentTab == 0) {
        opacity = 0xBF;
    }
    draw_msg(msg, dx, dy, opacity, 0, 1);

    if (gPauseMenuCurrentTab == 3) {
         if (gItemMenuLevel  == 0) {
             func_80242D04(0x21, arg1 + 0xC , arg2 + 0x1A + gItemMenuCurrentTab  * 32);
         } else {
             posX1 = pause_items_get_pos_x(gItemMenuCurrentPage, gItemMenuSelectedIndex  - gItemMenuPages[gItemMenuCurrentPage].listStart * gItemMenuPages[gItemMenuCurrentPage].numCols);
             posY1 = pause_items_get_pos_y(gItemMenuCurrentPage, gItemMenuSelectedIndex  - gItemMenuPages[gItemMenuCurrentPage].listStart * gItemMenuPages[gItemMenuCurrentPage].numCols);
             offsetX = pause_items_scroll_offset_x(posX1);
             offsetY = pause_items_scroll_offset_y(posY1);
             if (offsetY < 0) {
                 offsetY = 0;
             } else if (offsetY > 112) {
                 offsetY = 112;
             }

             if (gItemMenuCurrentScrollPos  != gItemMenuTargetScrollPos) {
                 func_80242BAC(0x21, arg1 + 0x55 + offsetX, arg2 + 0x17 + offsetY);
             } else {
                 func_80242D04(0x21, arg1 + 0x55 + offsetX, arg2 + 0x17 + offsetY);
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
                gItemMenuItemIDs[totalItems] = playerData->invItems[i];
                totalItems++;
            }
        }
    } else {
        for (i = 0; i < ARRAY_COUNT(playerData->keyItems); i++) {
            if (playerData->keyItems[i] != 0) {
                gItemMenuItemIDs[totalItems] = playerData->keyItems[i];
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

    for (i = totalItems; i < 100; i++) {
        gItemMenuItemIDs[i] = 0x7FFF;
    }

    page = &gItemMenuPages;
    gItemMenuSelectedIndex = 0;
    gItemMenuSelectedItemID = 0;
    D_802705C4 = 0;
    D_802705DC = 0;
    gItemMenuCurrentPage = 0;

    for (i = 0; i < gItemMenuNumItems / 8; i++, page++) {
        page->listStart = i * 8;
        page->numCols = 1;
        page->numRows = 8;
        page->enabled = TRUE;
        page->startIndex =  i * 8;
        page->count = 8;
    }

    if ((gItemMenuNumItems % 8) != 0) {
        page->listStart = i * 8;
        page->numCols = 1;
        page->enabled = TRUE;
        page->startIndex = i * 8;
        page->count = gItemMenuNumItems % 8;
        page->numRows = page->count;
        i++;
        page++;
    }

    for (; i < ARRAY_COUNT(gItemMenuPages); i++, page++) {
        page->enabled = FALSE;
    }

    gItemMenuTargetScrollPos = gItemMenuCurrentScrollPos = pause_items_get_pos_y(0, 0);
}

void pause_items_init(MenuPanel* panel) {
    s32 i;

    gItemMenuLevel = 0;
    gItemMenuCurrentTab = 0;
    pause_items_load_items(FALSE);

    for (i = 0; i < ARRAY_COUNT(gItemIcons); i++) {
        gItemIcons[i] = create_hud_element(D_8024F570[i]);
        set_hud_element_flags(gItemIcons[i], 0x80);
    }

    for (i = 0; i < ARRAY_COUNT(D_8024F5C0); i++) {
        D_8024F5C0[i].tab = panel;
    }

    setup_pause_menu_tab(&D_8024F5C0, 1);
    panel->unk_00.c.initialized = TRUE;
}

void pause_items_handle_input(MenuPanel* panel) {
    s32 oldTab;
    s32 oldSelectedIndex = gItemMenuSelectedIndex;
    s32 row = gItemMenuSelectedIndex / gItemMenuPages[gItemMenuCurrentPage].numCols;
    s32 column = gItemMenuSelectedIndex % gItemMenuPages[gItemMenuCurrentPage].numCols;

    if ((gPauseMenuPressedButtons & BUTTON_A) && gItemMenuLevel == 0) {
        if (gItemMenuItemIDs[gItemMenuSelectedIndex] == 0x7FFE) {
            sfx_play_sound(0x21D);
        } else {
            gItemMenuLevel = 1;
            sfx_play_sound(0xC9);
        }

        return;
    }

    if (gItemMenuNumItems != 0) {
        if (gItemMenuLevel == 0) {
            oldTab = gItemMenuCurrentTab;
            if (gPauseMenuHeldButtons & (BUTTON_STICK_UP|BUTTON_STICK_DOWN)) {
                gItemMenuCurrentTab ^= 1;
            }

            if (oldTab != gItemMenuCurrentTab) {
                sfx_play_sound(0xC8);
                pause_items_load_items(gItemMenuCurrentTab);
            }
        } else {
            if (gPauseMenuHeldButtons & (BUTTON_STICK_UP|BUTTON_Z)) {
                row--;
                if (gPauseMenuHeldButtons & BUTTON_STICK_UP) {
                    if (row < 0) {
                        row = 0;
                    }

                    if (row < gItemMenuPages[gItemMenuCurrentPage].listStart) {
                        gItemMenuCurrentPage--;
                    }
                } else {
                    gItemMenuCurrentPage--;
                    if (gItemMenuCurrentPage < 0) {
                        gItemMenuCurrentPage = 0;
                    }
                    row = gItemMenuPages[gItemMenuCurrentPage].listStart;
                }
            }

            if (gPauseMenuHeldButtons & (BUTTON_STICK_DOWN|BUTTON_R)) {
                if (gPauseMenuHeldButtons & BUTTON_STICK_DOWN) {
                    row++;
                    if (row >= gItemMenuPages[gItemMenuCurrentPage].listStart + gItemMenuPages[gItemMenuCurrentPage].numRows) {
                        gItemMenuCurrentPage++;

                        if (!gItemMenuPages[gItemMenuCurrentPage].enabled) {
                            gItemMenuCurrentPage--;
                            row--;
                        }
                    }
                } else {
                    gItemMenuCurrentPage++;

                    if (!gItemMenuPages[gItemMenuCurrentPage].enabled) {
                        gItemMenuCurrentPage--;
                    } else {
                        row = gItemMenuPages[gItemMenuCurrentPage].listStart;
                    }
                }
            }

            if (gItemMenuItemIDs[row * gItemMenuPages[gItemMenuCurrentPage].numCols] != 0x7FFE) {
                if (gPauseMenuHeldButtons & BUTTON_STICK_LEFT) {
                    column--;

                    if (column < 0) {
                        column = gItemMenuPages[gItemMenuCurrentPage].numCols - 1;
                    }
                } else if (gPauseMenuHeldButtons & BUTTON_STICK_RIGHT) {
                    column++;
                    if (column >= gItemMenuPages[gItemMenuCurrentPage].numCols) {
                        column = 0;
                    }
                }
            } else {
                column = 0;
            }

            gItemMenuSelectedIndex = column + row * gItemMenuPages[gItemMenuCurrentPage].numCols;
            if (gItemMenuSelectedIndex != oldSelectedIndex) {
                sfx_play_sound(0xC7);
            }

            gItemMenuSelectedItemID = gItemMenuItemIDs[gItemMenuSelectedIndex];
        }
    }

    if (gItemMenuLevel == 1) {
        if (gItemMenuSelectedItemID != 0x7FFE && gItemMenuSelectedItemID != 0x7FFF && gItemMenuSelectedItemID != 0) {
            gPauseMenuCurrentDescMsg = gItemTable[gItemMenuSelectedItemID].menuMsg;
        } else {
            gPauseMenuCurrentDescMsg = 0;
            gPauseMenuCurrentDescIconScript  = NULL;
        }
    } else {
        if (gItemMenuCurrentTab == 1) {
            gPauseMenuCurrentDescMsg = pause_get_menu_msg(0x51);
        } else {
            gPauseMenuCurrentDescMsg = pause_get_menu_msg(0x52);
        }

        gPauseMenuCurrentDescIconScript = NULL;
    }

    if (gPauseMenuPressedButtons & BUTTON_B) {
        if (gItemMenuLevel == 0) {
            sfx_play_sound(0xCA);
            gPauseMenuCurrentTab = 0;
        } else {
            sfx_play_sound(0xCA);
            gItemMenuLevel = 0;
        }
    }
}

void pause_items_update(MenuPanel* panel) {
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

void pause_items_cleanup(MenuPanel* panel) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gItemIcons); i++) {
        free_hud_element(gItemIcons[i]);
    }
}
