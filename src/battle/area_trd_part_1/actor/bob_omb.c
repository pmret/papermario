#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/bob_omb.h"

#define NAMESPACE b_area_trd_part_1_bob_omb

s32 N(idleAnimations_8021A510)[] = {
    STATUS_NORMAL,    NPC_ANIM_bob_omb_Palette_00_Anim_2,
    STATUS_STONE,     NPC_ANIM_bob_omb_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_bob_omb_Palette_00_Anim_18,
    STATUS_POISON,    NPC_ANIM_bob_omb_Palette_00_Anim_4,
    STATUS_STOP,      NPC_ANIM_bob_omb_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_bob_omb_Palette_00_Anim_2,
    STATUS_PARALYZE,  NPC_ANIM_bob_omb_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_bob_omb_Palette_00_Anim_1C,
    STATUS_FEAR,      NPC_ANIM_bob_omb_Palette_00_Anim_1C,
    STATUS_END,
};

s32 N(idleAnimations_8021A55C)[] = {
    STATUS_NORMAL,    NPC_ANIM_bob_omb_Palette_00_Anim_5,
    STATUS_STONE,     NPC_ANIM_bob_omb_Palette_00_Anim_1,
    STATUS_SLEEP,     NPC_ANIM_bob_omb_Palette_00_Anim_18,
    STATUS_POISON,    NPC_ANIM_bob_omb_Palette_00_Anim_5,
    STATUS_STOP,      NPC_ANIM_bob_omb_Palette_00_Anim_1,
    STATUS_STATIC,    NPC_ANIM_bob_omb_Palette_00_Anim_3,
    STATUS_PARALYZE,  NPC_ANIM_bob_omb_Palette_00_Anim_1,
    STATUS_DIZZY,     NPC_ANIM_bob_omb_Palette_00_Anim_1D,
    STATUS_FEAR,      NPC_ANIM_bob_omb_Palette_00_Anim_1D,
    STATUS_END,
};

s32 N(defenseTable_8021A5A8)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8021A5B4)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 75,
    STATUS_POISON, 0,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 80,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 80,
    STATUS_SHRINK, 90,
    STATUS_STOP, 90,
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

s32 N(statusTable_8021A660)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 40,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 40,
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

ActorPartBlueprint N(partsTable_8021A70C)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021A510),
        .defenseTable = N(defenseTable_8021A5A8),
        .eventFlags = ACTOR_EVENT_FLAG_EXPLOSIVE,
        .elementImmunityFlags = 0,
        .unk_1D = 247,
    },
};

extern EvtScript N(init_8021A758);

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_BOB_OMB,
    .level = 6,
    .maxHP = 3,
    .partCount = ARRAY_COUNT(N(partsTable_8021A70C)),
    .partsData = N(partsTable_8021A70C),
    .script = N(init_8021A758),
    .statusTable = N(statusTable_8021A5B4),
    .escapeChance = 70,
    .airLiftChance = 90,
    .spookChance = 90,
    .baseStatusChance = 90,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 34, 35 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

extern EvtScript N(takeTurn_8021C89C);
extern EvtScript N(idle_8021A7D4);
extern EvtScript N(handleEvent_8021ACE8);

EvtScript N(init_8021A758) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021C89C)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021A7D4)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021ACE8)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8021A7D4) = {
    EVT_RETURN
    EVT_END
};

extern EvtScript N(handleEvent_8021B4A8);

