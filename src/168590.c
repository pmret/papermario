#include "common.h"
#include "filemenu.h"
#include "hud_element.h"

typedef struct UnkStruct8015A370 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk_01[0x3];
    /* 0x04 */ void (*unk_04)(s32);
    /* 0x08 */ char unk_08[0x14];
    /* 0x1C */ u8 unk_1C;
} UnkStruct8015A370;

extern UnkStruct8015A370 D_8015A370;

extern MenuWindowBP D_8024A134[1];
extern HudScript* D_8024A180[3];
extern s32 D_8024A18C;
extern s32 D_8024C108;
extern MenuWindowBP D_8024A190[2];
extern s32 D_8024A1B4;
extern s8 D_8024C090;
extern s32 D_8024C100_C09980[3];
extern u8 D_8024C117;

void filemenu_info_draw_message_contents(MenuPanel* menu, s32 baseX, s32 baseY) {
    switch (menu->page) {
        case 0:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_26), baseX + 10, baseY + 4, 255, 0, 0);
            draw_number(filemenu_menus[0]->selected + 1, baseX + 48, baseY + 6, 0, 0, 255, 3);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_HAS_BEEN_DELETED), baseX + 49, baseY + 4, 255, 0, 0);
            break;
        case 2:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_COPY_FROM), baseX + 10, baseY + 4, 255, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_26), baseX + 84, baseY + 4, 255, 0, 0);
            draw_number(filemenu_loadedFileIdx + 1, baseX + 122, baseY + 6, 0, 0, 255, 3);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_TO), baseX + 10, baseY + 18, 255, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_26), baseX + 30, baseY + 18, 255, 0, 0);
            draw_number(filemenu_iterFileIdx + 1, baseX + 68, baseY + 20, 0, 0, 255, 3);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_PERIOD_34), baseX + 65, baseY + 18, 255, 0, 0);
            break;
        case 1:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_28), baseX + 10, baseY + 4, 255, 0, 0);
            break;
        case 3:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_26), baseX + 10, baseY + 4, 255, 0, 0);
            draw_number(filemenu_menus[0]->selected + 1, baseX + 48, baseY + 6, 0, 0, 255, 3);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_HAS_BEEN_CREATED), baseX + 49, baseY + 4, 255, 0, 0);
            break;
    }
    filemenu_set_cursor_alpha(0);
}

void filemenu_info_init(MenuPanel* tab) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8024A134); i++) {
        D_8024A134[i].tab = tab;
    }

    setup_pause_menu_tab(D_8024A134, ARRAY_COUNT(D_8024A134));
    tab->initialized = TRUE;
}

void filemenu_info_handle_input(void) {
    if (filemenu_pressedButtons & (BUTTON_A | BUTTON_B)) {
        MenuPanel* menu = filemenu_menus[0];

        filemenu_8024C098 = 0;

        switch (menu->page) {
            case 1:
                menu->page = 0;
                set_window_update(WINDOW_ID_51, (s32)filemenu_update_show_options_left);
                set_window_update(WINDOW_ID_52, (s32)filemenu_update_show_options_right);
                set_window_update(WINDOW_ID_53, (s32)filemenu_update_show_options_bottom);
                set_window_update(WINDOW_ID_55, (s32)filemenu_update_show_options_bottom);
                filemenu_set_selected(menu, 0, 2);
                break;
            case 4:
                menu->page = 0;
                set_window_update(WINDOW_ID_51, (s32)filemenu_update_show_options_left);
                set_window_update(WINDOW_ID_52, (s32)filemenu_update_show_options_right);
                set_window_update(WINDOW_ID_53, (s32)filemenu_update_show_options_bottom);
                set_window_update(WINDOW_ID_55, (s32)filemenu_update_show_options_bottom);
                filemenu_set_selected(menu, 1, 2);
                break;
            case 2:
                menu->page = 2;
                filemenu_set_selected(menu, 1, 2);
                break;
        }
        set_window_update(WINDOW_ID_47, WINDOW_UPDATE_HIDE);
    }
}

void filemenu_info_update(void) {
}

void filemenu_info_cleanup(void) {
}

void func_80248170(s32 idx) {
    Window* window = &gWindows[idx];

    if (window->updateCounter == 8) {
        window->flags &= ~WINDOW_FLAGS_INITIAL_ANIMATION;
        set_window_update(idx, WINDOW_UPDATE_SHOW);
    }
}

