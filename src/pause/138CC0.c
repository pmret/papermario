#include "common.h"
#include "hud_element.h"

// Probably only used here, but could theoretically be used in the main menu too
typedef struct {
    s32 cursorX;
    s32 cursorY;
    s32 baseMsgID;
} StatsEntryData; // size = 0xC

extern HudElementAnim HudScript_MarioHeadSmall[];
extern HudElementAnim HudScript_StatBoots0[];
extern HudElementAnim HudScript_StatBoots1[];
extern HudElementAnim HudScript_StatBoots2[];
extern HudElementAnim HudScript_StatBoots3[];
extern HudElementAnim HudScript_StatHammer0[];
extern HudElementAnim HudScript_StatHammer1[];
extern HudElementAnim HudScript_StatHammer2[];
extern HudElementAnim HudScript_StatHammer3[];
extern HudElementAnim HudScript_StatusCoin[];
extern HudElementAnim HudScript_StatusStarPoint[];
extern HudElementAnim HudScript_StatStarPiece_1[];
extern HudElementAnim HudScript_Clock[];
extern HudElementAnim HudScript_StatusHeart[];
extern HudElementAnim HudScript_StatFp_1[];
extern HudElementAnim HudScript_StatBp[];
extern HudElementAnim HudScript_StatusStar1[];
extern HudElementAnim HudScript_StatusStar2[];
extern HudElementAnim HudScript_StatusStar3[];
extern HudElementAnim HudScript_StatusStar4[];
extern HudElementAnim HudScript_StatusStar5[];
extern HudElementAnim HudScript_StatusStar6[];
extern HudElementAnim HudScript_StatusStar7[];
extern HudElementAnim HudScript_StatTimes[];

extern s32 D_8026FB30;

void pause_stats_draw_contents(void* arg0, s32 arg1, s32 arg2);
void pause_stats_init(MenuPanel* panel);
void pause_stats_handle_input(MenuPanel* panel);
void pause_stats_cleanup(void);

HudElementAnim* gStatsMenuElements[] = { HudScript_MarioHeadSmall, HudScript_StatBoots0, HudScript_StatHammer0,
                                       HudScript_StatusCoin, HudScript_StatusStarPoint, HudScript_StatStarPiece_1,
                                       HudScript_Clock, HudScript_StatusHeart, HudScript_StatFp_1, HudScript_StatBp,
                                       HudScript_StatusStar1, HudScript_StatTimes};
