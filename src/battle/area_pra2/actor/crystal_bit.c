#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/crystal_king.h"

#define NAMESPACE b_area_pra2_crystal_bit

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(nextTurn);

s32 N(idleAnimations_1)[] = {
    STATUS_NORMAL, NPC_ANIM_crystal_king_Palette_00_Anim_A,
    STATUS_END,
};

s32 N(idleAnimations_2)[] = {
    STATUS_NORMAL, NPC_ANIM_crystal_king_Palette_00_Anim_B,
    STATUS_END,
};

s32 N(idleAnimations_3)[] = {
    STATUS_NORMAL, NPC_ANIM_crystal_king_Palette_00_Anim_C,
    STATUS_END,
};

s32 N(defenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_FIRE, 0,
    ELEMENT_ICE, 99,
    ELEMENT_END,
};

s32 N(statusTable)[] = {
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
        .idleAnimations = N(idleAnimations_1),
        .defenseTable = N(defenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -10,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_20 | ACTOR_PART_FLAG_MULTI_TARGET | ACTOR_PART_FLAG_80000000,
        .index = 2,
        .posOffset = { 0, 50, 0 },
        .targetOffset = { 0, -34 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -10,
    },
};

ActorPartBlueprint N(parts_2)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 16 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_2),
        .defenseTable = N(defenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -10,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_20 | ACTOR_PART_FLAG_MULTI_TARGET | ACTOR_PART_FLAG_80000000,
        .index = 2,
        .posOffset = { 0, 50, 0 },
        .targetOffset = { 0, -34 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -10,
    },
};

ActorPartBlueprint N(parts_3)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 16 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_3),
        .defenseTable = N(defenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -10,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_20 | ACTOR_PART_FLAG_MULTI_TARGET | ACTOR_PART_FLAG_80000000,
        .index = 2,
        .posOffset = { 0, 50, 0 },
        .targetOffset = { 0, -34 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -10,
    },
};

ActorBlueprint N(1) = {
    .flags = ACTOR_FLAG_FLYING | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_CRYSTAL_BIT,
    .level = 0,
    .maxHP = 1,
    .partCount = ARRAY_COUNT(N(parts_1)),
    .partsData = N(parts_1),
    .script = &N(init),
    .statusTable = N(statusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
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
    .script = &N(init),
    .statusTable = N(statusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
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
    .script = &N(init),
    .statusTable = N(statusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
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
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_ADDR(N(nextTurn)))
    EVT_RETURN
    EVT_END
};

ApiStatus UpdateCrystalBitEffect(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);
    ActorPart* actorPart = get_actor_part(actor, 1);
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args);

    effect->data.miscParticles->scaleX = actorPart->scale.x * 24.0f;
    effect->data.miscParticles->scaleY = actorPart->scale.y * 24.0f;
    if (actorPart->flags & ACTOR_PART_FLAG_INVISIBLE) {
        effect->data.miscParticles->pos.x = actor->currentPos.x;
        effect->data.miscParticles->pos.y = -1000.0f;
        effect->data.miscParticles->pos.z = actor->currentPos.z;
    } else {
        effect->data.miscParticles->pos.x = actor->currentPos.x;
        effect->data.miscParticles->pos.y = actor->currentPos.y;
        effect->data.miscParticles->pos.z = actor->currentPos.z;
    }

    return ApiStatus_BLOCK;
}

EvtScript N(idle) = {
    EVT_CALL(PlayEffect, EFFECT_MISC_PARTICLES, 1, 0, -1000, 0, 24, 24, EVT_FLOAT(1.0), 5, 0, 0, 0, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, LW(15))
    EVT_CHILD_THREAD
        EVT_CALL(UpdateCrystalBitEffect, LW(15))
    EVT_END_CHILD_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetAnimation, ACTOR_SELF, 1, LW(1))
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetOwnerID, LW(0))
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, 4, LW(3))
            EVT_IF_EQ(LW(0), LW(3))
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_22)
                EVT_SET_CONST(LW(2), -1)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, 5, LW(3))
            EVT_IF_EQ(LW(0), LW(3))
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_23)
                EVT_SET_CONST(LW(2), -1)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, 6, LW(3))
            EVT_IF_EQ(LW(0), LW(3))
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_24)
                EVT_SET_CONST(LW(2), -1)
            EVT_END_IF
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetAnimation, ACTOR_SELF, 1, LW(1))
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetAnimation, ACTOR_SELF, 1, LW(1))
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_CALL(func_8027D32C, ACTOR_SELF)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_301)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(1), LW(2), LW(3))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(1), 0, LW(3))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(GetOwnerID, LW(0))
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, 4, LW(1))
            EVT_IF_EQ(LW(0), LW(1))
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_5)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, 5, LW(1))
            EVT_IF_EQ(LW(0), LW(1))
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_6)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, 6, LW(1))
            EVT_IF_EQ(LW(0), LW(1))
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_crystal_king_Palette_00_Anim_7)
            EVT_END_IF
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
            EVT_CALL(RandInt, 360, LW(0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(1), LW(2), LW(3))
            EVT_CALL(AddVectorPolar, LW(1), LW(3), EVT_FLOAT(30.0), LW(0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(1), 0, LW(3))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(AddVectorPolar, LW(1), LW(3), EVT_FLOAT(20.0), LW(0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(1), 0, LW(3))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(AddVectorPolar, LW(1), LW(3), EVT_FLOAT(10.0), LW(0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(1), 0, LW(3))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SET(LW(0), 255)
            EVT_LOOP(20)
                EVT_SUB(LW(0), 12)
                EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LW(0))
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_CALL(RemoveEffect, LW(0))
            EVT_CALL(RemoveActor, ACTOR_SELF)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetOwnerID, LW(0))
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, 4, LW(3))
            EVT_IF_EQ(LW(0), LW(3))
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_22)
                EVT_SET_CONST(LW(2), -1)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, 5, LW(3))
            EVT_IF_EQ(LW(0), LW(3))
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_23)
                EVT_SET_CONST(LW(2), -1)
            EVT_END_IF
            EVT_CALL(GetActorVar, ACTOR_ENEMY0, 6, LW(3))
            EVT_IF_EQ(LW(0), LW(3))
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_crystal_king_Palette_00_Anim_24)
                EVT_SET_CONST(LW(2), -1)
            EVT_END_IF
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_CALL(func_8027D32C, ACTOR_SELF)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_301)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(1), LW(2), LW(3))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(1), 0, LW(3))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
            EVT_CALL(RandInt, 360, LW(0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(1), LW(2), LW(3))
            EVT_CALL(AddVectorPolar, LW(1), LW(3), EVT_FLOAT(30.0), LW(0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(1), 0, LW(3))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(AddVectorPolar, LW(1), LW(3), EVT_FLOAT(20.0), LW(0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(1), 0, LW(3))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(AddVectorPolar, LW(1), LW(3), EVT_FLOAT(10.0), LW(0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(1), 0, LW(3))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SET(LW(0), 255)
            EVT_LOOP(20)
                EVT_SUB(LW(0), 12)
                EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LW(0))
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_CALL(RemoveEffect, LW(0))
            EVT_CALL(RemoveActor, ACTOR_SELF)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_CALL(RemoveEffect, LW(0))
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
