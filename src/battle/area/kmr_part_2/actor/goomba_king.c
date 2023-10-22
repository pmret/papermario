#include "../area.h"
#include "sprite/npc/GoombaKing.h"
#include "sprite/npc/GoombaBros.h"
#include "sprite/player.h"
#include "goomba_king_common.h"

#define NAMESPACE A(goomba_king)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_ShakeScreenWhileWalking);
extern EvtScript N(EVS_Attack_GroundStomp);
extern EvtScript N(EVS_Attack_SpinSwipe);
extern EvtScript N(EVS_GoombaKing_Death);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_TARGET      = 2,
};

enum N(ActorVars) {
    AVAR_Unused_0               = 0,
    AVAR_Unused_1               = 1,
    AVAR_IncreaseShaking        = 2, // when TRUE walking around causes more camera shaking
    AVAR_Scene_BeginBattle      = 3,
    AVAR_ScreenShakingScriptID  = 4,
    AVAR_Unused_5               = 5,
};

enum N(ActorParams) {
    DMG_SPIN        = 1,
    DMG_STOMP       = 2,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_GoombaKing_Idle,
    STATUS_KEY_STONE,     ANIM_GoombaKing_Still,
    STATUS_KEY_SLEEP,     ANIM_GoombaKing_Sleep,
    STATUS_KEY_POISON,    ANIM_GoombaKing_Still,
    STATUS_KEY_STOP,      ANIM_GoombaKing_Still,
    STATUS_KEY_STATIC,    ANIM_GoombaKing_Still,
    STATUS_KEY_PARALYZE,  ANIM_GoombaKing_Still,
    STATUS_KEY_DIZZY,     ANIM_GoombaKing_Dizzy,
    STATUS_END,
};

// while shuffling around during idle
s32 N(ShuffleAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_GoombaKing_Run,
    STATUS_KEY_STONE,     ANIM_GoombaKing_Still,
    STATUS_KEY_SLEEP,     ANIM_GoombaKing_Sleep,
    STATUS_KEY_POISON,    ANIM_GoombaKing_Still,
    STATUS_KEY_STOP,      ANIM_GoombaKing_Still,
    STATUS_KEY_STATIC,    ANIM_GoombaKing_Still,
    STATUS_KEY_PARALYZE,  ANIM_GoombaKing_Still,
    STATUS_KEY_DIZZY,     ANIM_GoombaKing_Dizzy,
    STATUS_END,
};

s32 N(UnusedDizzyAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_GoombaKing_Dizzy,
    STATUS_KEY_STONE,     ANIM_GoombaKing_Still,
    STATUS_KEY_SLEEP,     ANIM_GoombaKing_Sleep,
    STATUS_KEY_POISON,    ANIM_GoombaKing_Still,
    STATUS_KEY_STOP,      ANIM_GoombaKing_Still,
    STATUS_KEY_STATIC,    ANIM_GoombaKing_Still,
    STATUS_KEY_PARALYZE,  ANIM_GoombaKing_Still,
    STATUS_KEY_DIZZY,     ANIM_GoombaKing_Dizzy,
    STATUS_END,
};

s32 N(UnusedAngryAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_GoombaKing_Angry,
    STATUS_KEY_STONE,     ANIM_GoombaKing_Still,
    STATUS_KEY_SLEEP,     ANIM_GoombaKing_Sleep,
    STATUS_KEY_POISON,    ANIM_GoombaKing_Still,
    STATUS_KEY_STOP,      ANIM_GoombaKing_Still,
    STATUS_KEY_STATIC,    ANIM_GoombaKing_Still,
    STATUS_KEY_PARALYZE,  ANIM_GoombaKing_Still,
    STATUS_KEY_DIZZY,     ANIM_GoombaKing_Dizzy,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,             100,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,            100,
    STATUS_KEY_STOP,              100,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
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
        .flags = ACTOR_PART_FLAG_IGNORE_BELOW_CHECK | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -25, 15 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_IGNORE_BELOW_CHECK | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_TARGET,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 80 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GOOMBA_KING,
    .level = ACTOR_LEVEL_GOOMBA_KING,
    .maxHP = 10,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 56, 80 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -6, 38 },
    .statusTextOffset = { 12, 75 },
};

