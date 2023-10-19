#include "../area.h"
#include "sprite/npc/Tutankoopa.h"
#include "sprite/npc/ChainChomp.h"
#include "sprite/npc/BuzzyBeetle.h"
#include "sprite/player.h"
#include "tutankoopa_common.h"

#define NAMESPACE A(tutankoopa)

extern ActorBlueprint A(chain_chomp);
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_Tutankoopa_SpinSmashHit);
extern EvtScript N(EVS_TemporaryKnockout);
extern EvtScript N(EVS_Attack_ThrowShell);
extern EvtScript N(EVS_Attack_DropDebris);
extern EvtScript N(EVS_DropDebris_Self);
extern EvtScript N(EVS_DropDebris_Players);
extern EvtScript N(EVS_Move_SummonChomp);
extern EvtScript N(EVS_SummonedChompHop);
extern EvtScript N(EVS_LevitateToHomePos);
extern EvtScript N(EVS_GetBackUp);
extern EvtScript N(EVS_Tutankoopa_Death);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_TARGET          = 2,
    PRT_SHELL_1         = 3,
    PRT_SHELL_2         = 4,
    PRT_SHELL_3         = 5,
    PRT_DEBRIS_1        = 6,
    PRT_DEBRIS_2        = 7,
    PRT_DEBRIS_3        = 8,
};

enum N(ActorVars) {
    AVAR_NextMove               = 0,
    AVAL_Move_Toss              = 0,
    AVAL_Move_DropDebris        = 1,

    AVAR_StunState              = 1,
    AVAL_State_Normal           = 0,
    AVAL_State_Stunned          = 2,

    AVAR_ShellsLeft             = 2,
    AVAR_HasSummoned            = 3, // FALSE until a chomp has been summoned
    AVAR_Dialogue_Recover       = 4,
    AVAR_GateOpenAmount         = 5,
    AVAR_DebrisDropState        = 6,
    AVAR_Unknown                = 7,  // always zero
    AVAR_Stunned                = 8,  // overlapping usage with AVAR_StunState?
    AVAR_DoneFirstStrike        = 10, // unused
    AVAR_UsedSpikeTaunt         = 11, // unused dialogue toggle for spiky-taunting
    AVAR_NextSummonTime         = 12, // set by chomp actor when it dies
    AVAR_HittingSelf            = 13, // signal to HandleEvent to treat hit as self-inflicted
};

enum N(ActorParams) {
    DMG_DROP_DEBRIS_SELF        = 2,
    DMG_DROP_DEBRIS_PLAYER      = 2,
    DMG_DROP_DEBRIS_PARTNER     = 2,
    DMG_THROW_SHELL             = 3,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Tutankoopa_Idle,
    STATUS_KEY_STONE,     ANIM_Tutankoopa_Still,
    STATUS_KEY_SLEEP,     ANIM_Tutankoopa_Sleep,
    STATUS_KEY_POISON,    ANIM_Tutankoopa_Idle,
    STATUS_KEY_STOP,      ANIM_Tutankoopa_Still,
    STATUS_KEY_STATIC,    ANIM_Tutankoopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_Tutankoopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_Tutankoopa_Still,
    STATUS_KEY_DIZZY,     ANIM_Tutankoopa_Dizzy,
    STATUS_END,
};

s32 N(FallenAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Tutankoopa_Dizzy,
    STATUS_KEY_STONE,     ANIM_Tutankoopa_Fall,
    STATUS_KEY_SLEEP,     ANIM_Tutankoopa_SleepGround,
    STATUS_KEY_POISON,    ANIM_Tutankoopa_Dizzy,
    STATUS_KEY_STOP,      ANIM_Tutankoopa_Fall,
    STATUS_KEY_STATIC,    ANIM_Tutankoopa_Dizzy,
    STATUS_KEY_PARALYZE,  ANIM_Tutankoopa_Dizzy,
    STATUS_KEY_PARALYZE,  ANIM_Tutankoopa_Dizzy,
    STATUS_KEY_DIZZY,     ANIM_Tutankoopa_Dizzy,
    STATUS_END,
};

