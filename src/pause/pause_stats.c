#include "pause_common.h"

#if VERSION_PAL
extern u8 D_PAL_80271B20[4];
extern u8 D_PAL_80271B14[4];
extern u8 D_PAL_80271B1C[4];
extern u8 D_PAL_80271B18[4];
extern u8 D_PAL_80271B10[4];
extern u8 D_PAL_80271B24[4];
extern u8 D_PAL_80271B28[4];
#endif

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
#define POS_3_X 61
#define POS_4_X 16
#define PAUSE_BOX_WIDTH 113
#define X_VAR1 143
#define X_VAR2 155
#elif VERSION_PAL
#define NUMBER_OFFSET_Y 0
#define ROW_1_Y 51
#define ROW_2_Y 51
#define ROW_3_Y 85
#define ROW_4_Y 119
#define COL_A_X 25
#define COL_B_X 78
#define COL_C_X 105
#define POS_1_X D_PAL_80271B20[gCurrentLanguage]
#define POS_2_X D_PAL_80271B14[gCurrentLanguage]
#define POS_3_X D_PAL_80271B1C[gCurrentLanguage]
#define POS_4_X D_PAL_80271B18[gCurrentLanguage]
#define PAUSE_BOX_WIDTH D_PAL_80271B10[gCurrentLanguage]
#define X_VAR1 D_PAL_80271B24[gCurrentLanguage]
#define X_VAR2 D_PAL_80271B28[gCurrentLanguage]
#elif VERSION_JP
#define NUMBER_OFFSET_Y 0
#define ROW_1_Y 51
#define ROW_2_Y 51
#define ROW_3_Y 85
#define ROW_4_Y 119
#define COL_A_X 25
#define COL_B_X 78
#define COL_C_X 105
#define POS_1_X 62
#define POS_2_X 92
#define POS_3_X 53
#define POS_4_X 16
#define PAUSE_BOX_WIDTH 102
#define X_VAR1 151
#define X_VAR2 163
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
#define POS_3_X 61
#define POS_4_X 16
#define PAUSE_BOX_WIDTH 113
#define X_VAR1 143
#define X_VAR2 155
#endif

#if VERSION_JP
#define X_VAR3 239
#define X_VAR4 233
#define COUNT_DRAW_STYLE DRAW_NUMBER_STYLE_MONOSPACE
#define X_VAR5 239
#define X_VAR6 248
#define X_VAR7 127
#define X_VAR8 151
#define X_VAR9 164
#define X_VAR10 128
#define X_VAR11 128
#define X_VAR12 138
#define X_VAR13 150
#else
#define X_VAR3 281
#define X_VAR4 248
#define COUNT_DRAW_STYLE DRAW_NUMBER_STYLE_MONOSPACE_RIGHT
#define X_VAR5 237
#define X_VAR6 246
#define X_VAR7 137
#define X_VAR8 163
#define X_VAR9 176
#define X_VAR10 130
#define X_VAR11 138
#define X_VAR12 140
#define X_VAR13 152
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

#if VERSION_PAL
#define PAUSE_MSG_3B PAUSE_MSG_NO_BADGE
#define PAUSE_MSG_3F PAUSE_MSG_NO_BADGE
#endif

HudScript* gStatsBootsElements[] = { &HES_StatBoots0, &HES_StatBoots1, &HES_StatBoots2, &HES_StatBoots3 };
HudScript* gStatsHammerElements[] = { &HES_StatHammer0, &HES_StatHammer1, &HES_StatHammer2, &HES_StatHammer3 };
s32 gPauseStatsBootsMessages[] = { PAUSE_MSG_3B, PAUSE_MSG_3C, PAUSE_MSG_3D, PAUSE_MSG_3E };
s32 gPauseStatsHammerMessages[] = { PAUSE_MSG_3F, PAUSE_MSG_40, PAUSE_MSG_41, PAUSE_MSG_42 };
s8 gPauseStatsGridData[] = {
    0, 4,
    1, 5,
    1, 6,
    2, 7,
    2, 8,
    3, 9,
    3, 10
};

