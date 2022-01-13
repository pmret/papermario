#include "common.h"
#include "hud_element.h"

extern HudElementAnim HudScript_Kooper[];
extern HudElementAnim HudScript_Bombette[];
extern HudElementAnim HudScript_Partner0[];
extern HudElementAnim HudScript_Partner0Disabled[];
extern HudElementAnim HudScript_Goombario[];
extern HudElementAnim HudScript_GoombarioDisabled[];
extern HudElementAnim HudScript_KooperDisabled[];
extern HudElementAnim HudScript_BombetteDisabled[];
extern HudElementAnim HudScript_Parakarry[];
extern HudElementAnim HudScript_ParakarryDisabled[];
extern HudElementAnim HudScript_Bow[];
extern HudElementAnim HudScript_BowDisabled[];
extern HudElementAnim HudScript_Watt[];
extern HudElementAnim HudScript_WattDisabled[];
extern HudElementAnim HudScript_Sushie[];
extern HudElementAnim HudScript_SushieDisabled[];
extern HudElementAnim HudScript_Lakilester[];
extern HudElementAnim HudScript_LakilesterDisabled[];
extern HudElementAnim HudScript_PartnerA[];
extern HudElementAnim HudScript_PartnerADisabled[];

extern HudElementAnim HudScript_MenuBoots1[];
extern HudElementAnim HudScript_MenuBoots1Disabled[];
extern HudElementAnim HudScript_MenuBoots2[];
extern HudElementAnim HudScript_MenuBoots2Disabled[];
extern HudElementAnim HudScript_MenuBoots3[];
extern HudElementAnim HudScript_MenuBoots3Disabled[];

extern HudElementAnim HudScript_MenuHammer1[];
extern HudElementAnim HudScript_MenuHammer1Disabled[];
extern HudElementAnim HudScript_MenuHammer2[];
extern HudElementAnim HudScript_MenuHammer2Disabled[];
extern HudElementAnim HudScript_MenuHammer3[];
extern HudElementAnim HudScript_MenuHammer3Disabled[];

extern HudElementAnim HudScript_MenuItem[];
extern HudElementAnim HudScript_MenuItemDisabled[];

extern HudElementAnim HudScript_MenuStarPower[];
extern HudElementAnim HudScript_MenuStarPowerDisabled[];

extern HudElementAnim HudScript_Eldstar[];
extern HudElementAnim HudScript_EldstarDisabled[];
extern HudElementAnim HudScript_Mamar[];
extern HudElementAnim HudScript_MamarDisabled[];
extern HudElementAnim HudScript_Skolar[];
extern HudElementAnim HudScript_SkolarDisabled[];
extern HudElementAnim HudScript_Muskular[];
extern HudElementAnim HudScript_MuskularDisabled[];
extern HudElementAnim HudScript_Misstar[];
extern HudElementAnim HudScript_MisstarDisabled[];
extern HudElementAnim HudScript_Klevar[];
extern HudElementAnim HudScript_KlevarDisabled[];
extern HudElementAnim HudScript_Kalmar[];
extern HudElementAnim HudScript_KalmarDisabled[];
extern HudElementAnim HudScript_StarBeam[];
extern HudElementAnim HudScript_StarBeamDisabled[];
extern HudElementAnim HudScript_PeachBeam[];
extern HudElementAnim HudScript_PeachBeamDisabled[];

extern HudElementAnim D_80109338[];
extern HudElementAnim D_80109360[];
extern HudElementAnim D_80109388[];
extern HudElementAnim D_801093B0[];
extern HudElementAnim D_801093D8[];
extern HudElementAnim D_80109400[];
extern HudElementAnim D_80109428[];
extern HudElementAnim D_80109450[];

