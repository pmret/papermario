#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/the_master.h"

#define NAMESPACE b_area_mac_master2

s32 N(idleAnimations_8022B640)[] = {
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

s32 N(idleAnimations_8022B68C)[] = {
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

s32 N(defenseTable_8022B6D8)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8022B6E4)[] = {
    STATUS_NORMAL, 50,
    STATUS_DEFAULT, 50,
    STATUS_SLEEP, 30,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 30,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 30,
    STATUS_SHRINK, 40,
    STATUS_STOP, 50,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -2,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, -1,
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, -1,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_8022B790)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 28 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8022B640),
        .defenseTable = N(defenseTable_8022B6D8),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 2,
        .unk_1D = 0xF9,
    },
};

extern EvtScript N(init_8022B7DC);

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_THE_MASTER_2,
    .level = 0,
    .maxHP = 75,
    .partCount = ARRAY_COUNT(N(partsTable_8022B790)),
    .partsData = N(partsTable_8022B790),
    .script = &N(init_8022B7DC),
    .statusTable = N(statusTable_8022B6E4),
    .escapeChance = 100,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 30, 35 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 30 },
    .statusMessageOffset = { 10, 30 },
};

extern EvtScript N(takeTurn_8022CF48);
extern EvtScript N(idle_8022B8B0);
extern EvtScript N(handleEvent_8022D634);
extern EvtScript N(nextTurn_8022CFFC);

EvtScript N(init_8022B7DC) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8022CF48)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8022B8B0)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8022D634)))
    EVT_CALL(BindNextTurn, -127, EVT_ADDR(N(nextTurn_8022CFFC)))
    EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_CALL(SetActorVar, -127, 1, 0)
    EVT_CALL(SetActorVar, -127, 2, 0)
    EVT_CALL(SetActorVar, -127, 3, 2)
    EVT_CALL(SetBattleFlagBits, 8388608, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8022B8B0) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(8022B8C0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_the_master_Palette_00_Anim_16)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_the_master_Palette_00_Anim_1A)
            EVT_SET_CONST(LocalVar(2), NPC_ANIM_the_master_Palette_00_Anim_1B)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_the_master_Palette_00_Anim_1A)
            EVT_SET_CONST(LocalVar(2), NPC_ANIM_the_master_Palette_00_Anim_1B)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_the_master_Palette_00_Anim_18)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_the_master_Palette_00_Anim_16)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_the_master_Palette_00_Anim_16)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_the_master_Palette_00_Anim_16)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_8)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_WAIT(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_6)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_the_master_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_the_master_Palette_00_Anim_16)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_the_master_Palette_00_Anim_18)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_the_master_Palette_00_Anim_16)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_the_master_Palette_00_Anim_18)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_the_master_Palette_00_Anim_16)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_the_master_Palette_00_Anim_18)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(53)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_the_master_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_the_master_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_SET_CONST(LocalVar(0), 0x00000001)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_the_master_Palette_00_Anim_8)
            EVT_SET_CONST(LocalVar(2), NPC_ANIM_the_master_Palette_00_Anim_16)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(singleStrike2) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_8)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.8))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BD)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BD)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_E)
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_F)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BC)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BB)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(10), 0, 0, 0, 16)
    EVT_SWITCH(LocalVar(10))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(EnableActorBlur, -127, 1)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -50, 0, 0)
            EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
            EVT_CALL(EnableActorBlur, -127, 0)
            EVT_WAIT(10)
            EVT_IF_EQ(LocalVar(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
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
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), 0, 0, 0, 8, 48)
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BB)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, -127, 0, 20, 0)
                EVT_SET(LocalVar(0), 0)
                EVT_LOOP(10)
                    EVT_ADD(LocalVar(0), 36)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LocalVar(0))
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_ADD(LocalVar(0), 50)
            EVT_SET(LocalVar(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.2))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_21)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BA)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_23)
            EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
            EVT_WAIT(3)
            EVT_ADD(LocalVar(0), 20)
            EVT_SET(LocalVar(1), 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_21)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3B4)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_23)
            EVT_WAIT(20)
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

EvtScript N(doubleStrike2) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_I)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(SetBattleCamOffsetZ, 13)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_15)
    EVT_WAIT(40)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_H)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3B9)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BB)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(10), 0, 0, 0, 16)
    EVT_SWITCH(LocalVar(10))
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(EnableActorBlur, -127, 1)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -50, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_13)
            EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_3)
            EVT_CALL(EnableActorBlur, -127, 0)
            EVT_WAIT(10)
            EVT_IF_EQ(LocalVar(10), 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
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
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), 0, 0, 0, 5, 16)
    EVT_WAIT(15)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
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
    EVT_WAIT(2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3ED)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BB)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), 0, 0, 0, 6, 32)
    EVT_WAIT(15)
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BB)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, -127, 0, 10, 0)
                EVT_SET(LocalVar(0), 0)
                EVT_LOOP(10)
                    EVT_ADD(LocalVar(0), 36)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LocalVar(0))
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_ADD(LocalVar(0), 50)
            EVT_SET(LocalVar(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_21)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 30, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BA)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_23)
            EVT_CALL(SetActorRotationOffset, -127, 0, 0, 0)
            EVT_WAIT(3)
            EVT_ADD(LocalVar(0), 20)
            EVT_SET(LocalVar(1), 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_21)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3B4)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_23)
            EVT_WAIT(20)
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

