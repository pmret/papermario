#include "../area.h"
#include "sprite/npc/Fuzzipede.h"

#define NAMESPACE A(fuzzipede)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Floor_HandleEvent);
extern EvtScript N(EVS_Ceiling_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_LeaveHome);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_OFFSET      = 2,
};

enum N(ActorVars) {
    AVAR_CurrentHome        = 0,
    AVAL_Home_Crate             = 0,
    AVAL_Home_Ceiling1          = 1,
    AVAL_Home_Ceiling2          = 2,
    AVAL_Home_Ground            = 3,
    AVAL_Home_Ceiling3          = 4,
    AVAR_CommandLossState   = 1,
    AVAL_LossState_Idle         = 0,
    AVAL_LossState_KnockAway    = 1,
    AVAL_LossState_ShowMessage  = 2,
    AVAL_LossState_Done         = 3,
    AVAR_Taunted            = 2,
};

enum N(ActorParams) {
    DMG_LEAP            = 3,
    DMG_DISABLE         = 3,
    HEAL_AMT            = 4,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Fuzzipede_Anim04,
    STATUS_KEY_STONE,     ANIM_Fuzzipede_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Fuzzipede_Anim29,
    STATUS_KEY_POISON,    ANIM_Fuzzipede_Anim04,
    STATUS_KEY_STOP,      ANIM_Fuzzipede_Anim00,
    STATUS_KEY_STATIC,    ANIM_Fuzzipede_Anim04,
    STATUS_KEY_PARALYZE,  ANIM_Fuzzipede_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Fuzzipede_Anim26,
    STATUS_KEY_FEAR,      ANIM_Fuzzipede_Anim26,
    STATUS_END,
};

