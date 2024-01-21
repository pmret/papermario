#include "../area.h"
#include "sprite/npc/ChainChomp.h"
#include "sprite/npc/Tutankoopa.h"
#include "tutankoopa_common.h"

#define NAMESPACE A(chain_chomp)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_UpdateChain);
extern EvtScript N(EVS_Chomp_SpinSmashHit);
extern EvtScript N(EVS_Chomp_HopHome);
extern EvtScript N(EVS_Chomp_HopToPos);

enum N(ActorVars) {
    AVAR_EnableChainSounds      = 8,
};

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_TARGET          = 2,
    PRT_CHAIN_1         = 3,
    PRT_CHAIN_2         = 4,
    PRT_CHAIN_3         = 5,
    PRT_CHAIN_4         = 6,
    PRT_CHAIN_5         = 7,
    PRT_CHAIN_6         = 8,
    PRT_CHAIN_7         = 9,
    PRT_CHAIN_8         = 10,
};

enum N(ActorParams) {
    DMG_CHOMP_BITE      = 3,
};

s32 N(BasicAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ChainChomp_Idle,
    STATUS_KEY_STONE,     ANIM_ChainChomp_Still,
    STATUS_KEY_SLEEP,     ANIM_ChainChomp_Sleep,
    STATUS_KEY_POISON,    ANIM_ChainChomp_Idle,
    STATUS_KEY_STOP,      ANIM_ChainChomp_Still,
    STATUS_KEY_STATIC,    ANIM_ChainChomp_Still,
    STATUS_KEY_PARALYZE,  ANIM_ChainChomp_Still,
    STATUS_KEY_DIZZY,     ANIM_ChainChomp_Dizzy,
    STATUS_END,
};

s32 N(QuickBiteAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ChainChomp_QuickBite,
    STATUS_KEY_POISON,    ANIM_ChainChomp_QuickBite,
    STATUS_KEY_STOP,      ANIM_ChainChomp_Still,
    STATUS_KEY_STONE,     ANIM_ChainChomp_Still,
    STATUS_KEY_SLEEP,     ANIM_ChainChomp_Sleep,
    STATUS_KEY_STATIC,    ANIM_ChainChomp_Still,
    STATUS_KEY_PARALYZE,  ANIM_ChainChomp_Still,
    STATUS_KEY_DIZZY,     ANIM_ChainChomp_Dizzy,
    STATUS_END,
};

s32 N(BiteAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ChainChomp_Bite,
    STATUS_KEY_POISON,    ANIM_ChainChomp_Bite,
    STATUS_KEY_STOP,      ANIM_ChainChomp_Still,
    STATUS_KEY_STONE,     ANIM_ChainChomp_Still,
    STATUS_KEY_SLEEP,     ANIM_ChainChomp_Sleep,
    STATUS_KEY_STATIC,    ANIM_ChainChomp_Still,
    STATUS_KEY_PARALYZE,  ANIM_ChainChomp_Still,
    STATUS_KEY_DIZZY,     ANIM_ChainChomp_Dizzy,
    STATUS_END,
};

s32 N(SlowBiteAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ChainChomp_SlowBite,
    STATUS_KEY_POISON,    ANIM_ChainChomp_SlowBite,
    STATUS_KEY_STOP,      ANIM_ChainChomp_Still,
    STATUS_KEY_STONE,     ANIM_ChainChomp_Still,
    STATUS_KEY_SLEEP,     ANIM_ChainChomp_Sleep,
    STATUS_KEY_STATIC,    ANIM_ChainChomp_Still,
    STATUS_KEY_PARALYZE,  ANIM_ChainChomp_Still,
    STATUS_KEY_DIZZY,     ANIM_ChainChomp_Dizzy,
    STATUS_END,
};

