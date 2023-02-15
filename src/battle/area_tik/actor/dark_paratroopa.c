#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/ParaTroopa.h"
#include "sprite/npc/KoopaTroopa.h"
#include "effects.h"

#define NAMESPACE b_area_tik_dark_paratroopa

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(nextTurn);
extern EvtScript N(fall);
extern EvtScript N(init_koopa);
extern EvtScript N(takeTurn_koopa);
extern EvtScript N(idle_koopa);
extern EvtScript N(handleEvent_koopa);

extern s32 N(idleAnimations)[];
extern s32 N(idleAnimations2)[];
extern s32 N(idleAnimations3)[];

s32 N(defenseTable)[] = {
    ELEMENT_NORMAL, 2,
    ELEMENT_SMASH, 2,
    ELEMENT_JUMP, 2,
    ELEMENT_WATER, 2,
    ELEMENT_BLAST, 2,
    ELEMENT_END,
};

s32 N(defenseTable2)[] = {
    ELEMENT_NORMAL, 2,
    ELEMENT_END,
};

s32 N(defenseTable_koopa_flipped)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_koopa)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 80,
    STATUS_POISON, 60,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 50,
    STATUS_FEAR, 0,
    STATUS_STATIC, 80,
    STATUS_PARALYZE, 90,
    STATUS_SHRINK, 75,
    STATUS_STOP, 90,
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

s32 N(statusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 80,
    STATUS_POISON, 60,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 0,
    STATUS_STATIC, 80,
    STATUS_PARALYZE, 90,
    STATUS_SHRINK, 75,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 1,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 36 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -7,
    },
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -4, 36 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations2),
        .defenseTable = N(defenseTable2),
        .eventFlags = ACTOR_EVENT_FLAG_GROUNDABLE,
        .elementImmunityFlags = 0,
        .unk_1C = 2,
        .unk_1D = -14,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 32 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations3),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -10,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_DARK_PARATROOPA,
    .level = 18,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .takeTurnScript = &N(init),
    .statusTable = N(statusTable),
    .escapeChance = 50,
    .airLiftChance = 90,
    .hurricaneChance = 80,
    .spookChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 85,
    .coinReward = 2,
    .size = { 50, 38 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 29 },
    .statusMessageOffset = { 8, 30 },
};

s32 N(idleAnimations2)[] = {
    STATUS_NORMAL, ANIM_ParaTroopa_Dark_Idle,
    STATUS_STONE, ANIM_ParaTroopa_Dark_Still,
    STATUS_SLEEP, ANIM_ParaTroopa_Dark_Sleep,
    STATUS_POISON, ANIM_ParaTroopa_Dark_Still,
    STATUS_STOP, ANIM_ParaTroopa_Dark_Still,
    STATUS_STATIC, ANIM_ParaTroopa_Dark_Idle,
    STATUS_PARALYZE, ANIM_ParaTroopa_Dark_Still,
    STATUS_DIZZY, ANIM_ParaTroopa_Dark_Stunned,
    STATUS_FEAR, ANIM_ParaTroopa_Dark_Stunned,
    STATUS_END,
};

s32 N(idleAnimations_step)[] = {
    STATUS_NORMAL, ANIM_ParaTroopa_Dark_Idle,
    STATUS_STONE, ANIM_ParaTroopa_Dark_Still,
    STATUS_SLEEP, ANIM_ParaTroopa_Dark_Sleep,
    STATUS_POISON, ANIM_ParaTroopa_Dark_Still,
    STATUS_STOP, ANIM_ParaTroopa_Dark_Still,
    STATUS_STATIC, ANIM_ParaTroopa_Dark_Idle,
    STATUS_PARALYZE, ANIM_ParaTroopa_Dark_Still,
    STATUS_DIZZY, ANIM_ParaTroopa_Dark_Stunned,
    STATUS_FEAR, ANIM_ParaTroopa_Dark_Stunned,
    STATUS_END,
};

