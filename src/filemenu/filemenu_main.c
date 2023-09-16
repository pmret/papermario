#include "common.h"
#include "filemenu.h"
#include "hud_element.h"
#include "audio/public.h"
#include "fio.h"
#include "game_modes.h"

extern HudScript HES_Spirit1;
extern HudScript HES_Spirit2;
extern HudScript HES_Spirit3;
extern HudScript HES_Spirit4;
extern HudScript HES_Spirit5;
extern HudScript HES_Spirit6;
extern HudScript HES_Spirit7;
extern HudScript HES_Spirit1Missing;
extern HudScript HES_Spirit2Missing;
extern HudScript HES_Spirit3Missing;
extern HudScript HES_Spirit4Missing;
extern HudScript HES_Spirit5Missing;
extern HudScript HES_Spirit6Missing;
extern HudScript HES_Spirit7Missing;
extern HudScript HES_JpFile;
extern HudScript HES_JpFileDisabled;
extern HudScript HES_OptionMonoOn;
extern HudScript HES_OptionMonoOff;
extern HudScript HES_OptionStereoOn;
extern HudScript HES_OptionStereoOff;

#if VERSION_PAL
extern u8 D_filemenu_802508D0[4];
extern u8 D_filemenu_802508D4[4];
extern u8 D_filemenu_802508D8[4];
extern u8 D_filemenu_802508DC[4];
extern u8 D_filemenu_802508E0[4];
extern u8 D_filemenu_802508E4[4];
extern u8 D_filemenu_802508E8[4];
extern u8 D_filemenu_802508EC[4];
extern u8 D_filemenu_802508F0[4];
extern u8 D_filemenu_802508F4[4];
extern u8 D_filemenu_80250938[4];
extern u8 D_filemenu_8025093C[4];
#define COPY_OFFSET_X (D_filemenu_8025093C[gCurrentLanguage])
#define SAVE_OFFSET_X (D_filemenu_80250938[gCurrentLanguage])
#else
#define SAVE_OFFSET_X 25
#define COPY_OFFSET_X 16
#endif

BSS u8 filemenu_filename[8];

#if VERSION_IQUE
#define OFFSET_WIDTH        5
#define DELETE_OFFSET_X     9
#define CENTER_CANCEL_X     30
#define RIGHT_CANCEL_X      24
#define FILE_X              4
#define FILE_NUMBER_X       36
#define FILE_NAME_X         48
#define NUMBER_OFFSET_Y     1
#else
#define OFFSET_WIDTH        0
#define DELETE_OFFSET_X     8
#define CENTER_CANCEL_X     18
#define RIGHT_CANCEL_X      20
#define FILE_X              5
#define FILE_NUMBER_X       33
#define FILE_NAME_X         46
#define NUMBER_OFFSET_Y     0
#endif

extern HudScript HES_OptionMonoOn_de;
extern HudScript HES_OptionMonoOff_de;
extern HudScript HES_OptionStereoOn_de;
extern HudScript HES_OptionStereoOff_de;
extern HudScript HES_OptionMonoOn_fr;
extern HudScript HES_OptionMonoOff_fr;
extern HudScript HES_OptionStereoOn_fr;
extern HudScript HES_OptionStereoOff_fr;
extern HudScript HES_OptionMonoOn_es;
extern HudScript HES_OptionMonoOff_es;
extern HudScript HES_OptionStereoOn_es;
extern HudScript HES_OptionStereoOff_es;

HudScript* filemenu_main_hudElemScripts[][20] = {
    [LANGUAGE_DEFAULT] = {
        &HES_Spirit1, &HES_Spirit2, &HES_Spirit3, &HES_Spirit4, &HES_Spirit5, &HES_Spirit6, &HES_Spirit7,
        &HES_Spirit1Missing, &HES_Spirit2Missing, &HES_Spirit3Missing, &HES_Spirit4Missing, &HES_Spirit5Missing,
        &HES_Spirit6Missing, &HES_Spirit7Missing, &HES_JpFile, &HES_JpFileDisabled, &HES_OptionMonoOn,
        &HES_OptionMonoOff,
        &HES_OptionStereoOn, &HES_OptionStereoOff,
    },
#if VERSION_PAL
    [LANGUAGE_DE] = {
        &HES_Spirit1, &HES_Spirit2, &HES_Spirit3, &HES_Spirit4, &HES_Spirit5, &HES_Spirit6, &HES_Spirit7,
        &HES_Spirit1Missing, &HES_Spirit2Missing, &HES_Spirit3Missing, &HES_Spirit4Missing, &HES_Spirit5Missing,
        &HES_Spirit6Missing, &HES_Spirit7Missing, &HES_JpFile, &HES_JpFileDisabled, &HES_OptionMonoOn_de,
        &HES_OptionMonoOff_de,
        &HES_OptionStereoOn_de, &HES_OptionStereoOff_de,
    },
    [LANGUAGE_FR] = {
        &HES_Spirit1, &HES_Spirit2, &HES_Spirit3, &HES_Spirit4, &HES_Spirit5, &HES_Spirit6, &HES_Spirit7,
        &HES_Spirit1Missing, &HES_Spirit2Missing, &HES_Spirit3Missing, &HES_Spirit4Missing, &HES_Spirit5Missing,
        &HES_Spirit6Missing, &HES_Spirit7Missing, &HES_JpFile, &HES_JpFileDisabled, &HES_OptionMonoOn_fr,
        &HES_OptionMonoOff_fr,
        &HES_OptionStereoOn_fr, &HES_OptionStereoOff_fr,
    },
    [LANGUAGE_ES] = {
        &HES_Spirit1, &HES_Spirit2, &HES_Spirit3, &HES_Spirit4, &HES_Spirit5, &HES_Spirit6, &HES_Spirit7,
        &HES_Spirit1Missing, &HES_Spirit2Missing, &HES_Spirit3Missing, &HES_Spirit4Missing, &HES_Spirit5Missing,
        &HES_Spirit6Missing, &HES_Spirit7Missing, &HES_JpFile, &HES_JpFileDisabled, &HES_OptionMonoOn_es,
        &HES_OptionMonoOff_es,
        &HES_OptionStereoOn_es, &HES_OptionStereoOff_es,
    }
#endif
};

