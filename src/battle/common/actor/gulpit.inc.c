#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/Gulpit.h"

#define NAMESPACE A(gulpit)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_BIG_ROCK    = 2,
    PRT_SMALL_ROCK  = 3,
};

enum N(ActorVars) {
    AVAR_Rock_Type  = 0, // from gulpit rock
};

enum N(ActorParams) {
    DMG_LICK        = 2,
    DMG_SMALL_ROCK  = 5,
    DMG_BIG_ROCK    = 7,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Gulpit_Anim01,
    STATUS_KEY_STONE,     ANIM_Gulpit_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Gulpit_Anim0F,
    STATUS_KEY_POISON,    ANIM_Gulpit_Anim01,
    STATUS_KEY_STOP,      ANIM_Gulpit_Anim00,
    STATUS_KEY_STATIC,    ANIM_Gulpit_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_Gulpit_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Gulpit_Anim0E,
    STATUS_KEY_FEAR,      ANIM_Gulpit_Anim0E,
    STATUS_END,
};

s32 N(BigRockAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Gulpit_Anim10,
    STATUS_END,
};

s32 N(SmallRockAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Gulpit_Anim12,
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
    STATUS_KEY_POISON,             80,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             10,
    STATUS_KEY_PARALYZE,           80,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               85,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
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
        .targetOffset = { -7, 48 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -3, -23 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_BIG_ROCK,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(BigRockAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_SMALL_ROCK,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(SmallRockAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GULPIT,
    .level = ACTOR_LEVEL_GULPIT,
    .maxHP = 12,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 60,
    .airLiftChance = 50,
    .hurricaneChance = 50,
    .spookChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 53, 50 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -3, 37 },
    .statusTextOffset = { 10, 45 },
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
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_Gulpit_Anim03)
    ExecWait(EVS_Enemy_ReturnHome)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim01)
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
            SetConst(LVar1, ANIM_Gulpit_Anim0B)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Gulpit_Anim0C)
            SetConst(LVar2, ANIM_Gulpit_Anim0D)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Gulpit_Anim0C)
            SetConst(LVar2, ANIM_Gulpit_Anim0D)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Gulpit_Anim0D)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Gulpit_Anim0B)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Gulpit_Anim0B)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Gulpit_Anim0B)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Gulpit_Anim0B)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Gulpit_Anim0B)
            ExecWait(EVS_Enemy_Knockback)
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Gulpit_Anim0B)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Gulpit_Anim0B)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Gulpit_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Gulpit_Anim0B)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Gulpit_Anim0B)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Gulpit_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Gulpit_Anim03)
            SetConst(LVar2, ANIM_Gulpit_Anim0B)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Gulpit_Anim03)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Gulpit_Anim03)
            ExecWait(EVS_Enemy_BlowAway)
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_Lick) = {
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
        Add(LVar0, 80)
        Set(LVar1, 0)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EndIf
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim03)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(AddGoalPos, ACTOR_SELF, 10, 0, 0)
    Else
        Call(AddGoalPos, ACTOR_SELF, 20, 0, 0)
    EndIf
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim01)
    Wait(10)
    Thread
        Wait(3)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GULPIT_LICK)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim04)
    Wait(9)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(15)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            ExecWait(N(EVS_ReturnHome))
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_LICK, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Wait(10)
            Call(YieldTurn)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_SpitRock) = {
    Set(LVarA, LVar0)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(GetActorPos, LVarA, LVar0, LVar1, LVar2)
    Add(LVar0, 20)
    Sub(LVar2, 1)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim02)
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim01)
    Wait(10)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GULPIT_LICK)
    Call(GetActorVar, LVarA, AVAR_Rock_Type, LVar0)
    Set(LVarB, LVar0)
    Switch(LVarB)
        CaseEq(0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim05)
            Wait(3)
            Call(RemoveActor, LVarA)
            Wait(20)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim06)
            Wait(15)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim07)
            Set(LVarA, 2)
        CaseEq(1)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim08)
            Wait(3)
            Call(RemoveActor, LVarA)
            Wait(20)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim09)
            Wait(15)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim0A)
            Set(LVarA, 3)
    EndSwitch
    Call(SetPartSounds, ACTOR_SELF, LVarA, ACTOR_SOUND_JUMP, SOUND_LIGHT_THROW, SOUND_NONE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVar9, LVar0)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetPartFlagBits, ACTOR_SELF, LVarA, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, 20)
            Add(LVar2, 2)
            Call(SetPartPos, ACTOR_SELF, LVarA, LVar0, LVar1, LVar2)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -100, 0, 5)
            Call(SetPartMoveSpeed, ACTOR_SELF, LVarA, Float(14.0))
            Call(SetPartJumpGravity, ACTOR_SELF, LVarA, Float(0.01))
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpPartTo, ACTOR_SELF, LVarA, LVar0, LVar1, LVar2, 0, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, LVarA, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            IfEq(LVar9, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(15)
            Call(YieldTurn)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            ExecWait(N(EVS_ReturnHome))
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetPartFlagBits, ACTOR_SELF, LVarA, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    Add(LVar2, 2)
    Call(SetPartPos, ACTOR_SELF, LVarA, LVar0, LVar1, LVar2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetPartMoveSpeed, ACTOR_SELF, LVarA, Float(14.0))
    Call(SetPartJumpGravity, ACTOR_SELF, LVarA, Float(0.01))
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpPartTo, ACTOR_SELF, LVarA, LVar0, LVar1, LVar2, 0, TRUE)
    Switch(LVarA)
        CaseEq(PRT_BIG_ROCK)
            Wait(2)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_BIG_ROCK, BS_FLAGS1_TRIGGER_EVENTS)
        CaseEq(PRT_SMALL_ROCK)
            Wait(2)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SMALL_ROCK, BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim01)
            Call(GetPartOffset, ACTOR_SELF, LVarA, LVar0, LVar1, LVar2)
            Add(LVar0, -100)
            Call(SetPartJumpGravity, ACTOR_SELF, LVarA, Float(1.0))
            Call(JumpPartTo, ACTOR_SELF, LVarA, LVar0, LVar1, LVar2, 25, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, LVarA, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            Wait(10)
            Call(YieldTurn)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        ExecWait(N(EVS_Attack_Lick))
        Return
    EndIf
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAG_SHRINK)
        ExecWait(N(EVS_Attack_Lick))
        Return
    EndIf
    Set(LVarA, 0)
    // search for rock actors to pick up
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_ALLOW_TARGET_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetOriginalActorType, LVar0, LVar2)
        IfEq(LVar2, ACTOR_TYPE_GULPIT_ROCKS)
            Add(LVarA, 1)
            Switch(LVarA)
                CaseEq(1)
                    Set(LVarB, LVar0)
                CaseEq(2)
                    Set(LVarC, LVar0)
                CaseEq(3)
                    Set(LVarD, LVar0)
            EndSwitch
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Switch(LVarA)
        CaseEq(0)
            ExecWait(N(EVS_Attack_Lick))
        CaseEq(1)
            Set(LVar0, LVarB)
            ExecWait(N(EVS_Attack_SpitRock))
        CaseEq(2)
            Call(RandInt, 1, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    Set(LVar0, LVarB)
                CaseEq(1)
                    Set(LVar0, LVarC)
            EndSwitch
            ExecWait(N(EVS_Attack_SpitRock))
        CaseGe(3)
            Call(RandInt, 2, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    Set(LVar0, LVarB)
                CaseEq(1)
                    Set(LVar0, LVarC)
                CaseEq(2)
                    Set(LVar0, LVarD)
            EndSwitch
            ExecWait(N(EVS_Attack_SpitRock))
    EndSwitch
    Return
    End
};

