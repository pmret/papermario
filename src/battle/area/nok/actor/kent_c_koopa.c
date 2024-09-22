#include "../area.h"
#include "sprite/npc/KentCKoopa.h"
#include "sprite/player.h"
#include "sprite/npc/Coin.h"

#define NAMESPACE A(kent_c_koopa)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

extern EvtScript N(EVS_KentC_GoHome);
extern EvtScript N(EVS_Flipped_SpinSmashHit);
extern EvtScript N(EVS_Flipped_SpinSmashDeath);
extern EvtScript N(EVS_FlipOver);
extern EvtScript N(EVS_Attack_ShellToss);
extern EvtScript N(EVS_Attack_HeavyStomp);

extern EvtScript N(EVS_DropDummyCoins);
extern EvtScript N(EVS_DropDummyCoin);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_FLIPPED         = 2, // targetable body while flipped
    PRT_WEAK_POINT      = 3, // the tail
    PRT_DUMMY_COIN_1    = 4,
    PRT_DUMMY_COIN_2    = 5,
    PRT_DUMMY_COIN_3    = 6,
    PRT_DUMMY_COIN_4    = 7,
    PRT_DUMMY_COIN_5    = 8,
    PRT_DUMMY_COIN_6    = 9,
};

enum N(ActorVars) {
    AVAR_IsFlipped          = 0,
    AVAR_Anim_Hurt          = 1,
    AVAR_FlippedTurns       = 2, // turns left to remain flipped
    AVAR_CoinsToDrop        = 3, // remaining coins that can drop via Spin Smashing while flipped over
    AVAR_FlipResistance     = 4, // number of hits before flipping over
};

enum N(ActorParams) {
    DMG_SHELL_TOSS_PLAYER   = 3,
    DMG_SHELL_TOSS_PARTNER  = 3,
    DMG_HEAVY_STOMP         = 10,
};

s32 N(FlipPosOffsets)[] = { 9, 16, 22, 26, 30, 32, 33, 32, 30, 26, 22, 16, 9, 0, 4, 6, 7, 6, 4, 0, 2, 0 };

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_KentCKoopa_Anim01,
    STATUS_KEY_STONE,     ANIM_KentCKoopa_Anim00,
    STATUS_KEY_SLEEP,     ANIM_KentCKoopa_Anim13,
    STATUS_KEY_POISON,    ANIM_KentCKoopa_Anim01,
    STATUS_KEY_STOP,      ANIM_KentCKoopa_Anim00,
    STATUS_KEY_STATIC,    ANIM_KentCKoopa_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_KentCKoopa_Anim00,
    STATUS_KEY_DIZZY,     ANIM_KentCKoopa_Anim14,
    STATUS_KEY_FEAR,      ANIM_KentCKoopa_Anim00,
    STATUS_END,
};

s32 N(FlippedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_KentCKoopa_Anim1A,
    STATUS_KEY_STOP,      ANIM_KentCKoopa_Anim19,
    STATUS_KEY_PARALYZE,  ANIM_KentCKoopa_Anim19,
    STATUS_END,
};

s32 N(CoinAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Coin_Rotate,
    STATUS_END,
};

s32 N(NormalDefense)[] = {
    ELEMENT_NORMAL,   6,
    ELEMENT_BLAST,    6,
    ELEMENT_END,
};

s32 N(FlippedDefense)[] = {
    ELEMENT_NORMAL,   3,
    ELEMENT_END,
};

