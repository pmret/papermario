#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BonyBeetle.h"
#include "effects.h"

#define NAMESPACE A(bony_beetle)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandleEvent_SmoothUpright);
extern EvtScript N(EVS_HandleEvent_SpikyUpright);
extern EvtScript N(EVS_HandleEvent_SmoothToppled);
extern EvtScript N(EVS_HandleEvent_SpikyToppled);
extern EvtScript N(EVS_TrySwitchingSpikyState);
extern EvtScript N(EVS_TryGettingUp_Smooth);
extern EvtScript N(EVS_TryGettingUp_Spiky);
extern EvtScript N(EVS_Attack_ShellToss);
extern EvtScript N(EVS_Attack_SpikeBounce);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

enum N(ActorVars) {
    AVAR_IN_OnCeiling           = 0,
    AVAR_ShouldTrySwitching     = 1,
    AVAR_State                  = 8,
    AVAL_State_SmoothUpright    = 0,
    AVAL_State_SpikyUpright     = 1,
    AVAL_State_SmoothToppled    = 2,
    AVAL_State_SpikyToppled     = 3,
    AVAR_ToppleTurns            = 9,
};

enum N(ActorParams) {
    DMG_SHELL_TOSS      = 3,
    DMG_SPIKE_BOUNCE    = 5,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BonyBeetle_Anim04,
    STATUS_KEY_STONE,     ANIM_BonyBeetle_Anim00,
    STATUS_KEY_SLEEP,     ANIM_BonyBeetle_Anim2A,
    STATUS_KEY_POISON,    ANIM_BonyBeetle_Anim04,
    STATUS_KEY_STOP,      ANIM_BonyBeetle_Anim00,
    STATUS_KEY_STATIC,    ANIM_BonyBeetle_Anim04,
    STATUS_KEY_PARALYZE,  ANIM_BonyBeetle_Anim00,
    STATUS_KEY_DIZZY,     ANIM_BonyBeetle_Anim26,
    STATUS_KEY_FEAR,      ANIM_BonyBeetle_Anim26,
    STATUS_END,
};

s32 N(SpikyAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BonyBeetle_Anim05,
    STATUS_KEY_STONE,     ANIM_BonyBeetle_Anim01,
    STATUS_KEY_SLEEP,     ANIM_BonyBeetle_Anim2B,
    STATUS_KEY_POISON,    ANIM_BonyBeetle_Anim05,
    STATUS_KEY_STOP,      ANIM_BonyBeetle_Anim01,
    STATUS_KEY_STATIC,    ANIM_BonyBeetle_Anim05,
    STATUS_KEY_PARALYZE,  ANIM_BonyBeetle_Anim01,
    STATUS_KEY_DIZZY,     ANIM_BonyBeetle_Anim27,
    STATUS_KEY_FEAR,      ANIM_BonyBeetle_Anim27,
    STATUS_END,
};

s32 N(ToppledAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BonyBeetle_Anim06,
    STATUS_KEY_STONE,     ANIM_BonyBeetle_Anim02,
    STATUS_KEY_SLEEP,     ANIM_BonyBeetle_Anim2C,
    STATUS_KEY_POISON,    ANIM_BonyBeetle_Anim06,
    STATUS_KEY_STOP,      ANIM_BonyBeetle_Anim02,
    STATUS_KEY_STATIC,    ANIM_BonyBeetle_Anim06,
    STATUS_KEY_PARALYZE,  ANIM_BonyBeetle_Anim02,
    STATUS_KEY_DIZZY,     ANIM_BonyBeetle_Anim28,
    STATUS_KEY_FEAR,      ANIM_BonyBeetle_Anim28,
    STATUS_END,
};