s32 N(idleAnimations3)[] = {
    STATUS_NORMAL, ANIM_ParaTroopa_Dark_WingsStill,
    STATUS_STONE, ANIM_ParaTroopa_Dark_Still,
    STATUS_SLEEP, ANIM_ParaTroopa_Dark_Sleep,
    STATUS_POISON, ANIM_ParaTroopa_Dark_Still,
    STATUS_STOP, ANIM_ParaTroopa_Dark_Still,
    STATUS_STATIC, ANIM_ParaTroopa_Dark_WingsStill,
    STATUS_PARALYZE, ANIM_ParaTroopa_Dark_Still,
    STATUS_DIZZY, ANIM_ParaTroopa_Dark_Stunned,
    STATUS_FEAR, ANIM_ParaTroopa_Dark_Stunned,
    STATUS_END,
};

EvtScript N(nextTurn) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_RETURN
    EVT_END
};

#include "common/StartRumbleWithParams.inc.c"
#include "common/UnkBattleFunc1.inc.c"

EvtScript N(updateOffsets) = {
    EVT_IF_FLAG(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_DIZZY)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, 0, 25)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 2, 3, -6)
        EVT_CALL(N(UnkBattleFunc1), -19, 25, 4, 28)
    EVT_ELSE
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, -2, 36)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 2, 0, -7)
        EVT_CALL(N(UnkBattleFunc1), -10, 29, 8, 30)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_LABEL(10)
    EVT_CALL(RandInt, 80, LVar0)
    EVT_ADD(LVar0, 80)
    EVT_LOOP(LVar0)
        EVT_LABEL(0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
        EVT_EXEC_WAIT(N(updateOffsets))
        EVT_IF_FLAG(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(0.6))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_PTR(N(idleAnimations_step)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleFlyToGoal, ACTOR_SELF, 0, -5, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations2)))
    EVT_LOOP(20)
        EVT_LABEL(1)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
        EVT_EXEC_WAIT(N(updateOffsets))
        EVT_IF_FLAG(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(0.6))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_PTR(N(idleAnimations_step)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleFlyToGoal, ACTOR_SELF, 0, -5, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_PTR(N(idleAnimations2)))
    EVT_LOOP(40)
        EVT_LABEL(2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
        EVT_EXEC_WAIT(N(updateOffsets))
        EVT_IF_FLAG(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT(1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_Dark_Run)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 11)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_Dark_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_CALL(GetBattlePhase, LVar0)
            EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
                EVT_CALL(GetEncounterState, LVar0)
                EVT_IF_EQ(LVar0, ENCOUNTER_TRIGGER_HAMMER)
                    EVT_EXEC_WAIT(N(fall))
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_HurtStill)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_ParaTroopa_Dark_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_ParaTroopa_Dark_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_BurnStill)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_FALL_TRIGGER)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(fall))
        EVT_CASE_EQ(EVENT_15)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_BurnHurt)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(fall))
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_HurtStill)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_HurtStill)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_ShellEnter)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_ShellEnter)
            EVT_EXEC_WAIT(DoImmune)
            EVT_CALL(GetBattlePhase, LVar0)
            EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
                EVT_CALL(GetEncounterState, LVar0)
                EVT_IF_EQ(LVar0, ENCOUNTER_TRIGGER_HAMMER)
                    EVT_EXEC_WAIT(N(fall))
                EVT_END_IF
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_HurtStill)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_Idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 0)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_Run)
            EVT_SET_CONST(LVar2, ANIM_ParaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_Run)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_F)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_Dark_Run)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 30, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -16, 0)
    EVT_CALL(UseBattleCamPresetImmediately, BTL_CAM_PRESET_B)
    EVT_WAIT(5)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 3, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 1, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_Dark_Windup)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 6, 6, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT(6)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 1, 0, 0)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 25)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_Dark_ShellDive)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 10, 0)
                EVT_SET(LVar0, 0)
                EVT_LOOP(8)
                    EVT_ADD(LVar0, 90)
                    EVT_IF_GE(LVar0, 360)
                        EVT_SUB(LVar0, 360)
                    EVT_END_IF
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, -10, 0)
            EVT_END_THREAD
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_Dark_Hurt)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_Dark_Hurt)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 30)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 2, 0, 2)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 2, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E0)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 1, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_Dark_Windup)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 6, 6, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(6)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 1, 0, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_Dark_ShellDive)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 30, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_Dark_ShellHit)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 10, 0)
                EVT_SET(LVar0, 0)
                EVT_LOOP(12)
                    EVT_SUB(LVar0, 90)
                    EVT_IF_LT(LVar0, 0)
                        EVT_ADD(LVar0, 360)
                    EVT_END_IF
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, -10, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_Dark_Idle)
            EVT_END_THREAD
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 30, 0)
            EVT_WAIT(10)
            EVT_CALL(YieldTurn)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(fall) = {
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 2, 0, 0, 0)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_NO_TARGET)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 3, ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 1, ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_MULTI_TARGET)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 8)
    EVT_SUB(LVar2, 2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_Hurt)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 2, SOUND_301, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, 0)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
        EVT_CALL(N(StartRumbleWithParams), 128, 7)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(0.3))
        EVT_END_THREAD
        EVT_CALL(ResetActorSounds, ACTOR_SELF, 2)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_LOOP(10)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, 0)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
        EVT_THREAD
            EVT_LOOP(10)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 1)
                EVT_WAIT(1)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 1)
        EVT_END_THREAD
        EVT_CALL(N(StartRumbleWithParams), 150, 7)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(0.3))
        EVT_END_THREAD
        EVT_CALL(ResetActorSounds, ACTOR_SELF, 2)
    EVT_END_IF
    EVT_CALL(GetIndexFromHome, ACTOR_SELF, LVar0)
    EVT_MOD(LVar0, 4)
    EVT_CALL(SetGoalToIndex, ACTOR_SELF, LVar0)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_Idle)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 0)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(statusTable_koopa)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, 0)
    EVT_EXEC_WAIT(N(init_koopa))
    EVT_CALL(SetActorType, ACTOR_SELF, ACTOR_TYPE_DARK_KOOPA)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_1000, 1)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_IF_NE(LVarA, 0)
        EVT_CALL(DispatchEvent, ACTOR_SELF, EVENT_FLIP_TRIGGER)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(idleAnimations)[] = {
    STATUS_NORMAL, ANIM_KoopaTroopa_Dark_Idle,
    STATUS_STONE, ANIM_KoopaTroopa_Dark_Still,
    STATUS_SLEEP, ANIM_KoopaTroopa_Dark_Sleep,
    STATUS_POISON, ANIM_KoopaTroopa_Dark_Idle,
    STATUS_STOP, ANIM_KoopaTroopa_Dark_Still,
    STATUS_STATIC, ANIM_KoopaTroopa_Dark_Idle,
    STATUS_PARALYZE, ANIM_KoopaTroopa_Dark_Still,
    STATUS_DIZZY, ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_FEAR, ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_END,
};