HudElementAnim* D_8024F360[] = { HudScript_StatBoots0, HudScript_StatBoots1, HudScript_StatBoots2, HudScript_StatBoots3 };
HudElementAnim* D_8024F370[] = { HudScript_StatHammer0, HudScript_StatHammer1, HudScript_StatHammer2, HudScript_StatHammer3 };
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
HudElementAnim* D_8024F450[] = { HudScript_StatusStar1, HudScript_StatusStar3, HudScript_StatusStar2,
                                 HudScript_StatusStar4, HudScript_StatusStar5, HudScript_StatusStar6,
                                 HudScript_StatusStar7 };

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
MenuPanel D_8024F4AC = { .unk_00 = {
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
// Fake "badge" for the None entry that appears on the equipped badges page when nothing is equipped
#define BADGE_NONE_STANDIN 0x7FFE
// Invalid badge ID filled in unused slots of gBadgeMenuItemIDs
#define BADGE_INVALID 0x7FFF

INCLUDE_ASM(s32, "pause/138CC0", pause_stats_draw_contents);
/*
void pause_stats_draw_contents(void* arg0, s32 arg1, s32 arg2) {
    s32 frameCounter;
    s16 bootsAnimIndex, hammerAnimIndex;
    s16 bootsLevel, hammerLevel, playerLevel;
    s32 s2, s3, s4, s5, s6;
    s32 sp, splow, sphigh;

    set_hud_element_render_pos(gStatsMenuIconIDs[3], arg1 + 143, arg2 + 109);
    draw_hud_element_3(gStatsMenuIconIDs[3]);
    draw_msg(pause_get_menu_msg(50), arg1 + 155, arg2 + 101, 255, 10, 1);
    draw_number(gPlayerData.coins,  arg1 + 281, arg2 + 101, 1, 10, 255, 3);
    set_hud_element_render_pos(gStatsMenuIconIDs[11], arg1 + 248, arg2 + 108);
    draw_hud_element_3(gStatsMenuIconIDs[11]);
    set_hud_element_render_pos(gStatsMenuIconIDs[4], arg1 + 143, arg2 + 94);
    draw_hud_element_3(gStatsMenuIconIDs[4]);
    draw_msg(pause_get_menu_msg(51), arg1 + 155, arg2 + 86, 255, 10, 1);
    draw_number(gPlayerData.starPoints, arg1 + 281, arg2 + 86, 1, 10, 255, 3);
    set_hud_element_render_pos(gStatsMenuIconIDs[11], arg1 + 248, arg2 + 93);
    draw_hud_element_3(gStatsMenuIconIDs[11]);
    set_hud_element_render_pos(gStatsMenuIconIDs[5], arg1 + 143, arg2 + 123);
    draw_hud_element_3(gStatsMenuIconIDs[5]);
    draw_msg(pause_get_menu_msg(52), arg1 + 0x9B, arg2 + 0x74, 0xFF, 0xA, 1);
    draw_number(gPlayerData.starPieces, arg1 + 0x119, arg2 + 0x74, 1, 0xA, 0xFF, 3);
    set_hud_element_render_pos(gStatsMenuIconIDs[11], arg1 + 0xF8, arg2 + 0x7B);
    draw_hud_element_3(gStatsMenuIconIDs[11]);
    pause_draw_menu_label(0, arg1 + 21, arg2 + 35);
    set_hud_element_render_pos(gStatsMenuIconIDs[7], arg1 + 52, arg2 + 0x39);
    draw_hud_element_3(gStatsMenuIconIDs[7]);
    draw_msg(pause_get_menu_msg(54), arg1 + 25, arg2 + 51, 0xFF, 0, 1);
    draw_number(gPlayerData.curHP, arg1 + 78, arg2 + 51, 1, 0, 0xFF, 3);
    draw_msg(pause_get_menu_msg(57), arg1 + 78, arg2 + 51, 0xFF, 0, 1);
    draw_number(gPlayerData.curMaxHP, arg1 + 105, arg2 + 51, 1, 0, 0xFF, 3);
    pause_draw_menu_label(1, arg1 + 21, arg2 + 69);
    set_hud_element_render_pos(gStatsMenuIconIDs[8], arg1 + 52, arg2 + 92);
    draw_hud_element_3(gStatsMenuIconIDs[8]);
    draw_msg(pause_get_menu_msg(55), arg1 + 25, arg2 + 85, 0xFF, 0, 1);
    draw_number(gPlayerData.curFP, arg1 + 78, arg2 + 85, 1, 0, 0xFF, 3);
    draw_msg(pause_get_menu_msg(57), arg1 + 78, arg2 + 85, 0xFF, 0, 1);
    draw_number(gPlayerData.curMaxFP, arg1 + 105, arg2 + 85, 1, 0, 0xFF, 3);
    pause_draw_menu_label(2, arg1 + 21, arg2 + 103);
    set_hud_element_render_pos(gStatsMenuIconIDs[9], arg1 + 52, arg2 + 126);
    draw_hud_element_3(gStatsMenuIconIDs[9]);
    draw_msg(pause_get_menu_msg(56), arg1 + 25, arg2 + 119, 0xFF, 0, 1);
    draw_number(gPlayerData.maxBP, arg1 + 78, arg2 + 119, 1, 0, 0xFF, 3);
    set_hud_element_render_pos(gStatsMenuIconIDs[6], arg1 + 143, arg2 + 140);
    draw_hud_element_3(gStatsMenuIconIDs[6]);
    draw_msg(pause_get_menu_msg(53), arg1 + 155, arg2 + 133, 0xFF, 0xA, 1);
    frameCounter = gPlayerData.frameCounter;
    //bootsAnimIndex = 3;
    if (frameCounter > 21599999) {
        frameCounter = 21599999;
    }
    draw_number((frameCounter / 2160000) % 10, arg1 + 237, arg2 + 133, 1, 0xA, 0xFF, 2);
    draw_number(frameCounter / 216000 - (frameCounter / 2160000) * 10, arg1 + 246, arg2 + 133, 1, 0xA, 0xFF, 2);
    draw_msg(pause_get_menu_msg(58), arg1 + 257, arg2 + 132, 0xFF, 0xA, 1);
    draw_msg(pause_get_menu_msg(58), arg1 + 257, arg2 + 127, 0xFF, 0xA, 1);
    draw_number(frameCounter / 36000 - frameCounter / 216000 * 6, arg1 + 264, arg2 + 133, 1, 0xA, 0xFF, 2);
    draw_number(frameCounter / 3600 - frameCounter / 36000 * 10, arg1 + 273, arg2 + 133, 1, 0xA, 0xFF, 2);
    bootsLevel = gPlayerData.bootsLevel;
    hammerLevel = gPlayerData.hammerLevel;
    playerLevel = gPlayerData.level;
    draw_box(4, &D_8026FB30, arg1 + 7, arg2 + 12, 0, playerLevel >= 10 ? 121 : 113, 17, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 320, 240, 0);
    set_hud_element_render_pos(gStatsMenuIconIDs[0], arg1 + 61, arg2 + 21);
    draw_hud_element_3(gStatsMenuIconIDs[0]);
    draw_msg(pause_get_menu_msg(0x43), arg1 + 16, arg2 + 14, 0xFF, 0, 1);
    draw_msg(pause_get_menu_msg(0x44), arg1 + 67, arg2 + 14, 0xFF, 0, 1);
    draw_number(playerLevel, arg1 + 106, arg2 + 14, 1, 0, 0xFF, 2);

    bootsAnimIndex = bootsLevel + 1;
    if (bootsAnimIndex < 0) {
        bootsAnimIndex = 0;
    }
    if (bootsAnimIndex >= 4) {
        bootsAnimIndex = 3;
    }

    hammerAnimIndex = hammerLevel + 1;
    if (hammerAnimIndex < 0) {
        hammerAnimIndex = 0;
    }
    if (hammerAnimIndex >= 4) {
        hammerAnimIndex = 3;
    }

    pause_draw_menu_label(3, arg1 + 137, arg2 + 10);
    pause_draw_menu_label(4, arg1 + 137, arg2 + 35);
    set_hud_element_anim(gStatsMenuIconIDs[1], D_8024F360[bootsAnimIndex]);
    set_hud_element_render_pos(gStatsMenuIconIDs[1], arg1 + 163, arg2 + 29);
    draw_hud_element_3(gStatsMenuIconIDs[1]);
    draw_msg(pause_get_menu_msg(D_8024F380[bootsAnimIndex]), arg1 + 176, arg2 + 23, 0xFF, 0, 1);
    set_hud_element_anim(gStatsMenuIconIDs[2], D_8024F370[bootsAnimIndex]);
    set_hud_element_render_pos(gStatsMenuIconIDs[2], arg1 + 163, arg2 + 0x36);
    draw_hud_element_3(gStatsMenuIconIDs[2]);
    draw_msg(pause_get_menu_msg(D_8024F390[hammerAnimIndex]), arg1 + 176, arg2 + 48, 0xFF, 0, 1);
    pause_draw_menu_label(6, arg1 + 130, arg2 + 69);
    pause_draw_menu_label(5, arg1 + 138, arg2 + 60);

    sphigh = gPlayerData.specialBarsFilled;
    if (sphigh < 0) {
        sphigh += 255;
    }
    sphigh /= 256;
    splow = gPlayerData.specialBarsFilled - sphigh * 256;
    if (splow < 0) {
        splow += 31;
    }
    s4 = 1;
    s2 = s3 = s5 = 0;
    s6 = splow / 32 + sphigh * 8;

    if (s6 > 0) {
        while (1) {
            s3++;
            set_hud_element_anim(gStatsMenuIconIDs[10], D_8024F434[s5]);
            set_hud_element_render_pos(gStatsMenuIconIDs[10], arg1 + ((s5 * 20) + 140) + D_8024F46C, arg2 + 75);
            if (s4 != 0) {
                draw_hud_element_3(gStatsMenuIconIDs[10]);
                s4 = 0;
            } else {
                draw_hud_element_2(gStatsMenuIconIDs[10]);
            }

            s2 = 0 + 1;
            if (s3 >= s6) {
                break;
            }
            s3++;
            set_hud_element_anim(gStatsMenuIconIDs[10], D_8024F434[s5]);
            set_hud_element_render_pos(gStatsMenuIconIDs[10], arg1 + ((s5 * 20) + 140) + D_8024F470, arg2 + 75);
            if (s4 != 0) {
                draw_hud_element_3(gStatsMenuIconIDs[10]);
                s4 = 0;
            } else {
                draw_hud_element_2(gStatsMenuIconIDs[10]);
            }

            s2++;
            if (s3 >= s6) {
                break;
            }
            s3++;
            set_hud_element_anim(gStatsMenuIconIDs[10], D_8024F434[s5]);
            set_hud_element_render_pos(gStatsMenuIconIDs[10], arg1 + ((s5 * 20) + 140) + D_8024F474, arg2 + 75);
            if (s4 != 0) {
                draw_hud_element_3(gStatsMenuIconIDs[10]);
                s4 = 0;
            } else {
                draw_hud_element_2(gStatsMenuIconIDs[10]);
            }

            s2++;
            if (s3 >= s6) {
                break;
            }
            s3++;
            set_hud_element_anim(gStatsMenuIconIDs[10], D_8024F434[s5]);
            set_hud_element_render_pos(gStatsMenuIconIDs[10], arg1 + ((s5 * 20) + 140) + D_8024F478, arg2 + 75);
            if (s4 != 0) {
                draw_hud_element_3(gStatsMenuIconIDs[10]);
                s4 = 0;
            } else {
                draw_hud_element_2(gStatsMenuIconIDs[10]);
            }

            s2++;
            if (s3 >= s6) {
                break;
            }
            s3++;
            set_hud_element_anim(gStatsMenuIconIDs[10], D_8024F434[s5]);
            set_hud_element_render_pos(gStatsMenuIconIDs[10], arg1 + ((s5 * 20) + 140) + D_8024F47C, arg2 + 75);
            if (s4 != 0) {
                draw_hud_element_3(gStatsMenuIconIDs[10]);
                s4 = 0;
            } else {
                draw_hud_element_2(gStatsMenuIconIDs[10]);
            }

            s2++;
            if (s3 >= s6) {
                break;
            }
            s3++;
            set_hud_element_anim(gStatsMenuIconIDs[10], D_8024F434[s5]);
            set_hud_element_render_pos(gStatsMenuIconIDs[10], arg1 + ((s5 * 20) + 140) + D_8024F480, arg2 + 75);
            if (s4 != 0) {
                draw_hud_element_3(gStatsMenuIconIDs[10]);
                s4 = 0;
            } else {
                draw_hud_element_2(gStatsMenuIconIDs[10]);
            }

            s2++;
            if (s3 >= s6) {
                break;
            }
            s3++;
            set_hud_element_anim(gStatsMenuIconIDs[10], D_8024F434[s5]);
            set_hud_element_render_pos(gStatsMenuIconIDs[10], arg1 + ((s5 * 20) + 140) + D_8024F484, arg2 + 75);
            if (s4 != 0) {
                draw_hud_element_3(gStatsMenuIconIDs[10]);
                s4 = 0;
            } else {
                draw_hud_element_2(gStatsMenuIconIDs[10]);
            }

            s2++;
            if (s3 >= s6) {
                break;
            }
            s3++;
            set_hud_element_anim(gStatsMenuIconIDs[10], D_8024F450[s5]);
            set_hud_element_render_pos(gStatsMenuIconIDs[10], arg1 + ((s5 * 20) + 140), arg2 + 77);
            if (s4 != 0) {
                draw_hud_element_3(gStatsMenuIconIDs[10]);
                s4 = 0;
            } else {
                draw_hud_element_2(gStatsMenuIconIDs[10]);
            }

            s5++;
            if (s3 >= s6) {
                break;
            }
        }

    }
/*
    temp_v0_5 = phi_s5_3 * 0x14;
    temp_s6_3 = gPlayerData.unk28E * 8;
    phi_s0 = temp_v0_5 + 0x8C;
    phi_s5_2 = temp_v0_5 + 0x98;
loop_51:
    phi_s2_4 = phi_s2_3;
    phi_s4_11 = phi_s4_10;
    phi_s3_5 = phi_s3_4;
    phi_s4_11 = phi_s4_10;
    if (phi_s3_4 < temp_s6_3) {
        if (phi_s2_3 == 0) {
            temp_s3_12 = phi_s3_4 + 1;
            set_hud_element_anim(gStatsMenuIconIDs[10], &HudScript_StatusSPEmptyIncrement);
            set_hud_element_render_pos(gStatsMenuIconIDs[10], arg1 + phi_s0 + D_8024F46C.unk0, arg2 + 0x4B);
            phi_s3_5 = temp_s3_12;
            if (phi_s4_10 != 0) {
                draw_hud_element_3(gStatsMenuIconIDs[10]);
                phi_s4_11 = 0;
            } else {
                draw_hud_element_2(gStatsMenuIconIDs[10]);
            }
            phi_s2_4 = phi_s2_3 + 1;
            if (temp_s3_12 < temp_s6_3) {
                goto block_58;
            }
        } else {
block_58:
            phi_s2_5 = phi_s2_4;
            phi_s4_12 = phi_s4_11;
            phi_s3_6 = phi_s3_5;
            phi_s4_12 = phi_s4_11;
            if (phi_s2_4 == 1) {
                temp_s3_13 = phi_s3_5 + 1;
                set_hud_element_anim(gStatsMenuIconIDs[10], &HudScript_StatusSPEmptyIncrement);
                set_hud_element_render_pos(gStatsMenuIconIDs[10], arg1 + phi_s0 + D_8024F46C.unk4, arg2 + 0x4B);
                phi_s3_6 = temp_s3_13;
                if (phi_s4_11 != 0) {
                    draw_hud_element_3(gStatsMenuIconIDs[10]);
                    phi_s4_12 = 0;
                } else {
                    draw_hud_element_2(gStatsMenuIconIDs[10]);
                }
                phi_s2_5 = phi_s2_4 + 1;
                if (temp_s3_13 < temp_s6_3) {
                    goto block_63;
                }
            } else {
block_63:
                phi_s2_6 = phi_s2_5;
                phi_s4_13 = phi_s4_12;
                phi_s3_7 = phi_s3_6;
                phi_s4_13 = phi_s4_12;
                if (phi_s2_5 == 2) {
                    temp_s3_14 = phi_s3_6 + 1;
                    set_hud_element_anim(gStatsMenuIconIDs[10], &HudScript_StatusSPEmptyIncrement);
                    set_hud_element_render_pos(gStatsMenuIconIDs[10], arg1 + phi_s0 + D_8024F46C.unk8, arg2 + 0x4B);
                    phi_s3_7 = temp_s3_14;
                    if (phi_s4_12 != 0) {
                        draw_hud_element_3(gStatsMenuIconIDs[10]);
                        phi_s4_13 = 0;
                    } else {
                        draw_hud_element_2(gStatsMenuIconIDs[10]);
                    }
                    phi_s2_6 = phi_s2_5 + 1;
                    if (temp_s3_14 < temp_s6_3) {
                        goto block_69;
                    }
                } else {
block_69:
                    phi_s2_7 = phi_s2_6;
                    phi_s4_14 = phi_s4_13;
                    phi_s3_8 = phi_s3_7;
                    phi_s4_14 = phi_s4_13;
                    if (phi_s2_6 == 3) {
                        temp_s3_15 = phi_s3_7 + 1;
                        set_hud_element_anim(gStatsMenuIconIDs[10], &HudScript_StatusSPEmptyIncrement);
                        set_hud_element_render_pos(gStatsMenuIconIDs[10], arg1 + phi_s0 + D_8024F46C.unkC, arg2 + 0x4B);
                        phi_s3_8 = temp_s3_15;
                        if (phi_s4_13 != 0) {
                            draw_hud_element_3(gStatsMenuIconIDs[10]);
                            phi_s4_14 = 0;
                        } else {
                            draw_hud_element_2(gStatsMenuIconIDs[10]);
                        }
                        phi_s2_7 = phi_s2_6 + 1;
                        if (temp_s3_15 < temp_s6_3) {
                            goto block_75;
                        }
                    } else {
block_75:
                        phi_s2_8 = phi_s2_7;
                        phi_s4_15 = phi_s4_14;
                        phi_s3_9 = phi_s3_8;
                        phi_s4_15 = phi_s4_14;
                        if (phi_s2_7 == 4) {
                            temp_s3_16 = phi_s3_8 + 1;
                            set_hud_element_anim(gStatsMenuIconIDs[10], &HudScript_StatusSPEmptyIncrement);
                            set_hud_element_render_pos(gStatsMenuIconIDs[10], arg1 + phi_s0 + D_8024F46C.unk10, arg2 + 0x4B);
                            phi_s3_9 = temp_s3_16;
                            if (phi_s4_14 != 0) {
                                draw_hud_element_3(gStatsMenuIconIDs[10]);
                                phi_s4_15 = 0;
                            } else {
                                draw_hud_element_2(gStatsMenuIconIDs[10]);
                            }
                            phi_s2_8 = phi_s2_7 + 1;
                            if (temp_s3_16 < temp_s6_3) {
                                goto block_81;
                            }
                        } else {
block_81:
                            phi_s2_9 = phi_s2_8;
                            phi_s4_16 = phi_s4_15;
                            phi_s3_10 = phi_s3_9;
                            phi_s4_16 = phi_s4_15;
                            if (phi_s2_8 == 5) {
                                temp_s3_17 = phi_s3_9 + 1;
                                set_hud_element_anim(gStatsMenuIconIDs[10], &HudScript_StatusSPEmptyIncrement);
                                set_hud_element_render_pos(gStatsMenuIconIDs[10], arg1 + phi_s0 + D_8024F46C.unk14, arg2 + 0x4B);
                                phi_s3_10 = temp_s3_17;
                                if (phi_s4_15 != 0) {
                                    draw_hud_element_3(gStatsMenuIconIDs[10]);
                                    phi_s4_16 = 0;
                                } else {
                                    draw_hud_element_2(gStatsMenuIconIDs[10]);
                                }
                                phi_s2_9 = phi_s2_8 + 1;
                                if (temp_s3_17 < temp_s6_3) {
                                    goto block_87;
                                }
                            } else {
block_87:
                                phi_s2_10 = phi_s2_9;
                                phi_s4_17 = phi_s4_16;
                                phi_s3_11 = phi_s3_10;
                                phi_s4_17 = phi_s4_16;
                                if (phi_s2_9 == 6) {
                                    temp_s3_18 = phi_s3_10 + 1;
                                    set_hud_element_anim(gStatsMenuIconIDs[10], &HudScript_StatusSPEmptyIncrement);
                                    set_hud_element_render_pos(gStatsMenuIconIDs[10], arg1 + phi_s0 + D_8024F46C.unk18, arg2 + 0x4B);
                                    phi_s3_11 = temp_s3_18;
                                    if (phi_s4_16 != 0) {
                                        draw_hud_element_3(gStatsMenuIconIDs[10]);
                                        phi_s4_17 = 0;
                                    } else {
                                        draw_hud_element_2(gStatsMenuIconIDs[10]);
                                    }
                                    phi_s2_10 = phi_s2_9 + 1;
                                    if (temp_s3_18 < temp_s6_3) {
                                        goto block_93;
                                    }
                                } else {
block_93:
                                    phi_s3_4 = phi_s3_11;
                                    phi_s4_10 = phi_s4_17;
                                    phi_s4_10 = phi_s4_17;
                                    if (phi_s2_10 == 7) {
                                        temp_s3_19 = phi_s3_11 + 1;
                                        set_hud_element_anim(gStatsMenuIconIDs[10], &HudScript_StatusStarEmpty);
                                        set_hud_element_render_pos(gStatsMenuIconIDs[10], arg1 + phi_s5_2, arg2 + 0x4D);
                                        phi_s3_4 = temp_s3_19;
                                        if (phi_s4_17 != 0) {
                                            draw_hud_element_3(gStatsMenuIconIDs[10]);
                                            phi_s4_10 = 0;
                                        } else {
                                            draw_hud_element_2(gStatsMenuIconIDs[10]);
                                        }
                                        if (temp_s3_19 < temp_s6_3) {
                                            goto block_98;
                                        }
                                    } else {
block_98:
                                        phi_s0 += 0x14;
                                        phi_s5_2 += 0x14;
                                        goto loop_51;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (gPauseMenuCurrentTab == 1) {
        temp_v0_6 = (arg0->unk3 * 0xC) + &gStatsMenuEntries;
        func_80242D04(0x1F, arg1 + temp_v0_6->unk0, arg2 + temp_v0_6->unk4);
    }
}*/


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

s32 pause_badges_comparator(s16* a, s16* b) {
    s16 aVal;
    s16 bVal;

    if (*a == 0) {
        aVal = BADGE_INVALID;
    } else {
        aVal = gItemTable[*a].badgeSortPriority;
    }

    if (*b == 0) {
        bVal = BADGE_INVALID;
    } else {
        bVal = gItemTable[*b].badgeSortPriority;
    }

    if (aVal == bVal) {
        return 0;
    } else if (aVal < bVal) {
        return -1;
    } else {
        return 1;
    }
}

s32 pause_badges_count_all(void) {
    PlayerData* playerData = &gPlayerData;
    s32 i;

    pause_sort_item_list(playerData->badges, ARRAY_COUNT(playerData->badges), pause_badges_comparator);

    for (i = 0; i < ARRAY_COUNT(playerData->badges); i++) {
        if (playerData->badges[i] == 0) {
            break;
        }
    }

    return i;
}

s32 pause_badges_count_equipped(void) {
    PlayerData* playerData = &gPlayerData;
    s32 i;

    pause_sort_item_list(playerData->equippedBadges, ARRAY_COUNT(playerData->equippedBadges), &pause_badges_comparator);

    for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++) {
        if (playerData->equippedBadges[i] == 0) {
            break;
        }
    }

    return i;
}

s32 pause_badges_get_pos_x(s32 page, s32 itemIndex) {
    return (itemIndex % BADGE_MENU_PAGE(page)->numCols) * 141;
}

s32 pause_badges_get_pos_y(s32 page, s32 itemIndex) {
    return ((page + 1) * 11) + (BADGE_MENU_PAGE(page)->listStart * 16) + ((itemIndex / BADGE_MENU_PAGE(
                page)->numCols) * 16);
}

s32 pause_badges_get_column(s32 page, s32 itemIdx) {
    return itemIdx % BADGE_MENU_PAGE(page)->numCols;
}

s32 pause_badges_get_row(s32 page, s32 itemIdx) {
    return BADGE_MENU_PAGE(page)->listStart + (itemIdx / BADGE_MENU_PAGE(page)->numCols);
}

s32 pause_badges_is_visible(s32 y) {
    if (y < gBadgeMenuCurrentScrollPos - 32) {
        return FALSE;
    } else {
        return y < gBadgeMenuCurrentScrollPos + 128;
    }
}

s32 pause_badges_scroll_offset_y(s32 offset) {
    return offset - gBadgeMenuCurrentScrollPos;
}

s32 pause_badges_scroll_offset_x(s32 x) {
    return x;
}

s32 pause_badges_try_remove(s16 badgeID) {
    s16 *currentSlot = gPlayerData.equippedBadges;
    s16 *slotToRemove = currentSlot;
    s32 result = 0;
    s32 i;

    if (badgeID == BADGE_INVALID) {
        return 0;
    }

    for (i = 0; i < ARRAY_COUNT(gPlayerData.equippedBadges); i++, currentSlot++) {
        if (badgeID == *currentSlot) {
            slotToRemove = currentSlot;
            result = 1;
            break;
        }
    }

    // Remove and shift array contents
    for (; i < ARRAY_COUNT(gPlayerData.equippedBadges) - 1; i++, currentSlot++) {
        *currentSlot = *(currentSlot + 1);
    }
    *currentSlot = 0;

    if (*slotToRemove == 0) {
        result = 2;
    }
    return result;
}

typedef enum BadgeEquipResult {
    EQUIP_RESULT_ALREADY_EQUIPPED,
    EQUIP_RESULT_NOT_ENOUGH_BP,
    EQUIP_RESULT_TOO_MANY_BADGES,
    EQUIP_RESULT_SUCCESS,
} BadgeEquipResult;

s32 pause_badges_try_equip(s16 badgeID) {
    PlayerData* playerData = &gPlayerData;
    s16 *badgeSlot = &playerData->equippedBadges[0];
    s32 i;
    s32 totalEquippedBP;

    if (badgeID == BADGE_NONE_STANDIN) {
        badgeID = 0;
    }
    if (badgeID == BADGE_INVALID) {
        badgeID = 0;
    }
    if (badgeID == 0) {
        return EQUIP_RESULT_NOT_ENOUGH_BP;
    }

    for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++, badgeSlot++) {
        if (*badgeSlot == badgeID) {
            return EQUIP_RESULT_ALREADY_EQUIPPED;
        }
    }

    totalEquippedBP = pause_get_total_equipped_bp_cost();
    if (badgeID != 0) {
        u8 moveID = gItemTable[badgeID].moveID;
        s32 requiredBP = totalEquippedBP + gMoveTable[moveID].costBP;

        if (playerData->maxBP < requiredBP) {
            return EQUIP_RESULT_NOT_ENOUGH_BP;
        }
    }

    badgeSlot = &playerData->equippedBadges[0];
    for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++, badgeSlot++) {
        if (*badgeSlot == 0) {
            *badgeSlot = badgeID;
            break;
        }
    }
    if (i == ARRAY_COUNT(playerData->equippedBadges)) {
        return EQUIP_RESULT_TOO_MANY_BADGES;
    } else {
        return EQUIP_RESULT_SUCCESS;
    }
}

