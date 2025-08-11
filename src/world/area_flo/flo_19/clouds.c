#include "flo_19.h"

API_CALLABLE(N(CosInterpAbsMinMax)) {
    Bytecode* args = script->ptrReadPos;
    s32 outVarTime = *args++;
    s32 time = evt_get_variable(script, outVarTime);
    s32 outValue = *args++;
    f32 min = evt_get_float_variable(script, *args++);
    f32 max = evt_get_float_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);
    s32 onlyOnce = evt_get_variable(script, *args++);
    f32 phaseOffset = (evt_get_float_variable(script, *args++) / 180.0f) * PI;
    f32 delta = fabsf(max - min) / 2; // fabsf here is the only difference between this and CosInterpMinMax

    if (onlyOnce && duration < time) {
        time = duration;
        evt_set_variable(script, outVarTime, duration);
    }

    evt_set_float_variable(script, outValue,
        (min + delta) // average value
        - (delta * cos_rad(((time * PI) / duration) + phaseOffset))); // perturbation

    return ApiStatus_DONE2;
}

EvtScript N(EVS_AnimatePlatforms) = {
    SetGroup(EVT_GROUP_NOT_BATTLE)
    Set(LVarF, 0)
    Label(0)
        SetF(LVar0, Float(-215.4375))
        SetF(LVar1, Float(128.593))
        SetF(LVar2, Float(-200.0))
        AddF(LVar1, MV_Distortion_Platform_01)
        Call(TranslateGroup, MODEL_g17, LVar0, LVar1, LVar2)
        SetF(LVar0, Float(-79.86))
        Call(N(CosInterpAbsMinMax), LVarF, LVar1, Float(5.0), Float(136.765), 300, 0, 0)
        SetF(LVar2, Float(-200.0))
        AddF(LVar1, MV_Distortion_Platform_02)
        Call(TranslateGroup, MODEL_g21, LVar0, LVar1, LVar2)
        SetF(LVar0, Float(-364.265625))
        Call(N(CosInterpAbsMinMax), LVarF, LVar1, Float(5.0), Float(106.765), 300, 0, 0)
        SetF(LVar2, Float(10.0))
        AddF(LVar1, MV_Distortion_Platform_03)
        Call(TranslateGroup, MODEL_g22, LVar0, LVar1, LVar2)
        SetF(LVar0, Float(295.734))
        Call(N(CosInterpAbsMinMax), LVarF, LVar1, Float(65.0), Float(86.984), 200, 0, 0)
        SetF(LVar2, Float(-80.0))
        AddF(LVar1, MV_Distortion_Platform_04)
        Call(TranslateGroup, MODEL_g23, LVar0, LVar1, LVar2)
        Call(N(CosInterpAbsMinMax), LVarF, LVar2, Float(0.968), Float(1.031), 15, 0, 0)
        Call(N(CosInterpAbsMinMax), LVarF, LVar3, Float(1.031), Float(0.968), 15, 0, 0)
        SetF(LVar0, MV_Distortion_Platform_01)
        SetF(LVar1, MV_Distortion_Platform_01)
        MulF(LVar0, Float(-0.02))
        MulF(LVar1, Float(0.04))
        AddF(LVar0, LVar2)
        AddF(LVar1, LVar3)
        Call(ScaleGroup, MODEL_g17, LVar0, LVar1, 1)
        SetF(LVar0, MV_Distortion_Platform_02)
        SetF(LVar1, MV_Distortion_Platform_02)
        MulF(LVar0, Float(-0.02))
        MulF(LVar1, Float(0.04))
        AddF(LVar0, LVar2)
        AddF(LVar1, LVar3)
        Call(ScaleGroup, MODEL_g21, LVar0, LVar1, 1)
        SetF(LVar0, MV_Distortion_Platform_03)
        SetF(LVar1, MV_Distortion_Platform_03)
        MulF(LVar0, Float(-0.02))
        MulF(LVar1, Float(0.04))
        AddF(LVar0, LVar2)
        AddF(LVar1, LVar3)
        Call(ScaleGroup, MODEL_g22, LVar0, LVar1, 1)
        SetF(LVar0, MV_Distortion_Platform_04)
        SetF(LVar1, MV_Distortion_Platform_04)
        MulF(LVar0, Float(-0.02))
        MulF(LVar1, Float(0.04))
        AddF(LVar0, LVar2)
        AddF(LVar1, LVar3)
        Call(ScaleGroup, MODEL_g23, LVar0, LVar1, 1)
        Call(UpdateColliderTransform, COLLIDER_o77)
        Call(UpdateColliderTransform, COLLIDER_o78)
        Call(UpdateColliderTransform, COLLIDER_o76)
        Call(UpdateColliderTransform, COLLIDER_o79)
        Add(LVarF, 1)
        IfGe(LVarF, 1200)
            Set(LVarF, 0)
        EndIf
        SetF(LVar0, LVarA)
        SetF(LVar1, LVarB)
        SetF(LVar2, LVarC)
        SetF(LVar3, LVarD)
        MulF(LVar0, Float(-0.046875))
        MulF(LVar1, Float(-0.09375))
        MulF(LVar2, Float(-0.09375))
        MulF(LVar3, Float(-0.09375))
        AddF(MV_Distortion_Platform_01, LVar0)
        AddF(MV_Distortion_Platform_02, LVar1)
        AddF(MV_Distortion_Platform_03, LVar2)
        AddF(MV_Distortion_Platform_04, LVar3)
        MulF(MV_Distortion_Platform_01, Float(0.843))
        MulF(MV_Distortion_Platform_02, Float(0.843))
        MulF(MV_Distortion_Platform_03, Float(0.843))
        MulF(MV_Distortion_Platform_04, Float(0.843))
        AddF(LVarA, MV_Distortion_Platform_01)
        AddF(LVarB, MV_Distortion_Platform_02)
        AddF(LVarC, MV_Distortion_Platform_03)
        AddF(LVarD, MV_Distortion_Platform_04)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_AddPlayerWeight_Platform_01) = {
    Thread
        AddF(MV_Distortion_Platform_01, Float(-1.5))
        Wait(1)
        AddF(MV_Distortion_Platform_01, Float(-1.5))
    EndThread
    Return
    End
};

