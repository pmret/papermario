#include "common.h"
#include "filemenu.h"
#include "fio.h"
#include "game_modes.h"

#if VERSION_IQUE
#define DELETE_FILE_DELETE_X            20
#define DELETE_FILE_FILE_X              50
#define DELETE_FILE_NUMBER_X            43
#define DELETE_FILE_QMARK_X             (-1)
#define COPY_FILE_NUMBER_X              39
#define CREATE_FILE_FILE_X              164
#define START_GAME_START_WITH_X         37
#define START_GAME_FILE_X               63
#define START_GAME_NUMBER_X             42
#define START_GAME_QMARK_X              (-2)
#define NUMBER_OFFSET_Y                 1
#elif VERSION_PAL
extern u8 D_filemenu_80250924[4];
extern u8 D_filemenu_80250928[4];
extern u8 D_filemenu_802508FC[4];
extern u8 D_filemenu_8025092C[4];
extern u8 D_filemenu_80250934[4];
extern u8 D_filemenu_80250960[4];
extern u8 D_filemenu_80250908[4];
extern u8 D_filemenu_802508F8[4];
extern s8 D_filemenu_8025090C[4];
#define DELETE_FILE_DELETE_X            (D_filemenu_80250924[gCurrentLanguage])
#define DELETE_FILE_FILE_X              (D_filemenu_80250928[gCurrentLanguage])
#define DELETE_FILE_NUMBER_X            (D_filemenu_802508FC[gCurrentLanguage])
#define DELETE_FILE_QMARK_X             (D_filemenu_8025092C[gCurrentLanguage])
#define COPY_FILE_NUMBER_X              (D_filemenu_802508FC[gCurrentLanguage])
#define CREATE_FILE_FILE_X              (D_filemenu_80250960[gCurrentLanguage])
#define START_GAME_START_WITH_X         10
#define START_GAME_FILE_X               (D_filemenu_80250908[gCurrentLanguage])
#define START_GAME_NUMBER_X             (D_filemenu_802508F8[gCurrentLanguage])
#define START_GAME_QMARK_X              (D_filemenu_8025090C[gCurrentLanguage])
#define NUMBER_OFFSET_Y                 0
#else
#define DELETE_FILE_DELETE_X            10
#define DELETE_FILE_FILE_X              60
#define DELETE_FILE_NUMBER_X            38
#define DELETE_FILE_QMARK_X             1
#define COPY_FILE_NUMBER_X              38
#define CREATE_FILE_FILE_X              164
#define START_GAME_START_WITH_X         10
#define START_GAME_FILE_X               117
#define START_GAME_NUMBER_X             38
#define START_GAME_QMARK_X              (-3)
#define NUMBER_OFFSET_Y                 0
#endif

#if VERSION_PAL
extern u8 D_filemenu_80250930[4];
extern u8 D_filemenu_80250954[4];
extern u8 D_filemenu_80250964[4];
#define DELETE_FILE_MESSAGE_WIDTH       (D_filemenu_80250930[gCurrentLanguage])
#define COPY_FILE_MESSAGE_WIDTH         (D_filemenu_80250954[gCurrentLanguage])
#define CREATE_FILE_MESSAGE_WIDTH       (D_filemenu_80250964[gCurrentLanguage])
#else
#define DELETE_FILE_MESSAGE_WIDTH       182
#define COPY_FILE_MESSAGE_WIDTH         154
#define CREATE_FILE_MESSAGE_WIDTH       184
#endif

u8 filemenu_yesno_gridData[] = {
    0, 1,
#if !VERSION_PAL
    0, 1,
#endif
    0, 1,
    0, 1,
    0, 1,
};

