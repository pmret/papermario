#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/TheMaster.h"

#define NAMESPACE b_area_mac_master3

s32 N(IdleAnimations_8022D9A0)[] = {
    STATUS_NORMAL,    ANIM_TheMaster_Walk,
    STATUS_STONE,     ANIM_TheMaster_Still,
    STATUS_SLEEP,     ANIM_TheMaster_Sleep,
    STATUS_POISON,    ANIM_TheMaster_Still,
    STATUS_STOP,      ANIM_TheMaster_Still,
    STATUS_STATIC,    ANIM_TheMaster_Still,
    STATUS_PARALYZE,  ANIM_TheMaster_Still,
    STATUS_DIZZY,     ANIM_TheMaster_Dizzy,
    STATUS_DIZZY,     ANIM_TheMaster_Dizzy,
    STATUS_END,
};

s32 N(IdleAnimations_8022D9EC)[] = {
    STATUS_NORMAL,    ANIM_TheMaster_AscendedWalk,
    STATUS_STONE,     ANIM_TheMaster_AscendedStill,
    STATUS_SLEEP,     ANIM_TheMaster_AscendedSleep,
    STATUS_POISON,    ANIM_TheMaster_AscendedStill,
    STATUS_STOP,      ANIM_TheMaster_AscendedStill,
    STATUS_STATIC,    ANIM_TheMaster_AscendedStill,
    STATUS_PARALYZE,  ANIM_TheMaster_AscendedStill,
    STATUS_DIZZY,     ANIM_TheMaster_AscendedDizzy,
    STATUS_DIZZY,     ANIM_TheMaster_AscendedDizzy,
    STATUS_END,
};

s32 N(DefenseTable_8022DA38)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(StatusTable_8022DA44)[] = {
    STATUS_NORMAL, 50,
    STATUS_DEFAULT, 50,
    STATUS_SLEEP, 20,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 20,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 20,
    STATUS_SHRINK, 20,
    STATUS_STOP, 30,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -2,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -2,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, -2,
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, -1,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(PartsTable_8022DAF0)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 28 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8022D9A0),
        .defenseTable = N(DefenseTable_8022DA38),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 2, -7 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8022D9A0),
        .defenseTable = N(DefenseTable_8022DA38),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

extern EvtScript N(init_8022DB60);

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_THE_MASTER_3,
    .level = 0,
    .maxHP = 99,
    .partCount = ARRAY_COUNT( N(PartsTable_8022DAF0)),
    .partsData = N(PartsTable_8022DAF0),
    .initScript = &N(init_8022DB60),
    .statusTable = N(StatusTable_8022DA44),
    .escapeChance = 100,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 70,
    .coinReward = 0,
    .size = { 30, 35 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 30 },
    .statusMessageOffset = { 10, 30 },
};

extern EvtScript N(takeTurn_80230B20);
extern EvtScript N(idle_8022DC34);
extern EvtScript N(handleEvent_80231408);
extern EvtScript N(nextTurn_80230D44);

