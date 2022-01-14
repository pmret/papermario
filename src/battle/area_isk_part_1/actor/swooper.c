#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/swooper.h"

#define NAMESPACE b_area_isk_part_1_swooper

extern s32 N(idleAnimations_8021C5B4)[];
extern EvtSource N(init_8021C64C);
extern EvtSource N(takeTurn_8021DED4);
extern EvtSource N(idle_8021C6B0);
extern EvtSource N(handleEvent_8021D064);

s32 N(defenseTable_8021C4B0)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_8021C4BC)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 80,
    STATUS_POISON, 60,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 0,
    STATUS_STATIC, 80,
    STATUS_PARALYZE, 90,
    STATUS_SHRINK, 90,
    STATUS_STOP, 90,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 1,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_8021C568)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 29 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_8021C5B4),
        .defenseTable = N(defenseTable_8021C4B0),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 271,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_HP_OFFSET_BELOW,
    .type = ACTOR_TYPE_SWOOPER,
    .level = 10,
    .maxHP = 4,
    .partCount = ARRAY_COUNT(N(partsTable_8021C568)),
    .partsData = N(partsTable_8021C568),
    .script = N(init_8021C64C),
    .statusTable = N(statusTable_8021C4BC),
    .escapeChance = 50,
    .airLiftChance = 100,
    .spookChance = 95,
    .baseStatusChance = 90,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 1,
    .size = { 31, 24 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, -20 },
    .statusMessageOffset = { 10, -20 },
};

s32 N(idleAnimations_8021C5B4)[] = {
    STATUS_NORMAL,    NPC_ANIM_swooper_Palette_00_Anim_C,
    STATUS_STONE,     NPC_ANIM_swooper_Palette_00_Anim_B,
    STATUS_SLEEP,     NPC_ANIM_swooper_Palette_00_Anim_F,
    STATUS_POISON,    NPC_ANIM_swooper_Palette_00_Anim_C,
    STATUS_STOP,      NPC_ANIM_swooper_Palette_00_Anim_B,
    STATUS_STATIC,    NPC_ANIM_swooper_Palette_00_Anim_C,
    STATUS_PARALYZE,  NPC_ANIM_swooper_Palette_00_Anim_B,
    STATUS_DIZZY,     NPC_ANIM_swooper_Palette_00_Anim_10,
    STATUS_FEAR,      NPC_ANIM_swooper_Palette_00_Anim_10,
    STATUS_END,
};

s32 N(idleAnimations_8021C600)[] = {
    STATUS_NORMAL,    NPC_ANIM_swooper_Palette_00_Anim_2,
    STATUS_STONE,     NPC_ANIM_swooper_Palette_00_Anim_1,
    STATUS_SLEEP,     NPC_ANIM_swooper_Palette_00_Anim_13,
    STATUS_POISON,    NPC_ANIM_swooper_Palette_00_Anim_2,
    STATUS_STOP,      NPC_ANIM_swooper_Palette_00_Anim_1,
    STATUS_STATIC,    NPC_ANIM_swooper_Palette_00_Anim_2,
    STATUS_PARALYZE,  NPC_ANIM_swooper_Palette_00_Anim_1,
    STATUS_DIZZY,     NPC_ANIM_swooper_Palette_00_Anim_14,
    STATUS_FEAR,      NPC_ANIM_swooper_Palette_00_Anim_14,
    STATUS_END,
};

#include "common/UnkBattleFunc1.inc.c"

EvtSource N(init_8021C64C) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021DED4)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_8021C6B0)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_8021D064)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(idle_8021C6B0) = {
    EVT_RETURN
    EVT_END
};

EvtSource N(8021C6C0) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_swooper_Palette_00_Anim_2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 0, -24, 0)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 11)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_HP_OFFSET_BELOW, 1)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021C5B4)))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_swooper_Palette_00_Anim_C)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(1), 24)
            EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_swooper_Palette_00_Anim_2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, 11)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtSource N(8021C880) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_17)
            EVT_SET_CONST(LW(2), NPC_ANIM_swooper_Palette_00_Anim_18)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_17)
            EVT_SET_CONST(LW(2), NPC_ANIM_swooper_Palette_00_Anim_18)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_18)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(func_80269470)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_EXEC_WAIT(N(8021C6C0))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(func_80269470)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_THREAD
                EVT_WAIT_FRAMES(30)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_END_THREAD
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_2)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_2)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 0)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_2)
            EVT_SET_CONST(LW(2), NPC_ANIM_swooper_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_2)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(8021CD04) = {
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(GetLastDamage, ACTOR_SELF, LW(0))
    EVT_IF_LE(LW(0), 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_HP_OFFSET_BELOW, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_swooper_Palette_00_Anim_2)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(1), 24)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(10))
    EVT_IF_EQ(LW(10), -1)
        EVT_CALL(SetHomePos, ACTOR_SELF, LW(0), 45, LW(2))
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.80078125))
        EVT_CALL(SetGoalToHome, ACTOR_SELF)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
    EVT_ELSE
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.80078125))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 45, LW(2))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
        EVT_CALL(GetIndexFromPos, ACTOR_SELF, LW(10))
        EVT_MOD(LW(10), 4)
        EVT_ADD(LW(10), 4)
        EVT_CALL(SetGoalToIndex, ACTOR_SELF, LW(10))
        EVT_CALL(GetGoalPos, ACTOR_SELF, LW(10), LW(11), LW(12))
        EVT_CALL(SetHomePos, ACTOR_SELF, LW(10), LW(11), LW(12))
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.80078125))
        EVT_CALL(SetGoalToHome, ACTOR_SELF)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
    EVT_END_IF
    EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 0, -10)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 0, 22)
    EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021C600)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 1)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
    EVT_RETURN
    EVT_END
};

