#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleGoombario.h"

#define NAMESPACE A(goombario_clone)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleGoombario_Idle,
    STATUS_KEY_STONE,     ANIM_BattleGoombario_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleGoombario_Still,
    STATUS_KEY_POISON,    ANIM_BattleGoombario_Idle,
    STATUS_KEY_STOP,      ANIM_BattleGoombario_Still,
    STATUS_KEY_STATIC,    ANIM_BattleGoombario_Idle,
    STATUS_KEY_PARALYZE,  ANIM_BattleGoombario_Still,
    STATUS_KEY_DIZZY,     ANIM_BattleGoombario_Injured,
    STATUS_KEY_FEAR,      ANIM_BattleGoombario_Injured,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              60,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               80,
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
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 20 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -9 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GHOST_GOOMBARIO,
    .level = ACTOR_LEVEL_GHOST_GOOMBARIO,
    .maxHP = 15,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 80,
    .hurricaneChance = 70,
    .spookChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 2,
    .size = { 29, 26 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
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
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_CALL(GetLastElement, LVar1)
            EVT_IF_FLAG(LVar1, DAMAGE_TYPE_SHOCK)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
                EVT_EXEC_WAIT(A(EVS_Duplighost_OnHitElectric))
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_BurnHurt1)
            EVT_SET_CONST(LVar2, ANIM_BattleGoombario_BurnHurt2)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_BurnHurt1)
            EVT_SET_CONST(LVar2, ANIM_BattleGoombario_BurnHurt2)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(A(EVS_Duplighost_OnDeath))
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_BurnHurt2)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(A(EVS_Duplighost_OnDeath))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(A(EVS_Duplighost_OnShockHit))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_EXEC_WAIT(A(EVS_Duplighost_OnDeath))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_SET(LVar2, 12)
            EVT_EXEC_WAIT(A(EVS_Duplighost_OnShockDeath))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_EXEC_WAIT(A(EVS_Duplighost_OnDeath))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_Run)
            EVT_SET_CONST(LVar2, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_Run)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/UnkFunc62.inc.c"
#include "common/ActorJumpToPos.inc.c"

EvtScript N(EVS_HeadbonkFollowthrough) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
    EVT_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
        EVT_SET(LVar0, 180)
        EVT_LOOP(15)
            EVT_SUB(LVar0, 60)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Fall)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 60)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_SETF(LVar5, EVT_FLOAT(7.2))
    EVT_ELSE
        EVT_SET(LVar5, 18)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar5, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
    EVT_ADD(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar5, 0)
    EVT_WAIT(1)
    EVT_ADD(LVar0, 10)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar5, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Run)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ApproachPlayer) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 70, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Run)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
    EVT_RETURN
    EVT_END
};

