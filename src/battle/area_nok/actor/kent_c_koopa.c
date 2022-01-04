#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/coin.h"
#include "sprite/npc/kent_c_koopa.h"

#define NAMESPACE b_area_nok_kent_c_koopa

s32 N(intTable_80227910)[] = {
    0x00000009, 0x00000010, 0x00000016, 0x0000001A, 0x0000001E, 0x00000020, 0x00000021, 0x00000020,
    0x0000001E, 0x0000001A, 0x00000016, 0x00000010, 0x00000009, 0x00000000, 0x00000004, 0x00000006,
    0x00000007, 0x00000006, 0x00000004, 0x00000000, 0x00000002, 0x00000000,
};

s32 N(idleAnimations_80227968)[] = {
    STATUS_NORMAL,    NPC_ANIM_kent_c_koopa_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_kent_c_koopa_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_kent_c_koopa_Palette_00_Anim_13,
    STATUS_POISON,    NPC_ANIM_kent_c_koopa_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_kent_c_koopa_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_kent_c_koopa_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_kent_c_koopa_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_kent_c_koopa_Palette_00_Anim_14,
    STATUS_FEAR,      NPC_ANIM_kent_c_koopa_Palette_00_Anim_0,
    STATUS_END,
};

s32 N(idleAnimations_802279B4)[] = {
    STATUS_NORMAL,    NPC_ANIM_kent_c_koopa_Palette_00_Anim_1A,
    STATUS_STOP,      NPC_ANIM_kent_c_koopa_Palette_00_Anim_19,
    STATUS_PARALYZE,  NPC_ANIM_kent_c_koopa_Palette_00_Anim_19,
    STATUS_END,
};

s32 N(idleAnimations_802279D0)[] = {
    STATUS_NORMAL,    NPC_ANIM_coin_Palette_00_Anim_0,
    STATUS_END,
};

s32 N(defenseTable_802279DC)[] = {
    ELEMENT_NORMAL, 6,
    ELEMENT_BLAST, 6,
    ELEMENT_END,
};

s32 N(defenseTable_802279F0)[] = {
    ELEMENT_NORMAL, 3,
    ELEMENT_END,
};

s32 N(defenseTable_802279FC)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_80227A08)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 80,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 30,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 30,
    STATUS_SHRINK, 40,
    STATUS_STOP, 50,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, -1,
    STATUS_STOP_TURN_MOD, -2,
    STATUS_END,
};

ActorPartDesc N(partsTable_80227AB4)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 60 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80227968),
        .defenseTable = N(defenseTable_802279DC),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 2,
        .posOffset = { 12, 61, 0 },
        .targetOffset = { 0, -20 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_802279F0),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 3,
        .posOffset = { 45, 0, 0 },
        .targetOffset = { -70, 26 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable_802279FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802279D0),
        .defenseTable = N(defenseTable_802279FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802279D0),
        .defenseTable = N(defenseTable_802279FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802279D0),
        .defenseTable = N(defenseTable_802279FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 7,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802279D0),
        .defenseTable = N(defenseTable_802279FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 8,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802279D0),
        .defenseTable = N(defenseTable_802279FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 9,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802279D0),
        .defenseTable = N(defenseTable_802279FC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
};

extern EvtSource N(init_80227C20);

ActorDesc NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_KENT_C_KOOPA,
    .level = 55,
    .maxHP = 70,
    .partCount = ARRAY_COUNT(N(partsTable_80227AB4)),
    .partsData = N(partsTable_80227AB4),
    .script = N(init_80227C20),
    .statusTable = N(statusTable_80227A08),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 70,
    .coinReward = 0,
    .size = { 90, 70 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -26, 38 },
    .statusMessageOffset = { 2, 63 },
};

extern EvtSource N(takeTurn_80228A7C);
extern EvtSource N(idle_80227DD4);
extern EvtSource N(handleEvent_80227E08);
extern EvtSource N(nextTurn_80227D2C);

