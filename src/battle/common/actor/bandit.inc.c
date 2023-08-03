#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Bandit.h"

#define NAMESPACE A(bandit)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Init_Coin);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_TakeTurn);

BSS s32 N(DropCoinScript)[1];

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_COIN            = 2,
};

enum N(ActorVars) {
    AVAR_HasCoin        = 0, // has stolen coins
    AVAR_NumCoins       = 1, // number of coins stolen
    AVAR_Coin_NumCoins  = 1, // number of coins stolen also stored in coin actor
};

enum N(ActorParams) {
    DMG_TACKLE          = 2,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Bandit_Idle,
    STATUS_KEY_STONE,     ANIM_Bandit_Still,
    STATUS_KEY_SLEEP,     ANIM_Bandit_Sleep,
    STATUS_KEY_POISON,    ANIM_Bandit_Idle,
    STATUS_KEY_STOP,      ANIM_Bandit_Still,
    STATUS_KEY_STATIC,    ANIM_Bandit_Idle,
    STATUS_KEY_PARALYZE,  ANIM_Bandit_Still,
    STATUS_KEY_DIZZY,     ANIM_Bandit_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Bandit_Dizzy,
    STATUS_END,
};

s32 N(HoldingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Bandit_IdleHolding,
    STATUS_KEY_STONE,     ANIM_Bandit_StillHolding,
    STATUS_KEY_SLEEP,     ANIM_Bandit_Sleep,
    STATUS_KEY_POISON,    ANIM_Bandit_IdleHolding,
    STATUS_KEY_STOP,      ANIM_Bandit_StillHolding,
    STATUS_KEY_STATIC,    ANIM_Bandit_IdleHolding,
    STATUS_KEY_PARALYZE,  ANIM_Bandit_StillHolding,
    STATUS_KEY_DIZZY,     ANIM_Bandit_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Bandit_Dizzy,
    STATUS_END,
};