s32 N(FlippedTailDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              80,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              30,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           30,
    STATUS_KEY_SHRINK,             40,
    STATUS_KEY_STOP,               50,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          1,
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
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 60 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(NormalDefense),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_FLIPPED,
        .posOffset = { 12, 61, 0 },
        .targetOffset = { 0, -20 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(FlippedDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_WEAK_POINT,
        .posOffset = { 45, 0, 0 },
        .targetOffset = { -70, 26 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(FlippedTailDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_DUMMY_COIN_1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(CoinAnims),
        .defenseTable = N(FlippedTailDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_DUMMY_COIN_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(CoinAnims),
        .defenseTable = N(FlippedTailDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_DUMMY_COIN_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(CoinAnims),
        .defenseTable = N(FlippedTailDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_DUMMY_COIN_4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(CoinAnims),
        .defenseTable = N(FlippedTailDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_DUMMY_COIN_5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(CoinAnims),
        .defenseTable = N(FlippedTailDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_DUMMY_COIN_6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(CoinAnims),
        .defenseTable = N(FlippedTailDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_KENT_C_KOOPA,
    .level = ACTOR_LEVEL_KENT_C_KOOPA,
    .maxHP = 70,
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
    .powerBounceChance = 70,
    .coinReward = 0,
    .size = { 90, 70 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -26, 38 },
    .statusTextOffset = { 2, 63 },
};

EvtScript N(EVS_Init) = {
    Call(func_8027D434, ACTOR_SELF, PRT_WEAK_POINT, 70)
    Call(SetPartSize, ACTOR_SELF, PRT_WEAK_POINT, 30, 30)
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_IsFlipped, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, ANIM_KentCKoopa_Anim1C)
    Call(SetActorVar, ACTOR_SELF, AVAR_FlippedTurns, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_CoinsToDrop, 20)
    Call(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, 2)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
            Call(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, 2)
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastElement, LVarE)
    Call(GetLastEvent, ACTOR_SELF, LVarD)
    Switch(LVarD)
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
        CaseEq(EVENT_HIT_COMBO)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            ExecWait(EVS_Enemy_Hit)
            Call(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, 2)
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_BURN_HIT)
            Call(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, 2)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            IfEq(LVar0, 0)
                Set(LVar0, 1)
                Set(LVar1, ANIM_KentCKoopa_Anim15)
                Set(LVar2, ANIM_KentCKoopa_Anim16)
                ExecWait(EVS_Enemy_BurnHit)
            Else
                Set(LVar0, 1)
                Set(LVar1, ANIM_KentCKoopa_Anim17)
                Set(LVar2, ANIM_KentCKoopa_Anim18)
                ExecWait(EVS_Enemy_BurnHit)
            EndIf
        CaseEq(EVENT_BURN_DEATH)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            IfEq(LVar0, 0)
                Set(LVar0, 1)
                Set(LVar1, ANIM_KentCKoopa_Anim15)
                Set(LVar2, ANIM_KentCKoopa_Anim16)
            Else
                Set(LVar0, 1)
                Set(LVar1, ANIM_KentCKoopa_Anim17)
                Set(LVar2, ANIM_KentCKoopa_Anim18)
            EndIf
            ExecWait(EVS_Enemy_BurnHit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, LVar2)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            Call(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, 2)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            IfEq(LVar0, 0)
                SetConst(LVar0, PRT_MAIN)
                Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                ExecWait(EVS_Enemy_Hit)
            Else
                SetConst(LVar0, PRT_MAIN)
                Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                ExecWait(N(EVS_Flipped_SpinSmashHit))
            EndIf
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            IfEq(LVar0, 0)
                SetConst(LVar0, PRT_MAIN)
                Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                ExecWait(EVS_Enemy_Hit)
                SetConst(LVar0, PRT_MAIN)
                Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                ExecWait(EVS_Enemy_Death)
                Return
            Else
                SetConst(LVar0, PRT_MAIN)
                Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
                ExecWait(N(EVS_Flipped_SpinSmashDeath))
                Return
            EndIf
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            ExecWait(EVS_Enemy_ReturnHome)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_MAIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, LVar1)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_ZERO_DAMAGE)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            IfEq(LVar0, 0)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_KentCKoopa_Anim09)
                ExecWait(EVS_Enemy_NoDamageHit)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_KentCKoopa_Anim1A)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
        CaseEq(EVENT_IMMUNE)
            Call(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, 2)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            IfEq(LVar0, 0)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_KentCKoopa_Anim09)
                ExecWait(EVS_Enemy_NoDamageHit)
                Call(GetStatusFlags, ACTOR_SELF, LVar2)
                IfEq(LVar2, 0)
                    Wait(20)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim0C)
                    Wait(8)
                EndIf
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_KentCKoopa_Anim1A)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
        CaseEq(EVENT_AIR_LIFT_FAILED)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            IfEq(LVar0, 0)
                Set(LVar1, ANIM_KentCKoopa_Anim01)
            Else
                Set(LVar1, ANIM_KentCKoopa_Anim1A)
            EndIf
            Set(LVar0, 1)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_END_FIRST_STRIKE)
            ExecWait(N(EVS_KentC_GoHome))
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            IfEq(LVar0, 0)
                SetConst(LVar1, ANIM_KentCKoopa_Anim01)
                SetConst(LVar0, PRT_MAIN)
                ExecWait(EVS_Enemy_Recover)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_KentCKoopa_Anim1A)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
        CaseEq(EVENT_FLIP_TRIGGER)
            Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
            IfEq(LVar0, 1)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_KentCKoopa_Anim12)
                ExecWait(EVS_Enemy_Hit)
                Return
            EndIf
            // each flip trigger decrements AVAR_FlipResistance by 1
            Call(GetActorVar, ACTOR_SELF, AVAR_FlipResistance, LVar0)
            IfGt(LVar0, 0)
                Sub(LVar0, 1)
                Call(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, LVar0)
            EndIf
            // POW blocks immediately set AVAR_FlipResistance to 0
            Call(GetDamageSource, LVar0)
            IfEq(LVar0, DMG_SRC_POW_BLOCK)
                Call(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, 0)
            EndIf
            // if AVAR_FlipResistance is depleted, flip over
            Call(GetActorVar, ACTOR_SELF, AVAR_FlipResistance, LVar0)
            IfEq(LVar0, 0)
                Call(GetBattleFlags, LVarD)
                IfFlag(LVarD, BS_FLAGS1_TRIGGER_EVENTS)
                    Call(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, 2)
                EndIf
                ExecWait(N(EVS_FlipOver))
            Else
                Call(GetBattleFlags, LVarD)
                IfFlag(LVarD, BS_FLAGS1_TRIGGER_EVENTS)
                    Call(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, 2)
                    Call(GetLastDamage, ACTOR_SELF, LVar0)
                    IfGt(LVar0, 0)
                        SetConst(LVar0, PRT_MAIN)
                        SetConst(LVar1, ANIM_KentCKoopa_Anim1C)
                        ExecWait(EVS_Enemy_Hit)
                    Else
                        SetConst(LVar0, PRT_MAIN)
                        SetConst(LVar1, ANIM_KentCKoopa_Anim09)
                        ExecWait(EVS_Enemy_NoDamageHit)
                        Call(GetStatusFlags, ACTOR_SELF, LVar2)
                        IfEq(LVar2, 0)
                            Wait(20)
                            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim0C)
                            Wait(8)
                        EndIf
                    EndIf
                Else
                    SetConst(LVar0, PRT_MAIN)
                    SetConst(LVar1, ANIM_KentCKoopa_Anim1C)
                    ExecWait(EVS_Enemy_Hit)
                EndIf
            EndIf
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

