#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/ShySquadGuy.h"
#include "sprite/player.h"

#include "battle/area/omo2/actor/boss_common.h"

#define NAMESPACE b_area_omo2_1_shy_squad

extern s32 N(DefaultAnims)[];
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

extern EvtScript N(EVS_MoveSquadHome);
extern EvtScript N(EVS_SetMembersAnimation);
extern EvtScript N(EVS_MemberHitReaction);
extern EvtScript N(EVS_MemberShockReaction);
extern EvtScript N(EVS_ReduceCrowdSize);
extern EvtScript N(EVS_UpdateActorSize);
extern EvtScript N(EVS_Death);
extern EvtScript N(EVS_Flee);
extern EvtScript N(EVS_NotifyNextWave);

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
    AVAR_SquadArrived       = 0,
    AVAR_BeenAttackedCount  = 1,
    AVAR_HasBeenAttacked    = 2,
    AVAR_NumDefeated        = 3,
    AVAR_NumPendingDefeat   = 4,
};

enum N(ActorParams) {
    DMG_SWARM       = 1,
};

API_CALLABLE(N(GetActorPartSize)) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    ActorPart* actorPart;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actorPart = get_actor_part(get_actor(actorID), partID);
    evt_set_variable(script, *args++, actorPart->size.y);
    evt_set_variable(script, *args++, actorPart->size.x);

    return ApiStatus_DONE2;
}

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
        .idleAnimations = N(DefaultAnims),
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
        .idleAnimations = N(DefaultAnims),
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
        .idleAnimations = N(DefaultAnims),
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
        .idleAnimations = N(DefaultAnims),
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
        .idleAnimations = N(DefaultAnims),
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
        .idleAnimations = N(DefaultAnims),
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
        .idleAnimations = N(DefaultAnims),
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
        .idleAnimations = N(DefaultAnims),
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
        .idleAnimations = N(DefaultAnims),
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
        .idleAnimations = N(DefaultAnims),
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
        .idleAnimations = N(DefaultAnims),
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
        .idleAnimations = N(DefaultAnims),
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
        .idleAnimations = N(DefaultAnims),
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
        .idleAnimations = N(DefaultAnims),
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
        .idleAnimations = N(DefaultAnims),
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
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW,
    .type = ACTOR_TYPE_SHY_SQUAD,
    .level = ACTOR_LEVEL_SHY_SQUAD,
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
    .size = { 28, 24 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ShySquadGuy_Anim01,
    STATUS_KEY_STONE,     ANIM_ShySquadGuy_Anim00,
    STATUS_KEY_SLEEP,     ANIM_ShySquadGuy_Anim12,
    STATUS_KEY_POISON,    ANIM_ShySquadGuy_Anim01,
    STATUS_KEY_STOP,      ANIM_ShySquadGuy_Anim00,
    STATUS_KEY_STATIC,    ANIM_ShySquadGuy_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_ShySquadGuy_Anim00,
    STATUS_KEY_PARALYZE,  ANIM_ShySquadGuy_Anim00,
    STATUS_KEY_DIZZY,     ANIM_ShySquadGuy_Anim13,
    STATUS_KEY_DIZZY,     ANIM_ShySquadGuy_Anim13,
    STATUS_KEY_FEAR,      ANIM_ShySquadGuy_Anim00,
    STATUS_END,
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_SquadArrived, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_BeenAttackedCount, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_HasBeenAttacked, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_NumDefeated, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_NumPendingDefeat, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_01, HOME_OFFSET_X, 50)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_01, HOME_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_02, HOME_OFFSET_X, 50)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_02, HOME_OFFSET_Z, -40)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_03, HOME_OFFSET_X, 40)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_03, HOME_OFFSET_Z, 40)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_04, HOME_OFFSET_X, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_04, HOME_OFFSET_Z, 40)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_05, HOME_OFFSET_X, 30)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_05, HOME_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_06, HOME_OFFSET_X, 40)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_06, HOME_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_07, HOME_OFFSET_X, 30)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_07, HOME_OFFSET_Z, -40)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_08, HOME_OFFSET_X, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_08, HOME_OFFSET_Z, 40)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_09, HOME_OFFSET_X, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_09, HOME_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_10, HOME_OFFSET_X, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_10, HOME_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_11, HOME_OFFSET_X, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_11, HOME_OFFSET_Z, -40)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_12, HOME_OFFSET_X, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_12, HOME_OFFSET_Z, -40)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_13, HOME_OFFSET_X, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_13, HOME_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_14, HOME_OFFSET_X, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_14, HOME_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_15, HOME_OFFSET_X, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_15, HOME_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_01, HIT_OFFSET_X, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_01, HIT_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_02, HIT_OFFSET_X, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_02, HIT_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_03, HIT_OFFSET_X, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_03, HIT_OFFSET_Z, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_04, HIT_OFFSET_X, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_04, HIT_OFFSET_Z, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_05, HIT_OFFSET_X, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_05, HIT_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_06, HIT_OFFSET_X, 30)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_06, HIT_OFFSET_Z, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_07, HIT_OFFSET_X, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_07, HIT_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_08, HIT_OFFSET_X, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_08, HIT_OFFSET_Z, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_09, HIT_OFFSET_X, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_09, HIT_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_10, HIT_OFFSET_X, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_10, HIT_OFFSET_Z, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_11, HIT_OFFSET_X, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_11, HIT_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_12, HIT_OFFSET_X, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_12, HIT_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_13, HIT_OFFSET_X, -30)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_13, HIT_OFFSET_Z, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_14, HIT_OFFSET_X, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_14, HIT_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_15, HIT_OFFSET_X, -30)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_15, HIT_OFFSET_Z, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_01, SWARM_OFFSET_X, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_01, SWARM_OFFSET_Z, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_02, SWARM_OFFSET_X, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_02, SWARM_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_03, SWARM_OFFSET_X, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_03, SWARM_OFFSET_Z, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_04, SWARM_OFFSET_X, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_04, SWARM_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_05, SWARM_OFFSET_X, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_05, SWARM_OFFSET_Z, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_06, SWARM_OFFSET_X, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_06, SWARM_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_07, SWARM_OFFSET_X, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_07, SWARM_OFFSET_Z, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_08, SWARM_OFFSET_X, 30)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_08, SWARM_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_09, SWARM_OFFSET_X, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_09, SWARM_OFFSET_Z, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_10, SWARM_OFFSET_X, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_10, SWARM_OFFSET_Z, 0)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_11, SWARM_OFFSET_X, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_11, SWARM_OFFSET_Z, 20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_12, SWARM_OFFSET_X, 30)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_12, SWARM_OFFSET_Z, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_13, SWARM_OFFSET_X, -30)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_13, SWARM_OFFSET_Z, 10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_14, SWARM_OFFSET_X, -30)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_14, SWARM_OFFSET_Z, -10)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_15, SWARM_OFFSET_X, -20)
    Call(SetPartMovementVar, ACTOR_SELF, PRT_MEMBER_15, SWARM_OFFSET_Z, 20)
    Call(RandInt, 100, LVar0)
    Add(LVar0, 190)
    Call(RandInt, 100, LVar2)
    Add(LVar2, -50)
    Call(SetActorPos, ACTOR_SELF, LVar0, 0, LVar2)
    LOOP_MEMBERS(LVar1)
        Call(RandInt, 100, LVar0)
        Add(LVar0, 190)
        Call(RandInt, 100, LVar2)
        Add(LVar2, -50)
        Call(SetPartPos, ACTOR_SELF, LVar1, LVar0, 0, LVar2)
        Add(LVar1, 1)
    EndLoop
    LOOP_MEMBERS(LVar0)
        Call(CreatePartShadow, ACTOR_SELF, LVar0)
        Add(LVar0, 1)
    EndLoop
    Call(SetActorSize, ACTOR_SELF, EVT_IGNORE_ARG, 72)
    Call(SetPartSize, ACTOR_SELF, PRT_MAIN, 24, 24)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_PLAYER_BEGIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_SquadArrived, LVar0)
            IfEq(LVar0, 0)
                Call(SetActorVar, ACTOR_SELF, AVAR_SquadArrived, TRUE)
                LOOP_MEMBERS(LVar0)
                    Call(SetAnimation, ACTOR_SELF, LVar0, ANIM_ShySquadGuy_Anim03)
                    Add(LVar0, 1)
                EndLoop
                Call(SetHomePos, ACTOR_SELF, 65, 0, -10)
                Call(HPBarToHome, ACTOR_SELF)
                Call(SetActorYaw, ACTOR_SELF, 0)
                Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
                Set(LVar1, ANIM_ShySquadGuy_Anim03)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SHY_GUY_SCREAMS1)
                ExecWait(N(EVS_MoveSquadHome))
                Wait(10)
                Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
                Call(SetBattleCamDist, 360)
                Call(SetBattleCamTarget, 72, 45, 0)
                Call(MoveBattleCamOver, 30)
                Wait(30)
                Call(EnableBattleStatusBar, FALSE)
                Call(ActorSpeak, MSG_CH4_0065, ACTOR_SELF, PRT_MEMBER_08, ANIM_ShySquadGuy_Anim11, ANIM_ShySquadGuy_Anim11)
                LOOP_MEMBERS(LVar0)
                    Call(SetAnimation, ACTOR_SELF, LVar0, ANIM_ShySquadGuy_Anim0A)
                    Add(LVar0, 1)
                EndLoop
                Call(EndActorSpeech, ACTOR_SELF, PRT_MAIN, -1, -1)
                Call(EnableBattleStatusBar, TRUE)
                LOOP_MEMBERS(LVar0)
                    Call(SetAnimation, ACTOR_SELF, LVar0, ANIM_ShySquadGuy_Anim01)
                    Add(LVar0, 1)
                EndLoop
            EndIf
        CaseEq(PHASE_ENEMY_BEGIN)
            Call(GetActorVar, ACTOR_SELF, AVAR_HasBeenAttacked, LVar0)
            IfNe(LVar0, 0)
                Call(SetActorVar, ACTOR_SELF, AVAR_HasBeenAttacked, 0)
                Call(GetActorVar, ACTOR_SELF, AVAR_BeenAttackedCount, LVar0)
                Add(LVar0, 1)
                Call(SetActorVar, ACTOR_SELF, AVAR_BeenAttackedCount, LVar0)
                IfGe(LVar0, 2)
                    Call(GetActorVar, ACTOR_GENERAL, AVAR_General_Flags, LVar0)
                    BitwiseOrConst(LVar0, AVAR_GeneralFlag_SquadFled)
                    Call(SetActorVar, ACTOR_GENERAL, AVAR_General_Flags, LVar0)
                    ExecWait(N(EVS_Flee))
                    Return
                EndIf
            EndIf
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_MoveMemberToPos) = {
    Set(LVarA, PRT_MEMBER_01)
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

EvtScript N(EVS_MoveSquadHome) = {
    LOOP_MEMBERS(LVar0)
        Thread
            Call(SetGoalToHome, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar2, LVar4, LVar3)
            Call(GetPartMovementVar, ACTOR_SELF, LVar0, HOME_OFFSET_X, LVar4)
            Add(LVar2, LVar4)
            Call(GetPartMovementVar, ACTOR_SELF, LVar0, HOME_OFFSET_Z, LVar4)
            Add(LVar3, LVar4)
            Set(LVar4, Float(6.0))
            Set(LVar5, 0)
            ExecWait(N(EVS_MoveMemberToPos))
            Set(LVarA, 2)
            Call(GetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVarB)
            Add(LVarA, LVarB)
            IfGe(LVar0, LVarA)
                Call(SetPartYaw, ACTOR_SELF, LVar0, 0)
                Call(SetAnimation, ACTOR_SELF, LVar0, ANIM_ShySquadGuy_Anim01)
            EndIf
        EndThread
        Add(LVar0, 1)
    EndLoop
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetGoalToHome, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVarD, LVarE, LVarF)
    Call(SetGoalPos, ACTOR_SELF, LVarD, LVarE, LVarF)
    Call(RunToGoal, ACTOR_SELF, 0, TRUE)
    Return
    End
};

