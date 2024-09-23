#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/KoopaTroopa.h"
#include "effects.h"

#define NAMESPACE A(dark_koopa)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);

extern s32 N(KoopaAnims)[];

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_HasWhirlwind           = 1,
    AVAR_State                  = 8,
    AVAL_State_Normal           = 0,
    AVAL_State_Hyper            = 1,
    AVAL_State_ToppledNormal    = 2,
    AVAL_State_ToppledHyper     = 3,
    AVAR_ToppleTurns            = 9,
};

enum N(ActorParams) {
    DMG_SHELL_TOSS  = 3,
};

#define SWEAT_DECOR_IDX         0
#define WHIRLWIND_DECOR_IDX     1

s32 N(UprightDefenseTable)[] = {
    ELEMENT_NORMAL,   2,
    ELEMENT_SMASH,    2,
    ELEMENT_JUMP,     2,
    ELEMENT_WATER,    2,
    ELEMENT_BLAST,    2,
    ELEMENT_END,
};

s32 N(ToppledDefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              80,
    STATUS_KEY_POISON,             60,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,              50,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             80,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 36 },
        .opacity = 255,
        .idleAnimations = N(KoopaAnims),
        .defenseTable = N(UprightDefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -7 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_DARK_KOOPA,
    .level = ACTOR_LEVEL_DARK_KOOPA,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 60,
    .airLiftChance = 85,
    .hurricaneChance = 75,
    .spookChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 2,
    .size = { 28, 36 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 32 },
    .statusTextOffset = { 5, 32 },
};

s32 N(KoopaAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_KoopaTroopa_Dark_Idle,
    STATUS_KEY_STONE,     ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_SLEEP,     ANIM_KoopaTroopa_Dark_Sleep,
    STATUS_KEY_POISON,    ANIM_KoopaTroopa_Dark_Idle,
    STATUS_KEY_STOP,      ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_STATIC,    ANIM_KoopaTroopa_Dark_Idle,
    STATUS_KEY_PARALYZE,  ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_DIZZY,     ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_KEY_FEAR,      ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_END,
};

s32 N(ShuffleAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_KoopaTroopa_Dark_Walk,
    STATUS_KEY_STONE,     ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_SLEEP,     ANIM_KoopaTroopa_Dark_Sleep,
    STATUS_KEY_POISON,    ANIM_KoopaTroopa_Dark_Walk,
    STATUS_KEY_STOP,      ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_STATIC,    ANIM_KoopaTroopa_Dark_Walk,
    STATUS_KEY_PARALYZE,  ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_DIZZY,     ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_KEY_FEAR,      ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_END,
};

s32 N(HyperAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_KoopaTroopa_Dark_Scramble,
    STATUS_KEY_STONE,     ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_SLEEP,     ANIM_KoopaTroopa_Dark_Sleep,
    STATUS_KEY_POISON,    ANIM_KoopaTroopa_Dark_Scramble,
    STATUS_KEY_STOP,      ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_STATIC,    ANIM_KoopaTroopa_Dark_Scramble,
    STATUS_KEY_PARALYZE,  ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_DIZZY,     ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_KEY_FEAR,      ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_END,
};

s32 N(HyperShuffleAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_KoopaTroopa_Dark_Walk,
    STATUS_KEY_STONE,     ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_SLEEP,     ANIM_KoopaTroopa_Dark_Sleep,
    STATUS_KEY_POISON,    ANIM_KoopaTroopa_Dark_Walk,
    STATUS_KEY_STOP,      ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_STATIC,    ANIM_KoopaTroopa_Dark_Walk,
    STATUS_KEY_PARALYZE,  ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_DIZZY,     ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_KEY_FEAR,      ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_END,
};

