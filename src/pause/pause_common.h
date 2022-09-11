#ifndef PAUSE_COMMON_H
#define PAUSE_COMMON_H

#include "common.h"
#include "hud_element.h"

extern HudScript HES_PressAButton;
extern HudScript HES_PressStartButton;
extern HudScript HES_StartButtonText;
extern HudScript HES_StickTapRight;
extern HudScript HES_UnusedBadge;
extern HudScript HES_AnimatedCursorHand;
extern HudScript HES_DescMsgPrev;
extern HudScript HES_DescMsgNext;
extern HudScript HES_HeaderStats;
extern HudScript HES_HeaderBadges;
extern HudScript HES_HeaderItems;
extern HudScript HES_HeaderParty;
extern HudScript HES_HeaderSpirits;
extern HudScript HES_HeaderMap;
extern HudScript HES_MarioHeadSmall;
extern HudScript HES_StatBoots0;
extern HudScript HES_StatBoots1;
extern HudScript HES_StatBoots2;
extern HudScript HES_StatBoots3;
extern HudScript HES_StatHammer0;
extern HudScript HES_StatHammer1;
extern HudScript HES_StatHammer2;
extern HudScript HES_StatHammer3;
extern HudScript HES_StatusStarPoint;
extern HudScript HES_StatStarPiece_1;
extern HudScript HES_Clock;
extern HudScript HES_StatusHeart;
extern HudScript HES_StatFp_1;
extern HudScript HES_StatBp;
extern HudScript HES_StatusStar1;
extern HudScript HES_StatusStar2;
extern HudScript HES_StatusStar3;
extern HudScript HES_StatusStar4;
extern HudScript HES_StatusStar5;
extern HudScript HES_StatusStar6;
extern HudScript HES_StatusStar7;
extern HudScript HES_StatusStarEmpty;
extern HudScript HES_StatTimes;
extern HudScript HES_ListPrevPage;
extern HudScript HES_ListNextPage;
extern HudScript HES_Dash;
extern HudScript HES_LabelBpNeeded;
extern HudScript HES_FPCost;
extern HudScript HES_PartnerRank;
extern HudScript HES_MoveDiamond;
extern HudScript HES_MoveBlueOrb;
extern HudScript HES_MoveGreenOrb;
extern HudScript HES_MoveRedOrb;
extern HudScript HES_MapWalk0;
extern HudScript HES_StatusSPIncrement1;
extern HudScript HES_StatusSPIncrement2;
extern HudScript HES_StatusSPIncrement3;
extern HudScript HES_StatusSPIncrement4;
extern HudScript HES_StatusSPIncrement5;
extern HudScript HES_StatusSPIncrement6;
extern HudScript HES_StatusSPIncrement7;
extern HudScript HES_StatusSPEmptyIncrement;
extern IconHudScriptPair gItemHudScripts[];

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

void pause_update_tab_default(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
void pause_update_tab_active(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
void pause_update_tab_inactive(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
void pause_update_page_active_1(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
void pause_update_page_inactive_1(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
void pause_update_page_active_2(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
void pause_update_page_inactive_2(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);

void pause_set_cursor_pos(s32 windowID, s32 posX, s32 posY);
void pause_set_cursor_pos_immediate(s32 windowID, s32 posX, s32 posY);
void pause_set_cursor_opacity(s32 val);
void pause_draw_menu_label(s32 index, s32 x, s32 y);
s32 pause_get_total_equipped_bp_cost(void);
void pause_draw_rect(s32 ulx, s32 uly, s32 lrx, s32 lry, s32 tileDescriptor, s32 uls, s32 ult, s32 dsdx, s32 dtdy);
s32 pause_get_menu_msg(s32 index);
s32 pause_interp_vertical_scroll(s32 deltaBefore);
void pause_sort_item_list(s16* arr, s32 len, s32 (*compare)(s16*, s16 *));

#endif
