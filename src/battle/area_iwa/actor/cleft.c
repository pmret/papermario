#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/cleft.h"

#define NAMESPACE b_area_iwa_cleft

extern s32 N(idleAnimations_80218838)[];
extern EvtSource N(init_802188D0);
extern EvtSource N(idle_80218934);
extern EvtSource N(takeTurn_8021A3EC);
extern EvtSource N(handleEvent_80218C3C);

s32 N(defenseTable_80218710)[] = {
    ELEMENT_NORMAL, 2,
    ELEMENT_FIRE, 99,
    ELEMENT_MAGIC, 0,
    ELEMENT_END,
};

s32 N(defenseTable_8021872C)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_FIRE, 99,
    ELEMENT_END,
};

s32 N(statusTable_80218740)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 40,
    STATUS_POISON, 50,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 50,
    STATUS_FEAR, 0,
    STATUS_STATIC, 50,
    STATUS_PARALYZE, 50,
    STATUS_SHRINK, 75,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartDesc N(partsTable_802187EC)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 22 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80218838),
        .defenseTable = N(defenseTable_80218710),
        .eventFlags = ACTOR_EVENT_FLAG_SPIKY_TOP,
        .elementImmunityFlags = 0,
        .unk_1C = 246,
    },
};

ActorDesc NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_CLEFT,
    .level = 10,
    .maxHP = 2,
    .partCount = ARRAY_COUNT(N(partsTable_802187EC)),
    .partsData = N(partsTable_802187EC),
    .script = N(init_802188D0),
    .statusTable = N(statusTable_80218740),
    .escapeChance = 80,
    .airLiftChance = 40,
    .spookChance = 40,
    .baseStatusChance = 40,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 95,
    .coinReward = 2,
    .size = { 44, 36 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(idleAnimations_80218838)[] = {
    STATUS_NORMAL,    NPC_ANIM_cleft_default_idle,
    STATUS_STONE,     NPC_ANIM_cleft_default_still,
    STATUS_SLEEP,     NPC_ANIM_cleft_default_sleep,
    STATUS_POISON,    NPC_ANIM_cleft_default_idle,
    STATUS_STOP,      NPC_ANIM_cleft_default_still,
    STATUS_STATIC,    NPC_ANIM_cleft_default_idle,
    STATUS_PARALYZE,  NPC_ANIM_cleft_default_still,
    STATUS_DIZZY,     NPC_ANIM_cleft_default_dizzy,
    STATUS_FEAR,      NPC_ANIM_cleft_default_dizzy,
    STATUS_END,
};

s32 N(idleAnimations_80218884)[] = {
    STATUS_NORMAL,    NPC_ANIM_cleft_default_Anim_5,
    STATUS_STONE,     NPC_ANIM_cleft_default_inverted_still,
    STATUS_SLEEP,     NPC_ANIM_cleft_default_inverted_sleep,
    STATUS_POISON,    NPC_ANIM_cleft_default_Anim_5,
    STATUS_STOP,      NPC_ANIM_cleft_default_inverted_still,
    STATUS_STATIC,    NPC_ANIM_cleft_default_Anim_5,
    STATUS_PARALYZE,  NPC_ANIM_cleft_default_inverted_still,
    STATUS_DIZZY,     NPC_ANIM_cleft_default_inverted_dizzy,
    STATUS_FEAR,      NPC_ANIM_cleft_default_inverted_dizzy,
    STATUS_END,
};

#include "common/SetSpinSmashable.inc.c"

#include "common/StartRumbleWithParams.inc.c"

EvtSource N(init_802188D0) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80218934)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021A3EC)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80218C3C)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_80218934) = {
    EVT_RETURN
    EVT_END
};

EvtSource N(80218944) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 2)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_cleft_default_run)
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
    EVT_THREAD
        EVT_SET(LW(0), 0)
        EVT_LOOP(5)
            EVT_ADD(LW(0), -36)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.3))
    EVT_SUB(LW(1), 6)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    EVT_CALL(N(StartRumbleWithParams), 200, 10)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(PlayEffect, EFFECT_ID_1D, 0, LW(0), LW(1), LW(2), 40, 8, EVT_FLOAT(0.0), 20, 0, 0, 0, 0, 0)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), 0, LW(2))
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_cleft_default_inverted_idle)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80218884)))
    EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_ADDR(N(defenseTable_8021872C)))
    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 0, 15)
    EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 0, -7)
    EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_SPIKY_TOP, 0)
    EVT_CALL(N(SetSpinSmashable), 0)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_400, 1)
    EVT_RETURN
    EVT_END
};

