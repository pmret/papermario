#include "common.h"
#include "hud_element.h"

extern HudScript HudScript_YellowArrow;

extern HudScript HudScript_MenuFlee;
extern HudScript HudScript_MenuFleeDisabled;
extern HudScript HudScript_MenuDefend;
extern HudScript HudScript_MenuDefendDisabled;
extern HudScript HudScript_MenuStrategies;
extern HudScript HudScript_MenuStrategiesDisabled;
extern HudScript HudScript_MenuPouch;
extern HudScript HudScript_MenuPouchDisabled;
extern HudScript HudScript_MenuDoNothing;
extern HudScript HudScript_MenuDoNothingDisabled;

extern HudScript HudScript_Kooper;
extern HudScript HudScript_Bombette;
extern HudScript HudScript_Partner0;
extern HudScript HudScript_Partner0Disabled;
extern HudScript HudScript_Goombario;
extern HudScript HudScript_GoombarioDisabled;
extern HudScript HudScript_KooperDisabled;
extern HudScript HudScript_BombetteDisabled;
extern HudScript HudScript_Parakarry;
extern HudScript HudScript_ParakarryDisabled;
extern HudScript HudScript_Bow;
extern HudScript HudScript_BowDisabled;
extern HudScript HudScript_Watt;
extern HudScript HudScript_WattDisabled;
extern HudScript HudScript_Sushie;
extern HudScript HudScript_SushieDisabled;
extern HudScript HudScript_Lakilester;
extern HudScript HudScript_LakilesterDisabled;
extern HudScript HudScript_PartnerA;
extern HudScript HudScript_PartnerADisabled;

extern HudScript HudScript_MenuBoots1;
extern HudScript HudScript_MenuBoots1Disabled;
extern HudScript HudScript_MenuBoots2;
extern HudScript HudScript_MenuBoots2Disabled;
extern HudScript HudScript_MenuBoots3;
extern HudScript HudScript_MenuBoots3Disabled;

extern HudScript HudScript_MenuHammer1;
extern HudScript HudScript_MenuHammer1Disabled;
extern HudScript HudScript_MenuHammer2;
extern HudScript HudScript_MenuHammer2Disabled;
extern HudScript HudScript_MenuHammer3;
extern HudScript HudScript_MenuHammer3Disabled;

extern HudScript HudScript_MenuItem;
extern HudScript HudScript_MenuItemDisabled;

extern HudScript HudScript_MenuStarPower;
extern HudScript HudScript_MenuStarPowerDisabled;

extern HudScript HudScript_Eldstar;
extern HudScript HudScript_EldstarDisabled;
extern HudScript HudScript_Mamar;
extern HudScript HudScript_MamarDisabled;
extern HudScript HudScript_Skolar;
extern HudScript HudScript_SkolarDisabled;
extern HudScript HudScript_Muskular;
extern HudScript HudScript_MuskularDisabled;
extern HudScript HudScript_Misstar;
extern HudScript HudScript_MisstarDisabled;
extern HudScript HudScript_Klevar;
extern HudScript HudScript_KlevarDisabled;
extern HudScript HudScript_Kalmar;
extern HudScript HudScript_KalmarDisabled;
extern HudScript HudScript_StarBeam;
extern HudScript HudScript_StarBeamDisabled;
extern HudScript HudScript_PeachBeam;
extern HudScript HudScript_PeachBeamDisabled;

extern HudScript HudScript_MoveDiamond;
extern HudScript HudScript_MoveBlueOrb;
extern HudScript HudScript_MoveGreenOrb;
extern HudScript HudScript_MoveRedOrb;
extern HudScript HudScript_MoveDiamondDisabled;
extern HudScript HudScript_MoveBlueOrbDisabled;
extern HudScript HudScript_MoveGreenOrbDisabled;
extern HudScript HudScript_MoveRedOrbDisabled;

extern s32 D_802ACC60;
extern s32 D_802ACC6C;
extern s8 D_802AD000;
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
extern s32 D_802AD0A8;
extern s32 D_802AD0B0;
extern s32 D_802AD0BB[];
extern s32 D_802AD100;
extern s32 D_802AD104;
extern s32 battle_menu_isEnabled;
extern s32 battle_menu_isMessageDisabled;
extern s32 battle_menu_messageIDs[];
extern s32 battle_menu_submenuIDs;
extern HudScript* main_battle_menu_JumpHudScripts;
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

s16 D_802AB340[] = { 28, 40 };

s16 D_802AB344[] = { 0, -2 };

HudScript* battle_menu_JumpHudScripts[] = {
    &HudScript_MenuBoots1Disabled, &HudScript_MenuBoots1Disabled,
    &HudScript_MenuBoots1,&HudScript_MenuBoots1Disabled,
    &HudScript_MenuBoots2, &HudScript_MenuBoots2Disabled,
    &HudScript_MenuBoots3, &HudScript_MenuBoots3Disabled };

HudScript* battle_menu_HammerHudScripts[] = {
    &HudScript_MenuHammer1Disabled, &HudScript_MenuHammer1Disabled,
    &HudScript_MenuHammer1, &HudScript_MenuHammer1Disabled,
    &HudScript_MenuHammer2, &HudScript_MenuHammer2Disabled,
    &HudScript_MenuHammer3, &HudScript_MenuHammer3Disabled };

