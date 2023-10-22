#include "../area.h"
#include "sprite/npc/ChainChomp.h"
#include "sprite/npc/Tutankoopa.h"
#include "tutankoopa_common.h"

#define NAMESPACE A(chain_chomp)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_UpdateChain);
extern EvtScript N(EVS_Chomp_SpinSmashHit);
extern EvtScript N(EVS_Chomp_HopHome);
extern EvtScript N(EVS_Chomp_HopToPos);

enum N(ActorVars) {
    AVAR_EnableChainSounds      = 8,
};

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_TARGET          = 2,
    PRT_CHAIN_1         = 3,
    PRT_CHAIN_2         = 4,
    PRT_CHAIN_3         = 5,
    PRT_CHAIN_4         = 6,
    PRT_CHAIN_5         = 7,
    PRT_CHAIN_6         = 8,
    PRT_CHAIN_7         = 9,
    PRT_CHAIN_8         = 10,
};

enum N(ActorParams) {
    DMG_CHOMP_BITE      = 3,
};

s32 N(BasicAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ChainChomp_Idle,
    STATUS_KEY_STONE,     ANIM_ChainChomp_Still,
    STATUS_KEY_SLEEP,     ANIM_ChainChomp_Sleep,
    STATUS_KEY_POISON,    ANIM_ChainChomp_Idle,
    STATUS_KEY_STOP,      ANIM_ChainChomp_Still,
    STATUS_KEY_STATIC,    ANIM_ChainChomp_Still,
    STATUS_KEY_PARALYZE,  ANIM_ChainChomp_Still,
    STATUS_KEY_DIZZY,     ANIM_ChainChomp_Dizzy,
    STATUS_END,
};

s32 N(QuickBiteAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ChainChomp_QuickBite,
    STATUS_KEY_POISON,    ANIM_ChainChomp_QuickBite,
    STATUS_KEY_STOP,      ANIM_ChainChomp_Still,
    STATUS_KEY_STONE,     ANIM_ChainChomp_Still,
    STATUS_KEY_SLEEP,     ANIM_ChainChomp_Sleep,
    STATUS_KEY_STATIC,    ANIM_ChainChomp_Still,
    STATUS_KEY_PARALYZE,  ANIM_ChainChomp_Still,
    STATUS_KEY_DIZZY,     ANIM_ChainChomp_Dizzy,
    STATUS_END,
};

s32 N(BiteAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ChainChomp_Bite,
    STATUS_KEY_POISON,    ANIM_ChainChomp_Bite,
    STATUS_KEY_STOP,      ANIM_ChainChomp_Still,
    STATUS_KEY_STONE,     ANIM_ChainChomp_Still,
    STATUS_KEY_SLEEP,     ANIM_ChainChomp_Sleep,
    STATUS_KEY_STATIC,    ANIM_ChainChomp_Still,
    STATUS_KEY_PARALYZE,  ANIM_ChainChomp_Still,
    STATUS_KEY_DIZZY,     ANIM_ChainChomp_Dizzy,
    STATUS_END,
};

s32 N(SlowBiteAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ChainChomp_SlowBite,
    STATUS_KEY_POISON,    ANIM_ChainChomp_SlowBite,
    STATUS_KEY_STOP,      ANIM_ChainChomp_Still,
    STATUS_KEY_STONE,     ANIM_ChainChomp_Still,
    STATUS_KEY_SLEEP,     ANIM_ChainChomp_Sleep,
    STATUS_KEY_STATIC,    ANIM_ChainChomp_Still,
    STATUS_KEY_PARALYZE,  ANIM_ChainChomp_Still,
    STATUS_KEY_DIZZY,     ANIM_ChainChomp_Dizzy,
    STATUS_END,
};

