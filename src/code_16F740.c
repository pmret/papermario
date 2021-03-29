#include "common.h"
#include "ld_addrs.h"

extern s16 D_802809F6;
extern s32 D_80280A30;
extern s32 D_8029F254;

INCLUDE_ASM(s32, "code_16F740", func_80240E60);

INCLUDE_ASM(s32, "code_16F740", func_80240FDC);

void func_80241190(s32 battleState) {
    s32 flags = gBattleStatus.flags2;
    if (0) { do { } while (1); }
    gBattleState = battleState;
    gBattleStatus.unk_470 = 1;
    if (0) { do { } while (1); }

    gBattleStatus.battleState = 0;

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

INCLUDE_ASM(s32, "code_16F740", begin_battle);

void func_80241AB8(void) {
    set_transition_stencil_color(0, 0, 0, 0);

    if (D_80280A30 > 255) {
        set_transition_stencil_zoom_0(0, 255.0f);
    } else {
        set_transition_stencil_zoom_0(0, D_80280A30);
    }
}

INCLUDE_ASM(s32, "code_16F740", func_80241B14);

void func_8024201C(void) {
}

INCLUDE_ASM(s32, "code_16F740", update_heroes_start_turn);

void func_80242AC0(void) {
}

INCLUDE_ASM(s32, "code_16F740", switch_to_player);

void func_80242BA8(void) {
}

INCLUDE_ASM(s32, "code_16F740", update_end_player_turn);

void func_80242EF8(void) {
}

INCLUDE_ASM(s32, "code_16F740", switch_to_partner);

void func_80242FD8(void) {
}

INCLUDE_ASM(s32, "code_16F740", func_80242FE0);

void func_80243910(void) {
}

void switch_order(void) {
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

    dma_copy(&code_code_415D90_ROM_START, &code_code_415D90_ROM_END, &code_code_415D90_VRAM);

    // TODO Needed to match
    if (0) { s32 new_var; do { } while (new_var); }

    if (battleStatus->flags1 & 0x80000) {
        func_80241190(14);
    } else if (gBattleStatus.battleState == 70) {
        s32 oldBattleState = gBattleStatus.battleState;
        func_80241190(13);
        gBattleStatus.battleState = oldBattleState;
    } else {
        func_80241190(13);
    }
}

void func_802439D0(void) {
}

INCLUDE_ASM(s32, "code_16F740", func_802439D8);

void func_80243FD4(void) {
}

void func_80243FDC(void) {
    func_8024E40C(2);
    func_80241190(12);
}

void func_80244000(void) {
}

INCLUDE_ASM(s32, "code_16F740", func_80244008);

void func_80244708(void) {
}

INCLUDE_ASM(s32, "code_16F740", func_80244710);

void func_80244A48(void) {
}

INCLUDE_ASM(s32, "code_16F740", end_battle);

INCLUDE_ASM(s32, "code_16F740", func_80244D90);

INCLUDE_ASM(s32, "code_16F740", func_80244E38);

void func_80244EF8(void) {
}

INCLUDE_ASM(s32, "code_16F740", update_run_away);

void func_80245438(void) {
}

INCLUDE_ASM(s32, "code_16F740", func_80245440);

void func_802456B0(void) {
}

ApiStatus EnablePartnerBlur(ScriptInstance* script, s32 isInitialCall) {
    enable_partner_blur();
    return ApiStatus_DONE2;
}

ApiStatus DisablePartnerBlur(ScriptInstance* script, s32 isInitialCall) {
    disable_partner_blur();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_16F740", update_swap_partner);

void func_80245AC8(void) {
}

INCLUDE_ASM(s32, "code_16F740", update_player_action);

void func_80246448(void) {
}

INCLUDE_ASM(s32, "code_16F740", update_player_change_turn);

void func_80246B2C_code(void) {
}

INCLUDE_ASM(s32, "code_16F740", update_partner_action);

void func_80247214(void) {
}

// Something weird with using battleStatus twice but in specific ways
#ifdef NON_MATCHING
s32 func_80263434(void);
void func_8024721C(void) {
    BattleStatus* battleStatus;
    s32 battleState = gBattleStatus.battleState;

    if (0) { do {} while (1); }
    battleStatus = &gBattleStatus;

    if (battleState == 0) {
        battleStatus->flags2 |= 0x4;
        if (!func_80263434()) {
            battleStatus->flags1 &= ~0x80000;
            battleStatus->flags2 &= ~0x10;

            if (battleStatus->unk_94 < 0) {
                battleStatus->unk_94 = 0;
                func_80241190(6);
            } else {
                func_80241190(9);
            }
        }
    }
}
#else
INCLUDE_ASM(s32, "code_16F740", func_8024721C);
#endif


void func_802472A4(void) {
}

INCLUDE_ASM(s32, "code_16F740", update_enemy_change_turn);

void func_80247568(void) {
}

INCLUDE_ASM(s32, "code_16F740", update_enemy_action);

void func_80247AFC(void) {
}

INCLUDE_ASM(s32, "code_16F740", func_80247B04);

INCLUDE_ASM(s32, "code_16F740", func_802480F0);

INCLUDE_ASM(s32, "code_16F740", func_80248190);

void func_802485FC(void) {
    if (D_8029F254 != 0) {
        s32* temp_v0 = &D_80280A30;

        if (*temp_v0 == 0) {
            set_transition_stencil_zoom_0(255, -1.0f);
        } else {
            *temp_v0 -= 20;
            if (*temp_v0 < 0) {
                *temp_v0 = 0;
            }

            set_transition_stencil_zoom_0(0, *temp_v0);
        }
    }
}

INCLUDE_ASM(s32, "code_16F740", func_80248660);

void func_80248AA4(void) {
    if (D_8029F254 != 0) {
        s32* temp_v0 = &D_80280A30;

        if (*temp_v0 == 0) {
            set_transition_stencil_zoom_0(255, -1.0f);
        } else {
            *temp_v0 -= 20;
            if (*temp_v0 < 0) {
                *temp_v0 = 0;
            }

            set_transition_stencil_zoom_0(0, *temp_v0);
        }
    }
}

INCLUDE_ASM(s32, "code_16F740", func_80248B08);

void func_80248D78(void) {
    if (D_802809F6 == -1) {
        set_transition_stencil_color(0, 0, 0, 0);
        set_transition_stencil_zoom_0(0, D_80280A30);
    }
}