MenuWindowBP filemenu_yesno_windowBPs[] = {
    {
        .windowID = WIN_FILES_CONFIRM_OPTIONS,
        .unk_01 = 0,
        .pos = { .x = 0, .y = 0 },
        .width = 0,
        .height = 0,
        .priority = WINDOW_PRIORITY_64,
        .fpDrawContents = &filemenu_yesno_draw_options_contents,
        .tab = nullptr,
        .parentID = -1,
        .fpUpdate = { WINDOW_UPDATE_HIDE },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[19] }
    },
    {
        .windowID = WIN_FILES_CONFIRM_PROMPT,
        .unk_01 = 0,
        .pos = { .x = 0, .y = 0 },
        .width = 0,
        .height = 0,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_yesno_draw_prompt_contents,
        .tab = nullptr,
        .parentID = WIN_FILES_CONFIRM_OPTIONS,
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
    .state = 0,
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

    switch (menu->state) {
        case FM_CONFIRM_DELETE:
            xOffset1 = 28;
            yOffset1 = 4;
            xOffset2 = 28;
            yOffset2 = 21;
            break;
#if !VERSION_PAL
        case FM_CONFIRM_DUMMY:
            xOffset1 = 28;
            yOffset1 = 4;
            xOffset2 = 28;
            yOffset2 = 21;
            break;
#endif
        case FM_CONFIRM_CREATE:
            xOffset1 = 28;
            yOffset1 = 4;
            xOffset2 = 28;
            yOffset2 = 21;
            break;
        case FM_CONFIRM_COPY:
            xOffset1 = 28;
            yOffset1 = 4;
            xOffset2 = 28;
            yOffset2 = 21;
            break;
        case FM_CONFIRM_START:
            xOffset1 = 28;
            yOffset1 = 4;
            xOffset2 = 28;
            yOffset2 = 21;
            break;
    }

    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_YES), baseX + xOffset1, baseY + yOffset1, 0xFF, 0, 0);
    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_NO), baseX + xOffset2, baseY + yOffset2, 0xFF, 0, 0);

    if (filemenu_currentMenu == FILE_MENU_CONFIRM) {
        if (menu->selected == 0) {
            cursorGoalXOffset = xOffset1 - 10;
            cursorGoalYOffset = yOffset1 + 8;
        } else {
            cursorGoalXOffset = xOffset2 - 10;
            cursorGoalYOffset = yOffset2 + 8;
        }
        filemenu_set_cursor_goal_pos(WIN_FILES_CONFIRM_OPTIONS, baseX + cursorGoalXOffset, baseY + cursorGoalYOffset);
    }
}

void filemenu_yesno_draw_prompt_contents(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    s32 xOffset;
    s32 i;

    switch (menu->state) {
        case FM_CONFIRM_DELETE:
            xOffset = DELETE_FILE_DELETE_X;
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_DELETE), baseX + xOffset, baseY + 4, 0xFF, 0, 0);
            xOffset = DELETE_FILE_FILE_X;
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_22), baseX + xOffset, baseY + 4, 0xFF, 0, 0);
            xOffset += DELETE_FILE_NUMBER_X;
            draw_number(filemenu_menus[FILE_MENU_MAIN]->selected + 1, baseX + xOffset, baseY + 6 + NUMBER_OFFSET_Y, DRAW_NUMBER_CHARSET_NORMAL, MSG_PAL_WHITE, 0xFF, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
            xOffset += DELETE_FILE_QMARK_X;
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_QUESTION), baseX + xOffset, baseY + 4, 0xFF, 0, 0);
            break;
        case FM_CONFIRM_COPY:
            xOffset = 10;
#if VERSION_PAL
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_28), baseX + xOffset, baseY + 4, 0xFF, 0, 0);
            xOffset += D_filemenu_80250934[gCurrentLanguage];
#endif
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_22), baseX + xOffset, baseY + 4, 0xFF, 0, 0);
            xOffset += COPY_FILE_NUMBER_X;
            draw_number(filemenu_menus[FILE_MENU_MAIN]->selected + 1, baseX + xOffset, baseY + 6 + NUMBER_OFFSET_Y, DRAW_NUMBER_CHARSET_NORMAL, MSG_PAL_WHITE, 0xFF, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
#if !VERSION_IQUE
            xOffset++;
#endif
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_WILL_BE_DELETED), baseX + xOffset, baseY + 4, 0xFF, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_OK_TO_COPY_TO_THIS_FILE), baseX + 10, baseY + 18, 0xFF, 0, 0);
            break;