s32 N(BeetleShellAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BuzzyBeetle_Anim06,
    STATUS_END,
};

s32 N(RockAnimsA)[] = {
    STATUS_KEY_NORMAL,    ANIM_Tutankoopa_RockStill,
    STATUS_END,
};

s32 N(RockAnimsB)[] = {
    STATUS_KEY_NORMAL,    ANIM_Tutankoopa_RockStill,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              20,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              30,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           30,
    STATUS_KEY_SHRINK,             60,
    STATUS_KEY_STOP,               40,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
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
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 40 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_TARGET,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 39 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -5, -15 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_SKIP_SHOCK_EFFECT,
        .index = PRT_SHELL_1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(BeetleShellAnims),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_SKIP_SHOCK_EFFECT,
        .index = PRT_SHELL_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(BeetleShellAnims),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_SKIP_SHOCK_EFFECT,
        .index = PRT_SHELL_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(BeetleShellAnims),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_DEBRIS_1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(RockAnimsA),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_DEBRIS_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(RockAnimsA),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_DEBRIS_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(RockAnimsB),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_TUTANKOOPA,
    .level = ACTOR_LEVEL_TUTANKOOPA,
    .maxHP = 30,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 70,
    .coinReward = 0,
    .size = { 56, 45 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 35 },
    .statusTextOffset = { 10, 35 },
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

API_CALLABLE(SpawnFallingRock) {
    Bytecode* args = script->ptrReadPos;
    s32 posX = evt_get_variable(script, *args++);
    s32 floorY = evt_get_variable(script, *args++);
    s32 posZ = evt_get_variable(script, *args++);
    EffectInstance* effect = fx_floating_rock(2, posX, 150.0f, posZ, floorY, -0.5f, -0.9f, 0.5f, 60);

    effect->data.floatingRock->rotVel.x = 0;
    effect->data.floatingRock->rotVel.z = 0;
    effect->data.floatingRock->rotVel.y = 0;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(ForceHomePos, ACTOR_SELF, 97, 70, 15)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_SHELL_1, 70, 70, 3)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_SHELL_2, 80, 70, -7)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_SHELL_3, 60, 70, -7)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Stunned, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Toss)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_StunState, AVAL_State_Normal)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HasSummoned, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Dialogue_Recover, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShellsLeft, 3)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_DebrisDropState, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unknown, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_DoneFirstStrike, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_UsedSpikeTaunt, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextSummonTime, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HittingSelf, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Stunned, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_FLAG(LVar0, STATUS_FLAG_DIZZY)
                    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_TARGET, -10, 22)
                    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_TARGET, 2, -8)
                    EVT_CALL(N(SetAbsoluteStatusOffsets), -25, 15, 0, 20)
                EVT_ELSE
                    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_TARGET, 0, 39)
                    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_TARGET, -5, -15)
                    EVT_CALL(N(SetAbsoluteStatusOffsets), -17, 23, 11, 32)
                EVT_END_IF
            EVT_CASE_EQ(1)
                EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_TARGET, -10, 22)
                EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_TARGET, 2, -8)
                EVT_CALL(N(SetAbsoluteStatusOffsets), -25, 15, 0, 20)
        EVT_END_SWITCH
        EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(GetLastElement, LVarE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            // if damage is from "debris drop" backfiring, fall down and become stunned
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HittingSelf, LVar2)
            EVT_IF_TRUE(LVar2)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HittingSelf, FALSE)
                EVT_EXEC_WAIT(N(EVS_TemporaryKnockout))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar0, PRT_MAIN)
            EVT_SET(LVar1, ANIM_Tutankoopa_BurnHurt)
            EVT_SET(LVar2, ANIM_Tutankoopa_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LVar0, PRT_MAIN)
            EVT_SET(LVar1, ANIM_Tutankoopa_BurnHurt)
            EVT_SET(LVar2, ANIM_Tutankoopa_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_BurnStill)
            EVT_EXEC_WAIT(N(EVS_Tutankoopa_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(EVS_Tutankoopa_SpinSmashHit))
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Glare)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Run)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Stunned, LVar1)
            EVT_IF_EQ(LVar1, TRUE)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_StunState, LVar1)
                EVT_IF_NE(LVar1, AVAL_State_Normal)
                    EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Dizzy)
                EVT_ELSE
                    EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Idle)
                EVT_END_IF
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Idle)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_StunState, LVar1)
            EVT_IF_EQ(LVar1, AVAL_State_Normal)
                EVT_IF_FLAG(LVarE, DAMAGE_TYPE_JUMP)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_UsedSpikeTaunt, LVar0)
                    EVT_IF_EQ(LVar0, FALSE)
                        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_UsedSpikeTaunt, TRUE)
                        EVT_WAIT(60)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_OR_EQ(EVENT_SHOCK_DEATH)
        EVT_CASE_OR_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Hurt)
            EVT_EXEC_WAIT(N(EVS_Tutankoopa_Death))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(EVS_Tutankoopa_SpinSmashHit))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Hurt)
            EVT_EXEC_WAIT(N(EVS_Tutankoopa_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Hurt)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Idle)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Hurt)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Idle)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Tutankoopa_SpinSmashHit) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Hurt)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, 150, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_SUB(LVar1, 20)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 130, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Fall)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Levitate)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Run)
    EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TemporaryKnockout) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Stunned, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_WITHER)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Hurt)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.9))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 10)
    EVT_SET(LVar1, 0)
    EVT_ADD(LVar2, 24)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.1), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0), EVT_FLOAT(0.7), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(StartRumble, BTL_RUMBLE_LONG)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_COLLAPSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Fall)
    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 40)
    EVT_PLAY_EFFECT(EFFECT_STARS_ORBITING, 0, LVar0, LVar1, LVar2, 20, 4, LVarF, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Dizzy)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_KNOCKOUT_CHIRPING)
    EVT_WAIT(30)
    EVT_CALL(RemoveEffect, LVarF)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Stunned, TRUE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unknown, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_StunState, AVAL_State_Stunned)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(FallenAnims)))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_LABEL(0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Stunned, LVar0)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_CALL(ActorExists, ACTOR_CHOMP, LVar0)
            EVT_IF_EQ(LVar0, FALSE)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextSummonTime, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_EXEC_WAIT(N(EVS_Move_SummonChomp))
                    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
                    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                    EVT_RETURN
                EVT_ELSE
                    EVT_SUB(LVar0, 1)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextSummonTime, LVar0)
                EVT_END_IF
            EVT_END_IF
            // override to only use "drop debris" while shrunk
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_DropDebris)
            EVT_END_IF
            // select next attack, alternating between "throw shell" and "drop debris" when possible
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_Move_Toss)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ShellsLeft, LVar0)
                    EVT_IF_EQ(LVar0, 0)
                        // always use "drop debris" after all shells are gone
                        EVT_EXEC_WAIT(N(EVS_Attack_DropDebris))
                        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_DropDebris)
                    EVT_ELSE
                        // throw a shell if not shrunk
                        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                            EVT_EXEC_WAIT(N(EVS_Attack_ThrowShell))
                            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_DropDebris)
                        EVT_ELSE
                            EVT_EXEC_WAIT(N(EVS_Attack_DropDebris))
                            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Toss)
                        EVT_END_IF
                    EVT_END_IF
                EVT_CASE_DEFAULT
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Toss)
                    EVT_EXEC_WAIT(N(EVS_Attack_DropDebris))
            EVT_END_SWITCH
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_ELSE
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unknown, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_StunState, AVAL_State_Normal)
            EVT_EXEC_WAIT(N(EVS_GetBackUp))
            EVT_EXEC_WAIT(N(EVS_LevitateToHomePos))
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_ThrowShell) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ShellsLeft, LVar0)
    // get actor part for the Nth remaining shell
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_SET(LVar9, PRT_SHELL_3)
        EVT_CASE_EQ(2)
            EVT_SET(LVar9, PRT_SHELL_2)
        EVT_CASE_EQ(3)
            EVT_SET(LVar9, PRT_SHELL_1)
        EVT_CASE_DEFAULT
            EVT_RETURN
    EVT_END_SWITCH
    EVT_SUB(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ShellsLeft, LVar0)
    // begin the attack
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_15)
    EVT_CALL(SetBattleCamZoom, 320)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(BattleCamTargetActorPart, ACTOR_SELF, LVar9)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Run)
    EVT_CALL(GetPartOffset, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_SUB(LVar2, 3)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Idle)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Lift)
    EVT_WAIT(7)
    EVT_CALL(GetPartOffset, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_ADD(LVar1, 40)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar9, EVT_FLOAT(0.8))
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2, 5, TRUE)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar9, ANIM_BuzzyBeetle_Anim05)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_TOSS)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Toss)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LVar9, EVT_FLOAT(14.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar9, EVT_FLOAT(0.2))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 50)
            EVT_SET(LVar1, -5)
            EVT_CALL(FlyPartTo, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2, 0, 30, EASING_LINEAR)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 65)
            EVT_SET(LVar1, -5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LVar9, EVT_FLOAT(6.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar9, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2, 0, 15, EASING_LINEAR)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar9, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Run)
            EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Idle)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Toss)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LVar9, EVT_FLOAT(14.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar9, EVT_FLOAT(0.2))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar9, EVT_FLOAT(0.2))
    EVT_CALL(FlyPartTo, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2, 0, 30, EASING_LINEAR)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar8, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_THROW_SHELL, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 55)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LVar9, EVT_FLOAT(6.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar9, EVT_FLOAT(0.1))
    EVT_CALL(FlyPartTo, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2, 0, 25, EASING_LINEAR)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LVar9, EVT_FLOAT(4.0))
    EVT_SUB(LVar0, 20)
    EVT_CALL(FlyPartTo, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2, 0, 21, EASING_LINEAR)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar9, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_WAIT(19)
    EVT_IF_EQ(LVar8, HIT_RESULT_10)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(YieldTurn)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Run)
    EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_DropDebris) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_15)
    EVT_CALL(SetBattleCamZoom, 350)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DebrisDropState, LVar0)
    EVT_IF_EQ(LVar0, 0)
        // first use only
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_CALL(ActorSpeak, MSG_CH2_00E5, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Shout, ANIM_Tutankoopa_Shout)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_TUTANKOOPA_MAGIC)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Shout)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_PLAY_EFFECT(EFFECT_HIEROGLYPHS, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 45, 0)
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 70)
    EVT_CALL(PlaySound, SOUND_SPOOKY_LEVITATE)
    EVT_PLAY_EFFECT(EFFECT_CHOMP_DROP, 0, 0, 60, 0, EVT_FLOAT(0.2), 0, EVT_FLOAT(1.4), 255, EVT_FLOAT(0.1), 150, 0)
    EVT_WAIT(15)
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED | STATUS_FLAG_TRANSPARENT)
        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Flail)
        EVT_WAIT(49)
        EVT_CALL(PlaySound, SOUND_HEAVY_NPC_FALLING)
        EVT_WAIT(5)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Toss)
        EVT_WAIT(8)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Crouch)
        EVT_WAIT(5)
        EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_EXTREME)
        EVT_CALL(PlaySound, SOUND_HEAVY_NPC_LANDING)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(4.0))
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Question)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_PLAY_EFFECT(EFFECT_EMOTE, EMOTE_QUESTION, 0, LVar0, LVar1, LVar2, 20, 315, 30, 0, 0)
        EVT_CALL(PlaySound, SOUND_ILLUSION_DISSOLVE)
    EVT_ELSE
        EVT_WAIT(50)
        EVT_CALL(PlaySound, SOUND_HEAVY_NPC_FALLING)
        EVT_WAIT(18)
        EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_EXTREME)
        EVT_CALL(PlaySound, SOUND_HEAVY_NPC_LANDING)
        EVT_WAIT(20)
        EVT_CALL(PlaySound, SOUND_ILLUSION_DISSOLVE)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DebrisDropState, LVar0)
    EVT_SWITCH(LVar0)
        // first use: target player
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_DebrisDropState, 1)
            EVT_EXEC_WAIT(N(EVS_DropDebris_Players))
        // second use: target self if damage is survivable
        EVT_CASE_EQ(1)
            EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_DebrisDropState, 2)
            EVT_IF_GT(LVar0, DMG_DROP_DEBRIS_SELF)
                EVT_EXEC_WAIT(N(EVS_DropDebris_Self))
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_DropDebris_Players))
            EVT_END_IF
        // subsequent use: 50% chance to target player or target self while damage is survivable
        EVT_CASE_DEFAULT
            EVT_CALL(RandInt, 2, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
                EVT_IF_GT(LVar0, DMG_DROP_DEBRIS_SELF)
                    EVT_EXEC_WAIT(N(EVS_DropDebris_Self))
                EVT_ELSE
                    EVT_EXEC_WAIT(N(EVS_DropDebris_Players))
                EVT_END_IF
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_DropDebris_Players))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropDebris_Self) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_TUTANKOOPA)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, 170)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_DEBRIS_3, LVar0, LVar3, LVar2)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_DEBRIS_3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_DEBRIS_3, ANIM_Tutankoopa_RockStill)
    EVT_CALL(PlaySound, SOUND_TUTANKOOPA_DEBRIS_FALL)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_DEBRIS_3, EVT_FLOAT(8.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_DEBRIS_3, EVT_FLOAT(0.3))
    EVT_CALL(FallPartTo, ACTOR_SELF, PRT_DEBRIS_3, LVar0, LVar1, LVar2, 20)
    EVT_THREAD
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_DEBRIS_3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_DEBRIS_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_ThumbsUp)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HittingSelf, TRUE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, DMG_DROP_DEBRIS_SELF, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DropDebris_Players) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_THREAD
                EVT_LOOP(6)
                    EVT_CALL(RandInt, 120, LVar0)
                    EVT_SUB(LVar0, 150)
                    EVT_CALL(RandInt, 90, LVar1)
                    EVT_SUB(LVar0, 40)
                    EVT_CALL(PlaySound, SOUND_TUTANKOOPA_DEBRIS_FALL)
                    EVT_CALL(SpawnFallingRock, LVar0, 0, LVar1)
                    EVT_CALL(RandInt, 5, LVar0)
                    EVT_ADD(LVar0, 5)
                    EVT_WAIT(LVar0)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarB, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
            EVT_SWITCH(LVarB)
                EVT_CASE_EQ(HIT_RESULT_MISS)
                    EVT_RETURN
                EVT_CASE_DEFAULT
                    EVT_CALL(FreezeBattleState, TRUE)
                    EVT_THREAD
                        EVT_CALL(PlaySound, SOUND_TUTANKOOPA_DEBRIS_FALL)
                        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        EVT_SUB(LVar0, 5)
                        EVT_SET(LVar1, 0)
                        EVT_SET(LVar3, 170)
                        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_DEBRIS_1, LVar0, LVar3, LVar2)
                        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_DEBRIS_1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_DEBRIS_1, ANIM_Tutankoopa_RockStill)
                        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_DEBRIS_1, EVT_FLOAT(8.0))
                        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_DEBRIS_1, EVT_FLOAT(0.3))
                        EVT_CALL(FallPartTo, ACTOR_SELF, PRT_DEBRIS_1, LVar0, LVar1, LVar2, 20)
                        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_DEBRIS_1, ANIM_Tutankoopa_RockShatter)
                        EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                        EVT_END_IF
                    EVT_END_THREAD
                    EVT_WAIT(25)
                    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    EVT_SUB(LVar4, 5)
                    EVT_ADD(LVar5, 5)
                    EVT_SET(LVar7, 170)
                    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_DEBRIS_2, LVar4, LVar7, LVar6)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_DEBRIS_2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_DEBRIS_2, ANIM_Tutankoopa_RockStill)
                    EVT_CALL(PlaySound, SOUND_TUTANKOOPA_DEBRIS_FALL)
                    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_DEBRIS_2, EVT_FLOAT(8.0))
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_DEBRIS_2, EVT_FLOAT(0.3))
                    EVT_CALL(FallPartTo, ACTOR_SELF, PRT_DEBRIS_2, LVar4, LVar5, LVar6, 20)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_DEBRIS_1, ANIM_Tutankoopa_RockShatter)
                    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_DROP_DEBRIS_PARTNER, BS_FLAGS1_TRIGGER_EVENTS)
                    EVT_WAIT(20)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_DEBRIS_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    EVT_CALL(FreezeBattleState, FALSE)
                    EVT_RETURN
            EVT_END_SWITCH
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_LOOP(6)
            EVT_CALL(RandInt, 120, LVar0)
            EVT_SUB(LVar0, 150)
            EVT_CALL(RandInt, 90, LVar1)
            EVT_SUB(LVar0, 40)
            EVT_CALL(PlaySound, SOUND_TUTANKOOPA_DEBRIS_FALL)
            EVT_CALL(SpawnFallingRock, LVar0, 0, LVar1)
            EVT_CALL(RandInt, 5, LVar0)
            EVT_ADD(LVar0, 5)
            EVT_WAIT(LVar0)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(FreezeBattleState, TRUE)
    EVT_THREAD
        EVT_WAIT(25)
        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
        EVT_SUB(LVar4, 5)
        EVT_ADD(LVar5, 5)
        EVT_SET(LVar7, 170)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_DEBRIS_2, LVar4, LVar7, LVar6)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_DEBRIS_2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_DEBRIS_2, ANIM_Tutankoopa_RockStill)
        EVT_CALL(PlaySound, SOUND_TUTANKOOPA_DEBRIS_FALL)
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_DEBRIS_2, EVT_FLOAT(8.0))
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_DEBRIS_2, EVT_FLOAT(0.3))
        EVT_CALL(FallPartTo, ACTOR_SELF, PRT_DEBRIS_2, LVar4, LVar5, LVar6, 20)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_DEBRIS_1, ANIM_Tutankoopa_RockShatter)
        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_DROP_DEBRIS_PARTNER, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_WAIT(20)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_DEBRIS_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_CALL(FreezeBattleState, FALSE)
    EVT_END_THREAD
    EVT_CALL(PlaySound, SOUND_TUTANKOOPA_DEBRIS_FALL)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 5)
    EVT_ADD(LVar1, 5)
    EVT_SET(LVar3, 170)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_DEBRIS_1, LVar0, LVar3, LVar2)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_DEBRIS_1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_DEBRIS_1, ANIM_Tutankoopa_RockStill)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_DEBRIS_1, EVT_FLOAT(8.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_DEBRIS_1, EVT_FLOAT(0.3))
    EVT_CALL(FallPartTo, ACTOR_SELF, PRT_DEBRIS_1, LVar0, LVar1, LVar2, 20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_DEBRIS_1, ANIM_Tutankoopa_RockShatter)
    EVT_WAIT(2)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_DROP_DEBRIS_PLAYER, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_WAIT(19)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_DEBRIS_1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_IF_EQ(LVar0, HIT_RESULT_10)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

