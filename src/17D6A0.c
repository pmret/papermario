#include "common.h"
#include "effects.h"
#include "message_ids.h"
#include "battle/battle.h"
#include "hud_element.h"
#include "entity.h"
#include "ld_addrs.h"
#include "battle/action_cmd.h"
#include "sprite/player.h"

extern IMG_BIN ui_battle_menu_spirits_png[];
extern PAL_BIN ui_battle_menu_spirits_pal[];
extern IMG_BIN ui_battle_solid_star_png[];
extern PAL_BIN ui_battle_solid_star_pal[];

extern ActorBlueprint battle_partner_goombario;
extern ActorBlueprint battle_partner_kooper;
extern ActorBlueprint battle_partner_bombette;
extern ActorBlueprint battle_partner_parakarry;
extern ActorBlueprint battle_partner_goompa;
extern ActorBlueprint battle_partner_watt;
extern ActorBlueprint battle_partner_sushie;
extern ActorBlueprint battle_partner_lakilester;
extern ActorBlueprint battle_partner_bow;
extern ActorBlueprint battle_partner_twink;

PlayerCelebrationAnimOptions D_80280FC0 = {
    10, 90,
    {
        50, ANIM_MarioB1_JumpForJoy,
        50, ANIM_Mario1_Chuckle,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        50, ANIM_Mario1_DustOff,
        50, ANIM_Mario1_DustOff,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        50, ANIM_Mario1_ThumbsUp,
        50, ANIM_Mario1_ThumbsUp,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        50, ANIM_MarioB1_FingerWag,
        50, ANIM_MarioB1_FingerWag,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        80, ANIM_MarioB1_FingerWag,
        20, ANIM_MarioB1_JumpForJoy,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
        0, 0,
    }
};

#include "battle/actor_types.inc.c"

u32 bMarioIdleAnims[] = {
    STATUS_KEY_NORMAL,            ANIM_Mario1_Walk,
    STATUS_KEY_DANGER,            ANIM_Mario1_TiredIdle,
    STATUS_KEY_STONE,             ANIM_MarioB3_Petrified,
    STATUS_KEY_SLEEP,             ANIM_MarioB1_Sleep,
    STATUS_KEY_DIZZY,             ANIM_MarioB1_Sick,
    STATUS_KEY_STOP,              ANIM_Mario1_Still,
    STATUS_KEY_HUSTLE,            ANIM_Mario1_Run,
    STATUS_KEY_BERSERK,           ANIM_MarioB2_BerserkIdle,
    STATUS_KEY_PARALYZE,          ANIM_MarioB1_Sleep,
    STATUS_KEY_FROZEN,            ANIM_Mario1_Frozen,
    STATUS_KEY_TRANSPARENT,       ANIM_Mario1_Idle,
    STATUS_KEY_INACTIVE,          ANIM_Mario1_Still,
    STATUS_KEY_INACTIVE_BERSERK,  ANIM_MarioB2_BerserkStill,
    STATUS_KEY_14,                ANIM_MarioB2_Inert,
    STATUS_KEY_INACTIVE_SLEEP,    ANIM_MarioB1_SleepStill,
    STATUS_KEY_INACTIVE_DIZZY,    ANIM_MarioB1_SickStill,
    STATUS_KEY_INACTIVE_WEARY,    ANIM_Mario1_TiredStill,
    STATUS_KEY_THINKING,          ANIM_Mario1_Thinking,
    STATUS_KEY_WEARY,             ANIM_Mario1_SpinLand,
    STATUS_END
};

s32 bMarioDefendAnims[] = {
    STATUS_KEY_NORMAL,            ANIM_Mario1_Crouch,
    STATUS_KEY_DANGER,            ANIM_Mario1_TiredIdle,
    STATUS_KEY_STONE,             ANIM_MarioB3_Petrified,
    STATUS_KEY_SLEEP,             ANIM_MarioB1_Sleep,
    STATUS_KEY_DIZZY,             ANIM_MarioB1_Sick,
    STATUS_KEY_STOP,              ANIM_Mario1_Still,
    STATUS_KEY_HUSTLE,            ANIM_Mario1_Crouch,
    STATUS_KEY_BERSERK,           ANIM_Mario1_Crouch,
    STATUS_KEY_PARALYZE,          ANIM_MarioB1_Sleep,
    STATUS_KEY_FROZEN,            ANIM_Mario1_Frozen,
    STATUS_KEY_TRANSPARENT,       ANIM_Mario1_Idle,
    STATUS_KEY_INACTIVE,          ANIM_Mario1_Still,
    STATUS_KEY_INACTIVE_BERSERK,  ANIM_MarioB2_BerserkStill,
    STATUS_KEY_14,                ANIM_MarioB2_Inert,
    STATUS_KEY_INACTIVE_SLEEP,    ANIM_MarioB1_SleepStill,
    STATUS_KEY_INACTIVE_DIZZY,    ANIM_MarioB1_SickStill,
    STATUS_KEY_INACTIVE_WEARY,    ANIM_Mario1_TiredStill,
    STATUS_KEY_THINKING,          ANIM_Mario1_Thinking,
    STATUS_KEY_WEARY,             ANIM_Mario1_SpinLand,
    STATUS_END
};

s32 bMarioHideAnims[] = {
    STATUS_KEY_NORMAL,            ANIM_Mario1_Crouch,
    STATUS_KEY_DANGER,            ANIM_Mario1_TiredIdle,
    STATUS_KEY_STONE,             ANIM_MarioB3_Petrified,
    STATUS_KEY_SLEEP,             ANIM_MarioB1_Sleep,
    STATUS_KEY_DIZZY,             ANIM_MarioB1_Sick,
    STATUS_KEY_STOP,              ANIM_Mario1_Still,
    STATUS_KEY_HUSTLE,            ANIM_MarioW2_RideLaki,
    STATUS_KEY_BERSERK,           ANIM_MarioW2_RideLaki,
    STATUS_KEY_PARALYZE,          ANIM_MarioB1_Sleep,
    STATUS_KEY_FROZEN,            ANIM_Mario1_Frozen,
    STATUS_KEY_TRANSPARENT,       ANIM_Mario1_Idle,
    STATUS_KEY_INACTIVE,          ANIM_Mario1_Crouch,
    STATUS_KEY_INACTIVE_BERSERK,  ANIM_MarioB2_BerserkStill,
    STATUS_KEY_14,                ANIM_MarioB2_Inert,
    STATUS_KEY_INACTIVE_SLEEP,    ANIM_MarioB1_SleepStill,
    STATUS_KEY_INACTIVE_DIZZY,    ANIM_MarioB1_SickStill,
    STATUS_KEY_INACTIVE_WEARY,    ANIM_Mario1_TiredStill,
    STATUS_KEY_THINKING,          ANIM_Mario1_Thinking,
    STATUS_KEY_WEARY,             ANIM_Mario1_SpinLand,
    STATUS_END
};

s32 bPeachIdleAnims[] = {
    STATUS_KEY_NORMAL,    ANIM_Peach1_Walk,
    STATUS_KEY_INACTIVE,  ANIM_Peach2_Inert,
    STATUS_END
};

s32 bMarioDefenseTable[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END
};

s32 bPlayerStatusTable[] = {
    STATUS_KEY_NORMAL,          100,
    STATUS_KEY_DEFAULT,         100,
    STATUS_KEY_SLEEP,           100,
    STATUS_KEY_POISON,          100,
    STATUS_KEY_FROZEN,          100,
    STATUS_KEY_DIZZY,           100,
    STATUS_KEY_FEAR,            100,
    STATUS_KEY_STATIC,          100,
    STATUS_KEY_PARALYZE,        100,
    STATUS_KEY_SHRINK,          100,
    STATUS_KEY_STOP,            100,
    STATUS_TURN_MOD_DEFAULT,  0,
    STATUS_TURN_MOD_SLEEP,    0,
    STATUS_TURN_MOD_POISON,   0,
    STATUS_TURN_MOD_FROZEN,   0,
    STATUS_TURN_MOD_DIZZY,    0,
    STATUS_TURN_MOD_FEAR,     0,
    STATUS_TURN_MOD_STATIC,   0,
    STATUS_TURN_MOD_PARALYZE, 0,
    STATUS_TURN_MOD_SHRINK,   0,
    STATUS_TURN_MOD_STOP,     0,
    STATUS_END
};

ActorBlueprint bPlayerActorBlueprint = {
    .type = ACTOR_TYPE_PLAYER,
    .maxHP = 99,
    .statusTable = bPlayerStatusTable,

    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 80,

    .size = { 33, 43 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 30 },
    .statusTextOffset = { 10, 30 },
};

ActorPartBlueprint bMarioParts[] = {
    {
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 32 },
        .opacity = 255,
        .idleAnimations = bMarioIdleAnims,
        .defenseTable = bMarioDefenseTable,
    },
};

Vec3s btl_actorHomePositions[] = {
    [BTL_POS_GROUND_A] { 5, 0, -20 },
    [BTL_POS_GROUND_B] { 45, 0, -5 },
    [BTL_POS_GROUND_C] { 85, 0, 10 },
    [BTL_POS_GROUND_D] { 125, 0, 25 },
    [BTL_POS_AIR_A] { 10, 50, -20 },
    [BTL_POS_AIR_B] { 50, 45, -5 },
    [BTL_POS_AIR_C] { 90, 50, 10 },
    [BTL_POS_AIR_D] { 130, 55, 25 },
    [BTL_POS_HIGH_A] { 15, 85, -20 },
    [BTL_POS_HIGH_B] { 55, 80, -5 },
    [BTL_POS_HIGH_C] { 95, 85, 10 },
    [BTL_POS_HIGH_D] { 135, 90, 25 },
    [BTL_POS_TOP_A] { 15, 125, -20 },
    [BTL_POS_TOP_B] { 55, 120, -5 },
    [BTL_POS_TOP_C] { 95, 125, 10 },
    [BTL_POS_TOP_D] { 135, 130, 25 },
    [BTL_POS_CENTER] { 105, 0, 0 },
};