s32 N(ChainAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ChainChomp_Chain,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   3,
    ELEMENT_SHOCK,    3,
    ELEMENT_FIRE,    99,
    ELEMENT_ICE,     99,
    ELEMENT_MAGIC,   99,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,             75,
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
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(BasicAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_TARGET,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -13, 40 },
        .opacity = 255,
        .idleAnimations = N(BasicAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -16 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_TARGET_ONLY | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_CHAIN_1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(ChainAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_TARGET_ONLY | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_CHAIN_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(ChainAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_TARGET_ONLY | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_CHAIN_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(ChainAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_TARGET_ONLY | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_CHAIN_4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(ChainAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_TARGET_ONLY | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_CHAIN_5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(ChainAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_TARGET_ONLY | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_CHAIN_6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(ChainAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_TARGET_ONLY | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_CHAIN_7,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(ChainAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_TARGET_ONLY | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_CHAIN_8,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(ChainAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_CHOMP,
    .level = ACTOR_LEVEL_CHOMP,
    .maxHP = 4,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 95,
    .coinReward = 0,
    .size = { 56, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

#define CHOMP_CHAIN_FIRST_PART_IDX  PRT_CHAIN_1
#define CHOMP_CHAIN_LAST_PART_IDX   PRT_CHAIN_8
#define CHOMP_CHAIN_AVAR_SOUNDS     AVAR_EnableChainSounds
#define CHOMP_CHAIN_UPDATE_Z        TRUE
#include "common/battle/ChompChainSupport.inc.c"

API_CALLABLE(func_8021866C_4EFB0C) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = *args++;

    evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Init) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_EnableChainSounds, FALSE)
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetPartPos, ACTOR_SELF, PRT_TARGET, LVar0, LVar1, LVar2)
    Set(LVar0, PRT_CHAIN_1)
    Loop(1 + (PRT_CHAIN_8 - PRT_CHAIN_1))
        Call(SetPartSize, ACTOR_SELF, LVar0, 16, 16)
        Add(LVar0, 1)
    EndLoop
    Call(N(ChompChainInit))
    Exec(N(EVS_UpdateChain))
    Return
    End
};

EvtScript N(EVS_UpdateTargetPartPos) = {
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetPartPos, ACTOR_SELF, PRT_TARGET, LVar0, LVar1, LVar2)
        Call(SetTargetOffset, ACTOR_SELF, PRT_TARGET, 0, 24)
        Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_TARGET, 0, 0)
    Else
        Call(SetIdleGoalToHome, ACTOR_SELF)
        Call(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetPartPos, ACTOR_SELF, PRT_TARGET, LVar0, LVar1, LVar2)
        Call(SetTargetOffset, ACTOR_SELF, PRT_TARGET, -13, 40)
        Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_TARGET, 0, -14)
    EndIf
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
        Loop(0)
            ExecWait(N(EVS_UpdateTargetPartPos))
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(SlowBiteAnims)))
        Call(SetActorIdleJumpGravity, ACTOR_SELF, Float(1.0))
        Call(SetIdleGoalToHome, ACTOR_SELF)
        Call(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 10)
        Call(SetActorIdleJumpGravity, ACTOR_SELF, Float(0.8))
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleJumpToGoal, ACTOR_SELF, 11, 1)
        Loop(0)
            ExecWait(N(EVS_UpdateTargetPartPos))
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        Call(SetActorIdleJumpGravity, ACTOR_SELF, Float(1.0))
        Call(SetIdleGoalToHome, ACTOR_SELF)
        Call(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleJumpToGoal, ACTOR_SELF, 6, 1)
        Call(RandInt, 10, LVar0)
        Add(LVar0, 1)
        Wait(LVar0)
        Loop(0)
            ExecWait(N(EVS_UpdateTargetPartPos))
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(BiteAnims)))
        Call(SetActorIdleJumpGravity, ACTOR_SELF, Float(0.8))
        Call(SetIdleGoalToHome, ACTOR_SELF)
        Call(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleJumpToGoal, ACTOR_SELF, 15, 1)
        Loop(0)
            ExecWait(N(EVS_UpdateTargetPartPos))
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(SlowBiteAnims)))
        Call(SetActorIdleJumpGravity, ACTOR_SELF, Float(0.8))
        Call(SetIdleGoalToHome, ACTOR_SELF)
        Call(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Sub(LVar0, 20)
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleJumpToGoal, ACTOR_SELF, 12, 1)
        Loop(0)
            ExecWait(N(EVS_UpdateTargetPartPos))
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        Call(SetActorIdleJumpGravity, ACTOR_SELF, Float(0.8))
        Call(SetIdleGoalToHome, ACTOR_SELF)
        Call(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Sub(LVar0, 10)
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleJumpToGoal, ACTOR_SELF, 9, 1)
        Loop(0)
            ExecWait(N(EVS_UpdateTargetPartPos))
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(QuickBiteAnims)))
        Call(SetActorIdleJumpGravity, ACTOR_SELF, Float(0.8))
        Call(SetIdleGoalToHome, ACTOR_SELF)
        Call(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleJumpToGoal, ACTOR_SELF, 6, 1)
        Call(RandInt, 10, LVar0)
        Add(LVar0, 10)
        Wait(LVar0)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_UpdateChain) = {
    Label(0)
        Wait(1)
        Call(ActorExists, ACTOR_CHOMP, LVar0)
        IfEq(LVar0, TRUE)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(N(ChompChainUpdate), LVar2)
            Goto(0)
        EndIf
    Label(1)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Set(LVarF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Hurt)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Hurt)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Hurt)
            SetConst(LVar2, -1)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Hurt)
            SetConst(LVar2, -1)
            ExecWait(EVS_Enemy_BurnHit)
            Wait(10)
            Call(SetActorVar, ACTOR_TUTANKOOPA, AVAR_Tutankoopa_NextSummonTime, 2)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Hurt)
            ExecWait(N(EVS_Chomp_SpinSmashHit))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Hurt)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.4))
            Call(AddGoalPos, ACTOR_SELF, 30, 0, 0)
            Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            Call(AddGoalPos, ACTOR_SELF, 15, 0, 0)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            Call(AddGoalPos, ACTOR_SELF, 5, 0, 0)
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_SlowBite)
            ExecWait(N(EVS_Chomp_HopHome))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
            Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
            EndThread
            Call(SetGoalToHome, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetPartPos, ACTOR_SELF, PRT_TARGET, LVar0, LVar1, LVar2)
            Call(SetActorVar, ACTOR_SELF, AVAR_EnableChainSounds, FALSE)
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            Call(GetStatusFlags, ACTOR_SELF, LVar0)
            IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                Call(SetGoalToHome, ACTOR_SELF)
                Call(GetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
                IfFlag(LVar0, STATUS_FLAG_SHRINK)
                    Sub(LVar1, 10)
                    Add(LVar2, 4)
                Else
                    Sub(LVar1, 5)
                    Add(LVar2, 11)
                EndIf
                Call(SetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            EndIf
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Hurt)
            ExecWait(EVS_Enemy_AirLift)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Hurt)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            Call(SetActorVar, ACTOR_SELF, AVAR_EnableChainSounds, FALSE)
            Wait(10)
            Call(SetActorVar, ACTOR_TUTANKOOPA, AVAR_Tutankoopa_NextSummonTime, 2)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            Call(SetActorVar, ACTOR_TUTANKOOPA, AVAR_Tutankoopa_NextSummonTime, 2)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Hurt)
            ExecWait(N(EVS_Chomp_SpinSmashHit))
            Call(SetActorVar, ACTOR_TUTANKOOPA, AVAR_Tutankoopa_NextSummonTime, 2)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseDefault
    EndSwitch
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        IfNe(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
            Call(FallToGoal, ACTOR_SELF, 11)
        EndIf
    EndIf
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Chomp_SpinSmashHit) = {
    Call(ActorExists, ACTOR_TUTANKOOPA, LVar0)
    IfEq(LVar0, FALSE)
        Goto(1)
    EndIf
    Call(GetActorVar, ACTOR_TUTANKOOPA, AVAR_Tutankoopa_Stunned, LVar0)
    IfEq(LVar0, 0)
        Goto(1)
    EndIf
    Label(0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_Hurt)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_TUTANKOOPA)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, 20, LVar2)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.1))
    Call(SetActorSpeed, ACTOR_SELF, Float(7.0))
    Call(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.0))
    EndThread
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.1))
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, 150, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    Thread
        Call(GetStatusFlags, ACTOR_SELF, LVar0)
        IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
            Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
        EndIf
    EndThread
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetGoalPos, ACTOR_SELF, 130, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    Thread
        Call(GetStatusFlags, ACTOR_SELF, LVar0)
        IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
            Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
        EndIf
    EndThread
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Wait(15)
    Goto(10)
    Label(1)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_Hurt)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.1))
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, 135, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    Thread
        Call(GetStatusFlags, ACTOR_SELF, LVar0)
        IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
            Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
        EndIf
    EndThread
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetGoalPos, ACTOR_SELF, 105, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    Thread
        Call(GetStatusFlags, ACTOR_SELF, LVar0)
        IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
            Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
        EndIf
    EndThread
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Wait(15)
    Label(10)
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_ChainChomp_Idle)
    ExecWait(N(EVS_Chomp_HopHome))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Tutankoopa_Idle)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_EnableChainSounds, TRUE)
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, 0)
    Add(LVar0, 45)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
    Thread
        Call(GetStatusFlags, ACTOR_SELF, LVar0)
        IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
            Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
        EndIf
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_SlowBite)
    Wait(15)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_HURT)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(PlaySound, SOUND_ACTOR_HURT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_Idle)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 20)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            Thread
                Call(GetStatusFlags, ACTOR_SELF, LVar0)
                IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                    Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
                EndIf
            EndThread
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 25)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            Thread
                Call(GetStatusFlags, ACTOR_SELF, LVar0)
                IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                    Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
                EndIf
            EndThread
            Sub(LVar0, 15)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            Thread
                Call(GetStatusFlags, ACTOR_SELF, LVar0)
                IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                    Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
                EndIf
            EndThread
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_Bite)
            Wait(20)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Idle)
            ExecWait(N(EVS_Chomp_HopHome))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_Idle)
            Call(HPBarToHome, ACTOR_SELF)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetActorVar, ACTOR_SELF, AVAR_EnableChainSounds, FALSE)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_Idle)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        Add(LVar0, 4)
    Else
        Add(LVar0, 10)
    EndIf
    Set(LVar1, 27)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.2))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    Wait(2)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetPartPos, ACTOR_SELF, PRT_TARGET, LVar0, LVar1, LVar2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, DMG_CHOMP_BITE, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVarF)
        CaseDefault
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_Bite)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            Thread
                Call(GetStatusFlags, ACTOR_SELF, LVar0)
                IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                    Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
                EndIf
            EndThread
            Add(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            Thread
                Call(GetStatusFlags, ACTOR_SELF, LVar0)
                IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                    Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
                EndIf
            EndThread
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            Thread
                Call(GetStatusFlags, ACTOR_SELF, LVar0)
                IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                    Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
                EndIf
            EndThread
            Sub(LVar0, 10)
            Call(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
            Thread
                Call(GetStatusFlags, ACTOR_SELF, LVar0)
                IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                    Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
                EndIf
            EndThread
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_Idle)
            Wait(8)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            IfEq(LVarF, HIT_RESULT_10)
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(SetPartPos, ACTOR_SELF, PRT_TARGET, LVar0, LVar1, LVar2)
                Return
            EndIf
            Call(YieldTurn)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ChainChomp_Idle)
            ExecWait(N(EVS_Chomp_HopHome))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_Idle)
    EndSwitch
    Call(SetActorVar, ACTOR_SELF, AVAR_EnableChainSounds, FALSE)
    Call(HPBarToHome, ACTOR_SELF)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

