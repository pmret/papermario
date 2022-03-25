#include "common.h"
#include "filemenu.h"
#include "hud_element.h"
#include "audio.h"
#include "fio.h"

extern SaveMetadata gSaveSlotMetadata[4];
extern u8 gSaveSlotHasData[4];
extern HudScript* filemenu_hudElemScripts[14];
extern MenuWindowBP filemenu_windowBPs[14];

extern s8 D_8024C090;

void filemenu_draw_contents_title(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    s32 msgIdx;
    s32 xOffset;
    s32 yOffset;

    switch (menu->page) {
        case 0:
            msgIdx = FILE_MESSAGE_SELECT_FILE_TO_START;
            xOffset = 9;
            yOffset = 4;
            break;
        case 1:
            msgIdx = FILE_MESSAGE_SELECT_FILE_TO_DELETE;
            xOffset = 8;
            yOffset = 4;
            break;
        case 3:
            msgIdx = FILE_MESSAGE_COPY_WHICH_FILE;
            xOffset = 25;
            yOffset = 4;
            break;
        case 4:
            msgIdx = FILE_MESSAGE_COPY_TO_WHICH_FILE;
            xOffset = 16;
            yOffset = 4;
            break;
        case 2:
        default:
            msgIdx = FILE_MESSAGE_SELECT_FILE_TO_SAVE;
            xOffset = 10;
            yOffset = 4;
            break;
    }

    filemenu_draw_message(filemenu_get_menu_message(msgIdx), baseX + xOffset, baseY + yOffset, 255, 0, 0);
}

void filemenu_draw_contents_stereo(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    if (gGameStatusPtr->soundOutputMode == SOUND_OUT_STEREO) {
        hud_element_set_render_pos(filemenu_hudElemIDs[18], baseX + 34, baseY + 10);
        hud_element_draw_without_clipping(filemenu_hudElemIDs[18]);
    } else {
        hud_element_set_render_pos(filemenu_hudElemIDs[19], baseX + 34, baseY + 10);
        hud_element_draw_without_clipping(filemenu_hudElemIDs[19]);
    }
}

void filemenu_draw_contents_mono(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    if (gGameStatusPtr->soundOutputMode == SOUND_OUT_MONO) {
        hud_element_set_render_pos(filemenu_hudElemIDs[16], baseX + 34, baseY + 10);
        hud_element_draw_without_clipping(filemenu_hudElemIDs[16]);
    } else {
        hud_element_set_render_pos(filemenu_hudElemIDs[17], baseX + 34, baseY + 10);
        hud_element_draw_without_clipping(filemenu_hudElemIDs[17]);
    }
}

void filemenu_draw_contents_option_left(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    if (menu->page != 2) {
        if (menu->col == 0 && menu->row == 2) {
            filemenu_set_cursor_goal_pos(53, baseX, baseY + 8);
        }
        filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_DELETE_FILE), baseX + 8, baseY + 2, 255, 0, 1);
    }
}

void filemenu_draw_contents_option_center(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    s32 msgIdx;
    s32 xOffset;
    s32 yOffset;

    switch (menu->page) {
        case 1:
        case 2:
        case 3:
        case 4:
            msgIdx = FILE_MESSAGE_CANCEL;
            xOffset = 18;
            yOffset = 0;
            if (menu->col == 1 && menu->row == 2) {
                filemenu_set_cursor_goal_pos(54, baseX + 8, baseY + 8);
            }
            break;
        default:
            msgIdx = FILE_MESSAGE_COPY_FILE;
            xOffset = 14;
            yOffset = 0;
            if (menu->col == 1 && menu->row == 2) {
                filemenu_set_cursor_goal_pos(54, baseX + 4, baseY + 8);
            }
            break;
    }

    filemenu_draw_message(filemenu_get_menu_message(msgIdx), baseX + xOffset, baseY + yOffset + 2, 255, 0, 1);
}

void filemenu_draw_contents_option_right(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    if (menu->page != 2) {
        if (menu->col == 2 && menu->row == 2) {
            filemenu_set_cursor_goal_pos(55, baseX + 8, baseY + 8);
        }
        filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_CANCEL), baseX + 20, baseY + 2, 255, 0, 1);
    }
}

