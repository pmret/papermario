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
    Loop(0)
        Loop(10)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Sub(LVar1, 1)
            Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
        Loop(10)
            Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, 1)
            Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_RescuedMuskular) = {
    Call(DisablePartnerAI, 0)
    Call(func_802CF56C, 2)
    Call(SetNpcPos, NPC_Muskular, -520, 40, 270)
    Call(PlayerFaceNpc, NPC_Muskular, FALSE)
    Call(NpcFaceNpc, NPC_PARTNER, NPC_Muskular, 0)
    Call(UseSettingsFrom, CAM_DEFAULT, -420, 20, 235)
    Call(SetPanTarget, CAM_DEFAULT, -470, 20, 250)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForPlayerInputEnabled)
    Call(DisablePlayerInput, TRUE)
    Wait(40 * DT)
    Call(SpeakToPlayer, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 512, MSG_MAC_Housing_00C5)
    Call(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, -300)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.5), -9)
#if VERSION_PAL
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.6))
#else
    Call(SetCamSpeed, CAM_DEFAULT, 3)
#endif
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 512, MSG_MAC_Housing_00C6)
    Call(SetPanTarget, CAM_DEFAULT, -470, 20, 250)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(MakeLerp, 0, 360, 10 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcRotation, NPC_Muskular, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(EnableNpcAI, NPC_Muskular, FALSE)
    Call(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Leap)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_UsePower)
    Call(PlaySoundAtPlayer, SOUND_RECEIVE_STAR_POWER, SOUND_SPACE_DEFAULT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Set(LVar3, LVar1)
    Add(LVar0, 10)
    Add(LVar1, 50)
    Add(LVar2, 10)
    Add(LVar3, 30)
    Loop(5)
        PlayEffect(EFFECT_SPARKLES, 3, LVar0, LVar1, LVar2, 20)
        Wait(6 * DT)
        PlayEffect(EFFECT_SPARKLES, 1, LVar0, LVar3, LVar2, 20)
        Wait(6 * DT)
    EndLoop
    Wait(20 * DT)
    Call(PlaySoundAtPlayer, SOUND_GET_STAR_POWER_WAVE, SOUND_SPACE_DEFAULT)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    PlayEffect(EFFECT_ENERGY_ORB_WAVE, 4, LVar0, LVar1, LVar2, 1, 30)
    Wait(30 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetNpcAnimation, NPC_Muskular, ANIM_WorldMuskular_Idle)
    Call(EnableNpcAI, NPC_Muskular, TRUE)
    Call(N(UpgradeStarPowerCh4))
    Call(ShowMessageAtScreenPos, MSG_Menus_0194, 160, 40)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 512, MSG_MAC_Housing_00C7)
    Call(ShowMessageAtScreenPos, MSG_MAC_Housing_00C8, 160, 40)
    Call(SetPanTarget, CAM_DEFAULT, -470, 20, 250)
    Call(SetCamDistance, CAM_DEFAULT, -500)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.5), -9)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Wait(1)
    Call(SetNpcPos, NPC_Twink, -600, 200, 350)
    Call(NpcFlyTo, NPC_Twink, -437, 60, 270, 0, -10, EASING_LINEAR)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Housing_00C9)
    Call(InterpNpcYaw, NPC_Twink, 270, 0)
    Wait(20 * DT)
    Call(NpcJump1, NPC_Twink, -460, 45, 220, 10 * DT)
    Call(SpeakToNpc, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 512, NPC_Muskular, MSG_MAC_Housing_00CA)
    Call(SetCamDistance, CAM_DEFAULT, -300)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Wait(1)
    Call(SpeakToNpc, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 512, NPC_Twink, MSG_MAC_Housing_00CB)
    Call(SpeakToNpc, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, NPC_Muskular, MSG_MAC_Housing_00CC)
    Call(SpeakToNpc, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 512, NPC_Twink, MSG_MAC_Housing_00CD)
    Call(SpeakToNpc, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, NPC_Muskular, MSG_MAC_Housing_00CE)
    Call(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, -300)
    Call(SetCamPitch, CAM_DEFAULT, Float(17.5), -9)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(SpeakToNpc, NPC_Muskular, ANIM_WorldMuskular_Talk, ANIM_WorldMuskular_Idle, 512, NPC_Twink, MSG_MAC_Housing_00CF)
    Call(SetPanTarget, CAM_DEFAULT, -450, 20, 250)
    Call(SetCamDistance, CAM_DEFAULT, -400)
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SetNpcFlagBits, NPC_Muskular, NPC_FLAG_IGNORE_CAMERA_FOR_YAW, TRUE)
    Thread
        Loop(25)
            Call(GetNpcPos, NPC_Muskular, LVar0, LVar1, LVar2)
            PlayEffect(EFFECT_SPARKLES, 4, LVar0, LVar1, LVar2, 20)
            Wait(4 * DT)
        EndLoop
    EndThread
    Thread
        Set(LVar2, 0)
        Set(LVar3, 1800)
        Call(MakeLerp, LVar2, LVar3, 100 * DT, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcRotation, NPC_Muskular, 0, LVar0, 0)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Thread
        Call(GetNpcPos, NPC_Muskular, LVar2, LVar3, LVar4)
        Set(LVar5, LVar3)
        Add(LVar5, 180)
        Call(MakeLerp, LVar3, LVar5, 100 * DT, EASING_CUBIC_IN)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcPos, NPC_Muskular, LVar2, LVar0, LVar4)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(SetNpcPos, NPC_Muskular, NPC_DISPOSE_LOCATION)
    EndThread
    Thread
        Wait(15 * DT)
        Call(PlaySoundAtNpc, NPC_Muskular, SOUND_STAR_SPIRIT_DEPART_1, SOUND_SPACE_DEFAULT)
    EndThread
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Wait(115 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetMusic, 0, SONG_TWINK_THEME, 0, VOL_LEVEL_FULL)
    Call(SetPanTarget, CAM_DEFAULT, -450, 20, 250)
    Call(SetCamDistance, CAM_DEFAULT, -350)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
#if VERSION_PAL
    Call(SetNpcSpeed, NPC_Twink, Float(4.8))
#else
Call(SetNpcSpeed, NPC_Twink, 4)
#endif
    Call(NpcFlyTo, NPC_Twink, -480, 40, 270, 0, 10, EASING_LINEAR)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Housing_00D0)
    Call(InterpNpcYaw, NPC_Twink, 270, 0)
    Wait(30 * DT)
    Call(NpcFacePlayer, NPC_Twink, 0)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Housing_00D1)
    Call(SetPlayerAnimation, ANIM_Mario1_Question)
    Wait(20 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Housing_00D2)
    Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
    Wait(30 * DT)
    Call(SpeakToPlayer, NPC_Twink, ANIM_Twink_Talk, ANIM_Twink_Idle, 0, MSG_MAC_Housing_00D3)
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Call(NpcFlyTo, NPC_Twink, -600, 200, 350, 0, -10, EASING_LINEAR)
    Call(SetNpcPos, NPC_Twink, NPC_DISPOSE_LOCATION)
    Set(GB_StoryProgress, STORY_CH4_STAR_SPRIT_DEPARTED)
    Exec(N(EVS_SetupMusic))
    Call(EnablePartnerAI)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Muskular) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, mac_04_ENTRY_5)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Muskular)))
        Exec(N(EVS_Scene_RescuedMuskular))
    Else
        Call(RemoveNpc, NPC_SELF)
    EndIf
    Return
    End
};
