#include "../area.h"
#include "sprite/npc/KentCKoopa.h"
#include "sprite/player.h"
#include "sprite/npc/Coin.h"

#define NAMESPACE A(kent_c_koopa)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

extern EvtScript N(EVS_KentC_GoHome);
extern EvtScript N(EVS_Flipped_SpinSmashHit);
extern EvtScript N(EVS_Flipped_SpinSmashDeath);
extern EvtScript N(EVS_FlipOver);
extern EvtScript N(EVS_Attack_ShellToss);
extern EvtScript N(EVS_Attack_HeavyStomp);

extern EvtScript N(EVS_DropDummyCoins);
extern EvtScript N(EVS_DropDummyCoin);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_FLIPPED         = 2, // targetable body while flipped
    PRT_WEAK_POINT      = 3, // the tail
    PRT_DUMMY_COIN_1    = 4,
    PRT_DUMMY_COIN_2    = 5,
    PRT_DUMMY_COIN_3    = 6,
    PRT_DUMMY_COIN_4    = 7,
    PRT_DUMMY_COIN_5    = 8,
    PRT_DUMMY_COIN_6    = 9,
};

enum N(ActorVars) {
    AVAR_IsFlipped          = 0,
    AVAR_Anim_Hurt          = 1,
    AVAR_FlippedTurns       = 2, // turns left to remain flipped
    AVAR_CoinsToDrop        = 3, // remaining coins that can drop via Spin Smashing while flipped over
    AVAR_FlipResistance     = 4, // number of hits before flipping over
};

enum N(ActorParams) {
    DMG_SHELL_TOSS_PLAYER   = 3,
    DMG_SHELL_TOSS_PARTNER  = 3,
    DMG_HEAVY_STOMP         = 10,
};

s32 N(FlipPosOffsets)[] = { 9, 16, 22, 26, 30, 32, 33, 32, 30, 26, 22, 16, 9, 0, 4, 6, 7, 6, 4, 0, 2, 0 };

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_KentCKoopa_Anim01,
    STATUS_KEY_STONE,     ANIM_KentCKoopa_Anim00,
    STATUS_KEY_SLEEP,     ANIM_KentCKoopa_Anim13,
    STATUS_KEY_POISON,    ANIM_KentCKoopa_Anim01,
    STATUS_KEY_STOP,      ANIM_KentCKoopa_Anim00,
    STATUS_KEY_STATIC,    ANIM_KentCKoopa_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_KentCKoopa_Anim00,
    STATUS_KEY_DIZZY,     ANIM_KentCKoopa_Anim14,
    STATUS_KEY_FEAR,      ANIM_KentCKoopa_Anim00,
    STATUS_END,
};

s32 N(FlippedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_KentCKoopa_Anim1A,
    STATUS_KEY_STOP,      ANIM_KentCKoopa_Anim19,
    STATUS_KEY_PARALYZE,  ANIM_KentCKoopa_Anim19,
    STATUS_END,
};

s32 N(CoinAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Coin_Rotate,
    STATUS_END,
};

s32 N(NormalDefense)[] = {
    ELEMENT_NORMAL,   6,
    ELEMENT_BLAST,    6,
    ELEMENT_END,
};

s32 N(FlippedDefense)[] = {
    ELEMENT_NORMAL,   3,
    ELEMENT_END,
};

