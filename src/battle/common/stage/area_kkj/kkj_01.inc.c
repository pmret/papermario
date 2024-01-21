#include "battle/battle.h"
#include "mapfs/kkj_bt01_shape.h"

#define NAMESPACE A(kkj_01)

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

s32 N(ForegroundModels)[] = {
    MODEL_hana,
    MODEL_ha1,
    MODEL_ha2,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "kkj_tex",
    .shape = "kkj_bt01_shape",
    .hit = "kkj_bt01_hit",
    .bg = "kpa_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
