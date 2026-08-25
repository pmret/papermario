#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/KoopaTroopa.h"
#include "sprite/npc/ParaTroopa.h"

#define NAMESPACE A(paratroopa)

extern s32 N(DownedAnims)[];
extern s32 N(FlyingAnims)[];
extern s32 N(WingAnims)[];
extern EvtScript N(EVS_Flying_Init);
extern EvtScript N(EVS_Flying_Idle);
extern EvtScript N(EVS_Flying_TakeTurn);
extern EvtScript N(EVS_Flying_HandleEvent);
extern EvtScript N(EVS_KnockDown);

extern EvtScript N(EVS_Downed_Init);
extern EvtScript N(EVS_Downed_Idle);
extern EvtScript N(EVS_Downed_TakeTurn);
extern EvtScript N(EVS_Downed_HandleEvent);

#include "common/StartRumbleWithParams.inc.c"
#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

enum N(ActorPartIDs) {
    PRT_DOWNED          = 1,
    PRT_FLYING          = 2,
    PRT_DUMMY_WINGS     = 3,
};

enum N(ActorVars) {
    AVAR_AerialFlip     = 0, // true if current hit should trigger a flip event when KnockDown is done
    AVAR_IsFlipped      = 8,
    AVAR_FlippedTurns   = 9,
};

enum N(ActorParams) {
    DMG_AIR_TACKLE      = 1,
    DMG_SHELL_TOSS      = 1,
};

s32 N(DownedDefense)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_SMASH,    1,
    ELEMENT_JUMP,     1,
    ELEMENT_WATER,    1,
    ELEMENT_BLAST,    1,
    ELEMENT_END,
};

s32 N(FlyingDefense)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_END,
};

s32 N(FlippedDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(DownedStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              90,
    STATUS_KEY_POISON,             60,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_UNUSED,              0,
    STATUS_KEY_STATIC,             80,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             90,
    STATUS_KEY_STOP,              100,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_UNUSED,         0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

s32 N(FlyingStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              90,
    STATUS_KEY_POISON,             60,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_UNUSED,              0,
    STATUS_KEY_STATIC,             80,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             90,
    STATUS_KEY_STOP,              100,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          1,
    STATUS_TURN_MOD_UNUSED,         0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_DOWNED,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 36 },
        .opacity = 255,
        .idleAnimations = N(DownedAnims),
        .defenseTable = N(DownedDefense),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -7 },
    },
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_FLYING,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -4, 36 },
        .opacity = 255,
        .idleAnimations = N(FlyingAnims),
        .defenseTable = N(FlyingDefense),
        .eventFlags = ACTOR_EVENT_FLAG_GROUNDABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 2, -14 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_DUMMY_WINGS,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 32 },
        .opacity = 255,
        .idleAnimations = N(WingAnims),
        .defenseTable = N(DownedDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_PARATROOPA,
    .level = ACTOR_LEVEL_PARATROOPA,
    .maxHP = 4,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Flying_Init),
    .statusTable = N(FlyingStatusTable),
    .escapeChance = 60,
    .airLiftChance = 95,
    .hurricaneChance = 100,
    .spookChance = 90,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 50, 38 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 29 },
    .statusTextOffset = { 8, 30 },
};

s32 N(FlyingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ParaTroopa_Idle,
    STATUS_KEY_STONE,     ANIM_ParaTroopa_Still,
    STATUS_KEY_SLEEP,     ANIM_ParaTroopa_Sleep,
    STATUS_KEY_POISON,    ANIM_ParaTroopa_Still,
    STATUS_KEY_STOP,      ANIM_ParaTroopa_Still,
    STATUS_KEY_STATIC,    ANIM_ParaTroopa_Idle,
    STATUS_KEY_PARALYZE,  ANIM_ParaTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_ParaTroopa_Stunned,
    STATUS_KEY_UNUSED,    ANIM_ParaTroopa_Stunned,
    STATUS_END,
};

