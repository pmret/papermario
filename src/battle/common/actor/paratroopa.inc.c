#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/KoopaTroopa.h"
#include "sprite/npc/ParaTroopa.h"

s32 N(DefenseTable_8021EAD0)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_SMASH, 1,
    ELEMENT_JUMP, 1,
    ELEMENT_WATER, 1,
    ELEMENT_BLAST, 1,
    ELEMENT_END,
};

s32 N(DefenseTable_8021EAFC)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(DefenseTable_8021EB08)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable_8021EB14)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 90,
    STATUS_POISON, 60,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 0,
    STATUS_STATIC, 80,
    STATUS_PARALYZE, 90,
    STATUS_SHRINK, 90,
    STATUS_STOP, 100,
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

s32 N(StatusTable_8021EBC0)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 90,
    STATUS_POISON, 60,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 0,
    STATUS_STATIC, 80,
    STATUS_PARALYZE, 90,
    STATUS_SHRINK, 90,
    STATUS_STOP, 100,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 1,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

extern s32 N(IdleAnimations_80220AA0)[];
extern s32 N(IdleAnimations_8021ED00)[];
extern s32 N(IdleAnimations_8021ED98)[];
extern EvtScript N(init_8021EE0C);

ActorPartBlueprint N(PartsTable_8021EC6C)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 36 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80220AA0),
        .defenseTable = N(DefenseTable_8021EAD0),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -7 },
    },
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -4, 36 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8021ED00),
        .defenseTable = N(DefenseTable_8021EAFC),
        .eventFlags = ACTOR_EVENT_FLAG_GROUNDABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 2, -14 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 32 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8021ED98),
        .defenseTable = N(DefenseTable_8021EAD0),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_PARATROOPA,
    .level = 6,
    .maxHP = 4,
    .partCount = ARRAY_COUNT( N(PartsTable_8021EC6C)),
    .partsData = N(PartsTable_8021EC6C),
    .initScript = &N(init_8021EE0C),
    .statusTable = N(StatusTable_8021EBC0),
    .escapeChance = 60,
    .airLiftChance = 95,
    .hurricaneChance = 100,
    .spookChance = 90,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 50, 38 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 29 },
    .statusMessageOffset = { 8, 30 },
};

s32 N(IdleAnimations_8021ED00)[] = {
    STATUS_NORMAL,    ANIM_ParaTroopa_Idle,
    STATUS_STONE,     ANIM_ParaTroopa_Still,
    STATUS_SLEEP,     ANIM_ParaTroopa_Sleep,
    STATUS_POISON,    ANIM_ParaTroopa_Still,
    STATUS_STOP,      ANIM_ParaTroopa_Still,
    STATUS_STATIC,    ANIM_ParaTroopa_Idle,
    STATUS_PARALYZE,  ANIM_ParaTroopa_Still,
    STATUS_DIZZY,     ANIM_ParaTroopa_Stunned,
    STATUS_FEAR,      ANIM_ParaTroopa_Stunned,
    STATUS_END,
};

s32 N(IdleAnimations_8021ED4C)[] = {
    STATUS_NORMAL,    ANIM_ParaTroopa_Idle,
    STATUS_STONE,     ANIM_ParaTroopa_Still,
    STATUS_SLEEP,     ANIM_ParaTroopa_Sleep,
    STATUS_POISON,    ANIM_ParaTroopa_Still,
    STATUS_STOP,      ANIM_ParaTroopa_Still,
    STATUS_STATIC,    ANIM_ParaTroopa_Idle,
    STATUS_PARALYZE,  ANIM_ParaTroopa_Still,
    STATUS_DIZZY,     ANIM_ParaTroopa_Stunned,
    STATUS_FEAR,      ANIM_ParaTroopa_Stunned,
    STATUS_END,
};

s32 N(IdleAnimations_8021ED98)[] = {
    STATUS_NORMAL,    ANIM_ParaTroopa_WingsStill,
    STATUS_STONE,     ANIM_ParaTroopa_Still,
    STATUS_SLEEP,     ANIM_ParaTroopa_Sleep,
    STATUS_POISON,    ANIM_ParaTroopa_Still,
    STATUS_STOP,      ANIM_ParaTroopa_Still,
    STATUS_STATIC,    ANIM_ParaTroopa_WingsStill,
    STATUS_PARALYZE,  ANIM_ParaTroopa_Still,
    STATUS_DIZZY,     ANIM_ParaTroopa_Stunned,
    STATUS_FEAR,      ANIM_ParaTroopa_Stunned,
    STATUS_END,
};

