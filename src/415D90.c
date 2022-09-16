#include "common.h"
#include "battle/battle.h"
#include "hud_element.h"

extern HudScript HES_YellowArrow;

extern HudScript HES_MenuFlee;
extern HudScript HES_MenuFleeDisabled;
extern HudScript HES_MenuDefend;
extern HudScript HES_MenuDefendDisabled;
extern HudScript HES_MenuStrategies;
extern HudScript HES_MenuStrategiesDisabled;
extern HudScript HES_MenuPouch;
extern HudScript HES_MenuPouchDisabled;
extern HudScript HES_MenuDoNothing;
extern HudScript HES_MenuDoNothingDisabled;

extern HudScript HES_Kooper;
extern HudScript HES_Bombette;
extern HudScript HES_Partner0;
extern HudScript HES_Partner0Disabled;
extern HudScript HES_Goombario;
extern HudScript HES_GoombarioDisabled;
extern HudScript HES_KooperDisabled;
extern HudScript HES_BombetteDisabled;
extern HudScript HES_Parakarry;
extern HudScript HES_ParakarryDisabled;
extern HudScript HES_Bow;
extern HudScript HES_BowDisabled;
extern HudScript HES_Watt;
extern HudScript HES_WattDisabled;
extern HudScript HES_Sushie;
extern HudScript HES_SushieDisabled;
extern HudScript HES_Lakilester;
extern HudScript HES_LakilesterDisabled;
extern HudScript HES_PartnerA;
extern HudScript HES_PartnerADisabled;

extern HudScript HES_MenuBoots1;
extern HudScript HES_MenuBoots1Disabled;
extern HudScript HES_MenuBoots2;
extern HudScript HES_MenuBoots2Disabled;
extern HudScript HES_MenuBoots3;
extern HudScript HES_MenuBoots3Disabled;

extern HudScript HES_MenuHammer1;
extern HudScript HES_MenuHammer1Disabled;
extern HudScript HES_MenuHammer2;
extern HudScript HES_MenuHammer2Disabled;
extern HudScript HES_MenuHammer3;
extern HudScript HES_MenuHammer3Disabled;

extern HudScript HES_MenuItem;
extern HudScript HES_MenuItemDisabled;

extern HudScript HES_MenuStarPower;
extern HudScript HES_MenuStarPowerDisabled;

extern HudScript HES_Eldstar;
extern HudScript HES_EldstarDisabled;
extern HudScript HES_Mamar;
extern HudScript HES_MamarDisabled;
extern HudScript HES_Skolar;
extern HudScript HES_SkolarDisabled;
extern HudScript HES_Muskular;
extern HudScript HES_MuskularDisabled;
extern HudScript HES_Misstar;
extern HudScript HES_MisstarDisabled;
extern HudScript HES_Klevar;
extern HudScript HES_KlevarDisabled;
extern HudScript HES_Kalmar;
extern HudScript HES_KalmarDisabled;
extern HudScript HES_StarBeam;
extern HudScript HES_StarBeamDisabled;
extern HudScript HES_PeachBeam;
extern HudScript HES_PeachBeamDisabled;

extern HudScript HES_MoveDiamond;
extern HudScript HES_MoveBlueOrb;
extern HudScript HES_MoveGreenOrb;
extern HudScript HES_MoveRedOrb;
extern HudScript HES_MoveDiamondDisabled;
extern HudScript HES_MoveBlueOrbDisabled;
extern HudScript HES_MoveGreenOrbDisabled;
extern HudScript HES_MoveRedOrbDisabled;

extern HudScript HES_GreenArrowDown;
extern HudScript HES_GreenArrowUp;
extern HudScript HES_HandPointer;
extern HudScript HES_HandPointDownLoop;
extern HudScript HES_HandPointLeftLoop;

extern HudScript HES_FPCost;
extern HudScript HES_FPCostReduced;
extern HudScript HES_FPCostReducedTwice;
extern HudScript HES_POWCost;
extern HudScript HES_POWCostReduced;
extern HudScript HES_POWCostReducedTwice;
extern HudScript HES_StatusFlower;
extern HudScript HES_NotEnoughFP;
extern HudScript HES_NotEnoughPOW;
extern HudScript HES_ProjectorBeam;
extern HudScript HES_ProjectorReel;
extern HudScript HES_ProjectorSpot;
extern HudScript HES_SwapArrowLeft;
extern HudScript HES_SwapArrowRight;
extern HudScript HES_SwapBackground;
extern HudScript HES_SwapZ;

s16 D_802AB340[] = { 28, 40 };

s16 D_802AB344[] = { 0, -2 };

HudScript* battle_menu_JumpHudScripts[] = {
    &HES_MenuBoots1Disabled, &HES_MenuBoots1Disabled,
    &HES_MenuBoots1,&HES_MenuBoots1Disabled,
    &HES_MenuBoots2, &HES_MenuBoots2Disabled,
    &HES_MenuBoots3, &HES_MenuBoots3Disabled };

HudScript* battle_menu_HammerHudScripts[] = {
    &HES_MenuHammer1Disabled, &HES_MenuHammer1Disabled,
    &HES_MenuHammer1, &HES_MenuHammer1Disabled,
    &HES_MenuHammer2, &HES_MenuHammer2Disabled,
    &HES_MenuHammer3, &HES_MenuHammer3Disabled };

HudScript* battle_menu_ItemHudScripts[] = { &HES_MenuItem, &HES_MenuItemDisabled };

HudScript* battle_menu_StarPowerHudScripts[] = { &HES_MenuStarPower, &HES_MenuStarPowerDisabled };

HudScript* battle_menu_StarPowerMovesHudScripts[] = {
    &HES_MenuStarPower, &HES_MenuStarPowerDisabled, &HES_Eldstar, &HES_EldstarDisabled,
    &HES_Mamar, &HES_MamarDisabled, &HES_Skolar, &HES_SkolarDisabled,
    &HES_Muskular, &HES_MuskularDisabled, &HES_Misstar, &HES_MisstarDisabled,
    &HES_Klevar, &HES_KlevarDisabled, &HES_Kalmar, &HES_KalmarDisabled,
    &HES_StarBeam, &HES_StarBeamDisabled, &HES_PeachBeam, &HES_PeachBeamDisabled,
    &HES_MenuStarPower, &HES_MenuStarPowerDisabled, &HES_MenuStarPower, &HES_MenuStarPowerDisabled
};

HudScript* battle_menu_PartnerHudScripts[] = {
    &HES_Partner0, &HES_Goombario, &HES_Kooper, &HES_Bombette,
    &HES_Parakarry, &HES_Partner0, &HES_Watt, &HES_Sushie,
    &HES_Lakilester, &HES_Bow, &HES_PartnerA, &HES_PartnerA,
    &HES_PartnerA, &HES_PartnerA, &HES_PartnerA, &HES_PartnerA
};

HudScript* battle_menu_DisabledPartnerHudScripts[] = {
    &HES_Partner0Disabled, &HES_GoombarioDisabled, &HES_KooperDisabled, &HES_BombetteDisabled,
    &HES_ParakarryDisabled, &HES_Partner0Disabled, &HES_WattDisabled, &HES_SushieDisabled,
    &HES_LakilesterDisabled, &HES_BowDisabled, &HES_PartnerADisabled, &HES_PartnerADisabled,
    &HES_PartnerADisabled, &HES_PartnerADisabled, &HES_PartnerADisabled, &HES_PartnerADisabled
};

HudScript* battle_menu_StrategiesHudScript[] = { &HES_MenuStrategies };

HudScript* battle_menu_DisabledStrategiesHudScript[] = { &HES_MenuStrategiesDisabled };

HudScript* battle_menu_DoNothingHudScripts[] = { &HES_MenuDoNothing, &HES_MenuDoNothingDisabled };

HudScript* battle_menu_FleeHudScripts[] = { &HES_MenuFlee, &HES_MenuFleeDisabled };

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
    &HES_Goombario, &HES_GoombarioDisabled, &HES_MoveDiamond, &HES_MoveDiamondDisabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled,
    &HES_Kooper, &HES_KooperDisabled, &HES_MoveDiamond, &HES_MoveDiamondDisabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled,
    &HES_Bombette, &HES_BombetteDisabled, &HES_MoveDiamond, &HES_MoveDiamondDisabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled,
    &HES_Parakarry, &HES_ParakarryDisabled, &HES_MoveDiamond, &HES_MoveDiamondDisabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled,
    &HES_Partner0, &HES_Partner0Disabled, &HES_MoveDiamond, &HES_MoveDiamondDisabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled,
    &HES_Watt, &HES_WattDisabled, &HES_MoveDiamond, &HES_MoveDiamondDisabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled,
    &HES_Sushie, &HES_SushieDisabled, &HES_MoveDiamond, &HES_MoveDiamondDisabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled,
    &HES_Lakilester, &HES_LakilesterDisabled, &HES_MoveDiamond, &HES_MoveDiamondDisabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled,
    &HES_Bow, &HES_BowDisabled, &HES_MoveDiamond, &HES_MoveDiamondDisabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled };

HudScript* battle_menu_PeachStarPowerHudScripts[] = { &HES_MenuStarPower, &HES_MenuStarPowerDisabled };

// Focus
s32 D_802AB728[] = { 0x001D0055 };

HudScript* battle_menu_TwinkStarPowerHudScripts[] = { &HES_MenuStarPower, &HES_MenuStarPowerDisabled };

// Dash
s32 D_802AB734[] = { 0x001D0057 };

