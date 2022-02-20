#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/shy_guy.h"
#include "sprite/npc/jungle_guy.h"

#define NAMESPACE b_area_jan_spear_guy

extern s32 N(idleAnimations_8021BF40)[];
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

s32 N(idleAnimations_802185C0)[] = {
    STATUS_NORMAL,    NPC_ANIM_jungle_guy_Palette_00_Anim_4,
    STATUS_STONE,     NPC_ANIM_jungle_guy_Palette_00_Anim_2,
    STATUS_SLEEP,     NPC_ANIM_jungle_guy_Palette_00_Anim_D,
    STATUS_POISON,    NPC_ANIM_jungle_guy_Palette_00_Anim_F,
    STATUS_STOP,      NPC_ANIM_jungle_guy_Palette_00_Anim_2,
    STATUS_STATIC,    NPC_ANIM_jungle_guy_Palette_00_Anim_4,
    STATUS_PARALYZE,  NPC_ANIM_jungle_guy_Palette_00_Anim_2,
    STATUS_DIZZY,     NPC_ANIM_jungle_guy_Palette_00_Anim_F,
    STATUS_FEAR,      NPC_ANIM_jungle_guy_Palette_00_Anim_F,
    STATUS_END,
};

s32 N(idleAnimations_8021860C)[] = {
    STATUS_NORMAL,    NPC_ANIM_jungle_guy_Palette_00_Anim_3,
    STATUS_STONE,     NPC_ANIM_jungle_guy_Palette_00_Anim_D,
    STATUS_SLEEP,     NPC_ANIM_jungle_guy_Palette_00_Anim_D,
    STATUS_POISON,    NPC_ANIM_jungle_guy_Palette_00_Anim_F,
    STATUS_STOP,      NPC_ANIM_jungle_guy_Palette_00_Anim_1,
    STATUS_STATIC,    NPC_ANIM_jungle_guy_Palette_00_Anim_3,
    STATUS_PARALYZE,  NPC_ANIM_jungle_guy_Palette_00_Anim_1,
    STATUS_DIZZY,     NPC_ANIM_jungle_guy_Palette_00_Anim_F,
    STATUS_FEAR,      NPC_ANIM_jungle_guy_Palette_00_Anim_F,
    STATUS_END,
};

s32 N(idleAnimations_80218658)[] = {
    STATUS_NORMAL,    NPC_ANIM_jungle_guy_Palette_00_Anim_14,
    STATUS_END,
};

s32 N(idleAnimations_80218664)[] = {
    STATUS_NORMAL,    NPC_ANIM_jungle_guy_Palette_00_Anim_19,
    STATUS_END,
};

s32 N(defenseTable_80218670)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_FIRE, 0,
    ELEMENT_END,
};

s32 N(defenseTable_80218684)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_SHOCK, 0,
    ELEMENT_END,
};

s32 N(statusTable_80218698)[] = {
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
    STATUS_STOP, 80,
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

s32 N(statusTable_80218744)[] = {
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

ActorPartBlueprint N(partsTable_802187F0)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 22 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802185C0),
        .defenseTable = N(defenseTable_80218670),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_FRONT,
        .elementImmunityFlags = 0,
        .unk_1C = 0xFD,
        .unk_1D = 0xF8,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021BF40),
        .defenseTable = N(defenseTable_80218684),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0xFF,
        .unk_1D = 0xF6,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80218658),
        .defenseTable = N(defenseTable_80218684),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80218664),
        .defenseTable = N(defenseTable_80218684),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_SPEAR_GUY,
    .level = 16,
    .maxHP = 7,
    .partCount = ARRAY_COUNT(N(partsTable_802187F0)),
    .partsData = N(partsTable_802187F0),
    .script = &N(init_80218980),
    .statusTable = N(statusTable_80218698),
    .escapeChance = 50,
    .airLiftChance = 85,
    .spookChance = 80,
    .baseStatusChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 85,
    .coinReward = 2,
    .size = { 24, 24 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(setSpearStance) = {
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(2)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_ADDR(N(idleAnimations_802185C0)))
            EVT_CALL(SetPartEventFlags, -127, 2, 65536)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_ADDR(N(idleAnimations_8021860C)))
            EVT_CALL(SetPartEventFlags, -127, 2, 16)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80218980) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(setSpearStance))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_4)
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(setSpearStance))
            EVT_CALL(SetPartEventFlags, -127, 2, 16)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_3)
    EVT_END_SWITCH
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021BCB4)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80218E3C)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_ADDR(N(nextTurn_80218B24)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(GetEncounterState, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(2)
        EVT_CASE_OR_EQ(4)
        EVT_CASE_OR_EQ(6)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 2, ACTOR_EVENT_FLAG_SPIKY_FRONT, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_ADDR(N(idleAnimations_8021860C)))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_3)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_80218B24) = {
    EVT_CALL(BindNextTurn, ACTOR_SELF, 0)
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80218BE0)))
    EVT_RETURN
    EVT_END
};

