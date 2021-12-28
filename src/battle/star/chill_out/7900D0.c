#include "common.h"
#include "script_api/battle.h"
#include "sprite/npc/battle_muskular.h"

#define NAMESPACE battle_star_chill_out

extern s32 D_802A2CC0;

#include "common/StarPower.inc.c"

ApiStatus func_802A1518_7905E8(Evt* script, s32 isInitialCall) {
    D_802A2CC0 = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_802A1528_7905F8(Evt* script, s32 isInitialCall) {
    script->varTable[0] = D_802A2CC0;
    return ApiStatus_DONE2;
}

ApiStatus func_802A153C_79060C(Evt* script, s32 isInitialCall) {
    f32 a = rand_int(200) - 25;
    f32 b = rand_int(120) + 7;
    f32 c = rand_int(50) - 25;

    playFX_6F(2, a, b, c, 2.0f, 20);

    a = rand_int(200) - 25;
    b = rand_int(120) + 7;
    c = rand_int(50) - 25;

    playFX_11(4, a, b, c, 40.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_802A163C_79070C(Evt* script, s32 isInitialCall) {
    Actor* actor = get_actor(script->owner1.actorID);
    Actor* target = get_actor(actor->targetActorID);
    ActorPart* part = get_actor_part(target, actor->targetPartIndex);
    s32 flag1 = ACTOR_FLAG_NO_DMG_APPLY; // these manual flag ones are necessary to match. once we figure out flags, we can add more
    s32 flag2 = ACTOR_EVENT_FLAG_80000;

    script->varTable[0] = 0;

    if ((target->flags & ACTOR_FLAG_TARGET_ONLY) || (target->flags & flag1) || (target->flags & ACTOR_FLAG_2000) ||
        (part->eventFlags & ACTOR_EVENT_FLAG_ENCHANTED) || (part->eventFlags & flag2)) {
        return ApiStatus_DONE2;
    }

    script->varTable[0] = 1;
    return ApiStatus_DONE2;
}

ApiStatus func_802A16F4_7907C4(Evt* script, s32 isInitialCall);
INCLUDE_ASM(s32, "battle/star/chill_out/7900D0", func_802A16F4_7907C4);

EvtSource N(802A18F0) = {
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

EvtSource N(802A1C88) = {
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

EvtSource N(802A2020) = {
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

EvtSource N(802A222C) = {
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

EvtSource N(802A267C) = {
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
    EVT_CALL(func_802A1518_7905E8)
    EVT_EXEC_WAIT(N(802A18F0))
    EVT_SET_CONST(LW(0), NPC_ANIM_battle_muskular_Palette_00_Anim_1)
    EVT_EXEC_WAIT(N(802A2020))
    EVT_CALL(SetNpcAnimation, 100, NPC_ANIM_battle_muskular_Palette_00_Anim_2)
    EVT_WAIT_FRAMES(16)
    EVT_CALL(UseBattleCamPreset, 3)
    EVT_CALL(PlaySound, 0x244)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(10)
    EVT_CALL(ItemCheckHit, LW(0), 0, 0, 0, 0)
    EVT_IF_EQ(LW(0), 6)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_CALL(func_802A163C_79070C)
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(GetOwnerTarget, LW(10), LW(11))
        EVT_THREAD
            EVT_LOOP(5)
                EVT_CALL(SetActorScaleModifier, LW(10), EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorScaleModifier, LW(10), EVT_FLOAT(1.1005859375), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorScaleModifier, LW(10), EVT_FLOAT(1.2001953125), EVT_FLOAT(0.9501953125), EVT_FLOAT(1.0))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorScaleModifier, LW(10), EVT_FLOAT(1.30078125), EVT_FLOAT(0.900390625), EVT_FLOAT(1.0))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorScaleModifier, LW(10), EVT_FLOAT(1.3505859375), EVT_FLOAT(0.8505859375), EVT_FLOAT(1.0))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorScaleModifier, LW(10), EVT_FLOAT(1.380859375), EVT_FLOAT(0.80078125), EVT_FLOAT(1.0))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorScaleModifier, LW(10), EVT_FLOAT(1.400390625), EVT_FLOAT(0.80078125), EVT_FLOAT(1.0))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorScaleModifier, LW(10), EVT_FLOAT(1.30078125), EVT_FLOAT(0.8505859375), EVT_FLOAT(1.0))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorScaleModifier, LW(10), EVT_FLOAT(1.2001953125), EVT_FLOAT(0.900390625), EVT_FLOAT(1.0))
                EVT_WAIT_FRAMES(1)
                EVT_CALL(SetActorScaleModifier, LW(10), EVT_FLOAT(1.1005859375), EVT_FLOAT(0.9501953125), EVT_FLOAT(1.0))
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_CALL(SetActorScaleModifier, LW(10), EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_END_THREAD
    EVT_END_IF
    EVT_LABEL(11)
    EVT_CALL(ChooseNextTarget, 0, LW(0))
    EVT_IF_NE(LW(0), -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_LOOP(30)
        EVT_CALL(func_802A153C_79060C)
        EVT_WAIT_FRAMES(2)
    EVT_END_LOOP
    EVT_CALL(ChooseNextTarget, -1, 0)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemCheckHit, LW(0), 0, 0, 0, 0)
    EVT_IF_EQ(LW(0), 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(func_802A163C_79070C)
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(func_802A16F4_7907C4)
    EVT_ELSE
        EVT_CALL(PlayerDamageEnemy, LW(0), 0, 65535, 0, 0, 2080)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(ChooseNextTarget, 0, LW(0))
    EVT_IF_NE(LW(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT_FRAMES(5)
    EVT_CALL(func_802A1528_7905F8)
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(ShowMessageBox, 44, 60)
    EVT_END_IF
    EVT_CALL(func_80276EFC)
    EVT_EXEC_WAIT(N(802A222C))
    EVT_EXEC_WAIT(N(802A267C))
    EVT_CALL(func_802A1528_7905F8)
    EVT_IF_EQ(LW(0), 1)
        EVT_CALL(WaitForMessageBoxDone)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