extern u8 D_802AD000;
extern u8 D_802AD001;
extern s16 D_802AD006;
extern s16 D_802AD008;
extern s32 D_802AD010[];
extern s32 D_802AD028[];
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
extern s8 D_802AD10A;
extern s8 D_802AD10D;
extern s8 D_802AD10E;
extern s8 D_802AD10F;
extern s16 D_802AD112;
extern s32 battle_menu_moveOptionActive;
extern s8 battle_menu_moveScrollLine;
extern s16 battle_menu_moveScrollOffset;
extern u8 battle_menu_moveState;
extern s8 battle_menu_moveCursorPos;
extern s32 battle_menu_moveOptionDescriptions[24];
extern s32 battle_menu_moveOptionIndexMap[24];
extern s16 battle_menu_moveTextColor;
extern s16 battle_menu_moveTextOpacity;
extern s32 battle_menu_moveCursorIcon;
extern s32 battle_menu_moveUpArrowIcon;
extern s32 battle_menu_moveDownArrowIcon;
extern s32 battle_menu_moveOptionIconIDs[24];
extern s32 battle_menu_moveTitleIcon;
extern s32 battle_menu_moveOptionCostUnitIconIDs[24];

extern s32 D_802AD258;
extern s32 D_802AD4A8;
extern s32 battle_menu_hasSpiritsMenu;
extern s32 battle_menu_moveOptionCount;
extern s8 D_802AD604;
extern s8 D_802AD605;
extern u8 D_802AD606;
extern s8 D_802AD607;
extern s8 D_802AD608;
extern s8 D_802AD609;
extern s8 D_802AD60A;
extern s8 D_802AD60B;
extern s16 D_802AD60C;
extern s16 D_802AD60E;
extern s16 D_802AD610;
extern s8 D_802AD614;
extern s32 D_802AD618;
extern s32 D_802AD61C;
extern s32 D_802AD620;
extern s32 D_802AD624;
extern s32 D_802AD628[];
extern s32 D_802AD658[]; // msg IDs
extern s32 D_802AD66C;
extern s8 D_802AD673;
extern s32 D_802AD678[];
extern s32 D_802AD690[];
extern s32 D_802AD6C0[];
extern s32 D_802AD6D4;

s16 D_802AB340[] = { 0x001C, 0x0028 };

s16 D_802AB344[] = { 0, -2 };

HudElementAnim* battle_menu_iconScripts[] = {
    HudScript_MenuBoots1Disabled, HudScript_MenuBoots1Disabled,
    HudScript_MenuBoots1,HudScript_MenuBoots1Disabled,
    HudScript_MenuBoots2, HudScript_MenuBoots2Disabled,
    HudScript_MenuBoots3, HudScript_MenuBoots3Disabled };

HudElementAnim* battle_menu_HammerHudScripts[] = {
    HudScript_MenuHammer1Disabled, HudScript_MenuHammer1Disabled,
    HudScript_MenuHammer1, HudScript_MenuHammer1Disabled,
    HudScript_MenuHammer2, HudScript_MenuHammer2Disabled,
    HudScript_MenuHammer3, HudScript_MenuHammer3Disabled };

HudElementAnim* battle_menu_ItemHudScripts[] = { HudScript_MenuItem, HudScript_MenuItemDisabled };

HudElementAnim* battle_menu_StarPowerHudScripts[] = { HudScript_MenuStarPower, HudScript_MenuStarPowerDisabled };

HudElementAnim* StarPowerHudScripts[] = { HudScript_MenuStarPower, HudScript_MenuStarPowerDisabled, HudScript_Eldstar, HudScript_EldstarDisabled,
    HudScript_Mamar, HudScript_MamarDisabled, HudScript_Skolar, HudScript_SkolarDisabled,
    HudScript_Muskular, HudScript_MuskularDisabled, HudScript_Misstar, HudScript_MisstarDisabled,
    HudScript_Klevar, HudScript_KlevarDisabled, HudScript_Kalmar, HudScript_KalmarDisabled,
    HudScript_StarBeam, HudScript_StarBeamDisabled, HudScript_PeachBeam, HudScript_PeachBeamDisabled,
    HudScript_MenuStarPower, HudScript_MenuStarPowerDisabled, HudScript_MenuStarPower, HudScript_MenuStarPowerDisabled };

