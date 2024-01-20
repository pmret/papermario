#include "flo_21.h"

s32 N(UnusedScaleVectors)[] = {
    Float(1.0), Float(1.0),
    Float(1.0), Float(1.0),
    Float(1.0), Float(1.0),
    Float(1.1), Float(1.1),
    Float(1.1), Float(1.1),
    Float(1.1), Float(1.1),
    Float(1.0), Float(1.0),
    Float(1.0), Float(1.0),
    Float(1.0), Float(1.0),
    Float(0.9), Float(0.9),
    Float(0.9), Float(0.9),
    Float(0.9), Float(0.9),
};

EvtScript N(EVS_UnkInit_00) = {
    AddF(MV_Unk_00, Float(-1.5))
    Return
    End
};

EvtScript N(EVS_UnkInit_01) = {
    AddF(MV_Unk_01, Float(-1.5))
    Return
    End
};

EvtScript N(EVS_UnkInit_02) = {
    AddF(MV_Unk_02, Float(-1.5))
    Return
    End
};

EvtScript N(EVS_UnkInit_03) = {
    AddF(MV_Unk_03, Float(-1.5))
    Return
    End
};

EvtScript N(EVS_UnkInit_04) = {
    AddF(MV_Unk_04, Float(-1.5))
    Return
    End
};

#include "common/CosInterpMinMax.inc.c"

EvtScript N(EVS_SetupCloudPuffs) = {
    Thread
        Set(LVarF, 0)
        Label(0)
            Call(N(CosInterpMinMax), LVarF, LVar0, Float(0.968), Float(1.031), 15, 0, 0)
            Call(N(CosInterpMinMax), LVarF, LVar1, Float(1.031), Float(0.968), 15, 0, 0)
            Call(ScaleModel, MODEL_o1, LVar1, LVar0, 1)
            Call(ScaleModel, MODEL_o2, LVar1, LVar0, 1)
            Call(ScaleModel, MODEL_o3, LVar0, LVar1, 1)
            Call(ScaleModel, MODEL_o4, LVar0, LVar1, 1)
            Call(ScaleModel, MODEL_o9, LVar0, LVar1, 1)
            Call(ScaleModel, MODEL_o14, LVar1, LVar0, 1)
            Call(ScaleModel, MODEL_o15, LVar0, LVar1, 1)
            Call(ScaleModel, MODEL_o16, LVar0, LVar1, 1)
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
