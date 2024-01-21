#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/ShyGuy.h"
#include "sprite/npc/SpearGuy.h"

#define NAMESPACE A(spear_guy)

extern s32 N(ShyGuyAnims)[];

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern Formation N(ForwardSpearFormation);
extern Formation N(UpwardSpearFormation);

extern EvtScript N(EVS_ShyGuy_Init);
extern EvtScript N(EVS_ShyGuy_Idle);
extern EvtScript N(EVS_ShyGuy_TakeTurn);
extern EvtScript N(EVS_ShyGuy_HandleEvent);

enum N(ActorPartIDs) {
    PRT_SHY_GUY     = 1,
    PRT_SPEAR_GUY   = 2,
    PRT_SPEAR       = 3,
    PRT_GRASS_SKIRT = 4,
};

enum N(ActorVars) {
    AVAR_State              = 0,
    AVAL_State_SpearForward = 0,
    AVAL_State_SpearUpward  = 1,
    AVAL_State_ShyGuy       = 2,
    AVAR_Generation         = 1,
};

enum N(ActorParams) {
    DMG_STAB        = 3,
    DMG_THROW       = 3,
    DMG_TACKLE      = 2,
    DMG_VAULT       = 3,
};

s32 N(SpearForwardAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_SpearGuy_Anim04,
    STATUS_KEY_STONE,     ANIM_SpearGuy_Anim02,
    STATUS_KEY_SLEEP,     ANIM_SpearGuy_Anim0D,
    STATUS_KEY_POISON,    ANIM_SpearGuy_Anim0F,
    STATUS_KEY_STOP,      ANIM_SpearGuy_Anim02,
    STATUS_KEY_STATIC,    ANIM_SpearGuy_Anim04,
    STATUS_KEY_PARALYZE,  ANIM_SpearGuy_Anim02,
    STATUS_KEY_DIZZY,     ANIM_SpearGuy_Anim0F,
    STATUS_KEY_FEAR,      ANIM_SpearGuy_Anim0F,
    STATUS_END,
};

s32 N(SpearUpwardAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_SpearGuy_Anim03,
    STATUS_KEY_STONE,     ANIM_SpearGuy_Anim0D,
    STATUS_KEY_SLEEP,     ANIM_SpearGuy_Anim0D,
    STATUS_KEY_POISON,    ANIM_SpearGuy_Anim0F,
    STATUS_KEY_STOP,      ANIM_SpearGuy_Anim01,
    STATUS_KEY_STATIC,    ANIM_SpearGuy_Anim03,
    STATUS_KEY_PARALYZE,  ANIM_SpearGuy_Anim01,
    STATUS_KEY_DIZZY,     ANIM_SpearGuy_Anim0F,
    STATUS_KEY_FEAR,      ANIM_SpearGuy_Anim0F,
    STATUS_END,
};

s32 N(SpearAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_SpearGuy_Anim14,
    STATUS_END,
};

s32 N(GrassSkirtAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_SpearGuy_Anim19,
    STATUS_END,
};

s32 N(SpearGuyDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_FIRE,     0,
    ELEMENT_END,
};

s32 N(ShyGuyDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_SHOCK,    0,
    ELEMENT_END,
};

s32 N(SpearGuyStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              70,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

s32 N(ShyGuyStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              70,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_SPEAR_GUY,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 22 },
        .opacity = 255,
        .idleAnimations = N(SpearForwardAnims),
        .defenseTable = N(SpearGuyDefense),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_FRONT,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -3, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_DAMAGE_IMMUNE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_SHY_GUY,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(ShyGuyAnims),
        .defenseTable = N(ShyGuyDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_DAMAGE_IMMUNE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_SPEAR,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(SpearAnims),
        .defenseTable = N(ShyGuyDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_DAMAGE_IMMUNE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_GRASS_SKIRT,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(GrassSkirtAnims),
        .defenseTable = N(ShyGuyDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_SPEAR_GUY,
    .level = ACTOR_LEVEL_SPEAR_GUY,
    .maxHP = 7,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(SpearGuyStatusTable),
    .escapeChance = 50,
    .airLiftChance = 85,
    .hurricaneChance = 80,
    .spookChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 85,
    .coinReward = 2,
    .size = { 24, 24 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_UpdateSpearStance) = {
    Switch(LVar0)
        CaseEq(AVAL_State_ShyGuy)
            // do nothing
        CaseEq(AVAL_State_SpearForward)
            Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SpearForward)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_SPEAR_GUY, Ref(N(SpearForwardAnims)))
            Call(SetPartEventFlags, ACTOR_SELF, PRT_SPEAR_GUY, ACTOR_EVENT_FLAG_SPIKY_FRONT)
        CaseEq(AVAL_State_SpearUpward)
            Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_SpearUpward)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_SPEAR_GUY, Ref(N(SpearUpwardAnims)))
            Call(SetPartEventFlags, ACTOR_SELF, PRT_SPEAR_GUY, ACTOR_EVENT_FLAG_SPIKY_TOP)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Init) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_State_SpearForward)
            ExecWait(N(EVS_UpdateSpearStance))
            Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim04)
        CaseEq(AVAL_State_SpearUpward)
            ExecWait(N(EVS_UpdateSpearStance))
            Call(SetPartEventFlags, ACTOR_SELF, PRT_SPEAR_GUY, ACTOR_EVENT_FLAG_SPIKY_TOP)
            Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim03)
    EndSwitch
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_Generation, 0)
    Call(GetEncounterTrigger, LVar0)
    Switch(LVar0)
        CaseEq(ENCOUNTER_TRIGGER_JUMP)
        CaseOrEq(ENCOUNTER_TRIGGER_HAMMER)
        CaseOrEq(ENCOUNTER_TRIGGER_PARTNER)
            Call(SetPartEventBits, ACTOR_SELF, PRT_SPEAR_GUY, ACTOR_EVENT_FLAG_SPIKY_FRONT, FALSE)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_SPEAR_GUY, Ref(N(SpearUpwardAnims)))
            Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim03)
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(BindHandlePhase, ACTOR_SELF, NULL)
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Return
    End
};