u8 filemenu_main_gridData[] = {
    0, 0, 1, 2, 2, 3, 4, 5, 6,
    0, 0, 1, 2, 2, 3, 6, 6, 6,
    0, 0, 1, 2, 2, 3, 6, 6, 6,
    0, 0, 1, 2, 2, 3, 6, 6, 6,
#if !VERSION_PAL
    0, 0, 1, 2, 2, 3, 6, 6, 6,
#endif
};

MenuWindowBP filemenu_main_windowBPs[] = {
    {
        .windowID = WINDOW_ID_FILEMENU_TITLE,
        .unk_01 = 0,
        .pos = { .x = 0, .y = 0 },
        .width = 0,
        .height = 0,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_draw_contents_title,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_MAIN,
        .fpUpdate = { .func = &filemenu_update_show_title },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[3] }
    },
    {
        .windowID = WINDOW_ID_FILEMENU_STEREO,
        .unk_01 = 0,
        .pos = { .x = -2, .y = 6 },
        .width = 68,
        .height = 20,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_draw_contents_stereo,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_MAIN,
        .fpUpdate = { .func = &filemenu_update_show_options_left },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[2] }
    },
    {
        .windowID = WINDOW_ID_FILEMENU_MONO,
        .unk_01 = 0,
        .pos = { .x = 221, .y = 6 },
        .width = 68,
        .height = 20,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_draw_contents_mono,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_MAIN,
        .fpUpdate = { .func = &filemenu_update_show_options_right },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[2] }
    },
    {
        .windowID = WINDOW_ID_FILEMENU_OPTION_LEFT,
        .unk_01 = 0,
        .pos = { .x = 5, .y = 171 },
        .width = 88,
        .height = 16,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_draw_contents_option_left,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_MAIN,
        .fpUpdate = { .func = &filemenu_update_show_options_bottom },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[4] }
    },
    {
        .windowID = WINDOW_ID_FILEMENU_OPTION_CENTER,
        .unk_01 = 0,
        .pos = { .x = 0, .y = 171 },
        .width = 88,
        .height = 16,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_draw_contents_option_center,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_MAIN,
        .fpUpdate = { .func = &filemenu_update_show_options_bottom },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[5] }
    },
    {
        .windowID = WINDOW_ID_FILEMENU_OPTION_RIGHT,
        .unk_01 = 0,
        .pos = { .x = 195, .y = 171 },
        .width = 88,
        .height = 16,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_draw_contents_option_right,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_MAIN,
        .fpUpdate = { .func = &filemenu_update_show_options_bottom },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[6] }
    },
    {
        .windowID = WINDOW_ID_FILEMENU_FILE2_INFO,
        .unk_01 = 0,
        .pos = { .x = 9, .y = 110 },
        .width = 130,
        .height = 54,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_draw_contents_file_2_info,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_MAIN,
        .fpUpdate = { .func = &filemenu_update_show_options_left },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[9] }
    },
    {
        .windowID = WINDOW_ID_FILEMENU_FILE2_TITLE,
        .unk_01 = 0,
        .pos = { .x = 3, .y = -8 },
        .width = 124 + OFFSET_WIDTH,
        .height = 15,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_draw_contents_file_2_title,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_FILE2_INFO,
        .fpUpdate = { WINDOW_UPDATE_SHOW },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[13] }
    },
    {
        .windowID = WINDOW_ID_FILEMENU_FILE3_INFO,
        .unk_01 = 0,
        .pos = { .x = 149, .y = 110 },
        .width = 130,
        .height = 54,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_draw_contents_file_3_info,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_MAIN,
        .fpUpdate = { .func = &filemenu_update_show_options_right },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[10] }
    },
    {
        .windowID = WINDOW_ID_FILEMENU_FILE3_TITLE,
        .unk_01 = 0,
        .pos = { .x = 3, .y = -8 },
        .width = 124 + OFFSET_WIDTH,
        .height = 15,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_draw_contents_file_3_title,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_FILE3_INFO,
        .fpUpdate = { WINDOW_UPDATE_SHOW },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[14] }
    },
    {
        .windowID = WINDOW_ID_FILEMENU_FILE0_INFO,
        .unk_01 = 0,
        .pos = { .x = 9, .y = 41 },
        .width = 130 + OFFSET_WIDTH,
        .height = 54,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_draw_contents_file_0_info,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_MAIN,
        .fpUpdate = { .func = &filemenu_update_show_options_left },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[7] }
    },
    {
        .windowID = WINDOW_ID_FILEMENU_FILE0_TITLE,
        .unk_01 = 0,
        .pos = { .x = 3, .y = -8 },
        .width = 124 + OFFSET_WIDTH,
        .height = 15,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_draw_contents_file_0_title,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_FILE0_INFO,
        .fpUpdate = { WINDOW_UPDATE_SHOW },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[11] }
    },
    {
        .windowID = WINDOW_ID_FILEMENU_FILE1_INFO,
        .unk_01 = 0,
        .pos = { .x = 149, .y = 41 },
        .width = 130,
        .height = 54,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_draw_contents_file_1_info,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_MAIN,
        .fpUpdate = { .func = &filemenu_update_show_options_right },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[8] }
    },
    {
        .windowID = WINDOW_ID_FILEMENU_FILE1_TITLE,
        .unk_01 = 0,
        .pos = { .x = 3, .y = -8 },
        .width = 124 + OFFSET_WIDTH,
        .height = 15,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_draw_contents_file_1_title,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_FILE1_INFO,
        .fpUpdate = { WINDOW_UPDATE_SHOW },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[12] }
    },
};

