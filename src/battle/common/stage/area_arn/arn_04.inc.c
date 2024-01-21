#include "battle/battle.h"
#include "mapfs/arn_bt04_shape.h"

#define NAMESPACE A(arn_04)

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

s32 N(ForegroundModels)[] = {
    MODEL_o349,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "arn_tex",
    .shape = "arn_bt04_shape",
    .hit = "arn_bt04_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