// copied from goombario.c and used, but result is discarded
EvtScript N(EVS_CalculateJumpTime) = {
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVarB, LVarC, LVarD)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarC, LVarD, LVarE)
    EVT_IF_GT(LVarB, LVarC)
        EVT_SUB(LVarB, LVarC)
    EVT_ELSE
        EVT_SUB(LVarC, LVarB)
        EVT_SET(LVarB, LVarC)
    EVT_END_IF
    EVT_SUB(LVarB, 20)
    EVT_DIVF(LVarB, EVT_FLOAT(10.588))
    EVT_ADDF(LVarB, 15)
    EVT_SET(LVarA, LVarB)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_Headbonk) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_EXEC_WAIT(N(EVS_ApproachPlayer))
    EVT_EXEC_WAIT(N(EVS_CalculateJumpTime))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_SETF(LVar0, EVT_FLOAT(7.2))
        EVT_SETF(LVar1, EVT_FLOAT(7.6))
        EVT_SETF(LVar1, EVT_FLOAT(3.6))
    EVT_ELSE
        EVT_SET(LVar0, 18)
        EVT_SET(LVar1, 19)
        EVT_SET(LVar2, 9)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar1, 0)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar2, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 0, 5)
    EVT_CALL(SetJumpAnimations, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_GOOMBARIO_JUMP)
    EVT_CALL(N(UnkFunc62), LVarA, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetJumpAnimations, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
            EVT_CALL(N(ActorJumpToPos))
            EVT_THREAD
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
            EVT_END_THREAD
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(EVS_HeadbonkFollowthrough))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CHILD_THREAD
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT(1)
    EVT_WAIT(2)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Copy_PartnerLevel, LVar9)
    EVT_SWITCH(LVar9)
        EVT_CASE_EQ(PARTNER_RANK_NORMAL)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
        EVT_CASE_EQ(PARTNER_RANK_SUPER)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
        EVT_CASE_EQ(PARTNER_RANK_ULTRA)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 3, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_END_SWITCH
    EVT_CALL(GetActorHP, ACTOR_PLAYER, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_SET(LVarA, 24)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Copy_PartnerLevel, LVar9)
    EVT_SWITCH(LVar9)
        EVT_CASE_EQ(PARTNER_RANK_NORMAL)
            EVT_THREAD
                EVT_WAIT(4)
                EVT_SET(LVar0, 0)
                EVT_LOOP(6)
                    EVT_ADD(LVar0, 30)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetJumpAnimations, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_GOOMBARIO_HEADBONK)
            EVT_CALL(N(UnkFunc62), LVarA, 3)
        EVT_CASE_EQ(PARTNER_RANK_SUPER)
            EVT_THREAD
                EVT_WAIT(4)
                EVT_SET(LVar0, 0)
                EVT_LOOP(6)
                    EVT_ADD(LVar0, 30)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
            EVT_CALL(SetJumpAnimations, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_GOOMBARIO_HEADBONK)
            EVT_CALL(N(UnkFunc62), LVarA, 3)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
        EVT_CASE_EQ(PARTNER_RANK_ULTRA)
            EVT_THREAD
                EVT_WAIT(4)
                EVT_SET(LVar0, 0)
                EVT_LOOP(6)
                    EVT_ADD(LVar0, 30)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, EVT_IGNORE_ARG, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
            EVT_END_THREAD
            EVT_THREAD
                EVT_SET(LVar0, 0)
                EVT_LOOP(LVarA)
                    EVT_ADD(LVar0, 133)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, EVT_IGNORE_ARG, LVar0, EVT_IGNORE_ARG)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
            EVT_CALL(SetJumpAnimations, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_GOOMBARIO_HEADBONK)
            EVT_CALL(N(UnkFunc62), LVarA, 3)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
    EVT_END_SWITCH
    EVT_CHILD_THREAD
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT(1)
    EVT_WAIT(2)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Copy_PartnerLevel, LVar9)
    EVT_SWITCH(LVar9)
        EVT_CASE_EQ(PARTNER_RANK_NORMAL)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_CASE_EQ(PARTNER_RANK_SUPER)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 2, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_CASE_EQ(PARTNER_RANK_ULTRA)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 3, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_END_SWITCH
    EVT_LABEL(100)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(EVS_HeadbonkFollowthrough))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(CalculateTattleCamBoomLength)) {
    Actor* actor = get_actor(script->owner1.actorID);
    Actor* targetActor = get_actor(actor->targetActorID);
    s16 targetActorSizeX;
    u8 targetActorSizeY;
    u8 targetActorLargerDimension;

    if (!(targetActor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
        script->varTable[1] += targetActor->size.y / 2;
        script->varTable[1] += targetActor->size.y / 4;
    } else {
        script->varTable[1] -= targetActor->size.y / 2;
        script->varTable[1] -= targetActor->size.y / 4;
    }

    targetActorSizeY = targetActor->size.y;
    targetActorSizeX = targetActor->size.x;
    targetActorLargerDimension = targetActorSizeY;
    if (targetActorSizeY < targetActorSizeX) {
        targetActorLargerDimension = targetActorSizeX;
    }

    script->varTable[3] = targetActorLargerDimension + 126;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(OpenTattleWindow)) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, (s32) fx_tattle_window(0, 106.0f, 144.0f, 0, 1.0f, 0));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(HideTattleWindow)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, *args++);

    effect->data.tattleWindow->pos.y = NPC_DISPOSE_POS_Y;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CloseTattleWindow)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, *args++);

    effect->data.tattleWindow->pos.y = 144.0f;
    effect->flags |= FX_INSTANCE_FLAG_DISMISS;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Move_Tattle) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_WAIT(10)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_TATTLE_OPEN, TRUE)
    EVT_CALL(N(OpenTattleWindow), LVar5)
    EVT_WAIT(12)
    EVT_CALL(EnableBattleStatusBar, FALSE)
    EVT_CALL(SetCamEnabled, CAM_TATTLE, TRUE)
    EVT_CALL(SetCamNoDraw, CAM_TATTLE, FALSE)
    EVT_CALL(SetCamPerspective, CAM_TATTLE, CAM_UPDATE_MODE_6, 25, 16, 1024)
    EVT_CALL(SetCamViewport, CAM_TATTLE, 37, 95, 138, 99)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 8)
    EVT_SET(LVar1, 0)
    EVT_CALL(N(CalculateTattleCamBoomLength))
    EVT_WAIT(1)
    EVT_CALL(func_802CAE50, CAM_TATTLE, LVar0, LVar1, LVar2)
    EVT_CALL(func_802CABE8, CAM_TATTLE, 0, LVar3, 100, 4)
    EVT_WAIT(2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_TATTLE_WINDOW_OPEN)
    EVT_CALL(SetCamNoDraw, CAM_TATTLE, TRUE)
    EVT_WAIT(10)
    EVT_CALL(ActorSpeak, MSG_EnemyTattle_Mario, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Talk, ANIM_BattleGoombario_Idle)
    EVT_CALL(N(CloseTattleWindow), LVar5)
    EVT_WAIT(12)
    EVT_CALL(SetCamEnabled, CAM_TATTLE, FALSE)
    EVT_WAIT(32)
    EVT_CALL(EnableBattleStatusBar, TRUE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_TATTLE_OPEN, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(RandInt, 100, LVar0)
    EVT_IF_LT(LVar0, 10)
        EVT_EXEC_WAIT(N(EVS_Move_Tattle))
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_Attack_Headbonk))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

Formation A(GoombarioCloneFormation) = {
    ACTOR_BY_POS(NAMESPACE, A(DuplighostSummonPos), 0),
};
