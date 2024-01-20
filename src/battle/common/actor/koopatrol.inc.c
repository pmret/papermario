#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Koopatrol.h"
#include "effects.h"

#define NAMESPACE A(koopatrol)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

enum N(ActorVars) {
    AVAR_State          = 0,
    AVAL_State_Normal   = 0,
    AVAL_State_Toppled  = 1,
    AVAL_State_Charged  = 2,
    AVAR_Generation     = 1,
    AVAR_AncestorColumn = 2,
    AVAR_FlippedTurns   = 9,
};

enum N(ActorParams) {
    DMG_SHELL_TOSS      = 4,
    DMG_CHARGED_TOSS    = 10,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Koopatrol_Anim01,
    STATUS_KEY_STONE,     ANIM_Koopatrol_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Koopatrol_Anim11,
    STATUS_KEY_POISON,    ANIM_Koopatrol_Anim01,
    STATUS_KEY_STOP,      ANIM_Koopatrol_Anim00,
    STATUS_KEY_STATIC,    ANIM_Koopatrol_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_Koopatrol_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Koopatrol_Anim13,
    STATUS_KEY_FEAR,      ANIM_Koopatrol_Anim13,
    STATUS_END,
};

s32 N(ShuffleAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Koopatrol_Anim03,
    STATUS_KEY_STONE,     ANIM_Koopatrol_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Koopatrol_Anim11,
    STATUS_KEY_POISON,    ANIM_Koopatrol_Anim03,
    STATUS_KEY_STOP,      ANIM_Koopatrol_Anim00,
    STATUS_KEY_STATIC,    ANIM_Koopatrol_Anim03,
    STATUS_KEY_PARALYZE,  ANIM_Koopatrol_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Koopatrol_Anim13,
    STATUS_KEY_FEAR,      ANIM_Koopatrol_Anim13,
    STATUS_END,
};

s32 N(ToppledAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Koopatrol_Anim0F,
    STATUS_KEY_STONE,     ANIM_Koopatrol_Anim10,
    STATUS_KEY_SLEEP,     ANIM_Koopatrol_Anim12,
    STATUS_KEY_POISON,    ANIM_Koopatrol_Anim0F,
    STATUS_KEY_STOP,      ANIM_Koopatrol_Anim10,
    STATUS_KEY_STATIC,    ANIM_Koopatrol_Anim0F,
    STATUS_KEY_PARALYZE,  ANIM_Koopatrol_Anim10,
    STATUS_KEY_DIZZY,     ANIM_Koopatrol_Anim14,
    STATUS_KEY_FEAR,      ANIM_Koopatrol_Anim14,
    STATUS_END,
};

s32 N(ChargedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Koopatrol_Anim06,
    STATUS_KEY_STONE,     ANIM_Koopatrol_Anim06,
    STATUS_KEY_SLEEP,     ANIM_Koopatrol_Anim06,
    STATUS_KEY_POISON,    ANIM_Koopatrol_Anim06,
    STATUS_KEY_STOP,      ANIM_Koopatrol_Anim06,
    STATUS_KEY_STATIC,    ANIM_Koopatrol_Anim06,
    STATUS_KEY_PARALYZE,  ANIM_Koopatrol_Anim06,
    STATUS_KEY_DIZZY,     ANIM_Koopatrol_Anim06,
    STATUS_KEY_FEAR,      ANIM_Koopatrol_Anim06,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   3,
    ELEMENT_SHOCK,    3,
    ELEMENT_END,
};

