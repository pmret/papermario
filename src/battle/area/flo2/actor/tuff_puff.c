#include "../area.h"
#include "sprite/npc/TuffPuff.h"
#include "huff_n_puff_common.h"

#define NAMESPACE A(tuff_puff)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_TARGET      = 2,
};

enum N(ActorVars) {
    AVAR_IN_IsLarge     = 0,
    AVAR_IsLarge        = 0,
    AVAR_Index          = 1, // set by huff n puff after spawning
    AVAR_WobbleMode     = 2,
    AVAR_ScaleX         = 3,
    AVAR_ScaleY         = 4,
    AVAR_HealValue      = 5, // how much sucking this actor up will heal Huff N Puff
};

s32 N(SmallAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_TuffPuff_Anim02,
    STATUS_KEY_STONE,     ANIM_TuffPuff_Anim00,
    STATUS_KEY_SLEEP,     ANIM_TuffPuff_Anim02,
    STATUS_KEY_POISON,    ANIM_TuffPuff_Anim02,
    STATUS_KEY_STOP,      ANIM_TuffPuff_Anim00,
    STATUS_KEY_STATIC,    ANIM_TuffPuff_Anim02,
    STATUS_KEY_PARALYZE,  ANIM_TuffPuff_Anim02,
    STATUS_KEY_PARALYZE,  ANIM_TuffPuff_Anim00,
    STATUS_KEY_DIZZY,     ANIM_TuffPuff_Anim02,
    STATUS_KEY_DIZZY,     ANIM_TuffPuff_Anim02,
    STATUS_KEY_FEAR,      ANIM_TuffPuff_Anim02,
    STATUS_END,
};

s32 N(LargeAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_TuffPuff_Anim03,
    STATUS_KEY_STONE,     ANIM_TuffPuff_Anim01,
    STATUS_KEY_SLEEP,     ANIM_TuffPuff_Anim03,
    STATUS_KEY_POISON,    ANIM_TuffPuff_Anim03,
    STATUS_KEY_STOP,      ANIM_TuffPuff_Anim01,
    STATUS_KEY_STATIC,    ANIM_TuffPuff_Anim03,
    STATUS_KEY_PARALYZE,  ANIM_TuffPuff_Anim03,
    STATUS_KEY_PARALYZE,  ANIM_TuffPuff_Anim01,
    STATUS_KEY_DIZZY,     ANIM_TuffPuff_Anim03,
    STATUS_KEY_DIZZY,     ANIM_TuffPuff_Anim03,
    STATUS_KEY_FEAR,      ANIM_TuffPuff_Anim03,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_SHOCK,   99,
    ELEMENT_MYSTERY,  0,
    ELEMENT_JUMP,     0,
    ELEMENT_SMASH,    0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,                0,
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

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_IGNORE_BELOW_CHECK | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(SmallAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_IGNORE_BELOW_CHECK | ACTOR_PART_FLAG_PRIMARY_TARGET | ACTOR_PART_FLAG_SKIP_MOVEMENT_ALLOC,
        .index = PRT_TARGET,
        .posOffset = { 0, 50, 0 },
        .targetOffset = { 0, -50 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING | ACTOR_FLAG_HALF_HEIGHT | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_TUFF_PUFF,
    .level = ACTOR_LEVEL_TUFF_PUFF,
    .maxHP = 1,
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
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { 24, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 0 },
    .statusTextOffset = { 10, 10 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(GetActorVar, ACTOR_SELF, AVAR_IN_IsLarge, LVar0)
    IfFalse(LVar0)
        Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -9)
        Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_TARGET, -1, -9)
        Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -1, 9)
        Call(SetTargetOffset, ACTOR_SELF, PRT_TARGET, -1, -41)
        Call(SetActorSize, ACTOR_SELF, 20, 25)
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(SmallAnims)))
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TuffPuff_Anim02)
        Call(SetActorVar, ACTOR_SELF, AVAR_IsLarge, FALSE)
    Else
        Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -8, -13)
        Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_TARGET, -8, -13)
        Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 1, 14)
        Call(SetTargetOffset, ACTOR_SELF, PRT_TARGET, 1, -36)
        Call(SetActorSize, ACTOR_SELF, 28, 35)
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(LargeAnims)))
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TuffPuff_Anim03)
        Call(SetActorVar, ACTOR_SELF, AVAR_IsLarge, TRUE)
    EndIf
    Call(SetActorVar, ACTOR_SELF, AVAR_WobbleMode, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_ScaleX, 100)
    Call(SetActorVar, ACTOR_SELF, AVAR_ScaleY, 100)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Return
    End
};

#include "common/CosInterpMinMax.inc.c"

