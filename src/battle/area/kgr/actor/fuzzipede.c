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
        .idleAnimations = nullptr,
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
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_Floor_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_CurrentHome, AVAL_Home_Crate)
    Call(SetActorVar, ACTOR_SELF, AVAR_Taunted, false)
    Call(SetActorPos, ACTOR_SELF, 125, 33, -15)
    Call(SetHomePos, ACTOR_SELF, 125, 33, -15)
    Call(HPBarToHome, ACTOR_SELF)
    Call(SetDarknessMode, BTL_DARKNESS_MODE_1)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_Taunted, LVar0)
    IfFalse(LVar0)
        Call(SetActorVar, ACTOR_SELF, AVAR_Taunted, true)
        Call(UseBattleCamPreset, BTL_CAM_ACTOR_SIMPLE)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(SetBattleCamDist, 200)
        Call(SetBattleCamOffsetY, 10)
        Call(MoveBattleCamOver, 30)
        Wait(30)
        Call(ActorSpeak, MSG_MAC_Port_009C, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim24, ANIM_Fuzzipede_Anim04)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 30)
        Wait(30)
    EndIf
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HopOntoCrate) = {
    Call(SetHomePos, ACTOR_SELF, 125, 33, -15)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetActorSpeed, ACTOR_SELF, Float(7.0))
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim0A)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 60)
    Set(LVar1, 0)
    ExecWait(EVS_Enemy_HopToPos)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.2))
    Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_Floor_HandleEvent)))
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING | ACTOR_FLAG_UPSIDE_DOWN, false)
    Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 2, 24)
    Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -2, -10)
    Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_PRIMARY_TARGET, false)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, true)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_OFFSET, ACTOR_PART_FLAG_PRIMARY_TARGET, true)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_OFFSET, ACTOR_PART_FLAG_NO_TARGET, false)
    Call(HPBarToHome, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_HopToGround) = {
    Call(SetHomePos, ACTOR_SELF, 60, 0, 15)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetActorSpeed, ACTOR_SELF, Float(7.0))
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim0A)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    ExecWait(EVS_Enemy_HopToPos)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_Floor_HandleEvent)))
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING | ACTOR_FLAG_UPSIDE_DOWN, false)
    Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 2, 24)
    Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -2, -10)
    Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_PRIMARY_TARGET, true)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, false)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_OFFSET, ACTOR_PART_FLAG_PRIMARY_TARGET, false)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_OFFSET, ACTOR_PART_FLAG_NO_TARGET, true)
    Call(HPBarToHome, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_ClimbOntoCeiling) = {
    Call(SetHomePos, ACTOR_SELF, 30, 115, -28)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetActorSpeed, ACTOR_SELF, Float(7.0))
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim0A)
    Set(LVar0, 65)
    Set(LVar1, 0)
    Set(LVar2, -15)
    ExecWait(EVS_Enemy_HopToPos)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.2))
    Call(SetGoalPos, ACTOR_SELF, 125, 33, -15)
    Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(SetGoalPos, ACTOR_SELF, 130, 100, -28)
    Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.2))
    Call(SetGoalPos, ACTOR_SELF, 110, 109, -28)
    Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
    Call(SetGoalPos, ACTOR_SELF, 90, 117, -28)
    Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
    Call(SetGoalPos, ACTOR_SELF, 70, 120, -28)
    Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
    Call(SetGoalPos, ACTOR_SELF, 50, 125, -28)
    Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
    Call(SetGoalPos, ACTOR_SELF, 30, 130, -28)
    Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
    Thread
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Loop(10)
            AddF(LVar1, Float(-1.5))
            Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndThread
    Set(LVar0, 0)
    // flip over
    Loop(10)
        Add(LVar0, 18)
        Call(SetActorRotation, ACTOR_SELF, LVar0, 0, 0)
        Wait(1)
    EndLoop
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(HangingAnims)))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim06)
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_Ceiling_HandleEvent)))
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_UPSIDE_DOWN, true)
    Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 2, 24)
    Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 2, 8)
    Call(N(SetAbsoluteStatusOffsets), -10, -25, 10, -30)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_PRIMARY_TARGET, true)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, false)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_OFFSET, ACTOR_PART_FLAG_PRIMARY_TARGET, false)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_OFFSET, ACTOR_PART_FLAG_NO_TARGET, true)
    Call(HPBarToHome, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(HideHealthBar, ACTOR_SELF)
    // advance to next home position
    Call(GetActorVar, ACTOR_SELF, AVAR_CurrentHome, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_Home_Crate)
            Call(SetActorVar, ACTOR_SELF, AVAR_CurrentHome, AVAL_Home_Ceiling1)
        CaseEq(AVAL_Home_Ceiling1)
            Call(SetActorVar, ACTOR_SELF, AVAR_CurrentHome, AVAL_Home_Ceiling2)
        CaseEq(AVAL_Home_Ceiling2)
            Call(SetActorVar, ACTOR_SELF, AVAR_CurrentHome, AVAL_Home_Ground)
        CaseEq(AVAL_Home_Ground)
            Call(SetActorVar, ACTOR_SELF, AVAR_CurrentHome, AVAL_Home_Ceiling3)
        CaseEq(AVAL_Home_Ceiling3)
            Call(SetActorVar, ACTOR_SELF, AVAR_CurrentHome, AVAL_Home_Crate)
    EndSwitch
    // move to the current home
    Call(GetActorVar, ACTOR_SELF, AVAR_CurrentHome, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_Home_Crate)
            ExecWait(N(EVS_HopOntoCrate))
        CaseOrEq(AVAL_Home_Ceiling1)
        CaseOrEq(AVAL_Home_Ceiling2)
        CaseOrEq(AVAL_Home_Ceiling3)
            ExecWait(N(EVS_ClimbOntoCeiling))
        EndCaseGroup
        CaseEq(AVAL_Home_Ground)
            ExecWait(N(EVS_HopToGround))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Floor_HandleEvent) = {
    Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim1B)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim1E)
            SetConst(LVar2, ANIM_Fuzzipede_Anim1F)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim1E)
            SetConst(LVar2, ANIM_Fuzzipede_Anim1F)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim1F)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim1B)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim1B)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim1B)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim1B)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim08)
            ExecWait(EVS_Enemy_Knockback)
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim1B)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim1B)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim04)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim1B)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim1B)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            Call(SetActorYaw, ACTOR_SELF, 0)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim04)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_RECEIVE_BUFF)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim19)
            Call(UseBattleCamPreset, BTL_CAM_INTERRUPT)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_CeilingHit) = {
    Call(GetLastDamage, ACTOR_SELF, LVar0)
    IfLe(LVar0, 0)
        Return
    EndIf
    Call(HideHealthBar, ACTOR_SELF)
    ExecWait(N(EVS_LeaveHome))
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_Floor_HandleEvent)))
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING | ACTOR_FLAG_UPSIDE_DOWN, false)
    Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 2, 24)
    Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -2, -10)
    Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAGS_IMMOBILIZED)
        Call(SetActorVar, ACTOR_SELF, AVAR_CurrentHome, AVAL_Home_Ground)
        Call(HPBarToCurrent, ACTOR_SELF)
    Else
        ExecWait(N(EVS_ClimbOntoCeiling))
        Wait(20)
    EndIf
    Return
    End
};