s32 N(FlippedTailDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              80,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              30,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           30,
    STATUS_KEY_SHRINK,             40,
    STATUS_KEY_STOP,               50,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 60 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(NormalDefense),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_FLIPPED,
        .posOffset = { 12, 61, 0 },
        .targetOffset = { 0, -20 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(FlippedDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_WEAK_POINT,
        .posOffset = { 45, 0, 0 },
        .targetOffset = { -70, 26 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(FlippedTailDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_DUMMY_COIN_1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(CoinAnims),
        .defenseTable = N(FlippedTailDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_DUMMY_COIN_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(CoinAnims),
        .defenseTable = N(FlippedTailDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_DUMMY_COIN_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(CoinAnims),
        .defenseTable = N(FlippedTailDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_DUMMY_COIN_4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(CoinAnims),
        .defenseTable = N(FlippedTailDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_DUMMY_COIN_5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(CoinAnims),
        .defenseTable = N(FlippedTailDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_DUMMY_COIN_6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(CoinAnims),
        .defenseTable = N(FlippedTailDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_KENT_C_KOOPA,
    .level = 55,
    .maxHP = 70,
    .partCount = ARRAY_COUNT( N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 70,
    .coinReward = 0,
    .size = { 90, 70 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -26, 38 },
    .statusTextOffset = { 2, 63 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(func_8027D434, ACTOR_SELF, 3, 70)
    EVT_CALL(SetPartSize, ACTOR_SELF, PRT_WEAK_POINT, 30, 30)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsFlipped, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, ANIM_KentCKoopa_Anim1C)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FlippedTurns, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CoinsToDrop, 20)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, 2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, 2)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(GetLastElement, LVarE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVarD)
    EVT_SWITCH(LVarD)
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, 2)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, 2)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET(LVar0, 1)
                EVT_SET(LVar1, ANIM_KentCKoopa_Anim15)
                EVT_SET(LVar2, ANIM_KentCKoopa_Anim16)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_ELSE
                EVT_SET(LVar0, 1)
                EVT_SET(LVar1, ANIM_KentCKoopa_Anim17)
                EVT_SET(LVar2, ANIM_KentCKoopa_Anim18)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET(LVar0, 1)
                EVT_SET(LVar1, ANIM_KentCKoopa_Anim15)
                EVT_SET(LVar2, ANIM_KentCKoopa_Anim16)
            EVT_ELSE
                EVT_SET(LVar0, 1)
                EVT_SET(LVar1, ANIM_KentCKoopa_Anim17)
                EVT_SET(LVar2, ANIM_KentCKoopa_Anim18)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, LVar2)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, 2)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                EVT_EXEC_WAIT(N(EVS_Flipped_SpinSmashHit))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                EVT_EXEC_WAIT(N(EVS_Flipped_SpinSmashDeath))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_JumpBack)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_JumpBack)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim09)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim1A)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, 2)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim09)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar2)
                EVT_IF_EQ(LVar2, 0)
                    EVT_WAIT(20)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim0C)
                    EVT_WAIT(8)
                EVT_END_IF
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim1A)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET(LVar1, ANIM_KentCKoopa_Anim01)
            EVT_ELSE
                EVT_SET(LVar1, ANIM_KentCKoopa_Anim1A)
            EVT_END_IF
            EVT_SET(LVar0, 1)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(EVS_KentC_GoHome))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim01)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_EXEC_WAIT(EVS_Enemy_Recover)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim1A)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim12)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
                EVT_RETURN
            EVT_END_IF
            // each flip trigger decrements AVAR_FlipResistance by 1
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_FlipResistance, LVar0)
            EVT_IF_GT(LVar0, 0)
                EVT_SUB(LVar0, 1)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, LVar0)
            EVT_END_IF
            // POW blocks immediately set AVAR_FlipResistance to 0
            EVT_CALL(GetDamageSource, LVar0)
            EVT_IF_EQ(LVar0, DMG_SRC_POW_BLOCK)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, 0)
            EVT_END_IF
            // if AVAR_FlipResistance is depleted, flip over
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_FlipResistance, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(GetBattleFlags, LVarD)
                EVT_IF_FLAG(LVarD, BS_FLAGS1_SP_EVT_ACTIVE)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, 2)
                EVT_END_IF
                EVT_EXEC_WAIT(N(EVS_FlipOver))
            EVT_ELSE
                EVT_CALL(GetBattleFlags, LVarD)
                EVT_IF_FLAG(LVarD, BS_FLAGS1_SP_EVT_ACTIVE)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, 2)
                    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
                    EVT_IF_GT(LVar0, 0)
                        EVT_SET_CONST(LVar0, PRT_MAIN)
                        EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim1C)
                        EVT_EXEC_WAIT(EVS_Enemy_Hit)
                    EVT_ELSE
                        EVT_SET_CONST(LVar0, PRT_MAIN)
                        EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim09)
                        EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar2)
                        EVT_IF_EQ(LVar2, 0)
                            EVT_WAIT(20)
                            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim0C)
                            EVT_WAIT(8)
                        EVT_END_IF
                    EVT_END_IF
                EVT_ELSE
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim1C)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/StartRumbleWithParams.inc.c"
#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, 2)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
        EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
        EVT_CALL(SetBattleCamZoom, 200)
        EVT_CALL(SetBattleCamOffsetZ, 20)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 25)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_FlippedTurns, LVar0)
        EVT_SUB(LVar0, 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FlippedTurns, LVar0)
        EVT_IF_GT(LVar0, 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 36)
            EVT_ADD(LVar1, 18)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(3.0))
            EVT_LOOP(5)
                EVT_PLAY_EFFECT(EFFECT_SWEAT, 1, LVar0, LVar1, LVar2, 1, 225, 10, 0)
                EVT_WAIT(5)
            EVT_END_LOOP
            EVT_WAIT(30)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0))
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 36)
            EVT_ADD(LVar1, 18)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(3.0))
            EVT_LOOP(5)
                EVT_PLAY_EFFECT(EFFECT_SWEAT, 1, LVar0, LVar1, LVar2, 1, 225, 10, 0)
                EVT_WAIT(5)
            EVT_END_LOOP
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(3.0))
            EVT_WAIT(30)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 15)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim19)
            EVT_THREAD
                EVT_WAIT(3)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 27, 0)
                EVT_ELSE
                    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 10, 0)
                EVT_END_IF
                EVT_SET(LVar0, 0)
                EVT_LOOP(5)
                    EVT_ADD(LVar0, 36)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_CALL(N(StartRumbleWithParams), 80, 14)
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
            EVT_END_IF
            EVT_WAIT(3)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim0C)
            EVT_WAIT(10)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(NormalDefense)))
            EVT_CALL(SetEnemyTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 60)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_WEAK_POINT, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_WEAK_POINT, ACTOR_PART_FLAG_MULTI_TARGET, FALSE)
            EVT_CALL(SetPartFlags, ACTOR_SELF, PRT_FLIPPED, ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_4)
            EVT_CALL(SetPartFlags, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_MULTI_TARGET | ACTOR_PART_FLAG_4)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
            EVT_CALL(N(SetAbsoluteStatusOffsets), -26, 38, 2, 63)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsFlipped, FALSE)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, ANIM_KentCKoopa_Anim1C)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(RandInt, 100, LVar0)
    EVT_IF_LT(LVar0, 50)
        EVT_CALL(GetStatusFlags, ACTOR_PARTNER, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_KO)
            EVT_EXEC_WAIT(N(EVS_Attack_ShellToss))
        EVT_ELSE
            EVT_EXEC_WAIT(N(EVS_Attack_HeavyStomp))
        EVT_END_IF
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_Attack_HeavyStomp))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_ShellToss) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(SetBattleCamOffsetZ, 20)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 25)
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim0B)
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
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_370)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim0A)
    EVT_WAIT(10)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 3, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarB, 0, 0, 3, BS_FLAGS1_10)
            EVT_SWITCH(LVarB)
                EVT_CASE_EQ(6)
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    EVT_CALL(MoveBattleCamOver, 30)
                    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_SUB(LVar0, 40)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
                    EVT_CALL(SetGoalPos, ACTOR_SELF, -240, 0, LVar2)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(SetActorPos, ACTOR_SELF, 240, 0, LVar2)
                    EVT_CALL(SetGoalToHome, ACTOR_SELF)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
                    EVT_CALL(StopSound, SOUND_370)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim0C)
                    EVT_WAIT(8)
                    EVT_CALL(YieldTurn)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim01)
                    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
                    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                    EVT_RETURN
                EVT_CASE_DEFAULT
                    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
                    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_TRANSPARENT | STATUS_FLAGS_IMMOBILIZED)
                        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
                        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Flail)
                    EVT_END_IF
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
                    EVT_CALL(SetBattleCamTarget, -25, 60, 0)
                    EVT_CALL(SetBattleCamZoom, 460)
                    EVT_CALL(SetBattleCamOffsetZ, 0)
                    EVT_CALL(MoveBattleCamOver, 50)
                    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
                        EVT_ADD(LVar0, 32)
                    EVT_ELSE
                        EVT_ADD(LVar0, 12)
                    EVT_END_IF
                    EVT_SET(LVar1, 0)
                    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                    EVT_IF_EQ(LVarA, 5)
                        EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                    EVT_END_IF
                    EVT_SET(LVarA, 1)
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamTarget, -25, 60, 0)
            EVT_CALL(SetBattleCamZoom, 460)
            EVT_CALL(SetBattleCamOffsetZ, 0)
            EVT_CALL(MoveBattleCamOver, 50)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
            EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_TRANSPARENT | STATUS_FLAGS_IMMOBILIZED)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Flail)
            EVT_END_IF
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_ADD(LVar0, 32)
            EVT_ELSE
                EVT_ADD(LVar0, 12)
            EVT_END_IF
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarE)
            EVT_IF_NOT_FLAG(LVarE, STATUS_FLAG_SHRINK)
                EVT_CALL(SetDamageSource, DMG_SRC_CRUSH)
            EVT_END_IF
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, SUPPRESS_EVENT_ALL, 0, DMG_SHELL_TOSS_PLAYER, BS_FLAGS1_SP_EVT_ACTIVE)
            EVT_SET(LVarA, 0)
            EVT_IF_NOT_FLAG(LVarE, STATUS_FLAG_SHRINK)
                EVT_CALL(GetBattleFlags, LVar0)
                EVT_IF_NOT_FLAG(LVar0, BS_FLAGS1_ATK_BLOCKED)
                    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
                    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_STONE)
                        EVT_SET(LVarA, 1)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_IF_NE(LVarA, 0)
        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 32)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(SetDamageSource, DMG_SRC_CRUSH_PARTNER)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, DMG_SHELL_TOSS_PARTNER, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CALL(GetBattleFlags, LVar0)
        EVT_IF_NOT_FLAG(LVar0, BS_FLAGS1_ATK_BLOCKED)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, -240, 0, LVar2)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetActorPos, ACTOR_SELF, 240, 0, LVar2)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(StopSound, SOUND_370)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim0C)
            EVT_WAIT(8)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim01)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamTarget, -45, 60, 0)
            EVT_CALL(SetBattleCamZoom, 460)
            EVT_CALL(SetBattleCamOffsetZ, 0)
            EVT_CALL(MoveBattleCamOver, 30)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
        EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
            EVT_CALL(N(StartRumbleWithParams), 80, 14)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_ADD(LVar0, 16)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
        EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
            EVT_CALL(N(StartRumbleWithParams), 80, 14)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_ADD(LVar0, 10)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
        EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
            EVT_CALL(N(StartRumbleWithParams), 80, 14)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(StopSound, SOUND_370)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim0C)
    EVT_WAIT(8)
    EVT_CALL(YieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim04)
    EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim01)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_HeavyStomp) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(SetBattleCamZoom, 280)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim03)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim01)
    EVT_WAIT(8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3E7)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim06)
            EVT_THREAD
                EVT_WAIT(7)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim07)
                EVT_WAIT(4)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim08)
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EC)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_SUB(LVar0, 15)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EC)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim01)
            EVT_SUB(LVar0, 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EC)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_WAIT(8)
            EVT_IF_EQ(LVarA, 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_SET(LVar3, 0)
            EVT_LOOP(12)
                EVT_ADD(LVar3, 15)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar3)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim04)
            EVT_CALL(SetPartYaw, ACTOR_SELF, PRT_MAIN, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim01)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_SET(LVar3, 180)
            EVT_LOOP(15)
                EVT_SUB(LVar3, 12)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar3)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim06)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim07)
        EVT_WAIT(2)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim08)
    EVT_END_THREAD
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.3))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 14, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarF)
    EVT_IF_NOT_FLAG(LVarF, STATUS_FLAG_SHRINK)
        EVT_CALL(SetDamageSource, DMG_SRC_CRUSH)
    EVT_END_IF
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, SUPPRESS_EVENT_ALL, 0, DMG_HEAVY_STOMP, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_NOT_FLAG(LVar0, BS_FLAGS1_ATK_BLOCKED)
                EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_STONE)
                    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarE)
                    EVT_IF_NOT_FLAG(LVarE, STATUS_FLAG_SHRINK)
                        EVT_CALL(LandJump, ACTOR_SELF)
                        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EC)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
            EVT_THREAD
                EVT_CALL(N(StartRumbleWithParams), 80, 14)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim06)
            EVT_END_THREAD
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EC)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim01)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EC)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_WAIT(8)
            EVT_IF_EQ(LVarF, 10)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_EXEC_WAIT(N(EVS_KentC_GoHome))
        EVT_CASE_EQ(HIT_RESULT_3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KentC_GoHome) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_SET_CONST(LVar1, ANIM_KentCKoopa_Anim04)
    EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FlipOver) = {
    EVT_CALL(SetEnemyTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 40)
    EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(FlippedDefense)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(FlippedAnims)))
    EVT_CALL(N(SetAbsoluteStatusOffsets), -24, 47, 23, 37)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim1C)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsFlipped, TRUE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, ANIM_KentCKoopa_Anim12)
    EVT_THREAD
        EVT_WAIT(4)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 35, 0)
        EVT_ELSE
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
        EVT_END_IF
        EVT_SET(LVar0, 0)
        EVT_LOOP(5)
            EVT_SUB(LVar0, 18)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_USE_BUF(EVT_PTR(N(FlipPosOffsets)))
    EVT_LOOP(ARRAY_COUNT(N(FlipPosOffsets)))
        EVT_BUF_READ1(LVar0)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
        EVT_IF_EQ(LVar0, 0)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
                    EVT_CALL(N(StartRumbleWithParams), 80, 14)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim1D)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim1E)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_WEAK_POINT, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_WEAK_POINT, ACTOR_PART_FLAG_MULTI_TARGET, TRUE)
    EVT_CALL(SetPartFlags, ACTOR_SELF, PRT_FLIPPED, ACTOR_PART_FLAG_4)
    EVT_CALL(SetPartFlags, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_4)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FlippedTurns, 1)
    EVT_WAIT(8)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Flipped_SpinSmashHit) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_SET(LVarA, 5)
    EVT_EXEC_WAIT(N(EVS_DropDummyCoins))
    EVT_SET(LVar2, 0)
    EVT_LOOP(36)
        EVT_ADD(LVar2, 30)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Flipped_SpinSmashDeath) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_SET(LVarA, 0)
    EVT_EXEC_WAIT(N(EVS_DropDummyCoins))
    EVT_SET(LVar2, 0)
    EVT_LOOP(48)
        EVT_ADD(LVar2, 30)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_WAIT(10)
    EVT_SET(LVar0, PRT_MAIN)
    EVT_SET(LVar1, -1)
    EVT_EXEC_WAIT(EVS_Enemy_Death)
    EVT_RETURN
    EVT_END
};

