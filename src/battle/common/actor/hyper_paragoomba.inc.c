#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Goomba.h"
#include "sprite/npc/Paragoomba.h"

#define NAMESPACE A(hyper_paragoomba)

extern s32 N(FlyingAnims)[];
extern s32 N(LeftWingAnims)[];
extern s32 N(RightWingAnims)[];
extern s32 N(DownedAnims)[];

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_Flying_HandlePhase);
extern EvtScript N(EVS_Flying_TakeTurn);
extern EvtScript N(EVS_Attack_SkyDive);
extern EvtScript N(EVS_ReturnHome);
extern EvtScript N(EVS_KnockDown);
extern EvtScript N(EVS_KnockDown_Init);
extern EvtScript N(EVS_Downed_Idle);
extern EvtScript N(EVS_Downed_HandleEvent);
extern EvtScript N(EVS_Downed_TakeTurn);
extern EvtScript N(EVS_Attack_Headbonk);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1, // body after being downed
    PRT_FLYING          = 2, // body while flying
    PRT_DUMMY_WING_L    = 3, // temporary wing while being downed
    PRT_DUMMY_WING_R    = 4, // temporary wing while being downed
};

enum N(ActorVars) {
    AVAR_IsCharged      = 0,
    AVAR_NotFirstTurn   = 1,
};

enum N(ActorParams) {
    DMG_SKY_DIVE        = 1,
    DMG_CHARGED_DIVE    = 8,
    DMG_HEADBONK        = 1,
    DMG_CHARGED_BONK    = 8,
};

