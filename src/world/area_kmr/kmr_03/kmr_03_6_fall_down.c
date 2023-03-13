#include "kmr_03.h"

EvtScript N(EVS_Scene_FallingDown) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -270, 20, -80)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -270, 20, -80)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(700.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_IF_GE(GB_StoryProgress, STORY_CH0_FOUND_HAMMER)
        EVT_CALL(SetPlayerPos, NPC_DISPOSE_LOCATION)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(SetPlayerPos, -224, 20, -80)
        EVT_CALL(SetNpcPos, NPC_PARTNER, -224, 20, -80)
        EVT_WAIT(20 * DT)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0))
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerPos, LVar0, NPC_DISPOSE_POS_Y, LVar2)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 220)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_WAIT(18 * DT)
        EVT_CALL(PlaySoundAtPlayer, SOUND_175, SOUND_SPACE_MODE_0)
        EVT_WAIT(30 * DT)
        EVT_CALL(PlaySoundAtPlayer, SOUND_176, SOUND_SPACE_MODE_0)
        EVT_WAIT(28 * DT)
        EVT_CALL(PlaySoundAtPlayer, SOUND_175, SOUND_SPACE_MODE_0)
    EVT_END_THREAD
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetPlayerPos, -224, 120, -80)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
#if VERSION_PAL
    EVT_ADDF(LVar1, EVT_FLOAT(-2 * DT))
#else
    EVT_ADD(LVar1, -2)
#endif
    EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_GT(LVar1, 86)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetPlayerPos, -310, 20, -80)
    EVT_THREAD
        EVT_WAIT(20 * DT)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -310, 20, -80)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.2 / DT))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(func_802D286C, 0x00002800)
    EVT_CALL(func_802D2520, ANIM_Mario1_Idle, 5, 5, 1, 1, 0)
    EVT_WAIT(100 * DT)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(func_802D2520, ANIM_Mario1_Idle, 0, 0, 0, 0, 0)
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Jump)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(1.0))
    EVT_CALL(PlayerJump, LVar0, LVar1, LVar2, 10 * DT)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_THREAD
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 * DT))
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_END_THREAD
    EVT_WAIT(30 * DT)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