EvtScript N(nextTurn_8021EDE4) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(takeTurn_8021FA24);
extern EvtScript N(idle_8021EF5C);
extern EvtScript N(handleEvent_8021F2EC);

EvtScript N(init_8021EE0C) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8021FA24)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8021EF5C)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021F2EC)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn_8021EDE4)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_RETURN
    EVT_END
};

#include "common/StartRumbleWithParams.inc.c"

#include "common/UnkBattleFunc1.inc.c"

EvtScript N(8021EE84) = {
    EVT_IF_FLAG(LVar1, 0x00041000)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, 0, 25)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 2, 3, -6)
        EVT_CALL(N(UnkBattleFunc1), -19, 25, 4, 28)
    EVT_ELSE
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, -2, 36)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 2, 0, -7)
        EVT_CALL(N(UnkBattleFunc1), -10, 29, 8, 30)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8021EF5C) = {
    EVT_LABEL(10)
    EVT_CALL(RandInt, 80, LVar0)
    EVT_ADD(LVar0, 80)
    EVT_LOOP(LVar0)
        EVT_LABEL(0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
        EVT_EXEC_WAIT(N(8021EE84))
        EVT_IF_FLAG(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(0.6))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_PTR(N(IdleAnimations_8021ED4C)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleFlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_8021ED00)))
    EVT_LOOP(20)
        EVT_LABEL(1)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
        EVT_EXEC_WAIT(N(8021EE84))
        EVT_IF_FLAG(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(0.6))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_PTR(N(IdleAnimations_8021ED4C)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleFlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_PTR(N(IdleAnimations_8021ED00)))
    EVT_LOOP(40)
        EVT_LABEL(2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
        EVT_EXEC_WAIT(N(8021EE84))
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

EvtScript N(8021F26C) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_Run)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_SIN_OUT)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_Idle)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(802204DC);

EvtScript N(handleEvent_8021F2EC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Hurt)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Hurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_CALL(GetBattlePhase, LVar0)
            EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
                EVT_CALL(GetEncounterState, LVar0)
                EVT_IF_EQ(LVar0, 4)
                    EVT_EXEC_WAIT(N(802204DC))
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_HurtStill)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_ParaTroopa_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_ParaTroopa_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_BurnStill)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_FALL_TRIGGER)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Hurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(802204DC))
        EVT_CASE_EQ(EVENT_15)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_BurnHurt)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(802204DC))
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_HurtStill)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(8021F26C))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_HurtStill)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_ShellEnter)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_ShellEnter)
            EVT_EXEC_WAIT(DoImmune)
            EVT_CALL(GetBattlePhase, LVar0)
            EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
                EVT_CALL(GetEncounterState, LVar0)
                EVT_IF_EQ(LVar0, 4)
                    EVT_EXEC_WAIT(N(802204DC))
                EVT_END_IF
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Hurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_HurtStill)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(8021F26C))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Run)
            EVT_SET_CONST(LVar2, ANIM_ParaTroopa_Hurt)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Run)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 2)
            EVT_SET_CONST(LVar1, ANIM_ParaTroopa_Hurt)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021FA24) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_F)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_Run)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 30, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -16, EASING_LINEAR)
    EVT_CALL(UseBattleCamPresetImmediately, BTL_CAM_PRESET_B)
    EVT_WAIT(5)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_0, SOUND_0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_Windup)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 6, 6, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, EASING_LINEAR)
            EVT_WAIT(6)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_0, SOUND_0)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 25)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_ShellDive)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, EASING_LINEAR)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_Hurt)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_Hurt)
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
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 2, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_EXEC_WAIT(N(8021F26C))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 2, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E0)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_0, SOUND_0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_Windup)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 6, 6, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, EASING_LINEAR)
    EVT_WAIT(6)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_UNUSED_2C1)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_0, SOUND_0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_ShellDive)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, EASING_LINEAR)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 40, 30, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_ShellHit)
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
                EVT_CALL(SetAnimation, ACTOR_SELF, 2, ANIM_ParaTroopa_Idle)
            EVT_END_THREAD
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 30, EASING_LINEAR)
            EVT_WAIT(10)
            EVT_CALL(YieldTurn)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_EXEC_WAIT(N(8021F26C))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(80220B84);

