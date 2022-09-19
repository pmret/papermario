#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/JrTroopa.h"
#include "sprite/npc/ParaJrTroopa.h"

#define NAMESPACE b_area_kmr_part_3_jr_troopa

s32 N(idleAnimations_802229F0)[] = {
    STATUS_NORMAL,    ANIM_JrTroopa_Anim3,
    STATUS_STONE,     ANIM_JrTroopa_Anim0,
    STATUS_SLEEP,     ANIM_JrTroopa_Anim0,
    STATUS_POISON,    ANIM_JrTroopa_Anim0,
    STATUS_STOP,      ANIM_JrTroopa_Anim0,
    STATUS_STATIC,    ANIM_JrTroopa_Anim0,
    STATUS_PARALYZE,  ANIM_JrTroopa_Anim0,
    STATUS_END,
};

s32 N(defenseTable_80222A2C)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_80222A38)[] = {
    STATUS_NORMAL, 100,
    STATUS_DEFAULT, 100,
    STATUS_SLEEP, 100,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 50,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 100,
    STATUS_STOP, 100,
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

ActorPartBlueprint N(partsTable_80222AE4)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802229F0),
        .defenseTable = N(defenseTable_80222A2C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
};

extern EvtScript N(init_80223180);

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_JR_TROOPA1,
    .level = 41,
    .maxHP = 5,
    .partCount = ARRAY_COUNT(N(partsTable_80222AE4)),
    .partsData = N(partsTable_80222AE4),
    .script = &N(init_80223180),
    .statusTable = N(statusTable_80222A38),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 24, 32 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 30 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(80222B30) = {
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

EvtScript N(80222BC8) = {
    EVT_CALL(func_802535B4, 1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 12)
    EVT_RETURN
    EVT_END
};

EvtScript N(80222C08) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_55)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

s32 N(idleAnimations_80222C6C)[] = {
    STATUS_NORMAL,    ANIM_JrTroopa_Anim14,
    STATUS_END,
};

EvtScript N(80222C78) = {
    EVT_SET(LVarA, LVar0)
    EVT_CALL(func_8027D32C, -127)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVarA, LVar1)
    EVT_WAIT(10)
    EVT_CALL(func_80269E80, LVar5)
    EVT_SWITCH(LVar5)
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
            EVT_SET(LVar2, 0)
            EVT_LOOP(24)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar2)
                EVT_ADD(LVar2, 30)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_END_SWITCH
    EVT_LABEL(0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 10)
    EVT_ADD(LVar2, 10)
    EVT_CALL(PlayEffect, 0x1, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySound, SOUND_DEATH)
    EVT_CALL(DropStarPoints, -127)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(SetBattleCamZoom, 260)
    EVT_CALL(SetBattleCamOffsetZ, 15)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E5)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVarA, 0x210027)
    EVT_WAIT(12)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVarA, 0x210014)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, LVarA, EVT_PTR(N(idleAnimations_80222C6C)))
    EVT_WAIT(30)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_WAIT(15)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 180)
    EVT_WAIT(5)
    EVT_CALL(ActorSpeak, 721076, 256, 0, 10289160, 10289153)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, 4194304, 1)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(takeTurn_802234A4);
extern EvtScript N(handleEvent_80223290);
extern EvtScript N(nextTurn_80223D2C);

