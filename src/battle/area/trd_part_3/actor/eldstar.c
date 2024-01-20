#include "../area.h"
#include "sprite/npc/WorldEldstar.h"
#include "sprite/player.h"

#define NAMESPACE A(eldstar)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_ManageTutorial);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

s32 N(IdleAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_WorldEldstar_Idle,
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
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_HEALTH_BAR | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_ELDSTAR,
    .level = ACTOR_LEVEL_ELDSTAR,
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
    Exec(N(EVS_ManageTutorial))
    Return
    End
};

API_CALLABLE(N(UpdateHoverOffset)) {
    Actor* actor = get_actor(script->owner1.actorID);
    static s32 HoverOffset;

    if (isInitialCall) {
        HoverOffset = 0;
    }

    HoverOffset += 15;
    HoverOffset = clamp_angle(HoverOffset);
    actor->verticalRenderOffset = sin_rad(DEG_TO_RAD(HoverOffset)) * 3.0f;

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(StartBlinkingSP)) {
    status_bar_start_blinking_sp();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(StopBlinkingSP)) {
    status_bar_stop_blinking_sp();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(StartBlinkingHPandFP)) {
    status_bar_start_blinking_hp();
    status_bar_start_blinking_fp();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(StopBlinkingHPandFP)) {
    status_bar_stop_blinking_hp();
    status_bar_stop_blinking_fp();
    return ApiStatus_DONE2;
}

