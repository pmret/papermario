#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/stilt_guy.h"
#include "sprite/npc/stilt_guy_unfold.h"
#include "sprite/npc/shy_guy.h"
#include "sprite/npc/general_guy.h"

#define NAMESPACE b_area_omo2_2_stilt_guy

#include "common/GetSelectedMoveID.inc.c"

ApiStatus SetActorLevelToZero(Evt* script, s32 isInitialCall) {
    get_actor(script->owner1.actorID)->actorBlueprint->level = 0;
    return ApiStatus_DONE2;
}

#include "common/UnkBattleFunc1.inc.c"

extern s32 N(idleAnimations)[];
extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(check_fall_off);
extern EvtScript N(check_fall_off_2);
extern EvtScript N(fallOff);
extern EvtScript N(onDeath);
extern EvtScript N(attack);
extern EvtScript N(shy_guy_return_home);
extern EvtScript N(shy_guy_takeTurn);
extern EvtScript N(shy_guy_idle);
extern EvtScript N(shy_guy_handleEvent);


s32 N(idleAnimations2)[] = {
    STATUS_NORMAL, NPC_ANIM_stilt_guy_Palette_00_Anim_1,
    STATUS_STONE, NPC_ANIM_stilt_guy_Palette_00_Anim_0,
    STATUS_SLEEP, NPC_ANIM_stilt_guy_Palette_00_Anim_4,
    STATUS_POISON, NPC_ANIM_stilt_guy_Palette_00_Anim_1,
    STATUS_STOP, NPC_ANIM_stilt_guy_Palette_00_Anim_0,
    STATUS_STATIC, NPC_ANIM_stilt_guy_Palette_00_Anim_0,
    STATUS_PARALYZE, NPC_ANIM_stilt_guy_Palette_00_Anim_0,
    STATUS_PARALYZE, NPC_ANIM_stilt_guy_Palette_00_Anim_0,
    STATUS_DIZZY, NPC_ANIM_stilt_guy_Palette_00_Anim_0,
    STATUS_FEAR, NPC_ANIM_stilt_guy_Palette_00_Anim_0,
    STATUS_END,
};

s32 N(idleAnimations3)[] = {
    STATUS_NORMAL, NPC_ANIM_stilt_guy_unfold_Palette_00_Anim_0,
    STATUS_END,
};

