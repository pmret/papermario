#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/spiked_goomba.h"

#define NAMESPACE b_area_kmr_part_1_spiked_goomba

s32 N(defenseTable_8021AFD0)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8021AFDC)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 100,
    STATUS_POISON, 80,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 80,
    STATUS_STATIC, 80,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 100,
    STATUS_STOP, 100,
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

s32 N(idleAnimations_8021B0D4)[];
EvtSource N(init_8021B16C);

ActorPartDesc N(partsTable_8021B088)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021B0D4),
        .defenseTable = N(defenseTable_8021AFD0),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP,
        .elementImmunityFlags = 0,
        .unk_1C = 244,
    },
};

ActorDesc NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_SPIKED_GOOMBA,
    .level = 6,
    .maxHP = 2,
    .partCount = ARRAY_COUNT(N(partsTable_8021B088)),
    .partsData = N(partsTable_8021B088),
    .script = N(init_8021B16C),
    .statusTable = N(statusTable_8021AFDC),
    .escapeChance = 90,
    .airLiftChance = 95,
    .spookChance = 90,
    .baseStatusChance = 100,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 24, 28 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(idleAnimations_8021B0D4)[] = {
    STATUS_NORMAL,    NPC_ANIM_spiked_goomba_default_idle,
    STATUS_STONE,     NPC_ANIM_spiked_goomba_default_still,
    STATUS_SLEEP,     NPC_ANIM_spiked_goomba_default_sleep,
    STATUS_POISON,    NPC_ANIM_spiked_goomba_default_idle,
    STATUS_STOP,      NPC_ANIM_spiked_goomba_default_still,
    STATUS_STATIC,    NPC_ANIM_spiked_goomba_default_idle,
    STATUS_PARALYZE,  NPC_ANIM_spiked_goomba_default_still,
    STATUS_DIZZY,     NPC_ANIM_spiked_goomba_default_dizzy,
    STATUS_FEAR,      NPC_ANIM_spiked_goomba_default_dizzy,
    STATUS_END,
};

s32 N(idleAnimations_8021B120)[] = {
    STATUS_NORMAL,    NPC_ANIM_spiked_goomba_default_run,
    STATUS_STONE,     NPC_ANIM_spiked_goomba_default_still,
    STATUS_SLEEP,     NPC_ANIM_spiked_goomba_default_sleep,
    STATUS_POISON,    NPC_ANIM_spiked_goomba_default_idle,
    STATUS_STOP,      NPC_ANIM_spiked_goomba_default_still,
    STATUS_STATIC,    NPC_ANIM_spiked_goomba_default_run,
    STATUS_PARALYZE,  NPC_ANIM_spiked_goomba_default_still,
    STATUS_DIZZY,     NPC_ANIM_spiked_goomba_default_dizzy,
    STATUS_FEAR,      NPC_ANIM_spiked_goomba_default_dizzy,
    STATUS_END,
};

EvtSource N(takeTurn_8021BDDC);
EvtSource N(idle_8021B1B8);
EvtSource N(handleEvent_8021B494);

EvtSource N(init_8021B16C) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8021BDDC)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8021B1B8)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021B494)))
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_8021B1B8) = {
    EVT_LABEL(10)
    EVT_CALL(RandInt, 80, EVT_VAR(0))
    EVT_ADD(EVT_VAR(0), 80)
    EVT_LOOP(EVT_VAR(0))
        EVT_LABEL(0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, EVT_VAR(1))
        EVT_IF_FLAG(EVT_VAR(1), 0x35D000)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FIXED(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_8021B120)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(IdleRunToGoal, -127, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_8021B0D4)))
    EVT_LOOP(20)
        EVT_LABEL(1)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, EVT_VAR(1))
        EVT_IF_FLAG(EVT_VAR(1), 0x35D000)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_SUB(EVT_VAR(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FIXED(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_8021B120)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(IdleRunToGoal, -127, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_8021B0D4)))
    EVT_LOOP(80)
        EVT_LABEL(2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, EVT_VAR(1))
        EVT_IF_FLAG(EVT_VAR(1), 0x35D000)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtSource N(handleEvent_8021B494) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.0), EVT_FIXED(1.0), EVT_FIXED(1.0))
    EVT_CALL(GetLastEvent, ACTOR_SELF, EVT_VAR(0))
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_spiked_goomba_default_pain)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_spiked_goomba_default_burn_dead)
            EVT_SET_CONST(EVT_VAR(2), NPC_ANIM_spiked_goomba_default_burn_pain)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_spiked_goomba_default_burn_dead)
            EVT_SET_CONST(EVT_VAR(2), NPC_ANIM_spiked_goomba_default_burn_pain)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_spiked_goomba_default_burn_pain)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_spiked_goomba_default_pain)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_spiked_goomba_default_pain)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_spiked_goomba_default_dead)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_spiked_goomba_default_electrocute)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_spiked_goomba_default_pain)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FIXED(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_dizzy)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FIXED(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_idle)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FIXED(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(38)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_spiked_goomba_default_electrocute)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_spiked_goomba_default_dead)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(19)
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_spiked_goomba_default_idle)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_spiked_goomba_default_pain)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_spiked_goomba_default_dead)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(53)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FIXED(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FIXED(4.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FIXED(1.0))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_spiked_goomba_default_idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_spiked_goomba_default_run)
            EVT_SET_CONST(EVT_VAR(2), NPC_ANIM_spiked_goomba_default_pain)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(58)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_spiked_goomba_default_run)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_SET_CONST(EVT_VAR(0), 0x00000001)
            EVT_SET_CONST(EVT_VAR(1), NPC_ANIM_spiked_goomba_default_pain)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(27)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, EVT_VAR(0))
            EVT_IF_NOT_FLAG(EVT_VAR(0), 0x35D000)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_laugh)
            EVT_END_IF
            EVT_WAIT_FRAMES(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, EVT_VAR(3))
            EVT_IF_FLAG(EVT_VAR(3), 0x80000)
                EVT_ADD(EVT_VAR(1), 10)
            EVT_ELSE
                EVT_ADD(EVT_VAR(1), 26)
            EVT_END_IF
            EVT_CALL(PlayEffect, 0x1A, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 20, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(20)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_idle)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "anglestuff.inc.c"

