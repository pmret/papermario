#include "battle/battle.h"
#include "mapfs/arn_bt01_shape.h"

#define NAMESPACE A(arn_01)

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    -1,
    MODEL_iwa4,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "arn_tex",
    .shape = "arn_bt01_shape",
    .hit = "arn_bt01_hit",
    .bg = "arn_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
