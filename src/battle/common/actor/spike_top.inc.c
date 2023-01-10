#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/SpikeTop.h"

extern s32 N(idleAnimations)[];
extern EvtScript N(init);
extern EvtScript N(idle);
extern EvtScript N(spikeTop_TakeTurn_Ceiling);
extern EvtScript N(spikeTop_HandleEvent_Ceiling);
extern EvtScript N(spikeTop_TakeTurn_Floor);
extern EvtScript N(spikeTop_HandleEvent_Floor);

s32 N(defenseTable)[] = {
    ELEMENT_NORMAL, 4,
    ELEMENT_FIRE, 99,
    ELEMENT_BLAST, 99,
    ELEMENT_END,
};

s32 N(defenseTable_8021C8CC)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 60,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 0,
    STATUS_STATIC, 50,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 75,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
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
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .unk_1D = 14,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_HP_OFFSET_BELOW,
    .type = ACTOR_TYPE_SPIKE_TOP,
    .level = 17,
    .maxHP = 4,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .takeTurnScript = &N(init),
    .statusTable = N(statusTable),
    .escapeChance = 60,
    .airLiftChance = 70,
    .hurricaneChance = 65,
    .spookChance = 60,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 24, 24 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -8, 16 },
    .statusMessageOffset = { 8, 13 },
};

s32 N(idleAnimations_8021C9D0)[] = {
    STATUS_NORMAL,    ANIM_SpikeTop_Anim03,
    STATUS_STONE,     ANIM_SpikeTop_Anim00,
    STATUS_SLEEP,     ANIM_SpikeTop_Anim1B,
    STATUS_POISON,    ANIM_SpikeTop_Anim03,
    STATUS_STOP,      ANIM_SpikeTop_Anim00,
    STATUS_STATIC,    ANIM_SpikeTop_Anim03,
    STATUS_PARALYZE,  ANIM_SpikeTop_Anim00,
    STATUS_DIZZY,     ANIM_SpikeTop_Anim1E,
    STATUS_FEAR,      ANIM_SpikeTop_Anim1E,
    STATUS_END,
};

s32 N(idleAnimations)[] = {
    STATUS_NORMAL,    ANIM_SpikeTop_Anim04,
    STATUS_STONE,     ANIM_SpikeTop_Anim01,
    STATUS_SLEEP,     ANIM_SpikeTop_Anim1C,
    STATUS_POISON,    ANIM_SpikeTop_Anim04,
    STATUS_STOP,      ANIM_SpikeTop_Anim01,
    STATUS_STATIC,    ANIM_SpikeTop_Anim04,
    STATUS_PARALYZE,  ANIM_SpikeTop_Anim01,
    STATUS_DIZZY,     ANIM_SpikeTop_Anim1F,
    STATUS_FEAR,      ANIM_SpikeTop_Anim1F,
    STATUS_END,
};

s32 N(idleAnimations_8021CA68)[] = {
    STATUS_NORMAL,    ANIM_SpikeTop_Anim05,
    STATUS_STONE,     ANIM_SpikeTop_Anim02,
    STATUS_SLEEP,     ANIM_SpikeTop_Anim1D,
    STATUS_POISON,    ANIM_SpikeTop_Anim05,
    STATUS_STOP,      ANIM_SpikeTop_Anim02,
    STATUS_STATIC,    ANIM_SpikeTop_Anim05,
    STATUS_DIZZY,     ANIM_SpikeTop_Anim20,
    STATUS_FEAR,      ANIM_SpikeTop_Anim20,
    STATUS_END,
};

#include "common/UnkBattleFunc1.inc.c"