EvtScript N(EVS_AddPlayerWeight_Platform_02) = {
    Thread
        AddF(MV_Distortion_Platform_02, Float(-1.5))
        Wait(1)
        AddF(MV_Distortion_Platform_02, Float(-1.5))
    EndThread
    Return
    End
};

EvtScript N(EVS_AddPlayerWeight_Platform_03) = {
    Thread
        AddF(MV_Distortion_Platform_03, Float(-1.5))
        Wait(1)
        AddF(MV_Distortion_Platform_03, Float(-1.5))
    EndThread
    Return
    End
};

EvtScript N(EVS_AddPlayerWeight_Platform_04) = {
    Thread
        AddF(MV_Distortion_Platform_04, Float(-1.5))
        Wait(1)
        AddF(MV_Distortion_Platform_04, Float(-1.5))
    EndThread
    Return
    End
};

EvtScript N(EVS_SetupClouds) = {
    Call(ParentColliderToModel, COLLIDER_o77, MODEL_g17)
    Call(ParentColliderToModel, COLLIDER_o78, MODEL_g21)
    Call(ParentColliderToModel, COLLIDER_o76, MODEL_g22)
    Call(ParentColliderToModel, COLLIDER_o79, MODEL_g23)
    Call(SetModelFlags, MODEL_g17, MODEL_FLAG_BILLBOARD, true)
    Call(SetModelFlags, MODEL_g21, MODEL_FLAG_BILLBOARD, true)
    Call(SetModelFlags, MODEL_g22, MODEL_FLAG_BILLBOARD, true)
    Call(SetModelFlags, MODEL_g23, MODEL_FLAG_BILLBOARD, true)
    Exec(N(EVS_AnimatePlatforms))
    BindTrigger(Ref(N(EVS_AddPlayerWeight_Platform_01)), TRIGGER_FLOOR_TOUCH, COLLIDER_o77, 1, 0)
    BindTrigger(Ref(N(EVS_AddPlayerWeight_Platform_02)), TRIGGER_FLOOR_TOUCH, COLLIDER_o78, 1, 0)
    BindTrigger(Ref(N(EVS_AddPlayerWeight_Platform_03)), TRIGGER_FLOOR_TOUCH, COLLIDER_o76, 1, 0)
    BindTrigger(Ref(N(EVS_AddPlayerWeight_Platform_04)), TRIGGER_FLOOR_TOUCH, COLLIDER_o79, 1, 0)
    Thread
        Set(LVarF, 0)
        Label(0)
            Call(N(CosInterpAbsMinMax), LVarF, LVar0, Float(0.968), Float(1.031), 15, 0, 0)
            Call(N(CosInterpAbsMinMax), LVarF, LVar1, Float(1.031), Float(0.968), 15, 0, 0)
            Call(ScaleModel, MODEL_o73, LVar1, LVar0, 1)
            Call(ScaleModel, MODEL_o74, LVar1, LVar0, 1)
            Call(ScaleModel, MODEL_o75, LVar0, LVar1, 1)
            Call(ScaleModel, MODEL_o76, LVar0, LVar1, 1)
            Call(ScaleModel, MODEL_o77, LVar0, LVar1, 1)
            Call(ScaleModel, MODEL_o78, LVar1, LVar0, 1)
            Call(ScaleModel, MODEL_o45, LVar0, LVar1, 1)
            Call(ScaleModel, MODEL_o56, LVar0, LVar1, 1)
            Add(LVarF, 1)
            IfGe(LVarF, 30)
                Set(LVarF, 0)
            EndIf
            Wait(1)
            Goto(0)
    EndThread
    Return
    End
};
