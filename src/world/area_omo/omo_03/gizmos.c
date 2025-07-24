
#include "omo_03.h"
#include "effects.h"

EvtScript N(EVS_Gizmos_Wheels) = {
    Label(0)
        Call(MakeLerp, 0, -360, 100, EASING_LINEAR)
        Label(1)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_ha1, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha2, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha3, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha4, LVar0, 0, 0, 1)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Gizmos_Shutters) = {
    Label(0)
        Call(MakeLerp, 0, 160, 60, EASING_COS_IN_OUT)
        Label(1)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_m1_1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_m1_2, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
        Call(MakeLerp, 160, 0, 60, EASING_COS_IN_OUT)
        Label(2)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_m1_1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_m1_2, LVar0, 0, 1, 0)
            Wait(2)
            IfEq(LVar1, 1)
                Goto(2)
            EndIf
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Gizmos_Clocks) = {
    Label(0)
        Call(MakeLerp, 0, -360, 100, EASING_LINEAR)
        Label(1)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_hari1, LVar0, 0, 0, 1)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Scene_PullBlueSwitch) = {
    Call(DisablePlayerInput, true)
    Call(MakeLerp, 0, 70, 30, EASING_COS_IN_OUT)
    Label(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_bou1, LVar0, 0, 0, 1)
        Call(UpdateColliderTransform, COLLIDER_bou1)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(PlaySoundAt, SOUND_OMO_TRAIN_TRACK_LEVER, SOUND_SPACE_DEFAULT, -440, 10, 40)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o978, COLLIDER_FLAGS_UPPER_MASK)
    Wait(20)
    Call(UseSettingsFrom, CAM_DEFAULT, -184, 10, -229)
    Call(SetPanTarget, CAM_DEFAULT, -184, 10, -229)
    Call(SetCamDistance, CAM_DEFAULT, Float(517.4))
    Call(SetCamPosA, CAM_DEFAULT, Float(-180.0), Float(-322.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(25.0), Float(-6.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(20)
    Call(PlaySoundAt, SOUND_OMO_FLIP_TRAIN_TRACK, SOUND_SPACE_DEFAULT, -130, 0, -215)
    Call(MakeLerp, 0, 180, 30, EASING_COS_IN_OUT)
    Label(1)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_o933, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o818, LVar0, 1, 0, 0)
        Call(RotateModel, MODEL_o817, LVar0, 1, 0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(1)
        EndIf
    Call(PlaySoundAt, SOUND_OMO_FLIP_TRACK_THUD, SOUND_SPACE_DEFAULT, -130, 0, -215)
    Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(1.0))
    Call(GetModelCenter, MODEL_o932)
    PlayEffect(EFFECT_LANDING_DUST, 3, LVar0, LVar1, LVar2, 0)
    Wait(30)
    Set(GF_OMO03_BlueSwitchActivated, true)
    Call(SetNpcAnimation, NPC_Conductor, ANIM_TrainToad_Idle)
    Call(ResetCam, CAM_DEFAULT, Float(90.0))
    Call(DisablePlayerInput, false)
    Unbind
    Return
    End
};

EvtScript N(EVS_SetupGizmos) = {
    Exec(N(EVS_Gizmos_Wheels))
    Exec(N(EVS_Gizmos_Shutters))
    Exec(N(EVS_Gizmos_Clocks))
    Call(ParentColliderToModel, COLLIDER_bou1, MODEL_bou1)
    IfEq(GF_OMO03_BlueSwitchActivated, false)
        BindTrigger(Ref(N(EVS_Scene_PullBlueSwitch)), TRIGGER_WALL_PRESS_A, COLLIDER_o801, 1, 0)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o978, COLLIDER_FLAGS_UPPER_MASK)
    Else
        Call(RotateModel, MODEL_bou1, 70, 0, 0, 1)
        Call(UpdateColliderTransform, COLLIDER_bou1)
        Call(RotateModel, MODEL_o933, 180, 1, 0, 0)
        Call(RotateModel, MODEL_o818, 180, 1, 0, 0)
        Call(RotateModel, MODEL_o817, 180, 1, 0, 0)
    EndIf
    Return
    End
};