Vec3i N(SummonedChompPos) = { 190, 0, 0 };

Formation N(SummonedChomp) = {
    ACTOR_BY_POS(A(chain_chomp), N(SummonedChompPos), 100),
};

EvtScript N(EVS_Move_SummonChomp) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HasSummoned, LVar0)
    EVT_IF_FALSE(LVar0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Shout)
        EVT_CALL(ActorSpeak, MSG_CH2_00E6, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Shout, ANIM_Tutankoopa_Shout)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Shout)
        EVT_CALL(ActorSpeak, MSG_CH2_00E7, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Shout, ANIM_Tutankoopa_Shout)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Idle)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Stunned, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
        EVT_CALL(SetBattleCamZoom, 225)
        EVT_CALL(SetBattleCamOffsetZ, -30)
        EVT_CALL(MoveBattleCamOver, 40)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
        EVT_CALL(SetBattleCamZoom, 200)
        EVT_CALL(SetBattleCamOffsetZ, 35)
        EVT_CALL(MoveBattleCamOver, 40)
    EVT_END_IF
    // open the gate
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_GateOpenAmount, 0)
    EVT_THREAD
        // rumble while gate is opening
        EVT_LABEL(0)
            EVT_CALL(StartRumble, BTL_RUMBLE_LONG)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
            EVT_WAIT(1)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_GateOpenAmount, LVar0)
            EVT_IF_LT(LVar0, 60)
                EVT_GOTO(0)
            EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(PlaySound, SOUND_LARGE_GATE_OPEN)
    EVT_LABEL(10)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_GateOpenAmount, LVarD)
        EVT_CALL(TranslateModel, 31, 0, LVarD, 0)
        EVT_ADD(LVarD, 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_GateOpenAmount, LVarD)
        EVT_WAIT(1)
        EVT_IF_LT(LVarD, 60)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(StopSound, SOUND_LARGE_GATE_OPEN)
    EVT_WAIT(10)
    // create the chomp and have him exit the gate
    EVT_CALL(SummonEnemy, EVT_PTR(N(SummonedChomp)), FALSE)
    EVT_SET(LVarB, LVar0)
    EVT_SET(LVar0, 165)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, -30)
    EVT_CALL(SetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorDispOffset, LVarB, 0, 0, 0)
    EVT_CALL(UseIdleAnimation, LVarB, FALSE)
    EVT_CALL(EnableIdleScript, LVarB, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetAnimation, LVarB, 1, ANIM_ChainChomp_SlowBite)
    EVT_CALL(SetActorSpeed, LVarB, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, LVarB, EVT_FLOAT(0.8))
    EVT_SET(LVar0, 90)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, -30)
    EVT_SET(LVar3, 8)
    EVT_SET(LVar4, 30)
    EVT_EXEC_WAIT(N(EVS_SummonedChompHop))
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HasSummoned, LVar5)
    EVT_IF_FALSE(LVar5)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamZoom, 160)
        EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, 60)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(MoveBattleCamOver, 8)
        EVT_LOOP(3)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamZoom, 150)
            EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
            EVT_CALL(MoveBattleCamOver, 5)
            EVT_WAIT(4)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_BITE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamZoom, 200)
            EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
            EVT_CALL(MoveBattleCamOver, 5)
            EVT_WAIT(4)
        EVT_END_LOOP
    EVT_ELSE
        EVT_WAIT(8)
        EVT_CALL(SetGoalPos, LVarB, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, LVarB, 8, FALSE, TRUE, FALSE)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_THREAD
        EVT_CALL(SetGoalPos, LVarB, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, LVarB, 8, FALSE, TRUE, FALSE)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_THREAD
        EVT_WAIT(8)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetActorSpeed, LVarB, EVT_FLOAT(3.0))
    EVT_CALL(SetActorJumpGravity, LVarB, EVT_FLOAT(0.8))
    EVT_SET(LVar0, 20)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 20)
    EVT_SET(LVar3, 8)
    EVT_SET(LVar4, 20)
    EVT_EXEC_WAIT(N(EVS_SummonedChompHop))
    EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, LVarB, 2, LVar0, LVar1, LVar2) // references partID from chain_chomp
    EVT_CALL(HPBarToHome, LVarB)
    EVT_CALL(SetActorSpeed, LVarB, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, LVarB, EVT_FLOAT(0.8))
    EVT_CALL(EnableIdleScript, LVarB, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, LVarB, TRUE)
    // close the gate
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_GateOpenAmount, 60)
    EVT_THREAD
        // rumble while gate is opening
        EVT_LABEL(40)
            EVT_CALL(StartRumble, BTL_RUMBLE_LONG)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
            EVT_WAIT(1)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_GateOpenAmount, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_GOTO(40)
            EVT_END_IF
        EVT_END_THREAD
    EVT_CALL(PlaySound, SOUND_LARGE_GATE_OPEN)
    EVT_LABEL(50)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_GateOpenAmount, LVarD)
        EVT_CALL(TranslateModel, 31, 0, LVarD, 0)
        EVT_SUB(LVarD, 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_GateOpenAmount, LVarD)
        EVT_WAIT(1)
        EVT_IF_GT(LVarD, 0)
            EVT_GOTO(50)
    EVT_END_IF
    EVT_CALL(StopSound, SOUND_LARGE_GATE_OPEN)
    EVT_CALL(PlaySound, SOUND_LARGE_GATE_CLOSE)
    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.5))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HasSummoned, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SummonedChompHop) = {
    EVT_LABEL(20)
    EVT_CALL(GetActorPos, LVarB, LVar5, LVar6, LVar7)
    EVT_IF_EQ(LVar5, LVar0)
        EVT_GOTO(30)
    EVT_END_IF
    EVT_SET(LVar6, LVar5)
    EVT_SUB(LVar6, LVar0)
    EVT_IF_LT(LVar6, LVar4)
        EVT_CALL(SetGoalPos, LVarB, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, LVarB, LVar3, FALSE, TRUE, FALSE)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_THREAD
    EVT_ELSE
        EVT_SUB(LVar5, LVar4)
        EVT_CALL(SetGoalPos, LVarB, LVar5, LVar1, LVar2)
        EVT_CALL(JumpToGoal, LVarB, LVar3, FALSE, TRUE, FALSE)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_THREAD
    EVT_END_IF
    EVT_GOTO(20)
    EVT_LABEL(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LevitateToHomePos) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unknown, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_TUTANKOOPA_MAGIC)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Levitate)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_PLAY_EFFECT(EFFECT_HIEROGLYPHS, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 45, 0)
    EVT_WAIT(45)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_TUTANKOOPA_LEVITATE)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 97, 70, 15)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 45, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_A)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_B)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Stunned, FALSE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GetBackUp) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Levitate)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_A)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_B)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Idle)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
    EVT_WAIT(10)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Dialogue_Recover, LVar0)
    EVT_IF_FALSE(LVar0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_CALL(ActorSpeak, MSG_CH2_00E4, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Talk, ANIM_Tutankoopa_Idle)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Dialogue_Recover, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_DoneFirstStrike, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_DoneFirstStrike, TRUE)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

