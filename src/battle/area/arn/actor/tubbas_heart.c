#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleBow.h"
#include "sprite/npc/TubbasHeart.h"

#define NAMESPACE b_area_arn_tubbas_heart

extern EvtScript N(init_80223DA0);
extern EvtScript N(takeTurn_802245C8);
extern EvtScript N(idle_80223E98);
extern EvtScript N(handleEvent_80224038);
extern EvtScript N(80224414);
extern EvtScript N(802244DC);
extern EvtScript N(80224B3C);
extern EvtScript N(80225258);
extern EvtScript N(802255D8);

s32 N(IdleAnimations_80223BC0)[] = {
    STATUS_NORMAL,    ANIM_TubbasHeart_Anim01,
    STATUS_STONE,     ANIM_TubbasHeart_Anim00,
    STATUS_SLEEP,     ANIM_TubbasHeart_Anim04,
    STATUS_POISON,    ANIM_TubbasHeart_Anim01,
    STATUS_STOP,      ANIM_TubbasHeart_Anim00,
    STATUS_STATIC,    ANIM_TubbasHeart_Anim00,
    STATUS_PARALYZE,  ANIM_TubbasHeart_Anim00,
    STATUS_PARALYZE,  ANIM_TubbasHeart_Anim00,
    STATUS_DIZZY,     ANIM_TubbasHeart_Anim0D,
    STATUS_DIZZY,     ANIM_TubbasHeart_Anim0D,
    STATUS_FEAR,      ANIM_TubbasHeart_Anim0A,
    STATUS_END,
};

s32 N(IdleAnimations_80223C1C)[] = {
    STATUS_NORMAL,    ANIM_TubbasHeart_Anim0B,
    STATUS_STONE,     ANIM_TubbasHeart_Anim00,
    STATUS_SLEEP,     ANIM_TubbasHeart_Anim04,
    STATUS_POISON,    ANIM_TubbasHeart_Anim0B,
    STATUS_STOP,      ANIM_TubbasHeart_Anim00,
    STATUS_STATIC,    ANIM_TubbasHeart_Anim00,
    STATUS_PARALYZE,  ANIM_TubbasHeart_Anim00,
    STATUS_PARALYZE,  ANIM_TubbasHeart_Anim00,
    STATUS_DIZZY,     ANIM_TubbasHeart_Anim0D,
    STATUS_DIZZY,     ANIM_TubbasHeart_Anim0D,
    STATUS_FEAR,      ANIM_TubbasHeart_Anim0A,
    STATUS_END,
};

s32 N(DefenseTable_80223C78)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable_80223C84)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 0,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 90,
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

ActorPartBlueprint N(PartsTable_80223D30)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80223BC0),
        .defenseTable = N(DefenseTable_80223C78),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET | ACTOR_PART_FLAG_80000000,
        .index = 2,
        .posOffset = { 0, 54, 0 },
        .targetOffset = { 0, -30 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80223BC0),
        .defenseTable = N(DefenseTable_80223C78),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_TUBBA_HEART,
    .level = 0,
    .maxHP = 50,
    .partCount = ARRAY_COUNT( N(PartsTable_80223D30)),
    .partsData = N(PartsTable_80223D30),
    .initScript = &N(init_80223DA0),
    .statusTable = N(StatusTable_80223C84),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 30, 30 },
    .hpBarOffset = { 5, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(init_80223DA0) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, 0)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_802245C8)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_80223E98)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80224038)))
    EVT_CALL(SetPartTargetFlagBits, ACTOR_SELF, 2, ACTOR_PART_TARGET_FLAG_2, TRUE)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(func_80218680_4FF0D0)) {
    Bytecode *args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);

    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    f32 scale = evt_get_float_variable(script, *args++);

    effect->data.energyInOut->pos.x = x;
    effect->data.energyInOut->pos.y = y;
    effect->data.energyInOut->pos.z = z;
    effect->data.energyInOut->scale = scale;

    return ApiStatus_DONE2;
}

