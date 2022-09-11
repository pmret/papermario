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
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8021A11C)))
    EVT_CALL(GetActorVar, -127, 0, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetActorVar, -127, 8, 0)
        EVT_CALL(N(UnkBattleFunc1), -10, 0, 10, 0)
        EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8021B81C)))
        EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021A560)))
        EVT_CALL(SetPartEventBits, -127, 1, 4096, 0)
    EVT_ELSE
        EVT_CALL(SetActorVar, -127, 8, 1)
        EVT_CALL(SetTargetOffset, -127, 1, 0, 16)
        EVT_CALL(func_8027D4C8, -127, 1, -1, -9)
        EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_Chan)))
        EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021AAB8)))
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80219E70)))
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
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_Chan)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021AAB8)))
    EVT_CALL(SetActorVar, -127, 9, 1)
    EVT_CALL(SetDefenseTable, -127, 1, EVT_PTR(N(defenseTable_80219D6C)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80219F08)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_HP_OFFSET_BELOW, 0)
    EVT_CALL(SetPartEventBits, -127, 1, 16, 0)
    EVT_CALL(SetPartEventBits, -127, 1, 4096, 1)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_400, 1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_7)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 24)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorSounds, -127, 2, 769, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(GetIndexFromPos, -127, LVarA)
    EVT_MOD(LVarA, 4)
    EVT_CALL(SetGoalToIndex, -127, LVarA)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(SetHomePos, -127, LVarA, LVarB, LVarC)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021A560) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(9)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(10)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(8021A12C))
        EVT_CASE_EQ(13)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(8021A12C))
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_SET_CONST(LVar2, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021A12C))
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_SET_CONST(LVar2, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoReturnHome)
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(23)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(25)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoImmune)
            EVT_WAIT(2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, 0x200000)
                EVT_EXEC_WAIT(N(8021A12C))
            EVT_END_IF
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(49)
        EVT_CASE_EQ(57)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 1)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_4)
            EVT_SET_CONST(LVar2, NPC_ANIM_chan_Palette_00_Anim_6)
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
    EVT_CALL(GetActorVar, -127, 8, LVar3)
    EVT_IF_EQ(LVar3, 2)
        EVT_SET(LVar1, LVar2)
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
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_SET_CONST(LVar2, NPC_ANIM_chan_Palette_00_Anim_7)
            EVT_EXEC_WAIT(N(8021AA1C))
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_CALL(GetActorVar, -127, 8, LVar0)
            EVT_IF_NE(LVar0, 2)
                EVT_SET_CONST(LVar0, 0x00000001)
                EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
                EVT_SET_CONST(LVar2, NPC_ANIM_chan_Palette_00_Anim_6)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 0x00000001)
                EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_14)
                EVT_SET_CONST(LVar2, NPC_ANIM_chan_Palette_00_Anim_15)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_END_IF
        EVT_CASE_EQ(36)
            EVT_CALL(GetActorVar, -127, 8, LVar0)
            EVT_IF_NE(LVar0, 2)
                EVT_SET_CONST(LVar0, 0x00000001)
                EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
                EVT_SET_CONST(LVar2, NPC_ANIM_chan_Palette_00_Anim_6)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_SET_CONST(LVar0, 0x00000001)
                EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
                EVT_EXEC_WAIT(DoDeath)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 0x00000001)
                EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_14)
                EVT_SET_CONST(LVar2, NPC_ANIM_chan_Palette_00_Anim_15)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_SET_CONST(LVar0, 0x00000001)
                EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_15)
                EVT_EXEC_WAIT(DoDeath)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_SET_CONST(LVar2, NPC_ANIM_chan_Palette_00_Anim_7)
            EVT_EXEC_WAIT(N(8021AA1C))
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(13)
            EVT_CALL(SetActorVar, -127, 8, 2)
            EVT_CALL(SetTargetOffset, -127, 1, 0, 16)
            EVT_CALL(func_8027D4C8, -127, 1, -1, -9)
            EVT_CALL(SetActorVar, -127, 9, 1)
            EVT_CALL(SetDefenseTable, -127, 1, EVT_PTR(N(defenseTable_80219D6C)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80219F08)))
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_400, 1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_CALL(SetActorRotationOffset, -127, 0, 12, 0)
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
            EVT_USE_BUF(EVT_PTR(N(intTable_8021AA6C)))
            EVT_LOOP(19)
                EVT_BUF_READ1(LVar0)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_7)
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoReturnHome)
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(23)
            EVT_CALL(GetActorVar, -127, 8, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 0x00000001)
                EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_C)
                EVT_EXEC_WAIT(DoImmune)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_D)
                EVT_WAIT(8)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 0x00000001)
                EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_2)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(25)
            EVT_CALL(GetActorVar, -127, 8, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 0x00000001)
                EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_C)
                EVT_EXEC_WAIT(DoImmune)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_D)
                EVT_WAIT(8)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 0x00000001)
                EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_2)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(27)
            EVT_WAIT(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, 0x80000)
                EVT_ADD(LVar1, 9)
            EVT_ELSE
                EVT_ADD(LVar1, 24)
            EVT_END_IF
            EVT_CALL(PlayEffect, 0x1A, 0, LVar0, LVar1, LVar2, 20, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(20)
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_SET_CONST(LVar2, NPC_ANIM_chan_Palette_00_Anim_7)
            EVT_EXEC_WAIT(N(8021AA1C))
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_SET_CONST(LVar2, NPC_ANIM_chan_Palette_00_Anim_7)
            EVT_EXEC_WAIT(N(8021AA1C))
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_SET_CONST(LVar2, NPC_ANIM_chan_Palette_00_Anim_7)
            EVT_EXEC_WAIT(N(8021AA1C))
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_SET_CONST(LVar2, NPC_ANIM_chan_Palette_00_Anim_7)
            EVT_EXEC_WAIT(N(8021AA1C))
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(49)
            EVT_CALL(GetActorVar, -127, 8, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 0x00000001)
                EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_1)
                EVT_EXEC_WAIT(DoRecover)
            EVT_END_IF
        EVT_CASE_EQ(57)
            EVT_CALL(GetActorVar, -127, 8, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 0x00000001)
                EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_4)
                EVT_SET_CONST(LVar2, NPC_ANIM_chan_Palette_00_Anim_6)
                EVT_EXEC_WAIT(DoScareAway)
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LVar0, 0x00000001)
                EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_2)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(58)
            EVT_CALL(GetActorVar, -127, 8, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 0x00000001)
                EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_4)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 0x00000001)
                EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_2)
            EVT_END_IF
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_CALL(GetActorVar, -127, 8, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 0x00000001)
                EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_6)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 0x00000001)
                EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_7)
            EVT_END_IF
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(31)
            EVT_CALL(GetActorVar, -127, 8, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 0x00000001)
                EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_C)
                EVT_EXEC_WAIT(DoImmune)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_D)
                EVT_WAIT(8)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 0x00000001)
                EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_2)
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
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_Chan)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021AAB8)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80219E70)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_HP_OFFSET_BELOW, 0)
    EVT_CALL(SetPartEventBits, -127, 1, 4096, 1)
    EVT_CALL(GetIndexFromPos, -127, LVar0)
    EVT_MOD(LVar0, 4)
    EVT_CALL(SetGoalToIndex, -127, LVar0)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetHomePos, -127, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar4, LVar2)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_0)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_4)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar4, LVar2)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_0)
        EVT_WAIT(8)
    EVT_END_IF
    EVT_CALL(SetActorSounds, -127, 2, 769, 0)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_F)
        EVT_CALL(SetBattleCamZoom, 430)
        EVT_CALL(SetBattleCamOffsetZ, 20)
        EVT_CALL(MoveBattleCamOver, 10)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 3, 16)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(SetPartYaw, -127, 1, 180)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_7)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar1, 24)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_WAIT(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_0)
            EVT_END_THREAD
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT(8)
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
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 65535, 0, 3, 32)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 30)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_WAIT(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_0)
            EVT_END_THREAD
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT(8)
            EVT_CALL(YieldTurn)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_4)
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
    EVT_CALL(GetActorVar, -127, 8, LVar0)
    EVT_IF_EQ(LVar0, 2)
        EVT_CALL(GetActorVar, -127, 9, LVar0)
        EVT_SUB(LVar0, 1)
        EVT_IF_GT(LVar0, 0)
            EVT_CALL(SetActorVar, -127, 9, LVar0)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_WAIT(30)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_ELSE
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_WAIT(20)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_2)
            EVT_SET_CONST(LVar2, NPC_ANIM_chan_Palette_00_Anim_1)
            EVT_EXEC_WAIT(D_8029BBB4)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetActorVar, -127, 8, 1)
            EVT_CALL(SetTargetOffset, -127, 1, 0, 16)
            EVT_CALL(func_8027D4C8, -127, 1, -1, -9)
            EVT_CALL(SetDefenseTable, -127, 1, EVT_PTR(N(defenseTable_80219D50)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80219E70)))
            EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8021A11C)))
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
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_9)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(PlayEffect, 0x1D, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_WAIT(10)
        EVT_CALL(PlayEffect, 0x1D, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_WAIT(5)
        EVT_CALL(PlayEffect, 0x1D, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2021)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_5)
    EVT_WAIT(20)
    EVT_CALL(SetActorSounds, -127, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20D3)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 2, 16)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
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
                EVT_IF_EQ(LVarA, 5)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_D)
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
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 65535, 0, 2, 32)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chan_Palette_00_Anim_1)
            EVT_WAIT(8)
            EVT_CALL(YieldTurn)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_chan_Palette_00_Anim_4)
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
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021D0CC)))
    EVT_CALL(BindNextTurn, -127, EVT_PTR(N(nextTurn_8021CD7C)))
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
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, -127, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, 131103, -127, 1, 10682372, 10682371)
                EVT_CALL(SetActorVar, -127, 0, 1)
            EVT_END_IF
        EVT_CASE_EQ(12)
            EVT_CALL(GetActorVar, -127, 8, LVar0)
            EVT_IF_EQ(LVar0, 2)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, 0x37100A)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET_CONST(LVarA, NPC_ANIM_chan_Palette_00_Anim_4)
            EVT_SET_CONST(LVarB, NPC_ANIM_chan_Palette_00_Anim_3)
            EVT_CALL(GetActorVar, -127, 8, LVar0)
            EVT_IF_EQ(LVar0, 2)
                EVT_SET_CONST(LVarA, NPC_ANIM_chan_Palette_00_Anim_7)
                EVT_SET_CONST(LVarB, NPC_ANIM_chan_Palette_00_Anim_2)
            EVT_END_IF
            EVT_CALL(GetActorHP, -127, LVar0)
            EVT_CALL(GetEnemyMaxHP, -127, LVar1)
            EVT_DIV(LVar1, 2)
            EVT_IF_LE(LVar0, LVar1)
                EVT_CALL(GetActorVar, -127, 2, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                    EVT_CALL(MoveBattleCamOver, 10)
                    EVT_CALL(ActorSpeak, 131105, -127, 1, LVarA, LVarB)
                    EVT_CALL(SetActorVar, -127, 2, 1)
                    EVT_BREAK_SWITCH
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(GetPlayerHP, LVar0)
            EVT_IF_LE(LVar0, 5)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, 131106, -127, 1, LVarA, LVarB)
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
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(13)
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_NOT_FLAG(LVar0, 0x20)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, 0x3F1000)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET(LocalFlag(0), 0)
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(1)
                EVT_CASE_OR_EQ(0)
                    EVT_SET(LocalFlag(0), 1)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
            EVT_IF_EQ(LocalFlag(0), 0)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
            EVT_WAIT(30)
            EVT_CALL(GetActorVar, -127, 8, LVar0)
            EVT_IF_EQ(LVar0, 2)
                EVT_CALL(GetActorVar, -127, 1, LVar0)
                EVT_ADD(LVar0, 1)
                EVT_SWITCH(LVar0)
                    EVT_CASE_EQ(1)
                        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                        EVT_CALL(MoveBattleCamOver, 10)
                        EVT_CALL(ActorSpeak, 131104, -127, 1, 10682375, 10682370)
                    EVT_CASE_EQ(2)
                    EVT_CASE_EQ(3)
                        EVT_SET(LVar0, 0)
                EVT_END_SWITCH
                EVT_CALL(SetActorVar, -127, 1, LVar0)
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
