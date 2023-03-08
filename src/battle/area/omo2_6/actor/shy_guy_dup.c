#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/TankGuy.h"

#define NAMESPACE b_area_omo2_6_shy_guy_dup

extern s32 N(IdleAnimations)[];
extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(run_to_pos);

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
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

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 7,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 8,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 9,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_HIDE_HP_BAR,
    .type = ACTOR_TYPE_SHY_GUY_DUP,
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
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 30, 30 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL, ANIM_TankGuy_Anim01,
    STATUS_STONE, ANIM_TankGuy_Anim00,
    STATUS_SLEEP, ANIM_TankGuy_Anim00,
    STATUS_POISON, ANIM_TankGuy_Anim01,
    STATUS_STOP, ANIM_TankGuy_Anim00,
    STATUS_STATIC, ANIM_TankGuy_Anim00,
    STATUS_PARALYZE, ANIM_TankGuy_Anim00,
    STATUS_PARALYZE, ANIM_TankGuy_Anim00,
    STATUS_DIZZY, ANIM_TankGuy_Anim01,
    STATUS_DIZZY, ANIM_TankGuy_Anim01,
    STATUS_FEAR, ANIM_TankGuy_Anim00,
    STATUS_END,
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 2, 0, 0)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 2, 1, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 3, 0, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 3, 1, -30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 4, 0, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 4, 1, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 5, 0, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 5, 1, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 6, 0, 30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 6, 1, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 7, 0, 30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 7, 1, -30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 8, 0, 40)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 8, 1, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 9, 0, 50)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, 9, 1, 10)
    EVT_SET(LVar0, 2)
    EVT_LOOP(8)
        EVT_CALL(SetPartPos, ACTOR_SELF, LVar0, 185, 0, 47)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_CALL(ForceHomePos, ACTOR_SELF, 20, 0, -10)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_SET(LVar0, 2)
    EVT_SET(LVar1, ANIM_TankGuy_Anim03)
    EVT_SET(LVar4, EVT_FLOAT(4.0))
    EVT_SET(LVar5, 5)
    EVT_LOOP(8)
        EVT_THREAD
            EVT_CALL(GetPartMovementVar, ACTOR_SELF, LVar0, 0, LVar2)
            EVT_CALL(GetPartMovementVar, ACTOR_SELF, LVar0, 1, LVar3)
            EVT_SET(LVar5, 20)
            EVT_EXEC_WAIT(N(run_to_pos))
            EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, ANIM_TankGuy_Anim01)
        EVT_END_THREAD
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
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

EvtScript N(run_to_pos) = {
    EVT_CALL(GetPartOffset, ACTOR_SELF, LVar0, LVar6, 0, LVar7)
    EVT_IF_LT(LVar6, LVar2)
        EVT_CALL(SetPartYaw, ACTOR_SELF, LVar0, 180)
    EVT_ELSE
        EVT_CALL(SetPartYaw, ACTOR_SELF, LVar0, 0)
    EVT_END_IF
    EVT_CALL(GetDist2D, LVar9, LVar6, LVar7, LVar2, LVar3)
    EVT_IF_GE(LVar9, LVar4)
        EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LVar0, LVar4)
        EVT_CALL(RunPartTo, ACTOR_SELF, LVar0, LVar2, 0, LVar3, LVar5)
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
