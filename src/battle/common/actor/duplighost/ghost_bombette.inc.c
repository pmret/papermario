#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleBombette.h"

#define NAMESPACE A(bombette_clone)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleBombette_Idle,
    STATUS_KEY_STONE,     ANIM_BattleBombette_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleBombette_Still,
    STATUS_KEY_POISON,    ANIM_BattleBombette_Idle,
    STATUS_KEY_STOP,      ANIM_BattleBombette_Still,
    STATUS_KEY_STATIC,    ANIM_BattleBombette_Idle,
    STATUS_KEY_PARALYZE,  ANIM_BattleBombette_Still,
    STATUS_KEY_DIZZY,     ANIM_BattleBombette_Injured,
    STATUS_KEY_FEAR,      ANIM_BattleBombette_Injured,
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
        .targetOffset = { 0, 22 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -2, -7 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GHOST_BOMBETTE,
    .level = ACTOR_LEVEL_GHOST_BOMBETTE,
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
    .size = { 30, 28 },
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

EvtScript N(EVS_PlayDetonateFX) = {
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.75))
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.0))
        Call(ShakeCam, CAM_BATTLE, 0, 10, Float(4.5))
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.0))
    EndThread
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar2, 2)
    PlayEffect(EFFECT_SMOKE_RING, 0, LVar0, LVar1, LVar2, 0)
    Add(LVar1, 20)
    Add(LVar2, 2)
    PlayEffect(EFFECT_EXPLOSION, 0, LVar0, LVar1, LVar2, 0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BOMB_BLAST)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBombette_Hurt)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBombette_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Call(GetLastElement, LVar1)
            IfFlag(LVar1, DAMAGE_TYPE_SHOCK)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_BurnHurt)
                Wait(20)
                ExecWait(N(EVS_PlayDetonateFX))
                ExecWait(A(EVS_Duplighost_OnDeath))
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BattleBombette_BurnStill)
                Set(LVar2, EXEC_DEATH_NO_SPINNING)
                ExecWait(EVS_Enemy_Death)
                Return
            EndIf
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBombette_BurnHurt)
            SetConst(LVar2, ANIM_BattleBombette_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(N(EVS_PlayDetonateFX))
            ExecWait(A(EVS_Duplighost_OnDeath))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBombette_BurnStill)
            Set(LVar2, EXEC_DEATH_NO_SPINNING)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBombette_BurnHurt)
            SetConst(LVar2, ANIM_BattleBombette_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(N(EVS_PlayDetonateFX))
            ExecWait(A(EVS_Duplighost_OnDeath))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBombette_BurnStill)
            Set(LVar2, EXEC_DEATH_NO_SPINNING)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBombette_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            ExecWait(A(EVS_Duplighost_OnDeath))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBombette_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBombette_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_SHOCK_HIT)
        CaseOrEq(EVENT_SHOCK_DEATH)
            Call(HPBarToCurrent, ACTOR_SELF)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_BurnHurt)
            Wait(20)
            ExecWait(N(EVS_PlayDetonateFX))
            ExecWait(A(EVS_Duplighost_OnDeath))
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBombette_BurnStill)
            Set(LVar2, EXEC_DEATH_NO_SPINNING)
            ExecWait(EVS_Enemy_Death)
            Return
        EndCaseGroup
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBombette_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            ExecWait(A(EVS_Duplighost_OnDeath))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBombette_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBombette_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBombette_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBombette_Run)
            SetConst(LVar2, ANIM_BattleBombette_Hurt)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBombette_Run)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBombette_Hurt)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

#include "common/UnkActorPosFunc.inc.c"

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Wait(10)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 40, 0, 0)
    Call(MoveBattleCamOver, 30)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_Run)
    Call(RunToGoal, ACTOR_SELF, 30, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_Idle)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_Brace)
    Wait(15)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BOMBETTE_BODY_SLAM)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -10, 0, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_BodySlam)
            Call(RunToGoal, ACTOR_SELF, 5, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_Idle)
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 15, 0)
                Set(LVar0, 0)
                Loop(10)
                    Add(LVar0, 72)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EndThread
            Call(AddGoalPos, ACTOR_SELF, -60, 0, 0)
            Call(RunToGoal, ACTOR_SELF, 10, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_Idle)
            Thread
                Call(N(UnkActorPosFunc))
            EndThread
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(20)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Set(LVarA, LVar0)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_BodySlam)
    Call(RunToGoal, ACTOR_SELF, 4, FALSE)
    Call(GetActorVar, ACTOR_SELF, AVAR_Copy_PartnerLevel, LVar9)
    Switch(LVar9)
        CaseEq(PARTNER_RANK_NORMAL)
            Wait(2)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 2, BS_FLAGS1_TRIGGER_EVENTS)
        CaseEq(PARTNER_RANK_SUPER)
            Wait(2)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 3, BS_FLAGS1_TRIGGER_EVENTS)
        CaseEq(PARTNER_RANK_ULTRA)
            Wait(2)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 5, BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_Idle)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 8)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_Backfire2)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.4))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_Backfire1)
            Wait(1)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_Backfire2)
            Add(LVar0, 40)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_Backfire1)
            Wait(1)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_Backfire2)
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_Backfire1)
            Wait(1)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_Backfire2)
            Add(LVar0, 10)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_Backfire1)
            Wait(1)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_Idle)
            Wait(8)
            Call(YieldTurn)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBombette_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

Formation A(BombetteCloneFormation) = {
    ACTOR_BY_POS(NAMESPACE, A(DuplighostSummonPos), 0),
};
