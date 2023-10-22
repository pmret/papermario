#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Bzzap.h"

#define NAMESPACE A(bzzap)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_SWARM_1     = 2,
    PRT_SWARM_2     = 3,
    PRT_SWARM_3     = 4,
    PRT_SWARM_4     = 5,
    PRT_SWARM_5     = 6,
};

enum N(ActorParams) {
    DMG_STING       = 6,
    DMG_SWARM       = 1,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Bzzap_Anim01,
    STATUS_KEY_STONE,     ANIM_Bzzap_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Bzzap_Anim09,
    STATUS_KEY_POISON,    ANIM_Bzzap_Anim01,
    STATUS_KEY_STOP,      ANIM_Bzzap_Anim00,
    STATUS_KEY_STATIC,    ANIM_Bzzap_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_Bzzap_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Bzzap_Anim0A,
    STATUS_KEY_FEAR,      ANIM_Bzzap_Anim0A,
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
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          1,
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
        .targetOffset = { -7, 33 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 2, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_SWARM_1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -5 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_SWARM_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -5 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_SWARM_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -5 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_SWARM_4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -5 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_SWARM_5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -5 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_BZZAP,
    .level = ACTOR_LEVEL_BZZAP,
    .maxHP = 3,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
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
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

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

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetPartScale, ACTOR_SELF, PRT_SWARM_1, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_CALL(SetPartScale, ACTOR_SELF, PRT_SWARM_2, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_CALL(SetPartScale, ACTOR_SELF, PRT_SWARM_3, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_CALL(SetPartScale, ACTOR_SELF, PRT_SWARM_4, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_CALL(SetPartScale, ACTOR_SELF, PRT_SWARM_5, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SLEEP | STATUS_FLAG_DIZZY)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -7, 19)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 2, -6)
            EVT_CALL(N(SetAbsoluteStatusOffsets), -20, 20, 10, 27)
        EVT_ELSE
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -7, 33)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 2, -10)
            EVT_CALL(N(SetAbsoluteStatusOffsets), -16, 22, 4, 22)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReturnHome) = {
    EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bzzap_Anim03)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_SIN_OUT)
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
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim07)
            EVT_SET_CONST(LVar2, ANIM_Bzzap_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim07)
            EVT_SET_CONST(LVar2, ANIM_Bzzap_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim03)
            EVT_SET_CONST(LVar2, ANIM_Bzzap_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_ELSE
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 9, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bzzap_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_Sting) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bzzap_Anim03)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 52, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, EASING_COS_IN)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
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
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BZZAP_STING)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bzzap_Anim04)
            EVT_WAIT(10)
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
    EVT_WAIT(10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_ADD(LVar2, 1)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_QUADRATIC_OUT)
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BZZAP_STING)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bzzap_Anim04)
    EVT_WAIT(6)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, DMG_STATUS_KEY(STATUS_FLAG_POISON, 3, 40), DMG_STING, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SummonSwarmPart) = {
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
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_08)
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

