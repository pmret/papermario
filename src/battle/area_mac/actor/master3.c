#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/the_master.h"

#define NAMESPACE b_area_mac_master3

s32 N(idleAnimations_8022D9A0)[] = {
    STATUS_NORMAL,    NPC_ANIM_the_master_Palette_00_Anim_5,
    STATUS_STONE,     NPC_ANIM_the_master_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_the_master_Palette_00_Anim_1C,
    STATUS_POISON,    NPC_ANIM_the_master_Palette_00_Anim_0,
    STATUS_STOP,      NPC_ANIM_the_master_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_the_master_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_the_master_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_the_master_Palette_00_Anim_1E,
    STATUS_DIZZY,     NPC_ANIM_the_master_Palette_00_Anim_1E,
    STATUS_END,
};

s32 N(idleAnimations_8022D9EC)[] = {
    STATUS_NORMAL,    NPC_ANIM_the_master_Palette_00_Anim_6,
    STATUS_STONE,     NPC_ANIM_the_master_Palette_00_Anim_1,
    STATUS_SLEEP,     NPC_ANIM_the_master_Palette_00_Anim_1D,
    STATUS_POISON,    NPC_ANIM_the_master_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_the_master_Palette_00_Anim_1,
    STATUS_STATIC,    NPC_ANIM_the_master_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_the_master_Palette_00_Anim_1,
    STATUS_DIZZY,     NPC_ANIM_the_master_Palette_00_Anim_1F,
    STATUS_DIZZY,     NPC_ANIM_the_master_Palette_00_Anim_1F,
    STATUS_END,
};

s32 N(defenseTable_8022DA38)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(statusTable_8022DA44)[] = {
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

ActorPartBlueprint N(partsTable_8022DAF0)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 28 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8022D9A0),
        .defenseTable = N(defenseTable_8022DA38),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 2,
        .unk_1D = 0xF9,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8022D9A0),
        .defenseTable = N(defenseTable_8022DA38),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
};

