#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/npc/AlbinoDino.h"

#define NAMESPACE b_area_pra_albino_dino

extern EvtScript N(init);
extern EvtScript N(idle);
extern EvtScript N(takeTurn);
extern EvtScript N(handleEvent);

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL, ANIM_AlbinoDino_Anim03,
    STATUS_STONE, ANIM_AlbinoDino_Anim00,
    STATUS_SLEEP, ANIM_AlbinoDino_Anim03,
    STATUS_POISON, ANIM_AlbinoDino_Anim03,
    STATUS_STOP, ANIM_AlbinoDino_Anim00,
    STATUS_STATIC, ANIM_AlbinoDino_Anim03,
    STATUS_PARALYZE, ANIM_AlbinoDino_Anim00,
    STATUS_DIZZY, ANIM_AlbinoDino_Anim00,
    STATUS_FEAR, ANIM_AlbinoDino_Anim00,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 4,
    ELEMENT_FIRE, 99,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 0,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 75,
    STATUS_STOP, 0,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -9, 46 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -6, -17 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_ALBINO_DINO,
    .level = 23,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 40,
    .airLiftChance = 15,
    .hurricaneChance = 10,
    .spookChance = 25,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 64, 56 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -22, 24 },
    .statusMessageOffset = { 11, 40 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_AlbinoDino_Anim05)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_AlbinoDino_Anim03)
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
            EVT_SET_CONST(LVar1, ANIM_AlbinoDino_Anim08)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_AlbinoDino_Anim0A)
            EVT_SET_CONST(LVar2, ANIM_AlbinoDino_Anim0B)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_AlbinoDino_Anim0A)
            EVT_SET_CONST(LVar2, ANIM_AlbinoDino_Anim0B)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_AlbinoDino_Anim0B)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_AlbinoDino_Anim08)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_AlbinoDino_Anim08)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_AlbinoDino_Anim09)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_AlbinoDino_Anim08)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_AlbinoDino_Anim08)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_AlbinoDino_Anim08)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_AlbinoDino_Anim09)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_AlbinoDino_Anim03)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_AlbinoDino_Anim08)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_AlbinoDino_Anim09)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_AlbinoDino_Anim03)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_AlbinoDino_Anim05)
            EVT_SET_CONST(LVar2, ANIM_AlbinoDino_Anim08)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_AlbinoDino_Anim05)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_AlbinoDino_Anim08)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(stamp) = {
    EVT_SET(LVarA, 0)
    EVT_LABEL(0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorYaw, ACTOR_SELF, LVar3)
    EVT_IF_EQ(LVar3, 0)
        EVT_ADD(LVar0, 20)
    EVT_ELSE
        EVT_ADD(LVar0, -20)
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 25, 8, 45, 20, 0)
    EVT_IF_GT(LVarA, 3)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.2))
        EVT_SET(LVarA, 0)
    EVT_END_IF
    EVT_ADD(LVarA, 1)
    EVT_WAIT(2)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_EXEC_GET_TID(N(stamp), LVar9)
    EVT_THREAD
        EVT_LOOP(3)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_30B)
            EVT_WAIT(4)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2FD)
            EVT_WAIT(4)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_AlbinoDino_Anim05)
    EVT_WAIT(20)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_THREAD
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(AddGoalPos, ACTOR_SELF, -100, 0, 0)
                EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(12.0))
                EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
                EVT_KILL_THREAD(LVar9)
            EVT_END_THREAD
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_WAIT(30)
            EVT_IF_EQ(LVarF, HIT_RESULT_LUCKY)
                EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(40)
            EVT_CALL(YieldTurn)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_EXEC_WAIT(N(returnHome))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 12, 0, 0)
    EVT_ELSE
        EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
    EVT_END_IF
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(12.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(1.5))
    EVT_END_THREAD
    EVT_KILL_THREAD(LVar9)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, STATUS_FLAG_8 | 0x00000010, 4, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2FD)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_AlbinoDino_Anim03)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 3, EVT_FLOAT(1.0))
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
