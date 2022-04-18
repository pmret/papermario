#include "common.h"
#include "battle/battle.h"
#include "mapfs/arn_bt03_shape.h"

#define NAMESPACE b_area_arn_arn_03

EvtScript N(beforeBattle_80227A90) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80227AB0) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80227AC0)[] = {
    -1, MODEL_iwa4, 0,
};

Stage NAMESPACE = {
    .texture = "arn_tex",
    .shape = "arn_bt03_shape",
    .hit = "arn_bt03_hit",
    .bg = "arn_bg",
    .preBattle = N(beforeBattle_80227A90),
    .postBattle = N(afterBattle_80227AB0),
    .foregroundModelList = N(foregroundModelList_80227AC0),
};
