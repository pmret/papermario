#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Cleft.h"

#define NAMESPACE b_area_arn_hyper_cleft

extern s32 N(idleAnimations_80221CD4)[];
extern EvtScript N(init_80220CAC);
extern EvtScript N(idle_80221DD0);
extern EvtScript N(handleEvent_80222140);
extern EvtScript N(takeTurn_80221A58);
extern EvtScript N(takeTurn_80223B5C);
extern EvtScript N(nextTurn_80220D3C);
extern EvtScript N(80222F1C);
extern EvtScript N(80223310);

s32 N(defenseTable_80220B40)[] = {
    ELEMENT_NORMAL, 3,
    ELEMENT_FIRE, 99,
    ELEMENT_END,
};

s32 N(defenseTable_80220B54)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_FIRE, 99,
    ELEMENT_END,
};

s32 N(statusTable_80220B68)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 40,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 50,
    STATUS_FEAR, 0,
    STATUS_STATIC, 50,
    STATUS_PARALYZE, 50,
    STATUS_SHRINK, 90,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_80220C14)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 22 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80221CD4),
        .defenseTable = N(defenseTable_80220B40),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP,
        .elementImmunityFlags = 0,
        .unk_1D = 246,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_HYPER_CLEFT,
    .level = 15,
    .maxHP = 4,
    .partCount = ARRAY_COUNT(N(partsTable_80220C14)),
    .partsData = N(partsTable_80220C14),
    .script = &N(init_80220CAC),
    .statusTable = N(statusTable_80220B68),
    .escapeChance = 70,
    .airLiftChance = 30,
    .spookChance = 30,
    .baseStatusChance = 30,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 95,
    .coinReward = 2,
    .size = { 44, 36 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(idleAnimations_80220C60)[] = {
    STATUS_NORMAL,    ANIM_Cleft_Hyper_Anim4,
    STATUS_STONE,     ANIM_Cleft_Hyper_Anim0,
    STATUS_SLEEP,     ANIM_Cleft_Hyper_AnimC,
    STATUS_POISON,    ANIM_Cleft_Hyper_Anim4,
    STATUS_STOP,      ANIM_Cleft_Hyper_Anim0,
    STATUS_STATIC,    ANIM_Cleft_Hyper_Anim4,
    STATUS_PARALYZE,  ANIM_Cleft_Hyper_Anim0,
    STATUS_DIZZY,     ANIM_Cleft_Hyper_AnimE,
    STATUS_FEAR,      ANIM_Cleft_Hyper_AnimE,
    STATUS_END,
};

EvtScript N(init_80220CAC) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_80221DD0)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80222140)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_80221A58)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn_80220D3C)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_80220D3C) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_END)
            EVT_CALL(SetBattleVar, 1, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(80220DC0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_POWER_UP)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 10)
        EVT_CALL(PlayEffect, EFFECT_ENERGY_IN_OUT, 6, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 45, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim4)
        EVT_WAIT(30)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
        EVT_CALL(N(StartRumbleWithParams), 200, 10)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.5))
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2D9)
        EVT_CALL(PlayEffect, EFFECT_LANDING_DUST, 4, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
        EVT_END_THREAD
        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 2)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80220C60)))
        EVT_CALL(EnableActorGlow, ACTOR_SELF, TRUE)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_400000, 1)
        EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_LOOP(20)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, 1, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2DA)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 3, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_THREAD
                EVT_LOOP(0)
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_ADD(LVar0, 30)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
                    EVT_IF_GT(LVar0, LVar3)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_B)
                EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_END_IF
                EVT_WAIT(15)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_END_THREAD
            EVT_THREAD
                EVT_LOOP(30)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(PlayEffect, EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim11)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -200, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(12.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_WAIT(15)
            EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_400000, 0)
            EVT_CALL(YieldTurn)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorPos, ACTOR_SELF, 300, 0, 0)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim7)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim2)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80221CD4)))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_LOOP(25)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(PlayEffect, EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim11)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(12.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 8, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                EVT_SET(LVar0, 0)
                EVT_LOOP(60)
                    EVT_ADD(LVar0, 18)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 50)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 30, FALSE, TRUE, FALSE)
            EVT_SUB(LVar0, 40)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
            EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_400000, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim7)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim2)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80221CD4)))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80221A58) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetBattleVar, 1, 1)
        EVT_EXEC_WAIT(N(80223310))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(80222F1C))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 2)
        EVT_EXEC_WAIT(N(80220DC0))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleVar, 1, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LT(LVar0, 750)
                    EVT_CALL(SetBattleVar, 1, 2)
                    EVT_EXEC_WAIT(N(80220DC0))
                EVT_ELSE
                    EVT_CALL(SetBattleVar, 1, 1)
                    EVT_EXEC_WAIT(N(80223310))
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LT(LVar0, 500)
                    EVT_CALL(SetBattleVar, 1, 2)
                    EVT_EXEC_WAIT(N(80220DC0))
                EVT_ELSE
                    EVT_CALL(SetBattleVar, 1, 1)
                    EVT_EXEC_WAIT(N(80223310))
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(80223310))
            EVT_RETURN
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(80220DC0))
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(idleAnimations_80221CD4)[] = {
    STATUS_NORMAL,    ANIM_Cleft_Hyper_Anim2,
    STATUS_STONE,     ANIM_Cleft_Hyper_Anim0,
    STATUS_SLEEP,     ANIM_Cleft_Hyper_AnimC,
    STATUS_POISON,    ANIM_Cleft_Hyper_Anim2,
    STATUS_STOP,      ANIM_Cleft_Hyper_Anim0,
    STATUS_STATIC,    ANIM_Cleft_Hyper_Anim2,
    STATUS_PARALYZE,  ANIM_Cleft_Hyper_Anim0,
    STATUS_DIZZY,     ANIM_Cleft_Hyper_AnimE,
    STATUS_FEAR,      ANIM_Cleft_Hyper_AnimE,
    STATUS_END,
};