HudElementAnim* D_802AB3F8[] = { HudScript_Partner0, HudScript_Goombario, HudScript_Kooper, HudScript_Bombette,
    HudScript_Parakarry, HudScript_Partner0, HudScript_Watt, HudScript_Sushie,
    HudScript_Lakilester, HudScript_Bow, HudScript_PartnerA, HudScript_PartnerA,
    HudScript_PartnerA, HudScript_PartnerA, HudScript_PartnerA, HudScript_PartnerA };

HudElementAnim* D_802AB438[] = { HudScript_Partner0Disabled, HudScript_GoombarioDisabled, HudScript_KooperDisabled, HudScript_BombetteDisabled,
    HudScript_ParakarryDisabled, HudScript_Partner0Disabled, HudScript_WattDisabled, HudScript_SushieDisabled,
    HudScript_LakilesterDisabled, HudScript_BowDisabled, HudScript_PartnerADisabled, HudScript_PartnerADisabled,
    HudScript_PartnerADisabled, HudScript_PartnerADisabled, HudScript_PartnerADisabled, HudScript_PartnerADisabled };

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

HudElementAnim* D_802AB590[] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, HudScript_Goombario, HudScript_GoombarioDisabled, D_80109338, D_801093D8, D_80109360, D_80109400, D_80109388, D_80109428, D_801093B0, D_80109450, HudScript_Kooper, HudScript_KooperDisabled, D_80109338, D_801093D8, D_80109360, D_80109400, D_80109388, D_80109428, D_801093B0, D_80109450, HudScript_Bombette, HudScript_BombetteDisabled, D_80109338, D_801093D8, D_80109360, D_80109400, D_80109388, D_80109428, D_801093B0, D_80109450, HudScript_Parakarry, HudScript_ParakarryDisabled, D_80109338, D_801093D8, D_80109360, D_80109400, D_80109388, D_80109428, D_801093B0, D_80109450, HudScript_Partner0, HudScript_Partner0Disabled, D_80109338, D_801093D8, D_80109360, D_80109400, D_80109388, D_80109428, D_801093B0, D_80109450, HudScript_Watt, &HudScript_WattDisabled, D_80109338, D_801093D8, D_80109360, D_80109400, D_80109388, D_80109428, D_801093B0, D_80109450, HudScript_Sushie, HudScript_SushieDisabled, D_80109338, D_801093D8, D_80109360, D_80109400, D_80109388, D_80109428, D_801093B0, D_80109450, HudScript_Lakilester, HudScript_LakilesterDisabled, D_80109338, D_801093D8, D_80109360, D_80109400, D_80109388, D_80109428, D_801093B0, D_80109450, &HudScript_Bow, HudScript_BowDisabled, D_80109338, D_801093D8, D_80109360, D_80109400, D_80109388, D_80109428, D_801093B0, D_80109450 };

HudElementAnim* D_802AB720[] = { HudScript_MenuStarPower, HudScript_MenuStarPowerDisabled };

s32 D_802AB728[] = { 0x001D0055 };

HudElementAnim* D_802AB72C[] = { HudScript_MenuStarPower, HudScript_MenuStarPowerDisabled };

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
        s32* icons1 = D_802AD010;
        s32* icons2 = D_802AD028;

        free_hud_element(icons1[i]);
        free_hud_element(icons2[i]);
    }

    free_hud_element(D_802AD040);
    free_hud_element(D_802AD044);
    free_hud_element(D_802AD048);
    free_hud_element(D_802AD04C);
    free_hud_element(D_802AD05C);
    free_hud_element(D_802AD050);
    free_hud_element(D_802AD054);
    free_hud_element(D_802AD058);
}

INCLUDE_ASM(s32, "415D90", func_802A11B0);

void btl_draw_menu_wheel(void);
INCLUDE_ASM(s32, "415D90", btl_draw_menu_wheel);

