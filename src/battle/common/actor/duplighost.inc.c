#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/Duplighost.h"

extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);
extern EvtScript N(nextTurn);

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL, ANIM_Duplighost_Anim02,
    STATUS_STONE, ANIM_Duplighost_Anim00,
    STATUS_SLEEP, ANIM_Duplighost_Anim0D,
    STATUS_POISON, ANIM_Duplighost_Anim02,
    STATUS_STOP, ANIM_Duplighost_Anim00,
    STATUS_STATIC, ANIM_Duplighost_Anim02,
    STATUS_PARALYZE, ANIM_Duplighost_Anim00,
    STATUS_DIZZY, ANIM_Duplighost_Anim0E,
    STATUS_FEAR, ANIM_Duplighost_Anim0E,
    STATUS_END,
};

s32 N(IdleAnimations2)[] = {
    STATUS_NORMAL, ANIM_Duplighost_Anim0A,
    STATUS_END,
};

s32 N(IdleAnimations3)[] = {
    STATUS_NORMAL, ANIM_Duplighost_Anim04,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
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
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -2, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_DUPLIGHOST,
    .level = 23,
    .maxHP = 15,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 80,
    .hurricaneChance = 70,
    .spookChance = 50,
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
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_END)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
            EVT_IF_EQ(LVar0, 3)
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
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim04)
    EVT_EXEC_WAIT(DoReturnHome)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0C)
            EVT_SET_CONST(LVar2, -1)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0C)
            EVT_SET_CONST(LVar2, -1)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0C)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim02)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim02)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim04)
            EVT_SET_CONST(LVar2, ANIM_Duplighost_Anim0A)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim04)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Duplighost_Anim0A)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Duplighost_Anim07)
    EVT_WAIT(20)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_2CB, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Duplighost_Anim08)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -100, 0, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 17, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(10)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, 0, LVar2)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Duplighost_Anim02)
            EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Duplighost_Anim08)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_CALL(AddGoalPos, ACTOR_SELF, EVT_FLOAT(4.0), EVT_FLOAT(-6.0), 0)
    EVT_ELSE
        EVT_CALL(AddGoalPos, ACTOR_SELF, 10, -15, 0)
    EVT_END_IF
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.3))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Duplighost_Anim09)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
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
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_CALL(RemoveActor, LVar0)
    EVT_RETURN
    EVT_END
};

