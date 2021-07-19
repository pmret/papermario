#include "common.h"
#include "ld_addrs.h"

extern s16 D_802809F6;
extern s32 D_80280A30;
extern s32 D_8029F254;

INCLUDE_ASM(s32, "16F740", btl_merlee_on_start_turn);

INCLUDE_ASM(s32, "16F740", btl_merlee_on_first_strike);

void btl_set_state(s32 battleState) {
    s32 flags = gBattleStatus.flags2;
    gBattleState = battleState;
    D_800DC4E0 = 1;
    gBattleState2 = 0;

    flags &= 0x40;
    if (flags) {
        switch (battleState) {
            case 14:
                battleState = 16;
                break;
            case 13:
                battleState = 15;
                break;
            case 7:
                battleState = 8;
                break;
            case 8:
                battleState = 7;
                break;
        }
        gBattleState = battleState;
    }
}

INCLUDE_ASM(s32, "16F740", btl_state_update_normal_start);

void btl_state_draw_normal_start(void) {
    set_screen_overlay_color(0, 0, 0, 0);

    if (D_80280A30 > 255) {
        set_screen_overlay_params_front(0, 255.0f);
    } else {
        set_screen_overlay_params_front(0, D_80280A30);
    }
}

INCLUDE_ASM(s32, "16F740", btl_state_update_begin_turn);

void btl_state_draw_begin_turn(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_begin_player_turn);

void btl_state_draw_begin_player_turn(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_switch_to_player);

void btl_state_draw_switch_to_player(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_begin_partner_turn);

void btl_state_draw_begin_partner_turn(void) {
}

INCLUDE_ASM(void, "16F740", btl_state_update_switch_to_partner, s32);

void btl_state_draw_switch_to_partner(void) {
}

INCLUDE_ASM(s32, "16F740", func_80242FE0);

void func_80243910(void) {
}

void btl_state_update_prepare_menu(void) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->unk_4D = -1;
    battleStatus->unk_4E = -1;
    battleStatus->unk_4F = -1;
    battleStatus->unk_50 = -1;
    battleStatus->unk_51 = -1;
    battleStatus->unk_52 = -1;
    battleStatus->stratsLastCursorPos = -1;
    battleStatus->unk_5D = -1;
    battleStatus->unk_62 = -1;
    battleStatus->unk_63 = -1;

    dma_copy(_415D90_ROM_START, _415D90_ROM_END, _415D90_VRAM);

    if (battleStatus->flags1 & 0x80000) {
        btl_set_state(14);
    } else if (gBattleState2 == 70) {
        btl_set_state(13);
        gBattleState2 = 70;
    } else {
        btl_set_state(13);
    }
}

void btl_state_draw_prepare_menu(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_end_turn);

void btl_state_draw_end_turn(void) {
}

void btl_state_update_1C(void) {
    func_8024E40C(2);
    btl_set_state(12);
}

void btl_state_draw_1C(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_victory);

void btl_state_draw_victory(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_end_training_battle);

void btl_state_draw_end_training_battle(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_end_battle);

INCLUDE_ASM(s32, "16F740", btl_state_draw_end_battle);

INCLUDE_ASM(s32, "16F740", btl_state_update_defend);

void btl_state_draw_defend(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_run_away);

void btl_state_draw_run_away(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_defeat);

void btl_state_draw_defeat(void) {
}

ApiStatus EnablePartnerBlur(ScriptInstance* script, s32 isInitialCall) {
    enable_partner_blur();
    return ApiStatus_DONE2;
}

ApiStatus DisablePartnerBlur(ScriptInstance* script, s32 isInitialCall) {
    disable_partner_blur();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "16F740", btl_state_update_change_partner);

void btl_state_draw_change_partner(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_player_move);

void btl_state_draw_player_move(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_end_player_turn);

void filemenu_main_update_code(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_partner_move);

void btl_state_draw_partner_move(void) {
}

void btl_state_update_end_partner_turn(void) {
    BattleStatus* battleStatus = &gBattleStatus;

    if (gBattleState2 == 0) {
        battleStatus->flags2 |= 0x4;
        if (!btl_check_enemies_defeated()) {
            battleStatus->flags1 &= ~0x80000;
            battleStatus->flags2 &= ~0x10;

            if (battleStatus->unk_94 < 0) {
                battleStatus->unk_94 = 0;
                btl_set_state(6);
            } else {
                btl_set_state(9);
            }
        }
    }
}

void btl_state_draw_end_partner_turn(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_next_enemy);

void btl_state_draw_next_enemy(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_enemy_move);

void btl_state_draw_enemy_move(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_first_strike);

INCLUDE_ASM(s32, "16F740", btl_state_draw_first_stike);

INCLUDE_ASM(s32, "16F740", btl_state_update_partner_striking_first);

void btl_state_draw_partner_striking_first(void) {
    if (D_8029F254 != 0) {
        if (D_80280A30 == 0) {
            set_screen_overlay_params_front(255, -1.0f);
        } else {
            D_80280A30 -= 20;
            if (D_80280A30 < 0) {
                D_80280A30 = 0;
            }

            set_screen_overlay_params_front(0, D_80280A30);
        }
    }
}

INCLUDE_ASM(s32, "16F740", btl_state_update_enemy_striking_first);

void btl_state_draw_enemy_striking_first(void) {
    if (D_8029F254 != 0) {
        if (D_80280A30 == 0) {
            set_screen_overlay_params_front(255, -1.0f);
        } else {
            D_80280A30 -= 20;
            if (D_80280A30 < 0) {
                D_80280A30 = 0;
            }

            set_screen_overlay_params_front(0, D_80280A30);
        }
    }
}

INCLUDE_ASM(s32, "16F740", btl_state_update_end_demo_battle);

void btl_state_draw_end_demo_battle(void) {
    if (D_802809F6 == -1) {
        set_screen_overlay_color(0, 0, 0, 0);
        set_screen_overlay_params_front(0, D_80280A30);
    }
}
