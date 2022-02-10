#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/bzzap.h"

#define NAMESPACE b_area_mim_bzzap

extern EvtScript N(init_8021AA24);
extern EvtScript N(takeTurn_8021D28C);
extern EvtScript N(idle_8021AB10);
extern EvtScript N(handleEvent_8021ACA8);

s32 N(idleAnimations_8021A820)[] = {
    STATUS_NORMAL,    NPC_ANIM_bzzap_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_bzzap_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_bzzap_Palette_00_Anim_9,
    STATUS_POISON,    NPC_ANIM_bzzap_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_bzzap_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_bzzap_Palette_00_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_bzzap_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_bzzap_Palette_00_Anim_A,
    STATUS_FEAR,      NPC_ANIM_bzzap_Palette_00_Anim_A,
    STATUS_END,
};

s32 N(defenseTable_8021A86C)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8021A878)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 60,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 90,
    STATUS_SHRINK, 75,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_8021A924)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -7, 33 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021A820),
        .defenseTable = N(defenseTable_8021A86C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 2,
        .unk_1D = 0xF6,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021A820),
        .defenseTable = N(defenseTable_8021A86C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 255,
        .unk_1D = -5,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021A820),
        .defenseTable = N(defenseTable_8021A86C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 255,
        .unk_1D = -5,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021A820),
        .defenseTable = N(defenseTable_8021A86C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 255,
        .unk_1D = -5,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021A820),
        .defenseTable = N(defenseTable_8021A86C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 255,
        .unk_1D = -5,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021A820),
        .defenseTable = N(defenseTable_8021A86C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 255,
        .unk_1D = -5,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_BZZAP,
    .level = 19,
    .maxHP = 3,
    .partCount = ARRAY_COUNT(N(partsTable_8021A924)),
    .partsData = N(partsTable_8021A924),
    .script = &N(init_8021AA24),
    .statusTable = N(statusTable_8021A878),
    .escapeChance = 40,
    .airLiftChance = 95,
    .spookChance = 95,
    .baseStatusChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 38, 38 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

#include "common/UnkBattleFunc1.inc.c"

#include "common/UnkFloatFunc4.inc.c"

EvtScript N(init_8021AA24) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021D28C)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021AB10)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021ACA8)))
    EVT_CALL(SetPartScale, ACTOR_SELF, 2, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_CALL(SetPartScale, ACTOR_SELF, 3, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_CALL(SetPartScale, ACTOR_SELF, 4, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_CALL(SetPartScale, ACTOR_SELF, 5, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_CALL(SetPartScale, ACTOR_SELF, 6, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8021AB10) = {
    EVT_LABEL(0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
    EVT_IF_FLAG(LW(10), STATUS_FLAG_SLEEP | STATUS_FLAG_DIZZY)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -7, 19)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 2, -6)
        EVT_CALL(N(UnkBattleFunc1), -20, 20, 10, 27)
    EVT_ELSE
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -7, 33)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 2, -10)
        EVT_CALL(N(UnkBattleFunc1), -16, 22, 4, 22)
    EVT_END_IF
    EVT_WAIT_FRAMES(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021AC20) = {
    EVT_CALL(SetPartRotation, ACTOR_SELF, 1, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bzzap_Palette_00_Anim_3)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 11)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021ACA8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bzzap_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bzzap_Palette_00_Anim_7)
            EVT_SET_CONST(LW(2), NPC_ANIM_bzzap_Palette_00_Anim_8)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bzzap_Palette_00_Anim_7)
            EVT_SET_CONST(LW(2), NPC_ANIM_bzzap_Palette_00_Anim_8)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bzzap_Palette_00_Anim_8)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bzzap_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bzzap_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bzzap_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bzzap_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bzzap_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(8021AC20))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bzzap_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bzzap_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bzzap_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bzzap_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bzzap_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(8021AC20))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bzzap_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 0)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bzzap_Palette_00_Anim_3)
            EVT_SET_CONST(LW(2), NPC_ANIM_bzzap_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bzzap_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_IF_FLAG(LW(0), STATUS_FLAG_SHRINK)
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                EVT_ELSE
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 9, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_bzzap_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoBlowAway)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021B28C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bzzap_Palette_00_Anim_3)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 52, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, 12)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 20)
            EVT_ADD(LW(2), 1)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 4)
            EVT_WAIT_FRAMES(5)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20CA)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bzzap_Palette_00_Anim_4)
            EVT_WAIT_FRAMES(10)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_EXEC_WAIT(N(8021AC20))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 20)
    EVT_ADD(LW(2), 1)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 4)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20CA)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bzzap_Palette_00_Anim_4)
    EVT_WAIT_FRAMES(6)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, STATUS_FLAG_8 | STATUS_FLAG_20 | STATUS_FLAG_100 | STATUS_FLAG_200 | STATUS_FLAG_POISON | STATUS_FLAG_80000000, 6, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_WAIT_FRAMES(20)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(8021AC20))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021B77C) = {
    EVT_SET(LW(9), LW(0))
    EVT_CALL(SetPartYaw, ACTOR_SELF, LW(9), 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(10), LW(11), LW(12))
    EVT_ADD(LW(10), 200)
    EVT_ADD(LW(11), 100)
    EVT_CALL(SetPartPos, ACTOR_SELF, LW(9), LW(10), LW(11), LW(12))
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LW(9), ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(9), 0x4B0003)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(10), LW(11), LW(12))
    EVT_ADD(LW(11), 50)
    EVT_SUB(LW(12), 30)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LW(9), EVT_FLOAT(6.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LW(9), EVT_FLOAT(1.0))
    EVT_CALL(FlyPartTo, ACTOR_SELF, LW(9), LW(10), LW(11), LW(12), 0, -10, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
    EVT_CALL(GetPartOffset, ACTOR_SELF, LW(9), LW(6), LW(7), LW(8))
    EVT_CALL(MakeLerp, 90, 450, 50, 0)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(N(UnkFloatFunc4), LW(3), LW(5), 30, LW(0), LW(6), LW(8))
    EVT_CALL(SetPartPos, ACTOR_SELF, LW(9), LW(6), LW(7), LW(8))
    EVT_IF_GT(LW(3), LW(6))
        EVT_CALL(SetPartYaw, ACTOR_SELF, LW(9), 180)
    EVT_ELSE
        EVT_CALL(SetPartYaw, ACTOR_SELF, LW(9), 0)
    EVT_END_IF
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(LW(1), 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetPartYaw, ACTOR_SELF, LW(9), 0)
    EVT_IF_EQ(LW(9), 2)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_I)
        EVT_CALL(SetBattleCamZoom, 400)
        EVT_CALL(SetBattleCamOffsetZ, 30)
        EVT_CALL(BattleCamTargetActor, ACTOR_PLAYER)
        EVT_CALL(MoveBattleCamOver, 60)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(9), 0x4B0003)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(10), LW(11), LW(12))
    EVT_ADD(LW(11), 30)
    EVT_ADD(LW(12), 30)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LW(9), EVT_FLOAT(6.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LW(9), EVT_FLOAT(1.0))
    EVT_CALL(FlyPartTo, ACTOR_SELF, LW(9), LW(10), LW(11), LW(12), 0, -10, 0)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(3), LW(4), LW(5))
    EVT_CALL(GetPartOffset, ACTOR_SELF, LW(9), LW(6), LW(7), LW(8))
    EVT_CALL(MakeLerp, -90, -720, 100, 0)
    EVT_LABEL(1)
    EVT_CALL(UpdateLerp)
    EVT_CALL(N(UnkFloatFunc4), LW(3), LW(5), 30, LW(0), LW(6), LW(8))
    EVT_CALL(SetPartPos, ACTOR_SELF, LW(9), LW(6), LW(7), LW(8))
    EVT_IF_GT(LW(3), LW(6))
        EVT_CALL(SetPartYaw, ACTOR_SELF, LW(9), 180)
    EVT_ELSE
        EVT_CALL(SetPartYaw, ACTOR_SELF, LW(9), 0)
    EVT_END_IF
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(LW(1), 1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(8021BC74) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 2, 1, 0, 0)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 3, 1, 0, 0)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 4, 1, 0, 0)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 5, 1, 0, 0)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 6, 1, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x20CC)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bzzap_Palette_00_Anim_5)
    EVT_WAIT_FRAMES(40)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_bzzap_Palette_00_Anim_1)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(PlaySound, 0x358)
    EVT_SET(LW(0), 2)
    EVT_EXEC_GET_TID(N(8021B77C), LW(10))
    EVT_WAIT_FRAMES(11)
    EVT_SET(LW(0), 3)
    EVT_EXEC(N(8021B77C))
    EVT_WAIT_FRAMES(11)
    EVT_SET(LW(0), 4)
    EVT_EXEC(N(8021B77C))
    EVT_WAIT_FRAMES(11)
    EVT_SET(LW(0), 5)
    EVT_EXEC(N(8021B77C))
    EVT_WAIT_FRAMES(11)
    EVT_SET(LW(0), 6)
    EVT_EXEC(N(8021B77C))
    EVT_LABEL(0)
    EVT_IS_THREAD_RUNNING(LW(10), LW(0))
    EVT_WAIT_FRAMES(1)
    EVT_IF_EQ(LW(0), 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_THREAD
                EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 2, 0x20CB)
                EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_bzzap_Palette_00_Anim_4)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(AddGoalPos, ACTOR_SELF, -30, -20, 1)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 2, EVT_FLOAT(3.0))
                EVT_CALL(FlyPartTo, ACTOR_SELF, 2, LW(0), LW(1), LW(2), 0, -10, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_bzzap_Palette_00_Anim_3)
                EVT_CALL(SetPartYaw, ACTOR_SELF, 2, 180)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_ADD(LW(1), 100)
                EVT_ADD(LW(2), 100)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 2, 0, 2)
                EVT_CALL(FlyPartTo, ACTOR_SELF, 2, LW(0), LW(1), LW(2), 0, 10, 0)
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 2, 0)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_END_THREAD
            EVT_WAIT_FRAMES(11)
            EVT_THREAD
                EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 3, 0x20CB)
                EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_bzzap_Palette_00_Anim_4)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(AddGoalPos, ACTOR_SELF, -30, -20, 1)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 3, EVT_FLOAT(3.0))
                EVT_CALL(FlyPartTo, ACTOR_SELF, 3, LW(0), LW(1), LW(2), 0, -10, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_bzzap_Palette_00_Anim_3)
                EVT_CALL(SetPartYaw, ACTOR_SELF, 3, 180)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_ADD(LW(1), 100)
                EVT_ADD(LW(2), 100)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 3, 0, 2)
                EVT_CALL(FlyPartTo, ACTOR_SELF, 3, LW(0), LW(1), LW(2), 0, 10, 0)
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 3, 0)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_END_THREAD
            EVT_WAIT_FRAMES(11)
            EVT_THREAD
                EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 4, 0x20CB)
                EVT_CALL(SetAnimation, ACTOR_SELF, 4, NPC_ANIM_bzzap_Palette_00_Anim_4)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(AddGoalPos, ACTOR_SELF, -30, -20, 1)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 4, EVT_FLOAT(3.0))
                EVT_CALL(FlyPartTo, ACTOR_SELF, 4, LW(0), LW(1), LW(2), 0, -10, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 4, NPC_ANIM_bzzap_Palette_00_Anim_3)
                EVT_CALL(SetPartYaw, ACTOR_SELF, 4, 180)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_ADD(LW(1), 100)
                EVT_ADD(LW(2), 100)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 4, 0, 2)
                EVT_CALL(FlyPartTo, ACTOR_SELF, 4, LW(0), LW(1), LW(2), 0, 10, 0)
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 4, 0)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_END_THREAD
            EVT_WAIT_FRAMES(11)
            EVT_THREAD
                EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 5, 0x20CB)
                EVT_CALL(SetAnimation, ACTOR_SELF, 5, NPC_ANIM_bzzap_Palette_00_Anim_4)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(AddGoalPos, ACTOR_SELF, -30, -20, 1)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 5, EVT_FLOAT(3.0))
                EVT_CALL(FlyPartTo, ACTOR_SELF, 5, LW(0), LW(1), LW(2), 0, -10, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 5, NPC_ANIM_bzzap_Palette_00_Anim_3)
                EVT_CALL(SetPartYaw, ACTOR_SELF, 5, 180)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_ADD(LW(1), 100)
                EVT_ADD(LW(2), 100)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 5, 0, 2)
                EVT_CALL(FlyPartTo, ACTOR_SELF, 5, LW(0), LW(1), LW(2), 0, 10, 0)
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 5, 0)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_END_THREAD
            EVT_WAIT_FRAMES(11)
            EVT_THREAD
                EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 6, 0x20CB)
                EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_bzzap_Palette_00_Anim_4)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(AddGoalPos, ACTOR_SELF, -30, -20, 1)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(3.0))
                EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 0, -10, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_bzzap_Palette_00_Anim_3)
                EVT_CALL(SetPartYaw, ACTOR_SELF, 6, 180)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_ADD(LW(1), 100)
                EVT_ADD(LW(2), 100)
                EVT_CALL(AddActorDecoration, ACTOR_SELF, 6, 0, 2)
                EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 0, 10, 0)
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 6, 0)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_END_THREAD
            EVT_WAIT_FRAMES(11)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(30)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_WAIT_FRAMES(30)
            EVT_CALL(StopSound, 856)
            EVT_CALL(YieldTurn)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 2, 0x20CB)
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_bzzap_Palette_00_Anim_4)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, -10, -10, 1)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 2, EVT_FLOAT(3.0))
        EVT_CALL(FlyPartTo, ACTOR_SELF, 2, LW(0), LW(1), LW(2), 0, -10, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 1, BS_FLAGS1_10)
        EVT_CALL(SetAnimation, ACTOR_SELF, 2, NPC_ANIM_bzzap_Palette_00_Anim_3)
        EVT_CALL(SetPartYaw, ACTOR_SELF, 2, 180)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 100)
        EVT_ADD(LW(2), 100)
        EVT_CALL(FlyPartTo, ACTOR_SELF, 2, LW(0), LW(1), LW(2), 0, 10, 0)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 2, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(11)
    EVT_THREAD
        EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 3, 0x20CB)
        EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_bzzap_Palette_00_Anim_4)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, -10, -10, 1)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 3, EVT_FLOAT(3.0))
        EVT_CALL(FlyPartTo, ACTOR_SELF, 3, LW(0), LW(1), LW(2), 0, -10, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 1, BS_FLAGS1_40)
        EVT_CALL(SetAnimation, ACTOR_SELF, 3, NPC_ANIM_bzzap_Palette_00_Anim_3)
        EVT_CALL(SetPartYaw, ACTOR_SELF, 3, 180)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 100)
        EVT_ADD(LW(2), 100)
        EVT_CALL(FlyPartTo, ACTOR_SELF, 3, LW(0), LW(1), LW(2), 0, 10, 0)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(11)
    EVT_THREAD
        EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 4, 0x20CB)
        EVT_CALL(SetAnimation, ACTOR_SELF, 4, NPC_ANIM_bzzap_Palette_00_Anim_4)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, -10, -10, 1)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 4, EVT_FLOAT(3.0))
        EVT_CALL(FlyPartTo, ACTOR_SELF, 4, LW(0), LW(1), LW(2), 0, -10, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 1, BS_FLAGS1_40)
        EVT_CALL(SetAnimation, ACTOR_SELF, 4, NPC_ANIM_bzzap_Palette_00_Anim_3)
        EVT_CALL(SetPartYaw, ACTOR_SELF, 4, 180)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 100)
        EVT_ADD(LW(2), 100)
        EVT_CALL(FlyPartTo, ACTOR_SELF, 4, LW(0), LW(1), LW(2), 0, 10, 0)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 4, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(11)
    EVT_THREAD
        EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 5, 0x20CB)
        EVT_CALL(SetAnimation, ACTOR_SELF, 5, NPC_ANIM_bzzap_Palette_00_Anim_4)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, -10, -10, 1)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 5, EVT_FLOAT(3.0))
        EVT_CALL(FlyPartTo, ACTOR_SELF, 5, LW(0), LW(1), LW(2), 0, -10, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 1, BS_FLAGS1_40)
        EVT_CALL(SetAnimation, ACTOR_SELF, 5, NPC_ANIM_bzzap_Palette_00_Anim_3)
        EVT_CALL(SetPartYaw, ACTOR_SELF, 5, 180)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 100)
        EVT_ADD(LW(2), 100)
        EVT_CALL(FlyPartTo, ACTOR_SELF, 5, LW(0), LW(1), LW(2), 0, 10, 0)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 5, ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(11)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 6, 0x20CB)
    EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_bzzap_Palette_00_Anim_4)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, -10, -10, 1)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(3.0))
    EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 0, -10, 0)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetAnimation, ACTOR_SELF, 6, NPC_ANIM_bzzap_Palette_00_Anim_3)
            EVT_CALL(SetPartYaw, ACTOR_SELF, 6, 180)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(1), 100)
            EVT_ADD(LW(2), 100)
            EVT_CALL(FlyPartTo, ACTOR_SELF, 6, LW(0), LW(1), LW(2), 0, 10, 0)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_CALL(StopSound, 856)
            EVT_CALL(YieldTurn)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021D28C) = {
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
        EVT_EXEC_WAIT(N(8021B28C))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(RandInt, 1000, LW(0))
    EVT_IF_LT(LW(0), 500)
        EVT_EXEC_WAIT(N(8021B28C))
    EVT_ELSE
        EVT_EXEC_WAIT(N(8021BC74))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