HudScript* battle_menu_ItemHudScripts[] = { &HudScript_MenuItem, &HudScript_MenuItemDisabled };

HudScript* battle_menu_StarPowerHudScripts[] = { &HudScript_MenuStarPower, &HudScript_MenuStarPowerDisabled };

HudScript* battle_menu_StarPowerMovesHudScripts[] = {
    &HudScript_MenuStarPower, &HudScript_MenuStarPowerDisabled, &HudScript_Eldstar, &HudScript_EldstarDisabled,
    &HudScript_Mamar, &HudScript_MamarDisabled, &HudScript_Skolar, &HudScript_SkolarDisabled,
    &HudScript_Muskular, &HudScript_MuskularDisabled, &HudScript_Misstar, &HudScript_MisstarDisabled,
    &HudScript_Klevar, &HudScript_KlevarDisabled, &HudScript_Kalmar, &HudScript_KalmarDisabled,
    &HudScript_StarBeam, &HudScript_StarBeamDisabled, &HudScript_PeachBeam, &HudScript_PeachBeamDisabled,
    &HudScript_MenuStarPower, &HudScript_MenuStarPowerDisabled, &HudScript_MenuStarPower, &HudScript_MenuStarPowerDisabled
};

HudScript* battle_menu_PartnerHudScripts[] = {
    &HudScript_Partner0, &HudScript_Goombario, &HudScript_Kooper, &HudScript_Bombette,
    &HudScript_Parakarry, &HudScript_Partner0, &HudScript_Watt, &HudScript_Sushie,
    &HudScript_Lakilester, &HudScript_Bow, &HudScript_PartnerA, &HudScript_PartnerA,
    &HudScript_PartnerA, &HudScript_PartnerA, &HudScript_PartnerA, &HudScript_PartnerA
};

HudScript* battle_menu_DisabledPartnerHudScripts[] = {
    &HudScript_Partner0Disabled, &HudScript_GoombarioDisabled, &HudScript_KooperDisabled, &HudScript_BombetteDisabled,
    &HudScript_ParakarryDisabled, &HudScript_Partner0Disabled, &HudScript_WattDisabled, &HudScript_SushieDisabled,
    &HudScript_LakilesterDisabled, &HudScript_BowDisabled, &HudScript_PartnerADisabled, &HudScript_PartnerADisabled,
    &HudScript_PartnerADisabled, &HudScript_PartnerADisabled, &HudScript_PartnerADisabled, &HudScript_PartnerADisabled
};

HudScript* battle_menu_StrategiesHudScript[] = { &HudScript_MenuStrategies };

HudScript* battle_menu_DisabledStrategiesHudScript[] = { &HudScript_MenuStrategiesDisabled };

HudScript* battle_menu_DoNothingHudScripts[] = { &HudScript_MenuDoNothing, &HudScript_MenuDoNothingDisabled };

HudScript* battle_menu_FleeHudScripts[] = { &HudScript_MenuFlee, &HudScript_MenuFleeDisabled };

// Jump, Hammer, Items, RunAway, Defense
s32 battle_menu_leftJustfiedMessagesA[] = { 0x001D0039, 0x001D0038, 0x001D003F, 0x001D003B, 0x001D0044 };

// Change Member, Abilities, Strategies, Star Spirits
s32 battle_menu_leftJustfiedMessagesB[] = { 0x001D003E, 0x001D0045, 0x001D0043, 0x001D003A };

// Do Nothing, Act Later, Focus
s32 battle_menu_leftJustfiedMessagesC[] = { 0x001D003C, 0x001D0046, 0x001D0048 };

// Jump, Hammer
s32 battle_menu_centeredMessagesA[] = { 0x001D004B, 0x001D004A };

// Items, RunAway, Defense, Change Member, Abilities
s32 battle_menu_centeredMessagesB[] = { 0x001D0050, 0x001D004D, 0x001D0052, 0x001D004F, 0x001D0053 };

// Strategies
s32 battle_menu_centeredMessagesC[] = { 0x001D0051 };

// Star Spirits, Do Nothing, Act Later, Focus
s32 battle_menu_centeredMessagesD[] = { 0x001D004C, 0x001D004E, 0x001D0056, 0x001D0055 };

s32 D_802AB4F0[] = { 0x2, 0x1, 0x4, 0x6, 0x3, 0x5, 0x1A, 0x3, 0x34, 0x39, 0x31, 0x37 };

// s8 D_802AB513

s32 D_802AB520[] = {
    0x00000000, 0x00090012, 0x000A001A, 0x000B001C, 0x000C0017, 0x009D0001, 0x000E000B, 0x000F0012, 0x00100003,
    0x000D0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};

s32 D_802AB558[] = {
    0x00000000, 0x00090002, 0x000A0005, 0x000B0006, 0x000C0002, 0x009D0002, 0x000E0002, 0x000F0002, 0x00100002,
    0x000D0002, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};

