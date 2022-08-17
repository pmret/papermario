#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/shy_stack_guy.h"
#include "sprite/npc/shy_stack_damage.h"
#include "sprite/npc/shy_stack_rock.h"
#include "sprite/npc/general_guy.h"
#include "sprite/npc/shy_guy.h"

#define NAMESPACE b_area_omo2_3_shy_stack

ApiStatus func_80231000_54CC70(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_get_variable(script, args[1]);
    return ApiStatus_DONE2;
}

extern s32 N(idleAnimations)[];
extern s32 N(idleAnimations_rock)[];
extern s32 N(idleAnimations_damage)[];
extern s32 N(idleAnimations_shy_guy)[];

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

s32 N(defenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable)[] = {
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
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 67 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -8,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 50 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -8,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 33 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -8,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 16 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -8,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_rock),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 7,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_rock),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 8,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_rock),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 9,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_rock),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 10,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_damage),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 11,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_shy_guy),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 12,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_shy_guy),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 13,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_shy_guy),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 14,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_shy_guy),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_SHY_STACK,
    .level = 0,
    .maxHP = 10,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .script = &N(init),
    .statusTable = N(statusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 30, 75 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 75 },
    .statusMessageOffset = { 10, 65 },
};

s32 N(idleAnimations)[] = {
    STATUS_NORMAL, NPC_ANIM_shy_stack_guy_Palette_00_Anim_4,
    STATUS_STONE, NPC_ANIM_shy_stack_guy_Palette_00_Anim_0,
    STATUS_SLEEP, NPC_ANIM_shy_stack_guy_Palette_00_Anim_0,
    STATUS_POISON, NPC_ANIM_shy_stack_guy_Palette_00_Anim_4,
    STATUS_STOP, NPC_ANIM_shy_stack_guy_Palette_00_Anim_0,
    STATUS_STATIC, NPC_ANIM_shy_stack_guy_Palette_00_Anim_0,
    STATUS_PARALYZE, NPC_ANIM_shy_stack_guy_Palette_00_Anim_0,
    STATUS_PARALYZE, NPC_ANIM_shy_stack_guy_Palette_00_Anim_0,
    STATUS_DIZZY, NPC_ANIM_shy_stack_guy_Palette_00_Anim_C,
    STATUS_DIZZY, NPC_ANIM_shy_stack_guy_Palette_00_Anim_C,
    STATUS_FEAR, NPC_ANIM_shy_stack_guy_Palette_00_Anim_0,
    STATUS_END,
};

s32 N(idleAnimations2)[] = {
    STATUS_NORMAL, NPC_ANIM_shy_stack_guy_Palette_00_Anim_5,
    STATUS_STONE, NPC_ANIM_shy_stack_guy_Palette_00_Anim_1,
    STATUS_SLEEP, NPC_ANIM_shy_stack_guy_Palette_00_Anim_1,
    STATUS_POISON, NPC_ANIM_shy_stack_guy_Palette_00_Anim_5,
    STATUS_STOP, NPC_ANIM_shy_stack_guy_Palette_00_Anim_1,
    STATUS_STATIC, NPC_ANIM_shy_stack_guy_Palette_00_Anim_1,
    STATUS_PARALYZE, NPC_ANIM_shy_stack_guy_Palette_00_Anim_1,
    STATUS_PARALYZE, NPC_ANIM_shy_stack_guy_Palette_00_Anim_1,
    STATUS_DIZZY, NPC_ANIM_shy_stack_guy_Palette_00_Anim_D,
    STATUS_DIZZY, NPC_ANIM_shy_stack_guy_Palette_00_Anim_D,
    STATUS_FEAR, NPC_ANIM_shy_stack_guy_Palette_00_Anim_1,
    STATUS_END,
};

s32 N(idleAnimations3)[] = {
    STATUS_NORMAL, NPC_ANIM_shy_stack_guy_Palette_00_Anim_6,
    STATUS_STONE, NPC_ANIM_shy_stack_guy_Palette_00_Anim_2,
    STATUS_SLEEP, NPC_ANIM_shy_stack_guy_Palette_00_Anim_2,
    STATUS_POISON, NPC_ANIM_shy_stack_guy_Palette_00_Anim_6,
    STATUS_STOP, NPC_ANIM_shy_stack_guy_Palette_00_Anim_2,
    STATUS_STATIC, NPC_ANIM_shy_stack_guy_Palette_00_Anim_2,
    STATUS_PARALYZE, NPC_ANIM_shy_stack_guy_Palette_00_Anim_2,
    STATUS_PARALYZE, NPC_ANIM_shy_stack_guy_Palette_00_Anim_2,
    STATUS_DIZZY, NPC_ANIM_shy_stack_guy_Palette_00_Anim_E,
    STATUS_DIZZY, NPC_ANIM_shy_stack_guy_Palette_00_Anim_E,
    STATUS_FEAR, NPC_ANIM_shy_stack_guy_Palette_00_Anim_2,
    STATUS_END,
};

