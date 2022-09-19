#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/HurtPlant.h"

#define NAMESPACE b_area_jan_hurt_plant

extern EvtScript N(init_8021DA98);
extern EvtScript N(takeTurn_8021E33C);
extern EvtScript N(idle_8021DAE4);
extern EvtScript N(handleEvent_8021DCF4);

s32 N(idleAnimations_8021D940)[] = {
    STATUS_NORMAL,    ANIM_HurtPlant_Anim2,
    STATUS_STONE,     ANIM_HurtPlant_Anim0,
    STATUS_SLEEP,     ANIM_HurtPlant_AnimC,
    STATUS_POISON,    ANIM_HurtPlant_Anim2,
    STATUS_STOP,      ANIM_HurtPlant_Anim0,
    STATUS_STATIC,    ANIM_HurtPlant_Anim2,
    STATUS_PARALYZE,  ANIM_HurtPlant_Anim0,
    STATUS_DIZZY,     ANIM_HurtPlant_Anim9,
    STATUS_FEAR,      ANIM_HurtPlant_Anim9,
    STATUS_END,
};

s32 N(defenseTable_8021D98C)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_FIRE, 0,
    ELEMENT_END,
};

s32 N(statusTable_8021D9A0)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 95,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 50,
    STATUS_FEAR, 0,
    STATUS_STATIC, 50,
    STATUS_PARALYZE, 90,
    STATUS_SHRINK, 75,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_8021DA4C)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -10, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021D940),
        .defenseTable = N(defenseTable_8021D98C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0xF8,
        .unk_1D = 0xFB,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_HURT_PLANT,
    .level = 16,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(partsTable_8021DA4C)),
    .partsData = N(partsTable_8021DA4C),
    .script = &N(init_8021DA98),
    .statusTable = N(statusTable_8021D9A0),
    .escapeChance = 70,
    .airLiftChance = 20,
    .spookChance = 20,
    .baseStatusChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 95,
    .coinReward = 1,
    .size = { 40, 35 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -18, 23 },
    .statusMessageOffset = { 1, 20 },
};

EvtScript N(init_8021DA98) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8021E33C)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8021DAE4)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021DCF4)))
    EVT_RETURN
    EVT_END
};

#include "common/UnkBattleFunc1.inc.c"

EvtScript N(idle_8021DAE4) = {
    EVT_LABEL(0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_FLAG(STATUS_FLAG_SLEEP)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -6, 14)
            EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, -2, -5)
            EVT_CALL(N(UnkBattleFunc1), -20, 8, 0, 14)
        EVT_CASE_DEFAULT
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -10, 24)
            EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, -8, -5)
            EVT_CALL(N(UnkBattleFunc1), -18, 23, 1, 20)
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021DBFC) = {
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 1)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MOLE_DIG)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HurtPlant_Anim4)
    EVT_WAIT(10)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MOLE_SURFACE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HurtPlant_Anim3)
    EVT_WAIT(10)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021DCF4) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HurtPlant_AnimD)
            EVT_WAIT(3)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HurtPlant_AnimE)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HurtPlant_AnimA)
            EVT_SET_CONST(LVar2, -1)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HurtPlant_AnimA)
            EVT_SET_CONST(LVar2, -1)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HurtPlant_AnimA)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HurtPlant_AnimD)
            EVT_WAIT(3)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HurtPlant_AnimE)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HurtPlant_AnimD)
            EVT_WAIT(3)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HurtPlant_AnimE)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HurtPlant_AnimE)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HurtPlant_AnimD)
            EVT_WAIT(3)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HurtPlant_AnimE)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(8021DBFC))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HurtPlant_AnimD)
            EVT_WAIT(3)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HurtPlant_AnimE)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HurtPlant_AnimE)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HurtPlant_Anim2)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HurtPlant_AnimD)
            EVT_WAIT(3)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HurtPlant_AnimE)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HurtPlant_AnimE)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HurtPlant_Anim2)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HurtPlant_AnimD)
            EVT_WAIT(3)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HurtPlant_AnimE)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MOLE_DIG)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HurtPlant_Anim4)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 1)
            EVT_WAIT(20)
            EVT_CALL(func_8027D32C, ACTOR_SELF)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
            EVT_CALL(RemoveActor, ACTOR_SELF)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HurtPlant_Anim2)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_HurtPlant_Anim2)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021E33C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HurtPlant_Anim4)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 1)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
        EVT_CALL(MoveBattleCamOver, 1)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 27)
        EVT_SET(LVar1, 0)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_WAIT(15)
        EVT_GOTO(123)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MOLE_DIG)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HurtPlant_Anim4)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 1)
    EVT_WAIT(8)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 27)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 350)
    EVT_CALL(SetBattleCamOffsetZ, 45)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 27)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 0, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    EVT_LABEL(123)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MOLE_SURFACE)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HurtPlant_Anim3)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HurtPlant_Anim5)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2C4)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HurtPlant_Anim6)
    EVT_WAIT(6)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HurtPlant_Anim7)
            EVT_WAIT(5)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(8021DBFC))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_POISON)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_ELSE
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, STATUS_FLAG_4 | STATUS_FLAG_20 | STATUS_FLAG_40 | STATUS_FLAG_100 | STATUS_FLAG_200 | STATUS_FLAG_POISON | STATUS_FLAG_80000000, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_IF
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_HurtPlant_Anim7)
            EVT_WAIT(5)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_EXEC_WAIT(N(8021DBFC))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
