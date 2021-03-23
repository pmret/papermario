#include "common.h"

extern u8 D_802AD000;
extern u8 D_802AD001;
extern s16 D_802AD006;
extern s16 D_802AD008;
extern s8 D_802AD068;
extern u8 battle_menu_moveState;
extern u8 D_802AD604;
extern s32 D_802AD624;

void func_802A1000(void) {
    D_802AD006 = 255;
    D_802AD008 = 255;
    D_802AD000 = 0;
    D_802AD068 = -1;
}

void func_802A1030(void) {
    D_802AD001 = 3;
    D_802AD000 = 10;
}

void func_802A1050(void) {
    D_802AD000 = 2;
    D_802AD006 = 255;
    D_802AD008 = 255;
}

void func_802A1078(void) {
    D_802AD008 = 255;
    D_802AD000 = 20;
}

void func_802A1098(void) {
    D_802AD008 = 100;
    D_802AD000 = 30;
}

INCLUDE_ASM(s32, "code_415D90", func_802A10B8);

INCLUDE_ASM(s32, "code_415D90", func_802A11B0);

INCLUDE_ASM(s32, "code_415D90", draw_battle_wheel);

INCLUDE_ASM(s32, "code_415D90", func_802A2684);

void func_802A27D0(void) {
    battle_menu_moveState = 10;
}

INCLUDE_ASM(s32, "code_415D90", func_802A27E4);

INCLUDE_ASM(s32, "code_415D90", func_802A2910);

INCLUDE_ASM(s32, "code_415D90", func_802A2AB8);

void func_802A2C58(void) {
    set_window_update(8, 1);
    battle_menu_moveState = 30;
}

INCLUDE_ASM(s32, "code_415D90", func_802A2C84);

INCLUDE_ASM(s32, "code_415D90", func_802A3C98);

INCLUDE_ASM(s32, "code_415D90", func_802A43DC);

INCLUDE_ASM(s32, "code_415D90", func_802A4448);

INCLUDE_ASM(s32, "code_415D90", func_802A4494);

INCLUDE_ASM(s32, "code_415D90", func_802A4534);

INCLUDE_ASM(s32, "code_415D90", func_802A45D8);


void func_802A4718(void) {
    D_802AD604 = 10;
}

INCLUDE_ASM(s32, "code_415D90", func_802A472C);

INCLUDE_ASM(s32, "code_415D90", func_802A47E0);

INCLUDE_ASM(s32, "code_415D90", func_802A48FC);

void func_802A4A10(void) {
    set_window_update(6, 5);
    set_window_update(7, 5);
    set_window_update(8, 1);
    D_802AD604 = 30;
}

INCLUDE_ASM(s32, "code_415D90", func_802A4A54);

INCLUDE_ASM(s32, "code_415D90", func_802A5290);

void func_802A56F8(s32 arg0, s32 arg1, s32 arg2) {
    draw_msg(0x1D0043, arg1 + 0xF, arg2 + 2, D_802AD624, 0x33, 1);
}

INCLUDE_ASM(s32, "code_415D90", func_802A5738);

INCLUDE_ASM(s32, "code_415D90", func_802A57C8);

s32 can_switch_to_player(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;

    if (battleStatus->flags2 & 2) {
        return FALSE;
    } else {
        s8 debuff = player->debuff;
        s32 ret = player->koStatus == 0xD;

        if (debuff == 9) {
           ret = FALSE;
        }
        if (debuff == 10) {
           ret = FALSE;
        }
        if (debuff == 6) {
           ret = TRUE;
        }
        if (debuff == 3) {
           ret = TRUE;
        }
        if (debuff == 4) {
           ret = TRUE;
        }
        if (debuff == 5) {
           ret = TRUE;
        }
        if (debuff == 7) {
           ret = TRUE;
        }
        if (debuff == 8) {
           ret = TRUE;
        }
        if (player->stoneStatus == 0xC) {
           ret = TRUE;
        }
        if (battleStatus->outtaSightActive) {
           ret = TRUE;
        }
        return !ret;
    }
}

INCLUDE_ASM(s32, "code_415D90", func_802A58D0);

INCLUDE_ASM(s32, "code_415D90", update_player_menu);

INCLUDE_ASM(s32, "code_415D90", func_802A8180);

INCLUDE_ASM(s32, "code_415D90", update_partner_menu);

INCLUDE_ASM(s32, "code_415D90", func_802A9AE8);

s32 func_802A9B30(void) {
    return (gBattleStatus.flags2 & 4) <= 0;
}

INCLUDE_ASM(s32, "code_415D90", func_802A9B44);

INCLUDE_ASM(s32, "code_415D90", func_802AA05C);

s32 func_802AA0A4(void) {
    return (gBattleStatus.flags2 & 2) <= 0;
}

INCLUDE_ASM(s32, "code_415D90", func_802AA0B8);

INCLUDE_ASM(s32, "code_415D90", func_802AA640);

INCLUDE_ASM(s32, "code_415D90", update_targeting_enemies);

INCLUDE_ASM(s32, "code_415D90", func_802AACD8);

void func_802AB330(void){
}

void func_802AB338(void){
}
