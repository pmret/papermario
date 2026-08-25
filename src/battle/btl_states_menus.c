#include "battle/battle.h"
#include "hud_element.h"
#include "battle/action_cmd.h"
#include "sprite/player.h"

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
extern HudScript HES_MoveDiamond_disabled;
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
#if VERSION_PAL
extern HudScript HES_FPCost_de;
extern HudScript HES_FPCost_fr;
extern HudScript HES_FPCost_es;
extern HudScript HES_FPCostReduced_de;
extern HudScript HES_FPCostReduced_fr;
extern HudScript HES_FPCostReduced_es;
extern HudScript HES_FPCostReducedTwice_de;
extern HudScript HES_FPCostReducedTwice_fr;
extern HudScript HES_FPCostReducedTwice_es;
extern HudScript HES_POWCost_de;
extern HudScript HES_POWCost_fr;
extern HudScript HES_POWCost_es;
extern HudScript HES_POWCostReduced_de;
extern HudScript HES_POWCostReduced_fr;
extern HudScript HES_POWCostReduced_es;
extern HudScript HES_POWCostReducedTwice_de;
extern HudScript HES_POWCostReducedTwice_fr;
extern HudScript HES_POWCostReducedTwice_es;
extern HudScript HES_NotEnoughFP_de;
extern HudScript HES_NotEnoughFP_fr;
extern HudScript HES_NotEnoughFP_es;
extern HudScript HES_NotEnoughPOW_de;
extern HudScript HES_NotEnoughPOW_fr;
extern HudScript HES_NotEnoughPOW_es;
#endif
extern HudScript HES_ProjectorBeam;
extern HudScript HES_ProjectorReel;
extern HudScript HES_ProjectorSpot;
extern HudScript HES_SwapArrowLeft;
extern HudScript HES_SwapArrowRight;
extern HudScript HES_SwapBackground;
extern HudScript HES_SwapZ;

extern IconHudScriptPair gItemHudScripts[];

#if !VERSION_JP
s16 ErrorMessageHeight[] = { 28, 40 };

s16 ErrorMessageAdjustY[] = { 0, -2 };
#endif

#if VERSION_PAL
u8 D_PAL_802AB4C8[] = { 144, 158, 148, 144 };
u8 D_PAL_802AB4CC[] = { 144, 160, 160, 160 };
u8 D_PAL_802AB4D0[] = { 0, 20, 20, 20 };
u8 D_PAL_802AB4D4[] = { 0, 16, 16, 16 };
u8 D_PAL_802AB4D8[] = { 8, 24, 8, 16 };
u8 D_PAL_802AB4DC[] = { 100, 81, 116, 98 };
u8 D_PAL_802AB4E0[] = { 5, 16, 8, 16 };
u8 D_PAL_802AB4E4[] = { 156, 158, 158, 158 };
u8 D_PAL_802AB4E8[] = { 4, 6, 6, 6 };
u8 D_PAL_802AB4EC[] = { 18, 14, 18, 14 };
u8 D_PAL_802AB4F0[] = { 89, 101, 90, 101 };
u8 D_PAL_802AB4F4[] = { 16, 10, 14, 10 };
u8 D_PAL_802AB4F8[] = { 0, 2, 2, 2 };

HudScript* D_PAL_802AB4FC[][4] = {
    { &HES_FPCost, &HES_FPCost_de, &HES_FPCost_fr, &HES_FPCost_es },
    { &HES_FPCostReduced, &HES_FPCostReduced_de, &HES_FPCostReduced_fr, &HES_FPCostReduced_es },
    { &HES_FPCostReducedTwice, &HES_FPCostReducedTwice_de, &HES_FPCostReducedTwice_fr, &HES_FPCostReducedTwice_es },
};

HudScript* D_PAL_802AB52C[] = { &HES_NotEnoughFP, &HES_NotEnoughFP_de, &HES_NotEnoughFP_fr, &HES_NotEnoughFP_es };

HudScript* D_PAL_802AB53C[][4] = {
    { &HES_POWCost, &HES_POWCost_de, &HES_POWCost_fr, &HES_POWCost_es },
    { &HES_POWCostReduced, &HES_POWCostReduced_de, &HES_POWCostReduced_fr, &HES_POWCostReduced_es },
    { &HES_POWCostReducedTwice, &HES_POWCostReducedTwice_de, &HES_POWCostReducedTwice_fr, &HES_POWCostReducedTwice_es },
};

HudScript* D_PAL_802AB56C[] = { &HES_NotEnoughPOW, &HES_NotEnoughPOW_de, &HES_NotEnoughPOW_fr, &HES_NotEnoughPOW_es };
#endif

IconHudScriptPair BootsHudScripts[] = {
    { &HES_MenuBoots1Disabled, &HES_MenuBoots1Disabled },
    { &HES_MenuBoots1, &HES_MenuBoots1Disabled },
    { &HES_MenuBoots2, &HES_MenuBoots2Disabled },
    { &HES_MenuBoots3, &HES_MenuBoots3Disabled },
};

IconHudScriptPair HammerHudScripts[] = {
    { &HES_MenuHammer1Disabled, &HES_MenuHammer1Disabled },
    { &HES_MenuHammer1, &HES_MenuHammer1Disabled },
    { &HES_MenuHammer2, &HES_MenuHammer2Disabled },
    { &HES_MenuHammer3, &HES_MenuHammer3Disabled  },
};

IconHudScriptPair ItemsHudScripts = { &HES_MenuItem, &HES_MenuItemDisabled };

IconHudScriptPair StarPowersHudScripts = { &HES_MenuStarPower, &HES_MenuStarPowerDisabled };

//TODO retype to IconHudScriptPair[]
HudScript* StarPowerMovesHudScripts[] = {
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

HudScript* PartnerHudScripts[] = {
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

IconHudScriptPair StrategiesHudScripts = { &HES_MenuStrategies, &HES_MenuStrategiesDisabled };

IconHudScriptPair DoNothingHudScripts = { &HES_MenuDoNothing, &HES_MenuDoNothingDisabled };

IconHudScriptPair FleeHudScripts = { &HES_MenuFlee, &HES_MenuFleeDisabled };

#if VERSION_JP
IconHudScriptPair battle_menu_PouchHudScripts = { &HES_MenuPouch, &HES_MenuPouchDisabled };
#endif

s32 LeftJustMenuMessages[] = {
#if VERSION_JP
    MSG_Menus_JP_0049,
    MSG_Menus_JP_0048,
    MSG_Menus_JP_004F,
#else
    MSG_Menus_Jump,
    MSG_Menus_Hammer,
    MSG_Menus_Items,
#endif
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

s32 CenteredBattleMessages[] = {
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

s32 BattleMenu_CategoryForSubmenu[] = {
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

AnimID PartnerThinkAnims[] = {
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

AnimID PartnerIdleAnims[] = {
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

HudScript* PartnerMoveHudScripts[10][10] = {
    [PARTNER_GOOMBARIO]  { &HES_Goombario, &HES_GoombarioDisabled, &HES_MoveDiamond, &HES_MoveDiamond_disabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled },
    [PARTNER_KOOPER]     { &HES_Kooper, &HES_KooperDisabled, &HES_MoveDiamond, &HES_MoveDiamond_disabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled },
    [PARTNER_BOMBETTE]   { &HES_Bombette, &HES_BombetteDisabled, &HES_MoveDiamond, &HES_MoveDiamond_disabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled },
    [PARTNER_PARAKARRY]  { &HES_Parakarry, &HES_ParakarryDisabled, &HES_MoveDiamond, &HES_MoveDiamond_disabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled },
    [PARTNER_GOOMPA]     { &HES_Partner0, &HES_Partner0Disabled, &HES_MoveDiamond, &HES_MoveDiamond_disabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled },
    [PARTNER_WATT]       { &HES_Watt, &HES_WattDisabled, &HES_MoveDiamond, &HES_MoveDiamond_disabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled },
    [PARTNER_SUSHIE]     { &HES_Sushie, &HES_SushieDisabled, &HES_MoveDiamond, &HES_MoveDiamond_disabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled },
    [PARTNER_LAKILESTER] { &HES_Lakilester, &HES_LakilesterDisabled, &HES_MoveDiamond, &HES_MoveDiamond_disabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled },
    [PARTNER_BOW]        { &HES_Bow, &HES_BowDisabled, &HES_MoveDiamond, &HES_MoveDiamond_disabled, &HES_MoveBlueOrb, &HES_MoveBlueOrbDisabled, &HES_MoveGreenOrb, &HES_MoveGreenOrbDisabled, &HES_MoveRedOrb, &HES_MoveRedOrbDisabled },
};

IconHudScriptPair PeachStarPowerHudScripts = { &HES_MenuStarPower, &HES_MenuStarPowerDisabled };

s32 PeachMenuMessages[] = {
    MSG_Menus_Focus_Centered,
};

IconHudScriptPair TwinkStarPowerHudScripts = { &HES_MenuStarPower, &HES_MenuStarPowerDisabled };

s32 TwinkMenuMessages[] = {
    MSG_Menus_Dash_Centered,
};

s32 PartnerNameMessages[] = {
    MSG_NONE,
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
#if !VERSION_PAL
    MSG_NONE
#endif
};

BSS s32 BattleMenu_ChooseDelay;
BSS s32 BattleMenu_TargetPointerAlpha;
BSS s32 BattleMenu_TargetNameOffsetX; // used to animate the position of the target name box
BSS s32 BattleMenu_SwapDelay; // delay before the player and partner can swap after the main menu is opened
BSS s32 BattleMenu_TargetHudElems[MAX_ENEMY_ACTORS];
BSS PopupMenu BattlePopupMenu;
BSS s8 BattleMenuState;
BSS s8 BattleMenu_ReelAppearTimer;
BSS s8 BattleMenu_CurPos;
BSS s8 BattleMenu_PrevPos;
BSS s8 BattleMenu_WheelMoving;
BSS s16 BattleMenu_ReelAlpha;
BSS s16 BattleMenuAlpha;
BSS s16 BattleMenu_ReelHidePercent;
#if !VERSION_IQUE && !VERSION_PAL
BSS s16 D_802AD00C; // unused?
#endif
BSS s32 HID_OptionIcons[6];
BSS s32 HID_Spotlights[6];
BSS s32 HID_HighlightSpot;
BSS s32 HID_ProjectorReelA;
BSS s32 HID_ProjectorReelB;
BSS s32 HID_ProjectorBeam;
BSS s32 HID_SwapZ;
BSS s32 HID_SwapArrowLeft;
BSS s32 HID_SwapArrowRight;
BSS s32 HID_SwapBackground;
BSS s32 BattleMenu_BasePosX;
BSS s32 BattleMenu_BasePosY;
BSS s8 BattleMenu_ErrorCode;
BSS s8 BattleMenu_MinIdx;
BSS s8 BattleMenu_MaxIdx;
BSS s8 BattleMenu_HomePos;
BSS f32 BattleMenu_WheelAngle;
BSS f32 BattleMenu_WheelSpeed;
#if !VERSION_IQUE
BSS s32 D_802AD074; // unused?
#endif
BSS HudScript* WheelOptionHudScript[6];
BSS s32 WheelOptionName[6];
BSS s32 D_802AD0A8;
BSS s32 WheelOptionCount;
BSS s32 BattleMenu_PrevSelected;
#if !VERSION_IQUE
BSS s32 D_802AD0B4; // unused?
#endif
BSS s32 WheelOptionSubmenu[6];
BSS s32 WheelOptionEnabled[6];
BSS s32 WheelOptionError[6];
BSS s32 BattleMenu_WheelBase;
BSS s32 BattleMenu_ShowSwapIcons;
BSS s8 MovesMenuState;
BSS s8 MovesCursorPos;
BSS s8 MovesPrevCursorPos;
BSS s8 MovesErrorTimer;
BSS s8 MovesVisibleStart;
BSS s8 MovesVisibleEnd;
BSS s8 MovesMenuLines;
BSS s8 MovesDescVisible;
BSS s16 MovesScrollOffset;
BSS s16 MovesCursorOffset;
BSS s16 MovesTextColor;
BSS s16 MovesTextAlpha;
BSS HudElemID HID_MovesCursor;
BSS HudElemID HID_MovesArrowUp;
BSS HudElemID HID_MovesArrowDown;
#if !VERSION_IQUE
BSS s32 D_802AD124; // unused?
#endif
BSS HudElemID MovesOptionHIDs[24];
BSS HudElemID HID_MovesTitle;
#if !VERSION_IQUE
BSS s32 D_802AD18C; // unused?
#endif
BSS HudElemID MovesOptionCostHIDs[24];
BSS s16 MovesMenuPosX;
BSS s16 MovesMenuPosY;
#if !VERSION_IQUE
BSS s32 D_802AD1F4; // unused?
#endif
BSS s32 MovesOptionIndexMap[24];
BSS s32 MovesErrorCode;
#if !VERSION_IQUE
BSS s32 D_802AD25C; // unused?
#endif
BSS HudScript* MovesOptionHudScripts[24];
BSS s32 MovesOptionNames[24];
BSS s32 MovesOptionDisplayCosts[24];
BSS s32 MovesOptionDiscounts[24];
BSS s32 MovesOptionDiscountColors[24];
BSS s32 MovesOptionBPCosts[24];
BSS s32 UsingSpiritsSubmenu;
BSS s32 MovesOptionCount;
BSS s32 MovesPrevSelected;
#if !VERSION_IQUE
BSS s32 D_802AD4AC; // unused?
#endif
BSS s32 MovesOptionIndices[24];
BSS s32 MovesOptionEnabled[24];
BSS s32 MovesOptionDesc[24];
BSS s8 MovesOptionSortPriority[24];
BSS s8 MovesOptionError[24];
BSS s32 SelectedMovesIndex;
BSS s8 StratsMenuState;
BSS s8 StratsCursorPos;
BSS s8 StratsPrevCursorPos;
BSS s8 ShowingErrorMessage;
BSS s8 StratsVisibleStart;
BSS s8 StratsVisibleEnd;
BSS s8 StratsMenuLines;
BSS s8 StratsDescVisible;
BSS s16 StratsScrollOffset;
BSS s16 StratsCursorOffset;
BSS s16 StratsErrorCode;
BSS s16 StratsErrorTimer;
BSS s8 StratsTextColor;
BSS s32 HID_StratsCursor;
BSS HudElemID HID_StratsArrowUp;
BSS HudElemID HID_StratsArrowDown;
BSS s32 StratsTextAlpha;

#if VERSION_IQUE
#define TABMAX 5
#else
#define TABMAX 6
#endif

BSS s32 StratsOptionHIDs[5];
BSS s16 StratsMenuPosX;
BSS s16 StratsMenuPosY;
BSS HudScript* StratsOptionHudScripts[TABMAX];
BSS s32 StratsOptionNames[5]; // msg IDs
BSS s32 StratsOptionCount;
BSS s32 StratsPrevSelected;

#if !VERSION_IQUE
BSS s32 D_802AD674; // unused?
#endif
BSS s32 StratsOptionMenuTypes[TABMAX];
BSS s32 StratsOptionEnabled[TABMAX]; // strats options enabled
BSS s32 StratsOptionError[TABMAX];
BSS s32 StratsOptionMessage[5];
BSS s32 D_802AD6D4;

void create_battle_popup_menu(PopupMenu* popup);

s32 get_player_anim_for_status(s32 animID);
void btl_menu_moves_draw_content(void* data, s32 x, s32 y);
void btl_menu_moves_show_title(void* data, s32 x, s32 y);
void btl_menu_moves_show_icon(void* data, s32 x, s32 y);
void btl_menu_moves_show_desc(void* data, s32 x, s32 y);
void btl_menu_moves_show_error(void* data, s32 x, s32 y);
void btl_menu_strats_draw_content(void* data, s32 x, s32 y);
void btl_menu_strats_show_title(void* data, s32 x, s32 y);
void btl_menu_strats_show_desc(void* data, s32 x, s32 y);
void btl_menu_strats_show_error(void* data, s32 x, s32 y);

void btl_init_menu_items(void);
void btl_check_can_change_partner(void);
void btl_init_menu_partner(void);

// forces an update step for the popup menu
void flush_popup_menu(void);

void show_popup_menu(void);

void btl_init_menu_boots(void);
void btl_init_menu_hammer(void);

void btl_main_menu_init(void) {
    BattleMenu_ReelAlpha = 255;
    BattleMenuAlpha = 255;
    BattleMenuState = BTL_MENU_STATE_CREATE;
    BattleMenu_ErrorCode = -1;
}

// btl_main_menu_hide? (after begin targeting)
void btl_main_menu_hide(void) {
    BattleMenu_ReelAppearTimer = 3;
    BattleMenuState = BTL_MENU_STATE_HIDE_INIT;
}

// (after submenu closed/cancelled)
void btl_main_menu_resume_choose(void) {
    BattleMenuState = BTL_MENU_STATE_CHOOSING;
    BattleMenu_ReelAlpha = 255;
    BattleMenuAlpha = 255;
}

// btl_main_menu_show? (canceling targeting -> main menu)
void btl_main_menu_restore_choose(void) {
    BattleMenuAlpha = 255;
    BattleMenuState = BTL_MENU_STATE_RESTORE;
}

// btl_main_menu_show? (canceling targeting -> submenu)
void btl_main_menu_restore_submenu(void) {
    BattleMenuAlpha = 100;
    BattleMenuState = BTL_MENU_STATE_RESUME_SUBMENU;
}

void btl_main_menu_destroy(void) {
    s32 i;

    for (i = 0; i < WheelOptionCount; i++) {
        s32* icons1 = HID_OptionIcons;
        s32* icons2 = HID_Spotlights;

        hud_element_free(icons1[i]);
        hud_element_free(icons2[i]);
    }

    hud_element_free(HID_HighlightSpot);
    hud_element_free(HID_ProjectorReelA);
    hud_element_free(HID_ProjectorReelB);
    hud_element_free(HID_ProjectorBeam);
    hud_element_free(HID_SwapBackground);
    hud_element_free(HID_SwapZ);
    hud_element_free(HID_SwapArrowLeft);
    hud_element_free(HID_SwapArrowRight);
}

s32 btl_main_menu_update(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    f32 theta;
    HudElemID hid;
    s32 i;
    f32 x, y;
    s32 l, t;

    switch (BattleMenuState) {
        case BTL_MENU_STATE_CREATE:
            BattleMenu_BasePosX = 54;
            BattleMenu_BasePosY = 173;
            BattleMenu_WheelSpeed = 0.3f;
            BattleMenu_WheelMoving = 0;
            BattleMenu_HomePos = BattleMenu_PrevSelected;
            BattleMenu_MinIdx = 0;
            BattleMenu_MinIdx -= BattleMenu_PrevSelected;
            BattleMenu_MaxIdx = WheelOptionCount - 1;
            BattleMenu_MaxIdx -= BattleMenu_PrevSelected;

            for (i = 0; i < WheelOptionCount; i++) {
                HID_OptionIcons[i] = hid = hud_element_create(WheelOptionHudScript[i]);
                hud_element_set_render_depth(hid, 5);
#if VERSION_PAL
                hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER | HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_DISABLED);
#else
                hud_element_set_flags(hid, HUD_ELEMENT_FLAG_FILTER_TEX);
                hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER);
                hud_element_set_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
#endif
                hud_element_set_scale(hid, 0.75f);

                HID_Spotlights[i] = hid = hud_element_create(&HES_ProjectorSpot);
                hud_element_create_transform_B(hid);
                hud_element_set_render_depth(hid, 10);
#if VERSION_PAL
                hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER | HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_DISABLED);
#else
                hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER);
                hud_element_set_flags(hid, HUD_ELEMENT_FLAG_FILTER_TEX);
                hud_element_set_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
#endif

            }

            HID_HighlightSpot = hid = hud_element_create(&HES_ProjectorSpot);
            hud_element_create_transform_B(hid);
            hud_element_set_render_depth(hid, 7);
#if VERSION_PAL
            hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER | HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_DISABLED);
#else
            hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER);
            hud_element_set_flags(hid, HUD_ELEMENT_FLAG_FILTER_TEX);
            hud_element_set_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
#endif

            HID_ProjectorReelA = hid = hud_element_create(&HES_ProjectorReel);
            hud_element_create_transform_B(hid);
            hud_element_set_render_depth(hid, 0);
            hud_element_set_render_pos(hid, 40, 212);
            hud_element_set_tint(hid, 0, 91, 127);
            hud_element_set_transform_rotation_pivot(hid, 16, -16);
            hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER);
            hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_FILTER_TEX);
            hud_element_set_alpha(hid, 240);

            HID_ProjectorReelB = hid = hud_element_create(&HES_ProjectorReel);
            hud_element_create_transform_B(hid);
            hud_element_set_render_depth(hid, 2);
            hud_element_set_render_pos(hid, 39, 212);
            hud_element_set_tint(hid, 0, 91, 127);
            hud_element_set_transform_rotation_pivot(hid, 16, -16);
            hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER);
            hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_FILTER_TEX);
            hud_element_set_alpha(hid, 240);

            HID_ProjectorBeam = hid = hud_element_create(&HES_ProjectorBeam);
            hud_element_create_transform_B(hid);
            hud_element_set_render_depth(hid, 20);
            hud_element_set_render_pos(hid, 78, 178);
            hud_element_set_tint(hid, 255, 255, 255);
            hud_element_set_transform_rotation_pivot(hid, 0, 0);
            hud_element_set_transform_rotation(hid, 0.0f, 0.0f, -45.0f);
            hud_element_set_alpha(hid, 200);
#if VERSION_PAL
            hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER | HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_DISABLED);
#else
            hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER);
            hud_element_set_flags(hid, HUD_ELEMENT_FLAG_FILTER_TEX);
            hud_element_set_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
#endif

            HID_SwapBackground = hid = hud_element_create(&HES_SwapBackground);
            hud_element_set_render_depth(hid, 0);
            hud_element_set_render_pos(hid, 97, 208);
            hud_element_set_tint(hid, 255, 255, 255);
            hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER);
            hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_FILTER_TEX);
            hud_element_set_alpha(hid, 230);

            HID_SwapZ = hid = hud_element_create(&HES_SwapZ);
            hud_element_set_render_depth(hid, 5);
            hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_FILTER_TEX);
            hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER);
            hud_element_set_render_pos(hid, 94, 209);

            HID_SwapArrowLeft = hid = hud_element_create(&HES_SwapArrowLeft);
            hud_element_set_render_depth(hid, 5);
            hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_FILTER_TEX);
            hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER);
            hud_element_set_render_pos(hid, 81, 210);

            HID_SwapArrowRight = hid = hud_element_create(&HES_SwapArrowRight);
            hud_element_set_render_depth(hid, 5);
            hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_FILTER_TEX);
            hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER);
            hud_element_set_render_pos(hid, 102, 210);
            BattleMenu_ReelHidePercent = 100;
            BattleMenu_ReelAppearTimer = 3;
            BattleMenuState = BTL_MENU_STATE_SHOW_REEL;
            BattleMenu_WheelAngle = theta = BattleMenu_WheelBase * 28;
            break;
        case BTL_MENU_STATE_SHOW_REEL:
            BattleMenu_ReelHidePercent = (BattleMenu_ReelAppearTimer * 100) / 3;

            switch (BattleMenu_ReelAppearTimer) {
                case 1:
                    if (BattleMenu_ReelAppearTimer == 1) {
                        hid = HID_ProjectorBeam;
                        hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
                    }
                default:
                    BattleMenu_ReelAppearTimer--;
                    break;
                case 0:
                    BattleMenu_CurPos = 0;
                    BattleMenu_PrevPos = 0;
                    BattleMenu_WheelAngle = theta = BattleMenu_WheelBase * 28;
                    for (i = 0; i < WheelOptionCount; i++, theta += 28.0f) {
                        x = 0.0f;
                        y = 0.0f;
                        add_vec2D_polar(&x, &y, 87.0f, theta);

                        l = BattleMenu_BasePosX + x;
                        t = BattleMenu_BasePosY + y;
                        hid = HID_OptionIcons[i];
                        hud_element_set_render_pos(hid, l, t);
                        hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);

                        hid = HID_Spotlights[i];
                        hud_element_set_render_pos(hid, l, t);
                        hud_element_set_alpha(hid, 100);
                        hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
                    }

                    x = 0.0f;
                    y = 0.0f;
                    theta = BattleMenu_WheelBase * 28;
                    add_vec2D_polar(&x, &y, 87.0f, theta);

                    l = BattleMenu_BasePosX + x;
                    t = BattleMenu_BasePosY + y;
                    hid = HID_HighlightSpot;
                    hud_element_set_render_pos(hid, l, t);
                    hud_element_set_alpha(hid, 180);
                    hud_element_set_scale(hid, 0.85f);
                    hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
                    BattleMenuState = BTL_MENU_STATE_CHOOSING;
                    break;
            }
            break;
        case BTL_MENU_STATE_CHOOSING:
            if (battleStatus->curButtonsPressed & BUTTON_A) {
                if (WheelOptionEnabled[BattleMenu_CurPos + BattleMenu_HomePos] == true) {
                    sfx_play_sound(SOUND_MENU_NEXT);
                    BattleMenuState = BTL_MENU_STATE_SUBMENU_OPEN;
                } else {
                    sfx_play_sound(SOUND_MENU_ERROR);
                    BattleMenu_ErrorCode = WheelOptionError[BattleMenu_CurPos + BattleMenu_HomePos];
                    BattleMenuState = BTL_MENU_STATE_ERROR_SHOW;
                }
            } else {
                BattleMenu_PrevPos = BattleMenu_CurPos;
                if (BattleMenu_WheelMoving == 0) {
                    if ((battleStatus->curButtonsHeld & (BUTTON_STICK_LEFT | BUTTON_STICK_UP)) &&
                        BattleMenu_MinIdx < BattleMenu_CurPos)
                    {
                        BattleMenu_CurPos--;
                    }
                    if ((battleStatus->curButtonsHeld & (BUTTON_STICK_RIGHT | BUTTON_STICK_DOWN)) &&
                        BattleMenu_CurPos < BattleMenu_MaxIdx)
                    {
                        BattleMenu_CurPos++;
                    }
                }

                if (BattleMenu_PrevPos != BattleMenu_CurPos) {
                    BattleMenu_WheelMoving = 1;
                    sfx_play_sound(SOUND_MENU_CHANGE_TAB);
                }
            }
            break;
        case BTL_MENU_STATE_SUBMENU_OPEN:
            BattleMenuAlpha = 100;
            return BattleMenu_CurPos + BattleMenu_HomePos + 1;
        case BTL_MENU_STATE_HIDE_INIT:
            BattleMenu_ReelAppearTimer = 0;
            BattleMenu_ReelAlpha = 0;
            BattleMenuState = BTL_MENU_STATE_HIDE_HOLD;
            return BattleMenu_CurPos + BattleMenu_HomePos + 1;
        case BTL_MENU_STATE_HIDE_HOLD:
            return BattleMenu_CurPos + BattleMenu_HomePos + 1;
        case BTL_MENU_STATE_RESTORE:
            BattleMenu_ReelAppearTimer = 3;
            BattleMenu_ReelAlpha = 255;
            BattleMenuState = BTL_MENU_STATE_CHOOSING;
            return BattleMenu_CurPos + BattleMenu_HomePos + 1;
        case BTL_MENU_STATE_RESUME_SUBMENU:
            BattleMenu_ReelAppearTimer = 3;
            BattleMenu_ReelAlpha = 255;
            BattleMenuState = BTL_MENU_STATE_SUBMENU_OPEN;
            break;
        case BTL_MENU_STATE_ERROR_SHOW:
            btl_show_battle_message(BattleMenu_ErrorCode, 90);
            BattleMenuState = BTL_MENU_STATE_ERROR_DONE;
            break;
        case BTL_MENU_STATE_ERROR_DONE:
            if (btl_is_popup_displayed()) {
                break;
            }
            BattleMenu_ErrorCode = -1;
            BattleMenuState = BTL_MENU_STATE_CHOOSING;
            break;
    }
    return 0;
}

#if VERSION_JP
#define BASE_X 40
#else
#define BASE_X 3940
#endif

