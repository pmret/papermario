#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/GoombaKing.h"

#define NAMESPACE b_area_kmr_part_2_goomba_king

s32 N(IdleAnimations_80220800)[] = {
    STATUS_NORMAL,    ANIM_GoombaKing_Idle,
    STATUS_STONE,     ANIM_GoombaKing_Still,
    STATUS_SLEEP,     ANIM_GoombaKing_Sleep,
    STATUS_POISON,    ANIM_GoombaKing_Still,
    STATUS_STOP,      ANIM_GoombaKing_Still,
    STATUS_STATIC,    ANIM_GoombaKing_Still,
    STATUS_PARALYZE,  ANIM_GoombaKing_Still,
    STATUS_DIZZY,     ANIM_GoombaKing_Dizzy,
    STATUS_END,
};

s32 N(IdleAnimations_80220844)[] = {
    STATUS_NORMAL,    ANIM_GoombaKing_Run,
    STATUS_STONE,     ANIM_GoombaKing_Still,
    STATUS_SLEEP,     ANIM_GoombaKing_Sleep,
    STATUS_POISON,    ANIM_GoombaKing_Still,
    STATUS_STOP,      ANIM_GoombaKing_Still,
    STATUS_STATIC,    ANIM_GoombaKing_Still,
    STATUS_PARALYZE,  ANIM_GoombaKing_Still,
    STATUS_DIZZY,     ANIM_GoombaKing_Dizzy,
    STATUS_END,
};

s32 N(IdleAnimations_80220888)[] = {
    STATUS_NORMAL,   ANIM_GoombaKing_Dizzy,
    STATUS_STONE,    ANIM_GoombaKing_Still,
    STATUS_SLEEP,    ANIM_GoombaKing_Sleep,
    STATUS_POISON,   ANIM_GoombaKing_Still,
    STATUS_STOP,     ANIM_GoombaKing_Still,
    STATUS_STATIC,   ANIM_GoombaKing_Still,
    STATUS_PARALYZE, ANIM_GoombaKing_Still,
    STATUS_DIZZY,    ANIM_GoombaKing_Dizzy,
    STATUS_END,
};

s32 N(IdleAnimations_802208CC)[] = {
    STATUS_NORMAL,   ANIM_GoombaKing_Angry,
    STATUS_STONE,    ANIM_GoombaKing_Still,
    STATUS_SLEEP,    ANIM_GoombaKing_Sleep,
    STATUS_POISON,   ANIM_GoombaKing_Still,
    STATUS_STOP,     ANIM_GoombaKing_Still,
    STATUS_STATIC,   ANIM_GoombaKing_Still,
    STATUS_PARALYZE, ANIM_GoombaKing_Still,
    STATUS_DIZZY,    ANIM_GoombaKing_Dizzy,
    STATUS_END,
};

s32 N(DefenseTable_80220910)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable_8022091C)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 100,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 100,
    STATUS_STOP, 100,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, -1,
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, -1,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(PartsTable_802209C8)[] = {
    {
        .flags = ACTOR_PART_FLAG_20 | ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -25, 15 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_80220800),
        .defenseTable = N(DefenseTable_80220910),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_20 | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 80 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable_80220910),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

extern EvtScript N(init_80220A38);
extern EvtScript N(takeTurn_80221530);
extern EvtScript N(idle_80220B50);
extern EvtScript N(handleEvent_80220F34);
extern EvtScript N(nextTurn_802229C4);
extern EvtScript N(80222D9C);
extern EvtScript N(80221CD4);
extern EvtScript N(80221680);
extern EvtScript N(doDeath_80222F50);

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GOOMBA_KING,
    .level = 49,
    .maxHP = 10,
    .partCount = ARRAY_COUNT( N(PartsTable_802209C8)),
    .partsData = N(PartsTable_802209C8),
    .initScript = &N(init_80220A38),
    .statusTable = N(StatusTable_8022091C),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 56, 80 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -6, 38 },
    .statusMessageOffset = { 12, 75 },
};

// Unused function
API_CALLABLE(func_80218A60_43A4F0) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);

    fx_landing_dust(2, var1, var2, evt_get_variable(script, *args++), 0);
    return ApiStatus_DONE2;
}