EvtScript N(EVS_HitReaction) = {
    SetConst(LVar0, PRT_MEMBER_15)
    ExecWait(N(EVS_MemberHitReaction))
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
    Wait(33)
    Return
    End
};

EvtScript N(EVS_MemberShockReaction) = {
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
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(GetLastEvent, ACTOR_SELF, LVarF)
    Switch(LVarF)
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            Call(SetActorVar, ACTOR_SELF, AVAR_HasBeenAttacked, 1)
            SetConst(LVar1, ANIM_ShySquadGuy_Anim0D)
            ExecWait(N(EVS_ReduceCrowdSize))
            SetConst(LVar1, ANIM_ShySquadGuy_Anim0D)
            ExecWait(N(EVS_HitReaction))
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar1, ANIM_ShySquadGuy_Anim0D)
            ExecWait(N(EVS_ReduceCrowdSize))
            SetConst(LVar1, ANIM_ShySquadGuy_Anim0D)
            ExecWait(N(EVS_HitReaction))
            Wait(10)
            SetConst(LVar1, ANIM_ShySquadGuy_Anim0D)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_BURN_HIT)
            Call(SetActorVar, ACTOR_SELF, AVAR_HasBeenAttacked, 1)
            SetConst(LVar1, ANIM_ShySquadGuy_Anim0E)
            ExecWait(N(EVS_ReduceCrowdSize))
            LOOP_MEMBERS(LVar0)
                Call(SetAnimation, ACTOR_SELF, LVar0, ANIM_ShySquadGuy_Anim0E)
                Add(LVar0, 1)
            EndLoop
            Wait(20)
            LOOP_MEMBERS(LVar0)
                Call(SetAnimation, ACTOR_SELF, LVar0, ANIM_ShySquadGuy_Anim0F)
                Add(LVar0, 1)
            EndLoop
            Wait(15)
        CaseEq(EVENT_BURN_DEATH)
            Call(SetActorVar, ACTOR_SELF, AVAR_HasBeenAttacked, 1)
            SetConst(LVar1, ANIM_ShySquadGuy_Anim0E)
            ExecWait(N(EVS_ReduceCrowdSize))
            LOOP_MEMBERS(LVar0)
                Call(SetAnimation, ACTOR_SELF, LVar0, ANIM_ShySquadGuy_Anim0E)
                Add(LVar0, 1)
            EndLoop
            Wait(20)
            LOOP_MEMBERS(LVar0)
                Call(SetAnimation, ACTOR_SELF, LVar0, ANIM_ShySquadGuy_Anim0F)
                Add(LVar0, 1)
            EndLoop
            Wait(15)
            Wait(10)
            SetConst(LVar1, ANIM_ShySquadGuy_Anim0F)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            Call(SetActorVar, ACTOR_SELF, AVAR_HasBeenAttacked, 1)
            SetConst(LVar1, ANIM_ShySquadGuy_Anim0D)
            ExecWait(N(EVS_ReduceCrowdSize))
            SetConst(LVar1, ANIM_ShySquadGuy_Anim0D)
            ExecWait(N(EVS_HitReaction))
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar1, ANIM_ShySquadGuy_Anim0D)
            ExecWait(N(EVS_ReduceCrowdSize))
            SetConst(LVar1, ANIM_ShySquadGuy_Anim0D)
            ExecWait(N(EVS_HitReaction))
            SetConst(LVar1, ANIM_ShySquadGuy_Anim0D)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar1, ANIM_ShySquadGuy_Anim0D)
            ExecWait(N(EVS_ReduceCrowdSize))
            SetConst(LVar1, ANIM_ShySquadGuy_Anim0D)
            ExecWait(N(EVS_Shock))
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetActorYaw, ACTOR_SELF, 180)
            Set(LVar1, ANIM_ShySquadGuy_Anim03)
            ExecWait(N(EVS_MoveSquadHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar1, ANIM_ShySquadGuy_Anim0D)
            ExecWait(N(EVS_ReduceCrowdSize))
            SetConst(LVar1, ANIM_ShySquadGuy_Anim0D)
            ExecWait(N(EVS_Shock))
            SetConst(LVar1, ANIM_ShySquadGuy_Anim0D)
            ExecWait(N(EVS_Death))
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_SPIKE_TAUNT)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            Call(GetBattleFlags, LVar2)
            IfFlag(LVar2, BS_FLAGS1_PARTNER_ACTING)
                Call(GetMenuSelection, LVar0, LVar1, LVar2)
                IfEq(LVar2, MOVE_SPOOK)
                    Set(LVar1, ANIM_ShySquadGuy_Anim01)
                    ExecWait(N(EVS_SetMembersAnimation))
                    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
                    Return
                EndIf
            EndIf
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShySquadGuy_Anim01)
            ExecWait(N(EVS_HitReaction))
        EndCaseGroup
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            Set(LVar1, ANIM_ShySquadGuy_Anim08)
            ExecWait(N(EVS_SetMembersAnimation))
            Wait(1000)
        CaseEq(EVENT_END_FIRST_STRIKE)
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetActorYaw, ACTOR_SELF, 180)
            Set(LVar1, ANIM_ShySquadGuy_Anim03)
            ExecWait(N(EVS_MoveSquadHome))
            Call(HPBarToHome, ACTOR_SELF)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShySquadGuy_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_30)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_ShySquadGuy_Anim0D)
            ExecWait(EVS_Enemy_Hit)
            Wait(1000)
        CaseEq(EVENT_SCARE_AWAY)
        CaseDefault
    EndSwitch
    Set(LVar1, ANIM_ShySquadGuy_Anim01)
    ExecWait(N(EVS_SetMembersAnimation))
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
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
            ExecWait(N(EVS_UpdateActorSize))
            Return
        EndIf
        Call(GetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVar1)
        IfGe(LVar1, 15)
            ExecWait(N(EVS_UpdateActorSize))
            Return
        EndIf
        Set(LVar0, PRT_MEMBER_01)
        Add(LVar0, LVar1)
        IfNe(LVar0, NUM_MEMBERS + 1)
            Thread
                Call(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_NO_STATUS_ANIMS, TRUE)
                Call(GetPartOffset, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3)
                Call(GetPartMovementVar, ACTOR_SELF, LVar0, HIT_OFFSET_X, LVar7)
                Call(GetPartMovementVar, ACTOR_SELF, LVar0, HIT_OFFSET_Z, LVar8)
                Add(LVar1, LVar7)
                Add(LVar3, LVar8)
                Call(SetPartJumpGravity, ACTOR_SELF, LVar0, Float(0.5))
                Call(JumpPartTo, ACTOR_SELF, LVar0, LVar1, 0, LVar3, 15, TRUE)
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
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_DEATH)
                PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar1, LVar2, LVar3, 0, 0, 0, 0, 0)
                Set(LVar8, 0)
                Loop(12)
                    Call(SetPartRotation, ACTOR_SELF, LVar0, LVar8, 0, 0)
                    Add(LVar8, 8)
                    Wait(1)
                EndLoop
                Call(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, TRUE)
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
    Call(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(RemovePartShadow, ACTOR_SELF, LVar0)
    Return
    End
};

