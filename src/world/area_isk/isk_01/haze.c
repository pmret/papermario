#include "isk_01.h"

Gfx N(HazePreGfx)[] = {
    gsDPSetAlphaDither(G_AD_NOISE),
    gsSPEndDisplayList(),
};

EvtScript N(EVS_SetupHaze) = {
    Call(SetTexPanner, MODEL_o99, TEX_PANNER_2)
    Call(EnableTexPanning, MODEL_o99, TRUE)
    Set(LVar0, 0)
    Call(SetCustomGfx, 0, Ref(N(HazePreGfx)), NULL)
    Call(SetModelFlags, MODEL_o99, MODEL_FLAG_USES_CUSTOM_GFX, TRUE)
    Label(0)
        Add(LVar0, 70)
        Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, LVar0, 0)
        IfGt(LVar0, 0x4000)
            Add(LVar0, -0x4000)
        EndIf
        Wait(1)
        Goto(0)
    Return
    End
};
