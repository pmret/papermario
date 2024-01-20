#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BuzzyBeetle.h"

#define NAMESPACE A(buzzy_beetle)

extern s32 N(CeilingAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn_Ceiling);
extern EvtScript N(EVS_TakeTurn_Ground);
extern EvtScript N(EVS_HandleEvent_Ceiling);
extern EvtScript N(EVS_HandleEvent_Ground);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

enum N(ActorVars) {
    AVAR_IsCeiling      = 0,
    AVAR_ToppleState    = 8,
    AVAL_State_Ceiling  = 0,
    AVAL_State_Ground   = 1,
    AVAL_State_Toppled  = 2,
    AVAR_ToppleTurns    = 9,
};

enum N(ActorParams) {
    DMG_SHELL_TOSS      = 2,
    DMG_CEILING_DROP    = 3,
};

s32 N(UprightDefense)[] = {
    ELEMENT_NORMAL,   2,
    ELEMENT_FIRE,    99,
    ELEMENT_BLAST,   99,
    ELEMENT_END,
};

s32 N(ToppledDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              90,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             90,
    STATUS_KEY_STOP,               90,
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
        .idleAnimations = N(CeilingAnims),
        .defenseTable = N(UprightDefense),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 1, 7 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_UPSIDE_DOWN,
    .type = ACTOR_TYPE_BUZZY_BEETLE,
    .level = ACTOR_LEVEL_BUZZY_BEETLE,
    .maxHP = 3,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 60,
    .airLiftChance = 75,
    .hurricaneChance = 75,
    .spookChance = 75,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 22, 18 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -8, 16 },
    .statusTextOffset = { 8, 13 },
};

s32 N(GroundAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BuzzyBeetle_Anim01,
    STATUS_KEY_STONE,     ANIM_BuzzyBeetle_Anim00,
    STATUS_KEY_SLEEP,     ANIM_BuzzyBeetle_Anim09,
    STATUS_KEY_POISON,    ANIM_BuzzyBeetle_Anim01,
    STATUS_KEY_STOP,      ANIM_BuzzyBeetle_Anim00,
    STATUS_KEY_STATIC,    ANIM_BuzzyBeetle_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_BuzzyBeetle_Anim00,
    STATUS_KEY_DIZZY,     ANIM_BuzzyBeetle_Anim0A,
    STATUS_KEY_FEAR,      ANIM_BuzzyBeetle_Anim0A,
    STATUS_END,
};

s32 N(CeilingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BuzzyBeetle_Anim0F,
    STATUS_KEY_STONE,     ANIM_BuzzyBeetle_Anim0E,
    STATUS_KEY_SLEEP,     ANIM_BuzzyBeetle_Anim14,
    STATUS_KEY_POISON,    ANIM_BuzzyBeetle_Anim0F,
    STATUS_KEY_STOP,      ANIM_BuzzyBeetle_Anim0E,
    STATUS_KEY_STATIC,    ANIM_BuzzyBeetle_Anim0F,
    STATUS_KEY_PARALYZE,  ANIM_BuzzyBeetle_Anim0E,
    STATUS_KEY_DIZZY,     ANIM_BuzzyBeetle_Anim15,
    STATUS_KEY_FEAR,      ANIM_BuzzyBeetle_Anim15,
    STATUS_END,
};

