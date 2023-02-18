#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_nok_nok_03

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
    0x0000000E,
    0x0000000F,
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