s32 N(ToppledDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(ChargedDefense)[] = {
    ELEMENT_NORMAL,   3,
    ELEMENT_FIRE,     3,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              50,
    STATUS_KEY_POISON,             60,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             80,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             70,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

s32 N(ChargedStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,                0,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
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
        .targetOffset = { 0, 32 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -12 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_KOOPATROL,
    .level = ACTOR_LEVEL_KOOPATROL,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 75,
    .hurricaneChance = 65,
    .spookChance = 60,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 85,
    .coinReward = 2,
    .size = { 32, 42 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 32 },
    .statusTextOffset = { 5, 32 },
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"
#include "common/StartRumbleWithParams.inc.c"

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
    Call(SetActorVar, ACTOR_SELF, AVAR_Generation, 0)
    Call(GetIndexFromHome, ACTOR_SELF, LVar0)
    Call(SetActorVar, ACTOR_SELF, AVAR_AncestorColumn, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(SetBattleVar, BTL_VAR_KoopatrolSummonCount_0, 0)
        CaseEq(1)
            Call(SetBattleVar, BTL_VAR_KoopatrolSummonCount_1, 0)
        CaseEq(2)
            Call(SetBattleVar, BTL_VAR_KoopatrolSummonCount_2, 0)
        CaseEq(3)
            Call(SetBattleVar, BTL_VAR_KoopatrolSummonCount_3, 0)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
        CaseEq(PHASE_ENEMY_BEGIN)
        CaseEq(PHASE_ENEMY_END)
            Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_None)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_UpdateOffsets) = {
    Switch(LVar0)
        CaseEq(AVAL_State_Normal)
            IfFlag(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_DIZZY)
                Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -5, 15)
                Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
                Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
            Else
                Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -4, 32)
                Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -4)
                Call(N(SetAbsoluteStatusOffsets), -15, 32, 5, 32)
            EndIf
        CaseEq(AVAL_State_Toppled)
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -5, 15)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
            Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
        CaseEq(AVAL_State_Charged)
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -4, 20)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -6)
            Call(N(SetAbsoluteStatusOffsets), -15, 22, 5, 22)
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
                IfEq(LVar0, AVAL_State_Toppled)
                    Wait(1)
                    Goto(1)
                EndIf
                IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED | STATUS_FLAG_GLOWING)
                    Wait(1)
                    Goto(1)
                EndIf
            Wait(1)
        EndLoop
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Call(SetActorIdleSpeed, ACTOR_SELF, Float(1.0))
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ShuffleAnims)))
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleRunToGoal, ACTOR_SELF, 0)
        Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        Switch(LVar0)
            CaseEq(AVAL_State_Normal)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
            CaseEq(AVAL_State_Toppled)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledAnims)))
        EndSwitch
        Loop(20)
            Label(2)
                Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                ExecWait(N(EVS_UpdateOffsets))
                IfEq(LVar0, AVAL_State_Toppled)
                    Wait(1)
                    Goto(2)
                EndIf
                IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED | STATUS_FLAG_GLOWING)
                    Wait(1)
                    Goto(2)
                EndIf
            Wait(1)
        EndLoop
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Sub(LVar0, 5)
        Call(SetActorIdleSpeed, ACTOR_SELF, Float(1.0))
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ShuffleAnims)))
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleRunToGoal, ACTOR_SELF, 0)
        Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        Switch(LVar0)
            CaseEq(AVAL_State_Normal)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
            CaseEq(AVAL_State_Toppled)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledAnims)))
        EndSwitch
        Loop(80)
            Label(3)
                Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                ExecWait(N(EVS_UpdateOffsets))
                IfEq(LVar0, AVAL_State_Toppled)
                    Wait(1)
                    Goto(3)
                EndIf
                IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED | STATUS_FLAG_GLOWING)
                    Wait(1)
                    Goto(3)
                EndIf
            Wait(1)
        EndLoop
        Goto(0)
    Return
    End
};

