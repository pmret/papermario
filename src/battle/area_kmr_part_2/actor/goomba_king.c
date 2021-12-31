#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/goomba_bros.h"

#define NAMESPACE b_area_kmr_part_2_goomba_king

s32 N(idleAnimations_80220800)[] = {
    STATUS_NORMAL,    NPC_ANIM_goomba_king_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_goomba_king_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_goomba_king_Palette_00_Anim_8,
    STATUS_POISON,    NPC_ANIM_goomba_king_Palette_00_Anim_0,
    STATUS_STOP,      NPC_ANIM_goomba_king_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_goomba_king_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_goomba_king_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_goomba_king_Palette_00_Anim_7,
    STATUS_END,
};

s32 N(idleAnimations_80220844)[] = {
    STATUS_NORMAL,    NPC_ANIM_goomba_king_Palette_00_Anim_4,
    STATUS_STONE,     NPC_ANIM_goomba_king_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_goomba_king_Palette_00_Anim_8,
    STATUS_POISON,    NPC_ANIM_goomba_king_Palette_00_Anim_0,
    STATUS_STOP,      NPC_ANIM_goomba_king_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_goomba_king_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_goomba_king_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_goomba_king_Palette_00_Anim_7,
    STATUS_END,
};

s32 N(idleAnimations_80220888)[] = {
    STATUS_NORMAL,   NPC_ANIM_goomba_king_Palette_00_Anim_7,
    STATUS_STONE,    NPC_ANIM_goomba_king_Palette_00_Anim_0,
    STATUS_SLEEP,    NPC_ANIM_goomba_king_Palette_00_Anim_8,
    STATUS_POISON,   NPC_ANIM_goomba_king_Palette_00_Anim_0,
    STATUS_STOP,     NPC_ANIM_goomba_king_Palette_00_Anim_0,
    STATUS_STATIC,   NPC_ANIM_goomba_king_Palette_00_Anim_0,
    STATUS_PARALYZE, NPC_ANIM_goomba_king_Palette_00_Anim_0,
    STATUS_DIZZY,    NPC_ANIM_goomba_king_Palette_00_Anim_7,
    STATUS_END,
};

s32 N(idleAnimations_802208CC)[] = {
    STATUS_NORMAL,   NPC_ANIM_goomba_king_Palette_00_Anim_9,
    STATUS_STONE,    NPC_ANIM_goomba_king_Palette_00_Anim_0,
    STATUS_SLEEP,    NPC_ANIM_goomba_king_Palette_00_Anim_8,
    STATUS_POISON,   NPC_ANIM_goomba_king_Palette_00_Anim_0,
    STATUS_STOP,     NPC_ANIM_goomba_king_Palette_00_Anim_0,
    STATUS_STATIC,   NPC_ANIM_goomba_king_Palette_00_Anim_0,
    STATUS_PARALYZE, NPC_ANIM_goomba_king_Palette_00_Anim_0,
    STATUS_DIZZY,    NPC_ANIM_goomba_king_Palette_00_Anim_7,
    STATUS_END,
};

s32 N(defenseTable_80220910)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8022091C)[] = {
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
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, -1,
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, -1,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartDesc N(partsTable_802209C8)[] = {
    {
        .flags = ACTOR_PART_FLAG_20 | ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -25, 15 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80220800),
        .defenseTable = N(defenseTable_80220910),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_20 | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 80 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_80220910),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
};

ActorDesc NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GOOMBA_KING,
    .level = 49,
    .maxHP = 10,
    .partCount = ARRAY_COUNT(N(partsTable_802209C8)),
    .partsData = N(partsTable_802209C8),
    .script = N(init_80220A38),
    .statusTable = (DictionaryEntry*) N(statusTable_8022091C),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 56, 80 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -6, 38 },
    .statusMessageOffset = { 12, 75 },
};

EvtSource N(init_80220A38) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_80221530)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80220B50)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80220F34)))
    EVT_CALL(BindNextTurn, -127, EVT_ADDR(N(nextTurn_802229C4)))
    EVT_EXEC_GET_TID(N(80222D9C), LW(0))
    EVT_CALL(SetActorVar, -127, 4, LW(0))
    EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_CALL(SetActorVar, -127, 1, 0)
    EVT_CALL(SetActorVar, -127, 2, 0)
    EVT_CALL(SetActorVar, -127, 3, 0)
    EVT_CALL(SetActorVar, -127, 5, 0)
    EVT_CALL(SetActorVar, -127, 6, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_80220B50) = {
    EVT_LABEL(0)
    EVT_CALL(RandInt, 80, LW(0))
    EVT_ADD(LW(0), 80)
    EVT_WAIT_FRAMES(LW(0))
    EVT_LABEL(1)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), 0x35D000)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80220844)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleRunToGoal, -127, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80220800)))
    EVT_WAIT_FRAMES(20)
    EVT_LABEL(2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), 0x35D000)
        EVT_WAIT_FRAMES(1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80220844)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleRunToGoal, -127, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80220800)))
    EVT_WAIT_FRAMES(80)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtSource N(80220DB0) = {
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SET(LW(1), 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.400390625))
    EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20B4)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 15, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20B4)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 5, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20B4)
    EVT_RETURN
    EVT_END
};

