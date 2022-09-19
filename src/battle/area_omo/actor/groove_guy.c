#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/ShyGuy.h"
#include "sprite/npc/MediGuy.h"
#include "sprite/npc/GrooveGuy.h"

#define AREA b_area_omo
#define NAMESPACE A(groove_guy)

extern EvtScript N(init_80224B38);
extern EvtScript N(takeTurn_80226338);
extern EvtScript N(idle_80224B9C);
extern EvtScript N(handleEvent_80224D10);
extern EvtScript N(randomSummon);
extern EvtScript N(80226C00);
extern EvtScript N(80226DEC);
extern EvtScript N(802271A0);
extern Formation N(specialFormation_802273A8);
extern Formation N(specialFormation_802273C4);
extern Formation N(specialFormation_802273E0);

s32 N(idleAnimations_802249E0)[] = {
    STATUS_NORMAL,    ANIM_GrooveGuy_Anim1,
    STATUS_STONE,     ANIM_GrooveGuy_Anim0,
    STATUS_SLEEP,     ANIM_GrooveGuy_Anim6,
    STATUS_POISON,    ANIM_GrooveGuy_Anim1,
    STATUS_STOP,      ANIM_GrooveGuy_Anim0,
    STATUS_STATIC,    ANIM_GrooveGuy_Anim1,
    STATUS_PARALYZE,  ANIM_GrooveGuy_Anim0,
    STATUS_DIZZY,     ANIM_GrooveGuy_Anim7,
    STATUS_FEAR,      ANIM_GrooveGuy_Anim7,
    STATUS_END,
};

s32 N(defenseTable_80224A2C)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_SHOCK, 0,
    ELEMENT_END,
};

s32 N(statusTable_80224A40)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 70,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 50,
    STATUS_FEAR, 100,
    STATUS_STATIC, 50,
    STATUS_PARALYZE, 90,
    STATUS_SHRINK, 75,
    STATUS_STOP, 80,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 1,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

BSS EffectWhirlwindUnk D_802310D0;

ActorPartBlueprint N(partsTable_80224AEC)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802249E0),
        .defenseTable = N(defenseTable_80224A2C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 246,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GROOVE_GUY,
    .level = 15,
    .maxHP = 7,
    .partCount = ARRAY_COUNT(N(partsTable_80224AEC)),
    .partsData = N(partsTable_80224AEC),
    .script = &N(init_80224B38),
    .statusTable = N(statusTable_80224A40),
    .escapeChance = 50,
    .airLiftChance = 85,
    .spookChance = 80,
    .baseStatusChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 2,
    .size = { 28, 28 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(init_80224B38) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_80226338)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_80224B9C)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80224D10)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_RETURN
    EVT_END
};

#include "common/UnkBattleFunc1.inc.c"

EvtScript N(idle_80224B9C) = {
    EVT_LABEL(0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -4, 14)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 0, 0)
        EVT_CALL(N(UnkBattleFunc1), -13, 15, 4, 13)
    EVT_ELSE
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 0, 24)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 0, -10)
        EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80224CAC) = {
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim4)
    EVT_EXEC_WAIT(DoReturnHome)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_Anim1)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80224D10) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim8)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_AnimE)
            EVT_SET_CONST(LVar2, ANIM_GrooveGuy_AnimF)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_AnimE)
            EVT_SET_CONST(LVar2, ANIM_GrooveGuy_AnimF)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_AnimF)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim8)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim8)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim8)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim8)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim8)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(80224CAC))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim8)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim8)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim8)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim8)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim4)
            EVT_SET_CONST(LVar2, ANIM_GrooveGuy_Anim11)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim4)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_OR_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim4)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(basicAttack) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_Anim4)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 751, 0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 8378, 948)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 4, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_Anim10)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_EXEC_WAIT(N(80224CAC))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2EF)
    EVT_END_THREAD
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 8378, 948)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 4, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_Anim10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 10)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 30)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_Anim1)
            EVT_WAIT(8)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_EXEC_WAIT(N(80224CAC))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(sleepySpin) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 8378, 948)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 4, 10, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_Anim10)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 10)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2E2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_AnimC)
    EVT_SET(LVar0, 0)
    EVT_LOOP(30)
        EVT_ADD(LVar0, 48)
        EVT_MOD(LVar0, 360)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_AnimB)
            EVT_WAIT(20)
            EVT_IF_EQ(LVar0, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_EXEC_WAIT(N(80224CAC))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, 0x00000002 | 0x00000010 | STATUS_FLAG_20 | STATUS_FLAG_200 | STATUS_FLAG_DIZZY | STATUS_FLAG_80000000, 0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(WasStatusInflicted, ACTOR_SELF, LVar0)
            EVT_IF_EQ(LVar0, TRUE)
                EVT_THREAD
                    EVT_SET(LVar0, 0)
                    EVT_LOOP(30)
                        EVT_ADD(LVar0, 48)
                        EVT_MOD(LVar0, 360)
                        EVT_CALL(SetActorYaw, ACTOR_PLAYER, LVar0)
                        EVT_WAIT(1)
                    EVT_END_LOOP
                    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2E3)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_AnimB)
            EVT_SET(LVar0, 0)
            EVT_LOOP(15)
                EVT_ADD(LVar0, 24)
                EVT_MOD(LVar0, 360)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_AnimC)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2E4)
            EVT_THREAD
                EVT_SET(LVar0, 0)
                EVT_LOOP(20)
                    EVT_ADD(LVar0, 72)
                    EVT_MOD(LVar0, 360)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
            EVT_END_THREAD
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_AnimA)
            EVT_WAIT(25)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_EXEC_WAIT(N(80224CAC))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(getFirstOpenColumn) = {
    EVT_SET(LocalFlag(1), 0)
    EVT_SET(LocalFlag(2), 0)
    EVT_SET(LocalFlag(3), 0)
    EVT_SET(LocalFlag(4), 0)
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar5)
    EVT_CALL(GetIndexFromHome, LVar0, LVar5)
    EVT_MOD(LVar5, 4)
    EVT_SWITCH(LVar5)
        EVT_CASE_EQ(0)
            EVT_SET(LocalFlag(1), 1)
        EVT_CASE_EQ(1)
            EVT_SET(LocalFlag(2), 1)
        EVT_CASE_EQ(2)
            EVT_SET(LocalFlag(3), 1)
        EVT_CASE_EQ(3)
            EVT_SET(LocalFlag(4), 1)
    EVT_END_SWITCH
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(1), 0)
        EVT_SET(LVarA, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(2), 0)
        EVT_SET(LVarA, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(3), 0)
        EVT_SET(LVarA, 2)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(4), 0)
        EVT_SET(LVarA, 3)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVarA, -1)
    EVT_RETURN
    EVT_END
};

