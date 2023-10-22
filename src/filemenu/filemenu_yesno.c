#include "common.h"
#include "filemenu.h"
#include "fio.h"
#include "game_modes.h"

#if VERSION_IQUE
#define DELETE_FILE_DELETE_X            20
#define DELETE_FILE_FILE_X              50
#define DELETE_FILE_NUMBER_X            93
#define DELETE_FILE_QMARK_X             92
#define COPY_FILE_NUMBER_X              49
#define START_GAME_START_WITH_X         37
#define START_GAME_FILE_X               100
#define START_GAME_NUMBER_X             142
#define START_GAME_QMARK_X              140
#define NUMBER_OFFSET_Y                 1
#else
#define DELETE_FILE_DELETE_X            10
#define DELETE_FILE_FILE_X              60
#define DELETE_FILE_NUMBER_X            98
#define DELETE_FILE_QMARK_X             99
#define COPY_FILE_NUMBER_X              48
#define START_GAME_START_WITH_X         10
#define START_GAME_FILE_X               127
#define START_GAME_NUMBER_X             165
#define START_GAME_QMARK_X              162
#define NUMBER_OFFSET_Y                 0
#endif

u8 filemenu_yesno_gridData[] = {
    0, 1,
    0, 1,
    0, 1,
    0, 1,
#if !VERSION_PAL
    0, 1
#endif
};

MenuWindowBP filemenu_yesno_windowBPs[] = {
    {
        .windowID = WINDOW_ID_FILEMENU_YESNO_OPTIONS,
        .unk_01 = 0,
        .pos = { .x = 0, .y = 0 },
        .width = 0,
        .height = 0,
        .priority = WINDOW_PRIORITY_64,
        .fpDrawContents = &filemenu_yesno_draw_options_contents,
        .tab = NULL,
        .parentID = -1,
        .fpUpdate = { WINDOW_UPDATE_HIDE },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[19] }
    },
    {
        .windowID = WINDOW_ID_FILEMENU_YESNO_PROMPT,
        .unk_01 = 0,
        .pos = { .x = 0, .y = 0 },
        .width = 0,
        .height = 0,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_yesno_draw_prompt_contents,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_YESNO_OPTIONS,
        .fpUpdate = { WINDOW_UPDATE_SHOW },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[19] }
    },
};

MenuPanel filemenu_yesno_menuBP = {
    .initialized = FALSE,
    .col = 0,
    .row = 0,
    .selected = 0,
    .page = 0,
    .numCols = 1,
    .numRows = 2,
    .numPages = 0,
    .gridData = filemenu_yesno_gridData,
    .fpInit = &filemenu_yesno_init,
    .fpHandleInput = &filemenu_yesno_handle_input,
    .fpUpdate = &filemenu_yesno_update,
    .fpCleanup = &filemenu_yesno_cleanup
};

void filemenu_yesno_draw_options_contents(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    s32 xOffset1;
    s32 yOffset1;
    s32 xOffset2;
    s32 yOffset2;
    s32 cursorGoalXOffset;
    s32 cursorGoalYOffset;

    switch (menu->page) {
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
#if !VERSION_PAL
        case 4:
            xOffset1 = 28;
            yOffset1 = 4;
            xOffset2 = 28;
            yOffset2 = 21;
            break;
#endif
    }

    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_YES), baseX + xOffset1, baseY + yOffset1, 0xFF, 0, 0);
    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_NO), baseX + xOffset2, baseY + yOffset2, 0xFF, 0, 0);

    if (filemenu_currentMenu == 1) {
        if (menu->selected == 0) {
            cursorGoalXOffset = xOffset1 - 10;
            cursorGoalYOffset = yOffset1 + 8;
        } else {
            cursorGoalXOffset = xOffset2 - 10;
            cursorGoalYOffset = yOffset2 + 8;
        }
        filemenu_set_cursor_goal_pos(WINDOW_ID_FILEMENU_YESNO_OPTIONS, baseX + cursorGoalXOffset, baseY + cursorGoalYOffset);
    }
}

