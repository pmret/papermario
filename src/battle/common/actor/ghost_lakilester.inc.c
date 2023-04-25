#include "sprite/npc/BattleLakilester.h"

extern EvtScript N(lakilester_init);
extern EvtScript N(lakilester_handleEvent);
extern EvtScript N(lakilester_idle);
extern EvtScript N(lakilester_takeTurn);

s32 N(lakilester_idleAnimations)[] = {
    STATUS_NORMAL, ANIM_BattleLakilester_Idle,
    STATUS_STONE, ANIM_BattleLakilester_Still,
    STATUS_SLEEP, ANIM_BattleLakilester_Still,
    STATUS_POISON, ANIM_BattleLakilester_Idle,
    STATUS_STOP, ANIM_BattleLakilester_Still,
    STATUS_STATIC, ANIM_BattleLakilester_Idle,
    STATUS_PARALYZE, ANIM_BattleLakilester_Still,
    STATUS_DIZZY, ANIM_BattleLakilester_Injured,
    STATUS_FEAR, ANIM_BattleLakilester_Idle,
    STATUS_END,
};

s32 N(lakilester_idleAnimations2)[] = {
    STATUS_NORMAL, ANIM_BattleLakilester_Spiny,
    STATUS_END,
};

s32 N(lakilester_defenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(lakilester_statusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 60,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 75,
    STATUS_STOP, 80,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(lakilester_parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -3, 33 },
        .opacity = 255,
        .idleAnimations = N(lakilester_idleAnimations),
        .defenseTable = N(lakilester_defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -2, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(lakilester_idleAnimations2),
        .defenseTable = N(lakilester_defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint N(lakilester) = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_GHOST_LAKILESTER,
    .level = 23,
    .maxHP = 15,
    .partCount = ARRAY_COUNT(N(lakilester_parts)),
    .partsData = N(lakilester_parts),
    .initScript = &N(lakilester_init),
    .statusTable = N(lakilester_statusTable),
    .escapeChance = 50,
    .airLiftChance = 80,
    .hurricaneChance = 70,
    .spookChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 2,
    .size = { 44, 40 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(lakilester_init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(lakilester_takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(lakilester_idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(lakilester_handleEvent)))
    EVT_RETURN
    EVT_END
};

EvtScript N(lakilester_idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(lakilester_handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_CALL(GetLastElement, LVar1)
            EVT_IF_FLAG(LVar1, DAMAGE_TYPE_SHOCK)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_BattleLakilester_Hurt)
                EVT_EXEC_WAIT(N(OnHitElectric))
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_BattleLakilester_Hurt)
                EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleLakilester_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_BattleLakilester_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleLakilester_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_BattleLakilester_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleLakilester_BurnStill)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleLakilester_Hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleLakilester_Hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleLakilester_Dead)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleLakilester_Hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleLakilester_Hurt)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleLakilester_Run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleLakilester_Hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleLakilester_Dead)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleLakilester_Idle)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleLakilester_Hurt)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleLakilester_Dead)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleLakilester_Idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleLakilester_Run)
            EVT_SET_CONST(LVar2, ANIM_BattleLakilester_Hurt)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleLakilester_Run)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleLakilester_Hurt)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(lakilester_takeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleLakilester_Run)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, 20, 30, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleLakilester_Idle)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar0, -1)
        EVT_ADD(LVar1, 4)
        EVT_ADD(LVar2, 2)
        EVT_CALL(SetPartScale, ACTOR_SELF, 3, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_ADD(LVar0, -3)
        EVT_ADD(LVar1, 10)
        EVT_ADD(LVar2, 5)
        EVT_CALL(SetPartScale, ACTOR_SELF, 3, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 3, ANIM_BattleLakilester_Spiny)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleLakilester_LiftSpiny)
    EVT_LOOP(4)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_ADDF(LVar1, EVT_FLOAT(2.4))
        EVT_ELSE
            EVT_ADD(LVar1, 6)
        EVT_END_IF
        EVT_CALL(SetPartPos, ACTOR_SELF, 3, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar0, -3)
        EVT_ADD(LVar1, 16)
        EVT_ADD(LVar2, 2)
        EVT_SETF(LVar3, EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_ADD(LVar0, -8)
        EVT_ADD(LVar1, 40)
        EVT_ADD(LVar2, 5)
        EVT_SETF(LVar3, EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 0, LVar0, LVar1, LVar2, LVar3, 30, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2C5)
    EVT_THREAD
        EVT_LOOP(15)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 1, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 3, 1, 0, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 3, -1, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetPartDispOffset, ACTOR_SELF, 3, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleLakilester_HoldSpiny)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleLakilester_StrainHoldSpiny)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleLakilester_ThrowSpiny)
    EVT_WAIT(3)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 3, ACTOR_SOUND_JUMP, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_201B)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 3, ANIM_BattleLakilester_SpinySpin)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 3, EVT_FLOAT(1.5))
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(RandInt, 100, LVar3)
            EVT_SUB(LVar3, 50)
            EVT_ADD(LVar0, LVar3)
            EVT_CALL(JumpPartTo, ACTOR_SELF, 3, LVar0, 0, LVar2, 20, TRUE)
            EVT_THREAD
                EVT_ADD(LVar0, -50)
                EVT_CALL(JumpPartTo, ACTOR_SELF, 3, LVar0, 0, LVar2, 15, TRUE)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_END_THREAD
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 60)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleLakilester_Run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 3, ANIM_BattleLakilester_SpinySpin)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 3, EVT_FLOAT(1.5))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpPartTo, ACTOR_SELF, 3, LVar0, LVar1, LVar2, 20, TRUE)
    EVT_THREAD
        EVT_ADD(LVar0, -50)
        EVT_CALL(JumpPartTo, ACTOR_SELF, 3, LVar0, 0, LVar2, 15, TRUE)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_END_THREAD
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar9)
    EVT_SWITCH(LVar9)
        EVT_CASE_EQ(0)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(1)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(2)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 8)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleLakilester_Run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
