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
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnCount, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_DamageMultiplier, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastElement, LVarE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_OnHit))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_OnHit))
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_OnDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_OnHit))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_OnDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_OnDeath))
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_OnHit))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(EVS_OnDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(1000)
        EVT_CASE_DEFAULT
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
            EVT_WAIT(20)
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnHit) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_EXEC_WAIT(EVS_Enemy_Hit)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnDeath) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_EXEC_WAIT(EVS_Enemy_Hit)
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_EXEC_WAIT(EVS_Enemy_Death)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    // only use regular attacks for the first few turns
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_IF_LT(LVar0, 5)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnCount, LVar0)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, 5)
        EVT_EXEC_WAIT(N(EVS_UseAttack))
        EVT_RETURN
    EVT_END_IF
    // increment shockwave turn counter
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, LVar0)
    // use normal attack if shockwave was used recently
    EVT_IF_LT(LVar0, 4)
        EVT_EXEC_WAIT(N(EVS_UseAttack))
        EVT_RETURN
    EVT_END_IF
    // use shockwave if it hasn't been used recently
    EVT_IF_GT(LVar0, 6)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, 0)
        EVT_EXEC_WAIT(N(EVS_UseDrainingShockwave))
        EVT_RETURN
    EVT_END_IF
    // use shockwave if HP is low, even if it hasn't met the normal time threshold
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_IF_LT(LVar0, 8)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnsSinceShockwave, 0)
        EVT_EXEC_WAIT(N(EVS_UseDrainingShockwave))
        EVT_RETURN
    EVT_END_IF
    // fallback to using a regular attack
    EVT_EXEC_WAIT(N(EVS_UseAttack))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseAttack) = {
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_STATIC)
        EVT_EXEC_WAIT(N(EVS_Attack_FireBreath))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(RandInt, 2, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_Attack_ClawSwipe))
            EVT_RETURN
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_Attack_BodySlam))
            EVT_RETURN
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(N(EVS_Attack_FireBreath))
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_ClawSwipe) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(SetBattleCamZoom, 150)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Walk)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_RearUpMock)
    EVT_WAIT(25)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Swipe)
    EVT_WAIT(3)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Tantrum)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_WAIT(50)
            EVT_ELSE
                EVT_WAIT(30)
            EVT_END_IF
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_SET(LVar1, ANIM_BattleBowser_Walk)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DamageMultiplier, LVar0)
    EVT_MUL(LVar0, DMG_CLAW_SWIPE)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_WAIT(30)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Mock)
            EVT_WAIT(45)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_SET(LVar1, ANIM_BattleBowser_Walk)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_BodySlam) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(SetBattleCamZoom, 150)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Walk)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 80, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PreJump)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Jump)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 28, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(3.0))
            EVT_END_THREAD
            EVT_SUB(LVar0, 35)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 14, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(2.0))
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostJump)
            EVT_WAIT(3)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            EVT_WAIT(25)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_SET(LVar1, ANIM_BattleBowser_Walk)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 24, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(3.0))
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Land)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DamageMultiplier, LVar0)
    EVT_MUL(LVar0, DMG_BODY_SLAM)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(3.0))
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostJump)
            EVT_WAIT(3)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            EVT_WAIT(20)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_SET(LVar1, ANIM_BattleBowser_Walk)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_FireBreath) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(SetBattleCamZoom, 150)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PreFireBreath)
    EVT_WAIT(35)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_FireBreathStill)
    EVT_WAIT(10)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 70)
    EVT_ADD(LVar1, 35)
    EVT_ADD(LVar2, 10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_SUB(LVar3, 40)
    EVT_SET(LVar4, 20)
    EVT_PLAY_EFFECT(EFFECT_FIRE_BREATH, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, 50, 1, 24, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 100)
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_FireBreathLoop)
    EVT_WAIT(30)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostFireBreath)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            EVT_WAIT(30)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Tantrum)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(30)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DamageMultiplier, LVar0)
    EVT_MUL(LVar0, DMG_FIRE_BREATH)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_FIRE, SUPPRESS_EVENT_ALL, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_PostFireBreath)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            EVT_WAIT(30)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/FadeBackgroundDarken.inc.c"