EvtScript N(ignite) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_RETURN
    EVT_END_IF
    EVT_LABEL(0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021A55C)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021B4A8)))
    EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_8000, 1)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_ADDR(N(statusTable_8021A660)))
    EVT_CALL(PlayLoopingSoundAtActor, ACTOR_SELF, 0, 0x80000001)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bob_omb_Palette_00_Anim_5)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 0, LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(func_8026ED20, ACTOR_SELF, 1, 1)
    EVT_CALL(func_8026EBF8, ACTOR_SELF, 1, 0, 2, 0, 10, 0, 10, 0, 0)
    EVT_CALL(func_8026EA7C, ACTOR_SELF, 1, 15)
    EVT_WAIT_FRAMES(3)
    EVT_CALL(StopLoopingSoundAtActor, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021A9C8) = {
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021ACE8)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021A510)))
    EVT_CALL(SetPartEventBits, ACTOR_SELF, 1, ACTOR_EVENT_FLAG_8000, 0)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_ADDR(N(statusTable_8021A5B4)))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(2), 2)
    EVT_CALL(PlayEffect, EFFECT_LANDING_DUST, 3, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(StopLoopingSoundAtActor, ACTOR_SELF, 0)
    EVT_CALL(func_8026ED20, ACTOR_SELF, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021AAE8) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(StopLoopingSoundAtActor, ACTOR_SELF, 0)
        EVT_CALL(func_8026ED20, ACTOR_SELF, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(8021AB54) = {
    EVT_EXEC_WAIT(N(8021AAE8))
    EVT_CALL(StartRumble, 11)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.75))
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(4.5))
        EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(3.0))
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(2), 2)
    EVT_CALL(PlayEffect, EFFECT_SMOKE_RING, 0, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_ADD(LW(1), 20)
    EVT_ADD(LW(2), 2)
    EVT_CALL(PlayEffect, EFFECT_EXPLOSION, 0, LW(0), LW(1), LW(2), 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BOMB_BLAST)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021ACE8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(GetLastDamage, ACTOR_SELF, LW(0))
            EVT_IF_NE(LW(0), 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(GetLastElement, LW(14))
            EVT_IF_FLAG(LW(14), DAMAGE_TYPE_ELECTRIC)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_10)
                EVT_SET_CONST(LW(2), NPC_ANIM_bob_omb_Palette_00_Anim_11)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_EXEC_WAIT(N(8021AB54))
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_11)
                EVT_SET(LW(2), -12345)
                EVT_EXEC_WAIT(DoDeath)
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_E)
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_CALL(GetLastDamage, ACTOR_SELF, LW(0))
                EVT_IF_NE(LW(0), 0)
                    EVT_EXEC_WAIT(N(ignite))
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_10)
            EVT_SET_CONST(LW(2), NPC_ANIM_bob_omb_Palette_00_Anim_11)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021AB54))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_11)
            EVT_SET(LW(2), -12345)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_CALL(GetLastDamage, ACTOR_SELF, LW(0))
            EVT_IF_NE(LW(0), 0)
                EVT_EXEC_WAIT(N(ignite))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_EXEC_WAIT(N(8021AAE8))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_SHOCK_HIT)
        EVT_CASE_OR_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_10)
            EVT_SET(LW(2), -12345)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_UNKNOWN_TRIGGER)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_2)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_2)
            EVT_EXEC_WAIT(DoImmune)
            EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
            EVT_IF_EQ(LW(0), 1)
                EVT_EXEC_WAIT(N(ignite))
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetLastElement, LW(14))
            EVT_IF_FLAG(LW(14), DAMAGE_TYPE_ELECTRIC)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_10)
                EVT_SET_CONST(LW(2), NPC_ANIM_bob_omb_Palette_00_Anim_11)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_EXEC_WAIT(N(8021AB54))
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_11)
                EVT_SET(LW(2), -12345)
                EVT_EXEC_WAIT(DoDeath)
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_E)
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_WAIT_FRAMES(10)
                EVT_EXEC_WAIT(N(8021AAE8))
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_E)
                EVT_EXEC_WAIT(DoDeath)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_EXPLODE_TRIGGER)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_10)
            EVT_SET_CONST(LW(2), NPC_ANIM_bob_omb_Palette_00_Anim_11)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(8021AB54))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_11)
            EVT_SET(LW(2), -12345)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_2)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_6)
            EVT_SET_CONST(LW(2), NPC_ANIM_bob_omb_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_1C)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_1C)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021B4A8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(GetLastElement, LW(14))
            EVT_IF_FLAG(LW(14), DAMAGE_TYPE_WATER)
                EVT_EXEC_WAIT(N(8021A9C8))
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_E)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_F)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(GetLastElement, LW(14))
            EVT_SWITCH(LW(14))
                EVT_CASE_FLAG(DAMAGE_TYPE_WATER)
                    EVT_EXEC_WAIT(N(8021A9C8))
                    EVT_SET_CONST(LW(0), 1)
                    EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_E)
                    EVT_EXEC_WAIT(DoNormalHit)
                EVT_CASE_FLAG(DAMAGE_TYPE_ELECTRIC)
                    EVT_SET_CONST(LW(0), 1)
                    EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_10)
                    EVT_EXEC_WAIT(DoNormalHit)
                    EVT_EXEC_WAIT(N(8021AB54))
                    EVT_SET_CONST(LW(0), 1)
                    EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_11)
                    EVT_SET(LW(2), -12345)
                    EVT_EXEC_WAIT(DoDeath)
                    EVT_RETURN
                EVT_CASE_DEFAULT
                    EVT_SET_CONST(LW(0), 1)
                    EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_F)
                    EVT_EXEC_WAIT(DoNormalHit)
                    EVT_CALL(GetLastDamage, ACTOR_SELF, LW(0))
                    EVT_IF_GT(LW(0), 0)
                        EVT_EXEC_WAIT(N(8021AB54))
                        EVT_SET_CONST(LW(0), 1)
                        EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_11)
                        EVT_SET(LW(2), -12345)
                        EVT_EXEC_WAIT(DoDeath)
                        EVT_RETURN
                    EVT_END_IF
            EVT_END_SWITCH
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
        EVT_CASE_OR_EQ(EVENT_SPIN_SMASH_HIT)
        EVT_CASE_OR_EQ(EVENT_SPIN_SMASH_DEATH)
        EVT_CASE_OR_EQ(EVENT_EXPLODE_TRIGGER)
            EVT_EXEC_WAIT(N(8021AB54))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_11)
            EVT_SET(LW(2), -12345)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetLastElement, LW(14))
            EVT_IF_FLAG(LW(14), DAMAGE_TYPE_WATER)
                EVT_EXEC_WAIT(N(8021A9C8))
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_E)
            EVT_ELSE
                EVT_EXEC_WAIT(N(8021AB54))
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_11)
                EVT_SET(LW(2), -12345)
            EVT_END_IF
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_SHOCK_HIT)
        EVT_CASE_OR_EQ(EVENT_SHOCK_DEATH)
            EVT_EXEC_WAIT(N(8021AB54))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_11)
            EVT_SET(LW(2), -12345)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_EXEC_WAIT(N(8021AAE8))
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_6)
            EVT_SET_CONST(LW(2), NPC_ANIM_bob_omb_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_1D)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(func_80269E80, LW(0))
            EVT_IF_EQ(LW(0), 20)
                EVT_EXEC_WAIT(N(8021A9C8))
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_1C)
            EVT_ELSE
                EVT_CHILD_THREAD
                    EVT_WAIT_FRAMES(100)
                    EVT_EXEC_WAIT(N(8021AB54))
                EVT_END_CHILD_THREAD
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_1D)
            EVT_END_IF
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_UP_AND_AWAY)
            EVT_EXEC_WAIT(N(8021A9C8))
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(tackleAttack) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bob_omb_Palette_00_Anim_6)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bob_omb_Palette_00_Anim_2)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bob_omb_Palette_00_Anim_6)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 5)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.1))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bob_omb_Palette_00_Anim_1C)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 20)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 15)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_WAIT_FRAMES(8)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(5)
            EVT_CALL(YieldTurn)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bob_omb_Palette_00_Anim_6)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bob_omb_Palette_00_Anim_2)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(HIT_RESULT_HIT_STATIC)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.1))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bob_omb_Palette_00_Anim_14)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(GetActorSize, ACTOR_SELF, LW(3), LW(4))
            EVT_CALL(PlayEffect, EFFECT_FLASHING_BOX_SHOCKWAVE, 0, LW(0), LW(1), LW(2), LW(4), LW(3), 0, 0, 0, 0, 0, 0, 0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HIT_SHOCK)
            EVT_WAIT_FRAMES(20)
            EVT_EXEC_WAIT(N(8021AB54))
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_BLAST, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.1))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bob_omb_Palette_00_Anim_2)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 40)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_WAIT_FRAMES(4)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bob_omb_Palette_00_Anim_6)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bob_omb_Palette_00_Anim_2)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(blastAttack) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(PlayLoopingSoundAtActor, ACTOR_SELF, 0, 0x80000001)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bob_omb_Palette_00_Anim_7)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 80, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, -1, 14, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 90)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bob_omb_Palette_00_Anim_7)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_EXEC_WAIT(N(8021AB54))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bob_omb_Palette_00_Anim_11)
            EVT_WAIT_FRAMES(10)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), -1)
            EVT_SET(LW(2), -12345)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bob_omb_Palette_00_Anim_7)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 10, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bob_omb_Palette_00_Anim_14)
    EVT_WAIT_FRAMES(15)
    EVT_SET(LW(10), 1)
    EVT_EXEC_WAIT(N(8021AB54))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bob_omb_Palette_00_Anim_11)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_BLAST | DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_WAIT_FRAMES(15)
    EVT_SET_CONST(LW(0), 1)
    EVT_SET_CONST(LW(1), NPC_ANIM_bob_omb_Palette_00_Anim_11)
    EVT_SET(LW(2), -12345)
    EVT_EXEC_WAIT(DoDeath)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021C89C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_EXEC_WAIT(N(tackleAttack))
    EVT_ELSE
        EVT_EXEC_WAIT(N(blastAttack))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
