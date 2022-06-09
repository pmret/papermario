#include "pause_common.h"

void pause_stats_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_stats_init(MenuPanel* panel);
void pause_stats_handle_input(MenuPanel* panel);
void pause_stats_cleanup(MenuPanel* panel);

static s32 gPauseStatsIconIDs[12];

// Probably only used here, but could theoretically be used in the main menu too
typedef struct {
    s32 cursorX;
    s32 cursorY;
    s32 baseMsgID;
} StatsEntryData; // size = 0xC

HudScript* gStatsMenuElements[] = { &HES_MarioHeadSmall, &HES_StatBoots0, &HES_StatHammer0,
                                    &HES_StatusCoin, &HES_StatusStarPoint, &HES_StatStarPiece_1,
                                    &HES_Clock, &HES_StatusHeart, &HES_StatFp_1, &HES_StatBp,
                                    &HES_StatusStar1, &HES_StatTimes};
HudScript* gStatsBootsElements[] = { &HES_StatBoots0, &HES_StatBoots1, &HES_StatBoots2, &HES_StatBoots3 };
HudScript* gStatsHammerElements[] = { &HES_StatHammer0, &HES_StatHammer1, &HES_StatHammer2, &HES_StatHammer3 };
s32 gPauseStatsBootsMessages[] = { 59, 60, 61, 62 };
s32 gPauseStatsHammerMessages[] = { 63, 64, 65, 66 };
s8 gPauseStatsGridData[] = {
    0, 4,
    1, 5,
    1, 6,
    2, 7,
    2, 8,
    3, 9,
    3, 10
};
StatsEntryData gStatsMenuEntries[] = {
    {.cursorX =   9, .cursorY =  20, .baseMsgID = 33},
    {.cursorX =  17, .cursorY =  55, .baseMsgID = 34},
    {.cursorX =  17, .cursorY =  90, .baseMsgID = 35},
    {.cursorX =  17, .cursorY = 124, .baseMsgID = 36},
    {.cursorX = 138, .cursorY =  28, .baseMsgID = 37},
    {.cursorX = 138, .cursorY =  53, .baseMsgID = 40},
    {.cursorX = 132, .cursorY =  76, .baseMsgID = 44},
    {.cursorX = 125, .cursorY =  91, .baseMsgID = 45},
    {.cursorX = 125, .cursorY = 106, .baseMsgID = 46},
    {.cursorX = 125, .cursorY = 121, .baseMsgID = 47},
    {.cursorX = 125, .cursorY = 138, .baseMsgID = 49}
};
HudScript* gPauseStatsSPIncElements[] = { &HES_StatusSPIncrement1, &HES_StatusSPIncrement3,
                                          &HES_StatusSPIncrement2, &HES_StatusSPIncrement4,
                                          &HES_StatusSPIncrement5, &HES_StatusSPIncrement6,
                                          &HES_StatusSPIncrement7 };
HudScript* gPauseStatsStarElements[] = { &HES_StatusStar1, &HES_StatusStar3, &HES_StatusStar2,
                                         &HES_StatusStar4, &HES_StatusStar5, &HES_StatusStar6,
                                         &HES_StatusStar7 };
//s32 D_8024F46C[] = { -1, 1, 2, 4, 5, 7, 8 };
s32 D_8024F46C = -1;
s32 D_8024F470 = 1;
s32 D_8024F474 = 2;
s32 D_8024F478 = 4;
s32 D_8024F47C = 5;
s32 D_8024F480 = 7;
s32 D_8024F484 = 8;

MenuWindowBP gStatsMenuWindowBPs[] = {
    {
        .windowID = WINDOW_ID_PAUSE_STATS,
        .unk_01 = 0,
        .pos = { .x = 3, .y = 16 },
        .width = 289,
        .height = 154,
        .priority = 0,
        .fpDrawContents = &pause_stats_draw_contents,
        .tab = NULL,
        .parentID = WINDOW_ID_PAUSE_MAIN,
        .fpUpdate = { WINDOW_UPDATE_HIDE },
        .extraFlags = 0,
        .style = { .customStyle = &gPauseWS_12 }
    }
};
MenuPanel gPausePanelStats = {
    .initialized = FALSE,
    .col = 0,
    .row = 0,
    .selected = 0,
    .page = 0,
    .numCols = 2,
    .numRows = 7,
    .numPages = 0,
    .gridData = gPauseStatsGridData,
    .fpInit = &pause_stats_init,
    .fpHandleInput = &pause_stats_handle_input,
    .fpUpdate = NULL,
    .fpCleanup = &pause_stats_cleanup
};

