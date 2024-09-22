#include "mac_00.h"
#include "sprite/player.h"

EvtScript N(EVS_PlayerExitPipe_Epilogue) = {
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

EvtScript N(EVS_LuigiExitPipe_Epilogue) = {
    Call(EnableNpcShadow, NPC_Luigi_Epilogue, FALSE)
    Call(SetNpcPos, NPC_Luigi_Epilogue, -100, -35, -370)
    Call(SetNpcYaw, NPC_Luigi_Epilogue, 135)
    Wait(2)
    Call(PlaySoundAtNpc, NPC_Luigi_Epilogue, SOUND_ENTER_PIPE, SOUND_SPACE_DEFAULT)
    Call(SetNpcImgFXFlags, NPC_Luigi_Epilogue, IMGFX_FLAG_REVERSE_ANIM)
    Call(SetNpcImgFXParams, NPC_Luigi_Epilogue, IMGFX_SET_ANIM, IMGFX_ANIM_VERTICAL_PIPE_CURL, 1, 1, 0)
    Call(SetNpcPos, NPC_Luigi_Epilogue, -100, -10, -370)
    Call(GetNpcPos, NPC_Luigi_Epilogue, LVar0, LVar1, LVar2)
    Loop(45)
        Add(LVar1, 1)
        Call(SetNpcPos, NPC_Luigi_Epilogue, LVar0, LVar1, LVar2)
        Wait(1)
    EndLoop
    Call(SetNpcImgFXParams, NPC_Luigi_Epilogue, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetNpcPos, NPC_Luigi_Epilogue, -100, 30, -370)
    Wait(3)
    Call(EnableNpcShadow, NPC_Luigi_Epilogue, TRUE)
    Return
    End
};

EvtScript N(EVS_Scene_BeginEpilogue) = {
    Call(DisablePlayerInput, TRUE)
    Call(UseSettingsFrom, CAM_DEFAULT, -100, 30, -370)
    Call(SetPanTarget, CAM_DEFAULT, -100, 30, -370)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Thread
        ExecWait(N(EVS_PlayerExitPipe_Epilogue))
        Wait(10)
        Call(func_802D1270, -60, -320, Float(4.0))
    EndThread
    Thread
        Wait(70)
        ExecWait(N(EVS_LuigiExitPipe_Epilogue))
        Wait(10)
        Call(SetNpcFlagBits, NPC_Luigi_Epilogue, NPC_FLAG_GRAVITY, TRUE)
        Call(SetNpcAnimation, NPC_Luigi_Epilogue, ANIM_Luigi_Run)
        Call(SetNpcSpeed, NPC_Luigi_Epilogue, Float(4.0))
        Call(NpcMoveTo, NPC_Luigi_Epilogue, -100, -300, 0)
        Call(SetNpcAnimation, NPC_Luigi_Epilogue, ANIM_Luigi_Idle)
    EndThread
    Wait(70)
    Call(UseSettingsFrom, CAM_DEFAULT, -60, 0, -320)
    Call(SetPanTarget, CAM_DEFAULT, -60, 0, -320)
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Wait(80)
    Call(SpeakToPlayer, NPC_Luigi_Epilogue, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_Outro_0023)
    Wait(10)
    ChildThread
        Loop(0)
            Call(PlayerFaceNpc, NPC_Luigi_Epilogue, FALSE)
            Wait(1)
        EndLoop
    EndChildThread
    Call(SetNpcAnimation, NPC_Luigi_Epilogue, ANIM_Luigi_Run)
    Call(NpcMoveTo, NPC_Luigi_Epilogue, 60, -100, 0)
    Call(SetNpcFlagBits, NPC_Luigi_Epilogue, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcPos, NPC_Luigi_Epilogue, NPC_DISPOSE_LOCATION)
    Exec(N(EVS_BlockExitToGoomaRoad))
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