HudScript* battle_menu_PartnerMoveHudScripts[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    &HudScript_Goombario, &HudScript_GoombarioDisabled, &HudScript_MoveDiamond, &HudScript_MoveDiamondDisabled, &HudScript_MoveBlueOrb, &HudScript_MoveBlueOrbDisabled, &HudScript_MoveGreenOrb, &HudScript_MoveGreenOrbDisabled, &HudScript_MoveRedOrb, &HudScript_MoveRedOrbDisabled,
    &HudScript_Kooper, &HudScript_KooperDisabled, &HudScript_MoveDiamond, &HudScript_MoveDiamondDisabled, &HudScript_MoveBlueOrb, &HudScript_MoveBlueOrbDisabled, &HudScript_MoveGreenOrb, &HudScript_MoveGreenOrbDisabled, &HudScript_MoveRedOrb, &HudScript_MoveRedOrbDisabled,
    &HudScript_Bombette, &HudScript_BombetteDisabled, &HudScript_MoveDiamond, &HudScript_MoveDiamondDisabled, &HudScript_MoveBlueOrb, &HudScript_MoveBlueOrbDisabled, &HudScript_MoveGreenOrb, &HudScript_MoveGreenOrbDisabled, &HudScript_MoveRedOrb, &HudScript_MoveRedOrbDisabled,
    &HudScript_Parakarry, &HudScript_ParakarryDisabled, &HudScript_MoveDiamond, &HudScript_MoveDiamondDisabled, &HudScript_MoveBlueOrb, &HudScript_MoveBlueOrbDisabled, &HudScript_MoveGreenOrb, &HudScript_MoveGreenOrbDisabled, &HudScript_MoveRedOrb, &HudScript_MoveRedOrbDisabled,
    &HudScript_Partner0, &HudScript_Partner0Disabled, &HudScript_MoveDiamond, &HudScript_MoveDiamondDisabled, &HudScript_MoveBlueOrb, &HudScript_MoveBlueOrbDisabled, &HudScript_MoveGreenOrb, &HudScript_MoveGreenOrbDisabled, &HudScript_MoveRedOrb, &HudScript_MoveRedOrbDisabled,
    &HudScript_Watt, &HudScript_WattDisabled, &HudScript_MoveDiamond, &HudScript_MoveDiamondDisabled, &HudScript_MoveBlueOrb, &HudScript_MoveBlueOrbDisabled, &HudScript_MoveGreenOrb, &HudScript_MoveGreenOrbDisabled, &HudScript_MoveRedOrb, &HudScript_MoveRedOrbDisabled,
    &HudScript_Sushie, &HudScript_SushieDisabled, &HudScript_MoveDiamond, &HudScript_MoveDiamondDisabled, &HudScript_MoveBlueOrb, &HudScript_MoveBlueOrbDisabled, &HudScript_MoveGreenOrb, &HudScript_MoveGreenOrbDisabled, &HudScript_MoveRedOrb, &HudScript_MoveRedOrbDisabled,
    &HudScript_Lakilester, &HudScript_LakilesterDisabled, &HudScript_MoveDiamond, &HudScript_MoveDiamondDisabled, &HudScript_MoveBlueOrb, &HudScript_MoveBlueOrbDisabled, &HudScript_MoveGreenOrb, &HudScript_MoveGreenOrbDisabled, &HudScript_MoveRedOrb, &HudScript_MoveRedOrbDisabled,
    &HudScript_Bow, &HudScript_BowDisabled, &HudScript_MoveDiamond, &HudScript_MoveDiamondDisabled, &HudScript_MoveBlueOrb, &HudScript_MoveBlueOrbDisabled, &HudScript_MoveGreenOrb, &HudScript_MoveGreenOrbDisabled, &HudScript_MoveRedOrb, &HudScript_MoveRedOrbDisabled };

HudScript* battle_menu_PeachStarPowerHudScripts[] = { &HudScript_MenuStarPower, &HudScript_MenuStarPowerDisabled };

// Focus
s32 D_802AB728[] = { 0x001D0055 };

HudScript* battle_menu_TwinkStarPowerHudScripts[] = { &HudScript_MenuStarPower, &HudScript_MenuStarPowerDisabled };

// Dash
s32 D_802AB734[] = { 0x001D0057 };

s32 D_802AB738[] = {
    0x00000000, 0x001D0007, 0x001D0008, 0x001D0009, 0x001D000A, 0x001D000B, 0x001D000C, 0x001D000D, 0x001D000E,
    0x001D000F, 0x001D0010, 0x001D0011, 0x001D0012, 0x00000000
};

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

        hud_element_free(icons1[i]);
        hud_element_free(icons2[i]);
    }

    hud_element_free(D_802AD040);
    hud_element_free(D_802AD044);
    hud_element_free(D_802AD048);
    hud_element_free(D_802AD04C);
    hud_element_free(D_802AD05C);
    hud_element_free(D_802AD050);
    hud_element_free(D_802AD054);
    hud_element_free(D_802AD058);
}

s32 func_802A11B0(void);
INCLUDE_ASM(s32, "415D90", func_802A11B0);

void btl_draw_menu_wheel(void);

// various issues
#ifdef NON_MATCHING
extern s8 D_802AD002;
extern s8 D_802AD004;
extern s16 D_802AD00A;
extern s32 D_802AD060;
extern s32 D_802AD064;
extern s8 D_802AD06B;
extern f32 D_802AD06C;
extern f32 D_802AD070;

