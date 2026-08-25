#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Whacka.h"

#define NAMESPACE A(whacka)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_MakeWhackaBump);
extern EvtScript N(EVS_Death);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_SpawnedBump    = 0,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Whacka_Idle,
    STATUS_KEY_STONE,     ANIM_Whacka_Still,
    STATUS_KEY_SLEEP,     ANIM_Whacka_Idle,
    STATUS_KEY_POISON,    ANIM_Whacka_Idle,
    STATUS_KEY_STOP,      ANIM_Whacka_Still,
    STATUS_KEY_STATIC,    ANIM_Whacka_Idle,
    STATUS_KEY_PARALYZE,  ANIM_Whacka_Still,
    STATUS_KEY_DIZZY,     ANIM_Whacka_Idle,
    STATUS_KEY_UNUSED,    ANIM_Whacka_Idle,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_UNUSED,              0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,                0,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_UNUSED,         0,
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
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -5 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_HEALTH_BAR,
    .type = ACTOR_TYPE_WHACKA,
    .level = ACTOR_LEVEL_WHACKA,
    .maxHP = 99,
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
    .powerBounceChance = 50,
    .coinReward = 0,
    .size = { 47, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -20, 40 },
    .statusTextOffset = { 10, 30 },
};

API_CALLABLE(N(IsHitEightTimes)) {
    script->varTable[0] = 0;
    if (evt_get_variable(nullptr, GB_IWA00_Whacka_HitCount) >= 8) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_SpawnedBump, false)
    Call(N(IsHitEightTimes))
    IfEq(LVar0, 0)
        Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_INVISIBLE | ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY, true)
        Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, true)
    EndIf
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
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HIT_WHACKA)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Whacka_Idle)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Whacka_Hurt)
            ExecWait(N(EVS_MakeWhackaBump))
            ExecWait(EVS_Enemy_Hit)
            Call(RandInt, 100, LVar0)
            IfLe(LVar0, 100)
                ExecWait(N(EVS_Death))
                Return
            EndIf
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Whacka_Idle)
            SetConst(LVar2, ANIM_Whacka_Idle)
            ExecWait(N(EVS_MakeWhackaBump))
            ExecWait(EVS_Enemy_Hit)
            Call(RandInt, 100, LVar0)
            IfLe(LVar0, 100)
                ExecWait(N(EVS_Death))
                Return
            EndIf
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Whacka_Idle)
            SetConst(LVar2, ANIM_Whacka_Idle)
            ExecWait(N(EVS_MakeWhackaBump))
            ExecWait(EVS_Enemy_Hit)
            IfGe(100, 100)
                ExecWait(N(EVS_Death))
                Return
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Whacka_Idle)
                ExecWait(EVS_Enemy_Death)
                Return
            EndIf
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Whacka_Idle)
            ExecWait(EVS_Enemy_SpinSmashHit)
            Call(RandInt, 100, LVar0)
            IfLe(LVar0, 100)
                ExecWait(N(EVS_Death))
                Return
            EndIf
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Whacka_Idle)
            ExecWait(EVS_Enemy_SpinSmashHit)
            IfGe(100, 100)
                ExecWait(N(EVS_Death))
                Return
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Whacka_Idle)
                ExecWait(EVS_Enemy_Death)
                Return
            EndIf
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Whacka_Idle)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Whacka_Idle)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Whacka_Idle)
            ExecWait(EVS_Enemy_ReturnHome)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Whacka_Idle)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Whacka_Idle)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_ZERO_DAMAGE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Whacka_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        CaseEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Whacka_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
            Call(RandInt, 100, LVar0)
            IfLe(LVar0, 100)
                ExecWait(N(EVS_Death))
                Return
            EndIf
        CaseEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Whacka_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
            Call(RandInt, 100, LVar0)
            IfLe(LVar0, 100)
                ExecWait(N(EVS_Death))
                Return
            EndIf
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Whacka_Hurt)
            ExecWait(N(EVS_MakeWhackaBump))
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            IfGe(100, 100)
                ExecWait(N(EVS_Death))
                Return
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_Whacka_Idle)
                ExecWait(EVS_Enemy_Death)
                Return
            EndIf
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Whacka_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Whacka_Idle)
            SetConst(LVar2, ANIM_Whacka_Idle)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Whacka_Idle)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Whacka_Idle)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(RandInt, 100, LVar0)
    IfLe(LVar0, 100)
        ExecWait(N(EVS_Death))
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_MakeWhackaBump) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_SpawnedBump, true)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HIT_WHACKA)
    Thread
        Wait(15)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Whacka_Idle)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 5)
        Add(LVar1, 20)
        Add(LVar2, 10)
        Call(MakeItemEntity, ITEM_WHACKAS_BUMP, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS, 0)
    EndThread
    Return
    End
};

EvtScript N(EVS_Death) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Whacka_Burrow)
    Wait(40)
    Call(GetActorVar, ACTOR_SELF, AVAR_SpawnedBump, LVar0)
    IfNe(LVar0, false)
        Call(SetBattleFlagBits2, BS_FLAGS2_DROP_WHACKA_BUMP, true)
    EndIf
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET, true)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_INVISIBLE | ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY, true)
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};
