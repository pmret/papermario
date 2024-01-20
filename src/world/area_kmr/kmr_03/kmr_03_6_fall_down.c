#include "kmr_03.h"
#include "sprite/player.h"

EvtScript N(EVS_Scene_FallingDown) = {
    Call(UseSettingsFrom, CAM_DEFAULT, -270, 20, -80)
    Call(SetPanTarget, CAM_DEFAULT, -270, 20, -80)
    Call(SetCamDistance, CAM_DEFAULT, Float(700.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    IfGe(GB_StoryProgress, STORY_CH0_FOUND_HAMMER)
        Call(SetPlayerPos, NPC_DISPOSE_LOCATION)
        Call(DisablePlayerInput, TRUE)
        Call(SetPlayerPos, -224, 20, -80)
        Call(SetNpcPos, NPC_PARTNER, -224, 20, -80)
        Wait(20 * DT)
        Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
        Call(DisablePlayerInput, FALSE)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPlayerPos, LVar0, NPC_DISPOSE_POS_Y, LVar2)
    Wait(30 * DT)
    Call(SetCamDistance, CAM_DEFAULT, 220)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Wait(18 * DT)
        Call(PlaySoundAtPlayer, SOUND_PAPER_GLIDE_1, SOUND_SPACE_DEFAULT)
        Wait(30 * DT)
        Call(PlaySoundAtPlayer, SOUND_PAPER_GLIDE_2, SOUND_SPACE_DEFAULT)
        Wait(28 * DT)
        Call(PlaySoundAtPlayer, SOUND_PAPER_GLIDE_1, SOUND_SPACE_DEFAULT)
    EndThread
    Call(HidePlayerShadow, TRUE)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetPlayerPos, -224, 120, -80)
    Call(InterpPlayerYaw, 90, 0)
    Label(0)
    Wait(1)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
#if VERSION_PAL
    AddF(LVar1, Float(-2 * DT))
#else
    Add(LVar1, -2)
#endif
    Call(SetPlayerPos, LVar0, LVar1, LVar2)
    IfGt(LVar1, 86)
        Goto(0)
    EndIf
    Call(SetPlayerPos, -310, 20, -80)
    Thread
        Wait(20 * DT)
        Call(SetPanTarget, CAM_DEFAULT, -310, 20, -80)
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.2 / DT))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Call(SetPlayerImgFXFlags, IMGFX_FLAG_2000 | IMGFX_FLAG_800)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_FLUTTER_DOWN, 1, 1, 0)
    Wait(100 * DT)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(HidePlayerShadow, FALSE)
    Call(SetPlayerAnimation, ANIM_Mario1_BeforeJump)
    Wait(10 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Jump)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPlayerJumpscale, Float(1.0))
    Call(PlayerJump, LVar0, LVar1, LVar2, 10 * DT)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Thread
        Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 * DT))
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
    EndThread
    Wait(30 * DT)
    Call(DisablePlayerPhysics, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
