#include "common_structs.h"
#include "hud_element.h"
#include "world/partners.h"
#include "macros.h"
#include "common.h"
#include "sprite.h"
#include "pause/pause_common.h"
#include "world/partners.h"

BSS s16 D_8010C9C0;
BSS char D_8010C9C4[0x4];
BSS PopupMenu D_8010C9C8;
BSS s16 D_8010CCF8;
BSS s16 D_8010CCFA;
BSS s16 D_8010CCFC;
BSS s16 D_8010CCFE;
BSS s16 D_8010CD00;
BSS char D_8010CD04[0xC];
BSS s16 D_8010CD10;
BSS s16 D_8010CD12;
BSS char D_8010CD14[0xA];
BSS s32 D_8010CD20;
BSS char D_8010CD24[0xC];

extern s32 D_8008EEF0[];

void func_800E6860(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (gPartnerActionStatus.partnerActionState != PARTNER_ACTION_NONE && gPartnerActionStatus.actingPartner == PARTNER_BOW) {
        Npc* partner = get_npc_unsafe(NPC_PARTNER);

        func_802DDEE4(0, -1, 7, 0, 0, 0, playerStatus->alpha1, 0);
        func_8003D624(partner, 7, playerStatus->alpha1, 0, 0, 0, 0);
        playerStatus->alpha2 = 0;
    }
}

s32 func_800E6904(void) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 actionState = playerStatus->actionState;

    if (playerStatus->animFlags & PA_FLAGS_CHANGING_MAP) {
        return FALSE;
    }

    if (partnerActionStatus->partnerActionState == PARTNER_ACTION_NONE) {
        if (!(playerStatus->flags & PS_FLAGS_NO_STATIC_COLLISION) &&
            (actionState == ACTION_STATE_IDLE || actionState == ACTION_STATE_WALK || actionState == ACTION_STATE_RUN))
        {
            return TRUE;
        }
    } else if (partner_player_can_pause()) {
        if (partnerActionStatus->actingPartner == PARTNER_WATT) {
            return TRUE;
        } else if (partnerActionStatus->actingPartner == PARTNER_BOW) {
            if (actionState == ACTION_STATE_RIDE) {
                return TRUE;
            }
        } else if (partnerActionStatus->actingPartner == PARTNER_LAKILESTER) {
            if (actionState == ACTION_STATE_RIDE) {
                return TRUE;
            }
            sfx_play_sound(SOUND_MENU_ERROR);
        }
    }
    return FALSE;
}

