#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/stone_chomp.h"

#define NAMESPACE b_area_isk_part_1_stone_chomp

extern EvtScript N(init_80221ABC);
extern EvtScript N(takeTurn_80222ED0);
extern EvtScript N(idle_80221D00);
extern EvtScript N(handleEvent_80222364);
extern EvtScript N(8022181C);
extern EvtScript N(80222324);

s32 N(idleAnimations_80221450)[] = {
    STATUS_NORMAL,    NPC_ANIM_stone_chomp_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_stone_chomp_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_stone_chomp_Palette_00_Anim_A,
    STATUS_POISON,    NPC_ANIM_stone_chomp_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_stone_chomp_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_stone_chomp_Palette_00_Anim_1,
    STATUS_DIZZY,     NPC_ANIM_stone_chomp_Palette_00_Anim_B,
    STATUS_END,
};

s32 N(idleAnimations_8022148C)[] = {
    STATUS_NORMAL,    NPC_ANIM_stone_chomp_Palette_00_Anim_3,
    STATUS_POISON,    NPC_ANIM_stone_chomp_Palette_00_Anim_3,
    STATUS_STOP,      NPC_ANIM_stone_chomp_Palette_00_Anim_0,
    STATUS_STONE,     NPC_ANIM_stone_chomp_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_stone_chomp_Palette_00_Anim_A,
    STATUS_STATIC,    NPC_ANIM_stone_chomp_Palette_00_Anim_3,
    STATUS_DIZZY,     NPC_ANIM_stone_chomp_Palette_00_Anim_B,
    STATUS_END,
};

s32 N(idleAnimations_802214C8)[] = {
    STATUS_NORMAL,    NPC_ANIM_stone_chomp_Palette_00_Anim_4,
    STATUS_POISON,    NPC_ANIM_stone_chomp_Palette_00_Anim_4,
    STATUS_STOP,      NPC_ANIM_stone_chomp_Palette_00_Anim_0,
    STATUS_STONE,     NPC_ANIM_stone_chomp_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_stone_chomp_Palette_00_Anim_A,
    STATUS_STATIC,    NPC_ANIM_stone_chomp_Palette_00_Anim_4,
    STATUS_DIZZY,     NPC_ANIM_stone_chomp_Palette_00_Anim_B,
    STATUS_END,
};

s32 N(idleAnimations_80221504)[] = {
    STATUS_NORMAL,    NPC_ANIM_stone_chomp_Palette_00_Anim_5,
    STATUS_POISON,    NPC_ANIM_stone_chomp_Palette_00_Anim_5,
    STATUS_STOP,      NPC_ANIM_stone_chomp_Palette_00_Anim_0,
    STATUS_STONE,     NPC_ANIM_stone_chomp_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_stone_chomp_Palette_00_Anim_A,
    STATUS_STATIC,    NPC_ANIM_stone_chomp_Palette_00_Anim_5,
    STATUS_DIZZY,     NPC_ANIM_stone_chomp_Palette_00_Anim_B,
    STATUS_END,
};

s32 N(idleAnimations_80221540)[] = {
    STATUS_NORMAL,    NPC_ANIM_stone_chomp_Palette_00_Anim_2,
    STATUS_END,
};

