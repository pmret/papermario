#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Goompa.h"

#define NAMESPACE battle_partner_goompa

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Celebrate);
extern EvtScript N(runAway);
extern EvtScript N(runAwayFail);
extern EvtScript N(EVS_ExecuteAction);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

enum N(ActorVars) {
    AVAR_Unk_0      = 0,
    AVAR_Unk_1      = 1,
};

enum N(ActorParams) {
    DMG_UNK         = 0,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Goompa_Walk,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,             100,
    STATUS_KEY_POISON,            100,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,            100,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,            100,
    STATUS_KEY_STOP,              100,
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
        .index = PRT_MAIN,
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_GOOMBARIO,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .size = { 29, 26 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_Unk_0, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Unk_1, 0)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_PARTNER, false)
    Call(InterruptActionCommand)
    Call(GetLastEvent, ACTOR_PARTNER, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goompa_Injured)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Call(PlaySound, SOUND_NO_DAMGE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goompa_Injured)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_SPIKE_CONTACT)
            SetConst(LVar1, ANIM_Goompa_Injured)
            SetConst(LVar2, ANIM_Goompa_Run)
            SetConst(LVar3, ANIM_Goompa_Idle)
            ExecWait(EVS_Partner_SpikeContact)
        CaseEq(EVENT_BURN_CONTACT)
            SetConst(LVar0, ANIM_Goompa_Injured)
            SetConst(LVar1, ANIM_Goompa_Injured)
            SetConst(LVar2, ANIM_Goompa_Injured)
            SetConst(LVar3, ANIM_Goompa_Run)
            SetConst(LVar4, ANIM_Goompa_Idle)
            ExecWait(EVS_Partner_BurnContact)
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, 0)
            SetConst(LVar1, ANIM_Goompa_Injured)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_33)
        CaseEq(EVENT_RECOVER_FROM_KO)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Goompa_Idle)
            SetConst(LVar2, ANIM_Goompa_Run)
            ExecWait(EVS_Partner_Recover)
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_PARTNER, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_EXECUTE_ACTION)
            ExecWait(N(EVS_ExecuteAction))
        CaseEq(PHASE_CELEBRATE)
            ExecWait(N(EVS_Celebrate))
        CaseEq(PHASE_RUN_AWAY_START)
            ExecWait(N(runAway))
        CaseEq(PHASE_RUN_AWAY_FAIL)
            ExecWait(N(runAwayFail))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Celebrate) = {
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_Goompa_Celebrate)
    SetConst(LVar2, ANIM_Goompa_Walk)
    ExecWait(EVS_Partner_Celebrate)
    Return
    End
};

EvtScript N(runAway) = {
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_Goompa_Run)
    ExecWait(EVS_Partner_RunAway)
    Return
    End
};

EvtScript N(runAwayFail) = {
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(6.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_Goompa_Run)
    Call(SetActorYaw, ACTOR_PARTNER, 0)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_Goompa_Idle)
    Return
    End
};

EvtScript N(EVS_ExecuteAction) = {
    Return
    End
};
