#include "common.h"
#include "script_api/battle.h"

#define NAMESPACE battle_move_focus

#include "common/StarPower.inc.c"

API_CALLABLE(func_802A1518_78A378) {
    PlayerData* playerData = &gPlayerData;
    s32 deepFocusSP;
    s32 superFocusSP;

    script->varTable[0] = 0;

    if (playerData->specialBarsFilled >= playerData->maxStarPower * 256) {
        script->varTable[0] = 1;
        return ApiStatus_DONE2;
    }

    deepFocusSP = is_ability_active(ABILITY_DEEP_FOCUS) * 64;
    superFocusSP = is_ability_active(ABILITY_SUPER_FOCUS) * 128;

    add_SP(deepFocusSP + superFocusSP + 128);

    if (playerData->specialBarsFilled == playerData->maxStarPower * 256) {
        script->varTable[0] = 2;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(func_802A15B0_78A410) {
    PlayerData* playerData = &gPlayerData;

    script->varTable[0] = 0;

    if (playerData->specialBarsFilled >= playerData->maxStarPower * 256) {
        script->varTable[0] = 1;
        return ApiStatus_DONE2;
    }

    add_SP(128);

    if (playerData->specialBarsFilled == playerData->maxStarPower * 256) {
        script->varTable[0] = 2;
    }

    return ApiStatus_DONE2;
}

EvtScript N(802A1630) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 16)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, SOUND_241)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(FadeBackgroundToBlack))
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Pray)
        EVT_WAIT(10)
        EVT_CALL(PlaySound, SOUND_2051)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkStarFunc2), LVar0, LVar1, LVar2)
        EVT_WAIT(30)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_LookUp)
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
        EVT_CALL(PlaySound, SOUND_241)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(FadeBackgroundToBlack))
        EVT_WAIT(20)
        EVT_CALL(PlaySound, SOUND_2051)
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

EvtScript N(802A19C8) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_UsePower)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 16)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_WAIT(8)
        EVT_CALL(PlaySound, SOUND_241)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkBackgroundFunc2))
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Pray)
        EVT_WAIT(10)
        EVT_CALL(PlaySound, SOUND_2051)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkStarFunc2), LVar0, LVar1, LVar2)
        EVT_WAIT(30)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_LookUp)
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
        EVT_CALL(PlaySound, SOUND_241)
        EVT_CALL(N(UnkStarFunc), 1)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 15)
        EVT_CALL(N(UnkStarFunc1), LVar0, LVar1, LVar2)
        EVT_CALL(N(UnkBackgroundFunc2))
        EVT_WAIT(20)
        EVT_CALL(PlaySound, SOUND_2051)
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