s32 N(FlyingShuffleAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ParaTroopa_Idle,
    STATUS_KEY_STONE,     ANIM_ParaTroopa_Still,
    STATUS_KEY_SLEEP,     ANIM_ParaTroopa_Sleep,
    STATUS_KEY_POISON,    ANIM_ParaTroopa_Still,
    STATUS_KEY_STOP,      ANIM_ParaTroopa_Still,
    STATUS_KEY_STATIC,    ANIM_ParaTroopa_Idle,
    STATUS_KEY_PARALYZE,  ANIM_ParaTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_ParaTroopa_Stunned,
    STATUS_KEY_UNUSED,    ANIM_ParaTroopa_Stunned,
    STATUS_END,
};

s32 N(WingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ParaTroopa_WingsStill,
    STATUS_KEY_STONE,     ANIM_ParaTroopa_Still,
    STATUS_KEY_SLEEP,     ANIM_ParaTroopa_Sleep,
    STATUS_KEY_POISON,    ANIM_ParaTroopa_Still,
    STATUS_KEY_STOP,      ANIM_ParaTroopa_Still,
    STATUS_KEY_STATIC,    ANIM_ParaTroopa_WingsStill,
    STATUS_KEY_PARALYZE,  ANIM_ParaTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_ParaTroopa_Stunned,
    STATUS_KEY_UNUSED,    ANIM_ParaTroopa_Stunned,
    STATUS_END,
};

EvtScript N(EVS_Flying_HandlePhase) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_AerialFlip, false)
    Return
    End
};

EvtScript N(EVS_Flying_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_Flying_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Flying_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_Flying_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_Flying_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_AerialFlip, false)
    Return
    End
};

EvtScript N(EVS_Flying_UpdateTargetOffsets) = {
    IfFlag(LVar1, STATUS_FLAG_DIZZY | STATUS_FLAG_SLEEP)
        Call(SetTargetOffset, ACTOR_SELF, PRT_FLYING, 0, 25)
        Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_FLYING, 3, -6)
        Call(N(SetAbsoluteStatusOffsets), -19, 25, 4, 28)
    Else
        Call(SetTargetOffset, ACTOR_SELF, PRT_FLYING, -2, 36)
        Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_FLYING, 0, -7)
        Call(N(SetAbsoluteStatusOffsets), -10, 29, 8, 30)
    EndIf
    Return
    End
};

EvtScript N(EVS_Flying_Idle) = {
    Label(10)
        Call(RandInt, 80, LVar0)
        Add(LVar0, 80)
        Loop(LVar0)
            Label(0)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                ExecWait(N(EVS_Flying_UpdateTargetOffsets))
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
        Call(SetIdleAnimations, ACTOR_SELF, PRT_DOWNED, Ref(N(FlyingAnims)))
        Loop(20)
            Label(1)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                ExecWait(N(EVS_Flying_UpdateTargetOffsets))
                IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    Wait(1)
                    Goto(1)
                EndIf
            Wait(1)
        EndLoop
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Sub(LVar0, 5)
        Call(SetActorIdleSpeed, ACTOR_SELF, Float(0.6))
        Call(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, Ref(N(FlyingShuffleAnims)))
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleFlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
        Call(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, Ref(N(FlyingAnims)))
        Loop(40)
            Label(2)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                ExecWait(N(EVS_Flying_UpdateTargetOffsets))
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

EvtScript N(EVS_FlyHome) = {
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_ParaTroopa_Run)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Call(FlyToGoal, ACTOR_SELF, 0, 1, EASING_SIN_OUT)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_ParaTroopa_Idle)
    Return
    End
};