EvtSource N(handleEvent_8021D064) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_EXEC_WAIT(N(8021C880))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(GetBattlePhase, LW(0))
            EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_15)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_E)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_HIT)
            EVT_CALL(GetBattlePhase, LW(0))
            EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_15)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_E)
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_EXEC_WAIT(N(8021CD04))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(GetBattlePhase, LW(0))
            EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_17)
                EVT_SET_CONST(LW(2), NPC_ANIM_swooper_Palette_00_Anim_18)
                EVT_EXEC_WAIT(DoBurnHit)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_11)
                EVT_SET_CONST(LW(2), NPC_ANIM_swooper_Palette_00_Anim_12)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_EXEC_WAIT(N(8021CD04))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_CALL(GetBattlePhase, LW(0))
            EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_17)
                EVT_SET_CONST(LW(2), NPC_ANIM_swooper_Palette_00_Anim_18)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_18)
                EVT_EXEC_WAIT(DoDeath)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_11)
                EVT_SET_CONST(LW(2), NPC_ANIM_swooper_Palette_00_Anim_12)
                EVT_EXEC_WAIT(DoBurnHit)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_12)
                EVT_EXEC_WAIT(DoDeath)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(func_80269470)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_15)
            EVT_EXEC_WAIT(D_8029A76C)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_EXEC_WAIT(N(8021C6C0))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(func_80269470)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_15)
            EVT_EXEC_WAIT(D_8029A76C)
            EVT_THREAD
                EVT_WAIT_FRAMES(30)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_END_THREAD
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(GetBattlePhase, LW(0))
            EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_15)
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_WAIT_FRAMES(10)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_15)
                EVT_EXEC_WAIT(DoDeath)
            EVT_ELSE
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_E)
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_WAIT_FRAMES(10)
                EVT_SET_CONST(LW(0), 1)
                EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_E)
                EVT_EXEC_WAIT(DoDeath)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_HP_OFFSET_BELOW, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_8021C600)))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_swooper_Palette_00_Anim_2)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(8021C6C0))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, 1)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_HP_OFFSET_BELOW, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -24, 0)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_swooper_Palette_00_Anim_2)
            EVT_SET_CONST(LW(2), NPC_ANIM_swooper_Palette_00_Anim_15)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(8021D7E4) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_swooper_Palette_00_Anim_2)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
        EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_swooper_Palette_00_Anim_2)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
        EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, 0)
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 2, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.80078125))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_swooper_Palette_00_Anim_6)
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 50)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_swooper_Palette_00_Anim_6)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(10.0))
            EVT_WAIT_FRAMES(15)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(YieldTurn)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_EXEC_WAIT(N(8021C6C0))
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
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.80078125))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_swooper_Palette_00_Anim_6)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_swooper_Palette_00_Anim_6)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_swooper_Palette_00_Anim_2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(YieldTurn)
    EVT_EXEC_WAIT(N(8021C6C0))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtSource N(takeTurn_8021DED4) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_EXEC_WAIT(N(8021D7E4))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_swooper_Palette_00_Anim_2)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_HP_OFFSET_BELOW, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(1), 24)
    EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 2, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.80078125))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_swooper_Palette_00_Anim_6)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(AddGoalPos, ACTOR_SELF, -50, 0, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_swooper_Palette_00_Anim_6)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -40, 0)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(10.0))
            EVT_WAIT_FRAMES(15)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(YieldTurn)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_EXEC_WAIT(N(8021C6C0))
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
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.80078125))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_swooper_Palette_00_Anim_6)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_swooper_Palette_00_Anim_6)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -40, 0)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), 0, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_swooper_Palette_00_Anim_2)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, 0)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(YieldTurn)
    EVT_EXEC_WAIT(N(8021C6C0))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
