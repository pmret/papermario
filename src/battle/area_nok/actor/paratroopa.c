#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/koopa_troopa.h"
#include "sprite/npc/para_troopa.h"

#define NAMESPACE b_area_nok_paratroopa

s32 N(defenseTable_80223900)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_HAMMER, 1,
    ELEMENT_JUMP, 1,
    ELEMENT_WATER, 1,
    ELEMENT_BLAST, 1,
    ELEMENT_END,
};

s32 N(defenseTable_8022392C)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(defenseTable_80223938)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_80223944)[] = {
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

s32 N(statusTable_802239F0)[] = {
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
    STATUS_DIZZY_TURN_MOD, 1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 1,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

extern s32 N(idleAnimations_802258D0)[];
extern s32 N(idleAnimations_80223B30)[];
extern s32 N(idleAnimations_80223BC8)[];

ActorPartDesc N(partsTable_80223A9C)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 36 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802258D0),
        .defenseTable = N(defenseTable_80223900),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .unk_1C = 249,
    },
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -4, 36 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80223B30),
        .defenseTable = N(defenseTable_8022392C),
        .eventFlags = ACTOR_EVENT_FLAG_GROUNDABLE,
        .elementImmunityFlags = 0,
        .unk_1C = 754,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 32 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80223BC8),
        .defenseTable = N(defenseTable_80223900),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 246,
    },
};

extern EvtSource N(init_80223C3C);

ActorDesc NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_PARATROOPA,
    .level = 6,
    .maxHP = 4,
    .partCount = ARRAY_COUNT(N(partsTable_80223A9C)),
    .partsData = N(partsTable_80223A9C),
    .script = N(init_80223C3C),
    .statusTable = N(statusTable_802239F0),
    .escapeChance = 60,
    .airLiftChance = 95,
    .spookChance = 100,
    .baseStatusChance = 90,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 50, 38 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 29 },
    .statusMessageOffset = { 8, 30 },
};

s32 N(idleAnimations_80223B30)[] = {
    STATUS_NORMAL,    NPC_ANIM_para_troopa_Palette_01_Anim_1,
    STATUS_STONE,     NPC_ANIM_para_troopa_Palette_01_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_para_troopa_Palette_01_Anim_12,
    STATUS_POISON,    NPC_ANIM_para_troopa_Palette_01_Anim_0,
    STATUS_STOP,      NPC_ANIM_para_troopa_Palette_01_Anim_0,
    STATUS_STATIC,    NPC_ANIM_para_troopa_Palette_01_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_para_troopa_Palette_01_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_para_troopa_Palette_01_Anim_13,
    STATUS_FEAR,      NPC_ANIM_para_troopa_Palette_01_Anim_13,
    STATUS_END,
};

s32 N(idleAnimations_80223B7C)[] = {
    STATUS_NORMAL,    NPC_ANIM_para_troopa_Palette_01_Anim_1,
    STATUS_STONE,     NPC_ANIM_para_troopa_Palette_01_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_para_troopa_Palette_01_Anim_12,
    STATUS_POISON,    NPC_ANIM_para_troopa_Palette_01_Anim_0,
    STATUS_STOP,      NPC_ANIM_para_troopa_Palette_01_Anim_0,
    STATUS_STATIC,    NPC_ANIM_para_troopa_Palette_01_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_para_troopa_Palette_01_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_para_troopa_Palette_01_Anim_13,
    STATUS_FEAR,      NPC_ANIM_para_troopa_Palette_01_Anim_13,
    STATUS_END,
};

s32 N(idleAnimations_80223BC8)[] = {
    STATUS_NORMAL,    NPC_ANIM_para_troopa_Palette_01_Anim_F,
    STATUS_STONE,     NPC_ANIM_para_troopa_Palette_01_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_para_troopa_Palette_01_Anim_12,
    STATUS_POISON,    NPC_ANIM_para_troopa_Palette_01_Anim_0,
    STATUS_STOP,      NPC_ANIM_para_troopa_Palette_01_Anim_0,
    STATUS_STATIC,    NPC_ANIM_para_troopa_Palette_01_Anim_F,
    STATUS_PARALYZE,  NPC_ANIM_para_troopa_Palette_01_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_para_troopa_Palette_01_Anim_13,
    STATUS_FEAR,      NPC_ANIM_para_troopa_Palette_01_Anim_13,
    STATUS_END,
};

