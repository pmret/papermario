#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Cleft.h"

#define NAMESPACE A(hyper_cleft)

extern s32 N(UprightAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_TakeTurn_Unused);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_TryGettingUp);
extern EvtScript N(EVS_Attack_Tackle);

enum N(ActorPartIDs) {
    PRT_MAIN    = 1,
};

enum N(ActorVars) {
    AVAR_State                  = 0,
    AVAL_State_Normal           = 0,
    AVAL_State_Toppled          = 1,
    AVAL_State_Charged          = 2,
    AVAL_State_ChargedToppled   = 3,
    AVAR_ToppleTurns            = 1,
    AVAR_NotFirstTurn           = 2,
};

enum N(ActorParams) {
    DMG_TACKLE      = 3,
    DMG_CHARGED     = 8,
};

s32 N(UprightDefenseTable)[] = {
    ELEMENT_NORMAL,   3,
    ELEMENT_FIRE,    99,
    ELEMENT_END,
};

s32 N(ToppledDefenseTable)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_FIRE,    99,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              40,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              50,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           50,
    STATUS_KEY_SHRINK,             90,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
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
        .targetOffset = { 0, 22 },
        .opacity = 255,
        .idleAnimations = N(UprightAnims),
        .defenseTable = N(UprightDefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_HYPER_CLEFT,
    .level = ACTOR_LEVEL_HYPER_CLEFT,
    .maxHP = 4,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 70,
    .airLiftChance = 30,
    .hurricaneChance = 30,
    .spookChance = 30,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 95,
    .coinReward = 2,
    .size = { 44, 36 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(HyperAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Cleft_Hyper_Anim04,
    STATUS_KEY_STONE,     ANIM_Cleft_Hyper_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Cleft_Hyper_Anim0C,
    STATUS_KEY_POISON,    ANIM_Cleft_Hyper_Anim04,
    STATUS_KEY_STOP,      ANIM_Cleft_Hyper_Anim00,
    STATUS_KEY_STATIC,    ANIM_Cleft_Hyper_Anim04,
    STATUS_KEY_PARALYZE,  ANIM_Cleft_Hyper_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Cleft_Hyper_Anim0E,
    STATUS_KEY_FEAR,      ANIM_Cleft_Hyper_Anim0E,
    STATUS_END,
};

EvtScript N(EVS_Init) = {
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
    Call(SetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, FALSE)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
        CaseEq(PHASE_ENEMY_BEGIN)
        CaseEq(PHASE_ENEMY_END)
            Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_None)
            Call(SetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, TRUE)
    EndSwitch
    Return
    End
};

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(EVS_Move_Charge) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    IfEq(LVar0, AVAL_State_Normal)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 20)
        Wait(20)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_POWER_UP)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 10)
        PlayEffect(EFFECT_ENERGY_IN_OUT, 6, LVar0, LVar1, LVar2, Float(1.0), 45, 0)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim04)
        Wait(30)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 20)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
        Call(N(StartRumbleWithParams), 200, 10)
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.5))
        EndThread
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HYPER_CLEFT_LAND)
        PlayEffect(EFFECT_LANDING_DUST, 4, LVar0, LVar1, LVar2, 0, 0)
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
        EndThread
        Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Charged)
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(HyperAnims)))
        Call(EnableActorGlow, ACTOR_SELF, TRUE)
        Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, TRUE)
        Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
        Call(UseIdleAnimation, ACTOR_SELF, TRUE)
        Return
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(MoveBattleCamOver, 30)
    Loop(20)
        Call(SetActorDispOffset, ACTOR_SELF, 1, 0, 0)
        Wait(1)
        Call(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
        Wait(1)
    EndLoop
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HYPER_CLEFT_CHARGE)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 3, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Thread
                Loop(0)
                    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    Add(LVar0, 30)
                    Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
                    IfGt(LVar0, LVar3)
                        BreakLoop
                    EndIf
                    Wait(1)
                EndLoop
                Call(UseBattleCamPreset, BTL_CAM_PRESET_01)
                IfEq(LVarA, HIT_RESULT_LUCKY)
                    Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EndIf
                Wait(15)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EndThread
            Thread
                Loop(30)
                    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    PlayEffect(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0, 0)
                    Wait(1)
                EndLoop
            EndThread
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim11)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -200, 0, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(12.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Wait(15)
            Call(EnableActorGlow, ACTOR_SELF, FALSE)
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            Call(YieldTurn)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetActorPos, ACTOR_SELF, 300, 0, 0)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim07)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim02)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(UprightAnims)))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Thread
        Loop(25)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_WALKING_DUST, 2, LVar0, LVar1, LVar2, 0, 0, 0)
            Wait(1)
        EndLoop
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim11)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(12.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_CHARGED, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                Set(LVar0, 0)
                Loop(60)
                    Add(LVar0, 18)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EndThread
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 50)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 30, FALSE, TRUE, FALSE)
            Sub(LVar0, 40)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Wait(20)
            Call(YieldTurn)
            Call(EnableActorGlow, ACTOR_SELF, FALSE)
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim07)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetGoalToHome, ACTOR_SELF)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim02)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(UprightAnims)))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
        ExecWait(N(EVS_Attack_Tackle))
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    IfEq(LVar0, AVAL_State_Toppled)
        ExecWait(N(EVS_TryGettingUp))
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    IfEq(LVar0, AVAL_State_Charged)
        ExecWait(N(EVS_Move_Charge))
        Return
    EndIf
    Call(GetBattleVar, BTL_VAR_HyperSync, LVar0)
    Switch(LVar0)
        CaseEq(BTL_VAL_HyperSync_None)
            Call(GetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, LVar0)
            IfEq(LVar0, 0)
                Call(RandInt, 1000, LVar0)
                IfLt(LVar0, 750)
                    Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                    ExecWait(N(EVS_Move_Charge))
                Else
                    Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                    ExecWait(N(EVS_Attack_Tackle))
                EndIf
            Else
                Call(RandInt, 1000, LVar0)
                IfLt(LVar0, 500)
                    Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                    ExecWait(N(EVS_Move_Charge))
                Else
                    Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                    ExecWait(N(EVS_Attack_Tackle))
                EndIf
            EndIf
        CaseEq(BTL_VAL_HyperSync_Done)
            ExecWait(N(EVS_Attack_Tackle))
            Return
        CaseEq(BTL_VAL_HyperSync_Active)
            ExecWait(N(EVS_Move_Charge))
            Return
    EndSwitch
    Return
    End
};

