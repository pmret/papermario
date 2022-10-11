#include "common.h"
#include "battle/battle.h"
#include "mapfs/kpa_bt08_shape.h"

#define NAMESPACE b_area_kpa4_kpa_08

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    MODEL_o478, 0,
};

Stage NAMESPACE = {
    .texture = "kpa_tex",
    .shape = "kpa_bt08_shape",
    .hit = "kpa_bt08_hit",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
};