#include "common/FadeBackgroundLighten.inc.c"

EvtScript N(EVS_UseDrainingShockwave) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Brandish)
    EVT_WAIT(10)
    EVT_CALL(N(FadeBackgroundDarken))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 15)
    EVT_SUB(LVar2, 3)
    EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 2, LVar0, 90, LVar2, EVT_FLOAT(1.0), LVarF, 0)
    EVT_SUB(LVar2, 3)
    EVT_PLAY_EFFECT(EFFECT_BULB_GLOW, 2, LVar0, 90, LVar2, EVT_FLOAT(1.0), LVarE, 0)
    EVT_WAIT(16)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 45)
    EVT_WAIT(19)
    EVT_CALL(RemoveEffect, LVarF)
    EVT_CALL(RemoveEffect, LVarE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 13)
    EVT_SET(LVar1, 55)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_SHOCKWAVE, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 60, 0)
    EVT_THREAD
        EVT_CALL(N(FadeBackgroundLighten))
    EVT_END_THREAD
    EVT_WAIT(8)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(HIT_RESULT_MISS)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            EVT_WAIT(15)
            EVT_EXEC_WAIT(N(EVS_Recover))
            EVT_WAIT(30)
            EVT_RETURN
        EVT_CASE_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(FreezeBattleState, TRUE)
            EVT_THREAD
                EVT_WAIT(2)
                EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_COSMIC, 0, 0, DMG_SHOCKWAVE_P, BS_FLAGS1_TRIGGER_EVENTS)
                EVT_CALL(FreezeBattleState, FALSE)
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            EVT_WAIT(15)
            EVT_EXEC_WAIT(N(EVS_Recover))
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(30)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(FreezeBattleState, TRUE)
    EVT_THREAD
        EVT_WAIT(2)
        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_COSMIC, 0, 0, DMG_SHOCKWAVE_P, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_CALL(FreezeBattleState, FALSE)
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_COSMIC, 0, STATUS_FLAG_POISON, DMG_SHOCKWAVE, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(RemovePlayerBuffs, PLAYER_BUFF_JUMP_CHARGE | PLAYER_BUFF_HAMMER_CHARGE | PLAYER_BUFF_STONE | PLAYER_BUFF_HUSTLE | PLAYER_BUFF_STATIC | PLAYER_BUFF_TRANSPARENT | PLAYER_BUFF_CLOUD_NINE | PLAYER_BUFF_TURBO_CHARGE | PLAYER_BUFF_WATER_BLOCK | PLAYER_BUFF_PARTNER_GLOWING | 0xFFEFC04)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleBowser_Idle)
            EVT_WAIT(15)
            EVT_EXEC_WAIT(N(EVS_Recover))
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReturnHome) = {
    EVT_SET(LVar0, 1)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVarD, LVarE, LVarF)
    EVT_IF_LT(LVarA, LVarD)
        EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_ELSE
        EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_END_IF
    EVT_CALL(GetDist2D, LVar9, LVarA, LVarC, LVarD, LVarF)
    EVT_IF_GE(LVar9, EVT_FLOAT(4.0))
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_END_IF
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Recover) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    EVT_ADD(LVar2, 60)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar1, LVar2, LVar3, EVT_FLOAT(1.0), 0)
    EVT_ADD(LVar1, 30)
    EVT_ADD(LVar2, 20)
    EVT_PLAY_EFFECT(EFFECT_RECOVER, 0, LVar1, LVar2, LVar3, 10, 0)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_ADD(LVar0, 10)
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
    EVT_IF_GT(LVar0, LVar1)
        EVT_SET(LVar0, LVar1)
    EVT_END_IF
    EVT_CALL(SetEnemyHP, ACTOR_SELF, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DamageMultiplier, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_DamageMultiplier, LVar0)
    EVT_RETURN
    EVT_END
};
