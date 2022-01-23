#include "common.h"
#include "hud_element.h"

// Probably only used here, but could theoretically be used in the main menu too
typedef struct {
    s32 cursorX;
    s32 cursorY;
    s32 baseMsgID;
} StatsEntryData; // size = 0xC

extern HudScript HudScript_MarioHeadSmall[];
extern HudScript HudScript_StatBoots0[];
extern HudScript HudScript_StatBoots1[];
extern HudScript HudScript_StatBoots2[];
extern HudScript HudScript_StatBoots3[];
extern HudScript HudScript_StatHammer0[];
extern HudScript HudScript_StatHammer1[];
extern HudScript HudScript_StatHammer2[];
extern HudScript HudScript_StatHammer3[];
extern HudScript HudScript_StatusCoin[];
extern HudScript HudScript_StatusStarPoint[];
extern HudScript HudScript_StatStarPiece_1[];
extern HudScript HudScript_Clock[];
extern HudScript HudScript_StatusHeart[];
extern HudScript HudScript_StatFp_1[];
extern HudScript HudScript_StatBp[];
extern HudScript HudScript_StatusStar1[];
extern HudScript HudScript_StatusStar2[];
extern HudScript HudScript_StatusStar3[];
extern HudScript HudScript_StatusStar4[];
extern HudScript HudScript_StatusStar5[];
extern HudScript HudScript_StatusStar6[];
extern HudScript HudScript_StatusStar7[];
extern HudScript HudScript_StatTimes[];

extern s32 D_8026FB30;

void pause_stats_draw_contents(MenuPanel* panel, s32 arg1, s32 arg2);
void pause_stats_init(MenuPanel* panel);
void pause_stats_handle_input(MenuPanel* panel);
void pause_stats_cleanup(void);

HudScript* gStatsMenuElements[] = { HudScript_MarioHeadSmall, HudScript_StatBoots0, HudScript_StatHammer0,
                                       HudScript_StatusCoin, HudScript_StatusStarPoint, HudScript_StatStarPiece_1,
                                       HudScript_Clock, HudScript_StatusHeart, HudScript_StatFp_1, HudScript_StatBp,
                                       HudScript_StatusStar1, HudScript_StatTimes};
HudScript* gStatsBootsElements[] = { HudScript_StatBoots0, HudScript_StatBoots1, HudScript_StatBoots2, HudScript_StatBoots3 };
HudScript* gStatsHammerElements[] = { HudScript_StatHammer0, HudScript_StatHammer1, HudScript_StatHammer2, HudScript_StatHammer3 };
s32 D_8024F380[] = { 59, 60, 61, 62 };
s32 D_8024F390[] = { 63, 64, 65, 66 };
s32 D_8024F3A0[] = { 0x00040105, 0x01060207, 0x02080309, 0x030A0000 };
StatsEntryData gStatsMenuEntries[] = { {.cursorX =   9, .cursorY =  20, .baseMsgID = 33},
                                       {.cursorX =  17, .cursorY =  55, .baseMsgID = 34},
                                       {.cursorX =  17, .cursorY =  90, .baseMsgID = 35},
                                       {.cursorX =  17, .cursorY = 124, .baseMsgID = 36},
                                       {.cursorX = 138, .cursorY =  28, .baseMsgID = 37},
                                       {.cursorX = 138, .cursorY =  53, .baseMsgID = 40},
                                       {.cursorX = 132, .cursorY =  76, .baseMsgID = 44},
                                       {.cursorX = 125, .cursorY =  91, .baseMsgID = 45},
                                       {.cursorX = 125, .cursorY = 106, .baseMsgID = 46},
                                       {.cursorX = 125, .cursorY = 121, .baseMsgID = 47},
                                       {.cursorX = 125, .cursorY = 138, .baseMsgID = 49} };
s32 D_8024F434[] = { 0x80108298, 0x801082E8, 0x801082C0, 0x80108310, 0x80108338, 0x80108360, 0x80108388 };
HudScript* D_8024F450[] = { HudScript_StatusStar1, HudScript_StatusStar3, HudScript_StatusStar2,
                                 HudScript_StatusStar4, HudScript_StatusStar5, HudScript_StatusStar6,
                                 HudScript_StatusStar7 };
//s32 D_8024F46C[] = {-1, 1, 2, 4, 5, 7, 8};
s32 D_8024F46C = -1;
s32 D_8024F470 = 1;
s32 D_8024F474 = 2;
s32 D_8024F478 = 4;
s32 D_8024F47C = 5;
s32 D_8024F480 = 7;
s32 D_8024F484 = 8;