#if VERSION_PAL
#define BOOTS_X 138
#define HAMMER_X 138
#define STAR_POWER_X 122
#define COLLECTABLES_X 127
#elif VERSION_JP
#define BOOTS_X 128
#define HAMMER_X 128
#define STAR_POWER_X 122
#define COLLECTABLES_X 133
#else
#define BOOTS_X 138
#define HAMMER_X 138
#define STAR_POWER_X 132
#define COLLECTABLES_X 125
#endif

StatsEntryData gStatsMenuEntries[] = {
    { .cursorX =   9, .cursorY =  20, .baseMsgID = PAUSE_MSG_TIP_CONTROLS },
    { .cursorX =  17, .cursorY =  55, .baseMsgID = PAUSE_MSG_TIP_HP },
    { .cursorX =  17, .cursorY =  90, .baseMsgID = PAUSE_MSG_TIP_FP },
    { .cursorX =  17, .cursorY = 124, .baseMsgID = PAUSE_MSG_TIP_BP },
    { .cursorX = BOOTS_X, .cursorY =  28, .baseMsgID = PAUSE_MSG_TIP_BOOTS_1 },
    { .cursorX = HAMMER_X, .cursorY =  53, .baseMsgID = PAUSE_MSG_TIP_HAMMER_0 },
    { .cursorX = STAR_POWER_X, .cursorY =  76, .baseMsgID = PAUSE_MSG_TIP_STAR_POWER },
    { .cursorX = COLLECTABLES_X, .cursorY =  91, .baseMsgID = PAUSE_MSG_TIP_STAR_POINTS },
    { .cursorX = COLLECTABLES_X, .cursorY = 106, .baseMsgID = PAUSE_MSG_TIP_COINS },
    { .cursorX = COLLECTABLES_X, .cursorY = 121, .baseMsgID = PAUSE_MSG_TIP_SECRETS },
    { .cursorX = COLLECTABLES_X, .cursorY = 138, .baseMsgID = PAUSE_MSG_TIP_TIME },
};

#if VERSION_PAL
s32 D_pause_80253814[] = { 0, -16, -7, -19 };
#endif

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
        .windowID = WIN_PAUSE_STATS,
        .unk_01 = 0,
        .pos = { .x = 3, .y = 16 },
        .width = 289,
        .height = 154,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &pause_stats_draw_contents,
        .tab = nullptr,
        .parentID = WIN_PAUSE_MAIN,
        .fpUpdate = { WINDOW_UPDATE_HIDE },
        .extraFlags = 0,
        .style = { .customStyle = &gPauseWS_12 }
    }
};