MenuPanel filemenu_main_menuBP = {
    .initialized = FALSE,
    .col = 0,
    .row = 0,
    .selected = 0,
    .page = 0,
    .numCols = 3,
    .numRows = 3,
    .numPages = 0,
    .gridData = filemenu_main_gridData,
    .fpInit = &filemenu_main_init,
    .fpHandleInput = &filemenu_main_handle_input,
    .fpUpdate = &filemenu_main_update,
    .fpCleanup = &filemenu_main_cleanup
};

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
        case PAGE_0:
            msgIdx = FILE_MESSAGE_SELECT_FILE_TO_START;
            xOffset = 9;
            yOffset = 4;
            break;
        case PAGE_1:
            msgIdx = FILE_MESSAGE_SELECT_FILE_TO_DELETE;
            xOffset = DELETE_OFFSET_X;
            yOffset = 4;
            break;
        case PAGE_3:
            msgIdx = FILE_MESSAGE_COPY_WHICH_FILE;
            xOffset = SAVE_OFFSET_X;
            yOffset = 4;
            break;
        case PAGE_4:
            msgIdx = FILE_MESSAGE_COPY_TO_WHICH_FILE;
            xOffset = COPY_OFFSET_X;
            yOffset = 4;
            break;
#if !VERSION_PAL
        case PAGE_2:
        default:
            msgIdx = FILE_MESSAGE_SELECT_FILE_TO_SAVE;
            xOffset = 10;
            yOffset = 4;
            break;
#endif
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
#if VERSION_PAL
    s32 offset = D_filemenu_802508E8[gCurrentLanguage];

    if (menu->col == 0 && menu->row == 2) {
        filemenu_set_cursor_goal_pos(WINDOW_ID_FILEMENU_OPTION_LEFT, (baseX + offset) - 10, baseY + 8);
    }
    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_DELETE_FILE), baseX + offset + OFFSET_WIDTH, baseY + 2, 255, 0, 1);
#else
    if (menu->page != 2) {
        if (menu->col == 0 && menu->row == 2) {
            filemenu_set_cursor_goal_pos(WINDOW_ID_FILEMENU_OPTION_LEFT, baseX, baseY + 8);
        }
        filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_DELETE_FILE), baseX + 8 + OFFSET_WIDTH, baseY + 2, 255, 0, 1);
    }
#endif
}

#if VERSION_PAL
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
            msgIdx = FILE_MESSAGE_CANCEL;
            xOffset = D_filemenu_802508F4[gCurrentLanguage];
            yOffset = 0;
            if (menu->col == 1 && menu->row == 2) {
                filemenu_set_cursor_goal_pos(WINDOW_ID_FILEMENU_OPTION_CENTER, baseX + xOffset - 10, baseY + 8);
            }
            break;
        default:
            msgIdx = FILE_MESSAGE_COPY_FILE;
            xOffset = D_filemenu_802508EC[gCurrentLanguage];
            yOffset = 0;
            if (menu->col == 1 && menu->row == 2) {
                filemenu_set_cursor_goal_pos(WINDOW_ID_FILEMENU_OPTION_CENTER, baseX + xOffset - 10, baseY + 8);
            }
            break;
    }

    filemenu_draw_message(filemenu_get_menu_message(msgIdx), baseX + xOffset, baseY + yOffset + 2, 255, 0, 1);
}
#else
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
            xOffset = CENTER_CANCEL_X;
            yOffset = 0;
            if (menu->col == 1 && menu->row == 2) {
                filemenu_set_cursor_goal_pos(WINDOW_ID_FILEMENU_OPTION_CENTER, baseX + CENTER_CANCEL_X - 10, baseY + 8);
            }
            break;
        default:
            msgIdx = FILE_MESSAGE_COPY_FILE;
            xOffset = 14;
            yOffset = 0;
            if (menu->col == 1 && menu->row == 2) {
                filemenu_set_cursor_goal_pos(WINDOW_ID_FILEMENU_OPTION_CENTER, baseX + 4, baseY + 8);
            }
            break;
    }

    filemenu_draw_message(filemenu_get_menu_message(msgIdx), baseX + xOffset, baseY + yOffset + 2, 255, 0, 1);
}
#endif

void filemenu_draw_contents_option_right(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
#if VERSION_PAL
    s32 offset = D_filemenu_802508F0[gCurrentLanguage];

    if (menu->col == 2 && menu->row == 2) {
        filemenu_set_cursor_goal_pos(WINDOW_ID_FILEMENU_OPTION_RIGHT, baseX + offset - 10, baseY + 8);
    }
    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_CANCEL), baseX + offset, baseY + 2, 255, 0, 1);
#else
    if (menu->page != 2) {
        if (menu->col == 2 && menu->row == 2) {
            filemenu_set_cursor_goal_pos(WINDOW_ID_FILEMENU_OPTION_RIGHT, baseX + 8, baseY + 8);
        }
        filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_CANCEL), baseX + RIGHT_CANCEL_X, baseY + 2, 255, 0, 1);
    }
#endif
}

void filemenu_draw_contents_file_info(s32 fileIdx,
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    s32 xOffset;
    s32 temp_s0_3;
    s32 temp_s1_2;
    s32 temp_s3_2;
    s32 temp_s3;
    s32 id;
    s32 i;
    const int MAX_DISPLAYED_TIME = 100*60*60*60 - 1; // 100 hours minus one frame at 60 fps

    if (!gSaveSlotHasData[fileIdx]) {
#if VERSION_PAL
        xOffset = D_filemenu_802508E0[gCurrentLanguage];
#else
        xOffset = 50;
#endif
        filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_NEW), baseX + xOffset, baseY + 20, 255, 0xA, 0);
        return;
    }

    if (gSaveSlotMetadata[fileIdx].timePlayed == 0) {
#if VERSION_PAL
        xOffset = D_filemenu_802508E4[gCurrentLanguage];
#else
        xOffset = 30;
#endif
        filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FIRST_PLAY), baseX + xOffset, baseY + 20, 255, 0xA, 0);
        return;
    }

#if VERSION_PAL
    xOffset = D_filemenu_802508D8[gCurrentLanguage];
#else
    xOffset = 34;