EvtScript N(init_8022DB60) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_80230B20)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8022DC34)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80231408)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn_80230D44)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 2)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_NO_GAME_OVER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8022DC34) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(8022DC44) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedHurt)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_TheMaster_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_GOLDEN_FLAMES)
            EVT_WAIT(1)
            EVT_CALL(ModifyActorDecoration, ACTOR_SELF, 1, 0, 50, 50, 0, 0)
        EVT_CASE_EQ(36)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_TheMaster_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedDefeated)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedHurt)
            EVT_CHILD_THREAD
                EVT_WAIT(30)
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
                EVT_WAIT(10)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_GOLDEN_FLAMES)
                EVT_WAIT(1)
                EVT_CALL(ModifyActorDecoration, ACTOR_SELF, 1, 0, 50, 50, 0, 0)
            EVT_END_CHILD_THREAD
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedHurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedHurt)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedRun)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_WAIT(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedWalk)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedIdle)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedHurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedDefeated)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedHurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedDefeated)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedHurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedDefeated)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(53)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedIdle)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedIdle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedRun)
            EVT_SET_CONST(LVar2, ANIM_TheMaster_AscendedHurt)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(singleStrike3) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedRun)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.8))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedIdle)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BD)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BD)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedPunch)
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedKick)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BC)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BB)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 0, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -50, 0, 0)
            EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedIdle)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
            EVT_WAIT(10)
            EVT_IF_EQ(LVarA, 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedIdle)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedRun)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedIdle)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_SELF, 5, FALSE)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3ED)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BB)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 10, BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BB)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 20, 0)
                EVT_SET(LVar0, 0)
                EVT_LOOP(10)
                    EVT_ADD(LVar0, 36)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 50)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.2))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedMidair)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BA)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedLand)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT(3)
            EVT_ADD(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedMidair)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3B4)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedLand)
            EVT_WAIT(20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedIdle)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedRun)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedIdle)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(doubleStrike3) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_I)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(SetBattleCamOffsetZ, 13)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedDownwardStance)
    EVT_WAIT(40)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_H)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3B9)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BB)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 0, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -50, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedPalmStance)
            EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedIdle)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
            EVT_WAIT(10)
            EVT_IF_EQ(LVarA, 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedIdle)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedRun)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedIdle)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedPalmStance)
    EVT_CALL(RunToGoal, ACTOR_SELF, 5, FALSE)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(4.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3ED)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BB)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 6, BS_FLAGS1_10)
    EVT_WAIT(15)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_JUMP_3E2)
        EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedUppercut)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.9))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 25, FALSE, TRUE, FALSE)
        EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_WAIT(2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3ED)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BB)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 7, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_WAIT(15)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BB)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 10, 0)
                EVT_SET(LVar0, 0)
                EVT_LOOP(10)
                    EVT_ADD(LVar0, 36)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 50)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedMidair)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 30, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BA)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedLand)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT(3)
            EVT_ADD(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedMidair)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3B4)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedLand)
            EVT_WAIT(20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedIdle)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedRun)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedIdle)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(tripleStrike3) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_I)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(SetBattleCamOffsetZ, 13)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedDownwardStance)
    EVT_WAIT(20)
    EVT_CALL(ActorSpeak, MSG_MAC_Gate_003C, ACTOR_SELF, 1, 0x00A2000A, 0x00A20006)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_H)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3B9)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BB)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 0, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -50, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedPalmStance)
            EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedIdle)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
            EVT_WAIT(10)
            EVT_IF_EQ(LVarA, 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedIdle)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedRun)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedIdle)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedPalmStance)
    EVT_CALL(RunToGoal, ACTOR_SELF, 5, FALSE)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(4.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3ED)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BB)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 5, BS_FLAGS1_10)
    EVT_WAIT(15)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_THREAD
        EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_JUMP_3E2)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedUppercut)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 25, FALSE, TRUE, FALSE)
        EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_WAIT(2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3ED)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BB)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 6, 0)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(EnablePlayerBlur, 1)
        EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(0.3))
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Hurt, ANIM_Mario1_Hurt, ANIM_Mario1_Hurt)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(func_80273444, 50, 0, 0)
        EVT_CALL(EnablePlayerBlur, 0)
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedMidair)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 30, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BA)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedLand)
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(3)
    EVT_ADD(LVar0, 20)
    EVT_SET(LVar1, 0)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BD)
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BD)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedPunch)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3B4)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedKick)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_SELF, 3, FALSE)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(6.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(5.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(4.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3EE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BB)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 7, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_WAIT(15)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BB)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 10, 0)
                EVT_SET(LVar0, 0)
                EVT_LOOP(10)
                    EVT_ADD(LVar0, 36)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 50)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedMidair)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 30, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BA)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedLand)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT(3)
            EVT_ADD(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedMidair)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3B4)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedLand)
            EVT_WAIT(20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedIdle)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedRun)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedIdle)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80230240) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_I)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(SetBattleCamOffsetZ, 13)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedDownwardStance)
    EVT_WAIT(20)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedPalmStance)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedDownwardStance)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedPunch)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedDownwardStance)
    EVT_WAIT(15)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 50)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedIdle)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 90, 0, EASING_COS_IN_OUT)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, TRUE)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT(30)
    EVT_SET(LVar0, 80)
    EVT_LOOP(5)
        EVT_ADD(LVar0, 20)
        EVT_CALL(ModifyActorDecoration, ACTOR_SELF, 1, 0, 80, LVar0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(5)
        EVT_SUB(LVar0, 20)
        EVT_CALL(ModifyActorDecoration, ACTOR_SELF, 1, 0, 80, LVar0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8023059C) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_I)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(SetBattleCamOffsetZ, 13)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedDownwardStance)
    EVT_SET(LVar0, 80)
    EVT_LOOP(30)
        EVT_ADD(LVar0, 2)
        EVT_CALL(ModifyActorDecoration, ACTOR_SELF, 1, 0, 80, LVar0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedPunch)
    EVT_THREAD
        EVT_SET(LVar0, 140)
        EVT_LOOP(30)
            EVT_SUB(LVar0, 2)
            EVT_CALL(ModifyActorDecoration, ACTOR_SELF, 1, 0, 80, LVar0, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(AddActorDecoration, ACTOR_SELF, 2, 0, ACTOR_DECORATION_GOLDEN_FLAMES)
    EVT_WAIT(1)
    EVT_CALL(ModifyActorDecoration, ACTOR_SELF, 2, 0, 40, 40, 0, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, 1, FALSE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartAlpha, ACTOR_SELF, 2, 80)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 2, EVT_FLOAT(0.1))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 2, LVar0, LVar1, LVar2, 10, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, 1, TRUE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 10, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80230914) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_I)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(SetBattleCamOffsetZ, 13)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedDownwardStance)
    EVT_SET(LVar0, 80)
    EVT_LOOP(30)
        EVT_ADD(LVar0, 2)
        EVT_CALL(ModifyActorDecoration, ACTOR_SELF, 1, 0, 80, LVar0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedIdle)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, EASING_LINEAR)
    EVT_WAIT(10000)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 10, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80230B20) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
        EVT_IF_LT(LVar0, 0)
            EVT_EXEC_WAIT(N(80230240))
        EVT_ELSE
            EVT_CALL(GetActorHP, ACTOR_PLAYER, LVar0)
            EVT_IF_GT(LVar0, 20)
                EVT_CALL(RandInt, 100, LVar0)
                EVT_SWITCH(LVar0)
                    EVT_CASE_LT(30)
                        EVT_EXEC_WAIT(N(tripleStrike3))
                    EVT_CASE_LT(50)
                        EVT_EXEC_WAIT(N(doubleStrike3))
                    EVT_CASE_DEFAULT
                        EVT_EXEC_WAIT(N(singleStrike3))
                EVT_END_SWITCH
            EVT_ELSE
                EVT_CALL(RandInt, 100, LVar0)
                EVT_SWITCH(LVar0)
                    EVT_CASE_LT(50)
                        EVT_EXEC_WAIT(N(doubleStrike3))
                    EVT_CASE_DEFAULT
                        EVT_EXEC_WAIT(N(singleStrike3))
                EVT_END_SWITCH
            EVT_END_IF
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(RandInt, 100, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_LT(100)
                EVT_EXEC_WAIT(N(80230914))
            EVT_CASE_LT(50)
                EVT_EXEC_WAIT(N(8023059C))
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_80230D44) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                EVT_WAIT(10)
                EVT_CALL(ActorSpeak, MSG_MAC_Gate_002E, ACTOR_SELF, 1, 0x00A20009, 0x00A20005)
                EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_Cough)
                EVT_WAIT(15)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_OpenMouth)
                EVT_WAIT(5)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20B8)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 20)
                EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 30, 0)
                EVT_SET(LVar0, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_Still)
                EVT_LOOP(15)
                    EVT_ADD(LVar0, 24)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_SET(LVar0, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_Still)
                EVT_LOOP(5)
                    EVT_ADD(LVar0, 18)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMOKE_BURST)
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_ADD(LVar1, 3)
                    EVT_LOOP(3)
                        EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
                        EVT_WAIT(3)
                    EVT_END_LOOP
                EVT_END_THREAD
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_Still)
                EVT_LOOP(5)
                    EVT_ADD(LVar0, 36)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedStill)
                EVT_LOOP(5)
                    EVT_ADD(LVar0, 18)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_WAIT(15)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_8022D9EC)))
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedRun)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedUppercut)
                EVT_WAIT(2)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_GOLDEN_FLAMES)
                EVT_WAIT(1)
                EVT_CALL(ModifyActorDecoration, ACTOR_SELF, 1, 0, 50, 50, 0, 0)
                EVT_WAIT(15)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_TheMaster_AscendedIdle)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, MSG_MAC_Gate_0038, ACTOR_SELF, 1, 0x00A2000A, 0x00A20006)
            EVT_END_IF
        EVT_CASE_EQ(12)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, 0x351000)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
            EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
            EVT_DIV(LVar1, 2)
            EVT_IF_LE(LVar0, LVar1)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, MSG_MAC_Gate_003B, ACTOR_SELF, 1, 0x00A2000A, 0x00A20006)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetPlayerHP, LVar0)
            EVT_IF_LE(LVar0, 10)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, MSG_MAC_Gate_003D, ACTOR_SELF, 1, 0x00A2000A, 0x00A20006)
                EVT_BREAK_SWITCH
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80231408) = {
    EVT_EXEC_WAIT(N(8022DC44))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, 0x351000)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleFlags, LVar0)
    EVT_IF_FLAG(LVar0, BS_FLAGS1_200 | BS_FLAGS1_40)
        EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
        EVT_IF_GT(LVar0, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 1)
            EVT_CALL(AddActorVar, ACTOR_SELF, 3, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(10)
        EVT_CASE_OR_EQ(14)
        EVT_CASE_OR_EQ(11)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVarA)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVarB)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
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
            EVT_IF_EQ(LVarA, 1)
                EVT_IF_GT(LVarB, 2)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                    EVT_CALL(MoveBattleCamOver, 10)
                    EVT_CALL(ActorSpeak, MSG_MAC_Gate_003A, ACTOR_SELF, 1, 0x00A2000A, 0x00A20006)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, MSG_MAC_Gate_0039, ACTOR_SELF, 1, 0x00A2000A, 0x00A20006)
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