s32 N(ToppledSpikyAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BonyBeetle_Anim07,
    STATUS_KEY_STONE,     ANIM_BonyBeetle_Anim03,
    STATUS_KEY_SLEEP,     ANIM_BonyBeetle_Anim2D,
    STATUS_KEY_POISON,    ANIM_BonyBeetle_Anim07,
    STATUS_KEY_STOP,      ANIM_BonyBeetle_Anim03,
    STATUS_KEY_STATIC,    ANIM_BonyBeetle_Anim07,
    STATUS_KEY_PARALYZE,  ANIM_BonyBeetle_Anim03,
    STATUS_KEY_DIZZY,     ANIM_BonyBeetle_Anim29,
    STATUS_KEY_FEAR,      ANIM_BonyBeetle_Anim29,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   4,
    ELEMENT_END,
};

s32 N(ToppledDefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              60,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               85,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -3, 21 },
        .opacity = 255,
        .idleAnimations = N(SpikyAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_BONY_BEETLE,
    .level = ACTOR_LEVEL_BONY_BEETLE,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 70,
    .hurricaneChance = 60,
    .spookChance = 60,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 27, 27 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IN_OnCeiling, LVar0)
    EVT_CALL(GetInstigatorValue, ACTOR_SELF, LVar1)
    EVT_IF_EQ(LVar0, 1)
        EVT_IF_EQ(LVar1, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SpikyUpright)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(SpikyAnims)))
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, TRUE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim05)
        EVT_ELSE
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SmoothUpright)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim04)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(RandInt, 1000, LVar0)
        EVT_IF_LT(LVar0, 500)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SmoothUpright)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim04)
        EVT_ELSE
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SpikyUpright)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(SpikyAnims)))
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, TRUE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim05)
        EVT_END_IF
    EVT_END_IF
EVT_END_IF
EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -8)
EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -3, 21)
EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_UPSIDE_DOWN, FALSE)
EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
EVT_CALL(HPBarToHome, ACTOR_SELF)
EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldTrySwitching, FALSE)
EVT_RETURN
EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_State_SmoothUpright)
            EVT_EXEC_WAIT(N(EVS_HandleEvent_SmoothUpright))
        EVT_CASE_EQ(AVAL_State_SpikyUpright)
            EVT_EXEC_WAIT(N(EVS_HandleEvent_SpikyUpright))
        EVT_CASE_EQ(AVAL_State_SmoothToppled)
            EVT_EXEC_WAIT(N(EVS_HandleEvent_SmoothToppled))
        EVT_CASE_EQ(AVAL_State_SpikyToppled)
            EVT_EXEC_WAIT(N(EVS_HandleEvent_SpikyToppled))
    EVT_END_SWITCH
    EVT_CALL(ActorExists, ACTOR_SELF, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ShouldTrySwitching, LVar0)
        EVT_IF_EQ(LVar0, TRUE)
            EVT_EXEC_WAIT(N(EVS_TrySwitchingSpikyState))
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldTrySwitching, FALSE)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TrySwitchingSpikyState) = {
    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
    EVT_IF_LE(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
        EVT_RETURN
    EVT_END_IF
    EVT_LABEL(0)
    EVT_CALL(GetBattleFlags, LVarA)
    EVT_IF_FLAG(LVarA, BS_FLAGS1_EXECUTING_MOVE)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_State_SmoothUpright)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BONY_BEETLE_EXTEND_SPIKES)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SpikyUpright)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, TRUE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim2E)
            EVT_WAIT(25)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(SpikyAnims)))
        EVT_CASE_EQ(AVAL_State_SpikyUpright)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BONY_BEETLE_RETRACT_SPIKES)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SmoothUpright)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim2F)
            EVT_WAIT(25)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
        EVT_CASE_EQ(AVAL_State_SmoothToppled)
        EVT_CASE_EQ(AVAL_State_SpikyToppled)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_State_SmoothUpright)
            EVT_EXEC_WAIT(N(EVS_Attack_ShellToss))
        EVT_CASE_EQ(AVAL_State_SpikyUpright)
            EVT_EXEC_WAIT(N(EVS_Attack_SpikeBounce))
        EVT_CASE_EQ(AVAL_State_SmoothToppled)
            EVT_EXEC_WAIT(N(EVS_TryGettingUp_Smooth))
        EVT_CASE_EQ(AVAL_State_SpikyToppled)
            EVT_EXEC_WAIT(N(EVS_TryGettingUp_Spiky))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(FlipPosOffsets)[] = { 7, 13, 17, 21, 23, 24, 23, 21, 17, 13, 7, 0, 4, 6, 7, 6, 4, 0, 2, 0 };