// Very similar to func_802A45D8 - maybe can be used to reduce fake matches there
void func_802A2684(void) {
    if (D_802AD4A8 >= battle_menu_moveOptionCount) {
        D_802AD4A8 = battle_menu_moveOptionCount - 1;
    }

    battle_menu_moveState = 0;
    battle_menu_moveScrollLine = 0;
    battle_menu_moveCursorPos = D_802AD4A8;
    D_802AD10A = D_802AD4A8;
    D_802AD10E = battle_menu_moveOptionCount;

    if (D_802AD10E > 6) {
        D_802AD10E = 6;
    }

    D_802AD10D = 6;
    if (battle_menu_moveOptionCount < 6) {
        D_802AD10D = battle_menu_moveOptionCount;
    }

    battle_menu_moveTextOpacity = 255;
    D_802AD10F = 1;

    if (D_802AD10A < 0) {
        battle_menu_moveScrollLine = D_802AD10A;
    }
    if (D_802AD10A >= D_802AD10D) {
        battle_menu_moveScrollLine = D_802AD10A + 1 - D_802AD10E;
    }

    D_802AD10D = battle_menu_moveScrollLine + 6;
    if (D_802AD10D > battle_menu_moveOptionCount) {
        D_802AD10D = battle_menu_moveOptionCount;
    }

    battle_menu_moveScrollOffset = -battle_menu_moveScrollLine * 13;
    D_802AD112 = (D_802AD10A - battle_menu_moveScrollLine) * 13;
    battle_menu_moveOptionActive = 0;
}

void func_802A27D0(void) {
    battle_menu_moveState = 10;
}

void func_802A27E4(void) {
    s32 i;

    set_window_update(1, 2);

    if (!battle_menu_hasSpiritsMenu) {
        set_window_update(2, 2);
        set_window_update(3, 2);
    } else {
        set_window_update(4, 2);
        set_window_update(5, 2);
    }

    set_window_update(8, 2);

    for (i = 0; i < battle_menu_moveOptionCount; i++) {
        free_hud_element(battle_menu_moveOptionIconIDs[i]);
    }

    free_hud_element(battle_menu_moveCursorIcon);
    free_hud_element(battle_menu_moveUpArrowIcon);
    free_hud_element(battle_menu_moveDownArrowIcon);
    free_hud_element(battle_menu_moveTitleIcon);

    for (i = 0; i < battle_menu_moveOptionCount; i++) {
        free_hud_element(battle_menu_moveOptionCostUnitIconIDs[i]);
    }
}

void func_802A2910(void) {
    s32* moveOptionIconIDs;
    s32* moveOptionCostUnitIconIDs;
    s32 i;

    moveOptionIconIDs = battle_menu_moveOptionIconIDs;

    for (i = 0; i < battle_menu_moveOptionCount; i++) {
        set_hud_element_tint(moveOptionIconIDs[i], 255, 255, 255);
    }

    set_hud_element_tint(battle_menu_moveCursorIcon, 255, 255, 255);
    set_hud_element_tint(battle_menu_moveUpArrowIcon, 255, 255, 255);
    set_hud_element_tint(battle_menu_moveDownArrowIcon, 255, 255, 255);
    set_hud_element_tint(battle_menu_moveTitleIcon, 255, 255, 255);

    moveOptionCostUnitIconIDs = battle_menu_moveOptionCostUnitIconIDs;

    for (i = 0; i < battle_menu_moveOptionCount; i++) {
        set_hud_element_tint(moveOptionCostUnitIconIDs[i], 255, 255, 255);
    }

    set_hud_element_anim(battle_menu_moveCursorIcon, HudScript_AnimatedHandPointer);
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

    moveOptionIconIDs = battle_menu_moveOptionIconIDs;

    for (i = 0; i < battle_menu_moveOptionCount; i++) {
        set_hud_element_tint(moveOptionIconIDs[i], 255, 255, 255);
    }

    set_hud_element_tint(battle_menu_moveCursorIcon, 255, 255, 255);
    set_hud_element_tint(battle_menu_moveUpArrowIcon, 255, 255, 255);
    set_hud_element_tint(battle_menu_moveDownArrowIcon, 255, 255, 255);
    set_hud_element_tint(battle_menu_moveTitleIcon, 255, 255, 255);

    moveOptionCostUnitIconIDs = battle_menu_moveOptionCostUnitIconIDs;

    for (i = 0; i < battle_menu_moveOptionCount; i++) {
        set_hud_element_tint(moveOptionCostUnitIconIDs[i], 255, 255, 255);
    }

    set_hud_element_anim(battle_menu_moveCursorIcon, HudScript_AnimatedHandPointer);
    battle_menu_moveTextColor = 10;
    D_802AD10F = 1;
    battle_menu_moveState = 20;
}

