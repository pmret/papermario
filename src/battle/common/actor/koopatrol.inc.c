#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Koopatrol.h"
#include "effects.h"

#define NAMESPACE A(koopatrol)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

enum N(ActorVars) {
    AVAR_State          = 0,
    AVAL_State_Normal   = 0,
    AVAL_State_Toppled  = 1,
    AVAL_State_Charged  = 2,
    AVAR_Generation     = 1,
    AVAR_AncestorColumn = 2,
    AVAR_FlippedTurns   = 9,
};

enum N(ActorParams) {
    DMG_SHELL_TOSS      = 4,
    DMG_CHARGED_TOSS    = 10,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Koopatrol_Anim01,
    STATUS_KEY_STONE,     ANIM_Koopatrol_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Koopatrol_Anim11,
    STATUS_KEY_POISON,    ANIM_Koopatrol_Anim01,
    STATUS_KEY_STOP,      ANIM_Koopatrol_Anim00,
    STATUS_KEY_STATIC,    ANIM_Koopatrol_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_Koopatrol_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Koopatrol_Anim13,
    STATUS_KEY_FEAR,      ANIM_Koopatrol_Anim13,
    STATUS_END,
};

s32 N(ShuffleAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Koopatrol_Anim03,
    STATUS_KEY_STONE,     ANIM_Koopatrol_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Koopatrol_Anim11,
    STATUS_KEY_POISON,    ANIM_Koopatrol_Anim03,
    STATUS_KEY_STOP,      ANIM_Koopatrol_Anim00,
    STATUS_KEY_STATIC,    ANIM_Koopatrol_Anim03,
    STATUS_KEY_PARALYZE,  ANIM_Koopatrol_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Koopatrol_Anim13,
    STATUS_KEY_FEAR,      ANIM_Koopatrol_Anim13,
    STATUS_END,
};

s32 N(ToppledAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Koopatrol_Anim0F,
    STATUS_KEY_STONE,     ANIM_Koopatrol_Anim10,
    STATUS_KEY_SLEEP,     ANIM_Koopatrol_Anim12,
    STATUS_KEY_POISON,    ANIM_Koopatrol_Anim0F,
    STATUS_KEY_STOP,      ANIM_Koopatrol_Anim10,
    STATUS_KEY_STATIC,    ANIM_Koopatrol_Anim0F,
    STATUS_KEY_PARALYZE,  ANIM_Koopatrol_Anim10,
    STATUS_KEY_DIZZY,     ANIM_Koopatrol_Anim14,
    STATUS_KEY_FEAR,      ANIM_Koopatrol_Anim14,
    STATUS_END,
};

s32 N(ChargedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Koopatrol_Anim06,
    STATUS_KEY_STONE,     ANIM_Koopatrol_Anim06,
    STATUS_KEY_SLEEP,     ANIM_Koopatrol_Anim06,
    STATUS_KEY_POISON,    ANIM_Koopatrol_Anim06,
    STATUS_KEY_STOP,      ANIM_Koopatrol_Anim06,
    STATUS_KEY_STATIC,    ANIM_Koopatrol_Anim06,
    STATUS_KEY_PARALYZE,  ANIM_Koopatrol_Anim06,
    STATUS_KEY_DIZZY,     ANIM_Koopatrol_Anim06,
    STATUS_KEY_FEAR,      ANIM_Koopatrol_Anim06,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   3,
    ELEMENT_SHOCK,    3,
    ELEMENT_END,
};

