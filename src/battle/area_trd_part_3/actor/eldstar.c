#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/world_eldstar.h"

#define NAMESPACE b_area_trd_part_3_eldstar

extern EvtScript N(init_80218390);
extern EvtScript N(takeTurn_80218414);
extern EvtScript N(idle_802183E8);
extern EvtScript N(handleEvent_80218404);
extern EvtScript N(80218424);

BSS s32 D_80219040;

s32 N(idleAnimations_80218280)[] = {
    STATUS_NORMAL,    NPC_ANIM_world_eldstar_Palette_00_Anim_1,
    STATUS_END,
};

s32 N(defenseTable_8021828C)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_80218298)[] = {
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

ActorPartBlueprint N(partsTable_80218344)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80218280),
        .defenseTable = N(defenseTable_8021828C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_40000 | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_ELDSTAR,
    .level = 99,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(partsTable_80218344)),
    .partsData = N(partsTable_80218344),
    .script = &N(init_80218390),
    .statusTable = N(statusTable_80218298),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 0,
    .size = { 24, 32 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(init_80218390) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_80218414)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_802183E8)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_80218404)))
    EVT_EXEC(N(80218424))
    EVT_RETURN
    EVT_END
};

ApiStatus func_80218000_4CF1B0(Evt* script, s32 isInitialCall) {
    Actor* actor = get_actor(script->owner1.actorID);
    s32* sym;

    if (isInitialCall) {
        D_80219040 = 0;
    }

    sym = &D_80219040;
    *sym += 15;
    *sym = clamp_angle(*sym);
    actor->unk_19A = sin_rad(DEG_TO_RAD(*sym)) * 3.0f;

    return ApiStatus_BLOCK;
}

ApiStatus func_802180C8_4CF278(Evt* script, s32 isInitialCall) {
    status_menu_start_blinking_sp();
    return ApiStatus_DONE2;
}

ApiStatus func_802180E8_4CF298(Evt* script, s32 isInitialCall) {
    status_menu_stop_blinking_sp();
    return ApiStatus_DONE2;
}

ApiStatus func_80218108_4CF2B8(Evt* script, s32 isInitialCall) {
    status_menu_start_blinking_hp();
    status_menu_start_blinking_fp();
    return ApiStatus_DONE2;
}

ApiStatus func_80218130_4CF2E0(Evt* script, s32 isInitialCall) {
    status_menu_stop_blinking_hp();
    status_menu_stop_blinking_fp();
    return ApiStatus_DONE2;
}

ApiStatus func_80218158_4CF308(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->unk_4C[0] = 0;
    battleStatus->unk_5C[0] = 0;

    return ApiStatus_DONE2;
}

