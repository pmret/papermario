#include "common.h"
#include "hud_element.h"
#include "message_ids.h"

#define LINE_HEIGHT 13

extern HudScript HES_HandPointer;
extern HudScript HES_StatusStarPiece;
extern HudScript HES_GreenArrowDown;
extern HudScript HES_GreenArrowUp;
extern HudScript HES_EmptyBar;
extern HudScript HES_PartnerRank1A;
extern HudScript HES_PartnerRank1B;
extern HudScript HES_PartnerRank2A;
extern HudScript HES_PartnerRank2B;

HudScript* D_80109890[] = { &HES_PartnerRank1A, &HES_PartnerRank2A };
HudScript* D_80109898[] = { &HES_PartnerRank1B, &HES_PartnerRank2B };

#if VERSION_JP
#define WINDOW_KEY_WIDTH        242
#define ALREADY_PARTNER_HEIGHT  32
#define EMPTY_BAR_X             67
#define DIARY_PAGE_X            0
#define PARTNER_LIST_X1         50
#define PARTNER_LIST_X2         66
#define BADGE_PRICE_X           108
#define ITEM_PRICE_X            106
#define MENU_OFFSET_Y1          9
#define MENU_OFFSET_Y2          7
#define POPUP_PARTNER_WIDTH     80
#else
#define WINDOW_KEY_WIDTH        280
#define ALREADY_PARTNER_HEIGHT  40
#define EMPTY_BAR_X             73
#define DIARY_PAGE_X            8
#define PARTNER_LIST_X1         85
#define PARTNER_LIST_X2         91
#define BADGE_PRICE_X           115
#define ITEM_PRICE_X            121
#define MENU_OFFSET_Y1          8
#define MENU_OFFSET_Y2          6
#define POPUP_PARTNER_WIDTH     100
#endif

#if !VERSION_JP
s16 PopupWorldStartX[] = {
    [POPUP_MENU_USE_ITEM]          140,
    [POPUP_MENU_SWITCH_PARTNER]    140,
    [POPUP_MENU_THROW_AWAY_ITEM]   141,
    [POPUP_MENU_TRADE_FOR_BADGE]   124,
    [POPUP_MENU_UPGRADE_PARTNER]   134,
    [POPUP_MENU_SELL_ITEM]         119,
    [POPUP_MENU_CHECK_ITEM]        141,
    [POPUP_MENU_CLAIM_ITEM]        141,
    [POPUP_MENU_READ_LETTER]       108,
    [POPUP_MENU_TAKE_FROM_CHEST]   141,
    [POPUP_MENU_READ_DIARY_PAGE]   132,
    [POPUP_MENU_READ_POSTCARD]     132,
    [POPUP_MENU_USEKEY]            141,
    [POPUP_MENU_POST_OFFICE]       140,
};

s16 PopupContentScissorWidths[] = {
    [POPUP_MENU_USE_ITEM]          137,
    [POPUP_MENU_SWITCH_PARTNER]    133,
    [POPUP_MENU_THROW_AWAY_ITEM]   137,
    [POPUP_MENU_TRADE_FOR_BADGE]   154,
    [POPUP_MENU_UPGRADE_PARTNER]   164,
    [POPUP_MENU_SELL_ITEM]         290,
    [POPUP_MENU_CHECK_ITEM]        137,
    [POPUP_MENU_CLAIM_ITEM]        137,
    [POPUP_MENU_READ_LETTER]       167,
    [POPUP_MENU_TAKE_FROM_CHEST]   137,
    [POPUP_MENU_READ_DIARY_PAGE]   137,
    [POPUP_MENU_READ_POSTCARD]     147,
    [POPUP_MENU_USEKEY]            137,
    [POPUP_MENU_POST_OFFICE]       137,
};
#endif

SHIFT_BSS s32 gPopupState;
SHIFT_BSS s32 D_8010D644;
SHIFT_BSS s32 PopupMenu_SelectedIndex;
SHIFT_BSS s32 PopupMenu_PrevSelectedIndex;
SHIFT_BSS s32 PopupMenu_Alpha;
SHIFT_BSS s8 PopupMenu_FirstDisplayIndex;
SHIFT_BSS s8 PopupMenu_LastDisplayIndex;
SHIFT_BSS s8 PopupMenu_DisplayedEntryCount;
SHIFT_BSS s16 D_8010D658;
SHIFT_BSS s16 D_8010D65A;
SHIFT_BSS s32 PopupMenu_EmptybarHEID;
SHIFT_BSS s32 PopupMenu_TitleIconHEID;
SHIFT_BSS s32 PopupMenu_TimesHEID;
SHIFT_BSS s32 PopupMenu_PartnerLevelHEID;
SHIFT_BSS s32 PopupMenu_CursorHEID;
SHIFT_BSS s32 PopupMenu_UpArrowHEID;
SHIFT_BSS s32 PopupMenu_DownArrowHEID;
SHIFT_BSS s32 PopupMenu_EntryIconHEID;
SHIFT_BSS s16 D_8010D67C;
SHIFT_BSS s16 D_8010D67E;
SHIFT_BSS s16 D_8010D680;
SHIFT_BSS s16 D_8010D682;
SHIFT_BSS s16 D_8010D684;
SHIFT_BSS s16 D_8010D686;
SHIFT_BSS s16 PopupMenu_StarPieceCounterPosX;
SHIFT_BSS s16 PopupMenu_StarPieceCounterPosY;
SHIFT_BSS s16 D_8010D68C;
SHIFT_BSS s8 PopupNotBattle;
SHIFT_BSS s8 PopupMenu_MaxDisplayableEntryCount;
SHIFT_BSS s8 D_8010D690;
SHIFT_BSS s8 D_8010D691;
SHIFT_BSS s8 D_8010D692;
SHIFT_BSS s8 D_8010D693;
SHIFT_BSS s32 gPopupWorker;
SHIFT_BSS s8 PopupNotDipping;
SHIFT_BSS s8 PopupDipMode;
SHIFT_BSS s8 PopupMenu_WasStatusBarIgnoringChanges;
SHIFT_BSS PopupMenu* gPopupMenu;
SHIFT_BSS MessagePrintState* D_8010D6A0;
SHIFT_BSS s32 D_8010D6A4;

s8 status_bar_is_ignoring_changes(void);

enum PopupTypes {
    POPUP_TYPE_USE_ITEM,
    POPUP_TYPE_SWITCH_PARTNER,
    POPUP_TYPE_THROW_AWAY_ITEM,
    POPUP_TYPE_TRADE_FOR_BADGE,
    POPUP_TYPE_UPGRADE_PARTNER,
    POPUP_TYPE_SELL_ITEM,
    POPUP_TYPE_CHECK_ITEM,
    POPUP_TYPE_CLAIM_ITEM,
    POPUP_TYPE_READ_LETTER,
    POPUP_TYPE_TAKE_FROM_CHEST,
    POPUP_TYPE_READ_DIARY_PAGE,
    POPUP_TYPE_READ_POSTCARD,
    POPUP_TYPE_USE_KEY,
};

