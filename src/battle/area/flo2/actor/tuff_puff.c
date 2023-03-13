#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/RuffPuff.h"
#include "effects.h"

#define NAMESPACE b_area_flo2_tuff_puff

enum N(actorVars) {
    N(VAR_IS_BIG) = 0,
    N(VAR_INDEX) = 1,
    N(VAR_2) = 2,
    N(VAR_SCALE_X) = 3,
    N(VAR_SCALE_Y) = 4,
};

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(nextTurn);

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL, ANIM_RuffPuff_Anim02,
    STATUS_STONE, ANIM_RuffPuff_Anim00,
    STATUS_SLEEP, ANIM_RuffPuff_Anim02,
    STATUS_POISON, ANIM_RuffPuff_Anim02,
    STATUS_STOP, ANIM_RuffPuff_Anim00,
    STATUS_STATIC, ANIM_RuffPuff_Anim02,
    STATUS_PARALYZE, ANIM_RuffPuff_Anim02,
    STATUS_PARALYZE, ANIM_RuffPuff_Anim00,
    STATUS_DIZZY, ANIM_RuffPuff_Anim02,
    STATUS_DIZZY, ANIM_RuffPuff_Anim02,
    STATUS_FEAR, ANIM_RuffPuff_Anim02,
    STATUS_END,
};

s32 N(IdleAnimations2)[] = {
    STATUS_NORMAL, ANIM_RuffPuff_Anim03,
    STATUS_STONE, ANIM_RuffPuff_Anim01,
    STATUS_SLEEP, ANIM_RuffPuff_Anim03,
    STATUS_POISON, ANIM_RuffPuff_Anim03,
    STATUS_STOP, ANIM_RuffPuff_Anim01,
    STATUS_STATIC, ANIM_RuffPuff_Anim03,
    STATUS_PARALYZE, ANIM_RuffPuff_Anim03,
    STATUS_PARALYZE, ANIM_RuffPuff_Anim01,
    STATUS_DIZZY, ANIM_RuffPuff_Anim03,
    STATUS_DIZZY, ANIM_RuffPuff_Anim03,
    STATUS_FEAR, ANIM_RuffPuff_Anim03,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_SHOCK, 99,
    ELEMENT_MYSTERY, 0,
    ELEMENT_JUMP, 0,
    ELEMENT_SMASH, 0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 0,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 0,
    STATUS_STOP, 0,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
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
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_20 | ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_20 | ACTOR_PART_FLAG_MULTI_TARGET | ACTOR_PART_FLAG_80000000,
        .index = 2,
        .posOffset = { 0, 50, 0 },
        .targetOffset = { 0, -50 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING | ACTOR_FLAG_8000 | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_TUFF_PUFF,
    .level = 0,
    .maxHP = 1,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { 24, 32 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 0 },
    .statusMessageOffset = { 10, 10 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn)))
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_IS_BIG), LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, -1, -9)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 2, -1, -9)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -1, 9)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, -1, -41)
        EVT_CALL(SetActorSize, ACTOR_SELF, 20, 25)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations)))
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_RuffPuff_Anim02)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_IS_BIG), 0)
    EVT_ELSE
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 1, -8, -13)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 2, -8, -13)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 1, 14)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, 1, -36)
        EVT_CALL(SetActorSize, ACTOR_SELF, 28, 35)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations2)))
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_RuffPuff_Anim03)
        EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_IS_BIG), 1)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_2), 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_X), 100)
    EVT_CALL(SetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), 100)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn) = {
    EVT_RETURN
    EVT_END
};

#include "common/CosInterpMinMax.inc.c"

