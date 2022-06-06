#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/jr_troopa.h"
#include "sprite/npc/spiked_para_jr_troopa.h"
#include "sprite/npc/mage_jr_troopa.h"

#define NAMESPACE b_area_kmr_part_3_final_jr_troopa

#include "common/UnkBattleFunc1.inc.c"

s32 N(idleAnimations_8022C370)[] = {
    STATUS_NORMAL,    NPC_ANIM_jr_troopa_default_idle,
    STATUS_SLEEP,     NPC_ANIM_jr_troopa_default_sleep,
    STATUS_STONE,     NPC_ANIM_jr_troopa_default_still,
    STATUS_STOP,      NPC_ANIM_jr_troopa_default_still,
    STATUS_PARALYZE,  NPC_ANIM_jr_troopa_default_still,
    STATUS_DIZZY,     NPC_ANIM_jr_troopa_default_dizzy,
    STATUS_END,
};

s32 N(idleAnimations_8022C3A4)[] = {
    STATUS_NORMAL,    NPC_ANIM_spiked_para_jr_troopa_default_idle,
    STATUS_SLEEP,     NPC_ANIM_spiked_para_jr_troopa_default_sleep,
    STATUS_STONE,     NPC_ANIM_spiked_para_jr_troopa_default_still,
    STATUS_STOP,      NPC_ANIM_spiked_para_jr_troopa_default_still,
    STATUS_PARALYZE,  NPC_ANIM_spiked_para_jr_troopa_default_still,
    STATUS_DIZZY,     NPC_ANIM_spiked_para_jr_troopa_default_dizzy,
    STATUS_END,
};

s32 N(idleAnimations_8022C3D8)[] = {
    STATUS_NORMAL,    NPC_ANIM_mage_jr_troopa_default_idle,
    STATUS_SLEEP,     NPC_ANIM_mage_jr_troopa_default_sleep,
    STATUS_STONE,     NPC_ANIM_mage_jr_troopa_default_still,
    STATUS_STOP,      NPC_ANIM_mage_jr_troopa_default_still,
    STATUS_PARALYZE,  NPC_ANIM_mage_jr_troopa_default_still,
    STATUS_DIZZY,     NPC_ANIM_mage_jr_troopa_default_dizzy,
    STATUS_END,
};

s32 N(idleAnimations_8022C40C)[] = {
    STATUS_NORMAL,    NPC_ANIM_jr_troopa_default_dead,
    STATUS_END,
};

s32 N(defenseTable_8022C418)[] = {
    ELEMENT_NORMAL, 2,
    ELEMENT_END,
};

s32 N(defenseTable_8022C424)[] = {
    ELEMENT_NORMAL, 2,
    ELEMENT_END,
};

s32 N(defenseTable_8022C430)[] = {
    ELEMENT_NORMAL, 2,
    ELEMENT_END,
};

s32 N(statusTable_8022C43C)[] = {
    STATUS_NORMAL, 100,
    STATUS_DEFAULT, 100,
    STATUS_SLEEP, 30,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 40,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 40,
    STATUS_SHRINK, 60,
    STATUS_STOP, 60,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -2,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -2,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, -1,
    STATUS_STOP_TURN_MOD, -2,
    STATUS_END,
};

s32 N(statusTable_8022C4E8)[] = {
    STATUS_NORMAL, 100,
    STATUS_DEFAULT, 100,
    STATUS_SLEEP, 30,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 40,
    STATUS_SHRINK, 50,
    STATUS_STOP, 50,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -2,
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

s32 N(statusTable_8022C594)[] = {
    STATUS_NORMAL, 100,
    STATUS_DEFAULT, 100,
    STATUS_SLEEP, 30,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 40,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 40,
    STATUS_SHRINK, 50,
    STATUS_STOP, 50,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -2,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -2,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, -1,
    STATUS_STOP_TURN_MOD, -2,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_8022C640)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 26 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8022C370),
        .defenseTable = N(defenseTable_8022C418),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0xFE,
        .unk_1D = 0xFA,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 32 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8022C3A4),
        .defenseTable = N(defenseTable_8022C424),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP,
        .elementImmunityFlags = 0,
        .unk_1D = 245,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 28 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8022C3D8),
        .defenseTable = N(defenseTable_8022C430),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0xFE,
        .unk_1D = 0xF9,
    },
};

