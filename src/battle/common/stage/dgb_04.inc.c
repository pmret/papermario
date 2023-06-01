#include "battle/battle.h"
#include "mapfs/dgb_bt04_shape.h"

#define NAMESPACE A(dgb_04)

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
    MODEL_kumo1,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "dgb_tex",
    .shape = "dgb_bt04_shape",
    .hit = "dgb_bt04_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