MenuWindowBP gStatsMenuWindowBPs[] = { { .windowID = 31,
                                         .unk_01 = 0,
                                         .pos = { .x = 3,
                                                  .y = 16 },
                                         .height = 289,
                                         .width = 154,
                                         .unk_0A = { 0, 0},
                                         .fpDrawContents = &pause_stats_draw_contents,
                                         .tab = NULL,
                                         .parentID = 0x16000000,
                                         .fpUpdate = 2,
                                         .unk_1C = 0,
                                         .style = 0x8026FBA0 } };
MenuPanel gPausePanelStats = { .unk_00 = {
                            .s = 0 },
                         .page = 0,
                         .numCols = 2,
                         .numRows = 7,
                         .numPages = 0,
                         .gridData = D_8024F3A0,
                         .fpInit = &pause_stats_init,
                         .fpHandleInput = &pause_stats_handle_input,
                         .fpUpdate = NULL,
                         .fpCleanup = &pause_stats_cleanup };

INCLUDE_ASM(s32, "pause/138CC0", pause_stats_draw_contents);

void pause_stats_init(MenuPanel* panel) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gStatsMenuIconIDs); i++) {
        s32 iconID = create_hud_element(gStatsMenuElements[i]);

        gStatsMenuIconIDs[i] = iconID;
        set_hud_element_flags(iconID, 0x80);
    }

    for (i = 0; i < ARRAY_COUNT(gStatsMenuWindowBPs); i++) {
        gStatsMenuWindowBPs[i].tab = panel;
    }

    setup_pause_menu_tab(gStatsMenuWindowBPs, ARRAY_COUNT(gStatsMenuWindowBPs));
    panel->unk_00.c.initialized = TRUE;
}

void pause_stats_handle_input(MenuPanel* panel) {
    s32 initialSelection = panel->unk_00.c.selected;
    s16 adjustedBootsLevel;
    s16 adjustedHammerLevel;
    s32 msgOffset;

    if (gPauseMenuHeldButtons & BUTTON_STICK_LEFT) {
        while (1) {
            panel->unk_00.c.col--;
            if (panel->unk_00.c.col < 0) {
                panel->unk_00.c.col = 0;
                break;
            } else if (panel->unk_00.c.selected != panel->gridData[
                                            (panel->page * panel->numCols * panel->numRows)
                                          + (panel->numCols * panel->unk_00.c.row)
                                          + (panel->unk_00.c.col)]) {
                break;
            }
        }
    }

    if (gPauseMenuHeldButtons & BUTTON_STICK_RIGHT) {
        while (1) {
            panel->unk_00.c.col++;
            if (panel->unk_00.c.col >= panel->numCols) {
                panel->unk_00.c.col = panel->numCols - 1;
                break;
            } else if (panel->unk_00.c.selected != panel->gridData[
                                            (panel->page * panel->numCols * panel->numRows)
                                          + (panel->numCols * panel->unk_00.c.row)
                                          + (panel->unk_00.c.col)]) {
                break;
            }
        }
    }

    if (gPauseMenuHeldButtons & BUTTON_STICK_UP) {
        while (1) {
            panel->unk_00.c.row--;
            if (panel->unk_00.c.row < 0) {
                panel->unk_00.c.row = 0;
                break;
            } else if (panel->unk_00.c.selected != panel->gridData[
                                            (panel->page * panel->numCols * panel->numRows)
                                          + (panel->numCols * panel->unk_00.c.row)
                                          + (panel->unk_00.c.col)]) {
                break;
            }
        }
    }

    if (gPauseMenuHeldButtons & BUTTON_STICK_DOWN) {
        while (1) {
            panel->unk_00.c.row++;
            if (panel->unk_00.c.row >= panel->numRows) {
                panel->unk_00.c.row = panel->numRows - 1;
                break;
            } else if (panel->unk_00.c.selected != panel->gridData[
                                            (panel->page * panel->numCols * panel->numRows)
                                          + (panel->numCols * panel->unk_00.c.row)
                                          + (panel->unk_00.c.col)]) {
                break;
            }
        }
    }

    panel->unk_00.c.selected = panel->gridData[
                        (panel->page * panel->numCols * panel->numRows)
                      + (panel->numCols * panel->unk_00.c.row)
                      + (panel->unk_00.c.col)];
    if (panel->unk_00.c.selected != initialSelection) {
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

    switch (gStatsMenuEntries[panel->unk_00.c.selected].baseMsgID) {
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

    gPauseMenuCurrentDescMsg = pause_get_menu_msg(gStatsMenuEntries[panel->unk_00.c.selected].baseMsgID + msgOffset);
    gPauseMenuCurrentDescIconScript = NULL;

    if (gPauseMenuPressedButtons & BUTTON_B) {
        sfx_play_sound(SOUND_MENU_BACK);
        gPauseMenuCurrentTab = 0;
    }
}

void pause_stats_cleanup(void) {
    s32* iconIDs = gStatsMenuIconIDs;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gStatsMenuIconIDs); i++) {
        free_hud_element(iconIDs[i]);
    }
}
