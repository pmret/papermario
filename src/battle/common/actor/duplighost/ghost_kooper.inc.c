#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleKooper.h"

#define NAMESPACE A(kooper_clone)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleKooper_Idle,
    STATUS_KEY_STONE,     ANIM_BattleKooper_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleKooper_Still,
    STATUS_KEY_POISON,    ANIM_BattleKooper_Idle,
    STATUS_KEY_STOP,      ANIM_BattleKooper_Still,
    STATUS_KEY_STATIC,    ANIM_BattleKooper_Idle,
    STATUS_KEY_PARALYZE,  ANIM_BattleKooper_Still,
    STATUS_KEY_DIZZY,     ANIM_BattleKooper_Injured,
    STATUS_KEY_FEAR,      ANIM_BattleKooper_Injured,
    STATUS_END,
};

s32 N(ToppleAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleKooper_Toppled,
    STATUS_KEY_STONE,     ANIM_BattleKooper_StillToppled,
    STATUS_KEY_SLEEP,     ANIM_BattleKooper_StillToppled,
    STATUS_KEY_POISON,    ANIM_BattleKooper_Toppled,
    STATUS_KEY_STOP,      ANIM_BattleKooper_StillToppled,
    STATUS_KEY_STATIC,    ANIM_BattleKooper_Toppled,
    STATUS_KEY_PARALYZE,  ANIM_BattleKooper_StillToppled,
    STATUS_KEY_DIZZY,     ANIM_BattleKooper_Toppled,
    STATUS_KEY_FEAR,      ANIM_BattleKooper_Toppled,
    STATUS_END,
};

s32 N(UprightDefenseTable)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_END,
};

s32 N(ToppledDefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              60,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 32 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(UprightDefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -16 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GHOST_KOOPER,
    .level = ACTOR_LEVEL_GHOST_KOOPER,
    .maxHP = 15,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 80,
    .hurricaneChance = 70,
    .spookChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 2,
    .size = { 32, 38 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_Kooper_Toppled, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_Kooper_ToppleTurns, 0)
    Return
    End
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(EVS_Idle) = {
    Label(0)
    Call(GetActorVar, ACTOR_SELF, AVAR_Kooper_Toppled, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -2, 38)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -3, -9)
            Call(N(SetAbsoluteStatusOffsets), -10, 25, 10, 25)
        CaseEq(1)
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 5, 15)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -6)
            Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
    EndSwitch
    Wait(1)
    Goto(0)
    Return
    End
};

