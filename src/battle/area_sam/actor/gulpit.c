#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/gulpit.h"

#define NAMESPACE b_area_sam_gulpit

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);

s32 N(idleAnimations1)[] = {
    STATUS_NORMAL, NPC_ANIM_gulpit_Palette_00_Anim_1,
    STATUS_STONE, NPC_ANIM_gulpit_Palette_00_Anim_0,
    STATUS_SLEEP, NPC_ANIM_gulpit_Palette_00_Anim_F,
    STATUS_POISON, NPC_ANIM_gulpit_Palette_00_Anim_1,
    STATUS_STOP, NPC_ANIM_gulpit_Palette_00_Anim_0,
    STATUS_STATIC, NPC_ANIM_gulpit_Palette_00_Anim_1,
    STATUS_PARALYZE, NPC_ANIM_gulpit_Palette_00_Anim_0,
    STATUS_DIZZY, NPC_ANIM_gulpit_Palette_00_Anim_E,
    STATUS_FEAR, NPC_ANIM_gulpit_Palette_00_Anim_E,
    STATUS_END,
};

s32 N(idleAnimations2)[] = {
    STATUS_NORMAL, NPC_ANIM_gulpit_Palette_00_Anim_10,
    STATUS_END,
};

s32 N(idleAnimations3)[] = {
    STATUS_NORMAL, NPC_ANIM_gulpit_Palette_00_Anim_12,
    STATUS_END,
};

