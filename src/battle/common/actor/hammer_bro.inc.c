#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/HammerBros.h"

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL, ANIM_HammerBros_Anim02,
    STATUS_STONE, ANIM_HammerBros_Anim00,
    STATUS_SLEEP, ANIM_HammerBros_Anim11,
    STATUS_POISON, ANIM_HammerBros_Anim02,
    STATUS_STOP, ANIM_HammerBros_Anim00,
    STATUS_STATIC, ANIM_HammerBros_Anim02,
    STATUS_PARALYZE, ANIM_HammerBros_Anim00,
    STATUS_DIZZY, ANIM_HammerBros_Anim12,
    STATUS_FEAR, ANIM_HammerBros_Anim12,
    STATUS_END,
};

s32 N(IdleAnimations2)[] = {
    STATUS_NORMAL, ANIM_HammerBros_Anim0D,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 50,
    STATUS_POISON, 60,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 70,
    STATUS_FEAR, 0,
    STATUS_STATIC, 80,
    STATUS_PARALYZE, 70,
    STATUS_SHRINK, 70,
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
    STATUS_STOP_TURN_MOD, -2,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -3, 35 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -3, -10 },
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
        .idleAnimations = N(IdleAnimations2),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 4,
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
        .index = 5,
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
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations2),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_HAMMER_BROS,
    .level = 27,
    .maxHP = 12,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 30,
    .airLiftChance = 75,
    .hurricaneChance = 60,
    .spookChance = 40,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 2,
    .size = { 28, 38 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 35 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_LABEL(0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_FLAG(STATUS_FLAG_SLEEP)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -5, 15)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, 0, 0)
        EVT_CASE_DEFAULT
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -3, 35)
                    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, -3, -10)
                EVT_CASE_EQ(1)
                    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -5, 15)
                    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, 0, 0)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_GOTO(0)
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
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim0E)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim0F)
            EVT_SET_CONST(LVar2, ANIM_HammerBros_Anim10)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim0F)
            EVT_SET_CONST(LVar2, ANIM_HammerBros_Anim10)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim10)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim0E)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim0E)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim0E)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim15)
            EVT_EXEC_WAIT(DoImmune)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HammerBros_Anim17)
                EVT_WAIT(10)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim0E)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim0E)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim02)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim07)
            EVT_SET_CONST(LVar2, ANIM_HammerBros_Anim0E)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim07)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -2, 1, 0)
                EVT_ELSE
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -5, 3, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim0E)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim02)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attackHammerThrow) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_END_IF
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CHILD_THREAD
            EVT_SET(LVar0, 0)
            EVT_LABEL(0)
            EVT_ADD(LVar0, 20)
            EVT_MOD(LVar0, 360)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 2, 0, 0, LVar0)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_CHILD_THREAD
        EVT_CALL(SetPartPos, ACTOR_SELF, 2, 0, 50, 0)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HammerBros_Anim0C)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_SET(LVar0, 0)
        EVT_LABEL(0)
        EVT_ADD(LVar0, 20)
        EVT_MOD(LVar0, 360)
        EVT_CALL(SetPartRotation, ACTOR_SELF, 2, 0, 0, LVar0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_CHILD_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 23)
    EVT_ADD(LVar1, 23)
    EVT_SUB(LVar2, 2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HammerBros_Anim0C)
    EVT_WAIT(8)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_LABEL(100)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HammerBros_Anim02)
    EVT_END_THREAD
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 2, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, 2, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetPartSounds, ACTOR_SELF, 2, ACTOR_SOUND_JUMP, 0, 0)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 2, SOUND_2E9)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_SET(LVar1, 10)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(1.3))
            EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 15, TRUE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_SUB(LVar0, 40)
            EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 15, TRUE)
            EVT_SUB(LVar0, 30)
            EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 10, TRUE)
            EVT_SUB(LVar0, 20)
            EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 5, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
            EVT_WAIT(20)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetPartSounds, ACTOR_SELF, 2, ACTOR_SOUND_JUMP, 0, 0)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 2, SOUND_2E9)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(1.3))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 15, TRUE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, DMG_STATUS_CHANCE(STATUS_FLAG_SHRINK, 3, 50), 5, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(GetPartOffset, ACTOR_SELF, 2, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 50)
            EVT_SET(LVar1, 10)
            EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 20, TRUE)
            EVT_SUB(LVar0, 30)
            EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 10, TRUE)
            EVT_SUB(LVar0, 20)
            EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 5, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(hammerMiss) = {
    EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HammerBros_Anim02)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HammerBros_Anim0C)
    EVT_WAIT(4)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetPartSounds, ACTOR_SELF, LVar0, ACTOR_SOUND_JUMP, 0, 0)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, LVar0, SOUND_2E9)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    EVT_SET(LVar2, 10)
    EVT_CALL(RandInt, 60, LVar4)
    EVT_SET(LVar5, 30)
    EVT_SUB(LVar5, LVar4)
    EVT_ADD(LVar1, LVar5)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar0, EVT_FLOAT(1.3))
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3, 15, TRUE)
    EVT_SUB(LVar1, 50)
    EVT_SET(LVar2, 10)
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3, 20, TRUE)
    EVT_SUB(LVar1, 30)
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3, 10, TRUE)
    EVT_SUB(LVar1, 20)
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3, 5, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(hammerHit) = {
    EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HammerBros_Anim02)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HammerBros_Anim0C)
    EVT_WAIT(4)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetPartSounds, ACTOR_SELF, LVar0, ACTOR_SOUND_JUMP, 0, 0)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, LVar0, SOUND_2E9)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar0, EVT_FLOAT(1.3))
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3, 15, TRUE)
    EVT_SUB(LVar1, 50)
    EVT_SET(LVar2, 10)
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3, 20, TRUE)
    EVT_SUB(LVar1, 30)
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3, 10, TRUE)
    EVT_SUB(LVar1, 20)
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3, 5, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attackHammerSurge) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(100)
            EVT_ADD(LVar0, 20)
            EVT_MOD(LVar0, 360)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 2, 0, 0, LVar0)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 3, 0, 0, LVar0)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 4, 0, 0, LVar0)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 5, 0, 0, LVar0)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 6, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 23)
    EVT_ADD(LVar1, 23)
    EVT_SUB(LVar2, 2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 4, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 5, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 6, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 2, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
        EVT_CALL(SetPartScale, ACTOR_SELF, 3, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
        EVT_CALL(SetPartScale, ACTOR_SELF, 4, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
        EVT_CALL(SetPartScale, ACTOR_SELF, 5, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, 2, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, 3, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, 4, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, 5, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_SET(LVar0, 2)
            EVT_EXEC(N(hammerMiss))
            EVT_WAIT(5)
            EVT_SET(LVar0, 3)
            EVT_EXEC(N(hammerMiss))
            EVT_WAIT(5)
            EVT_SET(LVar0, 4)
            EVT_EXEC(N(hammerMiss))
            EVT_WAIT(5)
            EVT_SET(LVar0, 5)
            EVT_EXEC(N(hammerMiss))
            EVT_WAIT(5)
            EVT_SET(LVar0, 6)
            EVT_EXEC(N(hammerMiss))
            EVT_WAIT(5)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HammerBros_Anim02)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
            EVT_WAIT(20)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_SET(LVar0, 2)
        EVT_EXEC(N(hammerHit))
        EVT_WAIT(5)
        EVT_SET(LVar0, 3)
        EVT_EXEC(N(hammerHit))
        EVT_WAIT(5)
        EVT_SET(LVar0, 4)
        EVT_EXEC(N(hammerHit))
        EVT_WAIT(5)
        EVT_SET(LVar0, 5)
        EVT_EXEC(N(hammerHit))
        EVT_WAIT(5)
        EVT_SET(LVar0, 6)
        EVT_EXEC(N(hammerHit))
    EVT_END_THREAD
    EVT_WAIT(21)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_10)
    EVT_WAIT(5)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_40)
    EVT_WAIT(5)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_40)
    EVT_WAIT(5)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HammerBros_Anim02)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_40)
    EVT_WAIT(5)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, DMG_STATUS_CHANCE(STATUS_FLAG_SHRINK, 3, 50), 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
    EVT_MULF(LVar0, EVT_FLOAT(100.0))
    EVT_DIVF(LVar0, LVar1)
    EVT_IF_GT(LVar0, 34)
        EVT_EXEC_WAIT(N(attackHammerThrow))
    EVT_ELSE
        EVT_EXEC_WAIT(N(attackHammerSurge))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