void func_802A2C58(void) {
    set_window_update(8, 1);
    battle_menu_moveState = 30;
}

INCLUDE_ASM(s32, "415D90", func_802A2C84);

INCLUDE_ASM(s32, "415D90", func_802A3C98);

void func_802A43DC(s32 arg0, s32 x, s32 y) {
    s32 msgID;
    s32 posX;
    s32 posY;
    s32 opacity;
    s32 palette;

    if (!battle_menu_hasSpiritsMenu) {
        msgID = 0x1D0045;
        posX = x + 16;
        posY = y + 2;
        opacity = battle_menu_moveTextOpacity;
        palette = 0x30;
    } else {
        msgID = 0x1D003A;
        posX = x + 6;
        posY = y + 2;
        opacity = battle_menu_moveTextOpacity;
        palette = 0x31;
    }
    draw_msg(msgID, posX, posY, opacity, palette, 1);
}

void func_802A4448(s32 arg0, s32 x, s32 y) {
    s32 icon = battle_menu_moveTitleIcon;

    set_hud_element_render_pos(icon, x + 16, y + 15);
    set_hud_element_alpha(icon, battle_menu_moveTextOpacity);
    draw_hud_element_clipped(icon);
}

void func_802A4494(s32 arg0, s32 x, s32 y) {
    switch ((s8)battle_menu_moveState) {
        case -1:
        case 1:
        case 10:
        case 20:
        case 30:
            if (D_802AD10F != 0) {
                draw_msg(battle_menu_moveOptionDescriptions[battle_menu_moveOptionIndexMap[battle_menu_moveCursorPos]],
                            x + 8, y, battle_menu_moveTextOpacity, battle_menu_moveTextColor, 0);
            }
            break;
    }
}

void func_802A4534(s32 arg0, s32 x, s32 y) {
    s32 posY = y;
    s32 posX;
    s32 msgID;

    posY += 6;
    posX = x + 11;

    if (D_802AD258 != 0) {
        msgID = 0x1D00C3;
    } else if (battle_menu_hasSpiritsMenu == FALSE) {
        msgID = 0x1D009F;
    } else {
        msgID = 0x1D00A0;
    }
    draw_msg(msgID, posX, posY + D_802AB344[get_msg_lines(msgID) - 1], 255, 0xF, 0);
}

void func_802A45D8(void) {
    s32 sixTemp;
    s8 temp802AD673;

    D_802AD604 = 0;
    D_802AD605 = D_802AD673;
    D_802AD606 = D_802AD673;
    D_802AD608 = 0;
    D_802AD60A = D_802AD66C;

    if (D_802AD60A > 6) {
        D_802AD60A = 6;
    }

    D_802AD609 = sixTemp = 6;

    if (D_802AD609 > D_802AD66C) {
        D_802AD609 = D_802AD66C;
    }

    D_802AD624 = 255;
    D_802AD60B = 1;
    temp802AD673 = D_802AD673;

    if (D_802AD673 < 0) {
        D_802AD608 = D_802AD673;
    }
    if (D_802AD673 >= D_802AD609) {
        D_802AD608 = (temp802AD673 + 1 - D_802AD60A);
    }

    D_802AD609 = D_802AD608 + sixTemp;
    if (D_802AD609 > D_802AD66C) {
        D_802AD609 = D_802AD66C;
    }

    D_802AD60C = -D_802AD608 * 13;
    D_802AD60E = (D_802AD673 - D_802AD608) * 13;
    D_802AD607 = 0;
    D_802AD6D4 = 0;
}

void func_802A4718(void) {
    D_802AD604 = 10;
}

