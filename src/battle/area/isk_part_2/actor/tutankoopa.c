#include "../area.h"
#include "sprite/npc/Tutankoopa.h"
#include "sprite/npc/ChainChomp.h"
#include "sprite/npc/BuzzyBeetle.h"
#include "sprite/player.h"
#include "tutankoopa_common.h"

#define NAMESPACE A(tutankoopa)

extern ActorBlueprint A(chain_chomp);
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_Tutankoopa_SpinSmashHit);
extern EvtScript N(EVS_TemporaryKnockout);
extern EvtScript N(EVS_Attack_ThrowShell);
extern EvtScript N(EVS_Attack_DropDebris);
extern EvtScript N(EVS_DropDebris_Self);
extern EvtScript N(EVS_DropDebris_Players);
extern EvtScript N(EVS_Move_SummonChomp);
extern EvtScript N(EVS_SummonedChompHop);
extern EvtScript N(EVS_LevitateToHomePos);
extern EvtScript N(EVS_GetBackUp);
extern EvtScript N(EVS_Tutankoopa_Death);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_TARGET          = 2,
    PRT_SHELL_1         = 3,
    PRT_SHELL_2         = 4,
    PRT_SHELL_3         = 5,
    PRT_DEBRIS_1        = 6,
    PRT_DEBRIS_2        = 7,
    PRT_DEBRIS_3        = 8,
};

enum N(ActorVars) {
    AVAR_NextMove               = 0,
    AVAL_Move_Toss              = 0,
    AVAL_Move_DropDebris        = 1,

    AVAR_StunState              = 1,
    AVAL_State_Normal           = 0,
    AVAL_State_Stunned          = 2,

    AVAR_ShellsLeft             = 2,
    AVAR_HasSummoned            = 3, // false until a chomp has been summoned
    AVAR_Dialogue_Recover       = 4,
    AVAR_GateOpenAmount         = 5,
    AVAR_DebrisDropState        = 6,
    AVAR_Unknown                = 7,  // always zero
    AVAR_Stunned                = 8,  // overlapping usage with AVAR_StunState?
    AVAR_DoneFirstStrike        = 10, // unused
    AVAR_UsedSpikeTaunt         = 11, // unused dialogue toggle for spiky-taunting
    AVAR_NextSummonTime         = 12, // set by chomp actor when it dies
    AVAR_HittingSelf            = 13, // signal to HandleEvent to treat hit as self-inflicted
};

enum N(ActorParams) {
    DMG_DROP_DEBRIS_SELF        = 2,
    DMG_DROP_DEBRIS_PLAYER      = 2,
    DMG_DROP_DEBRIS_PARTNER     = 2,
    DMG_THROW_SHELL             = 3,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Tutankoopa_Idle,
    STATUS_KEY_STONE,     ANIM_Tutankoopa_Still,
    STATUS_KEY_SLEEP,     ANIM_Tutankoopa_Sleep,
    STATUS_KEY_POISON,    ANIM_Tutankoopa_Idle,
    STATUS_KEY_STOP,      ANIM_Tutankoopa_Still,
    STATUS_KEY_STATIC,    ANIM_Tutankoopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_Tutankoopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_Tutankoopa_Still,
    STATUS_KEY_DIZZY,     ANIM_Tutankoopa_Dizzy,
    STATUS_END,
};

s32 N(FallenAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Tutankoopa_Dizzy,
    STATUS_KEY_STONE,     ANIM_Tutankoopa_Fall,
    STATUS_KEY_SLEEP,     ANIM_Tutankoopa_SleepGround,
    STATUS_KEY_POISON,    ANIM_Tutankoopa_Dizzy,
    STATUS_KEY_STOP,      ANIM_Tutankoopa_Fall,
    STATUS_KEY_STATIC,    ANIM_Tutankoopa_Dizzy,
    STATUS_KEY_PARALYZE,  ANIM_Tutankoopa_Dizzy,
    STATUS_KEY_PARALYZE,  ANIM_Tutankoopa_Dizzy,
    STATUS_KEY_DIZZY,     ANIM_Tutankoopa_Dizzy,
    STATUS_END,
};

s32 N(BeetleShellAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BuzzyBeetle_Anim06,
    STATUS_END,
};

s32 N(RockAnimsA)[] = {
    STATUS_KEY_NORMAL,    ANIM_Tutankoopa_RockStill,
    STATUS_END,
};

