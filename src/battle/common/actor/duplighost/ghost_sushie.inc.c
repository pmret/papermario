#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleSushie.h"

#define NAMESPACE A(sushie_clone)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleSushie_Idle,
    STATUS_KEY_STONE,     ANIM_BattleSushie_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleSushie_Still,
    STATUS_KEY_POISON,    ANIM_BattleSushie_Idle,
    STATUS_KEY_STOP,      ANIM_BattleSushie_Still,
    STATUS_KEY_STATIC,    ANIM_BattleSushie_Idle,
    STATUS_KEY_PARALYZE,  ANIM_BattleSushie_Still,
    STATUS_KEY_DIZZY,     ANIM_BattleSushie_Injured,
    STATUS_KEY_FEAR,      ANIM_BattleSushie_Injured,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              60,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -12 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GHOST_SUSHIE,
    .level = ACTOR_LEVEL_GHOST_SUSHIE,
    .maxHP = 15,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 80,
    .hurricaneChance = 70,
    .spookChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 2,
    .size = { 37, 26 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            Call(GetLastElement, LVar1)
            IfFlag(LVar1, DAMAGE_TYPE_SHOCK)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BattleSushie_Hurt)
                ExecWait(A(EVS_Duplighost_OnHitElectric))
                Return
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BattleSushie_Hurt)
                ExecWait(EVS_Enemy_Hit)
            EndIf
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleSushie_BurnHurt)
            SetConst(LVar2, ANIM_BattleSushie_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleSushie_BurnHurt)
            SetConst(LVar2, ANIM_BattleSushie_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(A(EVS_Duplighost_OnDeath))
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleSushie_BurnStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleSushie_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            ExecWait(A(EVS_Duplighost_OnDeath))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleSushie_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleSushie_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleSushie_Hurt)
            ExecWait(A(EVS_Duplighost_OnShockHit))
            Return
        CaseEq(EVENT_SHOCK_DEATH)
            ExecWait(A(EVS_Duplighost_OnDeath))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleSushie_Hurt)
            Set(LVar2, 20)
            ExecWait(A(EVS_Duplighost_OnShockDeath))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleSushie_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleSushie_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            ExecWait(A(EVS_Duplighost_OnDeath))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleSushie_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleSushie_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleSushie_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleSushie_Run)
            SetConst(LVar2, ANIM_BattleSushie_Hurt)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleSushie_Run)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleSushie_Hurt)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 70, 0, 0)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Sub(LVar3, LVar0)
    Div(LVar3, Float(3.0))
    Set(LVarA, LVar3)
    IfLt(LVarA, 0)
        Mul(LVarA, -1)
    EndIf
    Call(MoveBattleCamOver, LVarA)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleSushie_Run)
    Call(RunToGoal, ACTOR_SELF, LVarA, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleSushie_Idle)
    Wait(10)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_08)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(AddBattleCamZoom, -50)
    Call(MoveBattleCamOver, 30)
    Call(func_8024ECF8, BTL_CAM_MODEY_1, BTL_CAM_MODEX_1, TRUE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleSushie_Tense1)
    Wait(15)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleSushie_Tense2)
    Wait(15)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleSushie_Jump)
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
                Set(LVar0, 0)
                Loop(10)
                    Add(LVar0, 36)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 20)
            EndThread
            Thread
                Call(GetActorVar, ACTOR_SELF, AVAR_Copy_PartnerLevel, LVar0)
                Switch(LVar0)
                    CaseEq(PARTNER_RANK_NORMAL)
                        Wait(13)
                        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.0), Float(1.0), Float(1.0))
                        Wait(1)
                        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.0), Float(1.0), Float(1.0))
                        Wait(1)
                        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.0), Float(1.0), Float(1.0))
                        Wait(1)
                        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.0), Float(1.0), Float(1.0))
                        Wait(1)
                        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.0), Float(1.0), Float(1.0))
                    CaseEq(PARTNER_RANK_SUPER)
                        Wait(13)
                        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.05), Float(1.05), Float(1.05))
                        Wait(1)
                        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.1), Float(1.1), Float(1.1))
                        Wait(1)
                        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.15), Float(1.15), Float(1.15))
                        Wait(1)
                        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.2), Float(1.2), Float(1.2))
                        Wait(1)
                        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.25), Float(1.25), Float(1.25))
                    CaseEq(PARTNER_RANK_ULTRA)
                        Wait(13)
                        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.1), Float(1.1), Float(1.1))
                        Wait(1)
                        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.2), Float(1.2), Float(1.2))
                        Wait(1)
                        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.3), Float(1.3), Float(1.3))
                        Wait(1)
                        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.4), Float(1.4), Float(1.4))
                        Wait(1)
                        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.5), Float(1.5), Float(1.5))
                EndSwitch
            EndThread
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SUSHIE_BELLY_FLOP)
            Call(SetGoalToTarget, ACTOR_SELF)
            Thread
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleSushie_Jump)
                Wait(10)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleSushie_Fall)
            EndThread
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleSushie_Land)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.0), Float(1.0), Float(1.0))
            Call(LandJump, ACTOR_SELF)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SUSHIE_STEP)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(AddGoalPos, ACTOR_SELF, -15, 0, 0)
            Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SUSHIE_STEP)
            Call(AddGoalPos, ACTOR_SELF, -10, 0, 0)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SUSHIE_STEP)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleSushie_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 10)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleSushie_Jump)
    Thread
        Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
        Set(LVar0, 0)
        Loop(10)
            Add(LVar0, 36)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            Wait(1)
        EndLoop
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 20)
    EndThread
    Thread
        Call(GetActorVar, ACTOR_SELF, AVAR_Copy_PartnerLevel, LVar0)
        Switch(LVar0)
            CaseEq(PARTNER_RANK_NORMAL)
                Wait(13)
                Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.1), Float(1.1), Float(1.1))
                Wait(1)
                Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.1), Float(1.1), Float(1.1))
                Wait(1)
                Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.2), Float(1.2), Float(1.2))
                Wait(1)
                Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.2), Float(1.2), Float(1.2))
                Wait(1)
                Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.3), Float(1.3), Float(1.3))
            CaseEq(PARTNER_RANK_SUPER)
                Wait(13)
                Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.15), Float(1.15), Float(1.15))
                Wait(1)
                Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.2), Float(1.2), Float(1.2))
                Wait(1)
                Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.35), Float(1.35), Float(1.35))
                Wait(1)
                Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.4), Float(1.4), Float(1.4))
                Wait(1)
                Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.55), Float(1.55), Float(1.55))
            CaseEq(PARTNER_RANK_ULTRA)
                Wait(13)
                Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.2), Float(1.2), Float(1.2))
                Wait(1)
                Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.3), Float(1.3), Float(1.3))
                Wait(1)
                Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.5), Float(1.5), Float(1.5))
                Wait(1)
                Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.6), Float(1.6), Float(1.6))
                Wait(1)
                Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.8), Float(1.8), Float(1.8))
        EndSwitch
    EndThread
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SUSHIE_BELLY_FLOP)
    Call(SetGoalToTarget, ACTOR_SELF)
    Thread
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleSushie_Jump)
        Wait(10)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleSushie_Fall)
    EndThread
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
    Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleSushie_Land)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    Thread
        Wait(3)
        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.0), Float(1.0), Float(1.0))
    EndThread
    Call(GetActorVar, ACTOR_SELF, AVAR_Copy_PartnerLevel, LVarA)
    Switch(LVarA)
        CaseEq(PARTNER_RANK_NORMAL)
            Wait(2)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 3, BS_FLAGS1_TRIGGER_EVENTS)
        CaseEq(PARTNER_RANK_SUPER)
            Wait(2)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 4, BS_FLAGS1_TRIGGER_EVENTS)
        CaseEq(PARTNER_RANK_ULTRA)
            Wait(2)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 5, BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleSushie_Fall)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 60)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.4))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SUSHIE_STEP)
            Add(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SUSHIE_STEP)
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SUSHIE_STEP)
            Add(LVar0, 10)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SUSHIE_STEP)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleSushie_Idle)
            Wait(15)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleSushie_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

Formation A(SushieCloneFormation) = {
    ACTOR_BY_POS(NAMESPACE, A(DuplighostSummonPos), 0),
};
