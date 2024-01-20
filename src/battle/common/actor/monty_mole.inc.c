#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/MontyMole.h"

#define NAMESPACE A(monty_mole)

extern s32 N(DefaultAnims)[];
extern s32 N(RockAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_TARGET      = 2,
    PRT_ROCK        = 3,
};

enum N(ActorVars) {
    AVAR_IN_Hole_Small  = 0,
};

enum N(ActorParams) {
    DMG_TOSS        = 2,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              90,
    STATUS_KEY_POISON,             80,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             10,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,             90,
    STATUS_KEY_STOP,              100,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 16 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -7 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET | ACTOR_PART_FLAG_SKIP_MOVEMENT_ALLOC,
        .index = PRT_TARGET,
        .posOffset = { 0, 0, -15 },
        .targetOffset = { -2, 12 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -7 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_ROCK,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(RockAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_MONTY_MOLE,
    .level = ACTOR_LEVEL_MONTY_MOLE,
    .maxHP = 3,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 80,
    .airLiftChance = 70,
    .hurricaneChance = 50,
    .spookChance = 85,
    .upAndAwayChance = 95,
    .spinSmashReq = 4,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 34, 18 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_MontyMole_Anim01,
    STATUS_KEY_STONE,     ANIM_MontyMole_Anim00,
    STATUS_KEY_SLEEP,     ANIM_MontyMole_Anim14,
    STATUS_KEY_POISON,    ANIM_MontyMole_Anim01,
    STATUS_KEY_STOP,      ANIM_MontyMole_Anim00,
    STATUS_KEY_STATIC,    ANIM_MontyMole_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_MontyMole_Anim00,
    STATUS_KEY_DIZZY,     ANIM_MontyMole_Anim14,
    STATUS_KEY_FEAR,      ANIM_MontyMole_Anim14,
    STATUS_END,
};

s32 N(RockAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_MontyMole_Anim0F,
    STATUS_END,
};

s32 N(EmptyHoleAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_MontyMole_Anim12,
    STATUS_END,
};

// unused
s32 N(LeapAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_MontyMole_Anim06,
    STATUS_END,
};

ActorPartBlueprint N(HoleParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_DAMAGE_IMMUNE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(EmptyHoleAnims),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

EvtScript N(EVS_Hole_Init) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_IN_Hole_Small, LVar0)
    IfEq(LVar0, TRUE)
        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(0.4), Float(0.4), Float(0.4))
    EndIf
    Return
    End
};

