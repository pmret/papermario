#include "../area.h"
#include "sprite/npc/Chan.h"

#define NAMESPACE A(chan)

extern s32 N(DefaultAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn_Ceiling);
extern EvtScript N(EVS_TakeTurn_Ground);
extern EvtScript N(EVS_HandleEvent_Ceiling);
extern EvtScript N(EVS_HandleEvent_Ground);
extern EvtScript N(EVS_HandleEvent_Initial);
extern EvtScript N(EVS_HandlePhase);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

enum N(ActorVars) {
    AVAR_IsCeiling      = 0, // leftover from buzzy beetle code
    AVAR_BattleCry      = 0,
    AVAR_FlipCount      = 1,
    AVAR_Respect        = 2, // 'Hmmm... You have some skills.'
    AVAR_ToppleState    = 8,
    AVAL_State_Ceiling  = 0,
    AVAL_State_Upright  = 1,
    AVAL_State_Toppled  = 2,
    AVAR_ToppleTurns    = 9,
};

enum N(ActorParams) {
    DMG_SHELL_TOSS      = 2,
    DMG_CEILING_DROP    = 3,
};

s32 N(UprightDefenseTable)[] = {
    ELEMENT_NORMAL,   2,
    ELEMENT_FIRE,    99,
    ELEMENT_BLAST,   99,
    ELEMENT_END,
};

s32 N(ToppledDefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              30,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              50,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           50,
    STATUS_KEY_SHRINK,             50,
    STATUS_KEY_STOP,              100,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 16 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(UprightDefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 1, 7 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_UPSIDE_DOWN,
    .type = ACTOR_TYPE_CHAN,
    .level = ACTOR_LEVEL_CHAN,
    .maxHP = 15,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 100,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 0,
    .size = { 22, 18 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(UprightAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Chan_Idle,
    STATUS_KEY_STONE,     ANIM_Chan_Still,
    STATUS_KEY_SLEEP,     ANIM_Chan_Sleep,
    STATUS_KEY_POISON,    ANIM_Chan_Idle,
    STATUS_KEY_STOP,      ANIM_Chan_Still,
    STATUS_KEY_STATIC,    ANIM_Chan_Idle,
    STATUS_KEY_PARALYZE,  ANIM_Chan_Still,
    STATUS_KEY_DIZZY,     ANIM_Chan_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Chan_Dizzy,
    STATUS_END,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Chan_Idle,
    STATUS_KEY_STONE,     ANIM_Chan_Still,
    STATUS_KEY_SLEEP,     ANIM_Chan_Sleep,
    STATUS_KEY_POISON,    ANIM_Chan_Idle,
    STATUS_KEY_STOP,      ANIM_Chan_Still,
    STATUS_KEY_STATIC,    ANIM_Chan_Idle,
    STATUS_KEY_PARALYZE,  ANIM_Chan_Still,
    STATUS_KEY_DIZZY,     ANIM_Chan_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Chan_Dizzy,
    STATUS_END,
};

s32 N(ToppledAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Chan_Toppled,
    STATUS_KEY_STONE,     ANIM_Chan_ToppledStill,
    STATUS_KEY_SLEEP,     ANIM_Chan_ToppledSleep,
    STATUS_KEY_POISON,    ANIM_Chan_Toppled,
    STATUS_KEY_STOP,      ANIM_Chan_ToppledStill,
    STATUS_KEY_STATIC,    ANIM_Chan_Toppled,
    STATUS_KEY_DIZZY,     ANIM_Chan_ToppledDizzy,
    STATUS_KEY_FEAR,      ANIM_Chan_ToppledDizzy,
    STATUS_END,
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

// seems to be copied directly from buzzy_beetle.c
EvtScript N(EVS_SetInitialState) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsCeiling, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleState, AVAL_State_Ceiling)
        EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 0, 10, 0)
        EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn_Ceiling)))
        EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent_Ceiling)))
        EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FLIPABLE, FALSE)
    EVT_ELSE
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleState, AVAL_State_Upright)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 16)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -9)
        EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn_Ground)))
        EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent_Ground)))
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(UprightAnims)))
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_UPSIDE_DOWN, FALSE)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FLIPABLE, TRUE)
    EVT_END_IF
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FallFromCeiling) = {
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleState, AVAL_State_Toppled)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 16)
    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -9)
    EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn_Ground)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent_Ground)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 1)
    EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledDefenseTable)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledAnims)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_UPSIDE_DOWN, FALSE)
    EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, FALSE)
    EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FLIPABLE, TRUE)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ToppledHurt)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 24)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_FALL_QUICK, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(GetIndexFromPos, ACTOR_SELF, LVarA)
    EVT_MOD(LVarA, 4)
    EVT_CALL(SetGoalToIndex, ACTOR_SELF, LVarA)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(SetHomePos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_SET(LVarD, LVarA)
    EVT_SET(LVarE, LVarB)
    EVT_SET(LVarF, LVarC)
    EVT_SUB(LVarD, LVar0)
    EVT_SUB(LVarE, LVar1)
    EVT_SUB(LVarF, LVar2)
    EVT_DIV(LVarD, 2)
    EVT_DIV(LVarE, 2)
    EVT_DIV(LVarF, 2)
    EVT_ADD(LVar0, LVarD)
    EVT_ADD(LVar1, LVarE)
    EVT_ADD(LVar2, LVarF)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Toppled)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent_Ceiling) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(EVS_FallFromCeiling))
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(EVS_FallFromCeiling))
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_SET_CONST(LVar2, ANIM_Chan_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(N(EVS_FallFromCeiling))
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_SET_CONST(LVar2, ANIM_Chan_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Run)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_EnterShell)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_EnterShell)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_WAIT(2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_STOP)
                EVT_EXEC_WAIT(N(EVS_FallFromCeiling))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            // nothing
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, TRUE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Run)
            EVT_SET_CONST(LVar2, ANIM_Chan_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

// switch the anim on LVar1 if toppled
EvtScript N(EVS_CheckToppleAnim) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar3)
    EVT_IF_EQ(LVar3, AVAL_State_Toppled)
        EVT_SET(LVar1, LVar2)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(FlipPosOffsets)[] = { 7, 13, 17, 21, 23, 24, 23, 21, 17, 13, 7, 0,  4,  7,  6,  4,  0,  2,  0 };

