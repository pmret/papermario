#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/TankGuy.h"

#include "battle/area/omo2/actor/boss_common.h"

#define NAMESPACE b_area_omo2_5_shy_squad_redux

extern s32 N(DarkAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_MoveMemberToPos);
extern EvtScript N(EVS_MemberHitReaction);
extern EvtScript N(EVS_MemberShockReaction);
extern EvtScript N(EVS_ReduceCrowdSize);
extern EvtScript N(EVS_SetMembersAnimation);
extern EvtScript N(EVS_Death);
extern EvtScript N(EVS_NotifyNextWave);
extern EvtScript N(EVS_Flee);
extern EvtScript N(EVS_Attack_Swarm);
extern EvtScript N(EVS_MoveSquadHome);

enum N(MemberOffsets) {
    HOME_OFFSET_X       = 0,
    HOME_OFFSET_Z       = 1,
    HIT_OFFSET_X        = 2,
    HIT_OFFSET_Z        = 3,
    SWARM_OFFSET_X      = 4,
    SWARM_OFFSET_Z      = 5,
};

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_MEMBER_01       = 2,
    PRT_MEMBER_02       = 3,
    PRT_MEMBER_03       = 4,
    PRT_MEMBER_04       = 5,
    PRT_MEMBER_05       = 6,
    PRT_MEMBER_06       = 7,
    PRT_MEMBER_07       = 8,
    PRT_MEMBER_08       = 9,
    PRT_MEMBER_09       = 10,
    PRT_MEMBER_10       = 11,
    PRT_MEMBER_11       = 12,
    PRT_MEMBER_12       = 13,
    PRT_MEMBER_13       = 14,
    PRT_MEMBER_14       = 15,
    PRT_MEMBER_15       = 16,
};

#define NUM_MEMBERS (1 + PRT_MEMBER_15 - PRT_MEMBER_01)

#define LOOP_MEMBERS(idx) \
    Set(idx, PRT_MEMBER_01) \
    Loop(NUM_MEMBERS)

enum N(ActorVars) {
    AVAR_NumDefeated        = 3,
    AVAR_NumPendingDefeat   = 4,
    AVAR_FleeState          = 15,
    AVAL_Flee_Init              = 0,
    AVAL_Flee_Looping           = 1,
    AVAL_Flee_Done              = 2,
};