EvtScript N(countActiveSummoners) = {
    EVT_SET(LVar9, 0)
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetOriginalActorType, LVar0, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(ACTOR_TYPE_GROOVE_GUY)
            EVT_CALL(GetStatusFlags, LVar0, LVar3)
            EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(GetActorVar, LVar0, 0, LVar3)
                EVT_IF_NE(LVar3, 2)
                    EVT_ADD(LVar9, 1)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80226338) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 2)
        EVT_CALL(RandInt, 100, LVar0)
        EVT_IF_LT(LVar0, 60)
            EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_DIZZY)
                EVT_EXEC_WAIT(N(basicAttack))
            EVT_ELSE
                EVT_EXEC_WAIT(N(sleepySpin))
            EVT_END_IF
        EVT_ELSE
            EVT_EXEC_WAIT(N(basicAttack))
        EVT_END_IF
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(getFirstOpenColumn))
    EVT_IF_EQ(LVarA, -1)
        EVT_CALL(RandInt, 100, LVar0)
        EVT_IF_LT(LVar0, 60)
            EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_DIZZY)
                EVT_EXEC_WAIT(N(basicAttack))
            EVT_ELSE
                EVT_EXEC_WAIT(N(sleepySpin))
            EVT_END_IF
        EVT_ELSE
            EVT_EXEC_WAIT(N(basicAttack))
        EVT_END_IF
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(countActiveSummoners))
    EVT_SWITCH(LVar9)
        EVT_CASE_EQ(1)
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 300)
                EVT_EXEC_WAIT(N(randomSummon))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 150)
                EVT_EXEC_WAIT(N(randomSummon))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 100)
                EVT_EXEC_WAIT(N(randomSummon))
                EVT_RETURN
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(RandInt, 100, LVar0)
    EVT_IF_LT(LVar0, 60)
        EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
        EVT_IF_FLAG(LVar0, STATUS_FLAG_DIZZY)
            EVT_EXEC_WAIT(N(basicAttack))
        EVT_ELSE
            EVT_EXEC_WAIT(N(sleepySpin))
        EVT_END_IF
    EVT_ELSE
        EVT_EXEC_WAIT(N(basicAttack))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(randomSummon) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_11)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(RandInt, 2, LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(80226C00))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(80226DEC))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(802271A0))
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_802249E0)))
    EVT_RETURN
    EVT_END
};

s32 func_8021878C_512D5C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 x, y, z;
    f32 temp_f20;
    s32 temp_v0;

    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);
    z = evt_get_variable(script, *args++);
    temp_f20 = evt_get_float_variable(script, *args++);
    temp_v0 = evt_get_variable(script, *args++);

    D_802310D0.unk_28 = x;
    D_802310D0.unk_2C = y;
    D_802310D0.unk_30 = z;
    fx_46(6, &D_802310D0, temp_f20, temp_v0);

    return ApiStatus_DONE2;
}