void pause_badges_draw_bp_orbs(s32 orbState, s32 x, s32 y) {
    s32 orbSize = 8;

    switch (orbState) {
        case 0:
            pause_draw_rect(x * 4, y * 4, (x + orbSize) * 4, (y + orbSize) * 4, 0, 0, 256, 1024, 1024);
            break;
        case 1:
            pause_draw_rect(x * 4, y * 4, (x + orbSize) * 4, (y + orbSize) * 4, 0, 0, 0, 1024, 1024);
            break;
        default:
            pause_draw_rect(x * 4, y * 4, (x + orbSize) * 4, (y + orbSize) * 4, 0, 0, 512, 1024, 1024);
            break;
    }
}

INCLUDE_ASM(s32, "pause/138CC0", pause_badges_draw_contents);

void pause_badges_load_badges(s32 onlyEquipped) {
    PlayerData* playerData = &gPlayerData;
    s32 numItems = 0;
    PauseItemPage* page;
    s32 i;

    D_80270388 = 0;
    if (!onlyEquipped) {
        for (i = 0; i < ARRAY_COUNT(playerData->badges); i++) {
            s16 badgeItemID = playerData->badges[i];

            if (badgeItemID == 0) {
                continue;
            } else if (badgeItemID > ITEM_LAST_BADGE) {
                break;
            } else {
                gBadgeMenuItemIDs[numItems] = badgeItemID;
                numItems += 1;
            }
        }
    } else {
        s16* equippedBadges;

        // This is just called to sort equippedBadges, the count is discarded
        pause_badges_count_equipped();

        equippedBadges = playerData->equippedBadges;
        for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++) {
            // This can be written more clearly as equippedBadges[i],
            // but that causes some instruction reordering
            s16 badgeItemID = *equippedBadges;

            if (badgeItemID != 0) {
                gBadgeMenuItemIDs[numItems] = badgeItemID;
                numItems += 1;
            }
            equippedBadges++;
        }
    }
    if (numItems == 0) {
        gBadgeMenuItemIDs[0] = BADGE_NONE_STANDIN;
        numItems = 1;
    }
    gBadgeMenuNumItems = numItems;
    for (i = numItems; i < ARRAY_COUNT(gBadgeMenuItemIDs); i++) {
        gBadgeMenuItemIDs[i] = BADGE_INVALID;
    }

    gBadgeMenuSelectedIndex = 0;
    gBadgeMenuSelectedItemID = 0;
    D_8027037C = 0;
    D_80270394 = 0;
    gBadgeMenuCurrentPage = 0;

    page = &gBadgeMenuPages[0];
    i = 0;

    for (i = 0; i < gBadgeMenuNumItems / 8; i++, page++) {
        page->listStart = i * 8;
        page->numCols = 1;
        page->numRows = 8;
        page->enabled = TRUE;
        page->startIndex = i * 8;
        page->count = 8;
    }

    if ((gBadgeMenuNumItems % 8) != 0) {
        s16 count;
        s32 menuNumItems;

        page->listStart = i * 8;
        page->numCols = 1;
        page->enabled = TRUE;
        page->startIndex = i * 8;

        menuNumItems = gBadgeMenuNumItems;
        count = menuNumItems - (menuNumItems / 8 * 8);
        page->count = count;
        page->numRows = page->count;
        i++;
        page++;
    }

    while (i < ARRAY_COUNT(gBadgeMenuPages)) {
        page->enabled = FALSE;

        i++;
        page++;
    }

    gBadgeMenuTargetScrollPos = gBadgeMenuCurrentScrollPos = pause_badges_get_pos_y(0, 0);
}