void filemenu_draw_contents_file_info(s32 fileIdx,
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    SaveMetadata* save;
    s32 temp_s0;
    s32 temp_s0_3;
    s32 temp_s1_2;
    s32 temp_s3_2;
    s32 temp_s3;
    s32 id;
    s32 i;
    const int MAX_DISPLAYED_TIME = 100*60*60*60 - 1; // 100 hours minus one frame at 60 fps

    if (!gSaveSlotHasData[fileIdx]) {
        filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_NEW), baseX + 50, baseY + 20, 0xFF, 0xA, 0);
        return;
    }

    save = &gSaveSlotMetadata[fileIdx];
    if (save->timePlayed == 0) {
        filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FIRST_PLAY), baseX + 30, baseY + 20, 0xFF, 0xA, 0);
        return;
    }

    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_LEVEL), baseX + 0x22, baseY + 10, 0xFF, 0xA, 1);
    temp_s3_2 = save->level;
    temp_s3 = temp_s3_2;
    temp_s0 = temp_s3 / 10;
    draw_number(temp_s0, baseX + 79, baseY + 10, 1, 0xA, 0xFF, 2);
    draw_number(temp_s3 - (temp_s0 * 10), baseX + 88, baseY + 10, 1, 0xA, 0xFF, 2);
    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_PLAY_TIME), baseX + 11, baseY + 24, 0xFF, 0xA, 1);

    temp_s3_2 = save->timePlayed;
    if (temp_s3_2 > MAX_DISPLAYED_TIME) {
        temp_s3_2 = MAX_DISPLAYED_TIME;
    }

    draw_number((temp_s3_2 / 2160000) % 10, baseX + 76, baseY + 24, 1, 0xA, 0xFF, 2);
    temp_s1_2 = temp_s3_2 / 216000;
    draw_number(temp_s1_2 - ((temp_s3_2 / 2160000) * 10), baseX + 85, baseY + 24, 1, 0xA, 0xFF, 2);
    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_PERIOD_13), baseX + 95, baseY + 23, 0xFF, 0xA, 1);
    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_PERIOD_13), baseX + 95, baseY + 18, 0xFF, 0xA, 1);
    temp_s0_3 = temp_s3_2 / 36000;
    draw_number(temp_s0_3 - (temp_s1_2 * 6), baseX + 100, baseY + 24, 1, 0xA, 0xFF, 2);
    draw_number((temp_s3_2 / 3600) - (temp_s0_3 * 10), baseX + 109, baseY + 24, 1, 0xA, 0xFF, 2);

    for (i = 0; i < 7; i++) {
        if (i < gSaveSlotMetadata[fileIdx].spiritsRescued) {
            id = filemenu_hudElemIDs[i];
        } else {
            id = filemenu_hudElemIDs[i + 7];
        }
        hud_element_set_render_pos(id, baseX + 17 + (i * 16), baseY + 44);
        if (i == 0) {
            hud_element_draw_without_clipping(id);
        } else {
            hud_element_draw_next(id);
        }
    }
}

void filemenu_draw_contents_file_title(
    s32 fileIdx,
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening)
{
    if (filemenu_8024C098 == 0 && menu->selected == fileIdx) {
        filemenu_set_cursor_goal_pos(fileIdx + 60, baseX - 3, baseY + 8);
    }

    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_26), baseX + 5, baseY + 1, 255, 0, 1);

    if (!gSaveSlotHasData[fileIdx]) {
        draw_number(fileIdx + 1, baseX + 33, baseY + 1, 1, 0, 255, 2);
    } else {
        draw_number(fileIdx + 1, baseX + 33, baseY + 1, 1, 0, 255, 2);
        filemenu_draw_file_name(gSaveSlotMetadata[fileIdx].filename, 8, baseX + 46, baseY + 1, 255, 0, 1, 9);
    }
}