s32 N(FlipPosOffsets)[] = { 9, 16, 22, 26, 30, 32, 33, 32, 30, 26, 22, 16, 9, 0, 4, 6, 7, 6, 4, 0, 2, 0 };

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            Switch(LVar0)
                CaseOrEq(AVAL_State_Normal)
                CaseOrEq(AVAL_State_Toppled)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim0B)
                    ExecWait(EVS_Enemy_Hit)
                EndCaseGroup
                CaseEq(AVAL_State_Charged)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim06)
                    ExecWait(EVS_Enemy_Hit)
            EndSwitch
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Koopatrol_Anim0C)
            SetConst(LVar2, ANIM_Koopatrol_Anim0D)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Koopatrol_Anim0C)
            SetConst(LVar2, ANIM_Koopatrol_Anim0D)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Koopatrol_Anim0D)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            Switch(LVar0)
                CaseOrEq(AVAL_State_Normal)
                CaseOrEq(AVAL_State_Toppled)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim0B)
                    ExecWait(EVS_Enemy_SpinSmashHit)
                EndCaseGroup
                CaseEq(AVAL_State_Charged)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim06)
                    ExecWait(EVS_Enemy_SpinSmashHit)
            EndSwitch
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            Switch(LVar0)
                CaseOrEq(AVAL_State_Normal)
                CaseOrEq(AVAL_State_Toppled)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim0B)
                    ExecWait(EVS_Enemy_SpinSmashHit)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim0B)
                    ExecWait(EVS_Enemy_Death)
                EndCaseGroup
                CaseEq(AVAL_State_Charged)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim06)
                    ExecWait(EVS_Enemy_SpinSmashHit)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim08)
                    Wait(5)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim0B)
                    ExecWait(EVS_Enemy_Death)
            EndSwitch
        CaseEq(EVENT_FLIP_TRIGGER)
            Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Toppled)
            Call(SetActorVar, ACTOR_SELF, AVAR_FlippedTurns, 1)
            Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledDefense)))
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledAnims)))
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -5, 15)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, FALSE)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim0B)
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
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim0F)
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Koopatrol_Anim0B)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Koopatrol_Anim0B)
            ExecWait(EVS_Enemy_Knockback)
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Koopatrol_Anim04)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Koopatrol_Anim0B)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Koopatrol_Anim0B)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_STAR_BEAM)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            IfEq(LVar0, AVAL_State_Charged)
                Call(SetStatusTable, ACTOR_SELF, Ref(N(StatusTable)))
                Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(DefenseTable)))
                Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FLIPABLE, TRUE)
                Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
                Call(GetStatusFlags, ACTOR_SELF, LVarA)
                IfNotFlag(LVarA, STATUS_FLAG_DEFENSE_BOOST | STATUS_FLAG_ATTACK_BOOST)
                    Call(EnableActorGlow, ACTOR_SELF, FALSE)
                EndIf
                Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Koopatrol_Anim08)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            Switch(LVar0)
                CaseEq(AVAL_State_Normal)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim07)
                    ExecWait(EVS_Enemy_NoDamageHit)
                    Call(GetStatusFlags, ACTOR_SELF, LVar0)
                    IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim08)
                        Wait(10)
                    EndIf
                CaseEq(AVAL_State_Toppled)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim0F)
                    ExecWait(EVS_Enemy_NoDamageHit)
                CaseEq(AVAL_State_Charged)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim06)
                    ExecWait(EVS_Enemy_NoDamageHit)
            EndSwitch
        EndCaseGroup
        CaseEq(EVENT_SPIKE_TAUNT)
            Wait(10)
            Set(LFlag0, FALSE)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(GetStatusFlags, ACTOR_SELF, LVar3)
            IfFlag(LVar3, STATUS_FLAG_SHRINK)
                Add(LVar1, 16)
                Set(LFlag0, TRUE)
            EndIf
            IfFlag(LVar3, STATUS_FLAG_DIZZY)
                Add(LVar0, -14)
                Add(LVar1, 20)
                Set(LFlag0, TRUE)
            EndIf
            IfFlag(LVar3, STATUS_FLAG_SLEEP)
                Add(LVar0, -14)
                Add(LVar1, 20)
                Set(LFlag0, TRUE)
            EndIf
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVarA)
            IfEq(LVarA, AVAL_State_Charged)
                Add(LVar1, 23)
                Set(LFlag0, TRUE)
            EndIf
            IfEq(LFlag0, FALSE)
                Add(LVar1, 42)
            EndIf
            PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 20, 0)
            Wait(20)
        CaseEq(EVENT_DEATH)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            Switch(LVar0)
                CaseOrEq(AVAL_State_Normal)
                CaseOrEq(AVAL_State_Toppled)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim0B)
                    ExecWait(EVS_Enemy_Hit)
                    Wait(10)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim0B)
                    ExecWait(EVS_Enemy_Death)
                    Return
                EndCaseGroup
                CaseEq(AVAL_State_Charged)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim06)
                    ExecWait(EVS_Enemy_Hit)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim08)
                    Wait(5)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim0B)
                    ExecWait(EVS_Enemy_Death)
                    Return
            EndSwitch
        CaseEq(EVENT_RECOVER_STATUS)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            Switch(LVar0)
                CaseEq(AVAL_State_Normal)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim01)
                    ExecWait(EVS_Enemy_Recover)
                CaseEq(AVAL_State_Toppled)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim0F)
                    ExecWait(EVS_Enemy_NoDamageHit)
                CaseEq(AVAL_State_Charged)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim06)
                    ExecWait(EVS_Enemy_Recover)
            EndSwitch
        CaseEq(EVENT_SCARE_AWAY)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            Switch(LVar0)
                CaseOrEq(AVAL_State_Normal)
                CaseOrEq(AVAL_State_Charged)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim04)
                    SetConst(LVar2, ANIM_Koopatrol_Anim0B)
                    ExecWait(EVS_Enemy_ScareAway)
                    Return
                EndCaseGroup
                CaseEq(AVAL_State_Toppled)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim0F)
                    ExecWait(EVS_Enemy_NoDamageHit)
            EndSwitch
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            Switch(LVar0)
                CaseEq(AVAL_State_Normal)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim16)
                    ExecWait(EVS_Enemy_AirLift)
                CaseEq(AVAL_State_Toppled)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim0F)
                    ExecWait(EVS_Enemy_AirLift)
                CaseEq(AVAL_State_Charged)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim0F)
                    ExecWait(EVS_Enemy_AirLift)
            EndSwitch
        CaseEq(EVENT_BLOW_AWAY)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            Switch(LVar0)
                CaseEq(AVAL_State_Normal)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim16)
                CaseEq(AVAL_State_Toppled)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim0F)
                CaseEq(AVAL_State_Charged)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim0F)
            EndSwitch
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseEq(EVENT_AIR_LIFT_FAILED)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            Switch(LVar0)
                CaseEq(AVAL_State_Normal)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim01)
                CaseEq(AVAL_State_Toppled)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim0F)
                CaseEq(AVAL_State_Charged)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_Koopatrol_Anim0F)
            EndSwitch
            ExecWait(EVS_Enemy_NoDamageHit)
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
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim06)
    Else
        Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        IfEq(LVar0, AVAL_State_Toppled)
            Call(GetActorVar, ACTOR_SELF, AVAR_FlippedTurns, LVar0)
            Sub(LVar0, 1)
            IfGt(LVar0, 0)
                Call(SetActorVar, ACTOR_SELF, AVAR_FlippedTurns, LVar0)
                Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
                Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(3.0))
                Wait(15)
                Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
                Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Else
                Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
                Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(3.0))
                Wait(10)
                Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
                Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
                Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_JUMP)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim0F)
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
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim01)
                Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
                Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(DefenseTable)))
                Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -4, 32)
                Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -4)
                Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, TRUE)
                Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, FALSE)
            EndIf
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndIf
        Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
        Wait(10)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim07)
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
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim06)
        Wait(10)
        Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EndIf
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_TOSS)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 4, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -40, 0, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(16.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(GetBattlePhase, LVar0)
            IfEq(LVar0, PHASE_FIRST_STRIKE)
                Call(UseBattleCamPreset, BTL_CAM_PRESET_05)
                Call(SetBattleCamZoom, 300)
                Call(SetBattleCamOffsetZ, 20)
                Call(MoveBattleCamOver, 10)
                Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
            EndIf
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim08)
            Wait(8)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Wait(4)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim16)
            Wait(1)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim16)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(2.0))
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim16)
            Wait(6)
            Sub(LVar1, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim16)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim01)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetPartYaw, ACTOR_SELF, PRT_MAIN, 0)
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
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim08)
            Wait(8)
            Call(YieldTurn)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Koopatrol_Anim04)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim01)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_ChargedToss) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    IfEq(LVar0, AVAL_State_Normal) // charge for attack
        Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 20)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_POWER_UP)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 10)
        PlayEffect(EFFECT_ENERGY_IN_OUT, 6, LVar0, LVar1, LVar2, Float(1.0), 45, 0)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim15)
        Wait(30)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 20)
        Thread
            Wait(8)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim07)
        EndThread
        Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_A)
        Call(N(StartRumbleWithParams), 128, 10)
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(0.5))
        EndThread
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim06)
        Call(SetStatusTable, ACTOR_SELF, Ref(N(ChargedStatusTable)))
        Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(ChargedDefense)))
        Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FLIPABLE, FALSE)
        Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Charged)
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ChargedAnims)))
        Call(EnableActorGlow, ACTOR_SELF, TRUE)
        Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, TRUE)
        Wait(10)
        Call(UseIdleAnimation, ACTOR_SELF, TRUE)
        Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
        Return
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Loop(20)
        Call(SetActorDispOffset, ACTOR_SELF, 1, 0, 0)
        Wait(1)
        Call(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
        Wait(1)
    EndLoop
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KOOPA_LAUNCH_SHELL)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 4, BS_FLAGS1_INCLUDE_POWER_UPS)
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
            Thread
                Loop(30)
                    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    PlayEffect(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0, 0)
                    Wait(1)
                EndLoop
            EndThread
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -200, 0, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(16.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Wait(15)
            Call(GetStatusFlags, ACTOR_SELF, LVarA)
            IfNotFlag(LVarA, STATUS_FLAG_DEFENSE_BOOST | STATUS_FLAG_ATTACK_BOOST)
                Call(EnableActorGlow, ACTOR_SELF, FALSE)
            EndIf
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            Call(YieldTurn)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetActorPos, ACTOR_SELF, 300, 0, 0)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorSpeed, ACTOR_SELF, Float(16.0))
            Call(SetGoalToHome, ACTOR_SELF)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim08)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetStatusTable, ACTOR_SELF, Ref(N(StatusTable)))
            Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(DefenseTable)))
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FLIPABLE, TRUE)
            Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
            Wait(10)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Thread
        Loop(30)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0, 0)
            Wait(1)
        EndLoop
    EndThread
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(16.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarA, 0, SUPPRESS_EVENT_ALL, 0, DMG_CHARGED_TOSS, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                Set(LVar0, 0)
                Loop(60)
                    Add(LVar0, 18)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EndThread
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 50)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 30, FALSE, TRUE, FALSE)
            Sub(LVar0, 40)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Wait(20)
            Call(YieldTurn)
            Call(GetStatusFlags, ACTOR_SELF, LVarA)
            IfNotFlag(LVarA, STATUS_FLAG_DEFENSE_BOOST | STATUS_FLAG_ATTACK_BOOST)
                Call(EnableActorGlow, ACTOR_SELF, FALSE)
            EndIf
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetActorPos, ACTOR_SELF, 300, 0, 0)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Koopatrol_Anim04)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim01)
            Call(SetStatusTable, ACTOR_SELF, Ref(N(StatusTable)))
            Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(DefenseTable)))
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FLIPABLE, TRUE)
            Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_GetAvailableColumn) = {
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(1)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetOriginalActorType, LVar0, LVar2)
        Switch(LVar2)
            CaseOrEq(ACTOR_TYPE_BILL_BLASTER)
            CaseOrEq(ACTOR_TYPE_BOMBSHELL_BLASTER)
                Set(LVarA, -1)
                Return
            EndCaseGroup
        EndSwitch
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(1)
        EndIf
    Set(LFlag1, FALSE)
    Set(LFlag2, FALSE)
    Set(LFlag3, FALSE)
    Set(LFlag4, FALSE)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetIndexFromHome, LVar0, LVar1)
        Mod(LVar1, 4)
        Switch(LVar1)
            CaseEq(0)
                Set(LFlag1, TRUE)
            CaseEq(1)
                Set(LFlag2, TRUE)
            CaseEq(2)
                Set(LFlag3, TRUE)
            CaseEq(3)
                Set(LFlag4, TRUE)
        EndSwitch
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    IfEq(LFlag1, FALSE)
        Set(LVarA, 0)
        Return
    EndIf
    IfEq(LFlag2, FALSE)
        Set(LVarA, 1)
        Return
    EndIf
    IfEq(LFlag3, FALSE)
        Set(LVarA, 2)
        Return
    EndIf
    IfEq(LFlag4, FALSE)
        Set(LVarA, 3)
        Return
    EndIf
    Set(LVarA, -1)
    Return
    End
};

