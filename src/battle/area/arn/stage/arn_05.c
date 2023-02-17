#include "common.h"
#include "battle/battle.h"
#include "mapfs/arn_bt05_shape.h"

#define NAMESPACE b_area_arn_arn_05

EvtScript N(beforeBattle_80227B80) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80227BBC) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80227BCC)[] = {
    MODEL_o354, 0,
};

Stage NAMESPACE = {
    .texture = "arn_tex",
    .shape = "arn_bt05_shape",
    .hit = "arn_bt05_hit",
    .preBattle = &N(beforeBattle_80227B80),
    .postBattle = &N(afterBattle_80227BBC),
    .foregroundModelList = N(foregroundModelList_80227BCC),
};