extern EvtScript N(init_8022CF80);

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_JR_TROOPA6,
    .level = 74,
    .maxHP = 60,
    .partCount = ARRAY_COUNT(N(partsTable_8022C640)),
    .partsData = N(partsTable_8022C640),
    .script = &N(init_8022CF80),
    .statusTable = N(statusTable_8022C43C),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 70,
    .coinReward = 0,
    .size = { 24, 32 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -20, 35 },
    .statusMessageOffset = { 10, 25 },
};

EvtScript N(8022C6D4) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(2))
    EVT_IF_FLAG(LW(2), 0x35D000)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleFlags, LW(2))
    EVT_IF_FLAG(LW(2), 0x80000)
        EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
        EVT_IF_EQ(LW(2), 183)
            EVT_CALL(SetActorVar, -127, 1, 1)
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

EvtScript N(8022C804) = {
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

EvtScript N(8022CB2C) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_H)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamOffsetZ, 38)
    EVT_CALL(SetBattleCamZoom, 256)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022CBC4) = {
    EVT_CALL(func_802535B4, 1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 12)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022CC04) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_55)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

s32 N(idleAnimations_8022CC68)[] = {
    STATUS_NORMAL,    NPC_ANIM_jr_troopa_default_dead,
    STATUS_END,
};

EvtScript N(8022CC74) = {
    EVT_SET(LW(10), LW(0))
    EVT_CALL(func_8027D32C, -127)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(10), LW(1))
    EVT_WAIT_FRAMES(10)
    EVT_CALL(func_80269E80, LW(5))
    EVT_SWITCH(LW(5))
        EVT_CASE_OR_EQ(10)
        EVT_CASE_OR_EQ(14)
        EVT_CASE_OR_EQ(12)
        EVT_CASE_OR_EQ(16)
        EVT_CASE_OR_EQ(11)
        EVT_CASE_OR_EQ(15)
        EVT_CASE_OR_EQ(13)
        EVT_CASE_OR_EQ(17)
        EVT_CASE_OR_EQ(2)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET(LW(2), 0)
            EVT_LOOP(24)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LW(2))
                EVT_ADD(LW(2), 30)
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_END_SWITCH
    EVT_LABEL(0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 10)
    EVT_ADD(LW(2), 10)
    EVT_CALL(PlayEffect, 0x1, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySound, SOUND_DEATH)
    EVT_CALL(DropStarPoints, -127)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(SetBattleCamZoom, 260)
    EVT_CALL(SetBattleCamOffsetZ, 15)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E5)
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(10), 0x210027)
    EVT_WAIT_FRAMES(12)
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(10), 0x210014)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, LW(10), EVT_ADDR(N(idleAnimations_8022CC68)))
    EVT_WAIT_FRAMES(60)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, 1)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(takeTurn_8022D920);
extern EvtScript N(idle_8022D058);
extern EvtScript N(handleEvent_8022D1C4);
extern EvtScript N(nextTurn_8023147C);