s32 D_802AB738[] = {
    0x00000000, 0x001D0007, 0x001D0008, 0x001D0009, 0x001D000A, 0x001D000B, 0x001D000C, 0x001D000D, 0x001D000E,
    0x001D000F, 0x001D0010, 0x001D0011, 0x001D0012, 0x00000000
};

extern s32 D_802ACC60;
extern s32 D_802ACC64;
extern s32 D_802ACC68;
extern s32 D_802ACC6C;
extern s32 D_802ACC70[];
extern s8 D_802AD000;
extern s8 D_802AD001;
extern s8 D_802AD002;
extern s8 D_802AD003;
extern s8 D_802AD004;
extern s16 D_802AD006;
extern s16 D_802AD008;
extern s16 D_802AD00A;
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
extern s32 D_802AD060;
extern s32 D_802AD064;
extern s8 D_802AD068;
extern s8 D_802AD069;
extern s8 D_802AD06A;
extern s8 D_802AD06B;
extern f32 D_802AD06C;
extern f32 D_802AD070;
extern HudScript* main_battle_menu_JumpHudScripts[];
extern s32 battle_menu_messageIDs[];
extern s32 main_menu_numOptions;
extern s32 D_802AD0A8;
extern s32 D_802AD0B0;
extern s8 D_802AD0B3;
extern s32 battle_menu_submenuIDs[];
extern s32 battle_menu_isEnabled[];
extern s32 battle_menu_isMessageDisabled[];
extern s32 D_802AD100;
extern s32 D_802AD104;
extern s8 battle_menu_moveState;
extern s8 battle_menu_moveCursorPos;
extern s8 D_802AD10A;
extern s8 D_802AD10B;
extern s8 battle_menu_moveScrollLine;
extern s8 D_802AD10D;
extern s8 D_802AD10E;
extern s8 D_802AD10F;
extern s16 battle_menu_moveScrollOffset;
extern s16 D_802AD112;
extern s16 battle_menu_moveTextColor;
extern s16 battle_menu_moveTextOpacity;
extern s32 battle_menu_moveCursorIcon;
extern s32 battle_menu_moveUpArrowIcon;
extern s32 battle_menu_moveDownArrowIcon;
extern s32 battle_menu_moveOptionIconIDs[24];
extern s32 battle_menu_moveTitleIcon;
extern s32 battle_menu_moveOptionCostUnitIconIDs[24];
extern s16 battle_menu_moveX;
extern s16 battle_menu_moveY;
extern s32 battle_menu_moveOptionIndexMap[24];
extern s32 D_802AD258;
extern HudScript* battle_menu_moveOptionIconScripts[];
extern s32 battle_menu_moveOptionNames[];
extern s32 battle_menu_moveOptionDisplayCosts[];
extern s32 battle_menu_moveOptionDisplayCostReductions[];
extern s32 battle_menu_moveOptionDisplayCostReductionColors[];
extern s32 battle_menu_moveOptionBPCosts[];
extern s32 battle_menu_hasSpiritsMenu;
extern s32 battle_menu_moveOptionCount;
extern s32 D_802AD4A8;
extern s32 battle_menu_moveOptionsEnabled[];
extern s32 battle_menu_moveOptionDescriptions[24];
extern s8 battle_menu_moveOptionSortPriorities[];
extern s8 battle_menu_moveOptionCantUseTypes[];
extern s32 battle_menu_moveOptionActive;
extern s8 D_802AD604;
extern s8 D_802AD605;
extern s8 D_802AD606;
extern s8 D_802AD607;
extern s8 D_802AD608;
extern s8 D_802AD609;
extern s8 D_802AD60A;
extern s8 D_802AD60B;
extern s16 D_802AD60C;
extern s16 D_802AD60E;
extern s16 D_802AD610;
extern s16 D_802AD612;
extern s8 D_802AD614;
extern s32 D_802AD618;
extern s32 D_802AD61C;
extern s32 D_802AD620;
extern s32 D_802AD624;
extern s32 D_802AD628[];
extern s16 D_802AD63C;
extern s16 D_802AD63E;
extern HudScript* D_802AD640[];
extern s32 D_802AD658[]; // msg IDs
extern s32 D_802AD66C;
extern u8 D_802AD66F;
extern s8 D_802AD673;
extern s32 D_802AD678[];
extern s32 D_802AD690[];
extern s32 D_802AD6A8[];
extern s32 D_802AD6C0[];
extern s32 D_802AD6D4;

void func_802A3C98(s32 x, s32 y);
void func_802A43DC(s32 arg0, s32 x, s32 y);
void func_802A4448(s32 arg0, s32 x, s32 y);
void func_802A4494(s32 arg0, s32 x, s32 y);
void func_802A4534(s32 arg0, s32 x, s32 y);
void func_802A5290(s32 arg0, s32 x, s32 y);
void func_802A56F8(s32 arg0, s32 x, s32 y);
void func_802A5738(s32 arg0, s32 x, s32 y);
void func_802A57C8(s32 arg0, s32 x, s32 y);

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
// so close
#ifdef NON_MATCHING
s32 func_802A11B0(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    f32 var_f20;
    s32 id;
    s32 i;
    f32 x, y;
    f32 x2, y2;

    switch (D_802AD000) {
        case 0:
            D_802AD060 = 54;
            D_802AD064 = 173;
            D_802AD070 = 0.3f;
            D_802AD004 = 0;
            D_802AD06B = D_802AD0B3;
            D_802AD069 = -D_802AD0B3;
            D_802AD06A = main_menu_numOptions - 1;
            D_802AD06A -= D_802AD0B3;

            for (i = 0; i < main_menu_numOptions; i++) {
                D_802AD010[i] = id = hud_element_create(main_battle_menu_JumpHudScripts[i]);
                hud_element_set_render_depth(id, 5);
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_FILTER_TEX);
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                hud_element_set_scale(id, 0.75f);

                D_802AD028[i] = id = hud_element_create(&HES_ProjectorSpot);
                hud_element_create_transform_B(id);
                hud_element_set_render_depth(id, 10);
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_FILTER_TEX);
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
            }

            D_802AD040 = id = hud_element_create(&HES_ProjectorSpot);
            hud_element_create_transform_B(id);
            hud_element_set_render_depth(id, 7);
            hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);
            hud_element_set_flags(id, HUD_ELEMENT_FLAGS_FILTER_TEX);
            hud_element_set_flags(id, HUD_ELEMENT_FLAGS_DISABLED);

            D_802AD044 = id = hud_element_create(&HES_ProjectorReel);
            hud_element_create_transform_B(id);
            hud_element_set_render_depth(id, 0);
            hud_element_set_render_pos(id, 40, 212);
            hud_element_set_tint(id, 0, 91, 127);
            hud_element_set_transform_rotation_pivot(id, 0x10, -0x10);
            hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);
            hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_FILTER_TEX);
            hud_element_set_alpha(id, 240);

            D_802AD048 = id = hud_element_create(&HES_ProjectorReel);
            hud_element_create_transform_B(id);
            hud_element_set_render_depth(id, 2);
            hud_element_set_render_pos(id, 39, 212);
            hud_element_set_tint(id, 0, 91, 127);
            hud_element_set_transform_rotation_pivot(id, 0x10, -0x10);
            hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);
            hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_FILTER_TEX);
            hud_element_set_alpha(id, 240);

            D_802AD04C = id = hud_element_create(&HES_ProjectorBeam);
            hud_element_create_transform_B(id);
            hud_element_set_render_depth(id, 20);
            hud_element_set_render_pos(id, 78, 178);
            hud_element_set_tint(id, 255, 255, 255);
            hud_element_set_transform_rotation_pivot(id, 0, 0);
            hud_element_set_transform_rotation(id, 0.0f, 0.0f, -45.0f);
            hud_element_set_alpha(id, 200);
            hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);
            hud_element_set_flags(id, HUD_ELEMENT_FLAGS_FILTER_TEX);
            hud_element_set_flags(id, HUD_ELEMENT_FLAGS_DISABLED);

            D_802AD05C = id = hud_element_create(&HES_SwapBackground);
            hud_element_set_render_depth(id, 0);
            hud_element_set_render_pos(id, 97, 208);
            hud_element_set_tint(id, 255, 255, 255);
            hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);
            hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_FILTER_TEX);
            hud_element_set_alpha(id, 230);

            D_802AD050 = id = hud_element_create(&HES_SwapZ);
            hud_element_set_render_depth(id, 5);
            hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_FILTER_TEX);
            hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);
            hud_element_set_render_pos(id, 94, 209);

            D_802AD054 = id = hud_element_create(&HES_SwapArrowLeft);
            hud_element_set_render_depth(id, 5);
            hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_FILTER_TEX);
            hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);
            hud_element_set_render_pos(id, 81, 210);

            D_802AD058 = id = hud_element_create(&HES_SwapArrowRight);
            hud_element_set_render_depth(id, 5);
            hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_FILTER_TEX);
            hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);
            hud_element_set_render_pos(id, 102, 210);
            D_802AD00A = 100;
            D_802AD001 = 3;
            D_802AD000 = 1;
            D_802AD06C = var_f20 = D_802AD100 * 28;
            break;
        case 1:
            D_802AD00A = (D_802AD001 * 100) / 3;

            switch (D_802AD001) {
                case 1:
                    if (D_802AD001 == 1) {
                        id = D_802AD04C;
                        hud_element_clear_flags(id, 2);
                    }
                default:
                    D_802AD001--;
                    break;
                case 0:
                    D_802AD002 = 0;
                    D_802AD003 = 0;

                    D_802AD06C = var_f20 = D_802AD100 * 28;
                    for (i = 0; i < main_menu_numOptions; i++, var_f20 += 28.0f) {
                        s32 id;

                        x = 0.0f;
                        y = 0.0f;
                        add_vec2D_polar(&x, &y, 87.0f, var_f20);

                        x2 = D_802AD060 + x;
                        y2 = D_802AD064 + y;
                        id = D_802AD010[i];
                        hud_element_set_render_pos(id, x2, y2);
                        hud_element_clear_flags(id, 2);

                        id = D_802AD028[i];
                        hud_element_set_render_pos(id, x2, y2);
                        hud_element_set_alpha(id, 100);
                        hud_element_clear_flags(id, 2);
                    }

                    x = 0.0f;
                    y = 0.0f;
                    add_vec2D_polar(&x, &y, 87.0f, D_802AD100 * 28);

                    id = D_802AD040;
                    hud_element_set_render_pos(id, D_802AD060 + x, D_802AD064 + y);
                    hud_element_set_alpha(id, 180);
                    hud_element_set_scale(id, 0.85f);
                    hud_element_clear_flags(id, 2);
                    D_802AD000 = 2;
                    break;
            }
            break;
        case 2:
            if (battleStatus->currentButtonsPressed & BUTTON_A) {
                if (battle_menu_isEnabled[D_802AD002 + D_802AD06B] == 1) {
                    sfx_play_sound(SOUND_MENU_NEXT);
                    D_802AD000 = -1;
                } else {
                    sfx_play_sound(SOUND_MENU_ERROR);
                    D_802AD068 = battle_menu_isMessageDisabled[D_802AD002 + D_802AD06B];
                    D_802AD000 = 100;
                }
            } else {
                D_802AD003 = D_802AD002;
                if (D_802AD004 == 0) {
                    if ((battleStatus->currentButtonsHeld & (BUTTON_STICK_LEFT | BUTTON_STICK_UP)) &&
                        (D_802AD069 < D_802AD002))
                    {
                        D_802AD002--;
                    }
                    if ((battleStatus->currentButtonsHeld & (BUTTON_STICK_RIGHT | BUTTON_STICK_DOWN)) &&
                        (D_802AD002 < D_802AD06A))
                    {
                        D_802AD002++;
                    }
                }

                if (D_802AD003 != D_802AD002) {
                    D_802AD004 = 1;
                    sfx_play_sound(SOUND_MENU_CHANGE_TAB);
                }
            }
            break;
        case -1:
            D_802AD008 = 100;
            return D_802AD002 + D_802AD06B + 1;
        case 10:
            D_802AD001 = 0;
            D_802AD006 = 0;
            D_802AD000 = 11;
            return D_802AD002 + D_802AD06B + 1;
        case 11:
            return D_802AD002 + D_802AD06B + 1;
        case 20:
            D_802AD001 = 3;
            D_802AD006 = 255;
            D_802AD000 = 2;
            return D_802AD002 + D_802AD06B + 1;
        case 30:
            D_802AD001 = 3;
            D_802AD006 = 255;
            D_802AD000 = -1;
            break;
        case 100:
            btl_show_battle_message(D_802AD068, 90);
            D_802AD000 = 101;
            break;
        case 101:
            if (!btl_is_popup_displayed()) {
                D_802AD068 = -1;
                D_802AD000 = 2;
            }
            break;
    }
    return 0;
}
#else
INCLUDE_ASM(s32, "415D90", func_802A11B0);
#endif

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
                        hud_element_set_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    } else {
                        hud_element_clear_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
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

    hud_element_set_script(battle_menu_moveCursorIcon, &HES_AnimatedHandPointer);
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

    hud_element_set_script(battle_menu_moveCursorIcon, &HES_AnimatedHandPointer);
    battle_menu_moveTextColor = 10;
    D_802AD10F = 1;
    battle_menu_moveState = 20;
}

