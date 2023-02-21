#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/WorldEldstar.h"

#define NAMESPACE b_area_trd_part_3_eldstar

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_ManageTutorial);

BSS s32 D_80219040;

s32 N(IdleAnims)[] = {
    STATUS_NORMAL,    ANIM_WorldEldstar_Idle,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 0,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 0,
    STATUS_STOP, 0,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(IdleAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_HIDE_HP_BAR | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_ELDSTAR,
    .level = 99,
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
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_EXEC(N(EVS_ManageTutorial))
    EVT_RETURN
    EVT_END
};

API_CALLABLE(func_80218000_4CF1B0) {
    Actor* actor = get_actor(script->owner1.actorID);
    s32* sym;

    if (isInitialCall) {
        D_80219040 = 0;
    }

    sym = &D_80219040;
    *sym += 15;
    *sym = clamp_angle(*sym);
    actor->verticalRenderOffset = sin_rad(DEG_TO_RAD(*sym)) * 3.0f;

    return ApiStatus_BLOCK;
}

API_CALLABLE(func_802180C8_4CF278) {
    status_menu_start_blinking_sp();
    return ApiStatus_DONE2;
}

API_CALLABLE(func_802180E8_4CF298) {
    status_menu_stop_blinking_sp();
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80218108_4CF2B8) {
    status_menu_start_blinking_hp();
    status_menu_start_blinking_fp();
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80218130_4CF2E0) {
    status_menu_stop_blinking_hp();
    status_menu_stop_blinking_fp();
    return ApiStatus_DONE2;
}

API_CALLABLE(func_80218158_4CF308) {
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

    battleStatus->flags2 &= ~BS_FLAGS2_2;

    if (script->functionTemp[0] != 0) {
        script->functionTemp[0]--;
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(func_802181B4_4CF364) {
    BattleStatus* battleStatus = &gBattleStatus;

    if (isInitialCall) {
        script->functionTemp[0] = 10;
    }

    battleStatus->flags2 &= ~BS_FLAGS2_4;

    if (script->functionTemp[0] != 0) {
        script->functionTemp[0]--;
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(func_802181F8_4CF3A8) {
    PlayerData* playerData = &gPlayerData;

    playerData->specialBarsFilled += 32;

    return ApiStatus_DONE2;
}

EvtScript N(EVS_Idle) = {
    EVT_CALL(func_80218000_4CF1B0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageTutorial) = {
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_TUTORIAL_BATTLE, TRUE)
    EVT_CALL(func_80218158_4CF308)
    EVT_CALL(WaitForState, BATTLE_STATE_PLAYER_MENU)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_WAIT(15)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(ActorSpeak, MSG_CH1_0114, ACTOR_SELF, 1, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle)
    EVT_THREAD
        EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
        EVT_CALL(SetGoalPos, ACTOR_SELF, -110, 100, 0)
        EVT_CALL(FlyToGoal, ACTOR_SELF, 20, 0, EASING_COS_IN_OUT)
        EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_LookUp)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(func_802180C8_4CF278)
    EVT_WAIT(120)
    EVT_CALL(func_802180E8_4CF298)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 20, 0, EASING_COS_IN_OUT)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
    EVT_CALL(ActorSpeak, MSG_CH1_0115, ACTOR_SELF, 1, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_LookUp)
    EVT_CALL(func_802180C8_4CF278)
    EVT_WAIT(120)
    EVT_CALL(func_802180E8_4CF298)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(ActorSpeak, MSG_CH1_0116, ACTOR_SELF, 1, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle)
    EVT_WAIT(10)
    EVT_CALL(SetBattleMenuDisableFlags, BTL_MENU_DISABLED_STAR_POWERS)
    EVT_CALL(SetEnabledStarPowers, 1 << STAR_POWER_INDEX(MOVE_REFRESH))
    EVT_CALL(WaitForState, BATTLE_STATE_PLAYER_MOVE)
    EVT_SET(LVar0, 255)
    EVT_LOOP(10)
        EVT_SUB(LVar0, 25)
        EVT_IF_LT(LVar0, 0)
            EVT_SET(LVar0, 0)
        EVT_END_IF
        EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
    EVT_THREAD
        EVT_CALL(N(func_80218170_4CF320))
    EVT_END_THREAD
    EVT_CALL(WaitForState, BATTLE_STATE_END_PLAYER_TURN)
    EVT_SET(LVar0, 0)
    EVT_LOOP(10)
        EVT_ADD(LVar0, 25)
        EVT_IF_GT(LVar0, 255)
            EVT_SET(LVar0, 255)
        EVT_END_IF
        EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, 255)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, FALSE)
    EVT_CALL(ActorSpeak, MSG_CH1_0117, ACTOR_SELF, 1, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle)
    EVT_WAIT(10)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_LookUp)
    EVT_CALL(func_802180C8_4CF278)
    EVT_WAIT(120)
    EVT_CALL(func_802180E8_4CF298)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(ActorSpeak, MSG_CH1_0118, ACTOR_SELF, 1, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle)
    EVT_WAIT(10)
    EVT_CALL(SetBattleState, BATTLE_STATE_END_TURN)
    EVT_CALL(WaitForState, BATTLE_STATE_BEGIN_TURN)
    EVT_WAIT(20)
    EVT_CALL(ActorSpeak, MSG_CH1_0119, ACTOR_SELF, 1, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle)
    EVT_WAIT(10)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_THREAD
        EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
        EVT_CALL(SetGoalPos, ACTOR_SELF, -110, 100, 0)
        EVT_CALL(FlyToGoal, ACTOR_SELF, 20, 0, EASING_COS_IN_OUT)
        EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_LookUp)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_LookUp)
    EVT_CALL(func_802180C8_4CF278)
    EVT_WAIT(120)
    EVT_CALL(func_802180E8_4CF298)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 20, 0, EASING_COS_IN_OUT)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
    EVT_CALL(ActorSpeak, MSG_CH1_011A, ACTOR_SELF, 1, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle)
    EVT_WAIT(10)
    EVT_CALL(ActorSpeak, MSG_CH1_011B, ACTOR_SELF, 1, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle)
    EVT_WAIT(10)
    EVT_CALL(SetBattleMenuDisableFlags, BTL_MENU_DISABLED_STAR_POWERS)
    EVT_CALL(SetEnabledStarPowers, 1 << STAR_POWER_INDEX(MOVE_FOCUS))
    EVT_CALL(func_80218158_4CF308)
    EVT_CALL(WaitForState, BATTLE_STATE_PLAYER_MOVE)
    EVT_SET(LVar0, 255)
    EVT_LOOP(10)
        EVT_SUB(LVar0, 25)
        EVT_IF_LT(LVar0, 0)
            EVT_SET(LVar0, 0)
        EVT_END_IF
        EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
    EVT_THREAD
        EVT_CALL(N(func_80218170_4CF320))
    EVT_END_THREAD
    EVT_CALL(WaitForState, BATTLE_STATE_END_PLAYER_TURN)
    EVT_SET(LVar0, 0)
    EVT_LOOP(10)
        EVT_ADD(LVar0, 25)
        EVT_IF_GT(LVar0, 255)
            EVT_SET(LVar0, 255)
        EVT_END_IF
        EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartAlpha, ACTOR_SELF, 1, 255)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, FALSE)
    EVT_CALL(ActorSpeak, MSG_CH1_011C, ACTOR_SELF, 1, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle)
    EVT_WAIT(10)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_LookUp)
    EVT_CALL(func_802180C8_4CF278)
    EVT_WAIT(120)
    EVT_CALL(func_802180E8_4CF298)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(ActorSpeak, MSG_CH1_011D, ACTOR_SELF, 1, ANIM_WorldEldstar_Wave, ANIM_WorldEldstar_Idle)
    EVT_CALL(WaitForState, BATTLE_STATE_0)
    EVT_CALL(SetBattleState, BATTLE_STATE_END_TRAINING_BATTLE)
    EVT_WAIT(10000)
    EVT_RETURN
    EVT_END
};
