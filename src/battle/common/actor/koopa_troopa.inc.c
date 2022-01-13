#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/koopa_troopa.h"

s32 N(defenseTable_8021C960)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_HAMMER, 1,
    ELEMENT_JUMP, 1,
    ELEMENT_WATER, 1,
    ELEMENT_BLAST, 1,
    ELEMENT_END,
};

s32 N(defenseTable_8021C98C)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8021C998)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 90,
    STATUS_POISON, 60,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 0,
    STATUS_STATIC, 80,
    STATUS_PARALYZE, 90,
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

extern s32 N(idleAnimations_8021CA90)[];
extern EvtSource N(init_8021CB74);

ActorPartDesc N(partsTable_8021CA44)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 36 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021CA90),
        .defenseTable = N(defenseTable_8021C960),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .unk_1C = 249,
    },
};

ActorDesc NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_KOOPA_TROOPA,
    .level = 6,
    .maxHP = 4,
    .partCount = ARRAY_COUNT(N(partsTable_8021CA44)),
    .partsData = N(partsTable_8021CA44),
    .script = N(init_8021CB74),
    .statusTable = N(statusTable_8021C998),
    .escapeChance = 70,
    .airLiftChance = 90,
    .spookChance = 90,
    .baseStatusChance = 90,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 28, 36 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 32 },
    .statusMessageOffset = { 5, 32 },
};

s32 N(idleAnimations_8021CA90)[] = {
    STATUS_NORMAL,    NPC_ANIM_koopa_troopa_Palette_01_Anim_1,
    STATUS_STONE,     NPC_ANIM_koopa_troopa_Palette_01_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_koopa_troopa_Palette_01_Anim_11,
    STATUS_POISON,    NPC_ANIM_koopa_troopa_Palette_01_Anim_1,
    STATUS_STOP,      NPC_ANIM_koopa_troopa_Palette_01_Anim_0,
    STATUS_STATIC,    NPC_ANIM_koopa_troopa_Palette_01_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_koopa_troopa_Palette_01_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_koopa_troopa_Palette_01_Anim_13,
    STATUS_FEAR,      NPC_ANIM_koopa_troopa_Palette_01_Anim_13,
    STATUS_END,
};

s32 N(idleAnimations_8021CADC)[] = {
    STATUS_NORMAL,    NPC_ANIM_koopa_troopa_Palette_01_Anim_3,
    STATUS_STONE,     NPC_ANIM_koopa_troopa_Palette_01_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_koopa_troopa_Palette_01_Anim_11,
    STATUS_POISON,    NPC_ANIM_koopa_troopa_Palette_01_Anim_3,
    STATUS_STOP,      NPC_ANIM_koopa_troopa_Palette_01_Anim_0,
    STATUS_STATIC,    NPC_ANIM_koopa_troopa_Palette_01_Anim_3,
    STATUS_PARALYZE,  NPC_ANIM_koopa_troopa_Palette_01_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_koopa_troopa_Palette_01_Anim_13,
    STATUS_FEAR,      NPC_ANIM_koopa_troopa_Palette_01_Anim_13,
    STATUS_END,
};

s32 N(idleAnimations_8021CB28)[] = {
    STATUS_NORMAL,    NPC_ANIM_koopa_troopa_Palette_01_Anim_F,
    STATUS_STONE,     NPC_ANIM_koopa_troopa_Palette_01_Anim_10,
    STATUS_SLEEP,     NPC_ANIM_koopa_troopa_Palette_01_Anim_12,
    STATUS_POISON,    NPC_ANIM_koopa_troopa_Palette_01_Anim_F,
    STATUS_STOP,      NPC_ANIM_koopa_troopa_Palette_01_Anim_10,
    STATUS_STATIC,    NPC_ANIM_koopa_troopa_Palette_01_Anim_F,
    STATUS_PARALYZE,  NPC_ANIM_koopa_troopa_Palette_01_Anim_10,
    STATUS_DIZZY,     NPC_ANIM_koopa_troopa_Palette_01_Anim_14,
    STATUS_FEAR,      NPC_ANIM_koopa_troopa_Palette_01_Anim_14,
    STATUS_END,
};

extern EvtSource N(takeTurn_8021DD9C);
extern EvtSource N(idle_8021CD30);
extern EvtSource N(handleEvent_8021D218);

EvtSource N(init_8021CB74) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021DD9C)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021CD30)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021D218)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_RETURN
    EVT_END
};

#include "common/UnkBattleFunc1.inc.c"

