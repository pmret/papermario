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
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReturnHome) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim03)
    EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim01)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0C)
            EVT_SET_CONST(LVar2, ANIM_Gulpit_Anim0D)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0C)
            EVT_SET_CONST(LVar2, ANIM_Gulpit_Anim0D)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0D)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim03)
            EVT_SET_CONST(LVar2, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim03)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim03)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_Lick) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 80)
        EVT_SET(LVar1, 0)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim03)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 10, 0, 0)
    EVT_ELSE
        EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 0, 0)
    EVT_END_IF
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim01)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_GULPIT_LICK)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim04)
    EVT_WAIT(9)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_LICK, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_WAIT(10)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_SpitRock) = {
    EVT_SET(LVarA, LVar0)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_SUB(LVar2, 1)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim02)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim01)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_GULPIT_LICK)
    EVT_CALL(GetActorVar, LVarA, AVAR_Rock_Type, LVar0)
    EVT_SET(LVarB, LVar0)
    EVT_SWITCH(LVarB)
        EVT_CASE_EQ(0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim05)
            EVT_WAIT(3)
            EVT_CALL(RemoveActor, LVarA)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim06)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim07)
            EVT_SET(LVarA, 2)
        EVT_CASE_EQ(1)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim08)
            EVT_WAIT(3)
            EVT_CALL(RemoveActor, LVarA)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim09)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim0A)
            EVT_SET(LVarA, 3)
    EVT_END_SWITCH
    EVT_CALL(SetPartSounds, ACTOR_SELF, LVarA, ACTOR_SOUND_JUMP, SOUND_LIGHT_THROW, SOUND_NONE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVar9, LVar0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVarA, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 20)
            EVT_ADD(LVar2, 2)
            EVT_CALL(SetPartPos, ACTOR_SELF, LVarA, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -100, 0, 5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LVarA, EVT_FLOAT(14.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVarA, EVT_FLOAT(0.01))
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpPartTo, ACTOR_SELF, LVarA, LVar0, LVar1, LVar2, 0, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVarA, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_IF_EQ(LVar9, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVarA, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_ADD(LVar2, 2)
    EVT_CALL(SetPartPos, ACTOR_SELF, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LVarA, EVT_FLOAT(14.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVarA, EVT_FLOAT(0.01))
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVarA, LVar0, LVar1, LVar2, 0, TRUE)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(PRT_BIG_ROCK)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_BIG_ROCK, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_CASE_EQ(PRT_SMALL_ROCK)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SMALL_ROCK, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim01)
            EVT_CALL(GetPartOffset, ACTOR_SELF, LVarA, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, -100)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVarA, EVT_FLOAT(1.0))
            EVT_CALL(JumpPartTo, ACTOR_SELF, LVarA, LVar0, LVar1, LVar2, 25, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVarA, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_WAIT(10)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_EXEC_WAIT(N(EVS_Attack_Lick))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_EXEC_WAIT(N(EVS_Attack_Lick))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVarA, 0)
    // search for rock actors to pick up
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_ALLOW_TARGET_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(GetOriginalActorType, LVar0, LVar2)
        EVT_IF_EQ(LVar2, ACTOR_TYPE_GULPIT_ROCKS)
            EVT_ADD(LVarA, 1)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(1)
                    EVT_SET(LVarB, LVar0)
                EVT_CASE_EQ(2)
                    EVT_SET(LVarC, LVar0)
                EVT_CASE_EQ(3)
                    EVT_SET(LVarD, LVar0)
            EVT_END_SWITCH
        EVT_END_IF
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_Attack_Lick))
        EVT_CASE_EQ(1)
            EVT_SET(LVar0, LVarB)
            EVT_EXEC_WAIT(N(EVS_Attack_SpitRock))
        EVT_CASE_EQ(2)
            EVT_CALL(RandInt, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_SET(LVar0, LVarB)
                EVT_CASE_EQ(1)
                    EVT_SET(LVar0, LVarC)
            EVT_END_SWITCH
            EVT_EXEC_WAIT(N(EVS_Attack_SpitRock))
        EVT_CASE_GE(3)
            EVT_CALL(RandInt, 2, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_SET(LVar0, LVarB)
                EVT_CASE_EQ(1)
                    EVT_SET(LVar0, LVarC)
                EVT_CASE_EQ(2)
                    EVT_SET(LVar0, LVarD)
            EVT_END_SWITCH
            EVT_EXEC_WAIT(N(EVS_Attack_SpitRock))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