// TODO: what is this, and look into warnings that are silenced via casts
s32* D_8028358C[] = {
    (s32*)-1, (s32*)-1, (s32*)-1, (s32*)-1, (s32*)-1, (s32*)-1, (s32*)-1, (s32*)-1,
    (s32*)D_8028358C, (s32*)D_8028358C, (s32*)D_8028358C, (s32*)D_8028358C, (s32*)D_8028358C, (s32*)D_8028358C,
    (s32*)D_8028358C, (s32*)D_8028358C, 0
};

s16 bMsgHeights[] = { 28, 40 }; // keyed by number of lines in the message (1 or 2)
s16 D_802835D4[] = { 0, -2 };
s16 D_802835D8[] = { 0, -12 };

//TODO Vec3f[]
f32 D_802835DC[] = {
    0.0f, 4.5f, 0.0f,
    1.0f, 4.0f, 0.0f,
    2.0f, 3.0f, 0.0f,
    3.0f, 2.0f, 0.0f,
    3.5f, 1.0f, 0.0f,
    4.0f, 0.0f, 0.0f,
    4.5f, 0.0f, 0.0f,
    5.0f, 0.0f, 0.0f,
    4.5f, 0.0f, 0.0f,
    4.0f, 0.0f, 0.0f,
    3.5f, -1.0f, 0.0f,
    3.0f, -2.0f, 0.0f,
    2.0f, -3.0f, 0.0f,
    1.0f, -4.0f, 0.0f,
    0.0f, -4.5f, 0.0f,
};

Vec3f D_80283690[] = {
    { 1.0f, 1.0f, 1.0f },
    { 0.8f, 0.8f, 0.8f },
    { 0.9f, 0.9f, 0.9f },
    { 1.1f, 1.1f, 1.1f },
    { 1.0f, 1.0f, 1.0f },
    { 0.8f, 0.8f, 0.8f },
    { 0.9f, 0.9f, 0.9f },
    { 1.1f, 1.1f, 1.1f },
    { 1.0f, 1.0f, 1.0f },
    { 0.8f, 0.8f, 0.8f },
    { 0.9f, 0.9f, 0.9f },
    { 1.1f, 1.1f, 1.1f },
    { 1.0f, 1.0f, 1.0f },
    { 0.8f, 0.8f, 0.8f },
    { 0.9f, 0.9f, 0.9f },
};

extern EntityModelScript EMS_BonkIcon;
EntityModelScript* bBonkModelScripts[] = {
    NULL,
    &EMS_BonkIcon, &EMS_BonkIcon, &EMS_BonkIcon, &EMS_BonkIcon, &EMS_BonkIcon,
    &EMS_BonkIcon, &EMS_BonkIcon, &EMS_BonkIcon, &EMS_BonkIcon, &EMS_BonkIcon,
};

s32 bMessages[] = {
    [BTL_MSG_MERLEE_ATK_UP]         MSG_Menus_Merlee_IncreaseAttack,
    [BTL_MSG_MERLEE_DEF_UP]         MSG_Menus_Merlee_DecreaseDamage,
    [BTL_MSG_MERLEE_EXP_UP]         MSG_Menus_Merlee_IncreaseStarPoints,
    [BTL_MSG_MERLEE_DONE]           MSG_Menus_Merlee_Exhausted,
    [BTL_MSG_CHARGE_HAMMER]         MSG_Menus_ChargeHammer,
    [BTL_MSG_CHARGE_HAMMER_MORE]    MSG_Menus_ChargeHammerMore,
    [BTL_MSG_CHARGE_JUMP]           MSG_Menus_ChargeJump,
    [BTL_MSG_CHARGE_JUMP_MORE]      MSG_Menus_ChargeJumpMore,
    [BTL_MSG_CANT_CHARGE]           MSG_Menus_ChargeMaxedOut,
    [BTL_MSG_ENEMY_MISSED]          MSG_Menus_EnemyMissed,

    // player status effects
    [BTL_MSG_PLAYER_DAZED]          MSG_Menus_PlayerDazed,
    [BTL_MSG_PLAYER_ASLEEP]         MSG_Menus_PlayerAsleep,
    [BTL_MSG_PLAYER_FROZEN]         MSG_Menus_PlayerFrozen,
    [BTL_MSG_PLAYER_POISONED]       MSG_Menus_PlayerPoisoned,
    [BTL_MSG_PLAYER_SHRUNK]         MSG_Menus_PlayerShrunk,
    [BTL_MSG_PLAYER_PARALYZED]      MSG_Menus_PlayerParalyzed,
    [BTL_MSG_PLAYER_CHARGED]        MSG_Menus_PlayerElectricCharge,
    [BTL_MSG_PLAYER_TRANSPARENT]    MSG_Menus_PlayerTransparent,

    // enemy status effects
    [BTL_MSG_ENEMY_DAZED]           MSG_Menus_EnemyDazed,
    [BTL_MSG_ENEMY_ASLEEP]          MSG_Menus_EnemyAsleep,
    [BTL_MSG_ENEMY_FROZEN]          MSG_Menus_EnemyFrozen,
    [BTL_MSG_ENEMY_POISONED]        MSG_Menus_EnemyPoisoned,
    [BTL_MSG_ENEMY_SHRUNK]          MSG_Menus_EnemyShrunk,
    [BTL_MSG_ENEMY_PARALYZED]       MSG_Menus_EnemyParalyzed,
    [BTL_MSG_ENEMY_ELECTRIFIED]     MSG_Menus_EnemyElectrified,
    [BTL_MSG_ENEMY_CANT_MOVE]       MSG_Menus_EnemyCantMove,

    [BTL_MSG_STAR_POWER_RECHARGED]  MSG_Menus_StarEnergyRecharged,
    [BTL_MSG_STAR_POWER_MAXED]      MSG_Menus_StarEnergyMaxedOut,
    [BTL_MSG_STAR_POWER_FILLED]     MSG_Menus_StarEnergyFilled,
    [BTL_MSG_ATTACK_UP]             MSG_Menus_AttackUp,
    [BTL_MSG_DEFENCE_UP]            MSG_Menus_DefenseUp,
    [BTL_MSG_HEAL_ONE]              MSG_Menus_HealOne,
    [BTL_MSG_HEAL_ALL]              MSG_Menus_HealAll,

    [BTL_MSG_ENEMY_TRANSPARENT]     MSG_Menus_EnemyTransparent,
    [BTL_MSG_ENEMY_CHARGED]         MSG_Menus_EnemyElectricCharge,
    [BTL_MSG_PARTNER_INJURED]       MSG_Menus_PartnerInjured,
    [BTL_MSG_CHARGE_GOOMBARIO]      MSG_Menus_ChargeGoombario,
    [BTL_MSG_CHARGE_GOOMBARIO_MORE] MSG_Menus_ChargeGoombarioMore,
    [BTL_MSG_WATER_BLOCK_BEGIN]     MSG_Menus_WaterBlockBegin,
    [BTL_MSG_WATER_BLOCK_END]       MSG_Menus_WaterBlockEnd,
    [BTL_MSG_CLOUD_NINE_BEGIN]      MSG_Menus_CloudNineBegin,
    [BTL_MSG_CLOUD_NINE_END]        MSG_Menus_CloudNineEnd,
    [BTL_MSG_TURBO_CHARGE_BEGIN]    MSG_Menus_TurboChargeBegin,
    [BTL_MSG_TURBO_CHARGE_END]      MSG_Menus_TurboChargeEnd,
    [BTL_MSG_CHILL_OUT_BEGIN]       MSG_Menus_ChillOutBegin,
    [BTL_MSG_UNUSED_CLOUD_NINE]     MSG_Menus_CloudNineBegin,

    // move action command tips
    [BTL_MSG_ACTION_TIP_00]         MSG_Menus_MoveTip_PressBeforeLanding,
    [BTL_MSG_ACTION_TIP_01]         MSG_Menus_MoveTip_PushLeftWithTiming,
    [BTL_MSG_ACTION_TIP_02]         MSG_Menus_MoveTip_PressBeforeStriking,
    [BTL_MSG_ACTION_TIP_03]         MSG_Menus_MoveTip_PressRepeatedly,
    [BTL_MSG_ACTION_TIP_04]         MSG_Menus_MoveTip_PushLeftRepeatedly,
    [BTL_MSG_ACTION_TIP_05]         MSG_Menus_MoveTip_PushLeftToAim,
    [BTL_MSG_ACTION_TIP_06]         MSG_Menus_MoveTip_PressBeforeLanding,
    [BTL_MSG_ACTION_TIP_07]         MSG_Menus_MoveTip_PressBeforeLanding,
    [BTL_MSG_ACTION_TIP_08]         MSG_Menus_MoveTip_PressAsShown,
    [BTL_MSG_ACTION_TIP_09]         MSG_Menus_MoveTip_NOT_USED_1,
    [BTL_MSG_ACTION_TIP_0A]         MSG_Menus_MoveTip_PressAsLightsUp,
    [BTL_MSG_ACTION_TIP_0B]         MSG_Menus_MoveTip_NOT_USED_2,
    [BTL_MSG_ACTION_TIP_0C]         MSG_Menus_MoveTip_PressBothRepeatedly,
    [BTL_MSG_ACTION_TIP_0D]         MSG_Menus_MoveTip_PressBeforeLanding,
    [BTL_MSG_ACTION_TIP_0E]         MSG_Menus_MoveTip_HoldThenTap,
    [BTL_MSG_ACTION_TIP_0F]         MSG_Menus_MoveTip_HoldThenRelease,
    [BTL_MSG_ACTION_TIP_10]         MSG_Menus_MoveTip_MoveToAim,
    [BTL_MSG_ACTION_TIP_11]         MSG_Menus_MoveTip_PressBeforeLanding,
    [BTL_MSG_ACTION_TIP_12]         MSG_Menus_MoveTip_PressToRunAway,
    [BTL_MSG_ACTION_TIP_13]         MSG_Menus_MoveTip_PressToReduceDamage,
    [BTL_MSG_ACTION_TIP_14]         MSG_Menus_MoveTip_NOT_USED_3,

    // no targets available
    [BTL_MSG_NO_JUMP_TARGET]        MSG_Menus_Battle_NoTarget_Jump,
    [BTL_MSG_NO_HAMMER_TARGET]      MSG_Menus_Battle_NoTarget_Hammer,
    [BTL_MSG_NO_ITEM_TARGET]        MSG_Menus_Battle_NoTarget_Item,
    [BTL_MSG_46]                    MSG_NONE,
    [BTL_MSG_47]                    MSG_NONE,

    // errors and warnings
    [BTL_MSG_CANT_SELECT_NOW]       MSG_Menus_Battle_CantSelectNow,
    [BTL_MSG_HAMMER_DISABLED_1]     MSG_Menus_Battle_CantUseHammer,
    [BTL_MSG_HAMMER_DISABLED_2]     MSG_Menus_Battle_CantUseHammer,
    [BTL_MSG_HAMMER_DISABLED_3]     MSG_Menus_Battle_CantUseHammer,
    [BTL_MSG_JUMP_DISABLED_1]       MSG_Menus_Battle_CantUseJump,
    [BTL_MSG_JUMP_DISABLED_2]       MSG_Menus_Battle_CantUseJump,
    [BTL_MSG_JUMP_DISABLED_3]       MSG_Menus_Battle_CantUseJump,
    [BTL_MSG_ITEMS_DISABLED]        MSG_Menus_Battle_CantUseItems,
    [BTL_MSG_CANT_SWITCH]           MSG_Menus_Battle_CantSwitch,
    [BTL_MSG_CANT_MOVE]             MSG_Menus_Battle_CantMove,
    [BTL_MSG_CANT_SWITCH_UNUSED]    MSG_Menus_Battle_CantSwitch,
    [BTL_MSG_CANT_MOVE_UNUSED]      MSG_Menus_Battle_CantMove,
    [BTL_MSG_CANT_SELECT_NOW_ALT]   MSG_Menus_Battle_CantSelectNow,
};