EvtSource N(init_80227C20) = {
    EVT_CALL(func_8027D434, -127, 3, 70)
    EVT_CALL(SetPartSize, -127, 3, 30, 30)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_80228A7C)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80227DD4)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80227E08)))
    EVT_CALL(BindNextTurn, -127, EVT_ADDR(N(nextTurn_80227D2C)))
    EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_CALL(SetActorVar, -127, 1, 4653084)
    EVT_CALL(SetActorVar, -127, 2, 0)
    EVT_CALL(SetActorVar, -127, 3, 20)
    EVT_CALL(SetActorVar, -127, 4, 2)
    EVT_RETURN
    EVT_END
};

EvtSource N(nextTurn_80227D2C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(10)
            EVT_CALL(SetActorVar, -127, 4, 2)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_80227DD4) = {
    EVT_LABEL(0)
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

extern EvtSource N(8022AD84);
extern EvtSource N(8022B158);
extern EvtSource N(8022B204);
extern EvtSource N(flipOver_KentC);
extern EvtSource N(shellToss_KentC);
extern EvtSource N(tackle_KentC);

EvtSource N(handleEvent_80227E08) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastElement, LW(14))
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(13))
    EVT_SWITCH(LW(13))
        EVT_CASE_EQ(56)
        EVT_CASE_EQ(9)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_CALL(GetActorVar, -127, 1, LW(1))
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_CALL(GetActorVar, -127, 1, LW(1))
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_CALL(SetActorVar, -127, 4, 2)
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_CALL(GetActorVar, -127, 1, LW(1))
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_CALL(GetActorVar, -127, 1, LW(1))
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(14)
            EVT_CALL(SetActorVar, -127, 4, 2)
            EVT_CALL(GetActorVar, -127, 0, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET(LW(0), 1)
                EVT_SET(LW(1), 4653077)
                EVT_SET(LW(2), 4653078)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_ELSE
                EVT_SET(LW(0), 1)
                EVT_SET(LW(1), 4653079)
                EVT_SET(LW(2), 4653080)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_END_IF
        EVT_CASE_EQ(36)
            EVT_CALL(GetActorVar, -127, 0, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET(LW(0), 1)
                EVT_SET(LW(1), 4653077)
                EVT_SET(LW(2), 4653078)
            EVT_ELSE
                EVT_SET(LW(0), 1)
                EVT_SET(LW(1), 4653079)
                EVT_SET(LW(2), 4653080)
            EVT_END_IF
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), LW(2))
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_CALL(SetActorVar, -127, 4, 2)
            EVT_CALL(GetActorVar, -127, 0, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_CALL(GetActorVar, -127, 1, LW(1))
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_CALL(GetActorVar, -127, 1, LW(1))
                EVT_EXEC_WAIT(N(8022B158))
            EVT_END_IF
        EVT_CASE_EQ(33)
            EVT_CALL(GetActorVar, -127, 0, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_CALL(GetActorVar, -127, 1, LW(1))
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_CALL(GetActorVar, -127, 1, LW(1))
                EVT_EXEC_WAIT(DoDeath)
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_CALL(GetActorVar, -127, 1, LW(1))
                EVT_EXEC_WAIT(N(8022B204))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_CALL(GetActorVar, -127, 1, LW(1))
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_CALL(GetActorVar, -127, 1, LW(1))
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_CALL(GetActorVar, -127, 1, LW(1))
            EVT_EXEC_WAIT(DoReturnHome)
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_CALL(GetActorVar, -127, 1, LW(1))
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_CALL(GetActorVar, -127, 1, LW(1))
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_CALL(GetActorVar, -127, 1, LW(1))
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(23)
            EVT_CALL(GetActorVar, -127, 0, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_kent_c_koopa_Palette_00_Anim_9)
                EVT_EXEC_WAIT(DoImmune)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_kent_c_koopa_Palette_00_Anim_1A)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(25)
            EVT_CALL(SetActorVar, -127, 4, 2)
            EVT_CALL(GetActorVar, -127, 0, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_kent_c_koopa_Palette_00_Anim_9)
                EVT_EXEC_WAIT(DoImmune)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(2))
                EVT_IF_EQ(LW(2), 0)
                    EVT_WAIT_FRAMES(20)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_C)
                    EVT_WAIT_FRAMES(8)
                EVT_END_IF
            EVT_ELSE
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_kent_c_koopa_Palette_00_Anim_1A)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(31)
            EVT_CALL(GetActorVar, -127, 0, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET(LW(1), 4653057)
            EVT_ELSE
                EVT_SET(LW(1), 4653082)
            EVT_END_IF
            EVT_SET(LW(0), 1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(53)
            EVT_EXEC_WAIT(N(8022AD84))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_CALL(GetActorVar, -127, 0, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(1), NPC_ANIM_kent_c_koopa_Palette_00_Anim_1)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_EXEC_WAIT(DoRecover)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_kent_c_koopa_Palette_00_Anim_1A)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(13)
            EVT_CALL(GetActorVar, -127, 0, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_SET_CONST(LW(0), 0x00000001)
                EVT_SET_CONST(LW(1), NPC_ANIM_kent_c_koopa_Palette_00_Anim_12)
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(GetActorVar, -127, 4, LW(0))
            EVT_IF_GT(LW(0), 0)
                EVT_SUB(LW(0), 1)
                EVT_CALL(SetActorVar, -127, 4, LW(0))
            EVT_END_IF
            EVT_CALL(func_80269E80, LW(0))
            EVT_IF_EQ(LW(0), 22)
                EVT_CALL(SetActorVar, -127, 4, 0)
            EVT_END_IF
            EVT_CALL(GetActorVar, -127, 4, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_CALL(GetBattleFlags, LW(13))
                EVT_IF_FLAG(LW(13), 0x20)
                    EVT_CALL(SetActorVar, -127, 4, 2)
                EVT_END_IF
                EVT_EXEC_WAIT(N(flipOver_KentC))
            EVT_ELSE
                EVT_CALL(GetBattleFlags, LW(13))
                EVT_IF_FLAG(LW(13), 0x20)
                    EVT_CALL(SetActorVar, -127, 4, 2)
                    EVT_CALL(GetLastDamage, -127, LW(0))
                    EVT_IF_GT(LW(0), 0)
                        EVT_SET_CONST(LW(0), 0x00000001)
                        EVT_SET_CONST(LW(1), NPC_ANIM_kent_c_koopa_Palette_00_Anim_1C)
                        EVT_EXEC_WAIT(DoNormalHit)
                    EVT_ELSE
                        EVT_SET_CONST(LW(0), 0x00000001)
                        EVT_SET_CONST(LW(1), NPC_ANIM_kent_c_koopa_Palette_00_Anim_9)
                        EVT_EXEC_WAIT(DoImmune)
                        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(2))
                        EVT_IF_EQ(LW(2), 0)
                            EVT_WAIT_FRAMES(20)
                            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_C)
                            EVT_WAIT_FRAMES(8)
                        EVT_END_IF
                    EVT_END_IF
                EVT_ELSE
                    EVT_SET_CONST(LW(0), 0x00000001)
                    EVT_SET_CONST(LW(1), NPC_ANIM_kent_c_koopa_Palette_00_Anim_1C)
                    EVT_EXEC_WAIT(DoNormalHit)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/StartRumbleWithParams.inc.c"

#include "common/UnkBattleFunc1.inc.c"

EvtSource N(takeTurn_80228A7C) = {
    EVT_CALL(SetActorVar, -127, 4, 2)
    EVT_CALL(GetActorVar, -127, 0, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
        EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
        EVT_CALL(UseBattleCamPreset, 14)
        EVT_CALL(SetBattleCamZoom, 200)
        EVT_CALL(SetBattleCamOffsetZ, 20)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 25)
        EVT_CALL(GetActorVar, -127, 2, LW(0))
        EVT_SUB(LW(0), 1)
        EVT_CALL(SetActorVar, -127, 2, LW(0))
        EVT_IF_GT(LW(0), 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 36)
            EVT_ADD(LW(1), 18)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(3.0))
            EVT_LOOP(5)
                EVT_CALL(PlayEffect, 0x28, 1, LW(0), LW(1), LW(2), 1, 225, 10, 0, 0, 0, 0, 0, 0)
                EVT_WAIT_FRAMES(5)
            EVT_END_LOOP
            EVT_WAIT_FRAMES(30)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 36)
            EVT_ADD(LW(1), 18)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(3.0))
            EVT_LOOP(5)
                EVT_CALL(PlayEffect, 0x28, 1, LW(0), LW(1), LW(2), 1, 225, 10, 0, 0, 0, 0, 0, 0)
                EVT_WAIT_FRAMES(5)
            EVT_END_LOOP
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(3.0))
            EVT_WAIT_FRAMES(30)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(MoveBattleCamOver, 15)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_19)
            EVT_THREAD
                EVT_WAIT_FRAMES(3)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
                EVT_IF_NOT_FLAG(LW(0), 0x80000)
                    EVT_CALL(SetActorRotationOffset, -127, 0, 27, 0)
                EVT_ELSE
                    EVT_CALL(SetActorRotationOffset, -127, 0, 10, 0)
                EVT_END_IF
                EVT_SET(LW(0), 0)
                EVT_LOOP(5)
                    EVT_ADD(LW(0), 36)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
            EVT_IF_NOT_FLAG(LW(3), 0x80000)
                EVT_CALL(N(StartRumbleWithParams), 80, 14)
                EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
            EVT_END_IF
            EVT_WAIT_FRAMES(3)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_C)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetDefenseTable, -127, 1, EVT_ADDR(N(defenseTable_802279DC)))
            EVT_CALL(SetEnemyTargetOffset, -127, 1, 0, 60)
            EVT_CALL(SetPartFlagBits, -127, 3, 131072, 1)
            EVT_CALL(SetPartFlagBits, -127, 3, 8388608, 0)
            EVT_CALL(SetPartFlags, ACTOR_SELF, 2, 131076)
            EVT_CALL(SetPartFlags, ACTOR_SELF, 1, 8388612)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80227968)))
            EVT_CALL(N(UnkBattleFunc1), -26, 38, 2, 63)
            EVT_CALL(SetActorVar, -127, 0, 0)
            EVT_CALL(SetActorVar, -127, 1, 4653084)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(RandInt, 100, LW(0))
    EVT_IF_LT(LW(0), 50)
        EVT_CALL(GetStatusFlags, ACTOR_PARTNER, LW(0))
        EVT_IF_NOT_FLAG(LW(0), 0x1000000)
            EVT_EXEC_WAIT(N(shellToss_KentC))
        EVT_ELSE
            EVT_EXEC_WAIT(N(tackle_KentC))
        EVT_END_IF
    EVT_ELSE
        EVT_EXEC_WAIT(N(tackle_KentC))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(shellToss_KentC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, 14)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(SetBattleCamOffsetZ, 20)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 25)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_B)
    EVT_WAIT_FRAMES(10)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 4)
        EVT_CALL(PlayEffect, 0x1D, 1, LW(0), LW(1), LW(2), 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_WAIT_FRAMES(3)
        EVT_CALL(PlayEffect, 0x1D, 1, LW(0), LW(1), LW(2), 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(PlayEffect, 0x1D, 1, LW(0), LW(1), LW(2), 32, 4, 0, 10, 0, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SetActorSounds, -127, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x370)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_A)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), 0, 0, 3, 16)
    EVT_SWITCH(LW(10))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(11), 0, 0, 3, 16)
            EVT_SWITCH(LW(11))
                EVT_CASE_EQ(6)
                    EVT_CALL(UseBattleCamPreset, 2)
                    EVT_CALL(MoveBattleCamOver, 30)
                    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_SUB(LW(0), 40)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
                    EVT_CALL(SetGoalPos, ACTOR_SELF, -240, 0, LW(2))
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(SetActorPos, ACTOR_SELF, 240, 0, LW(2))
                    EVT_CALL(SetGoalToHome, ACTOR_SELF)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
                    EVT_CALL(StopSound, 880)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_C)
                    EVT_WAIT_FRAMES(8)
                    EVT_CALL(YieldTurn)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_1)
                    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
                    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                    EVT_RETURN
                EVT_CASE_DEFAULT
                    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LW(0))
                    EVT_IF_NOT_FLAG(LW(0), 0x435D000)
                        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
                        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_1002B)
                    EVT_END_IF
                    EVT_CALL(UseBattleCamPreset, 19)
                    EVT_CALL(SetBattleCamTarget, -25, 60, 0)
                    EVT_CALL(SetBattleCamZoom, 460)
                    EVT_CALL(SetBattleCamOffsetZ, 0)
                    EVT_CALL(MoveBattleCamOver, 50)
                    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
                    EVT_IF_NOT_FLAG(LW(3), 0x80000)
                        EVT_ADD(LW(0), 32)
                    EVT_ELSE
                        EVT_ADD(LW(0), 12)
                    EVT_END_IF
                    EVT_SET(LW(1), 0)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_IF_EQ(LW(10), 5)
                        EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                    EVT_END_IF
                    EVT_SET(LW(10), 1)
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(UseBattleCamPreset, 19)
            EVT_CALL(SetBattleCamTarget, -25, 60, 0)
            EVT_CALL(SetBattleCamZoom, 460)
            EVT_CALL(SetBattleCamOffsetZ, 0)
            EVT_CALL(MoveBattleCamOver, 50)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
            EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LW(0))
            EVT_IF_NOT_FLAG(LW(0), 0x435D000)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_1002B)
            EVT_END_IF
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
            EVT_IF_NOT_FLAG(LW(3), 0x80000)
                EVT_ADD(LW(0), 32)
            EVT_ELSE
                EVT_ADD(LW(0), 12)
            EVT_END_IF
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(14))
            EVT_IF_NOT_FLAG(LW(14), 0x80000)
                EVT_CALL(func_80269EAC, 24)
            EVT_END_IF
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(15), 0, 65535, 0, 3, 32)
            EVT_SET(LW(10), 0)
            EVT_IF_NOT_FLAG(LW(14), 0x80000)
                EVT_CALL(GetBattleFlags, LW(0))
                EVT_IF_NOT_FLAG(LW(0), 0x80000000)
                    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LW(0))
                    EVT_IF_NOT_FLAG(LW(0), 0x100000)
                        EVT_SET(LW(10), 1)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_IF_NE(LW(10), 0)
        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), 32)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 0, LW(2))
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(func_80269EAC, 25)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 65535, 0, 3, 32)
        EVT_CALL(GetBattleFlags, LW(0))
        EVT_IF_NOT_FLAG(LW(0), 0x80000000)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, -240, 0, LW(2))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetActorPos, ACTOR_SELF, 240, 0, LW(2))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(StopSound, 880)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_C)
            EVT_WAIT_FRAMES(8)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_1)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(UseBattleCamPreset, 19)
            EVT_CALL(SetBattleCamTarget, -45, 60, 0)
            EVT_CALL(SetBattleCamZoom, 460)
            EVT_CALL(SetBattleCamOffsetZ, 0)
            EVT_CALL(MoveBattleCamOver, 30)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 30)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.80078125))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
        EVT_IF_NOT_FLAG(LW(3), 0x80000)
            EVT_CALL(N(StartRumbleWithParams), 80, 14)
            EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_ADD(LW(0), 16)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
        EVT_IF_NOT_FLAG(LW(3), 0x80000)
            EVT_CALL(N(StartRumbleWithParams), 80, 14)
            EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_ADD(LW(0), 10)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
        EVT_IF_NOT_FLAG(LW(3), 0x80000)
            EVT_CALL(N(StartRumbleWithParams), 80, 14)
            EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(StopSound, 880)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_C)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(YieldTurn)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_SET_CONST(LW(0), 0x00000001)
    EVT_SET_CONST(LW(1), NPC_ANIM_kent_c_koopa_Palette_00_Anim_4)
    EVT_EXEC_WAIT(DoReturnHome)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_1)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(tackle_KentC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, 63)
    EVT_CALL(SetBattleCamZoom, 280)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 50)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_3)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_1)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3E7)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, 16)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_6)
            EVT_THREAD
                EVT_WAIT_FRAMES(7)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_7)
                EVT_WAIT_FRAMES(4)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_8)
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 20)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20EC)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
                EVT_IF_NOT_FLAG(LW(3), 0x80000)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_SUB(LW(0), 15)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20EC)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
                EVT_IF_NOT_FLAG(LW(3), 0x80000)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_1)
            EVT_SUB(LW(0), 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20EC)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
                EVT_IF_NOT_FLAG(LW(3), 0x80000)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_WAIT_FRAMES(8)
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_SET(LW(3), 0)
            EVT_LOOP(12)
                EVT_ADD(LW(3), 15)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LW(3))
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_4)
            EVT_CALL(SetPartYaw, -127, 1, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_1)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_SET(LW(3), 180)
            EVT_LOOP(15)
                EVT_SUB(LW(3), 12)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LW(3))
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_6)
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_7)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_8)
    EVT_END_THREAD
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.30078125))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 14, FALSE, TRUE, FALSE)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(15))
    EVT_IF_NOT_FLAG(LW(15), 0x80000)
        EVT_CALL(func_80269EAC, 24)
    EVT_END_IF
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(15), 0, 65535, 0, 10, 32)
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(10)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_CALL(GetBattleFlags, LW(0))
            EVT_IF_NOT_FLAG(LW(0), 0x80000000)
                EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LW(0))
                EVT_IF_NOT_FLAG(LW(0), 0x100000)
                    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(14))
                    EVT_IF_NOT_FLAG(LW(14), 0x80000)
                        EVT_CALL(LandJump, -127)
                        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20EC)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
            EVT_THREAD
                EVT_CALL(N(StartRumbleWithParams), 80, 14)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
                EVT_IF_NOT_FLAG(LW(3), 0x80000)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT_FRAMES(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_6)
            EVT_END_THREAD
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 40)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20EC)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
                EVT_IF_NOT_FLAG(LW(3), 0x80000)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_1)
            EVT_ADD(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20EC)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
                EVT_IF_NOT_FLAG(LW(3), 0x80000)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_WAIT_FRAMES(8)
            EVT_IF_EQ(LW(15), 10)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_EXEC_WAIT(N(8022AD84))
        EVT_CASE_EQ(3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(8022AD84) = {
    EVT_SET_CONST(LW(0), 0x00000001)
    EVT_SET_CONST(LW(1), NPC_ANIM_kent_c_koopa_Palette_00_Anim_4)
    EVT_EXEC_WAIT(DoReturnHome)
    EVT_RETURN
    EVT_END
};

EvtSource N(flipOver_KentC) = {
    EVT_CALL(SetEnemyTargetOffset, -127, 1, 0, 40)
    EVT_CALL(SetDefenseTable, -127, 1, EVT_ADDR(N(defenseTable_802279F0)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_802279B4)))
    EVT_CALL(N(UnkBattleFunc1), -24, 47, 23, 37)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_1C)
    EVT_CALL(SetActorVar, -127, 0, 1)
    EVT_CALL(SetActorVar, -127, 1, 4653074)
    EVT_THREAD
        EVT_WAIT_FRAMES(4)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), 0x80000)
            EVT_CALL(SetActorRotationOffset, -127, 0, 35, 0)
        EVT_ELSE
            EVT_CALL(SetActorRotationOffset, -127, 0, 14, 0)
        EVT_END_IF
        EVT_SET(LW(0), 0)
        EVT_LOOP(5)
            EVT_SUB(LW(0), 18)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_USE_BUF(EVT_ADDR(N(intTable_80227910)))
    EVT_LOOP(22)
        EVT_BUF_READ1(LW(0))
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LW(0), 0)
        EVT_IF_EQ(LW(0), 0)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
                EVT_IF_NOT_FLAG(LW(3), 0x80000)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_1D)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_kent_c_koopa_Palette_00_Anim_1E)
    EVT_CALL(SetPartFlagBits, -127, 3, 131072, 0)
    EVT_CALL(SetPartFlagBits, -127, 3, 8388608, 1)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 2, 4)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 1, 131076)
    EVT_CALL(SetActorVar, -127, 2, 1)
    EVT_WAIT_FRAMES(8)
    EVT_RETURN
    EVT_END
};