s32 N(RockAnimsB)[] = {
    STATUS_KEY_NORMAL,    ANIM_Tutankoopa_RockStill,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              20,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              30,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           30,
    STATUS_KEY_SHRINK,             60,
    STATUS_KEY_STOP,               40,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 40 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_TARGET,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 39 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -5, -15 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_SKIP_SHOCK_EFFECT,
        .index = PRT_SHELL_1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(BeetleShellAnims),
        .defenseTable = nullptr,
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_SKIP_SHOCK_EFFECT,
        .index = PRT_SHELL_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(BeetleShellAnims),
        .defenseTable = nullptr,
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_SKIP_SHOCK_EFFECT,
        .index = PRT_SHELL_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(BeetleShellAnims),
        .defenseTable = nullptr,
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_DEBRIS_1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(RockAnimsA),
        .defenseTable = nullptr,
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_DEBRIS_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(RockAnimsA),
        .defenseTable = nullptr,
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_DEBRIS_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(RockAnimsB),
        .defenseTable = nullptr,
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_TUTANKOOPA,
    .level = ACTOR_LEVEL_TUTANKOOPA,
    .maxHP = 30,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 70,
    .coinReward = 0,
    .size = { 56, 45 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 35 },
    .statusTextOffset = { 10, 35 },
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

API_CALLABLE(SpawnFallingRock) {
    Bytecode* args = script->ptrReadPos;
    s32 posX = evt_get_variable(script, *args++);
    s32 floorY = evt_get_variable(script, *args++);
    s32 posZ = evt_get_variable(script, *args++);
    EffectInstance* effect = fx_floating_rock(2, posX, 150.0f, posZ, floorY, -0.5f, -0.9f, 0.5f, 60);

    effect->data.floatingRock->rotVel.x = 0;
    effect->data.floatingRock->rotVel.z = 0;
    effect->data.floatingRock->rotVel.y = 0;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(HPBarToHome, ACTOR_SELF)
    Call(ForceHomePos, ACTOR_SELF, 97, 70, 15)
    Call(SetPartPos, ACTOR_SELF, PRT_SHELL_1, 70, 70, 3)
    Call(SetPartPos, ACTOR_SELF, PRT_SHELL_2, 80, 70, -7)
    Call(SetPartPos, ACTOR_SELF, PRT_SHELL_3, 60, 70, -7)
    Call(SetActorVar, ACTOR_SELF, AVAR_Stunned, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Toss)
    Call(SetActorVar, ACTOR_SELF, AVAR_StunState, AVAL_State_Normal)
    Call(SetActorVar, ACTOR_SELF, AVAR_HasSummoned, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_Dialogue_Recover, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_ShellsLeft, 3)
    Call(SetActorVar, ACTOR_SELF, AVAR_DebrisDropState, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Unknown, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_DoneFirstStrike, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_UsedSpikeTaunt, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_NextSummonTime, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_HittingSelf, false)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
        Call(GetActorVar, ACTOR_SELF, AVAR_Stunned, LVar0)
        Switch(LVar0)
            CaseEq(0)
                Call(GetStatusFlags, ACTOR_SELF, LVar0)
                IfFlag(LVar0, STATUS_FLAG_DIZZY)
                    Call(SetTargetOffset, ACTOR_SELF, PRT_TARGET, -10, 22)
                    Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_TARGET, 2, -8)
                    Call(N(SetAbsoluteStatusOffsets), -25, 15, 0, 20)
                Else
                    Call(SetTargetOffset, ACTOR_SELF, PRT_TARGET, 0, 39)
                    Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_TARGET, -5, -15)
                    Call(N(SetAbsoluteStatusOffsets), -17, 23, 11, 32)
                EndIf
            CaseEq(1)
                Call(SetTargetOffset, ACTOR_SELF, PRT_TARGET, -10, 22)
                Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_TARGET, 2, -8)
                Call(N(SetAbsoluteStatusOffsets), -25, 15, 0, 20)
        EndSwitch
        Wait(1)
    Goto(0)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
    Call(GetLastElement, LVarE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Tutankoopa_Hurt)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Tutankoopa_Hurt)
            ExecWait(EVS_Enemy_Hit)
            // if damage is from "debris drop" backfiring, fall down and become stunned
            Call(GetActorVar, ACTOR_SELF, AVAR_HittingSelf, LVar2)
            IfTrue(LVar2)
                Call(SetActorVar, ACTOR_SELF, AVAR_HittingSelf, false)
                ExecWait(N(EVS_TemporaryKnockout))
            EndIf
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
        CaseEq(EVENT_BURN_HIT)
            Set(LVar0, PRT_MAIN)
            Set(LVar1, ANIM_Tutankoopa_BurnHurt)
            Set(LVar2, ANIM_Tutankoopa_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            Set(LVar0, PRT_MAIN)
            Set(LVar1, ANIM_Tutankoopa_BurnHurt)
            Set(LVar2, ANIM_Tutankoopa_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Tutankoopa_BurnStill)
            ExecWait(N(EVS_Tutankoopa_Death))
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            ExecWait(N(EVS_Tutankoopa_SpinSmashHit))
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Tutankoopa_Glare)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Tutankoopa_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Tutankoopa_Run)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Stunned, LVar1)
            IfEq(LVar1, true)
                Call(GetActorVar, ACTOR_SELF, AVAR_StunState, LVar1)
                IfNe(LVar1, AVAL_State_Normal)
                    SetConst(LVar1, ANIM_Tutankoopa_Dizzy)
                Else
                    SetConst(LVar1, ANIM_Tutankoopa_Idle)
                EndIf
            Else
                SetConst(LVar1, ANIM_Tutankoopa_Idle)
            EndIf
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_SPIKE_TAUNT)
            Call(GetActorVar, ACTOR_SELF, AVAR_StunState, LVar1)
            IfEq(LVar1, AVAL_State_Normal)
                IfFlag(LVarE, DAMAGE_TYPE_JUMP)
                    Call(GetActorVar, ACTOR_SELF, AVAR_UsedSpikeTaunt, LVar0)
                    IfEq(LVar0, false)
                        Call(SetActorVar, ACTOR_SELF, AVAR_UsedSpikeTaunt, true)
                        Wait(60)
                    EndIf
                EndIf
            EndIf
        CaseOrEq(EVENT_SHOCK_DEATH)
        CaseOrEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Tutankoopa_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Tutankoopa_Hurt)
            ExecWait(N(EVS_Tutankoopa_Death))
            Return
        EndCaseGroup
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            ExecWait(N(EVS_Tutankoopa_SpinSmashHit))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Tutankoopa_Hurt)
            ExecWait(N(EVS_Tutankoopa_Death))
            Return
        CaseEq(EVENT_SPIKE_CONTACT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Hurt)
            Wait(20)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Idle)
        CaseEq(EVENT_BURN_CONTACT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Hurt)
            Wait(20)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Run)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(RunToGoal, ACTOR_SELF, 0, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Idle)
        CaseEq(EVENT_END_FIRST_STRIKE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Tutankoopa_Idle)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Tutankoopa_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Tutankoopa_SpinSmashHit) = {
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Hurt)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.1))
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    Call(SetGoalPos, ACTOR_SELF, 150, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 0, false, true, false)
    Sub(LVar1, 20)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.1))
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetGoalPos, ACTOR_SELF, 130, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Fall)
    Wait(15)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Levitate)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Run)
    Call(RunToGoal, ACTOR_SELF, 10, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Idle)
    Return
    End
};