void filemenu_draw_contents_file_create_header(MenuPanel* menu, s32 baseX, s32 baseY) {
    s32 xOffset;
    s32 yOffset;
    s32 i;
    s32 tempAmt;

    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_ENTER_A_FILE_NAME), baseX + 10, baseY + 6, 255, 0, 0);
    filemenu_draw_file_name(filemenu_8024C110, 8, baseX + 36, baseY + 22, 255, 0, 0, 0xB);
    xOffset = 41;

    for (i = 0; i < 8; i++) {
        hud_element_set_render_pos(D_8024C100_C09980[1], baseX + 42 + (i * 11), baseY + xOffset);
        if (i == 0) {
            hud_element_draw_without_clipping(D_8024C100_C09980[1]);
        } else {
            hud_element_draw_next(D_8024C100_C09980[1]);
        }
    }

    tempAmt = 8;
    if (filemenu_8024C098 == 3) {
        s32 phi_v0 = 122;

        if (D_8024C090 != tempAmt) {
            phi_v0 = (D_8024C090 * 11) + 45;
        }
        hud_element_set_render_pos(D_8024C100_C09980[0], baseX + phi_v0, baseY + 45);
        hud_element_draw_next(D_8024C100_C09980[0]);
    }
}

void filemenu_draw_contents_choose_name(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);

#ifdef NON_MATCHING
void filemenu_draw_contents_choose_name(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity,
                                        s32 darkening)
{
    s32 sp18;
    s32 menuPage;
    s32 pageNotOne;
    s32 page;
    s32 temp_s2;
    s32 new_var;

    s32 gridData;
    s32 xOffset;
    s32 yOffset;
    s32 color;
    s32 flags;
    s32 i;
    s32 r;
    s32 c;

    s32 new_var2;

    if ((D_8015A370.unk_00 & 8) && D_8015A370.unk_04 == func_80248170) {
        sp18 = D_8015A370.unk_1C * 2;
        menuPage = menu->page;
        pageNotOne = menu->page != 1;
        if (sp18 > 0x10) {
            sp18 = 0x10;
        }

        for (r = 0; r < menu->numRows; r++) {
            temp_s2 = (r * 15); // ???

            for (i = 0; i < 2; i++) {
                if (i == 0) {
                    temp_s2 += 4;
                    page = menuPage;
                    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE,
                                  baseX,
                                  baseY + temp_s2,
                                  baseX + width,
                                  baseY + temp_s2 + sp18);
                } else {
                    temp_s2 += 4;
                    page = pageNotOne;
                    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE,
                                  baseX,
                                  baseY + temp_s2 + sp18,
                                  baseX + width,
                                  baseY + temp_s2 + 0x10);
                }

                for (c = 0; c < menu->numCols; c++) {
                    gridData = menu->gridData[(page * menu->numCols * menu->numRows) + (menu->numCols * r) + c];
                    if (gridData != 0xF7) {
                        if (r == menu->col && c == menu->row) {
                            flags = 8;
                            color = 0;
                        } else {
                            flags = 0;
                            color = 10;
                        }
                        xOffset = (c * 19) + 12;
                        yOffset = (r * 17) + 5;
                        if ((u32) (gridData - 0xA2) < 0x4EU) {
                            if (gridData >= 0xC6) {
                                hud_element_set_render_pos(D_8024C108, baseX + xOffset + 22, baseY + yOffset + 8);
                                hud_element_draw_without_clipping(D_8024C108);
                                flags = 0;
                            }
                        }
                        if (gridData == 0xC6) {
                            xOffset -= 1;
                        }
                        if (gridData == 0xC9) {
                            xOffset += 5;
                        }
                        if (gridData == 0xCA) {
                            xOffset += 8;
                        }
                        if (gridData == 0xC6 || gridData == 0xCA || gridData == 0xC9) {
                            yOffset -= 1;
                        }
                        filemenu_draw_message((Message* ) gridData, baseX + xOffset, baseY + yOffset, 255, color, flags);
                    }
                }
            }
        }
        gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, baseX, baseY, baseX + width, baseY + height);
    } else {
        for (r = 0; r < menu->numCols; r++) {
            for (c = 0; c < menu->numRows; c++) {
                gridData = menu->gridData[(menu->page * menu->numCols * menu->numRows) + (menu->numCols * c) + r];
                if (gridData != 0xF7) {
                    if (r == menu->col && c == menu->row) {
                        flags = 8;
                        color = 0;
                    } else {
                        flags = 0;
                        color = 10;
                    }
                    xOffset = (r * 19) + 12;
                    yOffset = (c * 17) + 5;

                    new_var2 = gridData; // ???

                    if ((u32) (gridData - 0xA2) < 0x4EU) {
                        if (gridData >= 0xC6) {
                            hud_element_set_render_pos(D_8024C108, baseX + xOffset + 22, baseY + yOffset + 8);
                            hud_element_draw_without_clipping(D_8024C108);
                            flags = 0;
                        }
                    }
                    if (gridData == 0xC6) {
                        xOffset -= 1;
                    }
                    if (gridData == 0xC9) {
                        xOffset += 5;
                    }
                    if (gridData == 0xCA) {
                        xOffset += 8;
                    }
                    if (gridData == 0xC6 || gridData == 0xCA || gridData == 0xC9) {
                        yOffset -= 1;
                    }
                    filemenu_draw_message((Message* ) new_var2, baseX + xOffset, baseY + yOffset, 255, color, flags);
                }
            }
        }
    }

    if (filemenu_8024C098 == 3) {
        if (filemenu_heldButtons & (BUTTON_STICK_RIGHT | BUTTON_STICK_LEFT | BUTTON_STICK_DOWN | BUTTON_STICK_UP)) {
            D_8024A18C = -4;
        }
        D_8024A18C += 1;
        filemenu_set_cursor_goal_pos(0x31, baseX + 2 + (menu->col * 19), baseY + 13 + (menu->row * 17));
    }
}
#else
INCLUDE_ASM(s32, "168590", filemenu_draw_contents_choose_name);
#endif

