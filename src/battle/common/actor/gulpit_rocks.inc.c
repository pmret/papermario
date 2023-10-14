#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/Gulpit.h"

#define NAMESPACE A(gulpit_rocks)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_RockType   = 0,
};

s32 N(BigRockAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Gulpit_Anim10,
    STATUS_END,
};

s32 N(SmallRockAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Gulpit_Anim12,
    STATUS_END,
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
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 14 },
        .opacity = 255,
        .idleAnimations = N(BigRockAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -6 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_TARGET_ONLY | ACTOR_FLAG_NO_HEALTH_BAR | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_GULPIT_ROCKS,
    .level = ACTOR_LEVEL_GULPIT_ROCKS,
    .maxHP = 1,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 100,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 0,
    .size = { 32, 18 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_RockType, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(BigRockAnims)))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim10)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_RockType, 0)
            EVT_CALL(SetActorSize, ACTOR_SELF, 24, 15)
        EVT_CASE_EQ(1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(SmallRockAnims)))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim12)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_RockType, 1)
            EVT_CALL(SetActorSize, ACTOR_SELF, 10, 8)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SelectRockAnim) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_RockType, LVarA)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
        EVT_CASE_EQ(1)
            EVT_SET_CONST(LVar1, LVar2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim10)
            EVT_SET_CONST(LVar2, ANIM_Gulpit_Anim12)
            EVT_EXEC_WAIT(N(EVS_SelectRockAnim))
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_BEGIN_AIR_LIFT)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim10)
            EVT_SET_CONST(LVar2, ANIM_Gulpit_Anim12)
            EVT_EXEC_WAIT(N(EVS_SelectRockAnim))
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
        EVT_CASE_OR_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Gulpit_Anim10)
            EVT_SET_CONST(LVar2, ANIM_Gulpit_Anim12)
            EVT_EXEC_WAIT(N(EVS_SelectRockAnim))
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_RockType, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim11)
                EVT_CASE_EQ(1)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Gulpit_Anim13)
            EVT_END_SWITCH
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 1, LVar0, LVar1, LVar2, 0, 0)
            EVT_WAIT(30)
            EVT_CALL(RemoveActor, ACTOR_SELF)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_RETURN
    EVT_END
};