s32 N(idleAnimations4)[] = {
    STATUS_NORMAL, NPC_ANIM_shy_stack_guy_Palette_00_Anim_7,
    STATUS_STONE, NPC_ANIM_shy_stack_guy_Palette_00_Anim_3,
    STATUS_SLEEP, NPC_ANIM_shy_stack_guy_Palette_00_Anim_3,
    STATUS_POISON, NPC_ANIM_shy_stack_guy_Palette_00_Anim_7,
    STATUS_STOP, NPC_ANIM_shy_stack_guy_Palette_00_Anim_3,
    STATUS_STATIC, NPC_ANIM_shy_stack_guy_Palette_00_Anim_3,
    STATUS_PARALYZE, NPC_ANIM_shy_stack_guy_Palette_00_Anim_3,
    STATUS_PARALYZE, NPC_ANIM_shy_stack_guy_Palette_00_Anim_3,
    STATUS_DIZZY, NPC_ANIM_shy_stack_guy_Palette_00_Anim_F,
    STATUS_DIZZY, NPC_ANIM_shy_stack_guy_Palette_00_Anim_F,
    STATUS_FEAR, NPC_ANIM_shy_stack_guy_Palette_00_Anim_3,
    STATUS_END,
};

s32 N(idleAnimations_rock)[] = {
    STATUS_NORMAL, NPC_ANIM_shy_stack_rock_Palette_00_Anim_0,
    STATUS_END,
};

s32 N(idleAnimations_damage)[] = {
    STATUS_NORMAL, NPC_ANIM_shy_stack_damage_Palette_00_Anim_0,
    STATUS_END,
};