EvtScript N(idle_80223E98) = {
    EVT_LABEL(0)
    EVT_CALL(ActorExists, ACTOR_SELF, LVar0)
    EVT_IF_NE(LVar0, FALSE)
        EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar4)
            EVT_IF_NOT_FLAG(LVar4, STATUS_FLAG_SHRINK)
                EVT_ADD(LVar2, 15)
                EVT_SETF(LVar4, EVT_FLOAT(1.0))
            EVT_ELSE
                EVT_ADD(LVar2, 6)
                EVT_SETF(LVar4, EVT_FLOAT(0.4))
            EVT_END_IF
            EVT_CALL(N(func_80218680_4FF0D0), LVar0, LVar1, LVar2, LVar3, LVar4)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80223FD8) = {
    EVT_SET(LVar1, 7077902)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_SET(LVar1, 7077899)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80224038) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_EXEC_WAIT(N(80223FD8))
            EVT_SET_CONST(LVar0, 1)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_TubbasHeart_Anim10)
            EVT_SET_CONST(LVar2, ANIM_TubbasHeart_Anim11)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(80223FD8))
            EVT_SET_CONST(LVar0, 1)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_OR_EQ(EVENT_SHOCK_HIT)
        EVT_CASE_OR_EQ(EVENT_SHOCK_DEATH)
            EVT_EXEC_WAIT(N(80223FD8))
            EVT_SET_CONST(LVar0, 1)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_EXEC_WAIT(N(80223FD8))
            EVT_SET_CONST(LVar0, 1)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TubbasHeart_Anim03)
            EVT_EXEC_WAIT(N(802244DC))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET(LVar1, 7077889)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_SET(LVar1, 7077899)
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_DEATH)
            EVT_EXEC_WAIT(N(80223FD8))
            EVT_SET_CONST(LVar0, 1)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(80223FD8))
            EVT_SET_CONST(LVar0, 1)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TubbasHeart_Anim03)
            EVT_EXEC_WAIT(N(802244DC))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_TubbasHeart_Anim01)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_IF_LE(LVar0, 5)
        EVT_EXEC_WAIT(N(80224414))
        EVT_RETURN
    EVT_ELSE
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80224414) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT(40)
    EVT_CALL(ActorSpeak, MSG_CH3_00C6, ACTOR_SELF, 1, ANIM_TubbasHeart_Anim0D, ANIM_TubbasHeart_Anim0D)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 25)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_DISABLE_CELEBRATION | BS_FLAGS1_BATTLE_FLED, TRUE)
    EVT_CALL(func_8026F60C, 20)
    EVT_RETURN
    EVT_END
};