#include "common/StartRumbleWithParams.inc.c"
#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(EVS_TakeTurn) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_FlipResistance, 2)
    Call(GetActorVar, ACTOR_SELF, AVAR_IsFlipped, LVar0)
    IfEq(LVar0, 1)
        Call(UseIdleAnimation, ACTOR_SELF, FALSE)
        Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
        Call(UseBattleCamPreset, BTL_CAM_ACTOR)
        Call(SetBattleCamDist, 200)
        Call(SetBattleCamOffsetY, 20)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 25)
        Call(GetActorVar, ACTOR_SELF, AVAR_FlippedTurns, LVar0)
        Sub(LVar0, 1)
        Call(SetActorVar, ACTOR_SELF, AVAR_FlippedTurns, LVar0)
        IfGt(LVar0, 0)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 36)
            Add(LVar1, 18)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(3.0))
            Loop(5)
                PlayEffect(EFFECT_SWEAT, 1, LVar0, LVar1, LVar2, 1, 225, 10, 0)
                Wait(5)
            EndLoop
            Wait(30)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        Else
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 36)
            Add(LVar1, 18)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(3.0))
            Loop(5)
                PlayEffect(EFFECT_SWEAT, 1, LVar0, LVar1, LVar2, 1, 225, 10, 0)
                Wait(5)
            EndLoop
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(3.0))
            Wait(30)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 15)
            Call(SetAnimationRate, ACTOR_SELF, PRT_MAIN, Float(1.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim19)
            Thread
                Wait(3)
                Call(GetStatusFlags, ACTOR_SELF, LVar0)
                IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
                    Call(SetActorRotationOffset, ACTOR_SELF, 0, 27, 0)
                Else
                    Call(SetActorRotationOffset, ACTOR_SELF, 0, 10, 0)
                EndIf
                Set(LVar0, 0)
                Loop(5)
                    Add(LVar0, 36)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            Call(GetStatusFlags, ACTOR_SELF, LVar3)
            IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
                Call(N(StartRumbleWithParams), 80, 14)
                Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
            EndIf
            Wait(3)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim0C)
            Wait(10)
            Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(NormalDefense)))
            Call(SetEnemyTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 60)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_WEAK_POINT, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_WEAK_POINT, ACTOR_PART_FLAG_PRIMARY_TARGET, FALSE)
            Call(SetPartFlags, ACTOR_SELF, PRT_FLIPPED, ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_NO_SHADOW)
            Call(SetPartFlags, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_PRIMARY_TARGET | ACTOR_PART_FLAG_NO_SHADOW)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
            Call(N(SetAbsoluteStatusOffsets), -26, 38, 2, 63)
            Call(SetActorVar, ACTOR_SELF, AVAR_IsFlipped, FALSE)
            Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, ANIM_KentCKoopa_Anim1C)
        EndIf
    EndIf
    Call(RandInt, 100, LVar0)
    IfLt(LVar0, 50)
        Call(GetStatusFlags, ACTOR_PARTNER, LVar0)
        IfNotFlag(LVar0, STATUS_FLAG_KO)
            ExecWait(N(EVS_Attack_ShellToss))
        Else
            ExecWait(N(EVS_Attack_HeavyStomp))
        EndIf
    Else
        ExecWait(N(EVS_Attack_HeavyStomp))
    EndIf
    Return
    End
};