EvtSource N(nextTurn_80223C14) = {
    EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_RETURN
    EVT_END
};

extern EvtSource N(takeTurn_80224854);
extern EvtSource N(idle_80223D8C);
extern EvtSource N(handleEvent_8022411C);

EvtSource N(init_80223C3C) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_80224854)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80223D8C)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8022411C)))
    EVT_CALL(BindNextTurn, -127, EVT_ADDR(N(nextTurn_80223C14)))
    EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_RETURN
    EVT_END
};

#include "common/StartRumbleWithParams.inc.c"

#include "common/UnkBattleFunc1.inc.c"

EvtSource N(80223CB4) = {
    EVT_IF_FLAG(LW(1), 0x41000)
        EVT_CALL(SetTargetOffset, -127, 2, 0, 25)
        EVT_CALL(func_8027D4C8, -127, 2, 3, -6)
        EVT_CALL(N(UnkBattleFunc1), -19, 25, 4, 28)
    EVT_ELSE
        EVT_CALL(SetTargetOffset, -127, 2, -2, 36)
        EVT_CALL(func_8027D4C8, -127, 2, 0, -7)
        EVT_CALL(N(UnkBattleFunc1), -10, 29, 8, 30)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_80223D8C) = {
    EVT_LABEL(10)
    EVT_CALL(RandInt, 80, LW(0))
    EVT_ADD(LW(0), 80)
    EVT_LOOP(LW(0))
        EVT_LABEL(0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_EXEC_WAIT(N(80223CB4))
        EVT_IF_FLAG(LW(1), 0x35D000)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(0.6005859375))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_ADDR(N(idleAnimations_80223B7C)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleFlyToGoal, ACTOR_SELF, 0, -5, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80223B30)))
    EVT_LOOP(20)
        EVT_LABEL(1)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_EXEC_WAIT(N(80223CB4))
        EVT_IF_FLAG(LW(1), 0x35D000)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(0.6005859375))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_ADDR(N(idleAnimations_80223B7C)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleFlyToGoal, ACTOR_SELF, 0, -5, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_ADDR(N(idleAnimations_80223B30)))
    EVT_LOOP(40)
        EVT_LABEL(2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_EXEC_WAIT(N(80223CB4))
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

EvtSource N(8022409C) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_para_troopa_Palette_01_Anim_3)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 11)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_para_troopa_Palette_01_Anim_1)
    EVT_RETURN
    EVT_END
};

extern EvtSource N(8022530C);