s32 N(CoinAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Bandit_Coin,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              70,
    STATUS_KEY_POISON,             20,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,               50,
    STATUS_KEY_STATIC,             30,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,             90,
    STATUS_KEY_STOP,              100,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 28 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -12 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_COIN,
        .posOffset = { 0, 30, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(CoinAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorPartBlueprint N(CoinParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_COIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(CoinAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_BANDIT,
    .level = 9,
    .maxHP = 5,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 40,
    .airLiftChance = 90,
    .hurricaneChance = 90,
    .spookChance = 90,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 1,
    .size = { 26, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 25 },
    .statusTextOffset = { 10, 25 },
};

ActorBlueprint N(coin) = {
    .flags = ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY,
    .type = ACTOR_TYPE_BANDIT,
    .level = 9,
    .maxHP = 5,
    .partCount = ARRAY_COUNT(N(CoinParts)),
    .partsData = N(CoinParts),
    .initScript = &N(EVS_Init_Coin),
    .statusTable = N(StatusTable),
    .escapeChance = 40,
    .airLiftChance = 90,
    .hurricaneChance = 90,
    .spookChance = 90,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 1,
    .size = { 26, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 25 },
    .statusTextOffset = { 10, 25 },
};

Vec3i N(CoinPos) = { NPC_DISPOSE_LOCATION };

Formation N(CoinFormation) = {
    ACTOR_BY_POS(N(coin), N(CoinPos), 0),
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HasCoin, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Dummy) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Init_Coin) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_Dummy)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Dummy)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_Dummy)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropCoin) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HasCoin, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(FALSE)
            // do nothing
        EVT_CASE_EQ(TRUE)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HasCoin, FALSE)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_COIN, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, FALSE)
            EVT_CALL(SummonEnemy, EVT_PTR(N(CoinFormation)), FALSE)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_COIN, LVar1, LVar2, LVar3)
            EVT_CALL(SetActorPos, LVarA, LVar1, LVar2, LVar3)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_COIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NumCoins, LVar0)
            EVT_CALL(SetActorVar, LVarA, AVAR_Coin_NumCoins, LVar0)
            EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(1.0))
            EVT_CALL(RandInt, 360, LVar0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            EVT_ADD(LVar2, 30)
            EVT_CALL(SetActorPos, LVarA, LVar1, LVar2, LVar3)
            EVT_CALL(SetActorSounds, LVarA, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(40.0), LVar0)
            EVT_CALL(SetGoalPos, LVarA, LVar1, 0, LVar3)
            EVT_CALL(JumpToGoal, LVarA, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, LVarA, SOUND_212)
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(20.0), LVar0)
            EVT_CALL(SetGoalPos, LVarA, LVar1, 0, LVar3)
            EVT_CALL(JumpToGoal, LVarA, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, LVarA, SOUND_212)
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(10.0), LVar0)
            EVT_CALL(SetGoalPos, LVarA, LVar1, 0, LVar3)
            EVT_CALL(JumpToGoal, LVarA, 5, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, LVarA, SOUND_212)
            EVT_LOOP(0)
                EVT_CALL(GetBattleFlags, LVar1)
                EVT_IF_FLAG(LVar1, BS_FLAGS1_PARTNER_ACTING)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_IF_NOT_FLAG(LVar1, BS_FLAGS1_100)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_WAIT(15)
            EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(1.0))
            EVT_CALL(SetActorSpeed, LVarA, EVT_FLOAT(6.0))
            EVT_SET(LVar0, -70)
            EVT_SET(LVar1, 0)
            EVT_SET(LVar2, 10)
            EVT_LABEL(5)
            EVT_CALL(GetActorPos, LVarA, LVar3, LVar4, LVar5)
            EVT_IF_EQ(LVar3, LVar0)
                EVT_GOTO(10)
            EVT_END_IF
            EVT_IF_LT(LVar3, LVar0)
                EVT_SET(LVar4, LVar0)
                EVT_SUB(LVar4, LVar3)
                EVT_IF_LT(LVar4, 30)
                    EVT_CALL(SetGoalPos, LVarA, LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, LVarA, 5, FALSE, TRUE, FALSE)
                    EVT_CALL(PlaySoundAtActor, LVarA, SOUND_212)
                EVT_ELSE
                    EVT_SET(LVar4, LVar3)
                    EVT_ADD(LVar3, 30)
                    EVT_CALL(SetGoalPos, LVarA, LVar3, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, LVarA, 0, FALSE, TRUE, FALSE)
                    EVT_CALL(PlaySoundAtActor, LVarA, SOUND_212)
                EVT_END_IF
            EVT_ELSE
                EVT_SET(LVar4, LVar3)
                EVT_SUB(LVar4, LVar0)
                EVT_IF_LT(LVar4, 30)
                    EVT_CALL(SetGoalPos, LVarA, LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, LVarA, 5, FALSE, TRUE, FALSE)
                    EVT_CALL(PlaySoundAtActor, LVarA, SOUND_212)
                EVT_ELSE
                    EVT_SUB(LVar3, 30)
                    EVT_CALL(SetGoalPos, LVarA, LVar3, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, LVarA, 0, FALSE, TRUE, FALSE)
                    EVT_CALL(PlaySoundAtActor, LVarA, SOUND_212)
                EVT_END_IF
            EVT_END_IF
            EVT_GOTO(5)
            EVT_LABEL(10)
            EVT_CALL(EnableActorBlur, LVarA, IDLE_SCRIPT_DISABLE)
            EVT_CALL(SetTargetActor, LVarA, ACTOR_PLAYER)
            EVT_CALL(SetGoalToTarget, LVarA)
            EVT_CALL(JumpToGoal, LVarA, 15, FALSE, FALSE, FALSE)
            EVT_CALL(GetGoalPos, LVarA, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_SMALL_GOLD_SPARKLE, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 0, 0)
            EVT_CALL(PlaySoundAtActor, LVarA, SOUND_211)
            EVT_CALL(GetActorVar, LVarA, AVAR_Coin_NumCoins, LVar0)
            EVT_CALL(AddCoin, LVar0)
            EVT_CALL(RemoveActor, LVarA)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_USE_ARRAY(EVT_PTR(N(DropCoinScript)))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_EXEC_GET_TID(N(EVS_DropCoin), ArrayVar(0))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bandit_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(ArrayVar(0), LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_CASE_OR_EQ(EVENT_HIT)
        EVT_CASE_OR_EQ(EVENT_SPIN_SMASH_LAUNCH_HIT)
            EVT_EXEC_GET_TID(N(EVS_DropCoin), ArrayVar(0))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bandit_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(ArrayVar(0), LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_EXEC_GET_TID(N(EVS_DropCoin), ArrayVar(0))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bandit_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_Bandit_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(ArrayVar(0), LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_EXEC_GET_TID(N(EVS_DropCoin), ArrayVar(0))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bandit_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_Bandit_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bandit_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(ArrayVar(0), LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_GET_TID(N(EVS_DropCoin), ArrayVar(0))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bandit_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(ArrayVar(0), LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_GET_TID(N(EVS_DropCoin), ArrayVar(0))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bandit_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bandit_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(ArrayVar(0), LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bandit_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bandit_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_JumpBack)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bandit_Run)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bandit_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bandit_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HasCoin, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_SET_CONST(LVar1, ANIM_Bandit_Idle)
                EVT_CASE_EQ(1)
                    EVT_SET_CONST(LVar1, ANIM_Bandit_IdleHolding)
            EVT_END_SWITCH
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_DEATH)
        EVT_CASE_OR_EQ(EVENT_SPIN_SMASH_LAUNCH_DEATH)
            EVT_EXEC_GET_TID(N(EVS_DropCoin), ArrayVar(0))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bandit_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bandit_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(ArrayVar(0), LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bandit_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_EXEC_GET_TID(N(EVS_DropCoin), ArrayVar(0))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bandit_Run)
            EVT_SET_CONST(LVar2, ANIM_Bandit_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(ArrayVar(0), LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_EXEC_GET_TID(N(EVS_DropCoin), ArrayVar(0))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bandit_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
            EVT_LOOP(0)
                EVT_IS_THREAD_RUNNING(ArrayVar(0), LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Bandit_Hurt)
            EVT_SET_CONST(LVar2, STATUS_FLAG_DIZZY)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Idle)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    // if carrying a coin, run away
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HasCoin, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_RunHolding)
        EVT_WAIT(30)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
        EVT_CALL(SetGoalPos, ACTOR_SELF, 300, 0, 0)
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetBattleFlagBits, BS_FLAGS1_BATTLE_FLED, TRUE)
        EVT_CALL(HideHealthBar, ACTOR_SELF)
        EVT_CALL(RemoveActor, ACTOR_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 50)
        EVT_SET(LVar1, 0)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Run)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Idle)
        EVT_WAIT(6)
    EVT_END_IF
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Walk)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 35, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20C2)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Tackle)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT(5)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(5)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Tackle)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_TACKLE, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            // dont steal coins if no damage, blocked
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LVar0)
            EVT_IF_LE(LVar0, 0)
                EVT_SET(LVar0, 1)
                EVT_GOTO(10)
            EVT_END_IF
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_FLAG(LVar0, BS_FLAGS1_ATK_BLOCKED)
                EVT_SET(LVar0, 1)
                EVT_GOTO(10)
            EVT_END_IF
            // cant steal coins if shrunk
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_SET(LVar0, 0)
                EVT_GOTO(10)
            EVT_END_IF
             // cant steal coins if player is stone
            EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_STONE)
                EVT_SET(LVar0, 0)
                EVT_GOTO(10)
            EVT_END_IF
            EVT_CALL(AddCoin, 0)
            // choose outcome based on stolen coin count
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_SET(LVar0, 1)
                EVT_CASE_LT(10)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NumCoins, LVar0)
                    EVT_SET(LVar0, 2)
                EVT_CASE_GE(10)
                    // cap num stolen to 10
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NumCoins, 10)
                    EVT_SET(LVar0, 2)
            EVT_END_SWITCH
            EVT_LABEL(10)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    // couldn't steal (from shrunk or player stone)
                    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_ADD(LVar0, 30)
                    EVT_SET(LVar1, 0)
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Idle)
                    EVT_WAIT(20)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Run)
                EVT_CASE_EQ(1)
                    // failed to steal (player blocked or damage negated)
                    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_ADD(LVar0, 30)
                    EVT_SET(LVar1, 0)
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_LookUp)
                    EVT_WAIT(20)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20C3)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Sleep)
                    EVT_WAIT(20)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_Run)
                EVT_CASE_DEFAULT
                    // stole coins
                    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                    EVT_CALL(GetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
                    EVT_ADD(LVarA, 30)
                    EVT_SET(LVarB, 0)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NumCoins, LVar0)
                    EVT_MUL(LVar0, -1)
                    EVT_CALL(AddCoin, LVar0)
                    EVT_THREAD
                        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_COIN, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
                        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_COIN, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_COIN, LVar0, LVar1, LVar2)
                        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_COIN, EVT_FLOAT(1.0))
                        EVT_ADD(LVarB, 30)
                        EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_COIN, LVarA, LVarB, LVarC, 22, TRUE)
                        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_COIN, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, FALSE)
                    EVT_END_THREAD
                    EVT_THREAD
                        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NumCoins, LVar0)
                        EVT_LOOP(LVar0)
                            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_212)
                            EVT_WAIT(1)
                        EVT_END_LOOP
                    EVT_END_THREAD
                    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(HoldingAnims)))
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_LookUp)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HasCoin, 1)
                    EVT_WAIT(7)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_GotCoin)
                    EVT_WAIT(20)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Bandit_RunHolding)
            EVT_END_SWITCH
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
