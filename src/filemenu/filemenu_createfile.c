#include "common.h"
#include "filemenu.h"
#include "hud_element.h"

extern HudScript HES_FilenameCaret;
extern HudScript HES_FilenameSpace;
extern HudScript HES_134F60_135120;

HudScript* filemenu_createfile_hudElemScripts[] = {
    &HES_FilenameCaret, &HES_FilenameSpace, &HES_134F60_135120
};

s32 D_8024A18C = -4;

#if VERSION_PAL
#define WINDOW_1_Y (0)
#define WINDOW_2_Y (55)
#define WINDOW_2_HEIGHT (133)
#define ROWS (8)
#define INPUT_FINAL_PAGE (1)
extern u8 D_filemenu_80250958[];
extern u8 D_filemenu_80250960[];
#else
#define WINDOW_1_Y (10)
#define WINDOW_2_Y (67)
#define WINDOW_2_HEIGHT (113)
#define ROWS (6)
#define INPUT_FINAL_PAGE (2)
#endif

MenuWindowBP filemenu_createfile_windowBPs[] = {
    {
        .windowID = WINDOW_ID_FILEMENU_CREATEFILE_HEADER,
        .unk_01 = 0,
        .pos = { .x = 68, .y = WINDOW_1_Y },
        .width = 164,
        .height = 46,
        .priority = WINDOW_PRIORITY_64,
        .fpDrawContents = &filemenu_draw_contents_file_create_header,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_MAIN,
        .fpUpdate = { WINDOW_UPDATE_HIDE },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[21] }
    },
    {
        .windowID = WINDOW_ID_FILEMENU_KEYBOARD,
        .unk_01 = 0,
        .pos = { .x = 12, .y = WINDOW_2_Y },
        .width = 262,
        .height = WINDOW_2_HEIGHT,
        .priority = WINDOW_PRIORITY_64,
        .fpDrawContents = &filemenu_draw_contents_choose_name,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_MAIN,
        .fpUpdate = { WINDOW_UPDATE_HIDE },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[22] }
    },
};

MenuPanel filemenu_createfile_menuBP = {
    .initialized = FALSE,
    .col = 0,
    .row = 0,
    .selected = 0,
    .page = 0,
    .numCols = 13,
    .numRows = ROWS,
    .numPages = 0,
    .gridData = filemenu_createfile_gridData,
    .fpInit = &filemenu_choose_name_init,
    .fpHandleInput = &filemenu_choose_name_handle_input,
    .fpUpdate = &filemenu_choose_name_update,
    .fpCleanup = &filemenu_choose_name_cleanup
};

void filemenu_update_change_layout(
    s32 windowIdx,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIdx];

    if (window->updateCounter == 8) {
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
        set_window_update(windowIdx, WINDOW_UPDATE_SHOW);
    }
}

void filemenu_draw_contents_file_create_header(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
#if VERSION_PAL
    s32 temp_s2 = D_filemenu_8025095C[gCurrentLanguage]; // 36
    s32 yOffset;
    s32 xOffset;
    s32 i;

    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_ENTER_A_FILE_NAME), baseX + 10, baseY + 6, 255, 0, 0);
    filemenu_draw_file_name(filemenu_filename, 8, baseX + temp_s2 + 2, baseY + 22, 255, 0, 0, 11);
    yOffset = 41;

    for (i = 0; i < ARRAY_COUNT(filemenu_filename); i++) {
        xOffset = temp_s2 + 6 + i * 11;
        hud_element_set_render_pos(filemenu_createfile_hudElems[1], baseX + xOffset, baseY + yOffset);
        if (i == 0) {
            hud_element_draw_without_clipping(filemenu_createfile_hudElems[1]);
        } else {
            hud_element_draw_next(filemenu_createfile_hudElems[1]);
        }
    }

    if (filemenu_currentMenu == 3) {
        if (filemenu_filename_pos == 8) {
            xOffset = temp_s2 + 86;
        } else {
            xOffset = temp_s2 + 9 + filemenu_filename_pos * 11;
        }
        yOffset = 45;
        hud_element_set_render_pos(filemenu_createfile_hudElems[0], baseX + xOffset, baseY + yOffset);
        hud_element_draw_next(filemenu_createfile_hudElems[0]);
    }