s32 N(idleAnimations_koopa_step)[] = {
    STATUS_NORMAL, ANIM_KoopaTroopa_Dark_Walk,
    STATUS_STONE, ANIM_KoopaTroopa_Dark_Still,
    STATUS_SLEEP, ANIM_KoopaTroopa_Dark_Sleep,
    STATUS_POISON, ANIM_KoopaTroopa_Dark_Walk,
    STATUS_STOP, ANIM_KoopaTroopa_Dark_Still,
    STATUS_STATIC, ANIM_KoopaTroopa_Dark_Walk,
    STATUS_PARALYZE, ANIM_KoopaTroopa_Dark_Still,
    STATUS_DIZZY, ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_FEAR, ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_END,
};

s32 N(idleAnimations_koopa_active)[] = {
    STATUS_NORMAL, ANIM_KoopaTroopa_Dark_Scramble,
    STATUS_STONE, ANIM_KoopaTroopa_Dark_Still,
    STATUS_SLEEP, ANIM_KoopaTroopa_Dark_Sleep,
    STATUS_POISON, ANIM_KoopaTroopa_Dark_Scramble,
    STATUS_STOP, ANIM_KoopaTroopa_Dark_Still,
    STATUS_STATIC, ANIM_KoopaTroopa_Dark_Scramble,
    STATUS_PARALYZE, ANIM_KoopaTroopa_Dark_Still,
    STATUS_DIZZY, ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_FEAR, ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_END,
};