void pause_badges_init(MenuPanel* panel) {
    s32 i;

    // This sorts the badge list and then discards the count
    pause_badges_count_all();

    gBadgeMenuLevel = 0;
    gBadgeMenuCurrentTab = 0;
    gBadgeMenuBShowNotEnoughBP = 0;

    pause_badges_load_badges(FALSE);
    if (gBadgeMenuItemIDs[0] == BADGE_NONE_STANDIN) {
        panel->unk_00.c.initialized = FALSE;
        return;
    }

    for (i = 0; i < ARRAY_COUNT(gBadgeMenuIconIDs); i++) {
        s32 iconID = create_hud_element(gBadgeMenuElements[i]);

        gBadgeMenuIconIDs[i] = iconID;
        set_hud_element_flags(iconID, 0x80);
    }

    for (i = 0; i < ARRAY_COUNT(gBadgeMenuWindowBPs); i++) {
        gBadgeMenuWindowBPs[i].tab = panel;
    }
    setup_pause_menu_tab(gBadgeMenuWindowBPs, ARRAY_COUNT(gBadgeMenuWindowBPs));
    panel->unk_00.c.initialized = TRUE;
}

void pause_badges_handle_input(MenuPanel* panel) {
    s32 selectedIndex = gBadgeMenuSelectedIndex;
    s32 numCols = gBadgeMenuPages[gBadgeMenuCurrentPage].numCols;

    s32 selectedCol = selectedIndex % numCols;
    s32 selectedRow = selectedIndex / numCols;

    if (gPauseMenuPressedButtons & BUTTON_A) {
        s16 badgeID;

        if (gBadgeMenuBShowNotEnoughBP != 0) {
            gBadgeMenuBShowNotEnoughBP = 0;
        } else if (gBadgeMenuLevel == 0) {
            if (gBadgeMenuItemIDs[selectedIndex] == BADGE_NONE_STANDIN) {
                sfx_play_sound(SOUND_MENU_BADGE_ERROR);
            } else {
                gBadgeMenuLevel = 1;
                sfx_play_sound(SOUND_MENU_NEXT);
            }
        } else {
            badgeID = gBadgeMenuItemIDs[selectedIndex];
            switch (pause_badges_try_equip(badgeID)) {
                case EQUIP_RESULT_ALREADY_EQUIPPED:
                    sfx_play_sound(SOUND_MENU_BADGE_UNEQUIP);
                    pause_badges_try_remove(badgeID);
                    break;
                case EQUIP_RESULT_NOT_ENOUGH_BP:
                    sfx_play_sound(SOUND_MENU_BADGE_ERROR);
                    gBadgeMenuBShowNotEnoughBP = 1;
                    break;
                case EQUIP_RESULT_TOO_MANY_BADGES:
                    sfx_play_sound(SOUND_MENU_BADGE_ERROR);
                    gBadgeMenuBShowNotEnoughBP = 2;
                    break;
                case EQUIP_RESULT_SUCCESS:
                    sfx_play_sound(SOUND_MENU_BADGE_EQUIP);
                    break;
            }
        }
        return;
    }

    if ((gPauseMenuPressedButtons != 0) || (gPauseMenuHeldButtons != 0)) {
        gBadgeMenuBShowNotEnoughBP = 0;
    }

    if (gBadgeMenuNumItems != 0) {
        if (gBadgeMenuLevel == 0) {
            s32 oldTab = gBadgeMenuCurrentTab;

            if (gPauseMenuHeldButtons & (BUTTON_STICK_UP | BUTTON_STICK_DOWN)) {
                gBadgeMenuCurrentTab ^= 1;
            }
            if (oldTab != gBadgeMenuCurrentTab) {
                sfx_play_sound(SOUND_MENU_CHANGE_TAB);
                pause_badges_load_badges(gBadgeMenuCurrentTab);
            }
        } else {
            s32 heldButtons = gPauseMenuHeldButtons;
            s32 heldButtons2;
            u8 newPageNumCols;

            if (heldButtons & (BUTTON_STICK_UP | BUTTON_Z)) {
                if (heldButtons & BUTTON_STICK_UP) {
                    selectedRow -= 1;
                    if (selectedRow < 0) {
                        selectedRow = 0;
                    }
                    if (selectedRow < gBadgeMenuPages[gBadgeMenuCurrentPage].listStart) {
                        gBadgeMenuCurrentPage -= 1;
                    }
                } else {
                    // Z button press
                    gBadgeMenuCurrentPage -= 1;
                    if (gBadgeMenuCurrentPage < 0) {
                        gBadgeMenuCurrentPage = 0;
                    }
                    selectedRow = gBadgeMenuPages[gBadgeMenuCurrentPage].listStart;
                }
            }

            // Need to re-read button state here for strange regalloc reasons
            heldButtons2 = gPauseMenuHeldButtons;
            if (heldButtons2 & (BUTTON_STICK_DOWN | BUTTON_R)) {
                if (heldButtons2 & BUTTON_STICK_DOWN) {
                    PauseItemPage* page = &gBadgeMenuPages[gBadgeMenuCurrentPage];

                    selectedRow += 1;
                    if (selectedRow >= (page->listStart + page->numRows)) {
                        gBadgeMenuCurrentPage += 1;
                        if (!gBadgeMenuPages[gBadgeMenuCurrentPage].enabled) {
                            gBadgeMenuCurrentPage -= 1;
                            selectedRow -= 1;
                        }
                    }
                } else {
                    // R button press
                    PauseItemPage* newPage;

                    gBadgeMenuCurrentPage++;
                    newPage = &gBadgeMenuPages[gBadgeMenuCurrentPage];

                    if (!newPage->enabled) {
                        gBadgeMenuCurrentPage -= 1;
                    } else {
                        selectedRow = newPage->listStart;
                    }
                }
            }

            newPageNumCols = gBadgeMenuPages[gBadgeMenuCurrentPage].numCols;
            if (gBadgeMenuItemIDs[selectedRow * newPageNumCols] != BADGE_NONE_STANDIN) {
                if (gPauseMenuHeldButtons & BUTTON_STICK_LEFT) {
                    selectedCol -= 1;
                    if (selectedCol < 0) {
                        selectedCol = newPageNumCols - 1;
                    }
                } else if (gPauseMenuHeldButtons & BUTTON_STICK_RIGHT) {
                    selectedCol += 1;
                    if (selectedCol >= newPageNumCols) {
                        selectedCol = 0;
                    }
                }
            } else {
                selectedCol = 0;
            }
            gBadgeMenuSelectedIndex = selectedCol + (selectedRow * gBadgeMenuPages[gBadgeMenuCurrentPage].numCols);
            if (gBadgeMenuSelectedIndex != selectedIndex) {
                sfx_play_sound(SOUND_MENU_CHANGE_SELECTION);
            }
            gBadgeMenuSelectedItemID = gBadgeMenuItemIDs[gBadgeMenuSelectedIndex];
        }
    }

    if (gBadgeMenuLevel == 1) {
        s32 itemID = gBadgeMenuSelectedItemID;

        if (((itemID != BADGE_NONE_STANDIN) && (itemID != BADGE_INVALID) && (itemID != 0))) {
            gPauseMenuCurrentDescMsg = gItemTable[itemID].menuMsg;
        } else {
            gPauseMenuCurrentDescMsg = 0;
            gPauseMenuCurrentDescIconScript = NULL;
        }
    } else {
        gPauseMenuCurrentDescMsg = pause_get_menu_msg(gBadgeMenuCurrentTab == 0 ? 0x4C : 0x4D);
        gPauseMenuCurrentDescIconScript = NULL;
    }

    if (gPauseMenuPressedButtons & BUTTON_B) {
        if (gBadgeMenuLevel == 0) {
            sfx_play_sound(SOUND_MENU_BACK);
            gPauseMenuCurrentTab = 0;
        } else {
            sfx_play_sound(SOUND_MENU_BACK);
            gBadgeMenuLevel = 0;
            enforce_hpfp_limits();
            if (gBadgeMenuCurrentTab == 1) {
                pause_badges_load_badges(TRUE);
            }
        }
    }
}

