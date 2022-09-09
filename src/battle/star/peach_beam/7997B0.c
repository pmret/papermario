#include "common.h"
#include "script_api/battle.h"

#define NAMESPACE battle_star_peach_beam

#include "common/StarPower.inc.c"

ApiStatus func_802A1518_799CC8(Evt* script, s32 isInitialCall);
INCLUDE_ASM(s32, "battle/star/peach_beam/7997B0", func_802A1518_799CC8);

ApiStatus func_802A2468_79AC18(Evt* script, s32 isInitialCall) {
    script->varTable[0] = D_802A3838;
    return ApiStatus_DONE2;
}

ApiStatus func_802A247C_79AC2C(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 230;
    }

    set_background_color_blend(0, 0, 0, script->functionTemp[0]);

    script->functionTemp[0] -= 5;
    if (script->functionTemp[0] <= 200) {
        set_background_color_blend(0, 0, 0, 200);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

// this file is identical in c code to star beam
// TODO: consider .inc.c?

EvtScript N(802A24F0) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_GotItem)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 16)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, 0x241)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(FadeBackgroundToBlack))
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_AnimPray)
        EVT_WAIT(10)
        EVT_CALL(PlaySound, 0x2051)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkStarFunc2), LVar0, LVar1, LVar2)
        EVT_WAIT(30)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x01002A)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(N(UnkStarFunc), 0)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 16)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
        EVT_CALL(N(UnkStarFunc), 4)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, 0x241)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(FadeBackgroundToBlack))
        EVT_WAIT(20)
        EVT_CALL(PlaySound, 0x2051)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_WAIT(10)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkStarFunc2), LVar0, LVar1, LVar2)
        EVT_WAIT(30)
        EVT_CALL(N(UnkStarFunc), 4)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802A2888) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_GotItem)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 16)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, 0x241)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkBackgroundFunc2))
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_AnimPray)
        EVT_WAIT(10)
        EVT_CALL(PlaySound, 0x2051)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkStarFunc2), LVar0, LVar1, LVar2)
        EVT_WAIT(30)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x01002A)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(N(UnkStarFunc), 0)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 16)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
        EVT_CALL(N(UnkStarFunc), 4)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, 0x241)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkBackgroundFunc2))
        EVT_WAIT(20)
        EVT_CALL(PlaySound, 0x2051)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_WAIT(10)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkStarFunc2), LVar0, LVar1, LVar2)
        EVT_WAIT(30)
        EVT_CALL(N(UnkStarFunc), 4)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802A2C20) = {
    EVT_WAIT(8)
    EVT_CALL(SetForegroundModelsVisible, 0)
    EVT_CALL(UseBattleCamPresetImmediately, BTL_CAM_PRESET_73)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_CALL(PlaySound, 0x2041)
    EVT_CALL(CreateNpc, 100, LVar0)
    EVT_CALL(N(SetNpcCollision32))
    EVT_CALL(SetNpcFlagBits, 100, ((NPC_FLAG_40000)), TRUE)
    EVT_CALL(SetNpcPos, 100, -75, 150, 0)
    EVT_CALL(SetNpcDecoration, 100, 0, 5)
    EVT_CALL(N(UnkStarFunc3), -75, 167, 0)
    EVT_WAIT(10)
    EVT_CALL(EnableNpcBlur, 100, 1)
    EVT_SET(LVar0, 0)
    EVT_LOOP(8)
        EVT_ADD(LVar0, 67)
        EVT_CALL(SetNpcRotation, 100, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(EnableNpcBlur, 100, 0)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 50)
    EVT_CALL(NpcFlyTo, 100, LVar0, LVar1, LVar2, 30, 0, 10)
    EVT_CALL(SetForegroundModelsVisible, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(802A2E2C) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(PlaySound, 0x2047)
        EVT_THREAD
            EVT_LOOP(5)
                EVT_WAIT(6)
                EVT_CALL(GetNpcPos, 100, LVar0, LVar1, LVar2)
                EVT_CALL(N(UnkStarFunc4), LVar0, LVar1, LVar2)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(EnableNpcBlur, 100, 1)
        EVT_THREAD
            EVT_SET(LVar2, 0)
            EVT_SET(LVar3, 720)
            EVT_CALL(MakeLerp, LVar2, LVar3, 30, 2)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetNpcRotation, 100, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(GetNpcPos, 100, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 60)
        EVT_CALL(NpcFlyTo, 100, LVar0, LVar1, LVar2, 15, 0, 10)
        EVT_ADD(LVar1, 140)
        EVT_CALL(NpcFlyTo, 100, LVar0, LVar1, LVar2, 15, 0, 10)
        EVT_WAIT(10)
        EVT_CALL(EnableNpcBlur, 100, 0)
        EVT_CALL(DeleteNpc, 100)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(PlaySound, 0x2045)
        EVT_THREAD
            EVT_LOOP(5)
                EVT_WAIT(6)
                EVT_CALL(GetNpcPos, 100, LVar0, LVar1, LVar2)
                EVT_CALL(N(UnkStarFunc4), LVar0, LVar1, LVar2)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(EnableNpcBlur, 100, 1)
        EVT_THREAD
            EVT_SET(LVar2, 0)
            EVT_SET(LVar3, 720)
            EVT_CALL(MakeLerp, LVar2, LVar3, 30, 2)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetNpcRotation, 100, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(GetNpcPos, 100, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 60)
        EVT_CALL(NpcFlyTo, 100, LVar0, LVar1, LVar2, 15, 0, 10)
        EVT_ADD(LVar1, 140)
        EVT_CALL(NpcFlyTo, 100, LVar0, LVar1, LVar2, 15, 0, 10)
        EVT_WAIT(10)
        EVT_CALL(EnableNpcBlur, 100, 0)
        EVT_CALL(DeleteNpc, 100)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802A327C) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(N(UnkBackgroundFunc))
        EVT_WAIT(15)
        EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_Running)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_ELSE
        EVT_CALL(N(UnkBackgroundFunc))
        EVT_WAIT(15)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(8.0))
        EVT_CALL(N(UnkStarFunc), 3)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_CALL(N(UnkStarFunc), 4)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802A33A8) = {
    EVT_THREAD
        EVT_CALL(PlayEffect, 0x38, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 100, 0, 0, 0, 0, 0, 0, 0)
        EVT_WAIT(5)
        EVT_CALL(PlayEffect, 0x38, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 100, 0, 0, 0, 0, 0, 0, 0)
        EVT_IF_EQ(LVarA, 1)
            EVT_WAIT(5)
            EVT_CALL(PlayEffect, 0x38, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 100, 0, 0, 0, 0, 0, 0, 0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(PlayEffect, 0x52, 4, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

s32 N(D_802A3514_7FCCC4)[] = {
    0x00000023, 0x00000000, 0x00000005, 0x0000000A, 0x0000000F, 0x00000014, 0x00000019, 0x0000001E,
};

s32 N(D_802A3534_7FCCE4)[] = {
    0x00000023, 0x00000000, 0x00000005, 0x0000000A, 0x0000000F, 0x00000014, 0x00000019, 0x0000001E,
};

s32 N(D_802A3554_7FCD04)[] = {
    0x42B20000, 0x43340000, 0x00000000, 0xC2100000, 0x43340000, 0x00000000, 0x434C0000, 0x43340000,
    0x00000000, 0x41F00000, 0x42C20000, 0x43EE8000, 0x43660000, 0x42A20000, 0x00000000, 0x43010000,
    0x43340000, 0x00000000, 0xC2700000, 0x43340000, 0x00000000, 0xC36A0000, 0x421C0000, 0x00000000,
};

EvtScript N(usePower) = {
    EVT_EXEC_WAIT(N(802A2888))
    EVT_CALL(AddBattleCamZoom, 100)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_THREAD
        EVT_CALL(func_802A1518_799CC8, 1)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(func_802A2468_79AC18)
        EVT_IF_EQ(LVar0, 1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemDamageEnemy, LVar0, 1082130432, 0, 0, 32)
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(func_802A2468_79AC18)
        EVT_IF_EQ(LVar0, 2)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(func_802A247C_79AC2C)
    EVT_CALL(func_80276EFC)
    EVT_EXEC_WAIT(N(802A327C))
    EVT_RETURN
    EVT_END
};