Vec3i N(SummonPos) = { NPC_DISPOSE_LOCATION };

Formation N(BackupFormation) = {
    ACTOR_BY_POS(NAMESPACE, N(SummonPos), 100)
};

EvtScript N(EVS_Move_SummonBackup) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim02)
    Wait(20)
    Loop(2)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim02)
        Wait(8)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
        Call(SetActorYaw, ACTOR_SELF, 180)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim09)
        Wait(8)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim02)
        Wait(8)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
        Call(SetActorYaw, ACTOR_SELF, 0)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim09)
        Wait(8)
    EndLoop
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 15)
    Thread
        Wait(8)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 30, 0)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim16)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
    Call(SummonEnemy, Ref(N(BackupFormation)), FALSE)
    Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    Add(LVar1, 200)
    Call(SetActorPos, LVar0, LVar1, LVar2, LVar3)
    Call(SetGoalToIndex, LVar0, LVarA)
    Call(PlaySoundAtActor, LVar0, SOUND_SHELL_TOSS)
    Call(SetActorSounds, LVar0, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Call(SetAnimation, LVar0, 1, ANIM_Koopatrol_Anim06)
    Call(SetActorSpeed, LVar0, Float(6.0))
    Call(RunToGoal, LVar0, 0, FALSE)
    Call(SetAnimation, LVar0, 1, ANIM_Koopatrol_Anim08)
    Wait(10)
    Call(SetAnimation, LVar0, 1, ANIM_Koopatrol_Anim01)
    Call(GetActorPos, LVar0, LVar1, LVar2, LVar3)
    Call(ForceHomePos, LVar0, LVar1, LVar2, LVar3)
    Call(HPBarToHome, LVar0)
    Call(GetActorVar, ACTOR_SELF, AVAR_Generation, LVar1)
    Switch(LVar1)
        CaseEq(0)
            Call(SetActorVar, LVar0, AVAR_Generation, 1)
        CaseEq(1)
            Call(SetActorVar, LVar0, AVAR_Generation, 2)
    EndSwitch
    Call(GetActorVar, ACTOR_SELF, AVAR_AncestorColumn, LVar1)
    Call(SetActorVar, LVar0, AVAR_AncestorColumn, LVar1)
    Switch(LVar1)
        CaseEq(0)
            Call(GetBattleVar, BTL_VAR_KoopatrolSummonCount_0, LVar0)
            Add(LVar0, 1)
            Call(SetBattleVar, BTL_VAR_KoopatrolSummonCount_0, LVar0)
        CaseEq(1)
            Call(GetBattleVar, BTL_VAR_KoopatrolSummonCount_1, LVar0)
            Add(LVar0, 1)
            Call(SetBattleVar, BTL_VAR_KoopatrolSummonCount_1, LVar0)
        CaseEq(2)
            Call(GetBattleVar, BTL_VAR_KoopatrolSummonCount_2, LVar0)
            Add(LVar0, 1)
            Call(SetBattleVar, BTL_VAR_KoopatrolSummonCount_2, LVar0)
        CaseEq(3)
            Call(GetBattleVar, BTL_VAR_KoopatrolSummonCount_3, LVar0)
            Add(LVar0, 1)
            Call(SetBattleVar, BTL_VAR_KoopatrolSummonCount_3, LVar0)
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_CountActiveSummoners) = {
    Set(LVar9, 0)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetOriginalActorType, LVar0, LVar2)
        Switch(LVar2)
            CaseEq(ACTOR_TYPE_KOOPATROL)
                Call(GetStatusFlags, LVar0, LVar3)
                IfNotFlag(LVar3, STATUS_FLAGS_IMMOBILIZED)
                    Call(GetActorVar, LVar0, AVAR_State, LVar3)
                    IfEq(LVar3, AVAL_State_Normal)
                        Call(GetActorVar, LVar0, AVAR_Generation, LVar3)
                        Switch(LVar3)
                            CaseOrEq(0)
                            CaseOrEq(1)
                                Call(GetActorVar, ACTOR_SELF, AVAR_AncestorColumn, LVar3)
                                Switch(LVar3)
                                    CaseEq(0)
                                        Call(GetBattleVar, BTL_VAR_KoopatrolSummonCount_0, LVar4)
                                    CaseEq(1)
                                        Call(GetBattleVar, BTL_VAR_KoopatrolSummonCount_1, LVar4)
                                    CaseEq(2)
                                        Call(GetBattleVar, BTL_VAR_KoopatrolSummonCount_2, LVar4)
                                    CaseEq(3)
                                        Call(GetBattleVar, BTL_VAR_KoopatrolSummonCount_3, LVar4)
                                EndSwitch
                                IfLt(LVar4, 2)
                                    Add(LVar9, 1)
                                EndIf
                            EndCaseGroup
                            CaseEq(2)
                        EndSwitch
                    EndIf
                EndIf
        EndSwitch
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
        ExecWait(N(EVS_Attack_ShellToss))
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_State_Normal)
            Call(GetBattleVar, BTL_VAR_HyperSync, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    Call(GetActorVar, ACTOR_SELF, AVAR_Generation, LVar0)
                    Switch(LVar0)
                        CaseOrEq(0)
                        CaseOrEq(1)
                            Call(GetActorVar, ACTOR_SELF, AVAR_AncestorColumn, LVar0)
                            Switch(LVar0)
                                CaseEq(0)
                                    Call(GetBattleVar, BTL_VAR_KoopatrolSummonCount_0, LVar1)
                                CaseEq(1)
                                    Call(GetBattleVar, BTL_VAR_KoopatrolSummonCount_1, LVar1)
                                CaseEq(2)
                                    Call(GetBattleVar, BTL_VAR_KoopatrolSummonCount_2, LVar1)
                                CaseEq(3)
                                    Call(GetBattleVar, BTL_VAR_KoopatrolSummonCount_3, LVar1)
                            EndSwitch
                            IfGe(LVar1, 2)
                                Call(RandInt, 1000, LVar0)
                                IfLt(LVar0, 300)
                                    Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                                    ExecWait(N(EVS_Attack_ChargedToss))
                                Else
                                    Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                                    ExecWait(N(EVS_Attack_ShellToss))
                                EndIf
                                Return
                            EndIf
                        EndCaseGroup
                        CaseEq(2)
                            Call(RandInt, 1000, LVar0)
                            IfLt(LVar0, 300)
                                Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                                ExecWait(N(EVS_Attack_ChargedToss))
                            Else
                                Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                                ExecWait(N(EVS_Attack_ShellToss))
                            EndIf
                            Return
                    EndSwitch
                    ExecWait(N(EVS_GetAvailableColumn))
                    IfEq(LVarA, -1)
                        Call(RandInt, 1000, LVar0)
                        IfLt(LVar0, 300)
                            Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                            ExecWait(N(EVS_Attack_ChargedToss))
                        Else
                            Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                            ExecWait(N(EVS_Attack_ShellToss))
                        EndIf
                        Return
                    EndIf
                    ExecWait(N(EVS_CountActiveSummoners))
                    Switch(LVar9)
                        CaseEq(1)
                            Call(RandInt, 1000, LVar0)
                            IfLt(LVar0, 400)
                                Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                                ExecWait(N(EVS_Move_SummonBackup))
                                Return
                            EndIf
                        CaseEq(2)
                            Call(RandInt, 1000, LVar0)
                            IfLt(LVar0, 200)
                                Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                                ExecWait(N(EVS_Move_SummonBackup))
                                Return
                            EndIf
                        CaseEq(3)
                            Call(RandInt, 1000, LVar0)
                            IfLt(LVar0, 100)
                                Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                                ExecWait(N(EVS_Move_SummonBackup))
                                Return
                            EndIf
                    EndSwitch
                    Call(RandInt, 1000, LVar0)
                    IfLt(LVar0, 300)
                        Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                        ExecWait(N(EVS_Attack_ChargedToss))
                    Else
                        Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                        ExecWait(N(EVS_Attack_ShellToss))
                    EndIf
                CaseEq(1)
                    Call(GetActorVar, ACTOR_SELF, AVAR_Generation, LVar0)
                    Switch(LVar0)
                        CaseOrEq(0)
                        CaseOrEq(1)
                            Call(GetActorVar, ACTOR_SELF, AVAR_AncestorColumn, LVar0)
                            Switch(LVar0)
                                CaseEq(0)
                                    Call(GetBattleVar, BTL_VAR_KoopatrolSummonCount_0, LVar1)
                                CaseEq(1)
                                    Call(GetBattleVar, BTL_VAR_KoopatrolSummonCount_1, LVar1)
                                CaseEq(2)
                                    Call(GetBattleVar, BTL_VAR_KoopatrolSummonCount_2, LVar1)
                                CaseEq(3)
                                    Call(GetBattleVar, BTL_VAR_KoopatrolSummonCount_3, LVar1)
                            EndSwitch
                            IfGe(LVar1, 2)
                                Call(RandInt, 1000, LVar0)
                                IfLt(LVar0, 300)
                                    Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                                    ExecWait(N(EVS_Attack_ChargedToss))
                                Else
                                    Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                                    ExecWait(N(EVS_Attack_ShellToss))
                                EndIf
                                Return
                            EndIf
                        EndCaseGroup
                        CaseEq(2)
                            ExecWait(N(EVS_Attack_ShellToss))
                            Return
                    EndSwitch
                    ExecWait(N(EVS_GetAvailableColumn))
                    IfEq(LVarA, -1)
                        ExecWait(N(EVS_Attack_ShellToss))
                        Return
                    EndIf
                    ExecWait(N(EVS_CountActiveSummoners))
                    Switch(LVar9)
                        CaseEq(1)
                            Call(RandInt, 1000, LVar0)
                            IfLt(LVar0, 400)
                                ExecWait(N(EVS_Move_SummonBackup))
                                Return
                            EndIf
                        CaseEq(2)
                            Call(RandInt, 1000, LVar0)
                            IfLt(LVar0, 200)
                                ExecWait(N(EVS_Move_SummonBackup))
                                Return
                            EndIf
                        CaseEq(3)
                            Call(RandInt, 1000, LVar0)
                            IfLt(LVar0, 100)
                                ExecWait(N(EVS_Move_SummonBackup))
                                Return
                            EndIf
                    EndSwitch
                    ExecWait(N(EVS_Attack_ShellToss))
                CaseEq(2)
                    ExecWait(N(EVS_Attack_ChargedToss))
            EndSwitch
        CaseEq(AVAL_State_Toppled)
            Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
            ExecWait(N(EVS_Attack_ShellToss))
        CaseEq(AVAL_State_Charged)
            ExecWait(N(EVS_Attack_ChargedToss))
    EndSwitch
    Return
    End
};

