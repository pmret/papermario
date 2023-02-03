#include "common.h"
#include "battle/battle.h"
#include "hud_element.h"
#include "battle/action_cmd.h"

#include "sprite/npc/Goompa.h"
#include "sprite/npc/BattleGoombario.h"
#include "sprite/npc/BattleKooper.h"
#include "sprite/npc/BattleBombette.h"
#include "sprite/npc/BattleParakarry.h"
#include "sprite/npc/BattleBow.h"
#include "sprite/npc/BattleWatt.h"
#include "sprite/npc/BattleSushie.h"
#include "sprite/npc/BattleLakilester.h"
#include "sprite/npc/Twink.h"

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
extern HudScript HES_MoveDiamondDisabled;
extern HudScript HES_MoveBlueOrb;
extern HudScript HES_MoveBlueOrbDisabled;
extern HudScript HES_MoveGreenOrb;
extern HudScript HES_MoveGreenOrbDisabled;
extern HudScript HES_MoveRedOrb;
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

extern IconHudScriptPair gItemHudScripts[];

s16 D_802AB340[] = { 28, 40 };

s16 D_802AB344[] = { 0, -2 };

IconHudScriptPair battle_menu_JumpHudScripts[] = {
    { &HES_MenuBoots1Disabled, &HES_MenuBoots1Disabled },
    { &HES_MenuBoots1, &HES_MenuBoots1Disabled },
    { &HES_MenuBoots2, &HES_MenuBoots2Disabled },
    { &HES_MenuBoots3, &HES_MenuBoots3Disabled },
};

IconHudScriptPair battle_menu_HammerHudScripts[] = {
    { &HES_MenuHammer1Disabled, &HES_MenuHammer1Disabled },
    { &HES_MenuHammer1, &HES_MenuHammer1Disabled },
    { &HES_MenuHammer2, &HES_MenuHammer2Disabled },
    { &HES_MenuHammer3, &HES_MenuHammer3Disabled  },
};

IconHudScriptPair battle_menu_ItemHudScripts = { &HES_MenuItem, &HES_MenuItemDisabled };

IconHudScriptPair battle_menu_StarPowerHudScripts = { &HES_MenuStarPower, &HES_MenuStarPowerDisabled };

