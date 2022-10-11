#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/Swooper.h"
#include "battle/action_cmd/stop_leech.h"

extern EvtScript N(init);
extern EvtScript N(idle);
extern EvtScript N(takeTurn);
extern EvtScript N(handleEvent);

extern s32 N(idleAnimations)[];

s32 N(defenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 60,
    STATUS_POISON, 60,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 0,
    STATUS_STATIC, 80,
    STATUS_PARALYZE, 80,
    STATUS_SHRINK, 75,
    STATUS_STOP, 85,
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
        .targetOffset = { 0, 29 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 1,
        .unk_1D = 15,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_HP_OFFSET_BELOW,
    .type = ACTOR_TYPE_SWOOPULA,
    .level = 22,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .script = &N(init),
    .statusTable = N(statusTable),
    .escapeChance = 30,
    .airLiftChance = 95,
    .spookChance = 95,
    .baseStatusChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 1,
    .size = { 31, 24 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, -20 },
    .statusMessageOffset = { 10, -20 },
};

s32 N(idleAnimations)[] = {
    STATUS_NORMAL, ANIM_Swooper_Gray_Anim0C,
    STATUS_STONE, ANIM_Swooper_Gray_Anim0B,
    STATUS_SLEEP, ANIM_Swooper_Gray_Anim0F,
    STATUS_POISON, ANIM_Swooper_Gray_Anim0C,
    STATUS_STOP, ANIM_Swooper_Gray_Anim0B,
    STATUS_STATIC, ANIM_Swooper_Gray_Anim0C,
    STATUS_PARALYZE, ANIM_Swooper_Gray_Anim0B,
    STATUS_DIZZY, ANIM_Swooper_Gray_Anim10,
    STATUS_FEAR, ANIM_Swooper_Gray_Anim10,
    STATUS_END,
};

s32 N(idleAnimations_flying)[] = {
    STATUS_NORMAL, ANIM_Swooper_Gray_Anim02,
    STATUS_STONE, ANIM_Swooper_Gray_Anim01,
    STATUS_SLEEP, ANIM_Swooper_Gray_Anim13,
    STATUS_POISON, ANIM_Swooper_Gray_Anim02,
    STATUS_STOP, ANIM_Swooper_Gray_Anim01,
    STATUS_STATIC, ANIM_Swooper_Gray_Anim02,
    STATUS_PARALYZE, ANIM_Swooper_Gray_Anim01,
    STATUS_DIZZY, ANIM_Swooper_Gray_Anim14,
    STATUS_FEAR, ANIM_Swooper_Gray_Anim14,
    STATUS_END,
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
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim02)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, -24, 0)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 11)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_HP_OFFSET_BELOW, 1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations)))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim0C)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 24)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim02)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 11)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(hadleEvent_flying) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim17)
            EVT_SET_CONST(LVar2, ANIM_Swooper_Gray_Anim18)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim17)
            EVT_SET_CONST(LVar2, ANIM_Swooper_Gray_Anim18)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim18)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(func_80269470)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(func_80269470)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_THREAD
                EVT_WAIT(30)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_END_THREAD
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim02)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim02)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 0)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim02)
            EVT_SET_CONST(LVar2, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim02)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/UnkBattleFunc1.inc.c"