EvtScript N(init) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
        EVT_CALL(N(UnkBattleFunc1), -10, 0, 10, 0)
        EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(spikeTop_TakeTurn_Ceiling)))
        EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(spikeTop_HandleEvent_Ceiling)))
        EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_FLIPABLE, 0)
    EVT_ELSE
        EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 0, 24)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, -1, -9)
        EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(spikeTop_TakeTurn_Floor)))
        EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(spikeTop_HandleEvent_Floor)))
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_8021C9D0)))
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_HP_OFFSET_BELOW, 0)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_FLIPABLE, 1)
    EVT_END_IF
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(spikeTop_FallDown) = {
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 2)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 1, 20)
    EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, -3, -8)
    EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(spikeTop_TakeTurn_Floor)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(spikeTop_HandleEvent_Floor)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 9, 1)
    EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(defenseTable_8021C8CC)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_8021CA68)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_HP_OFFSET_BELOW, 0)
    EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_SPIKY_TOP, 0)
    EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_FLIPABLE, 1)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_400, 1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim15)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 24)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 2, SOUND_301, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(GetIndexFromPos, ACTOR_SELF, LVarA)
    EVT_MOD(LVarA, 4)
    EVT_CALL(SetGoalToIndex, ACTOR_SELF, LVarA)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(SetHomePos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_SET(LVarD, LVarA)
    EVT_SET(LVarE, LVarB)
    EVT_SET(LVarF, LVarC)
    EVT_SUB(LVarD, LVar0)
    EVT_SUB(LVarE, LVar1)
    EVT_SUB(LVarF, LVar2)
    EVT_DIV(LVarD, 2)
    EVT_DIV(LVarE, 2)
    EVT_DIV(LVarF, 2)
    EVT_ADD(LVar0, LVarD)
    EVT_ADD(LVar1, LVarE)
    EVT_ADD(LVar2, LVarF)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim05)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(spikeTop_HandleEvent_Ceiling) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim14)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim14)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(spikeTop_FallDown))
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim14)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(spikeTop_FallDown))
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim19)
            EVT_SET_CONST(LVar2, ANIM_SpikeTop_Anim1A)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(spikeTop_FallDown))
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim19)
            EVT_SET_CONST(LVar2, ANIM_SpikeTop_Anim1A)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim1A)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim14)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim13)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim08)
            EVT_EXEC_WAIT(DoReturnHome)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim14)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim13)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_UNKNOWN_TRIGGER)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim0D)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim0D)
            EVT_EXEC_WAIT(DoImmune)
            EVT_WAIT(2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_STOP)
                EVT_EXEC_WAIT(N(spikeTop_FallDown))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim14)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim14)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 1)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim09)
            EVT_SET_CONST(LVar2, ANIM_SpikeTop_Anim14)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021D57C) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar3)
    EVT_IF_EQ(LVar3, 2)
        EVT_SET(LVar1, LVar2)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(intTable_8021D5CC)[] = {
    0x00000007, 0x0000000D, 0x00000011, 0x00000015, 0x00000017, 0x00000018, 0x00000017, 0x00000015,
    0x00000011, 0x0000000D, 0x00000007, 0x00000000, 0x00000004, 0x00000007, 0x00000006, 0x00000004,
    0x00000000, 0x00000002, 0x00000000,
};

