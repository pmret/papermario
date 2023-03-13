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
    s32 icon10;
    s32 limit;
    s32 var_s2_2;
    s32 var_s3_2;
    s32 cond;
    s32 elemIdx;
    s32 boxWidth;
    s16 level;
    s32 frameCounter;
    s32 maxStarPower;

    hud_element_set_render_pos(gPauseStatsIconIDs[3], baseX + 143, baseY + 109);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[3]);
    draw_msg(pause_get_menu_msg(0x32), baseX + 155, baseY + 101, 255, 0xA, 1);
    draw_number(gPlayerData.coins, baseX + 281, baseY + 101 + NUMBER_OFFSET_Y, 1, 0xA, 255, 3);
    hud_element_set_render_pos(gPauseStatsIconIDs[11], baseX + 248, baseY + 108);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[11]);
    hud_element_set_render_pos(gPauseStatsIconIDs[4], baseX + 143, baseY + 0x5E);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[4]);
    draw_msg(pause_get_menu_msg(51), baseX + 155, baseY + 86, 255, 0xA, 1);
    draw_number(gPlayerData.starPoints, baseX + 281, baseY + 86 + NUMBER_OFFSET_Y, 1, 0xA, 255, 3);
    hud_element_set_render_pos(gPauseStatsIconIDs[11], baseX + 248, baseY + 93);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[11]);
    hud_element_set_render_pos(gPauseStatsIconIDs[5], baseX + 143, baseY + 123);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[5]);
    draw_msg(pause_get_menu_msg(0x34), baseX + 155, baseY + 116, 255, 0xA, 1);
    draw_number(gPlayerData.starPieces, baseX + 281, baseY + 116 + NUMBER_OFFSET_Y, 1, 0xA, 255, 3);
    hud_element_set_render_pos(gPauseStatsIconIDs[11], baseX + 248, baseY + 123);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[11]);
    pause_draw_menu_label(0, baseX + 21, baseY + 35);
    hud_element_set_render_pos(gPauseStatsIconIDs[7], baseX + 52, baseY + 57);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[7]);
    draw_msg(pause_get_menu_msg(0x36), baseX + COL_A_X, baseY + ROW_1_Y, 255, 0, 1);
    draw_number(gPlayerData.curHP, baseX + 78, baseY + 51, 1, 0, 255, 3);
    draw_msg(pause_get_menu_msg(0x39), baseX + COL_B_X, baseY + ROW_2_Y, 255, 0, 1);
    draw_number(gPlayerData.curMaxHP, baseX + COL_C_X, baseY + ROW_2_Y + NUMBER_OFFSET_Y, 1, 0, 255, 3);
    pause_draw_menu_label(1, baseX + 21, baseY + 69);
    hud_element_set_render_pos(gPauseStatsIconIDs[8], baseX + 52, baseY + 92);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[8]);
    draw_msg(pause_get_menu_msg(0x37), baseX + COL_A_X, baseY + ROW_3_Y, 255, 0, 1);
    draw_number(gPlayerData.curFP, baseX + 78, baseY + 85, 1, 0, 255, 3);
    draw_msg(pause_get_menu_msg(0x39), baseX + COL_B_X, baseY + ROW_3_Y, 255, 0, 1);
    draw_number(gPlayerData.curMaxFP, baseX + COL_C_X, baseY + ROW_3_Y + NUMBER_OFFSET_Y, 1, 0, 255, 3);
    pause_draw_menu_label(2, baseX + 21, baseY + 103);
    hud_element_set_render_pos(gPauseStatsIconIDs[9], baseX + 52, baseY + 126);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[9]);
    draw_msg(pause_get_menu_msg(0x38), baseX + COL_A_X, baseY + ROW_4_Y, 255, 0, 1);
    draw_number(gPlayerData.maxBP, baseX + 78, baseY + 119, 1, 0, 255, 3);
    hud_element_set_render_pos(gPauseStatsIconIDs[6], baseX + 143, baseY + 140);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[6]);
    draw_msg(pause_get_menu_msg(0x35), baseX + 155, baseY + 133, 255, 0xA, 1);

    frameCounter = gPlayerData.frameCounter;
    if (frameCounter > 21599999) {
        frameCounter = 21599999;
    }
    draw_number((frameCounter / 2160000) % 10, baseX + 237, baseY + 133 + NUMBER_OFFSET_Y, 1, 0xA, 255, 2);
    draw_number((frameCounter / 216000) - ((frameCounter / 2160000) * 10), baseX + 246, baseY + 133 + NUMBER_OFFSET_Y, 1, 0xA, 255, 2);
    draw_msg(pause_get_menu_msg(0x3A), baseX + 257, baseY + 132, 255, 0xA, 1);
    draw_msg(pause_get_menu_msg(0x3A), baseX + 257, baseY + 127, 255, 0xA, 1);
    draw_number((frameCounter / 36000) - ((frameCounter / 216000) * 6), baseX + 264, baseY + 133 + NUMBER_OFFSET_Y, 1, 0xA, 255, 2);
    draw_number((frameCounter / 3600) - ((frameCounter / 36000) * 10), baseX + 273, baseY + 133 + NUMBER_OFFSET_Y, 1, 0xA, 255, 2);

    bootsLevel = gPlayerData.bootsLevel;
    hammerLevel = gPlayerData.hammerLevel;
    level = gPlayerData.level;
    draw_box(4, &gPauseWS_10, baseX + 7, baseY + 12, 0, level >= 10 ? 0x79 : 0x71, 17, 255, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);

