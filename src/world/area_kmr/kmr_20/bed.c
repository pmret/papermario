#include "kmr_20.h"
#include "sprite/player.h"

#include "world/common/complete/ToadHouseBlanketAnim.inc.c"
#include "world/common/atomic/ToadHouse.inc.c"
#include "world/common/atomic/ToadHouse.data.inc.c"

API_CALLABLE(N(MuteAmbienceVolume_Bed)) {
    snd_ambient_set_volume(0, 1000, 1);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetAmbienceVolumeHalf_Bed)) {
    snd_ambient_set_volume(0, 1000, 63);
    return ApiStatus_DONE2;
}

#include "world/common/todo/WaitForPlayerToLand.inc.c"

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    Set(LVar0, MSG_CH0_0106)
    Set(LVar8, MSG_CH0_0107)
    Set(LVar1, 0)
    Set(LVar2, 0)
    Set(LVar3, 0)
    Return
    End
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    Exec(N(EVS_PlayRestingSong))
    Call(SetPlayerSpeed, Float(3.0))
    Call(PlayerMoveTo, -28, -100, 0)
    Call(InterpPlayerYaw, 300, 0)
    Call(DisablePlayerPhysics, true)
    Thread
        Wait(6)
        Call(N(ToadHouse_CamSetFOV), 0, 40)
        Call(SetCamType, CAM_DEFAULT, 4, false)
        Call(SetCamPitch, CAM_DEFAULT, 35, -10)
        Call(SetCamDistance, CAM_DEFAULT, 135)
        Call(SetCamPosA, CAM_DEFAULT, -170, 0)
        Call(SetCamPosB, CAM_DEFAULT, -109, -76)
        Call(SetCamPosC, CAM_DEFAULT, 0, 120)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Call(EnableGroup, MODEL_o170, false)
        Call(EnableGroup, MODEL_o172, false)
        Call(EnableGroup, MODEL_o175, false)
        Call(EnableGroup, MODEL_o177, false)
        Call(EnableGroup, MODEL_o178, false)
        Call(EnableGroup, MODEL_o183, false)
        Call(EnableGroup, MODEL_o188, false)
        Call(EnableGroup, MODEL_o189, false)
        Call(EnableGroup, MODEL_o186, false)
        Call(EnableGroup, MODEL_o190, false)
        Call(EnableGroup, MODEL_o191, false)
    EndThread
    Call(GetPlayerPos, LVar4, LVar5, LVar6)
    Call(MakeLerp, 30, 85, 6, EASING_LINEAR)
    Loop(6)
        Wait(1)
        Call(UpdateLerp)
        Call(SetPlayerPos, LVar4, LVar0, LVar6)
    EndLoop
    Call(HidePlayerShadow, true)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    Call(UpdatePlayerImgFX, 0x00010002, IMGFX_SET_ANIM, IMGFX_ANIM_GET_IN_BED, 1, 1, 0)
    Thread
        Wait(60)
        Call(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    EndThread
    Call(N(MuteAmbienceVolume_Bed))
    Wait(75)
    Thread
        Wait(65)
        Call(N(ToadHouse_CamSetFOV), 0, 25)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Call(PanToTarget, CAM_DEFAULT, 0, false)
        Call(EnableGroup, MODEL_o170, true)
        Call(EnableGroup, MODEL_o172, true)
        Call(EnableGroup, MODEL_o175, true)
        Call(EnableGroup, MODEL_o177, true)
        Call(EnableGroup, MODEL_o178, true)
        Call(EnableGroup, MODEL_o183, true)
        Call(EnableGroup, MODEL_o188, true)
        Call(EnableGroup, MODEL_o189, true)
        Call(EnableGroup, MODEL_o186, true)
        Call(EnableGroup, MODEL_o190, true)
        Call(EnableGroup, MODEL_o191, true)
    EndThread
    Return
    End
};

EvtScript N(EVS_ToadHouse_ReturnFromRest) = {
    Call(N(SetAmbienceVolumeHalf_Bed))
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(HidePlayerShadow, false)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetPlayerPos, -45, 30, -70)
    Call(InterpPlayerYaw, 90, 0)
    Call(SetNpcPos, NPC_PARTNER, -75, 30, -70)
    Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
    Wait(5)
    Exec(N(EVS_SetupMusic))
    Call(DisablePlayerPhysics, false)
    Return
    End
};

EvtScript N(EVS_UseBed) = {
    Call(N(WaitForPlayerToLand))
    IfEq(LVar0, 1)
        Return
    EndIf
    Call(DisablePlayerInput, true)
    Call(N(ToadHouse_InitScreenOverlay), 0, 0, 0)
    ExecWait(N(EVS_ToadHouse_SetDialogue))
    IfEq(LVar0, 0)
        Call(DisablePlayerInput, false)
        Return
    EndIf
    Set(LVar9, LVar1)
    Set(LVarA, LVar2)
    Set(LVarB, LVar3)
    Call(N(ToadHouse_DoesPlayerNeedSleep))
    IfEq(LVar1, 0)
        Set(LVar8, LVar0)
    EndIf
    Call(ShowMessageAtScreenPos, LVar8, 160, 40)
    Call(ShowChoice, MSG_Choice_0007)
    Wait(10)
    IfEq(LVar0, 1)
        Call(CloseMessage)
        Call(DisablePlayerInput, false)
        Return
    EndIf
    Call(CloseMessage)
    Call(SetPlayerJumpscale, 1)
    Call(DisablePlayerPhysics, true)
    Call(N(ToadHouse_DisableStatusBar))
    IfNe(LVar4, 0)
        Exec(N(EVS_ToadHouse_Unk2))
    EndIf
    Call(N(ToadHouse_PutPartnerAway), LVarA)
    Wait(20)
    ExecGetTID(N(EVS_ToadHouse_GetInBed), LVar9)
    Call(N(ToadHouse_AwaitScriptComplete), LVar9)
    Thread
        Call(MakeLerp, 0, 255, 60, EASING_LINEAR)
        Label(0)
        Call(UpdateLerp)
        Call(N(ToadHouse_UpdateScreenOverlay), 3, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
        Call(FullyRestoreHPandFP)
        Call(FullyRestoreSP)
        IfNe(LVar4, 0)
            Exec(N(EVS_ToadHouse_Unk1))
        EndIf
        Call(N(ToadHouse_GetPartnerBackOut), LVarA)
        Wait(30)
        Call(MakeLerp, 255, 0, 30, EASING_LINEAR)
        Label(1)
        Call(UpdateLerp)
        Call(N(ToadHouse_UpdateScreenOverlay), 0, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(1)
        EndIf
    EndThread
    Wait(90)
    ExecGetTID(N(EVS_ToadHouse_ReturnFromRest), LVar9)
    Call(N(ToadHouse_AwaitScriptComplete), LVar9)
    Call(DisablePlayerPhysics, false)
    Call(N(ToadHouse_ShowWorldStatusBar))
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_SetupBed) = {
    BindTrigger(Ref(N(EVS_UseBed)), TRIGGER_WALL_PRESS_A, COLLIDER_o352, 1, 0)
    Return
    End
};
