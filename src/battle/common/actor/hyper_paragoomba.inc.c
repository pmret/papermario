#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Goomba.h"
#include "sprite/npc/Paragoomba.h"

#define NAMESPACE A(hyper_paragoomba)

extern s32 N(FlyingAnims)[];
extern s32 N(LeftWingAnims)[];
extern s32 N(RightWingAnims)[];
extern s32 N(DownedAnims)[];

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_Flying_HandlePhase);
extern EvtScript N(EVS_Flying_TakeTurn);
extern EvtScript N(EVS_Attack_SkyDive);
extern EvtScript N(EVS_ReturnHome);
extern EvtScript N(EVS_KnockDown);
extern EvtScript N(EVS_KnockDown_Init);
extern EvtScript N(EVS_Downed_Idle);
extern EvtScript N(EVS_Downed_HandleEvent);
extern EvtScript N(EVS_Downed_TakeTurn);
extern EvtScript N(EVS_Attack_Headbonk);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1, // body after being downed
    PRT_FLYING          = 2, // body while flying
    PRT_DUMMY_WING_L    = 3, // temporary wing while being downed
    PRT_DUMMY_WING_R    = 4, // temporary wing while being downed
};

enum N(ActorVars) {
    AVAR_IsCharged      = 0,
    AVAR_NotFirstTurn   = 1,
};

enum N(ActorParams) {
    DMG_SKY_DIVE        = 1,
    DMG_CHARGED_DIVE    = 8,
    DMG_HEADBONK        = 1,
    DMG_CHARGED_BONK    = 8,
};

s32 N(DownedDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(FlyingDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(DownedStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              80,
    STATUS_KEY_POISON,            100,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              80,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,            100,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,             80,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
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

s32 N(FlyingStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              80,
    STATUS_KEY_POISON,             80,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             80,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,             80,
    STATUS_KEY_STOP,               90,
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
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 22 },
        .opacity = 255,
        .idleAnimations = N(DownedAnims),
        .defenseTable = N(DownedDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_FLYING,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(FlyingAnims),
        .defenseTable = N(FlyingDefense),
        .eventFlags = ACTOR_EVENT_FLAG_GROUNDABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_DUMMY_WING_L,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -16, 24 },
        .opacity = 255,
        .idleAnimations = N(LeftWingAnims),
        .defenseTable = N(DownedDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_DUMMY_WING_R,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -16, 24 },
        .opacity = 255,
        .idleAnimations = N(RightWingAnims),
        .defenseTable = N(DownedDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_HYPER_PARAGOOMBA,
    .level = ACTOR_LEVEL_HYPER_PARAGOOMBA,
    .maxHP = 7,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(FlyingStatusTable),
    .escapeChance = 50,
    .airLiftChance = 95,
    .hurricaneChance = 95,
    .spookChance = 80,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 36, 26 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(ChargedFlyingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Paragoomba_Hyper_Miss,
    STATUS_KEY_STONE,     ANIM_Paragoomba_Hyper_Still,
    STATUS_KEY_SLEEP,     ANIM_Paragoomba_Hyper_Sleep,
    STATUS_KEY_POISON,    ANIM_Paragoomba_Hyper_Miss,
    STATUS_KEY_STOP,      ANIM_Paragoomba_Hyper_Still,
    STATUS_KEY_STATIC,    ANIM_Paragoomba_Hyper_Miss,
    STATUS_KEY_PARALYZE,  ANIM_Paragoomba_Hyper_Still,
    STATUS_KEY_DIZZY,     ANIM_Paragoomba_Hyper_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Paragoomba_Hyper_Dizzy,
    STATUS_END,
};

EvtScript N(EVS_Init) = {
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_Flying_HandlePhase)))
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_Flying_TakeTurn)))
    Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, FALSE)
    Return
    End
};