EvtScript N(knockDown) = {
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
    EVT_IF_LE(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_HP_OFFSET_BELOW, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim02)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 24)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
    EVT_IF_EQ(LVarA, -1)
        EVT_CALL(SetHomePos, ACTOR_SELF, LVar0, 45, LVar2)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetGoalToHome, ACTOR_SELF)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
    EVT_ELSE
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 45, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
        EVT_CALL(GetIndexFromPos, ACTOR_SELF, LVarA)
        EVT_MOD(LVarA, 4)
        EVT_ADD(LVarA, 4)
        EVT_CALL(SetGoalToIndex, ACTOR_SELF, LVarA)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
        EVT_CALL(SetHomePos, ACTOR_SELF, LVarA, LVarB, LVarC)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetGoalToHome, ACTOR_SELF)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
    EVT_END_IF
    EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 0, -10)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 0, 22)
    EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_flying)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 1)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(hadleEvent_flying))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(GetBattlePhase, LVar0)
            EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim0E)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(GetBattlePhase, LVar0)
            EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim0E)
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_EXEC_WAIT(N(knockDown))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetBattlePhase, LVar0)
            EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim17)
                EVT_SET_CONST(LVar2, ANIM_Swooper_Gray_Anim18)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim11)
                EVT_SET_CONST(LVar2, ANIM_Swooper_Gray_Anim12)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_EXEC_WAIT(N(knockDown))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetBattlePhase, LVar0)
            EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim17)
                EVT_SET_CONST(LVar2, ANIM_Swooper_Gray_Anim18)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim18)
                EVT_EXEC_WAIT(DoDeath)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim11)
                EVT_SET_CONST(LVar2, ANIM_Swooper_Gray_Anim12)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim12)
                EVT_EXEC_WAIT(DoDeath)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(func_80269470)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(D_8029A76C)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(func_80269470)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(D_8029A76C)
            EVT_THREAD
                EVT_WAIT(30)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_END_THREAD
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim0C)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetBattlePhase, LVar0)
            EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_WAIT(10)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
                EVT_EXEC_WAIT(DoDeath)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim0E)
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_WAIT(10)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim0E)
                EVT_EXEC_WAIT(DoDeath)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_HP_OFFSET_BELOW, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_flying)))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim02)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 1)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_HP_OFFSET_BELOW, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -24, 0)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim02)
            EVT_SET_CONST(LVar2, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/UnkBattleFunc2.inc.c"

EvtScript N(takeTurn_flying) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim02)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim02)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
        EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, 0)
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 2, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_WAIT(10)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim06)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 50)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim06)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(10.0))
            EVT_WAIT(15)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(YieldTurn)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(HIT_RESULT_HIT_STATIC)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_STATIC)
                EVT_SET(LocalFlag(0), 0)
            EVT_ELSE
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_WAIT(10)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim06)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, -4, -8, -15)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim06)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
    EVT_IF_EQ(LocalFlag(0), 1)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 0, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_STONE)
        EVT_WAIT(10)
        EVT_LOOP(2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim02)
            EVT_WAIT(21)
            EVT_LOOP(2)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3E0)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.5), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_WAIT(5)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.5), EVT_FLOAT(1.0))
            EVT_WAIT(2)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.6), EVT_FLOAT(1.6), EVT_FLOAT(1.0))
            EVT_WAIT(10)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 2, BS_FLAGS1_40)
            EVT_WAIT(30)
        EVT_END_LOOP
    EVT_ELSE
        EVT_CALL(ShowMessageBox, 49, 32767)
        EVT_CALL(func_802694A4, 1)
        EVT_CALL(LoadActionCommand, ACTION_COMMAND_STOP_LEECH)
        EVT_CALL(func_802A9000_425590)
        EVT_CALL(SetupMashMeter, 1, 30, 0, 0, 0, 0)
        EVT_WAIT(10)
        EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, 0)
        EVT_CALL(func_802A9110_4256A0, 0, 32767, 3)
        EVT_SET(LVarD, 0)
        EVT_LOOP(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim02)
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(21)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3000C)
            EVT_LOOP(2)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3E0)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                EVT_SET(LocalFlag(0), 0)
                EVT_LOOP(1)
                    EVT_CALL(GetActionSuccessCopy, LVar1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_SET(LocalFlag(0), 1)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_EQ(LocalFlag(0), 1)
                    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
                EVT_SET(LocalFlag(0), 0)
                EVT_LOOP(1)
                    EVT_CALL(GetActionSuccessCopy, LVar1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_SET(LocalFlag(0), 1)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_EQ(LocalFlag(0), 1)
                    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
                EVT_SET(LocalFlag(0), 0)
                EVT_LOOP(1)
                    EVT_CALL(GetActionSuccessCopy, LVar1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_SET(LocalFlag(0), 1)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_EQ(LocalFlag(0), 1)
                    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
                EVT_SET(LocalFlag(0), 0)
                EVT_LOOP(1)
                    EVT_CALL(GetActionSuccessCopy, LVar1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_SET(LocalFlag(0), 1)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_EQ(LocalFlag(0), 1)
                    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.5), EVT_FLOAT(1.0))
                EVT_SET(LocalFlag(0), 0)
                EVT_LOOP(1)
                    EVT_CALL(GetActionSuccessCopy, LVar1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_SET(LocalFlag(0), 1)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_EQ(LocalFlag(0), 1)
                    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
                EVT_SET(LocalFlag(0), 0)
                EVT_LOOP(1)
                    EVT_CALL(GetActionSuccessCopy, LVar1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_SET(LocalFlag(0), 1)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_EQ(LocalFlag(0), 1)
                    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
                EVT_SET(LocalFlag(0), 0)
                EVT_LOOP(1)
                    EVT_CALL(GetActionSuccessCopy, LVar1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_SET(LocalFlag(0), 1)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_EQ(LocalFlag(0), 1)
                    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
                EVT_SET(LocalFlag(0), 0)
                EVT_LOOP(1)
                    EVT_CALL(GetActionSuccessCopy, LVar1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_SET(LocalFlag(0), 1)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_EQ(LocalFlag(0), 1)
                    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                EVT_SET(LocalFlag(0), 0)
                EVT_LOOP(1)
                    EVT_CALL(GetActionSuccessCopy, LVar1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_SET(LocalFlag(0), 1)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_EQ(LocalFlag(0), 1)
                    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(5)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3E0)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(1)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(1)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(1)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(1)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.5), EVT_FLOAT(1.0))
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(2)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.6), EVT_FLOAT(1.6), EVT_FLOAT(1.0))
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(10)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(2)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 2, BS_FLAGS1_40)
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LVar3)
            EVT_IF_NE(LVar3, 0)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_206D)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_214)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 15)
                EVT_CALL(N(UnkBattleFunc2), LVar0, LVar1, LVar2, LVar3)
                EVT_THREAD
                    EVT_WAIT(15)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_25C)
                    EVT_CALL(N(UnkBattleFunc2_2), LVar0, LVar1, LVar2, LVar3)
                EVT_END_THREAD
                EVT_ADD(LVar0, 20)
                EVT_ADD(LVar1, 20)
                EVT_CALL(PlayEffect, EFFECT_RECOVER, 0, LVar0, LVar1, LVar2, LVar3, 0, 0, 0, 0, 0, 0, 0, 0)
                EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
                EVT_ADD(LVar0, LVar3)
                EVT_CALL(SetEnemyHP, ACTOR_SELF, LVar0)
            EVT_ELSE
                EVT_ADD(LVarD, 1)
                EVT_IF_GT(LVarD, 1)
                    EVT_CALL(func_80269470)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(GetPlayerHP, LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_CALL(func_80269470)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(30)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(func_80269470)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim02)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_EXEC_WAIT(N(returnHome))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(takeTurn_flying))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim02)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_HP_OFFSET_BELOW, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 24)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 2, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_WAIT(10)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim06)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -50, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim06)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -40, 0)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(10.0))
            EVT_WAIT(15)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(YieldTurn)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(HIT_RESULT_HIT_STATIC)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_STATIC)
                EVT_SET(LocalFlag(0), 0)
            EVT_ELSE
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_WAIT(10)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim06)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, -4, -8, -15)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim06)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -40, 0)
    EVT_IF_EQ(LocalFlag(0), 1)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 0, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_STONE)
        EVT_WAIT(10)
        EVT_LOOP(2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim02)
            EVT_WAIT(21)
            EVT_LOOP(2)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3E0)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.5), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3E0)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.5), EVT_FLOAT(1.0))
            EVT_WAIT(2)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.6), EVT_FLOAT(1.6), EVT_FLOAT(1.0))
            EVT_WAIT(10)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 2, BS_FLAGS1_40)
            EVT_WAIT(30)
        EVT_END_LOOP
    EVT_ELSE
        EVT_CALL(ShowMessageBox, 49, 32767)
        EVT_CALL(func_802694A4, 1)
        EVT_CALL(LoadActionCommand, ACTION_COMMAND_STOP_LEECH)
        EVT_CALL(func_802A9000_425590)
        EVT_CALL(SetupMashMeter, 1, 30, 0, 0, 0, 0)
        EVT_WAIT(10)
        EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, 0)
        EVT_CALL(func_802A9110_4256A0, 0, 32767, 3)
        EVT_SET(LVarD, 0)
        EVT_LOOP(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim02)
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(21)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_3000C)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3E0)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(1)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(1)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(1)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(1)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.5), EVT_FLOAT(1.0))
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(2)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.6), EVT_FLOAT(1.6), EVT_FLOAT(1.0))
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(10)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(2)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 2, BS_FLAGS1_40)
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LVar3)
            EVT_IF_NE(LVar3, 0)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_206D)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_214)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 15)
                EVT_CALL(N(UnkBattleFunc2), LVar0, LVar1, LVar2, LVar3)
                EVT_THREAD
                    EVT_WAIT(15)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_25C)
                    EVT_CALL(N(UnkBattleFunc2_2), LVar0, LVar1, LVar2, LVar3)
                EVT_END_THREAD
                EVT_ADD(LVar0, 20)
                EVT_ADD(LVar1, 20)
                EVT_CALL(PlayEffect, EFFECT_RECOVER, 0, LVar0, LVar1, LVar2, LVar3, 0, 0, 0, 0, 0, 0, 0, 0)
                EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
                EVT_ADD(LVar0, LVar3)
                EVT_CALL(SetEnemyHP, ACTOR_SELF, LVar0)
            EVT_ELSE
                EVT_ADD(LVarD, 1)
                EVT_IF_GT(LVarD, 1)
                    EVT_CALL(func_80269470)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(GetPlayerHP, LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_CALL(func_80269470)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(35)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(func_80269470)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Swooper_Gray_Anim02)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_EXEC_WAIT(N(returnHome))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