ApiStatus func_80218170_4CF320(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    if (isInitialCall) {
        script->functionTemp[0] = 10;
    }

    battleStatus->flags2 &= ~0x2;

    if (script->functionTemp[0] != 0) {
        script->functionTemp[0]--;
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802181B4_4CF364(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    if (isInitialCall) {
        script->functionTemp[0] = 10;
    }

    battleStatus->flags2 &= ~0x4;

    if (script->functionTemp[0] != 0) {
        script->functionTemp[0]--;
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802181F8_4CF3A8(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->specialBarsFilled += 32;

    return ApiStatus_DONE2;
}

EvtScript N(idle_802183E8) = {
    EVT_CALL(func_80218000_4CF1B0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_80218404) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80218414) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(80218424) = {
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_2000000, 1)
    EVT_CALL(func_80218158_4CF308)
    EVT_CALL(WaitForState, 13)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_WAIT(15)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(ActorSpeak, MSG_CH1_0114, ACTOR_SELF, 1, NPC_ANIM_world_eldstar_Palette_00_Anim_2, NPC_ANIM_world_eldstar_Palette_00_Anim_1)
    EVT_THREAD
        EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
        EVT_CALL(SetGoalPos, ACTOR_SELF, -110, 100, 0)
        EVT_CALL(FlyToGoal, ACTOR_SELF, 20, 0, 10)
        EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x01002A)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(func_802180C8_4CF278)
    EVT_WAIT(120)
    EVT_CALL(func_802180E8_4CF298)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 20, 0, 10)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
    EVT_CALL(ActorSpeak, MSG_CH1_0115, ACTOR_SELF, 1, NPC_ANIM_world_eldstar_Palette_00_Anim_2, NPC_ANIM_world_eldstar_Palette_00_Anim_1)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x01002A)
    EVT_CALL(func_802180C8_4CF278)
    EVT_WAIT(120)
    EVT_CALL(func_802180E8_4CF298)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_CALL(ActorSpeak, MSG_CH1_0116, ACTOR_SELF, 1, NPC_ANIM_world_eldstar_Palette_00_Anim_2, NPC_ANIM_world_eldstar_Palette_00_Anim_1)
    EVT_WAIT(10)
    EVT_CALL(func_8026E020, 256)
    EVT_CALL(func_8026E038, 2)
    EVT_CALL(WaitForState, 18)
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
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 1)
    EVT_THREAD
        EVT_CALL(func_80218170_4CF320)
    EVT_END_THREAD
    EVT_CALL(WaitForState, 22)
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
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 0)
    EVT_CALL(ActorSpeak, MSG_CH1_0117, ACTOR_SELF, 1, NPC_ANIM_world_eldstar_Palette_00_Anim_2, NPC_ANIM_world_eldstar_Palette_00_Anim_1)
    EVT_WAIT(10)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x01002A)
    EVT_CALL(func_802180C8_4CF278)
    EVT_WAIT(120)
    EVT_CALL(func_802180E8_4CF298)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_CALL(ActorSpeak, MSG_CH1_0118, ACTOR_SELF, 1, NPC_ANIM_world_eldstar_Palette_00_Anim_2, NPC_ANIM_world_eldstar_Palette_00_Anim_1)
    EVT_WAIT(10)
    EVT_CALL(SetBattleState, 6)
    EVT_CALL(WaitForState, 5)
    EVT_WAIT(20)
    EVT_CALL(ActorSpeak, MSG_CH1_0119, ACTOR_SELF, 1, NPC_ANIM_world_eldstar_Palette_00_Anim_2, NPC_ANIM_world_eldstar_Palette_00_Anim_1)
    EVT_WAIT(10)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_THREAD
        EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
        EVT_CALL(SetGoalPos, ACTOR_SELF, -110, 100, 0)
        EVT_CALL(FlyToGoal, ACTOR_SELF, 20, 0, 10)
        EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x01002A)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x01002A)
    EVT_CALL(func_802180C8_4CF278)
    EVT_WAIT(120)
    EVT_CALL(func_802180E8_4CF298)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 1)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 20, 0, 10)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, 0)
    EVT_CALL(ActorSpeak, MSG_CH1_011A, ACTOR_SELF, 1, NPC_ANIM_world_eldstar_Palette_00_Anim_2, NPC_ANIM_world_eldstar_Palette_00_Anim_1)
    EVT_WAIT(10)
    EVT_CALL(ActorSpeak, MSG_CH1_011B, ACTOR_SELF, 1, NPC_ANIM_world_eldstar_Palette_00_Anim_2, NPC_ANIM_world_eldstar_Palette_00_Anim_1)
    EVT_WAIT(10)
    EVT_CALL(func_8026E020, 256)
    EVT_CALL(func_8026E038, 1)
    EVT_CALL(func_80218158_4CF308)
    EVT_CALL(WaitForState, 18)
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
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 1)
    EVT_THREAD
        EVT_CALL(func_80218170_4CF320)
    EVT_END_THREAD
    EVT_CALL(WaitForState, 22)
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
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, 0)
    EVT_CALL(ActorSpeak, MSG_CH1_011C, ACTOR_SELF, 1, NPC_ANIM_world_eldstar_Palette_00_Anim_2, NPC_ANIM_world_eldstar_Palette_00_Anim_1)
    EVT_WAIT(10)
    EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x01002A)
    EVT_CALL(func_802180C8_4CF278)
    EVT_WAIT(120)
    EVT_CALL(func_802180E8_4CF298)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_CALL(ActorSpeak, MSG_CH1_011D, ACTOR_SELF, 1, NPC_ANIM_world_eldstar_Palette_00_Anim_2, NPC_ANIM_world_eldstar_Palette_00_Anim_1)
    EVT_CALL(WaitForState, 0)
    EVT_CALL(SetBattleState, 30)
    EVT_WAIT(10000)
    EVT_RETURN
    EVT_END
};