MenuPanel gPausePanelStats = {
    .initialized = false,
    .col = 0,
    .row = 0,
    .selected = 0,
    .state = 0,
    .numCols = 2,
    .numRows = 7,
    .numPages = 0,
    .gridData = gPauseStatsGridData,
    .fpInit = &pause_stats_init,
    .fpHandleInput = &pause_stats_handle_input,
    .fpUpdate = nullptr,
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
    bool drawingFirst;
    s32 powBarIdx;
    s32 boxWidth;
    s16 level;
    s32 frameCount;
    s32 powFullBars;

    // draw coin count
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_COIN], baseX + X_VAR1, baseY + 109);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_COIN]);
    draw_msg(pause_get_menu_msg(PAUSE_MSG_LBL_COINS), baseX + X_VAR2, baseY + 101, 255, MSG_PAL_STANDARD, 1);
    draw_number(gPlayerData.coins, baseX + X_VAR3, baseY + 101 + NUMBER_OFFSET_Y, 1, MSG_PAL_STANDARD, 255, COUNT_DRAW_STYLE);
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_TIMES], baseX + X_VAR4, baseY + 108);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_TIMES]);

    // draw star point count
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_STAR_POINT], baseX + X_VAR1, baseY + 94);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_STAR_POINT]);
    draw_msg(pause_get_menu_msg(PAUSE_MSG_LBL_STAR_POINTS), baseX + X_VAR2, baseY + 86, 255, MSG_PAL_STANDARD, 1);
    draw_number(gPlayerData.starPoints, baseX + X_VAR3, baseY + 86 + NUMBER_OFFSET_Y, 1, MSG_PAL_STANDARD, 255, COUNT_DRAW_STYLE);
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_TIMES], baseX + X_VAR4, baseY + 93);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_TIMES]);

    // draw star piece count
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_STAR_PIECE], baseX + X_VAR1, baseY + 123);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_STAR_PIECE]);
    draw_msg(pause_get_menu_msg(PAUSE_MSG_LBL_STAR_PIECES), baseX + X_VAR2, baseY + 116, 255, MSG_PAL_STANDARD, 1);
    draw_number(gPlayerData.starPieces, baseX + X_VAR3, baseY + 116 + NUMBER_OFFSET_Y, 1, MSG_PAL_STANDARD, 255, COUNT_DRAW_STYLE);
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_TIMES], baseX + X_VAR4, baseY + 123);
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
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_CLOCK], baseX + X_VAR1, baseY + 140);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_CLOCK]);
    draw_msg(pause_get_menu_msg(PAUSE_MSG_LBL_TIME), baseX + X_VAR2, baseY + 133, 255, MSG_PAL_STANDARD, 1);
    frameCount = gPlayerData.frameCounter;
    if (frameCount >= (100 * HOUR)) {
        frameCount = (100 * HOUR) - 1;
    }
    // draw hours
    draw_number((frameCount / (10 * HOUR)) % 10, baseX + X_VAR5, baseY + 133 + NUMBER_OFFSET_Y, 1, MSG_PAL_STANDARD, 255, 2);
    draw_number((frameCount / HOUR) % 10, baseX + X_VAR6, baseY + 133 + NUMBER_OFFSET_Y, 1, MSG_PAL_STANDARD, 255, 2);
    draw_msg(pause_get_menu_msg(PAUSE_MSG_DOT), baseX + 257, baseY + 132, 255, MSG_PAL_STANDARD, 1);
    draw_msg(pause_get_menu_msg(PAUSE_MSG_DOT), baseX + 257, baseY + 127, 255, MSG_PAL_STANDARD, 1);
    // draw minutes
    draw_number((frameCount / (10 * MINUTE)) % 6, baseX + 264, baseY + 133 + NUMBER_OFFSET_Y, 1, MSG_PAL_STANDARD, 255, 2);
    draw_number((frameCount / MINUTE) % 10, baseX + 273, baseY + 133 + NUMBER_OFFSET_Y, 1, MSG_PAL_STANDARD, 255, 2);

    bootsLevel = gPlayerData.bootsLevel;
    hammerLevel = gPlayerData.hammerLevel;
    level = gPlayerData.level;
    draw_box(4, &gPauseWS_10, baseX + 7, baseY + 12, 0, PAUSE_BOX_WIDTH + (level >= 10 ? 8 : 0), 17, 255, 0,
        0.0f, 0.0f, 0.0f, 0.0f, 0.0f, nullptr, nullptr, nullptr, SCREEN_WIDTH, SCREEN_HEIGHT, nullptr);

    // draw level
