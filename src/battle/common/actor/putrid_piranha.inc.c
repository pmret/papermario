#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/LargePiranha.h"

#define NAMESPACE A(putrid_piranha)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Attack_Bite);
extern EvtScript N(EVS_Attack_BadBreath);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorParams) {
    DMG_BITE        = 3,
    DMG_BREATH      = 2,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_LargePiranha_Putrid_Anim01,
    STATUS_KEY_STONE,     ANIM_LargePiranha_Putrid_Anim00,
    STATUS_KEY_SLEEP,     ANIM_LargePiranha_Putrid_Anim00,
    STATUS_KEY_POISON,    ANIM_LargePiranha_Putrid_Anim01,
    STATUS_KEY_STOP,      ANIM_LargePiranha_Putrid_Anim00,
    STATUS_KEY_STATIC,    ANIM_LargePiranha_Putrid_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_LargePiranha_Putrid_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_LargePiranha_Putrid_Anim00,
    STATUS_KEY_DIZZY,     ANIM_LargePiranha_Putrid_Anim0F,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_FIRE,     0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              95,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              50,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               85,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
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
        .targetOffset = { -15, 50 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 3, -14 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_PUTRID_PIRANHA,
    .level = ACTOR_LEVEL_PUTRID_PIRANHA,
    .maxHP = 12,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 60,
    .airLiftChance = 20,
    .hurricaneChance = 20,
    .spookChance = 30,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 95,
    .coinReward = 1,
    .size = { 60, 52 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -22, 32 },
    .statusTextOffset = { 1, 44 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_RETURN
    EVT_END
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_DIZZY)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -27, 33)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 5, -11)
            EVT_CALL(N(SetAbsoluteStatusOffsets), -37, 9, -7, 31)
        EVT_ELSE
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -15, 50)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 3, -14)
            EVT_CALL(N(SetAbsoluteStatusOffsets), -22, 32, 1, 44)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReturnHome) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim03)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim01)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
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
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Putrid_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Putrid_Anim10)
            EVT_SET_CONST(LVar2, ANIM_LargePiranha_Putrid_Anim11)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Putrid_Anim10)
            EVT_SET_CONST(LVar2, ANIM_LargePiranha_Putrid_Anim11)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Putrid_Anim11)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Putrid_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Putrid_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Putrid_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Putrid_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Putrid_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Putrid_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Putrid_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Putrid_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Putrid_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Putrid_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Putrid_Anim03)
            EVT_SET_CONST(LVar2, ANIM_LargePiranha_Putrid_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Putrid_Anim03)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_LargePiranha_Putrid_Anim03)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_EXEC_WAIT(N(EVS_Attack_Bite))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(RandInt, 100, LVar0)
    EVT_IF_LT(LVar0, 70)
        EVT_EXEC_WAIT(N(EVS_Attack_BadBreath))
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_Attack_Bite))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_Bite) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim18)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
        EVT_WAIT(8)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 27)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar3, LVar0)
        EVT_SET(LVar4, LVar1)
        EVT_SET(LVar5, LVar2)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar6, LVar7, LVar8)
        EVT_ADD(LVar3, LVar6)
        EVT_ADD(LVar4, LVar7)
        EVT_ADD(LVar5, LVar8)
        EVT_DIV(LVar3, 2)
        EVT_DIV(LVar4, 2)
        EVT_DIV(LVar5, 2)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamTarget, LVar3, LVar4, LVar5)
        EVT_CALL(SetBattleCamZoom, 300)
        EVT_CALL(SetBattleCamOffsetZ, 40)
        EVT_WAIT(20)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim17)
        EVT_WAIT(8)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim03)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim03)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_ADD(LVar0, 10)
        EVT_ELSE
            EVT_ADD(LVar0, 27)
        EVT_END_IF
        EVT_SET(LVar1, 0)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim01)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_PIRANHA_BITE)
    EVT_END_THREAD
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim05)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim06)
            EVT_WAIT(6)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim07)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(14)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(YieldTurn)
            EVT_CALL(GetBattlePhase, LVar0)
            EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim18)
                EVT_WAIT(10)
                EVT_CALL(SetGoalToHome, ACTOR_SELF)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim17)
                EVT_WAIT(10)
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, FALSE)
            EVT_ELSE
                EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(2.0))
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
                EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
                EVT_EXEC_WAIT(N(EVS_ReturnHome))
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0))
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim05)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim06)
    EVT_WAIT(1)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_BITE, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim07)
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
            EVT_CALL(GetBattlePhase, LVar0)
            EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim18)
                EVT_WAIT(10)
                EVT_CALL(SetGoalToHome, ACTOR_SELF)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim17)
                EVT_WAIT(10)
                EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, FALSE)
            EVT_ELSE
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
                EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/UnkEffect6FFunc.inc.c"

EvtScript N(EVS_Attack_BadBreath) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim03)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim03)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar0, 16)
    EVT_ELSE
        EVT_ADD(LVar0, 40)
    EVT_END_IF
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim01)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim08)
    EVT_WAIT(11)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_PIRANHA_BREATH)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar0, 12)
        EVT_SET(LVar1, 5)
        EVT_SETF(LVar3, EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_ADD(LVar0, 32)
        EVT_SET(LVar1, 13)
        EVT_SETF(LVar3, EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(N(UnkEffect6FFunc), LVar2, LVar0, LVar1, LVar2, LVar3, 30, 120, 0, 120)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim09)
    EVT_WAIT(5)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim0A)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(14)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(2.0))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, DMG_STATUS_KEY(STATUS_FLAG_POISON, 3, 100), DMG_BREATH, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_LargePiranha_Putrid_Anim0A)
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
