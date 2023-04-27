#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Koopatrol.h"
#include "effects.h"

enum N(ActorVars) {
    N(VAR_STATE) = 0,
    N(VAR_SUMMON_COUNT) = 1,
    N(VAR_INDEX_FROM_HOME) = 2,
    N(VAR_FLIPPED) = 9,
};

enum N(States) {
    N(STATE_NORMAL) = 0,
    N(STATE_FLIPPED) = 1,
    N(STATE_CHARGED) = 2,
};

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(nextTurn);

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL, ANIM_Koopatrol_Anim01,
    STATUS_STONE, ANIM_Koopatrol_Anim00,
    STATUS_SLEEP, ANIM_Koopatrol_Anim11,
    STATUS_POISON, ANIM_Koopatrol_Anim01,
    STATUS_STOP, ANIM_Koopatrol_Anim00,
    STATUS_STATIC, ANIM_Koopatrol_Anim01,
    STATUS_PARALYZE, ANIM_Koopatrol_Anim00,
    STATUS_DIZZY, ANIM_Koopatrol_Anim13,
    STATUS_FEAR, ANIM_Koopatrol_Anim13,
    STATUS_END,
};

s32 N(IdleAnimations_stepBack)[] = {
    STATUS_NORMAL, ANIM_Koopatrol_Anim03,
    STATUS_STONE, ANIM_Koopatrol_Anim00,
    STATUS_SLEEP, ANIM_Koopatrol_Anim11,
    STATUS_POISON, ANIM_Koopatrol_Anim03,
    STATUS_STOP, ANIM_Koopatrol_Anim00,
    STATUS_STATIC, ANIM_Koopatrol_Anim03,
    STATUS_PARALYZE, ANIM_Koopatrol_Anim00,
    STATUS_DIZZY, ANIM_Koopatrol_Anim13,
    STATUS_FEAR, ANIM_Koopatrol_Anim13,
    STATUS_END,
};

s32 N(IdleAnimations_flipped)[] = {
    STATUS_NORMAL, ANIM_Koopatrol_Anim0F,
    STATUS_STONE, ANIM_Koopatrol_Anim10,
    STATUS_SLEEP, ANIM_Koopatrol_Anim12,
    STATUS_POISON, ANIM_Koopatrol_Anim0F,
    STATUS_STOP, ANIM_Koopatrol_Anim10,
    STATUS_STATIC, ANIM_Koopatrol_Anim0F,
    STATUS_PARALYZE, ANIM_Koopatrol_Anim10,
    STATUS_DIZZY, ANIM_Koopatrol_Anim14,
    STATUS_FEAR, ANIM_Koopatrol_Anim14,
    STATUS_END,
};

s32 N(IdleAnimations_charged)[] = {
    STATUS_NORMAL, ANIM_Koopatrol_Anim06,
    STATUS_STONE, ANIM_Koopatrol_Anim06,
    STATUS_SLEEP, ANIM_Koopatrol_Anim06,
    STATUS_POISON, ANIM_Koopatrol_Anim06,
    STATUS_STOP, ANIM_Koopatrol_Anim06,
    STATUS_STATIC, ANIM_Koopatrol_Anim06,
    STATUS_PARALYZE, ANIM_Koopatrol_Anim06,
    STATUS_DIZZY, ANIM_Koopatrol_Anim06,
    STATUS_FEAR, ANIM_Koopatrol_Anim06,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 3,
    ELEMENT_SHOCK, 3,
    ELEMENT_END,
};

s32 N(DefenseTable_flipped)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(DefenseTable_charged)[] = {
    ELEMENT_NORMAL, 3,
    ELEMENT_FIRE, 3,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 50,
    STATUS_POISON, 60,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 0,
    STATUS_STATIC, 80,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 70,
    STATUS_STOP, 80,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

s32 N(StatusTable_charged)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_DIZZY, 0,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 0,
    STATUS_STOP, 0,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 32 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -12 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_KOOPATROL,
    .level = 25,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 75,
    .hurricaneChance = 65,
    .spookChance = 60,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 85,
    .coinReward = 2,
    .size = { 32, 42 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 32 },
    .statusMessageOffset = { 5, 32 },
};

