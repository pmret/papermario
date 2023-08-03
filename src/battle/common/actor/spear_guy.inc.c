#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/ShyGuy.h"
#include "sprite/npc/SpearGuy.h"

#define NAMESPACE A(spear_guy)

extern s32 N(IdleAnimations_8021BF40)[];
extern EvtScript N(init_80218980);
extern EvtScript N(takeTurn_8021BCB4);
extern EvtScript N(handleEvent_80218E3C);
extern EvtScript N(nextTurn_80218B24);
extern EvtScript N(idle_80218BE0);
extern EvtScript N(takeTurn_8021D8D8);
extern EvtScript N(idle_8021BFD8);
extern EvtScript N(handleEvent_8021C14C);
extern EvtScript N(8021BF8C);
extern Formation N(specialFormation_8021A8C0);
extern Formation N(specialFormation_8021A8DC);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_2               = 2,
    PRT_3               = 3,
    PRT_4               = 4,
};

s32 N(IdleAnimations_802185C0)[] = {
    STATUS_KEY_NORMAL,    ANIM_SpearGuy_Anim04,
    STATUS_KEY_STONE,     ANIM_SpearGuy_Anim02,
    STATUS_KEY_SLEEP,     ANIM_SpearGuy_Anim0D,
    STATUS_KEY_POISON,    ANIM_SpearGuy_Anim0F,
    STATUS_KEY_STOP,      ANIM_SpearGuy_Anim02,
    STATUS_KEY_STATIC,    ANIM_SpearGuy_Anim04,
    STATUS_KEY_PARALYZE,  ANIM_SpearGuy_Anim02,
    STATUS_KEY_DIZZY,     ANIM_SpearGuy_Anim0F,
    STATUS_KEY_FEAR,      ANIM_SpearGuy_Anim0F,
    STATUS_END,
};

s32 N(IdleAnimations_8021860C)[] = {
    STATUS_KEY_NORMAL,    ANIM_SpearGuy_Anim03,
    STATUS_KEY_STONE,     ANIM_SpearGuy_Anim0D,
    STATUS_KEY_SLEEP,     ANIM_SpearGuy_Anim0D,
    STATUS_KEY_POISON,    ANIM_SpearGuy_Anim0F,
    STATUS_KEY_STOP,      ANIM_SpearGuy_Anim01,
    STATUS_KEY_STATIC,    ANIM_SpearGuy_Anim03,
    STATUS_KEY_PARALYZE,  ANIM_SpearGuy_Anim01,
    STATUS_KEY_DIZZY,     ANIM_SpearGuy_Anim0F,
    STATUS_KEY_FEAR,      ANIM_SpearGuy_Anim0F,
    STATUS_END,
};

s32 N(IdleAnimations_80218658)[] = {
    STATUS_KEY_NORMAL,    ANIM_SpearGuy_Anim14,
    STATUS_END,
};

s32 N(IdleAnimations_80218664)[] = {
    STATUS_KEY_NORMAL,    ANIM_SpearGuy_Anim19,
    STATUS_END,
};

s32 N(DefenseTable_80218670)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_FIRE,     0,
    ELEMENT_END,
};

s32 N(DefenseTable_80218684)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_SHOCK,    0,
    ELEMENT_END,
};

s32 N(StatusTable_80218698)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              70,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