EvtScript N(EVS_Flying_HandlePhase) = {
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

EvtScript N(EVS_Attack_ChargedDive) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetActorVar, ACTOR_SELF, AVAR_IsCharged, LVar0)
    IfEq(LVar0, 0)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 20)
        Wait(20)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_POWER_UP)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 10)
        PlayEffect(EFFECT_ENERGY_IN_OUT, 6, LVar0, LVar1, LVar2, Float(1.0), 45, 0)
        Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Miss)
        Wait(30)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 20)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 20, FALSE, FALSE, FALSE)
        Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, TRUE)
        Call(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, Ref(N(ChargedFlyingAnims)))
        Call(EnableActorGlow, ACTOR_SELF, TRUE)
        Call(SetPartEventBits, ACTOR_SELF, PRT_FLYING, ACTOR_EVENT_FLAG_ATTACK_CHARGED, TRUE)
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
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_PREDIVE)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_DIVE)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, -60)
            Thread
                Set(LVar0, -60)
                Loop(60)
                    Add(LVar0, 19)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.01))
            Call(SetActorSpeed, ACTOR_SELF, Float(15.0))
            Call(JumpToGoal, ACTOR_SELF, 0, FALSE, FALSE, FALSE)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_01)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -60, 0, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.3))
            Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(AddGoalPos, ACTOR_SELF, -200, 0, 0)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Wait(20)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(EnableActorGlow, ACTOR_SELF, FALSE)
            Call(SetPartEventBits, ACTOR_SELF, PRT_FLYING, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            Thread
                Set(LVar0, 0)
                Loop(30)
                    Add(LVar0, 24)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EndThread
            Call(SetActorPos, ACTOR_SELF, 300, 0, 0)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(AddGoalPos, ACTOR_SELF, 30, 0, 0)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(AddActorDecoration, ACTOR_SELF, PRT_FLYING, 0, ACTOR_DECORATION_SWEAT)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(FlyToGoal, ACTOR_SELF, 0, 1, EASING_SIN_OUT)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Idle)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_FLYING, 0)
            Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, FALSE)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, Ref(N(FlyingAnims)))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, -70)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.01))
    Call(SetActorSpeed, ACTOR_SELF, Float(15.0))
    Call(JumpToGoal, ACTOR_SELF, 0, FALSE, FALSE, FALSE)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_CHARGED_DIVE, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                Set(LVar0, -70)
                Loop(60)
                    Add(LVar0, 18)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EndThread
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Set(LVar1, 0)
            Sub(LVar0, 70)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, FALSE, FALSE, FALSE)
            Sub(LVar0, 60)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
            Wait(20)
            Call(YieldTurn)
            Call(EnableActorGlow, ACTOR_SELF, FALSE)
            Call(SetPartEventBits, ACTOR_SELF, PRT_FLYING, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Run)
            ExecWait(N(EVS_ReturnHome))
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, FALSE)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, Ref(N(FlyingAnims)))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Flying_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
        ExecWait(N(EVS_Attack_SkyDive))
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_IsCharged, LVar0)
    IfEq(LVar0, 1)
        ExecWait(N(EVS_Attack_ChargedDive))
        Return
    EndIf
    Call(GetBattleVar, BTL_VAR_HyperSync, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(GetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, LVar0)
            IfEq(LVar0, 0)
                Call(RandInt, 1000, LVar0)
                IfLt(LVar0, 750)
                    Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                    ExecWait(N(EVS_Attack_ChargedDive))
                Else
                    Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                    ExecWait(N(EVS_Attack_SkyDive))
                EndIf
            Else
                Call(RandInt, 1000, LVar0)
                IfLt(LVar0, 500)
                    Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                    ExecWait(N(EVS_Attack_ChargedDive))
                Else
                    Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                    ExecWait(N(EVS_Attack_SkyDive))
                EndIf
            EndIf
        CaseEq(1)
            ExecWait(N(EVS_Attack_SkyDive))
        CaseEq(2)
            ExecWait(N(EVS_Attack_ChargedDive))
    EndSwitch
    Return
    End
};