EvtScript N(init_8022CF80) = {
    EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_CALL(SetActorVar, -127, 2, 0)
    EVT_CALL(SetActorVar, -127, 1, 0)
    EVT_CALL(SetActorVar, -127, 3, 1)
    EVT_CALL(SetActorVar, -127, 4, 5)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8022D920)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8022D058)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8022D1C4)))
    EVT_CALL(BindNextTurn, -127, EVT_ADDR(N(nextTurn_8023147C)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8022D058) = {
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, -127, 3, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
            EVT_IF_FLAG(LW(10), 0x41000)
                EVT_CALL(SetTargetOffset, -127, 2, -15, 28)
                EVT_CALL(func_8027D4C8, -127, 2, 4, -6)
                EVT_CALL(N(UnkBattleFunc1), -25, 27, -1, 27)
            EVT_ELSE
                EVT_CALL(SetTargetOffset, -127, 2, -8, 33)
                EVT_CALL(func_8027D4C8, -127, 2, 0, -6)
                EVT_CALL(N(UnkBattleFunc1), -22, 30, 2, 28)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(N(UnkBattleFunc1), -20, 35, 10, 25)
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(802315F0);
extern EvtScript N(802318F8);
extern EvtScript N(80232040);
extern EvtScript N(80232170);

EvtScript N(handleEvent_8022D1C4) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(10))
    EVT_SWITCH(LW(10))
        EVT_CASE_EQ(9)
            EVT_SET(LW(1), 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(10)
            EVT_SET(LW(1), 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(8022C6D4))
            EVT_EXEC_WAIT(N(80232170))
        EVT_CASE_EQ(32)
            EVT_SET(LW(1), 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_EXEC_WAIT(N(802318F8))
            EVT_RETURN
        EVT_CASE_EQ(14)
            EVT_SET(LW(1), 1)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET(LW(1), 1)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_WAIT_FRAMES(10)
            EVT_EXEC_WAIT(N(802318F8))
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET(LW(1), 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_SET(LW(1), 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_EXEC_WAIT(N(802318F8))
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_CALL(SetPartRotation, -127, 2, 0, 0, 0)
            EVT_CALL(SetPartRotationOffset, -127, 2, 0, 0, 0)
            EVT_SET(LW(1), 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET(LW(1), 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(80232040))
        EVT_CASE_EQ(38)
            EVT_CALL(SetPartRotation, -127, 2, 0, 0, 0)
            EVT_CALL(SetPartRotationOffset, -127, 2, 0, 0, 0)
            EVT_SET(LW(1), 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET(LW(1), 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(802318F8))
            EVT_RETURN
        EVT_CASE_EQ(23)
            EVT_SET(LW(1), 5)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(25)
            EVT_SET(LW(1), 5)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(DoImmune)
            EVT_EXEC_WAIT(N(8022C6D4))
            EVT_EXEC_WAIT(N(80232170))
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
                EVT_SET(LW(1), 2)
                EVT_EXEC_WAIT(N(802315F0))
                EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
                EVT_WAIT_FRAMES(1000)
            EVT_END_IF
        EVT_CASE_EQ(31)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_NOT_FLAG(LW(0), 0x35D000)
                EVT_SET(LW(1), 5)
                EVT_EXEC_WAIT(N(802315F0))
                EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
                EVT_WAIT_FRAMES(20)
                EVT_EXEC_WAIT(N(8022CB2C))
                EVT_SET(LW(1), 3)
                EVT_EXEC_WAIT(N(802315F0))
                EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
                EVT_CALL(ActorSpeak, 1900955, -127, LW(0), -1, -1)
                EVT_EXEC_WAIT(N(8022CBC4))
            EVT_END_IF
        EVT_CASE_EQ(42)
            EVT_SET(LW(1), 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(53)
            EVT_EXEC_WAIT(N(80232040))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_jr_troopa_default_idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(8022DD48);
extern EvtScript N(8022DF54);
extern EvtScript N(8022ED10);
extern EvtScript N(8022F468);
extern EvtScript N(80230034);
extern EvtScript N(80230794);
extern EvtScript N(8023106C);
extern EvtScript N(8022E198);

EvtScript N(takeTurn_8022D920) = {
    EVT_CALL(GetActorVar, -127, 3, LW(0))
    EVT_IF_NE(LW(0), 3)
        EVT_CALL(GetActorHP, -127, LW(1))
        EVT_CALL(GetEnemyMaxHP, -127, LW(2))
        EVT_MUL(LW(1), 100)
        EVT_DIV(LW(1), LW(2))
        EVT_IF_EQ(LW(0), 1)
            EVT_IF_LT(LW(1), 65)
                EVT_EXEC_WAIT(N(8022DD48))
            EVT_END_IF
        EVT_ELSE
            EVT_IF_LT(LW(1), 35)
                EVT_EXEC_WAIT(N(8022DF54))
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorHP, -127, LW(0))
    EVT_IF_LT(LW(0), 15)
        EVT_CALL(GetActorVar, -127, 2, LW(0))
        EVT_IF_NOT_FLAG(LW(0), 0x2)
            EVT_BITWISE_OR_CONST(LW(0), 0x2)
            EVT_CALL(SetActorVar, -127, 2, LW(0))
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(GetActorVar, -127, 3, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(2)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_spiked_para_jr_troopa_default_talk_point)
                EVT_CASE_EQ(3)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_mage_jr_troopa_default_talk_point)
                EVT_CASE_DEFAULT
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_talk)
            EVT_END_SWITCH
            EVT_CALL(ActorSpeak, 1245280, -127, 1, -1, -1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, -127, 3, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(2)
            EVT_CALL(RandInt, 100, LW(0))
            EVT_IF_LT(LW(0), 50)
                EVT_EXEC_WAIT(N(8022ED10))
            EVT_ELSE
                EVT_EXEC_WAIT(N(8022F468))
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_CALL(RandInt, 100, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_LT(60)
                    EVT_EXEC_WAIT(N(80230034))
                EVT_CASE_LT(80)
                    EVT_EXEC_WAIT(N(80230794))
                EVT_CASE_DEFAULT
                    EVT_CALL(GetActorHP, -127, LW(0))
                    EVT_CALL(GetEnemyMaxHP, -127, LW(1))
                    EVT_IF_NE(LW(0), LW(1))
                        EVT_CALL(GetActorVar, -127, 4, LW(2))
                        EVT_IF_GT(LW(2), 0)
                            EVT_SUB(LW(2), 1)
                            EVT_CALL(SetActorVar, -127, 4, LW(2))
                            EVT_EXEC_WAIT(N(8023106C))
                        EVT_ELSE
                            EVT_EXEC_WAIT(N(80230034))
                        EVT_END_IF
                    EVT_ELSE
                        EVT_EXEC_WAIT(N(80230034))
                    EVT_END_IF
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(N(8022E198))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8022DD48) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(ActorSpeak, 1245278, -127, 1, 2162712, 2162712)
    EVT_EXEC_WAIT(N(8022C804))
    EVT_CALL(SetPartFlagBits, -127, 1, 131073, 1)
    EVT_CALL(SetPartFlagBits, -127, 1, 8388608, 0)
    EVT_CALL(SetPartFlagBits, -127, 2, 131073, 0)
    EVT_CALL(SetPartFlagBits, -127, 2, 8388608, 1)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 60, 0)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(ForceHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetActorVar, -127, 3, 2)
    EVT_CALL(SetStatusTable, -127, EVT_ADDR(N(statusTable_8022C4E8)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022DF54) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(ActorSpeak, 1245279, -127, 2, 2293775, 2293775)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 120)
    EVT_EXEC_WAIT(N(8022C804))
    EVT_CALL(SetPartFlagBits, -127, 2, 131073, 1)
    EVT_CALL(SetPartFlagBits, -127, 2, 8388608, 0)
    EVT_CALL(SetPartFlagBits, -127, 3, 131073, 0)
    EVT_CALL(SetPartFlagBits, -127, 3, 8388608, 1)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 20)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(FallToGoal, -127, 10)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(ForceHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetActorVar, -127, 3, 3)
    EVT_CALL(SetStatusTable, -127, EVT_ADDR(N(statusTable_8022C594)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022E198) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_run)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SET(LW(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 0, LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(15), 0, 0, 8, 16)
    EVT_SWITCH(LW(15))
        EVT_CASE_EQ(5)
            EVT_THREAD
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_sprint_normal)
                EVT_WAIT_FRAMES(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_swim)
            EVT_END_THREAD
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_trip)
            EVT_THREAD
                EVT_WAIT_FRAMES(3)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_dead)
            EVT_END_THREAD
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 16, 0, 5)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_sprint_crazy)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(6)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_run)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 50)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 0, LW(2))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetActorSounds, -127, 2, 8418, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_jump)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_jump_still)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 10)
            EVT_SET(LW(1), 0)
            EVT_ADD(LW(2), 3)
            EVT_THREAD
                EVT_WAIT_FRAMES(8)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_jump_land)
            EVT_END_THREAD
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_panick)
            EVT_SUB(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_SUB(LW(0), 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_run)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_idle)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_run)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 50)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 0, LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetActorSounds, -127, 2, 8418, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_jump)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_jump_still)
    EVT_THREAD
        EVT_WAIT_FRAMES(8)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_jump_land)
    EVT_END_THREAD
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(15), 0, 0, 0, 8, 32)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
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
    EVT_SUB(LW(0), 10)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_idle)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_run)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_idle)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022ED10) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_spiked_para_jr_troopa_default_run)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), 0, 0, 6, 16)
    EVT_SWITCH(LW(10))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
            EVT_CALL(func_8024ECF8, -1, 1, 0)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(SetActorSounds, -127, 2, 8416, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_spiked_para_jr_troopa_default_run)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_spiked_para_jr_troopa_default_attack)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_spiked_para_jr_troopa_default_run)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_spiked_para_jr_troopa_default_idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetActorSounds, -127, 2, 8416, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_spiked_para_jr_troopa_default_run)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorSounds, -127, 1, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_spiked_para_jr_troopa_default_attack)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 8, 32)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_spiked_para_jr_troopa_default_run)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(YieldTurn)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_spiked_para_jr_troopa_default_run)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_spiked_para_jr_troopa_default_idle)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