EvtScript N(EVS_HandleEvent_SmoothUpright) = {
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim18)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldTrySwitching, TRUE)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1E)
            EVT_SET_CONST(LVar2, ANIM_BonyBeetle_Anim1F)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldTrySwitching, TRUE)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1E)
            EVT_SET_CONST(LVar2, ANIM_BonyBeetle_Anim1F)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1F)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim18)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldTrySwitching, TRUE)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim18)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim18)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SmoothToppled)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -8)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -3, 21)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 1)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledDefenseTable)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledAnims)))
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, FALSE)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim08)
            EVT_USE_BUF(N(FlipPosOffsets))
            EVT_LOOP(20)
                EVT_BUF_READ1(LVar0)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_WAIT(20)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim18)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim18)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim10)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_WAIT(20)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim12)
                EVT_WAIT(10)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim18)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim18)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim18)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim18)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim0E)
            EVT_SET_CONST(LVar2, ANIM_BonyBeetle_Anim18)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim18)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_ShellToss) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim16)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim10)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        EVT_WAIT(10)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        EVT_WAIT(5)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_SPIN)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim16)
    EVT_WAIT(15)
    EVT_LABEL(100)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_TOSS)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 3, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 40)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim12)
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim0E)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim04)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
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
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, DMG_SHELL_TOSS, BS_FLAGS1_TRIGGER_EVENTS)
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
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim12)
            EVT_WAIT(5)
            EVT_CALL(YieldTurn)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim04)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent_SpikyUpright) = {
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim19)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldTrySwitching, TRUE)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim20)
            EVT_SET_CONST(LVar2, ANIM_BonyBeetle_Anim21)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldTrySwitching, TRUE)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim20)
            EVT_SET_CONST(LVar2, ANIM_BonyBeetle_Anim21)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim21)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim19)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShouldTrySwitching, TRUE)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim19)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim19)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SpikyToppled)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -8)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -3, 21)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 1)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledDefenseTable)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledSpikyAnims)))
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, FALSE)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim09)
            EVT_USE_BUF(N(FlipPosOffsets))
            EVT_LOOP(20)
                EVT_BUF_READ1(LVar0)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_WAIT(20)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim19)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim19)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim0F)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim11)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_WAIT(20)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim13)
            EVT_END_IF
            EVT_WAIT(10)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_WAIT(10)
            EVT_SET(LFlag0, FALSE)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_ADD(LVar0, -3)
                EVT_ADD(LVar1, 10)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
            EVT_IF_FLAG(LVar3, STATUS_FLAG_DIZZY)
                EVT_ADD(LVar0, 0)
                EVT_ADD(LVar1, 26)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_ADD(LVar0, -8)
                EVT_ADD(LVar1, 26)
            EVT_END_IF
            EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 20, 0)
            EVT_WAIT(20)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim19)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim19)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim19)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim19)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim05)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim0F)
            EVT_SET_CONST(LVar2, ANIM_BonyBeetle_Anim19)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_SpikeBounce) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim17)
        EVT_WAIT(10)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim11)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        EVT_WAIT(10)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 32, 6, 0, 10, 0)
        EVT_WAIT(5)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 32, 8, 0, 10, 0)
        EVT_WAIT(5)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 32, 10, 0, 10, 0)
        EVT_WAIT(5)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 32, 12, 0, 10, 0)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_SPIN)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim17)
    EVT_WAIT(15)
    EVT_LABEL(100)
    EVT_THREAD
        EVT_LOOP(20)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, 0, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_TOSS)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, DMG_SPIKE_BOUNCE, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(24.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_01)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                EVT_SET(LVar0, 0)
                EVT_LOOP(10)
                    EVT_ADD(LVar0, 18)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                EVT_SET(LVar0, 180)
                EVT_LOOP(15)
                    EVT_ADD(LVar0, 12)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 50)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                EVT_SET(LVar0, 0)
                EVT_LOOP(10)
                    EVT_ADD(LVar0, 18)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_SUB(LVar0, 40)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                EVT_SET(LVar0, 180)
                EVT_LOOP(5)
                    EVT_ADD(LVar0, 18)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_WAIT(5)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim0F)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(24.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, 18)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, DMG_SPIKE_BOUNCE, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                EVT_SET(LVar0, 180)
                EVT_LOOP(15)
                    EVT_ADD(LVar0, 12)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 50)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                EVT_SET(LVar0, 0)
                EVT_LOOP(10)
                    EVT_ADD(LVar0, 18)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_SUB(LVar0, 40)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                EVT_SET(LVar0, 180)
                EVT_LOOP(5)
                    EVT_ADD(LVar0, 18)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_WAIT(5)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim13)
            EVT_WAIT(5)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim0F)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