EvtScript N(EVS_Ceiling_HandleEvent) = {
    Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim1C)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim1C)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_CeilingHit))
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim20)
            SetConst(LVar2, ANIM_Fuzzipede_Anim21)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(N(EVS_CeilingHit))
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim20)
            SetConst(LVar2, ANIM_Fuzzipede_Anim21)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim21)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim1B)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim08)
            ExecWait(EVS_Enemy_Knockback)
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim1B)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim1B)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim06)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim1C)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzipede_Anim1C)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_LeaveHome) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_CurrentHome, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_Home_Crate)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 60)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.2))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
        CaseEq(AVAL_Home_Ground)
            // do nothing
        CaseOrEq(AVAL_Home_Ceiling1)
        CaseOrEq(AVAL_Home_Ceiling2)
        CaseOrEq(AVAL_Home_Ceiling3)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING | ACTOR_FLAG_UPSIDE_DOWN, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 180)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.002))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(GetStatusFlags, ACTOR_SELF, LVarA)
            IfFlag(LVarA, STATUS_FLAG_SHRINK)
                Set(LVar1, 11)
            Else
                Set(LVar1, 28)
            EndIf
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Call(SetActorScale, ACTOR_SELF, Float(1.1), Float(0.8), Float(1.0))
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(1.3), Float(0.5), Float(1.0))
            Wait(1)
            Thread
                Call(SetActorScale, ACTOR_SELF, Float(1.1), Float(0.8), Float(1.0))
                Wait(1)
                Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
            EndThread
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                Set(LVar0, 180)
                Loop(8)
                    Sub(LVar0, 22)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.2))
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Attack_Leap) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    ExecWait(N(EVS_LeaveHome))
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim0A)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 50)
    Set(LVar1, 0)
    ExecWait(EVS_Enemy_HopToPos)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim12)
    Wait(10)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FUZZIPEDE_LEAP)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    Call(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim05)
            Thread
                Set(LVar0, 0)
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                Loop(20)
                    Add(LVar0, 9)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -20, 0, 5)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, -5, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, false, true, false)
            IfEq(LVarF, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(30)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Thread
                Wait(5)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
            EndThread
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
            Wait(20)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            ExecWait(N(EVS_ReturnHome))
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim05)
    Thread
        Set(LVar0, 0)
        Call(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
        Loop(20)
            Add(LVar0, 9)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.4))
    Call(JumpToGoal, ACTOR_SELF, 20, false, true, false)
    Call(SetActorScale, ACTOR_SELF, Float(1.1), Float(0.8), Float(1.0))
    Wait(1)
    Call(SetActorScale, ACTOR_SELF, Float(1.3), Float(0.5), Float(1.0))
    Wait(1)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, DMG_LEAP, BS_FLAGS1_TRIGGER_EVENTS)
    Call(SetActorScale, ACTOR_SELF, Float(1.1), Float(0.8), Float(1.0))
    Wait(1)
    Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
            Thread
                Set(LVar0, 180)
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                Loop(10)
                    Sub(LVar0, 18)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 30)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Add(LVar0, 10)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, false, true, false)
            Wait(8)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

