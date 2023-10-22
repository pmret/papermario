#include "../area.h"
#include "sprite/npc/TheMaster.h"

#define NAMESPACE A(master2)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_BattleCry      = 0,
    AVAR_Unused         = 1,
    AVAR_WasHit         = 2,
    AVAR_HitCounter     = 3,
};

enum N(ActorParams) {
    DMG_STRIKE_ONCE         = 8,
    DMG_STRIKE_TWICE_1      = 5,
    DMG_STRIKE_TWICE_2      = 6,
};

// AVAR_HitCounter starts at this value, for some reason
#define INITIAL_HIT_COUNT 2

s32 N(BaseAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_TheMaster_Walk,
    STATUS_KEY_STONE,     ANIM_TheMaster_Still,
    STATUS_KEY_SLEEP,     ANIM_TheMaster_Sleep,
    STATUS_KEY_POISON,    ANIM_TheMaster_Still,
    STATUS_KEY_STOP,      ANIM_TheMaster_Still,
    STATUS_KEY_STATIC,    ANIM_TheMaster_Still,
    STATUS_KEY_PARALYZE,  ANIM_TheMaster_Still,
    STATUS_KEY_DIZZY,     ANIM_TheMaster_Dizzy,
    STATUS_KEY_DIZZY,     ANIM_TheMaster_Dizzy,
    STATUS_END,
};

