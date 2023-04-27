#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/DryBones.h"

#define NAMESPACE b_area_kpa_dry_bones

extern EvtScript N(init);
extern EvtScript N(idle);
extern EvtScript N(takeTurn);
extern EvtScript N(handleEvent);
extern EvtScript N(nextTurn);

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL, ANIM_DryBones_Anim02,
    STATUS_STONE, ANIM_DryBones_Anim00,
    STATUS_SLEEP, ANIM_DryBones_Anim0E,
    STATUS_POISON, ANIM_DryBones_Anim02,
    STATUS_STOP, ANIM_DryBones_Anim00,
    STATUS_STATIC, ANIM_DryBones_Anim02,
    STATUS_PARALYZE, ANIM_DryBones_Anim00,
    STATUS_DIZZY, ANIM_DryBones_Anim0D,
    STATUS_FEAR, ANIM_DryBones_Anim0D,
    STATUS_END,
};

s32 N(IdleAnimations_dead)[] = {
    STATUS_NORMAL, ANIM_DryBones_Anim01,
    STATUS_END,
};

s32 N(IdleAnimations_bone)[] = {
    STATUS_NORMAL, ANIM_DryBones_Anim0F,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 2,
    ELEMENT_FIRE, -10,
    ELEMENT_BLAST, -10,
    ELEMENT_END,
};

s32 N(DefenseTable_dead)[] = {
    ELEMENT_NORMAL, 99,
    ELEMENT_FIRE, -10,
    ELEMENT_BLAST, -10,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 0,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 50,
    STATUS_SHRINK, 60,
    STATUS_STOP, 85,
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

s32 N(StatusTable_dead)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 0,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 0,
    STATUS_STOP, 0,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
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
        .targetOffset = { -8, 30 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_bone),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_DRY_BONES,
    .level = 30,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 75,
    .hurricaneChance = 70,
    .spookChance = 10,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 95,
    .coinReward = 1,
    .size = { 28, 32 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 15 },
    .statusMessageOffset = { 3, 27 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn) = {
    EVT_CALL(GetOriginalActorType, ACTOR_SELF, LVarA)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetOriginalActorType, LVar0, LVar2)
    EVT_IF_NE(LVar2, LVarA)
        EVT_CALL(GetActorHP, LVar0, LVar3)
        EVT_IF_NE(LVar3, 0)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(1)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetActorVar, LVar0, 8, LVar3)
    EVT_IF_NE(LVar3, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(2)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SWITCH(LVar1)
                EVT_CASE_FLAG(STATUS_FLAG_SLEEP)
                    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -6, 24)
                    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, 1, -5)
                EVT_CASE_DEFAULT
                    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -8, 30)
                    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, -1, -10)
            EVT_END_SWITCH
        EVT_CASE_EQ(1)
            EVT_SWITCH(LVar1)
                EVT_CASE_FLAG(STATUS_FLAG_SLEEP)
                    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -1, 10)
                    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, 0, 0)
                EVT_CASE_DEFAULT
                    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -1, 10)
                    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, 0, 0)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(reassemble) = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2D2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_DryBones_Anim08)
    EVT_WAIT(20)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_dead)))
    EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(DefenseTable_dead)))
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable_dead)))
    EVT_CALL(ClearStatusEffects, ACTOR_SELF)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -1, 10)
    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, 0, 0)
    EVT_CALL(RandInt, 0, LVar0)
    EVT_ADD(LVar0, 2)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_CALL(GetOriginalActorType, ACTOR_SELF, LVarA)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetOriginalActorType, LVar0, LVar2)
    EVT_IF_NE(LVar2, LVarA)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(1)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetActorVar, LVar0, 8, LVar3)
    EVT_IF_NE(LVar3, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(2)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_DryBones_Anim07)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_DryBones_Anim07)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION, TRUE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_DryBones_Anim0B)
            EVT_SET_CONST(LVar2, ANIM_DryBones_Anim0C)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION, FALSE)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_DryBones_Anim0B)
            EVT_SET_CONST(LVar2, ANIM_DryBones_Anim0C)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_DryBones_Anim0C)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_DryBones_Anim07)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_DryBones_Anim07)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_EXEC_WAIT(N(reassemble))
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_DryBones_Anim02)
                EVT_EXEC_WAIT(DoImmune)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_DryBones_Anim01)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_DryBones_Anim07)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_WAIT(10)
                EVT_EXEC_WAIT(N(reassemble))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_DryBones_Anim02)
                EVT_EXEC_WAIT(DoRecover)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_DryBones_Anim04)
            EVT_SET_CONST(LVar2, ANIM_DryBones_Anim07)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_DryBones_Anim04)
                EVT_EXEC_WAIT(DoAirLift)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_DryBones_Anim09)
                EVT_EXEC_WAIT(DoAirLift)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                        EVT_CALL(SetActorDispOffset, ACTOR_SELF, -1, -2, 0)
                    EVT_ELSE
                        EVT_CALL(SetActorDispOffset, ACTOR_SELF, -3, -5, 0)
                    EVT_END_IF
                EVT_END_IF
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_DryBones_Anim07)
                EVT_EXEC_WAIT(DoBlowAway)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_DryBones_Anim09)
                EVT_EXEC_WAIT(DoBlowAway)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_DryBones_Anim02)
                EVT_EXEC_WAIT(DoImmune)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_DryBones_Anim01)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(rotateBone) = {
    EVT_SET(LVar0, 0)
    EVT_LABEL(0)
    EVT_CALL(SetPartRotation, ACTOR_SELF, 2, 0, 0, LVar0)
    EVT_ADD(LVar0, 60)
    EVT_MOD(LVar0, 360)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
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
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_DryBones_Anim06)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_SUB(LVar0, 1)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2D4)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_DryBones_Anim09)
            EVT_WAIT(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2D3)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_DryBones_Anim0A)
            EVT_WAIT(20)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations)))
            EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(DefenseTable)))
            EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_2000, FALSE)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -8, 30)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, -1, -10)
            EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar0)
            EVT_CALL(SetEnemyHP, ACTOR_SELF, LVar0)
        EVT_ELSE
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2D4)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_DryBones_Anim09)
            EVT_WAIT(10)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_END_IF
        EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_DryBones_Anim05)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_DryBones_Anim06)
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_DryBones_Anim02)
    EVT_END_THREAD
    EVT_LABEL(100)
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
            EVT_SET(LVarF, LVar0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 20)
            EVT_CALL(SetPartPos, ACTOR_SELF, 2, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 2, SOUND_2D1)
            EVT_CALL(SetPartSounds, ACTOR_SELF, 2, ACTOR_SOUND_WALK, 0, 0)
            EVT_CALL(SetPartSounds, ACTOR_SELF, 2, ACTOR_SOUND_JUMP, 0, 0)
            EVT_EXEC_GET_TID(N(rotateBone), LVarA)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 100)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 2, EVT_FLOAT(12.0))
            EVT_CALL(RunPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_KILL_THREAD(LVarA)
            EVT_IF_EQ(LVarF, HIT_RESULT_LUCKY)
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
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 2, SOUND_2D1)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 2, ACTOR_SOUND_WALK, 0, 0)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 2, ACTOR_SOUND_JUMP, 0, 0)
    EVT_EXEC_GET_TID(N(rotateBone), LVarA)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 2, EVT_FLOAT(12.0))
    EVT_CALL(RunPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(GetPartOffset, ACTOR_SELF, 2, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 100)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(0.7))
            EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LVar0, 0, LVar2, 30, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_KILL_THREAD(LVarA)
            EVT_CALL(YieldTurn)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
