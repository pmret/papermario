#include "common.h"
#include "hud_element.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/jr_troopa.h"
#include "sprite/npc/mage_jr_troopa.h"

#define NAMESPACE b_area_kmr_part_3_mage_jr_troopa

s32 N(idleAnimations_8022A550)[] = {
    STATUS_NORMAL,    NPC_ANIM_mage_jr_troopa_default_idle,
    STATUS_SLEEP,     NPC_ANIM_mage_jr_troopa_default_sleep,
    STATUS_STONE,     NPC_ANIM_mage_jr_troopa_default_still,
    STATUS_POISON,    NPC_ANIM_mage_jr_troopa_default_still,
    STATUS_STOP,      NPC_ANIM_mage_jr_troopa_default_still,
    STATUS_STATIC,    NPC_ANIM_mage_jr_troopa_default_still,
    STATUS_PARALYZE,  NPC_ANIM_mage_jr_troopa_default_still,
    STATUS_DIZZY,     NPC_ANIM_mage_jr_troopa_default_dizzy,
    STATUS_END,
};

s32 N(idleAnimations_8022A594)[] = {
    STATUS_NORMAL,   NPC_ANIM_mage_jr_troopa_default_idle,
    STATUS_SLEEP,    NPC_ANIM_mage_jr_troopa_default_still,
    STATUS_STONE,    NPC_ANIM_mage_jr_troopa_default_still,
    STATUS_POISON,   NPC_ANIM_mage_jr_troopa_default_still,
    STATUS_STOP,     NPC_ANIM_mage_jr_troopa_default_still,
    STATUS_STATIC,   NPC_ANIM_mage_jr_troopa_default_still,
    STATUS_PARALYZE, NPC_ANIM_mage_jr_troopa_default_still,
    STATUS_DIZZY,    NPC_ANIM_mage_jr_troopa_default_dizzy,
    STATUS_END,
};

s32 N(idleAnimations_8022A5D8)[] = {
    STATUS_NORMAL,    NPC_ANIM_jr_troopa_default_idle,
    STATUS_SLEEP,     NPC_ANIM_jr_troopa_default_sleep,
    STATUS_STONE,     NPC_ANIM_jr_troopa_default_still,
    STATUS_POISON,    NPC_ANIM_jr_troopa_default_still,
    STATUS_STOP,      NPC_ANIM_jr_troopa_default_still,
    STATUS_STATIC,    NPC_ANIM_jr_troopa_default_still,
    STATUS_PARALYZE,  NPC_ANIM_jr_troopa_default_still,
    STATUS_DIZZY,     NPC_ANIM_jr_troopa_default_dizzy,
    STATUS_END,
};

s32 N(idleAnimations_8022A61C)[] = {
    STATUS_NORMAL,    NPC_ANIM_jr_troopa_default_dead,
    STATUS_END,
};

s32 N(defenseTable_8022A628)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(statusTable_8022A634)[] = {
    STATUS_NORMAL, 100,
    STATUS_DEFAULT, 100,
    STATUS_SLEEP, 35,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 45,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 45,
    STATUS_SHRINK, 60,
    STATUS_STOP, 60,
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

ActorPartBlueprint N(partsTable_8022A6E0)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 28 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8022A550),
        .defenseTable = N(defenseTable_8022A628),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0xFE,
        .unk_1D = 0xF9,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8022A5D8),
        .defenseTable = N(defenseTable_8022A628),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
};

extern EvtScript N(init_8022ACE4);

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_JR_TROOPA5,
    .level = 65,
    .maxHP = 50,
    .partCount = ARRAY_COUNT(N(partsTable_8022A6E0)),
    .partsData = N(partsTable_8022A6E0),
    .script = &N(init_8022ACE4),
    .statusTable = N(statusTable_8022A634),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 24, 32 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -20, 35 },
    .statusMessageOffset = { 10, 25 },
};

