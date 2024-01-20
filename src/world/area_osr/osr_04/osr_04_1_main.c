#include "osr_04.h"

EvtScript N(EVS_TexPan_Smoke) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, MODEL_ke1, TEX_PANNER_0)
    Call(SetTexPanner, MODEL_ke2, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_ke3, TEX_PANNER_2)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Label(10)
    Loop(5)
        Call(SetTexPanOffset, TEX_PANNER_0, 0, LVar0, LVar1)
        Call(SetTexPanOffset, TEX_PANNER_1, 0, LVar0, LVar1)
        Call(SetTexPanOffset, TEX_PANNER_2, 0, LVar0, LVar1)
        Add(LVar1, 100)
        Wait(1)
    EndLoop
    Add(LVar0, 0x2000)
    Goto(10)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Exec(N(EVS_Scene_BowsersAssault))
    Exec(N(EVS_TexPan_Smoke))
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_NONE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Call(FadeOutMusic, 0, 500)
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
