#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/ShyStackGuy.h"
#include "sprite/npc/ShyStackDamage.h"
#include "sprite/npc/ShyStackRock.h"
#include "sprite/npc/GeneralGuy.h"
#include "sprite/npc/ShyGuy.h"

#define NAMESPACE b_area_omo2_3_shy_stack

API_CALLABLE(func_80231000_54CC70) {
    Bytecode* args = script->ptrReadPos;

    evt_get_variable(script, args[1]);
    return ApiStatus_DONE2;
}

extern s32 N(IdleAnimations)[];
extern s32 N(IdleAnimations_rock)[];
extern s32 N(IdleAnimations_damage)[];
extern s32 N(IdleAnimations_shy_guy)[];

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(80235168);
extern EvtScript N(launch_rock);
extern EvtScript N(onDeath);
extern EvtScript N(onSpinSmashLaunchDeath);
extern EvtScript N(onSpinSmash);
extern EvtScript N(doSpinSmashHitLastGuy);
extern EvtScript N(doSpinSmashHit);

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 60,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 60,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 90,
    STATUS_SHRINK, 75,
    STATUS_STOP, 60,
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

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 20 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 67 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 50 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 33 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 16 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_rock),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 7,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_rock),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 8,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_rock),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 9,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_rock),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 10,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_damage),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 11,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_shy_guy),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 12,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_shy_guy),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 13,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_shy_guy),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 14,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_shy_guy),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_SHY_STACK,
    .level = 0,
    .maxHP = 10,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 30, 75 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 75 },
    .statusMessageOffset = { 10, 65 },
};

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL, ANIM_ShyStackGuy_Anim04,
    STATUS_STONE, ANIM_ShyStackGuy_Anim00,
    STATUS_SLEEP, ANIM_ShyStackGuy_Anim00,
    STATUS_POISON, ANIM_ShyStackGuy_Anim04,
    STATUS_STOP, ANIM_ShyStackGuy_Anim00,
    STATUS_STATIC, ANIM_ShyStackGuy_Anim00,
    STATUS_PARALYZE, ANIM_ShyStackGuy_Anim00,
    STATUS_PARALYZE, ANIM_ShyStackGuy_Anim00,
    STATUS_DIZZY, ANIM_ShyStackGuy_Anim0C,
    STATUS_DIZZY, ANIM_ShyStackGuy_Anim0C,
    STATUS_FEAR, ANIM_ShyStackGuy_Anim00,
    STATUS_END,
};

s32 N(IdleAnimations2)[] = {
    STATUS_NORMAL, ANIM_ShyStackGuy_Anim05,
    STATUS_STONE, ANIM_ShyStackGuy_Anim01,
    STATUS_SLEEP, ANIM_ShyStackGuy_Anim01,
    STATUS_POISON, ANIM_ShyStackGuy_Anim05,
    STATUS_STOP, ANIM_ShyStackGuy_Anim01,
    STATUS_STATIC, ANIM_ShyStackGuy_Anim01,
    STATUS_PARALYZE, ANIM_ShyStackGuy_Anim01,
    STATUS_PARALYZE, ANIM_ShyStackGuy_Anim01,
    STATUS_DIZZY, ANIM_ShyStackGuy_Anim0D,
    STATUS_DIZZY, ANIM_ShyStackGuy_Anim0D,
    STATUS_FEAR, ANIM_ShyStackGuy_Anim01,
    STATUS_END,
};

s32 N(IdleAnimations3)[] = {
    STATUS_NORMAL, ANIM_ShyStackGuy_Anim06,
    STATUS_STONE, ANIM_ShyStackGuy_Anim02,
    STATUS_SLEEP, ANIM_ShyStackGuy_Anim02,
    STATUS_POISON, ANIM_ShyStackGuy_Anim06,
    STATUS_STOP, ANIM_ShyStackGuy_Anim02,
    STATUS_STATIC, ANIM_ShyStackGuy_Anim02,
    STATUS_PARALYZE, ANIM_ShyStackGuy_Anim02,
    STATUS_PARALYZE, ANIM_ShyStackGuy_Anim02,
    STATUS_DIZZY, ANIM_ShyStackGuy_Anim0E,
    STATUS_DIZZY, ANIM_ShyStackGuy_Anim0E,
    STATUS_FEAR, ANIM_ShyStackGuy_Anim02,
    STATUS_END,
};

