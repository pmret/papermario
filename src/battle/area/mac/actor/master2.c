#include "../area.h"
#include "sprite/npc/TheMaster.h"

#define NAMESPACE A(master2)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_BattleCry      = 0,
    AVAR_Unused         = 1,
    AVAR_WasHit         = 2,
    AVAR_HitCounter     = 3,
};

enum N(ActorParams) {
    DMG_STRIKE_ONCE         = 8,
    DMG_STRIKE_TWICE_1      = 5,
    DMG_STRIKE_TWICE_2      = 6,
};

// AVAR_HitCounter starts at this value, for some reason
#define INITIAL_HIT_COUNT 2

s32 N(BaseAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_TheMaster_Walk,
    STATUS_KEY_STONE,     ANIM_TheMaster_Still,
    STATUS_KEY_SLEEP,     ANIM_TheMaster_Sleep,
    STATUS_KEY_POISON,    ANIM_TheMaster_Still,
    STATUS_KEY_STOP,      ANIM_TheMaster_Still,
    STATUS_KEY_STATIC,    ANIM_TheMaster_Still,
    STATUS_KEY_PARALYZE,  ANIM_TheMaster_Still,
    STATUS_KEY_DIZZY,     ANIM_TheMaster_Dizzy,
    STATUS_KEY_DIZZY,     ANIM_TheMaster_Dizzy,
    STATUS_END,
};

