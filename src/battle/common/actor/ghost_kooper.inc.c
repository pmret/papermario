#include "sprite/npc/BattleKooper.h"

extern EvtScript N(kooper_init);
extern EvtScript N(kooper_takeTurn);
extern EvtScript N(kooper_idle);
extern EvtScript N(kooper_handleEvent);

s32 N(kooper_idleAnimations)[] = {
    STATUS_NORMAL, ANIM_BattleKooper_Idle,
    STATUS_STONE, ANIM_BattleKooper_Still,
    STATUS_SLEEP, ANIM_BattleKooper_Still,
    STATUS_POISON, ANIM_BattleKooper_Idle,
    STATUS_STOP, ANIM_BattleKooper_Still,
    STATUS_STATIC, ANIM_BattleKooper_Idle,
    STATUS_PARALYZE, ANIM_BattleKooper_Still,
    STATUS_DIZZY, ANIM_BattleKooper_Injured,
    STATUS_FEAR, ANIM_BattleKooper_Injured,
    STATUS_END,
};

s32 N(kooper_idleAnimations2)[] = {
    STATUS_NORMAL, ANIM_BattleKooper_Toppled,
    STATUS_STONE, ANIM_BattleKooper_StillToppled,
    STATUS_SLEEP, ANIM_BattleKooper_StillToppled,
    STATUS_POISON, ANIM_BattleKooper_Toppled,
    STATUS_STOP, ANIM_BattleKooper_StillToppled,
    STATUS_STATIC, ANIM_BattleKooper_Toppled,
    STATUS_PARALYZE, ANIM_BattleKooper_StillToppled,
    STATUS_DIZZY, ANIM_BattleKooper_Toppled,
    STATUS_FEAR, ANIM_BattleKooper_Toppled,
    STATUS_END,
};

s32 N(kooper_defenseTable)[] = {
    ELEMENT_NORMAL, 1,
    ELEMENT_END,
};

s32 N(kooper_defenseTable2)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(kooper_statusTable)[] = {
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

ActorPartBlueprint N(kooper_parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 32 },
        .opacity = 255,
        .idleAnimations = N(kooper_idleAnimations),
        .defenseTable = N(kooper_defenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_FLIPABLE,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -16,
    },
};