s32 N(StatusTable_80218744)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              70,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PRT_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 22 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_802185C0),
        .defenseTable = N(DefenseTable_80218670),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_FRONT,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -3, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8021BF40),
        .defenseTable = N(DefenseTable_80218684),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80218658),
        .defenseTable = N(DefenseTable_80218684),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80218664),
        .defenseTable = N(DefenseTable_80218684),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_SPEAR_GUY,
    .level = 16,
    .maxHP = 7,
    .partCount = ARRAY_COUNT( N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(init_80218980),
    .statusTable = N(StatusTable_80218698),
    .escapeChance = 50,
    .airLiftChance = 85,
    .hurricaneChance = 80,
    .spookChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 85,
    .coinReward = 2,
    .size = { 24, 24 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(setSpearStance) = {
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(2)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_2, EVT_PTR(N(IdleAnimations_802185C0)))
            EVT_CALL(SetPartEventFlags, ACTOR_SELF, PRT_2, ACTOR_EVENT_FLAG_SPIKY_FRONT)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_2, EVT_PTR(N(IdleAnimations_8021860C)))
            EVT_CALL(SetPartEventFlags, ACTOR_SELF, PRT_2, ACTOR_EVENT_FLAG_SPIKY_TOP)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80218980) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(setSpearStance))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim04)
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(setSpearStance))
            EVT_CALL(SetPartEventFlags, ACTOR_SELF, PRT_2, ACTOR_EVENT_FLAG_SPIKY_TOP)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim03)
    EVT_END_SWITCH
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8021BCB4)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80218E3C)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn_80218B24)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(GetEncounterTrigger, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ENCOUNTER_TRIGGER_JUMP)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_HAMMER)
        EVT_CASE_OR_EQ(ENCOUNTER_TRIGGER_PARTNER)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_2, ACTOR_EVENT_FLAG_SPIKY_FRONT, FALSE)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_2, EVT_PTR(N(IdleAnimations_8021860C)))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim03)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_80218B24) = {
    EVT_CALL(BindNextTurn, ACTOR_SELF, 0)
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_80218BE0)))
    EVT_RETURN
    EVT_END
};