EvtSource N(takeTurn_8021BDDC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, 63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_run)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FIXED(6.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_idle)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_headbonk)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, EVT_VAR(0), ((0)), 0, 1, 16)
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(EVT_VAR(10), EVT_VAR(0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_SUB(EVT_VAR(0), 10)
            EVT_SET(EVT_VAR(1), 10)
            EVT_ADD(EVT_VAR(2), 3)
            EVT_CALL(SetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FIXED(1.2))
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, EVT_VAR(1), EVT_VAR(2), EVT_VAR(0))
                EVT_SET(EVT_VAR(0), 0)
                EVT_LOOP(16)
                    EVT_CALL(GetActorPos, ACTOR_SELF, EVT_VAR(4), EVT_VAR(5), EVT_VAR(6))
                    EVT_CALL(N(AngleCalculate), EVT_VAR(1), EVT_VAR(2), EVT_VAR(4), EVT_VAR(5), EVT_VAR(0))
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, EVT_VAR(0))
                    EVT_SET(EVT_VAR(1), EVT_VAR(4))
                    EVT_SET(EVT_VAR(2), EVT_VAR(5))
                    EVT_SET(EVT_VAR(3), EVT_VAR(6))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT_FRAMES(6)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_headbonk)
            EVT_END_THREAD
            EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_sleep)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.1), EVT_FIXED(0.8), EVT_FIXED(1.0))
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.3), EVT_FIXED(0.5), EVT_FIXED(1.0))
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.0), EVT_FIXED(1.0), EVT_FIXED(1.0))
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 7, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_pain)
            EVT_WAIT_FRAMES(5)
            EVT_IF_EQ(EVT_VAR(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, EVT_VAR(0), ((0x80000000)), 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(5)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_headbonk)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(0), 20)
            EVT_SET(EVT_VAR(1), 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FIXED(2.0))
            EVT_THREAD
                EVT_WAIT_FRAMES(4)
                EVT_SET(EVT_VAR(0), 180)
                EVT_LOOP(4)
                    EVT_SUB(EVT_VAR(0), 45)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, EVT_VAR(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_headbonk)
            EVT_END_THREAD
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_dizzy)
            EVT_WAIT_FRAMES(5)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FIXED(2.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FIXED(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FIXED(1.0))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_WAIT_FRAMES(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_idle)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FIXED(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FIXED(1.2))
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, EVT_VAR(1), EVT_VAR(2), EVT_VAR(0))
                EVT_SET(EVT_VAR(0), 0)
                EVT_LOOP(16)
                    EVT_CALL(GetActorPos, ACTOR_SELF, EVT_VAR(4), EVT_VAR(5), EVT_VAR(6))
                    EVT_CALL(N(AngleCalculate), EVT_VAR(1), EVT_VAR(2), EVT_VAR(4), EVT_VAR(5), EVT_VAR(0))
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, EVT_VAR(0))
                    EVT_SET(EVT_VAR(1), EVT_VAR(4))
                    EVT_SET(EVT_VAR(2), EVT_VAR(5))
                    EVT_SET(EVT_VAR(3), EVT_VAR(6))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT_FRAMES(6)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_headbonk)
            EVT_END_THREAD
            EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_headbonk)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.1), EVT_FIXED(0.8), EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.3), EVT_FIXED(0.5), EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(1)
    EVT_END_SWITCH
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, EVT_VAR(0), ((0)), 0, 0, 2, 32)
    EVT_SWITCH(EVT_VAR(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.1), EVT_FIXED(0.8), EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FIXED(1.0), EVT_FIXED(1.0), EVT_FIXED(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_idle)
            EVT_CALL(GetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_ADD(EVT_VAR(0), 40)
            EVT_SET(EVT_VAR(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FIXED(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_ADD(EVT_VAR(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(EVT_VAR(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(GetLastDamage, 0, EVT_VAR(0))
            EVT_IF_GT(EVT_VAR(0), 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_laugh)
                EVT_WAIT_FRAMES(15)
            EVT_ELSE
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_idle)
                EVT_WAIT_FRAMES(3)
            EVT_END_IF
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FIXED(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_goomba_default_run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FIXED(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FIXED(1.0))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