EvtScript N(EVS_SelectAnim) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_State, LVarA)
    IfEq(LVarA, AVAL_State_SpearForward)
        Call(GetStatusFlags, ACTOR_SELF, LVarB)
        IfFlag(LVarB, STATUS_FLAG_SLEEP | STATUS_FLAG_FEAR | STATUS_FLAG_DIZZY)
        Else
            Set(LVar1, LVar2)
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
        Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        Switch(LVar0)
            CaseEq(AVAL_State_SpearForward)
                Call(GetStatusFlags, ACTOR_SELF, LVar0)
                IfFlag(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FEAR | STATUS_FLAG_DIZZY)
                    Call(SetIdleAnimations, ACTOR_SELF, PRT_SPEAR_GUY, Ref(N(SpearUpwardAnims)))
                    Call(SetPartEventBits, ACTOR_SELF, PRT_SPEAR_GUY, ACTOR_EVENT_FLAG_SPIKY_TOP, TRUE)
                    Call(SetPartEventBits, ACTOR_SELF, PRT_SPEAR_GUY, ACTOR_EVENT_FLAG_SPIKY_FRONT, FALSE)
                Else
                    Call(SetIdleAnimations, ACTOR_SELF, PRT_SPEAR_GUY, Ref(N(SpearForwardAnims)))
                    Call(SetPartEventBits, ACTOR_SELF, PRT_SPEAR_GUY, ACTOR_EVENT_FLAG_SPIKY_TOP, FALSE)
                    Call(SetPartEventBits, ACTOR_SELF, PRT_SPEAR_GUY, ACTOR_EVENT_FLAG_SPIKY_FRONT, TRUE)
                EndIf
            CaseEq(AVAL_State_SpearUpward)
                Call(SetIdleAnimations, ACTOR_SELF, PRT_SPEAR_GUY, Ref(N(SpearUpwardAnims)))
                Call(SetPartEventBits, ACTOR_SELF, PRT_SPEAR_GUY, ACTOR_EVENT_FLAG_SPIKY_TOP, TRUE)
                Call(SetPartEventBits, ACTOR_SELF, PRT_SPEAR_GUY, ACTOR_EVENT_FLAG_SPIKY_FRONT, FALSE)
        EndSwitch
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    SetConst(LVar0, PRT_SPEAR_GUY)
    SetConst(LVar1, ANIM_SpearGuy_Anim06)
    ExecWait(EVS_Enemy_ReturnHome)
    Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
    Switch(LVar0)
        CaseEq(AVAL_State_SpearForward)
            Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim04)
        CaseEq(AVAL_State_SpearUpward)
            Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim03)
    EndSwitch
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
            SetConst(LVar0, PRT_SPEAR_GUY)
            SetConst(LVar1, ANIM_SpearGuy_Anim07)
            SetConst(LVar2, ANIM_SpearGuy_Anim08)
            ExecWait(N(EVS_SelectAnim))
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            IfEq(LVar0, AVAL_State_SpearForward)
                Call(GetStatusFlags, ACTOR_SELF, LVarB)
                IfFlag(LVarB, STATUS_FLAG_SLEEP | STATUS_FLAG_FEAR | STATUS_FLAG_DIZZY)
                    SetConst(LVar0, PRT_SPEAR_GUY)
                    SetConst(LVar1, ANIM_SpearGuy_Anim0A)
                    SetConst(LVar2, ANIM_SpearGuy_Anim0C)
                Else
                    SetConst(LVar0, PRT_SPEAR_GUY)
                    SetConst(LVar1, ANIM_SpearGuy_Anim0B)
                    SetConst(LVar2, -1)
                EndIf
            Else
                SetConst(LVar0, PRT_SPEAR_GUY)
                SetConst(LVar1, ANIM_SpearGuy_Anim0A)
                SetConst(LVar2, ANIM_SpearGuy_Anim0C)
            EndIf
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            IfEq(LVar0, AVAL_State_SpearForward)
                Call(GetStatusFlags, ACTOR_SELF, LVarB)
                IfFlag(LVarB, STATUS_FLAG_SLEEP | STATUS_FLAG_FEAR | STATUS_FLAG_DIZZY)
                    SetConst(LVar0, PRT_SPEAR_GUY)
                    SetConst(LVar1, ANIM_SpearGuy_Anim0A)
                    SetConst(LVar2, ANIM_SpearGuy_Anim0C)
                    ExecWait(EVS_Enemy_BurnHit)
                    SetConst(LVar0, PRT_SPEAR_GUY)
                    SetConst(LVar1, ANIM_SpearGuy_Anim0C)
                    ExecWait(EVS_Enemy_Death)
                Else
                    SetConst(LVar0, PRT_SPEAR_GUY)
                    SetConst(LVar1, ANIM_SpearGuy_Anim0B)
                    SetConst(LVar2, -1)
                    ExecWait(EVS_Enemy_BurnHit)
                    SetConst(LVar0, PRT_SPEAR_GUY)
                    SetConst(LVar1, ANIM_SpearGuy_Anim0B)
                    ExecWait(EVS_Enemy_Death)
                EndIf
            Else
                SetConst(LVar0, PRT_SPEAR_GUY)
                SetConst(LVar1, ANIM_SpearGuy_Anim0A)
                SetConst(LVar2, ANIM_SpearGuy_Anim0C)
                ExecWait(EVS_Enemy_BurnHit)
                SetConst(LVar0, PRT_SPEAR_GUY)
                SetConst(LVar1, ANIM_SpearGuy_Anim0C)
                ExecWait(EVS_Enemy_Death)
            EndIf
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_SPEAR_GUY)
            SetConst(LVar1, ANIM_SpearGuy_Anim07)
            SetConst(LVar2, ANIM_SpearGuy_Anim08)
            ExecWait(N(EVS_SelectAnim))
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_SPEAR_GUY)
            SetConst(LVar1, ANIM_SpearGuy_Anim07)
            SetConst(LVar2, ANIM_SpearGuy_Anim08)
            ExecWait(N(EVS_SelectAnim))
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_SPEAR_GUY)
            SetConst(LVar1, ANIM_SpearGuy_Anim09)
            SetConst(LVar2, ANIM_SpearGuy_Anim08)
            ExecWait(N(EVS_SelectAnim))
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_SPEAR_GUY)
            SetConst(LVar1, ANIM_SpearGuy_Anim07)
            SetConst(LVar2, ANIM_SpearGuy_Anim08)
            ExecWait(N(EVS_SelectAnim))
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_SPEAR_GUY)
            SetConst(LVar1, ANIM_SpearGuy_Anim07)
            SetConst(LVar2, ANIM_SpearGuy_Anim08)
            ExecWait(N(EVS_SelectAnim))
            ExecWait(EVS_Enemy_Knockback)
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_SPEAR_GUY)
            SetConst(LVar1, ANIM_SpearGuy_Anim07)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_SPEAR_GUY)
            SetConst(LVar1, ANIM_SpearGuy_Anim09)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_SPEAR_GUY)
            SetConst(LVar1, ANIM_SpearGuy_Anim03)
            SetConst(LVar2, ANIM_SpearGuy_Anim04)
            ExecWait(N(EVS_SelectAnim))
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_SPEAR_GUY)
            SetConst(LVar1, ANIM_SpearGuy_Anim07)
            SetConst(LVar2, ANIM_SpearGuy_Anim08)
            ExecWait(N(EVS_SelectAnim))
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_SPEAR_GUY)
            SetConst(LVar1, ANIM_SpearGuy_Anim09)
            SetConst(LVar2, ANIM_SpearGuy_Anim08)
            ExecWait(N(EVS_SelectAnim))
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
            Switch(LVar0)
                CaseEq(AVAL_State_SpearForward)
                    SetConst(LVar0, PRT_SPEAR_GUY)
                    SetConst(LVar1, ANIM_SpearGuy_Anim04)
                    ExecWait(EVS_Enemy_Recover)
                CaseEq(AVAL_State_SpearUpward)
                    SetConst(LVar0, PRT_SPEAR_GUY)
                    SetConst(LVar1, ANIM_SpearGuy_Anim03)
                    ExecWait(EVS_Enemy_Recover)
            EndSwitch
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_SPEAR_GUY)
            SetConst(LVar1, ANIM_SpearGuy_Anim06)
            SetConst(LVar2, ANIM_SpearGuy_Anim07)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_SPEAR_GUY)
            SetConst(LVar1, ANIM_SpearGuy_Anim04)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_SPEAR_GUY)
            SetConst(LVar1, ANIM_SpearGuy_Anim04)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseEq(EVENT_SPIKE_TAUNT)
            Wait(10)
            Set(LFlag0, FALSE)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(GetStatusFlags, ACTOR_SELF, LVar3)
            Call(GetActorVar, ACTOR_SELF, AVAR_State, LVarA)
            Switch(LVarA)
                CaseEq(AVAL_State_SpearForward)
                    IfFlag(LVar3, STATUS_FLAG_SHRINK)
                        Add(LVar0, -11)
                        Add(LVar1, 3)
                        Set(LFlag0, TRUE)
                    EndIf
                    IfFlag(LVar3, STATUS_FLAG_DIZZY)
                        Add(LVar0, -4)
                        Add(LVar1, 36)
                        Set(LFlag0, TRUE)
                    EndIf
                    IfFlag(LVar3, STATUS_FLAG_SLEEP)
                        Add(LVar0, -8)
                        Add(LVar1, 36)
                        Set(LFlag0, TRUE)
                    EndIf
                    IfEq(LFlag0, FALSE)
                        Add(LVar0, -28)
                        Add(LVar1, 8)
                    EndIf
                CaseEq(AVAL_State_SpearUpward)
                    IfFlag(LVar3, STATUS_FLAG_SHRINK)
                        Add(LVar0, -4)
                        Add(LVar1, 15)
                        Set(LFlag0, TRUE)
                    EndIf
                    IfFlag(LVar3, STATUS_FLAG_DIZZY)
                        Add(LVar0, -4)
                        Add(LVar1, 36)
                        Set(LFlag0, TRUE)
                    EndIf
                    IfFlag(LVar3, STATUS_FLAG_SLEEP)
                        Add(LVar0, -8)
                        Add(LVar1, 36)
                        Set(LFlag0, TRUE)
                    EndIf
                    IfEq(LFlag0, FALSE)
                        Add(LVar0, -10)
                        Add(LVar1, 38)
                    EndIf
            EndSwitch
            PlayEffect(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 20, 0)
            Wait(20)
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_SpearStab) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim06)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        Add(LVar0, 10)
    Else
        Add(LVar0, 25)
    EndIf
    Set(LVar1, 0)
    Add(LVar2, 1)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim04)
    Wait(5)
    Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim1A)
    Wait(15)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPEAR_STAB)
            Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim1B)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Sub(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Wait(15)
            Wait(20)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_SPEAR_GUY, 0, ACTOR_DECORATION_SWEAT)
            ExecWait(N(EVS_ReturnHome))
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_SPEAR_GUY, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPEAR_STAB)
    Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim1B)
    Wait(5)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_STAB, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Wait(20)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Move_SummonBackup) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_14)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 15)
    Wait(15)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_01)
    Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim05)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Thread
        Wait(5)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPEAR_GUY_DANCE_1)
        Wait(15)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPEAR_GUY_DANCE_2)
    EndThread
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 10)
    Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim05)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim10)
    Wait(25)
    Thread
        Wait(5)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPEAR_GUY_DANCE_1)
        Wait(15)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPEAR_GUY_DANCE_2)
    EndThread
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 20)
    Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim05)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim10)
    Wait(30)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 10)
    Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim05)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 30, 0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
    Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim0E)
    Wait(20)
    Call(GetOriginalActorType, ACTOR_SELF, LVar0)
    Call(CreateHomeTargetList, TARGET_FLAG_GROUND | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar1, LVar2)
        Call(GetOriginalActorType, LVar1, LVar2)
        IfEq(LVar0, LVar2)
            Call(SetAnimation, LVar1, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim04)
            Call(GetIndexFromHome, LVar1, LVar3)
            IfLt(LVarA, LVar3)
                Call(GetActorVar, LVar1, AVAR_State, LVar4)
                IfEq(LVar4, AVAL_State_SpearForward)
                    Call(SetActorVar, LVar1, AVAR_State, AVAL_State_SpearUpward)
                    Call(SetIdleAnimations, LVar1, PRT_SPEAR_GUY, Ref(N(SpearUpwardAnims)))
                    Call(SetPartEventFlags, LVar1, PRT_SPEAR_GUY, ACTOR_EVENT_FLAG_SPIKY_TOP)
                    Call(SetAnimation, LVar1, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim03)
                EndIf
            EndIf
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar1)
        IfNe(LVar1, ITER_NO_MORE)
            Goto(0)
        EndIf
    Set(LFlag0, FALSE)
    Call(CreateHomeTargetList, TARGET_FLAG_GROUND | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(1)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetIndexFromHome, LVar0, LVar1)
        IfLt(LVar1, LVarA)
            Set(LFlag0, TRUE)
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(1)
        EndIf
    IfEq(LFlag0, FALSE)
        Call(SummonEnemy, Ref(N(ForwardSpearFormation)), FALSE)
    Else
        Call(SummonEnemy, Ref(N(UpwardSpearFormation)), FALSE)
    EndIf
    Set(LVarB, LVar0)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(SetAnimation, LVarB, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim10)
    Call(SetGoalToIndex, LVarB, LVarA)
    Call(GetGoalPos, LVarB, LVar0, LVar1, LVar2)
    Add(LVar0, 220)
    Call(SetActorPos, LVarB, LVar0, 0, 0)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Thread
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPEAR_GUY_DANCE_1)
        Wait(15)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPEAR_GUY_DANCE_1)
        Wait(15)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPEAR_GUY_DANCE_2)
        Wait(15)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SPEAR_GUY_DANCE_2)
        Wait(15)
    EndThread
    Call(SetActorSpeed, LVarB, Float(4.0))
    Call(RunToGoal, LVarB, 0, FALSE)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
    Call(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 30, 0)
    Call(SetAnimation, LVarB, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim0E)
    Wait(20)
    IfEq(LFlag0, FALSE)
        Call(SetAnimation, LVarB, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim04)
    Else
        Call(SetAnimation, LVarB, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim03)
    EndIf
    Call(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    Call(ForceHomePos, LVarB, LVar0, LVar1, LVar2)
    Call(HPBarToHome, LVarB)
    Call(GetActorVar, ACTOR_SELF, AVAR_Generation, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(SetActorVar, LVarB, AVAR_Generation, 1)
        CaseEq(1)
            Call(SetActorVar, LVarB, AVAR_Generation, 2)
    EndSwitch
    Call(SetActorVar, ACTOR_SELF, AVAR_Generation, 3)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

Vec3i N(SummonPos) = { NPC_DISPOSE_LOCATION };

Formation N(ForwardSpearFormation) = {
    ACTOR_BY_POS(NAMESPACE, N(SummonPos), 100, AVAL_State_SpearForward),
};

Formation N(UpwardSpearFormation) = {
    ACTOR_BY_POS(NAMESPACE, N(SummonPos), 100, AVAL_State_SpearUpward),
};

EvtScript N(EVS_BecomeShyGuy) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_State, AVAL_State_ShyGuy)
    Wait(10)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim13)
    Wait(5)
    Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim18)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 10)
    Add(LVar1, 15)
    Sub(LVar2, 1)
    Call(SetPartPos, ACTOR_SELF, PRT_GRASS_SKIRT, LVar0, LVar1, LVar2)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_GRASS_SKIRT, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_GRASS_SKIRT, Float(0.5))
    Add(LVar0, 50)
    Sub(LVar2, 30)
    Thread
        Loop(15)
            Call(SetPartRotation, ACTOR_SELF, PRT_GRASS_SKIRT, 0, 0, 10)
            Wait(1)
            Call(SetPartRotation, ACTOR_SELF, PRT_GRASS_SKIRT, 0, 0, -10)
            Wait(1)
        EndLoop
    EndThread
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
    Thread
        Loop(10)
            Call(GetPartOffset, ACTOR_SELF, PRT_GRASS_SKIRT, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 5, 0)
            Wait(3)
        EndLoop
    EndThread
    Call(PlaySoundAtPart, ACTOR_SELF, PRT_GRASS_SKIRT, SOUND_SPEAR_GUY_RIP_SKIRT)
    Call(SetPartSounds, ACTOR_SELF, PRT_GRASS_SKIRT, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    Call(JumpPartTo, ACTOR_SELF, PRT_GRASS_SKIRT, LVar0, 0, LVar2, 30, TRUE)
    Wait(5)
    Call(SetPartFlags, ACTOR_SELF, PRT_SPEAR_GUY, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_DAMAGE_IMMUNE | ACTOR_PART_FLAG_NO_TARGET)
    Call(SetPartFlags, ACTOR_SELF, PRT_SHY_GUY, ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_PRIMARY_TARGET)
    Call(SetPartFlags, ACTOR_SELF, PRT_SPEAR, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_DAMAGE_IMMUNE | ACTOR_PART_FLAG_NO_TARGET)
    Call(SetPartFlags, ACTOR_SELF, PRT_GRASS_SKIRT, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_DAMAGE_IMMUNE | ACTOR_PART_FLAG_NO_TARGET)
    ExecWait(N(EVS_ShyGuy_Init))
    Call(SetActorType, ACTOR_SELF, ACTOR_TYPE_SHY_GUY)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TYPE_CHANGED, TRUE)
    Call(SetStatusTable, ACTOR_SELF, Ref(N(ShyGuyStatusTable)))
    Call(HPBarToHome, ACTOR_SELF)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_Attack_ThrowSpear) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim06)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 200)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim15)
    Call(SetActorYaw, ACTOR_SELF, 0)
    Sub(LVar0, 100)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Sub(LVar0, 70)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(SetPartScale, ACTOR_SELF, PRT_SPEAR, Float(0.4), Float(0.4), Float(0.4))
        Call(SetPartScale, ACTOR_SELF, PRT_GRASS_SKIRT, Float(0.4), Float(0.4), Float(0.4))
    Else
        Call(SetPartScale, ACTOR_SELF, PRT_SPEAR, Float(1.0), Float(1.0), Float(1.0))
        Call(SetPartScale, ACTOR_SELF, PRT_GRASS_SKIRT, Float(1.0), Float(1.0), Float(1.0))
    EndIf
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim11)
            Wait(5)
            Thread
                Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim17)
                Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
                Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Sub(LVar0, 20)
                Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                Sub(LVar0, 10)
                Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim12)
            EndThread
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetPartPos, ACTOR_SELF, PRT_SPEAR, LVar0, 20, LVar2)
            Call(SetPartRotation, ACTOR_SELF, PRT_SPEAR, 0, 0, -30)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_SPEAR, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Thread
                Call(MakeLerp, -30, 45, 20, EASING_LINEAR)
                Label(0)
                Call(UpdateLerp)
                Call(SetPartRotation, ACTOR_SELF, PRT_SPEAR, 0, 0, LVar0)
                Wait(1)
                IfEq(LVar1, 1)
                    Goto(0)
                EndIf
            EndThread
            Call(PlaySoundAtPart, ACTOR_SELF, PRT_SPEAR, SOUND_SPEAR_THROW)
            Call(SetPartSounds, ACTOR_SELF, PRT_SPEAR, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 20)
            Set(LVar1, 10)
            Add(LVar2, 2)
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_SPEAR, Float(0.7))
            Call(JumpPartTo, ACTOR_SELF, PRT_SPEAR, LVar0, LVar1, LVar2, 20, TRUE)
            Wait(10)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_SPEAR, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(AddActorDecoration, ACTOR_SELF, PRT_SPEAR_GUY, 0, ACTOR_DECORATION_SWEAT)
            Wait(30)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_SPEAR_GUY, 0)
            Wait(10)
            ExecWait(N(EVS_BecomeShyGuy))
            Call(YieldTurn)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim11)
    Wait(5)
    Thread
        Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim17)
        Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Sub(LVar0, 20)
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
        Sub(LVar0, 10)
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        Call(SetAnimation, ACTOR_SELF, PRT_SPEAR_GUY, ANIM_SpearGuy_Anim12)
    EndThread
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetPartPos, ACTOR_SELF, PRT_SPEAR, LVar0, 20, LVar2)
    Call(SetPartRotation, ACTOR_SELF, PRT_SPEAR, 0, 0, -30)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_SPEAR, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Thread
        Call(MakeLerp, -30, 45, 20, EASING_LINEAR)
        Label(0)
        Call(UpdateLerp)
        Call(SetPartRotation, ACTOR_SELF, PRT_SPEAR, 0, 0, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    EndThread
    Call(PlaySoundAtPart, ACTOR_SELF, PRT_SPEAR, SOUND_SPEAR_THROW)
    Call(SetPartSounds, ACTOR_SELF, PRT_SPEAR, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar2, 2)
    Call(SetPartJumpGravity, ACTOR_SELF, PRT_SPEAR, Float(0.7))
    Call(JumpPartTo, ACTOR_SELF, PRT_SPEAR, LVar0, LVar1, LVar2, 20, TRUE)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_THROW, BS_FLAGS1_TRIGGER_EVENTS)
    Wait(3)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_SPEAR, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Wait(20)
    ExecWait(N(EVS_BecomeShyGuy))
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_GetAvailableColumn) = {
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
    IfEq(LFlag1, FALSE)
        Set(LVarA, 0)
        Return
    EndIf
    IfEq(LFlag2, FALSE)
        Set(LVarA, 1)
        Return
    EndIf
    IfEq(LFlag3, FALSE)
        Set(LVarA, 2)
        Return
    EndIf
    IfEq(LFlag4, FALSE)
        Set(LVarA, 3)
        Return
    EndIf
    Set(LVarA, -1)
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
            CaseEq(ACTOR_TYPE_JUNGLE_FUZZY)
                Call(GetStatusFlags, LVar0, LVar3)
                IfNotFlag(LVar3, STATUS_FLAGS_IMMOBILIZED)
                    Call(GetActorVar, LVar0, AVAR_JungleFuzzy_Generation, LVar3)
                    IfNe(LVar3, 2)
                        Add(LVar9, 1)
                    EndIf
                EndIf
            CaseEq(ACTOR_TYPE_SPEAR_GUY)
                Call(GetStatusFlags, LVar0, LVar3)
                IfNotFlag(LVar3, STATUS_FLAGS_IMMOBILIZED)
                    Call(GetActorVar, LVar0, AVAR_Generation, LVar3)
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

EvtScript N(EVS_SwitchSpearStance) = {
    Call(GetIndexFromHome, ACTOR_SELF, LVarA)
    Set(LFlag0, FALSE)
    Call(CreateHomeTargetList, TARGET_FLAG_GROUND | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetIndexFromHome, LVar0, LVar1)
        IfLt(LVar1, LVarA)
            Set(LFlag0, TRUE)
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    IfEq(LFlag0, TRUE)
        Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        IfEq(LVar0, AVAL_State_SpearForward)
            Set(LVar0, AVAL_State_SpearUpward)
            ExecWait(N(EVS_UpdateSpearStance))
        EndIf
    Else
        Call(GetActorVar, ACTOR_SELF, AVAR_State, LVar0)
        IfEq(LVar0, AVAL_State_SpearUpward)
            Set(LVar0, AVAL_State_SpearForward)
            ExecWait(N(EVS_UpdateSpearStance))
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        ExecWait(N(EVS_Attack_SpearStab))
        ExecWait(N(EVS_SwitchSpearStance))
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_Generation, LVar0)
    Switch(LVar0)
        CaseOrEq(0)
        CaseOrEq(1)
            ExecWait(N(EVS_GetAvailableColumn))
            IfEq(LVarA, -1)
                ExecWait(N(EVS_Attack_SpearStab))
                ExecWait(N(EVS_SwitchSpearStance))
                Return
            EndIf
            ExecWait(N(EVS_CountActiveSummoners))
            Switch(LVar9)
                CaseEq(1)
                    Call(RandInt, 1000, LVar0)
                    IfLt(LVar0, 300)
                        ExecWait(N(EVS_Move_SummonBackup))
                        Return
                    EndIf
                CaseEq(2)
                    Call(RandInt, 1000, LVar0)
                    IfLt(LVar0, 150)
                        ExecWait(N(EVS_Move_SummonBackup))
                        Return
                    EndIf
                CaseEq(3)
                    Call(RandInt, 1000, LVar0)
                    IfLt(LVar0, 100)
                        ExecWait(N(EVS_Move_SummonBackup))
                        Return
                    EndIf
            EndSwitch
            ExecWait(N(EVS_Attack_SpearStab))
            ExecWait(N(EVS_SwitchSpearStance))
        EndCaseGroup
        CaseEq(2)
            Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
            Call(GetTargetListLength, LVar0)
            IfEq(LVar0, 1)
                ExecWait(N(EVS_Attack_ThrowSpear))
                Return
            EndIf
            ExecWait(N(EVS_Attack_SpearStab))
            ExecWait(N(EVS_SwitchSpearStance))
        CaseEq(3)
            ExecWait(N(EVS_Attack_ThrowSpear))
    EndSwitch
    Return
    End
};