s32 N(defenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 60,
    STATUS_POISON, 80,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 0,
    STATUS_STATIC, 10,
    STATUS_PARALYZE, 80,
    STATUS_SHRINK, 75,
    STATUS_STOP, 85,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 1,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -7, 48 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations1),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = -3,
        .unk_1D = -23,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations2),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations3),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GULPIT,
    .level = 22,
    .maxHP = 12,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .script = &N(init),
    .statusTable = N(statusTable),
    .escapeChance = 60,
    .airLiftChance = 50,
    .spookChance = 50,
    .baseStatusChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 53, 50 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -3, 37 },
    .statusMessageOffset = { 10, 45 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome) = {
    EVT_SET_CONST(LocalVar(0), 1)
    EVT_SET_CONST(LocalVar(1), NPC_ANIM_gulpit_Palette_00_Anim_3)
    EVT_EXEC_WAIT(DoReturnHome)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_gulpit_Palette_00_Anim_1)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_gulpit_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_gulpit_Palette_00_Anim_C)
            EVT_SET_CONST(LocalVar(2), NPC_ANIM_gulpit_Palette_00_Anim_D)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_gulpit_Palette_00_Anim_C)
            EVT_SET_CONST(LocalVar(2), NPC_ANIM_gulpit_Palette_00_Anim_D)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_gulpit_Palette_00_Anim_D)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_gulpit_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_gulpit_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_gulpit_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_gulpit_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_gulpit_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_gulpit_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_gulpit_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_gulpit_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_gulpit_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_gulpit_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_gulpit_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_gulpit_Palette_00_Anim_3)
            EVT_SET_CONST(LocalVar(2), NPC_ANIM_gulpit_Palette_00_Anim_B)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_gulpit_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_gulpit_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoBlowAway)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attack_lick) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(GetBattlePhase, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), PHASE_FIRST_STRIKE)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(0), 80)
        EVT_SET(LocalVar(1), 0)
        EVT_CALL(SetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_gulpit_Palette_00_Anim_3)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
    EVT_IF_FLAG(LocalVar(0), STATUS_FLAG_SHRINK)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 10, 0, 0)
    EVT_ELSE
        EVT_CALL(AddGoalPos, ACTOR_SELF, 20, 0, 0)
    EVT_END_IF
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_gulpit_Palette_00_Anim_1)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EE)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_gulpit_Palette_00_Anim_4)
    EVT_WAIT(9)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LocalVar(10), LocalVar(0))
            EVT_IF_EQ(LocalVar(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), 0, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_WAIT(10)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attack_rock) = {
    EVT_SET(LocalVar(10), LocalVar(0))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(GetActorPos, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 20)
    EVT_SUB(LocalVar(2), 1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_gulpit_Palette_00_Anim_2)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_gulpit_Palette_00_Anim_1)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20EE)
    EVT_CALL(GetActorVar, LocalVar(10), 0, LocalVar(0))
    EVT_SET(LocalVar(11), LocalVar(0))
    EVT_SWITCH(LocalVar(11))
        EVT_CASE_EQ(0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_gulpit_Palette_00_Anim_5)
            EVT_WAIT(3)
            EVT_CALL(RemoveActor, LocalVar(10))
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_gulpit_Palette_00_Anim_6)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_gulpit_Palette_00_Anim_7)
            EVT_SET(LocalVar(10), 2)
        EVT_CASE_EQ(1)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_gulpit_Palette_00_Anim_8)
            EVT_WAIT(3)
            EVT_CALL(RemoveActor, LocalVar(10))
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_gulpit_Palette_00_Anim_9)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_gulpit_Palette_00_Anim_A)
            EVT_SET(LocalVar(10), 3)
    EVT_END_SWITCH
    EVT_CALL(SetPartSounds, ACTOR_SELF, LocalVar(10), 2, 985, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LocalVar(9), LocalVar(0))
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LocalVar(10), ACTOR_PART_FLAG_INVISIBLE, 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_ADD(LocalVar(1), 20)
            EVT_ADD(LocalVar(2), 2)
            EVT_CALL(SetPartPos, ACTOR_SELF, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -100, 0, 5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LocalVar(10), EVT_FLOAT(14.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LocalVar(10), EVT_FLOAT(0.01))
            EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(JumpPartTo, ACTOR_SELF, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2), 0, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LocalVar(10), ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_IF_EQ(LocalVar(9), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LocalVar(10), ACTOR_PART_FLAG_INVISIBLE, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(1), 20)
    EVT_ADD(LocalVar(2), 2)
    EVT_CALL(SetPartPos, ACTOR_SELF, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LocalVar(10), EVT_FLOAT(14.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LocalVar(10), EVT_FLOAT(0.01))
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpPartTo, ACTOR_SELF, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2), 0, 1)
    EVT_SWITCH(LocalVar(10))
        EVT_CASE_EQ(2)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 7, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(3)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_SWITCH
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_gulpit_Palette_00_Anim_1)
            EVT_CALL(GetPartOffset, ACTOR_SELF, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_ADD(LocalVar(0), -100)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LocalVar(10), EVT_FLOAT(1.0))
            EVT_CALL(JumpPartTo, ACTOR_SELF, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2), 25, 1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LocalVar(10), ACTOR_PART_FLAG_INVISIBLE, 1)
            EVT_WAIT(10)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetBattlePhase, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), PHASE_FIRST_STRIKE)
        EVT_EXEC_WAIT(N(attack_lick))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(0))
    EVT_IF_FLAG(LocalVar(0), STATUS_FLAG_SHRINK)
        EVT_EXEC_WAIT(N(attack_lick))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LocalVar(10), 0)
    EVT_CALL(EnemyCreateTargetList, 65538)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LocalVar(0), LocalVar(1))
    EVT_CALL(GetOriginalActorType, LocalVar(0), LocalVar(2))
    EVT_IF_EQ(LocalVar(2), ACTOR_TYPE_GULPIT_ROCKS)
        EVT_ADD(LocalVar(10), 1)
        EVT_SWITCH(LocalVar(10))
            EVT_CASE_EQ(1)
                EVT_SET(LocalVar(11), LocalVar(0))
            EVT_CASE_EQ(2)
                EVT_SET(LocalVar(12), LocalVar(0))
            EVT_CASE_EQ(3)
                EVT_SET(LocalVar(13), LocalVar(0))
        EVT_END_SWITCH
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_IF_NE(LocalVar(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_SWITCH(LocalVar(10))
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(attack_lick))
        EVT_CASE_EQ(1)
            EVT_SET(LocalVar(0), LocalVar(11))
            EVT_EXEC_WAIT(N(attack_rock))
        EVT_CASE_EQ(2)
            EVT_CALL(RandInt, 1, LocalVar(0))
            EVT_SWITCH(LocalVar(0))
                EVT_CASE_EQ(0)
                    EVT_SET(LocalVar(0), LocalVar(11))
                EVT_CASE_EQ(1)
                    EVT_SET(LocalVar(0), LocalVar(12))
            EVT_END_SWITCH
            EVT_EXEC_WAIT(N(attack_rock))
        EVT_CASE_GE(3)
            EVT_CALL(RandInt, 2, LocalVar(0))
            EVT_SWITCH(LocalVar(0))
                EVT_CASE_EQ(0)
                    EVT_SET(LocalVar(0), LocalVar(11))
                EVT_CASE_EQ(1)
                    EVT_SET(LocalVar(0), LocalVar(12))
                EVT_CASE_EQ(2)
                    EVT_SET(LocalVar(0), LocalVar(13))
            EVT_END_SWITCH
            EVT_EXEC_WAIT(N(attack_rock))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