EvtScript N(80218B5C) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarB)
        EVT_IF_FLAG(LVarB, STATUS_FLAG_SLEEP | STATUS_FLAG_FEAR | STATUS_FLAG_DIZZY)
        EVT_ELSE
            EVT_SET(LVar1, LVar2)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80218BE0) = {
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FEAR | STATUS_FLAG_DIZZY)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_2, EVT_PTR(N(IdleAnimations_8021860C)))
                EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_2, ACTOR_EVENT_FLAG_SPIKY_TOP, TRUE)
                EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_2, ACTOR_EVENT_FLAG_SPIKY_FRONT, FALSE)
            EVT_ELSE
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_2, EVT_PTR(N(IdleAnimations_802185C0)))
                EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_2, ACTOR_EVENT_FLAG_SPIKY_TOP, FALSE)
                EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_2, ACTOR_EVENT_FLAG_SPIKY_FRONT, TRUE)
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_2, EVT_PTR(N(IdleAnimations_8021860C)))
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_2, ACTOR_EVENT_FLAG_SPIKY_TOP, TRUE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_2, ACTOR_EVENT_FLAG_SPIKY_FRONT, FALSE)
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80218D7C) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_SET_CONST(LVar0, PRT_2)
    EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim06)
    EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim04)
        EVT_CASE_EQ(1)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim03)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80218E3C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim07)
            EVT_SET_CONST(LVar2, ANIM_SpearGuy_Anim08)
            EVT_EXEC_WAIT(N(80218B5C))
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarB)
                EVT_IF_FLAG(LVarB, STATUS_FLAG_SLEEP | STATUS_FLAG_FEAR | STATUS_FLAG_DIZZY)
                    EVT_SET_CONST(LVar0, PRT_2)
                    EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim0A)
                    EVT_SET_CONST(LVar2, ANIM_SpearGuy_Anim0C)
                EVT_ELSE
                    EVT_SET_CONST(LVar0, PRT_2)
                    EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim0B)
                    EVT_SET_CONST(LVar2, -1)
                EVT_END_IF
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_2)
                EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim0A)
                EVT_SET_CONST(LVar2, ANIM_SpearGuy_Anim0C)
            EVT_END_IF
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarB)
                EVT_IF_FLAG(LVarB, STATUS_FLAG_SLEEP | STATUS_FLAG_FEAR | STATUS_FLAG_DIZZY)
                    EVT_SET_CONST(LVar0, PRT_2)
                    EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim0A)
                    EVT_SET_CONST(LVar2, ANIM_SpearGuy_Anim0C)
                    EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                    EVT_SET_CONST(LVar0, PRT_2)
                    EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim0C)
                    EVT_EXEC_WAIT(EVS_Enemy_Death)
                EVT_ELSE
                    EVT_SET_CONST(LVar0, PRT_2)
                    EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim0B)
                    EVT_SET_CONST(LVar2, -1)
                    EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                    EVT_SET_CONST(LVar0, PRT_2)
                    EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim0B)
                    EVT_EXEC_WAIT(EVS_Enemy_Death)
                EVT_END_IF
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_2)
                EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim0A)
                EVT_SET_CONST(LVar2, ANIM_SpearGuy_Anim0C)
                EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
                EVT_SET_CONST(LVar0, PRT_2)
                EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim0C)
                EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim07)
            EVT_SET_CONST(LVar2, ANIM_SpearGuy_Anim08)
            EVT_EXEC_WAIT(N(80218B5C))
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim07)
            EVT_SET_CONST(LVar2, ANIM_SpearGuy_Anim08)
            EVT_EXEC_WAIT(N(80218B5C))
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim09)
            EVT_SET_CONST(LVar2, ANIM_SpearGuy_Anim08)
            EVT_EXEC_WAIT(N(80218B5C))
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim07)
            EVT_SET_CONST(LVar2, ANIM_SpearGuy_Anim08)
            EVT_EXEC_WAIT(N(80218B5C))
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim07)
            EVT_SET_CONST(LVar2, ANIM_SpearGuy_Anim08)
            EVT_EXEC_WAIT(N(80218B5C))
            EVT_EXEC_WAIT(EVS_Enemy_JumpBack)
            EVT_EXEC_WAIT(N(80218D7C))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim09)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim03)
            EVT_SET_CONST(LVar2, ANIM_SpearGuy_Anim04)
            EVT_EXEC_WAIT(N(80218B5C))
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim07)
            EVT_SET_CONST(LVar2, ANIM_SpearGuy_Anim08)
            EVT_EXEC_WAIT(N(80218B5C))
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim09)
            EVT_SET_CONST(LVar2, ANIM_SpearGuy_Anim08)
            EVT_EXEC_WAIT(N(80218B5C))
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_SET_CONST(LVar0, PRT_2)
                    EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim04)
                    EVT_EXEC_WAIT(EVS_Enemy_Recover)
                EVT_CASE_EQ(1)
                    EVT_SET_CONST(LVar0, PRT_2)
                    EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim03)
                    EVT_EXEC_WAIT(EVS_Enemy_Recover)
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim06)
            EVT_SET_CONST(LVar2, ANIM_SpearGuy_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_SpearGuy_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_WAIT(10)
            EVT_SET(LFlag0, FALSE)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
            EVT_SWITCH(LVarA)
                EVT_CASE_EQ(0)
                    EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                        EVT_ADD(LVar0, -11)
                        EVT_ADD(LVar1, 3)
                        EVT_SET(LFlag0, TRUE)
                    EVT_END_IF
                    EVT_IF_FLAG(LVar3, STATUS_FLAG_DIZZY)
                        EVT_ADD(LVar0, -4)
                        EVT_ADD(LVar1, 36)
                        EVT_SET(LFlag0, TRUE)
                    EVT_END_IF
                    EVT_IF_FLAG(LVar3, STATUS_FLAG_SLEEP)
                        EVT_ADD(LVar0, -8)
                        EVT_ADD(LVar1, 36)
                        EVT_SET(LFlag0, TRUE)
                    EVT_END_IF
                    EVT_IF_EQ(LFlag0, FALSE)
                        EVT_ADD(LVar0, -28)
                        EVT_ADD(LVar1, 8)
                    EVT_END_IF
                EVT_CASE_EQ(1)
                    EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                        EVT_ADD(LVar0, -4)
                        EVT_ADD(LVar1, 15)
                        EVT_SET(LFlag0, TRUE)
                    EVT_END_IF
                    EVT_IF_FLAG(LVar3, STATUS_FLAG_DIZZY)
                        EVT_ADD(LVar0, -4)
                        EVT_ADD(LVar1, 36)
                        EVT_SET(LFlag0, TRUE)
                    EVT_END_IF
                    EVT_IF_FLAG(LVar3, STATUS_FLAG_SLEEP)
                        EVT_ADD(LVar0, -8)
                        EVT_ADD(LVar1, 36)
                        EVT_SET(LFlag0, TRUE)
                    EVT_END_IF
                    EVT_IF_EQ(LFlag0, FALSE)
                        EVT_ADD(LVar0, -10)
                        EVT_ADD(LVar1, 38)
                    EVT_END_IF
            EVT_END_SWITCH
            EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 20, 0)
            EVT_WAIT(20)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(spearStab) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim06)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar0, 10)
    EVT_ELSE
        EVT_ADD(LVar0, 25)
    EVT_END_IF
    EVT_SET(LVar1, 0)
    EVT_ADD(LVar2, 1)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim04)
    EVT_WAIT(5)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim1A)
    EVT_WAIT(15)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_309)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim1B)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_2, 0, ACTOR_DECORATION_SWEAT)
            EVT_EXEC_WAIT(N(80218D7C))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_2, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_309)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim1B)
    EVT_WAIT(5)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_WAIT(20)
            EVT_EXEC_WAIT(N(80218D7C))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(summonBackup) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_01)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim05)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2FA)
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2FB)
    EVT_END_THREAD
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 10)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim05)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim10)
    EVT_WAIT(25)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2FA)
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2FB)
    EVT_END_THREAD
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim05)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim10)
    EVT_WAIT(30)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 10)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim05)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 30, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_206D)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim0E)
    EVT_WAIT(20)
    EVT_CALL(GetOriginalActorType, ACTOR_SELF, LVar0)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_4 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar1, LVar2)
    EVT_CALL(GetOriginalActorType, LVar1, LVar2)
    EVT_IF_EQ(LVar0, LVar2)
        EVT_CALL(SetAnimation, LVar1, 2, ANIM_SpearGuy_Anim04)
        EVT_CALL(GetIndexFromHome, LVar1, LVar3)
        EVT_IF_LT(LVarA, LVar3)
            EVT_CALL(GetActorVar, LVar1, 0, LVar4)
            EVT_IF_EQ(LVar4, 0)
                EVT_CALL(SetActorVar, LVar1, 0, 1)
                EVT_CALL(SetIdleAnimations, LVar1, 2, EVT_PTR(N(IdleAnimations_8021860C)))
                EVT_CALL(SetPartEventFlags, LVar1, 2, 16)
                EVT_CALL(SetAnimation, LVar1, 2, ANIM_SpearGuy_Anim03)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar1)
    EVT_IF_NE(LVar1, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_SET(LFlag0, FALSE)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_4 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(1)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetIndexFromHome, LVar0, LVar1)
    EVT_IF_LT(LVar1, LVarA)
        EVT_SET(LFlag0, TRUE)
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_CALL(SummonEnemy, EVT_PTR(N(specialFormation_8021A8C0)), FALSE)
    EVT_ELSE
        EVT_CALL(SummonEnemy, EVT_PTR(N(specialFormation_8021A8DC)), FALSE)
    EVT_END_IF
    EVT_SET(LVarB, LVar0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(SetAnimation, LVarB, 2, ANIM_SpearGuy_Anim10)
    EVT_CALL(SetGoalToIndex, LVarB, LVarA)
    EVT_CALL(GetGoalPos, LVarB, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 220)
    EVT_CALL(SetActorPos, LVarB, LVar0, 0, 0)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2FA)
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2FA)
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2FB)
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2FB)
        EVT_WAIT(15)
    EVT_END_THREAD
    EVT_CALL(SetActorSpeed, LVarB, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, LVarB, 0, FALSE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_206D)
    EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 30, 0)
    EVT_CALL(SetAnimation, LVarB, 2, ANIM_SpearGuy_Anim0E)
    EVT_WAIT(20)
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_CALL(SetAnimation, LVarB, 2, ANIM_SpearGuy_Anim04)
    EVT_ELSE
        EVT_CALL(SetAnimation, LVarB, 2, ANIM_SpearGuy_Anim03)
    EVT_END_IF
    EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, LVarB)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, LVarB, 1, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, LVarB, 1, 2)
    EVT_END_SWITCH
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 3)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

