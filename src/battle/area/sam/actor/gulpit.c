#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/Gulpit.h"

#define NAMESPACE b_area_sam_gulpit

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);

s32 N(IdleAnimations1)[] = {
    STATUS_NORMAL, ANIM_Gulpit_Anim01,
    STATUS_STONE, ANIM_Gulpit_Anim00,
    STATUS_SLEEP, ANIM_Gulpit_Anim0F,
    STATUS_POISON, ANIM_Gulpit_Anim01,
    STATUS_STOP, ANIM_Gulpit_Anim00,
    STATUS_STATIC, ANIM_Gulpit_Anim01,
    STATUS_PARALYZE, ANIM_Gulpit_Anim00,
    STATUS_DIZZY, ANIM_Gulpit_Anim0E,
    STATUS_FEAR, ANIM_Gulpit_Anim0E,
    STATUS_END,
};

s32 N(IdleAnimations2)[] = {
    STATUS_NORMAL, ANIM_Gulpit_Anim10,
    STATUS_END,
};

s32 N(IdleAnimations3)[] = {
    STATUS_NORMAL, ANIM_Gulpit_Anim12,
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
    STATUS_POISON, 80,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 0,
    STATUS_STATIC, 10,
    STATUS_PARALYZE, 80,
    STATUS_SHRINK, 75,
    STATUS_STOP, 85,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 1,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -7, 48 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations1),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -3, -23 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations2),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations3),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GULPIT,
    .level = 22,
    .maxHP = 12,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
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
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -3, 37 },
    .statusMessageOffset = { 10, 45 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim03)
    EVT_EXEC_WAIT(DoReturnHome)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Gulpit_Anim01)
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
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0C)
            EVT_SET_CONST(LVar2, ANIM_Gulpit_Anim0D)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0C)
            EVT_SET_CONST(LVar2, ANIM_Gulpit_Anim0D)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0D)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim01)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim01)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim03)
            EVT_SET_CONST(LVar2, ANIM_Gulpit_Anim0B)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim03)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim03)
            EVT_EXEC_WAIT(DoBlowAway)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attack_lick) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Gulpit_Anim03)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 10, 0, 0)
    EVT_ELSE
        EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 0, 0)
    EVT_END_IF
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Gulpit_Anim01)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EE)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Gulpit_Anim04)
    EVT_WAIT(9)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
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
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
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

EvtScript N(attack_rock) = {
    EVT_SET(LVarA, LVar0)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_SUB(LVar2, 1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Gulpit_Anim02)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Gulpit_Anim01)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EE)
    EVT_CALL(GetActorVar, LVarA, 0, LVar0)
    EVT_SET(LVarB, LVar0)
    EVT_SWITCH(LVarB)
        EVT_CASE_EQ(0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Gulpit_Anim05)
            EVT_WAIT(3)
            EVT_CALL(RemoveActor, LVarA)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Gulpit_Anim06)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Gulpit_Anim07)
            EVT_SET(LVarA, 2)
        EVT_CASE_EQ(1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Gulpit_Anim08)
            EVT_WAIT(3)
            EVT_CALL(RemoveActor, LVarA)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Gulpit_Anim09)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Gulpit_Anim0A)
            EVT_SET(LVarA, 3)
    EVT_END_SWITCH
    EVT_CALL(SetPartSounds, ACTOR_SELF, LVarA, ACTOR_SOUND_JUMP, 985, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
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
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
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
        EVT_CASE_EQ(2)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 7, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(3)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Gulpit_Anim01)
            EVT_CALL(GetPartOffset, ACTOR_SELF, LVarA, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, -100)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVarA, EVT_FLOAT(1.0))
            EVT_CALL(JumpPartTo, ACTOR_SELF, LVarA, LVar0, LVar1, LVar2, 25, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVarA, ACTOR_PART_FLAG_INVISIBLE, TRUE)
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

EvtScript N(takeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_EXEC_WAIT(N(attack_lick))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_EXEC_WAIT(N(attack_lick))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVarA, 0)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_10000)
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
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(attack_lick))
        EVT_CASE_EQ(1)
            EVT_SET(LVar0, LVarB)
            EVT_EXEC_WAIT(N(attack_rock))
        EVT_CASE_EQ(2)
            EVT_CALL(RandInt, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_SET(LVar0, LVarB)
                EVT_CASE_EQ(1)
                    EVT_SET(LVar0, LVarC)
            EVT_END_SWITCH
            EVT_EXEC_WAIT(N(attack_rock))
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
            EVT_EXEC_WAIT(N(attack_rock))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

