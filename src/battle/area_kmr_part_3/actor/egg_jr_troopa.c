#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/JrTroopa.h"

#define NAMESPACE b_area_kmr_part_3_egg_jr_troopa

s32 N(idleAnimations_80224380)[] = {
    STATUS_NORMAL,    ANIM_JrTroopa_Anim3,
    STATUS_SLEEP,     ANIM_JrTroopa_Anim1C,
    STATUS_STONE,     ANIM_JrTroopa_Anim0,
    STATUS_POISON,    ANIM_JrTroopa_Anim0,
    STATUS_STOP,      ANIM_JrTroopa_Anim0,
    STATUS_STATIC,    ANIM_JrTroopa_Anim0,
    STATUS_PARALYZE,  ANIM_JrTroopa_Anim0,
    STATUS_END,
};

s32 N(idleAnimations_802243BC)[] = {
    STATUS_NORMAL,   ANIM_JrTroopa_Anim3,
    STATUS_SLEEP,    ANIM_JrTroopa_Anim0,
    STATUS_STONE,    ANIM_JrTroopa_Anim0,
    STATUS_POISON,   ANIM_JrTroopa_Anim0,
    STATUS_STOP,     ANIM_JrTroopa_Anim0,
    STATUS_STATIC,   ANIM_JrTroopa_Anim0,
    STATUS_PARALYZE, ANIM_JrTroopa_Anim0,
    STATUS_END,
};

s32 N(idleAnimations_802243F8)[] = {
    STATUS_NORMAL,    ANIM_JrTroopa_Anim4,
    STATUS_STOP,      ANIM_JrTroopa_Anim2,
    STATUS_END,
};

s32 N(defenseTable_8022440C)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(statusTable_80224418)[] = {
    STATUS_NORMAL, 100,
    STATUS_DEFAULT, 100,
    STATUS_SLEEP, 80,
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

ActorPartBlueprint N(partsTable_802244C4)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -6, 18 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80224380),
        .defenseTable = N(defenseTable_8022440C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 5,
        .unk_1D = 0xFC,
    },
};

extern EvtScript N(init_80224A94);

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_JR_TROOPA2,
    .level = 44,
    .maxHP = 15,
    .partCount = ARRAY_COUNT(N(partsTable_802244C4)),
    .partsData = N(partsTable_802244C4),
    .script = &N(init_80224A94),
    .statusTable = N(statusTable_80224418),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 32, 32 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 30 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(80224510) = {
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

EvtScript N(802245A8) = {
    EVT_CALL(func_802535B4, 1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 12)
    EVT_RETURN
    EVT_END
};

EvtScript N(802245E8) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_55)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

s32 N(idleAnimations_8022464C)[] = {
    STATUS_NORMAL,    ANIM_JrTroopa_Anim14,
    STATUS_END,
};

EvtScript N(80224658) = {
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
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, LVarA, EVT_PTR(N(idleAnimations_8022464C)))
    EVT_WAIT(60)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, 4194304, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(80224964) = {
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CLOSE_SHELL)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 10)
    EVT_ADD(LVar2, 5)
    EVT_CALL(PlayEffect, 0x7, 0, LVar0, LVar1, LVar2, -4, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, 0x7, 0, LVar0, LVar1, LVar2, 4, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim12)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_802243F8)))
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(takeTurn_80225314);
extern EvtScript N(idle_80224B24);
extern EvtScript N(handleEvent_80224B58);
extern EvtScript N(nextTurn_80225B4C);