s32 N(idleAnimations_koopa_step_active)[] = {
    STATUS_NORMAL, ANIM_KoopaTroopa_Dark_Walk,
    STATUS_STONE, ANIM_KoopaTroopa_Dark_Still,
    STATUS_SLEEP, ANIM_KoopaTroopa_Dark_Sleep,
    STATUS_POISON, ANIM_KoopaTroopa_Dark_Walk,
    STATUS_STOP, ANIM_KoopaTroopa_Dark_Still,
    STATUS_STATIC, ANIM_KoopaTroopa_Dark_Walk,
    STATUS_PARALYZE, ANIM_KoopaTroopa_Dark_Still,
    STATUS_DIZZY, ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_FEAR, ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_END,
};

s32 N(idleAnimations_koopa_flipped)[] = {
    STATUS_NORMAL, ANIM_KoopaTroopa_Dark_ToppleStruggle,
    STATUS_STONE, ANIM_KoopaTroopa_Dark_ToppleStill,
    STATUS_SLEEP, ANIM_KoopaTroopa_Dark_ToppleSleep,
    STATUS_POISON, ANIM_KoopaTroopa_Dark_ToppleStruggle,
    STATUS_STOP, ANIM_KoopaTroopa_Dark_ToppleStill,
    STATUS_STATIC, ANIM_KoopaTroopa_Dark_ToppleStruggle,
    STATUS_PARALYZE, ANIM_KoopaTroopa_Dark_ToppleStill,
    STATUS_DIZZY, ANIM_KoopaTroopa_Dark_ToppleStunned,
    STATUS_FEAR, ANIM_KoopaTroopa_Dark_ToppleStunned,
    STATUS_END,
};

