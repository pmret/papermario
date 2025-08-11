#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/StoneChomp.h"

#define NAMESPACE A(stone_chomp)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Chomp_HopToPos);
extern EvtScript N(EVS_UpdateChain);

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

enum N(ActorVars) {
    AVAR_EnableChainSounds      = 8,
};

enum N(ActorParams) {
    DMG_CHOMP_BITE              = 3,
};

s32 N(BasicAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_StoneChomp_Idle,
    STATUS_KEY_STONE,     ANIM_StoneChomp_Still,
    STATUS_KEY_SLEEP,     ANIM_StoneChomp_Sleep,
    STATUS_KEY_POISON,    ANIM_StoneChomp_Idle,
    STATUS_KEY_STOP,      ANIM_StoneChomp_Still,
    STATUS_KEY_STATIC,    ANIM_StoneChomp_Idle,
    STATUS_KEY_DIZZY,     ANIM_StoneChomp_Dizzy,
    STATUS_END,
};

s32 N(QuickBiteAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_StoneChomp_QuickBite,
    STATUS_KEY_POISON,    ANIM_StoneChomp_QuickBite,
    STATUS_KEY_STOP,      ANIM_StoneChomp_Still,
    STATUS_KEY_STONE,     ANIM_StoneChomp_Still,
    STATUS_KEY_SLEEP,     ANIM_StoneChomp_Sleep,
    STATUS_KEY_STATIC,    ANIM_StoneChomp_QuickBite,
    STATUS_KEY_DIZZY,     ANIM_StoneChomp_Dizzy,
    STATUS_END,
};

s32 N(BiteAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_StoneChomp_Bite,
    STATUS_KEY_POISON,    ANIM_StoneChomp_Bite,
    STATUS_KEY_STOP,      ANIM_StoneChomp_Still,
    STATUS_KEY_STONE,     ANIM_StoneChomp_Still,
    STATUS_KEY_SLEEP,     ANIM_StoneChomp_Sleep,
    STATUS_KEY_STATIC,    ANIM_StoneChomp_Bite,
    STATUS_KEY_DIZZY,     ANIM_StoneChomp_Dizzy,
    STATUS_END,
};

s32 N(SlowBiteAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_StoneChomp_SlowBite,
    STATUS_KEY_POISON,    ANIM_StoneChomp_SlowBite,
    STATUS_KEY_STOP,      ANIM_StoneChomp_Still,
    STATUS_KEY_STONE,     ANIM_StoneChomp_Still,
    STATUS_KEY_SLEEP,     ANIM_StoneChomp_Sleep,
    STATUS_KEY_STATIC,    ANIM_StoneChomp_SlowBite,
    STATUS_KEY_DIZZY,     ANIM_StoneChomp_Dizzy,
    STATUS_END,
};

s32 N(ChainAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_StoneChomp_Chain,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   1,
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
    STATUS_KEY_PARALYZE,           50,
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
        .projectileTargetOffset = { 0, -14 },
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
    .type = ACTOR_TYPE_STONE_CHOMP,
    .level = ACTOR_LEVEL_STONE_CHOMP,
    .maxHP = 4,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 25,
    .hurricaneChance = 25,
    .spookChance = 0,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 85,
    .coinReward = 5,
    .size = { 56, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

#define CHOMP_CHAIN_FIRST_PART_IDX  PRT_CHAIN_1
#define CHOMP_CHAIN_LAST_PART_IDX   PRT_CHAIN_8
#define CHOMP_CHAIN_AVAR_SOUNDS     AVAR_EnableChainSounds
#include "common/battle/ChompChainSupport.inc.c"

// Custom version of EVS_Enemy_HopHome
// (in) LVar0: part idx
// (in) LVar1: hopping animID
EvtScript N(EVS_Chomp_HopHome) = {
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(2.0))
    ExecWait(N(EVS_Chomp_HopToPos))
    Return
    End
};

// Custom version of EVS_Enemy_HopToPos
// (in) LVar0: target posX
// (in) LVar1: target posY
// (in) LVar2: target posZ
EvtScript N(EVS_Chomp_HopToPos) = {
    Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
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
                Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STONE_CHOMP_STEP)
            Else
                Set(LVar4, LVar3)
                Add(LVar3, 30)
                Call(SetGoalPos, ACTOR_SELF, LVar3, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 0, false, true, false)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STONE_CHOMP_STEP)
            EndIf
        Else
            Set(LVar4, LVar3)
            Sub(LVar4, LVar0)
            IfLt(LVar4, 30)
                Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STONE_CHOMP_STEP)
            Else
                Sub(LVar3, 30)
                Call(SetGoalPos, ACTOR_SELF, LVar3, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 0, false, true, false)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STONE_CHOMP_STEP)
            EndIf
        EndIf
        Goto(0)
    Label(10)
    Return
    End
};