s32 N(AscendedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_TheMaster_AscendedWalk,
    STATUS_KEY_STONE,     ANIM_TheMaster_AscendedStill,
    STATUS_KEY_SLEEP,     ANIM_TheMaster_AscendedSleep,
    STATUS_KEY_POISON,    ANIM_TheMaster_AscendedStill,
    STATUS_KEY_STOP,      ANIM_TheMaster_AscendedStill,
    STATUS_KEY_STATIC,    ANIM_TheMaster_AscendedStill,
    STATUS_KEY_PARALYZE,  ANIM_TheMaster_AscendedStill,
    STATUS_KEY_DIZZY,     ANIM_TheMaster_AscendedDizzy,
    STATUS_KEY_DIZZY,     ANIM_TheMaster_AscendedDizzy,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,             50,
    STATUS_KEY_DEFAULT,            50,
    STATUS_KEY_SLEEP,              30,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              30,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           30,
    STATUS_KEY_SHRINK,             40,
    STATUS_KEY_STOP,               50,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -2,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,        -1,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -5, 28 },
        .opacity = 255,
        .idleAnimations = N(BaseAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 2, -7 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_THE_MASTER_2,
    .level = ACTOR_LEVEL_THE_MASTER_2,
    .maxHP = 75,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 100,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 30, 35 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 30 },
    .statusTextOffset = { 10, 30 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_BattleCry, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unused, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_WasHit, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HitCounter, INITIAL_HIT_COUNT)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_NO_GAME_OVER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent_Inner) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedHurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_TheMaster_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_TheMaster_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedDefeated)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedHurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedHurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedHurt)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedRun)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0))
            EVT_WAIT(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedWalk)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedIdle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedHurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedDefeated)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedHurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedDefeated)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedHurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedDefeated)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedIdle)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedIdle)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_TheMaster_AscendedRun)
            EVT_SET_CONST(LVar2, ANIM_TheMaster_AscendedHurt)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_StrikeOnce) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedRun)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.8))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_STANCE_CHANGE)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_STANCE_CHANGE)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedPunch)
    EVT_WAIT(30)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedKick)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_KICK)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_FLUTTER)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 0, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -50, 0, 0)
            EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
            EVT_WAIT(10)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedRun)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_SELF, 5, FALSE)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_SMACK)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_FLUTTER)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_STRIKE_ONCE, BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_FLUTTER)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 20, 0)
                EVT_SET(LVar0, 0)
                EVT_LOOP(10)
                    EVT_ADD(LVar0, 36)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 50)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.2))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedMidair)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_A)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedLand)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT(3)
            EVT_ADD(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedMidair)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_B)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedLand)
            EVT_WAIT(20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedRun)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_StrikeTwice) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_08)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 200)
    EVT_CALL(SetBattleCamOffsetZ, 13)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedDownwardStance)
    EVT_WAIT(40)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_07)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_WAIT(10)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_LEAP)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_FLUTTER)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 0, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -50, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedPalmStance)
            EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
            EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
            EVT_WAIT(10)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedRun)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedPalmStance)
    EVT_CALL(RunToGoal, ACTOR_SELF, 5, FALSE)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(4.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(3.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(2.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.0))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_SMACK)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_FLUTTER)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_STRIKE_TWICE_1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_WAIT(15)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_JUMP)
        EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedUppercut)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.9))
        EVT_CALL(JumpToGoal, ACTOR_SELF, 25, FALSE, TRUE, FALSE)
        EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_WAIT(2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_SMACK)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_FLUTTER)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_STRIKE_TWICE_2, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_WAIT(15)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_FLIP)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MASTER_FLUTTER)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 10, 0)
                EVT_SET(LVar0, 0)
                EVT_LOOP(10)
                    EVT_ADD(LVar0, 36)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 50)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedMidair)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 30, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_A)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedLand)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_WAIT(3)
            EVT_ADD(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedMidair)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_STEP_B)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedLand)
            EVT_WAIT(20)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.8))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedRun)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedIdle)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(RandInt, 100, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_LT(20)
            EVT_EXEC_WAIT(N(EVS_Attack_StrikeTwice))
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(N(EVS_Attack_StrikeOnce))
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_BattleCry, LVar0)
            EVT_IF_EQ(LVar0, FALSE)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                EVT_WAIT(10)
                EVT_CALL(ActorSpeak, MSG_MAC_Gate_002E, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Talk, ANIM_TheMaster_Walk)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_BattleCry, TRUE)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Cough)
                EVT_WAIT(15)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_OpenMouth)
                EVT_WAIT(5)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_GHOST_TRANSFORM)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 20)
                EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 30, 0)
                EVT_SET(LVar0, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Still)
                EVT_LOOP(15)
                    EVT_ADD(LVar0, 24)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_SET(LVar0, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Still)
                EVT_LOOP(5)
                    EVT_ADD(LVar0, 18)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SMOKE_BURST)
                EVT_THREAD
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_ADD(LVar1, 3)
                    EVT_LOOP(3)
                        EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
                        EVT_WAIT(3)
                    EVT_END_LOOP
                EVT_END_THREAD
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_Still)
                EVT_LOOP(5)
                    EVT_ADD(LVar0, 36)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedStill)
                EVT_LOOP(5)
                    EVT_ADD(LVar0, 18)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_WAIT(15)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(AscendedAnims)))
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedRun)
                EVT_WAIT(15)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, MSG_MAC_Gate_0033, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedTalk, ANIM_TheMaster_AscendedWalk)
            EVT_END_IF
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAGS_DOJO)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
            EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
            EVT_DIV(LVar1, 2)
            EVT_IF_LE(LVar0, LVar1)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, MSG_MAC_Gate_0036, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedTalk, ANIM_TheMaster_AscendedWalk)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(GetPlayerHP, LVar0)
            EVT_IF_LE(LVar0, 5)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, MSG_MAC_Gate_0037, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedTalk, ANIM_TheMaster_AscendedWalk)
                EVT_BREAK_SWITCH
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_EXEC_WAIT(N(EVS_HandleEvent_Inner))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAGS_DOJO)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleFlags, LVar0)
    EVT_IF_FLAG(LVar0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)
        EVT_CALL(GetLastDamage, ACTOR_SELF, LVar0)
        EVT_IF_GT(LVar0, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_WasHit, TRUE)
            EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_HitCounter, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_SPIN_SMASH_HIT)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_WasHit, LVarA)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HitCounter, LVarB)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_WasHit, FALSE)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAGS_DOJO | STATUS_FLAG_POISON | STATUS_FLAG_SHRINK)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_SET(LFlag0, FALSE)
            EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
            EVT_SWITCH(LVar0)
                EVT_CASE_OR_EQ(BTL_MENU_TYPE_SMASH)
                EVT_CASE_OR_EQ(BTL_MENU_TYPE_JUMP)
                    EVT_SET(LFlag0, TRUE)
                EVT_END_CASE_GROUP
            EVT_END_SWITCH
            EVT_IF_EQ(LFlag0, FALSE)
                EVT_BREAK_SWITCH
            EVT_END_IF
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            EVT_IF_EQ(LVarA, TRUE)
                EVT_IF_GT(LVarB, INITIAL_HIT_COUNT)
                    // 'Nice maneuver.'
                    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                    EVT_CALL(MoveBattleCamOver, 10)
                    EVT_CALL(ActorSpeak, MSG_MAC_Gate_0035, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedTalk, ANIM_TheMaster_AscendedWalk)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HitCounter, 0)
                EVT_END_IF
            EVT_ELSE
                // 'You can't defeat me like that'
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_CALL(ActorSpeak, MSG_MAC_Gate_0034, ACTOR_SELF, PRT_MAIN, ANIM_TheMaster_AscendedTalk, ANIM_TheMaster_AscendedWalk)
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
