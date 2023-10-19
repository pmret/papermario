#include "../area.h"
#include "sprite/npc/BabyBlooper.h"
#include "battle/action_cmd/stop_leech.h"
#include "sprite/player.h"

#define NAMESPACE A(blooper_baby)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Death);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_TARGET      = 2,
};

enum N(ActorVars) {
    AVAR_HomePosX   = 0,
    AVAR_HomePosY   = 1,
    AVAR_HomePosZ   = 2,
};

enum N(ActorParams) {
    DMG_LEECH       = 2,
};

EvtScript N(EVS_FloatToPos) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim00)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim01)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_IF_GT(LVarB, 20)
        EVT_SUB(LVarB, 20)
    EVT_ELSE
        EVT_SET(LVarB, 0)
    EVT_END_IF
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(FallToGoal, ACTOR_SELF, 8)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BABY_BLOOPER_MOVE)
    EVT_SET(LVar7, LVar4)
    EVT_ADD(LVar7, LVar4)
    EVT_ADD(LVar7, LVar0)
    EVT_MULF(LVar7, EVT_FLOAT(0.33))
    EVT_SET(LVar8, LVar5)
    EVT_ADD(LVar8, LVar5)
    EVT_ADD(LVar8, LVar1)
    EVT_MULF(LVar8, EVT_FLOAT(0.33))
    EVT_SET(LVar9, LVar6)
    EVT_ADD(LVar9, LVar6)
    EVT_ADD(LVar9, LVar2)
    EVT_MULF(LVar9, EVT_FLOAT(0.33))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar7, LVar8, LVar9)
    EVT_CALL(FlyToGoal, ACTOR_SELF, LVar3, -2, EASING_CUBIC_OUT)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim00)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim01)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_SUB(LVarB, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
    EVT_CALL(FallToGoal, ACTOR_SELF, 8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BABY_BLOOPER_MOVE)
    EVT_SET(LVar7, LVar0)
    EVT_ADD(LVar7, LVar0)
    EVT_ADD(LVar7, LVar4)
    EVT_MULF(LVar7, EVT_FLOAT(0.33))
    EVT_SET(LVar8, LVar1)
    EVT_ADD(LVar8, LVar1)
    EVT_ADD(LVar8, LVar5)
    EVT_MULF(LVar8, EVT_FLOAT(0.33))
    EVT_SET(LVar9, LVar2)
    EVT_ADD(LVar9, LVar2)
    EVT_ADD(LVar9, LVar6)
    EVT_MULF(LVar9, EVT_FLOAT(0.33))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar7, LVar8, LVar9)
    EVT_CALL(FlyToGoal, ACTOR_SELF, LVar3, -2, EASING_CUBIC_OUT)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim00)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim01)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_SUB(LVarB, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
    EVT_CALL(FallToGoal, ACTOR_SELF, 8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BABY_BLOOPER_MOVE)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, LVar3, -2, EASING_CUBIC_OUT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_FloatToHome) = {
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, 12)
    EVT_EXEC_WAIT(N(EVS_FloatToPos))
    EVT_RETURN
    EVT_END
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BabyBlooper_Anim00,
    STATUS_KEY_STOP,      ANIM_BabyBlooper_Anim00,
    STATUS_KEY_SLEEP,     ANIM_BabyBlooper_Anim06,
    STATUS_KEY_PARALYZE,  ANIM_BabyBlooper_Anim07,
    STATUS_KEY_PARALYZE,  ANIM_BabyBlooper_Anim00,
    STATUS_KEY_DIZZY,     ANIM_BabyBlooper_Anim07,
    STATUS_KEY_SHRINK,    ANIM_BabyBlooper_Anim00,
    STATUS_END,
};

s32 N(AscendAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BabyBlooper_Anim01,
    STATUS_KEY_STOP,      ANIM_BabyBlooper_Anim00,
    STATUS_KEY_SLEEP,     ANIM_BabyBlooper_Anim06,
    STATUS_KEY_PARALYZE,  ANIM_BabyBlooper_Anim07,
    STATUS_KEY_PARALYZE,  ANIM_BabyBlooper_Anim00,
    STATUS_KEY_DIZZY,     ANIM_BabyBlooper_Anim07,
    STATUS_KEY_SHRINK,    ANIM_BabyBlooper_Anim01,
    STATUS_END,
};