void func_802A472C(void) {
    s32 i;

    set_window_update(6, 2);
    set_window_update(7, 2);
    set_window_update(8, 2);

    for (i = 0; i < D_802AD66C; i++) {
        free_hud_element(D_802AD628[i]);
    }

    free_hud_element(D_802AD618);
    free_hud_element(D_802AD61C);
    free_hud_element(D_802AD620);
}

void func_802A47E0(void) {
    s32 i;

    for (i = 0; i < D_802AD66C; i++) {
        set_hud_element_tint(D_802AD628[i], 0xFF, 0xFF, 0xFF);
    }

    set_hud_element_tint(D_802AD618, 0xFF, 0xFF, 0xFF);
    set_hud_element_tint(D_802AD61C, 0xFF, 0xFF, 0xFF);
    set_hud_element_tint(D_802AD620, 0xFF, 0xFF, 0xFF);
    set_hud_element_anim(D_802AD618, HudScript_AnimatedHandPointer);
    set_window_update(6, 5);
    set_window_update(7, 5);
    set_window_update(8, 1);
    D_802AD614 = 10;
    D_802AD60B = 1;
    D_802AD624 = 255;
    D_802AD604 = 1;
}

void func_802A48FC(void) {
    s32 i;

    set_window_update(6, 5);
    set_window_update(7, 5);
    set_window_update(8, 1);

    for (i = 0; i < D_802AD66C; i++) {
        set_hud_element_tint(D_802AD628[i], 0xFF, 0xFF, 0xFF);
    }

    set_hud_element_tint(D_802AD618, 0xFF, 0xFF, 0xFF);
    set_hud_element_tint(D_802AD61C, 0xFF, 0xFF, 0xFF);
    set_hud_element_tint(D_802AD620, 0xFF, 0xFF, 0xFF);
    set_hud_element_anim(D_802AD618, HudScript_AnimatedHandPointer);
    D_802AD614 = 10;
    D_802AD60B = 1;
    D_802AD604 = 20;
}

void func_802A4A10(void) {
    set_window_update(6, 5);
    set_window_update(7, 5);
    set_window_update(8, 1);
    D_802AD604 = 30;
}

INCLUDE_ASM(s32, "415D90", func_802A4A54);

// getting there but needs work
#ifdef NON_EQUIVALENT
void func_802A5290(s32 arg0, s32 x, s32 y) {
    s16 temp_s1;
    s16 temp_s1_3;
    s32 temp_f6;
    s32 temp_f6_2;
    s32 phi_s1;
    s32 phi_s1_2;
    s32 t1;
    s32 xt;

    s32 lry;
    s32 yOffset;
    s32 uly;
    s32 xTemp;
    s32 iconIndex;
    s32 i;

    switch (D_802AD604) {
        case -1:
        case 1:
        case 10:
        case 20:
        case 30:
        case 40:
        case 41:
            temp_s1 = -D_802AD608 * 13;
            temp_f6 = (temp_s1 - D_802AD60C) * 0.5;
            D_802AD60C += temp_f6;
            if (temp_f6 == 0) {
                D_802AD60C = temp_s1;
            }
            t1 = D_802AD60A * 13;

            xTemp = x + 4;
            uly = y + 18;
            yOffset = 1 + t1;
            lry = yOffset + uly;
            gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, xTemp, uly, x + 142, lry);

            xTemp = x + 33;
            phi_s1 = y + (D_802AD60C + 19);
            for (i = 0; i < D_802AD66C; i++, phi_s1 += 0xD) {
                s32 palette = D_802AD614;

                if (D_802AD678[i] == 5 && is_ability_active(ABILITY_QUICK_CHANGE)) {
                    palette = 0x37;
                }
                if (D_802AD690[i] == 0) {
                    palette = 0xB;
                }
                draw_msg(D_802AD658[i], xTemp, phi_s1, D_802AD624, palette, 1);
            }

            xTemp = x + 24;
            phi_s1_2 = D_802AD60C + y + 24;
            for (i = 0; i < D_802AD66C; i++, phi_s1_2 += 0xD) {
                iconIndex = D_802AD628[i];

                set_hud_element_render_pos(iconIndex, xTemp, phi_s1_2);
                set_hud_element_alpha(iconIndex, D_802AD624);
                draw_hud_element_3(iconIndex);
            }

            temp_s1_3 = (D_802AD605 - D_802AD608) * 13;
            temp_f6_2 = (f64) (temp_s1_3 - D_802AD60E);
            if (temp_f6_2 != 0) {
                D_802AD60E += temp_f6_2;
            } else {
                D_802AD60E = temp_s1_3;
            }

            iconIndex = D_802AD618;
            set_hud_element_render_pos(iconIndex, x + 10, y + (D_802AD60E + 26));
            set_hud_element_alpha(iconIndex, D_802AD624);
            draw_hud_element_clipped(iconIndex);

            if (D_802AD608 > 0) {
                iconIndex = D_802AD61C;
                set_hud_element_render_pos(iconIndex, x + 67, y + 16);
                set_hud_element_alpha(iconIndex, D_802AD624);
                draw_hud_element_clipped(iconIndex);
            }

            if (D_802AD609 < D_802AD66C) {
                iconIndex = D_802AD620;
                set_hud_element_render_pos(iconIndex, x + 67, y + 100);
                set_hud_element_alpha(iconIndex, D_802AD624);
                draw_hud_element_clipped(iconIndex);
            }

            break;
    }
}
#else
INCLUDE_ASM(s32, "415D90", func_802A5290);
#endif

