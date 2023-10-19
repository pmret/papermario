#include "../area.h"
#include "sprite/npc/JrTroopa.h"
#include "sprite/npc/ParaJrTroopa.h"
#include "sprite/player.h"
#include "sprite/npc/Goompa.h"

#define NAMESPACE A(jr_troopa)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

enum N(ActorVars) {
    AVAR_TurnCount                  = 0,
    AVAR_Goompa_Introduction_Done   = 1,
    AVAR_HitReact_State             = 2,
    AVAL_HitReact_Init              = 0,
    AVAL_HitReact_Hit               = 1,
    AVAL_HitReact_Done              = 2,
    AVAR_JrTroopa_PoweredUp         = 3,
    AVAR_AttackDamage               = 4,
    AVAR_JustGettingStarted         = 5,
};

enum N(ActorParams) {
    DMG_INITIAL          = 1,
    DMG_FULL_POWER       = 2,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Idle,
    STATUS_KEY_STONE,     ANIM_JrTroopa_Still,
    STATUS_KEY_SLEEP,     ANIM_JrTroopa_Still,
    STATUS_KEY_POISON,    ANIM_JrTroopa_Still,
    STATUS_KEY_STOP,      ANIM_JrTroopa_Still,
    STATUS_KEY_STATIC,    ANIM_JrTroopa_Still,
    STATUS_KEY_PARALYZE,  ANIM_JrTroopa_Still,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,             100,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              50,
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
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_JR_TROOPA_1,
    .level = ACTOR_LEVEL_JR_TROOPA_1,
    .maxHP = 5,
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
    .size = { 24, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 30 },
    .statusTextOffset = { 10, 20 },
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

s32 N(DefeatedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_JrTroopa_Defeated,
    STATUS_END,
};

EvtScript N(EVS_JrTroopa_Death) = {
    EVT_SET(LVarA, LVar0)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVarA, LVar1)
    EVT_WAIT(10)
    EVT_CALL(GetDamageSource, LVar5)
    EVT_SWITCH(LVar5)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_SLAP_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_FAN_SMACK_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_SLAP_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_FAN_SMACK_LEFT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_SLAP_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_NEXT_FAN_SMACK_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_SLAP_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_LAST_FAN_SMACK_RIGHT)
        EVT_CASE_OR_EQ(DMG_SRC_SPIN_SMASH)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
            EVT_SET(LVar2, 0)
            EVT_LOOP(24)
                EVT_CALL(SetActorYaw, ACTOR_SELF, LVar2)
                EVT_ADD(LVar2, 30)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_END_SWITCH
    EVT_LABEL(0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 10)
    EVT_ADD(LVar2, 10)
    EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySound, SOUND_ACTOR_DEATH)
    EVT_CALL(DropStarPoints, ACTOR_SELF)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(SetBattleCamZoom, 260)
    EVT_CALL(SetBattleCamOffsetZ, 15)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_KNOCKOUT_CHIRPING)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVarA, ANIM_JrTroopa_Collapse)
    EVT_WAIT(12)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVarA, ANIM_JrTroopa_Defeated)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, LVarA, EVT_PTR(N(DefeatedAnims)))
    EVT_WAIT(30)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(15)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 180)
    EVT_WAIT(5)
    EVT_CALL(ActorSpeak, MSG_CH0_00B4, ACTOR_PARTNER, 0, ANIM_Goompa_Talk, ANIM_Goompa_Idle)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_DMG_APPLY, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_TurnCount, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Goompa_Introduction_Done, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HitReact_State, AVAL_HitReact_Init)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_JrTroopa_PoweredUp, FALSE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_AttackDamage, DMG_INITIAL)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_JustGettingStarted, FALSE)
    EVT_RETURN
    EVT_END
};