#if !VERSION_IQUE
    hud_element_set_render_pos(gPauseStatsIconIDs[0], baseX + 61, baseY + 21);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[0]);
#endif
    draw_msg(pause_get_menu_msg(0x43), baseX + 16, baseY + 14, 255, 0, 1);
    draw_msg(pause_get_menu_msg(0x44), baseX + POS_1_X, baseY + 14, 255, 0, 1);
    draw_number(level, baseX + POS_2_X, baseY + 14 + NUMBER_OFFSET_Y, 1, 0, 255, 2);

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

    pause_draw_menu_label(3, baseX + 137, baseY + 10);
    pause_draw_menu_label(4, baseX + 137, baseY + 35);

    hud_element_set_script(gPauseStatsIconIDs[1], gStatsBootsElements[bootsLevel]);
    hud_element_set_render_pos(gPauseStatsIconIDs[1], baseX + 163, baseY + 29);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[1]);
    draw_msg(pause_get_menu_msg(gPauseStatsBootsMessages[bootsLevel]), baseX + 176, baseY + 23, 255, 0, 1);
    hud_element_set_script(gPauseStatsIconIDs[2], gStatsHammerElements[hammerLevel]);
    hud_element_set_render_pos(gPauseStatsIconIDs[2], baseX + 163, baseY + 54);
    hud_element_draw_without_clipping(gPauseStatsIconIDs[2]);
    draw_msg(pause_get_menu_msg(gPauseStatsHammerMessages[hammerLevel]), baseX + 176, baseY + 48, 255, 0, 1);
    pause_draw_menu_label(6, baseX + 130, baseY + 69);
    pause_draw_menu_label(5, baseX + 138, baseY + 60);
    cond = TRUE;
    var_s3_2 = 0;
    elemIdx = 0;
    var_s2_2 = 0;
    icon10 = gPauseStatsIconIDs[10];

    playerData = &gPlayerData;
    maxStarPower = playerData->specialBarsFilled / 256;
    limit = playerData->specialBarsFilled % 256;
    limit /= 32;
    limit += maxStarPower * 8;

    while (TRUE) {

        if (var_s3_2 >= limit) {
            break;
        }
        var_s3_2++;
        hud_element_set_script(icon10, gPauseStatsSPIncElements[elemIdx]);
        hud_element_set_render_pos(icon10, baseX + 140 + (elemIdx * 20) + D_8024F46C[0], baseY + 75);
        if (cond) {
            hud_element_draw_without_clipping(icon10);
            cond = FALSE;
        } else {
            hud_element_draw_next(icon10);
        }
        var_s2_2++;

        if (var_s3_2 >= limit) {
            break;
        }
        var_s3_2++;
        hud_element_set_script(icon10, gPauseStatsSPIncElements[elemIdx]);
        hud_element_set_render_pos(icon10, baseX + 140 + (elemIdx * 20) + D_8024F46C[1], baseY + 75);
        if (cond) {
            hud_element_draw_without_clipping(icon10);
            cond = FALSE;
        } else {
            hud_element_draw_next(icon10);
        }
        var_s2_2++;

        if (var_s3_2 >= limit) {
            break;
        }

        var_s3_2++;
        hud_element_set_script(icon10, gPauseStatsSPIncElements[elemIdx]);
        hud_element_set_render_pos(icon10, baseX + 140 + (elemIdx * 20) + D_8024F46C[2], baseY + 75);
        if (cond) {
            hud_element_draw_without_clipping(icon10);
            cond = FALSE;
        } else {
            hud_element_draw_next(icon10);
        }
        var_s2_2++;

        if (var_s3_2 >= limit) {
            break;
        }

        var_s3_2++;
        hud_element_set_script(icon10, gPauseStatsSPIncElements[elemIdx]);
        hud_element_set_render_pos(icon10, baseX + 140 + (elemIdx * 20) + D_8024F46C[3], baseY + 75);
        if (cond) {
            hud_element_draw_without_clipping(icon10);
            cond = FALSE;
        } else {
            hud_element_draw_next(icon10);
        }
        var_s2_2++;

        if (var_s3_2 >= limit) {
            break;
        }

        var_s3_2++;
        hud_element_set_script(icon10, gPauseStatsSPIncElements[elemIdx]);
        hud_element_set_render_pos(icon10, baseX + 140 + (elemIdx * 20) + D_8024F46C[4], baseY + 75);
        if (cond) {
            hud_element_draw_without_clipping(icon10);
            cond = FALSE;
        } else {
            hud_element_draw_next(icon10);
        }
        var_s2_2++;

        if (var_s3_2 >= limit) {
            break;
        }
        var_s3_2++;
        hud_element_set_script(icon10, gPauseStatsSPIncElements[elemIdx]);
        hud_element_set_render_pos(icon10, baseX + 140 + (elemIdx * 20) + D_8024F46C[5], baseY + 75);
        if (cond) {
            hud_element_draw_without_clipping(icon10);
            cond = FALSE;
        } else {
            hud_element_draw_next(icon10);
        }
        var_s2_2++;
        if (var_s3_2 >= limit) {
            break;
        }
        var_s3_2++;
        hud_element_set_script(icon10, gPauseStatsSPIncElements[elemIdx]);
        hud_element_set_render_pos(icon10, baseX + 140 + (elemIdx * 20) + D_8024F46C[6], baseY + 75);
        if (cond) {
            hud_element_draw_without_clipping(icon10);
            cond = FALSE;
        } else {
            hud_element_draw_next(icon10);
        }
        var_s2_2++;

        if (var_s3_2 >= limit) {
            break;
        }

        var_s3_2++;
        hud_element_set_script(icon10, gPauseStatsStarElements[elemIdx]);
        hud_element_set_render_pos(icon10, baseX + 0x98 + (elemIdx * 20), baseY + 0x4D);
        if (cond) {
            hud_element_draw_without_clipping(icon10);
            cond = FALSE;
        } else {
            hud_element_draw_next(icon10);
        }
        var_s2_2 = 0;
        elemIdx += 1;
        if (var_s3_2 >= limit) {
            break;
        }
    }

    maxStarPower = playerData->maxStarPower;
    limit = 8 * maxStarPower;
    while (TRUE) {
        if (var_s3_2 >= limit) {
            break;
        }

        if (var_s2_2 == 0) {
            var_s3_2++;
            hud_element_set_script(icon10, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(icon10, baseX + 140 + (elemIdx * 20) + D_8024F46C[0], baseY + 75);
            if (cond) {
                hud_element_draw_without_clipping(icon10);
                cond = FALSE;
            } else {
                hud_element_draw_next(icon10);
            }
            if (var_s3_2 >= limit) {
                break;
            }
            var_s2_2++;
        }

        if (var_s2_2 == 1) {
            var_s3_2++;
            hud_element_set_script(icon10, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(icon10, baseX + 140 + (elemIdx * 20) + D_8024F46C[1], baseY + 75);
            if (cond) {
                hud_element_draw_without_clipping(icon10);
                cond = FALSE;
            } else {
                hud_element_draw_next(icon10);
            }
            if (var_s3_2 >= limit) {
                break;
            }
            var_s2_2++;
        }


        if (var_s2_2 == 2) {
            var_s3_2++;
            hud_element_set_script(icon10, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(icon10, baseX + 140 + (elemIdx * 20) + D_8024F46C[2], baseY + 75);
            if (cond) {
                hud_element_draw_without_clipping(icon10);
                cond = FALSE;
            } else {
                hud_element_draw_next(icon10);
            }
            if (var_s3_2 >= limit) {
                break;
            }
            var_s2_2++;
        }


        if (var_s2_2 == 3) {
            var_s3_2++;
            hud_element_set_script(icon10, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(icon10, baseX + 140 + (elemIdx * 20) + D_8024F46C[3], baseY + 75);
            if (cond) {
                hud_element_draw_without_clipping(icon10);
                cond = FALSE;
            } else {
                hud_element_draw_next(icon10);
            }
            if (var_s3_2 >= limit) {
                break;
            }
            var_s2_2++;
        }


        if (var_s2_2 == 4) {
            var_s3_2++;
            hud_element_set_script(icon10, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(icon10, baseX + 140 + (elemIdx * 20) + D_8024F46C[4], baseY + 75);
            if (cond) {
                hud_element_draw_without_clipping(icon10);
                cond = FALSE;
            } else {
                hud_element_draw_next(icon10);
            }
            if (var_s3_2 >= limit) {
                break;
            }
            var_s2_2++;
        }


        if (var_s2_2 == 5) {
            var_s3_2++;
            hud_element_set_script(icon10, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(icon10, baseX + 140 + (elemIdx * 20) + D_8024F46C[5], baseY + 75);
            if (cond) {
                hud_element_draw_without_clipping(icon10);
                cond = FALSE;
            } else {
                hud_element_draw_next(icon10);
            }
            if (var_s3_2 >= limit) {
                break;
            }

            var_s2_2++;
        }


        if (var_s2_2 == 6) {
            var_s3_2++;
            hud_element_set_script(icon10, &HES_StatusSPEmptyIncrement);
            hud_element_set_render_pos(icon10, baseX + 140 + (elemIdx * 20) + D_8024F46C[6], baseY + 75);
            if (cond) {
                hud_element_draw_without_clipping(icon10);
                cond = FALSE;
            } else {
                hud_element_draw_next(icon10);
            }
            if (var_s3_2 >= limit) {
                break;
            }
            var_s2_2++;
        }

        if (var_s2_2 == 7) {
            var_s3_2++;
            hud_element_set_script(icon10, &HES_StatusStarEmpty);
            hud_element_set_render_pos(icon10, baseX + 152 + (elemIdx * 20), baseY + 0x4D);
            if (cond) {
                hud_element_draw_without_clipping(icon10);
                cond = FALSE;
            } else {
                hud_element_draw_next(icon10);
            }
            if (var_s3_2 >= limit) {
                break;
            }
            var_s2_2 = 0;
        }
        var_s2_2 = 0;
        elemIdx++;
    }

    if (gPauseMenuCurrentTab == 1) {
        StatsEntryData* entry = &gStatsMenuEntries[menu->selected];

        pause_set_cursor_pos(0x1F, baseX + entry->cursorX, baseY + entry->cursorY);
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
        case 0x25:
            if (adjustedBootsLevel > 1) {
                msgOffset = adjustedBootsLevel - 1;
            }
            break;
        case 0x28:
            msgOffset = adjustedHammerLevel;
            break;
        case 0x2F:
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