extern EvtSource N(8022B2E8);

EvtSource N(8022B158) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_SET(LW(10), 5)
    EVT_EXEC_WAIT(N(8022B2E8))
    EVT_SET(LW(2), 0)
    EVT_LOOP(36)
        EVT_ADD(LW(2), 30)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LW(2))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(8022B204) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_SET(LW(10), 0)
    EVT_EXEC_WAIT(N(8022B2E8))
    EVT_SET(LW(2), 0)
    EVT_LOOP(48)
        EVT_ADD(LW(2), 30)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LW(2))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_WAIT_FRAMES(10)
    EVT_SET(LW(0), 1)
    EVT_SET(LW(1), -1)
    EVT_EXEC_WAIT(DoDeath)
    EVT_RETURN
    EVT_END
};

extern EvtSource N(8022B444);

EvtSource N(8022B2E8) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
    EVT_IF_FLAG(LW(3), 0x80000)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, -127, 3, LW(3))
    EVT_CALL(GetLastDamage, -127, LW(4))
    EVT_IF_GT(LW(4), LW(3))
        EVT_SET(LW(4), LW(3))
    EVT_END_IF
    EVT_IF_GT(LW(4), 6)
        EVT_SET(LW(4), 6)
    EVT_END_IF
    EVT_IF_GT(LW(4), 0)
        EVT_THREAD
            EVT_SUB(LW(3), LW(4))
            EVT_CALL(SetActorVar, -127, 3, LW(3))
            EVT_SET(LW(5), 4)
            EVT_LOOP(LW(4))
                EVT_EXEC(N(8022B444))
                EVT_ADD(LW(5), 1)
                EVT_WAIT_FRAMES(LW(10))
            EVT_END_LOOP
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