EvtScript N(802204DC) = {
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, 2, 0, 0, 0)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_NO_TARGET)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 3, ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 1, ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_MULTI_TARGET)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 8)
    EVT_SUB(LVar2, 2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Hurt)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_301, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, 0)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
        EVT_CALL(N(StartRumbleWithParams), 128, 7)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(0.3))
        EVT_END_THREAD
        EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_LOOP(10)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, 0)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
        EVT_THREAD
            EVT_LOOP(10)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                EVT_WAIT(1)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_END_THREAD
        EVT_CALL(N(StartRumbleWithParams), 150, 7)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(0.3))
        EVT_END_THREAD
        EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
    EVT_END_IF
    EVT_CALL(GetIndexFromHome, ACTOR_SELF, LVar0)
    EVT_MOD(LVar0, 4)
    EVT_CALL(SetGoalToIndex, ACTOR_SELF, LVar0)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Idle)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable_8021EB14)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, 0)
    EVT_EXEC_WAIT(N(80220B84))
    EVT_CALL(SetActorType, ACTOR_SELF, ACTOR_TYPE_KOOPA_TROOPA)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TYPE_CHANGED, TRUE)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_IF_NE(LVarA, 0)
        EVT_CALL(DispatchEvent, ACTOR_SELF, EVENT_FLIP_TRIGGER)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(IdleAnimations_80220AA0)[] = {
    STATUS_NORMAL,    ANIM_KoopaTroopa_Idle,
    STATUS_STONE,     ANIM_KoopaTroopa_Still,
    STATUS_SLEEP,     ANIM_KoopaTroopa_Sleep,
    STATUS_POISON,    ANIM_KoopaTroopa_Idle,
    STATUS_STOP,      ANIM_KoopaTroopa_Still,
    STATUS_STATIC,    ANIM_KoopaTroopa_Idle,
    STATUS_PARALYZE,  ANIM_KoopaTroopa_Still,
    STATUS_DIZZY,     ANIM_KoopaTroopa_Stunned,
    STATUS_FEAR,      ANIM_KoopaTroopa_Stunned,
    STATUS_END,
};

s32 N(IdleAnimations_80220AEC)[] = {
    STATUS_NORMAL,    ANIM_KoopaTroopa_Walk,
    STATUS_STONE,     ANIM_KoopaTroopa_Still,
    STATUS_SLEEP,     ANIM_KoopaTroopa_Sleep,
    STATUS_POISON,    ANIM_KoopaTroopa_Walk,
    STATUS_STOP,      ANIM_KoopaTroopa_Still,
    STATUS_STATIC,    ANIM_KoopaTroopa_Walk,
    STATUS_PARALYZE,  ANIM_KoopaTroopa_Still,
    STATUS_DIZZY,     ANIM_KoopaTroopa_Stunned,
    STATUS_FEAR,      ANIM_KoopaTroopa_Stunned,
    STATUS_END,
};

s32 N(IdleAnimations_80220B38)[] = {
    STATUS_NORMAL,    ANIM_KoopaTroopa_ToppleStruggle,
    STATUS_STONE,     ANIM_KoopaTroopa_ToppleStill,
    STATUS_SLEEP,     ANIM_KoopaTroopa_ToppleSleep,
    STATUS_POISON,    ANIM_KoopaTroopa_ToppleStruggle,
    STATUS_STOP,      ANIM_KoopaTroopa_ToppleStill,
    STATUS_STATIC,    ANIM_KoopaTroopa_ToppleStruggle,
    STATUS_PARALYZE,  ANIM_KoopaTroopa_ToppleStill,
    STATUS_DIZZY,     ANIM_KoopaTroopa_ToppleStunned,
    STATUS_FEAR,      ANIM_KoopaTroopa_ToppleStunned,
    STATUS_END,
};

extern EvtScript N(takeTurn_80221DAC);
extern EvtScript N(idle_80220D40);
extern EvtScript N(handleEvent_80221228);

