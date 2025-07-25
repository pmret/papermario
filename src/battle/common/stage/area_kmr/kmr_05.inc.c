#include "battle/battle.h"
#include "mapfs/kmr_bt05_shape.h"

#define NAMESPACE A(kmr_05)

#include "battle/common/stage/lib/MovingClouds.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(EnableModel, MODEL_o302, false)
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

s32 N(ForegroundModels)[] = {
    MODEL_n2,
    MODEL_m4,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "kmr_tex",
    .shape = "kmr_bt05_shape",
    .hit = "kmr_bt05_hit",
    .bg = "kmr_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