s32 bActorMessages[] = {
    MSG_Menus_Party_Mario,
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
    MSG_Menus_Party_Peach
};

PopupMessage* bPopupMessage = NULL;

s32 D_802838FC_padding = 0;

//TODO split files

#include "ui/battle/cursor_hand.png.inc.c"
#include "ui/battle/cursor_hand.pal.inc.c"

Vtx BtlCursorModelVtx[] = {
    {{{ -22, -6, 0 }, 0, { 1024, 1024 }, { 0, 0, 0, 255 }}},
    {{{   9, -6, 0 }, 0, {    0, 1024 }, { 0, 0, 0, 255 }}},
    {{{   9, 25, 0 }, 0, {    0,    0 }, { 0, 0, 0, 255 }}},
    {{{ -22, 25, 0 }, 0, { 1024,    0 }, { 0, 0, 0, 255 }}},
};

Gfx BtlCursorModelGfx[] = {
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, ui_battle_cursor_hand_pal),
    gsDPLoadTextureTile_4b(ui_battle_cursor_hand_png, G_IM_FMT_CI, 32, 0, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(BtlCursorModelVtx, 4, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsSPEndDisplayList(),
};

EntityModelScript EMS_CursorIcon = STANDARD_ENTITY_MODEL_SCRIPT(BtlCursorModelGfx, RENDER_MODE_ALPHATEST);

Vtx BtlBonkModelVtx[] = {
    {{{ -16, -16, 0 }, 0, {    0,    0 }, { 0, 0, 0, 255 }}},
    {{{  15, -16, 0 }, 0, { 1024,    0 }, { 0, 0, 0, 255 }}},
    {{{  15,  15, 0 }, 0, { 1024, 1024 }, { 0, 0, 0, 255 }}},
    {{{ -16,  15, 0 }, 0, {    0, 1024 }, { 0, 0, 0, 255 }}},
};

Gfx BtlBonkModelGfx[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(PM_CC_01, PM_CC_02),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, ui_battle_menu_spirits_pal),
    gsDPLoadTextureTile_4b(ui_battle_menu_spirits_png, G_IM_FMT_CI, 32, 0, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(BtlBonkModelVtx, 4, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

EntityModelScript EMS_BonkIcon = STANDARD_ENTITY_MODEL_SCRIPT(BtlBonkModelGfx, RENDER_MODE_2D);

Vtx BtlStarModelVtx[] = {
    {{{ -16, -16, 0 }, 0, {    0, 1024 }, { 0, 0, 0, 255 }}},
    {{{  15, -16, 0 }, 0, { 1024, 1024 }, { 0, 0, 0, 255 }}},
    {{{  15,  15, 0 }, 0, { 1024,    0 }, { 0, 0, 0, 255 }}},
    {{{ -16,  15, 0 }, 0, {    0,    0 }, { 0, 0, 0, 255 }}},
};

Gfx BtlStarModelGfx[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_AVERAGE),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPLoadTLUT_pal16(0, ui_battle_solid_star_pal),
    gsDPLoadTextureTile_4b(ui_battle_solid_star_png, G_IM_FMT_CI, 32, 0, 0, 0, 31, 31, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPVertex(BtlStarModelVtx, 4, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

EntityModelScript EMS_StarIcon = STANDARD_ENTITY_MODEL_SCRIPT(BtlStarModelGfx, RENDER_MODE_ALPHATEST);

s32 D_80283F04_padding = 0;
s32 D_80283F08_padding = 0;
s32 D_80283F0C_padding = 0;

#define BATTLE_PARTNER_ENTRY(name, Y) \
    { \
        (u32)battle_partner_##name##_ROM_START, \
        (u32)battle_partner_##name##_ROM_END, \
        battle_partner_##name##_VRAM, \
        &battle_partner_##name, \
        Y \
    }

PartnerDMAData bPartnerDmaTable[] = {
    {},
    BATTLE_PARTNER_ENTRY(goombario, 0),
    BATTLE_PARTNER_ENTRY(kooper, 0),
    BATTLE_PARTNER_ENTRY(bombette, 0),
    BATTLE_PARTNER_ENTRY(parakarry, 30),
    BATTLE_PARTNER_ENTRY(goompa, 0),
    BATTLE_PARTNER_ENTRY(watt, 20),
    BATTLE_PARTNER_ENTRY(sushie, 0),
    BATTLE_PARTNER_ENTRY(lakilester, 10),
    BATTLE_PARTNER_ENTRY(bow, 20),
    {},
    BATTLE_PARTNER_ENTRY(twink, 30),
};

BSS PopupMessage popupMessages[32];
BSS s16 D_8029F640;
BSS s16 D_8029F642;
BSS s16 D_8029F644;
BSS s16 D_8029F646;
BSS s16 D_8029F648;
BSS s16 D_8029F64A;
BSS s16 D_8029F64C;
BSS s16 D_8029F64E;
BSS s16 D_8029F650;

extern HudScript HES_AimReticle;
extern HudScript HES_AimTarget;
extern HudScript HES_CDownButton;
extern HudScript HES_CLeftButton;
extern HudScript HES_CRightButton;
extern HudScript HES_CUpButton;
extern HudScript HES_Item_MenuBoots1;
extern HudScript HES_Item_MenuBoots2;
extern HudScript HES_Item_MenuBoots3;
extern HudScript HES_Item_MenuHammer1;
extern HudScript HES_Item_MenuHammer2;
extern HudScript HES_Item_MenuHammer3;
extern HudScript HES_Item_MenuItems;
extern HudScript HES_MashBButton2;
extern HudScript HES_MashCDownButton1;
extern HudScript HES_MashCLeftButton;
extern HudScript HES_MashCRightButton1;
extern HudScript HES_MashCUpButton;
extern HudScript HES_RotateStickCW;
extern HudScript HES_StickBackAndForth;
extern HudScript HES_StickTapLeft;
extern HudScript HES_StickTapRight;
extern HudScript HES_TimingBlink;

void btl_bonk_update(void* data);
void btl_bonk_render(void* data);
void btl_bonk_setup_gfx(void* data);
void btl_update_message_popup(void* popup);
void btl_show_message_popup(void* popup);

void btl_popup_messages_init(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        popup->active = FALSE;
        popup->message = NULL;
    }
}

void btl_popup_messages_delete(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (popup->message != NULL) {
            heap_free(popup->message);
            popup->message = NULL;
        }
        popup->active = FALSE;
    }
}

void btl_popup_messages_update(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (popup->active && popup->updateFunc != NULL) {
            popup->updateFunc(popup);
        }
    }
}

void btl_popup_messages_draw_world_geometry(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (popup->active && popup->renderWorldFunc != NULL) {
            popup->renderWorldFunc(popup);
        }
    }
}

void btl_popup_messages_draw_ui(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (popup->active && popup->renderUIFunc != NULL) {
            popup->renderUIFunc(popup);
        }
    }
}

PopupMessage* btl_create_popup(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];
        if (!popup->active) {
            popup->active = TRUE;
            return popup;
        }
    }

    return NULL;
}

void free_popup(PopupMessage* popup) {
    if (popup->message != NULL) {
        heap_free(popup->message);
        popup->message = NULL;
    }
    popup->active = FALSE;
}