EvtScript N(EVS_Attack_ShellToss) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(SetBattleCamDist, 200)
    Call(SetBattleCamOffsetY, 20)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 25)
    Wait(20)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim0B)
    Wait(10)
    Thread
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 4)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        Wait(3)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
        Wait(2)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 32, 4, 0, 10, 0)
    EndThread
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_KENT_C_SHELL_TOSS_LOOP)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim0A)
    Wait(10)
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 3, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            Call(EnemyTestTarget, ACTOR_SELF, LVarB, 0, 0, 3, BS_FLAGS1_INCLUDE_POWER_UPS)
            Switch(LVarB)
                CaseEq(6)
                    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    Call(MoveBattleCamOver, 30)
                    Call(SetGoalToTarget, ACTOR_SELF)
                    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Sub(LVar0, 40)
                    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
                    Call(SetGoalPos, ACTOR_SELF, -240, 0, LVar2)
                    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
                    Call(SetActorPos, ACTOR_SELF, 240, 0, LVar2)
                    Call(SetGoalToHome, ACTOR_SELF)
                    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
                    Call(ResetAllActorSounds, ACTOR_SELF)
                    Call(StopSound, SOUND_KENT_C_SHELL_TOSS_LOOP)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim0C)
                    Wait(8)
                    Call(YieldTurn)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim01)
                    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
                    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
                    Return
                CaseDefault
                    Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
                    IfNotFlag(LVar0, STATUS_FLAG_TRANSPARENT | STATUS_FLAGS_IMMOBILIZED)
                        Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
                        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Flail)
                    EndIf
                    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
                    Call(SetBattleCamTarget, -25, 60, 0)
                    Call(SetBattleCamDist, 460)
                    Call(SetBattleCamOffsetY, 0)
                    Call(MoveBattleCamOver, 50)
                    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                    Call(SetGoalToTarget, ACTOR_SELF)
                    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(GetStatusFlags, ACTOR_SELF, LVar3)
                    IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
                        Add(LVar0, 32)
                    Else
                        Add(LVar0, 12)
                    EndIf
                    Set(LVar1, 0)
                    Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
                    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
                    IfEq(LVarA, HIT_RESULT_LUCKY)
                        Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                    EndIf
                    Set(LVarA, 1)
            EndSwitch
        EndCaseGroup
        CaseDefault
            Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
            Call(SetBattleCamTarget, -25, 60, 0)
            Call(SetBattleCamDist, 460)
            Call(SetBattleCamOffsetY, 0)
            Call(MoveBattleCamOver, 50)
            Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
            Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
            IfNotFlag(LVar0, STATUS_FLAG_TRANSPARENT | STATUS_FLAGS_IMMOBILIZED)
                Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Flail)
            EndIf
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(GetStatusFlags, ACTOR_SELF, LVar3)
            IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
                Add(LVar0, 32)
            Else
                Add(LVar0, 12)
            EndIf
            Set(LVar1, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetStatusFlags, ACTOR_SELF, LVarE)
            IfNotFlag(LVarE, STATUS_FLAG_SHRINK)
                Call(SetDamageSource, DMG_SRC_CRUSH)
            EndIf
            Call(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, SUPPRESS_EVENT_ALL, 0, DMG_SHELL_TOSS_PLAYER, BS_FLAGS1_TRIGGER_EVENTS)
            Set(LVarA, 0)
            IfNotFlag(LVarE, STATUS_FLAG_SHRINK)
                Call(GetBattleFlags, LVar0)
                IfNotFlag(LVar0, BS_FLAGS1_ATK_BLOCKED)
                    Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
                    IfNotFlag(LVar0, STATUS_FLAG_STONE)
                        Set(LVarA, 1)
                    EndIf
                EndIf
            EndIf
    EndSwitch
    IfNe(LVarA, 0)
        Call(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 32)
        Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
        Call(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
        Call(RunToGoal, ACTOR_SELF, 0, FALSE)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(SetDamageSource, DMG_SRC_CRUSH_PARTNER)
        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, DMG_SHELL_TOSS_PARTNER, BS_FLAGS1_TRIGGER_EVENTS)
        Call(GetBattleFlags, LVar0)
        IfNotFlag(LVar0, BS_FLAGS1_ATK_BLOCKED)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetGoalPos, ACTOR_SELF, -240, 0, LVar2)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            Call(SetActorPos, ACTOR_SELF, 240, 0, LVar2)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(ResetAllActorSounds, ACTOR_SELF)
            Call(StopSound, SOUND_KENT_C_SHELL_TOSS_LOOP)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim0C)
            Wait(8)
            Call(YieldTurn)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim01)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        Else
            Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
            Call(SetBattleCamTarget, -45, 60, 0)
            Call(SetBattleCamDist, 460)
            Call(SetBattleCamOffsetY, 0)
            Call(MoveBattleCamOver, 30)
        EndIf
    EndIf
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    Thread
        Call(GetStatusFlags, ACTOR_SELF, LVar3)
        IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
            Call(N(StartRumbleWithParams), 80, 14)
            Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
        EndIf
    EndThread
    Add(LVar0, 16)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
    Thread
        Call(GetStatusFlags, ACTOR_SELF, LVar3)
        IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
            Call(N(StartRumbleWithParams), 80, 14)
            Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
        EndIf
    EndThread
    Add(LVar0, 10)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    Thread
        Call(GetStatusFlags, ACTOR_SELF, LVar3)
        IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
            Call(N(StartRumbleWithParams), 80, 14)
            Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
        EndIf
    EndThread
    Call(ResetAllActorSounds, ACTOR_SELF)
    Call(StopSound, SOUND_KENT_C_SHELL_TOSS_LOOP)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim0C)
    Wait(8)
    Call(YieldTurn)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_KentCKoopa_Anim04)
    ExecWait(EVS_Enemy_ReturnHome)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim01)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_HeavyStomp) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(SetBattleCamDist, 280)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 50)
    Set(LVar1, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim03)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim01)
    Wait(8)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LARGE_ACTOR_JUMP)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim06)
            Thread
                Wait(7)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim07)
                Wait(4)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim08)
            EndThread
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 20)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_A)
            Thread
                Call(GetStatusFlags, ACTOR_SELF, LVar3)
                IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
                    Call(N(StartRumbleWithParams), 80, 14)
                    Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
                EndIf
            EndThread
            Sub(LVar0, 15)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_A)
            Thread
                Call(GetStatusFlags, ACTOR_SELF, LVar3)
                IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
                    Call(N(StartRumbleWithParams), 80, 14)
                    Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
                EndIf
            EndThread
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim01)
            Sub(LVar0, 10)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_A)
            Thread
                Call(GetStatusFlags, ACTOR_SELF, LVar3)
                IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
                    Call(N(StartRumbleWithParams), 80, 14)
                    Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
                EndIf
            EndThread
            Wait(8)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            Set(LVar3, 0)
            Loop(12)
                Add(LVar3, 15)
                Call(SetActorYaw, ACTOR_SELF, LVar3)
                Wait(1)
            EndLoop
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim04)
            Call(SetPartYaw, ACTOR_SELF, PRT_MAIN, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim01)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Set(LVar3, 180)
            Loop(15)
                Sub(LVar3, 12)
                Call(SetActorYaw, ACTOR_SELF, LVar3)
                Wait(1)
            EndLoop
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim06)
    Thread
        Wait(5)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim07)
        Wait(2)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim08)
    EndThread
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.3))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(JumpToGoal, ACTOR_SELF, 14, FALSE, TRUE, FALSE)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetStatusFlags, ACTOR_SELF, LVarF)
    IfNotFlag(LVarF, STATUS_FLAG_SHRINK)
        Call(SetDamageSource, DMG_SRC_CRUSH)
    EndIf
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, SUPPRESS_EVENT_ALL, 0, DMG_HEAVY_STOMP, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(HIT_RESULT_10)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 30)
            Call(GetBattleFlags, LVar0)
            IfNotFlag(LVar0, BS_FLAGS1_ATK_BLOCKED)
                Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
                IfNotFlag(LVar0, STATUS_FLAG_STONE)
                    Call(GetStatusFlags, ACTOR_SELF, LVarE)
                    IfNotFlag(LVarE, STATUS_FLAG_SHRINK)
                        Call(LandJump, ACTOR_SELF)
                        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_A)
                    EndIf
                EndIf
            EndIf
            Thread
                Call(N(StartRumbleWithParams), 80, 14)
                Call(GetStatusFlags, ACTOR_SELF, LVar3)
                IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
                    Call(N(StartRumbleWithParams), 80, 14)
                    Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
                EndIf
            EndThread
            Thread
                Wait(5)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim06)
            EndThread
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_A)
            Thread
                Call(GetStatusFlags, ACTOR_SELF, LVar3)
                IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
                    Call(N(StartRumbleWithParams), 80, 14)
                    Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
                EndIf
            EndThread
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim01)
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_A)
            Thread
                Call(GetStatusFlags, ACTOR_SELF, LVar3)
                IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
                    Call(N(StartRumbleWithParams), 80, 14)
                    Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
                EndIf
            EndThread
            Wait(8)
            IfEq(LVarF, 10)
                Return
            EndIf
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            ExecWait(N(EVS_KentC_GoHome))
        CaseEq(HIT_RESULT_NICE_NO_DAMAGE)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_KentC_GoHome) = {
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_KentCKoopa_Anim04)
    ExecWait(EVS_Enemy_ReturnHome)
    Return
    End
};