s32 N(defenseTable_8022154C)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(statusTable_80221558)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 50,
    STATUS_SHRINK, 75,
    STATUS_STOP, 75,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_80221604)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80221450),
        .defenseTable = N(defenseTable_8022154C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -13, 40 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80221450),
        .defenseTable = N(defenseTable_8022154C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 242,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80221540),
        .defenseTable = N(defenseTable_8022154C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80221540),
        .defenseTable = N(defenseTable_8022154C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80221540),
        .defenseTable = N(defenseTable_8022154C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80221540),
        .defenseTable = N(defenseTable_8022154C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 7,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80221540),
        .defenseTable = N(defenseTable_8022154C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 8,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80221540),
        .defenseTable = N(defenseTable_8022154C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 9,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80221540),
        .defenseTable = N(defenseTable_8022154C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 10,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80221540),
        .defenseTable = N(defenseTable_8022154C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_STONE_CHOMP,
    .level = 14,
    .maxHP = 4,
    .partCount = ARRAY_COUNT(N(partsTable_80221604)),
    .partsData = N(partsTable_80221604),
    .script = &N(init_80221ABC),
    .statusTable = N(statusTable_80221558),
    .escapeChance = 0,
    .airLiftChance = 25,
    .spookChance = 25,
    .baseStatusChance = 0,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 85,
    .coinReward = 5,
    .size = { 56, 40 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

#include "common/ChompChainInit.inc.c"

#include "common/ChompChainUpdateHelperFunc.inc.c"

#include "common/ChompChainUpdateHelperFunc2.inc.c"

ApiStatus b_area_isk_part_1_ChompChainUpdate(Evt* script, s32 isInitialCall);
INCLUDE_ASM(s32, "battle/area_isk_part_1/4E29B0", b_area_isk_part_1_ChompChainUpdate);

EvtScript N(80221794) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_EXEC_WAIT(N(8022181C))
    EVT_RETURN
    EVT_END
};

EvtScript N(8022181C) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
    EVT_LABEL(0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
    EVT_IF_EQ(LW(3), LW(0))
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_LT(LW(3), LW(0))
        EVT_SET(LW(4), LW(0))
        EVT_SUB(LW(4), LW(3))
        EVT_IF_LT(LW(4), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3F9)
        EVT_ELSE
            EVT_SET(LW(4), LW(3))
            EVT_ADD(LW(3), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(3), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3F9)
        EVT_END_IF
    EVT_ELSE
        EVT_SET(LW(4), LW(3))
        EVT_SUB(LW(4), LW(0))
        EVT_IF_LT(LW(4), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3F9)
        EVT_ELSE
            EVT_SUB(LW(3), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(3), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3F9)
        EVT_END_IF
    EVT_END_IF
    EVT_GOTO(0)
    EVT_LABEL(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80221ABC) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_80222ED0)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80221D00)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80222364)))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, LW(0), LW(1), LW(2))
    EVT_SET(LW(0), 3)
    EVT_LOOP(8)
        EVT_CALL(SetPartSize, ACTOR_SELF, LW(0), 16, 16)
        EVT_ADD(LW(0), 1)
    EVT_END_LOOP
    EVT_CALL(N(ChompChainInit))
    EVT_EXEC(N(80222324))
    EVT_RETURN
    EVT_END
};