//TODO retype to IconHudScriptPair[]
HudScript* battle_menu_StarPowerMovesHudScripts[] = {
    &HES_MenuStarPower, &HES_MenuStarPowerDisabled,
    &HES_Eldstar, &HES_EldstarDisabled,
    &HES_Mamar, &HES_MamarDisabled,
    &HES_Skolar, &HES_SkolarDisabled,
    &HES_Muskular, &HES_MuskularDisabled,
    &HES_Misstar, &HES_MisstarDisabled,
    &HES_Klevar, &HES_KlevarDisabled,
    &HES_Kalmar, &HES_KalmarDisabled,
    &HES_StarBeam, &HES_StarBeamDisabled,
    &HES_PeachBeam, &HES_PeachBeamDisabled,
    &HES_MenuStarPower, &HES_MenuStarPowerDisabled,
    &HES_MenuStarPower, &HES_MenuStarPowerDisabled,
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

IconHudScriptPair battle_menu_StrategiesHudScript = { &HES_MenuStrategies, &HES_MenuStrategiesDisabled };

IconHudScriptPair battle_menu_DoNothingHudScripts = { &HES_MenuDoNothing, &HES_MenuDoNothingDisabled };

IconHudScriptPair battle_menu_FleeHudScripts = { &HES_MenuFlee, &HES_MenuFleeDisabled };

s32 BattleMenu_LeftJustMessages[] = {
    MSG_Menus_Jump,
    MSG_Menus_Hammer,
    MSG_Menus_Items,
    MSG_Menus_RunAway,
    MSG_Menus_Defense,
    MSG_Menus_ChangeMember,
    MSG_Menus_Abilities,
    MSG_Menus_Strategies,
    MSG_Menus_StarSpirits,
    MSG_Menus_DoNothing,
    MSG_Menus_ActLater,
    MSG_Menus_Focus,
};

s32 BattleMenu_CenteredMessages[] = {
    MSG_Menus_Jump_Centered,
    MSG_Menus_Hammer_Centered,
    MSG_Menus_Items_Centered,
    MSG_Menus_RunAway_Centered,
    MSG_Menus_Defense_Centered,
    MSG_Menus_ChangeMember_Centered,
    MSG_Menus_Abilities_Centered,
    MSG_Menus_Strategies_Centered,
    MSG_Menus_StarSpirits_Centered,
    MSG_Menus_DoNothing_Centered,
    MSG_Menus_ActLater_Centered,
    MSG_Menus_Focus_Centered,
};

s32 D_802AB4F0[] = {
    [BTL_MENU_TYPE_JUMP]            MOVE_TYPE_JUMP,
    [BTL_MENU_TYPE_SMASH]           MOVE_TYPE_HAMMER,
    [BTL_MENU_TYPE_ITEMS]           MOVE_TYPE_ITEMS,
    [BTL_MENU_TYPE_RUN_AWAY]        MOVE_TYPE_6,
    [BTL_MENU_TYPE_DEFEND]          MOVE_TYPE_3,
    [BTL_MENU_TYPE_CHANGE_PARTNER]  MOVE_TYPE_SWITCH,
    [BTL_MENU_TYPE_ABILITY]         0x1A,
    [BTL_MENU_TYPE_STRATEGIES]      MOVE_TYPE_3,
    [BTL_MENU_TYPE_STAR_POWERS]     0x34,
    [BTL_MENU_TYPE_DO_NOTHING]      0x39,
    [BTL_MENU_TYPE_ACT_LATER]       0x31,
    [BTL_MENU_TYPE_PARTNER_FOCUS]   0x37
};

AnimID BattleMenu_PartnerThinkAnims[] = {
    [PARTNER_GOOMBARIO]  ANIM_BattleGoombario_Think,
    [PARTNER_KOOPER]     ANIM_BattleKooper_Think,
    [PARTNER_BOMBETTE]   ANIM_BattleBombette_Think,
    [PARTNER_PARAKARRY]  ANIM_BattleParakarry_Think,
    [PARTNER_GOOMPA]     ANIM_Goompa_Idle,
    [PARTNER_WATT]       ANIM_BattleWatt_Think,
    [PARTNER_SUSHIE]     ANIM_BattleSushie_Think,
    [PARTNER_LAKILESTER] ANIM_BattleLakilester_Run,
    [PARTNER_BOW]        ANIM_BattleBow_Still,
    [PARTNER_GOOMBARIA]  0,
    [PARTNER_TWINK]      0,
    0x00000000,
    0x00000000
};

AnimID BattleMenu_PartnerIdleAnims[] = {
    [PARTNER_GOOMBARIO]  ANIM_BattleGoombario_Walk,
    [PARTNER_KOOPER]     ANIM_BattleKooper_Walk,
    [PARTNER_BOMBETTE]   ANIM_BattleBombette_Walk,
    [PARTNER_PARAKARRY]  ANIM_BattleParakarry_Walk,
    [PARTNER_GOOMPA]     ANIM_Goompa_Walk,
    [PARTNER_WATT]       ANIM_BattleWatt_Walk,
    [PARTNER_SUSHIE]     ANIM_BattleSushie_Walk,
    [PARTNER_LAKILESTER] ANIM_BattleLakilester_Walk,
    [PARTNER_BOW]        ANIM_BattleBow_Walk,
    [PARTNER_GOOMBARIA]  0,
    [PARTNER_TWINK]      0,
    0x00000000,
    0x00000000
};

HudScript* battle_menu_PartnerMoveHudScripts[10][10] = {
    [PARTNER_GOOMBARIO]  { &HES_Goombario, &HES_GoombarioDisabled, &HES_MoveDiamond, &HES_MoveDiamondDisabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled, },
    [PARTNER_KOOPER]     { &HES_Kooper, &HES_KooperDisabled, &HES_MoveDiamond, &HES_MoveDiamondDisabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled, },
    [PARTNER_BOMBETTE]   { &HES_Bombette, &HES_BombetteDisabled, &HES_MoveDiamond, &HES_MoveDiamondDisabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled, },
    [PARTNER_PARAKARRY]  { &HES_Parakarry, &HES_ParakarryDisabled, &HES_MoveDiamond, &HES_MoveDiamondDisabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled, },
    [PARTNER_GOOMPA]     { &HES_Partner0, &HES_Partner0Disabled, &HES_MoveDiamond, &HES_MoveDiamondDisabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled, },
    [PARTNER_WATT]       { &HES_Watt, &HES_WattDisabled, &HES_MoveDiamond, &HES_MoveDiamondDisabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled, },
    [PARTNER_SUSHIE]     { &HES_Sushie, &HES_SushieDisabled, &HES_MoveDiamond, &HES_MoveDiamondDisabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled, },
    [PARTNER_LAKILESTER] { &HES_Lakilester, &HES_LakilesterDisabled, &HES_MoveDiamond, &HES_MoveDiamondDisabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled, },
    [PARTNER_BOW]        { &HES_Bow, &HES_BowDisabled, &HES_MoveDiamond, &HES_MoveDiamondDisabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled },
};

IconHudScriptPair battle_menu_PeachStarPowerHudScripts = { &HES_MenuStarPower, &HES_MenuStarPowerDisabled };

s32 D_802AB728[] = {
    MSG_Menus_Focus_Centered,
};

IconHudScriptPair battle_menu_TwinkStarPowerHudScripts = { &HES_MenuStarPower, &HES_MenuStarPowerDisabled };

s32 D_802AB734[] = {
    MSG_Menus_Dash_Centered,
};

s32 PartnerNameMessages[] = {
    0x00000000,
    MSG_Menus_Party_Goombario,
    MSG_Menus_Party_Kooper,
    MSG_Menus_Party_Bombette,
    MSG_Menus_Party_Parakarry,
    MSG_Menus_Party_Goompa,
    MSG_Menus_Party_Watt,
    MSG_Menus_Party_Sushie,
    MSG_Menus_Party_Lakilester,
    MSG_Menus_Party_Bow,
    MSG_Menus_Party_Goombaria,
    MSG_Menus_Party_Twink,
    MSG_Menus_Party_Peach,
    0x00000000
};

BSS s32 D_802ACC60;
BSS s32 D_802ACC64;
BSS s32 D_802ACC68;
BSS s32 D_802ACC6C;
BSS s32 D_802ACC70[24];
BSS PopupMenu D_802ACCD0;
BSS s8 BattleMenuState;
BSS s8 D_802AD001;
BSS s8 BattleMenu_CurPos;
BSS s8 BattleMenu_PrevPos;
BSS s8 D_802AD004;
BSS s16 D_802AD006;
BSS s16 BattleMenuAlpha;
BSS s16 D_802AD00A;
BSS s16 D_802AD00C; // unused?
BSS s32 D_802AD010[6];
BSS s32 D_802AD028[6];
BSS s32 D_802AD040;
BSS s32 D_802AD044;
BSS s32 D_802AD048;
BSS s32 D_802AD04C;
BSS s32 D_802AD050;
BSS s32 D_802AD054;
BSS s32 D_802AD058;
BSS s32 D_802AD05C;
BSS s32 BattleMenu_BasePosX;
BSS s32 BattleMenu_BasePosY;
BSS s8 BattleMenuDisableMsg;
BSS s8 BattleMenu_MinIdx;
BSS s8 BattleMenu_MaxIdx;
BSS s8 BattleMenu_HomePos;
BSS f32 BattleMenu_WheelAngle;
BSS f32 D_802AD070;
BSS s32 D_802AD074; // unused?
BSS HudScript* BattleMenu_HudScripts[6];
BSS s32 BattleMenu_TitleMessages[6];
BSS s32 D_802AD0A8;
BSS s32 BattleMenu_NumOptions;
BSS s32 D_802AD0B0;
BSS s32 D_802AD0B4; // unused?
BSS s32 battle_menu_submenuIDs[6];
BSS s32 BattleMenu_OptionEnabled[6];
BSS s32 battle_menu_isMessageDisabled[6];
BSS s32 D_802AD100;
BSS s32 BattleMenu_ShowSwapIcons;
BSS s8 battle_menu_moveState;
BSS s8 battle_menu_moveCursorPos;
BSS s8 D_802AD10A;
BSS s8 D_802AD10B;
BSS s8 battle_menu_moveScrollLine;
BSS s8 D_802AD10D;
BSS s8 D_802AD10E;
BSS s8 D_802AD10F;
BSS s16 battle_menu_moveScrollOffset;
BSS s16 D_802AD112;
BSS s16 BattleMenu_Moves_TextColor;
BSS s16 BattleMenu_Moves_TextAlpha;
BSS HudElemID BattleMenu_Moves_CursorID;
BSS HudElemID BattleMenu_Moves_UpArrowID;
BSS HudElemID BattleMenu_Moves_DownArrowID;
BSS s32 D_802AD124; // unused?
BSS HudElemID BattleMenu_Moves_OptionIDs[24];
BSS HudElemID BattleMenu_Moves_TitleID;
BSS s32 D_802AD18C; // unused?
BSS HudElemID BattleMenu_Moves_OptionCostUnitIDs[24];
BSS s16 BattleMenu_Moves_PosX;
BSS s16 BattleMenu_Moves_PosY;
BSS s32 D_802AD1F4; // unused?
BSS s32 BattleMenu_Moves_OptionIndexMap[24];
BSS s32 D_802AD258;
BSS s32 D_802AD25C; // unused?
BSS HudScript* battle_menu_moveOptionIconScripts[24];
BSS s32 battle_menu_moveOptionNames[24];
BSS s32 battle_menu_moveOptionDisplayCosts[24];
BSS s32 battle_menu_moveOptionDisplayCostReductions[24];
BSS s32 battle_menu_moveOptionDisplayCostReductionColors[24];
BSS s32 battle_menu_moveOptionBPCosts[24];
BSS s32 BattleMenu_UsingSpiritsSubmenu;
BSS s32 BattleMenu_Moves_OptionCount;
BSS s32 D_802AD4A8;
BSS s32 D_802AD4AC; // unused?
BSS s32 BattleMenu_Moves_OptionIndices[24];
BSS s32 BattleMenu_Moves_OptionEnabled[24];
BSS s32 BattleMenu_Moves_OptionDescMessages[24];
BSS s8 BattleMenu_Moves_OptionSortPriority[24];
BSS s8 BattleMenu_Moves_OptionCantUseMessages[24];
BSS s32 battle_menu_moveOptionActive;
BSS s8 BattleSubmenuStratsState;
BSS s8 D_802AD605;
BSS s8 D_802AD606;
BSS s8 D_802AD607;
BSS s8 D_802AD608;
BSS s8 D_802AD609;
BSS s8 D_802AD60A;
BSS s8 D_802AD60B;
BSS s16 D_802AD60C;
BSS s16 D_802AD60E;
BSS s16 D_802AD610;
BSS s16 D_802AD612;
BSS s8 D_802AD614;
BSS s32 D_802AD618;
BSS HudElemID GreenArrowUpID;
BSS HudElemID GreenArrowDownID;
BSS s32 D_802AD624;
BSS s32 D_802AD628[5];
BSS s16 D_802AD63C;
BSS s16 D_802AD63E;
BSS HudScript* D_802AD640[6];
BSS s32 D_802AD658[5]; // msg IDs
BSS s32 D_802AD66C;
BSS s32 D_802AD670;

//TODO remove it in func_802A45D8 and use D_802AD670 instead
extern s8 D_802AD673;

BSS s32 D_802AD674; // unused?
BSS s32 D_802AD678[6];
BSS s32 D_802AD690[6];
BSS s32 D_802AD6A8[6];
BSS s32 D_802AD6C0[5];
BSS s32 D_802AD6D4;

void func_800F513C(PopupMenu* popup);

s32 func_80265D44(s32 animID);
void func_802A3C98(void* data, s32 x, s32 y);
void func_802A43DC(void* data, s32 x, s32 y);
void func_802A4448(void* data, s32 x, s32 y);
void func_802A4494(void* data, s32 x, s32 y);
void func_802A4534(void* data, s32 x, s32 y);
void func_802A5290(void* data, s32 x, s32 y);
void func_802A56F8(void* data, s32 x, s32 y);
void func_802A5738(void* data, s32 x, s32 y);
void func_802A57C8(void* data, s32 x, s32 y);

void func_80263300(void);
void func_80263268(void);
void btl_init_menu_partner(void);
void func_800F52BC(void);
void func_800F16CC(void);

void btl_main_menu_init(void) {
    D_802AD006 = 255;
    BattleMenuAlpha = 255;
    BattleMenuState = BTL_MENU_STATE_CREATE;
    BattleMenuDisableMsg = -1;
}

// btl_main_menu_hide? (after begin targeting)
void func_802A1030(void) {
    D_802AD001 = 3;
    BattleMenuState = BTL_MENU_STATE_UNK_A;
}

// (after submenu closed/cancelled)
void func_802A1050(void) {
    BattleMenuState = BTL_MENU_STATE_ACCEPT_INPUT;
    D_802AD006 = 255;
    BattleMenuAlpha = 255;
}
