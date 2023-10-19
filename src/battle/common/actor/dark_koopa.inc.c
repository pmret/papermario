#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/KoopaTroopa.h"
#include "effects.h"

#define NAMESPACE A(dark_koopa)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);

extern s32 N(KoopaAnims)[];

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_HasWhirlwind           = 1,
    AVAR_State                  = 8,
    AVAL_State_Normal           = 0,
    AVAL_State_Hyper            = 1,
    AVAL_State_ToppledNormal    = 2,
    AVAL_State_ToppledHyper     = 3,
    AVAR_ToppleTurns            = 9,
};

enum N(ActorParams) {
    DMG_SHELL_TOSS  = 3,
};

#define SWEAT_DECOR_IDX         0
#define WHIRLWIND_DECOR_IDX     1

s32 N(UprightDefenseTable)[] = {
    ELEMENT_NORMAL,   2,
    ELEMENT_SMASH,    2,
    ELEMENT_JUMP,     2,
    ELEMENT_WATER,    2,
    ELEMENT_BLAST,    2,
    ELEMENT_END,
};

s32 N(ToppledDefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              80,
    STATUS_KEY_POISON,             60,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,              50,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             80,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 36 },
        .opacity = 255,
        .idleAnimations = N(KoopaAnims),
        .defenseTable = N(UprightDefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -7 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_DARK_KOOPA,
    .level = ACTOR_LEVEL_DARK_KOOPA,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 60,
    .airLiftChance = 85,
    .hurricaneChance = 75,
    .spookChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 2,
    .size = { 28, 36 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 32 },
    .statusTextOffset = { 5, 32 },
};

s32 N(KoopaAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_KoopaTroopa_Dark_Idle,
    STATUS_KEY_STONE,     ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_SLEEP,     ANIM_KoopaTroopa_Dark_Sleep,
    STATUS_KEY_POISON,    ANIM_KoopaTroopa_Dark_Idle,
    STATUS_KEY_STOP,      ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_STATIC,    ANIM_KoopaTroopa_Dark_Idle,
    STATUS_KEY_PARALYZE,  ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_DIZZY,     ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_KEY_FEAR,      ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_END,
};

s32 N(ShuffleAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_KoopaTroopa_Dark_Walk,
    STATUS_KEY_STONE,     ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_SLEEP,     ANIM_KoopaTroopa_Dark_Sleep,
    STATUS_KEY_POISON,    ANIM_KoopaTroopa_Dark_Walk,
    STATUS_KEY_STOP,      ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_STATIC,    ANIM_KoopaTroopa_Dark_Walk,
    STATUS_KEY_PARALYZE,  ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_DIZZY,     ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_KEY_FEAR,      ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_END,
};

s32 N(HyperAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_KoopaTroopa_Dark_Scramble,
    STATUS_KEY_STONE,     ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_SLEEP,     ANIM_KoopaTroopa_Dark_Sleep,
    STATUS_KEY_POISON,    ANIM_KoopaTroopa_Dark_Scramble,
    STATUS_KEY_STOP,      ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_STATIC,    ANIM_KoopaTroopa_Dark_Scramble,
    STATUS_KEY_PARALYZE,  ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_DIZZY,     ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_KEY_FEAR,      ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_END,
};

s32 N(HyperShuffleAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_KoopaTroopa_Dark_Walk,
    STATUS_KEY_STONE,     ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_SLEEP,     ANIM_KoopaTroopa_Dark_Sleep,
    STATUS_KEY_POISON,    ANIM_KoopaTroopa_Dark_Walk,
    STATUS_KEY_STOP,      ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_STATIC,    ANIM_KoopaTroopa_Dark_Walk,
    STATUS_KEY_PARALYZE,  ANIM_KoopaTroopa_Dark_Still,
    STATUS_KEY_DIZZY,     ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_KEY_FEAR,      ANIM_KoopaTroopa_Dark_Stunned,
    STATUS_END,
};

