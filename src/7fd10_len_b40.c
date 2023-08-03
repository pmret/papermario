#include "common_structs.h"
#include "hud_element.h"
#include "world/partners.h"
#include "macros.h"
#include "common.h"
#include "sprite.h"
#include "pause/pause_common.h"
#include "world/partners.h"
#include "world/partner/lakilester.h"

BSS s16 D_8010C9C0;
BSS char D_8010C9C4[0x4];
BSS PopupMenu D_8010C9C8;
BSS s16 D_8010CCF8;
BSS s16 D_8010CCFA;
BSS s16 D_8010CCFC;
BSS s16 D_8010CCFE;
BSS s16 D_8010CD00;

extern s32 MenuIndexFromPartnerID[];

void func_800E6860(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (gPartnerStatus.partnerActionState != PARTNER_ACTION_NONE && gPartnerStatus.actingPartner == PARTNER_BOW) {
        Npc* partner = get_npc_unsafe(NPC_PARTNER);

        set_player_imgfx_comp(PLAYER_SPRITE_MAIN, -1, IMGFX_SET_ALPHA, 0, 0, 0, playerStatus->alpha1, 0);
        npc_set_imgfx_params(partner, IMGFX_SET_ALPHA, playerStatus->alpha1, 0, 0, 0, 0);
        playerStatus->alpha2 = 0;
    }
}

s32 func_800E6904(void) {
    PartnerStatus* partnerStatus = &gPartnerStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 actionState = playerStatus->actionState;

    if (playerStatus->animFlags & PA_FLAG_CHANGING_MAP) {
        return FALSE;
    }

    if (partnerStatus->partnerActionState == PARTNER_ACTION_NONE) {
        if (!(playerStatus->flags & PS_FLAG_NO_STATIC_COLLISION) &&
            (actionState == ACTION_STATE_IDLE || actionState == ACTION_STATE_WALK || actionState == ACTION_STATE_RUN))
        {
            return TRUE;
        }
    } else if (partner_player_can_pause()) {
        if (partnerStatus->actingPartner == PARTNER_WATT) {
            return TRUE;
        } else if (partnerStatus->actingPartner == PARTNER_BOW) {
            if (actionState == ACTION_STATE_RIDE) {
                return TRUE;
            }
        } else if (partnerStatus->actingPartner == PARTNER_LAKILESTER) {
            if (actionState == ACTION_STATE_RIDE) {
                return TRUE;
            }
            sfx_play_sound(SOUND_MENU_ERROR);
        }
    }
    return FALSE;
}

s32 can_pause(s32 currentButtons, s32 pressedButtons) {
    PartnerStatus* partnerStatus = &gPartnerStatus;
    s32 actionState = gPlayerStatus.actionState;

    if (!(gPlayerStatus.animFlags & PA_FLAG_CHANGING_MAP)
        && !(gPlayerStatus.flags & PS_FLAG_PAUSE_DISABLED)
        && !(currentButtons & (BUTTON_Z | BUTTON_R))
        && (pressedButtons & (BUTTON_START | BUTTON_C_LEFT | BUTTON_C_RIGHT))
        && ((gGameStatusPtr->mapShop == NULL) || !(gGameStatusPtr->mapShop->flags & SHOP_FLAG_1))
        && !(gOverrideFlags & GLOBAL_OVERRIDES_DISABLE_MENUS)
        && !is_picking_up_item()
    ) {
        if (!(gPlayerStatus.animFlags & PA_FLAG_8BIT_MARIO)) {
            if (partnerStatus->partnerActionState == PARTNER_ACTION_NONE) {
                if (!(gPlayerStatus.flags & PS_FLAG_NO_STATIC_COLLISION)) {
                    if (actionState == ACTION_STATE_IDLE ||
                        actionState == ACTION_STATE_WALK ||
                        actionState == ACTION_STATE_RUN)
                    {
                        return TRUE;
                    }
                }
            } else if (partner_player_can_pause()) {
                if (partnerStatus->actingPartner == PARTNER_WATT) {
                    return actionState == ACTION_STATE_IDLE ||
                           actionState == ACTION_STATE_WALK ||
                           actionState == ACTION_STATE_RUN;
                } else if (partnerStatus->actingPartner == PARTNER_BOW) {
                    if (actionState == ACTION_STATE_RIDE) {
                        gPlayerStatus.alpha2 = 0;
                        return TRUE;
                    }
                } else if (partnerStatus->actingPartner == PARTNER_LAKILESTER) {
                    if (actionState == ACTION_STATE_RIDE) {
                        if (world_lakilester_can_dismount()) {
                            return TRUE;
                        }
                        sfx_play_sound(SOUND_MENU_ERROR);
                    }
                } else if (partnerStatus->actingPartner == PARTNER_SUSHIE) {
                    sfx_play_sound(SOUND_MENU_ERROR);
                }
            }
        } else {
            sfx_play_sound(SOUND_MENU_ERROR);
        }
    }
    return FALSE;
}

void func_800E6B68(void) {
    D_8010CD00 = 0;
}

