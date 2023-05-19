#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/PetitPiranha.h"

#define NAMESPACE b_area_kzn2_petit_piranha_bomb

extern EvtScript N(init);
extern EvtScript N(idle);
extern EvtScript N(takeTurn);
extern EvtScript N(handleEvent);

s32 N(IdleAnimations)[] = {
    STATUS_KEY_NORMAL, ANIM_PetitPiranha_Anim01,
    STATUS_KEY_STONE, ANIM_PetitPiranha_Anim00,
    STATUS_KEY_SLEEP, ANIM_PetitPiranha_Anim00,
    STATUS_KEY_POISON, ANIM_PetitPiranha_Anim01,
    STATUS_KEY_STOP, ANIM_PetitPiranha_Anim00,
    STATUS_KEY_STATIC, ANIM_PetitPiranha_Anim00,
    STATUS_KEY_PARALYZE, ANIM_PetitPiranha_Anim00,
    STATUS_KEY_PARALYZE, ANIM_PetitPiranha_Anim00,
    STATUS_KEY_DIZZY, ANIM_PetitPiranha_Anim01,
    STATUS_KEY_DIZZY, ANIM_PetitPiranha_Anim01,
    STATUS_TABLE_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_WATER, -2,
    ELEMENT_ICE, -2,
    ELEMENT_FIRE, 99,
    ELEMENT_BLAST, 0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL, 0,
    STATUS_KEY_DEFAULT, 0,
    STATUS_KEY_SLEEP, 0,
    STATUS_KEY_POISON, 0,
    STATUS_KEY_FROZEN, 0,
    STATUS_KEY_DIZZY, 0,
    STATUS_KEY_FEAR, 0,
    STATUS_KEY_STATIC, 0,
    STATUS_KEY_PARALYZE, 0,
    STATUS_KEY_SHRINK, 0,
    STATUS_KEY_STOP, 0,
    STATUS_TURN_MOD_DEFAULT, 0,
    STATUS_TURN_MOD_SLEEP, 0,
    STATUS_TURN_MOD_POISON, 0,
    STATUS_TURN_MOD_FROZEN, 0,
    STATUS_TURN_MOD_DIZZY, 0,
    STATUS_TURN_MOD_FEAR, 0,
    STATUS_TURN_MOD_STATIC, 0,
    STATUS_TURN_MOD_PARALYZE, 0,
    STATUS_TURN_MOD_SHRINK, 0,
    STATUS_TURN_MOD_STOP, 0,
    STATUS_TABLE_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_FIREY,
        .elementImmunityFlags = ELEMENT_FIRE,
        .projectileTargetOffset = { -2, -22 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_PETIT_PIRANHA_BOMB,
    .level = 0,
    .maxHP = 1,
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
    .size = { 30, 30 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
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
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};