EvtScript N(EVS_FlipOver) = {
    Call(SetEnemyTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 40)
    Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(FlippedDefense)))
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(FlippedAnims)))
    Call(N(SetAbsoluteStatusOffsets), -24, 47, 23, 37)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim1C)
    Call(SetActorVar, ACTOR_SELF, AVAR_IsFlipped, TRUE)
    Call(SetActorVar, ACTOR_SELF, AVAR_Anim_Hurt, ANIM_KentCKoopa_Anim12)
    Thread
        Wait(4)
        Call(GetStatusFlags, ACTOR_SELF, LVar0)
        IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 35, 0)
        Else
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
        EndIf
        Set(LVar0, 0)
        Loop(5)
            Sub(LVar0, 18)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            Wait(1)
        EndLoop
    EndThread
    UseBuf(Ref(N(FlipPosOffsets)))
    Loop(ARRAY_COUNT(N(FlipPosOffsets)))
        BufRead1(LVar0)
        Call(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
        IfEq(LVar0, 0)
            Thread
                Call(GetStatusFlags, ACTOR_SELF, LVar3)
                IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
                    Call(N(StartRumbleWithParams), 80, 14)
                    Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
                EndIf
            EndThread
        EndIf
        Wait(1)
    EndLoop
    Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim1D)
    Wait(1)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_KentCKoopa_Anim1E)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_WEAK_POINT, ACTOR_PART_FLAG_NO_TARGET, FALSE)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_WEAK_POINT, ACTOR_PART_FLAG_PRIMARY_TARGET, TRUE)
    Call(SetPartFlags, ACTOR_SELF, PRT_FLIPPED, ACTOR_PART_FLAG_NO_SHADOW)
    Call(SetPartFlags, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_NO_SHADOW)
    Call(SetActorVar, ACTOR_SELF, AVAR_FlippedTurns, 1)
    Wait(8)
    Return
    End
};