s32 N(defenseTable2)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(defenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_SHOCK, 0,
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

s32 N(statusTable2)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 70,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 100,
    STATUS_STATIC, 50,
    STATUS_PARALYZE, 90,
    STATUS_SHRINK, 75,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 1,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = -1,
        .unk_1D = -10,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 40 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations2),
        .defenseTable = N(defenseTable2),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = -1,
        .unk_1D = -5,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 3,
        .posOffset = { 0, 74, 0 },
        .targetOffset = { 0, -8 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable2),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = -1,
        .unk_1D = -3,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET,
        .index = 4,
        .posOffset = { -2, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable2),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = -1,
        .unk_1D = 5,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000 | ACTOR_PART_FLAG_20000000,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations3),
        .defenseTable = N(defenseTable2),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000 | ACTOR_PART_FLAG_20000000,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations3),
        .defenseTable = N(defenseTable2),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000 | ACTOR_PART_FLAG_20000000,
        .index = 7,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations3),
        .defenseTable = N(defenseTable2),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000 | ACTOR_PART_FLAG_20000000,
        .index = 8,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations3),
        .defenseTable = N(defenseTable2),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_STILT_GUY,
    .level = 0,
    .maxHP = 7,
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
    .statusIconOffset = { -15, 70 },
    .statusMessageOffset = { 10, 65 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetPartTargetFlagBits, ACTOR_SELF, 4, 1, 1)
    EVT_CALL(SetPartSize, ACTOR_SELF, 1, 24, 30)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetPartRotationOffset, ACTOR_SELF, 8, 0, 13, 0)
    EVT_CALL(SetPartRotationOffset, ACTOR_SELF, 7, 0, 13, 0)
    EVT_CALL(SetPartRotationOffset, ACTOR_SELF, 6, 0, 13, 0)
    EVT_CALL(SetPartRotationOffset, ACTOR_SELF, 5, 0, 13, 0)
    EVT_THREAD
        EVT_SET(LW(0), 90)
        EVT_SET(LW(1), 270)
        EVT_LOOP(5)
            EVT_LOOP(2)
                EVT_LABEL(0)
                EVT_CALL(SetPartRotation, ACTOR_SELF, 8, LW(1), 0, 0)
                EVT_WAIT_FRAMES(1)
                EVT_SUB(LW(1), LW(0))
                EVT_IF_GE(LW(1), -90)
                    EVT_GOTO(0)
                EVT_END_IF
                EVT_ADD(LW(1), 360)
            EVT_END_LOOP
            EVT_SUB(LW(0), 15)
        EVT_END_LOOP
        EVT_CALL(SetPartRotation, ACTOR_SELF, 8, -90, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 8, EVT_FLOAT(0.6))
        EVT_CALL(SetAnimation, ACTOR_SELF, 8, NPC_ANIM_stilt_guy_unfold_Palette_00_Anim_3)
        EVT_CALL(GetActorPos, ACTOR_ENEMY0, LW(0), LW(1), LW(2))
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(1))
        EVT_IF_EQ(LW(1), 0)
            EVT_SET(LW(0), 10)
            EVT_CALL(PlaySound, SOUND_305)
        EVT_ELSE
            EVT_SET(LW(0), 50)
            EVT_CALL(PlaySound, SOUND_306)
        EVT_END_IF
        EVT_SUB(LW(2), 13)
        EVT_CALL(SetPartPos, ACTOR_SELF, 8, LW(0), 200, LW(2))
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), 200, LW(2))
        EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_2)
        EVT_CALL(SetAnimation, ACTOR_ENEMY0, 1, NPC_ANIM_general_guy_Palette_00_Anim_A)
        EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY0, 1, SOUND_GENERAL_WHISTLE)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 8, ACTOR_PART_FLAG_INVISIBLE, 0)
        EVT_CALL(FallPartTo, ACTOR_SELF, 8, LW(0), -9, LW(2), 80)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(15)
        EVT_SET(LW(0), 90)
        EVT_SET(LW(1), 450)
        EVT_LOOP(5)
            EVT_LOOP(2)
                EVT_LABEL(1)
                EVT_CALL(SetPartRotation, ACTOR_SELF, 7, LW(1), 0, 0)
                EVT_WAIT_FRAMES(1)
                EVT_SUB(LW(1), LW(0))
                EVT_IF_GE(LW(1), 90)
                    EVT_GOTO(1)
                EVT_END_IF
                EVT_ADD(LW(1), 360)
            EVT_END_LOOP
            EVT_SUB(LW(0), 15)
        EVT_END_LOOP
        EVT_CALL(SetPartRotation, ACTOR_SELF, 7, 90, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 7, EVT_FLOAT(0.6))
        EVT_CALL(SetAnimation, ACTOR_SELF, 7, NPC_ANIM_stilt_guy_unfold_Palette_00_Anim_2)
        EVT_CALL(GetActorPos, ACTOR_ENEMY0, LW(0), LW(1), LW(2))
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_SET(LW(0), 10)
        EVT_ELSE
            EVT_SET(LW(0), 50)
        EVT_END_IF
        EVT_SUB(LW(2), 13)
        EVT_CALL(SetPartPos, ACTOR_SELF, 7, LW(0), 200, LW(2))
        EVT_WAIT_FRAMES(15)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 7, ACTOR_PART_FLAG_INVISIBLE, 0)
        EVT_CALL(FallPartTo, ACTOR_SELF, 7, LW(0), -9, LW(2), 80)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(30)
        EVT_SET(LW(0), 90)
        EVT_SET(LW(1), 270)
        EVT_LOOP(5)
            EVT_LOOP(2)
                EVT_LABEL(2)
                EVT_CALL(SetPartRotation, ACTOR_SELF, 6, LW(1), 0, 0)
                EVT_WAIT_FRAMES(1)
                EVT_SUB(LW(1), LW(0))
                EVT_IF_GE(LW(1), -90)
                    EVT_GOTO(2)
                EVT_END_IF
                EVT_ADD(LW(1), 360)
            EVT_END_LOOP
            EVT_SUB(LW(0), 15)
        EVT_END_LOOP
        EVT_CALL(SetPartRotation, ACTOR_SELF, 6, -90, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.6))
        EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_stilt_guy_unfold_Palette_00_Anim_1)
        EVT_CALL(GetActorPos, ACTOR_ENEMY0, LW(0), LW(1), LW(2))
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_SET(LW(0), 10)
        EVT_ELSE
            EVT_SET(LW(0), 50)
        EVT_END_IF
        EVT_SUB(LW(2), 13)
        EVT_CALL(SetPartPos, ACTOR_SELF, 6, LW(0), 200, LW(2))
        EVT_WAIT_FRAMES(30)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 0)
        EVT_CALL(FallPartTo, ACTOR_SELF, 6, LW(0), -9, LW(2), 80)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT_FRAMES(45)
        EVT_SET(LW(0), 90)
        EVT_SET(LW(1), 450)
        EVT_LOOP(5)
            EVT_LOOP(2)
                EVT_LABEL(3)
                EVT_CALL(SetPartRotation, ACTOR_SELF, 5, LW(1), 0, 0)
                EVT_WAIT_FRAMES(1)
                EVT_SUB(LW(1), LW(0))
                EVT_IF_GE(LW(1), 90)
                    EVT_GOTO(3)
                EVT_END_IF
                EVT_ADD(LW(1), 360)
            EVT_END_LOOP
            EVT_SUB(LW(0), 15)
        EVT_END_LOOP
        EVT_CALL(SetPartRotation, ACTOR_SELF, 5, 90, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 5, EVT_FLOAT(0.6))
        EVT_CALL(SetAnimation, ACTOR_SELF, 5, NPC_ANIM_stilt_guy_unfold_Palette_00_Anim_0)
        EVT_CALL(GetActorPos, ACTOR_ENEMY0, LW(0), LW(1), LW(2))
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_SET(LW(0), 10)
        EVT_ELSE
            EVT_SET(LW(0), 50)
        EVT_END_IF
        EVT_SUB(LW(2), 13)
        EVT_CALL(SetPartPos, ACTOR_SELF, 5, LW(0), 200, LW(2))
        EVT_WAIT_FRAMES(45)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE, 0)
        EVT_CALL(FallPartTo, -127, 5, LW(0), -9, LW(2), 80)
        EVT_WAIT_FRAMES(15)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 7, ACTOR_PART_FLAG_INVISIBLE, 1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 8, ACTOR_PART_FLAG_INVISIBLE, 1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, 1)
        EVT_CALL(GetPartOffset, ACTOR_SELF, 8, LW(0), LW(1), LW(2))
        EVT_ADD(LW(2), 13)
        EVT_CALL(ForceHomePos, ACTOR_SELF, LW(0), 0, LW(2))
        EVT_CALL(SetPartPos, ACTOR_SELF, 5, LW(0), 0, LW(2))
        EVT_CALL(GetPartOffset, ACTOR_SELF, 5, LW(0), LW(1), LW(2))
        EVT_CALL(SetPartPos, ACTOR_SELF, 5, LW(0), 0, LW(2))
        EVT_CALL(SetPartRotation, ACTOR_SELF, 5, 0, 0, 0)
        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, 8, 0, 0, 0)
        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, 7, 0, 0, 0)
        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, 6, 0, 0, 0)
        EVT_CALL(SetPartRotationOffset, ACTOR_SELF, 5, 0, 0, 0)
        EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 5, SOUND_2065)
        EVT_CALL(SetAnimation, ACTOR_SELF, 5, NPC_ANIM_stilt_guy_unfold_Palette_00_Anim_5)
        EVT_CALL(func_8026ED20, ACTOR_SELF, 5, 1)
        EVT_CALL(func_8026EBF8, ACTOR_SELF, 5, 1, 0, 0, 36, 0, 255, 0, 0)
        EVT_CALL(func_8026EA7C, ACTOR_SELF, 5, 16)
        EVT_WAIT_FRAMES(18)
        EVT_CALL(func_8026ED20, ACTOR_SELF, 5, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 5, NPC_ANIM_stilt_guy_unfold_Palette_00_Anim_4)
        EVT_WAIT_FRAMES(5)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, 0)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
        EVT_IF_EQ(LW(0), 1)
            EVT_CALL(SetActorVar, ACTOR_ENEMY1, 1, 3)
        EVT_ELSE
        EVT_END_IF
    EVT_END_THREAD
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