s32 N(ToppledAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_KoopaTroopa_Dark_ToppleStruggle,
    STATUS_KEY_STONE,     ANIM_KoopaTroopa_Dark_ToppleStill,
    STATUS_KEY_SLEEP,     ANIM_KoopaTroopa_Dark_ToppleSleep,
    STATUS_KEY_POISON,    ANIM_KoopaTroopa_Dark_ToppleStruggle,
    STATUS_KEY_STOP,      ANIM_KoopaTroopa_Dark_ToppleStill,
    STATUS_KEY_STATIC,    ANIM_KoopaTroopa_Dark_ToppleStruggle,
    STATUS_KEY_PARALYZE,  ANIM_KoopaTroopa_Dark_ToppleStill,
    STATUS_KEY_DIZZY,     ANIM_KoopaTroopa_Dark_ToppleStunned,
    STATUS_KEY_FEAR,      ANIM_KoopaTroopa_Dark_ToppleStunned,
    STATUS_END,
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(RandInt, 1000, LVar0)
    EVT_IF_LT(LVar0, 300)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
    EVT_ELSE
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Hyper)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(HyperAnims)))
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Scramble)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HasWhirlwind, FALSE)
    EVT_RETURN
    EVT_END
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(EVS_UpdateOffsets) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(AVAL_State_Normal)
        EVT_CASE_OR_EQ(AVAL_State_Hyper)
            EVT_IF_FLAG(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_DIZZY)
                EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -5, 15)
                EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
                EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
            EVT_ELSE
                EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -4, 32)
                EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -4)
                EVT_CALL(N(SetAbsoluteStatusOffsets), -15, 32, 5, 32)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(AVAL_State_ToppledNormal)
        EVT_CASE_OR_EQ(AVAL_State_ToppledHyper)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -5, 15)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
            EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_CALL(RandInt, 80, LVarA)
        EVT_ADD(LVarA, 80)
        EVT_LOOP(LVarA)
            EVT_LABEL(1)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
                EVT_EXEC_WAIT(N(EVS_UpdateOffsets))
                EVT_IF_EQ(LVar0, AVAL_State_ToppledNormal)
                    EVT_WAIT(1)
                    EVT_GOTO(1)
                EVT_END_IF
                EVT_IF_EQ(LVar0, AVAL_State_ToppledHyper)
                    EVT_WAIT(1)
                    EVT_GOTO(1)
                EVT_END_IF
                EVT_IF_FLAG(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    EVT_WAIT(1)
                    EVT_GOTO(1)
                EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(AVAL_State_Normal)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ShuffleAnims)))
            EVT_CASE_EQ(AVAL_State_Hyper)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(HyperShuffleAnims)))
        EVT_END_SWITCH
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IdleRunToGoal, ACTOR_SELF, 0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(AVAL_State_Normal)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(KoopaAnims)))
            EVT_CASE_EQ(AVAL_State_Hyper)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(HyperAnims)))
            EVT_CASE_OR_EQ(AVAL_State_ToppledNormal)
            EVT_CASE_OR_EQ(AVAL_State_ToppledHyper)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledAnims)))
            EVT_END_CASE_GROUP
        EVT_END_SWITCH
        EVT_LOOP(20)
            EVT_LABEL(2)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
                EVT_EXEC_WAIT(N(EVS_UpdateOffsets))
                EVT_IF_EQ(LVar0, AVAL_State_ToppledNormal)
                    EVT_WAIT(1)
                    EVT_GOTO(2)
                EVT_END_IF
                EVT_IF_EQ(LVar0, AVAL_State_ToppledHyper)
                    EVT_WAIT(1)
                    EVT_GOTO(2)
                EVT_END_IF
                EVT_IF_FLAG(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    EVT_WAIT(1)
                    EVT_GOTO(2)
                EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(AVAL_State_Normal)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ShuffleAnims)))
            EVT_CASE_EQ(AVAL_State_Hyper)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(HyperShuffleAnims)))
        EVT_END_SWITCH
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 5)
        EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IdleRunToGoal, ACTOR_SELF, 0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(AVAL_State_Normal)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(KoopaAnims)))
            EVT_CASE_EQ(AVAL_State_Hyper)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(HyperAnims)))
            EVT_CASE_OR_EQ(AVAL_State_ToppledNormal)
            EVT_CASE_OR_EQ(AVAL_State_ToppledHyper)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledAnims)))
            EVT_END_CASE_GROUP
        EVT_END_SWITCH
        EVT_LOOP(50)
            EVT_LABEL(3)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
                EVT_EXEC_WAIT(N(EVS_UpdateOffsets))
                EVT_IF_EQ(LVar0, AVAL_State_ToppledNormal)
                    EVT_WAIT(1)
                    EVT_GOTO(3)
                EVT_END_IF
                EVT_IF_EQ(LVar0, AVAL_State_ToppledHyper)
                    EVT_WAIT(1)
                    EVT_GOTO(3)
                EVT_END_IF
                EVT_IF_FLAG(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    EVT_WAIT(1)
                    EVT_GOTO(3)
                EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(AVAL_State_Hyper)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HasWhirlwind, TRUE)
                EVT_THREAD
                    EVT_CALL(MakeLerp, 720, 0, 30, EASING_COS_IN_OUT)
                    EVT_LABEL(10)
                        EVT_CALL(UpdateLerp)
                        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
                        EVT_IF_EQ(LVar1, 1)
                            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HasWhirlwind, LVar2)
                            EVT_IF_EQ(LVar2, 1)
                                EVT_WAIT(1)
                                EVT_GOTO(10)
                            EVT_END_IF
                        EVT_END_IF
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HasWhirlwind, FALSE)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
                EVT_END_THREAD
                EVT_WAIT(8)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, WHIRLWIND_DECOR_IDX, ACTOR_DECORATION_WHIRLWIND)
                EVT_WAIT(15)
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, WHIRLWIND_DECOR_IDX)
                EVT_WAIT(8)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HasWhirlwind, FALSE)
            EVT_CASE_EQ(AVAL_State_Normal)
            EVT_CASE_EQ(AVAL_State_ToppledNormal)
            EVT_CASE_EQ(AVAL_State_ToppledHyper)
        EVT_END_SWITCH
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(FlipPosOffsets)[] = { 9, 16, 22, 26, 30, 32, 33, 32, 30, 26, 22, 16, 9, 0, 4, 6, 7, 6, 4, 0, 2, 0 };

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0))
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HasWhirlwind, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, WHIRLWIND_DECOR_IDX)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HasWhirlwind, FALSE)
    EVT_END_IF
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_KoopaTroopa_Dark_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_KoopaTroopa_Dark_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_State_Normal)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_ToppledNormal)
                EVT_CASE_EQ(AVAL_State_Hyper)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_ToppledHyper)
            EVT_END_SWITCH
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 1)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledDefenseTable)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledAnims)))
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -5, 15)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Hurt)
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
            EVT_USE_BUF(N(FlipPosOffsets))
            EVT_LOOP(ARRAY_COUNT(N(FlipPosOffsets)))
                EVT_BUF_READ1(LVar0)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ToppleStruggle)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(0.5))
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Run)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(AVAL_State_Normal)
                EVT_CASE_OR_EQ(AVAL_State_Hyper)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_ShellEnter)
                    EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ShellExit)
                        EVT_WAIT(10)
                    EVT_END_IF
                EVT_END_CASE_GROUP
                EVT_CASE_OR_EQ(AVAL_State_ToppledNormal)
                EVT_CASE_OR_EQ(AVAL_State_ToppledHyper)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_ToppleStruggle)
                    EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            EVT_IF_EQ(LVar0, AVAL_State_Normal)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Run)
                EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_END_IF
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            EVT_IF_EQ(LVar0, AVAL_State_Normal)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Scramble)
                EVT_EXEC_WAIT(EVS_Enemy_Recover)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(AVAL_State_Normal)
                EVT_CASE_OR_EQ(AVAL_State_Hyper)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Run)
                    EVT_SET_CONST(LVar2, ANIM_KoopaTroopa_Dark_Hurt)
                    EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
                    EVT_RETURN
                EVT_END_CASE_GROUP
                EVT_CASE_OR_EQ(AVAL_State_ToppledNormal)
                EVT_CASE_OR_EQ(AVAL_State_ToppledHyper)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_ToppleStruggle)
                    EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(AVAL_State_Normal)
                EVT_CASE_OR_EQ(AVAL_State_Hyper)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Panic)
                EVT_END_CASE_GROUP
                EVT_CASE_OR_EQ(AVAL_State_ToppledNormal)
                EVT_CASE_OR_EQ(AVAL_State_ToppledHyper)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_ToppleStruggle)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(AVAL_State_Normal)
                EVT_CASE_OR_EQ(AVAL_State_Hyper)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Panic)
                EVT_END_CASE_GROUP
                EVT_CASE_OR_EQ(AVAL_State_ToppledNormal)
                EVT_CASE_OR_EQ(AVAL_State_ToppledHyper)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_ToppleStruggle)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(AVAL_State_Normal)
                EVT_CASE_OR_EQ(AVAL_State_Hyper)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Idle)
                    EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                EVT_END_CASE_GROUP
                EVT_CASE_OR_EQ(AVAL_State_ToppledNormal)
                EVT_CASE_OR_EQ(AVAL_State_ToppledHyper)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_ToppleStruggle)
                    EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_ShellToss) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ShellSpin)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ShellEnter)
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
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_SPIN)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ShellSpin)
        EVT_WAIT(10)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_TOSS)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, 3, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -40, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ShellExit)
            EVT_WAIT(8)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_WAIT(4)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_BeginPanic1)
            EVT_WAIT(1)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_BeginPanic2)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Panic)
            EVT_WAIT(6)
            EVT_SUB(LVar1, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, SWEAT_DECOR_IDX, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Panic)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, SWEAT_DECOR_IDX)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_STATUS_ALWAYS_HITS, SUPPRESS_EVENT_ALL, 0, DMG_SHELL_TOSS, BS_FLAGS1_TRIGGER_EVENTS)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ShellExit)
            EVT_WAIT(8)
            EVT_CALL(YieldTurn)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Run)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Idle)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_Whirlwind) = {
    EVT_LABEL(10)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HasWhirlwind, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, TRUE)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 8, 0, 0)
    EVT_ELSE
        EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 0, 0)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Run)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Scramble)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ShellEnter)
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
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_SPIN)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ShellSpin)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DIZZY_SHELL)
    EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, WHIRLWIND_DECOR_IDX, ACTOR_DECORATION_WHIRLWIND)
    EVT_WAIT(40)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, 0, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ShellExit)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, WHIRLWIND_DECOR_IDX)
            EVT_WAIT(10)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, SWEAT_DECOR_IDX, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Panic)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Scramble)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, SWEAT_DECOR_IDX)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_ALL, DMG_STATUS_KEY(STATUS_FLAG_DIZZY, 2, 60), 0, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_THREAD
                EVT_CALL(WasStatusInflicted, ACTOR_SELF, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_CALL(MakeLerp, 0, 1080, 30, EASING_COS_IN_OUT)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ShellExit)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, WHIRLWIND_DECOR_IDX)
            EVT_WAIT(10)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_KoopaTroopa_Dark_Run)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_Scramble)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TryGettingUp) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
    EVT_SUB(LVar0, 1)
    EVT_IF_GT(LVar0, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
        EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, SWEAT_DECOR_IDX, ACTOR_DECORATION_SWEAT)
        EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(2.0))
        EVT_WAIT(30)
        EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(0.5))
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, SWEAT_DECOR_IDX)
    EVT_ELSE
        EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, SWEAT_DECOR_IDX, ACTOR_DECORATION_SWEAT)
        EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(2.0))
        EVT_WAIT(20)
        EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(0.5))
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, SWEAT_DECOR_IDX)
        EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_JUMP)
        EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0))
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KoopaTroopa_Dark_ToppleStruggle)
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
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_A)
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(UprightDefenseTable)))
        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -4, 32)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -4)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, FALSE)
        EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(AVAL_State_ToppledNormal)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(KoopaAnims)))
            EVT_CASE_EQ(AVAL_State_ToppledHyper)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Hyper)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(HyperAnims)))
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_State_Normal)
            EVT_EXEC_WAIT(N(EVS_Attack_ShellToss))
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 300)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(KoopaAnims)))
            EVT_ELSE
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Hyper)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(HyperAnims)))
            EVT_END_IF
        EVT_CASE_EQ(AVAL_State_Hyper)
            EVT_EXEC_WAIT(N(EVS_Attack_Whirlwind))
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 300)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(KoopaAnims)))
            EVT_ELSE
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Hyper)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(HyperAnims)))
            EVT_END_IF
        EVT_CASE_OR_EQ(AVAL_State_ToppledNormal)
        EVT_CASE_OR_EQ(AVAL_State_ToppledHyper)
            EVT_EXEC_WAIT(N(EVS_TryGettingUp))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

