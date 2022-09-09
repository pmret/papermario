#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/duplighost.h"

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(nextTurn);

s32 N(idleAnimations)[] = {
    STATUS_NORMAL, NPC_ANIM_duplighost_Palette_00_Anim_2,
    STATUS_STONE, NPC_ANIM_duplighost_Palette_00_Anim_0,
    STATUS_SLEEP, NPC_ANIM_duplighost_Palette_00_Anim_D,
    STATUS_POISON, NPC_ANIM_duplighost_Palette_00_Anim_2,
    STATUS_STOP, NPC_ANIM_duplighost_Palette_00_Anim_0,
    STATUS_STATIC, NPC_ANIM_duplighost_Palette_00_Anim_2,
    STATUS_PARALYZE, NPC_ANIM_duplighost_Palette_00_Anim_0,
    STATUS_DIZZY, NPC_ANIM_duplighost_Palette_00_Anim_E,
    STATUS_FEAR, NPC_ANIM_duplighost_Palette_00_Anim_E,
    STATUS_END,
};

s32 N(idleAnimations2)[] = {
    STATUS_NORMAL, NPC_ANIM_duplighost_Palette_00_Anim_A,
    STATUS_END,
};

s32 N(idleAnimations3)[] = {
    STATUS_NORMAL, NPC_ANIM_duplighost_Palette_00_Anim_4,
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
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 0,
    STATUS_STATIC, 75,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 75,
    STATUS_STOP, 80,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 1,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 25 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = -2,
        .unk_1D = -10,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_DUPLIGHOST,
    .level = 23,
    .maxHP = 15,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .script = &N(init),
    .statusTable = N(statusTable),
    .escapeChance = 50,
    .airLiftChance = 80,
    .spookChance = 70,
    .baseStatusChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 2,
    .size = { 36, 36 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_ADDR(N(nextTurn)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn) = {
    EVT_CALL(GetBattlePhase, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_END)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LocalVar(0))
            EVT_IF_EQ(LocalVar(0), 3)
                EVT_CALL(SetActorVar, ACTOR_SELF, 8, 2)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome) = {
    EVT_SET_CONST(LocalVar(0), 1)
    EVT_SET_CONST(LocalVar(1), NPC_ANIM_duplighost_Palette_00_Anim_4)
    EVT_EXEC_WAIT(DoReturnHome)
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
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_duplighost_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_duplighost_Palette_00_Anim_C)
            EVT_SET_CONST(LocalVar(2), -1)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_duplighost_Palette_00_Anim_C)
            EVT_SET_CONST(LocalVar(2), -1)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_duplighost_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_duplighost_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_duplighost_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_duplighost_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_duplighost_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_duplighost_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_duplighost_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_duplighost_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_duplighost_Palette_00_Anim_2)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_duplighost_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_duplighost_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_duplighost_Palette_00_Anim_2)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_duplighost_Palette_00_Anim_4)
            EVT_SET_CONST(LocalVar(2), NPC_ANIM_duplighost_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_duplighost_Palette_00_Anim_4)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_duplighost_Palette_00_Anim_A)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(attack) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_duplighost_Palette_00_Anim_7)
    EVT_WAIT(20)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 715, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LocalVar(10), LocalVar(0))
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_duplighost_Palette_00_Anim_8)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -100, 0, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 17, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LocalVar(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(SetActorPos, ACTOR_SELF, LocalVar(0), 0, LocalVar(2))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_duplighost_Palette_00_Anim_2)
            EVT_CALL(ResetActorSounds, ACTOR_SELF, 2)
            EVT_WAIT(15)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_duplighost_Palette_00_Anim_8)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(10))
    EVT_IF_FLAG(LocalVar(10), STATUS_FLAG_SHRINK)
        EVT_CALL(AddGoalPos, ACTOR_SELF, EVT_FLOAT(4.0), EVT_FLOAT(-6.0), 0)
    EVT_ELSE
        EVT_CALL(AddGoalPos, ACTOR_SELF, 10, -15, 0)
    EVT_END_IF
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), 0, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(ResetActorSounds, ACTOR_SELF, 2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_duplighost_Palette_00_Anim_9)
            EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_ADD(LocalVar(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), 0, LocalVar(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_ADD(LocalVar(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), 0, LocalVar(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
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

EvtScript N(OnDeath) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LocalVar(0))
    EVT_CALL(RemoveActor, LocalVar(0))
    EVT_RETURN
    EVT_END
};

EvtScript N(OnHitElectric) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(1))
    EVT_WAIT(30)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LocalVar(10))
    EVT_CALL(UseIdleAnimation, LocalVar(10), FALSE)
    EVT_CALL(func_8027D32C, LocalVar(10))
    EVT_CALL(CopyStatusEffects, ACTOR_SELF, LocalVar(10))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMOKE_BURST)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(1), 3)
        EVT_ADD(LocalVar(2), 5)
        EVT_LOOP(3)
            EVT_CALL(PlayEffect, EFFECT_BIG_SMOKE_PUFF, LocalVar(0), LocalVar(1), LocalVar(2), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(GetActorHP, ACTOR_SELF, LocalVar(11))
    EVT_CALL(SetEnemyHP, LocalVar(10), LocalVar(11))
    EVT_CALL(CopyBuffs, ACTOR_SELF, LocalVar(10))
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(11), LocalVar(12), LocalVar(13))
    EVT_CALL(SetActorPos, LocalVar(10), LocalVar(11), LocalVar(12), LocalVar(13))
    EVT_CALL(SetPartFlagBits, LocalVar(10), 1, ACTOR_PART_FLAG_MULTI_TARGET, 1)
    EVT_CALL(SetPartFlagBits, LocalVar(10), 1, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, 0)
    EVT_CALL(SetActorFlagBits, LocalVar(10), ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_DMG_APPLY, 0)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 1)
    EVT_CALL(SetActorVar, LocalVar(10), 8, 2)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LocalVar(0), ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_CALL(SetIdleAnimations, LocalVar(10), 1, EVT_ADDR(N(idleAnimations2)))
    EVT_CALL(SetAnimation, LocalVar(10), 1, NPC_ANIM_duplighost_Palette_00_Anim_A)
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(GetActorPos, LocalVar(10), LocalVar(11), LocalVar(12), LocalVar(13))
    EVT_IF_GT(LocalVar(12), 0)
        EVT_SET(LocalVar(12), 0)
        EVT_CALL(SetActorJumpGravity, LocalVar(10), EVT_FLOAT(0.5))
        EVT_CALL(SetActorSounds, LocalVar(10), 2, 769, 0)
        EVT_CALL(SetGoalPos, LocalVar(10), LocalVar(11), LocalVar(12), LocalVar(13))
        EVT_CALL(JumpToGoal, LocalVar(10), 15, FALSE, TRUE, FALSE)
        EVT_CALL(ResetActorSounds, LocalVar(10), 2)
        EVT_CALL(SetGoalPos, LocalVar(10), LocalVar(11), LocalVar(12), LocalVar(13))
        EVT_CALL(JumpToGoal, LocalVar(10), 10, FALSE, TRUE, FALSE)
        EVT_CALL(SetGoalPos, LocalVar(10), LocalVar(11), LocalVar(12), LocalVar(13))
        EVT_CALL(JumpToGoal, LocalVar(10), 5, FALSE, TRUE, FALSE)
    EVT_END_IF
    EVT_CALL(ForceHomePos, LocalVar(10), LocalVar(11), LocalVar(12), LocalVar(13))
    EVT_CALL(HPBarToHome, LocalVar(10))
    EVT_CALL(SetIdleAnimations, LocalVar(10), 1, EVT_ADDR(N(idleAnimations)))
    EVT_CALL(SetAnimation, LocalVar(10), 1, NPC_ANIM_duplighost_Palette_00_Anim_2)
    EVT_CALL(SetActorPos, ACTOR_SELF, 0, -1000, 0)
    EVT_CALL(ForceHomePos, ACTOR_SELF, 0, -1000, 0)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(OnShockHit) = {
    EVT_SET(LocalVar(9), LocalVar(0))
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(0), LocalVar(1))
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(2), LocalVar(3), LocalVar(4))
    EVT_ADD(LocalVar(2), 10)
    EVT_ADD(LocalVar(3), 10)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(2), LocalVar(3), LocalVar(4))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_EXEC_WAIT(DoShockHit)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LocalVar(10))
    EVT_CALL(UseIdleAnimation, LocalVar(10), FALSE)
    EVT_CALL(func_8027D32C, LocalVar(10))
    EVT_CALL(CopyStatusEffects, ACTOR_SELF, LocalVar(10))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMOKE_BURST)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(1), 3)
        EVT_ADD(LocalVar(2), 5)
        EVT_LOOP(3)
            EVT_CALL(PlayEffect, EFFECT_BIG_SMOKE_PUFF, LocalVar(0), LocalVar(1), LocalVar(2), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(GetActorHP, ACTOR_SELF, LocalVar(11))
    EVT_CALL(SetEnemyHP, LocalVar(10), LocalVar(11))
    EVT_CALL(CopyBuffs, ACTOR_SELF, LocalVar(10))
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(11), LocalVar(12), LocalVar(13))
    EVT_CALL(SetActorPos, LocalVar(10), LocalVar(11), LocalVar(12), LocalVar(13))
    EVT_CALL(SetPartFlagBits, LocalVar(10), 1, ACTOR_PART_FLAG_MULTI_TARGET, 1)
    EVT_CALL(SetPartFlagBits, LocalVar(10), 1, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, 0)
    EVT_CALL(SetActorFlagBits, LocalVar(10), ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_DMG_APPLY, 0)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 1)
    EVT_CALL(SetActorVar, LocalVar(10), 8, 3)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LocalVar(9), ACTOR_PART_FLAG_INVISIBLE, 1)
    EVT_CALL(SetIdleAnimations, LocalVar(10), 1, EVT_ADDR(N(idleAnimations2)))
    EVT_CALL(SetAnimation, LocalVar(10), 1, NPC_ANIM_duplighost_Palette_00_Anim_A)
    EVT_WAIT(15)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(SetActorJumpGravity, LocalVar(10), EVT_FLOAT(0.5))
    EVT_CALL(GetActorPos, LocalVar(10), LocalVar(11), LocalVar(12), LocalVar(13))
    EVT_ADD(LocalVar(11), 30)
    EVT_SET(LocalVar(12), 0)
    EVT_CALL(SetGoalPos, LocalVar(10), LocalVar(11), LocalVar(12), LocalVar(13))
    EVT_CALL(JumpToGoal, LocalVar(10), 15, FALSE, TRUE, FALSE)
    EVT_ADD(LocalVar(11), 20)
    EVT_CALL(SetGoalPos, LocalVar(10), LocalVar(11), LocalVar(12), LocalVar(13))
    EVT_CALL(JumpToGoal, LocalVar(10), 10, FALSE, TRUE, FALSE)
    EVT_ADD(LocalVar(11), 10)
    EVT_CALL(SetGoalPos, LocalVar(10), LocalVar(11), LocalVar(12), LocalVar(13))
    EVT_CALL(JumpToGoal, LocalVar(10), 5, FALSE, TRUE, FALSE)
    EVT_WAIT(20)
    EVT_CALL(AddActorDecoration, LocalVar(10), 1, 0, 2)
    EVT_CALL(SetActorYaw, LocalVar(10), 180)
    EVT_CALL(SetIdleAnimations, LocalVar(10), 1, EVT_ADDR(N(idleAnimations3)))
    EVT_CALL(SetAnimation, LocalVar(10), 1, NPC_ANIM_duplighost_Palette_00_Anim_4)
    EVT_CALL(SetActorSpeed, LocalVar(10), EVT_FLOAT(8.0))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(11), LocalVar(12), LocalVar(13))
    EVT_CALL(SetGoalPos, LocalVar(10), LocalVar(11), 0, LocalVar(13))
    EVT_CALL(RunToGoal, LocalVar(10), 0, FALSE)
    EVT_CALL(SetAnimation, LocalVar(10), 1, NPC_ANIM_duplighost_Palette_00_Anim_2)
    EVT_CALL(SetActorYaw, LocalVar(10), 0)
    EVT_CALL(RemoveActorDecoration, LocalVar(10), 1, 0)
    EVT_CALL(SetIdleAnimations, LocalVar(10), 1, EVT_ADDR(N(idleAnimations)))
    EVT_CALL(ForceHomePos, LocalVar(10), LocalVar(11), 0, LocalVar(13))
    EVT_CALL(HPBarToHome, LocalVar(10))
    EVT_CALL(SetActorPos, ACTOR_SELF, 0, -1000, 0)
    EVT_CALL(ForceHomePos, ACTOR_SELF, 0, -1000, 0)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(OnShockDeath) = {
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_SET(LocalVar(10), LocalVar(0))
    EVT_SET(LocalVar(11), LocalVar(1))
    EVT_SET(LocalVar(12), LocalVar(2))
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(10), LocalVar(11))
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 15)
    EVT_ADD(LocalVar(1), 10)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetAnimation, ACTOR_SELF, LocalVar(10), LocalVar(11))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, FALSE, FALSE)
    EVT_SET(LocalVar(0), LocalVar(10))
    EVT_SET(LocalVar(1), LocalVar(11))
    EVT_EXEC_WAIT(DoShockHit)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, LocalVar(12), 0)
        EVT_SET(LocalVar(0), 0)
        EVT_LOOP(15)
            EVT_ADD(LocalVar(0), -48)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LocalVar(0))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 60)
    EVT_SET(LocalVar(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_ADD(LocalVar(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_ADD(LocalVar(0), 10)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

Vec3i N(pos_summon) = { 0, -1000, 0 };

#include "ghost_goombario.inc.c"

Formation N(formation_goombario) = {
    { .actor = &N(goombario), .home = { .vec = &N(pos_summon) }, .priority = 0 },
};

#include "ghost_kooper.inc.c"

Formation N(formation_kooper) = {
    { .actor = &N(kooper), .home = { .vec = &N(pos_summon) }, .priority = 0 },
};

#include "ghost_bombette.inc.c"

Formation N(formation_bombette) = {
    { .actor = &N(bombette), .home = { .vec = &N(pos_summon) }, .priority = 0 },
};

#include "ghost_parakarry.inc.c"

Formation N(formation_parakarry) = {
    { .actor = &N(parakarry), .home = { .vec = &N(pos_summon) }, .priority = 0 },
};

#include "ghost_bow.inc.c"

Formation N(formation_bow) = {
    { .actor = &N(bow), .home = { .vec = &N(pos_summon) }, .priority = 0 },
};

#include "ghost_watt.inc.c"

Formation N(formation_watt) = {
    { .actor = &N(watt), .home = { .vec = &N(pos_summon) }, .priority = 0 },
};

#include "ghost_sushie.inc.c"

Formation N(formation_sushie) = {
    { .actor = &N(sushie), .home = { .vec = &N(pos_summon) }, .priority = 0 },
};

#include "ghost_lakilester.inc.c"

Formation N(formation_lakilester) = {
    { .actor = &N(lakilester), .home = { .vec = &N(pos_summon) }, .priority = 0 },
};

ApiStatus N(GetPartnerAndLevel)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gPlayerData.currentPartner);
    evt_set_variable(script, *args++, gPlayerData.partners[gPlayerData.currentPartner].level);
    return ApiStatus_DONE2;
}

ApiStatus N(CopyPriority)(Evt* script, s32 isInitialCall) {
    s32 partnerID = evt_get_variable(script, *script->ptrReadPos);
    Actor* actor = get_actor(script->owner1.actorID);
    FormationRow* formation = NULL;

    switch (partnerID) {
        case PARTNER_GOOMBARIO:
            formation = N(formation_goombario);
            break;
        case PARTNER_KOOPER:
            formation = N(formation_kooper);
            break;
        case PARTNER_BOMBETTE:
            formation = N(formation_bombette);
            break;
        case PARTNER_PARAKARRY:
            formation = N(formation_parakarry);
            break;
        case PARTNER_BOW:
            formation = N(formation_bow);
            break;
        case PARTNER_WATT:
            formation = N(formation_watt);
            break;
        case PARTNER_SUSHIE:
            formation = N(formation_sushie);
            break;
        case PARTNER_LAKILESTER:
            formation = N(formation_lakilester);
            break;
    }

    formation->priority = actor->turnPriority;

    return ApiStatus_DONE2;
}

EvtScript N(copyPartner) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20B8)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_duplighost_Palette_00_Anim_6)
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(10))
    EVT_IF_FLAG(LocalVar(10), STATUS_FLAG_SHRINK)
        EVT_ADD(LocalVar(1), 8)
        EVT_SETF(LocalVar(3), EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_ADD(LocalVar(1), 20)
        EVT_SETF(LocalVar(3), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(PlayEffect, EFFECT_GATHER_ENERGY_PINK, 1, LocalVar(0), LocalVar(1), LocalVar(2), LocalVar(3), 40, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(N(UnkBackgroundFunc3))
    EVT_CALL(MakeLerp, 0, 200, 20, 0)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(N(SetBackgroundAlpha), LocalVar(0))
    EVT_WAIT(1)
    EVT_IF_EQ(LocalVar(1), 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(N(GetPartnerAndLevel), LocalVar(5), LocalVar(6))
    EVT_CALL(N(CopyPriority), LocalVar(5))
    EVT_SWITCH(LocalVar(5))
        EVT_CASE_EQ(1)
            EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_goombario)), 0)
        EVT_CASE_EQ(2)
            EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_kooper)), 0)
        EVT_CASE_EQ(3)
            EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_bombette)), 0)
        EVT_CASE_EQ(4)
            EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_parakarry)), 0)
        EVT_CASE_EQ(9)
            EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_bow)), 0)
        EVT_CASE_EQ(6)
            EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_watt)), 0)
        EVT_CASE_EQ(7)
            EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_sushie)), 0)
        EVT_CASE_EQ(8)
            EVT_CALL(SummonEnemy, EVT_ADDR(N(formation_lakilester)), 0)
    EVT_END_SWITCH
    EVT_SET(LocalVar(10), LocalVar(0))
    EVT_CALL(CopyStatusEffects, ACTOR_SELF, LocalVar(10))
    EVT_CALL(SetBattleVar, 3, LocalVar(5))
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMOKE_BURST)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(1), 3)
        EVT_ADD(LocalVar(2), 5)
        EVT_LOOP(3)
            EVT_CALL(PlayEffect, EFFECT_BIG_SMOKE_PUFF, LocalVar(0), LocalVar(1), LocalVar(2), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetActorPos, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, 1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_MULTI_TARGET, 0)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_DMG_APPLY, 1)
    EVT_CALL(GetActorHP, ACTOR_SELF, LocalVar(0))
    EVT_CALL(SetEnemyHP, LocalVar(10), LocalVar(0))
    EVT_CALL(CopyBuffs, ACTOR_SELF, LocalVar(10))
    EVT_CALL(GetOwnerID, LocalVar(0))
    EVT_CALL(SetActorVar, LocalVar(10), 0, LocalVar(0))
    EVT_CALL(SetActorVar, LocalVar(10), 1, LocalVar(6))
    EVT_WAIT(20)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_THREAD
        EVT_CALL(MakeLerp, 200, 0, 20, 0)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetBackgroundAlpha), LocalVar(0))
        EVT_WAIT(1)
        EVT_IF_EQ(LocalVar(1), 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetActorSounds, LocalVar(10), 2, 0, 0)
    EVT_SWITCH(LocalVar(5))
        EVT_CASE_EQ(8)
            EVT_CALL(GetActorPos, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(SetActorJumpGravity, LocalVar(10), EVT_FLOAT(0.01))
            EVT_CALL(SetGoalPos, LocalVar(10), LocalVar(0), 10, LocalVar(2))
            EVT_CALL(JumpToGoal, LocalVar(10), 10, FALSE, FALSE, FALSE)
            EVT_WAIT(10)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(4)
            EVT_CALL(GetActorPos, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(SetActorJumpGravity, LocalVar(10), EVT_FLOAT(0.01))
            EVT_CALL(SetGoalPos, LocalVar(10), LocalVar(0), 30, LocalVar(2))
            EVT_CALL(JumpToGoal, LocalVar(10), 20, FALSE, FALSE, FALSE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(ForceHomePos, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(HPBarToHome, LocalVar(10))
    EVT_CALL(ResetActorSounds, LocalVar(10), 2)
    EVT_WAIT(20)
    EVT_CALL(SetActorPos, ACTOR_SELF, 0, -1000, 0)
    EVT_CALL(ForceHomePos, ACTOR_SELF, 0, -1000, 0)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_EQ(0)
            EVT_CALL(RandInt, 1000, LocalVar(0))
            EVT_IF_LT(LocalVar(0), 600)
                EVT_CALL(GetBattleVar, 0, LocalVar(0))
                EVT_IF_NOT_FLAG(LocalVar(0), 0x4)
                    EVT_CALL(GetBattleVar, 0, LocalVar(0))
                    EVT_BITWISE_OR_CONST(LocalVar(0), 0x4)
                    EVT_CALL(SetBattleVar, 0, LocalVar(0))
                    EVT_EXEC_WAIT(N(copyPartner))
                EVT_ELSE
                    EVT_CALL(GetBattleVar, 3, LocalVar(0))
                    EVT_CALL(N(GetPartnerAndLevel), LocalVar(1), LocalVar(2))
                    EVT_IF_EQ(LocalVar(0), LocalVar(1))
                        EVT_EXEC_WAIT(N(copyPartner))
                    EVT_ELSE
                        EVT_EXEC_WAIT(N(attack))
                    EVT_END_IF
                EVT_END_IF
            EVT_ELSE
                EVT_EXEC_WAIT(N(attack))
            EVT_END_IF
        EVT_CASE_EQ(1)
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(attack))
        EVT_CASE_EQ(3)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};