#include "common/UnkBattleFunc1.inc.c"
#include "common/StartRumbleWithParams.inc.c"

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn)))
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_STATE), N(STATE_NORMAL))
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SUMMON_COUNT), 0)
    EVT_CALL(GetIndexFromHome, ACTOR_SELF, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_INDEX_FROM_HOME), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetBattleVar, 4, 0)
        EVT_CASE_EQ(1)
            EVT_CALL(SetBattleVar, 5, 0)
        EVT_CASE_EQ(2)
            EVT_CALL(SetBattleVar, 6, 0)
        EVT_CASE_EQ(3)
            EVT_CALL(SetBattleVar, 7, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_END)
            EVT_CALL(SetBattleVar, 1, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(update_unknown) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(N(STATE_NORMAL))
            EVT_IF_FLAG(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_DIZZY)
                EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -5, 15)
                EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, 0, 0)
                EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
            EVT_ELSE
                EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -4, 32)
                EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, -1, -4)
                EVT_CALL(N(UnkBattleFunc1), -15, 32, 5, 32)
            EVT_END_IF
        EVT_CASE_EQ(N(STATE_FLIPPED))
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -5, 15)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, 0, 0)
            EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
        EVT_CASE_EQ(N(STATE_CHARGED))
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -4, 20)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, 0, -6)
            EVT_CALL(N(UnkBattleFunc1), -15, 22, 5, 22)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_LABEL(0)
    EVT_CALL(RandInt, 80, LVarA)
    EVT_ADD(LVarA, 80)
    EVT_LOOP(LVarA)
        EVT_LABEL(1)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_STATE), LVar0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
        EVT_EXEC_WAIT(N(update_unknown))
        EVT_IF_EQ(LVar0, N(STATE_FLIPPED))
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_IF_FLAG(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP | STATUS_FLAG_GLOWING)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_stepBack)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleRunToGoal, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_STATE), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(N(STATE_NORMAL))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations)))
        EVT_CASE_EQ(N(STATE_FLIPPED))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_flipped)))
    EVT_END_SWITCH
    EVT_LOOP(20)
        EVT_LABEL(2)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_STATE), LVar0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
        EVT_EXEC_WAIT(N(update_unknown))
        EVT_IF_EQ(LVar0, N(STATE_FLIPPED))
            EVT_WAIT(1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_IF_FLAG(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP | STATUS_FLAG_GLOWING)
            EVT_WAIT(1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_stepBack)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleRunToGoal, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_STATE), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(N(STATE_NORMAL))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations)))
        EVT_CASE_EQ(N(STATE_FLIPPED))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_flipped)))
    EVT_END_SWITCH
    EVT_LOOP(80)
        EVT_LABEL(3)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_STATE), LVar0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
        EVT_EXEC_WAIT(N(update_unknown))
        EVT_IF_EQ(LVar0, N(STATE_FLIPPED))
            EVT_WAIT(1)
            EVT_GOTO(3)
        EVT_END_IF
        EVT_IF_FLAG(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP | STATUS_FLAG_GLOWING)
            EVT_WAIT(1)
            EVT_GOTO(3)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(flipPos)[] = {
    9, 16, 22, 26, 30, 32, 33, 32, 30, 26, 22, 16, 9, 0, 4, 6, 7, 6, 4, 0, 2, 0,
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_STATE), LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(N(STATE_NORMAL))
                EVT_CASE_OR_EQ(N(STATE_FLIPPED))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
                    EVT_EXEC_WAIT(EVS_DoNormalHit)
                EVT_END_CASE_GROUP
                EVT_CASE_EQ(N(STATE_CHARGED))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim06)
                    EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0C)
            EVT_SET_CONST(LVar2, ANIM_Koopatrol_Anim0D)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0C)
            EVT_SET_CONST(LVar2, ANIM_Koopatrol_Anim0D)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0D)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_STATE), LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(N(STATE_NORMAL))
                EVT_CASE_OR_EQ(N(STATE_FLIPPED))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
                    EVT_EXEC_WAIT(DoSpinSmashHit)
                EVT_END_CASE_GROUP
                EVT_CASE_EQ(N(STATE_CHARGED))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim06)
                    EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_STATE), LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(N(STATE_NORMAL))
                EVT_CASE_OR_EQ(N(STATE_FLIPPED))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
                    EVT_EXEC_WAIT(DoSpinSmashHit)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
                    EVT_EXEC_WAIT(EVS_DoDeath)
                EVT_END_CASE_GROUP
                EVT_CASE_EQ(N(STATE_CHARGED))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim06)
                    EVT_EXEC_WAIT(DoSpinSmashHit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim08)
                    EVT_WAIT(5)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
                    EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_STATE), N(STATE_FLIPPED))
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_FLIPPED), 1)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(DefenseTable_flipped)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_flipped)))
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -5, 15)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, 0, 0)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_SPIKY_TOP, FALSE)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim0B)
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
            EVT_USE_BUF(N(flipPos))
            EVT_LOOP(22)
                EVT_BUF_READ1(LVar0)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim0F)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim04)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_STAR_BEAM)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_STATE), LVar0)
            EVT_IF_EQ(LVar0, N(STATE_CHARGED))
                EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable)))
                EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(DefenseTable)))
                EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_FLIPABLE, TRUE)
                EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_STATE), N(STATE_NORMAL))
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations)))
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
                EVT_IF_NOT_FLAG(LVarA, STATUS_FLAG_DEFENSE_BOOST | STATUS_FLAG_ATTACK_BOOST)
                    EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
                EVT_END_IF
                EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim08)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_STATE), LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(N(STATE_NORMAL))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim07)
                    EVT_EXEC_WAIT(DoImmune)
                    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim08)
                        EVT_WAIT(10)
                    EVT_END_IF
                EVT_CASE_EQ(N(STATE_FLIPPED))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0F)
                    EVT_EXEC_WAIT(DoImmune)
                EVT_CASE_EQ(N(STATE_CHARGED))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim06)
                    EVT_EXEC_WAIT(DoImmune)
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_WAIT(10)
            EVT_SET(LocalFlag(0), 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_ADD(LVar1, 16)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
            EVT_IF_FLAG(LVar3, STATUS_FLAG_DIZZY)
                EVT_ADD(LVar0, -14)
                EVT_ADD(LVar1, 20)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SLEEP)
                EVT_ADD(LVar0, -14)
                EVT_ADD(LVar1, 20)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_STATE), LVarA)
            EVT_IF_EQ(LVarA, N(STATE_CHARGED))
                EVT_ADD(LVar1, 23)
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
            EVT_IF_EQ(LocalFlag(0), 0)
                EVT_ADD(LVar1, 42)
            EVT_END_IF
            EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 20, 0)
            EVT_WAIT(20)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_STATE), LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(N(STATE_NORMAL))
                EVT_CASE_OR_EQ(N(STATE_FLIPPED))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
                    EVT_EXEC_WAIT(EVS_DoNormalHit)
                    EVT_WAIT(10)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
                    EVT_EXEC_WAIT(EVS_DoDeath)
                    EVT_RETURN
                EVT_END_CASE_GROUP
                EVT_CASE_EQ(N(STATE_CHARGED))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim06)
                    EVT_EXEC_WAIT(EVS_DoNormalHit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim08)
                    EVT_WAIT(5)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
                    EVT_EXEC_WAIT(EVS_DoDeath)
                    EVT_RETURN
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_STATE), LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(N(STATE_NORMAL))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim01)
                    EVT_EXEC_WAIT(DoRecover)
                EVT_CASE_EQ(N(STATE_FLIPPED))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0F)
                    EVT_EXEC_WAIT(DoImmune)
                EVT_CASE_EQ(N(STATE_CHARGED))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim06)
                    EVT_EXEC_WAIT(DoRecover)
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_STATE), LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(N(STATE_NORMAL))
                EVT_CASE_OR_EQ(N(STATE_CHARGED))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim04)
                    EVT_SET_CONST(LVar2, ANIM_Koopatrol_Anim0B)
                    EVT_EXEC_WAIT(DoScareAway)
                    EVT_RETURN
                EVT_END_CASE_GROUP
                EVT_CASE_EQ(N(STATE_FLIPPED))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0F)
                    EVT_EXEC_WAIT(DoImmune)
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_STATE), LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(N(STATE_NORMAL))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim16)
                    EVT_EXEC_WAIT(DoAirLift)
                EVT_CASE_EQ(N(STATE_FLIPPED))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0F)
                    EVT_EXEC_WAIT(DoAirLift)
                EVT_CASE_EQ(N(STATE_CHARGED))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0F)
                    EVT_EXEC_WAIT(DoAirLift)
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_STATE), LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(N(STATE_NORMAL))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim16)
                EVT_CASE_EQ(N(STATE_FLIPPED))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0F)
                EVT_CASE_EQ(N(STATE_CHARGED))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0F)
            EVT_END_SWITCH
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_STATE), LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(N(STATE_NORMAL))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim01)
                EVT_CASE_EQ(N(STATE_FLIPPED))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0F)
                EVT_CASE_EQ(N(STATE_CHARGED))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0F)
            EVT_END_SWITCH
            EVT_EXEC_WAIT(DoImmune)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attackShellToss) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim06)
    EVT_ELSE
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_STATE), LVar0)
        EVT_IF_EQ(LVar0, N(STATE_FLIPPED))
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_FLIPPED), LVar0)
            EVT_SUB(LVar0, 1)
            EVT_IF_GT(LVar0, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_FLIPPED), LVar0)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(3.0))
                EVT_WAIT(15)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_ELSE
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(3.0))
                EVT_WAIT(10)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
                EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_0, 0)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_JUMP_3E2)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim0F)
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
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim01)
                EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_STATE), N(STATE_NORMAL))
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations)))
                EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(DefenseTable)))
                EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -4, 32)
                EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, -1, -4)
                EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_SPIKY_TOP, TRUE)
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, FALSE)
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim07)
        EVT_WAIT(10)
        EVT_THREAD
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 4)
            EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
            EVT_WAIT(3)
            EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
            EVT_WAIT(2)
            EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        EVT_END_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2021)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim06)
        EVT_WAIT(10)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20D3)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_0, SOUND_0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 4, BS_FLAGS1_10)
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
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_05)
                EVT_CALL(SetBattleCamZoom, 300)
                EVT_CALL(SetBattleCamOffsetZ, 20)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
            EVT_END_IF
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim08)
            EVT_WAIT(8)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_WAIT(4)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim16)
            EVT_WAIT(1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim16)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim16)
            EVT_WAIT(6)
            EVT_SUB(LVar1, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim16)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim01)
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
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim08)
            EVT_WAIT(8)
            EVT_CALL(YieldTurn)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim04)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim01)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attackShellMissile) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_STATE), LVar0)
    EVT_IF_EQ(LVar0, N(STATE_NORMAL)) // charge for attack
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_POWER_UP)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 10)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 6, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 45, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim15)
        EVT_WAIT(30)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_THREAD
            EVT_WAIT(8)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim07)
        EVT_END_THREAD
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BA)
        EVT_CALL(N(StartRumbleWithParams), 128, 10)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(0.5))
        EVT_END_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim06)
        EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable_charged)))
        EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(DefenseTable_charged)))
        EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_FLIPABLE, FALSE)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_STATE), N(STATE_CHARGED))
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_charged)))
        EVT_CALL(EnableActorGlow, ACTOR_SELF, TRUE)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_ATTACK_CHARGED, TRUE)
        EVT_WAIT(10)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_LOOP(20)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, 1, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_37C)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_0, SOUND_0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 4, BS_FLAGS1_10)
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
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_01)
                EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_END_IF
                EVT_WAIT(15)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_END_THREAD
            EVT_THREAD
                EVT_LOOP(30)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0, 0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -200, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_WAIT(15)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
            EVT_IF_NOT_FLAG(LVarA, STATUS_FLAG_DEFENSE_BOOST | STATUS_FLAG_ATTACK_BOOST)
                EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_END_IF
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            EVT_CALL(YieldTurn)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorPos, ACTOR_SELF, 300, 0, 0)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim08)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable)))
            EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(DefenseTable)))
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_FLIPABLE, TRUE)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_STATE), N(STATE_NORMAL))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations)))
            EVT_WAIT(10)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_LOOP(30)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarA, 0, SUPPRESS_EVENT_ALL, 0, 10, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
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
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
            EVT_IF_NOT_FLAG(LVarA, STATUS_FLAG_DEFENSE_BOOST | STATUS_FLAG_ATTACK_BOOST)
                EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_END_IF
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorPos, ACTOR_SELF, 300, 0, 0)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim04)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim01)
            EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable)))
            EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(DefenseTable)))
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_FLIPABLE, TRUE)
            EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_STATE), N(STATE_NORMAL))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations)))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(findTarget) = {
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(1)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetOriginalActorType, LVar0, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_OR_EQ(ACTOR_TYPE_BILL_BLASTER)
        EVT_CASE_OR_EQ(ACTOR_TYPE_BOMBSHELL_BLASTER)
            EVT_SET(LVarA, -1)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_SET(LocalFlag(1), 0)
    EVT_SET(LocalFlag(2), 0)
    EVT_SET(LocalFlag(3), 0)
    EVT_SET(LocalFlag(4), 0)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetIndexFromHome, LVar0, LVar1)
    EVT_MOD(LVar1, 4)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_SET(LocalFlag(1), 1)
        EVT_CASE_EQ(1)
            EVT_SET(LocalFlag(2), 1)
        EVT_CASE_EQ(2)
            EVT_SET(LocalFlag(3), 1)
        EVT_CASE_EQ(3)
            EVT_SET(LocalFlag(4), 1)
    EVT_END_SWITCH
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
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