EvtScript N(EVS_TemporaryKnockout) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_Stunned, LVar0)
    IfEq(LVar0, true)
        Return
    EndIf
    Call(HideHealthBar, ACTOR_SELF)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_WITHER)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Hurt)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.9))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 10)
    Set(LVar1, 0)
    Add(LVar2, 24)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 16, false, true, false)
    Thread
        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.1), Float(0.5), Float(1.0))
        Wait(1)
        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.0), Float(0.7), Float(1.0))
        Wait(1)
        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.0), Float(1.0), Float(1.0))
    EndThread
    Call(StartRumble, BTL_RUMBLE_LONG)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_COLLAPSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Fall)
    Call(ShakeCam, CAM_BATTLE, 0, 5, Float(3.0))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 40)
    PlayEffect(EFFECT_STARS_ORBITING, 0, LVar0, LVar1, LVar2, 20, 4, LVarF, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Dizzy)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KNOCKOUT_CHIRPING)
    Wait(30)
    Call(RemoveEffect, LVarF)
    Call(SetActorVar, ACTOR_SELF, AVAR_Stunned, true)
    Call(SetActorVar, ACTOR_SELF, AVAR_Unknown, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_StunState, AVAL_State_Stunned)
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(FallenAnims)))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(HPBarToHome, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Label(0)
        Call(GetActorVar, ACTOR_SELF, AVAR_Stunned, LVar0)
        IfEq(LVar0, false)
            Call(ActorExists, ACTOR_CHOMP, LVar0)
            IfEq(LVar0, false)
                Call(GetActorVar, ACTOR_SELF, AVAR_NextSummonTime, LVar0)
                IfEq(LVar0, 0)
                    ExecWait(N(EVS_Move_SummonChomp))
                    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
                    Call(UseIdleAnimation, ACTOR_SELF, true)
                    Return
                Else
                    Sub(LVar0, 1)
                    Call(SetActorVar, ACTOR_SELF, AVAR_NextSummonTime, LVar0)
                EndIf
            EndIf
            // override to only use "drop debris" while shrunk
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfFlag(LVar0, STATUS_FLAG_SHRINK)
                Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_DropDebris)
            EndIf
            // select next attack, alternating between "throw shell" and "drop debris" when possible
            Call(GetActorVar, ACTOR_SELF, AVAR_NextMove, LVar0)
            Switch(LVar0)
                CaseEq(AVAL_Move_Toss)
                    Call(GetActorVar, ACTOR_SELF, AVAR_ShellsLeft, LVar0)
                    IfEq(LVar0, 0)
                        // always use "drop debris" after all shells are gone
                        ExecWait(N(EVS_Attack_DropDebris))
                        Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_DropDebris)
                    Else
                        // throw a shell if not shrunk
                        Call(GetStatusFlags, ACTOR_SELF, LVar0)
                        IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                            ExecWait(N(EVS_Attack_ThrowShell))
                            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_DropDebris)
                        Else
                            ExecWait(N(EVS_Attack_DropDebris))
                            Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Toss)
                        EndIf
                    EndIf
                CaseDefault
                    Call(SetActorVar, ACTOR_SELF, AVAR_NextMove, AVAL_Move_Toss)
                    ExecWait(N(EVS_Attack_DropDebris))
            EndSwitch
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        Else
            Call(SetActorVar, ACTOR_SELF, AVAR_Unknown, 0)
            Call(SetActorVar, ACTOR_SELF, AVAR_StunState, AVAL_State_Normal)
            ExecWait(N(EVS_GetBackUp))
            ExecWait(N(EVS_LevitateToHomePos))
            Goto(0)
        EndIf
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    Return
    End
};