enum N(ActorParams) {
    DMG_SWARM       = 1,
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
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DarkAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_01,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DarkAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_02,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DarkAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_03,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DarkAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_04,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DarkAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_05,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DarkAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_06,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DarkAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_07,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DarkAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_08,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DarkAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_09,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DarkAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_10,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DarkAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_11,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DarkAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_12,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DarkAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_13,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DarkAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_14,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DarkAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_DECORATIONS | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_MEMBER_15,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DarkAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW,
    .type = ACTOR_TYPE_SHY_SQUAD_REDUX,
    .level = ACTOR_LEVEL_SHY_SQUAD_REDUX,
    .maxHP = 15,
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

s32 N(DarkAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_TankGuy_Anim01,
    STATUS_KEY_STOP,      ANIM_TankGuy_Anim00,
    STATUS_END,
};

s32 N(BrightAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_TankGuy_Anim07,
    STATUS_KEY_STOP,      ANIM_TankGuy_Anim00,
    STATUS_END,
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_NumDefeated, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_NumPendingDefeat, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_FleeState, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_01, HOME_OFFSET_X, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_01, HOME_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_02, HOME_OFFSET_X, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_02, HOME_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_03, HOME_OFFSET_X, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_03, HOME_OFFSET_Z, -40)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_04, HOME_OFFSET_X, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_04, HOME_OFFSET_Z, 40)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_05, HOME_OFFSET_X, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_05, HOME_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_06, HOME_OFFSET_X, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_06, HOME_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_07, HOME_OFFSET_X, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_07, HOME_OFFSET_Z, -40)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_08, HOME_OFFSET_X, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_08, HOME_OFFSET_Z, 40)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_09, HOME_OFFSET_X, 40)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_09, HOME_OFFSET_Z, 40)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_10, HOME_OFFSET_X, 50)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_10, HOME_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_11, HOME_OFFSET_X, 50)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_11, HOME_OFFSET_Z, -40)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_12, HOME_OFFSET_X, 30)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_12, HOME_OFFSET_Z, -40)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_13, HOME_OFFSET_X, 40)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_13, HOME_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_14, HOME_OFFSET_X, 30)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_14, HOME_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_15, HOME_OFFSET_X, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_15, HOME_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_01, HIT_OFFSET_X, -30)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_01, HIT_OFFSET_Z, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_02, HIT_OFFSET_X, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_02, HIT_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_03, HIT_OFFSET_X, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_03, HIT_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_04, HIT_OFFSET_X, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_04, HIT_OFFSET_Z, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_05, HIT_OFFSET_X, -30)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_05, HIT_OFFSET_Z, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_06, HIT_OFFSET_X, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_06, HIT_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_07, HIT_OFFSET_X, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_07, HIT_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_08, HIT_OFFSET_X, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_08, HIT_OFFSET_Z, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_09, HIT_OFFSET_X, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_09, HIT_OFFSET_Z, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_10, HIT_OFFSET_X, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_10, HIT_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_11, HIT_OFFSET_X, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_11, HIT_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_12, HIT_OFFSET_X, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_12, HIT_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_13, HIT_OFFSET_X, 30)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_13, HIT_OFFSET_Z, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_14, HIT_OFFSET_X, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_14, HIT_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_15, HIT_OFFSET_X, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_15, HIT_OFFSET_Z, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_01, SWARM_OFFSET_X, -30)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_01, SWARM_OFFSET_Z, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_02, SWARM_OFFSET_X, -30)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_02, SWARM_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_03, SWARM_OFFSET_X, 30)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_03, SWARM_OFFSET_Z, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_04, SWARM_OFFSET_X, 30)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_04, SWARM_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_05, SWARM_OFFSET_X, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_05, SWARM_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_06, SWARM_OFFSET_X, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_06, SWARM_OFFSET_Z, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_07, SWARM_OFFSET_X, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_07, SWARM_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_08, SWARM_OFFSET_X, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_08, SWARM_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_09, SWARM_OFFSET_X, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_09, SWARM_OFFSET_Z, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_10, SWARM_OFFSET_X, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_10, SWARM_OFFSET_Z, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_11, SWARM_OFFSET_X, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_11, SWARM_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_12, SWARM_OFFSET_X, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_12, SWARM_OFFSET_Z, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_13, SWARM_OFFSET_X, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_13, SWARM_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_14, SWARM_OFFSET_X, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_14, SWARM_OFFSET_Z, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_15, SWARM_OFFSET_X, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_15, SWARM_OFFSET_Z, 0)
    LOOP_MEMBERS(LVar0)
        Call(SetPartPos, ACTOR_SELF, LVar0, 185, 0, 47)
        Add(LVar0, 1)
    EndLoop
    Call(ForceHomePos, ACTOR_SELF, 20, 0, -10)
    Call(HPBarToHome, ACTOR_SELF)
    LOOP_MEMBERS(LVar0)
        Call(CreatePartShadow, ACTOR_SELF, LVar0)
        Add(LVar0, 1)
    EndLoop
    Set(LVar0, PRT_MEMBER_01)
    Set(LVar1, ANIM_TankGuy_Anim03)
    Set(LVar2, 55)
    Set(LVar3, 47)
    Set(LVar4, Float(4.0))
    Set(LVar5, 30)
    Set(LVarF, 0)
    Loop(NUM_MEMBERS)
        Thread
            Wait(LVarF)
            ExecWait(N(EVS_MoveMemberToPos))
            Call(GetPartMovementVar, ACTOR_SELF, LVar0, HOME_OFFSET_X, LVar2)
            Call(GetPartMovementVar, ACTOR_SELF, LVar0, HOME_OFFSET_Z, LVar3)
            Set(LVar5, 20)
            ExecWait(N(EVS_MoveMemberToPos))
            Call(SetAnimation, ACTOR_SELF, LVar0, ANIM_TankGuy_Anim01)
        EndThread
        Add(LVar0, 1)
        Add(LVarF, 5)
    EndLoop
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
        Call(GetCurrentPartnerID, LVar0)
        IfEq(LVar0, PARTNER_WATT)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(BrightAnims)))
            LOOP_MEMBERS(LVar0)
                Call(SetIdleAnimations, ACTOR_SELF, LVar0, Ref(N(BrightAnims)))
                Add(LVar0, 1)
            EndLoop
        Else
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DarkAnims)))
            LOOP_MEMBERS(LVar0)
                Call(SetIdleAnimations, ACTOR_SELF, LVar0, Ref(N(DarkAnims)))
                Add(LVar0, 1)
            EndLoop
        EndIf
        Wait(1)
    Goto(0)
    Return
    End
};