void btl_draw_menu_wheel(void) {
    s32 id;
    s32 opacity;

    f32 temp_f24;
    f32 theta;

    s32 cond;
    f32 x;
    f32 y;
    f32 scale;
    s32 i;

    s32 new_var;

    switch (D_802AD000) {
        case 1:
            func_80144218(-1);
            id = D_802AD048;
            hud_element_set_transform_rotation(id, 0.0f, 0.0f, 0.0f);
            hud_element_set_alpha(id, (D_802AD006 * 254) / 255);
            hud_element_set_render_pos(id, 3940 - D_802AD00A, D_802AD00A + 212);
            func_80144238(id);
            id = D_802AD044;
            hud_element_set_alpha(id, (D_802AD006 * 254) / 255);
            hud_element_set_render_pos(id, 40 - D_802AD00A, D_802AD00A + 212);
            func_80144238(id);
            break;
        case -1:
        case 2:
        case 10:
        case 20:
        case 30:
            opacity = (D_802AD006 * D_802AD008) / 255;
            func_80144218(-1);
            temp_f24 = (D_802AD100 - D_802AD002) * 28;

            cond = FALSE;
            if (D_802AD06C > temp_f24) {
                D_802AD06C -= D_802AD070;
                if (D_802AD06C < temp_f24) {
                    D_802AD06C = temp_f24;
                    cond = TRUE;
                }
            } else if (D_802AD06C < temp_f24) {
                D_802AD06C += D_802AD070;
                if (D_802AD06C > temp_f24) {
                    D_802AD06C = temp_f24;
                    cond = TRUE;
                }
            } else {
                cond = TRUE;
            }

            if (!cond) {
                D_802AD070 = (D_802AD070 * (D_802AD070 + 1.0) * (D_802AD070 + 1.0));
            } else {
                D_802AD004 = 0;
                D_802AD070 = 0.3f;
            }

            theta = D_802AD06C;
            for (i = 0; i < main_menu_numOptions; i++, theta += 28.0f) {
                x = 0.0f;
                y = 0.0f;
                add_vec2D_polar(&x, &y, 87.0f, theta);
                id = D_802AD028[i];
                x = D_802AD060 + x;
                y = D_802AD064 + y;
                hud_element_set_transform_pos(id, x, -y, 0.0f);
                hud_element_set_render_pos(id, 0, 0);
                hud_element_set_alpha(id, (opacity * 150) / 255);

                if (theta == 56.0f && cond == TRUE) {
                    hud_element_set_scale(id, 1.6f);
                } else {
                    hud_element_set_scale(id, 1.0f);
                }

                func_80144238(id);
                if (i == D_802AD06B + D_802AD002) {
                    x = 0.0f;
                    y = 0.0f;
                    add_vec2D_polar(&x, &y, 87.0f, 56.0f);
                    x = D_802AD060 + x;
                    y = D_802AD064 + y;
                    id = D_802AD040;
                    hud_element_set_transform_pos(id, x, -y, 0.0f);
                    hud_element_set_render_pos(id, 0, 0);
                    hud_element_set_alpha(id, (opacity * 180) / 255);
                    hud_element_set_scale(id, 1.2f);
                    if (!cond) {
                        hud_element_set_flags(id, 2);
                    } else {
                        hud_element_clear_flags(id, 2);
                    }
                    func_80144238(id);
                }
            }

            scale = (fabsf(fabsf((D_802AD06C - ((D_802AD100 - D_802AD002) * 28)) * (45.0 / 28.0)) - 22.5) / 22.5) + 0.01;
            if (cond) {
                scale = 1.0f;
            }

            id = D_802AD04C;
            hud_element_set_transform_rotation_pivot(id, 0, 0);
            hud_element_set_transform_rotation(id, 0.0f, 0.0f, -43.0f);
            hud_element_set_scale(id, scale);
            hud_element_set_transform_scale(id, 1.0f, 1.8f, 1.0f);
            hud_element_set_alpha(id, (opacity * 200) / 255);
            hud_element_set_render_pos(id, 79, 176);
            func_80144238(id);

            id = D_802AD048;
            scale = (D_802AD06C - ((D_802AD100 - D_802AD002) * 28)) * (45.0 / 28.0);
            hud_element_set_transform_rotation(id, 0.0f, 0.0f, -scale);
            hud_element_set_transform_rotation_pivot(id, 18, -20);
            hud_element_set_scale(id, 0.95f);
            hud_element_set_alpha(id, (opacity * 254) / 255);
            hud_element_set_render_pos(id, 40 - D_802AD00A, D_802AD00A + 212);
            func_80144238(id);

            id = D_802AD044;
            hud_element_set_alpha(id, (opacity * 254) / 255);
            hud_element_set_render_pos(id, 40 - D_802AD00A, D_802AD00A + 212);
            hud_element_set_scale(id, 1.0f);
            func_80144238(id);

            theta = D_802AD06C;
            for (i = 0; i < main_menu_numOptions; i++, theta += 28.0f) {
                s32 l;
                s32 t;
                s32 new_var;

                x = 0.0f;
                y = 0.0f;
                add_vec2D_polar(&x, &y, 87.0f, theta);

                x = D_802AD060 + x;
                l = x;
                y = D_802AD064 + y;
                t = y;
                btl_draw_prim_quad(0, 0, 0, 0, l - 12, t - 12, 24, 24);
                id = D_802AD010[i];
                hud_element_set_render_pos(id, l, t);
                hud_element_set_alpha(id, (opacity * 180) / 255);
                if (i == D_802AD06B + D_802AD002) {
                    hud_element_set_alpha(id, opacity);
                }
                hud_element_draw_clipped(id);
            }

            if (cond) {
                s32 msgX;
                s32 msgY;

                msgX = D_802AD060 + 20;
                msgY = D_802AD064;

                msgY -= 34;

                btl_draw_prim_quad(0, 0, 0, 0, D_802AD060 + 46, msgY, 48, 16);
                draw_msg(battle_menu_messageIDs[D_802AD002 + D_802AD06B], msgX, msgY, opacity, 0x35, 0);
            }

            if ((gBattleStatus.flags1 & 0x02000000) || (gBattleStatus.flags2 & 0x40)) {
                D_802AD104 = 0;
            }

            if (D_802AD104 != 0) {
                id = D_802AD05C;
                hud_element_set_alpha(id, (opacity * 200) / 255);
                hud_element_draw_clipped(id);
                id = D_802AD050;
                hud_element_set_alpha(id, opacity);
                hud_element_draw_clipped(id);
                id = D_802AD054;
                hud_element_set_alpha(id, opacity);
                hud_element_draw_clipped(id);
                id = D_802AD058;
                hud_element_set_alpha(id, opacity);
                hud_element_draw_clipped(id);
            }
            break;
    }
}
#else
INCLUDE_ASM(s32, "415D90", btl_draw_menu_wheel);
#endif

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

    set_window_update(WINDOW_ID_1, WINDOW_UPDATE_HIDE);

    if (!battle_menu_hasSpiritsMenu) {
        set_window_update(WINDOW_ID_2, WINDOW_UPDATE_HIDE);
        set_window_update(WINDOW_ID_3, WINDOW_UPDATE_HIDE);
    } else {
        set_window_update(WINDOW_ID_4, WINDOW_UPDATE_HIDE);
        set_window_update(WINDOW_ID_5, WINDOW_UPDATE_HIDE);
    }

    set_window_update(WINDOW_ID_8, WINDOW_UPDATE_HIDE);

    for (i = 0; i < battle_menu_moveOptionCount; i++) {
        hud_element_free(battle_menu_moveOptionIconIDs[i]);
    }

    hud_element_free(battle_menu_moveCursorIcon);
    hud_element_free(battle_menu_moveUpArrowIcon);
    hud_element_free(battle_menu_moveDownArrowIcon);
    hud_element_free(battle_menu_moveTitleIcon);

    for (i = 0; i < battle_menu_moveOptionCount; i++) {
        hud_element_free(battle_menu_moveOptionCostUnitIconIDs[i]);
    }
}

