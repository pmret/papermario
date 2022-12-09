#include "common.h"
#include "hud_element.h"

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
s16 D_801098A0[] = {
    0x008C, 0x008C, 0x008D, 0x007C, 0x0086, 0x0077, 0x008D, 0x008D, 0x006C, 0x008D, 0x0084, 0x0084, 0x008D, 0x008C,
};
s16 D_801098BC[] = {
    0x0089, 0x0085, 0x0089, 0x009A, 0x00A4, 0x0122, 0x0089, 0x0089, 0x00A7, 0x0089, 0x0089, 0x0093, 0x0089, 0x0089,
    0x0000, 0x0000, 0x0000, 0x0000,
};

extern s32 D_8010D640;
extern s32 D_8010D644;
extern s32 D_8010D648;
extern s32 D_8010D64C;
extern s32 D_8010D650;
extern s8 D_8010D654;
extern s8 D_8010D655;
extern s8 D_8010D656;
extern s16 D_8010D658;
extern s16 D_8010D65A;
extern s32 D_8010D65C;
extern s32 D_8010D660;
extern s32 D_8010D664;
extern s32 D_8010D668;
extern s32 D_8010D66C;
extern s32 D_8010D670;
extern s32 D_8010D674;
extern s32 D_8010D678;
extern s16 D_8010D67C;
extern s16 D_8010D67E;
extern s16 D_8010D680;
extern s16 D_8010D682;
extern s16 D_8010D684;
extern s16 D_8010D686;
extern s16 D_8010D688;
extern s16 D_8010D68A;
extern s16 D_8010D68C;
extern s8 D_8010D68E; // bool
extern s8 D_8010D68F;
extern s8 D_8010D690;
extern s8 D_8010D691;
extern s8 D_8010D692;
extern s8 D_8010D693;
extern s32 D_8010D694;
extern s8 D_8010D698;
extern s8 D_8010D699;
extern s8 D_8010D69A;
extern PopupMenu* gPopupMenu;
extern MessagePrintState* D_8010D6A0;
extern s32 D_8010D6A4;

s8 func_800E98D4(void);

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
void func_800F4C1C(PopupMessage* popup, s32 x, s32 y);
void func_800F4C6C(PopupMessage* popup, s32 x, s32 y);
void func_800F4CF0(PopupMessage* popup, s32 x, s32 y);
void func_800F4D28(PopupMessage* popup, s32 x, s32 y);

void hide_popup_menu(void) {
    if (D_8010D68E) {
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
        set_window_update(WINDOW_ID_21, 2);
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
                set_window_update(WINDOW_ID_14, 2);
                set_window_update(WINDOW_ID_19, 2);
                break;
            case POPUP_MENU_READ_DIARY_PAGE:
            case POPUP_MENU_READ_POSTCARD:
            case POPUP_MENU_POST_OFFICE:
                set_window_update(WINDOW_ID_14, 2);
                break;
        }
    }

    if (gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE) {
        set_window_update(WINDOW_ID_16, (s32) basic_hidden_window_update);
        set_window_update(WINDOW_ID_20, (s32) basic_hidden_window_update);
    }
    if (gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
        set_window_update(WINDOW_ID_18, (s32) basic_hidden_window_update);
    }
    if (gPopupMenu->popupType == POPUP_MENU_SELL_ITEM) {
        set_window_update(WINDOW_ID_16, (s32) basic_hidden_window_update);
        set_window_update(WINDOW_ID_20, (s32) basic_hidden_window_update);
    }
    D_8010D640 = 10;
    D_8010D644 = D_8010D692;
}

void destroy_popup_menu(void) {
    hud_element_free(D_8010D65C);
    hud_element_free(D_8010D678);
    hud_element_free(D_8010D66C);
    hud_element_free(D_8010D670);
    hud_element_free(D_8010D674);

    if (gPopupMenu->popupType == POPUP_TYPE_TRADE_FOR_BADGE) {
        hud_element_free(D_8010D660);
        hud_element_free(D_8010D664);
    }

    if (gPopupMenu->popupType == POPUP_TYPE_UPGRADE_PARTNER) {
        hud_element_free(D_8010D660);
        hud_element_free(D_8010D664);
    }

    if (gPopupMenu->popupType == POPUP_TYPE_SWITCH_PARTNER || gPopupMenu->popupType == POPUP_TYPE_UPGRADE_PARTNER) {
        hud_element_free(D_8010D668);
    }

    if (gPopupMenu->popupType == POPUP_TYPE_SELL_ITEM) {
        hud_element_free(D_8010D660);
    }

    if ((gPopupMenu->popupType <= POPUP_TYPE_USE_ITEM ||
         gPopupMenu->popupType == POPUP_TYPE_SWITCH_PARTNER ||
         gPopupMenu->popupType == POPUP_TYPE_THROW_AWAY_ITEM ||
         gPopupMenu->popupType == POPUP_TYPE_TRADE_FOR_BADGE ||
         gPopupMenu->popupType == POPUP_TYPE_UPGRADE_PARTNER ||
         gPopupMenu->popupType == POPUP_TYPE_USE_KEY
        ) && !gGameStatusPtr->isBattle) {
        if (D_8010D69A == 0) {
            status_menu_respond_to_changes();
        }
        close_status_menu();
    }

    D_8010D640 = -4;
}