s32 N(DownedDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(FlyingDefense)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(DownedStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              80,
    STATUS_KEY_POISON,            100,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              80,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,            100,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,             80,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

s32 N(FlyingStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              80,
    STATUS_KEY_POISON,             80,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              90,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             80,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,             80,
    STATUS_KEY_STOP,               90,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 22 },
        .opacity = 255,
        .idleAnimations = N(DownedAnims),
        .defenseTable = N(DownedDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_FLYING,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(FlyingAnims),
        .defenseTable = N(FlyingDefense),
        .eventFlags = ACTOR_EVENT_FLAG_GROUNDABLE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_DUMMY_WING_L,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -16, 24 },
        .opacity = 255,
        .idleAnimations = N(LeftWingAnims),
        .defenseTable = N(DownedDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_DUMMY_WING_R,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -16, 24 },
        .opacity = 255,
        .idleAnimations = N(RightWingAnims),
        .defenseTable = N(DownedDefense),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -10 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_HYPER_PARAGOOMBA,
    .level = ACTOR_LEVEL_HYPER_PARAGOOMBA,
    .maxHP = 7,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(FlyingStatusTable),
    .escapeChance = 50,
    .airLiftChance = 95,
    .hurricaneChance = 95,
    .spookChance = 80,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 1,
    .size = { 36, 26 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(ChargedFlyingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Paragoomba_Hyper_Miss,
    STATUS_KEY_STONE,     ANIM_Paragoomba_Hyper_Still,
    STATUS_KEY_SLEEP,     ANIM_Paragoomba_Hyper_Sleep,
    STATUS_KEY_POISON,    ANIM_Paragoomba_Hyper_Miss,
    STATUS_KEY_STOP,      ANIM_Paragoomba_Hyper_Still,
    STATUS_KEY_STATIC,    ANIM_Paragoomba_Hyper_Miss,
    STATUS_KEY_PARALYZE,  ANIM_Paragoomba_Hyper_Still,
    STATUS_KEY_DIZZY,     ANIM_Paragoomba_Hyper_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Paragoomba_Hyper_Dizzy,
    STATUS_END,
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_Flying_HandlePhase)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_Flying_TakeTurn)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsCharged, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Flying_HandlePhase) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_END)
            EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_None)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, TRUE)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_ChargedDive) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsCharged, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_POWER_UP)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 10)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 6, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 45, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Miss)
        EVT_WAIT(30)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, FALSE, FALSE)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsCharged, TRUE)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, EVT_PTR(N(ChargedFlyingAnims)))
        EVT_CALL(EnableActorGlow, ACTOR_SELF, TRUE)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_FLYING, ACTOR_EVENT_FLAG_ATTACK_CHARGED, TRUE)
        EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_LOOP(20)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, 1, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_PREDIVE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_DIVE)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -60)
            EVT_THREAD
                EVT_SET(LVar0, -60)
                EVT_LOOP(60)
                    EVT_ADD(LVar0, 19)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(15.0))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, FALSE, FALSE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_01)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -60, 0, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.3))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(AddGoalPos, ACTOR_SELF, -200, 0, 0)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_FLYING, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            EVT_THREAD
                EVT_SET(LVar0, 0)
                EVT_LOOP(30)
                    EVT_ADD(LVar0, 24)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(SetActorPos, ACTOR_SELF, 300, 0, 0)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_FLYING, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_SIN_OUT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_FLYING, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsCharged, FALSE)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, EVT_PTR(N(FlyingAnims)))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, -70)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(15.0))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, FALSE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_CHARGED_DIVE, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 16, 0)
                EVT_SET(LVar0, -70)
                EVT_LOOP(60)
                    EVT_ADD(LVar0, 18)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 0)
            EVT_SUB(LVar0, 70)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, FALSE, FALSE)
            EVT_SUB(LVar0, 60)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, FALSE, FALSE)
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
            EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_FLYING, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Run)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsCharged, FALSE)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, EVT_PTR(N(FlyingAnims)))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Flying_TakeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
        EVT_EXEC_WAIT(N(EVS_Attack_SkyDive))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsCharged, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(EVS_Attack_ChargedDive))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleVar, BTL_VAR_HyperSync, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LT(LVar0, 750)
                    EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                    EVT_EXEC_WAIT(N(EVS_Attack_ChargedDive))
                EVT_ELSE
                    EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                    EVT_EXEC_WAIT(N(EVS_Attack_SkyDive))
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LT(LVar0, 500)
                    EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                    EVT_EXEC_WAIT(N(EVS_Attack_ChargedDive))
                EVT_ELSE
                    EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                    EVT_EXEC_WAIT(N(EVS_Attack_SkyDive))
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_Attack_SkyDive))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_Attack_ChargedDive))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(FlyingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Paragoomba_Hyper_Idle,
    STATUS_KEY_STONE,     ANIM_Paragoomba_Hyper_Still,
    STATUS_KEY_SLEEP,     ANIM_Paragoomba_Hyper_Sleep,
    STATUS_KEY_POISON,    ANIM_Paragoomba_Hyper_Idle,
    STATUS_KEY_STOP,      ANIM_Paragoomba_Hyper_Still,
    STATUS_KEY_STATIC,    ANIM_Paragoomba_Hyper_Idle,
    STATUS_KEY_PARALYZE,  ANIM_Paragoomba_Hyper_Still,
    STATUS_KEY_DIZZY,     ANIM_Paragoomba_Hyper_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Paragoomba_Hyper_Dizzy,
    STATUS_END,
};

s32 N(FlyingShuffleAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Paragoomba_Hyper_Run,
    STATUS_KEY_STONE,     ANIM_Paragoomba_Hyper_Still,
    STATUS_KEY_SLEEP,     ANIM_Paragoomba_Hyper_Sleep,
    STATUS_KEY_POISON,    ANIM_Paragoomba_Hyper_Idle,
    STATUS_KEY_STOP,      ANIM_Paragoomba_Hyper_Still,
    STATUS_KEY_STATIC,    ANIM_Paragoomba_Hyper_Run,
    STATUS_KEY_PARALYZE,  ANIM_Paragoomba_Hyper_Still,
    STATUS_KEY_DIZZY,     ANIM_Paragoomba_Hyper_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Paragoomba_Hyper_Dizzy,
    STATUS_END,
};

s32 N(LeftWingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Paragoomba_Hyper_LWingStill,
    STATUS_END,
};

s32 N(RightWingAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Paragoomba_Hyper_RWingStill,
    STATUS_END,
};

