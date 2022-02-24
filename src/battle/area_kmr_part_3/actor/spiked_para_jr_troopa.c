#include "common.h"
#include "hud_element.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/jr_troopa.h"
#include "sprite/npc/spiked_para_jr_troopa.h"

#define NAMESPACE b_area_kmr_part_3_spiked_para_jr_troopa

s32 N(idleAnimations_80227F00)[] = {
    STATUS_NORMAL,    NPC_ANIM_spiked_para_jr_troopa_default_idle,
    STATUS_SLEEP,     NPC_ANIM_spiked_para_jr_troopa_default_sleep,
    STATUS_STONE,     NPC_ANIM_spiked_para_jr_troopa_default_still,
    STATUS_POISON,    NPC_ANIM_spiked_para_jr_troopa_default_still,
    STATUS_STOP,      NPC_ANIM_spiked_para_jr_troopa_default_still,
    STATUS_STATIC,    NPC_ANIM_spiked_para_jr_troopa_default_still,
    STATUS_PARALYZE,  NPC_ANIM_spiked_para_jr_troopa_default_still,
    STATUS_DIZZY,     NPC_ANIM_spiked_para_jr_troopa_default_dizzy,
    STATUS_END,
};

s32 N(idleAnimations_80227F44)[] = {
    STATUS_NORMAL,    NPC_ANIM_jr_troopa_default_idle_angry,
    STATUS_END,
};

s32 N(idleAnimations_80227F50)[] = {
    STATUS_NORMAL,    NPC_ANIM_jr_troopa_default_dead,
    STATUS_END,
};

s32 N(defenseTable_80227F5C)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(statusTable_80227F68)[] = {
    STATUS_NORMAL, 100,
    STATUS_DEFAULT, 100,
    STATUS_SLEEP, 40,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 45,
    STATUS_SHRINK, 60,
    STATUS_STOP, 70,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, -1,
    STATUS_STOP_TURN_MOD, -2,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_80228014)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 32 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80227F00),
        .defenseTable = N(defenseTable_80227F5C),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP,
        .elementImmunityFlags = 0,
        .unk_1D = 245,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80227F44),
        .defenseTable = N(defenseTable_80227F5C),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
};

extern EvtScript N(init_80228618);

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_JR_TROOPA4,
    .level = 59,
    .maxHP = 40,
    .partCount = ARRAY_COUNT(N(partsTable_80228014)),
    .partsData = N(partsTable_80228014),
    .script = &N(init_80228618),
    .statusTable = N(statusTable_80227F68),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 60, 38 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -25, 35 },
    .statusMessageOffset = { 10, 25 },
};

EvtScript N(80228084) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(2))
    EVT_IF_FLAG(LW(2), 0x35D000)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleFlags, LW(2))
    EVT_IF_FLAG(LW(2), 0x80000)
        EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
        EVT_IF_EQ(LW(2), 183)
            EVT_CALL(SetActorVar, -127, 2, 1)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x263)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(1), 30)
            EVT_CALL(ShowEmote, 0, EMOTE_QUESTION, -45, 30, 2, LW(0), LW(1), LW(2), 5)
            EVT_WAIT_FRAMES(30)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802281B4) = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20B9)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
    EVT_IF_NOT_FLAG(LW(3), 0x80000)
        EVT_ADD(LW(1), 16)
    EVT_ELSE
        EVT_ADD(LW(1), 6)
    EVT_END_IF
    EVT_CALL(PlayEffect, 0x13, 0, LW(0), LW(1), LW(2), 1, 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x13, 1, LW(0), LW(1), LW(2), 1, 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_THREAD
        EVT_SET(LW(0), 0)
        EVT_LOOP(32)
            EVT_WAIT_FRAMES(1)
            EVT_ADD(LW(0), 45)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LW(0), 0)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT_FRAMES(32)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x300)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 15)
    EVT_CALL(PlayEffect, 0x52, 4, LW(0), LW(1), LW(2), 1, 40, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 0, LW(0), LW(1), LW(2), -4, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 0, LW(0), LW(1), LW(2), -4, 4, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 0, LW(0), LW(1), LW(2), 4, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 0, LW(0), LW(1), LW(2), 4, 4, 0, 0, 0, 0, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(802284DC) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(UseBattleCamPreset, 7)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamOffsetZ, 38)
    EVT_CALL(SetBattleCamZoom, 256)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_RETURN
    EVT_END
};

