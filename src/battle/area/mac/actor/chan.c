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
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(GetActorVar, ACTOR_SELF, AVAR_IsCeiling, LVar0)
    IfEq(LVar0, true)
        Call(SetActorVar, ACTOR_SELF, AVAR_ToppleState, AVAL_State_Ceiling)
        Call(N(SetAbsoluteStatusOffsets), -10, 0, 10, 0)
        Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn_Ceiling)))
        Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent_Ceiling)))
        Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FLIPABLE, false)
    Else
        Call(SetActorVar, ACTOR_SELF, AVAR_ToppleState, AVAL_State_Upright)
        Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 16)
        Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -9)
        Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn_Ground)))
        Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent_Ground)))
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(UprightAnims)))
        Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_UPSIDE_DOWN, false)
        Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FLIPABLE, true)
    EndIf
    Call(HPBarToHome, ACTOR_SELF)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
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
    Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledDefenseTable)))
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledAnims)))
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_UPSIDE_DOWN, false)
    Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, false)
    Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FLIPABLE, true)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, true)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ToppledHurt)
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar1, 24)
    Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, 0)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_FALL_QUICK, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
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
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Toppled)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
    Call(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
    Call(HPBarToHome, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_HandleEvent_Ceiling) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_FallFromCeiling))
        CaseEq(EVENT_FLIP_TRIGGER)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_FallFromCeiling))
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            SetConst(LVar2, ANIM_Chan_Hurt)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(N(EVS_FallFromCeiling))
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            SetConst(LVar2, ANIM_Chan_Hurt)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Run)
            ExecWait(EVS_Enemy_ReturnHome)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_ZERO_DAMAGE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_EnterShell)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_EnterShell)
            ExecWait(EVS_Enemy_NoDamageHit)
            Wait(2)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAG_STOP)
                ExecWait(N(EVS_FallFromCeiling))
            EndIf
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            // nothing
        CaseEq(EVENT_SCARE_AWAY)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, true)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Run)
            SetConst(LVar2, ANIM_Chan_Hurt)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
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
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            SetConst(LVar2, ANIM_Chan_ToppledHurt)
            ExecWait(N(EVS_CheckToppleAnim))
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfNe(LVar0, AVAL_State_Toppled)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Chan_Hurt)
                SetConst(LVar2, ANIM_Chan_Hurt)
                ExecWait(EVS_Enemy_BurnHit)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Chan_ToppledBurnHurt)
                SetConst(LVar2, ANIM_Chan_ToppledBurnStill)
                ExecWait(EVS_Enemy_BurnHit)
            EndIf
        CaseEq(EVENT_BURN_DEATH)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfNe(LVar0, AVAL_State_Toppled)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Chan_Hurt)
                SetConst(LVar2, ANIM_Chan_Hurt)
                ExecWait(EVS_Enemy_BurnHit)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Chan_Hurt)
                ExecWait(EVS_Enemy_Death)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Chan_ToppledBurnHurt)
                SetConst(LVar2, ANIM_Chan_ToppledBurnStill)
                ExecWait(EVS_Enemy_BurnHit)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Chan_ToppledBurnStill)
                ExecWait(EVS_Enemy_Death)
            EndIf
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            SetConst(LVar2, ANIM_Chan_ToppledHurt)
            ExecWait(N(EVS_CheckToppleAnim))
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_FLIP_TRIGGER)
            Call(SetActorVar, ACTOR_SELF, AVAR_ToppleState, AVAL_State_Toppled)
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 16)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -9)
            Call(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 1)
            Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledDefenseTable)))
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledAnims)))
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, true)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Hurt)
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
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ToppledHurt)
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Run)
            ExecWait(EVS_Enemy_ReturnHome)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_ZERO_DAMAGE)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfEq(LVar0, AVAL_State_Upright)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Chan_EnterShell)
                ExecWait(EVS_Enemy_NoDamageHit)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ExitShell)
                Wait(8)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Chan_Toppled)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
        CaseEq(EVENT_IMMUNE)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfEq(LVar0, AVAL_State_Upright)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Chan_EnterShell)
                ExecWait(EVS_Enemy_NoDamageHit)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ExitShell)
                Wait(8)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Chan_Toppled)
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
            SetConst(LVar1, ANIM_Chan_Hurt)
            SetConst(LVar2, ANIM_Chan_ToppledHurt)
            ExecWait(N(EVS_CheckToppleAnim))
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            SetConst(LVar2, ANIM_Chan_ToppledHurt)
            ExecWait(N(EVS_CheckToppleAnim))
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            SetConst(LVar2, ANIM_Chan_ToppledHurt)
            ExecWait(N(EVS_CheckToppleAnim))
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Hurt)
            SetConst(LVar2, ANIM_Chan_ToppledHurt)
            ExecWait(N(EVS_CheckToppleAnim))
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfEq(LVar0, AVAL_State_Upright)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Chan_Idle)
                ExecWait(EVS_Enemy_Recover)
            EndIf
        CaseEq(EVENT_SCARE_AWAY)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfEq(LVar0, AVAL_State_Upright)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Chan_Run)
                SetConst(LVar2, ANIM_Chan_Hurt)
                ExecWait(EVS_Enemy_ScareAway)
                Return
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Chan_Toppled)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfEq(LVar0, AVAL_State_Upright)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Chan_Run)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Chan_Toppled)
            EndIf
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfEq(LVar0, AVAL_State_Upright)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Chan_Hurt)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Chan_ToppledHurt)
            EndIf
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseEq(EVENT_AIR_LIFT_FAILED)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfEq(LVar0, AVAL_State_Upright)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Chan_EnterShell)
                ExecWait(EVS_Enemy_NoDamageHit)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ExitShell)
                Wait(8)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Chan_Toppled)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn_Ceiling) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetActorVar, ACTOR_SELF, AVAR_ToppleState, AVAL_State_Upright)
    Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 16)
    Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -9)
    Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn_Ground)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent_Ground)))
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(UprightAnims)))
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_UPSIDE_DOWN, false)
    Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FLIPABLE, true)
    Call(GetIndexFromPos, ACTOR_SELF, LVar0)
    Mod(LVar0, 4)
    Call(SetGoalToIndex, ACTOR_SELF, LVar0)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(HPBarToHome, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar4, LVar2)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Still)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Run)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar4, LVar2)
        Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
        Call(RunToGoal, ACTOR_SELF, 0, false)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Still)
        Wait(8)
    EndIf
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_FALL_QUICK, 0)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(UseBattleCamPreset, BTL_CAM_ACTOR_TARGET_MIDPOINT)
        Call(SetBattleCamDist, 430)
        Call(SetBattleCamOffsetY, 20)
        Call(MoveBattleCamOver, 10)
        Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    EndIf
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, DMG_CEILING_DROP, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(SetPartYaw, ACTOR_SELF, PRT_MAIN, 180)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ToppledHurt)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar1, 24)
            Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(ResetAllActorSounds, ACTOR_SELF)
            Add(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
            Thread
                Wait(5)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Still)
            EndThread
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Wait(8)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Run)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Idle)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ToppledHurt)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar1, 24)
    Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, LVar4)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
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
            Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
            Thread
                Wait(5)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Still)
            EndThread
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Wait(8)
            Call(YieldTurn)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Run)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Idle)
        EndCaseGroup
    EndSwitch
    Label(10)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn_Ground) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
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
            SetConst(LVar1, ANIM_Chan_Toppled)
            SetConst(LVar2, ANIM_Chan_Idle)
            ExecWait(EVS_Enemy_FlipBackUp)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetActorVar, ACTOR_SELF, AVAR_ToppleState, AVAL_State_Upright)
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 16)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -9)
            Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(UprightDefenseTable)))
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(UprightAnims)))
            Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, false)
        EndIf
        Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
        Call(UseIdleAnimation, ACTOR_SELF, true)
        Return
    EndIf
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_EnterShell)
    Wait(10)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ShellStill)
    Thread
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        Wait(10)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        Wait(5)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
    EndThread
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_SPIN)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ShellSpin)
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
                Call(UseBattleCamPreset, BTL_CAM_INTERRUPT)
                IfEq(LVarA, HIT_RESULT_LUCKY)
                    Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EndIf
                Wait(15)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EndThread
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -150, 0, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(14.0))
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Wait(15)
            Call(YieldTurn)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 200)
            Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(10.0))
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Wait(10)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ExitShell)
            Wait(10)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(14.0))
    Call(RunToGoal, ACTOR_SELF, 0, false)
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
            Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
            Add(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, false, true, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Idle)
            Wait(8)
            Call(YieldTurn)
            Call(ResetAllActorSounds, ACTOR_SELF)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Chan_Run)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Idle)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Init) = {
    ExecWait(N(EVS_SetInitialState))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent_Initial)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_BattleCry, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_FlipCount, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Respect, false)
    Call(SetBattleFlagBits, BS_FLAGS1_NO_GAME_OVER, true)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_BattleCry, LVar0)
            IfEq(LVar0, false)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Call(MoveBattleCamOver, 10)
                Call(ActorSpeak, MSG_MAC_Gate_001F, ACTOR_SELF, PRT_MAIN, ANIM_Chan_Run, ANIM_Chan_Walk)
                Call(SetActorVar, ACTOR_SELF, AVAR_BattleCry, true)
            EndIf
        CaseEq(PHASE_ENEMY_BEGIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfEq(LVar0, AVAL_State_Toppled)
                BreakSwitch
            EndIf
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAGS_DOJO | STATUS_FLAG_POISON | STATUS_KEY_SHRINK) /// @bug STATUS_KEY_SHRINK used instead of STATUS_FLAG_SHRINK
                BreakSwitch
            EndIf
            SetConst(LVarA, ANIM_Chan_Run)
            SetConst(LVarB, ANIM_Chan_Walk)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfEq(LVar0, AVAL_State_Toppled)
                SetConst(LVarA, ANIM_Chan_ToppledHurt)
                SetConst(LVarB, ANIM_Chan_Toppled)
            EndIf
            // if less than half HP, tell the player they have some skills
            Call(GetActorHP, ACTOR_SELF, LVar0)
            Call(GetEnemyMaxHP, ACTOR_SELF, LVar1)
            Div(LVar1, 2)
            IfLe(LVar0, LVar1)
                Call(GetActorVar, ACTOR_SELF, AVAR_Respect, LVar0)
                IfEq(LVar0, false)
                    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    Call(MoveBattleCamOver, 10)
                    Call(ActorSpeak, MSG_MAC_Gate_0021, ACTOR_SELF, PRT_MAIN, LVarA, LVarB)
                    Call(SetActorVar, ACTOR_SELF, AVAR_Respect, true)
                    BreakSwitch
                EndIf
            EndIf
            Call(GetPlayerHP, LVar0)
            IfLe(LVar0, 5)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Call(MoveBattleCamOver, 10)
                Call(ActorSpeak, MSG_MAC_Gate_0022, ACTOR_SELF, PRT_MAIN, LVarA, LVarB)
                BreakSwitch
            EndIf
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_HandleEvent_Initial) = {
    ExecWait(N(EVS_HandleEvent_Ground))
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_FLIP_TRIGGER)
            Call(GetBattleFlags, LVar0)
            IfNotFlag(LVar0, BS_FLAGS1_TRIGGER_EVENTS)
                BreakSwitch
            EndIf
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAGS_DOJO | STATUS_FLAG_POISON | STATUS_FLAG_SHRINK)
                BreakSwitch
            EndIf
            Set(LFlag0, false)
            Call(GetMenuSelection, LVar0, LVar1, LVar2)
            Switch(LVar0)
                CaseOrEq(BTL_MENU_TYPE_SMASH)
                CaseOrEq(BTL_MENU_TYPE_JUMP)
                    Set(LFlag0, true)
                EndCaseGroup
            EndSwitch
            IfEq(LFlag0, false)
                BreakSwitch
            EndIf
            Call(UseIdleAnimation, ACTOR_SELF, false)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            Wait(30)
            Call(GetActorVar, ACTOR_SELF, AVAR_ToppleState, LVar0)
            IfEq(LVar0, AVAL_State_Toppled)
                Call(GetActorVar, ACTOR_SELF, AVAR_FlipCount, LVar0)
                Add(LVar0, 1)
                Switch(LVar0)
                    CaseEq(1)
                        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                        Call(MoveBattleCamOver, 10)
                        Call(ActorSpeak, MSG_MAC_Gate_0020, ACTOR_SELF, PRT_MAIN, ANIM_Chan_ToppledHurt, ANIM_Chan_Toppled)
                    CaseEq(2)
                    CaseEq(3)
                        Set(LVar0, 0)
                EndSwitch
                Call(SetActorVar, ACTOR_SELF, AVAR_FlipCount, LVar0)
            EndIf
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
    EndSwitch
    Return
    End
};
