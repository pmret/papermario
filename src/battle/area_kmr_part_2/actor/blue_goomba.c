#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/goomba_bros.h"

#define NAMESPACE b_area_kmr_part_2_blue_goomba

s32 N(defenseTable_802198B0)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_802198BC)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 100,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
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

extern s32 N(idleAnimations_802199B4)[];
extern EvtSource N(init_8021B268);
extern EvtSource N(doDeath_8021B388);
extern EvtSource N(takeTurn_8021A5A0);
extern EvtSource N(idle_80219A98);
extern EvtSource N(handleEvent_80219D74);
extern EvtSource N(takeTurn_8021B2C8);

ActorPartDesc N(partsTable_80219968)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802199B4),
        .defenseTable = N(defenseTable_802198B0),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 253,
    },
};

ActorDesc NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_BLUE_GOOMBA_BOSS,
    .level = 20,
    .maxHP = 6,
    .partCount = ARRAY_COUNT(N(partsTable_80219968)),
    .partsData = N(partsTable_80219968),
    .script = N(init_8021B268),
    .statusTable = N(statusTable_802198BC),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 32, 32 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 8, 25 },
};

s32 N(idleAnimations_802199B4)[] = {
    STATUS_NORMAL,    NPC_ANIM_goomba_bros_Palette_01_Anim_2,
    STATUS_STONE,     NPC_ANIM_goomba_bros_Palette_01_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_goomba_bros_Palette_01_Anim_D,
    STATUS_POISON,    NPC_ANIM_goomba_bros_Palette_01_Anim_2,
    STATUS_STOP,      NPC_ANIM_goomba_bros_Palette_01_Anim_0,
    STATUS_STATIC,    NPC_ANIM_goomba_bros_Palette_01_Anim_2,
    STATUS_PARALYZE,  NPC_ANIM_goomba_bros_Palette_01_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_goomba_bros_Palette_01_Anim_C,
    STATUS_FEAR,      NPC_ANIM_goomba_bros_Palette_01_Anim_C,
    STATUS_END,
};

s32 N(idleAnimations_80219A00)[] = {
    STATUS_NORMAL,    NPC_ANIM_goomba_bros_Palette_01_Anim_6,
    STATUS_STONE,     NPC_ANIM_goomba_bros_Palette_01_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_goomba_bros_Palette_01_Anim_D,
    STATUS_POISON,    NPC_ANIM_goomba_bros_Palette_01_Anim_2,
    STATUS_STOP,      NPC_ANIM_goomba_bros_Palette_01_Anim_0,
    STATUS_STATIC,    NPC_ANIM_goomba_bros_Palette_01_Anim_6,
    STATUS_PARALYZE,  NPC_ANIM_goomba_bros_Palette_01_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_goomba_bros_Palette_01_Anim_C,
    STATUS_FEAR,      NPC_ANIM_goomba_bros_Palette_01_Anim_C,
    STATUS_END,
};

EvtSource N(init_80219A4C) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021A5A0)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80219A98)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80219D74)))
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_80219A98) = {
    EVT_LABEL(10)
    EVT_CALL(RandInt, 80, LW(0))
    EVT_ADD(LW(0), 80)
    EVT_LOOP(LW(0))
        EVT_LABEL(0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_IF_FLAG(LW(1), 0x35D000)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80219A00)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleRunToGoal, -127, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_802199B4)))
    EVT_LOOP(20)
        EVT_LABEL(1)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_IF_FLAG(LW(1), 0x35D000)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80219A00)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleRunToGoal, -127, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_802199B4)))
    EVT_LOOP(80)
        EVT_LABEL(2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_IF_FLAG(LW(1), 0x35D000)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtSource N(handleEvent_80219D74) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_E)
            EVT_SET_CONST(LW(2), NPC_ANIM_goomba_bros_Palette_01_Anim_F)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_E)
            EVT_SET_CONST(LW(2), NPC_ANIM_goomba_bros_Palette_01_Anim_F)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_F)
            EVT_EXEC_WAIT(N(doDeath_8021B388))
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(N(doDeath_8021B388))
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_C)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6005859375))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(N(doDeath_8021B388))
            EVT_RETURN
        EVT_CASE_EQ(19)
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_2)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(N(doDeath_8021B388))
            EVT_RETURN
        EVT_CASE_EQ(53)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_6)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_2)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_6)
            EVT_SET_CONST(LW(2), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(58)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_6)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_2)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/anglestuff.inc.c"