void func_800F16CC(void) {
    if (D_8010D68E) {
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
                sfx_play_sound(SOUND_1);
                set_window_update(WINDOW_ID_19, (s32) basic_window_update);
                break;
            case POPUP_MENU_SWITCH_PARTNER:
            case POPUP_MENU_UPGRADE_PARTNER:
                set_window_update(WINDOW_ID_14, (s32) basic_window_update);
                sfx_play_sound(SOUND_2);
                set_window_update(WINDOW_ID_19, (s32) basic_window_update);
                break;
            case POPUP_MENU_READ_DIARY_PAGE:
            case POPUP_MENU_READ_POSTCARD:
            case POPUP_MENU_POST_OFFICE:
                set_window_update(WINDOW_ID_14, (s32) basic_window_update);
                sfx_play_sound(SOUND_1);
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
                set_window_update(WINDOW_ID_14, 1);
                set_window_update(WINDOW_ID_19, 1);
                break;
            case POPUP_MENU_SWITCH_PARTNER:
            case POPUP_MENU_UPGRADE_PARTNER:
                set_window_update(WINDOW_ID_14, 1);
                set_window_update(WINDOW_ID_19, 1);
                break;
            case POPUP_MENU_READ_DIARY_PAGE:
            case POPUP_MENU_READ_POSTCARD:
            case POPUP_MENU_POST_OFFICE:
                set_window_update(WINDOW_ID_14, 1);
                break;
        }
    }

    if (gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE) {
        set_window_update(WINDOW_ID_16, (s32) basic_window_update);
        set_window_update(WINDOW_ID_20, (s32) basic_window_update);
    }
    if (gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
        set_window_update(WINDOW_ID_18, (s32) basic_window_update);
    }
    if (gPopupMenu->popupType == POPUP_MENU_SELL_ITEM) {
        set_window_update(WINDOW_ID_16, (s32) basic_window_update);
    }
    hud_element_set_tint(D_8010D65C, 255, 255, 255);
    hud_element_set_tint(D_8010D678, 255, 255, 255);
    hud_element_set_tint(D_8010D66C, 255, 255, 255);
    hud_element_set_tint(D_8010D670, 255, 255, 255);
    hud_element_set_tint(D_8010D674, 255, 255, 255);

    if (gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE) {
        hud_element_set_tint(D_8010D660, 255, 255, 255);
        hud_element_set_tint(D_8010D664, 255, 255, 255);
    }
    if (gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
        hud_element_set_tint(D_8010D660, 255, 255, 255);
        hud_element_set_tint(D_8010D664, 255, 255, 255);
    }
    if (gPopupMenu->popupType == POPUP_MENU_SWITCH_PARTNER || gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
        hud_element_set_tint(D_8010D668, 255, 255, 255);
    }
    if (gPopupMenu->popupType == POPUP_MENU_SELL_ITEM) {
        hud_element_set_tint(D_8010D660, 255, 255, 255);
    }
    hud_element_set_script(D_8010D66C, &HES_AnimatedHandPointer);
    D_8010D690 = MSG_PAL_STANDARD;
    D_8010D640 = 0x14;
}