s32 N(ToppledAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_KoopaTroopa_Dark_ToppleStruggle,
    STATUS_KEY_STONE,     ANIM_KoopaTroopa_Dark_ToppleStill,
    STATUS_KEY_SLEEP,     ANIM_KoopaTroopa_Dark_ToppleSleep,
    STATUS_KEY_POISON,    ANIM_KoopaTroopa_Dark_ToppleStruggle,
    STATUS_KEY_STOP,      ANIM_KoopaTroopa_Dark_ToppleStill,
    STATUS_KEY_STATIC,    ANIM_KoopaTroopa_Dark_ToppleStruggle,
    STATUS_KEY_PARALYZE,  ANIM_KoopaTroopa_Dark_ToppleStill,
    STATUS_KEY_DIZZY,     ANIM_KoopaTroopa_Dark_ToppleStunned,
    STATUS_KEY_FEAR,      ANIM_KoopaTroopa_Dark_ToppleStunned,
    STATUS_END,
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(RandInt, 1000, LVar0)
    IfLt(LVar0, 300)
        Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
    Else
        Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Hyper)
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(HyperAnims)))
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Scramble)
    EndIf
    Call(SetActorVar, ACTOR_SELF, AVAR_HasWhirlwind, FALSE)
    Return
    End
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(EVS_UpdateOffsets) = {
    Switch(LVar0)
        CaseOrEq(AVAL_State_Normal)
        CaseOrEq(AVAL_State_Hyper)
            IfFlag(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_DIZZY)
                Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -5, 15)
                Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
                Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
            Else
                Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -4, 32)
                Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -4)
                Call(N(SetAbsoluteStatusOffsets), -15, 32, 5, 32)
            EndIf
        EndCaseGroup
        CaseOrEq(AVAL_State_ToppledNormal)
        CaseOrEq(AVAL_State_ToppledHyper)
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -5, 15)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
            Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
        Call(RandInt, 80, LVarA)
        Add(LVarA, 80)
        Loop(LVarA)
            Label(1)
                Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                ExecWait(N(EVS_UpdateOffsets))
                IfEq(LVar0, AVAL_State_ToppledNormal)
                    Wait(1)
                    Goto(1)
                EndIf
                IfEq(LVar0, AVAL_State_ToppledHyper)
                    Wait(1)
                    Goto(1)
                EndIf
                IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    Wait(1)
                    Goto(1)
                EndIf
            Wait(1)
        EndLoop
        Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        Switch(LVar0)
            CaseEq(AVAL_State_Normal)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ShuffleAnims)))
            CaseEq(AVAL_State_Hyper)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(HyperShuffleAnims)))
        EndSwitch
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Call(SetActorIdleSpeed, ACTOR_SELF, Float(1.0))
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleRunToGoal, ACTOR_SELF, 0)
        Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        Switch(LVar0)
            CaseEq(AVAL_State_Normal)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(KoopaAnims)))
            CaseEq(AVAL_State_Hyper)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(HyperAnims)))
            CaseOrEq(AVAL_State_ToppledNormal)
            CaseOrEq(AVAL_State_ToppledHyper)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledAnims)))
            EndCaseGroup
        EndSwitch
        Loop(20)
            Label(2)
                Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                ExecWait(N(EVS_UpdateOffsets))
                IfEq(LVar0, AVAL_State_ToppledNormal)
                    Wait(1)
                    Goto(2)
                EndIf
                IfEq(LVar0, AVAL_State_ToppledHyper)
                    Wait(1)
                    Goto(2)
                EndIf
                IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    Wait(1)
                    Goto(2)
                EndIf
            Wait(1)
        EndLoop
        Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        Switch(LVar0)
            CaseEq(AVAL_State_Normal)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ShuffleAnims)))
            CaseEq(AVAL_State_Hyper)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(HyperShuffleAnims)))
        EndSwitch
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Sub(LVar0, 5)
        Call(SetActorIdleSpeed, ACTOR_SELF, Float(1.0))
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleRunToGoal, ACTOR_SELF, 0)
        Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        Switch(LVar0)
            CaseEq(AVAL_State_Normal)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(KoopaAnims)))
            CaseEq(AVAL_State_Hyper)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(HyperAnims)))
            CaseOrEq(AVAL_State_ToppledNormal)
            CaseOrEq(AVAL_State_ToppledHyper)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledAnims)))
            EndCaseGroup
        EndSwitch
        Loop(50)
            Label(3)
                Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                ExecWait(N(EVS_UpdateOffsets))
                IfEq(LVar0, AVAL_State_ToppledNormal)
                    Wait(1)
                    Goto(3)
                EndIf
                IfEq(LVar0, AVAL_State_ToppledHyper)
                    Wait(1)
                    Goto(3)
                EndIf
                IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    Wait(1)
                    Goto(3)
                EndIf
            Wait(1)
        EndLoop
        Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        Switch(LVar0)
            CaseEq(AVAL_State_Hyper)
                Call(SetActorVar, ACTOR_SELF, AVAR_HasWhirlwind, TRUE)
                Thread
                    Call(MakeLerp, 720, 0, 30, EASING_COS_IN_OUT)
                    Label(10)
                        Call(UpdateLerp)
                        Call(SetActorYaw, ACTOR_SELF, LVar0)
                        IfEq(LVar1, 1)
                            Call(GetActorVar, ACTOR_SELF, AVAR_HasWhirlwind, LVar2)
                            IfEq(LVar2, 1)
                                Wait(1)
                                Goto(10)
                            EndIf
                        EndIf
                    Call(SetActorVar, ACTOR_SELF, AVAR_HasWhirlwind, FALSE)
                    Call(SetActorYaw, ACTOR_SELF, 0)
                EndThread
                Wait(8)
                Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, WHIRLWIND_DECOR_IDX, ACTOR_DECORATION_WHIRLWIND)
                Wait(15)
                Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, WHIRLWIND_DECOR_IDX)
                Wait(8)
                Call(SetActorVar, ACTOR_SELF, AVAR_HasWhirlwind, FALSE)
            CaseEq(AVAL_State_Normal)
            CaseEq(AVAL_State_ToppledNormal)
            CaseEq(AVAL_State_ToppledHyper)
        EndSwitch
        Goto(0)
    Return
    End
};