s32 N(FlyingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Paragoomba_Hyper_Idle,
    STATUS_KEY_STONE,     ANIM_Paragoomba_Hyper_Still,
    STATUS_KEY_SLEEP,     ANIM_Paragoomba_Hyper_Sleep,
    STATUS_KEY_POISON,    ANIM_Paragoomba_Hyper_Idle,
    STATUS_KEY_STOP,      ANIM_Paragoomba_Hyper_Still,
    STATUS_KEY_STATIC,    ANIM_Paragoomba_Hyper_Idle,
    STATUS_KEY_PARALYZE,  ANIM_Paragoomba_Hyper_Still,
    STATUS_KEY_DIZZY,     ANIM_Paragoomba_Hyper_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Paragoomba_Hyper_Dizzy,
    STATUS_END,
};

s32 N(FlyingShuffleAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Paragoomba_Hyper_Run,
    STATUS_KEY_STONE,     ANIM_Paragoomba_Hyper_Still,
    STATUS_KEY_SLEEP,     ANIM_Paragoomba_Hyper_Sleep,
    STATUS_KEY_POISON,    ANIM_Paragoomba_Hyper_Idle,
    STATUS_KEY_STOP,      ANIM_Paragoomba_Hyper_Still,
    STATUS_KEY_STATIC,    ANIM_Paragoomba_Hyper_Run,
    STATUS_KEY_PARALYZE,  ANIM_Paragoomba_Hyper_Still,
    STATUS_KEY_DIZZY,     ANIM_Paragoomba_Hyper_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Paragoomba_Hyper_Dizzy,
    STATUS_END,
};

s32 N(LeftWingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Paragoomba_Hyper_LWingStill,
    STATUS_END,
};

s32 N(RightWingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Paragoomba_Hyper_RWingStill,
    STATUS_END,
};

