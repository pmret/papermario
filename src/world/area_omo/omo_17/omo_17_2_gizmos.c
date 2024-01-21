#include "omo_17.h"

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
            Call(RotateModel, MODEL_ha6, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha7, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha8, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha9, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha10, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha11, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha12, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha13, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha14, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha15, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha16, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha17, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_ha18, LVar0, 0, 0, 1)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
        Goto(0)
    Return
    End
};

EvtScript N(EVS_SetupGizmos) = {
    Exec(N(EVS_Gizmos_Wheels))
    Return
    End
};