EvtScript N(8022A750) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(2))
    EVT_IF_FLAG(LocalVar(2), 0x35D000)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleFlags, LocalVar(2))
    EVT_IF_FLAG(LocalVar(2), 0x80000)
        EVT_CALL(GetMenuSelection, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_IF_EQ(LocalVar(2), 183)
            EVT_CALL(SetActorVar, -127, 3, 1)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x263)
            EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_ADD(LocalVar(1), 30)
            EVT_CALL(ShowEmote, 0, EMOTE_QUESTION, -45, 30, 2, LocalVar(0), LocalVar(1), LocalVar(2), 5)
            EVT_WAIT(30)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(8022A880) = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20B9)
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(3))
    EVT_IF_NOT_FLAG(LocalVar(3), 0x80000)
        EVT_ADD(LocalVar(1), 16)
    EVT_ELSE
        EVT_ADD(LocalVar(1), 6)
    EVT_END_IF
    EVT_CALL(PlayEffect, 0x13, 0, LocalVar(0), LocalVar(1), LocalVar(2), 1, 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x13, 1, LocalVar(0), LocalVar(1), LocalVar(2), 1, 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_THREAD
        EVT_SET(LocalVar(0), 0)
        EVT_LOOP(32)
            EVT_WAIT(1)
            EVT_ADD(LocalVar(0), 45)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LocalVar(0), 0)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(32)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x300)
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(1), 15)
    EVT_CALL(PlayEffect, 0x52, 4, LocalVar(0), LocalVar(1), LocalVar(2), 1, 40, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 0, LocalVar(0), LocalVar(1), LocalVar(2), -4, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 0, LocalVar(0), LocalVar(1), LocalVar(2), -4, 4, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 0, LocalVar(0), LocalVar(1), LocalVar(2), 4, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 0, LocalVar(0), LocalVar(1), LocalVar(2), 4, 4, 0, 0, 0, 0, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022ABA8) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_H)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamOffsetZ, 38)
    EVT_CALL(SetBattleCamZoom, 256)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022AC40) = {
    EVT_CALL(func_802535B4, 1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 12)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022AC80) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_55)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(takeTurn_8022B4F0);
extern EvtScript N(idle_8022ADA4);
extern EvtScript N(handleEvent_8022ADD8);
extern EvtScript N(nextTurn_8022BB44);