// unused
EvtScript N(EVS_FallFromCeiling) = {
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SmoothToppled)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 1)
    EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledDefenseTable)))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledAnims)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_UPSIDE_DOWN, FALSE)
    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -8)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -3, 21)
    EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim06)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 24)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent_SmoothToppled) = {
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1A)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim22)
            EVT_SET_CONST(LVar2, ANIM_BonyBeetle_Anim23)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim22)
            EVT_SET_CONST(LVar2, ANIM_BonyBeetle_Anim23)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim23)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1A)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1A)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1A)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SmoothToppled)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -8)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -3, 21)
            EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 1)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledDefenseTable)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledAnims)))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim1A)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
            EVT_USE_BUF(N(FlipPosOffsets))
            EVT_LOOP(20)
                EVT_BUF_READ1(LVar0)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_WAIT(20)
        EVT_CASE_OR_EQ(EVENT_SCARE_AWAY)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1A)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1A)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1A)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1A)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1A)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TryGettingUp_Smooth) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
    EVT_SUB(LVar0, 1)
    EVT_IF_GT(LVar0, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
        EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim1C)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim06)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_15)
        EVT_CALL(SetBattleCamZoom, 350)
        EVT_CALL(SetBattleCamOffsetZ, 20)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim1C)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim06)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim0A)
        EVT_WAIT(20)
        EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SmoothUpright)
        EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefenseTable)))
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, FALSE)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent_SpikyToppled) = {
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim24)
            EVT_SET_CONST(LVar2, ANIM_BonyBeetle_Anim25)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim24)
            EVT_SET_CONST(LVar2, ANIM_BonyBeetle_Anim25)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim25)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SpikyToppled)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -8)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -3, 21)
            EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 1)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledDefenseTable)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledSpikyAnims)))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim1B)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
            EVT_USE_BUF(N(FlipPosOffsets))
            EVT_LOOP(20)
                EVT_BUF_READ1(LVar0)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_WAIT(20)
        EVT_CASE_OR_EQ(EVENT_SCARE_AWAY)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BonyBeetle_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TryGettingUp_Spiky) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
    EVT_SUB(LVar0, 1)
    EVT_IF_GT(LVar0, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
        EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim1D)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim07)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_15)
        EVT_CALL(SetBattleCamZoom, 350)
        EVT_CALL(SetBattleCamOffsetZ, 20)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim1D)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim07)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BonyBeetle_Anim0B)
        EVT_WAIT(20)
        EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SpikyUpright)
        EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefenseTable)))
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(SpikyAnims)))
        EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, TRUE)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, FALSE)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