s32 N(ShyGuyAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ShyGuy_Red_Anim01,
    STATUS_KEY_STONE,     ANIM_ShyGuy_Red_Anim00,
    STATUS_KEY_SLEEP,     ANIM_ShyGuy_Red_Anim12,
    STATUS_KEY_POISON,    ANIM_ShyGuy_Red_Anim01,
    STATUS_KEY_STOP,      ANIM_ShyGuy_Red_Anim00,
    STATUS_KEY_STATIC,    ANIM_ShyGuy_Red_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_ShyGuy_Red_Anim00,
    STATUS_KEY_DIZZY,     ANIM_ShyGuy_Red_Anim13,
    STATUS_KEY_FEAR,      ANIM_ShyGuy_Red_Anim13,
    STATUS_END,
};

EvtScript N(EVS_ShyGuy_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_ShyGuy_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_ShyGuy_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_ShyGuy_HandleEvent)))
    Return
    End
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(EVS_ShyGuy_Idle) = {
    Label(0)
        Call(GetStatusFlags, ACTOR_SELF, LVar0)
        IfFlag(LVar0, STATUS_FLAG_SLEEP)
            Call(SetTargetOffset, ACTOR_SELF, PRT_SHY_GUY, -4, 14)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_SHY_GUY, 0, 0)
            Call(N(SetAbsoluteStatusOffsets), -10, 13, 10, 13)
        Else
            Call(SetTargetOffset, ACTOR_SELF, PRT_SHY_GUY, 0, 24)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_SHY_GUY, -1, -10)
            Call(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
        EndIf
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_ShyGuy_ReturnHome) = {
    Call(ResetAllActorSounds, ACTOR_SELF)
    SetConst(LVar0, PRT_SHY_GUY)
    SetConst(LVar1, ANIM_ShyGuy_Red_Anim03)
    ExecWait(EVS_Enemy_ReturnHome)
    Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim01)
    Return
    End
};