EvtScript N(EVS_Flying_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            Call(SetActorVar, ACTOR_SELF, AVAR_AerialFlip, true)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_ParaTroopa_Hurt)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_HIT)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_ParaTroopa_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Call(GetBattlePhase, LVar0)
            IfEq(LVar0, PHASE_FIRST_STRIKE)
                Call(GetEncounterTrigger, LVar0)
                IfEq(LVar0, ENCOUNTER_TRIGGER_HAMMER)
                    ExecWait(N(EVS_KnockDown))
                EndIf
            EndIf
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_ParaTroopa_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_ParaTroopa_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_ParaTroopa_HurtStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_ParaTroopa_BurnHurt)
            SetConst(LVar2, ANIM_ParaTroopa_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_ParaTroopa_BurnHurt)
            SetConst(LVar2, ANIM_ParaTroopa_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_ParaTroopa_BurnStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_FALL_TRIGGER)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_ParaTroopa_Hurt)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_KnockDown))
        CaseEq(EVENT_15)
            SetConst(LVar0, PRT_DOWNED)
            SetConst(LVar1, ANIM_ParaTroopa_BurnHurt)
            SetConst(LVar1, ANIM_ParaTroopa_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(N(EVS_KnockDown))
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_DOWNED)
            SetConst(LVar1, ANIM_ParaTroopa_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_DOWNED)
            SetConst(LVar1, ANIM_ParaTroopa_HurtStill)
            ExecWait(EVS_Enemy_Knockback)
            ExecWait(N(EVS_FlyHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_ParaTroopa_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_ParaTroopa_HurtStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_ZERO_DAMAGE)
            Call(SetActorVar, ACTOR_SELF, AVAR_AerialFlip, true)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_ParaTroopa_ShellEnter)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_ParaTroopa_ShellEnter)
            ExecWait(EVS_Enemy_NoDamageHit)
            Call(GetBattlePhase, LVar0)
            IfEq(LVar0, PHASE_FIRST_STRIKE)
                Call(GetEncounterTrigger, LVar0)
                IfEq(LVar0, ENCOUNTER_TRIGGER_HAMMER)
                    ExecWait(N(EVS_KnockDown))
                EndIf
            EndIf
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_ParaTroopa_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_ParaTroopa_HurtStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
            Call(SetActorPos, ACTOR_SELF, 20, 0, 0)
            Call(HPBarToCurrent, ACTOR_SELF)
        CaseEq(EVENT_END_FIRST_STRIKE)
            ExecWait(N(EVS_FlyHome))
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_ParaTroopa_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, false)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_ParaTroopa_Run)
            SetConst(LVar2, ANIM_ParaTroopa_Hurt)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_ParaTroopa_Run)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_FLYING)
            SetConst(LVar1, ANIM_ParaTroopa_Hurt)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Flying_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR_TARGET_MIDPOINT)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_ParaTroopa_Run)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 40, 30, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(7.0))
    Call(FlyToGoal, ACTOR_SELF, 0, -16, EASING_LINEAR)
    Call(UseBattleCamPresetImmediately, BTL_CAM_INTERRUPT)
    Wait(5)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_PREDIVE)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_ParaTroopa_Windup)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(AddGoalPos, ACTOR_SELF, 6, 6, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(2.0))
            Call(FlyToGoal, ACTOR_SELF, 0, 0, EASING_LINEAR)
            Wait(6)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_DIVE)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Sub(LVar0, 25)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(10.0))
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_ParaTroopa_ShellDive)
            Call(FlyToGoal, ACTOR_SELF, 0, 0, EASING_LINEAR)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(4.0))
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 10, 0)
                Set(LVar0, 0)
                Loop(8)
                    Add(LVar0, 90)
                    IfGe(LVar0, 360)
                        Sub(LVar0, 360)
                    EndIf
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                Call(SetActorRotationOffset, ACTOR_SELF, 0, -10, 0)
            EndThread
            Call(JumpToGoal, ACTOR_SELF, 6, false, true, false)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(4.0))
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_ParaTroopa_Hurt)
            Call(JumpToGoal, ACTOR_SELF, 6, false, true, false)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(4.0))
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_ParaTroopa_Hurt)
            Call(JumpToGoal, ACTOR_SELF, 6, false, true, false)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, 30)
            Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Wait(20)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(AddActorDecoration, ACTOR_SELF, PRT_FLYING, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorYaw, ACTOR_SELF, 180)
            ExecWait(N(EVS_FlyHome))
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_FLYING, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_PREDIVE)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_ParaTroopa_Windup)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(AddGoalPos, ACTOR_SELF, 6, 6, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(2.0))
    Call(FlyToGoal, ACTOR_SELF, 0, 0, EASING_LINEAR)
    Wait(6)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_DIVE)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(10.0))
    Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_ParaTroopa_ShellDive)
    Call(FlyToGoal, ACTOR_SELF, 0, 0, EASING_LINEAR)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, DMG_AIR_TACKLE, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, 40, 30, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_ParaTroopa_ShellHit)
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 10, 0)
                Set(LVar0, 0)
                Loop(12)
                    Sub(LVar0, 90)
                    IfLt(LVar0, 0)
                        Add(LVar0, 360)
                    EndIf
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                Call(SetActorRotationOffset, ACTOR_SELF, 0, -10, 0)
                Call(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_ParaTroopa_Idle)
            EndThread
            Call(FlyToGoal, ACTOR_SELF, 0, 30, EASING_LINEAR)
            Wait(10)
            Call(YieldTurn)
            Call(ResetAllActorSounds, ACTOR_SELF)
            ExecWait(N(EVS_FlyHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_KnockDown) = {
    Call(SetPartDispOffset, ACTOR_SELF, PRT_FLYING, 0, 0, 0)
    Call(HideHealthBar, ACTOR_SELF)
    Call(SetPartFlags, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_NO_TARGET)
    Call(SetPartFlags, ACTOR_SELF, PRT_DUMMY_WINGS, ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)
    Call(SetPartFlags, ACTOR_SELF, PRT_DOWNED, ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_PRIMARY_TARGET)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 8)
    Sub(LVar2, 2)
    Call(SetPartPos, ACTOR_SELF, PRT_DUMMY_WINGS, LVar0, LVar1, LVar2)
    Call(SetAnimation, ACTOR_SELF, PRT_DOWNED, ANIM_KoopaTroopa_Hurt)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_FALL_QUICK, 0)
    Call(GetActorVar, ACTOR_SELF, AVAR_AerialFlip, LVarA)
    IfFalse(LVarA)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Set(LVar1, 0)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
        Call(N(StartRumbleWithParams), 128, 7)
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(0.3))
        EndThread
        Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
        Loop(10)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WINGS, ACTOR_PART_FLAG_INVISIBLE, true)
            Wait(1)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WINGS, ACTOR_PART_FLAG_INVISIBLE, false)
            Wait(1)
        EndLoop
        Call(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WINGS, ACTOR_PART_FLAG_INVISIBLE, true)
    Else
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Set(LVar1, 0)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
        Thread
            Loop(10)
                Call(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WINGS, ACTOR_PART_FLAG_INVISIBLE, true)
                Wait(1)
                Call(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WINGS, ACTOR_PART_FLAG_INVISIBLE, false)
                Wait(1)
            EndLoop
            Call(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WINGS, ACTOR_PART_FLAG_INVISIBLE, true)
        EndThread
        Call(N(StartRumbleWithParams), 150, 7)
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 5, Float(0.3))
        EndThread
        Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
    EndIf
    Call(GetIndexFromHome, ACTOR_SELF, LVar0)
    Mod(LVar0, 4)
    Call(SetGoalToIndex, ACTOR_SELF, LVar0)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetAnimation, ACTOR_SELF, PRT_DOWNED, ANIM_KoopaTroopa_Idle)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, false)
    Call(SetStatusTable, ACTOR_SELF, Ref(N(DownedStatusTable)))
    Call(BindHandlePhase, ACTOR_SELF, 0)
    ExecWait(N(EVS_Downed_Init))
    Call(SetActorType, ACTOR_SELF, ACTOR_TYPE_KOOPA_TROOPA)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TYPE_CHANGED, true)
    Call(HPBarToHome, ACTOR_SELF)
    Call(ResetAllActorSounds, ACTOR_SELF)
    IfTrue(LVarA)
        Call(DispatchEvent, ACTOR_SELF, EVENT_FLIP_TRIGGER)
    EndIf
    Return
    End
};

