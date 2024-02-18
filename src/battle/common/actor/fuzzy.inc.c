#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Fuzzy.h"
#include "sprite/player.h"
#include "effects.h"

#define NAMESPACE A(fuzzy)

extern s32 N(DefaultAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorParams) {
    DMG_LEECH       = 1,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              95,
    STATUS_KEY_POISON,             90,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             70,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             75,
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
        .targetOffset = { 0, 20 },
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
    .type = ACTOR_TYPE_FUZZY,
    .level = ACTOR_LEVEL_FUZZY,
    .maxHP = 3,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 95,
    .hurricaneChance = 95,
    .spookChance = 95,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 33, 28 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Fuzzy_Idle,
    STATUS_KEY_STONE,     ANIM_Fuzzy_Still,
    STATUS_KEY_SLEEP,     ANIM_Fuzzy_Sleep,
    STATUS_KEY_POISON,    ANIM_Fuzzy_Idle,
    STATUS_KEY_STOP,      ANIM_Fuzzy_Still,
    STATUS_KEY_STATIC,    ANIM_Fuzzy_Idle,
    STATUS_KEY_PARALYZE,  ANIM_Fuzzy_Still,
    STATUS_KEY_DIZZY,     ANIM_Fuzzy_Stunned,
    STATUS_KEY_FEAR,      ANIM_Fuzzy_Stunned,
    STATUS_END,
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
    Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            Call(GetLastElement, LVar0)
            IfFlag(LVar0, DAMAGE_TYPE_SHOCK)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Fuzzy_HurtShock)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Fuzzy_Hurt)
            EndIf
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Burn)
            SetConst(LVar2, ANIM_Fuzzy_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Burn)
            SetConst(LVar2, ANIM_Fuzzy_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_BurnStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_HurtShock)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_HurtShock)
            ExecWait(EVS_Enemy_Knockback)
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Run)
            ExecWait(EVS_Enemy_HopHome)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_HurtShock)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            Call(GetLastElement, LVar0)
            IfFlag(LVar0, DAMAGE_TYPE_SHOCK)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Fuzzy_HurtShock)
                ExecWait(EVS_Enemy_Hit)
                Wait(10)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Fuzzy_HurtShock)
                ExecWait(EVS_Enemy_Death)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Fuzzy_Hurt)
                ExecWait(EVS_Enemy_Hit)
                Wait(10)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Fuzzy_Hurt)
                ExecWait(EVS_Enemy_Death)
            EndIf
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Run)
            SetConst(LVar2, ANIM_Fuzzy_Anim09)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Run)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Run)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

#include "common/SpawnEnemyDrainFX.inc.c"

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 50)
        Set(LVar1, 0)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Goto(100)
    EndIf
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Run)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 50)
    Set(LVar1, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    ExecWait(EVS_Enemy_HopToPos)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Idle)
    Label(100)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Leech)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 9, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
    Wait(5)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 5)
            Set(LVar1, 0)
            Sub(LVar2, 5)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(3.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jump)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 11, FALSE, TRUE, FALSE)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Anim09)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 20)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(3.0))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 15)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(3.0))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Wait(4)
            Wait(5)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(5)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            ExecWait(EVS_Enemy_HopToPos)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
        CaseEq(HIT_RESULT_HIT_STATIC)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAG_STATIC)
                Set(LFlag0, FALSE)
            Else
                Set(LFlag0, TRUE)
            EndIf
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, -3, -12, -15)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(3.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jump)
    Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    IfEq(LFlag0, TRUE)
        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 0, BS_FLAGS1_TRIGGER_EVENTS)
        Return
    EndIf
    Wait(10)
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Leeching)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LEECH)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Bite)
    Wait(21)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Still)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 330)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LEECH)
    Call(SetActorDispOffset, ACTOR_SELF, -3, -2, 0)
    Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
    Wait(1)
    Call(SetActorScale, ACTOR_SELF, Float(0.9), Float(1.2), Float(1.0))
    Wait(1)
    Call(SetActorScale, ACTOR_SELF, Float(0.8), Float(1.3), Float(1.0))
    Wait(1)
    Call(SetActorScale, ACTOR_SELF, Float(0.7), Float(1.4), Float(1.0))
    Wait(1)
    Call(SetActorScale, ACTOR_SELF, Float(0.7), Float(1.5), Float(1.0))
    Wait(2)
    Call(SetActorScale, ACTOR_SELF, Float(0.6), Float(1.6), Float(1.0))
    Wait(10)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, DMG_LEECH, BS_FLAGS1_TRIGGER_EVENTS)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Idle)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(GetLastDamage, ACTOR_PLAYER, LVar3)
            IfNe(LVar3, 0)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEART_BOUNCE)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar1, 10)
                Call(N(SpawnDrainHealthStartFX), LVar0, LVar1, LVar2, LVar3)
                Thread
                    Wait(15)
                    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STAR_BOUNCE_A)
                    Call(N(SpawnDrainHealthContinueFX), LVar0, LVar1, LVar2, LVar3)
                EndThread
                Add(LVar0, 20)
                Add(LVar1, 20)
                PlayEffect(EFFECT_RECOVER, 0, LVar0, LVar1, LVar2, LVar3, 0)
                Call(GetActorHP, ACTOR_SELF, LVar0)
                Add(LVar0, LVar3)
                Call(SetEnemyHP, ACTOR_SELF, LVar0)
            EndIf
            Thread
                Call(SetActorScale, ACTOR_SELF, Float(1.6), Float(0.6), Float(1.0))
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 10, 0)
                Wait(1)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 330)
                Wait(1)
                Call(SetActorScale, ACTOR_SELF, Float(0.7), Float(1.5), Float(1.0))
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 300)
                Wait(1)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 270)
                Wait(1)
                Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(0.7), Float(1.0))
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 240)
                Wait(1)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 210)
                Wait(1)
                Call(SetActorScale, ACTOR_SELF, Float(0.7), Float(1.4), Float(1.0))
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 180)
                Wait(2)
                Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(0.7), Float(1.0))
                Wait(2)
                Call(SetActorScale, ACTOR_SELF, Float(1.2), Float(0.5), Float(1.0))
            EndThread
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Call(SetActorScale, ACTOR_SELF, Float(1.4), Float(0.2), Float(1.0))
            Wait(1)
            Thread
                Wait(1)
                Call(SetActorScale, ACTOR_SELF, Float(1.2), Float(0.5), Float(1.0))
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 150)
                Wait(1)
                Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 120)
                Wait(1)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 90)
                Wait(1)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 60)
                Wait(1)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 30)
                Wait(1)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EndThread
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Wait(5)
            Call(YieldTurn)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            ExecWait(EVS_Enemy_HopToPos)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Idle)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};
