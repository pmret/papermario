#include "common.h"

extern s32 D_80104A28;
extern s32 D_80107D48;
extern s32 D_80107D98;
extern s32 D_80107CA8;
extern s32 D_80107CD0;
extern s32 D_80107CF8;
extern s32 D_80107D20;
extern s32 D_80107D70;
extern s32 D_80107DC0;
extern s32 D_80107DE8;
extern s32 D_80107E10;
extern s32 D_80107E38;
extern s32 D_80107E60;
extern s32 D_80107E88;
extern s32 D_80107EB0;
extern s32 D_80107ED8;
extern s32 D_80107F00;
extern s32 D_80107F28;
extern s32 D_80107F50;
extern s32 D_80107FC8;
extern s32 D_80107FF0;
extern s32 D_80108974;

extern u8 D_802AD000;
extern u8 D_802AD001;
extern s16 D_802AD006;
extern s16 D_802AD008;
extern s32* D_802AD010;
extern s32* D_802AD028;
extern s32 D_802AD040;
extern s32 D_802AD044;
extern s32 D_802AD048;
extern s32 D_802AD04C;
extern s32 D_802AD05C;
extern s32 D_802AD050;
extern s32 D_802AD054;
extern s32 D_802AD058;
extern s8 D_802AD068;
extern s32 main_menu_numOptions;
extern s8 D_802AD10F;
extern u8 battle_menu_moveState;
extern s16 battle_menu_moveTextColor;
extern s16 battle_menu_moveTextOpacity;
extern s32 battle_menu_moveCursorIcon;
extern s32 battle_menu_moveUpArrowIcon;
extern s32 battle_menu_moveDownArrowIcon;
extern s32* battle_menu_moveOptionIconIDs;
extern s32 battle_menu_moveTitleIcon;
extern s32* battle_menu_moveOptionCostUnitIconIDs;
extern s32 D_802AD258;
extern s32 battle_menu_hasSpiritsMenu;
extern s32 battle_menu_moveOptionCount;
extern s8 D_802AD604;
extern s8 D_802AD605;
extern s8 D_802AD60B;
extern s32 D_802AD610;
extern s8 D_802AD614;
extern s32 D_802AD618;
extern s32 D_802AD61C;
extern s32 D_802AD620;
extern s32 D_802AD624;
extern s32 D_802AD628;
extern s32 D_802AD66C;
extern s32* D_802AD6C0[];

s16 D_802AB340[] = { 0x001C, 0x0028 };

s16 D_802AB344[] = { 0, -2 };

s32 battle_menu_iconScripts[] = { 0x8010876C, 0x8010876C, 0x80108744, 0x8010876C, 0x80108794, 0x801087BC, 0x801087E4, 0x8010880C };

s32 D_802AB368[] = { 0x8010885C, 0x8010885C, 0x80108834, 0x8010885C, 0x80108884, 0x801088AC, 0x801088D4, 0x801088FC };

s32 D_802AB388[] = { 0x80108924, 0x8010894C };

s32 D_802AB390[] = { &D_80108974, 0x8010899C };

s32 D_802AB398[] = { &D_80108974, 0x8010899C, 0x80107990, 0x801079BC, 0x801079E8, 0x80107A14, 0x80107A40, 0x80107A6C, 0x80107A98, 0x80107AC4, 0x80107AF0, 0x80107B1C, 0x80107B48, 0x80107B74, 0x80107BA0, 0x80107BCC, 0x80107BF8, 0x80107C24, 0x80107C50, 0x80107C7C, &D_80108974, 0x8010899C, &D_80108974, 0x8010899C };

s32 D_802AB3F8[] = { &D_80107CA8, &D_80107CF8, &D_80107D48, &D_80107D98, &D_80107DE8, &D_80107CA8, &D_80107E88, &D_80107ED8, &D_80107F28, &D_80107E38, &D_80107FC8, &D_80107FC8, &D_80107FC8, &D_80107FC8, &D_80107FC8, &D_80107FC8 };

s32 D_802AB438[] = { &D_80107CD0, &D_80107D20, &D_80107D70, &D_80107DC0, &D_80107E10, &D_80107CD0, &D_80107EB0, &D_80107F00, &D_80107F50, &D_80107E60, &D_80107FF0, &D_80107FF0, &D_80107FF0, &D_80107FF0, &D_80107FF0, &D_80107FF0 };

s32 D_802AB478[] = { 0x80292200 };

s32 D_802AB47C[] = { 0x80292228 };

s32 D_802AB480[] = { 0x802922A0, 0x802922C8 };