EvtScript N(idle) = {
    EVT_SET(LVarF, 0)
    EVT_LOOP(0)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_2), LVarA)
        EVT_SWITCH(LVarA)
            EVT_CASE_EQ(0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar0, EVT_FLOAT(0.97), EVT_FLOAT(1.03), 15, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar1, EVT_FLOAT(1.03), EVT_FLOAT(0.97), 15, 0, 0)
                EVT_ADD(LVarF, 1)
            EVT_CASE_EQ(1)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar0, EVT_FLOAT(0.95), EVT_FLOAT(1.05), 15, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar1, EVT_FLOAT(1.05), EVT_FLOAT(0.95), 15, 0, 0)
                EVT_ADD(LVarF, 3)
            EVT_CASE_EQ(2)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar0, EVT_FLOAT(0.9), EVT_FLOAT(1.1), 15, 0, 0)
                EVT_CALL(N(CosInterpMinMax), LVarF, LVar1, EVT_FLOAT(1.1), EVT_FLOAT(0.9), 15, 0, 0)
                EVT_ADD(LVarF, 5)
        EVT_END_SWITCH
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_X), LVar2)
        EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_SCALE_Y), LVar3)
        EVT_DIVF(LVar2, EVT_FLOAT(100.0))
        EVT_DIVF(LVar3, EVT_FLOAT(100.0))
        EVT_MULF(LVar1, LVar2)
        EVT_MULF(LVar0, LVar3)
        EVT_CALL(SetActorScale, ACTOR_SELF, LVar1, LVar0, EVT_FLOAT(1.0))
        EVT_IF_GE(LVarF, 30)
            EVT_SET(LVarF, 0)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(onDeath) = {
    EVT_CALL(ActorExists, ACTOR_ENEMY0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_INDEX), LVar0)
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 2, LVar1)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_BITWISE_AND_CONST(LVar1, ~0x1)
        EVT_CASE_EQ(1)
            EVT_BITWISE_AND_CONST(LVar1, ~0x2)
        EVT_CASE_EQ(2)
            EVT_BITWISE_AND_CONST(LVar1, ~0x4)
        EVT_CASE_EQ(3)
            EVT_BITWISE_AND_CONST(LVar1, ~0x8)
        EVT_CASE_EQ(4)
            EVT_BITWISE_AND_CONST(LVar1, ~0x10)
        EVT_CASE_EQ(5)
            EVT_BITWISE_AND_CONST(LVar1, ~0x20)
        EVT_CASE_EQ(6)
            EVT_BITWISE_AND_CONST(LVar1, ~0x40)
        EVT_CASE_EQ(7)
            EVT_BITWISE_AND_CONST(LVar1, ~0x80)
        EVT_CASE_EQ(8)
            EVT_BITWISE_AND_CONST(LVar1, ~0x100)
        EVT_CASE_EQ(9)
            EVT_BITWISE_AND_CONST(LVar1, ~0x200)
    EVT_END_SWITCH
    EVT_CALL(SetActorVar, ACTOR_ENEMY0, 2, LVar1)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_IS_BIG), LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim0C)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim0D)
            EVT_END_IF
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_IS_BIG), LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim0C)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim0D)
            EVT_END_IF
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_IS_BIG), LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim0E)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim10)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_IS_BIG), LVar2)
            EVT_IF_EQ(LVar2, 0)
                EVT_SET_CONST(LVar2, ANIM_RuffPuff_Anim0F)
            EVT_ELSE
                EVT_SET_CONST(LVar2, ANIM_RuffPuff_Anim11)
            EVT_END_IF
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_IS_BIG), LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim0E)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim10)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_IS_BIG), LVar2)
            EVT_IF_EQ(LVar2, 0)
                EVT_SET_CONST(LVar2, ANIM_RuffPuff_Anim0F)
            EVT_ELSE
                EVT_SET_CONST(LVar2, ANIM_RuffPuff_Anim11)
            EVT_END_IF
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_IS_BIG), LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim0F)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim11)
            EVT_END_IF
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_IS_BIG), LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim02)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim03)
            EVT_END_IF
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_IS_BIG), LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim02)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim03)
            EVT_END_IF
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_IS_BIG), LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim0C)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim0D)
            EVT_END_IF
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_IS_BIG), LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim0C)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim0D)
            EVT_END_IF
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_IS_BIG), LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim02)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim03)
            EVT_END_IF
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_IS_BIG), LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim06)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim07)
            EVT_END_IF
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_IS_BIG), LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim0C)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim0D)
            EVT_END_IF
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, N(VAR_IS_BIG), LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim02)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_RuffPuff_Anim03)
            EVT_END_IF
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