void show_immune_bonk(f32 x, f32 y, f32 z, s32 numStars, s32 arg4, s32 arg5) {
    BattleStatus* battleStatus = &gBattleStatus;
    PopupMessage* popup;
    Message* message;
    EntityModelScript** modelScript;
    f32 var_f20;
    f32 baseScale;
    f32* f1;
    f32* f2;
    f32* f3;
    s32 arg5mod8;
    s32 iMod8;
    s32 sign;
    s32 cond;
    s32 one;
    s32 two;
    s32 i;

    baseScale = 1.0f;
    cond = FALSE;
    var_f20 = 1.0f;
    if (numStars < 1) {
        numStars = 1;
        cond = TRUE;
        baseScale = 0.4f;
        var_f20 = 0.7f;
    }

    if (battleStatus->flags1 & (BS_FLAGS1_200 | BS_FLAGS1_40)) {
        baseScale *= 2.0;
    }

    popup = btl_create_popup();
    if (popup != NULL) {
        sign = 1;
        if (arg5 < 0) {
            arg5 = -arg5;
            sign = -1;
        }

        while (TRUE) {
            if (arg5 > 5) {
                arg5 -= 5;
            } else {
                break;
            }
        }

        battleStatus->unk_90 = 0;
        popup->updateFunc = btl_bonk_update;
        popup->renderWorldFunc = btl_bonk_render;
        popup->unk_00 = 0;
        popup->renderUIFunc = NULL;
        popup->messageIndex = 1;
        popup->active |= 0x10;
        message = popup->message = heap_malloc(numStars * sizeof(*popup->message));
        ASSERT (popup->message != NULL);

        for (i = 0; i < numStars; i++, message++) {
            modelScript = &bBonkModelScripts[numStars];
            message->unk_00 = TRUE;
            message->entityModelIndex = load_entity_model(*modelScript);
            set_entity_model_flags(message->entityModelIndex, ENTITY_MODEL_FLAG_HIDDEN);
            bind_entity_model_setupGfx(message->entityModelIndex, message, btl_bonk_setup_gfx);
            message->pos.x = x;
            message->pos.y = y;
            message->pos.z = z;
            arg5mod8 = arg5 % 8;
            arg5++;

            one = 1;
            two = 2;

            f1 = &D_802835DC[arg5mod8 * 3];
            f2 = &D_802835DC[arg5mod8 * 3 + one];
            f3 = &D_802835DC[arg5mod8 * 3 + two];
            message->vel.x = 2.0 * *f1 * sign * var_f20;
            message->vel.y = 2.0 * *f2 * var_f20;
            message->vel.z = 2.0 * *f3 * var_f20;
            message->accel.x = *f1 * sign * var_f20;
            message->accel.y = *f2 * var_f20;
            message->accel.z = *f3 * var_f20;

            iMod8 = (i % 8);
            message->scale = D_80283690[iMod8].x * baseScale;
            message->rotZ = 0;
            message->rotVelZ = sign * 107;
            message->rotY = clamp_angle(180.0f - gCameras[CAM_BATTLE].curYaw);
            message->appearTime = 14;
            message->unk_24 = arg4;
            message->deleteTime = 240;
            if (cond) {
                message->deleteTime = 10;
            }
            message->unk_48 = 255.0f;
        }
    }
}

void btl_bonk_update(void* data) {
    PopupMessage* popup = data;
    Message* message = popup->message;
    s32 found = FALSE;
    s32 i;

    for (i = 0; i < popup->messageIndex; i++, message++) {
        if (message->unk_00) {
            s32 modelIdx = message->entityModelIndex;

            found = TRUE;
            if (message->unk_24 != 0) {
                message->unk_24--;
                if (message->unk_24 == 0) {
                    clear_entity_model_flags(modelIdx, MODEL_FLAG_20);
                }
                exec_entity_model_commandlist(modelIdx);
                break;
            }

            exec_entity_model_commandlist(modelIdx);
            if (message->appearTime >= 0) {
                message->pos.x += message->vel.x;
                message->pos.y += message->vel.y;
                message->pos.z += message->vel.z;
            }
            message->rotY = clamp_angle(180.0f - gCameras[CAM_BATTLE].curYaw);
            message->rotZ += message->rotVelZ;
            message->rotZ = clamp_angle(message->rotZ);
            message->rotVelZ *= 0.8;
            if (message->appearTime < 10) {
                message->accel.x *= 0.5;
                message->accel.y *= 0.5;
                message->accel.z *= 0.5;
                message->vel.x = message->accel.x;
                message->vel.y = message->accel.y;
                message->vel.z = message->accel.z;
            }

            message->appearTime--;
            if (message->appearTime < 0) {
                message->deleteTime--;
                if (message->deleteTime < 0) {
                    free_entity_model_by_index(modelIdx);
                    message->unk_00 = FALSE;
                }
            }
        }
    }

    if (!found) {
        heap_free(popup->message);
        popup->message = NULL;
        free_popup(popup);
    }
}

void btl_bonk_render(void* data) {
    PopupMessage* popup = data;
    Message* message = popup->message;
    Matrix4f sp18;
    Matrix4f mtxRotX;
    Matrix4f mtxRotY;
    Matrix4f mtxRotZ;
    Matrix4f sp118;
    Matrix4f sp158;
    Matrix4f sp198;
    Matrix4f mtxScale;
    Mtx sp218;
    s32 i;

    for (i = 0; i < popup->messageIndex; i++, message++) {
        if (message->unk_00) {
            if (message->unk_24 != 0) {
                break;
            } else {
                s32 modelIdx = message->entityModelIndex;

                guTranslateF(sp18, message->pos.x, message->pos.y, message->pos.z);
                guRotateF(mtxRotX, 0.0f, 1.0f, 0.0f, 0.0f);
                guRotateF(mtxRotY, message->rotY, 0.0f, 1.0f, 0.0f);
                guRotateF(mtxRotZ, message->rotZ, 0.0f, 0.0f, 1.0f);
                guScaleF(mtxScale, message->scale, message->scale, message->scale);
                guMtxCatF(mtxRotZ, mtxRotX, sp158);
                guMtxCatF(sp158, mtxRotY, sp118);
                guMtxCatF(mtxScale, sp118, sp158);
                guMtxCatF(sp158, sp18, sp198);
                guMtxF2L(sp198, &sp218);
                draw_entity_model_A(modelIdx, &sp218);
            }
        }
    }
}

void btl_bonk_setup_gfx(void* data) {
    Message* message = data;
    s32 alphaAmt = message->deleteTime;

    if (alphaAmt > 10) {
        alphaAmt = 10;
    }
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, (alphaAmt * 255) / 10);
}

void btl_bonk_cleanup(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(popupMessages); i++) {
        PopupMessage* popup = &popupMessages[i];

        if (popup->active != 0 && (popup->active & 0x10)) {
            Message* message = popup->message;
            s32 j;

            for (j = 0; j < popup->messageIndex; j++, message++) {
                if (message->unk_00) {
                    message->unk_24 = 0;
                    message->appearTime = 1;
                    message->deleteTime = 20;
                }
            }
        }
    }
}

ApiStatus ShowImmuneBonk(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 arg4 = evt_get_variable(script, *args++);
    s32 arg5 = evt_get_variable(script, *args++);
    s32 arg6 = evt_get_variable(script, *args++);

    show_immune_bonk(x, y, z, arg4, arg5, arg6);
    return ApiStatus_DONE2;
}

ApiStatus ForceImmuneBonkCleanup(Evt* script, s32 isInitialCall) {
    btl_bonk_cleanup();
    return ApiStatus_DONE2;
}

// show a popup message bubble with a message selected from BattleMessages
void btl_show_battle_message(s32 messageIndex, s32 duration) {
    PopupMessage* popup = btl_create_popup();

    if (popup != NULL) {
        popup->updateFunc = btl_update_message_popup;
        popup->renderUIFunc = btl_show_message_popup;
        popup->unk_00 = 0;
        popup->renderWorldFunc = NULL;
        popup->messageIndex = messageIndex;
        popup->duration = duration;
        popup->showMsgState = 0;
        popup->needsInit = TRUE;
        popup->message = NULL;
        D_8029F640 = 0;
        bPopupMessage = popup;
        D_8029F64A = FALSE;
        D_8029F64C = 0;
        D_8029F64E = 0;
        D_8029F650 = 0;
    }
}

// show a popup message bubble with a message selected from BattleMessages
void btl_show_variable_battle_message(s32 messageIndex, s32 duration, s32 varValue) {
    PopupMessage* popup = btl_create_popup();

    if (popup != NULL) {
        popup->updateFunc = btl_update_message_popup;
        popup->renderUIFunc = btl_show_message_popup;
        popup->unk_00 = 0;
        popup->renderWorldFunc = NULL;
        popup->messageIndex = messageIndex;
        popup->duration = duration;
        popup->showMsgState = 0;
        popup->needsInit = TRUE;
        popup->message = NULL;
        D_8029F640 = varValue;
        bPopupMessage = popup;
        D_8029F64A = FALSE;
        D_8029F64C = 0;
        D_8029F64E = 0;
        D_8029F650 = 0;
    }
}

s32 btl_is_popup_displayed(void) {
    return bPopupMessage != NULL;
}

void btl_set_popup_duration(s32 duration) {
    PopupMessage* popup = bPopupMessage;

    if (D_8029F64A && popup != NULL) {
        popup->duration = duration;
    }
}

void func_8024FAE8(void) {
    D_8029F64C = 1;
}

void func_8024FAFC(void) {
    D_8029F64C = 0;
}

void close_action_command_instruction_popup(void) {
    PopupMessage* popup = bPopupMessage;

    if (popup != NULL && popup->messageIndex < BTL_MSG_NO_JUMP_TARGET && popup->messageIndex >= BTL_MSG_ACTION_TIP_00) {
        popup->duration = 0;
    }
}