EvtScript N(802A1D60) = {
    EVT_WAIT(8)
    EVT_CALL(SetForegroundModelsVisible, FALSE)
    EVT_CALL(UseBattleCamPresetImmediately, BTL_CAM_PRESET_73)
    EVT_CALL(MoveBattleCamOver, 1)
    EVT_CALL(PlaySound, SOUND_2041)
    EVT_CALL(CreateNpc, NPC_BTL_SPIRIT, LVar0)
    EVT_CALL(N(SetNpcCollision32))
    EVT_CALL(SetNpcFlagBits, NPC_BTL_SPIRIT, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    EVT_CALL(SetNpcPos, NPC_BTL_SPIRIT, -75, 150, 0)
    EVT_CALL(SetNpcDecoration, NPC_BTL_SPIRIT, 0, NPC_DECORATION_WHITE_GLOW_BEHIND)
    EVT_CALL(N(UnkStarFunc3), -75, 167, 0)
    EVT_WAIT(10)
    EVT_CALL(EnableNpcBlur, NPC_BTL_SPIRIT, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(8)
        EVT_ADD(LVar0, 67)
        EVT_CALL(SetNpcRotation, NPC_BTL_SPIRIT, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(EnableNpcBlur, NPC_BTL_SPIRIT, FALSE)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_69)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 50)
    EVT_CALL(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 30, 0, EASING_COS_IN_OUT)
    EVT_CALL(SetForegroundModelsVisible, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(802A1F6C) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(PlaySound, SOUND_2047)
        EVT_THREAD
            EVT_LOOP(5)
                EVT_WAIT(6)
                EVT_CALL(GetNpcPos, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2)
                EVT_CALL(N(UnkStarFunc4), LVar0, LVar1, LVar2)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(EnableNpcBlur, NPC_BTL_SPIRIT, TRUE)
        EVT_THREAD
            EVT_SET(LVar2, 0)
            EVT_SET(LVar3, 720)
            EVT_CALL(MakeLerp, LVar2, LVar3, 30, EASING_CUBIC_IN)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetNpcRotation, NPC_BTL_SPIRIT, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(GetNpcPos, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 60)
        EVT_CALL(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 15, 0, EASING_COS_IN_OUT)
        EVT_ADD(LVar1, 140)
        EVT_CALL(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 15, 0, EASING_COS_IN_OUT)
        EVT_WAIT(10)
        EVT_CALL(EnableNpcBlur, NPC_BTL_SPIRIT, FALSE)
        EVT_CALL(DeleteNpc, NPC_BTL_SPIRIT)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(PlaySound, SOUND_2045)
        EVT_THREAD
            EVT_LOOP(5)
                EVT_WAIT(6)
                EVT_CALL(GetNpcPos, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2)
                EVT_CALL(N(UnkStarFunc4), LVar0, LVar1, LVar2)
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(EnableNpcBlur, NPC_BTL_SPIRIT, TRUE)
        EVT_THREAD
            EVT_SET(LVar2, 0)
            EVT_SET(LVar3, 720)
            EVT_CALL(MakeLerp, LVar2, LVar3, 30, EASING_CUBIC_IN)
            EVT_LOOP(0)
                EVT_CALL(UpdateLerp)
                EVT_CALL(SetNpcRotation, NPC_BTL_SPIRIT, 0, LVar0, 0)
                EVT_WAIT(1)
                EVT_IF_EQ(LVar1, 0)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_THREAD
        EVT_CALL(GetNpcPos, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 60)
        EVT_CALL(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 15, 0, EASING_COS_IN_OUT)
        EVT_ADD(LVar1, 140)
        EVT_CALL(NpcFlyTo, NPC_BTL_SPIRIT, LVar0, LVar1, LVar2, 15, 0, EASING_COS_IN_OUT)
        EVT_WAIT(10)
        EVT_CALL(EnableNpcBlur, NPC_BTL_SPIRIT, FALSE)
        EVT_CALL(DeleteNpc, NPC_BTL_SPIRIT)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(802A23BC) = {
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(N(UnkBackgroundFunc))
        EVT_WAIT(15)
        EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
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

EvtScript N(EVS_UsePower) = {
    EVT_EXEC_WAIT(N(802A1630))
    EVT_CALL(func_802535B4, 1)
    EVT_CALL(GetOwnerID, LVarA)
    EVT_IF_EQ(LVarA, 0)
        EVT_CALL(PlaySound, SOUND_2053)
        EVT_CALL(func_802A1518_78A378)
        EVT_WAIT(30)
        EVT_CALL(N(UnkBackgroundFunc))
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_CALL(ShowMessageBox, BTL_MSG_STAR_POWER_RECHARGED, 60)
            EVT_CASE_EQ(1)
                EVT_CALL(ShowMessageBox, BTL_MSG_STAR_POWER_MAXED, 60)
            EVT_CASE_EQ(2)
                EVT_CALL(ShowMessageBox, BTL_MSG_STAR_POWER_FILLED, 60)
        EVT_END_SWITCH
        EVT_CALL(WaitForMessageBoxDone)
        EVT_CALL(func_80276EFC)
        EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
        EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(8.0))
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Run)
        EVT_CALL(PlayerRunToGoal, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_ELSE
        EVT_CALL(PlaySound, SOUND_2053)
        EVT_CALL(func_802A15B0_78A410)
        EVT_WAIT(30)
        EVT_CALL(N(UnkBackgroundFunc))
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_CALL(ShowMessageBox, BTL_MSG_STAR_POWER_RECHARGED, 60)
            EVT_CASE_EQ(1)
                EVT_CALL(ShowMessageBox, BTL_MSG_STAR_POWER_MAXED, 60)
            EVT_CASE_EQ(2)
                EVT_CALL(ShowMessageBox, BTL_MSG_STAR_POWER_FILLED, 60)
        EVT_END_SWITCH
        EVT_CALL(WaitForMessageBoxDone)
        EVT_CALL(PartnerYieldTurn)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(8.0))
        EVT_CALL(N(UnkStarFunc), 3)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_CALL(N(UnkStarFunc), 4)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