s32 can_pause(s32 currentButtons, s32 pressedButtons) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    s32 actionState = gPlayerStatus.actionState;

    if (!(gPlayerStatus.animFlags & PA_FLAGS_CHANGING_MAP) &&
        !(gPlayerStatus.flags & PS_FLAGS_CANT_PAUSE) &&
        !(currentButtons & (BUTTON_Z | BUTTON_R)) &&
        (pressedButtons & (BUTTON_START | BUTTON_C_LEFT | BUTTON_C_RIGHT)) &&
        ((gGameStatusPtr->mapShop == NULL) || !(gGameStatusPtr->mapShop->flags & 1)) &&
        !(gOverrideFlags & GLOBAL_OVERRIDES_DISABLE_MENUS) &&
        !is_picking_up_item())
    {
        if (!(gPlayerStatus.animFlags & PA_FLAGS_8BIT_MARIO)) {
            if (partnerActionStatus->partnerActionState == PARTNER_ACTION_NONE) {
                if (!(gPlayerStatus.flags & PS_FLAGS_NO_STATIC_COLLISION)) {
                    if (actionState == ACTION_STATE_IDLE ||
                        actionState == ACTION_STATE_WALK ||
                        actionState == ACTION_STATE_RUN)
                    {
                        return TRUE;
                    }
                }
            } else if (partner_player_can_pause()) {
                if (partnerActionStatus->actingPartner == PARTNER_WATT) {
                    return actionState == ACTION_STATE_IDLE ||
                           actionState == ACTION_STATE_WALK ||
                           actionState == ACTION_STATE_RUN;
                } else if (partnerActionStatus->actingPartner == PARTNER_BOW) {
                    if (actionState == ACTION_STATE_RIDE) {
                        gPlayerStatus.alpha2 = 0;
                        return TRUE;
                    }
                } else if (partnerActionStatus->actingPartner == PARTNER_LAKILESTER) {
                    if (actionState == ACTION_STATE_RIDE) {
                        if (lakilester_raycast_below()) {
                            return TRUE;
                        }
                        sfx_play_sound(SOUND_MENU_ERROR);
                    }
                } else if (partnerActionStatus->actingPartner == PARTNER_SUSHIE) {
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

    for (i = 1; i < ARRAY_COUNT(D_8008EEC0); i++) {
        s32 partnerID = D_8008EEC0[i];

        if (playerData->partners[partnerID].enabled && partnerID != PARTNER_GOOMPA) {
            PartnerPopupProperties* properties = &gPartnerPopupProperties[partnerID];

            menu->ptrIcon[optionCount] = wPartnerHudScripts[partnerID];
            menu->userIndex[optionCount] = partnerID;
            menu->enabled[optionCount] = TRUE;
            menu->nameMsg[optionCount] = properties->nameMsg;
            menu->descMsg[optionCount] = properties->worldDescMsg;
            menu->value[optionCount] = playerData->partners[partnerID].level;
            if (playerData->currentPartner == partnerID) {
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

            if (item->typeFlags & 1) {
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

    PartnerActionStatus* partnerActionStatus;
    PlayerStatus* playerStatus;
    PlayerData* playerData;
    PopupMenu* popup;
    s32 flags;
    s32 numEntries;
    s32 pressedButtons;
    s32 currentButtons;
    s8* partnerActionState;

    partnerActionStatus = &gPartnerActionStatus;
    playerStatus = &gPlayerStatus;
    playerData = &gPlayerData;
    popup = &D_8010C9C8;

    if (gGameStatusPtr->disableScripts ||
        (gGameStatusPtr->peachFlags & PEACH_STATUS_FLAG_IS_PEACH) ||
        evt_get_variable(NULL, GB_StoryProgress) == STORY_INTRO)
    {
        return;
    }

    if (partnerActionStatus->partnerActionState != 0 &&
        (partnerActionStatus->actingPartner == PARTNER_SUSHIE ||
         partnerActionStatus->actingPartner == PARTNER_LAKILESTER ||
         partnerActionStatus->actingPartner == PARTNER_BOW))
    {
        currentButtons = partnerActionStatus->currentButtons;
        pressedButtons = partnerActionStatus->pressedButtons;
    } else {
        currentButtons = playerStatus->currentButtons;
        pressedButtons = playerStatus->pressedButtons;
    }
    partnerActionState = &partnerActionStatus->partnerActionState;

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
                        if (playerStatus->flags & PS_FLAGS_CANT_CHANGE_PARTNER) {
                            sfx_play_sound(SOUND_MENU_ERROR);
                            if (D_8010C9C0) {
                                func_800E6860();
                                playerStatus->flags &= ~PS_FLAGS_PAUSED;
                                gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
                                set_time_freeze_mode(TIME_FREEZE_NORMAL);
                            }
                        } else {
                            numEntries = setup_partner_popup(popup);
                            if (numEntries == 0) {
                                return;
                            }
                            popup->numEntries = numEntries;
                            popup->popupType = 1;
                            popup->initialPos = D_8008EEF0[playerData->currentPartner] - 1;
                            break;
                        }
                        return;
                    case 1:
                        numEntries = setup_item_popup(popup);
                        if (numEntries == 0) {
                            return;
                        }
                        popup->popupType = 0;
                        popup->numEntries = numEntries;
                        popup->initialPos = 0;
                        break;
                }
                playerStatus->flags |= PS_FLAGS_PAUSED;
                disable_player_input();
                partner_disable_input();
                D_8010CCFA = 3;
                D_8010CD00 = 1;
                D_8010CCFE = playerStatus->inputEnabledCounter;
            }
            break;
        case 1:
            flags = ~PS_FLAGS_PAUSED;
            if ((func_800E6904() == 0) || is_picking_up_item() || D_8010CCFE < playerStatus->inputEnabledCounter) {
                playerStatus->flags &= flags;
                enable_player_input();
                partner_enable_input();
                D_8010CD00 = 0;
                if (D_8010C9C0) {
                    func_800E6860();
                    playerStatus->flags &= ~PS_FLAGS_PAUSED;
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
            create_popup_menu(popup);
            set_time_freeze_mode(TIME_FREEZE_PARTNER_MENU);
            if (*partnerActionState == 0) {
                set_action_state(ACTION_STATE_IDLE);
            }
            D_8010CD00++;
            break;
        case 3:
            if (popup->result != -1) {
                D_8010CCFC = popup->result;
                if (D_8010CCFC != 0) {
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
                if (D_8010CCFC == -2) {
                    if ((setup_partner_popup(popup) == 0) || (setup_item_popup(popup) == 0)) {
                        D_8010CCFC = 0xFF;
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

                if (D_8010CCFC != 0xFF) {
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
                playerStatus->flags &= ~PS_FLAGS_PAUSED;
                gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
                set_time_freeze_mode(TIME_FREEZE_NORMAL);
            }
            break;
        case 10:
            D_8010CCFA--;
            if (D_8010CCFA == 0) {
                func_800E6860();
                D_8010CD00 = 0;
                playerStatus->flags &= ~PS_FLAGS_PAUSED;
                gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
                enable_player_input();
                partner_enable_input();
            }
            break;
    }
}

void check_input_status_menu(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 pressedButtons;

    if (evt_get_variable(NULL, GB_StoryProgress) < STORY_EPILOGUE) {
        if (playerStatus->actionState != ACTION_STATE_RIDE) {
            pressedButtons = playerStatus->pressedButtons;
        } else {
            pressedButtons = gGameStatusPtr->pressedButtons[0];
        }

        if (!is_status_menu_visible()) {
            if (!(playerStatus->currentButtons & (Z_TRIG | R_TRIG)) && (pressedButtons & BUTTON_C_UP) && func_800E9860()) {
                open_status_menu_long();

                if (!is_picking_up_item()) {
                    sfx_play_sound(SOUND_3);
                }
            }
        } else if (!(playerStatus->currentButtons & (Z_TRIG | R_TRIG)) && (pressedButtons & BUTTON_C_UP) && func_800E9860()) {
            close_status_menu();

            if (!is_picking_up_item()) {
                sfx_play_sound(SOUND_4);
            }
        }
    }
}