EvtScript N(EVS_ShyGuy_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0D)
            SetConst(LVar2, ANIM_ShyGuy_Red_Anim0E)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0D)
            SetConst(LVar2, ANIM_ShyGuy_Red_Anim0E)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0E)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_Knockback)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            ExecWait(N(EVS_ShyGuy_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim03)
            SetConst(LVar2, ANIM_ShyGuy_Red_Anim14)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim0C)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_Tackle) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim03)
    Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 50)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_ACTOR_HOP, 0)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim04)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim05)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(ResetAllActorSounds, ACTOR_SELF)
            Sub(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Wait(15)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_SHY_GUY, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim04)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_SHY_GUY, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim01)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Thread
        Wait(3)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_HOP)
    EndThread
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim04)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 10)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim05)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_TACKLE, BS_FLAGS1_TRIGGER_EVENTS)
    Call(ResetAllActorSounds, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 15)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim01)
    Wait(8)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    ExecWait(N(EVS_ShyGuy_ReturnHome))
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_Vault) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 20)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_TIMING_BAR_GO)
    Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim09)
    Wait(20)
    Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim03)
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 80)
    Set(LVar1, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim04)
    Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
    Sub(LVar0, 40)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim09)
            Thread
                Wait(12)
                Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim0A)
            EndThread
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 10)
            Set(LVar1, 0)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 24, FALSE, TRUE, FALSE)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim05)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.5))
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Sub(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Wait(15)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 15)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Call(AddActorDecoration, ACTOR_SELF, PRT_SHY_GUY, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim04)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_SHY_GUY, 0)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim01)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim09)
    Thread
        Wait(9)
        Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim0A)
    EndThread
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_VAULT, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 15)
            Thread
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                Set(LVar3, 0)
                Loop(20)
                    Sub(LVar3, 30)
                    IfLt(LVar3, 0)
                        Add(LVar3, 360)
                    EndIf
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar3)
                    Wait(1)
                EndLoop
                Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EndThread
            Call(GetBattleFlags, LVar0)
            IfFlag(LVar0, BS_FLAGS1_ATK_BLOCKED)
                Goto(1)
            EndIf
            Call(GetLastDamage, ACTOR_PLAYER, LVar0)
            IfEq(LVar0, 0)
                Goto(1)
            EndIf
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LRAW_CHEERING)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LRAW_CHEERING | SOUND_ID_TRIGGER_CHANGE_SOUND)
            Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim09)
            Wait(10)
            Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim07)
            Wait(15)
            Goto(2)
            Label(1)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_COLLAPSE)
            Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim10)
            Wait(10)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_DISAPPOINTED)
            Call(AddActorDecoration, ACTOR_SELF, PRT_SHY_GUY, 0, ACTOR_DECORATION_SWEAT)
            Call(RandInt, 100, LVar0)
            IfLt(LVar0, 50)
                Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim11)
            Else
                Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim13)
            EndIf
            Wait(25)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_SHY_GUY, 0)
            Call(SetActorYaw, ACTOR_SELF, 180)
            Label(2)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            SetConst(LVar0, PRT_SHY_GUY)
            SetConst(LVar1, ANIM_ShyGuy_Red_Anim04)
            ExecWait(EVS_Enemy_ReturnHome)
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_SHY_GUY, ANIM_ShyGuy_Red_Anim01)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_ShyGuy_TakeTurn) = {
    Call(RandInt, 1, LVar0)
    IfEq(LVar0, 0)
        ExecWait(N(EVS_Attack_Tackle))
    Else
        ExecWait(N(EVS_Attack_Vault))
    EndIf
    Return
    End
};