Vec3i N(vector3D_8021A8B4) = { NPC_DISPOSE_LOCATION };

Formation N(specialFormation_8021A8C0) = {
    ACTOR_BY_POS(NAMESPACE, N(vector3D_8021A8B4), 100, 0),
};

Formation N(specialFormation_8021A8DC) = {
    ACTOR_BY_POS(NAMESPACE, N(vector3D_8021A8B4), 100, 1),
};

EvtScript N(becomeShyGuy) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 2)
    EVT_WAIT(10)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim13)
    EVT_WAIT(5)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim18)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 10)
    EVT_ADD(LVar1, 15)
    EVT_SUB(LVar2, 1)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_4, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_4, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_4, EVT_FLOAT(0.5))
    EVT_ADD(LVar0, 50)
    EVT_SUB(LVar2, 30)
    EVT_THREAD
        EVT_LOOP(15)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_4, 0, 0, 10)
            EVT_WAIT(1)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_4, 0, 0, -10)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_206D)
    EVT_THREAD
        EVT_LOOP(10)
            EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_4, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 5, 0)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_4, SOUND_2FC)
    EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_4, ACTOR_SOUND_JUMP, 0, 0)
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_4, LVar0, 0, LVar2, 30, TRUE)
    EVT_WAIT(5)
    EVT_CALL(SetPartFlags, ACTOR_SELF, PRT_2, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET)
    EVT_CALL(SetPartFlags, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_MULTI_TARGET)
    EVT_CALL(SetPartFlags, ACTOR_SELF, PRT_3, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET)
    EVT_CALL(SetPartFlags, ACTOR_SELF, PRT_4, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET)
    EVT_EXEC_WAIT(N(8021BF8C))
    EVT_CALL(SetActorType, ACTOR_SELF, ACTOR_TYPE_SHY_GUY)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TYPE_CHANGED, TRUE)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable_80218744)))
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(spearThrow) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim06)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 200)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim15)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_SUB(LVar0, 100)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_SUB(LVar0, 70)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_3, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_4, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_3, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_4, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim11)
            EVT_WAIT(5)
            EVT_THREAD
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim17)
                EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_SUB(LVar0, 20)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                EVT_SUB(LVar0, 10)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim12)
            EVT_END_THREAD
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetPartPos, ACTOR_SELF, PRT_3, LVar0, 20, LVar2)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_3, 0, 0, -30)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_THREAD
                EVT_CALL(MakeLerp, -30, 45, 20, EASING_LINEAR)
                EVT_LABEL(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_3, 0, 0, LVar0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 1)
                    EVT_GOTO(0)
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_3, SOUND_30A)
            EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_3, ACTOR_SOUND_JUMP, 0, 0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_SET(LVar1, 10)
            EVT_ADD(LVar2, 2)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_3, EVT_FLOAT(0.7))
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_3, LVar0, LVar1, LVar2, 20, TRUE)
            EVT_WAIT(10)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_2, 0, ACTOR_DECORATION_SWEAT)
            EVT_WAIT(30)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_2, 0)
            EVT_WAIT(10)
            EVT_EXEC_WAIT(N(becomeShyGuy))
            EVT_CALL(YieldTurn)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim11)
    EVT_WAIT(5)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim17)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 20)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
        EVT_SUB(LVar0, 10)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_SpearGuy_Anim12)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_3, LVar0, 20, LVar2)
    EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_3, 0, 0, -30)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_THREAD
        EVT_CALL(MakeLerp, -30, 45, 20, EASING_LINEAR)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_3, 0, 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_3, SOUND_30A)
    EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_3, ACTOR_SOUND_JUMP, 0, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 2)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_3, EVT_FLOAT(0.7))
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_3, LVar0, LVar1, LVar2, 20, TRUE)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_WAIT(3)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_WAIT(20)
    EVT_EXEC_WAIT(N(becomeShyGuy))
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021B770) = {
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar5)
    EVT_CALL(GetIndexFromHome, LVar0, LVar5)
    EVT_MOD(LVar5, 4)
    EVT_SWITCH(LVar5)
        EVT_CASE_EQ(0)
            EVT_SET(LFlag1, TRUE)
        EVT_CASE_EQ(1)
            EVT_SET(LFlag2, TRUE)
        EVT_CASE_EQ(2)
            EVT_SET(LFlag3, TRUE)
        EVT_CASE_EQ(3)
            EVT_SET(LFlag4, TRUE)
    EVT_END_SWITCH
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LFlag1, FALSE)
        EVT_SET(LVarA, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LFlag2, FALSE)
        EVT_SET(LVarA, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LFlag3, FALSE)
        EVT_SET(LVarA, 2)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LFlag4, FALSE)
        EVT_SET(LVarA, 3)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVarA, -1)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021B96C) = {
    EVT_SET(LVar9, 0)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetOriginalActorType, LVar0, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(ACTOR_TYPE_JUNGLE_FUZZY)
            EVT_CALL(GetStatusFlags, LVar0, LVar3)
            EVT_IF_NOT_FLAG(LVar3, STATUS_FLAGS_IMMOBILIZED)
                EVT_CALL(GetActorVar, LVar0, 0, LVar3)
                EVT_IF_NE(LVar3, 2)
                    EVT_ADD(LVar9, 1)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(ACTOR_TYPE_SPEAR_GUY)
            EVT_CALL(GetStatusFlags, LVar0, LVar3)
            EVT_IF_NOT_FLAG(LVar3, STATUS_FLAGS_IMMOBILIZED)
                EVT_CALL(GetActorVar, LVar0, 1, LVar3)
                EVT_IF_LT(LVar3, 2)
                    EVT_ADD(LVar9, 1)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(8021BB18) = {
    EVT_CALL(GetIndexFromHome, ACTOR_SELF, LVarA)
    EVT_SET(LFlag0, FALSE)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_4 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetIndexFromHome, LVar0, LVar1)
    EVT_IF_LT(LVar1, LVarA)
        EVT_SET(LFlag0, TRUE)
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_SET(LVar0, 1)
            EVT_EXEC_WAIT(N(setSpearStance))
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_SET(LVar0, 0)
            EVT_EXEC_WAIT(N(setSpearStance))
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021BCB4) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_EXEC_WAIT(N(spearStab))
        EVT_EXEC_WAIT(N(8021BB18))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(1)
            EVT_EXEC_WAIT(N(8021B770))
            EVT_IF_EQ(LVarA, -1)
                EVT_EXEC_WAIT(N(spearStab))
                EVT_EXEC_WAIT(N(8021BB18))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(8021B96C))
            EVT_SWITCH(LVar9)
                EVT_CASE_EQ(1)
                    EVT_CALL(RandInt, 1000, LVar0)
                    EVT_IF_LT(LVar0, 300)
                        EVT_EXEC_WAIT(N(summonBackup))
                        EVT_RETURN
                    EVT_END_IF
                EVT_CASE_EQ(2)
                    EVT_CALL(RandInt, 1000, LVar0)
                    EVT_IF_LT(LVar0, 150)
                        EVT_EXEC_WAIT(N(summonBackup))
                        EVT_RETURN
                    EVT_END_IF
                EVT_CASE_EQ(3)
                    EVT_CALL(RandInt, 1000, LVar0)
                    EVT_IF_LT(LVar0, 100)
                        EVT_EXEC_WAIT(N(summonBackup))
                        EVT_RETURN
                    EVT_END_IF
            EVT_END_SWITCH
            EVT_EXEC_WAIT(N(spearStab))
            EVT_EXEC_WAIT(N(8021BB18))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(2)
            EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
            EVT_CALL(GetTargetListLength, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_EXEC_WAIT(N(spearThrow))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(spearStab))
            EVT_EXEC_WAIT(N(8021BB18))
        EVT_CASE_EQ(3)
            EVT_EXEC_WAIT(N(spearThrow))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(IdleAnimations_8021BF40)[] = {
    STATUS_KEY_NORMAL,    ANIM_ShyGuy_Red_Anim01,
    STATUS_KEY_STONE,     ANIM_ShyGuy_Red_Anim00,
    STATUS_KEY_SLEEP,     ANIM_ShyGuy_Red_Anim12,
    STATUS_KEY_POISON,    ANIM_ShyGuy_Red_Anim01,
    STATUS_KEY_STOP,      ANIM_ShyGuy_Red_Anim00,
    STATUS_KEY_STATIC,    ANIM_ShyGuy_Red_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_ShyGuy_Red_Anim00,
    STATUS_KEY_DIZZY,     ANIM_ShyGuy_Red_Anim13,
    STATUS_KEY_FEAR,      ANIM_ShyGuy_Red_Anim13,
    STATUS_END,
};

