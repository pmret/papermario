#include "../area.h"
#include "sprite/npc/TuffPuff.h"
#include "huff_n_puff_common.h"

#define NAMESPACE A(tuff_puff)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_TARGET      = 2,
};

enum N(ActorVars) {
    AVAR_IN_IsLarge     = 0,
    AVAR_IsLarge        = 0,
    AVAR_Index          = 1, // set by huff n puff after spawning
    AVAR_WobbleMode     = 2,
    AVAR_ScaleX         = 3,
    AVAR_ScaleY         = 4,
    AVAR_HealValue      = 5, // how much sucking this actor up will heal Huff N Puff
};

s32 N(SmallAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_TuffPuff_Anim02,
    STATUS_KEY_STONE,     ANIM_TuffPuff_Anim00,
    STATUS_KEY_SLEEP,     ANIM_TuffPuff_Anim02,
    STATUS_KEY_POISON,    ANIM_TuffPuff_Anim02,
    STATUS_KEY_STOP,      ANIM_TuffPuff_Anim00,
    STATUS_KEY_STATIC,    ANIM_TuffPuff_Anim02,
    STATUS_KEY_PARALYZE,  ANIM_TuffPuff_Anim02,
    STATUS_KEY_PARALYZE,  ANIM_TuffPuff_Anim00,
    STATUS_KEY_DIZZY,     ANIM_TuffPuff_Anim02,
    STATUS_KEY_DIZZY,     ANIM_TuffPuff_Anim02,
    STATUS_KEY_FEAR,      ANIM_TuffPuff_Anim02,
    STATUS_END,
};

s32 N(LargeAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_TuffPuff_Anim03,
    STATUS_KEY_STONE,     ANIM_TuffPuff_Anim01,
    STATUS_KEY_SLEEP,     ANIM_TuffPuff_Anim03,
    STATUS_KEY_POISON,    ANIM_TuffPuff_Anim03,
    STATUS_KEY_STOP,      ANIM_TuffPuff_Anim01,
    STATUS_KEY_STATIC,    ANIM_TuffPuff_Anim03,
    STATUS_KEY_PARALYZE,  ANIM_TuffPuff_Anim03,
    STATUS_KEY_PARALYZE,  ANIM_TuffPuff_Anim01,
    STATUS_KEY_DIZZY,     ANIM_TuffPuff_Anim03,
    STATUS_KEY_DIZZY,     ANIM_TuffPuff_Anim03,
    STATUS_KEY_FEAR,      ANIM_TuffPuff_Anim03,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_SHOCK,   99,
    ELEMENT_MYSTERY,  0,
    ELEMENT_JUMP,     0,
    ELEMENT_SMASH,    0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,                0,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_IGNORE_BELOW_CHECK | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(SmallAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_IGNORE_BELOW_CHECK | ACTOR_PART_FLAG_PRIMARY_TARGET | ACTOR_PART_FLAG_SKIP_MOVEMENT_ALLOC,
        .index = PRT_TARGET,
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
    .flags = ACTOR_FLAG_FLYING | ACTOR_FLAG_HALF_HEIGHT | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_TUFF_PUFF,
    .level = ACTOR_LEVEL_TUFF_PUFF,
    .maxHP = 1,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
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
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 0 },
    .statusTextOffset = { 10, 10 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IN_IsLarge, LVar0)
    EVT_IF_FALSE(LVar0)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -9)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_TARGET, -1, -9)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -1, 9)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_TARGET, -1, -41)
        EVT_CALL(SetActorSize, ACTOR_SELF, 20, 25)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(SmallAnims)))
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TuffPuff_Anim02)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsLarge, FALSE)
    EVT_ELSE
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -8, -13)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_TARGET, -8, -13)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 1, 14)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_TARGET, 1, -36)
        EVT_CALL(SetActorSize, ACTOR_SELF, 28, 35)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(LargeAnims)))
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TuffPuff_Anim03)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsLarge, TRUE)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_WobbleMode, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleX, 100)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScaleY, 100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_RETURN
    EVT_END
};

#include "common/CosInterpMinMax.inc.c"

EvtScript N(EVS_Idle) = {
    EVT_SET(LVarF, 0)
    EVT_LOOP(0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_WobbleMode, LVarA)
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
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar2)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar3)
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
    EVT_CALL(ActorExists, ACTOR_HUFF_N_PUFF, LVar0)
    EVT_IF_FALSE(LVar0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Index, LVar0)
    EVT_CALL(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_HuffNPuff_Flags, LVar1)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_BITWISE_AND_CONST(LVar1, ~(1 << 0))
        EVT_CASE_EQ(1)
            EVT_BITWISE_AND_CONST(LVar1, ~(1 << 1))
        EVT_CASE_EQ(2)
            EVT_BITWISE_AND_CONST(LVar1, ~(1 << 2))
        EVT_CASE_EQ(3)
            EVT_BITWISE_AND_CONST(LVar1, ~(1 << 3))
        EVT_CASE_EQ(4)
            EVT_BITWISE_AND_CONST(LVar1, ~(1 << 4))
        EVT_CASE_EQ(5)
            EVT_BITWISE_AND_CONST(LVar1, ~(1 << 5))
        EVT_CASE_EQ(6)
            EVT_BITWISE_AND_CONST(LVar1, ~(1 << 6))
        EVT_CASE_EQ(7)
            EVT_BITWISE_AND_CONST(LVar1, ~(1 << 7))
        EVT_CASE_EQ(8)
            EVT_BITWISE_AND_CONST(LVar1, ~(1 << 8))
        EVT_CASE_EQ(9)
            EVT_BITWISE_AND_CONST(LVar1, ~(1 << 9))
    EVT_END_SWITCH
    EVT_CALL(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_WobbleMode, LVar1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            EVT_IF_FALSE(LVar1)
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim0C)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim0D)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            EVT_IF_FALSE(LVar1)
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim0C)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim0D)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            EVT_IF_FALSE(LVar1)
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim0E)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim10)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar2)
            EVT_IF_FALSE(LVar2)
                EVT_SET_CONST(LVar2, ANIM_TuffPuff_Anim0F)
            EVT_ELSE
                EVT_SET_CONST(LVar2, ANIM_TuffPuff_Anim11)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            EVT_IF_FALSE(LVar1)
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim0E)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim10)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar2)
            EVT_IF_FALSE(LVar2)
                EVT_SET_CONST(LVar2, ANIM_TuffPuff_Anim0F)
            EVT_ELSE
                EVT_SET_CONST(LVar2, ANIM_TuffPuff_Anim11)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            EVT_IF_FALSE(LVar1)
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim0F)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim11)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            EVT_IF_FALSE(LVar1)
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim02)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim03)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            EVT_IF_FALSE(LVar1)
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim02)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim03)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            EVT_IF_FALSE(LVar1)
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim0C)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim0D)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            EVT_IF_FALSE(LVar1)
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim0C)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim0D)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            EVT_IF_FALSE(LVar1)
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim02)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim03)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            EVT_IF_FALSE(LVar1)
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim06)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim07)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            EVT_IF_FALSE(LVar1)
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim0C)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim0D)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            EVT_IF_FALSE(LVar1)
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim02)
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_TuffPuff_Anim03)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    // do nothing
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