EvtSource N(8021CBD8) = {
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_IF_FLAG(LW(1), 0x00041000)
                EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -5, 15)
                EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 0, 0)
                EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
            EVT_ELSE
                EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -4, 32)
                EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, -1, -4)
                EVT_CALL(N(UnkBattleFunc1), -15, 32, 5, 32)
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -5, 15)
            EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 0, 0)
            EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_8021CD30) = {
    EVT_LABEL(0)
    EVT_CALL(RandInt, 80, LW(10))
    EVT_ADD(LW(10), 80)
    EVT_LOOP(LW(10))
        EVT_LABEL(1)
        EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_EXEC_WAIT(N(8021CBD8))
        EVT_IF_EQ(LW(0), 1)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_IF_FLAG(LW(1), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021CADC)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleRunToGoal, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021CA90)))
        EVT_CASE_EQ(1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021CB28)))
    EVT_END_SWITCH
    EVT_LOOP(20)
        EVT_LABEL(2)
        EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_EXEC_WAIT(N(8021CBD8))
        EVT_IF_EQ(LW(0), 1)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_IF_FLAG(LW(1), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021CADC)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleRunToGoal, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021CA90)))
        EVT_CASE_EQ(1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021CB28)))
    EVT_END_SWITCH
    EVT_LOOP(80)
        EVT_LABEL(3)
        EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_EXEC_WAIT(N(8021CBD8))
        EVT_IF_EQ(LW(0), 1)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(3)
        EVT_END_IF
        EVT_IF_FLAG(LW(1), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(3)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(intTable_8021D1C0)[] = {
    0x00000009, 0x00000010, 0x00000016, 0x0000001A, 0x0000001E, 0x00000020, 0x00000021, 0x00000020,
    0x0000001E, 0x0000001A, 0x00000016, 0x00000010, 0x00000009, 0x00000000, 0x00000004, 0x00000006,
    0x00000007, 0x00000006, 0x00000004, 0x00000000, 0x00000002, 0x00000000,
};

EvtSource N(handleEvent_8021D218) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_C)
            EVT_SET_CONST(LW(2), NPC_ANIM_koopa_troopa_Palette_01_Anim_D)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_C)
            EVT_SET_CONST(LW(2), NPC_ANIM_koopa_troopa_Palette_01_Anim_D)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_D)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 9, 2)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_ADDR(N(defenseTable_8021C98C)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021CB28)))
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -5, 15)
            EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 0, 0)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_400, 1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
            EVT_CHILD_THREAD
                EVT_WAIT_FRAMES(4)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 30)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -30)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -60)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -75)
                EVT_WAIT_FRAMES(1)
            EVT_END_CHILD_THREAD
            EVT_USE_BUF(EVT_ADDR(N(intTable_8021D1C0)))
            EVT_LOOP(22)
                EVT_BUF_READ1(LW(0))
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LW(0), 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_F)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_4)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_7)
                EVT_EXEC_WAIT(DoImmune)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
                EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_8)
                    EVT_WAIT_FRAMES(10)
                EVT_END_IF
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_F)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_4)
                EVT_EXEC_WAIT(DoReturnHome)
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_1)
                EVT_EXEC_WAIT(DoRecover)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_F)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_4)
                EVT_SET_CONST(LW(2), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
                EVT_EXEC_WAIT(DoScareAway)
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_F)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_17)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_F)
            EVT_END_IF
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_17)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_F)
            EVT_END_IF
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_1)
                EVT_EXEC_WAIT(DoImmune)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_F)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(takeTurn_8021DD9C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_6)
    EVT_ELSE
        EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
        EVT_IF_EQ(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 9, LW(0))
            EVT_SUB(LW(0), 1)
            EVT_IF_GT(LW(0), 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, 9, LW(0))
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(3.0))
                EVT_WAIT_FRAMES(30)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_ELSE
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(3.0))
                EVT_WAIT_FRAMES(20)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
                EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 0, 0)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_JUMP_3E2)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_F)
                EVT_SET(LW(0), 0)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
                EVT_CHILD_THREAD
                    EVT_LOOP(5)
                        EVT_ADD(LW(0), 15)
                        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                        EVT_WAIT_FRAMES(1)
                    EVT_END_LOOP
                EVT_END_CHILD_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
                EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BA)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_1)
                EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021CA90)))
                EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_ADDR(N(defenseTable_8021C960)))
                EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -4, 32)
                EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, -1, -4)
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_400, 0)
                EVT_CALL(ResetActorSounds, ACTOR_SELF, 2)
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_7)
        EVT_WAIT_FRAMES(10)
        EVT_CHILD_THREAD
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(1), 4)
            EVT_CALL(PlayEffect, EFFECT_ID_1D, 1, LW(0), LW(1), LW(2), 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(3)
            EVT_CALL(PlayEffect, EFFECT_ID_1D, 1, LW(0), LW(1), LW(2), 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(PlayEffect, EFFECT_ID_1D, 1, LW(0), LW(1), LW(2), 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_END_CHILD_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2021)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_6)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20D3)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -40, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(GetBattlePhase, LW(0))
            EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_F)
                EVT_CALL(SetBattleCamZoom, 300)
                EVT_CALL(SetBattleCamOffsetZ, 20)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(func_8024ECF8, -1, 1, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_8)
            EVT_WAIT_FRAMES(8)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_WAIT_FRAMES(4)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_15)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_16)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(1), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_17)
            EVT_WAIT_FRAMES(6)
            EVT_SUB(LW(1), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_17)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_1)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetPartYaw, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 65535, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 40)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_8)
            EVT_WAIT_FRAMES(8)
            EVT_CALL(YieldTurn)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_4)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_1)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