s32 N(ToppledDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(ChargedDefense)[] = {
    ELEMENT_NORMAL,   3,
    ELEMENT_FIRE,     3,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              50,
    STATUS_KEY_POISON,             60,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             80,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             70,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

s32 N(ChargedStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,                0,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
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
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 32 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP | ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -12 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_KOOPATROL,
    .level = ACTOR_LEVEL_KOOPATROL,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
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
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 32 },
    .statusTextOffset = { 5, 32 },
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"
#include "common/StartRumbleWithParams.inc.c"

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Generation, 0)
    EVT_CALL(GetIndexFromHome, ACTOR_SELF, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_AncestorColumn, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetBattleVar, BTL_VAR_KoopatrolSummonCount_0, 0)
        EVT_CASE_EQ(1)
            EVT_CALL(SetBattleVar, BTL_VAR_KoopatrolSummonCount_1, 0)
        EVT_CASE_EQ(2)
            EVT_CALL(SetBattleVar, BTL_VAR_KoopatrolSummonCount_2, 0)
        EVT_CASE_EQ(3)
            EVT_CALL(SetBattleVar, BTL_VAR_KoopatrolSummonCount_3, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_END)
            EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_None)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdateOffsets) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_State_Normal)
            EVT_IF_FLAG(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_DIZZY)
                EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -5, 15)
                EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
                EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
            EVT_ELSE
                EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -4, 32)
                EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -4)
                EVT_CALL(N(SetAbsoluteStatusOffsets), -15, 32, 5, 32)
            EVT_END_IF
        EVT_CASE_EQ(AVAL_State_Toppled)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -5, 15)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
            EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
        EVT_CASE_EQ(AVAL_State_Charged)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -4, 20)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -6)
            EVT_CALL(N(SetAbsoluteStatusOffsets), -15, 22, 5, 22)
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
                EVT_IF_EQ(LVar0, AVAL_State_Toppled)
                    EVT_WAIT(1)
                    EVT_GOTO(1)
                EVT_END_IF
                EVT_IF_FLAG(LVar1, STATUS_FLAGS_IMMOBILIZED | STATUS_FLAG_GLOWING)
                    EVT_WAIT(1)
                    EVT_GOTO(1)
                EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ShuffleAnims)))
        EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IdleRunToGoal, ACTOR_SELF, 0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(AVAL_State_Normal)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
            EVT_CASE_EQ(AVAL_State_Toppled)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledAnims)))
        EVT_END_SWITCH
        EVT_LOOP(20)
            EVT_LABEL(2)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
                EVT_EXEC_WAIT(N(EVS_UpdateOffsets))
                EVT_IF_EQ(LVar0, AVAL_State_Toppled)
                    EVT_WAIT(1)
                    EVT_GOTO(2)
                EVT_END_IF
                EVT_IF_FLAG(LVar1, STATUS_FLAGS_IMMOBILIZED | STATUS_FLAG_GLOWING)
                    EVT_WAIT(1)
                    EVT_GOTO(2)
                EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 5)
        EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ShuffleAnims)))
        EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IdleRunToGoal, ACTOR_SELF, 0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(AVAL_State_Normal)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
            EVT_CASE_EQ(AVAL_State_Toppled)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledAnims)))
        EVT_END_SWITCH
        EVT_LOOP(80)
            EVT_LABEL(3)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
                EVT_EXEC_WAIT(N(EVS_UpdateOffsets))
                EVT_IF_EQ(LVar0, AVAL_State_Toppled)
                    EVT_WAIT(1)
                    EVT_GOTO(3)
                EVT_END_IF
                EVT_IF_FLAG(LVar1, STATUS_FLAGS_IMMOBILIZED | STATUS_FLAG_GLOWING)
                    EVT_WAIT(1)
                    EVT_GOTO(3)
                EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(FlipPosOffsets)[] = { 9, 16, 22, 26, 30, 32, 33, 32, 30, 26, 22, 16, 9, 0, 4, 6, 7, 6, 4, 0, 2, 0 };

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(AVAL_State_Normal)
                EVT_CASE_OR_EQ(AVAL_State_Toppled)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
                EVT_END_CASE_GROUP
                EVT_CASE_EQ(AVAL_State_Charged)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim06)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0C)
            EVT_SET_CONST(LVar2, ANIM_Koopatrol_Anim0D)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0C)
            EVT_SET_CONST(LVar2, ANIM_Koopatrol_Anim0D)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0D)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(AVAL_State_Normal)
                EVT_CASE_OR_EQ(AVAL_State_Toppled)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
                    EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
                EVT_END_CASE_GROUP
                EVT_CASE_EQ(AVAL_State_Charged)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim06)
                    EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(AVAL_State_Normal)
                EVT_CASE_OR_EQ(AVAL_State_Toppled)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
                    EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
                    EVT_EXEC_WAIT(EVS_Enemy_Death)
                EVT_END_CASE_GROUP
                EVT_CASE_EQ(AVAL_State_Charged)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim06)
                    EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim08)
                    EVT_WAIT(5)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
                    EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Toppled)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FlippedTurns, 1)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledDefense)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ToppledAnims)))
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -5, 15)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, FALSE)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim0B)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim0F)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_STAR_BEAM)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            EVT_IF_EQ(LVar0, AVAL_State_Charged)
                EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable)))
                EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefenseTable)))
                EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FLIPABLE, TRUE)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
                EVT_IF_NOT_FLAG(LVarA, STATUS_FLAG_DEFENSE_BOOST | STATUS_FLAG_ATTACK_BOOST)
                    EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
                EVT_END_IF
                EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim08)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_END_IF
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_State_Normal)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim07)
                    EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim08)
                        EVT_WAIT(10)
                    EVT_END_IF
                EVT_CASE_EQ(AVAL_State_Toppled)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0F)
                    EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                EVT_CASE_EQ(AVAL_State_Charged)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim06)
                    EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_WAIT(10)
            EVT_SET(LFlag0, FALSE)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                EVT_ADD(LVar1, 16)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
            EVT_IF_FLAG(LVar3, STATUS_FLAG_DIZZY)
                EVT_ADD(LVar0, -14)
                EVT_ADD(LVar1, 20)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
            EVT_IF_FLAG(LVar3, STATUS_FLAG_SLEEP)
                EVT_ADD(LVar0, -14)
                EVT_ADD(LVar1, 20)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVarA)
            EVT_IF_EQ(LVarA, AVAL_State_Charged)
                EVT_ADD(LVar1, 23)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_ADD(LVar1, 42)
            EVT_END_IF
            EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 20, 0)
            EVT_WAIT(20)
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(AVAL_State_Normal)
                EVT_CASE_OR_EQ(AVAL_State_Toppled)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
                    EVT_WAIT(10)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
                    EVT_EXEC_WAIT(EVS_Enemy_Death)
                    EVT_RETURN
                EVT_END_CASE_GROUP
                EVT_CASE_EQ(AVAL_State_Charged)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim06)
                    EVT_EXEC_WAIT(EVS_Enemy_Hit)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim08)
                    EVT_WAIT(5)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0B)
                    EVT_EXEC_WAIT(EVS_Enemy_Death)
                    EVT_RETURN
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_State_Normal)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim01)
                    EVT_EXEC_WAIT(EVS_Enemy_Recover)
                EVT_CASE_EQ(AVAL_State_Toppled)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0F)
                    EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                EVT_CASE_EQ(AVAL_State_Charged)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim06)
                    EVT_EXEC_WAIT(EVS_Enemy_Recover)
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(AVAL_State_Normal)
                EVT_CASE_OR_EQ(AVAL_State_Charged)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim04)
                    EVT_SET_CONST(LVar2, ANIM_Koopatrol_Anim0B)
                    EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
                    EVT_RETURN
                EVT_END_CASE_GROUP
                EVT_CASE_EQ(AVAL_State_Toppled)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0F)
                    EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_State_Normal)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim16)
                    EVT_EXEC_WAIT(EVS_Enemy_AirLift)
                EVT_CASE_EQ(AVAL_State_Toppled)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0F)
                    EVT_EXEC_WAIT(EVS_Enemy_AirLift)
                EVT_CASE_EQ(AVAL_State_Charged)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0F)
                    EVT_EXEC_WAIT(EVS_Enemy_AirLift)
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_State_Normal)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim16)
                EVT_CASE_EQ(AVAL_State_Toppled)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0F)
                EVT_CASE_EQ(AVAL_State_Charged)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0F)
            EVT_END_SWITCH
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(AVAL_State_Normal)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim01)
                EVT_CASE_EQ(AVAL_State_Toppled)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0F)
                EVT_CASE_EQ(AVAL_State_Charged)
                    EVT_SET_CONST(LVar0, PRT_MAIN)
                    EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim0F)
            EVT_END_SWITCH
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
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
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim06)
    EVT_ELSE
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        EVT_IF_EQ(LVar0, AVAL_State_Toppled)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_FlippedTurns, LVar0)
            EVT_SUB(LVar0, 1)
            EVT_IF_GT(LVar0, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FlippedTurns, LVar0)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(3.0))
                EVT_WAIT(15)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0))
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_ELSE
                EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(3.0))
                EVT_WAIT(10)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0))
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
                EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_JUMP)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim0F)
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
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim01)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
                EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefenseTable)))
                EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -4, 32)
                EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -4)
                EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, TRUE)
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, FALSE)
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim07)
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
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim06)
        EVT_WAIT(10)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_TOSS)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 4, BS_FLAGS1_INCLUDE_POWER_UPS)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim08)
            EVT_WAIT(8)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_WAIT(4)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim16)
            EVT_WAIT(1)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim16)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim16)
            EVT_WAIT(6)
            EVT_SUB(LVar1, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim16)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim01)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetPartYaw, ACTOR_SELF, PRT_MAIN, 0)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim08)
            EVT_WAIT(8)
            EVT_CALL(YieldTurn)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim01)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_ChargedToss) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    EVT_IF_EQ(LVar0, AVAL_State_Normal) // charge for attack
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_POWER_UP)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 10)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 6, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 45, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim15)
        EVT_WAIT(30)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_THREAD
            EVT_WAIT(8)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim07)
        EVT_END_THREAD
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_A)
        EVT_CALL(N(StartRumbleWithParams), 128, 10)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(0.5))
        EVT_END_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim06)
        EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(ChargedStatusTable)))
        EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ChargedDefense)))
        EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FLIPABLE, FALSE)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Charged)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ChargedAnims)))
        EVT_CALL(EnableActorGlow, ACTOR_SELF, TRUE)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, TRUE)
        EVT_WAIT(10)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_LOOP(20)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, 1, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_KOOPA_LAUNCH_SHELL)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 4, BS_FLAGS1_INCLUDE_POWER_UPS)
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
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            EVT_CALL(YieldTurn)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorPos, ACTOR_SELF, 300, 0, 0)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim08)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable)))
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefenseTable)))
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FLIPABLE, TRUE)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
            EVT_WAIT(10)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
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
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarA, 0, SUPPRESS_EVENT_ALL, 0, DMG_CHARGED_TOSS, BS_FLAGS1_TRIGGER_EVENTS)
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
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorPos, ACTOR_SELF, 300, 0, 0)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Koopatrol_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim01)
            EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable)))
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefenseTable)))
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_FLIPABLE, TRUE)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GetAvailableColumn) = {
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
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
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_SET(LFlag1, FALSE)
    EVT_SET(LFlag2, FALSE)
    EVT_SET(LFlag3, FALSE)
    EVT_SET(LFlag4, FALSE)
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(GetIndexFromHome, LVar0, LVar1)
        EVT_MOD(LVar1, 4)
        EVT_SWITCH(LVar1)
            EVT_CASE_EQ(0)
                EVT_SET(LFlag1, TRUE)
            EVT_CASE_EQ(1)
                EVT_SET(LFlag2, TRUE)
            EVT_CASE_EQ(2)
                EVT_SET(LFlag3, TRUE)
            EVT_CASE_EQ(3)
                EVT_SET(LFlag4, TRUE)
        EVT_END_SWITCH
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_IF_EQ(LFlag1, FALSE)
        EVT_SET(LVarA, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LFlag2, FALSE)
        EVT_SET(LVarA, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LFlag3, FALSE)
        EVT_SET(LVarA, 2)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LFlag4, FALSE)
        EVT_SET(LVarA, 3)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVarA, -1)
    EVT_RETURN
    EVT_END
};

