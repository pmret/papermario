#include "isk_09.h"

EvtScript N(EVS_FlipStairsCCW) = {
    Wait(20)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar3, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, LVar4, COLLIDER_FLAGS_UPPER_MASK)
    Call(PlaySoundAtCollider, LVar4, SOUND_LOOP_ISK_FLIP_STAIRS, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 90, LVar5, EASING_COS_IN)
    Label(10)
        Call(UpdateLerp)
        Call(RotateModel, LVar2, LVar0, 0, 0, 1)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Call(StopSound, SOUND_LOOP_ISK_FLIP_STAIRS)
    Return
    End
};

EvtScript N(EVS_FlipStairsCW) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, LVar3, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, LVar4, COLLIDER_FLAGS_UPPER_MASK)
    Call(PlaySoundAtCollider, LVar3, SOUND_LOOP_ISK_FLIP_STAIRS, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 90, 0, LVar5, EASING_COS_IN)
    Label(10)
        Call(UpdateLerp)
        Call(RotateModel, LVar2, LVar0, 0, 0, 1)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Call(StopSound, SOUND_LOOP_ISK_FLIP_STAIRS)
    Return
    End
};

EvtScript N(EVS_FlipStairsCCW_BottomBlue) = {
    Set(LVar2, MODEL_g321)
    Set(LVar3, COLLIDER_o2031)
    Set(LVar4, COLLIDER_o2032)
    Set(LVar5, 30)
    ExecWait(N(EVS_FlipStairsCCW))
    Return
    End
};

EvtScript N(EVS_FlipStairsCW_BottomBlue) = {
    Set(LVar2, MODEL_g321)
    Set(LVar3, COLLIDER_o2031)
    Set(LVar4, COLLIDER_o2032)
    Set(LVar5, 30)
    ExecWait(N(EVS_FlipStairsCW))
    Return
    End
};

EvtScript N(EVS_FlipStairsCCW_TopBlue) = {
    Set(LVar2, MODEL_g327)
    Set(LVar3, COLLIDER_o2034)
    Set(LVar4, COLLIDER_o2033)
    Set(LVar5, 30)
    ExecWait(N(EVS_FlipStairsCCW))
    Return
    End
};

EvtScript N(EVS_FlipStairsCW_TopBlue) = {
    Set(LVar2, MODEL_g327)
    Set(LVar3, COLLIDER_o2034)
    Set(LVar4, COLLIDER_o2033)
    Set(LVar5, 30)
    ExecWait(N(EVS_FlipStairsCW))
    Return
    End
};

EvtScript N(EVS_FlipStairsCCW_BottomRed) = {
    Set(LVar2, MODEL_g328)
    Set(LVar3, COLLIDER_o2036)
    Set(LVar4, COLLIDER_o2035)
    Set(LVar5, 30)
    ExecWait(N(EVS_FlipStairsCCW))
    Return
    End
};

EvtScript N(EVS_FlipStairsCW_BottomRed) = {
    Set(LVar2, MODEL_g328)
    Set(LVar3, COLLIDER_o2036)
    Set(LVar4, COLLIDER_o2035)
    Set(LVar5, 30)
    ExecWait(N(EVS_FlipStairsCW))
    Return
    End
};

EvtScript N(EVS_FlipStairsCCW_TopRed) = {
    Set(LVar2, MODEL_g329)
    Set(LVar3, COLLIDER_o2037)
    Set(LVar4, COLLIDER_o2038)
    Set(LVar5, 30)
    ExecWait(N(EVS_FlipStairsCCW))
    Return
    End
};

EvtScript N(EVS_FlipStairsCW_TopRed) = {
    Set(LVar2, MODEL_g329)
    Set(LVar3, COLLIDER_o2037)
    Set(LVar4, COLLIDER_o2038)
    Set(LVar5, 30)
    ExecWait(N(EVS_FlipStairsCW))
    Return
    End
};