EvtScript N(EVS_Flying_Init_Unused) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_Attack_SkyDive)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_LABEL(10)
        EVT_CALL(RandInt, 80, LVar0)
        EVT_ADD(LVar0, 80)
        EVT_LOOP(LVar0)
            EVT_LABEL(0)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
                EVT_IF_FLAG(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    EVT_WAIT(1)
                    EVT_GOTO(0)
                EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 5)
        EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(0.6))
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, EVT_PTR(N(FlyingShuffleAnims)))
        EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IdleFlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
        EVT_LOOP(20)
            EVT_LABEL(1)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
                EVT_IF_FLAG(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    EVT_WAIT(1)
                    EVT_GOTO(1)
                EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 5)
        EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(0.6))
        EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IdleFlyToGoal, ACTOR_SELF, 0, -5, EASING_LINEAR)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, EVT_PTR(N(FlyingAnims)))
        EVT_LOOP(40)
            EVT_LABEL(2)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
                EVT_IF_FLAG(LVar1, STATUS_FLAGS_IMMOBILIZED)
                    EVT_WAIT(1)
                    EVT_GOTO(2)
                EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReturnHome) = {
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_SIN_OUT)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Idle)
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
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_Paragoomba_Hyper_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_CALL(GetBattlePhase, LVar0)
            EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
                EVT_CALL(GetEncounterTrigger, LVar0)
                EVT_IF_EQ(LVar0, ENCOUNTER_TRIGGER_HAMMER)
                    EVT_EXEC_WAIT(N(EVS_KnockDown))
                EVT_END_IF
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_Paragoomba_Hyper_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_Paragoomba_Hyper_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_Paragoomba_Hyper_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_Paragoomba_Hyper_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_Paragoomba_Hyper_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_FALL_TRIGGER)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_Paragoomba_Hyper_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(EVS_KnockDown))
        EVT_CASE_EQ(EVENT_15)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_Paragoomba_Hyper_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_Paragoomba_Hyper_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(N(EVS_KnockDown))
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_FLYING, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsCharged, FALSE)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, EVT_PTR(N(FlyingAnims)))
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_Paragoomba_Hyper_Electrocute)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_Paragoomba_Hyper_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Dizzy)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_FLYING, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsCharged, FALSE)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, EVT_PTR(N(FlyingAnims)))
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_Paragoomba_Hyper_Electrocute)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_Paragoomba_Hyper_HurtStill)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_STAR_BEAM)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsCharged, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
                EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_FLYING, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsCharged, FALSE)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_FLYING, EVT_PTR(N(FlyingAnims)))
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_Paragoomba_Hyper_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_Paragoomba_Hyper_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_Paragoomba_Hyper_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_Paragoomba_Hyper_HurtStill)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Run)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_Paragoomba_Hyper_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_Paragoomba_Hyper_Run)
            EVT_SET_CONST(LVar2, ANIM_Paragoomba_Hyper_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_Paragoomba_Hyper_Run)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_FLYING)
            EVT_SET_CONST(LVar1, ANIM_Paragoomba_Hyper_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_SkyDive) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Run)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -4, EASING_LINEAR)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
            EVT_CALL(SetBattleCamZoom, 300)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_PREDIVE)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Dive)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_DIVE)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_SUB(LVar0, 80)
            EVT_SET(LVar1, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Dive)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_QUADRATIC_OUT)
            EVT_THREAD
                EVT_LOOP(4)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_FLY)
                    EVT_WAIT(4)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Miss)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_FLYING, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_FLYING, EVT_FLOAT(3.0))
            EVT_WAIT(10)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(10)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_FLYING, EVT_FLOAT(1.0))
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Run)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_FLYING, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_WAIT(10)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
            EVT_CALL(SetBattleCamZoom, 300)
            EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
            EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_PREDIVE)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(5.0))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Dive)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, FALSE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_PARAGOOMBA_DIVE)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_FLY, SOUND_NONE, SOUND_NONE)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Dive)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
    EVT_END_SWITCH
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_SKY_DIVE, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 10, 0)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Run)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, -10, EASING_LINEAR)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_WAIT(5)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_FLYING, ANIM_Paragoomba_Hyper_Run)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/StartRumbleWithParams.inc.c"

