#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/CrystalKing.h"

#define NAMESPACE b_area_pra2_crystal_bit

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(nextTurn);

s32 N(IdleAnimations_1)[] = {
    STATUS_NORMAL, ANIM_CrystalKing_Anim0A,
    STATUS_END,
};

s32 N(IdleAnimations_2)[] = {
    STATUS_NORMAL, ANIM_CrystalKing_Anim0B,
    STATUS_END,
};

s32 N(IdleAnimations_3)[] = {
    STATUS_NORMAL, ANIM_CrystalKing_Anim0C,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_FIRE, 0,
    ELEMENT_ICE, 99,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 0,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 0,
    STATUS_STOP, 0,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(parts_1)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 16 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_1),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_20 | ACTOR_PART_FLAG_MULTI_TARGET | ACTOR_PART_FLAG_80000000,
        .index = 2,
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

ActorPartBlueprint N(parts_2)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 16 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_2),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_20 | ACTOR_PART_FLAG_MULTI_TARGET | ACTOR_PART_FLAG_80000000,
        .index = 2,
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

ActorPartBlueprint N(parts_3)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 16 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_3),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_20 | ACTOR_PART_FLAG_MULTI_TARGET | ACTOR_PART_FLAG_80000000,
        .index = 2,
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

ActorBlueprint N(1) = {
    .flags = ACTOR_FLAG_FLYING | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_CRYSTAL_BIT,
    .level = 0,
    .maxHP = 1,
    .partCount = ARRAY_COUNT(N(parts_1)),
    .partsData = N(parts_1),
    .initScript = &N(init),
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
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

ActorBlueprint N(2) = {
    .flags = ACTOR_FLAG_FLYING | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_CRYSTAL_BIT,
    .level = 0,
    .maxHP = 1,
    .partCount = ARRAY_COUNT(N(parts_2)),
    .partsData = N(parts_2),
    .initScript = &N(init),
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
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

ActorBlueprint N(3) = {
    .flags = ACTOR_FLAG_FLYING | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_CRYSTAL_BIT,
    .level = 0,
    .maxHP = 1,
    .partCount = ARRAY_COUNT(N(parts_3)),
    .partsData = N(parts_3),
    .initScript = &N(init),
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
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn)))
    EVT_RETURN
    EVT_END
};

API_CALLABLE(UpdateCrystalBitEffect) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);
    ActorPart* actorPart = get_actor_part(actor, 1);
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args);

    effect->data.miscParticles->scaleX = actorPart->scale.x * 24.0f;
    effect->data.miscParticles->scaleY = actorPart->scale.y * 24.0f;
    if (actorPart->flags & ACTOR_PART_FLAG_INVISIBLE) {
        effect->data.miscParticles->pos.x = actor->currentPos.x;
        effect->data.miscParticles->pos.y = NPC_DISPOSE_POS_Y;
        effect->data.miscParticles->pos.z = actor->currentPos.z;
    } else {
        effect->data.miscParticles->pos.x = actor->currentPos.x;
        effect->data.miscParticles->pos.y = actor->currentPos.y;
        effect->data.miscParticles->pos.z = actor->currentPos.z;
    }

    return ApiStatus_BLOCK;
}

EvtScript N(idle) = {
    EVT_PLAY_EFFECT(EFFECT_MISC_PARTICLES, 1, NPC_DISPOSE_LOCATION, 24, 24, EVT_FLOAT(1.0), 5, 0, 0, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, LVarF)
    EVT_CHILD_THREAD
        EVT_CALL(UpdateCrystalBitEffect, LVarF)
    EVT_END_CHILD_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetAnimation, ACTOR_SELF, 1, LVar1)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetOwnerID, LVar0)
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, 4, LVar3)
            EVT_IF_EQ(LVar0, LVar3)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim22)
                EVT_SET_CONST(LVar2, -1)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, 5, LVar3)
            EVT_IF_EQ(LVar0, LVar3)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim23)
                EVT_SET_CONST(LVar2, -1)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, 6, LVar3)
            EVT_IF_EQ(LVar0, LVar3)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim24)
                EVT_SET_CONST(LVar2, -1)
            EVT_END_IF
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetAnimation, ACTOR_SELF, 1, LVar1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetAnimation, ACTOR_SELF, 1, LVar1)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_CALL(func_8027D32C, ACTOR_SELF)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_301)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, 0, LVar3)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(GetOwnerID, LVar0)
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, 4, LVar1)
            EVT_IF_EQ(LVar0, LVar1)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim05)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, 5, LVar1)
            EVT_IF_EQ(LVar0, LVar1)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim06)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, 6, LVar1)
            EVT_IF_EQ(LVar0, LVar1)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_CrystalKing_Anim07)
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
                EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_CALL(RemoveEffect, LVar0)
            EVT_CALL(RemoveActor, ACTOR_SELF)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetOwnerID, LVar0)
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, 4, LVar3)
            EVT_IF_EQ(LVar0, LVar3)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim22)
                EVT_SET_CONST(LVar2, -1)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, 5, LVar3)
            EVT_IF_EQ(LVar0, LVar3)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim23)
                EVT_SET_CONST(LVar2, -1)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, 6, LVar3)
            EVT_IF_EQ(LVar0, LVar3)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_CrystalKing_Anim24)
                EVT_SET_CONST(LVar2, -1)
            EVT_END_IF
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_CALL(func_8027D32C, ACTOR_SELF)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_301)
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
                EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_CALL(RemoveEffect, LVar0)
            EVT_CALL(RemoveActor, ACTOR_SELF)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_CALL(RemoveEffect, LVar0)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn) = {
    EVT_RETURN
    EVT_END
};