// everything below this point is copied from the basic Cleft actor

s32 N(UprightAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Cleft_Hyper_Anim02,
    STATUS_KEY_STONE,     ANIM_Cleft_Hyper_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Cleft_Hyper_Anim0C,
    STATUS_KEY_POISON,    ANIM_Cleft_Hyper_Anim02,
    STATUS_KEY_STOP,      ANIM_Cleft_Hyper_Anim00,
    STATUS_KEY_STATIC,    ANIM_Cleft_Hyper_Anim02,
    STATUS_KEY_PARALYZE,  ANIM_Cleft_Hyper_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Cleft_Hyper_Anim0E,
    STATUS_KEY_FEAR,      ANIM_Cleft_Hyper_Anim0E,
    STATUS_END,
};

s32 N(ToppledAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Cleft_Hyper_Anim05,
    STATUS_KEY_STONE,     ANIM_Cleft_Hyper_Anim01,
    STATUS_KEY_SLEEP,     ANIM_Cleft_Hyper_Anim0D,
    STATUS_KEY_POISON,    ANIM_Cleft_Hyper_Anim05,
    STATUS_KEY_STOP,      ANIM_Cleft_Hyper_Anim01,
    STATUS_KEY_STATIC,    ANIM_Cleft_Hyper_Anim05,
    STATUS_KEY_PARALYZE,  ANIM_Cleft_Hyper_Anim01,
    STATUS_KEY_DIZZY,     ANIM_Cleft_Hyper_Anim0F,
    STATUS_KEY_FEAR,      ANIM_Cleft_Hyper_Anim0F,
    STATUS_END,
};