EvtScript N(EVS_Flying_Init_Unused) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_Attack_SkyDive)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(10)
        Call(RandInt, 80, LVar0)
        Add(LVar0, 80)
        Loop(LVar0)
            Label(0)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    Wait(1)
                    Goto(0)
                EndIf
            Wait(1)
        EndLoop
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Call(SetActorIdleSpeed, ACTOR_SELF, Float(0.6))
        Call(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, Ref(N(FlyingShuffleAnims)))
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleFlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
        Loop(20)
            Label(1)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    Wait(1)
                    Goto(1)
                EndIf
            Wait(1)
        EndLoop
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Sub(LVar0, 5)
        Call(SetActorIdleSpeed, ACTOR_SELF, Float(0.6))
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleFlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
        Call(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, Ref(N(FlyingAnims)))
        Loop(40)
            Label(2)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    Wait(1)
                    Goto(2)
                EndIf
            Wait(1)
        EndLoop
        Goto(10)
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(ResetAllActorSounds, ACTOR_SELF)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(7.0))
    Call(FlyToGoal, ACTOR_SELF, 0, 1, EASING_SIN_OUT)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Idle)
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
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hyper_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Call(GetBattlePhase, LVar0)
            IfEq(LVar0, PHASE_FIRST_STRIKE)
                Call(GetEncounterTrigger, LVar0)
                IfEq(LVar0, ENCOUNTER_TRIGGER_HAMMER)
                    ExecWait(N(EVS_KnockDown))
                EndIf
            EndIf
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hyper_BurnHurt)
            SetConst(LVar2, ANIM_Paragoomba_Hyper_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hyper_BurnHurt)
            SetConst(LVar2, ANIM_Paragoomba_Hyper_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hyper_BurnStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_FALL_TRIGGER)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hyper_Hurt)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_KnockDown))
        CaseEq(EVENT_15)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hyper_BurnHurt)
            SetConst(LVar2, ANIM_Paragoomba_Hyper_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(N(EVS_KnockDown))
        CaseEq(EVENT_SHOCK_HIT)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(EnableActorGlow, ACTOR_SELF, FALSE)
            Call(SetPartEventBits, ACTOR_SELF, PRT_FLYING, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, FALSE)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, Ref(N(FlyingAnims)))
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hyper_Electrocute)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hyper_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Dizzy)
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(EnableActorGlow, ACTOR_SELF, FALSE)
            Call(SetPartEventBits, ACTOR_SELF, PRT_FLYING, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, FALSE)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, Ref(N(FlyingAnims)))
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hyper_Electrocute)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hyper_HurtStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_STAR_BEAM)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsCharged, LVar0)
            IfEq(LVar0, 1)
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                Call(EnableActorGlow, ACTOR_SELF, FALSE)
                Call(SetPartEventBits, ACTOR_SELF, PRT_FLYING, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
                Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, FALSE)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, Ref(N(FlyingAnims)))
            EndIf
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hyper_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hyper_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hyper_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hyper_HurtStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
            Call(SetActorPos, ACTOR_SELF, 20, 0, 0)
            Call(HPBarToCurrent, ACTOR_SELF)
        CaseEq(EVENT_END_FIRST_STRIKE)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Run)
            ExecWait(N(EVS_ReturnHome))
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hyper_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hyper_Run)
            SetConst(LVar2, ANIM_Paragoomba_Hyper_Hurt)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hyper_Run)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_Paragoomba_Hyper_Hurt)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_SkyDive) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Run)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(FlyToGoal, ACTOR_SELF, 0, -4, EASING_LINEAR)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_66)
            Call(SetBattleCamZoom, 300)
            Call(BattleCamTargetActor, ACTOR_SELF)
            Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_PREDIVE)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Dive)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_DIVE)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            Call(SetGoalToTarget, ACTOR_SELF)
            Sub(LVar0, 80)
            Set(LVar1, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Dive)
            Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_QUADRATIC_OUT)
            Thread
                Loop(4)
                    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_FLY)
                    Wait(4)
                EndLoop
            EndThread
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Miss)
            Call(AddActorDecoration, ACTOR_SELF, PRT_FLYING, 0, ACTOR_DECORATION_SWEAT)
            Call(SetAnimationRate, ACTOR_SELF, PRT_FLYING, Float(3.0))
            Wait(10)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(10)
            Call(SetAnimationRate, ACTOR_SELF, PRT_FLYING, Float(1.0))
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(YieldTurn)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Run)
            Call(SetActorYaw, ACTOR_SELF, 180)
            ExecWait(N(EVS_ReturnHome))
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_FLYING, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
        CaseDefault
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_66)
            Call(SetBattleCamZoom, 300)
            Call(BattleCamTargetActor, ACTOR_SELF)
            Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_PREDIVE)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Dive)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_DIVE)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Dive)
            Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
    EndSwitch
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_SKY_DIVE, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, 50, 10, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Run)
            Call(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Wait(5)
            Call(YieldTurn)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Run)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(EVS_KnockDown) = {
    Call(HideHealthBar, ACTOR_SELF)
    Call(SetPartFlags, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_NO_TARGET)
    Call(SetPartFlags, ACTOR_SELF, PRT_DUMMY_WING_L, ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)
    Call(SetPartFlags, ACTOR_SELF, PRT_DUMMY_WING_R, ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)
    Call(SetPartFlags, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_PRIMARY_TARGET)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetPartPos, ACTOR_SELF, PRT_DUMMY_WING_L, LVar0, LVar1, LVar2)
    Call(SetPartDispOffset, ACTOR_SELF, PRT_DUMMY_WING_L, -9, 7, -2)
    Call(SetPartPos, ACTOR_SELF, PRT_DUMMY_WING_R, LVar0, LVar1, LVar2)
    Call(SetPartDispOffset, ACTOR_SELF, PRT_DUMMY_WING_R, 11, 7, -2)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    IfEq(LVar0, EVENT_15)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_BurnStill)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Hurt)
    EndIf
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_FALL_QUICK, 0)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    Call(N(StartRumbleWithParams), 100, 10)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(0.3))
    EndThread
    Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
    Call(GetLastEvent, ACTOR_SELF, LVar3)
    IfEq(LVar3, EVENT_15)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Hurt)
        Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        Add(LVar4, 10)
        Add(LVar5, 5)
        PlayEffect(EFFECT_SMOKE_BURST, 0, LVar3, LVar4, LVar5, Float(1.0), 10, 0)
    EndIf
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    Loop(10)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WING_L, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WING_R, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        Wait(1)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WING_L, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WING_R, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        Wait(1)
    EndLoop
    Call(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WING_L, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WING_R, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(GetIndexFromHome, ACTOR_SELF, LVar0)
    Mod(LVar0, 4)
    Call(SetGoalToIndex, ACTOR_SELF, LVar0)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
    Call(SetStatusTable, ACTOR_SELF, Ref(N(DownedStatusTable)))
    Call(SetActorType, ACTOR_SELF, ACTOR_TYPE_HYPER_GOOMBA)
    ExecWait(N(EVS_KnockDown_Init))
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TYPE_CHANGED, TRUE)
    Call(HPBarToHome, ACTOR_SELF)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Return
    End
};