Vec3i N(summon_pos) = { NPC_DISPOSE_LOCATION };

Formation N(summon_formation) = {
    { .actor = &NAMESPACE, .home = { .vec = &N(summon_pos) }, .priority = 100, }
};

EvtScript N(summonFriend) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2E5)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim02)
    EVT_WAIT(20)
    EVT_LOOP(2)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim02)
        EVT_WAIT(8)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2E5)
        EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim09)
        EVT_WAIT(8)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim02)
        EVT_WAIT(8)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2E5)
        EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim09)
        EVT_WAIT(8)
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 30, 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_206D)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Koopatrol_Anim16)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
    EVT_CALL(SummonEnemy, EVT_PTR(N(summon_formation)), 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    EVT_ADD(LVar1, 200)
    EVT_CALL(SetActorPos, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(SetGoalToIndex, LVar0, LVarA)
    EVT_CALL(PlaySoundAtActor, LVar0, SOUND_20D3)
    EVT_CALL(SetActorSounds, LVar0, ACTOR_SOUND_WALK, SOUND_0, SOUND_0)
    EVT_CALL(SetAnimation, LVar0, 1, ANIM_Koopatrol_Anim06)
    EVT_CALL(SetActorSpeed, LVar0, EVT_FLOAT(6.0))
    EVT_CALL(RunToGoal, LVar0, 0, FALSE)
    EVT_CALL(SetAnimation, LVar0, 1, ANIM_Koopatrol_Anim08)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, LVar0, 1, ANIM_Koopatrol_Anim01)
    EVT_CALL(GetActorPos, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(ForceHomePos, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(HPBarToHome, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SUMMON_COUNT), LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, LVar0, N(VAR_SUMMON_COUNT), 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, LVar0, N(VAR_SUMMON_COUNT), 2)
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_INDEX_FROM_HOME), LVar1)
    EVT_CALL(SetActorVar, LVar0, N(VAR_INDEX_FROM_HOME), LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(GetBattleVar, 4, LVar0)
            EVT_ADD(LVar0, 1)
            EVT_CALL(SetBattleVar, 4, LVar0)
        EVT_CASE_EQ(1)
            EVT_CALL(GetBattleVar, 5, LVar0)
            EVT_ADD(LVar0, 1)
            EVT_CALL(SetBattleVar, 5, LVar0)
        EVT_CASE_EQ(2)
            EVT_CALL(GetBattleVar, 6, LVar0)
            EVT_ADD(LVar0, 1)
            EVT_CALL(SetBattleVar, 6, LVar0)
        EVT_CASE_EQ(3)
            EVT_CALL(GetBattleVar, 7, LVar0)
            EVT_ADD(LVar0, 1)
            EVT_CALL(SetBattleVar, 7, LVar0)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(findPlacesToSummon) = {
    EVT_SET(LVar9, 0)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetOriginalActorType, LVar0, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(ACTOR_TYPE_KOOPATROL)
            EVT_CALL(GetStatusFlags, LVar0, LVar3)
            EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(GetActorVar, LVar0, N(VAR_STATE), LVar3)
                EVT_IF_EQ(LVar3, N(STATE_NORMAL))
                    EVT_CALL(GetActorVar, LVar0, N(VAR_SUMMON_COUNT), LVar3)
                    EVT_SWITCH(LVar3)
                        EVT_CASE_OR_EQ(0)
                        EVT_CASE_OR_EQ(1)
                            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_INDEX_FROM_HOME), LVar3)
                            EVT_SWITCH(LVar3)
                                EVT_CASE_EQ(0)
                                    EVT_CALL(GetBattleVar, 4, LVar4)
                                EVT_CASE_EQ(1)
                                    EVT_CALL(GetBattleVar, 5, LVar4)
                                EVT_CASE_EQ(2)
                                    EVT_CALL(GetBattleVar, 6, LVar4)
                                EVT_CASE_EQ(3)
                                    EVT_CALL(GetBattleVar, 7, LVar4)
                            EVT_END_SWITCH
                            EVT_IF_LT(LVar4, 2)
                                EVT_ADD(LVar9, 1)
                            EVT_END_IF
                        EVT_END_CASE_GROUP
                        EVT_CASE_EQ(2)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetBattleVar, 1, 1)
        EVT_EXEC_WAIT(N(attackShellToss))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_STATE), LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(N(STATE_NORMAL))
            EVT_CALL(GetBattleVar, 1, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SUMMON_COUNT), LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_OR_EQ(0)
                        EVT_CASE_OR_EQ(1)
                            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_INDEX_FROM_HOME), LVar0)
                            EVT_SWITCH(LVar0)
                                EVT_CASE_EQ(0)
                                    EVT_CALL(GetBattleVar, 4, LVar1)
                                EVT_CASE_EQ(1)
                                    EVT_CALL(GetBattleVar, 5, LVar1)
                                EVT_CASE_EQ(2)
                                    EVT_CALL(GetBattleVar, 6, LVar1)
                                EVT_CASE_EQ(3)
                                    EVT_CALL(GetBattleVar, 7, LVar1)
                            EVT_END_SWITCH
                            EVT_IF_GE(LVar1, 2)
                                EVT_CALL(RandInt, 1000, LVar0)
                                EVT_IF_LT(LVar0, 300)
                                    EVT_CALL(SetBattleVar, 1, 2)
                                    EVT_EXEC_WAIT(N(attackShellMissile))
                                EVT_ELSE
                                    EVT_CALL(SetBattleVar, 1, 1)
                                    EVT_EXEC_WAIT(N(attackShellToss))
                                EVT_END_IF
                                EVT_RETURN
                            EVT_END_IF
                        EVT_END_CASE_GROUP
                        EVT_CASE_EQ(2)
                            EVT_CALL(RandInt, 1000, LVar0)
                            EVT_IF_LT(LVar0, 300)
                                EVT_CALL(SetBattleVar, 1, 2)
                                EVT_EXEC_WAIT(N(attackShellMissile))
                            EVT_ELSE
                                EVT_CALL(SetBattleVar, 1, 1)
                                EVT_EXEC_WAIT(N(attackShellToss))
                            EVT_END_IF
                            EVT_RETURN
                    EVT_END_SWITCH
                    EVT_EXEC_WAIT(N(findTarget))
                    EVT_IF_EQ(LVarA, -1)
                        EVT_CALL(RandInt, 1000, LVar0)
                        EVT_IF_LT(LVar0, 300)
                            EVT_CALL(SetBattleVar, 1, 2)
                            EVT_EXEC_WAIT(N(attackShellMissile))
                        EVT_ELSE
                            EVT_CALL(SetBattleVar, 1, 1)
                            EVT_EXEC_WAIT(N(attackShellToss))
                        EVT_END_IF
                        EVT_RETURN
                    EVT_END_IF
                    EVT_EXEC_WAIT(N(findPlacesToSummon))
                    EVT_SWITCH(LVar9)
                        EVT_CASE_EQ(1)
                            EVT_CALL(RandInt, 1000, LVar0)
                            EVT_IF_LT(LVar0, 400)
                                EVT_CALL(SetBattleVar, 1, 1)
                                EVT_EXEC_WAIT(N(summonFriend))
                                EVT_RETURN
                            EVT_END_IF
                        EVT_CASE_EQ(2)
                            EVT_CALL(RandInt, 1000, LVar0)
                            EVT_IF_LT(LVar0, 200)
                                EVT_CALL(SetBattleVar, 1, 1)
                                EVT_EXEC_WAIT(N(summonFriend))
                                EVT_RETURN
                            EVT_END_IF
                        EVT_CASE_EQ(3)
                            EVT_CALL(RandInt, 1000, LVar0)
                            EVT_IF_LT(LVar0, 100)
                                EVT_CALL(SetBattleVar, 1, 1)
                                EVT_EXEC_WAIT(N(summonFriend))
                                EVT_RETURN
                            EVT_END_IF
                    EVT_END_SWITCH
                    EVT_CALL(RandInt, 1000, LVar0)
                    EVT_IF_LT(LVar0, 300)
                        EVT_CALL(SetBattleVar, 1, 2)
                        EVT_EXEC_WAIT(N(attackShellMissile))
                    EVT_ELSE
                        EVT_CALL(SetBattleVar, 1, 1)
                        EVT_EXEC_WAIT(N(attackShellToss))
                    EVT_END_IF
                EVT_CASE_EQ(1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SUMMON_COUNT), LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_OR_EQ(0)
                        EVT_CASE_OR_EQ(1)
                            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_INDEX_FROM_HOME), LVar0)
                            EVT_SWITCH(LVar0)
                                EVT_CASE_EQ(0)
                                    EVT_CALL(GetBattleVar, 4, LVar1)
                                EVT_CASE_EQ(1)
                                    EVT_CALL(GetBattleVar, 5, LVar1)
                                EVT_CASE_EQ(2)
                                    EVT_CALL(GetBattleVar, 6, LVar1)
                                EVT_CASE_EQ(3)
                                    EVT_CALL(GetBattleVar, 7, LVar1)
                            EVT_END_SWITCH
                            EVT_IF_GE(LVar1, 2)
                                EVT_CALL(RandInt, 1000, LVar0)
                                EVT_IF_LT(LVar0, 300)
                                    EVT_CALL(SetBattleVar, 1, 2)
                                    EVT_EXEC_WAIT(N(attackShellMissile))
                                EVT_ELSE
                                    EVT_CALL(SetBattleVar, 1, 1)
                                    EVT_EXEC_WAIT(N(attackShellToss))
                                EVT_END_IF
                                EVT_RETURN
                            EVT_END_IF
                        EVT_END_CASE_GROUP
                        EVT_CASE_EQ(2)
                            EVT_EXEC_WAIT(N(attackShellToss))
                            EVT_RETURN
                    EVT_END_SWITCH
                    EVT_EXEC_WAIT(N(findTarget))
                    EVT_IF_EQ(LVarA, -1)
                        EVT_EXEC_WAIT(N(attackShellToss))
                        EVT_RETURN
                    EVT_END_IF
                    EVT_EXEC_WAIT(N(findPlacesToSummon))
                    EVT_SWITCH(LVar9)
                        EVT_CASE_EQ(1)
                            EVT_CALL(RandInt, 1000, LVar0)
                            EVT_IF_LT(LVar0, 400)
                                EVT_EXEC_WAIT(N(summonFriend))
                                EVT_RETURN
                            EVT_END_IF
                        EVT_CASE_EQ(2)
                            EVT_CALL(RandInt, 1000, LVar0)
                            EVT_IF_LT(LVar0, 200)
                                EVT_EXEC_WAIT(N(summonFriend))
                                EVT_RETURN
                            EVT_END_IF
                        EVT_CASE_EQ(3)
                            EVT_CALL(RandInt, 1000, LVar0)
                            EVT_IF_LT(LVar0, 100)
                                EVT_EXEC_WAIT(N(summonFriend))
                                EVT_RETURN
                            EVT_END_IF
                    EVT_END_SWITCH
                    EVT_EXEC_WAIT(N(attackShellToss))
                EVT_CASE_EQ(2)
                    EVT_EXEC_WAIT(N(attackShellMissile))
            EVT_END_SWITCH
        EVT_CASE_EQ(N(STATE_FLIPPED))
            EVT_CALL(SetBattleVar, 1, 1)
            EVT_EXEC_WAIT(N(attackShellToss))
        EVT_CASE_EQ(N(STATE_CHARGED))
            EVT_EXEC_WAIT(N(attackShellMissile))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

