#include "common.h"
#include "sprite.h"
#include "hud_element.h"
#include "pause/pause_common.h"

extern s32 D_8008EEC0[12];
extern s32 D_8008EEF0[];
extern s16 D_8010C9C0;
extern PopupMenu D_8010C9C8;
extern s16 D_8010CCF8;
extern s16 D_8010CCFA;
extern s16 D_8010CCFC;
extern s16 D_8010CCFE;

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

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_100000) {
        return FALSE;
    }

    if (partnerActionStatus->partnerActionState == PARTNER_ACTION_NONE) {
        if (!(playerStatus->flags & PLAYER_STATUS_FLAGS_1000) &&
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

    if (!(gPlayerStatus.animFlags & PLAYER_STATUS_ANIM_FLAGS_100000) &&
        !(gPlayerStatus.flags & PLAYER_STATUS_FLAGS_100) &&
        !(currentButtons & (BUTTON_Z | BUTTON_R)) &&
        (pressedButtons & (BUTTON_START | BUTTON_C_LEFT | BUTTON_C_RIGHT)) &&
        ((gGameStatusPtr->mapShop == NULL) || !(gGameStatusPtr->mapShop->flags & 1)) &&
        !(gOverrideFlags & GLOBAL_OVERRIDES_DISABLE_MENUS) &&
        !is_picking_up_item())
    {
        if (!(gPlayerStatus.animFlags & PLAYER_STATUS_ANIM_FLAGS_8BIT_MARIO)) {
            if (partnerActionStatus->partnerActionState == PARTNER_ACTION_NONE) {
                if (!(gPlayerStatus.flags & PLAYER_STATUS_FLAGS_1000)) {
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
                        if (func_802BD7DC()) {
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
            s32* properties = gPartnerPopupProperties[partnerID];

            menu->ptrIcon[optionCount] = wPartnerHudScripts[partnerID];
            menu->userIndex[optionCount] = partnerID;
            menu->enabled[optionCount] = TRUE;
            menu->nameMsg[optionCount] = properties[0];
            menu->descMsg[optionCount] = properties[2];
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

INCLUDE_ASM(s32, "7fd10_len_b40", check_input_open_menus);

void check_input_status_menu(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 pressedButtons;

    if (evt_get_variable(NULL, EVT_STORY_PROGRESS) < STORY_EPILOGUE) {
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
