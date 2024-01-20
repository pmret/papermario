#include "hos_00.h"

EvtScript N(EVS_TexPan_ToggleUnused) = {
    Label(0)
        Call(SetTexPanOffset, TEX_PANNER_D, TEX_PANNER_MAIN, 0, 0)
        Wait(10)
        Call(SetTexPanOffset, TEX_PANNER_D, TEX_PANNER_MAIN, 0x4000, 0)
        Wait(10)
        Goto(0)
    Return
    End
};