#if VERSION_PAL
INCLUDE_ASM(void, "filemenu/filemenu_yesno", filemenu_yesno_draw_prompt_contents);
#else
void filemenu_yesno_draw_prompt_contents(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    s32 xOffset;
    s32 i;

    switch (menu->page) {
        case 0:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_DELETE), baseX + DELETE_FILE_DELETE_X, baseY + 4, 0xFF, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_22), baseX + DELETE_FILE_FILE_X, baseY + 4, 0xFF, 0, 0);
            draw_number(filemenu_menus[0]->selected + 1, baseX + DELETE_FILE_NUMBER_X, baseY + 6 + NUMBER_OFFSET_Y, DRAW_NUMBER_CHARSET_NORMAL, MSG_PAL_WHITE, 0xFF, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_QUESTION), baseX + DELETE_FILE_QMARK_X, baseY + 4, 0xFF, 0, 0);            break;
        case 3:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_22), baseX + 10, baseY + 4, 0xFF, 0, 0);
            draw_number(filemenu_menus[0]->selected + 1, baseX + COPY_FILE_NUMBER_X, baseY + 6 + NUMBER_OFFSET_Y, DRAW_NUMBER_CHARSET_NORMAL, MSG_PAL_WHITE, 0xFF, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_WILL_BE_DELETED), baseX + 49, baseY + 4, 0xFF, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_OK_TO_COPY_TO_THIS_FILE), baseX + 10, baseY + 18, 0xFF, 0, 0);
            break;
        case 1:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_OVERRIDE_TO_NEW_DATA), baseX + 10, baseY + 4, 0xFF, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_SAVE_OK), baseX + 10, baseY + 18, 0xFF, 0, 0);
            break;
        case 2:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_NAME_IS), baseX + 10, baseY + 6, 0xFF, 0, 0);

            for (i = ARRAY_COUNT(filemenu_filename) - 1; i >= 0; i--) {
                if (filemenu_filename[i] != 0xF7) {
                    break;
                }
            }

            xOffset = (147 - (i * 11)) / 2;
            filemenu_draw_file_name(filemenu_filename, i + 1, baseX + xOffset, baseY + 22, 0xFF, 0, 8, 0xB);
            xOffset += (i + 1) * 11;
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_PERIOD_20), baseX + xOffset, baseY + 22, 0xFF, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_OK), baseX + 70, baseY + 38, 0xFF, 0, 0);
            break;
        case 4:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_START_GAME_WITH), baseX + START_GAME_START_WITH_X, baseY + 4, 0xFF, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_22), baseX + START_GAME_FILE_X, baseY + 4, 0xFF, 0, 0);
            draw_number(filemenu_menus[0]->selected + 1, baseX + START_GAME_NUMBER_X, baseY + 6 + NUMBER_OFFSET_Y, DRAW_NUMBER_CHARSET_NORMAL, MSG_PAL_WHITE, 0xFF, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_QUESTION), baseX + START_GAME_QMARK_X, baseY + 4, 0xFF, 0, 0);
            break;
    }
}
#endif

void filemenu_yesno_init(MenuPanel* tab) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(filemenu_yesno_windowBPs); i++) {
        filemenu_yesno_windowBPs[i].tab = tab;
    }

    setup_pause_menu_tab(filemenu_yesno_windowBPs, ARRAY_COUNT(filemenu_yesno_windowBPs));
    tab->initialized = TRUE;
}