EvtScript N(EVS_Flipped_SpinSmashHit) = {
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Set(LVarA, 5)
    ExecWait(N(EVS_DropDummyCoins))
    Set(LVar2, 0)
    Loop(36)
        Add(LVar2, 30)
        Call(SetActorYaw, ACTOR_SELF, LVar2)
        Wait(1)
    EndLoop
    Call(SetActorYaw, ACTOR_SELF, 0)
    Return
    End
};

EvtScript N(EVS_Flipped_SpinSmashDeath) = {
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Set(LVarA, 0)
    ExecWait(N(EVS_DropDummyCoins))
    Set(LVar2, 0)
    Loop(48)
        Add(LVar2, 30)
        Call(SetActorYaw, ACTOR_SELF, LVar2)
        Wait(1)
    EndLoop
    Call(SetActorYaw, ACTOR_SELF, 0)
    Wait(10)
    Set(LVar0, PRT_MAIN)
    Set(LVar1, -1)
    ExecWait(EVS_Enemy_Death)
    Return
    End
};

// when hit with Spin Smash while flipped over, coins fly out
// (in) LVarA : delay between each coin release
EvtScript N(EVS_DropDummyCoins) = {
    Call(GetStatusFlags, ACTOR_SELF, LVar3)
    IfFlag(LVar3, STATUS_FLAG_SHRINK)
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_CoinsToDrop, LVar3)
    Call(GetLastDamage, ACTOR_SELF, LVar4)
    IfGt(LVar4, LVar3)
        Set(LVar4, LVar3)
    EndIf
    IfGt(LVar4, 6)
        Set(LVar4, 6)
    EndIf
    IfGt(LVar4, 0)
        Thread
            Sub(LVar3, LVar4)
            Call(SetActorVar, ACTOR_SELF, AVAR_CoinsToDrop, LVar3)
            Set(LVar5, PRT_DUMMY_COIN_1)
            Loop(LVar4)
                Exec(N(EVS_DropDummyCoin))
                Add(LVar5, 1)
                Wait(LVarA)
            EndLoop
        EndThread
    EndIf
    Return
    End
};

