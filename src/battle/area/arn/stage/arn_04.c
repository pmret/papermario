#include "common.h"
#include "battle/battle.h"
#include "mapfs/arn_bt04_shape.h"

#define NAMESPACE b_area_arn_arn_04

EvtScript N(beforeBattle_80227B00) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80227B3C) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80227B4C)[] = {
    MODEL_o349, 0,
};

Stage NAMESPACE = {
    .texture = "arn_tex",
    .shape = "arn_bt04_shape",
    .hit = "arn_bt04_hit",
    .preBattle = &N(beforeBattle_80227B00),
    .postBattle = &N(afterBattle_80227B3C),
    .foregroundModelList = N(foregroundModelList_80227B4C),
};