#if !VERSION_PAL
        case FM_CONFIRM_DUMMY:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_OVERRIDE_TO_NEW_DATA), baseX + 10, baseY + 4, 0xFF, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_SAVE_OK), baseX + 10, baseY + 18, 0xFF, 0, 0);
            break;
#endif
        case FM_CONFIRM_CREATE:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_NAME_IS), baseX + 10, baseY + 6, 0xFF, 0, 0);

            for (i = ARRAY_COUNT(filemenu_filename) - 1; i >= 0; i--) {
                if (filemenu_filename[i] != MSG_CHAR_READ_SPACE) {
                    break;
                }
            }

            xOffset = ((CREATE_FILE_FILE_X - 17) - (i * 11)) / 2;
            filemenu_draw_file_name(filemenu_filename, i + 1, baseX + xOffset, baseY + 22, 0xFF, 0, 8, 0xB);
            xOffset += (i + 1) * 11;
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_PERIOD_20), baseX + xOffset, baseY + 22, 0xFF, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_OK), baseX + 70, baseY + 38, 0xFF, 0, 0);
            break;
        case FM_CONFIRM_START:
            xOffset = START_GAME_START_WITH_X;
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_START_GAME_WITH), baseX + xOffset, baseY + 4, 0xFF, 0, 0);
#if VERSION_PAL
            if (gCurrentLanguage == LANGUAGE_ES) {
                break;
            }
#endif
            xOffset += START_GAME_FILE_X;
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_22), baseX + xOffset, baseY + 4, 0xFF, 0, 0);
            xOffset += START_GAME_NUMBER_X;
            draw_number(filemenu_menus[FILE_MENU_MAIN]->selected + 1, baseX + xOffset, baseY + 6 + NUMBER_OFFSET_Y, DRAW_NUMBER_CHARSET_NORMAL, MSG_PAL_WHITE, 0xFF, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
            xOffset += START_GAME_QMARK_X;
#if VERSION_PAL
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_PAL_QUESTION_24), baseX + xOffset, baseY + 4, 0xFF, 0, 0);
#else
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_QUESTION), baseX + xOffset, baseY + 4, 0xFF, 0, 0);
#endif
            break;
    }
}