EvtScript N(OnHitElectric) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_WAIT(30)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
    EVT_CALL(UseIdleAnimation, LVarA, FALSE)
    EVT_CALL(func_8027D32C, LVarA)
    EVT_CALL(CopyStatusEffects, ACTOR_SELF, LVarA)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMOKE_BURST)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 3)
        EVT_ADD(LVar2, 5)
        EVT_LOOP(3)
            EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVarB)
    EVT_CALL(SetEnemyHP, LVarA, LVarB)
    EVT_CALL(CopyBuffs, ACTOR_SELF, LVarA)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarB, LVarC, LVarD)
    EVT_CALL(SetActorPos, LVarA, LVarB, LVarC, LVarD)
    EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_MULTI_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_DMG_APPLY, FALSE)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
    EVT_CALL(SetActorVar, LVarA, 8, 2)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetIdleAnimations, LVarA, 1, EVT_PTR(N(IdleAnimations2)))
    EVT_CALL(SetAnimation, LVarA, 1, ANIM_Duplighost_Anim0A)
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(GetActorPos, LVarA, LVarB, LVarC, LVarD)
    EVT_IF_GT(LVarC, 0)
        EVT_SET(LVarC, 0)
        EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(0.5))
        EVT_CALL(SetActorSounds, LVarA, ACTOR_SOUND_JUMP, SOUND_301, 0)
        EVT_CALL(SetGoalPos, LVarA, LVarB, LVarC, LVarD)
        EVT_CALL(JumpToGoal, LVarA, 15, FALSE, TRUE, FALSE)
        EVT_CALL(ResetActorSounds, LVarA, ACTOR_SOUND_JUMP)
        EVT_CALL(SetGoalPos, LVarA, LVarB, LVarC, LVarD)
        EVT_CALL(JumpToGoal, LVarA, 10, FALSE, TRUE, FALSE)
        EVT_CALL(SetGoalPos, LVarA, LVarB, LVarC, LVarD)
        EVT_CALL(JumpToGoal, LVarA, 5, FALSE, TRUE, FALSE)
    EVT_END_IF
    EVT_CALL(ForceHomePos, LVarA, LVarB, LVarC, LVarD)
    EVT_CALL(HPBarToHome, LVarA)
    EVT_CALL(SetIdleAnimations, LVarA, 1, EVT_PTR(N(IdleAnimations)))
    EVT_CALL(SetAnimation, LVarA, 1, ANIM_Duplighost_Anim02)
    EVT_CALL(SetActorPos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(ForceHomePos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(OnShockHit) = {
    EVT_SET(LVar9, LVar0)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar2, LVar3, LVar4)
    EVT_ADD(LVar2, 10)
    EVT_ADD(LVar3, 10)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar2, LVar3, LVar4)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_EXEC_WAIT(DoShockHit)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVarA)
    EVT_CALL(UseIdleAnimation, LVarA, FALSE)
    EVT_CALL(func_8027D32C, LVarA)
    EVT_CALL(CopyStatusEffects, ACTOR_SELF, LVarA)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMOKE_BURST)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 3)
        EVT_ADD(LVar2, 5)
        EVT_LOOP(3)
            EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVarB)
    EVT_CALL(SetEnemyHP, LVarA, LVarB)
    EVT_CALL(CopyBuffs, ACTOR_SELF, LVarA)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarB, LVarC, LVarD)
    EVT_CALL(SetActorPos, LVarA, LVarB, LVarC, LVarD)
    EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_MULTI_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, LVarA, 1, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, FALSE)
    EVT_CALL(SetActorFlagBits, LVarA, ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_DMG_APPLY, FALSE)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
    EVT_CALL(SetActorVar, LVarA, 8, 3)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar9, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetIdleAnimations, LVarA, 1, EVT_PTR(N(IdleAnimations2)))
    EVT_CALL(SetAnimation, LVarA, 1, ANIM_Duplighost_Anim0A)
    EVT_WAIT(15)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(0.5))
    EVT_CALL(GetActorPos, LVarA, LVarB, LVarC, LVarD)
    EVT_ADD(LVarB, 30)
    EVT_SET(LVarC, 0)
    EVT_CALL(SetGoalPos, LVarA, LVarB, LVarC, LVarD)
    EVT_CALL(JumpToGoal, LVarA, 15, FALSE, TRUE, FALSE)
    EVT_ADD(LVarB, 20)
    EVT_CALL(SetGoalPos, LVarA, LVarB, LVarC, LVarD)
    EVT_CALL(JumpToGoal, LVarA, 10, FALSE, TRUE, FALSE)
    EVT_ADD(LVarB, 10)
    EVT_CALL(SetGoalPos, LVarA, LVarB, LVarC, LVarD)
    EVT_CALL(JumpToGoal, LVarA, 5, FALSE, TRUE, FALSE)
    EVT_WAIT(20)
    EVT_CALL(AddActorDecoration, LVarA, 1, 0, ACTOR_DECORATION_SWEAT)
    EVT_CALL(SetActorYaw, LVarA, 180)
    EVT_CALL(SetIdleAnimations, LVarA, 1, EVT_PTR(N(IdleAnimations3)))
    EVT_CALL(SetAnimation, LVarA, 1, ANIM_Duplighost_Anim04)
    EVT_CALL(SetActorSpeed, LVarA, EVT_FLOAT(8.0))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVarB, LVarC, LVarD)
    EVT_CALL(SetGoalPos, LVarA, LVarB, 0, LVarD)
    EVT_CALL(RunToGoal, LVarA, 0, FALSE)
    EVT_CALL(SetAnimation, LVarA, 1, ANIM_Duplighost_Anim02)
    EVT_CALL(SetActorYaw, LVarA, 0)
    EVT_CALL(RemoveActorDecoration, LVarA, 1, 0)
    EVT_CALL(SetIdleAnimations, LVarA, 1, EVT_PTR(N(IdleAnimations)))
    EVT_CALL(ForceHomePos, LVarA, LVarB, 0, LVarD)
    EVT_CALL(HPBarToHome, LVarA)
    EVT_CALL(SetActorPos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(ForceHomePos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(OnShockDeath) = {
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarB, LVar1)
    EVT_SET(LVarC, LVar2)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVarA, LVarB)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 15)
    EVT_ADD(LVar1, 10)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetAnimation, ACTOR_SELF, LVarA, LVarB)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, FALSE, FALSE)
    EVT_SET(LVar0, LVarA)
    EVT_SET(LVar1, LVarB)
    EVT_EXEC_WAIT(DoShockHit)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, LVarC, 0)
        EVT_SET(LVar0, 0)
        EVT_LOOP(15)
            EVT_ADD(LVar0, -48)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 60)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_ADD(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_ADD(LVar0, 10)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_RETURN
    EVT_END
};

Vec3i N(pos_summon) = { NPC_DISPOSE_LOCATION };

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