EvtSource N(handleEvent_8022411C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(9)
            EVT_CALL(SetActorVar, -127, 0, 1)
            EVT_SET_CONST(LW(0), 0x00000002)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(10)
            EVT_SET_CONST(LW(0), 0x00000002)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_CALL(GetBattlePhase, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_CALL(GetEncounterState, LW(0))
                EVT_IF_EQ(LW(0), 4)
                    EVT_EXEC_WAIT(N(8022530C))
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LW(0), 0x00000002)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LW(0), 0x00000002)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 0x00000002)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LW(0), 0x00000002)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_8)
            EVT_SET_CONST(LW(2), NPC_ANIM_para_troopa_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LW(0), 0x00000002)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_8)
            EVT_SET_CONST(LW(2), NPC_ANIM_para_troopa_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 0x00000002)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(12)
            EVT_SET_CONST(LW(0), 0x00000002)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(8022530C))
        EVT_CASE_EQ(15)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_8)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8022530C))
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_6)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(8022409C))
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LW(0), 0x00000002)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000002)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(23)
            EVT_CALL(SetActorVar, -127, 0, 1)
            EVT_SET_CONST(LW(0), 0x00000002)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_SET_CONST(LW(0), 0x00000002)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoImmune)
            EVT_CALL(GetBattlePhase, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_CALL(GetEncounterState, LW(0))
                EVT_IF_EQ(LW(0), 4)
                    EVT_EXEC_WAIT(N(8022530C))
                EVT_END_IF
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LW(0), 0x00000002)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000002)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(56)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(53)
            EVT_EXEC_WAIT(N(8022409C))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LW(0), 0x00000002)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 0)
            EVT_SET_CONST(LW(0), 0x00000002)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_3)
            EVT_SET_CONST(LW(2), NPC_ANIM_para_troopa_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(58)
            EVT_SET_CONST(LW(0), 0x00000002)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_3)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_SET_CONST(LW(0), 0x00000002)
            EVT_SET_CONST(LW(1), NPC_ANIM_para_troopa_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(takeTurn_80224854) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, 5)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_para_troopa_Palette_01_Anim_3)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 30, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -16, 0)
    EVT_CALL(func_8024E664, 1)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, 16)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E0)
            EVT_CALL(SetActorSounds, -127, 1, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_para_troopa_Palette_01_Anim_4)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(AddGoalPos, ACTOR_SELF, 6, 6, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT_FRAMES(6)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
            EVT_CALL(SetActorSounds, -127, 1, 0, 0)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 25)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_para_troopa_Palette_01_Anim_C)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, -127, 0, 10, 0)
                EVT_SET(LW(0), 0)
                EVT_LOOP(8)
                    EVT_ADD(LW(0), 90)
                    EVT_IF_GE(LW(0), 360)
                        EVT_SUB(LW(0), 360)
                    EVT_END_IF
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotationOffset, -127, 0, -10, 0)
            EVT_END_THREAD
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_para_troopa_Palette_01_Anim_7)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_para_troopa_Palette_01_Anim_7)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(1), 30)
            EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_WAIT_FRAMES(20)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(YieldTurn)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 2, 0, 2)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_EXEC_WAIT(N(8022409C))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 2, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E0)
    EVT_CALL(SetActorSounds, -127, 1, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_para_troopa_Palette_01_Anim_4)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(AddGoalPos, ACTOR_SELF, 6, 6, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT_FRAMES(6)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
    EVT_CALL(SetActorSounds, -127, 1, 0, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_para_troopa_Palette_01_Anim_C)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 65535, 0, 1, 32)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 30, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_para_troopa_Palette_01_Anim_D)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, -127, 0, 10, 0)
                EVT_SET(LW(0), 0)
                EVT_LOOP(12)
                    EVT_SUB(LW(0), 90)
                    EVT_IF_LT(LW(0), 0)
                        EVT_ADD(LW(0), 360)
                    EVT_END_IF
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotationOffset, -127, 0, -10, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_para_troopa_Palette_01_Anim_1)
            EVT_END_THREAD
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 30, 0)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(YieldTurn)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_EXEC_WAIT(N(8022409C))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

extern EvtSource N(802259B4);