s32 N(HangingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Fuzzipede_Anim06,
    STATUS_KEY_STONE,     ANIM_Fuzzipede_Anim02,
    STATUS_KEY_SLEEP,     ANIM_Fuzzipede_Anim2A,
    STATUS_KEY_POISON,    ANIM_Fuzzipede_Anim06,
    STATUS_KEY_STOP,      ANIM_Fuzzipede_Anim02,
    STATUS_KEY_STATIC,    ANIM_Fuzzipede_Anim06,
    STATUS_KEY_PARALYZE,  ANIM_Fuzzipede_Anim02,
    STATUS_KEY_DIZZY,     ANIM_Fuzzipede_Anim27,
    STATUS_KEY_FEAR,      ANIM_Fuzzipede_Anim27,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              50,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              50,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             50,
    STATUS_KEY_STOP,               75,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -2, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET | ACTOR_PART_FLAG_SKIP_MOVEMENT_ALLOC,
        .index = PRT_OFFSET,
        .posOffset = { 0, 40, 0 },
        .targetOffset = { 2, -16 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -2, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_FUZZIPEDE,
    .level = ACTOR_LEVEL_FUZZIPEDE,
    .maxHP = 20,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 26, 38 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_Floor_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CurrentHome, AVAL_Home_Crate)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Taunted, FALSE)
    EVT_CALL(SetActorPos, ACTOR_SELF, 125, 33, -15)
    EVT_CALL(SetHomePos, ACTOR_SELF, 125, 33, -15)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetDarknessMode, BTL_DARKNESS_MODE_1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Taunted, LVar0)
    EVT_IF_FALSE(LVar0)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Taunted, TRUE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_08)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(SetBattleCamZoom, 200)
        EVT_CALL(SetBattleCamOffsetZ, 10)
        EVT_CALL(MoveBattleCamOver, 30)
        EVT_WAIT(30)
        EVT_CALL(ActorSpeak, MSG_MAC_Port_009C, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim24, ANIM_Fuzzipede_Anim04)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 30)
        EVT_WAIT(30)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HopOntoCrate) = {
    EVT_CALL(SetHomePos, ACTOR_SELF, 125, 33, -15)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim0A)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 60)
    EVT_SET(LVar1, 0)
    EVT_EXEC_WAIT(EVS_Enemy_HopToPos)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_Floor_HandleEvent)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING | ACTOR_FLAG_UPSIDE_DOWN, FALSE)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 2, 24)
    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -2, -10)
    EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_OFFSET, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_OFFSET, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HopToGround) = {
    EVT_CALL(SetHomePos, ACTOR_SELF, 60, 0, 15)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim0A)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_EXEC_WAIT(EVS_Enemy_HopToPos)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_Floor_HandleEvent)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING | ACTOR_FLAG_UPSIDE_DOWN, FALSE)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 2, 24)
    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -2, -10)
    EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_OFFSET, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_OFFSET, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ClimbOntoCeiling) = {
    EVT_CALL(SetHomePos, ACTOR_SELF, 30, 115, -28)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim0A)
    EVT_SET(LVar0, 65)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, -15)
    EVT_EXEC_WAIT(EVS_Enemy_HopToPos)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 125, 33, -15)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, 130, 100, -28)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 110, 109, -28)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, 90, 117, -28)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, 70, 120, -28)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, 50, 125, -28)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, 30, 130, -28)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_LOOP(10)
            EVT_ADDF(LVar1, EVT_FLOAT(-1.5))
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_SET(LVar0, 0)
    // flip over
    EVT_LOOP(10)
        EVT_ADD(LVar0, 18)
        EVT_CALL(SetActorRotation, ACTOR_SELF, LVar0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(HangingAnims)))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim06)
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_Ceiling_HandleEvent)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_UPSIDE_DOWN, TRUE)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 2, 24)
    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 2, 8)
    EVT_CALL(N(SetAbsoluteStatusOffsets), -10, -25, 10, -30)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_OFFSET, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_OFFSET, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReturnHome) = {
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    // advance to next home position
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_CurrentHome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_Home_Crate)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CurrentHome, AVAL_Home_Ceiling1)
        EVT_CASE_EQ(AVAL_Home_Ceiling1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CurrentHome, AVAL_Home_Ceiling2)
        EVT_CASE_EQ(AVAL_Home_Ceiling2)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CurrentHome, AVAL_Home_Ground)
        EVT_CASE_EQ(AVAL_Home_Ground)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CurrentHome, AVAL_Home_Ceiling3)
        EVT_CASE_EQ(AVAL_Home_Ceiling3)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CurrentHome, AVAL_Home_Crate)
    EVT_END_SWITCH
    // move to the current home
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_CurrentHome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_Home_Crate)
            EVT_EXEC_WAIT(N(EVS_HopOntoCrate))
        EVT_CASE_OR_EQ(AVAL_Home_Ceiling1)
        EVT_CASE_OR_EQ(AVAL_Home_Ceiling2)
        EVT_CASE_OR_EQ(AVAL_Home_Ceiling3)
            EVT_EXEC_WAIT(N(EVS_ClimbOntoCeiling))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(AVAL_Home_Ground)
            EVT_EXEC_WAIT(N(EVS_HopToGround))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Floor_HandleEvent) = {
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim1E)
            EVT_SET_CONST(LVar2, ANIM_Fuzzipede_Anim1F)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim1E)
            EVT_SET_CONST(LVar2, ANIM_Fuzzipede_Anim1F)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim1F)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_RECEIVE_BUFF)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim19)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_01)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CeilingHit) = {
    EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
    EVT_IF_LE(LVar0, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_EXEC_WAIT(N(EVS_LeaveHome))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_Floor_HandleEvent)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING | ACTOR_FLAG_UPSIDE_DOWN, FALSE)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 2, 24)
    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -2, -10)
    EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAGS_IMMOBILIZED)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CurrentHome, AVAL_Home_Ground)
        EVT_CALL(HPBarToCurrent, ACTOR_SELF)
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_ClimbOntoCeiling))
        EVT_WAIT(20)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Ceiling_HandleEvent) = {
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim1C)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim1C)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(EVS_CeilingHit))
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim20)
            EVT_SET_CONST(LVar2, ANIM_Fuzzipede_Anim21)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(N(EVS_CeilingHit))
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim20)
            EVT_SET_CONST(LVar2, ANIM_Fuzzipede_Anim21)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim21)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim1B)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim1C)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Fuzzipede_Anim1C)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LeaveHome) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_CurrentHome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(AVAL_Home_Crate)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 60)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(AVAL_Home_Ground)
            // do nothing
        EVT_CASE_OR_EQ(AVAL_Home_Ceiling1)
        EVT_CASE_OR_EQ(AVAL_Home_Ceiling2)
        EVT_CASE_OR_EQ(AVAL_Home_Ceiling3)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING | ACTOR_FLAG_UPSIDE_DOWN, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 180)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.002))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
            EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
                EVT_SET(LVar1, 11)
            EVT_ELSE
                EVT_SET(LVar1, 28)
            EVT_END_IF
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_THREAD
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
                EVT_WAIT(1)
                EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_END_THREAD
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                EVT_SET(LVar0, 180)
                EVT_LOOP(8)
                    EVT_SUB(LVar0, 22)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_Leap) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_EXEC_WAIT(N(EVS_LeaveHome))
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim0A)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_SET(LVar1, 0)
    EVT_EXEC_WAIT(EVS_Enemy_HopToPos)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim12)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_FUZZIPEDE_LEAP)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim05)
            EVT_THREAD
                EVT_SET(LVar0, 0)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                EVT_LOOP(20)
                    EVT_ADD(LVar0, 9)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -20, 0, 5)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, -5, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarF, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(30)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_THREAD
                EVT_WAIT(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
            EVT_END_THREAD
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim05)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
        EVT_LOOP(20)
            EVT_ADD(LVar0, 9)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
    EVT_WAIT(1)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
    EVT_WAIT(1)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, DMG_LEAP, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
    EVT_WAIT(1)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
            EVT_THREAD
                EVT_SET(LVar0, 180)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                EVT_LOOP(10)
                    EVT_SUB(LVar0, 18)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 30)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_WAIT(8)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/ItemEntityJumpToPos.inc.c"
#include "common/DisableRandomAbility.inc.c"
#include "common/StartRumbleWithParams.inc.c"
#include "common/battle/CheckPlayerCanLoseCommand.inc.c"