ApiStatus N(CalculateRotationZ)(Evt* script, s32 isInitialCall);

EvtScript N(8022F468) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CLOSE_SHELL)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_spiked_para_jr_troopa_default_shell_hide)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_spiked_para_jr_troopa_default_idle_shell)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
    EVT_CALL(SetActorSounds, -127, 2, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(15), 0, 0, 6, 16)
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_THREAD
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
                EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_SUB(LW(0), 10)
                EVT_SET(LW(1), 12)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_END_THREAD
            EVT_SET(LW(0), 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(1), LW(2), LW(3))
            EVT_LOOP(20)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(4), LW(5), LW(6))
                EVT_CALL(N(CalculateRotationZ), LW(1), LW(2), LW(4), LW(5), LW(0))
                EVT_CALL(SetPartRotation, -127, 2, 0, 0, LW(0))
                EVT_SET(LW(1), LW(4))
                EVT_SET(LW(2), LW(5))
                EVT_SET(LW(3), LW(6))
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_IF_EQ(LW(15), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(15), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(1), LW(2), LW(3))
                EVT_SUB(LW(1), 40)
                EVT_SET(LW(2), 10)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LW(1), LW(2), LW(3))
                EVT_CALL(JumpToGoal, ACTOR_SELF, 14, FALSE, TRUE, FALSE)
            EVT_END_THREAD
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(1), LW(2), LW(3))
            EVT_LOOP(14)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(4), LW(5), LW(6))
                EVT_CALL(N(CalculateRotationZ), LW(1), LW(2), LW(4), LW(5), LW(0))
                EVT_SET(LW(7), LW(0))
                EVT_ADD(LW(7), 180)
                EVT_CALL(SetPartRotation, -127, 2, 0, 0, LW(7))
                EVT_SET(LW(1), LW(4))
                EVT_SET(LW(2), LW(5))
                EVT_SET(LW(3), LW(6))
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetPartRotation, -127, 2, 0, 0, 0)
            EVT_CALL(SetPartRotationOffset, -127, 2, 0, 0, 0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_OPEN_SHELL)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_spiked_para_jr_troopa_default_shell_show)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_spiked_para_jr_troopa_default_run)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 2, 0, 2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -5, 0)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 2, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(SetPartRotationOffset, -127, 2, 0, 12, 0)
    EVT_THREAD
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_SET(LW(0), 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(1), LW(2), LW(3))
    EVT_LOOP(20)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(4), LW(5), LW(6))
        EVT_CALL(N(CalculateRotationZ), LW(1), LW(2), LW(4), LW(5), LW(0))
        EVT_CALL(SetPartRotation, -127, 2, 0, 0, LW(0))
        EVT_SET(LW(1), LW(4))
        EVT_SET(LW(2), LW(5))
        EVT_SET(LW(3), LW(6))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(15), 0, 0, 0, 9, 32)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(1), LW(2), LW(3))
        EVT_ADD(LW(1), 40)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(1), LW(2), LW(3))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 14, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(1), LW(2), LW(3))
    EVT_LOOP(14)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(4), LW(5), LW(6))
        EVT_CALL(N(CalculateRotationZ), LW(1), LW(2), LW(4), LW(5), LW(0))
        EVT_SET(LW(7), LW(0))
        EVT_ADD(LW(7), 180)
        EVT_CALL(SetPartRotation, -127, 2, 0, 0, LW(7))
        EVT_SET(LW(1), LW(4))
        EVT_SET(LW(2), LW(5))
        EVT_SET(LW(3), LW(6))
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetPartRotation, -127, 2, 0, 0, 0)
    EVT_CALL(SetPartRotationOffset, -127, 2, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_OPEN_SHELL)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_spiked_para_jr_troopa_default_shell_show)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_spiked_para_jr_troopa_default_run)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -5, 0)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/anglestuff.inc.c"

