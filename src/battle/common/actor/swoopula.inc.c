#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/Swooper.h"
#include "sprite/player.h"
#include "battle/action_cmd/stop_leech.h"

#define NAMESPACE A(swoopula)

extern s32 N(CeilingAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_IN_SnapToIndexPos  = 0, // -1 = no, 0 = yes
    AVAR_IsFlying           = 8, // false when attached to ceiling
};

enum N(ActorParams) {
    DMG_LEECH       = 2,
    MAX_LEECH_COUNT = 5,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              60,
    STATUS_KEY_POISON,             60,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             80,
    STATUS_KEY_PARALYZE,           80,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               85,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          1,
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
        .targetOffset = { 0, 29 },
        .opacity = 255,
        .idleAnimations = N(CeilingAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 1, 15 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_UPSIDE_DOWN,
    .type = ACTOR_TYPE_SWOOPULA,
    .level = ACTOR_LEVEL_SWOOPULA,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 30,
    .airLiftChance = 95,
    .hurricaneChance = 95,
    .spookChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 1,
    .size = { 31, 24 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, -20 },
    .statusTextOffset = { 10, -20 },
};

s32 N(CeilingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Swooper_Gray_Anim0C,
    STATUS_KEY_STONE,     ANIM_Swooper_Gray_Anim0B,
    STATUS_KEY_SLEEP,     ANIM_Swooper_Gray_Anim0F,
    STATUS_KEY_POISON,    ANIM_Swooper_Gray_Anim0C,
    STATUS_KEY_STOP,      ANIM_Swooper_Gray_Anim0B,
    STATUS_KEY_STATIC,    ANIM_Swooper_Gray_Anim0C,
    STATUS_KEY_PARALYZE,  ANIM_Swooper_Gray_Anim0B,
    STATUS_KEY_DIZZY,     ANIM_Swooper_Gray_Anim10,
    STATUS_KEY_FEAR,      ANIM_Swooper_Gray_Anim10,
    STATUS_END,
};

s32 N(FlyingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Swooper_Gray_Anim02,
    STATUS_KEY_STONE,     ANIM_Swooper_Gray_Anim01,
    STATUS_KEY_SLEEP,     ANIM_Swooper_Gray_Anim13,
    STATUS_KEY_POISON,    ANIM_Swooper_Gray_Anim02,
    STATUS_KEY_STOP,      ANIM_Swooper_Gray_Anim01,
    STATUS_KEY_STATIC,    ANIM_Swooper_Gray_Anim02,
    STATUS_KEY_PARALYZE,  ANIM_Swooper_Gray_Anim01,
    STATUS_KEY_DIZZY,     ANIM_Swooper_Gray_Anim14,
    STATUS_KEY_FEAR,      ANIM_Swooper_Gray_Anim14,
    STATUS_END,
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsFlying, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReturnHome) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsFlying, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim02)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, -24, 0)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_SIN_OUT)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_UPSIDE_DOWN, TRUE)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(CeilingAnims)))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim0C)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 24)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(1)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim02)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_SIN_OUT)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Flying_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim17)
            EVT_SET_CONST(LVar2, ANIM_Swooper_Gray_Anim18)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim17)
            EVT_SET_CONST(LVar2, ANIM_Swooper_Gray_Anim18)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim18)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(func_80269470)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(func_80269470)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_THREAD
                EVT_WAIT(30)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_END_THREAD
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim02)
            EVT_SET_CONST(LVar2, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(EVS_FallFromCeiling) = {
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
    EVT_IF_LE(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_UPSIDE_DOWN, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim02)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 24)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IN_SnapToIndexPos, LVarA)
    EVT_IF_EQ(LVarA, -1)
        EVT_CALL(SetHomePos, ACTOR_SELF, LVar0, 45, LVar2)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetGoalToHome, ACTOR_SELF)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
    EVT_ELSE
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 45, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
        EVT_CALL(GetIndexFromPos, ACTOR_SELF, LVarA)
        EVT_MOD(LVarA, 4)
        EVT_ADD(LVarA, 4)
        EVT_CALL(SetGoalToIndex, ACTOR_SELF, LVarA)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
        EVT_CALL(SetHomePos, ACTOR_SELF, LVarA, LVarB, LVarC)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
        EVT_CALL(SetGoalToHome, ACTOR_SELF)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
    EVT_END_IF
    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -10)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 22)
    EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(FlyingAnims)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, TRUE)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsFlying, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsFlying, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(EVS_Flying_HandleEvent))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(GetBattlePhase, LVar0)
            EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim0E)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(GetBattlePhase, LVar0)
            EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim0E)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
                EVT_EXEC_WAIT(N(EVS_FallFromCeiling))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetBattlePhase, LVar0)
            EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim17)
                EVT_SET_CONST(LVar2, ANIM_Swooper_Gray_Anim18)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim11)
                EVT_SET_CONST(LVar2, ANIM_Swooper_Gray_Anim12)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_EXEC_WAIT(N(EVS_FallFromCeiling))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetBattlePhase, LVar0)
            EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim17)
                EVT_SET_CONST(LVar2, ANIM_Swooper_Gray_Anim18)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim18)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim11)
                EVT_SET_CONST(LVar2, ANIM_Swooper_Gray_Anim12)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim12)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(func_80269470)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit_Impl)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(func_80269470)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit_Impl)
            EVT_THREAD
                EVT_WAIT(30)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_END_THREAD
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetBattlePhase, LVar0)
            EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
                EVT_WAIT(10)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim15)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim0E)
                EVT_EXEC_WAIT(EVS_Enemy_Hit)
                EVT_WAIT(10)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim0E)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_UPSIDE_DOWN, FALSE)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(FlyingAnims)))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim02)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, TRUE)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_UPSIDE_DOWN, FALSE)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -24, 0)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Swooper_Gray_Anim02)
            EVT_SET_CONST(LVar2, ANIM_Swooper_Gray_Anim15)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/SpawnEnemyDrainFX.inc.c"