void func_802A56F8(s32 arg0, s32 x, s32 y) {
    draw_msg(0x1D0043, x + 15, y + 2, D_802AD624, 0x33, 1);
}

void func_802A5738(s32 arg0, s32 x, s32 y) {
    switch (D_802AD604) {
        case -1:
        case 1:
        case 10:
        case 20:
        case 30:
            if (D_802AD60B != 0) {
                draw_msg(D_802AD6C0[D_802AD605], x + 8, y, D_802AD624, D_802AD614, 0);
            }
            break;
    }
}

// regalloc, arg setting order dumbness
#ifdef NON_EQUIVALENT
void func_802A57C8(s32 arg0, s32 x, s32 y) {
    x += 11;
    y += 6;

    if (D_802AD610 == 0) {
        draw_msg(0x1D00CB, x, y, 255, 15, 0);
    } else {
        draw_msg(0x1D00CC, x, y, 255, 15, 0);
    }
}
#else
INCLUDE_ASM(s32, "415D90", func_802A57C8);
#endif

s32 can_btl_state_update_switch_to_player(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;

    if (battleStatus->flags2 & BS_FLAGS2_2) {
        return FALSE;
    } else {
        s8 debuff = player->debuff;
        s32 playerCantMove = player->koStatus == STATUS_DAZE;

        if (debuff == STATUS_POISON) {
            playerCantMove = FALSE;
        }
        if (debuff == STATUS_SHRINK) {
            playerCantMove = FALSE;
        }
        if (debuff == STATUS_SLEEP) {
            playerCantMove = TRUE;
        }
        if (debuff == STATUS_FEAR) {
            playerCantMove = TRUE;
        }
        if (debuff == STATUS_DIZZY) {
            playerCantMove = TRUE;
        }
        if (debuff == STATUS_PARALYZE) {
            playerCantMove = TRUE;
        }
        if (debuff == STATUS_FROZEN) {
            playerCantMove = TRUE;
        }
        if (debuff == STATUS_STOP) {
            playerCantMove = TRUE;
        }
        if (player->stoneStatus == STATUS_STONE) {
            playerCantMove = TRUE;
        }
        if (battleStatus->outtaSightActive) {
            playerCantMove = TRUE;
        }
        return !playerCantMove;
    }
}