void func_802A2910(void) {
    s32* moveOptionIconIDs;
    s32* moveOptionCostUnitIconIDs;
    s32 i;

    moveOptionIconIDs = battle_menu_moveOptionIconIDs;

    for (i = 0; i < battle_menu_moveOptionCount; i++) {
        hud_element_set_tint(moveOptionIconIDs[i], 255, 255, 255);
    }

    hud_element_set_tint(battle_menu_moveCursorIcon, 255, 255, 255);
    hud_element_set_tint(battle_menu_moveUpArrowIcon, 255, 255, 255);
    hud_element_set_tint(battle_menu_moveDownArrowIcon, 255, 255, 255);
    hud_element_set_tint(battle_menu_moveTitleIcon, 255, 255, 255);

    moveOptionCostUnitIconIDs = battle_menu_moveOptionCostUnitIconIDs;

    for (i = 0; i < battle_menu_moveOptionCount; i++) {
        hud_element_set_tint(moveOptionCostUnitIconIDs[i], 255, 255, 255);
    }

    hud_element_set_script(battle_menu_moveCursorIcon, &HudScript_AnimatedHandPointer);
    set_window_update(WINDOW_ID_1, WINDOW_UPDATE_TRANSPARENT);

    if (!battle_menu_hasSpiritsMenu) {
        set_window_update(WINDOW_ID_2, WINDOW_UPDATE_TRANSPARENT);
        set_window_update(WINDOW_ID_3, WINDOW_UPDATE_TRANSPARENT);
    } else {
        set_window_update(WINDOW_ID_4, WINDOW_UPDATE_TRANSPARENT);
        set_window_update(WINDOW_ID_5, WINDOW_UPDATE_TRANSPARENT);
    }

    set_window_update(WINDOW_ID_8, WINDOW_UPDATE_SHOW);
    battle_menu_moveTextColor = 10;
    D_802AD10F = 1;
    battle_menu_moveTextOpacity = 255;
    battle_menu_moveState = 1;
}

