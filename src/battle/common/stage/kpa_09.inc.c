#include "battle/battle.h"
#include "mapfs/kpa_bt09_shape.h"

#define NAMESPACE A(kpa_09)

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
    MODEL_o353,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "kpa_tex",
    .shape = "kpa_bt09_shape",
    .hit = "kpa_bt09_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