EvtSource N(takeTurn_8021A5A0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, 63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_6)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_2)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_8)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, 16)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 10)
            EVT_SET(LW(1), 10)
            EVT_ADD(LW(2), 3)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2001953125))
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(1), LW(2), LW(0))
                EVT_SET(LW(0), 0)
                EVT_LOOP(16)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(4), LW(5), LW(6))
                    EVT_CALL(N(AngleCalculate), LW(1), LW(2), LW(4), LW(5), LW(0))
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_SET(LW(1), LW(4))
                    EVT_SET(LW(2), LW(5))
                    EVT_SET(LW(3), LW(6))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT_FRAMES(6)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_8)
            EVT_END_THREAD
            EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_D)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1005859375), EVT_FLOAT(0.80078125), EVT_FLOAT(1.0))
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.30078125), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 7, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_9)
            EVT_WAIT_FRAMES(5)
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0x80000000, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(5)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_8)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 20)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_THREAD
                EVT_WAIT_FRAMES(4)
                EVT_SET(LW(0), 180)
                EVT_LOOP(4)
                    EVT_SUB(LW(0), 45)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_8)
            EVT_END_THREAD
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_C)
            EVT_WAIT_FRAMES(5)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_WAIT_FRAMES(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6005859375))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2001953125))
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(1), LW(2), LW(0))
                EVT_SET(LW(0), 0)
                EVT_LOOP(16)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(4), LW(5), LW(6))
                    EVT_CALL(N(AngleCalculate), LW(1), LW(2), LW(4), LW(5), LW(0))
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_SET(LW(1), LW(4))
                    EVT_SET(LW(2), LW(5))
                    EVT_SET(LW(3), LW(6))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT_FRAMES(6)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_8)
            EVT_END_THREAD
            EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_8)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1005859375), EVT_FLOAT(0.80078125), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.30078125), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
    EVT_END_SWITCH
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 1, 32)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1005859375), EVT_FLOAT(0.80078125), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_2)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 40)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.80078125))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_2)
            EVT_WAIT_FRAMES(3)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_bros_Palette_01_Anim_6)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(init_8021B268) = {
    EVT_EXEC_WAIT(N(init_80219A4C))
    EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_CALL(SetActorVar, -127, 1, 0)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021B2C8)))
    EVT_RETURN
    EVT_END
};

EvtSource N(takeTurn_8021B2C8) = {
    EVT_CALL(GetActorVar, -127, 0, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_CALL(UseBattleCamPreset, 14)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 30)
        EVT_WAIT_FRAMES(30)
        EVT_CALL(SetActorVar, -127, 0, 1)
        EVT_CALL(ActorSpeak, 721087, -127, 1, -1, -1)
    EVT_END_IF
    EVT_EXEC_WAIT(N(takeTurn_8021A5A0))
    EVT_RETURN
    EVT_END
};

EvtSource N(doDeath_8021B388) = {
    EVT_CALL(func_8027D32C, -127)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_SET(LW(2), 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_WAIT_FRAMES(10)
    EVT_LOOP(24)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LW(2))
        EVT_ADD(LW(2), 30)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(2), LW(3), LW(4))
    EVT_CALL(PlayEffect, 0x1, LW(2), LW(3), LW(4), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DEATH)
    EVT_CALL(DropStarPoints, -127)
    EVT_SET(LW(3), 0)
    EVT_LOOP(12)
        EVT_CALL(SetActorRotation, ACTOR_SELF, LW(3), 0, 0)
        EVT_ADD(LW(3), 8)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, -127, 0, 1, 1)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, 4, 1)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(ActorExists, 513, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(GetActorHP, 513, LW(0))
    EVT_END_IF
    EVT_IF_NE(LW(0), 0)
        EVT_CALL(UseBattleCamPreset, 14)
        EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY1)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT_FRAMES(20)
        EVT_CALL(UseIdleAnimation, ACTOR_ENEMY1, FALSE)
        EVT_CALL(EnableIdleScript, ACTOR_ENEMY1, 0)
        EVT_CALL(SetAnimation, ACTOR_ENEMY1, 1, NPC_ANIM_goomba_bros_Palette_00_Anim_B)
        EVT_CALL(ActorSpeak, 721089, 513, 1, -1, -1)
        EVT_CALL(EnableIdleScript, ACTOR_ENEMY1, 1)
        EVT_CALL(UseIdleAnimation, ACTOR_ENEMY1, TRUE)
        EVT_CALL(UseBattleCamPreset, 2)
        EVT_CALL(MoveBattleCamOver, 30)
        EVT_WAIT_FRAMES(30)
    EVT_END_IF
    EVT_CALL(RemoveActor, -127)
    EVT_RETURN
    EVT_END
};