EvtScript N(80228574) = {
    EVT_CALL(func_802535B4, 1)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(MoveBattleCamOver, 12)
    EVT_RETURN
    EVT_END
};

EvtScript N(802285B4) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, 55)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(takeTurn_8022936C);
extern EvtScript N(idle_802286C0);
extern EvtScript N(handleEvent_802287D0);
extern EvtScript N(nextTurn_80229B38);

EvtScript N(init_80228618) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8022936C)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_802286C0)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_802287D0)))
    EVT_CALL(BindNextTurn, -127, EVT_ADDR(N(nextTurn_80229B38)))
    EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_CALL(SetActorVar, -127, 1, 0)
    EVT_CALL(SetActorVar, -127, 2, 0)
    EVT_RETURN
    EVT_END
};

#include "common/UnkBattleFunc1.inc.c"

EvtScript N(idle_802286C0) = {
    EVT_LABEL(0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
    EVT_IF_FLAG(LW(10), 0x41000)
        EVT_CALL(SetTargetOffset, -127, 1, -15, 28)
        EVT_CALL(func_8027D4C8, -127, 1, 4, -6)
        EVT_CALL(N(UnkBattleFunc1), -25, 27, -1, 27)
    EVT_ELSE
        EVT_CALL(SetTargetOffset, -127, 1, -8, 33)
        EVT_CALL(func_8027D4C8, -127, 1, 0, -6)
        EVT_CALL(N(UnkBattleFunc1), -22, 30, 2, 28)
    EVT_END_IF
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(80228FE8);
extern EvtScript N(8022906C);
extern EvtScript N(8022A018);
extern EvtScript N(8022A39C);
extern EvtScript N(8022A480);

EvtScript N(handleEvent_802287D0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(9)
            EVT_EXEC_WAIT(N(80228FE8))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_spiked_para_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(10)
            EVT_EXEC_WAIT(N(80228FE8))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_spiked_para_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(8022906C))
            EVT_EXEC_WAIT(N(80228084))
            EVT_EXEC_WAIT(N(8022A480))
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_spiked_para_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_spiked_para_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(N(8022A018))
            EVT_RETURN
        EVT_CASE_EQ(14)
            EVT_EXEC_WAIT(N(80228FE8))
            EVT_SET(LW(0), 1)
            EVT_SET(LW(1), 2293770)
            EVT_SET(LW(2), 2293771)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8022906C))
        EVT_CASE_EQ(36)
            EVT_EXEC_WAIT(N(80228FE8))
            EVT_SET(LW(0), 1)
            EVT_SET(LW(1), 2293770)
            EVT_SET(LW(2), 2293771)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_spiked_para_jr_troopa_default_burn_dead)
            EVT_EXEC_WAIT(N(8022A018))
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_EXEC_WAIT(N(80228FE8))
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_spiked_para_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_EXEC_WAIT(N(8022906C))
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_spiked_para_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_spiked_para_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(N(8022A018))
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_spiked_para_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_spiked_para_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(8022A39C))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_idle)
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_spiked_para_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_spiked_para_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_spiked_para_jr_troopa_default_still)
            EVT_EXEC_WAIT(N(8022A018))
            EVT_RETURN
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_spiked_para_jr_troopa_default_idle)
            EVT_EXEC_WAIT(DoImmune)
            EVT_EXEC_WAIT(N(80228084))
            EVT_EXEC_WAIT(N(8022A480))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(27)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
            EVT_SWITCH(LW(3))
                EVT_CASE_FLAG(266240)
                    EVT_ADD(LW(0), -13)
                    EVT_ADD(LW(1), 37)
                EVT_CASE_FLAG(524288)
                    EVT_ADD(LW(0), -1)
                    EVT_ADD(LW(1), 14)
                EVT_CASE_DEFAULT
                    EVT_ADD(LW(0), -4)
                    EVT_ADD(LW(1), 37)
            EVT_END_SWITCH
            EVT_CALL(PlayEffect, 0x1A, 0, LW(0), LW(1), LW(2), 20, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(20)
        EVT_CASE_EQ(58)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_NOT_FLAG(LW(0), 0x35D000)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_hanging)
                EVT_WAIT_FRAMES(1000)
            EVT_END_IF
        EVT_CASE_EQ(31)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_NOT_FLAG(LW(0), 0x35D000)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_hanging)
                EVT_WAIT_FRAMES(20)
                EVT_EXEC_WAIT(N(802284DC))
                EVT_CALL(ActorSpeak, 1900955, -127, 1, 2293775, 2293775)
                EVT_EXEC_WAIT(N(80228574))
            EVT_END_IF
        EVT_CASE_EQ(42)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_hurt)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_idle)
        EVT_CASE_EQ(53)
            EVT_EXEC_WAIT(N(8022A39C))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_idle)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_spiked_para_jr_troopa_default_idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80228FE8) = {
    EVT_CALL(GetActorVar, -127, 1, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_CALL(GetLastDamage, -127, LW(1))
        EVT_IF_NE(LW(1), 0)
            EVT_CALL(SetActorVar, -127, 1, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(8022906C) = {
    EVT_CALL(GetActorVar, -127, 1, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), 0x351000)
            EVT_CALL(SetActorVar, -127, 1, 2)
            EVT_EXEC_WAIT(N(802284DC))
            EVT_CALL(ActorSpeak, 458940, -127, 1, -1, -1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_idle)
            EVT_EXEC_WAIT(N(80228574))
        EVT_ELSE
            EVT_CALL(SetActorVar, -127, 1, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80229160) = {
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
    EVT_SUB(LW(0), 10)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_idle)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_idle)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_run)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8022936C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, 63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_run)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), 0, 0, 6, 16)
    EVT_SWITCH(LW(10))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, 66)
            EVT_CALL(func_8024ECF8, -1, 1, 0)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(SetActorSounds, -127, 2, 8416, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_run)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorSounds, -127, 1, 0, 0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_SUB(LW(0), 80)
            EVT_SET(LW(1), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_attack)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_run)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, 66)
            EVT_CALL(func_8024ECF8, -1, 1, 0)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(SetActorSounds, -127, 2, 8416, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_run)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorSounds, -127, 1, 0, 0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_attack)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 6, 32)
    EVT_SET(LW(15), LW(0))
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(10)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_run)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_idle)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