s32 setup_partner_popup(PopupMenu* menu) {
    PlayerData* playerData = &gPlayerData;
    s32 optionCount = 0;
    s32 i;

    for (i = 1; i < ARRAY_COUNT(PartnerIDFromMenuIndex); i++) {
        s32 partnerID = PartnerIDFromMenuIndex[i];

        if (playerData->partners[partnerID].enabled && partnerID != PARTNER_GOOMPA) {
            PartnerPopupProperties* properties = &gPartnerPopupProperties[partnerID];

            menu->ptrIcon[optionCount] = wPartnerHudScripts[partnerID];
            menu->userIndex[optionCount] = partnerID;
            menu->enabled[optionCount] = TRUE;
            menu->nameMsg[optionCount] = properties->nameMsg;
            menu->descMsg[optionCount] = properties->worldDescMsg;
            menu->value[optionCount] = playerData->partners[partnerID].level;
            if (playerData->curPartner == partnerID) {
                menu->enabled[optionCount] = FALSE;
                menu->ptrIcon[optionCount] = wDisabledPartnerHudScripts[partnerID];
            }
            optionCount++;
        }
    }
    return optionCount;
}

s32 setup_item_popup(PopupMenu* menu) {
    PlayerData* playerData = &gPlayerData;
    s32 optionCount = 0;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(playerData->invItems); i++) {
        s32 itemIdx = playerData->invItems[i];

        if (itemIdx != 0) {
            ItemData* item = &gItemTable[itemIdx];
            IconHudScriptPair* itemScripts = &gItemHudScripts[item->hudElemID];

            if (item->typeFlags & ITEM_TYPE_FLAG_WORLD_USABLE) {
                menu->ptrIcon[optionCount] = itemScripts->enabled;
                menu->userIndex[optionCount] = i;
                menu->enabled[optionCount] = 1;
            } else {
                menu->ptrIcon[optionCount] = itemScripts->disabled;
                menu->userIndex[optionCount] = i;
                menu->enabled[optionCount] = FALSE;
            }
            menu->nameMsg[optionCount] = item->nameMsg;
            menu->descMsg[optionCount] = item->shortDescMsg;
            optionCount++;
        }
    }
    return optionCount;
}