Vec3i N(SummonPos) = { NPC_DISPOSE_LOCATION };

Formation N(BackupFormation) = {
    ACTOR_BY_POS(NAMESPACE, N(SummonPos), 100)
};

EvtScript N(EVS_Move_SummonBackup) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim02)
    EVT_WAIT(20)
    EVT_LOOP(2)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim02)
        EVT_WAIT(8)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
        EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim09)
        EVT_WAIT(8)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim02)
        EVT_WAIT(8)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
        EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim09)
        EVT_WAIT(8)
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 30, 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Koopatrol_Anim16)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
    EVT_CALL(SummonEnemy, EVT_PTR(N(BackupFormation)), FALSE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    EVT_ADD(LVar1, 200)
    EVT_CALL(SetActorPos, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(SetGoalToIndex, LVar0, LVarA)
    EVT_CALL(PlaySoundAtActor, LVar0, SOUND_SHELL_TOSS)
    EVT_CALL(SetActorSounds, LVar0, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    EVT_CALL(SetAnimation, LVar0, 1, ANIM_Koopatrol_Anim06)
    EVT_CALL(SetActorSpeed, LVar0, EVT_FLOAT(6.0))
    EVT_CALL(RunToGoal, LVar0, 0, FALSE)
    EVT_CALL(SetAnimation, LVar0, 1, ANIM_Koopatrol_Anim08)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, LVar0, 1, ANIM_Koopatrol_Anim01)
    EVT_CALL(GetActorPos, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(ForceHomePos, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(HPBarToHome, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Generation, LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, LVar0, AVAR_Generation, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, LVar0, AVAR_Generation, 2)
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_AncestorColumn, LVar1)
    EVT_CALL(SetActorVar, LVar0, AVAR_AncestorColumn, LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(GetBattleVar, BTL_VAR_KoopatrolSummonCount_0, LVar0)
            EVT_ADD(LVar0, 1)
            EVT_CALL(SetBattleVar, BTL_VAR_KoopatrolSummonCount_0, LVar0)
        EVT_CASE_EQ(1)
            EVT_CALL(GetBattleVar, BTL_VAR_KoopatrolSummonCount_1, LVar0)
            EVT_ADD(LVar0, 1)
            EVT_CALL(SetBattleVar, BTL_VAR_KoopatrolSummonCount_1, LVar0)
        EVT_CASE_EQ(2)
            EVT_CALL(GetBattleVar, BTL_VAR_KoopatrolSummonCount_2, LVar0)
            EVT_ADD(LVar0, 1)
            EVT_CALL(SetBattleVar, BTL_VAR_KoopatrolSummonCount_2, LVar0)
        EVT_CASE_EQ(3)
            EVT_CALL(GetBattleVar, BTL_VAR_KoopatrolSummonCount_3, LVar0)
            EVT_ADD(LVar0, 1)
            EVT_CALL(SetBattleVar, BTL_VAR_KoopatrolSummonCount_3, LVar0)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CountActiveSummoners) = {
    EVT_SET(LVar9, 0)
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(GetOriginalActorType, LVar0, LVar2)
        EVT_SWITCH(LVar2)
            EVT_CASE_EQ(ACTOR_TYPE_KOOPATROL)
                EVT_CALL(GetStatusFlags, LVar0, LVar3)
                EVT_IF_NOT_FLAG(LVar3, STATUS_FLAGS_IMMOBILIZED)
                    EVT_CALL(GetActorVar, LVar0, AVAR_State, LVar3)
                    EVT_IF_EQ(LVar3, AVAL_State_Normal)
                        EVT_CALL(GetActorVar, LVar0, AVAR_Generation, LVar3)
                        EVT_SWITCH(LVar3)
                            EVT_CASE_OR_EQ(0)
                            EVT_CASE_OR_EQ(1)
                                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_AncestorColumn, LVar3)
                                EVT_SWITCH(LVar3)
                                    EVT_CASE_EQ(0)
                                        EVT_CALL(GetBattleVar, BTL_VAR_KoopatrolSummonCount_0, LVar4)
                                    EVT_CASE_EQ(1)
                                        EVT_CALL(GetBattleVar, BTL_VAR_KoopatrolSummonCount_1, LVar4)
                                    EVT_CASE_EQ(2)
                                        EVT_CALL(GetBattleVar, BTL_VAR_KoopatrolSummonCount_2, LVar4)
                                    EVT_CASE_EQ(3)
                                        EVT_CALL(GetBattleVar, BTL_VAR_KoopatrolSummonCount_3, LVar4)
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
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
        EVT_EXEC_WAIT(N(EVS_Attack_ShellToss))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_State_Normal)
            EVT_CALL(GetBattleVar, BTL_VAR_HyperSync, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Generation, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_OR_EQ(0)
                        EVT_CASE_OR_EQ(1)
                            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_AncestorColumn, LVar0)
                            EVT_SWITCH(LVar0)
                                EVT_CASE_EQ(0)
                                    EVT_CALL(GetBattleVar, BTL_VAR_KoopatrolSummonCount_0, LVar1)
                                EVT_CASE_EQ(1)
                                    EVT_CALL(GetBattleVar, BTL_VAR_KoopatrolSummonCount_1, LVar1)
                                EVT_CASE_EQ(2)
                                    EVT_CALL(GetBattleVar, BTL_VAR_KoopatrolSummonCount_2, LVar1)
                                EVT_CASE_EQ(3)
                                    EVT_CALL(GetBattleVar, BTL_VAR_KoopatrolSummonCount_3, LVar1)
                            EVT_END_SWITCH
                            EVT_IF_GE(LVar1, 2)
                                EVT_CALL(RandInt, 1000, LVar0)
                                EVT_IF_LT(LVar0, 300)
                                    EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                                    EVT_EXEC_WAIT(N(EVS_Attack_ChargedToss))
                                EVT_ELSE
                                    EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                                    EVT_EXEC_WAIT(N(EVS_Attack_ShellToss))
                                EVT_END_IF
                                EVT_RETURN
                            EVT_END_IF
                        EVT_END_CASE_GROUP
                        EVT_CASE_EQ(2)
                            EVT_CALL(RandInt, 1000, LVar0)
                            EVT_IF_LT(LVar0, 300)
                                EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                                EVT_EXEC_WAIT(N(EVS_Attack_ChargedToss))
                            EVT_ELSE
                                EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                                EVT_EXEC_WAIT(N(EVS_Attack_ShellToss))
                            EVT_END_IF
                            EVT_RETURN
                    EVT_END_SWITCH
                    EVT_EXEC_WAIT(N(EVS_GetAvailableColumn))
                    EVT_IF_EQ(LVarA, -1)
                        EVT_CALL(RandInt, 1000, LVar0)
                        EVT_IF_LT(LVar0, 300)
                            EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                            EVT_EXEC_WAIT(N(EVS_Attack_ChargedToss))
                        EVT_ELSE
                            EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                            EVT_EXEC_WAIT(N(EVS_Attack_ShellToss))
                        EVT_END_IF
                        EVT_RETURN
                    EVT_END_IF
                    EVT_EXEC_WAIT(N(EVS_CountActiveSummoners))
                    EVT_SWITCH(LVar9)
                        EVT_CASE_EQ(1)
                            EVT_CALL(RandInt, 1000, LVar0)
                            EVT_IF_LT(LVar0, 400)
                                EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                                EVT_EXEC_WAIT(N(EVS_Move_SummonBackup))
                                EVT_RETURN
                            EVT_END_IF
                        EVT_CASE_EQ(2)
                            EVT_CALL(RandInt, 1000, LVar0)
                            EVT_IF_LT(LVar0, 200)
                                EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                                EVT_EXEC_WAIT(N(EVS_Move_SummonBackup))
                                EVT_RETURN
                            EVT_END_IF
                        EVT_CASE_EQ(3)
                            EVT_CALL(RandInt, 1000, LVar0)
                            EVT_IF_LT(LVar0, 100)
                                EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                                EVT_EXEC_WAIT(N(EVS_Move_SummonBackup))
                                EVT_RETURN
                            EVT_END_IF
                    EVT_END_SWITCH
                    EVT_CALL(RandInt, 1000, LVar0)
                    EVT_IF_LT(LVar0, 300)
                        EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                        EVT_EXEC_WAIT(N(EVS_Attack_ChargedToss))
                    EVT_ELSE
                        EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                        EVT_EXEC_WAIT(N(EVS_Attack_ShellToss))
                    EVT_END_IF
                EVT_CASE_EQ(1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Generation, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_OR_EQ(0)
                        EVT_CASE_OR_EQ(1)
                            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_AncestorColumn, LVar0)
                            EVT_SWITCH(LVar0)
                                EVT_CASE_EQ(0)
                                    EVT_CALL(GetBattleVar, BTL_VAR_KoopatrolSummonCount_0, LVar1)
                                EVT_CASE_EQ(1)
                                    EVT_CALL(GetBattleVar, BTL_VAR_KoopatrolSummonCount_1, LVar1)
                                EVT_CASE_EQ(2)
                                    EVT_CALL(GetBattleVar, BTL_VAR_KoopatrolSummonCount_2, LVar1)
                                EVT_CASE_EQ(3)
                                    EVT_CALL(GetBattleVar, BTL_VAR_KoopatrolSummonCount_3, LVar1)
                            EVT_END_SWITCH
                            EVT_IF_GE(LVar1, 2)
                                EVT_CALL(RandInt, 1000, LVar0)
                                EVT_IF_LT(LVar0, 300)
                                    EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                                    EVT_EXEC_WAIT(N(EVS_Attack_ChargedToss))
                                EVT_ELSE
                                    EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                                    EVT_EXEC_WAIT(N(EVS_Attack_ShellToss))
                                EVT_END_IF
                                EVT_RETURN
                            EVT_END_IF
                        EVT_END_CASE_GROUP
                        EVT_CASE_EQ(2)
                            EVT_EXEC_WAIT(N(EVS_Attack_ShellToss))
                            EVT_RETURN
                    EVT_END_SWITCH
                    EVT_EXEC_WAIT(N(EVS_GetAvailableColumn))
                    EVT_IF_EQ(LVarA, -1)
                        EVT_EXEC_WAIT(N(EVS_Attack_ShellToss))
                        EVT_RETURN
                    EVT_END_IF
                    EVT_EXEC_WAIT(N(EVS_CountActiveSummoners))
                    EVT_SWITCH(LVar9)
                        EVT_CASE_EQ(1)
                            EVT_CALL(RandInt, 1000, LVar0)
                            EVT_IF_LT(LVar0, 400)
                                EVT_EXEC_WAIT(N(EVS_Move_SummonBackup))
                                EVT_RETURN
                            EVT_END_IF
                        EVT_CASE_EQ(2)
                            EVT_CALL(RandInt, 1000, LVar0)
                            EVT_IF_LT(LVar0, 200)
                                EVT_EXEC_WAIT(N(EVS_Move_SummonBackup))
                                EVT_RETURN
                            EVT_END_IF
                        EVT_CASE_EQ(3)
                            EVT_CALL(RandInt, 1000, LVar0)
                            EVT_IF_LT(LVar0, 100)
                                EVT_EXEC_WAIT(N(EVS_Move_SummonBackup))
                                EVT_RETURN
                            EVT_END_IF
                    EVT_END_SWITCH
                    EVT_EXEC_WAIT(N(EVS_Attack_ShellToss))
                EVT_CASE_EQ(2)
                    EVT_EXEC_WAIT(N(EVS_Attack_ChargedToss))
            EVT_END_SWITCH
        EVT_CASE_EQ(AVAL_State_Toppled)
            EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
            EVT_EXEC_WAIT(N(EVS_Attack_ShellToss))
        EVT_CASE_EQ(AVAL_State_Charged)
            EVT_EXEC_WAIT(N(EVS_Attack_ChargedToss))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

