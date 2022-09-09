#include "sprite/npc/battle_goombario.h"

extern EvtScript N(goombario_init);
extern EvtScript N(goombario_takeTurn);
extern EvtScript N(goombario_idle);
extern EvtScript N(goombario_handleEvent);

#include "world/common/UnkFunc62.inc.c"
#include "common/ActorJumpToPos.inc.c"
#include "common/UnkActorSizeFunc.inc.c"
#include "common/UnkEffect6CFunc.inc.c"

ApiStatus N(UnkTattleEffectFunc1)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, *args++);

    effect->data.tattleWindow->pos.y = -1000.0f;
    return ApiStatus_DONE2;
}

ApiStatus N(UnkTattleEffectFunc2)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, *args++);

    effect->data.tattleWindow->pos.y = 144.0f;
    effect->flags |= EFFECT_INSTANCE_FLAGS_10;
    return ApiStatus_DONE2;
}

s32 N(goombario_idleAnimations)[] = {
    STATUS_NORMAL, NPC_ANIM_battle_goombario_default_idle,
    STATUS_STONE, NPC_ANIM_battle_goombario_default_still,
    STATUS_SLEEP, NPC_ANIM_battle_goombario_default_still,
    STATUS_POISON, NPC_ANIM_battle_goombario_default_idle,
    STATUS_STOP, NPC_ANIM_battle_goombario_default_still,
    STATUS_STATIC, NPC_ANIM_battle_goombario_default_idle,
    STATUS_PARALYZE, NPC_ANIM_battle_goombario_default_still,
    STATUS_DIZZY, NPC_ANIM_battle_goombario_default_daze,
    STATUS_FEAR, NPC_ANIM_battle_goombario_default_daze,
    STATUS_END,
};

s32 N(goombario_defenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(goombario_statusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 60,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
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
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(goombario_parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 20 },
        .opacity = 255,
        .idleAnimations = N(goombario_idleAnimations),
        .defenseTable = N(goombario_defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .unk_1C = -1,
        .unk_1D = -9,
    },
};

ActorBlueprint N(goombario) = {
    .flags = 0,
    .type = ACTOR_TYPE_GHOST_GOOMBARIO,
    .level = 23,
    .maxHP = 15,
    .partCount = ARRAY_COUNT(N(goombario_parts)),
    .partsData = N(goombario_parts),
    .script = &N(goombario_init),
    .statusTable = N(goombario_statusTable),
    .escapeChance = 50,
    .airLiftChance = 80,
    .spookChance = 70,
    .baseStatusChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 2,
    .size = { 29, 26 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(goombario_init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(goombario_takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(goombario_idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(goombario_handleEvent)))
    EVT_RETURN
    EVT_END
};

EvtScript N(goombario_idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(goombario_handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LocalVar(0))
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_CALL(GetLastElement, LocalVar(1))
            EVT_IF_FLAG(LocalVar(1), DAMAGE_TYPE_ELECTRIC)
                EVT_SET_CONST(LocalVar(0), 1)
                EVT_SET_CONST(LocalVar(1), NPC_ANIM_battle_goombario_default_pain)
                EVT_EXEC_WAIT(N(OnHitElectric))
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LocalVar(0), 1)
                EVT_SET_CONST(LocalVar(1), NPC_ANIM_battle_goombario_default_pain)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_battle_goombario_default_burn_pain)
            EVT_SET_CONST(LocalVar(2), NPC_ANIM_battle_goombario_default_burn_dead)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_battle_goombario_default_burn_pain)
            EVT_SET_CONST(LocalVar(2), NPC_ANIM_battle_goombario_default_burn_dead)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_WAIT(10)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_battle_goombario_default_burn_dead)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(N(OnShockHit))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_SET(LocalVar(2), 12)
            EVT_EXEC_WAIT(N(OnShockDeath))
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_battle_goombario_default_idle)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_battle_goombario_default_idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_battle_goombario_default_run)
            EVT_SET_CONST(LocalVar(2), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_battle_goombario_default_run)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LocalVar(0), 1)
            EVT_SET_CONST(LocalVar(1), NPC_ANIM_battle_goombario_default_pain)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(goombario_returnBack) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_idle)
    EVT_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
        EVT_SET(LocalVar(0), 180)
        EVT_LOOP(15)
            EVT_SUB(LocalVar(0), 60)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LocalVar(0))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_fall)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 60)
    EVT_SET(LocalVar(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(10))
    EVT_IF_FLAG(LocalVar(10), STATUS_FLAG_SHRINK)
        EVT_SETF(LocalVar(5), EVT_FLOAT(7.2))
    EVT_ELSE
        EVT_SET(LocalVar(5), 18)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_charge)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LocalVar(5), 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_idle)
    EVT_ADD(LocalVar(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_charge)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LocalVar(5), 0)
    EVT_WAIT(1)
    EVT_ADD(LocalVar(0), 10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_idle)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_charge)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LocalVar(5), 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_idle)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_run)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(goombario_runToPlayer) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 70, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_run)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(goombario_8021C7FC) = {
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(11), LocalVar(12), LocalVar(13))
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(12), LocalVar(13), LocalVar(14))
    EVT_IF_GT(LocalVar(11), LocalVar(12))
        EVT_SUB(LocalVar(11), LocalVar(12))
    EVT_ELSE
        EVT_SUB(LocalVar(12), LocalVar(11))
        EVT_SET(LocalVar(11), LocalVar(12))
    EVT_END_IF
    EVT_SUB(LocalVar(11), 20)
    EVT_DIVF(LocalVar(11), EVT_FLOAT(10.5888671875))
    EVT_ADDF(LocalVar(11), 15)
    EVT_SET(LocalVar(10), LocalVar(11))
    EVT_RETURN
    EVT_END
};