EvtScript N(80220B84) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_80221DAC)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_80220D40)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80221228)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80220BE8) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_IF_FLAG(LVar1, 0x00041000)
                EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -5, 15)
                EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, 0, 0)
                EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
            EVT_ELSE
                EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -4, 32)
                EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, -1, -4)
                EVT_CALL(N(UnkBattleFunc1), -15, 32, 5, 32)
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -5, 15)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, 0, 0)
            EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80220D40) = {
    EVT_LABEL(0)
    EVT_CALL(RandInt, 80, LVarA)
    EVT_ADD(LVarA, 80)
    EVT_LOOP(LVarA)
        EVT_LABEL(1)
        EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
        EVT_EXEC_WAIT(N(80220BE8))
        EVT_IF_EQ(LVar0, 1)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_IF_FLAG(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80220AEC)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleRunToGoal, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80220AA0)))
        EVT_CASE_EQ(1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80220B38)))
    EVT_END_SWITCH
    EVT_LOOP(20)
        EVT_LABEL(2)
        EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
        EVT_EXEC_WAIT(N(80220BE8))
        EVT_IF_EQ(LVar0, 1)
            EVT_WAIT(1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_IF_FLAG(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT(1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80220AEC)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleRunToGoal, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80220AA0)))
        EVT_CASE_EQ(1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80220B38)))
    EVT_END_SWITCH
    EVT_LOOP(80)
        EVT_LABEL(3)
        EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
        EVT_EXEC_WAIT(N(80220BE8))
        EVT_IF_EQ(LVar0, 1)
            EVT_WAIT(1)
            EVT_GOTO(3)
        EVT_END_IF
        EVT_IF_FLAG(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT(1)
            EVT_GOTO(3)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(intTable_802211D0)[] = {
    0x00000009, 0x00000010, 0x00000016, 0x0000001A, 0x0000001E, 0x00000020, 0x00000021, 0x00000020,
    0x0000001E, 0x0000001A, 0x00000016, 0x00000010, 0x00000009, 0x00000000, 0x00000004, 0x00000006,
    0x00000007, 0x00000006, 0x00000004, 0x00000000, 0x00000002, 0x00000000,
};

EvtScript N(handleEvent_80221228) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Hurt)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_KoopaTroopa_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_KoopaTroopa_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_BurnStill)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Hurt)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 9, 2)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(DefenseTable_8021EB08)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80220B38)))
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -5, 15)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, 0, 0)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Hurt)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
            EVT_CHILD_THREAD
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
            EVT_END_CHILD_THREAD
            EVT_USE_BUF(EVT_PTR(N(intTable_802211D0)))
            EVT_LOOP(22)
                EVT_BUF_READ1(LVar0)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_ToppleStruggle)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Hurt)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Run)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Hurt)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Hurt)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_ShellEnter)
                EVT_EXEC_WAIT(DoImmune)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_ShellExit)
                    EVT_WAIT(10)
                EVT_END_IF
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_ToppleStruggle)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Hurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Hurt)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Run)
                EVT_EXEC_WAIT(DoReturnHome)
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Idle)
                EVT_EXEC_WAIT(DoRecover)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_ToppleStruggle)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Run)
                EVT_SET_CONST(LVar2, ANIM_KoopaTroopa_Hurt)
                EVT_EXEC_WAIT(DoScareAway)
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_ToppleStruggle)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Panic)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_ToppleStruggle)
            EVT_END_IF
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Panic)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_ToppleStruggle)
            EVT_END_IF
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Idle)
                EVT_EXEC_WAIT(DoImmune)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_ToppleStruggle)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80221DAC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_ShellSpin)
    EVT_ELSE
        EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 9, LVar0)
            EVT_SUB(LVar0, 1)
            EVT_IF_GT(LVar0, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, 9, LVar0)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(3.0))
                EVT_WAIT(30)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_ELSE
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(3.0))
                EVT_WAIT(20)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
                EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_0, 0)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_JUMP_3E2)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_ToppleStruggle)
                EVT_SET(LVar0, 0)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
                EVT_CHILD_THREAD
                    EVT_LOOP(5)
                        EVT_ADD(LVar0, 15)
                        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                        EVT_WAIT(1)
                    EVT_END_LOOP
                EVT_END_CHILD_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
                EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BA)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Idle)
                EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80220AA0)))
                EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(DefenseTable_8021EAD0)))
                EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -4, 32)
                EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, -1, -4)
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, FALSE)
                EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_ShellEnter)
        EVT_WAIT(10)
        EVT_CHILD_THREAD
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 4)
            EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
            EVT_WAIT(3)
            EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
            EVT_WAIT(2)
            EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        EVT_END_CHILD_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2021)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_ShellSpin)
        EVT_WAIT(10)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20D3)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_0, SOUND_0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -40, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(GetBattlePhase, LVar0)
            EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_F)
                EVT_CALL(SetBattleCamZoom, 300)
                EVT_CALL(SetBattleCamOffsetZ, 20)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(func_8024ECF8, -1, 1, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_ShellExit)
            EVT_WAIT(8)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_WAIT(4)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_BeginPanic1)
            EVT_WAIT(1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_BeginPanic2)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Panic)
            EVT_WAIT(6)
            EVT_SUB(LVar1, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Panic)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetPartYaw, ACTOR_SELF, 1, 0)
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
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_ShellExit)
            EVT_WAIT(8)
            EVT_CALL(YieldTurn)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Run)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_KoopaTroopa_Idle)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
