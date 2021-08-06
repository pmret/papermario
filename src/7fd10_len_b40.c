#include "common.h"

void func_800E6860(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (gPartnerActionStatus.actionState.b[0] != 0 && gPartnerActionStatus.actionState.b[3]  == 9) {
        Npc* partner = get_npc_unsafe(NPC_PARTNER);

        func_802DDEE4(0, -1, 7, 0, 0, 0, playerStatus->alpha1, 0);
        func_8003D624(partner, 7, playerStatus->alpha1, 0, 0, 0, 0);
        playerStatus->alpha2 = 0;
    }
}

// playerStatus getting coppied to a0 - how? inlining?
#ifdef NON_MATCHING
s32 func_800E6904(void) {
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;
    //PlayerStatus* playerStatus = &gPlayerStatus; // doesn't change codegen to use it, so commented out for now
    s32 actionState = gPlayerStatus.actionState;

    if (!(gPlayerStatus.animFlags & 0x100000)) {
        if (partnerActionStatus->actionState.b[0] == 0) {
            if (!(gPlayerStatus.flags & 0x1000)) {
                if (actionState == ACTION_STATE_IDLE || actionState == ACTION_STATE_WALK || actionState == ACTION_STATE_RUN) {
                    return 1;
                }
            }
        } else if (partner_player_can_pause()) {
            if (partnerActionStatus->actionState.b[3] == 6) {
                return 1;
            } else if (partnerActionStatus->actionState.b[3] == 9) {
                if (actionState == ACTION_STATE_RIDE) {
                    return 1;
                }
            } else if (partnerActionStatus->actionState.b[3] == 8) {
                if (actionState != ACTION_STATE_RIDE) {
                    sfx_play_sound(0x21D);
                } else {
                    return 1;
                }
            }
        }
    }

    return 0;
}
#else
INCLUDE_ASM(s32, "7fd10_len_b40", func_800E6904);
#endif

INCLUDE_ASM(s32, "7fd10_len_b40", can_pause);

void func_800E6B68(void) {
    D_8010CD00 = 0;
}

INCLUDE_ASM(s32, "7fd10_len_b40", setup_partner_popup);

INCLUDE_ASM(s32, "7fd10_len_b40", setup_item_popup);

INCLUDE_ASM(s32, "7fd10_len_b40", check_input_open_menus);

void check_input_status_menu(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 pressedButtons;

    if (get_variable(NULL, SI_STORY_PROGRESS) < STORY_EPILOGUE) {
        if (playerStatus->actionState != ACTION_STATE_RIDE) {
            pressedButtons = playerStatus->pressedButtons;
        } else {
            pressedButtons = gGameStatusPtr->pressedButtons;
        }

        if (!is_status_menu_visible()) {
            if (!(playerStatus->currentButtons & Z_TRIG + R_TRIG) && (pressedButtons & 8) && func_800E9860()) {
                open_status_menu_long();

                if (!is_picking_up_item()) {
                    sfx_play_sound(3);
                }
            }
        } else if (!(playerStatus->currentButtons & Z_TRIG + R_TRIG) && (pressedButtons & 8) && func_800E9860()) {
            close_status_menu();

            if (!is_picking_up_item()) {
                sfx_play_sound(4);
            }
        }
    }
}