void btl_main_menu_draw(void) {
    s32 id;
    s32 opacity;
    f32 theta;
    s32 cond;
    f32 x, y;
    f32 scale;
    s32 i;
    s32 l, t;

    switch (BattleMenuState) {
        case BTL_MENU_STATE_SHOW_REEL:
            hud_element_draw_complex_hud_first(-1);
            id = HID_ProjectorReelB;
            hud_element_set_transform_rotation(id, 0.0f, 0.0f, 0.0f);
            hud_element_set_alpha(id, (BattleMenu_ReelAlpha * 254) / 255);
            hud_element_set_render_pos(id, BASE_X - BattleMenu_ReelHidePercent, BattleMenu_ReelHidePercent + 212);
            hud_element_draw_complex_hud_next(id);
            id = HID_ProjectorReelA;
            hud_element_set_alpha(id, (BattleMenu_ReelAlpha * 254) / 255);
            hud_element_set_render_pos(id, 40 - BattleMenu_ReelHidePercent, BattleMenu_ReelHidePercent + 212);
            hud_element_draw_complex_hud_next(id);
            break;
        case BTL_MENU_STATE_SUBMENU_OPEN:
        case BTL_MENU_STATE_CHOOSING:
        case BTL_MENU_STATE_HIDE_INIT:
        case BTL_MENU_STATE_RESTORE:
        case BTL_MENU_STATE_RESUME_SUBMENU:
            opacity = (BattleMenu_ReelAlpha * BattleMenuAlpha) / 255;
            hud_element_draw_complex_hud_first(-1);
            theta = (BattleMenu_WheelBase - BattleMenu_CurPos) * 28;

            cond = false;
            if (BattleMenu_WheelAngle > theta) {
                BattleMenu_WheelAngle -= BattleMenu_WheelSpeed;
                if (BattleMenu_WheelAngle < theta) {
                    BattleMenu_WheelAngle = theta;
                    cond = true;
                }
            } else if (BattleMenu_WheelAngle < theta) {
                BattleMenu_WheelAngle += BattleMenu_WheelSpeed;
                if (BattleMenu_WheelAngle > theta) {
                    BattleMenu_WheelAngle = theta;
                    cond = true;
                }
            } else {
                cond = true;
            }

            if (!cond) {
                BattleMenu_WheelSpeed = (BattleMenu_WheelSpeed * (BattleMenu_WheelSpeed + 1.0) * (BattleMenu_WheelSpeed + 1.0));
            } else {
                BattleMenu_WheelMoving = 0;
                BattleMenu_WheelSpeed = 0.3f;
            }

            theta = BattleMenu_WheelAngle;
            for (i = 0; i < WheelOptionCount; i++, theta += 28.0f) {
                x = 0.0f;
                y = 0.0f;
                add_vec2D_polar(&x, &y, 87.0f, theta);
                id = HID_Spotlights[i];
                x = BattleMenu_BasePosX + x;
                y = BattleMenu_BasePosY + y;
                hud_element_set_transform_pos(id, x, -y, 0.0f);
                hud_element_set_render_pos(id, 0, 0);
                hud_element_set_alpha(id, (opacity * 150) / 255);

                if (theta == 56.0f && cond == true) {
                    hud_element_set_scale(id, 1.6f);
                } else {
                    hud_element_set_scale(id, 1.0f);
                }

                hud_element_draw_complex_hud_next(id);
                if (i == BattleMenu_HomePos + BattleMenu_CurPos) {
                    x = 0.0f;
                    y = 0.0f;
                    add_vec2D_polar(&x, &y, 87.0f, 56.0f);
                    x = BattleMenu_BasePosX + x;
                    y = BattleMenu_BasePosY + y;
                    id = HID_HighlightSpot;
                    hud_element_set_transform_pos(id, x, -y, 0.0f);
                    hud_element_set_render_pos(id, 0, 0);
                    hud_element_set_alpha(id, (opacity * 180) / 255);
                    hud_element_set_scale(id, 1.2f);
                    if (!cond) {
                        hud_element_set_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    } else {
                        hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    }
                    hud_element_draw_complex_hud_next(id);
                }
            }
            theta = (BattleMenu_WheelBase - BattleMenu_CurPos) * 28;
            scale = (fabsf(fabsf((BattleMenu_WheelAngle - theta) * (45.0 / 28.0)) - 22.5) / 22.5) + 0.01;
            if (cond) {
                scale = 1.0f;
            }

            id = HID_ProjectorBeam;
            hud_element_set_transform_rotation_pivot(id, 0, 0);
            hud_element_set_transform_rotation(id, 0.0f, 0.0f, -43.0f);
            hud_element_set_scale(id, scale);
            hud_element_set_transform_scale(id, 1.0f, 1.8f, 1.0f);
            hud_element_set_alpha(id, (opacity * 200) / 255);
            hud_element_set_render_pos(id, 79, 176);
            hud_element_draw_complex_hud_next(id);

            id = HID_ProjectorReelB;
            theta = (BattleMenu_WheelBase - BattleMenu_CurPos) * 28;
            scale = (BattleMenu_WheelAngle - theta) * (45.0 / 28.0);
            hud_element_set_transform_rotation(id, 0.0f, 0.0f, -scale);
            hud_element_set_transform_rotation_pivot(id, 18, -20);
            hud_element_set_scale(id, 0.95f);
            hud_element_set_alpha(id, (opacity * 254) / 255);
            hud_element_set_render_pos(id, 40 - BattleMenu_ReelHidePercent, BattleMenu_ReelHidePercent + 212);
            hud_element_draw_complex_hud_next(id);

            id = HID_ProjectorReelA;
            hud_element_set_alpha(id, (opacity * 254) / 255);
            hud_element_set_render_pos(id, 40 - BattleMenu_ReelHidePercent, BattleMenu_ReelHidePercent + 212);
            hud_element_set_scale(id, 1.0f);
            hud_element_draw_complex_hud_next(id);

            theta = BattleMenu_WheelAngle;
            for (i = 0; i < WheelOptionCount; i++, theta += 28.0f) {
                x = 0.0f;
                y = 0.0f;
                add_vec2D_polar(&x, &y, 87.0f, theta);
                l = x = BattleMenu_BasePosX + x;
                t = y = BattleMenu_BasePosY + y;
                btl_draw_prim_quad(0, 0, 0, 0, l - 12, t - 12, 24, 24);
                id = HID_OptionIcons[i];
                hud_element_set_render_pos(id, l, t);
                hud_element_set_alpha(id, (opacity * 180) / 255);
                if (i == BattleMenu_HomePos + BattleMenu_CurPos) {
                    hud_element_set_alpha(id, opacity);
                }
                hud_element_draw_clipped(id);
            }

            if (cond) {
                l = BattleMenu_BasePosX + 20;
                t = BattleMenu_BasePosY - 34;
                btl_draw_prim_quad(0, 0, 0, 0, l + 26, t, 48, 16);
                draw_msg(WheelOptionName[BattleMenu_CurPos + BattleMenu_HomePos], l, t, opacity, MSG_PAL_35, 0);
            }

            if ((gBattleStatus.flags1 & BS_FLAGS1_TUTORIAL_BATTLE) || (gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE)) {
                BattleMenu_ShowSwapIcons = false;
            }

            if (BattleMenu_ShowSwapIcons) {
                id = HID_SwapBackground;
                hud_element_set_alpha(id, (opacity * 200) / 255);
                hud_element_draw_clipped(id);
                id = HID_SwapZ;
                hud_element_set_alpha(id, opacity);
                hud_element_draw_clipped(id);
                id = HID_SwapArrowLeft;
                hud_element_set_alpha(id, opacity);
                hud_element_draw_clipped(id);
                id = HID_SwapArrowRight;
                hud_element_set_alpha(id, opacity);
                hud_element_draw_clipped(id);
            }
            break;
    }
}

// Very similar to btl_menu_strats_init - maybe can be used to reduce fake matches there
void btl_submenu_moves_init(void) {
    if (MovesPrevSelected >= MovesOptionCount) {
        MovesPrevSelected = MovesOptionCount - 1;
    }

    MovesMenuState = BTL_SUBMENU_MOVES_STATE_INIT;
    MovesVisibleStart = 0;
    MovesCursorPos = MovesPrevSelected;
    MovesPrevCursorPos = MovesPrevSelected;
    MovesMenuLines = MovesOptionCount;

    if (MovesMenuLines > 6) {
        MovesMenuLines = 6;
    }

    MovesVisibleEnd = 6;
    if (MovesOptionCount < 6) {
        MovesVisibleEnd = MovesOptionCount;
    }

    MovesTextAlpha = 255;
    MovesDescVisible = 1;

    if (MovesPrevCursorPos < 0) {
        MovesVisibleStart = MovesPrevCursorPos;
    }
    if (MovesPrevCursorPos >= MovesVisibleEnd) {
        MovesVisibleStart = MovesPrevCursorPos + 1 - MovesMenuLines;
    }

    MovesVisibleEnd = MovesVisibleStart + 6;
    if (MovesVisibleEnd > MovesOptionCount) {
        MovesVisibleEnd = MovesOptionCount;
    }

    MovesScrollOffset = -MovesVisibleStart * 13;
    MovesCursorOffset = (MovesPrevCursorPos - MovesVisibleStart) * 13;
    SelectedMovesIndex = 0;
}

void btl_submenu_moves_hide(void) {
    MovesMenuState = BTL_SUBMENU_MOVES_STATE_HIDE_INIT;
}

void btl_submenu_moves_destroy(void) {
    s32 i;

    set_window_update(WIN_BTL_MOVES_MENU, WINDOW_UPDATE_HIDE);

    if (!UsingSpiritsSubmenu) {
        set_window_update(WIN_BTL_MOVES_TITLE, WINDOW_UPDATE_HIDE);
        set_window_update(WIN_BTL_MOVES_ICON, WINDOW_UPDATE_HIDE);
    } else {
        set_window_update(WIN_BTL_SPIRITS_TITLE, WINDOW_UPDATE_HIDE);
        set_window_update(WIN_BTL_SPIRITS_ICON, WINDOW_UPDATE_HIDE);
    }

    set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_HIDE);

    for (i = 0; i < MovesOptionCount; i++) {
        hud_element_free(MovesOptionHIDs[i]);
    }

    hud_element_free(HID_MovesCursor);
    hud_element_free(HID_MovesArrowUp);
    hud_element_free(HID_MovesArrowDown);
    hud_element_free(HID_MovesTitle);

    for (i = 0; i < MovesOptionCount; i++) {
        hud_element_free(MovesOptionCostHIDs[i]);
    }
}

void btl_submenu_moves_resume_choose(void) {
    s32* moveOptionIconIDs;
    s32* moveOptionCostUnitIconIDs;
    s32 i;

    moveOptionIconIDs = MovesOptionHIDs;

    for (i = 0; i < MovesOptionCount; i++) {
        hud_element_set_tint(moveOptionIconIDs[i], 255, 255, 255);
    }

    hud_element_set_tint(HID_MovesCursor, 255, 255, 255);
    hud_element_set_tint(HID_MovesArrowUp, 255, 255, 255);
    hud_element_set_tint(HID_MovesArrowDown, 255, 255, 255);
    hud_element_set_tint(HID_MovesTitle, 255, 255, 255);

    moveOptionCostUnitIconIDs = MovesOptionCostHIDs;

    for (i = 0; i < MovesOptionCount; i++) {
        hud_element_set_tint(moveOptionCostUnitIconIDs[i], 255, 255, 255);
    }

    hud_element_set_script(HID_MovesCursor, &HES_AnimatedHandPointer);
    set_window_update(WIN_BTL_MOVES_MENU, WINDOW_UPDATE_TRANSPARENT);

    if (!UsingSpiritsSubmenu) {
        set_window_update(WIN_BTL_MOVES_TITLE, WINDOW_UPDATE_TRANSPARENT);
        set_window_update(WIN_BTL_MOVES_ICON, WINDOW_UPDATE_TRANSPARENT);
    } else {
        set_window_update(WIN_BTL_SPIRITS_TITLE, WINDOW_UPDATE_TRANSPARENT);
        set_window_update(WIN_BTL_SPIRITS_ICON, WINDOW_UPDATE_TRANSPARENT);
    }

    set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_SHOW);
    MovesTextColor = MSG_PAL_STANDARD;
    MovesDescVisible = 1;
    MovesTextAlpha = 255;
    MovesMenuState = BTL_SUBMENU_MOVES_STATE_CHOOSING;
}

void btl_submenu_moves_restore_choose(void) {
    s32* moveOptionIconIDs;
    s32* moveOptionCostUnitIconIDs;
    s32 i;

    set_window_update(WIN_BTL_MOVES_MENU, WINDOW_UPDATE_TRANSPARENT);

    if (!UsingSpiritsSubmenu) {
        set_window_update(WIN_BTL_MOVES_TITLE, WINDOW_UPDATE_TRANSPARENT);
        set_window_update(WIN_BTL_MOVES_ICON, WINDOW_UPDATE_TRANSPARENT);
    } else {
        set_window_update(WIN_BTL_SPIRITS_TITLE, WINDOW_UPDATE_TRANSPARENT);
        set_window_update(WIN_BTL_SPIRITS_ICON, WINDOW_UPDATE_TRANSPARENT);
    }
    set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_SHOW);

    moveOptionIconIDs = MovesOptionHIDs;

    for (i = 0; i < MovesOptionCount; i++) {
        hud_element_set_tint(moveOptionIconIDs[i], 255, 255, 255);
    }

    hud_element_set_tint(HID_MovesCursor, 255, 255, 255);
    hud_element_set_tint(HID_MovesArrowUp, 255, 255, 255);
    hud_element_set_tint(HID_MovesArrowDown, 255, 255, 255);
    hud_element_set_tint(HID_MovesTitle, 255, 255, 255);

    moveOptionCostUnitIconIDs = MovesOptionCostHIDs;

    for (i = 0; i < MovesOptionCount; i++) {
        hud_element_set_tint(moveOptionCostUnitIconIDs[i], 255, 255, 255);
    }

    hud_element_set_script(HID_MovesCursor, &HES_AnimatedHandPointer);
    MovesTextColor = MSG_PAL_STANDARD;
    MovesDescVisible = 1;
    MovesMenuState = BTL_SUBMENU_MOVES_STATE_RESTORE;
}

void btl_submenu_moves_restore_locked(void) {
    set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_SHOW);
    MovesMenuState = BTL_SUBMENU_MOVES_STATE_LOCK;
}

#if VERSION_PAL
#define MOVES_OPTIONS_W D_PAL_802AB4E4[gCurrentLanguage]
#define MOVES_TITLE_X D_PAL_802AB4EC[gCurrentLanguage]
#define MOVES_TITLE_W D_PAL_802AB4F0[gCurrentLanguage]
#define MOVES_ICON_X 120 + D_PAL_802AB4F8[gCurrentLanguage]
#define STAR_SPIRITS_OPTIONS_W D_PAL_802AB4CC[gCurrentLanguage]
#define STAR_SPIRITS_TITLE_X D_PAL_802AB4D8[gCurrentLanguage]
#define STAR_SPIRITS_TITLE_W D_PAL_802AB4DC[gCurrentLanguage]
#define STAR_SPIRITS_ICON_X 110 + D_PAL_802AB4D4[gCurrentLanguage]
#define POS_X 20
#define WIDTH_3 280
#elif VERSION_JP
#define MOVES_OPTIONS_W 150
#define MOVES_TITLE_X 10
#define MOVES_TITLE_W 80
#define MOVES_ICON_X 104
#define STAR_SPIRITS_OPTIONS_W 144
#define STAR_SPIRITS_TITLE_X 10
#define STAR_SPIRITS_TITLE_W 80
#define STAR_SPIRITS_ICON_X 104
#define POS_X 32
#define WIDTH_3 242
#else
#define MOVES_OPTIONS_W 150
#define MOVES_TITLE_X 16
#define MOVES_TITLE_W 90
#define MOVES_ICON_X 114
#define STAR_SPIRITS_OPTIONS_W 144
#define STAR_SPIRITS_TITLE_X 10
#define STAR_SPIRITS_TITLE_W 100
#define STAR_SPIRITS_ICON_X 110
#define POS_X 20
#define WIDTH_3 280
#endif

s32 btl_submenu_moves_update(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    s8 temp_v0_14;
    s32 moveX;
    s32 moveY;
    s32 msgWidth;
    s32 msgX;
    s32 msgID;
    s32 cond;
    HudElemID hid;
    s32 i;
    s32 j;

    switch (MovesMenuState) {
        case BTL_SUBMENU_MOVES_STATE_INIT:
            MovesScrollOffset = -MovesVisibleStart * 13;
            MovesCursorOffset = (MovesCursorPos - MovesVisibleStart) * 13;
            MovesMenuPosX = POS_X;
            MovesMenuPosY = 68;

            for (i = 0; i < MovesOptionCount; i++) {
                MovesOptionIndexMap[i] = i;
            }

            if (!UsingSpiritsSubmenu) {
                for (i = 0; i < (MovesOptionCount - 1); i++) {
                    for (j = i + 1; j < MovesOptionCount; j++) {
                        do {
                            s32 temp1 = MovesOptionIndexMap[i];
                            s32 temp2 = MovesOptionIndexMap[j];

                            if (MovesOptionSortPriority[temp1] < MovesOptionSortPriority[temp2]) {
                                continue;
                            }

                            if (
                                MovesOptionSortPriority[temp1] != MovesOptionSortPriority[temp2] ||
                                (MovesOptionDisplayCosts[temp1] >= MovesOptionDisplayCosts[temp2]) &&
                                (MovesOptionDisplayCosts[temp1] != MovesOptionDisplayCosts[temp2] ||
                                    MovesOptionBPCosts[temp1] >= MovesOptionBPCosts[temp2])
                            )
                            {
                                s32 swapTmp = MovesOptionIndexMap[i];
                                MovesOptionIndexMap[i] = MovesOptionIndexMap[j];
                                MovesOptionIndexMap[j] = swapTmp;
                            }
                        } while (0);
                    }
                }
            }

            for (i = 0; i < MovesOptionCount; i++) {
                hid = hud_element_create(MovesOptionHudScripts[MovesOptionIndexMap[i]]);
                MovesOptionHIDs[i] = hid;
                hud_element_set_scale(hid, 0.45f);
                hud_element_set_flags(hid, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_MANUAL_RENDER);
            }

            hid = hud_element_create(&HES_AnimatedHandPointer);
            HID_MovesCursor = hid;
            hud_element_set_flags(hid, HUD_ELEMENT_FLAG_DROP_SHADOW | HUD_ELEMENT_FLAG_MANUAL_RENDER);
            hud_element_set_render_pos(hid, MovesMenuPosX, MovesMenuPosY);

            hid = hud_element_create(&HES_GreenArrowUp);
            HID_MovesArrowUp = hid;
            hud_element_set_flags(hid, HUD_ELEMENT_FLAG_DROP_SHADOW | HUD_ELEMENT_FLAG_MANUAL_RENDER);
            hud_element_set_render_pos(hid, MovesMenuPosX + 39, MovesMenuPosY - 7);

            hid = hud_element_create(&HES_GreenArrowDown);
            HID_MovesArrowDown = hid;
            hud_element_set_flags(hid, HUD_ELEMENT_FLAG_DROP_SHADOW | HUD_ELEMENT_FLAG_MANUAL_RENDER);
            hud_element_set_render_pos(hid, MovesMenuPosX + 39, MovesMenuPosY + 78);

            if (!UsingSpiritsSubmenu) {
                hid = hud_element_create(&HES_StatusFlower);
                HID_MovesTitle = hid;
                hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER);
            } else {
                hid = hud_element_create(&HES_MenuStarPower);
                HID_MovesTitle = hid;
                hud_element_set_scale(hid, 0.75f);
                hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER);
            }
            hud_element_set_render_pos(hid, MovesMenuPosX + 56, MovesMenuPosY);

            for (i = 0; i < MovesOptionCount; i++) {
                if (!UsingSpiritsSubmenu) {
#if VERSION_PAL
                    switch (MovesOptionDiscountColors[i]) {
                        case 0:
                            hid = 0;
                            break;
                        case 1:
                            hid = 1;
                            break;
                        default:
                            hid = 2;
                            break;
                    }
                    hid = hud_element_create(D_PAL_802AB4FC[hid][gCurrentLanguage]);
                    MovesOptionCostHIDs[i] = hid;
#else
                    switch (MovesOptionDiscountColors[i]) {
                        case 0:
                            hid = hud_element_create(&HES_FPCost);
                            MovesOptionCostHIDs[i] = hid;
                            break;
                        case 1:
                            hid = hud_element_create(&HES_FPCostReduced);
                            MovesOptionCostHIDs[i] = hid;
                            break;
                        default:
                            hid = hud_element_create(&HES_FPCostReducedTwice);
                            MovesOptionCostHIDs[i] = hid;
                            break;
                    }
#endif
                } else {
#if VERSION_PAL
                    switch (MovesOptionDiscountColors[i]) {
                        case 0:
                            hid = 0;
                            break;
                        case 1:
                            hid = 1;
                            break;
                        default:
                            hid = 2;
                            break;
                    }
                    hid = hud_element_create(D_PAL_802AB53C[hid][gCurrentLanguage]);
                    MovesOptionCostHIDs[i] = hid;
#else
                    switch (MovesOptionDiscountColors[i]) {
                        case 0:
                            hid = hud_element_create(&HES_POWCost);
                            MovesOptionCostHIDs[i] = hid;
                            break;
                        case 1:
                            hid = hud_element_create(&HES_POWCostReduced);
                            MovesOptionCostHIDs[i] = hid;
                            break;
                        default:
                            hid = hud_element_create(&HES_POWCostReducedTwice);
                            MovesOptionCostHIDs[i] = hid;
                            break;
                    }
#endif
                }
                hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER);
                hud_element_set_render_pos(hid, MovesMenuPosX + 56, MovesMenuPosY);
            }

            MovesTextColor = MSG_PAL_STANDARD;

            moveX = MovesMenuPosX;
            moveY = MovesMenuPosY;
#if VERSION_JP
            set_window_properties(WIN_BTL_MOVES_MENU, moveX, moveY, 140, (MovesMenuLines * 13) + 28, 0, btl_menu_moves_draw_content, nullptr, -1);
#endif
            if (!UsingSpiritsSubmenu) {
#if !VERSION_JP
                set_window_properties(WIN_BTL_MOVES_MENU, moveX, moveY, MOVES_OPTIONS_W, (MovesMenuLines * 13) + 28, 0, btl_menu_moves_draw_content, nullptr, -1);
#endif
                set_window_properties(WIN_BTL_MOVES_TITLE, moveX + MOVES_TITLE_X, moveY - 6, MOVES_TITLE_W, 16, 1, btl_menu_moves_show_title, nullptr, -1);
                set_window_properties(WIN_BTL_MOVES_ICON, moveX + MOVES_ICON_X, moveY - 12, 32, 32, 1, btl_menu_moves_show_icon, nullptr, -1);
            } else {
                s16 new_var;

#if !VERSION_JP
                set_window_properties(WIN_BTL_MOVES_MENU, moveX, moveY, STAR_SPIRITS_OPTIONS_W, (MovesMenuLines * 13) + 28, 0, btl_menu_moves_draw_content, nullptr, -1);
#endif
                new_var = moveY; // todo required to match
                set_window_properties(WIN_BTL_SPIRITS_TITLE, moveX + STAR_SPIRITS_TITLE_X, new_var - 6, STAR_SPIRITS_TITLE_W, 16, 1, btl_menu_moves_show_title, 0, -1);
                set_window_properties(WIN_BTL_SPIRITS_ICON, moveX + STAR_SPIRITS_ICON_X, new_var - 12, 32, 35, 1, btl_menu_moves_show_icon, 0, -1);
            }

            moveX = POS_X;
            moveY = MovesMenuPosY;
            set_window_properties(WIN_BTL_DESC_BOX, moveX, 186, WIDTH_3, 32, WINDOW_PRIORITY_20, btl_menu_moves_show_desc, nullptr, -1);
            set_window_update(WIN_BTL_MOVES_MENU, WINDOW_UPDATE_SHOW);
            if (!UsingSpiritsSubmenu) {
                set_window_update(WIN_BTL_MOVES_TITLE, WINDOW_UPDATE_SHOW);
                set_window_update(WIN_BTL_MOVES_ICON, WINDOW_UPDATE_SHOW);
            } else {
                set_window_update(WIN_BTL_SPIRITS_TITLE, WINDOW_UPDATE_SHOW);
                set_window_update(WIN_BTL_SPIRITS_ICON, WINDOW_UPDATE_SHOW);
            }
            set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_SHOW);

            do {
                cond = false;
                if (MovesCursorPos >= (MovesVisibleStart + MovesVisibleEnd) - 1) {
                    MovesVisibleStart++;
                    if (MovesVisibleStart > MovesOptionCount - 6) {
                        MovesVisibleStart = MovesOptionCount - 6;
                        if (MovesVisibleStart < 0) {
                            MovesVisibleStart = 0;
                        }
                    } else {
                        cond = true;
                    }
                }
            } while (cond);

            MovesMenuState = BTL_SUBMENU_MOVES_STATE_CHOOSING;
            MovesVisibleEnd = MovesVisibleStart + 6;
            MovesScrollOffset = -MovesVisibleStart * 13;
            MovesCursorOffset = (MovesCursorPos - MovesVisibleStart) * 13;
            break;
        case BTL_SUBMENU_MOVES_STATE_CHOOSING:
            MovesPrevCursorPos = MovesCursorPos;
            if (battleStatus->curButtonsHeld & (BUTTON_STICK_UP | BUTTON_Z)) {
                if (MovesCursorPos > 0) {
                    MovesCursorPos--;
                } else if (battleStatus->curButtonsPressed & (BUTTON_STICK_UP | BUTTON_Z)) {
                    MovesCursorPos--;
                }
            }

            if (battleStatus->curButtonsHeld & (BUTTON_STICK_DOWN | BUTTON_R)) {
                if (MovesCursorPos < MovesOptionCount - 1) {
                    MovesCursorPos++;
                } else if (battleStatus->curButtonsPressed & (BUTTON_STICK_DOWN | BUTTON_R)) {
                    MovesCursorPos++;
                }
            }

            if (MovesCursorPos < 0) {
                MovesCursorPos = MovesOptionCount - 1;
            }

            if (MovesOptionCount - 1 < MovesCursorPos) {
                MovesCursorPos = 0;
            }

            if (MovesPrevCursorPos != MovesCursorPos) {
                hud_element_set_scale(MovesOptionHIDs[MovesPrevCursorPos], 0.45f);
                sfx_play_sound(SOUND_MENU_CHANGE_SELECTION);
            }

            if (MovesCursorPos < MovesVisibleStart + 1) {
                MovesVisibleStart--;
                if (MovesVisibleStart < 0) {
                    MovesVisibleStart = 0;
                }
            }

            if (MovesCursorPos >= (MovesVisibleEnd - 1)) {
                MovesVisibleStart++;
                if (MovesVisibleStart > MovesOptionCount - 6) {
                    MovesVisibleStart = MovesOptionCount - 6;
                    if (MovesVisibleStart < 0) {
                        MovesVisibleStart = 0;
                    }
                }
            }

            MovesVisibleEnd = MovesVisibleStart + 6;
            if (battleStatus->curButtonsPressed & BUTTON_A) {
                if (MovesOptionEnabled[MovesOptionIndexMap[MovesCursorPos]] == 1) {
                    sfx_play_sound(SOUND_MENU_NEXT);
                    MovesMenuState = BTL_SUBMENU_MOVES_STATE_SELECT;
                } else {
                    sfx_play_sound(SOUND_MENU_ERROR);
                    MovesErrorCode = 0;
                    temp_v0_14 = MovesOptionError[MovesOptionIndexMap[MovesCursorPos]];
                    if (temp_v0_14 != 0) {
                        MovesErrorCode = temp_v0_14;
                    }
                    MovesMenuState = BTL_SUBMENU_MOVES_STATE_ERROR_INIT;
                }
                break;
            }

            if (battleStatus->curButtonsPressed & BUTTON_B) {
                sfx_play_sound(SOUND_MENU_BACK);
                btl_submenu_moves_destroy();
                MovesMenuState = BTL_SUBMENU_MOVES_STATE_CANCEL;
            }
            break;
        case BTL_SUBMENU_MOVES_STATE_SELECT:
            for (i = 0; i < MovesOptionCount; i++) {
                hid = MovesOptionHIDs[i];
                hud_element_set_tint(hid, 160, 160, 160);
            }
            hud_element_set_tint(HID_MovesCursor, 160, 160, 160);
            hud_element_set_tint(HID_MovesArrowUp, 160, 160, 160);
            hud_element_set_tint(HID_MovesArrowDown, 160, 160, 160);
            hud_element_set_tint(HID_MovesTitle, 160, 160, 160);

            for (i = 0; i < MovesOptionCount; i++) {
                hid = MovesOptionCostHIDs[i];
                hud_element_set_tint(hid, 160, 160, 160);
            }

            hud_element_set_script(HID_MovesCursor, &HES_HandPointer);
            MovesTextColor = MSG_PAL_0D;
            set_window_update(WIN_BTL_MOVES_MENU, WINDOW_UPDATE_DARKENED);
            if (!UsingSpiritsSubmenu) {
                set_window_update(WIN_BTL_MOVES_TITLE, WINDOW_UPDATE_DARKENED);
                set_window_update(WIN_BTL_MOVES_ICON, WINDOW_UPDATE_DARKENED);
            } else {
                set_window_update(WIN_BTL_SPIRITS_TITLE, WINDOW_UPDATE_DARKENED);
                set_window_update(WIN_BTL_SPIRITS_ICON, WINDOW_UPDATE_DARKENED);
            }
            set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_HIDE);
            if (!UsingSpiritsSubmenu) {
                status_bar_stop_blinking_fp();
            } else {
                status_bar_stop_blinking_sp();
            }
            SelectedMovesIndex = MovesCursorPos;
            return MovesOptionIndexMap[MovesCursorPos] + 1;
        case BTL_SUBMENU_MOVES_STATE_CANCEL:
            if (!UsingSpiritsSubmenu) {
                status_bar_stop_blinking_fp();
            } else {
                status_bar_stop_blinking_sp();
            }
            return POPUP_RESULT_CANCEL;
        case BTL_SUBMENU_MOVES_STATE_HIDE_INIT:
            set_window_update(WIN_BTL_MOVES_MENU, WINDOW_UPDATE_HIDE);
            if (!UsingSpiritsSubmenu) {
                set_window_update(WIN_BTL_MOVES_TITLE, WINDOW_UPDATE_HIDE);
                set_window_update(WIN_BTL_MOVES_ICON, WINDOW_UPDATE_HIDE);
            } else {
                set_window_update(WIN_BTL_SPIRITS_TITLE, WINDOW_UPDATE_HIDE);
                set_window_update(WIN_BTL_SPIRITS_ICON, WINDOW_UPDATE_HIDE);
            }
            set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_HIDE);
            if (!UsingSpiritsSubmenu) {
                status_bar_stop_blinking_fp();
            } else {
                status_bar_stop_blinking_sp();
            }
            MovesMenuState = BTL_SUBMENU_MOVES_STATE_HIDE_HOLD;
            SelectedMovesIndex = MovesCursorPos;
            return MovesOptionIndexMap[MovesCursorPos] + 1;
        case BTL_SUBMENU_MOVES_STATE_HIDE_HOLD:
            SelectedMovesIndex = MovesCursorPos;
            return MovesOptionIndexMap[MovesCursorPos] + 1;
        case BTL_SUBMENU_MOVES_STATE_RESTORE:
            set_window_update(WIN_BTL_MOVES_MENU, WINDOW_UPDATE_SHOW);
            if (!UsingSpiritsSubmenu) {
                set_window_update(WIN_BTL_MOVES_TITLE, WINDOW_UPDATE_SHOW);
                set_window_update(WIN_BTL_MOVES_ICON, WINDOW_UPDATE_SHOW);
            } else {
                set_window_update(WIN_BTL_SPIRITS_TITLE, WINDOW_UPDATE_SHOW);
                set_window_update(WIN_BTL_SPIRITS_ICON, WINDOW_UPDATE_SHOW);
            }
            set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_SHOW);
            MovesMenuState = BTL_SUBMENU_MOVES_STATE_CHOOSING;
            SelectedMovesIndex = MovesCursorPos;
            return MovesOptionIndexMap[MovesCursorPos] + 1;
        case BTL_SUBMENU_MOVES_STATE_LOCK:
            set_window_update(WIN_BTL_MOVES_MENU, WINDOW_UPDATE_9);
            if (!UsingSpiritsSubmenu) {
                set_window_update(WIN_BTL_MOVES_TITLE, WINDOW_UPDATE_9);
                set_window_update(WIN_BTL_MOVES_ICON, WINDOW_UPDATE_9);
            } else {
                set_window_update(WIN_BTL_SPIRITS_TITLE, WINDOW_UPDATE_9);
                set_window_update(WIN_BTL_SPIRITS_ICON, WINDOW_UPDATE_9);
            }
            set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_HIDE);
            MovesMenuState = BTL_SUBMENU_MOVES_STATE_SELECT;
            break;
        case BTL_SUBMENU_MOVES_STATE_ERROR_INIT:
            SelectedMovesIndex = -1;
            MovesMenuState = BTL_SUBMENU_MOVES_STATE_ERROR_SHOW;
            return POPUP_RESULT_INVALID;
        case BTL_SUBMENU_MOVES_STATE_ERROR_SHOW:
            set_window_update(WIN_BTL_MOVES_MENU, WINDOW_UPDATE_HIDE);
            if (!UsingSpiritsSubmenu) {
                set_window_update(WIN_BTL_MOVES_TITLE, WINDOW_UPDATE_HIDE);
                set_window_update(WIN_BTL_MOVES_ICON, WINDOW_UPDATE_HIDE);
            } else {
                set_window_update(WIN_BTL_SPIRITS_TITLE, WINDOW_UPDATE_HIDE);
                set_window_update(WIN_BTL_SPIRITS_ICON, WINDOW_UPDATE_HIDE);
            }
            set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_HIDE);

            msgID = MSG_Menus_Battle_CantSelectNow;
            if (MovesErrorCode == 0) {
                if (!UsingSpiritsSubmenu) {
                    msgID = MSG_Menus_NotEnoughFP;
                } else {
                    msgID = MSG_Menus_NotEnoughStarPower;
                }
            }

            msgWidth = get_msg_width(msgID, 0) + 23;
            moveX = (SCREEN_WIDTH / 2) - (msgWidth / 2);