// when hit with Spin Smash while flipped over, coins fly out
// (in) LVarA : delay between each coin release
EvtScript N(EVS_DropDummyCoins) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_CoinsToDrop, LVar3)
    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar4)
    EVT_IF_GT(LVar4, LVar3)
        EVT_SET(LVar4, LVar3)
    EVT_END_IF
    EVT_IF_GT(LVar4, 6)
        EVT_SET(LVar4, 6)
    EVT_END_IF
    EVT_IF_GT(LVar4, 0)
        EVT_THREAD
            EVT_SUB(LVar3, LVar4)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CoinsToDrop, LVar3)
            EVT_SET(LVar5, PRT_DUMMY_COIN_1)
            EVT_LOOP(LVar4)
                EVT_EXEC(N(EVS_DropDummyCoin))
                EVT_ADD(LVar5, 1)
                EVT_WAIT(LVarA)
            EVT_END_LOOP
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(GetCoinTrajectory)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    f32 angle = rand_int(360);

    f32 centerX = x;
    f32 centerZ = z;

    s32 startX = centerX + cos_deg(angle) * 46.0f;
    s32 startZ = centerZ + sin_deg(angle) * 46.0f;
    s32 endX = centerX + cos_deg(angle) * 62.0f;
    s32 endZ = centerZ + sin_deg(angle) * 62.0f;

    evt_set_variable(script, *args++, startX);
    evt_set_variable(script, *args++, startZ);
    evt_set_variable(script, *args++, endX);
    evt_set_variable(script, *args++, endZ);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(UnusedFunc)) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var1 = *args++;

    evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_DropDummyCoin) = {
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, LVar5, SOUND_212)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar6, LVar7, LVar8)
    EVT_CALL(SetPartPos, ACTOR_SELF, LVar5, LVar6, 35, LVar8)
    EVT_CALL(N(GetCoinTrajectory), LVar6, LVar8, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar5, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar5, EVT_FLOAT(1.0))
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar5, LVar0, 0, LVar1, 18, TRUE)
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar5, LVar2, 0, LVar3, 9, TRUE)
    EVT_WAIT(10)
    // blinking
    EVT_LOOP(10)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar5, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        EVT_WAIT(1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar5, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_WAIT(1)
    EVT_END_LOOP
    // give coin to player
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, LVar5, SOUND_211)
    EVT_CALL(AddCoin, 1)
    EVT_RETURN
    EVT_END
};