API_CALLABLE(N(GetPartnerAndLevel)) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gPlayerData.currentPartner);
    evt_set_variable(script, *args++, gPlayerData.partners[gPlayerData.currentPartner].level);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CopyPriority)) {
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
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Duplighost_Anim06)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar1, 8)
        EVT_SETF(LVar3, EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_ADD(LVar1, 20)
        EVT_SETF(LVar3, EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar1, LVar2, LVar3, 40, 0)
    EVT_CALL(N(UnkBackgroundFunc3))
    EVT_CALL(MakeLerp, 0, 200, 20, EASING_LINEAR)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(N(SetBackgroundAlpha), LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT(10)
    EVT_CALL(N(GetPartnerAndLevel), LVar5, LVar6)
    EVT_CALL(N(CopyPriority), LVar5)
    EVT_SWITCH(LVar5)
        EVT_CASE_EQ(1)
            EVT_CALL(SummonEnemy, EVT_PTR(N(formation_goombario)), 0)
        EVT_CASE_EQ(2)
            EVT_CALL(SummonEnemy, EVT_PTR(N(formation_kooper)), 0)
        EVT_CASE_EQ(3)
            EVT_CALL(SummonEnemy, EVT_PTR(N(formation_bombette)), 0)
        EVT_CASE_EQ(4)
            EVT_CALL(SummonEnemy, EVT_PTR(N(formation_parakarry)), 0)
        EVT_CASE_EQ(9)
            EVT_CALL(SummonEnemy, EVT_PTR(N(formation_bow)), 0)
        EVT_CASE_EQ(6)
            EVT_CALL(SummonEnemy, EVT_PTR(N(formation_watt)), 0)
        EVT_CASE_EQ(7)
            EVT_CALL(SummonEnemy, EVT_PTR(N(formation_sushie)), 0)
        EVT_CASE_EQ(8)
            EVT_CALL(SummonEnemy, EVT_PTR(N(formation_lakilester)), 0)
    EVT_END_SWITCH
    EVT_SET(LVarA, LVar0)
    EVT_CALL(CopyStatusEffects, ACTOR_SELF, LVarA)
    EVT_CALL(SetBattleVar, 3, LVar5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMOKE_BURST)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 3)
        EVT_ADD(LVar2, 5)
        EVT_LOOP(3)
            EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, ACTOR_PART_FLAG_MULTI_TARGET, FALSE)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_CALL(SetEnemyHP, LVarA, LVar0)
    EVT_CALL(CopyBuffs, ACTOR_SELF, LVarA)
    EVT_CALL(GetOwnerID, LVar0)
    EVT_CALL(SetActorVar, LVarA, 0, LVar0)
    EVT_CALL(SetActorVar, LVarA, 1, LVar6)
    EVT_WAIT(20)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_THREAD
        EVT_CALL(MakeLerp, 200, 0, 20, EASING_LINEAR)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(SetBackgroundAlpha), LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetActorSounds, LVarA, ACTOR_SOUND_JUMP, SOUND_0, 0)
    EVT_SWITCH(LVar5)
        EVT_CASE_EQ(8)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(0.01))
            EVT_CALL(SetGoalPos, LVarA, LVar0, 10, LVar2)
            EVT_CALL(JumpToGoal, LVarA, 10, FALSE, FALSE, FALSE)
            EVT_WAIT(10)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(9)
        EVT_CASE_OR_EQ(4)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, LVarA, EVT_FLOAT(0.01))
            EVT_CALL(SetGoalPos, LVarA, LVar0, 30, LVar2)
            EVT_CALL(JumpToGoal, LVarA, 20, FALSE, FALSE, FALSE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, LVarA)
    EVT_CALL(ResetActorSounds, LVarA, ACTOR_SOUND_JUMP)
    EVT_WAIT(20)
    EVT_CALL(SetActorPos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(ForceHomePos, ACTOR_SELF, NPC_DISPOSE_LOCATION)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 600)
                EVT_CALL(GetBattleVar, 0, LVar0)
                EVT_IF_NOT_FLAG(LVar0, 0x4)
                    EVT_CALL(GetBattleVar, 0, LVar0)
                    EVT_BITWISE_OR_CONST(LVar0, 0x4)
                    EVT_CALL(SetBattleVar, 0, LVar0)
                    EVT_EXEC_WAIT(N(copyPartner))
                EVT_ELSE
                    EVT_CALL(GetBattleVar, 3, LVar0)
                    EVT_CALL(N(GetPartnerAndLevel), LVar1, LVar2)
                    EVT_IF_EQ(LVar0, LVar1)
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