#if !VERSION_IQUE
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_MARIO], baseX + POS_3_X, baseY + 21);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_MARIO]);
#endif
    draw_msg(pause_get_menu_msg(PAUSE_MSG_MARIO), baseX + POS_4_X, baseY + 14, 255, MSG_PAL_WHITE, 1);
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

    pause_draw_menu_label(PAUSE_LBL_BOOTS,  baseX + X_VAR7, baseY + 10);
    pause_draw_menu_label(PAUSE_LBL_HAMMER, baseX + X_VAR7, baseY + 35);

    // draw boots
    hud_element_set_script(gPauseStatsIconIDs[STAT_ICON_BOOTS], gStatsBootsElements[bootsLevel]);
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_BOOTS], baseX + X_VAR8, baseY + 29);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_BOOTS]);
    draw_msg(pause_get_menu_msg(gPauseStatsBootsMessages[bootsLevel]), baseX + X_VAR9, baseY + 23, 255, MSG_PAL_WHITE, 1);

    // draw hammer
    hud_element_set_script(gPauseStatsIconIDs[STAT_ICON_HAMMER], gStatsHammerElements[hammerLevel]);
    hud_element_set_render_pos(gPauseStatsIconIDs[STAT_ICON_HAMMER], baseX + X_VAR8, baseY + 54);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[STAT_ICON_HAMMER]);
    draw_msg(pause_get_menu_msg(gPauseStatsHammerMessages[hammerLevel]), baseX + X_VAR9, baseY + 48, 255, MSG_PAL_WHITE, 1);

    // draw star power bar
    pause_draw_menu_label(PAUSE_LBL_STATS,  baseX + X_VAR10, baseY + 69);
    pause_draw_menu_label(PAUSE_LBL_ENERGY, baseX + X_VAR11, baseY + 60);

    drawingFirst = true;
    curIncrement = 0;
    powBarIdx = 0; // which bar of the power meter we're drawing
    powIncIdx = 0; // which increment of the bar we're drawing
    powHudElemID = gPauseStatsIconIDs[STAT_ICON_STAR];

    // get number of full power increments
    playerData = &gPlayerData;
    powFullBars = playerData->starPower / SP_PER_BAR;
    powIncrements = playerData->starPower % SP_PER_BAR; // get remainder in unfilled bar
    powIncrements /= SP_PER_SEG; // subdivide unfilled bar into 8 segments (8 = 256/32)
    powIncrements += powFullBars * 8; // add 8 increments per full bar

    // draw filled bars
    while (true) {
        if (curIncrement >= powIncrements) {
            break;
        }

        curIncrement++;
        hud_element_set_script(powHudElemID, gPauseStatsSPIncElements[powBarIdx]);
        hud_element_set_render_pos(powHudElemID, baseX + X_VAR12 + (powBarIdx * 20) + D_8024F46C[0], baseY + 75);
        if (drawingFirst) {
            hud_element_draw_without_clipping(powHudElemID);
            drawingFirst = false;
        } else {
            hud_element_draw_next(powHudElemID);
        }
        powIncIdx++;

        if (curIncrement >= powIncrements) {
            break;
        }

        curIncrement++;
        hud_element_set_script(powHudElemID, gPauseStatsSPIncElements[powBarIdx]);
        hud_element_set_render_pos(powHudElemID, baseX + X_VAR12 + (powBarIdx * 20) + D_8024F46C[1], baseY + 75);
        if (drawingFirst) {
            hud_element_draw_without_clipping(powHudElemID);
            drawingFirst = false;
        } else {
            hud_element_draw_next(powHudElemID);
        }
        powIncIdx++;

        if (curIncrement >= powIncrements) {
            break;
        }

        curIncrement++;
        hud_element_set_script(powHudElemID, gPauseStatsSPIncElements[powBarIdx]);
        hud_element_set_render_pos(powHudElemID, baseX + X_VAR12 + (powBarIdx * 20) + D_8024F46C[2], baseY + 75);
        if (drawingFirst) {
            hud_element_draw_without_clipping(powHudElemID);
            drawingFirst = false;
        } else {
            hud_element_draw_next(powHudElemID);
        }
        powIncIdx++;

        if (curIncrement >= powIncrements) {
            break;
        }

        curIncrement++;
        hud_element_set_script(powHudElemID, gPauseStatsSPIncElements[powBarIdx]);
        hud_element_set_render_pos(powHudElemID, baseX + X_VAR12 + (powBarIdx * 20) + D_8024F46C[3], baseY + 75);
        if (drawingFirst) {
            hud_element_draw_without_clipping(powHudElemID);
            drawingFirst = false;
        } else {
            hud_element_draw_next(powHudElemID);
        }
        powIncIdx++;

        if (curIncrement >= powIncrements) {
            break;
        }

        curIncrement++;
        hud_element_set_script(powHudElemID, gPauseStatsSPIncElements[powBarIdx]);
        hud_element_set_render_pos(powHudElemID, baseX + X_VAR12 + (powBarIdx * 20) + D_8024F46C[4], baseY + 75);
        if (drawingFirst) {
            hud_element_draw_without_clipping(powHudElemID);
            drawingFirst = false;
        } else {
            hud_element_draw_next(powHudElemID);
        }
        powIncIdx++;

        if (curIncrement >= powIncrements) {
            break;
        }

        curIncrement++;
        hud_element_set_script(powHudElemID, gPauseStatsSPIncElements[powBarIdx]);
        hud_element_set_render_pos(powHudElemID, baseX + X_VAR12 + (powBarIdx * 20) + D_8024F46C[5], baseY + 75);
        if (drawingFirst) {
            hud_element_draw_without_clipping(powHudElemID);
            drawingFirst = false;
        } else {
            hud_element_draw_next(powHudElemID);
        }
        powIncIdx++;

        if (curIncrement >= powIncrements) {
            break;
        }

        curIncrement++;
        hud_element_set_script(powHudElemID, gPauseStatsSPIncElements[powBarIdx]);
        hud_element_set_render_pos(powHudElemID, baseX + X_VAR12 + (powBarIdx * 20) + D_8024F46C[6], baseY + 75);
        if (drawingFirst) {
            hud_element_draw_without_clipping(powHudElemID);
            drawingFirst = false;
        } else {
            hud_element_draw_next(powHudElemID);
        }
        powIncIdx++;

        if (curIncrement >= powIncrements) {
            break;
        }

        curIncrement++;
        hud_element_set_script(powHudElemID, gPauseStatsStarElements[powBarIdx]);
        hud_element_set_render_pos(powHudElemID, baseX + X_VAR13 + (powBarIdx * 20), baseY + 77);
        if (drawingFirst) {
            hud_element_draw_without_clipping(powHudElemID);
            drawingFirst = false;
        } else {
            hud_element_draw_next(powHudElemID);
        }
        powIncIdx++;

        powIncIdx = 0;
        powBarIdx++;
        if (curIncrement >= powIncrements) {
            break;
        }
    }

    // get number of total power increments
    powFullBars = playerData->maxStarPower;
    powIncrements = 8 * powFullBars;

    // draw empty bars
    while (true) {
        if (curIncrement >= powIncrements) {
            break;
        }

        if (powIncIdx == 0) {
            curIncrement++;
            hud_element_set_script(powHudElemID, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(powHudElemID, baseX + X_VAR12 + (powBarIdx * 20) + D_8024F46C[0], baseY + 75);
            if (drawingFirst) {
                hud_element_draw_without_clipping(powHudElemID);
                drawingFirst = false;
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
            hud_element_set_render_pos(powHudElemID, baseX + X_VAR12 + (powBarIdx * 20) + D_8024F46C[1], baseY + 75);
            if (drawingFirst) {
                hud_element_draw_without_clipping(powHudElemID);
                drawingFirst = false;
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
            hud_element_set_render_pos(powHudElemID, baseX + X_VAR12 + (powBarIdx * 20) + D_8024F46C[2], baseY + 75);
            if (drawingFirst) {
                hud_element_draw_without_clipping(powHudElemID);
                drawingFirst = false;
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
            hud_element_set_render_pos(powHudElemID, baseX + X_VAR12 + (powBarIdx * 20) + D_8024F46C[3], baseY + 75);
            if (drawingFirst) {
                hud_element_draw_without_clipping(powHudElemID);
                drawingFirst = false;
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
            hud_element_set_render_pos(powHudElemID, baseX + X_VAR12 + (powBarIdx * 20) + D_8024F46C[4], baseY + 75);
            if (drawingFirst) {
                hud_element_draw_without_clipping(powHudElemID);
                drawingFirst = false;
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
            hud_element_set_render_pos(powHudElemID, baseX + X_VAR12 + (powBarIdx * 20) + D_8024F46C[5], baseY + 75);
            if (drawingFirst) {
                hud_element_draw_without_clipping(powHudElemID);
                drawingFirst = false;
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
            hud_element_set_render_pos(powHudElemID, baseX + X_VAR12 + (powBarIdx * 20) + D_8024F46C[6], baseY + 75);
            if (drawingFirst) {
                hud_element_draw_without_clipping(powHudElemID);
                drawingFirst = false;
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
            hud_element_set_render_pos(powHudElemID, baseX + X_VAR13 + (powBarIdx * 20), baseY + 77);
            if (drawingFirst) {
                hud_element_draw_without_clipping(powHudElemID);
                drawingFirst = false;
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
#if VERSION_PAL
        s32 palOffsetX = menu->selected >= 7 ? D_pause_80253814[gCurrentLanguage] : 0;
        StatsEntryData* entry = &gStatsMenuEntries[menu->selected];

        pause_set_cursor_pos(WIN_PAUSE_STATS, baseX + entry->cursorX + palOffsetX, baseY + entry->cursorY);
#else
        StatsEntryData* entry = &gStatsMenuEntries[menu->selected];

        pause_set_cursor_pos(WIN_PAUSE_STATS, baseX + entry->cursorX, baseY + entry->cursorY);
#endif
    }
}

void pause_stats_init(MenuPanel* panel) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPauseStatsIconIDs); i++) {
        gPauseStatsIconIDs[i] = hud_element_create(gStatsMenuElements[i]);
        hud_element_set_flags(gPauseStatsIconIDs[i], HUD_ELEMENT_FLAG_80);
    }

    for (i = 0; i < ARRAY_COUNT(gStatsMenuWindowBPs); i++) {
        gStatsMenuWindowBPs[i].tab = panel;
    }

    setup_pause_menu_tab(gStatsMenuWindowBPs, ARRAY_COUNT(gStatsMenuWindowBPs));
    panel->initialized = true;
}

void pause_stats_handle_input(MenuPanel* panel) {
    s32 initialSelection = panel->selected;
    s16 bootsMsgIdx;
    s16 hammerMsgIdx;
    s32 msgOffset;

    if (gPauseHeldButtons & BUTTON_STICK_LEFT) {
        while (true) {
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
        while (true) {
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
        while (true) {
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
        while (true) {
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
    bootsMsgIdx = gPlayerData.bootsLevel;
    hammerMsgIdx = gPlayerData.hammerLevel;

    bootsMsgIdx++;
    if (bootsMsgIdx < 0) {
        bootsMsgIdx = 0;
    }
    if (bootsMsgIdx > 3) {
        bootsMsgIdx = 3;
    }

    hammerMsgIdx++;
    if (hammerMsgIdx < 0) {
        hammerMsgIdx = 0;
    }
    if (hammerMsgIdx > 3) {
        hammerMsgIdx = 3;
    }

    switch (gStatsMenuEntries[panel->selected].baseMsgID) {
        case PAUSE_MSG_TIP_BOOTS_1:
            if (bootsMsgIdx > 1) {
                msgOffset = bootsMsgIdx - 1;
            }
            break;
        case PAUSE_MSG_TIP_HAMMER_0:
            msgOffset = hammerMsgIdx;
            break;
        case PAUSE_MSG_TIP_SECRETS:
            if (evt_get_variable(nullptr, GF_Tutorial_GotStarPiece)) {
                msgOffset = 1;
            }
            break;
    }

    gPauseCurrentDescMsg = pause_get_menu_msg(gStatsMenuEntries[panel->selected].baseMsgID + msgOffset);
    gPauseCurrentDescIconScript = nullptr;

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