EvtScript N(EVS_Init_Unused) = {
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn_Unused)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

#include "common/SetSpinSmashable.inc.c"

EvtScript N(EVS_FlipOver) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Toppled)
    Call(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 2)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim07)
    Call(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
    Thread
        Set(LVar0, 0)
        Loop(5)
            Add(LVar0, -36)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.3))
    Sub(LVar1, 6)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    Call(N(StartRumbleWithParams), 200, 10)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
    EndThread
    PlayEffect(EFFECT_SMOKE_IMPACT, 0, LVar0, LVar1, LVar2, 40, 8, Float(0.0), 20, 0)
    Call(SetActorPos, ACTOR_SELF, LVar0, 0, LVar2)
    Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim03)
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledAnims)))
    Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledDefenseTable)))
    Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 15)
    Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -7)
    Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, FALSE)
    Call(N(SetSpinSmashable), FALSE)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
    Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(EnableActorGlow, ACTOR_SELF, FALSE)
    Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            Call(GetLastElement, LVar0)
            Switch(LVar0)
                CaseFlag(DAMAGE_TYPE_BLAST)
                    ExecWait(N(EVS_FlipOver))
                CaseDefault
                    Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
                    IfEq(LVar0, AVAL_State_Toppled)
                        SetConst(LVar1, ANIM_Cleft_Hyper_Anim09)
                    Else
                        SetConst(LVar1, ANIM_Cleft_Hyper_Anim08)
                    EndIf
                    SetConst(LVar0, PRT_MAIN)
                    ExecWait(EVS_Enemy_Hit)
            EndSwitch
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            Call(GetLastElement, LVar0)
            Switch(LVar0)
                CaseFlag(DAMAGE_TYPE_BLAST)
                    ExecWait(N(EVS_FlipOver))
                CaseDefault
                    Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION, TRUE)
                    Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
                    IfEq(LVar0, AVAL_State_Toppled)
                        SetConst(LVar0, PRT_MAIN)
                        SetConst(LVar1, ANIM_Cleft_Hyper_Anim09)
                        SetConst(LVar2, -1)
                        ExecWait(EVS_Enemy_BurnHit)
                    Else
                        SetConst(LVar0, PRT_MAIN)
                        SetConst(LVar1, ANIM_Cleft_Hyper_Anim08)
                        SetConst(LVar2, -1)
                        ExecWait(EVS_Enemy_BurnHit)
                    EndIf
                    Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION, FALSE)
            EndSwitch
        CaseEq(EVENT_BURN_DEATH)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            IfEq(LVar0, AVAL_State_Toppled)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim09)
                SetConst(LVar2, -1)
                ExecWait(EVS_Enemy_BurnHit)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim09)
                ExecWait(EVS_Enemy_Death)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim08)
                SetConst(LVar2, -1)
                ExecWait(EVS_Enemy_BurnHit)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim08)
                ExecWait(EVS_Enemy_Death)
            EndIf
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            IfEq(LVar0, AVAL_State_Toppled)
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim09)
            Else
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim08)
            EndIf
            SetConst(LVar0, PRT_MAIN)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            IfEq(LVar0, AVAL_State_Toppled)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim09)
                ExecWait(EVS_Enemy_SpinSmashHit)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim09)
                ExecWait(EVS_Enemy_Death)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim08)
                ExecWait(EVS_Enemy_SpinSmashHit)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim08)
                ExecWait(EVS_Enemy_Death)
            EndIf
            Return
        CaseEq(EVENT_SHOCK_HIT)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(EnableActorGlow, ACTOR_SELF, FALSE)
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(UprightAnims)))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Cleft_Hyper_Anim08)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Cleft_Hyper_Anim08)
            ExecWait(EVS_Enemy_Knockback)
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Cleft_Hyper_Anim07)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        CaseEq(EVENT_SHOCK_DEATH)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(EnableActorGlow, ACTOR_SELF, FALSE)
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(UprightAnims)))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Cleft_Hyper_Anim08)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Cleft_Hyper_Anim08)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_STAR_BEAM)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            IfEq(LVar0, AVAL_State_Charged)
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                Call(EnableActorGlow, ACTOR_SELF, FALSE)
                Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
                Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(UprightAnims)))
            EndIf
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            IfEq(LVar0, AVAL_State_Toppled)
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim03)
            Else
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim02)
            EndIf
            SetConst(LVar0, PRT_MAIN)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_SPIKE_TAUNT)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim18)
            EndIf
            Wait(10)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(GetStatusFlags, ACTOR_SELF, LVar3)
            IfFlag(LVar3, STATUS_FLAG_SHRINK)
                Add(LVar0, -3)
                Add(LVar1, 10)
            Else
                Add(LVar0, -8)
                Add(LVar1, 27)
            EndIf
            PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 20, 0)
            Wait(20)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            IfEq(LVar0, AVAL_State_Toppled)
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim03)
            Else
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim02)
            EndIf
            SetConst(LVar0, PRT_MAIN)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            IfEq(LVar0, AVAL_State_Toppled)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim09)
                ExecWait(EVS_Enemy_Hit)
                Wait(10)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim09)
                ExecWait(EVS_Enemy_Death)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim08)
                ExecWait(EVS_Enemy_Hit)
                Wait(10)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim08)
                ExecWait(EVS_Enemy_Death)
            EndIf
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            IfEq(LVar0, AVAL_State_Normal)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim02)
                ExecWait(EVS_Enemy_Recover)
            EndIf
        CaseEq(EVENT_SCARE_AWAY)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            IfEq(LVar0, AVAL_State_Toppled)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim03)
                ExecWait(EVS_Enemy_NoDamageHit)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim07)
                SetConst(LVar2, ANIM_Cleft_Hyper_Anim08)
                ExecWait(EVS_Enemy_ScareAway)
                Return
            EndIf
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Cleft_Hyper_Anim0F)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            IfEq(LVar0, AVAL_State_Toppled)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim0F)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Hyper_Anim08)
            EndIf
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TryGettingUp) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
    Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(3.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim03)
    Wait(20)
    Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim05)
    Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
    Call(GetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
    IfGt(LVar0, 0)
        Sub(LVar0, 1)
        Call(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
    Else
        Call(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim03)
        Thread
            Wait(3)
            Loop(5)
                Add(LVar0, 36)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                Wait(1)
            EndLoop
        EndThread
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Sub(LVar1, 6)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(1.3))
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
        Call(N(StartRumbleWithParams), 200, 10)
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
        EndThread
        Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        Call(SetActorPos, ACTOR_SELF, LVar0, 0, LVar2)
        Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_Normal)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim02)
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(UprightAnims)))
        Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(UprightDefenseTable)))
        Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 22)
        Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -10)
        Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, TRUE)
        Wait(1)
        Call(N(SetSpinSmashable), TRUE)
        Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, FALSE)
    EndIf
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_Tackle) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(MoveBattleCamOver, 30)
    Thread
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        Wait(10)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        Wait(5)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim10)
    Wait(10)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim11)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 50, 0, -5)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim00)
    Wait(8)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CLEFT_TACKLE)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 3, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Thread
                    Wait(10)
                    Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EndThread
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim11)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 100)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, 45)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim08)
            Wait(15)
            Wait(8)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim07)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim02)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim11)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 20)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_TACKLE, BS_FLAGS1_TRIGGER_EVENTS)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim02)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 15)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(2.4))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim02)
            Wait(5)
            Call(YieldTurn)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim07)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetGoalToHome, ACTOR_SELF)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Hyper_Anim02)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn_Unused) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    IfEq(LVar0, AVAL_State_Toppled)
        ExecWait(N(EVS_TryGettingUp))
    Else
        ExecWait(N(EVS_Attack_Tackle))
    EndIf
    Return
    End
};