#if VERSION_JP
            set_window_properties(WIN_BTL_POPUP, moveX, 80, msgWidth, 28, 20, btl_menu_moves_show_error, nullptr, -1);
#else
            set_window_properties(WIN_BTL_POPUP, moveX, 80, msgWidth, ErrorMessageHeight[get_msg_lines(msgID) - 1], 20, btl_menu_moves_show_error, nullptr, -1);
#endif
            set_window_update(WIN_BTL_POPUP, WINDOW_UPDATE_SHOW);
            MovesErrorTimer = 60;
            MovesMenuState = BTL_SUBMENU_MOVES_STATE_ERROR_DONE;
            return POPUP_RESULT_INVALID;
        case BTL_SUBMENU_MOVES_STATE_ERROR_DONE:
            if (gGameStatusPtr->pressedButtons[0] & (BUTTON_A | BUTTON_B)) {
                MovesErrorTimer = 0;
            }
            if (MovesErrorTimer != 0) {
                MovesErrorTimer--;
                return POPUP_RESULT_INVALID;
            }
            set_window_update(WIN_BTL_POPUP, WINDOW_UPDATE_HIDE);
            set_window_update(WIN_BTL_MOVES_MENU, WINDOW_UPDATE_SHOW);
            if (!UsingSpiritsSubmenu) {
                set_window_update(WIN_BTL_MOVES_TITLE, WINDOW_UPDATE_SHOW);
                set_window_update(WIN_BTL_MOVES_ICON, WINDOW_UPDATE_SHOW);
            } else {
                set_window_update(WIN_BTL_SPIRITS_TITLE, WINDOW_UPDATE_SHOW);
                set_window_update(WIN_BTL_SPIRITS_ICON, WINDOW_UPDATE_SHOW);
            }
            set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_SHOW);
            MovesMenuState = BTL_SUBMENU_MOVES_STATE_CHOOSING;
            break;
    }
    return POPUP_RESULT_CHOOSING;
}

#if VERSION_IQUE
#define MOVE_TEXT_Y 2
#define X_VAR254 153
#define X_VAR255 31
#define FP_COST_X 104
#define SP_COST_X 89
#define HUD_NOT_ENOUGH_FP &HES_NotEnoughFP
#define HUD_FP_COST_X 116
#define HUD_NOT_ENOUGH_POW &HES_NotEnoughPOW
#define HUD_SP_COST_X 102
#define X_VAR3 24
#elif VERSION_PAL
#define MOVE_TEXT_Y 0
#define X_VAR254 169
#define X_VAR255 31
#define FP_COST_X 108 + D_PAL_802AB4E8[gCurrentLanguage]
#define SP_COST_X 93 + D_PAL_802AB4D0[gCurrentLanguage]
#define HUD_NOT_ENOUGH_FP D_PAL_802AB52C[gCurrentLanguage]
#define HUD_FP_COST_X 116 + D_PAL_802AB4E8[gCurrentLanguage]
#define HUD_NOT_ENOUGH_POW D_PAL_802AB56C[gCurrentLanguage]
#define HUD_SP_COST_X 102 + D_PAL_802AB4D0[gCurrentLanguage]
#define X_VAR3 24
#elif VERSION_JP
#define MOVE_TEXT_Y 0
#define X_VAR254 139
#define X_VAR255 35
#define X_VAR3 26
#else
#define MOVE_TEXT_Y 0
#define X_VAR254 153
#define X_VAR255 31
#define FP_COST_X 108
#define SP_COST_X 93
#define HUD_NOT_ENOUGH_FP &HES_NotEnoughFP
#define HUD_FP_COST_X 116
#define HUD_NOT_ENOUGH_POW &HES_NotEnoughPOW
#define HUD_SP_COST_X 102
#define X_VAR3 24
#endif

void btl_menu_moves_draw_content(void* data, s32 x, s32 y) {
    s32 var_t0;
    s32 temp_f6;
    s32 xPos, yPos;
    s32 yRenderPos;
    s32 palette;
    s32 num;
    s32 v0;
    s32 a0;
    s32 idx;
    s32 id;
    s32 i;

    switch (MovesMenuState) {
        case BTL_SUBMENU_MOVES_STATE_SELECT:
        case BTL_SUBMENU_MOVES_STATE_CHOOSING:
        case BTL_SUBMENU_MOVES_STATE_HIDE_INIT:
        case BTL_SUBMENU_MOVES_STATE_RESTORE:
        case BTL_SUBMENU_MOVES_STATE_LOCK:
        case BTL_SUBMENU_MOVES_STATE_ERROR_INIT:
        case BTL_SUBMENU_MOVES_STATE_ERROR_SHOW:
            yPos = -MovesVisibleStart * 13;
            var_t0 = MovesScrollOffset;
            temp_f6 = (yPos - var_t0) * 0.5;
            if (temp_f6 == 0) {
                var_t0 = yPos;
            } else {
                var_t0 += temp_f6;
            }
            MovesScrollOffset = var_t0;

            xPos = x + 2;
            yPos = y + 18;
            var_t0 = yPos + 1 + (MovesMenuLines * 13);
            gDPSetScissor(
                gMainGfxPos++, G_SC_NON_INTERLACE,
                xPos,
                yPos,
                x + X_VAR254,
                var_t0
            );

            xPos = x + X_VAR255;
            yPos = y + 19 + MovesScrollOffset;

            idx = 0;
            for (i = 0; i < MovesOptionCount; i++, idx++) {
                if (i >= MovesVisibleStart - 1 && MovesVisibleStart + MovesMenuLines >= i) {
                    palette = MovesTextColor;

                    if (MovesOptionEnabled[MovesOptionIndexMap[idx]] <= 0) {
                        palette = MSG_PAL_0B;
                    }

                    if (MovesOptionNames[MovesOptionIndexMap[idx]] >= 0) {
                        draw_msg(
                            MovesOptionNames[MovesOptionIndexMap[idx]],
                            xPos, yPos - MOVE_TEXT_Y, MovesTextAlpha, palette, 1
                        );
                    }

#if VERSION_JP
                    a0 = MovesOptionDiscounts[MovesOptionIndexMap[idx]];
                    if (MovesOptionEnabled[MovesOptionIndexMap[idx]] <= 0) {
                        v0 = MovesOptionDisplayCosts[MovesOptionIndexMap[idx]];
                    } else {
                        v0 = MovesOptionDisplayCosts[MovesOptionIndexMap[idx]];
                    }
#else
                    if (MovesOptionEnabled[MovesOptionIndexMap[idx]] <= 0) {
                        a0 = MovesOptionDiscounts[MovesOptionIndexMap[idx]];
                        do {} while (0);
                        v0 = MovesOptionDisplayCosts[MovesOptionIndexMap[idx]];
                    } else {
                        a0 = MovesOptionDiscounts[MovesOptionIndexMap[idx]];
                        do {} while (0);
                        v0 = MovesOptionDisplayCosts[MovesOptionIndexMap[idx]];
                    }
#endif
                    num = v0 - a0;

                    if (v0 != 0 && num <= 0) {
                        num = 1;
                    }

                    if (!UsingSpiritsSubmenu ) {
                        if (i == MovesCursorPos) {
                            if (num == 0 || MovesOptionEnabled[MovesOptionIndexMap[idx]] <= 0) {
                                status_bar_stop_blinking_fp();
                            } else {
                                status_bar_start_blinking_fp();
                            }
                        }
                    } else {
                        if (i == MovesCursorPos) {
                            if (num == 0 || MovesOptionEnabled[MovesOptionIndexMap[idx]] <= 0) {
                                status_bar_stop_blinking_sp();
                            } else {
                                a0 = MovesOptionDisplayCosts[MovesOptionIndexMap[idx]];
                                status_bar_start_blinking_sp_bars(
                                    MovesOptionDisplayCosts[MovesOptionIndexMap[idx]]
                                );
                            }
                        }
                    }

                    switch (MovesOptionDiscountColors[i]) {
                        case 0:
                            palette = MSG_PAL_STANDARD;
                            break;
                        case 1:
                            palette = MSG_PAL_37;
                            break;
                        default:
                            palette = MSG_PAL_38;
                            break;
                    }

                    if (MovesOptionEnabled[MovesOptionIndexMap[idx]] <= 0) {
                        palette = MSG_PAL_0B;
                    }

                    if (MovesOptionDisplayCosts[MovesOptionIndexMap[idx]] != 0) {
#if VERSION_JP
                        draw_number(
                            num, xPos + 91, yPos, DRAW_NUMBER_CHARSET_THIN, palette, MovesTextAlpha,
                            DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT
                        );

                        id = MovesOptionCostHIDs[idx];
                        if (MovesOptionEnabled[MovesOptionIndexMap[idx]] <= 0) {
                            if (!UsingSpiritsSubmenu) {
                                hud_element_set_script(id, &HES_NotEnoughFP);
                            } else {
                                hud_element_set_script(id, &HES_NotEnoughPOW);
                            }
                        }
                        yRenderPos = yPos + 7;
                        hud_element_set_render_pos(id, xPos + 100, yRenderPos);
#else
                        id = MovesOptionCostHIDs[idx];

                        if (!UsingSpiritsSubmenu) {
                            draw_number(
                                num, xPos + FP_COST_X, yPos, DRAW_NUMBER_CHARSET_THIN, palette, MovesTextAlpha,
                                DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT
                            );
                            if (MovesOptionEnabled[MovesOptionIndexMap[idx]] <= 0) {
                                hud_element_set_script(id, HUD_NOT_ENOUGH_FP);
                            }
                            yRenderPos = yPos + 7;
                            hud_element_set_render_pos(id, xPos + HUD_FP_COST_X, yRenderPos);
                        } else {
                            draw_number(
                                num, xPos + SP_COST_X, yPos, DRAW_NUMBER_CHARSET_THIN, palette, MovesTextAlpha,
                                DRAW_NUMBER_STYLE_MONOSPACE | DRAW_NUMBER_STYLE_ALIGN_RIGHT
                            );
                            if (MovesOptionEnabled[MovesOptionIndexMap[idx]] <= 0) {
                                hud_element_set_script(id, HUD_NOT_ENOUGH_POW);
                            }
                            yRenderPos = yPos + 7;
                            hud_element_set_render_pos(id, xPos + HUD_SP_COST_X, yRenderPos);
                        }
#endif
                        hud_element_set_alpha(id, MovesTextAlpha);
                        hud_element_draw_without_clipping(id);
                    }
                }
                yPos += 13;
            }

            xPos = x + X_VAR3;
            yPos = MovesScrollOffset + y + 24;

            idx = 0;
            for (i = 0; i < MovesOptionCount; i++, idx++) {
                if (i < MovesVisibleStart - 1) {
                    yPos += 13;
                } else if (MovesVisibleStart + MovesMenuLines < i) {
                    yPos += 13;
                } else {
                    id = MovesOptionHIDs[idx];
                    hud_element_set_render_pos(id, xPos, yPos);
                    hud_element_set_alpha(id, MovesTextAlpha);
                    hud_element_draw_without_clipping(id);
                    yPos += 13;
                }
            }

            yPos = (MovesCursorPos - MovesVisibleStart) * 13;
            var_t0 = MovesCursorOffset;
            temp_f6 = (yPos - MovesCursorOffset) * 1.0;
            xPos = x + 10;
            if (temp_f6 != 0) {
                var_t0 += temp_f6;
            } else {
                var_t0 = yPos;
            }
            MovesCursorOffset = var_t0;
            yPos =  y + 26 + MovesCursorOffset;

            id = HID_MovesCursor;
            hud_element_set_render_pos(id, xPos, yPos);
            hud_element_set_alpha(id, MovesTextAlpha);
            hud_element_draw_without_clipping(id);

            if (MovesVisibleStart > 0) {
                id = HID_MovesArrowUp;
                hud_element_set_render_pos(id, x + 72, y + 15);
                hud_element_set_alpha(id, MovesTextAlpha);
                hud_element_draw_clipped(id);
            }

            if (MovesVisibleEnd < MovesOptionCount) {
                id = HID_MovesArrowDown;
                hud_element_set_render_pos(id, x + 72, y + 100);
                hud_element_set_alpha(id, MovesTextAlpha);
                hud_element_draw_clipped(id);
            }

            if (MovesMenuState == -1) {
                if (!UsingSpiritsSubmenu) {
                    status_bar_stop_blinking_fp();
                } else {
                    status_bar_stop_blinking_sp();
                }
            }
            break;
    }
}


#if VERSION_PAL
#define TEXT_ABILITIES_X D_PAL_802AB4F4[gCurrentLanguage]
#define TEXT_STAR_SPIRITS_X D_PAL_802AB4E0[gCurrentLanguage]
#elif VERSION_JP
#define TEXT_ABILITIES_X 28
#define TEXT_STAR_SPIRITS_X 24
#else
#define TEXT_ABILITIES_X 16
#define TEXT_STAR_SPIRITS_X 6
#endif

void btl_menu_moves_show_title(void* data, s32 x, s32 y) {
    if (!UsingSpiritsSubmenu) {
        draw_msg(MSG_Menus_Abilities, x + TEXT_ABILITIES_X, y + 2, MovesTextAlpha, MSG_PAL_30, DRAW_MSG_STYLE_MENU);
    } else {
        draw_msg(MSG_Menus_StarSpirits, x + TEXT_STAR_SPIRITS_X, y + 2, MovesTextAlpha, MSG_PAL_31, DRAW_MSG_STYLE_MENU);
    }
}

void btl_menu_moves_show_icon(void* data, s32 x, s32 y) {
    s32 icon = HID_MovesTitle;

    hud_element_set_render_pos(icon, x + 16, y + 15);
    hud_element_set_alpha(icon, MovesTextAlpha);
    hud_element_draw_clipped(icon);
}

void btl_menu_moves_show_desc(void* data, s32 x, s32 y) {
    switch (MovesMenuState) {
        case BTL_SUBMENU_MOVES_STATE_SELECT:
        case BTL_SUBMENU_MOVES_STATE_CHOOSING:
        case BTL_SUBMENU_MOVES_STATE_HIDE_INIT:
        case BTL_SUBMENU_MOVES_STATE_RESTORE:
        case BTL_SUBMENU_MOVES_STATE_LOCK:
            if (MovesDescVisible != 0) {
                draw_msg(MovesOptionDesc[MovesOptionIndexMap[MovesCursorPos]],
                            x + 8, y, MovesTextAlpha, MovesTextColor, 0);
            }
            break;
    }
}

void btl_menu_moves_show_error(void* data, s32 x, s32 y) {
#if VERSION_JP
    s32 posX = x + 11;
    s32 posY = y + 6;

    if (MovesErrorCode != 0) {
        draw_msg(MSG_Menus_Battle_CantSelectNow, posX, posY, 255, MSG_PAL_0F, 0);
    } else if (!UsingSpiritsSubmenu) {
        draw_msg(MSG_Menus_NotEnoughFP, posX, posY, 255, MSG_PAL_0F, 0);
    } else {
        draw_msg(MSG_Menus_NotEnoughStarPower, posX, posY, 255, MSG_PAL_0F, 0);
    }
#else
    s32 posY = y;
    s32 posX;
    s32 msgID;

    posY += 6;
    posX = x + 11;

    if (MovesErrorCode != 0) {
        msgID = MSG_Menus_Battle_CantSelectNow;
    } else if (!UsingSpiritsSubmenu) {
        msgID = MSG_Menus_NotEnoughFP;
    } else {
        msgID = MSG_Menus_NotEnoughStarPower;
    }
    draw_msg(msgID, posX, posY + ErrorMessageAdjustY[get_msg_lines(msgID) - 1], 255, MSG_PAL_0F, 0);
#endif
}

void btl_menu_strats_init(void) {
    s32 sixTemp;
    s8 temp802AD673;

    StratsMenuState = BTL_SUBMENU_STRATS_STATE_INIT;
    StratsCursorPos = StratsPrevSelected;
    StratsPrevCursorPos = StratsPrevSelected;
    StratsVisibleStart = 0;
    StratsMenuLines = StratsOptionCount;

    if (StratsMenuLines > 6) {
        StratsMenuLines = 6;
    }

    StratsVisibleEnd = sixTemp = 6;

    if (StratsVisibleEnd > StratsOptionCount) {
        StratsVisibleEnd = StratsOptionCount;
    }

    StratsTextAlpha = 255;
    StratsDescVisible = 1;
    temp802AD673 = StratsPrevSelected;

    if ((s8) StratsPrevSelected < 0) {
        StratsVisibleStart = StratsPrevSelected;
    }
    if ((s8) StratsPrevSelected >= StratsVisibleEnd) {
        StratsVisibleStart = (temp802AD673 + 1 - StratsMenuLines);
    }

    StratsVisibleEnd = StratsVisibleStart + sixTemp;
    if (StratsVisibleEnd > StratsOptionCount) {
        StratsVisibleEnd = StratsOptionCount;
    }

    StratsScrollOffset = -StratsVisibleStart * 13;
    StratsCursorOffset = ((s8) StratsPrevSelected - StratsVisibleStart) * 13;
    ShowingErrorMessage = false;
    D_802AD6D4 = 0;
}

void btl_submenu_strats_hide(void) {
    StratsMenuState = BTL_SUBMENU_STRATS_STATE_HIDE_INIT;
}

void btl_submenu_strats_destroy(void) {
    s32 i;

    set_window_update(WIN_BTL_STRATS_MENU, WINDOW_UPDATE_HIDE);
    set_window_update(WIN_BTL_STRATS_TITLE, WINDOW_UPDATE_HIDE);
    set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_HIDE);

    for (i = 0; i < StratsOptionCount; i++) {
        hud_element_free(StratsOptionHIDs[i]);
    }

    hud_element_free(HID_StratsCursor);
    hud_element_free(HID_StratsArrowUp);
    hud_element_free(HID_StratsArrowDown);
}

void btl_submenu_strats_resume_choose(void) {
    s32 i;

    for (i = 0; i < StratsOptionCount; i++) {
        hud_element_set_tint(StratsOptionHIDs[i], 255, 255, 255);
    }

    hud_element_set_tint(HID_StratsCursor, 255, 255, 255);
    hud_element_set_tint(HID_StratsArrowUp, 255, 255, 255);
    hud_element_set_tint(HID_StratsArrowDown, 255, 255, 255);
    hud_element_set_script(HID_StratsCursor, &HES_AnimatedHandPointer);
    set_window_update(WIN_BTL_STRATS_MENU, WINDOW_UPDATE_TRANSPARENT);
    set_window_update(WIN_BTL_STRATS_TITLE, WINDOW_UPDATE_TRANSPARENT);
    set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_SHOW);
    StratsTextColor = MSG_PAL_STANDARD;
    StratsDescVisible = 1;
    StratsTextAlpha = 255;
    StratsMenuState = BTL_SUBMENU_STRATS_STATE_CHOOSING;
}

void btl_submenu_strats_restore_choose(void) {
    s32 i;

    set_window_update(WIN_BTL_STRATS_MENU, WINDOW_UPDATE_TRANSPARENT);
    set_window_update(WIN_BTL_STRATS_TITLE, WINDOW_UPDATE_TRANSPARENT);
    set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_SHOW);

    for (i = 0; i < StratsOptionCount; i++) {
        hud_element_set_tint(StratsOptionHIDs[i], 255, 255, 255);
    }

    hud_element_set_tint(HID_StratsCursor, 255, 255, 255);
    hud_element_set_tint(HID_StratsArrowUp, 255, 255, 255);
    hud_element_set_tint(HID_StratsArrowDown, 255, 255, 255);
    hud_element_set_script(HID_StratsCursor, &HES_AnimatedHandPointer);
    StratsTextColor = MSG_PAL_STANDARD;
    StratsDescVisible = 1;
    StratsMenuState = BTL_SUBMENU_STRATS_STATE_RESTORE;
}

void btl_submenu_strats_restore_locked(void) {
    set_window_update(WIN_BTL_STRATS_MENU, WINDOW_UPDATE_TRANSPARENT);
    set_window_update(WIN_BTL_STRATS_TITLE, WINDOW_UPDATE_TRANSPARENT);
    set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_SHOW);
    StratsMenuState = BTL_SUBMENU_STRATS_STATE_LOCK;
}

#if VERSION_JP
#define X_VAR6 10
#define X_VAR7 32
#define W_VAR1 108
#define W_VAR2 88
#define W_VAR3 242
#else
#define X_VAR6 18
#define X_VAR7 20
#define W_VAR1 144
#define W_VAR2 108
#define W_VAR3 280
#endif

s32 btl_submenu_strats_update(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    HudElemID hid;
    s32 x, y;
    s32 width;
    s32 msgID;
    s32 i;

    switch (StratsMenuState) {
        case BTL_SUBMENU_STRATS_STATE_INIT:
#if VERSION_JP
            StratsMenuPosX = 32;
#else
            StratsMenuPosX = 20;
#endif
            StratsMenuPosY = 68;
            StratsScrollOffset = -StratsVisibleStart * 13;
            StratsCursorOffset = (StratsCursorPos - StratsVisibleStart) * 13;

            for (i = 0; i < StratsOptionCount; i++) {
                StratsOptionHIDs[i] = hid = hud_element_create(StratsOptionHudScripts[i]);
                hud_element_set_scale(hid, 0.45f);
                hud_element_set_flags(hid, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_MANUAL_RENDER);
            }

            HID_StratsCursor = hid = hud_element_create(&HES_AnimatedHandPointer);
            hud_element_set_flags(hid, HUD_ELEMENT_FLAG_DROP_SHADOW | HUD_ELEMENT_FLAG_MANUAL_RENDER);
            x = StratsMenuPosX; //! required to match
            y = StratsMenuPosY;
            hud_element_set_render_pos(hid, x, y);

            HID_StratsArrowUp = hid = hud_element_create(&HES_GreenArrowUp);
            hud_element_set_flags(hid, HUD_ELEMENT_FLAG_DROP_SHADOW | HUD_ELEMENT_FLAG_MANUAL_RENDER);
            hud_element_set_render_pos(hid, StratsMenuPosX + 39, StratsMenuPosY - 7);

            HID_StratsArrowDown = hid = hud_element_create(&HES_GreenArrowDown);
            hud_element_set_flags(hid, HUD_ELEMENT_FLAG_DROP_SHADOW | HUD_ELEMENT_FLAG_MANUAL_RENDER);
            hud_element_set_render_pos(hid, StratsMenuPosX + 39, StratsMenuPosY + 78);

            StratsTextColor = MSG_PAL_STANDARD;
            x = StratsMenuPosX;
            y = StratsMenuPosY;
#if VERSION_PAL
            width = get_msg_width(MSG_Menus_Strategies, 0) + 32;
            set_window_properties(WIN_BTL_STRATS_MENU, x, y, D_PAL_802AB4C8[gCurrentLanguage], (StratsMenuLines * 13) + 26,
                0, btl_menu_strats_draw_content, nullptr, -1);
            set_window_properties(WIN_BTL_STRATS_TITLE, x + (D_PAL_802AB4C8[gCurrentLanguage] - width) / 2, y - 6, width, 16,
                1, btl_menu_strats_show_title, nullptr, -1);
#else
            set_window_properties(WIN_BTL_STRATS_MENU, x, y, W_VAR1, (StratsMenuLines * 13) + 26, 0, btl_menu_strats_draw_content, nullptr, -1);
            set_window_properties(WIN_BTL_STRATS_TITLE, x + X_VAR6, y - 6, W_VAR2, 16, 1, btl_menu_strats_show_title, nullptr, -1);
#endif
            x = X_VAR7;
            y = 186;
            set_window_properties(WIN_BTL_DESC_BOX, x, y, W_VAR3, 32, WINDOW_PRIORITY_20, btl_menu_strats_show_desc, nullptr, -1);
            set_window_update(WIN_BTL_STRATS_MENU, WINDOW_UPDATE_SHOW);
            set_window_update(WIN_BTL_STRATS_TITLE, WINDOW_UPDATE_SHOW);
            set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_SHOW);
            StratsMenuState = BTL_SUBMENU_STRATS_STATE_CHOOSING;
            return POPUP_RESULT_CHOOSING;
        case BTL_SUBMENU_STRATS_STATE_CHOOSING:
            if (!ShowingErrorMessage) {
                StratsPrevCursorPos = StratsCursorPos;

                // only wrap selection on stick press, not when held
                if (battleStatus->curButtonsHeld & BUTTON_STICK_UP) {
                    if (StratsCursorPos > 0) {
                        StratsCursorPos--;
                    } else if (battleStatus->curButtonsPressed & BUTTON_STICK_UP) {
                        StratsCursorPos--;
                    }
                }

                if (battleStatus->curButtonsHeld & BUTTON_STICK_DOWN) {
                    if (StratsCursorPos < StratsOptionCount - 1) {
                        StratsCursorPos++;
                    } else if (battleStatus->curButtonsPressed & BUTTON_STICK_DOWN) {
                        StratsCursorPos++;
                    }
                }

                // wrap the selected index
                if (StratsCursorPos < 0) {
                    StratsCursorPos = StratsOptionCount - 1;
                }
                if (StratsOptionCount - 1 < StratsCursorPos) {
                    StratsCursorPos = 0;
                }

                if (StratsPrevCursorPos != StratsCursorPos) {
                    hud_element_set_scale(StratsOptionHIDs[StratsPrevCursorPos], 0.45f);
                    sfx_play_sound(SOUND_MENU_CHANGE_SELECTION);
                }

                if (StratsCursorPos < StratsVisibleStart) {
                    StratsVisibleStart = StratsCursorPos;
                }
                if (StratsCursorPos >= StratsVisibleEnd) {
                    StratsVisibleStart = StratsCursorPos + 1 - StratsMenuLines;
                }
                StratsVisibleEnd = StratsVisibleStart + 6;
                if (StratsVisibleEnd > StratsOptionCount) {
                    StratsVisibleEnd = StratsOptionCount;
                }

                if (battleStatus->curButtonsPressed & BUTTON_A) {
                    if (StratsOptionEnabled[StratsCursorPos] == 1) {
                        sfx_play_sound(SOUND_MENU_NEXT);
                        StratsMenuState = BTL_SUBMENU_STRATS_STATE_SELECT;
                    } else {
                        sfx_play_sound(SOUND_MENU_ERROR);
                        StratsMenuState = BTL_SUBMENU_STRATS_STATE_ERROR_INIT;
                        StratsErrorCode = StratsOptionError[StratsCursorPos];
                    }
                } else if (battleStatus->curButtonsPressed & BUTTON_B) {
                    sfx_play_sound(SOUND_MENU_BACK);
                    btl_submenu_strats_destroy();
                    StratsMenuState = BTL_SUBMENU_STRATS_STATE_CANCEL;
                }
            }
            return POPUP_RESULT_CHOOSING;
        case BTL_SUBMENU_STRATS_STATE_SELECT:
            for (i = 0; i < StratsOptionCount; i++) {
                hud_element_set_tint(StratsOptionHIDs[i], 160, 160, 160);
            }
            hud_element_set_tint(HID_StratsCursor, 160, 160, 160);
            hud_element_set_tint(HID_StratsArrowUp, 160, 160, 160);
            hud_element_set_tint(HID_StratsArrowDown, 160, 160, 160);
            hud_element_set_script(HID_StratsCursor, &HES_HandPointer);
            StratsTextColor = MSG_PAL_0D;
            set_window_update(WIN_BTL_STRATS_MENU, WINDOW_UPDATE_DARKENED);
            set_window_update(WIN_BTL_STRATS_TITLE, WINDOW_UPDATE_DARKENED);
            set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_HIDE);
            return StratsCursorPos + 1;
        case BTL_SUBMENU_STRATS_STATE_CANCEL:
            return POPUP_RESULT_CANCEL;
        case BTL_SUBMENU_STRATS_STATE_HIDE_INIT:
            set_window_update(WIN_BTL_STRATS_MENU, WINDOW_UPDATE_HIDE);
            set_window_update(WIN_BTL_STRATS_TITLE, WINDOW_UPDATE_HIDE);
            set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_HIDE);
            StratsMenuState = BTL_SUBMENU_STRATS_STATE_HIDE_HOLD;
            return StratsCursorPos + 1;
        case BTL_SUBMENU_STRATS_STATE_HIDE_HOLD:
            return StratsCursorPos + 1;
        case BTL_SUBMENU_STRATS_STATE_RESTORE:
            set_window_update(WIN_BTL_STRATS_MENU, WINDOW_UPDATE_SHOW);
            set_window_update(WIN_BTL_STRATS_TITLE, WINDOW_UPDATE_SHOW);
            set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_SHOW);
            StratsMenuState = BTL_SUBMENU_STRATS_STATE_CHOOSING;
            return StratsCursorPos + 1;
        case BTL_SUBMENU_STRATS_STATE_LOCK:
            set_window_update(WIN_BTL_STRATS_MENU, WINDOW_UPDATE_SHOW);
            set_window_update(WIN_BTL_STRATS_TITLE, WINDOW_UPDATE_SHOW);
            set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_SHOW);
            StratsMenuState = BTL_SUBMENU_STRATS_STATE_SELECT;
            return POPUP_RESULT_CHOOSING;
        case BTL_SUBMENU_STRATS_STATE_ERROR_INIT:
            D_802AD6D4 = -1;
            StratsMenuState = BTL_SUBMENU_STRATS_STATE_ERROR_SHOW;
            return POPUP_RESULT_INVALID;
        case BTL_SUBMENU_STRATS_STATE_ERROR_SHOW:
            set_window_update(WIN_BTL_STRATS_MENU, WINDOW_UPDATE_HIDE);
            set_window_update(WIN_BTL_STRATS_TITLE, WINDOW_UPDATE_HIDE);
            set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_HIDE);
            switch (StratsErrorCode) {
                case 0:
                    msgID = MSG_Menus_Battle_CantSwitch2;
                    break;
                case 1:
                    msgID = MSG_Menus_Battle_CantRunAway;
                    break;
                default:
                    msgID = MSG_Menus_Battle_CantRunAway;
                    break;
            }
            width = get_msg_width(msgID, 0) + 23;
            x = (SCREEN_WIDTH / 2) - (width / 2);