s32 func_802A58D0(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    s8 partnerDebuff;
    s32 partnerCantMove;

    if (battleStatus->flags2 & BS_FLAGS2_4 || partner == PARTNER_NONE || partner->flags & 0x200000) {
        return FALSE;
    }

    partnerDebuff = partner->debuff;
    partnerCantMove = partner->koStatus == STATUS_DAZE;

    if (partnerDebuff == STATUS_POISON) {
        partnerCantMove = FALSE;
    }
    if (partnerDebuff == STATUS_SHRINK) {
        partnerCantMove = FALSE;
    }
    if (partnerDebuff == STATUS_SLEEP) {
        partnerCantMove = TRUE;
    }
    if (partnerDebuff == STATUS_FEAR) {
        partnerCantMove = TRUE;
    }
    if (partnerDebuff == STATUS_PARALYZE) {
        partnerCantMove = TRUE;
    }
    if (partnerDebuff == STATUS_FROZEN) {
        partnerCantMove = TRUE;
    }
    if (partnerDebuff == STATUS_STOP) {
        partnerCantMove = TRUE;
    }
    if (partner->stoneStatus == STATUS_STONE) {
        partnerCantMove = TRUE;
    }
    return !partnerCantMove;
}

INCLUDE_ASM(s32, "415D90", btl_state_update_player_menu);

//requires above to be decomped
#ifdef NON_EQUIVALENT
void btl_state_draw_player_menu(void) {
    switch (gBattleState2) {
        case 1:
            btl_draw_menu_wheel();
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 51:
        case 52:
        case 53:
        case 54:
        case 61:
        case 62:
        case 63:
        case 64:
        case 65:
        case 200:
        case 201:
            btl_draw_menu_wheel();
            break;
        case 202:
            btl_draw_menu_wheel();
            break;
        case 203:
            btl_draw_menu_wheel();
            break;
        case 204:
            btl_draw_menu_wheel();
            break;
        case 205:
            btl_draw_menu_wheel();
            break;
    }
}
#else
INCLUDE_ASM(s32, "415D90", btl_state_draw_player_menu);
#endif

INCLUDE_ASM(s32, "415D90", btl_state_update_partner_menu);

void btl_state_draw_partner_menu(void) {
    switch (gBattleState2) {
        case 2:
            btl_draw_menu_wheel();
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 30:
        case 31:
        case 32:
        case 33:
        case 34:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 51:
        case 52:
        case 53:
        case 54:
        case 61:
        case 62:
        case 63:
        case 64:
        case 65:
        case 200:
        case 201:
            btl_draw_menu_wheel();
            break;
        case 202:
            btl_draw_menu_wheel();
            break;
        case 203:
            btl_draw_menu_wheel();
            break;
        case 204:
            btl_draw_menu_wheel();
            break;
        case 205:
            btl_draw_menu_wheel();
            break;
    }
}

s32 func_802A9B30(void) {
    return (gBattleStatus.flags2 & BS_FLAGS2_4) <= 0;
}

INCLUDE_ASM(s32, "415D90", btl_state_update_peach_menu);

// Needs the above jtbl to be decompiled and then this will work
#ifdef NON_MATCHING
void btl_state_draw_peach_menu(void) {
    switch (gBattleState2) {
        case 1:
            btl_draw_menu_wheel();
            break;
        case 2:
            btl_draw_menu_wheel();
            break;
        case 3:
            btl_draw_menu_wheel();
            break;
        case 4:
            btl_draw_menu_wheel();
            break;
        case 5:
            btl_draw_menu_wheel();
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            break;
    }
}
#else
INCLUDE_ASM(s32, "415D90", btl_state_draw_peach_menu);
#endif

s32 func_802AA0A4(void) {
    return (gBattleStatus.flags2 & 2) <= 0;
}

INCLUDE_ASM(s32, "415D90", btl_state_update_twink_menu); // look into m2c bug

void btl_state_draw_twink_menu(void) {
    switch (gBattleState2) {
        case 1:
            btl_draw_menu_wheel();
            break;
        case 2:
            btl_draw_menu_wheel();
            break;
        case 3:
            btl_draw_menu_wheel();
            break;
        case 4:
            btl_draw_menu_wheel();
            break;
        case 5:
            btl_draw_menu_wheel();
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            break;
    }
}

INCLUDE_ASM(s32, "415D90", btl_state_update_select_target);

INCLUDE_ASM(s32, "415D90", btl_state_draw_select_target);

void btl_state_update_22(void) {
}

void btl_state_draw_22(void) {
}
