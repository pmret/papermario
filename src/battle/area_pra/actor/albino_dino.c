#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/albino_dino.h"

#define NAMESPACE b_area_pra_albino_dino

s32 N(idleAnimations)[] = {
    STATUS_NORMAL, NPC_ANIM_albino_dino_Palette_00_Anim_3,
    STATUS_STONE, NPC_ANIM_albino_dino_Palette_00_Anim_0,
    STATUS_SLEEP, NPC_ANIM_albino_dino_Palette_00_Anim_3,
    STATUS_POISON, NPC_ANIM_albino_dino_Palette_00_Anim_3,
    STATUS_STOP, NPC_ANIM_albino_dino_Palette_00_Anim_0,
    STATUS_STATIC, NPC_ANIM_albino_dino_Palette_00_Anim_3,
    STATUS_PARALYZE, NPC_ANIM_albino_dino_Palette_00_Anim_0,
    STATUS_DIZZY, NPC_ANIM_albino_dino_Palette_00_Anim_0,
    STATUS_FEAR, NPC_ANIM_albino_dino_Palette_00_Anim_0,
    STATUS_END,
};

s32 N(defenseTable)[] = {
    ELEMENT_NORMAL, 4,
    ELEMENT_FIRE, 99,
    ELEMENT_END,
};

s32 N(statusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 0,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 75,
    STATUS_STOP, 0,
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

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -9, 46 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = -6,
        .unk_1D = -17,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_ALBINO_DINO,
    .level = 23,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .script = &N(init),
    .statusTable = N(statusTable),
    .escapeChance = 40,
    .airLiftChance = 15,
    .spookChance = 10,
    .baseStatusChance = 25,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 64, 56 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -22, 24 },
    .statusMessageOffset = { 11, 40 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, N(takeTurn))
    EVT_CALL(BindIdle, ACTOR_SELF, N(idle))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, N(handleEvent))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(8021D9C4) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_albino_dino_Palette_00_Anim_5)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_albino_dino_Palette_00_Anim_3)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_albino_dino_Palette_00_Anim_8)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_albino_dino_Palette_00_Anim_A)
            EVT_SET_CONST(LW(2), NPC_ANIM_albino_dino_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_albino_dino_Palette_00_Anim_A)
            EVT_SET_CONST(LW(2), NPC_ANIM_albino_dino_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_albino_dino_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_albino_dino_Palette_00_Anim_8)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_albino_dino_Palette_00_Anim_8)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_albino_dino_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_albino_dino_Palette_00_Anim_8)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_albino_dino_Palette_00_Anim_8)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(8021D9C4))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_albino_dino_Palette_00_Anim_8)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_albino_dino_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_albino_dino_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_albino_dino_Palette_00_Anim_8)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_albino_dino_Palette_00_Anim_9)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_albino_dino_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_albino_dino_Palette_00_Anim_5)
            EVT_SET_CONST(LW(2), NPC_ANIM_albino_dino_Palette_00_Anim_8)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_albino_dino_Palette_00_Anim_5)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_albino_dino_Palette_00_Anim_8)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021DF24) = {
    EVT_SET(LW(10), 0)
    EVT_LABEL(0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetActorYaw, -127, LW(3))
    EVT_IF_EQ(LW(3), 0)
        EVT_ADD(LW(0), 20)
    EVT_ELSE
        EVT_ADD(LW(0), -20)
    EVT_END_IF
    EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LW(0), LW(1), LW(2), 25, 8, 45, 20, 0, 0, 0, 0, 0)
    EVT_IF_GT(LW(10), 3)
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(0.2))
        EVT_SET(LW(10), 0)
    EVT_END_IF
    EVT_ADD(LW(10), 1)
    EVT_WAIT_FRAMES(2)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_EXEC_GET_TID(N(8021DF24), LW(9))
    EVT_THREAD
        EVT_LOOP(3)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x30B)
            EVT_WAIT_FRAMES(4)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2FD)
            EVT_WAIT_FRAMES(4)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_albino_dino_Palette_00_Anim_5)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(15), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_THREAD
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(AddGoalPos, ACTOR_SELF, -100, 0, 0)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(12.0))
                EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                EVT_KILL_THREAD(LW(9))
            EVT_END_THREAD
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_WAIT_FRAMES(30)
            EVT_IF_EQ(LW(15), HIT_RESULT_LUCKY)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(40)
            EVT_CALL(YieldTurn)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_EXEC_WAIT(N(8021D9C4))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
    EVT_IF_FLAG(LW(10), STATUS_FLAG_SHRINK)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 12, 0, 0)
    EVT_ELSE
        EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
    EVT_END_IF
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(12.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 4, EVT_FLOAT(1.5))
    EVT_END_THREAD
    EVT_KILL_THREAD(LW(9))
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(15), 0, 0, STATUS_FLAG_8 | 0x00000010, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(15))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 40)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2FD)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_albino_dino_Palette_00_Anim_3)
            EVT_CALL(ShakeCam, 1, 0, 3, EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(10)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(8021D9C4))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