EvtSource N(8022530C) = {
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 2, 0, 0, 0)
    EVT_CALL(func_8027D32C, -127)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 2, 131077)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 3, 1179652)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 1, 8388612)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 8)
    EVT_SUB(LW(2), 2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, LW(0), LW(1), LW(2))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
    EVT_CALL(SetActorSounds, -127, 2, 769, 0)
    EVT_CALL(GetActorVar, -127, 0, LW(10))
    EVT_IF_EQ(LW(10), 0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_SET(LW(1), 0)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.80078125))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
        EVT_CALL(N(StartRumbleWithParams), 128, 7)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(0.30078125))
        EVT_END_THREAD
        EVT_CALL(ResetActorSounds, -127, 2)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_LOOP(10)
            EVT_CALL(SetPartFlagBits, -127, 3, 1, 1)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartFlagBits, -127, 3, 1, 0)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetPartFlagBits, -127, 3, 1, 1)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_SET(LW(1), 0)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.80078125))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
        EVT_THREAD
            EVT_LOOP(10)
                EVT_CALL(SetPartFlagBits, -127, 3, 1, 1)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetPartFlagBits, -127, 3, 1, 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetPartFlagBits, -127, 3, 1, 1)
        EVT_END_THREAD
        EVT_CALL(N(StartRumbleWithParams), 150, 7)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(0.30078125))
        EVT_END_THREAD
        EVT_CALL(ResetActorSounds, -127, 2)
    EVT_END_IF
    EVT_CALL(GetIndexFromHome, -127, LW(0))
    EVT_MOD(LW(0), 4)
    EVT_CALL(SetGoalToIndex, -127, LW(0))
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetHomePos, -127, LW(0), LW(1), LW(2))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_1)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 0)
    EVT_CALL(SetStatusTable, -127, EVT_ADDR(N(statusTable_80223944)))
    EVT_CALL(BindNextTurn, -127, 0)
    EVT_EXEC_WAIT(N(802259B4))
    EVT_CALL(SetActorType, -127, 11)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_1000, 1)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_IF_NE(LW(10), 0)
        EVT_CALL(DispatchEvent, ACTOR_SELF, 13)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(idleAnimations_802258D0)[] = {
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

s32 N(idleAnimations_8022591C)[] = {
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

s32 N(idleAnimations_80225968)[] = {
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

extern EvtSource N(takeTurn_80226BDC);
extern EvtSource N(idle_80225B70);
extern EvtSource N(handleEvent_80226058);

EvtSource N(802259B4) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_80226BDC)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80225B70)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80226058)))
    EVT_CALL(SetActorVar, -127, 8, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(80225A18) = {
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_IF_FLAG(LW(1), 0x41000)
                EVT_CALL(SetTargetOffset, -127, 1, -5, 15)
                EVT_CALL(func_8027D4C8, -127, 1, 0, 0)
                EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
            EVT_ELSE
                EVT_CALL(SetTargetOffset, -127, 1, -4, 32)
                EVT_CALL(func_8027D4C8, -127, 1, -1, -4)
                EVT_CALL(N(UnkBattleFunc1), -15, 32, 5, 32)
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_CALL(SetTargetOffset, -127, 1, -5, 15)
            EVT_CALL(func_8027D4C8, -127, 1, 0, 0)
            EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_80225B70) = {
    EVT_LABEL(0)
    EVT_CALL(RandInt, 80, LW(10))
    EVT_ADD(LW(10), 80)
    EVT_LOOP(LW(10))
        EVT_LABEL(1)
        EVT_CALL(GetActorVar, -127, 8, LW(0))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_EXEC_WAIT(N(80225A18))
        EVT_IF_EQ(LW(0), 1)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_IF_FLAG(LW(1), 0x35D000)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022591C)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleRunToGoal, -127, 0)
    EVT_CALL(GetActorVar, -127, 8, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_802258D0)))
        EVT_CASE_EQ(1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80225968)))
    EVT_END_SWITCH
    EVT_LOOP(20)
        EVT_LABEL(2)
        EVT_CALL(GetActorVar, -127, 8, LW(0))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_EXEC_WAIT(N(80225A18))
        EVT_IF_EQ(LW(0), 1)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_IF_FLAG(LW(1), 0x35D000)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022591C)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleRunToGoal, -127, 0)
    EVT_CALL(GetActorVar, -127, 8, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_802258D0)))
        EVT_CASE_EQ(1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80225968)))
    EVT_END_SWITCH
    EVT_LOOP(80)
        EVT_LABEL(3)
        EVT_CALL(GetActorVar, -127, 8, LW(0))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(1))
        EVT_EXEC_WAIT(N(80225A18))
        EVT_IF_EQ(LW(0), 1)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(3)
        EVT_END_IF
        EVT_IF_FLAG(LW(1), 0x35D000)
            EVT_WAIT_FRAMES(1)
            EVT_GOTO(3)
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(intTable_80226000)[] = {
    0x00000009, 0x00000010, 0x00000016, 0x0000001A, 0x0000001E, 0x00000020, 0x00000021, 0x00000020,
    0x0000001E, 0x0000001A, 0x00000016, 0x00000010, 0x00000009, 0x00000000, 0x00000004, 0x00000006,
    0x00000007, 0x00000006, 0x00000004, 0x00000000, 0x00000002, 0x00000000,
};