#else
    s32 xOffset;
    s32 yOffset;
    s32 i;
    s32 tempAmt;

    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_ENTER_A_FILE_NAME), baseX + 10, baseY + 6, 255, 0, 0);
    filemenu_draw_file_name(filemenu_filename, 8, baseX + 36, baseY + 22, 255, 0, 0, 11);
    xOffset = 41;

    for (i = 0; i < ARRAY_COUNT(filemenu_filename); i++) {
        hud_element_set_render_pos(filemenu_createfile_hudElems[1], baseX + 42 + (i * 11), baseY + xOffset);
        if (i == 0) {
            hud_element_draw_without_clipping(filemenu_createfile_hudElems[1]);
        } else {
            hud_element_draw_next(filemenu_createfile_hudElems[1]);
        }
    }

    tempAmt = 8;
    if (filemenu_currentMenu == 3) {
        s32 phi_v0 = 122;

        if (filemenu_filename_pos != tempAmt) {
            phi_v0 = (filemenu_filename_pos * 11) + 45;
        }
        hud_element_set_render_pos(filemenu_createfile_hudElems[0], baseX + phi_v0, baseY + 45);
        hud_element_draw_next(filemenu_createfile_hudElems[0]);
    }
#endif
}

#if VERSION_PAL
INCLUDE_ASM(void, "filemenu/filemenu_createfile", filemenu_draw_contents_choose_name);
#else
s32 msg_get_print_char_width(s32 character, s32 charset, s32 variation, f32 msgScale, s32 overrideCharWidth, u8 flags);

#if VERSION_PAL
#define FILEMENU_ROW_AMT (15)
#define FILEMENU_C9_OFFSET (16)
#else
#define FILEMENU_ROW_AMT (17)
#define FILEMENU_C9_OFFSET (5)
#endif