void check_input_open_menus(void) {
    static s16 D_8010C9C0;

    PartnerStatus* partnerStatus;
    PlayerStatus* playerStatus;
    PlayerData* playerData;
    PopupMenu* popup;
    s32 flags;
    s32 numEntries;
    s32 pressedButtons;
    s32 currentButtons;
    s8* partnerActionState;

    partnerStatus = &gPartnerStatus;
    playerStatus = &gPlayerStatus;
    playerData = &gPlayerData;
    popup = &D_8010C9C8;

    if (gGameStatusPtr->disableScripts ||
        (gGameStatusPtr->peachFlags & PEACH_STATUS_FLAG_IS_PEACH) ||
        evt_get_variable(NULL, GB_StoryProgress) == STORY_INTRO)
    {
        return;
    }

    if (partnerStatus->partnerActionState != 0 &&
        (partnerStatus->actingPartner == PARTNER_SUSHIE ||
         partnerStatus->actingPartner == PARTNER_LAKILESTER ||
         partnerStatus->actingPartner == PARTNER_BOW))
    {
        currentButtons = partnerStatus->curButtons;
        pressedButtons = partnerStatus->pressedButtons;
    } else {
        currentButtons = playerStatus->curButtons;
        pressedButtons = playerStatus->pressedButtons;
    }
    partnerActionState = &partnerStatus->partnerActionState;

    if (evt_get_variable(NULL, GB_StoryProgress) >= STORY_EPILOGUE) {
        currentButtons &= ~(BUTTON_C_LEFT | BUTTON_C_RIGHT);
        pressedButtons &= ~(BUTTON_C_LEFT | BUTTON_C_RIGHT);
    }

    switch (D_8010CD00) {
        case 0:
            if (can_pause(currentButtons, pressedButtons)) {
                D_8010CCF8 = 1;
                if (pressedButtons & 1) {
                    D_8010CCF8 = 0;
                }
                if (pressedButtons & BUTTON_START) {
                    D_8010CCF8 = 2;
                }
                D_8010C9C0 = FALSE;
block_17:
                switch (D_8010CCF8) {
                    case 0:
                        if (playerStatus->flags & PS_FLAG_NO_CHANGE_PARTNER) {
                            sfx_play_sound(SOUND_MENU_ERROR);
                            if (D_8010C9C0) {
                                func_800E6860();
                                playerStatus->flags &= ~PS_FLAG_PAUSED;
                                gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
                                set_time_freeze_mode(TIME_FREEZE_NORMAL);
                            }
                        } else {
                            numEntries = setup_partner_popup(popup);
                            if (numEntries == 0) {
                                return;
                            }
                            popup->numEntries = numEntries;
                            popup->popupType = POPUP_MENU_SWITCH_PARTNER;
                            popup->initialPos = MenuIndexFromPartnerID[playerData->curPartner] - 1;
                            break;
                        }
                        return;
                    case 1:
                        numEntries = setup_item_popup(popup);
                        if (numEntries == 0) {
                            return;
                        }
                        popup->popupType = POPUP_MENU_USE_ITEM;
                        popup->numEntries = numEntries;
                        popup->initialPos = 0;
                        break;
                }
                playerStatus->flags |= PS_FLAG_PAUSED;
                disable_player_input();
                partner_disable_input();
                D_8010CCFA = 3;
                D_8010CD00 = 1;
                D_8010CCFE = playerStatus->inputDisabledCount;
            }
            break;
        case 1:
            flags = ~PS_FLAG_PAUSED;
            if ((func_800E6904() == 0) || is_picking_up_item() || D_8010CCFE < playerStatus->inputDisabledCount != 0) {
                playerStatus->flags &= flags;
                enable_player_input();
                partner_enable_input();
                D_8010CD00 = 0;
                if (D_8010C9C0) {
                    func_800E6860();
                    playerStatus->flags &= ~PS_FLAG_PAUSED;
                    gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
                    set_time_freeze_mode(TIME_FREEZE_NORMAL);
                }
            } else {
                D_8010CCFA--;
                if (D_8010CCFA == 0) {
                    D_8010CD00 = 2;
                    gOverrideFlags |= GLOBAL_OVERRIDES_40;
                }
            }
            break;
        case 2:
            if (D_8010CCF8 == 2) {
                set_game_mode(GAME_MODE_PAUSE);
                sfx_play_sound(SOUND_MENU_OPEN);
                D_8010CCFA = 10;
                D_8010CD00 = 10;
                return;
            }
            create_standard_popup_menu(popup);
            set_time_freeze_mode(TIME_FREEZE_POPUP_MENU);
            if (*partnerActionState == PARTNER_ACTION_NONE) {
                set_action_state(ACTION_STATE_IDLE);
            }
            D_8010CD00++;
            break;
        case 3:
            if (popup->result != POPUP_RESULT_MINUS_1) {
                D_8010CCFC = popup->result;
                if (D_8010CCFC != POPUP_RESULT_CHOOSING) {
                    hide_popup_menu();
                    D_8010CCFA = 15;
                    D_8010CD00++;
                }
            }
            break;
        case 4:
            D_8010CCFA--;
            if (D_8010CCFA == 0) {
                destroy_popup_menu();
                D_8010CD00 = 0;
                enable_player_input();
                partner_enable_input();
                if (D_8010CCFC == POPUP_RESULT_MINUS_2) {
                    if ((setup_partner_popup(popup) == 0) || (setup_item_popup(popup) == 0)) {
                        D_8010CCFC = POPUP_RESULT_CANCEL;
                    } else {
                        switch (D_8010CCF8) {
                            case 0:
                                D_8010CCF8 = 1;
                                break;
                            case 1:
                                D_8010CCF8 = 0;
                                break;
                        }
                        D_8010C9C0 = TRUE;
                        goto block_17; // TODO required to match
                    }
                }

                if (D_8010CCFC != POPUP_RESULT_CANCEL) {
                    switch (D_8010CCF8) {
                        case 0:
                            switch_to_partner(popup->userIndex[D_8010CCFC - 1]);
                            break;
                        case 1:
                            do {
                                use_consumable(popup->userIndex[D_8010CCFC - 1]);
                            } while (0); // todo required to match
                            gOverrideFlags |= GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS;
                            break;
                    }
                }
                func_800E6860();
                playerStatus->flags &= ~PS_FLAG_PAUSED;
                gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
                set_time_freeze_mode(TIME_FREEZE_NORMAL);
            }
            break;
        case 10:
            D_8010CCFA--;
            if (D_8010CCFA == 0) {
                func_800E6860();
                D_8010CD00 = 0;
                playerStatus->flags &= ~PS_FLAG_PAUSED;
                gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
                enable_player_input();
                partner_enable_input();
            }
            break;
    }
}

void check_input_status_bar(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 pressedButtons;

    if (evt_get_variable(NULL, GB_StoryProgress) < STORY_EPILOGUE) {
        if (playerStatus->actionState != ACTION_STATE_RIDE) {
            pressedButtons = playerStatus->pressedButtons;
        } else {
            pressedButtons = gGameStatusPtr->pressedButtons[0];
        }

        if (!is_status_bar_visible()) {
            if (!(playerStatus->curButtons & (Z_TRIG | R_TRIG)) && (pressedButtons & BUTTON_C_UP) && func_800E9860()) {
                open_status_bar_long();

                if (!is_picking_up_item()) {
                    sfx_play_sound(SOUND_LOWER_STATUS_BAR);
                }
            }
        } else if (!(playerStatus->curButtons & (Z_TRIG | R_TRIG)) && (pressedButtons & BUTTON_C_UP) && func_800E9860()) {
            close_status_bar();

            if (!is_picking_up_item()) {
                sfx_play_sound(SOUND_RAISE_STATUS_BAR);
            }
        }
    }
}