EvtScript N(80218B5C) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(10))
    EVT_IF_EQ(LW(10), 0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(11))
        EVT_IF_FLAG(LW(11), STATUS_FLAG_SLEEP | STATUS_FLAG_FEAR | STATUS_FLAG_DIZZY)
        EVT_ELSE
            EVT_SET(LW(1), LW(2))
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80218BE0) = {
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FEAR | STATUS_FLAG_DIZZY)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_ADDR(N(idleAnimations_8021860C)))
                EVT_CALL(SetPartEventBits, ACTOR_SELF, 2, ACTOR_EVENT_FLAG_SPIKY_TOP, 1)
                EVT_CALL(SetPartEventBits, ACTOR_SELF, 2, ACTOR_EVENT_FLAG_SPIKY_FRONT, 0)
            EVT_ELSE
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_ADDR(N(idleAnimations_802185C0)))
                EVT_CALL(SetPartEventBits, ACTOR_SELF, 2, ACTOR_EVENT_FLAG_SPIKY_TOP, 0)
                EVT_CALL(SetPartEventBits, ACTOR_SELF, 2, ACTOR_EVENT_FLAG_SPIKY_FRONT, 1)
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 2, EVT_ADDR(N(idleAnimations_8021860C)))
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 2, ACTOR_EVENT_FLAG_SPIKY_TOP, 1)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, 2, ACTOR_EVENT_FLAG_SPIKY_FRONT, 0)
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80218D7C) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_SET_CONST(LW(0), 2)
    EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_6)
    EVT_EXEC_WAIT(DoReturnHome)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_4)
        EVT_CASE_EQ(1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_3)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80218E3C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_7)
            EVT_SET_CONST(LW(2), NPC_ANIM_jungle_guy_Palette_00_Anim_8)
            EVT_EXEC_WAIT(N(80218B5C))
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(11))
                EVT_IF_FLAG(LW(11), STATUS_FLAG_SLEEP | STATUS_FLAG_FEAR | STATUS_FLAG_DIZZY)
                    EVT_SET_CONST(LW(0), 2)
                    EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_A)
                    EVT_SET_CONST(LW(2), NPC_ANIM_jungle_guy_Palette_00_Anim_C)
                EVT_ELSE
                    EVT_SET_CONST(LW(0), 2)
                    EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_B)
                    EVT_SET_CONST(LW(2), -1)
                EVT_END_IF
            EVT_ELSE
                EVT_SET_CONST(LW(0), 2)
                EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_A)
                EVT_SET_CONST(LW(2), NPC_ANIM_jungle_guy_Palette_00_Anim_C)
            EVT_END_IF
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(11))
                EVT_IF_FLAG(LW(11), STATUS_FLAG_SLEEP | STATUS_FLAG_FEAR | STATUS_FLAG_DIZZY)
                    EVT_SET_CONST(LW(0), 2)
                    EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_A)
                    EVT_SET_CONST(LW(2), NPC_ANIM_jungle_guy_Palette_00_Anim_C)
                    EVT_EXEC_WAIT(DoBurnHit)
                    EVT_SET_CONST(LW(0), 2)
                    EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_C)
                    EVT_EXEC_WAIT(DoDeath)
                EVT_ELSE
                    EVT_SET_CONST(LW(0), 2)
                    EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_B)
                    EVT_SET_CONST(LW(2), -1)
                    EVT_EXEC_WAIT(DoBurnHit)
                    EVT_SET_CONST(LW(0), 2)
                    EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_B)
                    EVT_EXEC_WAIT(DoDeath)
                EVT_END_IF
            EVT_ELSE
                EVT_SET_CONST(LW(0), 2)
                EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_A)
                EVT_SET_CONST(LW(2), NPC_ANIM_jungle_guy_Palette_00_Anim_C)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_SET_CONST(LW(0), 2)
                EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_C)
                EVT_EXEC_WAIT(DoDeath)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_7)
            EVT_SET_CONST(LW(2), NPC_ANIM_jungle_guy_Palette_00_Anim_8)
            EVT_EXEC_WAIT(N(80218B5C))
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_7)
            EVT_SET_CONST(LW(2), NPC_ANIM_jungle_guy_Palette_00_Anim_8)
            EVT_EXEC_WAIT(N(80218B5C))
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_9)
            EVT_SET_CONST(LW(2), NPC_ANIM_jungle_guy_Palette_00_Anim_8)
            EVT_EXEC_WAIT(N(80218B5C))
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_7)
            EVT_SET_CONST(LW(2), NPC_ANIM_jungle_guy_Palette_00_Anim_8)
            EVT_EXEC_WAIT(N(80218B5C))
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_7)
            EVT_SET_CONST(LW(2), NPC_ANIM_jungle_guy_Palette_00_Anim_8)
            EVT_EXEC_WAIT(N(80218B5C))
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(80218D7C))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_7)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_3)
            EVT_SET_CONST(LW(2), NPC_ANIM_jungle_guy_Palette_00_Anim_4)
            EVT_EXEC_WAIT(N(80218B5C))
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_7)
            EVT_SET_CONST(LW(2), NPC_ANIM_jungle_guy_Palette_00_Anim_8)
            EVT_EXEC_WAIT(N(80218B5C))
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_9)
            EVT_SET_CONST(LW(2), NPC_ANIM_jungle_guy_Palette_00_Anim_8)
            EVT_EXEC_WAIT(N(80218B5C))
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_EQ(0)
                    EVT_SET_CONST(LW(0), 2)
                    EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_4)
                    EVT_EXEC_WAIT(DoRecover)
                EVT_CASE_EQ(1)
                    EVT_SET_CONST(LW(0), 2)
                    EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_3)
                    EVT_EXEC_WAIT(DoRecover)
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_6)
            EVT_SET_CONST(LW(2), NPC_ANIM_jungle_guy_Palette_00_Anim_7)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LW(0), 2)
            EVT_SET_CONST(LW(1), NPC_ANIM_jungle_guy_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_WAIT_FRAMES(10)
            EVT_SET(LF(0), 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(10))
            EVT_SWITCH(LW(10))
                EVT_CASE_EQ(0)
                    EVT_IF_FLAG(LW(3), STATUS_FLAG_SHRINK)
                        EVT_ADD(LW(0), -11)
                        EVT_ADD(LW(1), 3)
                        EVT_SET(LF(0), 1)
                    EVT_END_IF
                    EVT_IF_FLAG(LW(3), STATUS_FLAG_DIZZY)
                        EVT_ADD(LW(0), -4)
                        EVT_ADD(LW(1), 36)
                        EVT_SET(LF(0), 1)
                    EVT_END_IF
                    EVT_IF_FLAG(LW(3), STATUS_FLAG_SLEEP)
                        EVT_ADD(LW(0), -8)
                        EVT_ADD(LW(1), 36)
                        EVT_SET(LF(0), 1)
                    EVT_END_IF
                    EVT_IF_EQ(LF(0), 0)
                        EVT_ADD(LW(0), -28)
                        EVT_ADD(LW(1), 8)
                    EVT_END_IF
                EVT_CASE_EQ(1)
                    EVT_IF_FLAG(LW(3), STATUS_FLAG_SHRINK)
                        EVT_ADD(LW(0), -4)
                        EVT_ADD(LW(1), 15)
                        EVT_SET(LF(0), 1)
                    EVT_END_IF
                    EVT_IF_FLAG(LW(3), STATUS_FLAG_DIZZY)
                        EVT_ADD(LW(0), -4)
                        EVT_ADD(LW(1), 36)
                        EVT_SET(LF(0), 1)
                    EVT_END_IF
                    EVT_IF_FLAG(LW(3), STATUS_FLAG_SLEEP)
                        EVT_ADD(LW(0), -8)
                        EVT_ADD(LW(1), 36)
                        EVT_SET(LF(0), 1)
                    EVT_END_IF
                    EVT_IF_EQ(LF(0), 0)
                        EVT_ADD(LW(0), -10)
                        EVT_ADD(LW(1), 38)
                    EVT_END_IF
            EVT_END_SWITCH
            EVT_CALL(PlayEffect, EFFECT_LENS_FLARE, 0, LW(0), LW(1), LW(2), 20, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(20)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(spearStab) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_6)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
    EVT_IF_FLAG(LW(10), STATUS_FLAG_SHRINK)
        EVT_ADD(LW(0), 10)
    EVT_ELSE
        EVT_ADD(LW(0), 25)
    EVT_END_IF
    EVT_SET(LW(1), 0)
    EVT_ADD(LW(2), 1)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_4)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_1A)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x309)
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_1B)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(10), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_SUB(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT_FRAMES(15)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 2, 0, 2)
            EVT_EXEC_WAIT(N(80218D7C))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 2, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x309)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_1B)
    EVT_WAIT_FRAMES(5)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_WAIT_FRAMES(20)
            EVT_EXEC_WAIT(N(80218D7C))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(summonBackup) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_B)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_5)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2FA)
        EVT_WAIT_FRAMES(15)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2FB)
    EVT_END_THREAD
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_5)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_10)
    EVT_WAIT_FRAMES(25)
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2FA)
        EVT_WAIT_FRAMES(15)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2FB)
    EVT_END_THREAD
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_5)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_10)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_5)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 15)
    EVT_CALL(PlayEffect, EFFECT_SPARKLES, 0, LW(0), LW(1), LW(2), 30, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x206D)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_E)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(GetOriginalActorType, ACTOR_SELF, LW(0))
    EVT_CALL(EnemyCreateTargetList, 32772)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LW(1), LW(2))
    EVT_CALL(GetOriginalActorType, LW(1), LW(2))
    EVT_IF_EQ(LW(0), LW(2))
        EVT_CALL(SetAnimation, LW(1), 2, NPC_ANIM_jungle_guy_Palette_00_Anim_4)
        EVT_CALL(GetIndexFromHome, LW(1), LW(3))
        EVT_IF_LT(LW(10), LW(3))
            EVT_CALL(GetActorVar, LW(1), 0, LW(4))
            EVT_IF_EQ(LW(4), 0)
                EVT_CALL(SetActorVar, LW(1), 0, 1)
                EVT_CALL(SetIdleAnimations, LW(1), 2, EVT_ADDR(N(idleAnimations_8021860C)))
                EVT_CALL(SetPartEventFlags, LW(1), 2, 16)
                EVT_CALL(SetAnimation, LW(1), 2, NPC_ANIM_jungle_guy_Palette_00_Anim_3)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LW(1))
    EVT_IF_NE(LW(1), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_SET(LF(0), 0)
    EVT_CALL(EnemyCreateTargetList, 32772)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(1)
    EVT_CALL(GetOwnerTarget, LW(0), LW(1))
    EVT_CALL(GetIndexFromHome, LW(0), LW(1))
    EVT_IF_LT(LW(1), LW(10))
        EVT_SET(LF(0), 1)
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LW(0))
    EVT_IF_NE(LW(0), -1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_IF_EQ(LF(0), 0)
        EVT_CALL(SummonEnemy, EVT_ADDR(N(specialFormation_8021A8C0)), 0)
    EVT_ELSE
        EVT_CALL(SummonEnemy, EVT_ADDR(N(specialFormation_8021A8DC)), 0)
    EVT_END_IF
    EVT_SET(LW(11), LW(0))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(SetAnimation, LW(11), 2, NPC_ANIM_jungle_guy_Palette_00_Anim_10)
    EVT_CALL(SetGoalToIndex, LW(11), LW(10))
    EVT_CALL(GetGoalPos, LW(11), LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 220)
    EVT_CALL(SetActorPos, LW(11), LW(0), 0, 0)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 0, 0)
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2FA)
        EVT_WAIT_FRAMES(15)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2FA)
        EVT_WAIT_FRAMES(15)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2FB)
        EVT_WAIT_FRAMES(15)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2FB)
        EVT_WAIT_FRAMES(15)
    EVT_END_THREAD
    EVT_CALL(SetActorSpeed, LW(11), EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, LW(11), 0, FALSE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x206D)
    EVT_CALL(GetActorPos, LW(11), LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 15)
    EVT_CALL(PlayEffect, EFFECT_SPARKLES, 0, LW(0), LW(1), LW(2), 30, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(SetAnimation, LW(11), 2, NPC_ANIM_jungle_guy_Palette_00_Anim_E)
    EVT_WAIT_FRAMES(20)
    EVT_IF_EQ(LF(0), 0)
        EVT_CALL(SetAnimation, LW(11), 2, NPC_ANIM_jungle_guy_Palette_00_Anim_4)
    EVT_ELSE
        EVT_CALL(SetAnimation, LW(11), 2, NPC_ANIM_jungle_guy_Palette_00_Anim_3)
    EVT_END_IF
    EVT_CALL(GetActorPos, LW(11), LW(0), LW(1), LW(2))
    EVT_CALL(ForceHomePos, LW(11), LW(0), LW(1), LW(2))
    EVT_CALL(HPBarToHome, LW(11))
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, LW(11), 1, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, LW(11), 1, 2)
    EVT_END_SWITCH
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 3)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

