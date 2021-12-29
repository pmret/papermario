#include "common.h"
#include "script_api/battle.h"
#include "sprite/npc/battle_misstar.h"

#define NAMESPACE battle_star_smooch

#include "common/StarPower.inc.c"

#include "common/AddHP.inc.c"

ApiStatus func_802A156C_7922FC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);

    playFX_40(0, var1, var2, var3, var4);

    return ApiStatus_DONE2;
}

EvtSource N(802A1630) = {
    EVT_CALL(GetOwnerID, LW(10))
    EVT_IF_EQ(LW(10), 0)
        EVT_CALL(UseBattleCamPreset, 69)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_GOT_ITEM)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), 16)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_WAIT_FRAMES(8)
        EVT_CALL(PlaySound, 0x241)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 15)
        EVT_CALL(N(UnkStarFunc1), LW(0), LW(1), LW(2))
        EVT_CALL(N(FadeBackgroundToBlack))
        EVT_WAIT_FRAMES(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_PRAY)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(PlaySound, 0x2051)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
        EVT_CALL(N(UnkStarFunc2), LW(0), LW(1), LW(2))
        EVT_WAIT_FRAMES(30)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x01002A)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, 69)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(N(UnkStarFunc), 0)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), 16)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
        EVT_CALL(N(UnkStarFunc), 4)
        EVT_WAIT_FRAMES(8)
        EVT_CALL(PlaySound, 0x241)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 15)
        EVT_CALL(N(UnkStarFunc1), LW(0), LW(1), LW(2))
        EVT_CALL(N(FadeBackgroundToBlack))
        EVT_WAIT_FRAMES(20)
        EVT_CALL(PlaySound, 0x2051)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
        EVT_CALL(N(UnkStarFunc2), LW(0), LW(1), LW(2))
        EVT_WAIT_FRAMES(30)
        EVT_CALL(N(UnkStarFunc), 4)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(802A19C8) = {
    EVT_CALL(GetOwnerID, LW(10))
    EVT_IF_EQ(LW(10), 0)
        EVT_CALL(UseBattleCamPreset, 69)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_GOT_ITEM)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), 16)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_WAIT_FRAMES(8)
        EVT_CALL(PlaySound, 0x241)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 15)
        EVT_CALL(N(UnkStarFunc1), LW(0), LW(1), LW(2))
        EVT_CALL(N(UnkBackgroundFunc2))
        EVT_WAIT_FRAMES(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_PRAY)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(PlaySound, 0x2051)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
        EVT_CALL(N(UnkStarFunc2), LW(0), LW(1), LW(2))
        EVT_WAIT_FRAMES(30)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x01002A)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, 69)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(N(UnkStarFunc), 0)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), 16)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
        EVT_CALL(N(UnkStarFunc), 4)
        EVT_WAIT_FRAMES(8)
        EVT_CALL(PlaySound, 0x241)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 15)
        EVT_CALL(N(UnkStarFunc1), LW(0), LW(1), LW(2))
        EVT_CALL(N(UnkBackgroundFunc2))
        EVT_WAIT_FRAMES(20)
        EVT_CALL(PlaySound, 0x2051)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
        EVT_CALL(N(UnkStarFunc2), LW(0), LW(1), LW(2))
        EVT_WAIT_FRAMES(30)
        EVT_CALL(N(UnkStarFunc), 4)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(802A1D60) = {
    EVT_WAIT_FRAMES(8)
    EVT_CALL(SetForegroundModelsVisible, 0)
    EVT_CALL(func_8024E664, 73)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_CALL(PlaySound, 0x2041)
    EVT_CALL(CreateNpc, 100, LW(0))
    EVT_CALL(N(SetNpcCollision32))
    EVT_CALL(SetNpcFlagBits, 100, ((NPC_FLAG_40000)), TRUE)
    EVT_CALL(SetNpcPos, 100, -75, 150, 0)
    EVT_CALL(SetNpcDecoration, 100, 0, 5)
    EVT_CALL(N(UnkStarFunc3), -75, 167, 0)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(EnableNpcBlur, 100, 1)
    EVT_SET(LW(0), 0)
    EVT_LOOP(8)
        EVT_ADD(LW(0), 67)
        EVT_CALL(SetNpcRotation, 100, 0, LW(0), 0)
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_WAIT_FRAMES(10)
    EVT_CALL(EnableNpcBlur, 100, 0)
    EVT_THREAD
        EVT_WAIT_FRAMES(10)
        EVT_CALL(UseBattleCamPreset, 69)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 50)
    EVT_CALL(NpcFlyTo, 100, LW(0), LW(1), LW(2), 30, 0, 10)
    EVT_CALL(SetForegroundModelsVisible, 1)
    EVT_RETURN
    EVT_END
};

