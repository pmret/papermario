#include "hos_00.h"

EvtScript N(EVS_TexPan_ToggleUnused) = {
    EVT_LABEL(0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_D, TEX_PANNER_MAIN, 0, 0)
        EVT_WAIT(10)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_D, TEX_PANNER_MAIN, 0x4000, 0)
        EVT_WAIT(10)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};