#if VERSION_PAL
            set_window_properties(WIN_BTL_POPUP, x, 80, width, ErrorMessageHeight[get_msg_lines(msgID) - 1],
                20, btl_menu_strats_show_error, nullptr, -1);
#else
            set_window_properties(WIN_BTL_POPUP, x, 80, width, 28, 20, btl_menu_strats_show_error, nullptr, -1);
#endif
            set_window_update(WIN_BTL_POPUP, WINDOW_UPDATE_SHOW);
            StratsErrorTimer = 60;
            StratsMenuState = BTL_SUBMENU_STRATS_STATE_ERROR_DONE;
            return POPUP_RESULT_INVALID;
        case BTL_SUBMENU_STRATS_STATE_ERROR_DONE:
            if (gGameStatusPtr->pressedButtons[0] & (BUTTON_A | BUTTON_B)) {
                StratsErrorTimer = 0;
            }
            if (StratsErrorTimer != 0) {
                StratsErrorTimer--;
                return POPUP_RESULT_INVALID;
            }
            set_window_update(WIN_BTL_POPUP, WINDOW_UPDATE_HIDE);
            set_window_update(WIN_BTL_STRATS_MENU, WINDOW_UPDATE_SHOW);
            set_window_update(WIN_BTL_STRATS_TITLE, WINDOW_UPDATE_SHOW);
            set_window_update(WIN_BTL_DESC_BOX, WINDOW_UPDATE_SHOW);
            StratsMenuState = BTL_SUBMENU_STRATS_STATE_CHOOSING;
            return POPUP_RESULT_CHOOSING;
    }
    return POPUP_RESULT_CHOOSING;
}

#if VERSION_IQUE
#define STRATS_OPTION_Y 3
#define STRATS_SUBMENU_WIDTH 142
#elif VERSION_PAL
#define STRATS_OPTION_Y 0
#define STRATS_SUBMENU_WIDTH 182
#elif VERSION_JP
#define STRATS_OPTION_Y 0
#define STRATS_SUBMENU_WIDTH 106
#else
#define STRATS_OPTION_Y 0
#define STRATS_SUBMENU_WIDTH 142
#endif

void btl_menu_strats_draw_content(void* data, s32 x, s32 y) {
    s32 var_t0;
    s32 temp_f6;
    s32 xPos, yPos;
    s32 idx;
    s32 id;
    s32 i;

    switch (StratsMenuState) {
        case BTL_SUBMENU_STRATS_STATE_SELECT:
        case BTL_SUBMENU_STRATS_STATE_CHOOSING:
        case BTL_SUBMENU_STRATS_STATE_HIDE_INIT:
        case BTL_SUBMENU_STRATS_STATE_RESTORE:
        case BTL_SUBMENU_STRATS_STATE_LOCK:
        case BTL_SUBMENU_STRATS_STATE_ERROR_INIT:
        case BTL_SUBMENU_STRATS_STATE_ERROR_SHOW:
            yPos = -StratsVisibleStart * 13;
            var_t0 = StratsScrollOffset;
            temp_f6 = (yPos - var_t0) * 0.5;
            if (temp_f6 != 0) {
                var_t0 += temp_f6;
            } else {
                var_t0 = yPos;
            }
            StratsScrollOffset = var_t0;

            xPos = x + 4;
            yPos = y + 18;
            var_t0 = yPos + 1 + (StratsMenuLines * 13);
            gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, xPos, yPos, x + STRATS_SUBMENU_WIDTH, var_t0);

            xPos = x + 33;
            yPos = y + 19 + StratsScrollOffset;

            idx = 0;
            for (i = 0; i < StratsOptionCount; i++, idx++) {
                s32 palette = StratsTextColor;

                if (StratsOptionMenuTypes[i] == 5 && is_ability_active(ABILITY_QUICK_CHANGE)) {
                    palette = MSG_PAL_37;
                }
                if (StratsOptionEnabled[idx] == 0) {
                    palette = MSG_PAL_0B;
                }
                draw_msg(StratsOptionNames[idx], xPos, yPos - STRATS_OPTION_Y, StratsTextAlpha, palette, DRAW_MSG_STYLE_MENU);
                yPos += 13;
            }

            xPos = x + 24;
            yPos = StratsScrollOffset + y + 24;

            idx = 0;
            for (i = 0; i < StratsOptionCount; i++, idx++) {
                id = StratsOptionHIDs[idx];
                hud_element_set_render_pos(id, xPos, yPos);
                hud_element_set_alpha(id, StratsTextAlpha);
                hud_element_draw_without_clipping(id);
                yPos += 13;
            }

            yPos = (StratsCursorPos - StratsVisibleStart) * 13;
            var_t0 = StratsCursorOffset;
            temp_f6 = (yPos - var_t0) * 1.0;
            xPos = x + 10;
            if (temp_f6 != 0) {
                var_t0 += temp_f6;
            } else {
                var_t0 = yPos;
            }
            StratsCursorOffset = var_t0;
            yPos = y + 26 + StratsCursorOffset;

            id = HID_StratsCursor;
            hud_element_set_render_pos(id, xPos, yPos);
            hud_element_set_alpha(id, StratsTextAlpha);
            hud_element_draw_clipped(id);

            if (StratsVisibleStart > 0) {
                id = HID_StratsArrowUp;
                hud_element_set_render_pos(id, x + 67, y + 16);
                hud_element_set_alpha(id, StratsTextAlpha);
                hud_element_draw_clipped(id);
            }
            if (StratsVisibleEnd < StratsOptionCount) {
                id = HID_StratsArrowDown;
                hud_element_set_render_pos(id, x + 67, y + 100);
                hud_element_set_alpha(id, StratsTextAlpha);
                hud_element_draw_clipped(id);
            }
            break;
    }
}

#if VERSION_JP
#define X_VAR9 27
#else
#define X_VAR9 15
#endif

void btl_menu_strats_show_title(void* data, s32 x, s32 y) {
    draw_msg(MSG_Menus_Strategies, x + X_VAR9, y + 2, StratsTextAlpha, MSG_PAL_33, DRAW_MSG_STYLE_MENU);
}

void btl_menu_strats_show_desc(void* data, s32 x, s32 y) {
    switch (StratsMenuState) {
        case BTL_SUBMENU_STRATS_STATE_SELECT:
        case BTL_SUBMENU_STRATS_STATE_CHOOSING:
        case BTL_SUBMENU_STRATS_STATE_HIDE_INIT:
        case BTL_SUBMENU_STRATS_STATE_RESTORE:
        case BTL_SUBMENU_STRATS_STATE_LOCK:
            if (StratsDescVisible != 0) {
                draw_msg(StratsOptionMessage[StratsCursorPos], x + 8, y, StratsTextAlpha, StratsTextColor, 0);
            }
            break;
    }
}

void btl_menu_strats_show_error(void* data, s32 x, s32 y) {
    s32 msgID;
    x += 11;
    y += 6;

    switch (StratsErrorCode) {
        case 0:
            msgID = MSG_Menus_Battle_CantSwitch2;
            break;
        case 1:
            msgID = MSG_Menus_Battle_CantRunAway;
            break;
        default:
            msgID = MSG_Menus_Battle_CantRunAway;
            break;
    }
#if VERSION_PAL
    y += ErrorMessageAdjustY[get_msg_lines(msgID) - 1];
#endif
    draw_msg(msgID, x, y, 255, MSG_PAL_0F, 0);
}

s32 btl_player_can_act(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;

    if (battleStatus->flags2 & BS_FLAGS2_PLAYER_TURN_USED) {
        return false;
    } else {
        s8 debuff = player->debuff;
        s32 playerCantMove = false;

        if (player->koStatus == STATUS_KEY_KO) {
            playerCantMove = true;
        }
        if (debuff == STATUS_KEY_POISON) {
            playerCantMove = false;
        }
        if (debuff == STATUS_KEY_SHRINK) {
            playerCantMove = false;
        }
        if (debuff == STATUS_KEY_SLEEP) {
            playerCantMove = true;
        }
        if (debuff == STATUS_KEY_UNUSED) {
            playerCantMove = true;
        }
        if (debuff == STATUS_KEY_DIZZY) {
            playerCantMove = true;
        }
        if (debuff == STATUS_KEY_PARALYZE) {
            playerCantMove = true;
        }
        if (debuff == STATUS_KEY_FROZEN) {
            playerCantMove = true;
        }
        if (debuff == STATUS_KEY_STOP) {
            playerCantMove = true;
        }
        if (player->stoneStatus == STATUS_KEY_STONE) {
            playerCantMove = true;
        }
        if (battleStatus->outtaSightActive) {
            playerCantMove = true;
        }
        return !playerCantMove;
    }
}

#if VERSION_JP
s32 btl_menu_can_player_move(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s8 debuff = player->debuff;
    s32 playerCantMove = false;

    if (player->koStatus == STATUS_KEY_KO) {
        playerCantMove = true;
    }
    if (debuff == STATUS_KEY_POISON) {
        playerCantMove = false;
    }
    if (debuff == STATUS_KEY_SHRINK) {
        playerCantMove = false;
    }
    if (debuff == STATUS_KEY_SLEEP) {
        playerCantMove = true;
    }
    if (debuff == STATUS_KEY_UNUSED) {
        playerCantMove = true;
    }
    if (debuff == STATUS_KEY_DIZZY) {
        playerCantMove = true;
    }
    if (debuff == STATUS_KEY_PARALYZE) {
        playerCantMove = true;
    }
    if (debuff == STATUS_KEY_FROZEN) {
        playerCantMove = true;
    }
    if (debuff == STATUS_KEY_STOP) {
        playerCantMove = true;
    }
    if (player->stoneStatus == STATUS_KEY_STONE) {
        playerCantMove = true;
    }
    if (battleStatus->outtaSightActive) {
        playerCantMove = true;
    }
    return !playerCantMove;
}
#endif

extern s32 MenuIndexFromPartnerID[]; // TODO MOVE

s32 btl_partner_can_act(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    s8 partnerDebuff;
    s32 partnerCantMove;

    if (battleStatus->flags2 & BS_FLAGS2_PARTNER_TURN_USED || partner == PARTNER_NONE || partner->flags & ACTOR_FLAG_NO_ATTACK) {
        return false;
    }

    partnerDebuff = partner->debuff;
    partnerCantMove = false;

    if (partner->koStatus == STATUS_KEY_KO) {
        partnerCantMove = true;
    }
    if (partnerDebuff == STATUS_KEY_POISON) {
        partnerCantMove = false;
    }
    if (partnerDebuff == STATUS_KEY_SHRINK) {
        partnerCantMove = false;
    }
    if (partnerDebuff == STATUS_KEY_SLEEP) {
        partnerCantMove = true;
    }
    if (partnerDebuff == STATUS_KEY_UNUSED) {
        partnerCantMove = true;
    }
    if (partnerDebuff == STATUS_KEY_PARALYZE) {
        partnerCantMove = true;
    }
    if (partnerDebuff == STATUS_KEY_FROZEN) {
        partnerCantMove = true;
    }
    if (partnerDebuff == STATUS_KEY_STOP) {
        partnerCantMove = true;
    }
    if (partner->stoneStatus == STATUS_KEY_STONE) {
        partnerCantMove = true;
    }
    return !partnerCantMove;
}

