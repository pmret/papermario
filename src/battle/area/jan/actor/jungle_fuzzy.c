#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Fuzzy.h"
#include "battle/action_cmd/stop_leech.h"

#define NAMESPACE b_area_jan_jungle_fuzzy

extern s32 N(IdleAnimations_8021EADC)[];
extern EvtScript N(init_8021EB28);
extern EvtScript N(takeTurn_80221628);
extern EvtScript N(idle_8021EB8C);
extern EvtScript N(handleEvent_8021EB9C);
extern Formation N(specialFormation_8022180C);

s32 N(DefenseTable_8021E9D0)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_FIRE, 0,
    ELEMENT_END,
};

s32 N(StatusTable_8021E9E4)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 95,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 0,
    STATUS_STATIC, 70,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 75,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint  N(PartsTable_8021EA90)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 20 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8021EADC),
        .defenseTable = N(DefenseTable_8021E9D0),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_JUNGLE_FUZZY,
    .level = 16,
    .maxHP = 7,
    .partCount = ARRAY_COUNT( N(PartsTable_8021EA90)),
    .partsData = N(PartsTable_8021EA90),
    .initScript = &N(init_8021EB28),
    .statusTable = N(StatusTable_8021E9E4),
    .escapeChance = 30,
    .airLiftChance = 85,
    .hurricaneChance = 80,
    .spookChance = 75,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 33, 28 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(IdleAnimations_8021EADC)[] = {
    STATUS_NORMAL,    ANIM_Fuzzy_Jungle_Idle,
    STATUS_STONE,     ANIM_Fuzzy_Jungle_Still,
    STATUS_SLEEP,     ANIM_Fuzzy_Jungle_Sleep,
    STATUS_POISON,    ANIM_Fuzzy_Jungle_Idle,
    STATUS_STOP,      ANIM_Fuzzy_Jungle_Still,
    STATUS_STATIC,    ANIM_Fuzzy_Jungle_Idle,
    STATUS_PARALYZE,  ANIM_Fuzzy_Jungle_Still,
    STATUS_DIZZY,     ANIM_Fuzzy_Jungle_Stunned,
    STATUS_FEAR,      ANIM_Fuzzy_Jungle_Stunned,
    STATUS_END,
};

