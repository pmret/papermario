#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Cleft.h"

#define NAMESPACE A(cleft)

extern s32 N(UprightAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_Toppled        = 0,
    AVAR_ToppleTurns    = 1,
};

enum N(ActorParams) {
    DMG_TACKLE      = 2,
};

s32 N(UprightDefenseTable)[] = {
    ELEMENT_NORMAL,   2,
    ELEMENT_FIRE,    99,
    ELEMENT_MAGIC,    0,
    ELEMENT_END,
};

s32 N(ToppledDefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_FIRE,    99,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              40,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,              50,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           50,
    STATUS_KEY_SHRINK,             75,
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
    .type = ACTOR_TYPE_CLEFT,
    .level = ACTOR_LEVEL_CLEFT,
    .maxHP = 2,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 80,
    .airLiftChance = 40,
    .hurricaneChance = 40,
    .spookChance = 40,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 95,
    .coinReward = 2,
    .size = { 44, 36 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(UprightAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Cleft_Anim02,
    STATUS_KEY_STONE,     ANIM_Cleft_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Cleft_Anim0C,
    STATUS_KEY_POISON,    ANIM_Cleft_Anim02,
    STATUS_KEY_STOP,      ANIM_Cleft_Anim00,
    STATUS_KEY_STATIC,    ANIM_Cleft_Anim02,
    STATUS_KEY_PARALYZE,  ANIM_Cleft_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Cleft_Anim0E,
    STATUS_KEY_FEAR,      ANIM_Cleft_Anim0E,
    STATUS_END,
};

s32 N(ToppledAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Cleft_Anim05,
    STATUS_KEY_STONE,     ANIM_Cleft_Anim01,
    STATUS_KEY_SLEEP,     ANIM_Cleft_Anim0D,
    STATUS_KEY_POISON,    ANIM_Cleft_Anim05,
    STATUS_KEY_STOP,      ANIM_Cleft_Anim01,
    STATUS_KEY_STATIC,    ANIM_Cleft_Anim05,
    STATUS_KEY_PARALYZE,  ANIM_Cleft_Anim01,
    STATUS_KEY_DIZZY,     ANIM_Cleft_Anim0F,
    STATUS_KEY_FEAR,      ANIM_Cleft_Anim0F,
    STATUS_END,
};

#include "common/SetSpinSmashable.inc.c"

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(EVS_Init) = {
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_Toppled, 0)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_FlipOver) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_Toppled, 1)
    Call(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, 2)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim07)
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
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim03)
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledAnims)))
    Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(ToppledDefenseTable)))
    Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 15)
    Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -7)
    Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_SPIKY_TOP, FALSE)
    Call(N(SetSpinSmashable), FALSE)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, TRUE)
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
                    Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
                    IfEq(LVar0, 1)
                        SetConst(LVar1, ANIM_Cleft_Anim09)
                    Else
                        SetConst(LVar1, ANIM_Cleft_Anim08)
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
                    Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
                    IfEq(LVar0, 1)
                        SetConst(LVar0, PRT_MAIN)
                        SetConst(LVar1, ANIM_Cleft_Anim09)
                        SetConst(LVar2, -1)
                        ExecWait(EVS_Enemy_BurnHit)
                    Else
                        SetConst(LVar0, PRT_MAIN)
                        SetConst(LVar1, ANIM_Cleft_Anim08)
                        SetConst(LVar2, -1)
                        ExecWait(EVS_Enemy_BurnHit)
                    EndIf
                    Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION, FALSE)
            EndSwitch
        CaseEq(EVENT_BURN_DEATH)
            Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            IfEq(LVar0, 1)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Anim09)
                SetConst(LVar2, -1)
                ExecWait(EVS_Enemy_BurnHit)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Anim09)
                ExecWait(EVS_Enemy_Death)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Anim08)
                SetConst(LVar2, -1)
                ExecWait(EVS_Enemy_BurnHit)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Anim08)
                ExecWait(EVS_Enemy_Death)
            EndIf
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            IfEq(LVar0, 1)
                SetConst(LVar1, ANIM_Cleft_Anim09)
            Else
                SetConst(LVar1, ANIM_Cleft_Anim08)
            EndIf
            SetConst(LVar0, PRT_MAIN)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            IfEq(LVar0, 1)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Anim09)
                ExecWait(EVS_Enemy_SpinSmashHit)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Anim09)
                ExecWait(EVS_Enemy_Death)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Anim08)
                ExecWait(EVS_Enemy_SpinSmashHit)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Anim08)
                ExecWait(EVS_Enemy_Death)
            EndIf
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Cleft_Anim08)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Cleft_Anim08)
            ExecWait(EVS_Enemy_Knockback)
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Cleft_Anim07)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Cleft_Anim08)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Cleft_Anim08)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_STAR_BEAM)
        CaseEq(EVENT_SPIKE_TAUNT)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim18)
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
            Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            IfEq(LVar0, 1)
                SetConst(LVar1, ANIM_Cleft_Anim03)
            Else
                SetConst(LVar1, ANIM_Cleft_Anim02)
            EndIf
            SetConst(LVar0, PRT_MAIN)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            IfEq(LVar0, 1)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Anim09)
                ExecWait(EVS_Enemy_Hit)
                Wait(10)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Anim09)
                ExecWait(EVS_Enemy_Death)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Anim08)
                ExecWait(EVS_Enemy_Hit)
                Wait(10)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Anim08)
                ExecWait(EVS_Enemy_Death)
            EndIf
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            IfEq(LVar0, 0)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Anim02)
                ExecWait(EVS_Enemy_Recover)
            EndIf
        CaseEq(EVENT_SCARE_AWAY)
            Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            IfEq(LVar0, 1)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Anim03)
                ExecWait(EVS_Enemy_NoDamageHit)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Anim07)
                SetConst(LVar2, ANIM_Cleft_Anim08)
                ExecWait(EVS_Enemy_ScareAway)
                Return
            EndIf
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Cleft_Anim0F)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
            IfEq(LVar0, 1)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Anim0F)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Cleft_Anim08)
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
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim03)
    Wait(20)
    Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim05)
    Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
    Call(GetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
    IfGt(LVar0, 0)
        Sub(LVar0, 1)
        Call(SetActorVar, ACTOR_SELF, AVAR_ToppleTurns, LVar0)
    Else
        Call(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim03)
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
        Call(SetActorVar, ACTOR_SELF, AVAR_Toppled, 0)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim02)
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
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim10)
    Wait(10)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim11)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 50, 0, -5)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim00)
    Wait(8)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CLEFT_TACKLE)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, DMG_TACKLE, BS_FLAGS1_INCLUDE_POWER_UPS)
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
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim11)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 100)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, 45)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim08)
            Wait(15)
            Wait(8)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetPartRotation, ACTOR_SELF, PRT_MAIN, 0, 0, 0)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim07)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim02)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim11)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 20)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_TACKLE, BS_FLAGS1_TRIGGER_EVENTS)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim02)
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
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim02)
            Wait(5)
            Call(YieldTurn)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim07)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(SetGoalToHome, ACTOR_SELF)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Cleft_Anim02)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_Toppled, LVar0)
    IfEq(LVar0, TRUE)
        ExecWait(N(EVS_TryGettingUp))
    Else
        ExecWait(N(EVS_Attack_Tackle))
    EndIf
    Return
    End
};
