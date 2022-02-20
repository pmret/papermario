#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/fuzzy.h"

#define NAMESPACE b_area_mim_forest_fuzzy

extern s32 N(idleAnimations_802184C4)[];
extern EvtScript N(init_80218510);
extern EvtScript N(takeTurn_8021A61C);
extern EvtScript N(idle_80218574);
extern EvtScript N(handleEvent_80218584);
extern Formation N(specialFormation_8021A800);

s32 N(defenseTable_802183C0)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_802183CC)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 95,
    STATUS_POISON, 90,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 0,
    STATUS_STATIC, 70,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 75,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
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

ActorPartBlueprint N(partsTable_80218478)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 20 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_802184C4),
        .defenseTable = N(defenseTable_802183C0),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 246,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_FOREST_FUZZY,
    .level = 11,
    .maxHP = 6,
    .partCount = ARRAY_COUNT(N(partsTable_80218478)),
    .partsData = N(partsTable_80218478),
    .script = &N(init_80218510),
    .statusTable = N(statusTable_802183CC),
    .escapeChance = 40,
    .airLiftChance = 90,
    .spookChance = 90,
    .baseStatusChance = 85,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 33, 28 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(idleAnimations_802184C4)[] = {
    STATUS_NORMAL,    NPC_ANIM_fuzzy_Palette_01_Anim_1,
    STATUS_STONE,     NPC_ANIM_fuzzy_Palette_01_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_fuzzy_Palette_01_Anim_E,
    STATUS_POISON,    NPC_ANIM_fuzzy_Palette_01_Anim_1,
    STATUS_STOP,      NPC_ANIM_fuzzy_Palette_01_Anim_0,
    STATUS_STATIC,    NPC_ANIM_fuzzy_Palette_01_Anim_1,
    STATUS_PARALYZE,  NPC_ANIM_fuzzy_Palette_01_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_fuzzy_Palette_01_Anim_F,
    STATUS_FEAR,      NPC_ANIM_fuzzy_Palette_01_Anim_F,
    STATUS_END,
};

EvtScript N(init_80218510) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021A61C)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80218574)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_80218584)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80218574) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80218584) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_CALL(GetLastElement, LW(0))
            EVT_IF_FLAG(LW(0), DAMAGE_TYPE_ELECTRIC)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_13)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_8)
            EVT_END_IF
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_10)
            EVT_SET_CONST(LW(2), NPC_ANIM_fuzzy_Palette_01_Anim_12)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_10)
            EVT_SET_CONST(LW(2), NPC_ANIM_fuzzy_Palette_01_Anim_12)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_12)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_8)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_8)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_8)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(func_80269470)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_13)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_13)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_3)
            EVT_EXEC_WAIT(D_8029C0A4)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(func_80269470)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_13)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_13)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetLastElement, LW(0))
            EVT_IF_FLAG(LW(0), DAMAGE_TYPE_ELECTRIC)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_13)
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_WAIT_FRAMES(10)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_13)
                EVT_EXEC_WAIT(DoDeath)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_8)
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_WAIT_FRAMES(10)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_8)
                EVT_EXEC_WAIT(DoDeath)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_3)
            EVT_SET_CONST(LW(2), NPC_ANIM_fuzzy_Palette_01_Anim_9)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_3)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_3)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_fuzzy_Palette_01_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80218C48) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetBattleCamTarget, LW(0), LW(1), LW(2))
    EVT_CALL(SetBattleCamZoom, 330)
    EVT_CALL(SetBattleCamOffsetZ, 30)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_B)
    EVT_THREAD
        EVT_WAIT_FRAMES(30)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x206E)
        EVT_WAIT_FRAMES(30)
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x206F)
            EVT_WAIT_FRAMES(11)
        EVT_END_LOOP
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2070)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzy_Palette_01_Anim_D)
    EVT_WAIT_FRAMES(130)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzy_Palette_01_Anim_2)
    EVT_CALL(SummonEnemy, EVT_ADDR(N(specialFormation_8021A800)), 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(1), LW(2), LW(3))
    EVT_CALL(SetActorPos, LW(0), LW(1), LW(2), LW(3))
    EVT_CALL(SetGoalToIndex, LW(0), LW(10))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzy_Palette_01_Anim_2)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(1), LW(2), LW(3))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(1), LW(2), LW(3))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 14, FALSE, TRUE, FALSE)
    EVT_END_THREAD
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetAnimation, LW(0), 1, NPC_ANIM_fuzzy_Palette_01_Anim_2)
    EVT_CALL(SetActorJumpGravity, LW(0), EVT_FLOAT(1.4))
    EVT_CALL(JumpToGoal, LW(0), 14, FALSE, TRUE, FALSE)
    EVT_CALL(GetActorPos, LW(0), LW(1), LW(2), LW(3))
    EVT_CALL(ForceHomePos, LW(0), LW(1), LW(2), LW(3))
    EVT_CALL(HPBarToHome, LW(0))
    EVT_CALL(SetAnimation, LW(0), 1, NPC_ANIM_fuzzy_Palette_01_Anim_1)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(1))
    EVT_SWITCH(LW(1))
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, LW(0), 0, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, LW(0), 0, 2)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/UnkBattleFunc2.inc.c"

