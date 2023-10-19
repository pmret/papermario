#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/ShyGuy.h"
#include "sprite/npc/MediGuy.h"
#include "sprite/npc/GrooveGuy.h"

#define NAMESPACE A(groove_guy)

extern ActorBlueprint A(red_shy_guy);
extern ActorBlueprint A(medi_guy);

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_RandomSummon);
extern EvtScript N(EVS_SummonShyGuy);
extern EvtScript N(EVS_SummonGrooveGuy);
extern EvtScript N(EVS_SummonMediGuy);

extern Formation N(ShyGuyFormation);
extern Formation N(GrooveGuyFormation);
extern Formation N(MediGuyFormation);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_Generation = 0,
};

enum N(ActorParams) {
    DMG_TACKLE      = 2,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_GrooveGuy_Anim01,
    STATUS_KEY_STONE,     ANIM_GrooveGuy_Anim00,
    STATUS_KEY_SLEEP,     ANIM_GrooveGuy_Anim06,
    STATUS_KEY_POISON,    ANIM_GrooveGuy_Anim01,
    STATUS_KEY_STOP,      ANIM_GrooveGuy_Anim00,
    STATUS_KEY_STATIC,    ANIM_GrooveGuy_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_GrooveGuy_Anim00,
    STATUS_KEY_DIZZY,     ANIM_GrooveGuy_Anim07,
    STATUS_KEY_FEAR,      ANIM_GrooveGuy_Anim07,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_SHOCK,    0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              70,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              50,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       1,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

BSS PlayerStatus N(DummyPlayerStatus);

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GROOVE_GUY,
    .level = ACTOR_LEVEL_GROOVE_GUY,
    .maxHP = 7,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 85,
    .hurricaneChance = 80,
    .spookChance = 70,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 2,
    .size = { 28, 28 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Generation, 0)
    EVT_RETURN
    EVT_END
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -4, 14)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
            EVT_CALL(N(SetAbsoluteStatusOffsets), -13, 15, 4, 13)
        EVT_ELSE
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 24)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, -10)
            EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 20, 10, 20)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReturnHome) = {
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim04)
    EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim01)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim0E)
            EVT_SET_CONST(LVar2, ANIM_GrooveGuy_Anim0F)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim0E)
            EVT_SET_CONST(LVar2, ANIM_GrooveGuy_Anim0F)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim0F)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim08)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim04)
            EVT_SET_CONST(LVar2, ANIM_GrooveGuy_Anim11)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_OR_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GrooveGuy_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_Tackle) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim04)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 50)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_ACTOR_HOP, 0)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim10)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
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
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_HOP)
    EVT_END_THREAD
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim10)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 10)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_TACKLE, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 30)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim01)
            EVT_WAIT(8)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_SleepySpin) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim10)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 10)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_GROOVE_GUY_TWIRL)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0C)
    EVT_SET(LVar0, 0)
    EVT_LOOP(30)
        EVT_ADD(LVar0, 48)
        EVT_MOD(LVar0, 360)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0B)
            EVT_WAIT(20)
            EVT_IF_EQ(LVar0, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, DMG_STATUS_KEY(STATUS_FLAG_DIZZY, 2, 50), 0, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(WasStatusInflicted, ACTOR_SELF, LVar0)
            EVT_IF_EQ(LVar0, TRUE)
                EVT_THREAD
                    EVT_SET(LVar0, 0)
                    EVT_LOOP(30)
                        EVT_ADD(LVar0, 48)
                        EVT_MOD(LVar0, 360)
                        EVT_CALL(SetActorYaw, ACTOR_PLAYER, LVar0)
                        EVT_WAIT(1)
                    EVT_END_LOOP
                    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
                EVT_END_THREAD
            EVT_END_IF
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_GROOVE_GUY_LEAP)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0B)
            EVT_SET(LVar0, 0)
            EVT_LOOP(15)
                EVT_ADD(LVar0, 24)
                EVT_MOD(LVar0, 360)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0C)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_GROOVE_GUY_SPIN_DOWN)
            EVT_THREAD
                EVT_SET(LVar0, 0)
                EVT_LOOP(20)
                    EVT_ADD(LVar0, 72)
                    EVT_MOD(LVar0, 360)
                    EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
            EVT_END_THREAD
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0A)
            EVT_WAIT(25)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GetAvailableColumn) = {
    EVT_SET(LFlag1, FALSE)
    EVT_SET(LFlag2, FALSE)
    EVT_SET(LFlag3, FALSE)
    EVT_SET(LFlag4, FALSE)
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(GetOwnerTarget, LVar0, LVar5)
        EVT_CALL(GetIndexFromHome, LVar0, LVar5)
        EVT_MOD(LVar5, 4)
        EVT_SWITCH(LVar5)
            EVT_CASE_EQ(0)
                EVT_SET(LFlag1, TRUE)
            EVT_CASE_EQ(1)
                EVT_SET(LFlag2, TRUE)
            EVT_CASE_EQ(2)
                EVT_SET(LFlag3, TRUE)
            EVT_CASE_EQ(3)
                EVT_SET(LFlag4, TRUE)
        EVT_END_SWITCH
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_IF_EQ(LFlag1, FALSE)
        EVT_SET(LVarA, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LFlag2, FALSE)
        EVT_SET(LVarA, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LFlag3, FALSE)
        EVT_SET(LVarA, 2)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LFlag4, FALSE)
        EVT_SET(LVarA, 3)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVarA, -1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CountActiveSummoners) = {
    EVT_SET(LVar9, 0)
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(GetOriginalActorType, LVar0, LVar2)
        EVT_SWITCH(LVar2)
            EVT_CASE_EQ(ACTOR_TYPE_GROOVE_GUY)
                EVT_CALL(GetStatusFlags, LVar0, LVar3)
                EVT_IF_NOT_FLAG(LVar3, STATUS_FLAGS_IMMOBILIZED)
                    EVT_CALL(GetActorVar, LVar0, AVAR_Generation, LVar3)
                    EVT_IF_NE(LVar3, 2)
                        EVT_ADD(LVar9, 1)
                    EVT_END_IF
                EVT_END_IF
        EVT_END_SWITCH
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Generation, LVar0)
    EVT_IF_EQ(LVar0, 2)
        EVT_CALL(RandInt, 100, LVar0)
        EVT_IF_LT(LVar0, 60)
            EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_DIZZY)
                EVT_EXEC_WAIT(N(EVS_Attack_Tackle))
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_Attack_SleepySpin))
            EVT_END_IF
        EVT_ELSE
            EVT_EXEC_WAIT(N(EVS_Attack_Tackle))
        EVT_END_IF
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_GetAvailableColumn))
    EVT_IF_EQ(LVarA, -1)
        EVT_CALL(RandInt, 100, LVar0)
        EVT_IF_LT(LVar0, 60)
            EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_DIZZY)
                EVT_EXEC_WAIT(N(EVS_Attack_Tackle))
            EVT_ELSE
                EVT_EXEC_WAIT(N(EVS_Attack_SleepySpin))
            EVT_END_IF
        EVT_ELSE
            EVT_EXEC_WAIT(N(EVS_Attack_Tackle))
        EVT_END_IF
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_CountActiveSummoners))
    EVT_SWITCH(LVar9)
        EVT_CASE_EQ(1)
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 300)
                EVT_EXEC_WAIT(N(EVS_RandomSummon))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 150)
                EVT_EXEC_WAIT(N(EVS_RandomSummon))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 100)
                EVT_EXEC_WAIT(N(EVS_RandomSummon))
                EVT_RETURN
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(RandInt, 100, LVar0)
    EVT_IF_LT(LVar0, 60)
        EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
        EVT_IF_FLAG(LVar0, STATUS_FLAG_DIZZY)
            EVT_EXEC_WAIT(N(EVS_Attack_Tackle))
        EVT_ELSE
            EVT_EXEC_WAIT(N(EVS_Attack_SleepySpin))
        EVT_END_IF
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_Attack_Tackle))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RandomSummon) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_11)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(RandInt, 2, LVar1)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_SummonShyGuy))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_SummonGrooveGuy))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_SummonMediGuy))
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(SpawnSpinFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 x, y, z;
    f32 scale;
    s32 duration;

    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);
    z = evt_get_variable(script, *args++);
    scale = evt_get_float_variable(script, *args++);
    duration = evt_get_variable(script, *args++);

    N(DummyPlayerStatus).pos.x = x;
    N(DummyPlayerStatus).pos.y = y;
    N(DummyPlayerStatus).pos.z = z;
    fx_effect_46(6, &N(DummyPlayerStatus), scale, duration);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_PerformSummonDance) = {
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0C)
    EVT_WAIT(4)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0B)
    EVT_WAIT(4)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0C)
    EVT_WAIT(4)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0D)
    EVT_WAIT(4)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0C)
    EVT_WAIT(4)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0B)
    EVT_WAIT(4)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0C)
    EVT_WAIT(4)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0D)
    EVT_WAIT(4)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_CALL_FOR_BACKUP)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0C)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_SETF(LVar3, EVT_FLOAT(1.0))
    EVT_ELSE
        EVT_SETF(LVar3, EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(N(SpawnSpinFX), LVar0, LVar1, LVar2, LVar3, 48)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_GROOVE_GUY_SUMMON)
    EVT_SET(LVar0, 0)
    EVT_LOOP(48)
        EVT_ADD(LVar0, 30)
        EVT_IF_GE(LVar0, 360)
            EVT_SUB(LVar0, 360)
        EVT_END_IF
        EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 30)
    EVT_PLAY_EFFECT(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, 30, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GrooveGuy_Anim0A)
    EVT_WAIT(8)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SummonShyGuy) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_EXEC_WAIT(N(EVS_PerformSummonDance))
    EVT_CALL(SummonEnemy, EVT_PTR(N(ShyGuyFormation)), FALSE)
    EVT_SET(LVarB, LVar0)
    EVT_SET(LVar0, 200)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_CALL(SetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, LVarB, PRT_MAIN, ANIM_ShyGuy_Red_Anim04)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetGoalToIndex, LVarB, LVarA)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK, SOUND_ACTOR_STEP_A, SOUND_ACTOR_STEP_B)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_WALK_INCREMENT, 10, 0)
    EVT_CALL(SetActorSpeed, LVarB, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, LVarB, 0, FALSE)
    EVT_CALL(SetAnimation, LVarB, PRT_MAIN, ANIM_ShyGuy_Red_Anim01)
    EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, LVarB)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SummonGrooveGuy) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_EXEC_WAIT(N(EVS_PerformSummonDance))
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SummonEnemy, EVT_PTR(N(GrooveGuyFormation)), FALSE)
    EVT_SET(LVarB, LVar0)
    EVT_CALL(SetAnimation, LVarB, PRT_MAIN, ANIM_GrooveGuy_Anim0C)
    EVT_CALL(SetGoalToIndex, LVarB, LVarA)
    EVT_CALL(GetGoalPos, LVarB, LVar3, LVar4, LVar5)
    EVT_ADD(LVar3, 200)
    EVT_CALL(SetActorPos, LVarB, LVar3, LVar4, LVar5)
    EVT_THREAD
        EVT_SET(LVar6, 0)
        EVT_LOOP(50)
            EVT_ADD(LVar6, 30)
            EVT_MOD(LVar6, 360)
            EVT_CALL(SetActorYaw, LVarB, LVar6)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorYaw, LVarB, 0)
    EVT_END_THREAD
    EVT_CALL(SetActorSounds, LVarB, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    EVT_THREAD
        EVT_LOOP(2)
            EVT_CALL(PlaySoundAtActor, LVarB, SOUND_GROOVE_GUY_TWIRL)
            EVT_WAIT(25)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetActorSpeed, LVarB, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, LVarB, 0, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMALL_LENS_FLARE)
    EVT_CALL(SetAnimation, LVarB, PRT_MAIN, ANIM_GrooveGuy_Anim0A)
    EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_PLAY_EFFECT(EFFECT_LENS_FLARE, 0, LVar0, LVar1, LVar2, 30, 0)
    EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, LVarB, LVar0, LVar1, LVar2)
    EVT_WAIT(25)
    EVT_CALL(SetAnimation, LVarB, PRT_MAIN, ANIM_GrooveGuy_Anim01)
    EVT_CALL(HPBarToHome, LVarB)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Generation, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, LVarB, AVAR_Generation, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, LVarB, AVAR_Generation, 2)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SummonMediGuy) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_EXEC_WAIT(N(EVS_PerformSummonDance))
    EVT_CALL(SummonEnemy, EVT_PTR(N(MediGuyFormation)), FALSE)
    EVT_SET(LVarB, LVar0)
    EVT_CALL(SetAnimation, LVarB, PRT_MAIN, ANIM_MediGuy_Anim05)
    EVT_ADD(LVarA, 4)
    EVT_CALL(SetGoalToIndex, LVarB, LVarA)
    EVT_CALL(GetGoalPos, LVarB, LVar3, LVar4, LVar5)
    EVT_SET(LVar0, 200)
    EVT_SET(LVar1, LVar4)
    EVT_SET(LVar2, LVar5)
    EVT_CALL(SetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorSounds, LVarB, ACTOR_SOUND_WALK, SOUND_SHY_GUY_FLY, SOUND_NONE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, LVarB, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, LVarB, 0, FALSE)
    EVT_CALL(SetAnimation, LVarB, PRT_MAIN, ANIM_MediGuy_Anim01)
    EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, LVarB)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

Vec3i N(SummonPos) = { NPC_DISPOSE_LOCATION };

Formation N(ShyGuyFormation) = {
    ACTOR_BY_POS(A(red_shy_guy), N(SummonPos), 100),
};

Formation N(GrooveGuyFormation) = {
    ACTOR_BY_POS(NAMESPACE, N(SummonPos), 100),
};

Formation N(MediGuyFormation) = {
    ACTOR_BY_POS(A(medi_guy), N(SummonPos), 100),
};