EvtScript N(takeTurn_8022CF48) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(RandInt, 100, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_LT(20)
            EVT_EXEC_WAIT(N(doubleStrike2))
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(N(singleStrike2))
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_8022CFFC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, -127, 0, LocalVar(0))
            EVT_IF_EQ(LocalVar(0), 0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                EVT_WAIT(10)
                EVT_CALL(ActorSpeak, 131118, -127, 1, 10616841, 10616837)
                EVT_CALL(SetActorVar, -127, 0, 1)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_D)
                EVT_WAIT(15)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_C)
                EVT_WAIT(5)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20B8)
                EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
                EVT_ADD(LocalVar(1), 20)
                EVT_CALL(PlayEffect, 0x13, 1, LocalVar(0), LocalVar(1), LocalVar(2), EVT_FLOAT(1.0), 30, 0, 0, 0, 0, 0, 0, 0)
                EVT_SET(LocalVar(0), 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_0)
                EVT_LOOP(15)
                    EVT_ADD(LocalVar(0), 24)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LocalVar(0), 0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_SET(LocalVar(0), 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_0)
                EVT_LOOP(5)
                    EVT_ADD(LocalVar(0), 18)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LocalVar(0), 0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMOKE_BURST)
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
                    EVT_ADD(LocalVar(1), 3)
                    EVT_LOOP(3)
                        EVT_CALL(PlayEffect, 0x1, LocalVar(0), LocalVar(1), LocalVar(2), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
                        EVT_WAIT(3)
                    EVT_END_LOOP
                EVT_END_THREAD
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_0)
                EVT_LOOP(5)
                    EVT_ADD(LocalVar(0), 36)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LocalVar(0), 0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_1)
                EVT_LOOP(5)
                    EVT_ADD(LocalVar(0), 18)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LocalVar(0), 0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_WAIT(15)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8022B68C)))
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_8)
                EVT_WAIT(15)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, 131123, -127, 1, 10616842, 10616838)
            EVT_END_IF
        EVT_CASE_EQ(12)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
            EVT_IF_FLAG(LocalVar(0), 0x351000)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetActorHP, -127, LocalVar(0))
            EVT_CALL(GetEnemyMaxHP, -127, LocalVar(1))
            EVT_DIV(LocalVar(1), 2)
            EVT_IF_LE(LocalVar(0), LocalVar(1))
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, 131126, -127, 1, 10616842, 10616838)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetPlayerHP, LocalVar(0))
            EVT_IF_LE(LocalVar(0), 5)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, 131127, -127, 1, 10616842, 10616838)
                EVT_BREAK_SWITCH
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8022D634) = {
    EVT_EXEC_WAIT(N(8022B8C0))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
    EVT_IF_FLAG(LocalVar(0), 0x351000)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleFlags, LocalVar(0))
    EVT_IF_FLAG(LocalVar(0), 0x240)
        EVT_CALL(GetLastDamage, -127, LocalVar(0))
        EVT_IF_GT(LocalVar(0), 0)
            EVT_CALL(SetActorVar, -127, 2, 1)
            EVT_CALL(AddActorVar, -127, 3, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetLastEvent, ACTOR_SELF, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(10)
        EVT_CASE_OR_EQ(14)
        EVT_CASE_OR_EQ(11)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_CALL(GetActorVar, -127, 2, LocalVar(10))
            EVT_CALL(GetActorVar, -127, 3, LocalVar(11))
            EVT_CALL(SetActorVar, -127, 2, 0)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
            EVT_IF_FLAG(LocalVar(0), 0x3F1000)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET(LocalFlag(0), 0)
            EVT_CALL(GetMenuSelection, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_SWITCH(LocalVar(0))
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
            EVT_IF_EQ(LocalVar(10), 1)
                EVT_IF_GT(LocalVar(11), 2)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                    EVT_CALL(MoveBattleCamOver, 10)
                    EVT_CALL(ActorSpeak, 131125, -127, 1, 10616842, 10616838)
                    EVT_CALL(SetActorVar, -127, 3, 0)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, 131124, -127, 1, 10616842, 10616838)
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
