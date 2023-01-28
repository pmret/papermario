#include "common.h"
#include "battle/battle.h"
#include "mapfs/kkj_bt01_shape.h"

#define NAMESPACE b_area_kpa2_kpa_02

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    MODEL_hana, MODEL_ha1, MODEL_ha2, 0,
};

Stage NAMESPACE = {
    .texture = "kkj_tex",
    .shape = "kkj_bt01_shape",
    .hit = "kkj_bt01_hit",
    .bg = "kpa_bg",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
};
