#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "animation_script.h"

#include "battle/area/omo2/actor/boss_common.h"

#define NAMESPACE b_area_omo2_light_bulb

typedef struct BulbFragment {
    /* 0x00 */ s32 type;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 scale;
    /* 0x14 */ s32 duration;
    /* 0x18 */ Vec3f vel;
    /* 0x24 */ f32 gravAccel;
} BulbFragment; // size = 0x28

extern AnimScript AS_ToyTank_CloseHatch;

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Hit);
extern EvtScript N(EVS_Death);
extern EvtScript N(EVS_ShakeTank);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_SHOCK,    0,
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
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 35 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -14 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_TATTLE | ACTOR_FLAG_NO_HEALTH_BAR,
    .type = ACTOR_TYPE_LIGHT_BULB,
    .level = ACTOR_LEVEL_LIGHT_BULB,
    .maxHP = 8,
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
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 30, 30 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    Call(SetActorPos, ACTOR_SELF, 116, 70, 0)
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
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
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            ExecWait(N(EVS_Hit))
        CaseOrEq(EVENT_HIT)
        CaseOrEq(EVENT_BURN_HIT)
            ExecWait(N(EVS_Hit))
        EndCaseGroup
        CaseEq(EVENT_SPIN_SMASH_HIT)
            ExecWait(N(EVS_Hit))
        CaseEq(EVENT_ZERO_DAMAGE)
            Call(GetActorVar, ACTOR_TANK, AVAR_Tank_HandlingEvent, LVar0)
            IfFalse(LVar0)
                Call(func_8026E914, LVar0, LVar1)
                Call(PlayModelAnimation, 0, Ref(AS_ToyTank_CloseHatch))
                Wait(30)
            EndIf
        CaseEq(EVENT_IMMUNE)
            Call(GetActorVar, ACTOR_TANK, AVAR_Tank_HandlingEvent, LVar0)
            IfFalse(LVar0)
                Call(PlayModelAnimation, 0, Ref(AS_ToyTank_CloseHatch))
                Wait(30)
            EndIf
        CaseEq(EVENT_AIR_LIFT_FAILED)
        CaseOrEq(EVENT_DEATH)
        CaseOrEq(EVENT_BURN_DEATH)
            ExecWait(N(EVS_Death))
            Return
        EndCaseGroup
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_SPIKE_CONTACT)
        CaseEq(EVENT_BURN_CONTACT)
        CaseEq(EVENT_SHOCK_HIT)
        CaseEq(EVENT_END_FIRST_STRIKE)
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Return
    End
};

EvtScript N(EVS_Hit) = {
    ExecWait(N(EVS_ShakeTank))
    Return
    End
};

EvtScript N(EVS_ShakeTank) = {
    Call(GetActorVar, ACTOR_TANK, AVAR_Tank_HandlingEvent, LVar0)
    IfFalse(LVar0)
        Call(PlayModelAnimation, 0, Ref(AS_ToyTank_CloseHatch))
        Wait(30)
    EndIf
    Return
    End
};