// unused
EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_GOTO(0)
        EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HitReact_State, LVar0)
    EVT_IF_EQ(LVar0, AVAL_HitReact_Init)
        EVT_CALL(GetLastDamage, ACTOR_SELF, LVar1)
        EVT_IF_NE(LVar1, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HitReact_State, AVAL_HitReact_Hit)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Hurt)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Panic)
            EVT_EXEC_WAIT(N(EVS_JrTroopa_Death))
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_JrTroopa_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
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
    EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_TurnCount, 1)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
    EVT_SUB(LVar1, LVar0)
    EVT_IF_EQ(LVar1, 3)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_JustGettingStarted, LVar0)
        EVT_IF_FALSE(LVar0)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_JustGettingStarted, TRUE)
            EVT_EXEC_WAIT(N(EVS_Cam_FocusOnJrTroopa))
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_WAIT(20)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
            EVT_CALL(ActorSpeak, MSG_CH0_00B1, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Run)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(8.0))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Jump)
    EVT_CALL(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_JR_TOOPA_JUMP, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_AttackDamage, LVar1)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, LVar1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(6)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar0, 40)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 30)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_ADD(LVar0, 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_SUB(LVar0, 10)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
            EVT_WAIT(8)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Run)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(2.0))
    EVT_THREAD
        EVT_WAIT(3)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Midair)
        EVT_WAIT(5)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Fall)
    EVT_END_THREAD
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_WAIT(2)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_AttackDamage, LVar1)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, LVar1, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
            EVT_WAIT(10)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Run)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
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
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            // trying showing the scene where Goompa introduces the player to Jr Troopa
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Goompa_Introduction_Done, LVar0)
            EVT_IF_FALSE(LVar0)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Goompa_Introduction_Done, TRUE)
                EVT_WAIT(15)
                EVT_CALL(EnableBattleStatusBar, FALSE)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
                EVT_THREAD
                    EVT_SET(LVar1, 0)
                    EVT_WAIT(8)
                    EVT_LOOP(5)
                        EVT_WAIT(1)
                        EVT_SUB(LVar1, 36)
                        EVT_CALL(SetActorYaw, ACTOR_PLAYER, LVar1)
                    EVT_END_LOOP
                EVT_END_THREAD
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Punch)
                EVT_CALL(ActorSpeak, MSG_CH0_00AF, ACTOR_PARTNER, 0, ANIM_Goompa_Talk, ANIM_Goompa_Idle)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_NodYes)
                EVT_WAIT(10)
                EVT_THREAD
                    EVT_SET(LVar1, 180)
                    EVT_WAIT(4)
                    EVT_LOOP(5)
                        EVT_WAIT(1)
                        EVT_ADD(LVar1, 36)
                        EVT_CALL(SetActorYaw, ACTOR_PLAYER, LVar1)
                    EVT_END_LOOP
                EVT_END_THREAD
                EVT_WAIT(10)
                EVT_CALL(EnableBattleStatusBar, TRUE)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
                EVT_CALL(MoveBattleCamOver, 4)
            EVT_END_IF
            EVT_END_IF // @bug END_IF with no IF
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
            // trying showing the scene where Goompa congratulates the player for dealing damage to Jr Troopa
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_HitReact_State, LVar0)
            EVT_IF_EQ(LVar0, AVAL_HitReact_Hit)
                EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_HitReact_State, AVAL_HitReact_Done)
                EVT_EXEC_WAIT(N(EVS_Cam_FocusOnGoompa))
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
                EVT_THREAD
                    EVT_SET(LVar1, 0)
                    EVT_LOOP(5)
                        EVT_WAIT(1)
                        EVT_SUB(LVar1, 36)
                        EVT_CALL(SetActorYaw, ACTOR_PLAYER, LVar1)
                    EVT_END_LOOP
                EVT_END_THREAD
                EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
                EVT_CALL(ActorSpeak, MSG_CH0_00B0, ACTOR_PARTNER, 0, ANIM_Goompa_Talk, ANIM_Goompa_Idle)
                EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
                EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_ThumbsUp)
                EVT_WAIT(20)
                EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
                EVT_WAIT(4)
                EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            EVT_END_IF
            // trying showing the scene where Jr Troopa powers up
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_JrTroopa_PoweredUp, LVar0)
            EVT_IF_FALSE(LVar0)
                EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
                EVT_IF_LE(LVar0, 1)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_JrTroopa_PoweredUp, TRUE)
                    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
                    EVT_CALL(ActorSpeak, MSG_CH0_00B2, ACTOR_PARTNER, 0, ANIM_Goompa_Talk, ANIM_Goompa_Idle)
                    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
                    EVT_EXEC_WAIT(N(EVS_Cam_FocusOnJrTroopa))
                    EVT_CALL(ActorSpeak, MSG_CH0_00B3, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Talk, ANIM_JrTroopa_Idle)
                    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_JR_TROOPA_TRANSFORM)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_ChargeArmsUp)
                    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                    EVT_ADD(LVar1, 16)
                    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, 1, 30, 0)
                    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 1, LVar0, LVar1, LVar2, 1, 30, 0)
                    EVT_WAIT(30)
                    EVT_WAIT(20)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_AttackDamage, DMG_FULL_POWER)
                    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_JrTroopa_Idle)
                    EVT_WAIT(20)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
