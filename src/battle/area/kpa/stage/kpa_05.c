#include "common.h"
#include "battle/battle.h"
#include "mapfs/kpa_bt05_shape.h"

#define NAMESPACE b_area_kpa_kpa_05

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
    MODEL_saku, 0,
};

Stage NAMESPACE = {
    .texture = "kpa_tex",
    .shape = "kpa_bt05_shape",
    .hit = "kpa_bt05_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
