#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/player.h"
#include "sprite/npc/Fuzzy.h"
#include "battle/action_cmd/stop_leech.h"

#define NAMESPACE A(jungle_fuzzy)

extern s32 N(DefaultAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern Formation N(SummonFormation);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_Generation     = 0,
};

enum N(ActorParams) {
    DMG_LEECH       = 2,
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
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             70,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
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

ActorPartBlueprint  N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 20 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_JUNGLE_FUZZY,
    .level = ACTOR_LEVEL_JUNGLE_FUZZY,
    .maxHP = 7,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 30,
    .airLiftChance = 85,
    .hurricaneChance = 80,
    .spookChance = 75,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 33, 28 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Fuzzy_Jungle_Idle,
    STATUS_KEY_STONE,     ANIM_Fuzzy_Jungle_Still,
    STATUS_KEY_SLEEP,     ANIM_Fuzzy_Jungle_Sleep,
    STATUS_KEY_POISON,    ANIM_Fuzzy_Jungle_Idle,
    STATUS_KEY_STOP,      ANIM_Fuzzy_Jungle_Still,
    STATUS_KEY_STATIC,    ANIM_Fuzzy_Jungle_Idle,
    STATUS_KEY_PARALYZE,  ANIM_Fuzzy_Jungle_Still,
    STATUS_KEY_DIZZY,     ANIM_Fuzzy_Jungle_Stunned,
    STATUS_KEY_FEAR,      ANIM_Fuzzy_Jungle_Stunned,
    STATUS_END,
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_Generation, 0)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            Call(GetLastElement, LVar0)
            IfFlag(LVar0, DAMAGE_TYPE_SHOCK)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Fuzzy_Jungle_HurtShock)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Fuzzy_Jungle_Hurt)
            EndIf
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Jungle_Burn)
            SetConst(LVar2, ANIM_Fuzzy_Jungle_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Jungle_Burn)
            SetConst(LVar2, ANIM_Fuzzy_Jungle_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Jungle_BurnStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Jungle_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Jungle_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Jungle_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            Call(func_80269470)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Jungle_HurtShock)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Jungle_HurtShock)
            ExecWait(EVS_Enemy_Knockback)
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Jungle_Run)
            ExecWait(EVS_Enemy_HopHome)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        CaseEq(EVENT_SHOCK_DEATH)
            Call(func_80269470)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Jungle_HurtShock)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Jungle_HurtShock)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Jungle_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            Call(GetLastElement, LVar0)
            IfFlag(LVar0, DAMAGE_TYPE_SHOCK)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Fuzzy_Jungle_HurtShock)
                ExecWait(EVS_Enemy_Hit)
                Wait(10)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Fuzzy_Jungle_HurtShock)
                ExecWait(EVS_Enemy_Death)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Fuzzy_Jungle_Hurt)
                ExecWait(EVS_Enemy_Hit)
                Wait(10)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Fuzzy_Jungle_Hurt)
                ExecWait(EVS_Enemy_Death)
            EndIf
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Jungle_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Jungle_Run)
            SetConst(LVar2, ANIM_Fuzzy_Jungle_Anim09)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Jungle_Run)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Jungle_Run)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Fuzzy_Jungle_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Move_Divide) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamDist, 330)
    Call(SetBattleCamOffsetY, 30)
    Call(MoveBattleCamOver, 20)
    Wait(20)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(UseBattleCamPreset, BTL_CAM_INTERRUPT)
    Thread
        Wait(30)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FUZZY_RUMBLE)
        Wait(30)
        Loop(4)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FUZZY_SHAKE)
            Wait(11)
        EndLoop
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FUZZY_DIVIDE)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jungle_Anim0D)
    Wait(130)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jungle_Walk)
    Call(SummonEnemy, Ref(N(SummonFormation)), FALSE)
    Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    Call(SetActorPos, LVar0, LVar1, LVar2, LVar3)
    Call(SetGoalToIndex, LVar0, LVarA)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Thread
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jungle_Walk)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(1.4))
        Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
        Call(SetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
        Call(JumpToGoal, ACTOR_SELF, 14, FALSE, TRUE, FALSE)
    EndThread
    Wait(1)
    Call(SetAnimation, LVar0, 1, ANIM_Fuzzy_Jungle_Walk)
    Call(SetActorJumpGravity, LVar0, Float(1.4))
    Call(JumpToGoal, LVar0, 14, FALSE, TRUE, FALSE)
    Call(GetActorPos, LVar0, LVar1, LVar2, LVar3)
    Call(ForceHomePos, LVar0, LVar1, LVar2, LVar3)
    Call(HPBarToHome, LVar0)
    Call(SetAnimation, LVar0, 1, ANIM_Fuzzy_Jungle_Idle)
    Call(GetActorVar, ACTOR_SELF, AVAR_Generation, LVar1)
    Switch(LVar1)
        CaseEq(0)
            Call(SetActorVar, LVar0, AVAR_Generation, 1)
        CaseEq(1)
            Call(SetActorVar, LVar0, AVAR_Generation, 2)
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

#include "common/SpawnEnemyDrainFX.inc.c"

EvtScript N(EVS_Attack_Leech) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 50)
        Set(LVar1, 0)
        Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Goto(100)
    EndIf
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jungle_Run)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 50)
    Set(LVar1, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    ExecWait(EVS_Enemy_HopToPos)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jungle_Idle)
    Label(100)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jungle_Leech)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 9, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
    Wait(5)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 5)
            Set(LVar1, 0)
            Sub(LVar2, 5)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(3.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jungle_Jump)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 11, FALSE, TRUE, FALSE)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jungle_Anim09)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 20)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(3.0))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 15)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(3.0))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Wait(4)
            Wait(5)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(5)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jungle_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            ExecWait(EVS_Enemy_HopToPos)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
        CaseEq(HIT_RESULT_HIT_STATIC)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAG_STATIC)
                Set(LFlag0, FALSE)
            Else
                Set(LFlag0, TRUE)
            EndIf
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, -3, -12, -15)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(3.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jungle_Jump)
    Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    IfEq(LFlag0, TRUE)
        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 0, BS_FLAGS1_TRIGGER_EVENTS)
        Return
    EndIf
    Call(GetStatusFlags, ACTOR_PLAYER, LVar1)
    IfFlag(LVar1, STATUS_FLAG_STONE)
        Wait(10)
        Loop(2)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LEECH)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jungle_Bite)
            Wait(21)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jungle_Still)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 330)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LEECH)
            Call(SetActorDispOffset, ACTOR_SELF, -3, -2, 0)
            Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(0.9), Float(1.2), Float(1.0))
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(0.8), Float(1.3), Float(1.0))
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(0.7), Float(1.4), Float(1.0))
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(0.7), Float(1.5), Float(1.0))
            Wait(2)
            Call(SetActorScale, ACTOR_SELF, Float(0.6), Float(1.6), Float(1.0))
            Wait(10)
            Wait(2)
            Call(EnemyDamageTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, DMG_LEECH, BS_FLAGS1_NICE_HIT)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jungle_Jump)
            Wait(30)
        EndLoop
    Else
        Call(ShowMessageBox, BTL_MSG_ACTION_TIP_MASH_BUTTON, 32767)
        Call(ShowActionHud, TRUE)
        Call(LoadActionCommand, ACTION_COMMAND_STOP_LEECH)
        Call(action_command_stop_leech_init)
        Call(SetupMashMeter, 1, 23, 0, 0, 0, 0)
        Wait(10)
        Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
        Call(action_command_stop_leech_start, 0, 32767, 3)
        Set(LVarD, 0)
        Loop(5)
            Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
            Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Leeching)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LEECH)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jungle_Bite)
            Set(LFlag0, FALSE)
            Loop(21)
                Call(GetActionSuccessCopy, LVar1)
                IfEq(LVar1, 1)
                    Set(LFlag0, TRUE)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            IfEq(LFlag0, TRUE)
                Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                BreakLoop
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jungle_Still)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 330)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LEECH)
            Call(SetActorDispOffset, ACTOR_SELF, -3, -2, 0)
            Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
            Set(LFlag0, FALSE)
            Loop(1)
                Call(GetActionSuccessCopy, LVar1)
                IfEq(LVar1, 1)
                    Set(LFlag0, TRUE)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            IfEq(LFlag0, TRUE)
                Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                BreakLoop
            EndIf
            Call(SetActorScale, ACTOR_SELF, Float(0.9), Float(1.2), Float(1.0))
            Set(LFlag0, FALSE)
            Loop(1)
                Call(GetActionSuccessCopy, LVar1)
                IfEq(LVar1, 1)
                    Set(LFlag0, TRUE)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            IfEq(LFlag0, TRUE)
                Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                BreakLoop
            EndIf
            Call(SetActorScale, ACTOR_SELF, Float(0.8), Float(1.3), Float(1.0))
            Set(LFlag0, FALSE)
            Loop(1)
                Call(GetActionSuccessCopy, LVar1)
                IfEq(LVar1, 1)
                    Set(LFlag0, TRUE)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            IfEq(LFlag0, TRUE)
                Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                BreakLoop
            EndIf
            Call(SetActorScale, ACTOR_SELF, Float(0.7), Float(1.4), Float(1.0))
            Set(LFlag0, FALSE)
            Loop(1)
                Call(GetActionSuccessCopy, LVar1)
                IfEq(LVar1, 1)
                    Set(LFlag0, TRUE)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            IfEq(LFlag0, TRUE)
                Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                BreakLoop
            EndIf
            Call(SetActorScale, ACTOR_SELF, Float(0.7), Float(1.5), Float(1.0))
            Set(LFlag0, FALSE)
            Loop(2)
                Call(GetActionSuccessCopy, LVar1)
                IfEq(LVar1, 1)
                    Set(LFlag0, TRUE)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            IfEq(LFlag0, TRUE)
                Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                BreakLoop
            EndIf
            Call(SetActorScale, ACTOR_SELF, Float(0.6), Float(1.6), Float(1.0))
            Set(LFlag0, FALSE)
            Loop(10)
                Call(GetActionSuccessCopy, LVar1)
                IfEq(LVar1, 1)
                    Set(LFlag0, TRUE)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            IfEq(LFlag0, TRUE)
                Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                BreakLoop
            EndIf
            Set(LFlag0, FALSE)
            Loop(2)
                Call(GetActionSuccessCopy, LVar1)
                IfEq(LVar1, 1)
                    Set(LFlag0, TRUE)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            IfEq(LFlag0, TRUE)
                Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                BreakLoop
            EndIf
            Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            Call(EnemyDamageTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, DMG_LEECH, BS_FLAGS1_NICE_HIT)
            Call(GetLastDamage, ACTOR_PLAYER, LVar3)
            IfNe(LVar3, 0)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEART_BOUNCE)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar1, 10)
                Call(N(SpawnDrainHealthStartFX), LVar0, LVar1, LVar2, LVar3)
                Thread
                    Wait(15)
                    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STAR_BOUNCE_A)
                    Call(N(SpawnDrainHealthContinueFX), LVar0, LVar1, LVar2, LVar3)
                EndThread
                Add(LVar0, 20)
                Add(LVar1, 20)
                PlayEffect(EFFECT_RECOVER, 0, LVar0, LVar1, LVar2, LVar3, 0)
                Call(GetActorHP, ACTOR_SELF, LVar0)
                Add(LVar0, LVar3)
                Call(SetEnemyHP, ACTOR_SELF, LVar0)
            Else
                Add(LVarD, 1)
                IfGt(LVarD, 1)
                    Call(func_80269470)
                    BreakLoop
                EndIf
            EndIf
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
            Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jungle_Jump)
            Call(GetPlayerHP, LVar1)
            IfEq(LVar1, 0)
                Call(func_80269470)
                BreakLoop
            EndIf
            Set(LFlag0, FALSE)
            Loop(35)
                Call(GetActionSuccessCopy, LVar1)
                IfEq(LVar1, 1)
                    Set(LFlag0, TRUE)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            IfEq(LFlag0, TRUE)
                BreakLoop
            EndIf
        EndLoop
        Call(func_80269470)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        Call(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
        Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jungle_Jump)
    EndIf
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jungle_Idle)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Thread
        Call(SetActorScale, ACTOR_SELF, Float(1.6), Float(0.6), Float(1.0))
        Call(SetActorRotationOffset, ACTOR_SELF, 0, 10, 0)
        Wait(1)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 330)
        Wait(1)
        Call(SetActorScale, ACTOR_SELF, Float(0.7), Float(1.5), Float(1.0))
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 300)
        Wait(1)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 270)
        Wait(1)
        Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(0.7), Float(1.0))
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 240)
        Wait(1)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 210)
        Wait(1)
        Call(SetActorScale, ACTOR_SELF, Float(0.7), Float(1.4), Float(1.0))
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 180)
        Wait(2)
        Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(0.7), Float(1.0))
        Wait(2)
        Call(SetActorScale, ACTOR_SELF, Float(1.2), Float(0.5), Float(1.0))
    EndThread
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 40)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    Call(SetActorScale, ACTOR_SELF, Float(1.4), Float(0.2), Float(1.0))
    Wait(1)
    Thread
        Wait(1)
        Call(SetActorScale, ACTOR_SELF, Float(1.2), Float(0.5), Float(1.0))
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 150)
        Wait(1)
        Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 120)
        Wait(1)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 90)
        Wait(1)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 60)
        Wait(1)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 30)
        Wait(1)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EndThread
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    Wait(5)
    Call(YieldTurn)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jungle_Run)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    ExecWait(EVS_Enemy_HopToPos)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Fuzzy_Jungle_Idle)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_GetAvailableColumn) = {
    Set(LFlag1, FALSE)
    Set(LFlag2, FALSE)
    Set(LFlag3, FALSE)
    Set(LFlag4, FALSE)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar5)
        Call(GetIndexFromHome, LVar0, LVar5)
        Mod(LVar5, 4)
        Switch(LVar5)
            CaseEq(0)
                Set(LFlag1, TRUE)
            CaseEq(1)
                Set(LFlag2, TRUE)
            CaseEq(2)
                Set(LFlag3, TRUE)
            CaseEq(3)
                Set(LFlag4, TRUE)
        EndSwitch
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Set(LVarA, -1)
    Set(LVarB, -1)
    Call(GetIndexFromHome, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(0)
            IfEq(LFlag2, FALSE)
                Set(LVarA, 1)
            EndIf
        CaseEq(1)
            IfEq(LFlag1, FALSE)
                Set(LVarA, 0)
            EndIf
            IfEq(LFlag3, FALSE)
                IfEq(LVarA, -1)
                    Set(LVarA, 2)
                Else
                    Set(LVarB, 2)
                EndIf
            EndIf
        CaseEq(2)
            IfEq(LFlag2, FALSE)
                Set(LVarA, 1)
            EndIf
            IfEq(LFlag4, FALSE)
                IfEq(LVarA, -1)
                    Set(LVarA, 3)
                Else
                    Set(LVarB, 3)
                EndIf
            EndIf
        CaseEq(3)
            IfEq(LFlag3, FALSE)
                Set(LVarA, 2)
            EndIf
    EndSwitch
    IfNe(LVarB, -1)
        Call(RandInt, 1000, LVar0)
        IfLt(LVar0, 500)
            Set(LVarA, LVarB)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_CountActiveSummoners) = {
    Set(LVar9, 0)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetOriginalActorType, LVar0, LVar2)
        Switch(LVar2)
            CaseOrEq(ACTOR_TYPE_FOREST_FUZZY)
            CaseOrEq(ACTOR_TYPE_JUNGLE_FUZZY)
                Call(GetStatusFlags, LVar0, LVar3)
                IfNotFlag(LVar3, STATUS_FLAGS_IMMOBILIZED)
                    Call(GetActorVar, LVar0, AVAR_Generation, LVar3)
                    IfNe(LVar3, 2)
                        Add(LVar9, 1)
                    EndIf
                EndIf
            EndCaseGroup
            CaseEq(ACTOR_TYPE_SPEAR_GUY)
                Call(GetStatusFlags, LVar0, LVar3)
                IfNotFlag(LVar3, STATUS_FLAGS_IMMOBILIZED)
                    Call(GetActorVar, LVar0, AVAR_SpearGuy_Generation, LVar3)
                    IfLt(LVar3, 2)
                        Add(LVar9, 1)
                    EndIf
                EndIf
        EndSwitch
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        ExecWait(N(EVS_Attack_Leech))
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_Generation, LVar0)
    IfEq(LVar0, 2)
        ExecWait(N(EVS_Attack_Leech))
        Return
    EndIf
    ExecWait(N(EVS_GetAvailableColumn))
    IfEq(LVarA, -1)
        ExecWait(N(EVS_Attack_Leech))
        Return
    EndIf
    ExecWait(N(EVS_CountActiveSummoners))
    Switch(LVar9)
        CaseEq(1)
            Call(RandInt, 1000, LVar0)
            IfLt(LVar0, 400)
                ExecWait(N(EVS_Move_Divide))
                Return
            EndIf
        CaseEq(2)
            Call(RandInt, 1000, LVar0)
            IfLt(LVar0, 150)
                ExecWait(N(EVS_Move_Divide))
                Return
            EndIf
        CaseEq(3)
            Call(RandInt, 1000, LVar0)
            IfLt(LVar0, 70)
                ExecWait(N(EVS_Move_Divide))
                Return
            EndIf
    EndSwitch
    ExecWait(N(EVS_Attack_Leech))
    Return
    End
};

Vec3i N(SummonPos) = { NPC_DISPOSE_LOCATION };

Formation N(SummonFormation) = {
    ACTOR_BY_POS(NAMESPACE, N(SummonPos), 0),
};