// everything below this point is shared with Koopa Troopa, but not in a manner
// that can be cleanly separated

s32 N(DownedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_KoopaTroopa_Idle,
    STATUS_KEY_STONE,     ANIM_KoopaTroopa_Still,
    STATUS_KEY_SLEEP,     ANIM_KoopaTroopa_Sleep,
    STATUS_KEY_POISON,    ANIM_KoopaTroopa_Idle,
    STATUS_KEY_STOP,      ANIM_KoopaTroopa_Still,
    STATUS_KEY_STATIC,    ANIM_KoopaTroopa_Idle,
    STATUS_KEY_PARALYZE,  ANIM_KoopaTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_KoopaTroopa_Stunned,
    STATUS_KEY_UNUSED,    ANIM_KoopaTroopa_Stunned,
    STATUS_END,
};

s32 N(DownedShuffleAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_KoopaTroopa_Walk,
    STATUS_KEY_STONE,     ANIM_KoopaTroopa_Still,
    STATUS_KEY_SLEEP,     ANIM_KoopaTroopa_Sleep,
    STATUS_KEY_POISON,    ANIM_KoopaTroopa_Walk,
    STATUS_KEY_STOP,      ANIM_KoopaTroopa_Still,
    STATUS_KEY_STATIC,    ANIM_KoopaTroopa_Walk,
    STATUS_KEY_PARALYZE,  ANIM_KoopaTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_KoopaTroopa_Stunned,
    STATUS_KEY_UNUSED,    ANIM_KoopaTroopa_Stunned,
    STATUS_END,
};