void btl_state_update_player_menu(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* playerActor = battleStatus->playerActor;
    Actor* partnerActor = battleStatus->partnerActor;
    PopupMenu* popup = &BattlePopupMenu;
    MoveData* moveData;
    s32 entryIdx, initialPos;
    s32 i;
    s32 submenuResult;
    s32 jumpTargetCount, hammerTargetCount, jumpChance;
    ItemData* itemData;
    s32 starBeamLevel;
    s32 currentSubmenu;
    s32 currentSubmenu2;
    IconHudScriptPair* hudScriptPair;
    PartnerPopupProperties* prop;

    switch (gBattleSubState) {
        case BTL_SUBSTATE_PLAYER_MENU_INIT:
            battleStatus->moveCategory = BTL_MENU_TYPE_INVALID;
            battleStatus->selectedMoveID = 0;
            battleStatus->curAttackElement = 0;
            if (!btl_player_can_act()) {
                btl_set_state(BATTLE_STATE_END_PLAYER_TURN);
                return;
            }
            btl_cam_use_preset(BTL_CAM_DEFAULT);
            btl_cam_move(10);
            if (!(battleStatus->flags1 & BS_FLAGS1_PLAYER_IN_BACK)) {
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_CREATE_MAIN_MENU;
            } else {
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_PERFORM_SWAP;
                partnerActor->state.curPos.x = partnerActor->homePos.x;
                partnerActor->state.curPos.z = partnerActor->homePos.z;
                partnerActor->state.goalPos.x = playerActor->homePos.x;
                partnerActor->state.goalPos.z = playerActor->homePos.z;
                partnerActor->state.moveTime = 4;
                partnerActor->state.angle = 0.0f;
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_PERFORM_SWAP:
            if (partnerActor->state.moveTime != 0) {
                partnerActor->curPos.x += (partnerActor->state.goalPos.x - partnerActor->curPos.x) / partnerActor->state.moveTime;
                partnerActor->curPos.z += (partnerActor->state.goalPos.z - partnerActor->curPos.z) / partnerActor->state.moveTime;
                playerActor->curPos.x += (partnerActor->state.curPos.x - playerActor->curPos.x) / partnerActor->state.moveTime;
                playerActor->curPos.z += (partnerActor->state.curPos.z - playerActor->curPos.z) / partnerActor->state.moveTime;
            }
            partnerActor->curPos.z -= sin_rad(DEG_TO_RAD(partnerActor->state.angle)) * 16.0f;
            partnerActor->yaw = clamp_angle(-partnerActor->state.angle);
            playerActor->curPos.z += sin_rad(DEG_TO_RAD(partnerActor->state.angle)) * 16.0f;
            playerActor->yaw = clamp_angle(-partnerActor->state.angle);
            partnerActor->state.angle += 90.0f;
            if (partnerActor->state.moveTime != 0) {
                partnerActor->state.moveTime--;
            } else {
                partnerActor->curPos.x = partnerActor->state.goalPos.x;
                partnerActor->curPos.z = partnerActor->state.goalPos.z;
                playerActor->curPos.x = partnerActor->state.curPos.x;
                playerActor->curPos.z = partnerActor->state.curPos.z;
                partnerActor->homePos.x = partnerActor->curPos.x;
                partnerActor->homePos.z = partnerActor->curPos.z;
                playerActor->homePos.x = playerActor->curPos.x;
                playerActor->homePos.z = playerActor->curPos.z;
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_CREATE_MAIN_MENU;
                battleStatus->flags1 &= ~BS_FLAGS1_PLAYER_IN_BACK;
            }
            break;
    }

    switch (gBattleSubState) {
        case BTL_SUBSTATE_PLAYER_MENU_CREATE_MAIN_MENU:
            gBattleStatus.flags1 |= BS_FLAGS1_MENU_OPEN;
            playerActor->flags &= ~ACTOR_FLAG_USING_IDLE_ANIM;
            playerActor->flags |= ACTOR_FLAG_SHOW_STATUS_ICONS;
            if (partnerActor != nullptr) {
                partnerActor->flags |= ACTOR_FLAG_USING_IDLE_ANIM;
                partnerActor->flags |= ACTOR_FLAG_SHOW_STATUS_ICONS;
            }
            btl_check_can_change_partner();
            btl_init_menu_items();
            btl_init_menu_boots();
            btl_init_menu_hammer();
            if (player_team_is_ability_active(playerActor, ABILITY_BERSERKER)) {
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_BERSERKER_CHOOSE;
                break;
            }

            entryIdx = 0;
            initialPos = 2;
            if (battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_MAIN] < 0) {
                battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_MAIN] = 0;
            }

            // strategies menu category
            WheelOptionSubmenu[entryIdx] = BTL_MENU_TYPE_STRATEGIES;
            WheelOptionEnabled[entryIdx] = true;
            WheelOptionHudScript[entryIdx] = StrategiesHudScripts.enabled;
            WheelOptionName[entryIdx] = CenteredBattleMessages[BTL_MENU_TYPE_STRATEGIES];
            if (battleStatus->actionCommandMode == AC_MODE_TUTORIAL || gBattleStatus.flags1 & BS_FLAGS1_TUTORIAL_BATTLE) {
                WheelOptionName[entryIdx] = MSG_Menus_EndTraining_Centered;
            }
            WheelOptionError[entryIdx] = 0;
            if (!(battleStatus->enabledMenusFlags & BTL_MENU_ENABLED_STRATEGIES)) {
                WheelOptionHudScript[entryIdx] = StrategiesHudScripts.disabled;
                WheelOptionEnabled[entryIdx] = false;
                WheelOptionError[entryIdx] = BTL_MSG_CANT_SELECT_NOW;
            }
            if (battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_MAIN] == BTL_MENU_TYPE_STRATEGIES) {
                initialPos = entryIdx;
            }
            entryIdx++;

            // items menu category
            if (battleStatus->menuStatus[0] >= 0) {
                WheelOptionHudScript[entryIdx] = ItemsHudScripts.enabled;
                WheelOptionSubmenu[entryIdx] = BTL_MENU_TYPE_ITEMS;
                WheelOptionEnabled[entryIdx] = true;
                WheelOptionName[entryIdx] = CenteredBattleMessages[BTL_MENU_TYPE_ITEMS];

                if(battleStatus->menuStatus[0] == 0) {
                    WheelOptionHudScript[entryIdx] = ItemsHudScripts.disabled;
                    WheelOptionEnabled[entryIdx] = false;
                    WheelOptionError[entryIdx] = BTL_MSG_NO_ITEM_TARGET;
                }

                if (!(battleStatus->enabledMenusFlags & BTL_MENU_ENABLED_ITEMS)) {
                    WheelOptionHudScript[entryIdx] = ItemsHudScripts.disabled;
                    WheelOptionEnabled[entryIdx] = false;
                    WheelOptionError[entryIdx] = BTL_MSG_CANT_SELECT_NOW;
                }

                if (battleStatus->itemLossTurns >= 0) {
                    WheelOptionHudScript[entryIdx] = ItemsHudScripts.disabled;
                    WheelOptionEnabled[entryIdx] = false;
                    WheelOptionError[entryIdx] = BTL_MSG_CANT_SELECT_NOW;
                }

                if (battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_MAIN] == BTL_MENU_TYPE_ITEMS) {
                    initialPos = entryIdx;
                }

                entryIdx++;
            }

            // jump menu category
            WheelOptionHudScript[entryIdx] = BootsHudScripts[playerData->bootsLevel + 1].enabled;
            WheelOptionSubmenu[entryIdx] = BTL_MENU_TYPE_JUMP;
            WheelOptionEnabled[entryIdx] = true;
            WheelOptionName[entryIdx] = CenteredBattleMessages[BTL_MENU_TYPE_JUMP];

            if (battleStatus->menuStatus[1] <= 0) {
                WheelOptionHudScript[entryIdx] = BootsHudScripts[0].enabled;
                WheelOptionEnabled[entryIdx] = false;
                WheelOptionError[entryIdx] = BTL_MSG_NO_JUMP_TARGET;
            }
            if (!(battleStatus->enabledMenusFlags & BTL_MENU_ENABLED_JUMP)) {
                WheelOptionHudScript[entryIdx] = BootsHudScripts[0].disabled;
                WheelOptionEnabled[entryIdx] = false;
                WheelOptionError[entryIdx] = BTL_MSG_CANT_SELECT_NOW;
            }
            if (battleStatus->jumpLossTurns >= 0) {
                WheelOptionHudScript[entryIdx] = BootsHudScripts[0].disabled;
                WheelOptionEnabled[entryIdx] = false;
                WheelOptionError[entryIdx] = BTL_MSG_CANT_SELECT_NOW;
            }
            if (battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_MAIN] == BTL_MENU_TYPE_JUMP) {
                initialPos = entryIdx;
            }
            entryIdx++;

            // hammer menu category
            if (playerData->hammerLevel >= 0) {
                WheelOptionHudScript[entryIdx] = HammerHudScripts[playerData->hammerLevel + 1].enabled;
                WheelOptionSubmenu[entryIdx] = BTL_MENU_TYPE_SMASH;
                WheelOptionEnabled[entryIdx] = true;
                WheelOptionName[entryIdx] = CenteredBattleMessages[BTL_MENU_TYPE_SMASH];
                if (battleStatus->menuStatus[2] <= 0) {
                    WheelOptionHudScript[entryIdx] = HammerHudScripts[0].enabled;
                    WheelOptionEnabled[entryIdx] = false;
                    WheelOptionError[entryIdx] = BTL_MSG_NO_HAMMER_TARGET;
                }
                if (!(battleStatus->enabledMenusFlags & BTL_MENU_ENABLED_SMASH)) {
                    WheelOptionHudScript[entryIdx] = HammerHudScripts[0].disabled;
                    WheelOptionEnabled[entryIdx] = false;
                    WheelOptionError[entryIdx] = BTL_MSG_CANT_SELECT_NOW;
                }
                if (battleStatus->hammerLossTurns >= 0) {
                    WheelOptionHudScript[entryIdx] = HammerHudScripts[0].disabled;
                    WheelOptionEnabled[entryIdx] = false;
                    WheelOptionError[entryIdx] = BTL_MSG_CANT_SELECT_NOW;
                }
                if (battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_MAIN] == BTL_MENU_TYPE_SMASH) {
                    initialPos = entryIdx;
                }
                entryIdx++;
            }

            // star powers menu category
            if (playerData->maxStarPower != 0) {
                WheelOptionHudScript[entryIdx] = StarPowersHudScripts.enabled;
                WheelOptionSubmenu[entryIdx] = BTL_MENU_TYPE_STAR_POWERS;
                WheelOptionEnabled[entryIdx] = true;
                WheelOptionName[entryIdx] = CenteredBattleMessages[BTL_MENU_TYPE_STAR_POWERS];
                WheelOptionError[entryIdx] = 0;
                if (!(battleStatus->enabledMenusFlags & BTL_MENU_ENABLED_STAR_POWERS)) {
                    WheelOptionHudScript[entryIdx] = StarPowersHudScripts.disabled;
                    WheelOptionEnabled[entryIdx] = false;
                    WheelOptionError[entryIdx] = BTL_MSG_CANT_SELECT_NOW;
                }
                if (battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_MAIN] == BTL_MENU_TYPE_STAR_POWERS) {
                    initialPos = entryIdx;
                }
                entryIdx++;
            }

            WheelOptionCount = entryIdx;
            D_802AD0A8 = 0;
            BattleMenu_PrevSelected = initialPos;
            BattleMenu_WheelBase = 2 - initialPos;
            if (btl_partner_can_act()) {
                BattleMenu_ShowSwapIcons = true;
            } else {
                BattleMenu_ShowSwapIcons = false;
            }
            btl_main_menu_init();
            BattleMenu_ChooseDelay = 8;
            BattleMenu_SwapDelay = 0;
            gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_MAIN_CHOOSING;
            break;
        case BTL_SUBSTATE_PLAYER_MENU_MAIN_CHOOSING:
            if (battleStatus->hustleTurns != 0) {
                set_actor_anim(ACTOR_PLAYER, 0, ANIM_Mario1_ThinkingRun);
            } else {
                set_actor_anim(ACTOR_PLAYER, 0, get_player_anim_for_status(STATUS_KEY_THINKING));
            }
            submenuResult = btl_main_menu_update();
            if (BattleMenu_SwapDelay != 0) {
                BattleMenu_SwapDelay--;
            } else if (!(gBattleStatus.flags1 & BS_FLAGS1_TUTORIAL_BATTLE) && (gGameStatusPtr->pressedButtons[0] & BUTTON_Z)) {
                if (btl_partner_can_act() && battleStatus->hustleTurns != 1) {
                    sfx_play_sound(SOUND_PARTNER_SWAP_BATTLE_POS);
                    battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_MAIN] = WheelOptionSubmenu[BattleMenu_CurPos + BattleMenu_HomePos];
                    btl_main_menu_destroy();
                    btl_set_state(BATTLE_STATE_SWITCH_TO_PARTNER);
                } else if (partnerActor != nullptr && !(partnerActor->flags & BS_FLAGS1_YIELD_TURN) && battleStatus->hustleTurns != 1) {
                    sfx_play_sound(SOUND_MENU_ERROR);
                    gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_MAIN_SHOW_CANT_SWAP;
                }
                break;
            }

            if (BattleMenu_ChooseDelay != 0) {
                BattleMenu_ChooseDelay--;
                break;
            }

            if (submenuResult == POPUP_RESULT_CHOOSING) {
                break;
            }

            set_actor_anim(ACTOR_PLAYER, 0, ANIM_Mario1_Walk);
            battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_MAIN] = battleStatus->curSubmenu = WheelOptionSubmenu[submenuResult - 1];
            for (i = 0; i < ARRAY_COUNT(battleStatus->submenuMoves); i++) {
                battleStatus->submenuMoves[i] = MOVE_NONE;
                battleStatus->submenuIcons[0] = ITEM_NONE; /// @bug ?
                battleStatus->submenuStatus[i] = 0;
            }

            switch (battleStatus->curSubmenu) {
                case BTL_MENU_TYPE_ITEMS:
                    battleStatus->submenuMoves[0] = BattleMenu_CategoryForSubmenu[BTL_MENU_TYPE_STAR_POWERS]; // ???
                    battleStatus->submenuIcons[0] = ITEM_PARTNER_ATTACK;
                    battleStatus->submenuStatus[0] = 1;
                    for (i = 0; i < ARRAY_COUNT(playerData->invItems); i++) {
                        if (playerData->invItems[i] == ITEM_NONE) {
                            continue;
                        }
                        itemData = &gItemTable[playerData->invItems[i]];

                        battleStatus->moveCategory = BTL_MENU_TYPE_ITEMS;
                        battleStatus->moveArgument = playerData->invItems[i];
                        battleStatus->curTargetListFlags = itemData->targetFlags;
                        create_current_pos_target_list(playerActor);
                    }
                    entryIdx = 1;
                    for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++) {
                        if (playerData->equippedBadges[i] != 0) {
                            s32 moveID = gItemTable[playerData->equippedBadges[i]].moveID;
                            moveData = &gMoveTable[moveID];
                            if (moveData->category == BattleMenu_CategoryForSubmenu[battleStatus->curSubmenu]) {
                                battleStatus->submenuMoves[entryIdx] = moveID;
                                battleStatus->submenuIcons[entryIdx] = playerData->equippedBadges[i];
                                battleStatus->submenuStatus[entryIdx] = 1;
                                if (playerData->curFP < moveData->costFP) {
                                    battleStatus->submenuStatus[entryIdx] = 0;
                                }
                                entryIdx++;
                            }
                        }
                    }
                    battleStatus->submenuMoveCount = entryIdx;
                    if (entryIdx == 1) {
                        battleStatus->submenuMoveCount = 0;
                    }
                    break;
                    do { // required to match
                case BTL_MENU_TYPE_SMASH:
                    btl_init_menu_hammer();
                    if (battleStatus->submenuMoveCount == 1) {
                        battleStatus->submenuMoveCount = 0;
                    }
                    if (battleStatus->actionCommandMode == AC_MODE_TUTORIAL) {
                        battleStatus->submenuMoveCount = 0;
                    }
                    break;
                case BTL_MENU_TYPE_JUMP:
                    btl_init_menu_boots();
                    if (battleStatus->submenuMoveCount == 1) {
                        battleStatus->submenuMoveCount = 0;
                    }
                    if (battleStatus->actionCommandMode == AC_MODE_TUTORIAL) {
                        battleStatus->submenuMoveCount = 0;
                    }
                    break;
                case BTL_MENU_TYPE_STAR_POWERS:
                    battleStatus->submenuMoves[0] = MOVE_FOCUS;
                    battleStatus->submenuIcons[0] = ITEM_PARTNER_ATTACK;
                    battleStatus->submenuStatus[0] = 1;
                    entryIdx = 1;
                    initialPos = 8;
                    for (i = 0; i < playerData->maxStarPower; i++) {
                        moveData = &gMoveTable[MOVE_REFRESH + i];
                        battleStatus->submenuMoves[entryIdx] = MOVE_REFRESH + i;
                        battleStatus->submenuIcons[entryIdx] = 0;
                        battleStatus->moveCategory = BTL_MENU_TYPE_STAR_POWERS;
                        battleStatus->moveArgument = MOVE_REFRESH + i;
                        battleStatus->curTargetListFlags = moveData->flags;
                        create_current_pos_target_list(playerActor);
                        battleStatus->submenuStatus[entryIdx] = 1;
                        if (playerActor->targetListLength == 0) {
                            battleStatus->submenuStatus[entryIdx] = -2;
                        }
                        if (playerData->starPower / SP_PER_BAR < moveData->costFP) {
                            battleStatus->submenuStatus[entryIdx] = 0;
                        }
                        if (gBattleStatus.flags2 & BS_FLAGS2_NO_TARGET_AVAILABLE) {
                            battleStatus->submenuStatus[entryIdx] = -1;
                        }
                        entryIdx++;
                    }
                    starBeamLevel = playerData->starBeamLevel;
                    if (starBeamLevel == 1) {
                        do {
                            moveData = &gMoveTable[MOVE_STAR_BEAM];
                            battleStatus->submenuMoves[entryIdx] = MOVE_STAR_BEAM;
                            battleStatus->submenuIcons[entryIdx] = 0;
                            battleStatus->moveCategory = BTL_MENU_TYPE_STAR_POWERS;
                            battleStatus->moveArgument = MOVE_REFRESH + i;
                            battleStatus->curTargetListFlags = moveData->flags;
                            create_current_pos_target_list(playerActor);
                            battleStatus->submenuStatus[entryIdx] = starBeamLevel;
                            if (playerActor->targetListLength == 0) {
                                battleStatus->submenuStatus[entryIdx] = -2;
                            }
                            if (playerData->starPower / SP_PER_BAR < moveData->costFP) {
                                battleStatus->submenuStatus[entryIdx] = 0;
                            }
                            if (gBattleStatus.flags2 & BS_FLAGS2_NO_TARGET_AVAILABLE) {
                                battleStatus->submenuStatus[entryIdx] = -1;
                            }
                            entryIdx++;
                        } while (0);
                    }
                    if (playerData->starBeamLevel == 2) {
                        do {
                            do {
                                moveData = &gMoveTable[MOVE_PEACH_BEAM];
                                battleStatus->submenuMoves[entryIdx] = MOVE_PEACH_BEAM;
                                battleStatus->submenuIcons[entryIdx] = 0;
                                battleStatus->moveCategory = BTL_MENU_TYPE_STAR_POWERS;
                                battleStatus->moveArgument = MOVE_REFRESH + i;
                                battleStatus->curTargetListFlags = moveData->flags;
                                create_current_pos_target_list(playerActor);
                                battleStatus->submenuStatus[entryIdx] = 1;
                                if (playerActor->targetListLength == 0) {
                                    battleStatus->submenuStatus[entryIdx] = -2;
                                }
                                if (playerData->starPower / SP_PER_BAR < moveData->costFP) {
                                    battleStatus->submenuStatus[entryIdx] = 0;
                                }
                                if (gBattleStatus.flags2 & BS_FLAGS2_NO_TARGET_AVAILABLE) {
                                    battleStatus->submenuStatus[entryIdx] = -1;
                                }
                                entryIdx++;
                            } while (0); // TODO required to match
                        } while (0); // TODO required to match
                    }
                    battleStatus->submenuMoveCount = entryIdx;
                    break;
                } while (0); // TODO required to match
            }

            currentSubmenu = battleStatus->curSubmenu;
            if (currentSubmenu == BTL_MENU_TYPE_STAR_POWERS) {
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_BUILD_MENU;
                btl_state_update_player_menu();
                btl_state_update_player_menu();
                break;
            } else if (currentSubmenu == BTL_MENU_TYPE_STRATEGIES) {
                if (battleStatus->actionCommandMode != AC_MODE_TUTORIAL && !(gBattleStatus.flags1 & BS_FLAGS1_TUTORIAL_BATTLE)) {
                    gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_BUILD_MENU;
                    btl_state_update_player_menu();
                    btl_state_update_player_menu();
                    break;
                } else {
                    btl_main_menu_destroy();
                    battleStatus->moveCategory = currentSubmenu;
                    battleStatus->moveArgument = 0;
                    battleStatus->selectedMoveID = 0;
                    btl_set_state(BATTLE_STATE_PLAYER_MOVE);
                    break;
                }
            } else {
                if (battleStatus->submenuMoveCount == 0) {
                    if (currentSubmenu != BTL_MENU_TYPE_ITEMS) {
                        gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_NOSUBMENU_SHOW;
                        break;
                    } else {
                        gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_ITEMS_BUILD_MENU;
                        btl_state_update_player_menu();
                        btl_state_update_player_menu();
                        break;
                    }
                }

                initialPos = 0;
                if (currentSubmenu == BTL_MENU_TYPE_JUMP) {
                    if (battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_JUMP] < 0) {
                        battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_JUMP] = 0;
                    }
                    initialPos = battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_JUMP];
                }
                if (battleStatus->curSubmenu == BTL_MENU_TYPE_SMASH) {
                    if (battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_SMASH] < 0) {
                        battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_SMASH] = 0;
                    }
                    initialPos = battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_SMASH];
                }
                if (battleStatus->curSubmenu == BTL_MENU_TYPE_ITEMS) {
                    if (battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_ITEMS] < 0) {
                        battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_ITEMS] = 0;
                    }
                    initialPos = battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_ITEMS];
                }

                for (i = 0; i < battleStatus->submenuMoveCount; i++) {
                    moveData = &gMoveTable[battleStatus->submenuMoves[i]];
                    itemData = &gItemTable[battleStatus->submenuIcons[i]];
                    hudScriptPair = &gItemHudScripts[itemData->hudElemID];

                    MovesOptionError[i] = 0;
                    if (battleStatus->submenuStatus[i] == 0) {
                        MovesOptionError[i] = 0;
                    }
                    if (battleStatus->submenuStatus[i] == -1) {
                        battleStatus->submenuStatus[i] = 0;
                        MovesOptionError[i] = BTL_MSG_CANT_SELECT_NOW;
                    }
                    if (battleStatus->submenuStatus[i] == -2) {
                        battleStatus->submenuStatus[i] = 0;
                        MovesOptionError[i] = BTL_MSG_CANT_SELECT_NOW;
                    }
                    if (battleStatus->submenuStatus[i] == -3) {
                        battleStatus->submenuStatus[i] = 0;
                        MovesOptionError[i] = BTL_MSG_CANT_SELECT_NOW_ALT;
                    }
                    MovesOptionHudScripts[i] = hudScriptPair->enabled;
                    if (battleStatus->submenuStatus[i] == 0) {
                        MovesOptionHudScripts[i] = hudScriptPair->disabled;
                    }

                    MovesOptionDisplayCosts[i] = moveData->costFP;
                    MovesOptionBPCosts[i] = moveData->costBP;
                    MovesOptionSortPriority[i] = 0;
                    MovesOptionDiscounts[i] = 0;
                    MovesOptionDiscountColors[i] = 0;

                    if (player_team_is_ability_active(playerActor, ABILITY_FLOWER_SAVER)) {
                        MovesOptionDiscounts[i] += player_team_is_ability_active(playerActor, ABILITY_FLOWER_SAVER);
                        MovesOptionDiscountColors[i] = 1;
                    }
                    if (player_team_is_ability_active(playerActor, ABILITY_FLOWER_FANATIC)) {
                        MovesOptionDiscounts[i] += 2 * player_team_is_ability_active(playerActor, ABILITY_FLOWER_FANATIC);
                        MovesOptionDiscountColors[i] = 2;
                    }

                    MovesOptionIndices[i] = i;
                    MovesOptionEnabled[i] = battleStatus->submenuStatus[i];
                    MovesOptionNames[i] = moveData->nameMsg;
                    MovesOptionDesc[i] = moveData->shortDescMsg;

                }
                UsingSpiritsSubmenu = false;
                MovesPrevSelected = initialPos;
                MovesOptionCount = battleStatus->submenuMoveCount;
                btl_submenu_moves_init();
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_ABILITIES_CHOOSING;
                break;
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_ABILITIES_CHOOSING:
            submenuResult = btl_submenu_moves_update();
            if (submenuResult == POPUP_RESULT_INVALID) {
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_ABILITIES_SHOW_ERROR;
            } else if (submenuResult == POPUP_RESULT_CHOOSING) {
            } else if (submenuResult == POPUP_RESULT_CANCEL) {
                btl_main_menu_resume_choose();
                BattleMenu_ChooseDelay = 8;
                BattleMenu_SwapDelay = 4;
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_MAIN_CHOOSING;
                btl_state_update_player_menu();
                btl_state_update_player_menu();
            } else {
                battleStatus->lastSelectedAbility = MovesOptionIndices[submenuResult - 1];
                battleStatus->selectedMoveID = battleStatus->submenuMoves[battleStatus->lastSelectedAbility];
                if (battleStatus->curSubmenu == BTL_MENU_TYPE_JUMP) {
                    battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_JUMP] = SelectedMovesIndex;
                }
                if (battleStatus->curSubmenu == BTL_MENU_TYPE_SMASH) {
                    battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_SMASH] = SelectedMovesIndex;
                }
                currentSubmenu2 = battleStatus->curSubmenu;
                if (battleStatus->curSubmenu == BTL_MENU_TYPE_ITEMS) {
                    battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_ITEMS] = SelectedMovesIndex;
                    if (battleStatus->curSubmenu == currentSubmenu2) {
                        gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_DIPPING_BUILD_MENU;
                        btl_state_update_player_menu();
                        btl_state_update_player_menu();
                        break;
                    }
                }
                btl_submenu_moves_hide();
                btl_main_menu_hide();
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_ABILITIES_HANDOVER;
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_ABILITIES_HANDOVER:
            submenuResult = btl_submenu_moves_update();
            if ((battleStatus->curButtonsPressed & BUTTON_B) && submenuResult == POPUP_RESULT_CHOOSING) {
                btl_submenu_moves_restore_choose();
                btl_main_menu_restore_submenu();
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_ABILITIES_REOPEN_MENU;
                break;
            }
            if (btl_main_menu_update() == 0) {
                break;
            }
            battleStatus->cancelTargetMenuSubstate = BTL_SUBSTATE_PLAYER_MENU_ABILITIES_TARGET_CANCEL;
            battleStatus->acceptTargetMenuSubstate = BTL_SUBSTATE_PLAYER_MENU_ABILITIES_TARGET_CHOSEN;
            battleStatus->selectedMoveID = battleStatus->submenuMoves[battleStatus->lastSelectedAbility];
            battleStatus->curTargetListFlags = gMoveTable[battleStatus->submenuMoves[battleStatus->lastSelectedAbility]].flags;
            currentSubmenu = battleStatus->curSubmenu;
            switch (currentSubmenu) {
                case BTL_MENU_TYPE_JUMP:
                    battleStatus->moveCategory = BTL_MENU_TYPE_JUMP;
                    battleStatus->moveArgument = playerData->bootsLevel;
                    btl_set_state(BATTLE_STATE_SELECT_TARGET);
                    break;
                case BTL_MENU_TYPE_SMASH:
                    battleStatus->moveCategory = BTL_MENU_TYPE_SMASH;
                    battleStatus->moveArgument = playerData->hammerLevel;
                    btl_set_state(BATTLE_STATE_SELECT_TARGET);
                    break;
                case BTL_MENU_TYPE_DEFEND:
                    gBattleSubState = battleStatus->acceptTargetMenuSubstate;
                    btl_state_update_player_menu();
                    battleStatus->moveCategory = BTL_MENU_TYPE_DEFEND;
                    btl_set_state(BATTLE_STATE_DEFEND);
                    break;
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_ABILITIES_REOPEN_MENU:
            btl_submenu_moves_update();
            if (btl_main_menu_update() == 0) {
                break;
            }
            gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_ABILITIES_CHOOSING;
            break;
        case BTL_SUBSTATE_PLAYER_MENU_ABILITIES_TARGET_CANCEL:
            btl_submenu_moves_restore_choose();
            btl_main_menu_restore_submenu();
            gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_ABILITIES_REOPEN_MENU;
            break;
        case BTL_SUBSTATE_PLAYER_MENU_ABILITIES_TARGET_CHOSEN:
            btl_submenu_moves_destroy();
            btl_main_menu_destroy();
            break;
        case BTL_SUBSTATE_PLAYER_MENU_ABILITIES_SHOW_ERROR:
            if (btl_submenu_moves_update() != -1) {
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_ABILITIES_CHOOSING;
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_MAIN_SHOW_CANT_SWAP:
            if (gBattleStatus.flags2 & BS_FLAGS2_PARTNER_TURN_USED) {
                btl_show_variable_battle_message(BTL_MSG_CANT_SWITCH, 60, 0);
            } else {
                btl_show_variable_battle_message(BTL_MSG_CANT_MOVE, 60, playerData->curPartner);
            }
            ShowingErrorMessage = true;
            gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_MAIN_AWAIT_CANT_SWAP;
            break;
        case BTL_SUBSTATE_PLAYER_MENU_MAIN_AWAIT_CANT_SWAP:
            if (btl_is_popup_displayed()) {
                break;
            }
            ShowingErrorMessage = false;
            BattleMenu_ChooseDelay = 0;
            BattleMenu_SwapDelay = 4;
            gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_MAIN_CHOOSING;
            break;
        case BTL_SUBSTATE_PLAYER_MENU_NOSUBMENU_SHOW:
            btl_main_menu_hide();
            gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_NOSUBMENU_HANDOVER;
            break;
        case BTL_SUBSTATE_PLAYER_MENU_NOSUBMENU_HANDOVER:
            submenuResult = btl_main_menu_update();
            if ((battleStatus->curButtonsPressed & BUTTON_B) && submenuResult == POPUP_RESULT_CHOOSING) {
                btl_main_menu_restore_choose();
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_NOSUBMENU_RETURN_MAIN;
            } else if (submenuResult != POPUP_RESULT_CHOOSING) {
                battleStatus->cancelTargetMenuSubstate = BTL_SUBSTATE_PLAYER_MENU_NOSUBMENU_TARGET_CANCEL;
                battleStatus->acceptTargetMenuSubstate = BTL_SUBSTATE_PLAYER_MENU_NOSUBMENU_TARGET_CHOSEN;
                switch (battleStatus->curSubmenu) {
                    case BTL_MENU_TYPE_JUMP:
                        battleStatus->moveCategory = BTL_MENU_TYPE_JUMP;
                        battleStatus->moveArgument = playerData->bootsLevel;
                        battleStatus->selectedMoveID = playerData->bootsLevel + MOVE_JUMP1;
                        battleStatus->curTargetListFlags = gMoveTable[battleStatus->selectedMoveID].flags;
                        btl_set_state(BATTLE_STATE_SELECT_TARGET);
                        break;
                    case BTL_MENU_TYPE_SMASH:
                        battleStatus->moveCategory = BTL_MENU_TYPE_SMASH;
                        battleStatus->moveArgument = playerData->hammerLevel;
                        battleStatus->selectedMoveID = playerData->hammerLevel + MOVE_HAMMER1;
                        battleStatus->curTargetListFlags = gMoveTable[battleStatus->selectedMoveID].flags;
                        btl_set_state(BATTLE_STATE_SELECT_TARGET);
                        break;
                    default:
                        goto CASE_C; // TODO find better match
                }
            }
            break;
        CASE_C:
        case BTL_SUBSTATE_PLAYER_MENU_NOSUBMENU_RETURN_MAIN:
            if (btl_main_menu_update() == 0) {
                break;
            }
            BattleMenu_ChooseDelay = 8;
            BattleMenu_SwapDelay = 4;
            gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_MAIN_CHOOSING;
            break;
        case BTL_SUBSTATE_PLAYER_MENU_NOSUBMENU_TARGET_CANCEL:
            btl_main_menu_restore_choose();
            gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_NOSUBMENU_RETURN_MAIN;
            break;
        case BTL_SUBSTATE_PLAYER_MENU_NOSUBMENU_TARGET_CHOSEN:
            btl_main_menu_destroy();
            break;
        case BTL_SUBSTATE_PLAYER_MENU_DIPPING_BUILD_MENU:
            if (battleStatus->selectedMoveID == MOVE_DOUBLE_DIP) {
                battleStatus->itemUsesLeft = 2;
            }
            if (battleStatus->selectedMoveID == MOVE_TRIPLE_DIP) {
                battleStatus->itemUsesLeft = 3;
            }
            entryIdx = 0;
            for (i = 0; i < ARRAY_COUNT(playerData->invItems); i++) {
                if (playerData->invItems[i] == ITEM_NONE) {
                    continue;
                }
                itemData = &gItemTable[playerData->invItems[i]];
                hudScriptPair = &gItemHudScripts[itemData->hudElemID];
                if (!(itemData->typeFlags & ITEM_TYPE_FLAG_BATTLE_USABLE)) {
                    continue;
                }
                battleStatus->moveCategory = BTL_MENU_TYPE_ITEMS;
                battleStatus->moveArgument = playerData->invItems[i];
                battleStatus->curTargetListFlags = itemData->targetFlags;
                create_current_pos_target_list(playerActor);
                popup->ptrIcon[entryIdx] = hudScriptPair->enabled;
                popup->userIndex[entryIdx] = playerData->invItems[i];
                popup->enabled[entryIdx] = true;
                popup->nameMsg[entryIdx] = itemData->nameMsg;
                popup->descMsg[entryIdx] = itemData->shortDescMsg;
                if (playerActor->targetListLength == 0) {
                    popup->ptrIcon[entryIdx] = hudScriptPair->disabled;
                    popup->enabled[entryIdx] = 0;
                }
                entryIdx++;
            }
            popup->dipMode = 0;
            popup->titleNumber = 0;
            if (battleStatus->selectedMoveID == MOVE_DOUBLE_DIP) {
                popup->dipMode = 1;
                popup->titleNumber = battleStatus->itemUsesLeft;
            }
            if (battleStatus->selectedMoveID == MOVE_TRIPLE_DIP) {
                popup->dipMode = 2;
                popup->titleNumber = battleStatus->itemUsesLeft;
            }
            if (battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_DIP] < 0) {
                battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_DIP] = 0;
            }
            popup->popupType = POPUP_MENU_USE_ITEM;
            popup->numEntries = entryIdx;
            initialPos = battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_DIP];
            popup->initialPos = initialPos;
            create_battle_popup_menu(popup);
            flush_popup_menu();
            gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_DIPPING_CHOOSING;
            break;
        case BTL_SUBSTATE_PLAYER_MENU_DIPPING_CHOOSING:
            if (popup->result != POPUP_RESULT_CHOOSING) {
                if (popup->result == POPUP_RESULT_CANCEL) {
                    btl_submenu_moves_resume_choose();
                    battleStatus->selectedMoveID = 0;
                    battleStatus->itemUsesLeft = 0;
                    gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_ABILITIES_CHOOSING;
                    btl_state_update_player_menu();
                    btl_state_update_player_menu();
                } else {
                    battleStatus->cancelTargetMenuSubstate = BTL_SUBSTATE_PLAYER_MENU_DIPPING_TARGET_CANCEL;
                    battleStatus->acceptTargetMenuSubstate = BTL_SUBSTATE_PLAYER_MENU_DIPPING_TARGET_CHOSEN;
                    battleStatus->lastSelectedItem = popup->userIndex[popup->result - 1];
                    battleStatus->moveCategory = BTL_MENU_TYPE_ITEMS;
                    battleStatus->moveArgument = battleStatus->lastSelectedItem;
                    battleStatus->curTargetListFlags = gItemTable[battleStatus->moveArgument].targetFlags | TARGET_FLAG_PRIMARY_ONLY;
                    battleStatus->curAttackElement = 0;
                    battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_DIP] = popup->result - 1;
                    hide_popup_menu();
                    btl_submenu_moves_hide();
                    btl_main_menu_hide();
                    gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_DIPPING_HANDOVER;
                }
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_DIPPING_HANDOVER:
            if ((battleStatus->curButtonsPressed & BUTTON_B) && popup->result == POPUP_RESULT_CHOOSING) {
                show_popup_menu();
                btl_submenu_moves_restore_locked();
                btl_main_menu_restore_submenu();
                battleStatus->selectedMoveID = 0;
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_DIPPING_REOPEN_MENU;
            } else {
                btl_submenu_moves_update();
                if (btl_main_menu_update()) {
                    btl_set_state(BATTLE_STATE_SELECT_TARGET);
                }
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_DIPPING_REOPEN_MENU:
            btl_submenu_moves_update();
            if (btl_main_menu_update() != 0) {
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_DIPPING_CHOOSING;
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_DIPPING_TARGET_CANCEL:
            show_popup_menu();
            btl_submenu_moves_restore_locked();
            btl_main_menu_restore_submenu();
            btl_submenu_moves_update();
            gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_DIPPING_REOPEN_MENU;
            break;
        case BTL_SUBSTATE_PLAYER_MENU_DIPPING_TARGET_CHOSEN:
            destroy_popup_menu();
            btl_submenu_moves_destroy();
            btl_main_menu_destroy();
            break;
        case BTL_SUBSTATE_PLAYER_MENU_ITEMS_BUILD_MENU:
            entryIdx = 0;
            for (i = 0; i < ARRAY_COUNT(playerData->invItems); i++) {
                if (playerData->invItems[i] == ITEM_NONE) {
                    continue;
                }
                itemData = &gItemTable[playerData->invItems[i]];
                hudScriptPair = &gItemHudScripts[itemData->hudElemID];
                if (!(itemData->typeFlags & ITEM_TYPE_FLAG_BATTLE_USABLE)) {
                    continue;
                }
                battleStatus->moveCategory = BTL_MENU_TYPE_ITEMS;
                battleStatus->moveArgument = playerData->invItems[i];
                battleStatus->curTargetListFlags = itemData->targetFlags;
                create_current_pos_target_list(playerActor);
                popup->ptrIcon[entryIdx] = hudScriptPair->enabled;

                popup->userIndex[entryIdx] = playerData->invItems[i];
                popup->enabled[entryIdx] = 1;
                popup->nameMsg[entryIdx] = itemData->nameMsg;
                popup->descMsg[entryIdx] = itemData->shortDescMsg;
                if (playerActor->targetListLength == 0) {
                    popup->ptrIcon[entryIdx] = hudScriptPair->disabled;
                    popup->enabled[entryIdx] = 0;
                }
                entryIdx++;
            }
            if (battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_DIP] < 0) {
                battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_DIP] = 0;
            }
            initialPos = battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_DIP];
            popup->popupType = POPUP_MENU_USE_ITEM;
            popup->numEntries = entryIdx;
            popup->dipMode = 0;
            popup->titleNumber = 0;
            popup->initialPos = initialPos;
            create_battle_popup_menu(popup);
            flush_popup_menu();
            gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_ITEMS_CHOOSING;
            break;
        case BTL_SUBSTATE_PLAYER_MENU_ITEMS_CHOOSING:
            if (popup->result != POPUP_RESULT_CHOOSING) {
                if (popup->result == POPUP_RESULT_CANCEL) {
                    btl_main_menu_resume_choose();
                    BattleMenu_ChooseDelay = 8;
                    BattleMenu_SwapDelay = 4;
                    gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_MAIN_CHOOSING;
                    btl_state_update_player_menu();
                    btl_state_update_player_menu();
                } else {
                    battleStatus->cancelTargetMenuSubstate = BTL_SUBSTATE_PLAYER_MENU_ITEMS_TARGET_CANCEL;
                    battleStatus->acceptTargetMenuSubstate = BTL_SUBSTATE_PLAYER_MENU_ITEMS_TARGET_CHOSEN;
                    battleStatus->lastSelectedItem = popup->userIndex[popup->result - 1];
                    battleStatus->moveCategory = BTL_MENU_TYPE_ITEMS;
                    battleStatus->moveArgument = battleStatus->lastSelectedItem;
                    battleStatus->selectedMoveID = MOVE_ITEMS;
                    battleStatus->curTargetListFlags = gItemTable[battleStatus->moveArgument].targetFlags | TARGET_FLAG_PRIMARY_ONLY;
                    battleStatus->curAttackElement = 0;
                    battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_DIP] = popup->result - 1;
                    hide_popup_menu();
                    btl_main_menu_hide();
                    gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_ITEMS_HANDOVER;
                }
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_ITEMS_HANDOVER:
            if ((battleStatus->curButtonsPressed & BUTTON_B) && popup->result == POPUP_RESULT_CHOOSING) {
                show_popup_menu();
                btl_main_menu_restore_submenu();
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_ITEMS_REOPEN_MENU;
            } else {
                if (btl_main_menu_update() != 0) {
                    btl_set_state(BATTLE_STATE_SELECT_TARGET);
                }
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_ITEMS_REOPEN_MENU:
            if (btl_main_menu_update() != 0) {
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_ITEMS_CHOOSING;
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_ITEMS_TARGET_CANCEL:
            show_popup_menu();
            btl_main_menu_restore_submenu();
            gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_ITEMS_REOPEN_MENU;
            break;
        case BTL_SUBSTATE_PLAYER_MENU_ITEMS_TARGET_CHOSEN:
            destroy_popup_menu();
            btl_main_menu_destroy();
            break;
        case BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_BUILD_MENU:
            for (i = 0; i < battleStatus->submenuMoveCount; i++) {
                moveData = &gMoveTable[battleStatus->submenuMoves[i]];
                MovesOptionError[i] = 0;

                if (battleStatus->submenuStatus[i] == 0) {
                    MovesOptionError[i] = 0;
                }

                if (battleStatus->submenuStatus[i] == -1) {
                    battleStatus->submenuStatus[i] = 0;
                    MovesOptionError[i] = BTL_MSG_CANT_SELECT_NOW;
                }
                if (battleStatus->submenuStatus[i] == -2) {
                    battleStatus->submenuStatus[i] = 0;
                    MovesOptionError[i] = BTL_MSG_CANT_SELECT_NOW;
                }
                if (!(battleStatus->enabledStarPowersFlags & (1 << i))) {
                    battleStatus->submenuStatus[i] = 0;
                    MovesOptionError[i] = BTL_MSG_CANT_SELECT_NOW;
                }

                MovesOptionHudScripts[i] = StarPowerMovesHudScripts[2 * STAR_POWER_INDEX(battleStatus->submenuMoves[i]) + 0];
                if (battleStatus->submenuStatus[i] == 0) {
                    MovesOptionHudScripts[i] = StarPowerMovesHudScripts[2 * STAR_POWER_INDEX(battleStatus->submenuMoves[i]) + 1];
                }
                MovesOptionDisplayCosts[i] = moveData->costFP;
                MovesOptionBPCosts[i] = moveData->costBP;
                MovesOptionSortPriority[i] = 0;
                MovesOptionIndices[i] = i;
                MovesOptionEnabled[i] = battleStatus->submenuStatus[i];
                MovesOptionNames[i] = moveData->nameMsg;
                MovesOptionDesc[i] = moveData->shortDescMsg;
                MovesOptionDiscounts[i] = 0;
                MovesOptionDiscountColors[i] = 0;
            }
            if (battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_STAR_POWER] < 0) {
                battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_STAR_POWER] = 0;
            }
            initialPos = battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_STAR_POWER];
            MovesOptionCount = battleStatus->submenuMoveCount;
            MovesPrevSelected = initialPos;
            UsingSpiritsSubmenu = true;
            btl_submenu_moves_init();
            gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_CHOOSING;
            break;
        case BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_CHOOSING:
            submenuResult = btl_submenu_moves_update();
            if (submenuResult == POPUP_RESULT_INVALID) {
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_SHOW_ERROR;
            } else if (submenuResult == POPUP_RESULT_CHOOSING) {
            } else if (submenuResult == POPUP_RESULT_CANCEL) {
                btl_main_menu_resume_choose();
                BattleMenu_ChooseDelay = 8;
                BattleMenu_SwapDelay = 4;
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_MAIN_CHOOSING;
                btl_state_update_player_menu();
                btl_state_update_player_menu();
            } else {
                battleStatus->lastSelectedAbility = MovesOptionIndices[submenuResult - 1];
                battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_STAR_POWER] = SelectedMovesIndex;
                btl_submenu_moves_hide();
                btl_main_menu_hide();
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_HANDOVER;
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_HANDOVER:
            submenuResult = btl_submenu_moves_update();
            if ((battleStatus->curButtonsPressed & BUTTON_B) && submenuResult == POPUP_RESULT_CHOOSING) {
                btl_submenu_moves_restore_choose();
                btl_main_menu_restore_submenu();
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_REOPEN_MENU;
            } else if (btl_main_menu_update() != 0) {
                battleStatus->cancelTargetMenuSubstate = BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_TARGET_CANCEL;
                battleStatus->acceptTargetMenuSubstate = BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_TARGET_CHOSEN;
                battleStatus->moveCategory = BTL_MENU_TYPE_STAR_POWERS;
                battleStatus->selectedMoveID = battleStatus->submenuMoves[battleStatus->lastSelectedAbility];
                battleStatus->curTargetListFlags = gMoveTable[battleStatus->submenuMoves[battleStatus->lastSelectedAbility]].flags;
                battleStatus->moveArgument = battleStatus->lastSelectedAbility;
                if (playerData->starBeamLevel == 2 && battleStatus->moveArgument == 8) {
                    battleStatus->moveArgument++;
                }
                btl_set_state(BATTLE_STATE_SELECT_TARGET);
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_REOPEN_MENU:
            btl_submenu_moves_update();
            if (btl_main_menu_update() != 0) {
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_CHOOSING;
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_TARGET_CANCEL:
            btl_submenu_moves_restore_choose();
            btl_main_menu_restore_submenu();
            gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_REOPEN_MENU;
            break;
        case BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_TARGET_CHOSEN:
            btl_submenu_moves_destroy();
            btl_main_menu_destroy();
            break;
        case BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_SHOW_ERROR:
            if (btl_submenu_moves_update() != -1) {
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_CHOOSING;
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_NEXT_DIP_BUILD_MENU:
            if (!btl_player_can_act()) {
                battleStatus->itemUsesLeft = 1;
                btl_set_state(BATTLE_STATE_END_PLAYER_TURN);
            } else {
                entryIdx = 0;
                for (i = 0; i < ARRAY_COUNT(playerData->invItems); i++) {
                    if (playerData->invItems[i] == ITEM_NONE) {
                        continue;
                    }
                    itemData = &gItemTable[playerData->invItems[i]];
                    hudScriptPair = &gItemHudScripts[itemData->hudElemID];
                    if (!(itemData->typeFlags & ITEM_TYPE_FLAG_BATTLE_USABLE)) {
                        continue;
                    }

                    battleStatus->moveCategory = BTL_MENU_TYPE_ITEMS;
                    battleStatus->moveArgument = playerData->invItems[i];
                    battleStatus->curTargetListFlags = itemData->targetFlags;
                    create_current_pos_target_list(playerActor);
                    popup->ptrIcon[entryIdx] = hudScriptPair->enabled;
                    popup->userIndex[entryIdx] = playerData->invItems[i];
                    popup->enabled[entryIdx] = true;
                    popup->nameMsg[entryIdx] = itemData->nameMsg;
                    popup->descMsg[entryIdx] = itemData->shortDescMsg;
                    if (playerActor->targetListLength == 0) {
                        popup->ptrIcon[entryIdx] = hudScriptPair->disabled;
                        popup->enabled[entryIdx] = false;
                    }
                    entryIdx++;
                }
                if (entryIdx == 0) {
                    battleStatus->itemUsesLeft = 1;
                    btl_set_state(BATTLE_STATE_END_PLAYER_TURN);
                } else {
                    popup->popupType = POPUP_MENU_USE_ITEM;
                    if (battleStatus->selectedMoveID == MOVE_DOUBLE_DIP) {
                        popup->popupType += POPUP_MENU_DOUBLE_DIP;
                        popup->dipMode = 1;
                        popup->titleNumber = battleStatus->itemUsesLeft;
                    }
                    if (battleStatus->selectedMoveID == MOVE_TRIPLE_DIP) {
                        popup->popupType += POPUP_MENU_TRIPLE_DIP;
                        popup->dipMode = 2;
                        popup->titleNumber = battleStatus->itemUsesLeft;
                    }
                    if (battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_DIP] < 0) {
                        battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_DIP] = 0;
                    }
                    popup->numEntries = entryIdx;
                    initialPos = battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_DIP];
                    popup->initialPos = initialPos;
                    create_battle_popup_menu(popup);
                    flush_popup_menu();
                    gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_NEXT_DIP_CHOOSING;
                }
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_NEXT_DIP_CHOOSING:
            if (popup->result != POPUP_RESULT_CHOOSING) {
                if (popup->result == POPUP_RESULT_CANCEL) {
                    battleStatus->itemUsesLeft = 1;
                    btl_set_state(BATTLE_STATE_END_PLAYER_TURN);
                } else {
                    battleStatus->cancelTargetMenuSubstate = BTL_SUBSTATE_PLAYER_MENU_NEXT_DIP_TARGET_CANCEL;
                    battleStatus->acceptTargetMenuSubstate = BTL_SUBSTATE_PLAYER_MENU_NEXT_DIP_TARGET_CHOSEN;
                    battleStatus->lastSelectedItem = popup->userIndex[popup->result - 1];
                    battleStatus->moveCategory = BTL_MENU_TYPE_ITEMS;
                    battleStatus->moveArgument = battleStatus->lastSelectedItem;
                    battleStatus->curTargetListFlags = gItemTable[battleStatus->moveArgument].targetFlags | TARGET_FLAG_PRIMARY_ONLY;
                    battleStatus->curAttackElement = 0;
                    battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_DIP] = popup->result - 1;
                    hide_popup_menu();
                    BattleMenu_ChooseDelay = 5;
                    gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_NEXT_DIP_HANDOVER;
                }
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_NEXT_DIP_HANDOVER:
            if (BattleMenu_ChooseDelay != 0) {
                BattleMenu_ChooseDelay--;
            } else {
                btl_set_state(BATTLE_STATE_SELECT_TARGET);
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_NEXT_DIP_REOPEN_MENU:
            if (BattleMenu_ChooseDelay != 0) {
                BattleMenu_ChooseDelay--;
            } else {
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_NEXT_DIP_CHOOSING;
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_NEXT_DIP_TARGET_CANCEL:
            show_popup_menu();
            BattleMenu_ChooseDelay = 5;
            gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_NEXT_DIP_REOPEN_MENU;
            break;
        case BTL_SUBSTATE_PLAYER_MENU_NEXT_DIP_TARGET_CHOSEN:
            destroy_popup_menu();
            break;
        case BTL_SUBSTATE_PLAYER_MENU_BERSERKER_CHOOSE:
            if (playerData->bootsLevel >= 0) {
                battleStatus->curTargetListFlags = gMoveTable[MOVE_BERSERKER_JUMP].flags;
                create_current_pos_target_list(playerActor);
                jumpTargetCount = playerActor->targetListLength;
            } else {
                jumpTargetCount = 0;
            }

            if (playerData->hammerLevel >= 0) {
                battleStatus->curTargetListFlags = gMoveTable[MOVE_BERSERKER_HAMMER].flags;
                create_current_pos_target_list(playerActor);
                hammerTargetCount = playerActor->targetListLength;
            } else {
                hammerTargetCount = 0;
            }

            if (jumpTargetCount <= 0 && hammerTargetCount <= 0) {
                battleStatus->moveCategory = BTL_MENU_TYPE_DO_NOTHING;
                battleStatus->waitForState = BATTLE_STATE_NONE;
                btl_set_state(BATTLE_STATE_END_PLAYER_TURN);
            } else {
                jumpChance = 50;
                if (jumpTargetCount <= 0) {
                    jumpChance = 0;
                }
                if (hammerTargetCount <= 0) {
                    jumpChance = 101;
                }
                if (rand_int(100) < jumpChance) {
                    battleStatus->selectedMoveID = MOVE_BERSERKER_JUMP;
                    battleStatus->moveCategory = BTL_MENU_TYPE_JUMP;
                    battleStatus->curTargetListFlags = gMoveTable[MOVE_BERSERKER_JUMP].flags;
                    battleStatus->moveArgument = playerData->bootsLevel;
                    create_current_pos_target_list(playerActor);
                } else {
                    battleStatus->selectedMoveID = MOVE_BERSERKER_HAMMER;
                    battleStatus->moveCategory = BTL_MENU_TYPE_SMASH;
                    battleStatus->curTargetListFlags = gMoveTable[MOVE_BERSERKER_HAMMER].flags;
                    battleStatus->moveArgument = playerData->hammerLevel;
                    create_current_pos_target_list(playerActor);
                }
                btl_set_state(BATTLE_STATE_PLAYER_MOVE);
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_BUILD_MENU:
            entryIdx = 0;
            btl_check_can_change_partner();

            // add 'Change Member' command
            if (battleStatus->changePartnerAllowed >= 0) {
                StratsOptionMenuTypes[entryIdx] = BTL_MENU_TYPE_CHANGE_PARTNER;
                StratsOptionNames[entryIdx] = LeftJustMenuMessages[BTL_MENU_TYPE_CHANGE_PARTNER];
                StratsOptionHudScripts[entryIdx] = PartnerHudScripts[playerData->curPartner];
                StratsOptionEnabled[entryIdx] = 1;
                StratsOptionMessage[entryIdx] = MSG_Menus_Action_ChangePartner;
                if (battleStatus->changePartnerAllowed <= 0) {
                    StratsOptionHudScripts[entryIdx] = battle_menu_DisabledPartnerHudScripts[playerData->curPartner];
                    StratsOptionEnabled[entryIdx] = 0;
                    StratsOptionError[entryIdx] = 0;
                }
                entryIdx++;
            }

            // add 'Do Nothing' command
            StratsOptionHudScripts[entryIdx] = DoNothingHudScripts.enabled;
            StratsOptionMenuTypes[entryIdx] = BTL_MENU_TYPE_DO_NOTHING;
            StratsOptionEnabled[entryIdx] = 1;
            StratsOptionNames[entryIdx] = LeftJustMenuMessages[BTL_MENU_TYPE_DO_NOTHING];
            StratsOptionMessage[entryIdx] = MSG_Menus_Action_DoNothing;
            entryIdx++;

            // add 'Run Away' command
            StratsOptionHudScripts[entryIdx] = FleeHudScripts.enabled;
            StratsOptionMenuTypes[entryIdx] = BTL_MENU_TYPE_RUN_AWAY;
            StratsOptionEnabled[entryIdx] = 1;
            StratsOptionNames[entryIdx] = LeftJustMenuMessages[BTL_MENU_TYPE_RUN_AWAY];
            StratsOptionMessage[entryIdx] = MSG_Menus_Action_RunAway;
            if (!(gBattleStatus.flags2 & BS_FLAGS2_CAN_FLEE)) {
                StratsOptionHudScripts[entryIdx] = FleeHudScripts.disabled;
                StratsOptionEnabled[entryIdx] = 0;
                StratsOptionError[entryIdx] = 1;
            }
            entryIdx++;

            if (battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_STRATEGY] < 0) {
                battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_STRATEGY] = 0;
            }
            initialPos = battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_STRATEGY];
            StratsOptionCount = entryIdx;
            StratsPrevSelected = initialPos;
            btl_menu_strats_init();
            gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_CHOOSING;
            break;
        case BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_CHOOSING:
            submenuResult = btl_submenu_strats_update();
            if (submenuResult == POPUP_RESULT_INVALID) {
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_SHOW_ERROR;
            } else if (submenuResult == POPUP_RESULT_CHOOSING) {
            } else if (submenuResult == POPUP_RESULT_CANCEL) {
                btl_main_menu_resume_choose();
                BattleMenu_ChooseDelay = 8;
                BattleMenu_SwapDelay = 4;
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_MAIN_CHOOSING;
                btl_state_update_player_menu();
                btl_state_update_player_menu();
            } else {
                battleStatus->curSubmenu = StratsOptionMenuTypes[submenuResult - 1];
                battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_STRATEGY] = submenuResult - 1;
                if (battleStatus->curSubmenu == BTL_MENU_TYPE_CHANGE_PARTNER) {
                    gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_BUILD_MENU;
                    btl_state_update_player_menu();
                    btl_state_update_player_menu();
                } else {
                    btl_submenu_strats_hide();
                    btl_main_menu_hide();
                    gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_HANDOVER;
                }
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_HANDOVER:
            submenuResult = btl_submenu_strats_update();
            if ((battleStatus->curButtonsPressed & BUTTON_B) && submenuResult == POPUP_RESULT_CHOOSING) {
                btl_submenu_strats_restore_choose();
                btl_main_menu_restore_submenu();
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_REOPEN_MENU;
            } else if (btl_main_menu_update() != 0) {
                battleStatus->cancelTargetMenuSubstate = BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_TARGET_CANCEL;
                battleStatus->acceptTargetMenuSubstate = BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_TARGET_CHOSEN;
                switch (battleStatus->curSubmenu) {
                    case BTL_MENU_TYPE_RUN_AWAY:
                        gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_TARGET_CHOSEN;
                        btl_state_update_player_menu();
                        battleStatus->moveCategory = BTL_MENU_TYPE_RUN_AWAY;
                        battleStatus->selectedMoveID = MOVE_RUN_AWAY;
                        btl_set_state(BATTLE_STATE_RUN_AWAY);
                        break;
                    case BTL_MENU_TYPE_DO_NOTHING:
                        battleStatus->hustleTurns = 0;
                        gBattleStatus.flags1 &= ~BS_FLAGS1_HUSTLED;
                        gBattleSubState = battleStatus->acceptTargetMenuSubstate;
                        btl_state_update_player_menu();
                        btl_set_state(BATTLE_STATE_END_PLAYER_TURN);
                        break;
                    case BTL_MENU_TYPE_DEFEND:
                        gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_TARGET_CHOSEN;
                        btl_state_update_player_menu();
                        battleStatus->selectedMoveID = MOVE_DEFEND;
                        battleStatus->moveCategory = BTL_MENU_TYPE_DEFEND;
                        btl_set_state(BATTLE_STATE_DEFEND);
                        break;
                    case BTL_MENU_TYPE_ACT_LATER:
                        gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_TARGET_CHOSEN;
                        btl_state_update_player_menu();
                        btl_set_state(BATTLE_STATE_SWITCH_TO_PARTNER);
                        break;
                }
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_REOPEN_MENU:
            btl_submenu_strats_update();
            if (btl_main_menu_update() != 0) {
                BattleMenu_ChooseDelay = 8;
                BattleMenu_SwapDelay = 4;
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_MAIN_CHOOSING;
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_TARGET_CANCEL:
            btl_submenu_strats_restore_choose();
            btl_main_menu_restore_submenu();
            gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_REOPEN_MENU;
            break;
        case BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_TARGET_CHOSEN:
            btl_submenu_strats_destroy();
            btl_main_menu_destroy();
            break;
        case BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_SHOW_ERROR:
            if (btl_submenu_strats_update() != -1) {
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_CHOOSING;
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_BUILD_MENU:
            entryIdx = 0;
            for (i = 1; i < ARRAY_COUNT(playerData->partners); i++) {
                s32 partnerId = PartnerIDFromMenuIndex[i];
                if (playerData->partners[partnerId].enabled) {
                    prop = &gPartnerPopupProperties[partnerId];
                    popup->ptrIcon[entryIdx] = PartnerHudScripts[partnerId];
                    popup->userIndex[entryIdx] = partnerId;
                    popup->enabled[entryIdx] = 1;
                    popup->nameMsg[entryIdx] = prop->nameMsg;
                    popup->descMsg[entryIdx] = prop->battleDescMsg;
                    popup->value[entryIdx] = playerData->partners[partnerId].level;
                    if (playerData->curPartner == partnerId) {
                        popup->enabled[entryIdx] = 0;
                        popup->ptrIcon[entryIdx] = battle_menu_DisabledPartnerHudScripts[partnerId];
                    }
                    entryIdx++;
                }
            }
            if (battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_PARTNER] < 0) {
                battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_PARTNER] = 0;
            }
            popup->popupType = POPUP_MENU_SWITCH_PARTNER;
            popup->numEntries = entryIdx;
            popup->initialPos = MenuIndexFromPartnerID[playerData->curPartner] - 1;
            popup->dipMode = 0;
            popup->titleNumber = 0;
            create_battle_popup_menu(popup);
            flush_popup_menu();
            gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_CHOOSING;
            break;
        case BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_CHOOSING:
            if (popup->result == POPUP_RESULT_INVALID) {
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_ERROR;
            } else if (popup->result != POPUP_RESULT_CHOOSING) {
                if (popup->result == POPUP_RESULT_CANCEL) {
                    btl_submenu_strats_resume_choose();
                    gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_CHOOSING;
                    btl_state_update_player_menu();
                    btl_state_update_player_menu();
                } else {
                    battleStatus->cancelTargetMenuSubstate = BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_TARGET_CANCEL;
                    battleStatus->acceptTargetMenuSubstate = BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_TARGET_CHOSEN;
                    battleStatus->lastSelectedPartner = popup->userIndex[popup->result - 1];
                    battleStatus->moveCategory = BTL_MENU_TYPE_CHANGE_PARTNER;
                    battleStatus->selectedMoveID = MOVE_CHANGE_PARTNER;
                    battleStatus->curTargetListFlags = TARGET_FLAG_2;
                    battleStatus->moveArgument = battleStatus->lastSelectedPartner;
                    battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_PARTNER] = popup->result - 1;
                    hide_popup_menu();
                    btl_submenu_strats_hide();
                    btl_main_menu_hide();
                    gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_HANDOVER;
                }
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_HANDOVER:
            if ((battleStatus->curButtonsPressed & BUTTON_B) && popup->result == POPUP_RESULT_CHOOSING) {
                show_popup_menu();
                btl_submenu_strats_restore_locked();
                btl_main_menu_restore_submenu();
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_REOPEN_MENU;
            } else {
                btl_submenu_strats_update();
                if (btl_main_menu_update() != 0) {
                    gBattleSubState = battleStatus->acceptTargetMenuSubstate;
                    btl_state_update_player_menu();
                    btl_set_state(BATTLE_STATE_CHANGE_PARTNER);
                }
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_REOPEN_MENU:
            btl_submenu_strats_update();
            if (btl_main_menu_update() != 0) {
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_CHOOSING;
            }
            break;
        case BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_TARGET_CANCEL:
            show_popup_menu();
            btl_submenu_strats_restore_locked();
            btl_main_menu_restore_submenu();
            gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_REOPEN_MENU;
            break;
        case BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_TARGET_CHOSEN:
            destroy_popup_menu();
            btl_submenu_strats_destroy();
            btl_main_menu_destroy();
            break;
        case BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_ERROR:
            set_window_update(WIN_BTL_STRATS_MENU, WINDOW_UPDATE_HIDE);
            set_window_update(WIN_BTL_STRATS_TITLE, WINDOW_UPDATE_HIDE);
            if (popup->result != POPUP_RESULT_INVALID) {
                set_window_update(WIN_BTL_STRATS_MENU, WINDOW_UPDATE_9);
                set_window_update(WIN_BTL_STRATS_TITLE, WINDOW_UPDATE_9);
                gBattleSubState = BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_CHOOSING;
            }
            break;
    }
}

void btl_state_draw_player_menu(void) {
    switch (gBattleSubState) {
        case BTL_SUBSTATE_PLAYER_MENU_MAIN_CHOOSING:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_PLAYER_MENU_ABILITIES_CHOOSING:
        case BTL_SUBSTATE_PLAYER_MENU_ABILITIES_HANDOVER:
        case BTL_SUBSTATE_PLAYER_MENU_ABILITIES_REOPEN_MENU:
        case BTL_SUBSTATE_PLAYER_MENU_ABILITIES_TARGET_CANCEL:
        case BTL_SUBSTATE_PLAYER_MENU_NOSUBMENU_SHOW:
        case BTL_SUBSTATE_PLAYER_MENU_NOSUBMENU_HANDOVER:
        case BTL_SUBSTATE_PLAYER_MENU_NOSUBMENU_RETURN_MAIN:
        case BTL_SUBSTATE_PLAYER_MENU_NOSUBMENU_TARGET_CANCEL:
        case BTL_SUBSTATE_PLAYER_MENU_DIPPING_BUILD_MENU:
        case BTL_SUBSTATE_PLAYER_MENU_DIPPING_CHOOSING:
        case BTL_SUBSTATE_PLAYER_MENU_DIPPING_HANDOVER:
        case BTL_SUBSTATE_PLAYER_MENU_DIPPING_REOPEN_MENU:
        case BTL_SUBSTATE_PLAYER_MENU_DIPPING_TARGET_CANCEL:
        case BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_BUILD_MENU:
        case BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_CHOOSING:
        case BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_HANDOVER:
        case BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_REOPEN_MENU:
        case BTL_SUBSTATE_PLAYER_MENU_CHANGE_PARTNER_TARGET_CANCEL:
        case BTL_SUBSTATE_PLAYER_MENU_ITEMS_BUILD_MENU:
        case BTL_SUBSTATE_PLAYER_MENU_ITEMS_CHOOSING:
        case BTL_SUBSTATE_PLAYER_MENU_ITEMS_HANDOVER:
        case BTL_SUBSTATE_PLAYER_MENU_ITEMS_REOPEN_MENU:
        case BTL_SUBSTATE_PLAYER_MENU_ITEMS_TARGET_CANCEL:
        case BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_CHOOSING:
        case BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_HANDOVER:
        case BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_REOPEN_MENU:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_TARGET_CANCEL:
        case BTL_SUBSTATE_PLAYER_MENU_STAR_SPIRITS_TARGET_CHOSEN:
        case BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_BUILD_MENU:
        case BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_CHOOSING:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_HANDOVER:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_REOPEN_MENU:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_TARGET_CANCEL:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_PLAYER_MENU_STRATEGIES_TARGET_CHOSEN:
            btl_main_menu_draw();
            break;
    }
}

void btl_state_update_partner_menu(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* playerActor = battleStatus->playerActor;
    Actor* partnerActor = battleStatus->partnerActor;
    PopupMenu* popupMenu = &BattlePopupMenu;
    s32 entryIdx;
    s32 i;
    s32 popupIndex;
    s32 initialPos;
    MoveData* moveData;
    PartnerPopupProperties* popupProps;

    if (gBattleSubState == BTL_SUBSTATE_PARTNER_MENU_NONE) {
        battleStatus->moveCategory = BTL_MENU_TYPE_INVALID;
        battleStatus->selectedMoveID = MOVE_NONE;
        battleStatus->curAttackElement = 0;
        if (!btl_partner_can_act()) {
            btl_set_state(BATTLE_STATE_TRANSFER_TURN);
        } else {
            btl_cam_use_preset(BTL_CAM_DEFAULT);
            battleStatus->flags1 |= BS_FLAGS1_MENU_OPEN;
            playerActor->flags &= ~(ACTOR_FLAG_USING_IDLE_ANIM | ACTOR_FLAG_SHOW_STATUS_ICONS);
            partnerActor->flags &= ~(ACTOR_FLAG_USING_IDLE_ANIM | ACTOR_FLAG_SHOW_STATUS_ICONS);
            if (battleStatus->flags1 & BS_FLAGS1_PLAYER_IN_BACK) {
                gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_CREATE_MAIN_MENU;
            } else {
                gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_PERFORM_SWAP;
                partnerActor->state.curPos.x = partnerActor->homePos.x;
                partnerActor->state.curPos.z = partnerActor->homePos.z;
                partnerActor->state.goalPos.x = playerActor->homePos.x;
                partnerActor->state.goalPos.z = playerActor->homePos.z;
                partnerActor->state.moveTime = 4;
                partnerActor->state.angle = 0.0f;
            }
        }
    }
    if (gBattleSubState == BTL_SUBSTATE_PARTNER_MENU_PERFORM_SWAP) {
        if (partnerActor->state.moveTime != 0) {
            partnerActor->curPos.x += (partnerActor->state.goalPos.x - partnerActor->curPos.x) / partnerActor->state.moveTime;
            partnerActor->curPos.z += (partnerActor->state.goalPos.z - partnerActor->curPos.z) / partnerActor->state.moveTime;
            playerActor->curPos.x += (partnerActor->state.curPos.x - playerActor->curPos.x) / partnerActor->state.moveTime;
            playerActor->curPos.z += (partnerActor->state.curPos.z - playerActor->curPos.z) / partnerActor->state.moveTime;
        }
        partnerActor->curPos.z += sin_rad(DEG_TO_RAD(partnerActor->state.angle)) * 16.0f;
        partnerActor->yaw = clamp_angle(-partnerActor->state.angle);
        playerActor->curPos.z -= sin_rad(DEG_TO_RAD(partnerActor->state.angle)) * 16.0f;
        playerActor->yaw = clamp_angle(-partnerActor->state.angle);
        partnerActor->state.angle += 90.0f;
        if (partnerActor->state.moveTime != 0) {
            partnerActor->state.moveTime--;
        } else {
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_CREATE_MAIN_MENU;
            partnerActor->curPos.x = partnerActor->state.goalPos.x;
            partnerActor->curPos.z = partnerActor->state.goalPos.z;
            playerActor->curPos.x = partnerActor->state.curPos.x;
            playerActor->curPos.z = partnerActor->state.curPos.z;
            partnerActor->homePos.x = partnerActor->curPos.x;
            partnerActor->homePos.z = partnerActor->curPos.z;
            playerActor->homePos.x = playerActor->curPos.x;
            playerActor->homePos.z = playerActor->curPos.z;
            gBattleStatus.flags1 |= BS_FLAGS1_PLAYER_IN_BACK;
        }
    }
    switch (gBattleSubState) {
        case BTL_SUBSTATE_PARTNER_MENU_CREATE_MAIN_MENU:
            partnerActor->flags |= ACTOR_FLAG_SHOW_STATUS_ICONS;
            partnerActor->flags &= ~ACTOR_FLAG_USING_IDLE_ANIM;
            playerActor->flags |= ACTOR_FLAG_USING_IDLE_ANIM;
            playerActor->flags |= ACTOR_FLAG_SHOW_STATUS_ICONS;
            btl_init_menu_items();
            btl_check_can_change_partner();
            entryIdx = 0;
            initialPos = 1;
            if (battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_MAIN] < 0) {
                battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_MAIN] = BTL_MENU_TYPE_ABILITY;
            }
            btl_init_menu_partner();
            btl_check_can_change_partner();

            // strategies menu category
            WheelOptionSubmenu[entryIdx] = BTL_MENU_TYPE_STRATEGIES;
            WheelOptionEnabled[entryIdx] = true;
            WheelOptionError[entryIdx] = 0;
            WheelOptionHudScript[entryIdx] = StrategiesHudScripts.enabled;
            WheelOptionName[entryIdx] = CenteredBattleMessages[BTL_MENU_TYPE_STRATEGIES];
            if (!(battleStatus->enabledMenusFlags & BTL_MENU_ENABLED_STRATEGIES)) {
                WheelOptionEnabled[entryIdx] = false;
                WheelOptionError[entryIdx] = BTL_MSG_CANT_SELECT_NOW;
                WheelOptionHudScript[entryIdx] = StrategiesHudScripts.disabled;
            }
            if (battleStatus->lastPartnerMenuSelection[entryIdx] == BTL_MENU_TYPE_STRATEGIES) {
                initialPos = entryIdx;
            }
            entryIdx++;

            // abilities menu category
            WheelOptionHudScript[entryIdx] = PartnerMoveHudScripts[playerData->curPartner][0];
            WheelOptionSubmenu[entryIdx] = BTL_MENU_TYPE_ABILITY;
            WheelOptionEnabled[entryIdx] = true;
            WheelOptionName[entryIdx] = CenteredBattleMessages[BTL_MENU_TYPE_ABILITY];
            if (battleStatus->menuStatus[3] <= 0) {
                WheelOptionHudScript[entryIdx] = PartnerMoveHudScripts[playerData->curPartner][1];
                WheelOptionEnabled[entryIdx] = false;
                WheelOptionError[entryIdx] = BTL_MSG_CANT_SELECT_NOW;
            }
            if (!(battleStatus->enabledMenusFlags & BTL_MENU_ENABLED_ABILITIES)) {
                WheelOptionHudScript[entryIdx] = PartnerMoveHudScripts[playerData->curPartner][1];
                WheelOptionEnabled[entryIdx] = false;
                WheelOptionError[entryIdx] = BTL_MSG_CANT_SELECT_NOW;
            }
            if (battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_MAIN] == BTL_MENU_TYPE_ABILITY) {
                initialPos = entryIdx;
            }
            entryIdx++;

            // focus menu category
            if (playerData->maxStarPower != 0 && is_ability_active(ABILITY_GROUP_FOCUS)) {
                WheelOptionSubmenu[entryIdx] = BTL_MENU_TYPE_PARTNER_FOCUS;
                WheelOptionEnabled[entryIdx] = true;
                WheelOptionError[entryIdx] = 0;
                WheelOptionHudScript[entryIdx] = StarPowersHudScripts.enabled;
                WheelOptionName[entryIdx] = CenteredBattleMessages[BTL_MENU_TYPE_PARTNER_FOCUS];
                if (!(battleStatus->enabledMenusFlags & BTL_MENU_ENABLED_PARTNER_FOCUS)) {
                    WheelOptionEnabled[entryIdx] = false;
                    WheelOptionError[entryIdx] = BTL_MSG_CANT_SELECT_NOW;
                    WheelOptionHudScript[entryIdx] = StarPowersHudScripts.disabled;
                }
                if (battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_MAIN] == BTL_MENU_TYPE_PARTNER_FOCUS) {
                    initialPos = entryIdx;
                }
                entryIdx++;
            }

            WheelOptionCount = entryIdx;
            D_802AD0A8 = 1;
            BattleMenu_PrevSelected = initialPos;
            BattleMenu_WheelBase = 2 - initialPos;
            if (btl_player_can_act()) {
                BattleMenu_ShowSwapIcons = true;
            } else {
                BattleMenu_ShowSwapIcons = false;
            }
            btl_main_menu_init();
            BattleMenu_ChooseDelay = 8;
            BattleMenu_SwapDelay = 0;
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_MAIN_BEGIN;
            return;
        case BTL_SUBSTATE_PARTNER_MENU_MAIN_BEGIN:
            set_actor_anim(ACTOR_PARTNER, 0, PartnerThinkAnims[playerData->curPartner]);
