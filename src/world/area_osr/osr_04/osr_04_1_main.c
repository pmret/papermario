#include "osr_04.h"

EvtScript N(EVS_TexPan_Smoke) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, MODEL_ke1, TEX_PANNER_0)
    EVT_CALL(SetTexPanner, MODEL_ke2, TEX_PANNER_1)
    EVT_CALL(SetTexPanner, MODEL_ke3, TEX_PANNER_2)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_LABEL(10)
    EVT_LOOP(5)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_0, 0, LVar0, LVar1)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_1, 0, LVar0, LVar1)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_2, 0, LVar0, LVar1)
        EVT_ADD(LVar1, 100)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_ADD(LVar0, 0x2000)
    EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterMap) = {
    EVT_EXEC(N(EVS_Scene_BowsersAssault))
    EVT_EXEC(N(EVS_TexPan_Smoke))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_NONE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_NO_LEAD()
    EVT_CALL(FadeOutMusic, 0, 500)
    EVT_EXEC(N(EVS_EnterMap))
    EVT_WAIT(1)
    EVT_RETURN
    EVT_END
};