EvtScript N(EVS_KnockDown) = {
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(SetPartFlags, ACTOR_SELF, PRT_FLYING, ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_NO_TARGET)
    EVT_CALL(SetPartFlags, ACTOR_SELF, PRT_DUMMY_WING_L, ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)
    EVT_CALL(SetPartFlags, ACTOR_SELF, PRT_DUMMY_WING_R, ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)
    EVT_CALL(SetPartFlags, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_SHADOW | ACTOR_PART_FLAG_PRIMARY_TARGET)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_DUMMY_WING_L, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_DUMMY_WING_L, -9, 7, -2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_DUMMY_WING_R, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_DUMMY_WING_R, 11, 7, -2)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_IF_EQ(LVar0, EVENT_15)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_BurnStill)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Hurt)
    EVT_END_IF
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_FALL_QUICK, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(N(StartRumbleWithParams), 100, 10)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(0.3))
    EVT_END_THREAD
    EVT_CALL(ResetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar3)
    EVT_IF_EQ(LVar3, EVENT_15)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Hurt)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_ADD(LVar4, 10)
        EVT_ADD(LVar5, 5)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 10, 0)
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_LOOP(10)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WING_L, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WING_R, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_WAIT(1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WING_L, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WING_R, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WING_L, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_DUMMY_WING_R, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(GetIndexFromHome, ACTOR_SELF, LVar0)
    EVT_MOD(LVar0, 4)
    EVT_CALL(SetGoalToIndex, ACTOR_SELF, LVar0)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(DownedStatusTable)))
    EVT_CALL(SetActorType, ACTOR_SELF, ACTOR_TYPE_HYPER_GOOMBA)
    EVT_EXEC_WAIT(N(EVS_KnockDown_Init))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TYPE_CHANGED, TRUE)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

s32 N(DownedChargedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Goomba_Hyper_Sleep,
    STATUS_KEY_STONE,     ANIM_Goomba_Hyper_Still,
    STATUS_KEY_SLEEP,     ANIM_Goomba_Hyper_Sleep,
    STATUS_KEY_POISON,    ANIM_Goomba_Hyper_Sleep,
    STATUS_KEY_STOP,      ANIM_Goomba_Hyper_Still,
    STATUS_KEY_STATIC,    ANIM_Goomba_Hyper_Sleep,
    STATUS_KEY_PARALYZE,  ANIM_Goomba_Hyper_Still,
    STATUS_KEY_DIZZY,     ANIM_Goomba_Hyper_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Goomba_Hyper_Dizzy,
    STATUS_END,
};

EvtScript N(EVS_Downed_Init) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Downed_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_Downed_HandleEvent)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_Downed_TakeTurn)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsCharged, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_KnockDown_Init) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Downed_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_Downed_HandleEvent)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_Downed_TakeTurn)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsCharged, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsCharged, FALSE)
        EVT_CASE_EQ(1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsCharged, TRUE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, TRUE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_FLYING, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, LVar0)
    EVT_RETURN
    EVT_END
};

// everything below is copied from Hyper Goomba actor