EvtScript N(init_koopa) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_koopa)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_koopa)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_koopa)))
    EVT_CALL(RandInt, 1000, LVar0)
    EVT_IF_LT(LVar0, 300)
        EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_ELSE
        EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_koopa_active)))
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_Scramble)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(updateOffsets_koopa) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(1)
            EVT_IF_FLAG(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_DIZZY)
                EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -5, 15)
                EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 0, 0)
                EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
            EVT_ELSE
                EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -4, 32)
                EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, -1, -4)
                EVT_CALL(N(UnkBattleFunc1), -15, 32, 5, 32)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(3)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -5, 15)
            EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 0, 0)
            EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_koopa) = {
    EVT_LABEL(0)
    EVT_CALL(RandInt, 80, LVarA)
    EVT_ADD(LVarA, 80)
    EVT_LOOP(LVarA)
        EVT_LABEL(1)
        EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
        EVT_EXEC_WAIT(N(updateOffsets_koopa))
        EVT_IF_EQ(LVar0, 2)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_IF_EQ(LVar0, 3)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_IF_FLAG(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_koopa_step)))
        EVT_CASE_EQ(1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_koopa_step_active)))
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleRunToGoal, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations)))
        EVT_CASE_EQ(1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_koopa_active)))
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(3)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_koopa_flipped)))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_LOOP(20)
        EVT_LABEL(2)
        EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
        EVT_EXEC_WAIT(N(updateOffsets_koopa))
        EVT_IF_EQ(LVar0, 2)
            EVT_WAIT(1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_IF_EQ(LVar0, 3)
            EVT_WAIT(1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_IF_FLAG(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT(1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_koopa_step)))
        EVT_CASE_EQ(1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_koopa_step_active)))
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleRunToGoal, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations)))
        EVT_CASE_EQ(1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_koopa_active)))
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(3)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_koopa_flipped)))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_LOOP(50)
        EVT_LABEL(3)
        EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
        EVT_EXEC_WAIT(N(updateOffsets_koopa))
        EVT_IF_EQ(LVar0, 2)
            EVT_WAIT(1)
            EVT_GOTO(3)
        EVT_END_IF
        EVT_IF_EQ(LVar0, 3)
            EVT_WAIT(1)
            EVT_GOTO(3)
        EVT_END_IF
        EVT_IF_FLAG(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT(1)
            EVT_GOTO(3)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
            EVT_THREAD
                EVT_CALL(MakeLerp, 720, 0, 30, 10)
                EVT_LABEL(10)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
                EVT_IF_EQ(LVar1, 1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar2)
                    EVT_IF_EQ(LVar2, 1)
                        EVT_WAIT(1)
                        EVT_GOTO(10)
                    EVT_END_IF
                EVT_END_IF
                EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
                EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_END_THREAD
            EVT_WAIT(8)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 1, 7)
            EVT_WAIT(15)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 1)
            EVT_WAIT(8)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(2)
        EVT_CASE_EQ(3)
    EVT_END_SWITCH
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(bounceTable)[] = { 9, 16, 22, 26, 30, 32, 33, 32, 30, 26, 22, 16, 9, 0, 4, 6, 7, 6, 4, 0, 2, 0, };

