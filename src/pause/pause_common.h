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

enum PauseMenuLabels {
    PAUSE_LBL_HP        = 0,
    PAUSE_LBL_FP        = 1,
    PAUSE_LBL_BP        = 2,
    PAUSE_LBL_BOOTS     = 3,
    PAUSE_LBL_HAMMER    = 4,
    PAUSE_LBL_ENERGY    = 5,
    PAUSE_LBL_STATS     = 6,
    PAUSE_LBL_AVAILABLE = 7,
    PAUSE_LBL_ABILITIES = 8,
};

enum PauseMenuMessages {
    PAUSE_MSG_NONE                  = 0x00,
    PAUSE_MSG_TUT_NAME_BADGES       = 0x01,
    PAUSE_MSG_TUT_UNUSED_1          = 0x02,
    PAUSE_MSG_TUT_UNUSED_2          = 0x03,
    PAUSE_MSG_TUT_UNUSED_3          = 0x04,
    PAUSE_MSG_TUT_UNUSED_4          = 0x05,
    PAUSE_MSG_TUT_UNUSED_5          = 0x06,
    PAUSE_MSG_TUT_UNUSED_6          = 0x07,
    PAUSE_MSG_TUT_UNUSED_7          = 0x08,
    PAUSE_MSG_TUT_DESC_1            = 0x09,
    PAUSE_MSG_TUT_DESC_2            = 0x0A,
    PAUSE_MSG_TUT_DESC_3            = 0x0B,
    PAUSE_MSG_TUT_DESC_4            = 0x0C,
    PAUSE_MSG_TUT_DESC_5            = 0x0D,
    PAUSE_MSG_TUT_DESC_6            = 0x0E,
    PAUSE_MSG_TUT_DESC_7            = 0x0F,
    PAUSE_MSG_TUT_CMD_1             = 0x10,
    PAUSE_MSG_TUT_CMD_2             = 0x11,
    PAUSE_MSG_TUT_CMD_3             = 0x12,
    PAUSE_MSG_TUT_CMD_4             = 0x13,
    PAUSE_MSG_TUT_CMD_5             = 0x14,
    PAUSE_MSG_TUT_CMD_6             = 0x15,
    PAUSE_MSG_TUT_CMD_7             = 0x16,
    PAUSE_MSG_17                    = 0x17,
    PAUSE_MSG_18                    = 0x18,
    PAUSE_MSG_19                    = 0x19,
    PAUSE_MSG_1A                    = 0x1A,
    PAUSE_MSG_TAB_STATS             = 0x1B,
    PAUSE_MSG_TAB_BADGES            = 0x1C,
    PAUSE_MSG_TAB_ITEMS             = 0x1D,
    PAUSE_MSG_TAB_PARTY             = 0x1E,
    PAUSE_MSG_TAB_SPIRITS           = 0x1F,
    PAUSE_MSG_TAB_MAP               = 0x20,
    PAUSE_MSG_TIP_CONTROLS          = 0x21,
    PAUSE_MSG_TIP_HP                = 0x22,
    PAUSE_MSG_TIP_FP                = 0x23,
    PAUSE_MSG_TIP_BP                = 0x24,
    PAUSE_MSG_TIP_BOOTS_1           = 0x25,
    PAUSE_MSG_TIP_BOOTS_2           = 0x26,
    PAUSE_MSG_TIP_BOOTS_3           = 0x27,
    PAUSE_MSG_TIP_HAMMER_0          = 0x28,
    PAUSE_MSG_TIP_HAMMER_1          = 0x29,
    PAUSE_MSG_TIP_HAMMER_2          = 0x2A,
    PAUSE_MSG_TIP_HAMMER_3          = 0x2B,
    PAUSE_MSG_TIP_STAR_POWER        = 0x2C,
    PAUSE_MSG_TIP_STAR_POINTS       = 0x2D,
    PAUSE_MSG_TIP_COINS             = 0x2E,
    PAUSE_MSG_TIP_SECRETS           = 0x2F,
    PAUSE_MSG_TIP_STAR_PIECES       = 0x30,
    PAUSE_MSG_TIP_TIME              = 0x31,
    PAUSE_MSG_LBL_COINS             = 0x32,
    PAUSE_MSG_LBL_STAR_POINTS       = 0x33,
    PAUSE_MSG_LBL_STAR_PIECES       = 0x34,
    PAUSE_MSG_LBL_TIME              = 0x35,
    PAUSE_MSG_LBL_HP                = 0x36,
    PAUSE_MSG_LBL_FP                = 0x37,
    PAUSE_MSG_LBL_BP                = 0x38,
    PAUSE_MSG_SLASH                 = 0x39,
    PAUSE_MSG_DOT                   = 0x3A,
    PAUSE_MSG_3B                    = 0x3B,
    PAUSE_MSG_3C                    = 0x3C,
    PAUSE_MSG_3D                    = 0x3D,
    PAUSE_MSG_3E                    = 0x3E,
    PAUSE_MSG_3F                    = 0x3F,
    PAUSE_MSG_40                    = 0x40,
    PAUSE_MSG_41                    = 0x41,
    PAUSE_MSG_42                    = 0x42,
    PAUSE_MSG_MARIO                 = 0x43,
    PAUSE_MSG_LEVEL                 = 0x44,
    PAUSE_MSG_NO_BADGE              = 0x45,
    PAUSE_MSG_BADGE_BP              = 0x46,
    PAUSE_MSG_ALL_BADGES            = 0x47,
    PAUSE_MSG_ACTIVE                = 0x48,
    PAUSE_MSG_BADGES                = 0x49,
    PAUSE_MSG_NOT_ENOUGH_BP         = 0x4A,
    PAUSE_MSG_DONT_WEAR_MORE        = 0x4B,
    PAUSE_MSG_BAGDE_DESC_ALL        = 0x4C,
    PAUSE_MSG_BAGDE_DESC_ACTIVE     = 0x4D,
    PAUSE_MSG_BAGDE_DESC_NONE       = 0x4E,
    PAUSE_MSG_KEY_ITEMS             = 0x4F,
    PAUSE_MSG_CONSUMABLES           = 0x50,
    PAUSE_MSG_DESC_CONSUMABLES      = 0x51,
    PAUSE_MSG_DESC_KEY_ITEMS        = 0x52,
    PAUSE_MSG_PARTNER_HP            = 0x53,
    PAUSE_MSG_PARTNER_FP            = 0x54,
    PAUSE_MSG_PARTNER_ABILITIES     = 0x55,
    PAUSE_MSG_UNKNOWN_SPIRIT        = 0x56,
};

#endif
