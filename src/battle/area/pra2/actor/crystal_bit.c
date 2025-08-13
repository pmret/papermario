#include "../area.h"
#include "sprite/npc/CrystalKing.h"
#include "crystal_king_common.h"

#define NAMESPACE A(crystal_bit)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_TARGET      = 2,
};

s32 N(CubeAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_CrystalKing_Anim0A,
    STATUS_END,
};

s32 N(SphereAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_CrystalKing_Anim0B,
    STATUS_END,
};

s32 N(PrismAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_CrystalKing_Anim0C,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_FIRE,     0,
    ELEMENT_ICE,     99,
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

ActorPartBlueprint N(CubeParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 16 },
        .opacity = 255,
        .idleAnimations = N(CubeAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_IGNORE_BELOW_CHECK | ACTOR_PART_FLAG_PRIMARY_TARGET | ACTOR_PART_FLAG_SKIP_MOVEMENT_ALLOC,
        .index = PRT_TARGET,
        .posOffset = { 0, 50, 0 },
        .targetOffset = { 0, -34 },
        .opacity = 255,
        .idleAnimations = nullptr,
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorPartBlueprint N(SphereParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 16 },
        .opacity = 255,
        .idleAnimations = N(SphereAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_IGNORE_BELOW_CHECK | ACTOR_PART_FLAG_PRIMARY_TARGET | ACTOR_PART_FLAG_SKIP_MOVEMENT_ALLOC,
        .index = PRT_TARGET,
        .posOffset = { 0, 50, 0 },
        .targetOffset = { 0, -34 },
        .opacity = 255,
        .idleAnimations = nullptr,
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorPartBlueprint N(PrismParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 16 },
        .opacity = 255,
        .idleAnimations = N(PrismAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_IGNORE_BELOW_CHECK | ACTOR_PART_FLAG_PRIMARY_TARGET | ACTOR_PART_FLAG_SKIP_MOVEMENT_ALLOC,
        .index = PRT_TARGET,
        .posOffset = { 0, 50, 0 },
        .targetOffset = { 0, -34 },
        .opacity = 255,
        .idleAnimations = nullptr,
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorBlueprint N(cube) = {
    .flags = ACTOR_FLAG_FLYING | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_CRYSTAL_BIT,
    .level = ACTOR_LEVEL_CRYSTAL_BIT,
    .maxHP = 1,
    .partCount = ARRAY_COUNT(N(CubeParts)),
    .partsData = N(CubeParts),
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
    .size = { 18, 15 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

ActorBlueprint N(sphere) = {
    .flags = ACTOR_FLAG_FLYING | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_CRYSTAL_BIT,
    .level = ACTOR_LEVEL_CRYSTAL_BIT,
    .maxHP = 1,
    .partCount = ARRAY_COUNT(N(SphereParts)),
    .partsData = N(SphereParts),
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
    .size = { 18, 15 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

ActorBlueprint N(prism) = {
    .flags = ACTOR_FLAG_FLYING | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_CRYSTAL_BIT,
    .level = ACTOR_LEVEL_CRYSTAL_BIT,
    .maxHP = 1,
    .partCount = ARRAY_COUNT(N(PrismParts)),
    .partsData = N(PrismParts),
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
    .size = { 18, 15 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Return
    End
};

API_CALLABLE(N(UpdateCrystalBitEffect)) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);
    ActorPart* actorPart = get_actor_part(actor, 1);
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args);

    effect->data.miscParticles->scaleX = actorPart->scale.x * 24.0f;
    effect->data.miscParticles->scaleY = actorPart->scale.y * 24.0f;
    if (actorPart->flags & ACTOR_PART_FLAG_INVISIBLE) {
        effect->data.miscParticles->pos.x = actor->curPos.x;
        effect->data.miscParticles->pos.y = NPC_DISPOSE_POS_Y;
        effect->data.miscParticles->pos.z = actor->curPos.z;
    } else {
        effect->data.miscParticles->pos.x = actor->curPos.x;
        effect->data.miscParticles->pos.y = actor->curPos.y;
        effect->data.miscParticles->pos.z = actor->curPos.z;
    }

    return ApiStatus_BLOCK;
}

EvtScript N(EVS_Idle) = {
    PlayEffect(EFFECT_MISC_PARTICLES, 1, NPC_DISPOSE_LOCATION, 24, 24, Float(1.0), 5, 0, 0, 0, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Bit_ParticlesEffect, LVarF)
    ChildThread
        Call(N(UpdateCrystalBitEffect), LVarF)
    EndChildThread
    Loop(0)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            Call(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            Call(GetOwnerID, LVar0)
            Call(GetActorVar, ACTOR_KING, AVAR_King_CubeBitID, LVar3)
            IfEq(LVar0, LVar3)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_CrystalKing_Anim22)
                SetConst(LVar2, -1)
            EndIf
            Call(GetActorVar, ACTOR_KING, AVAR_King_SphereBitID, LVar3)
            IfEq(LVar0, LVar3)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_CrystalKing_Anim23)
                SetConst(LVar2, -1)
            EndIf
            Call(GetActorVar, ACTOR_KING, AVAR_King_PrismBitID, LVar3)
            IfEq(LVar0, LVar3)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_CrystalKing_Anim24)
                SetConst(LVar2, -1)
            EndIf
            ExecWait(EVS_Enemy_BurnHit)
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            Call(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            Call(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
            ExecWait(EVS_Enemy_Hit)
            Call(HideHealthBar, ACTOR_SELF)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            Call(SetGoalPos, ACTOR_SELF, LVar1, 0, LVar3)
            Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
            Call(GetOwnerID, LVar0)
            Call(GetActorVar, ACTOR_KING, AVAR_King_CubeBitID, LVar1)
            IfEq(LVar0, LVar1)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim05)
            EndIf
            Call(GetActorVar, ACTOR_KING, AVAR_King_SphereBitID, LVar1)
            IfEq(LVar0, LVar1)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim06)
            EndIf
            Call(GetActorVar, ACTOR_KING, AVAR_King_PrismBitID, LVar1)
            IfEq(LVar0, LVar1)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim07)
            EndIf
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.2))
            Call(RandInt, 360, LVar0)
            Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            Call(AddVectorPolar, LVar1, LVar3, Float(30.0), LVar0)
            Call(SetGoalPos, ACTOR_SELF, LVar1, 0, LVar3)
            Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
            Call(AddVectorPolar, LVar1, LVar3, Float(20.0), LVar0)
            Call(SetGoalPos, ACTOR_SELF, LVar1, 0, LVar3)
            Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
            Call(AddVectorPolar, LVar1, LVar3, Float(10.0), LVar0)
            Call(SetGoalPos, ACTOR_SELF, LVar1, 0, LVar3)
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
            Set(LVar0, 255)
            Loop(20)
                Sub(LVar0, 12)
                Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
                Wait(1)
            EndLoop
            Call(GetActorVar, ACTOR_SELF, AVAR_Bit_ParticlesEffect, LVar0)
            Call(RemoveEffect, LVar0)
            Call(RemoveActor, ACTOR_SELF)
            Return
        CaseEq(EVENT_BURN_DEATH)
            Call(GetOwnerID, LVar0)
            Call(GetActorVar, ACTOR_KING, AVAR_King_CubeBitID, LVar3)
            IfEq(LVar0, LVar3)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_CrystalKing_Anim22)
                SetConst(LVar2, -1)
            EndIf
            Call(GetActorVar, ACTOR_KING, AVAR_King_SphereBitID, LVar3)
            IfEq(LVar0, LVar3)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_CrystalKing_Anim23)
                SetConst(LVar2, -1)
            EndIf
            Call(GetActorVar, ACTOR_KING, AVAR_King_PrismBitID, LVar3)
            IfEq(LVar0, LVar3)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_CrystalKing_Anim24)
                SetConst(LVar2, -1)
            EndIf
            ExecWait(EVS_Enemy_BurnHit)
            Call(HideHealthBar, ACTOR_SELF)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            Call(SetGoalPos, ACTOR_SELF, LVar1, 0, LVar3)
            Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.2))
            Call(RandInt, 360, LVar0)
            Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            Call(AddVectorPolar, LVar1, LVar3, Float(30.0), LVar0)
            Call(SetGoalPos, ACTOR_SELF, LVar1, 0, LVar3)
            Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
            Call(AddVectorPolar, LVar1, LVar3, Float(20.0), LVar0)
            Call(SetGoalPos, ACTOR_SELF, LVar1, 0, LVar3)
            Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
            Call(AddVectorPolar, LVar1, LVar3, Float(10.0), LVar0)
            Call(SetGoalPos, ACTOR_SELF, LVar1, 0, LVar3)
            Call(JumpToGoal, ACTOR_SELF, 5, false, true, false)
            Set(LVar0, 255)
            Loop(20)
                Sub(LVar0, 12)
                Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
                Wait(1)
            EndLoop
            Call(GetActorVar, ACTOR_SELF, AVAR_Bit_ParticlesEffect, LVar0)
            Call(RemoveEffect, LVar0)
            Call(RemoveActor, ACTOR_SELF)
            Return
        CaseEq(EVENT_BLOW_AWAY)
            Call(GetActorVar, ACTOR_SELF, AVAR_Bit_ParticlesEffect, LVar0)
            Call(RemoveEffect, LVar0)
            Return
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Return
    End
};