void btl_update_message_popup(void* data) {
    PopupMessage* popup = data;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 shouldDisposeWindow = FALSE;

    s32 actionCommandMode;

    switch (popup->messageIndex) {
        case BTL_MSG_MERLEE_ATK_UP:
        case BTL_MSG_MERLEE_DEF_UP:
        case BTL_MSG_MERLEE_EXP_UP:
        case BTL_MSG_MERLEE_DONE:
        case BTL_MSG_CHARGE_HAMMER:
        case BTL_MSG_CHARGE_HAMMER_MORE:
        case BTL_MSG_CHARGE_JUMP:
        case BTL_MSG_CHARGE_JUMP_MORE:
        case BTL_MSG_CANT_CHARGE:
        case BTL_MSG_ENEMY_MISSED:
        case BTL_MSG_PLAYER_DAZED:
        case BTL_MSG_PLAYER_ASLEEP:
        case BTL_MSG_PLAYER_FROZEN:
        case BTL_MSG_PLAYER_POISONED:
        case BTL_MSG_PLAYER_SHRUNK:
        case BTL_MSG_PLAYER_PARALYZED:
        case BTL_MSG_PLAYER_CHARGED:
        case BTL_MSG_PLAYER_TRANSPARENT:
        case BTL_MSG_ENEMY_DAZED:
        case BTL_MSG_ENEMY_ASLEEP:
        case BTL_MSG_ENEMY_FROZEN:
        case BTL_MSG_ENEMY_POISONED:
        case BTL_MSG_ENEMY_SHRUNK:
        case BTL_MSG_ENEMY_PARALYZED:
        case BTL_MSG_ENEMY_ELECTRIFIED:
        case BTL_MSG_ENEMY_CANT_MOVE:
        case BTL_MSG_STAR_POWER_RECHARGED:
        case BTL_MSG_STAR_POWER_MAXED:
        case BTL_MSG_STAR_POWER_FILLED:
        case BTL_MSG_ATTACK_UP:
        case BTL_MSG_DEFENCE_UP:
        case BTL_MSG_HEAL_ONE:
        case BTL_MSG_HEAL_ALL:
        case BTL_MSG_ENEMY_TRANSPARENT:
        case BTL_MSG_ENEMY_CHARGED:
        case BTL_MSG_PARTNER_INJURED:
        case BTL_MSG_CHARGE_GOOMBARIO:
        case BTL_MSG_CHARGE_GOOMBARIO_MORE:
        case BTL_MSG_WATER_BLOCK_BEGIN:
        case BTL_MSG_WATER_BLOCK_END:
        case BTL_MSG_CLOUD_NINE_BEGIN:
        case BTL_MSG_CLOUD_NINE_END:
        case BTL_MSG_TURBO_CHARGE_BEGIN:
        case BTL_MSG_TURBO_CHARGE_END:
        case BTL_MSG_CHILL_OUT_BEGIN:
        case BTL_MSG_UNUSED_CLOUD_NINE:
        case BTL_MSG_CANT_SWITCH:
        case BTL_MSG_CANT_MOVE:
        case BTL_MSG_CANT_SWITCH_UNUSED:
        case BTL_MSG_CANT_MOVE_UNUSED:
        case BTL_MSG_CANT_SELECT_NOW_ALT:
            switch (popup->showMsgState) {
                default:
                    break;
                case 0:
                    popup->showMsgState = 1;
                    break;
                case 1:
                    popup->showMsgState = 2;
                    break;
                case 2:
                    if (battleStatus->curButtonsPressed & (BUTTON_A | BUTTON_B)) {
                        popup->duration = 0;
                    }

                    if (popup->duration != 0) {
                        popup->duration--;
                    } else {
                        popup->showMsgState = 3;
                    }
                    break;
                case 4:
                    shouldDisposeWindow = TRUE;
                    break;
                case 3:
                    popup->showMsgState = 4;
                    break;
            }
            break;
        // move action command tips
        case BTL_MSG_ACTION_TIP_00:
        case BTL_MSG_ACTION_TIP_01:
        case BTL_MSG_ACTION_TIP_02:
        case BTL_MSG_ACTION_TIP_03:
        case BTL_MSG_ACTION_TIP_04:
        case BTL_MSG_ACTION_TIP_05:
        case BTL_MSG_ACTION_TIP_06:
        case BTL_MSG_ACTION_TIP_07:
        case BTL_MSG_ACTION_TIP_08:
        case BTL_MSG_ACTION_TIP_09:
        case BTL_MSG_ACTION_TIP_0A:
        case BTL_MSG_ACTION_TIP_0B:
        case BTL_MSG_ACTION_TIP_0C:
        case BTL_MSG_ACTION_TIP_0D:
        case BTL_MSG_ACTION_TIP_0E:
        case BTL_MSG_ACTION_TIP_0F:
        case BTL_MSG_ACTION_TIP_10:
        case BTL_MSG_ACTION_TIP_11:
        case BTL_MSG_ACTION_TIP_12:
        case BTL_MSG_ACTION_TIP_13:
        case BTL_MSG_ACTION_TIP_14:
            actionCommandMode = battleStatus->actionCommandMode;
            D_8029F64A = TRUE;
            if (actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
                D_8029F64A = FALSE;
                shouldDisposeWindow = TRUE;
                break;
            }

            switch (popup->showMsgState) {
                case 0:
                    gBattleStatus.flags1 |= BS_FLAGS1_4000;
                    gBattleStatus.flags1 &= ~BS_FLAGS1_10000;
                    switch (popup->messageIndex) {
                        case BTL_MSG_ACTION_TIP_04:
                            D_8029F642 = hud_element_create(&HES_StickNeutral);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                        case BTL_MSG_ACTION_TIP_01:
                            D_8029F642 = hud_element_create(&HES_StickNeutral);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);

                            D_8029F644 = hud_element_create(&HES_TimingReady);
                            hud_element_set_flags(D_8029F644, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F644, -100, -100);
                            break;
                        case BTL_MSG_ACTION_TIP_05:
                            D_8029F642 = hud_element_create(&HES_StickNeutral);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);

                            D_8029F644 = hud_element_create(&HES_AimTarget);
                            hud_element_set_flags(D_8029F644, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F644, -100, -100);
                            hud_element_create_transform_B(D_8029F644);
                            break;
                        case BTL_MSG_ACTION_TIP_06:
                            D_8029F642 = hud_element_create(&HES_CUpButton);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);

                            D_8029F644 = hud_element_create(&HES_CDownButton);
                            hud_element_set_flags(D_8029F644, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F644, -100, -100);

                            D_8029F646 = hud_element_create(&HES_CLeftButton);
                            hud_element_set_flags(D_8029F646, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F646, -100, -100);

                            D_8029F648 = hud_element_create(&HES_CRightButton);
                            hud_element_set_flags(D_8029F648, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F648, -100, -100);
                            break;
                        case BTL_MSG_ACTION_TIP_07:
                            D_8029F642 = hud_element_create(&HES_StickNeutral);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                        case BTL_MSG_ACTION_TIP_08:
                            D_8029F642 = hud_element_create(&HES_AButton);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);

                            D_8029F644 = hud_element_create(&HES_BButton);
                            hud_element_set_flags(D_8029F644, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F644, -100, -100);

                            D_8029F646 = hud_element_create(&HES_CDownButton);
                            hud_element_set_flags(D_8029F646, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F646, -100, -100);
                            break;
                        case BTL_MSG_ACTION_TIP_09:
                            D_8029F642 = hud_element_create(&HES_StickNeutral);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                        case BTL_MSG_ACTION_TIP_0A:
                            D_8029F642 = hud_element_create(&HES_TimingReady);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);

                            D_8029F644 = hud_element_create(&HES_AButton);
                            hud_element_set_flags(D_8029F644, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F644, -100, -100);
                            break;
                        case BTL_MSG_ACTION_TIP_0B:
                            D_8029F642 = hud_element_create(&HES_AButton);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            D_8029F644 = hud_element_create(&HES_BButton);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                        case BTL_MSG_ACTION_TIP_0C:
                            D_8029F642 = hud_element_create(&HES_AButton);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);

                            D_8029F644 = hud_element_create(&HES_BButton);
                            hud_element_set_flags(D_8029F644, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F644, -100, -100);
                            break;
                        case BTL_MSG_ACTION_TIP_0F:
                            D_8029F642 = hud_element_create(&HES_TimingReady);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);

                            D_8029F644 = hud_element_create(&HES_AButtonDown);
                            hud_element_set_flags(D_8029F644, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F644, -100, -100);
                            break;
                        case BTL_MSG_ACTION_TIP_10:
                            D_8029F642 = hud_element_create(&HES_StickNeutral);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);

                            D_8029F644 = hud_element_create(&HES_AimTarget);
                            hud_element_set_flags(D_8029F644, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F644, -100, -100);
                            hud_element_create_transform_B(D_8029F644);

                            D_8029F646 = hud_element_create(&HES_AimReticle);
                            hud_element_set_flags(D_8029F646, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F646, -100, -100);
                            hud_element_create_transform_B(D_8029F646);
                            break;
                        case BTL_MSG_ACTION_TIP_12:
                        case BTL_MSG_ACTION_TIP_13:
                            D_8029F642 = hud_element_create(&HES_AButton);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            // fallthrough
                        case BTL_MSG_ACTION_TIP_00:
                        case BTL_MSG_ACTION_TIP_02:
                        case BTL_MSG_ACTION_TIP_03:
                        case BTL_MSG_ACTION_TIP_0D:
                        case BTL_MSG_ACTION_TIP_0E:
                        case BTL_MSG_ACTION_TIP_11:
                        case BTL_MSG_ACTION_TIP_14:
                            D_8029F642 = hud_element_create(&HES_AButton);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_FILTER_TEX | HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                    }
                    popup->showMsgState = 1;
                    break;
                case 1:
                    if (gBattleStatus.flags1 & BS_FLAGS1_10000) {
                        gBattleStatus.flags1 &= ~BS_FLAGS1_4000;
                        set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_SHOW_TRANSPARENT);
                        popup->duration = 0;
                        popup->showMsgState = 2;
                    } else if (!(gBattleStatus.flags1 & BS_FLAGS1_4000) && (actionCommandMode != ACTION_COMMAND_MODE_TUTORIAL)) {
                        set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_SHOW_TRANSPARENT);
                        switch (popup->messageIndex) {
                            case BTL_MSG_ACTION_TIP_03:
                                hud_element_set_script(D_8029F642, &HES_MashAButton);
                                break;
                            case BTL_MSG_ACTION_TIP_04:
                                hud_element_set_script(D_8029F642, &HES_StickMashLeft);
                                break;
                            case BTL_MSG_ACTION_TIP_01:
                                hud_element_set_script(D_8029F642, &HES_StickTapLeft);
                                hud_element_set_script(D_8029F644, &HES_TimingBlink);
                                break;
                            case BTL_MSG_ACTION_TIP_05:
                                hud_element_set_script(D_8029F642, &HES_StickTapLeft);
                                hud_element_set_script(D_8029F644, &HES_AimTarget);
                                break;
                            case BTL_MSG_ACTION_TIP_06:
                                hud_element_set_script(D_8029F642, &HES_MashCUpButton);
                                hud_element_set_script(D_8029F644, &HES_MashCDownButton1);
                                hud_element_set_script(D_8029F646, &HES_MashCLeftButton);
                                hud_element_set_script(D_8029F648, &HES_MashCRightButton1);
                                break;
                            case BTL_MSG_ACTION_TIP_07:
                                hud_element_set_script(D_8029F642, &HES_StickBackAndForth);
                                break;
                            case BTL_MSG_ACTION_TIP_08:
                                hud_element_set_script(D_8029F642, &HES_PressAButton);
                                hud_element_set_script(D_8029F644, &HES_PressBButton);
                                hud_element_set_script(D_8029F646, &HES_PressCDownButton);
                                break;
                            case BTL_MSG_ACTION_TIP_09:
                                hud_element_set_script(D_8029F642, &HES_RotateStickCW);
                                break;
                            case BTL_MSG_ACTION_TIP_0A:
                                hud_element_set_script(D_8029F642, &HES_TimingBlink);
                                hud_element_set_script(D_8029F644, &HES_MashAButton);
                                break;
                            case BTL_MSG_ACTION_TIP_0B:
                                hud_element_set_script(D_8029F642, &HES_MashAButton);
                                hud_element_set_script(D_8029F644, &HES_MashBButton2);
                                break;
                            case BTL_MSG_ACTION_TIP_0C:
                                hud_element_set_script(D_8029F642, &HES_MashAButton);
                                hud_element_set_script(D_8029F644, &HES_MashBButton1);
                                break;
                            case BTL_MSG_ACTION_TIP_0D:
                                hud_element_set_script(D_8029F642, &HES_MashAButton);
                                break;
                            case BTL_MSG_ACTION_TIP_0F:
                                hud_element_set_script(D_8029F642, &HES_TimingBlink);
                                hud_element_set_script(D_8029F644, &HES_PressAButton);
                                break;
                            case BTL_MSG_ACTION_TIP_10:
                                hud_element_set_script(D_8029F642, &HES_StickTapRight);
                                break;
                            case BTL_MSG_ACTION_TIP_11:
                                hud_element_set_script(D_8029F642, &HES_MashAButton);
                                break;
                            case BTL_MSG_ACTION_TIP_12:
                            case BTL_MSG_ACTION_TIP_13:
                                hud_element_set_script(D_8029F642, &HES_PressAButton);
                                // fallthrough
                            case BTL_MSG_ACTION_TIP_00:
                            case BTL_MSG_ACTION_TIP_02:
                            case BTL_MSG_ACTION_TIP_0E:
                            case BTL_MSG_ACTION_TIP_14:
                                hud_element_set_script(D_8029F642, &HES_PressAButton);
                                break;
                        }
                        if (popup->duration != -1) {
                            popup->duration = 30;
                        }
                        popup->showMsgState = 2;
                        break;
                    }
                    break;
                case 2:
                    if ((actionCommandMode != popup->showMsgState) || (gBattleStatus.flags1 & BS_FLAGS1_10000)) {
                        s16* duration;

                        if (D_8029F64E < 192) {
                            if (D_8029F64C == 0) {
                                D_8029F64E += 10;
                                if (D_8029F64E > 192) {
                                    D_8029F64E = 192;
                                }
                            } else {
                                break;
                            }
                        }

                        gWindows[WINDOW_ID_BATTLE_POPUP].pos.y = D_8029F64E + D_8029F650;

                        duration = &popup->duration; // TODO required to match
                        if (*duration != -1) {
                            if (popup->duration != 0) {
                                popup->duration--;
                            } else {
                                switch (popup->messageIndex) {
                                    case BTL_MSG_ACTION_TIP_00:
                                    case BTL_MSG_ACTION_TIP_02:
                                    case BTL_MSG_ACTION_TIP_03:
                                    case BTL_MSG_ACTION_TIP_04:
                                    case BTL_MSG_ACTION_TIP_07:
                                    case BTL_MSG_ACTION_TIP_09:
                                    case BTL_MSG_ACTION_TIP_0D:
                                    case BTL_MSG_ACTION_TIP_0E:
                                    case BTL_MSG_ACTION_TIP_11:
                                    case BTL_MSG_ACTION_TIP_12:
                                    case BTL_MSG_ACTION_TIP_13:
                                    case BTL_MSG_ACTION_TIP_14:
                                        hud_element_free(D_8029F642);
                                        break;
                                    case BTL_MSG_ACTION_TIP_01:
                                    case BTL_MSG_ACTION_TIP_05:
                                    case BTL_MSG_ACTION_TIP_0A:
                                    case BTL_MSG_ACTION_TIP_0B:
                                    case BTL_MSG_ACTION_TIP_0C:
                                    case BTL_MSG_ACTION_TIP_0F:
                                        hud_element_free(D_8029F642);
                                        hud_element_free(D_8029F644);
                                        break;
                                    case BTL_MSG_ACTION_TIP_08:
                                    case BTL_MSG_ACTION_TIP_10:
                                        hud_element_free(D_8029F642);
                                        hud_element_free(D_8029F644);
                                        hud_element_free(D_8029F646);
                                        break;
                                    case BTL_MSG_ACTION_TIP_06:
                                        hud_element_free(D_8029F642);
                                        hud_element_free(D_8029F644);
                                        hud_element_free(D_8029F646);
                                        hud_element_free(D_8029F648);
                                        break;
                                }
                                D_8029F64A = FALSE;
                                shouldDisposeWindow = TRUE;
                            }
                        }
                    }
                    break;
            }
            break;
        case BTL_MSG_NO_JUMP_TARGET:
        case BTL_MSG_NO_HAMMER_TARGET:
        case BTL_MSG_NO_ITEM_TARGET:
        case BTL_MSG_46:
        case BTL_MSG_47:
        case BTL_MSG_CANT_SELECT_NOW:
            switch (popup->showMsgState) {
                default:
                    break;
                case 0:
                    popup->showMsgState = 1;
                    break;
                case 1:
                    popup->showMsgState = 2;
                    break;
                case 2:
                    if (battleStatus->curButtonsPressed & (BUTTON_A | BUTTON_B)) {
                        popup->duration = 0;
                    }

                    if (popup->duration != 0) {
                        popup->duration--;
                    } else {
                        popup->showMsgState = 3;
                    }
                    break;
                case 3:
                    popup->showMsgState = 4;
                    break;
                case 4:
                    shouldDisposeWindow = TRUE;
                    break;
            }
            break;
        case BTL_MSG_HAMMER_DISABLED_1:
        case BTL_MSG_HAMMER_DISABLED_2:
        case BTL_MSG_HAMMER_DISABLED_3:
        case BTL_MSG_JUMP_DISABLED_1:
        case BTL_MSG_JUMP_DISABLED_2:
        case BTL_MSG_JUMP_DISABLED_3:
        case BTL_MSG_ITEMS_DISABLED:
            switch (popup->showMsgState) {
                case 0:
                    switch (popup->messageIndex) {
                        case BTL_MSG_HAMMER_DISABLED_1:
                            D_8029F642 = hud_element_create(&HES_Item_MenuHammer1);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                        case BTL_MSG_HAMMER_DISABLED_2:
                            D_8029F642 = hud_element_create(&HES_Item_MenuHammer2);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                        case BTL_MSG_HAMMER_DISABLED_3:
                            D_8029F642 = hud_element_create(&HES_Item_MenuHammer3);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                        case BTL_MSG_JUMP_DISABLED_1:
                            D_8029F642 = hud_element_create(&HES_Item_MenuBoots1);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                        case BTL_MSG_JUMP_DISABLED_2:
                            D_8029F642 = hud_element_create(&HES_Item_MenuBoots2);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                        case BTL_MSG_JUMP_DISABLED_3:
                            D_8029F642 = hud_element_create(&HES_Item_MenuBoots3);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                        case BTL_MSG_ITEMS_DISABLED:
                            D_8029F642 = hud_element_create(&HES_Item_MenuItems);
                            hud_element_set_flags(D_8029F642, HUD_ELEMENT_FLAG_80);
                            hud_element_set_render_pos(D_8029F642, -100, -100);
                            break;
                    }
                    popup->showMsgState = 1;
                    break;
                case 1:
                    if (popup->duration != 0) {
                        popup->duration--;
                        break;
                    }
                    shouldDisposeWindow = TRUE;
                    hud_element_free(D_8029F642);
                    break;
            }
            break;
    }
    if (shouldDisposeWindow) {
        set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_HIDE);
        bPopupMessage = NULL;
        free_popup(popup);
    }
}