#endif
    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_LEVEL), baseX + xOffset, baseY + 10, 255, 0xA, 1);
    temp_s3_2 = gSaveSlotMetadata[fileIdx].level;
    temp_s3 = temp_s3_2;
    draw_number(temp_s3 / 10, baseX + 79, baseY + 10 + NUMBER_OFFSET_Y, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_STANDARD, 255, DRAW_NUMBER_STYLE_MONOSPACE);
    draw_number(temp_s3 % 10, baseX + 88, baseY + 10 + NUMBER_OFFSET_Y, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_STANDARD, 255, DRAW_NUMBER_STYLE_MONOSPACE);
#if VERSION_PAL
    xOffset = D_filemenu_802508DC[gCurrentLanguage];
#else
    xOffset = 11;
#endif
    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_PLAY_TIME), baseX + xOffset, baseY + 24, 255, 0xA, 1);

    temp_s3_2 = gSaveSlotMetadata[fileIdx].timePlayed;
    if (temp_s3_2 > MAX_DISPLAYED_TIME) {
        temp_s3_2 = MAX_DISPLAYED_TIME;
    }

    draw_number((temp_s3_2 / 2160000) % 10, baseX + 76, baseY + 24 + NUMBER_OFFSET_Y, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_STANDARD, 255, DRAW_NUMBER_STYLE_MONOSPACE);
    temp_s1_2 = temp_s3_2 / 216000;
    draw_number(temp_s1_2 - ((temp_s3_2 / 2160000) * 10), baseX + 85, baseY + 24 + NUMBER_OFFSET_Y, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_STANDARD, 255, DRAW_NUMBER_STYLE_MONOSPACE);
    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_PERIOD_13), baseX + 95, baseY + 23, 255, 0xA, 1);
    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_PERIOD_13), baseX + 95, baseY + 18, 255, 0xA, 1);
    temp_s0_3 = temp_s3_2 / 36000;
    draw_number(temp_s0_3 - (temp_s1_2 * 6), baseX + 100, baseY + 24 + NUMBER_OFFSET_Y, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_STANDARD, 255, DRAW_NUMBER_STYLE_MONOSPACE);
    draw_number((temp_s3_2 / 3600) - (temp_s0_3 * 10), baseX + 109, baseY + 24 + NUMBER_OFFSET_Y, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_STANDARD, 255, DRAW_NUMBER_STYLE_MONOSPACE);

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

#if VERSION_PAL
void filemenu_draw_contents_file_title(
    s32 fileIdx,
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening)
{
    if (filemenu_currentMenu == 0 && menu->selected == fileIdx) {
        filemenu_set_cursor_goal_pos(fileIdx + 60, baseX - 3, baseY + 8);
    }

    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_OK), baseX + FILE_X, baseY + 1, 255, 0, 1);

    if (!gSaveSlotHasData[fileIdx]) {
        filemenu_draw_message(filemenu_get_menu_message(fileIdx + FILE_MESSAGE_BASE_UNK),
            baseX + D_filemenu_802508D0[gCurrentLanguage], baseY + 1, 255, 0, 1);
    } else {
        s32 tmp = D_filemenu_802508D0[gCurrentLanguage];

        filemenu_draw_message(filemenu_get_menu_message(fileIdx + FILE_MESSAGE_BASE_UNK),
            baseX + tmp, baseY + 1, 255, 0, 1);

        tmp += D_filemenu_802508D4[gCurrentLanguage];
        tmp += 6;
        filemenu_draw_file_name(
            gSaveSlotMetadata[fileIdx].filename,
            ARRAY_COUNT(gSaveSlotMetadata[fileIdx].filename),
            baseX + tmp,
            baseY + 1, 255, 0, 1, 9);
        }
}
#else
void filemenu_draw_contents_file_title(
    s32 fileIdx,
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening)
{
    if (filemenu_currentMenu == 0 && menu->selected == fileIdx) {
        filemenu_set_cursor_goal_pos(fileIdx + 60, baseX - 3, baseY + 8);
    }

    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_26), baseX + FILE_X, baseY + 1, 255, 0, 1);

    if (!gSaveSlotHasData[fileIdx]) {
        draw_number(fileIdx + 1, baseX + FILE_NUMBER_X, baseY + 1 + NUMBER_OFFSET_Y, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_WHITE, 255, DRAW_NUMBER_STYLE_MONOSPACE);
    } else {
        draw_number(fileIdx + 1, baseX + FILE_NUMBER_X, baseY + 1 + NUMBER_OFFSET_Y, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_WHITE, 255, DRAW_NUMBER_STYLE_MONOSPACE);
        filemenu_draw_file_name(
            gSaveSlotMetadata[fileIdx].filename,
            ARRAY_COUNT(gSaveSlotMetadata[fileIdx].filename),
            baseX + FILE_NAME_X, baseY + 1, 255, 0, 1, 9);
    }
}
#endif

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

