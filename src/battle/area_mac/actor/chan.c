#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/chan.h"

#define NAMESPACE b_area_mac_chan

s32 N(defenseTable_80219D50)[] = {
    ELEMENT_NORMAL, 2,
    ELEMENT_FIRE, 99,
    ELEMENT_BLAST, 99,
    ELEMENT_END,
};

s32 N(defenseTable_80219D6C)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_80219D78)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 30,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 50,
    STATUS_FEAR, 0,
    STATUS_STATIC, 50,
    STATUS_PARALYZE, 50,
    STATUS_SHRINK, 50,
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

extern s32 N(idleAnimations_80219EBC)[];
extern EvtScript N(init_8021CCDC);

ActorPartBlueprint N(partsTable_80219E24)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 16 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80219EBC),
        .defenseTable = N(defenseTable_80219D50),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .unk_1C = 1,
        .unk_1D = 263,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_HP_OFFSET_BELOW,
    .type = ACTOR_TYPE_CHAN,
    .level = 0,
    .maxHP = 15,
    .partCount = ARRAY_COUNT(N(partsTable_80219E24)),
    .partsData = N(partsTable_80219E24),
    .script = &N(init_8021CCDC),
    .statusTable = N(statusTable_80219D78),
    .escapeChance = 100,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 0,
    .size = { 22, 18 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(idleAnimations_80219E70)[] = {
    STATUS_NORMAL,    NPC_ANIM_chan_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_chan_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_chan_Palette_00_Anim_A,
    STATUS_POISON,    NPC_ANIM_chan_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_chan_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_chan_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_chan_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_chan_Palette_00_Anim_B,
    STATUS_FEAR,      NPC_ANIM_chan_Palette_00_Anim_B,
    STATUS_END,
};

s32 N(idleAnimations_80219EBC)[] = {
    STATUS_NORMAL,    NPC_ANIM_chan_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_chan_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_chan_Palette_00_Anim_A,
    STATUS_POISON,    NPC_ANIM_chan_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_chan_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_chan_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_chan_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_chan_Palette_00_Anim_B,
    STATUS_FEAR,      NPC_ANIM_chan_Palette_00_Anim_B,
    STATUS_END,
};

s32 N(idleAnimations_80219F08)[] = {
    STATUS_NORMAL,    NPC_ANIM_chan_Palette_00_Anim_2,
    STATUS_STONE,     NPC_ANIM_chan_Palette_00_Anim_F,
    STATUS_SLEEP,     NPC_ANIM_chan_Palette_00_Anim_10,
    STATUS_POISON,    NPC_ANIM_chan_Palette_00_Anim_2,
    STATUS_STOP,      NPC_ANIM_chan_Palette_00_Anim_F,
    STATUS_STATIC,    NPC_ANIM_chan_Palette_00_Anim_2,
    STATUS_DIZZY,     NPC_ANIM_chan_Palette_00_Anim_11,
    STATUS_FEAR,      NPC_ANIM_chan_Palette_00_Anim_11,
    STATUS_END,
};

#include "common/UnkBattleFunc1.inc.c"

extern EvtScript N(idle_8021A11C);
extern EvtScript N(takeTurn_8021B81C);
extern EvtScript N(handleEvent_8021A560);
extern EvtScript N(takeTurn_Chan);
extern EvtScript N(handleEvent_8021AAB8);

EvtScript N(80219F4C) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021A11C)))
    EVT_CALL(GetActorVar, -127, 0, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(SetActorVar, -127, 8, 0)
        EVT_CALL(N(UnkBattleFunc1), -10, 0, 10, 0)
        EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021B81C)))
        EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021A560)))
        EVT_CALL(SetPartEventBits, -127, 1, 4096, 0)
    EVT_ELSE
        EVT_CALL(SetActorVar, -127, 8, 1)
        EVT_CALL(SetTargetOffset, -127, 1, 0, 16)
        EVT_CALL(func_8027D4C8, -127, 1, -1, -9)
        EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_Chan)))
        EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021AAB8)))
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80219E70)))
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_HP_OFFSET_BELOW, 0)
        EVT_CALL(SetPartEventBits, -127, 1, 4096, 1)
    EVT_END_IF
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8021A11C) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(8021A12C) = {
    EVT_CALL(func_8027D32C, -127)
    EVT_CALL(SetActorVar, -127, 8, 2)
    EVT_CALL(SetTargetOffset, -127, 1, 0, 16)
    EVT_CALL(func_8027D4C8, -127, 1, -1, -9)
    EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_Chan)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021AAB8)))
    EVT_CALL(SetActorVar, -127, 9, 1)
    EVT_CALL(SetDefenseTable, -127, 1, EVT_ADDR(N(defenseTable_80219D6C)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80219F08)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_HP_OFFSET_BELOW, 0)
    EVT_CALL(SetPartEventBits, -127, 1, 16, 0)
    EVT_CALL(SetPartEventBits, -127, 1, 4096, 1)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_400, 1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_7)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(1), 24)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorSounds, -127, 2, 769, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(GetIndexFromPos, -127, LW(10))
    EVT_MOD(LW(10), 4)
    EVT_CALL(SetGoalToIndex, -127, LW(10))
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(10), LW(11), LW(12))
    EVT_CALL(SetHomePos, -127, LW(10), LW(11), LW(12))
    EVT_SET(LW(13), LW(10))
    EVT_SET(LW(14), LW(11))
    EVT_SET(LW(15), LW(12))
    EVT_SUB(LW(13), LW(0))
    EVT_SUB(LW(14), LW(1))
    EVT_SUB(LW(15), LW(2))
    EVT_DIV(LW(13), 2)
    EVT_DIV(LW(14), 2)
    EVT_DIV(LW(15), 2)
    EVT_ADD(LW(0), LW(13))
    EVT_ADD(LW(1), LW(14))
    EVT_ADD(LW(2), LW(15))
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(10), LW(11), LW(12))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021A560) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(9)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(8021A12C))
        EVT_CASE_EQ(13)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(8021A12C))
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_SET_CONST(LW(2), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021A12C))
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_SET_CONST(LW(2), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoReturnHome)
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(23)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(25)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoImmune)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_NOT_FLAG(LW(0), 0x200000)
                EVT_EXEC_WAIT(N(8021A12C))
            EVT_END_IF
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(49)
        EVT_CASE_EQ(57)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 1)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_4)
            EVT_SET_CONST(LW(2), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021AA1C) = {
    EVT_CALL(GetActorVar, -127, 8, LW(3))
    EVT_IF_EQ(LW(3), 2)
        EVT_SET(LW(1), LW(2))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(intTable_8021AA6C)[] = {
    0x00000007, 0x0000000D, 0x00000011, 0x00000015, 0x00000017, 0x00000018, 0x00000017, 0x00000015,
    0x00000011, 0x0000000D, 0x00000007, 0x00000000, 0x00000004, 0x00000007, 0x00000006, 0x00000004,
    0x00000000, 0x00000002, 0x00000000,
};

EvtScript N(handleEvent_8021AAB8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_SET_CONST(LW(2), NPC_ANIM_chan_Palette_00_Anim_7)
            EVT_EXEC_WAIT(N(8021AA1C))
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_CALL(GetActorVar, -127, 8, LW(0))
            EVT_IF_NE(LW(0), 2)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
                EVT_SET_CONST(LW(2), NPC_ANIM_chan_Palette_00_Anim_6)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_14)
                EVT_SET_CONST(LW(2), NPC_ANIM_chan_Palette_00_Anim_15)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_END_IF
        EVT_CASE_EQ(36)
            EVT_CALL(GetActorVar, -127, 8, LW(0))
            EVT_IF_NE(LW(0), 2)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
                EVT_SET_CONST(LW(2), NPC_ANIM_chan_Palette_00_Anim_6)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
                EVT_EXEC_WAIT(DoDeath)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_14)
                EVT_SET_CONST(LW(2), NPC_ANIM_chan_Palette_00_Anim_15)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_15)
                EVT_EXEC_WAIT(DoDeath)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_SET_CONST(LW(2), NPC_ANIM_chan_Palette_00_Anim_7)
            EVT_EXEC_WAIT(N(8021AA1C))
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(13)
            EVT_CALL(SetActorVar, -127, 8, 2)
            EVT_CALL(SetTargetOffset, -127, 1, 0, 16)
            EVT_CALL(func_8027D4C8, -127, 1, -1, -9)
            EVT_CALL(SetActorVar, -127, 9, 1)
            EVT_CALL(SetDefenseTable, -127, 1, EVT_ADDR(N(defenseTable_80219D6C)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80219F08)))
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_400, 1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_CALL(SetActorRotationOffset, -127, 0, 12, 0)
            EVT_THREAD
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -45)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -90)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -135)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -180)
                EVT_WAIT_FRAMES(1)
            EVT_END_THREAD
            EVT_USE_BUF(EVT_ADDR(N(intTable_8021AA6C)))
            EVT_LOOP(19)
                EVT_BUF_READ1(LW(0))
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LW(0), 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_7)
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoReturnHome)
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(23)
            EVT_CALL(GetActorVar, -127, 8, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_C)
                EVT_EXEC_WAIT(DoImmune)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_D)
                EVT_WAIT_FRAMES(8)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_2)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(25)
            EVT_CALL(GetActorVar, -127, 8, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_C)
                EVT_EXEC_WAIT(DoImmune)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_D)
                EVT_WAIT_FRAMES(8)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_2)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(27)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
            EVT_IF_FLAG(LW(3), 0x80000)
                EVT_ADD(LW(1), 9)
            EVT_ELSE
                EVT_ADD(LW(1), 24)
            EVT_END_IF
            EVT_CALL(PlayEffect, 0x1A, 0, LW(0), LW(1), LW(2), 20, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(20)
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_SET_CONST(LW(2), NPC_ANIM_chan_Palette_00_Anim_7)
            EVT_EXEC_WAIT(N(8021AA1C))
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_SET_CONST(LW(2), NPC_ANIM_chan_Palette_00_Anim_7)
            EVT_EXEC_WAIT(N(8021AA1C))
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_SET_CONST(LW(2), NPC_ANIM_chan_Palette_00_Anim_7)
            EVT_EXEC_WAIT(N(8021AA1C))
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_SET_CONST(LW(2), NPC_ANIM_chan_Palette_00_Anim_7)
            EVT_EXEC_WAIT(N(8021AA1C))
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(49)
            EVT_CALL(GetActorVar, -127, 8, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_1)
                EVT_EXEC_WAIT(DoRecover)
            EVT_END_IF
        EVT_CASE_EQ(57)
            EVT_CALL(GetActorVar, -127, 8, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_4)
                EVT_SET_CONST(LW(2), NPC_ANIM_chan_Palette_00_Anim_6)
                EVT_EXEC_WAIT(DoScareAway)
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_2)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(58)
            EVT_CALL(GetActorVar, -127, 8, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_4)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_2)
            EVT_END_IF
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_CALL(GetActorVar, -127, 8, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_7)
            EVT_END_IF
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(31)
            EVT_CALL(GetActorVar, -127, 8, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_C)
                EVT_EXEC_WAIT(DoImmune)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_D)
                EVT_WAIT_FRAMES(8)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_2)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021B81C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetActorVar, -127, 8, 1)
    EVT_CALL(SetTargetOffset, -127, 1, 0, 16)
    EVT_CALL(func_8027D4C8, -127, 1, -1, -9)
    EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_Chan)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021AAB8)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80219E70)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_HP_OFFSET_BELOW, 0)
    EVT_CALL(SetPartEventBits, -127, 1, 4096, 1)
    EVT_CALL(GetIndexFromPos, -127, LW(0))
    EVT_MOD(LW(0), 4)
    EVT_CALL(SetGoalToIndex, -127, LW(0))
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetHomePos, -127, LW(0), LW(1), LW(2))
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
        EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(4), LW(2))
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_0)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_4)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
        EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(4), LW(2))
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_0)
        EVT_WAIT_FRAMES(8)
    EVT_END_IF
    EVT_CALL(SetActorSounds, -127, 2, 769, 0)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_F)
        EVT_CALL(SetBattleCamZoom, 430)
        EVT_CALL(SetBattleCamOffsetZ, 20)
        EVT_CALL(MoveBattleCamOver, 10)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 3, 16)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(SetPartYaw, -127, 1, 180)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_7)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(1), 24)
            EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SET(LW(1), 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_ADD(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_WAIT_FRAMES(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_0)
            EVT_END_THREAD
            EVT_ADD(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT_FRAMES(8)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_4)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_1)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_7)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(1), 24)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(3), LW(4), LW(5))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SET(LW(1), LW(4))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 65535, 0, 3, 32)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 30)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_WAIT_FRAMES(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_0)
            EVT_END_THREAD
            EVT_ADD(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT_FRAMES(8)
            EVT_CALL(YieldTurn)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_1)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_LABEL(10)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_Chan) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, -127, 8, LW(0))
    EVT_IF_EQ(LW(0), 2)
        EVT_CALL(GetActorVar, -127, 9, LW(0))
        EVT_SUB(LW(0), 1)
        EVT_IF_GT(LW(0), 0)
            EVT_CALL(SetActorVar, -127, 9, LW(0))
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_WAIT_FRAMES(30)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_ELSE
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_2)
            EVT_SET_CONST(LW(2), NPC_ANIM_chan_Palette_00_Anim_1)
            EVT_EXEC_WAIT(D_8029BBB4)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetActorVar, -127, 8, 1)
            EVT_CALL(SetTargetOffset, -127, 1, 0, 16)
            EVT_CALL(func_8027D4C8, -127, 1, -1, -9)
            EVT_CALL(SetDefenseTable, -127, 1, EVT_ADDR(N(defenseTable_80219D50)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80219E70)))
            EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021A11C)))
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_400, 0)
        EVT_END_IF
        EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_C)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_9)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(PlayEffect, 0x1D, 1, LW(0), LW(1), LW(2), 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(PlayEffect, 0x1D, 1, LW(0), LW(1), LW(2), 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_WAIT_FRAMES(5)
        EVT_CALL(PlayEffect, 0x1D, 1, LW(0), LW(1), LW(2), 32, 4, 0, 10, 0, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2021)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_5)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetActorSounds, -127, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20D3)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 2, 16)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LW(10), LW(0))
            EVT_THREAD
                EVT_LOOP(0)
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
                    EVT_ADD(LW(0), 30)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
                    EVT_IF_GT(LW(0), LW(3))
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_B)
                EVT_IF_EQ(LW(10), 5)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_END_IF
                EVT_WAIT_FRAMES(15)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -150, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(14.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_WAIT_FRAMES(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 200)
            EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_D)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(14.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 65535, 0, 2, 32)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_1)
            EVT_WAIT_FRAMES(8)
            EVT_CALL(YieldTurn)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_chan_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_1)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(handleEvent_8021D0CC);