// Unused
API_CALLABLE(N(SpawnImpactDustFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);

    fx_landing_dust(2, x, y, z, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_EXEC_GET_TID(N(EVS_ShakeScreenWhileWalking), LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_ScreenShakingScriptID, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unused_0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unused_1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IncreaseShaking, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Scene_BeginBattle, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unused_5, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TREE_DELAY, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_CALL(RandInt, 80, LVar0)
        EVT_ADD(LVar0, 80)
        EVT_WAIT(LVar0)
        EVT_LABEL(1)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_WAIT(1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_CALL(SetGoalToHome, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ShuffleAnims)))
        EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IdleRunToGoal, ACTOR_SELF, 0)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
        EVT_WAIT(20)
        EVT_LABEL(2)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_WAIT(1)
                EVT_GOTO(2)
            EVT_END_IF
        EVT_CALL(SetGoalToHome, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(ShuffleAnims)))
        EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IdleRunToGoal, ACTOR_SELF, 0)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
        EVT_WAIT(80)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript A(EVS_Lee_ShockKnockback) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar0, LVar1)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
    EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_B)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 15, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_B)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 5, 0, 0)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_B)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_GoombaKing_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(A(EVS_Lee_ShockKnockback))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Run)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScreenShakingScriptID, LVar0)
            EVT_KILL_THREAD(LVar0)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(N(EVS_GoombaKing_Death))
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScreenShakingScriptID, LVar0)
            EVT_KILL_THREAD(LVar0)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(N(EVS_GoombaKing_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_GoombaKing_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_WAIT(10)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScreenShakingScriptID, LVar0)
            EVT_KILL_THREAD(LVar0)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_BurnStill)
            EVT_EXEC_WAIT(N(EVS_GoombaKing_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_ScreenShakingScriptID, LVar0)
            EVT_KILL_THREAD(LVar0)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Dead)
            EVT_EXEC_WAIT(N(EVS_GoombaKing_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Dead)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Idle)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_GoombaKing_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorVar, ACTOR_TREE, AVAR_TREE_DELAY, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_CALL(RandInt, 100, LVar1)
            EVT_IF_LT(LVar1, 60)
                EVT_SUB(LVar0, 1)
                EVT_CALL(SetActorVar, ACTOR_TREE, AVAR_TREE_DELAY, LVar0)
                EVT_EXEC_WAIT(N(EVS_Attack_GroundStomp))
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_Attack_SpinSwipe))
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_SpinSwipe) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        EVT_CALL(AddBattleCamZoom, -100)
        EVT_CALL(SetBattleCamOffsetZ, 20)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 30)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
        EVT_CALL(AddBattleCamZoom, -100)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_END_IF
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 32, 0, 0)
    EVT_ELSE
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 12, 0, 0)
    EVT_END_IF
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Run)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Idle)
    EVT_WAIT(8)
    EVT_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_GOOMBA_KING_SPIN)
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_GOOMBA_KING_SPIN)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Kick)
    EVT_SET(LVar0, 0)
    EVT_LOOP(20)
        EVT_ADD(LVar0, 18)
        EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Dizzy)
            EVT_SET(LVar0, 0)
            EVT_LOOP(20)
                EVT_ADD(LVar0, 18)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Idle)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Run)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Idle)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVarA, 0, 0, 0, DMG_SPIN, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Idle)
    EVT_SWITCH(LVarA)
        EVT_CASE_DEFAULT
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Idle)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(3.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Run)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Idle)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_GroundStomp) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_15)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_WAIT(15)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Angry)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_HEAVY_NPC_STEP_B)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Still)
    EVT_THREAD
        EVT_CALL(StartRumble, BTL_RUMBLE_PLAYER_MAX)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 10, EVT_FLOAT(4.0))
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_GoombaKing_Idle)
        EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, -80, 125, 0, 100, 0)
        EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, -15, 135, 0, 85, 0)
        EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, 100, 103, 0, 70, 0)
    EVT_END_THREAD
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_THREAD
                EVT_WAIT(12)
                EVT_CALL(PlaySoundAtPart, ACTOR_TREE, PRT_TREE_NUT_1, SOUND_FALL_QUICK)
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT(10)
                EVT_CALL(SetPartJumpGravity, ACTOR_TREE, PRT_TREE_NUT_1, EVT_FLOAT(1.5))
                EVT_CALL(GetPartOffset, ACTOR_TREE, PRT_TREE_NUT_1, LVar0, LVar1, LVar2)
                EVT_CALL(FallPartTo, ACTOR_TREE, PRT_TREE_NUT_1, LVar0, 10, LVar2, 14)
                EVT_SUB(LVar0, 12)
                EVT_CALL(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_1, LVar0, 10, LVar2, 10, TRUE)
                EVT_SUB(LVar0, 7)
                EVT_CALL(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_1, LVar0, 10, LVar2, 7, TRUE)
                EVT_LOOP(20)
                    EVT_CALL(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    EVT_WAIT(1)
                    EVT_CALL(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT(5)
                EVT_CALL(PlaySoundAtPart, ACTOR_TREE, PRT_TREE_NUT_2, SOUND_FALL_QUICK)
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT(3)
                EVT_CALL(SetPartJumpGravity, ACTOR_TREE, PRT_TREE_NUT_2, EVT_FLOAT(1.5))
                EVT_CALL(GetPartOffset, ACTOR_TREE, PRT_TREE_NUT_2, LVar0, LVar1, LVar2)
                EVT_CALL(FallPartTo, ACTOR_TREE, PRT_TREE_NUT_2, LVar0, 10, LVar2, 15)
                EVT_SUB(LVar0, 12)
                EVT_CALL(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_2, LVar0, 10, LVar2, 10, TRUE)
                EVT_SUB(LVar0, 7)
                EVT_CALL(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_2, LVar0, 10, LVar2, 7, TRUE)
                EVT_LOOP(20)
                    EVT_CALL(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    EVT_WAIT(1)
                    EVT_CALL(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT(17)
                EVT_CALL(PlaySoundAtPart, ACTOR_TREE, PRT_TREE_NUT_3, SOUND_FALL_QUICK)
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT(15)
                EVT_CALL(SetPartJumpGravity, ACTOR_TREE, PRT_TREE_NUT_3, EVT_FLOAT(1.5))
                EVT_CALL(GetPartOffset, ACTOR_TREE, PRT_TREE_NUT_3, LVar0, LVar1, LVar2)
                EVT_CALL(FallPartTo, ACTOR_TREE, PRT_TREE_NUT_3, LVar0, 10, LVar2, 17)
                EVT_ADD(LVar0, 12)
                EVT_CALL(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_3, LVar0, 10, LVar2, 10, TRUE)
                EVT_ADD(LVar0, 7)
                EVT_CALL(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_3, LVar0, 10, LVar2, 7, TRUE)
                EVT_LOOP(20)
                    EVT_CALL(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    EVT_WAIT(1)
                    EVT_CALL(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_WAIT(15)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_WAIT(12)
        EVT_CALL(PlaySoundAtPart, ACTOR_TREE, PRT_TREE_NUT_1, SOUND_FALL_QUICK)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetPartJumpGravity, ACTOR_TREE, PRT_TREE_NUT_1, EVT_FLOAT(1.5))
        EVT_CALL(GetPartOffset, ACTOR_TREE, PRT_TREE_NUT_1, LVar0, LVar1, LVar2)
        EVT_CALL(FallPartTo, ACTOR_TREE, PRT_TREE_NUT_1, LVar0, 35, LVar2, 14)
        EVT_SUB(LVar0, 12)
        EVT_CALL(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_1, LVar0, 10, LVar2, 10, TRUE)
        EVT_SUB(LVar0, 7)
        EVT_CALL(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_1, LVar0, 10, LVar2, 7, TRUE)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtPart, ACTOR_TREE, PRT_TREE_NUT_2, SOUND_FALL_QUICK)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(SetPartJumpGravity, ACTOR_TREE, PRT_TREE_NUT_2, EVT_FLOAT(1.5))
        EVT_CALL(GetPartOffset, ACTOR_TREE, PRT_TREE_NUT_2, LVar0, LVar1, LVar2)
        EVT_CALL(FallPartTo, ACTOR_TREE, PRT_TREE_NUT_2, LVar0, 10, LVar2, 15)
        EVT_SUB(LVar0, 12)
        EVT_CALL(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_2, LVar0, 10, LVar2, 10, TRUE)
        EVT_SUB(LVar0, 7)
        EVT_CALL(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_2, LVar0, 10, LVar2, 7, TRUE)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_2, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_2, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(17)
        EVT_CALL(PlaySoundAtPart, ACTOR_TREE, PRT_TREE_NUT_3, SOUND_FALL_QUICK)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(SetPartJumpGravity, ACTOR_TREE, PRT_TREE_NUT_3, EVT_FLOAT(1.5))
        EVT_CALL(GetPartOffset, ACTOR_TREE, PRT_TREE_NUT_3, LVar0, LVar1, LVar2)
        EVT_CALL(FallPartTo, ACTOR_TREE, PRT_TREE_NUT_3, LVar0, 10, LVar2, 17)
        EVT_ADD(LVar0, 12)
        EVT_CALL(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_3, LVar0, 10, LVar2, 10, TRUE)
        EVT_ADD(LVar0, 7)
        EVT_CALL(JumpPartTo, ACTOR_TREE, PRT_TREE_NUT_3, LVar0, 10, LVar2, 7, TRUE)
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_TREE, PRT_TREE_NUT_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(24)
    EVT_WAIT(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, SUPPRESS_EVENT_ALL, 0, DMG_STOMP, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(HIT_RESULT_10)
            EVT_RETURN
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
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Scene_BeginBattle, LVar0)
            EVT_IF_EQ(LVar0, FALSE)
                EVT_CALL(EnableBattleStatusBar, FALSE)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
                EVT_CALL(BattleCamTargetActor, ACTOR_RED_GOOMBA)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT(20)
                EVT_CALL(UseIdleAnimation, ACTOR_RED_GOOMBA, FALSE)
                EVT_CALL(EnableIdleScript, ACTOR_RED_GOOMBA, IDLE_SCRIPT_DISABLE)
                EVT_CALL(ActorSpeak, MSG_CH0_00CB, ACTOR_RED_GOOMBA, PRT_MAIN, ANIM_GoombaBros_Red_Talk, ANIM_GoombaBros_Red_Talk)
                EVT_CALL(EnableIdleScript, ACTOR_RED_GOOMBA, IDLE_SCRIPT_ENABLE)
                EVT_CALL(UseIdleAnimation, ACTOR_RED_GOOMBA, TRUE)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
                EVT_CALL(BattleCamTargetActor, ACTOR_BLUE_GOOMBA)
                EVT_CALL(MoveBattleCamOver, 10)
                EVT_WAIT(10)
                EVT_CALL(UseIdleAnimation, ACTOR_BLUE_GOOMBA, FALSE)
                EVT_CALL(EnableIdleScript, ACTOR_BLUE_GOOMBA, IDLE_SCRIPT_DISABLE)
                EVT_CALL(ActorSpeak, MSG_CH0_00CC, ACTOR_BLUE_GOOMBA, PRT_MAIN, ANIM_GoombaBros_Blue_Talk, ANIM_GoombaBros_Blue_Talk)
                EVT_CALL(EnableIdleScript, ACTOR_BLUE_GOOMBA, IDLE_SCRIPT_ENABLE)
                EVT_CALL(UseIdleAnimation, ACTOR_BLUE_GOOMBA, TRUE)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_KING)
                EVT_CALL(MoveBattleCamOver, 20)
                EVT_WAIT(20)
                EVT_CALL(ActorSpeak, MSG_CH0_00CD, ACTOR_KING, PRT_MAIN, ANIM_GoombaKing_Angry, ANIM_GoombaKing_Angry)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Scene_BeginBattle, TRUE)
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
                EVT_CALL(EnableBattleStatusBar, TRUE)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShakeScreenWhileWalking) = {
    EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_CALL(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
        EVT_IF_NE(LVar0, ANIM_GoombaKing_Run)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(GetAnimation, ACTOR_SELF, PRT_MAIN, LVar0)
        EVT_IF_NE(LVar0, ANIM_GoombaKing_Run)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(StartRumble, BTL_RUMBLE_LONG)
        EVT_CALL(GetPartAnimNotify, ACTOR_SELF, PRT_MAIN, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IncreaseShaking, LVar0)
            EVT_IF_EQ(LVar0, FALSE)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.2))
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.7))
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GoombaKing_Death) = {
    EVT_CALL(HideHealthBar, ACTOR_SELF)
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
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_DEATH)
    EVT_CALL(DropStarPoints, ACTOR_SELF)
    EVT_SET(LVar3, 0)
    EVT_LOOP(12)
        EVT_CALL(SetActorRotation, ACTOR_SELF, LVar3, 0, 0)
        EVT_ADD(LVar3, 8)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
    EVT_WAIT(30)
    EVT_CALL(ActorExists, ACTOR_RED_GOOMBA, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(GetActorHP, ACTOR_RED_GOOMBA, LVar0)
    EVT_END_IF
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(UseIdleAnimation, ACTOR_RED_GOOMBA, FALSE)
        EVT_CALL(EnableIdleScript, ACTOR_RED_GOOMBA, IDLE_SCRIPT_DISABLE)
        EVT_CALL(ActorSpeak, MSG_CH0_00CF, ACTOR_RED_GOOMBA, PRT_MAIN, ANIM_GoombaBros_Red_CryTalk, ANIM_GoombaBros_Red_CryTalk)
        EVT_CALL(EnableIdleScript, ACTOR_RED_GOOMBA, IDLE_SCRIPT_ENABLE)
        EVT_CALL(UseIdleAnimation, ACTOR_RED_GOOMBA, TRUE)
    EVT_END_IF
    EVT_CALL(ActorExists, ACTOR_BLUE_GOOMBA, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(GetActorHP, ACTOR_BLUE_GOOMBA, LVar0)
    EVT_END_IF
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(UseIdleAnimation, ACTOR_BLUE_GOOMBA, FALSE)
        EVT_CALL(EnableIdleScript, ACTOR_BLUE_GOOMBA, IDLE_SCRIPT_DISABLE)
        EVT_CALL(ActorSpeak, MSG_CH0_00D0, ACTOR_BLUE_GOOMBA, PRT_MAIN, ANIM_GoombaBros_Blue_CryTalk, ANIM_GoombaBros_Blue_CryTalk)
        EVT_CALL(EnableIdleScript, ACTOR_BLUE_GOOMBA, IDLE_SCRIPT_ENABLE)
        EVT_CALL(UseIdleAnimation, ACTOR_BLUE_GOOMBA, TRUE)
    EVT_END_IF
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};
