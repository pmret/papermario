#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "mapfs/iwa_bt01_shape.h"

#define NAMESPACE b_area_dig_dig_02

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetGroupVisibility, MODEL_a, MODEL_GROUP_HIDDEN)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    MODEL_iwa1, MODEL_o331, 0,
};

Stage NAMESPACE = {
    .texture = "iwa_tex",
    .shape = "iwa_bt01_shape",
    .hit = "iwa_bt01_hit",
    .bg = "iwa_bg",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
};