EvtScript N(EVS_MoveMemberToPos) = {
    Set(LVarA, 2)
    Call(GetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVarB)
    Add(LVarA, LVarB)
    IfLt(LVar0, LVarA)
        Return
    EndIf
    Call(GetPartOffset, ACTOR_SELF, LVar0, LVar6, 0, LVar7)
    IfLt(LVar6, LVar2)
        Call(SetPartYaw, ACTOR_SELF, LVar0, 180)
    Else
        Call(SetPartYaw, ACTOR_SELF, LVar0, 0)
    EndIf
    Call(GetDist2D, LVar9, LVar6, LVar7, LVar2, LVar3)
    IfGe(LVar9, LVar4)
        Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        Call(SetPartMoveSpeed, ACTOR_SELF, LVar0, LVar4)
        Call(RunPartTo, ACTOR_SELF, LVar0, LVar2, 0, LVar3, LVar5)
    EndIf
    Return
    End
};

EvtScript N(EVS_HitReaction) = {
    SetConst(LVar0, PRT_MEMBER_01)
    Loop(NUM_MEMBERS)
        Call(GetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVarD)
        Call(GetActorVar, ACTOR_SELF, AVAR_NumPendingDefeat, LVarE)
        Add(LVarD, 2)
        Add(LVarD, LVarE)
        IfGe(LVar0, LVarD)
            Thread
                ExecWait(N(EVS_MemberHitReaction))
            EndThread
        EndIf
        Add(LVar0, 1)
    EndLoop
    Wait(30)
    Return
    End
};