EvtSource N(handleEvent_80218C3C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_CALL(GetLastElement, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_FLAG(DAMAGE_TYPE_BLAST)
                    EVT_EXEC_WAIT(N(80218944))
                EVT_CASE_DEFAULT
                    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
                    EVT_IF_EQ(LW(0), 1)
                        EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_Anim_9)
                    EVT_ELSE
                        EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_skid)
                    EVT_END_IF
                    EVT_SET_CONST(LW(0), 1)
                    EVT_EXEC_WAIT(DoNormalHit)
            EVT_END_SWITCH
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetLastElement, LW(0))
            EVT_SWITCH(LW(0))
                EVT_CASE_FLAG(DAMAGE_TYPE_BLAST)
                    EVT_EXEC_WAIT(N(80218944))
                EVT_CASE_DEFAULT
                    EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_EXPLOSIVE, 1)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
                    EVT_IF_EQ(LW(0), 1)
                        EVT_SET_CONST(LW(0), 1)
                        EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_Anim_9)
                        EVT_SET_CONST(LW(2), -1)
                        EVT_EXEC_WAIT(DoBurnHit)
                    EVT_ELSE
                        EVT_SET_CONST(LW(0), 1)
                        EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_skid)
                        EVT_SET_CONST(LW(2), -1)
                        EVT_EXEC_WAIT(DoBurnHit)
                    EVT_END_IF
                    EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_EXPLOSIVE, 0)
            EVT_END_SWITCH
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_Anim_9)
                EVT_SET_CONST(LW(2), -1)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_Anim_9)
                EVT_EXEC_WAIT(DoDeath)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_skid)
                EVT_SET_CONST(LW(2), -1)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_skid)
                EVT_EXEC_WAIT(DoDeath)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_Anim_9)
            EVT_ELSE
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_skid)
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_Anim_9)
                EVT_EXEC_WAIT(DoSpinSmashHit)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_Anim_9)
                EVT_EXEC_WAIT(DoDeath)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_skid)
                EVT_EXEC_WAIT(DoSpinSmashHit)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_skid)
                EVT_EXEC_WAIT(DoDeath)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_skid)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_skid)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_run)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_skid)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_skid)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_STAR_BEAM)
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_cleft_default_laugh)
            EVT_END_IF
            EVT_WAIT_FRAMES(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(3))
            EVT_IF_FLAG(LW(3), STATUS_FLAG_SHRINK)
                EVT_ADD(LW(0), -3)
                EVT_ADD(LW(1), 10)
            EVT_ELSE
                EVT_ADD(LW(0), -8)
                EVT_ADD(LW(1), 27)
            EVT_END_IF
            EVT_CALL(PlayEffect, EFFECT_ID_1A, 0, LW(0), LW(1), LW(2), 20, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(20)
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_inverted_idle)
            EVT_ELSE
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_idle)
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_Anim_9)
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_WAIT_FRAMES(10)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_Anim_9)
                EVT_EXEC_WAIT(DoDeath)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_skid)
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_WAIT_FRAMES(10)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_skid)
                EVT_EXEC_WAIT(DoDeath)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_IF_EQ(LW(0), 0)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_idle)
                EVT_EXEC_WAIT(DoRecover)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_inverted_idle)
                EVT_EXEC_WAIT(DoImmune)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_run)
                EVT_SET_CONST(LW(2), NPC_ANIM_cleft_default_skid)
                EVT_EXEC_WAIT(DoScareAway)
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_inverted_dizzy)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_inverted_dizzy)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_cleft_default_skid)
            EVT_END_IF
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(802197AC) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
    EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(3.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_cleft_default_inverted_idle)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_cleft_default_Anim_5)
    EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LW(0))
    EVT_IF_GT(LW(0), 0)
        EVT_SUB(LW(0), 1)
        EVT_CALL(SetActorVar, ACTOR_SELF, 1, LW(0))
    EVT_ELSE
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_cleft_default_inverted_idle)
        EVT_THREAD
            EVT_WAIT_FRAMES(3)
            EVT_LOOP(5)
                EVT_ADD(LW(0), 36)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LW(0))
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_SUB(LW(1), 6)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.3))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
        EVT_CALL(N(StartRumbleWithParams), 200, 10)
        EVT_THREAD
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
        EVT_END_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), 0, LW(2))
        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_cleft_default_idle)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80218838)))
        EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_ADDR(N(defenseTable_80218710)))
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 0, 22)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 0, -10)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_SPIKY_TOP, 1)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(N(SetSpinSmashable), 1)
        EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_400, 0)
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(80219BA0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(PlayEffect, EFFECT_ID_1D, 1, LW(0), LW(1), LW(2), 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(PlayEffect, EFFECT_ID_1D, 1, LW(0), LW(1), LW(2), 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_WAIT_FRAMES(5)
        EVT_CALL(PlayEffect, EFFECT_ID_1D, 1, LW(0), LW(1), LW(2), 32, 4, 0, 10, 0, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_cleft_default_charge_still)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_cleft_default_charge)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, -5)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_cleft_default_still)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20D1)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 2, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_THREAD
                    EVT_WAIT_FRAMES(10)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_cleft_default_charge)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 100)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 1, 0, 0, 45)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_cleft_default_skid)
            EVT_WAIT_FRAMES(15)
            EVT_WAIT_FRAMES(8)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetPartRotation, ACTOR_SELF, 1, 0, 0, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_cleft_default_run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_cleft_default_idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_cleft_default_charge)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_cleft_default_idle)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 15)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.4))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_cleft_default_idle)
            EVT_WAIT_FRAMES(5)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_cleft_default_run)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_cleft_default_idle)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(takeTurn_8021A3EC) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_EXEC_WAIT(N(802197AC))
    EVT_ELSE
        EVT_EXEC_WAIT(N(80219BA0))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