EvtScript N(init_80223180) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_802234A4)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80223290)))
    EVT_CALL(BindNextTurn, -127, EVT_PTR(N(nextTurn_80223D2C)))
    EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_CALL(SetActorVar, -127, 1, 0)
    EVT_CALL(SetActorVar, -127, 2, 0)
    EVT_CALL(SetActorVar, -127, 3, 0)
    EVT_CALL(SetActorVar, -127, 4, 1)
    EVT_CALL(SetActorVar, -127, 5, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8022325C) = {
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80223290) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, -127, 2, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(GetLastDamage, -127, LVar1)
        EVT_IF_NE(LVar1, 0)
            EVT_CALL(SetActorVar, -127, 2, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim11)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim11)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim13)
            EVT_EXEC_WAIT(N(80222C78))
            EVT_RETURN
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim3)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_802234A4) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(AddActorVar, -127, 0, 1)
    EVT_CALL(GetActorHP, -127, LVar0)
    EVT_CALL(GetEnemyMaxHP, -127, LVar1)
    EVT_SUB(LVar1, LVar0)
    EVT_IF_EQ(LVar1, 3)
        EVT_CALL(GetActorVar, -127, 5, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(SetActorVar, -127, 5, 1)
            EVT_EXEC_WAIT(N(80222B30))
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_WAIT(20)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
            EVT_CALL(ActorSpeak, 721073, -127, 1, 2162710, 2162691)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim9)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim3)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_AnimE)
    EVT_CALL(SetActorSounds, -127, 2, 8418, 0)
    EVT_CALL(GetActorVar, -127, 4, LVar1)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, LVar1, 16)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(6)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 30)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_SUB(LVar0, 10)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim3)
            EVT_WAIT(8)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim3)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim9)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim3)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_AnimF)
        EVT_WAIT(5)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim10)
    EVT_END_THREAD
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(GetActorVar, -127, 4, LVar1)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, LVar1, 32)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim3)
            EVT_WAIT(10)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim9)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_80223D2C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, -127, 1, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(SetActorVar, -127, 1, 1)
                EVT_WAIT(15)
                EVT_CALL(func_802535B4, 0)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
                EVT_THREAD
                    EVT_SET(LVar1, 0)
                    EVT_WAIT(8)
                    EVT_LOOP(5)
                        EVT_WAIT(1)
                        EVT_SUB(LVar1, 36)
                        EVT_CALL(SetActorYaw, ACTOR_PLAYER, LVar1)
                    EVT_END_LOOP
                EVT_END_THREAD
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim2B)
                EVT_CALL(ActorSpeak, 721071, 256, 0, 10289160, 10289153)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim3)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_NodYes)
                EVT_WAIT(10)
                EVT_THREAD
                    EVT_SET(LVar1, 180)
                    EVT_WAIT(4)
                    EVT_LOOP(5)
                        EVT_WAIT(1)
                        EVT_ADD(LVar1, 36)
                        EVT_CALL(SetActorYaw, ACTOR_PLAYER, LVar1)
                    EVT_END_LOOP
                EVT_END_THREAD
                EVT_WAIT(10)
                EVT_CALL(func_802535B4, 1)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
                EVT_CALL(MoveBattleCamOver, 4)
            EVT_END_IF
        EVT_END_IF
    EVT_CASE_EQ(12)
        EVT_CALL(GetActorVar, -127, 2, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(SetActorVar, -127, 2, 2)
            EVT_EXEC_WAIT(N(80222C08))
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
            EVT_THREAD
                EVT_SET(LVar1, 0)
                EVT_LOOP(5)
                    EVT_WAIT(1)
                    EVT_SUB(LVar1, 36)
                    EVT_CALL(SetActorYaw, ACTOR_PLAYER, LVar1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
            EVT_CALL(ActorSpeak, 721072, 256, 0, 10289160, 10289153)
            EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_ThumbsUp)
            EVT_WAIT(20)
            EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
            EVT_WAIT(4)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        EVT_END_IF
        EVT_CALL(GetActorVar, -127, 3, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(GetActorHP, -127, LVar0)
            EVT_IF_LE(LVar0, 1)
                EVT_CALL(SetActorVar, -127, 3, 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
                EVT_CALL(ActorSpeak, 721074, 256, 0, 10289160, 10289153)
                EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
                EVT_EXEC_WAIT(N(80222B30))
                EVT_CALL(ActorSpeak, 721075, -127, 1, 2162710, 2162691)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20B9)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_AnimB)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 16)
                EVT_CALL(PlayEffect, 0x13, 0, LVar0, LVar1, LVar2, 1, 30, 0, 0, 0, 0, 0, 0, 0)
                EVT_CALL(PlayEffect, 0x13, 1, LVar0, LVar1, LVar2, 1, 30, 0, 0, 0, 0, 0, 0, 0)
                EVT_WAIT(30)
                EVT_WAIT(20)
                EVT_CALL(SetActorVar, -127, 4, 2)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim3)
                EVT_WAIT(20)
            EVT_END_IF
        EVT_END_IF
EVT_END_SWITCH
EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
EVT_RETURN
EVT_END
};
