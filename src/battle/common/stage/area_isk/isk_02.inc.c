#include "battle/battle.h"
#include "mapfs/isk_bt02_shape.h"

#define NAMESPACE A(isk_02)

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_BTL_ISK)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
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
