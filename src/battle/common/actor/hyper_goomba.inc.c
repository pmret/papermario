#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Goomba.h"

#ifndef NESTED_HYPER_GOOMBA_INCLUDE
#define NAMESPACE A(hyper_goomba)
#endif

extern s32 N(DefaultAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_Attack_Headbonk);

enum N(ActorParams) {
    DMG_HEADBONK    = 1,
    DMG_CHARGED     = 8,
};

#ifndef NESTED_HYPER_GOOMBA_INCLUDE

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_IsCharged      = 0,
    AVAR_NotFirstTurn   = 1,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              80,
    STATUS_KEY_POISON,            100,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              80,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,            100,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,             80,
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
        .targetOffset = { 0, 22 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_HYPER_GOOMBA,
    .level = ACTOR_LEVEL_HYPER_GOOMBA,
    .maxHP = 7,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 60,
    .airLiftChance = 90,
    .hurricaneChance = 90,
    .spookChance = 80,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 24, 24 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

#endif // NESTED_HYPER_GOOMBA_INCLUDE

s32 N(HyperAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Goomba_Hyper_Sleep,
    STATUS_KEY_STONE,     ANIM_Goomba_Hyper_Still,
    STATUS_KEY_SLEEP,     ANIM_Goomba_Hyper_Sleep,
    STATUS_KEY_POISON,    ANIM_Goomba_Hyper_Sleep,
    STATUS_KEY_STOP,      ANIM_Goomba_Hyper_Still,
    STATUS_KEY_STATIC,    ANIM_Goomba_Hyper_Sleep,
    STATUS_KEY_PARALYZE,  ANIM_Goomba_Hyper_Still,
    STATUS_KEY_DIZZY,     ANIM_Goomba_Hyper_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Goomba_Hyper_Dizzy,
    STATUS_END,
};

EvtScript N(EVS_Init) = {
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, false)
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
            Call(SetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, true)
    EndSwitch
    Return
    End
};

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(EVS_Move_Charge) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetActorVar, ACTOR_SELF, AVAR_IsCharged, LVar0)
    IfEq(LVar0, 0)
        Call(UseBattleCamPreset, BTL_CAM_ACTOR)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 20)
        Wait(20)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_POWER_UP)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 10)
        PlayEffect(EFFECT_ENERGY_IN_OUT, 6, LVar0, LVar1, LVar2, Float(1.0), 45, 0)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Run)
        Wait(30)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 20)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
        Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 20, false, true, false)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GOOMBA_STEP)
        Call(N(StartRumbleWithParams), 128, 10)
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(0.5))
        EndThread
        Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, 1)
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(HyperAnims)))
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
        Call(EnableActorGlow, ACTOR_SELF, true)
        Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, true)
        Wait(2)
        Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
        Call(UseIdleAnimation, ACTOR_SELF, true)
        Return
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Loop(20)
        Call(SetActorDispOffset, ACTOR_SELF, 1, 0, 0)
        Wait(1)
        Call(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
        Wait(1)
    EndLoop
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
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
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 80)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_ACTOR_HURT, 0)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -200, 0, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.01))
            Call(SetActorSpeed, ACTOR_SELF, Float(15.0))
            Call(JumpToGoal, ACTOR_SELF, 0, false, true, false)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorPos, ACTOR_SELF, LVar0, 0, LVar2)
            Wait(20)
            Call(EnableActorGlow, ACTOR_SELF, false)
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, false)
            Call(YieldTurn)
            Call(SetActorPos, ACTOR_SELF, 300, 0, 0)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Run)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetGoalToHome, ACTOR_SELF)
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, 0)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_ACTOR_HURT, 0)
    Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 80)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.01))
    Call(SetActorSpeed, ACTOR_SELF, Float(15.0))
    Call(JumpToGoal, ACTOR_SELF, 0, false, true, false)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_CHARGED, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
                Set(LVar0, 80)
                Loop(60)
                    Add(LVar0, 18)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EndThread
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Set(LVar1, 0)
            Sub(LVar0, 50)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 30, false, true, false)
            Sub(LVar0, 40)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, false, true, false)
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
            Wait(10)
            Call(EnableActorGlow, ACTOR_SELF, false)
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, false)
            Call(YieldTurn)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Run)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetGoalToHome, ACTOR_SELF)
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, 0)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
        ExecWait(N(EVS_Attack_Headbonk))
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_IsCharged, LVar0)
    IfEq(LVar0, 1)
        ExecWait(N(EVS_Move_Charge))
        Return
    EndIf
    Call(GetBattleVar, BTL_VAR_HyperSync, LVar0)
    Switch(LVar0)
        CaseEq(BTL_VAL_HyperSync_None)
            Call(GetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, LVar0)
            IfEq(LVar0, 0)
                Call(RandInt, 1000, LVar0)
                IfLt(LVar0, 750)
                    Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                    ExecWait(N(EVS_Move_Charge))
                Else
                    Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                    ExecWait(N(EVS_Attack_Headbonk))
                EndIf
            Else
                Call(RandInt, 1000, LVar0)
                IfLt(LVar0, 500)
                    Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                    ExecWait(N(EVS_Move_Charge))
                Else
                    Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                    ExecWait(N(EVS_Attack_Headbonk))
                EndIf
            EndIf
        CaseEq(BTL_VAL_HyperSync_Done)
            ExecWait(N(EVS_Attack_Headbonk))
        CaseEq(BTL_VAL_HyperSync_Active)
            ExecWait(N(EVS_Move_Charge))
    EndSwitch
    Return
    End
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Goomba_Hyper_Idle,
    STATUS_KEY_STONE,     ANIM_Goomba_Hyper_Still,
    STATUS_KEY_SLEEP,     ANIM_Goomba_Hyper_Sleep,
    STATUS_KEY_POISON,    ANIM_Goomba_Hyper_Idle,
    STATUS_KEY_STOP,      ANIM_Goomba_Hyper_Still,
    STATUS_KEY_STATIC,    ANIM_Goomba_Hyper_Idle,
    STATUS_KEY_PARALYZE,  ANIM_Goomba_Hyper_Still,
    STATUS_KEY_DIZZY,     ANIM_Goomba_Hyper_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Goomba_Hyper_Dizzy,
    STATUS_END,
};