s32 N(IdleAnimations4)[] = {
    STATUS_NORMAL, ANIM_ShyStackGuy_Anim07,
    STATUS_STONE, ANIM_ShyStackGuy_Anim03,
    STATUS_SLEEP, ANIM_ShyStackGuy_Anim03,
    STATUS_POISON, ANIM_ShyStackGuy_Anim07,
    STATUS_STOP, ANIM_ShyStackGuy_Anim03,
    STATUS_STATIC, ANIM_ShyStackGuy_Anim03,
    STATUS_PARALYZE, ANIM_ShyStackGuy_Anim03,
    STATUS_PARALYZE, ANIM_ShyStackGuy_Anim03,
    STATUS_DIZZY, ANIM_ShyStackGuy_Anim0F,
    STATUS_DIZZY, ANIM_ShyStackGuy_Anim0F,
    STATUS_FEAR, ANIM_ShyStackGuy_Anim03,
    STATUS_END,
};

s32 N(IdleAnimations_rock)[] = {
    STATUS_NORMAL, ANIM_ShyStackRock_Anim00,
    STATUS_END,
};

s32 N(IdleAnimations_damage)[] = {
    STATUS_NORMAL, ANIM_ShyStackDamage_Anim00,
    STATUS_END,
};

s32 N(IdleAnimations_shy_guy)[] = {
    STATUS_NORMAL, ANIM_ShyGuy_Red_Anim01,
    STATUS_END,
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, ANIM_ShyStackGuy_Anim00)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, ANIM_ShyStackGuy_Anim04)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, ANIM_ShyStackGuy_Anim08)
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, ANIM_ShyStackGuy_Anim10)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, ANIM_ShyStackGuy_Anim14)
    EVT_CALL(SetActorVar, ACTOR_SELF, 6, ANIM_ShyStackGuy_Anim1B)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_SET(LVar0, 10)
        EVT_CALL(SetPartPos, ACTOR_SELF, 14, LVar0, 200, 0)
        EVT_CALL(SetPartPos, ACTOR_SELF, 13, LVar0, 200, 0)
        EVT_CALL(SetPartPos, ACTOR_SELF, 12, LVar0, 200, 0)
        EVT_CALL(SetPartPos, ACTOR_SELF, 11, LVar0, 200, 0)
        EVT_THREAD
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 14, SOUND_301)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 14, ANIM_ShyGuy_Red_Anim0A)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 14, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 14, EVT_FLOAT(1.0))
            EVT_CALL(SetPartSounds, ACTOR_SELF, 14, ACTOR_SOUND_JUMP, 0, 0)
            EVT_CALL(FallPartTo, ACTOR_SELF, 14, LVar0, 0, 0, 36)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 14, SOUND_2064)
            EVT_CALL(SetAnimation, ACTOR_SELF, 14, ANIM_ShyGuy_Red_Anim07)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(36)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 13, SOUND_301)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(31)
            EVT_CALL(SetAnimation, ACTOR_SELF, 13, ANIM_ShyGuy_Red_Anim0A)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 13, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 13, EVT_FLOAT(1.0))
            EVT_CALL(SetPartSounds, ACTOR_SELF, 13, ACTOR_SOUND_JUMP, 0, 0)
            EVT_CALL(FallPartTo, ACTOR_SELF, 13, LVar0, 18, 0, 32)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 13, SOUND_2064)
            EVT_CALL(SetAnimation, ACTOR_SELF, 13, ANIM_ShyGuy_Red_Anim07)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -5, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, 0, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(67)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 12, SOUND_301)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(62)
            EVT_CALL(SetAnimation, ACTOR_SELF, 12, ANIM_ShyGuy_Red_Anim0A)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 12, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 12, EVT_FLOAT(1.0))
            EVT_CALL(SetPartSounds, ACTOR_SELF, 12, ACTOR_SOUND_JUMP, 0, 0)
            EVT_CALL(FallPartTo, ACTOR_SELF, 12, LVar0, 36, 0, 28)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 12, SOUND_2064)
            EVT_CALL(SetAnimation, ACTOR_SELF, 12, ANIM_ShyGuy_Red_Anim07)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -3, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -6, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -4, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, 0, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(98)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 11, SOUND_301)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(93)
            EVT_CALL(SetAnimation, ACTOR_SELF, 11, ANIM_ShyGuy_Red_Anim0A)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 11, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 11, EVT_FLOAT(1.0))
            EVT_CALL(SetPartSounds, ACTOR_SELF, 11, ACTOR_SOUND_JUMP, 0, 0)
            EVT_CALL(FallPartTo, ACTOR_SELF, 11, LVar0, 54, 0, 24)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 11, SOUND_2064)
            EVT_CALL(SetAnimation, ACTOR_SELF, 11, ANIM_ShyGuy_Red_Anim07)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 12, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -1, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 11, 0, -3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 12, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -3, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 11, 0, -5, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 12, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -1, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 11, 0, -3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 12, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 11, 0, 0, 0)
            EVT_WAIT(7)
            EVT_CALL(GetPartOffset, ACTOR_SELF, 14, LVar0, LVar1, LVar2)
            EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 11, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 12, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 13, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 14, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_END_THREAD
    EVT_ELSE
        EVT_CALL(SetPartPos, ACTOR_SELF, 14, 200, 0, 47)
        EVT_CALL(SetPartPos, ACTOR_SELF, 13, 200, 0, 47)
        EVT_CALL(SetPartPos, ACTOR_SELF, 12, 200, 0, 47)
        EVT_CALL(SetPartPos, ACTOR_SELF, 11, 200, 0, 47)
        EVT_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 14, ANIM_ShyGuy_Red_Anim04)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 14, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 14, EVT_FLOAT(4.0))
            EVT_CALL(RunPartTo, ACTOR_SELF, 14, 55, 0, 47, FALSE)
            EVT_CALL(RunPartTo, ACTOR_SELF, 14, 50, 0, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 14, ANIM_ShyGuy_Red_Anim07)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(31)
            EVT_CALL(SetAnimation, ACTOR_SELF, 13, ANIM_ShyGuy_Red_Anim04)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 13, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 13, EVT_FLOAT(4.0))
            EVT_CALL(RunPartTo, ACTOR_SELF, 13, 55, 0, 47, 36)
            EVT_CALL(SetAnimation, ACTOR_SELF, 13, ANIM_ShyGuy_Red_Anim09)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 13, EVT_FLOAT(1.0))
            EVT_CALL(JumpPartTo, ACTOR_SELF, 13, 50, 18, 0, 20, TRUE)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 13, SOUND_2064)
            EVT_CALL(SetAnimation, ACTOR_SELF, 13, ANIM_ShyGuy_Red_Anim07)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -5, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, 0, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(77)
            EVT_CALL(SetAnimation, ACTOR_SELF, 13, ANIM_ShyGuy_Red_Anim0A)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(62)
            EVT_CALL(SetAnimation, ACTOR_SELF, 12, ANIM_ShyGuy_Red_Anim04)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 12, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 12, EVT_FLOAT(4.0))
            EVT_CALL(RunPartTo, ACTOR_SELF, 12, 55, 0, 47, 36)
            EVT_CALL(SetAnimation, ACTOR_SELF, 12, ANIM_ShyGuy_Red_Anim09)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 12, EVT_FLOAT(1.0))
            EVT_CALL(JumpPartTo, ACTOR_SELF, 12, 50, 36, 0, 20, TRUE)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 12, SOUND_2064)
            EVT_CALL(SetAnimation, ACTOR_SELF, 12, ANIM_ShyGuy_Red_Anim07)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -3, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -5, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, 0, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(108)
            EVT_CALL(SetAnimation, ACTOR_SELF, 12, ANIM_ShyGuy_Red_Anim0A)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 11, ANIM_ShyGuy_Red_Anim04)
            EVT_WAIT(143)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 11, ANIM_ShyGuy_Red_Anim09)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 11, ANIM_ShyGuy_Red_Anim0A)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT(133)
            EVT_CALL(GetActorPos, ACTOR_ENEMY0, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, -3)
            EVT_CALL(SetPartPos, ACTOR_SELF, 11, LVar0, LVar1, LVar2)
            EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim05)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 11, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_ADD(LVar0, -20)
            EVT_ADD(LVar1, 18)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 11, EVT_FLOAT(0.6))
            EVT_CALL(JumpPartTo, ACTOR_SELF, 11, LVar0, LVar1, LVar2, 20, TRUE)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 11, EVT_FLOAT(0.3))
            EVT_CALL(JumpPartTo, ACTOR_SELF, 11, 50, 54, 0, 30, TRUE)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 11, SOUND_2064)
            EVT_CALL(SetAnimation, ACTOR_SELF, 11, ANIM_ShyGuy_Red_Anim07)
            EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim04)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 12, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -1, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 11, 0, -3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 12, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -3, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 11, 0, -5, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 12, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -1, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 11, 0, -3, 0)
            EVT_WAIT(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 12, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 11, 0, 0, 0)
            EVT_WAIT(12)
            EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, ANIM_GeneralGuy_Anim03)
            EVT_CALL(GetPartOffset, ACTOR_SELF, 14, LVar0, LVar1, LVar2)
            EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 11, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 12, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 13, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 14, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_CALL(SetActorVar, ACTOR_ENEMY1, 2, 4)
        EVT_END_THREAD
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
                EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVarA)
                EVT_IF_EQ(LVarA, 3)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
                    EVT_EXEC_WAIT(EVS_DoNormalHit)
                EVT_ELSE
                    EVT_CALL(GetDamageSource, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_OR_EQ(DMG_SRC_SHELL_TOSS)
                        EVT_CASE_OR_EQ(DMG_SRC_POWER_SHELL)
                        EVT_CASE_OR_EQ(DMG_SRC_FIRE_SHELL)
                            EVT_EXEC_WAIT(N(80235168))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_SET_CONST(LVar0, 1)
                            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
                            EVT_EXEC_WAIT(EVS_DoNormalHit)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
                EVT_EXEC_WAIT(EVS_DoNormalHit)
                EVT_WAIT(10)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVarA)
                EVT_IF_EQ(LVarA, 3)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
                    EVT_EXEC_WAIT(EVS_DoNormalHit)
                    EVT_WAIT(10)
                EVT_ELSE
                    EVT_CALL(GetDamageSource, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_OR_EQ(DMG_SRC_SHELL_TOSS)
                        EVT_CASE_OR_EQ(DMG_SRC_POWER_SHELL)
                        EVT_CASE_OR_EQ(DMG_SRC_FIRE_SHELL)
                            EVT_EXEC_WAIT(N(80235168))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_SET_CONST(LVar0, 1)
                            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
                            EVT_EXEC_WAIT(EVS_DoNormalHit)
                            EVT_WAIT(10)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar2)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVarA)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_ELSE
                EVT_IF_EQ(LVarA, 3)
                    EVT_EXEC_WAIT(DoBurnHit)
                EVT_ELSE
                    EVT_CALL(GetDamageSource, LVarA)
                    EVT_SWITCH(LVarA)
                        EVT_CASE_OR_EQ(DMG_SRC_SHELL_TOSS)
                        EVT_CASE_OR_EQ(DMG_SRC_POWER_SHELL)
                        EVT_CASE_OR_EQ(DMG_SRC_FIRE_SHELL)
                            EVT_EXEC_WAIT(N(80235168))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_EXEC_WAIT(DoBurnHit)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar2)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVarA)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar1)
            EVT_ELSE
                EVT_IF_EQ(LVarA, 3)
                    EVT_EXEC_WAIT(DoBurnHit)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar1)
                EVT_ELSE
                    EVT_CALL(GetDamageSource, LVarA)
                    EVT_SWITCH(LVarA)
                        EVT_CASE_OR_EQ(DMG_SRC_SHELL_TOSS)
                        EVT_CASE_OR_EQ(DMG_SRC_POWER_SHELL)
                        EVT_CASE_OR_EQ(DMG_SRC_FIRE_SHELL)
                            EVT_EXEC_WAIT(N(80235168))
                            EVT_SET_CONST(LVar1, -1)
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_EXEC_WAIT(DoBurnHit)
                            EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar1)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
                EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(onSpinSmash))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
                EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(onSpinSmash))
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_LAUNCH_HIT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
                EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(80235168))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_LAUNCH_DEATH)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar5)
            EVT_IF_FLAG(LVar5, STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LVar0, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
                EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(80235168))
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
            EVT_EXEC_WAIT(N(onSpinSmashLaunchDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_SPIKE_TAUNT)
            EVT_CALL(GetBattleFlags, LVar2)
            EVT_IF_FLAG(LVar2, BS_FLAGS1_PARTNER_ACTING)
                EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
                EVT_IF_EQ(LVar2, MOVE_SPOOK)
                    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
            EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
            EVT_WAIT(1000)
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar2)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_WAIT(1000)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar2)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(rotate) = {
    EVT_SET(LVar0, 0)
    EVT_LABEL(0)
    EVT_SUB(LVar0, 30)
    EVT_IF_LT(LVar0, 0)
        EVT_ADD(LVar0, 360)
    EVT_END_IF
    EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(onSpinSmash) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVarA)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(doSpinSmashHit))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(doSpinSmashHit))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(doSpinSmashHit))
        EVT_CASE_EQ(3)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
            EVT_EXEC_WAIT(N(doSpinSmashHitLastGuy))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(doSpinSmashHitLastGuy) = {
    EVT_EXEC_GET_TID(N(rotate), LVarE)
    EVT_CALL(GetPartEventFlags, ACTOR_SELF, LVar0, LVarA)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(PlayerCreateTargetList, TARGET_FLAG_4 | TARGET_FLAG_10000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerID, LVar1)
    EVT_CALL(GetOwnerTarget, LVar0, LVar9)
    EVT_IF_NE(LVar1, LVar0)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_ADD(LVarF, 1)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_EQ(LVar0, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(GetOwnerTarget, LVar0, LVar9)
    EVT_CALL(GetActorFlags, LVar0, LVar1)
    EVT_IF_FLAG(LVar1, ACTOR_FLAG_TARGET_ONLY)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(DispatchDamageEvent, LVar0, 1, EVENT_SPIN_SMASH_LAUNCH_HIT)
    EVT_GOTO(1)
    EVT_LABEL(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(GetActorSize, ACTOR_SELF, LVar0, LVar3)
    EVT_DIV(LVar3, 2)
    EVT_SET(LVar4, 70)
    EVT_SUB(LVar4, LVar3)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar5, LVar4)
    EVT_SUB(LVar5, LVar0)
    EVT_IF_LT(LVar5, 6)
        EVT_SET(LVar5, 1)
    EVT_ELSE
        EVT_SET(LVar5, 0)
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, LVar5, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar6, LVar7, LVar8)
    EVT_SUB(LVar4, 18)
    EVT_IF_LE(LVar4, LVar6)
        EVT_SET(LVar4, LVar6)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_ELSE
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
        EVT_CALL(SetGoalToHome, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar4, LVar7, LVar8)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar4, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_END_IF
    EVT_KILL_THREAD(LVarE)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(fall_apart) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVarA)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, ANIM_ShyStackGuy_Anim01)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, ANIM_ShyStackGuy_Anim05)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, ANIM_ShyStackGuy_Anim09)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, ANIM_ShyStackGuy_Anim11)
            EVT_CALL(SetActorVar, ACTOR_SELF, 5, ANIM_ShyStackGuy_Anim15)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, ANIM_ShyStackGuy_Anim1C)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations2)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_MULTI_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_MULTI_TARGET, TRUE)
            EVT_CALL(SetActorSize, ACTOR_SELF, 62, EVT_IGNORE_ARG)
            EVT_CALL(func_8026DA94, ACTOR_SELF, 0, -20, 0, -20)
            EVT_CALL(SetPartSize, ACTOR_SELF, 1, 57, 30)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, 2)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, ANIM_ShyStackGuy_Anim02)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, ANIM_ShyStackGuy_Anim06)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, ANIM_ShyStackGuy_Anim0A)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, ANIM_ShyStackGuy_Anim12)
            EVT_CALL(SetActorVar, ACTOR_SELF, 5, ANIM_ShyStackGuy_Anim16)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, ANIM_ShyStackGuy_Anim1D)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations3)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_MULTI_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_MULTI_TARGET, TRUE)
            EVT_CALL(SetActorSize, ACTOR_SELF, 44, EVT_IGNORE_ARG)
            EVT_CALL(func_8026DA94, ACTOR_SELF, 0, -40, 0, -40)
            EVT_CALL(SetPartSize, ACTOR_SELF, 1, 39, 30)
        EVT_CASE_EQ(2)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, 3)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, ANIM_ShyStackGuy_Anim03)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, ANIM_ShyStackGuy_Anim07)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, ANIM_ShyStackGuy_Anim0B)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, ANIM_ShyStackGuy_Anim13)
            EVT_CALL(SetActorVar, ACTOR_SELF, 5, ANIM_ShyStackGuy_Anim17)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, ANIM_ShyStackGuy_Anim1E)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations4)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_MULTI_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_NO_TARGET, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_NO_TARGET, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_MULTI_TARGET, TRUE)
            EVT_CALL(SetActorSize, ACTOR_SELF, 26, EVT_IGNORE_ARG)
            EVT_CALL(func_8026DA94, ACTOR_SELF, 0, -60, 0, -60)
            EVT_CALL(SetPartSize, ACTOR_SELF, 1, 21, 30)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(lower_actor_pos) = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_301)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 18)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SET(LVar3, LVar1)
        EVT_WAIT(2)
        EVT_SUB(LVar3, 1)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_WAIT(3)
        EVT_SUB(LVar3, 2)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_WAIT(2)
        EVT_SUB(LVar3, 3)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_WAIT(1)
        EVT_SUB(LVar3, 5)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_WAIT(1)
        EVT_SUB(LVar3, 7)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar3, 2)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar3, 3)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_WAIT(1)
        EVT_ADD(LVar3, 3)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_WAIT(1)
        EVT_SUB(LVar3, 3)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_WAIT(1)
        EVT_SUB(LVar3, 3)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_WAIT(1)
        EVT_SUB(LVar3, 2)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar3, LVar2)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2064)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(doSpinSmashHit) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(func_80231000_54CC70, EVT_PTR("X"), LVar0)
    EVT_CALL(func_80231000_54CC70, EVT_PTR("Y"), LVar1)
    EVT_CALL(func_80231000_54CC70, EVT_PTR("Z"), LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 10, ANIM_ShyStackDamage_Anim00)
    EVT_CALL(SetPartPos, ACTOR_SELF, 10, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartRotation, ACTOR_SELF, 10, 0, 0, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 10, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_EXEC_WAIT(N(fall_apart))
    EVT_SET_CONST(LVar0, 1)
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_EXEC_WAIT(N(lower_actor_pos))
    EVT_CALL(PlayerCreateTargetList, TARGET_FLAG_4 | TARGET_FLAG_8000 | TARGET_FLAG_10000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerID, LVar1)
    EVT_CALL(GetOwnerTarget, LVar0, LVar9)
    EVT_IF_NE(LVar1, LVar0)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_ADD(LVarF, 1)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_CALL(func_80231000_54CC70, EVT_PTR("T"), LVar0)
    EVT_IF_EQ(LVar0, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(GetOwnerTarget, LVar0, LVar9)
    EVT_CALL(GetActorFlags, LVar0, LVar1)
    EVT_IF_FLAG(LVar1, ACTOR_FLAG_TARGET_ONLY)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetOwnerID, LVar0)
    EVT_CALL(func_80231000_54CC70, EVT_PTR("MYSELF ID"), LVar0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(func_80231000_54CC70, EVT_PTR("TARGET ID"), LVar0)
    EVT_CALL(func_80231000_54CC70, EVT_PTR("TARGET PARTS ID"), LVar1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 10, EVT_FLOAT(0.1))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 10, EVT_FLOAT(7.0))
    EVT_CALL(func_80231000_54CC70, EVT_PTR("TX"), LVar0)
    EVT_CALL(func_80231000_54CC70, EVT_PTR("TY"), LVar1)
    EVT_CALL(func_80231000_54CC70, EVT_PTR("TZ"), LVar2)
    EVT_CALL(JumpPartTo, ACTOR_SELF, 10, LVar0, LVar1, LVar2, 0, TRUE)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(DispatchDamageEvent, LVar0, 1, EVENT_SPIN_SMASH_LAUNCH_HIT)
    EVT_GOTO(1)
    EVT_LABEL(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 10, EVT_FLOAT(0.1))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 10, EVT_FLOAT(6.0))
    EVT_CALL(GetActorSize, ACTOR_SELF, LVar0, LVar3)
    EVT_DIV(LVar3, 2)
    EVT_SET(LVar4, 70)
    EVT_SUB(LVar4, LVar3)
    EVT_CALL(GetPartOffset, ACTOR_SELF, 10, LVar0, LVar1, LVar2)
    EVT_SET(LVar5, LVar4)
    EVT_SUB(LVar5, LVar0)
    EVT_IF_LT(LVar5, 6)
        EVT_SET(LVar5, 1)
    EVT_ELSE
        EVT_SET(LVar5, 0)
    EVT_END_IF
    EVT_CALL(JumpPartTo, ACTOR_SELF, 10, LVar4, LVar1, LVar2, LVar5, TRUE)
    EVT_SUB(LVar4, 18)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 10, EVT_FLOAT(1.5))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 10, EVT_FLOAT(3.0))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 10, LVar4, LVar1, LVar2, 12, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 10, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(GetPartOffset, ACTOR_SELF, 10, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 10)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 10, SOUND_DEATH)
    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    EVT_SET(LVar0, 0)
    EVT_LOOP(12)
        EVT_CALL(SetPartRotation, ACTOR_SELF, 10, LVar0, 0, 0)
        EVT_ADD(LVar0, 8)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 10, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80235168) = {
    EVT_CALL(GetDamageSource, LVar0)
    EVT_IF_EQ(LVar0, DMG_SRC_FIRE_SHELL)
        EVT_CALL(SetAnimation, ACTOR_SELF, 10, ANIM_ShyStackDamage_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 10, ANIM_ShyStackDamage_Anim00)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(func_80231000_54CC70, EVT_PTR("X"), LVar0)
    EVT_CALL(func_80231000_54CC70, EVT_PTR("Y"), LVar1)
    EVT_CALL(func_80231000_54CC70, EVT_PTR("Z"), LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, 10, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartRotation, ACTOR_SELF, 10, 0, 0, 0)
    EVT_EXEC_WAIT(N(fall_apart))
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar1)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar1)
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 10, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_EXEC_WAIT(N(lower_actor_pos))
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(30)
            EVT_ADD(LVar0, 24)
            EVT_CALL(SetPartYaw, ACTOR_SELF, 10, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetPartYaw, ACTOR_SELF, 10, LVar0)
    EVT_END_THREAD
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 10, EVT_FLOAT(3.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 10, EVT_FLOAT(0.5))
    EVT_CALL(GetActorSize, ACTOR_SELF, LVar0, LVar3)
    EVT_DIV(LVar3, 2)
    EVT_SET(LVar4, 70)
    EVT_SUB(LVar4, LVar3)
    EVT_CALL(GetPartOffset, ACTOR_SELF, 10, LVar0, LVar1, LVar2)
    EVT_SET(LVar5, LVar4)
    EVT_SUB(LVar5, LVar0)
    EVT_IF_LT(LVar5, 6)
        EVT_SET(LVar5, 1)
    EVT_ELSE
        EVT_SET(LVar5, 0)
    EVT_END_IF
    EVT_CALL(JumpPartTo, ACTOR_SELF, 10, LVar4, LVar1, LVar2, LVar5, TRUE)
    EVT_SET(LVar1, 0)
    EVT_SUB(LVar0, 10)
    EVT_CALL(JumpPartTo, ACTOR_SELF, 10, LVar0, LVar1, LVar2, 10, TRUE)
    EVT_WAIT(20)
    EVT_CALL(GetPartOffset, ACTOR_SELF, 10, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 10)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 10, SOUND_DEATH)
    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    EVT_SET(LVar0, 0)
    EVT_LOOP(12)
        EVT_CALL(SetPartRotation, ACTOR_SELF, 10, LVar0, 0, 0)
        EVT_ADD(LVar0, 8)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 10, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 10, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetActorSize, ACTOR_SELF, LVar3, LVar4)
            EVT_DIV(LVar3, 2)
            EVT_ADD(LVar1, LVar3)
            EVT_ADD(LVar2, 5)
            EVT_DIVF(LVar3, EVT_FLOAT(10.0))
            EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, LVar3, 10, 0)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar0)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(GetActorVar, ACTOR_SELF, 6, LVar0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar0)
    EVT_WAIT(20)
    EVT_ADD(LVar0, 4)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2E7)
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2E8)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVar5, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 7, 0)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET(LVar5, 0)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 7, 4)
                EVT_CASE_EQ(1)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 7, 3)
                EVT_CASE_EQ(2)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 7, 2)
                EVT_CASE_EQ(3)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 7, 1)
                EVT_CASE_DEFAULT
                    EVT_CALL(SetActorVar, ACTOR_SELF, 7, 1)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_SET(LVar1, LVar5)
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_IF_LE(LVar0, 0)
        EVT_SET(LVar0, 0)
        EVT_EXEC(N(launch_rock))
    EVT_END_IF
    EVT_IF_LE(LVar0, 1)
        EVT_SET(LVar0, 1)
        EVT_EXEC(N(launch_rock))
    EVT_END_IF
    EVT_IF_LE(LVar0, 2)
        EVT_SET(LVar0, 2)
        EVT_EXEC(N(launch_rock))
    EVT_END_IF
    EVT_SET(LVar0, 3)
    EVT_EXEC(N(launch_rock))
    EVT_WAIT(10)
    EVT_CALL(GetActorVar, ACTOR_SELF, 7, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(2)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(3)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(4)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_DEFAULT
            EVT_SWITCH(LVarF)
                EVT_CASE_EQ(HIT_RESULT_LUCKY)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_CASE_DEFAULT
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_WAIT(15)
            EVT_WAIT(15)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(launch_rock) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarF)
    EVT_IF_FLAG(LVarF, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, 7, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, 8, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, 9, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_ADD(LVar3, -4)
                EVT_ADD(LVar4, 28)
                EVT_SET(LVar2, 9)
            EVT_CASE_EQ(1)
                EVT_ADD(LVar3, -4)
                EVT_ADD(LVar4, 21)
                EVT_SET(LVar2, 8)
            EVT_CASE_EQ(2)
                EVT_ADD(LVar3, -4)
                EVT_ADD(LVar4, 14)
                EVT_SET(LVar2, 7)
            EVT_CASE_DEFAULT
                EVT_ADD(LVar3, -4)
                EVT_ADD(LVar4, 7)
                EVT_SET(LVar2, 6)
        EVT_END_SWITCH
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, 7, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, 8, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, 9, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_ADD(LVar3, -10)
                EVT_ADD(LVar4, 72)
                EVT_SET(LVar2, 9)
            EVT_CASE_EQ(1)
                EVT_ADD(LVar3, -10)
                EVT_ADD(LVar4, 54)
                EVT_SET(LVar2, 8)
            EVT_CASE_EQ(2)
                EVT_ADD(LVar3, -10)
                EVT_ADD(LVar4, 36)
                EVT_SET(LVar2, 7)
            EVT_CASE_DEFAULT
                EVT_ADD(LVar3, -10)
                EVT_ADD(LVar4, 18)
                EVT_SET(LVar2, 6)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(SetPartSounds, ACTOR_SELF, LVar2, ACTOR_SOUND_JUMP, 0, 0)
    EVT_CALL(SetPartPos, ACTOR_SELF, LVar2, LVar3, LVar4, LVar5)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar2, ANIM_ShyStackRock_Anim00)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_WAIT(1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar6, LVar7, LVar8)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LVar2, EVT_FLOAT(12.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar2, EVT_FLOAT(1.0))
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_CALL(JumpPartTo, ACTOR_SELF, LVar2, LVar6, LVar7, LVar8, 9, TRUE)
            EVT_SUB(LVar6, 100)
            EVT_CALL(RandInt, 40, LVar9)
            EVT_SUB(LVar6, LVar9)
            EVT_ADD(LVar7, LVar9)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar2, EVT_FLOAT(0.8))
            EVT_CALL(JumpPartTo, ACTOR_SELF, LVar2, LVar6, LVar7, LVar8, 25, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_CASE_EQ(1)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar2, EVT_FLOAT(2.2))
                EVT_CASE_EQ(1)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar2, EVT_FLOAT(1.8))
                EVT_CASE_EQ(2)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar2, EVT_FLOAT(1.4))
                EVT_CASE_DEFAULT
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar2, EVT_FLOAT(1.0))
            EVT_END_SWITCH
            EVT_SET(LVar7, 0)
            EVT_CALL(RandInt, 35, LVar9)
            EVT_ADD(LVar9, 30)
            EVT_SUB(LVar6, LVar9)
            EVT_CALL(JumpPartTo, ACTOR_SELF, LVar2, LVar6, LVar7, LVar8, 9, TRUE)
            EVT_CALL(RandInt, 25, LVar9)
            EVT_ADD(LVar9, 45)
            EVT_SUB(LVar6, LVar9)
            EVT_CALL(JumpPartTo, ACTOR_SELF, LVar2, LVar6, LVar7, LVar8, 8, TRUE)
            EVT_SUB(LVar6, 25)
            EVT_CALL(JumpPartTo, ACTOR_SELF, LVar2, LVar6, LVar7, LVar8, 4, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(onDeath) = {
    EVT_EXEC_WAIT(EVS_AnimateDeath)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(GetActorVar, ACTOR_ENEMY1, 3, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_ENEMY1, 3, LVar0)
    EVT_IF_GE(LVar0, 2)
        EVT_CALL(func_8026BF48, 1)
    EVT_END_IF
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(onSpinSmashLaunchDeath) = {
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_SET(LVar2, 0)
    EVT_LOOP(24)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar2)
        EVT_ADD(LVar2, 30)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DEATH)
    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySound, SOUND_DEATH)
    EVT_CALL(DropStarPoints, ACTOR_SELF)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_SET(LVar3, 0)
    EVT_LOOP(12)
        EVT_CALL(SetActorRotation, ACTOR_SELF, LVar3, 0, 0)
        EVT_ADD(LVar3, 8)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(GetActorVar, ACTOR_ENEMY1, 3, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_ENEMY1, 3, LVar0)
    EVT_IF_GE(LVar0, 2)
        EVT_CALL(func_8026BF48, 1)
    EVT_END_IF
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};