EvtScript N(80221BC4) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(SetPartPos, ACTOR_SELF, 2, LW(0), LW(1), LW(2))
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, 0, 24)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 2, 0, 0)
    EVT_ELSE
        EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
        EVT_CALL(GetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(SetPartPos, ACTOR_SELF, 2, LW(0), LW(1), LW(2))
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, -13, 40)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 2, 0, -14)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80221D00) = {
    EVT_LABEL(0)
    EVT_LOOP(0)
        EVT_EXEC_WAIT(N(80221BC4))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80221504)))
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 10)
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 11, 1)
    EVT_LOOP(0)
        EVT_EXEC_WAIT(N(80221BC4))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 6, 1)
    EVT_CALL(RandInt, 10, LW(0))
    EVT_ADD(LW(0), 1)
    EVT_WAIT(LW(0))
    EVT_LOOP(0)
        EVT_EXEC_WAIT(N(80221BC4))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_802214C8)))
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 15, 1)
    EVT_LOOP(0)
        EVT_EXEC_WAIT(N(80221BC4))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80221504)))
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 20)
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 12, 1)
    EVT_LOOP(0)
        EVT_EXEC_WAIT(N(80221BC4))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 10)
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 9, 1)
    EVT_LOOP(0)
        EVT_EXEC_WAIT(N(80221BC4))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022148C)))
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 6, 1)
    EVT_CALL(RandInt, 10, LW(0))
    EVT_ADD(LW(0), 10)
    EVT_WAIT(LW(0))
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80222324) = {
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(b_area_isk_part_1_ChompChainUpdate)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80222364) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_stone_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_stone_chomp_Palette_00_Anim_9)
            EVT_CALL(SetAnimation, ACTOR_SELF, 4, NPC_ANIM_stone_chomp_Palette_00_Anim_9)
            EVT_CALL(SetAnimation, ACTOR_SELF, 5, NPC_ANIM_stone_chomp_Palette_00_Anim_9)
            EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_stone_chomp_Palette_00_Anim_9)
            EVT_CALL(SetAnimation, ACTOR_SELF, 7, NPC_ANIM_stone_chomp_Palette_00_Anim_9)
            EVT_CALL(SetAnimation, ACTOR_SELF, 8, NPC_ANIM_stone_chomp_Palette_00_Anim_9)
            EVT_CALL(SetAnimation, ACTOR_SELF, 9, NPC_ANIM_stone_chomp_Palette_00_Anim_9)
            EVT_CALL(SetAnimation, ACTOR_SELF, 10, NPC_ANIM_stone_chomp_Palette_00_Anim_9)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_stone_chomp_Palette_00_Anim_7)
            EVT_SET_CONST(LW(2), NPC_ANIM_stone_chomp_Palette_00_Anim_8)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_stone_chomp_Palette_00_Anim_9)
            EVT_CALL(SetAnimation, ACTOR_SELF, 4, NPC_ANIM_stone_chomp_Palette_00_Anim_9)
            EVT_CALL(SetAnimation, ACTOR_SELF, 5, NPC_ANIM_stone_chomp_Palette_00_Anim_9)
            EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_stone_chomp_Palette_00_Anim_9)
            EVT_CALL(SetAnimation, ACTOR_SELF, 7, NPC_ANIM_stone_chomp_Palette_00_Anim_9)
            EVT_CALL(SetAnimation, ACTOR_SELF, 8, NPC_ANIM_stone_chomp_Palette_00_Anim_9)
            EVT_CALL(SetAnimation, ACTOR_SELF, 9, NPC_ANIM_stone_chomp_Palette_00_Anim_9)
            EVT_CALL(SetAnimation, ACTOR_SELF, 10, NPC_ANIM_stone_chomp_Palette_00_Anim_9)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_stone_chomp_Palette_00_Anim_7)
            EVT_SET_CONST(LW(2), NPC_ANIM_stone_chomp_Palette_00_Anim_8)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_stone_chomp_Palette_00_Anim_8)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_stone_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_stone_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_stone_chomp_Palette_00_Anim_6)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SET(LW(1), 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
            EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3F9)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 15, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3F9)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 5, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3F9)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3F9)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_stone_chomp_Palette_00_Anim_5)
            EVT_EXEC_WAIT(N(80221794))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3F9)
            EVT_THREAD
                EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
            EVT_END_THREAD
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetPartPos, ACTOR_SELF, 2, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_stone_chomp_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_stone_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_stone_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_stone_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_stone_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_stone_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_stone_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_stone_chomp_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_stone_chomp_Palette_00_Anim_1)
            EVT_SET_CONST(LW(2), NPC_ANIM_stone_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(SetGoalToHome, ACTOR_SELF)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LW(1), LW(2), LW(3))
                EVT_IF_FLAG(LW(0), STATUS_FLAG_SHRINK)
                    EVT_SUB(LW(1), 10)
                    EVT_ADD(LW(2), 4)
                EVT_ELSE
                    EVT_SUB(LW(1), 5)
                    EVT_ADD(LW(2), 11)
                EVT_END_IF
                EVT_CALL(SetActorPos, ACTOR_SELF, LW(1), LW(2), LW(3))
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_stone_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoAirLift)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_stone_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_stone_chomp_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
        EVT_CASE_EQ(EVENT_UP_AND_AWAY)
            EVT_WAIT(1000)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_IF_NE(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 0, LW(2))
            EVT_CALL(FallToGoal, ACTOR_SELF, 11)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80222ED0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SET(LW(1), 0)
    EVT_ADD(LW(0), 45)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3F9)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_stone_chomp_Palette_00_Anim_5)
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x10F)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_stone_chomp_Palette_00_Anim_1)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 20)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3F9)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 25)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3F9)
            EVT_SUB(LW(0), 15)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3F9)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_stone_chomp_Palette_00_Anim_4)
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_stone_chomp_Palette_00_Anim_4)
            EVT_EXEC_WAIT(N(8022181C))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_stone_chomp_Palette_00_Anim_1)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_stone_chomp_Palette_00_Anim_1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
    EVT_IF_FLAG(LW(10), STATUS_FLAG_SHRINK)
        EVT_ADD(LW(0), 4)
    EVT_ELSE
        EVT_ADD(LW(0), 10)
    EVT_END_IF
    EVT_SET(LW(1), 27)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, LW(0), LW(1), LW(2))
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_stone_chomp_Palette_00_Anim_4)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 40)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3F9)
            EVT_ADD(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3F9)
            EVT_ADD(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3F9)
            EVT_SUB(LW(0), 10)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3F9)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_stone_chomp_Palette_00_Anim_1)
            EVT_WAIT(8)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_stone_chomp_Palette_00_Anim_4)
            EVT_EXEC_WAIT(N(8022181C))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_stone_chomp_Palette_00_Anim_1)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetPartPos, ACTOR_SELF, 2, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