EvtScript N(EVS_Init) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_EnableChainSounds, false)
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
        Call(N(ChompChainUpdate))
        Goto(0)
        Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_StoneChomp_Hurt)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            Call(SetAnimation, ACTOR_SELF, PRT_CHAIN_1, ANIM_StoneChomp_BurnChain)
            Call(SetAnimation, ACTOR_SELF, PRT_CHAIN_2, ANIM_StoneChomp_BurnChain)
            Call(SetAnimation, ACTOR_SELF, PRT_CHAIN_3, ANIM_StoneChomp_BurnChain)
            Call(SetAnimation, ACTOR_SELF, PRT_CHAIN_4, ANIM_StoneChomp_BurnChain)
            Call(SetAnimation, ACTOR_SELF, PRT_CHAIN_5, ANIM_StoneChomp_BurnChain)
            Call(SetAnimation, ACTOR_SELF, PRT_CHAIN_6, ANIM_StoneChomp_BurnChain)
            Call(SetAnimation, ACTOR_SELF, PRT_CHAIN_7, ANIM_StoneChomp_BurnChain)
            Call(SetAnimation, ACTOR_SELF, PRT_CHAIN_8, ANIM_StoneChomp_BurnChain)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_StoneChomp_BurnHurt)
            SetConst(LVar2, ANIM_StoneChomp_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            Call(SetAnimation, ACTOR_SELF, PRT_CHAIN_1, ANIM_StoneChomp_BurnChain)
            Call(SetAnimation, ACTOR_SELF, PRT_CHAIN_2, ANIM_StoneChomp_BurnChain)
            Call(SetAnimation, ACTOR_SELF, PRT_CHAIN_3, ANIM_StoneChomp_BurnChain)
            Call(SetAnimation, ACTOR_SELF, PRT_CHAIN_4, ANIM_StoneChomp_BurnChain)
            Call(SetAnimation, ACTOR_SELF, PRT_CHAIN_5, ANIM_StoneChomp_BurnChain)
            Call(SetAnimation, ACTOR_SELF, PRT_CHAIN_6, ANIM_StoneChomp_BurnChain)
            Call(SetAnimation, ACTOR_SELF, PRT_CHAIN_7, ANIM_StoneChomp_BurnChain)
            Call(SetAnimation, ACTOR_SELF, PRT_CHAIN_8, ANIM_StoneChomp_BurnChain)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_StoneChomp_BurnHurt)
            SetConst(LVar2, ANIM_StoneChomp_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_StoneChomp_BurnStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_StoneChomp_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_StoneChomp_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_StoneChomp_Hurt)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.4))
            Call(AddGoalPos, ACTOR_SELF, 30, 0, 0)
            Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STONE_CHOMP_STEP)
            Call(AddGoalPos, ACTOR_SELF, 15, 0, 0)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STONE_CHOMP_STEP)
            Call(AddGoalPos, ACTOR_SELF, 5, 0, 0)
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STONE_CHOMP_STEP)
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STONE_CHOMP_STEP)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_StoneChomp_SlowBite)
            ExecWait(N(EVS_Chomp_HopHome))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.6))
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STONE_CHOMP_STEP)
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
            EndThread
            Call(SetGoalToHome, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetPartPos, ACTOR_SELF, PRT_TARGET, LVar0, LVar1, LVar2)
            Call(SetActorVar, ACTOR_SELF, AVAR_EnableChainSounds, false)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_StoneChomp_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_StoneChomp_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            Call(SetActorVar, ACTOR_SELF, AVAR_EnableChainSounds, false)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_StoneChomp_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_StoneChomp_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_StoneChomp_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_StoneChomp_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_StoneChomp_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_StoneChomp_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_StoneChomp_Idle)
            SetConst(LVar2, ANIM_StoneChomp_Hurt)
            ExecWait(EVS_Enemy_ScareAway)
            Return
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
            SetConst(LVar1, ANIM_StoneChomp_Hurt)
            ExecWait(EVS_Enemy_AirLift)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_StoneChomp_Hurt)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_StoneChomp_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
        CaseEq(EVENT_UP_AND_AWAY)
            Wait(1000)
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
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(SetActorVar, ACTOR_SELF, AVAR_EnableChainSounds, true)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, 0)
    Add(LVar0, 45)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STONE_CHOMP_STEP)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_StoneChomp_SlowBite)
    Wait(15)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_HURT)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_StoneChomp_Idle)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 20)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STONE_CHOMP_STEP)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 25)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STONE_CHOMP_STEP)
            Sub(LVar0, 15)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 4, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STONE_CHOMP_STEP)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_StoneChomp_Bite)
            Wait(20)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_StoneChomp_Bite)
            ExecWait(N(EVS_Chomp_HopToPos))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_StoneChomp_Idle)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(HPBarToHome, ACTOR_SELF)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(SetActorVar, ACTOR_SELF, AVAR_EnableChainSounds, false)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_StoneChomp_Idle)
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
    Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetPartPos, ACTOR_SELF, PRT_TARGET, LVar0, LVar1, LVar2)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_CHOMP_BITE, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_StoneChomp_Bite)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STONE_CHOMP_STEP)
            Add(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STONE_CHOMP_STEP)
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STONE_CHOMP_STEP)
            Sub(LVar0, 10)
            Call(JumpToGoal, ACTOR_SELF, 4, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STONE_CHOMP_STEP)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_StoneChomp_Idle)
            Wait(8)
            Call(YieldTurn)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_StoneChomp_Bite)
            ExecWait(N(EVS_Chomp_HopToPos))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_StoneChomp_Idle)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetPartPos, ACTOR_SELF, PRT_TARGET, LVar0, LVar1, LVar2)
            Call(SetActorYaw, ACTOR_SELF, 0)
        EndCaseGroup
    EndSwitch
    Call(SetActorVar, ACTOR_SELF, AVAR_EnableChainSounds, false)
    Call(HPBarToHome, ACTOR_SELF)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};
