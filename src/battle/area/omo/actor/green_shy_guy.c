#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/ShyGuy.h"

#define NAMESPACE b_area_omo_green_shy_guy

extern s32 N(IdleAnimations_8021FF1C)[];
extern EvtScript N(init_8021FF68);
extern EvtScript N(takeTurn_802218B4);
extern EvtScript N(idle_8021FFB4);
extern EvtScript N(handleEvent_80220128);

s32 N(DefenseTable_8021FE10)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_SHOCK, 0,
    ELEMENT_END,
};

s32 N(StatusTable_8021FE24)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 70,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 100,
    STATUS_STATIC, 50,
    STATUS_PARALYZE, 90,
    STATUS_SHRINK, 75,
    STATUS_STOP, 90,
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

enum PartIDs {
    PT_MAIN     = 1,
};

ActorPartBlueprint N(PartsTable_8021FED0)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8021FF1C),
        .defenseTable = N(DefenseTable_8021FE10),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_SHY_GUY,
    .level = 14,
    .maxHP = 7,
    .partCount = ARRAY_COUNT( N(PartsTable_8021FED0)),
    .partsData = N(PartsTable_8021FED0),
    .initScript = &N(init_8021FF68),
    .statusTable = N(StatusTable_8021FE24),
    .escapeChance = 60,
    .airLiftChance = 85,
    .hurricaneChance = 80,
    .spookChance = 80,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 28, 24 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(IdleAnimations_8021FF1C)[] = {
    STATUS_NORMAL,    ANIM_ShyGuy_Green_Anim01,
    STATUS_STONE,     ANIM_ShyGuy_Green_Anim00,
    STATUS_SLEEP,     ANIM_ShyGuy_Green_Anim12,
    STATUS_POISON,    ANIM_ShyGuy_Green_Anim01,
    STATUS_STOP,      ANIM_ShyGuy_Green_Anim00,
    STATUS_STATIC,    ANIM_ShyGuy_Green_Anim01,
    STATUS_PARALYZE,  ANIM_ShyGuy_Green_Anim00,
    STATUS_DIZZY,     ANIM_ShyGuy_Green_Anim13,
    STATUS_FEAR,      ANIM_ShyGuy_Green_Anim13,
    STATUS_END,
};

EvtScript N(init_8021FF68) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_802218B4)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8021FFB4)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80220128)))
    EVT_RETURN
    EVT_END
};

#include "common/UnkBattleFunc1.inc.c"

EvtScript N(idle_8021FFB4) = {
    EVT_LABEL(0)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP)
        EVT_CALL(SetTargetOffset, ACTOR_SELF, PT_MAIN, -4, 14)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PT_MAIN, 0, 0)
        EVT_CALL(N(UnkBattleFunc1), -10, 13, 10, 13)
    EVT_ELSE
        EVT_CALL(SetTargetOffset, ACTOR_SELF, PT_MAIN, 0, 24)
        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PT_MAIN, -1, -10)
        EVT_CALL(N(UnkBattleFunc1), -10, 20, 10, 20)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(802200C4) = {
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim03)
    EVT_EXEC_WAIT(DoReturnHome)
    EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim01)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80220128) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim0C)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim0D)
            EVT_SET_CONST(LVar2, ANIM_ShyGuy_Green_Anim0E)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim0D)
            EVT_SET_CONST(LVar2, ANIM_ShyGuy_Green_Anim0E)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim0E)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim0C)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim0C)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim0C)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim0C)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim0C)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(802200C4))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim0C)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim0C)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim01)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim0C)
            EVT_EXEC_WAIT(EVS_DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim0C)
            EVT_EXEC_WAIT(EVS_DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim01)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim03)
            EVT_SET_CONST(LVar2, ANIM_ShyGuy_Green_Anim14)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim0C)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim0C)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80220604) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim03)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_2EF, 0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_20BA, SOUND_3B4)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim04)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim05)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim04)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim01)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2EF)
    EVT_END_THREAD
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_20BA, SOUND_3B4)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim04)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 10)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim05)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim01)
    EVT_WAIT(8)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_EXEC_WAIT(N(802200C4))
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(80220D2C) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_234)
    EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim09)
    EVT_WAIT(20)
    EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim03)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 80)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_20BA, SOUND_3B4)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim04)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_SUB(LVar0, 40)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim09)
            EVT_THREAD
                EVT_WAIT(12)
                EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim0A)
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 10)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 24, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim05)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_SUB(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 15)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim04)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim01)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim09)
    EVT_THREAD
        EVT_WAIT(9)
        EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim0A)
    EVT_END_THREAD
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 18, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 15)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 14, 0)
                EVT_SET(LVar3, 0)
                EVT_LOOP(20)
                    EVT_SUB(LVar3, 30)
                    EVT_IF_LT(LVar3, 0)
                        EVT_ADD(LVar3, 360)
                    EVT_END_IF
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar3)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(GetBattleFlags, LVar0)
            EVT_IF_FLAG(LVar0, BS_FLAGS1_ATK_BLOCKED)
                EVT_GOTO(1)
            EVT_END_IF
            EVT_CALL(GetLastDamage, ACTOR_PLAYER, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_GOTO(1)
            EVT_END_IF
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_349)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_349 | SOUND_ID_TRIGGER_CHANGE_SOUND)
            EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim09)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim07)
            EVT_WAIT(15)
            EVT_GOTO(2)
            EVT_LABEL(1)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E4)
            EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim10)
            EVT_WAIT(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20C3)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(RandInt, 100, LVar0)
            EVT_IF_LT(LVar0, 50)
                EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim11)
            EVT_ELSE
                EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim13)
            EVT_END_IF
            EVT_WAIT(25)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_LABEL(2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_ShyGuy_Green_Anim04)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PT_MAIN, ANIM_ShyGuy_Green_Anim01)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_802218B4) = {
    EVT_CALL(RandInt, 1, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_EXEC_WAIT(N(80220604))
    EVT_ELSE
        EVT_EXEC_WAIT(N(80220D2C))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
