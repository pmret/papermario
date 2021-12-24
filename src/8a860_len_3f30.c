#include "common.h"
#include "hud_element.h"

extern s32 D_80104A00[0];
extern s32 D_80104C10[0];
extern s32 D_80107798[0];
extern s32 D_801077E4[0];
extern s32 D_8010790C[0];
extern s32 D_80109298;
extern s32 D_801092C0;
extern s32 D_801092E8;
extern s32 D_80109310;

extern s32 D_80109890[] = { &D_80109298, &D_801092E8 };
extern s32 D_80109898[] = { &D_801092C0, &D_80109310 };
extern s16 D_801098A0[] = {
    0x008C, 0x008C, 0x008D, 0x007C, 0x0086, 0x0077, 0x008D, 0x008D, 0x006C, 0x008D, 0x0084, 0x0084, 0x008D, 0x008C,
};
extern s16 D_801098BC[] = {
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
extern u8 D_8010D656;
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
extern s8 D_8010D68E;
extern s8 D_8010D68F;
extern s8 D_8010D690;
extern s8 D_8010D691;
extern s8 D_8010D692;
extern s32 D_8010D694;
extern s8 D_8010D698;
extern s8 D_8010D699;
extern s8 D_8010D69A;
extern PopupMenu* gPopupMenu;
extern MessagePrintState* D_8010D6A0;
extern s32 D_8010D6A4;

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

void popup_menu_draw_menu_contents(s32* userData, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void popup_menu_draw_title_contents(s32* userData, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void func_800F48F4(s32* userData, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void func_800F4944(s32* userData, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void func_800F4C1C(PopupMessage* popup, s32 x, s32 y);
void func_800F4C6C(PopupMessage* popup, s32 x, s32 y);
void func_800F4CF0(PopupMessage* popup, s32 x, s32 y);
void func_800F4D28(PopupMessage* popup, s32 x, s32 y);

INCLUDE_ASM(s32, "8a860_len_3f30", hide_popup_menu);

void destroy_popup_menu(void) {
    free_hud_element(D_8010D65C);
    free_hud_element(D_8010D678);
    free_hud_element(D_8010D66C);
    free_hud_element(D_8010D670);
    free_hud_element(D_8010D674);

    if (gPopupMenu->popupType == POPUP_TYPE_TRADE_FOR_BADGE) {
        free_hud_element(D_8010D660);
        free_hud_element(D_8010D664);
    }

    if (gPopupMenu->popupType == POPUP_TYPE_UPGRADE_PARTNER) {
        free_hud_element(D_8010D660);
        free_hud_element(D_8010D664);
    }

    if (gPopupMenu->popupType == POPUP_TYPE_SWITCH_PARTNER || gPopupMenu->popupType == POPUP_TYPE_UPGRADE_PARTNER) {
        free_hud_element(D_8010D668);
    }

    if (gPopupMenu->popupType == POPUP_TYPE_SELL_ITEM) {
        free_hud_element(D_8010D660);
    }

    if ((gPopupMenu->popupType <= POPUP_TYPE_USE_ITEM ||
         gPopupMenu->popupType == POPUP_TYPE_SWITCH_PARTNER ||
         gPopupMenu->popupType == POPUP_TYPE_THROW_AWAY_ITEM ||
         gPopupMenu->popupType == POPUP_TYPE_TRADE_FOR_BADGE ||
         gPopupMenu->popupType == POPUP_TYPE_UPGRADE_PARTNER ||
         gPopupMenu->popupType == POPUP_TYPE_USE_KEY
        ) && !gGameStatusPtr->isBattle) {
        if (D_8010D69A == 0) {
            func_800E98C4();
        }
        close_status_menu();
    }

    D_8010D640 = -4;
}

INCLUDE_ASM(s32, "8a860_len_3f30", func_800F16CC);

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
            if (D_8010D68E != 0) {
                D_8010D67C = D_801098A0[gPopupMenu->popupType] + 20;
            }
            if (D_8010D68F >= 7) {
                D_8010D67E = 62;
            }
            D_8010D68C = 0;
            elementID = create_hud_element(D_8010790C);
            D_8010D65C = elementID;
            set_hud_element_flags(elementID, 0x80);
            set_hud_element_tint(elementID, 255, 255, 255);
            if (gPopupMenu->popupType != 2) {
                set_hud_element_flags(elementID, 2);
            }

            one = 1; // required to match (why is 1 loaded so early?)
            elementID = create_hud_element(gPopupMenu->ptrIcon[0]);
            D_8010D678 = elementID;
            set_hud_element_scale(elementID, 0.45f);
            set_hud_element_flags(elementID, 0x8080);

            elementID = create_hud_element(D_80104A28);
            D_8010D66C = elementID;
            set_hud_element_flags(elementID, 0x20000080);

            elementID = create_hud_element(D_801077E4);
            D_8010D670 = elementID;
            set_hud_element_flags(elementID, 0x20000080);

            elementID = create_hud_element(D_80107798);
            D_8010D674 = elementID;
            set_hud_element_flags(elementID, 0x20000080);

            if (gPopupMenu->popupType == 3) {
                D_8010D660 = create_hud_element(D_80104C10);
                elementID = D_8010D660;
                set_hud_element_flags(elementID, 0x80);
                set_hud_element_tint(elementID, 255, 255, 255);
            }
            if (gPopupMenu->popupType == 4) {
                D_8010D660 = create_hud_element(D_80104C10);
                elementID = D_8010D660;
                set_hud_element_flags(elementID, 0x8080);
                set_hud_element_tint(elementID, 255, 255, 255);
            }
            if (gPopupMenu->popupType == 5) {
                D_8010D660 = create_hud_element(&D_80108558);
                elementID = D_8010D660;
                set_hud_element_flags(elementID, 0x80);
                set_hud_element_tint(elementID, 255, 255, 255);
            }
            if (gPopupMenu->popupType == 3 || gPopupMenu->popupType == 4) {
                D_8010D664 = create_hud_element(&D_80109270);
                elementID = D_8010D664;
                set_hud_element_flags(elementID, 0x80);
                set_hud_element_tint(elementID, 255, 255, 255);
            }
            if (gPopupMenu->popupType == one || gPopupMenu->popupType == 4) {
                D_8010D668 = create_hud_element(D_80109890[0]);
                elementID = D_8010D668;
                set_hud_element_flags(elementID, 0x80);
                set_hud_element_tint(elementID, 255, 255, 255);
            }

            D_8010D65A = -200;
            D_8010D644 = D_8010D691;
            if (D_8010D68E == 0) {
                D_8010D644 = 1;
            }
            D_8010D690 = 0xA;

            posX = D_8010D67C;
            posY = D_8010D67E;
            switch (gPopupMenu->popupType) {
                case 0:
                case 2:
                case 6:
                case 7:
                case 12:
                    set_window_properties(0xE, posX, posY, 0x91, ((s8) D_8010D656 * 0xD) + 0x1A, 0x14, popup_menu_draw_menu_contents, NULL, -1);
                    if (gPopupMenu->unk_31C == 0) {
                        set_window_properties(0xF, 0x19, -6, 0x5F, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    } else {
                        set_window_properties(0xF, 0xC, -6, 0x79, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    }
                    set_window_update(0xF, 1);
                    set_window_update(0x11, 2);
                    break;
                case 1:
                    set_window_properties(0xE, posX, posY, 0x8B, ((s8) D_8010D656 * 0xD) + 0x1A, 0x14, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(0x11, 0xD, -6, 0x72, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    set_window_update(0xF, 2);
                    set_window_update(0x11, 1);
                    break;
                case 3:
                    set_window_properties(0xE, posX, posY, 0xA2, ((s8) D_8010D656 * 0xD) + 0x1A, 0x14, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(0xF, 0x11, -6, 0x60, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    set_window_update(0xF, 1);
                    set_window_update(0x11, 2);
                    break;
                case 4:
                    set_window_properties(0xE, posX, posY, 0x92, ((s8) D_8010D656 * 0xD) + 0x1A, 0x14, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(0x11, 0xC, -6, 0x72, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    set_window_update(0xF, 2);
                    set_window_update(0x11, 1);
                    break;
                case 5:
                    set_window_properties(0xE, posX, posY, 0xA7, ((s8) D_8010D656 * 0xD) + 0x1A, 0x14, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(0xF, 0x16, -6, 0x5F, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    set_window_update(0xF, 1);
                    set_window_update(0x11, 2);
                    break;
                case 8:
                    set_window_properties(0xE, posX, posY, 0xAA, ((s8) D_8010D656 * 0xD) + 0x1A, 0x14, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(0xF, 0x20, -6, 0x68, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    set_window_update(0xF, 1);
                    set_window_update(0x11, 2);
                    break;
                case 9:
                    set_window_properties(0xE, posX, posY, 0x91, ((s8) D_8010D656 * 0xD) + 0x1A, 0x14, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(0xF, 0xC, -6, 0x79, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    set_window_update(0xF, 1);
                    set_window_update(0x11, 2);
                    break;
                case 10:
                    set_window_properties(0xE, posX, posY, 0x80, ((s8) D_8010D656 * 0xD) + 0x1A, 0x14, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(0xF, 0xC, -6, 0x68, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    set_window_update(0xF, 1);
                    set_window_update(0x11, 2);
                    break;
                case 11:
                    set_window_properties(0xE, posX, posY, 0x95, ((s8) D_8010D656 * 0xD) + 0x1A, 0x14, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(0xF, 6, -6, 0x8B, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    set_window_update(0xF, 1);
                    set_window_update(0x11, 2);
                    break;
                case 13:
                    set_window_properties(0xE, posX, posY, 0x83, ((s8) D_8010D656 * 0xD) + 0x1A, 0x14, popup_menu_draw_menu_contents, NULL, -1);
                    set_window_properties(0x11, 0xA, -6, 0x72, 0x10, 0x15, popup_menu_draw_title_contents, NULL, 0xE);
                    set_window_update(0xF, 2);
                    set_window_update(0x11, 1);
                    break;
            }

            switch (gPopupMenu->popupType) {
                case 3:
                    set_window_properties(0x10, 0x7E, -0xE, 0x20, 0x20, 0x15, func_800F4C6C, NULL, 0xE);
                    break;
                case 5:
                    set_window_properties(0x10, 0x83, -0xE, 0x20, 0x20, 0x15, func_800F4C6C, NULL, 0xE);
                    break;
            }

            if (gPopupMenu->popupType == 3) {
                set_window_properties(0x14, D_8010D688, D_8010D68A, 0x40, 0x14, 0x15, func_800F4D28, NULL, -1);
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
            D_8010D658 = -D_8010D654 * 0xD;
            if (gPopupMenu->popupType >= 0 && (gPopupMenu->popupType < 0xA || gPopupMenu->popupType == 0xC)) {
                set_window_properties(0x13, D_8010D680, D_8010D682, 0x118, 0x20, 0x14, func_800F48F4, NULL, -1);
            }

            posX = D_8010D684;
            posY = D_8010D686;
            switch (gPopupMenu->popupType) {
                case 0:
                case 6:
                case 7:
                case 9:
                case 12:
                    set_window_properties(0x15, posX, posY, 0x90, 0x20, 0x14, func_800F4944, NULL, -1);
                    break;
                case 1:
                case 2:
                case 13:
                    set_window_properties(0x15, posX, posY, 0x90, 0x28, 0x14, func_800F4944, NULL, -1);
                    break;
                case 3:
                case 10:
                case 11:
                    set_window_properties(0x15, posX, posY, 0x80, 0x28, 0x14, func_800F4944, NULL, -1);
                    break;
                case 4:
                    set_window_properties(0x15, posX, posY, 0x88, 0x28, 0x14, func_800F4944, NULL, -1);
                    break;
                case 8:
                    set_window_properties(0x15, posX, posY, 0x70, 0x28, 0x14, func_800F4944, NULL, -1);
                    break;
                case 5:
                    set_window_properties(0x15, posX, posY, 0x78, 0x20, 0x14, func_800F4944, NULL, -1);
                    break;
            }

            if (D_8010D68E == 0) {
                switch (gPopupMenu->popupType) {
                    case 0:
                    case 2:
                    case 3:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                    case 9:
                    case 12:
                        set_window_update(0xE, 1);
                        set_window_update(0x13, 1);
                        break;
                    case 1:
                    case 4:
                        set_window_update(0xE, 1);
                        set_window_update(0x13, 1);
                        break;
                    case 10:
                    case 11:
                    case 13:
                        set_window_update(0xE, 1);
                        break;
                }
            } else {
                switch (gPopupMenu->popupType) {
                    case 0:
                    case 2:
                    case 3:
                    case 5:
                    case 6:
                    case 7:
                    case 8:
                    case 9:
                    case 12:
                        set_window_update(0xE, basic_window_update);
                        sfx_play_sound(1);
                        set_window_update(0x13, basic_window_update);
                        break;
                    case 1:
                    case 4:
                        set_window_update(0xE, basic_window_update);
                        sfx_play_sound(2);
                        set_window_update(0x13, basic_window_update);
                        break;
                    case 10:
                    case 11:
                    case 13:
                        set_window_update(0xE, basic_window_update);
                        sfx_play_sound(1);
                        break;
                }
                set_window_update(0x15, 1);
            }

            if (gPopupMenu->popupType == 3) {
                set_window_update(0x10, basic_window_update);
                set_window_update(0x14, basic_window_update);
            }
            if (gPopupMenu->popupType == 4) {
                set_window_update(0x12, basic_window_update);
            }
            if (gPopupMenu->popupType == 5) {
                set_window_update(0x10, basic_window_update);
            }
            D_8010D640 = 1;
            break;
        case 1:
            if (D_8010D644 != 0) {
                D_8010D644--;
            } else {
                D_8010D64C = D_8010D648;

                if (gGameStatusPtr->heldButtons & (BUTTON_STICK_UP | BUTTON_Z) &&
                    (D_8010D648 > 0 || (gGameStatusPtr->pressedButtons & 0x12000)))
                {
                    do {
                        D_8010D648--;
                    } while (0); // required to match
                }

                if (gGameStatusPtr->heldButtons & (BUTTON_STICK_DOWN | BUTTON_R) &&
                    ((D_8010D648 < gPopupMenu->numEntries - 1) || (gGameStatusPtr->pressedButtons & (BUTTON_STICK_DOWN | BUTTON_R))))
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
                    sfx_play_sound(0xC7);
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

                if (gGameStatusPtr->pressedButtons & 0x8000) {
                    switch (gPopupMenu->popupType) {
                        case 8:
                            sfx_play_sound(SOUND_MENU_NEXT);
                            if (D_8010D68E == 0) {
                                D_8010D640 = -1;
                            } else {
                                D_8010D640 = -2;
                            }
                            break;
                        case 13:
                            sfx_play_sound(SOUND_MENU_NEXT);
                            if (D_8010D68E == 0) {
                                D_8010D640 = -1;
                            } else {
                                D_8010D640 = -2;
                            }
                            break;
                        default:
                            if (gPopupMenu->enabled[D_8010D648]) {
                                sfx_play_sound(SOUND_MENU_NEXT);
                                if (D_8010D68E == 0) {
                                    D_8010D640 = -1;
                                } else {
                                    D_8010D640 = -2;
                                }
                                break;
                            }
                            if (gPopupMenu->popupType == 1) {
                                sfx_play_sound(SOUND_MENU_BADGE_ERROR);
                                D_8010D640 = 0x1E;
                                break;
                            }
                            if ((D_8010D68E != 0) && (gPopupMenu->popupType == 0 || gPopupMenu->popupType == 3)) {
                                sfx_play_sound(SOUND_MENU_BADGE_ERROR);
                            }
                            break;
                    }
                } else {
                    switch (gPopupMenu->popupType) {
                        case 0:
                        case 2:
                        case 3:
                        case 5:
                        case 6:
                        case 7:
                        case 12:
                            if (D_8010D68E != 0) {
                                buttons = BUTTON_B | BUTTON_C_LEFT;
                            } else {
                                buttons = BUTTON_B;
                            }
                            break;
                        case 1:
                        case 4:
                            if (D_8010D68E != 0) {
                                buttons = BUTTON_B | BUTTON_C_RIGHT;
                            } else {
                                buttons = BUTTON_B;
                            }
                            break;
                        case 8:
                        case 9:
                        case 10:
                        case 11:
                        case 13:
                            buttons = BUTTON_B;
                            break;
                        default:
                            buttons = BUTTON_NONE;
                            break;
                    }

                    if (gGameStatusPtr->pressedButtons & buttons) {
                        sfx_play_sound(0xCA);
                        if (D_8010D698 != 0) {
                            if (D_8010D68E == 0) {
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
                            buttons = BUTTON_NONE;
                            break;
                        case 0:
                            buttons = BUTTON_C_RIGHT;
                            break;
                        case 1:
                            buttons = BUTTON_C_LEFT;
                            break;
                    }

                    if (D_8010D68E != 0 && (gGameStatusPtr->pressedButtons & buttons)) {
                        sfx_play_sound(0xCA);
                        D_8010D640 = -6;
                        break;
                    }
                }
            }
            break;
        case -1:
            set_hud_element_tint(D_8010D65C, 160, 160, 160);
            set_hud_element_tint(D_8010D678, 160, 160, 160);
            set_hud_element_tint(D_8010D66C, 160, 160, 160);
            set_hud_element_tint(D_8010D670, 160, 160, 160);
            set_hud_element_tint(D_8010D674, 160, 160, 160);
            set_hud_element_anim(D_8010D66C, D_80104A00);
            if (gPopupMenu->popupType == 3) {
                set_hud_element_tint(D_8010D660, 160, 160, 160);
                set_hud_element_tint(D_8010D664, 160, 160, 160);
            }
            if (gPopupMenu->popupType == 4) {
                set_hud_element_tint(D_8010D660, 160, 160, 160);
                set_hud_element_tint(D_8010D664, 160, 160, 160);
            }
            if (gPopupMenu->popupType == 1 || gPopupMenu->popupType == 4) {
                set_hud_element_tint(D_8010D668, 160, 160, 160);
            }
            if (gPopupMenu->popupType == 5) {
                set_hud_element_tint(D_8010D660, 160, 160, 160);
            }
            D_8010D690 = 0xD;

            gPopupMenu->result = D_8010D648 + 1;
            return D_8010D648 + 1;
        case -2:
            gPopupMenu->result = D_8010D648 + 1;
            return D_8010D648 + 1;
        case -3:
            switch (gPopupMenu->popupType) {
                case 0:
                case 2:
                case 3:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 12:
                    set_window_update(0xE, 2);
                    set_window_update(0x13, 2);
                    break;
                case 1:
                case 4:
                    set_window_update(0xE, 2);
                    set_window_update(0x13, 2);
                    break;
                case 10:
                case 11:
                case 13:
                    set_window_update(0xE, 2);
                    break;
            }
            destroy_popup_menu();
            free_generic_entity(D_8010D694);
            D_8010D640 = -5;
            gPopupMenu->result = 255;
            return 255;
        case -4:
            free_generic_entity(D_8010D694);
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
            set_window_update(0xE, 2);
            set_window_update(0x13, 2);
            if (D_8010D68E != 0) {
                set_window_update(0x15, 2);
            }
            width = get_msg_width(0x1D006B, 0) + 23;
            set_window_properties(9, 160 - (width / 2), 0x50, width, 0x28, 0x14, func_800F4CF0, NULL, -1);
            set_window_update(9, 1);
            D_8010D644 = 0x3C;
            D_8010D640 = 0x20;
            return 0;
        case 32:
            if (gGameStatusPtr->pressedButtons & (BUTTON_A | BUTTON_B | BUTTON_C_RIGHT)) {
                D_8010D644 = 0;
            }
            if (D_8010D644 != 0) {
                D_8010D644--;
                return 0;
            }
            set_window_update(9, 2);
            set_window_update(0xE, 1);
            set_window_update(0x13, 1);
            if (D_8010D68E != 0) {
                set_window_update(0x15, 1);
            }
            D_8010D640 = 1;
            gPopupMenu->result = 0;
            break;
        case 100:
            set_hud_element_tint(D_8010D65C, 160, 160, 160);
            set_hud_element_tint(D_8010D678, 160, 160, 160);
            set_hud_element_tint(D_8010D66C, 160, 160, 160);
            set_hud_element_tint(D_8010D670, 160, 160, 160);
            set_hud_element_tint(D_8010D674, 160, 160, 160);
            set_hud_element_anim(D_8010D66C, D_80104A00);

            if (gPopupMenu->popupType == 3) {
                set_hud_element_tint(D_8010D660, 160, 160, 160);
                set_hud_element_tint(D_8010D664, 160, 160, 160);
            }
            if (gPopupMenu->popupType == 4) {
                set_hud_element_tint(D_8010D660, 160, 160, 160);
                set_hud_element_tint(D_8010D664, 160, 160, 160);
            }
            if (gPopupMenu->popupType == 1 || gPopupMenu->popupType == 4) {
                set_hud_element_tint(D_8010D668, 160, 160, 160);
            }
            if (gPopupMenu->popupType == 5) {
                set_hud_element_tint(D_8010D660, 160, 160, 160);
            }

            switch (gPopupMenu->popupType) {
                case 0:
                case 2:
                case 3:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 12:
                    set_window_update(0xE, 2);
                    set_window_update(0x13, 2);
                    break;
                case 1:
                case 4:
                    set_window_update(0xE, 2);
                    set_window_update(0x13, 2);
                    break;
                case 10:
                case 11:
                case 13:
                    set_window_update(0xE, 2);
                    break;
            }

            D_8010D690 = 0xD;
            if (D_8010D699 == 1) {
                msgID = 0x1D0068;
            } else {
                msgID = 0x1D0069;
            }
            width = get_msg_width(msgID, 0) + 23;
            set_window_properties(0x15, 160 - (width / 2), 76, width, 32, 0x13, func_800F4C1C, NULL, -1);
            set_window_update(0x15, 1);
            D_8010D6A0 = msg_get_printer_for_msg(0x1E001D, &D_8010D6A4);
            msg_printer_set_origin_pos(D_8010D6A0, 160, 0x90);
            D_8010D640 = 0x65;
            break;
        case 101:
            if (D_8010D6A4 == 1) {
                set_window_update(0x15, 2);
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
            set_hud_element_tint(D_8010D65C, 255, 255, 255);
            set_hud_element_tint(D_8010D678, 255, 255, 255);
            set_hud_element_tint(D_8010D66C, 255, 255, 255);
            set_hud_element_tint(D_8010D670, 255, 255, 255);
            set_hud_element_tint(D_8010D674, 255, 255, 255);
            if (gPopupMenu->popupType == 3) {
                set_hud_element_tint(D_8010D660, 160, 160, 160);
                set_hud_element_tint(D_8010D664, 160, 160, 160);
            }
            if (gPopupMenu->popupType == 4) {
                set_hud_element_tint(D_8010D660, 160, 160, 160);
                set_hud_element_tint(D_8010D664, 160, 160, 160);
            }
            if (gPopupMenu->popupType == 1 || gPopupMenu->popupType == 4) {
                set_hud_element_tint(D_8010D668, 160, 160, 160);
            }
            if (gPopupMenu->popupType == 5) {
                set_hud_element_tint(D_8010D660, 160, 160, 160);
            }
            set_hud_element_anim(D_8010D66C, D_80104A00);

            switch (gPopupMenu->popupType) {
                case 0:
                case 2:
                case 3:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 12:
                    set_window_update(0xE, 1);
                    set_window_update(0x13, 1);
                    break;
                case 1:
                case 4:
                    set_window_update(0xE, 1);
                    set_window_update(0x13, 1);
                    break;
                case 10:
                case 11:
                case 13:
                    set_window_update(0xE, 1);
                    break;
            }
            D_8010D690 = 0xA;
            D_8010D640 = 1;
            break;
    }
    gPopupMenu->result = 0;
    return 0;
}

INCLUDE_ASM(s32, "8a860_len_3f30", popup_menu_draw_menu_contents);

INCLUDE_ASM(s32, "8a860_len_3f30", popup_menu_draw_title_contents);

void func_800F48F4(s32* userData, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    draw_msg(gPopupMenu->descMsg[D_8010D648], baseX + 8, baseY, D_8010D650, D_8010D690, 0);
}

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

    if (gPopupMenu->popupType == POPUP_TYPE_TRADE_FOR_BADGE) {
        set_hud_element_render_pos(hudElement, xPos, yPos);
    } else {
        set_hud_element_render_pos(hudElement, xPos, y + 10);
    }

    draw_hud_element_clipped(hudElement);
    hudElement = D_8010D664;
    set_hud_element_render_pos(hudElement, x + 26, y + 11);
    set_hud_element_alpha(hudElement, D_8010D650);
    draw_hud_element_clipped(hudElement);

    type = gPopupMenu->popupType;
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
    gPopupMenu = popup;
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
    otherPopup = gPopupMenu;
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
    if (gPopupMenu->numEntries < 6) {
        D_8010D655 = gPopupMenu->numEntries;
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