ApiStatus func_802189DC_447E1C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    f32 posX = evt_get_float_variable(script, *args++);
    f32 posY = evt_get_float_variable(script, *args++);
    s32 icon = create_hud_element(HudScript_AnimatedHandPointer);

    set_hud_element_render_pos(icon, posX, posY);
    set_hud_element_scale(icon, 1.5f);
    clear_hud_element_flags(icon, HUD_ELEMENT_FLAGS_200000 | HUD_ELEMENT_FLAGS_2);
    evt_set_variable(script, *args++, icon);
    load_tattle_flags(0x8B);
    return ApiStatus_DONE2;
}

#include "common/FreeIcon.inc.c"

EvtScript N(nextTurn_80229B38) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, -127, 0, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_CALL(SetActorVar, -127, 0, 1)
                EVT_WAIT_FRAMES(15)
                EVT_CALL(UseBattleCamPreset, 14)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(SetBattleCamOffsetZ, 35)
                EVT_CALL(MoveBattleCamOver, 30)
                EVT_WAIT_FRAMES(20)
                EVT_CALL(ActorSpeak, 458936, -127, 2, 2162693, 2162693)
                EVT_WAIT_FRAMES(10)
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, 4096, 1)
                EVT_CALL(func_8026D940, -127, -20, 40)
                EVT_CALL(func_8027D2D8, -127)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_SET(LW(0), 115)
                EVT_SET(LW(1), 150)
                EVT_CALL(func_802189DC_447E1C, LW(0), LW(1), LW(10))
                EVT_WAIT_FRAMES(10)
                EVT_CALL(GetEnemyMaxHP, -127, LW(0))
                EVT_LABEL(0)
                EVT_SUB(LW(0), 1)
                EVT_CALL(SetEnemyHP, -127, LW(0))
                EVT_WAIT_FRAMES(1)
                EVT_IF_GT(LW(0), 20)
                    EVT_GOTO(0)
                EVT_END_IF
                EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jr_troopa_default_hurt_crazy)
                EVT_WAIT_FRAMES(15)
                EVT_LOOP(2)
                    EVT_CALL(SetActorFlagBits, ACTOR_SELF, 4096, 0)
                    EVT_WAIT_FRAMES(15)
                    EVT_CALL(SetActorFlagBits, ACTOR_SELF, 4096, 1)
                    EVT_WAIT_FRAMES(15)
                EVT_END_LOOP
                EVT_CALL(ActorSpeak, 458937, -127, 2, 2162707, 2162707)
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, 4096, 0)
                EVT_CALL(N(FreeIcon), LW(10))
                EVT_CALL(func_8027D32C, -127)
                EVT_CALL(func_8026D940, -127, 0, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jr_troopa_default_idle_angry)
                EVT_WAIT_FRAMES(25)
                EVT_CALL(ActorSpeak, 458938, -127, 2, 2162710, 2162691)
                EVT_WAIT_FRAMES(10)
                EVT_EXEC_WAIT(N(802281B4))
                EVT_CALL(SetPartFlagBits, -127, 2, 1, 1)
                EVT_CALL(SetPartFlagBits, -127, 1, 1, 0)
                EVT_WAIT_FRAMES(20)
                EVT_CALL(SetGoalToHome, ACTOR_SELF)
                EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 80, 0)
                EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 0)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(ForceHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(HPBarToHome, ACTOR_SELF)
                EVT_WAIT_FRAMES(10)
                EVT_CALL(ActorSpeak, 458939, -127, 1, 2293775, 2293763)
                EVT_WAIT_FRAMES(10)
                EVT_EXEC_WAIT(N(80228574))
            EVT_END_IF
        EVT_CASE_EQ(12)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022A018) = {
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_IF_EQ(LW(1), 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x301)
    EVT_CALL(SetActorSounds, -127, 2, 0, 0)
    EVT_CALL(func_8027D32C, -127)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 0, LW(2))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(FallToGoal, -127, 10)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_CALL(HPBarToCurrent, ACTOR_SELF)
    EVT_CALL(func_8027D2D8, -127)
    EVT_LABEL(0)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 10)
        EVT_ADD(LW(2), 10)
        EVT_LOOP(3)
            EVT_CALL(PlayEffect, 0x1, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetPartFlagBits, -127, 1, 1, 1)
    EVT_CALL(SetPartFlagBits, -127, 2, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jr_troopa_default_dead_still)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 5)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_WAIT_FRAMES(15)
    EVT_CALL(PlaySound, SOUND_DEATH)
    EVT_CALL(DropStarPoints, -127)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, 14)
    EVT_CALL(SetBattleCamZoom, 260)
    EVT_CALL(SetBattleCamOffsetZ, 15)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E5)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jr_troopa_default_dead)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_ADDR(N(idleAnimations_80227F50)))
    EVT_WAIT_FRAMES(60)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, 4194304, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022A39C) = {
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_spiked_para_jr_troopa_default_run)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
    EVT_SUB(LW(4), LW(1))
    EVT_MULF(LW(4), EVT_FLOAT(0.3))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, LW(4), 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022A480) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), 0x35D000)
        EVT_CALL(GetActorVar, -127, 2, LW(0))
        EVT_IF_EQ(LW(0), 1)
            EVT_CALL(SetActorVar, -127, 2, 0)
            EVT_WAIT_FRAMES(10)
            EVT_EXEC_WAIT(N(802284DC))
            EVT_CALL(ActorSpeak, 1900954, -127, 1, 2293775, 2293763)
            EVT_EXEC_WAIT(N(80228574))
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
