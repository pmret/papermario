#include "pause_common.h"

void pause_stats_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_stats_init(MenuPanel* panel);
void pause_stats_handle_input(MenuPanel* panel);
void pause_stats_cleanup(MenuPanel* panel);

static s32 gPauseStatsIconIDs[12];

#if VERSION_IQUE
#define NUMBER_OFFSET_Y 2
#define ROW_1_Y 48
#define ROW_2_Y 49
#define ROW_3_Y 83
#define ROW_4_Y 116
#define COL_A_X 17
#define COL_B_X 80
#define COL_C_X 110
#define POS_1_X 60
#define POS_2_X 100
#else
#define NUMBER_OFFSET_Y 0
#define ROW_1_Y 51
#define ROW_2_Y 51
#define ROW_3_Y 85
#define ROW_4_Y 119
#define COL_A_X 25
#define COL_B_X 78
#define COL_C_X 105
#define POS_1_X 67
#define POS_2_X 106
#endif

// Probably only used here, but could theoretically be used in the main menu too
typedef struct {
    s32 cursorX;
    s32 cursorY;
    s32 baseMsgID;
} StatsEntryData; // size = 0xC

enum {
    STAT_ICON_MARIO         = 0,
    STAT_ICON_BOOTS         = 1,
    STAT_ICON_HAMMER        = 2,
    STAT_ICON_COIN          = 3,
    STAT_ICON_STAR_POINT    = 4,
    STAT_ICON_STAR_PIECE    = 5,
    STAT_ICON_CLOCK         = 6,
    STAT_ICON_HP            = 7,
    STAT_ICON_FP            = 8,
    STAT_ICON_BP            = 9,
    STAT_ICON_STAR          = 10,
    STAT_ICON_TIMES         = 11,
};

HudScript* gStatsMenuElements[] = {
    [STAT_ICON_MARIO]       &HES_MarioHeadSmall,
    [STAT_ICON_BOOTS]       &HES_StatBoots0,
    [STAT_ICON_HAMMER]      &HES_StatHammer0,
    [STAT_ICON_COIN]        &HES_StatusCoin,
    [STAT_ICON_STAR_POINT]  &HES_StatusStarPoint,
    [STAT_ICON_STAR_PIECE]  &HES_StatStarPiece_1,
    [STAT_ICON_CLOCK]       &HES_Clock,
    [STAT_ICON_HP]          &HES_StatusHeart,
    [STAT_ICON_FP]          &HES_StatFp_1,
    [STAT_ICON_BP]          &HES_StatBp,
    [STAT_ICON_STAR]        &HES_StatusStar1,
    [STAT_ICON_TIMES]       &HES_StatTimes,
};

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
    { .cursorX =   9, .cursorY =  20, .baseMsgID = PAUSE_MSG_TIP_CONTROLS },
    { .cursorX =  17, .cursorY =  55, .baseMsgID = PAUSE_MSG_TIP_HP },
    { .cursorX =  17, .cursorY =  90, .baseMsgID = PAUSE_MSG_TIP_FP },
    { .cursorX =  17, .cursorY = 124, .baseMsgID = PAUSE_MSG_TIP_BP },
    { .cursorX = 138, .cursorY =  28, .baseMsgID = PAUSE_MSG_TIP_BOOTS_1 },
    { .cursorX = 138, .cursorY =  53, .baseMsgID = PAUSE_MSG_TIP_HAMMER_0 },
    { .cursorX = 132, .cursorY =  76, .baseMsgID = PAUSE_MSG_TIP_STAR_POWER },
    { .cursorX = 125, .cursorY =  91, .baseMsgID = PAUSE_MSG_TIP_STAR_POINTS },
    { .cursorX = 125, .cursorY = 106, .baseMsgID = PAUSE_MSG_TIP_COINS },
    { .cursorX = 125, .cursorY = 121, .baseMsgID = PAUSE_MSG_TIP_SECRETS },
    { .cursorX = 125, .cursorY = 138, .baseMsgID = PAUSE_MSG_TIP_TIME },
}; 
HudScript* gPauseStatsSPIncElements[] = { &HES_StatusSPIncrement1, &HES_StatusSPIncrement3,
                                          &HES_StatusSPIncrement2, &HES_StatusSPIncrement4,
                                          &HES_StatusSPIncrement5, &HES_StatusSPIncrement6,
                                          &HES_StatusSPIncrement7 };
