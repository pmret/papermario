#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/kpa_bt03_shape.h"

#define NAMESPACE b_area_kpa_kpa_03

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(func_80253734, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    MODEL_tar1, 0,
};

Stage NAMESPACE = {
    .texture = "kpa_tex",
    .shape = "kpa_bt03_shape",
    .hit = "kpa_bt03_hit",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
};