void func_802A2AB8(void) {
    s32* moveOptionIconIDs;
    s32* moveOptionCostUnitIconIDs;
    s32 i;

    set_window_update(WINDOW_ID_1, WINDOW_UPDATE_TRANSPARENT);

    if (!battle_menu_hasSpiritsMenu) {
        set_window_update(WINDOW_ID_2, WINDOW_UPDATE_TRANSPARENT);
        set_window_update(WINDOW_ID_3, WINDOW_UPDATE_TRANSPARENT);
    } else {
        set_window_update(WINDOW_ID_4, WINDOW_UPDATE_TRANSPARENT);
        set_window_update(WINDOW_ID_5, WINDOW_UPDATE_TRANSPARENT);
    }
    set_window_update(WINDOW_ID_8, WINDOW_UPDATE_SHOW);

    moveOptionIconIDs = battle_menu_moveOptionIconIDs;

    for (i = 0; i < battle_menu_moveOptionCount; i++) {
        hud_element_set_tint(moveOptionIconIDs[i], 255, 255, 255);
    }

    hud_element_set_tint(battle_menu_moveCursorIcon, 255, 255, 255);
    hud_element_set_tint(battle_menu_moveUpArrowIcon, 255, 255, 255);
    hud_element_set_tint(battle_menu_moveDownArrowIcon, 255, 255, 255);
    hud_element_set_tint(battle_menu_moveTitleIcon, 255, 255, 255);

    moveOptionCostUnitIconIDs = battle_menu_moveOptionCostUnitIconIDs;

    for (i = 0; i < battle_menu_moveOptionCount; i++) {
        hud_element_set_tint(moveOptionCostUnitIconIDs[i], 255, 255, 255);
    }

    hud_element_set_script(battle_menu_moveCursorIcon, &HudScript_AnimatedHandPointer);
    battle_menu_moveTextColor = 10;
    D_802AD10F = 1;
    battle_menu_moveState = 20;
}

void func_802A2C58(void) {
    set_window_update(WINDOW_ID_8, WINDOW_UPDATE_SHOW);
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

    hud_element_set_render_pos(icon, x + 16, y + 15);
    hud_element_set_alpha(icon, battle_menu_moveTextOpacity);
    hud_element_draw_clipped(icon);
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

    set_window_update(WINDOW_ID_6, WINDOW_UPDATE_HIDE);
    set_window_update(WINDOW_ID_7, WINDOW_UPDATE_HIDE);
    set_window_update(WINDOW_ID_8, WINDOW_UPDATE_HIDE);

    for (i = 0; i < D_802AD66C; i++) {
        hud_element_free(D_802AD628[i]);
    }

    hud_element_free(D_802AD618);
    hud_element_free(D_802AD61C);
    hud_element_free(D_802AD620);
}

void func_802A47E0(void) {
    s32 i;

    for (i = 0; i < D_802AD66C; i++) {
        hud_element_set_tint(D_802AD628[i], 0xFF, 0xFF, 0xFF);
    }

    hud_element_set_tint(D_802AD618, 0xFF, 0xFF, 0xFF);
    hud_element_set_tint(D_802AD61C, 0xFF, 0xFF, 0xFF);
    hud_element_set_tint(D_802AD620, 0xFF, 0xFF, 0xFF);
    hud_element_set_script(D_802AD618, &HudScript_AnimatedHandPointer);
    set_window_update(WINDOW_ID_6, WINDOW_UPDATE_TRANSPARENT);
    set_window_update(WINDOW_ID_7, WINDOW_UPDATE_TRANSPARENT);
    set_window_update(WINDOW_ID_8, WINDOW_UPDATE_SHOW);
    D_802AD614 = 10;
    D_802AD60B = 1;
    D_802AD624 = 255;
    D_802AD604 = 1;
}

void func_802A48FC(void) {
    s32 i;

    set_window_update(WINDOW_ID_6, WINDOW_UPDATE_TRANSPARENT);
    set_window_update(WINDOW_ID_7, WINDOW_UPDATE_TRANSPARENT);
    set_window_update(WINDOW_ID_8, WINDOW_UPDATE_SHOW);

    for (i = 0; i < D_802AD66C; i++) {
        hud_element_set_tint(D_802AD628[i], 0xFF, 0xFF, 0xFF);
    }

    hud_element_set_tint(D_802AD618, 0xFF, 0xFF, 0xFF);
    hud_element_set_tint(D_802AD61C, 0xFF, 0xFF, 0xFF);
    hud_element_set_tint(D_802AD620, 0xFF, 0xFF, 0xFF);
    hud_element_set_script(D_802AD618, &HudScript_AnimatedHandPointer);
    D_802AD614 = 10;
    D_802AD60B = 1;
    D_802AD604 = 20;
}