EvtScript N(init_80224A94) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_80225314)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_80224B24)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80224B58)))
    EVT_CALL(BindNextTurn, -127, EVT_PTR(N(nextTurn_80225B4C)))
    EVT_CALL(SetActorVar, -127, 0, 0)
    EVT_CALL(SetActorVar, -127, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80224B24) = {
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(802250E4);
extern EvtScript N(802251CC);

EvtScript N(handleEvent_80224B58) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(9)
            EVT_EXEC_WAIT(N(802250E4))
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim11)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(10)
            EVT_EXEC_WAIT(N(802250E4))
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim11)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(802251CC))
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim11)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim13)
            EVT_EXEC_WAIT(N(80224658))
            EVT_RETURN
        EVT_CASE_EQ(14)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, 2162728)
            EVT_SET(LVar2, 2162729)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(36)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, 2162728)
            EVT_SET(LVar2, 2162729)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim29)
            EVT_EXEC_WAIT(N(80224658))
            EVT_RETURN
        EVT_CASE_EQ(11)
            EVT_EXEC_WAIT(N(802250E4))
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim11)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_EXEC_WAIT(N(802251CC))
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim11)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim13)
            EVT_EXEC_WAIT(N(80224658))
            EVT_RETURN
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim11)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim11)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim9)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_EXEC_WAIT(N(80224964))
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim11)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim11)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetHomePos, -127, LVar0, LVar1, LVar2)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim13)
            EVT_EXEC_WAIT(N(80224658))
            EVT_RETURN
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
        EVT_CASE_OR_EQ(31)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim4)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(53)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim3)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Anim3)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(802250E4) = {
    EVT_CALL(GetActorVar, -127, 1, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(GetLastDamage, -127, LVar1)
        EVT_CALL(GetBattleFlags, LVar2)
        EVT_IF_NOT_FLAG(LVar2, 0x80000)
            EVT_IF_NE(LVar1, 0)
                EVT_CALL(SetActorVar, -127, 1, 1)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, 0x351000)
                    EVT_CALL(FreezeBattleCam, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802251CC) = {
    EVT_CALL(GetActorVar, -127, 1, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, 0x351000)
            EVT_CALL(SetActorVar, -127, 1, 2)
            EVT_EXEC_WAIT(N(80224510))
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_WAIT(30)
            EVT_CALL(ActorSpeak, 786730, -127, 1, 2162717, 2162717)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim1A)
            EVT_CALL(EndActorSpeech, -127, 1, -1, -1)
            EVT_EXEC_WAIT(N(80224964))
            EVT_EXEC_WAIT(N(802245A8))
        EVT_ELSE
            EVT_CALL(SetActorVar, -127, 1, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(FreezeBattleCam, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80225314) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_OPEN_SHELL)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim3)
    EVT_WAIT(20)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
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
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 2, 16)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(5)
        EVT_CASE_OR_EQ(6)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_AnimF)
            EVT_THREAD
                EVT_WAIT(8)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim10)
            EVT_END_THREAD
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 0)
            EVT_ADD(LVar2, 5)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(2)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim3)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 25)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_AnimB)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim3)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_EXEC_WAIT(N(80224964))
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
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
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 2, 32)
    EVT_SWITCH(LVar0)
        EVT_CASE_DEFAULT
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
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim9)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_Anim3)
            EVT_EXEC_WAIT(N(80224964))
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_80225B4C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, -127, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(SetActorVar, -127, 0, 1)
                EVT_WAIT(15)
                EVT_EXEC_WAIT(N(80224510))
                EVT_WAIT(10)
                EVT_CALL(ActorSpeak, 786728, -127, 1, 2162714, 2162715)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_JrTroopa_AnimB)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20B9)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 16)
                EVT_CALL(PlayEffect, 0x13, 0, LVar0, LVar1, LVar2, 1, 30, 0, 0, 0, 0, 0, 0, 0)
                EVT_CALL(PlayEffect, 0x13, 1, LVar0, LVar1, LVar2, 1, 30, 0, 0, 0, 0, 0, 0, 0)
                EVT_WAIT(30)
                EVT_EXEC_WAIT(N(80224964))
                EVT_WAIT(30)
                EVT_CALL(ActorSpeak, 786729, -127, 1, 2162711, 2162692)
                EVT_WAIT(10)
                EVT_EXEC_WAIT(N(802245A8))
            EVT_ELSE
            EVT_END_IF
        EVT_CASE_EQ(12)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
