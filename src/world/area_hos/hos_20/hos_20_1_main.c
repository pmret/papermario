#include "hos_20.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_TexPan_MotionLines) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, hos_20_ENTRY_2)
        EVT_CALL(RotateModel, MODEL_h1, 180, 0, 0, 1)
        EVT_CALL(RotateModel, MODEL_h2, 180, 0, 0, 1)
        EVT_CALL(RotateModel, MODEL_h3, 180, 0, 0, 1)
        EVT_CALL(RotateModel, MODEL_h4, 180, 0, 0, 1)
    EVT_END_IF
    EVT_CALL(EnableTexPanning, MODEL_h1, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_h2, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_h3, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_h4, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_C)
        TEX_PAN_PARAMS_STEP(-2048,-2048,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_B)
        TEX_PAN_PARAMS_STEP(-6144,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_D)
        TEX_PAN_PARAMS_STEP(    0,-5120,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_A)
        TEX_PAN_PARAMS_STEP( 1024,-3072,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_EXEC(N(EVS_TexPan_MotionLines))
    EVT_CALL(GetEntryID, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(hos_20_ENTRY_0)
            EVT_EXEC(N(EVS_Starship_Flight1))
        EVT_CASE_EQ(hos_20_ENTRY_1)
            EVT_EXEC(N(EVS_Starship_Flight2))
        EVT_CASE_EQ(hos_20_ENTRY_2)
            EVT_EXEC(N(EVS_Starship_Return))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};