EvtScript N(EVS_ManageCommandLoss) = {
    EVT_LABEL(0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_CommandLossState, LVarA)
        EVT_SWITCH(LVarA)
            EVT_CASE_EQ(AVAL_LossState_Idle)
                // do nothing
            EVT_CASE_EQ(AVAL_LossState_KnockAway)
                EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
                EVT_SET(LVar2, 0)
                EVT_SUB(LVar3, 1)
                EVT_CALL(N(DisableRandomAbility), LVar4, LVar5)
                EVT_CALL(MakeItemEntity, LVar4, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_DECORATION, 0)
                EVT_ADD(LVar1, 30)
                EVT_CALL(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 20, EVT_FLOAT(1.0))
                EVT_ADD(LVar1, 20)
                EVT_CALL(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 10, EVT_FLOAT(1.0))
                EVT_ADD(LVar1, 10)
                EVT_CALL(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 5, EVT_FLOAT(1.0))
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CommandLossState, AVAL_LossState_Idle)
            EVT_CASE_EQ(AVAL_LossState_ShowMessage)
                EVT_CALL(ShowMessageBox, LVar5, 60)
                EVT_SUB(LVar1, 150)
                EVT_CALL(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 30, EVT_FLOAT(1.0))
                EVT_CALL(RemoveItemEntity, LVar0)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CommandLossState, AVAL_LossState_Done)
                EVT_RETURN
        EVT_END_SWITCH
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_DisableTackle) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_EXEC_WAIT(N(EVS_LeaveHome))
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim0A)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 80)
    EVT_SET(LVar1, 0)
    EVT_EXEC_WAIT(EVS_Enemy_HopToPos)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim12)
    EVT_WAIT(30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_FUZZIPEDE_STRIKE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim11)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.002))
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarF, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
            EVT_THREAD
                EVT_SET(LVar0, 90)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                EVT_LOOP(6)
                    EVT_ADD(LVar0, 15)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.3))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_THREAD
                EVT_SET(LVar0, 180)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                EVT_LOOP(7)
                    EVT_ADD(LVar0, 25)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 7, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim11)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.002))
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 1)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
    EVT_WAIT(1)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
    EVT_WAIT(1)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, DMG_DISABLE, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_THREAD
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_SET(LFlag0, FALSE)
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_NOT_FLAG(LVar0, BS_FLAGS1_ATK_BLOCKED)
                EVT_SET(LFlag0, TRUE)
            EVT_END_IF
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LVar0)
            EVT_IF_LE(LVar0, 0)
                EVT_SET(LFlag0, FALSE)
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_SET(LFlag0, FALSE)
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_STONE | STATUS_FLAG_RIGHT_ON)
                EVT_SET(LFlag0, FALSE)
            EVT_END_IF
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CommandLossState, AVAL_LossState_KnockAway)
                EVT_EXEC(N(EVS_ManageCommandLoss))
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
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
                EVT_ADD(LVar0, 10)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
                EVT_WAIT(8)
                EVT_LABEL(0)
                    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_CommandLossState, LVar0)
                    EVT_IF_NE(LVar0, AVAL_LossState_Idle)
                        EVT_WAIT(1)
                        EVT_GOTO(0)
                    EVT_END_IF
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_LOOP(3)
                    EVT_SUB(LVar0, 10)
                    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
                EVT_END_LOOP
                EVT_WAIT(10)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CommandLossState, AVAL_LossState_ShowMessage)
                EVT_PLAY_EFFECT(EFFECT_FIREWORK, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 0, 0)
                EVT_CALL(N(StartRumbleWithParams), 200, 10)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_COMMAND_LOSS)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim13)
                EVT_WAIT(20)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
            EVT_ELSE
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
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
                EVT_ADD(LVar0, 10)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
                EVT_WAIT(8)
                EVT_WAIT(10)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Recover) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim12)
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEART_BOUNCE)
        EVT_WAIT(30)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_STAR_BOUNCE_A)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(FreezeBattleState, TRUE)
        EVT_CALL(HealActor, ACTOR_SELF, HEAL_AMT, FALSE)
        EVT_CALL(FreezeBattleState, FALSE)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_CurrentHome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(AVAL_Home_Crate)
        EVT_CASE_OR_EQ(AVAL_Home_Ground)
            // 50% chance to heal when HP < 35%
            EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
            EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
            EVT_MUL(LVar0, 100)
            EVT_DIV(LVar0, LVar1)
            EVT_IF_LE(LVar0, 35)
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LT(LVar0, 500)
                    EVT_EXEC_WAIT(N(EVS_Recover))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    // 50% chance to try disabling a command, if possible
    EVT_CALL(RandInt, 1000, LVar0)
    EVT_IF_LT(LVar0, 500)
        EVT_EXEC_WAIT(N(EVS_Attack_Leap))
    EVT_ELSE
        EVT_CALL(N(CheckPlayerCanLoseCommand), LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_EXEC_WAIT(N(EVS_Attack_DisableTackle))
        EVT_ELSE
            EVT_EXEC_WAIT(N(EVS_Attack_Leap))
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
