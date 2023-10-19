#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Spiny.h"
#include "sprite/npc/Lakitu.h"
#include "effects.h"

#define NAMESPACE A(lakitu)

extern ActorBlueprint A(spiny);

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_SPINY_BALL  = 2,
    PRT_SPINY       = 3,
};

enum N(ActorVars) {
    AVAR_SummonCount    = 0,
};

enum N(ActorParams) {
    DMG_SPINY_TOSS  = 3,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Lakitu_Anim01,
    STATUS_KEY_STONE,     ANIM_Lakitu_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Lakitu_Anim08,
    STATUS_KEY_POISON,    ANIM_Lakitu_Anim01,
    STATUS_KEY_STOP,      ANIM_Lakitu_Anim00,
    STATUS_KEY_STATIC,    ANIM_Lakitu_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_Lakitu_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Lakitu_Anim09,
    STATUS_KEY_FEAR,      ANIM_Lakitu_Anim09,
    STATUS_END,
};

s32 N(SpinyBallAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Lakitu_Anim0B,
    STATUS_END,
};

s32 N(SpinyAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Spiny_Anim01,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_MYSTERY,  0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              50,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           50,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 35 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -13 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_SPINY_BALL,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(SpinyBallAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_SPINY,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(SpinyAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_LAKITU,
    .level = ACTOR_LEVEL_LAKITU,
    .maxHP = 12,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 40,
    .airLiftChance = 90,
    .hurricaneChance = 90,
    .spookChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 85,
    .coinReward = 2,
    .size = { 32, 38 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -11, 20 },
    .statusTextOffset = { 10, 34 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_SummonCount, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReturnHome) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim03)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, EASING_SIN_OUT)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim01)
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
            EVT_SET_CONST(LVar1, ANIM_Lakitu_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lakitu_Anim05)
            EVT_SET_CONST(LVar2, ANIM_Lakitu_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lakitu_Anim05)
            EVT_SET_CONST(LVar2, ANIM_Lakitu_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lakitu_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lakitu_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lakitu_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lakitu_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lakitu_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lakitu_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lakitu_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lakitu_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lakitu_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lakitu_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lakitu_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lakitu_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lakitu_Anim03)
            EVT_SET_CONST(LVar2, ANIM_Lakitu_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lakitu_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Lakitu_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_SpinyToss) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim03)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, -20, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim01)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SPINY_BALL, ANIM_Lakitu_Anim0B)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim12)
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim13)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -3)
        EVT_ADD(LVar1, 16)
        EVT_ADD(LVar2, 2)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.4), 10, 0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 12)
        EVT_ADD(LVar2, 0)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_SPINY_BALL, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_SPINY_BALL, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -8)
        EVT_ADD(LVar1, 40)
        EVT_ADD(LVar2, 5)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 10, 0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 30)
        EVT_ADD(LVar2, 2)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_SPINY_BALL, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_SPINY_BALL, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim15)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim01)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SPINY_BALL, ANIM_Lakitu_Anim0C)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_SPINY_BALL, SOUND_LAKITU_THROW_SPINY)
    EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_SPINY_BALL, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, 0, LVar2, 20, TRUE)
            EVT_SUB(LVar0, 30)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, 0, LVar2, 10, TRUE)
            EVT_SUB(LVar0, 20)
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, 0, LVar2, 5, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_SPINY_BALL, EVT_FLOAT(1.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, LVar1, LVar2, 20, TRUE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_SPINY_TOSS, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_THREAD
                EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_SPINY_BALL, EVT_FLOAT(1.0))
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_SUB(LVar0, 40)
                EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, 0, LVar2, 20, TRUE)
                EVT_SUB(LVar0, 30)
                EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, 0, LVar2, 10, TRUE)
                EVT_SUB(LVar0, 20)
                EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, 0, LVar2, 5, TRUE)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_END_THREAD
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

Vec3i N(SummonPos) = { NPC_DISPOSE_LOCATION };

Formation N(SpinyFormation) = {
    ACTOR_BY_POS(A(spiny), N(SummonPos), 100, 1),
};

