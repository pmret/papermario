#include "battle/battle.h"
#include "mapfs/tik_bt05_shape.h"

#define NAMESPACE A(tik_05)

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(SetTexPanner, MODEL_taki1, TEX_PANNER_1)
    EVT_CALL(EnableTexPanning, MODEL_taki1, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(   0, -2700,   0, -3000)
        TEX_PAN_PARAMS_FREQ(   1,     1,   1,     1)
        TEX_PAN_PARAMS_INIT(   0,     0,   0,     0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_CALL(SetTexPanner, MODEL_taki2, TEX_PANNER_2)
    EVT_CALL(EnableTexPanning, MODEL_taki2, TRUE)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(   50, -200,  110, -500)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    MODEL_taki1,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "tik_tex",
    .shape = "tik_bt05_shape",
    .hit = "tik_bt05_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};