s32 popup_menu_update(void) {
    s32 posX;
    s32 posY;
    s32 width;
    s32 elementID;
    s32 cond;
    s32 buttons;
    s32 msgID;
    s32 one;
    s32 i;

    switch (D_8010D640) {
        case 0:
            D_8010D67C = 20;
            D_8010D67E = 72;
            D_8010D680 = 20;
            D_8010D682 = 186;
            D_8010D684 = 16;
            D_8010D686 = 88;
            D_8010D688 = 32;
            D_8010D68A = 164;
            if (D_8010D68E) {
                D_8010D67C = D_801098A0[gPopupMenu->popupType] + 20;
            }
            if (D_8010D68F >= 7) {
                D_8010D67E = 62;
            }
            D_8010D68C = 0;
            elementID = hud_element_create(&HES_EmptyBar);
            D_8010D65C = elementID;
            hud_element_set_flags(elementID, HUD_ELEMENT_FLAGS_80);
            hud_element_set_tint(elementID, 255, 255, 255);
            if (gPopupMenu->popupType != POPUP_MENU_THROW_AWAY_ITEM) {
                hud_element_set_flags(elementID, HUD_ELEMENT_FLAGS_DISABLED);
            }

            one = 1; // required to match (why is 1 loaded so early?)
            elementID = hud_element_create(gPopupMenu->ptrIcon[0]);
            D_8010D678 = elementID;
            hud_element_set_scale(elementID, 0.45f);
            hud_element_set_flags(elementID, HUD_ELEMENT_FLAGS_FILTER_TEX | HUD_ELEMENT_FLAGS_80);

            elementID = hud_element_create(&HES_AnimatedHandPointer);
            D_8010D66C = elementID;
            hud_element_set_flags(elementID, HUD_ELEMENT_FLAGS_DROP_SHADOW | HUD_ELEMENT_FLAGS_80);

            elementID = hud_element_create(&HES_GreenArrowUp);
            D_8010D670 = elementID;
            hud_element_set_flags(elementID, HUD_ELEMENT_FLAGS_DROP_SHADOW | HUD_ELEMENT_FLAGS_80);

            elementID = hud_element_create(&HES_GreenArrowDown);
            D_8010D674 = elementID;
            hud_element_set_flags(elementID, HUD_ELEMENT_FLAGS_DROP_SHADOW | HUD_ELEMENT_FLAGS_80);

            if (gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE) {
                D_8010D660 = hud_element_create(&HES_StatusStarPiece);
                elementID = D_8010D660;
                hud_element_set_flags(elementID, HUD_ELEMENT_FLAGS_80);
                hud_element_set_tint(elementID, 255, 255, 255);
            }
            if (gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
                D_8010D660 = hud_element_create(&HES_StatusStarPiece);
                elementID = D_8010D660;
                hud_element_set_flags(elementID, HUD_ELEMENT_FLAGS_FILTER_TEX | HUD_ELEMENT_FLAGS_80);
                hud_element_set_tint(elementID, 255, 255, 255);
            }
            if (gPopupMenu->popupType == POPUP_MENU_SELL_ITEM) {
                D_8010D660 = hud_element_create(&HES_StatusCoin);
                elementID = D_8010D660;
                hud_element_set_flags(elementID, HUD_ELEMENT_FLAGS_80);
                hud_element_set_tint(elementID, 255, 255, 255);
            }
            if (gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE || gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
                D_8010D664 = hud_element_create(&HES_MenuTimes);
                elementID = D_8010D664;
                hud_element_set_flags(elementID, HUD_ELEMENT_FLAGS_80);
                hud_element_set_tint(elementID, 255, 255, 255);
            }
            if (gPopupMenu->popupType == one || gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
                D_8010D668 = hud_element_create(D_80109890[0]);
                elementID = D_8010D668;
                hud_element_set_flags(elementID, HUD_ELEMENT_FLAGS_80);
                hud_element_set_tint(elementID, 255, 255, 255);
            }

            D_8010D65A = -200;
            D_8010D644 = D_8010D691;
            if (!D_8010D68E) {
                D_8010D644 = 1;
            }
            D_8010D690 = MSG_PAL_STANDARD;

            posX = D_8010D67C;
            posY = D_8010D67E;
            switch (gPopupMenu->popupType) {
                case POPUP_MENU_USE_ITEM:
                case POPUP_MENU_THROW_AWAY_ITEM:
                case POPUP_MENU_CHECK_ITEM:
                case POPUP_MENU_CLAIM_ITEM:
                case POPUP_MENU_USEKEY:
                    set_window_properties(WINDOW_ID_14, posX, posY, 0x91, (D_8010D656 * 13) + 0x1A, 0x14, popup_menu_draw_menu_contents, NULL, -1);
                    if (gPopupMenu->unk_31C == 0) {
                        set_window_properties(WINDOW_ID_15, 0x19, -6, 0x5F, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    } else {
                        set_window_properties(WINDOW_ID_15, 0xC, -6, 0x79, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    }
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_SWITCH_PARTNER:
                    set_window_properties(WINDOW_ID_14, posX, posY, 0x8B, (D_8010D656 * 13) + 0x1A, 0x14, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_17, 0xD, -6, 0x72, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_HIDE);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_SHOW);
                    break;
                case POPUP_MENU_TRADE_FOR_BADGE:
                    set_window_properties(WINDOW_ID_14, posX, posY, 0xA2, (D_8010D656 * 13) + 0x1A, 0x14, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_15, 0x11, -6, 0x60, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_UPGRADE_PARTNER:
                    set_window_properties(WINDOW_ID_14, posX, posY, 0x92, (D_8010D656 * 13) + 0x1A, 0x14, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_17, 0xC, -6, 0x72, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_HIDE);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_SHOW);
                    break;
                case POPUP_MENU_SELL_ITEM:
                    set_window_properties(WINDOW_ID_14, posX, posY, 0xA7, (D_8010D656 * 13) + 0x1A, 0x14, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_15, 0x16, -6, 0x5F, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_READ_LETTER:
                    set_window_properties(WINDOW_ID_14, posX, posY, 0xAA, (D_8010D656 * 13) + 0x1A, 0x14, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_15, 0x20, -6, 0x68, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_TAKE_FROM_CHEST:
                    set_window_properties(WINDOW_ID_14, posX, posY, 0x91, (D_8010D656 * 13) + 0x1A, 0x14, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_15, 0xC, -6, 0x79, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_READ_DIARY_PAGE:
                    set_window_properties(WINDOW_ID_14, posX, posY, 0x80, (D_8010D656 * 13) + 0x1A, 0x14, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_15, 0xC, -6, 0x68, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_READ_POSTCARD:
                    set_window_properties(WINDOW_ID_14, posX, posY, 0x95, (D_8010D656 * 13) + 0x1A, 0x14, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_15, 6, -6, 0x8B, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_SHOW);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_HIDE);
                    break;
                case POPUP_MENU_POST_OFFICE:
                    set_window_properties(WINDOW_ID_14, posX, posY, 0x83, (D_8010D656 * 13) + 0x1A, 0x14, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(WINDOW_ID_17, 0xA, -6, 0x72, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    set_window_update(WINDOW_ID_15, WINDOW_UPDATE_HIDE);
                    set_window_update(WINDOW_ID_17, WINDOW_UPDATE_SHOW);
                    break;
            }

            switch (gPopupMenu->popupType) {
                case POPUP_MENU_TRADE_FOR_BADGE:
                    set_window_properties(WINDOW_ID_16, 0x7E, -0xE, 0x20, 0x20, 0x15, func_800F4C6C, NULL, 0xE);
                    break;
                case POPUP_MENU_SELL_ITEM:
                    set_window_properties(WINDOW_ID_16, 0x83, -0xE, 0x20, 0x20, 0x15, func_800F4C6C, NULL, 0xE);
                    break;
            }

            if (gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE) {
                set_window_properties(WINDOW_ID_20, D_8010D688, D_8010D68A, 0x40, 0x14, 0x15, func_800F4D28, NULL, -1);
            }

            do {
                cond = FALSE;
                if (D_8010D648 >= D_8010D654 + D_8010D655 - 1) {
                    D_8010D654++;
                    if (D_8010D654 > gPopupMenu->numEntries - D_8010D68F) {
                        D_8010D654 = gPopupMenu->numEntries - D_8010D68F;
                        if (D_8010D654 < 0) {
                            D_8010D654 = 0;
                        }
                    } else {
                        cond = TRUE;
                    }
                }
            } while (cond);

            D_8010D655 = D_8010D654 + D_8010D68F;
            D_8010D658 = -D_8010D654 * 13;
            if (gPopupMenu->popupType >= POPUP_MENU_USE_ITEM
                && (gPopupMenu->popupType < POPUP_MENU_READ_DIARY_PAGE || gPopupMenu->popupType == POPUP_MENU_USEKEY))
            {
                set_window_properties(WINDOW_ID_19, D_8010D680, D_8010D682, 0x118, 0x20, 0x14, func_800F48F4, NULL, -1);
            }

            posX = D_8010D684;
            posY = D_8010D686;
            switch (gPopupMenu->popupType) {
                case POPUP_MENU_USE_ITEM:
                case POPUP_MENU_CHECK_ITEM:
                case POPUP_MENU_CLAIM_ITEM:
                case POPUP_MENU_TAKE_FROM_CHEST:
                case POPUP_MENU_USEKEY:
                    set_window_properties(WINDOW_ID_21, posX, posY, 0x90, 0x20, 0x14, func_800F4944, NULL, -1);
                    break;
                case POPUP_MENU_SWITCH_PARTNER:
                case POPUP_MENU_THROW_AWAY_ITEM:
                case POPUP_MENU_POST_OFFICE:
                    set_window_properties(WINDOW_ID_21, posX, posY, 0x90, 0x28, 0x14, func_800F4944, NULL, -1);
                    break;
                case POPUP_MENU_TRADE_FOR_BADGE:
                case POPUP_MENU_READ_DIARY_PAGE:
                case POPUP_MENU_READ_POSTCARD:
                    set_window_properties(WINDOW_ID_21, posX, posY, 0x80, 0x28, 0x14, func_800F4944, NULL, -1);
                    break;
                case POPUP_MENU_UPGRADE_PARTNER:
                    set_window_properties(WINDOW_ID_21, posX, posY, 0x88, 0x28, 0x14, func_800F4944, NULL, -1);
                    break;
                case POPUP_MENU_READ_LETTER:
                    set_window_properties(WINDOW_ID_21, posX, posY, 0x70, 0x28, 0x14, func_800F4944, NULL, -1);
                    break;
                case POPUP_MENU_SELL_ITEM:
                    set_window_properties(WINDOW_ID_21, posX, posY, 0x78, 0x20, 0x14, func_800F4944, NULL, -1);
                    break;
            }

            if (!D_8010D68E) {
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
                        sfx_play_sound(SOUND_1);
                        set_window_update(WINDOW_ID_19, (s32)basic_window_update);
                        break;
                    case POPUP_MENU_SWITCH_PARTNER:
                    case POPUP_MENU_UPGRADE_PARTNER:
                        set_window_update(WINDOW_ID_14, (s32)basic_window_update);
                        sfx_play_sound(SOUND_2);
                        set_window_update(WINDOW_ID_19, (s32)basic_window_update);
                        break;
                    case POPUP_MENU_READ_DIARY_PAGE:
                    case POPUP_MENU_READ_POSTCARD:
                    case POPUP_MENU_POST_OFFICE:
                        set_window_update(WINDOW_ID_14, (s32)basic_window_update);
                        sfx_play_sound(SOUND_1);
                        break;
                }
                set_window_update(WINDOW_ID_21, WINDOW_UPDATE_SHOW);
            }

            if (gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE) {
                set_window_update(WINDOW_ID_16, (s32)basic_window_update);
                set_window_update(WINDOW_ID_20, (s32)basic_window_update);
            }
            if (gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
                set_window_update(WINDOW_ID_18, (s32)basic_window_update);
            }
            if (gPopupMenu->popupType == POPUP_MENU_SELL_ITEM) {
                set_window_update(WINDOW_ID_16, (s32)basic_window_update);
            }
            D_8010D640 = 1;
            break;
        case 1:
            if (D_8010D644 != 0) {
                D_8010D644--;
            } else {
                D_8010D64C = D_8010D648;

                if (gGameStatusPtr->heldButtons[0] & (BUTTON_STICK_UP | BUTTON_Z) &&
                    (D_8010D648 > 0 || (gGameStatusPtr->pressedButtons[0] & (BUTTON_STICK_UP | BUTTON_Z))))
                {
                    do {
                        D_8010D648--;
                    } while (0); // required to match
                }

                if (gGameStatusPtr->heldButtons[0] & (BUTTON_STICK_DOWN | BUTTON_R) &&
                    ((D_8010D648 < gPopupMenu->numEntries - 1) || (gGameStatusPtr->pressedButtons[0] & (BUTTON_STICK_DOWN | BUTTON_R))))
                {
                    do {
                        D_8010D648++;
                    } while (0); // required to match
                }

                if (D_8010D648 < 0) {
                    D_8010D648 = gPopupMenu->numEntries - 1;
                }
                if (D_8010D648 > gPopupMenu->numEntries - 1) {
                    D_8010D648 = 0;
                }

                if (D_8010D64C != D_8010D648) {
                    sfx_play_sound(SOUND_MENU_CHANGE_SELECTION);
                }

                for (i = 0; i < 4; i++) {
                    if (D_8010D648 < D_8010D654 + 1) {
                        D_8010D654--;
                        if (D_8010D654 < 0) {
                            D_8010D654 = 0;
                        }
                    }
                }

                for (i = 0; i < 4; i++) {
                    if (D_8010D648 >= D_8010D655 - 1) {
                        D_8010D654++;
                        if (D_8010D654 > gPopupMenu->numEntries - D_8010D68F) {
                            D_8010D654 = gPopupMenu->numEntries - D_8010D68F;
                            if (D_8010D654 < 0) {
                                D_8010D654 = 0;
                            }
                        }
                    }
                    D_8010D655 = D_8010D654 + D_8010D68F;
                }

                if (gGameStatusPtr->pressedButtons[0] & BUTTON_A) {
                    switch (gPopupMenu->popupType) {
                        case POPUP_MENU_READ_LETTER:
                            sfx_play_sound(SOUND_MENU_NEXT);
                            if (!D_8010D68E) {
                                D_8010D640 = -1;
                            } else {
                                D_8010D640 = -2;
                            }
                            break;
                        case POPUP_MENU_POST_OFFICE:
                            sfx_play_sound(SOUND_MENU_NEXT);
                            if (!D_8010D68E) {
                                D_8010D640 = -1;
                            } else {
                                D_8010D640 = -2;
                            }
                            break;
                        default:
                            if (gPopupMenu->enabled[D_8010D648]) {
                                sfx_play_sound(SOUND_MENU_NEXT);
                                if (!D_8010D68E) {
                                    D_8010D640 = -1;
                                } else {
                                    D_8010D640 = -2;
                                }
                                break;
                            }
                            if (gPopupMenu->popupType == POPUP_MENU_SWITCH_PARTNER) {
                                sfx_play_sound(SOUND_MENU_ERROR);
                                D_8010D640 = 0x1E;
                                break;
                            }
                            if (D_8010D68E && (gPopupMenu->popupType == POPUP_MENU_USE_ITEM || gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE)) {
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
                            if (D_8010D68E) {
                                buttons = BUTTON_B | BUTTON_C_LEFT;
                            } else {
                                buttons = BUTTON_B;
                            }
                            break;
                        case POPUP_MENU_SWITCH_PARTNER:
                        case POPUP_MENU_UPGRADE_PARTNER:
                            if (D_8010D68E) {
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
                        if (D_8010D698 != 0) {
                            if (!D_8010D68E) {
                                D_8010D640 = -3;
                            } else {
                                D_8010D640 = -7;
                            }
                        } else {
                            if (D_8010D699 == 0) {
                                D_8010D640 = 30;
                            } else {
                                D_8010D640 = 100;
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

                    if (D_8010D68E && (gGameStatusPtr->pressedButtons[0] & buttons)) {
                        sfx_play_sound(SOUND_MENU_BACK);
                        D_8010D640 = -6;
                        break;
                    }
                }
            }
            break;
        case -1:
            hud_element_set_tint(D_8010D65C, 160, 160, 160);
            hud_element_set_tint(D_8010D678, 160, 160, 160);
            hud_element_set_tint(D_8010D66C, 160, 160, 160);
            hud_element_set_tint(D_8010D670, 160, 160, 160);
            hud_element_set_tint(D_8010D674, 160, 160, 160);
            hud_element_set_script(D_8010D66C, &HES_HandPointer);
            if (gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE) {
                hud_element_set_tint(D_8010D660, 160, 160, 160);
                hud_element_set_tint(D_8010D664, 160, 160, 160);
            }
            if (gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
                hud_element_set_tint(D_8010D660, 160, 160, 160);
                hud_element_set_tint(D_8010D664, 160, 160, 160);
            }
            if (gPopupMenu->popupType == POPUP_MENU_SWITCH_PARTNER || gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
                hud_element_set_tint(D_8010D668, 160, 160, 160);
            }
            if (gPopupMenu->popupType == POPUP_MENU_SELL_ITEM) {
                hud_element_set_tint(D_8010D660, 160, 160, 160);
            }
            D_8010D690 = MSG_PAL_0D;

            gPopupMenu->result = D_8010D648 + 1;
            return D_8010D648 + 1;
        case -2:
            gPopupMenu->result = D_8010D648 + 1;
            return D_8010D648 + 1;
        case -3:
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
            free_worker(D_8010D694);
            D_8010D640 = -5;
            gPopupMenu->result = 255;
            return 255;
        case -4:
            free_worker(D_8010D694);
            D_8010D640 = -5;
            gPopupMenu->result = 255;
            return 255;
        case -6:
            gPopupMenu->result = -2;
            return 255;
        case -7:
        case -5:
            gPopupMenu->result = 255;
            return 255;
        case 10:
            D_8010D644--;
            if (D_8010D644 == 0) {
                D_8010D640 = 0xB;
                gPopupMenu->result = D_8010D648 + 1;
                return D_8010D648 + 1;
            }
            break;
        case 20:
            D_8010D644++;
            if (D_8010D644 >= D_8010D692) {
                D_8010D640 = 1;
                gPopupMenu->result = D_8010D648 + 1;
                return D_8010D648 + 1;
            }
            break;
        case 30:
            D_8010D640 = 0x1F;
            gPopupMenu->result = -1;
            return 0;
        case 31:
            set_window_update(WINDOW_ID_14, WINDOW_UPDATE_HIDE);
            set_window_update(WINDOW_ID_19, WINDOW_UPDATE_HIDE);
            if (D_8010D68E) {
                set_window_update(WINDOW_ID_21, WINDOW_UPDATE_HIDE);
            }
            width = get_msg_width(0x1D006B, 0) + 23;
            set_window_properties(WINDOW_ID_9, 160 - (width / 2), 0x50, width, 0x28, 0x14, func_800F4CF0, NULL, -1);
            set_window_update(WINDOW_ID_9, WINDOW_UPDATE_SHOW);
            D_8010D644 = 0x3C;
            D_8010D640 = 0x20;
            return 0;
        case 32:
            if (gGameStatusPtr->pressedButtons[0] & (BUTTON_A | BUTTON_B | BUTTON_C_RIGHT)) {
                D_8010D644 = 0;
            }
            if (D_8010D644 != 0) {
                D_8010D644--;
                return 0;
            }
            set_window_update(WINDOW_ID_9, WINDOW_UPDATE_HIDE);
            set_window_update(WINDOW_ID_14, WINDOW_UPDATE_SHOW);
            set_window_update(WINDOW_ID_19, WINDOW_UPDATE_SHOW);
            if (D_8010D68E) {
                set_window_update(WINDOW_ID_21, WINDOW_UPDATE_SHOW);
            }
            D_8010D640 = 1;
            gPopupMenu->result = 0;
            break;
        case 100:
            hud_element_set_tint(D_8010D65C, 160, 160, 160);
            hud_element_set_tint(D_8010D678, 160, 160, 160);
            hud_element_set_tint(D_8010D66C, 160, 160, 160);
            hud_element_set_tint(D_8010D670, 160, 160, 160);
            hud_element_set_tint(D_8010D674, 160, 160, 160);
            hud_element_set_script(D_8010D66C, &HES_HandPointer);

            if (gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE) {
                hud_element_set_tint(D_8010D660, 160, 160, 160);
                hud_element_set_tint(D_8010D664, 160, 160, 160);
            }
            if (gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
                hud_element_set_tint(D_8010D660, 160, 160, 160);
                hud_element_set_tint(D_8010D664, 160, 160, 160);
            }
            if (gPopupMenu->popupType == 1 || gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
                hud_element_set_tint(D_8010D668, 160, 160, 160);
            }
            if (gPopupMenu->popupType == POPUP_MENU_SELL_ITEM) {
                hud_element_set_tint(D_8010D660, 160, 160, 160);
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
            if (D_8010D699 == 1) {
                msgID = 0x1D0068;
            } else {
                msgID = 0x1D0069;
            }
            width = get_msg_width(msgID, 0) + 23;
            set_window_properties(WINDOW_ID_21, 160 - (width / 2), 76, width, 32, 0x13, func_800F4C1C, NULL, -1);
            set_window_update(WINDOW_ID_21, WINDOW_UPDATE_SHOW);
            D_8010D6A0 = msg_get_printer_for_msg(0x1E001D, &D_8010D6A4);
            msg_printer_set_origin_pos(D_8010D6A0, 160, 0x90);
            D_8010D640 = 0x65;
            break;
        case 101:
            if (D_8010D6A4 == 1) {
                set_window_update(WINDOW_ID_21, WINDOW_UPDATE_HIDE);
                switch (D_8010D6A0->currentOption) {
                    case 0:
                        D_8010D640 = 0x66;
                        break;
                    case 1:
                        D_8010D640 = 0x67;
                        break;
                }
            }
            break;
        case 102:
            D_8010D640 = -3;
            break;
        case 103:
            hud_element_set_tint(D_8010D65C, 255, 255, 255);
            hud_element_set_tint(D_8010D678, 255, 255, 255);
            hud_element_set_tint(D_8010D66C, 255, 255, 255);
            hud_element_set_tint(D_8010D670, 255, 255, 255);
            hud_element_set_tint(D_8010D674, 255, 255, 255);
            if (gPopupMenu->popupType == POPUP_MENU_TRADE_FOR_BADGE) {
                hud_element_set_tint(D_8010D660, 160, 160, 160);
                hud_element_set_tint(D_8010D664, 160, 160, 160);
            }
            if (gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
                hud_element_set_tint(D_8010D660, 160, 160, 160);
                hud_element_set_tint(D_8010D664, 160, 160, 160);
            }
            if (gPopupMenu->popupType == 1 || gPopupMenu->popupType == POPUP_MENU_UPGRADE_PARTNER) {
                hud_element_set_tint(D_8010D668, 160, 160, 160);
            }
            if (gPopupMenu->popupType == POPUP_MENU_SELL_ITEM) {
                hud_element_set_tint(D_8010D660, 160, 160, 160);
            }
            hud_element_set_script(D_8010D66C, &HES_HandPointer);

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
            D_8010D640 = 1;
            break;
    }
    gPopupMenu->result = 0;
    return 0;
}

INCLUDE_ASM(s32, "8a860_len_3f30", popup_menu_draw_menu_contents);

void popup_menu_draw_title_contents(
    s32* userData, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening)
{
    switch (gPopupMenu->popupType) {
        case POPUP_MENU_USE_ITEM:
        case POPUP_MENU_THROW_AWAY_ITEM:
        case POPUP_MENU_SELL_ITEM:
        case POPUP_MENU_CHECK_ITEM:
        case POPUP_MENU_CLAIM_ITEM:
            switch (gPopupMenu->unk_31C) {
                case 0:
                    draw_msg(0x1D003F, baseX + 26, baseY + 2, D_8010D650, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
                    break;
                case 1:
                    draw_msg(0x1D0041, baseX + 4, baseY + 2, D_8010D650, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
                    draw_number(gPopupMenu->unk_320, baseX + 94, baseY + 2, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_32, D_8010D650, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
                    draw_number(2, baseX + 114, baseY + 2, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_32, D_8010D650, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
                    break;
                case 2:
                    draw_msg(0x1D0042, baseX + 6, baseY + 2, D_8010D650, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
                    draw_number(gPopupMenu->unk_320, baseX + 94, baseY + 2, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_32, D_8010D650, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
                    draw_number(3, baseX + 114, baseY + 2, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_32, D_8010D650, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
                    break;
            }
            break;
        case POPUP_MENU_TRADE_FOR_BADGE:
            draw_msg(0x1F0032, baseX + 27, baseY + 2, D_8010D650, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
            break;
        case POPUP_MENU_READ_LETTER:
            draw_msg(0x1F0033, baseX + 23, baseY + 2, D_8010D650, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
            break;
        case POPUP_MENU_TAKE_FROM_CHEST:
            draw_msg(0x1D00D7, baseX + 4, baseY + 2, D_8010D650, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
            break;
        case POPUP_MENU_READ_DIARY_PAGE:
            draw_msg(0x1D00CE, baseX + 8, baseY + 2, D_8010D650, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
            break;
        case POPUP_MENU_READ_POSTCARD:
            draw_msg(0x1D00D0, baseX + 6, baseY + 2, D_8010D650, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
            break;
        case POPUP_MENU_USEKEY:
            draw_msg(0x1D003F, baseX + 27, baseY + 2, D_8010D650, MSG_PAL_32, DRAW_MSG_STYLE_MENU);
            break;
        case POPUP_MENU_SWITCH_PARTNER:
        case POPUP_MENU_UPGRADE_PARTNER:
        case POPUP_MENU_POST_OFFICE:
            draw_msg(0x1D003D, baseX + 8, baseY + 2, D_8010D650, MSG_PAL_34, DRAW_MSG_STYLE_MENU);
            break;
    }
}

void func_800F48F4(s32* userData, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    draw_msg(gPopupMenu->descMsg[D_8010D648], baseX + 8, baseY, D_8010D650, D_8010D690, 0);
}

void func_800F4944(s32* userData, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    s32 msgWidth;

    baseY += 7;

    if (D_8010D68E) {
        switch (gPopupMenu->popupType) {
            case POPUP_MENU_USE_ITEM:
                msgWidth = get_msg_width(0x1D0061, 0);
                baseX += 72 - (msgWidth / 2);
                draw_msg(0x1D0061, baseX, baseY, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_SWITCH_PARTNER:
                msgWidth = get_msg_width(0x1D0063, 0);
                baseX += 72 - (msgWidth / 2);
                draw_msg(0x1D0063, baseX, baseY - 4, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_THROW_AWAY_ITEM:
                msgWidth = get_msg_width(0x1D0064, 0);
                baseX += 72 - (msgWidth / 2);
                draw_msg(0x1D0064, baseX, baseY - 4, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_TRADE_FOR_BADGE:
                msgWidth = get_msg_width(0x1D0070, 0);
                baseX += 64 - (msgWidth / 2);
                draw_msg(0x1D0070, baseX, baseY - 4, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_UPGRADE_PARTNER:
                msgWidth = get_msg_width(0x1D006A, 0);
                baseX += 68 - (msgWidth / 2);
                draw_msg(0x1D006A, baseX, baseY - 4, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_SELL_ITEM:
                msgWidth = get_msg_width(0x1D0065, 0);
                baseX += 60 - (msgWidth / 2);
                draw_msg(0x1D0065, baseX, baseY, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_CHECK_ITEM:
                msgWidth = get_msg_width(0x1D0066, 0);
                baseX += 72 - (msgWidth / 2);
                draw_msg(0x1D0066, baseX, baseY, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_CLAIM_ITEM:
                msgWidth = get_msg_width(0x1D0067, 0);
                baseX += 72 - (msgWidth / 2);
                draw_msg(0x1D0067, baseX, baseY, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_POST_OFFICE:
                msgWidth = get_msg_width(0x1D006F, 0);
                baseX += 72 - (msgWidth / 2);
                draw_msg(0x1D006F, baseX, baseY - 4, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_READ_LETTER:
                msgWidth = get_msg_width(0x1D006D, 0);
                baseX += 56 - (msgWidth / 2);
                draw_msg(0x1D006D, baseX, baseY - 4, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_TAKE_FROM_CHEST:
                msgWidth = get_msg_width(0x1D00D6, 0);
                baseX += 72 - (msgWidth / 2);
                draw_msg(0x1D00D6, baseX, baseY, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_READ_DIARY_PAGE:
                msgWidth = get_msg_width(0x1D006C, 0);
                baseX += 64 - (msgWidth / 2);
                draw_msg(0x1D006C, baseX, baseY - 4, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_READ_POSTCARD:
                msgWidth = get_msg_width(0x1D006D, 0);
                baseX += 64 - (msgWidth / 2);
                draw_msg(0x1D006D, baseX, baseY - 4, 255, MSG_PAL_0F, 0);
                break;
            case POPUP_MENU_USEKEY:
                msgWidth = get_msg_width(0x1D0062, 0);
                baseX += 72 - (msgWidth / 2);
                draw_msg(0x1D0062, baseX, baseY, 255, MSG_PAL_0F, 0);
                break;
        }
    }
}

void func_800F4C1C(PopupMessage* popup, s32 x, s32 y) {
    s32 msg = 0x1D0069;
    s32 xPos = x + 11;
    s32 yPos = y + 8;

    if (D_8010D699 == 1) {
        msg = 0x1D0068;
    }
    draw_msg(msg, xPos, yPos, 255, MSG_PAL_0F, 0);
}

void func_800F4C6C(PopupMessage* popup, s32 x, s32 y) {
    s32 hudElement;
    s32 xPos;
    s32 yPos;

    switch (gPopupMenu->popupType) {
        case POPUP_TYPE_TRADE_FOR_BADGE:
            xPos = x + 16;
            hudElement = D_8010D660;
            yPos = y + 16;
            break;
        case POPUP_TYPE_SELL_ITEM:
            xPos = x + 17;
            hudElement = D_8010D660;
            yPos = y + 17;
            break;
        default:
            return;
    }

    hud_element_set_render_pos(hudElement, xPos, yPos);
    hud_element_set_alpha(hudElement, D_8010D650);
    hud_element_draw_clipped(hudElement);
}

void func_800F4CF0(PopupMessage* popup, s32 x, s32 y) {
    draw_msg(0x1D006B, x + 16, y + 2, 255, MSG_PAL_0F, 0);
}

void func_800F4D28(PopupMessage* popup, s32 x, s32 y) {
    s32 hudElement = D_8010D660;
    PlayerData* playerData = &gPlayerData;
    s32 xPos = x + 14;
    s32 yPos = y + 9;
    s32 type;

    hud_element_set_alpha(hudElement, D_8010D650);

    if (gPopupMenu->popupType == POPUP_TYPE_TRADE_FOR_BADGE) {
        hud_element_set_render_pos(hudElement, xPos, yPos);
    } else {
        hud_element_set_render_pos(hudElement, xPos, y + 10);
    }

    hud_element_draw_clipped(hudElement);
    hudElement = D_8010D664;
    hud_element_set_render_pos(hudElement, x + 26, y + 11);
    hud_element_set_alpha(hudElement, D_8010D650);
    hud_element_draw_clipped(hudElement);

    type = gPopupMenu->popupType;
    if (type == POPUP_TYPE_TRADE_FOR_BADGE) {
        draw_number(playerData->starPieces, x + 58, y + 4, DRAW_NUMBER_CHARSET_THIN, MSG_PAL_STANDARD, D_8010D650, DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT);
    }
}

void create_popup_menu(PopupMenu* popup) {
    PopupMenu* otherPopup;
    s8 entryCount;
    s32 initialPos;
    s32 numEntries;

    D_8010D69A = func_800E98D4();
    status_menu_ignore_changes();
    open_status_menu_short();
    gPopupMenu = popup;
    popup->result = 0;
    popup->unk_31C = 0;
    popup->unk_320 = 0;
    D_8010D699 = 0;
    D_8010D698 = 1;
    if (popup->popupType >= 100) {
        popup->popupType -= 100;
        D_8010D699 = 1;
        if (popup->popupType >= 100) {
            popup->popupType -= 100;
            D_8010D699 = 2;
        }
        D_8010D698 = 0;
    }

    D_8010D68E = TRUE;
    D_8010D68F = 6;
    D_8010D640 = 0;

    initialPos = gPopupMenu->initialPos;
    numEntries = gPopupMenu->numEntries;
    D_8010D648 = initialPos;
    if (initialPos >= numEntries) {
        D_8010D648 = numEntries - 1;
    }
    D_8010D654 = 0;
    D_8010D64C = D_8010D648;

    entryCount = gPopupMenu->numEntries;
    D_8010D656 = entryCount;
    if (D_8010D68F < entryCount) {
        D_8010D656 = 6;
    }

    D_8010D655 = 6;
    if (gPopupMenu->numEntries < D_8010D68F) {
        D_8010D655 = gPopupMenu->numEntries;
    }

    D_8010D650 = 255;
    D_8010D691 = 4;
    D_8010D692 = 6;
    D_8010D694 = create_worker_frontUI(popup_menu_update, NULL);
}

void func_800F4FC4(PopupMenu* popup) {
    gPopupMenu = popup;

    popup->result = 0;
    popup->unk_31C = 0;
    popup->unk_320 = 0;
    D_8010D69A = func_800E98D4();
    D_8010D699 = 0;
    D_8010D698 = 1;
    if (gPopupMenu->popupType >= 100) {
        gPopupMenu->popupType -= 100;
        D_8010D699 = 1;
        if (gPopupMenu->popupType >= 100) {
            gPopupMenu->popupType -= 100;
            D_8010D699 = 2;
        }
        D_8010D698 = 0;
    }

    D_8010D68E = TRUE;
    D_8010D68F = 6;
    D_8010D640 = 0;
    D_8010D648 = gPopupMenu->initialPos;
    if (D_8010D648 >= gPopupMenu->numEntries) {
        D_8010D648 = gPopupMenu->numEntries - 1;
    }
    D_8010D654 = 0;
    D_8010D64C = D_8010D648;
    D_8010D656 = gPopupMenu->numEntries;

    if (D_8010D656 > D_8010D68F) {
        D_8010D656 = D_8010D68F;
    }

    D_8010D655 = D_8010D68F;
    if (gPopupMenu->numEntries < D_8010D68F) {
        D_8010D655 = gPopupMenu->numEntries;
    }

    D_8010D650 = 255;
    D_8010D691 = 4;
    D_8010D692 = 6;
    D_8010D694 = create_worker_frontUI(popup_menu_update, NULL);
}

void func_800F513C(PopupMenu* popup) {
    gPopupMenu = popup;

    popup->result = 0;
    D_8010D693 = popup->unk_320;
    D_8010D69A = func_800E98D4();
    D_8010D699 = 0;
    D_8010D698 = 1;
    if (gPopupMenu->popupType >= 100) {
        gPopupMenu->popupType -= 100;
        D_8010D699 = 1;
        if (gPopupMenu->popupType >= 100) {
            gPopupMenu->popupType -= 100;
            D_8010D699 = 2;
        }
        D_8010D698 = 0;
    }

    D_8010D68F = 6;
    D_8010D68E = FALSE;
    D_8010D640 = 0;
    D_8010D648 = gPopupMenu->initialPos;
    if (D_8010D648 >= gPopupMenu->numEntries) {
        D_8010D648 = gPopupMenu->numEntries - 1;
    }
    D_8010D654 = 0;
    D_8010D64C = D_8010D648;
    D_8010D656 = gPopupMenu->numEntries;

    if (D_8010D656 > D_8010D68F) {
        D_8010D656 = D_8010D68F;
    }

    D_8010D655 = D_8010D68F;
    if (gPopupMenu->numEntries < D_8010D68F) {
        D_8010D655 = gPopupMenu->numEntries;
    }

    D_8010D650 = 255;
    D_8010D691 = 9;
    D_8010D692 = 2;
    D_8010D694 = create_worker_frontUI(popup_menu_update, NULL);
}

void func_800F52BC(void) {
    popup_menu_update();
}
