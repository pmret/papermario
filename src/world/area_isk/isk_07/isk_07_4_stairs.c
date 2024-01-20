#include "isk_07.h"

EvtScript N(EVS_RedStairs_FlipCCW) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o1994, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2000, COLLIDER_FLAGS_UPPER_MASK)
    Call(PlaySoundAtCollider, COLLIDER_o2000, SOUND_LOOP_ISK_FLIP_STAIRS, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 90, 30, EASING_QUADRATIC_OUT)
    Label(10)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_g311, LVar0, 0, 0, 1)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Call(StopSound, SOUND_LOOP_ISK_FLIP_STAIRS)
    Return
    End
};

EvtScript N(EVS_RedStairs_FlipCW) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1994, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2000, COLLIDER_FLAGS_UPPER_MASK)
    Call(PlaySoundAtCollider, COLLIDER_o1994, SOUND_LOOP_ISK_FLIP_STAIRS, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 90, 0, 30, EASING_QUADRATIC_OUT)
    Label(10)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_g311, LVar0, 0, 0, 1)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Call(StopSound, SOUND_LOOP_ISK_FLIP_STAIRS)
    Return
    End
};

EvtScript N(EVS_FlipRedStairs) = {
    Call(InterpCamTargetPos, 0, 1, 369, -349, 369, 20)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
    Call(UseSettingsFrom, CAM_DEFAULT, 369, -349, 369)
    Call(SetPanTarget, CAM_DEFAULT, 369, -349, 369)
    Wait(1)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    IfEq(MF_StairsFlipped, FALSE)
        ExecWait(N(EVS_RedStairs_FlipCCW))
        Set(MF_StairsFlipped, TRUE)
    Else
        ExecWait(N(EVS_RedStairs_FlipCW))
        Set(MF_StairsFlipped, FALSE)
    EndIf
    Call(ShakeCam, CAM_DEFAULT, 0, 3, Float(0.1))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Call(DisablePlayerInput, FALSE)
    Set(AF_ISK07_FlippingRedStairs, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupStairs) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o1994, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2000, COLLIDER_FLAGS_UPPER_MASK)
    Set(MF_StairsFlipped, FALSE)
    BindTrigger(Ref(N(EVS_FlipRedStairs)), TRIGGER_AREA_FLAG_SET, AF_ISK07_FlippingRedStairs, 1, 0)
    Return
    End
};