EvtScript N(handleEvent_koopa) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_END_IF
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_KoopaTroopa_Dark_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_KoopaTroopa_Dark_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_BurnStill)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 2)
                EVT_CASE_EQ(1)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 3)
            EVT_END_SWITCH
            EVT_CALL(SetActorVar, ACTOR_SELF, 9, 1)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(defenseTable_koopa_flipped)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_koopa_flipped)))
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -5, 15)
            EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 0, 0)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_400, 1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
            EVT_THREAD
                EVT_WAIT(4)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 30)
                EVT_WAIT(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -30)
                EVT_WAIT(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -60)
                EVT_WAIT(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -75)
                EVT_WAIT(1)
            EVT_END_THREAD
            EVT_USE_BUF(N(bounceTable))
            EVT_LOOP(22)
                EVT_BUF_READ1(LVar0)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_ToppleStruggle)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(0.5))
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Run)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(0)
                EVT_CASE_OR_EQ(1)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_ShellEnter)
                    EVT_EXEC_WAIT(DoImmune)
                    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_ShellExit)
                        EVT_WAIT(10)
                    EVT_END_IF
                EVT_END_CASE_GROUP
                EVT_CASE_OR_EQ(2)
                EVT_CASE_OR_EQ(3)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_ToppleStruggle)
                    EVT_EXEC_WAIT(DoImmune)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Run)
                EVT_EXEC_WAIT(DoReturnHome)
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Scramble)
                EVT_EXEC_WAIT(DoRecover)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(0)
                EVT_CASE_OR_EQ(1)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Run)
                    EVT_SET_CONST(LVar2, ANIM_KoopaTroopa_Dark_Hurt)
                    EVT_EXEC_WAIT(DoScareAway)
                    EVT_RETURN
                EVT_END_CASE_GROUP
                EVT_CASE_OR_EQ(2)
                EVT_CASE_OR_EQ(3)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_ToppleStruggle)
                    EVT_EXEC_WAIT(DoImmune)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(0)
                EVT_CASE_OR_EQ(1)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Panic)
                EVT_END_CASE_GROUP
                EVT_CASE_OR_EQ(2)
                EVT_CASE_OR_EQ(3)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_ToppleStruggle)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(0)
                EVT_CASE_OR_EQ(1)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Panic)
                EVT_END_CASE_GROUP
                EVT_CASE_OR_EQ(2)
                EVT_CASE_OR_EQ(3)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_ToppleStruggle)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(0)
                EVT_CASE_OR_EQ(1)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Idle)
                    EVT_EXEC_WAIT(DoImmune)
                EVT_END_CASE_GROUP
                EVT_CASE_OR_EQ(2)
                EVT_CASE_OR_EQ(3)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_ToppleStruggle)
                    EVT_EXEC_WAIT(DoImmune)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(koopa_attackShellToss) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_ShellSpin)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_ShellEnter)
        EVT_WAIT(10)
        EVT_THREAD
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 4)
            EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_WAIT(3)
            EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_WAIT(2)
            EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2021)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_ShellSpin)
        EVT_WAIT(10)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20D3)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, 3, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -40, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_ShellExit)
            EVT_WAIT(8)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_WAIT(4)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_BeginPanic1)
            EVT_WAIT(1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_BeginPanic2)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_Panic)
            EVT_WAIT(6)
            EVT_SUB(LVar1, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_Panic)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_Idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_STATUS_ALWAYS_HITS, SUPPRESS_EVENT_ALL, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_ShellExit)
            EVT_WAIT(8)
            EVT_CALL(YieldTurn)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Run)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_Idle)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(koopa_attackDizzyTornado) = {
    EVT_LABEL(10)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 8, 0, 0)
    EVT_ELSE
        EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 0, 0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_Run)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_Scramble)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_ShellEnter)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 4)
        EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_WAIT(3)
        EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_WAIT(2)
        EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2021)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_ShellSpin)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2026)
    EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 1, 7)
    EVT_WAIT(40)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, 0, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_ShellExit)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 1)
            EVT_WAIT(10)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_Panic)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_Scramble)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_ALL, DMG_STATUS_CHANCE(STATUS_FLAG_DIZZY, 2, 60), 0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_THREAD
                EVT_CALL(WasStatusInflicted, ACTOR_SELF, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(MakeLerp, 0, 1080, 30, 10)
                    EVT_LABEL(0)
                    EVT_CALL(UpdateLerp)
                    EVT_CALL(SetActorYaw, ACTOR_PLAYER, LVar0)
                    EVT_WAIT(1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_GOTO(0)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_THREAD
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_ShellExit)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 1)
            EVT_WAIT(10)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Run)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_Scramble)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(koopa_standUp) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetActorVar, ACTOR_SELF, 9, LVar0)
    EVT_SUB(LVar0, 1)
    EVT_IF_GT(LVar0, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 9, LVar0)
        EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
        EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
        EVT_WAIT(30)
        EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(0.5))
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
    EVT_ELSE
        EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
        EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
        EVT_WAIT(20)
        EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(0.5))
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
        EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 0, 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_JUMP_3E2)
        EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Dark_ToppleStruggle)
        EVT_SET(LVar0, 0)
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
        EVT_THREAD
            EVT_LOOP(5)
                EVT_ADD(LVar0, 15)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BA)
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(defenseTable)))
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -4, 32)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, -1, -4)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_400, 0)
        EVT_CALL(ResetActorSounds, ACTOR_SELF, 2)
        EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(2)
                EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations)))
            EVT_CASE_EQ(3)
                EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_koopa_active)))
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_koopa) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(koopa_attackShellToss))
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 300)
                EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations)))
            EVT_ELSE
                EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_koopa_active)))
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(koopa_attackDizzyTornado))
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 300)
                EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations)))
            EVT_ELSE
                EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(idleAnimations_koopa_active)))
            EVT_END_IF
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(3)
            EVT_EXEC_WAIT(N(koopa_standUp))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