EvtScript N(EVS_HandleEvent_Ground) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_SET_CONST(LVar2, ANIM_Chan_ToppledHurt)
            EVT_EXEC_WAIT(N(EVS_CheckToppleAnim))
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            EVT_IF_NE(LVar0, AVAL_State_Toppled)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
                EVT_SET_CONST(LVar2, ANIM_Chan_Hurt)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Chan_ToppledBurnHurt)
                EVT_SET_CONST(LVar2, ANIM_Chan_ToppledBurnStill)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            EVT_IF_NE(LVar0, AVAL_State_Toppled)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
                EVT_SET_CONST(LVar2, ANIM_Chan_Hurt)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Chan_ToppledBurnHurt)
                EVT_SET_CONST(LVar2, ANIM_Chan_ToppledBurnStill)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Chan_ToppledBurnStill)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_SET_CONST(LVar2, ANIM_Chan_ToppledHurt)
            EVT_EXEC_WAIT(N(EVS_CheckToppleAnim))
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleState, AVAL_State_Toppled)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 16)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -9)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 1)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledDefenseTable)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledAnims)))
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Hurt)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
            EVT_THREAD
                EVT_WAIT(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -45)
                EVT_WAIT(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -90)
                EVT_WAIT(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -135)
                EVT_WAIT(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -180)
                EVT_WAIT(1)
            EVT_END_THREAD
            EVT_USE_BUF(EVT_PTR(N(FlipPosOffsets)))
            EVT_LOOP(19)
                EVT_BUF_READ1(LVar0)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ToppledHurt)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Run)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            EVT_IF_EQ(LVar0, AVAL_State_Upright)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Chan_EnterShell)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ExitShell)
                EVT_WAIT(8)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Chan_Toppled)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            EVT_IF_EQ(LVar0, AVAL_State_Upright)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Chan_EnterShell)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ExitShell)
                EVT_WAIT(8)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Chan_Toppled)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_WAIT(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_ADD(LVar1, 9)
            EVT_ELSE
                EVT_ADD(LVar1, 24)
            EVT_END_IF
            EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 20, 0)
            EVT_WAIT(20)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_SET_CONST(LVar2, ANIM_Chan_ToppledHurt)
            EVT_EXEC_WAIT(N(EVS_CheckToppleAnim))
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_SET_CONST(LVar2, ANIM_Chan_ToppledHurt)
            EVT_EXEC_WAIT(N(EVS_CheckToppleAnim))
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_SET_CONST(LVar2, ANIM_Chan_ToppledHurt)
            EVT_EXEC_WAIT(N(EVS_CheckToppleAnim))
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_SET_CONST(LVar2, ANIM_Chan_ToppledHurt)
            EVT_EXEC_WAIT(N(EVS_CheckToppleAnim))
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            EVT_IF_EQ(LVar0, AVAL_State_Upright)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Chan_Idle)
                EVT_EXEC_WAIT(EVS_Enemy_Recover)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            EVT_IF_EQ(LVar0, AVAL_State_Upright)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Chan_Run)
                EVT_SET_CONST(LVar2, ANIM_Chan_Hurt)
                EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Chan_Toppled)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            EVT_IF_EQ(LVar0, AVAL_State_Upright)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Chan_Run)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Chan_Toppled)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            EVT_IF_EQ(LVar0, AVAL_State_Upright)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Chan_Hurt)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Chan_ToppledHurt)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            EVT_IF_EQ(LVar0, AVAL_State_Upright)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Chan_EnterShell)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ExitShell)
                EVT_WAIT(8)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Chan_Toppled)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_END_IF
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn_Ceiling) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleState, AVAL_State_Upright)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 16)
    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -9)
    EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn_Ground)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent_Ground)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(UprightAnims)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_UPSIDE_DOWN, FALSE)
    EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FLIPABLE, TRUE)
    EVT_CALL(GetIndexFromPos, ACTOR_SELF, LVar0)
    EVT_MOD(LVar0, 4)
    EVT_CALL(SetGoalToIndex, ACTOR_SELF, LVar0)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar4, LVar2)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Still)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Run)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar4, LVar2)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Still)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_FALL_QUICK, 0)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_05)
        EVT_CALL(SetBattleCamZoom, 430)
        EVT_CALL(SetBattleCamOffsetZ, 20)
        EVT_CALL(MoveBattleCamOver, 10)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, DMG_CEILING_DROP, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(SetPartYaw, ACTOR_SELF, PRT_MAIN, 180)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ToppledHurt)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar1, 24)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_WAIT(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Still)
            EVT_END_THREAD
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT(8)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Run)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ToppledHurt)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 24)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, LVar4)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, DMG_CEILING_DROP, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 30)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_WAIT(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Still)
            EVT_END_THREAD
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT(8)
            EVT_CALL(YieldTurn)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Run)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Idle)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_LABEL(10)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn_Ground) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
    EVT_IF_EQ(LVar0, AVAL_State_Toppled)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
        EVT_SUB(LVar0, 1)
        EVT_IF_GT(LVar0, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_WAIT(30)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_ELSE
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_WAIT(20)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Toppled)
            EVT_SET_CONST(LVar2, ANIM_Chan_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_FlipBackUp)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleState, AVAL_State_Upright)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 16)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -9)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(UprightDefenseTable)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(UprightAnims)))
            EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, FALSE)
        EVT_END_IF
        EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_EnterShell)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ShellStill)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        EVT_WAIT(10)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        EVT_WAIT(5)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_SPIN)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ShellSpin)
    EVT_WAIT(20)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_TOSS)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_THREAD
                EVT_LOOP(0)
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_ADD(LVar0, 30)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
                    EVT_IF_GT(LVar0, LVar3)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_01)
                EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_END_IF
                EVT_WAIT(15)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -150, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(14.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 200)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ExitShell)
            EVT_WAIT(10)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(14.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, DMG_SHELL_TOSS, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Idle)
            EVT_WAIT(8)
            EVT_CALL(YieldTurn)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Chan_Run)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Idle)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Init) = {
    EVT_EXEC_WAIT(N(EVS_SetInitialState))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent_Initial)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_BattleCry, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FlipCount, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Respect, FALSE)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_NO_GAME_OVER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_BattleCry, LVar0)
            EVT_IF_EQ(LVar0, FALSE)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, MSG_MAC_Gate_001F, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Run, ANIM_Chan_Walk)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_BattleCry, TRUE)
            EVT_END_IF
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            EVT_IF_EQ(LVar0, AVAL_State_Toppled)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAGS_DOJO | STATUS_FLAG_POISON | STATUS_KEY_SHRINK) // @bug STATUS_KEY_SHRINK used instead of STATUS_FLAG_SHRINK
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET_CONST(LVarA, ANIM_Chan_Run)
            EVT_SET_CONST(LVarB, ANIM_Chan_Walk)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            EVT_IF_EQ(LVar0, AVAL_State_Toppled)
                EVT_SET_CONST(LVarA, ANIM_Chan_ToppledHurt)
                EVT_SET_CONST(LVarB, ANIM_Chan_Toppled)
            EVT_END_IF
            // if less than half HP, tell the player they have some skills
            EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
            EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
            EVT_DIV(LVar1, 2)
            EVT_IF_LE(LVar0, LVar1)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Respect, LVar0)
                EVT_IF_EQ(LVar0, FALSE)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    EVT_CALL(MoveBattleCamOver, 10)
                    EVT_CALL(ActorSpeak, MSG_MAC_Gate_0021, ACTOR_SELF, PRT_MAIN, LVarA, LVarB)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Respect, TRUE)
                    EVT_BREAK_SWITCH
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(GetPlayerHP, LVar0)
            EVT_IF_LE(LVar0, 5)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, MSG_MAC_Gate_0022, ACTOR_SELF, PRT_MAIN, LVarA, LVarB)
                EVT_BREAK_SWITCH
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent_Initial) = {
    EVT_EXEC_WAIT(N(EVS_HandleEvent_Ground))
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_NOT_FLAG(LVar0, BS_FLAGS1_TRIGGER_EVENTS)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAGS_DOJO | STATUS_FLAG_POISON | STATUS_FLAG_SHRINK)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET(LFlag0, FALSE)
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(BTL_MENU_TYPE_SMASH)
                EVT_CASE_OR_EQ(BTL_MENU_TYPE_JUMP)
                    EVT_SET(LFlag0, TRUE)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            EVT_WAIT(30)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            EVT_IF_EQ(LVar0, AVAL_State_Toppled)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_FlipCount, LVar0)
                EVT_ADD(LVar0, 1)
                EVT_SWITCH(LVar0)
                    EVT_CASE_EQ(1)
                        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                        EVT_CALL(MoveBattleCamOver, 10)
                        EVT_CALL(ActorSpeak, MSG_MAC_Gate_0020, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ToppledHurt, ANIM_Chan_Toppled)
                    EVT_CASE_EQ(2)
                    EVT_CASE_EQ(3)
                        EVT_SET(LVar0, 0)
                EVT_END_SWITCH
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FlipCount, LVar0)
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