EvtScript N(EVS_Attack_CallSwarm) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_SWARM_1, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_SWARM_2, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_SWARM_3, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_SWARM_4, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_SWARM_5, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BZZAP_CALL_SWARM)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bzzap_Anim05)
    EVT_WAIT(40)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bzzap_Anim01)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(PlaySound, SOUND_MINI_BZZAP_BUZZ)
    EVT_SET(LVar0, PRT_SWARM_1)
    EVT_EXEC_GET_TID(N(EVS_SummonSwarmPart), LVarA)
    EVT_WAIT(11)
    EVT_SET(LVar0, PRT_SWARM_2)
    EVT_EXEC(N(EVS_SummonSwarmPart))
    EVT_WAIT(11)
    EVT_SET(LVar0, PRT_SWARM_3)
    EVT_EXEC(N(EVS_SummonSwarmPart))
    EVT_WAIT(11)
    EVT_SET(LVar0, PRT_SWARM_4)
    EVT_EXEC(N(EVS_SummonSwarmPart))
    EVT_WAIT(11)
    EVT_SET(LVar0, PRT_SWARM_5)
    EVT_EXEC(N(EVS_SummonSwarmPart))
    EVT_LABEL(0)
        EVT_IS_THREAD_RUNNING(LVarA, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_THREAD
                EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_SWARM_1, SOUND_MINI_BZZAP_STING)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SWARM_1, ANIM_Bzzap_Anim04)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(AddGoalPos, ACTOR_SELF, -30, -20, 1)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_SWARM_1, EVT_FLOAT(3.0))
                EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_SWARM_1, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SWARM_1, ANIM_Bzzap_Anim03)
                EVT_CALL(SetPartYaw, ACTOR_SELF, PRT_SWARM_1, 180)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 100)
                EVT_ADD(LVar2, 100)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_SWARM_1, 0, ACTOR_DECORATION_SWEAT)
                EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_SWARM_1, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_SWARM_1, 0)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SWARM_1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_END_THREAD
            EVT_WAIT(11)
            EVT_THREAD
                EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_SWARM_2, SOUND_MINI_BZZAP_STING)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SWARM_2, ANIM_Bzzap_Anim04)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(AddGoalPos, ACTOR_SELF, -30, -20, 1)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_SWARM_2, EVT_FLOAT(3.0))
                EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_SWARM_2, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SWARM_2, ANIM_Bzzap_Anim03)
                EVT_CALL(SetPartYaw, ACTOR_SELF, PRT_SWARM_2, 180)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 100)
                EVT_ADD(LVar2, 100)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_SWARM_2, 0, ACTOR_DECORATION_SWEAT)
                EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_SWARM_2, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_SWARM_2, 0)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SWARM_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_END_THREAD
            EVT_WAIT(11)
            EVT_THREAD
                EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_SWARM_3, SOUND_MINI_BZZAP_STING)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SWARM_3, ANIM_Bzzap_Anim04)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(AddGoalPos, ACTOR_SELF, -30, -20, 1)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_SWARM_3, EVT_FLOAT(3.0))
                EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_SWARM_3, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SWARM_3, ANIM_Bzzap_Anim03)
                EVT_CALL(SetPartYaw, ACTOR_SELF, PRT_SWARM_3, 180)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 100)
                EVT_ADD(LVar2, 100)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_SWARM_3, 0, ACTOR_DECORATION_SWEAT)
                EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_SWARM_3, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_SWARM_3, 0)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SWARM_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_END_THREAD
            EVT_WAIT(11)
            EVT_THREAD
                EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_SWARM_4, SOUND_MINI_BZZAP_STING)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SWARM_4, ANIM_Bzzap_Anim04)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(AddGoalPos, ACTOR_SELF, -30, -20, 1)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_SWARM_4, EVT_FLOAT(3.0))
                EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_SWARM_4, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SWARM_4, ANIM_Bzzap_Anim03)
                EVT_CALL(SetPartYaw, ACTOR_SELF, PRT_SWARM_4, 180)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 100)
                EVT_ADD(LVar2, 100)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_SWARM_4, 0, ACTOR_DECORATION_SWEAT)
                EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_SWARM_4, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_SWARM_4, 0)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SWARM_4, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_END_THREAD
            EVT_WAIT(11)
            EVT_THREAD
                EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_SWARM_5, SOUND_MINI_BZZAP_STING)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SWARM_5, ANIM_Bzzap_Anim04)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(AddGoalPos, ACTOR_SELF, -30, -20, 1)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_SWARM_5, EVT_FLOAT(3.0))
                EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_SWARM_5, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SWARM_5, ANIM_Bzzap_Anim03)
                EVT_CALL(SetPartYaw, ACTOR_SELF, PRT_SWARM_5, 180)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 100)
                EVT_ADD(LVar2, 100)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_SWARM_5, 0, ACTOR_DECORATION_SWEAT)
                EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_SWARM_5, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_SWARM_5, 0)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SWARM_5, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_END_THREAD
            EVT_WAIT(11)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(30)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_WAIT(30)
            EVT_CALL(StopSound, SOUND_MINI_BZZAP_BUZZ)
            EVT_CALL(YieldTurn)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_SWARM_1, SOUND_MINI_BZZAP_STING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SWARM_1, ANIM_Bzzap_Anim04)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, -10, -10, 1)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_SWARM_1, EVT_FLOAT(3.0))
        EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_SWARM_1, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
        EVT_WAIT(2)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SWARM, BS_FLAGS1_INCLUDE_POWER_UPS)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SWARM_1, ANIM_Bzzap_Anim03)
        EVT_CALL(SetPartYaw, ACTOR_SELF, PRT_SWARM_1, 180)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 100)
        EVT_ADD(LVar2, 100)
        EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_SWARM_1, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SWARM_1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_END_THREAD
    EVT_WAIT(11)
    EVT_THREAD
        EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_SWARM_2, SOUND_MINI_BZZAP_STING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SWARM_2, ANIM_Bzzap_Anim04)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, -10, -10, 1)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_SWARM_2, EVT_FLOAT(3.0))
        EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_SWARM_2, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
        EVT_WAIT(2)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SWARM, BS_FLAGS1_NICE_HIT)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SWARM_2, ANIM_Bzzap_Anim03)
        EVT_CALL(SetPartYaw, ACTOR_SELF, PRT_SWARM_2, 180)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 100)
        EVT_ADD(LVar2, 100)
        EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_SWARM_2, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SWARM_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_END_THREAD
    EVT_WAIT(11)
    EVT_THREAD
        EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_SWARM_3, SOUND_MINI_BZZAP_STING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SWARM_3, ANIM_Bzzap_Anim04)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, -10, -10, 1)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_SWARM_3, EVT_FLOAT(3.0))
        EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_SWARM_3, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
        EVT_WAIT(2)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SWARM, BS_FLAGS1_NICE_HIT)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SWARM_3, ANIM_Bzzap_Anim03)
        EVT_CALL(SetPartYaw, ACTOR_SELF, PRT_SWARM_3, 180)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 100)
        EVT_ADD(LVar2, 100)
        EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_SWARM_3, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SWARM_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_END_THREAD
    EVT_WAIT(11)
    EVT_THREAD
        EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_SWARM_4, SOUND_MINI_BZZAP_STING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SWARM_4, ANIM_Bzzap_Anim04)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, -10, -10, 1)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_SWARM_4, EVT_FLOAT(3.0))
        EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_SWARM_4, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
        EVT_WAIT(2)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SWARM, BS_FLAGS1_NICE_HIT)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SWARM_4, ANIM_Bzzap_Anim03)
        EVT_CALL(SetPartYaw, ACTOR_SELF, PRT_SWARM_4, 180)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 100)
        EVT_ADD(LVar2, 100)
        EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_SWARM_4, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SWARM_4, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_END_THREAD
    EVT_WAIT(11)
    EVT_WAIT(1)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_SWARM_5, SOUND_MINI_BZZAP_STING)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SWARM_5, ANIM_Bzzap_Anim04)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, -10, -10, 1)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_SWARM_5, EVT_FLOAT(3.0))
    EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_SWARM_5, LVar0, LVar1, LVar2, 0, -10, EASING_LINEAR)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SWARM, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SWARM_5, ANIM_Bzzap_Anim03)
            EVT_CALL(SetPartYaw, ACTOR_SELF, PRT_SWARM_5, 180)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 100)
            EVT_ADD(LVar2, 100)
            EVT_CALL(FlyPartTo, ACTOR_SELF, PRT_SWARM_5, LVar0, LVar1, LVar2, 0, 10, EASING_LINEAR)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SWARM_5, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(StopSound, SOUND_MINI_BZZAP_BUZZ)
            EVT_CALL(YieldTurn)
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
        EVT_EXEC_WAIT(N(EVS_Attack_Sting))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(RandInt, 1000, LVar0)
    EVT_IF_LT(LVar0, 500)
        EVT_EXEC_WAIT(N(EVS_Attack_Sting))
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_Attack_CallSwarm))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
