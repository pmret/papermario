#include "omo_01.h"
#include "model.h"

EvtScript N(EVS_Gizmos_Wheels) = {
    Loop(0)
        Call(MakeLerp, 0, -360, 100, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_ha1, LVar0, 1, 0, 1)
            Call(RotateModel, MODEL_ha2, LVar0, 1, 0, 1)
            Call(RotateModel, MODEL_ha3, LVar0, 1, 0, 1)
            Call(RotateModel, MODEL_ha4, LVar0, 1, 0, 1)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_Gizmos_Shutters) = {
    Loop(0)
        Call(MakeLerp, 0, 160, 60, EASING_COS_IN_OUT)
        Label(1)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_m1_1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_m1_2, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_m2_1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_m2_2, LVar0, 0, 1, 0)
            Call(RotateModel, MODEL_m4_1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_m4_2, LVar0, 0, 1, 0)
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
            Call(RotateModel, MODEL_m4_1, LVar0, 0, -1, 0)
            Call(RotateModel, MODEL_m4_2, LVar0, 0, 1, 0)
            Wait(2)
            IfEq(LVar1, 1)
                Goto(2)
            EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_Gizmos_Clocks) = {
    Loop(0)
        Call(MakeLerp, 0, -360, 100, EASING_LINEAR)
        Label(1)
            Call(UpdateLerp)
            Call(RotateModel, MODEL_hari1, LVar0, 0, 0, 1)
            Call(RotateModel, MODEL_hari2, LVar0, 1, 0, 1)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(1)
            EndIf
    EndLoop
    Return
    End
};

s32 N(RockingHorseModels)[] = {
    MODEL_o353,
    MODEL_o355,
};

#define ROCKING_SOUND_LOCATION -185.0f, 0.0f, 160.0f
#define ROCKING_USE_SIN_DEG 1
#import "../common/RockingHorse.inc.c"

EvtScript N(EVS_SetupGizmos) = {
    Exec(N(EVS_Gizmos_Wheels))
    Exec(N(EVS_Gizmos_Shutters))
    Exec(N(EVS_Gizmos_Clocks))
    Exec(N(EVS_Gizmos_RockingHorses))
    Return
    End
};
