#include "mim_09.h"

EvtScript N(EVS_FlowersGentleRocking) = {
    Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, -0x8000)
    Wait(2)
    Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, -0x10000)
    Wait(2)
    Call(PlaySoundAt, SOUND_FLOWERS_LAUGH, SOUND_SPACE_DEFAULT, -23, 0, 300)
    Call(MakeLerp, 0, 30, 50, EASING_COS_IN_OUT)
    Label(10)
    Call(UpdateLerp)
    Call(RotateModel, MODEL_o464, LVar0, 0, 0, 1)
    Call(RotateModel, MODEL_o465, LVar0, 0, 0, 1)
    Call(RotateModel, MODEL_o466, LVar0, 0, 0, 1)
    Call(RotateModel, MODEL_o467, LVar0, 0, 0, 1)
    Call(RotateModel, MODEL_o468, LVar0, 0, 0, 1)
    Call(RotateModel, MODEL_o469, LVar0, 0, 0, 1)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(10)
    EndIf
    Call(PlaySoundAt, SOUND_FLOWERS_LAUGH, SOUND_SPACE_DEFAULT, -23, 0, 300)
    Call(MakeLerp, 30, -30, 50, EASING_COS_IN_OUT)
    Label(20)
    Call(UpdateLerp)
    Call(RotateModel, MODEL_o464, LVar0, 0, 0, 1)
    Call(RotateModel, MODEL_o465, LVar0, 0, 0, 1)
    Call(RotateModel, MODEL_o466, LVar0, 0, 0, 1)
    Call(RotateModel, MODEL_o467, LVar0, 0, 0, 1)
    Call(RotateModel, MODEL_o468, LVar0, 0, 0, 1)
    Call(RotateModel, MODEL_o469, LVar0, 0, 0, 1)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(20)
    EndIf
    Call(PlaySoundAt, SOUND_FLOWERS_LAUGH, SOUND_SPACE_DEFAULT, -23, 0, 300)
    Call(MakeLerp, -30, 0, 50, EASING_COS_IN_OUT)
    Label(30)
    Call(UpdateLerp)
    Call(RotateModel, MODEL_o464, LVar0, 0, 0, 1)
    Call(RotateModel, MODEL_o465, LVar0, 0, 0, 1)
    Call(RotateModel, MODEL_o466, LVar0, 0, 0, 1)
    Call(RotateModel, MODEL_o467, LVar0, 0, 0, 1)
    Call(RotateModel, MODEL_o468, LVar0, 0, 0, 1)
    Call(RotateModel, MODEL_o469, LVar0, 0, 0, 1)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(30)
    EndIf
    Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, -0x8000)
    Wait(2)
    Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, 0, 0)
    Wait(20)
    Return
    End
};

EvtScript N(EVS_InspectBush) = {
    IfEq(MV_FoundHint, false)
        Set(MV_FoundHint, true)
        Call(SetGroupVisibility, MODEL_hana, MODEL_GROUP_VISIBLE)
        Call(PlaySound, SOUND_FLOWERS_GROW)
        Call(MakeLerp, 10, 100, 30, EASING_LINEAR)
        Label(0)
        Call(UpdateLerp)
        MulF(LVar0, Float(0.01))
        Call(ScaleModel, MODEL_o464, LVar0, LVar0, LVar0)
        Call(ScaleModel, MODEL_o465, LVar0, LVar0, LVar0)
        Call(ScaleModel, MODEL_o466, LVar0, LVar0, LVar0)
        Call(ScaleModel, MODEL_o467, LVar0, LVar0, LVar0)
        Call(ScaleModel, MODEL_o468, LVar0, LVar0, LVar0)
        Call(ScaleModel, MODEL_o469, LVar0, LVar0, LVar0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
        Wait(10)
        ExecWait(N(EVS_FlowersGentleRocking))
    Else
        ExecWait(N(EVS_FlowersGentleRocking))
    EndIf
    Return
    End
};

EvtScript N(EVS_SetupExitHint) = {
    Set(MV_FoundHint, 0)
    Call(SetGroupVisibility, MODEL_hana, MODEL_GROUP_HIDDEN)
    Call(SetTexPanner, MODEL_o465, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o467, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_o469, TEX_PANNER_0)
    BindTrigger(Ref(N(EVS_InspectBush)), TRIGGER_WALL_PRESS_A, COLLIDER_atari_kusa, 1, 0)
    Return
    End
};