s32 N(ChainAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ChainChomp_Chain,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   3,
    ELEMENT_SHOCK,    3,
    ELEMENT_FIRE,    99,
    ELEMENT_ICE,     99,
    ELEMENT_MAGIC,   99,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               75,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(BasicAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_TARGET,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -13, 40 },
        .opacity = 255,
        .idleAnimations = N(BasicAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -16 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_TARGET_ONLY | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_CHAIN_1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(ChainAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_TARGET_ONLY | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_CHAIN_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(ChainAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_TARGET_ONLY | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_CHAIN_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(ChainAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_TARGET_ONLY | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_CHAIN_4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(ChainAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_TARGET_ONLY | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_CHAIN_5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(ChainAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_TARGET_ONLY | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_CHAIN_6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(ChainAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_TARGET_ONLY | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_CHAIN_7,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(ChainAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_TARGET_ONLY | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_CHAIN_8,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(ChainAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_CHOMP,
    .level = ACTOR_LEVEL_CHOMP,
    .maxHP = 4,
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
    .powerBounceChance = 95,
    .coinReward = 0,
    .size = { 56, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

#define CHOMP_CHAIN_FIRST_PART_IDX  PRT_CHAIN_1
#define CHOMP_CHAIN_LAST_PART_IDX   PRT_CHAIN_8
#define CHOMP_CHAIN_AVAR_SOUNDS     AVAR_EnableChainSounds
#define CHOMP_CHAIN_UPDATE_Z        TRUE
#include "common/battle/ChompChainSupport.inc.c"

API_CALLABLE(func_8021866C_4EFB0C) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = *args++;

    evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Init) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_EnableChainSounds, FALSE)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_TARGET, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, PRT_CHAIN_1)
    EVT_LOOP(1 + (PRT_CHAIN_8 - PRT_CHAIN_1))
        EVT_CALL(SetPartSize, ACTOR_SELF, LVar0, 16, 16)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_CALL(N(ChompChainInit))
    EVT_EXEC(N(EVS_UpdateChain))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateTargetPartPos) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_TARGET, LVar0, LVar1, LVar2)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_TARGET, 0, 24)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_TARGET, 0, 0)
    EVT_ELSE
        EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
        EVT_CALL(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_TARGET, LVar0, LVar1, LVar2)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_TARGET, -13, 40)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_TARGET, 0, -14)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_LOOP(0)
            EVT_EXEC_WAIT(N(EVS_UpdateTargetPartPos))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(SlowBiteAnims)))
        EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
        EVT_CALL(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 10)
        EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 11, 1)
        EVT_LOOP(0)
            EVT_EXEC_WAIT(N(EVS_UpdateTargetPartPos))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
        EVT_CALL(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 6, 1)
        EVT_CALL(RandInt, 10, LVar0)
        EVT_ADD(LVar0, 1)
        EVT_WAIT(LVar0)
        EVT_LOOP(0)
            EVT_EXEC_WAIT(N(EVS_UpdateTargetPartPos))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(BiteAnims)))
        EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
        EVT_CALL(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 15, 1)
        EVT_LOOP(0)
            EVT_EXEC_WAIT(N(EVS_UpdateTargetPartPos))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(SlowBiteAnims)))
        EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
        EVT_CALL(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 20)
        EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 12, 1)
        EVT_LOOP(0)
            EVT_EXEC_WAIT(N(EVS_UpdateTargetPartPos))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
        EVT_CALL(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 10)
        EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 9, 1)
        EVT_LOOP(0)
            EVT_EXEC_WAIT(N(EVS_UpdateTargetPartPos))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(QuickBiteAnims)))
        EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
        EVT_CALL(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 6, 1)
        EVT_CALL(RandInt, 10, LVar0)
        EVT_ADD(LVar0, 10)
        EVT_WAIT(LVar0)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateChain) = {
    EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_CALL(ActorExists, ACTOR_CHOMP, LVar0)
        EVT_IF_EQ(LVar0, TRUE)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(N(ChompChainUpdate), LVar2)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_LABEL(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Hurt)
            EVT_SET_CONST(LVar2, -1)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Hurt)
            EVT_SET_CONST(LVar2, -1)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_WAIT(10)
            EVT_CALL(SetActorVar, ACTOR_TUTANKOOPA, AVAR_Tutankoopa_NextSummonTime, 2)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Hurt)
            EVT_EXEC_WAIT(N(EVS_Chomp_SpinSmashHit))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Hurt)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
            EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 15, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 5, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_SlowBite)
            EVT_EXEC_WAIT(N(EVS_Chomp_HopHome))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
            EVT_END_THREAD
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetPartPos, ACTOR_SELF, PRT_TARGET, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_EnableChainSounds, FALSE)
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_CALL(SetGoalToHome, ACTOR_SELF)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
                EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_SUB(LVar1, 10)
                    EVT_ADD(LVar2, 4)
                EVT_ELSE
                    EVT_SUB(LVar1, 5)
                    EVT_ADD(LVar2, 11)
                EVT_END_IF
                EVT_CALL(SetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0))
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_EnableChainSounds, FALSE)
            EVT_WAIT(10)
            EVT_CALL(SetActorVar, ACTOR_TUTANKOOPA, AVAR_Tutankoopa_NextSummonTime, 2)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_CALL(SetActorVar, ACTOR_TUTANKOOPA, AVAR_Tutankoopa_NextSummonTime, 2)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Hurt)
            EVT_EXEC_WAIT(N(EVS_Chomp_SpinSmashHit))
            EVT_CALL(SetActorVar, ACTOR_TUTANKOOPA, AVAR_Tutankoopa_NextSummonTime, 2)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_IF_NE(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
            EVT_CALL(FallToGoal, ACTOR_SELF, 11)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Chomp_SpinSmashHit) = {
    EVT_CALL(ActorExists, ACTOR_TUTANKOOPA, LVar0)
    EVT_IF_EQ(LVar0, FALSE)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_TUTANKOOPA, AVAR_Tutankoopa_Stunned, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_LABEL(0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_Hurt)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_TUTANKOOPA)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 20, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, 150, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 130, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(15)
    EVT_GOTO(10)
    EVT_LABEL(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_Hurt)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, 135, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 105, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT(15)
    EVT_LABEL(10)
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_SET_CONST(LVar1, ANIM_ChainChomp_Idle)
    EVT_EXEC_WAIT(N(EVS_Chomp_HopHome))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_EnableChainSounds, TRUE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_ADD(LVar0, 45)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_SlowBite)
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_HURT)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(PlaySound, SOUND_ACTOR_HURT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_Idle)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 25)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_SUB(LVar0, 15)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_Bite)
            EVT_WAIT(20)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Idle)
            EVT_EXEC_WAIT(N(EVS_Chomp_HopHome))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_Idle)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_EnableChainSounds, FALSE)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_Idle)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar0, 4)
    EVT_ELSE
        EVT_ADD(LVar0, 10)
    EVT_END_IF
    EVT_SET(LVar1, 27)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_TARGET, LVar0, LVar1, LVar2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, DMG_CHOMP_BITE, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVarF)
        EVT_CASE_DEFAULT
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_Bite)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_SUB(LVar0, 10)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_Idle)
            EVT_WAIT(8)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_IF_EQ(LVarF, HIT_RESULT_10)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(SetPartPos, ACTOR_SELF, PRT_TARGET, LVar0, LVar1, LVar2)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(YieldTurn)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ChainChomp_Idle)
            EVT_EXEC_WAIT(N(EVS_Chomp_HopHome))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_Idle)
    EVT_END_SWITCH
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_EnableChainSounds, FALSE)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

