#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleBowser.h"
#include "effects.h"

#define NAMESPACE b_area_kpa2_bowser

enum N(ActorVars) {
    N(VAR_TURN_COUNTER) = 1,
    N(VAR_TURNS_AFTER_SHOCKWAVE) = 2,
    N(VAR_3) = 3,
};

extern EvtScript N(init);
extern EvtScript N(idle);
extern EvtScript N(takeTurn);
extern EvtScript N(handleEvent);
extern EvtScript N(onHit);
extern EvtScript N(onDeath);
extern EvtScript N(normalAttack);
extern EvtScript N(attackShockwaveDrain);
extern EvtScript N(attackFlameBreath);
extern EvtScript N(attackClawSwipe);
extern EvtScript N(attackHeavyJump);
extern EvtScript N(returnHome);
extern EvtScript N(recover);

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL, ANIM_BattleBowser_Idle,
    STATUS_STONE, ANIM_BattleBowser_Still,
    STATUS_SLEEP, ANIM_BattleBowser_Idle,
    STATUS_POISON, ANIM_BattleBowser_Idle,
    STATUS_STOP, ANIM_BattleBowser_Still,
    STATUS_STATIC, ANIM_BattleBowser_Still,
    STATUS_PARALYZE, ANIM_BattleBowser_Still,
    STATUS_PARALYZE, ANIM_BattleBowser_Still,
    STATUS_DIZZY, ANIM_BattleBowser_Idle,
    STATUS_DIZZY, ANIM_BattleBowser_Idle,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 30,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 30,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 30,
    STATUS_SHRINK, 50,
    STATUS_STOP, 30,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, -1,
    STATUS_STOP_TURN_MOD, -2,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -18, 72 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = ELEMENT_FIRE,
        .projectileTargetOffset = { 0, -8 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_BOWSER_PHASE_1,
    .level = 100,
    .maxHP = 50,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
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
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -40, 67 },
    .statusMessageOffset = { 10, 60 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURN_COUNTER), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURNS_AFTER_SHOCKWAVE), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_3), 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastElement, LVarE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onHit))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onHit))
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onHit))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(DoShockHit)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onHit))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(1000)
        EVT_CASE_DEFAULT
            EVT_SET_CONST(LVar1, ANIM_BattleBowser_Hurt)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar1)
            EVT_WAIT(20)
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(onHit) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_EXEC_WAIT(DoNormalHit)
    EVT_RETURN
    EVT_END
};

EvtScript N(onDeath) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_EXEC_WAIT(DoNormalHit)
    EVT_SET_CONST(LVar0, 1)
    EVT_EXEC_WAIT(DoDeath)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURN_COUNTER), LVar0)
    EVT_ADD(LVar0, 1)
    EVT_IF_LT(LVar0, 5)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURN_COUNTER), LVar0)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURNS_AFTER_SHOCKWAVE), 5)
        EVT_EXEC_WAIT(N(normalAttack))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_TURNS_AFTER_SHOCKWAVE), LVar0)
    EVT_ADD(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURNS_AFTER_SHOCKWAVE), LVar0)
    EVT_IF_LT(LVar0, 4)
        EVT_EXEC_WAIT(N(normalAttack))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_GT(LVar0, 6)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURNS_AFTER_SHOCKWAVE), 0)
        EVT_EXEC_WAIT(N(attackShockwaveDrain))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_IF_LT(LVar0, 8)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_TURNS_AFTER_SHOCKWAVE), 0)
        EVT_EXEC_WAIT(N(attackShockwaveDrain))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(normalAttack))
    EVT_RETURN
    EVT_END
};