void filemenu_choose_name_init(MenuPanel* menu) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8024A180); i++) {
        D_8024C100_C09980[i] = hud_element_create(D_8024A180[i]);
        hud_element_set_flags(D_8024C100_C09980[i], HUD_ELEMENT_FLAGS_80);
    }

    for (i = 0; i < ARRAY_COUNT(D_8024A190); i++) {
        D_8024A190[i].tab = menu;
    }

    setup_pause_menu_tab(D_8024A190, 2);

    gWindows[48].pos.x = ((gWindows[48].parent != -1)
                        ? (gWindows[gWindows[48].parent].width / 2)
                        : SCREEN_WIDTH / 2) - gWindows[48].width / 2;

    gWindows[49].pos.x = ((gWindows[49].parent != -1)
                        ? (gWindows[gWindows[49].parent].width / 2)
                        : SCREEN_WIDTH / 2) - gWindows[49].width / 2;

    menu->initialized = TRUE;
}

void filemenu_choose_name_handle_input(MenuPanel* menu) {
    s32 oldSelected = menu->selected;
    MenuPanel* newMenu;
    MenuPanel* newMenu2;
    s32 temp;
    s32 i;

    if (filemenu_heldButtons & BUTTON_STICK_LEFT) {
        menu->col--;
        if (menu->col < 0) {
            menu->col = menu->numCols - 1;
        }
    } else if (filemenu_heldButtons & BUTTON_STICK_RIGHT) {
        menu->col++;
        if (menu->col >= menu->numCols) {
            menu->col = 0;
        }
        if (menu->row == menu->numRows - 1) {
            if (menu->col > 10) {
                menu->col = 0;
            } else if (menu->col == 8 || menu->col == 9) {
                menu->col = 10;
            } else if (menu->col == 5 || menu->col == 6) {
                menu->col = 7;
            }
        }
    }

    if (filemenu_heldButtons & BUTTON_STICK_UP) {
        menu->row--;
        if (menu->row < 0) {
            menu->row = menu->numRows - 1;
        }
    } else if (filemenu_heldButtons & BUTTON_STICK_DOWN) {
        menu->row++;
        if (menu->row >= menu->numRows) {
            menu->row = 0;
        }
    }

    if (menu->row == menu->numRows - 1) {
        if (menu->col > 10) {
            menu->col = 10;
        } else if (menu->col == 8 || menu->col == 9) {
            menu->col = 7;
        } else if (menu->col == 5 || menu->col == 6) {
            menu->col = 4;
        }
    }

    menu->selected = MENU_PANEL_SELECTED_GRID_DATA(menu);
    if (oldSelected != menu->selected) {
        sfx_play_sound(SOUND_2102);
    }

    if (filemenu_pressedButtons & BUTTON_A) {
        switch (menu->selected) {
            case 0xC6:
                sfx_play_sound(SOUND_2103);
                if (D_8024C090 == ARRAY_COUNT(filemenu_8024C110)) {
                    D_8024C090 = ARRAY_COUNT(filemenu_8024C110) - 1;
                }
                filemenu_8024C110[D_8024C090] = 0xF7;
                D_8024C090++;
                if (D_8024C090 > ARRAY_COUNT(filemenu_8024C110)) {
                    D_8024C090 = ARRAY_COUNT(filemenu_8024C110);
                }
                break;
            case 0xC9:
                break;
            case 0xC7:
                if (menu->page != 1) {
                    sfx_play_sound(SOUND_2105);
                    menu->page = 1;
                    filemenu_set_selected(menu, menu->col, menu->row);
                    set_window_update(WINDOW_ID_49, (s32)func_80248170);
                }
                break;
            case 0xC8:
                if (menu->page != 0) {
                    sfx_play_sound(SOUND_2105);
                    menu->page = 0;
                    filemenu_set_selected(menu, menu->col, menu->row);
                    set_window_update(WINDOW_ID_49, (s32)func_80248170);
                }
                break;
            case 0xCA:
                for (i = 0; i < ARRAY_COUNT(filemenu_8024C110); i++) {
                    if (filemenu_8024C110[i] != 0xF7) {
                        break;
                    }
                }
                if (i == ARRAY_COUNT(filemenu_8024C110)) {
                    sfx_play_sound(SOUND_MENU_ERROR);
                    break;
                }

                sfx_play_sound(SOUND_MENU_NEXT);
                set_window_update(WINDOW_ID_50, (s32) filemenu_update_show_name_confirm);
                gWindows[50].pos.y = 121;
                gWindows[50].width = 69;
                gWindows[50].height = 44;
                gWindows[50].pos.x = ((gWindows[50].parent != -1)
                                    ? (gWindows[gWindows[50].parent].width / 2)
                                    : SCREEN_WIDTH / 2) - gWindows[50].width / 2;

                gWindows[46].pos.y = -70;
                gWindows[46].width = 164;
                gWindows[46].height = 62;
                gWindows[46].pos.x = ((gWindows[46].parent != -1)
                                    ? (gWindows[gWindows[46].parent].width / 2)
                                    : SCREEN_WIDTH / 2) - gWindows[46].width / 2;

                filemenu_8024C098 = 1;
                newMenu = filemenu_menus[filemenu_8024C098];
                newMenu->page = 2;
                filemenu_set_selected(newMenu, 0, 0);
                return;
            default:
                sfx_play_sound(SOUND_2103);
                if (D_8024C090 == ARRAY_COUNT(filemenu_8024C110)) {
                    D_8024C117 = menu->selected;
                } else {
                    filemenu_8024C110[D_8024C090] = menu->selected;
                    D_8024C090++;
                    if (D_8024C090 > ARRAY_COUNT(filemenu_8024C110)) {
                        D_8024C090 = ARRAY_COUNT(filemenu_8024C110);
                    }
                }
                break;
        }

        if (((u8)(menu->selected + 0x39) >= 3) && (D_8024C090 == ARRAY_COUNT(filemenu_8024C110))) { // todo ???
            filemenu_set_selected(menu, menu->numCols - 3, menu->numRows - 1);
        }
    }


    if ((filemenu_pressedButtons & BUTTON_B) || ((filemenu_pressedButtons & BUTTON_A) && (menu->selected == 0xC9))) {
        sfx_play_sound(SOUND_2104);
        D_8024C090--;
        if (D_8024C090 < 0) {
            D_8024C090 = 0;
            set_window_update(WINDOW_ID_48, (s32) &filemenu_update_hidden_name_input);
            set_window_update(WINDOW_ID_49, (s32) &filemenu_update_hidden_name_input);
            set_window_update(WINDOW_ID_45, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_51, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_52, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_53, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_54, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_55, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_53, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_56, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_57, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_58, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_59, (s32) &filemenu_update_show_with_rotation);
            filemenu_8024C098 = 0;
            return;
        }

        for (i = D_8024C090; i < ARRAY_COUNT(filemenu_8024C110); i++) {
            filemenu_8024C110[i] = 0xF7;
        }
    }

    if (filemenu_pressedButtons & BUTTON_START) {
        for (i = 0; i < ARRAY_COUNT(filemenu_8024C110); i++) {
            if (filemenu_8024C110[i] != 0xF7) {
                break;
            }
        }
        if (i == ARRAY_COUNT(filemenu_8024C110)) {
            sfx_play_sound(SOUND_MENU_ERROR);
            return;

        }

        sfx_play_sound(SOUND_MENU_NEXT);
        set_window_update(WINDOW_ID_50, (s32) filemenu_update_show_name_confirm);

        gWindows[50].pos.y = 121;
        gWindows[50].width = 69;
        gWindows[50].height = 44;
        gWindows[50].pos.x = ((gWindows[50].parent != -1)
                            ? (gWindows[gWindows[50].parent].width / 2)
                            : SCREEN_WIDTH / 2) - gWindows[50].width / 2;

        gWindows[46].pos.y = -70;
        gWindows[46].width = 164;
        gWindows[46].height = 62;
        gWindows[46].pos.x = ((gWindows[46].parent != -1)
                            ? (gWindows[gWindows[46].parent].width / 2)
                            : SCREEN_WIDTH / 2) - gWindows[46].width / 2;

        newMenu2 = filemenu_menus[1];
        filemenu_8024C098 = 1;
        newMenu2->page = 2;
        filemenu_set_selected(newMenu2, 0, 0);
    }
}

static const f32 padding[2] = { 0.0f, 0.0f }; // not sure why this is needed

void filemenu_choose_name_update(void) {
}

void filemenu_choose_name_cleanup(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8024C100_C09980); i++) {
        hud_element_free(D_8024C100_C09980[i]);
    }
}
