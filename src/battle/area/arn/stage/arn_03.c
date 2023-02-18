#include "common.h"
#include "battle/battle.h"
#include "mapfs/arn_bt03_shape.h"

#define NAMESPACE b_area_arn_arn_03

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
    -1, MODEL_iwa4, 0,
};

Stage NAMESPACE = {
    .texture = "arn_tex",
    .shape = "arn_bt03_shape",
    .hit = "arn_bt03_hit",
    .bg = "arn_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