void filemenu_draw_contents_choose_name(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    s32 changeLayoutOffset;
    s32 currentPage;
    s32 previousPage;
    s32 page;
    s32 row, col;
    s32 xOffset, yOffset;
    s32 c, specialChar;
    s32 layer;
    s32 flags;
    s32 color;
    s32 xNudge;
    Window* window = &gWindows[WINDOW_ID_FILEMENU_KEYBOARD];

    if ((window->flags & WINDOW_FLAG_INITIAL_ANIMATION) && window->fpUpdate.func == filemenu_update_change_layout) {
        changeLayoutOffset = window->updateCounter * 2;
        currentPage = menu->page;
        previousPage = menu->page != 1;
        if (changeLayoutOffset > 16) {
            changeLayoutOffset = 16;
        }

        for (row = 0; row < menu->numRows; row++) {
            for (layer = 0; layer < 2; layer++) {
                yOffset = 15 * row + 4;
                if (layer == 0) {
                    page = currentPage;
                    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE,
                                  baseX,
                                  baseY + yOffset,
                                  baseX + width,
                                  baseY + yOffset + changeLayoutOffset);
                } else {
                    page = previousPage;
                    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE,
                                  baseX,
                                  baseY + yOffset + changeLayoutOffset,
                                  baseX + width,
                                  baseY + yOffset + 16);
                }

                for (col = 0; col < menu->numCols; col++) {
                    c = menu->gridData[page * menu->numCols * menu->numRows + menu->numCols * row + col];
                    if (c != 0xF7) {
                        if (col == menu->col && row == menu->row) {
                            flags = 8;
                            color = 0;
                        } else {
                            flags = 0;
                            color = 10;
                        }
                        xOffset = 19 * col + 12;
                        yOffset = FILEMENU_ROW_AMT * row + 5;
#if VERSION_PAL
                        xNudge = msg_get_print_char_width(c, 0, 0, 1.0f, 0, 1);
#endif
                        specialChar = c;
                        if (c >= 0xA2 && c < 0xF0) {
                            if (c >= 0xC6) {
                                hud_element_set_render_pos(filemenu_createfile_hudElems[2], baseX + xOffset + 22, baseY + yOffset + 8);
                                hud_element_draw_without_clipping(filemenu_createfile_hudElems[2]);
                                flags = 0;
                            }
                        }
                        if (specialChar == 0xC6) {
                            xOffset -= 1;
                        }
                        if (specialChar == 0xC9) {
#if VERSION_PAL
                            xOffset += 16;
#else
                            xOffset += 5;
#endif
                        }
                        if (specialChar == 0xCA) {
#if VERSION_PAL
                            if (gCurrentLanguage == LANGUAGE_DE) {
                                xOffset += 4;
                            } else {
                                xOffset += 8;
                            }
#else
                            xOffset += 8;
#endif
                        }
                        if (specialChar == 0xC6 || specialChar == 0xCA || specialChar == 0xC9) {
                            yOffset -= 1;
                            xNudge = 9;
                        }
#if VERSION_PAL
                        filemenu_draw_message((u8*)c, baseX + xOffset + ((8 - xNudge) / 2), baseY + yOffset, 255, color, flags);
#else
                        filemenu_draw_message((u8*)c, baseX + xOffset, baseY + yOffset, 255, color, flags);
#endif
                    }
                }
            }
        }
        gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, baseX, baseY, baseX + width, baseY + height);
    } else {
        for (col = 0; col < menu->numCols; col++) {
            for (row = 0; row < menu->numRows; row++) {
                c = menu->gridData[menu->page * menu->numCols * menu->numRows + menu->numCols * row + col];
                if (c != 0xF7) {
                    if (col == menu->col && row == menu->row) {
                        flags = 8;
                        color = 0;
                    } else {
                        flags = 0;
                        color = 10;
                    }
                    xOffset = col * 19 + 12;
                    yOffset = row * FILEMENU_ROW_AMT + 5;
#if VERSION_PAL
                    xNudge = msg_get_print_char_width(c, 0, 0, 1.0f, 0, 1);
#endif
                    specialChar = c;
                    if (c >= 0xA2 && c < 0xF0) {
                        if (c >= 0xC6) {
                            hud_element_set_render_pos(filemenu_createfile_hudElems[2], baseX + xOffset + 22, baseY + yOffset + 8);
                            hud_element_draw_without_clipping(filemenu_createfile_hudElems[2]);
                            flags = 0;
                        }
                    }
                    if (specialChar == 0xC6) {
                        xOffset -= 1;
                    }
                    if (specialChar == 0xC9) {
                        xOffset += FILEMENU_C9_OFFSET;
                    }
                    if (specialChar == 0xCA) {
#if VERSION_PAL
                        if (gCurrentLanguage == LANGUAGE_DE) {
                            xOffset += 4;
                        } else {
                            xOffset += 8;
                        }
#else
                        xOffset += 8;
#endif
                    }
                    if (specialChar == 0xC6 || specialChar == 0xCA || specialChar == 0xC9) {
                        yOffset -= 1;
                        xNudge = 9;
                    }
#if VERSION_PAL
                    filemenu_draw_message((u8*)c, baseX + xOffset + ((8 - xNudge) / 2), baseY + yOffset, 255, color, flags);
#else
                    filemenu_draw_message((u8*)c, baseX + xOffset, baseY + yOffset, 255, color, flags);
#endif
                }
            }
        }
    }

    if (filemenu_currentMenu == 3) {
        if (filemenu_heldButtons & (BUTTON_STICK_RIGHT | BUTTON_STICK_LEFT | BUTTON_STICK_DOWN | BUTTON_STICK_UP)) {
            D_8024A18C = -4;
        }
        D_8024A18C++;
        filemenu_set_cursor_goal_pos(WINDOW_ID_FILEMENU_KEYBOARD,
                                     baseX + 2 + menu->col * 19,
                                     baseY + 13 + menu->row * FILEMENU_ROW_AMT);
    }
}
#endif

void filemenu_choose_name_init(MenuPanel* menu) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(filemenu_createfile_hudElemScripts); i++) {
        filemenu_createfile_hudElems[i] = hud_element_create(filemenu_createfile_hudElemScripts[i]);
        hud_element_set_flags(filemenu_createfile_hudElems[i], HUD_ELEMENT_FLAG_80);
    }

    for (i = 0; i < ARRAY_COUNT(filemenu_createfile_windowBPs); i++) {
        filemenu_createfile_windowBPs[i].tab = menu;
    }

    setup_pause_menu_tab(filemenu_createfile_windowBPs, ARRAY_COUNT(filemenu_createfile_windowBPs));

    gWindows[WINDOW_ID_FILEMENU_CREATEFILE_HEADER].pos.x = ((gWindows[WINDOW_ID_FILEMENU_CREATEFILE_HEADER].parent != -1)
                        ? (gWindows[gWindows[WINDOW_ID_FILEMENU_CREATEFILE_HEADER].parent].width / 2)
                        : SCREEN_WIDTH / 2) - gWindows[WINDOW_ID_FILEMENU_CREATEFILE_HEADER].width / 2;

    gWindows[WINDOW_ID_FILEMENU_KEYBOARD].pos.x = ((gWindows[WINDOW_ID_FILEMENU_KEYBOARD].parent != -1)
                        ? (gWindows[gWindows[WINDOW_ID_FILEMENU_KEYBOARD].parent].width / 2)
                        : SCREEN_WIDTH / 2) - gWindows[WINDOW_ID_FILEMENU_KEYBOARD].width / 2;

    menu->initialized = TRUE;
}