EvtScript N(80219054) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), 50)
        EVT_SET(LW(1), 0)
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_GOTO(100)
    EVT_END_IF
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzy_Palette_01_Anim_3)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 50)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_EXEC_WAIT(D_8029C12C)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzy_Palette_01_Anim_1)
    EVT_LABEL(100)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzy_Palette_01_Anim_4)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 9, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 8, 0)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_IGNORE_DEFENSE, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 5)
            EVT_SET(LW(1), 0)
            EVT_SUB(LW(2), 5)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzy_Palette_01_Anim_5)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 11, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzy_Palette_01_Anim_9)
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
            EVT_WAIT_FRAMES(4)
            EVT_WAIT_FRAMES(5)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT_FRAMES(5)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzy_Palette_01_Anim_3)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_EXEC_WAIT(D_8029C12C)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(HIT_RESULT_HIT_STATIC)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_FLAG(LW(0), STATUS_FLAG_STATIC)
                EVT_SET(LF(0), 0)
            EVT_ELSE
                EVT_SET(LF(0), 1)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, -3, -12, -15)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzy_Palette_01_Anim_5)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_IF_EQ(LF(0), 1)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 0, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_RETURN
    EVT_END_IF
    EVT_WAIT_FRAMES(10)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x03000C)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3E0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzy_Palette_01_Anim_7)
    EVT_WAIT_FRAMES(21)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzy_Palette_01_Anim_0)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 330)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x3E0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -3, -2, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9), EVT_FLOAT(1.2), EVT_FLOAT(1.0))
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.8), EVT_FLOAT(1.3), EVT_FLOAT(1.0))
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.5), EVT_FLOAT(1.0))
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.6), EVT_FLOAT(1.6), EVT_FLOAT(1.0))
    EVT_WAIT_FRAMES(10)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(10), DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzy_Palette_01_Anim_1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(GetLastDamage, ACTOR_PLAYER, LW(3))
    EVT_IF_NE(LW(3), 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x206D)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x214)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 10)
        EVT_CALL(N(UnkBattleFunc2), LW(0), LW(1), LW(2), LW(3))
        EVT_THREAD
            EVT_WAIT_FRAMES(15)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_25C)
            EVT_CALL(N(UnkBattleFunc2_2), LW(0), LW(1), LW(2), LW(3))
        EVT_END_THREAD
        EVT_ADD(LW(0), 20)
        EVT_ADD(LW(1), 20)
        EVT_CALL(PlayEffect, EFFECT_RECOVER, 0, LW(0), LW(1), LW(2), LW(3), 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(GetActorHP, ACTOR_SELF, LW(0))
        EVT_ADD(LW(0), LW(3))
        EVT_CALL(SetEnemyHP, ACTOR_SELF, LW(0))
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.6), EVT_FLOAT(0.6), EVT_FLOAT(1.0))
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 10, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 330)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.5), EVT_FLOAT(1.0))
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 300)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 270)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(0.7), EVT_FLOAT(1.0))
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 240)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 210)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.7), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 180)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(0.7), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(2)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.2), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 40)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.4), EVT_FLOAT(0.2), EVT_FLOAT(1.0))
    EVT_WAIT_FRAMES(1)
    EVT_THREAD
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.2), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 150)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 120)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 90)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 60)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 30)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 30)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(YieldTurn)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzy_Palette_01_Anim_3)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_EXEC_WAIT(D_8029C12C)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_fuzzy_Palette_01_Anim_1)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021A0D4) = {
    EVT_SET(LF(1), 0)
    EVT_SET(LF(2), 0)
    EVT_SET(LF(3), 0)
    EVT_SET(LF(4), 0)
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
    EVT_SET(LW(10), -1)
    EVT_SET(LW(11), -1)
    EVT_CALL(GetIndexFromHome, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_IF_EQ(LF(2), 0)
                EVT_SET(LW(10), 1)
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_IF_EQ(LF(1), 0)
                EVT_SET(LW(10), 0)
            EVT_END_IF
            EVT_IF_EQ(LF(3), 0)
                EVT_IF_EQ(LW(10), -1)
                    EVT_SET(LW(10), 2)
                EVT_ELSE
                    EVT_SET(LW(11), 2)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_IF_EQ(LF(2), 0)
                EVT_SET(LW(10), 1)
            EVT_END_IF
            EVT_IF_EQ(LF(4), 0)
                EVT_IF_EQ(LW(10), -1)
                    EVT_SET(LW(10), 3)
                EVT_ELSE
                    EVT_SET(LW(11), 3)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_IF_EQ(LF(3), 0)
                EVT_SET(LW(10), 2)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_IF_NE(LW(11), -1)
        EVT_CALL(RandInt, 1000, LW(0))
        EVT_IF_LT(LW(0), 500)
            EVT_SET(LW(10), LW(11))
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(8021A45C) = {
    EVT_SET(LW(9), 0)
    EVT_CALL(EnemyCreateTargetList, 32770)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LW(0), LW(1))
    EVT_CALL(GetOriginalActorType, LW(0), LW(2))
    EVT_SWITCH(LW(2))
        EVT_CASE_OR_EQ(ACTOR_TYPE_FOREST_FUZZY)
        EVT_CASE_OR_EQ(ACTOR_TYPE_JUNGLE_FUZZY)
            EVT_CALL(GetStatusFlags, LW(0), LW(3))
            EVT_IF_NOT_FLAG(LW(3), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(GetActorVar, LW(0), 0, LW(3))
                EVT_IF_NE(LW(3), 2)
                    EVT_ADD(LW(9), 1)
                EVT_END_IF
            EVT_END_IF
        EVT_END_CASE_GROUP
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

EvtScript N(takeTurn_8021A61C) = {
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
        EVT_EXEC_WAIT(N(80219054))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_IF_EQ(LW(0), 2)
        EVT_EXEC_WAIT(N(80219054))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(8021A0D4))
    EVT_IF_EQ(LW(10), -1)
        EVT_EXEC_WAIT(N(80219054))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(8021A45C))
    EVT_SWITCH(LW(9))
        EVT_CASE_EQ(1)
            EVT_CALL(RandInt, 1000, LW(0))
            EVT_IF_LT(LW(0), 300)
                EVT_EXEC_WAIT(N(80218C48))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_CALL(RandInt, 1000, LW(0))
            EVT_IF_LT(LW(0), 150)
                EVT_EXEC_WAIT(N(80218C48))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_CALL(RandInt, 1000, LW(0))
            EVT_IF_LT(LW(0), 100)
                EVT_EXEC_WAIT(N(80218C48))
                EVT_RETURN
            EVT_END_IF
    EVT_END_SWITCH
    EVT_EXEC_WAIT(N(80219054))
    EVT_RETURN
    EVT_END
};

Vec3i N(vector3D_8021A7F4) = { 0, -1000, 0 };

Formation N(specialFormation_8021A800) = {
    { .actor = &NAMESPACE, .home = { .vec = &N(vector3D_8021A7F4) }},
};
