#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/TankGuy.h"

#define NAMESPACE b_area_omo2_6_shy_squad_stub

extern s32 N(DefaultAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_MoveMemberToPos);

enum N(MemberOffsets) {
    HOME_OFFSET_X       = 0,
    HOME_OFFSET_Z       = 1,
};

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_MEMBER_01   = 2,
    PRT_MEMBER_02   = 3,
    PRT_MEMBER_03   = 4,
    PRT_MEMBER_04   = 5,
    PRT_MEMBER_05   = 6,
    PRT_MEMBER_06   = 7,
    PRT_MEMBER_07   = 8,
    PRT_MEMBER_08   = 9,
};

#define NUM_MEMBERS (1 + PRT_MEMBER_08 - PRT_MEMBER_01)

#define LOOP_MEMBERS(idx) \
    EVT_SET(idx, PRT_MEMBER_01) \
    EVT_LOOP(NUM_MEMBERS)

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
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_PRIMARY_TARGET,
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
        .index = PRT_MEMBER_01,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_02,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_03,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_04,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_05,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_06,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_07,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_08,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_HEALTH_BAR,
    .type = ACTOR_TYPE_SHY_SQUAD_STUB,
    .level = ACTOR_LEVEL_SHY_SQUAD_STUB,
    .maxHP = 10,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
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

s32 N(DefaultAnims)[] = {
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

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_01, HOME_OFFSET_X, 0)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_01, HOME_OFFSET_Z, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_02, HOME_OFFSET_X, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_02, HOME_OFFSET_Z, -30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_03, HOME_OFFSET_X, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_03, HOME_OFFSET_Z, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_04, HOME_OFFSET_X, 20)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_04, HOME_OFFSET_Z, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_05, HOME_OFFSET_X, 30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_05, HOME_OFFSET_Z, 10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_06, HOME_OFFSET_X, 30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_06, HOME_OFFSET_Z, -30)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_07, HOME_OFFSET_X, 40)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_07, HOME_OFFSET_Z, -10)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_08, HOME_OFFSET_X, 50)
    EVT_CALL(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_08, HOME_OFFSET_Z, 10)
    LOOP_MEMBERS(LVar0)
        EVT_CALL(SetPartPos, ACTOR_SELF, LVar0, 185, 0, 47)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_CALL(ForceHomePos, ACTOR_SELF, 20, 0, -10)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_SET(LVar0, PRT_MEMBER_01)
    EVT_SET(LVar1, ANIM_TankGuy_Anim03)
    EVT_SET(LVar4, EVT_FLOAT(4.0))
    EVT_SET(LVar5, 5)
    EVT_LOOP(NUM_MEMBERS)
        EVT_THREAD
            EVT_CALL(GetPartMovementVar, ACTOR_SELF, LVar0, HOME_OFFSET_X, LVar2)
            EVT_CALL(GetPartMovementVar, ACTOR_SELF, LVar0, HOME_OFFSET_Z, LVar3)
            EVT_SET(LVar5, 20)
            EVT_EXEC_WAIT(N(EVS_MoveMemberToPos))
            EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, ANIM_TankGuy_Anim01)
        EVT_END_THREAD
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MoveMemberToPos) = {
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

EvtScript N(EVS_HandleEvent) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_RETURN
    EVT_END
};