void func_802A2C58(void) {
    set_window_update(WINDOW_ID_8, WINDOW_UPDATE_SHOW);
    battle_menu_moveState = 30;
}

s32 func_802A2C84(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    s8 temp_v0_14;
    s32 moveX;
    s32 moveY;
    s32 msgWidth;
    s32 msgX;
    s32 msgID;
    s32 cond;
    s32 id;
    s32 i;
    s32 j;

    switch (battle_menu_moveState) {
        case 0:
            battle_menu_moveScrollOffset = -battle_menu_moveScrollLine * 13;
            D_802AD112 = (battle_menu_moveCursorPos - battle_menu_moveScrollLine) * 13;
            battle_menu_moveX = 20;
            battle_menu_moveY = 68;

            for (i = 0; i < battle_menu_moveOptionCount; i++) {
                battle_menu_moveOptionIndexMap[i] = i;
            }

            if (!battle_menu_hasSpiritsMenu) {
                for (i = 0; i < (battle_menu_moveOptionCount - 1); i++) {
                    for (j = i + 1; j < battle_menu_moveOptionCount; j++) {
                        do {
                            s32 temp1 = battle_menu_moveOptionIndexMap[i];
                            s32 temp2 = battle_menu_moveOptionIndexMap[j];

                            if (battle_menu_moveOptionSortPriorities[temp1] < battle_menu_moveOptionSortPriorities[temp2]) {
                                continue;
                            }

                            if (
                                battle_menu_moveOptionSortPriorities[temp1] != battle_menu_moveOptionSortPriorities[temp2] ||
                                (battle_menu_moveOptionDisplayCosts[temp1] >= battle_menu_moveOptionDisplayCosts[temp2]) &&
                                (battle_menu_moveOptionDisplayCosts[temp1] != battle_menu_moveOptionDisplayCosts[temp2] ||
                                    battle_menu_moveOptionBPCosts[temp1] >= battle_menu_moveOptionBPCosts[temp2])
                            )
                            {
                                s32 swapTmp = battle_menu_moveOptionIndexMap[i];
                                battle_menu_moveOptionIndexMap[i] = battle_menu_moveOptionIndexMap[j];
                                battle_menu_moveOptionIndexMap[j] = swapTmp;
                            }
                        } while (0);
                    }
                }
            }

            for (i = 0; i < battle_menu_moveOptionCount; i++) {
                id = hud_element_create(battle_menu_moveOptionIconScripts[battle_menu_moveOptionIndexMap[i]]);
                battle_menu_moveOptionIconIDs[i] = id;
                hud_element_set_scale(id, 0.45f);
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_FILTER_TEX | HUD_ELEMENT_FLAGS_80);
            }

            id = hud_element_create(&HES_AnimatedHandPointer);
            battle_menu_moveCursorIcon = id;
            hud_element_set_flags(id, HUD_ELEMENT_FLAGS_DROP_SHADOW | HUD_ELEMENT_FLAGS_80);
            hud_element_set_render_pos(id, battle_menu_moveX, battle_menu_moveY);

            id = hud_element_create(&HES_GreenArrowUp);
            battle_menu_moveUpArrowIcon = id;
            hud_element_set_flags(id, HUD_ELEMENT_FLAGS_DROP_SHADOW | HUD_ELEMENT_FLAGS_80);
            hud_element_set_render_pos(id, battle_menu_moveX + 39, battle_menu_moveY - 7);

            id = hud_element_create(&HES_GreenArrowDown);
            battle_menu_moveDownArrowIcon = id;
            hud_element_set_flags(id, HUD_ELEMENT_FLAGS_DROP_SHADOW | HUD_ELEMENT_FLAGS_80);
            hud_element_set_render_pos(id, battle_menu_moveX + 39, battle_menu_moveY + 78);

            if (battle_menu_hasSpiritsMenu == 0) {
                id = hud_element_create(&HES_StatusFlower);
                battle_menu_moveTitleIcon = id;
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);
            } else {
                id = hud_element_create(&HES_MenuStarPower);
                battle_menu_moveTitleIcon = id;
                hud_element_set_scale(id, 0.75f);
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);
            }
            hud_element_set_render_pos(id, battle_menu_moveX + 56, battle_menu_moveY);

            for (i = 0; i < battle_menu_moveOptionCount; i++) {
                if (!battle_menu_hasSpiritsMenu) {
                    switch (battle_menu_moveOptionDisplayCostReductionColors[i]) {
                        case 0:
                            id = hud_element_create(&HES_FPCost);
                            battle_menu_moveOptionCostUnitIconIDs[i] = id;
                            break;
                        case 1:
                            id = hud_element_create(&HES_FPCostReduced);
                            battle_menu_moveOptionCostUnitIconIDs[i] = id;
                            break;
                        default:
                            id = hud_element_create(&HES_FPCostReducedTwice);
                            battle_menu_moveOptionCostUnitIconIDs[i] = id;
                            break;
                    }
                } else {
                    switch (battle_menu_moveOptionDisplayCostReductionColors[i]) {
                        case 0:
                            id = hud_element_create(&HES_POWCost);
                            battle_menu_moveOptionCostUnitIconIDs[i] = id;
                            break;
                        case 1:
                            id = hud_element_create(&HES_POWCostReduced);
                            battle_menu_moveOptionCostUnitIconIDs[i] = id;
                            break;
                        default:
                            id = hud_element_create(&HES_POWCostReducedTwice);
                            battle_menu_moveOptionCostUnitIconIDs[i] = id;
                            break;
                    }
                }
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_80);
                hud_element_set_render_pos(id, battle_menu_moveX + 56, battle_menu_moveY);
            }

            battle_menu_moveTextColor = 0xA;

            moveX = battle_menu_moveX;
            moveY = battle_menu_moveY;
            if (!battle_menu_hasSpiritsMenu) {
                set_window_properties(1, moveX, moveY, 150, (D_802AD10E * 13) + 28, 0, func_802A3C98, NULL, -1);
                set_window_properties(2, moveX + 16, moveY - 6, 90, 16, 1, func_802A43DC, NULL, -1);
                set_window_properties(3, moveX + 114, moveY - 12, 32, 32, 1, func_802A4448, NULL, -1);
            } else {
                s16 new_var;

                set_window_properties(1, moveX, moveY, 144, (D_802AD10E * 13) + 28, 0, func_802A3C98, NULL, -1);
                new_var = moveY; // todo required to match
                set_window_properties(4, moveX + 10, new_var - 6, 100, 16, 1, func_802A43DC, 0, -1);
                set_window_properties(5, moveX + 110, new_var - 12, 32, 35, 1, func_802A4448, 0, -1);
            }

            moveX = 20;
            moveY = battle_menu_moveY;
            set_window_properties(8, moveX, 186, 280, 32, 20, func_802A4494, NULL, -1);
            set_window_update(1, 1);
            if (!battle_menu_hasSpiritsMenu) {
                set_window_update(2, 1);
                set_window_update(3, 1);
            } else {
                set_window_update(4, 1);
                set_window_update(5, 1);
            }
            set_window_update(8, 1);

            do {
                cond = FALSE;
                if (battle_menu_moveCursorPos >= (battle_menu_moveScrollLine + D_802AD10D) - 1) {
                    battle_menu_moveScrollLine++;
                    if (battle_menu_moveScrollLine > battle_menu_moveOptionCount - 6) {
                        battle_menu_moveScrollLine = battle_menu_moveOptionCount - 6;
                        if (battle_menu_moveScrollLine < 0) {
                            battle_menu_moveScrollLine = 0;
                        }
                    } else {
                        cond = TRUE;
                    }
                }
            } while (cond);

            battle_menu_moveState = 1;
            D_802AD10D = battle_menu_moveScrollLine + 6;
            battle_menu_moveScrollOffset = -battle_menu_moveScrollLine * 13;
            D_802AD112 = (battle_menu_moveCursorPos - battle_menu_moveScrollLine) * 13;
            break;
        case 1:
            D_802AD10A = battle_menu_moveCursorPos;
            if (battleStatus->currentButtonsHeld & (BUTTON_STICK_UP | BUTTON_Z)) {
                if (battle_menu_moveCursorPos > 0) {
                    battle_menu_moveCursorPos--;
                } else if (battleStatus->currentButtonsPressed & (BUTTON_STICK_UP | BUTTON_Z)) {
                    battle_menu_moveCursorPos--;
                }
            }

            if (battleStatus->currentButtonsHeld & (BUTTON_STICK_DOWN | BUTTON_R)) {
                if (battle_menu_moveCursorPos < battle_menu_moveOptionCount - 1) {
                    battle_menu_moveCursorPos++;
                } else if (battleStatus->currentButtonsPressed & (BUTTON_STICK_DOWN | BUTTON_R)) {
                    battle_menu_moveCursorPos++;
                }
            }

            if (battle_menu_moveCursorPos < 0) {
                battle_menu_moveCursorPos = battle_menu_moveOptionCount - 1;
            }

            if (battle_menu_moveOptionCount - 1 < battle_menu_moveCursorPos) {
                battle_menu_moveCursorPos = 0;
            }

            if (D_802AD10A != battle_menu_moveCursorPos) {
                hud_element_set_scale(battle_menu_moveOptionIconIDs[D_802AD10A], 0.45f);
                sfx_play_sound(SOUND_MENU_CHANGE_SELECTION);
            }

            if (battle_menu_moveCursorPos < battle_menu_moveScrollLine + 1) {
                battle_menu_moveScrollLine--;
                if (battle_menu_moveScrollLine < 0) {
                    battle_menu_moveScrollLine = 0;
                }
            }

            if (battle_menu_moveCursorPos >= (D_802AD10D - 1)) {
                battle_menu_moveScrollLine++;
                if (battle_menu_moveScrollLine > battle_menu_moveOptionCount - 6) {
                    battle_menu_moveScrollLine = battle_menu_moveOptionCount - 6;
                    if (battle_menu_moveScrollLine < 0) {
                        battle_menu_moveScrollLine = 0;
                    }
                }
            }

            D_802AD10D = battle_menu_moveScrollLine + 6;
            if (battleStatus->currentButtonsPressed & BUTTON_A) {
                if (battle_menu_moveOptionsEnabled[battle_menu_moveOptionIndexMap[battle_menu_moveCursorPos]] == 1) {
                    sfx_play_sound(SOUND_MENU_NEXT);
                    battle_menu_moveState = -1;
                } else {
                    sfx_play_sound(SOUND_MENU_ERROR);
                    D_802AD258 = 0;
                    temp_v0_14 = battle_menu_moveOptionCantUseTypes[battle_menu_moveOptionIndexMap[battle_menu_moveCursorPos]];
                    if (temp_v0_14 != 0) {
                        D_802AD258 = temp_v0_14;
                    }
                    battle_menu_moveState = 40;
                }
                break;
            }

            if (battleStatus->currentButtonsPressed & 0x4000) {
                sfx_play_sound(SOUND_MENU_BACK);
                func_802A27E4();
                battle_menu_moveState = -2;
            }
            break;
        case -1:
            for (i = 0; i < battle_menu_moveOptionCount; i++) {
                id = battle_menu_moveOptionIconIDs[i];
                hud_element_set_tint(id, 160, 160, 160);
            }
            hud_element_set_tint(battle_menu_moveCursorIcon, 160, 160, 160);
            hud_element_set_tint(battle_menu_moveUpArrowIcon, 160, 160, 160);
            hud_element_set_tint(battle_menu_moveDownArrowIcon, 160, 160, 160);
            hud_element_set_tint(battle_menu_moveTitleIcon, 160, 160, 160);

            for (i = 0; i < battle_menu_moveOptionCount; i++) {
                id = battle_menu_moveOptionCostUnitIconIDs[i];
                hud_element_set_tint(id, 160, 160, 160);
            }

            hud_element_set_script(battle_menu_moveCursorIcon, &HES_HandPointer);
            battle_menu_moveTextColor = 0xD;
            set_window_update(1, 4);
            if (!battle_menu_hasSpiritsMenu) {
                set_window_update(2, 4);
                set_window_update(3, 4);
            } else {
                set_window_update(4, 4);
                set_window_update(5, 4);
            }
            set_window_update(8, 2);
            if (!battle_menu_hasSpiritsMenu) {
                status_menu_stop_blinking_fp();
            } else {
                status_menu_stop_blinking_sp();
            }
            battle_menu_moveOptionActive = battle_menu_moveCursorPos;
            return battle_menu_moveOptionIndexMap[battle_menu_moveCursorPos] + 1;
        case -2:
            if (!battle_menu_hasSpiritsMenu) {
                status_menu_stop_blinking_fp();
            } else {
                status_menu_stop_blinking_sp();
            }
            return 255;
        case 10:
            set_window_update(1, 2);
            if (!battle_menu_hasSpiritsMenu) {
                set_window_update(2, 2);
                set_window_update(3, 2);
            } else {
                set_window_update(4, 2);
                set_window_update(5, 2);
            }
            set_window_update(8, 2);
            if (!battle_menu_hasSpiritsMenu) {
                status_menu_stop_blinking_fp();
            } else {
                status_menu_stop_blinking_sp();
            }
            battle_menu_moveState = 11;
            battle_menu_moveOptionActive = battle_menu_moveCursorPos;
            return battle_menu_moveOptionIndexMap[battle_menu_moveCursorPos] + 1;
        case 11:
            battle_menu_moveOptionActive = battle_menu_moveCursorPos;
            return battle_menu_moveOptionIndexMap[battle_menu_moveCursorPos] + 1;
        case 20:
            set_window_update(1, 1);
            if (!battle_menu_hasSpiritsMenu) {
                set_window_update(2, 1);
                set_window_update(3, 1);
            } else {
                set_window_update(4, 1);
                set_window_update(5, 1);
            }
            set_window_update(8, 1);
            battle_menu_moveState = 1;
            battle_menu_moveOptionActive = battle_menu_moveCursorPos;
            return battle_menu_moveOptionIndexMap[battle_menu_moveCursorPos] + 1;
        case 30:
            set_window_update(1, 9);
            if (!battle_menu_hasSpiritsMenu) {
                set_window_update(2, 9);
                set_window_update(3, 9);
            } else {
                set_window_update(4, 9);
                set_window_update(5, 9);
            }
            set_window_update(8, 2);
            battle_menu_moveState = -1;
            break;
        case 40:
            battle_menu_moveOptionActive = -1;
            battle_menu_moveState = 41;
            return -1;
        case 41:
            set_window_update(1, 2);
            if (!battle_menu_hasSpiritsMenu) {
                set_window_update(2, 2);
                set_window_update(3, 2);
            } else {
                set_window_update(4, 2);
                set_window_update(5, 2);
            }
            set_window_update(8, 2);

            msgID = 0x1D00C3;
            if (D_802AD258 == 0) {
                if (!battle_menu_hasSpiritsMenu) {
                    msgID = 0x1D009F;
                } else {
                    msgID = 0x1D00A0;
                }
            }

            msgWidth = get_msg_width(msgID, 0) + 23;
            moveX = (SCREEN_WIDTH / 2) - (msgWidth / 2);
            set_window_properties(9, moveX, 80, msgWidth, D_802AB340[get_msg_lines(msgID) - 1], 0x14, func_802A4534, NULL, -1);
            set_window_update(9, 1);
            D_802AD10B = 60;
            battle_menu_moveState = 42;
            return -1;
        case 42:
            if (gGameStatusPtr->pressedButtons[0] & (BUTTON_A | BUTTON_B)) {
                D_802AD10B = 0;
            }
            if (D_802AD10B != 0) {
                D_802AD10B--;
                return -1;
            }
            set_window_update(9, 2);
            set_window_update(1, 1);
            if (!battle_menu_hasSpiritsMenu) {
                set_window_update(2, 1);
                set_window_update(3, 1);
            } else {
                set_window_update(4, 1);
                set_window_update(5, 1);
            }
            set_window_update(8, 1);
            battle_menu_moveState = 1;
            break;
    }
    return 0;
}