#if VERSION_PAL
            btl_init_menu_partner();
#endif
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_MAIN_CHOOSING;
        case BTL_SUBSTATE_PARTNER_MENU_MAIN_CHOOSING:
            entryIdx = btl_main_menu_update();

            if (BattleMenu_SwapDelay != 0) {
                BattleMenu_SwapDelay--;
            } else if (!(gBattleStatus.flags1 & BS_FLAGS1_TUTORIAL_BATTLE) && (gGameStatusPtr->pressedButtons[0] & BUTTON_Z)) {
                if (btl_player_can_act()) {
                    sfx_play_sound(SOUND_PARTNER_SWAP_BATTLE_POS);
                    battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_MAIN] = WheelOptionSubmenu[BattleMenu_CurPos + BattleMenu_HomePos];
                    btl_main_menu_destroy();
                    btl_set_state(BATTLE_STATE_SWITCH_TO_PLAYER);
                } else {
                    sfx_play_sound(SOUND_MENU_ERROR);
                    gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_MAIN_SHOW_CANT_SWAP;
                }
                break;
            }

            if (BattleMenu_ChooseDelay != 0) {
                BattleMenu_ChooseDelay--;
            } else if (entryIdx != 0) {
                set_actor_anim(ACTOR_PARTNER, 0, PartnerIdleAnims[playerData->curPartner]);
                battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_MAIN] = battleStatus->curPartnerSubmenu = WheelOptionSubmenu[entryIdx - 1];
                if (battleStatus->curPartnerSubmenu == 7) {
                    gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_BUILD_MENU;
                    btl_state_update_partner_menu();
                    btl_state_update_partner_menu();
                } else if (battleStatus->curPartnerSubmenu == 6) {
                    gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_ABILITIES_BUILD_MENU;
                    btl_state_update_partner_menu();
                    btl_state_update_partner_menu();
                } else if (battleStatus->curPartnerSubmenu == 8) {
                    gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_FOCUS_BUILD_MENU;
                    btl_state_update_partner_menu();
                    btl_state_update_partner_menu();
                } else if (battleStatus->curPartnerSubmenu == 2) {
                    gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_ITEMS_BUILD_MENU;
                    btl_state_update_partner_menu();
                    btl_state_update_partner_menu();
                } else if (battleStatus->curPartnerSubmenu == 5) {
                    gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_BUILD_MENU;
                    btl_state_update_partner_menu();
                    btl_state_update_partner_menu();
                } else {
                    battleStatus->cancelTargetMenuSubstate = BTL_SUBSTATE_PARTNER_MENU_MAIN_TARGET_CANCEL;
                    battleStatus->acceptTargetMenuSubstate = BTL_SUBSTATE_PARTNER_MENU_MAIN_TARGET_CHOSEN;
                    btl_main_menu_hide();
                    gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_MAIN_HANDOVER;
                }
            }
            break;
    case BTL_SUBSTATE_PARTNER_MENU_MAIN_HANDOVER:
        entryIdx = btl_main_menu_update();
        if ((battleStatus->curButtonsPressed & BUTTON_B) && entryIdx == POPUP_RESULT_CHOOSING) {
            btl_main_menu_restore_choose();
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_MAIN_REOPEN_MENU;
            return;
        }
        if (entryIdx != POPUP_RESULT_CHOOSING) {
            battleStatus->moveCategory = BTL_MENU_TYPE_STAR_POWERS;
            battleStatus->selectedMoveID = MOVE_FOCUS;
            battleStatus->moveArgument = 0;
            battleStatus->curTargetListFlags = gMoveTable[MOVE_FOCUS].flags;
            btl_set_state(BATTLE_STATE_SELECT_TARGET);
            return;
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_MAIN_REOPEN_MENU:
        if (btl_main_menu_update() != 0) {
            BattleMenu_ChooseDelay = 8;
            BattleMenu_SwapDelay = 4;
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_MAIN_BEGIN;
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_MAIN_TARGET_CANCEL:
        btl_main_menu_restore_choose();
        gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_MAIN_REOPEN_MENU;
        break;
    case BTL_SUBSTATE_PARTNER_MENU_MAIN_TARGET_CHOSEN:
        btl_main_menu_destroy();
        break;
    case BTL_SUBSTATE_PARTNER_MENU_MAIN_SHOW_CANT_SWAP:
        if (btl_player_can_act() == 0) {
            btl_show_variable_battle_message(BTL_MSG_CANT_MOVE, 60, 0);
        } else {
            btl_show_variable_battle_message(BTL_MSG_CANT_SWITCH, 60, 0);
        }
        ShowingErrorMessage = true;
        gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_MAIN_AWAIT_CANT_SWAP;
        break;
    case BTL_SUBSTATE_PARTNER_MENU_MAIN_AWAIT_CANT_SWAP:
        if (btl_is_popup_displayed()) {
            break;
        }
        BattleMenu_ChooseDelay = 0;
        ShowingErrorMessage = false;
        BattleMenu_SwapDelay = 4;
        gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_MAIN_BEGIN;
        break;
    case BTL_SUBSTATE_PARTNER_MENU_ABILITIES_BUILD_MENU:
        for (i = 0; i < battleStatus->submenuMoveCount; i++) {
            moveData = &gMoveTable[battleStatus->submenuMoves[i]];

            MovesOptionError[i] = 0;
            if (battleStatus->submenuStatus[i] == 0) {
                MovesOptionError[i] = 0;
            }
            if (battleStatus->submenuStatus[i] == -1) {
                battleStatus->submenuStatus[i] = 0;
                MovesOptionError[i] = BTL_MSG_CANT_SELECT_NOW;
            }
            if (battleStatus->submenuStatus[i] == -2) {
                battleStatus->submenuStatus[i] = 0;
                MovesOptionError[i] = BTL_MSG_CANT_SELECT_NOW;
            }
            MovesOptionHudScripts[i] = PartnerMoveHudScripts[playerData->curPartner][2 * i + 2];
            if (battleStatus->submenuStatus[i] == 0) {
                MovesOptionHudScripts[i] = PartnerMoveHudScripts[playerData->curPartner][2 * i + 3];
            }
            MovesOptionIndices[i] = battleStatus->submenuMoves[i];
            MovesOptionEnabled[i] = battleStatus->submenuStatus[i];
            MovesOptionNames[i] = moveData->nameMsg;
            MovesOptionDesc[i] = moveData->shortDescMsg;
            MovesOptionDisplayCosts[i] = moveData->costFP;
            MovesOptionBPCosts[i] = moveData->costBP;
            MovesOptionSortPriority[i] = i;

            MovesOptionDiscounts[i] = 0;
            MovesOptionDiscountColors[i] = 0;
            if (player_team_is_ability_active(playerActor, ABILITY_FLOWER_SAVER)) {
                MovesOptionDiscounts[i] += player_team_is_ability_active(playerActor, ABILITY_FLOWER_SAVER);
                MovesOptionDiscountColors[i] = 1;
            }
            if (player_team_is_ability_active(playerActor, ABILITY_FLOWER_FANATIC)) {
                MovesOptionDiscounts[i] += player_team_is_ability_active(playerActor, ABILITY_FLOWER_FANATIC) * 2;
                MovesOptionDiscountColors[i] = 2;
            }
        }
        if (battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_ABILITY] < 0) {
            battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_ABILITY] = 0;
        }
        UsingSpiritsSubmenu = false;
        MovesOptionCount = battleStatus->submenuMoveCount;
        initialPos = battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_ABILITY];
        MovesPrevSelected = initialPos;
        btl_submenu_moves_init();
        gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_ABILITIES_CHOOSING;
        break;
    case BTL_SUBSTATE_PARTNER_MENU_ABILITIES_CHOOSING:
        entryIdx = btl_submenu_moves_update();
        if (entryIdx == POPUP_RESULT_INVALID) {
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_ABILITIES_SHOW_ERROR;
        } else if (entryIdx != POPUP_RESULT_CHOOSING) {
            if (entryIdx == POPUP_RESULT_CANCEL) {
                btl_main_menu_resume_choose();
                BattleMenu_ChooseDelay = 8;
                BattleMenu_SwapDelay = 4;
                gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_MAIN_BEGIN;
                btl_state_update_partner_menu();
                btl_state_update_partner_menu();
            } else {
                battleStatus->lastPartnerPowerSelection = entryIdx - 1;
                btl_submenu_moves_hide();
                btl_main_menu_hide();
                gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_ABILITIES_HANDOVER;
            }
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_ABILITIES_HANDOVER:
        entryIdx = btl_submenu_moves_update();
        if ((battleStatus->curButtonsPressed & BUTTON_B) && entryIdx == POPUP_RESULT_CHOOSING) {
            btl_submenu_moves_restore_choose();
            btl_main_menu_restore_submenu();
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_ABILITIES_REOPEN_MENU;
        } else if (btl_main_menu_update() != 0) {
            battleStatus->moveCategory = BTL_MENU_TYPE_ABILITY;
            battleStatus->selectedMoveID = MovesOptionIndices[battleStatus->lastPartnerPowerSelection];
            battleStatus->curTargetListFlags = gMoveTable[battleStatus->selectedMoveID].flags;
            battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_ABILITY] = SelectedMovesIndex;
            battleStatus->cancelTargetMenuSubstate = BTL_SUBSTATE_PARTNER_MENU_ABILITIES_TARGET_CANCEL;
            battleStatus->acceptTargetMenuSubstate = BTL_SUBSTATE_PARTNER_MENU_ABILITIES_TARGET_CHOSEN;
            btl_set_state(BATTLE_STATE_SELECT_TARGET);
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_ABILITIES_REOPEN_MENU:
        btl_submenu_moves_update();
        if (btl_main_menu_update() != 0) {
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_ABILITIES_CHOOSING;
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_ABILITIES_TARGET_CANCEL:
        btl_submenu_moves_restore_choose();
        btl_main_menu_restore_submenu();
        gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_ABILITIES_REOPEN_MENU;
        break;
    case BTL_SUBSTATE_PARTNER_MENU_ABILITIES_TARGET_CHOSEN:
        btl_submenu_moves_destroy();
        btl_main_menu_destroy();
        break;
    case BTL_SUBSTATE_PARTNER_MENU_ABILITIES_SHOW_ERROR:
        if (btl_submenu_moves_update() != -1) {
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_ABILITIES_CHOOSING;
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_ITEMS_BUILD_MENU:
        popupIndex = 0;
        for (i = 0; i < ARRAY_COUNT(playerData->invItems); i++) {
            ItemData* item;
            HudScript** hudScript;
            if (playerData->invItems[i] == ITEM_NONE) {
                continue;
            }
            item = &gItemTable[playerData->invItems[i]];
            hudScript = &gItemHudScripts[item->hudElemID].enabled;

            if (!(item->typeFlags & ITEM_TYPE_FLAG_BATTLE_USABLE)) {
                continue;
            }
            popupMenu->ptrIcon[popupIndex] = hudScript[0];
            popupMenu->userIndex[popupIndex] = playerData->invItems[i];
            popupMenu->enabled[popupIndex] = true;
            popupMenu->nameMsg[popupIndex] = item->nameMsg;
            popupMenu->descMsg[popupIndex] = item->shortDescMsg;
            popupIndex++;
        }
        if (battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_PARTNER_ITEM] < 0) {
            battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_PARTNER_ITEM] = 0;
        }
        popupMenu->popupType = POPUP_MENU_USE_ITEM;
        popupMenu->numEntries = popupIndex;
        popupMenu->dipMode = 0;
        popupMenu->titleNumber = 0;
        initialPos = battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_PARTNER_ITEM];
        popupMenu->initialPos = initialPos;
        create_battle_popup_menu(popupMenu);
        flush_popup_menu();
        gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_ITEMS_CHOOSING;
        break;
    case BTL_SUBSTATE_PARTNER_MENU_ITEMS_CHOOSING:
        if (popupMenu->result != POPUP_RESULT_CHOOSING) {
            if (popupMenu->result == POPUP_RESULT_CANCEL) {
                btl_main_menu_resume_choose();
                BattleMenu_ChooseDelay = 8;
                BattleMenu_SwapDelay = 4;
                gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_MAIN_BEGIN;
                btl_state_update_partner_menu();
                btl_state_update_partner_menu();
            } else {
                battleStatus->cancelTargetMenuSubstate = BTL_SUBSTATE_PARTNER_MENU_ITEMS_TARGET_CANCEL;
                battleStatus->acceptTargetMenuSubstate = BTL_SUBSTATE_PARTNER_MENU_ITEMS_TARGET_CHOSEN;
                battleStatus->lastSelectedItem = popupMenu->userIndex[popupMenu->result - 1];
                battleStatus->moveCategory = BTL_MENU_TYPE_ITEMS;
                battleStatus->moveArgument = battleStatus->lastSelectedItem;
                battleStatus->curTargetListFlags = gItemTable[battleStatus->moveArgument].targetFlags | TARGET_FLAG_PRIMARY_ONLY;
                battleStatus->curAttackElement = 0;
                battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_PARTNER_ITEM] = popupMenu->result - 1;
                hide_popup_menu();
                btl_main_menu_hide();
                gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_ITEMS_HANDOVER;
            }
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_ITEMS_HANDOVER:
        if ((battleStatus->curButtonsPressed & BUTTON_B) && popupMenu->result == POPUP_RESULT_CHOOSING) {
            show_popup_menu();
            btl_main_menu_restore_submenu();
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_ITEMS_REOPEN_MENU;
        } else if (btl_main_menu_update() != 0) {
            btl_set_state(BATTLE_STATE_SELECT_TARGET);
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_ITEMS_REOPEN_MENU:
        if (btl_main_menu_update() != 0) {
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_ITEMS_CHOOSING;
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_ITEMS_TARGET_CANCEL:
        show_popup_menu();
        btl_main_menu_restore_submenu();
        gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_ITEMS_REOPEN_MENU;
        break;
    case BTL_SUBSTATE_PARTNER_MENU_ITEMS_TARGET_CHOSEN:
        destroy_popup_menu();
        btl_main_menu_destroy();
        break;
    case BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_BUILD_MENU:
        popupIndex = 0;
        for (i = 1; i < ARRAY_COUNT(PartnerIDFromMenuIndex); i++) {
            s32 partnerId = PartnerIDFromMenuIndex[i];
            if (playerData->partners[partnerId].enabled) {
                popupProps = &gPartnerPopupProperties[partnerId];
                popupMenu->ptrIcon[popupIndex] = PartnerHudScripts[partnerId];
                popupMenu->userIndex[popupIndex] = partnerId;
                popupMenu->enabled[popupIndex] = 1;
                popupMenu->nameMsg[popupIndex] = popupProps->nameMsg;
                popupMenu->descMsg[popupIndex] = popupProps->battleDescMsg;
                popupMenu->value[popupIndex] = playerData->partners[partnerId].level;
                if (playerData->curPartner == partnerId) {
                    popupMenu->enabled[popupIndex] = 0;
                    popupMenu->ptrIcon[popupIndex] = battle_menu_DisabledPartnerHudScripts[partnerId];
                }
                popupIndex++;
            }
        }
        if (battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_PARTNER] < 0) {
            battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_PARTNER] = 0;
        }
        popupMenu->popupType = POPUP_MENU_SWITCH_PARTNER;
        popupMenu->numEntries = popupIndex;
        popupMenu->initialPos = MenuIndexFromPartnerID[playerData->curPartner] - 1;
        popupMenu->dipMode = 0;
        popupMenu->titleNumber = 0;
        create_battle_popup_menu(popupMenu);
        flush_popup_menu();
        gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_CHOOSING;
        break;
    case BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_CHOOSING:
        if (popupMenu->result == POPUP_RESULT_INVALID) {
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_SHOW_ERROR;
        } else if (popupMenu->result != POPUP_RESULT_CHOOSING) {
            if (popupMenu->result == POPUP_RESULT_CANCEL) {
                btl_main_menu_resume_choose();
                BattleMenu_ChooseDelay = 8;
                BattleMenu_SwapDelay = 4;
                gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_MAIN_BEGIN;
                btl_state_update_partner_menu();
                btl_state_update_partner_menu();
            } else {
                battleStatus->cancelTargetMenuSubstate = BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_TARGET_CANCEL;
                battleStatus->acceptTargetMenuSubstate = BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_TARGET_CHOSEN;
                battleStatus->lastSelectedPartner = popupMenu->userIndex[popupMenu->result - 1];
                battleStatus->moveCategory = BTL_MENU_TYPE_CHANGE_PARTNER;
                battleStatus->selectedMoveID = MOVE_CHANGE_PARTNER;
                battleStatus->curTargetListFlags = TARGET_FLAG_2;
                battleStatus->moveArgument = battleStatus->lastSelectedPartner;
                battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_PARTNER] = popupMenu->result - 1;
                hide_popup_menu();
                btl_main_menu_hide();
                gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_HANDOVER;
            }
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_HANDOVER:
        if ((battleStatus->curButtonsPressed & BUTTON_B) && (popupMenu->result == POPUP_RESULT_CHOOSING)) {
            show_popup_menu();
            btl_main_menu_restore_submenu();
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_REOPEN_MENU;
        } else if (btl_main_menu_update() != 0) {
            gBattleSubState = battleStatus->acceptTargetMenuSubstate;
            btl_state_update_partner_menu();
            btl_set_state(BATTLE_STATE_CHANGE_PARTNER);
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_REOPEN_MENU:
        if (btl_main_menu_update() != 0) {
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_CHOOSING;
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_TARGET_CANCEL:
        show_popup_menu();
        btl_main_menu_restore_submenu();
        gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_REOPEN_MENU;
        break;
    case BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_TARGET_CHOSEN:
        destroy_popup_menu();
        btl_main_menu_destroy();
        break;
    case BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_SHOW_ERROR:
        if (popupMenu->result != POPUP_RESULT_INVALID) {
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_CHOOSING;
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_FOCUS_BUILD_MENU:
        entryIdx = 1;
        battleStatus->submenuMoves[0] = MOVE_FOCUS;
        battleStatus->submenuMoveCount = entryIdx;
        battleStatus->submenuIcons[0] = ITEM_PARTNER_ATTACK;
        battleStatus->submenuStatus[0] = 1;
        for (i = 0; i < battleStatus->submenuMoveCount; i++) {
            moveData = &gMoveTable[battleStatus->submenuMoves[i]];
            MovesOptionHudScripts[i] = StarPowerMovesHudScripts[2 * STAR_POWER_INDEX(battleStatus->submenuMoves[i]) + 0];
            if (battleStatus->submenuStatus[i] == 0) {
                MovesOptionHudScripts[i] = StarPowerMovesHudScripts[2 * STAR_POWER_INDEX(battleStatus->submenuMoves[i]) + 1];
            }
            MovesOptionDisplayCosts[i] = moveData->costFP;
            MovesOptionBPCosts[i] = moveData->costBP;
            MovesOptionIndices[i] = i;
            MovesOptionSortPriority[i] = i;
            MovesOptionEnabled[i] = battleStatus->submenuStatus[i];
            MovesOptionNames[i] = moveData->nameMsg;
            MovesOptionDesc[i] = moveData->shortDescMsg;
            MovesOptionDiscounts[i] = 0;
            MovesOptionDiscountColors[i] = 0;
        }
        if (battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_STAR_POWER] < 0) {
            battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_STAR_POWER] = 0;
        }
        UsingSpiritsSubmenu = true;
        MovesOptionCount = battleStatus->submenuMoveCount;
        initialPos = battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_STAR_POWER];
        MovesPrevSelected = initialPos;
        btl_submenu_moves_init();
        gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_FOCUS_CHOOSING;
        break;
    case BTL_SUBSTATE_PARTNER_MENU_FOCUS_CHOOSING:
        entryIdx = btl_submenu_moves_update();
        if (entryIdx != POPUP_RESULT_CHOOSING) {
            if (entryIdx == POPUP_RESULT_CANCEL) {
                btl_main_menu_resume_choose();
                BattleMenu_ChooseDelay = 8;
                BattleMenu_SwapDelay = 4;
                gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_MAIN_BEGIN;
                btl_state_update_partner_menu();
                btl_state_update_partner_menu();
            } else {
                battleStatus->lastPartnerPowerSelection = MovesOptionIndices[entryIdx - 1];
                btl_submenu_moves_hide();
                btl_main_menu_hide();
                gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_FOCUS_HANDOVER;
            }
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_FOCUS_HANDOVER:
        entryIdx = btl_submenu_moves_update();
        if ((battleStatus->curButtonsPressed & BUTTON_B) && (entryIdx == POPUP_RESULT_CHOOSING)) {
            btl_submenu_moves_restore_choose();
            btl_main_menu_restore_submenu();
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_FOCUS_REOPEN_MENU;
        } else if (btl_main_menu_update() != 0) {
            battleStatus->cancelTargetMenuSubstate = BTL_SUBSTATE_PARTNER_MENU_FOCUS_CANCELED;
            battleStatus->acceptTargetMenuSubstate = BTL_SUBSTATE_PARTNER_MENU_FOCUS_SELECTED;
            battleStatus->moveCategory = BTL_MENU_TYPE_STAR_POWERS;
            battleStatus->selectedMoveID = battleStatus->submenuMoves[battleStatus->lastPartnerPowerSelection];
            battleStatus->curTargetListFlags = gMoveTable[battleStatus->submenuMoves[battleStatus->lastPartnerPowerSelection]].flags;
            battleStatus->moveArgument = battleStatus->lastPartnerPowerSelection;
            battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_STAR_POWER] = SelectedMovesIndex;
            btl_set_state(BATTLE_STATE_SELECT_TARGET);
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_FOCUS_REOPEN_MENU:
        btl_submenu_moves_update();
        if (btl_main_menu_update() != 0) {
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_FOCUS_CHOOSING;
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_FOCUS_CANCELED:
        btl_submenu_moves_restore_choose();
        btl_main_menu_restore_submenu();
        gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_FOCUS_REOPEN_MENU;
        break;
    case BTL_SUBSTATE_PARTNER_MENU_FOCUS_SELECTED:
        btl_submenu_moves_destroy();
        btl_main_menu_destroy();
        break;
    case BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_BUILD_MENU:
        popupIndex = 0;
        btl_check_can_change_partner();

        // add 'Change Member' command
        if (battleStatus->changePartnerAllowed >= 0) {
            StratsOptionMenuTypes[popupIndex] = BTL_MENU_TYPE_CHANGE_PARTNER;
            StratsOptionNames[popupIndex] = LeftJustMenuMessages[BTL_MENU_TYPE_CHANGE_PARTNER];
            StratsOptionHudScripts[popupIndex] = PartnerHudScripts[playerData->curPartner];
            StratsOptionEnabled[popupIndex] = 1;
            StratsOptionMessage[popupIndex] = MSG_Menus_Action_ChangePartner;
            if (battleStatus->changePartnerAllowed <= 0) {
                StratsOptionHudScripts[popupIndex] = battle_menu_DisabledPartnerHudScripts[playerData->curPartner];
                StratsOptionEnabled[popupIndex] = 0;
                StratsOptionError[popupIndex] = 0;
            }
            popupIndex++;
        }

        // add 'Do Nothing' command
        StratsOptionHudScripts[popupIndex] = DoNothingHudScripts.enabled;
        StratsOptionMenuTypes[popupIndex] = BTL_MENU_TYPE_DO_NOTHING;
        StratsOptionEnabled[popupIndex] = 1;
        StratsOptionNames[popupIndex] = LeftJustMenuMessages[BTL_MENU_TYPE_DO_NOTHING];
        StratsOptionMessage[popupIndex] = MSG_Menus_Action_DoNothing;
        popupIndex++;

        if (battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_STRATEGY] < 0) {
            battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_STRATEGY] = 0;
        }
        StratsOptionCount = popupIndex;
        initialPos = battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_STRATEGY];
        StratsPrevSelected = initialPos;
        btl_menu_strats_init();
        gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_CHOOSING;
        break;
    case BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_CHOOSING:
        entryIdx = btl_submenu_strats_update();
        if (entryIdx == POPUP_RESULT_CHOOSING) {
        } else if (entryIdx == POPUP_RESULT_CANCEL) {
            btl_main_menu_resume_choose();
            BattleMenu_ChooseDelay = 8;
            BattleMenu_SwapDelay = 4;
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_MAIN_BEGIN;
            btl_state_update_partner_menu();
            btl_state_update_partner_menu();
        } else {
            battleStatus->curPartnerSubmenu = StratsOptionMenuTypes[entryIdx - 1];
            battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_STRATEGY] = entryIdx - 1;
            if (battleStatus->curPartnerSubmenu == 5) { // change partner
                gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_BUILD_MENU;
                btl_state_update_partner_menu();
                btl_state_update_partner_menu();
            } else {
                btl_submenu_strats_hide();
                btl_main_menu_hide();
                gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_HANDOVER;
            }
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_HANDOVER:
        entryIdx = btl_submenu_strats_update();
        if ((battleStatus->curButtonsPressed & BUTTON_B) && entryIdx == POPUP_RESULT_CHOOSING) {
            btl_submenu_strats_restore_choose();
            btl_main_menu_restore_submenu();
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_REOPEN_MENU;
        } else if (btl_main_menu_update() != 0) {
            battleStatus->cancelTargetMenuSubstate = BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_TARGET_CANCEL;
            battleStatus->acceptTargetMenuSubstate = BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_TARGET_CHOSEN;
            entryIdx = battleStatus->curPartnerSubmenu;
            switch (entryIdx) {
                case 9:
                    gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_TARGET_CHOSEN;
                    btl_state_update_partner_menu();
                    btl_set_state(BATTLE_STATE_END_PARTNER_TURN);
                    break;
                case 3:
                    gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_TARGET_CHOSEN;
                    btl_state_update_partner_menu();
                    battleStatus->moveCategory = entryIdx;
                    battleStatus->selectedMoveID = MOVE_RUN_AWAY;
                    btl_set_state(BATTLE_STATE_RUN_AWAY);
                    break;
                case 10:
                    gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_TARGET_CHOSEN;
                    btl_state_update_partner_menu();
                    btl_set_state(BATTLE_STATE_SWITCH_TO_PLAYER);
                    break;
            }
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_REOPEN_MENU:
        btl_submenu_strats_update();
        if (btl_main_menu_update() != 0) {
            BattleMenu_ChooseDelay = 8;
            BattleMenu_SwapDelay = 4;
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_MAIN_BEGIN;
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_TARGET_CANCEL:
        btl_submenu_strats_restore_choose();
        btl_main_menu_restore_submenu();
        gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_REOPEN_MENU;
        break;
    case BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_TARGET_CHOSEN:
        btl_submenu_strats_destroy();
        btl_main_menu_destroy();
        break;
    case BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_BUILD_MENU:
        popupIndex = 0;
        for (i = 1; i < ARRAY_COUNT(PartnerIDFromMenuIndex); i++) {
            s32 partnerId = PartnerIDFromMenuIndex[i];
            if (playerData->partners[partnerId].enabled) {
                popupProps = &gPartnerPopupProperties[partnerId];
                popupMenu->ptrIcon[popupIndex] = PartnerHudScripts[partnerId];
                popupMenu->userIndex[popupIndex] = partnerId;
                popupMenu->enabled[popupIndex] = 1;
                popupMenu->nameMsg[popupIndex] = popupProps->nameMsg;
                popupMenu->descMsg[popupIndex] = popupProps->battleDescMsg;
                popupMenu->value[popupIndex] = playerData->partners[partnerId].level;
                if (playerData->curPartner == partnerId) {
                    popupMenu->enabled[popupIndex] = 0;
                    popupMenu->ptrIcon[popupIndex] = battle_menu_DisabledPartnerHudScripts[partnerId];
                }
                popupIndex++;
            }
        }
        if (battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_PARTNER] < 0) {
            battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_PARTNER] = 0;
        }
        popupMenu->popupType = POPUP_MENU_SWITCH_PARTNER;
        popupMenu->numEntries = popupIndex;
        popupMenu->initialPos = MenuIndexFromPartnerID[playerData->curPartner] - 1;
        popupMenu->dipMode = 0;
        popupMenu->titleNumber = 0;
        create_battle_popup_menu(popupMenu);
        flush_popup_menu();
        gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_CHOOSING;
        break;
    case BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_CHOOSING:
        if (popupMenu->result == POPUP_RESULT_INVALID) {
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_ERROR;
        } else if (popupMenu->result != POPUP_RESULT_CHOOSING) {
            if (popupMenu->result == POPUP_RESULT_CANCEL) {
                btl_submenu_strats_resume_choose();
                gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_CHOOSING;
                btl_state_update_partner_menu();
                btl_state_update_partner_menu();
            } else {
                battleStatus->cancelTargetMenuSubstate = BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_TARGET_CANCEL;
                battleStatus->acceptTargetMenuSubstate = BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_TARGET_CHOSEN;
                battleStatus->lastSelectedPartner = popupMenu->userIndex[popupMenu->result - 1];
                battleStatus->moveCategory = BTL_MENU_TYPE_CHANGE_PARTNER;
                battleStatus->selectedMoveID = MOVE_CHANGE_PARTNER;
                battleStatus->curTargetListFlags = TARGET_FLAG_2;
                battleStatus->moveArgument = battleStatus->lastSelectedPartner;
                battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_PARTNER] = popupMenu->result - 1;
                hide_popup_menu();
                btl_submenu_strats_hide();
                btl_main_menu_hide();
                gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_HANDOVER;
            }
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_HANDOVER:
        if ((battleStatus->curButtonsPressed & BUTTON_B) && popupMenu->result == POPUP_RESULT_CHOOSING) {
            show_popup_menu();
            btl_submenu_strats_restore_locked();
            btl_main_menu_restore_submenu();
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_REOPEN_MENU;
        } else {
            btl_submenu_strats_update();
            if (btl_main_menu_update() != 0) {
                gBattleSubState = battleStatus->acceptTargetMenuSubstate;
                btl_state_update_partner_menu();
                btl_set_state(BATTLE_STATE_CHANGE_PARTNER);
            }
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_REOPEN_MENU:
        btl_submenu_strats_update();
        if (btl_main_menu_update() != 0) {
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_CHOOSING;
        }
        break;
    case BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_TARGET_CANCEL:
        show_popup_menu();
        btl_submenu_strats_restore_locked();
        btl_main_menu_restore_submenu();
        gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_REOPEN_MENU;
        break;
    case BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_TARGET_CHOSEN:
        destroy_popup_menu();
        btl_submenu_strats_destroy();
        btl_main_menu_destroy();
        break;
    case BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_ERROR:
        set_window_update(WIN_BTL_STRATS_MENU, WINDOW_UPDATE_HIDE);
        set_window_update(WIN_BTL_STRATS_TITLE, WINDOW_UPDATE_HIDE);
        if (popupMenu->result != POPUP_RESULT_INVALID) {
            set_window_update(WIN_BTL_STRATS_MENU, WINDOW_UPDATE_9);
            set_window_update(WIN_BTL_STRATS_TITLE, WINDOW_UPDATE_9);
            gBattleSubState = BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_CHOOSING;
        }
        break;
    }
}

