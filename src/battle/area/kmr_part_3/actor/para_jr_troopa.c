#include "../area.h"
#include "sprite/npc/JrTroopa.h"
#include "sprite/npc/ParaJrTroopa.h"

#define NAMESPACE A(para_jr_troopa)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_JrTroopa_Death);
extern EvtScript N(EVS_JrTroopa_FlyHome);
extern EvtScript N(EVS_TryFearReaction);

enum N(ActorPartIDs) {
    PRT_GROUND      = 1,
    PRT_FLYING      = 2,
};

enum N(ActorVars) {
    AVAR_Transformed        = 0,
    AVAR_SpookReact         = 1,
    AVAL_SpookReact_None    = 0,
    AVAL_SpookReact_Ready   = 1,
};

enum N(ActorParams) {
    DMG_DIVE        = 5,
};

s32 N(FlyingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_ParaJrTroopa_Idle,
    STATUS_KEY_SLEEP,     ANIM_ParaJrTroopa_Sleep,
    STATUS_KEY_STONE,     ANIM_ParaJrTroopa_Still,
    STATUS_KEY_POISON,    ANIM_ParaJrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_ParaJrTroopa_Still,
    STATUS_KEY_STATIC,    ANIM_ParaJrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_ParaJrTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_ParaJrTroopa_Dizzy,
    STATUS_END,
};

s32 N(BaseAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Idle,
    STATUS_KEY_SLEEP,     ANIM_JrTroopa_Sleep,
    STATUS_KEY_STONE,     ANIM_JrTroopa_Still,
    STATUS_KEY_POISON,    ANIM_JrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_JrTroopa_Still,
    STATUS_KEY_STATIC,    ANIM_JrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_JrTroopa_Still,
    STATUS_KEY_DIZZY,     ANIM_JrTroopa_Dizzy,
    STATUS_END,
};

s32 N(DefeatedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Defeated,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,              50,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              50,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           50,
    STATUS_KEY_SHRINK,             80,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_GROUND,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 35 },
        .opacity = 255,
        .idleAnimations = N(FlyingAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -6 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_FLYING,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(BaseAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_JR_TROOPA_3,
    .level = ACTOR_LEVEL_JR_TROOPA_3,
    .maxHP = 40,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 60, 35 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -25, 35 },
    .statusTextOffset = { 10, 25 },
};

