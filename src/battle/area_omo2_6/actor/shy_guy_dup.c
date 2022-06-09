#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/tank_guy.h"

#define NAMESPACE b_area_omo2_6_shy_guy_dup

extern s32 N(idleAnimations)[];
extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(80231620);

s32 N(defenseTable)[] = {
    ELEMENT_NORMAL, 0,
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

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 7,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 8,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 9,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_40000,
    .type = ACTOR_TYPE_SHY_GUY_DUP,
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
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 30, 30 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(idleAnimations)[] = {
    STATUS_NORMAL, NPC_ANIM_tank_guy_Palette_00_Anim_1,
    STATUS_STONE, NPC_ANIM_tank_guy_Palette_00_Anim_0,
    STATUS_SLEEP, NPC_ANIM_tank_guy_Palette_00_Anim_0,
    STATUS_POISON, NPC_ANIM_tank_guy_Palette_00_Anim_1,
    STATUS_STOP, NPC_ANIM_tank_guy_Palette_00_Anim_0,
    STATUS_STATIC, NPC_ANIM_tank_guy_Palette_00_Anim_0,
    STATUS_PARALYZE, NPC_ANIM_tank_guy_Palette_00_Anim_0,
    STATUS_PARALYZE, NPC_ANIM_tank_guy_Palette_00_Anim_0,
    STATUS_DIZZY, NPC_ANIM_tank_guy_Palette_00_Anim_1,
    STATUS_DIZZY, NPC_ANIM_tank_guy_Palette_00_Anim_1,
    STATUS_FEAR, NPC_ANIM_tank_guy_Palette_00_Anim_0,
    STATUS_END,
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent)))
    EVT_CALL(SetPartMovementVar, -127, 2, 0, 0)
    EVT_CALL(SetPartMovementVar, -127, 2, 1, -10)
    EVT_CALL(SetPartMovementVar, -127, 3, 0, 10)
    EVT_CALL(SetPartMovementVar, -127, 3, 1, -30)
    EVT_CALL(SetPartMovementVar, -127, 4, 0, 10)
    EVT_CALL(SetPartMovementVar, -127, 4, 1, 10)
    EVT_CALL(SetPartMovementVar, -127, 5, 0, 20)
    EVT_CALL(SetPartMovementVar, -127, 5, 1, -10)
    EVT_CALL(SetPartMovementVar, -127, 6, 0, 30)
    EVT_CALL(SetPartMovementVar, -127, 6, 1, 10)
    EVT_CALL(SetPartMovementVar, -127, 7, 0, 30)
    EVT_CALL(SetPartMovementVar, -127, 7, 1, -30)
    EVT_CALL(SetPartMovementVar, -127, 8, 0, 40)
    EVT_CALL(SetPartMovementVar, -127, 8, 1, -10)
    EVT_CALL(SetPartMovementVar, -127, 9, 0, 50)
    EVT_CALL(SetPartMovementVar, -127, 9, 1, 10)
    EVT_SET(LW(0), 2)
    EVT_LOOP(8)
        EVT_CALL(SetPartPos, ACTOR_SELF, LW(0), 185, 0, 47)
        EVT_ADD(LW(0), 1)
    EVT_END_LOOP
    EVT_CALL(ForceHomePos, ACTOR_SELF, 20, 0, -10)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_SET(LW(0), 2)
    EVT_SET(LW(1), 7864323)
    EVT_SET(LW(4), EVT_FLOAT(4.0))
    EVT_SET(LW(5), 5)
    EVT_LOOP(8)
        EVT_THREAD
            EVT_CALL(GetPartMovementVar, -127, LW(0), 0, LW(2))
            EVT_CALL(GetPartMovementVar, -127, LW(0), 1, LW(3))
            EVT_SET(LW(5), 20)
            EVT_EXEC_WAIT(N(80231620))
            EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), 0x780001)
        EVT_END_THREAD
        EVT_ADD(LW(0), 1)
    EVT_END_LOOP
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

EvtScript N(80231620) = {
    EVT_CALL(GetPartOffset, ACTOR_SELF, LW(0), LW(6), 0, LW(7))
    EVT_IF_LT(LW(6), LW(2))
        EVT_CALL(SetPartYaw, ACTOR_SELF, LW(0), 180)
    EVT_ELSE
        EVT_CALL(SetPartYaw, ACTOR_SELF, LW(0), 0)
    EVT_END_IF
    EVT_CALL(GetDist2D, LW(9), LW(6), LW(7), LW(2), LW(3))
    EVT_IF_GE(LW(9), LW(4))
        EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LW(0), LW(4))
        EVT_CALL(RunPartTo, -127, LW(0), LW(2), 0, LW(3), LW(5))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_RETURN
    EVT_END
};
