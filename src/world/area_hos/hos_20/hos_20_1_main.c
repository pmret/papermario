#include "hos_20.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_TexPan_MotionLines) = {
    SetGroup(EVT_GROUP_00)
    Call(GetEntryID, LVar0)
    IfEq(LVar0, hos_20_ENTRY_2)
        Call(RotateModel, MODEL_h1, 180, 0, 0, 1)
        Call(RotateModel, MODEL_h2, 180, 0, 0, 1)
        Call(RotateModel, MODEL_h3, 180, 0, 0, 1)
        Call(RotateModel, MODEL_h4, 180, 0, 0, 1)
    EndIf
    Call(EnableTexPanning, MODEL_h1, TRUE)
    Call(EnableTexPanning, MODEL_h2, TRUE)
    Call(EnableTexPanning, MODEL_h3, TRUE)
    Call(EnableTexPanning, MODEL_h4, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_C)
        TEX_PAN_PARAMS_STEP(-2048,-2048,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_B)
        TEX_PAN_PARAMS_STEP(-6144,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_D)
        TEX_PAN_PARAMS_STEP(    0,-5120,    0,    0)
        TEX_PAN_PARAMS_FREQ(    0,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_A)
        TEX_PAN_PARAMS_STEP( 1024,-3072,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    0,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Return
    End
};

EvtScript N(EVS_Main) = {
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    Exec(N(EVS_TexPan_MotionLines))
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(hos_20_ENTRY_0)
            Exec(N(EVS_Starship_Flight1))
        CaseEq(hos_20_ENTRY_1)
            Exec(N(EVS_Starship_Flight2))
        CaseEq(hos_20_ENTRY_2)
            Exec(N(EVS_Starship_Return))
    EndSwitch
    Return
    End
};
