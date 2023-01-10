#include "sprite/npc/BattleGoombario.h"

extern EvtScript N(goombario_init);
extern EvtScript N(goombario_takeTurn);
extern EvtScript N(goombario_idle);
extern EvtScript N(goombario_handleEvent);

#include "world/common/todo/UnkFunc62.inc.c"
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
    STATUS_NORMAL, ANIM_BattleGoombario_Idle,
    STATUS_STONE, ANIM_BattleGoombario_Still,
    STATUS_SLEEP, ANIM_BattleGoombario_Still,
    STATUS_POISON, ANIM_BattleGoombario_Idle,
    STATUS_STOP, ANIM_BattleGoombario_Still,
    STATUS_STATIC, ANIM_BattleGoombario_Idle,
    STATUS_PARALYZE, ANIM_BattleGoombario_Still,
    STATUS_DIZZY, ANIM_BattleGoombario_Injured,
    STATUS_FEAR, ANIM_BattleGoombario_Injured,
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
    .takeTurnScript = &N(goombario_init),
    .statusTable = N(goombario_statusTable),
    .escapeChance = 50,
    .airLiftChance = 80,
    .hurricaneChance = 70,
    .spookChance = 50,
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
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(goombario_takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(goombario_idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(goombario_handleEvent)))
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
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_CALL(GetLastElement, LVar1)
            EVT_IF_FLAG(LVar1, DAMAGE_TYPE_ELECTRIC)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
                EVT_EXEC_WAIT(N(OnHitElectric))
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_BurnHurt1)
            EVT_SET_CONST(LVar2, ANIM_BattleGoombario_BurnHurt2)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_BurnHurt1)
            EVT_SET_CONST(LVar2, ANIM_BattleGoombario_BurnHurt2)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_BurnHurt2)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(N(OnShockHit))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_SET(LVar2, 12)
            EVT_EXEC_WAIT(N(OnShockDeath))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_Idle)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_Idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_Run)
            EVT_SET_CONST(LVar2, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_Run)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_Idle)
    EVT_THREAD
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
        EVT_SET(LVar0, 180)
        EVT_LOOP(15)
            EVT_SUB(LVar0, 60)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_Fall)
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 60)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_SETF(LVar5, EVT_FLOAT(7.2))
    EVT_ELSE
        EVT_SET(LVar5, 18)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar5, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_Idle)
    EVT_ADD(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar5, 0)
    EVT_WAIT(1)
    EVT_ADD(LVar0, 10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_Idle)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar5, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_Idle)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_Run)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_Idle)
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
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_Run)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(goombario_8021C7FC) = {
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVarB, LVarC, LVarD)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVarC, LVarD, LVarE)
    EVT_IF_GT(LVarB, LVarC)
        EVT_SUB(LVarB, LVarC)
    EVT_ELSE
        EVT_SUB(LVarC, LVarB)
        EVT_SET(LVarB, LVarC)
    EVT_END_IF
    EVT_SUB(LVarB, 20)
    EVT_DIVF(LVarB, EVT_FLOAT(10.5888671875))
    EVT_ADDF(LVarB, 15)
    EVT_SET(LVarA, LVarB)
    EVT_RETURN
    EVT_END
};

