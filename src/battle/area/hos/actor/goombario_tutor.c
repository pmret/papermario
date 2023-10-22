#include "../area.h"
#include "battle/action_cmd.h"
#include "battle/action_cmd/jump.h"
#include "sprite/npc/BattleGoombario.h"
#include "sprite/npc/Twink.h"

#define NAMESPACE A(goombario_tutor)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_ManageTutorial);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorVars) {
    AVAR_FirstTurn  = 0,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleGoombario_Idle,
    STATUS_KEY_STONE,     ANIM_BattleGoombario_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleGoombario_Still,
    STATUS_KEY_POISON,    ANIM_BattleGoombario_Idle,
    STATUS_KEY_STOP,      ANIM_BattleGoombario_Still,
    STATUS_KEY_STATIC,    ANIM_BattleGoombario_Still,
    STATUS_KEY_PARALYZE,  ANIM_BattleGoombario_Still,
    STATUS_KEY_DIZZY,     ANIM_BattleGoombario_Still,
    STATUS_KEY_DIZZY,     ANIM_BattleGoombario_Still,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,                0,
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

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -4, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_HEALTH_BAR,
    .type = ACTOR_TYPE_GOOMBARIO_TUTOR1,
    .level = ACTOR_LEVEL_GOOMBARIO_TUTOR1,
    .maxHP = 99,
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
    .powerBounceChance = 100,
    .coinReward = 0,
    .size = { 24, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FirstTurn, TRUE)
    EVT_EXEC(N(EVS_ManageTutorial))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_THREAD
        EVT_CALL(FreezeBattleState, TRUE)
        EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(EVENT_HIT)
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_FirstTurn, LVar0)
                EVT_IF_EQ(LVar0, FALSE)
                    EVT_CALL(RandInt, 2, LVar0)
                    EVT_SWITCH(LVar0)
                        EVT_CASE_EQ(0)
                            EVT_CALL(ActorSpeak, MSG_HOS_002D, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_HurtStill, ANIM_BattleGoombario_Walk)
                        EVT_CASE_EQ(1)
                            EVT_CALL(ActorSpeak, MSG_HOS_002E, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_HurtStill, ANIM_BattleGoombario_Walk)
                        EVT_CASE_EQ(2)
                    EVT_END_SWITCH
                EVT_END_IF
        EVT_END_SWITCH
        EVT_CALL(FreezeBattleState, FALSE)
    EVT_END_THREAD
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_Idle)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_30)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleGoombario_HurtStill)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(1000)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    EVT_CALL(SetBattleCamZoom, 400)
    EVT_CALL(SetBattleCamOffsetZ, 40)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Run)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    EVT_WAIT(1)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    EVT_WAIT(5)
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_66)
    EVT_CALL(SetBattleCamZoom, 400)
    EVT_CALL(SetBattleCamOffsetZ, 40)
    EVT_CALL(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(AddGoalPos, ACTOR_SELF, -10, 0, 0)
    EVT_CALL(GetBattleFlags2, LVar0)
    EVT_IF_FLAG(LVar0, BS_FLAGS2_DOING_JUMP_TUTORIAL)
        EVT_CALL(AddGoalPos, ACTOR_SELF, 5, 10, 0)
    EVT_END_IF
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.1))
    EVT_THREAD
        EVT_WAIT(4)
        EVT_SET(LVar0, 0)
        EVT_LOOP(4)
            EVT_ADD(LVar0, 45)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(LoadActionCommand, ACTION_COMMAND_JUMP)
        EVT_CALL(action_command_jump_init)
        EVT_CALL(ShowActionHud, TRUE)
        EVT_WAIT(10)
        EVT_CALL(action_command_jump_start, 12, 3)
    EVT_END_THREAD
    EVT_CALL(PlaySound, SOUND_ACTOR_JUMP)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 22, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
    EVT_WAIT(1)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.3), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
    EVT_WAIT(1)
    EVT_CALL(GetActionCommandMode, LVar0)
    EVT_IF_EQ(LVar0, ACTION_COMMAND_MODE_TUTORIAL)
        EVT_CALL(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL_WAIT_INPUT)
        EVT_LOOP(0)
            EVT_CALL(GetActionCommandMode, LVar0)
            EVT_IF_LT(LVar0, ACTION_COMMAND_MODE_TUTORIAL)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_FirstTurn, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_CALL(SetDamageSource, DMG_SRC_TUTORIAL_GOOMBARIO)
    EVT_END_IF
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_CALL(CloseActionCommandInfo)
    EVT_SET(LVarF, LVar0)
    EVT_SWITCH(LVarF)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
        EVT_CASE_OR_EQ(HIT_RESULT_10)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1), EVT_FLOAT(0.8), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT(1)
            EVT_CALL(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
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
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
            EVT_WAIT(8)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Run)
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(SetPartnerGoombario)) {
    PlayerData* playerData = &gPlayerData;

    playerData->curPartner = PARTNER_GOOMBARIO;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ManageTutorial) = {
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_TUTORIAL_BATTLE, TRUE)
    EVT_CALL(EnableBattleStatusBar, FALSE)
    EVT_CALL(WaitForState, BATTLE_STATE_PLAYER_MENU)
    EVT_WAIT(15)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_PARTNER, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, FALSE, FALSE)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, MSG_HOS_0019, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(SetBattleMenuEnabledFlags, BTL_MENU_ENABLED_JUMP)
    EVT_CALL(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL)
    EVT_CALL(WaitForState, BATTLE_STATE_PLAYER_MOVE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(15)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, -73, 40, 202)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 20, 20, EASING_COS_IN_OUT)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, MSG_HOS_001A, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(SetActionCommandMode, ACTION_COMMAND_MODE_LEARNED)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    EVT_CALL(SetMessageBoxDuration, -1)
    EVT_THREAD
        EVT_LOOP(15)
            EVT_CALL(SetMessageBoxDuration, 35)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 20, 20, EASING_COS_IN_OUT)
    EVT_CALL(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL)
    EVT_CALL(WaitForState, BATTLE_STATE_0)
    EVT_CALL(SetBattleFlagBits2, BS_FLAGS2_DOING_JUMP_TUTORIAL, TRUE)
    EVT_LOOP(0)
        EVT_CALL(GetActionCommandMode, LVar0)
        EVT_IF_NE(LVar0, ACTION_COMMAND_MODE_TUTORIAL)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    // 'Press [A] at exactly this moment.'
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, MSG_HOS_001B, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    EVT_LOOP(0)
        EVT_CALL(CheckButtonDown, BUTTON_A, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(CheckButtonPress, BUTTON_A, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EndActorSpeech, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(SetActionSuccess, 1)
    EVT_CALL(SetActionCommandMode, ACTION_COMMAND_MODE_LEARNED)
    EVT_CALL(WaitForState, BATTLE_STATE_BEGIN_PARTNER_TURN)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(15)
    // 'When you see "Nice" appear ...'
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, MSG_HOS_001D, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(WaitForState, BATTLE_STATE_9)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(15)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, MSG_HOS_001E, ACTOR_ENEMY0, 1, ANIM_BattleGoombario_Talk, ANIM_BattleGoombario_Idle)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL)
    EVT_CALL(WaitForState, BATTLE_STATE_0)
    EVT_LOOP(0)
        EVT_CALL(GetActionCommandMode, LVar0)
        EVT_IF_NE(LVar0, ACTION_COMMAND_MODE_TUTORIAL)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, MSG_HOS_001F, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    EVT_LOOP(0)
        EVT_CALL(CheckButtonDown, BUTTON_A, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(CheckButtonPress, BUTTON_A, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EndActorSpeech, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(SetActionSuccess, 1)
    EVT_CALL(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL_BLOCK)
    EVT_CALL(WaitForState, BATTLE_STATE_END_TURN)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(15)
    EVT_CALL(SetActionCommandMode, ACTION_COMMAND_MODE_LEARNED)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, MSG_HOS_0020, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(WaitForState, BATTLE_STATE_PLAYER_MENU)
    EVT_CALL(SetBattleMenuEnabledFlags, BTL_MENU_ENABLED_SMASH)
    EVT_CALL(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL)
    EVT_CALL(WaitForState, BATTLE_STATE_PLAYER_MOVE)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, MSG_HOS_0022, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    EVT_LOOP(0)
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(CheckButtonPress, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EndActorSpeech, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(SetActionCommandMode, ACTION_COMMAND_MODE_LEARNED)
    EVT_CALL(WaitForState, BATTLE_STATE_0)
    EVT_WAIT(5)
    EVT_CALL(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL)
    EVT_LOOP(0)
        EVT_CALL(GetActionCommandMode, LVar0)
        EVT_IF_NE(LVar0, ACTION_COMMAND_MODE_TUTORIAL)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL_BLOCK)
            EVT_CALL(PauseTakeTurn, ACTOR_PLAYER)
            EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
            EVT_CALL(ActorSpeak, MSG_HOS_0023, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
            EVT_LOOP(0)
                EVT_CALL(CheckButtonPress, BUTTON_STICK_LEFT, LVar0)
                EVT_IF_EQ(LVar0, 1)
                    EVT_BREAK_LOOP
                EVT_END_IF
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_CALL(EndActorSpeech, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
            EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
            EVT_CALL(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL)
            EVT_CALL(ResumeTakeTurn, ACTOR_PLAYER)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(GetActionQuality, LVar0)
        EVT_IF_EQ(LVar0, 3)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, MSG_HOS_0024, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    EVT_LOOP(0)
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EndActorSpeech, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(SetActionSuccess, 1)
    EVT_CALL(SetActionCommandMode, ACTION_COMMAND_MODE_LEARNED)
    EVT_CALL(WaitForState, BATTLE_STATE_BEGIN_PARTNER_TURN)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(15)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, MSG_HOS_0025, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(SetActorFlagBits, ACTOR_ENEMY0, ACTOR_FLAG_NO_ATTACK, TRUE)
    EVT_CALL(WaitForState, BATTLE_STATE_0)
    EVT_CALL(WaitForState, BATTLE_STATE_PLAYER_MENU)
    EVT_CALL(ShowBattleChoice, MSG_Choice_001D)
    EVT_CALL(EndActorSpeech, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(ActorSpeak, MSG_HOS_0027, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, MSG_HOS_0028, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_FirstTurn, FALSE)
    EVT_CALL(SetBattleFlagBits2, BS_FLAGS2_DOING_JUMP_TUTORIAL, FALSE)
    EVT_LABEL(10)
    EVT_CALL(SetBattleMenuEnabledFlags, BTL_MENU_ENABLED_JUMP | BTL_MENU_ENABLED_SMASH | BTL_MENU_ENABLED_STRATEGIES)
    EVT_CALL(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL)
    EVT_CALL(WaitForState, BATTLE_STATE_PLAYER_MOVE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_IF_EQ(LVar0, BTL_MENU_TYPE_STRATEGIES)
        EVT_GOTO(99)
    EVT_END_IF
    EVT_CALL(SetActionCommandMode, ACTION_COMMAND_MODE_LEARNED)
    EVT_CALL(WaitForState, BATTLE_STATE_BEGIN_PARTNER_TURN)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(GetActionResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(ACTION_RESULT_EARLY)
            EVT_CALL(ActorSpeak, MSG_HOS_002A, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
        EVT_CASE_EQ(ACTION_RESULT_FAIL)
            EVT_CALL(ActorSpeak, MSG_HOS_002B, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
        EVT_CASE_EQ(ACTION_RESULT_SUCCESS)
            EVT_CALL(ActorSpeak, MSG_HOS_0029, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(SetEnemyHP, ACTOR_ENEMY0, 99)
    EVT_CALL(SetActorFlagBits, ACTOR_ENEMY0, ACTOR_FLAG_NO_ATTACK, FALSE)
    EVT_CALL(SetActionCommandMode, ACTION_COMMAND_MODE_LEARNED)
    EVT_CALL(WaitForState, BATTLE_STATE_END_TURN)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(GetBlockResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(BLOCK_RESULT_EARLY)
            EVT_CALL(ActorSpeak, MSG_HOS_002A, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
        EVT_CASE_EQ(BLOCK_RESULT_FAIL)
            EVT_CALL(ActorSpeak, MSG_HOS_002B, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
        EVT_CASE_EQ(BLOCK_RESULT_SUCCESS)
            EVT_CALL(ActorSpeak, MSG_HOS_0029, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_CALL(WaitForState, BATTLE_STATE_PLAYER_MENU)
    EVT_GOTO(10)
    EVT_LABEL(99)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(ActorSpeak, MSG_HOS_002C, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    EVT_LABEL(100)
    EVT_CALL(WaitForState, BATTLE_STATE_0)
    EVT_CALL(SetBattleState, BATTLE_STATE_END_TRAINING_BATTLE)
    EVT_CALL(N(SetPartnerGoombario))
    EVT_WAIT(10000)
    EVT_RETURN
    EVT_END
};