EvtScript N(normalAttack) = {
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_STATIC)
        EVT_EXEC_WAIT(N(attackFlameBreath))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(RandInt, 2, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(attackClawSwipe))
            EVT_RETURN
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(attackHeavyJump))
            EVT_RETURN
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(N(attackFlameBreath))
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(attackClawSwipe) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(SetBattleCamZoom, 150)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Walk)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_RearUpMock)
    EVT_WAIT(25)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Swipe)
    EVT_WAIT(3)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Tantrum)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_WAIT(50)
            EVT_ELSE
                EVT_WAIT(30)
            EVT_END_IF
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_SET(LVar1, ANIM_BattleBowser_Walk)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_3), LVar0)
    EVT_MUL(LVar0, 6)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 0, LVar0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_WAIT(30)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Mock)
            EVT_WAIT(45)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_SET(LVar1, ANIM_BattleBowser_Walk)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attackHeavyJump) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(SetBattleCamZoom, 150)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Walk)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 80, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_PreJump)
    EVT_WAIT(3)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Jump)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_10)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_PostJump)
            EVT_WAIT(3)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
            EVT_WAIT(25)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_SET(LVar1, ANIM_BattleBowser_Walk)
            EVT_EXEC_WAIT(N(returnHome))
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
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Land)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_3), LVar0)
    EVT_MUL(LVar0, 6)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 0, LVar0, BS_FLAGS1_SP_EVT_ACTIVE)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_PostJump)
            EVT_WAIT(3)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
            EVT_WAIT(20)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_SET(LVar1, ANIM_BattleBowser_Walk)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attackFlameBreath) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(SetBattleCamZoom, 150)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_PreFireBreath)
    EVT_WAIT(35)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_FireBreathStill)
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
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 100)
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_FireBreathLoop)
    EVT_WAIT(30)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_PostFireBreath)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
            EVT_WAIT(30)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Tantrum)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(30)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_3), LVar0)
    EVT_MUL(LVar0, 8)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_FIRE, SUPPRESS_EVENT_ALL, 0, LVar0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_PostFireBreath)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
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

#include "common/FadeBackgroundToBlack.inc.c"
#include "common/UnfadeBackgroundToBlack.inc.c"

EvtScript N(attackShockwaveDrain) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Brandish)
    EVT_WAIT(10)
    EVT_CALL(N(FadeBackgroundToBlack))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 15)
    EVT_SUB(LVar2, 3)
    EVT_PLAY_EFFECT(EFFECT_LIGHT_RAYS, 2, LVar0, 90, LVar2, EVT_FLOAT(1.0), LVarF, 0)
    EVT_SUB(LVar2, 3)
    EVT_PLAY_EFFECT(EFFECT_BULB_GLOW, 2, LVar0, 90, LVar2, EVT_FLOAT(1.0), LVarE, 0)
    EVT_WAIT(16)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 45)
    EVT_WAIT(19)
    EVT_CALL(RemoveEffect, LVarF)
    EVT_CALL(RemoveEffect, LVarE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 13)
    EVT_SET(LVar1, 55)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_SHOCKWAVE, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 60, 0)
    EVT_THREAD
        EVT_CALL(N(UnfadeBackgroundToBlack))
    EVT_END_THREAD
    EVT_WAIT(8)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(HIT_RESULT_MISS)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
            EVT_WAIT(15)
            EVT_EXEC_WAIT(N(recover))
            EVT_WAIT(30)
            EVT_RETURN
        EVT_CASE_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(func_8026BF48, 1)
            EVT_THREAD
                EVT_WAIT(2)
                EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_COSMIC, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
                EVT_CALL(func_8026BF48, 0)
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
            EVT_WAIT(15)
            EVT_EXEC_WAIT(N(recover))
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(30)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(func_8026BF48, 1)
    EVT_THREAD
        EVT_WAIT(2)
        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_COSMIC, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CALL(func_8026BF48, 0)
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_COSMIC, 0, STATUS_FLAG_POISON, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(RemovePlayerBuffs, PLAYER_BUFF_JUMP_CHARGE | PLAYER_BUFF_HAMMER_CHARGE | PLAYER_BUFF_STONE | PLAYER_BUFF_HUSTLE | PLAYER_BUFF_STATIC | PLAYER_BUFF_TRANSPARENT | PLAYER_BUFF_CLOUD_NINE | PLAYER_BUFF_TURBO_CHARGE | PLAYER_BUFF_WATER_BLOCK | PLAYER_BUFF_PARTNER_GLOWING | 0xFFEFC04)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleBowser_Idle)
            EVT_WAIT(15)
            EVT_EXEC_WAIT(N(recover))
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_RETURN
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome) = {
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

EvtScript N(recover) = {
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
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_3), LVar0)
    EVT_ADD(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_3), LVar0)
    EVT_RETURN
    EVT_END
};