void func_802A4A10(void) {
    set_window_update(WINDOW_ID_6, WINDOW_UPDATE_TRANSPARENT);
    set_window_update(WINDOW_ID_7, WINDOW_UPDATE_TRANSPARENT);
    set_window_update(WINDOW_ID_8, WINDOW_UPDATE_SHOW);
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

                hud_element_set_render_pos(iconIndex, xTemp, phi_s1_2);
                hud_element_set_alpha(iconIndex, D_802AD624);
                hud_element_draw_without_clipping(iconIndex);
            }

            temp_s1_3 = (D_802AD605 - D_802AD608) * 13;
            temp_f6_2 = (f64) (temp_s1_3 - D_802AD60E);
            if (temp_f6_2 != 0) {
                D_802AD60E += temp_f6_2;
            } else {
                D_802AD60E = temp_s1_3;
            }

            iconIndex = D_802AD618;
            hud_element_set_render_pos(iconIndex, x + 10, y + (D_802AD60E + 26));
            hud_element_set_alpha(iconIndex, D_802AD624);
            hud_element_draw_clipped(iconIndex);

            if (D_802AD608 > 0) {
                iconIndex = D_802AD61C;
                hud_element_set_render_pos(iconIndex, x + 67, y + 16);
                hud_element_set_alpha(iconIndex, D_802AD624);
                hud_element_draw_clipped(iconIndex);
            }

            if (D_802AD609 < D_802AD66C) {
                iconIndex = D_802AD620;
                hud_element_set_render_pos(iconIndex, x + 67, y + 100);
                hud_element_set_alpha(iconIndex, D_802AD624);
                hud_element_draw_clipped(iconIndex);
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

void btl_state_draw_player_menu(void) {
    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_1:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_2:
        case BATTLE_STATE2_UNK_3:
        case BATTLE_STATE2_UNK_4:
        case BATTLE_STATE2_UNK_5:
        case BATTLE_STATE2_PLAYER_DEFEATED:
        case BATTLE_STATE2_UNK_B:
        case BATTLE_STATE2_UNK_C:
        case BATTLE_STATE2_UNK_D:
        case BATTLE_STATE2_UNK_14:
        case BATTLE_STATE2_UNK_15:
        case BATTLE_STATE2_UNK_16:
        case BATTLE_STATE2_UNK_17:
        case BATTLE_STATE2_UNK_18:
        case BATTLE_STATE2_UNK_1E:
        case BATTLE_STATE2_UNK_1F:
        case BATTLE_STATE2_UNK_20:
        case BATTLE_STATE2_UNK_21:
        case BATTLE_STATE2_UNK_22:
        case BATTLE_STATE2_UNK_28:
        case BATTLE_STATE2_UNK_29:
        case BATTLE_STATE2_UNK_2A:
        case BATTLE_STATE2_UNK_2B:
        case BATTLE_STATE2_UNK_2C:
        case BATTLE_STATE2_UNK_3D:
        case BATTLE_STATE2_UNK_3E:
        case BATTLE_STATE2_UNK_3F:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_40:
        case BATTLE_STATE2_UNK_41:
        case BATTLE_STATE2_UNK_C8:
        case BATTLE_STATE2_UNK_C9:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_CA:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_CB:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_CC:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_CD:
            btl_draw_menu_wheel();
            break;
    }
}

static const f32 padding = 0.0f;

INCLUDE_ASM(s32, "415D90", btl_state_update_partner_menu);

void btl_state_draw_partner_menu(void) {
    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_2:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_3:
        case BATTLE_STATE2_UNK_4:
        case BATTLE_STATE2_UNK_5:
        case BATTLE_STATE2_UNK_6:
        case BATTLE_STATE2_PLAYER_DEFEATED:
        case BATTLE_STATE2_UNK_B:
        case BATTLE_STATE2_UNK_C:
        case BATTLE_STATE2_UNK_D:
        case BATTLE_STATE2_UNK_E:
        case BATTLE_STATE2_UNK_14:
        case BATTLE_STATE2_UNK_15:
        case BATTLE_STATE2_UNK_16:
        case BATTLE_STATE2_UNK_17:
        case BATTLE_STATE2_UNK_18:
        case BATTLE_STATE2_UNK_1E:
        case BATTLE_STATE2_UNK_1F:
        case BATTLE_STATE2_UNK_20:
        case BATTLE_STATE2_UNK_21:
        case BATTLE_STATE2_UNK_22:
        case BATTLE_STATE2_UNK_28:
        case BATTLE_STATE2_UNK_29:
        case BATTLE_STATE2_UNK_2A:
        case BATTLE_STATE2_UNK_2B:
        case BATTLE_STATE2_UNK_2C:
        case BATTLE_STATE2_UNK_33:
        case BATTLE_STATE2_UNK_34:
        case BATTLE_STATE2_UNK_35:
        case BATTLE_STATE2_UNK_36:
        case BATTLE_STATE2_UNK_3D:
        case BATTLE_STATE2_UNK_3E:
        case BATTLE_STATE2_UNK_3F:
        case BATTLE_STATE2_UNK_40:
        case BATTLE_STATE2_UNK_41:
        case BATTLE_STATE2_UNK_C8:
        case BATTLE_STATE2_UNK_C9:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_CA:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_CB:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_CC:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_CD:
            btl_draw_menu_wheel();
            break;
    }
}

s32 func_802A9B30(void) {
    return (gBattleStatus.flags2 & BS_FLAGS2_4) <= 0;
}

