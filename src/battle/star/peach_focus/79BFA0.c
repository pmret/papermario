#include "common.h"
#include "script_api/battle.h"

#define NAMESPACE battle_star_peach_focus

#include "common/StarPower.inc.c"

ApiStatus func_802A1518_79C4B8(Evt* script, s32 isInitialCall) {
    // TODO: replace with actual struct when we know what it is
    // varTable[0] is Twink's actorVar[0]
    ((s32*)script->varTable[0])[1]++;
    return ApiStatus_DONE2;
}

EvtSource N(802A1530) = {
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

EvtSource N(802A18C8) = {
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

EvtSource N(802A1C60) = {
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

EvtSource N(802A1E6C) = {
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

EvtSource N(802A22BC) = {
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

EvtSource N(usePower) = {
    EVT_CALL(UseBattleCamPreset, 69)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x0A0003)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 16)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
    EVT_CALL(SetGoalPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x0C000D)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 180)
    EVT_CALL(UseBattleCamPreset, 19)
    EVT_CALL(SetBattleCamTarget, -105, -7, 0)
    EVT_CALL(SetBattleCamZoom, 213)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x0D000F)
    EVT_CALL(PlaySound, 0x241)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_ADD(LW(1), 20)
    EVT_CALL(N(UnkStarFunc1), LW(0), LW(1), LW(2))
    EVT_CALL(N(FadeBackgroundToBlack))
    EVT_CALL(GetActorVar, 256, 0, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_CALL(ActorSpeak, 1245334, 0, 0, 851983, 851983)
    EVT_END_IF
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x0A0001)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(PlaySound, 0x2051)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(N(UnkStarFunc2), LW(0), LW(1), LW(2))
    EVT_WAIT_FRAMES(30)
    EVT_CALL(PlaySound, 0x2053)
    EVT_CALL(GetActorVar, ACTOR_PARTNER, 0, LW(0))
    EVT_ADD(LW(0), 1)
    EVT_CALL(SetActorVar, ACTOR_PARTNER, 0, LW(0))
    EVT_CALL(ModifyActorDecoration, 256, 1, 0, LW(0), 0, 0, 0)
    EVT_CALL(GetActorVar, ACTOR_PARTNER, 1, LW(0))
    EVT_CALL(func_802A1518_79C4B8)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(UseBattleCamPreset, 2)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 150)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 120)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 90)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 60)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 30)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(func_80276EFC)
    EVT_CALL(N(UnkBackgroundFunc))
    EVT_WAIT_FRAMES(15)
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x0A0003)
    EVT_CALL(PlayerRunToGoal, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x0A0002)
    EVT_RETURN
    EVT_END
};
