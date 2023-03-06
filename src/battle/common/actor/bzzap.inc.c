#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Bzzap.h"

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL,    ANIM_Bzzap_Anim01,
    STATUS_STONE,     ANIM_Bzzap_Anim00,
    STATUS_SLEEP,     ANIM_Bzzap_Anim09,
    STATUS_POISON,    ANIM_Bzzap_Anim01,
    STATUS_STOP,      ANIM_Bzzap_Anim00,
    STATUS_STATIC,    ANIM_Bzzap_Anim01,
    STATUS_PARALYZE,  ANIM_Bzzap_Anim00,
    STATUS_DIZZY,     ANIM_Bzzap_Anim0A,
    STATUS_FEAR,      ANIM_Bzzap_Anim0A,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 60,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 90,
    STATUS_SHRINK, 75,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -7, 33 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 2, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -5 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -5 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -5 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -5 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -5 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_BZZAP,
    .level = 19,
    .maxHP = 3,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 40,
    .airLiftChance = 95,
    .hurricaneChance = 95,
    .spookChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 38, 38 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

#include "common/UnkBattleFunc1.inc.c"

API_CALLABLE(N(AddVecXZ)) {
    Bytecode* args = script->ptrReadPos;
    s32 prevX = evt_get_variable(script, *args++);
    s32 prevZ = evt_get_variable(script, *args++);
    s32 length = evt_get_variable(script, *args++);
    s32 yaw = evt_get_variable(script, *args++);

    f32 outX = prevX + (length * cos_deg(yaw));
    f32 outZ = prevZ - (length * sin_deg(yaw));

    evt_set_float_variable(script, *args++, outX);
    evt_set_float_variable(script, *args++, outZ);
    return ApiStatus_DONE2;
}

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(SetPartScale, ACTOR_SELF, 2, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_CALL(SetPartScale, ACTOR_SELF, 3, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_CALL(SetPartScale, ACTOR_SELF, 4, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_CALL(SetPartScale, ACTOR_SELF, 5, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_LABEL(0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SLEEP | STATUS_FLAG_DIZZY)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -7, 19)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, 2, -6)
        EVT_CALL(N(UnkBattleFunc1), -20, 20, 10, 27)
    EVT_ELSE
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -7, 33)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, 2, -10)
        EVT_CALL(N(UnkBattleFunc1), -16, 22, 4, 22)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome) = {
    EVT_CALL(SetPartRotation, ACTOR_SELF, 1, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Bzzap_Anim03)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_SIN_OUT)
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
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim06)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim07)
            EVT_SET_CONST(LVar2, ANIM_Bzzap_Anim08)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim07)
            EVT_SET_CONST(LVar2, ANIM_Bzzap_Anim08)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim08)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim06)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim06)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim0B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim06)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim06)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim06)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim0B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim01)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim06)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim0B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim01)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim03)
            EVT_SET_CONST(LVar2, ANIM_Bzzap_Anim06)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim01)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_ELSE
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 9, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim06)
            EVT_EXEC_WAIT(DoBlowAway)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attackThornStab) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Bzzap_Anim03)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 52, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, EASING_COS_IN)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_WAIT(10)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 20)
            EVT_ADD(LVar2, 1)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_QUADRATIC_OUT)
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20CA)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Bzzap_Anim04)
            EVT_WAIT(10)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
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
    EVT_WAIT(10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_ADD(LVar2, 1)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_QUADRATIC_OUT)
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20CA)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Bzzap_Anim04)
    EVT_WAIT(6)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, DMG_STATUS_CHANCE(STATUS_FLAG_POISON, 3, 40), 6, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021B77C) = {
    EVT_SET(LVar9, LVar0)
    EVT_CALL(SetPartYaw, ACTOR_SELF, LVar9, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_ADD(LVarA, 200)
    EVT_ADD(LVarB, 100)
    EVT_CALL(SetPartPos, ACTOR_SELF, LVar9, LVarA, LVarB, LVarC)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar9, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar9, ANIM_Bzzap_Anim03)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_ADD(LVarB, 50)
    EVT_SUB(LVarC, 30)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LVar9, EVT_FLOAT(6.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar9, EVT_FLOAT(1.0))
    EVT_CALL(FlyPartTo, ACTOR_SELF, LVar9, LVarA, LVarB, LVarC, 0, -10, EASING_LINEAR)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_CALL(GetPartOffset, ACTOR_SELF, LVar9, LVar6, LVar7, LVar8)
    EVT_CALL(MakeLerp, 90, 450, 50, EASING_LINEAR)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(N(AddVecXZ), LVar3, LVar5, 30, LVar0, LVar6, LVar8)
    EVT_CALL(SetPartPos, ACTOR_SELF, LVar9, LVar6, LVar7, LVar8)
    EVT_IF_GT(LVar3, LVar6)
        EVT_CALL(SetPartYaw, ACTOR_SELF, LVar9, 180)
    EVT_ELSE
        EVT_CALL(SetPartYaw, ACTOR_SELF, LVar9, 0)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetPartYaw, ACTOR_SELF, LVar9, 0)
    EVT_IF_EQ(LVar9, 2)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_I)
        EVT_CALL(SetBattleCamZoom, 400)
        EVT_CALL(SetBattleCamOffsetZ, 30)
        EVT_CALL(BattleCamTargetActor, ACTOR_PLAYER)
        EVT_CALL(MoveBattleCamOver, 60)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar9, ANIM_Bzzap_Anim03)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVarA, LVarB, LVarC)
    EVT_ADD(LVarB, 30)
    EVT_ADD(LVarC, 30)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LVar9, EVT_FLOAT(6.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar9, EVT_FLOAT(1.0))
    EVT_CALL(FlyPartTo, ACTOR_SELF, LVar9, LVarA, LVarB, LVarC, 0, -10, EASING_LINEAR)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
    EVT_CALL(GetPartOffset, ACTOR_SELF, LVar9, LVar6, LVar7, LVar8)
    EVT_CALL(MakeLerp, -90, -720, 100, EASING_LINEAR)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(N(AddVecXZ), LVar3, LVar5, 30, LVar0, LVar6, LVar8)
    EVT_CALL(SetPartPos, ACTOR_SELF, LVar9, LVar6, LVar7, LVar8)
    EVT_IF_GT(LVar3, LVar6)
        EVT_CALL(SetPartYaw, ACTOR_SELF, LVar9, 180)
    EVT_ELSE
        EVT_CALL(SetPartYaw, ACTOR_SELF, LVar9, 0)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(attackSwarmSting) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 2, ACTOR_SOUND_FLY, 0, 0)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 3, ACTOR_SOUND_FLY, 0, 0)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 4, ACTOR_SOUND_FLY, 0, 0)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 5, ACTOR_SOUND_FLY, 0, 0)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 6, ACTOR_SOUND_FLY, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20CC)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Bzzap_Anim05)
    EVT_WAIT(40)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Bzzap_Anim01)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(PlaySound, SOUND_358)
    EVT_SET(LVar0, 2)
    EVT_EXEC_GET_TID(N(8021B77C), LVarA)
    EVT_WAIT(11)
    EVT_SET(LVar0, 3)
    EVT_EXEC(N(8021B77C))
    EVT_WAIT(11)
    EVT_SET(LVar0, 4)
    EVT_EXEC(N(8021B77C))
    EVT_WAIT(11)
    EVT_SET(LVar0, 5)
    EVT_EXEC(N(8021B77C))
    EVT_WAIT(11)
    EVT_SET(LVar0, 6)
    EVT_EXEC(N(8021B77C))
    EVT_LABEL(0)
    EVT_IS_THREAD_RUNNING(LVarA, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_THREAD
                EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 2, SOUND_20CB)
                EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_Bzzap_Anim04)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(AddGoalPos, ACTOR_SELF, -30, -20, 1)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 2, EVT_FLOAT(3.0))
                EVT_CALL(FlyPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
                EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_Bzzap_Anim03)
                EVT_CALL(SetPartYaw, ACTOR_SELF, 2, 180)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 100)
                EVT_ADD(LVar2, 100)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 2, 0, ACTOR_DECORATION_SWEAT)
                EVT_CALL(FlyPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 2, 0)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_END_THREAD
            EVT_WAIT(11)
            EVT_THREAD
                EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 3, SOUND_20CB)
                EVT_CALL(SetAnimation, ACTOR_SELF, 3, ANIM_Bzzap_Anim04)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(AddGoalPos, ACTOR_SELF, -30, -20, 1)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 3, EVT_FLOAT(3.0))
                EVT_CALL(FlyPartTo, ACTOR_SELF, 3, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
                EVT_CALL(SetAnimation, ACTOR_SELF, 3, ANIM_Bzzap_Anim03)
                EVT_CALL(SetPartYaw, ACTOR_SELF, 3, 180)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 100)
                EVT_ADD(LVar2, 100)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 3, 0, ACTOR_DECORATION_SWEAT)
                EVT_CALL(FlyPartTo, ACTOR_SELF, 3, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 3, 0)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_END_THREAD
            EVT_WAIT(11)
            EVT_THREAD
                EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 4, SOUND_20CB)
                EVT_CALL(SetAnimation, ACTOR_SELF, 4, ANIM_Bzzap_Anim04)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(AddGoalPos, ACTOR_SELF, -30, -20, 1)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 4, EVT_FLOAT(3.0))
                EVT_CALL(FlyPartTo, ACTOR_SELF, 4, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
                EVT_CALL(SetAnimation, ACTOR_SELF, 4, ANIM_Bzzap_Anim03)
                EVT_CALL(SetPartYaw, ACTOR_SELF, 4, 180)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 100)
                EVT_ADD(LVar2, 100)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 4, 0, ACTOR_DECORATION_SWEAT)
                EVT_CALL(FlyPartTo, ACTOR_SELF, 4, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 4, 0)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_END_THREAD
            EVT_WAIT(11)
            EVT_THREAD
                EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 5, SOUND_20CB)
                EVT_CALL(SetAnimation, ACTOR_SELF, 5, ANIM_Bzzap_Anim04)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(AddGoalPos, ACTOR_SELF, -30, -20, 1)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 5, EVT_FLOAT(3.0))
                EVT_CALL(FlyPartTo, ACTOR_SELF, 5, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
                EVT_CALL(SetAnimation, ACTOR_SELF, 5, ANIM_Bzzap_Anim03)
                EVT_CALL(SetPartYaw, ACTOR_SELF, 5, 180)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 100)
                EVT_ADD(LVar2, 100)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 5, 0, ACTOR_DECORATION_SWEAT)
                EVT_CALL(FlyPartTo, ACTOR_SELF, 5, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 5, 0)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_END_THREAD
            EVT_WAIT(11)
            EVT_THREAD
                EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 6, SOUND_20CB)
                EVT_CALL(SetAnimation, ACTOR_SELF, 6, ANIM_Bzzap_Anim04)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(AddGoalPos, ACTOR_SELF, -30, -20, 1)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(3.0))
                EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
                EVT_CALL(SetAnimation, ACTOR_SELF, 6, ANIM_Bzzap_Anim03)
                EVT_CALL(SetPartYaw, ACTOR_SELF, 6, 180)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 100)
                EVT_ADD(LVar2, 100)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 6, 0, ACTOR_DECORATION_SWEAT)
                EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 6, 0)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_END_THREAD
            EVT_WAIT(11)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(30)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_WAIT(30)
            EVT_CALL(StopSound, SOUND_358)
            EVT_CALL(YieldTurn)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 2, SOUND_20CB)
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_Bzzap_Anim04)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, -10, -10, 1)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 2, EVT_FLOAT(3.0))
        EVT_CALL(FlyPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
        EVT_WAIT(2)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 1, BS_FLAGS1_10)
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_Bzzap_Anim03)
        EVT_CALL(SetPartYaw, ACTOR_SELF, 2, 180)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 100)
        EVT_ADD(LVar2, 100)
        EVT_CALL(FlyPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_END_THREAD
    EVT_WAIT(11)
    EVT_THREAD
        EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 3, SOUND_20CB)
        EVT_CALL(SetAnimation, ACTOR_SELF, 3, ANIM_Bzzap_Anim04)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, -10, -10, 1)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 3, EVT_FLOAT(3.0))
        EVT_CALL(FlyPartTo, ACTOR_SELF, 3, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
        EVT_WAIT(2)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 1, BS_FLAGS1_40)
        EVT_CALL(SetAnimation, ACTOR_SELF, 3, ANIM_Bzzap_Anim03)
        EVT_CALL(SetPartYaw, ACTOR_SELF, 3, 180)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 100)
        EVT_ADD(LVar2, 100)
        EVT_CALL(FlyPartTo, ACTOR_SELF, 3, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_END_THREAD
    EVT_WAIT(11)
    EVT_THREAD
        EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 4, SOUND_20CB)
        EVT_CALL(SetAnimation, ACTOR_SELF, 4, ANIM_Bzzap_Anim04)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, -10, -10, 1)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 4, EVT_FLOAT(3.0))
        EVT_CALL(FlyPartTo, ACTOR_SELF, 4, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
        EVT_WAIT(2)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 1, BS_FLAGS1_40)
        EVT_CALL(SetAnimation, ACTOR_SELF, 4, ANIM_Bzzap_Anim03)
        EVT_CALL(SetPartYaw, ACTOR_SELF, 4, 180)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 100)
        EVT_ADD(LVar2, 100)
        EVT_CALL(FlyPartTo, ACTOR_SELF, 4, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_END_THREAD
    EVT_WAIT(11)
    EVT_THREAD
        EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 5, SOUND_20CB)
        EVT_CALL(SetAnimation, ACTOR_SELF, 5, ANIM_Bzzap_Anim04)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, -10, -10, 1)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 5, EVT_FLOAT(3.0))
        EVT_CALL(FlyPartTo, ACTOR_SELF, 5, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
        EVT_WAIT(2)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 1, BS_FLAGS1_40)
        EVT_CALL(SetAnimation, ACTOR_SELF, 5, ANIM_Bzzap_Anim03)
        EVT_CALL(SetPartYaw, ACTOR_SELF, 5, 180)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 100)
        EVT_ADD(LVar2, 100)
        EVT_CALL(FlyPartTo, ACTOR_SELF, 5, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_END_THREAD
    EVT_WAIT(11)
    EVT_WAIT(1)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 6, SOUND_20CB)
    EVT_CALL(SetAnimation, ACTOR_SELF, 6, ANIM_Bzzap_Anim04)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, -10, -10, 1)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(3.0))
    EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetAnimation, ACTOR_SELF, 6, ANIM_Bzzap_Anim03)
            EVT_CALL(SetPartYaw, ACTOR_SELF, 6, 180)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 100)
            EVT_ADD(LVar2, 100)
            EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(StopSound, SOUND_358)
            EVT_CALL(YieldTurn)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_EXEC_WAIT(N(attackThornStab))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(RandInt, 1000, LVar0)
    EVT_IF_LT(LVar0, 500)
        EVT_EXEC_WAIT(N(attackThornStab))
    EVT_ELSE
        EVT_EXEC_WAIT(N(attackSwarmSting))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