s32 N(AscendedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_TheMaster_AscendedWalk,
    STATUS_KEY_STONE,     ANIM_TheMaster_AscendedStill,
    STATUS_KEY_SLEEP,     ANIM_TheMaster_AscendedSleep,
    STATUS_KEY_POISON,    ANIM_TheMaster_AscendedStill,
    STATUS_KEY_STOP,      ANIM_TheMaster_AscendedStill,
    STATUS_KEY_STATIC,    ANIM_TheMaster_AscendedStill,
    STATUS_KEY_PARALYZE,  ANIM_TheMaster_AscendedStill,
    STATUS_KEY_DIZZY,     ANIM_TheMaster_AscendedDizzy,
    STATUS_KEY_DIZZY,     ANIM_TheMaster_AscendedDizzy,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,             50,
    STATUS_KEY_DEFAULT,            50,
    STATUS_KEY_SLEEP,              30,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              30,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           30,
    STATUS_KEY_SHRINK,             40,
    STATUS_KEY_STOP,               50,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -2,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,        -1,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 28 },
        .opacity = 255,
        .idleAnimations = N(BaseAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 2, -7 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_THE_MASTER_2,
    .level = ACTOR_LEVEL_THE_MASTER_2,
    .maxHP = 75,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 100,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 30, 35 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 30 },
    .statusTextOffset = { 10, 30 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_BattleCry, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_Unused, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_WasHit, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_HitCounter, INITIAL_HIT_COUNT)
    Call(SetBattleFlagBits, BS_FLAGS1_NO_GAME_OVER, TRUE)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HandleEvent_Inner) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_AscendedHurt)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_BurnHurt)
            SetConst(LVar2, ANIM_TheMaster_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_BurnHurt)
            SetConst(LVar2, ANIM_TheMaster_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_AscendedDefeated)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_AscendedHurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_AscendedHurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_AscendedHurt)
            ExecWait(EVS_Enemy_Knockback)
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(2.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedRun)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
            Wait(5)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedWalk)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_AscendedIdle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_AscendedHurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_AscendedDefeated)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_AscendedHurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_AscendedDefeated)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_AscendedHurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_AscendedDefeated)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_END_FIRST_STRIKE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_AscendedIdle)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_AscendedIdle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TheMaster_AscendedRun)
            SetConst(LVar2, ANIM_TheMaster_AscendedHurt)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_StrikeOnce) = {
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedRun)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(3.8))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
    Wait(10)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_STANCE_CHANGE)
    Thread
        Wait(15)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_STANCE_CHANGE)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedPunch)
    Wait(30)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedKick)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_KICK)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_FLUTTER)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 0, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -50, 0, 0)
            Call(RunToGoal, ACTOR_SELF, 10, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
            Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
            Wait(10)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedRun)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
            Return
        EndCaseGroup
    EndSwitch
    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 0, 0, 0)
    Call(RunToGoal, ACTOR_SELF, 5, FALSE)
    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_SMACK)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_FLUTTER)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_STRIKE_ONCE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_FLUTTER)
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 20, 0)
                Set(LVar0, 0)
                Loop(10)
                    Add(LVar0, 36)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 50)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.2))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedMidair)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_A)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedLand)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Wait(3)
            Add(LVar0, 20)
            Set(LVar1, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedMidair)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_B)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedLand)
            Wait(20)
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(3.8))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedRun)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_StrikeTwice) = {
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_08)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamZoom, 200)
    Call(SetBattleCamOffsetZ, 13)
    Call(MoveBattleCamOver, 60)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedDownwardStance)
    Wait(40)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_07)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 1)
    Wait(10)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_LEAP)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_FLUTTER)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 0, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -50, 0, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedPalmStance)
            Call(RunToGoal, ACTOR_SELF, 10, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
            Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
            Wait(10)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedRun)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
            Return
        EndCaseGroup
    EndSwitch
    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedPalmStance)
    Call(RunToGoal, ACTOR_SELF, 5, FALSE)
    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(4.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(3.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(2.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.0))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
    EndThread
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_SMACK)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_FLUTTER)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_STRIKE_TWICE_1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Wait(15)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Thread
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_JUMP)
        Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedUppercut)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(0.9))
        Call(JumpToGoal, ACTOR_SELF, 25, FALSE, TRUE, FALSE)
        Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
    EndThread
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.5))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.2))
    EndThread
    Wait(2)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_SMACK)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_FLUTTER)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_STRIKE_TWICE_2, BS_FLAGS1_TRIGGER_EVENTS)
    Wait(15)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_FLIP)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_FLUTTER)
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 10, 0)
                Set(LVar0, 0)
                Loop(10)
                    Add(LVar0, 36)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 50)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedMidair)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 30, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_A)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedLand)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Wait(3)
            Add(LVar0, 20)
            Set(LVar1, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedMidair)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_B)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedLand)
            Wait(20)
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(3.8))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedRun)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(RandInt, 100, LVar0)
    Switch(LVar0)
        CaseLt(20)
            ExecWait(N(EVS_Attack_StrikeTwice))
        CaseDefault
            ExecWait(N(EVS_Attack_StrikeOnce))
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_BattleCry, LVar0)
            IfEq(LVar0, FALSE)
                Call(UseBattleCamPreset, BTL_CAM_PRESET_13)
                Call(BattleCamTargetActor, ACTOR_SELF)
                Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                Wait(10)
                Call(ActorSpeak, MSG_MAC_Gate_002E, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Talk, ANIM_TheMaster_Walk)
                Call(SetActorVar, ACTOR_SELF, AVAR_BattleCry, TRUE)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Cough)
                Wait(15)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_OpenMouth)
                Wait(5)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GHOST_TRANSFORM)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Add(LVar1, 20)
                PlayEffect(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar1, LVar2, Float(1.0), 30, 0)
                Set(LVar0, 0)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Still)
                Loop(15)
                    Add(LVar0, 24)
                    Call(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
                    Wait(1)
                EndLoop
                Set(LVar0, 0)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Still)
                Loop(5)
                    Add(LVar0, 18)
                    Call(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
                    Wait(1)
                EndLoop
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SMOKE_BURST)
                Thread
                    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Add(LVar1, 3)
                    Loop(3)
                        PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
                        Wait(3)
                    EndLoop
                EndThread
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Still)
                Loop(5)
                    Add(LVar0, 36)
                    Call(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
                    Wait(1)
                EndLoop
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedStill)
                Loop(5)
                    Add(LVar0, 18)
                    Call(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
                    Wait(1)
                EndLoop
                Wait(15)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(AscendedAnims)))
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedRun)
                Wait(15)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Call(MoveBattleCamOver, 10)
                Call(ActorSpeak, MSG_MAC_Gate_0033, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedTalk, ANIM_TheMaster_AscendedWalk)
            EndIf
        CaseEq(PHASE_ENEMY_BEGIN)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAGS_DOJO)
                BreakSwitch
            EndIf
            Call(GetActorHP, ACTOR_SELF, LVar0)
            Call(GetEnemyMaxHP, ACTOR_SELF, LVar1)
            Div(LVar1, 2)
            IfLe(LVar0, LVar1)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Call(MoveBattleCamOver, 10)
                Call(ActorSpeak, MSG_MAC_Gate_0036, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedTalk, ANIM_TheMaster_AscendedWalk)
                BreakSwitch
            EndIf
            Call(GetPlayerHP, LVar0)
            IfLe(LVar0, 5)
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Call(MoveBattleCamOver, 10)
                Call(ActorSpeak, MSG_MAC_Gate_0037, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedTalk, ANIM_TheMaster_AscendedWalk)
                BreakSwitch
            EndIf
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    ExecWait(N(EVS_HandleEvent_Inner))
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAGS_DOJO)
        Return
    EndIf
    Call(GetBattleFlags, LVar0)
    IfFlag(LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)
        Call(GetLastDamage, ACTOR_SELF, LVar0)
        IfGt(LVar0, 0)
            Call(SetActorVar, ACTOR_SELF, AVAR_WasHit, TRUE)
            Call(AddActorVar, ACTOR_SELF, AVAR_HitCounter, 1)
        EndIf
    EndIf
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT)
        CaseOrEq(EVENT_BURN_HIT)
        CaseOrEq(EVENT_SPIN_SMASH_HIT)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            Call(GetActorVar, ACTOR_SELF, AVAR_WasHit, LVarA)
            Call(GetActorVar, ACTOR_SELF, AVAR_HitCounter, LVarB)
            Call(SetActorVar, ACTOR_SELF, AVAR_WasHit, FALSE)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAGS_DOJO | STATUS_FLAG_POISON | STATUS_FLAG_SHRINK)
                BreakSwitch
            EndIf
            Set(LFlag0, FALSE)
            Call(GetMenuSelection, LVar0, LVar1, LVar2)
            Switch(LVar0)
                CaseOrEq(BTL_MENU_TYPE_SMASH)
                CaseOrEq(BTL_MENU_TYPE_JUMP)
                    Set(LFlag0, TRUE)
                EndCaseGroup
            EndSwitch
            IfEq(LFlag0, FALSE)
                BreakSwitch
            EndIf
            Call(UseIdleAnimation, ACTOR_SELF, FALSE)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            IfEq(LVarA, TRUE)
                IfGt(LVarB, INITIAL_HIT_COUNT)
                    // 'Nice maneuver.'
                    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    Call(MoveBattleCamOver, 10)
                    Call(ActorSpeak, MSG_MAC_Gate_0035, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedTalk, ANIM_TheMaster_AscendedWalk)
                    Call(SetActorVar, ACTOR_SELF, AVAR_HitCounter, 0)
                EndIf
            Else
                // 'You can't defeat me like that'
                Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                Call(MoveBattleCamOver, 10)
                Call(ActorSpeak, MSG_MAC_Gate_0034, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedTalk, ANIM_TheMaster_AscendedWalk)
            EndIf
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
        EndCaseGroup
    EndSwitch
    Return
    End
};