EvtScript N(80230034) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_mage_jr_troopa_default_attack)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), 0x80000)
        EVT_SET(LW(3), 0)
        EVT_SET(LW(4), 36)
        EVT_SETF(LW(5), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_SET(LW(3), 0)
        EVT_SET(LW(4), 14)
        EVT_SETF(LW(5), GF(-1999590))
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), LW(3))
    EVT_ADD(LW(1), LW(4))
    EVT_CALL(PlayEffect, 0x13, 0, LW(0), LW(1), LW(2), LW(5), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_mage_jr_troopa_default_attack2)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), DAMAGE_TYPE_NO_CONTACT, 0, 1, 16)
    EVT_SWITCH(LW(10))
        EVT_CASE_EQ(6)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(3), LW(4), LW(5))
            EVT_SUB(LW(3), 120)
            EVT_ADD(LW(4), 20)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_NOT_FLAG(LW(0), 0x80000)
                EVT_SET(LW(6), -8)
                EVT_SET(LW(7), 20)
                EVT_SETF(LW(8), EVT_FLOAT(1.0))
            EVT_ELSE
                EVT_SET(LW(6), -3)
                EVT_SET(LW(7), 8)
                EVT_SETF(LW(8), GF(-1999590))
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), LW(6))
            EVT_ADD(LW(1), LW(7))
            EVT_CALL(PlayEffect, 0x12, 0, LW(0), LW(1), LW(2), LW(3), LW(4), LW(5), 30, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(35)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(5)
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_ADD(LW(1), 12)
                EVT_CALL(PlayEffect, 0x3E, 0, LW(0), LW(1), LW(2), EVT_FLOAT(3.0), 30, 0, 0, 0, 0, 0, 0, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_mage_jr_troopa_default_attack2_burn)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_WAIT_FRAMES(40)
                EVT_SUB(LW(0), 7)
                EVT_ADD(LW(1), 14)
                EVT_ADD(LW(2), 4)
                EVT_CALL(PlayEffect, 0x7, 2, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
                EVT_WAIT_FRAMES(20)
                EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_mage_jr_troopa_default_idle)
            EVT_END_THREAD
            EVT_WAIT_FRAMES(20)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_WAIT_FRAMES(40)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(3), LW(4), LW(5))
    EVT_ADD(LW(4), 20)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), 0x80000)
        EVT_SET(LW(6), -8)
        EVT_SET(LW(7), 20)
        EVT_SETF(LW(8), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_SET(LW(6), -3)
        EVT_SET(LW(7), 8)
        EVT_SETF(LW(8), GF(-1999590))
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), LW(6))
    EVT_ADD(LW(1), LW(7))
    EVT_CALL(PlayEffect, 0x12, 0, LW(0), LW(1), LW(2), LW(3), LW(4), LW(5), 15, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), (DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT), 0, 0, 8, 32)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/Dist3D.inc.c" // Not used?

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"

