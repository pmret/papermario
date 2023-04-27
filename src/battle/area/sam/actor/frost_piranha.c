#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/LargePiranha.h"

#define NAMESPACE b_area_sam_frost_piranha

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(attack_bite);
extern EvtScript N(attack_icy_breath);

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL, ANIM_LargePiranha_Frost_Anim01,
    STATUS_STONE, ANIM_LargePiranha_Frost_Anim00,
    STATUS_SLEEP, ANIM_LargePiranha_Frost_Anim00,
    STATUS_POISON, ANIM_LargePiranha_Frost_Anim01,
    STATUS_STOP, ANIM_LargePiranha_Frost_Anim00,
    STATUS_STATIC, ANIM_LargePiranha_Frost_Anim00,
    STATUS_PARALYZE, ANIM_LargePiranha_Frost_Anim00,
    STATUS_PARALYZE, ANIM_LargePiranha_Frost_Anim00,
    STATUS_DIZZY, ANIM_LargePiranha_Frost_Anim0F,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_FIRE, -2,
    ELEMENT_ICE, 99,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 95,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 50,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 90,
    STATUS_SHRINK, 75,
    STATUS_STOP, 85,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 1,
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
        .targetOffset = { -15, 50 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 3, -14 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_FROST_PIRANHA,
    .level = 22,
    .maxHP = 10,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 70,
    .airLiftChance = 20,
    .hurricaneChance = 20,
    .spookChance = 20,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 60, 52 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -22, 32 },
    .statusMessageOffset = { 1, 44 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_RETURN
    EVT_END
};

#include "common/UnkBattleFunc1.inc.c"

EvtScript N(idle) = {
    EVT_LABEL(0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_DIZZY)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -27, 33)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, 5, -11)
        EVT_CALL(N(UnkBattleFunc1), -37, 9, -7, 31)
    EVT_ELSE
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -15, 50)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, 3, -14)
        EVT_CALL(N(UnkBattleFunc1), -22, 32, 1, 44)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(return_home) = {
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim03)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim01)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
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
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Frost_Anim0E)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Frost_Anim10)
            EVT_SET_CONST(LVar2, ANIM_LargePiranha_Frost_Anim11)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Frost_Anim10)
            EVT_SET_CONST(LVar2, ANIM_LargePiranha_Frost_Anim11)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Frost_Anim11)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Frost_Anim0E)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Frost_Anim0E)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Frost_Anim0E)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Frost_Anim0E)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(return_home))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Frost_Anim0E)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Frost_Anim0E)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Frost_Anim01)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Frost_Anim0E)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Frost_Anim0E)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Frost_Anim01)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Frost_Anim03)
            EVT_SET_CONST(LVar2, ANIM_LargePiranha_Frost_Anim0E)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Frost_Anim03)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Frost_Anim03)
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
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_EXEC_WAIT(N(attack_bite))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_FROZEN)
        EVT_EXEC_WAIT(N(attack_bite))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(RandInt, 1000, LVar0)
    EVT_IF_LT(LVar0, 250)
        EVT_EXEC_WAIT(N(attack_icy_breath))
    EVT_ELSE
        EVT_EXEC_WAIT(N(attack_bite))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(attack_bite) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim18)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
        EVT_WAIT(8)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 27)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar3, LVar0)
        EVT_SET(LVar4, LVar1)
        EVT_SET(LVar5, LVar2)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar6, LVar7, LVar8)
        EVT_ADD(LVar3, LVar6)
        EVT_ADD(LVar4, LVar7)
        EVT_ADD(LVar5, LVar8)
        EVT_DIV(LVar3, 2)
        EVT_DIV(LVar4, 2)
        EVT_DIV(LVar5, 2)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamTarget, LVar3, LVar4, LVar5)
        EVT_CALL(SetBattleCamZoom, 300)
        EVT_CALL(SetBattleCamOffsetZ, 40)
        EVT_WAIT(20)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim17)
        EVT_WAIT(8)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim03)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim03)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_ADD(LVar0, 10)
        EVT_ELSE
            EVT_ADD(LVar0, 27)
        EVT_END_IF
        EVT_SET(LVar1, 0)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim01)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20DE)
    EVT_END_THREAD
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim05)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim06)
            EVT_WAIT(6)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim07)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(14)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(GetBattlePhase, LVar0)
            EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim18)
                EVT_WAIT(10)
                EVT_CALL(SetGoalToHome, ACTOR_SELF)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim17)
                EVT_WAIT(10)
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, FALSE)
            EVT_ELSE
                EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
                EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
                EVT_EXEC_WAIT(N(return_home))
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim05)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim06)
    EVT_WAIT(1)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim07)
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
            EVT_CALL(GetBattlePhase, LVar0)
            EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim18)
                EVT_WAIT(10)
                EVT_CALL(SetGoalToHome, ACTOR_SELF)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim17)
                EVT_WAIT(10)
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, FALSE)
            EVT_ELSE
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
                EVT_EXEC_WAIT(N(return_home))
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/UnkEffect6FFunc.inc.c"

EvtScript N(attack_icy_breath) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim03)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim03)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar0, 20)
    EVT_ELSE
        EVT_ADD(LVar0, 50)
    EVT_END_IF
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim01)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim0B)
    EVT_WAIT(11)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3AB)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar0, 12)
        EVT_SET(LVar1, 5)
        EVT_SETF(LVar3, EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_ADD(LVar0, 32)
        EVT_SET(LVar1, 13)
        EVT_SETF(LVar3, EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(N(UnkEffect6FFunc), LVar2, LVar0, LVar1, LVar2, LVar3, 30, 120, 0, 120)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim0C)
    EVT_WAIT(5)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_ICE, STATUS_FLAG_FROZEN, 1, BS_FLAGS1_10) //@bug malformed status word
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim0D)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(14)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
            EVT_EXEC_WAIT(N(return_home))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_ICE | DAMAGE_TYPE_STATUS_ALWAYS_HITS, SUPPRESS_EVENT_ALL, DMG_STATUS_IGNORE_RES(STATUS_FLAG_FROZEN, 2), 0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_LargePiranha_Frost_Anim0D)
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_EXEC_WAIT(N(return_home))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