EvtScript N(goombario_attack) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_EXEC_WAIT(N(goombario_runToPlayer))
    EVT_EXEC_WAIT(N(goombario_8021C7FC))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_SETF(LVar0, EVT_FLOAT(7.2))
        EVT_SETF(LVar1, EVT_FLOAT(7.6))
        EVT_SETF(LVar1, EVT_FLOAT(3.6))
    EVT_ELSE
        EVT_SET(LVar0, 18)
        EVT_SET(LVar1, 19)
        EVT_SET(LVar2, 9)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_PreHeadbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar1, 0)
    EVT_WAIT(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar2, 0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 0, 5)
    EVT_CALL(SetJumpAnimations, ACTOR_SELF, 1, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 2, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_200D)
    EVT_CALL(N(UnkFunc62), LVarA, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetJumpAnimations, ACTOR_SELF, 1, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
            EVT_CALL(N(ActorJumpToPos))
            EVT_THREAD
                EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
            EVT_END_THREAD
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
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
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar9)
    EVT_SWITCH(LVar9)
        EVT_CASE_EQ(0)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 1, BS_FLAGS1_10)
        EVT_CASE_EQ(1)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 2, BS_FLAGS1_10)
        EVT_CASE_EQ(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 3, BS_FLAGS1_10)
    EVT_END_SWITCH
    EVT_CALL(GetActorHP, ACTOR_PLAYER, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_SET(LVarA, 24)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar9)
    EVT_SWITCH(LVar9)
        EVT_CASE_EQ(0)
            EVT_THREAD
                EVT_WAIT(4)
                EVT_SET(LVar0, 0)
                EVT_LOOP(6)
                    EVT_ADD(LVar0, 30)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetJumpAnimations, ACTOR_SELF, 1, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_281)
            EVT_CALL(N(UnkFunc62), LVarA, 3)
        EVT_CASE_EQ(1)
            EVT_THREAD
                EVT_WAIT(4)
                EVT_SET(LVar0, 0)
                EVT_LOOP(6)
                    EVT_ADD(LVar0, 30)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
            EVT_CALL(SetJumpAnimations, ACTOR_SELF, 1, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_281)
            EVT_CALL(N(UnkFunc62), LVarA, 3)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
        EVT_CASE_EQ(2)
            EVT_THREAD
                EVT_WAIT(4)
                EVT_SET(LVar0, 0)
                EVT_LOOP(6)
                    EVT_ADD(LVar0, 30)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, EVT_IGNORE_ARG, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleGoombario_Headbonk)
            EVT_END_THREAD
            EVT_THREAD
                EVT_SET(LVar0, 0)
                EVT_LOOP(LVarA)
                    EVT_ADD(LVar0, 133)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, EVT_IGNORE_ARG, LVar0, EVT_IGNORE_ARG)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
            EVT_CALL(SetJumpAnimations, ACTOR_SELF, 1, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_281)
            EVT_CALL(N(UnkFunc62), LVarA, 3)
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
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar9)
    EVT_SWITCH(LVar9)
        EVT_CASE_EQ(0)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(1)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_SWITCH
    EVT_LABEL(100)
    EVT_SWITCH(LVar0)
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
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_WAIT(10)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4, 1)
    EVT_CALL(N(UnkEffect6CFunc), LVar5)
    EVT_WAIT(12)
    EVT_CALL(func_802535B4, 0)
    EVT_CALL(SetCamEnabled, 2, 1)
    EVT_CALL(SetCamFlag80, 2, 0)
    EVT_CALL(SetCamPerspective, 2, 6, 25, 16, 1024)
    EVT_CALL(SetCamViewport, 2, 37, 95, 138, 99)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 8)
    EVT_SET(LVar1, 0)
    EVT_CALL(N(UnkActorSizeFunc))
    EVT_WAIT(1)
    EVT_CALL(func_802CAE50, 2, LVar0, LVar1, LVar2)
    EVT_CALL(func_802CABE8, 2, 0, LVar3, 100, 4)
    EVT_WAIT(2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_282)
    EVT_CALL(SetCamFlag80, 2, 1)
    EVT_WAIT(10)
    EVT_CALL(ActorSpeak, MSG_EnemyTattle_Mario, ACTOR_SELF, 1, ANIM_BattleGoombario_Talk, ANIM_BattleGoombario_Idle)
    EVT_CALL(N(UnkTattleEffectFunc2), LVar5)
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
    EVT_CALL(RandInt, 100, LVar0)
    EVT_IF_LT(LVar0, 10)
        EVT_EXEC_WAIT(N(goombario_tattle))
    EVT_ELSE
        EVT_EXEC_WAIT(N(goombario_attack))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