EvtScript N(EVS_Attack_ThrowShell) = {
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetActorVar, ACTOR_SELF, AVAR_ShellsLeft, LVar0)
    // get actor part for the Nth remaining shell
    Switch(LVar0)
        CaseEq(1)
            Set(LVar9, PRT_SHELL_3)
        CaseEq(2)
            Set(LVar9, PRT_SHELL_2)
        CaseEq(3)
            Set(LVar9, PRT_SHELL_1)
        CaseDefault
            Return
    EndSwitch
    Sub(LVar0, 1)
    Call(SetActorVar, ACTOR_SELF, AVAR_ShellsLeft, LVar0)
    // begin the attack
    Call(UseBattleCamPreset, BTL_CAM_ACTOR_FAR)
    Call(SetBattleCamDist, 320)
    Call(SetBattleCamOffsetY, 0)
    Call(BattleCamTargetActorPart, ACTOR_SELF, LVar9)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Run)
    Call(GetPartOffset, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2)
    Add(LVar0, 20)
    Sub(LVar2, 3)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 10, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Idle)
    Wait(10)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Lift)
    Wait(7)
    Call(GetPartOffset, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2)
    Add(LVar0, 20)
    Add(LVar1, 40)
    Call(SetPartJumpGravity, ACTOR_SELF, LVar9, Float(0.8))
    Call(JumpPartTo, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2, 5, true)
    Wait(8)
    Call(SetAnimation, ACTOR_SELF, LVar9, ANIM_BuzzyBeetle_Anim05)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_TOSS)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Toss)
            Call(SetPartMoveSpeed, ACTOR_SELF, LVar9, Float(14.0))
            Call(SetPartJumpGravity, ACTOR_SELF, LVar9, Float(0.2))
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 50)
            Set(LVar1, -5)
            Call(FlyPartTo, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2, 0, 30, EASING_LINEAR)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Sub(LVar0, 65)
            Set(LVar1, -5)
            Call(SetPartMoveSpeed, ACTOR_SELF, LVar9, Float(6.0))
            Call(SetPartJumpGravity, ACTOR_SELF, LVar9, Float(0.1))
            Call(FlyPartTo, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2, 0, 15, EASING_LINEAR)
            Call(SetPartFlagBits, ACTOR_SELF, LVar9, ACTOR_PART_FLAG_INVISIBLE, true)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Run)
            Call(RunToGoal, ACTOR_SELF, 10, false)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Idle)
            Return
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Toss)
    Call(SetPartMoveSpeed, ACTOR_SELF, LVar9, Float(14.0))
    Call(SetPartJumpGravity, ACTOR_SELF, LVar9, Float(0.2))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetPartJumpGravity, ACTOR_SELF, LVar9, Float(0.2))
    Call(FlyPartTo, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2, 0, 30, EASING_LINEAR)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar8, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_THROW_SHELL, BS_FLAGS1_TRIGGER_EVENTS)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Sub(LVar0, 55)
    Set(LVar1, 0)
    Call(SetPartMoveSpeed, ACTOR_SELF, LVar9, Float(6.0))
    Call(SetPartJumpGravity, ACTOR_SELF, LVar9, Float(0.1))
    Call(FlyPartTo, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2, 0, 25, EASING_LINEAR)
    Call(SetPartMoveSpeed, ACTOR_SELF, LVar9, Float(4.0))
    Sub(LVar0, 20)
    Call(FlyPartTo, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2, 0, 21, EASING_LINEAR)
    Call(SetPartFlagBits, ACTOR_SELF, LVar9, ACTOR_PART_FLAG_INVISIBLE, true)
    Wait(19)
    IfEq(LVar8, HIT_RESULT_10)
        Return
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(YieldTurn)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Run)
    Call(RunToGoal, ACTOR_SELF, 10, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Idle)
    Return
    End
};