ActorBlueprint N(kooper) = {
    .flags = 0,
    .type = ACTOR_TYPE_GHOST_KOOPER,
    .level = 23,
    .maxHP = 15,
    .partCount = ARRAY_COUNT(N(kooper_parts)),
    .partsData = N(kooper_parts),
    .script = &N(kooper_init),
    .statusTable = N(kooper_statusTable),
    .escapeChance = 50,
    .airLiftChance = 80,
    .spookChance = 70,
    .baseStatusChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 2,
    .size = { 32, 38 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(kooper_init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(kooper_takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(kooper_idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(kooper_handleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, 0)
    EVT_RETURN
    EVT_END
};

#include "common/UnkBattleFunc1.inc.c"

//TODO find the way to include it
ApiStatus N(kooper_UnkActorPosFunc)(Evt* script, s32 isInitialCall) {
    Actor* actor = get_actor(script->owner1.actorID);
    ActorState* actorState = &actor->state;

    if (isInitialCall) {
        actor->state.currentPos.x = actor->currentPos.x;
        actor->state.currentPos.y = actor->currentPos.y;
        actor->state.currentPos.z = actor->currentPos.z;
    }

    add_xz_vec3f(&actorState->currentPos, actor->state.speed, actor->state.angle);
    if (actor->state.speed < 4.0f) {
        play_movement_dust_effects(0, actor->state.currentPos.x, actor->state.currentPos.y, actor->state.currentPos.z, actor->state.angle);
    } else {
        play_movement_dust_effects(1, actor->state.currentPos.x, actor->state.currentPos.y, actor->state.currentPos.z, actor->state.angle);
    }

    actorState->speed /= 1.5;
    actor->currentPos.x = actorState->currentPos.x;
    actor->currentPos.y = actorState->currentPos.y;
    actor->currentPos.z = actorState->currentPos.z;

    if (actorState->speed < 1.0) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

EvtScript N(kooper_idle) = {
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -2, 38)
            EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, -3, -9)
            EVT_CALL(N(UnkBattleFunc1), -10, 25, 10, 25)
        EVT_CASE_EQ(1)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 5, 15)
            EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 0, -6)
            EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

s32 N(kooper_dispOffsets)[] = {
    9, 16, 22, 26, 30, 32, 33, 32, 30, 26, 22, 16, 9, 0, 4, 6, 7, 6, 4, 0, 2, 0,
};

EvtScript N(kooper_handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_CALL(GetLastElement, LVar1)
            EVT_IF_FLAG(LVar1, DAMAGE_TYPE_ELECTRIC)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
                EVT_EXEC_WAIT(N(OnHitElectric))
                EVT_RETURN
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_BattleKooper_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_BattleKooper_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_BurnStill)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_FLIP_TRIGGER)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, 1)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(kooper_defenseTable2)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(kooper_idleAnimations2)))
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, 5, 15)
            EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, 0, -6)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleKooper_Hurt)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
            EVT_THREAD
                EVT_WAIT(4)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 30)
                EVT_WAIT(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_WAIT(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -30)
                EVT_WAIT(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -60)
                EVT_WAIT(1)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -75)
                EVT_WAIT(1)
            EVT_END_THREAD
            EVT_USE_BUF(N(kooper_dispOffsets))
            EVT_LOOP(22)
                EVT_BUF_READ1(LVar0)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleKooper_Toppled)
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_BattleKooper_Idle)
                EVT_CASE_EQ(1)
                    EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_BattleKooper_Toppled)
            EVT_END_SWITCH
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_BattleKooper_Toppled)
                EVT_EXEC_WAIT(DoImmune)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_BattleKooper_Idle)
                EVT_EXEC_WAIT(DoRecover)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Run)
            EVT_SET_CONST(LVar2, ANIM_BattleKooper_Hurt)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_BattleKooper_Run)
                EVT_CASE_EQ(1)
                    EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(3.0))
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_BattleKooper_Toppled)
            EVT_END_SWITCH
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                        EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 1, 0)
                        EVT_ELSE
                            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 3, 0)
                        EVT_END_IF
                    EVT_END_IF
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
                EVT_CASE_EQ(1)
                    EVT_SET_CONST(LVar0, 1)
                    EVT_SET_CONST(LVar1, ANIM_BattleKooper_Toppled)
            EVT_END_SWITCH
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(kooper_takeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar0)
        EVT_SUB(LVar0, 1)
        EVT_IF_GT(LVar0, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 4, LVar0)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(3.0))
            EVT_WAIT(30)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
        EVT_ELSE
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(3.0))
            EVT_WAIT(20)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleKooper_Toppled)
            EVT_SET(LVar0, 0)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
            EVT_THREAD
                EVT_LOOP(5)
                    EVT_ADD(LVar0, 15)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleKooper_Idle)
            EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
            EVT_CALL(SetDefenseTable, ACTOR_SELF, 1, EVT_PTR(N(kooper_defenseTable)))
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(kooper_idleAnimations)))
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 1, -2, 38)
            EVT_CALL(func_8027D4C8, ACTOR_SELF, 1, -3, -9)
        EVT_END_IF
        EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleKooper_EnterShell)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_0)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleKooper_ShellSpinSlowest)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_200C)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 75)
    EVT_CALL(func_8024ECF8, 1, 1, 1)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(LVar0, 10)
        EVT_CASE_EQ(1)
            EVT_SET(LVar0, 20)
        EVT_CASE_EQ(2)
            EVT_SET(LVar0, 30)
    EVT_END_SWITCH
    EVT_SET(LVar9, 0)
    EVT_LOOP(LVar0)
        EVT_ADD(LVar9, 1)
        EVT_SWITCH(LVar9)
            EVT_CASE_LT(20)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleKooper_ShellSpinSlowest)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
            EVT_CASE_EQ(20)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_LT(40)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleKooper_ShellSpinSlower)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(12.0))
            EVT_CASE_EQ(40)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_LT(50)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleKooper_ShellSpinFaster)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(14.0))
            EVT_CASE_EQ(50)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_LT(60)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleKooper_ShellSpinFastest)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(16.0))
            EVT_CASE_EQ(60)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_END_SWITCH
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_200A)
    EVT_CALL(SetActorSounds, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(AddActorDecoration, ACTOR_SELF, 0, 0, 5)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_THREAD
                EVT_CALL(N(kooper_UnkActorPosFunc))
                EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 0, 0)
            EVT_END_THREAD
            EVT_WAIT(4)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleKooper_ShellStill)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, -8, 0, 0)
            EVT_SET(LVar0, 0)
            EVT_LOOP(2)
                EVT_ADD(LVar0, 30)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_WAIT(5)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
            EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 16, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_LOOP(5)
                EVT_ADD(LVar0, -12)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 2)
            EVT_WAIT(2)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -2)
            EVT_WAIT(2)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleKooper_ExitShell)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleKooper_Run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.5))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 0, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar9)
    EVT_SWITCH(LVar9)
        EVT_CASE_EQ(0)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 65535, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(1)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 65535, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(2)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 65535, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 8)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 60)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 10)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleKooper_ExitShell)
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_BattleKooper_Run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.5))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