EvtScript N(EVS_BlueStairs_FlipCCW) = {
    Call(DisablePlayerInput, true)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(UseSettingsFrom, CAM_DEFAULT, -522, -310, -95)
    Call(SetPanTarget, CAM_DEFAULT, -522, -377, -92)
    Wait(1)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    ExecWait(N(EVS_FlipStairsCCW_BottomBlue))
    Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(0.1))
    Call(SetPanTarget, CAM_DEFAULT, -522, -222, -92)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    ExecWait(N(EVS_FlipStairsCCW_TopBlue))
    Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(0.1))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_BlueStairs_FlipCW) = {
    Call(DisablePlayerInput, true)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(UseSettingsFrom, CAM_DEFAULT, -522, -310, -95)
    Call(SetPanTarget, CAM_DEFAULT, -522, -377, -92)
    Wait(1)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    ExecWait(N(EVS_FlipStairsCW_BottomBlue))
    Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(0.1))
    Call(SetPanTarget, CAM_DEFAULT, -522, -222, -92)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    ExecWait(N(EVS_FlipStairsCW_TopBlue))
    Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(0.1))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_RedStairs_FlipCCW) = {
    Call(DisablePlayerInput, true)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(UseSettingsFrom, CAM_DEFAULT, -408, -310, -347)
    Call(SetPanTarget, CAM_DEFAULT, -408, -377, -347)
    Wait(1)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    ExecWait(N(EVS_FlipStairsCCW_BottomRed))
    Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(0.1))
    Call(SetPanTarget, CAM_DEFAULT, -408, -222, -347)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    ExecWait(N(EVS_FlipStairsCCW_TopRed))
    Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(0.1))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_RedStairs_FlipCW) = {
    Call(DisablePlayerInput, true)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(UseSettingsFrom, CAM_DEFAULT, -408, -310, -347)
    Call(SetPanTarget, CAM_DEFAULT, -408, -377, -347)
    Wait(1)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    ExecWait(N(EVS_FlipStairsCW_BottomRed))
    Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(0.1))
    Call(SetPanTarget, CAM_DEFAULT, -408, -222, -347)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    ExecWait(N(EVS_FlipStairsCW_TopRed))
    Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(0.1))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Call(DisablePlayerInput, false)
    Return
    End
};

EvtScript N(EVS_FlipBlueStairs) = {
    IfEq(MF_BlueStairsFlipped, false)
        ExecWait(N(EVS_BlueStairs_FlipCCW))
        Set(MF_BlueStairsFlipped, true)
    Else
        ExecWait(N(EVS_BlueStairs_FlipCW))
        Set(MF_BlueStairsFlipped, false)
    EndIf
    Call(DisablePlayerInput, false)
    Set(AF_ISK09_FlippingBlueStairs, false)
    Return
    End
};

EvtScript N(EVS_FlipRedStairs) = {
    IfEq(MF_RedStairsFlipped, false)
        ExecWait(N(EVS_RedStairs_FlipCW))
        Set(MF_RedStairsFlipped, true)
    Else
        ExecWait(N(EVS_RedStairs_FlipCCW))
        Set(MF_RedStairsFlipped, false)
    EndIf
    Call(DisablePlayerInput, false)
    Set(AF_ISK09_FlippingRedStairs, false)
    Return
    End
};

EvtScript N(EVS_SetupStairs) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2032, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2033, COLLIDER_FLAGS_UPPER_MASK)
    Call(RotateModel, MODEL_g328, 90, 0, 0, 1)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2036, COLLIDER_FLAGS_UPPER_MASK)
    Call(RotateModel, MODEL_g329, 90, 0, 0, 1)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2037, COLLIDER_FLAGS_UPPER_MASK)
    Set(MF_BlueStairsFlipped, false)
    Set(MF_RedStairsFlipped, false)
    BindTrigger(Ref(N(EVS_FlipBlueStairs)), TRIGGER_AREA_FLAG_SET, AF_ISK09_FlippingBlueStairs, 1, 0)
    BindTrigger(Ref(N(EVS_FlipRedStairs)), TRIGGER_AREA_FLAG_SET, AF_ISK09_FlippingRedStairs, 1, 0)
    Return
    End
};
