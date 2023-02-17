#include "common.h"
#include "battle/battle.h"
#include "mapfs/arn_bt06_shape.h"

#define NAMESPACE b_area_arn_arn_06

EvtScript N(beforeBattle_80227C00) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80227C20) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80227C30)[] = {
    MODEL_kabe3, 0,
};

Stage NAMESPACE = {
    .texture = "arn_tex",
    .shape = "arn_bt06_shape",
    .hit = "arn_bt06_hit",
    .preBattle = &N(beforeBattle_80227C00),
    .postBattle = &N(afterBattle_80227C20),
    .foregroundModelList = N(foregroundModelList_80227C30),
};
