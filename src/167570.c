#include "common.h"
#include "filemenu.h"
#include "fio.h"

extern SaveMetadata gSaveSlotMetadata[4];
extern u8 gSaveSlotHasData[4];
extern MenuWindowBP D_8024A0CC[2];

void filemenu_yesno_draw_options_contents(MenuPanel* tab, s32 posX, s32 posY) {
    s32 xOffset1;
    s32 yOffset1;
    s32 xOffset2;
    s32 yOffset2;
    s32 cursorGoalXOffset;
    s32 cursorGoalYOffset;

    switch (tab->page) {
        case 0:
            xOffset1 = 28;
            yOffset1 = 4;
            xOffset2 = 28;
            yOffset2 = 21;
            break;
        case 1:
            xOffset1 = 28;
            yOffset1 = 4;
            xOffset2 = 28;
            yOffset2 = 21;
            break;
        case 2:
            xOffset1 = 28;
            yOffset1 = 4;
            xOffset2 = 28;
            yOffset2 = 21;
            break;
        case 3:
            xOffset1 = 28;
            yOffset1 = 4;
            xOffset2 = 28;
            yOffset2 = 21;
            break;
        case 4:
            xOffset1 = 28;
            yOffset1 = 4;
            xOffset2 = 28;
            yOffset2 = 21;
            break;
    }

    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_YES), posX + xOffset1, posY + yOffset1, 0xFF, 0, 0);
    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_NO), posX + xOffset2, posY + yOffset2, 0xFF, 0, 0);

    if (filemenu_8024C098 == 1) {
        if (tab->selected == 0) {
            cursorGoalXOffset = xOffset1 - 10;
            cursorGoalYOffset = yOffset1 + 8;
        } else {
            cursorGoalXOffset = xOffset2 - 10;
            cursorGoalYOffset = yOffset2 + 8;
        }
        filemenu_set_cursor_goal_pos(0x32, posX + cursorGoalXOffset, posY + cursorGoalYOffset);
    }
}

void filemenu_yesno_draw_prompt_contents(MenuPanel* tab, s32 posX, s32 posY) {
    s32 xOffset;
    s32 i;

    switch (tab->page) {
        case 0:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_DELETE), posX + 10, posY + 4, 0xFF, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_22), posX + 60, posY + 4, 0xFF, 0, 0);
            draw_number(filemenu_menus[0]->selected + 1, posX + 98, posY + 6, 0, 0, 0xFF, 3);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_QUESTION), posX + 99, posY + 4, 0xFF, 0, 0);
            break;
        case 3:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_22), posX + 10, posY + 4, 0xFF, 0, 0);
            draw_number(filemenu_menus[0]->selected + 1, posX + 48, posY + 6, 0, 0, 0xFF, 3);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_WILL_BE_DELETED), posX + 49, posY + 4, 0xFF, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_OK_TO_COPY_TO_THIS_FILE), posX + 10, posY + 18, 0xFF, 0, 0);
            break;
        case 1:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_OVERRIDE_TO_NEW_DATA), posX + 10, posY + 4, 0xFF, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_SAVE_OK), posX + 10, posY + 18, 0xFF, 0, 0);
            break;
        case 2:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_NAME_IS), posX + 10, posY + 6, 0xFF, 0, 0);

            for (i = ARRAY_COUNT(filemenu_8024C110) - 1; i >= 0; i--) {
                if (filemenu_8024C110[i] != 0xF7) {
                    break;
                }
            }

            xOffset = (147 - (i * 11)) / 2;
            filemenu_draw_file_name(filemenu_8024C110, i + 1, posX + xOffset, posY + 22, 0xFF, 0, 8, 0xB);
            xOffset += (i + 1) * 11;
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_PERIOD_20), posX + xOffset, posY + 22, 0xFF, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_OK), posX + 70, posY + 38, 0xFF, 0, 0);
            break;
        case 4:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_START_GAME_WITH), posX + 10, posY + 4, 0xFF, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_22), posX + 127, posY + 4, 0xFF, 0, 0);
            draw_number(filemenu_menus[0]->selected + 1, posX + 165, posY + 6, 0, 0, 0xFF, 3);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_QUESTION), posX + 162, posY + 4, 0xFF, 0, 0);
            break;
    }
}

void filemenu_yesno_init(MenuPanel* tab) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8024A0CC); i++) {
        D_8024A0CC[i].tab = tab;
    }

    setup_pause_menu_tab(D_8024A0CC, ARRAY_COUNT(D_8024A0CC));
    tab->initialized = TRUE;
}

