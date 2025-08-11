#include "kpa_134.h"

s32 N(WallPanels)[] = {
    MODEL_o371, -230, 272, -100,
    MODEL_o372, -160, 272, -100,
    MODEL_o373, -103, 272, -100,
    MODEL_o374, -46, 272, -100,
    MODEL_o375, 10, 272, -100,
    MODEL_o376, 67, 272, -100,
    MODEL_o377, 135, 272, -100,
    MODEL_o382, 245, 272, -100,
    MODEL_o381, 318, 272, -100,
    MODEL_o380, 375, 272, -100,
    MODEL_o379, 432, 272, -100,
    MODEL_o378, 490, 272, -100,
    MODEL_o383, 547, 272, -100,
    MODEL_o384, 615, 272, -100,
    -1,
};

EvtScript N(EVS_FocusCam_Wall) = {
    Call(UseSettingsFrom, CAM_DEFAULT, LVar6, LVar7, LVar8)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.5))
    Call(SetCamDistance, CAM_DEFAULT, Float(450.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.5), Float(-8.0))
    Call(SetPanTarget, CAM_DEFAULT, LVar6, LVar7, LVar8)
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Return
    End
};

EvtScript N(EVS_FlipWallPanel) = {
    Call(MakeLerp, 0, 450, 15, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, LVar5, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(EnableModel, LVar5, false)
    Return
    End
};

EvtScript N(EVS_FlipWallPanels) = {
    Call(DisablePlayerInput, true)
    Loop(0)
        Wait(1)
        Call(GetPlayerActionState, LVar0)
        IfEq(LVar0, ACTION_STATE_IDLE)
            BreakLoop
        EndIf
    EndLoop
    Wait(20)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o383, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o384, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_sikake, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    UseBuf(Ref(N(WallPanels)))
    Call(GetPlayerPos, LVar6, LVar7, LVar8)
    Set(LVar6, 615)
    Exec(N(EVS_FocusCam_Wall))
    Loop(0)
        BufRead4(LVar5, LVar6, LVar7, LVar8)
        IfEq(LVar5, -1)
            BreakLoop
        EndIf
        Call(PlaySoundAt, SOUND_KPA_FLIP_BRIDGE_PANEL, SOUND_SPACE_DEFAULT, LVar6, LVar7, LVar8)
        Exec(N(EVS_FlipWallPanel))
        Wait(10)
    EndLoop
    Wait(50)
    Call(StopSound, SOUND_KPA_FLIP_BRIDGE_PANEL)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0))
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, false)
    Set(GF_KPA134_BlueSwitch, true)
    Call(DisablePlayerInput, false)
    Unbind
    Return
    End
};