void func_80250818(void* data, s32 x, s32 y) {
    PopupMessage* popup = data;
    s32 messageID;
    s32 msgLinesIdx;
    s32 opacity;

    x += 15;
    y += 6;

    switch (popup->messageIndex) {
        case BTL_MSG_MERLEE_ATK_UP:
        case BTL_MSG_MERLEE_DEF_UP:
        case BTL_MSG_MERLEE_EXP_UP:
        case BTL_MSG_MERLEE_DONE:
        case BTL_MSG_CANT_CHARGE:
        case BTL_MSG_ENEMY_MISSED:
        case BTL_MSG_PLAYER_DAZED:
        case BTL_MSG_PLAYER_ASLEEP:
        case BTL_MSG_PLAYER_FROZEN:
        case BTL_MSG_PLAYER_POISONED:
        case BTL_MSG_PLAYER_SHRUNK:
        case BTL_MSG_PLAYER_PARALYZED:
        case BTL_MSG_PLAYER_CHARGED:
        case BTL_MSG_PLAYER_TRANSPARENT:
        case BTL_MSG_ENEMY_DAZED:
        case BTL_MSG_ENEMY_ASLEEP:
        case BTL_MSG_ENEMY_FROZEN:
        case BTL_MSG_ENEMY_POISONED:
        case BTL_MSG_ENEMY_SHRUNK:
        case BTL_MSG_ENEMY_PARALYZED:
        case BTL_MSG_ENEMY_ELECTRIFIED:
        case BTL_MSG_ENEMY_CANT_MOVE:
        case BTL_MSG_STAR_POWER_RECHARGED:
        case BTL_MSG_STAR_POWER_MAXED:
        case BTL_MSG_STAR_POWER_FILLED:
        case BTL_MSG_PARTNER_INJURED:
        case BTL_MSG_CHARGE_GOOMBARIO:
        case BTL_MSG_CHARGE_GOOMBARIO_MORE:
        case BTL_MSG_WATER_BLOCK_BEGIN:
        case BTL_MSG_WATER_BLOCK_END:
        case BTL_MSG_CLOUD_NINE_BEGIN:
        case BTL_MSG_CLOUD_NINE_END:
        case BTL_MSG_TURBO_CHARGE_BEGIN:
        case BTL_MSG_TURBO_CHARGE_END:
        case BTL_MSG_CHILL_OUT_BEGIN:
        case BTL_MSG_UNUSED_CLOUD_NINE:
        case BTL_MSG_NO_JUMP_TARGET:
        case BTL_MSG_NO_HAMMER_TARGET:
        case BTL_MSG_NO_ITEM_TARGET:
        case BTL_MSG_46:
        case BTL_MSG_47:
        case BTL_MSG_CANT_SELECT_NOW:
        case BTL_MSG_CANT_SWITCH:
        case BTL_MSG_CANT_SWITCH_UNUSED:
        case BTL_MSG_CANT_MOVE_UNUSED:
        case BTL_MSG_CANT_SELECT_NOW_ALT:
            messageID = bMessages[popup->messageIndex];
            msgLinesIdx = get_msg_lines(messageID) - 1;
            draw_msg(messageID, x, y + D_802835D4[msgLinesIdx], 255, MSG_PAL_0F, 0);
            break;
        case BTL_MSG_CHARGE_HAMMER:
        case BTL_MSG_CHARGE_HAMMER_MORE:
        case BTL_MSG_CHARGE_JUMP:
        case BTL_MSG_CHARGE_JUMP_MORE:
        case BTL_MSG_ATTACK_UP:
        case BTL_MSG_DEFENCE_UP:
        case BTL_MSG_HEAL_ONE:
        case BTL_MSG_HEAL_ALL:
        case BTL_MSG_ENEMY_TRANSPARENT:
        case BTL_MSG_ENEMY_CHARGED:
            messageID = bMessages[popup->messageIndex];
            msgLinesIdx = get_msg_lines(messageID) - 1;
            y += D_802835D4[msgLinesIdx];
            set_message_value(D_8029F640, 0);
            draw_msg(messageID, x, y, 255, MSG_PAL_0F, 0);
            break;
        case BTL_MSG_CANT_MOVE:
            messageID = bMessages[popup->messageIndex];
            msgLinesIdx = get_msg_lines(messageID) - 1;
            y += D_802835D4[msgLinesIdx];
            set_message_msg(bActorMessages[D_8029F640], 0);
            draw_msg(messageID, x, y, 255, MSG_PAL_0F, 0);
            break;
        case BTL_MSG_HAMMER_DISABLED_1:
        case BTL_MSG_HAMMER_DISABLED_2:
        case BTL_MSG_HAMMER_DISABLED_3:
        case BTL_MSG_JUMP_DISABLED_1:
        case BTL_MSG_JUMP_DISABLED_2:
        case BTL_MSG_JUMP_DISABLED_3:
        case BTL_MSG_ITEMS_DISABLED:
            messageID = bMessages[popup->messageIndex];
            draw_msg(messageID, x + 0x1D, y + 6, 255, MSG_PAL_0F, 0);
            hud_element_set_render_pos(D_8029F642, x + 13, y + 14);
            hud_element_draw_clipped(D_8029F642);
            break;
        case BTL_MSG_ACTION_TIP_00:
        case BTL_MSG_ACTION_TIP_01:
        case BTL_MSG_ACTION_TIP_02:
        case BTL_MSG_ACTION_TIP_03:
        case BTL_MSG_ACTION_TIP_04:
        case BTL_MSG_ACTION_TIP_05:
        case BTL_MSG_ACTION_TIP_06:
        case BTL_MSG_ACTION_TIP_07:
        case BTL_MSG_ACTION_TIP_08:
        case BTL_MSG_ACTION_TIP_09:
        case BTL_MSG_ACTION_TIP_0A:
        case BTL_MSG_ACTION_TIP_0B:
        case BTL_MSG_ACTION_TIP_0C:
        case BTL_MSG_ACTION_TIP_0D:
        case BTL_MSG_ACTION_TIP_0E:
        case BTL_MSG_ACTION_TIP_0F:
        case BTL_MSG_ACTION_TIP_10:
        case BTL_MSG_ACTION_TIP_11:
        case BTL_MSG_ACTION_TIP_12:
        case BTL_MSG_ACTION_TIP_13:
        case BTL_MSG_ACTION_TIP_14:
            opacity = 255;
            if (popup->showMsgState < 2) {
                opacity = 160;
            }
            if (popup->messageIndex == BTL_MSG_ACTION_TIP_0D) {
                opacity = 255;
            }

            x -= 11;
            y -= 6;
            messageID = bMessages[popup->messageIndex];
            msgLinesIdx = get_msg_lines(messageID) - 1;
            y += D_802835D4[msgLinesIdx];
            draw_msg(messageID, x + 11, y + 6, opacity, MSG_PAL_0F, 0);

            switch (popup->messageIndex) {
                case BTL_MSG_ACTION_TIP_00:
                    hud_element_set_render_pos(D_8029F642, x + 65, y + 14);
                    hud_element_set_scale(D_8029F642, 0.5f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);
                    break;
                case BTL_MSG_ACTION_TIP_01:
                    hud_element_set_render_pos(D_8029F642, x + 55, y + 14);
                    hud_element_set_scale(D_8029F642, 0.6f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);

                    hud_element_set_render_pos(D_8029F644, x + 73, y + 31);
                    hud_element_set_alpha(D_8029F644, opacity);
                    hud_element_draw_clipped(D_8029F644);
                    break;
                case BTL_MSG_ACTION_TIP_02:
                    hud_element_set_render_pos(D_8029F642, x + 64, y + 14);
                    hud_element_set_scale(D_8029F642, 0.5f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);
                    break;
                case BTL_MSG_ACTION_TIP_03:
                    hud_element_set_render_pos(D_8029F642, x + 67, y + 14);
                    hud_element_set_scale(D_8029F642, 0.5f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);
                    break;
                case BTL_MSG_ACTION_TIP_04:
                    hud_element_set_render_pos(D_8029F642, x + 56, y + 14);
                    hud_element_set_scale(D_8029F642, 0.6f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);
                    break;
                case BTL_MSG_ACTION_TIP_05:
                    hud_element_set_render_pos(D_8029F642, x + 65, y + 13);
                    hud_element_set_scale(D_8029F642, 0.6f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);

                    hud_element_set_render_pos(D_8029F644, x + 146, y + 32);
                    hud_element_set_scale(D_8029F644, 0.8f);
                    hud_element_set_alpha(D_8029F644, opacity);
                    func_80144218(D_8029F644);
                    break;
                case BTL_MSG_ACTION_TIP_08:
                    hud_element_set_render_pos(D_8029F642, x + 86, y + 13);
                    hud_element_set_scale(D_8029F642, 0.5f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);

                    hud_element_set_render_pos(D_8029F644, x + 64, y + 13);
                    hud_element_set_scale(D_8029F644, 0.5f);
                    hud_element_set_alpha(D_8029F644, opacity);
                    hud_element_draw_clipped(D_8029F644);

                    hud_element_set_render_pos(D_8029F646, x + 108, y + 13);
                    hud_element_set_scale(D_8029F646, 0.5f);
                    hud_element_set_alpha(D_8029F646, opacity);
                    hud_element_draw_clipped(D_8029F646);
                    break;
                case BTL_MSG_ACTION_TIP_0A:
                    hud_element_set_render_pos(D_8029F642, x + 105, y + 13);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);

                    hud_element_set_render_pos(D_8029F644, x + 65, y + 14);
                    hud_element_set_scale(D_8029F644, 0.5f);
                    hud_element_set_alpha(D_8029F644, opacity);
                    hud_element_draw_clipped(D_8029F644);
                    break;
                case BTL_MSG_ACTION_TIP_0C:
                    hud_element_set_render_pos(D_8029F642, x + 63, y + 14);
                    hud_element_set_scale(D_8029F642, 0.5f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);

                    hud_element_set_render_pos(D_8029F644, x + 84, y + 14);
                    hud_element_set_scale(D_8029F644, 0.5f);
                    hud_element_set_alpha(D_8029F644, opacity);
                    hud_element_draw_clipped(D_8029F644);
                    break;
                case BTL_MSG_ACTION_TIP_0E:
                    hud_element_set_render_pos(D_8029F642, x + 124, y + 14);
                    hud_element_set_scale(D_8029F642, 0.5f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);
                    break;
                case BTL_MSG_ACTION_TIP_0F:
                    hud_element_set_render_pos(D_8029F642, x + 56, y + 31);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);

                    hud_element_set_render_pos(D_8029F644, x + 53, y + 14);
                    hud_element_set_scale(D_8029F644, 0.5f);
                    hud_element_set_alpha(D_8029F644, opacity);
                    hud_element_draw_clipped(D_8029F644);
                    break;
                case BTL_MSG_ACTION_TIP_10:
                    hud_element_set_render_pos(D_8029F642, x + 107, y + 13);
                    hud_element_set_scale(D_8029F642, 0.6f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);

                    hud_element_set_render_pos(D_8029F644, x + 210, y + 15);
                    hud_element_set_scale(D_8029F644, 0.8f);
                    hud_element_set_alpha(D_8029F644, opacity);
                    func_80144218(D_8029F644);

                    hud_element_set_render_pos(D_8029F646, x + 56, y + 15);
                    hud_element_set_scale(D_8029F646, 0.8f);
                    hud_element_set_alpha(D_8029F646, opacity);
                    func_80144218(D_8029F646);
                    break;
                case BTL_MSG_ACTION_TIP_12:
                case BTL_MSG_ACTION_TIP_13:
                    hud_element_set_render_pos(D_8029F642, x + 64, y + 13);
                    hud_element_set_scale(D_8029F642, 0.5f);
                    hud_element_set_alpha(D_8029F642, opacity);
                    hud_element_draw_clipped(D_8029F642);
                    break;
            }
            break;
    }
}