s32 N(ToppledAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BuzzyBeetle_Anim02,
    STATUS_KEY_STONE,     ANIM_BuzzyBeetle_Anim1A,
    STATUS_KEY_SLEEP,     ANIM_BuzzyBeetle_Anim1B,
    STATUS_KEY_POISON,    ANIM_BuzzyBeetle_Anim02,
    STATUS_KEY_STOP,      ANIM_BuzzyBeetle_Anim1A,
    STATUS_KEY_STATIC,    ANIM_BuzzyBeetle_Anim02,
    STATUS_KEY_DIZZY,     ANIM_BuzzyBeetle_Anim1C,
    STATUS_KEY_FEAR,      ANIM_BuzzyBeetle_Anim1C,
    STATUS_END,
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(EVS_Init) = {
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(GetActorVar, ACTOR_SELF, AVAR_IsCeiling, LVar0)
    IfEq(LVar0, TRUE)
        Call(SetActorVar, ACTOR_SELF, AVAR_ToppleState, AVAL_State_Ceiling)
        Call(N(SetAbsoluteStatusOffsets), -10, 0, 10, 0)
        Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn_Ceiling)))
        Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent_Ceiling)))
        Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FLIPABLE, FALSE)
    Else
        Call(SetActorVar, ACTOR_SELF, AVAR_ToppleState, AVAL_State_Ground)
        Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 16)
        Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -9)
        Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn_Ground)))
        Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent_Ground)))
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(GroundAnims)))
        Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_UPSIDE_DOWN, FALSE)
        Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FLIPABLE, TRUE)
    EndIf
    Call(HPBarToHome, ACTOR_SELF)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_FallFromCeiling) = {
    Call(HideHealthBar, ACTOR_SELF)
    Call(SetActorVar, ACTOR_SELF, AVAR_ToppleState, AVAL_State_Toppled)
    Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 16)
    Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -9)
    Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn_Ground)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent_Ground)))
    Call(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 1)
    Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledDefense)))
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledAnims)))
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_UPSIDE_DOWN, FALSE)
    Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, FALSE)
    Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FLIPABLE, TRUE)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim08)
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar1, 24)
    Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, 0)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_FALL_QUICK, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    Call(GetIndexFromPos, ACTOR_SELF, LVarA)
    Mod(LVarA, 4)
    Call(SetGoalToIndex, ACTOR_SELF, LVarA)
    Call(GetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Call(SetHomePos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Set(LVarD, LVarA)
    Set(LVarE, LVarB)
    Set(LVarF, LVarC)
    Sub(LVarD, LVar0)
    Sub(LVarE, LVar1)
    Sub(LVarF, LVar2)
    Div(LVarD, 2)
    Div(LVarE, 2)
    Div(LVarF, 2)
    Add(LVar0, LVarD)
    Add(LVar1, LVarE)
    Add(LVar2, LVarF)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim02)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    Call(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    Call(HPBarToHome, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_HandleEvent_Ceiling) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim13)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim13)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_FallFromCeiling))
        CaseEq(EVENT_FLIP_TRIGGER)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim13)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_FallFromCeiling))
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim18)
            SetConst(LVar2, ANIM_BuzzyBeetle_Anim18)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(N(EVS_FallFromCeiling))
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim18)
            SetConst(LVar2, ANIM_BuzzyBeetle_Anim18)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim18)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim13)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim07)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim04)
            ExecWait(EVS_Enemy_ReturnHome)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim13)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim07)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_ZERO_DAMAGE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim16)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim16)
            ExecWait(EVS_Enemy_NoDamageHit)
            Wait(2)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAG_STOP)
                ExecWait(N(EVS_FallFromCeiling))
            EndIf
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim13)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim13)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            // nothing
        CaseEq(EVENT_SCARE_AWAY)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, TRUE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim11)
            SetConst(LVar2, ANIM_BuzzyBeetle_Anim13)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

// switch the anim on LVar1 if toppled
EvtScript N(EVS_CheckToppleAnim) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar3)
    IfEq(LVar3, AVAL_State_Toppled)
        Set(LVar1, LVar2)
    EndIf
    Return
    End
};

s32 N(FlipPosOffsets)[] = { 7, 13, 17, 21, 23, 24, 23, 21, 17, 13, 7, 0,  4,  7,  6,  4,  0,  2,  0 };

