#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/SmallPiranha.h"

#define NAMESPACE b_area_mim_piranha_plant

extern EvtScript N(init_8021D498);
extern EvtScript N(takeTurn_8021DCD4);
extern EvtScript N(idle_8021D4E4);
extern EvtScript N(handleEvent_8021D60C);

s32 N(idleAnimations_8021D330)[] = {
    STATUS_NORMAL,    ANIM_SmallPiranha_Anim01,
    STATUS_STONE,     ANIM_SmallPiranha_Anim00,
    STATUS_SLEEP,     ANIM_SmallPiranha_Anim00,
    STATUS_POISON,    ANIM_SmallPiranha_Anim01,
    STATUS_STOP,      ANIM_SmallPiranha_Anim00,
    STATUS_STATIC,    ANIM_SmallPiranha_Anim01,
    STATUS_PARALYZE,  ANIM_SmallPiranha_Anim00,
    STATUS_DIZZY,     ANIM_SmallPiranha_Anim01,
    STATUS_FEAR,      ANIM_SmallPiranha_Anim01,
    STATUS_END,
};

s32 N(unk_missing_8021D37C)[] = {
    STATUS_NORMAL, ANIM_SmallPiranha_Anim01,
    STATUS_END,
};

s32 N(unk_missing_8021D388)[] = {
    STATUS_NORMAL, ANIM_SmallPiranha_Anim06,
    STATUS_END,
};

s32 N(defenseTable_8021D394)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8021D3A0)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 95,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 50,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 80,
    STATUS_STOP, 90,
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

ActorPartBlueprint N(partsTable_8021D44C)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 35 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021D330),
        .defenseTable = N(defenseTable_8021D394),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP,
        .elementImmunityFlags = 0,
        .unk_1D = 246,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_PIRANHA_PLANT,
    .level = 11,
    .maxHP = 5,
    .partCount = ARRAY_COUNT(N(partsTable_8021D44C)),
    .partsData = N(partsTable_8021D44C),
    .script = &N(init_8021D498),
    .statusTable = N(statusTable_8021D3A0),
    .escapeChance = 70,
    .airLiftChance = 20,
    .spookChance = 20,
    .baseStatusChance = 40,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 38, 38 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -7, 33 },
    .statusMessageOffset = { 10, 33 },
};

EvtScript N(init_8021D498) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8021DCD4)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8021D4E4)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021D60C)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8021D4E4) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(8021D4F4) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 1)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SmallPiranha_Anim04)
    EVT_WAIT(10)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SmallPiranha_Anim03)
    EVT_WAIT(10)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021D60C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SmallPiranha_Anim09)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SmallPiranha_Anim0A)
            EVT_SET_CONST(LVar2, ANIM_SmallPiranha_Anim0B)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SmallPiranha_Anim0A)
            EVT_SET_CONST(LVar2, ANIM_SmallPiranha_Anim0B)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SmallPiranha_Anim0B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SmallPiranha_Anim09)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SmallPiranha_Anim09)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SmallPiranha_Anim09)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SmallPiranha_Anim09)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(8021D4F4))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SmallPiranha_Anim09)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SmallPiranha_Anim09)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SmallPiranha_Anim01)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_THREAD
                EVT_WAIT(10)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                    EVT_ADD(LVar0, 0)
                    EVT_ADD(LVar1, 14)
                EVT_ELSE
                    EVT_ADD(LVar0, 0)
                    EVT_ADD(LVar1, 35)
                EVT_END_IF
                EVT_CALL(PlayEffect, EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 20, 0, 0, 0, 0, 0, 0, 0, 0)
                EVT_WAIT(20)
            EVT_END_THREAD
            EVT_LOOP(40)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SmallPiranha_Anim01)
                EVT_WAIT(1)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SmallPiranha_Anim06)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SmallPiranha_Anim01)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SmallPiranha_Anim09)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SmallPiranha_Anim09)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SmallPiranha_Anim01)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SmallPiranha_Anim09)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SmallPiranha_Anim04)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 1)
            EVT_WAIT(8)
            EVT_CALL(func_8027D32C, ACTOR_SELF)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
            EVT_CALL(RemoveActor, ACTOR_SELF)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SmallPiranha_Anim09)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SmallPiranha_Anim09)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021DCD4) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SmallPiranha_Anim04)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 1)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
        EVT_CALL(MoveBattleCamOver, 1)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 20)
        EVT_SET(LVar1, 0)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_WAIT(15)
        EVT_GOTO(123)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SmallPiranha_Anim04)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 1)
    EVT_WAIT(8)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 350)
    EVT_CALL(SetBattleCamOffsetZ, 45)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
    EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar0, 8)
        EVT_ADD(LVar0, -3)
    EVT_ELSE
        EVT_ADD(LVar0, 20)
    EVT_END_IF
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 0, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, FALSE, FALSE)
    EVT_LABEL(123)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SmallPiranha_Anim03)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SmallPiranha_Anim05)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
            EVT_IF_NOT_FLAG(LVar5, STATUS_FLAG_SHRINK)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SmallPiranha_Anim06)
                EVT_WAIT(2)
            EVT_END_IF
            EVT_THREAD
                EVT_WAIT(6)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20DE)
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SmallPiranha_Anim07)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SmallPiranha_Anim08)
            EVT_WAIT(2)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(8021D4F4))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SmallPiranha_Anim06)
    EVT_WAIT(2)
    EVT_THREAD
        EVT_WAIT(6)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20DE)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SmallPiranha_Anim07)
    EVT_WAIT(10)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_WAIT(2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SmallPiranha_Anim08)
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_EXEC_WAIT(N(8021D4F4))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