EvtScript N(EVS_Death) = {
    SetConst(LVar0, PRT_MEMBER_01)
    Loop(NUM_MEMBERS - 1)
        Call(GetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVar2)
        Call(GetActorVar, ACTOR_SELF, AVAR_NumPendingDefeat, LVar3)
        Add(LVar2, PRT_MEMBER_01)
        Add(LVar2, LVar3)
        IfGe(LVar0, LVar2)
            Thread
                ExecWait(N(EVS_DefeatMember))
            EndThread
        EndIf
        Add(LVar0, 1)
    EndLoop
    Set(LVar0, PRT_MEMBER_15)
    Call(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    Set(LVar2, 0)
    Loop(24)
        Call(SetPartRotation, ACTOR_SELF, LVar0, 0, LVar2, 0)
        Add(LVar2, 30)
        Wait(1)
    EndLoop
    Call(GetPartOffset, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3)
    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar1, LVar2, LVar3, 0, 0, 0, 0, 0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_DEATH)
    Call(DropStarPoints, ACTOR_SELF)
    Set(LVar3, 0)
    Loop(12)
        Call(SetPartRotation, ACTOR_SELF, LVar0, LVar3, 0, 0)
        Add(LVar3, 8)
        Wait(1)
    EndLoop
    Call(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(RemovePartShadow, ACTOR_SELF, LVar0)
    ExecWait(N(EVS_NotifyNextWave))
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_Attack_Swarm) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamDist, 350)
    Call(SetBattleCamOffsetY, 34)
    Call(MoveBattleCamOver, 50)
    Set(LVar0, 15)
    Call(GetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVar1)
    Sub(LVar0, LVar1)
    Switch(LVar0)
        CaseEq(1)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
        CaseLt(5)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SMALL_CROWD_WALK)
        CaseDefault
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LARGE_CROWD_WALK)
    EndSwitch
    Set(LVar0, PRT_MEMBER_01)
    Set(LVar1, ANIM_ShySquadGuy_Anim03)
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
    Call(GetPartMovementVar, ACTOR_SELF, PRT_MEMBER_15, SWARM_OFFSET_X, LVar5)
    Add(LVar2, LVar5)
    Call(GetPartMovementVar, ACTOR_SELF, PRT_MEMBER_15, SWARM_OFFSET_Z, LVar5)
    Add(LVar3, LVar5)
    Call(SetGoalPos, ACTOR_SELF, LVar2, 0, LVar3)
    Call(RunToGoal, ACTOR_SELF, 30, TRUE)
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
            Set(LVar7, ANIM_ShySquadGuy_Anim0D)
        Else
            Set(LVar7, ANIM_ShySquadGuy_Anim11)
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
            Set(LVar0, 15)
            Call(GetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVar1)
            Sub(LVar0, LVar1)
            Switch(LVar0)
                CaseEq(1)
                    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
                    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
                CaseLt(5)
                    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SMALL_CROWD_WALK)
                CaseDefault
                    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LARGE_CROWD_WALK)
            EndSwitch
            Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
            Call(SetActorYaw, ACTOR_SELF, 180)
            Set(LVar1, ANIM_ShySquadGuy_Anim04)
            ExecWait(N(EVS_MoveSquadHome))
            Set(LVar1, ANIM_ShySquadGuy_Anim01)
            ExecWait(N(EVS_SetMembersAnimation))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
        CaseEq(HIT_RESULT_HIT_STATIC)
            Call(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, DMG_SWARM, BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Set(LVarE, 15)
    Call(GetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVar0)
    Sub(LVarE, LVar0)
    Set(LVarD, LVarE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LRAW_FIGHTING)
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
    Call(StopSound, SOUND_LRAW_FIGHTING)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Wait(20)
    Set(LVar0, 15)
    Call(GetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVar1)
    Sub(LVar0, LVar1)
    Switch(LVar0)
        CaseEq(1)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
        CaseLt(5)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SMALL_CROWD_WALK)
        CaseDefault
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LARGE_CROWD_WALK)
    EndSwitch
    Set(LVar1, ANIM_ShySquadGuy_Anim04)
    ExecWait(N(EVS_MoveSquadHome))
    Set(LVar1, ANIM_ShySquadGuy_Anim01)
    ExecWait(N(EVS_SetMembersAnimation))
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    ExecWait(N(EVS_Attack_Swarm))
    Return
    End
};