EvtScript N(goombario_attack) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_EXEC_WAIT(N(goombario_runToPlayer))
    EVT_EXEC_WAIT(N(goombario_8021C7FC))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LocalVar(10))
    EVT_IF_FLAG(LocalVar(10), STATUS_FLAG_SHRINK)
        EVT_SETF(LocalVar(0), EVT_FLOAT(7.2))
        EVT_SETF(LocalVar(1), EVT_FLOAT(7.6))
        EVT_SETF(LocalVar(1), EVT_FLOAT(3.6))
    EVT_ELSE
        EVT_SET(LocalVar(0), 18)
        EVT_SET(LocalVar(1), 19)
        EVT_SET(LocalVar(2), 9)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_charge)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LocalVar(0), 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LocalVar(1), 0)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LocalVar(2), 0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 0, 5)
    EVT_CALL(SetJumpAnimations, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk, NPC_ANIM_battle_goombario_default_headbonk, NPC_ANIM_battle_goombario_default_headbonk)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_200D)
    EVT_CALL(N(UnkFunc62), LocalVar(10), 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LocalVar(10), LocalVar(0))
            EVT_CALL(SetJumpAnimations, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk, NPC_ANIM_battle_goombario_default_headbonk, NPC_ANIM_battle_goombario_default_headbonk)
            EVT_CALL(N(ActorJumpToPos))
            EVT_THREAD
                EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
            EVT_END_THREAD
            EVT_IF_EQ(LocalVar(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LocalVar(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(goombario_returnBack))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CHILD_THREAD
        EVT_CALL(SetPartScale, ACTOR_SELF, 1, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_SELF, 1, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_SELF, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT(1)
    EVT_WAIT(2)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LocalVar(9))
    EVT_SWITCH(LocalVar(9))
        EVT_CASE_EQ(0)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), 0, 0, 0, 1, BS_FLAGS1_10)
        EVT_CASE_EQ(1)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), 0, 0, 0, 2, BS_FLAGS1_10)
        EVT_CASE_EQ(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), 0, 0, 0, 3, BS_FLAGS1_10)
    EVT_END_SWITCH
    EVT_CALL(GetActorHP, ACTOR_PLAYER, LocalVar(0))
    EVT_IF_EQ(LocalVar(0), 0)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_SET(LocalVar(10), 24)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LocalVar(9))
    EVT_SWITCH(LocalVar(9))
        EVT_CASE_EQ(0)
            EVT_THREAD
                EVT_WAIT(4)
                EVT_SET(LocalVar(0), 0)
                EVT_LOOP(6)
                    EVT_ADD(LocalVar(0), 30)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LocalVar(0))
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetJumpAnimations, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk, NPC_ANIM_battle_goombario_default_headbonk, NPC_ANIM_battle_goombario_default_headbonk)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_281)
            EVT_CALL(N(UnkFunc62), LocalVar(10), 3)
        EVT_CASE_EQ(1)
            EVT_THREAD
                EVT_WAIT(4)
                EVT_SET(LocalVar(0), 0)
                EVT_LOOP(6)
                    EVT_ADD(LocalVar(0), 30)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LocalVar(0))
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
            EVT_CALL(SetJumpAnimations, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk, NPC_ANIM_battle_goombario_default_headbonk, NPC_ANIM_battle_goombario_default_headbonk)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_281)
            EVT_CALL(N(UnkFunc62), LocalVar(10), 3)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
        EVT_CASE_EQ(2)
            EVT_THREAD
                EVT_WAIT(4)
                EVT_SET(LocalVar(0), 0)
                EVT_LOOP(6)
                    EVT_ADD(LocalVar(0), 30)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, EVT_IGNORE_ARG, LocalVar(0))
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk)
            EVT_END_THREAD
            EVT_THREAD
                EVT_SET(LocalVar(0), 0)
                EVT_LOOP(LocalVar(10))
                    EVT_ADD(LocalVar(0), 133)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, EVT_IGNORE_ARG, LocalVar(0), EVT_IGNORE_ARG)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
            EVT_CALL(SetJumpAnimations, ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_headbonk, NPC_ANIM_battle_goombario_default_headbonk, NPC_ANIM_battle_goombario_default_headbonk)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_281)
            EVT_CALL(N(UnkFunc62), LocalVar(10), 3)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
    EVT_END_SWITCH
    EVT_CHILD_THREAD
        EVT_CALL(SetPartScale, ACTOR_SELF, 1, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_SELF, 1, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_SELF, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_CHILD_THREAD
    EVT_WAIT(1)
    EVT_WAIT(2)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LocalVar(9))
    EVT_SWITCH(LocalVar(9))
        EVT_CASE_EQ(0)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), 0, 0, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(1)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), 0, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LocalVar(0), 0, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_SWITCH
    EVT_LABEL(100)
    EVT_SWITCH(LocalVar(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(YieldTurn)
            EVT_EXEC_WAIT(N(goombario_returnBack))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(goombario_tattle) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_WAIT(10)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4, 1)
    EVT_CALL(N(UnkEffect6CFunc), LocalVar(5))
    EVT_WAIT(12)
    EVT_CALL(func_802535B4, 0)
    EVT_CALL(SetCamEnabled, 2, 1)
    EVT_CALL(SetCamFlag80, 2, 0)
    EVT_CALL(SetCamPerspective, 2, 6, 25, 16, 1024)
    EVT_CALL(SetCamViewport, 2, 37, 95, 138, 99)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SUB(LocalVar(0), 8)
    EVT_SET(LocalVar(1), 0)
    EVT_CALL(N(UnkActorSizeFunc))
    EVT_WAIT(1)
    EVT_CALL(func_802CAE50, 2, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(func_802CABE8, 2, 0, LocalVar(3), 100, 4)
    EVT_WAIT(2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_282)
    EVT_CALL(SetCamFlag80, 2, 1)
    EVT_WAIT(10)
    EVT_CALL(ActorSpeak, MESSAGE_ID(0x1C, 0x0092), ACTOR_SELF, 1, NPC_ANIM_battle_goombario_default_talk, NPC_ANIM_battle_goombario_default_idle)
    EVT_CALL(N(UnkTattleEffectFunc2), LocalVar(5))
    EVT_WAIT(12)
    EVT_CALL(SetCamEnabled, 2, 0)
    EVT_WAIT(32)
    EVT_CALL(func_802535B4, 1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4, 0)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(goombario_takeTurn) = {
    EVT_CALL(RandInt, 100, LocalVar(0))
    EVT_IF_LT(LocalVar(0), 10)
        EVT_EXEC_WAIT(N(goombario_tattle))
    EVT_ELSE
        EVT_EXEC_WAIT(N(goombario_attack))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
