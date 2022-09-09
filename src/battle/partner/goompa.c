#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/goompa.h"

#define NAMESPACE battle_partner_goombario

extern EvtScript N(init_80238110);
extern EvtScript N(takeTurn_802383F4);
extern EvtScript N(idle_8023818C);
extern EvtScript N(handleEvent_8023819C);
extern EvtScript N(80238488);
extern EvtScript N(802384D4);
extern EvtScript N(80238510);
extern EvtScript N(8023859C);

s32 N(idleAnimations_80238000)[] = {
    STATUS_NORMAL, NPC_ANIM_goompa_Palette_00_Anim_2,
    STATUS_END,
};

s32 N(defenseTable_8023800C)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_80238018)[] = {
    STATUS_NORMAL,            100,
    STATUS_DEFAULT,           100,
    STATUS_SLEEP,             100,
    STATUS_POISON,            100,
    STATUS_FROZEN,            100,
    STATUS_DIZZY,             100,
    STATUS_FEAR,              100,
    STATUS_STATIC,            100,
    STATUS_PARALYZE,          100,
    STATUS_SHRINK,            100,
    STATUS_STOP,              100,
    STATUS_DEFAULT_TURN_MOD,  0,
    STATUS_SLEEP_TURN_MOD,    0,
    STATUS_POISON_TURN_MOD,   0,
    STATUS_FROZEN_TURN_MOD,   0,
    STATUS_DIZZY_TURN_MOD,    0,
    STATUS_FEAR_TURN_MOD,     0,
    STATUS_STATIC_TURN_MOD,   0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD,   0,
    STATUS_STOP_TURN_MOD,     0,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_802380C4)[] = {
    {
        .index = 1,
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80238000),
        .defenseTable = N(defenseTable_8023800C),
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_PART_FLAG_200000,
    .type = ACTOR_TYPE_GOOMBARIO,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(partsTable_802380C4)),
    .partsData = N(partsTable_802380C4),
    .script = &N(init_80238110),
    .statusTable = N(statusTable_80238018),
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .size = { 29, 26 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(init_80238110) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_802383F4)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8023818C)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8023819C)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8023818C) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8023819C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(GetLastEvent, ACTOR_PARTNER, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_goompa_Palette_00_Anim_7)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(PlaySound, SOUND_208C)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_goompa_Palette_00_Anim_7)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_goompa_Palette_00_Anim_7)
            EVT_SET_CONST(LocalVar(2), NPC_ANIM_goompa_Palette_00_Anim_3)
            EVT_SET_CONST(LocalVar(3), NPC_ANIM_goompa_Palette_00_Anim_1)
            EVT_EXEC_WAIT(D_80294FE4)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
            EVT_SET_CONST(LocalVar(0), NPC_ANIM_goompa_Palette_00_Anim_7)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_goompa_Palette_00_Anim_7)
            EVT_SET_CONST(LocalVar(2), NPC_ANIM_goompa_Palette_00_Anim_7)
            EVT_SET_CONST(LocalVar(3), NPC_ANIM_goompa_Palette_00_Anim_3)
            EVT_SET_CONST(LocalVar(4), NPC_ANIM_goompa_Palette_00_Anim_1)
            EVT_EXEC_WAIT(D_80294C68)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LocalVar(0), 0)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_goompa_Palette_00_Anim_7)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_33)
        EVT_CASE_EQ(EVENT_RECOVER_PARTNER)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_goompa_Palette_00_Anim_1)
            EVT_SET_CONST(LocalVar(2), NPC_ANIM_goompa_Palette_00_Anim_3)
            EVT_EXEC_WAIT(D_80295EC4)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_802383F4) = {
    EVT_CALL(GetBattlePhase, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(PHASE_EXECUTE_ACTION)
            EVT_EXEC_WAIT(N(8023859C))
        EVT_CASE_EQ(PHASE_5)
            EVT_EXEC_WAIT(N(80238488))
        EVT_CASE_EQ(PHASE_RUN_AWAY_START)
            EVT_EXEC_WAIT(N(802384D4))
        EVT_CASE_EQ(PHASE_RUN_AWAY_FAIL)
            EVT_EXEC_WAIT(N(80238510))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80238488) = {
    EVT_SET_CONST(LocalVar(0), 1)
    EVT_SET_CONST(LocalVar(1), NPC_ANIM_goompa_Palette_00_Anim_9)
    EVT_SET_CONST(LocalVar(2), NPC_ANIM_goompa_Palette_00_Anim_2)
    EVT_EXEC_WAIT(D_80294720)
    EVT_RETURN
    EVT_END
};

EvtScript N(802384D4) = {
    EVT_SET_CONST(LocalVar(0), 1)
    EVT_SET_CONST(LocalVar(1), NPC_ANIM_goompa_Palette_00_Anim_3)
    EVT_EXEC_WAIT(D_80294AFC)
    EVT_RETURN
    EVT_END
};

EvtScript N(80238510) = {
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_goompa_Palette_00_Anim_3)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_goompa_Palette_00_Anim_1)
    EVT_RETURN
    EVT_END
};

EvtScript N(8023859C) = {
    EVT_RETURN
    EVT_END
};