void btl_state_draw_partner_menu(void) {
    switch (gBattleSubState) {
        case BTL_SUBSTATE_PARTNER_MENU_MAIN_BEGIN:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_PARTNER_MENU_MAIN_CHOOSING:
        case BTL_SUBSTATE_PARTNER_MENU_MAIN_HANDOVER:
        case BTL_SUBSTATE_PARTNER_MENU_MAIN_REOPEN_MENU:
        case BTL_SUBSTATE_PARTNER_MENU_MAIN_TARGET_CANCEL:
        case BTL_SUBSTATE_PARTNER_MENU_ABILITIES_BUILD_MENU:
        case BTL_SUBSTATE_PARTNER_MENU_ABILITIES_CHOOSING:
        case BTL_SUBSTATE_PARTNER_MENU_ABILITIES_HANDOVER:
        case BTL_SUBSTATE_PARTNER_MENU_ABILITIES_REOPEN_MENU:
        case BTL_SUBSTATE_PARTNER_MENU_ABILITIES_TARGET_CANCEL:
        case BTL_SUBSTATE_PARTNER_MENU_UNKNOWN_1:
        case BTL_SUBSTATE_PARTNER_MENU_UNKNOWN_2:
        case BTL_SUBSTATE_PARTNER_MENU_UNKNOWN_3:
        case BTL_SUBSTATE_PARTNER_MENU_UNKNOWN_4:
        case BTL_SUBSTATE_PARTNER_MENU_UNKNOWN_5:
        case BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_BUILD_MENU:
        case BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_CHOOSING:
        case BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_HANDOVER:
        case BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_REOPEN_MENU:
        case BTL_SUBSTATE_PARTNER_MENU_CHANGE_PARTNER_TARGET_CANCEL:
        case BTL_SUBSTATE_PARTNER_MENU_ITEMS_BUILD_MENU:
        case BTL_SUBSTATE_PARTNER_MENU_ITEMS_CHOOSING:
        case BTL_SUBSTATE_PARTNER_MENU_ITEMS_HANDOVER:
        case BTL_SUBSTATE_PARTNER_MENU_ITEMS_REOPEN_MENU:
        case BTL_SUBSTATE_PARTNER_MENU_ITEMS_TARGET_CANCEL:
        case BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_CHOOSING:
        case BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_HANDOVER:
        case BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_REOPEN_MENU:
        case BTL_SUBSTATE_PARTNER_MENU_UNUSED_CHANGE_PARTNER_TARGET_CANCEL:
        case BTL_SUBSTATE_PARTNER_MENU_FOCUS_CHOOSING:
        case BTL_SUBSTATE_PARTNER_MENU_FOCUS_HANDOVER:
        case BTL_SUBSTATE_PARTNER_MENU_FOCUS_REOPEN_MENU:
        case BTL_SUBSTATE_PARTNER_MENU_FOCUS_CANCELED:
        case BTL_SUBSTATE_PARTNER_MENU_FOCUS_SELECTED:
        case BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_BUILD_MENU:
        case BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_CHOOSING:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_HANDOVER:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_REOPEN_MENU:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_TARGET_CANCEL:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_PARTNER_MENU_STRATEGIES_TARGET_CHOSEN:
            btl_main_menu_draw();
            break;
    }
}

s32 btl_menu_show_switch_to_twink(void) {
    if (gBattleStatus.flags2 & BS_FLAGS2_PARTNER_TURN_USED) {
        return false;
    }
    return true;
}

