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

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_2               = 2,
    PRT_3               = 3,
    PRT_4               = 4,
    PRT_5               = 5,
    PRT_6               = 6,
    PRT_7               = 7,
    PRT_8               = 8,
    PRT_9               = 9,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
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
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PRT_MAIN,
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
        .index = PRT_2,
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
        .index = PRT_3,
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
        .index = PRT_4,
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
        .index = PRT_5,
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
        .index = PRT_6,
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
        .index = PRT_7,
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
        .index = PRT_8,
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
        .index = PRT_9,
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
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_HEALTH_BAR,
    .type = ACTOR_TYPE_SHY_GUY_DUP,
    .level = ACTOR_LEVEL_SHY_GUY_DUP,
    .maxHP = 10,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
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
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(IdleAnimations)[] = {
    STATUS_KEY_NORMAL,    ANIM_TankGuy_Anim01,
    STATUS_KEY_STONE,     ANIM_TankGuy_Anim00,
    STATUS_KEY_SLEEP,     ANIM_TankGuy_Anim00,
    STATUS_KEY_POISON,    ANIM_TankGuy_Anim01,
    STATUS_KEY_STOP,      ANIM_TankGuy_Anim00,
    STATUS_KEY_STATIC,    ANIM_TankGuy_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_TankGuy_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_TankGuy_Anim00,
    STATUS_KEY_DIZZY,     ANIM_TankGuy_Anim01,
    STATUS_KEY_DIZZY,     ANIM_TankGuy_Anim01,
    STATUS_KEY_FEAR,      ANIM_TankGuy_Anim00,
    STATUS_END,
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_2, 0, 0)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_2, 1, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_3, 0, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_3, 1, -30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_4, 0, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_4, 1, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_5, 0, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_5, 1, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_6, 0, 30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_6, 1, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_7, 0, 30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_7, 1, -30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_8, 0, 40)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_8, 1, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_9, 0, 50)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_9, 1, 10)
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
