#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/LargePiranha.h"

#define NAMESPACE A(frost_piranha)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Attack_Bite);
extern EvtScript N(EVS_Attack_FrostBreath);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorParams) {
    DMG_BITE        = 4,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_LargePiranha_Frost_Anim01,
    STATUS_KEY_STONE,     ANIM_LargePiranha_Frost_Anim00,
    STATUS_KEY_SLEEP,     ANIM_LargePiranha_Frost_Anim00,
    STATUS_KEY_POISON,    ANIM_LargePiranha_Frost_Anim01,
    STATUS_KEY_STOP,      ANIM_LargePiranha_Frost_Anim00,
    STATUS_KEY_STATIC,    ANIM_LargePiranha_Frost_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_LargePiranha_Frost_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_LargePiranha_Frost_Anim00,
    STATUS_KEY_DIZZY,     ANIM_LargePiranha_Frost_Anim0F,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_FIRE,    -2,
    ELEMENT_ICE,     99,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              95,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              50,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               85,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          1,
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
        .targetOffset = { -15, 50 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 3, -14 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_FROST_PIRANHA,
    .level = ACTOR_LEVEL_FROST_PIRANHA,
    .maxHP = 10,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 70,
    .airLiftChance = 20,
    .hurricaneChance = 20,
    .spookChance = 20,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 60, 52 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -22, 32 },
    .statusTextOffset = { 1, 44 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Return
    End
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(EVS_Idle) = {
    Label(0)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_DIZZY)
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -27, 33)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 5, -11)
            Call(N(SetAbsoluteStatusOffsets), -37, 9, -7, 31)
        Else
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -15, 50)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 3, -14)
            Call(N(SetAbsoluteStatusOffsets), -22, 32, 1, 44)
        EndIf
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim03)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim01)
    Call(SetActorYaw, ACTOR_SELF, 0)
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
            SetConst(LVar1, ANIM_LargePiranha_Frost_Anim0E)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LargePiranha_Frost_Anim10)
            SetConst(LVar2, ANIM_LargePiranha_Frost_Anim11)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LargePiranha_Frost_Anim10)
            SetConst(LVar2, ANIM_LargePiranha_Frost_Anim11)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LargePiranha_Frost_Anim11)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LargePiranha_Frost_Anim0E)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LargePiranha_Frost_Anim0E)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LargePiranha_Frost_Anim0E)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LargePiranha_Frost_Anim0E)
            ExecWait(EVS_Enemy_ShockHit)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LargePiranha_Frost_Anim0E)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LargePiranha_Frost_Anim0E)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LargePiranha_Frost_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LargePiranha_Frost_Anim0E)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LargePiranha_Frost_Anim0E)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LargePiranha_Frost_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LargePiranha_Frost_Anim03)
            SetConst(LVar2, ANIM_LargePiranha_Frost_Anim0E)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LargePiranha_Frost_Anim03)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_LargePiranha_Frost_Anim03)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        ExecWait(N(EVS_Attack_Bite))
        Return
    EndIf
    Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
    IfFlag(LVar0, STATUS_FLAG_FROZEN)
        ExecWait(N(EVS_Attack_Bite))
        Return
    EndIf
    Call(RandInt, 1000, LVar0)
    IfLt(LVar0, 250)
        ExecWait(N(EVS_Attack_FrostBreath))
    Else
        ExecWait(N(EVS_Attack_Bite))
    EndIf
    Return
    End
};

EvtScript N(EVS_Attack_Bite) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim18)
        Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, true)
        Wait(8)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 27)
        Set(LVar1, 0)
        Set(LVar3, LVar0)
        Set(LVar4, LVar1)
        Set(LVar5, LVar2)
        Call(GetActorPos, ACTOR_PLAYER, LVar6, LVar7, LVar8)
        Add(LVar3, LVar6)
        Add(LVar4, LVar7)
        Add(LVar5, LVar8)
        Div(LVar3, 2)
        Div(LVar4, 2)
        Div(LVar5, 2)
        Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
        Call(SetBattleCamTarget, LVar3, LVar4, LVar5)
        Call(SetBattleCamDist, 300)
        Call(SetBattleCamOffsetY, 40)
        Wait(20)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, false)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim17)
        Wait(8)
    Else
        Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim03)
        Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim03)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_SHRINK)
            Add(LVar0, 10)
        Else
            Add(LVar0, 27)
        EndIf
        Set(LVar1, 0)
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(RunToGoal, ACTOR_SELF, 0, false)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim01)
    EndIf
    Thread
        Wait(8)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PIRANHA_BITE)
    EndThread
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim05)
            Wait(10)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim06)
            Wait(6)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim07)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(14)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(GetBattlePhase, LVar0)
            IfEq(LVar0, PHASE_FIRST_STRIKE)
                Call(SetActorSpeed, ACTOR_SELF, Float(7.0))
                Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, true)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim18)
                Wait(10)
                Call(SetGoalToHome, ACTOR_SELF)
                Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim17)
                Wait(10)
                Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, false)
            Else
                Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(2.0))
                Call(SetActorSpeed, ACTOR_SELF, Float(7.0))
                Call(SetActorYaw, ACTOR_SELF, 180)
                Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
                ExecWait(N(EVS_ReturnHome))
                Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
                Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
            EndIf
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim05)
    Wait(10)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim06)
    Wait(1)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_BITE, BS_FLAGS1_TRIGGER_EVENTS)
    Set(LVarF, LVar0)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Wait(10)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim07)
            Wait(20)
            Call(YieldTurn)
            Call(GetBattlePhase, LVar0)
            IfEq(LVar0, PHASE_FIRST_STRIKE)
                Call(SetActorSpeed, ACTOR_SELF, Float(7.0))
                Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, true)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim18)
                Wait(10)
                Call(SetGoalToHome, ACTOR_SELF)
                Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim17)
                Wait(10)
                Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, false)
            Else
                Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
                ExecWait(N(EVS_ReturnHome))
            EndIf
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

#include "common/UnkEffect6FFunc.inc.c"

EvtScript N(EVS_Attack_FrostBreath) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim03)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim03)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        Add(LVar0, 20)
    Else
        Add(LVar0, 50)
    EndIf
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim01)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim0B)
    Wait(11)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PIRANHA_BREATH)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        Add(LVar0, 12)
        Set(LVar1, 5)
        SetF(LVar3, Float(0.4))
    Else
        Add(LVar0, 32)
        Set(LVar1, 13)
        SetF(LVar3, Float(1.0))
    EndIf
    Call(N(UnkEffect6FFunc), LVar2, LVar0, LVar1, LVar2, LVar3, 30, 120, 0, 120)
    Wait(1)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim0C)
    Wait(5)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_ICE, STATUS_FLAG_FROZEN, 1, BS_FLAGS1_INCLUDE_POWER_UPS) //@bug malformed status word
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Wait(10)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim0D)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(14)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(2.0))
            Call(SetActorSpeed, ACTOR_SELF, Float(7.0))
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            ExecWait(N(EVS_ReturnHome))
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_ICE | DAMAGE_TYPE_STATUS_ALWAYS_HITS, SUPPRESS_EVENT_ALL, DMG_STATUS_IGNORE_RES(STATUS_FLAG_FROZEN, 2), 0, BS_FLAGS1_TRIGGER_EVENTS)
    Set(LVarF, LVar0)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Wait(10)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Frost_Anim0D)
            Wait(20)
            Call(YieldTurn)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};