s32 N(DownedFlippedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_KoopaTroopa_ToppleStruggle,
    STATUS_KEY_STONE,     ANIM_KoopaTroopa_ToppleStill,
    STATUS_KEY_SLEEP,     ANIM_KoopaTroopa_ToppleSleep,
    STATUS_KEY_POISON,    ANIM_KoopaTroopa_ToppleStruggle,
    STATUS_KEY_STOP,      ANIM_KoopaTroopa_ToppleStill,
    STATUS_KEY_STATIC,    ANIM_KoopaTroopa_ToppleStruggle,
    STATUS_KEY_PARALYZE,  ANIM_KoopaTroopa_ToppleStill,
    STATUS_KEY_DIZZY,     ANIM_KoopaTroopa_ToppleStunned,
    STATUS_KEY_UNUSED,    ANIM_KoopaTroopa_ToppleStunned,
    STATUS_END,
};

EvtScript N(EVS_Downed_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_Downed_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Downed_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_Downed_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_IsFlipped, false)
    Return
    End
};

EvtScript N(EVS_Downed_UpdateTargetOffsets) = {
    Switch(LVar0)
        CaseEq(0)
            IfFlag(LVar1, STATUS_FLAG_SLEEP | STATUS_FLAG_DIZZY)
                Call(SetTargetOffset, ACTOR_SELF, PRT_DOWNED, -5, 15)
                Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_DOWNED, 0, 0)
                Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
            Else
                Call(SetTargetOffset, ACTOR_SELF, PRT_DOWNED, -4, 32)
                Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_DOWNED, -1, -4)
                Call(N(SetAbsoluteStatusOffsets), -15, 32, 5, 32)
            EndIf
        CaseEq(1)
            Call(SetTargetOffset, ACTOR_SELF, PRT_DOWNED, -5, 15)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_DOWNED, 0, 0)
            Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Downed_Idle) = {
    Label(0)
        Call(RandInt, 80, LVarA)
        Add(LVarA, 80)
        Loop(LVarA)
            Label(1)
                Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                ExecWait(N(EVS_Downed_UpdateTargetOffsets))
                IfEq(LVar0, 1)
                    Wait(1)
                    Goto(1)
                EndIf
                IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    Wait(1)
                    Goto(1)
                EndIf
            Wait(1)
        EndLoop
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Call(SetActorIdleSpeed, ACTOR_SELF, Float(1.0))
        Call(SetIdleAnimations, ACTOR_SELF, PRT_DOWNED, Ref(N(DownedShuffleAnims)))
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleRunToGoal, ACTOR_SELF, 0)
        Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
        Switch(LVar0)
            CaseEq(0)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_DOWNED, Ref(N(DownedAnims)))
            CaseEq(1)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_DOWNED, Ref(N(DownedFlippedAnims)))
        EndSwitch
        Loop(20)
            Label(2)
                Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                ExecWait(N(EVS_Downed_UpdateTargetOffsets))
                IfEq(LVar0, 1)
                    Wait(1)
                    Goto(2)
                EndIf
                IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    Wait(1)
                    Goto(2)
                EndIf
            Wait(1)
        EndLoop
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Sub(LVar0, 5)
        Call(SetActorIdleSpeed, ACTOR_SELF, Float(1.0))
        Call(SetIdleAnimations, ACTOR_SELF, PRT_DOWNED, Ref(N(DownedShuffleAnims)))
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleRunToGoal, ACTOR_SELF, 0)
        Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
        Switch(LVar0)
            CaseEq(0)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_DOWNED, Ref(N(DownedAnims)))
            CaseEq(1)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_DOWNED, Ref(N(DownedFlippedAnims)))
        EndSwitch
        Loop(80)
            Label(3)
                Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
                Call(GetStatusFlags, ACTOR_SELF, LVar1)
                ExecWait(N(EVS_Downed_UpdateTargetOffsets))
                IfEq(LVar0, 1)
                    Wait(1)
                    Goto(3)
                EndIf
                IfFlag(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    Wait(1)
                    Goto(3)
                EndIf
            Wait(1)
        EndLoop
        Goto(0)
    Return
    End
};