API_CALLABLE(N(ClearPlayerMenuSelections)) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->lastPlayerMenuSelection[BTL_MENU_IDX_MAIN] = 0;
    battleStatus->lastPartnerMenuSelection[BTL_MENU_IDX_MAIN] = 0;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80218170_4CF320)) {
    BattleStatus* battleStatus = &gBattleStatus;

    if (isInitialCall) {
        script->functionTemp[0] = 10;
    }

    battleStatus->flags2 &= ~BS_FLAGS2_PLAYER_TURN_USED;

    if (script->functionTemp[0] != 0) {
        script->functionTemp[0]--;
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802181B4_4CF364)) {
    BattleStatus* battleStatus = &gBattleStatus;

    if (isInitialCall) {
        script->functionTemp[0] = 10;
    }

    battleStatus->flags2 &= ~BS_FLAGS2_PARTNER_TURN_USED;

    if (script->functionTemp[0] != 0) {
        script->functionTemp[0]--;
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(AddStarPower)) {
    PlayerData* playerData = &gPlayerData;

    playerData->starPower += SP_PER_SEG;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_Idle) = {
    Call(N(UpdateHoverOffset))
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Return
    End
};

EvtScript N(EVS_ManageTutorial) = {
    Call(SetBattleFlagBits, BS_FLAGS1_TUTORIAL_BATTLE, TRUE)
    Call(N(ClearPlayerMenuSelections))
    Call(WaitForState, BATTLE_STATE_PLAYER_MENU)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Wait(15)
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(ActorSpeak, MSG_CH1_0114, ACTOR_SELF, PRT_MAIN, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle)
    Thread
        Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
        Call(SetGoalPos, ACTOR_SELF, -110, 100, 0)
        Call(FlyToGoal, ACTOR_SELF, 20, 0, EASING_COS_IN_OUT)
        Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_LookUp)
    EndThread
    Wait(10)
    Call(N(StartBlinkingSP))
    Wait(120)
    Call(N(StopBlinkingSP))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
    Call(FlyToGoal, ACTOR_SELF, 20, 0, EASING_COS_IN_OUT)
    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
    Call(ActorSpeak, MSG_CH1_0115, ACTOR_SELF, PRT_MAIN, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle)
    Wait(10)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_LookUp)
    Call(N(StartBlinkingSP))
    Wait(120)
    Call(N(StopBlinkingSP))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(ActorSpeak, MSG_CH1_0116, ACTOR_SELF, PRT_MAIN, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle)
    Wait(10)
    Call(SetBattleMenuEnabledFlags, BTL_MENU_ENABLED_STAR_POWERS)
    Call(SetEnabledStarPowers, 1 << STAR_POWER_INDEX(MOVE_REFRESH))
    Call(WaitForState, BATTLE_STATE_PLAYER_MOVE)
    Set(LVar0, 255)
    Loop(10)
        Sub(LVar0, 25)
        IfLt(LVar0, 0)
            Set(LVar0, 0)
        EndIf
        Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
        Wait(1)
    EndLoop
    Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, 0)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
    Thread
        Call(N(func_80218170_4CF320))
    EndThread
    Call(WaitForState, BATTLE_STATE_END_PLAYER_TURN)
    Set(LVar0, 0)
    Loop(10)
        Add(LVar0, 25)
        IfGt(LVar0, 255)
            Set(LVar0, 255)
        EndIf
        Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
        Wait(1)
    EndLoop
    Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, 255)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, FALSE)
    Call(ActorSpeak, MSG_CH1_0117, ACTOR_SELF, PRT_MAIN, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle)
    Wait(10)
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_LookUp)
    Call(N(StartBlinkingSP))
    Wait(120)
    Call(N(StopBlinkingSP))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(ActorSpeak, MSG_CH1_0118, ACTOR_SELF, PRT_MAIN, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle)
    Wait(10)
    Call(SetBattleState, BATTLE_STATE_END_TURN)
    Call(WaitForState, BATTLE_STATE_BEGIN_TURN)
    Wait(20)
    Call(ActorSpeak, MSG_CH1_0119, ACTOR_SELF, PRT_MAIN, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle)
    Wait(10)
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Thread
        Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
        Call(SetGoalPos, ACTOR_SELF, -110, 100, 0)
        Call(FlyToGoal, ACTOR_SELF, 20, 0, EASING_COS_IN_OUT)
        Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_LookUp)
    EndThread
    Wait(10)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_LookUp)
    Call(N(StartBlinkingSP))
    Wait(120)
    Call(N(StopBlinkingSP))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
    Call(FlyToGoal, ACTOR_SELF, 20, 0, EASING_COS_IN_OUT)
    Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
    Call(ActorSpeak, MSG_CH1_011A, ACTOR_SELF, PRT_MAIN, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle)
    Wait(10)
    Call(ActorSpeak, MSG_CH1_011B, ACTOR_SELF, PRT_MAIN, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle)
    Wait(10)
    Call(SetBattleMenuEnabledFlags, BTL_MENU_ENABLED_STAR_POWERS)
    Call(SetEnabledStarPowers, 1 << STAR_POWER_INDEX(MOVE_FOCUS))
    Call(N(ClearPlayerMenuSelections))
    Call(WaitForState, BATTLE_STATE_PLAYER_MOVE)
    Set(LVar0, 255)
    Loop(10)
        Sub(LVar0, 25)
        IfLt(LVar0, 0)
            Set(LVar0, 0)
        EndIf
        Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
        Wait(1)
    EndLoop
    Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, 0)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
    Thread
        Call(N(func_80218170_4CF320))
    EndThread
    Call(WaitForState, BATTLE_STATE_END_PLAYER_TURN)
    Set(LVar0, 0)
    Loop(10)
        Add(LVar0, 25)
        IfGt(LVar0, 255)
            Set(LVar0, 255)
        EndIf
        Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, LVar0)
        Wait(1)
    EndLoop
    Call(SetPartAlpha, ACTOR_SELF, PRT_MAIN, 255)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, FALSE)
    Call(ActorSpeak, MSG_CH1_011C, ACTOR_SELF, PRT_MAIN, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle)
    Wait(10)
    Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_LookUp)
    Call(N(StartBlinkingSP))
    Wait(120)
    Call(N(StopBlinkingSP))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(ActorSpeak, MSG_CH1_011D, ACTOR_SELF, PRT_MAIN, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle)
    Call(WaitForState, BATTLE_STATE_0)
    Call(SetBattleState, BATTLE_STATE_END_TRAINING_BATTLE)
    Wait(10000)
    Return
    End
};