s32 N(idleAnimations_shy_guy)[] = {
    STATUS_NORMAL, NPC_ANIM_shy_guy_Palette_00_Anim_1,
    STATUS_END,
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, NPC_ANIM_shy_stack_guy_Palette_00_Anim_0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, NPC_ANIM_shy_stack_guy_Palette_00_Anim_4)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, NPC_ANIM_shy_stack_guy_Palette_00_Anim_8)
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, NPC_ANIM_shy_stack_guy_Palette_00_Anim_10)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, NPC_ANIM_shy_stack_guy_Palette_00_Anim_14)
    EVT_CALL(SetActorVar, ACTOR_SELF, 6, NPC_ANIM_shy_stack_guy_Palette_00_Anim_1B)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_SET(LW(0), 10)
        EVT_CALL(SetPartPos, ACTOR_SELF, 14, LW(0), 200, 0)
        EVT_CALL(SetPartPos, ACTOR_SELF, 13, LW(0), 200, 0)
        EVT_CALL(SetPartPos, ACTOR_SELF, 12, LW(0), 200, 0)
        EVT_CALL(SetPartPos, ACTOR_SELF, 11, LW(0), 200, 0)
        EVT_THREAD
            EVT_WAIT_FRAMES(5)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 14, SOUND_301)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 14, NPC_ANIM_shy_guy_Palette_00_Anim_A)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 14, ACTOR_PART_FLAG_INVISIBLE, 0)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 14, EVT_FLOAT(1.0))
            EVT_CALL(SetPartSounds, ACTOR_SELF, 14, 2, 0, 0)
            EVT_CALL(FallPartTo, ACTOR_SELF, 14, LW(0), 0, 0, 36)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 14, SOUND_2064)
            EVT_CALL(SetAnimation, ACTOR_SELF, 14, NPC_ANIM_shy_guy_Palette_00_Anim_7)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT_FRAMES(36)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 13, SOUND_301)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT_FRAMES(31)
            EVT_CALL(SetAnimation, ACTOR_SELF, 13, NPC_ANIM_shy_guy_Palette_00_Anim_A)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 13, ACTOR_PART_FLAG_INVISIBLE, 0)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 13, EVT_FLOAT(1.0))
            EVT_CALL(SetPartSounds, ACTOR_SELF, 13, 2, 0, 0)
            EVT_CALL(FallPartTo, ACTOR_SELF, 13, LW(0), 18, 0, 32)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 13, SOUND_2064)
            EVT_CALL(SetAnimation, ACTOR_SELF, 13, NPC_ANIM_shy_guy_Palette_00_Anim_7)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -3, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -5, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -3, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, 0, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT_FRAMES(67)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 12, SOUND_301)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT_FRAMES(62)
            EVT_CALL(SetAnimation, ACTOR_SELF, 12, NPC_ANIM_shy_guy_Palette_00_Anim_A)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 12, ACTOR_PART_FLAG_INVISIBLE, 0)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 12, EVT_FLOAT(1.0))
            EVT_CALL(SetPartSounds, ACTOR_SELF, 12, 2, 0, 0)
            EVT_CALL(FallPartTo, ACTOR_SELF, 12, LW(0), 36, 0, 28)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 12, SOUND_2064)
            EVT_CALL(SetAnimation, ACTOR_SELF, 12, NPC_ANIM_shy_guy_Palette_00_Anim_7)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -4, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -3, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -6, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -4, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, 0, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT_FRAMES(98)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 11, SOUND_301)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT_FRAMES(93)
            EVT_CALL(SetAnimation, ACTOR_SELF, 11, NPC_ANIM_shy_guy_Palette_00_Anim_A)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 11, ACTOR_PART_FLAG_INVISIBLE, 0)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 11, EVT_FLOAT(1.0))
            EVT_CALL(SetPartSounds, ACTOR_SELF, 11, 2, 0, 0)
            EVT_CALL(FallPartTo, ACTOR_SELF, 11, LW(0), 54, 0, 24)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 11, SOUND_2064)
            EVT_CALL(SetAnimation, ACTOR_SELF, 11, NPC_ANIM_shy_guy_Palette_00_Anim_7)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 12, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -1, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 11, 0, -3, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 12, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -3, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 11, 0, -5, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 12, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -1, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 11, 0, -3, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 12, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 11, 0, 0, 0)
            EVT_WAIT_FRAMES(7)
            EVT_CALL(GetPartOffset, ACTOR_SELF, 14, LW(0), LW(1), LW(2))
            EVT_CALL(ForceHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 11, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 12, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 13, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 14, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_INVISIBLE, 0)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, 14, NPC_ANIM_shy_guy_Palette_00_Anim_4)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 14, ACTOR_PART_FLAG_INVISIBLE, 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 14, EVT_FLOAT(4.0))
            EVT_CALL(RunPartTo, ACTOR_SELF, 14, 55, 0, 47, 0)
            EVT_CALL(RunPartTo, ACTOR_SELF, 14, 50, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 14, NPC_ANIM_shy_guy_Palette_00_Anim_7)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT_FRAMES(31)
            EVT_CALL(SetAnimation, ACTOR_SELF, 13, NPC_ANIM_shy_guy_Palette_00_Anim_4)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 13, ACTOR_PART_FLAG_INVISIBLE, 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 13, EVT_FLOAT(4.0))
            EVT_CALL(RunPartTo, ACTOR_SELF, 13, 55, 0, 47, 36)
            EVT_CALL(SetAnimation, ACTOR_SELF, 13, NPC_ANIM_shy_guy_Palette_00_Anim_9)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 13, EVT_FLOAT(1.0))
            EVT_CALL(JumpPartTo, ACTOR_SELF, 13, 50, 18, 0, 20, 1)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 13, SOUND_2064)
            EVT_CALL(SetAnimation, ACTOR_SELF, 13, NPC_ANIM_shy_guy_Palette_00_Anim_7)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -3, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -5, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -3, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, 0, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT_FRAMES(77)
            EVT_CALL(SetAnimation, ACTOR_SELF, 13, NPC_ANIM_shy_guy_Palette_00_Anim_A)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT_FRAMES(62)
            EVT_CALL(SetAnimation, ACTOR_SELF, 12, NPC_ANIM_shy_guy_Palette_00_Anim_4)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 12, ACTOR_PART_FLAG_INVISIBLE, 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 12, EVT_FLOAT(4.0))
            EVT_CALL(RunPartTo, ACTOR_SELF, 12, 55, 0, 47, 36)
            EVT_CALL(SetAnimation, ACTOR_SELF, 12, NPC_ANIM_shy_guy_Palette_00_Anim_9)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 12, EVT_FLOAT(1.0))
            EVT_CALL(JumpPartTo, ACTOR_SELF, 12, 50, 36, 0, 20, 1)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 12, SOUND_2064)
            EVT_CALL(SetAnimation, ACTOR_SELF, 12, NPC_ANIM_shy_guy_Palette_00_Anim_7)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -3, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -3, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -5, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -3, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, 0, 0)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT_FRAMES(108)
            EVT_CALL(SetAnimation, ACTOR_SELF, 12, NPC_ANIM_shy_guy_Palette_00_Anim_A)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 11, NPC_ANIM_shy_guy_Palette_00_Anim_4)
            EVT_WAIT_FRAMES(143)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 11, NPC_ANIM_shy_guy_Palette_00_Anim_9)
            EVT_WAIT_FRAMES(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 11, NPC_ANIM_shy_guy_Palette_00_Anim_A)
        EVT_END_THREAD
        EVT_THREAD
            EVT_WAIT_FRAMES(133)
            EVT_CALL(GetActorPos, ACTOR_ENEMY0, LW(0), LW(1), LW(2))
            EVT_ADD(LW(1), -3)
            EVT_CALL(SetPartPos, ACTOR_SELF, 11, LW(0), LW(1), LW(2))
            EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_5)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 11, ACTOR_PART_FLAG_INVISIBLE, 0)
            EVT_ADD(LW(0), -20)
            EVT_ADD(LW(1), 18)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 11, EVT_FLOAT(0.6))
            EVT_CALL(JumpPartTo, ACTOR_SELF, 11, LW(0), LW(1), LW(2), 20, 1)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 11, EVT_FLOAT(0.3))
            EVT_CALL(JumpPartTo, ACTOR_SELF, 11, 50, 54, 0, 30, 1)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 11, SOUND_2064)
            EVT_CALL(SetAnimation, ACTOR_SELF, 11, NPC_ANIM_shy_guy_Palette_00_Anim_7)
            EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_4)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 12, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -1, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 11, 0, -3, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 12, EVT_FLOAT(1.2), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -3, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 11, 0, -5, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 12, EVT_FLOAT(1.1), EVT_FLOAT(0.9), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, -1, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, -2, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 11, 0, -3, 0)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartScale, ACTOR_SELF, 14, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 13, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartScale, ACTOR_SELF, 12, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 13, 0, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 12, 0, 0, 0)
            EVT_CALL(SetPartDispOffset, ACTOR_SELF, 11, 0, 0, 0)
            EVT_WAIT_FRAMES(12)
            EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_3)
            EVT_CALL(GetPartOffset, ACTOR_SELF, 14, LW(0), LW(1), LW(2))
            EVT_CALL(ForceHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 11, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 12, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 13, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 14, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_INVISIBLE, 0)
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
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_FLAG(LW(0), STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LW(0), 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(10))
                EVT_IF_EQ(LW(10), 3)
                    EVT_SET_CONST(LW(0), 1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
                    EVT_EXEC_WAIT(DoNormalHit)
                EVT_ELSE
                    EVT_CALL(func_80269E80, LW(0))
                    EVT_SWITCH(LW(0))
                        EVT_CASE_OR_EQ(6)
                        EVT_CASE_OR_EQ(7)
                        EVT_CASE_OR_EQ(9)
                            EVT_EXEC_WAIT(N(80235168))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_SET_CONST(LW(0), 1)
                            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
                            EVT_EXEC_WAIT(DoNormalHit)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_FLAG(LW(0), STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LW(0), 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_WAIT_FRAMES(10)
            EVT_ELSE
                EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(10))
                EVT_IF_EQ(LW(10), 3)
                    EVT_SET_CONST(LW(0), 1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
                    EVT_EXEC_WAIT(DoNormalHit)
                    EVT_WAIT_FRAMES(10)
                EVT_ELSE
                    EVT_CALL(func_80269E80, LW(0))
                    EVT_SWITCH(LW(0))
                        EVT_CASE_OR_EQ(6)
                        EVT_CASE_OR_EQ(7)
                        EVT_CASE_OR_EQ(9)
                            EVT_EXEC_WAIT(N(80235168))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_SET_CONST(LW(0), 1)
                            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
                            EVT_EXEC_WAIT(DoNormalHit)
                            EVT_WAIT_FRAMES(10)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 4, LW(1))
            EVT_CALL(GetActorVar, ACTOR_SELF, 5, LW(2))
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(10))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(5))
            EVT_IF_FLAG(LW(5), STATUS_FLAG_SHRINK)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_ELSE
                EVT_IF_EQ(LW(10), 3)
                    EVT_EXEC_WAIT(DoBurnHit)
                EVT_ELSE
                    EVT_CALL(func_80269E80, LW(10))
                    EVT_SWITCH(LW(10))
                        EVT_CASE_OR_EQ(6)
                        EVT_CASE_OR_EQ(7)
                        EVT_CASE_OR_EQ(9)
                            EVT_EXEC_WAIT(N(80235168))
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_EXEC_WAIT(DoBurnHit)
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 4, LW(1))
            EVT_CALL(GetActorVar, ACTOR_SELF, 5, LW(2))
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(10))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(5))
            EVT_IF_FLAG(LW(5), STATUS_FLAG_SHRINK)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_CALL(GetActorVar, ACTOR_SELF, 5, LW(1))
            EVT_ELSE
                EVT_IF_EQ(LW(10), 3)
                    EVT_EXEC_WAIT(DoBurnHit)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 5, LW(1))
                EVT_ELSE
                    EVT_CALL(func_80269E80, LW(10))
                    EVT_SWITCH(LW(10))
                        EVT_CASE_OR_EQ(6)
                        EVT_CASE_OR_EQ(7)
                        EVT_CASE_OR_EQ(9)
                            EVT_EXEC_WAIT(N(80235168))
                            EVT_SET_CONST(LW(1), -1)
                        EVT_END_CASE_GROUP
                        EVT_CASE_DEFAULT
                            EVT_EXEC_WAIT(DoBurnHit)
                            EVT_CALL(GetActorVar, ACTOR_SELF, 5, LW(1))
                    EVT_END_SWITCH
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(5))
            EVT_IF_FLAG(LW(5), STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LW(0), 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(onSpinSmash))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(5))
            EVT_IF_FLAG(LW(5), STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LW(0), 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(onSpinSmash))
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_LAUNCH_HIT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(5))
            EVT_IF_FLAG(LW(5), STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LW(0), 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(80235168))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_LAUNCH_DEATH)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(5))
            EVT_IF_FLAG(LW(5), STATUS_FLAG_SHRINK)
                EVT_SET_CONST(LW(0), 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_ELSE
                EVT_EXEC_WAIT(N(80235168))
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
            EVT_EXEC_WAIT(N(onSpinSmashLaunchDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_SPIKE_TAUNT)
            EVT_CALL(GetBattleFlags, LW(2))
            EVT_IF_FLAG(LW(2), BS_FLAGS1_80000)
                EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
                EVT_IF_EQ(LW(2), 183)
                    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(1))
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
            EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
            EVT_WAIT_FRAMES(1000)
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(1))
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 2, LW(1))
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(2))
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(1000)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(2))
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(rotate) = {
    EVT_SET(LW(0), 0)
    EVT_LABEL(0)
    EVT_SUB(LW(0), 30)
    EVT_IF_LT(LW(0), 0)
        EVT_ADD(LW(0), 360)
    EVT_END_IF
    EVT_CALL(SetActorYaw, ACTOR_SELF, LW(0))
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(onSpinSmash) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(10))
    EVT_SWITCH(LW(10))
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(doSpinSmashHit))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(doSpinSmashHit))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(doSpinSmashHit))
        EVT_CASE_EQ(3)
            EVT_SET_CONST(LW(0), 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
            EVT_EXEC_WAIT(N(doSpinSmashHitLastGuy))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(doSpinSmashHitLastGuy) = {
    EVT_EXEC_GET_TID(N(rotate), LW(14))
    EVT_CALL(GetPartEventFlags, ACTOR_SELF, LW(0), LW(10))
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_CALL(PlayerCreateTargetList, 65540)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerID, LW(1))
    EVT_CALL(GetOwnerTarget, LW(0), LW(9))
    EVT_IF_NE(LW(1), LW(0))
        EVT_CALL(ChooseNextTarget, 0, LW(0))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_ADD(LW(15), 1)
    EVT_CALL(ChooseNextTarget, 0, LW(0))
    EVT_IF_EQ(LW(0), -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(GetOwnerTarget, LW(0), LW(9))
    EVT_CALL(GetActorFlags, LW(0), LW(1))
    EVT_IF_FLAG(LW(1), ACTOR_FLAG_TARGET_ONLY)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 0, LW(2))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetOwnerTarget, LW(0), LW(1))
    EVT_CALL(DispatchDamageEvent, LW(0), 1, 17)
    EVT_GOTO(1)
    EVT_LABEL(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(GetActorSize, ACTOR_SELF, LW(0), LW(3))
    EVT_DIV(LW(3), 2)
    EVT_SET(LW(4), 70)
    EVT_SUB(LW(4), LW(3))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SET(LW(5), LW(4))
    EVT_SUB(LW(5), LW(0))
    EVT_IF_LT(LW(5), 6)
        EVT_SET(LW(5), 1)
    EVT_ELSE
        EVT_SET(LW(5), 0)
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(4), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, LW(5), FALSE, TRUE, FALSE)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(6), LW(7), LW(8))
    EVT_SUB(LW(4), 18)
    EVT_IF_LE(LW(4), LW(6))
        EVT_SET(LW(4), LW(6))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(4), LW(1), LW(2))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_ELSE
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(4), LW(1), LW(2))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
        EVT_CALL(SetGoalToHome, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LW(4), LW(7), LW(8))
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(4), LW(1), LW(2))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_END_IF
    EVT_KILL_THREAD(LW(14))
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_WAIT_FRAMES(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(fall_apart) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(10))
    EVT_SWITCH(LW(10))
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, NPC_ANIM_shy_stack_guy_Palette_00_Anim_1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, NPC_ANIM_shy_stack_guy_Palette_00_Anim_5)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, NPC_ANIM_shy_stack_guy_Palette_00_Anim_9)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, NPC_ANIM_shy_stack_guy_Palette_00_Anim_11)
            EVT_CALL(SetActorVar, ACTOR_SELF, 5, NPC_ANIM_shy_stack_guy_Palette_00_Anim_15)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, NPC_ANIM_shy_stack_guy_Palette_00_Anim_1C)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations2)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_MULTI_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_NO_TARGET, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_NO_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_MULTI_TARGET, 1)
            EVT_CALL(SetActorSize, ACTOR_SELF, 62, EVT_LIMIT)
            EVT_CALL(func_8026DA94, ACTOR_SELF, 0, -20, 0, -20)
            EVT_CALL(SetPartSize, ACTOR_SELF, 1, 57, 30)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, 2)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, NPC_ANIM_shy_stack_guy_Palette_00_Anim_2)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, NPC_ANIM_shy_stack_guy_Palette_00_Anim_6)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, NPC_ANIM_shy_stack_guy_Palette_00_Anim_A)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, NPC_ANIM_shy_stack_guy_Palette_00_Anim_12)
            EVT_CALL(SetActorVar, ACTOR_SELF, 5, NPC_ANIM_shy_stack_guy_Palette_00_Anim_16)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, NPC_ANIM_shy_stack_guy_Palette_00_Anim_1D)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations3)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_MULTI_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_NO_TARGET, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_NO_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_MULTI_TARGET, 1)
            EVT_CALL(SetActorSize, ACTOR_SELF, 44, EVT_LIMIT)
            EVT_CALL(func_8026DA94, ACTOR_SELF, 0, -40, 0, -40)
            EVT_CALL(SetPartSize, ACTOR_SELF, 1, 39, 30)
        EVT_CASE_EQ(2)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, 3)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, NPC_ANIM_shy_stack_guy_Palette_00_Anim_3)
            EVT_CALL(SetActorVar, ACTOR_SELF, 2, NPC_ANIM_shy_stack_guy_Palette_00_Anim_7)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, NPC_ANIM_shy_stack_guy_Palette_00_Anim_B)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, NPC_ANIM_shy_stack_guy_Palette_00_Anim_13)
            EVT_CALL(SetActorVar, ACTOR_SELF, 5, NPC_ANIM_shy_stack_guy_Palette_00_Anim_17)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, NPC_ANIM_shy_stack_guy_Palette_00_Anim_1E)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations4)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_MULTI_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_NO_TARGET, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_NO_TARGET, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_MULTI_TARGET, 1)
            EVT_CALL(SetActorSize, ACTOR_SELF, 26, EVT_LIMIT)
            EVT_CALL(func_8026DA94, ACTOR_SELF, 0, -60, 0, -60)
            EVT_CALL(SetPartSize, ACTOR_SELF, 1, 21, 30)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(lower_actor_pos) = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_301)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 18)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_SET(LW(3), LW(1))
        EVT_WAIT_FRAMES(2)
        EVT_SUB(LW(3), 1)
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
        EVT_WAIT_FRAMES(3)
        EVT_SUB(LW(3), 2)
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
        EVT_WAIT_FRAMES(2)
        EVT_SUB(LW(3), 3)
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
        EVT_WAIT_FRAMES(1)
        EVT_SUB(LW(3), 5)
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
        EVT_WAIT_FRAMES(1)
        EVT_SUB(LW(3), 7)
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(LW(3), 2)
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(LW(3), 3)
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
        EVT_WAIT_FRAMES(1)
        EVT_ADD(LW(3), 3)
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
        EVT_WAIT_FRAMES(1)
        EVT_SUB(LW(3), 3)
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
        EVT_WAIT_FRAMES(1)
        EVT_SUB(LW(3), 3)
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
        EVT_WAIT_FRAMES(1)
        EVT_SUB(LW(3), 2)
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(3), LW(2))
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2064)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(doSpinSmashHit) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(func_80231000_54CC70, EVT_ADDR("X"), LW(0))
    EVT_CALL(func_80231000_54CC70, EVT_ADDR("Y"), LW(1))
    EVT_CALL(func_80231000_54CC70, EVT_ADDR("Z"), LW(2))
    EVT_CALL(SetAnimation, ACTOR_SELF, 10, NPC_ANIM_shy_stack_damage_Palette_00_Anim_0)
    EVT_CALL(SetPartPos, ACTOR_SELF, 10, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartRotation, ACTOR_SELF, 10, 0, 0, 0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 10, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_EXEC_WAIT(N(fall_apart))
    EVT_SET_CONST(LW(0), 1)
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_EXEC_WAIT(N(lower_actor_pos))
    EVT_CALL(PlayerCreateTargetList, 98308)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerID, LW(1))
    EVT_CALL(GetOwnerTarget, LW(0), LW(9))
    EVT_IF_NE(LW(1), LW(0))
        EVT_CALL(ChooseNextTarget, 0, LW(0))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_ADD(LW(15), 1)
    EVT_CALL(ChooseNextTarget, 0, LW(0))
    EVT_CALL(func_80231000_54CC70, EVT_ADDR("T"), LW(0))
    EVT_IF_EQ(LW(0), -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(GetOwnerTarget, LW(0), LW(9))
    EVT_CALL(GetActorFlags, LW(0), LW(1))
    EVT_IF_FLAG(LW(1), ACTOR_FLAG_TARGET_ONLY)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetOwnerID, LW(0))
    EVT_CALL(func_80231000_54CC70, EVT_ADDR("MYSELF ID"), LW(0))
    EVT_CALL(GetOwnerTarget, LW(0), LW(1))
    EVT_CALL(func_80231000_54CC70, EVT_ADDR("TARGET ID"), LW(0))
    EVT_CALL(func_80231000_54CC70, EVT_ADDR("TARGET PARTS ID"), LW(1))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SET(LW(1), 0)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 10, EVT_FLOAT(0.1))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 10, EVT_FLOAT(7.0))
    EVT_CALL(func_80231000_54CC70, EVT_ADDR("TX"), LW(0))
    EVT_CALL(func_80231000_54CC70, EVT_ADDR("TY"), LW(1))
    EVT_CALL(func_80231000_54CC70, EVT_ADDR("TZ"), LW(2))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 10, LW(0), LW(1), LW(2), 0, 1)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetOwnerTarget, LW(0), LW(1))
    EVT_CALL(DispatchDamageEvent, LW(0), 1, 17)
    EVT_GOTO(1)
    EVT_LABEL(10)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 10, EVT_FLOAT(0.1))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 10, EVT_FLOAT(6.0))
    EVT_CALL(GetActorSize, ACTOR_SELF, LW(0), LW(3))
    EVT_DIV(LW(3), 2)
    EVT_SET(LW(4), 70)
    EVT_SUB(LW(4), LW(3))
    EVT_CALL(GetPartOffset, ACTOR_SELF, 10, LW(0), LW(1), LW(2))
    EVT_SET(LW(5), LW(4))
    EVT_SUB(LW(5), LW(0))
    EVT_IF_LT(LW(5), 6)
        EVT_SET(LW(5), 1)
    EVT_ELSE
        EVT_SET(LW(5), 0)
    EVT_END_IF
    EVT_CALL(JumpPartTo, ACTOR_SELF, 10, LW(4), LW(1), LW(2), LW(5), 1)
    EVT_SUB(LW(4), 18)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 10, EVT_FLOAT(1.5))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 10, EVT_FLOAT(3.0))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 10, LW(4), LW(1), LW(2), 12, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 10, ACTOR_PART_FLAG_NO_TARGET, 1)
    EVT_CALL(GetPartOffset, ACTOR_SELF, 10, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 10)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 10, SOUND_DEATH)
    EVT_CALL(PlayEffect, EFFECT_BIG_SMOKE_PUFF, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_SET(LW(0), 0)
    EVT_LOOP(12)
        EVT_CALL(SetPartRotation, ACTOR_SELF, 10, LW(0), 0, 0)
        EVT_ADD(LW(0), 8)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 10, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(80235168) = {
    EVT_CALL(func_80269E80, LW(0))
    EVT_IF_EQ(LW(0), 9)
        EVT_CALL(SetAnimation, ACTOR_SELF, 10, NPC_ANIM_shy_stack_damage_Palette_00_Anim_1)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 10, NPC_ANIM_shy_stack_damage_Palette_00_Anim_0)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(func_80231000_54CC70, EVT_ADDR("X"), LW(0))
    EVT_CALL(func_80231000_54CC70, EVT_ADDR("Y"), LW(1))
    EVT_CALL(func_80231000_54CC70, EVT_ADDR("Z"), LW(2))
    EVT_CALL(SetPartPos, ACTOR_SELF, 10, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartRotation, ACTOR_SELF, 10, 0, 0, 0)
    EVT_EXEC_WAIT(N(fall_apart))
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(1))
    EVT_SWITCH(LW(1))
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, 4, LW(1))
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(1))
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(1))
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 10, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_EXEC_WAIT(N(lower_actor_pos))
    EVT_THREAD
        EVT_SET(LW(0), 0)
        EVT_LOOP(30)
            EVT_ADD(LW(0), 24)
            EVT_CALL(SetPartYaw, ACTOR_SELF, 10, LW(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetPartYaw, ACTOR_SELF, 10, LW(0))
    EVT_END_THREAD
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 10, EVT_FLOAT(3.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 10, EVT_FLOAT(0.5))
    EVT_CALL(GetActorSize, ACTOR_SELF, LW(0), LW(3))
    EVT_DIV(LW(3), 2)
    EVT_SET(LW(4), 70)
    EVT_SUB(LW(4), LW(3))
    EVT_CALL(GetPartOffset, ACTOR_SELF, 10, LW(0), LW(1), LW(2))
    EVT_SET(LW(5), LW(4))
    EVT_SUB(LW(5), LW(0))
    EVT_IF_LT(LW(5), 6)
        EVT_SET(LW(5), 1)
    EVT_ELSE
        EVT_SET(LW(5), 0)
    EVT_END_IF
    EVT_CALL(JumpPartTo, ACTOR_SELF, 10, LW(4), LW(1), LW(2), LW(5), 1)
    EVT_SET(LW(1), 0)
    EVT_SUB(LW(0), 10)
    EVT_CALL(JumpPartTo, ACTOR_SELF, 10, LW(0), LW(1), LW(2), 10, 1)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(GetPartOffset, ACTOR_SELF, 10, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 10)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 10, SOUND_DEATH)
    EVT_CALL(PlayEffect, EFFECT_BIG_SMOKE_PUFF, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_SET(LW(0), 0)
    EVT_LOOP(12)
        EVT_CALL(SetPartRotation, ACTOR_SELF, 10, LW(0), 0, 0)
        EVT_ADD(LW(0), 8)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 10, ACTOR_PART_FLAG_NO_TARGET, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 10, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LW(0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(GetActorSize, ACTOR_SELF, LW(3), LW(4))
            EVT_DIV(LW(3), 2)
            EVT_ADD(LW(1), LW(3))
            EVT_ADD(LW(2), 5)
            EVT_DIVF(LW(3), EVT_FLOAT(10.0))
            EVT_CALL(PlayEffect, EFFECT_SMOKE_BURST, 0, LW(0), LW(1), LW(2), LW(3), 10, 0, 0, 0, 0, 0, 0, 0)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, 5, LW(0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(0))
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
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 6, LW(0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(0))
    EVT_WAIT_FRAMES(20)
    EVT_ADD(LW(0), 4)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, LW(0))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2E7)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2E8)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(15), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(5), 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 7, 0)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET(LW(5), 0)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
            EVT_SWITCH(LW(0))
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
    EVT_SET(LW(1), LW(5))
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
    EVT_IF_LE(LW(0), 0)
        EVT_SET(LW(0), 0)
        EVT_EXEC(N(launch_rock))
    EVT_END_IF
    EVT_IF_LE(LW(0), 1)
        EVT_SET(LW(0), 1)
        EVT_EXEC(N(launch_rock))
    EVT_END_IF
    EVT_IF_LE(LW(0), 2)
        EVT_SET(LW(0), 2)
        EVT_EXEC(N(launch_rock))
    EVT_END_IF
    EVT_SET(LW(0), 3)
    EVT_EXEC(N(launch_rock))
    EVT_WAIT_FRAMES(10)
    EVT_CALL(GetActorVar, ACTOR_SELF, 7, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(1)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(2)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(3)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(4)
            EVT_WAIT_FRAMES(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_DEFAULT
            EVT_SWITCH(LW(15))
                EVT_CASE_EQ(HIT_RESULT_LUCKY)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_CASE_DEFAULT
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_SET(LW(15), LW(0))
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_WAIT_FRAMES(15)
            EVT_WAIT_FRAMES(15)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(launch_rock) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(15))
    EVT_IF_FLAG(LW(15), STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, 7, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, 8, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, 9, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(1.0))
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
        EVT_SWITCH(LW(0))
            EVT_CASE_EQ(HIT_RESULT_HIT)
                EVT_ADD(LW(3), -4)
                EVT_ADD(LW(4), 28)
                EVT_SET(LW(2), 9)
            EVT_CASE_EQ(HIT_RESULT_1)
                EVT_ADD(LW(3), -4)
                EVT_ADD(LW(4), 21)
                EVT_SET(LW(2), 8)
            EVT_CASE_EQ(HIT_RESULT_QUAKE_IMMUNE)
                EVT_ADD(LW(3), -4)
                EVT_ADD(LW(4), 14)
                EVT_SET(LW(2), 7)
            EVT_CASE_DEFAULT
                EVT_ADD(LW(3), -4)
                EVT_ADD(LW(4), 7)
                EVT_SET(LW(2), 6)
        EVT_END_SWITCH
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, 7, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, 8, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, 9, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
        EVT_SWITCH(LW(0))
            EVT_CASE_EQ(HIT_RESULT_HIT)
                EVT_ADD(LW(3), -10)
                EVT_ADD(LW(4), 72)
                EVT_SET(LW(2), 9)
            EVT_CASE_EQ(1)
                EVT_ADD(LW(3), -10)
                EVT_ADD(LW(4), 54)
                EVT_SET(LW(2), 8)
            EVT_CASE_EQ(HIT_RESULT_QUAKE_IMMUNE)
                EVT_ADD(LW(3), -10)
                EVT_ADD(LW(4), 36)
                EVT_SET(LW(2), 7)
            EVT_CASE_DEFAULT
                EVT_ADD(LW(3), -10)
                EVT_ADD(LW(4), 18)
                EVT_SET(LW(2), 6)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(SetPartSounds, ACTOR_SELF, LW(2), 2, 0, 0)
    EVT_CALL(SetPartPos, ACTOR_SELF, LW(2), LW(3), LW(4), LW(5))
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(2), NPC_ANIM_shy_stack_rock_Palette_00_Anim_0)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LW(2), ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(6), LW(7), LW(8))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LW(2), EVT_FLOAT(12.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LW(2), EVT_FLOAT(1.0))
    EVT_SWITCH(LW(1))
        EVT_CASE_EQ(0)
            EVT_CALL(JumpPartTo, ACTOR_SELF, LW(2), LW(6), LW(7), LW(8), 9, 1)
            EVT_SUB(LW(6), 100)
            EVT_CALL(RandInt, 40, LW(9))
            EVT_SUB(LW(6), LW(9))
            EVT_ADD(LW(7), LW(9))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LW(2), EVT_FLOAT(0.8))
            EVT_CALL(JumpPartTo, ACTOR_SELF, LW(2), LW(6), LW(7), LW(8), 25, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LW(2), ACTOR_PART_FLAG_INVISIBLE, 1)
        EVT_CASE_EQ(1)
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(HIT_RESULT_HIT)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LW(2), EVT_FLOAT(2.2))
                EVT_CASE_EQ(HIT_RESULT_1)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LW(2), EVT_FLOAT(1.8))
                EVT_CASE_EQ(HIT_RESULT_QUAKE_IMMUNE)
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LW(2), EVT_FLOAT(1.4))
                EVT_CASE_DEFAULT
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LW(2), EVT_FLOAT(1.0))
            EVT_END_SWITCH
            EVT_SET(LW(7), 0)
            EVT_CALL(RandInt, 35, LW(9))
            EVT_ADD(LW(9), 30)
            EVT_SUB(LW(6), LW(9))
            EVT_CALL(JumpPartTo, ACTOR_SELF, LW(2), LW(6), LW(7), LW(8), 9, 1)
            EVT_CALL(RandInt, 25, LW(9))
            EVT_ADD(LW(9), 45)
            EVT_SUB(LW(6), LW(9))
            EVT_CALL(JumpPartTo, ACTOR_SELF, LW(2), LW(6), LW(7), LW(8), 8, 1)
            EVT_SUB(LW(6), 25)
            EVT_CALL(JumpPartTo, ACTOR_SELF, LW(2), LW(6), LW(7), LW(8), 4, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LW(2), ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(onDeath) = {
    EVT_EXEC_WAIT(D_8029AF08)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_CALL(GetActorVar, ACTOR_ENEMY1, 3, LW(0))
    EVT_ADD(LW(0), 1)
    EVT_CALL(SetActorVar, ACTOR_ENEMY1, 3, LW(0))
    EVT_IF_GE(LW(0), 2)
        EVT_CALL(func_8026BF48, 1)
    EVT_END_IF
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(onSpinSmashLaunchDeath) = {
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_SET(LW(2), 0)
    EVT_LOOP(24)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LW(2))
        EVT_ADD(LW(2), 30)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DEATH)
    EVT_CALL(PlayEffect, EFFECT_BIG_SMOKE_PUFF, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySound, SOUND_DEATH)
    EVT_CALL(DropStarPoints, ACTOR_SELF)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_SET(LW(3), 0)
    EVT_LOOP(12)
        EVT_CALL(SetActorRotation, ACTOR_SELF, LW(3), 0, 0)
        EVT_ADD(LW(3), 8)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_CALL(GetActorVar, ACTOR_ENEMY1, 3, LW(0))
    EVT_ADD(LW(0), 1)
    EVT_CALL(SetActorVar, ACTOR_ENEMY1, 3, LW(0))
    EVT_IF_GE(LW(0), 2)
        EVT_CALL(func_8026BF48, 1)
    EVT_END_IF
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};
