#include "common.h"
#include "script_api/battle.h"
#include "sprite/npc/battle_skolar.h"

#define NAMESPACE battle_star_star_storm

#include "common/StarPower.inc.c"

ApiStatus func_802A1518_78ECE8(Evt* script, s32 isInitialCall) {
    s32 var1 = -50 - rand_int(200);
    s32 var2 = 200;
    s32 var3 = rand_int(40);
    f32 var4;

    if (script->varTable[0] % 4) {
        var4 = var1 + (rand_int(50) + var2);
        fx_star(2, var1, var2, var3, var4, 0, var3, rand_int(10) + 7);
    } else {
        var4 = var1 + (rand_int(50) + var2);
        fx_star(3, var1, var2, var3, var4, 0, var3, rand_int(10) + 7);
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802A1628_78EDF8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);

    fx_damage_stars(2, var1, var2, var3, 0, -1.0f, 0, 5);

    return ApiStatus_DONE2;
}

EvtScript N(802A16F0) = {
    EVT_CALL(GetOwnerID, LocalVar(10))
    EVT_IF_EQ(LocalVar(10), 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_GOT_ITEM)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(0), 16)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, 0x241)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(1), 15)
        EVT_CALL(N(UnkStarFunc1), LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(N(FadeBackgroundToBlack))
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_PRAY)
        EVT_WAIT(10)
        EVT_CALL(PlaySound, 0x2051)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(N(UnkStarFunc2), LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_WAIT(30)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x01002A)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(N(UnkStarFunc), 0)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(0), 16)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
        EVT_CALL(N(UnkStarFunc), 4)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, 0x241)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(1), 15)
        EVT_CALL(N(UnkStarFunc1), LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(N(FadeBackgroundToBlack))
        EVT_WAIT(20)
        EVT_CALL(PlaySound, 0x2051)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_WAIT(10)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(N(UnkStarFunc2), LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_WAIT(30)
        EVT_CALL(N(UnkStarFunc), 4)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802A1A88) = {
    EVT_CALL(GetOwnerID, LocalVar(10))
    EVT_IF_EQ(LocalVar(10), 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_GOT_ITEM)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(0), 16)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, 0x241)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(1), 15)
        EVT_CALL(N(UnkStarFunc1), LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(N(UnkBackgroundFunc2))
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_PRAY)
        EVT_WAIT(10)
        EVT_CALL(PlaySound, 0x2051)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(N(UnkStarFunc2), LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_WAIT(30)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, 0x01002A)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(N(UnkStarFunc), 0)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(0), 16)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
        EVT_CALL(N(UnkStarFunc), 4)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, 0x241)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(1), 15)
        EVT_CALL(N(UnkStarFunc1), LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(N(UnkBackgroundFunc2))
        EVT_WAIT(20)
        EVT_CALL(PlaySound, 0x2051)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_WAIT(10)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_CALL(N(UnkStarFunc2), LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_WAIT(30)
        EVT_CALL(N(UnkStarFunc), 4)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802A1E20) = {
    EVT_WAIT(8)
    EVT_CALL(SetForegroundModelsVisible, 0)
    EVT_CALL(UseBattleCamPresetImmediately, BTL_CAM_PRESET_73)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_CALL(PlaySound, 0x2041)
    EVT_CALL(CreateNpc, 100, LocalVar(0))
    EVT_CALL(N(SetNpcCollision32))
    EVT_CALL(SetNpcFlagBits, 100, ((NPC_FLAG_40000)), TRUE)
    EVT_CALL(SetNpcPos, 100, -75, 150, 0)
    EVT_CALL(SetNpcDecoration, 100, 0, 5)
    EVT_CALL(N(UnkStarFunc3), -75, 167, 0)
    EVT_WAIT(10)
    EVT_CALL(EnableNpcBlur, 100, 1)
    EVT_SET(LocalVar(0), 0)
    EVT_LOOP(8)
        EVT_ADD(LocalVar(0), 67)
        EVT_CALL(SetNpcRotation, 100, 0, LocalVar(0), 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(EnableNpcBlur, 100, 0)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(1), 50)
    EVT_CALL(NpcFlyTo, 100, LocalVar(0), LocalVar(1), LocalVar(2), 30, 0, 10)
    EVT_CALL(SetForegroundModelsVisible, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(802A202C) = {
    EVT_CALL(GetOwnerID, LocalVar(10))
    EVT_IF_EQ(LocalVar(10), 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(PlaySound, 0x2047)
        EVT_THREAD
            EVT_LOOP(5)
                EVT_WAIT(6)
                EVT_CALL(GetNpcPos, 100, LocalVar(0), LocalVar(1), LocalVar(2))
                EVT_CALL(N(UnkStarFunc4), LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(EnableNpcBlur, 100, 1)
        EVT_THREAD
            EVT_SET(LocalVar(2), 0)
            EVT_SET(LocalVar(3), 720)
            EVT_CALL(MakeLerp, LocalVar(2), LocalVar(3), 30, 2)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetNpcRotation, 100, 0, LocalVar(0), 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LocalVar(1), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(GetNpcPos, 100, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(1), 60)
        EVT_CALL(NpcFlyTo, 100, LocalVar(0), LocalVar(1), LocalVar(2), 15, 0, 10)
        EVT_ADD(LocalVar(1), 140)
        EVT_CALL(NpcFlyTo, 100, LocalVar(0), LocalVar(1), LocalVar(2), 15, 0, 10)
        EVT_WAIT(10)
        EVT_CALL(EnableNpcBlur, 100, 0)
        EVT_CALL(DeleteNpc, 100)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(PlaySound, 0x2045)
        EVT_THREAD
            EVT_LOOP(5)
                EVT_WAIT(6)
                EVT_CALL(GetNpcPos, 100, LocalVar(0), LocalVar(1), LocalVar(2))
                EVT_CALL(N(UnkStarFunc4), LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(EnableNpcBlur, 100, 1)
        EVT_THREAD
            EVT_SET(LocalVar(2), 0)
            EVT_SET(LocalVar(3), 720)
            EVT_CALL(MakeLerp, LocalVar(2), LocalVar(3), 30, 2)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetNpcRotation, 100, 0, LocalVar(0), 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LocalVar(1), 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(GetNpcPos, 100, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(1), 60)
        EVT_CALL(NpcFlyTo, 100, LocalVar(0), LocalVar(1), LocalVar(2), 15, 0, 10)
        EVT_ADD(LocalVar(1), 140)
        EVT_CALL(NpcFlyTo, 100, LocalVar(0), LocalVar(1), LocalVar(2), 15, 0, 10)
        EVT_WAIT(10)
        EVT_CALL(EnableNpcBlur, 100, 0)
        EVT_CALL(DeleteNpc, 100)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802A247C) = {
    EVT_CALL(GetOwnerID, LocalVar(10))
    EVT_IF_EQ(LocalVar(10), 0)
        EVT_CALL(N(UnkBackgroundFunc))
        EVT_WAIT(15)
        EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_RUNNING)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
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

EvtScript N(usePower) = {
    EVT_EXEC_WAIT(N(802A16F0))
    EVT_SET_CONST(LocalVar(0), NPC_ANIM_battle_skolar_Palette_00_Anim_1)
    EVT_EXEC_WAIT(N(802A1E20))
    EVT_CALL(SetNpcAnimation, 100, NPC_ANIM_battle_skolar_Palette_00_Anim_2)
    EVT_WAIT(16)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_THREAD
        EVT_SET(LocalVar(0), 0)
        EVT_LOOP(10)
            EVT_CALL(PlaySound, SOUND_259)
            EVT_CALL(func_802A1518_78ECE8)
            EVT_WAIT(5)
            EVT_ADD(LocalVar(0), 1)
            EVT_CALL(PlaySound, SOUND_25A)
            EVT_CALL(func_802A1518_78ECE8)
            EVT_WAIT(5)
            EVT_ADD(LocalVar(0), 1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LocalVar(0), 0)
        EVT_WAIT(50)
        EVT_LOOP(10)
            EVT_CALL(PlaySound, SOUND_25C)
            EVT_ADD(LocalVar(0), 1)
            EVT_WAIT(5)
            EVT_CALL(PlaySound, SOUND_25D)
            EVT_ADD(LocalVar(0), 1)
            EVT_WAIT(5)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(10)
            EVT_WAIT(7)
            EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
            EVT_CALL(StartRumble, 8)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(90)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(ItemCheckHit, LocalVar(0), 0, 0, 0, 0)
    EVT_IF_EQ(LocalVar(0), 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(func_802A1628_78EDF8, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(ItemDamageEnemy, LocalVar(0), 939524352, 0, 7, 32)
    EVT_LABEL(1)
    EVT_WAIT(10)
    EVT_CALL(ChooseNextTarget, 0, LocalVar(0))
    EVT_IF_NE(LocalVar(0), -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_WAIT(20)
    EVT_EXEC_WAIT(N(802A202C))
    EVT_CALL(func_80276EFC)
    EVT_EXEC_WAIT(N(802A247C))
    EVT_RETURN
    EVT_END
};