Vec3i N(vector3D_8021A8B4) = { 0, -1000, 0 };

Formation N(specialFormation_8021A8C0) = {
    { .actor = &NAMESPACE, .home = { .vec = &N(vector3D_8021A8B4) }, .priority = 100, .var0 = 0 },
};

Formation N(specialFormation_8021A8DC) = {
    { .actor = &NAMESPACE, .home = { .vec = &N(vector3D_8021A8B4) }, .priority = 100, .var0 = 1 },
};

EvtScript N(becomeShyGuy) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 2)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetHomePos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_13)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_18)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 10)
    EVT_ADD(LW(1), 15)
    EVT_SUB(LW(2), 1)
    EVT_CALL(SetPartPos, ACTOR_SELF, 4, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 4, EVT_FLOAT(0.5))
    EVT_ADD(LW(0), 50)
    EVT_SUB(LW(2), 30)
    EVT_THREAD
        EVT_LOOP(15)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 4, 0, 0, 10)
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 4, 0, 0, -10)
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x206D)
    EVT_THREAD
        EVT_LOOP(10)
            EVT_CALL(GetPartOffset, ACTOR_SELF, 4, LW(0), LW(1), LW(2))
            EVT_CALL(PlayEffect, EFFECT_SPARKLES, 3, LW(0), LW(1), LW(2), 5, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 4, 0x2FC)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 4, 2, 0, 0)
    EVT_CALL(JumpPartTo, ACTOR_SELF, 4, LW(0), 0, LW(2), 30, 1)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 1, ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_MULTI_TARGET)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET)
    EVT_CALL(SetPartFlags, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_4 | ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET)
    EVT_EXEC_WAIT(N(8021BF8C))
    EVT_CALL(SetActorType, ACTOR_SELF, ACTOR_TYPE_SHY_GUY)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_1000, 1)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_ADDR(N(statusTable_80218744)))
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(spearThrow) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_6)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 200)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_15)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_SUB(LW(0), 100)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_SUB(LW(0), 70)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 3, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
        EVT_CALL(SetPartScale, ACTOR_SELF, 4, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, 3, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, 4, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_11)
            EVT_WAIT_FRAMES(5)
            EVT_THREAD
                EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_17)
                EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_SUB(LW(0), 20)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
                EVT_SUB(LW(0), 10)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
                EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_12)
            EVT_END_THREAD
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetPartPos, ACTOR_SELF, 3, LW(0), 20, LW(2))
            EVT_CALL(SetPartRotation, ACTOR_SELF, 3, 0, 0, -30)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 0)
            EVT_THREAD
                EVT_CALL(MakeLerp, -30, 45, 20, 0)
                EVT_LABEL(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetPartRotation, ACTOR_SELF, 3, 0, 0, LW(0))
                EVT_WAIT_FRAMES(1)
                EVT_IF_EQ(LW(1), 1)
                    EVT_GOTO(0)
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 3, 0x30A)
            EVT_CALL(SetPartSounds, ACTOR_SELF, 3, 2, 0, 0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 20)
            EVT_SET(LW(1), 10)
            EVT_ADD(LW(2), 2)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 3, EVT_FLOAT(0.7))
            EVT_CALL(JumpPartTo, ACTOR_SELF, 3, LW(0), LW(1), LW(2), 20, 1)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 2, 0, 2)
            EVT_WAIT_FRAMES(30)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 2, 0)
            EVT_WAIT_FRAMES(10)
            EVT_EXEC_WAIT(N(becomeShyGuy))
            EVT_CALL(YieldTurn)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_11)
    EVT_WAIT_FRAMES(5)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_17)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_SUB(LW(0), 20)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
        EVT_SUB(LW(0), 10)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_jungle_guy_Palette_00_Anim_12)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, LW(0), 20, LW(2))
    EVT_CALL(SetPartRotation, ACTOR_SELF, 3, 0, 0, -30)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_THREAD
        EVT_CALL(MakeLerp, -30, 45, 20, 0)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetPartRotation, ACTOR_SELF, 3, 0, 0, LW(0))
        EVT_WAIT_FRAMES(1)
        EVT_IF_EQ(LW(1), 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 3, 0x30A)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 3, 2, 0, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(2), 2)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 3, EVT_FLOAT(0.7))
    EVT_CALL(JumpPartTo, ACTOR_SELF, 3, LW(0), LW(1), LW(2), 20, 1)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_WAIT_FRAMES(3)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_WAIT_FRAMES(20)
    EVT_EXEC_WAIT(N(becomeShyGuy))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021B770) = {
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LW(0), LW(5))
    EVT_CALL(GetIndexFromHome, LW(0), LW(5))
    EVT_MOD(LW(5), 4)
    EVT_SWITCH(LW(5))
        EVT_CASE_EQ(0)
            EVT_SET(LF(1), 1)
        EVT_CASE_EQ(1)
            EVT_SET(LF(2), 1)
        EVT_CASE_EQ(2)
            EVT_SET(LF(3), 1)
        EVT_CASE_EQ(3)
            EVT_SET(LF(4), 1)
    EVT_END_SWITCH
    EVT_CALL(ChooseNextTarget, 0, LW(0))
    EVT_IF_NE(LW(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LF(1), 0)
        EVT_SET(LW(10), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LF(2), 0)
        EVT_SET(LW(10), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LF(3), 0)
        EVT_SET(LW(10), 2)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LF(4), 0)
        EVT_SET(LW(10), 3)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LW(10), -1)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021B96C) = {
    EVT_SET(LW(9), 0)
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LW(0), LW(1))
    EVT_CALL(GetOriginalActorType, LW(0), LW(2))
    EVT_SWITCH(LW(2))
        EVT_CASE_EQ(ACTOR_TYPE_JUNGLE_FUZZY)
            EVT_CALL(GetStatusFlags, LW(0), LW(3))
            EVT_IF_NOT_FLAG(LW(3), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(GetActorVar, LW(0), 0, LW(3))
                EVT_IF_NE(LW(3), 2)
                    EVT_ADD(LW(9), 1)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(ACTOR_TYPE_SPEAR_GUY)
            EVT_CALL(GetStatusFlags, LW(0), LW(3))
            EVT_IF_NOT_FLAG(LW(3), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(GetActorVar, LW(0), 1, LW(3))
                EVT_IF_LT(LW(3), 2)
                    EVT_ADD(LW(9), 1)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(ChooseNextTarget, 0, LW(0))
    EVT_IF_NE(LW(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(8021BB18) = {
    EVT_CALL(GetIndexFromHome, ACTOR_SELF, LW(10))
    EVT_SET(LF(0), 0)
    EVT_CALL(EnemyCreateTargetList, 32772)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LW(0), LW(1))
    EVT_CALL(GetIndexFromHome, LW(0), LW(1))
    EVT_IF_LT(LW(1), LW(10))
        EVT_SET(LF(0), 1)
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LW(0))
    EVT_IF_NE(LW(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LF(0), 1)
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
        EVT_IF_EQ(LW(0), 0)
            EVT_SET(LW(0), 1)
            EVT_EXEC_WAIT(N(setSpearStance))
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
        EVT_IF_EQ(LW(0), 1)
            EVT_SET(LW(0), 0)
            EVT_EXEC_WAIT(N(setSpearStance))
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021BCB4) = {
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
        EVT_EXEC_WAIT(N(spearStab))
        EVT_EXEC_WAIT(N(8021BB18))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(1)
            EVT_EXEC_WAIT(N(8021B770))
            EVT_IF_EQ(LW(10), -1)
                EVT_EXEC_WAIT(N(spearStab))
                EVT_EXEC_WAIT(N(8021BB18))
                EVT_RETURN
            EVT_END_IF
            EVT_EXEC_WAIT(N(8021B96C))
            EVT_SWITCH(LW(9))
                EVT_CASE_EQ(1)
                    EVT_CALL(RandInt, 1000, LW(0))
                    EVT_IF_LT(LW(0), 300)
                        EVT_EXEC_WAIT(N(summonBackup))
                        EVT_RETURN
                    EVT_END_IF
                EVT_CASE_EQ(2)
                    EVT_CALL(RandInt, 1000, LW(0))
                    EVT_IF_LT(LW(0), 150)
                        EVT_EXEC_WAIT(N(summonBackup))
                        EVT_RETURN
                    EVT_END_IF
                EVT_CASE_EQ(3)
                    EVT_CALL(RandInt, 1000, LW(0))
                    EVT_IF_LT(LW(0), 100)
                        EVT_EXEC_WAIT(N(summonBackup))
                        EVT_RETURN
                    EVT_END_IF
            EVT_END_SWITCH
            EVT_EXEC_WAIT(N(spearStab))
            EVT_EXEC_WAIT(N(8021BB18))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(2)
            EVT_CALL(EnemyCreateTargetList, 32770)
            EVT_CALL(GetTargetListLength, LW(0))
            EVT_IF_EQ(LW(0), 1)
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

s32 N(idleAnimations_8021BF40)[] = {
    STATUS_NORMAL,    NPC_ANIM_shy_guy_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_shy_guy_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_shy_guy_Palette_00_Anim_12,
    STATUS_POISON,    NPC_ANIM_shy_guy_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_shy_guy_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_shy_guy_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_shy_guy_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_shy_guy_Palette_00_Anim_13,
    STATUS_FEAR,      NPC_ANIM_shy_guy_Palette_00_Anim_13,
    STATUS_END,
};

EvtScript N(8021BF8C) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021D8D8)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021BFD8)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021C14C)))
    EVT_RETURN
    EVT_END
};

#include "common/UnkBattleFunc1.inc.c"

EvtScript N(idle_8021BFD8) = {
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

EvtScript N(8021C0E8) = {
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_SET_CONST(LW(0), 1)
    EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_3)
    EVT_EXEC_WAIT(DoReturnHome)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_1)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021C14C) = {
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
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(8021C0E8))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_shy_guy_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoDeath)
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
            EVT_EXEC_WAIT(DoDeath)
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

EvtScript N(8021C628) = {
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
            EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 751, 0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 8378, 948)
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
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2EF)
    EVT_END_THREAD
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 8378, 948)
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
    EVT_EXEC_WAIT(N(8021C0E8))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021CD50) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x234)
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
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 8378, 948)
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
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x349)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x749)
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
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20E4)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_shy_guy_Palette_00_Anim_10)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20C3)
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

EvtScript N(takeTurn_8021D8D8) = {
    EVT_CALL(RandInt, 1, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_EXEC_WAIT(N(8021C628))
    EVT_ELSE
        EVT_EXEC_WAIT(N(8021CD50))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
