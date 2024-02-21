#include "mac_00.h"
#include "sprite/player.h"

EvtScript N(EVS_PlayerExitPipe_Intro) = {
    Call(DisablePlayerPhysics, TRUE)
    Call(HidePlayerShadow, TRUE)
    Call(SetPlayerPos, -100, -10, -370)
    Call(InterpPlayerYaw, 135, 0)
    Wait(2)
    Call(PlaySoundAtPlayer, SOUND_ENTER_PIPE, SOUND_SPACE_DEFAULT)
    Call(SetPlayerImgFXFlags, IMGFX_FLAG_REVERSE_ANIM)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_VERTICAL_PIPE_CURL, 1, 1, 0)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Loop(40)
        Add(LVar1, 1)
        Call(SetPlayerPos, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(HidePlayerShadow, FALSE)
    Call(DisablePlayerPhysics, FALSE)
    Return
    End
};

EvtScript N(EVS_LuigiExitPipe_Intro) = {
    Call(EnableNpcShadow, NPC_Luigi_Intro, FALSE)
    Call(SetNpcPos, NPC_Luigi_Intro, -100, -35, -370)
    Call(SetNpcYaw, NPC_Luigi_Intro, 135)
    Wait(2)
    Call(PlaySoundAtNpc, NPC_Luigi_Intro, SOUND_ENTER_PIPE, SOUND_SPACE_DEFAULT)
    Call(SetNpcImgFXFlags, NPC_Luigi_Intro, IMGFX_FLAG_REVERSE_ANIM)
    Call(SetNpcImgFXParams, NPC_Luigi_Intro, IMGFX_SET_ANIM, IMGFX_ANIM_VERTICAL_PIPE_CURL, 1, 1, 0)
    Call(SetNpcPos, NPC_Luigi_Intro, -100, -10, -370)
    Call(GetNpcPos, NPC_Luigi_Intro, LVar0, LVar1, LVar2)
    Loop(45)
        Add(LVar1, 1)
        Call(SetNpcPos, NPC_Luigi_Intro, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(SetNpcImgFXParams, NPC_Luigi_Intro, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetNpcPos, NPC_Luigi_Intro, -100, 30, -370)
    Wait(3)
    Call(EnableNpcShadow, NPC_Luigi_Intro, TRUE)
    Return
    End
};

EvtScript N(EVS_Scene_Intro) = {
    Call(DisablePlayerInput, TRUE)
    Call(UseSettingsFrom, CAM_DEFAULT, -100, 30, -370)
    Call(SetPanTarget, CAM_DEFAULT, -100, 30, -370)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Thread
        ExecWait(N(EVS_PlayerExitPipe_Intro))
        Wait(10 * DT)
        Call(func_802D1270, -60, -320, Float(4.0 / DT))
        Wait(63 * DT)
        Call(func_802D1270, 80, -60, Float(4.0 / DT))
        Call(func_802D1270, 180, 0, Float(4.0 / DT))
        Call(func_802D1270, 650, 0, Float(4.0 / DT))
    EndThread
    Thread
        Wait(70 * DT)
        ExecWait(N(EVS_LuigiExitPipe_Intro))
        Wait(10 * DT)
        Call(SetNpcFlagBits, NPC_Luigi_Intro, NPC_FLAG_GRAVITY, TRUE)
        Call(SetNpcAnimation, NPC_Luigi_Intro, ANIM_Luigi_Run)
        Call(SetNpcSpeed, NPC_Luigi_Intro, Float(4.0 / DT))
        Call(NpcMoveTo, NPC_Luigi_Intro, 80, -60, 0)
        Call(NpcMoveTo, NPC_Luigi_Intro, 180, 0, 0)
        Call(NpcMoveTo, NPC_Luigi_Intro, 650, 0, 0)
    EndThread
    Wait(70 * DT)
    Call(SetPanTarget, CAM_DEFAULT, -60, 0, -320)
    Call(SetCamDistance, CAM_DEFAULT, Float(600.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(UseSettingsFrom, CAM_DEFAULT, 400, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 400, 0, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(450.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.5 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(GotoMap, Ref("mac_01"), mac_01_ENTRY_4)
    Wait(100 * DT)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