EvtScript N(EVS_SetupFearReaction) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar2)
    EVT_IF_FLAG(LVar2, STATUS_FLAGS_IMMOBILIZED)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleFlags, LVar2)
    EVT_IF_FLAG(LVar2, BS_FLAGS1_PARTNER_ACTING)
        EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVar2, MOVE_SPOOK)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_SpookReact, AVAL_SpookReact_Ready)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_EMOTE_QUESTION)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 30)
            EVT_CALL(ShowEmote, 0, EMOTE_QUESTION, -45, 30, EMOTER_POS, LVar0, LVar1, LVar2, 5)
            EVT_WAIT(30)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Transform) = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_JR_TROOPA_TRANSFORM)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
    EVT_IF_NOT_FLAG(LVar3, STATUS_FLAG_SHRINK)
        EVT_ADD(LVar1, 16)
    EVT_ELSE
        EVT_ADD(LVar1, 6)
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, 1, 30, 0)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar1, LVar2, 1, 30, 0)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(32)
            EVT_WAIT(1)
            EVT_ADD(LVar0, 45)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, LVar0, 0)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(32)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_JR_TROOPA_NEW_POWER)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, 1, 40, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, -4, 0, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, -4, 4, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, 4, 0, 0)
    EVT_PLAY_EFFECT(EFFECT_WALKING_DUST, 0, LVar0, LVar1, LVar2, 4, 4, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Cam_FocusOnJrTroopa) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_07)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamOffsetZ, 38)
    EVT_CALL(SetBattleCamZoom, 256)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Cam_ResetFocus) = {
    EVT_CALL(EnableBattleStatusBar, TRUE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 12)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Cam_FocusOnGoompa) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_55)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Transformed, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_SpookReact, AVAL_SpookReact_None)
    EVT_RETURN
    EVT_END
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_DIZZY | STATUS_FLAG_SLEEP)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_GROUND, -12, 28)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_GROUND, 4, -6)
            EVT_CALL(N(SetAbsoluteStatusOffsets), -25, 27, -1, 27)
        EVT_ELSE
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_GROUND, -5, 33)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_GROUND, 0, -6)
            EVT_CALL(N(SetAbsoluteStatusOffsets), -22, 30, 2, 28)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
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
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(EVS_SetupFearReaction))
            EVT_EXEC_WAIT(N(EVS_TryFearReaction))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(N(EVS_JrTroopa_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar0, PRT_GROUND)
            EVT_SET(LVar1, ANIM_ParaJrTroopa_BurnHurt)
            EVT_SET(LVar2, ANIM_ParaJrTroopa_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LVar0, PRT_GROUND)
            EVT_SET(LVar1, ANIM_ParaJrTroopa_BurnHurt)
            EVT_SET(LVar2, ANIM_ParaJrTroopa_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_BurnStill)
            EVT_EXEC_WAIT(N(EVS_JrTroopa_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(N(EVS_JrTroopa_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_EXEC_WAIT(N(EVS_JrTroopa_FlyHome))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Idle)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Idle)
            EVT_EXEC_WAIT(N(EVS_JrTroopa_Death))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_EXEC_WAIT(N(EVS_SetupFearReaction))
            EVT_EXEC_WAIT(N(EVS_TryFearReaction))
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Hurt)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_FlyFast)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Idle)
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Flail)
                EVT_WAIT(1000)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_SET_CONST(LVar0, PRT_GROUND)
                EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Flail)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
                EVT_EXEC_WAIT(N(EVS_Cam_FocusOnJrTroopa))
                EVT_CALL(ActorSpeak, MSG_Menus_019B, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Talk, ANIM_ParaJrTroopa_Talk)
                EVT_EXEC_WAIT(N(EVS_Cam_ResetFocus))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_ReturnHome)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_GROUND)
            EVT_SET_CONST(LVar1, ANIM_ParaJrTroopa_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Overshoot_Unused) = {
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 40)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_ADD(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
    EVT_SUB(LVar0, 10)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Idle)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Idle)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_FlyFast)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_FlyFast)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, EASING_LINEAR)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 5, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
            EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_PARAGOOMBA_PREDIVE, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_FlyFast)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_DIVE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_SUB(LVar0, 80)
            EVT_SET(LVar1, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Dive)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_FlyFast)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_GROUND, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_GROUND, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
            EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_PARAGOOMBA_PREDIVE, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_FlyFast)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_DIVE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Dive)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_DIVE, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_FlyFast)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
            EVT_WAIT(10)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_FlyFast)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Idle)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetBattlePhase, LVarF)
    EVT_SWITCH(LVarF)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            // trying showing the scene where Jr Troopa transforms
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Transformed, LVar0)
            EVT_IF_FALSE(LVar0)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Transformed, TRUE)
                EVT_WAIT(15)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
                EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
                EVT_CALL(SetBattleCamOffsetZ, 35)
                EVT_CALL(MoveBattleCamOver, 30)
                EVT_WAIT(30)
                EVT_CALL(ActorSpeak, MSG_CH3_0020, ACTOR_SELF, PRT_FLYING, ANIM_JrTroopa_PointTalk, ANIM_JrTroopa_PointTapFoot)
                EVT_WAIT(8)
                EVT_EXEC_WAIT(N(EVS_Transform))
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GROUND, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                EVT_WAIT(30)
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_ADD(LVar0, 20)
                EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 60, LVar2)
                EVT_CALL(FlyToGoal, ACTOR_SELF, 45, 0, EASING_LINEAR)
                EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, 60, LVar2)
                EVT_CALL(HPBarToHome, ACTOR_SELF)
                EVT_WAIT(8)
                EVT_CALL(ActorSpeak, MSG_CH3_0021, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Talk, ANIM_ParaJrTroopa_Idle)
                EVT_WAIT(10)
                EVT_EXEC_WAIT(N(EVS_Cam_ResetFocus))
            EVT_END_IF
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_JrTroopa_Death) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_IF_EQ(LVar1, 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(FallToGoal, ACTOR_SELF, 10)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_CALL(HPBarToCurrent, ACTOR_SELF)
    EVT_CALL(ShowHealthBar, ACTOR_SELF)
    EVT_LABEL(0)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 10)
        EVT_ADD(LVar2, 10)
        EVT_LOOP(3)
            EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_GROUND, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_JrTroopa_DefeatedBegin)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 5)
    EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_ACTOR_DEATH)
    EVT_CALL(DropStarPoints, ACTOR_SELF)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(SetBattleCamZoom, 260)
    EVT_CALL(SetBattleCamOffsetZ, 15)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_KNOCKOUT_CHIRPING)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_JrTroopa_Defeated)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, EVT_PTR(N(DefeatedAnims)))
    EVT_WAIT(60)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_JrTroopa_FlyHome) = {
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_FlyFast)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    EVT_SUB(LVar4, LVar1)
    EVT_MULF(LVar4, EVT_FLOAT(0.3))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, LVar4, EASING_LINEAR)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TryFearReaction) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_SpookReact, LVar0)
        EVT_IF_EQ(LVar0, AVAL_SpookReact_Ready)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_SpookReact, AVAL_SpookReact_None)
            EVT_WAIT(15)
            EVT_EXEC_WAIT(N(EVS_Cam_FocusOnJrTroopa))
            EVT_WAIT(10)
            EVT_CALL(ActorSpeak, MSG_Menus_019A, ACTOR_SELF, PRT_GROUND, ANIM_ParaJrTroopa_Talk, ANIM_ParaJrTroopa_Idle)
            EVT_WAIT(10)
            EVT_EXEC_WAIT(N(EVS_Cam_ResetFocus))
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