// Custom version of EVS_Enemy_HopHome
// (in) LVar0: part idx
// (in) LVar1: hopping animID
EvtScript N(EVS_Chomp_HopHome) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_Bite)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_EXEC_WAIT(N(EVS_Chomp_HopToPos))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_TARGET, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

// Custom version of EVS_Enemy_HopToPos
// (in) LVar0: target posX
// (in) LVar1: target posY
// (in) LVar2: target posZ
EvtScript N(EVS_Chomp_HopToPos) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_IF_LT(LVar3, LVar0)
        EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_ELSE
        EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_END_IF
    EVT_LABEL(0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_IF_EQ(LVar3, LVar0)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_IF_LT(LVar3, LVar0)
            EVT_SET(LVar4, LVar0)
            EVT_SUB(LVar4, LVar3)
            EVT_IF_LT(LVar4, 30)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
                EVT_THREAD
                    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                    EVT_END_IF
                EVT_END_THREAD
            EVT_ELSE
                EVT_SET(LVar4, LVar3)
                EVT_ADD(LVar3, 30)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar3, LVar1, LVar2)
                EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
                EVT_THREAD
                    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                    EVT_END_IF
                EVT_END_THREAD
            EVT_END_IF
        EVT_ELSE
            EVT_SET(LVar4, LVar3)
            EVT_SUB(LVar4, LVar0)
            EVT_IF_LT(LVar4, 30)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
                EVT_THREAD
                    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                    EVT_END_IF
                EVT_END_THREAD
            EVT_ELSE
                EVT_SUB(LVar3, 30)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar3, LVar1, LVar2)
                EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
                EVT_THREAD
                    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                    EVT_END_IF
                EVT_END_THREAD
            EVT_END_IF
        EVT_END_IF
        EVT_GOTO(0)
    EVT_LABEL(10)
    EVT_RETURN
    EVT_END
};
