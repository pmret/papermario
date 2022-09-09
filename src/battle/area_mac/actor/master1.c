#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/the_master.h"

#define NAMESPACE b_area_mac_master1

s32 N(idleAnimations_8022A260)[] = {
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

s32 N(defenseTable_8022A2AC)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8022A2B8)[] = {
    STATUS_NORMAL, 50,
    STATUS_DEFAULT, 50,
    STATUS_SLEEP, 40,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 40,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 50,
    STATUS_SHRINK, 60,
    STATUS_STOP, 70,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
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

ActorPartBlueprint N(partsTable_8022A364)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 28 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8022A260),
        .defenseTable = N(defenseTable_8022A2AC),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 2,
        .unk_1D = 0xF9,
    },
};

extern EvtScript N(init_8022A3B0);

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_THE_MASTER_1,
    .level = 0,
    .maxHP = 50,
    .partCount = ARRAY_COUNT(N(partsTable_8022A364)),
    .partsData = N(partsTable_8022A364),
    .script = &N(init_8022A3B0),
    .statusTable = N(statusTable_8022A2B8),
    .escapeChance = 100,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 30, 35 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 30 },
    .statusMessageOffset = { 10, 30 },
};

extern EvtScript N(takeTurn_8022AA54);
extern EvtScript N(idle_8022A494);
extern EvtScript N(handleEvent_8022B2CC);
extern EvtScript N(nextTurn_8022B06C);

EvtScript N(init_8022A3B0) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8022AA54)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8022A494)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8022B2CC)))
    EVT_CALL(BindNextTurn, -127, EVT_PTR(N(nextTurn_8022B06C)))
    EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_CALL(SetActorVar, -127, 1, 0)
    EVT_CALL(SetActorVar, -127, 2, 0)
    EVT_CALL(SetActorVar, -127, 3, 2)
    EVT_SET(GF_FoughtTheMaster, 1)
    EVT_CALL(SetBattleFlagBits, 8388608, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8022A494) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(8022A4A4) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_the_master_Palette_00_Anim_17)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_the_master_Palette_00_Anim_1A)
            EVT_SET_CONST(LVar2, NPC_ANIM_the_master_Palette_00_Anim_1B)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_the_master_Palette_00_Anim_1A)
            EVT_SET_CONST(LVar2, NPC_ANIM_the_master_Palette_00_Anim_1B)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_the_master_Palette_00_Anim_19)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_the_master_Palette_00_Anim_17)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_the_master_Palette_00_Anim_17)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_the_master_Palette_00_Anim_17)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_7)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_WAIT(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_5)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_the_master_Palette_00_Anim_2)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_the_master_Palette_00_Anim_17)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_the_master_Palette_00_Anim_19)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_the_master_Palette_00_Anim_17)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_the_master_Palette_00_Anim_19)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_the_master_Palette_00_Anim_17)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_the_master_Palette_00_Anim_19)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(53)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_the_master_Palette_00_Anim_2)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_the_master_Palette_00_Anim_2)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(57)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, NPC_ANIM_the_master_Palette_00_Anim_7)
            EVT_SET_CONST(LVar2, NPC_ANIM_the_master_Palette_00_Anim_17)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8022AA54) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_7)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.6))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_2)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BB)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20BB)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_10)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_11)
        EVT_WAIT(7)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_12)
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(RunToGoal, ACTOR_SELF, 8, TRUE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 0, 16)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_WAIT(10)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_7)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(RunToGoal, ACTOR_SELF, 10, TRUE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_2)
            EVT_WAIT(3)
            EVT_IF_EQ(LVarA, 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_2)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_7)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_2)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3ED)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 6, 48)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_7)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(RunToGoal, ACTOR_SELF, 10, TRUE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_2)
            EVT_WAIT(20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_2)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_7)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_the_master_Palette_00_Anim_2)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_8022B06C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, -127, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, 131118, -127, 1, 10616841, 10616837)
                EVT_CALL(SetActorVar, -127, 0, 1)
            EVT_END_IF
        EVT_CASE_EQ(12)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, 0x351000)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetActorHP, -127, LVar0)
            EVT_CALL(GetEnemyMaxHP, -127, LVar1)
            EVT_DIV(LVar1, 2)
            EVT_IF_LE(LVar0, LVar1)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, 131121, -127, 1, 10616841, 10616837)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetPlayerHP, LVar0)
            EVT_IF_LE(LVar0, 5)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, 131122, -127, 1, 10616841, 10616837)
                EVT_BREAK_SWITCH
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8022B2CC) = {
    EVT_EXEC_WAIT(N(8022A4A4))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, 0x351000)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleFlags, LVar0)
    EVT_IF_FLAG(LVar0, 0x240)
        EVT_CALL(GetLastDamage, -127, LVar0)
        EVT_IF_GT(LVar0, 0)
            EVT_CALL(SetActorVar, -127, 2, 1)
            EVT_CALL(AddActorVar, -127, 3, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(10)
        EVT_CASE_OR_EQ(14)
        EVT_CASE_OR_EQ(11)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_CALL(GetActorVar, -127, 2, LVarA)
            EVT_CALL(GetActorVar, -127, 3, LVarB)
            EVT_CALL(SetActorVar, -127, 2, 0)
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
                    EVT_CALL(ActorSpeak, 131120, -127, 1, 10616841, 10616837)
                    EVT_CALL(SetActorVar, -127, 3, 0)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, 131119, -127, 1, 10616841, 10616837)
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