// TODO figure out how to merge these nicer
#if VERSION_PAL
void filemenu_main_init(MenuPanel* menu) {
    s32 halfWidth;
    s32 i;
    s32 tmp;

    for (i = 0; i < ARRAY_COUNT(filemenu_hudElemIDs); i++) {
        filemenu_hudElemIDs[i] = hud_element_create(filemenu_main_hudElemScripts[gCurrentLanguage][i]);
        hud_element_set_flags(filemenu_hudElemIDs[i], HUD_ELEMENT_FLAG_80);
    }

    for (i = 0; i < ARRAY_COUNT(filemenu_main_windowBPs); i++) {
        filemenu_main_windowBPs[i].tab = menu;
    }

    setup_pause_menu_tab(filemenu_main_windowBPs, ARRAY_COUNT(filemenu_main_windowBPs));
    menu->selected = MENU_PANEL_SELECTED_GRID_DATA(menu);

    gWindows[WINDOW_ID_FILEMENU_TITLE].pos.y = 1;
    gWindows[WINDOW_ID_FILEMENU_TITLE].width = 162;
    gWindows[WINDOW_ID_FILEMENU_TITLE].height = 25;

    halfWidth = gWindows[WINDOW_ID_FILEMENU_TITLE].width / 2;

    gWindows[WINDOW_ID_FILEMENU_TITLE].pos.x = gWindows[WINDOW_ID_FILEMENU_TITLE].parent != -1
        ? (gWindows[gWindows[WINDOW_ID_FILEMENU_TITLE].parent].width / 2) - halfWidth
        : SCREEN_WIDTH / 2 - halfWidth;

    tmp = 1;
    halfWidth = gWindows[WINDOW_ID_FILEMENU_OPTION_CENTER].width / 2;

    gWindows[WINDOW_ID_FILEMENU_OPTION_CENTER].pos.x = gWindows[WINDOW_ID_FILEMENU_OPTION_CENTER].parent != -1
        ? (gWindows[gWindows[WINDOW_ID_FILEMENU_OPTION_CENTER].parent].width / 2) - halfWidth
        : SCREEN_WIDTH / 2 - halfWidth;

    if (menu->page != 0) {
        set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, WINDOW_UPDATE_HIDE);
        set_window_update(WINDOW_ID_FILEMENU_OPTION_RIGHT, WINDOW_UPDATE_HIDE);
        set_window_update(WINDOW_ID_FILEMENU_STEREO, WINDOW_UPDATE_HIDE);
        set_window_update(WINDOW_ID_FILEMENU_MONO, WINDOW_UPDATE_HIDE);
    }
    menu->initialized = tmp;
}
#else
void filemenu_main_init(MenuPanel* menu) {
    s32 halfWidth;
    s32 halfWidth2;
    s16* posXPtr;
    s32 x;
    s32 i;
    s32 tmp;

    for (i = 0; i < ARRAY_COUNT(filemenu_hudElemIDs); i++) {
        filemenu_hudElemIDs[i] = hud_element_create(filemenu_main_hudElemScripts[gCurrentLanguage][i]);
        hud_element_set_flags(filemenu_hudElemIDs[i], HUD_ELEMENT_FLAG_80);
    }

    for (i = 0; i < ARRAY_COUNT(filemenu_main_windowBPs); i++) {
        filemenu_main_windowBPs[i].tab = menu;
    }

    setup_pause_menu_tab(filemenu_main_windowBPs, ARRAY_COUNT(filemenu_main_windowBPs));
    menu->selected = MENU_PANEL_SELECTED_GRID_DATA(menu);

    if (menu->page == 2) {
        gWindows[WINDOW_ID_FILEMENU_TITLE].pos.y = 1;
        gWindows[WINDOW_ID_FILEMENU_TITLE].width = 211;
        gWindows[WINDOW_ID_FILEMENU_TITLE].height = 25;
    } else {
        gWindows[WINDOW_ID_FILEMENU_TITLE].pos.y = 1;
        gWindows[WINDOW_ID_FILEMENU_TITLE].width = 162;
        gWindows[WINDOW_ID_FILEMENU_TITLE].height = 25;
    }

    halfWidth = gWindows[WINDOW_ID_FILEMENU_TITLE].width / 2;
    posXPtr = &gWindows[WINDOW_ID_FILEMENU_TITLE].pos.x;
    if (gWindows[WINDOW_ID_FILEMENU_TITLE].parent != -1) {
        x = (gWindows[gWindows[WINDOW_ID_FILEMENU_TITLE].parent].width / 2) - halfWidth;
    } else {
        x = SCREEN_WIDTH / 2 - halfWidth;
    }
    *posXPtr = x;

    halfWidth2 = gWindows[WINDOW_ID_FILEMENU_OPTION_CENTER].width / 2;
    posXPtr = &gWindows[WINDOW_ID_FILEMENU_OPTION_CENTER].pos.x;
    if (gWindows[WINDOW_ID_FILEMENU_OPTION_CENTER].parent != -1) {
        x = (gWindows[gWindows[WINDOW_ID_FILEMENU_OPTION_CENTER].parent].width / 2) - halfWidth2;
    } else {
        x = SCREEN_WIDTH / 2 - halfWidth2;
    }
    *posXPtr = x;

    if (menu->page != 0) {
        set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, WINDOW_UPDATE_HIDE);
        set_window_update(WINDOW_ID_FILEMENU_OPTION_RIGHT, WINDOW_UPDATE_HIDE);
        set_window_update(WINDOW_ID_FILEMENU_STEREO, WINDOW_UPDATE_HIDE);
        set_window_update(WINDOW_ID_FILEMENU_MONO, WINDOW_UPDATE_HIDE);
    }
    menu->initialized = 1;
}
#endif