EvtScript N(EVS_MemberHitReaction) = {
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Set(LVar2, LVar0)
    Call(GetDamageIntensity)
    Switch(LVar0)
        CaseEq(DAMAGE_INTENSITY_LIGHT)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 1, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 3, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 8, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 4, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 10, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 4, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 5, 0)
            Wait(1)
            Loop(2)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 3, 0)
                Wait(1)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(4)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 1, 0)
                Wait(1)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
            Wait(10)
        CaseEq(DAMAGE_INTENSITY_MEDIUM)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 1, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 4, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 20, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 10, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 22, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 10, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 14, 0)
            Wait(1)
            Loop(2)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 7, 0)
                Wait(1)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(6)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 3, 0)
                Wait(1)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
            Wait(10)
        CaseEq(DAMAGE_INTENSITY_HEAVY)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 1, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 6, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 22, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 12, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 25, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 12, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 17, 0)
            Wait(1)
            Loop(2)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 10, 0)
                Wait(1)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(6)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 4, 0)
                Wait(1)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
            Wait(10)
        CaseEq(DAMAGE_INTENSITY_EXTREME)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 3, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 8, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 24, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 14, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 28, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 14, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 19, 0)
            Wait(1)
            Loop(2)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 14, 0)
                Wait(1)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(6)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 5, 0)
                Wait(1)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(2)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 2, 0)
                Wait(1)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
            Wait(10)
        CaseEq(DAMAGE_INTENSITY_UNUSED)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 5, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 10, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 28, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 16, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 32, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 16, 0)
            Wait(1)
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 21, 0)
            Wait(1)
            Loop(2)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 16, 0)
                Wait(1)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(6)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 7, 0)
                Wait(1)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                Wait(1)
            EndLoop
            Loop(2)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 3, 0)
                Wait(1)
                Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
                Wait(1)
            EndLoop
            Call(SetPartDispOffset, ACTOR_SELF, LVar2, 0, 0, 0)
            Wait(10)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Shock) = {
    SetConst(LVar0, PRT_MEMBER_01)
    Loop(NUM_MEMBERS)
        Call(GetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVarD)
        Call(GetActorVar, ACTOR_SELF, AVAR_NumPendingDefeat, LVarE)
        Add(LVarD, 2)
        Add(LVarD, LVarE)
        IfGe(LVar0, LVarD)
            Thread
                ExecWait(N(EVS_MemberShockReaction))
            EndThread
        EndIf
        Add(LVar0, 1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_MemberShockReaction) = {
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Call(GetPartOffset, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3)
    Call(GetActorSize, ACTOR_SELF, LVar4, LVar5)
    PlayEffect(EFFECT_FLASHING_BOX_SHOCKWAVE, FX_SHOCK_OVERLAY_SHOCK_HIT, LVar1, LVar2, LVar3, LVar5, LVar4, 0)
    Call(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 0, 0)
    Call(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 1, 0)
    Wait(1)
    Call(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 4, 0)
    Wait(1)
    Call(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 16, 0)
    Wait(1)
    Call(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 8, 0)
    Wait(1)
    Call(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 20, 0)
    Wait(1)
    Call(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 8, 0)
    Wait(1)
    Call(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 12, 0)
    Wait(1)
    Loop(2)
        Call(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 6, 0)
        Wait(1)
        Call(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    Loop(6)
        Call(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 2, 0)
        Wait(1)
        Call(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    Call(SetPartDispOffset, ACTOR_SELF, LVar0, 0, 0, 0)
    Wait(10)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar1, ANIM_TankGuy_Anim04)
            ExecWait(N(EVS_ReduceCrowdSize))
            SetConst(LVar1, ANIM_TankGuy_Anim04)
            ExecWait(N(EVS_HitReaction))
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar1, ANIM_TankGuy_Anim04)
            ExecWait(N(EVS_ReduceCrowdSize))
            SetConst(LVar1, ANIM_TankGuy_Anim04)
            ExecWait(N(EVS_HitReaction))
            Wait(10)
            SetConst(LVar1, ANIM_TankGuy_Anim04)
            ExecWait(N(EVS_Death))
            Return
        CaseOrEq(EVENT_BURN_HIT)
        CaseOrEq(EVENT_BURN_DEATH)
            SetConst(LVar1, ANIM_TankGuy_Anim05)
            ExecWait(N(EVS_ReduceCrowdSize))
            LOOP_MEMBERS(LVar0)
                Call(SetAnimation, ACTOR_SELF, LVar0, ANIM_TankGuy_Anim05)
                Add(LVar0, 1)
            EndLoop
            Wait(20)
            LOOP_MEMBERS(LVar0)
                Call(SetAnimation, ACTOR_SELF, LVar0, ANIM_TankGuy_Anim05)
                Add(LVar0, 1)
            EndLoop
            Wait(15)
            IfEq(LVar0, 36)
                Wait(10)
                SetConst(LVar1, ANIM_TankGuy_Anim05)
                ExecWait(N(EVS_Death))
                Return
            EndIf
        EndCaseGroup
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar1, ANIM_TankGuy_Anim04)
            ExecWait(N(EVS_ReduceCrowdSize))
            SetConst(LVar1, ANIM_TankGuy_Anim04)
            ExecWait(N(EVS_HitReaction))
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar1, ANIM_TankGuy_Anim04)
            ExecWait(N(EVS_ReduceCrowdSize))
            SetConst(LVar1, ANIM_TankGuy_Anim04)
            ExecWait(N(EVS_HitReaction))
            SetConst(LVar1, ANIM_TankGuy_Anim04)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar1, ANIM_TankGuy_Anim04)
            ExecWait(N(EVS_ReduceCrowdSize))
            SetConst(LVar1, ANIM_TankGuy_Anim04)
            ExecWait(N(EVS_Shock))
            Wait(40)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            ExecWait(N(EVS_MoveSquadHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar1, ANIM_TankGuy_Anim04)
            ExecWait(N(EVS_ReduceCrowdSize))
            SetConst(LVar1, ANIM_TankGuy_Anim04)
            ExecWait(N(EVS_Shock))
            Wait(40)
            SetConst(LVar1, ANIM_TankGuy_Anim04)
            ExecWait(N(EVS_Death))
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_SPIKE_TAUNT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TankGuy_Anim01)
            ExecWait(N(EVS_HitReaction))
        EndCaseGroup
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            Set(LVar1, ANIM_TankGuy_Anim04)
            ExecWait(N(EVS_SetMembersAnimation))
            Wait(1000)
        CaseEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TankGuy_Anim01)
            ExecWait(N(EVS_HitReaction))
        CaseEq(EVENT_END_FIRST_STRIKE)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TankGuy_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_30)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_TankGuy_Anim04)
            ExecWait(EVS_Enemy_Hit)
            Wait(1000)
        CaseEq(EVENT_SCARE_AWAY)
        CaseDefault
    EndSwitch
    Set(LVar1, ANIM_TankGuy_Anim01)
    ExecWait(N(EVS_SetMembersAnimation))
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_ReduceCrowdSize) = {
    Set(LVar1, LVar1)
    ExecWait(N(EVS_SetMembersAnimation))
    Call(GetActorVar, ACTOR_SELF, AVAR_NumPendingDefeat, LVar0)
    Call(GetLastDamage, ACTOR_SELF, LVar1)
    Add(LVar0, LVar1)
    Call(SetActorVar, ACTOR_SELF, AVAR_NumPendingDefeat, LVar0)
    Label(0)
        Call(GetActorVar, ACTOR_SELF, AVAR_NumPendingDefeat, LVar0)
        IfEq(LVar0, 0)
            Return
        EndIf
        Call(GetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVar1)
        IfGe(LVar1, 15)
            Return
        EndIf
        Set(LVar0, PRT_MEMBER_01)
        Add(LVar0, LVar1)
        IfNe(LVar0, NUM_MEMBERS + 1)
            Thread
                Call(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_NO_STATUS_ANIMS, true)
                Call(GetPartOffset, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3)
                Call(GetPartMovementVar, ACTOR_SELF, LVar0, HIT_OFFSET_X, LVar7)
                Call(GetPartMovementVar, ACTOR_SELF, LVar0, HIT_OFFSET_Z, LVar8)
                Add(LVar1, LVar7)
                Add(LVar3, LVar8)
                Call(SetPartJumpGravity, ACTOR_SELF, LVar0, Float(0.5))
                Call(JumpPartTo, ACTOR_SELF, LVar0, LVar1, 0, LVar3, 15, true)
                Call(GetDamageSource, LVar5)
                Switch(LVar5)
                    CaseOrEq(DMG_SRC_NEXT_SLAP_LEFT)
                    CaseOrEq(DMG_SRC_NEXT_FAN_SMACK_LEFT)
                    CaseOrEq(DMG_SRC_LAST_SLAP_LEFT)
                    CaseOrEq(DMG_SRC_LAST_FAN_SMACK_LEFT)
                    CaseOrEq(DMG_SRC_NEXT_SLAP_RIGHT)
                    CaseOrEq(DMG_SRC_NEXT_FAN_SMACK_RIGHT)
                    CaseOrEq(DMG_SRC_LAST_SLAP_RIGHT)
                    CaseOrEq(DMG_SRC_LAST_FAN_SMACK_RIGHT)
                    CaseOrEq(DMG_SRC_SPIN_SMASH)
                    EndCaseGroup
                    CaseDefault
                        Set(LVar7, 0)
                        Loop(24)
                            Call(SetPartRotation, ACTOR_SELF, LVar0, 0, LVar7, 0)
                            Add(LVar7, 30)
                            Wait(1)
                        EndLoop
                EndSwitch
                PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar1, LVar2, LVar3, 0, 0, 0, 0, 0)
                Set(LVar8, 0)
                Loop(12)
                    Call(SetPartRotation, ACTOR_SELF, LVar0, LVar8, 0, 0)
                    Add(LVar8, 8)
                    Wait(1)
                EndLoop
                Call(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, true)
                Call(RemovePartShadow, ACTOR_SELF, LVar0)
            EndThread
        EndIf
        Call(GetActorVar, ACTOR_SELF, AVAR_NumPendingDefeat, LVar0)
        Sub(LVar0, 1)
        Call(SetActorVar, ACTOR_SELF, AVAR_NumPendingDefeat, LVar0)
        Call(GetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVar0)
        Add(LVar0, 1)
        Call(SetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVar0)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_SetMembersAnimation) = {
    Set(LVar2, PRT_MEMBER_01)
    Call(GetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVar0)
    Loop(NUM_MEMBERS)
        IfEq(LVar0, 0)
            Call(SetAnimation, ACTOR_SELF, LVar2, LVar1)
        Else
            Sub(LVar0, 1)
        EndIf
        Add(LVar2, 1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_DefeatMember) = {
    IfNe(LVar1, -1)
        Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
        Wait(10)
    EndIf
    Call(GetDamageSource, LVar5)
    Switch(LVar5)
        CaseOrEq(DMG_SRC_NEXT_SLAP_LEFT)
        CaseOrEq(DMG_SRC_NEXT_FAN_SMACK_LEFT)
        CaseOrEq(DMG_SRC_LAST_SLAP_LEFT)
        CaseOrEq(DMG_SRC_LAST_FAN_SMACK_LEFT)
        CaseOrEq(DMG_SRC_NEXT_SLAP_RIGHT)
        CaseOrEq(DMG_SRC_NEXT_FAN_SMACK_RIGHT)
        CaseOrEq(DMG_SRC_LAST_SLAP_RIGHT)
        CaseOrEq(DMG_SRC_LAST_FAN_SMACK_RIGHT)
        CaseOrEq(DMG_SRC_SPIN_SMASH)
        EndCaseGroup
        CaseDefault
            Set(LVar2, 0)
            Loop(24)
                Call(SetPartRotation, ACTOR_SELF, LVar0, 0, LVar2, 0)
                Add(LVar2, 30)
                Wait(1)
            EndLoop
    EndSwitch
    Set(LVar3, 0)
    Loop(12)
        Call(SetPartRotation, ACTOR_SELF, LVar0, LVar3, 0, 0)
        Add(LVar3, 8)
        Wait(1)
    EndLoop
    Call(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, true)
    Call(RemovePartShadow, ACTOR_SELF, LVar0)
    Return
    End
};

EvtScript N(EVS_Death) = {
    SetConst(LVar0, PRT_MEMBER_01)
    Loop(NUM_MEMBERS - 1)
        Call(GetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVar2)
        Call(GetActorVar, ACTOR_SELF, AVAR_NumPendingDefeat, LVar3)
        Add(LVar2, 2)
        Add(LVar2, LVar3)
        IfGe(LVar0, LVar2)
            Thread
                ExecWait(N(EVS_DefeatMember))
            EndThread
        EndIf
        Add(LVar0, 1)
    EndLoop
    Set(LVar0, 16)
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Set(LVar2, 0)
    Loop(24)
        Call(SetPartRotation, ACTOR_SELF, LVar0, 0, LVar2, 0)
        Add(LVar2, 30)
        Wait(1)
    EndLoop
    Call(GetPartOffset, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3)
    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar1, LVar2, LVar3, 0, 0, 0, 0, 0)
    Call(DropStarPoints, ACTOR_SELF)
    Set(LVar3, 0)
    Loop(12)
        Call(SetPartRotation, ACTOR_SELF, LVar0, LVar3, 0, 0)
        Add(LVar3, 8)
        Wait(1)
    EndLoop
    Call(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, true)
    Call(RemovePartShadow, ACTOR_SELF, LVar0)
    Wait(30)
    ExecWait(N(EVS_NotifyNextWave))
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetCurrentPartnerID, LVar0)
    IfEq(LVar0, PARTNER_WATT)
        Call(GetEnemyMaxHP, ACTOR_SELF, LVar0)
        Call(GetActorHP, ACTOR_SELF, LVar1)
        IfEq(LVar0, LVar1)
            ExecWait(N(EVS_Attack_Swarm))
        Else
            ExecWait(N(EVS_Flee))
            ExecWait(N(EVS_NotifyNextWave))
            Call(RemoveActor, ACTOR_SELF)
            Return
        EndIf
    Else
        ExecWait(N(EVS_Attack_Swarm))
    EndIf
    Return
    End
};