#include "common/ItemEntityJumpToPos.inc.c"
#include "common/DisableRandomAbility.inc.c"
#include "common/StartRumbleWithParams.inc.c"
#include "common/battle/CheckPlayerCanLoseCommand.inc.c"

EvtScript N(EVS_ManageCommandLoss) = {
    Label(0)
        Call(GetActorVar, ACTOR_SELF, AVAR_CommandLossState, LVarA)
        Switch(LVarA)
            CaseEq(AVAL_LossState_Idle)
                // do nothing
            CaseEq(AVAL_LossState_KnockAway)
                Call(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
                Set(LVar2, 0)
                Sub(LVar3, 1)
                Call(N(DisableRandomAbility), LVar4, LVar5)
                Call(MakeItemEntity, LVar4, LVar1, LVar2, LVar3, ITEM_SPAWN_MODE_DECORATION, 0)
                Add(LVar1, 30)
                Call(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 20, Float(1.0))
                Add(LVar1, 20)
                Call(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 10, Float(1.0))
                Add(LVar1, 10)
                Call(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 5, Float(1.0))
                Call(SetActorVar, ACTOR_SELF, AVAR_CommandLossState, AVAL_LossState_Idle)
            CaseEq(AVAL_LossState_ShowMessage)
                Call(ShowMessageBox, LVar5, 60)
                Sub(LVar1, 150)
                Call(N(ItemEntityJumpToPos), LVar0, LVar1, LVar2, LVar3, 30, Float(1.0))
                Call(RemoveItemEntity, LVar0)
                Call(SetActorVar, ACTOR_SELF, AVAR_CommandLossState, AVAL_LossState_Done)
                Return
        EndSwitch
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Attack_DisableTackle) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    ExecWait(N(EVS_LeaveHome))
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim0A)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 80)
    Set(LVar1, 0)
    ExecWait(EVS_Enemy_HopToPos)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim12)
    Wait(30)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FUZZIPEDE_STRIKE)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    Call(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim11)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.002))
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
            IfEq(LVarF, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
            Thread
                Set(LVar0, 90)
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                Loop(6)
                    Add(LVar0, 15)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Sub(LVar0, 30)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.3))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, false, true, false)
            Thread
                Set(LVar0, 180)
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                Loop(7)
                    Add(LVar0, 25)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Sub(LVar0, 20)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.5))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 7, false, true, false)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Wait(20)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            ExecWait(N(EVS_ReturnHome))
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim11)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.002))
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar2, 1)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
    Call(SetActorScale, ACTOR_SELF, Float(1.1), Float(0.8), Float(1.0))
    Wait(1)
    Call(SetActorScale, ACTOR_SELF, Float(1.3), Float(0.5), Float(1.0))
    Wait(1)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, DMG_DISABLE, BS_FLAGS1_TRIGGER_EVENTS)
    Thread
        Call(SetActorScale, ACTOR_SELF, Float(1.1), Float(0.8), Float(1.0))
        Wait(1)
        Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
    EndThread
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Set(LFlag0, false)
            Call(GetBattleFlags, LVar0)
            IfNotFlag(LVar0, BS_FLAGS1_ATK_BLOCKED)
                Set(LFlag0, true)
            EndIf
            Call(GetLastDamage, ACTOR_PLAYER, LVar0)
            IfLe(LVar0, 0)
                Set(LFlag0, false)
            EndIf
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAG_SHRINK)
                Set(LFlag0, false)
            EndIf
            Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
            IfFlag(LVar0, STATUS_FLAG_STONE | STATUS_FLAG_RIGHT_ON)
                Set(LFlag0, false)
            EndIf
            IfEq(LFlag0, true)
                Call(SetActorVar, ACTOR_SELF, AVAR_CommandLossState, AVAL_LossState_KnockAway)
                Exec(N(EVS_ManageCommandLoss))
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
                Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar0, 40)
                Set(LVar1, 0)
                Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
                Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
                Add(LVar0, 30)
                Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
                Add(LVar0, 20)
                Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 6, false, true, false)
                Add(LVar0, 10)
                Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 4, false, true, false)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
                Wait(8)
                Label(0)
                    Call(GetActorVar, ACTOR_SELF, AVAR_CommandLossState, LVar0)
                    IfNe(LVar0, AVAL_LossState_Idle)
                        Wait(1)
                        Goto(0)
                    EndIf
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Loop(3)
                    Sub(LVar0, 10)
                    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(JumpToGoal, ACTOR_SELF, 6, false, true, false)
                EndLoop
                Wait(10)
                Call(SetActorVar, ACTOR_SELF, AVAR_CommandLossState, AVAL_LossState_ShowMessage)
                PlayEffect(EFFECT_FIREWORK, 0, LVar0, LVar1, LVar2, Float(1.0), 0, 0)
                Call(N(StartRumbleWithParams), 200, 10)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_COMMAND_LOSS)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim13)
                Wait(20)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
            Else
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
                Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar0, 40)
                Set(LVar1, 0)
                Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
                Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
                Add(LVar0, 30)
                Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
                Add(LVar0, 20)
                Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 6, false, true, false)
                Add(LVar0, 10)
                Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 4, false, true, false)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
                Wait(8)
                Wait(10)
            EndIf
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Recover) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Wait(20)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim12)
    Wait(30)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzipede_Anim04)
    Thread
        Wait(5)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEART_BOUNCE)
        Wait(30)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STAR_BOUNCE_A)
    EndThread
    Thread
        Call(FreezeBattleState, true)
        Call(HealActor, ACTOR_SELF, HEAL_AMT, false)
        Call(FreezeBattleState, false)
    EndThread
    Call(WaitForBuffDone)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_CurrentHome, LVar0)
    Switch(LVar0)
        CaseOrEq(AVAL_Home_Crate)
        CaseOrEq(AVAL_Home_Ground)
            // 50% chance to heal when HP < 35%
            Call(GetActorHP, ACTOR_SELF, LVar0)
            Call(GetEnemyMaxHP, ACTOR_SELF, LVar1)
            Mul(LVar0, 100)
            Div(LVar0, LVar1)
            IfLe(LVar0, 35)
                Call(RandInt, 1000, LVar0)
                IfLt(LVar0, 500)
                    ExecWait(N(EVS_Recover))
                    Return
                EndIf
            EndIf
        EndCaseGroup
    EndSwitch
    // 50% chance to try disabling a command, if possible
    Call(RandInt, 1000, LVar0)
    IfLt(LVar0, 500)
        ExecWait(N(EVS_Attack_Leap))
    Else
        Call(N(CheckPlayerCanLoseCommand), LVar0)
        IfEq(LVar0, 0)
            ExecWait(N(EVS_Attack_DisableTackle))
        Else
            ExecWait(N(EVS_Attack_Leap))
        EndIf
    EndIf
    Return
    End
};
