#include "kzn_23.h"

#include "../common/SmokeTexPanners.inc.c"

// should add to zero over a full cycle
s32 N(LavaFluctuationOffsets)[] = {
     1,  2,  3,  3,  2,  1,
    -1, -2, -3, -3, -2, -1,
};

// overlay a sinusoidal offset to the lava level
EvtScript N(EVS_ModulateLavaLevel) = {
    Loop(0)
        UseBuf(N(LavaFluctuationOffsets))
        Loop(ARRAY_COUNT(N(LavaFluctuationOffsets)))
            BufRead1(LVar1)
            Add(MV_LavaLevel, LVar1)
            Wait(3)
        EndLoop
    EndLoop
    Return
    End
};

EvtScript N(EVS_RaiseLava) = {
    Exec(N(EVS_ModulateLavaLevel))
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, MODEL_yu, TEX_PANNER_0)
    Set(LVar0, 0)
    Set(LVar1, 0)
    Set(LVar2, 0)
    Set(LVar3, 0)
    Set(MV_LavaLevel, -105)
    Set(LVar5, 40)
    Call(TranslateModel, MODEL_yu, 0, MV_LavaLevel, 0)
    Wait(6)
    Label(10)
        Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, LVar0, LVar1)
        Call(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_AUX, LVar2, LVar3)
        Sub(LVar0, 700)
        Add(LVar1, 700)
        Add(LVar2, 200)
        Sub(LVar3, 300)
        IfEq(LVar5, 40)
            IfLt(MV_LavaLevel, 2700)
                Add(MV_LavaLevel, 20)
            Else
                Sub(LVar5, 1)
            EndIf
        Else
            IfNe(LVar5, 0)
                Sub(LVar5, 1)
                Sub(MV_LavaLevel, 1)
            EndIf
        EndIf
        Call(TranslateModel, MODEL_yu, 0, MV_LavaLevel, 0)
        Wait(1)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    Call(SetSpriteShading, SHADING_KZN_23)
    EVT_SETUP_CAMERA_DEFAULT()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_RaiseLava))
    Set(LVar0, MODEL_kem1)
    Exec(N(EVS_StartTexPanner_SmokeLeft))
    Set(LVar0, MODEL_kem2)
    Exec(N(EVS_StartTexPanner_SmokeRight))
    Return
    End
};
