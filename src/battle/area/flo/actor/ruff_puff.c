#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/TuffPuff.h"

#define NAMESPACE b_area_flo_ruff_puff

extern EvtScript N(EVS_Init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL, ANIM_TuffPuff_Idle,
    STATUS_STONE, ANIM_TuffPuff_Still,
    STATUS_SLEEP, ANIM_TuffPuff_Sleep,
    STATUS_POISON, ANIM_TuffPuff_Idle,
    STATUS_STOP, ANIM_TuffPuff_Still,
    STATUS_STATIC, ANIM_TuffPuff_Idle,
    STATUS_PARALYZE, ANIM_TuffPuff_Still,
    STATUS_DIZZY, ANIM_TuffPuff_Dizzy,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_MYSTERY, 0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 50,
    STATUS_POISON, 90,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 0,
    STATUS_STATIC, 70,
    STATUS_PARALYZE, 40,
    STATUS_SHRINK, 75,
    STATUS_STOP, 80,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 26 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -13 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_RUFF_PUFF,
    .level = 19,
    .maxHP = 10,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 90,
    .hurricaneChance = 90,
    .spookChance = 40,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 2,
    .size = { 32, 32 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_RETURN
    EVT_END
};

#include "common/CosInterpMinMax.inc.c"

EvtScript N(idle) = {
    EVT_SET(LVarF, 0)
    EVT_LOOP(0)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVar0, EVT_FLOAT(0.97), EVT_FLOAT(1.03), 15, 0, 0)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVar1, EVT_FLOAT(1.03), EVT_FLOAT(0.97), 15, 0, 0)
        EVT_ADD(LVarF, 1)
        EVT_CALL(SetActorScale, ACTOR_SELF, LVar1, LVar0, EVT_FLOAT(1.0))
        EVT_IF_GE(LVarF, 30)
            EVT_SET(LVarF, 0)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TuffPuff_Run)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_SIN_OUT)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_TuffPuff_Hurt)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_TuffPuff_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_TuffPuff_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_TuffPuff_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_TuffPuff_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_TuffPuff_BurnStill)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_TuffPuff_Hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_TuffPuff_Hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_TuffPuff_Hurt)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_TuffPuff_Hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_TuffPuff_Hurt)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_TuffPuff_Hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_TuffPuff_Hurt)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_TuffPuff_Idle)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_TuffPuff_Hurt)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_TuffPuff_Hurt)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_TuffPuff_Idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_TuffPuff_Run)
            EVT_SET_CONST(LVar2, ANIM_TuffPuff_Hurt)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_TuffPuff_Run)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_TuffPuff_Run)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TuffPuff_Run)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_SIN_OUT)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TuffPuff_Idle)
    EVT_WAIT(5)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TuffPuff_Grin)
    EVT_WAIT(5)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                EVT_SETF(LVar0, EVT_FLOAT(0.0))
                EVT_LOOP(15)
                    EVT_ADDF(LVar0, EVT_FLOAT(12.0))
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(AddGoalPos, ACTOR_SELF, -10, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                EVT_SETF(LVar0, EVT_FLOAT(180.0))
                EVT_LOOP(10)
                    EVT_ADDF(LVar0, EVT_FLOAT(18.0))
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(AddGoalPos, ACTOR_SELF, -30, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -20, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -10, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 13, 0)
        EVT_SETF(LVar0, EVT_FLOAT(0.0))
        EVT_LOOP(8)
            EVT_ADDF(LVar0, EVT_FLOAT(22.5))
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                EVT_SETF(LVar0, EVT_FLOAT(180.0))
                EVT_LOOP(10)
                    EVT_SUBF(LVar0, EVT_FLOAT(22.5))
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(JumpWithBounce, ACTOR_SELF, 10, EVT_FLOAT(5.0))
            EVT_WAIT(10)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