EvtScript N(spikeTop_HandleEvent_Floor) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim13)
            EVT_SET_CONST(LVar2, ANIM_SpikeTop_Anim15)
            EVT_EXEC_WAIT(N(8021D57C))
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_NE(LVar0, 2)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim16)
                EVT_SET_CONST(LVar2, ANIM_SpikeTop_Anim17)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim18)
                EVT_SET_CONST(LVar2, ANIM_SpikeTop_Anim18)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_NE(LVar0, 2)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim16)
                EVT_SET_CONST(LVar2, ANIM_SpikeTop_Anim17)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim17)
                EVT_EXEC_WAIT(DoDeath)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim18)
                EVT_SET_CONST(LVar2, ANIM_SpikeTop_Anim18)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim18)
                EVT_EXEC_WAIT(DoDeath)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim13)
            EVT_SET_CONST(LVar2, ANIM_SpikeTop_Anim15)
            EVT_EXEC_WAIT(N(8021D57C))
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, 2)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 1, 20)
            EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, -3, -8)
            EVT_CALL(SetActorVar, ACTOR_SELF, 9, 1)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(defenseTable_8021C8CC)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_8021CA68)))
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_SPIKY_TOP, 0)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_400, 1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim13)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
            EVT_THREAD
                EVT_WAIT(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -45)
                EVT_WAIT(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -90)
                EVT_WAIT(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -135)
                EVT_WAIT(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -180)
                EVT_WAIT(1)
            EVT_END_THREAD
            EVT_USE_BUF(EVT_PTR(N(intTable_8021D5CC)))
            EVT_LOOP(19)
                EVT_BUF_READ1(LVar0)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim15)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim13)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim13)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim08)
            EVT_EXEC_WAIT(DoReturnHome)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim13)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim13)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_UNKNOWN_TRIGGER)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim0B)
                EVT_EXEC_WAIT(DoImmune)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim0E)
                EVT_WAIT(8)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim05)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim0B)
                EVT_EXEC_WAIT(DoImmune)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim0C)
                EVT_WAIT(8)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim05)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_WAIT(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_ADD(LVar1, 9)
            EVT_ELSE
                EVT_ADD(LVar1, 24)
            EVT_END_IF
            EVT_CALL(PlayEffect, EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 20, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(20)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim13)
            EVT_SET_CONST(LVar2, ANIM_SpikeTop_Anim15)
            EVT_EXEC_WAIT(N(8021D57C))
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim13)
            EVT_SET_CONST(LVar2, ANIM_SpikeTop_Anim15)
            EVT_EXEC_WAIT(N(8021D57C))
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim13)
            EVT_SET_CONST(LVar2, ANIM_SpikeTop_Anim15)
            EVT_EXEC_WAIT(N(8021D57C))
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim13)
            EVT_SET_CONST(LVar2, ANIM_SpikeTop_Anim15)
            EVT_EXEC_WAIT(N(8021D57C))
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim03)
                EVT_EXEC_WAIT(DoRecover)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim08)
                EVT_SET_CONST(LVar2, ANIM_SpikeTop_Anim13)
                EVT_EXEC_WAIT(DoScareAway)
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim05)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim08)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim05)
            EVT_END_IF
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 7, 0, 0)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim13)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim15)
            EVT_END_IF
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim0B)
                EVT_EXEC_WAIT(DoImmune)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim0C)
                EVT_WAIT(8)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim05)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(spikeTop_TakeTurn_Ceiling) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 0, 24)
    EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, -1, -9)
    EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(spikeTop_TakeTurn_Floor)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(spikeTop_HandleEvent_Floor)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_8021C9D0)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_HP_OFFSET_BELOW, 0)
    EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_FLIPABLE, 1)
    EVT_CALL(GetIndexFromPos, ACTOR_SELF, LVar0)
    EVT_MOD(LVar0, 4)
    EVT_CALL(SetGoalToIndex, ACTOR_SELF, LVar0)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar4, LVar2)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim09)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar4, LVar2)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim01)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_CALL(SetActorSounds, ACTOR_SELF, 2, SOUND_301, 0)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_F)
        EVT_CALL(SetBattleCamZoom, 430)
        EVT_CALL(SetBattleCamOffsetZ, 20)
        EVT_CALL(MoveBattleCamOver, 10)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 4, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(SetPartYaw, ACTOR_SELF, 1, 180)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim15)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar1, 24)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_WAIT(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim00)
            EVT_END_THREAD
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT(8)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim08)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim03)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim15)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 24)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, LVar4)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 65535, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 30)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_WAIT(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim00)
            EVT_END_THREAD
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT(8)
            EVT_CALL(YieldTurn)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim08)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim03)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_LABEL(10)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(spikeTop_TakeTurn_Floor) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_IF_EQ(LVar0, 2)
        EVT_CALL(GetActorVar, ACTOR_SELF, 9, LVar0)
        EVT_SUB(LVar0, 1)
        EVT_IF_GT(LVar0, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 9, LVar0)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_WAIT(30)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_ELSE
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_WAIT(20)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim05)
            EVT_SET_CONST(LVar2, ANIM_SpikeTop_Anim03)
            EVT_EXEC_WAIT(D_8029BBB4)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 0, 24)
            EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, -1, -9)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(defenseTable)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_8021C9D0)))
            EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_400, 0)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_SPIKY_TOP, 1)
        EVT_END_IF
        EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim0B)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim0F)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_WAIT(10)
        EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_WAIT(5)
        EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2021)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim0A)
    EVT_WAIT(20)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20D3)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 3, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_THREAD
                EVT_LOOP(0)
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_ADD(LVar0, 30)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
                    EVT_IF_GT(LVar0, LVar3)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_B)
                EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_END_IF
                EVT_WAIT(15)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -150, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(14.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 200)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim0C)
            EVT_WAIT(10)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(14.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 65535, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim03)
            EVT_WAIT(8)
            EVT_CALL(YieldTurn)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_SpikeTop_Anim08)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_SpikeTop_Anim03)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