s32 N(DownedChargedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Goomba_Hyper_Sleep,
    STATUS_KEY_STONE,     ANIM_Goomba_Hyper_Still,
    STATUS_KEY_SLEEP,     ANIM_Goomba_Hyper_Sleep,
    STATUS_KEY_POISON,    ANIM_Goomba_Hyper_Sleep,
    STATUS_KEY_STOP,      ANIM_Goomba_Hyper_Still,
    STATUS_KEY_STATIC,    ANIM_Goomba_Hyper_Sleep,
    STATUS_KEY_PARALYZE,  ANIM_Goomba_Hyper_Still,
    STATUS_KEY_DIZZY,     ANIM_Goomba_Hyper_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Goomba_Hyper_Dizzy,
    STATUS_END,
};

EvtScript N(EVS_Downed_Init) = {
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Downed_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_Downed_HandleEvent)))
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_Downed_TakeTurn)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, FALSE)
    Return
    End
};

EvtScript N(EVS_KnockDown_Init) = {
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Downed_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_Downed_HandleEvent)))
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_Downed_TakeTurn)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(GetActorVar, ACTOR_SELF, AVAR_IsCharged, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, FALSE)
        CaseEq(1)
            Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, TRUE)
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, TRUE)
            Call(SetPartEventBits, ACTOR_SELF, PRT_FLYING, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
    EndSwitch
    Call(GetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, LVar0)
    Call(SetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, LVar0)
    Return
    End
};

// everything below is copied from Hyper Goomba actor