// Ordering shenanigans
#ifdef NON_MATCHING
void btl_state_update_peach_menu(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    s32 temp_s0_2;
    s32 phi_v0;

    switch (gBattleState2) {
        case 0:
            btl_cam_use_preset(BTL_CAM_PRESET_C);
            btl_cam_move(0xA);
            if (!(gBattleStatus.flags1 & 0x100000)) {
                gBattleState2 = 0xB;
                break;
            }
            player->state.currentPos.x = player->homePos.x;
            player->state.currentPos.z = player->homePos.z;
            gBattleState2 = 0xA;
            player->state.goalPos.x = partner->homePos.x;
            player->state.goalPos.z = partner->homePos.z;
            player->state.moveTime = 4;
            player->state.angle = 0.0f;
            break;
        case 10:
            if (player->state.moveTime != 0) {
                player->currentPos.x += (player->state.goalPos.x - player->currentPos.x) / player->state.moveTime;
                player->currentPos.z += (player->state.goalPos.z - player->currentPos.z) / player->state.moveTime;
                partner->currentPos.x += (player->state.currentPos.x - partner->currentPos.x) / player->state.moveTime;
                partner->currentPos.z += (player->state.currentPos.z - partner->currentPos.z) / player->state.moveTime;
            }

            player->currentPos.z -= sin_rad(player->state.angle * TAU / 360.0f) * 16.0f;
            player->yaw = clamp_angle(-player->state.angle);
            partner->currentPos.z += sin_rad(player->state.angle * TAU / 360.0f) * 16.0f;
            partner->yaw = clamp_angle(-player->state.angle);
            player->state.angle += 90.0f;

            if (player->state.moveTime != 0) {
                player->state.moveTime--;
                break;
            }

            player->currentPos.x = player->state.goalPos.x;
            player->currentPos.z = player->state.goalPos.z;
            partner->currentPos.x = player->state.currentPos.x;
            partner->currentPos.z = player->state.currentPos.z;
            player->homePos.x = player->currentPos.x;
            player->homePos.z = player->currentPos.z;
            partner->homePos.x = partner->currentPos.x;
            partner->homePos.z = partner->currentPos.z;
            gBattleStatus.flags1 &= ~0x100000;
        case 11:
            gBattleStatus.flags1 |= 2;
            player->flags &= ~0x4000000;
            player->flags |= 0x08000000;

            if (partner != NULL) {
                partner->flags |= 0x4000000;
                partner->flags |= 0x08000000;
            }

            battleStatus->selectedMoveID = 0;
            battle_menu_submenuIDs = 8;
            battle_menu_isEnabled = TRUE;
            battle_menu_isMessageDisabled = 0;
            main_battle_menu_JumpHudScripts = battle_menu_PeachStarPowerHudScripts[0];
            battle_menu_messageIDs = D_802AB728[0];
            if (!(battleStatus->menuDisableFlags & 0x100)) {
                battle_menu_isEnabled = FALSE;
                battle_menu_isMessageDisabled = 0x48;
                main_battle_menu_JumpHudScripts = battle_menu_PeachStarPowerHudScripts[1];
            }

            if (func_802A9B30()) {
                D_802AD104 = 1;
                phi_v0 = 2 - 0;
                main_menu_numOptions = 1;
            } else {
                D_802AD104 = 0;
                phi_v0 = 2 - 0;
                main_menu_numOptions = 1;
            }

            D_802AD0A8 = 0;
            D_802AD0B0 = 0;
            D_802AD100 = phi_v0;
            func_802A1000();
            D_802ACC60 = 8;
            gBattleState2 = 1;
            break;
        case 1:
            set_animation(0, 0, 0xC0009);
            temp_s0_2 = func_802A11B0();
            if (D_802ACC60 != 0) {
                D_802ACC60--;
                break;
            }
            if (temp_s0_2 != 0) {
                set_animation(0, 0, 0xA0002);
                battleStatus->currentSubmenu = D_802AD0BB[temp_s0_2 - 1];
                func_802A1030();
                D_802ACC60 = 8;
                D_802ACC6C = 4;
                gBattleState2 = 2;
            }
            break;
        case 2:
            if (func_802A11B0() != 0) {
                battleStatus->unk_6C = 4;
                battleStatus->unk_6E = 5;
                battleStatus->moveCategory = 8;
                battleStatus->selectedMoveID = MOVE_PEACH_FOCUS;
                battleStatus->selectedItemID = 0xA;
                battleStatus->currentTargetListFlags = gMoveTable[MOVE_PEACH_FOCUS].flags;
                btl_set_state(0x11);
            }
            break;
        case 4:
            func_802A1050();
            gBattleState2 = 1;
            btl_state_update_peach_menu();
            btl_state_update_peach_menu();
            break;
        case 5:
            func_802A10B8();
            break;
        case 8:
            btl_show_variable_battle_message(0x50, 60, 0);
            D_802AD607 = 1;
            gBattleState2 = 9;
            break;
        case 9:
            if (!btl_is_popup_displayed()) {
                D_802AD607 = 0;
                D_802ACC60 = 0;
                gBattleState2 = 1;
            }
            break;
    }
}
#else
INCLUDE_ASM(s32, "415D90", btl_state_update_peach_menu);
#endif

void btl_state_draw_peach_menu(void) {
    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_1:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_2:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_3:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_4:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_5:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_6:
        case BATTLE_STATE2_UNK_7:
        case BATTLE_STATE2_UNK_8:
        case BATTLE_STATE2_UNK_9:
            break;
    }
}

static const f32 padding2 = 0.0f;

s32 func_802AA0A4(void) {
    return (gBattleStatus.flags2 & 2) <= 0;
}

INCLUDE_ASM(s32, "415D90", btl_state_update_twink_menu); // look into m2c bug

void btl_state_draw_twink_menu(void) {
    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_1:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_2:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_3:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_4:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_5:
            btl_draw_menu_wheel();
            break;
        case BATTLE_STATE2_UNK_6:
        case BATTLE_STATE2_UNK_7:
        case BATTLE_STATE2_UNK_8:
        case BATTLE_STATE2_UNK_9:
            break;
    }
}

INCLUDE_ASM(s32, "415D90", btl_state_update_select_target);

INCLUDE_ASM(s32, "415D90", btl_state_draw_select_target);

void btl_state_update_22(void) {
}

void btl_state_draw_22(void) {
}