s32 N(FlipPosOffsets)[] = { 9, 16, 22, 26, 30, 32, 33, 32, 30, 26, 22, 16, 9, 0, 4, 6, 7, 6, 4, 0, 2, 0 };

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            Call(GetLastElement, LVar1)
            IfFlag(LVar1, DAMAGE_TYPE_SHOCK)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BattleKooper_Hurt)
                ExecWait(A(EVS_Duplighost_OnHitElectric))
                Return
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BattleKooper_Hurt)
                ExecWait(EVS_Enemy_Hit)
            EndIf
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleKooper_BurnHurt)
            SetConst(LVar2, ANIM_BattleKooper_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleKooper_BurnHurt)
            SetConst(LVar2, ANIM_BattleKooper_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(A(EVS_Duplighost_OnDeath))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleKooper_BurnStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleKooper_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            ExecWait(A(EVS_Duplighost_OnDeath))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleKooper_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleKooper_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_FLIP_TRIGGER)
            Call(SetActorVar, ACTOR_SELF, AVAR_Kooper_Toppled, 1)
            Call(SetActorVar, ACTOR_SELF, AVAR_Kooper_ToppleTurns, 1)
            Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledDefenseTable)))
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppleAnims)))
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 5, 15)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -6)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKooper_Hurt)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
            Thread
                Wait(4)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 30)
                Wait(1)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                Wait(1)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, -30)
                Wait(1)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, -60)
                Wait(1)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, -75)
                Wait(1)
            EndThread
            UseBuf(N(FlipPosOffsets))
            Loop(ARRAY_COUNT(N(FlipPosOffsets)))
                BufRead1(LVar0)
                Call(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                Wait(1)
            EndLoop
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKooper_Toppled)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            Call(GetActorVar, ACTOR_SELF, AVAR_Kooper_Toppled, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_BattleKooper_Idle)
                CaseEq(1)
                    Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_BattleKooper_Toppled)
            EndSwitch
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            ExecWait(A(EVS_Duplighost_OnDeath))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleKooper_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleKooper_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            Call(GetActorVar, ACTOR_SELF, AVAR_Kooper_Toppled, LVar0)
            IfEq(LVar0, 1)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BattleKooper_Toppled)
                ExecWait(EVS_Enemy_NoDamageHit)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BattleKooper_Idle)
                ExecWait(EVS_Enemy_Recover)
            EndIf
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleKooper_Run)
            SetConst(LVar2, ANIM_BattleKooper_Hurt)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            Call(GetActorVar, ACTOR_SELF, AVAR_Kooper_Toppled, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_BattleKooper_Run)
                CaseEq(1)
                    Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(3.0))
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_BattleKooper_Toppled)
            EndSwitch
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            Call(GetActorVar, ACTOR_SELF, AVAR_Kooper_Toppled, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    Call(GetStatusFlags, ACTOR_SELF, LVar0)
                    IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                        IfFlag(LVar0, STATUS_FLAG_SHRINK)
                            Call(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
                        Else
                            Call(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                        EndIf
                    EndIf
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_BattleKooper_Hurt)
                CaseEq(1)
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_BattleKooper_Toppled)
            EndSwitch
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

#include "common/UnkActorPosFunc.inc.c"

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetActorVar, ACTOR_SELF, AVAR_Kooper_Toppled, LVar0)
    IfEq(LVar0, 1)
        Call(GetActorVar, ACTOR_SELF, AVAR_Kooper_ToppleTurns, LVar0)
        Sub(LVar0, 1)
        IfGt(LVar0, 0)
            Call(SetActorVar, ACTOR_SELF, AVAR_Kooper_ToppleTurns, LVar0)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(3.0))
            Wait(30)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
        Else
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(3.0))
            Wait(20)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKooper_Toppled)
            Set(LVar0, 0)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
            Thread
                Loop(5)
                    Add(LVar0, 15)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(3.0))
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKooper_Idle)
            Call(SetActorVar, ACTOR_SELF, AVAR_Kooper_Toppled, 0)
            Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(UprightDefenseTable)))
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -2, 38)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -3, -9)
        EndIf
        Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
        Call(UseIdleAnimation, ACTOR_SELF, true)
        Return
    EndIf
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKooper_EnterShell)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_NONE)
    Wait(15)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKooper_ShellSpinSlowest)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KOOPER_SHELL_SPINUP)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 75)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_AVG, BTL_CAM_XADJ_AVG, true)
    Call(GetActorVar, ACTOR_SELF, AVAR_Copy_PartnerLevel, LVar0)
    Switch(LVar0)
        CaseEq(PARTNER_RANK_NORMAL)
            Set(LVar0, 10)
        CaseEq(PARTNER_RANK_SUPER)
            Set(LVar0, 20)
        CaseEq(PARTNER_RANK_ULTRA)
            Set(LVar0, 30)
    EndSwitch
    Set(LVar9, 0)
    Loop(LVar0)
        Add(LVar9, 1)
        Switch(LVar9)
            CaseLt(20)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKooper_ShellSpinSlowest)
                Call(SetActorSpeed, ACTOR_SELF, Float(10.0))
            CaseEq(20)
                Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            CaseLt(40)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKooper_ShellSpinSlower)
                Call(SetActorSpeed, ACTOR_SELF, Float(12.0))
            CaseEq(40)
                Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            CaseLt(50)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKooper_ShellSpinFaster)
                Call(SetActorSpeed, ACTOR_SELF, Float(14.0))
            CaseEq(50)
                Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            CaseLt(60)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKooper_ShellSpinFastest)
                Call(SetActorSpeed, ACTOR_SELF, Float(16.0))
            CaseEq(60)
                Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
        EndSwitch
        Wait(1)
    EndLoop
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAKARRY_AIR_RAID_1)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 15)
    Call(AddActorDecoration, ACTOR_SELF, PRT_ZERO, 0, ACTOR_DECORATION_GREY_SMOKE_TRAIL)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Thread
                Call(N(UnkActorPosFunc))
                Call(RemoveActorDecoration, ACTOR_SELF, PRT_ZERO, 0)
            EndThread
            Wait(4)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKooper_ShellStill)
            Call(SetActorRotationOffset, ACTOR_SELF, -8, 0, 0)
            Set(LVar0, 0)
            Loop(2)
                Add(LVar0, 30)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                Wait(1)
            EndLoop
            Wait(5)
            Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
            PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 16, 4, 0, 10, 0)
            Loop(5)
                Add(LVar0, -12)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                Wait(1)
            EndLoop
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 2)
            Wait(2)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, -2)
            Wait(2)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(10)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKooper_ExitShell)
            Wait(10)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKooper_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.5))
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(RemoveActorDecoration, ACTOR_SELF, PRT_ZERO, 0)
    Call(GetActorVar, ACTOR_SELF, AVAR_Copy_PartnerLevel, LVar9)
    Switch(LVar9)
        CaseEq(PARTNER_RANK_NORMAL)
            Wait(2)
#if VERSION_JP
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
#else
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, 2, BS_FLAGS1_TRIGGER_EVENTS)
#endif
        CaseEq(PARTNER_RANK_SUPER)
            Wait(2)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, 3, BS_FLAGS1_TRIGGER_EVENTS)
        CaseEq(PARTNER_RANK_ULTRA)
            Wait(2)
#if VERSION_JP
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, 4, BS_FLAGS1_TRIGGER_EVENTS)
#else
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, 5, BS_FLAGS1_TRIGGER_EVENTS)
#endif
    EndSwitch
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 8)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 60)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.4))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, false, true, false)
            Add(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, false, true, false)
            Add(LVar0, 10)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 4, false, true, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKooper_ExitShell)
            Wait(15)
            Call(YieldTurn)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleKooper_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.5))
            Call(RunToGoal, ACTOR_SELF, 0, false)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

Formation A(KooperCloneFormation) = {
    ACTOR_BY_POS(NAMESPACE, A(DuplighostSummonPos), 0),
};
