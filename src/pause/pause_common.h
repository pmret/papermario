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
extern HudScript HudScript_FPCost[];
extern HudScript HudScript_PartnerRank[];
extern HudScript HudScript_MoveDiamond[];
extern HudScript HudScript_MoveBlueOrb[];
extern HudScript HudScript_MoveGreenOrb[];
extern HudScript HudScript_MoveRedOrb[];
extern HudScript HudScript_MapWalk0[];
extern HudScript HudScript_StatusSPIncrement1[];
extern HudScript HudScript_StatusSPIncrement2[];
extern HudScript HudScript_StatusSPIncrement3[];
extern HudScript HudScript_StatusSPIncrement4[];
extern HudScript HudScript_StatusSPIncrement5[];
extern HudScript HudScript_StatusSPIncrement6[];
extern HudScript HudScript_StatusSPIncrement7[];
extern HudScriptPair gItemHudScripts[];

//TODO add in functions.h
void update_window_hierarchy(s32 windowIndex, s32 arg1);
void get_msg_properties(s32 msgID, s32* height, s32* width, s32* maxLineChars, s32* numLines,
                        s32* maxLinesPerPage, s32* arg6, s32 charset);
void replace_window_update(s32 idx, s8 arg1, WindowUpdateFunc pendingFunc);
void decode_yay0(void* src, void* dst);

extern MenuPanel gPausePanelTabs;
extern MenuPanel gPausePanelStats;
extern MenuPanel gPausePanelBadges;
extern MenuPanel gPausePanelItems;
extern MenuPanel gPausePanelPartners;
extern MenuPanel gPausePanelSpirits;
extern MenuPanel gPausePanelMap;
extern MenuPanel* gPausePanels[];

extern Gfx gPauseDLOrbs[];

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

//bss
extern s32 gPauseHeldButtons;
extern s32 gPausePressedButtons;
extern s32 gPauseCurrentDescMsg;
extern HudScript* gPauseCurrentDescIconScript;
extern s32 gPauseCursorIconID;
extern s8 gPauseMenuCurrentTab;

extern s8  gPauseBufferPal1[512];
extern s8  gPauseBufferImg1[15752];
extern s8  gPauseBufferPal2[512];
extern s8  gPauseBufferImg2[15752];

void pause_tutorial_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_main_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_textbox_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_draw_cursor(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_tabs_draw_stats(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_tabs_draw_badges(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_tabs_draw_items(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_tabs_draw_party(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_tabs_draw_spirits(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_tabs_draw_map(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_tabs_draw_invis(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_stats_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_badges_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_items_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_partners_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_partners_draw_title(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_partners_draw_movelist(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_partners_draw_movelist_title(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_partners_draw_movelist_flower(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_spirits_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_spirits_draw_title(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_map_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_map_draw_title(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);

void pause_tabs_init(MenuPanel* tab);
void pause_tabs_handle_input(MenuPanel* tab);
void pause_tabs_update(MenuPanel* tab);
void pause_tabs_cleanup(MenuPanel* tab);
void pause_stats_init(MenuPanel* panel);
void pause_stats_handle_input(MenuPanel* panel);
void pause_stats_cleanup(MenuPanel* panel);

void pause_update_tab_default(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
void pause_update_tab_active(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
void pause_update_tab_inactive(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
void pause_update_page_active_1(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
void pause_update_page_inactive_1(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
void pause_update_page_active_2(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
void pause_update_page_inactive_2(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);

void pause_set_cursor_pos(s32 windowID, s32 posX, s32 posY);
void pause_set_cursor_pos_immediate(s32 windowID, s32 posX, s32 posY);
void pause_set_cursor_opacity(s32 val);
void pause_draw_menu_label(s32 index, s32 x, s32 y);

#endif
