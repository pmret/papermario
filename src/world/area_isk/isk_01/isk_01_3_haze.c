#include "isk_01.h"

Gfx N(HazePreGfx)[] = {
    gsDPSetAlphaDither(G_AD_NOISE),
    gsSPEndDisplayList(),
};

EvtScript N(EVS_SetupHaze) = {
    EVT_CALL(SetTexPanner, MODEL_o99, TEX_PANNER_2)
    EVT_CALL(EnableTexPanning, MODEL_o99, TRUE)
    EVT_SET(LVar0, 0)
    EVT_CALL(SetCustomGfx, 0, EVT_PTR(N(HazePreGfx)), NULL)
    EVT_CALL(SetModelFlags, MODEL_o99, MODEL_FLAG_USES_CUSTOM_GFX, TRUE)
    EVT_LABEL(0)
        EVT_ADD(LVar0, 70)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, LVar0, 0)
        EVT_IF_GT(LVar0, 0x4000)
            EVT_ADD(LVar0, -0x4000)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};