void pause_badges_update(void) {
    PauseItemPage* menuPages = gBadgeMenuPages;
    PauseItemPage* currentMenuPage = &menuPages[gBadgeMenuCurrentPage];
    s32 temp = (gBadgeMenuSelectedIndex / currentMenuPage->numCols) - currentMenuPage->listStart;
    s32* currentScrollPos;

    if ((temp < 2) || currentMenuPage->numRows < 9) {
        D_80270394 = 0;
    } else if (temp >= currentMenuPage->numRows - 2) {
        D_80270394 = currentMenuPage->numRows - 8;
    } else {
        s32* unkSym = &D_80270394;

        if (temp - *unkSym >= 7) {
            *unkSym = temp - 6;
        } else if (temp - *unkSym <= 0) {
            *unkSym = temp - 1;
        }
    }

    currentScrollPos = &gBadgeMenuCurrentScrollPos;
    gBadgeMenuTargetScrollPos = pause_badges_get_pos_y(gBadgeMenuCurrentPage, D_80270394 * currentMenuPage->numCols);
    *currentScrollPos += pause_interp_vertical_scroll(gBadgeMenuTargetScrollPos - *currentScrollPos);
}

void pause_badges_cleanup(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gBadgeMenuIconIDs); i++) {
        free_hud_element(gBadgeMenuIconIDs[i]);
    }
}
