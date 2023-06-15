#include "battle/battle.h"
#include "mapfs/arn_bt05_shape.h"

#define NAMESPACE A(arn_05)

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    MODEL_o354,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "arn_tex",
    .shape = "arn_bt05_shape",
    .hit = "arn_bt05_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