EvtScript N(EVS_HandlePhase) = {
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
        CaseEq(PHASE_ENEMY_BEGIN)
        CaseEq(PHASE_ENEMY_END)
            Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_None)
            Call(SetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, 1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Downed_Move_Charge) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetActorVar, ACTOR_SELF, AVAR_IsCharged, LVar0)
    IfEq(LVar0, 0)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 20)
        Wait(20)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_POWER_UP)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 10)
        PlayEffect(EFFECT_ENERGY_IN_OUT, 6, LVar0, LVar1, LVar2, Float(1.0), 45, 0)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Run)
        Wait(30)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 20)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
        Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GOOMBA_STEP)
        Call(N(StartRumbleWithParams), 128, 10)
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(0.5))
        EndThread
        Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, 1)
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DownedChargedAnims)))
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
        Call(EnableActorGlow, ACTOR_SELF, TRUE)
        Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, TRUE)
        Wait(2)
        Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
        Call(UseIdleAnimation, ACTOR_SELF, TRUE)
        Return
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Loop(20)
        Call(SetActorDispOffset, ACTOR_SELF, 1, 0, 0)
        Wait(1)
        Call(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
        Wait(1)
    EndLoop
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
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
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 80)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_ACTOR_HURT, 0)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -200, 0, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.01))
            Call(SetActorSpeed, ACTOR_SELF, Float(15.0))
            Call(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorPos, ACTOR_SELF, LVar0, 0, LVar2)
            Wait(20)
            Call(EnableActorGlow, ACTOR_SELF, FALSE)
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            Call(YieldTurn)
            Call(SetActorPos, ACTOR_SELF, 300, 0, 0)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Run)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetGoalToHome, ACTOR_SELF)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, 0)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DownedAnims)))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_ACTOR_HURT, 0)
    Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 80)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.01))
    Call(SetActorSpeed, ACTOR_SELF, Float(15.0))
    Call(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_CHARGED_BONK, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
                Set(LVar0, 80)
                Loop(60)
                    Add(LVar0, 18)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EndThread
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Set(LVar1, 0)
            Sub(LVar0, 50)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 30, FALSE, TRUE, FALSE)
            Sub(LVar0, 40)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Wait(10)
            Call(EnableActorGlow, ACTOR_SELF, FALSE)
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            Call(YieldTurn)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Run)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetGoalToHome, ACTOR_SELF)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, 0)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DownedAnims)))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Downed_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
        ExecWait(N(EVS_Attack_Headbonk))
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_IsCharged, LVar0)
    IfEq(LVar0, 1)
        ExecWait(N(EVS_Downed_Move_Charge))
        Return
    EndIf
    Call(GetBattleVar, BTL_VAR_HyperSync, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(GetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, LVar0)
            IfEq(LVar0, 0)
                Call(RandInt, 1000, LVar0)
                IfLt(LVar0, 750)
                    Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                    ExecWait(N(EVS_Downed_Move_Charge))
                Else
                    Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                    ExecWait(N(EVS_Attack_Headbonk))
                EndIf
            Else
                Call(RandInt, 1000, LVar0)
                IfLt(LVar0, 500)
                    Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                    ExecWait(N(EVS_Downed_Move_Charge))
                Else
                    Call(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                    ExecWait(N(EVS_Attack_Headbonk))
                EndIf
            EndIf
        CaseEq(1)
            ExecWait(N(EVS_Attack_Headbonk))
        CaseEq(2)
            ExecWait(N(EVS_Downed_Move_Charge))
    EndSwitch
    Return
    End
};

s32 N(DownedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Goomba_Hyper_Idle,
    STATUS_KEY_STONE,     ANIM_Goomba_Hyper_Still,
    STATUS_KEY_SLEEP,     ANIM_Goomba_Hyper_Sleep,
    STATUS_KEY_POISON,    ANIM_Goomba_Hyper_Idle,
    STATUS_KEY_STOP,      ANIM_Goomba_Hyper_Still,
    STATUS_KEY_STATIC,    ANIM_Goomba_Hyper_Idle,
    STATUS_KEY_PARALYZE,  ANIM_Goomba_Hyper_Still,
    STATUS_KEY_DIZZY,     ANIM_Goomba_Hyper_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Goomba_Hyper_Dizzy,
    STATUS_END,
};

s32 N(DownedShuffleAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Goomba_Hyper_Run,
    STATUS_KEY_STONE,     ANIM_Goomba_Hyper_Still,
    STATUS_KEY_SLEEP,     ANIM_Goomba_Hyper_Sleep,
    STATUS_KEY_POISON,    ANIM_Goomba_Hyper_Idle,
    STATUS_KEY_STOP,      ANIM_Goomba_Hyper_Still,
    STATUS_KEY_STATIC,    ANIM_Goomba_Hyper_Run,
    STATUS_KEY_PARALYZE,  ANIM_Goomba_Hyper_Still,
    STATUS_KEY_DIZZY,     ANIM_Goomba_Hyper_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Goomba_Hyper_Dizzy,
    STATUS_END,
};

EvtScript N(EVS_Downed_Init_Unused) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_Attack_Headbonk)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Downed_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_Downed_HandleEvent)))
    Return
    End
};

EvtScript N(EVS_Downed_Idle) = {
    Label(10)
    Call(RandInt, 80, LVar0)
    Add(LVar0, 80)
    Loop(LVar0)
        Label(0)
        Call(GetStatusFlags, ACTOR_SELF, LVar1)
        IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED)
            Wait(1)
            Goto(0)
        EndIf
        Wait(1)
    EndLoop
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 5)
    Call(SetActorIdleSpeed, ACTOR_SELF, Float(1.0))
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DownedShuffleAnims)))
    Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(IdleRunToGoal, ACTOR_SELF, 0)
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DownedAnims)))
    Loop(20)
        Label(1)
        Call(GetStatusFlags, ACTOR_SELF, LVar1)
        IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED)
            Wait(1)
            Goto(1)
        EndIf
        Wait(1)
    EndLoop
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 5)
    Call(SetActorIdleSpeed, ACTOR_SELF, Float(1.0))
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DownedShuffleAnims)))
    Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(IdleRunToGoal, ACTOR_SELF, 0)
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DownedAnims)))
    Loop(80)
        Label(2)
        Call(GetStatusFlags, ACTOR_SELF, LVar1)
        IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED)
            Wait(1)
            Goto(2)
        EndIf
        Wait(1)
    EndLoop
    Goto(10)
    Return
    End
};