void btl_state_update_peach_menu(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    s32 selectedOption;
    s32 initialPos;
    s32 entryIdx;

    switch (gBattleSubState) {
        case BTL_SUBSTATE_PEACH_MENU_INIT:
            btl_cam_use_preset(BTL_CAM_DEFAULT);
            btl_cam_move(10);
            if (!(gBattleStatus.flags1 & BS_FLAGS1_PLAYER_IN_BACK)) {
                gBattleSubState = BTL_SUBSTATE_PEACH_CREATE_MAIN_MENU;
                break;
            }
            player->state.curPos.x = player->homePos.x;
            player->state.curPos.z = player->homePos.z;
            gBattleSubState = BTL_SUBSTATE_PEACH_MENU_PERFORM_SWAP;
            player->state.goalPos.x = partner->homePos.x;
            player->state.goalPos.z = partner->homePos.z;
            player->state.moveTime = 4;
            player->state.angle = 0.0f;
            break;
        case BTL_SUBSTATE_PEACH_MENU_PERFORM_SWAP:
            if (player->state.moveTime != 0) {
                player->curPos.x += (player->state.goalPos.x - player->curPos.x) / player->state.moveTime;
                player->curPos.z += (player->state.goalPos.z - player->curPos.z) / player->state.moveTime;
                partner->curPos.x += (player->state.curPos.x - partner->curPos.x) / player->state.moveTime;
                partner->curPos.z += (player->state.curPos.z - partner->curPos.z) / player->state.moveTime;
            }

            player->curPos.z -= sin_rad(DEG_TO_RAD(player->state.angle)) * 16.0f;
            player->yaw = clamp_angle(-player->state.angle);
            partner->curPos.z += sin_rad(DEG_TO_RAD(player->state.angle)) * 16.0f;
            partner->yaw = clamp_angle(-player->state.angle);
            player->state.angle += 90.0f;

            if (player->state.moveTime != 0) {
                player->state.moveTime--;
                break;
            }

            player->curPos.x = player->state.goalPos.x;
            player->curPos.z = player->state.goalPos.z;
            partner->curPos.x = player->state.curPos.x;
            partner->curPos.z = player->state.curPos.z;
            player->homePos.x = player->curPos.x;
            player->homePos.z = player->curPos.z;
            partner->homePos.x = partner->curPos.x;
            partner->homePos.z = partner->curPos.z;
            gBattleStatus.flags1 &= ~BS_FLAGS1_PLAYER_IN_BACK;
        case BTL_SUBSTATE_PEACH_CREATE_MAIN_MENU:
            gBattleStatus.flags1 |= BS_FLAGS1_MENU_OPEN;
            player->flags &= ~ACTOR_FLAG_USING_IDLE_ANIM;
            player->flags |= ACTOR_FLAG_SHOW_STATUS_ICONS;
            if (partner != nullptr) {
                partner->flags |= ACTOR_FLAG_USING_IDLE_ANIM;
                partner->flags |= ACTOR_FLAG_SHOW_STATUS_ICONS;
            }

            entryIdx = 0;
            battleStatus->selectedMoveID = MOVE_NONE;
            WheelOptionSubmenu[entryIdx] = BTL_MENU_TYPE_STAR_POWERS;
            WheelOptionEnabled[entryIdx] = true;
            WheelOptionError[entryIdx] = 0;
            WheelOptionHudScript[entryIdx] = PeachStarPowerHudScripts.enabled;
            WheelOptionName[entryIdx] = PeachMenuMessages[entryIdx];
            if (!(battleStatus->enabledMenusFlags & BTL_MENU_ENABLED_STAR_POWERS)) {
                WheelOptionEnabled[entryIdx] = false;
                WheelOptionError[entryIdx] = BTL_MSG_CANT_SELECT_NOW;
                WheelOptionHudScript[entryIdx] = PeachStarPowerHudScripts.disabled;
            }

            initialPos = 0;
            entryIdx++;

            if (btl_menu_show_switch_to_twink()) {
                BattleMenu_ShowSwapIcons = true;
            } else {
                BattleMenu_ShowSwapIcons = false;
            }
            WheelOptionCount = entryIdx;
            D_802AD0A8 = 0;
            BattleMenu_PrevSelected = initialPos;
            BattleMenu_WheelBase = 2 - initialPos;

            btl_main_menu_init();
            BattleMenu_ChooseDelay = 8;
            gBattleSubState = BTL_SUBSTATE_PEACH_MENU_CHOOSE_CATEGORY;
            break;
        case BTL_SUBSTATE_PEACH_MENU_CHOOSE_CATEGORY:
            set_actor_anim(ACTOR_PLAYER, 0, ANIM_Peach2_Delighted);
            selectedOption = btl_main_menu_update();
            if (BattleMenu_ChooseDelay != 0) {
                BattleMenu_ChooseDelay--;
                break;
            }
            if (selectedOption != 0) {
                set_actor_anim(ACTOR_PLAYER, 0, ANIM_Peach1_Walk);
                battleStatus->curSubmenu = WheelOptionSubmenu[selectedOption - 1];
                btl_main_menu_hide();
                BattleMenu_ChooseDelay = 8;
                BattleMenu_SwapDelay = 4;
                gBattleSubState = BTL_SUBSTATE_PEACH_MENU_CHOOSE_TARGET;
            }
            break;
        case BTL_SUBSTATE_PEACH_MENU_CHOOSE_TARGET:
            if (btl_main_menu_update() != 0) {
                battleStatus->cancelTargetMenuSubstate = BTL_SUBSTATE_PEACH_MENU_TARGET_CANCEL;
                battleStatus->acceptTargetMenuSubstate = BTL_SUBSTATE_PEACH_MENU_TARGET_CHOSEN;
                battleStatus->curTargetListFlags = gMoveTable[MOVE_PEACH_FOCUS].flags;
                battleStatus->moveCategory = BTL_MENU_TYPE_STAR_POWERS;
                battleStatus->selectedMoveID = MOVE_PEACH_FOCUS;
                battleStatus->moveArgument = STAR_POWER_INDEX(MOVE_PEACH_FOCUS);
                btl_set_state(BATTLE_STATE_SELECT_TARGET);
            }
            break;
        case BTL_SUBSTATE_PEACH_MENU_TARGET_CANCEL:
            btl_main_menu_resume_choose();
            gBattleSubState = BTL_SUBSTATE_PEACH_MENU_CHOOSE_CATEGORY;
            btl_state_update_peach_menu();
            btl_state_update_peach_menu();
            break;
        case BTL_SUBSTATE_PEACH_MENU_TARGET_CHOSEN:
            btl_main_menu_destroy();
            break;
        case BTL_SUBSTATE_PEACH_MENU_SHOW_CANT_SWITCH:
            btl_show_variable_battle_message(BTL_MSG_CANT_SWITCH, 60, 0);
            ShowingErrorMessage = true;
            gBattleSubState = BTL_SUBSTATE_PEACH_MENU_AWAIT_CANT_SWITCH_POPUP;
            break;
        case BTL_SUBSTATE_PEACH_MENU_AWAIT_CANT_SWITCH_POPUP:
            if (btl_is_popup_displayed()) {
                break;
            }
            ShowingErrorMessage = false;
            BattleMenu_ChooseDelay = 0;
            gBattleSubState = BTL_SUBSTATE_PEACH_MENU_CHOOSE_CATEGORY;
            break;
    }
}

void btl_state_draw_peach_menu(void) {
    switch (gBattleSubState) {
        case BTL_SUBSTATE_PEACH_MENU_CHOOSE_CATEGORY:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_PEACH_MENU_CHOOSE_TARGET:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_PEACH_MENU_UNUSED_3:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_PEACH_MENU_TARGET_CANCEL:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_PEACH_MENU_TARGET_CHOSEN:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_PEACH_MENU_UNUSED_6:
        case BTL_SUBSTATE_PEACH_MENU_UNUSED_7:
        case BTL_SUBSTATE_PEACH_MENU_SHOW_CANT_SWITCH:
        case BTL_SUBSTATE_PEACH_MENU_AWAIT_CANT_SWITCH_POPUP:
            break;
    }
}

s32 btl_menu_show_switch_to_peach(void) {
    if (gBattleStatus.flags2 & BS_FLAGS2_PLAYER_TURN_USED) {
        return false;
    }
    return true;
}

void btl_state_update_twink_menu(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    s32 s1;
    s32 selection;
    s32 var_v0_2;
    s32 shouldSkipTurn;
    s32 initialPos;
    s32 entryIdx;

    switch (gBattleSubState) {
        case BTL_SUBSTATE_TWINK_MENU_INIT:
            shouldSkipTurn = false;
            if (player->debuff == STATUS_KEY_SLEEP) {
                shouldSkipTurn = true;
            }
            if (player->debuff == STATUS_KEY_UNUSED) {
                shouldSkipTurn = true;
            }
            if (player->debuff == STATUS_KEY_DIZZY) {
                shouldSkipTurn = true;
            }
            if (player->debuff == STATUS_KEY_PARALYZE) {
                shouldSkipTurn = true;
            }
            if (player->debuff == STATUS_KEY_FROZEN) {
                shouldSkipTurn = true;
            }
            if (player->debuff == STATUS_KEY_STOP) {
                shouldSkipTurn = true;
            }
            if (player->stoneStatus == STATUS_KEY_STONE) {
                shouldSkipTurn = true;
            }
            if (player->koStatus == STATUS_KEY_KO) {
                shouldSkipTurn = true;
            }

            if (shouldSkipTurn) {
                btl_set_state(BATTLE_STATE_END_PLAYER_TURN);
                break;
            }

            btl_cam_use_preset(BTL_CAM_DEFAULT);
            btl_cam_move(10);
            if (!(gBattleStatus.flags1 & BS_FLAGS1_PLAYER_IN_BACK)) {
                player->state.curPos.x = player->homePos.x;
                player->state.curPos.z = player->homePos.z;
                player->state.goalPos.x = partner->homePos.x;
                player->state.goalPos.z = partner->homePos.z;
                gBattleSubState = BTL_SUBSTATE_TWINK_MENU_PERFORM_SWAP;
                player->state.moveTime = 4;
                player->state.angle = 0.0f;
                break;
            }
            gBattleSubState = BTL_SUBSTATE_TWINK_MENU_CREATE_MAIN_MENU;
            break;
        case BTL_SUBSTATE_TWINK_MENU_PERFORM_SWAP:
            if (player->state.moveTime != 0) {
                player->curPos.x += (player->state.goalPos.x - player->curPos.x) / player->state.moveTime;
                player->curPos.z += (player->state.goalPos.z - player->curPos.z) / player->state.moveTime;
                partner->curPos.x += (player->state.curPos.x - partner->curPos.x) / player->state.moveTime;
                partner->curPos.z += (player->state.curPos.z - partner->curPos.z) / player->state.moveTime;
            }
            player->curPos.z += sin_rad(DEG_TO_RAD(player->state.angle)) * 16.0f;
            player->yaw = clamp_angle(-player->state.angle);
            partner->curPos.z -= sin_rad(DEG_TO_RAD(player->state.angle)) * 16.0f;
            partner->yaw = clamp_angle(-player->state.angle);
            player->state.angle += 90.0f;
            if (player->state.moveTime != 0) {
                player->state.moveTime--;
                break;
            }
            player->curPos.x = player->state.goalPos.x;
            player->curPos.z = player->state.goalPos.z;
            partner->curPos.x = player->state.curPos.x;
            partner->curPos.z = player->state.curPos.z;
            player->homePos.x = player->curPos.x;
            player->homePos.z = player->curPos.z;
            partner->homePos.x = partner->curPos.x;
            partner->homePos.z = partner->curPos.z;
            gBattleStatus.flags1 |= BS_FLAGS1_PLAYER_IN_BACK;
        case BTL_SUBSTATE_TWINK_MENU_CREATE_MAIN_MENU:
            gBattleStatus.flags1 |= BS_FLAGS1_MENU_OPEN;
            player->flags &= ~ACTOR_FLAG_USING_IDLE_ANIM;
            player->flags |= ACTOR_FLAG_SHOW_STATUS_ICONS;
            if (partner != nullptr) {
                partner->flags |= ACTOR_FLAG_USING_IDLE_ANIM;
                partner->flags |= ACTOR_FLAG_SHOW_STATUS_ICONS;
            }

            entryIdx = 0;
            battleStatus->selectedMoveID = MOVE_NONE;
            WheelOptionSubmenu[entryIdx] = BTL_MENU_TYPE_STAR_POWERS;
            WheelOptionEnabled[entryIdx] = true;
            WheelOptionError[entryIdx] = 0;
            WheelOptionHudScript[entryIdx] = TwinkStarPowerHudScripts.enabled;
            WheelOptionName[entryIdx] = TwinkMenuMessages[entryIdx];
            if (!(battleStatus->enabledMenusFlags & BTL_MENU_ENABLED_STAR_POWERS)) {
                WheelOptionEnabled[entryIdx] = false;
                WheelOptionError[entryIdx] = BTL_MSG_CANT_SELECT_NOW;
                WheelOptionHudScript[entryIdx] = TwinkStarPowerHudScripts.disabled;
            }

            initialPos = 0;
            entryIdx++;

            if (btl_menu_show_switch_to_peach()) {
                BattleMenu_ShowSwapIcons = true;
            } else {
                BattleMenu_ShowSwapIcons = false;
            }
            WheelOptionCount = entryIdx;
            D_802AD0A8 = 0;
            BattleMenu_PrevSelected = initialPos;
            BattleMenu_WheelBase = 2 - initialPos;

            btl_main_menu_init();
            BattleMenu_ChooseDelay = 8;
            gBattleSubState = BTL_SUBSTATE_TWINK_MENU_CHOOSE_CATEGORY;
            break;
        case BTL_SUBSTATE_TWINK_MENU_CHOOSE_CATEGORY:
            set_actor_anim(ACTOR_PARTNER, 0, ANIM_Twink_Idle);
            selection = btl_main_menu_update();
            if (BattleMenu_ChooseDelay != 0) {
                BattleMenu_ChooseDelay--;
                break;
            }
            if (selection != 0) {
                set_actor_anim(ACTOR_PARTNER, 0, ANIM_Twink_Angry);
                battleStatus->curSubmenu = WheelOptionSubmenu[selection - 1];
                btl_main_menu_hide();
                BattleMenu_ChooseDelay = 8;
                BattleMenu_SwapDelay = 4;
                gBattleSubState = BTL_SUBSTATE_TWINK_MENU_CHOOSE_TARGET;
            }
            break;
        case BTL_SUBSTATE_TWINK_MENU_CHOOSE_TARGET:
            if (btl_main_menu_update() != 0) {
                battleStatus->cancelTargetMenuSubstate = BTL_SUBSTATE_TWINK_MENU_TARGET_CANCEL;
                battleStatus->acceptTargetMenuSubstate = BTL_SUBSTATE_TWINK_MENU_TARGET_CHOSEN;
                battleStatus->moveCategory = BTL_MENU_TYPE_STAR_POWERS;
                battleStatus->selectedMoveID = MOVE_TWINK_DASH;
                battleStatus->moveArgument = 0;
                battleStatus->curTargetListFlags = gMoveTable[MOVE_TWINK_DASH].flags;
                btl_set_state(BATTLE_STATE_SELECT_TARGET);
            }
            break;
        case BTL_SUBSTATE_TWINK_MENU_TARGET_CANCEL:
            btl_main_menu_resume_choose();
            gBattleSubState = BTL_SUBSTATE_TWINK_MENU_CHOOSE_CATEGORY;
            btl_state_update_twink_menu();
            btl_state_update_twink_menu();
            break;
        case BTL_SUBSTATE_TWINK_MENU_TARGET_CHOSEN:
            btl_main_menu_destroy();
            break;
        case BTL_SUBSTATE_TWINK_MENU_SHOW_CANT_SWITCH:
            btl_show_variable_battle_message(BTL_MSG_CANT_SWITCH, 60, 0);
            ShowingErrorMessage = true;
            gBattleSubState = BTL_SUBSTATE_TWINK_MENU_AWAIT_CANT_SWITCH_POPUP;
            break;
        case BTL_SUBSTATE_TWINK_MENU_AWAIT_CANT_SWITCH_POPUP:
            if (btl_is_popup_displayed()) {
                break;
            }
            ShowingErrorMessage = false;
            BattleMenu_ChooseDelay = 0;
            gBattleSubState = BTL_SUBSTATE_TWINK_MENU_CHOOSE_CATEGORY;
            break;
    }
}

void btl_state_draw_twink_menu(void) {
    switch (gBattleSubState) {
        case BTL_SUBSTATE_TWINK_MENU_CHOOSE_CATEGORY:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_TWINK_MENU_CHOOSE_TARGET:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_TWINK_MENU_UNUSED_3:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_TWINK_MENU_TARGET_CANCEL:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_TWINK_MENU_TARGET_CHOSEN:
            btl_main_menu_draw();
            break;
        case BTL_SUBSTATE_TWINK_MENU_UNUSED_6:
        case BTL_SUBSTATE_TWINK_MENU_UNUSED_7:
        case BTL_SUBSTATE_TWINK_MENU_SHOW_CANT_SWITCH:
        case BTL_SUBSTATE_TWINK_MENU_AWAIT_CANT_SWITCH_POPUP:
            break;
    }
}

void btl_state_update_select_target(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* actor;
    s32 targetListLength;
    s32 selectedTargetIndex;
    HudElemID hid;
    s8* targetIndexList;
    SelectableTarget* target;
    s32 i;

    if (!(gBattleStatus.flags1 & BS_FLAGS1_PARTNER_ACTING)) {
        actor = battleStatus->playerActor;
    } else {
        actor = battleStatus->partnerActor;
    }
    targetListLength = actor->targetListLength;
    selectedTargetIndex = actor->selectedTargetIndex;

    actor->flags &= ~ACTOR_FLAG_SHOW_STATUS_ICONS;
    targetIndexList = actor->targetIndexList;
    switch (gBattleSubState) {
        case BTL_SUBSTATE_SELECT_TARGET_INIT:
            BattleMenu_TargetPointerAlpha = 255;
            BattleMenu_TargetNameOffsetX = -100;
            gBattleStatus.flags1 &= ~BS_FLAGS1_MENU_OPEN;

            // prepare the action command tip for the selected move
            if (!is_ability_active(ABILITY_BERSERKER) || (gBattleStatus.flags1 & BS_FLAGS1_PARTNER_ACTING)) {
                if (battleStatus->selectedMoveID != MOVE_NONE) {
                    s8 actionTip = gMoveTable[battleStatus->selectedMoveID].actionTip;

                    if (actionTip >= 0) {
                        btl_show_battle_message(BTL_MSG_ACTION_TIP_PRESS_BEFORE_LANDING + actionTip, 60);
                    }
                }
            }

            // create the target list
            create_current_pos_target_list(actor);
            targetListLength = actor->targetListLength;
            if (battleStatus->curTargetListFlags & TARGET_FLAG_SELECT_ONE) {
                targetIndexList = actor->targetIndexList;
                for (i = 0; i < targetListLength; i++) {
                    target = &actor->targetData[targetIndexList[i]];
                    if (get_actor_part(get_actor(target->actorID), target->partID)->flags & ACTOR_PART_FLAG_DEFAULT_TARGET) {
                        actor->selectedTargetIndex = i;
                        break;
                    }
                }
            }

            // when TARGET_FLAG_OVERRIDE is set, skip selecting a target and begin executing the move
            if (battleStatus->curTargetListFlags & TARGET_FLAG_OVERRIDE) {
                if (!(gBattleStatus.flags1 & BS_FLAGS1_PARTNER_ACTING)) {
                    gBattleSubState = battleStatus->acceptTargetMenuSubstate;
                    if (gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE) {
                        btl_state_update_player_menu();
                    } else {
                        btl_state_update_player_menu();
                    }
                    btl_set_state(BATTLE_STATE_PLAYER_MOVE);
                } else {
                    gBattleSubState = battleStatus->acceptTargetMenuSubstate;
                    if (gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE) {
                        btl_state_update_twink_menu();
                    } else {
                        btl_state_update_partner_menu();
                    }
                    btl_set_state(BATTLE_STATE_PARTNER_MOVE);
                }
                break;
            }

            // if the target list is empty, skip selecting a target and begin executing the move
            if (targetListLength == 0) {
                if (!(gBattleStatus.flags1 & BS_FLAGS1_PARTNER_ACTING)) {
                    gBattleSubState = battleStatus->acceptTargetMenuSubstate;
                    if (gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE) {
                        btl_state_update_player_menu();
                    } else {
                        btl_state_update_player_menu();
                    }
                    btl_set_state(BATTLE_STATE_PLAYER_MOVE);
                } else {
                    gBattleSubState = battleStatus->acceptTargetMenuSubstate;
                    if (gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE) {
                        btl_state_update_twink_menu();
                    } else {
                        btl_state_update_partner_menu();
                    }
                    btl_set_state(BATTLE_STATE_PARTNER_MOVE);
                }
                break;
            }

            // create the HUD elements for the target pointers
            for (i = 0; i < targetListLength; i++) {
                hid = hud_element_create(&HES_HandPointDownLoop);
                BattleMenu_TargetHudElems[i] = hid;
                hud_element_set_render_depth(hid, 0);
                hud_element_set_render_pos(hid, 0, -100);
            }
            gBattleSubState = BTL_SUBSTATE_SELECT_TARGET_CHOOSE;
            break;
        case BTL_SUBSTATE_SELECT_TARGET_CHOOSE:
            // animate the target name sliding into view
            if (BattleMenu_TargetNameOffsetX < 0) {
                BattleMenu_TargetNameOffsetX += 20;
                if (BattleMenu_TargetNameOffsetX > 0) {
                    BattleMenu_TargetNameOffsetX = 0;
                }
            }

            if (battleStatus->curButtonsPressed & BUTTON_B) {
                sfx_play_sound(SOUND_MENU_BACK);
                gBattleSubState = BTL_SUBSTATE_SELECT_TARGET_CANCEL;
                break;
            }

            if (battleStatus->curButtonsPressed & BUTTON_A) {
                sfx_play_sound(SOUND_MENU_NEXT);
                BattleMenu_ChooseDelay = 8;
                BattleMenu_SwapDelay = 4;
                gBattleSubState = BTL_SUBSTATE_SELECT_TARGET_DONE;
                break;
            }

            gBattleStatus.flags1 |= BS_FLAGS1_MENU_OPEN;
            if (battleStatus->curButtonsDown & (BUTTON_Z | BUTTON_R)) {
                gBattleStatus.flags1 &= ~BS_FLAGS1_MENU_OPEN;
                break;
            }

            if (battleStatus->curTargetListFlags & TARGET_FLAG_SELECT_ONE) {
                s32 oldSelectedTargetIndex = selectedTargetIndex;

                if (battleStatus->curButtonsHeld & BUTTON_STICK_LEFT) {
                    selectedTargetIndex--;
                }
                if (battleStatus->curButtonsHeld & BUTTON_STICK_RIGHT) {
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
                    hid = BattleMenu_TargetHudElems[0];

                    if (actorFlags & ACTOR_FLAG_UPSIDE_DOWN) {
                        hud_element_set_script(hid, &HES_HandPointLeftLoop);
                    } else {
                        hud_element_set_script(hid, &HES_HandPointDownLoop);
                    }
                    sfx_play_sound(SOUND_MENU_CHANGE_SELECTION);
                }
                actor->selectedTargetIndex = selectedTargetIndex;
            }
            break;
        case BTL_SUBSTATE_SELECT_TARGET_DONE:
            gBattleStatus.flags1 &= ~BS_FLAGS1_MENU_OPEN;
            target = &actor->targetData[targetIndexList[actor->selectedTargetIndex]];
            actor->targetActorID = target->actorID;
            actor->targetPartID = target->partID;

            // free the HUD elements for the target pointers
            for (i = 0; i < targetListLength; i++) {
                hud_element_free(BattleMenu_TargetHudElems[i]);
            }

            // begin executing the move
            if (!(gBattleStatus.flags1 & BS_FLAGS1_PARTNER_ACTING)) {
                gBattleSubState = battleStatus->acceptTargetMenuSubstate;
                if (gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE) {
                    btl_state_update_peach_menu();
                } else {
                    btl_state_update_player_menu();
                }
                btl_set_state(BATTLE_STATE_PLAYER_MOVE);
            } else {
                gBattleSubState = battleStatus->acceptTargetMenuSubstate;
                if (gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE) {
                    btl_state_update_twink_menu();
                } else {
                    btl_state_update_partner_menu();
                }
                btl_set_state(BATTLE_STATE_PARTNER_MOVE);
            }
            break;
        case BTL_SUBSTATE_SELECT_TARGET_CANCEL:
            // free the HUD elements for the target pointers
            for (i = 0; i < targetListLength; i++) {
                hud_element_free(BattleMenu_TargetHudElems[i]);
            }

            gBattleStatus.flags1 |= BS_FLAGS1_10000 | BS_FLAGS1_MENU_OPEN;
            actor->flags |= ACTOR_FLAG_SHOW_STATUS_ICONS;

            if (battleStatus->itemUsesLeft != 0) {
                btl_set_state(BATTLE_STATE_PLAYER_MENU);
                gBattleSubState = battleStatus->cancelTargetMenuSubstate;
                if (gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE) {
                    btl_state_update_peach_menu();
                } else {
                    btl_state_update_player_menu();
                }
            } else if (!(gBattleStatus.flags1 & BS_FLAGS1_PARTNER_ACTING)) {
                btl_set_state(BATTLE_STATE_PLAYER_MENU);
                gBattleSubState = battleStatus->cancelTargetMenuSubstate;
                if (gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE) {
                    btl_state_update_peach_menu();
                } else {
                    btl_state_update_player_menu();
                }
            } else {
                btl_set_state(BATTLE_STATE_PARTNER_MENU);
                gBattleSubState = battleStatus->cancelTargetMenuSubstate;
                if (gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE) {
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
    Actor* choosingActor;
    Actor* enemyActor;
    s32 id;
    s32 i;
    s32 nameWidth;
    s32 xOffset, yOffset;
    f32 targetX, targetY, targetZ;
    s32 screenX, screenY, screenZ;
    s32 selectedTargetIndex;
    s8* targetIndexList;
    s32* tmpPtr; // TODO required to match and CURSED

    if (!(gBattleStatus.flags1 & BS_FLAGS1_PARTNER_ACTING)) {
        choosingActor = battleStatus->playerActor;
    } else {
        choosingActor = battleStatus->partnerActor;
    }

    targetListLength = choosingActor->targetListLength;
    target = choosingActor->targetData;
    selectedTargetIndex = choosingActor->selectedTargetIndex;
    targetIndexList = choosingActor->targetIndexList;

    tmpPtr = &BattleMenu_TargetNameOffsetX;

    if (targetListLength == 0) {
        return;
    }

    // draw target pointers
    if (battleStatus->curTargetListFlags & TARGET_FLAG_SELECT_ONE) {
        target = &choosingActor->targetData[targetIndexList[selectedTargetIndex]];
        enemyActor = get_actor(target->actorID);
        id = BattleMenu_TargetHudElems[0];
        targetX = target->truePos.x;
        targetY = target->truePos.y;
        targetZ = target->truePos.z;

        // select target pointer style based on target actor orientation
        if (enemyActor->flags & ACTOR_FLAG_UPSIDE_DOWN) {
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

        get_screen_coords(CAM_BATTLE, targetX, targetY, targetZ, &screenX, &screenY, &screenZ);
        hud_element_set_render_pos(id, screenX + xOffset, screenY + yOffset);
        hud_element_set_alpha(id, BattleMenu_TargetPointerAlpha);
    } else {
        for (i = 0; i < targetListLength; i++) {
            target = &choosingActor->targetData[targetIndexList[i]];
            enemyActor = get_actor(target->actorID);
            id = BattleMenu_TargetHudElems[i];
            targetX = target->truePos.x;
            targetY = target->truePos.y;
            targetZ = target->truePos.z;

            // select target pointer style based on target actor orientation
            if (enemyActor->flags & ACTOR_FLAG_UPSIDE_DOWN) {
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

            get_screen_coords(CAM_BATTLE, targetX, targetY, targetZ, &screenX, &screenY, &screenZ);
            hud_element_set_render_pos(id, screenX + xOffset, screenY + yOffset);
            hud_element_set_alpha(id, BattleMenu_TargetPointerAlpha);
        }
    }

    currentPartner = playerData->curPartner;
    screenX = 52;
    screenY = 64;
    if (gBattleStatus.flags2 & BS_FLAGS2_PEACH_BATTLE) {
        currentPartner = PARTNER_TWINK;
    }

    // get target name width
    if ((battleStatus->curTargetListFlags & TARGET_FLAG_SELECT_ONE) || targetListLength == 1) {
        actorID = target->actorID;
        if (actorID == ACTOR_PLAYER) {
            nameWidth = get_msg_width(MSG_Menus_Battle_TargetMario, 0) + 10;
        } else if (actorID == ACTOR_PARTNER) {
            nameWidth = get_msg_width(PartnerNameMessages[currentPartner], 0) + 10;
        } else {
            target = &choosingActor->targetData[targetIndexList[selectedTargetIndex]];
            enemyActor = get_actor(target->actorID);
            msgID = get_actor_part(enemyActor, target->partID)->staticData->overrideNameMsg;
            if (msgID == MSG_NONE) {
                msgID = bActorNames[enemyActor->actorType];
            }
            nameWidth = get_msg_width(msgID, 0) + 10;
        }
    } else {
        target = &choosingActor->targetData[targetIndexList[selectedTargetIndex]];
        actorID = target->actorID;
        if (actorID == ACTOR_PLAYER) {
            nameWidth = get_msg_width(MSG_Menus_Battle_TargetMario, 0) + 10;
        } else if (actorID == ACTOR_PARTNER) {
            nameWidth = get_msg_width(PartnerNameMessages[currentPartner], 0) + 10;
        } else {
            nameWidth = get_msg_width(MSG_Menus_Battle_TargetAllEnemies, 0) + 10;
        }
    }

    // draw target name box
    draw_box(0, WINDOW_STYLE_4, screenX + BattleMenu_TargetNameOffsetX, screenY, 0, nameWidth, 20, 255, 0,
                0.0f, 0.0f, 0.0f, 0.0f, 0.0f, nullptr, nullptr, nullptr, SCREEN_WIDTH, SCREEN_HEIGHT, nullptr);

    // draw target name text
    screenX += 4;
    screenY += 2;
    if ((battleStatus->curTargetListFlags & TARGET_FLAG_SELECT_ONE) || targetListLength == 1) {
        actorID = target->actorID;
        if (actorID == ACTOR_PLAYER) {
            draw_msg(MSG_Menus_Battle_TargetMario, screenX + BattleMenu_TargetNameOffsetX, screenY, 255, MSG_PAL_36, 0);
        } else if (actorID == ACTOR_PARTNER) {
            draw_msg(PartnerNameMessages[currentPartner], screenX + BattleMenu_TargetNameOffsetX, screenY, 255, MSG_PAL_36, 0);
        } else {
            target = &choosingActor->targetData[targetIndexList[selectedTargetIndex]];
            enemyActor = get_actor(target->actorID);
            msgID = get_actor_part(enemyActor, target->partID)->staticData->overrideNameMsg;
            if (msgID == MSG_NONE) {
                msgID = bActorNames[enemyActor->actorType];
            }
            draw_msg(msgID, screenX + *tmpPtr, screenY, 255, MSG_PAL_36, 0); // TODO required to match
        }
    } else {
        target = &choosingActor->targetData[targetIndexList[selectedTargetIndex]];
        actorID = target->actorID;
        if (actorID == ACTOR_PLAYER) {
            draw_msg(MSG_Menus_Battle_TargetMario, screenX + BattleMenu_TargetNameOffsetX, screenY, 255, MSG_PAL_36, 0);
        } else if (actorID == ACTOR_PARTNER) {
            draw_msg(PartnerNameMessages[currentPartner], screenX + BattleMenu_TargetNameOffsetX, screenY, 255, MSG_PAL_36, 0);
        } else {
            draw_msg(MSG_Menus_Battle_TargetAllEnemies, screenX + BattleMenu_TargetNameOffsetX, screenY, 255, MSG_PAL_36, 0);
        }
    }
}

void btl_state_update_22(void) {
}

void btl_state_draw_22(void) {
}