EvtScript N(EVS_Idle) = {
    Set(LVarF, 0)
    Loop(0)
        Call(GetActorVar, ACTOR_SELF, AVAR_WobbleMode, LVarA)
        Switch(LVarA)
            CaseEq(0)
                Call(N(CosInterpMinMax), LVarF, LVar0, Float(0.97), Float(1.03), 15, 0, 0)
                Call(N(CosInterpMinMax), LVarF, LVar1, Float(1.03), Float(0.97), 15, 0, 0)
                Add(LVarF, 1)
            CaseEq(1)
                Call(N(CosInterpMinMax), LVarF, LVar0, Float(0.95), Float(1.05), 15, 0, 0)
                Call(N(CosInterpMinMax), LVarF, LVar1, Float(1.05), Float(0.95), 15, 0, 0)
                Add(LVarF, 3)
            CaseEq(2)
                Call(N(CosInterpMinMax), LVarF, LVar0, Float(0.9), Float(1.1), 15, 0, 0)
                Call(N(CosInterpMinMax), LVarF, LVar1, Float(1.1), Float(0.9), 15, 0, 0)
                Add(LVarF, 5)
        EndSwitch
        Call(GetActorVar, ACTOR_SELF, AVAR_ScaleX, LVar2)
        Call(GetActorVar, ACTOR_SELF, AVAR_ScaleY, LVar3)
        DivF(LVar2, Float(100.0))
        DivF(LVar3, Float(100.0))
        MulF(LVar1, LVar2)
        MulF(LVar0, LVar3)
        Call(SetActorScale, ACTOR_SELF, LVar1, LVar0, Float(1.0))
        IfGe(LVarF, 30)
            Set(LVarF, 0)
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(onDeath) = {
    Call(ActorExists, ACTOR_HUFF_N_PUFF, LVar0)
    IfFalse(LVar0)
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_Index, LVar0)
    Call(GetActorVar, ACTOR_HUFF_N_PUFF, AVAR_HuffNPuff_Flags, LVar1)
    Switch(LVar0)
        CaseEq(0)
            BitwiseAndConst(LVar1, ~(1 << 0))
        CaseEq(1)
            BitwiseAndConst(LVar1, ~(1 << 1))
        CaseEq(2)
            BitwiseAndConst(LVar1, ~(1 << 2))
        CaseEq(3)
            BitwiseAndConst(LVar1, ~(1 << 3))
        CaseEq(4)
            BitwiseAndConst(LVar1, ~(1 << 4))
        CaseEq(5)
            BitwiseAndConst(LVar1, ~(1 << 5))
        CaseEq(6)
            BitwiseAndConst(LVar1, ~(1 << 6))
        CaseEq(7)
            BitwiseAndConst(LVar1, ~(1 << 7))
        CaseEq(8)
            BitwiseAndConst(LVar1, ~(1 << 8))
        CaseEq(9)
            BitwiseAndConst(LVar1, ~(1 << 9))
    EndSwitch
    Call(SetActorVar, ACTOR_HUFF_N_PUFF, AVAR_WobbleMode, LVar1)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            IfFalse(LVar1)
                SetConst(LVar1, ANIM_TuffPuff_Anim0C)
            Else
                SetConst(LVar1, ANIM_TuffPuff_Anim0D)
            EndIf
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            IfFalse(LVar1)
                SetConst(LVar1, ANIM_TuffPuff_Anim0C)
            Else
                SetConst(LVar1, ANIM_TuffPuff_Anim0D)
            EndIf
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_BURN_HIT)
            Set(LVar0, 1)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            IfFalse(LVar1)
                SetConst(LVar1, ANIM_TuffPuff_Anim0E)
            Else
                SetConst(LVar1, ANIM_TuffPuff_Anim10)
            EndIf
            Call(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar2)
            IfFalse(LVar2)
                SetConst(LVar2, ANIM_TuffPuff_Anim0F)
            Else
                SetConst(LVar2, ANIM_TuffPuff_Anim11)
            EndIf
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            Set(LVar0, 1)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            IfFalse(LVar1)
                SetConst(LVar1, ANIM_TuffPuff_Anim0E)
            Else
                SetConst(LVar1, ANIM_TuffPuff_Anim10)
            EndIf
            Call(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar2)
            IfFalse(LVar2)
                SetConst(LVar2, ANIM_TuffPuff_Anim0F)
            Else
                SetConst(LVar2, ANIM_TuffPuff_Anim11)
            EndIf
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(N(onDeath))
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            IfFalse(LVar1)
                SetConst(LVar1, ANIM_TuffPuff_Anim0F)
            Else
                SetConst(LVar1, ANIM_TuffPuff_Anim11)
            EndIf
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_ZERO_DAMAGE)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            IfFalse(LVar1)
                SetConst(LVar1, ANIM_TuffPuff_Anim02)
            Else
                SetConst(LVar1, ANIM_TuffPuff_Anim03)
            EndIf
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            IfFalse(LVar1)
                SetConst(LVar1, ANIM_TuffPuff_Anim02)
            Else
                SetConst(LVar1, ANIM_TuffPuff_Anim03)
            EndIf
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            IfFalse(LVar1)
                SetConst(LVar1, ANIM_TuffPuff_Anim0C)
            Else
                SetConst(LVar1, ANIM_TuffPuff_Anim0D)
            EndIf
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(onDeath))
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            IfFalse(LVar1)
                SetConst(LVar1, ANIM_TuffPuff_Anim0C)
            Else
                SetConst(LVar1, ANIM_TuffPuff_Anim0D)
            EndIf
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            IfFalse(LVar1)
                SetConst(LVar1, ANIM_TuffPuff_Anim02)
            Else
                SetConst(LVar1, ANIM_TuffPuff_Anim03)
            EndIf
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            IfFalse(LVar1)
                SetConst(LVar1, ANIM_TuffPuff_Anim06)
            Else
                SetConst(LVar1, ANIM_TuffPuff_Anim07)
            EndIf
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            ExecWait(N(onDeath))
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            IfFalse(LVar1)
                SetConst(LVar1, ANIM_TuffPuff_Anim0C)
            Else
                SetConst(LVar1, ANIM_TuffPuff_Anim0D)
            EndIf
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsLarge, LVar1)
            IfFalse(LVar1)
                SetConst(LVar1, ANIM_TuffPuff_Anim02)
            Else
                SetConst(LVar1, ANIM_TuffPuff_Anim03)
            EndIf
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    // do nothing
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};
