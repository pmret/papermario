#include "../area.h"
#include "sprite/npc/Blooper.h"

#define NAMESPACE A(blooper)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Attack_SpinDrop);
extern EvtScript N(EVS_Attack_InkBlast);
extern EvtScript N(EVS_Death);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_TARGET      = 2,
};

enum N(ActorParams) {
    DMG_SPIN_DROP   = 3,
    DMG_INK_BLAST   = 3,
};

EvtScript N(EVS_FloatToPos) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim00)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim0C)
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
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BLOOPER_MOVE)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim00)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim0C)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_SUB(LVarB, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
    EVT_CALL(FallToGoal, ACTOR_SELF, 8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BLOOPER_MOVE)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim00)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim0C)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_SUB(LVarB, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
    EVT_CALL(FallToGoal, ACTOR_SELF, 8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BLOOPER_MOVE)
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
    STATUS_KEY_NORMAL,    ANIM_Blooper_Anim00,
    STATUS_KEY_STOP,      ANIM_Blooper_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Blooper_Anim07,
    STATUS_KEY_PARALYZE,  ANIM_Blooper_Anim08,
    STATUS_KEY_PARALYZE,  ANIM_Blooper_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Blooper_Anim08,
    STATUS_KEY_SHRINK,    ANIM_Blooper_Anim00,
    STATUS_END,
};

s32 N(AscendAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Blooper_Anim0C,
    STATUS_KEY_STOP,      ANIM_Blooper_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Blooper_Anim07,
    STATUS_KEY_PARALYZE,  ANIM_Blooper_Anim08,
    STATUS_KEY_PARALYZE,  ANIM_Blooper_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Blooper_Anim08,
    STATUS_KEY_SHRINK,    ANIM_Blooper_Anim0C,
    STATUS_END,
};

s32 N(DescendAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Blooper_Anim00,
    STATUS_KEY_STOP,      ANIM_Blooper_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Blooper_Anim07,
    STATUS_KEY_PARALYZE,  ANIM_Blooper_Anim08,
    STATUS_KEY_PARALYZE,  ANIM_Blooper_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Blooper_Anim08,
    STATUS_KEY_SHRINK,    ANIM_Blooper_Anim00,
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
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              80,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             90,
    STATUS_KEY_STOP,              100,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 50 },
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
        .posOffset = { 0, 20, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -37 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_BLOOPER,
    .level = ACTOR_LEVEL_BLOOPER,
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
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { 57, 61 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { 0, 22 },
    .statusTextOffset = { 15, 55 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.75), EVT_FLOAT(0.75), EVT_FLOAT(1.0))
    EVT_CALL(ForceHomePos, ACTOR_SELF, 90, 45, -10)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
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
        EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
        EVT_CALL(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_IF_GE(LVar4, LVar1)
            EVT_GOTO(11)
        EVT_END_IF
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(AscendAnims)))
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim00)
        EVT_WAIT(9)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim0C)
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
        EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
        EVT_CALL(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 10)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_IF_GE(LVar4, LVar1)
            EVT_GOTO(12)
        EVT_END_IF
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(AscendAnims)))
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim00)
        EVT_WAIT(9)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim0C)
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
        EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
        EVT_CALL(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, -10)
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
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar0, PRT_MAIN)
            EVT_SET(LVar1, ANIM_Blooper_Anim05)
            EVT_SET(LVar2, ANIM_Blooper_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LVar0, PRT_MAIN)
            EVT_SET(LVar1, ANIM_Blooper_Anim05)
            EVT_SET(LVar2, ANIM_Blooper_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim06)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim00)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_EXEC_WAIT(N(EVS_FloatToHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim04)
            EVT_EXEC_WAIT(N(EVS_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(EVS_FloatToHome))
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Blooper_Anim00)
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
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(RandInt, 100, LVar0)
        EVT_IF_LT(LVar0, 50)
            EVT_EXEC_WAIT(N(EVS_Attack_SpinDrop))
        EVT_ELSE
            EVT_EXEC_WAIT(N(EVS_Attack_InkBlast))
        EVT_END_IF
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_Attack_SpinDrop))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_SpinDrop) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 95)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(SetBattleCamZoom, 400)
        EVT_CALL(MoveBattleCamOver, 130)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 72)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(SetBattleCamZoom, 340)
        EVT_CALL(MoveBattleCamOver, 130)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 100)
    EVT_SET(LVar3, 15)
    EVT_EXEC_WAIT(N(EVS_FloatToPos))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BLOOPER_FALL)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_THREAD
                EVT_SET(LVar0, 0)
                EVT_LOOP(36)
                    EVT_ADD(LVar0, 30)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim0D)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
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
    EVT_END_SWITCH
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(16)
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim0D)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 30)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_SPIN_DROP, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_STONE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim04)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim00)
    EVT_END_IF
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

#include "common/StartRumbleWithParams.inc.c"
#include "common/SpitInk.inc.c"

EvtScript N(EVS_Attack_InkBlast) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 85)
    EVT_ADD(LVar1, 45)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim00)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim0C)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_IF_GT(LVarB, 30)
        EVT_SUB(LVarB, 30)
    EVT_ELSE
        EVT_SET(LVarB, 0)
    EVT_END_IF
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(FallToGoal, ACTOR_SELF, 8)
    EVT_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_SUB(LVar0, 30)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(SetBattleCamZoom, 350)
        EVT_CALL(MoveBattleCamOver, 50)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BLOOPER_MOVE)
    EVT_SET(LVar7, LVar4)
    EVT_ADD(LVar7, LVar0)
    EVT_MULF(LVar7, EVT_FLOAT(0.5))
    EVT_SET(LVar8, LVar5)
    EVT_ADD(LVar8, LVar1)
    EVT_MULF(LVar8, EVT_FLOAT(0.5))
    EVT_SET(LVar9, LVar6)
    EVT_ADD(LVar9, LVar2)
    EVT_MULF(LVar9, EVT_FLOAT(0.5))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar7, LVar8, LVar9)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 15, -2, EASING_CUBIC_OUT)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim00)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim0C)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_SUB(LVarB, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
    EVT_CALL(FallToGoal, ACTOR_SELF, 8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BLOOPER_MOVE)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 15, -2, EASING_CUBIC_OUT)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim03)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_SUB(LVarB, 30)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.2))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 16, 0, EASING_LINEAR)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 40, 0)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -40)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BLOOPER_SQUIRT)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_ADD(LVar3, 1)
    EVT_SUB(LVar4, 27)
    EVT_SUB(LVar5, 3)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(N(SpitInk), LVar0, LVar1, LVar2, LVar3, LVar4, LVar5)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT(10)
            EVT_IF_EQ(LVarF, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(30)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim00)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_EXEC_WAIT(N(EVS_FloatToHome))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetDamageSource, DMG_SRC_INK_BLAST)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_INK_BLAST, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim00)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_EXEC_WAIT(N(EVS_FloatToHome))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