void filemenu_yesno_init(MenuPanel* tab) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(filemenu_yesno_windowBPs); i++) {
        filemenu_yesno_windowBPs[i].tab = tab;
    }

    setup_pause_menu_tab(filemenu_yesno_windowBPs, ARRAY_COUNT(filemenu_yesno_windowBPs));
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

    if ((filemenu_pressedButtons & BUTTON_START) && menu->state == FM_CONFIRM_START) {
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
            case 0: // YES
                switch (menu->state) {
                    case FM_CONFIRM_DELETE:
                        filemenu_currentMenu = FILE_MENU_MESSAGE;
                        filemenu_menus[FILE_MENU_MESSAGE]->state = FM_MESSAGE_DELETED;
                        gWindows[WIN_FILES_MESSAGE].width = DELETE_FILE_MESSAGE_WIDTH;
                        gWindows[WIN_FILES_MESSAGE].height = 25;
                        gWindows[WIN_FILES_MESSAGE].pos.x = CENTER_WINDOW_X(WIN_FILES_MESSAGE);
                        gWindows[WIN_FILES_MESSAGE].pos.y = CENTER_WINDOW_Y(WIN_FILES_MESSAGE);
                        set_window_update(WIN_FILES_MESSAGE, WINDOW_UPDATE_SHOW);
                        set_window_update(WIN_FILES_CONFIRM_OPTIONS, (s32)filemenu_update_hidden_name_confirm);

                        slot = filemenu_menus[FILE_MENU_MAIN]->selected;
                        for (i = 0; i < ARRAY_COUNT(gSaveSlotMetadata->filename); i++) {
                            gSaveSlotMetadata[slot].filename[i] = MSG_CHAR_READ_SPACE;
                        }
                        gSaveSlotMetadata[slot].level = 0;
                        gSaveSlotMetadata[slot].timePlayed = 0;
                        gSaveSlotMetadata[slot].spiritsRescued = 0;
                        fio_erase_game(slot);
                        gSaveSlotHasData[slot] = FALSE;
                        break;
                    case FM_CONFIRM_COPY:
                        filemenu_currentMenu = FILE_MENU_MESSAGE;
                        filemenu_menus[filemenu_currentMenu]->state = FM_MESSAGE_COPIED;
                        gWindows[WIN_FILES_MESSAGE].width = COPY_FILE_MESSAGE_WIDTH;
                        gWindows[WIN_FILES_MESSAGE].height = 39;
                        gWindows[WIN_FILES_MESSAGE].pos.x = CENTER_WINDOW_X(WIN_FILES_MESSAGE);
                        gWindows[WIN_FILES_MESSAGE].pos.y = CENTER_WINDOW_Y(WIN_FILES_MESSAGE);
                        set_window_update(WIN_FILES_MESSAGE, WINDOW_UPDATE_SHOW);
                        set_window_update(WIN_FILES_CONFIRM_OPTIONS, (s32)filemenu_update_hidden_name_confirm);
#if VERSION_PAL
                        if (fio_load_game(filemenu_loadedFileIdx)) {
                            gSaveSlotMetadata[filemenu_iterFileIdx] = gSaveSlotMetadata[filemenu_loadedFileIdx];
                            fio_save_game(filemenu_iterFileIdx);
                            gSaveSlotHasData[filemenu_iterFileIdx] = TRUE;
                        }
#else
                        fio_load_game(filemenu_loadedFileIdx);
                        gSaveSlotMetadata[filemenu_iterFileIdx] = gSaveSlotMetadata[filemenu_loadedFileIdx];
                        fio_save_game(filemenu_iterFileIdx);
                        gSaveSlotHasData[filemenu_iterFileIdx] = TRUE;
#endif
                        break;
#if !VERSION_PAL
                    case FM_CONFIRM_DUMMY:
                        filemenu_currentMenu = FILE_MENU_MESSAGE;
                        filemenu_menus[filemenu_currentMenu]->state = FM_MESSAGE_DUMMY;
                        gWindows[WIN_FILES_MESSAGE].width = 153;
                        gWindows[WIN_FILES_MESSAGE].height = 25;
                        gWindows[WIN_FILES_MESSAGE].pos.x = CENTER_WINDOW_X(WIN_FILES_MESSAGE);
                        gWindows[WIN_FILES_MESSAGE].pos.y = CENTER_WINDOW_Y(WIN_FILES_MESSAGE);
                        set_window_update(WIN_FILES_MESSAGE, WINDOW_UPDATE_SHOW);
                        set_window_update(WIN_FILES_CONFIRM_OPTIONS, (s32)filemenu_update_hidden_name_confirm);
                        gSaveSlotMetadata[filemenu_menus[FILE_MENU_MAIN]->selected] = gSaveSlotMetadata[gGameStatusPtr->saveSlot];
                        fio_save_game(filemenu_menus[FILE_MENU_MAIN]->selected);
                        gSaveSlotHasData[filemenu_menus[FILE_MENU_MAIN]->selected] = TRUE;
                        break;
#endif
                    case FM_CONFIRM_CREATE:
                        clear_player_data();
                        clear_saved_variables();
                        gGameStatusPtr->areaID = AREA_KMR;
                        gGameStatusPtr->mapID = 11; //TODO hardcoded area/map IDs
                        gGameStatusPtr->entryID = 0;
                        evt_set_variable(nullptr, GB_StoryProgress, STORY_INTRO);

                        slot2 = filemenu_menus[FILE_MENU_MAIN]->selected;
                        for (i = 0; i < ARRAY_COUNT(gSaveSlotMetadata->filename); i++) {
                            gSaveSlotMetadata[slot2].filename[i] = filemenu_filename[i];
                        }
                        fio_save_game(slot2);
                        gSaveSlotHasData[slot2] = TRUE;
                        set_window_update(WIN_FILES_INPUT_FIELD, (s32)filemenu_update_hidden_name_input);
                        set_window_update(WIN_FILES_INPUT_KEYBOARD, (s32)filemenu_update_hidden_name_input);
                        set_window_update(WIN_FILES_TITLE, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_STEREO, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_MONO, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_OPTION_LEFT, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_OPTION_CENTER, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_OPTION_RIGHT, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_OPTION_LEFT, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_SLOT1_BODY, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_SLOT2_BODY, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_SLOT3_BODY, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_SLOT4_BODY, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_CONFIRM_OPTIONS, (s32)filemenu_update_hidden_name_confirm);
                        filemenu_currentMenu = FILE_MENU_MESSAGE;
                        filemenu_menus[filemenu_currentMenu]->state = FM_MESSAGE_CREATED;
                        gWindows[WIN_FILES_MESSAGE].width = CREATE_FILE_MESSAGE_WIDTH;
                        gWindows[WIN_FILES_MESSAGE].height = 25;
                        gWindows[WIN_FILES_MESSAGE].pos.x = CENTER_WINDOW_X(WIN_FILES_MESSAGE);
                        gWindows[WIN_FILES_MESSAGE].pos.y = CENTER_WINDOW_Y(WIN_FILES_MESSAGE);
                        set_window_update(WIN_FILES_MESSAGE, WINDOW_UPDATE_SHOW);
                        break;
                    case FM_CONFIRM_START:
                        slot3 = filemenu_menus[FILE_MENU_MAIN]->selected;
#if VERSION_PAL
                        if (gGameStatusPtr->soundOutputMode != 1 - gSaveGlobals.useMonoSound ||
                            slot3 != (u8)gSaveGlobals.lastFileSelected || gCurrentLanguage != gSaveGlobals.language)
                        {
                            gSaveGlobals.useMonoSound = 1 - gGameStatusPtr->soundOutputMode;
                            gSaveGlobals.lastFileSelected = slot3;
                            gSaveGlobals.language = gCurrentLanguage;
                            fio_save_globals();
                        }
                        if (fio_load_game(slot3)) {
                            set_game_mode(GAME_MODE_END_FILE_SELECT);
                        } else {
                            filemenu_currentMenu = FILE_MENU_MAIN;
                            slot4 = filemenu_menus[FILE_MENU_MAIN]->selected;
                            set_window_update(WIN_FILES_TITLE, (s32)filemenu_update_show_with_rotation);
                            set_window_update(WIN_FILES_STEREO, (s32)filemenu_update_show_with_rotation);
                            set_window_update(WIN_FILES_MONO, (s32)filemenu_update_show_with_rotation);
                            set_window_update(WIN_FILES_OPTION_LEFT, (s32)filemenu_update_show_with_rotation);
                            set_window_update(WIN_FILES_OPTION_CENTER, (s32)filemenu_update_show_with_rotation);
                            set_window_update(WIN_FILES_OPTION_RIGHT, (s32)filemenu_update_show_with_rotation);
                            set_window_update(WIN_FILES_OPTION_LEFT, (s32)filemenu_update_show_with_rotation);
                            set_window_update(WIN_FILES_SLOT1_BODY, (s32)filemenu_update_show_with_rotation);
                            set_window_update(WIN_FILES_SLOT2_BODY, (s32)filemenu_update_show_with_rotation);
                            set_window_update(WIN_FILES_SLOT3_BODY, (s32)filemenu_update_show_with_rotation);
                            set_window_update(WIN_FILES_SLOT4_BODY, (s32)filemenu_update_show_with_rotation);
                            set_window_update(slot4 + WIN_FILES_SLOT1_BODY, (s32)filemenu_update_deselect_file);
                            set_window_update(WIN_FILES_CONFIRM_OPTIONS, WINDOW_UPDATE_HIDE);
                        }
#else
                        if (gGameStatusPtr->soundOutputMode != 1 - gSaveGlobals.useMonoSound ||
                            slot3 != (u8)gSaveGlobals.lastFileSelected)
                        {
                            gSaveGlobals.useMonoSound = 1 - gGameStatusPtr->soundOutputMode;
                            gSaveGlobals.lastFileSelected = slot3;
                            fio_save_globals();
                        }
                        fio_load_game(slot3);
                        set_game_mode(GAME_MODE_END_FILE_SELECT);
#endif
                        break;
                }
                break;
            case 1: // NO
                switch (menu->state) {
                    case FM_CONFIRM_DELETE:
#if !VERSION_PAL
                    case FM_CONFIRM_DUMMY:
#endif
                    case FM_CONFIRM_COPY:
                        filemenu_currentMenu = FILE_MENU_MAIN;
                        set_window_update(WIN_FILES_CONFIRM_OPTIONS, (s32)filemenu_update_hidden_name_confirm);
                        break;
                    case FM_CONFIRM_CREATE:
                        filemenu_currentMenu = FILE_MENU_INPUT_NAME;
                        set_window_update(WIN_FILES_CONFIRM_OPTIONS, (s32)filemenu_update_hidden_name_confirm);
                        break;
                    case FM_CONFIRM_START:
                        filemenu_currentMenu = FILE_MENU_MAIN;
                        slot4 = filemenu_menus[FILE_MENU_MAIN]->selected;
                        set_window_update(WIN_FILES_TITLE, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_STEREO, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_MONO, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_OPTION_LEFT, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_OPTION_CENTER, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_OPTION_RIGHT, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_OPTION_LEFT, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_SLOT1_BODY, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_SLOT2_BODY, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_SLOT3_BODY, (s32)filemenu_update_show_with_rotation);
                        set_window_update(WIN_FILES_SLOT4_BODY, (s32)filemenu_update_show_with_rotation);
                        set_window_update(slot4 + WIN_FILES_SLOT1_BODY, (s32)filemenu_update_deselect_file);
                        set_window_update(WIN_FILES_CONFIRM_OPTIONS, WINDOW_UPDATE_HIDE);
                        break;
                }
                break;
        }
    }

    if (filemenu_pressedButtons & BUTTON_B) {
        u32 slot;

        sfx_play_sound(SOUND_MENU_BACK);
        filemenu_set_selected(menu, 0, 1);

        switch (menu->state) {
            case FM_CONFIRM_DELETE:
#if !VERSION_PAL
            case FM_CONFIRM_DUMMY:
#endif
            case FM_CONFIRM_COPY:
                filemenu_currentMenu = FILE_MENU_MAIN;
                set_window_update(WIN_FILES_CONFIRM_OPTIONS, (s32)filemenu_update_hidden_name_confirm);
                break;
            case FM_CONFIRM_CREATE:
                filemenu_currentMenu = FILE_MENU_INPUT_NAME;
                set_window_update(WIN_FILES_CONFIRM_OPTIONS, (s32)filemenu_update_hidden_name_confirm);
                break;
            case FM_CONFIRM_START:
                filemenu_currentMenu = FILE_MENU_MAIN;
                slot = filemenu_menus[FILE_MENU_MAIN]->selected;
                set_window_update(WIN_FILES_TITLE, (s32)filemenu_update_show_with_rotation);
                set_window_update(WIN_FILES_STEREO, (s32)filemenu_update_show_with_rotation);
                set_window_update(WIN_FILES_MONO, (s32)filemenu_update_show_with_rotation);
                set_window_update(WIN_FILES_OPTION_LEFT, (s32)filemenu_update_show_with_rotation);
                set_window_update(WIN_FILES_OPTION_CENTER, (s32)filemenu_update_show_with_rotation);
                set_window_update(WIN_FILES_OPTION_RIGHT, (s32)filemenu_update_show_with_rotation);
                set_window_update(WIN_FILES_OPTION_LEFT, (s32)filemenu_update_show_with_rotation);
                set_window_update(WIN_FILES_SLOT1_BODY, (s32)filemenu_update_show_with_rotation);
                set_window_update(WIN_FILES_SLOT2_BODY, (s32)filemenu_update_show_with_rotation);
                set_window_update(WIN_FILES_SLOT3_BODY, (s32)filemenu_update_show_with_rotation);
                set_window_update(WIN_FILES_SLOT4_BODY, (s32)filemenu_update_show_with_rotation);
                set_window_update(slot + WIN_FILES_SLOT1_BODY, (s32)filemenu_update_deselect_file);
                set_window_update(WIN_FILES_CONFIRM_OPTIONS, WINDOW_UPDATE_HIDE);
                break;
        }
    }
}

void filemenu_yesno_update(MenuPanel* menu) {
}

void filemenu_yesno_cleanup(MenuPanel* menu) {
}