// Custom version of EVS_Enemy_HopHome
// (in) LVar0: part idx
// (in) LVar1: hopping animID
EvtScript N(EVS_Chomp_HopHome) = {
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ChainChomp_Bite)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetGoalToHome, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    ExecWait(N(EVS_Chomp_HopToPos))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetPartPos, ACTOR_SELF, PRT_TARGET, LVar0, LVar1, LVar2)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Return
    End
};

// Custom version of EVS_Enemy_HopToPos
// (in) LVar0: target posX
// (in) LVar1: target posY
// (in) LVar2: target posZ
EvtScript N(EVS_Chomp_HopToPos) = {
    Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    IfLt(LVar3, LVar0)
        Call(SetActorYaw, ACTOR_SELF, 180)
    Else
        Call(SetActorYaw, ACTOR_SELF, 0)
    EndIf
    Label(0)
        Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        IfEq(LVar3, LVar0)
            Goto(10)
        EndIf
        IfLt(LVar3, LVar0)
            Set(LVar4, LVar0)
            Sub(LVar4, LVar3)
            IfLt(LVar4, 30)
                Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
                Thread
                    Call(GetStatusFlags, ACTOR_SELF, LVar0)
                    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                        Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
                    EndIf
                EndThread
            Else
                Set(LVar4, LVar3)
                Add(LVar3, 30)
                Call(SetGoalPos, ACTOR_SELF, LVar3, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
                Thread
                    Call(GetStatusFlags, ACTOR_SELF, LVar0)
                    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                        Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
                    EndIf
                EndThread
            EndIf
        Else
            Set(LVar4, LVar3)
            Sub(LVar4, LVar0)
            IfLt(LVar4, 30)
                Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
                Thread
                    Call(GetStatusFlags, ACTOR_SELF, LVar0)
                    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                        Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
                    EndIf
                EndThread
            Else
                Sub(LVar3, 30)
                Call(SetGoalPos, ACTOR_SELF, LVar3, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHAIN_CHOMP_THUD)
                Thread
                    Call(GetStatusFlags, ACTOR_SELF, LVar0)
                    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                        Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
                    EndIf
                EndThread
            EndIf
        EndIf
        Goto(0)
    Label(10)
    Return
    End
};
