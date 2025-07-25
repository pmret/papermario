#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/Gulpit.h"

#define NAMESPACE A(gulpit_rocks)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_RockType   = 0,
};

s32 N(BigRockAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Gulpit_Anim10,
    STATUS_END,
};

s32 N(SmallRockAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Gulpit_Anim12,
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
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 14 },
        .opacity = 255,
        .idleAnimations = N(BigRockAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -6 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_TARGET_ONLY | ACTOR_FLAG_NO_HEALTH_BAR | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_GULPIT_ROCKS,
    .level = ACTOR_LEVEL_GULPIT_ROCKS,
    .maxHP = 1,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 100,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 0,
    .size = { 32, 18 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(GetActorVar, ACTOR_SELF, AVAR_RockType, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(BigRockAnims)))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim10)
            Call(GetActorVar, ACTOR_SELF, AVAR_RockType, 0)
            Call(SetActorSize, ACTOR_SELF, 24, 15)
        CaseEq(1)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(SmallRockAnims)))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim12)
            Call(GetActorVar, ACTOR_SELF, AVAR_RockType, 1)
            Call(SetActorSize, ACTOR_SELF, 10, 8)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_SelectRockAnim) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_RockType, LVarA)
    Switch(LVarA)
        CaseEq(0)
        CaseEq(1)
            SetConst(LVar1, LVar2)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
        CaseOrEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Gulpit_Anim10)
            SetConst(LVar2, ANIM_Gulpit_Anim12)
            ExecWait(N(EVS_SelectRockAnim))
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_BEGIN_AIR_LIFT)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Gulpit_Anim10)
            SetConst(LVar2, ANIM_Gulpit_Anim12)
            ExecWait(N(EVS_SelectRockAnim))
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseOrEq(EVENT_BURN_DEATH)
        CaseOrEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Gulpit_Anim10)
            SetConst(LVar2, ANIM_Gulpit_Anim12)
            ExecWait(N(EVS_SelectRockAnim))
            ExecWait(EVS_Enemy_Hit)
            Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, true)
            Call(GetActorVar, ACTOR_SELF, AVAR_RockType, LVar0)
            Switch(LVar0)
                CaseEq(0)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim11)
                CaseEq(1)
                    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim13)
            EndSwitch
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_LANDING_DUST, 1, LVar0, LVar1, LVar2, 0, 0)
            Wait(30)
            Call(RemoveActor, ACTOR_SELF)
            Return
        EndCaseGroup
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Return
    End
};

