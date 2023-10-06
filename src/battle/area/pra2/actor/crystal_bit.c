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
        .idleAnimations = NULL,
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
        .idleAnimations = NULL,
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
        .idleAnimations = NULL,
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
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_RETURN
    EVT_END
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
    EVT_PLAY_EFFECT(EFFECT_MISC_PARTICLES, 1, NPC_DISPOSE_LOCATION, 24, 24, EVT_FLOAT(1.0), 5, 0, 0, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Bit_ParticlesEffect, LVarF)
    EVT_CHILD_THREAD
        EVT_CALL(N(UpdateCrystalBitEffect), LVarF)
    EVT_END_CHILD_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetOwnerID, LVar0)
            EVT_CALL(GetActorVar, ACTOR_KING, AVAR_King_CubeBitID, LVar3)
            EVT_IF_EQ(LVar0, LVar3)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim22)
                EVT_SET_CONST(LVar2, -1)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_KING, AVAR_King_SphereBitID, LVar3)
            EVT_IF_EQ(LVar0, LVar3)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim23)
                EVT_SET_CONST(LVar2, -1)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_KING, AVAR_King_PrismBitID, LVar3)
            EVT_IF_EQ(LVar0, LVar3)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim24)
                EVT_SET_CONST(LVar2, -1)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_CALL(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar1)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_CALL(HideHealthBar, ACTOR_SELF)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, 0, LVar3)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(GetOwnerID, LVar0)
            EVT_CALL(GetActorVar, ACTOR_KING, AVAR_King_CubeBitID, LVar1)
            EVT_IF_EQ(LVar0, LVar1)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim05)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_KING, AVAR_King_SphereBitID, LVar1)
            EVT_IF_EQ(LVar0, LVar1)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim06)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_KING, AVAR_King_PrismBitID, LVar1)
            EVT_IF_EQ(LVar0, LVar1)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_CrystalKing_Anim07)
            EVT_END_IF
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
            EVT_CALL(RandInt, 360, LVar0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(30.0), LVar0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, 0, LVar3)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(20.0), LVar0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, 0, LVar3)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(10.0), LVar0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, 0, LVar3)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SET(LVar0, 255)
            EVT_LOOP(20)
                EVT_SUB(LVar0, 12)
                EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bit_ParticlesEffect, LVar0)
            EVT_CALL(RemoveEffect, LVar0)
            EVT_CALL(RemoveActor, ACTOR_SELF)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetOwnerID, LVar0)
            EVT_CALL(GetActorVar, ACTOR_KING, AVAR_King_CubeBitID, LVar3)
            EVT_IF_EQ(LVar0, LVar3)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim22)
                EVT_SET_CONST(LVar2, -1)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_KING, AVAR_King_SphereBitID, LVar3)
            EVT_IF_EQ(LVar0, LVar3)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim23)
                EVT_SET_CONST(LVar2, -1)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_KING, AVAR_King_PrismBitID, LVar3)
            EVT_IF_EQ(LVar0, LVar3)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim24)
                EVT_SET_CONST(LVar2, -1)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_CALL(HideHealthBar, ACTOR_SELF)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, 0, LVar3)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
            EVT_CALL(RandInt, 360, LVar0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(30.0), LVar0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, 0, LVar3)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(20.0), LVar0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, 0, LVar3)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(AddVectorPolar, LVar1, LVar3, EVT_FLOAT(10.0), LVar0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, 0, LVar3)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SET(LVar0, 255)
            EVT_LOOP(20)
                EVT_SUB(LVar0, 12)
                EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bit_ParticlesEffect, LVar0)
            EVT_CALL(RemoveEffect, LVar0)
            EVT_CALL(RemoveActor, ACTOR_SELF)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Bit_ParticlesEffect, LVar0)
            EVT_CALL(RemoveEffect, LVar0)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_RETURN
    EVT_END
};
