#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BulletBill.h"

#define NAMESPACE b_area_kpa4_bombshell_bill

extern EvtScript N(init);
extern EvtScript N(idle);
extern EvtScript N(takeTurn);
extern EvtScript N(handleEvent);
extern EvtScript N(playExplosionEffects);

extern s32 N(IdleAnimations)[];

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
    STATUS_DIZZY, 100,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 100,
    STATUS_STOP, 0,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -2,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 16 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_FIRE_EXPLODE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -6 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_BOMBSHELL_BILL,
    .level = 24,
    .maxHP = 3,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 40,
    .airLiftChance = 100,
    .hurricaneChance = 95,
    .spookChance = 0,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 28, 22 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL, ANIM_BulletBill_Gold_Anim01,
    STATUS_STONE, ANIM_BulletBill_Gold_Anim00,
    STATUS_STOP, ANIM_BulletBill_Gold_Anim00,
    STATUS_PARALYZE, ANIM_BulletBill_Gold_Anim00,
    STATUS_END,
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 16)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_ELSE
        EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
        EVT_CALL(GetActorPos, LVar0, LVar1, LVar2, LVar3)
        EVT_CALL(GetStatusFlags, LVar0, LVar4)
        EVT_IF_FLAG(LVar4, STATUS_FLAG_SHRINK)
            EVT_SET(LVar5, -13)
            EVT_SET(LVar6, 4)
        EVT_ELSE
            EVT_SET(LVar5, -33)
            EVT_SET(LVar6, 11)
        EVT_END_IF
        EVT_ADD(LVar1, LVar5)
        EVT_ADD(LVar2, LVar6)
        EVT_CALL(SetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
        EVT_CALL(CopyStatusEffects, LVar0, ACTOR_SELF)
        EVT_CALL(CopyBuffs, LVar0, ACTOR_SELF)
        EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_0, 0)
        EVT_CALL(GetActorPos, LVar0, LVar1, LVarB, LVarC)
        EVT_SUB(LVar1, 90)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BulletBill_Gold_Anim03)
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BulletBill_Gold_Anim01)
        EVT_CALL(ForceHomePos, ACTOR_SELF, LVar1, LVar2, LVar3)
        EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(explode) = {
    EVT_EXEC_WAIT(N(playExplosionEffects))
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, ANIM_BulletBill_Gold_Anim07)
    EVT_SET(LVar2, -12345)
    EVT_EXEC_WAIT(DoDeath)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BulletBill_Gold_Anim05)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BulletBill_Gold_Anim05)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_EXEC_WAIT(N(explode))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_EXEC_WAIT(N(explode))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(explode))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(explode))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BulletBill_Gold_Anim05)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_EXEC_WAIT(N(explode))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BulletBill_Gold_Anim05)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_EXEC_WAIT(N(explode))
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BulletBill_Gold_Anim01)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BulletBill_Gold_Anim05)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(explode))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_EXPLODE_TRIGGER)
            EVT_EXEC_WAIT(N(explode))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BulletBill_Gold_Anim01)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BulletBill_Gold_Anim05)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_EXEC_WAIT(N(explode))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BulletBill_Gold_Anim03)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BulletBill_Gold_Anim03)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BulletBill_Gold_Anim04)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    EVT_WAIT(15)
    EVT_CALL(UseBattleCamPresetImmediately, BTL_CAM_PRESET_19)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 6, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SET(LVar3, LVar1)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, LVar3)
            EVT_SUB(LVar0, 90)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(func_8027D32C, ACTOR_SELF)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
            EVT_CALL(RemoveActor, ACTOR_SELF)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar1)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, LVar3)
    EVT_ADD(LVar0, 10)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
    EVT_EXEC_WAIT(N(playExplosionEffects))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 6, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(YieldTurn)
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, ANIM_BulletBill_Gold_Anim07)
    EVT_SET(LVar2, -12345)
    EVT_EXEC_WAIT(DoDeath)
    EVT_RETURN
    EVT_END
};

EvtScript N(playExplosionEffects) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 2)
    EVT_PLAY_EFFECT(EFFECT_SMOKE_RING, 0, LVar0, LVar1, LVar2, 0)
    EVT_ADD(LVar1, 16)
    EVT_ADD(LVar2, 2)
    EVT_PLAY_EFFECT(EFFECT_BLAST, 0, LVar0, LVar1, LVar2, EVT_FLOAT(3.0), 30, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2078)
    EVT_CALL(StartRumble, 11)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