EvtSource N(handleEvent_80226058) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_C)
            EVT_SET_CONST(LW(2), NPC_ANIM_koopa_troopa_Palette_01_Anim_D)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_C)
            EVT_SET_CONST(LW(2), NPC_ANIM_koopa_troopa_Palette_01_Anim_D)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_D)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(13)
            EVT_CALL(SetActorVar, -127, 8, 1)
            EVT_CALL(SetActorVar, -127, 9, 2)
            EVT_CALL(SetDefenseTable, -127, 1, EVT_ADDR(N(defenseTable_80223938)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80225968)))
            EVT_CALL(SetTargetOffset, -127, 1, -5, 15)
            EVT_CALL(func_8027D4C8, -127, 1, 0, 0)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_400, 1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
            EVT_CALL(SetActorRotationOffset, -127, 0, 12, 0)
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
            EVT_USE_BUF(EVT_ADDR(N(intTable_80226000)))
            EVT_LOOP(22)
                EVT_BUF_READ1(LW(0))
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LW(0), 0)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_F)
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_4)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6005859375))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
            EVT_CALL(GetActorVar, -127, 8, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_7)
                EVT_EXEC_WAIT(DoImmune)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
                EVT_IF_NOT_FLAG(LW(0), 0x35D000)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_8)
                    EVT_WAIT_FRAMES(10)
                EVT_END_IF
            EVT_ELSE
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_F)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(53)
            EVT_CALL(GetActorVar, -127, 8, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_4)
                EVT_EXEC_WAIT(DoReturnHome)
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetHomePos, -127, LW(0), LW(1), LW(2))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_CALL(GetActorVar, -127, 8, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_1)
                EVT_EXEC_WAIT(DoRecover)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_F)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(57)
            EVT_CALL(GetActorVar, -127, 8, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_4)
                EVT_SET_CONST(LW(2), NPC_ANIM_koopa_troopa_Palette_01_Anim_B)
                EVT_EXEC_WAIT(DoScareAway)
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_F)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(58)
            EVT_CALL(GetActorVar, -127, 8, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_17)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_F)
            EVT_END_IF
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(22)
            EVT_CALL(GetActorVar, -127, 8, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_17)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_F)
            EVT_END_IF
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(31)
            EVT_CALL(GetActorVar, -127, 8, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_1)
                EVT_EXEC_WAIT(DoImmune)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_koopa_troopa_Palette_01_Anim_F)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(takeTurn_80226BDC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_6)
    EVT_ELSE
        EVT_CALL(GetActorVar, -127, 8, LW(0))
        EVT_IF_EQ(LW(0), 1)
            EVT_CALL(GetActorVar, -127, 9, LW(0))
            EVT_SUB(LW(0), 1)
            EVT_IF_GT(LW(0), 0)
                EVT_CALL(SetActorVar, -127, 9, LW(0))
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
                EVT_CALL(SetActorSounds, -127, 2, 0, 0)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_JUMP_3E2)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_F)
                EVT_SET(LW(0), 0)
                EVT_CALL(SetActorRotationOffset, -127, 0, 12, 0)
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
                EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_1)
                EVT_CALL(SetActorVar, -127, 8, 0)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_802258D0)))
                EVT_CALL(SetDefenseTable, -127, 1, EVT_ADDR(N(defenseTable_80223900)))
                EVT_CALL(SetTargetOffset, -127, 1, -4, 32)
                EVT_CALL(func_8027D4C8, -127, 1, -1, -4)
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_400, 0)
                EVT_CALL(ResetActorSounds, -127, 2)
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(UseBattleCamPreset, 63)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_7)
        EVT_WAIT_FRAMES(10)
        EVT_CHILD_THREAD
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(1), 4)
            EVT_CALL(PlayEffect, 0x1D, 1, LW(0), LW(1), LW(2), 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(3)
            EVT_CALL(PlayEffect, 0x1D, 1, LW(0), LW(1), LW(2), 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(PlayEffect, 0x1D, 1, LW(0), LW(1), LW(2), 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_END_CHILD_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2021)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_6)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20D3)
    EVT_CALL(SetActorSounds, -127, 0, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, 16)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -40, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(GetBattlePhase, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_CALL(UseBattleCamPreset, 5)
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
            EVT_IF_EQ(LW(10), 5)
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
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_17)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_1)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetPartYaw, -127, 1, 0)
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
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 65535, 0, 1, 32)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, 2)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_koopa_troopa_Palette_01_Anim_8)
            EVT_WAIT_FRAMES(8)
            EVT_CALL(YieldTurn)
            EVT_SET_CONST(LW(0), 0x00000001)
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
