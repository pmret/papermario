#include "common.h"
#include "hud_element.h"

extern s32 D_8010D650;
extern s32 D_8010D660;
extern s32 D_8010D664;
extern s8 D_8010D699;
extern PopupMenu* D_8010D69C;
extern s32 D_8010D640;
extern s32 D_8010D65C;
extern s32 D_8010D668;
extern s32 D_8010D66C;
extern s32 D_8010D670;
extern s32 D_8010D674;
extern s32 D_8010D678;
extern s8 D_8010D69A;
extern s32 D_8010D648;
extern s32 D_8010D64C;
extern s8 D_8010D654;
extern u8 D_8010D655;
extern u8 D_8010D656;
extern s8 D_8010D68E;
extern s8 D_8010D68F;
extern s8 D_8010D691;
extern s8 D_8010D692;
extern s32 D_8010D694;
extern s8 D_8010D698;
void func_800E9894(void);
s8 func_800E98D4(void);
void open_status_menu_short(void);
void func_800E98C4(void);

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

INCLUDE_ASM(s32, "8a860_len_3f30", hide_popup_menu);

void destroy_popup_menu(void) {
    free_hud_element(D_8010D65C);
    free_hud_element(D_8010D678);
    free_hud_element(D_8010D66C);
    free_hud_element(D_8010D670);
    free_hud_element(D_8010D674);

    if (D_8010D69C->popupType == POPUP_TYPE_TRADE_FOR_BADGE) {
        free_hud_element(D_8010D660);
        free_hud_element(D_8010D664);
    }

    if (D_8010D69C->popupType == POPUP_TYPE_UPGRADE_PARTNER) {
        free_hud_element(D_8010D660);
        free_hud_element(D_8010D664);
    }

    if (D_8010D69C->popupType == POPUP_TYPE_SWITCH_PARTNER || D_8010D69C->popupType == POPUP_TYPE_UPGRADE_PARTNER) {
        free_hud_element(D_8010D668);
    }

    if (D_8010D69C->popupType == POPUP_TYPE_SELL_ITEM) {
        free_hud_element(D_8010D660);
    }

    if ((D_8010D69C->popupType <= POPUP_TYPE_USE_ITEM ||
         D_8010D69C->popupType == POPUP_TYPE_SWITCH_PARTNER ||
         D_8010D69C->popupType == POPUP_TYPE_THROW_AWAY_ITEM ||
         D_8010D69C->popupType == POPUP_TYPE_TRADE_FOR_BADGE ||
         D_8010D69C->popupType == POPUP_TYPE_UPGRADE_PARTNER ||
         D_8010D69C->popupType == POPUP_TYPE_USE_KEY
        ) && !gGameStatusPtr->isBattle) {
        if (D_8010D69A == 0) {
            func_800E98C4();
        }
        close_status_menu();
    }

    D_8010D640 = -4;
}

INCLUDE_ASM(s32, "8a860_len_3f30", func_800F16CC);

void popup_menu_update(void);
INCLUDE_ASM(s32, "8a860_len_3f30", popup_menu_update);

INCLUDE_ASM(s32, "8a860_len_3f30", popup_menu_draw_menu_contents);

INCLUDE_ASM(s32, "8a860_len_3f30", popup_menu_draw_title_contents);

INCLUDE_ASM(s32, "8a860_len_3f30", func_800F48F4);

INCLUDE_ASM(s32, "8a860_len_3f30", func_800F4944);

void func_800F4C1C(PopupMessage* popup, s32 x, s32 y) {
    s32 msg = 0x1D0069;
    s32 xPos = x + 11;
    s32 yPos = y + 8;

    if (D_8010D699 == 1) {
        msg = 0x1D0068;
    }
    draw_msg(msg, xPos, yPos, 255, 15, 0);
}

void func_800F4C6C(PopupMessage* popup, s32 x, s32 y) {
    s32 hudElement;
    s32 xPos;
    s32 yPos;

    switch (D_8010D69C->popupType) {
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

    set_hud_element_render_pos(hudElement, xPos, yPos);
    set_hud_element_alpha(hudElement, D_8010D650);
    draw_hud_element_clipped(hudElement);
}

void func_800F4CF0(PopupMessage* popup, s32 x, s32 y) {
    draw_msg(0x1D006B, x + 16, y + 2, 255, 15, 0);
}

void func_800F4D28(PopupMessage* popup, s32 x, s32 y) {
    s32 hudElement = D_8010D660;
    PlayerData* playerData = &gPlayerData;
    s32 xPos = x + 14;
    s32 yPos = y + 9;
    s32 type;

    set_hud_element_alpha(hudElement, D_8010D650);

    if (D_8010D69C->popupType == POPUP_TYPE_TRADE_FOR_BADGE) {
        set_hud_element_render_pos(hudElement, xPos, yPos);
    } else {
        set_hud_element_render_pos(hudElement, xPos, y + 10);
    }

    draw_hud_element_clipped(hudElement);
    hudElement = D_8010D664;
    set_hud_element_render_pos(hudElement, x + 26, y + 11);
    set_hud_element_alpha(hudElement, D_8010D650);
    draw_hud_element_clipped(hudElement);

    type = D_8010D69C->popupType;
    if (type == POPUP_TYPE_TRADE_FOR_BADGE) {
        draw_number(playerData->starPieces, x + 58, y + 4, 1, 10, D_8010D650, type);
    }
}

#ifdef NON_EQUIVALENT
void create_popup_menu(PopupMenu* popup) {
    PopupMenu* otherPopup;
    s8 entryCount;

    D_8010D69A = func_800E98D4();
    func_800E9894();
    open_status_menu_short();
    D_8010D69C = popup;
    popup->result = 0;
    popup->unk_31C = 0;
    popup->unk_320 = 0;
    D_8010D699 = 0;
    D_8010D698 = 1;
    if (popup->popupType >= 0x64) {
        popup->popupType -= 0x64;
        D_8010D699 = 1;
        if (popup->popupType >= 0x64) {
            popup->popupType -= 0x64;
            D_8010D699 = 2;
        }
        D_8010D698 = 0;
    }
    otherPopup = D_8010D69C;
    D_8010D68E = 1;
    D_8010D640 = 0;
    D_8010D648 = otherPopup->initialPos;
    if (otherPopup->initialPos >= otherPopup->numEntries) {
        D_8010D648 = otherPopup->numEntries - 1;
    }
    D_8010D68F = 6;
    D_8010D654 = 0;
    D_8010D64C = D_8010D648;
    entryCount = otherPopup->numEntries;

    D_8010D656 = entryCount;
    if (entryCount > 6) {
        D_8010D656 = 6;
    }
    D_8010D655 = 6;
    if (temp_a1->numEntries < 6) {
        D_8010D655 = temp_a1->numEntries;
    }
    D_8010D650 = 255;
    D_8010D691 = 4;
    D_8010D692 = 6;
    D_8010D694 = create_generic_entity_frontUI(popup_menu_update, NULL);
}
#else
INCLUDE_ASM(void, "8a860_len_3f30", create_popup_menu, PopupMenu* popup);
#endif

INCLUDE_ASM(s32, "8a860_len_3f30", func_800F4FC4);

INCLUDE_ASM(s32, "8a860_len_3f30", func_800F513C);

void func_800F52BC(void) {
    popup_menu_update();
}
