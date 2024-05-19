#include "common.h"
#include "battle/battle.h"
#include "sprite/player.h"

PlayerCelebrationAnimOptions bPlayerCelebrations = {
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

Vec3s StandardActorHomePositions[] = {
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
// Note: check D_8028358C_2 in battle/popup_messages.c (file split might be incorrect)
s32* D_8028358C[] = {
    (s32*)-1, (s32*)-1, (s32*)-1, (s32*)-1, (s32*)-1, (s32*)-1, (s32*)-1, (s32*)-1,
    (s32*)D_8028358C, (s32*)D_8028358C, (s32*)D_8028358C, (s32*)D_8028358C, (s32*)D_8028358C,
#if !VERSION_JP
    (s32*)D_8028358C, (s32*)D_8028358C, (s32*)D_8028358C, 0
#endif
};
