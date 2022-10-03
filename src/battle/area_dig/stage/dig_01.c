#include "common.h"
#include "battle/battle.h"
#include "mapfs/nok_bt04_shape.h"

#define NAMESPACE b_area_dig_dig_01

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    MODEL_ueki2, MODEL_ueki1, MODEL_kabu2, MODEL_kabu1, MODEL_kusa3, 0,
};

Stage NAMESPACE = {
    .texture = "nok_tex",
    .shape = "nok_bt04_shape",
    .hit = "nok_bt04_hit",
    .bg = "nok_bg",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
};