EvtScript N(802244DC) = {
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 45)
    EVT_SET(LVar1, 0)
    EVT_EXEC_WAIT(D_8029C12C)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TubbasHeart_Anim01)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_802245C8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_IF_NE(LVar0, HIT_RESULT_MISS)
        EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
        EVT_IF_NOT_FLAG(LVar0, 0x00000001)
            EVT_CALL(GetCurrentPartnerID, LVar0)
            EVT_IF_EQ(LVar0, 9)
                EVT_CALL(func_802535B4, 0)
                EVT_BITWISE_OR_CONST(LVar0, 0x3)
                EVT_CALL(SetActorVar, ACTOR_SELF, 2, LVar0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(MoveBattleCamOver, 40)
                EVT_WAIT(40)
                EVT_CALL(ActorSpeak, MSG_CH3_00C3, ACTOR_SELF, 1, ANIM_TubbasHeart_Anim0B, ANIM_TubbasHeart_Anim01)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_PARTNER)
                EVT_CALL(MoveBattleCamOver, 25)
                EVT_WAIT(25)
                EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, 1, ANIM_BattleBow_Talk)
                EVT_CALL(ActorSpeak, MSG_CH3_00C4, ACTOR_PARTNER, 1, ANIM_BattleBow_Talk, ANIM_BattleBow_Idle)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, 1, ANIM_BattleBow_Laugh)
                EVT_CALL(EndActorSpeech, ACTOR_PARTNER, 1, -1, -1)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
                EVT_CALL(MoveBattleCamOver, 30)
                EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
                    EVT_IF_NE(LVar0, 0)
                        EVT_CALL(func_802535B4, 1)
                    EVT_END_IF
                EVT_ELSE
                    EVT_CALL(func_802535B4, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, 3, 1)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(MoveBattleCamOver, 40)
                EVT_WAIT(40)
                EVT_CALL(ActorSpeak, MSG_CH3_00C5, ACTOR_SELF, 1, ANIM_TubbasHeart_Anim0B, ANIM_TubbasHeart_Anim01)
            EVT_END_IF
            EVT_EXEC_WAIT(N(80225258))
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
            EVT_IF_FLAG(LVar0, 0x00000002)
                EVT_CALL(func_802535B4, 1)
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(802255D8))
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar1)
                EVT_ADD(LVar1, 1)
                EVT_CALL(SetActorVar, ACTOR_SELF, 5, LVar1)
                EVT_IF_GE(LVar1, 2)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 2)
                EVT_ELSE
                    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_EXEC_WAIT(N(80224B3C))
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
    EVT_BITWISE_AND_CONST(LVar0, -3)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, LVar0)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80224B3C) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TubbasHeart_Anim03)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 45)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 40)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_EXEC_WAIT(D_8029C12C)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TubbasHeart_Anim01)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TubbasHeart_Anim16)
    EVT_WAIT(5)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TubbasHeart_Anim15)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_SUB(LVar0, 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TubbasHeart_Anim03)
            EVT_EXEC_WAIT(N(802244DC))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 6, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TubbasHeart_Anim01)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 30)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_WAIT(8)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TubbasHeart_Anim03)
            EVT_EXEC_WAIT(N(802244DC))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80225258) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 85, 50, 0)
    EVT_CALL(SetBattleCamZoom, 280)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT(40)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TubbasHeart_Anim0B)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar4)
    EVT_IF_NOT_FLAG(LVar4, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar1, 15)
        EVT_SETF(LVar3, EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_ADD(LVar1, 6)
        EVT_SETF(LVar3, EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_GATHER_MAGIC, 1, LVar0, LVar1, LVar2, LVar3, 60, 0)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 6, LVar0, LVar1, LVar2, LVar3, 60, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20F7)
    EVT_WAIT(60)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar4)
    EVT_IF_NOT_FLAG(LVar4, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar1, 15)
        EVT_SETF(LVar3, EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_ADD(LVar1, 6)
        EVT_SETF(LVar3, EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 3, LVar0, LVar1, LVar2, LVar3, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, LVarF)
    EVT_CALL(EnableActorGlow, ACTOR_SELF, TRUE)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80223C1C)))
    EVT_RETURN
    EVT_END
};

EvtScript N(802255D8) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, 85, 50, 0)
    EVT_CALL(SetBattleCamZoom, 280)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TubbasHeart_Anim0C)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar1, 16)
    EVT_ELSE
        EVT_ADD(LVar1, 6)
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 45, 0)
    EVT_WAIT(60)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TubbasHeart_Anim0B)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_SUB(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
        EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar0)
        EVT_CALL(RemoveEffect, LVar0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 4, 0)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80223BC0)))
    EVT_END_IF
    EVT_CALL(PlaySound, SOUND_20F9)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 5)
            EVT_PLAY_EFFECT(EFFECT_TUBBA_HEART_ATTACK, 1, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 200, 0)
            EVT_WAIT(145)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_ELSE
            EVT_END_IF
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 5)
    EVT_PLAY_EFFECT(EFFECT_TUBBA_HEART_ATTACK, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 200, 0)
    EVT_THREAD
        EVT_WAIT(160)
        EVT_CALL(PlaySound, SOUND_20FC)
    EVT_END_THREAD
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Flail)
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 300)
    EVT_CALL(SetBattleCamOffsetZ, 35)
    EVT_CALL(MoveBattleCamOver, 50)
    EVT_WAIT(56)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_3DB)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Leeching)
    EVT_WAIT(37)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_3DB)
    EVT_WAIT(22)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_20FB)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 12, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_RETURN
    EVT_END
};