EvtSource N(handleEvent_80220F34) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(9)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_king_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_king_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_king_Palette_00_Anim_D)
            EVT_SET_CONST(LW(2), NPC_ANIM_goomba_king_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_king_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_king_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_king_Palette_00_Anim_6)
            EVT_EXEC_WAIT(N(80220DB0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_king_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoReturnHome)
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_king_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_CALL(GetActorVar, -127, 4, LW(0))
            EVT_KILL_THREAD(LW(0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_king_Palette_00_Anim_6)
            EVT_EXEC_WAIT(N(80222F50))
            EVT_RETURN
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_king_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_king_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(GetActorVar, -127, 4, LW(0))
            EVT_KILL_THREAD(LW(0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_king_Palette_00_Anim_6)
            EVT_EXEC_WAIT(N(80222F50))
            EVT_RETURN
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_king_Palette_00_Anim_D)
            EVT_SET_CONST(LW(2), NPC_ANIM_goomba_king_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(GetActorVar, -127, 4, LW(0))
            EVT_KILL_THREAD(LW(0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_king_Palette_00_Anim_E)
            EVT_EXEC_WAIT(N(80222F50))
            EVT_RETURN
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_king_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_CALL(GetActorVar, -127, 4, LW(0))
            EVT_KILL_THREAD(LW(0))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_king_Palette_00_Anim_6)
            EVT_EXEC_WAIT(N(80222F50))
            EVT_RETURN
        EVT_CASE_EQ(42)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_king_Palette_00_Anim_6)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_king_Palette_00_Anim_4)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_king_Palette_00_Anim_1)
        EVT_CASE_EQ(53)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_king_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_goomba_king_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(takeTurn_80221530) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), 0x80000)
        EVT_CALL(GetActorVar, 515, 6, LW(0))
        EVT_IF_NE(LW(0), 0)
            EVT_CALL(RandInt, 100, LW(1))
            EVT_IF_LT(LW(1), 60)
                EVT_SUB(LW(0), 1)
                EVT_CALL(SetActorVar, 515, 6, LW(0))
                EVT_EXEC_WAIT(N(80221CD4))
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(80221680))
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtSource N(80221680) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), 0x80000)
        EVT_CALL(UseBattleCamPreset, 63)
        EVT_CALL(AddBattleCamZoom, -100)
        EVT_CALL(SetBattleCamOffsetZ, 20)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 30)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, 63)
        EVT_CALL(AddBattleCamZoom, -100)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_END_IF
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), 0x80000)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 32, 0, 0)
    EVT_ELSE
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 12, 0, 0)
    EVT_END_IF
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_king_Palette_00_Anim_4)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_king_Palette_00_Anim_1)
    EVT_WAIT_FRAMES(8)
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20ED)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20ED)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_king_Palette_00_Anim_5)
    EVT_SET(LW(0), 0)
    EVT_LOOP(20)
        EVT_ADD(LW(0), 18)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LW(0))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), ((0)), 0, 2, 16)
    EVT_SWITCH(LW(10))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0x80000000, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_king_Palette_00_Anim_7)
            EVT_SET(LW(0), 0)
            EVT_LOOP(20)
                EVT_ADD(LW(0), 18)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LW(0))
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_king_Palette_00_Anim_1)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_king_Palette_00_Anim_4)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_king_Palette_00_Anim_1)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(10), ((0)), 0, 0, 1, 32)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_king_Palette_00_Anim_1)
    EVT_SWITCH(LW(10))
        EVT_CASE_DEFAULT
            EVT_WAIT_FRAMES(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_king_Palette_00_Anim_1)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_king_Palette_00_Anim_4)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_king_Palette_00_Anim_1)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(80221CD4) = {
    EVT_CALL(UseBattleCamPreset, 15)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(func_8024ECF8, 0, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_king_Palette_00_Anim_9)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.80078125))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20B4)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_king_Palette_00_Anim_0)
    EVT_THREAD
        EVT_CALL(StartRumble, 11)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), 0x80000)
            EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(4.0))
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_goomba_king_Palette_00_Anim_1)
        EVT_CALL(PlayEffect, 0x14, 0, -80, 125, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(PlayEffect, 0x14, 0, -15, 135, 0, 85, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(PlayEffect, 0x14, 0, 100, 103, 0, 70, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), ((0)), 0, 2, 16)
    EVT_SWITCH(LW(10))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_THREAD
                EVT_WAIT_FRAMES(12)
                EVT_CALL(PlaySoundAtPart, 515, 3, 769)
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT_FRAMES(10)
                EVT_CALL(SetPartJumpGravity, 515, 3, EVT_FLOAT(1.5))
                EVT_CALL(GetPartOffset, 515, 3, LW(0), LW(1), LW(2))
                EVT_CALL(FallPartTo, 515, 3, LW(0), 10, LW(2), 14)
                EVT_SUB(LW(0), 12)
                EVT_CALL(JumpPartTo, 515, 3, LW(0), 10, LW(2), 10, 1)
                EVT_SUB(LW(0), 7)
                EVT_CALL(JumpPartTo, 515, 3, LW(0), 10, LW(2), 7, 1)
                EVT_LOOP(20)
                    EVT_CALL(SetPartFlagBits, 515, 3, 1, 0)
                    EVT_WAIT_FRAMES(1)
                    EVT_CALL(SetPartFlagBits, 515, 3, 1, 1)
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT_FRAMES(5)
                EVT_CALL(PlaySoundAtPart, 515, 4, 769)
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT_FRAMES(3)
                EVT_CALL(SetPartJumpGravity, 515, 4, EVT_FLOAT(1.5))
                EVT_CALL(GetPartOffset, 515, 4, LW(0), LW(1), LW(2))
                EVT_CALL(FallPartTo, 515, 4, LW(0), 10, LW(2), 15)
                EVT_SUB(LW(0), 12)
                EVT_CALL(JumpPartTo, 515, 4, LW(0), 10, LW(2), 10, 1)
                EVT_SUB(LW(0), 7)
                EVT_CALL(JumpPartTo, 515, 4, LW(0), 10, LW(2), 7, 1)
                EVT_LOOP(20)
                    EVT_CALL(SetPartFlagBits, 515, 4, 1, 0)
                    EVT_WAIT_FRAMES(1)
                    EVT_CALL(SetPartFlagBits, 515, 4, 1, 1)
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT_FRAMES(17)
                EVT_CALL(PlaySoundAtPart, 515, 5, 769)
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT_FRAMES(15)
                EVT_CALL(SetPartJumpGravity, 515, 5, EVT_FLOAT(1.5))
                EVT_CALL(GetPartOffset, 515, 5, LW(0), LW(1), LW(2))
                EVT_CALL(FallPartTo, 515, 5, LW(0), 10, LW(2), 17)
                EVT_ADD(LW(0), 12)
                EVT_CALL(JumpPartTo, 515, 5, LW(0), 10, LW(2), 10, 1)
                EVT_ADD(LW(0), 7)
                EVT_CALL(JumpPartTo, 515, 5, LW(0), 10, LW(2), 7, 1)
                EVT_LOOP(20)
                    EVT_CALL(SetPartFlagBits, 515, 5, 1, 0)
                    EVT_WAIT_FRAMES(1)
                    EVT_CALL(SetPartFlagBits, 515, 5, 1, 1)
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_WAIT_FRAMES(15)
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0x80000000, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_WAIT_FRAMES(12)
        EVT_CALL(PlaySoundAtPart, 515, 3, 769)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(10)
        EVT_CALL(SetPartJumpGravity, 515, 3, EVT_FLOAT(1.5))
        EVT_CALL(GetPartOffset, 515, 3, LW(0), LW(1), LW(2))
        EVT_CALL(FallPartTo, 515, 3, LW(0), 35, LW(2), 14)
        EVT_SUB(LW(0), 12)
        EVT_CALL(JumpPartTo, 515, 3, LW(0), 10, LW(2), 10, 1)
        EVT_SUB(LW(0), 7)
        EVT_CALL(JumpPartTo, 515, 3, LW(0), 10, LW(2), 7, 1)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, 515, 3, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartFlagBits, 515, 3, 1, 1)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(PlaySoundAtPart, 515, 4, 769)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(3)
        EVT_CALL(SetPartJumpGravity, 515, 4, EVT_FLOAT(1.5))
        EVT_CALL(GetPartOffset, 515, 4, LW(0), LW(1), LW(2))
        EVT_CALL(FallPartTo, 515, 4, LW(0), 10, LW(2), 15)
        EVT_SUB(LW(0), 12)
        EVT_CALL(JumpPartTo, 515, 4, LW(0), 10, LW(2), 10, 1)
        EVT_SUB(LW(0), 7)
        EVT_CALL(JumpPartTo, 515, 4, LW(0), 10, LW(2), 7, 1)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, 515, 4, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartFlagBits, 515, 4, 1, 1)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(17)
        EVT_CALL(PlaySoundAtPart, 515, 5, 769)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(15)
        EVT_CALL(SetPartJumpGravity, 515, 5, EVT_FLOAT(1.5))
        EVT_CALL(GetPartOffset, 515, 5, LW(0), LW(1), LW(2))
        EVT_CALL(FallPartTo, 515, 5, LW(0), 10, LW(2), 17)
        EVT_ADD(LW(0), 12)
        EVT_CALL(JumpPartTo, 515, 5, LW(0), 10, LW(2), 10, 1)
        EVT_ADD(LW(0), 7)
        EVT_CALL(JumpPartTo, 515, 5, LW(0), 10, LW(2), 7, 1)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, 515, 5, 1, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartFlagBits, 515, 5, 1, 1)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(24)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), ((0)), 65535, 0, 2, 32)
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(10)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(nextTurn_802229C4) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, -127, 3, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_CALL(func_802535B4, 0)
                EVT_CALL(UseBattleCamPreset, 13)
                EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY1)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT_FRAMES(20)
                EVT_CALL(UseIdleAnimation, ACTOR_ENEMY1, FALSE)
                EVT_CALL(EnableIdleScript, ACTOR_ENEMY1, 0)
                EVT_CALL(ActorSpeak, 721099, 513, 1, 6422538, 6422538)
                EVT_CALL(EnableIdleScript, ACTOR_ENEMY1, 1)
                EVT_CALL(UseIdleAnimation, ACTOR_ENEMY1, TRUE)
                EVT_CALL(UseBattleCamPreset, 13)
                EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY2)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_WAIT_FRAMES(10)
                EVT_CALL(UseIdleAnimation, ACTOR_ENEMY2, FALSE)
                EVT_CALL(EnableIdleScript, ACTOR_ENEMY2, 0)
                EVT_CALL(ActorSpeak, 721100, 514, 1, 6422794, 6422794)
                EVT_CALL(EnableIdleScript, ACTOR_ENEMY2, 1)
                EVT_CALL(UseIdleAnimation, ACTOR_ENEMY2, TRUE)
                EVT_CALL(UseBattleCamPreset, 14)
                EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY0)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT_FRAMES(20)
                EVT_CALL(ActorSpeak, 721101, 512, 1, 6488073, 6488073)
                EVT_CALL(SetActorVar, -127, 3, 1)
                EVT_CALL(UseBattleCamPreset, 14)
                EVT_CALL(BattleCamTargetActor, ACTOR_PLAYER)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_WAIT_FRAMES(10)
                EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, 180)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_QUESTION)
                EVT_CALL(ActorSpeak, 721102, 256, 0, -1, -1)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_NOD_YES)
                EVT_WAIT_FRAMES(15)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
                EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_CALL(UseBattleCamPreset, 2)
                EVT_WAIT_FRAMES(20)
                EVT_CALL(func_802535B4, 1)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(80222D9C) = {
    EVT_LABEL(0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(GetAnimation, -127, 1, LW(0))
    EVT_IF_NE(LW(0), 6488068)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetAnimation, -127, 1, LW(0))
    EVT_IF_NE(LW(0), 6488068)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(StartRumble, 1)
    EVT_CALL(func_8026DF88, -127, 1, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(GetActorVar, -127, 2, LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_NOT_FLAG(LW(0), 0x80000)
                EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.2001953125))
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_NOT_FLAG(LW(0), 0x80000)
                EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.7001953125))
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtSource N(80222F50) = {
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
    EVT_CALL(SetPartFlagBits, -127, 1, 1, 1)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, 4, 1)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(ActorExists, 513, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(GetActorHP, 513, LW(0))
    EVT_END_IF
    EVT_IF_NE(LW(0), 0)
        EVT_CALL(UseIdleAnimation, ACTOR_ENEMY1, FALSE)
        EVT_CALL(EnableIdleScript, ACTOR_ENEMY1, 0)
        EVT_CALL(ActorSpeak, 721103, 513, 1, 6422539, 6422539)
        EVT_CALL(EnableIdleScript, ACTOR_ENEMY1, 1)
        EVT_CALL(UseIdleAnimation, ACTOR_ENEMY1, TRUE)
    EVT_END_IF
    EVT_CALL(ActorExists, 514, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(GetActorHP, 514, LW(0))
    EVT_END_IF
    EVT_IF_NE(LW(0), 0)
        EVT_CALL(UseIdleAnimation, ACTOR_ENEMY2, FALSE)
        EVT_CALL(EnableIdleScript, ACTOR_ENEMY2, 0)
        EVT_CALL(ActorSpeak, 721104, 514, 1, 6422795, 6422795)
        EVT_CALL(EnableIdleScript, ACTOR_ENEMY2, 1)
        EVT_CALL(UseIdleAnimation, ACTOR_ENEMY2, TRUE)
    EVT_END_IF
    EVT_CALL(RemoveActor, -127)
    EVT_RETURN
    EVT_END
};
