#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Whacka.h"

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(spawnWhackasBump);
extern EvtScript N(die);

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL,    ANIM_Whacka_Idle,
    STATUS_STONE,     ANIM_Whacka_Still,
    STATUS_SLEEP,     ANIM_Whacka_Idle,
    STATUS_POISON,    ANIM_Whacka_Idle,
    STATUS_STOP,      ANIM_Whacka_Still,
    STATUS_STATIC,    ANIM_Whacka_Idle,
    STATUS_PARALYZE,  ANIM_Whacka_Still,
    STATUS_DIZZY,     ANIM_Whacka_Idle,
    STATUS_FEAR,      ANIM_Whacka_Idle,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 0,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 0,
    STATUS_STOP, 0,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -5 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_HIDE_HP_BAR,
    .type = ACTOR_TYPE_WHACKA,
    .level = 0,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 50,
    .coinReward = 0,
    .size = { 47, 32 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -20, 40 },
    .statusMessageOffset = { 10, 30 },
};

API_CALLABLE(N(IsHitEightTimes)) {
    script->varTable[0] = 0;
    if (evt_get_variable(NULL, GB_IWA00_Whacka_HitCount) >= 8) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(N(IsHitEightTimes))
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_DISABLED | ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY, TRUE)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_END_IF
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
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2073)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Hurt)
            EVT_EXEC_WAIT(N(spawnWhackasBump))
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LE(LVar0, 100)
                EVT_EXEC_WAIT(N(die))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_SET_CONST(LVar2, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(N(spawnWhackasBump))
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LE(LVar0, 100)
                EVT_EXEC_WAIT(N(die))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_SET_CONST(LVar2, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(N(spawnWhackasBump))
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_IF_GE(100, 100)
                EVT_EXEC_WAIT(N(die))
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
                EVT_EXEC_WAIT(EVS_DoDeath)
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LE(LVar0, 100)
                EVT_EXEC_WAIT(N(die))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_IF_GE(100, 100)
                EVT_EXEC_WAIT(N(die))
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
                EVT_EXEC_WAIT(EVS_DoDeath)
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(DoReturnHome)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(DoImmune)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LE(LVar0, 100)
                EVT_EXEC_WAIT(N(die))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(DoImmune)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LE(LVar0, 100)
                EVT_EXEC_WAIT(N(die))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Hurt)
            EVT_EXEC_WAIT(N(spawnWhackasBump))
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_WAIT(10)
            EVT_IF_GE(100, 100)
                EVT_EXEC_WAIT(N(die))
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
                EVT_EXEC_WAIT(EVS_DoDeath)
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_SET_CONST(LVar2, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Whacka_Idle)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(RandInt, 100, LVar0)
    EVT_IF_LE(LVar0, 100)
        EVT_EXEC_WAIT(N(die))
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(spawnWhackasBump) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2073)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Whacka_Idle)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_ADD(LVar1, 20)
        EVT_ADD(LVar2, 10)
        EVT_CALL(MakeItemEntity, ITEM_WHACKAS_BUMP, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_FALL_SPAWN_ALWAYS, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(die) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Whacka_Burrow)
    EVT_WAIT(40)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(SetBattleFlagBits2, BS_FLAGS2_DROP_WHACKA_BUMP, TRUE)
    EVT_END_IF
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_DISABLED | ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};