void btl_show_message_popup(void* data) {
    PopupMessage* popup = data;
    s32 numLines;
    s32 posX;
    s32 posY = 80;
    s32 width;
    s32 msgWidth;
    s32 height;

    switch (popup->messageIndex) {
        case BTL_MSG_MERLEE_ATK_UP:
        case BTL_MSG_MERLEE_DEF_UP:
        case BTL_MSG_MERLEE_EXP_UP:
        case BTL_MSG_MERLEE_DONE:
        case BTL_MSG_CANT_CHARGE:
        case BTL_MSG_ENEMY_MISSED:
        case BTL_MSG_PLAYER_DAZED:
        case BTL_MSG_PLAYER_ASLEEP:
        case BTL_MSG_PLAYER_FROZEN:
        case BTL_MSG_PLAYER_POISONED:
        case BTL_MSG_PLAYER_SHRUNK:
        case BTL_MSG_PLAYER_PARALYZED:
        case BTL_MSG_PLAYER_CHARGED:
        case BTL_MSG_PLAYER_TRANSPARENT:
        case BTL_MSG_ENEMY_DAZED:
        case BTL_MSG_ENEMY_ASLEEP:
        case BTL_MSG_ENEMY_FROZEN:
        case BTL_MSG_ENEMY_POISONED:
        case BTL_MSG_ENEMY_SHRUNK:
        case BTL_MSG_ENEMY_PARALYZED:
        case BTL_MSG_ENEMY_ELECTRIFIED:
        case BTL_MSG_ENEMY_CANT_MOVE:
        case BTL_MSG_STAR_POWER_RECHARGED:
        case BTL_MSG_STAR_POWER_MAXED:
        case BTL_MSG_STAR_POWER_FILLED:
        case BTL_MSG_PARTNER_INJURED:
        case BTL_MSG_CHARGE_GOOMBARIO:
        case BTL_MSG_CHARGE_GOOMBARIO_MORE:
        case BTL_MSG_WATER_BLOCK_BEGIN:
        case BTL_MSG_WATER_BLOCK_END:
        case BTL_MSG_CLOUD_NINE_BEGIN:
        case BTL_MSG_CLOUD_NINE_END:
        case BTL_MSG_TURBO_CHARGE_BEGIN:
        case BTL_MSG_TURBO_CHARGE_END:
        case BTL_MSG_CHILL_OUT_BEGIN:
        case BTL_MSG_UNUSED_CLOUD_NINE:
        case BTL_MSG_NO_JUMP_TARGET:
        case BTL_MSG_NO_HAMMER_TARGET:
        case BTL_MSG_NO_ITEM_TARGET:
        case BTL_MSG_46:
        case BTL_MSG_47:
        case BTL_MSG_CANT_SELECT_NOW:
        case BTL_MSG_CANT_SWITCH:
        case BTL_MSG_CANT_SWITCH_UNUSED:
        case BTL_MSG_CANT_MOVE_UNUSED:
        case BTL_MSG_CANT_SELECT_NOW_ALT:
            if (popup->needsInit) {
                s32 messageID;

                popup->needsInit = FALSE;
                messageID = bMessages[popup->messageIndex];
                msgWidth = get_msg_width(messageID, 0) + 30;
                posX = 160 - (msgWidth / 2);
                width = msgWidth;
                numLines = get_msg_lines(messageID) - 1;
                height = bMsgHeights[numLines];
                set_window_properties(WINDOW_ID_BATTLE_POPUP, posX, posY, width, height, WINDOW_PRIORITY_0, func_80250818, popup, -1);
                set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_SHOW);
            }
            break;
        case BTL_MSG_HAMMER_DISABLED_1:
        case BTL_MSG_HAMMER_DISABLED_2:
        case BTL_MSG_HAMMER_DISABLED_3:
        case BTL_MSG_JUMP_DISABLED_1:
        case BTL_MSG_JUMP_DISABLED_2:
        case BTL_MSG_JUMP_DISABLED_3:
        case BTL_MSG_ITEMS_DISABLED:
            if (popup->needsInit) {
                popup->needsInit = FALSE;
                msgWidth = get_msg_width(bMessages[popup->messageIndex], 0) + 55;
                posX = 160 - (msgWidth / 2);
                width = msgWidth;
                height = 40;
                set_window_properties(WINDOW_ID_BATTLE_POPUP, posX, posY, width, height, WINDOW_PRIORITY_0, func_80250818, popup, -1);
                set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_SHOW);
            }
            break;
        case BTL_MSG_CHARGE_HAMMER:
        case BTL_MSG_CHARGE_HAMMER_MORE:
        case BTL_MSG_CHARGE_JUMP:
        case BTL_MSG_CHARGE_JUMP_MORE:
        case BTL_MSG_ATTACK_UP:
        case BTL_MSG_DEFENCE_UP:
        case BTL_MSG_HEAL_ONE:
        case BTL_MSG_HEAL_ALL:
        case BTL_MSG_ENEMY_TRANSPARENT:
        case BTL_MSG_ENEMY_CHARGED:
            if (popup->needsInit) {
                s32 messageID;

                popup->needsInit = FALSE;
                messageID = bMessages[popup->messageIndex];
                set_message_value(D_8029F640, 0);
                msgWidth = get_msg_width(messageID, 0) + 31;
                posX = 160 - (msgWidth / 2);
                width = msgWidth;
                numLines = get_msg_lines(messageID) - 1;
                height = bMsgHeights[numLines];
                set_window_properties(WINDOW_ID_BATTLE_POPUP, posX, posY, width, height, WINDOW_PRIORITY_0, func_80250818, popup, -1);
                set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_SHOW);
            }
            break;
        case BTL_MSG_CANT_MOVE:
            if (popup->needsInit) {
                s32 messageID;

                popup->needsInit = FALSE;
                messageID = bMessages[popup->messageIndex];
                set_message_msg(bActorMessages[D_8029F640], 0);
                msgWidth = get_msg_width(messageID, 0) + 31;
                posX = 160 - (msgWidth / 2);
                width = msgWidth;
                numLines = get_msg_lines(messageID) - 1;
                height = bMsgHeights[numLines];
                set_window_properties(WINDOW_ID_BATTLE_POPUP, posX, posY, width, height, WINDOW_PRIORITY_0, func_80250818, popup, -1);
                set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_SHOW);
            }
            break;
        case BTL_MSG_ACTION_TIP_00:
        case BTL_MSG_ACTION_TIP_01:
        case BTL_MSG_ACTION_TIP_02:
        case BTL_MSG_ACTION_TIP_03:
        case BTL_MSG_ACTION_TIP_04:
        case BTL_MSG_ACTION_TIP_05:
        case BTL_MSG_ACTION_TIP_06:
        case BTL_MSG_ACTION_TIP_07:
        case BTL_MSG_ACTION_TIP_08:
        case BTL_MSG_ACTION_TIP_09:
        case BTL_MSG_ACTION_TIP_0A:
        case BTL_MSG_ACTION_TIP_0B:
        case BTL_MSG_ACTION_TIP_0C:
        case BTL_MSG_ACTION_TIP_0D:
        case BTL_MSG_ACTION_TIP_0E:
        case BTL_MSG_ACTION_TIP_0F:
        case BTL_MSG_ACTION_TIP_10:
        case BTL_MSG_ACTION_TIP_11:
        case BTL_MSG_ACTION_TIP_12:
        case BTL_MSG_ACTION_TIP_13:
        case BTL_MSG_ACTION_TIP_14:
            if (popup->needsInit) {
                s32 messageID;

                popup->needsInit = FALSE;
                messageID = bMessages[popup->messageIndex];
                msgWidth = get_msg_width(messageID, 0) + 31;
                posX = 160 - (msgWidth / 2);
                posY = 192;
                width = msgWidth;
                numLines = get_msg_lines(messageID) - 1;
                height = bMsgHeights[numLines];
                if (popup->messageIndex == BTL_MSG_ACTION_TIP_0D) {
                    posY = 120;
                    D_8029F64C = 1;
                }
                D_8029F64E = posY;
                D_8029F650 = D_802835D8[numLines];

                posY = D_8029F64E + D_8029F650;
                set_window_properties(WINDOW_ID_BATTLE_POPUP, posX, posY, width, height, WINDOW_PRIORITY_0, func_80250818, popup, -1);
                if (popup->messageIndex == BTL_MSG_ACTION_TIP_0D) {
                    set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_SHOW);
                } else {
                    set_window_update(WINDOW_ID_BATTLE_POPUP, WINDOW_UPDATE_SHOW_DARKENED);
                }
            }
            break;
    }
}