EvtScript N(init_8022ACE4) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8022B4F0)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8022ADA4)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8022ADD8)))
    EVT_CALL(BindNextTurn, -127, EVT_ADDR(N(nextTurn_8022BB44)))
    EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_CALL(SetActorVar, -127, 1, 0)
    EVT_CALL(SetActorVar, -127, 2, 0)
    EVT_CALL(SetActorVar, -127, 3, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8022ADA4) = {
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(8022C2A4);
extern EvtScript N(8022BF1C);

EvtScript N(handleEvent_8022ADD8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(9)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_mage_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(10)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_mage_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(8022A750))
            EVT_EXEC_WAIT(N(8022C2A4))
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_mage_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_mage_jr_troopa_default_still)
            EVT_EXEC_WAIT(N(8022BF1C))
            EVT_RETURN
        EVT_CASE_EQ(14)
            EVT_SET(LocalVar(0), 1)
            EVT_SET(LocalVar(1), 2359306)
            EVT_SET(LocalVar(2), 2359307)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET(LocalVar(0), 1)
            EVT_SET(LocalVar(1), 2359306)
            EVT_SET(LocalVar(2), 2359307)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_mage_jr_troopa_default_burn_dead)
            EVT_EXEC_WAIT(N(8022BF1C))
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_mage_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_mage_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_mage_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(N(8022BF1C))
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_mage_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_mage_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_mage_jr_troopa_default_run)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_mage_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_mage_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_mage_jr_troopa_default_still)
            EVT_EXEC_WAIT(N(8022BF1C))
            EVT_RETURN
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_mage_jr_troopa_default_idle)
            EVT_EXEC_WAIT(DoImmune)
            EVT_EXEC_WAIT(N(8022A750))
            EVT_EXEC_WAIT(N(8022C2A4))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(58)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
            EVT_IF_NOT_FLAG(LocalVar(0), 0x35D000)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_mage_jr_troopa_default_hanging)
                EVT_WAIT(1000)
            EVT_END_IF
        EVT_CASE_EQ(31)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
            EVT_IF_NOT_FLAG(LocalVar(0), 0x35D000)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_mage_jr_troopa_default_hanging)
                EVT_WAIT(20)
                EVT_EXEC_WAIT(N(8022ABA8))
                EVT_CALL(ActorSpeak, 1900955, -127, 1, 2359310, 2359299)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_mage_jr_troopa_default_idle)
                EVT_EXEC_WAIT(N(8022AC40))
            EVT_END_IF
        EVT_CASE_EQ(42)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_mage_jr_troopa_default_hurt)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_mage_jr_troopa_default_run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_mage_jr_troopa_default_idle)
        EVT_CASE_EQ(53)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_mage_jr_troopa_default_idle)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_mage_jr_troopa_default_idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8022B4F0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_mage_jr_troopa_default_attack)
    EVT_WAIT(8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x80000)
        EVT_SET(LocalVar(3), 0)
        EVT_SET(LocalVar(4), 36)
        EVT_SETF(LocalVar(5), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_SET(LocalVar(3), 0)
        EVT_SET(LocalVar(4), 14)
        EVT_SETF(LocalVar(5), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), LocalVar(3))
    EVT_ADD(LocalVar(1), LocalVar(4))
    EVT_CALL(PlayEffect, 0x13, 0, LocalVar(0), LocalVar(1), LocalVar(2), LocalVar(5), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_mage_jr_troopa_default_attack2)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_NO_CONTACT, 0, 1, 16)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(3), LocalVar(4), LocalVar(5))
            EVT_SUB(LocalVar(3), 120)
            EVT_ADD(LocalVar(4), 20)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
            EVT_IF_NOT_FLAG(LocalVar(0), 0x80000)
                EVT_SET(LocalVar(6), -8)
                EVT_SET(LocalVar(7), 20)
                EVT_SETF(LocalVar(8), EVT_FLOAT(1.0))
            EVT_ELSE
                EVT_SET(LocalVar(6), -3)
                EVT_SET(LocalVar(7), 8)
                EVT_SETF(LocalVar(8), EVT_FLOAT(0.4))
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_ADD(LocalVar(0), LocalVar(6))
            EVT_ADD(LocalVar(1), LocalVar(7))
            EVT_CALL(PlayEffect, 0x12, 0, LocalVar(0), LocalVar(1), LocalVar(2), LocalVar(3), LocalVar(4), LocalVar(5), 30, 0, 0, 0, 0, 0)
            EVT_WAIT(35)
            EVT_IF_EQ(LVarA, 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(3), LocalVar(4), LocalVar(5))
    EVT_ADD(LocalVar(4), 20)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
    EVT_IF_NOT_FLAG(LocalVar(0), 0x80000)
        EVT_SET(LocalVar(6), -8)
        EVT_SET(LocalVar(7), 20)
        EVT_SETF(LocalVar(8), EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_SET(LocalVar(6), -3)
        EVT_SET(LocalVar(7), 8)
        EVT_SETF(LocalVar(8), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), LocalVar(6))
    EVT_ADD(LocalVar(1), LocalVar(7))
    EVT_CALL(PlayEffect, 0x12, 0, LocalVar(0), LocalVar(1), LocalVar(2), LocalVar(3), LocalVar(4), LocalVar(5), 15, 0, 0, 0, 0, 0)
    EVT_WAIT(15)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), (DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT), 0, 0, 8, 32)
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(0)
            EVT_CALL(GetActorVar, -127, 1, LocalVar(0))
            EVT_IF_EQ(LocalVar(0), 0)
                EVT_CALL(GetLastDamage, 0, LocalVar(1))
                EVT_IF_NE(LocalVar(1), 0)
                    EVT_CALL(SetActorVar, -127, 1, 1)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_8022BB44) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(12)
            EVT_CALL(GetActorVar, -127, 0, LocalVar(0))
            EVT_IF_EQ(LocalVar(0), 1)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(1))
                EVT_IF_NOT_FLAG(LocalVar(1), 0x35D000)
                    EVT_CALL(SetActorVar, -127, 0, 2)
                    EVT_CALL(GetActorVar, -127, 3, LocalVar(0))
                    EVT_IF_EQ(LocalVar(0), 0)
                        EVT_EXEC_WAIT(N(8022ABA8))
                        EVT_WAIT(20)
                    EVT_END_IF
                    EVT_CALL(ActorSpeak, 1179869, -127, 1, 2359310, 2359299)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_mage_jr_troopa_default_idle)
                    EVT_EXEC_WAIT(N(8022AC40))
                    EVT_WAIT(20)
                EVT_END_IF
            EVT_ELSE
                EVT_WAIT(20)
            EVT_END_IF
            EVT_CALL(SetActorVar, -127, 3, 0)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_CALL(GetActorVar, -127, 1, LocalVar(0))
            EVT_IF_EQ(LocalVar(0), 1)
                EVT_CALL(SetActorVar, -127, 1, 2)
                EVT_EXEC_WAIT(N(8022ABA8))
                EVT_WAIT(20)
                EVT_CALL(ActorSpeak, 1179870, -127, 1, 2359310, 2359299)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_mage_jr_troopa_default_idle)
                EVT_EXEC_WAIT(N(8022AC40))
                EVT_WAIT(10)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, -127, 0, LocalVar(0))
            EVT_IF_EQ(LocalVar(0), 0)
                EVT_CALL(SetActorVar, -127, 0, 1)
                EVT_WAIT(15)
                EVT_EXEC_WAIT(N(8022ABA8))
                EVT_WAIT(10)
                EVT_CALL(ActorSpeak, 1179867, -127, 2, 2162714, 2162715)
                EVT_WAIT(8)
                EVT_EXEC_WAIT(N(8022A880))
                EVT_CALL(SetPartFlagBits, -127, 2, 1, 1)
                EVT_CALL(SetPartFlagBits, -127, 1, 1, 0)
                EVT_WAIT(15)
                EVT_CALL(ActorSpeak, 1179868, -127, 1, 2359310, 2359299)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_mage_jr_troopa_default_idle)
                EVT_WAIT(10)
                EVT_EXEC_WAIT(N(8022AC40))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022BF1C) = {
    EVT_CALL(func_8027D32C, -127)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(func_80269E80, LocalVar(5))
    EVT_SWITCH(LocalVar(5))
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
            EVT_SET(LocalVar(2), 0)
            EVT_LOOP(24)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LocalVar(2))
                EVT_ADD(LocalVar(2), 30)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_END_SWITCH
    EVT_LABEL(0)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(1), 10)
        EVT_ADD(LocalVar(2), 10)
        EVT_LOOP(3)
            EVT_CALL(PlayEffect, 0x1, LocalVar(0), LocalVar(1), LocalVar(2), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetPartFlagBits, -127, 1, 1, 1)
    EVT_CALL(SetPartFlagBits, -127, 2, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jr_troopa_default_dead_still)
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SUB(LocalVar(0), 5)
    EVT_CALL(SetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_WAIT(15)
    EVT_CALL(PlaySound, SOUND_DEATH)
    EVT_CALL(DropStarPoints, -127)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(SetBattleCamZoom, 260)
    EVT_CALL(SetBattleCamOffsetZ, 15)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E5)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jr_troopa_default_dead)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_ADDR(N(idleAnimations_8022A61C)))
    EVT_WAIT(60)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022C2A4) = {
    EVT_CALL(GetActorVar, -127, 3, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 1)
        EVT_WAIT(10)
        EVT_EXEC_WAIT(N(8022ABA8))
        EVT_CALL(ActorSpeak, 1900954, -127, 1, 2359310, 2359299)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_mage_jr_troopa_default_idle)
        EVT_CALL(GetActorVar, -127, 0, LocalVar(0))
        EVT_IF_NE(LocalVar(0), 1)
            EVT_EXEC_WAIT(N(8022AC40))
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