s32 N(idleAnimations_80221D20)[] = {
    STATUS_NORMAL,    ANIM_Cleft_Hyper_Anim5,
    STATUS_STONE,     ANIM_Cleft_Hyper_Anim1,
    STATUS_SLEEP,     ANIM_Cleft_Hyper_AnimD,
    STATUS_POISON,    ANIM_Cleft_Hyper_Anim5,
    STATUS_STOP,      ANIM_Cleft_Hyper_Anim1,
    STATUS_STATIC,    ANIM_Cleft_Hyper_Anim5,
    STATUS_PARALYZE,  ANIM_Cleft_Hyper_Anim1,
    STATUS_DIZZY,     ANIM_Cleft_Hyper_AnimF,
    STATUS_FEAR,      ANIM_Cleft_Hyper_AnimF,
    STATUS_END,
};

EvtScript N(80221D6C) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_80221DD0)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_80223B5C)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80222140)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80221DD0) = {
    EVT_RETURN
    EVT_END
};

#include "common/SetSpinSmashable.inc.c"

EvtScript N(80221DE0) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim7)
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(5)
            EVT_ADD(LVar0, -36)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.3))
    EVT_SUB(LVar1, 6)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    EVT_CALL(N(StartRumbleWithParams), 200, 10)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 40, 8, EVT_FLOAT(0.0), 20, 0, 0, 0, 0, 0)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, 0, LVar2)
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim3)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80221D20)))
    EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(defenseTable_80220B54)))
    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 0, 15)
    EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 0, -7)
    EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_SPIKY_TOP, 0)
    EVT_CALL(N(SetSpinSmashable), 0)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_400, 1)
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
    EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_400000, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80222140) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_CALL(GetLastElement, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_FLAG(DAMAGE_TYPE_BLAST)
                    EVT_EXEC_WAIT(N(80221DE0))
                EVT_CASE_DEFAULT
                    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
                    EVT_IF_EQ(LVar0, 1)
                        EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim9)
                    EVT_ELSE
                        EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim8)
                    EVT_END_IF
                    EVT_SET_CONST(LVar0, 1)
                    EVT_EXEC_WAIT(DoNormalHit)
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetLastElement, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_FLAG(DAMAGE_TYPE_BLAST)
                    EVT_EXEC_WAIT(N(80221DE0))
                EVT_CASE_DEFAULT
                    EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_EXPLOSIVE, 1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
                    EVT_IF_EQ(LVar0, 1)
                        EVT_SET_CONST(LVar0, 1)
                        EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim9)
                        EVT_SET_CONST(LVar2, -1)
                        EVT_EXEC_WAIT(DoBurnHit)
                    EVT_ELSE
                        EVT_SET_CONST(LVar0, 1)
                        EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim8)
                        EVT_SET_CONST(LVar2, -1)
                        EVT_EXEC_WAIT(DoBurnHit)
                    EVT_END_IF
                    EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_EXPLOSIVE, 0)
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim9)
                EVT_SET_CONST(LVar2, -1)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim9)
                EVT_EXEC_WAIT(DoDeath)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim8)
                EVT_SET_CONST(LVar2, -1)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim8)
                EVT_EXEC_WAIT(DoDeath)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim9)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim8)
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim9)
                EVT_EXEC_WAIT(DoSpinSmashHit)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim9)
                EVT_EXEC_WAIT(DoDeath)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim8)
                EVT_EXEC_WAIT(DoSpinSmashHit)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim8)
                EVT_EXEC_WAIT(DoDeath)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_400000, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80221CD4)))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim8)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim8)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim7)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_400000, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80221CD4)))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim8)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim8)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_STAR_BEAM)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 2)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
                EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_400000, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80221CD4)))
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim3)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim2)
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim18)
            EVT_END_IF
            EVT_WAIT(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_ADD(LVar0, -3)
                EVT_ADD(LVar1, 10)
            EVT_ELSE
                EVT_ADD(LVar0, -8)
                EVT_ADD(LVar1, 27)
            EVT_END_IF
            EVT_CALL(PlayEffect, EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 20, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(20)
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim3)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim2)
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim9)
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_WAIT(10)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim9)
                EVT_EXEC_WAIT(DoDeath)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim8)
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_WAIT(10)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim8)
                EVT_EXEC_WAIT(DoDeath)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim2)
                EVT_EXEC_WAIT(DoRecover)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim3)
                EVT_EXEC_WAIT(DoImmune)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim7)
                EVT_SET_CONST(LVar2, ANIM_Cleft_Hyper_Anim8)
                EVT_EXEC_WAIT(DoScareAway)
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_AnimF)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_AnimF)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Cleft_Hyper_Anim8)
            EVT_END_IF
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80222F1C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
    EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(3.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim3)
    EVT_WAIT(20)
    EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim5)
    EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_IF_GT(LVar0, 0)
        EVT_SUB(LVar0, 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_ELSE
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim3)
        EVT_THREAD
            EVT_WAIT(3)
            EVT_LOOP(5)
                EVT_ADD(LVar0, 36)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar1, 6)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.3))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
        EVT_CALL(N(StartRumbleWithParams), 200, 10)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
        EVT_END_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, 0, LVar2)
        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim2)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_80221CD4)))
        EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(defenseTable_80220B40)))
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 0, 22)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 0, -10)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_SPIKY_TOP, 1)
        EVT_WAIT(1)
        EVT_CALL(N(SetSpinSmashable), 1)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_400, 0)
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80223310) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_WAIT(10)
        EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_WAIT(5)
        EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim10)
    EVT_WAIT(10)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim11)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, -5)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim0)
    EVT_WAIT(8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20D1)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 3, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_THREAD
                    EVT_WAIT(10)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim11)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 100)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 1, 0, 0, 45)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim8)
            EVT_WAIT(15)
            EVT_WAIT(8)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 1, 0, 0, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim7)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim2)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim11)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim2)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 15)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.4))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim2)
            EVT_WAIT(5)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim7)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Cleft_Hyper_Anim2)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80223B5C) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(80222F1C))
    EVT_ELSE
        EVT_EXEC_WAIT(N(80223310))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