extern EvtScript N(init_8022DB60);

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_THE_MASTER_3,
    .level = 0,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(partsTable_8022DAF0)),
    .partsData = N(partsTable_8022DAF0),
    .script = &N(init_8022DB60),
    .statusTable = N(statusTable_8022DA44),
    .escapeChance = 100,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
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
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_80230B20)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8022DC34)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80231408)))
    EVT_CALL(BindNextTurn, -127, EVT_ADDR(N(nextTurn_80230D44)))
    EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_CALL(SetActorVar, -127, 1, 0)
    EVT_CALL(SetActorVar, -127, 2, 0)
    EVT_CALL(SetActorVar, -127, 3, 2)
    EVT_CALL(SetBattleFlagBits, 8388608, 1)
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
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_the_master_Palette_00_Anim_16)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_the_master_Palette_00_Anim_1A)
            EVT_SET_CONST(LW(2), NPC_ANIM_the_master_Palette_00_Anim_1B)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 1)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(ModifyActorDecoration, -127, 1, 0, 50, 50, 0, 0)
        EVT_CASE_EQ(36)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_the_master_Palette_00_Anim_1A)
            EVT_SET_CONST(LW(2), NPC_ANIM_the_master_Palette_00_Anim_1B)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_the_master_Palette_00_Anim_18)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_the_master_Palette_00_Anim_16)
            EVT_CHILD_THREAD
                EVT_WAIT_FRAMES(30)
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
                EVT_WAIT_FRAMES(10)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 1)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(ModifyActorDecoration, -127, 1, 0, 50, 50, 0, 0)
            EVT_END_CHILD_THREAD
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_the_master_Palette_00_Anim_16)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_the_master_Palette_00_Anim_16)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_8)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_6)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_the_master_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_the_master_Palette_00_Anim_16)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_the_master_Palette_00_Anim_18)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_the_master_Palette_00_Anim_16)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_the_master_Palette_00_Anim_18)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_the_master_Palette_00_Anim_16)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_the_master_Palette_00_Anim_18)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(53)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_the_master_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_the_master_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_the_master_Palette_00_Anim_8)
            EVT_SET_CONST(LW(2), NPC_ANIM_the_master_Palette_00_Anim_16)
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
    EVT_CALL(UseBattleCamPreset, 63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_8)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.8))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BD)
    EVT_THREAD
        EVT_WAIT_FRAMES(15)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BD)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_E)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_F)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BC)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BB)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), 0, 0, 0, 16)
    EVT_SWITCH(LW(10))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(EnableActorBlur, -127, 1)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -50, 0, 0)
            EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
            EVT_CALL(EnableActorBlur, -127, 0)
            EVT_WAIT_FRAMES(10)
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_8)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableActorBlur, -127, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_SELF, 5, FALSE)
    EVT_CALL(EnableActorBlur, -127, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3ED)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BB)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 10, 48)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BB)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, -127, 0, 20, 0)
                EVT_SET(LW(0), 0)
                EVT_LOOP(10)
                    EVT_ADD(LW(0), 36)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 50)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.2))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_21)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BA)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_23)
            EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
            EVT_WAIT_FRAMES(3)
            EVT_ADD(LW(0), 20)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_21)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3B4)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_23)
            EVT_WAIT_FRAMES(20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_8)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(doubleStrike3) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, 8)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(SetBattleCamOffsetZ, 13)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_15)
    EVT_WAIT_FRAMES(40)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, 7)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3B9)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BB)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), 0, 0, 0, 16)
    EVT_SWITCH(LW(10))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(EnableActorBlur, -127, 1)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -50, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_13)
            EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
            EVT_CALL(EnableActorBlur, -127, 0)
            EVT_WAIT_FRAMES(10)
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_8)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableActorBlur, -127, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_13)
    EVT_CALL(RunToGoal, ACTOR_SELF, 5, FALSE)
    EVT_CALL(EnableActorBlur, -127, 0)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(4.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3ED)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BB)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 6, 16)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_JUMP_3E2)
        EVT_CALL(EnableActorBlur, -127, 1)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_14)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.9))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 25, FALSE, TRUE, FALSE)
        EVT_CALL(EnableActorBlur, -127, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.5))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_WAIT_FRAMES(2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3ED)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BB)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 7, 32)
    EVT_WAIT_FRAMES(15)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BB)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, -127, 0, 10, 0)
                EVT_SET(LW(0), 0)
                EVT_LOOP(10)
                    EVT_ADD(LW(0), 36)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 50)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_21)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 30, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BA)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_23)
            EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
            EVT_WAIT_FRAMES(3)
            EVT_ADD(LW(0), 20)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_21)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3B4)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_23)
            EVT_WAIT_FRAMES(20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_8)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(tripleStrike3) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, 8)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(SetBattleCamOffsetZ, 13)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_15)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(ActorSpeak, 131132, -127, 1, 10616842, 10616838)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, 7)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3B9)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BB)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), 0, 0, 0, 16)
    EVT_SWITCH(LW(10))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(EnableActorBlur, -127, 1)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -50, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_13)
            EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
            EVT_CALL(EnableActorBlur, -127, 0)
            EVT_WAIT_FRAMES(10)
            EVT_IF_EQ(LW(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_8)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableActorBlur, -127, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_13)
    EVT_CALL(RunToGoal, ACTOR_SELF, 5, FALSE)
    EVT_CALL(EnableActorBlur, -127, 0)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(4.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3ED)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BB)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 5, 16)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_THREAD
        EVT_CALL(EnableActorBlur, -127, 1)
        EVT_WAIT_FRAMES(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_JUMP_3E2)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_14)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 25, FALSE, TRUE, FALSE)
        EVT_CALL(EnableActorBlur, -127, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.5))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_WAIT_FRAMES(2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3ED)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BB)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 6, 0)
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(EnablePlayerBlur, 1)
        EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(0.3))
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
        EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_FALL_BACK, ANIM_FALL_BACK, ANIM_FALL_BACK)
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
        EVT_CALL(func_80273444, 50, 0, 0)
        EVT_CALL(EnablePlayerBlur, 0)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 50)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_21)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 30, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BA)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_23)
    EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
    EVT_WAIT_FRAMES(3)
    EVT_ADD(LW(0), 20)
    EVT_SET(LW(1), 0)
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BD)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BD)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_E)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3B4)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_F)
    EVT_CALL(EnableActorBlur, -127, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_SELF, 3, FALSE)
    EVT_CALL(EnableActorBlur, -127, 0)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(6.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(5.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(4.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3EE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BB)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 7, 32)
    EVT_WAIT_FRAMES(15)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BB)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, -127, 0, 10, 0)
                EVT_SET(LW(0), 0)
                EVT_LOOP(10)
                    EVT_ADD(LW(0), 36)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 50)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_21)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 30, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BA)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_23)
            EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
            EVT_WAIT_FRAMES(3)
            EVT_ADD(LW(0), 20)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_21)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3B4)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_23)
            EVT_WAIT_FRAMES(20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_8)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80230240) = {
    EVT_CALL(UseBattleCamPreset, 8)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(SetBattleCamOffsetZ, 13)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_15)
    EVT_WAIT_FRAMES(20)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_13)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_15)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_E)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_15)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(EnableActorBlur, -127, 1)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 50)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 90, 0, 10)
    EVT_CALL(EnableActorBlur, -127, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(ForceHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 1)
    EVT_CALL(SetActorVar, -127, 1, 1)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_WAIT_FRAMES(30)
    EVT_SET(LW(0), 80)
    EVT_LOOP(5)
        EVT_ADD(LW(0), 20)
        EVT_CALL(ModifyActorDecoration, -127, 1, 0, 80, LW(0), 0, 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_LOOP(5)
        EVT_SUB(LW(0), 20)
        EVT_CALL(ModifyActorDecoration, -127, 1, 0, 80, LW(0), 0, 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(10)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8023059C) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, 8)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(SetBattleCamOffsetZ, 13)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_15)
    EVT_SET(LW(0), 80)
    EVT_LOOP(30)
        EVT_ADD(LW(0), 2)
        EVT_CALL(ModifyActorDecoration, -127, 1, 0, 80, LW(0), 0, 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_E)
    EVT_THREAD
        EVT_SET(LW(0), 140)
        EVT_LOOP(30)
            EVT_SUB(LW(0), 2)
            EVT_CALL(ModifyActorDecoration, -127, 1, 0, 80, LW(0), 0, 0)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(AddActorDecoration, ACTOR_SELF, 2, 0, 1)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(ModifyActorDecoration, -127, 2, 0, 40, 40, 0, 0)
    EVT_CALL(SetPartFlagBits, -127, 2, 1, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartAlpha, -127, 2, 80)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartJumpGravity, -127, 2, EVT_FLOAT(0.1))
    EVT_CALL(JumpPartTo, -127, 2, LW(0), LW(1), LW(2), 10, 1)
    EVT_CALL(SetPartFlagBits, -127, 2, 1, 1)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 10, 16)
    EVT_SWITCH(LW(0))
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
    EVT_CALL(UseBattleCamPreset, 8)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(SetBattleCamOffsetZ, 13)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_15)
    EVT_SET(LW(0), 80)
    EVT_LOOP(30)
        EVT_ADD(LW(0), 2)
        EVT_CALL(ModifyActorDecoration, -127, 1, 0, 80, LW(0), 0, 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 0)
    EVT_WAIT_FRAMES(10000)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 10, 16)
    EVT_SWITCH(LW(0))
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
    EVT_CALL(GetActorVar, -127, 1, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_CALL(GetActorHP, -127, LW(0))
        EVT_IF_LT(LW(0), 0)
            EVT_EXEC_WAIT(N(80230240))
        EVT_ELSE
            EVT_CALL(GetActorHP, 0, LW(0))
            EVT_IF_GT(LW(0), 20)
                EVT_CALL(RandInt, 100, LW(0))
                EVT_SWITCH(LW(0))
                    EVT_CASE_LT(30)
                        EVT_EXEC_WAIT(N(tripleStrike3))
                    EVT_CASE_LT(50)
                        EVT_EXEC_WAIT(N(doubleStrike3))
                    EVT_CASE_DEFAULT
                        EVT_EXEC_WAIT(N(singleStrike3))
                EVT_END_SWITCH
            EVT_ELSE
                EVT_CALL(RandInt, 100, LW(0))
                EVT_SWITCH(LW(0))
                    EVT_CASE_LT(50)
                        EVT_EXEC_WAIT(N(doubleStrike3))
                    EVT_CASE_DEFAULT
                        EVT_EXEC_WAIT(N(singleStrike3))
                EVT_END_SWITCH
            EVT_END_IF
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(RandInt, 100, LW(0))
        EVT_SWITCH(LW(0))
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
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, -127, 0, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_CALL(UseBattleCamPreset, 13)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                EVT_WAIT_FRAMES(10)
                EVT_CALL(ActorSpeak, 131118, -127, 1, 10616841, 10616837)
                EVT_CALL(SetActorVar, -127, 0, 1)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_D)
                EVT_WAIT_FRAMES(15)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_C)
                EVT_WAIT_FRAMES(5)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20B8)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_ADD(LW(1), 20)
                EVT_CALL(PlayEffect, 0x13, 1, LW(0), LW(1), LW(2), EVT_FLOAT(1.0), 30, 0, 0, 0, 0, 0, 0, 0)
                EVT_SET(LW(0), 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_0)
                EVT_LOOP(15)
                    EVT_ADD(LW(0), 24)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LW(0), 0)
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_SET(LW(0), 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_0)
                EVT_LOOP(5)
                    EVT_ADD(LW(0), 18)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LW(0), 0)
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMOKE_BURST)
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                    EVT_ADD(LW(1), 3)
                    EVT_LOOP(3)
                        EVT_CALL(PlayEffect, 0x1, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
                        EVT_WAIT_FRAMES(3)
                    EVT_END_LOOP
                EVT_END_THREAD
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_0)
                EVT_LOOP(5)
                    EVT_ADD(LW(0), 36)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LW(0), 0)
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_1)
                EVT_LOOP(5)
                    EVT_ADD(LW(0), 18)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LW(0), 0)
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_WAIT_FRAMES(15)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022D9EC)))
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_8)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_14)
                EVT_WAIT_FRAMES(2)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 1)
                EVT_WAIT_FRAMES(1)
                EVT_CALL(ModifyActorDecoration, -127, 1, 0, 50, 50, 0, 0)
                EVT_WAIT_FRAMES(15)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
                EVT_CALL(UseBattleCamPreset, 2)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, 131128, -127, 1, 10616842, 10616838)
            EVT_END_IF
        EVT_CASE_EQ(12)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_FLAG(LW(0), 0x351000)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetActorHP, -127, LW(0))
            EVT_CALL(GetEnemyMaxHP, -127, LW(1))
            EVT_DIV(LW(1), 2)
            EVT_IF_LE(LW(0), LW(1))
                EVT_CALL(UseBattleCamPreset, 2)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, 131131, -127, 1, 10616842, 10616838)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetPlayerHP, LW(0))
            EVT_IF_LE(LW(0), 10)
                EVT_CALL(UseBattleCamPreset, 2)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, 131133, -127, 1, 10616842, 10616838)
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
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), 0x351000)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleFlags, LW(0))
    EVT_IF_FLAG(LW(0), 0x240)
        EVT_CALL(GetLastDamage, -127, LW(0))
        EVT_IF_GT(LW(0), 0)
            EVT_CALL(SetActorVar, -127, 2, 1)
            EVT_CALL(AddActorVar, -127, 3, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(10)
        EVT_CASE_OR_EQ(14)
        EVT_CASE_OR_EQ(11)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_CALL(GetActorVar, -127, 2, LW(10))
            EVT_CALL(GetActorVar, -127, 3, LW(11))
            EVT_CALL(SetActorVar, -127, 2, 0)
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
            EVT_IF_EQ(LW(10), 1)
                EVT_IF_GT(LW(11), 2)
                    EVT_CALL(UseBattleCamPreset, 2)
                    EVT_CALL(MoveBattleCamOver, 10)
                    EVT_CALL(ActorSpeak, 131130, -127, 1, 10616842, 10616838)
                    EVT_CALL(SetActorVar, -127, 3, 0)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(UseBattleCamPreset, 2)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, 131129, -127, 1, 10616842, 10616838)
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