const f32 padding3 = 0.0f;

// needs a lot of work
#ifdef NON_MATCHING
void func_802A3C98(s32 x, s32 y) {
    s32 palette;
    s32 num;
    s32 id;
    s32 i;

    s32 var_t0;
    s32 var_t0_4;
    s32 temp_f6_2;
    s32 moveOptX;
    s32 moveOptY;
    s32 t2;
    s32 temp1;

    switch (battle_menu_moveState) {
        case -1:
        case 1:
        case 10:
        case 20:
        case 30:
        case 40:
        case 41:
            temp_f6_2 = ((-battle_menu_moveScrollLine * 13) - battle_menu_moveScrollOffset) * 0.5;
            var_t0 = battle_menu_moveScrollOffset + temp_f6_2;
            if (temp_f6_2 == 0) {
                var_t0 = -battle_menu_moveScrollLine * 13;
            }
            battle_menu_moveScrollOffset = var_t0;
            t2 = D_802AD10E * 13;

            moveOptY = y + (battle_menu_moveScrollOffset + 19);
            moveOptX = x + 31;

            temp1 = y + 18 + (t2 + 1);

            gDPSetScissor(
                gMasterGfxPos++, G_SC_NON_INTERLACE,
                x + 2,
                y + 18,
                x + 153,
                temp1
            );

            for (i = 0; i < battle_menu_moveOptionCount; i++) {
                if ((i >= battle_menu_moveScrollLine - 1) && (i <= battle_menu_moveScrollLine + D_802AD10E)) {
                    palette = battle_menu_moveTextColor;
                    if (battle_menu_moveOptionsEnabled[battle_menu_moveOptionIndexMap[i]] <= 0) {
                        palette = 0xB;
                    }

                    if (battle_menu_moveOptionNames[battle_menu_moveOptionIndexMap[i]] >= 0) {
                        draw_msg(battle_menu_moveOptionNames[battle_menu_moveOptionIndexMap[i]], moveOptX, moveOptY, battle_menu_moveTextOpacity, palette, 1);
                    }

                    num = battle_menu_moveOptionDisplayCosts[battle_menu_moveOptionIndexMap[i]] - battle_menu_moveOptionDisplayCostReductions[battle_menu_moveOptionIndexMap[i]];
                    if ((battle_menu_moveOptionDisplayCosts[battle_menu_moveOptionIndexMap[i]] != 0) && (num <= 0)) {
                        num = 1;
                    }

                    if (!battle_menu_hasSpiritsMenu) {
                        if (i == battle_menu_moveCursorPos) {
                            if (num == 0 || (battle_menu_moveOptionsEnabled[battle_menu_moveOptionIndexMap[i]] <= 0)) {
                                status_menu_stop_blinking_fp();
                            } else {
                                status_menu_start_blinking_fp();
                            }
                        }
                    } else {
                        if (i == battle_menu_moveCursorPos) {
                            if (num == 0 || (battle_menu_moveOptionsEnabled[battle_menu_moveOptionIndexMap[i]] <= 0)) {
                                status_menu_stop_blinking_sp();
                            } else {
                                status_menu_start_blinking_sp_bars(battle_menu_moveOptionDisplayCosts[battle_menu_moveOptionIndexMap[i]]);
                            }
                        }
                    }

                    switch (battle_menu_moveOptionDisplayCostReductionColors[i]) {
                        case 0:
                            palette = 0xA;
                            break;
                        case 1:
                            palette = 0x37;
                            break;
                        default:
                            palette = 0x38;
                            break;
                    }

                    if (battle_menu_moveOptionsEnabled[battle_menu_moveOptionIndexMap[i]] <= 0) {
                        palette = 0xB;
                    }

                    if (battle_menu_moveOptionDisplayCosts[battle_menu_moveOptionIndexMap[i]] != 0) {
                        id = battle_menu_moveOptionCostUnitIconIDs[i];
                        if (!battle_menu_hasSpiritsMenu) {
                            draw_number(num, moveOptX + 108, moveOptY, 1, palette, battle_menu_moveTextOpacity, 3);
                            if (battle_menu_moveOptionsEnabled[battle_menu_moveOptionIndexMap[i]] <= 0) {
                                hud_element_set_script(id, &HES_NotEnoughFP);
                            }
                            moveOptX += 116;
                        } else {
                            draw_number(num, moveOptX + 93, moveOptY, 1, palette, battle_menu_moveTextOpacity, 3);
                            if (battle_menu_moveOptionsEnabled[battle_menu_moveOptionIndexMap[i]] <= 0) {
                                hud_element_set_script(id, &HES_NotEnoughPOW);
                            }
                            moveOptX += 102;
                        }
                        hud_element_set_render_pos(id, moveOptX, moveOptY + 7);
                        hud_element_set_alpha(id, battle_menu_moveTextOpacity);
                        hud_element_draw_without_clipping(id);
                    }
                    moveOptY += 13;
                }
            }

            moveOptX = x + 24;
            moveOptY = battle_menu_moveScrollOffset + y + 24;
            for (i = 0; i < battle_menu_moveOptionCount; i++) {
                if (i >= (battle_menu_moveScrollLine - 1) && i <= (battle_menu_moveScrollLine + D_802AD10E)) {
                    id = battle_menu_moveOptionIconIDs[i];
                    hud_element_set_render_pos(id, moveOptX, moveOptY);
                    hud_element_set_alpha(id, battle_menu_moveTextOpacity);
                    hud_element_draw_without_clipping(id);
                }
                moveOptY += 13;
            }

            temp_f6_2 =  (f64) ((battle_menu_moveCursorPos - battle_menu_moveScrollLine) * 13 - D_802AD112);
            var_t0_4 = D_802AD112 + temp_f6_2;
            if (temp_f6_2 == 0) {
                var_t0_4 = (battle_menu_moveCursorPos - battle_menu_moveScrollLine) * 13;
            }
            D_802AD112 = var_t0_4;

            id = battle_menu_moveCursorIcon;
            hud_element_set_render_pos(id, x + 10, y + (var_t0_4 + 26));
            hud_element_set_alpha(id, battle_menu_moveTextOpacity);
            hud_element_draw_without_clipping(id);

            if (battle_menu_moveScrollLine > 0) {
                id = battle_menu_moveUpArrowIcon;
                hud_element_set_render_pos(id, x + 72, y + 15);
                hud_element_set_alpha(id, battle_menu_moveTextOpacity);
                hud_element_draw_clipped(id);
            }

            if (D_802AD10D < battle_menu_moveOptionCount) {
                id = battle_menu_moveDownArrowIcon;
                hud_element_set_render_pos(id, x + 72, y + 100);
                hud_element_set_alpha(id, battle_menu_moveTextOpacity);
                hud_element_draw_clipped(id);
            }

            if (battle_menu_moveState == -1) {
                if (!battle_menu_hasSpiritsMenu) {
                    status_menu_stop_blinking_fp();
                } else {
                    status_menu_stop_blinking_sp();
                }
            }
            break;
    }
}
#else
INCLUDE_ASM(s32, "415D90", func_802A3C98);
#endif

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
    } else if (!battle_menu_hasSpiritsMenu) {
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
    hud_element_set_script(D_802AD618, &HES_AnimatedHandPointer);
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
    hud_element_set_script(D_802AD618, &HES_AnimatedHandPointer);
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

// v0/v1 dumb
#ifdef NON_MATCHING
s32 func_802A4A54(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;
    s32 x;
    s32 y;
    s32 width;
    s32 msgID;
    s32 i;

    switch (D_802AD604) {
        case 0:
            D_802AD63C = 20;
            D_802AD63E = 68;
            D_802AD60C = -D_802AD608 * 13;
            D_802AD60E = (D_802AD605 - D_802AD608) * 13;

            for (i = 0; i < D_802AD66C; i++) {
                D_802AD628[i] = id = hud_element_create(D_802AD640[i]);
                hud_element_set_scale(id, 0.45f);
                hud_element_set_flags(id, HUD_ELEMENT_FLAGS_FILTER_TEX | HUD_ELEMENT_FLAGS_80);
            }

            D_802AD618 = id = hud_element_create(HES_AnimatedHandPointer);
            hud_element_set_flags(id, HUD_ELEMENT_FLAGS_DROP_SHADOW | HUD_ELEMENT_FLAGS_80);
            hud_element_set_render_pos(id, D_802AD63C, D_802AD63E);

            D_802AD61C = id = hud_element_create(HES_GreenArrowUp);
            hud_element_set_flags(id, HUD_ELEMENT_FLAGS_DROP_SHADOW | HUD_ELEMENT_FLAGS_80);
            hud_element_set_render_pos(id, D_802AD63C + 39, D_802AD63E - 7);

            D_802AD620 = id = hud_element_create(HES_GreenArrowDown);
            hud_element_set_flags(id, HUD_ELEMENT_FLAGS_DROP_SHADOW | HUD_ELEMENT_FLAGS_80);
            hud_element_set_render_pos(id, D_802AD63C + 39, D_802AD63E + 78);

            D_802AD614 = 10;
            x = D_802AD63C;
            y = D_802AD63E;
            set_window_properties(6, x, y, 144, (D_802AD60A * 13) + 26, 0, func_802A5290, NULL, -1);
            set_window_properties(7, x + 18, y - 6, 108, 16, 1, func_802A56F8, NULL, -1);
            x = 20;
            y = 186;
            set_window_properties(8, x, y, 280, 32, 0x14, func_802A5738, NULL, -1);
            set_window_update(6, 1);
            set_window_update(7, 1);
            set_window_update(8, 1);
            D_802AD604 = 1;
            break;
        case 1:
            if (D_802AD607 == 0) {
                D_802AD606 = D_802AD605;
                if (battleStatus->currentButtonsHeld & BUTTON_STICK_UP) {
                    if (D_802AD605 > 0) {
                        D_802AD605--;
                    } else if (battleStatus->currentButtonsPressed & BUTTON_STICK_UP) {
                        D_802AD605--;
                    }
                }

                if (battleStatus->currentButtonsHeld & BUTTON_STICK_DOWN) {
                    if (D_802AD605 < D_802AD66C - 1) {
                        D_802AD605++;
                    } else if (battleStatus->currentButtonsPressed & BUTTON_STICK_DOWN) {
                        D_802AD605++;
                    }
                }

                if (D_802AD605 < 0) {
                    D_802AD605 = D_802AD66F - 1;
                }
                if (D_802AD66C - 1 < D_802AD605) {
                    D_802AD605 = 0;
                }

                if (D_802AD606 != D_802AD605) {
                    hud_element_set_scale(D_802AD628[D_802AD606], 0.45f);
                    sfx_play_sound(SOUND_MENU_CHANGE_SELECTION);
                }

                if (D_802AD605 < D_802AD608) {
                    D_802AD608 = D_802AD605;
                }
                if (D_802AD605 >= D_802AD609) {
                    D_802AD608 = D_802AD605 - ((u8) D_802AD60A - 1);
                }
                D_802AD609 = D_802AD608 + 6;
                if (D_802AD609 > D_802AD66C) {
                    D_802AD609 = D_802AD66C;
                }

                if (battleStatus->currentButtonsPressed & BUTTON_A) {
                    if (D_802AD690[D_802AD605] == 1) {
                        sfx_play_sound(SOUND_MENU_NEXT);
                        D_802AD604 = -1;
                    } else {
                        sfx_play_sound(SOUND_MENU_ERROR);
                        D_802AD604 = 40;
                        D_802AD610 = D_802AD6A8[D_802AD605];
                    }
                    break;
                }

                if (battleStatus->currentButtonsPressed & BUTTON_B) {
                    sfx_play_sound(SOUND_MENU_BACK);
                    func_802A472C();
                    D_802AD604 = -2;
                }
            }
            break;
        case -1:
            for (i = 0; i < D_802AD66C; i++) {
                hud_element_set_tint(D_802AD628[i], 160, 160, 160);
            }
            hud_element_set_tint(D_802AD618, 160, 160, 160);
            hud_element_set_tint(D_802AD61C, 160, 160, 160);
            hud_element_set_tint(D_802AD620, 160, 160, 160);
            hud_element_set_script(D_802AD618, HES_HandPointer);
            D_802AD614 = 13;
            set_window_update(6, 4);
            set_window_update(7, 4);
            set_window_update(8, 2);
            return D_802AD605 + 1;
        case -2:
            return 0xFF;
        case 10:
            set_window_update(6, 2);
            set_window_update(7, 2);
            set_window_update(8, 2);
            D_802AD604 = 11;
            return D_802AD605 + 1;
        case 11:
            return D_802AD605 + 1;
        case 20:
            set_window_update(6, 1);
            set_window_update(7, 1);
            set_window_update(8, 1);
            D_802AD604 = 1;
            return D_802AD605 + 1;
        case 30:
            set_window_update(6, 1);
            set_window_update(7, 1);
            set_window_update(8, 1);
            D_802AD604 = -1;
            break;
        case 40:
            D_802AD6D4 = -1;
            D_802AD604 = 41;
            return -1;
        case 41:
            set_window_update(6, 2);
            set_window_update(7, 2);
            set_window_update(8, 2);
            if (D_802AD610 == 0) {
                msgID = 0x1D0000;
                msgID |= 0xCB;
            } else {
                msgID = 0x1D0000;
                msgID |= 0xCC;
            }
            width = get_msg_width(msgID, 0) + 23;
            set_window_properties(9, (SCREEN_WIDTH / 2) - ((width) / 2), 80, width, 28, 0x14, func_802A57C8, NULL, -1);
            set_window_update(9, 1);
            D_802AD612 = 60;
            D_802AD604 = 42;
            return -1;
        case 42:
            if (gGameStatusPtr->pressedButtons[0] & (BUTTON_A | BUTTON_B)) {
                D_802AD612 = 0;
            }
            if (D_802AD612 != 0) {
                D_802AD612--;
                return -1;
            }
            set_window_update(9, 2);
            set_window_update(6, 1);
            set_window_update(7, 1);
            set_window_update(8, 1);
            D_802AD604 = 1;
            break;
    }
    return 0;
}
#else
INCLUDE_ASM(s32, "415D90", func_802A4A54);
#endif

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
            for (i = 0; i < D_802AD66C; i++, phi_s1 += 13) {
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
            for (i = 0; i < D_802AD66C; i++, phi_s1_2 += 13) {
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
    s32 a0;

    s32 x2;
    s32 y2;

    x2 = x + 11;
    y2 = y + 6;

    if (D_802AD610 == 0) {
        a0 = 0x1D0000;
        a0 |= 0xCB;
    } else {
        a0 = 0x1D0000;
        a0 |= 0xCC;
    }
    draw_msg(a0, x2, y2, 255, 15, 0);
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
        s32 playerCantMove = FALSE;

        if (player->koStatus == STATUS_DAZE) {
            playerCantMove = TRUE;
        }
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
    partnerCantMove = FALSE;

    if (partner->koStatus == STATUS_DAZE) {
        partnerCantMove = TRUE;
    }
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

            player->currentPos.z -= sin_rad(DEG_TO_RAD(player->state.angle)) * 16.0f;
            player->yaw = clamp_angle(-player->state.angle);
            partner->currentPos.z += sin_rad(DEG_TO_RAD(player->state.angle)) * 16.0f;
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
                btl_set_state(BATTLE_STATE_SELECT_TARGET);
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

// weird sub stuff
#ifdef NON_MATCHING
void btl_state_update_twink_menu(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    s32 temp_s0_2;
    s32 var_v0_2;
    s32 cond;
    s32 z;

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_0:
            cond = FALSE;
            if (player->debuff == STATUS_SLEEP) {
                cond = TRUE;
            }
            if (player->debuff == STATUS_FEAR) {
                cond = TRUE;
            }
            if (player->debuff == STATUS_DIZZY) {
                cond = TRUE;
            }
            if (player->debuff == STATUS_PARALYZE) {
                cond = TRUE;
            }
            if (player->debuff == STATUS_FROZEN) {
                cond = TRUE;
            }
            if (player->debuff == STATUS_STOP) {
                cond = TRUE;
            }
            if (player->stoneStatus == STATUS_STONE) {
                cond = TRUE;
            }
            if (player->koStatus == STATUS_DAZE) {
                cond = TRUE;
            }

            if (cond) {
                btl_set_state(BATTLE_STATE_END_PLAYER_TURN);
                break;
            }

            btl_cam_use_preset(BTL_CAM_PRESET_C);
            btl_cam_move(10);
            if (!(gBattleStatus.flags1 & BS_FLAGS1_100000)) {
                player->state.currentPos.x = player->homePos.x;
                player->state.currentPos.z = player->homePos.z;
                player->state.goalPos.x = partner->homePos.x;
                player->state.goalPos.z = partner->homePos.z;
                gBattleState2 = BATTLE_STATE2_PLAYER_DEFEATED;
                player->state.moveTime = 4;
                player->state.angle = 0.0f;
                break;
            }
            gBattleState2 = BATTLE_STATE2_UNK_B;
            break;
        case BATTLE_STATE2_PLAYER_DEFEATED:
            if (player->state.moveTime != 0) {
                player->currentPos.x += (player->state.goalPos.x - player->currentPos.x) / player->state.moveTime;
                player->currentPos.z += (player->state.goalPos.z - player->currentPos.z) / player->state.moveTime;
                partner->currentPos.x += (player->state.currentPos.x - partner->currentPos.x) / player->state.moveTime;
                partner->currentPos.z += (player->state.currentPos.z - partner->currentPos.z) / player->state.moveTime;
            }
            player->currentPos.z += sin_rad(DEG_TO_RAD(player->state.angle)) * 16.0f;
            player->yaw = clamp_angle(-player->state.angle);
            partner->currentPos.z -= sin_rad(DEG_TO_RAD(player->state.angle)) * 16.0f;
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
            gBattleStatus.flags1 |= BS_FLAGS1_100000;
        case BATTLE_STATE2_UNK_B:
            gBattleStatus.flags1 |= BS_FLAGS1_2;
            player->flags &= ~ACTOR_FLAG_4000000;
            player->flags |= ACTOR_FLAG_8000000;
            if (partner != NULL) {
                partner->flags |= ACTOR_FLAG_4000000;
                partner->flags |= ACTOR_FLAG_8000000;
            }
            battleStatus->selectedMoveID = MOVE_NONE;
            battle_menu_submenuIDs = 8;

            battle_menu_isEnabled = TRUE;
            battle_menu_isMessageDisabled = 0;
            main_battle_menu_JumpHudScripts = battle_menu_TwinkStarPowerHudScripts[0];
            *battle_menu_messageIDs = *D_802AB734;
            if (!(battleStatus->menuDisableFlags & 0x100)) {
                battle_menu_isEnabled = FALSE;
                battle_menu_isMessageDisabled = 0x48;
                main_battle_menu_JumpHudScripts = battle_menu_TwinkStarPowerHudScripts[1];
            }

            z = 0;
            if (func_802AA0A4() != 0) {
                D_802AD104 = 1;
                var_v0_2 = 2 - z;
            } else {
                D_802AD104 = 0;
                var_v0_2 = 2 - z;
            }
            main_menu_numOptions = 1;
            D_802AD0A8 = 0;
            D_802AD0B0 = 0;
            D_802AD100 = var_v0_2;

            func_802A1000();
            D_802ACC60 = 8;
            gBattleState2 = BATTLE_STATE2_UNK_1;
            break;
        case BATTLE_STATE2_UNK_1:
            set_animation(ACTOR_PARTNER, 0, 0x200001);
            temp_s0_2 = func_802A11B0();
            if (D_802ACC60 != 0) {
                D_802ACC60--;
                break;
            }
            if (temp_s0_2 != 0) {
                set_animation(ACTOR_PARTNER, 0, 0x200008);
                battleStatus->currentSubmenu = battle_menu_submenuIDs[temp_s0_2 - 1];
                func_802A1030();
                D_802ACC60 = 8;
                D_802ACC6C = 4;
                gBattleState2 = BATTLE_STATE2_UNK_2;
            }
            break;
        case BATTLE_STATE2_UNK_2:
            if (func_802A11B0() != 0) {
                battleStatus->unk_6C = 4;
                battleStatus->unk_6E = 5;
                battleStatus->moveCategory = 8;
                battleStatus->selectedMoveID = MOVE_TWINK_DASH;
                battleStatus->selectedItemID = ITEM_NONE;
                battleStatus->currentTargetListFlags = gMoveTable[MOVE_TWINK_DASH].flags;
                btl_set_state(BATTLE_STATE_SELECT_TARGET);
            }
            break;
        case BATTLE_STATE2_UNK_4:
            func_802A1050();
            gBattleState2 = BATTLE_STATE2_UNK_1;
            btl_state_update_twink_menu();
            btl_state_update_twink_menu();
            break;
        case BATTLE_STATE2_UNK_5:
            func_802A10B8();
            break;
        case BATTLE_STATE2_UNK_8:
            btl_show_variable_battle_message(0x50, 60, 0);
            D_802AD607 = 1;
            gBattleState2 = BATTLE_STATE2_UNK_9;
            break;
        case BATTLE_STATE2_UNK_9:
            if (!btl_is_popup_displayed()) {
                D_802AD607 = 0;
                D_802ACC60 = 0;
                gBattleState2 = BATTLE_STATE2_UNK_1;
            }
            break;
    }
}
#else
INCLUDE_ASM(s32, "415D90", btl_state_update_twink_menu); // look into m2c bug
#endif

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

void btl_state_update_select_target(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* actor;
    s32 targetListLength;
    s32 selectedTargetIndex;
    s32 id;
    s8* targetIndexList;
    SelectableTarget* target;
    s32 i;

    if (!(gBattleStatus.flags1 & BS_FLAGS1_80000)) {
        actor = battleStatus->playerActor;
    } else {
        actor = battleStatus->partnerActor;
    }
    targetListLength = actor->targetListLength;
    selectedTargetIndex = actor->selectedTargetIndex;

    actor->flags &= ~ACTOR_FLAG_8000000;
    targetIndexList = actor->targetIndexList;
    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_0:
            D_802ACC64 = 0xFF;
            D_802ACC68 = -100;
            gBattleStatus.flags1 &= ~BS_FLAGS1_2;
            if (!is_ability_active(ABILITY_BERSERKER) || (gBattleStatus.flags1 & BS_FLAGS1_80000)) {
                if (battleStatus->selectedMoveID != MOVE_NONE) {
                    s8 actionTip = gMoveTable[battleStatus->selectedMoveID].actionTip;

                    if (actionTip >= 0) {
                        btl_show_battle_message(actionTip + 0x2E, 60);
                    }
                }
            }
            player_create_target_list(actor);
            targetListLength = actor->targetListLength;
            if (battleStatus->currentTargetListFlags & 1) {
                targetIndexList = actor->targetIndexList;
                for (i = 0; i < targetListLength; i++) {
                    target = &actor->targetData[targetIndexList[i]];
                    if (get_actor_part(get_actor(target->actorID), target->partID)->flags & ACTOR_PART_FLAG_8) {
                        actor->selectedTargetIndex = i;
                        break;
                    }
                }
            }

            if (battleStatus->currentTargetListFlags & 0x80000000) {
                if (!(gBattleStatus.flags1 & BS_FLAGS1_80000)) {
                    gBattleState2 = battleStatus->unk_6E;
                    if (gBattleStatus.flags2 & BS_FLAGS2_40) {
                        btl_state_update_player_menu();
                    } else {
                        btl_state_update_player_menu();
                    }
                    btl_set_state(BATTLE_STATE_PLAYER_MOVE);
                } else {
                    gBattleState2 = battleStatus->unk_6E;
                    if (gBattleStatus.flags2 & BS_FLAGS2_40) {
                        btl_state_update_twink_menu();
                    } else {
                        btl_state_update_partner_menu();
                    }
                    btl_set_state(BATTLE_STATE_PARTNER_MOVE);
                }
                return;
            }

            if (targetListLength == 0) {
                if (!(gBattleStatus.flags1 & BS_FLAGS1_80000)) {
                    gBattleState2 = battleStatus->unk_6E;
                    if (gBattleStatus.flags2 & BS_FLAGS2_40) {
                        btl_state_update_player_menu();
                    } else {
                        btl_state_update_player_menu();
                    }
                    btl_set_state(BATTLE_STATE_PLAYER_MOVE);
                } else {
                    gBattleState2 = battleStatus->unk_6E;
                    if (gBattleStatus.flags2 & BS_FLAGS2_40) {
                        btl_state_update_twink_menu();
                    } else {
                        btl_state_update_partner_menu();
                    }
                    btl_set_state(BATTLE_STATE_PARTNER_MOVE);
                }
                return;
            }

            for (i = 0; i < targetListLength; i++) {
                id = hud_element_create(&HES_HandPointDownLoop);
                D_802ACC70[i] = id;
                hud_element_set_render_depth(id, 0);
                hud_element_set_render_pos(id, 0, -100);
            }
            gBattleState2 = BATTLE_STATE2_UNK_1;
            break;
        case BATTLE_STATE2_UNK_1:
            if (D_802ACC68 < 0) {
                D_802ACC68 += 20;
                if (D_802ACC68 > 0) {
                    D_802ACC68 = 0;
                }
            }

            if (battleStatus->currentButtonsPressed & BUTTON_B) {
                sfx_play_sound(SOUND_MENU_BACK);
                gBattleState2 = BATTLE_STATE2_PLAYER_DEFEATED;
                break;
            }

            if (battleStatus->currentButtonsPressed & BUTTON_A) {
                sfx_play_sound(SOUND_MENU_NEXT);
                D_802ACC60 = 8;
                D_802ACC6C = 4;
                gBattleState2 = BATTLE_STATE2_UNK_2;
                break;
            }

            gBattleStatus.flags1 |= BS_FLAGS1_2;
            if (battleStatus->currentButtonsDown & (BUTTON_Z | BUTTON_R)) {
                gBattleStatus.flags1 &= ~BS_FLAGS1_2;
                break;
            }

            if (battleStatus->currentTargetListFlags & 1) {
                s32 oldSelectedTargetIndex = selectedTargetIndex;

                if (battleStatus->currentButtonsHeld & BUTTON_STICK_LEFT) {
                    selectedTargetIndex--;
                }
                if (battleStatus->currentButtonsHeld & BUTTON_STICK_RIGHT) {
                    selectedTargetIndex++;
                }
                if (selectedTargetIndex < 0) {
                    selectedTargetIndex = targetListLength - 1;
                }
                if (selectedTargetIndex >= targetListLength) {
                    selectedTargetIndex = 0;
                }
                if (selectedTargetIndex != oldSelectedTargetIndex) {
                    s32 actorFlags;

                    target = &actor->targetData[targetIndexList[selectedTargetIndex]];
                    actorFlags = get_actor(target->actorID)->flags;
                    id = D_802ACC70[0];

                    if (actorFlags & ACTOR_FLAG_HP_OFFSET_BELOW) {
                        hud_element_set_script(id, &HES_HandPointLeftLoop);
                    } else {
                        hud_element_set_script(id, &HES_HandPointDownLoop);
                    }
                    sfx_play_sound(SOUND_MENU_CHANGE_SELECTION);
                }
                actor->selectedTargetIndex = selectedTargetIndex;
            }
            break;
        case BATTLE_STATE2_UNK_2:
            gBattleStatus.flags1 &= ~BS_FLAGS1_2;
            target = &actor->targetData[targetIndexList[actor->selectedTargetIndex]];
            actor->targetActorID = target->actorID;
            actor->targetPartIndex = target->partID;
            for (i = 0; i < targetListLength; i++) {
                hud_element_free(D_802ACC70[i]);
            }

            if (!(gBattleStatus.flags1 & BS_FLAGS1_80000)) {
                gBattleState2 = battleStatus->unk_6E;
                if (gBattleStatus.flags2 & BS_FLAGS2_40) {
                    btl_state_update_peach_menu();
                } else {
                    btl_state_update_player_menu();
                }
                btl_set_state(BATTLE_STATE_PLAYER_MOVE);
            } else {
                gBattleState2 = battleStatus->unk_6E;
                if (gBattleStatus.flags2 & BS_FLAGS2_40) {
                    btl_state_update_twink_menu();
                } else {
                    btl_state_update_partner_menu();
                }
                btl_set_state(BATTLE_STATE_PARTNER_MOVE);
            }
            break;
        case BATTLE_STATE2_PLAYER_DEFEATED:
            for (i = 0; i < targetListLength; i++) {
                hud_element_free(D_802ACC70[i]);
            }
            gBattleStatus.flags1 |= BS_FLAGS1_10000 | BS_FLAGS1_2;
            actor->flags |= ACTOR_FLAG_8000000;

            if (battleStatus->itemUsesLeft != 0) {
                btl_set_state(BATTLE_STATE_PLAYER_MENU);
                gBattleState2 = battleStatus->unk_6C;
                if (gBattleStatus.flags2 & BS_FLAGS2_40) {
                    btl_state_update_peach_menu();
                } else {
                    btl_state_update_player_menu();
                }
            } else if (!(gBattleStatus.flags1 & BS_FLAGS1_80000)) {
                btl_set_state(BATTLE_STATE_PLAYER_MENU);
                gBattleState2 = battleStatus->unk_6C;
                if (gBattleStatus.flags2 & BS_FLAGS2_40) {
                    btl_state_update_peach_menu();
                } else {
                    btl_state_update_player_menu();
                }
            } else {
                btl_set_state(BATTLE_STATE_PARTNER_MENU);
                gBattleState2 = battleStatus->unk_6C;
                if (gBattleStatus.flags2 & BS_FLAGS2_40) {
                    btl_state_update_twink_menu();
                } else {
                    btl_state_update_partner_menu();
                }
            }
            break;
    }
}

void btl_state_draw_select_target(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    s32 msgID;
    s32 msgX;
    s32 msgY;
    s32 targetListLength;
    s32 currentPartner;
    s32 actorID;
    SelectableTarget* target;
    Actor* actor;
    Actor* anotherActor;
    s32 id;
    s32 msgWidth;
    s32 xOffset, yOffset;
    f32 targetX, targetY, targetZ;
    s32 screenX, screenY, screenZ;
    s32 selectedTargetIndex;
    s8* targetIndexList;
    s32* tmpPtr; // TODO required to match and CURSED

    if (!(gBattleStatus.flags1 & BS_FLAGS1_80000)) {
        actor = battleStatus->playerActor;
    } else {
        actor = battleStatus->partnerActor;
    }

    targetListLength = actor->targetListLength;
    target = actor->targetData;
    selectedTargetIndex = actor->selectedTargetIndex;
    targetIndexList = actor->targetIndexList;

    tmpPtr = &D_802ACC68;

    if (targetListLength != 0) {
        if (battleStatus->currentTargetListFlags & 1) {
            target = &actor->targetData[targetIndexList[selectedTargetIndex]];
            anotherActor = get_actor(target->actorID);
            id = D_802ACC70[0];
            targetX = target->pos.x;
            targetY = target->pos.y;
            targetZ = target->pos.z;

            if (anotherActor->flags & ACTOR_FLAG_HP_OFFSET_BELOW) {
                xOffset = 16;
                yOffset = 2;
                if (hud_element_get_script(id) != &HES_HandPointLeftLoop) {
                    hud_element_set_script(id, &HES_HandPointLeftLoop);
                }
            } else {
                xOffset = 5;
                yOffset = -11;
                if (hud_element_get_script(id) != &HES_HandPointDownLoop) {
                    hud_element_set_script(id, &HES_HandPointDownLoop);
                }
            }

            get_screen_coords(1, targetX, targetY, targetZ, &screenX, &screenY, &screenZ);
            hud_element_set_render_pos(id, screenX + xOffset, screenY + yOffset);
            hud_element_set_alpha(id, D_802ACC64);
        } else {
            s32 i;

            for (i = 0; i < targetListLength; i++) {
                target = &actor->targetData[targetIndexList[i]];
                anotherActor = get_actor(target->actorID);
                id = D_802ACC70[i];
                targetX = target->pos.x;
                targetY = target->pos.y;
                targetZ = target->pos.z;
                if (anotherActor->flags & ACTOR_FLAG_HP_OFFSET_BELOW) {
                    xOffset = 16;
                    yOffset = 2;
                    if (hud_element_get_script(id) != &HES_HandPointLeftLoop) {
                        hud_element_set_script(id, &HES_HandPointLeftLoop);
                    }
                } else {
                    xOffset = 5;
                    yOffset = -11;
                    if (hud_element_get_script(id) != &HES_HandPointDownLoop) {
                        hud_element_set_script(id, &HES_HandPointDownLoop);
                    }
                }
                get_screen_coords(1, targetX, targetY, targetZ, &screenX, &screenY, &screenZ);
                hud_element_set_render_pos(id, screenX + xOffset, screenY + yOffset);
                hud_element_set_alpha(id, D_802ACC64);
            }
        }

        currentPartner = playerData->currentPartner;
        screenX = 52;
        screenY = 64;
        if (gBattleStatus.flags2 & BS_FLAGS2_40) {
            currentPartner = PARTNER_TWINK;
        }

        if ((battleStatus->currentTargetListFlags & 1) || targetListLength == 1) {
            actorID = target->actorID;
            if (actorID == ACTOR_PLAYER) {
                msgWidth = get_msg_width(0x1D00C4, 0) + 10;
            } else if (actorID == ACTOR_PARTNER) {
                msgWidth = get_msg_width(D_802AB738[currentPartner], 0) + 10;
            } else {
                target = &actor->targetData[targetIndexList[selectedTargetIndex]];
                anotherActor = get_actor(target->actorID);
                msgID = get_actor_part(anotherActor, target->partID)->staticData->unk_20;
                if (msgID == 0) {
                    msgID = bActorNames[anotherActor->actorType];
                }
                msgWidth = get_msg_width(msgID, 0) + 10;
            }
        } else {
            target = &actor->targetData[targetIndexList[selectedTargetIndex]];
            actorID = target->actorID;
            if (actorID == ACTOR_PLAYER) {
                msgWidth = get_msg_width(0x1D00C4, 0) + 10;
            } else if (actorID == ACTOR_PARTNER) {
                msgWidth = get_msg_width(D_802AB738[currentPartner], 0) + 10;
            } else {
                msgWidth = get_msg_width(0x1D00C5, 0) + 10;
            }
        }

        draw_box(0, 4, screenX + D_802ACC68, screenY, 0, msgWidth, 20, 255, 0,
                 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL, SCREEN_WIDTH, SCREEN_HEIGHT, NULL);

        screenX += 4;
        screenY += 2;
        if ((battleStatus->currentTargetListFlags & 1) || targetListLength == 1) {
            actorID = target->actorID;
            if (actorID == ACTOR_PLAYER) {
                draw_msg(0x1D00C4, screenX + D_802ACC68, screenY, 255, 0x36, 0);
            } else if (actorID == ACTOR_PARTNER) {
                draw_msg(D_802AB738[currentPartner], screenX + D_802ACC68, screenY, 255, 0x36, 0);
            } else {
                target = &actor->targetData[targetIndexList[selectedTargetIndex]];
                anotherActor = get_actor(target->actorID);
                msgID = get_actor_part(anotherActor, target->partID)->staticData->unk_20;
                if (msgID == 0) {
                    msgID = bActorNames[anotherActor->actorType];
                }
                draw_msg(msgID, screenX + *tmpPtr, screenY, 255, 0x36, 0); // TODO required to match
            }
        } else {
            target = &actor->targetData[targetIndexList[selectedTargetIndex]];
            actorID = target->actorID;
            if (actorID == ACTOR_PLAYER) {
                draw_msg(0x1D00C4, screenX + D_802ACC68, screenY, 255, 0x36, 0);
            } else if (actorID == ACTOR_PARTNER) {
                draw_msg(D_802AB738[currentPartner], screenX + D_802ACC68, screenY, 255, 0x36, 0);
            } else {
                draw_msg(0x1D00C5, screenX + D_802ACC68, screenY, 255, 0x36, 0);
            }
        }
    }
}

void btl_state_update_22(void) {
}

void btl_state_draw_22(void) {
}
