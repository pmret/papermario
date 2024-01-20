#include "../area.h"
#include "sprite/npc/BattleBowser.h"

#define NAMESPACE A(unused_bowser)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_OnHit);
extern EvtScript N(EVS_OnDeath);
extern EvtScript N(EVS_UseAttack);
extern EvtScript N(EVS_UseDrainingShockwave);
extern EvtScript N(EVS_Attack_FireBreath);
extern EvtScript N(EVS_Attack_ClawSwipe);
extern EvtScript N(EVS_Attack_BodySlam);
extern EvtScript N(EVS_ReturnHome);
extern EvtScript N(EVS_Recover);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

enum N(ActorVars) {
    AVAR_TurnCount              = 1,
    AVAR_TurnsSinceShockwave    = 2,
    AVAR_DamageMultiplier       = 3,
};

enum N(ActorParams) {
    DMG_CLAW_SWIPE      = 6,
    DMG_BODY_SLAM       = 6,
    DMG_FIRE_BREATH     = 8,
    DMG_SHOCKWAVE       = 4,
    DMG_SHOCKWAVE_P     = 3,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleBowser_Idle,
    STATUS_KEY_STONE,     ANIM_BattleBowser_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleBowser_Idle,
    STATUS_KEY_POISON,    ANIM_BattleBowser_Idle,
    STATUS_KEY_STOP,      ANIM_BattleBowser_Still,
    STATUS_KEY_STATIC,    ANIM_BattleBowser_Still,
    STATUS_KEY_PARALYZE,  ANIM_BattleBowser_Still,
    STATUS_KEY_PARALYZE,  ANIM_BattleBowser_Still,
    STATUS_KEY_DIZZY,     ANIM_BattleBowser_Idle,
    STATUS_KEY_DIZZY,     ANIM_BattleBowser_Idle,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              30,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              30,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           30,
    STATUS_KEY_SHRINK,             50,
    STATUS_KEY_STOP,               30,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -18, 72 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = ELEMENT_FIRE,
        .projectileTargetOffset = { 0, -8 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_HALLWAY_BOWSER,
    .level = ACTOR_LEVEL_HALLWAY_BOWSER,
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
    .spinSmashReq = 4,
    .powerBounceChance = 65,
    .coinReward = 0,
    .size = { 80, 82 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -40, 67 },
    .statusTextOffset = { 10, 60 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_TurnCount, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_DamageMultiplier, 1)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetLastElement, LVarE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            Set(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_OnHit))
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            Set(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_OnHit))
        CaseOrEq(EVENT_BURN_DEATH)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_OnDeath))
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            Set(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_OnHit))
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_OnDeath))
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_OnDeath))
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Set(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_OnHit))
        EndCaseGroup
        CaseEq(EVENT_SPIKE_TAUNT)
        CaseEq(EVENT_DEATH)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(N(EVS_OnDeath))
            Return
        CaseEq(EVENT_END_FIRST_STRIKE)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBowser_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_30)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(1000)
        CaseDefault
            SetConst(LVar1, ANIM_BattleBowser_Hurt)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
            Wait(20)
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_OnHit) = {
    SetConst(LVar0, PRT_MAIN)
    ExecWait(EVS_Enemy_Hit)
    Return
    End
};

EvtScript N(EVS_OnDeath) = {
    SetConst(LVar0, PRT_MAIN)
    ExecWait(EVS_Enemy_Hit)
    SetConst(LVar0, PRT_MAIN)
    ExecWait(EVS_Enemy_Death)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    // only use regular attacks for the first few turns
    Call(GetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar0)
    Add(LVar0, 1)
    IfLt(LVar0, 5)
        Call(SetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar0)
        Call(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, 5)
        ExecWait(N(EVS_UseAttack))
        Return
    EndIf
    // increment shockwave turn counter
    Call(GetActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, LVar0)
    Add(LVar0, 1)
    Call(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, LVar0)
    // use normal attack if shockwave was used recently
    IfLt(LVar0, 4)
        ExecWait(N(EVS_UseAttack))
        Return
    EndIf
    // use shockwave if it hasn't been used recently
    IfGt(LVar0, 6)
        Call(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, 0)
        ExecWait(N(EVS_UseDrainingShockwave))
        Return
    EndIf
    // use shockwave if HP is low, even if it hasn't met the normal time threshold
    Call(GetActorHP, ACTOR_SELF, LVar0)
    IfLt(LVar0, 8)
        Call(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, 0)
        ExecWait(N(EVS_UseDrainingShockwave))
        Return
    EndIf
    // fallback to using a regular attack
    ExecWait(N(EVS_UseAttack))
    Return
    End
};

