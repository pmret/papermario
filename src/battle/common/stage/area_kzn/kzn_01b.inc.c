#include "battle/battle.h"
#include "mapfs/kzn_bt01_shape.h"

#define NAMESPACE A(kzn_01b)

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
    MODEL_ue2,
    MODEL_ue1,
    MODEL_iwa3,
    MODEL_sita1,
    MODEL_ue3,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "kzn_tex",
    .shape = "kzn_bt01_shape",
    .hit = "kzn_bt01_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