EvtScript N(EVS_Move_SummonSpiny) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SummonEnemy, EVT_PTR(N(SpinyFormation)), FALSE)
    EVT_CALL(CopyStatusEffects, ACTOR_SELF, LVar0)
    EVT_SET(LVarB, LVar0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SPINY_BALL, ANIM_Lakitu_Anim0B)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim12)
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim13)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -3)
        EVT_ADD(LVar1, 16)
        EVT_ADD(LVar2, 2)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.4), 10, 0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 12)
        EVT_ADD(LVar2, 0)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_SPINY_BALL, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_SPINY_BALL, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_SPINY, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -8)
        EVT_ADD(LVar1, 40)
        EVT_ADD(LVar2, 5)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 10, 0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 30)
        EVT_ADD(LVar2, 2)
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_SPINY_BALL, LVar0, LVar1, LVar2)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_SPINY_BALL, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_SPINY, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim15)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Lakitu_Anim01)
    EVT_END_THREAD
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_SPINY_BALL, SOUND_LAKITU_THROW_SPINY)
    EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_SPINY_BALL, ANIM_Lakitu_Anim0C)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_SPINY_BALL, EVT_FLOAT(1.6))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 40)
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, 0, LVar2, 12, TRUE)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_SPINY, LVar0, 0, LVar2)
    EVT_SUB(LVar0, 30)
    EVT_THREAD
        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, PRT_SPINY, 0, 16, 0)
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LFlag0, FALSE)
        EVT_LOOP(12)
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_SPINY, 0, 0, LVar0)
            EVT_ADD(LVar1, 1)
            EVT_IF_GE(LVar1, 6)
                EVT_IF_EQ(LFlag0, TRUE)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SPINY, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    EVT_SET(LFlag0, FALSE)
                EVT_ELSE
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SPINY, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    EVT_SET(LFlag0, TRUE)
                EVT_END_IF
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_SPINY, EVT_FLOAT(1.3))
        EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_SPINY, LVar0, 0, LVar2, 12, TRUE)
    EVT_END_THREAD
    EVT_WAIT(1)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_SPINY_BALL, EVT_FLOAT(1.3))
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_SPINY_BALL, LVar0, 0, LVar2, 12, TRUE)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar0, 0, LVar2, 0, 0)
    EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_SPINY_BALL, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SPINY_BALL, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_SPINY, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetAnimation, LVarB, 1, ANIM_Spiny_Anim01)
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, LVarB, 1, ANIM_Spiny_Anim04)
    EVT_CALL(SetGoalToIndex, LVarB, LVarA)
    EVT_CALL(GetGoalPos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, LVarB, LVar3, LVar4, LVar5)
    EVT_IF_LT(LVar0, LVar3)
        EVT_CALL(SetActorYaw, LVarB, 0)
    EVT_ELSE
        EVT_CALL(SetActorYaw, LVarB, 180)
    EVT_END_IF
    EVT_CALL(SetActorSpeed, LVarB, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, LVarB, 0, FALSE)
    EVT_CALL(SetAnimation, LVarB, 1, ANIM_Spiny_Anim01)
    EVT_CALL(SetActorYaw, LVarB, 0)
    EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, LVarB)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_SummonCount, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_SummonCount, LVar0)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GetAvailableColumn) = {
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(GetOwnerTarget, LVar0, LVar5)
        EVT_CALL(GetIndexFromHome, LVar0, LVar5)
        EVT_MOD(LVar5, 4)
        EVT_SWITCH(LVar5)
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

EvtScript N(EVS_CountActiveSummoners) = {
    EVT_SET(LVar9, 0)
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(GetOriginalActorType, LVar0, LVar2)
        EVT_SWITCH(LVar2)
            EVT_CASE_EQ(ACTOR_TYPE_LAKITU)
                EVT_CALL(GetStatusFlags, LVar0, LVar3)
                EVT_IF_NOT_FLAG(LVar3, STATUS_FLAGS_IMMOBILIZED)
                    EVT_CALL(GetActorVar, LVar0, AVAR_SummonCount, LVar3)
                    EVT_IF_LT(LVar3, 3)
                        EVT_ADD(LVar9, 1)
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
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_SummonCount, LVar0)
    EVT_IF_GE(LVar0, 3)
        EVT_EXEC_WAIT(N(EVS_Attack_SpinyToss))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_GetAvailableColumn))
    EVT_IF_EQ(LVarA, -1)
        EVT_EXEC_WAIT(N(EVS_Attack_SpinyToss))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_CountActiveSummoners))
    EVT_SWITCH(LVar9)
        EVT_CASE_EQ(1)
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 500)
                EVT_EXEC_WAIT(N(EVS_Move_SummonSpiny))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 250)
                EVT_EXEC_WAIT(N(EVS_Move_SummonSpiny))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 150)
                EVT_EXEC_WAIT(N(EVS_Move_SummonSpiny))
                EVT_RETURN
            EVT_END_IF
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(EVS_Attack_SpinyToss))
    EVT_RETURN
    EVT_END
};
