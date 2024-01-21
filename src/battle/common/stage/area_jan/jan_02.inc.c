#include "battle/battle.h"
#include "mapfs/jan_bt02_shape.h"

#define NAMESPACE A(jan_02)

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
    MODEL_o64,
    MODEL_o65,
    MODEL_o66,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "jan_tex",
    .shape = "jan_bt02_shape",
    .hit = "jan_bt02_hit",
    .bg = "yos_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