EvtScript N(return_home) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_EXEC_WAIT(N(shy_guy_return_home))
        EVT_RETURN
    EVT_END_IF
    EVT_SET_CONST(LW(0), 2)
    EVT_SET_CONST(LW(1), NPC_ANIM_stilt_guy_Palette_00_Anim_3)
    EVT_EXEC_WAIT(DoReturnHome)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_stilt_guy_Palette_00_Anim_1)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastElement, LW(15))
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_EXEC_WAIT(N(check_fall_off))
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_stilt_guy_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_UNKNOWN_TRIGGER)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_stilt_guy_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_HIT)
        EVT_CASE_OR_EQ(EVENT_SPIN_SMASH_HIT)
        EVT_CASE_OR_EQ(EVENT_SPIN_SMASH_LAUNCH_HIT)
            EVT_CALL(GetBattleFlags, LW(2))
            EVT_IF_FLAG(LW(2), BS_FLAGS1_80000)
                EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
                EVT_IF_EQ(LW(2), 183)
                    EVT_SET(LW(0), 2)
                    EVT_SET(LW(1), 7340033)
                    EVT_EXEC_WAIT(DoImmune)
                    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_stilt_guy_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(check_fall_off_2))
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
            EVT_IF_NE(LW(0), 0)
                EVT_EXEC_WAIT(N(fallOff))
            EVT_END_IF
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_stilt_guy_Palette_00_Anim_6)
            EVT_WAIT_FRAMES(1000)
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET(LW(0), 2)
            EVT_SET(LW(1), 7340033)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(func_80269E80, LW(0))
            EVT_IF_NE(LW(0), 9)
                EVT_SET(LW(0), 2)
                EVT_SET(LW(1), NPC_ANIM_stilt_guy_Palette_00_Anim_9)
                EVT_SET(LW(2), NPC_ANIM_stilt_guy_Palette_00_Anim_A)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_ELSE
                EVT_SET(LW(0), 2)
                EVT_SET(LW(1), NPC_ANIM_stilt_guy_Palette_00_Anim_9)
                EVT_SET(LW(2), NPC_ANIM_stilt_guy_Palette_00_Anim_A)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_EXEC_WAIT(N(fallOff))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LW(0), 2)
            EVT_SET(LW(1), NPC_ANIM_stilt_guy_Palette_00_Anim_9)
            EVT_SET(LW(2), NPC_ANIM_stilt_guy_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_stilt_guy_Palette_00_Anim_A)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_stilt_guy_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_stilt_guy_Palette_00_Anim_7)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_stilt_guy_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(return_home))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_stilt_guy_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_stilt_guy_Palette_00_Anim_7)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_stilt_guy_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_stilt_guy_Palette_00_Anim_7)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(return_home))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_stilt_guy_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_stilt_guy_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(1000)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_stilt_guy_Palette_00_Anim_3)
            EVT_SET_CONST(LW(2), NPC_ANIM_stilt_guy_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(check_fall_off) = {
    EVT_CALL(GetBattleFlags, LW(0))
    EVT_IF_NOT_FLAG(LW(0), BS_FLAGS1_80000)
        EVT_IF_FLAG(LW(0), BS_FLAGS1_40 | BS_FLAGS1_200)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(N(GetSelectedMoveID), LW(0))
        EVT_SWITCH(LW(0))
            EVT_CASE_OR_EQ(MOVE_HEADBONK1)
            EVT_CASE_OR_EQ(MOVE_HEADBONK2)
            EVT_CASE_OR_EQ(MOVE_HEADBONK3)
            EVT_CASE_OR_EQ(MOVE_MULTIBONK)
                EVT_CALL(GetBattleFlags, LW(0))
                EVT_IF_FLAG(LW(0), BS_FLAGS1_40 | BS_FLAGS1_200)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
                EVT_END_IF
            EVT_END_CASE_GROUP
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(check_fall_off_2) = {
    EVT_CALL(GetBattleFlags, LW(0))
    EVT_IF_NOT_FLAG(LW(0), BS_FLAGS1_80000)
        EVT_IF_FLAG(LW(15), DAMAGE_TYPE_JUMP)
            EVT_IF_FLAG(LW(0), BS_FLAGS1_40 | BS_FLAGS1_200)
                EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_FLAG(LW(15), DAMAGE_TYPE_POW | DAMAGE_TYPE_QUAKE)
            EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_SHRINK | STATUS_FLAG_STOP)
        EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_EXEC_WAIT(N(attack))
    EVT_RETURN
    EVT_END
};

EvtScript N(attack) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(SetBattleCamOffsetZ, 40)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_stilt_guy_Palette_00_Anim_3)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 50)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_stilt_guy_Palette_00_Anim_4)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_THREAD
                EVT_WAIT_FRAMES(9)
                EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_stilt_guy_Palette_00_Anim_4)
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_stilt_guy_Palette_00_Anim_5)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 15)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2EF)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2066)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 25)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2066)
            EVT_WAIT_FRAMES(15)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 2, 0, 2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_EXEC_WAIT(N(return_home))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 2, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_WAIT_FRAMES(8)
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_stilt_guy_Palette_00_Anim_4)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_stilt_guy_Palette_00_Anim_5)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2EF)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 8, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SET(LW(15), LW(0))
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 30)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2066)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_stilt_guy_Palette_00_Anim_1)
            EVT_WAIT_FRAMES(8)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_EXEC_WAIT(N(return_home))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(fallOff) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 1, ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_MULTI_TARGET)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_NO_TARGET)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_NO_TARGET)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_C)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
    EVT_IF_NOT_FLAG(LW(3), STATUS_FLAG_SHRINK)
        EVT_ADD(LW(1), 50)
    EVT_ELSE
        EVT_ADD(LW(1), 20)
    EVT_END_IF
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_THREAD
        EVT_WAIT_FRAMES(6)
        EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 2, SOUND_2067)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_stilt_guy_Palette_00_Anim_8)
        EVT_SET(LW(0), 0)
        EVT_LOOP(15)
            EVT_ADD(LW(0), 6)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 2, 0, 0, LW(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetPartFlags, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_NO_TARGET)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 2, SOUND_301)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 0, LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_CALL(RandInt, 100, LW(1))
    EVT_IF_LT(LW(1), 50)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 0, LW(2))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 0, LW(2))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_10)
        EVT_WAIT_FRAMES(10)
    EVT_END_IF
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(shy_guy_takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(shy_guy_idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(shy_guy_handleEvent)))
    EVT_CALL(SetActorType, ACTOR_SELF, ACTOR_TYPE_SHY_GUY)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_1000, 1)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(GetActorSize, ACTOR_SELF, LW(0), LW(1))
    EVT_CALL(SetActorSize, ACTOR_SELF, 24, LW(1))
    EVT_CALL(SetActorLevelToZero)
    EVT_RETURN
    EVT_END
};