EvtScript N(EVS_HandlePhase) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
        EVT_CASE_EQ(PHASE_ENEMY_END)
            EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_None)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, 1)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Downed_Move_Charge) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsCharged, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_POWER_UP)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 10)
        EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 6, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 45, 0)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Run)
        EVT_WAIT(30)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
        EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, 0, LVar2)
        EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_GOOMBA_STEP)
        EVT_CALL(N(StartRumbleWithParams), 128, 10)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(0.5))
        EVT_END_THREAD
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsCharged, 1)
        EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DownedChargedAnims)))
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
        EVT_CALL(EnableActorGlow, ACTOR_SELF, TRUE)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, TRUE)
        EVT_WAIT(2)
        EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_LOOP(20)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, 1, 0, 0)
        EVT_WAIT(1)
        EVT_CALL(SetActorDispOffset, ACTOR_SELF, -1, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_THREAD
                EVT_LOOP(0)
                    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
                    EVT_ADD(LVar0, 30)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
                    EVT_IF_GT(LVar0, LVar3)
                        EVT_BREAK_LOOP
                    EVT_END_IF
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_01)
                EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_END_IF
                EVT_WAIT(15)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_END_THREAD
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 80)
            EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_ACTOR_HURT, 0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -200, 0, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(15.0))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorPos, ACTOR_SELF, LVar0, 0, LVar2)
            EVT_WAIT(20)
            EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorPos, ACTOR_SELF, 300, 0, 0)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Run)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsCharged, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DownedAnims)))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_ACTOR_HURT, 0)
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 80)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.01))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(15.0))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_CHARGED_BONK, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_THREAD
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
                EVT_SET(LVar0, 80)
                EVT_LOOP(60)
                    EVT_ADD(LVar0, 18)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_END_THREAD
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SET(LVar1, 0)
            EVT_SUB(LVar0, 50)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 30, FALSE, TRUE, FALSE)
            EVT_SUB(LVar0, 40)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 20, FALSE, TRUE, FALSE)
            EVT_SUB(LVar0, 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_WAIT(10)
            EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Run)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsCharged, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DownedAnims)))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Downed_TakeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
        EVT_EXEC_WAIT(N(EVS_Attack_Headbonk))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsCharged, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(EVS_Downed_Move_Charge))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetBattleVar, BTL_VAR_HyperSync, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_NotFirstTurn, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LT(LVar0, 750)
                    EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                    EVT_EXEC_WAIT(N(EVS_Downed_Move_Charge))
                EVT_ELSE
                    EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                    EVT_EXEC_WAIT(N(EVS_Attack_Headbonk))
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LT(LVar0, 500)
                    EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Active)
                    EVT_EXEC_WAIT(N(EVS_Downed_Move_Charge))
                EVT_ELSE
                    EVT_CALL(SetBattleVar, BTL_VAR_HyperSync, BTL_VAL_HyperSync_Done)
                    EVT_EXEC_WAIT(N(EVS_Attack_Headbonk))
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_Attack_Headbonk))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_Downed_Move_Charge))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(DownedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Goomba_Hyper_Idle,
    STATUS_KEY_STONE,     ANIM_Goomba_Hyper_Still,
    STATUS_KEY_SLEEP,     ANIM_Goomba_Hyper_Sleep,
    STATUS_KEY_POISON,    ANIM_Goomba_Hyper_Idle,
    STATUS_KEY_STOP,      ANIM_Goomba_Hyper_Still,
    STATUS_KEY_STATIC,    ANIM_Goomba_Hyper_Idle,
    STATUS_KEY_PARALYZE,  ANIM_Goomba_Hyper_Still,
    STATUS_KEY_DIZZY,     ANIM_Goomba_Hyper_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Goomba_Hyper_Dizzy,
    STATUS_END,
};

s32 N(DownedShuffleAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Goomba_Hyper_Run,
    STATUS_KEY_STONE,     ANIM_Goomba_Hyper_Still,
    STATUS_KEY_SLEEP,     ANIM_Goomba_Hyper_Sleep,
    STATUS_KEY_POISON,    ANIM_Goomba_Hyper_Idle,
    STATUS_KEY_STOP,      ANIM_Goomba_Hyper_Still,
    STATUS_KEY_STATIC,    ANIM_Goomba_Hyper_Run,
    STATUS_KEY_PARALYZE,  ANIM_Goomba_Hyper_Still,
    STATUS_KEY_DIZZY,     ANIM_Goomba_Hyper_Dizzy,
    STATUS_KEY_FEAR,      ANIM_Goomba_Hyper_Dizzy,
    STATUS_END,
};