ActorBlueprint N(hole) = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_HEALTH_BAR | ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY,
    .type = ACTOR_TYPE_MONTY_HOLE,
    .level = ACTOR_LEVEL_MONTY_HOLE,
    .maxHP = 5,
    .partCount = ARRAY_COUNT(N(HoleParts)),
    .partsData = N(HoleParts),
    .initScript = &N(EVS_Hole_Init),
    .statusTable = NULL,
    .escapeChance = 80,
    .airLiftChance = 0,
    .hurricaneChance = 80,
    .spookChance = 80,
    .upAndAwayChance = 90,
    .spinSmashReq = 4,
    .powerBounceChance = 90,
    .coinReward = 2,
    .size = { 32, 18 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

Vec3i N(SummonPos) = { NPC_DISPOSE_LOCATION };

Formation N(HoleFormation) = {
    ACTOR_BY_POS(N(hole), N(SummonPos), 0, FALSE),
};

Formation N(SmallHoleFormation) = {
    ACTOR_BY_POS(N(hole), N(SummonPos), 0, TRUE),
};

EvtScript N(EVS_CreateEmptyHole) = {
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(SummonEnemy, Ref(N(SmallHoleFormation)), FALSE)
    Else
        Call(SummonEnemy, Ref(N(HoleFormation)), FALSE)
    EndIf
    Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    Sub(LVar3, 1)
    Call(SetActorPos, LVar0, LVar1, LVar2, LVar3)
    Return
    End
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
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
    Call(GetLastElement, LVarE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            IfFlag(LVarE, DAMAGE_TYPE_SMASH)
                ChildThread
                    Wait(8)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Anim07)
                EndChildThread
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_MontyMole_Anim06)
                ExecWait(EVS_Enemy_Hit)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Anim08)
                Wait(10)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_MontyMole_Anim05)
                ExecWait(EVS_Enemy_Hit)
            EndIf
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MontyMole_Anim0A)
            SetConst(LVar2, ANIM_MontyMole_Anim0B)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MontyMole_Anim0A)
            SetConst(LVar2, ANIM_MontyMole_Anim0B)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(N(EVS_CreateEmptyHole))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MontyMole_Anim0C)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Call(GetLastElement, LVar0)
            IfFlag(LVar0, DAMAGE_TYPE_SMASH)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
                Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(2.0))
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Anim11)
                Wait(80)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
                Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Anim10)
                Wait(20)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Anim14)
                Wait(20)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_MontyMole_Anim01)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MontyMole_Anim05)
            ExecWait(EVS_Enemy_Hit)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Anim06)
            Wait(10)
            ExecWait(N(EVS_CreateEmptyHole))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MontyMole_Anim09)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Anim06)
            Wait(8)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Anim07)
            Wait(5)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Anim08)
            Wait(8)
        CaseEq(EVENT_SCARE_AWAY)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Anim06)
            Wait(15)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Anim07)
            Wait(15)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Anim08)
            Wait(15)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TARGET_ONLY | ACTOR_FLAG_NO_DMG_APPLY, TRUE)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(EmptyHoleAnims)))
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_MontyMole_Anim05)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            ExecWait(N(EVS_CreateEmptyHole))
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                Call(SetActorDispOffset, ACTOR_SELF, 0, -5, 0)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Anim19)
            Else
                IfFlag(LVar0, STATUS_FLAG_SHRINK)
                    Call(SetActorDispOffset, ACTOR_SELF, 0, -9, 0)
                Else
                    Call(SetActorDispOffset, ACTOR_SELF, 0, -23, 0)
                EndIf
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Anim09)
            EndIf
            Wait(1000)
            Return
        CaseEq(EVENT_AIR_LIFT_FAILED)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(2.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Anim11)
            Wait(40)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Anim10)
            Wait(20)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Anim14)
            Wait(20)
        CaseEq(EVENT_UP_AND_AWAY)
            ExecWait(N(EVS_CreateEmptyHole))
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
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 1)
    EndIf
    ChildThread
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
        Wait(20)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
    EndChildThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Anim04)
    Wait(37)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    Call(SetPartPos, ACTOR_SELF, PRT_ROCK, LVar0, LVar1, LVar2)
    Wait(1)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_ROCK, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(SetPartScale, ACTOR_SELF, PRT_ROCK, Float(0.4), Float(0.4), Float(0.4))
    Else
        Call(SetPartScale, ACTOR_SELF, PRT_ROCK, Float(1.0), Float(1.0), Float(1.0))
    EndIf
    Call(PlaySoundAtPart, ACTOR_SELF, PRT_ROCK, SOUND_MOLE_THROW)
    Call(SetPartSounds, ACTOR_SELF, PRT_ROCK, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 2, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 100)
            Set(LVar1, -5)
            Call(SetPartMoveSpeed, ACTOR_SELF, PRT_ROCK, Float(12.0))
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_ROCK, Float(0.1))
            Call(SetAnimation, ACTOR_SELF, PRT_ROCK, ANIM_MontyMole_Anim0F)
            Call(FlyPartTo, ACTOR_SELF, PRT_ROCK, LVar0, LVar1, LVar2, 0, 30, EASING_LINEAR)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_ROCK, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(YieldTurn)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetPartMoveSpeed, ACTOR_SELF, PRT_ROCK, Float(12.0))
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_ROCK, Float(0.1))
    Call(SetAnimation, ACTOR_SELF, PRT_ROCK, ANIM_MontyMole_Anim0F)
    Call(FlyPartTo, ACTOR_SELF, PRT_ROCK, LVar0, LVar1, LVar2, 0, 20, EASING_LINEAR)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_TOSS, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Sub(LVar0, 55)
            Set(LVar1, 0)
            Call(SetPartMoveSpeed, ACTOR_SELF, PRT_ROCK, Float(6.0))
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_ROCK, Float(0.1))
            Call(FlyPartTo, ACTOR_SELF, PRT_ROCK, LVar0, LVar1, LVar2, 0, 25, EASING_LINEAR)
            Call(SetPartMoveSpeed, ACTOR_SELF, PRT_ROCK, Float(4.0))
            Sub(LVar0, 20)
            Call(FlyPartTo, ACTOR_SELF, PRT_ROCK, LVar0, LVar1, LVar2, 0, 21, EASING_LINEAR)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_ROCK, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};