#if VERSION_PAL
INCLUDE_ASM(void, "filemenu/filemenu_yesno", filemenu_yesno_handle_input);
#else
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
                        filemenu_currentMenu = 2;
                        filemenu_menus[filemenu_currentMenu]->page = 0;
                        gWindows[WINDOW_ID_FILEMENU_INFO].width = 182;
                        gWindows[WINDOW_ID_FILEMENU_INFO].height = 25;
                        gWindows[WINDOW_ID_FILEMENU_INFO].pos.x = ((gWindows[WINDOW_ID_FILEMENU_INFO].parent != -1)
                                            ? (gWindows[gWindows[WINDOW_ID_FILEMENU_INFO].parent].width / 2)
                                            : SCREEN_WIDTH / 2) - gWindows[WINDOW_ID_FILEMENU_INFO].width / 2;
                        gWindows[WINDOW_ID_FILEMENU_INFO].pos.y = ((gWindows[WINDOW_ID_FILEMENU_INFO].parent != -1)
                                            ? (gWindows[gWindows[WINDOW_ID_FILEMENU_INFO].parent].height / 2)
                                            : SCREEN_HEIGHT / 2) - gWindows[WINDOW_ID_FILEMENU_INFO].height / 2;
                        set_window_update(WINDOW_ID_FILEMENU_INFO, WINDOW_UPDATE_SHOW);
                        set_window_update(WINDOW_ID_FILEMENU_YESNO_OPTIONS, (s32)filemenu_update_hidden_name_confirm);

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
                        filemenu_currentMenu = 2;
                        filemenu_menus[filemenu_currentMenu]->page = 2;
                        gWindows[WINDOW_ID_FILEMENU_INFO].width = 154;
                        gWindows[WINDOW_ID_FILEMENU_INFO].height = 39;
                        gWindows[WINDOW_ID_FILEMENU_INFO].pos.x = ((gWindows[WINDOW_ID_FILEMENU_INFO].parent != -1)
                                             ? (gWindows[gWindows[WINDOW_ID_FILEMENU_INFO].parent].width / 2)
                                             : SCREEN_WIDTH / 2) - gWindows[WINDOW_ID_FILEMENU_INFO].width / 2;
                        gWindows[WINDOW_ID_FILEMENU_INFO].pos.y = ((gWindows[WINDOW_ID_FILEMENU_INFO].parent != -1)
                                             ? (gWindows[gWindows[WINDOW_ID_FILEMENU_INFO].parent].height / 2)
                                             : SCREEN_HEIGHT / 2) - gWindows[WINDOW_ID_FILEMENU_INFO].height / 2;
                        set_window_update(WINDOW_ID_FILEMENU_INFO, WINDOW_UPDATE_SHOW);
                        set_window_update(WINDOW_ID_FILEMENU_YESNO_OPTIONS, (s32)filemenu_update_hidden_name_confirm);
                        fio_load_game(filemenu_loadedFileIdx);
                        gSaveSlotMetadata[filemenu_iterFileIdx] = gSaveSlotMetadata[filemenu_loadedFileIdx];
                        fio_save_game(filemenu_iterFileIdx);
                        gSaveSlotHasData[filemenu_iterFileIdx] = TRUE;
                        break;
                    case 1:
                        filemenu_currentMenu = 2;
                        filemenu_menus[filemenu_currentMenu]->page = 1;
                        gWindows[WINDOW_ID_FILEMENU_INFO].width = 153;
                        gWindows[WINDOW_ID_FILEMENU_INFO].height = 25;
                        gWindows[WINDOW_ID_FILEMENU_INFO].pos.x = ((gWindows[WINDOW_ID_FILEMENU_INFO].parent != -1)
                                             ? (gWindows[gWindows[WINDOW_ID_FILEMENU_INFO].parent].width / 2)
                                             : SCREEN_WIDTH / 2) - gWindows[WINDOW_ID_FILEMENU_INFO].width / 2;
                        gWindows[WINDOW_ID_FILEMENU_INFO].pos.y = ((gWindows[WINDOW_ID_FILEMENU_INFO].parent != -1)
                                             ? (gWindows[gWindows[WINDOW_ID_FILEMENU_INFO].parent].height / 2)
                                             : SCREEN_HEIGHT / 2) - gWindows[WINDOW_ID_FILEMENU_INFO].height / 2;
                        set_window_update(WINDOW_ID_FILEMENU_INFO, WINDOW_UPDATE_SHOW);
                        set_window_update(WINDOW_ID_FILEMENU_YESNO_OPTIONS, (s32)filemenu_update_hidden_name_confirm);
                        gSaveSlotMetadata[filemenu_menus[0]->selected] = gSaveSlotMetadata[gGameStatusPtr->saveSlot];
                        fio_save_game(filemenu_menus[0]->selected);
                        gSaveSlotHasData[filemenu_menus[0]->selected] = TRUE;
                        break;
                    case 2:
                        clear_player_data();
                        clear_saved_variables();
                        gGameStatusPtr->areaID = AREA_KMR;
                        gGameStatusPtr->mapID = 11; //TODO hardcoded area/map IDs
                        gGameStatusPtr->entryID = 0;
                        evt_set_variable(NULL, GB_StoryProgress, STORY_INTRO);

                        slot2 = filemenu_menus[0]->selected;
                        for (i = 0; i < ARRAY_COUNT(gSaveSlotMetadata->filename); i++) {
                            gSaveSlotMetadata[slot2].filename[i] = filemenu_filename[i];
                        }
                        fio_save_game(slot2);
                        gSaveSlotHasData[slot2] = TRUE;
                        set_window_update(WINDOW_ID_FILEMENU_CREATEFILE_HEADER, (s32)filemenu_update_hidden_name_input);
                        set_window_update(WINDOW_ID_FILEMENU_KEYBOARD, (s32)filemenu_update_hidden_name_input);
                        set_window_update(WINDOW_ID_FILEMENU_TITLE, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_STEREO, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_MONO, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_OPTION_CENTER, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_OPTION_RIGHT, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_FILE0_INFO, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_FILE1_INFO, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_FILE2_INFO, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_FILE3_INFO, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_YESNO_OPTIONS, (s32)filemenu_update_hidden_name_confirm);
                        filemenu_currentMenu = 2;
                        filemenu_menus[2]->page = 3;
                        gWindows[WINDOW_ID_FILEMENU_INFO].width = 184;
                        gWindows[WINDOW_ID_FILEMENU_INFO].height = 25;
                        gWindows[WINDOW_ID_FILEMENU_INFO].pos.x = ((gWindows[WINDOW_ID_FILEMENU_INFO].parent != -1)
                                             ? (gWindows[gWindows[WINDOW_ID_FILEMENU_INFO].parent].width / 2)
                                             : SCREEN_WIDTH / 2) - gWindows[WINDOW_ID_FILEMENU_INFO].width / 2;
                        gWindows[WINDOW_ID_FILEMENU_INFO].pos.y = ((gWindows[WINDOW_ID_FILEMENU_INFO].parent != -1)
                                             ? (gWindows[gWindows[WINDOW_ID_FILEMENU_INFO].parent].height / 2)
                                             : SCREEN_HEIGHT / 2) - gWindows[WINDOW_ID_FILEMENU_INFO].height / 2;
                        set_window_update(WINDOW_ID_FILEMENU_INFO, WINDOW_UPDATE_SHOW);
                        break;
                    case 4:
                        slot3 = filemenu_menus[0]->selected;
                        if (gGameStatusPtr->soundOutputMode != 1 - gSaveGlobals.useMonoSound ||
                            slot3 != (u8)gSaveGlobals.lastFileSelected)
                        {
                            gSaveGlobals.useMonoSound = 1 - gGameStatusPtr->soundOutputMode;
                            gSaveGlobals.lastFileSelected = slot3;
                            fio_save_globals();
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
                        filemenu_currentMenu = 0;
                        set_window_update(WINDOW_ID_FILEMENU_YESNO_OPTIONS, (s32)filemenu_update_hidden_name_confirm);
                        break;
                    case 2:
                        filemenu_currentMenu = 3;
                        set_window_update(WINDOW_ID_FILEMENU_YESNO_OPTIONS, (s32)filemenu_update_hidden_name_confirm);
                        break;
                    case 4:
                        filemenu_currentMenu = 0;
                        slot4 = filemenu_menus[0]->selected;
                        set_window_update(WINDOW_ID_FILEMENU_TITLE, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_STEREO, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_MONO, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_OPTION_CENTER, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_OPTION_RIGHT, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_FILE0_INFO, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_FILE1_INFO, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_FILE2_INFO, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WINDOW_ID_FILEMENU_FILE3_INFO, (s32)filemenu_update_show_with_rotation);
                        set_window_update(slot4 + WINDOW_ID_FILEMENU_FILE0_INFO, (s32)filemenu_update_deselect_file);
                        set_window_update(WINDOW_ID_FILEMENU_YESNO_OPTIONS, WINDOW_UPDATE_HIDE);
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
                filemenu_currentMenu = 0;
                set_window_update(WINDOW_ID_FILEMENU_YESNO_OPTIONS, (s32)filemenu_update_hidden_name_confirm);
                break;
            case 2:
                filemenu_currentMenu = 3;
                set_window_update(WINDOW_ID_FILEMENU_YESNO_OPTIONS, (s32)filemenu_update_hidden_name_confirm);
                break;
            case 4:
                filemenu_currentMenu = 0;
                slot = filemenu_menus[0]->selected;
                set_window_update(WINDOW_ID_FILEMENU_TITLE, (s32)filemenu_update_show_with_rotation);
                set_window_update(WINDOW_ID_FILEMENU_STEREO, (s32)filemenu_update_show_with_rotation);
                set_window_update(WINDOW_ID_FILEMENU_MONO, (s32)filemenu_update_show_with_rotation);
                set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, (s32)filemenu_update_show_with_rotation);
                set_window_update(WINDOW_ID_FILEMENU_OPTION_CENTER, (s32)filemenu_update_show_with_rotation);
                set_window_update(WINDOW_ID_FILEMENU_OPTION_RIGHT, (s32)filemenu_update_show_with_rotation);
                set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, (s32)filemenu_update_show_with_rotation);
                set_window_update(WINDOW_ID_FILEMENU_FILE0_INFO, (s32)filemenu_update_show_with_rotation);
                set_window_update(WINDOW_ID_FILEMENU_FILE1_INFO, (s32)filemenu_update_show_with_rotation);
                set_window_update(WINDOW_ID_FILEMENU_FILE2_INFO, (s32)filemenu_update_show_with_rotation);
                set_window_update(WINDOW_ID_FILEMENU_FILE3_INFO, (s32)filemenu_update_show_with_rotation);
                set_window_update(slot + WINDOW_ID_FILEMENU_FILE0_INFO, (s32)filemenu_update_deselect_file);
                set_window_update(WINDOW_ID_FILEMENU_YESNO_OPTIONS, WINDOW_UPDATE_HIDE);
                break;
        }
    }
}
#endif

void filemenu_yesno_update(MenuPanel* menu) {
}

void filemenu_yesno_cleanup(MenuPanel* menu) {
}