INCLUDE_ASM(s32, "pause/138CC0", pause_stats_draw_contents);

void pause_stats_init(MenuPanel* panel) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPauseStatsIconIDs); i++) {
        s32 iconID = hud_element_create(gStatsMenuElements[i]);

        gPauseStatsIconIDs[i] = iconID;
        hud_element_set_flags(iconID, HUD_ELEMENT_FLAGS_80);
    }

    for (i = 0; i < ARRAY_COUNT(gStatsMenuWindowBPs); i++) {
        gStatsMenuWindowBPs[i].tab = panel;
    }

    setup_pause_menu_tab(gStatsMenuWindowBPs, ARRAY_COUNT(gStatsMenuWindowBPs));
    panel->initialized = TRUE;
}

void pause_stats_handle_input(MenuPanel* panel) {
    s32 initialSelection = panel->selected;
    s16 adjustedBootsLevel;
    s16 adjustedHammerLevel;
    s32 msgOffset;

    if (gPauseHeldButtons & BUTTON_STICK_LEFT) {
        while (1) {
            panel->col--;
            if (panel->col < 0) {
                panel->col = 0;
                break;
            } else if (panel->selected != MENU_PANEL_SELECTED_GRID_DATA(panel)) {
                break;
            }
        }
    }

    if (gPauseHeldButtons & BUTTON_STICK_RIGHT) {
        while (1) {
            panel->col++;
            if (panel->col >= panel->numCols) {
                panel->col = panel->numCols - 1;
                break;
            } else if (panel->selected != MENU_PANEL_SELECTED_GRID_DATA(panel)) {
                break;
            }
        }
    }

    if (gPauseHeldButtons & BUTTON_STICK_UP) {
        while (1) {
            panel->row--;
            if (panel->row < 0) {
                panel->row = 0;
                break;
            } else if (panel->selected != MENU_PANEL_SELECTED_GRID_DATA(panel)) {
                break;
            }
        }
    }

    if (gPauseHeldButtons & BUTTON_STICK_DOWN) {
        while (1) {
            panel->row++;
            if (panel->row >= panel->numRows) {
                panel->row = panel->numRows - 1;
                break;
            } else if (panel->selected != MENU_PANEL_SELECTED_GRID_DATA(panel)) {
                break;
            }
        }
    }

    panel->selected = MENU_PANEL_SELECTED_GRID_DATA(panel);
    if (panel->selected != initialSelection) {
        sfx_play_sound(SOUND_MENU_CHANGE_SELECTION);
    }

    msgOffset = 0;
    adjustedBootsLevel = gPlayerData.bootsLevel;
    adjustedHammerLevel = gPlayerData.hammerLevel;

    adjustedBootsLevel++;
    if (adjustedBootsLevel < 0) {
        adjustedBootsLevel = 0;
    }
    if (adjustedBootsLevel > 3) {
        adjustedBootsLevel = 3;
    }

    adjustedHammerLevel++;
    if (adjustedHammerLevel < 0) {
        adjustedHammerLevel = 0;
    }
    if (adjustedHammerLevel > 3) {
        adjustedHammerLevel = 3;
    }

    switch (gStatsMenuEntries[panel->selected].baseMsgID) {
        case 0x25:
            if (adjustedBootsLevel > 1) {
                msgOffset = adjustedBootsLevel - 1;
            }
            break;
        case 0x28:
            msgOffset = adjustedHammerLevel;
            break;
        case 0x2F:
            if (evt_get_variable(NULL, EVT_SAVE_FLAG_TUTORIAL_GOT_STAR_PIECE)) {
                msgOffset = 1;
            }
            break;
    }

    gPauseCurrentDescMsg = pause_get_menu_msg(gStatsMenuEntries[panel->selected].baseMsgID + msgOffset);
    gPauseCurrentDescIconScript = NULL;

    if (gPausePressedButtons & BUTTON_B) {
        sfx_play_sound(SOUND_MENU_BACK);
        gPauseMenuCurrentTab = 0;
    }
}

void pause_stats_cleanup(MenuPanel* panel) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPauseStatsIconIDs); i++) {
        hud_element_free(gPauseStatsIconIDs[i]);
    }
}
