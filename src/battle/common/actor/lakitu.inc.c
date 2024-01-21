#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Spiny.h"
#include "sprite/npc/Lakitu.h"
#include "effects.h"

#define NAMESPACE A(lakitu)

extern ActorBlueprint A(spiny);

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_SPINY_BALL  = 2,
    PRT_SPINY       = 3,
};

enum N(ActorVars) {
    AVAR_SummonCount    = 0,
};

enum N(ActorParams) {
    DMG_SPINY_TOSS  = 3,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Lakitu_Anim01,
    STATUS_KEY_STONE,     ANIM_Lakitu_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Lakitu_Anim08,
    STATUS_KEY_POISON,    ANIM_Lakitu_Anim01,
    STATUS_KEY_STOP,      ANIM_Lakitu_Anim00,
    STATUS_KEY_STATIC,    ANIM_Lakitu_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_Lakitu_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Lakitu_Anim09,
    STATUS_KEY_FEAR,      ANIM_Lakitu_Anim09,
    STATUS_END,
};

s32 N(SpinyBallAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Lakitu_Anim0B,
    STATUS_END,
};

s32 N(SpinyAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Spiny_Anim01,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_MYSTERY,  0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              50,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           50,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
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
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_SPINY,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(SpinyAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_LAKITU,
    .level = ACTOR_LEVEL_LAKITU,
    .maxHP = 12,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 40,
    .airLiftChance = 90,
    .hurricaneChance = 90,
    .spookChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 85,
    .coinReward = 2,
    .size = { 32, 38 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -11, 20 },
    .statusTextOffset = { 10, 34 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_SummonCount, 0)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim03)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(7.0))
    Call(FlyToGoal, ACTOR_SELF, 0, 0, EASING_SIN_OUT)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim01)
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
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lakitu_Anim04)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lakitu_Anim05)
            SetConst(LVar2, ANIM_Lakitu_Anim06)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lakitu_Anim05)
            SetConst(LVar2, ANIM_Lakitu_Anim06)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lakitu_Anim06)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lakitu_Anim04)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lakitu_Anim04)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lakitu_Anim04)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lakitu_Anim04)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lakitu_Anim04)
            ExecWait(EVS_Enemy_Knockback)
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lakitu_Anim04)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lakitu_Anim04)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lakitu_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lakitu_Anim04)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lakitu_Anim04)
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
            SetConst(LVar1, ANIM_Lakitu_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lakitu_Anim03)
            SetConst(LVar2, ANIM_Lakitu_Anim04)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lakitu_Anim04)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Lakitu_Anim04)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_SpinyToss) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim03)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, -20, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim01)
    Call(SetAnimation, ACTOR_SELF, PRT_SPINY_BALL, ANIM_Lakitu_Anim0B)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim12)
    Wait(20)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim13)
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, -3)
        Add(LVar1, 16)
        Add(LVar2, 2)
        PlayEffect(EFFECT_ENERGY_IN_OUT, 0, LVar0, LVar1, LVar2, Float(0.4), 10, 0)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 12)
        Add(LVar2, 0)
        Call(SetPartPos, ACTOR_SELF, PRT_SPINY_BALL, LVar0, LVar1, LVar2)
        Call(SetPartScale, ACTOR_SELF, PRT_SPINY_BALL, Float(0.4), Float(0.4), Float(0.4))
    Else
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, -8)
        Add(LVar1, 40)
        Add(LVar2, 5)
        PlayEffect(EFFECT_ENERGY_IN_OUT, 0, LVar0, LVar1, LVar2, Float(1.0), 10, 0)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 30)
        Add(LVar2, 2)
        Call(SetPartPos, ACTOR_SELF, PRT_SPINY_BALL, LVar0, LVar1, LVar2)
        Call(SetPartScale, ACTOR_SELF, PRT_SPINY_BALL, Float(1.0), Float(1.0), Float(1.0))
    EndIf
    Call(SetPartFlagBits, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Wait(10)
    Thread
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim15)
        Wait(20)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim01)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_SPINY_BALL, ANIM_Lakitu_Anim0C)
    Call(PlaySoundAtPart, ACTOR_SELF, PRT_SPINY_BALL, SOUND_LAKITU_THROW_SPINY)
    Call(SetPartSounds, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_SPINY_BALL, Float(1.0))
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 40)
            Set(LVar1, 0)
            Call(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, 0, LVar2, 20, TRUE)
            Sub(LVar0, 30)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, 0, LVar2, 10, TRUE)
            Sub(LVar0, 20)
            Call(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, 0, LVar2, 5, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Wait(20)
            Call(YieldTurn)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorYaw, ACTOR_SELF, 180)
            ExecWait(N(EVS_ReturnHome))
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_SPINY_BALL, Float(1.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, LVar1, LVar2, 20, TRUE)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SPINY_TOSS, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Thread
                Call(SetPartJumpGravity, ACTOR_SELF, PRT_SPINY_BALL, Float(1.0))
                Call(SetGoalToTarget, ACTOR_SELF)
                Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Sub(LVar0, 40)
                Call(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, 0, LVar2, 20, TRUE)
                Sub(LVar0, 30)
                Call(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, 0, LVar2, 10, TRUE)
                Sub(LVar0, 20)
                Call(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, 0, LVar2, 5, TRUE)
                Call(SetPartFlagBits, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EndThread
            Wait(20)
            Call(YieldTurn)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

Vec3i N(SummonPos) = { NPC_DISPOSE_LOCATION };

Formation N(SpinyFormation) = {
    ACTOR_BY_POS(A(spiny), N(SummonPos), 100, 1),
};

EvtScript N(EVS_Move_SummonSpiny) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SummonEnemy, Ref(N(SpinyFormation)), FALSE)
    Call(CopyStatusEffects, ACTOR_SELF, LVar0)
    Set(LVarB, LVar0)
    Call(SetAnimation, ACTOR_SELF, PRT_SPINY_BALL, ANIM_Lakitu_Anim0B)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim12)
    Wait(20)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim13)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, -3)
        Add(LVar1, 16)
        Add(LVar2, 2)
        PlayEffect(EFFECT_ENERGY_IN_OUT, 0, LVar0, LVar1, LVar2, Float(0.4), 10, 0)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 12)
        Add(LVar2, 0)
        Call(SetPartPos, ACTOR_SELF, PRT_SPINY_BALL, LVar0, LVar1, LVar2)
        Call(SetPartScale, ACTOR_SELF, PRT_SPINY_BALL, Float(0.4), Float(0.4), Float(0.4))
        Call(SetPartScale, ACTOR_SELF, PRT_SPINY, Float(0.4), Float(0.4), Float(0.4))
    Else
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, -8)
        Add(LVar1, 40)
        Add(LVar2, 5)
        PlayEffect(EFFECT_ENERGY_IN_OUT, 0, LVar0, LVar1, LVar2, Float(1.0), 10, 0)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 30)
        Add(LVar2, 2)
        Call(SetPartPos, ACTOR_SELF, PRT_SPINY_BALL, LVar0, LVar1, LVar2)
        Call(SetPartScale, ACTOR_SELF, PRT_SPINY_BALL, Float(1.0), Float(1.0), Float(1.0))
        Call(SetPartScale, ACTOR_SELF, PRT_SPINY, Float(1.0), Float(1.0), Float(1.0))
    EndIf
    Call(SetPartFlagBits, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Wait(10)
    Thread
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim15)
        Wait(20)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim01)
    EndThread
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(PlaySoundAtPart, ACTOR_SELF, PRT_SPINY_BALL, SOUND_LAKITU_THROW_SPINY)
    Call(SetPartSounds, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    Call(SetAnimation, ACTOR_SELF, PRT_SPINY_BALL, ANIM_Lakitu_Anim0C)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_SPINY_BALL, Float(1.6))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 40)
    Call(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, 0, LVar2, 12, TRUE)
    Call(SetPartPos, ACTOR_SELF, PRT_SPINY, LVar0, 0, LVar2)
    Sub(LVar0, 30)
    Thread
        Call(SetPartRotationOffset, ACTOR_SELF, PRT_SPINY, 0, 16, 0)
        Set(LVar0, 0)
        Set(LVar1, 0)
        Set(LFlag0, FALSE)
        Loop(12)
            Add(LVar0, 30)
            Call(SetPartRotation, ACTOR_SELF, PRT_SPINY, 0, 0, LVar0)
            Add(LVar1, 1)
            IfGe(LVar1, 6)
                IfEq(LFlag0, TRUE)
                    Call(SetPartFlagBits, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    Call(SetPartFlagBits, ACTOR_SELF, PRT_SPINY, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    Set(LFlag0, FALSE)
                Else
                    Call(SetPartFlagBits, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    Call(SetPartFlagBits, ACTOR_SELF, PRT_SPINY, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    Set(LFlag0, TRUE)
                EndIf
            EndIf
            Wait(1)
        EndLoop
    EndThread
    Thread
        Call(SetPartJumpGravity, ACTOR_SELF, PRT_SPINY, Float(1.3))
        Call(JumpPartTo, ACTOR_SELF, PRT_SPINY, LVar0, 0, LVar2, 12, TRUE)
    EndThread
    Wait(1)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_SPINY_BALL, Float(1.3))
    Call(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, 0, LVar2, 12, TRUE)
    PlayEffect(EFFECT_LANDING_DUST, 1, LVar0, 0, LVar2, 0, 0)
    Call(GetPartOffset, ACTOR_SELF, PRT_SPINY_BALL, LVar0, LVar1, LVar2)
    Call(SetActorPos, LVarB, LVar0, LVar1, LVar2)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_SPINY, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(SetAnimation, LVarB, 1, ANIM_Spiny_Anim01)
    Wait(20)
    Call(SetAnimation, LVarB, 1, ANIM_Spiny_Anim04)
    Call(SetGoalToIndex, LVarB, LVarA)
    Call(GetGoalPos, LVarB, LVar0, LVar1, LVar2)
    Call(GetActorPos, LVarB, LVar3, LVar4, LVar5)
    IfLt(LVar0, LVar3)
        Call(SetActorYaw, LVarB, 0)
    Else
        Call(SetActorYaw, LVarB, 180)
    EndIf
    Call(SetActorSpeed, LVarB, Float(4.0))
    Call(RunToGoal, LVarB, 0, FALSE)
    Call(SetAnimation, LVarB, 1, ANIM_Spiny_Anim01)
    Call(SetActorYaw, LVarB, 0)
    Call(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    Call(ForceHomePos, LVarB, LVar0, LVar1, LVar2)
    Call(HPBarToHome, LVarB)
    Call(GetActorVar, ACTOR_SELF, AVAR_SummonCount, LVar0)
    Add(LVar0, 1)
    Call(SetActorVar, ACTOR_SELF, AVAR_SummonCount, LVar0)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_GetAvailableColumn) = {
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar5)
        Call(GetIndexFromHome, LVar0, LVar5)
        Mod(LVar5, 4)
        Switch(LVar5)
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

EvtScript N(EVS_CountActiveSummoners) = {
    Set(LVar9, 0)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetOriginalActorType, LVar0, LVar2)
        Switch(LVar2)
            CaseEq(ACTOR_TYPE_LAKITU)
                Call(GetStatusFlags, LVar0, LVar3)
                IfNotFlag(LVar3, STATUS_FLAGS_IMMOBILIZED)
                    Call(GetActorVar, LVar0, AVAR_SummonCount, LVar3)
                    IfLt(LVar3, 3)
                        Add(LVar9, 1)
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
    Call(GetActorVar, ACTOR_SELF, AVAR_SummonCount, LVar0)
    IfGe(LVar0, 3)
        ExecWait(N(EVS_Attack_SpinyToss))
        Return
    EndIf
    ExecWait(N(EVS_GetAvailableColumn))
    IfEq(LVarA, -1)
        ExecWait(N(EVS_Attack_SpinyToss))
        Return
    EndIf
    ExecWait(N(EVS_CountActiveSummoners))
    Switch(LVar9)
        CaseEq(1)
            Call(RandInt, 1000, LVar0)
            IfLt(LVar0, 500)
                ExecWait(N(EVS_Move_SummonSpiny))
                Return
            EndIf
        CaseEq(2)
            Call(RandInt, 1000, LVar0)
            IfLt(LVar0, 250)
                ExecWait(N(EVS_Move_SummonSpiny))
                Return
            EndIf
        CaseEq(3)
            Call(RandInt, 1000, LVar0)
            IfLt(LVar0, 150)
                ExecWait(N(EVS_Move_SummonSpiny))
                Return
            EndIf
    EndSwitch
    ExecWait(N(EVS_Attack_SpinyToss))
    Return
    End
};
