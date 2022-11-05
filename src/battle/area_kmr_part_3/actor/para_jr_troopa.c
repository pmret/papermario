#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/JrTroopa.h"
#include "sprite/npc/ParaJrTroopa.h"

#define NAMESPACE b_area_kmr_part_3_para_jr_troopa

s32 N(idleAnimations_80225DC0)[] = {
    STATUS_NORMAL,    ANIM_ParaJrTroopa_Idle,
    STATUS_SLEEP,     ANIM_ParaJrTroopa_Sleep,
    STATUS_STONE,     ANIM_ParaJrTroopa_Still,
    STATUS_POISON,    ANIM_ParaJrTroopa_Still,
    STATUS_STOP,      ANIM_ParaJrTroopa_Still,
    STATUS_STATIC,    ANIM_ParaJrTroopa_Still,
    STATUS_PARALYZE,  ANIM_ParaJrTroopa_Still,
    STATUS_DIZZY,     ANIM_ParaJrTroopa_Dizzy,
    STATUS_END,
};

s32 N(idleAnimations_80225E04)[] = {
    STATUS_NORMAL,    ANIM_JrTroopa_Idle,
    STATUS_SLEEP,     ANIM_JrTroopa_Sleep,
    STATUS_STONE,     ANIM_JrTroopa_Still,
    STATUS_POISON,    ANIM_JrTroopa_Still,
    STATUS_STOP,      ANIM_JrTroopa_Still,
    STATUS_STATIC,    ANIM_JrTroopa_Still,
    STATUS_PARALYZE,  ANIM_JrTroopa_Still,
    STATUS_DIZZY,     ANIM_JrTroopa_Dizzy,
    STATUS_END,
};

s32 N(idleAnimations_80225E48)[] = {
    STATUS_NORMAL,    ANIM_JrTroopa_Defeated,
    STATUS_END,
};

s32 N(defenseTable_80225E54)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(statusTable_80225E60)[] = {
    STATUS_NORMAL, 100,
    STATUS_DEFAULT, 100,
    STATUS_SLEEP, 50,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 50,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 50,
    STATUS_SHRINK, 80,
    STATUS_STOP, 80,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
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

ActorPartBlueprint N(partsTable_80225F0C)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 35 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80225DC0),
        .defenseTable = N(defenseTable_80225E54),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 250,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80225E04),
        .defenseTable = N(defenseTable_80225E54),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
};

extern EvtScript N(init_80226510);

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_JR_TROOPA3,
    .level = 52,
    .maxHP = 40,
    .partCount = ARRAY_COUNT(N(partsTable_80225F0C)),
    .partsData = N(partsTable_80225F0C),
    .script = &N(init_80226510),
    .statusTable = N(statusTable_80225E60),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 60, 35 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -25, 35 },
    .statusMessageOffset = { 10, 25 },
};

EvtScript N(80225F7C) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar2)
    EVT_IF_FLAG(LVar2, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleFlags, LVar2)
    EVT_IF_FLAG(LVar2, BS_FLAGS1_80000)
        EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar2, 183)
            EVT_CALL(SetActorVar, -127, 1, 1)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_263)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 30)
            EVT_CALL(ShowEmote, 0, EMOTE_QUESTION, -45, 30, 2, LVar0, LVar1, LVar2, 5)
            EVT_WAIT(30)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802260AC) = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20B9)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_IF_NOT_FLAG(LVar3, 0x80000)
        EVT_ADD(LVar1, 16)
    EVT_ELSE
        EVT_ADD(LVar1, 6)
    EVT_END_IF
    EVT_CALL(PlayEffect, 0x13, 0, LVar0, LVar1, LVar2, 1, 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x13, 1, LVar0, LVar1, LVar2, 1, 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(32)
            EVT_WAIT(1)
            EVT_ADD(LVar0, 45)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(32)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_300)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_CALL(PlayEffect, 0x52, 4, LVar0, LVar1, LVar2, 1, 40, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 0, LVar0, LVar1, LVar2, -4, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 0, LVar0, LVar1, LVar2, -4, 4, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 0, LVar0, LVar1, LVar2, 4, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 0, LVar0, LVar1, LVar2, 4, 4, 0, 0, 0, 0, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(802263D4) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_H)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamOffsetZ, 38)
    EVT_CALL(SetBattleCamZoom, 256)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022646C) = {
    EVT_CALL(func_802535B4, 1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 12)
    EVT_RETURN
    EVT_END
};

EvtScript N(802264AC) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_55)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(takeTurn_80226F58);
extern EvtScript N(idle_802265A0);
extern EvtScript N(handleEvent_802266B0);
extern EvtScript N(nextTurn_80227724);

EvtScript N(init_80226510) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_80226F58)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_802265A0)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_802266B0)))
    EVT_CALL(BindNextTurn, -127, EVT_PTR(N(nextTurn_80227724)))
    EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_CALL(SetActorVar, -127, 1, 0)
    EVT_RETURN
    EVT_END
};

#include "common/UnkBattleFunc1.inc.c"