EvtScript N(init_80220A38) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_80221530)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_80220B50)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80220F34)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn_802229C4)))
    EVT_EXEC_GET_TID(N(80222D9C), LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 6, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80220B50) = {
    EVT_LABEL(0)
    EVT_CALL(RandInt, 80, LVar0)
    EVT_ADD(LVar0, 80)
    EVT_WAIT(LVar0)
    EVT_LABEL(1)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_WAIT(1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80220844)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleRunToGoal, ACTOR_SELF, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80220800)))
    EVT_WAIT(20)
    EVT_LABEL(2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_WAIT(1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80220844)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleRunToGoal, ACTOR_SELF, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_80220800)))
    EVT_WAIT(80)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80220DB0) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
    EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20B4)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 15, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20B4)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 5, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20B4)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80220F34) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(9)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
        EVT_CASE_EQ(10)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
        EVT_CASE_EQ(14)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_GoombaKing_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(11)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(47)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(N(80220DB0))
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Run)
            EVT_EXEC_WAIT(DoReturnHome)
        EVT_CASE_EQ(38)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar0)
            EVT_KILL_THREAD(LVar0)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(N(doDeath_80222F50))
            EVT_RETURN
        EVT_CASE_OR_EQ(23)
        EVT_CASE_OR_EQ(25)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Idle)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(32)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_WAIT(10)
            EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar0)
            EVT_KILL_THREAD(LVar0)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(N(doDeath_80222F50))
            EVT_RETURN
        EVT_CASE_EQ(36)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_GoombaKing_BurnStill)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_WAIT(10)
            EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar0)
            EVT_KILL_THREAD(LVar0)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_BurnStill)
            EVT_EXEC_WAIT(N(doDeath_80222F50))
            EVT_RETURN
        EVT_CASE_EQ(33)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar0)
            EVT_KILL_THREAD(LVar0)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(N(doDeath_80222F50))
            EVT_RETURN
        EVT_CASE_EQ(42)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GoombaKing_Dead)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GoombaKing_Run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GoombaKing_Idle)
        EVT_CASE_EQ(53)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Idle)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(49)
            EVT_SET_CONST(LVar0, 0x00000001)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Idle)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80221530) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x80000)
        EVT_CALL(GetActorVar, ACTOR_ENEMY3, 6, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_CALL(RandInt, 100, LVar1)
            EVT_IF_LT(LVar1, 60)
                EVT_SUB(LVar0, 1)
                EVT_CALL(SetActorVar, ACTOR_ENEMY3, 6, LVar0)
                EVT_EXEC_WAIT(N(80221CD4))
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(80221680))
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(80221680) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x80000)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
        EVT_CALL(AddBattleCamZoom, -100)
        EVT_CALL(SetBattleCamOffsetZ, 20)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 30)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
        EVT_CALL(AddBattleCamZoom, -100)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_END_IF
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, 0x80000)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 32, 0, 0)
    EVT_ELSE
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 12, 0, 0)
    EVT_END_IF
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GoombaKing_Run)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GoombaKing_Idle)
    EVT_WAIT(8)
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20ED)
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20ED)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GoombaKing_Kick)
    EVT_SET(LVar0, 0)
    EVT_LOOP(20)
        EVT_ADD(LVar0, 18)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 2, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_IF_EQ(LVarA, 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0x80000000, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GoombaKing_Dizzy)
            EVT_SET(LVar0, 0)
            EVT_LOOP(20)
                EVT_ADD(LVar0, 18)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GoombaKing_Idle)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GoombaKing_Run)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GoombaKing_Idle)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarA, 0, 0, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GoombaKing_Idle)
    EVT_SWITCH(LVarA)
        EVT_CASE_DEFAULT
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GoombaKing_Idle)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GoombaKing_Run)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GoombaKing_Idle)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80221CD4) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_15)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT(15)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GoombaKing_Angry)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20B4)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GoombaKing_Still)
    EVT_THREAD
        EVT_CALL(StartRumble, 11)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, 0x80000)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(4.0))
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_GoombaKing_Idle)
        EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, -80, 125, 0, 100, 0)
        EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, -15, 135, 0, 85, 0)
        EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, 100, 103, 0, 70, 0)
    EVT_END_THREAD
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 2, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(6)
        EVT_CASE_OR_EQ(5)
            EVT_THREAD
                EVT_WAIT(12)
                EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY3, 3, SOUND_301)
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT(10)
                EVT_CALL(SetPartJumpGravity, ACTOR_ENEMY3, 3, EVT_FLOAT(1.5))
                EVT_CALL(GetPartOffset, ACTOR_ENEMY3, 3, LVar0, LVar1, LVar2)
                EVT_CALL(FallPartTo, ACTOR_ENEMY3, 3, LVar0, 10, LVar2, 14)
                EVT_SUB(LVar0, 12)
                EVT_CALL(JumpPartTo, ACTOR_ENEMY3, 3, LVar0, 10, LVar2, 10, TRUE)
                EVT_SUB(LVar0, 7)
                EVT_CALL(JumpPartTo, ACTOR_ENEMY3, 3, LVar0, 10, LVar2, 7, TRUE)
                EVT_LOOP(20)
                    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY3, 3, 1, FALSE)
                    EVT_WAIT(1)
                    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY3, 3, 1, TRUE)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT(5)
                EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY3, 4, SOUND_301)
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT(3)
                EVT_CALL(SetPartJumpGravity, ACTOR_ENEMY3, 4, EVT_FLOAT(1.5))
                EVT_CALL(GetPartOffset, ACTOR_ENEMY3, 4, LVar0, LVar1, LVar2)
                EVT_CALL(FallPartTo, ACTOR_ENEMY3, 4, LVar0, 10, LVar2, 15)
                EVT_SUB(LVar0, 12)
                EVT_CALL(JumpPartTo, ACTOR_ENEMY3, 4, LVar0, 10, LVar2, 10, TRUE)
                EVT_SUB(LVar0, 7)
                EVT_CALL(JumpPartTo, ACTOR_ENEMY3, 4, LVar0, 10, LVar2, 7, TRUE)
                EVT_LOOP(20)
                    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY3, 4, 1, FALSE)
                    EVT_WAIT(1)
                    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY3, 4, 1, TRUE)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT(17)
                EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY3, 5, SOUND_301)
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT(15)
                EVT_CALL(SetPartJumpGravity, ACTOR_ENEMY3, 5, EVT_FLOAT(1.5))
                EVT_CALL(GetPartOffset, ACTOR_ENEMY3, 5, LVar0, LVar1, LVar2)
                EVT_CALL(FallPartTo, ACTOR_ENEMY3, 5, LVar0, 10, LVar2, 17)
                EVT_ADD(LVar0, 12)
                EVT_CALL(JumpPartTo, ACTOR_ENEMY3, 5, LVar0, 10, LVar2, 10, TRUE)
                EVT_ADD(LVar0, 7)
                EVT_CALL(JumpPartTo, ACTOR_ENEMY3, 5, LVar0, 10, LVar2, 7, TRUE)
                EVT_LOOP(20)
                    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY3, 5, 1, FALSE)
                    EVT_WAIT(1)
                    EVT_CALL(SetPartFlagBits, ACTOR_ENEMY3, 5, 1, TRUE)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_WAIT(15)
            EVT_IF_EQ(LVarA, 5)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0x80000000, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_WAIT(12)
        EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY3, 3, SOUND_301)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetPartJumpGravity, ACTOR_ENEMY3, 3, EVT_FLOAT(1.5))
        EVT_CALL(GetPartOffset, ACTOR_ENEMY3, 3, LVar0, LVar1, LVar2)
        EVT_CALL(FallPartTo, ACTOR_ENEMY3, 3, LVar0, 35, LVar2, 14)
        EVT_SUB(LVar0, 12)
        EVT_CALL(JumpPartTo, ACTOR_ENEMY3, 3, LVar0, 10, LVar2, 10, TRUE)
        EVT_SUB(LVar0, 7)
        EVT_CALL(JumpPartTo, ACTOR_ENEMY3, 3, LVar0, 10, LVar2, 7, TRUE)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY3, 3, 1, FALSE)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY3, 3, 1, TRUE)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY3, 4, SOUND_301)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(SetPartJumpGravity, ACTOR_ENEMY3, 4, EVT_FLOAT(1.5))
        EVT_CALL(GetPartOffset, ACTOR_ENEMY3, 4, LVar0, LVar1, LVar2)
        EVT_CALL(FallPartTo, ACTOR_ENEMY3, 4, LVar0, 10, LVar2, 15)
        EVT_SUB(LVar0, 12)
        EVT_CALL(JumpPartTo, ACTOR_ENEMY3, 4, LVar0, 10, LVar2, 10, TRUE)
        EVT_SUB(LVar0, 7)
        EVT_CALL(JumpPartTo, ACTOR_ENEMY3, 4, LVar0, 10, LVar2, 7, TRUE)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY3, 4, 1, FALSE)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY3, 4, 1, TRUE)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(17)
        EVT_CALL(PlaySoundAtPart, ACTOR_ENEMY3, 5, SOUND_301)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(SetPartJumpGravity, ACTOR_ENEMY3, 5, EVT_FLOAT(1.5))
        EVT_CALL(GetPartOffset, ACTOR_ENEMY3, 5, LVar0, LVar1, LVar2)
        EVT_CALL(FallPartTo, ACTOR_ENEMY3, 5, LVar0, 10, LVar2, 17)
        EVT_ADD(LVar0, 12)
        EVT_CALL(JumpPartTo, ACTOR_ENEMY3, 5, LVar0, 10, LVar2, 10, TRUE)
        EVT_ADD(LVar0, 7)
        EVT_CALL(JumpPartTo, ACTOR_ENEMY3, 5, LVar0, 10, LVar2, 7, TRUE)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY3, 5, 1, FALSE)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_ENEMY3, 5, 1, TRUE)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(24)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(10)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_802229C4) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(10)
            EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(func_802535B4, 0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
                EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY1)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT(20)
                EVT_CALL(UseIdleAnimation, ACTOR_ENEMY1, FALSE)
                EVT_CALL(EnableIdleScript, ACTOR_ENEMY1, 0)
                EVT_CALL(ActorSpeak, MSG_CH0_00CB, ACTOR_ENEMY1, 1, 0x0062000A, 0x0062000A)
                EVT_CALL(EnableIdleScript, ACTOR_ENEMY1, 1)
                EVT_CALL(UseIdleAnimation, ACTOR_ENEMY1, TRUE)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
                EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY2)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_WAIT(10)
                EVT_CALL(UseIdleAnimation, ACTOR_ENEMY2, FALSE)
                EVT_CALL(EnableIdleScript, ACTOR_ENEMY2, 0)
                EVT_CALL(ActorSpeak, MSG_CH0_00CC, ACTOR_ENEMY2, 1, 0x0062010A, 0x0062010A)
                EVT_CALL(EnableIdleScript, ACTOR_ENEMY2, 1)
                EVT_CALL(UseIdleAnimation, ACTOR_ENEMY2, TRUE)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_ENEMY0)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT(20)
                EVT_CALL(ActorSpeak, MSG_CH0_00CD, ACTOR_ENEMY0, 1, 0x00630009, 0x00630009)
                EVT_CALL(SetActorVar, ACTOR_SELF, 3, 1)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_PLAYER)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_WAIT(10)
                EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, 180)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Question)
                EVT_CALL(ActorSpeak, MSG_CH0_00CE, ACTOR_PARTNER, 0, -1, -1)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_NodYes)
                EVT_WAIT(15)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
                EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_WAIT(20)
                EVT_CALL(func_802535B4, 1)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80222D9C) = {
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(GetAnimation, ACTOR_SELF, 1, LVar0)
    EVT_IF_NE(LVar0, 6488068)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetAnimation, ACTOR_SELF, 1, LVar0)
    EVT_IF_NE(LVar0, 6488068)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(StartRumble, 1)
    EVT_CALL(func_8026DF88, ACTOR_SELF, 1, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, 0x80000)
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.2))
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, 0x80000)
                EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.7))
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(doDeath_80222F50) = {
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_SET(LVar2, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_WAIT(10)
    EVT_LOOP(24)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar2)
        EVT_ADD(LVar2, 30)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar2, LVar3, LVar4)
    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar2, LVar3, LVar4, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DEATH)
    EVT_CALL(DropStarPoints, ACTOR_SELF)
    EVT_SET(LVar3, 0)
    EVT_LOOP(12)
        EVT_CALL(SetActorRotation, ACTOR_SELF, LVar3, 0, 0)
        EVT_ADD(LVar3, 8)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 1, 1, TRUE)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, 4, TRUE)
    EVT_WAIT(30)
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(GetActorHP, ACTOR_ENEMY1, LVar0)
    EVT_END_IF
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(UseIdleAnimation, ACTOR_ENEMY1, FALSE)
        EVT_CALL(EnableIdleScript, ACTOR_ENEMY1, 0)
        EVT_CALL(ActorSpeak, MSG_CH0_00CF, ACTOR_ENEMY1, 1, 0x0062000B, 0x0062000B)
        EVT_CALL(EnableIdleScript, ACTOR_ENEMY1, 1)
        EVT_CALL(UseIdleAnimation, ACTOR_ENEMY1, TRUE)
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_ENEMY2, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(GetActorHP, ACTOR_ENEMY2, LVar0)
    EVT_END_IF
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(UseIdleAnimation, ACTOR_ENEMY2, FALSE)
        EVT_CALL(EnableIdleScript, ACTOR_ENEMY2, 0)
        EVT_CALL(ActorSpeak, MSG_CH0_00D0, ACTOR_ENEMY2, 1, 0x0062010B, 0x0062010B)
        EVT_CALL(EnableIdleScript, ACTOR_ENEMY2, 1)
        EVT_CALL(UseIdleAnimation, ACTOR_ENEMY2, TRUE)
    EVT_END_IF
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};