EvtScript N(8022671C) = {
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2E5)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_AnimC)
    EVT_WAIT(4)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2E5)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_AnimB)
    EVT_WAIT(4)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2E5)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_AnimC)
    EVT_WAIT(4)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2E5)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_AnimD)
    EVT_WAIT(4)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2E5)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_AnimC)
    EVT_WAIT(4)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2E5)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_AnimB)
    EVT_WAIT(4)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2E5)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_AnimC)
    EVT_WAIT(4)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2E5)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_AnimD)
    EVT_WAIT(4)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2E5)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_AnimC)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_SETF(LVar3, EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_SETF(LVar3, EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(func_8021878C_512D5C, LVar0, LVar1, LVar2, LVar3, 48)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2E6)
    EVT_SET(LVar0, 0)
    EVT_LOOP(48)
        EVT_ADD(LVar0, 30)
        EVT_IF_GE(LVar0, 360)
            EVT_SUB(LVar0, 360)
        EVT_END_IF
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 30)
    EVT_CALL(PlayEffect, EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 30, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x206D)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GrooveGuy_AnimA)
    EVT_WAIT(8)
    EVT_RETURN
    EVT_END
};

EvtScript N(80226C00) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_EXEC_WAIT(N(8022671C))
    EVT_CALL(SummonEnemy, EVT_PTR(N(specialFormation_802273A8)), 0)
    EVT_SET(LVarB, LVar0)
    EVT_SET(LVar0, 200)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_CALL(SetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, LVarB, 1, ANIM_ShyGuy_Red_Anim4)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetGoalToIndex, LVarB, LVarA)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 8378, 948)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 4, 10, 0)
    EVT_CALL(SetActorSpeed, LVarB, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, LVarB, 0, FALSE)
    EVT_CALL(SetAnimation, LVarB, 1, ANIM_ShyGuy_Red_Anim1)
    EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, LVarB)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80226DEC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_EXEC_WAIT(N(8022671C))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SummonEnemy, EVT_PTR(N(specialFormation_802273C4)), 0)
    EVT_SET(LVarB, LVar0)
    EVT_CALL(SetAnimation, LVarB, 1, ANIM_GrooveGuy_AnimC)
    EVT_CALL(SetGoalToIndex, LVarB, LVarA)
    EVT_CALL(GetGoalPos, LVarB, LVar3, LVar4, LVar5)
    EVT_ADD(LVar3, 200)
    EVT_CALL(SetActorPos, LVarB, LVar3, LVar4, LVar5)
    EVT_THREAD
        EVT_SET(LVar6, 0)
        EVT_LOOP(50)
            EVT_ADD(LVar6, 30)
            EVT_MOD(LVar6, 360)
            EVT_CALL(SetActorYaw, LVarB, LVar6)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorYaw, LVarB, 0)
    EVT_END_THREAD
    EVT_CALL(SetActorSounds, LVarB, 0, 0, 0)
    EVT_THREAD
        EVT_LOOP(2)
            EVT_CALL(PlaySoundAtActor, LVarB, 0x2E2)
            EVT_WAIT(25)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetActorSpeed, LVarB, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, LVarB, 0, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20F3)
    EVT_CALL(SetAnimation, LVarB, 1, ANIM_GrooveGuy_AnimA)
    EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(PlayEffect, EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, LVarB, LVar0, LVar1, LVar2)
    EVT_WAIT(25)
    EVT_CALL(SetAnimation, LVarB, 1, ANIM_GrooveGuy_Anim1)
    EVT_CALL(HPBarToHome, LVarB)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, LVarB, 0, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, LVarB, 0, 2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(802271A0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_EXEC_WAIT(N(8022671C))
    EVT_CALL(SummonEnemy, EVT_PTR(N(specialFormation_802273E0)), 0)
    EVT_SET(LVarB, LVar0)
    EVT_CALL(SetAnimation, LVarB, 1, ANIM_MediGuy_Anim5)
    EVT_ADD(LVarA, 4)
    EVT_CALL(SetGoalToIndex, LVarB, LVarA)
    EVT_CALL(GetGoalPos, LVarB, LVar3, LVar4, LVar5)
    EVT_SET(LVar0, 200)
    EVT_SET(LVar1, LVar4)
    EVT_SET(LVar2, LVar5)
    EVT_CALL(SetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorSounds, LVarB, 0, 896, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, LVarB, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, LVarB, 0, FALSE)
    EVT_CALL(SetAnimation, LVarB, 1, ANIM_MediGuy_Anim1)
    EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, LVarB)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

extern ActorBlueprint A(red_shy_guy);
extern ActorBlueprint A(medi_guy);

Vec3i N(vector3D_8022739C) = { 0, 0xFFFFFC18, 0 };

Formation N(specialFormation_802273A8) = {
    { .actor = &A(red_shy_guy), .home = { .vec = &N(vector3D_8022739C) }, .priority = 100 },
};

Formation N(specialFormation_802273C4) = {
    { .actor = &NAMESPACE, .home = { .vec = &N(vector3D_8022739C) }, .priority = 100 },
};

Formation N(specialFormation_802273E0) = {
    { .actor = &A(medi_guy), .home = { .vec = &N(vector3D_8022739C) }, .priority = 100 },
};