extern EvtScript N(nextTurn_8021CD7C);

EvtScript N(init_8021CCDC) = {
    EVT_EXEC_WAIT(N(80219F4C))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021D0CC)))
    EVT_CALL(BindNextTurn, -127, EVT_ADDR(N(nextTurn_8021CD7C)))
    EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_CALL(SetActorVar, -127, 1, 0)
    EVT_CALL(SetActorVar, -127, 2, 0)
    EVT_CALL(SetBattleFlagBits, 8388608, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_8021CD7C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, -127, 0, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, 131103, -127, 1, 10682372, 10682371)
                EVT_CALL(SetActorVar, -127, 0, 1)
            EVT_END_IF
        EVT_CASE_EQ(12)
            EVT_CALL(GetActorVar, -127, 8, LW(0))
            EVT_IF_EQ(LW(0), 2)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_FLAG(LW(0), 0x37100A)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET_CONST(LW(10), NPC_ANIM_chan_Palette_00_Anim_4)
            EVT_SET_CONST(LW(11), NPC_ANIM_chan_Palette_00_Anim_3)
            EVT_CALL(GetActorVar, -127, 8, LW(0))
            EVT_IF_EQ(LW(0), 2)
                EVT_SET_CONST(LW(10), NPC_ANIM_chan_Palette_00_Anim_7)
                EVT_SET_CONST(LW(11), NPC_ANIM_chan_Palette_00_Anim_2)
            EVT_END_IF
            EVT_CALL(GetActorHP, -127, LW(0))
            EVT_CALL(GetEnemyMaxHP, -127, LW(1))
            EVT_DIV(LW(1), 2)
            EVT_IF_LE(LW(0), LW(1))
                EVT_CALL(GetActorVar, -127, 2, LW(0))
                EVT_IF_EQ(LW(0), 0)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                    EVT_CALL(MoveBattleCamOver, 10)
                    EVT_CALL(ActorSpeak, 131105, -127, 1, LW(10), LW(11))
                    EVT_CALL(SetActorVar, -127, 2, 1)
                    EVT_BREAK_SWITCH
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(GetPlayerHP, LW(0))
            EVT_IF_LE(LW(0), 5)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, 131106, -127, 1, LW(10), LW(11))
                EVT_BREAK_SWITCH
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021D0CC) = {
    EVT_EXEC_WAIT(N(handleEvent_8021AAB8))
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(13)
            EVT_CALL(GetBattleFlags, LW(0))
            EVT_IF_NOT_FLAG(LW(0), 0x20)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_FLAG(LW(0), 0x3F1000)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET(LF(0), 0)
            EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
            EVT_SWITCH(LW(0))
                EVT_CASE_OR_EQ(1)
                EVT_CASE_OR_EQ(0)
                    EVT_SET(LF(0), 1)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
            EVT_IF_EQ(LF(0), 0)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
            EVT_WAIT_FRAMES(30)
            EVT_CALL(GetActorVar, -127, 8, LW(0))
            EVT_IF_EQ(LW(0), 2)
                EVT_CALL(GetActorVar, -127, 1, LW(0))
                EVT_ADD(LW(0), 1)
                EVT_SWITCH(LW(0))
                    EVT_CASE_EQ(1)
                        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                        EVT_CALL(MoveBattleCamOver, 10)
                        EVT_CALL(ActorSpeak, 131104, -127, 1, 10682375, 10682370)
                    EVT_CASE_EQ(2)
                    EVT_CASE_EQ(3)
                        EVT_SET(LW(0), 0)
                EVT_END_SWITCH
                EVT_CALL(SetActorVar, -127, 1, LW(0))
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