// kills the summoned chomp before dying
EvtScript N(EVS_Tutankoopa_Death) = {
    EVT_CALL(ActorExists, ACTOR_CHOMP, LVar2)
    EVT_IF_NE(LVar2, FALSE)
        EVT_CALL(GetActorHP, ACTOR_CHOMP, LVar2)
        EVT_IF_NE(LVar2, 0)
            EVT_THREAD
                EVT_CALL(HideHealthBar, ACTOR_CHOMP)
                EVT_CALL(EnableIdleScript, ACTOR_CHOMP, IDLE_SCRIPT_DISABLE)
                EVT_CALL(UseIdleAnimation, ACTOR_CHOMP, FALSE)
                EVT_CALL(SetAnimation, ACTOR_CHOMP, PRT_MAIN, ANIM_ChainChomp_Hurt)
                EVT_WAIT(10)
                EVT_SET(LVar2, 0)
                EVT_LOOP(24)
                    EVT_CALL(SetActorYaw, ACTOR_CHOMP, LVar2)
                    EVT_ADD(LVar2, 30)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorYaw, ACTOR_CHOMP, 0)
                EVT_CALL(GetActorPos, ACTOR_CHOMP, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 10)
                EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
                EVT_CALL(PlaySoundAtActor, ACTOR_CHOMP, SOUND_ACTOR_DEATH)
                EVT_SET(LVar3, 0)
                EVT_LOOP(12)
                    EVT_CALL(SetActorRotation, ACTOR_CHOMP, LVar3, 0, 0)
                    EVT_ADD(LVar3, 8)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(RemoveActor, ACTOR_CHOMP)
            EVT_END_THREAD
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(EVS_Enemy_DeathWithoutRemove)
    EVT_LABEL(0)
        EVT_CALL(ActorExists, ACTOR_CHOMP, LVar0)
        EVT_IF_NE(LVar0, FALSE)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};