EvtScript N(8021BF8C) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8021D8D8)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8021BFD8)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021C14C)))
    EVT_RETURN
    EVT_END
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(idle_8021BFD8) = {
    EVT_LABEL(0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -4, 14)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
        EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 13, 10, 13)
    EVT_ELSE
        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 24)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -10)
        EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021C0E8) = {
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim03)
    EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim01)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021C14C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0D)
            EVT_SET_CONST(LVar2, ANIM_ShyGuy_Red_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0D)
            EVT_SET_CONST(LVar2, ANIM_ShyGuy_Red_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_JumpBack)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(8021C0E8))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim03)
            EVT_SET_CONST(LVar2, ANIM_ShyGuy_Red_Anim14)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021C628) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim03)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_2EF, 0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_20BA, SOUND_3B4)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim04)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim05)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim01)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2EF)
    EVT_END_THREAD
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_20BA, SOUND_3B4)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim04)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 10)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim05)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim01)
    EVT_WAIT(8)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_EXEC_WAIT(N(8021C0E8))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021CD50) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_234)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim09)
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim03)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 80)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_20BA, SOUND_3B4)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim04)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_SUB(LVar0, 40)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim09)
            EVT_THREAD
                EVT_WAIT(12)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim0A)
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 10)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 24, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim05)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 15)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim01)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim09)
    EVT_THREAD
        EVT_WAIT(9)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim0A)
    EVT_END_THREAD
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 15)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                EVT_SET(LVar3, 0)
                EVT_LOOP(20)
                    EVT_SUB(LVar3, 30)
                    EVT_IF_LT(LVar3, 0)
                        EVT_ADD(LVar3, 360)
                    EVT_END_IF
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar3)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_FLAG(LVar0, BS_FLAGS1_ATK_BLOCKED)
                EVT_GOTO(1)
            EVT_END_IF
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_GOTO(1)
            EVT_END_IF
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_349)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_349 | SOUND_ID_TRIGGER_CHANGE_SOUND)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim09)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim07)
            EVT_WAIT(15)
            EVT_GOTO(2)
            EVT_LABEL(1)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E4)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim10)
            EVT_WAIT(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20C3)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LT(LVar0, 50)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim11)
            EVT_ELSE
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim13)
            EVT_END_IF
            EVT_WAIT(25)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_LABEL(2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Red_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_ShyGuy_Red_Anim01)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021D8D8) = {
    EVT_CALL(RandInt, 1, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_EXEC_WAIT(N(8021C628))
    EVT_ELSE
        EVT_EXEC_WAIT(N(8021CD50))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
