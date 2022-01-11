#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/battle_bandit.h"
#include "sprite/npc/world_parakarry.h"

#define NAMESPACE b_area_sbk_bandit

extern EvtSource N(init_8021D750);
extern EvtSource N(init_8021D7C4);
extern EvtSource N(takeTurn_8021E900);
extern EvtSource N(idle_8021D810);
extern EvtSource N(handleEvent_8021DF88);

BSS s32 D_80220160[];

s32 N(idleAnimations_8021D510)[] = {
    STATUS_NORMAL,    NPC_ANIM_battle_bandit_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_battle_bandit_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_battle_bandit_Palette_00_Anim_10,
    STATUS_POISON,    NPC_ANIM_battle_bandit_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_battle_bandit_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_battle_bandit_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_battle_bandit_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_battle_bandit_Palette_00_Anim_11,
    STATUS_FEAR,      NPC_ANIM_battle_bandit_Palette_00_Anim_11,
    STATUS_END,
};

s32 N(idleAnimations_8021D55C)[] = {
    STATUS_NORMAL,    NPC_ANIM_battle_bandit_Palette_00_Anim_2,
    STATUS_STONE,     NPC_ANIM_battle_bandit_Palette_00_Anim_4,
    STATUS_SLEEP,     NPC_ANIM_battle_bandit_Palette_00_Anim_10,
    STATUS_POISON,    NPC_ANIM_battle_bandit_Palette_00_Anim_2,
    STATUS_STOP,      NPC_ANIM_battle_bandit_Palette_00_Anim_4,
    STATUS_STATIC,    NPC_ANIM_battle_bandit_Palette_00_Anim_2,
    STATUS_PARALYZE,  NPC_ANIM_battle_bandit_Palette_00_Anim_4,
    STATUS_DIZZY,     NPC_ANIM_battle_bandit_Palette_00_Anim_11,
    STATUS_FEAR,      NPC_ANIM_battle_bandit_Palette_00_Anim_11,
    STATUS_END,
};

s32 N(idleAnimations_8021D5A8)[] = {
    STATUS_NORMAL,    NPC_ANIM_battle_bandit_Palette_00_Anim_14,
    STATUS_END,
};

s32 N(defenseTable_8021D5B4)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8021D5C0)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 70,
    STATUS_POISON, 20,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 50,
    STATUS_STATIC, 30,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 90,
    STATUS_STOP, 100,
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

ActorPartDesc N(partsTable_8021D66C)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 28 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021D510),
        .defenseTable = N(defenseTable_8021D5B4),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 244,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 2,
        .posOffset = { 0, 30, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021D5A8),
        .defenseTable = N(defenseTable_8021D5B4),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
};

ActorPartDesc N(partsTable_8021D6B4)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021D5A8),
        .defenseTable = N(defenseTable_8021D5B4),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
};

ActorDesc NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_BANDIT,
    .level = 9,
    .maxHP = 5,
    .partCount = ARRAY_COUNT(N(partsTable_8021D66C)),
    .partsData = N(partsTable_8021D66C),
    .script = N(init_8021D750),
    .statusTable = N(statusTable_8021D5C0),
    .escapeChance = 40,
    .airLiftChance = 90,
    .spookChance = 90,
    .baseStatusChance = 90,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 1,
    .size = { 26, 32 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 25 },
    .statusMessageOffset = { 10, 25 },
};

ActorDesc N(2) = {
    .flags = ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY,
    .type = ACTOR_TYPE_BANDIT,
    .level = 9,
    .maxHP = 5,
    .partCount = ARRAY_COUNT(N(partsTable_8021D6B4)),
    .partsData = N(partsTable_8021D6B4),
    .script = N(init_8021D7C4),
    .statusTable = N(statusTable_8021D5C0),
    .escapeChance = 40,
    .airLiftChance = 90,
    .spookChance = 90,
    .baseStatusChance = 90,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 1,
    .size = { 26, 32 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 25 },
    .statusMessageOffset = { 10, 25 },
};

