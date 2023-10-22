#include "../area.h"
#include "sprite/npc/MontyMole.h"

#define NAMESPACE A(monty_mole_boss)

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
    ELEMENT_SMASH,    0,
    ELEMENT_THROW,   -3,
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
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               90,
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
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -7 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET | ACTOR_PART_FLAG_SKIP_MOVEMENT_ALLOC,
        .index = PRT_TARGET,
        .posOffset = { 0, 0, -15 },
        .targetOffset = { 0, 16 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
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
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_MONTY_MOLE_BOSS,
    .level = ACTOR_LEVEL_MONTY_MOLE_BOSS,
    .maxHP = 12,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 55,
    .hurricaneChance = 40,
    .spookChance = 50,
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
    STATUS_KEY_NORMAL,    ANIM_MontyMole_Dark_Anim01,
    STATUS_KEY_STONE,     ANIM_MontyMole_Dark_Anim00,
    STATUS_KEY_SLEEP,     ANIM_MontyMole_Dark_Anim14,
    STATUS_KEY_POISON,    ANIM_MontyMole_Dark_Anim01,
    STATUS_KEY_STOP,      ANIM_MontyMole_Dark_Anim00,
    STATUS_KEY_STATIC,    ANIM_MontyMole_Dark_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_MontyMole_Dark_Anim00,
    STATUS_KEY_DIZZY,     ANIM_MontyMole_Dark_Anim14,
    STATUS_KEY_FEAR,      ANIM_MontyMole_Dark_Anim14,
    STATUS_END,
};

s32 N(RockAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_MontyMole_Dark_Anim0F,
    STATUS_END,
};

s32 N(EmptyHoleAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_MontyMole_Dark_Anim12,
    STATUS_END,
};

// unused
s32 N(LeapAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_MontyMole_Dark_Anim06,
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
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

EvtScript N(EVS_Hole_Init) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IN_Hole_Small, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_RETURN
    EVT_END
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
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SummonEnemy, EVT_PTR(N(SmallHoleFormation)), FALSE)
    EVT_ELSE
        EVT_CALL(SummonEnemy, EVT_PTR(N(HoleFormation)), FALSE)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    EVT_SUB(LVar3, 1)
    EVT_CALL(SetActorPos, LVar0, LVar1, LVar2, LVar3)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastElement, LVarE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_IF_FLAG(LVarE, DAMAGE_TYPE_SMASH)
                EVT_CHILD_THREAD
                    EVT_WAIT(8)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Dark_Anim07)
                EVT_END_CHILD_THREAD
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_MontyMole_Dark_Anim06)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Dark_Anim08)
                EVT_WAIT(10)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_MontyMole_Dark_Anim05)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_MontyMole_Dark_Anim0A)
            EVT_SET_CONST(LVar2, ANIM_MontyMole_Dark_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_MontyMole_Dark_Anim0A)
            EVT_SET_CONST(LVar2, ANIM_MontyMole_Dark_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(N(EVS_CreateEmptyHole))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_MontyMole_Dark_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(GetLastElement, LVar0)
            EVT_IF_FLAG(LVar0, DAMAGE_TYPE_SMASH)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(2.0))
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Dark_Anim11)
                EVT_WAIT(80)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0))
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Dark_Anim10)
                EVT_WAIT(20)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Dark_Anim14)
                EVT_WAIT(20)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_MontyMole_Dark_Anim01)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_MontyMole_Dark_Anim05)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Dark_Anim06)
            EVT_WAIT(10)
            EVT_EXEC_WAIT(N(EVS_CreateEmptyHole))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_MontyMole_Dark_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Dark_Anim06)
            EVT_WAIT(8)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Dark_Anim07)
            EVT_WAIT(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Dark_Anim08)
            EVT_WAIT(8)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Dark_Anim06)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Dark_Anim07)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Dark_Anim08)
            EVT_WAIT(15)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TARGET_ONLY | ACTOR_FLAG_NO_DMG_APPLY, TRUE)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(EmptyHoleAnims)))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_MontyMole_Dark_Anim05)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_EXEC_WAIT(N(EVS_CreateEmptyHole))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -5, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Dark_Anim19)
            EVT_ELSE
                EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -9, 0)
                EVT_ELSE
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -23, 0)
                EVT_END_IF
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Dark_Anim09)
            EVT_END_IF
            EVT_WAIT(1000)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Dark_Anim11)
            EVT_WAIT(40)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Dark_Anim10)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Dark_Anim14)
            EVT_WAIT(20)
        EVT_CASE_EQ(EVENT_UP_AND_AWAY)
            EVT_EXEC_WAIT(N(EVS_CreateEmptyHole))
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
        EVT_WAIT(20)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_MontyMole_Dark_Anim04)
    EVT_WAIT(37)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_ROCK, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_ROCK, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_ROCK, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_ROCK, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_ROCK, SOUND_MOLE_THROW)
    EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_ROCK, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 3, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 100)
            EVT_SET(LVar1, -5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_ROCK, EVT_FLOAT(12.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_ROCK, EVT_FLOAT(0.1))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ROCK, ANIM_MontyMole_Dark_Anim0F)
            EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_ROCK, LVar0, LVar1, LVar2, 0, 30, EASING_LINEAR)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_ROCK, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(YieldTurn)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_ROCK, EVT_FLOAT(12.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_ROCK, EVT_FLOAT(0.1))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_ROCK, ANIM_MontyMole_Dark_Anim0F)
    EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_ROCK, LVar0, LVar1, LVar2, 0, 20, EASING_LINEAR)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 3, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 55)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_ROCK, EVT_FLOAT(6.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_ROCK, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_ROCK, LVar0, LVar1, LVar2, 0, 25, EASING_LINEAR)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_ROCK, EVT_FLOAT(4.0))
            EVT_SUB(LVar0, 20)
            EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_ROCK, LVar0, LVar1, LVar2, 0, 21, EASING_LINEAR)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_ROCK, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