s32 N(DescendAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BabyBlooper_Anim00,
    STATUS_KEY_STOP,      ANIM_BabyBlooper_Anim00,
    STATUS_KEY_SLEEP,     ANIM_BabyBlooper_Anim06,
    STATUS_KEY_PARALYZE,  ANIM_BabyBlooper_Anim07,
    STATUS_KEY_PARALYZE,  ANIM_BabyBlooper_Anim00,
    STATUS_KEY_DIZZY,     ANIM_BabyBlooper_Anim07,
    STATUS_KEY_SHRINK,    ANIM_BabyBlooper_Anim00,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,             100,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,              100,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
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
        .targetOffset = { 0, 85 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_TARGET,
        .posOffset = { 0, 27, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 1, -13 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_BLOOPER_BABY,
    .level = ACTOR_LEVEL_BLOOPER_BABY,
    .maxHP = 6,
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
    .size = { 28, 25 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -12, 20 },
    .statusTextOffset = { 10, 25 },
};

#include "common/StartRumbleWithParams.inc.c"
#include "common/SpawnEnemyDrainFX.inc.c"

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BABY_BLOOPER_MOVE)
    EVT_CALL(N(StartRumbleWithParams), 80, 20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim00)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim01)
    EVT_CALL(GetActorPos, ACTOR_ENEMY0, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 10)
    EVT_SUB(LVar2, 10)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 20)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(0.3))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 8, 0, EASING_LINEAR)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BABY_BLOOPER_MOVE)
    EVT_CALL(N(StartRumbleWithParams), 80, 20)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HomePosX, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HomePosY, LVar1)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HomePosZ, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 12, -2, EASING_CUBIC_OUT)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(SetGoalToHome, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_IF_GE(LVar4, LVar1)
            EVT_GOTO(11)
        EVT_END_IF
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(AscendAnims)))
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim00)
        EVT_WAIT(9)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim01)
        EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IdleFlyToGoal, ACTOR_SELF, 0, 0, EASING_SIN_OUT)
        EVT_LABEL(11)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(SetGoalToHome, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 5)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_IF_GE(LVar4, LVar1)
            EVT_GOTO(12)
        EVT_END_IF
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(AscendAnims)))
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim00)
        EVT_WAIT(9)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim01)
        EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IdleFlyToGoal, ACTOR_SELF, 0, 0, EASING_SIN_OUT)
        EVT_WAIT(3)
        EVT_LABEL(12)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DescendAnims)))
        EVT_CALL(SetGoalToHome, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, -5)
        EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(0.3))
        EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IdleFlyToGoal, ACTOR_SELF, 0, 1, EASING_SIN_OUT)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BabyBlooper_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BabyBlooper_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_SET_CONST(LVar1, ANIM_BabyBlooper_Anim03)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, ANIM_BabyBlooper_Anim04)
            EVT_SET(LVar2, ANIM_BabyBlooper_Anim05)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, ANIM_BabyBlooper_Anim04)
            EVT_SET(LVar2, ANIM_BabyBlooper_Anim05)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar1, ANIM_BabyBlooper_Anim05)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BabyBlooper_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BabyBlooper_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BabyBlooper_Anim03)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BabyBlooper_Anim00)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BabyBlooper_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BabyBlooper_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_EXEC_WAIT(N(EVS_FloatToHome))
        EVT_CASE_OR_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BabyBlooper_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BabyBlooper_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BabyBlooper_Anim03)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(EVS_FloatToHome))
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BabyBlooper_Anim00)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Death) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_EXEC_WAIT(EVS_Enemy_Death)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 100)
    EVT_SET(LVar3, 12)
    EVT_EXEC_WAIT(N(EVS_FloatToPos))
    EVT_THREAD
        EVT_WAIT(2)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
    EVT_END_THREAD
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim02)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarF, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_EXEC_WAIT(N(EVS_FloatToHome))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_HIT_STATIC)
        EVT_CASE_OR_EQ(HIT_RESULT_IMMUNE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim02)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarF, 7)
                EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, 0, BS_FLAGS1_NICE_HIT)
            EVT_END_IF
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_EXEC_WAIT(N(EVS_FloatToHome))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 50)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 325)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim02)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 10)
    EVT_SUB(LVar2, 5)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim08)
    EVT_CALL(ShowMessageBox, BTL_MSG_ACTION_TIP_MASH_BUTTON, 32767)
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_STOP_LEECH)
    EVT_CALL(action_command_stop_leech_init)
    EVT_CALL(SetupMashMeter, 1, 15, 0, 0, 0, 0)
    EVT_WAIT(10)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    EVT_CALL(action_command_stop_leech_start, 0, 32767, 3)
    EVT_LOOP(5)
        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Leeching)
        EVT_SET(LFlag0, FALSE)
        EVT_LOOP(10)
            EVT_CALL(GetActionSuccessCopy, LVar1)
            EVT_IF_EQ(LVar1, 1)
                EVT_SET(LFlag0, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(DispatchEventPlayer, EVENT_66)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LEECH)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_SET(LFlag0, FALSE)
        EVT_LOOP(2)
            EVT_CALL(GetActionSuccessCopy, LVar1)
            EVT_IF_EQ(LVar1, 1)
                EVT_SET(LFlag0, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(DispatchEventPlayer, EVENT_66)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.1), EVT_FLOAT(1.0))
        EVT_SET(LFlag0, FALSE)
        EVT_LOOP(2)
            EVT_CALL(GetActionSuccessCopy, LVar1)
            EVT_IF_EQ(LVar1, 1)
                EVT_SET(LFlag0, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(DispatchEventPlayer, EVENT_66)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
        EVT_SET(LFlag0, FALSE)
        EVT_LOOP(3)
            EVT_CALL(GetActionSuccessCopy, LVar1)
            EVT_IF_EQ(LVar1, 1)
                EVT_SET(LFlag0, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(DispatchEventPlayer, EVENT_66)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
        EVT_SET(LFlag0, FALSE)
        EVT_LOOP(2)
            EVT_CALL(GetActionSuccessCopy, LVar1)
            EVT_IF_EQ(LVar1, 1)
                EVT_SET(LFlag0, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(DispatchEventPlayer, EVENT_66)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        EVT_CALL(SetDamageSource, DMG_SRC_LEECH)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, DMG_LEECH, BS_FLAGS1_NICE_HIT)
        EVT_CALL(StartRumble, BTL_RUMBLE_HIT_MIN)
        EVT_CALL(GetLastDamage, ACTOR_PLAYER, LVar3)
        EVT_IF_NE(LVar3, 0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEART_BOUNCE)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 10)
            EVT_CALL(N(SpawnDrainHealthStartFX), LVar0, LVar1, LVar2, LVar3)
            EVT_THREAD
                EVT_WAIT(15)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_STAR_BOUNCE_A)
                EVT_CALL(N(SpawnDrainHealthContinueFX), LVar0, LVar1, LVar2, LVar3)
            EVT_END_THREAD
            EVT_ADD(LVar0, 20)
            EVT_ADD(LVar1, 20)
            EVT_PLAY_EFFECT(EFFECT_RECOVER, 0, LVar0, LVar1, LVar2, LVar3, 0)
            EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
            EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
            EVT_ADD(LVar0, LVar3)
            EVT_IF_GT(LVar0, LVar1)
                EVT_SET(LVar0, LVar1)
            EVT_END_IF
            EVT_CALL(SetEnemyHP, ACTOR_SELF, LVar0)
        EVT_ELSE
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(DispatchEventPlayer, EVENT_66)
            EVT_CALL(func_80269470)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
        EVT_SET(LFlag0, FALSE)
        EVT_LOOP(3)
            EVT_CALL(GetActionSuccessCopy, LVar1)
            EVT_IF_EQ(LVar1, 1)
                EVT_SET(LFlag0, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(DispatchEventPlayer, EVENT_66)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
        EVT_SET(LFlag0, FALSE)
        EVT_LOOP(2)
            EVT_CALL(GetActionSuccessCopy, LVar1)
            EVT_IF_EQ(LVar1, 1)
                EVT_SET(LFlag0, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(DispatchEventPlayer, EVENT_66)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.1), EVT_FLOAT(1.0))
        EVT_SET(LFlag0, FALSE)
        EVT_LOOP(2)
            EVT_CALL(GetActionSuccessCopy, LVar1)
            EVT_IF_EQ(LVar1, 1)
                EVT_SET(LFlag0, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(DispatchEventPlayer, EVENT_66)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(GetPlayerHP, LVar1)
        EVT_IF_EQ(LVar1, 0)
            EVT_CALL(DispatchEventPlayer, EVENT_66)
            EVT_CALL(func_80269470)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_SET(LFlag0, FALSE)
        EVT_LOOP(12)
            EVT_CALL(GetActionSuccessCopy, LVar1)
            EVT_IF_EQ(LVar1, 1)
                EVT_SET(LFlag0, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(DispatchEventPlayer, EVENT_66)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DispatchEventPlayer, EVENT_66)
    EVT_CALL(func_80269470)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_STONE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim02)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim00)
    EVT_END_IF
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_SUB(LVar1, 15)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_EXEC_WAIT(N(EVS_FloatToHome))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