EvtScript N(EVS_Downed_Init_Unused) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_Attack_Headbonk)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Downed_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_Downed_HandleEvent)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Downed_Idle) = {
    EVT_LABEL(10)
    EVT_CALL(RandInt, 80, LVar0)
    EVT_ADD(LVar0, 80)
    EVT_LOOP(LVar0)
        EVT_LABEL(0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
        EVT_IF_FLAG(LVar1, STATUS_FLAGS_IMMOBILIZED)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DownedShuffleAnims)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleRunToGoal, ACTOR_SELF, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DownedAnims)))
    EVT_LOOP(20)
        EVT_LABEL(1)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
        EVT_IF_FLAG(LVar1, STATUS_FLAGS_IMMOBILIZED)
            EVT_WAIT(1)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 5)
    EVT_CALL(SetActorIdleSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DownedShuffleAnims)))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(IdleRunToGoal, ACTOR_SELF, 0)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DownedAnims)))
    EVT_LOOP(80)
        EVT_LABEL(2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
        EVT_IF_FLAG(LVar1, STATUS_FLAGS_IMMOBILIZED)
            EVT_WAIT(1)
            EVT_GOTO(2)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Downed_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Goomba_Hyper_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Goomba_Hyper_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_Goomba_Hyper_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Goomba_Hyper_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_Goomba_Hyper_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Goomba_Hyper_BurnStill)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Goomba_Hyper_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Goomba_Hyper_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Goomba_Hyper_Dead)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsCharged, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DownedAnims)))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Goomba_Hyper_Electrocute)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Goomba_Hyper_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Knockback)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Dizzy)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0))
            EVT_WAIT(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsCharged, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DownedAnims)))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Goomba_Hyper_Electrocute)
            EVT_EXEC_WAIT(EVS_Enemy_ShockHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Goomba_Hyper_Dead)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_STAR_BEAM)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_IsCharged, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
                EVT_CALL(EnableActorGlow, ACTOR_SELF, FALSE)
                EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_IsCharged, 0)
                EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DownedAnims)))
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Goomba_Hyper_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Goomba_Hyper_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Goomba_Hyper_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Goomba_Hyper_Dead)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0))
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Goomba_Hyper_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Goomba_Hyper_Run)
            EVT_SET_CONST(LVar2, ANIM_Goomba_Hyper_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Goomba_Hyper_Run)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Goomba_Hyper_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

#include "common/CalculateArcsinDeg.inc.c"

EvtScript N(EVS_Attack_Headbonk) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Run)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Midair)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 10)
            EVT_SET(LVar1, 10)
            EVT_ADD(LVar2, 3)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar0)
                EVT_SET(LVar0, 0)
                EVT_LOOP(16)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    EVT_CALL(N(CalculateArcsinDeg), LVar1, LVar2, LVar4, LVar5, LVar0)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_SET(LVar1, LVar4)
                    EVT_SET(LVar2, LVar5)
                    EVT_SET(LVar3, LVar6)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT(6)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Midair)
            EVT_END_THREAD
            EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Sleep)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 5, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 7, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Hurt)
            EVT_WAIT(5)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(5)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Midair)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 20)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
            EVT_THREAD
                EVT_WAIT(4)
                EVT_SET(LVar0, 180)
                EVT_LOOP(4)
                    EVT_SUB(LVar0, 45)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Midair)
            EVT_END_THREAD
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Dizzy)
            EVT_WAIT(5)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(2.0))
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0))
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_WAIT(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.2))
            EVT_THREAD
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar0)
                EVT_SET(LVar0, 0)
                EVT_LOOP(16)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    EVT_CALL(N(CalculateArcsinDeg), LVar1, LVar2, LVar4, LVar5, LVar0)
                    EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    EVT_SET(LVar1, LVar4)
                    EVT_SET(LVar2, LVar5)
                    EVT_SET(LVar3, LVar6)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_THREAD
                EVT_WAIT(6)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Midair)
            EVT_END_THREAD
            EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Tense)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
            EVT_WAIT(1)
    EVT_END_SWITCH
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_HEADBONK, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Idle)
            EVT_WAIT(3)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Goomba_Hyper_Run)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(1.0))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