EvtScript N(80230794) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_mage_jr_troopa_default_attack)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), 0x80000)
        EVT_SET(LW(3), 0)
        EVT_SET(LW(4), 36)
        EVT_SETF(LW(5), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_SET(LW(3), 0)
        EVT_SET(LW(4), 14)
        EVT_SETF(LW(5), GF(-1999590))
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), LW(3))
    EVT_ADD(LW(1), LW(4))
    EVT_CALL(PlayEffect, 0x13, 0, LW(0), LW(1), LW(2), LW(5), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BIG_POWER_UP)
    EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_mage_jr_troopa_default_attack2)
    EVT_CALL(N(UnkBackgroundFunc3))
    EVT_CALL(MakeLerp, 0, 200, 60, 10)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(N(SetBackgroundAlpha), LW(0))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(LW(1), 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_CALL(RandInt, 40, LW(1))
    EVT_ADD(LW(0), LW(1))
    EVT_ADD(LW(0), 50)
    EVT_SET(LW(1), 200)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_366)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), DAMAGE_TYPE_NO_CONTACT, 0, 1, 16)
    EVT_SWITCH(LW(10))
        EVT_CASE_EQ(6)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(3), 0, LW(5))
            EVT_CALL(PlayEffect, 0x5E, 0, LW(0), LW(1), LW(2), LW(3), LW(4), LW(5), EVT_FLOAT(1.0), 18, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(MakeLerp, 200, 0, 60, 0)
            EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(SetBackgroundAlpha), LW(0))
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(LW(1), 1)
                EVT_GOTO(2)
            EVT_END_IF
            EVT_WAIT_FRAMES(20)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(5)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(RandInt, 40, LW(1))
            EVT_SUB(LW(0), LW(1))
            EVT_SET(LW(1), 200)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
            EVT_CALL(PlayEffect, 0x5E, 0, LW(0), LW(1), LW(2), LW(3), 0, LW(5), EVT_FLOAT(1.0), 18, 0, 0, 0, 0)
            EVT_THREAD
                EVT_WAIT_FRAMES(10)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_ADD(LW(1), 12)
                EVT_CALL(PlayEffect, 0x3E, 0, LW(0), LW(1), LW(2), EVT_FLOAT(3.0), 30, 0, 0, 0, 0, 0, 0, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_mage_jr_troopa_default_attack2_burn)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_WAIT_FRAMES(40)
                EVT_SUB(LW(0), 7)
                EVT_ADD(LW(1), 14)
                EVT_ADD(LW(2), 4)
                EVT_CALL(PlayEffect, 0x7, 2, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
                EVT_WAIT_FRAMES(20)
                EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_mage_jr_troopa_default_idle)
            EVT_END_THREAD
            EVT_WAIT_FRAMES(20)
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(MakeLerp, 200, 0, 60, 0)
            EVT_LABEL(2)
            EVT_CALL(UpdateLerp)
            EVT_CALL(N(SetBackgroundAlpha), LW(0))
            EVT_WAIT_FRAMES(1)
            EVT_IF_EQ(LW(1), 1)
                EVT_GOTO(2)
            EVT_END_IF
            EVT_WAIT_FRAMES(20)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(3), 0, LW(5))
    EVT_CALL(PlayEffect, 0x5E, 0, LW(0), LW(1), LW(2), LW(3), LW(4), LW(5), EVT_FLOAT(1.0), 18, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(14)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), (DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_ELECTRIC | DAMAGE_TYPE_NO_CONTACT), 0, 65536, 9, 32)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MakeLerp, 200, 0, 60, 0)
    EVT_LABEL(2)
    EVT_CALL(UpdateLerp)
    EVT_CALL(N(SetBackgroundAlpha), LW(0))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(LW(1), 1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_WAIT_FRAMES(20)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8023106C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_mage_jr_troopa_default_attack)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_NOT_FLAG(LW(0), 0x80000)
        EVT_SET(LW(3), 0)
        EVT_SET(LW(4), 36)
        EVT_SETF(LW(5), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_SET(LW(3), 0)
        EVT_SET(LW(4), 14)
        EVT_SETF(LW(5), GF(-1999590))
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), LW(3))
    EVT_ADD(LW(1), LW(4))
    EVT_CALL(PlayEffect, 0x13, 0, LW(0), LW(1), LW(2), LW(5), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2F8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x214)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(1), LW(2), LW(3))
    EVT_ADD(LW(2), 50)
    EVT_CALL(PlayEffect, 0x11, 1, LW(1), LW(2), LW(3), 10, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x40, 2, LW(1), LW(2), LW(3), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_mage_jr_troopa_default_idle)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(GetEnemyMaxHP, -127, LW(0))
    EVT_MUL(LW(0), 17)
    EVT_DIV(LW(0), 100)
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x206D)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x214)
        EVT_WAIT_FRAMES(30)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_25C)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(func_8026BF48, 1)
        EVT_CALL(HealActor, -127, LW(0), 0)
        EVT_CALL(func_8026BF48, 0)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(30)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_8023147C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, -127, 2, LW(0))
            EVT_IF_NOT_FLAG(LW(0), 0x1)
                EVT_BITWISE_OR_CONST(LW(0), 0x1)
                EVT_CALL(SetActorVar, -127, 2, LW(0))
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_CALL(ActorSpeak, 1245277, -127, 1, 2162714, 2162714)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_idle)
            EVT_END_IF
        EVT_CASE_EQ(12)
        EVT_CASE_EQ(11)
        EVT_CASE_EQ(10)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(802315F0) = {
    EVT_CALL(GetActorVar, -127, 3, LW(0))
    EVT_SWITCH(LW(1))
        EVT_CASE_EQ(0)
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(2)
                    EVT_SET(LW(1), 2293769)
                EVT_CASE_EQ(3)
                    EVT_SET(LW(1), 2359305)
                EVT_CASE_DEFAULT
                    EVT_SET(LW(1), 2162705)
            EVT_END_SWITCH
        EVT_CASE_EQ(1)
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(2)
                    EVT_SET(LW(1), 2293770)
                    EVT_SET(LW(2), 2293771)
                EVT_CASE_EQ(3)
                    EVT_SET(LW(1), 2359306)
                    EVT_SET(LW(2), 2359307)
                EVT_CASE_DEFAULT
                    EVT_SET(LW(1), 2162728)
                    EVT_SET(LW(2), 2162729)
            EVT_END_SWITCH
        EVT_CASE_EQ(2)
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(2)
                    EVT_SET(LW(1), 2293776)
                EVT_CASE_EQ(3)
                    EVT_SET(LW(1), 2359311)
                EVT_CASE_DEFAULT
                    EVT_SET(LW(1), 2162730)
            EVT_END_SWITCH
        EVT_CASE_EQ(3)
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(2)
                    EVT_SET(LW(1), 2293775)
                EVT_CASE_EQ(3)
                    EVT_SET(LW(1), 2359310)
                EVT_CASE_DEFAULT
                    EVT_SET(LW(1), 2162710)
            EVT_END_SWITCH
        EVT_CASE_EQ(4)
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(2)
                    EVT_SET(LW(1), 2293767)
                EVT_CASE_EQ(3)
                    EVT_SET(LW(1), 2359301)
                EVT_CASE_DEFAULT
                    EVT_SET(LW(1), 2162697)
            EVT_END_SWITCH
        EVT_CASE_DEFAULT
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(2)
                    EVT_SET(LW(1), 2293763)
                EVT_CASE_EQ(3)
                    EVT_SET(LW(1), 2359298)
                EVT_CASE_DEFAULT
                    EVT_SET(LW(1), 2162691)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(802318F8) = {
    EVT_CALL(GetActorVar, -127, 3, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(2)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_IF_EQ(LW(1), 0)
                EVT_GOTO(0)
            EVT_END_IF
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x301)
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
            EVT_CALL(SetPartFlagBits, -127, 2, 1, 1)
            EVT_CALL(SetPartFlagBits, -127, 1, 1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_dead_still)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 5)
            EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_WAIT_FRAMES(15)
            EVT_CALL(PlaySound, SOUND_DEATH)
            EVT_CALL(DropStarPoints, -127)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
            EVT_CALL(SetBattleCamZoom, 260)
            EVT_CALL(SetBattleCamOffsetZ, 15)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_dead)
            EVT_WAIT_FRAMES(60)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, 1)
            EVT_RETURN
        EVT_CASE_EQ(3)
            EVT_CALL(func_8027D32C, -127)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
            EVT_CALL(func_80269E80, LW(5))
            EVT_SWITCH(LW(5))
                EVT_CASE_OR_EQ(10)
                EVT_CASE_OR_EQ(14)
                EVT_CASE_OR_EQ(12)
                EVT_CASE_OR_EQ(16)
                EVT_CASE_OR_EQ(11)
                EVT_CASE_OR_EQ(15)
                EVT_CASE_OR_EQ(13)
                EVT_CASE_OR_EQ(17)
                EVT_CASE_OR_EQ(2)
                EVT_END_CASE_GROUP
                EVT_CASE_DEFAULT
                    EVT_SET(LW(2), 0)
                    EVT_LOOP(24)
                        EVT_CALL(SetActorYaw, ACTOR_SELF, LW(2))
                        EVT_ADD(LW(2), 30)
                        EVT_WAIT_FRAMES(1)
                    EVT_END_LOOP
                    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_END_SWITCH
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_ADD(LW(1), 10)
                EVT_ADD(LW(2), 10)
                EVT_LOOP(3)
                    EVT_CALL(PlayEffect, 0x1, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
                    EVT_WAIT_FRAMES(3)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetPartFlagBits, -127, 3, 1, 1)
            EVT_CALL(SetPartFlagBits, -127, 1, 1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_dead_still)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 5)
            EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_WAIT_FRAMES(15)
            EVT_CALL(PlaySound, SOUND_DEATH)
            EVT_CALL(DropStarPoints, -127)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
            EVT_CALL(SetBattleCamZoom, 260)
            EVT_CALL(SetBattleCamOffsetZ, 15)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_dead)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022C40C)))
            EVT_WAIT_FRAMES(60)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, 1)
            EVT_RETURN
        EVT_CASE_DEFAULT
            EVT_SET(LW(1), 0)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(N(8022CC74))
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80232040) = {
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(GetActorVar, -127, 3, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(2)
            EVT_SET(LW(1), 4)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -5, 0)
        EVT_CASE_EQ(3)
            EVT_SET(LW(1), 4)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(DoReturnHome)
        EVT_CASE_DEFAULT
            EVT_SET(LW(1), 4)
            EVT_EXEC_WAIT(N(802315F0))
            EVT_EXEC_WAIT(DoReturnHome)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80232170) = {
    EVT_CALL(GetActorVar, -127, 1, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_WAIT_FRAMES(10)
        EVT_EXEC_WAIT(N(8022CB2C))
        EVT_CALL(GetActorVar, -127, 3, LW(0))
        EVT_SWITCH(LW(0))
            EVT_CASE_EQ(2)
                EVT_CALL(ActorSpeak, 1900954, -127, 2, 2293775, 2293763)
            EVT_CASE_EQ(3)
                EVT_CALL(ActorSpeak, 1900954, -127, 3, 2359310, 2359299)
            EVT_CASE_DEFAULT
                EVT_CALL(ActorSpeak, 1900954, -127, 1, 2162710, 2162691)
        EVT_END_SWITCH
        EVT_CALL(GetActorVar, -127, 0, LW(0))
        EVT_IF_NE(LW(0), 1)
            EVT_EXEC_WAIT(N(8022CBC4))
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SetActorVar, -127, 1, 0)
    EVT_RETURN
    EVT_END
};