EvtScript N(EVS_Flying_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim02)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim02)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
        EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, EASING_LINEAR)
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_WAIT(10)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim06)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 50)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim06)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(10.0))
            EVT_WAIT(15)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0))
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(YieldTurn)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(HIT_RESULT_HIT_STATIC)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_STATIC)
                EVT_SET(LFlag0, FALSE)
            EVT_ELSE
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_WAIT(10)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim06)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, -4, -8, -15)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim06)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 0, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_STONE)
        EVT_WAIT(10)
        EVT_LOOP(2)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim02)
            EVT_WAIT(21)
            EVT_LOOP(2)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LEECH)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.5), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_WAIT(5)
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
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, DMG_LEECH, BS_FLAGS1_NICE_HIT)
            EVT_WAIT(30)
        EVT_END_LOOP
    EVT_ELSE
        EVT_CALL(ShowMessageBox, BTL_MSG_ACTION_TIP_MASH_BUTTON, 32767)
        EVT_CALL(ShowActionHud, TRUE)
        EVT_CALL(LoadActionCommand, ACTION_COMMAND_STOP_LEECH)
        EVT_CALL(action_command_stop_leech_init)
        EVT_CALL(SetupMashMeter, 1, 30, 0, 0, 0, 0)
        EVT_WAIT(10)
        EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
        EVT_CALL(action_command_stop_leech_start, 0, 32767, 3)
        EVT_SET(LVarD, 0)
        EVT_LOOP(MAX_LEECH_COUNT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim02)
            EVT_SET(LFlag0, FALSE)
            EVT_LOOP(21)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LFlag0, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Leeching)
            EVT_LOOP(2)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LEECH)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                EVT_SET(LFlag0, FALSE)
                EVT_LOOP(1)
                    EVT_CALL(GetActionSuccessCopy, LVar1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_SET(LFlag0, TRUE)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_EQ(LFlag0, TRUE)
                    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
                EVT_SET(LFlag0, FALSE)
                EVT_LOOP(1)
                    EVT_CALL(GetActionSuccessCopy, LVar1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_SET(LFlag0, TRUE)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_EQ(LFlag0, TRUE)
                    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
                EVT_SET(LFlag0, FALSE)
                EVT_LOOP(1)
                    EVT_CALL(GetActionSuccessCopy, LVar1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_SET(LFlag0, TRUE)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_EQ(LFlag0, TRUE)
                    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
                EVT_SET(LFlag0, FALSE)
                EVT_LOOP(1)
                    EVT_CALL(GetActionSuccessCopy, LVar1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_SET(LFlag0, TRUE)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_EQ(LFlag0, TRUE)
                    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.5), EVT_FLOAT(1.0))
                EVT_SET(LFlag0, FALSE)
                EVT_LOOP(1)
                    EVT_CALL(GetActionSuccessCopy, LVar1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_SET(LFlag0, TRUE)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_EQ(LFlag0, TRUE)
                    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
                EVT_SET(LFlag0, FALSE)
                EVT_LOOP(1)
                    EVT_CALL(GetActionSuccessCopy, LVar1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_SET(LFlag0, TRUE)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_EQ(LFlag0, TRUE)
                    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
                EVT_SET(LFlag0, FALSE)
                EVT_LOOP(1)
                    EVT_CALL(GetActionSuccessCopy, LVar1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_SET(LFlag0, TRUE)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_EQ(LFlag0, TRUE)
                    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
                EVT_SET(LFlag0, FALSE)
                EVT_LOOP(1)
                    EVT_CALL(GetActionSuccessCopy, LVar1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_SET(LFlag0, TRUE)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_EQ(LFlag0, TRUE)
                    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                EVT_SET(LFlag0, FALSE)
                EVT_LOOP(1)
                    EVT_CALL(GetActionSuccessCopy, LVar1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_SET(LFlag0, TRUE)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_IF_EQ(LFlag0, TRUE)
                    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_SET(LFlag0, FALSE)
            EVT_LOOP(5)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LFlag0, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LEECH)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_SET(LFlag0, FALSE)
            EVT_LOOP(1)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LFlag0, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
            EVT_SET(LFlag0, FALSE)
            EVT_LOOP(1)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LFlag0, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
            EVT_SET(LFlag0, FALSE)
            EVT_LOOP(1)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LFlag0, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
            EVT_SET(LFlag0, FALSE)
            EVT_LOOP(1)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LFlag0, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.5), EVT_FLOAT(1.0))
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
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.6), EVT_FLOAT(1.6), EVT_FLOAT(1.0))
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
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
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
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 2, BS_FLAGS1_NICE_HIT)
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LVar3)
            EVT_IF_NE(LVar3, 0)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEART_BOUNCE)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 15)
                EVT_CALL(N(SpawnDrainHealthStartFX), LVar0, LVar1, LVar2, LVar3)
                EVT_THREAD
                    EVT_WAIT(15)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_STAR_BOUNCE_A)
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
            EVT_CALL(GetPlayerHP, LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_CALL(func_80269470)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_SET(LFlag0, FALSE)
            EVT_LOOP(30)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LFlag0, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(func_80269470)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim02)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_EXEC_WAIT(N(EVS_ReturnHome))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsFlying, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(EVS_Flying_TakeTurn))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim02)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_UPSIDE_DOWN, FALSE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 24)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_WAIT(10)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim06)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -50, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim06)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -40, EASING_LINEAR)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(10.0))
            EVT_WAIT(15)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0))
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(YieldTurn)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(HIT_RESULT_HIT_STATIC)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_STATIC)
                EVT_SET(LFlag0, FALSE)
            EVT_ELSE
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_WAIT(10)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim06)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, -4, -8, -15)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim06)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -40, EASING_LINEAR)
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 0, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_STONE)
        EVT_WAIT(10)
        EVT_LOOP(2)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim02)
            EVT_WAIT(21)
            EVT_LOOP(2)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LEECH)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.5), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LEECH)
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
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 2, BS_FLAGS1_NICE_HIT)
            EVT_WAIT(30)
        EVT_END_LOOP
    EVT_ELSE
        EVT_CALL(ShowMessageBox, BTL_MSG_ACTION_TIP_MASH_BUTTON, 32767)
        EVT_CALL(ShowActionHud, TRUE)
        EVT_CALL(LoadActionCommand, ACTION_COMMAND_STOP_LEECH)
        EVT_CALL(action_command_stop_leech_init)
        EVT_CALL(SetupMashMeter, 1, 30, 0, 0, 0, 0)
        EVT_WAIT(10)
        EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
        EVT_CALL(action_command_stop_leech_start, 0, 32767, 3)
        EVT_SET(LVarD, 0)
        EVT_LOOP(MAX_LEECH_COUNT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim02)
            EVT_SET(LFlag0, FALSE)
            EVT_LOOP(21)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LFlag0, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Leeching)
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_LEECH)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_SET(LFlag0, FALSE)
            EVT_LOOP(1)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LFlag0, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
            EVT_SET(LFlag0, FALSE)
            EVT_LOOP(1)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LFlag0, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
            EVT_SET(LFlag0, FALSE)
            EVT_LOOP(1)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LFlag0, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
            EVT_SET(LFlag0, FALSE)
            EVT_LOOP(1)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LFlag0, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.5), EVT_FLOAT(1.0))
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
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.6), EVT_FLOAT(1.6), EVT_FLOAT(1.0))
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
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
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
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, DMG_LEECH, BS_FLAGS1_NICE_HIT)
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LVar3)
            EVT_IF_NE(LVar3, 0)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEART_BOUNCE)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 15)
                EVT_CALL(N(SpawnDrainHealthStartFX), LVar0, LVar1, LVar2, LVar3)
                EVT_THREAD
                    EVT_WAIT(15)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_STAR_BOUNCE_A)
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
            EVT_CALL(GetPlayerHP, LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_CALL(func_80269470)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_SET(LFlag0, FALSE)
            EVT_LOOP(35)
                EVT_CALL(GetActionSuccessCopy, LVar1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_SET(LFlag0, TRUE)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(func_80269470)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Swooper_Gray_Anim02)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_EXEC_WAIT(N(EVS_ReturnHome))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