ApiStatus ShowMessageBox(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 messageIndex = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    btl_show_battle_message(messageIndex, duration);
    return ApiStatus_DONE2;
}

ApiStatus ShowVariableMessageBox(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 messageIndex = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);
    s32 varValue = evt_get_variable(script, *args++);

    btl_show_variable_battle_message(messageIndex, duration, varValue);
    return ApiStatus_DONE2;
}

ApiStatus IsMessageBoxDisplayed(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, btl_is_popup_displayed());
    return ApiStatus_DONE2;
}

ApiStatus WaitForMessageBoxDone(Evt* script, s32 isInitialCall) {
    return !btl_is_popup_displayed() * ApiStatus_DONE2;
}

ApiStatus ForceCloseMessageBox(Evt* script, s32 isInitialCall) {
    if (bPopupMessage != NULL) {
        bPopupMessage->duration = 0;
    }
    return ApiStatus_DONE2;
}

ApiStatus SetMessageBoxDuration(Evt* script, s32 isInitialCall) {
    btl_set_popup_duration(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus func_80251434(Evt* script, s32 isInitialCall) {
    func_8024FAE8();
    return ApiStatus_DONE2;
}

ApiStatus func_80251454(Evt* script, s32 isInitialCall) {
    func_8024FAFC();
    return ApiStatus_DONE2;
}

void apply_shock_effect(Actor* actor) {
    ActorPart* part = actor->partsTable;

    while (part != NULL) {
        if (!(part->flags & ACTOR_PART_FLAG_INVISIBLE)
            && part->idleAnimations != NULL
            && !(part->flags & ACTOR_PART_FLAG_40000000)
        ) {
            f32 x = part->curPos.x;
            f32 y = part->curPos.y + (actor->size.y / 10);
            f32 z = part->curPos.z;
            s32 f1 = (part->size.x + (part->size.x / 4)) * actor->scalingFactor;
            s32 f2 = (part->size.y - 2) * actor->scalingFactor;

            if (actor->flags & ACTOR_FLAG_HALF_HEIGHT) {
                y -= actor->size.y / 2;
            }

            fx_flashing_box_shockwave(0, x, y, z, f1, f2);
        }
        part = part->nextPart;
    }
}
