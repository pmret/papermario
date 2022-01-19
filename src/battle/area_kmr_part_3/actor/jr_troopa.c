#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/jr_troopa.h"
#include "sprite/npc/para_jr_troopa.h"

#define NAMESPACE b_area_kmr_part_3_jr_troopa

s32 N(idleAnimations_802229F0)[] = {
    STATUS_NORMAL,    NPC_ANIM_jr_troopa_default_idle,
    STATUS_STONE,     NPC_ANIM_jr_troopa_default_still,
    STATUS_SLEEP,     NPC_ANIM_jr_troopa_default_still,
    STATUS_POISON,    NPC_ANIM_jr_troopa_default_still,
    STATUS_STOP,      NPC_ANIM_jr_troopa_default_still,
    STATUS_STATIC,    NPC_ANIM_jr_troopa_default_still,
    STATUS_PARALYZE,  NPC_ANIM_jr_troopa_default_still,
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
    .script = N(init_80223180),
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

EvtScript N(80222BC8) = {
    EVT_CALL(func_802535B4, 1)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(MoveBattleCamOver, 12)
    EVT_RETURN
    EVT_END
};

EvtScript N(80222C08) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, 55)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

s32 N(idleAnimations_80222C6C)[] = {
    STATUS_NORMAL,    NPC_ANIM_jr_troopa_default_dead,
    STATUS_END,
};

EvtScript N(80222C78) = {
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
    EVT_CALL(UseBattleCamPreset, 14)
    EVT_CALL(SetBattleCamZoom, 260)
    EVT_CALL(SetBattleCamOffsetZ, 15)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E5)
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(10), 0x210027)
    EVT_WAIT_FRAMES(12)
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(10), 0x210014)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, LW(10), EVT_ADDR(N(idleAnimations_80222C6C)))
    EVT_WAIT_FRAMES(30)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 180)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(ActorSpeak, 721076, 256, 0, 10289160, 10289153)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, 4194304, 1)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(takeTurn_802234A4);
extern EvtScript N(handleEvent_80223290);
extern EvtScript N(nextTurn_80223D2C);

EvtScript N(init_80223180) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_802234A4)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80223290)))
    EVT_CALL(BindNextTurn, -127, EVT_ADDR(N(nextTurn_80223D2C)))
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
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80223290) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, -127, 2, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_CALL(GetLastDamage, -127, LW(1))
        EVT_IF_NE(LW(1), 0)
            EVT_CALL(SetActorVar, -127, 2, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_jr_troopa_default_hurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_jr_troopa_default_hurt_crazy)
            EVT_EXEC_WAIT(N(80222C78))
            EVT_RETURN
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
            EVT_SET_CONST(LW(0), 0x00000001)
            EVT_SET_CONST(LW(1), NPC_ANIM_jr_troopa_default_idle)
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
    EVT_CALL(GetActorHP, -127, LW(0))
    EVT_CALL(GetEnemyMaxHP, -127, LW(1))
    EVT_SUB(LW(1), LW(0))
    EVT_IF_EQ(LW(1), 3)
        EVT_CALL(GetActorVar, -127, 5, LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_CALL(SetActorVar, -127, 5, 1)
            EVT_EXEC_WAIT(N(80222B30))
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
            EVT_CALL(ActorSpeak, 721073, -127, 1, 2162710, 2162691)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, 63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_run)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_idle)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_jump)
    EVT_CALL(SetActorSounds, -127, 2, 8418, 0)
    EVT_CALL(GetActorVar, -127, 4, LW(1))
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, LW(1), 16)
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(6)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 40)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 30)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_SUB(LW(0), 10)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_idle)
            EVT_WAIT_FRAMES(8)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_idle)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_run)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_idle)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_THREAD
        EVT_WAIT_FRAMES(3)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_jump_still)
        EVT_WAIT_FRAMES(5)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_jump_land)
    EVT_END_THREAD
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(GetActorVar, -127, 4, LW(1))
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, LW(1), 32)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_CALL(UseBattleCamPreset, 2)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_idle)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_run)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_idle)
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
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, -127, 1, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_CALL(SetActorVar, -127, 1, 1)
                EVT_WAIT_FRAMES(15)
                EVT_CALL(func_802535B4, 0)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
                EVT_THREAD
                    EVT_SET(LW(1), 0)
                    EVT_WAIT_FRAMES(8)
                    EVT_LOOP(5)
                        EVT_WAIT_FRAMES(1)
                        EVT_SUB(LW(1), 36)
                        EVT_CALL(SetActorYaw, ACTOR_PLAYER, LW(1))
                    EVT_END_LOOP
                EVT_END_THREAD
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_shadowboxing)
                EVT_CALL(ActorSpeak, 721071, 256, 0, 10289160, 10289153)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_idle)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_NOD_YES)
                EVT_WAIT_FRAMES(10)
                EVT_THREAD
                    EVT_SET(LW(1), 180)
                    EVT_WAIT_FRAMES(4)
                    EVT_LOOP(5)
                        EVT_WAIT_FRAMES(1)
                        EVT_ADD(LW(1), 36)
                        EVT_CALL(SetActorYaw, ACTOR_PLAYER, LW(1))
                    EVT_END_LOOP
                EVT_END_THREAD
                EVT_WAIT_FRAMES(10)
                EVT_CALL(func_802535B4, 1)
                EVT_CALL(UseBattleCamPreset, 2)
                EVT_CALL(MoveBattleCamOver, 4)
            EVT_END_IF
        EVT_END_IF
    EVT_CASE_EQ(12)
        EVT_CALL(GetActorVar, -127, 2, LW(0))
        EVT_IF_EQ(LW(0), 1)
            EVT_CALL(SetActorVar, -127, 2, 2)
            EVT_EXEC_WAIT(N(80222C08))
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
            EVT_THREAD
                EVT_SET(LW(1), 0)
                EVT_LOOP(5)
                    EVT_WAIT_FRAMES(1)
                    EVT_SUB(LW(1), 36)
                    EVT_CALL(SetActorYaw, ACTOR_PLAYER, LW(1))
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
            EVT_CALL(ActorSpeak, 721072, 256, 0, 10289160, 10289153)
            EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_THUMBS_UP)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
            EVT_WAIT_FRAMES(4)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        EVT_END_IF
        EVT_CALL(GetActorVar, -127, 3, LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_CALL(GetActorHP, -127, LW(0))
            EVT_IF_LE(LW(0), 1)
                EVT_CALL(SetActorVar, -127, 3, 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
                EVT_CALL(ActorSpeak, 721074, 256, 0, 10289160, 10289153)
                EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
                EVT_EXEC_WAIT(N(80222B30))
                EVT_CALL(ActorSpeak, 721075, -127, 1, 2162710, 2162691)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20B9)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_sprint_crazy)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_ADD(LW(1), 16)
                EVT_CALL(PlayEffect, 0x13, 0, LW(0), LW(1), LW(2), 1, 30, 0, 0, 0, 0, 0, 0, 0)
                EVT_CALL(PlayEffect, 0x13, 1, LW(0), LW(1), LW(2), 1, 30, 0, 0, 0, 0, 0, 0, 0)
                EVT_WAIT_FRAMES(30)
                EVT_WAIT_FRAMES(20)
                EVT_CALL(SetActorVar, -127, 4, 2)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_jr_troopa_default_idle)
                EVT_WAIT_FRAMES(20)
            EVT_END_IF
        EVT_END_IF
EVT_END_SWITCH
EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
EVT_RETURN
EVT_END
};
