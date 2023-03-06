#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/MarshalGuy.h"

#define NAMESPACE b_area_omo2_4_signal_guy

extern s32 N(IdleAnimations)[];

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);

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
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_MULTI_TARGET | ACTOR_PART_FLAG_20000000,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_DMG_POPUP,
    .type = ACTOR_TYPE_SIGNAL_GUY,
    .level = 0,
    .maxHP = 8,
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
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 30, 30 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL, ANIM_MarshalGuy_Anim01,
    STATUS_END,
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(SetActorPos, ACTOR_SELF, 180, 0, 0)
    EVT_CALL(ForceHomePos, ACTOR_SELF, 180, 0, 0)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MarshalGuy_Anim0F)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
        EVT_CALL(SetGoalPos, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_GENERAL_WHISTLE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MarshalGuy_Anim04)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MarshalGuy_Anim05)
        EVT_WAIT(15)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MarshalGuy_Anim09)
    EVT_END_THREAD
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
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
        EVT_CASE_OR_EQ(EVENT_SPIN_SMASH_HIT)
        EVT_CASE_OR_EQ(EVENT_SPIN_SMASH_DEATH)
        EVT_CASE_OR_EQ(EVENT_SHOCK_HIT)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_SPIKE_TAUNT)
        EVT_CASE_OR_EQ(EVENT_DEATH)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MarshalGuy_Anim0A)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 35)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MarshalGuy_Anim02)
            EVT_WAIT(24)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MarshalGuy_Anim03)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 5)
            EVT_ADD(LVar1, 10)
            EVT_LOOP(4)
                EVT_PLAY_EFFECT(EFFECT_SWEAT, 0, LVar0, LVar1, LVar2, 10, 45, 4, 0)
                EVT_WAIT(6)
            EVT_END_LOOP
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_20BA, SOUND_3B4)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MarshalGuy_Anim0C)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_STEAM_EMITTER)
            EVT_CALL(SetGoalPos, ACTOR_SELF, -200, 0, 20)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, LVar0, 0)
            EVT_CALL(RemoveActor, ACTOR_SELF)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_MarshalGuy_Anim01)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_MarshalGuy_Anim0A)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(1000)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_MarshalGuy_Anim01)
            EVT_SET_CONST(LVar2, ANIM_MarshalGuy_Anim0A)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
            EVT_SET_CONST(LVar1, ANIM_MarshalGuy_Anim0A)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, LVar1)
            EVT_WAIT(20)
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_RETURN
    EVT_END
};