void filemenu_draw_contents_file_0_info(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_info(0, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_1_info(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_info(1, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_2_info(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_info(2, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_3_info(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_info(3, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_0_title(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_title(0, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_1_title(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_title(1, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_2_title(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_title(2, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_3_title(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_title(3, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_main_init(MenuPanel* menu) {
    s32 halfWidth;
    s32 halfWidth2;
    s16* posXPtr;
    s32 x;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(filemenu_hudElemIDs); i++) {
        filemenu_hudElemIDs[i] = hud_element_create(filemenu_hudElemScripts[i]);
        hud_element_set_flags(filemenu_hudElemIDs[i], HUD_ELEMENT_FLAGS_80);
    }

    for (i = 0; i < ARRAY_COUNT(filemenu_windowBPs); i++) {
        filemenu_windowBPs[i].tab = menu;
    }

    setup_pause_menu_tab(filemenu_windowBPs, ARRAY_COUNT(filemenu_windowBPs));
    menu->selected = menu->gridData[(menu->page * menu->numCols * menu->numRows) +
                                             (menu->numCols * menu->row) +
                                             menu->col];

    if (menu->page == 2) {
        gWindows[45].pos.y = 1;
        gWindows[45].width = 211;
        gWindows[45].height = 25;
    } else {
        gWindows[45].pos.y = 1;
        gWindows[45].width = 162;
        gWindows[45].height = 25;
    }

    halfWidth = gWindows[45].width / 2;
    posXPtr = &gWindows[45].pos.x;
    if (gWindows[45].parent != -1) {
        x = (gWindows[gWindows[45].parent].width / 2) - halfWidth;
    } else {
        x = 160 - halfWidth;
    }
    *posXPtr = x;

    halfWidth2 = gWindows[54].width / 2;
    posXPtr = &gWindows[54].pos.x;
    if (gWindows[54].parent != -1) {
        x = (gWindows[gWindows[54].parent].width / 2) - halfWidth2;
    } else {
        x = 160 - halfWidth2;
    }
    *posXPtr = x;

    if (menu->page != 0) {
        set_window_update(0x35, WINDOW_UPDATE_HIDE);
        set_window_update(0x37, WINDOW_UPDATE_HIDE);
        set_window_update(0x33, WINDOW_UPDATE_HIDE);
        set_window_update(0x34, WINDOW_UPDATE_HIDE);
    }
    menu->initialized = 1;
}

static const f32 padding[] = { 0.0f }; // TODO remove when the following func is matched

void filemenu_main_handle_input(MenuPanel* menu);
// tons of issues
#ifdef NON_EQUIVALENT
void filemenu_main_handle_input(MenuPanel* menu) {
    s32 originalSelected = menu->selected;
    s32 i;
    MenuPanel* temp_a0;

    if (filemenu_heldButtons & BUTTON_STICK_LEFT) {
        while(TRUE) {
            menu->col--;
            if (menu->col < 0) {
                menu->col = 0;
                break;
            }
            if (menu->selected != MENU_PANEL_SELECTED_GRID_DATA(menu)) {
                break;
            }
        }
    }

    if (filemenu_heldButtons & BUTTON_STICK_RIGHT) {
        while (TRUE) {
            menu->col++;
            if (menu->col >= menu->numCols) {
                menu->col = menu->numCols - 1;
                break;
            }

            if (menu->selected != MENU_PANEL_SELECTED_GRID_DATA(menu)) {
                break;
            }
        }
    }

    if (filemenu_heldButtons & BUTTON_STICK_UP) {
        menu->row--;
        if (menu->row < 0) {
            menu->row = 0;
        }
    }

    if (filemenu_heldButtons & BUTTON_STICK_DOWN) {
        menu->row++;
        if (menu->row >= menu->numRows) {
            menu->row = menu->numRows - 1;
        }
    }

    switch (menu->page) {
        case 0:
            if (menu->col == 1 && (u8) menu->row < 2) {
                menu->col = 0;
            }
            break;
        case 1: // TODO required to duplicate cases 1-4 instead of using fallthrough
            if (menu->col == 1 && (u8) menu->row < 2) {
                menu->col = 0;
            }
            if (menu->row == 2) {
                menu->col = 1;
            }
            break;
        case 2:
            if (menu->col == 1 && (u8) menu->row < 2) {
                menu->col = 0;
            }
            if (menu->row == 2) {
                menu->col = 1;
            }
            break;
        case 3:
            if (menu->col == 1 && (u8) menu->row < 2) {
                menu->col = 0;
            }
            if (menu->row == 2) {
                menu->col = 1;
            }
            break;
        case 4:
            if (menu->col == 1 && (u8) menu->row < 2) {
                menu->col = 0;
            }
            if (menu->row == 2) {
                menu->col = 1;
            }
            break;
    }

    menu->selected = MENU_PANEL_SELECTED_GRID_DATA(menu);
    if (originalSelected != menu->selected) {
        sfx_play_sound(SOUND_2101);
    }

    if (menu->page == 0) {
        s32 originalOutputMode = gGameStatusPtr->soundOutputMode;

        if (filemenu_pressedButtons & BUTTON_Z) {
            gGameStatusPtr->soundOutputMode = SOUND_OUT_STEREO;
        }
        if (filemenu_pressedButtons & BUTTON_R) {
            gGameStatusPtr->soundOutputMode = SOUND_OUT_MONO;
        }

        if (originalOutputMode != gGameStatusPtr->soundOutputMode) {
            sfx_play_sound(SOUND_MENU_CHANGE_TAB);
            if (gGameStatusPtr->soundOutputMode != SOUND_OUT_MONO) {
                audio_set_stereo();
            } else {
                audio_set_mono();
            }
        }
    }

    if ((filemenu_pressedButtons & 0x1000) && menu->page == 0 && menu->selected < 4) {
        filemenu_pressedButtons = 0x8000;
    }

    if (filemenu_pressedButtons & 0x8000) {
        s32 cond = FALSE;

        switch (menu->page) {
            case 0:
                if (menu->selected < 4 && !gSaveSlotHasData[menu->selected] == 0) {
                    cond = TRUE;
                }

                if (cond) {
                    for (i = 0; i < ARRAY_COUNT(filemenu_8024C110); i++) {
                        filemenu_8024C110[i] = 0xF7;
                    }
                    D_8024C090 = 0;
                    set_window_update(0x30, filemenu_update_show_name_input);
                    set_window_update(0x31, filemenu_update_show_name_input);
                    set_window_update(0x2D, filemenu_update_hidden_with_rotation);
                    set_window_update(0x33, filemenu_update_hidden_with_rotation);
                    set_window_update(0x34, filemenu_update_hidden_with_rotation);
                    set_window_update(0x35, filemenu_update_hidden_with_rotation);
                    set_window_update(0x36, filemenu_update_hidden_with_rotation);
                    set_window_update(0x37, filemenu_update_hidden_with_rotation);
                    set_window_update(0x35, filemenu_update_hidden_with_rotation);
                    set_window_update(0x38, filemenu_update_hidden_with_rotation);
                    set_window_update(0x39, filemenu_update_hidden_with_rotation);
                    set_window_update(0x3A, filemenu_update_hidden_with_rotation);
                    set_window_update(0x3B, filemenu_update_hidden_with_rotation);
                    sfx_play_sound(SOUND_MENU_NEXT);
                    filemenu_8024C098 = 3;
                    temp_a0 = filemenu_menus[filemenu_8024C098];
                    temp_a0->page = 0;
                    filemenu_set_selected(temp_a0, 0, 0);
                    break;
                }

                if (menu->selected == 6) {
                    set_window_update(0x33, filemenu_update_hidden_options_left);
                    set_window_update(0x34, filemenu_update_hidden_options_right);
                    set_window_update(0x35, filemenu_update_hidden_options_bottom);
                    set_window_update(0x36, filemenu_update_hidden_options_bottom);
                    set_window_update(0x37, filemenu_update_hidden_options_bottom);
                    set_window_update(0x38, filemenu_update_hidden_options_left);
                    set_window_update(0x39, filemenu_update_hidden_options_right);
                    set_window_update(0x3A, filemenu_update_hidden_options_left);
                    set_window_update(0x3B, filemenu_update_hidden_options_right);
                    set_window_update(0x2D, filemenu_update_hidden_title);
                    sfx_play_sound(SOUND_D6);
                    set_game_mode(0xF);
                } else if (menu->selected == 4) {
                    sfx_play_sound(SOUND_MENU_NEXT);
                    menu->page = 1;
                    filemenu_set_selected(menu, 1, 2);
                    set_window_update(0x33, filemenu_update_hidden_options_left);
                    set_window_update(0x34, filemenu_update_hidden_options_right);
                    set_window_update(0x35, filemenu_update_hidden_options_bottom);
                    set_window_update(0x37, filemenu_update_hidden_options_bottom);
                } else if (menu->selected == 5) {
                    sfx_play_sound(SOUND_MENU_NEXT);
                    menu->page = 3;
                    filemenu_set_selected(menu, 1, 2);
                    set_window_update(0x33, filemenu_update_hidden_options_left);
                    set_window_update(0x34, filemenu_update_hidden_options_right);
                    set_window_update(0x35, filemenu_update_hidden_options_bottom);
                    set_window_update(0x37, filemenu_update_hidden_options_bottom);
                } else if (menu->selected < 4) {
                    sfx_play_sound(SOUND_MENU_NEXT);
                    set_window_update(0x2D, filemenu_update_hidden_with_rotation);
                    set_window_update(0x33, filemenu_update_hidden_with_rotation);
                    set_window_update(0x34, filemenu_update_hidden_with_rotation);
                    set_window_update(0x35, filemenu_update_hidden_with_rotation);
                    set_window_update(0x36, filemenu_update_hidden_with_rotation);
                    set_window_update(0x37, filemenu_update_hidden_with_rotation);
                    set_window_update(0x35, filemenu_update_hidden_with_rotation);
                    set_window_update(0x38, filemenu_update_hidden_with_rotation);
                    set_window_update(0x39, filemenu_update_hidden_with_rotation);
                    set_window_update(0x3A, filemenu_update_hidden_with_rotation);
                    set_window_update(0x3B, filemenu_update_hidden_with_rotation);
                    set_window_update(menu->selected + 56, filemenu_update_select_file);
                    sfx_play_sound(SOUND_MENU_NEXT);
                    set_window_update(0x32, 1);
                    gWindows[50].pos.y = 143;
                    gWindows[50].width = 69;
                    gWindows[50].height = 44;
                    gWindows[50].pos.x = ((gWindows[50].parent != -1) ? (gWindows[gWindows[50].parent].width / 2) : 320 / 2) - gWindows[50].width / 2;

                    gWindows[46].pos.y = -29;
                    gWindows[46].width = 192;
                    gWindows[46].height = 25;
                    gWindows[46].pos.x = ((gWindows[46].parent != -1) ? (gWindows[gWindows[46].parent].width / 2) : 320 / 2) - gWindows[46].width / 2;

                    filemenu_8024C098 = 1;
                    temp_a0 = filemenu_menus[filemenu_8024C098];
                    temp_a0->page = 4;
                    filemenu_set_selected(temp_a0, 0, 0);
                }
                break;
            case 1:
                if (menu->selected == 6) {
                    sfx_play_sound(SOUND_MENU_NEXT);
                    menu->page = 0;
                    set_window_update(0x33, filemenu_update_show_options_left);
                    set_window_update(0x34, filemenu_update_show_options_right);
                    set_window_update(0x35, filemenu_update_show_options_bottom);
                    set_window_update(0x37, filemenu_update_show_options_bottom);
                    filemenu_set_selected(menu, 0, 2);
                } else if (menu->selected < 4) {
                    if (gSaveSlotHasData[menu->selected] != 0) {
                        sfx_play_sound(SOUND_MENU_NEXT);
                        set_window_update(0x32, filemenu_update_show_name_confirm);
                        gWindows[50].pos.y = 121;
                        gWindows[50].width = 69;
                        gWindows[50].height = 44;
                        gWindows[50].pos.x = ((gWindows[50].parent != -1) ? (gWindows[gWindows[50].parent].width / 2) : 320 / 2) - 34;

                        gWindows[46].pos.y = -29;
                        gWindows[46].width = 118;
                        gWindows[46].height = 25;
                        gWindows[46].pos.x = ((gWindows[46].parent != -1) ? (gWindows[gWindows[46].parent].width / 2) : 320 / 2) - 59;

                        filemenu_8024C098 = 1;
                        temp_a0 = filemenu_menus[filemenu_8024C098];
                        temp_a0->page = 0;
                        filemenu_set_selected(temp_a0, 0, 1);
                    } else {
                        sfx_play_sound(SOUND_MENU_ERROR);
                    }
                }
                break;
            case 3:
                if (menu->selected == 6) {
                    sfx_play_sound(SOUND_MENU_NEXT);
                    menu->page = 0;
                    set_window_update(0x33, filemenu_update_show_options_left);
                    set_window_update(0x34, filemenu_update_show_options_right);
                    set_window_update(0x35, filemenu_update_show_options_bottom);
                    set_window_update(0x37, filemenu_update_show_options_bottom);
                    filemenu_set_selected(menu, 0, 1);
                } else if (menu->selected < 4) {
                    if (gSaveSlotHasData[menu->selected] != 0) {
                        sfx_play_sound(SOUND_MENU_NEXT);
                        menu->page = 4;
                        filemenu_loadedFileIdx = menu->selected;
                    } else {
                        sfx_play_sound(SOUND_MENU_ERROR);
                    }
                }
                break;
            case 4:
                if (menu->selected == 6) {
                    sfx_play_sound(SOUND_MENU_NEXT);
                    menu->page = 3;
                    filemenu_set_selected(menu, 0, 2);
                } else if (menu->selected < 4) {
                    if (filemenu_loadedFileIdx == menu->selected) {
                        sfx_play_sound(SOUND_MENU_ERROR);
                    } else {
                        filemenu_iterFileIdx = menu->selected;
                        if (gSaveSlotHasData[menu->selected] == 0) {
                            sfx_play_sound(SOUND_MENU_NEXT);
                            filemenu_8024C098 = 2;
                            filemenu_menus[filemenu_8024C098]->page = 2;

                            gWindows[47].width = 154;
                            gWindows[47].height = 39;
                            gWindows[47].pos.x = ((gWindows[47].parent != -1) ? (gWindows[gWindows[47].parent].width / 2) : 320 / 2) - gWindows[47].width / 2;
                            gWindows[47].pos.y = ((gWindows[47].parent != -1) ? (gWindows[gWindows[47].parent].height / 2) : 240 / 2) - gWindows[47].height / 2;


                            set_window_update(0x2F, 1);
                            set_window_update(0x32, 2);
                            fio_load_game(filemenu_loadedFileIdx);
                            gSaveSlotMetadata[filemenu_iterFileIdx] = gSaveSlotMetadata[filemenu_loadedFileIdx];
                            fio_save_game(filemenu_iterFileIdx);
                            gSaveSlotHasData[filemenu_iterFileIdx] = 1;
                        } else {
                            sfx_play_sound(SOUND_MENU_NEXT);
                            set_window_update(0x32, filemenu_update_show_name_confirm);

                            gWindows[50].pos.y = 121;
                            gWindows[50].width = 69;
                            gWindows[50].height = 44;
                            gWindows[50].pos.x = ((gWindows[50].parent != -1) ? (gWindows[gWindows[50].parent].width / 2) : 320 / 2) - gWindows[50].width / 2;

                            gWindows[46].pos.y = -43;
                            gWindows[46].width = 182;
                            gWindows[46].height = 39;
                            gWindows[46].pos.x = ((gWindows[46].parent != -1) ? (gWindows[gWindows[46].parent].width / 2) : 320 / 2) - gWindows[46].width / 2;

                            filemenu_8024C098 = 1;
                            temp_a0 = filemenu_menus[filemenu_8024C098];
                            temp_a0->page = 3;
                            filemenu_set_selected(temp_a0, 0, 1);
                        }
                    }
                }
                break;
            case 2:
                if (menu->selected == 6) {
                    sfx_play_sound(SOUND_MENU_NEXT);
                    set_game_mode(0xD);
                } else if (menu->selected < 4) {
                    if (gSaveSlotHasData[menu->selected] == 0) {
                        sfx_play_sound(SOUND_MENU_NEXT);
                        filemenu_8024C098 = 2;
                        filemenu_menus[filemenu_8024C098]->page = 1;
                        set_window_update(0x2C, main_menu_window_update);
                        set_window_update(0x2F, 1);
                        set_window_update(0x32, 2);
                        fio_save_game(menu->selected);
                        gSaveSlotHasData[menu->selected] = 1;
                    } else {
                        sfx_play_sound(SOUND_MENU_NEXT);
                        set_window_update(0x32, filemenu_update_show_name_confirm);
                        gWindows[50].pos.y = 127;
                        gWindows[50].width = 69;
                        gWindows[50].height = 44;
                        gWindows[50].pos.x = ((gWindows[50].parent != -1) ? (gWindows[gWindows[50].parent].width / 2) : 320 / 2) - gWindows[50].width / 2;

                        gWindows[46].pos.y = -50;
                        gWindows[46].width = 148;
                        gWindows[46].height = 38;
                        gWindows[46].pos.x = ((gWindows[46].parent != -1) ? (gWindows[gWindows[46].parent].width / 2) : 320 / 2) - gWindows[46].width / 2;

                        filemenu_8024C098 = 1;
                        temp_a0 = filemenu_menus[filemenu_8024C098];
                        temp_a0->page = 1;
                        filemenu_set_selected(temp_a0, 0, 1);
                    }
                }
                break;
        }
    }

    if (filemenu_pressedButtons & 0x4000) {
        switch (menu->page) {
            case 0:
                filemenu_set_selected(menu, 2, 2);
                break;
            case 1:
                filemenu_set_selected(menu, 1, 2);
                break;
            case 2:
                filemenu_set_selected(menu, 1, 2);
                break;
            case 3:
                filemenu_set_selected(menu, 1, 2);
                break;
            case 4:
                filemenu_set_selected(menu, 1, 2);
                break;
        }

        switch (menu->page) {
            case 0:
                set_window_update(0x33, filemenu_update_hidden_options_left);
                set_window_update(0x34, filemenu_update_hidden_options_right);
                set_window_update(0x35, filemenu_update_hidden_options_bottom);
                set_window_update(0x36, filemenu_update_hidden_options_bottom);
                set_window_update(0x37, filemenu_update_hidden_options_bottom);
                set_window_update(0x38, filemenu_update_hidden_options_left);
                set_window_update(0x39, filemenu_update_hidden_options_right);
                set_window_update(0x3A, filemenu_update_hidden_options_left);
                set_window_update(0x3B, filemenu_update_hidden_options_right);
                set_window_update(0x2D, filemenu_update_hidden_title);
                sfx_play_sound(SOUND_D6);
                set_game_mode(0xF);
                break;
            case 1:
                menu->page = 0;
                filemenu_set_selected(menu, 0, 2);
                set_window_update(0x33, filemenu_update_show_options_left);
                set_window_update(0x34, filemenu_update_show_options_right);
                set_window_update(0x35, filemenu_update_show_options_bottom);
                set_window_update(0x37, filemenu_update_show_options_bottom);
                sfx_play_sound(SOUND_MENU_BACK);
                break;
            case 3:
                menu->page = 0;
                filemenu_set_selected(menu, 1, 2);
                set_window_update(0x33, filemenu_update_show_options_left);
                set_window_update(0x34, filemenu_update_show_options_right);
                set_window_update(0x35, filemenu_update_show_options_bottom);
                set_window_update(0x37, filemenu_update_show_options_bottom);
                sfx_play_sound(SOUND_MENU_BACK);
                break;
            case 4:
                menu->page = 3;
                filemenu_set_selected(menu, (filemenu_loadedFileIdx % 2) * 2, filemenu_loadedFileIdx / 2);
                sfx_play_sound(SOUND_MENU_BACK);
                break;
            case 2:
                sfx_play_sound(SOUND_MENU_BACK);
                set_game_mode(0xD);
                break;
        }
    }
}
#else
INCLUDE_ASM(s32, "165490", filemenu_main_handle_input);
#endif

INCLUDE_ASM(s32, "165490", filemenu_main_update);

void filemenu_main_cleanup(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(filemenu_hudElemIDs); i++) {
        hud_element_free(filemenu_hudElemIDs[i]);
    }
}
