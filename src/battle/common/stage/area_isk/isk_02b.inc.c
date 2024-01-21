#include "battle/battle.h"
#include "mapfs/isk_bt02_shape.h"

#define NAMESPACE A(isk_02b)

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Call(EnableModel, MODEL_o365, FALSE)
    Call(EnableModel, MODEL_o366, FALSE)
    Call(EnableModel, MODEL_o367, FALSE)
    Call(EnableModel, MODEL_o389, FALSE)
    Call(EnableModel, MODEL_o390, FALSE)
    Call(EnableModel, MODEL_o391, FALSE)
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

s32 N(ForegroundModels)[] = {
    MODEL_o398,
    MODEL_o397,
    MODEL_o399,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt02_shape",
    .hit = "isk_bt02_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