#if VERSION_PAL
INCLUDE_ASM(void, "filemenu/filemenu_main", filemenu_main_handle_input);
#else
void filemenu_main_handle_input(MenuPanel* menu) {
    s32 originalSelected = menu->selected;
    s32 i;

    if (filemenu_heldButtons & BUTTON_STICK_LEFT) {
        while (TRUE) {
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
        sfx_play_sound(SOUND_FILE_MENU_MOVE_CURSOR);
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

    if ((filemenu_pressedButtons & BUTTON_START) && menu->page == 0 && menu->selected < 4) {
        filemenu_pressedButtons = BUTTON_A;
    }

    if (filemenu_pressedButtons & BUTTON_A) {
        s32 cond = FALSE;

        switch (menu->page) {
            case 0:
                if (menu->selected < 4 && !gSaveSlotHasData[menu->selected]) {
                    cond = TRUE;
                }

                if (cond) {
                    MenuPanel* temp_a0;
                    for (i = 0; i < ARRAY_COUNT(filemenu_filename); i++) {
                        filemenu_filename[i] = 0xF7;
                    }
                    filemenu_filename_pos = 0;
                    set_window_update(WINDOW_ID_FILEMENU_CREATEFILE_HEADER, (s32)filemenu_update_show_name_input);
                    set_window_update(WINDOW_ID_FILEMENU_KEYBOARD, (s32)filemenu_update_show_name_input);
                    set_window_update(WINDOW_ID_FILEMENU_TITLE, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(WINDOW_ID_FILEMENU_STEREO, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(WINDOW_ID_FILEMENU_MONO, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(WINDOW_ID_FILEMENU_OPTION_CENTER, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(WINDOW_ID_FILEMENU_OPTION_RIGHT, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(WINDOW_ID_FILEMENU_FILE0_INFO, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(WINDOW_ID_FILEMENU_FILE1_INFO, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(WINDOW_ID_FILEMENU_FILE2_INFO, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(WINDOW_ID_FILEMENU_FILE3_INFO, (s32)filemenu_update_hidden_with_rotation);
                    sfx_play_sound(SOUND_MENU_NEXT);
                    filemenu_currentMenu = 3;
                    temp_a0 = filemenu_menus[filemenu_currentMenu];
                    temp_a0->page = 0;
                    filemenu_set_selected(temp_a0, 0, 0);
                    break;
                }

                if (menu->selected == 6) {
                    set_window_update(WINDOW_ID_FILEMENU_STEREO, (s32)filemenu_update_hidden_options_left);
                    set_window_update(WINDOW_ID_FILEMENU_MONO, (s32)filemenu_update_hidden_options_right);
                    set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, (s32)filemenu_update_hidden_options_bottom);
                    set_window_update(WINDOW_ID_FILEMENU_OPTION_CENTER, (s32)filemenu_update_hidden_options_bottom);
                    set_window_update(WINDOW_ID_FILEMENU_OPTION_RIGHT, (s32)filemenu_update_hidden_options_bottom);
                    set_window_update(WINDOW_ID_FILEMENU_FILE0_INFO, (s32)filemenu_update_hidden_options_left);
                    set_window_update(WINDOW_ID_FILEMENU_FILE1_INFO, (s32)filemenu_update_hidden_options_right);
                    set_window_update(WINDOW_ID_FILEMENU_FILE2_INFO, (s32)filemenu_update_hidden_options_left);
                    set_window_update(WINDOW_ID_FILEMENU_FILE3_INFO, (s32)filemenu_update_hidden_options_right);
                    set_window_update(WINDOW_ID_FILEMENU_TITLE, (s32)filemenu_update_hidden_title);
                    sfx_play_sound(SOUND_FILE_MENU_OUT);
                    set_game_mode(GAME_MODE_END_FILE_SELECT);
                } else if (menu->selected == 4) {
                    sfx_play_sound(SOUND_MENU_NEXT);
                    menu->page = 1;
                    filemenu_set_selected(menu, 1, 2);
                    set_window_update(WINDOW_ID_FILEMENU_STEREO, (s32)filemenu_update_hidden_options_left);
                    set_window_update(WINDOW_ID_FILEMENU_MONO, (s32)filemenu_update_hidden_options_right);
                    set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, (s32)filemenu_update_hidden_options_bottom);
                    set_window_update(WINDOW_ID_FILEMENU_OPTION_RIGHT, (s32)filemenu_update_hidden_options_bottom);
                } else if (menu->selected == 5) {
                    sfx_play_sound(SOUND_MENU_NEXT);
                    menu->page = 3;
                    filemenu_set_selected(menu, 1, 2);
                    set_window_update(WINDOW_ID_FILEMENU_STEREO, (s32)filemenu_update_hidden_options_left);
                    set_window_update(WINDOW_ID_FILEMENU_MONO, (s32)filemenu_update_hidden_options_right);
                    set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, (s32)filemenu_update_hidden_options_bottom);
                    set_window_update(WINDOW_ID_FILEMENU_OPTION_RIGHT, (s32)filemenu_update_hidden_options_bottom);
                } else if (menu->selected < 4) {
                    MenuPanel* temp_a0;

                    sfx_play_sound(SOUND_MENU_NEXT);
                    set_window_update(WINDOW_ID_FILEMENU_TITLE, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(WINDOW_ID_FILEMENU_STEREO, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(WINDOW_ID_FILEMENU_MONO, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(WINDOW_ID_FILEMENU_OPTION_CENTER, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(WINDOW_ID_FILEMENU_OPTION_RIGHT, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(WINDOW_ID_FILEMENU_FILE0_INFO, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(WINDOW_ID_FILEMENU_FILE1_INFO, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(WINDOW_ID_FILEMENU_FILE2_INFO, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(WINDOW_ID_FILEMENU_FILE3_INFO, (s32)filemenu_update_hidden_with_rotation);
                    set_window_update(menu->selected + WINDOW_ID_FILEMENU_FILE0_INFO, (s32)filemenu_update_select_file);
                    sfx_play_sound(SOUND_MENU_NEXT);
                    set_window_update(WINDOW_ID_FILEMENU_YESNO_OPTIONS, WINDOW_UPDATE_SHOW);

                    gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].pos.y = 143;
                    gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].width = 69;
                    gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].height = 44;
                    gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].pos.x = ((gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].parent != -1)
                                        ? (gWindows[gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].parent].width / 2)
                                        : SCREEN_WIDTH / 2) - gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].width / 2;

                    gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].pos.y = -29;
                    gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].width = 192;
                    gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].height = 25;
                    gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].pos.x = ((gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].parent != -1)
                                         ? (gWindows[gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].parent].width / 2)
                                         : SCREEN_WIDTH / 2) - gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].width / 2;

                    filemenu_currentMenu = 1;
                    temp_a0 = filemenu_menus[filemenu_currentMenu];
                    temp_a0->page = 4;
                    filemenu_set_selected(temp_a0, 0, 0);
                }
                break;
            case 1:
                if (menu->selected == 6) {
                    sfx_play_sound(SOUND_MENU_NEXT);
                    menu->page = 0;
                    set_window_update(WINDOW_ID_FILEMENU_STEREO, (s32)filemenu_update_show_options_left);
                    set_window_update(WINDOW_ID_FILEMENU_MONO, (s32)filemenu_update_show_options_right);
                    set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, (s32)filemenu_update_show_options_bottom);
                    set_window_update(WINDOW_ID_FILEMENU_OPTION_RIGHT, (s32)filemenu_update_show_options_bottom);
                    filemenu_set_selected(menu, 0, 2);
                } else if (menu->selected < 4) {
                    if (gSaveSlotHasData[menu->selected]) {
                        MenuPanel* temp_a0;

                        sfx_play_sound(SOUND_MENU_NEXT);
                        set_window_update(WINDOW_ID_FILEMENU_YESNO_OPTIONS, (s32)filemenu_update_show_name_confirm);

                        gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].pos.y = 121;
                        gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].width = 69;
                        gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].height = 44;
                        gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].pos.x = ((gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].parent != -1)
                                         ? (gWindows[gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].parent].width / 2)
                                         : SCREEN_WIDTH / 2) - gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].width / 2;

                        gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].pos.y = -29;
                        gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].width = 118;
                        gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].height = 25;
                        gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].pos.x = ((gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].parent != -1)
                                         ? (gWindows[gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].parent].width / 2)
                                         : SCREEN_WIDTH / 2) - gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].width / 2;

                        filemenu_currentMenu = 1;
                        temp_a0 = filemenu_menus[filemenu_currentMenu];
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
                    set_window_update(WINDOW_ID_FILEMENU_STEREO, (s32)filemenu_update_show_options_left);
                    set_window_update(WINDOW_ID_FILEMENU_MONO, (s32)filemenu_update_show_options_right);
                    set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, (s32)filemenu_update_show_options_bottom);
                    set_window_update(WINDOW_ID_FILEMENU_OPTION_RIGHT, (s32)filemenu_update_show_options_bottom);
                    filemenu_set_selected(menu, 0, 1);
                } else if (menu->selected < 4) {
                    if (gSaveSlotHasData[menu->selected]) {
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
                        if (!gSaveSlotHasData[menu->selected]) {
                            sfx_play_sound(SOUND_MENU_NEXT);
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
                            set_window_update(WINDOW_ID_FILEMENU_YESNO_OPTIONS, WINDOW_UPDATE_HIDE);
                            fio_load_game(filemenu_loadedFileIdx);
                            gSaveSlotMetadata[filemenu_iterFileIdx] = gSaveSlotMetadata[filemenu_loadedFileIdx];
                            fio_save_game(filemenu_iterFileIdx);
                            gSaveSlotHasData[filemenu_iterFileIdx] = TRUE;
                        } else {
                            MenuPanel* temp_a0;

                            sfx_play_sound(SOUND_MENU_NEXT);
                            set_window_update(WINDOW_ID_FILEMENU_YESNO_OPTIONS, (s32)filemenu_update_show_name_confirm);
                            gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].pos.y = 121;
                            gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].width = 69;
                            gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].height = 44;
                            gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].pos.x = ((gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].parent != -1)
                                         ? (gWindows[gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].parent].width / 2)
                                         : SCREEN_WIDTH / 2) - gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].width / 2;

                            gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].pos.y = -43;
                            gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].width = 182;
                            gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].height = 39;
                            gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].pos.x = ((gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].parent != -1)
                                         ? (gWindows[gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].parent].width / 2)
                                         : SCREEN_WIDTH / 2) - gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].width / 2;

                            filemenu_currentMenu = 1;
                            temp_a0 = filemenu_menus[filemenu_currentMenu];
                            temp_a0->page = 3;
                            filemenu_set_selected(temp_a0, 0, 1);
                        }
                    }
                }
                break;
            case 2:
                if (menu->selected == 6) {
                    sfx_play_sound(SOUND_MENU_NEXT);
                    set_game_mode(GAME_MODE_END_LANGUAGE_SELECT);
                } else if (menu->selected < 4) {
                    if (!gSaveSlotHasData[menu->selected]) {
                        sfx_play_sound(SOUND_MENU_NEXT);
                        filemenu_currentMenu = 2;
                        filemenu_menus[filemenu_currentMenu]->page = 1;
                        set_window_update(WINDOW_ID_FILEMENU_MAIN, (s32)main_menu_window_update);
                        set_window_update(WINDOW_ID_FILEMENU_INFO, WINDOW_UPDATE_SHOW);
                        set_window_update(WINDOW_ID_FILEMENU_YESNO_OPTIONS, WINDOW_UPDATE_HIDE);
                        fio_save_game(menu->selected);
                        gSaveSlotHasData[menu->selected] = TRUE;
                    } else {
                        MenuPanel* temp_a0;

                        sfx_play_sound(SOUND_MENU_NEXT);
                        set_window_update(WINDOW_ID_FILEMENU_YESNO_OPTIONS, (s32)filemenu_update_show_name_confirm);
                        gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].pos.y = 127;
                        gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].width = 69;
                        gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].height = 44;
                        gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].pos.x = ((gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].parent != -1)
                                         ? (gWindows[gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].parent].width / 2)
                                         : SCREEN_WIDTH / 2) - gWindows[WINDOW_ID_FILEMENU_YESNO_OPTIONS].width / 2;

                        gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].pos.y = -50;
                        gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].width = 148;
                        gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].height = 38;
                        gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].pos.x = ((gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].parent != -1)
                                         ? (gWindows[gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].parent].width / 2)
                                         : SCREEN_WIDTH / 2) - gWindows[WINDOW_ID_FILEMENU_YESNO_PROMPT].width / 2;

                        filemenu_currentMenu = 1;
                        temp_a0 = filemenu_menus[filemenu_currentMenu];
                        temp_a0->page = 1;
                        filemenu_set_selected(temp_a0, 0, 1);
                    }
                }
                break;
        }
    }

    if (filemenu_pressedButtons & BUTTON_B) {
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
                set_window_update(WINDOW_ID_FILEMENU_STEREO, (s32)filemenu_update_hidden_options_left);
                set_window_update(WINDOW_ID_FILEMENU_MONO, (s32)filemenu_update_hidden_options_right);
                set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, (s32)filemenu_update_hidden_options_bottom);
                set_window_update(WINDOW_ID_FILEMENU_OPTION_CENTER, (s32)filemenu_update_hidden_options_bottom);
                set_window_update(WINDOW_ID_FILEMENU_OPTION_RIGHT, (s32)filemenu_update_hidden_options_bottom);
                set_window_update(WINDOW_ID_FILEMENU_FILE0_INFO, (s32)filemenu_update_hidden_options_left);
                set_window_update(WINDOW_ID_FILEMENU_FILE1_INFO, (s32)filemenu_update_hidden_options_right);
                set_window_update(WINDOW_ID_FILEMENU_FILE2_INFO, (s32)filemenu_update_hidden_options_left);
                set_window_update(WINDOW_ID_FILEMENU_FILE3_INFO, (s32)filemenu_update_hidden_options_right);
                set_window_update(WINDOW_ID_FILEMENU_TITLE, (s32)filemenu_update_hidden_title);
                sfx_play_sound(SOUND_FILE_MENU_OUT);
                set_game_mode(GAME_MODE_END_FILE_SELECT);
                break;
            case 1:
                menu->page = 0;
                filemenu_set_selected(menu, 0, 2);
                set_window_update(WINDOW_ID_FILEMENU_STEREO, (s32)filemenu_update_show_options_left);
                set_window_update(WINDOW_ID_FILEMENU_MONO, (s32)filemenu_update_show_options_right);
                set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, (s32)filemenu_update_show_options_bottom);
                set_window_update(WINDOW_ID_FILEMENU_OPTION_RIGHT, (s32)filemenu_update_show_options_bottom);
                sfx_play_sound(SOUND_MENU_BACK);
                break;
            case 3:
                menu->page = 0;
                filemenu_set_selected(menu, 1, 2);
                set_window_update(WINDOW_ID_FILEMENU_STEREO, (s32)filemenu_update_show_options_left);
                set_window_update(WINDOW_ID_FILEMENU_MONO, (s32)filemenu_update_show_options_right);
                set_window_update(WINDOW_ID_FILEMENU_OPTION_LEFT, (s32)filemenu_update_show_options_bottom);
                set_window_update(WINDOW_ID_FILEMENU_OPTION_RIGHT, (s32)filemenu_update_show_options_bottom);
                sfx_play_sound(SOUND_MENU_BACK);
                break;
            case 4:
                menu->page = 3;
                filemenu_set_selected(menu, (filemenu_loadedFileIdx % 2) * 2, filemenu_loadedFileIdx / 2);
                sfx_play_sound(SOUND_MENU_BACK);
                break;
            case 2:
                sfx_play_sound(SOUND_MENU_BACK);
                set_game_mode(GAME_MODE_END_LANGUAGE_SELECT);
                break;
        }
    }
}
#endif

