#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Goompa.h"

#define NAMESPACE battle_partner_goompa

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(celebrate);
extern EvtScript N(runAway);
extern EvtScript N(runAwayFail);
extern EvtScript N(executeAction);

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL, ANIM_Goompa_Walk,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
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

ActorPartBlueprint N(parts)[] = {
    {
        .index = 1,
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_PART_FLAG_200000,
    .type = ACTOR_TYPE_GOOMBARIO,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .size = { 29, 26 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(GetLastEvent, ACTOR_PARTNER, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Goompa_Injured)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(PlaySound, SOUND_208C)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Goompa_Injured)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_SET_CONST(LVar1, ANIM_Goompa_Injured)
            EVT_SET_CONST(LVar2, ANIM_Goompa_Run)
            EVT_SET_CONST(LVar3, ANIM_Goompa_Idle)
            EVT_EXEC_WAIT(DoPartnerSpikeContact)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
            EVT_SET_CONST(LVar0, ANIM_Goompa_Injured)
            EVT_SET_CONST(LVar1, ANIM_Goompa_Injured)
            EVT_SET_CONST(LVar2, ANIM_Goompa_Injured)
            EVT_SET_CONST(LVar3, ANIM_Goompa_Run)
            EVT_SET_CONST(LVar4, ANIM_Goompa_Idle)
            EVT_EXEC_WAIT(DoPartnerBurnContact)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 0)
            EVT_SET_CONST(LVar1, ANIM_Goompa_Injured)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_33)
        EVT_CASE_EQ(EVENT_RECOVER_FROM_KO)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Goompa_Idle)
            EVT_SET_CONST(LVar2, ANIM_Goompa_Run)
            EVT_EXEC_WAIT(DoPartnerRecover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_EXECUTE_ACTION)
            EVT_EXEC_WAIT(N(executeAction))
        EVT_CASE_EQ(PHASE_CELEBRATE)
            EVT_EXEC_WAIT(N(celebrate))
        EVT_CASE_EQ(PHASE_RUN_AWAY_START)
            EVT_EXEC_WAIT(N(runAway))
        EVT_CASE_EQ(PHASE_RUN_AWAY_FAIL)
            EVT_EXEC_WAIT(N(runAwayFail))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(celebrate) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, ANIM_Goompa_Celebrate)
    EVT_SET_CONST(LVar2, ANIM_Goompa_Walk)
    EVT_EXEC_WAIT(D_80294720)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAway) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, ANIM_Goompa_Run)
    EVT_EXEC_WAIT(DoPartnerRunAway)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAwayFail) = {
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_Goompa_Run)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_Goompa_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(executeAction) = {
    EVT_RETURN
    EVT_END
};
