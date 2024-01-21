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
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetActorVar, ACTOR_SELF, AVAR_FirstTurn, TRUE)
    Exec(N(EVS_ManageTutorial))
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Thread
        Call(FreezeBattleState, TRUE)
        Call(GetLastEvent, ACTOR_SELF, LVar0)
        Switch(LVar0)
            CaseEq(EVENT_HIT)
                Call(GetActorVar, ACTOR_SELF, AVAR_FirstTurn, LVar0)
                IfEq(LVar0, FALSE)
                    Call(RandInt, 2, LVar0)
                    Switch(LVar0)
                        CaseEq(0)
                            Call(ActorSpeak, MSG_HOS_002D, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_HurtStill, ANIM_BattleGoombario_Walk)
                        CaseEq(1)
                            Call(ActorSpeak, MSG_HOS_002E, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_HurtStill, ANIM_BattleGoombario_Walk)
                        CaseEq(2)
                    EndSwitch
                EndIf
        EndSwitch
        Call(FreezeBattleState, FALSE)
    EndThread
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_30)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
            ExecWait(EVS_Enemy_Hit)
            Wait(1000)
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(SetBattleCamZoom, 400)
    Call(SetBattleCamOffsetZ, 40)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Run)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 50, 0, 0)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
    Call(SetActorDispOffset, ACTOR_SELF, 0, -1, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, -2, 0)
    Wait(5)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 10, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_66)
    Call(SetBattleCamZoom, 400)
    Call(SetBattleCamOffsetZ, 40)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, -10, 0, 0)
    Call(GetBattleFlags2, LVar0)
    IfFlag(LVar0, BS_FLAGS2_DOING_JUMP_TUTORIAL)
        Call(AddGoalPos, ACTOR_SELF, 5, 10, 0)
    EndIf
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.1))
    Thread
        Wait(4)
        Set(LVar0, 0)
        Loop(4)
            Add(LVar0, 45)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            Wait(1)
        EndLoop
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
    EndThread
    Thread
        Call(LoadActionCommand, ACTION_COMMAND_JUMP)
        Call(action_command_jump_init)
        Call(ShowActionHud, TRUE)
        Wait(10)
        Call(action_command_jump_start, 12, 3)
    EndThread
    Call(PlaySound, SOUND_ACTOR_JUMP)
    Call(JumpToGoal, ACTOR_SELF, 22, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
    Call(SetActorScale, ACTOR_SELF, Float(1.1), Float(0.8), Float(1.0))
    Wait(1)
    Call(SetActorScale, ACTOR_SELF, Float(1.3), Float(0.5), Float(1.0))
    Wait(1)
    Call(GetActionCommandMode, LVar0)
    IfEq(LVar0, ACTION_COMMAND_MODE_TUTORIAL)
        Call(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL_WAIT_INPUT)
        Loop(0)
            Call(GetActionCommandMode, LVar0)
            IfLt(LVar0, ACTION_COMMAND_MODE_TUTORIAL)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_FirstTurn, LVar0)
    IfEq(LVar0, TRUE)
        Call(SetDamageSource, DMG_SRC_TUTORIAL_GOOMBARIO)
    EndIf
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
    Call(CloseActionCommandInfo)
    Set(LVarF, LVar0)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(HIT_RESULT_10)
            Call(SetActorScale, ACTOR_SELF, Float(1.1), Float(0.8), Float(1.0))
            Wait(1)
            Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
            Wait(1)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            Add(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            Sub(LVar0, 10)
            Call(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
            Wait(8)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetActorSpeed, ACTOR_SELF, Float(4.0))
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Run)
            Call(RunToGoal, ACTOR_SELF, 0, FALSE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

API_CALLABLE(N(SetPartnerGoombario)) {
    PlayerData* playerData = &gPlayerData;

    playerData->curPartner = PARTNER_GOOMBARIO;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ManageTutorial) = {
    Call(SetBattleFlagBits, BS_FLAGS1_TUTORIAL_BATTLE, TRUE)
    Call(EnableBattleStatusBar, FALSE)
    Call(WaitForState, BATTLE_STATE_PLAYER_MENU)
    Wait(15)
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(EnableIdleScript, ACTOR_PARTNER, IDLE_SCRIPT_DISABLE)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.0))
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 10, FALSE, FALSE, FALSE)
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(ActorSpeak, MSG_HOS_0019, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Call(SetBattleMenuEnabledFlags, BTL_MENU_ENABLED_JUMP)
    Call(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL)
    Call(WaitForState, BATTLE_STATE_PLAYER_MOVE)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Wait(15)
    Call(SetGoalPos, ACTOR_PARTNER, -73, 40, 202)
    Call(FlyToGoal, ACTOR_PARTNER, 20, 20, EASING_COS_IN_OUT)
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(ActorSpeak, MSG_HOS_001A, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Call(SetActionCommandMode, ACTION_COMMAND_MODE_LEARNED)
    Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    Call(SetMessageBoxDuration, -1)
    Thread
        Loop(15)
            Call(SetMessageBoxDuration, 35)
            Wait(1)
        EndLoop
    EndThread
    Wait(15)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(FlyToGoal, ACTOR_PARTNER, 20, 20, EASING_COS_IN_OUT)
    Call(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL)
    Call(WaitForState, BATTLE_STATE_0)
    Call(SetBattleFlagBits2, BS_FLAGS2_DOING_JUMP_TUTORIAL, TRUE)
    Loop(0)
        Call(GetActionCommandMode, LVar0)
        IfNe(LVar0, ACTION_COMMAND_MODE_TUTORIAL)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    // 'Press [A] at exactly this moment.'
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(ActorSpeak, MSG_HOS_001B, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    Loop(0)
        Call(CheckButtonDown, BUTTON_A, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Loop(0)
        Call(CheckButtonPress, BUTTON_A, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(EndActorSpeech, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Call(SetActionSuccess, 1)
    Call(SetActionCommandMode, ACTION_COMMAND_MODE_LEARNED)
    Call(WaitForState, BATTLE_STATE_BEGIN_PARTNER_TURN)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Wait(15)
    // 'When you see "Nice" appear ...'
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(ActorSpeak, MSG_HOS_001D, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Call(WaitForState, BATTLE_STATE_9)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Wait(15)
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(ActorSpeak, MSG_HOS_001E, ACTOR_ENEMY0, 1, ANIM_BattleGoombario_Talk, ANIM_BattleGoombario_Idle)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Call(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL)
    Call(WaitForState, BATTLE_STATE_0)
    Loop(0)
        Call(GetActionCommandMode, LVar0)
        IfNe(LVar0, ACTION_COMMAND_MODE_TUTORIAL)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(ActorSpeak, MSG_HOS_001F, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    Loop(0)
        Call(CheckButtonDown, BUTTON_A, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Loop(0)
        Call(CheckButtonPress, BUTTON_A, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(EndActorSpeech, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Call(SetActionSuccess, 1)
    Call(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL_BLOCK)
    Call(WaitForState, BATTLE_STATE_END_TURN)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Wait(15)
    Call(SetActionCommandMode, ACTION_COMMAND_MODE_LEARNED)
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(ActorSpeak, MSG_HOS_0020, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Call(WaitForState, BATTLE_STATE_PLAYER_MENU)
    Call(SetBattleMenuEnabledFlags, BTL_MENU_ENABLED_SMASH)
    Call(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL)
    Call(WaitForState, BATTLE_STATE_PLAYER_MOVE)
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(ActorSpeak, MSG_HOS_0022, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    Loop(0)
        Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Loop(0)
        Call(CheckButtonPress, BUTTON_STICK_LEFT, LVar0)
        IfEq(LVar0, 1)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(EndActorSpeech, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Call(SetActionCommandMode, ACTION_COMMAND_MODE_LEARNED)
    Call(WaitForState, BATTLE_STATE_0)
    Wait(5)
    Call(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL)
    Loop(0)
        Call(GetActionCommandMode, LVar0)
        IfNe(LVar0, ACTION_COMMAND_MODE_TUTORIAL)
            BreakLoop
        EndIf
        Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        IfEq(LVar0, 0)
            Call(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL_BLOCK)
            Call(PauseTakeTurn, ACTOR_PLAYER)
            Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
            Call(ActorSpeak, MSG_HOS_0023, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
            Loop(0)
                Call(CheckButtonPress, BUTTON_STICK_LEFT, LVar0)
                IfEq(LVar0, 1)
                    BreakLoop
                EndIf
                Wait(1)
            EndLoop
            Call(EndActorSpeech, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
            Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
            Call(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL)
            Call(ResumeTakeTurn, ACTOR_PLAYER)
        EndIf
        Wait(1)
    EndLoop
    Loop(0)
        Call(GetActionQuality, LVar0)
        IfEq(LVar0, 3)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(ActorSpeak, MSG_HOS_0024, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    Loop(0)
        Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        IfEq(LVar0, 0)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(EndActorSpeech, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Call(SetActionSuccess, 1)
    Call(SetActionCommandMode, ACTION_COMMAND_MODE_LEARNED)
    Call(WaitForState, BATTLE_STATE_BEGIN_PARTNER_TURN)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Wait(15)
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(ActorSpeak, MSG_HOS_0025, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Call(SetActorFlagBits, ACTOR_ENEMY0, ACTOR_FLAG_NO_ATTACK, TRUE)
    Call(WaitForState, BATTLE_STATE_0)
    Call(WaitForState, BATTLE_STATE_PLAYER_MENU)
    Call(ShowBattleChoice, MSG_Choice_001D)
    Call(EndActorSpeech, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    IfEq(LVar0, 1)
        Call(ActorSpeak, MSG_HOS_0027, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
        Goto(100)
    EndIf
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(ActorSpeak, MSG_HOS_0028, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Call(SetActorVar, ACTOR_SELF, AVAR_FirstTurn, FALSE)
    Call(SetBattleFlagBits2, BS_FLAGS2_DOING_JUMP_TUTORIAL, FALSE)
    Label(10)
    Call(SetBattleMenuEnabledFlags, BTL_MENU_ENABLED_JUMP | BTL_MENU_ENABLED_SMASH | BTL_MENU_ENABLED_STRATEGIES)
    Call(SetActionCommandMode, ACTION_COMMAND_MODE_TUTORIAL)
    Call(WaitForState, BATTLE_STATE_PLAYER_MOVE)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    IfEq(LVar0, BTL_MENU_TYPE_STRATEGIES)
        Goto(99)
    EndIf
    Call(SetActionCommandMode, ACTION_COMMAND_MODE_LEARNED)
    Call(WaitForState, BATTLE_STATE_BEGIN_PARTNER_TURN)
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(GetActionResult, LVar0)
    Switch(LVar0)
        CaseEq(ACTION_RESULT_EARLY)
            Call(ActorSpeak, MSG_HOS_002A, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
        CaseEq(ACTION_RESULT_FAIL)
            Call(ActorSpeak, MSG_HOS_002B, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
        CaseEq(ACTION_RESULT_SUCCESS)
            Call(ActorSpeak, MSG_HOS_0029, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    EndSwitch
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Call(SetEnemyHP, ACTOR_ENEMY0, 99)
    Call(SetActorFlagBits, ACTOR_ENEMY0, ACTOR_FLAG_NO_ATTACK, FALSE)
    Call(SetActionCommandMode, ACTION_COMMAND_MODE_LEARNED)
    Call(WaitForState, BATTLE_STATE_END_TURN)
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(GetBlockResult, LVar0)
    Switch(LVar0)
        CaseEq(BLOCK_RESULT_EARLY)
            Call(ActorSpeak, MSG_HOS_002A, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
        CaseEq(BLOCK_RESULT_FAIL)
            Call(ActorSpeak, MSG_HOS_002B, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
        CaseEq(BLOCK_RESULT_SUCCESS)
            Call(ActorSpeak, MSG_HOS_0029, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    EndSwitch
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Call(WaitForState, BATTLE_STATE_PLAYER_MENU)
    Goto(10)
    Label(99)
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(ActorSpeak, MSG_HOS_002C, ACTOR_PARTNER, 1, ANIM_Twink_Talk, ANIM_Twink_Fly)
    Label(100)
    Call(WaitForState, BATTLE_STATE_0)
    Call(SetBattleState, BATTLE_STATE_END_TRAINING_BATTLE)
    Call(N(SetPartnerGoombario))
    Wait(10000)
    Return
    End
};