s32 N(ShuffleAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Goomba_Hyper_Run,
    STATUS_KEY_STONE,     ANIM_Goomba_Hyper_Still,
    STATUS_KEY_SLEEP,     ANIM_Goomba_Hyper_Sleep,
    STATUS_KEY_POISON,    ANIM_Goomba_Hyper_Idle,
    STATUS_KEY_STOP,      ANIM_Goomba_Hyper_Still,
    STATUS_KEY_STATIC,    ANIM_Goomba_Hyper_Run,
    STATUS_KEY_PARALYZE,  ANIM_Goomba_Hyper_Still,
    STATUS_KEY_DIZZY,     ANIM_Goomba_Hyper_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Goomba_Hyper_Dizzy,
    STATUS_END,
};

// unused
EvtScript N(EVS_Init_Base) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_Attack_Headbonk)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(10)
        Call(RandInt, 80, LVar0)
        Add(LVar0, 80)
        Loop(LVar0)
            Label(0)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    Wait(1)
                    Goto(0)
                EndIf
            Wait(1)
        EndLoop
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Call(SetActorIdleSpeed, ACTOR_SELF, Float(1.0))
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ShuffleAnims)))
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleRunToGoal, ACTOR_SELF, 0)
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
        Loop(20)
            Label(1)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    Wait(1)
                    Goto(1)
                EndIf
            Wait(1)
        EndLoop
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Sub(LVar0, 5)
        Call(SetActorIdleSpeed, ACTOR_SELF, Float(1.0))
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ShuffleAnims)))
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleRunToGoal, ACTOR_SELF, 0)
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
        Loop(80)
            Label(2)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    Wait(1)
                    Goto(2)
                EndIf
            Wait(1)
        EndLoop
        Goto(10)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Hurt)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_BurnHurt)
            SetConst(LVar2, ANIM_Goomba_Hyper_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_BurnHurt)
            SetConst(LVar2, ANIM_Goomba_Hyper_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_BurnStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Dead)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(EnableActorGlow, ACTOR_SELF, false)
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, false)
            Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, 0)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Electrocute)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(2.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Dizzy)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
            Wait(5)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
        CaseEq(EVENT_SHOCK_DEATH)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(EnableActorGlow, ACTOR_SELF, false)
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, false)
            Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, 0)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Electrocute)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Dead)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_STAR_BEAM)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsCharged, LVar0)
            IfEq(LVar0, 1)
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                Call(EnableActorGlow, ACTOR_SELF, false)
                Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, false)
                Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, 0)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
            EndIf
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Dead)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_END_FIRST_STRIKE)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(2.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Run)
            SetConst(LVar2, ANIM_Goomba_Hyper_Hurt)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Run)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Hurt)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

#include "common/CalculateArcsinDeg.inc.c"

EvtScript N(EVS_Attack_Headbonk) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Run)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
    Call(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    Wait(5)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Midair)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 10)
            Set(LVar1, 10)
            Add(LVar2, 3)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.2))
            Thread
                Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar0)
                Set(LVar0, 0)
                Loop(16)
                    Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    Call(N(CalculateArcsinDeg), LVar1, LVar2, LVar4, LVar5, LVar0)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Set(LVar1, LVar4)
                    Set(LVar2, LVar5)
                    Set(LVar3, LVar6)
                    Wait(1)
                EndLoop
            EndThread
            Thread
                Wait(6)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Midair)
            EndThread
            Call(JumpToGoal, ACTOR_SELF, 16, false, true, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Sleep)
            Call(SetActorScale, ACTOR_SELF, Float(1.1), Float(0.8), Float(1.0))
            Call(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(1.3), Float(0.5), Float(1.0))
            Call(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
            Call(SetActorDispOffset, ACTOR_SELF, 0, 7, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Hurt)
            Wait(5)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(5)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Midair)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 20)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(2.0))
            Thread
                Wait(4)
                Set(LVar0, 180)
                Loop(4)
                    Sub(LVar0, 45)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Midair)
            EndThread
            Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Dizzy)
            Wait(5)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(2.0))
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
            Call(SetActorYaw, ACTOR_SELF, 0)
            Wait(5)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
        CaseDefault
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.2))
            Thread
                Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar0)
                Set(LVar0, 0)
                Loop(16)
                    Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    Call(N(CalculateArcsinDeg), LVar1, LVar2, LVar4, LVar5, LVar0)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Set(LVar1, LVar4)
                    Set(LVar2, LVar5)
                    Set(LVar3, LVar6)
                    Wait(1)
                EndLoop
            EndThread
            Thread
                Wait(6)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Midair)
            EndThread
            Call(JumpToGoal, ACTOR_SELF, 16, false, true, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Tense)
            Call(SetActorScale, ACTOR_SELF, Float(1.1), Float(0.8), Float(1.0))
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(1.3), Float(0.5), Float(1.0))
            Wait(1)
    EndSwitch
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_HEADBONK, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetActorScale, ACTOR_SELF, Float(1.1), Float(0.8), Float(1.0))
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
            Wait(1)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
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
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
            Wait(3)
            Call(YieldTurn)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(2.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};