EvtScript N(onDeath) = {
    EVT_EXEC_WAIT(D_8029AF08)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_CALL(GetActorVar, ACTOR_ENEMY1, 2, LW(0))
    EVT_ADD(LW(0), 1)
    EVT_CALL(SetActorVar, ACTOR_ENEMY1, 2, LW(0))
    EVT_IF_GE(LW(0), 2)
        EVT_CALL(func_8026BF48, 1)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 100)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(shy_guy_rotate) = {
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

EvtScript N(shy_guy_on_spin_smash) = {
    EVT_EXEC_GET_TID(N(shy_guy_rotate), LW(14))
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
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS, 65535, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
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

s32 N(idleAnimations)[] = {
    STATUS_NORMAL, NPC_ANIM_shy_guy_Palette_00_Anim_1,
    STATUS_STONE, NPC_ANIM_shy_guy_Palette_00_Anim_0,
    STATUS_SLEEP, NPC_ANIM_shy_guy_Palette_00_Anim_12,
    STATUS_POISON, NPC_ANIM_shy_guy_Palette_00_Anim_1,
    STATUS_STOP, NPC_ANIM_shy_guy_Palette_00_Anim_0,
    STATUS_STATIC, NPC_ANIM_shy_guy_Palette_00_Anim_1,
    STATUS_PARALYZE, NPC_ANIM_shy_guy_Palette_00_Anim_0,
    STATUS_DIZZY, NPC_ANIM_shy_guy_Palette_00_Anim_13,
    STATUS_FEAR, NPC_ANIM_shy_guy_Palette_00_Anim_13,
    STATUS_END,
};

EvtScript N(shy_guy_init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(shy_guy_takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(shy_guy_idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(shy_guy_handleEvent)))
    EVT_RETURN
    EVT_END
};

EvtScript N(shy_guy_idle) = {
    EVT_LABEL(0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), STATUS_FLAG_SLEEP)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -4, 14)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 0, 0)
        EVT_CALL(N(UnkBattleFunc1), -10, 13, 10, 13)
    EVT_ELSE
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 0, 24)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, -1, -10)
        EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
    EVT_END_IF
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(shy_guy_return_home) = {
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_SET_CONST(LW(0), 1)
    EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_3)
    EVT_EXEC_WAIT(DoReturnHome)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_1)
    EVT_RETURN
    EVT_END
};