EvtScript N(EVS_Attack_DropDebris) = {
    Call(UseBattleCamPreset, BTL_CAM_ACTOR_FAR)
    Call(SetBattleCamDist, 350)
    Call(SetBattleCamOffsetY, 0)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 40)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetActorVar, ACTOR_SELF, AVAR_DebrisDropState, LVar0)
    IfEq(LVar0, 0)
        // first use only
        Call(UseBattleCamPreset, BTL_CAM_ACTOR_CLOSE)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 20)
        Wait(20)
        Call(ActorSpeak, MSG_CH2_00E5, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Shout, ANIM_Tutankoopa_Shout)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EndIf
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_TUTANKOOPA_MAGIC)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Shout)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    PlayEffect(EFFECT_HIEROGLYPHS, 0, LVar0, LVar1, LVar2, Float(1.0), 45, 0)
    Wait(30)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 70)
    Call(PlaySound, SOUND_SPOOKY_LEVITATE)
    PlayEffect(EFFECT_CHOMP_DROP, 0, 0, 60, 0, Float(0.2), 0, Float(1.4), 255, Float(0.1), 150, 0)
    Wait(15)
    Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
    IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED | STATUS_FLAG_TRANSPARENT)
        Call(UseIdleAnimation, ACTOR_PLAYER, false)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Flail)
        Wait(49)
        Call(PlaySound, SOUND_HEAVY_NPC_FALLING)
        Wait(5)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Toss)
        Wait(8)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Crouch)
        Wait(5)
        Call(StartRumble, BTL_RUMBLE_PLAYER_EXTREME)
        Call(PlaySound, SOUND_HEAVY_NPC_LANDING)
        Call(ShakeCam, CAM_BATTLE, 0, 5, Float(4.0))
        Wait(20)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Question)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar1, 20)
        PlayEffect(EFFECT_EMOTE, EMOTE_QUESTION, 0, LVar0, LVar1, LVar2, 20, 315, 30, 0, 0)
        Call(PlaySound, SOUND_ILLUSION_DISSOLVE)
    Else
        Wait(50)
        Call(PlaySound, SOUND_HEAVY_NPC_FALLING)
        Wait(18)
        Call(StartRumble, BTL_RUMBLE_PLAYER_EXTREME)
        Call(PlaySound, SOUND_HEAVY_NPC_LANDING)
        Wait(20)
        Call(PlaySound, SOUND_ILLUSION_DISSOLVE)
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_DebrisDropState, LVar0)
    Switch(LVar0)
        // first use: target player
        CaseEq(0)
            Call(SetActorVar, ACTOR_SELF, AVAR_DebrisDropState, 1)
            ExecWait(N(EVS_DropDebris_Players))
        // second use: target self if damage is survivable
        CaseEq(1)
            Call(GetActorHP, ACTOR_SELF, LVar0)
            Call(SetActorVar, ACTOR_SELF, AVAR_DebrisDropState, 2)
            IfGt(LVar0, DMG_DROP_DEBRIS_SELF)
                ExecWait(N(EVS_DropDebris_Self))
            Else
                ExecWait(N(EVS_DropDebris_Players))
            EndIf
        // subsequent use: 50% chance to target player or target self while damage is survivable
        CaseDefault
            Call(RandInt, 2, LVar0)
            IfEq(LVar0, 0)
                Call(GetActorHP, ACTOR_SELF, LVar0)
                IfGt(LVar0, DMG_DROP_DEBRIS_SELF)
                    ExecWait(N(EVS_DropDebris_Self))
                Else
                    ExecWait(N(EVS_DropDebris_Players))
                EndIf
            Else
                ExecWait(N(EVS_DropDebris_Players))
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_DropDebris_Self) = {
    Call(SetTargetActor, ACTOR_SELF, ACTOR_TUTANKOOPA)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar3, 170)
    Call(SetPartPos, ACTOR_SELF, PRT_DEBRIS_3, LVar0, LVar3, LVar2)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_DEBRIS_3, ACTOR_PART_FLAG_INVISIBLE, false)
    Call(SetAnimation, ACTOR_SELF, PRT_DEBRIS_3, ANIM_Tutankoopa_RockStill)
    Call(PlaySound, SOUND_TUTANKOOPA_DEBRIS_FALL)
    Call(SetPartMoveSpeed, ACTOR_SELF, PRT_DEBRIS_3, Float(8.0))
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_DEBRIS_3, Float(0.3))
    Call(FallPartTo, ACTOR_SELF, PRT_DEBRIS_3, LVar0, LVar1, LVar2, 20)
    Thread
        Loop(20)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_DEBRIS_3, ACTOR_PART_FLAG_INVISIBLE, false)
            Wait(1)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_DEBRIS_3, ACTOR_PART_FLAG_INVISIBLE, true)
            Wait(1)
        EndLoop
    EndThread
    Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
    IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_ThumbsUp)
    EndIf
    Call(SetActorVar, ACTOR_SELF, AVAR_HittingSelf, true)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, DMG_DROP_DEBRIS_SELF, BS_FLAGS1_TRIGGER_EVENTS)
    Return
    End
};