EvtScript N(init_8021EB28) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_80221628)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8021EB8C)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021EB9C)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8021EB8C) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021EB9C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_CALL(GetLastElement, LVar0)
            EVT_IF_FLAG(LVar0, DAMAGE_TYPE_SHOCK)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_HurtShock)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_Hurt)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_Burn)
            EVT_SET_CONST(LVar2, ANIM_Fuzzy_Jungle_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_Burn)
            EVT_SET_CONST(LVar2, ANIM_Fuzzy_Jungle_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_BurnStill)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_Hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_Hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_Hurt)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(func_80269470)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_HurtShock)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_HurtShock)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_Run)
            EVT_EXEC_WAIT(D_8029C0A4)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(func_80269470)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_HurtShock)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_HurtShock)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_Idle)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetLastElement, LVar0)
            EVT_IF_FLAG(LVar0, DAMAGE_TYPE_SHOCK)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_HurtShock)
                EVT_EXEC_WAIT(EVS_DoNormalHit)
                EVT_WAIT(10)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_HurtShock)
                EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_Hurt)
                EVT_EXEC_WAIT(EVS_DoNormalHit)
                EVT_WAIT(10)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_Hurt)
                EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_Idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_Run)
            EVT_SET_CONST(LVar2, ANIM_Fuzzy_Jungle_Anim09)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_Run)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_Run)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Fuzzy_Jungle_Idle)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(divide) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 330)
    EVT_CALL(SetBattleCamOffsetZ, 30)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(20)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_01)
    EVT_THREAD
        EVT_WAIT(30)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_206E)
        EVT_WAIT(30)
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_206F)
            EVT_WAIT(11)
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2070)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Fuzzy_Jungle_Anim0D)
    EVT_WAIT(130)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Fuzzy_Jungle_Walk)
    EVT_CALL(SummonEnemy, EVT_PTR(N(specialFormation_8022180C)), 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    EVT_CALL(SetActorPos, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(SetGoalToIndex, LVar0, LVarA)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Fuzzy_Jungle_Walk)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 14, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, LVar0, 1, ANIM_Fuzzy_Jungle_Walk)
    EVT_CALL(SetActorJumpGravity, LVar0, EVT_FLOAT(1.4))
    EVT_CALL(JumpToGoal, LVar0, 14, FALSE, TRUE, FALSE)
    EVT_CALL(GetActorPos, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(ForceHomePos, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(HPBarToHome, LVar0)
    EVT_CALL(SetAnimation, LVar0, 1, ANIM_Fuzzy_Jungle_Idle)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, LVar0, 0, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, LVar0, 0, 2)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/SpawnEnemyDrainFX.inc.c"

EvtScript N(leechAttack) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 50)
        EVT_SET(LVar1, 0)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Fuzzy_Jungle_Run)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_EXEC_WAIT(D_8029C12C)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Fuzzy_Jungle_Idle)
    EVT_LABEL(100)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Fuzzy_Jungle_Anim04)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 9, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
    EVT_WAIT(5)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 2, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 5)
            EVT_SET(LVar1, 0)
            EVT_SUB(LVar2, 5)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Fuzzy_Jungle_Jump)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 11, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Fuzzy_Jungle_Anim09)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 15)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(4)
            EVT_WAIT(5)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(5)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Fuzzy_Jungle_Run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_EXEC_WAIT(D_8029C12C)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(HIT_RESULT_HIT_STATIC)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_STATIC)
                EVT_SET(LocalFlag(0), 0)
            EVT_ELSE
                EVT_SET(LocalFlag(0), 1)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, -3, -12, -15)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Fuzzy_Jungle_Jump)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_IF_EQ(LocalFlag(0), 1)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 0, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar1)
    EVT_IF_FLAG(LVar1, STATUS_FLAG_STONE)
        EVT_WAIT(10)
        EVT_LOOP(2)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3E0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Fuzzy_Jungle_Bite)
            EVT_WAIT(21)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Fuzzy_Jungle_Still)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 330)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3E0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, -3, -2, 0)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.5), EVT_FLOAT(1.0))
            EVT_WAIT(2)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.6), EVT_FLOAT(1.6), EVT_FLOAT(1.0))
            EVT_WAIT(10)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 2, BS_FLAGS1_40)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Fuzzy_Jungle_Jump)
            EVT_WAIT(30)
        EVT_END_LOOP
    EVT_ELSE
        EVT_CALL(ShowMessageBox, BTL_MSG_ACTION_TIP_03, 0x00007FFF)
        EVT_CALL(ShowActionHud, TRUE)
        EVT_CALL(LoadActionCommand, ACTION_COMMAND_STOP_LEECH)
        EVT_CALL(action_command_stop_leech_init)
        EVT_CALL(SetupMashMeter, 1, 23, 0, 0, 0, 0)
        EVT_WAIT(10)
        EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
        EVT_CALL(action_command_stop_leech_start, 0, 32767, 3)
        EVT_SET(LVarD, 0)
        EVT_LOOP(5)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Leeching)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3E0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Fuzzy_Jungle_Bite)
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(21)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Fuzzy_Jungle_Still)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 330)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3E0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, -3, -2, 0)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(1)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(1)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(1)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(1)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.5), EVT_FLOAT(1.0))
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(2)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.6), EVT_FLOAT(1.6), EVT_FLOAT(1.0))
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(10)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(2)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 2, BS_FLAGS1_40)
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LVar3)
            EVT_IF_NE(LVar3, 0)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_206D)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_214)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 10)
                EVT_CALL(N(SpawnDrainHealthStartFX), LVar0, LVar1, LVar2, LVar3)
                EVT_THREAD
                    EVT_WAIT(15)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_25C)
                    EVT_CALL(N(SpawnDrainHealthContinueFX), LVar0, LVar1, LVar2, LVar3)
                EVT_END_THREAD
                EVT_ADD(LVar0, 20)
                EVT_ADD(LVar1, 20)
                EVT_PLAY_EFFECT(EFFECT_RECOVER, 0, LVar0, LVar1, LVar2, LVar3, 0)
                EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
                EVT_ADD(LVar0, LVar3)
                EVT_CALL(SetEnemyHP, ACTOR_SELF, LVar0)
            EVT_ELSE
                EVT_ADD(LVarD, 1)
                EVT_IF_GT(LVarD, 1)
                    EVT_CALL(func_80269470)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_IF
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Fuzzy_Jungle_Jump)
            EVT_CALL(GetPlayerHP, LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_CALL(func_80269470)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_SET(LocalFlag(0), 0)
            EVT_LOOP(35)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LocalFlag(0), 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LocalFlag(0), 1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(func_80269470)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Fuzzy_Jungle_Jump)
    EVT_END_IF
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Fuzzy_Jungle_Idle)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_THREAD
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.6), EVT_FLOAT(0.6), EVT_FLOAT(1.0))
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 10, 0)
        EVT_WAIT(1)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 330)
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.5), EVT_FLOAT(1.0))
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 300)
        EVT_WAIT(1)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 270)
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(0.7), EVT_FLOAT(1.0))
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 240)
        EVT_WAIT(1)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 210)
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 180)
        EVT_WAIT(2)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(0.7), EVT_FLOAT(1.0))
        EVT_WAIT(2)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.2), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 40)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.4), EVT_FLOAT(0.2), EVT_FLOAT(1.0))
    EVT_WAIT(1)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.2), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 150)
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 120)
        EVT_WAIT(1)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 90)
        EVT_WAIT(1)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 60)
        EVT_WAIT(1)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 30)
        EVT_WAIT(1)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_WAIT(5)
    EVT_CALL(YieldTurn)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Fuzzy_Jungle_Run)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_EXEC_WAIT(D_8029C12C)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Fuzzy_Jungle_Idle)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(802210E0) = {
    EVT_SET(LocalFlag(1), 0)
    EVT_SET(LocalFlag(2), 0)
    EVT_SET(LocalFlag(3), 0)
    EVT_SET(LocalFlag(4), 0)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar5)
    EVT_CALL(GetIndexFromHome, LVar0, LVar5)
    EVT_MOD(LVar5, 4)
    EVT_SWITCH(LVar5)
        EVT_CASE_EQ(0)
            EVT_SET(LocalFlag(1), 1)
        EVT_CASE_EQ(1)
            EVT_SET(LocalFlag(2), 1)
        EVT_CASE_EQ(2)
            EVT_SET(LocalFlag(3), 1)
        EVT_CASE_EQ(3)
            EVT_SET(LocalFlag(4), 1)
    EVT_END_SWITCH
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_SET(LVarA, -1)
    EVT_SET(LVarB, -1)
    EVT_CALL(GetIndexFromHome, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_IF_EQ(LocalFlag(2), 0)
                EVT_SET(LVarA, 1)
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_IF_EQ(LocalFlag(1), 0)
                EVT_SET(LVarA, 0)
            EVT_END_IF
            EVT_IF_EQ(LocalFlag(3), 0)
                EVT_IF_EQ(LVarA, -1)
                    EVT_SET(LVarA, 2)
                EVT_ELSE
                    EVT_SET(LVarB, 2)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_IF_EQ(LocalFlag(2), 0)
                EVT_SET(LVarA, 1)
            EVT_END_IF
            EVT_IF_EQ(LocalFlag(4), 0)
                EVT_IF_EQ(LVarA, -1)
                    EVT_SET(LVarA, 3)
                EVT_ELSE
                    EVT_SET(LVarB, 3)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_IF_EQ(LocalFlag(3), 0)
                EVT_SET(LVarA, 2)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_IF_NE(LVarB, -1)
        EVT_CALL(RandInt, 1000, LVar0)
        EVT_IF_LT(LVar0, 500)
            EVT_SET(LVarA, LVarB)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80221468) = {
    EVT_SET(LVar9, 0)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetOriginalActorType, LVar0, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_OR_EQ(ACTOR_TYPE_FOREST_FUZZY)
        EVT_CASE_OR_EQ(ACTOR_TYPE_JUNGLE_FUZZY)
            EVT_CALL(GetStatusFlags, LVar0, LVar3)
            EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(GetActorVar, LVar0, 0, LVar3)
                EVT_IF_NE(LVar3, 2)
                    EVT_ADD(LVar9, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(ACTOR_TYPE_SPEAR_GUY)
            EVT_CALL(GetStatusFlags, LVar0, LVar3)
            EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(GetActorVar, LVar0, 1, LVar3)
                EVT_IF_LT(LVar3, 2)
                    EVT_ADD(LVar9, 1)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80221628) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_EXEC_WAIT(N(leechAttack))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 2)
        EVT_EXEC_WAIT(N(leechAttack))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(802210E0))
    EVT_IF_EQ(LVarA, -1)
        EVT_EXEC_WAIT(N(leechAttack))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(80221468))
    EVT_SWITCH(LVar9)
        EVT_CASE_EQ(1)
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 400)
                EVT_EXEC_WAIT(N(divide))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 150)
                EVT_EXEC_WAIT(N(divide))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 70)
                EVT_EXEC_WAIT(N(divide))
                EVT_RETURN
            EVT_END_IF
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(leechAttack))
    EVT_RETURN
    EVT_END
};

Vec3i N(vector3D_80221800) = { NPC_DISPOSE_LOCATION };

Formation N(specialFormation_8022180C) = {
    { .actor = &NAMESPACE, .home = { .vec = &N(vector3D_80221800) } },
};