API_CALLABLE(N(SpawnShatterFX)) {
    s32 i;
    BulbFragment shards[] = {
        {
            .type = 1,
            .pos = { 117.0f, 102.0f, 0.0f },
            .vel = { 0.3f, 0.7f, 0.0f },
            .scale = 0.2f,
            .duration = 20,
            .gravAccel = -0.3f,
        },
        {
            .type = 0,
            .pos = { 117.0f, 82.0f, 11.0f },
            .vel = { 0.3f, 0.9f, 0.1f },
            .scale = 0.5f,
            .duration = 20,
            .gravAccel = -0.3f,
        },
        {
            .type = 0,
            .pos = { 117.0f, 92.0f, 14.0f },
            .vel = { 0.3f, 0.8f, 0.3f },
            .scale = 0.4f,
            .duration = 20,
            .gravAccel = -0.3f,
        },
        {
            .type = 1,
            .pos = { 125.0f, 82.0f, 0.0f },
            .vel = { 0.5f, 0.9f, 0.0f },
            .scale = 0.2f,
            .duration = 20,
            .gravAccel = -0.3f,
        },
        {
            .type = 0,
            .pos = { 108.0f, 82.0f, 0.0f },
            .vel = { -0.2f, 0.9f, 0.0f },
            .scale = 0.3f,
            .duration = 20,
            .gravAccel = -0.3f,
        },
        {
            .type = 0,
            .pos = { 105.0f, 92.0f, 0.0f },
            .vel = { -0.1f, 0.8f, 0.0f },
            .scale = 0.4f,
            .duration = 20,
            .gravAccel = -0.3f,
        },
        {
            .type = 1,
            .pos = { 127.0f, 92.0f, 0.0f },
            .vel = { 0.7f, 0.8f, 0.0f },
            .scale = 0.2f,
            .duration = 20,
            .gravAccel = -0.3f,
        },
        {
            .type = 0,
            .pos = { 117.0f, 97.0f, 7.0f },
            .vel = { 0.7f, 0.8f, 0.2f },
            .scale = 0.1f,
            .duration = 20,
            .gravAccel = -0.3f,
        },
        {
            .type = 0,
            .pos = { 117.0f, 87.0f, 7.0f },
            .vel = { 0.7f, 0.8f, 0.2f },
            .scale = 0.3f,
            .duration = 20,
            .gravAccel = -0.3f,
        },
        {
            .type = 0,
            .pos = { 111.0f, 97.0f, 3.0f },
            .vel = { 0.0f, 1.0f, 0.1f },
            .scale = 0.2f,
            .duration = 20,
            .gravAccel = -0.3f,
        },
        {
            .type = 0,
            .pos = { 111.0f, 92.0f, 7.0f },
            .vel = { 0.0f, 1.0f, 0.2f },
            .scale = 0.1f,
            .duration = 20,
            .gravAccel = -0.3f,
        },
        {
            .type = 0,
            .pos = { 111.0f, 87.0f, 3.0f },
            .vel = { 0.0f, 1.0f, 0.1f },
            .scale = 0.5f,
            .duration = 20,
            .gravAccel = -0.3f,
        },
        {
            .type = 1,
            .pos = { 123.0f, 97.0f, 3.0f },
            .vel = { 0.1f, 1.0f, 0.1f },
            .scale = 0.2f,
            .duration = 20,
            .gravAccel = -0.3f,
        },
        {
            .type = 0,
            .pos = { 123.0f, 92.0f, 7.0f },
            .vel = { 0.1f, 1.0f, 0.2f },
            .scale = 0.4f,
            .duration = 20,
            .gravAccel = -0.3f,
        },
        {
            .type = 0,
            .pos = { 123.0f, 87.0f, 3.0f },
            .vel = { 0.1f, 1.0f, 0.1f },
            .scale = 0.3f,
            .duration = 20,
            .gravAccel = -0.3f,
        },
    };

    for (i = 0; i < ARRAY_COUNT(shards); i++) {
        EffectInstance* effect = fx_ice_shard(shards[i].type, shards[i].pos.x, shards[i].pos.y,
                                              shards[i].pos.z, shards[i].scale, shards[i].duration);
        effect->data.iceShard->vel.x = shards[i].vel.x;
        effect->data.iceShard->vel.y = shards[i].vel.y;
        effect->data.iceShard->vel.z = shards[i].vel.z;
        effect->data.iceShard->gravAccel = shards[i].gravAccel;
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_Death) = {
    Call(PlaySoundAtActor, ACTOR_BULB, SOUND_TANK_BULB_SHATTER)
    Call(N(SpawnShatterFX))
    Call(EnableModel, MODEL_kyu3, FALSE)
    Call(EnableModel, MODEL_kyu1, FALSE)
    Call(GetActorVar, ACTOR_TANK, AVAR_Tank_BulbGlowEffect, LVar0)
    IfNe(LVar0, NULL)
        Call(RemoveEffect, LVar0)
        Call(SetActorVar, ACTOR_TANK, AVAR_Tank_BulbGlowEffect, NULL)
    EndIf
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};
