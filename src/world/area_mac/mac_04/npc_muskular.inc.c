#include "sprite/player.h"

API_CALLABLE(N(UpgradeStarPowerCh4)) {
    PlayerData* playerData = &gPlayerData;

    set_max_star_power(4);
    playerData->curHP = playerData->curMaxHP;
    playerData->curFP = playerData->curMaxFP;
    sync_status_bar();
    return ApiStatus_DONE2;
}

EvtScript N(EVS_NpcIdle_Muskular) = {
    EVT_LOOP(0)
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(10)
            EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 1)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_RescuedMuskular) = {
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(func_802CF56C, 2)
    EVT_CALL(SetNpcPos, NPC_Muskular, -520, 40, 270)
    EVT_CALL(PlayerFaceNpc, NPC_Muskular, FALSE)
    EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_Muskular, 0)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -420, 20, 235)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -470, 20, 250)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForPlayerInputEnabled)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(40 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 512, MSG_MAC_Housing_00C5)
    EVT_CALL(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.5), -9)
#if VERSION_PAL
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.6))
#else
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
#endif
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 512, MSG_MAC_Housing_00C6)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -470, 20, 250)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(MakeLerp, 0, 360, 10 * DT, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_Muskular, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(EnableNpcAI, NPC_Muskular, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Leap)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_UsePower)
    EVT_CALL(PlaySoundAtPlayer, SOUND_RECEIVE_STAR_POWER, SOUND_SPACE_DEFAULT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar1)
    EVT_ADD(LVar0, 10)
    EVT_ADD(LVar1, 50)
    EVT_ADD(LVar2, 10)
    EVT_ADD(LVar3, 30)
    EVT_LOOP(5)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 20)
        EVT_WAIT(6 * DT)
        EVT_PLAY_EFFECT(EFFECT_SPARKLES, 1, LVar0, LVar3, LVar2, 20)
        EVT_WAIT(6 * DT)
    EVT_END_LOOP
    EVT_WAIT(20 * DT)
    EVT_CALL(PlaySoundAtPlayer, SOUND_GET_STAR_POWER_WAVE, SOUND_SPACE_DEFAULT)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, 1, 30)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Idle)
    EVT_CALL(EnableNpcAI, NPC_Muskular, TRUE)
    EVT_CALL(N(UpgradeStarPowerCh4))
    EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_0194, 160, 40)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 512, MSG_MAC_Housing_00C7)
    EVT_CALL(ShowMessageAtScreenPos, MSG_MAC_Housing_00C8, 160, 40)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -470, 20, 250)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -500)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.5), -9)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_WAIT(1)
    EVT_CALL(SetNpcPos, NPC_Twink, -600, 200, 350)
    EVT_CALL(NpcFlyTo, NPC_Twink, -437, 60, 270, 0, -10, EASING_LINEAR)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Housing_00C9)
    EVT_CALL(InterpNpcYaw, NPC_Twink, 270, 0)
    EVT_WAIT(20 * DT)
    EVT_CALL(NpcJump1, NPC_Twink, -460, 45, 220, 10 * DT)
    EVT_CALL(SpeakToNpc, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 512, NPC_Muskular, MSG_MAC_Housing_00CA)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -300)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_WAIT(1)
    EVT_CALL(SpeakToNpc, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 512, NPC_Twink, MSG_MAC_Housing_00CB)
    EVT_CALL(SpeakToNpc, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, NPC_Muskular, MSG_MAC_Housing_00CC)
    EVT_CALL(SpeakToNpc, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 512, NPC_Twink, MSG_MAC_Housing_00CD)
    EVT_CALL(SpeakToNpc, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, NPC_Muskular, MSG_MAC_Housing_00CE)
    EVT_CALL(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.5), -9)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToNpc, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 512, NPC_Twink, MSG_MAC_Housing_00CF)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -450, 20, 250)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -400)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetNpcFlagBits, NPC_Muskular, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    EVT_THREAD
        EVT_LOOP(25)
            EVT_CALL(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
            EVT_PLAY_EFFECT(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 20)
            EVT_WAIT(4 * DT)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar2, 0)
        EVT_SET(LVar3, 1800)
        EVT_CALL(MakeLerp, LVar2, LVar3, 100 * DT, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_Muskular, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_Muskular, LVar2, LVar3, LVar4)
        EVT_SET(LVar5, LVar3)
        EVT_ADD(LVar5, 180)
        EVT_CALL(MakeLerp, LVar3, LVar5, 100 * DT, EASING_CUBIC_IN)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcPos, NPC_Muskular, LVar2, LVar0, LVar4)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, NPC_Muskular, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(15 * DT)
        EVT_CALL(PlaySoundAtNpc, NPC_Muskular, SOUND_STAR_SPIRIT_DEPART_1, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_WAIT(115 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetMusicTrack, 0, SONG_TWINK_THEME, 0, 8)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -450, 20, 250)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, -350)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
#if VERSION_PAL
    EVT_CALL(SetNpcSpeed, NPC_Twink, EVT_FLOAT(4.8))
#else
EVT_CALL(SetNpcSpeed, NPC_Twink, 4)
#endif
    EVT_CALL(NpcFlyTo, NPC_Twink, -480, 40, 270, 0, 10, EASING_LINEAR)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Housing_00D0)
    EVT_CALL(InterpNpcYaw, NPC_Twink, 270, 0)
    EVT_WAIT(30 * DT)
    EVT_CALL(NpcFacePlayer, NPC_Twink, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Housing_00D1)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Question)
    EVT_WAIT(20 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Housing_00D2)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_NodYes)
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Housing_00D3)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(NpcFlyTo, NPC_Twink, -600, 200, 350, 0, -10, EASING_LINEAR)
    EVT_CALL(SetNpcPos, NPC_Twink, NPC_DISPOSE_LOCATION)
    EVT_SET(GB_StoryProgress, STORY_CH4_STAR_SPRIT_DEPARTED)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Muskular) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, mac_04_ENTRY_5)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Muskular)))
        EVT_EXEC(N(EVS_Scene_RescuedMuskular))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