void filemenu_yesno_handle_input(MenuPanel* menu) {
    s32 oldSelected = menu->selected;

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

    menu->selected = MENU_PANEL_SELECTED_GRID_DATA(menu);

    if (oldSelected != menu->selected) {
        sfx_play_sound(SOUND_MENU_CHANGE_SELECTION);
    }

    if ((filemenu_pressedButtons & BUTTON_START) && menu->page == 4) {
        filemenu_set_selected(menu, 0, 0);
        filemenu_pressedButtons = BUTTON_A;
    }

    if (filemenu_pressedButtons & BUTTON_A) {
        u32 slot;
        u32 slot2;
        u32 slot3;
        u32 slot4;
        s32 i;

        sfx_play_sound(SOUND_MENU_NEXT);

        switch (menu->selected) {
            case 0:
                switch (menu->page) {
                    case 0:
                        filemenu_8024C098 = 2;
                        filemenu_menus[filemenu_8024C098]->page = 0;
                        gWindows[47].width = 182;
                        gWindows[47].height = 25;
                        gWindows[47].pos.x = ((gWindows[47].parent != -1)
                                            ? (gWindows[gWindows[47].parent].width / 2)
                                            : SCREEN_WIDTH / 2) - gWindows[47].width / 2;
                        gWindows[47].pos.y = ((gWindows[47].parent != -1)
                                            ? (gWindows[gWindows[47].parent].height / 2)
                                            : SCREEN_HEIGHT / 2) - gWindows[47].height / 2;
                        set_window_update(WINDOW_ID_47, WINDOW_UPDATE_SHOW);
                        set_window_update(WINDOW_ID_50, (s32)filemenu_update_hidden_name_confirm);

                        slot = filemenu_menus[0]->selected;
                        for (i = 0; i < ARRAY_COUNT(gSaveSlotMetadata->filename); i++) {
                            gSaveSlotMetadata[slot].filename[i] = 0xF7;
                        }
                        gSaveSlotMetadata[slot].level = 0;
                        gSaveSlotMetadata[slot].timePlayed = 0;
                        gSaveSlotMetadata[slot].spiritsRescued = 0;
                        fio_erase_game(slot);
                        gSaveSlotHasData[slot] = FALSE;
                        break;
                    case 3:
                        filemenu_8024C098 = 2;
                        filemenu_menus[filemenu_8024C098]->page = 2;
                        gWindows[47].width = 154;
                        gWindows[47].height = 39;
                        gWindows[47].pos.x = ((gWindows[47].parent != -1)
                                             ? (gWindows[gWindows[47].parent].width / 2)
                                             : SCREEN_WIDTH / 2) - gWindows[47].width / 2;
                        gWindows[47].pos.y = ((gWindows[47].parent != -1)
                                             ? (gWindows[gWindows[47].parent].height / 2)
                                             : SCREEN_HEIGHT / 2) - gWindows[47].height / 2;
                        set_window_update(WINDOW_ID_47, WINDOW_UPDATE_SHOW);
                        set_window_update(WINDOW_ID_50, (s32)filemenu_update_hidden_name_confirm);
                        fio_load_game(filemenu_loadedFileIdx);
                        gSaveSlotMetadata[filemenu_iterFileIdx] = gSaveSlotMetadata[filemenu_loadedFileIdx];
                        fio_save_game(filemenu_iterFileIdx);
                        gSaveSlotHasData[filemenu_iterFileIdx] = TRUE;
                        break;
                    case 1:
                        filemenu_8024C098 = 2;
                        filemenu_menus[filemenu_8024C098]->page = 1;
                        gWindows[47].width = 153;
                        gWindows[47].height = 25;
                        gWindows[47].pos.x = ((gWindows[47].parent != -1)
                                             ? (gWindows[gWindows[47].parent].width / 2)
                                             : SCREEN_WIDTH / 2) - gWindows[47].width / 2;
                        gWindows[47].pos.y = ((gWindows[47].parent != -1)
                                             ? (gWindows[gWindows[47].parent].height / 2)
                                             : SCREEN_HEIGHT / 2) - gWindows[47].height / 2;
                        set_window_update(WINDOW_ID_47, WINDOW_UPDATE_SHOW);
                        set_window_update(WINDOW_ID_50, (s32)filemenu_update_hidden_name_confirm);
                        gSaveSlotMetadata[filemenu_menus[0]->selected] = gSaveSlotMetadata[gGameStatusPtr->saveSlot];
                        fio_save_game(filemenu_menus[0]->selected);
                        gSaveSlotHasData[filemenu_menus[0]->selected] = TRUE;
                        break;
                    case 2:
                        clear_player_data();
                        clear_saved_variables();
                        gGameStatusPtr->areaID = 0;
                        gGameStatusPtr->mapID = 0xB;
                        gGameStatusPtr->entryID = 0;
                        evt_set_variable(NULL, EVT_STORY_PROGRESS, STORY_INTRO);

                        slot2 = filemenu_menus[0]->selected;
                        for (i = 0; i < ARRAY_COUNT(gSaveSlotMetadata->filename); i++) {
                            gSaveSlotMetadata[slot2].filename[i] = filemenu_8024C110[i];
                        }
                        fio_save_game(slot2);
                        gSaveSlotHasData[slot2] = TRUE;
                        set_window_update(WINDOW_ID_48, (s32)filemenu_update_hidden_name_input);
                        set_window_update(WINDOW_ID_49, (s32)filemenu_update_hidden_name_input);
                        set_window_update(WINDOW_ID_45, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_51, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_52, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_53, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_54, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_55, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_53, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_56, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_57, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_58, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_59, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_50, (s32)filemenu_update_hidden_name_confirm);
                        filemenu_8024C098 = 2;
                        filemenu_menus[2]->page = 3;
                        gWindows[47].width = 184;
                        gWindows[47].height = 25;
                        gWindows[47].pos.x = ((gWindows[47].parent != -1)
                                             ? (gWindows[gWindows[47].parent].width / 2)
                                             : SCREEN_WIDTH / 2) - gWindows[47].width / 2;
                        gWindows[47].pos.y = ((gWindows[47].parent != -1)
                                             ? (gWindows[gWindows[47].parent].height / 2)
                                             : SCREEN_HEIGHT / 2) - gWindows[47].height / 2;
                        set_window_update(WINDOW_ID_47, WINDOW_UPDATE_SHOW);
                        break;
                    case 4:
                        slot3 = filemenu_menus[0]->selected;
                        if (gGameStatusPtr->soundOutputMode != 1 - D_800D95E8.saveSlot ||
                            slot3 != (u8)D_800D95E8.saveCount)
                        {
                            D_800D95E8.saveSlot = 1 - gGameStatusPtr->soundOutputMode;
                            D_800D95E8.saveCount = slot3;
                            fio_flush_backups();
                        }
                        fio_load_game(slot3);
                        set_game_mode(GAME_MODE_END_FILE_SELECT);
                        break;
                }
                break;
            case 1:
                switch (menu->page) {
                    case 0:
                    case 1:
                    case 3:
                        filemenu_8024C098 = 0;
                        set_window_update(WINDOW_ID_50, (s32)filemenu_update_hidden_name_confirm);
                        break;
                    case 2:
                        filemenu_8024C098 = 3;
                        set_window_update(WINDOW_ID_50, (s32)filemenu_update_hidden_name_confirm);
                        break;
                    case 4:
                        filemenu_8024C098 = 0;
                        slot4 = filemenu_menus[0]->selected;
                        set_window_update(WINDOW_ID_45, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_51, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_52, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_53, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_54, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_55, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_53, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_56, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_57, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_58, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_59, (s32)filemenu_update_show_with_rotation);
                        set_window_update(slot4 + 0x38, (s32)filemenu_update_deselect_file);
                        set_window_update(WINDOW_ID_50, WINDOW_UPDATE_HIDE);
                        break;
                }
                break;
        }
    }

    if (filemenu_pressedButtons & BUTTON_B) {
        u32 slot;

        sfx_play_sound(SOUND_MENU_BACK);
        filemenu_set_selected(menu, 0, 1);

        switch (menu->page) {
            case 0:
            case 1:
            case 3:
                filemenu_8024C098 = 0;
                set_window_update(WINDOW_ID_50, (s32)filemenu_update_hidden_name_confirm);
                break;
            case 2:
                filemenu_8024C098 = 3;
                set_window_update(WINDOW_ID_50, (s32)filemenu_update_hidden_name_confirm);
                break;
            case 4:
                filemenu_8024C098 = 0;
                slot = filemenu_menus[0]->selected;
                set_window_update(WINDOW_ID_45, (s32)filemenu_update_show_with_rotation);
                set_window_update(WINDOW_ID_51, (s32)filemenu_update_show_with_rotation);
                set_window_update(WINDOW_ID_52, (s32)filemenu_update_show_with_rotation);
                set_window_update(WINDOW_ID_53, (s32)filemenu_update_show_with_rotation);
                set_window_update(WINDOW_ID_54, (s32)filemenu_update_show_with_rotation);
                set_window_update(WINDOW_ID_55, (s32)filemenu_update_show_with_rotation);
                set_window_update(WINDOW_ID_53, (s32)filemenu_update_show_with_rotation);
                set_window_update(WINDOW_ID_56, (s32)filemenu_update_show_with_rotation);
                set_window_update(WINDOW_ID_57, (s32)filemenu_update_show_with_rotation);
                set_window_update(WINDOW_ID_58, (s32)filemenu_update_show_with_rotation);
                set_window_update(WINDOW_ID_59, (s32)filemenu_update_show_with_rotation);
                set_window_update(slot + WINDOW_ID_56, (s32)filemenu_update_deselect_file);
                set_window_update(WINDOW_ID_50, WINDOW_UPDATE_HIDE);
                break;
        }
    }
}

void filemenu_yesno_update(void) {
}

void filemenu_yesno_cleanup(void) {
}