EvtScript N(EVS_DropDebris_Players) = {
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Thread
                Loop(6)
                    Call(RandInt, 120, LVar0)
                    Sub(LVar0, 150)
                    Call(RandInt, 90, LVar1)
                    Sub(LVar0, 40)
                    Call(PlaySound, SOUND_TUTANKOOPA_DEBRIS_FALL)
                    Call(SpawnFallingRock, LVar0, 0, LVar1)
                    Call(RandInt, 5, LVar0)
                    Add(LVar0, 5)
                    Wait(LVar0)
                EndLoop
            EndThread
            Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            Call(EnemyTestTarget, ACTOR_SELF, LVarB, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
            Switch(LVarB)
                CaseEq(HIT_RESULT_MISS)
                    Return
                CaseDefault
                    Call(FreezeBattleState, true)
                    Thread
                        Call(PlaySound, SOUND_TUTANKOOPA_DEBRIS_FALL)
                        Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                        Call(SetGoalToTarget, ACTOR_SELF)
                        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        Sub(LVar0, 5)
                        Set(LVar1, 0)
                        Set(LVar3, 170)
                        Call(SetPartPos, ACTOR_SELF, PRT_DEBRIS_1, LVar0, LVar3, LVar2)
                        Call(SetPartFlagBits, ACTOR_SELF, PRT_DEBRIS_1, ACTOR_PART_FLAG_INVISIBLE, false)
                        Call(SetAnimation, ACTOR_SELF, PRT_DEBRIS_1, ANIM_Tutankoopa_RockStill)
                        Call(SetPartMoveSpeed, ACTOR_SELF, PRT_DEBRIS_1, Float(8.0))
                        Call(SetPartJumpGravity, ACTOR_SELF, PRT_DEBRIS_1, Float(0.3))
                        Call(FallPartTo, ACTOR_SELF, PRT_DEBRIS_1, LVar0, LVar1, LVar2, 20)
                        Call(SetAnimation, ACTOR_SELF, PRT_DEBRIS_1, ANIM_Tutankoopa_RockShatter)
                        IfEq(LVarA, HIT_RESULT_LUCKY)
                            Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                        EndIf
                    EndThread
                    Wait(25)
                    Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                    Call(SetGoalToTarget, ACTOR_SELF)
                    Call(GetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    Sub(LVar4, 5)
                    Add(LVar5, 5)
                    Set(LVar7, 170)
                    Call(SetPartPos, ACTOR_SELF, PRT_DEBRIS_2, LVar4, LVar7, LVar6)
                    Call(SetPartFlagBits, ACTOR_SELF, PRT_DEBRIS_2, ACTOR_PART_FLAG_INVISIBLE, false)
                    Call(SetAnimation, ACTOR_SELF, PRT_DEBRIS_2, ANIM_Tutankoopa_RockStill)
                    Call(PlaySound, SOUND_TUTANKOOPA_DEBRIS_FALL)
                    Call(SetPartMoveSpeed, ACTOR_SELF, PRT_DEBRIS_2, Float(8.0))
                    Call(SetPartJumpGravity, ACTOR_SELF, PRT_DEBRIS_2, Float(0.3))
                    Call(FallPartTo, ACTOR_SELF, PRT_DEBRIS_2, LVar4, LVar5, LVar6, 20)
                    Call(SetAnimation, ACTOR_SELF, PRT_DEBRIS_1, ANIM_Tutankoopa_RockShatter)
                    Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                    Call(SetGoalToTarget, ACTOR_SELF)
                    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_DROP_DEBRIS_PARTNER, BS_FLAGS1_TRIGGER_EVENTS)
                    Wait(20)
                    Call(SetPartFlagBits, ACTOR_SELF, PRT_DEBRIS_2, ACTOR_PART_FLAG_INVISIBLE, true)
                    Call(FreezeBattleState, false)
                    Return
            EndSwitch
            Return
        EndCaseGroup
    EndSwitch
    Thread
        Loop(6)
            Call(RandInt, 120, LVar0)
            Sub(LVar0, 150)
            Call(RandInt, 90, LVar1)
            Sub(LVar0, 40)
            Call(PlaySound, SOUND_TUTANKOOPA_DEBRIS_FALL)
            Call(SpawnFallingRock, LVar0, 0, LVar1)
            Call(RandInt, 5, LVar0)
            Add(LVar0, 5)
            Wait(LVar0)
        EndLoop
    EndThread
    Call(FreezeBattleState, true)
    Thread
        Wait(25)
        Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
        Sub(LVar4, 5)
        Add(LVar5, 5)
        Set(LVar7, 170)
        Call(SetPartPos, ACTOR_SELF, PRT_DEBRIS_2, LVar4, LVar7, LVar6)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_DEBRIS_2, ACTOR_PART_FLAG_INVISIBLE, false)
        Call(SetAnimation, ACTOR_SELF, PRT_DEBRIS_2, ANIM_Tutankoopa_RockStill)
        Call(PlaySound, SOUND_TUTANKOOPA_DEBRIS_FALL)
        Call(SetPartMoveSpeed, ACTOR_SELF, PRT_DEBRIS_2, Float(8.0))
        Call(SetPartJumpGravity, ACTOR_SELF, PRT_DEBRIS_2, Float(0.3))
        Call(FallPartTo, ACTOR_SELF, PRT_DEBRIS_2, LVar4, LVar5, LVar6, 20)
        Call(SetAnimation, ACTOR_SELF, PRT_DEBRIS_1, ANIM_Tutankoopa_RockShatter)
        Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_DROP_DEBRIS_PARTNER, BS_FLAGS1_TRIGGER_EVENTS)
        Wait(20)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_DEBRIS_2, ACTOR_PART_FLAG_INVISIBLE, true)
        Call(FreezeBattleState, false)
    EndThread
    Call(PlaySound, SOUND_TUTANKOOPA_DEBRIS_FALL)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 5)
    Add(LVar1, 5)
    Set(LVar3, 170)
    Call(SetPartPos, ACTOR_SELF, PRT_DEBRIS_1, LVar0, LVar3, LVar2)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_DEBRIS_1, ACTOR_PART_FLAG_INVISIBLE, false)
    Call(SetAnimation, ACTOR_SELF, PRT_DEBRIS_1, ANIM_Tutankoopa_RockStill)
    Call(SetPartMoveSpeed, ACTOR_SELF, PRT_DEBRIS_1, Float(8.0))
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_DEBRIS_1, Float(0.3))
    Call(FallPartTo, ACTOR_SELF, PRT_DEBRIS_1, LVar0, LVar1, LVar2, 20)
    Call(SetAnimation, ACTOR_SELF, PRT_DEBRIS_1, ANIM_Tutankoopa_RockShatter)
    Wait(2)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_DROP_DEBRIS_PLAYER, BS_FLAGS1_TRIGGER_EVENTS)
    Wait(19)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_DEBRIS_1, ACTOR_PART_FLAG_INVISIBLE, true)
    IfEq(LVar0, HIT_RESULT_10)
        Return
    EndIf
    Return
    End
};

Vec3i N(SummonedChompPos) = { 190, 0, 0 };

Formation N(SummonedChomp) = {
    ACTOR_BY_POS(A(chain_chomp), N(SummonedChompPos), 100),
};