EvtScript N(EVS_NotifyNextWave) = {
    Call(FreezeBattleState, true)
    Call(SetActorVar, ACTOR_TANK, AVAR_Tank_UnusedPhase, AVAL_UnusedPhase_Defeated)
    Return
    End
};

EvtScript N(EVS_Flee) = {
    Call(SetActorVar, ACTOR_SELF, AVAR_FleeState, AVAL_Flee_Init)
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 40)
    Set(LVar0, PRT_MEMBER_01)
    Set(LVar1, 0)
    Loop(NUM_MEMBERS)
        Call(GetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVar2)
        Add(LVar2, PRT_MEMBER_01)
        IfGe(LVar0, LVar2)
            Call(SetActorVar, ACTOR_SELF, AVAR_FleeState, AVAL_Flee_Looping)
            Thread
                Wait(LVar1)
                Call(SetAnimation, ACTOR_SELF, LVar0, ANIM_TankGuy_Anim03)
                Call(SetPartYaw, ACTOR_SELF, LVar0, 180)
                Call(RunPartTo, ACTOR_SELF, LVar0, 55, 0, 47, 20)
                Call(RunPartTo, ACTOR_SELF, LVar0, 185, 0, 47, 30)
                IfEq(LVar0, PRT_MEMBER_15)
                    Call(SetActorVar, ACTOR_SELF, AVAR_FleeState, AVAL_Flee_Done)
                EndIf
            EndThread
            Add(LVar1, 5)
        EndIf
        Add(LVar0, 1)
    EndLoop
    // wait for fleeing to finish
    Call(GetActorVar, ACTOR_SELF, AVAR_FleeState, LVar0)
    IfEq(LVar0, AVAL_Flee_Init)
        Call(SetActorVar, ACTOR_SELF, AVAR_FleeState, AVAL_Flee_Done)
    EndIf
    Set(LVar0, 15)
    Loop(0)
        Call(GetActorVar, ACTOR_SELF, AVAR_FleeState, LVar0)
        IfEq(LVar0, AVAL_Flee_Done)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Attack_Swarm) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(SetBattleCamDist, 300)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 30)
    Set(LVar0, PRT_MEMBER_01)
    Set(LVar1, ANIM_TankGuy_Anim03)
    Loop(NUM_MEMBERS)
        Thread
            Call(GetActorPos, ACTOR_PLAYER, LVar2, LVar5, LVar3)
            Call(GetPartMovementVar, ACTOR_SELF, LVar0, SWARM_OFFSET_X, LVar5)
            Add(LVar2, LVar5)
            Call(GetPartMovementVar, ACTOR_SELF, LVar0, SWARM_OFFSET_Z, LVar5)
            Add(LVar3, LVar5)
            SetF(LVar4, Float(6.0))
            Set(LVar5, 30)
            ExecWait(N(EVS_MoveMemberToPos))
        EndThread
        Add(LVar0, 1)
    EndLoop
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(GetGoalPos, ACTOR_PLAYER, LVar2, LVar5, LVar3)
    Call(GetPartMovementVar, ACTOR_SELF, PRT_MEMBER_01, SWARM_OFFSET_X, LVar5)
    Add(LVar2, LVar5)
    Call(GetPartMovementVar, ACTOR_SELF, PRT_MEMBER_01, SWARM_OFFSET_Z, LVar5)
    Add(LVar3, LVar5)
    Call(SetGoalPos, ACTOR_SELF, LVar2, 0, LVar3)
    Call(RunToGoal, ACTOR_SELF, 30, false)
    LOOP_MEMBERS(LVar0)
        Call(GetActorPos, ACTOR_PLAYER, LVar4, LVar5, LVar6)
        Call(GetPartOffset, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3)
        IfLt(LVar1, LVar4)
            Call(SetPartYaw, ACTOR_SELF, LVar0, 180)
        Else
            Call(SetPartYaw, ACTOR_SELF, LVar0, 0)
        EndIf
        Call(RandInt, 100, LVar7)
        IfLt(LVar7, 50)
            Set(LVar7, ANIM_TankGuy_Anim04)
        Else
            Set(LVar7, ANIM_TankGuy_Anim07)
        EndIf
        Call(SetAnimation, ACTOR_SELF, LVar0, LVar7)
        Add(LVar0, 1)
    EndLoop
    Call(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarA)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(GetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVar0)
            IfLt(LVar0, 14)
                Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                PlayEffect(EFFECT_LANDING_DUST, 3, LVar0, LVar1, LVar2, 0, 0)
                Thread
                    Loop(7)
                        PlayEffect(EFFECT_LANDING_DUST, 0, LVar0, LVar1, LVar2, 0, 0)
                        Wait(2)
                        PlayEffect(EFFECT_LANDING_DUST, 1, LVar0, LVar1, LVar2, 0, 0)
                        Wait(2)
                    EndLoop
                EndThread
            EndIf
            Wait(36)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 30)
            ExecWait(N(EVS_MoveSquadHome))
            Set(LVar1, ANIM_TankGuy_Anim01)
            ExecWait(N(EVS_SetMembersAnimation))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
        CaseEq(HIT_RESULT_HIT_STATIC)
            Call(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, DMG_SWARM, BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Set(LVarE, 15)
    Call(GetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVar0)
    Sub(LVarE, LVar0)
    Set(LVarD, LVarE)
    Loop(LVarD)
        IfGt(LVarE, 1)
            Set(LVar0, BS_FLAGS1_NICE_HIT)
        Else
            Set(LVar0, BS_FLAGS1_TRIGGER_EVENTS)
        EndIf
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, DMG_SWARM, LVar0)
        Thread
            Call(GetActorPos, ACTOR_PLAYER, LVar1, LVar2, LVar3)
            PlayEffect(EFFECT_LANDING_DUST, 0, LVar1, LVar2, LVar3, 0, 0)
            Wait(2)
            PlayEffect(EFFECT_LANDING_DUST, 1, LVar1, LVar2, LVar3, 0, 0)
            Wait(2)
        EndThread
        Call(GetPlayerHP, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
        Sub(LVarE, 1)
        IfEq(LVarE, 0)
            BreakLoop
        EndIf
        Wait(10)
    EndLoop
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Wait(20)
    ExecWait(N(EVS_MoveSquadHome))
    Set(LVar1, ANIM_TankGuy_Anim01)
    ExecWait(N(EVS_SetMembersAnimation))
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_MoveSquadHome) = {
    Set(LVar0, PRT_MEMBER_01)
    Set(LVar1, ANIM_TankGuy_Anim03)
    Loop(NUM_MEMBERS)
        Thread
            Call(SetGoalToHome, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar2, LVar5, LVar3)
            Call(GetPartMovementVar, ACTOR_SELF, LVar0, SWARM_OFFSET_X, LVar5)
            Add(LVar2, LVar5)
            Call(GetPartMovementVar, ACTOR_SELF, LVar0, SWARM_OFFSET_Z, LVar5)
            Add(LVar3, LVar5)
            SetF(LVar4, Float(6.0))
            Set(LVar5, 30)
            ExecWait(N(EVS_MoveMemberToPos))
            Call(SetAnimation, ACTOR_SELF, LVar0, ANIM_TankGuy_Anim01)
            Call(SetPartYaw, ACTOR_SELF, LVar0, 0)
        EndThread
        Add(LVar0, 1)
    EndLoop
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetGoalToHome, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar2, LVar5, LVar3)
    Call(GetPartMovementVar, ACTOR_SELF, PRT_MEMBER_01, SWARM_OFFSET_X, LVar5)
    Add(LVar2, LVar5)
    Call(GetPartMovementVar, ACTOR_SELF, PRT_MEMBER_01, SWARM_OFFSET_Z, LVar5)
    Add(LVar3, LVar5)
    Call(SetGoalPos, ACTOR_SELF, LVar2, 0, LVar3)
    Call(RunToGoal, ACTOR_SELF, 30, false)
    Return
    End
};