HudScript* gPauseStatsStarElements[] = { &HES_StatusStar1, &HES_StatusStar3, &HES_StatusStar2,
                                         &HES_StatusStar4, &HES_StatusStar5, &HES_StatusStar6,
                                         &HES_StatusStar7 };
s32 D_8024F46C[] = { -1, 1, 2, 4, 5, 7, 8 };
// s32 D_8024F46C = -1;
// s32 D_8024F470 = 1;
// s32 D_8024F474 = 2;
// s32 D_8024F478 = 4;
// s32 D_8024F47C = 5;
// s32 D_8024F480 = 7;
// s32 D_8024F484 = 8;

MenuWindowBP gStatsMenuWindowBPs[] = {
    {
        .windowID = WINDOW_ID_PAUSE_STATS,
        .unk_01 = 0,
        .pos = { .x = 3, .y = 16 },
        .width = 289,
        .height = 154,
        .priority = WINDOW_PRIORITY_0,
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


void pause_stats_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    StatsEntryData* statsEntryData;
    PlayerData* playerData;
    s16 bootsLevel;
    s16 hammerLevel;
    s32 powHudElemID;
    s32 powIncrements;
    s32 powIncIdx;
    s32 curIncrement;
    b32 drawingFirst;
    s32 powBarIdx;
    s32 boxWidth;
    s16 level;
    s32 frameCount;
    s32 powFullBars;

    // draw coin count
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_COIN], baseX + 143, baseY + 109);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_COIN]);
    draw_msg(pause_get_menu_msg(PAUSE_MSG_LBL_COINS), baseX + 155, baseY + 101, 255, MSG_PAL_STANDARD, 1);
    draw_number(gPlayerData.coins, baseX + 281, baseY + 101 + NUMBER_OFFSET_Y, 1, MSG_PAL_STANDARD, 255, 3);
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_TIMES], baseX + 248, baseY + 108);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_TIMES]);

    // draw star point count
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_STAR_POINT], baseX + 143, baseY + 94);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_STAR_POINT]);
    draw_msg(pause_get_menu_msg(PAUSE_MSG_LBL_STAR_POINTS), baseX + 155, baseY + 86, 255, MSG_PAL_STANDARD, 1);
    draw_number(gPlayerData.starPoints, baseX + 281, baseY + 86 + NUMBER_OFFSET_Y, 1, MSG_PAL_STANDARD, 255, 3);
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_TIMES], baseX + 248, baseY + 93);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_TIMES]);

    // draw star piece count
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_STAR_PIECE], baseX + 143, baseY + 123);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_STAR_PIECE]);
    draw_msg(pause_get_menu_msg(PAUSE_MSG_LBL_STAR_PIECES), baseX + 155, baseY + 116, 255, MSG_PAL_STANDARD, 1);
    draw_number(gPlayerData.starPieces, baseX + 281, baseY + 116 + NUMBER_OFFSET_Y, 1, MSG_PAL_STANDARD, 255, 3);
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_TIMES], baseX + 248, baseY + 123);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_TIMES]);

    // draw HP count
    pause_draw_menu_label(PAUSE_LBL_HP, baseX + 21, baseY + 35);
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_HP], baseX + 52, baseY + 57);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_HP]);
    draw_msg(pause_get_menu_msg(PAUSE_MSG_LBL_HP), baseX + COL_A_X, baseY + ROW_1_Y, 255, MSG_PAL_WHITE, 1);
    draw_number(gPlayerData.curHP, baseX + 78, baseY + 51, 1, 0, 255, 3);
    draw_msg(pause_get_menu_msg(PAUSE_MSG_SLASH), baseX + COL_B_X, baseY + ROW_2_Y, 255, MSG_PAL_WHITE, 1);
    draw_number(gPlayerData.curMaxHP, baseX + COL_C_X, baseY + ROW_2_Y + NUMBER_OFFSET_Y, 1, 0, 255, 3);

    // draw FP count
    pause_draw_menu_label(PAUSE_LBL_FP, baseX + 21, baseY + 69);
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_FP], baseX + 52, baseY + 92);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_FP]);
    draw_msg(pause_get_menu_msg(PAUSE_MSG_LBL_FP), baseX + COL_A_X, baseY + ROW_3_Y, 255, MSG_PAL_WHITE, 1);
    draw_number(gPlayerData.curFP, baseX + 78, baseY + 85, 1, MSG_PAL_WHITE, 255, 3);
    draw_msg(pause_get_menu_msg(PAUSE_MSG_SLASH), baseX + COL_B_X, baseY + ROW_3_Y, 255, MSG_PAL_WHITE, 1);
    draw_number(gPlayerData.curMaxFP, baseX + COL_C_X, baseY + ROW_3_Y + NUMBER_OFFSET_Y, 1, MSG_PAL_WHITE, 255, 3);

    // draw BP count
    pause_draw_menu_label(PAUSE_LBL_BP, baseX + 21, baseY + 103);
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_BP], baseX + 52, baseY + 126);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_BP]);
    draw_msg(pause_get_menu_msg(PAUSE_MSG_LBL_BP), baseX + COL_A_X, baseY + ROW_4_Y, 255, MSG_PAL_WHITE, 1);
    draw_number(gPlayerData.maxBP, baseX + 78, baseY + 119, 1, MSG_PAL_WHITE, 255, 3);

    #define MINUTE (60 * 60)
    #define HOUR   (MINUTE * 60)

    // draw play time
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_CLOCK], baseX + 143, baseY + 140);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_CLOCK]);
    draw_msg(pause_get_menu_msg(PAUSE_MSG_LBL_TIME), baseX + 155, baseY + 133, 255, MSG_PAL_STANDARD, 1);
    frameCount = gPlayerData.frameCounter;
    if (frameCount >= (100 * HOUR)) {
        frameCount = (100 * HOUR) - 1;
    }
    // draw hours
    draw_number((frameCount / (10 * HOUR)) % 10, baseX + 237, baseY + 133 + NUMBER_OFFSET_Y, 1, MSG_PAL_STANDARD, 255, 2);
    draw_number((frameCount / HOUR) % 10, baseX + 246, baseY + 133 + NUMBER_OFFSET_Y, 1, MSG_PAL_STANDARD, 255, 2);
    draw_msg(pause_get_menu_msg(PAUSE_MSG_DOT), baseX + 257, baseY + 132, 255, MSG_PAL_STANDARD, 1);
    draw_msg(pause_get_menu_msg(PAUSE_MSG_DOT), baseX + 257, baseY + 127, 255, MSG_PAL_STANDARD, 1);
    // draw minutes
    draw_number((frameCount / (10 * MINUTE)) % 6, baseX + 264, baseY + 133 + NUMBER_OFFSET_Y, 1, MSG_PAL_STANDARD, 255, 2);
    draw_number((frameCount / MINUTE) % 10, baseX + 273, baseY + 133 + NUMBER_OFFSET_Y, 1, MSG_PAL_STANDARD, 255, 2);

    bootsLevel = gPlayerData.bootsLevel;
    hammerLevel = gPlayerData.hammerLevel;
    level = gPlayerData.level;
    draw_box(4, &gPauseWS_10, baseX + 7, baseY + 12, 0, level >= 10 ? 121 : 113, 17, 255, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);

    // draw level
