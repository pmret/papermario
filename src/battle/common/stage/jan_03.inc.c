#include "battle/battle.h"
#include "mapfs/jan_bt03_shape.h"

#define NAMESPACE A(jan_03)

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(SetGroupVisibility, MODEL_g2, MODEL_GROUP_HIDDEN)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    MODEL_o91,
    MODEL_o90,
    MODEL_o86,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "jan_tex",
    .shape = "jan_bt03_shape",
    .hit = "jan_bt03_hit",
    .bg = "jan_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