EvtScript N(idle_802265A0) = {
    EVT_LABEL(0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, 0x41000)
        EVT_CALL(SetTargetOffset, -127, 1, -12, 28)
        EVT_CALL(func_8027D4C8, -127, 1, 4, -6)
        EVT_CALL(N(UnkBattleFunc1), -25, 27, -1, 27)
    EVT_ELSE
        EVT_CALL(SetTargetOffset, -127, 1, -5, 33)
        EVT_CALL(func_8027D4C8, -127, 1, 0, -6)
        EVT_CALL(N(UnkBattleFunc1), -22, 30, 2, 28)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(802279B0);
extern EvtScript N(80227D38);
extern EvtScript N(80227E1C);

EvtScript N(handleEvent_802266B0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(80225F7C))
            EVT_EXEC_WAIT(N(80227E1C))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(N(802279B0))
            EVT_RETURN
        EVT_CASE_EQ(14)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, 2424840)
            EVT_SET(LVar2, 2424841)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, 2424840)
            EVT_SET(LVar2, 2424841)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_BurnStill)
            EVT_EXEC_WAIT(N(802279B0))
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(N(802279B0))
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(80227D38))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ParaJrTroopa_Idle)
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Idle)
            EVT_EXEC_WAIT(N(802279B0))
            EVT_RETURN
        EVT_CASE_EQ(23)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Idle)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(25)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Idle)
            EVT_EXEC_WAIT(DoImmune)
            EVT_EXEC_WAIT(N(80225F7C))
            EVT_EXEC_WAIT(N(80227E1C))
        EVT_CASE_EQ(42)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ParaJrTroopa_Hurt)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ParaJrTroopa_FlyFast)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ParaJrTroopa_Idle)
        EVT_CASE_EQ(58)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ParaJrTroopa_Flail)
                EVT_WAIT(1000)
            EVT_END_IF
        EVT_CASE_EQ(31)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_SET_CONST(LVar0, 0x00000001)
                EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Flail)
                EVT_EXEC_WAIT(DoImmune)
                EVT_EXEC_WAIT(N(802263D4))
                EVT_CALL(ActorSpeak, 1900955, -127, 1, 2424844, 2424844)
                EVT_EXEC_WAIT(N(8022646C))
            EVT_END_IF
        EVT_CASE_EQ(53)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Idle)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80226D4C) = {
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
    EVT_SUB(LVar0, 10)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ParaJrTroopa_Idle)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ParaJrTroopa_Idle)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ParaJrTroopa_FlyFast)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ParaJrTroopa_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80226F58) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ParaJrTroopa_FlyFast)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 5, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
            EVT_CALL(func_8024ECF8, -1, 1, 0)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(SetActorSounds, -127, 2, 8416, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ParaJrTroopa_FlyFast)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorSounds, -127, 1, 0, 0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_SUB(LVar0, 80)
            EVT_SET(LVar1, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ParaJrTroopa_Dive)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
            EVT_IF_EQ(LVarA, 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ParaJrTroopa_FlyFast)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ParaJrTroopa_Idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
            EVT_CALL(func_8024ECF8, -1, 1, 0)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(SetActorSounds, -127, 2, 8416, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ParaJrTroopa_FlyFast)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorSounds, -127, 1, 0, 0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ParaJrTroopa_Dive)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ParaJrTroopa_FlyFast)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
            EVT_WAIT(10)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ParaJrTroopa_FlyFast)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ParaJrTroopa_Idle)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_80227724) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LVarF)
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, -127, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(SetActorVar, -127, 0, 1)
                EVT_WAIT(15)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(SetBattleCamOffsetZ, 35)
                EVT_CALL(MoveBattleCamOver, 30)
                EVT_WAIT(30)
                EVT_CALL(ActorSpeak, 917536, -127, 2, 2162714, 2162715)
                EVT_WAIT(8)
                EVT_EXEC_WAIT(N(802260AC))
                EVT_CALL(SetPartFlagBits, -127, 2, 1, 1)
                EVT_CALL(SetPartFlagBits, -127, 1, 1, 0)
                EVT_WAIT(30)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, 20)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 60, LVar2)
                EVT_CALL(FlyToGoal, ACTOR_SELF, 45, 0, 0)
                EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, 60, LVar2)
                EVT_CALL(HPBarToHome, ACTOR_SELF)
                EVT_WAIT(8)
                EVT_CALL(ActorSpeak, 917537, -127, 1, 2424844, 2424834)
                EVT_WAIT(10)
                EVT_EXEC_WAIT(N(8022646C))
            EVT_END_IF
        EVT_CASE_EQ(12)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(802279B0) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_IF_EQ(LVar1, 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_301)
    EVT_CALL(SetActorSounds, -127, 2, 0, 0)
    EVT_CALL(func_8027D32C, -127)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(FallToGoal, -127, 10)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_CALL(HPBarToCurrent, ACTOR_SELF)
    EVT_CALL(func_8027D2D8, -127)
    EVT_LABEL(0)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 10)
        EVT_ADD(LVar2, 10)
        EVT_LOOP(3)
            EVT_CALL(PlayEffect, 0x1, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetPartFlagBits, -127, 1, 1, 1)
    EVT_CALL(SetPartFlagBits, -127, 2, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_JrTroopa_DefeatedBegin)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 5)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DEATH)
    EVT_CALL(DropStarPoints, -127)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(SetBattleCamZoom, 260)
    EVT_CALL(SetBattleCamOffsetZ, 15)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E5)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_JrTroopa_Defeated)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_PTR(N(idleAnimations_80225E48)))
    EVT_WAIT(60)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, 4194304, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(80227D38) = {
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_ParaJrTroopa_FlyFast)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_SUB(LVar4, LVar1)
    EVT_MULF(LVar4, EVT_FLOAT(0.3))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, LVar4, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80227E1C) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(GetActorVar, -127, 1, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(SetActorVar, -127, 1, 0)
            EVT_WAIT(15)
            EVT_EXEC_WAIT(N(802263D4))
            EVT_WAIT(10)
            EVT_CALL(ActorSpeak, 1900954, -127, 1, 2424844, 2424834)
            EVT_WAIT(10)
            EVT_EXEC_WAIT(N(8022646C))
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