#if !VERSION_IQUE
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_MARIO], baseX + 61, baseY + 21);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_MARIO]);
#endif
    draw_msg(pause_get_menu_msg(PAUSE_MSG_MARIO), baseX + 16, baseY + 14, 255, MSG_PAL_WHITE, 1);
    draw_msg(pause_get_menu_msg(PAUSE_MSG_LEVEL), baseX + POS_1_X, baseY + 14, 255, MSG_PAL_WHITE, 1);
    draw_number(level, baseX + POS_2_X, baseY + 14 + NUMBER_OFFSET_Y, 1, MSG_PAL_WHITE, 255, 2);

    bootsLevel++;
    if (bootsLevel < 0) {
        bootsLevel = 0;
    }
    if (bootsLevel > 3) {
        bootsLevel = 3;
    }

    hammerLevel++;
    if (hammerLevel < 0) {
        hammerLevel = 0;
    }
    if (hammerLevel > 3) {
        hammerLevel = 3;
    }

    pause_draw_menu_label(PAUSE_LBL_BOOTS,  baseX + 137, baseY + 10);
    pause_draw_menu_label(PAUSE_LBL_HAMMER, baseX + 137, baseY + 35);

    // draw boots
    hud_element_set_script(gPauseStatsIconIDs[STAT_ICON_BOOTS], gStatsBootsElements[bootsLevel]);
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_BOOTS], baseX + 163, baseY + 29);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_BOOTS]);
    draw_msg(pause_get_menu_msg(gPauseStatsBootsMessages[bootsLevel]), baseX + 176, baseY + 23, 255, MSG_PAL_WHITE, 1);

    // draw hammer
    hud_element_set_script(gPauseStatsIconIDs[STAT_ICON_HAMMER], gStatsHammerElements[hammerLevel]);
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_HAMMER], baseX + 163, baseY + 54);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_HAMMER]);
    draw_msg(pause_get_menu_msg(gPauseStatsHammerMessages[hammerLevel]), baseX + 176, baseY + 48, 255, MSG_PAL_WHITE, 1);

    // draw star power bar
    pause_draw_menu_label(PAUSE_LBL_STATS,  baseX + 130, baseY + 69);
    pause_draw_menu_label(PAUSE_LBL_ENERGY, baseX + 138, baseY + 60);

    drawingFirst = TRUE;
    curIncrement = 0;
    powBarIdx = 0; // which bar of the power meter we're drawing
    powIncIdx = 0; // which increment of the bar we're drawing
    powHudElemID = gPauseStatsIconIDs[STAT_ICON_STAR];

    // get number of full power increments
    playerData = &gPlayerData;
    powFullBars = playerData->specialBarsFilled / 256;
    powIncrements = playerData->specialBarsFilled % 256; // get remainder in unfilled bar
    powIncrements /= 32; // subdivide unfilled bar into 8 segments (8 = 256/32)
    powIncrements += powFullBars * 8; // add 8 increments per full bar

    // draw filled bars
    while (TRUE) {
        if (curIncrement >= powIncrements) {
            break;
        }

        curIncrement++;
        hud_element_set_script(powHudElemID, gPauseStatsSPIncElements[powBarIdx]);
        hud_element_set_render_pos(powHudElemID, baseX + 140 + (powBarIdx * 20) + D_8024F46C[0], baseY + 75);
        if (drawingFirst) {
            hud_element_draw_without_clipping(powHudElemID);
            drawingFirst = FALSE;
        } else {
            hud_element_draw_next(powHudElemID);
        }
        powIncIdx++;

        if (curIncrement >= powIncrements) {
            break;
        }

        curIncrement++;
        hud_element_set_script(powHudElemID, gPauseStatsSPIncElements[powBarIdx]);
        hud_element_set_render_pos(powHudElemID, baseX + 140 + (powBarIdx * 20) + D_8024F46C[1], baseY + 75);
        if (drawingFirst) {
            hud_element_draw_without_clipping(powHudElemID);
            drawingFirst = FALSE;
        } else {
            hud_element_draw_next(powHudElemID);
        }
        powIncIdx++;

        if (curIncrement >= powIncrements) {
            break;
        }

        curIncrement++;
        hud_element_set_script(powHudElemID, gPauseStatsSPIncElements[powBarIdx]);
        hud_element_set_render_pos(powHudElemID, baseX + 140 + (powBarIdx * 20) + D_8024F46C[2], baseY + 75);
        if (drawingFirst) {
            hud_element_draw_without_clipping(powHudElemID);
            drawingFirst = FALSE;
        } else {
            hud_element_draw_next(powHudElemID);
        }
        powIncIdx++;

        if (curIncrement >= powIncrements) {
            break;
        }

        curIncrement++;
        hud_element_set_script(powHudElemID, gPauseStatsSPIncElements[powBarIdx]);
        hud_element_set_render_pos(powHudElemID, baseX + 140 + (powBarIdx * 20) + D_8024F46C[3], baseY + 75);
        if (drawingFirst) {
            hud_element_draw_without_clipping(powHudElemID);
            drawingFirst = FALSE;
        } else {
            hud_element_draw_next(powHudElemID);
        }
        powIncIdx++;

        if (curIncrement >= powIncrements) {
            break;
        }

        curIncrement++;
        hud_element_set_script(powHudElemID, gPauseStatsSPIncElements[powBarIdx]);
        hud_element_set_render_pos(powHudElemID, baseX + 140 + (powBarIdx * 20) + D_8024F46C[4], baseY + 75);
        if (drawingFirst) {
            hud_element_draw_without_clipping(powHudElemID);
            drawingFirst = FALSE;
        } else {
            hud_element_draw_next(powHudElemID);
        }
        powIncIdx++;

        if (curIncrement >= powIncrements) {
            break;
        }

        curIncrement++;
        hud_element_set_script(powHudElemID, gPauseStatsSPIncElements[powBarIdx]);
        hud_element_set_render_pos(powHudElemID, baseX + 140 + (powBarIdx * 20) + D_8024F46C[5], baseY + 75);
        if (drawingFirst) {
            hud_element_draw_without_clipping(powHudElemID);
            drawingFirst = FALSE;
        } else {
            hud_element_draw_next(powHudElemID);
        }
        powIncIdx++;

        if (curIncrement >= powIncrements) {
            break;
        }

        curIncrement++;
        hud_element_set_script(powHudElemID, gPauseStatsSPIncElements[powBarIdx]);
        hud_element_set_render_pos(powHudElemID, baseX + 140 + (powBarIdx * 20) + D_8024F46C[6], baseY + 75);
        if (drawingFirst) {
            hud_element_draw_without_clipping(powHudElemID);
            drawingFirst = FALSE;
        } else {
            hud_element_draw_next(powHudElemID);
        }
        powIncIdx++;

        if (curIncrement >= powIncrements) {
            break;
        }

        curIncrement++;
        hud_element_set_script(powHudElemID, gPauseStatsStarElements[powBarIdx]);
        hud_element_set_render_pos(powHudElemID, baseX + 152 + (powBarIdx * 20), baseY + 77);
        if (drawingFirst) {
            hud_element_draw_without_clipping(powHudElemID);
            drawingFirst = FALSE;
        } else {
            hud_element_draw_next(powHudElemID);
        }
        powIncIdx++;

        powIncIdx = 0;
        powBarIdx += 1;
        if (curIncrement >= powIncrements) {
            break;
        }
    }
    
    // get number of total power increments
    powFullBars = playerData->maxStarPower;
    powIncrements = 8 * powFullBars;

    // draw empty bars
    while (TRUE) {
        if (curIncrement >= powIncrements) {
            break;
        }

        if (powIncIdx == 0) {
            curIncrement++;
            hud_element_set_script(powHudElemID, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(powHudElemID, baseX + 140 + (powBarIdx * 20) + D_8024F46C[0], baseY + 75);
            if (drawingFirst) {
                hud_element_draw_without_clipping(powHudElemID);
                drawingFirst = FALSE;
            } else {
                hud_element_draw_next(powHudElemID);
            }
            if (curIncrement >= powIncrements) {
                break;
            }
            powIncIdx++;
        }

        if (powIncIdx == 1) {
            curIncrement++;
            hud_element_set_script(powHudElemID, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(powHudElemID, baseX + 140 + (powBarIdx * 20) + D_8024F46C[1], baseY + 75);
            if (drawingFirst) {
                hud_element_draw_without_clipping(powHudElemID);
                drawingFirst = FALSE;
            } else {
                hud_element_draw_next(powHudElemID);
            }
            powIncIdx++;

            if (curIncrement >= powIncrements) {
                break;
            }
        }

        if (powIncIdx == 2) {
            curIncrement++;
            hud_element_set_script(powHudElemID, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(powHudElemID, baseX + 140 + (powBarIdx * 20) + D_8024F46C[2], baseY + 75);
            if (drawingFirst) {
                hud_element_draw_without_clipping(powHudElemID);
                drawingFirst = FALSE;
            } else {
                hud_element_draw_next(powHudElemID);
            }
            powIncIdx++;

            if (curIncrement >= powIncrements) {
                break;
            }
        }

        if (powIncIdx == 3) {
            curIncrement++;
            hud_element_set_script(powHudElemID, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(powHudElemID, baseX + 140 + (powBarIdx * 20) + D_8024F46C[3], baseY + 75);
            if (drawingFirst) {
                hud_element_draw_without_clipping(powHudElemID);
                drawingFirst = FALSE;
            } else {
                hud_element_draw_next(powHudElemID);
            }
            powIncIdx++;

            if (curIncrement >= powIncrements) {
                break;
            }
        }

        if (powIncIdx == 4) {
            curIncrement++;
            hud_element_set_script(powHudElemID, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(powHudElemID, baseX + 140 + (powBarIdx * 20) + D_8024F46C[4], baseY + 75);
            if (drawingFirst) {
                hud_element_draw_without_clipping(powHudElemID);
                drawingFirst = FALSE;
            } else {
                hud_element_draw_next(powHudElemID);
            }
            powIncIdx++;
            
            if (curIncrement >= powIncrements) {
                break;
            }
        }

        if (powIncIdx == 5) {
            curIncrement++;
            hud_element_set_script(powHudElemID, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(powHudElemID, baseX + 140 + (powBarIdx * 20) + D_8024F46C[5], baseY + 75);
            if (drawingFirst) {
                hud_element_draw_without_clipping(powHudElemID);
                drawingFirst = FALSE;
            } else {
                hud_element_draw_next(powHudElemID);
            }
            powIncIdx++;

            if (curIncrement >= powIncrements) {
                break;
            }
        }

        if (powIncIdx == 6) {
            curIncrement++;
            hud_element_set_script(powHudElemID, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(powHudElemID, baseX + 140 + (powBarIdx * 20) + D_8024F46C[6], baseY + 75);
            if (drawingFirst) {
                hud_element_draw_without_clipping(powHudElemID);
                drawingFirst = FALSE;
            } else {
                hud_element_draw_next(powHudElemID);
            }
            powIncIdx++;

            if (curIncrement >= powIncrements) {
                break;
            }
        }

        if (powIncIdx == 7) {
            curIncrement++;
            hud_element_set_script(powHudElemID, &HES_StatusStarEmpty);
            hud_element_set_render_pos(powHudElemID, baseX + 152 + (powBarIdx * 20), baseY + 77);
            if (drawingFirst) {
                hud_element_draw_without_clipping(powHudElemID);
                drawingFirst = FALSE;
            } else {
                hud_element_draw_next(powHudElemID);
            }
            powIncIdx++;

            if (curIncrement >= powIncrements) {
                break;
            }
        }
        powIncIdx = 0;
        powBarIdx++;
    }

    if (gPauseMenuCurrentTab == 1) {
        StatsEntryData* entry = &gStatsMenuEntries[menu->selected];

        pause_set_cursor_pos(WINDOW_ID_PAUSE_STATS, baseX + entry->cursorX, baseY + entry->cursorY);
    }
}

void pause_stats_init(MenuPanel* panel) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPauseStatsIconIDs); i++) {
        s32 iconID = hud_element_create(gStatsMenuElements[i]);

        gPauseStatsIconIDs[i] = iconID;
        hud_element_set_flags(iconID, HUD_ELEMENT_FLAG_80);
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
        case PAUSE_MSG_TIP_BOOTS_1:
            if (adjustedBootsLevel > 1) {
                msgOffset = adjustedBootsLevel - 1;
            }
            break;
        case PAUSE_MSG_TIP_HAMMER_0:
            msgOffset = adjustedHammerLevel;
            break;
        case PAUSE_MSG_TIP_SECRETS:
            if (evt_get_variable(NULL, GF_Tutorial_GotStarPiece)) {
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