void filemenu_choose_name_handle_input(MenuPanel* menu) {
    s32 oldSelected = menu->selected;
    MenuPanel* newMenu;
    MenuPanel* newMenu2;
    s32 i;

#if VERSION_PAL
    s32 halfWidth;

    gWindows[WINDOW_ID_FILEMENU_CREATEFILE_HEADER].width = D_filemenu_80250958[gCurrentLanguage];
    halfWidth = gWindows[WINDOW_ID_FILEMENU_CREATEFILE_HEADER].width / 2;
    gWindows[WINDOW_ID_FILEMENU_CREATEFILE_HEADER].pos.x = gWindows[WINDOW_ID_FILEMENU_CREATEFILE_HEADER].parent != -1 ?
        (gWindows[gWindows[WINDOW_ID_FILEMENU_CREATEFILE_HEADER].parent].width / 2) - halfWidth :
        SCREEN_WIDTH / 2 - halfWidth;
#endif

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
            }
#if !VERSION_PAL
            else if (menu->col == 5 || menu->col == 6) {
                menu->col = 7;
            }
#endif
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
        }
#if !VERSION_PAL
        else if (menu->col == 5 || menu->col == 6) {
            menu->col = 4;
        }
#endif
    }

    menu->selected = MENU_PANEL_SELECTED_GRID_DATA(menu);
    if (oldSelected != menu->selected) {
        sfx_play_sound(SOUND_CREATE_FILE_MOVE_CURSOR);
    }

    if (filemenu_pressedButtons & BUTTON_A) {
        switch (menu->selected) {
            case 0xC6:
                sfx_play_sound(SOUND_CREATE_FILE_SET_CHARACTER);
                if (filemenu_filename_pos == ARRAY_COUNT(filemenu_filename)) {
                    filemenu_filename_pos = ARRAY_COUNT(filemenu_filename) - 1;
                }
                filemenu_filename[filemenu_filename_pos] = 0xF7;
                filemenu_filename_pos++;
                if (filemenu_filename_pos > ARRAY_COUNT(filemenu_filename)) {
                    filemenu_filename_pos = ARRAY_COUNT(filemenu_filename);
                }
                break;
            case 0xC9:
                break;
            case 0xC7:
                if (menu->page != 1) {
                    sfx_play_sound(SOUND_CREATE_FILE_CHANGE_CHARSET);
                    menu->page = 1;
                    filemenu_set_selected(menu, menu->col, menu->row);
                    set_window_update(WINDOW_ID_FILEMENU_KEYBOARD, (s32)filemenu_update_change_layout);
                }
                break;
            case 0xC8:
                if (menu->page != 0) {
                    sfx_play_sound(SOUND_CREATE_FILE_CHANGE_CHARSET);
                    menu->page = 0;
                    filemenu_set_selected(menu, menu->col, menu->row);
                    set_window_update(WINDOW_ID_FILEMENU_KEYBOARD, (s32)filemenu_update_change_layout);
                }
                break;
            case 0xCA:
                for (i = 0; i < ARRAY_COUNT(filemenu_filename); i++) {
                    if (filemenu_filename[i] != 0xF7) {
                        break;
                    }
                }
                if (i == ARRAY_COUNT(filemenu_filename)) {
                    sfx_play_sound(SOUND_MENU_ERROR);
                    break;
                }

                sfx_play_sound(SOUND_MENU_NEXT);
                set_window_update(WINDOW_ID_FILEMENU_YESNO_OPTIONS, (s32) filemenu_update_show_name_confirm);
                gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].pos.y = 121;
                gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].width = 69;
                gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].height = 44;
                gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].pos.x = ((gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].parent != -1)
                                               ? (gWindows[gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].parent].width / 2)
                                               : SCREEN_WIDTH / 2) - gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].width / 2;

                gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].pos.y = -70;
#if VERSION_PAL
                gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].width = D_filemenu_80250960[gCurrentLanguage];
                halfWidth = gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].width / 2;
                gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].height = 62;
                gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].pos.x = gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].parent != -1
                    ? (gWindows[gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].parent].width / 2) - halfWidth
                    : SCREEN_WIDTH / 2 - halfWidth;
#else
                gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].width = 164;
                gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].height = 62;
                gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].pos.x = ((gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].parent != -1)
                    ? (gWindows[gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].parent].width / 2)
                    : SCREEN_WIDTH / 2) - gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].width / 2;
