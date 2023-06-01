#include "battle/battle.h"
#include "mapfs/nok_bt03_shape.h"

#define NAMESPACE A(nok_03)

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
    MODEL_ha3,
    MODEL_hap,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "nok_tex",
    .shape = "nok_bt03_shape",
    .hit = "nok_bt03_hit",
    .bg = "nok_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