EvtScript N(EVS_Move_SummonChomp) = {
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    Call(GetActorVar, ACTOR_SELF, AVAR_HasSummoned, LVar0)
    IfFalse(LVar0)
        Call(UseBattleCamPreset, BTL_CAM_ACTOR_CLOSE)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 20)
        Wait(20)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Shout)
        Call(ActorSpeak, MSG_CH2_00E6, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Shout, ANIM_Tutankoopa_Shout)
    Else
        Call(UseBattleCamPreset, BTL_CAM_ACTOR_CLOSE)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 20)
        Wait(20)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Shout)
        Call(ActorSpeak, MSG_CH2_00E7, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Shout, ANIM_Tutankoopa_Shout)
    EndIf
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Idle)
    Call(GetActorVar, ACTOR_SELF, AVAR_Stunned, LVar0)
    IfEq(LVar0, 0)
        Call(UseBattleCamPreset, BTL_CAM_ACTOR_CLOSE)
        Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
        Call(SetBattleCamDist, 225)
        Call(SetBattleCamOffsetY, -30)
        Call(MoveBattleCamOver, 40)
    Else
        Call(UseBattleCamPreset, BTL_CAM_ACTOR_CLOSE)
        Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
        Call(SetBattleCamDist, 200)
        Call(SetBattleCamOffsetY, 35)
        Call(MoveBattleCamOver, 40)
    EndIf
    // open the gate
    Call(SetActorVar, ACTOR_SELF, AVAR_GateOpenAmount, 0)
    Thread
        // rumble while gate is opening
        Label(0)
            Call(StartRumble, BTL_RUMBLE_LONG)
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
            Wait(1)
            Call(GetActorVar, ACTOR_SELF, AVAR_GateOpenAmount, LVar0)
            IfLt(LVar0, 60)
                Goto(0)
            EndIf
    EndThread
    Call(PlaySound, SOUND_LARGE_GATE_OPEN)
    Label(10)
        Call(GetActorVar, ACTOR_SELF, AVAR_GateOpenAmount, LVarD)
        Call(TranslateModel, 31, 0, LVarD, 0)
        Add(LVarD, 1)
        Call(SetActorVar, ACTOR_SELF, AVAR_GateOpenAmount, LVarD)
        Wait(1)
        IfLt(LVarD, 60)
            Goto(10)
        EndIf
    Call(StopSound, SOUND_LARGE_GATE_OPEN)
    Wait(10)
    // create the chomp and have him exit the gate
    Call(SummonEnemy, Ref(N(SummonedChomp)), false)
    Set(LVarB, LVar0)
    Set(LVar0, 165)
    Set(LVar1, 0)
    Set(LVar2, -30)
    Call(SetActorPos, LVarB, LVar0, LVar1, LVar2)
    Call(SetActorDispOffset, LVarB, 0, 0, 0)
    Call(UseIdleAnimation, LVarB, false)
    Call(EnableIdleScript, LVarB, IDLE_SCRIPT_DISABLE)
    Call(SetAnimation, LVarB, 1, ANIM_ChainChomp_SlowBite)
    Call(SetActorSpeed, LVarB, Float(6.0))
    Call(SetActorJumpGravity, LVarB, Float(0.8))
    Set(LVar0, 90)
    Set(LVar1, 0)
    Set(LVar2, -30)
    Set(LVar3, 8)
    Set(LVar4, 30)
    ExecWait(N(EVS_SummonedChompHop))
    Call(GetActorVar, ACTOR_SELF, AVAR_HasSummoned, LVar5)
    IfFalse(LVar5)
        Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
        Call(SetBattleCamDist, 160)
        Call(GetActorPos, LVarB, LVar0, LVar1, LVar2)
        Set(LVar1, 60)
        Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
        Call(MoveBattleCamOver, 8)
        Loop(3)
            Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
            Call(SetBattleCamDist, 150)
            Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
            Call(MoveBattleCamOver, 5)
            Wait(4)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_BITE)
            Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
            Call(SetBattleCamDist, 200)
            Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
            Call(MoveBattleCamOver, 5)
            Wait(4)
        EndLoop
    Else
        Wait(8)
        Call(SetGoalPos, LVarB, LVar0, LVar1, LVar2)
        Call(JumpToGoal, LVarB, 8, false, true, false)
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
        EndThread
        Call(SetGoalPos, LVarB, LVar0, LVar1, LVar2)
        Call(JumpToGoal, LVarB, 8, false, true, false)
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
        EndThread
        Wait(8)
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Call(SetActorSpeed, LVarB, Float(3.0))
    Call(SetActorJumpGravity, LVarB, Float(0.8))
    Set(LVar0, 20)
    Set(LVar1, 0)
    Set(LVar2, 20)
    Set(LVar3, 8)
    Set(LVar4, 20)
    ExecWait(N(EVS_SummonedChompHop))
    Call(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    Call(ForceHomePos, LVarB, LVar0, LVar1, LVar2)
    Call(SetPartPos, LVarB, 2, LVar0, LVar1, LVar2) // references partID from chain_chomp
    Call(HPBarToHome, LVarB)
    Call(SetActorSpeed, LVarB, Float(6.0))
    Call(SetActorJumpGravity, LVarB, Float(0.8))
    Call(EnableIdleScript, LVarB, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, LVarB, true)
    // close the gate
    Call(SetActorVar, ACTOR_SELF, AVAR_GateOpenAmount, 60)
    Thread
        // rumble while gate is opening
        Label(40)
            Call(StartRumble, BTL_RUMBLE_LONG)
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
            Wait(1)
            Call(GetActorVar, ACTOR_SELF, AVAR_GateOpenAmount, LVar0)
            IfNe(LVar0, 0)
                Goto(40)
            EndIf
        EndThread
    Call(PlaySound, SOUND_LARGE_GATE_OPEN)
    Label(50)
        Call(GetActorVar, ACTOR_SELF, AVAR_GateOpenAmount, LVarD)
        Call(TranslateModel, 31, 0, LVarD, 0)
        Sub(LVarD, 1)
        Call(SetActorVar, ACTOR_SELF, AVAR_GateOpenAmount, LVarD)
        Wait(1)
        IfGt(LVarD, 0)
            Goto(50)
    EndIf
    Call(StopSound, SOUND_LARGE_GATE_OPEN)
    Call(PlaySound, SOUND_LARGE_GATE_CLOSE)
    Call(ShakeCam, CAM_BATTLE, 0, 4, Float(0.5))
    Call(SetActorVar, ACTOR_SELF, AVAR_HasSummoned, true)
    Return
    End
};