EvtScript N(EVS_Downed_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Hurt)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_BurnHurt)
            SetConst(LVar2, ANIM_Goomba_Hyper_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_BurnHurt)
            SetConst(LVar2, ANIM_Goomba_Hyper_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_BurnStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Dead)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(EnableActorGlow, ACTOR_SELF, FALSE)
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, 0)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DownedAnims)))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Electrocute)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(2.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Dizzy)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
            Wait(5)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        CaseEq(EVENT_SHOCK_DEATH)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(EnableActorGlow, ACTOR_SELF, FALSE)
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, 0)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DownedAnims)))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Electrocute)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Dead)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_STAR_BEAM)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsCharged, LVar0)
            IfEq(LVar0, 1)
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                Call(EnableActorGlow, ACTOR_SELF, FALSE)
                Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
                Call(SetActorVar, ACTOR_SELF, AVAR_IsCharged, 0)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DownedAnims)))
            EndIf
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Dead)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_END_FIRST_STRIKE)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(2.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Run)
            SetConst(LVar2, ANIM_Goomba_Hyper_Hurt)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Run)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goomba_Hyper_Hurt)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

#include "common/CalculateArcsinDeg.inc.c"

EvtScript N(EVS_Attack_Headbonk) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Run)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
    Call(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    Wait(5)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Midair)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 10)
            Set(LVar1, 10)
            Add(LVar2, 3)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.2))
            Thread
                Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar0)
                Set(LVar0, 0)
                Loop(16)
                    Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    Call(N(CalculateArcsinDeg), LVar1, LVar2, LVar4, LVar5, LVar0)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Set(LVar1, LVar4)
                    Set(LVar2, LVar5)
                    Set(LVar3, LVar6)
                    Wait(1)
                EndLoop
            EndThread
            Thread
                Wait(6)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Midair)
            EndThread
            Call(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Sleep)
            Call(SetActorScale, ACTOR_SELF, Float(1.1), Float(0.8), Float(1.0))
            Call(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(1.3), Float(0.5), Float(1.0))
            Call(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
            Call(SetActorDispOffset, ACTOR_SELF, 0, 7, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Hurt)
            Wait(5)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(5)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Midair)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 20)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(2.0))
            Thread
                Wait(4)
                Set(LVar0, 180)
                Loop(4)
                    Sub(LVar0, 45)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Midair)
            EndThread
            Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Dizzy)
            Wait(5)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(2.0))
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
            Call(SetActorYaw, ACTOR_SELF, 0)
            Wait(5)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
        CaseDefault
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.2))
            Thread
                Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar0)
                Set(LVar0, 0)
                Loop(16)
                    Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    Call(N(CalculateArcsinDeg), LVar1, LVar2, LVar4, LVar5, LVar0)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Set(LVar1, LVar4)
                    Set(LVar2, LVar5)
                    Set(LVar3, LVar6)
                    Wait(1)
                EndLoop
            EndThread
            Thread
                Wait(6)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Midair)
            EndThread
            Call(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Tense)
            Call(SetActorScale, ACTOR_SELF, Float(1.1), Float(0.8), Float(1.0))
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(1.3), Float(0.5), Float(1.0))
            Wait(1)
    EndSwitch
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_HEADBONK, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetActorScale, ACTOR_SELF, Float(1.1), Float(0.8), Float(1.0))
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
            Wait(1)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Add(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
            Wait(3)
            Call(YieldTurn)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(2.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};