EvtScript N(EVS_HandleEvent_Ground) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim07)
            SetConst(LVar2, ANIM_BuzzyBeetle_Anim19)
            ExecWait(N(EVS_CheckToppleAnim))
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfNe(LVar0, AVAL_State_Toppled)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BuzzyBeetle_Anim0B)
                SetConst(LVar2, ANIM_BuzzyBeetle_Anim0B)
                ExecWait(EVS_Enemy_BurnHit)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BuzzyBeetle_Anim1D)
                SetConst(LVar2, ANIM_BuzzyBeetle_Anim1D)
                ExecWait(EVS_Enemy_BurnHit)
            EndIf
        CaseEq(EVENT_BURN_DEATH)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfNe(LVar0, AVAL_State_Toppled)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BuzzyBeetle_Anim0B)
                SetConst(LVar2, ANIM_BuzzyBeetle_Anim0B)
                ExecWait(EVS_Enemy_BurnHit)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BuzzyBeetle_Anim0B)
                ExecWait(EVS_Enemy_Death)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BuzzyBeetle_Anim1D)
                SetConst(LVar2, ANIM_BuzzyBeetle_Anim1D)
                ExecWait(EVS_Enemy_BurnHit)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BuzzyBeetle_Anim1D)
                ExecWait(EVS_Enemy_Death)
            EndIf
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim07)
            SetConst(LVar2, ANIM_BuzzyBeetle_Anim19)
            ExecWait(N(EVS_CheckToppleAnim))
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_FLIP_TRIGGER)
            Call(SetActorVar, ACTOR_SELF, AVAR_ToppleState, AVAL_State_Toppled)
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 16)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -9)
            Call(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 1)
            Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledDefense)))
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledAnims)))
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim07)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
            Thread
                Wait(1)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                Wait(1)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, -45)
                Wait(1)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, -90)
                Wait(1)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, -135)
                Wait(1)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, -180)
                Wait(1)
            EndThread
            UseBuf(Ref(N(FlipPosOffsets)))
            Loop(19)
                BufRead1(LVar0)
                Call(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                Wait(1)
            EndLoop
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim19)
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim07)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim07)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim04)
            ExecWait(EVS_Enemy_ReturnHome)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim07)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim07)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_ZERO_DAMAGE)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfEq(LVar0, AVAL_State_Ground)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BuzzyBeetle_Anim0C)
                ExecWait(EVS_Enemy_NoDamageHit)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim17)
                Wait(8)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BuzzyBeetle_Anim02)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
        CaseEq(EVENT_IMMUNE)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfEq(LVar0, AVAL_State_Ground)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BuzzyBeetle_Anim0C)
                ExecWait(EVS_Enemy_NoDamageHit)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim0D)
                Wait(8)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BuzzyBeetle_Anim02)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
        CaseEq(EVENT_SPIKE_TAUNT)
            Wait(10)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(GetStatusFlags, ACTOR_SELF, LVar3)
            IfFlag(LVar3, STATUS_FLAG_SHRINK)
                Add(LVar1, 9)
            Else
                Add(LVar1, 24)
            EndIf
            PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 20, 0)
            Wait(20)
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim07)
            SetConst(LVar2, ANIM_BuzzyBeetle_Anim19)
            ExecWait(N(EVS_CheckToppleAnim))
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim07)
            SetConst(LVar2, ANIM_BuzzyBeetle_Anim19)
            ExecWait(N(EVS_CheckToppleAnim))
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim07)
            SetConst(LVar2, ANIM_BuzzyBeetle_Anim19)
            ExecWait(N(EVS_CheckToppleAnim))
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim07)
            SetConst(LVar2, ANIM_BuzzyBeetle_Anim19)
            ExecWait(N(EVS_CheckToppleAnim))
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfEq(LVar0, AVAL_State_Ground)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BuzzyBeetle_Anim01)
                ExecWait(EVS_Enemy_Recover)
            EndIf
        CaseEq(EVENT_SCARE_AWAY)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfEq(LVar0, AVAL_State_Ground)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BuzzyBeetle_Anim04)
                SetConst(LVar2, ANIM_BuzzyBeetle_Anim07)
                ExecWait(EVS_Enemy_ScareAway)
                Return
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BuzzyBeetle_Anim02)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfEq(LVar0, AVAL_State_Ground)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BuzzyBeetle_Anim04)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BuzzyBeetle_Anim02)
            EndIf
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfEq(LVar0, AVAL_State_Ground)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BuzzyBeetle_Anim07)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BuzzyBeetle_Anim08)
            EndIf
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseEq(EVENT_AIR_LIFT_FAILED)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfEq(LVar0, AVAL_State_Ground)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BuzzyBeetle_Anim0C)
                ExecWait(EVS_Enemy_NoDamageHit)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim0D)
                Wait(8)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BuzzyBeetle_Anim02)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn_Ceiling) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetActorVar, ACTOR_SELF, AVAR_ToppleState, AVAL_State_Ground)
    Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 16)
    Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -9)
    Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn_Ground)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent_Ground)))
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(GroundAnims)))
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_UPSIDE_DOWN, FALSE)
    Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FLIPABLE, TRUE)
    Call(GetIndexFromPos, ACTOR_SELF, LVar0)
    Mod(LVar0, 4)
    Call(SetGoalToIndex, ACTOR_SELF, LVar0)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(HPBarToHome, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar4, LVar2)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim0E)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim11)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar4, LVar2)
        Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
        Call(RunToGoal, ACTOR_SELF, 0, FALSE)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim0E)
        Wait(8)
    EndIf
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_FALL_QUICK, 0)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_05)
        Call(SetBattleCamZoom, 430)
        Call(SetBattleCamOffsetZ, 20)
        Call(MoveBattleCamOver, 10)
        Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EndIf
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, DMG_CEILING_DROP, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(SetPartYaw, ACTOR_SELF, PRT_MAIN, 180)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim08)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar1, 24)
            Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(ResetAllActorSounds, ACTOR_SELF)
            Add(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            Thread
                Wait(5)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim00)
            EndThread
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Wait(8)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim04)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim01)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim08)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar1, 24)
    Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, LVar4)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, DMG_CEILING_DROP, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 30)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            Thread
                Wait(5)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim00)
            EndThread
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Wait(8)
            Call(YieldTurn)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim04)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim01)
        EndCaseGroup
    EndSwitch
    Label(10)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn_Ground) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
    IfEq(LVar0, AVAL_State_Toppled)
        Call(GetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
        Sub(LVar0, 1)
        IfGt(LVar0, 0)
            Call(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Wait(30)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Else
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Wait(20)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim02)
            SetConst(LVar2, ANIM_BuzzyBeetle_Anim01)
            ExecWait(EVS_Enemy_FlipBackUp)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetActorVar, ACTOR_SELF, AVAR_ToppleState, AVAL_State_Ground)
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 16)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -9)
            Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(UprightDefense)))
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(GroundAnims)))
            Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, FALSE)
        EndIf
        Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
        Call(UseIdleAnimation, ACTOR_SELF, TRUE)
        Return
    EndIf
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim0C)
    Wait(10)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim06)
    Thread
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        Wait(10)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        Wait(5)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
    EndThread
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_SPIN)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim05)
    Wait(20)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_TOSS)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Thread
                Loop(0)
                    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    Add(LVar0, 30)
                    Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
                    IfGt(LVar0, LVar3)
                        BreakLoop
                    EndIf
                    Wait(1)
                EndLoop
                Call(UseBattleCamPreset, BTL_CAM_PRESET_01)
                IfEq(LVarA, HIT_RESULT_LUCKY)
                    Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EndIf
                Wait(15)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EndThread
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -150, 0, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(14.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Wait(15)
            Call(YieldTurn)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 200)
            Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(10.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Wait(10)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim0D)
            Wait(10)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(14.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, DMG_SHELL_TOSS, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Add(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim01)
            Wait(8)
            Call(YieldTurn)
            Call(ResetAllActorSounds, ACTOR_SELF)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BuzzyBeetle_Anim04)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BuzzyBeetle_Anim01)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};