EvtScript N(shy_guy_handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_D)
            EVT_SET_CONST(LW(2), NPC_ANIM_shy_guy_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_D)
            EVT_SET_CONST(LW(2), NPC_ANIM_shy_guy_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_E)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(N(shy_guy_on_spin_smash))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(N(shy_guy_on_spin_smash))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(shy_guy_return_home))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_3)
            EVT_SET_CONST(LW(2), NPC_ANIM_shy_guy_Palette_00_Anim_14)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(shy_guy_attack1) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_3)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 50)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetActorSounds, ACTOR_SELF, 2, SOUND_2EF, 0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 0, SOUND_20BA, SOUND_3B4)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 4, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_4)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_5)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_SUB(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT_FRAMES(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_1)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_WAIT_FRAMES(3)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2EF)
    EVT_END_THREAD
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, SOUND_20BA, SOUND_3B4)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 4, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_4)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 10)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_5)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 30)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_1)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_EXEC_WAIT(N(shy_guy_return_home))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(shy_guy_attack2) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_234)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_9)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_3)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 80)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, SOUND_20BA, SOUND_3B4)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 4, 10, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_4)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_SUB(LW(0), 40)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_9)
            EVT_THREAD
                EVT_WAIT_FRAMES(12)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_A)
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 10)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 24, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_5)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_SUB(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT_FRAMES(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 15)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_1)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_9)
    EVT_THREAD
        EVT_WAIT_FRAMES(9)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_A)
    EVT_END_THREAD
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 15)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                EVT_SET(LW(3), 0)
                EVT_LOOP(20)
                    EVT_SUB(LW(3), 30)
                    EVT_IF_LT(LW(3), 0)
                        EVT_ADD(LW(3), 360)
                    EVT_END_IF
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(3))
                    EVT_WAIT_FRAMES(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(GetBattleFlags, LW(0))
            EVT_IF_FLAG(LW(0), BS_FLAGS1_ATK_BLOCKED)
                EVT_GOTO(1)
            EVT_END_IF
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_GOTO(1)
            EVT_END_IF
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 40)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_349)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_749)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_9)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_7)
            EVT_WAIT_FRAMES(15)
            EVT_GOTO(2)
            EVT_LABEL(1)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 40)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E4)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_10)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20C3)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(RandInt, 100, LW(0))
            EVT_IF_LT(LW(0), 50)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_11)
            EVT_ELSE
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_13)
            EVT_END_IF
            EVT_WAIT_FRAMES(25)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_LABEL(2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_1)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(shy_guy_takeTurn) = {
    EVT_CALL(RandInt, 1, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_EXEC_WAIT(N(shy_guy_attack1))
    EVT_ELSE
        EVT_EXEC_WAIT(N(shy_guy_attack2))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
