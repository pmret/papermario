#include "common_structs.h"
#include "hud_element.h"
#include "world/partners.h"
#include "macros.h"
#include "common.h"
#include "sprite.h"
#include "game_modes.h"
#include "pause/pause_common.h"
#include "world/partners.h"
#include "world/partner/lakilester.h"

enum WorldMenuStates {
    WORLD_MENU_STATE_NONE       = 0,
    WORLD_MENU_STATE_DELAY      = 1,
    WORLD_MENU_STATE_OPEN       = 2,
    WORLD_MENU_STATE_HOLD       = 3,
    WORLD_MENU_STATE_CLOSE      = 4,
    WORLD_MENU_STATE_UNPAUSE    = 10,
};

enum WorldMenuTypes {
    WORLD_MENU_CHANGE_PARTNER   = 0,
    WORLD_MENU_USE_ITEM         = 1,
    WORLD_MENU_PAUSE            = 2,
};

BSS s32 D_8010C9C4;
BSS PopupMenu WorldPopupMenu;
BSS s16 WorldMenuType;
BSS s16 WorldMenuDelay;
BSS s16 WorldPopupResult;
BSS s16 OpenMenuDisableCount;
BSS s16 WorldMenuState;

extern s32 MenuIndexFromPartnerID[];

void reset_outta_sight_alpha_on_menu_close(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (gPartnerStatus.partnerActionState != PARTNER_ACTION_NONE && gPartnerStatus.actingPartner == PARTNER_BOW) {
        Npc* partner = get_npc_unsafe(NPC_PARTNER);

        set_player_imgfx_comp(PLAYER_SPRITE_MAIN, -1, IMGFX_SET_ALPHA, 0, 0, 0, playerStatus->curAlpha, 0);
        npc_set_imgfx_params(partner, IMGFX_SET_ALPHA, playerStatus->curAlpha, 0, 0, 0, 0);
        playerStatus->prevAlpha = 0;
    }
}