void filemenu_main_update(MenuPanel* menu) {
    gWindowStyles[WINDOW_ID_FILEMENU_FILE0_INFO].customStyle = &filemenu_windowStyles[15];
    gWindowStyles[WINDOW_ID_FILEMENU_FILE1_INFO].customStyle = &filemenu_windowStyles[15];
    gWindowStyles[WINDOW_ID_FILEMENU_FILE2_INFO].customStyle = &filemenu_windowStyles[15];
    gWindowStyles[WINDOW_ID_FILEMENU_FILE3_INFO].customStyle = &filemenu_windowStyles[15];
    gWindowStyles[WINDOW_ID_FILEMENU_FILE0_TITLE].customStyle = &filemenu_windowStyles[17];
    gWindowStyles[WINDOW_ID_FILEMENU_FILE1_TITLE].customStyle = &filemenu_windowStyles[17];
    gWindowStyles[WINDOW_ID_FILEMENU_FILE2_TITLE].customStyle = &filemenu_windowStyles[17];
    gWindowStyles[WINDOW_ID_FILEMENU_FILE3_TITLE].customStyle = &filemenu_windowStyles[17];

    switch (menu->selected) {
        case 0:
            gWindowStyles[WINDOW_ID_FILEMENU_FILE0_INFO].customStyle = &filemenu_windowStyles[16];
            gWindowStyles[WINDOW_ID_FILEMENU_FILE0_TITLE].customStyle = &filemenu_windowStyles[18];
            break;
        case 1:
            gWindowStyles[WINDOW_ID_FILEMENU_FILE1_INFO].customStyle = &filemenu_windowStyles[16];
            gWindowStyles[WINDOW_ID_FILEMENU_FILE1_TITLE].customStyle = &filemenu_windowStyles[18];
            break;
        case 2:
            gWindowStyles[WINDOW_ID_FILEMENU_FILE2_INFO].customStyle = &filemenu_windowStyles[16];
            gWindowStyles[WINDOW_ID_FILEMENU_FILE2_TITLE].customStyle = &filemenu_windowStyles[18];
            break;
        case 3:
            gWindowStyles[WINDOW_ID_FILEMENU_FILE3_INFO].customStyle = &filemenu_windowStyles[16];
            gWindowStyles[WINDOW_ID_FILEMENU_FILE3_TITLE].customStyle = &filemenu_windowStyles[18];
            break;
    }

    if (filemenu_menus[0]->page == PAGE_4) {
        switch (filemenu_loadedFileIdx) {
            case 0:
                gWindowStyles[WINDOW_ID_FILEMENU_FILE0_INFO].customStyle = &filemenu_windowStyles[16];
                gWindowStyles[WINDOW_ID_FILEMENU_FILE0_TITLE].customStyle = &filemenu_windowStyles[18];
                return;
            case 1:
                gWindowStyles[WINDOW_ID_FILEMENU_FILE1_INFO].customStyle = &filemenu_windowStyles[16];
                gWindowStyles[WINDOW_ID_FILEMENU_FILE1_TITLE].customStyle = &filemenu_windowStyles[18];
                return;
            case 2:
                gWindowStyles[WINDOW_ID_FILEMENU_FILE2_INFO].customStyle = &filemenu_windowStyles[16];
                gWindowStyles[WINDOW_ID_FILEMENU_FILE2_TITLE].customStyle = &filemenu_windowStyles[18];
                return;
            case 3:
                gWindowStyles[WINDOW_ID_FILEMENU_FILE3_INFO].customStyle = &filemenu_windowStyles[16];
                gWindowStyles[WINDOW_ID_FILEMENU_FILE3_TITLE].customStyle = &filemenu_windowStyles[18];
                return;
        }
    }
}

void filemenu_main_cleanup(MenuPanel* menu) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(filemenu_hudElemIDs); i++) {
        hud_element_free(filemenu_hudElemIDs[i]);
    }
}