EvtScript N(EVS_UseAttack) = {
    Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
    IfFlag(LVar0, STATUS_FLAG_STATIC)
        ExecWait(N(EVS_Attack_FireBreath))
        Return
    EndIf
    Call(RandInt, 2, LVar0)
    Switch(LVar0)
        CaseEq(0)
            ExecWait(N(EVS_Attack_ClawSwipe))
            Return
        CaseEq(1)
            ExecWait(N(EVS_Attack_BodySlam))
            Return
        CaseDefault
            ExecWait(N(EVS_Attack_FireBreath))
            Return
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Attack_ClawSwipe) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(SetBattleCamZoom, 150)
    Call(SetBattleCamOffsetZ, 0)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 40)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Walk)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 40, 0, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_RearUpMock)
    Wait(25)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Swipe)
    Wait(3)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Wait(20)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Tantrum)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                Wait(50)
            Else
                Wait(30)
            EndIf
            Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
            Set(LVar1, ANIM_BattleBowser_Walk)
            ExecWait(N(EVS_ReturnHome))
            Return
        EndCaseGroup
        CaseDefault
    EndSwitch
    Call(GetActorVar, ACTOR_SELF, AVAR_DamageMultiplier, LVar0)
    Mul(LVar0, DMG_CLAW_SWIPE)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(HIT_RESULT_10)
            Wait(30)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Mock)
            Wait(45)
            IfEq(LVarF, HIT_RESULT_10)
                Return
            EndIf
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
            Set(LVar1, ANIM_BattleBowser_Walk)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_BodySlam) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(SetBattleCamZoom, 150)
    Call(SetBattleCamOffsetZ, 0)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 40)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Walk)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 80, 0, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
    Wait(15)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PreJump)
    Wait(3)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Jump)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 28, FALSE, TRUE, FALSE)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(3.0))
            EndThread
            Sub(LVar0, 35)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 14, FALSE, TRUE, FALSE)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(2.0))
            EndThread
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostJump)
            Wait(3)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            Wait(25)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
            Set(LVar1, ANIM_BattleBowser_Walk)
            ExecWait(N(EVS_ReturnHome))
            Return
        EndCaseGroup
        CaseDefault
    EndSwitch
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(JumpToGoal, ACTOR_SELF, 24, FALSE, TRUE, FALSE)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 4, Float(3.0))
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Land)
    Call(GetActorVar, ACTOR_SELF, AVAR_DamageMultiplier, LVar0)
    Mul(LVar0, DMG_BODY_SLAM)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(HIT_RESULT_10)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 4, Float(3.0))
            EndThread
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostJump)
            Wait(3)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            Wait(20)
            IfEq(LVarF, HIT_RESULT_10)
                Return
            EndIf
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
            Set(LVar1, ANIM_BattleBowser_Walk)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_FireBreath) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(SetBattleCamZoom, 150)
    Call(SetBattleCamOffsetZ, 0)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 40)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PreFireBreath)
    Wait(35)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_FireBreathStill)
    Wait(10)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 70)
    Add(LVar1, 35)
    Add(LVar2, 10)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Sub(LVar3, 40)
    Set(LVar4, 20)
    PlayEffect(EFFECT_FIRE_BREATH, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 50, 1, 24, 0)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 100)
    Wait(20)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_FireBreathLoop)
    Wait(30)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostFireBreath)
            Wait(15)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            Wait(30)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Tantrum)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(30)
            Return
        EndCaseGroup
        CaseDefault
    EndSwitch
    Call(GetActorVar, ACTOR_SELF, AVAR_DamageMultiplier, LVar0)
    Mul(LVar0, DMG_FIRE_BREATH)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_FIRE, SUPPRESS_EVENT_ALL, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(HIT_RESULT_10)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostFireBreath)
            Wait(15)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            Wait(30)
            IfEq(LVarF, HIT_RESULT_10)
                Return
            EndIf
        EndCaseGroup
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

#include "common/FadeBackgroundDarken.inc.c"
#include "common/FadeBackgroundLighten.inc.c"