s32 N(FlipPosOffsets)[] = { 9, 16, 22, 26, 30, 32, 33, 32, 30, 26, 22, 16, 9, 0, 4, 6, 7, 6, 4, 0, 2, 0 };

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(GetActorVar, ACTOR_SELF, AVAR_HasWhirlwind, LVar0)
    IfEq(LVar0, TRUE)
        Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, WHIRLWIND_DECOR_IDX)
        Call(SetActorVar, ACTOR_SELF, AVAR_HasWhirlwind, FALSE)
    EndIf
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_KoopaTroopa_Dark_BurnHurt)
            SetConst(LVar2, ANIM_KoopaTroopa_Dark_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_KoopaTroopa_Dark_BurnHurt)
            SetConst(LVar2, ANIM_KoopaTroopa_Dark_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_KoopaTroopa_Dark_BurnStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_FLIP_TRIGGER)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            Switch(LVar0)
                CaseEq(AVAL_State_Normal)
                    Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_ToppledNormal)
                CaseEq(AVAL_State_Hyper)
                    Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_ToppledHyper)
            EndSwitch
            Call(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 1)
            Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledDefenseTable)))
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledAnims)))
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -5, 15)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Hurt)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
            Thread
                Wait(4)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 30)
                Wait(1)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                Wait(1)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, -30)
                Wait(1)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, -60)
                Wait(1)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, -75)
                Wait(1)
            EndThread
            UseBuf(N(FlipPosOffsets))
            Loop(ARRAY_COUNT(N(FlipPosOffsets)))
                BufRead1(LVar0)
                Call(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                Wait(1)
            EndLoop
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ToppleStruggle)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(0.5))
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_KoopaTroopa_Dark_Run)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            Switch(LVar0)
                CaseOrEq(AVAL_State_Normal)
                CaseOrEq(AVAL_State_Hyper)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_KoopaTroopa_Dark_ShellEnter)
                    ExecWait(EVS_Enemy_NoDamageHit)
                    Call(GetStatusFlags, ACTOR_SELF, LVar0)
                    IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ShellExit)
                        Wait(10)
                    EndIf
                EndCaseGroup
                CaseOrEq(AVAL_State_ToppledNormal)
                CaseOrEq(AVAL_State_ToppledHyper)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_KoopaTroopa_Dark_ToppleStruggle)
                    ExecWait(EVS_Enemy_NoDamageHit)
                EndCaseGroup
            EndSwitch
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_END_FIRST_STRIKE)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            IfEq(LVar0, AVAL_State_Normal)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_KoopaTroopa_Dark_Run)
                ExecWait(EVS_Enemy_ReturnHome)
            EndIf
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            IfEq(LVar0, AVAL_State_Normal)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_KoopaTroopa_Dark_Scramble)
                ExecWait(EVS_Enemy_Recover)
            EndIf
        CaseEq(EVENT_SCARE_AWAY)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            Switch(LVar0)
                CaseOrEq(AVAL_State_Normal)
                CaseOrEq(AVAL_State_Hyper)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_KoopaTroopa_Dark_Run)
                    SetConst(LVar2, ANIM_KoopaTroopa_Dark_Hurt)
                    ExecWait(EVS_Enemy_ScareAway)
                    Return
                EndCaseGroup
                CaseOrEq(AVAL_State_ToppledNormal)
                CaseOrEq(AVAL_State_ToppledHyper)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_KoopaTroopa_Dark_ToppleStruggle)
                    ExecWait(EVS_Enemy_NoDamageHit)
                EndCaseGroup
            EndSwitch
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            Switch(LVar0)
                CaseOrEq(AVAL_State_Normal)
                CaseOrEq(AVAL_State_Hyper)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_KoopaTroopa_Dark_Panic)
                EndCaseGroup
                CaseOrEq(AVAL_State_ToppledNormal)
                CaseOrEq(AVAL_State_ToppledHyper)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_KoopaTroopa_Dark_ToppleStruggle)
                EndCaseGroup
            EndSwitch
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            Switch(LVar0)
                CaseOrEq(AVAL_State_Normal)
                CaseOrEq(AVAL_State_Hyper)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_KoopaTroopa_Dark_Panic)
                EndCaseGroup
                CaseOrEq(AVAL_State_ToppledNormal)
                CaseOrEq(AVAL_State_ToppledHyper)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_KoopaTroopa_Dark_ToppleStruggle)
                EndCaseGroup
            EndSwitch
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseEq(EVENT_AIR_LIFT_FAILED)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            Switch(LVar0)
                CaseOrEq(AVAL_State_Normal)
                CaseOrEq(AVAL_State_Hyper)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_KoopaTroopa_Dark_Idle)
                    ExecWait(EVS_Enemy_NoDamageHit)
                EndCaseGroup
                CaseOrEq(AVAL_State_ToppledNormal)
                CaseOrEq(AVAL_State_ToppledHyper)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_KoopaTroopa_Dark_ToppleStruggle)
                    ExecWait(EVS_Enemy_NoDamageHit)
                EndCaseGroup
            EndSwitch
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_ShellToss) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ShellSpin)
    Else
        Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Wait(10)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ShellEnter)
        Wait(10)
        Thread
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, 4)
            PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
            Wait(3)
            PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
            Wait(2)
            PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        EndThread
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_SPIN)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ShellSpin)
        Wait(10)
        Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    EndIf
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_TOSS)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, 3, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetStatusFlags, ACTOR_SELF, LVar5)
            Call(AddGoalPos, ACTOR_SELF, -40, 0, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(16.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ShellExit)
            Wait(8)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Wait(4)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_BeginPanic1)
            Wait(1)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_BeginPanic2)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(2.0))
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Panic)
            Wait(6)
            Sub(LVar1, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, SWEAT_DECOR_IDX, ACTOR_DECORATION_SWEAT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Panic)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetGoalToHome, ACTOR_SELF)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Idle)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, SWEAT_DECOR_IDX)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(16.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_STATUS_ALWAYS_HITS, SUPPRESS_EVENT_ALL, 0, DMG_SHELL_TOSS, BS_FLAGS1_TRIGGER_EVENTS)
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
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ShellExit)
            Wait(8)
            Call(YieldTurn)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_KoopaTroopa_Dark_Run)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Idle)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_Whirlwind) = {
    Label(10)
        Call(GetActorVar, ACTOR_SELF, AVAR_HasWhirlwind, LVar0)
        Wait(1)
        IfEq(LVar0, TRUE)
            Goto(10)
        EndIf
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(AddGoalPos, ACTOR_SELF, 8, 0, 0)
    Else
        Call(AddGoalPos, ACTOR_SELF, 20, 0, 0)
    EndIf
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Run)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Scramble)
    Wait(10)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ShellEnter)
    Wait(10)
    Thread
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 4)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        Wait(3)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        Wait(2)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
    EndThread
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_SPIN)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ShellSpin)
    Wait(20)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_DIZZY_SHELL)
    Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, WHIRLWIND_DECOR_IDX, ACTOR_DECORATION_WHIRLWIND)
    Wait(40)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, 0, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ShellExit)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, WHIRLWIND_DECOR_IDX)
            Wait(10)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, SWEAT_DECOR_IDX, ACTOR_DECORATION_SWEAT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Panic)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetGoalToHome, ACTOR_SELF)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Scramble)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, SWEAT_DECOR_IDX)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Return
        EndCaseGroup
    EndSwitch
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_ALL, DMG_STATUS_KEY(STATUS_FLAG_DIZZY, 2, 60), 0, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Thread
                Call(WasStatusInflicted, ACTOR_SELF, LVar0)
                IfEq(LVar0, 1)
                    Call(MakeLerp, 0, 1080, 30, EASING_COS_IN_OUT)
                    Label(0)
                    Call(UpdateLerp)
                    Call(SetActorYaw, ACTOR_PLAYER, LVar0)
                    Wait(1)
                    IfEq(LVar1, 1)
                        Goto(0)
                    EndIf
                EndIf
            EndThread
            Wait(20)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ShellExit)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, WHIRLWIND_DECOR_IDX)
            Wait(10)
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_KoopaTroopa_Dark_Run)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Scramble)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TryGettingUp) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
    Sub(LVar0, 1)
    IfGt(LVar0, 0)
        Call(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
        Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, SWEAT_DECOR_IDX, ACTOR_DECORATION_SWEAT)
        Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(2.0))
        Wait(30)
        Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(0.5))
        Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, SWEAT_DECOR_IDX)
    Else
        Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, SWEAT_DECOR_IDX, ACTOR_DECORATION_SWEAT)
        Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(2.0))
        Wait(20)
        Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(0.5))
        Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, SWEAT_DECOR_IDX)
        Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_JUMP)
        Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ToppleStruggle)
        Set(LVar0, 0)
        Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
        Thread
            Loop(5)
                Add(LVar0, 15)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                Wait(1)
            EndLoop
        EndThread
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(3.0))
        Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_A)
        Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
        Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(UprightDefenseTable)))
        Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -4, 32)
        Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -4)
        Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, FALSE)
        Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
        Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        Switch(LVar0)
            CaseEq(AVAL_State_ToppledNormal)
                Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(KoopaAnims)))
            CaseEq(AVAL_State_ToppledHyper)
                Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Hyper)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(HyperAnims)))
        EndSwitch
    EndIf
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_State_Normal)
            ExecWait(N(EVS_Attack_ShellToss))
            Call(RandInt, 1000, LVar0)
            IfLt(LVar0, 300)
                Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(KoopaAnims)))
            Else
                Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Hyper)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(HyperAnims)))
            EndIf
        CaseEq(AVAL_State_Hyper)
            ExecWait(N(EVS_Attack_Whirlwind))
            Call(RandInt, 1000, LVar0)
            IfLt(LVar0, 300)
                Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(KoopaAnims)))
            Else
                Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Hyper)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(HyperAnims)))
            EndIf
        CaseOrEq(AVAL_State_ToppledNormal)
        CaseOrEq(AVAL_State_ToppledHyper)
            ExecWait(N(EVS_TryGettingUp))
        EndCaseGroup
    EndSwitch
    Return
    End
};

