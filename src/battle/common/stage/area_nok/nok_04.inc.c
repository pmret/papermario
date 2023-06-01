#include "battle/battle.h"
#include "mapfs/nok_bt04_shape.h"

#define NAMESPACE A(nok_04)

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
    MODEL_ueki2,
    MODEL_ueki1,
    MODEL_kabu2,
    MODEL_kabu1,
    MODEL_kusa3,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "nok_tex",
    .shape = "nok_bt04_shape",
    .hit = "nok_bt04_hit",
    .bg = "nok_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