EvtScript N(EVS_UseDrainingShockwave) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_13)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 30)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Brandish)
    Wait(10)
    Call(N(FadeBackgroundDarken))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 15)
    Sub(LVar2, 3)
    PlayEffect(EFFECT_LIGHT_RAYS, 2, LVar0, 90, LVar2, Float(1.0), LVarF, 0)
    Sub(LVar2, 3)
    PlayEffect(EFFECT_BULB_GLOW, 2, LVar0, 90, LVar2, Float(1.0), LVarE, 0)
    Wait(16)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 45)
    Wait(19)
    Call(RemoveEffect, LVarF)
    Call(RemoveEffect, LVarE)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 13)
    Set(LVar1, 55)
    PlayEffect(EFFECT_ENERGY_SHOCKWAVE, 0, LVar0, LVar1, LVar2, Float(1.0), 60, 0)
    Thread
        Call(N(FadeBackgroundLighten))
    EndThread
    Wait(8)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseEq(HIT_RESULT_MISS)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            Wait(15)
            ExecWait(N(EVS_Recover))
            Wait(30)
            Return
        CaseEq(HIT_RESULT_LUCKY)
            Call(FreezeBattleState, TRUE)
            Thread
                Wait(2)
                Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                Call(SetGoalToTarget, ACTOR_SELF)
                Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_COSMIC, 0, 0, DMG_SHOCKWAVE_P, BS_FLAGS1_TRIGGER_EVENTS)
                Call(FreezeBattleState, FALSE)
            EndThread
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            Wait(15)
            ExecWait(N(EVS_Recover))
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(30)
            Return
        CaseDefault
    EndSwitch
    Call(FreezeBattleState, TRUE)
    Thread
        Wait(2)
        Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_COSMIC, 0, 0, DMG_SHOCKWAVE_P, BS_FLAGS1_TRIGGER_EVENTS)
        Call(FreezeBattleState, FALSE)
    EndThread
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_COSMIC, 0, STATUS_FLAG_POISON, DMG_SHOCKWAVE, BS_FLAGS1_TRIGGER_EVENTS)
    Call(RemovePlayerBuffs, PLAYER_BUFF_JUMP_CHARGE | PLAYER_BUFF_HAMMER_CHARGE | PLAYER_BUFF_STONE | PLAYER_BUFF_HUSTLE | PLAYER_BUFF_STATIC | PLAYER_BUFF_TRANSPARENT | PLAYER_BUFF_CLOUD_NINE | PLAYER_BUFF_TURBO_CHARGE | PLAYER_BUFF_WATER_BLOCK | PLAYER_BUFF_PARTNER_GLOWING | 0xFFEFC04)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(HIT_RESULT_10)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            Wait(15)
            ExecWait(N(EVS_Recover))
            IfEq(LVarF, HIT_RESULT_10)
                Return
            EndIf
        EndCaseGroup
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Set(LVar0, 1)
    Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVarD, LVarE, LVarF)
    IfLt(LVarA, LVarD)
        Call(SetActorYaw, ACTOR_SELF, 180)
    Else
        Call(SetActorYaw, ACTOR_SELF, 0)
    EndIf
    Call(GetDist2D, LVar9, LVarA, LVarC, LVarD, LVarF)
    IfGe(LVar9, Float(4.0))
        Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    EndIf
    Call(SetActorYaw, ACTOR_SELF, 0)
    Return
    End
};

EvtScript N(EVS_Recover) = {
    Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    Add(LVar2, 60)
    PlayEffect(EFFECT_SPARKLES, 0, LVar1, LVar2, LVar3, Float(1.0), 0)
    Add(LVar1, 30)
    Add(LVar2, 20)
    PlayEffect(EFFECT_RECOVER, 0, LVar1, LVar2, LVar3, 10, 0)
    Call(GetActorHP, ACTOR_SELF, LVar0)
    Add(LVar0, 10)
    Call(GetEnemyMaxHP, ACTOR_SELF, LVar1)
    IfGt(LVar0, LVar1)
        Set(LVar0, LVar1)
    EndIf
    Call(SetEnemyHP, ACTOR_SELF, LVar0)
    Call(GetActorVar, ACTOR_SELF, AVAR_DamageMultiplier, LVar0)
    Add(LVar0, 1)
    Call(SetActorVar, ACTOR_SELF, AVAR_DamageMultiplier, LVar0)
    Return
    End
};
