#include "../area.h"
#include "sprite/npc/BattleLakilester.h"

#define NAMESPACE A(spike)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_SPINY_BALL  = 2,
};

enum N(ActorParams) {
    DMG_SPINY_TOSS  = 4,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleLakilester_Idle,
    STATUS_KEY_STONE,     ANIM_BattleLakilester_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleLakilester_Block,
    STATUS_KEY_POISON,    ANIM_BattleLakilester_Idle,
    STATUS_KEY_STOP,      ANIM_BattleLakilester_Still,
    STATUS_KEY_STATIC,    ANIM_BattleLakilester_Idle,
    STATUS_KEY_PARALYZE,  ANIM_BattleLakilester_Still,
    STATUS_KEY_DIZZY,     ANIM_BattleLakilester_Injured,
    STATUS_KEY_FEAR,      ANIM_BattleLakilester_Idle,
    STATUS_END,
};

s32 N(SpinyBallAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleLakilester_Spiny,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              40,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              50,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           40,
    STATUS_KEY_SHRINK,             50,
    STATUS_KEY_STOP,               50,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 35 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -13 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_SPINY_BALL,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(SpinyBallAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_SPIKE,
    .level = ACTOR_LEVEL_SPIKE,
    .maxHP = 50,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 32, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -14, 20 },
    .statusTextOffset = { 6, 32 },
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

EvtScript N(EVS_ReturnHome) = {
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleLakilester_Run)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(7.0))
    Call(FlyToGoal, ACTOR_SELF, 0, 0, EASING_SIN_OUT)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleLakilester_Idle)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_BurnHurt)
            SetConst(LVar2, ANIM_BattleLakilester_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_BurnHurt)
            SetConst(LVar2, ANIM_BattleLakilester_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_BurnStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Dead)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Dead)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Dead)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
            Call(SetActorPos, ACTOR_SELF, 20, 0, 0)
            Call(HPBarToCurrent, ACTOR_SELF)
        CaseEq(EVENT_END_FIRST_STRIKE)
            ExecWait(N(EVS_ReturnHome))
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Run)
            SetConst(LVar2, ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleLakilester_Hurt)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Attack_SpinyToss) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleLakilester_Run)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, 20, 30, LVar2)
    Call(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleLakilester_Idle)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        Add(LVar0, -1)
        Add(LVar1, 4)
        Add(LVar2, 2)
        Call(SetPartScale, ACTOR_SELF, PRT_SPINY_BALL, Float(0.4), Float(0.4), Float(0.4))
    Else
        Add(LVar0, -3)
        Add(LVar1, 10)
        Add(LVar2, 5)
        Call(SetPartScale, ACTOR_SELF, PRT_SPINY_BALL, Float(1.0), Float(1.0), Float(1.0))
    EndIf
    Call(SetPartPos, ACTOR_SELF, PRT_SPINY_BALL, LVar0, LVar1, LVar2)
    Wait(1)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_PART_FLAG_INVISIBLE, false)
    Call(SetAnimation, ACTOR_SELF, PRT_SPINY_BALL, ANIM_BattleLakilester_Spiny)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleLakilester_LiftSpiny)
    Loop(4)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_SHRINK)
            AddF(LVar1, Float(2.4))
        Else
            Add(LVar1, 6)
        EndIf
        Call(SetPartPos, ACTOR_SELF, PRT_SPINY_BALL, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        Add(LVar0, -3)
        Add(LVar1, 16)
        Add(LVar2, 2)
        SetF(LVar3, Float(0.4))
    Else
        Add(LVar0, -8)
        Add(LVar1, 40)
        Add(LVar2, 5)
        SetF(LVar3, Float(1.0))
    EndIf
    PlayEffect(EFFECT_ENERGY_IN_OUT, 0, LVar0, LVar1, LVar2, LVar3, 30, 0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPIKE_SUMMON_SPINY)
    Thread
        Loop(15)
            Call(SetActorDispOffset, ACTOR_SELF, 1, 0, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_SPINY_BALL, 1, 0, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
            Call(SetPartDispOffset, ACTOR_SELF, PRT_SPINY_BALL, -1, 0, 0)
            Wait(1)
        EndLoop
        Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
        Call(SetPartDispOffset, ACTOR_SELF, PRT_SPINY_BALL, 0, 0, 0)
    EndThread
    Call(SetGoalToTarget, ACTOR_SELF)
    Wait(10)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleLakilester_HoldSpiny)
    Wait(10)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleLakilester_StrainHoldSpiny)
    Wait(10)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleLakilester_ThrowSpiny)
    Wait(3)
    Call(PlaySoundAtPart, ACTOR_SELF, PRT_SPINY_BALL, SOUND_SPIKE_THROW_SPINY)
    Call(SetPartSounds, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetAnimation, ACTOR_SELF, PRT_SPINY_BALL, ANIM_BattleLakilester_SpinySpin)
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_SPINY_BALL, Float(1.5))
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(RandInt, 100, LVar3)
            Sub(LVar3, 50)
            Add(LVar0, LVar3)
            Call(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, 0, LVar2, 20, true)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Thread
                Add(LVar0, -50)
                Call(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, 0, LVar2, 15, true)
                Call(SetPartFlagBits, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_PART_FLAG_INVISIBLE, true)
            EndThread
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(15)
            Call(YieldTurn)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorYaw, ACTOR_SELF, 180)
            ExecWait(N(EVS_ReturnHome))
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_SPINY_BALL, ANIM_BattleLakilester_SpinySpin)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_SPINY_BALL, Float(1.5))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, LVar1, LVar2, 20, true)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Thread
        Add(LVar0, -50)
        Call(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, 0, LVar2, 15, true)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_PART_FLAG_INVISIBLE, true)
    EndThread
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SPINY_TOSS, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Wait(15)
            Call(YieldTurn)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    ExecWait(N(EVS_Attack_SpinyToss))
    Return
    End
};