EvtSource N(802A1F6C) = {
    EVT_CALL(GetOwnerID, LW(10))
    EVT_IF_EQ(LW(10), 0)
        EVT_CALL(UseBattleCamPreset, 2)
        EVT_CALL(PlaySound, 0x2047)
        EVT_THREAD
            EVT_LOOP(5)
                EVT_WAIT_FRAMES(6)
                EVT_CALL(GetNpcPos, 100, LW(0), LW(1), LW(2))
                EVT_CALL(N(UnkStarFunc4), LW(0), LW(1), LW(2))
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(EnableNpcBlur, 100, 1)
        EVT_THREAD
            EVT_SET(LW(2), 0)
            EVT_SET(LW(3), 720)
            EVT_CALL(MakeLerp, LW(2), LW(3), 30, 2)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetNpcRotation, 100, 0, LW(0), 0)
                EVT_WAIT_FRAMES(1)
                EVT_IF_EQ(LW(1), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(GetNpcPos, 100, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 60)
        EVT_CALL(NpcFlyTo, 100, LW(0), LW(1), LW(2), 15, 0, 10)
        EVT_ADD(LW(1), 140)
        EVT_CALL(NpcFlyTo, 100, LW(0), LW(1), LW(2), 15, 0, 10)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(EnableNpcBlur, 100, 0)
        EVT_CALL(DeleteNpc, 100)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, 2)
        EVT_CALL(PlaySound, 0x2045)
        EVT_THREAD
            EVT_LOOP(5)
                EVT_WAIT_FRAMES(6)
                EVT_CALL(GetNpcPos, 100, LW(0), LW(1), LW(2))
                EVT_CALL(N(UnkStarFunc4), LW(0), LW(1), LW(2))
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(EnableNpcBlur, 100, 1)
        EVT_THREAD
            EVT_SET(LW(2), 0)
            EVT_SET(LW(3), 720)
            EVT_CALL(MakeLerp, LW(2), LW(3), 30, 2)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetNpcRotation, 100, 0, LW(0), 0)
                EVT_WAIT_FRAMES(1)
                EVT_IF_EQ(LW(1), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(GetNpcPos, 100, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 60)
        EVT_CALL(NpcFlyTo, 100, LW(0), LW(1), LW(2), 15, 0, 10)
        EVT_ADD(LW(1), 140)
        EVT_CALL(NpcFlyTo, 100, LW(0), LW(1), LW(2), 15, 0, 10)
        EVT_WAIT_FRAMES(10)
        EVT_CALL(EnableNpcBlur, 100, 0)
        EVT_CALL(DeleteNpc, 100)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(802A23BC) = {
    EVT_CALL(GetOwnerID, LW(10))
    EVT_IF_EQ(LW(10), 0)
        EVT_CALL(N(UnkBackgroundFunc))
        EVT_WAIT_FRAMES(15)
        EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_ELSE
        EVT_CALL(N(UnkBackgroundFunc))
        EVT_WAIT_FRAMES(15)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(8.0))
        EVT_CALL(N(UnkStarFunc), 3)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_CALL(N(UnkStarFunc), 4)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

s32 N(intTable_802A24E8)[] = {
    0x0000000F, 0x0000000F, 0xFFFFFFDF, 0x0000001B, 0xFFFFFFEA, 0xFFFFFFE6, 0x0000000A, 0xFFFFFFDD,
    0x00000023, 0x00000000,
};

EvtSource N(usePower) = {
    EVT_EXEC_WAIT(N(802A1630))
    EVT_SET_CONST(LW(0), NPC_ANIM_battle_misstar_Palette_00_Anim_0)
    EVT_EXEC_WAIT(N(802A1D60))
    EVT_WAIT_FRAMES(16)
    EVT_THREAD
        EVT_WAIT_FRAMES(10)
        EVT_CALL(SetNpcRotation, 100, 0, 180, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetNpcRotation, 100, 0, 150, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetNpcRotation, 100, 0, 120, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetNpcRotation, 100, 0, 90, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetNpcRotation, 100, 0, 60, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetNpcRotation, 100, 0, 30, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetNpcRotation, 100, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 25)
    EVT_ADD(LW(0), 30)
    EVT_CALL(NpcFlyTo, 100, LW(0), LW(1), LW(2), 20, 0, 10)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetNpcAnimation, 100, NPC_ANIM_battle_misstar_Palette_00_Anim_1)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 15)
    EVT_ADD(LW(1), 15)
    EVT_ADD(LW(2), -5)
    EVT_CALL(NpcFlyTo, 100, LW(0), LW(1), LW(2), 10, 0, 10)
    EVT_CALL(PlaySound, 0x245)
    EVT_THREAD
        EVT_CALL(PlayEffect, 0x40, 2, LW(0), LW(1), LW(2), 1, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_WAIT_FRAMES(2)
        EVT_USE_BUF(EVT_ADDR(N(intTable_802A24E8)))
        EVT_LOOP(5)
            EVT_BUF_READ2(LW(5), LW(6))
            EVT_SET(LW(3), LW(0))
            EVT_SET(LW(4), LW(1))
            EVT_ADD(LW(3), LW(5))
            EVT_ADD(LW(4), LW(6))
            EVT_CALL(PlayEffect, 0x40, 2, LW(3), LW(4), LW(2), 1, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT_FRAMES(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 15)
        EVT_ADD(LW(0), 5)
        EVT_CALL(N(UnkStarFunc1), LW(0), LW(1), LW(2))
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
        EVT_ADD(LW(1), 20)
        EVT_ADD(LW(0), 25)
        EVT_CALL(NpcFlyTo, 100, LW(0), LW(1), LW(2), 10, 0, 10)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x01002E)
    EVT_WAIT_FRAMES(12)
    EVT_THREAD
        EVT_EXEC_WAIT(N(802A1F6C))
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(2)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1005859375), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.2001953125), EVT_FLOAT(0.9501953125), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.30078125), EVT_FLOAT(0.900390625), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.3505859375), EVT_FLOAT(0.8505859375), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.380859375), EVT_FLOAT(0.80078125), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.400390625), EVT_FLOAT(0.80078125), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.30078125), EVT_FLOAT(0.8505859375), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.2001953125), EVT_FLOAT(0.900390625), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
            EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1005859375), EVT_FLOAT(0.9501953125), EVT_FLOAT(1.0))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.1005859375), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.2001953125), EVT_FLOAT(0.9501953125), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.30078125), EVT_FLOAT(0.900390625), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.3505859375), EVT_FLOAT(0.8505859375), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.380859375), EVT_FLOAT(0.80078125), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.400390625), EVT_FLOAT(0.80078125), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.900390625), EVT_FLOAT(1.30078125), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.900390625), EVT_FLOAT(1.2001953125), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(0.9501953125), EVT_FLOAT(1.1005859375), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_WAIT_FRAMES(1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_END_THREAD
    EVT_LOOP(10)
        EVT_WAIT_FRAMES(3)
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 0)
    EVT_ADD(LW(1), 35)
    EVT_CALL(func_802A156C_7922FC, LW(0), LW(1), LW(2), 20)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 25)
    EVT_CALL(func_802D7520, LW(0), LW(1), LW(2), 20)
    EVT_CALL(N(AddHP), 20)
    EVT_THREAD
        EVT_CALL(N(UnkBackgroundFunc))
    EVT_END_THREAD
    EVT_CALL(func_80276EFC)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, 0x160)
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.0))
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_10009)
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_CALL(func_80273444, 20, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10009)
    EVT_WAIT_FRAMES(4)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_RETURN
    EVT_END
};
