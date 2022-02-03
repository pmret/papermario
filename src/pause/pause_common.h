#ifndef PAUSE_COMMON_H
#define PAUSE_COMMON_H

#include "common.h"
#include "hud_element.h"

extern HudScript HudScript_PressAButton[];
extern HudScript HudScript_PressStartButton[];
extern HudScript HudScript_StartButtonText[];
extern HudScript HudScript_StickTapRight[];
extern HudScript HudScript_UnusedBadge[];
extern HudScript HudScript_AnimatedCursorHand[];
extern HudScript HudScript_DescMsgPrev[];
extern HudScript HudScript_DescMsgNext[];
extern HudScript HudScript_HeaderStats[];
extern HudScript HudScript_HeaderBadges[];
extern HudScript HudScript_HeaderItems[];
extern HudScript HudScript_HeaderParty[];
extern HudScript HudScript_HeaderSpirits[];
extern HudScript HudScript_HeaderMap[];
extern HudScript HudScript_MarioHeadSmall[];
extern HudScript HudScript_StatBoots0[];
extern HudScript HudScript_StatBoots1[];
extern HudScript HudScript_StatBoots2[];
extern HudScript HudScript_StatBoots3[];
extern HudScript HudScript_StatHammer0[];
extern HudScript HudScript_StatHammer1[];
extern HudScript HudScript_StatHammer2[];
extern HudScript HudScript_StatHammer3[];
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
extern HudScript HudScript_ListPrevPage[];
extern HudScript HudScript_ListNextPage[];
extern HudScript HudScript_Dash[];
extern HudScript HudScript_LabelBpNeeded[];

//TODO add in functions.h
void update_window_hierarchy(s32 windowIndex, s32 arg1);
void get_msg_properties(s32 msgID, s32* height, s32* width, s32* maxLineChars, s32* numLines,
                        s32* maxLinesPerPage, s32* arg6, s32 charset);
void replace_window_update(s32 idx, s8 arg1, WindowUpdateFunc pendingFunc);

extern MenuPanel gPausePanelTabs;
extern MenuPanel gPausePanelStats;
extern MenuPanel gPausePanelBadges;
extern MenuPanel gPausePanelItems;
extern MenuPanel gPausePanelPartners;
extern MenuPanel gPausePanelSpirits;
extern MenuPanel gPausePanelMap;
extern MenuPanel* gPausePanels[];

extern WindowStyleCustom gPauseWS_0;
extern WindowStyleCustom gPauseWS_1;
extern WindowStyleCustom gPauseWS_2;
extern WindowStyleCustom gPauseWS_3;
extern WindowStyleCustom gPauseWS_4;
extern WindowStyleCustom gPauseWS_5;
extern WindowStyleCustom gPauseWS_6;
extern WindowStyleCustom gPauseWS_7;
extern WindowStyleCustom gPauseWS_8;
extern WindowStyleCustom gPauseWS_9;
extern WindowStyleCustom gPauseWS_10;
extern WindowStyleCustom gPauseWS_11;
extern WindowStyleCustom gPauseWS_12;
extern WindowStyleCustom gPauseWS_13;
extern WindowStyleCustom gPauseWS_14;
extern WindowStyleCustom gPauseWS_15;
extern WindowStyleCustom gPauseWS_16;
extern WindowStyleCustom gPauseWS_17;
extern WindowStyleCustom gPauseWS_18;
extern WindowStyleCustom gPauseWS_19;
extern WindowStyleCustom gPauseWS_20;
extern WindowStyleCustom gPauseWS_21;
extern WindowStyleCustom gPauseWS_22;
extern WindowStyleCustom gPauseWS_23;
extern WindowStyleCustom gPauseWS_24;
extern WindowStyleCustom gPauseWS_25;
extern WindowStyleCustom gPauseWS_26;
extern WindowStyleCustom gPauseWS_27;
extern WindowStyleCustom gPauseWS_28;

//extern
extern s32 gPauseHeldButtons;
extern s32 gPausePressedButtons;
extern s32 gPauseCurrentDescMsg;
extern HudScript* gPauseCurrentDescIconScript;
extern s32 gPauseCursorIconID;
extern s8 gPauseMenuCurrentTab;
extern s32 gPauseTutorialFrameCounter;
extern s32 D_802700E4;
extern s32 D_802700E8;
extern s32 D_802700EC;
extern s32 D_802700F0[4];
extern s32 D_80270100;
extern s32 D_80270104;
extern s32 gPauseShownDescMsg;
extern s32 gPauseDescTextMaxPos;
extern s32 gPauseDescTextPos;
extern s32 gPauseDescTextOffset;
extern HudScript* gPauseShownDescIconScript;
extern s32 gPauseTutorialSprites[3];
extern s32 D_80270128[2];
extern s32 D_80270130[4];
extern s32 D_80270140;
extern s32 D_80270144;
extern s32 D_80270148;
extern s32 D_8027014C;
extern s32 D_80270150[4];
extern s32 D_80270160[4];
extern s32 D_80270170[4];
extern s32 D_80270180[4];
extern s32 D_80270190[4];
extern s32 D_802701A0[4];
extern s32 D_802701B0[4];
extern s32 D_802701C0[4];
extern s32 D_802701D0[4];
extern s32 D_802701E0[4];
extern s32 D_802701F0[4];
extern s32 D_80270200[64];
extern s32 D_80270300[64];
extern s32 D_80270400[64];
extern s32 D_80270500[64];
extern s32 D_80270600[64];
extern s32 D_80270700[1];
extern s32 D_80270704[63];
extern s32 D_80270800[64];
extern s32 D_80270900[64];
extern s32 D_80270A00[64];
extern s32 D_80270B00[64];
extern s32 D_80270C00[64];
extern s32 D_80270D00[64];
extern s32 D_80270E00[64];
extern s32 D_80270F00[64];
extern s32 D_80271000[1024];
extern s32 D_80272000[1024];
extern s32 D_80273000[1024];
extern s32 D_80274000[1024];
extern s32 D_80275000[1024];
extern s32 D_80276000[1024];
extern s32 D_80277000[1024];
extern s32 D_80278000[64];
extern s32 D_80278100[64];
extern s32 D_80278200[64];
extern s32 D_80278300[64];
extern s32 D_80278400[64];
extern s32 D_80278500[64];
extern s32 D_80278600[4];
extern s32 D_80278610[4];
extern s32 D_80278620[4];
extern s32 D_80278630[4];

void pause_tutorial_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_main_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_textbox_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_cursor_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_tabs_draw_stats(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_tabs_draw_badges(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_tabs_draw_items(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_tabs_draw_party(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_tabs_draw_spirits(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_tabs_draw_map(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_tabs_draw_invis(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_stats_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_badges_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);

void pause_tabs_init(MenuPanel* tab);
void pause_tabs_handle_input(MenuPanel* tab);
void pause_tabs_update(MenuPanel* tab);
void pause_tabs_cleanup(MenuPanel* tab);
void pause_stats_init(MenuPanel* panel);
void pause_stats_handle_input(MenuPanel* panel);
void pause_stats_cleanup(MenuPanel* panel);

void pause_update_tab_default(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
void pause_update_tab_getting_focus(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
void pause_update_tab_losing_focus(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
void func_80243238(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
void func_802432E8(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
void func_80243188(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
void func_80243388(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);

void pause_set_cursor_pos(s32 windowID, s32 posX, s32 posY);
void pause_set_cursor_pos_immediate(s32 windowID, s32 posX, s32 posY);
void pause_set_cursor_opacity(s32 val);

#endif