EvtScript N(EVS_Flee) = {
    Call(EnableBattleStatusBar, FALSE)
    LOOP_MEMBERS(LVar0)
        Call(SetAnimation, ACTOR_SELF, LVar0, ANIM_ShySquadGuy_Anim08)
        Add(LVar0, 1)
    EndLoop
    Call(UseBattleCamPreset, BTL_CAM_ACTOR)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(MoveBattleCamOver, 30)
    Wait(30)
    Call(ActorSpeak, MSG_CH4_0066, ACTOR_SELF, PRT_MAIN, -1, -1)
    Call(HideHealthBar, ACTOR_SELF)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Set(LVar0, PRT_MEMBER_01)
    Set(LVar1, ANIM_ShySquadGuy_Anim08)
    Loop(NUM_MEMBERS - 1)
        Thread
            Call(RandInt, 100, LVar2)
            Add(LVar2, 190)
            Call(RandInt, 100, LVar3)
            Add(LVar3, -50)
            SetF(LVar4, Float(6.0))
            Set(LVar5, 0)
            ExecWait(N(EVS_MoveMemberToPos))
        EndThread
        Add(LVar0, 1)
    EndLoop
    Thread
        Set(LVar0, PRT_MEMBER_15)
        Set(LVar1, ANIM_ShySquadGuy_Anim08)
        Set(LVar2, 240)
        Set(LVar3, 0)
        SetF(LVar4, Float(6.0))
        Set(LVar5, 0)
        ExecWait(N(EVS_MoveMemberToPos))
    EndThread
    Set(LVar0, 15)
    Call(GetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVar1)
    Sub(LVar0, LVar1)
    Switch(LVar0)
        CaseEq(1)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
            Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
        CaseLt(4)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SHY_GUY_SCREAMS3)
        CaseDefault
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_SHY_GUY_SCREAMS2)
    EndSwitch
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetActorYaw, ACTOR_SELF, 180)
    Call(SetGoalPos, ACTOR_SELF, 240, 0, 0)
    Call(RunToGoal, ACTOR_SELF, 0, TRUE)
    Wait(30)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_DISTANT_THUD)
    Call(ShakeCam, CAM_BATTLE, 0, 6, Float(2.5))
    Call(GetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVar0)
    IfLt(LVar0, 14)
        Call(ActorSpeak, MSG_CH4_0067, ACTOR_GENERAL, PRT_MAIN, -1, -1)
    Else
        Call(ActorSpeak, MSG_CH4_0068, ACTOR_GENERAL, PRT_MAIN, -1, -1)
    EndIf
    Thread
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_DISTANT_THUD)
        Call(ShakeCam, CAM_BATTLE, 0, 4, Float(2.0))
        Wait(12)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_DISTANT_THUD)
        Call(ShakeCam, CAM_BATTLE, 0, 4, Float(2.0))
    EndThread
    Call(EndActorSpeech, ACTOR_GENERAL, PRT_MAIN, -1, -1)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Wait(40)
    Thread
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_RUN_AWAY_BUILDUP)
        Wait(20)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_RUN_AWAY)
    EndThread
    Set(LVar0, PRT_MEMBER_01)
    Set(LVar1, ANIM_ShySquadGuy_Anim08)
    Loop(NUM_MEMBERS - 1)
        Thread
            Call(RandInt, 100, LVar2)
            Add(LVar2, -290)
            Call(RandInt, 100, LVar3)
            Add(LVar3, -50)
            SetF(LVar4, Float(10.0))
            ExecWait(N(EVS_MoveMemberToPos))
        EndThread
        Add(LVar0, 1)
    EndLoop
    Thread
        Label(0)
            Wait(1)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            IfGt(LVar0, 30)
                Goto(0)
            EndIf
        Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Flail)
        Label(1)
            Wait(1)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(GetActorPos, ACTOR_PLAYER, LVar3, LVar4, LVar5)
            Add(LVar3, 10)
            IfGt(LVar0, LVar3)
                Goto(1)
            EndIf
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Flail)
        Set(LVar7, 0)
        Loop(40)
            Add(LVar7, 36)
            IfGe(LVar7, 360)
                Sub(LVar7, 360)
            EndIf
            Call(SetActorRotation, ACTOR_PLAYER, 0, LVar7, 0)
            Wait(1)
        EndLoop
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        Call(SetActorRotation, ACTOR_PLAYER, 0, 0, 0)
        Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EndThread
    Thread
        Set(LVar0, PRT_MEMBER_15)
        Set(LVar1, ANIM_ShySquadGuy_Anim08)
        Set(LVar2, -240)
        Set(LVar3, 0)
        SetF(LVar4, Float(10.0))
        Set(LVar5, 0)
        ExecWait(N(EVS_MoveMemberToPos))
    EndThread
    Call(SetActorSpeed, ACTOR_SELF, Float(10.0))
    Call(SetActorYaw, ACTOR_SELF, 0)
    Call(SetGoalPos, ACTOR_SELF, -240, 0, 0)
    Call(RunToGoal, ACTOR_SELF, 0, TRUE)
    ExecWait(N(EVS_NotifyNextWave))
    Wait(10)
    Call(EnableBattleStatusBar, TRUE)
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_NotifyNextWave) = {
    Call(FreezeBattleState, TRUE)
    Call(SetActorVar, ACTOR_TANK, AVAR_Tank_SquadPhase, AVAL_SquadPhase_Defeated)
    Return
    End
};

EvtScript N(EVS_UpdateActorSize) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_NumDefeated, LVar0)
    Switch(LVar0)
        CaseLe(1)
            Call(SetActorSize, ACTOR_SELF, EVT_IGNORE_ARG, 72)
        CaseLe(2)
            Call(SetActorSize, ACTOR_SELF, EVT_IGNORE_ARG, 48)
        CaseLe(8)
            Call(SetActorSize, ACTOR_SELF, EVT_IGNORE_ARG, 24)
        CaseDefault
            Call(SetActorSize, ACTOR_SELF, EVT_IGNORE_ARG, EVT_IGNORE_ARG)
    EndSwitch
    Return
    End
};