Vec3i N(vector3D_8021D728) = { 0, 0xFFFFFC18, 0 };

Formation N(specialFormation_8021D734) = {
    { .actor = &N(2), .home = { .vec = &N(vector3D_8021D728) }},
};

EvtSource N(init_8021D750) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021E900)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021D810)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021DF88)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(handleEvent_8021D7B4) = {
    EVT_RETURN
    EVT_END
};

EvtSource N(init_8021D7C4) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021D7B4)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021D7B4)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021D7B4)))
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_8021D810) = {
    EVT_RETURN
    EVT_END
};

EvtSource N(8021D820) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021D510)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_100000, 0)
            EVT_CALL(SummonEnemy, EVT_ADDR(N(specialFormation_8021D734)), 0)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(GetPartOffset, ACTOR_SELF, 2, LW(1), LW(2), LW(3))
            EVT_CALL(SetActorPos, LW(10), LW(1), LW(2), LW(3))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_CALL(SetActorVar, LW(10), 1, LW(0))
            EVT_CALL(SetActorJumpGravity, LW(10), EVT_FLOAT(1.0))
            EVT_CALL(RandInt, 360, LW(0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(1), LW(2), LW(3))
            EVT_ADD(LW(2), 30)
            EVT_CALL(SetActorPos, LW(10), LW(1), LW(2), LW(3))
            EVT_CALL(SetActorSounds, LW(10), 2, 0, 0)
            EVT_CALL(AddVectorPolar, LW(1), LW(3), EVT_FLOAT(40.0), LW(0))
            EVT_CALL(SetGoalPos, LW(10), LW(1), 0, LW(3))
            EVT_CALL(JumpToGoal, LW(10), 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, LW(10), 0x212)
            EVT_CALL(AddVectorPolar, LW(1), LW(3), EVT_FLOAT(20.0), LW(0))
            EVT_CALL(SetGoalPos, LW(10), LW(1), 0, LW(3))
            EVT_CALL(JumpToGoal, LW(10), 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, LW(10), 0x212)
            EVT_CALL(AddVectorPolar, LW(1), LW(3), EVT_FLOAT(10.0), LW(0))
            EVT_CALL(SetGoalPos, LW(10), LW(1), 0, LW(3))
            EVT_CALL(JumpToGoal, LW(10), 5, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, LW(10), 0x212)
            EVT_LOOP(0)
                EVT_CALL(GetBattleFlags, LW(1))
                EVT_IF_FLAG(LW(1), BS_FLAGS1_80000)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_IF_NOT_FLAG(LW(1), BS_FLAGS1_100)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_WAIT_FRAMES(15)
            EVT_CALL(SetActorJumpGravity, LW(10), EVT_FLOAT(1.0))
            EVT_CALL(SetActorSpeed, LW(10), EVT_FLOAT(6.0))
            EVT_SET(LW(0), -70)
            EVT_SET(LW(1), 0)
            EVT_SET(LW(2), 10)
            EVT_LABEL(5)
            EVT_CALL(GetActorPos, LW(10), LW(3), LW(4), LW(5))
            EVT_IF_EQ(LW(3), LW(0))
                EVT_GOTO(10)
            EVT_END_IF
            EVT_IF_LT(LW(3), LW(0))
                EVT_SET(LW(4), LW(0))
                EVT_SUB(LW(4), LW(3))
                EVT_IF_LT(LW(4), 30)
                    EVT_CALL(SetGoalPos, LW(10), LW(0), LW(1), LW(2))
                    EVT_CALL(JumpToGoal, LW(10), 5, FALSE, TRUE, FALSE)
                    EVT_CALL(PlaySoundAtActor, LW(10), 0x212)
                EVT_ELSE
                    EVT_SET(LW(4), LW(3))
                    EVT_ADD(LW(3), 30)
                    EVT_CALL(SetGoalPos, LW(10), LW(3), LW(1), LW(2))
                    EVT_CALL(JumpToGoal, LW(10), 0, FALSE, TRUE, FALSE)
                    EVT_CALL(PlaySoundAtActor, LW(10), 0x212)
                EVT_END_IF
            EVT_ELSE
                EVT_SET(LW(4), LW(3))
                EVT_SUB(LW(4), LW(0))
                EVT_IF_LT(LW(4), 30)
                    EVT_CALL(SetGoalPos, LW(10), LW(0), LW(1), LW(2))
                    EVT_CALL(JumpToGoal, LW(10), 5, FALSE, TRUE, FALSE)
                    EVT_CALL(PlaySoundAtActor, LW(10), 0x212)
                EVT_ELSE
                    EVT_SUB(LW(3), 30)
                    EVT_CALL(SetGoalPos, LW(10), LW(3), LW(1), LW(2))
                    EVT_CALL(JumpToGoal, LW(10), 0, FALSE, TRUE, FALSE)
                    EVT_CALL(PlaySoundAtActor, LW(10), 0x212)
                EVT_END_IF
            EVT_END_IF
            EVT_GOTO(5)
            EVT_LABEL(10)
            EVT_CALL(EnableActorBlur, LW(10), 1)
            EVT_CALL(SetTargetActor, LW(10), ACTOR_PLAYER)
            EVT_CALL(SetGoalToTarget, LW(10))
            EVT_CALL(JumpToGoal, LW(10), 15, FALSE, FALSE, FALSE)
            EVT_CALL(GetGoalPos, LW(10), LW(0), LW(1), LW(2))
            EVT_CALL(PlayEffect, EFFECT_ID_49, 0, LW(0), LW(1), LW(2), EVT_FLOAT(1.0), 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(PlaySoundAtActor, LW(10), 0x211)
            EVT_CALL(GetActorVar, LW(10), 1, LW(0))
            EVT_CALL(AddCoin, LW(0))
            EVT_CALL(RemoveActor, LW(10))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(handleEvent_8021DF88) = {
    EVT_USE_ARRAY(D_80220160)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_EXEC_GET_TID(N(8021D820), UW(0))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(UW(0), LW(0))
                EVT_IF_EQ(LW(0), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
        EVT_CASE_OR_EQ(EVENT_HIT)
        EVT_CASE_OR_EQ(EVENT_SPIN_SMASH_LAUNCH_HIT)
            EVT_EXEC_GET_TID(N(8021D820), UW(0))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(UW(0), LW(0))
                EVT_IF_EQ(LW(0), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_EXEC_GET_TID(N(8021D820), UW(0))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_A)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_bandit_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(UW(0), LW(0))
                EVT_IF_EQ(LW(0), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_EXEC_GET_TID(N(8021D820), UW(0))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_A)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_bandit_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(UW(0), LW(0))
                EVT_IF_EQ(LW(0), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_GET_TID(N(8021D820), UW(0))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(UW(0), LW(0))
                EVT_IF_EQ(LW(0), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_GET_TID(N(8021D820), UW(0))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoDeath)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(UW(0), LW(0))
                EVT_IF_EQ(LW(0), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_7)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6005859375))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(0)
                    EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_1)
                EVT_CASE_EQ(1)
                    EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_2)
            EVT_END_SWITCH
            EVT_SET_CONST(LW(0), 1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_DEATH)
        EVT_CASE_OR_EQ(EVENT_SPIN_SMASH_LAUNCH_DEATH)
            EVT_EXEC_GET_TID(N(8021D820), UW(0))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoDeath)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(UW(0), LW(0))
                EVT_IF_EQ(LW(0), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_EXEC_GET_TID(N(8021D820), UW(0))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_7)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_bandit_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(UW(0), LW(0))
                EVT_IF_EQ(LW(0), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_EXEC_GET_TID(N(8021D820), UW(0))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoAirLift)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(UW(0), LW(0))
                EVT_IF_EQ(LW(0), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_bandit_Palette_00_Anim_9)
            EVT_SET_CONST(LW(2), NPC_ANIM_world_parakarry_Palette_00_Anim_0)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bandit_Palette_00_Anim_1)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(takeTurn_8021E900) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bandit_Palette_00_Anim_8)
        EVT_WAIT_FRAMES(30)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
        EVT_CALL(SetGoalPos, ACTOR_SELF, 300, 0, 0)
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetBattleFlagBits, BS_FLAGS1_40000, 1)
        EVT_CALL(func_8027D32C, ACTOR_SELF)
        EVT_CALL(RemoveActor, ACTOR_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), 50)
        EVT_SET(LW(1), 0)
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bandit_Palette_00_Anim_7)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bandit_Palette_00_Anim_1)
        EVT_WAIT_FRAMES(6)
    EVT_END_IF
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bandit_Palette_00_Anim_5)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 35, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20C2)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bandit_Palette_00_Anim_D)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_SUB(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT_FRAMES(5)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(5)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bandit_Palette_00_Anim_7)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bandit_Palette_00_Anim_1)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bandit_Palette_00_Anim_D)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LW(0))
            EVT_IF_LE(LW(0), 0)
                EVT_SET(LW(0), 1)
                EVT_GOTO(10)
            EVT_END_IF
            EVT_CALL(GetBattleFlags, LW(0))
            EVT_IF_FLAG(LW(0), BS_FLAGS1_ATK_BLOCKED)
                EVT_SET(LW(0), 1)
                EVT_GOTO(10)
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_FLAG(LW(0), STATUS_FLAG_SHRINK)
                EVT_SET(LW(0), 0)
                EVT_GOTO(10)
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LW(0))
            EVT_IF_FLAG(LW(0), STATUS_FLAG_STONE)
                EVT_SET(LW(0), 0)
                EVT_GOTO(10)
            EVT_END_IF
            EVT_CALL(AddCoin, 0)
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(0)
                    EVT_SET(LW(0), 1)
                EVT_CASE_LT(10)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 1, LW(0))
                    EVT_SET(LW(0), 2)
                EVT_CASE_GE(10)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 10)
                    EVT_SET(LW(0), 2)
            EVT_END_SWITCH
            EVT_LABEL(10)
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(0)
                    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_ADD(LW(0), 30)
                    EVT_SET(LW(1), 0)
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.80078125))
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bandit_Palette_00_Anim_1)
                    EVT_WAIT_FRAMES(20)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bandit_Palette_00_Anim_7)
                EVT_CASE_EQ(1)
                    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_ADD(LW(0), 30)
                    EVT_SET(LW(1), 0)
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.80078125))
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bandit_Palette_00_Anim_E)
                    EVT_WAIT_FRAMES(20)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20C3)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bandit_Palette_00_Anim_10)
                    EVT_WAIT_FRAMES(20)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bandit_Palette_00_Anim_7)
                EVT_CASE_DEFAULT
                    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(10), LW(11), LW(12))
                    EVT_ADD(LW(10), 30)
                    EVT_SET(LW(11), 0)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
                    EVT_MUL(LW(0), -1)
                    EVT_CALL(AddCoin, LW(0))
                    EVT_THREAD
                        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_100000, 1)
                        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, 0)
                        EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
                        EVT_CALL(SetPartPos, ACTOR_SELF, 2, LW(0), LW(1), LW(2))
                        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(1.0))
                        EVT_ADD(LW(11), 30)
                        EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LW(10), LW(11), LW(12), 22, 1)
                        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_100000, 0)
                    EVT_END_THREAD
                    EVT_THREAD
                        EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
                        EVT_LOOP(LW(0))
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x212)
                            EVT_WAIT_FRAMES(1)
                        EVT_END_LOOP
                    EVT_END_THREAD
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.80078125))
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(10), LW(11), LW(12))
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021D55C)))
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bandit_Palette_00_Anim_E)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
                    EVT_WAIT_FRAMES(7)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bandit_Palette_00_Anim_F)
                    EVT_WAIT_FRAMES(20)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_bandit_Palette_00_Anim_8)
            EVT_END_SWITCH
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