s32 N(FlipPosOffsets)[] = { 9, 16, 22, 26, 30, 32, 33, 32, 30, 26, 22, 16, 9, 0, 4, 6, 7, 6, 4, 0, 2, 0 };

EvtScript N(EVS_Downed_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_DOWNED)
            SetConst(LVar1, ANIM_KoopaTroopa_Hurt)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_DOWNED)
            SetConst(LVar1, ANIM_KoopaTroopa_BurnHurt)
            SetConst(LVar2, ANIM_KoopaTroopa_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_DOWNED)
            SetConst(LVar1, ANIM_KoopaTroopa_BurnHurt)
            SetConst(LVar2, ANIM_KoopaTroopa_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_DOWNED)
            SetConst(LVar1, ANIM_KoopaTroopa_BurnStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_DOWNED)
            SetConst(LVar1, ANIM_KoopaTroopa_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_DOWNED)
            SetConst(LVar1, ANIM_KoopaTroopa_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_DOWNED)
            SetConst(LVar1, ANIM_KoopaTroopa_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_FLIP_TRIGGER)
            Call(SetActorVar, ACTOR_SELF, AVAR_IsFlipped, true)
            Call(SetActorVar, ACTOR_SELF, AVAR_FlippedTurns, 2)
            Call(SetDefenseTable, ACTOR_SELF, PRT_DOWNED, Ref(N(FlippedDefense)))
            Call(SetIdleAnimations, ACTOR_SELF, PRT_DOWNED, Ref(N(DownedFlippedAnims)))
            Call(SetTargetOffset, ACTOR_SELF, PRT_DOWNED, -5, 15)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_DOWNED, 0, 0)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, true)
            Call(SetAnimation, ACTOR_SELF, PRT_DOWNED, ANIM_KoopaTroopa_Hurt)
            Call(GetStatusFlags, ACTOR_SELF, LVarA)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
            ChildThread
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
            EndChildThread
            UseBuf(Ref(N(FlipPosOffsets)))
            Loop(ARRAY_COUNT(N(FlipPosOffsets)))
                BufRead1(LVar0)
                Call(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                Wait(1)
            EndLoop
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_DOWNED, ANIM_KoopaTroopa_ToppleStruggle)
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_DOWNED)
            SetConst(LVar1, ANIM_KoopaTroopa_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_DOWNED)
            SetConst(LVar1, ANIM_KoopaTroopa_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
            SetConst(LVar0, PRT_DOWNED)
            SetConst(LVar1, ANIM_KoopaTroopa_Run)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_DOWNED)
            SetConst(LVar1, ANIM_KoopaTroopa_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_DOWNED)
            SetConst(LVar1, ANIM_KoopaTroopa_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            IfEq(LVar0, 0)
                SetConst(LVar0, PRT_DOWNED)
                SetConst(LVar1, ANIM_KoopaTroopa_ShellEnter)
                ExecWait(EVS_Enemy_NoDamageHit)
                Call(GetStatusFlags, ACTOR_SELF, LVar0)
                IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                    Call(SetAnimation, ACTOR_SELF, PRT_DOWNED, ANIM_KoopaTroopa_ShellExit)
                    Wait(10)
                EndIf
            Else
                SetConst(LVar0, PRT_DOWNED)
                SetConst(LVar1, ANIM_KoopaTroopa_ToppleStruggle)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_DOWNED)
            SetConst(LVar1, ANIM_KoopaTroopa_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_DOWNED)
            SetConst(LVar1, ANIM_KoopaTroopa_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_END_FIRST_STRIKE)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            IfEq(LVar0, 0)
                SetConst(LVar0, PRT_DOWNED)
                SetConst(LVar1, ANIM_KoopaTroopa_Run)
                ExecWait(EVS_Enemy_ReturnHome)
            EndIf
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            IfEq(LVar0, 0)
                SetConst(LVar0, PRT_DOWNED)
                SetConst(LVar1, ANIM_KoopaTroopa_Idle)
                ExecWait(EVS_Enemy_Recover)
            Else
                SetConst(LVar0, PRT_DOWNED)
                SetConst(LVar1, ANIM_KoopaTroopa_ToppleStruggle)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
        CaseEq(EVENT_SCARE_AWAY)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            IfEq(LVar0, 0)
                SetConst(LVar0, PRT_DOWNED)
                SetConst(LVar1, ANIM_KoopaTroopa_Run)
                SetConst(LVar2, ANIM_KoopaTroopa_Hurt)
                ExecWait(EVS_Enemy_ScareAway)
                Return
            Else
                SetConst(LVar0, PRT_DOWNED)
                SetConst(LVar1, ANIM_KoopaTroopa_ToppleStruggle)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            IfEq(LVar0, 0)
                SetConst(LVar0, PRT_DOWNED)
                SetConst(LVar1, ANIM_KoopaTroopa_Panic)
            Else
                SetConst(LVar0, PRT_DOWNED)
                SetConst(LVar1, ANIM_KoopaTroopa_ToppleStruggle)
            EndIf
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            IfEq(LVar0, 0)
                SetConst(LVar0, PRT_DOWNED)
                SetConst(LVar1, ANIM_KoopaTroopa_Panic)
            Else
                SetConst(LVar0, PRT_DOWNED)
                SetConst(LVar1, ANIM_KoopaTroopa_ToppleStruggle)
            EndIf
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseEq(EVENT_AIR_LIFT_FAILED)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            IfEq(LVar0, 0)
                SetConst(LVar0, PRT_DOWNED)
                SetConst(LVar1, ANIM_KoopaTroopa_Idle)
                ExecWait(EVS_Enemy_NoDamageHit)
            Else
                SetConst(LVar0, PRT_DOWNED)
                SetConst(LVar1, ANIM_KoopaTroopa_ToppleStruggle)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Downed_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(SetAnimation, ACTOR_SELF, PRT_DOWNED, ANIM_KoopaTroopa_ShellSpin)
    Else
        Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
        IfEq(LVar0, 1)
            Call(GetActorVar, ACTOR_SELF, AVAR_FlippedTurns, LVar0)
            Sub(LVar0, 1)
            IfGt(LVar0, 0)
                Call(SetActorVar, ACTOR_SELF, AVAR_FlippedTurns, LVar0)
                Call(AddActorDecoration, ACTOR_SELF, PRT_DOWNED, 0, ACTOR_DECORATION_SWEAT)
                Call(SetAnimationRate, ACTOR_SELF, PRT_DOWNED, Float(3.0))
                Wait(30)
                Call(SetAnimationRate, ACTOR_SELF, PRT_DOWNED, Float(1.0))
                Call(RemoveActorDecoration, ACTOR_SELF, PRT_DOWNED, 0)
            Else
                Call(AddActorDecoration, ACTOR_SELF, PRT_DOWNED, 0, ACTOR_DECORATION_SWEAT)
                Call(SetAnimationRate, ACTOR_SELF, PRT_DOWNED, Float(3.0))
                Wait(20)
                Call(SetAnimationRate, ACTOR_SELF, PRT_DOWNED, Float(1.0))
                Call(RemoveActorDecoration, ACTOR_SELF, PRT_DOWNED, 0)
                Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_JUMP)
                Call(SetAnimation, ACTOR_SELF, PRT_DOWNED, ANIM_KoopaTroopa_ToppleStruggle)
                Set(LVar0, 0)
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
                ChildThread
                    Loop(5)
                        Add(LVar0, 15)
                        Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                        Wait(1)
                    EndLoop
                EndChildThread
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(SetActorJumpGravity, ACTOR_SELF, Float(3.0))
                Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_A)
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
                Call(SetAnimation, ACTOR_SELF, PRT_DOWNED, ANIM_KoopaTroopa_Idle)
                Call(SetActorVar, ACTOR_SELF, AVAR_IsFlipped, false)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_DOWNED, Ref(N(DownedAnims)))
                Call(SetDefenseTable, ACTOR_SELF, PRT_DOWNED, Ref(N(DownedDefense)))
                Call(SetTargetOffset, ACTOR_SELF, PRT_DOWNED, -4, 32)
                Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_DOWNED, -1, -4)
                Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLIPPED, false)
                Call(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
            EndIf
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndIf
        Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Wait(10)
        Call(SetAnimation, ACTOR_SELF, PRT_DOWNED, ANIM_KoopaTroopa_ShellEnter)
        Wait(10)
        ChildThread
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, 4)
            PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
            Wait(3)
            PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
            Wait(2)
            PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        EndChildThread
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_SPIN)
        Call(SetAnimation, ACTOR_SELF, PRT_DOWNED, ANIM_KoopaTroopa_ShellSpin)
        Wait(10)
        Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    EndIf
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SHELL_TOSS)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -40, 0, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(16.0))
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Call(GetBattlePhase, LVar0)
            IfEq(LVar0, PHASE_FIRST_STRIKE)
                Call(UseBattleCamPreset, BTL_CAM_ACTOR_TARGET_MIDPOINT)
                Call(SetBattleCamDist, 300)
                Call(SetBattleCamOffsetY, 20)
                Call(MoveBattleCamOver, 10)
                Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_DOWNED, ANIM_KoopaTroopa_ShellExit)
            Wait(8)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Wait(4)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_DOWNED, ANIM_KoopaTroopa_BeginPanic1)
            Wait(1)
            Call(SetAnimation, ACTOR_SELF, PRT_DOWNED, ANIM_KoopaTroopa_BeginPanic2)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(2.0))
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
            Call(SetAnimation, ACTOR_SELF, PRT_DOWNED, ANIM_KoopaTroopa_Panic)
            Wait(6)
            Sub(LVar1, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_DOWNED, 0, ACTOR_DECORATION_SWEAT)
            Call(SetAnimation, ACTOR_SELF, PRT_DOWNED, ANIM_KoopaTroopa_Panic)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Call(SetAnimation, ACTOR_SELF, PRT_DOWNED, ANIM_KoopaTroopa_Idle)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_DOWNED, 0)
            Call(SetPartYaw, ACTOR_SELF, PRT_DOWNED, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(16.0))
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, DMG_SHELL_TOSS, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
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
            Call(SetAnimation, ACTOR_SELF, PRT_DOWNED, ANIM_KoopaTroopa_ShellExit)
            Wait(8)
            Call(YieldTurn)
            SetConst(LVar0, PRT_DOWNED)
            SetConst(LVar1, ANIM_KoopaTroopa_Run)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetAnimation, ACTOR_SELF, PRT_DOWNED, ANIM_KoopaTroopa_Idle)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};