b32 should_cancel_open_world_menu(void) {
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
    } else if (partner_can_open_world_menus()) {
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

b32 can_open_world_menu(s32 currentButtons, s32 pressedButtons) {
    PartnerStatus* partnerStatus = &gPartnerStatus;
    s32 actionState = gPlayerStatus.actionState;

    if (!(gPlayerStatus.animFlags & PA_FLAG_CHANGING_MAP)
        && !(gPlayerStatus.flags & PS_FLAG_PAUSE_DISABLED)
        && !(currentButtons & (BUTTON_Z | BUTTON_R))
        && (pressedButtons & (BUTTON_START | BUTTON_C_LEFT | BUTTON_C_RIGHT))
        && !((gGameStatusPtr->mapShop != NULL) && (gGameStatusPtr->mapShop->flags & SHOP_FLAG_SHOWING_ITEM_INFO))
        && !(gOverrideFlags & GLOBAL_OVERRIDES_DISABLE_MENUS)
        && !is_picking_up_item()
    ) {
        if (gPlayerStatus.animFlags & PA_FLAG_8BIT_MARIO) {
            sfx_play_sound(SOUND_MENU_ERROR);
            return FALSE;
        }
        if (partnerStatus->partnerActionState == PARTNER_ACTION_NONE) {
            if (!(gPlayerStatus.flags & PS_FLAG_NO_STATIC_COLLISION)) {
                if (actionState == ACTION_STATE_IDLE ||
                    actionState == ACTION_STATE_WALK ||
                    actionState == ACTION_STATE_RUN
                ) {
                    return TRUE;
                }
            }
        } else if (partner_can_open_world_menus()) {
            if (partnerStatus->actingPartner == PARTNER_WATT) {
                return actionState == ACTION_STATE_IDLE ||
                        actionState == ACTION_STATE_WALK ||
                        actionState == ACTION_STATE_RUN;
            } else if (partnerStatus->actingPartner == PARTNER_BOW) {
                if (actionState == ACTION_STATE_RIDE) {
                    gPlayerStatus.prevAlpha = 0;
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
    }
    return FALSE;
}

void clear_world_menus(void) {
    WorldMenuState = WORLD_MENU_STATE_NONE;
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
    static s16 SwappedWorldMenus;

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
    popup = &WorldPopupMenu;

    if (gGameStatusPtr->debugScripts != DEBUG_SCRIPTS_NONE
        || (gGameStatusPtr->peachFlags & PEACH_FLAG_IS_PEACH)
        || evt_get_variable(NULL, GB_StoryProgress) == STORY_INTRO
    ) {
        return;
    }

    if (partnerStatus->partnerActionState != PARTNER_ACTION_NONE &&
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

    // prevent opening popup menus during the epilogue
    if (evt_get_variable(NULL, GB_StoryProgress) >= STORY_EPILOGUE) {
        currentButtons &= ~(BUTTON_C_LEFT | BUTTON_C_RIGHT);
        pressedButtons &= ~(BUTTON_C_LEFT | BUTTON_C_RIGHT);
    }

    switch (WorldMenuState) {
        case WORLD_MENU_STATE_NONE:
            if (can_open_world_menu(currentButtons, pressedButtons)) {
                WorldMenuType = WORLD_MENU_USE_ITEM;
                if (pressedButtons & BUTTON_C_RIGHT) {
                    WorldMenuType = WORLD_MENU_CHANGE_PARTNER;
                }
                if (pressedButtons & BUTTON_START) {
                    WorldMenuType = WORLD_MENU_PAUSE;
                }
                SwappedWorldMenus = FALSE;
block_17:
                switch (WorldMenuType) {
                    case WORLD_MENU_CHANGE_PARTNER:
                        if (playerStatus->flags & PS_FLAG_NO_CHANGE_PARTNER) {
                            sfx_play_sound(SOUND_MENU_ERROR);
                            if (SwappedWorldMenus) {
                                reset_outta_sight_alpha_on_menu_close();
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
                    case WORLD_MENU_USE_ITEM:
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
                WorldMenuDelay = 3;
                WorldMenuState = WORLD_MENU_STATE_DELAY;
                OpenMenuDisableCount = playerStatus->inputDisabledCount;
            }
            break;
        case WORLD_MENU_STATE_DELAY:
            flags = ~PS_FLAG_PAUSED;
            if (!should_cancel_open_world_menu() || is_picking_up_item() || OpenMenuDisableCount < playerStatus->inputDisabledCount != 0) {
                playerStatus->flags &= flags;
                enable_player_input();
                partner_enable_input();
                WorldMenuState = WORLD_MENU_STATE_NONE;
                if (SwappedWorldMenus) {
                    reset_outta_sight_alpha_on_menu_close();
                    playerStatus->flags &= ~PS_FLAG_PAUSED;
                    gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
                    set_time_freeze_mode(TIME_FREEZE_NORMAL);
                }
            } else {
                WorldMenuDelay--;
                if (WorldMenuDelay == 0) {
                    WorldMenuState = WORLD_MENU_STATE_OPEN;
                    gOverrideFlags |= GLOBAL_OVERRIDES_40;
                }
            }
            break;
        case WORLD_MENU_STATE_OPEN:
            if (WorldMenuType == WORLD_MENU_PAUSE) {
                set_game_mode(GAME_MODE_PAUSE);
                sfx_play_sound(SOUND_MENU_OPEN);
                WorldMenuDelay = 10;
                WorldMenuState = WORLD_MENU_STATE_UNPAUSE;
                return;
            }
            create_standard_popup_menu(popup);
            set_time_freeze_mode(TIME_FREEZE_POPUP_MENU);
            if (*partnerActionState == PARTNER_ACTION_NONE) {
                set_action_state(ACTION_STATE_IDLE);
            }
            WorldMenuState++;
            break;
        case WORLD_MENU_STATE_HOLD:
            if (popup->result != POPUP_RESULT_INVALID) {
                WorldPopupResult = popup->result;
                if (WorldPopupResult != POPUP_RESULT_CHOOSING) {
                    hide_popup_menu();
                    WorldMenuDelay = 15;
                    WorldMenuState++;
                }
            }
            break;
        case WORLD_MENU_STATE_CLOSE:
            WorldMenuDelay--;
            if (WorldMenuDelay != 0) {
                break;
            }
            destroy_popup_menu();
            WorldMenuState = WORLD_MENU_STATE_NONE;
            enable_player_input();
            partner_enable_input();
            if (WorldPopupResult == POPUP_RESULT_SWAP_MENU) {
                if ((setup_partner_popup(popup) == 0) || (setup_item_popup(popup) == 0)) {
                    WorldPopupResult = POPUP_RESULT_CANCEL;
                } else {
                    // swap to other menu
                    switch (WorldMenuType) {
                        case WORLD_MENU_CHANGE_PARTNER:
                            WorldMenuType = WORLD_MENU_USE_ITEM;
                            break;
                        case WORLD_MENU_USE_ITEM:
                            WorldMenuType = WORLD_MENU_CHANGE_PARTNER;
                            break;
                    }
                    SwappedWorldMenus = TRUE;
                    goto block_17; // TODO required to match
                }
            }

            if (WorldPopupResult != POPUP_RESULT_CANCEL) {
                switch (WorldMenuType) {
                    case WORLD_MENU_CHANGE_PARTNER:
                        switch_to_partner(popup->userIndex[WorldPopupResult - 1]);
                        break;
                    case WORLD_MENU_USE_ITEM:
                        do {
                            use_consumable(popup->userIndex[WorldPopupResult - 1]);
                        } while (0); // todo required to match
#ifndef VERSION_JP
                        gOverrideFlags |= GLOBAL_OVERRIDES_CANT_PICK_UP_ITEMS;
#endif
                        break;
                }
            }
            reset_outta_sight_alpha_on_menu_close();
            playerStatus->flags &= ~PS_FLAG_PAUSED;
            gOverrideFlags &= ~GLOBAL_OVERRIDES_40;
            set_time_freeze_mode(TIME_FREEZE_NORMAL);
            break;
        case WORLD_MENU_STATE_UNPAUSE:
            WorldMenuDelay--;
            if (WorldMenuDelay == 0) {
                reset_outta_sight_alpha_on_menu_close();
                WorldMenuState = WORLD_MENU_STATE_NONE;
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
            if (!(playerStatus->curButtons & (Z_TRIG | R_TRIG))
                && (pressedButtons & BUTTON_C_UP)
                && can_control_status_bar()
            ) {
                open_status_bar_slowly();
#if VERSION_JP
                sfx_play_sound(SOUND_LOWER_STATUS_BAR);
#else
                if (!is_picking_up_item()) {
                    sfx_play_sound(SOUND_LOWER_STATUS_BAR);
                }
#endif
            }
        } else if (!(playerStatus->curButtons & (Z_TRIG | R_TRIG))
            && (pressedButtons & BUTTON_C_UP)
            && can_control_status_bar()
        ) {
            close_status_bar();
#if VERSION_JP
            sfx_play_sound(SOUND_RAISE_STATUS_BAR);
#else
            if (!is_picking_up_item()) {
                sfx_play_sound(SOUND_RAISE_STATUS_BAR);
            }
#endif
        }
    }
}