API_CALLABLE(N(GetCoinTrajectory)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    f32 angle = rand_int(360);

    f32 centerX = x;
    f32 centerZ = z;

    s32 startX = centerX + cos_deg(angle) * 46.0f;
    s32 startZ = centerZ + sin_deg(angle) * 46.0f;
    s32 endX = centerX + cos_deg(angle) * 62.0f;
    s32 endZ = centerZ + sin_deg(angle) * 62.0f;

    evt_set_variable(script, *args++, startX);
    evt_set_variable(script, *args++, startZ);
    evt_set_variable(script, *args++, endX);
    evt_set_variable(script, *args++, endZ);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(UnusedFunc)) {
    Bytecode* args = script->ptrReadPos;
    Bytecode var1 = *args++;

    evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_DropDummyCoin) = {
    Call(PlaySoundAtPart, ACTOR_SELF, LVar5, SOUND_COIN_BOUNCE)
    Call(GetActorPos, ACTOR_SELF, LVar6, LVar7, LVar8)
    Call(SetPartPos, ACTOR_SELF, LVar5, LVar6, 35, LVar8)
    Call(N(GetCoinTrajectory), LVar6, LVar8, LVar0, LVar1, LVar2, LVar3)
    Call(SetPartFlagBits, ACTOR_SELF, LVar5, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(SetPartJumpGravity, ACTOR_SELF, LVar5, Float(1.0))
    Call(JumpPartTo, ACTOR_SELF, LVar5, LVar0, 0, LVar1, 18, TRUE)
    Call(JumpPartTo, ACTOR_SELF, LVar5, LVar2, 0, LVar3, 9, TRUE)
    Wait(10)
    // blinking
    Loop(10)
        Call(SetPartFlagBits, ACTOR_SELF, LVar5, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        Wait(1)
        Call(SetPartFlagBits, ACTOR_SELF, LVar5, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        Wait(1)
    EndLoop
    // give coin to player
    Call(PlaySoundAtPart, ACTOR_SELF, LVar5, SOUND_COIN_PICKUP)
    Call(AddCoin, 1)
    Return
    End
};