void popup_menu_draw_menu_contents(s32* userData, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void popup_menu_draw_title_contents(s32* userData, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void func_800F48F4(s32* userData, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void func_800F4944(s32* userData, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void func_800F4C1C(s32* userData, s32 x, s32 y);
void popup_draw_cost_icon(s32* userData, s32 x, s32 y);
void popup_draw_already_have_partner(s32* userData, s32 x, s32 y);
void func_800F4D28(s32* userData, s32 x, s32 y);

void hide_popup_menu(void) {
    if (PopupNotBattle) {
        switch (gPopupMenu->popupType) {
            case POPUP_MENU_USE_ITEM:
            case POPUP_MENU_SWITCH_PARTNER:
            case POPUP_MENU_THROW_AWAY_ITEM:
            case POPUP_MENU_TRADE_FOR_BADGE:
            case POPUP_MENU_UPGRADE_PARTNER:
            case POPUP_MENU_SELL_ITEM:
            case POPUP_MENU_CHECK_ITEM:
            case POPUP_MENU_CLAIM_ITEM:
            case POPUP_MENU_READ_LETTER:
            case POPUP_MENU_TAKE_FROM_CHEST:
            case POPUP_MENU_USEKEY:
                set_window_update(WINDOW_ID_14, (s32) basic_hidden_window_update);
                set_window_update(WINDOW_ID_19, (s32) basic_hidden_window_update);
                break;
            case POPUP_MENU_READ_DIARY_PAGE:
            case POPUP_MENU_READ_POSTCARD:
            case POPUP_MENU_POST_OFFICE:
                set_window_update(WINDOW_ID_14, (s32) basic_hidden_window_update);
                break;
        }
        set_window_update(WINDOW_ID_21, WINDOW_UPDATE_HIDE);
    } else {
        switch (gPopupMenu->popupType) {
            case POPUP_MENU_USE_ITEM:
            case POPUP_MENU_SWITCH_PARTNER:
            case POPUP_MENU_THROW_AWAY_ITEM:
            case POPUP_MENU_TRADE_FOR_BADGE:
            case POPUP_MENU_UPGRADE_PARTNER:
            case POPUP_MENU_SELL_ITEM:
            case POPUP_MENU_CHECK_ITEM:
            case POPUP_MENU_CLAIM_ITEM:
            case POPUP_MENU_READ_LETTER:
            case POPUP_MENU_TAKE_FROM_CHEST:
            case POPUP_MENU_USEKEY:
                set_window_update(WINDOW_ID_14, WINDOW_UPDATE_HIDE);
                set_window_update(WINDOW_ID_19, WINDOW_UPDATE_HIDE);
                break;
            case POPUP_MENU_READ_DIARY_PAGE:
            case POPUP_MENU_READ_POSTCARD:
            case POPUP_MENU_POST_OFFICE:
                set_window_update(WINDOW_ID_14, WINDOW_UPDATE_HIDE);
                break;
        }
    }

    if (gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE) {
        set_window_update(WINDOW_ID_16, (s32) basic_hidden_window_update);
        set_window_update(WINDOW_ID_CURRENCY_COUNTER, (s32) basic_hidden_window_update);
    }
    if (gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
        set_window_update(WINDOW_ID_18, (s32) basic_hidden_window_update);
    }
    if (gPopupMenu->popupType == POPUP_MENU_SELL_ITEM) {
        set_window_update(WINDOW_ID_16, (s32) basic_hidden_window_update);
        set_window_update(WINDOW_ID_CURRENCY_COUNTER, (s32) basic_hidden_window_update);
    }
    gPopupState = POPUP_STATE_10;
    D_8010D644 = D_8010D692;
}

void destroy_popup_menu(void) {
    hud_element_free(PopupMenu_EmptybarHEID);
    hud_element_free(PopupMenu_EntryIconHEID);
    hud_element_free(PopupMenu_CursorHEID);
    hud_element_free(PopupMenu_UpArrowHEID);
    hud_element_free(PopupMenu_DownArrowHEID);

    if (gPopupMenu->popupType == POPUP_TYPE_TRADE_FOR_BADGE) {
        hud_element_free(PopupMenu_TitleIconHEID);
        hud_element_free(PopupMenu_TimesHEID);
    }

    if (gPopupMenu->popupType == POPUP_TYPE_UPGRADE_PARTNER) {
        hud_element_free(PopupMenu_TitleIconHEID);
        hud_element_free(PopupMenu_TimesHEID);
    }

    if (gPopupMenu->popupType == POPUP_TYPE_SWITCH_PARTNER || gPopupMenu->popupType == POPUP_TYPE_UPGRADE_PARTNER) {
        hud_element_free(PopupMenu_PartnerLevelHEID);
    }

    if (gPopupMenu->popupType == POPUP_TYPE_SELL_ITEM) {
        hud_element_free(PopupMenu_TitleIconHEID);
    }

    if ((gPopupMenu->popupType <= POPUP_TYPE_USE_ITEM ||
         gPopupMenu->popupType == POPUP_TYPE_SWITCH_PARTNER ||
         gPopupMenu->popupType == POPUP_TYPE_THROW_AWAY_ITEM ||
         gPopupMenu->popupType == POPUP_TYPE_TRADE_FOR_BADGE ||
         gPopupMenu->popupType == POPUP_TYPE_UPGRADE_PARTNER ||
         gPopupMenu->popupType == POPUP_TYPE_USE_KEY
        ) && !gGameStatusPtr->isBattle) {
        if (!PopupMenu_WasStatusBarIgnoringChanges) {
            status_bar_respond_to_changes();
        }
        close_status_bar();
    }

    gPopupState = POPUP_STATE_MINUS_4;
}

void func_800F16CC(void) {
    if (PopupNotBattle) {
        switch (gPopupMenu->popupType) {
            case POPUP_MENU_USE_ITEM:
            case POPUP_MENU_THROW_AWAY_ITEM:
            case POPUP_MENU_TRADE_FOR_BADGE:
            case POPUP_MENU_SELL_ITEM:
            case POPUP_MENU_CHECK_ITEM:
            case POPUP_MENU_CLAIM_ITEM:
            case POPUP_MENU_READ_LETTER:
            case POPUP_MENU_TAKE_FROM_CHEST:
            case POPUP_MENU_USEKEY:
                set_window_update(WINDOW_ID_14, (s32) basic_window_update);
                sfx_play_sound(SOUND_OPEN_POPUP_1);
                set_window_update(WINDOW_ID_19, (s32) basic_window_update);
                break;
            case POPUP_MENU_SWITCH_PARTNER:
            case POPUP_MENU_UPGRADE_PARTNER:
                set_window_update(WINDOW_ID_14, (s32) basic_window_update);
                sfx_play_sound(SOUND_OPEN_POPUP_2);
                set_window_update(WINDOW_ID_19, (s32) basic_window_update);
                break;
            case POPUP_MENU_READ_DIARY_PAGE:
            case POPUP_MENU_READ_POSTCARD:
            case POPUP_MENU_POST_OFFICE:
                set_window_update(WINDOW_ID_14, (s32) basic_window_update);
                sfx_play_sound(SOUND_OPEN_POPUP_1);
                break;
        }
        set_window_update(WINDOW_ID_21, (s32) basic_window_update);
    } else {
        switch (gPopupMenu->popupType) {
            case POPUP_MENU_USE_ITEM:
            case POPUP_MENU_THROW_AWAY_ITEM:
            case POPUP_MENU_TRADE_FOR_BADGE:
            case POPUP_MENU_SELL_ITEM:
            case POPUP_MENU_CHECK_ITEM:
            case POPUP_MENU_CLAIM_ITEM:
            case POPUP_MENU_READ_LETTER:
            case POPUP_MENU_TAKE_FROM_CHEST:
            case POPUP_MENU_USEKEY:
                set_window_update(WINDOW_ID_14, WINDOW_UPDATE_SHOW);
                set_window_update(WINDOW_ID_19, WINDOW_UPDATE_SHOW);
                break;
            case POPUP_MENU_SWITCH_PARTNER:
            case POPUP_MENU_UPGRADE_PARTNER:
                set_window_update(WINDOW_ID_14, WINDOW_UPDATE_SHOW);
                set_window_update(WINDOW_ID_19, WINDOW_UPDATE_SHOW);
                break;
            case POPUP_MENU_READ_DIARY_PAGE:
            case POPUP_MENU_READ_POSTCARD:
            case POPUP_MENU_POST_OFFICE:
                set_window_update(WINDOW_ID_14, WINDOW_UPDATE_SHOW);
                break;
        }
    }

    if (gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE) {
        set_window_update(WINDOW_ID_16, (s32) basic_window_update);
        set_window_update(WINDOW_ID_CURRENCY_COUNTER, (s32) basic_window_update);
    }
    if (gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
        set_window_update(WINDOW_ID_18, (s32) basic_window_update);
    }
    if (gPopupMenu->popupType == POPUP_MENU_SELL_ITEM) {
        set_window_update(WINDOW_ID_16, (s32) basic_window_update);
    }
    hud_element_set_tint(PopupMenu_EmptybarHEID, 255, 255, 255);
    hud_element_set_tint(PopupMenu_EntryIconHEID, 255, 255, 255);
    hud_element_set_tint(PopupMenu_CursorHEID, 255, 255, 255);
    hud_element_set_tint(PopupMenu_UpArrowHEID, 255, 255, 255);
    hud_element_set_tint(PopupMenu_DownArrowHEID, 255, 255, 255);

    if (gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE) {
        hud_element_set_tint(PopupMenu_TitleIconHEID, 255, 255, 255);
        hud_element_set_tint(PopupMenu_TimesHEID, 255, 255, 255);
    }
    if (gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
        hud_element_set_tint(PopupMenu_TitleIconHEID, 255, 255, 255);
        hud_element_set_tint(PopupMenu_TimesHEID, 255, 255, 255);
    }
    if (gPopupMenu->popupType == POPUP_MENU_SWITCH_PARTNER || gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
        hud_element_set_tint(PopupMenu_PartnerLevelHEID, 255, 255, 255);
    }
    if (gPopupMenu->popupType == POPUP_MENU_SELL_ITEM) {
        hud_element_set_tint(PopupMenu_TitleIconHEID, 255, 255, 255);
    }
    hud_element_set_script(PopupMenu_CursorHEID, &HES_AnimatedHandPointer);
    D_8010D690 = MSG_PAL_STANDARD;
    gPopupState = POPUP_STATE_20;
}

#if VERSION_PAL
s32 popup_menu_update(void);
INCLUDE_ASM(s32, "8a860_len_3f30", popup_menu_update);
#else
s32 popup_menu_update(void) {
    s32 posX;
    s32 posY;
    s32 width;
    s32 height;
    s32 elementID;
    s32 cond;
    s32 buttons;
    s32 msgID;
    s32 one;
    s32 i;

    s32 var_s5 = 0;
    s32 var_s6 = 0; // maybe 6 before 5
    s32 msgWidth;
    s32 width2;
    s32 posX2;

    switch (gPopupState) {
        case POPUP_STATE_INIT:
#if VERSION_JP
            D_8010D67C = 32;
            D_8010D67E = 72;
            D_8010D680 = 32;
            PopupMenu_StarPieceCounterPosX = 32;
#else
            D_8010D67C = 20;
            D_8010D67E = 72;
            D_8010D680 = 20;
#endif
            D_8010D682 = 186;
            D_8010D684 = 16;
            D_8010D686 = 88;
#if !VERSION_JP
            PopupMenu_StarPieceCounterPosX = 32;
#endif
            PopupMenu_StarPieceCounterPosY = 164;
            if (PopupNotBattle) {
#if VERSION_JP

                switch (gPopupMenu->popupType) {
                    case POPUP_MENU_USE_ITEM:
                    case POPUP_MENU_THROW_AWAY_ITEM:
                    case POPUP_MENU_CHECK_ITEM:
                    case POPUP_MENU_CLAIM_ITEM:
                    case POPUP_MENU_READ_LETTER:
                    case POPUP_MENU_TAKE_FROM_CHEST:
                    case POPUP_MENU_USEKEY:
                        D_8010D67C += 144;
                        break;
                    case POPUP_MENU_TRADE_FOR_BADGE:
                        D_8010D67C += 122;
                        break;
                    case POPUP_MENU_UPGRADE_PARTNER:
                        D_8010D67C += 134;
                        break;
                    case POPUP_MENU_SELL_ITEM:
                        D_8010D67C += 122;
                        break;
                    case POPUP_MENU_SWITCH_PARTNER:
                    case POPUP_MENU_READ_DIARY_PAGE:
                    case POPUP_MENU_READ_POSTCARD:
                    case POPUP_MENU_POST_OFFICE:
                        D_8010D67C += 160;
                        break;
                }
#else
                D_8010D67C = PopupWorldStartX[gPopupMenu->popupType] + 20;
#endif
            }
            if (PopupMenu_MaxDisplayableEntryCount >= 7) {
#if VERSION_JP
                D_8010D67E -= 10;
#else
                D_8010D67E = 62;
#endif
            }
            D_8010D68C = 0;
            elementID = hud_element_create(&HES_EmptyBar);
            PopupMenu_EmptybarHEID = elementID;
            hud_element_set_flags(elementID, HUD_ELEMENT_FLAG_80);
            hud_element_set_tint(elementID, 255, 255, 255);
            if (gPopupMenu->popupType != POPUP_MENU_THROW_AWAY_ITEM) {
                hud_element_set_flags(elementID, HUD_ELEMENT_FLAG_DISABLED);
            }

            one = POPUP_MENU_SWITCH_PARTNER; // required to match (why is 1 loaded so early?)
            elementID = hud_element_create(gPopupMenu->ptrIcon[0]);
            PopupMenu_EntryIconHEID = elementID;
            hud_element_set_scale(elementID, 0.45f);
            hud_element_set_flags(elementID, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);

            elementID = hud_element_create(&HES_AnimatedHandPointer);
            PopupMenu_CursorHEID = elementID;
            hud_element_set_flags(elementID, HUD_ELEMENT_FLAG_DROP_SHADOW | HUD_ELEMENT_FLAG_80);

            elementID = hud_element_create(&HES_GreenArrowUp);
            PopupMenu_UpArrowHEID = elementID;
            hud_element_set_flags(elementID, HUD_ELEMENT_FLAG_DROP_SHADOW | HUD_ELEMENT_FLAG_80);

            elementID = hud_element_create(&HES_GreenArrowDown);
            PopupMenu_DownArrowHEID = elementID;
            hud_element_set_flags(elementID, HUD_ELEMENT_FLAG_DROP_SHADOW | HUD_ELEMENT_FLAG_80);

            if (gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE) {
                PopupMenu_TitleIconHEID = hud_element_create(&HES_StatusStarPiece);
                elementID = PopupMenu_TitleIconHEID;
                hud_element_set_flags(elementID, HUD_ELEMENT_FLAG_80);
                hud_element_set_tint(elementID, 255, 255, 255);
            }
            if (gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
                PopupMenu_TitleIconHEID = hud_element_create(&HES_StatusStarPiece);
                elementID = PopupMenu_TitleIconHEID;
                hud_element_set_flags(elementID, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                hud_element_set_tint(elementID, 255, 255, 255);
            }
            if (gPopupMenu->popupType == POPUP_MENU_SELL_ITEM) {
                PopupMenu_TitleIconHEID = hud_element_create(&HES_StatusCoin);
                elementID = PopupMenu_TitleIconHEID;
                hud_element_set_flags(elementID, HUD_ELEMENT_FLAG_80);
                hud_element_set_tint(elementID, 255, 255, 255);
            }
            if (gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE || gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
                PopupMenu_TimesHEID = hud_element_create(&HES_MenuTimes);
                elementID = PopupMenu_TimesHEID;
                hud_element_set_flags(elementID, HUD_ELEMENT_FLAG_80);
                hud_element_set_tint(elementID, 255, 255, 255);
            }
            if (gPopupMenu->popupType == one || gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
                PopupMenu_PartnerLevelHEID = hud_element_create(D_80109890[0]);
                elementID = PopupMenu_PartnerLevelHEID;
                hud_element_set_flags(elementID, HUD_ELEMENT_FLAG_80);
                hud_element_set_tint(elementID, 255, 255, 255);
            }

            D_8010D65A = -200;
            D_8010D644 = D_8010D691;
            if (!PopupNotBattle) {
                D_8010D644 = 1;
            }
            D_8010D690 = MSG_PAL_STANDARD;

            posX = D_8010D67C;
            posY = D_8010D67E;

#if VERSION_PAL
            gPopupMenu->unk_338 = 0;
            gPopupMenu->unk_340 = 0;

            switch (gPopupMenu->popupType) {
                case POPUP_MENU_USE_ITEM:
                    gPopupMenu->unk_33C = MSG_Menus_0061;
                    switch (gPopupMenu->dipMode) {
                        case 0:
                            gPopupMenu->unk_330 = MSG_Menus_Items;
                            break;
                        case 1:
                            gPopupMenu->unk_330 = MSG_Menus_DoubleDip;
                            break;
                        case 2:
                            gPopupMenu->unk_330 = MSG_Menus_TripleDip;
                            break;
                    }
                case POPUP_MENU_THROW_AWAY_ITEM:
                    gPopupMenu->unk_330 = MSG_Menus_Items;
                    gPopupMenu->unk_33C = MSG_Menus_0064;
                case POPUP_MENU_CHECK_ITEM:
                    gPopupMenu->unk_330 = MSG_Menus_Items;
                    gPopupMenu->unk_33C = MSG_Menus_0066;
                case POPUP_MENU_CLAIM_ITEM:
                    gPopupMenu->unk_330 = MSG_Menus_Items;
                    gPopupMenu->unk_33C = MSG_Menus_0067;
                case POPUP_MENU_USEKEY:
                    var_s6 = 145;
                    var_s5 = 145;
                    gPopupMenu->unk_33C = MSG_Menus_0062;
                    gPopupMenu->unk_330 = MSG_Menus_Items;
                    break;
                case POPUP_MENU_SWITCH_PARTNER:
                    var_s6 = 139;
                    var_s5 = 139;
                    gPopupMenu->unk_330 = MSG_Menus_PartyMember;
                    gPopupMenu->unk_338 = 1;
                    gPopupMenu->unk_33C = MSG_Menus_0063;
                    break;
                case POPUP_MENU_TRADE_FOR_BADGE:
                    var_s6 = 162;
                    var_s5 = 140;
                    gPopupMenu->unk_340 = -16;
                    gPopupMenu->unk_330 = MSG_MenuTip_0032;
                    gPopupMenu->unk_33C = MSG_Menus_0070;
                    break;
                case POPUP_MENU_UPGRADE_PARTNER:
                    var_s6 = 146;
                    var_s5 = 140;
                    gPopupMenu->unk_340 = -8;
                    gPopupMenu->unk_330 = MSG_Menus_PartyMember;
                    gPopupMenu->unk_338 = 1;
                    gPopupMenu->unk_33C = MSG_Menus_006A;
                    break;
                case POPUP_MENU_SELL_ITEM:
                    var_s6 = 167;
                    var_s5 = 145;
                    gPopupMenu->unk_340 = -24;
                    gPopupMenu->unk_330 = MSG_Menus_Items;
                    gPopupMenu->unk_33C = MSG_Menus_0065;
                    break;
                case POPUP_MENU_READ_LETTER:
                    var_s6 = 170;
                    var_s5 = 170;
                    gPopupMenu->unk_340 = -32;
                    gPopupMenu->unk_330 = MSG_MenuTip_0033;
                    gPopupMenu->unk_33C = MSG_Menus_006D;
                    break;
                case POPUP_MENU_TAKE_FROM_CHEST:
                    var_s6 = 145;
                    var_s5 = 145;
                    gPopupMenu->unk_330 = MSG_Menus_00D7;
                    gPopupMenu->unk_33C = MSG_Menus_00D6;
                    break;
                case POPUP_MENU_READ_DIARY_PAGE:
                    var_s6 = 140;
                    var_s5 = 140;
                    gPopupMenu->unk_340 = -16;
                    gPopupMenu->unk_330 = MSG_Menus_00CE;
                    gPopupMenu->unk_33C = MSG_Menus_006C;
                    break;
                case POPUP_MENU_READ_POSTCARD:
                    var_s6 = 149;
                    var_s5 = 149;
                    gPopupMenu->unk_340 = -16;
                    gPopupMenu->unk_330 = MSG_Menus_00D0;
                    gPopupMenu->unk_33C = MSG_Menus_006D;
                    break;
                case POPUP_MENU_POST_OFFICE:
                    var_s6 = 131;
                    var_s5 = 131;
                    gPopupMenu->unk_330 = MSG_Menus_PartyMember;
                    gPopupMenu->unk_338 = 1;
                    gPopupMenu->unk_33C = MSG_Menus_006F;
                    break;
            }
            msgWidth = get_msg_width(gPopupMenu->unk_330, 0);
            width2 = msgWidth + (((var_s5 - msgWidth) * 2) / 5);
            posX2 = (var_s5 - width2) / 2;
            gPopupMenu->unk_334 = (width2 - msgWidth) / 2;
            if (gPopupMenu->popupType == POPUP_MENU_USE_ITEM && gPopupMenu->dipMode != 0) {
                width2 = 125;
                posX2 = (var_s5 - width2) / 2;
                gPopupMenu->unk_334 = (80 - msgWidth) / 2;
            }
            set_window_properties(WINDOW_ID_14, posX, posY, var_s6, (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 26,
                                  WINDOW_PRIORITY_20, popup_menu_draw_menu_contents, NULL, -1);
            if (gPopupMenu->unk_338 == 0) {
                set_window_properties(WINDOW_ID_15, posX2, -6, width2, 16, WINDOW_PRIORITY_21,
                                      popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                set_window_update(WINDOW_ID_15, 1);
                set_window_update(WINDOW_ID_17, 2);
            } else {
                set_window_properties(WINDOW_ID_17, posX2, -6, width2, 16, WINDOW_PRIORITY_21,
                                      popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                set_window_update(WINDOW_ID_15, 2);
                set_window_update(WINDOW_ID_17, 1);
            }
#elif VERSION_JP
            switch (gPopupMenu->popupType) {
                case POPUP_MENU_USE_ITEM:
                case POPUP_MENU_THROW_AWAY_ITEM:
                case POPUP_MENU_CHECK_ITEM:
                case POPUP_MENU_CLAIM_ITEM:
                case POPUP_MENU_TAKE_FROM_CHEST:
                case POPUP_MENU_USEKEY:
                    set_window_properties(WINDOW_ID_14, posX, posY, 130, (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 26, WINDOW_PRIORITY_20, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_15, 12, -6, 106, 16, WINDOW_PRIORITY_21, popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_SWITCH_PARTNER:
                    set_window_properties(WINDOW_ID_14, posX, posY, 104, (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 26, WINDOW_PRIORITY_20, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_17, 14, -6, 72, 16, WINDOW_PRIORITY_21, popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_HIDE);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_SHOW);
                    break;
                case POPUP_MENU_TRADE_FOR_BADGE:
                    set_window_properties(WINDOW_ID_14, posX, posY, 152, (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 26, WINDOW_PRIORITY_20, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_15, 12, -6, 106, 16, WINDOW_PRIORITY_21, popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_UPGRADE_PARTNER:
                    set_window_properties(WINDOW_ID_14, posX, posY, 126, (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 26, WINDOW_PRIORITY_20, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_17, 12, -6, 66, 16, WINDOW_PRIORITY_21, popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_HIDE);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_SHOW);
                    break;
                case POPUP_MENU_SELL_ITEM:
                    set_window_properties(WINDOW_ID_14, posX, posY, 152, (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 26, WINDOW_PRIORITY_20, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_15, 12, -6, 106, 16, WINDOW_PRIORITY_21, popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_READ_LETTER:
                    set_window_properties(WINDOW_ID_14, posX, posY, 120, (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 26, WINDOW_PRIORITY_20, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_15, 24, -6, 72, 16, WINDOW_PRIORITY_21, popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_READ_DIARY_PAGE:
                    set_window_properties(WINDOW_ID_14, posX, posY, 108, (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 26, WINDOW_PRIORITY_20, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_15, 12, -6, 84, 16, WINDOW_PRIORITY_21, popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_READ_POSTCARD:
                    set_window_properties(WINDOW_ID_14, posX, posY, 124, (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 26, WINDOW_PRIORITY_20, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_15, 12, -6, 100, 16, WINDOW_PRIORITY_21, popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_POST_OFFICE:
                    set_window_properties(WINDOW_ID_14, posX, posY, 96, (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 26, WINDOW_PRIORITY_20, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_17, 10, -6, 72, 16, WINDOW_PRIORITY_21, popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_HIDE);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_SHOW);
                    break;
            }
#else
            switch (gPopupMenu->popupType) {
                case POPUP_MENU_USE_ITEM:
                case POPUP_MENU_THROW_AWAY_ITEM:
                case POPUP_MENU_CHECK_ITEM:
                case POPUP_MENU_CLAIM_ITEM:
                case POPUP_MENU_USEKEY:
                    set_window_properties(WINDOW_ID_14, posX, posY, 145, (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 26, WINDOW_PRIORITY_20, popup_menu_draw_menu_contents, NULL, -1);
                    if (gPopupMenu->dipMode == 0) {
                        set_window_properties(WINDOW_ID_15, 25, -6, 95, 16, WINDOW_PRIORITY_21, popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                    } else {
                        set_window_properties(WINDOW_ID_15, 12, -6, 121, 16, WINDOW_PRIORITY_21, popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                    }
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_SWITCH_PARTNER:
                    set_window_properties(WINDOW_ID_14, posX, posY, 139, (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 26, WINDOW_PRIORITY_20, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_17, 13, -6, 114, 16, WINDOW_PRIORITY_21, popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_HIDE);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_SHOW);
                    break;
                case POPUP_MENU_TRADE_FOR_BADGE:
                    set_window_properties(WINDOW_ID_14, posX, posY, 162, (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 26, WINDOW_PRIORITY_20, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_15, 17, -6, 96, 16, WINDOW_PRIORITY_21, popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_UPGRADE_PARTNER:
                    set_window_properties(WINDOW_ID_14, posX, posY, 146, (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 26, WINDOW_PRIORITY_20, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_17, 12, -6, 114, 16, WINDOW_PRIORITY_21, popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_HIDE);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_SHOW);
                    break;
                case POPUP_MENU_SELL_ITEM:
                    set_window_properties(WINDOW_ID_14, posX, posY, 167, (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 26, WINDOW_PRIORITY_20, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_15, 22, -6, 95, 16, WINDOW_PRIORITY_21, popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_READ_LETTER:
                    set_window_properties(WINDOW_ID_14, posX, posY, 170, (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 26, WINDOW_PRIORITY_20, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_15, 32, -6, 104, 16, WINDOW_PRIORITY_21, popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_TAKE_FROM_CHEST:
                    set_window_properties(WINDOW_ID_14, posX, posY, 145, (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 26, WINDOW_PRIORITY_20, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_15, 12, -6, 121, 16, WINDOW_PRIORITY_21, popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_READ_DIARY_PAGE:
                    set_window_properties(WINDOW_ID_14, posX, posY, 128, (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 26, WINDOW_PRIORITY_20, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_15, 12, -6, 104, 16, WINDOW_PRIORITY_21, popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_READ_POSTCARD:
                    set_window_properties(WINDOW_ID_14, posX, posY, 149, (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 26, WINDOW_PRIORITY_20, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_15, 6, -6, 139, 16, WINDOW_PRIORITY_21, popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_POST_OFFICE:
                    set_window_properties(WINDOW_ID_14, posX, posY, 131, (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 26, WINDOW_PRIORITY_20, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_17, 10, -6, 114, 16, WINDOW_PRIORITY_21, popup_menu_draw_title_contents, NULL, WINDOW_ID_14);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_HIDE);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_SHOW);
                    break;
            }
#endif

#if VERSION_JP
            switch (gPopupMenu->popupType) {
                case POPUP_MENU_UPGRADE_PARTNER:
                    set_window_properties(WINDOW_ID_18, 84, -6, 40, 16, WINDOW_PRIORITY_21, popup_draw_cost_icon, NULL, WINDOW_ID_14);
                    break;
                case POPUP_MENU_TRADE_FOR_BADGE:
                    set_window_properties(WINDOW_ID_16, 116, -14, 32, 32, WINDOW_PRIORITY_21, popup_draw_cost_icon, NULL, WINDOW_ID_14);
                    break;
                case POPUP_MENU_SELL_ITEM:
                    set_window_properties(WINDOW_ID_16, 116, -14, 32, 32, WINDOW_PRIORITY_21, popup_draw_cost_icon, NULL, WINDOW_ID_14);
                    break;
            }
#else
            switch (gPopupMenu->popupType) {
                case POPUP_MENU_TRADE_FOR_BADGE:
                    set_window_properties(WINDOW_ID_16, 126, -14, 32, 32, WINDOW_PRIORITY_21, popup_draw_cost_icon, NULL, WINDOW_ID_14);
                    break;
                case POPUP_MENU_SELL_ITEM:
                    set_window_properties(WINDOW_ID_16, 131, -14, 32, 32, WINDOW_PRIORITY_21, popup_draw_cost_icon, NULL, WINDOW_ID_14);
                    break;
            }
#endif

            if (gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE) {
                posX = PopupMenu_StarPieceCounterPosX;
                posY = PopupMenu_StarPieceCounterPosY;
                set_window_properties(WINDOW_ID_CURRENCY_COUNTER, posX, posY, 64, 20, WINDOW_PRIORITY_21, func_800F4D28, NULL, -1);
            }

            do {
                cond = FALSE;
                if (PopupMenu_SelectedIndex >= PopupMenu_FirstDisplayIndex + PopupMenu_LastDisplayIndex - 1) {
                    PopupMenu_FirstDisplayIndex++;
                    if (PopupMenu_FirstDisplayIndex > gPopupMenu->numEntries - PopupMenu_MaxDisplayableEntryCount) {
                        PopupMenu_FirstDisplayIndex = gPopupMenu->numEntries - PopupMenu_MaxDisplayableEntryCount;
                        if (PopupMenu_FirstDisplayIndex < 0) {
                            PopupMenu_FirstDisplayIndex = 0;
                        }
                    } else {
                        cond = TRUE;
                    }
                }
            } while (cond);

            PopupMenu_LastDisplayIndex = PopupMenu_FirstDisplayIndex + PopupMenu_MaxDisplayableEntryCount;
            D_8010D658 = -PopupMenu_FirstDisplayIndex * LINE_HEIGHT;
            if (gPopupMenu->popupType >= POPUP_MENU_USE_ITEM
                && (gPopupMenu->popupType < POPUP_MENU_READ_DIARY_PAGE || gPopupMenu->popupType == POPUP_MENU_USEKEY))
            {
                posX = D_8010D680;
                posY = D_8010D682;
                set_window_properties(WINDOW_ID_19, posX, posY, WINDOW_KEY_WIDTH, 32, WINDOW_PRIORITY_20, func_800F48F4, NULL, -1);
            }

            posX = D_8010D684;
            posY = D_8010D686;

#if VERSION_PAL
            height = 32;
            if (get_msg_lines(gPopupMenu->unk_33C) == 2) {
                height = 40;
            }
            set_window_properties(WINDOW_ID_21, posX, posY, gPopupMenu->unk_340 + 144, height, WINDOW_PRIORITY_20, func_800F4944, NULL, -1);
#else
            switch (gPopupMenu->popupType) {
#if VERSION_JP
                case POPUP_MENU_USE_ITEM:
                case POPUP_MENU_SWITCH_PARTNER:
                case POPUP_MENU_THROW_AWAY_ITEM:
                case POPUP_MENU_CHECK_ITEM:
                case POPUP_MENU_CLAIM_ITEM:
                case POPUP_MENU_READ_LETTER:
                case POPUP_MENU_TAKE_FROM_CHEST:
                case POPUP_MENU_READ_DIARY_PAGE:
                case POPUP_MENU_READ_POSTCARD:
                case POPUP_MENU_USEKEY:
                case POPUP_MENU_POST_OFFICE:
                    switch (gPopupMenu->dipMode) {
                        case 0:
                            set_window_properties(WINDOW_ID_21, D_8010D684, D_8010D686, 152, 32, WINDOW_PRIORITY_20, func_800F4944, NULL, -1);
                            break;
                        case 1:
                            set_window_properties(WINDOW_ID_21, D_8010D684, D_8010D686, 152, 32, WINDOW_PRIORITY_20, func_800F4944, NULL, -1);
                            break;
                        case 2:
                            set_window_properties(WINDOW_ID_21, D_8010D684, D_8010D686, 152, 32, WINDOW_PRIORITY_20, func_800F4944, NULL, -1);
                            break;
                    }
                    break;
                case POPUP_MENU_TRADE_FOR_BADGE:
                    set_window_properties(WINDOW_ID_21, D_8010D684, D_8010D686, 136, 32, WINDOW_PRIORITY_20, func_800F4944, NULL, -1);
                    break;
                case POPUP_MENU_UPGRADE_PARTNER:
                    set_window_properties(WINDOW_ID_21, D_8010D684, D_8010D686, 136, 48, WINDOW_PRIORITY_20, func_800F4944, NULL, -1);
                    break;
                case POPUP_MENU_SELL_ITEM:
                    set_window_properties(WINDOW_ID_21, D_8010D684, D_8010D686, 120, 32, WINDOW_PRIORITY_20, func_800F4944, NULL, -1);
                    break;
#else
                case POPUP_MENU_USE_ITEM:
                case POPUP_MENU_CHECK_ITEM:
                case POPUP_MENU_CLAIM_ITEM:
                case POPUP_MENU_TAKE_FROM_CHEST:
                case POPUP_MENU_USEKEY:
                    set_window_properties(WINDOW_ID_21, posX, posY, 144, 32, WINDOW_PRIORITY_20, func_800F4944, NULL, -1);
                    break;
                case POPUP_MENU_SWITCH_PARTNER:
                case POPUP_MENU_THROW_AWAY_ITEM:
                case POPUP_MENU_POST_OFFICE:
                    set_window_properties(WINDOW_ID_21, posX, posY, 144, 40, WINDOW_PRIORITY_20, func_800F4944, NULL, -1);
                    break;
                case POPUP_MENU_TRADE_FOR_BADGE:
                case POPUP_MENU_READ_DIARY_PAGE:
                case POPUP_MENU_READ_POSTCARD:
                    set_window_properties(WINDOW_ID_21, posX, posY, 128, 40, WINDOW_PRIORITY_20, func_800F4944, NULL, -1);
                    break;
                case POPUP_MENU_UPGRADE_PARTNER:
                    set_window_properties(WINDOW_ID_21, posX, posY, 136, 40, WINDOW_PRIORITY_20, func_800F4944, NULL, -1);
                    break;
                case POPUP_MENU_READ_LETTER:
                    set_window_properties(WINDOW_ID_21, posX, posY, 112, 40, WINDOW_PRIORITY_20, func_800F4944, NULL, -1);
                    break;
                case POPUP_MENU_SELL_ITEM:
                    set_window_properties(WINDOW_ID_21, posX, posY, 120, 32, WINDOW_PRIORITY_20, func_800F4944, NULL, -1);
                    break;
#endif
            }
#endif

            if (!PopupNotBattle) {
                switch (gPopupMenu->popupType) {
                    case POPUP_MENU_USE_ITEM:
                    case POPUP_MENU_THROW_AWAY_ITEM:
                    case POPUP_MENU_TRADE_FOR_BADGE:
                    case POPUP_MENU_SELL_ITEM:
                    case POPUP_MENU_CHECK_ITEM:
                    case POPUP_MENU_CLAIM_ITEM:
                    case POPUP_MENU_READ_LETTER:
                    case POPUP_MENU_TAKE_FROM_CHEST:
                    case POPUP_MENU_USEKEY:
                        set_window_update(WINDOW_ID_14, WINDOW_UPDATE_SHOW);
                        set_window_update(WINDOW_ID_19, WINDOW_UPDATE_SHOW);
                        break;
                    case POPUP_MENU_SWITCH_PARTNER:
                    case POPUP_MENU_UPGRADE_PARTNER:
                        set_window_update(WINDOW_ID_14, WINDOW_UPDATE_SHOW);
                        set_window_update(WINDOW_ID_19, WINDOW_UPDATE_SHOW);
                        break;
                    case POPUP_MENU_READ_DIARY_PAGE:
                    case POPUP_MENU_READ_POSTCARD:
                    case POPUP_MENU_POST_OFFICE:
                        set_window_update(WINDOW_ID_14, WINDOW_UPDATE_SHOW);
                        break;
                }
            } else {
                switch (gPopupMenu->popupType) {
                    case POPUP_MENU_USE_ITEM:
                    case POPUP_MENU_THROW_AWAY_ITEM:
                    case POPUP_MENU_TRADE_FOR_BADGE:
                    case POPUP_MENU_SELL_ITEM:
                    case POPUP_MENU_CHECK_ITEM:
                    case POPUP_MENU_CLAIM_ITEM:
                    case POPUP_MENU_READ_LETTER:
                    case POPUP_MENU_TAKE_FROM_CHEST:
                    case POPUP_MENU_USEKEY:
                        set_window_update(WINDOW_ID_14, (s32)basic_window_update);
                        sfx_play_sound(SOUND_OPEN_POPUP_1);
                        set_window_update(WINDOW_ID_19, (s32)basic_window_update);
                        break;
                    case POPUP_MENU_SWITCH_PARTNER:
                    case POPUP_MENU_UPGRADE_PARTNER:
                        set_window_update(WINDOW_ID_14, (s32)basic_window_update);
                        sfx_play_sound(SOUND_OPEN_POPUP_2);
                        set_window_update(WINDOW_ID_19, (s32)basic_window_update);
                        break;
                    case POPUP_MENU_READ_DIARY_PAGE:
                    case POPUP_MENU_READ_POSTCARD:
                    case POPUP_MENU_POST_OFFICE:
                        set_window_update(WINDOW_ID_14, (s32)basic_window_update);
                        sfx_play_sound(SOUND_OPEN_POPUP_1);
                        break;
                }
                set_window_update(WINDOW_ID_21, WINDOW_UPDATE_SHOW);
            }

            if (gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE) {
                set_window_update(WINDOW_ID_16, (s32)basic_window_update);
                set_window_update(WINDOW_ID_CURRENCY_COUNTER, (s32)basic_window_update);
            }
            if (gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
                set_window_update(WINDOW_ID_18, (s32)basic_window_update);
            }
            if (gPopupMenu->popupType == POPUP_MENU_SELL_ITEM) {
                set_window_update(WINDOW_ID_16, (s32)basic_window_update);
            }
            gPopupState = POPUP_STATE_CHOOSING;
            break;
        case POPUP_STATE_CHOOSING:
            if (D_8010D644 != 0) {
                D_8010D644--;
            } else {
                PopupMenu_PrevSelectedIndex = PopupMenu_SelectedIndex;

                // change selection on up input
                if (gGameStatusPtr->heldButtons[0] & (BUTTON_STICK_UP | BUTTON_Z) &&
                    (PopupMenu_SelectedIndex > 0 || (gGameStatusPtr->pressedButtons[0] & (BUTTON_STICK_UP | BUTTON_Z))))
                {
                    do {
                        PopupMenu_SelectedIndex--;
                    } while (0); // required to match
                }

                // change selection on down input
                if (gGameStatusPtr->heldButtons[0] & (BUTTON_STICK_DOWN | BUTTON_R) &&
                    ((PopupMenu_SelectedIndex < gPopupMenu->numEntries - 1) || (gGameStatusPtr->pressedButtons[0] & (BUTTON_STICK_DOWN | BUTTON_R))))
                {
                    do {
                        PopupMenu_SelectedIndex++;
                    } while (0); // required to match
                }

                // wrap selected index
                if (PopupMenu_SelectedIndex < 0) {
                    PopupMenu_SelectedIndex = gPopupMenu->numEntries - 1;
                }
                if (PopupMenu_SelectedIndex > gPopupMenu->numEntries - 1) {
                    PopupMenu_SelectedIndex = 0;
                }

                if (PopupMenu_PrevSelectedIndex != PopupMenu_SelectedIndex) {
                    sfx_play_sound(SOUND_MENU_CHANGE_SELECTION);
                }

                // ensure one option is displayed above the selected index, if applicable
                // shift up to 4 entries at a time on list wrap
                for (i = 0; i < 4; i++) {
                    if (PopupMenu_SelectedIndex < PopupMenu_FirstDisplayIndex + 1) {
                        PopupMenu_FirstDisplayIndex--;
                        if (PopupMenu_FirstDisplayIndex < 0) {
                            PopupMenu_FirstDisplayIndex = 0;
                        }
                    }
                }

                // ensure one option is displayed after the selected index, if applicable
                // shift up to 4 entries at a time on list wrap
                for (i = 0; i < 4; i++) {
                    if (PopupMenu_SelectedIndex >= PopupMenu_LastDisplayIndex - 1) {
                        PopupMenu_FirstDisplayIndex++;
                        if (PopupMenu_FirstDisplayIndex > gPopupMenu->numEntries - PopupMenu_MaxDisplayableEntryCount) {
                            PopupMenu_FirstDisplayIndex = gPopupMenu->numEntries - PopupMenu_MaxDisplayableEntryCount;
                            if (PopupMenu_FirstDisplayIndex < 0) {
                                PopupMenu_FirstDisplayIndex = 0;
                            }
                        }
                    }
                    PopupMenu_LastDisplayIndex = PopupMenu_FirstDisplayIndex + PopupMenu_MaxDisplayableEntryCount;
                }

                // make selection on A button input
                if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
                    switch (gPopupMenu->popupType) {
                        case POPUP_MENU_READ_LETTER:
                            sfx_play_sound(SOUND_MENU_NEXT);
                            if (!PopupNotBattle) {
                                gPopupState = POPUP_STATE_CHOSE_WORLD;
                            } else {
                                gPopupState = POPUP_STATE_CHOSE_BATTLE;
                            }
                            break;
                        case POPUP_MENU_POST_OFFICE:
                            sfx_play_sound(SOUND_MENU_NEXT);
                            if (!PopupNotBattle) {
                                gPopupState = POPUP_STATE_CHOSE_WORLD;
                            } else {
                                gPopupState = POPUP_STATE_CHOSE_BATTLE;
                            }
                            break;
                        default:
                            if (gPopupMenu->enabled[PopupMenu_SelectedIndex]) {
                                sfx_play_sound(SOUND_MENU_NEXT);
                                if (!PopupNotBattle) {
                                    gPopupState = POPUP_STATE_CHOSE_WORLD;
                                } else {
                                    gPopupState = POPUP_STATE_CHOSE_BATTLE;
                                }
                                break;
                            }
                            if (gPopupMenu->popupType == POPUP_MENU_SWITCH_PARTNER) {
                                sfx_play_sound(SOUND_MENU_ERROR);
                                gPopupState = POPUP_STATE_ALREADY_HAVE_PARTNER_BEGIN;
                                break;
                            }
                            if (PopupNotBattle && (gPopupMenu->popupType == POPUP_MENU_USE_ITEM || gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE)) {
                                sfx_play_sound(SOUND_MENU_ERROR);
                            }
                            break;
                    }
                } else {
                    switch (gPopupMenu->popupType) {
                        case POPUP_MENU_USE_ITEM:
                        case POPUP_MENU_THROW_AWAY_ITEM:
                        case POPUP_MENU_TRADE_FOR_BADGE:
                        case POPUP_MENU_SELL_ITEM:
                        case POPUP_MENU_CHECK_ITEM:
                        case POPUP_MENU_CLAIM_ITEM:
                        case POPUP_MENU_USEKEY:
                            if (PopupNotBattle) {
                                buttons = BUTTON_B | BUTTON_C_LEFT;
                            } else {
                                buttons = BUTTON_B;
                            }
                            break;
                        case POPUP_MENU_SWITCH_PARTNER:
                        case POPUP_MENU_UPGRADE_PARTNER:
                            if (PopupNotBattle) {
                                buttons = BUTTON_B | BUTTON_C_RIGHT;
                            } else {
                                buttons = BUTTON_B;
                            }
                            break;
                        case POPUP_MENU_READ_LETTER:
                        case POPUP_MENU_TAKE_FROM_CHEST:
                        case POPUP_MENU_READ_DIARY_PAGE:
                        case POPUP_MENU_READ_POSTCARD:
                        case POPUP_MENU_POST_OFFICE:
                            buttons = BUTTON_B;
                            break;
                        default:
                            buttons = 0;
                            break;
                    }

                    if (gGameStatusPtr->pressedButtons[0] & buttons) {
                        sfx_play_sound(SOUND_MENU_BACK);
                        if (PopupNotDipping) {
                            if (!PopupNotBattle) {
                                gPopupState = POPUP_STATE_MINUS_3;
                            } else {
                                gPopupState = POPUP_STATE_MINUS_7;
                            }
                        } else {
                            if (PopupDipMode == 0) {
                                gPopupState = POPUP_STATE_ALREADY_HAVE_PARTNER_BEGIN;
                            } else {
                                gPopupState = POPUP_STATE_CANCEL_DIP;
                            }
                        }
                        break;
                    }

                    switch (gPopupMenu->popupType) {
                        default:
                            buttons = 0;
                            break;
                        case POPUP_MENU_USE_ITEM:
                            buttons = BUTTON_C_RIGHT;
                            break;
                        case POPUP_MENU_SWITCH_PARTNER:
                            buttons = BUTTON_C_LEFT;
                            break;
                    }

                    if (PopupNotBattle && (gGameStatusPtr->pressedButtons[0] & buttons)) {
                        sfx_play_sound(SOUND_MENU_BACK);
                        gPopupState = POPUP_STATE_CHOSE_SWAP;
                        break;
                    }
                }
            }
            break;
        case POPUP_STATE_CHOSE_WORLD:
            hud_element_set_tint(PopupMenu_EmptybarHEID, 160, 160, 160);
            hud_element_set_tint(PopupMenu_EntryIconHEID, 160, 160, 160);
            hud_element_set_tint(PopupMenu_CursorHEID, 160, 160, 160);
            hud_element_set_tint(PopupMenu_UpArrowHEID, 160, 160, 160);
            hud_element_set_tint(PopupMenu_DownArrowHEID, 160, 160, 160);
            hud_element_set_script(PopupMenu_CursorHEID, &HES_HandPointer);
            if (gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE) {
                hud_element_set_tint(PopupMenu_TitleIconHEID, 160, 160, 160);
                hud_element_set_tint(PopupMenu_TimesHEID, 160, 160, 160);
            }
            if (gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
                hud_element_set_tint(PopupMenu_TitleIconHEID, 160, 160, 160);
                hud_element_set_tint(PopupMenu_TimesHEID, 160, 160, 160);
            }
            if (gPopupMenu->popupType == POPUP_MENU_SWITCH_PARTNER || gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
                hud_element_set_tint(PopupMenu_PartnerLevelHEID, 160, 160, 160);
            }
            if (gPopupMenu->popupType == POPUP_MENU_SELL_ITEM) {
                hud_element_set_tint(PopupMenu_TitleIconHEID, 160, 160, 160);
            }
            D_8010D690 = MSG_PAL_0D;

            gPopupMenu->result = PopupMenu_SelectedIndex + 1;
            return PopupMenu_SelectedIndex + 1;
        case POPUP_STATE_CHOSE_BATTLE:
            gPopupMenu->result = PopupMenu_SelectedIndex + 1;
            return PopupMenu_SelectedIndex + 1;
        case POPUP_STATE_MINUS_3:
            switch (gPopupMenu->popupType) {
                case POPUP_MENU_USE_ITEM:
                case POPUP_MENU_THROW_AWAY_ITEM:
                case POPUP_MENU_TRADE_FOR_BADGE:
                case POPUP_MENU_SELL_ITEM:
                case POPUP_MENU_CHECK_ITEM:
                case POPUP_MENU_CLAIM_ITEM:
                case POPUP_MENU_READ_LETTER:
                case POPUP_MENU_TAKE_FROM_CHEST:
                case POPUP_MENU_USEKEY:
                    set_window_update(WINDOW_ID_14, WINDOW_UPDATE_HIDE);
                    set_window_update(WINDOW_ID_19, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_SWITCH_PARTNER:
                case POPUP_MENU_UPGRADE_PARTNER:
                    set_window_update(WINDOW_ID_14, WINDOW_UPDATE_HIDE);
                    set_window_update(WINDOW_ID_19, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_READ_DIARY_PAGE:
                case POPUP_MENU_READ_POSTCARD:
                case POPUP_MENU_POST_OFFICE:
                    set_window_update(WINDOW_ID_14, WINDOW_UPDATE_HIDE);
                    break;
            }
            destroy_popup_menu();
            free_worker(gPopupWorker);
            gPopupState = POPUP_STATE_MINUS_5;
            gPopupMenu->result = POPUP_RESULT_CANCEL;
            return 255;
        case POPUP_STATE_MINUS_4:
            free_worker(gPopupWorker);
            gPopupState = POPUP_STATE_MINUS_5;
            gPopupMenu->result = POPUP_RESULT_CANCEL;
            return 255;
        case POPUP_STATE_CHOSE_SWAP:
            gPopupMenu->result = POPUP_RESULT_SWAP_MENU;
            return 255;
        case POPUP_STATE_MINUS_7:
        case POPUP_STATE_MINUS_5:
            gPopupMenu->result = POPUP_RESULT_CANCEL;
            return 255;
        case POPUP_STATE_10:
            D_8010D644--;
            if (D_8010D644 == 0) {
                gPopupState = POPUP_STATE_11;
                gPopupMenu->result = PopupMenu_SelectedIndex + 1;
                return PopupMenu_SelectedIndex + 1;
            }
            break;
        case POPUP_STATE_20:
            D_8010D644++;
            if (D_8010D644 >= D_8010D692) {
                gPopupState = POPUP_STATE_CHOOSING;
                gPopupMenu->result = PopupMenu_SelectedIndex + 1;
                return PopupMenu_SelectedIndex + 1;
            }
            break;
        case POPUP_STATE_ALREADY_HAVE_PARTNER_BEGIN:
            gPopupState = POPUP_STATE_ALREADY_HAVE_PARTNER_SHOW;
            gPopupMenu->result = POPUP_RESULT_INVALID;
            return 0;
        case POPUP_STATE_ALREADY_HAVE_PARTNER_SHOW:
            set_window_update(WINDOW_ID_14, WINDOW_UPDATE_HIDE);
            set_window_update(WINDOW_ID_19, WINDOW_UPDATE_HIDE);
            if (PopupNotBattle) {
                set_window_update(WINDOW_ID_21, WINDOW_UPDATE_HIDE);
            }
#if VERSION_PAL
            width = get_msg_width(MSG_Menus_006B, 0) + 32;
            if (get_msg_lines(MSG_Menus_006B) == 1) {
                posY = 76;
            } else {
                posY = 72;
            }
            set_window_properties(WINDOW_ID_BATTLE_POPUP, 160 - (width / 2), posY, width, 40, WINDOW_PRIORITY_20, popup_draw_already_have_partner, NULL, -1);
#else
            width = get_msg_width(MSG_Menus_006B, 0) + 23;
            set_window_properties(WINDOW_ID_BATTLE_POPUP, 160 - (width / 2), 80, width, ALREADY_PARTNER_HEIGHT, WINDOW_PRIORITY_20, popup_draw_already_have_partner, NULL, -1);
#endif
            set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_SHOW);
            D_8010D644 = 60;
            gPopupState = POPUP_STATE_ALREADY_HAVE_PARTNER_AWAIT;
            return 0;
        case POPUP_STATE_ALREADY_HAVE_PARTNER_AWAIT:
            if (gGameStatusPtr->pressedButtons[0] & (BUTTON_A | BUTTON_B | BUTTON_C_RIGHT)) {
                D_8010D644 = 0;
            }
            if (D_8010D644 != 0) {
                D_8010D644--;
                return 0;
            }
            set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_HIDE);
            set_window_update(WINDOW_ID_14, WINDOW_UPDATE_SHOW);
            set_window_update(WINDOW_ID_19, WINDOW_UPDATE_SHOW);
            if (PopupNotBattle) {
                set_window_update(WINDOW_ID_21, WINDOW_UPDATE_SHOW);
            }
            gPopupState = POPUP_STATE_CHOOSING;
            gPopupMenu->result = POPUP_RESULT_CHOOSING;
            break;
        case POPUP_STATE_CANCEL_DIP:
            hud_element_set_tint(PopupMenu_EmptybarHEID, 160, 160, 160);
            hud_element_set_tint(PopupMenu_EntryIconHEID, 160, 160, 160);
            hud_element_set_tint(PopupMenu_CursorHEID, 160, 160, 160);
            hud_element_set_tint(PopupMenu_UpArrowHEID, 160, 160, 160);
            hud_element_set_tint(PopupMenu_DownArrowHEID, 160, 160, 160);
            hud_element_set_script(PopupMenu_CursorHEID, &HES_HandPointer);

            if (gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE) {
                hud_element_set_tint(PopupMenu_TitleIconHEID, 160, 160, 160);
                hud_element_set_tint(PopupMenu_TimesHEID, 160, 160, 160);
            }
            if (gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
                hud_element_set_tint(PopupMenu_TitleIconHEID, 160, 160, 160);
                hud_element_set_tint(PopupMenu_TimesHEID, 160, 160, 160);
            }
            if (gPopupMenu->popupType == POPUP_MENU_SWITCH_PARTNER || gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
                hud_element_set_tint(PopupMenu_PartnerLevelHEID, 160, 160, 160);
            }
            if (gPopupMenu->popupType == POPUP_MENU_SELL_ITEM) {
                hud_element_set_tint(PopupMenu_TitleIconHEID, 160, 160, 160);
            }

            switch (gPopupMenu->popupType) {
                case POPUP_MENU_USE_ITEM:
                case POPUP_MENU_THROW_AWAY_ITEM:
                case POPUP_MENU_TRADE_FOR_BADGE:
                case POPUP_MENU_SELL_ITEM:
                case POPUP_MENU_CHECK_ITEM:
                case POPUP_MENU_CLAIM_ITEM:
                case POPUP_MENU_READ_LETTER:
                case POPUP_MENU_TAKE_FROM_CHEST:
                case POPUP_MENU_USEKEY:
                    set_window_update(WINDOW_ID_14, WINDOW_UPDATE_HIDE);
                    set_window_update(WINDOW_ID_19, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_SWITCH_PARTNER:
                case POPUP_MENU_UPGRADE_PARTNER:
                    set_window_update(WINDOW_ID_14, WINDOW_UPDATE_HIDE);
                    set_window_update(WINDOW_ID_19, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_READ_DIARY_PAGE:
                case POPUP_MENU_READ_POSTCARD:
                case POPUP_MENU_POST_OFFICE:
                    set_window_update(WINDOW_ID_14, WINDOW_UPDATE_HIDE);
                    break;
            }

            D_8010D690 = MSG_PAL_0D;
            if (PopupDipMode == 1) {
                msgID = MSG_Menus_0068;
            } else {
                msgID = MSG_Menus_0069;
            }
#if VERSION_PAL
            width = get_msg_width(msgID, 0) + 32;
            if (get_msg_lines(msgID) == 1) {
                height = 32;
                posY = 76;
            } else {
                height = 40;
                posY = 72;
            }
            set_window_properties(WINDOW_ID_21, 160 - (width / 2), posY, width, height, WINDOW_PRIORITY_19, func_800F4C1C, NULL, -1);
#else
            width = get_msg_width(msgID, 0) + 23;
            set_window_properties(WINDOW_ID_21, 160 - (width / 2), 76, width, 32, WINDOW_PRIORITY_19, func_800F4C1C, NULL, -1);
#endif
            set_window_update(WINDOW_ID_21, WINDOW_UPDATE_SHOW);
            D_8010D6A0 = msg_get_printer_for_msg(MSG_Choice_001D, &D_8010D6A4);
            msg_printer_set_origin_pos(D_8010D6A0, 160, 144);
            gPopupState = POPUP_STATE_CANCEL_DIP_AWAIT_CHOICE;
            break;
        case POPUP_STATE_CANCEL_DIP_AWAIT_CHOICE:
            if (D_8010D6A4 == 1) {
                set_window_update(WINDOW_ID_21, WINDOW_UPDATE_HIDE);
                switch (D_8010D6A0->curOption) {
                    case 0:
                        gPopupState = POPUP_STATE_CANCEL_DIP_ACCEPT;
                        break;
                    case 1:
                        gPopupState = POPUP_STATE_CANCEL_DIP_DECLINE;
                        break;
                }
            }
            break;
        case POPUP_STATE_CANCEL_DIP_ACCEPT:
            gPopupState = POPUP_STATE_MINUS_3;
            break;
        case POPUP_STATE_CANCEL_DIP_DECLINE:
            hud_element_set_tint(PopupMenu_EmptybarHEID, 255, 255, 255);
            hud_element_set_tint(PopupMenu_EntryIconHEID, 255, 255, 255);
            hud_element_set_tint(PopupMenu_CursorHEID, 255, 255, 255);
            hud_element_set_tint(PopupMenu_UpArrowHEID, 255, 255, 255);
            hud_element_set_tint(PopupMenu_DownArrowHEID, 255, 255, 255);
            if (gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE) {
                hud_element_set_tint(PopupMenu_TitleIconHEID, 160, 160, 160);
                hud_element_set_tint(PopupMenu_TimesHEID, 160, 160, 160);
            }
            if (gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
                hud_element_set_tint(PopupMenu_TitleIconHEID, 160, 160, 160);
                hud_element_set_tint(PopupMenu_TimesHEID, 160, 160, 160);
            }
            if (gPopupMenu->popupType == POPUP_MENU_SWITCH_PARTNER || gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
                hud_element_set_tint(PopupMenu_PartnerLevelHEID, 160, 160, 160);
            }
            if (gPopupMenu->popupType == POPUP_MENU_SELL_ITEM) {
                hud_element_set_tint(PopupMenu_TitleIconHEID, 160, 160, 160);
            }
            hud_element_set_script(PopupMenu_CursorHEID, &HES_HandPointer);

            switch (gPopupMenu->popupType) {
                case POPUP_MENU_USE_ITEM:
                case POPUP_MENU_THROW_AWAY_ITEM:
                case POPUP_MENU_TRADE_FOR_BADGE:
                case POPUP_MENU_SELL_ITEM:
                case POPUP_MENU_CHECK_ITEM:
                case POPUP_MENU_CLAIM_ITEM:
                case POPUP_MENU_READ_LETTER:
                case POPUP_MENU_TAKE_FROM_CHEST:
                case POPUP_MENU_USEKEY:
                    set_window_update(WINDOW_ID_14, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_19, WINDOW_UPDATE_SHOW);
                    break;
                case POPUP_MENU_SWITCH_PARTNER:
                case POPUP_MENU_UPGRADE_PARTNER:
                    set_window_update(WINDOW_ID_14, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_19, WINDOW_UPDATE_SHOW);
                    break;
                case POPUP_MENU_READ_DIARY_PAGE:
                case POPUP_MENU_READ_POSTCARD:
                case POPUP_MENU_POST_OFFICE:
                    set_window_update(WINDOW_ID_14, WINDOW_UPDATE_SHOW);
                    break;
            }
            D_8010D690 = MSG_PAL_STANDARD;
            gPopupState = POPUP_STATE_CHOOSING;
            break;
    }
    gPopupMenu->result = POPUP_RESULT_CHOOSING;
    return 0;
}
#endif

void popup_menu_draw_menu_contents(s32* userData, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    s32 x, y;
    s32 x1, y1;
    s32 offset;
    s32 sp28;
    s32 dy;
    s32 i, j;
    s32 id;
    s32 msgPal;
    s32 a0;
    s32 v0;
    s32 t;

    switch (gPopupState) {
        case POPUP_STATE_10:
        case POPUP_STATE_CHOSE_WORLD:
        case POPUP_STATE_CHOSE_BATTLE:
        case POPUP_STATE_CHOSE_SWAP:
        case POPUP_STATE_MINUS_7:
        case POPUP_STATE_MINUS_8:
        case POPUP_STATE_CHOOSING:
        case POPUP_STATE_ALREADY_HAVE_PARTNER_BEGIN:
        case POPUP_STATE_ALREADY_HAVE_PARTNER_SHOW:
        case POPUP_STATE_20:
        case POPUP_STATE_CANCEL_DIP:
        case POPUP_STATE_CANCEL_DIP_AWAIT_CHOICE:
        case POPUP_STATE_CANCEL_DIP_ACCEPT:
        case POPUP_STATE_CANCEL_DIP_DECLINE:
        case POPUP_STATE_104:
        case POPUP_STATE_105:
            break;
        default:
            return;
    }

    baseX += 2;
    baseY += 15;
    y = -PopupMenu_FirstDisplayIndex * LINE_HEIGHT;
    y1 = D_8010D658;
    dy = y - y1;

    if (dy < 130) {
        dy *= 0.5;
    } else {
        dy = dy * 100 / 150;
    }
    if (dy != 0) {
        y1 += dy;
    } else {
        y1 = y;
    }
    D_8010D658 = y1;
    sp28 = -D_8010D658 / LINE_HEIGHT;

    x = baseX;
    y = baseY;
    y1 = y + PopupMenu_DisplayedEntryCount * LINE_HEIGHT + 4;
    switch (gPopupMenu->popupType) {
        case POPUP_MENU_USE_ITEM:
#if VERSION_JP
        case POPUP_MENU_THROW_AWAY_ITEM:
#endif
        case POPUP_MENU_TRADE_FOR_BADGE:
        case POPUP_MENU_SELL_ITEM:
        case POPUP_MENU_CHECK_ITEM:
        case POPUP_MENU_CLAIM_ITEM:
        case POPUP_MENU_READ_LETTER:
        case POPUP_MENU_TAKE_FROM_CHEST:
        case POPUP_MENU_READ_DIARY_PAGE:
        case POPUP_MENU_READ_POSTCARD:
        case POPUP_MENU_USEKEY:
        case POPUP_MENU_POST_OFFICE:
            gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, x, y, x + 112, y1);
            break;
        case POPUP_MENU_SWITCH_PARTNER:
        case POPUP_MENU_UPGRADE_PARTNER:
            gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, x, y, x + 90, y1);
            break;
#if !VERSION_JP
        case POPUP_MENU_THROW_AWAY_ITEM:
            gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, x, y, x + 160, y1);
            break;
#endif
    }

    y = baseY + D_8010D658 + 8;
    if (gPopupMenu->popupType == POPUP_MENU_THROW_AWAY_ITEM) {
        y = baseY + D_8010D658 + 21;
    }
    id = PopupMenu_EmptybarHEID;
    hud_element_set_render_pos(id, baseX + EMPTY_BAR_X, y - 3);
    hud_element_set_alpha(id, PopupMenu_Alpha);
    if (PopupMenu_MaxDisplayableEntryCount < gPopupMenu->numEntries) {
        hud_element_draw_without_clipping(id);
    }
    x = baseX;
    y = baseY + 2;
    y1 = y + PopupMenu_DisplayedEntryCount * LINE_HEIGHT;
    if ((gPopupMenu->popupType == POPUP_MENU_THROW_AWAY_ITEM) && (PopupMenu_FirstDisplayIndex < 2)) {
        y = baseY;
        y1++;
    }

#if VERSION_JP
    switch (gPopupMenu->popupType) {
        case POPUP_MENU_USE_ITEM:
        case POPUP_MENU_THROW_AWAY_ITEM:
        case POPUP_MENU_CHECK_ITEM:
        case POPUP_MENU_CLAIM_ITEM:
        case POPUP_MENU_READ_LETTER:
        case POPUP_MENU_TAKE_FROM_CHEST:
        case POPUP_MENU_READ_DIARY_PAGE:
        case POPUP_MENU_READ_POSTCARD:
        case POPUP_MENU_USEKEY:
        case POPUP_MENU_POST_OFFICE:
            gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, x, y, x + 112, y1);
            break;
        case POPUP_MENU_SWITCH_PARTNER:
            gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, x, y, x + 98, y1);
            break;
        case POPUP_MENU_TRADE_FOR_BADGE:
            gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, x, y, x + 144, y1);
            break;
        case POPUP_MENU_UPGRADE_PARTNER:
            gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, x, y, x + 144, y1);
            break;
        case POPUP_MENU_SELL_ITEM:
            gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, x, y, x + 140, y1);
            break;
    }
#else
    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, x, y, x + PopupContentScissorWidths[gPopupMenu->popupType], y1);
#endif

    x = baseX + 32;
    y = baseY + D_8010D658 + 2;
    offset = 0;
    if (gPopupMenu->popupType == POPUP_MENU_THROW_AWAY_ITEM) {
        y = baseY + D_8010D658;
        offset = 2;
    }

    t = 0;
    for (i = 0; i < gPopupMenu->numEntries; i++, t++) {
        if (sp28 - 1 > i || sp28 + PopupMenu_DisplayedEntryCount < i) {
            y += LINE_HEIGHT;
            if (i == 0) {
                y += offset;
            }
        } else {
            msgPal = D_8010D690;
            if (gPopupMenu->popupType == POPUP_MENU_SWITCH_PARTNER) {
                msgPal = MSG_PAL_STANDARD;
            }
            if (gPopupMenu->enabled[t] == 0) {
                msgPal = MSG_PAL_0B;
            }
            switch (gPopupMenu->popupType) {
                case POPUP_MENU_USE_ITEM:
                case POPUP_MENU_THROW_AWAY_ITEM:
                case POPUP_MENU_TRADE_FOR_BADGE:
                case POPUP_MENU_SELL_ITEM:
                case POPUP_MENU_CHECK_ITEM:
                case POPUP_MENU_CLAIM_ITEM:
                case POPUP_MENU_TAKE_FROM_CHEST:
                case POPUP_MENU_USEKEY:
                case POPUP_MENU_POST_OFFICE:
                    draw_msg(gPopupMenu->nameMsg[t], x, y, PopupMenu_Alpha, msgPal, DRAW_MSG_STYLE_MENU);
                    break;
                case POPUP_MENU_SWITCH_PARTNER:
                case POPUP_MENU_UPGRADE_PARTNER:
                    draw_msg(gPopupMenu->nameMsg[t], x, y, PopupMenu_Alpha, msgPal, DRAW_MSG_STYLE_MENU);
                    break;
                case POPUP_MENU_READ_LETTER:
                    if (gPopupMenu->enabled[t] == 2) {
                        msgPal = MSG_PAL_22;
                    }
                    draw_msg(gPopupMenu->nameMsg[t], x, y, PopupMenu_Alpha, msgPal, DRAW_MSG_STYLE_MENU);
                    break;
                case POPUP_MENU_READ_DIARY_PAGE:
                    if (gPopupMenu->value[t] != 0) {
                        msgPal = MSG_PAL_0B;
                    } else {
                        msgPal = MSG_PAL_STANDARD;
                    }
                    set_message_int_var(gPopupMenu->userIndex[t] + 1, 0);
                    draw_msg(MSG_Menus_00CD, x + DIARY_PAGE_X, y, PopupMenu_Alpha, msgPal, DRAW_MSG_STYLE_MENU);
                    break;
                case POPUP_MENU_READ_POSTCARD:
                    if (gPopupMenu->value[t] != 0) {
                        msgPal = MSG_PAL_0B;
                    } else {
                        msgPal = MSG_PAL_STANDARD;
                    }
                    a0 = gPopupMenu->nameMsg[t];
                    draw_msg(a0, x, y, PopupMenu_Alpha, msgPal, DRAW_MSG_STYLE_MENU);
                    break;
            }
            switch (gPopupMenu->popupType) {
                case POPUP_MENU_SWITCH_PARTNER:
                case POPUP_MENU_UPGRADE_PARTNER:
                    for (j = 0; j < ARRAY_COUNT(D_80109890); j++) {
                        id = PopupMenu_PartnerLevelHEID;

                        if (gPopupMenu->enabled[i]) {
                            hud_element_set_script(id, D_80109890[j]);
                        } else {
                            hud_element_set_script(id, D_80109898[j]);
                        }
                        if (gPopupMenu->popupType == POPUP_MENU_SWITCH_PARTNER) {
                            hud_element_set_render_pos(id, x + PARTNER_LIST_X1 + j * 13, y + 10);
                        } else {
                            hud_element_set_render_pos(id, x + PARTNER_LIST_X2 + j * 13, y + 10);
                        }
                        if (j < gPopupMenu->value[i]) {
                            hud_element_draw_next(id);
                        }
                    }
                    break;
                case POPUP_MENU_TRADE_FOR_BADGE:
                    draw_number(gPopupMenu->value[t], x + BADGE_PRICE_X, y, 1, msgPal, PopupMenu_Alpha, DRAW_NUMBER_STYLE_MONOSPACE_RIGHT);
                    break;
                case POPUP_MENU_SELL_ITEM:
                    draw_number(gPopupMenu->value[t], x + ITEM_PRICE_X, y, 1, msgPal, PopupMenu_Alpha, DRAW_NUMBER_STYLE_MONOSPACE_RIGHT);
                    break;
            }
            y += LINE_HEIGHT;
            if (i == 0) {
                y += offset;
            }
        }
    }

    x = baseX + 24;
    y = baseY + D_8010D658 + MENU_OFFSET_Y1;
    offset = 0;
    if (gPopupMenu->popupType == POPUP_MENU_THROW_AWAY_ITEM) {
        y = baseY + D_8010D658 + MENU_OFFSET_Y2;
        offset = 2;
    }

    switch (gPopupMenu->popupType) {
        case POPUP_MENU_USE_ITEM:
        case POPUP_MENU_SWITCH_PARTNER:
        case POPUP_MENU_THROW_AWAY_ITEM:
        case POPUP_MENU_TRADE_FOR_BADGE:
        case POPUP_MENU_UPGRADE_PARTNER:
        case POPUP_MENU_SELL_ITEM:
        case POPUP_MENU_CHECK_ITEM:
        case POPUP_MENU_CLAIM_ITEM:
        case POPUP_MENU_READ_LETTER:
        case POPUP_MENU_TAKE_FROM_CHEST:
        case POPUP_MENU_USEKEY:
        case POPUP_MENU_POST_OFFICE:
            for (i = 0; i < gPopupMenu->numEntries; i++) {
                if (sp28 - 1 > i || sp28 + PopupMenu_DisplayedEntryCount < i) {
                    y += LINE_HEIGHT;
                    if (i == 0) {
                        y += offset;
                    }
                } else {
                    id = PopupMenu_EntryIconHEID;
                    hud_element_set_script(id, gPopupMenu->ptrIcon[i]);
                    hud_element_set_render_pos(id, x, y);
                    hud_element_set_alpha(id, PopupMenu_Alpha);
                    hud_element_set_scale(id, 0.45f);
                    hud_element_draw_without_clipping(id);
                    y += LINE_HEIGHT;
                    if (i == 0) {
                        y += offset;
                    }
                }
            }
            break;
        case POPUP_MENU_READ_DIARY_PAGE:
            for (i = 0; i < gPopupMenu->numEntries; i++) {
                if (sp28 - 1 > i || sp28 + PopupMenu_DisplayedEntryCount < i) {
                    y += LINE_HEIGHT;
                    if (i == 0) {
                        y += offset;
                    }
                } else {
                    id = PopupMenu_EntryIconHEID;
                    hud_element_set_script(id, gPopupMenu->ptrIcon[i]);
                    hud_element_set_render_pos(id, x, y);
                    hud_element_set_alpha(id, PopupMenu_Alpha);
                    hud_element_set_scale(id, 0.45f);
                    hud_element_draw_without_clipping(id);
                    y += LINE_HEIGHT;
                    if (i == 0) {
                        y += offset;
                    }
                }
            }
            break;
        case POPUP_MENU_READ_POSTCARD:
            for (i = 0; i < gPopupMenu->numEntries; i++) {
                if (sp28 - 1 > i || sp28 + PopupMenu_DisplayedEntryCount < i) {
                    y += LINE_HEIGHT;
                    if (i == 0) {
                        y += offset;
                    }
                } else {
                    id = PopupMenu_EntryIconHEID;
                    hud_element_set_script(id, gPopupMenu->ptrIcon[i]);
                    hud_element_set_render_pos(id, x, y);
                    hud_element_set_alpha(id, PopupMenu_Alpha);
                    hud_element_set_scale(id, 0.45f);
                    hud_element_draw_without_clipping(id);
                    y += LINE_HEIGHT;
                    if (i == 0) {
                        y += offset;
                    }
                }
            }
            break;
    }

    v0 = (PopupMenu_SelectedIndex - PopupMenu_FirstDisplayIndex) * LINE_HEIGHT;
    x = baseX + 8;
    y = baseY + 9 + v0;
    id = PopupMenu_CursorHEID;

    if (gPopupMenu->popupType == POPUP_TYPE_THROW_AWAY_ITEM && PopupMenu_SelectedIndex == 0) {
        y -= 2;
    }
    hud_element_set_render_pos(id, x, y);
    hud_element_set_alpha(id, PopupMenu_Alpha);
    hud_element_draw_without_clipping(id);

    x = baseX;
    y = baseY - 6;
    y1 = y + (PopupMenu_DisplayedEntryCount * LINE_HEIGHT) + 16;
    switch (gPopupMenu->popupType) {
        case POPUP_MENU_USE_ITEM:
        case POPUP_MENU_THROW_AWAY_ITEM:
        case POPUP_MENU_TRADE_FOR_BADGE:
        case POPUP_MENU_SELL_ITEM:
        case POPUP_MENU_CHECK_ITEM:
        case POPUP_MENU_CLAIM_ITEM:
        case POPUP_MENU_READ_LETTER:
        case POPUP_MENU_TAKE_FROM_CHEST:
        case POPUP_MENU_READ_DIARY_PAGE:
        case POPUP_MENU_READ_POSTCARD:
        case POPUP_MENU_USEKEY:
        case POPUP_MENU_POST_OFFICE:
            gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, x, y, x + 112, y1);
            break;
        case POPUP_MENU_SWITCH_PARTNER:
        case POPUP_MENU_UPGRADE_PARTNER:
            gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, x, y, x + POPUP_PARTNER_WIDTH, y1);
            break;
    }

    switch (gPopupMenu->popupType) {
#if VERSION_JP
        case POPUP_MENU_TRADE_FOR_BADGE:
            offset = 31;
            break;
        case POPUP_MENU_UPGRADE_PARTNER:
            offset = 32;
            break;
        case POPUP_MENU_SELL_ITEM:
            offset = 31;
            break;
        default:
            offset = 31;
            break;
        case POPUP_MENU_CLAIM_ITEM:
        case POPUP_MENU_READ_LETTER:
        case POPUP_MENU_TAKE_FROM_CHEST:
            offset = 31;
            break;
        case POPUP_MENU_USEKEY:
            offset = 31;
            break;
        case POPUP_MENU_READ_DIARY_PAGE:
            offset = 13;
            break;
        case POPUP_MENU_READ_POSTCARD:
            offset = 21;
            break;
        case POPUP_MENU_SWITCH_PARTNER:
        case POPUP_MENU_POST_OFFICE:
            offset = 14;
            break;
#else
        case POPUP_MENU_SWITCH_PARTNER:
            offset = 35;
            break;
        case POPUP_MENU_THROW_AWAY_ITEM:
        case POPUP_MENU_UPGRADE_PARTNER:
            offset = 35;
            break;
        case POPUP_MENU_SELL_ITEM:
            offset = 31;
            break;
        case POPUP_MENU_CHECK_ITEM:
            offset = 31;
            break;
        case POPUP_MENU_CLAIM_ITEM:
        case POPUP_MENU_READ_LETTER:
        case POPUP_MENU_TAKE_FROM_CHEST:
            offset = 31;
            break;
        default:
            offset = 37;
            break;
        case POPUP_MENU_READ_DIARY_PAGE:
            offset = 29;
            break;
        case POPUP_MENU_READ_POSTCARD:
            offset = 21;
            break;
        case POPUP_MENU_TRADE_FOR_BADGE:
        case POPUP_MENU_POST_OFFICE:
            offset = 30;
            break;
#endif
    }

    if (PopupMenu_FirstDisplayIndex > 0) {
        id = PopupMenu_UpArrowHEID;
        x = baseX + offset;
        y = baseY;
        hud_element_set_render_pos(id, x + 35, y - 1);
        hud_element_set_alpha(id, PopupMenu_Alpha);
        hud_element_draw_without_clipping(id);
    }

    if (PopupMenu_LastDisplayIndex < gPopupMenu->numEntries) {
        id = PopupMenu_DownArrowHEID;
        x = baseX + offset;
        y = baseY;
        y += PopupMenu_MaxDisplayableEntryCount * LINE_HEIGHT;
        hud_element_set_render_pos(id, x + 35, y + 5);
        hud_element_set_alpha(id, PopupMenu_Alpha);
        hud_element_draw_without_clipping(id);
    }
}

#if VERSION_PAL
void popup_menu_draw_title_contents(s32* userData, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    draw_msg(gPopupMenu->unk_330, baseX + gPopupMenu->unk_334, baseY + 2, PopupMenu_Alpha, gPopupMenu->unk_338 == 0 ? MSG_PAL_32 : MSG_PAL_34, DRAW_MSG_STYLE_MENU);

    switch (gPopupMenu->popupType) {
        case POPUP_MENU_USE_ITEM:
        case POPUP_MENU_THROW_AWAY_ITEM:
        case POPUP_MENU_SELL_ITEM:
        case POPUP_MENU_CHECK_ITEM:
        case POPUP_MENU_CLAIM_ITEM:
            switch (gPopupMenu->dipMode) {
                case 1:
                    draw_number(gPopupMenu->titleNumber, baseX + 94, baseY + 2, 1, MSG_PAL_32, PopupMenu_Alpha,
                                DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
                    draw_number(2, baseX + 114, baseY + 2, 1, MSG_PAL_32, PopupMenu_Alpha,
                                DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
                    draw_msg(MSG_MenuTip_0034, baseX + 94, baseY + 2, PopupMenu_Alpha, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
                    break;
                case 2:
                    draw_number(gPopupMenu->titleNumber, baseX + 94, baseY + 2, 1, MSG_PAL_32, PopupMenu_Alpha,
                                DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
                    draw_number(3, baseX + 114, baseY + 2, 1, MSG_PAL_32, PopupMenu_Alpha,
                                DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
                    draw_msg(MSG_MenuTip_0034, baseX + 94, baseY + 2, PopupMenu_Alpha, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
                    break;
            }
            break;
    }
}
#else

#if VERSION_JP
#define POPUP_ITEM_X            35
#define POPUP_ITEMDIP_NUMBER_X  82
#define POPUP_ITEMDIP_X         102
#define POPUP_TRIPLE_DIP_X      4
#define POPUP_BADGE_X           38
#define POPUP_CHEST_X           31
#define POPUP_POSTCARD_X        16
#define POPUP_ITEM_KEY_X        35
#define POPUP_POSTOFFICE_X      23
#else
#define POPUP_ITEM_X            26
#define POPUP_ITEMDIP_NUMBER_X  94
#define POPUP_ITEMDIP_X         114
#define POPUP_TRIPLE_DIP_X      6
#define POPUP_BADGE_X           27
#define POPUP_CHEST_X           4
#define POPUP_POSTCARD_X        6
#define POPUP_ITEM_KEY_X        27
#define POPUP_POSTOFFICE_X      8
#endif

void popup_menu_draw_title_contents(
    s32* userData, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening)
{
    switch (gPopupMenu->popupType) {
        case POPUP_MENU_USE_ITEM:
        case POPUP_MENU_THROW_AWAY_ITEM:
        case POPUP_MENU_SELL_ITEM:
        case POPUP_MENU_CHECK_ITEM:
        case POPUP_MENU_CLAIM_ITEM:
            switch (gPopupMenu->dipMode) {
                case 0:
#if VERSION_JP
                    draw_msg(MSG_Menus_JP_004F, baseX + POPUP_ITEM_X, baseY + 2, PopupMenu_Alpha, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
#else
                    draw_msg(MSG_Menus_Items, baseX + POPUP_ITEM_X, baseY + 2, PopupMenu_Alpha, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
#endif
                    break;
                case 1:
                    draw_msg(MSG_Menus_DoubleDip, baseX + 4, baseY + 2, PopupMenu_Alpha, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
                    draw_number(gPopupMenu->titleNumber, baseX + POPUP_ITEMDIP_NUMBER_X, baseY + 2, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_32,
                                PopupMenu_Alpha, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
                    draw_number(2, baseX + POPUP_ITEMDIP_X, baseY + 2, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_32, PopupMenu_Alpha, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
                    break;
                case 2:
                    draw_msg(MSG_Menus_TripleDip, baseX + POPUP_TRIPLE_DIP_X, baseY + 2, PopupMenu_Alpha, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
                    draw_number(gPopupMenu->titleNumber, baseX + POPUP_ITEMDIP_NUMBER_X, baseY + 2, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_32,
                                PopupMenu_Alpha, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
                    draw_number(3, baseX + POPUP_ITEMDIP_X, baseY + 2, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_32, PopupMenu_Alpha,
                                DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
                    break;
            }
            break;
        case POPUP_MENU_TRADE_FOR_BADGE:
            draw_msg(MSG_MenuTip_0032, baseX + POPUP_BADGE_X, baseY + 2, PopupMenu_Alpha, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
            break;
#if VERSION_JP
        case POPUP_MENU_UPGRADE_PARTNER:
            draw_msg(MSG_Menus_PartyMember, baseX + 20, baseY + 2, PopupMenu_Alpha, MSG_PAL_34, DRAW_MSG_STYLE_MENU);
            break;
#endif
        case POPUP_MENU_READ_LETTER:
            draw_msg(MSG_MenuTip_0033, baseX + 23, baseY + 2, PopupMenu_Alpha, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
            break;
        case POPUP_MENU_TAKE_FROM_CHEST:
            draw_msg(MSG_Menus_00D7, baseX + POPUP_CHEST_X, baseY + 2, PopupMenu_Alpha, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
            break;
        case POPUP_MENU_READ_DIARY_PAGE:
            draw_msg(MSG_Menus_00CE, baseX + 8, baseY + 2, PopupMenu_Alpha, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
            break;
        case POPUP_MENU_READ_POSTCARD:
            draw_msg(MSG_Menus_00D0, baseX + POPUP_POSTCARD_X, baseY + 2, PopupMenu_Alpha, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
            break;
        case POPUP_MENU_USEKEY:
#if VERSION_JP
            draw_msg(MSG_Menus_KeyItems, baseX + POPUP_ITEM_KEY_X, baseY + 2, PopupMenu_Alpha, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
#else
            draw_msg(MSG_Menus_Items, baseX + POPUP_ITEM_KEY_X, baseY + 2, PopupMenu_Alpha, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
#endif
            break;
        case POPUP_MENU_SWITCH_PARTNER:
#if !VERSION_JP
        case POPUP_MENU_UPGRADE_PARTNER:
#endif
        case POPUP_MENU_POST_OFFICE:
            draw_msg(MSG_Menus_PartyMember, baseX + POPUP_POSTOFFICE_X, baseY + 2, PopupMenu_Alpha, MSG_PAL_34, DRAW_MSG_STYLE_MENU);
            break;
    }
}
#endif

void func_800F48F4(s32* userData, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    draw_msg(gPopupMenu->descMsg[PopupMenu_SelectedIndex], baseX + 8, baseY, PopupMenu_Alpha, D_8010D690, 0);
}

#if VERSION_PAL
void func_800F4944(s32* userData, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    s32 x = baseX;
    s32 y = baseY + 7;

    if (PopupNotBattle) {
        s32 msgWidth = get_msg_width(gPopupMenu->unk_33C, 0);
        s32 msgLines = get_msg_lines(gPopupMenu->unk_33C);

        x += ((gPopupMenu->unk_340 + 144) / 2) - (msgWidth / 2);

        draw_msg(gPopupMenu->unk_33C, x, msgLines != 1 ? y - 4 : y, 255, MSG_PAL_0F, 0);
    }
}
#else
void func_800F4944(s32* userData, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    s32 msgWidth;

#if VERSION_JP
    baseY += 6;

    if (PopupNotBattle) {
        switch (gPopupMenu->popupType) {
            case POPUP_MENU_USE_ITEM:
                msgWidth = get_msg_width(MSG_Menus_0061, 0) + 18;
                baseX += 76 - (msgWidth / 2);
                draw_msg(MSG_Menus_0061, baseX + 6, baseY + 2, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_SWITCH_PARTNER:
                msgWidth = get_msg_width(MSG_Menus_0063, 0) + 18;
                baseX += 76 - (msgWidth / 2);
                draw_msg(MSG_Menus_0063, baseX + 8, baseY + 2, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_THROW_AWAY_ITEM:
                msgWidth = get_msg_width(MSG_Menus_0064, 0) + 18;
                baseX += 76 - (msgWidth / 2);
                draw_msg(MSG_Menus_0064, baseX + 4, baseY + 2, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_TRADE_FOR_BADGE:
                msgWidth = get_msg_width(MSG_Menus_0070, 0) + 18;
                baseX += 76 - (msgWidth / 2);
                draw_msg(MSG_Menus_0070, baseX + 4, baseY + 2, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_UPGRADE_PARTNER:
                msgWidth = get_msg_width(MSG_Menus_006A, 0) + 18;
                baseX += 76 - (msgWidth / 2);
                draw_msg(MSG_Menus_006A, baseX + 4, baseY + 2, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_SELL_ITEM:
                msgWidth = get_msg_width(MSG_Menus_0065, 0) + 18;
                baseX += 76 - (msgWidth / 2);
                draw_msg(MSG_Menus_0065, baseX - 4, baseY + 2, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_CHECK_ITEM:
                msgWidth = get_msg_width(MSG_Menus_0066, 0) + 18;
                baseX += 76 - (msgWidth / 2);
                draw_msg(MSG_Menus_0066, baseX + 6, baseY + 2, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_CLAIM_ITEM:
                msgWidth = get_msg_width(MSG_Menus_0067, 0) + 18;
                baseX += 76 - (msgWidth / 2);
                draw_msg(MSG_Menus_0067, baseX + 6, baseY + 2, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_READ_LETTER:
                msgWidth = get_msg_width(MSG_Menus_JP_0081, 0) + 18;
                baseX += 76 - (msgWidth / 2);
                draw_msg(MSG_Menus_JP_0081, baseX + 6, baseY + 2, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_TAKE_FROM_CHEST:
                msgWidth = get_msg_width(MSG_Menus_00D6, 0) + 18;
                baseX += 76 - (msgWidth / 2);
                draw_msg(MSG_Menus_00D6, baseX + 6, baseY + 2, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_READ_DIARY_PAGE:
                msgWidth = get_msg_width(MSG_Menus_006C, 0) + 18;
                baseX += 76 - (msgWidth / 2);
                draw_msg(MSG_Menus_006C, baseX + 6, baseY + 2, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_READ_POSTCARD:
                msgWidth = get_msg_width(MSG_Menus_006D, 0) + 18;
                baseX += 76 - (msgWidth / 2);
                draw_msg(MSG_Menus_006D, baseX + 6, baseY + 2, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_USEKEY:
                msgWidth = get_msg_width(MSG_Menus_0062, 0) + 18;
                baseX += 76 - (msgWidth / 2);
                draw_msg(MSG_Menus_0062, baseX + 6, baseY + 2, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_POST_OFFICE:
                msgWidth = get_msg_width(MSG_Menus_006F, 0) + 18;
                baseX += 76 - (msgWidth / 2);
                draw_msg(MSG_Menus_006F, baseX + 6, baseY + 2, 255, MSG_PAL_0F, 0);
                break;
        }
    }
#else
    baseY += 7;

    if (PopupNotBattle) {
        switch (gPopupMenu->popupType) {
            case POPUP_MENU_USE_ITEM:
                msgWidth = get_msg_width(MSG_Menus_0061, 0);
                baseX += 72 - (msgWidth / 2);
                draw_msg(MSG_Menus_0061, baseX, baseY, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_SWITCH_PARTNER:
                msgWidth = get_msg_width(MSG_Menus_0063, 0);
                baseX += 72 - (msgWidth / 2);
                draw_msg(MSG_Menus_0063, baseX, baseY - 4, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_THROW_AWAY_ITEM:
                msgWidth = get_msg_width(MSG_Menus_0064, 0);
                baseX += 72 - (msgWidth / 2);
                draw_msg(MSG_Menus_0064, baseX, baseY - 4, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_TRADE_FOR_BADGE:
                msgWidth = get_msg_width(MSG_Menus_0070, 0);
                baseX += 64 - (msgWidth / 2);
                draw_msg(MSG_Menus_0070, baseX, baseY - 4, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_UPGRADE_PARTNER:
                msgWidth = get_msg_width(MSG_Menus_006A, 0);
                baseX += 68 - (msgWidth / 2);
                draw_msg(MSG_Menus_006A, baseX, baseY - 4, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_SELL_ITEM:
                msgWidth = get_msg_width(MSG_Menus_0065, 0);
                baseX += 60 - (msgWidth / 2);
                draw_msg(MSG_Menus_0065, baseX, baseY, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_CHECK_ITEM:
                msgWidth = get_msg_width(MSG_Menus_0066, 0);
                baseX += 72 - (msgWidth / 2);
                draw_msg(MSG_Menus_0066, baseX, baseY, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_CLAIM_ITEM:
                msgWidth = get_msg_width(MSG_Menus_0067, 0);
                baseX += 72 - (msgWidth / 2);
                draw_msg(MSG_Menus_0067, baseX, baseY, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_POST_OFFICE:
                msgWidth = get_msg_width(MSG_Menus_006F, 0);
                baseX += 72 - (msgWidth / 2);
                draw_msg(MSG_Menus_006F, baseX, baseY - 4, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_READ_LETTER:
                msgWidth = get_msg_width(MSG_Menus_006D, 0);
                baseX += 56 - (msgWidth / 2);
                draw_msg(MSG_Menus_006D, baseX, baseY - 4, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_TAKE_FROM_CHEST:
                msgWidth = get_msg_width(MSG_Menus_00D6, 0);
                baseX += 72 - (msgWidth / 2);
                draw_msg(MSG_Menus_00D6, baseX, baseY, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_READ_DIARY_PAGE:
                msgWidth = get_msg_width(MSG_Menus_006C, 0);
                baseX += 64 - (msgWidth / 2);
                draw_msg(MSG_Menus_006C, baseX, baseY - 4, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_READ_POSTCARD:
                msgWidth = get_msg_width(MSG_Menus_006D, 0);
                baseX += 64 - (msgWidth / 2);
                draw_msg(MSG_Menus_006D, baseX, baseY - 4, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_USEKEY:
                msgWidth = get_msg_width(MSG_Menus_0062, 0);
                baseX += 72 - (msgWidth / 2);
                draw_msg(MSG_Menus_0062, baseX, baseY, 255, MSG_PAL_0F, 0);
                break;
        }
    }
#endif
}
#endif

#if VERSION_PAL
#define X_800F4C1C 16
#else
#define X_800F4C1C 11
#endif

void func_800F4C1C(s32* userData, s32 x, s32 y) {
    s32 xPos = x + X_800F4C1C;
    s32 yPos = y + 8;
    s32 msg;

    if (PopupDipMode == 1) {
        msg = MSG_Menus_0068;
    } else {
        msg = MSG_Menus_0069;
    }

#if VERSION_PAL
    if (get_msg_lines(msg) != 1) {
        yPos -= 4;
    }
#endif
    draw_msg(msg, xPos, yPos, 255, MSG_PAL_0F, 0);
}

void popup_draw_cost_icon(s32* userData, s32 x, s32 y) {
    s32 hudElement;
    s32 xPos;
    s32 yPos;

    switch (gPopupMenu->popupType) {
        case POPUP_TYPE_TRADE_FOR_BADGE:
            xPos = x + 16;
            hudElement = PopupMenu_TitleIconHEID;
            yPos = y + 16;
            break;
#if VERSION_JP
        case POPUP_TYPE_UPGRADE_PARTNER:
            draw_msg(MSG_Menus_006E, x + 7, y + 2, PopupMenu_Alpha, MSG_PAL_34, 1);
            return;
#endif
        case POPUP_TYPE_SELL_ITEM:
            xPos = x + 17;
            hudElement = PopupMenu_TitleIconHEID;
            yPos = y + 17;
            break;
        default:
            return;
    }

    hud_element_set_render_pos(hudElement, xPos, yPos);
    hud_element_set_alpha(hudElement, PopupMenu_Alpha);
    hud_element_draw_clipped(hudElement);
}

void popup_draw_already_have_partner(s32* userData, s32 x, s32 y) {
#if VERSION_JP
    draw_msg(MSG_Menus_006B, x + 11, y + 8, 255, MSG_PAL_0F, 0);
#else
    draw_msg(MSG_Menus_006B, x + 16, y + 2, 255, MSG_PAL_0F, 0);
#endif
}

void func_800F4D28(s32* userData, s32 x, s32 y) {
    s32 hudElement = PopupMenu_TitleIconHEID;
    PlayerData* playerData = &gPlayerData;
    s32 xPos = x + 14;
    s32 yPos = y + 9;
    s32 type;

    hud_element_set_alpha(hudElement, PopupMenu_Alpha);

    if (gPopupMenu->popupType == POPUP_TYPE_TRADE_FOR_BADGE) {
        hud_element_set_render_pos(hudElement, xPos, yPos);
    } else {
        hud_element_set_render_pos(hudElement, xPos, y + 10);
    }

    hud_element_draw_clipped(hudElement);

    hudElement = PopupMenu_TimesHEID;
    hud_element_set_render_pos(hudElement, x + 26, y + 11);
    hud_element_set_alpha(hudElement, PopupMenu_Alpha);
    hud_element_draw_clipped(hudElement);

    type = gPopupMenu->popupType;
    if (type == POPUP_TYPE_TRADE_FOR_BADGE) {
        draw_number(playerData->starPieces, x + 58, y + 4, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_STANDARD, PopupMenu_Alpha, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
    }
}

void create_standard_popup_menu(PopupMenu* popup) {
    PopupMenu* otherPopup;
    s8 entryCount;
    s32 initialPos;
    s32 numEntries;

    PopupMenu_WasStatusBarIgnoringChanges = status_bar_is_ignoring_changes();
    status_bar_ignore_changes();
    open_status_bar_quickly();
    gPopupMenu = popup;
    popup->result = POPUP_RESULT_CHOOSING;
    popup->dipMode = 0;
    popup->titleNumber = 0;
    PopupDipMode = 0;
    PopupNotDipping = TRUE;
    if (popup->popupType >= POPUP_MENU_DOUBLE_DIP) {
        popup->popupType -= POPUP_MENU_DOUBLE_DIP;
        PopupDipMode = 1;
        if (popup->popupType >= POPUP_MENU_DOUBLE_DIP) {
            popup->popupType -= POPUP_MENU_DOUBLE_DIP;
            PopupDipMode = 2;
        }
        PopupNotDipping = FALSE;
    }

    PopupNotBattle = TRUE;
    PopupMenu_MaxDisplayableEntryCount = 6;
    gPopupState = POPUP_STATE_INIT;

    initialPos = gPopupMenu->initialPos;
    numEntries = gPopupMenu->numEntries;
    PopupMenu_SelectedIndex = initialPos;
    if (initialPos >= numEntries) {
        PopupMenu_SelectedIndex = numEntries - 1;
    }
    PopupMenu_FirstDisplayIndex = 0;
    PopupMenu_PrevSelectedIndex = PopupMenu_SelectedIndex;

    entryCount = gPopupMenu->numEntries;
    PopupMenu_DisplayedEntryCount = entryCount;
    if (PopupMenu_MaxDisplayableEntryCount < entryCount) {
        PopupMenu_DisplayedEntryCount = 6;
    }

    PopupMenu_LastDisplayIndex = 6;
    if (gPopupMenu->numEntries < PopupMenu_MaxDisplayableEntryCount) {
        PopupMenu_LastDisplayIndex = gPopupMenu->numEntries;
    }

    PopupMenu_Alpha = 255;
    D_8010D691 = 4;
    D_8010D692 = 6;
    gPopupWorker = create_worker_frontUI((void (*) (void)) popup_menu_update, NULL);
}

void create_shop_popup_menu(PopupMenu* popup) {
    gPopupMenu = popup;

    popup->result = POPUP_RESULT_CHOOSING;
    popup->dipMode = 0;
    popup->titleNumber = 0;
    PopupMenu_WasStatusBarIgnoringChanges = status_bar_is_ignoring_changes();
    PopupDipMode = 0;
    PopupNotDipping = TRUE;
    if (gPopupMenu->popupType >= POPUP_MENU_DOUBLE_DIP) {
        gPopupMenu->popupType -= POPUP_MENU_DOUBLE_DIP;
        PopupDipMode = 1;
        if (gPopupMenu->popupType >= POPUP_MENU_DOUBLE_DIP) {
            gPopupMenu->popupType -= POPUP_MENU_DOUBLE_DIP;
            PopupDipMode = 2;
        }
        PopupNotDipping = FALSE;
    }

    PopupNotBattle = TRUE;
    PopupMenu_MaxDisplayableEntryCount = 6;
    gPopupState = POPUP_STATE_INIT;
    PopupMenu_SelectedIndex = gPopupMenu->initialPos;
    if (PopupMenu_SelectedIndex >= gPopupMenu->numEntries) {
        PopupMenu_SelectedIndex = gPopupMenu->numEntries - 1;
    }
    PopupMenu_FirstDisplayIndex = 0;
    PopupMenu_PrevSelectedIndex = PopupMenu_SelectedIndex;
    PopupMenu_DisplayedEntryCount = gPopupMenu->numEntries;

    if (PopupMenu_DisplayedEntryCount > PopupMenu_MaxDisplayableEntryCount) {
        PopupMenu_DisplayedEntryCount = PopupMenu_MaxDisplayableEntryCount;
    }

    PopupMenu_LastDisplayIndex = PopupMenu_MaxDisplayableEntryCount;
    if (gPopupMenu->numEntries < PopupMenu_MaxDisplayableEntryCount) {
        PopupMenu_LastDisplayIndex = gPopupMenu->numEntries;
    }

    PopupMenu_Alpha = 255;
    D_8010D691 = 4;
    D_8010D692 = 6;
    gPopupWorker = create_worker_frontUI((void (*) (void)) popup_menu_update, NULL);
}

void create_battle_popup_menu(PopupMenu* popup) {
    gPopupMenu = popup;

    popup->result = POPUP_RESULT_CHOOSING;
    D_8010D693 = popup->titleNumber;
    PopupMenu_WasStatusBarIgnoringChanges = status_bar_is_ignoring_changes();
    PopupDipMode = 0;
    PopupNotDipping = TRUE;
    if (gPopupMenu->popupType >= POPUP_MENU_DOUBLE_DIP) {
        gPopupMenu->popupType -= POPUP_MENU_DOUBLE_DIP;
        PopupDipMode = 1;
        if (gPopupMenu->popupType >= POPUP_MENU_DOUBLE_DIP) {
            gPopupMenu->popupType -= POPUP_MENU_DOUBLE_DIP;
            PopupDipMode = 2;
        }
        PopupNotDipping = FALSE;
    }

    PopupNotBattle = FALSE;
    PopupMenu_MaxDisplayableEntryCount = 6;
    gPopupState = POPUP_STATE_INIT;
    PopupMenu_SelectedIndex = gPopupMenu->initialPos;
    if (PopupMenu_SelectedIndex >= gPopupMenu->numEntries) {
        PopupMenu_SelectedIndex = gPopupMenu->numEntries - 1;
    }
    PopupMenu_FirstDisplayIndex = 0;
    PopupMenu_PrevSelectedIndex = PopupMenu_SelectedIndex;
    PopupMenu_DisplayedEntryCount = gPopupMenu->numEntries;

    if (PopupMenu_DisplayedEntryCount > PopupMenu_MaxDisplayableEntryCount) {
        PopupMenu_DisplayedEntryCount = PopupMenu_MaxDisplayableEntryCount;
    }

    PopupMenu_LastDisplayIndex = PopupMenu_MaxDisplayableEntryCount;
    if (gPopupMenu->numEntries < PopupMenu_MaxDisplayableEntryCount) {
        PopupMenu_LastDisplayIndex = gPopupMenu->numEntries;
    }

    PopupMenu_Alpha = 255;
    D_8010D691 = 9;
    D_8010D692 = 2;
    gPopupWorker = create_worker_frontUI((void (*) (void)) popup_menu_update, NULL);
}

void func_800F52BC(void) {
    popup_menu_update();
}