s32 D_802AB488[] = { 0x80292160, 0x80292188 };

s32 battle_menu_leftJustfiedMessages[] = { 0x001D0039, 0x001D0038, 0x001D003F, 0x001D003B, 0x001D0044 };

s32 D_802AB4A4[] = { 0x001D003E, 0x001D0045, 0x001D0043, 0x001D003A };

s32 D_802AB4B4[] = { 0x001D003C, 0x001D0046, 0x001D0048 };

s32 battle_menu_centeredMessages[] = { 0x001D004B, 0x001D004A };

s32 D_802AB4C8[] = { 0x001D0050, 0x001D004D, 0x001D0052, 0x001D004F, 0x001D0053 };

s32 D_802AB4DC[] = { 0x001D0051 };

s32 D_802AB4E0[] = { 0x001D004C, 0x001D004E, 0x001D0056, 0x001D0055 };

s8 D_802AB4F0[] = { 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x39, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x37, };

// s8 D_802AB513

s32 D_802AB520[] = { 0x00000000, 0x00090012, 0x000A001A, 0x000B001C, 0x000C0017, 0x009D0001, 0x000E000B, 0x000F0012, 0x00100003, 0x000D0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

s32 D_802AB558[] = { 0x00000000, 0x00090002, 0x000A0005, 0x000B0006, 0x000C0002, 0x009D0002, 0x000E0002, 0x000F0002, 0x00100002, 0x000D0002, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

s32 D_802AB590[] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, &D_80107CF8, &D_80107D20, 0x80109338, 0x801093D8, 0x80109360, 0x80109400, 0x80109388, 0x80109428, 0x801093B0, 0x80109450, &D_80107D48, &D_80107D70, 0x80109338, 0x801093D8, 0x80109360, 0x80109400, 0x80109388, 0x80109428, 0x801093B0, 0x80109450, &D_80107D98, &D_80107DC0, 0x80109338, 0x801093D8, 0x80109360, 0x80109400, 0x80109388, 0x80109428, 0x801093B0, 0x80109450, &D_80107DE8, &D_80107E10, 0x80109338, 0x801093D8, 0x80109360, 0x80109400, 0x80109388, 0x80109428, 0x801093B0, 0x80109450, &D_80107CA8, &D_80107CD0, 0x80109338, 0x801093D8, 0x80109360, 0x80109400, 0x80109388, 0x80109428, 0x801093B0, 0x80109450, &D_80107E88, &D_80107EB0, 0x80109338, 0x801093D8, 0x80109360, 0x80109400, 0x80109388, 0x80109428, 0x801093B0, 0x80109450, &D_80107ED8, &D_80107F00, 0x80109338, 0x801093D8, 0x80109360, 0x80109400, 0x80109388, 0x80109428, 0x801093B0, 0x80109450, &D_80107F28, &D_80107F50, 0x80109338, 0x801093D8, 0x80109360, 0x80109400, 0x80109388, 0x80109428, 0x801093B0, 0x80109450, &D_80107E38, &D_80107E60, 0x80109338, 0x801093D8, 0x80109360, 0x80109400, 0x80109388, 0x80109428, 0x801093B0, 0x80109450 };

s32 D_802AB720[] = { &D_80108974, 0x8010899C };

s32 D_802AB728[] = { 0x001D0055 };

s32 D_802AB72C[] = { &D_80108974, 0x8010899C };

s32 D_802AB734[] = { 0x001D0057 };

s32 D_802AB738[] = { 0x00000000, 0x001D0007, 0x001D0008, 0x001D0009, 0x001D000A, 0x001D000B, 0x001D000C, 0x001D000D, 0x001D000E, 0x001D000F, 0x001D0010, 0x001D0011, 0x001D0012, 0x00000000 };

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

void func_802A10B8(void) {
    s32 i;

    for (i = 0; i < main_menu_numOptions; i++) {
        s32* icons1 = &D_802AD010;
        s32* icons2 = &D_802AD028;

        free_icon(icons1[i]);
        free_icon(icons2[i]);
    }

    free_icon(D_802AD040);
    free_icon(D_802AD044);
    free_icon(D_802AD048);
    free_icon(D_802AD04C);
    free_icon(D_802AD05C);
    free_icon(D_802AD050);
    free_icon(D_802AD054);
    free_icon(D_802AD058);
}

INCLUDE_ASM(s32, "code_415D90", func_802A11B0);

INCLUDE_ASM(s32, "code_415D90", draw_battle_wheel);

INCLUDE_ASM(s32, "code_415D90", func_802A2684);

void func_802A27D0(void) {
    battle_menu_moveState = 10;
}

INCLUDE_ASM(s32, "code_415D90", func_802A27E4);

void func_802A2910(void) {
    s32* moveOptionIconIDs;
    s32* moveOptionCostUnitIconIDs;
    s32 i;

    moveOptionIconIDs = &battle_menu_moveOptionIconIDs;

    for (i = 0; i < battle_menu_moveOptionCount; i++) {
        icon_set_tint(moveOptionIconIDs[i], 255, 255, 255);
    }

    icon_set_tint(battle_menu_moveCursorIcon, 255, 255, 255);
    icon_set_tint(battle_menu_moveUpArrowIcon, 255, 255, 255);
    icon_set_tint(battle_menu_moveDownArrowIcon, 255, 255, 255);
    icon_set_tint(battle_menu_moveTitleIcon, 255, 255, 255);

    moveOptionCostUnitIconIDs = &battle_menu_moveOptionCostUnitIconIDs;

    for (i = 0; i < battle_menu_moveOptionCount; i++) {
        icon_set_tint(moveOptionCostUnitIconIDs[i], 255, 255, 255);
    }

    set_menu_icon_script(battle_menu_moveCursorIcon, &D_80104A28);
    set_window_update(1, 5);

    if (!battle_menu_hasSpiritsMenu) {
        set_window_update(2, 5);
        set_window_update(3, 5);
    } else {
        set_window_update(4, 5);
        set_window_update(5, 5);
    }

    set_window_update(8, 1);
    battle_menu_moveTextColor = 10;
    D_802AD10F = 1;
    battle_menu_moveTextOpacity = 255;
    battle_menu_moveState = 1;
}

void func_802A2AB8(void) {
    s32* moveOptionIconIDs;
    s32* moveOptionCostUnitIconIDs;
    s32 i;

    set_window_update(1, 5);

    if (!battle_menu_hasSpiritsMenu) {
        set_window_update(2, 5);
        set_window_update(3, 5);
    } else {
        set_window_update(4, 5);
        set_window_update(5, 5);
    }
    set_window_update(8, 1);

    moveOptionIconIDs = &battle_menu_moveOptionIconIDs;

    for (i = 0; i < battle_menu_moveOptionCount; i++) {
        icon_set_tint(moveOptionIconIDs[i], 255, 255, 255);
    }

    icon_set_tint(battle_menu_moveCursorIcon, 255, 255, 255);
    icon_set_tint(battle_menu_moveUpArrowIcon, 255, 255, 255);
    icon_set_tint(battle_menu_moveDownArrowIcon, 255, 255, 255);
    icon_set_tint(battle_menu_moveTitleIcon, 255, 255, 255);

    moveOptionCostUnitIconIDs = &battle_menu_moveOptionCostUnitIconIDs;

    for (i = 0; i < battle_menu_moveOptionCount; i++) {
        icon_set_tint(moveOptionCostUnitIconIDs[i], 255, 255, 255);
    }

    set_menu_icon_script(battle_menu_moveCursorIcon, &D_80104A28);
    battle_menu_moveTextColor = 10;
    D_802AD10F = 1;
    battle_menu_moveState = 20;
}

void func_802A2C58(void) {
    set_window_update(8, 1);
    battle_menu_moveState = 30;
}

INCLUDE_ASM(s32, "code_415D90", func_802A2C84);

INCLUDE_ASM(s32, "code_415D90", func_802A3C98);

void func_802A43DC(s32 arg0, s32 arg1, s32 arg2) {
    s32 phi_a0;
    s32 phi_a1;
    s32 phi_a2;
    s32 phi_a3;
    s32 phi_v0;

    if (!battle_menu_hasSpiritsMenu) {
        phi_a0 = 0x1D0045;
        phi_a1 = arg1 + 0x10;
        phi_a2 = arg2 + 2;
        phi_a3 = battle_menu_moveTextOpacity;
        phi_v0 = 0x30;
    } else {
        phi_a0 = 0x1D003A;
        phi_a1 = arg1 + 6;
        phi_a2 = arg2 + 2;
        phi_a3 = battle_menu_moveTextOpacity;
        phi_v0 = 0x31;
    }
    draw_msg(phi_a0, phi_a1, phi_a2, phi_a3, phi_v0, 1);
}

void func_802A4448(s32 arg0, s32 arg1, s32 arg2) {
    s32 icon = battle_menu_moveTitleIcon;

    set_icon_render_pos(icon, arg1 + 0x10, arg2 + 0xF);
    icon_set_opacity(icon, battle_menu_moveTextOpacity);
    draw_icon_0(icon);
}

INCLUDE_ASM(s32, "code_415D90", func_802A4494);

void func_802A4534(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp2 = arg2;
    s32 temp1;
    s32 phi_s0;

    temp2 += 6;
    temp1 = arg1 + 11;

    if (D_802AD258 != 0) {
        phi_s0 = 0x1D00C3;
    } else if (battle_menu_hasSpiritsMenu == 0) {
        phi_s0 = 0x1D009F;
    } else {
        phi_s0 = 0x1D00A0;
    }
    draw_msg(phi_s0, temp1, temp2 + D_802AB344[get_msg_lines(phi_s0) - 1], 255, 0xF, 0);
}

INCLUDE_ASM(s32, "code_415D90", func_802A45D8);


void func_802A4718(void) {
    D_802AD604 = 10;
}

//INCLUDE_ASM(s32, "code_415D90", func_802A472C);
void func_802A472C(void) {
    s32* temp = &D_802AD628;
    s32 i;

    set_window_update(6, 2);
    set_window_update(7, 2);
    set_window_update(8, 2);

    for (i = 0; i < D_802AD66C; i++) {
        free_icon(temp[i]);
    }

    free_icon(D_802AD618);
    free_icon(D_802AD61C);
    free_icon(D_802AD620);
}

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

#ifdef NON_MATCHING
void func_802A5738(s32 arg0, s32 arg1, s32 arg2) {
    s32 id;

    switch (D_802AD604) {
        case -1:
        case 1:
        case 10:
        case 20:
        case 30:
            if (D_802AD60B != 0) {
                draw_msg(D_802AD6C0[D_802AD605], arg1 + 8, arg2, D_802AD624, D_802AD614, 0);
            }
            break;
    }
}
#else
INCLUDE_ASM(s32, "code_415D90", func_802A5738);
#endif

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

s32 func_802A58D0(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    s8 partnerDebuff;
    s32 ret;

    if (battleStatus->flags2 & 4 || partner == PartnerID_NONE || partner->flags & 0x200000) {
        return FALSE;
    }

    partnerDebuff = partner->debuff;
    ret = partner->koStatus == 0xD;

    if (partnerDebuff == 9) {
        ret = FALSE;
    }
    if (partnerDebuff == 10) {
        ret = FALSE;
    }
    if (partnerDebuff == 6) {
        ret = TRUE;
    }
    if (partnerDebuff == 3) {
        ret = TRUE;
    }
    if (partnerDebuff == 5) {
        ret = TRUE;
    }
    if (partnerDebuff == 7) {
        ret = TRUE;
    }
    if (partnerDebuff == 8) {
        ret = TRUE;
    }
    if (partner->stoneStatus == 0xC) {
        ret = TRUE;
    }
    return !ret;
}

INCLUDE_ASM(s32, "code_415D90", update_player_menu);

INCLUDE_ASM(s32, "code_415D90", func_802A8180);

INCLUDE_ASM(s32, "code_415D90", update_partner_menu);

INCLUDE_ASM(s32, "code_415D90", func_802A9AE8);

s32 func_802A9B30(void) {
    return (gBattleStatus.flags2 & 4) <= 0;
}

INCLUDE_ASM(s32, "code_415D90", func_802A9B44);

INCLUDE_ASM(s32, "code_415D90", func_802AA05C);
// void func_802AA05C(void) {
//     switch (gBattleStatus.battleState) {
//         case 1:
//             draw_battle_wheel();
//             break;
//         case 2:
//             draw_battle_wheel();
//             break;
//         case 3:
//             draw_battle_wheel();
//             break;
//         case 4:
//             draw_battle_wheel();
//             break;
//         case 5:
//             draw_battle_wheel();
//             break;
//         case 6:
//         case 7:
//         case 8:
//         case 9:
//             break;
//     }
// }

s32 func_802AA0A4(void) {
    return (gBattleStatus.flags2 & 2) <= 0;
}

INCLUDE_ASM(s32, "code_415D90", func_802AA0B8); // look into m2c bug

void func_802AA640(void) {
    switch (gBattleStatus.battleState) {
        case 1:
            draw_battle_wheel();
            break;
        case 2:
            draw_battle_wheel();
            break;
        case 3:
            draw_battle_wheel();
            break;
        case 4:
            draw_battle_wheel();
            break;
        case 5:
            draw_battle_wheel();
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            break;
    }
}

INCLUDE_ASM(s32, "code_415D90", update_targeting_enemies);

INCLUDE_ASM(s32, "code_415D90", func_802AACD8);

void func_802AB330(void){
}

void func_802AB338(void){
}
