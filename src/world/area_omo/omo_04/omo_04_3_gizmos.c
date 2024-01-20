#include "omo_04.h"

EvtScript N(EVS_Gizmos_Wheels) = {
    Label(0)
        Call(MakeLerp, 0, -360, 100, EASING_LINEAR)
        Label(1)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_ha1, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha2, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha3, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha4, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha5, LVar0, 0, 0, 1)
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
    Label(0)
        Call(MakeLerp, 0, 160, 60, EASING_COS_IN_OUT)
        Label(1)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_m1_1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_m1_2, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_m2_1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_m2_2, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_m3_1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_m3_2, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
        Call(MakeLerp, 160, 0, 60, EASING_COS_IN_OUT)
        Label(2)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_m1_1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_m1_2, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_m2_1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_m2_2, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_m3_1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_m3_2, LVar0, 0, 1, 0)
            Wait(2)
            IfEq(LVar1, 1)
                Goto(2)
            EndIf
        Goto(0)
    Return
    End
};

EvtScript N(EVS_SetupGizmos) = {
    Exec(N(EVS_Gizmos_Wheels))
    Exec(N(EVS_Gizmos_Shutters))
    Return
    End
};