#endif

                filemenu_currentMenu = 1;
                newMenu = filemenu_menus[filemenu_currentMenu];
                newMenu->page = INPUT_FINAL_PAGE;
                filemenu_set_selected(newMenu, 0, 0);
                return;
            default:
                sfx_play_sound(SOUND_CREATE_FILE_SET_CHARACTER);
                if (filemenu_filename_pos == ARRAY_COUNT(filemenu_filename)) {
                    filemenu_filename[7] = menu->selected;
                } else {
                    filemenu_filename[filemenu_filename_pos] = menu->selected;
                    filemenu_filename_pos++;
                    if (filemenu_filename_pos > ARRAY_COUNT(filemenu_filename)) {
                        filemenu_filename_pos = ARRAY_COUNT(filemenu_filename);
                    }
                }
                break;
        }

        if (menu->selected != 0xC7 && menu->selected != 0xC8 && menu->selected != 0xC9 &&
            filemenu_filename_pos == ARRAY_COUNT(filemenu_filename)) {
            filemenu_set_selected(menu, menu->numCols - 3, menu->numRows - 1);
        }
    }


    if ((filemenu_pressedButtons & BUTTON_B) || ((filemenu_pressedButtons & BUTTON_A) && menu->selected == 0xC9)) {
        sfx_play_sound(SOUND_CREATE_FILE_BACKSPACE);
        filemenu_filename_pos--;
        if (filemenu_filename_pos < 0) {
            filemenu_filename_pos = 0;
            set_window_update(WINDOW_ID_FILEMENU_CREATEFILE_HEADER, (s32) &filemenu_update_hidden_name_input);
            set_window_update(WINDOW_ID_FILEMENU_KEYBOARD, (s32) &filemenu_update_hidden_name_input);
            set_window_update(WINDOW_ID_FILEMENU_TITLE, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_FILEMENU_STEREO, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_FILEMENU_MONO, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_FILEMENU_OPTION_CENTER, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_FILEMENU_OPTION_RIGHT, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_FILEMENU_FILE0_INFO, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_FILEMENU_FILE1_INFO, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_FILEMENU_FILE2_INFO, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_FILEMENU_FILE3_INFO, (s32) &filemenu_update_show_with_rotation);
            filemenu_currentMenu = 0;
            return;
        }

        for (i = filemenu_filename_pos; i < ARRAY_COUNT(filemenu_filename); i++) {
            filemenu_filename[i] = 0xF7;
        }
    }

    if (filemenu_pressedButtons & BUTTON_START) {
        for (i = 0; i < ARRAY_COUNT(filemenu_filename); i++) {
            if (filemenu_filename[i] != 0xF7) {
                break;
            }
        }
        if (i == ARRAY_COUNT(filemenu_filename)) {
            sfx_play_sound(SOUND_MENU_ERROR);
            return;

        }

        sfx_play_sound(SOUND_MENU_NEXT);
        set_window_update(WINDOW_ID_FILEMENU_YESNO_OPTIONS, (s32) filemenu_update_show_name_confirm);

        gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].pos.y = 121;
        gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].width = 69;
        gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].height = 44;
        gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].pos.x = ((gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].parent != -1)
                            ? (gWindows[gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].parent].width / 2)
                            : SCREEN_WIDTH / 2) - gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].width / 2;

        gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].pos.y = -70;
#if VERSION_PAL
        gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].width = D_filemenu_80250960[gCurrentLanguage];
        gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].height = 62;
        halfWidth = gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].width / 2;
        gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].pos.x = gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].parent != -1
            ? (gWindows[gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].parent].width / 2) - halfWidth
            : SCREEN_WIDTH / 2 - halfWidth;
#else

        gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].width = 164;
        gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].height = 62;
        gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].pos.x = ((gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].parent != -1)
            ? (gWindows[gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].parent].width / 2)
            : SCREEN_WIDTH / 2) - gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].width / 2;
#endif

        filemenu_currentMenu = 1;
        newMenu2 = filemenu_menus[filemenu_currentMenu];
        newMenu2->page = INPUT_FINAL_PAGE;
        filemenu_set_selected(newMenu2, 0, 0);
    }
}

static const f32 padding[2] = { 0.0f, 0.0f }; // not sure why this is needed

void filemenu_choose_name_update(MenuPanel* menu) {
}

void filemenu_choose_name_cleanup(MenuPanel* menu) {
    s32 i;

    for (i = 0; i < 3; i++) {
        hud_element_free(filemenu_createfile_hudElems[i]);
    }
}