ApiStatus func_80218C74_48DE14(Evt* script, s32 isInitialCall);
INCLUDE_ASM(s32, "battle/area_nok/48DCF0", func_80218C74_48DE14);

ApiStatus func_80218DF8_48DF98(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = args++;

    evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}


EvtSource N(8022B444) = {
    EVT_CALL(PlaySoundAtPart, -127, LW(5), 530)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(6), LW(7), LW(8))
    EVT_CALL(SetPartPos, ACTOR_SELF, LW(5), LW(6), 35, LW(8))
    EVT_CALL(func_80218C74_48DE14, LW(6), LW(8), LW(0), LW(1), LW(2), LW(3))
    EVT_CALL(SetPartFlagBits, -127, LW(5), 1, 0)
    EVT_CALL(SetPartJumpGravity, -127, LW(5), EVT_FLOAT(1.0))
    EVT_CALL(JumpPartTo, -127, LW(5), LW(0), 0, LW(1), 18, 1)
    EVT_CALL(JumpPartTo, -127, LW(5), LW(2), 0, LW(3), 9, 1)
    EVT_WAIT_FRAMES(10)
    EVT_LOOP(10)
        EVT_CALL(SetPartFlagBits, -127, LW(5), 1, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetPartFlagBits, -127, LW(5), 1, 1)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtPart, -127, LW(5), 529)
    EVT_CALL(AddCoin, 1)
    EVT_RETURN
    EVT_END
};