EvtScript N(EVS_SummonedChompHop) = {
    Label(20)
    Call(GetActorPos, LVarB, LVar5, LVar6, LVar7)
    IfEq(LVar5, LVar0)
        Goto(30)
    EndIf
    Set(LVar6, LVar5)
    Sub(LVar6, LVar0)
    IfLt(LVar6, LVar4)
        Call(SetGoalPos, LVarB, LVar0, LVar1, LVar2)
        Call(JumpToGoal, LVarB, LVar3, false, true, false)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
        EndThread
    Else
        Sub(LVar5, LVar4)
        Call(SetGoalPos, LVarB, LVar5, LVar1, LVar2)
        Call(JumpToGoal, LVarB, LVar3, false, true, false)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
        Thread
            Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
        EndThread
    EndIf
    Goto(20)
    Label(30)
    Return
    End
};

EvtScript N(EVS_LevitateToHomePos) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_Unknown, 0)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR_CLOSE)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_TUTANKOOPA_MAGIC)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Levitate)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    PlayEffect(EFFECT_HIEROGLYPHS, 0, LVar0, LVar1, LVar2, Float(1.0), 45, 0)
    Wait(45)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 60)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_TUTANKOOPA_LEVITATE)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.1))
    Call(SetGoalPos, ACTOR_SELF, 97, 70, 15)
    Call(JumpToGoal, ACTOR_SELF, 45, false, true, false)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_A)
    Thread
        Wait(1)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_B)
    EndThread
    Wait(5)
    Call(SetActorVar, ACTOR_SELF, AVAR_Stunned, false)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(HPBarToHome, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_GetBackUp) = {
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Levitate)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_A)
    Thread
        Wait(1)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_B)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Idle)
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
    Wait(10)
    Call(GetActorVar, ACTOR_SELF, AVAR_Dialogue_Recover, LVar0)
    IfFalse(LVar0)
        Call(UseBattleCamPreset, BTL_CAM_ACTOR_CLOSE)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 20)
        Wait(20)
        Call(ActorSpeak, MSG_CH2_00E4, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Talk, ANIM_Tutankoopa_Idle)
        Call(SetActorVar, ACTOR_SELF, AVAR_Dialogue_Recover, true)
    EndIf
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_DoneFirstStrike, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    Call(SetActorVar, ACTOR_SELF, AVAR_DoneFirstStrike, true)
            EndSwitch
    EndSwitch
    Return
    End
};

// kills the summoned chomp before dying
EvtScript N(EVS_Tutankoopa_Death) = {
    Call(ActorExists, ACTOR_CHOMP, LVar2)
    IfNe(LVar2, false)
        Call(GetActorHP, ACTOR_CHOMP, LVar2)
        IfNe(LVar2, 0)
            Thread
                Call(HideHealthBar, ACTOR_CHOMP)
                Call(EnableIdleScript, ACTOR_CHOMP, IDLE_SCRIPT_DISABLE)
                Call(UseIdleAnimation, ACTOR_CHOMP, false)
                Call(SetAnimation, ACTOR_CHOMP, PRT_MAIN, ANIM_ChainChomp_Hurt)
                Wait(10)
                Set(LVar2, 0)
                Loop(24)
                    Call(SetActorYaw, ACTOR_CHOMP, LVar2)
                    Add(LVar2, 30)
                    Wait(1)
                EndLoop
                Call(SetActorYaw, ACTOR_CHOMP, 0)
                Call(GetActorPos, ACTOR_CHOMP, LVar0, LVar1, LVar2)
                Add(LVar1, 10)
                PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
                Call(PlaySoundAtActor, ACTOR_CHOMP, SOUND_ACTOR_DEATH)
                Set(LVar3, 0)
                Loop(12)
                    Call(SetActorRotation, ACTOR_CHOMP, LVar3, 0, 0)
                    Add(LVar3, 8)
                    Wait(1)
                EndLoop
                Call(RemoveActor, ACTOR_CHOMP)
            EndThread
        EndIf
    EndIf
    ExecWait(EVS_Enemy_DeathWithoutRemove)
    Label(0)
        Call(ActorExists, ACTOR_CHOMP, LVar0)
        IfNe(LVar0, false)
            Wait(1)
            Goto(0)
        EndIf
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};
