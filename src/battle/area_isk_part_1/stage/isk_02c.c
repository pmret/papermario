#include "common.h"
#include "battle/battle.h"
#include "mapfs/isk_bt02_shape.h"

#define NAMESPACE b_area_isk_part_1_isk_02c

EvtScript N(beforeBattle_80223E90) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(EnableModel, MODEL_kai2, 0)
    EVT_CALL(EnableModel, MODEL_kai1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80223EF4) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80223F04)[] = {
    MODEL_o398, MODEL_o397, MODEL_o399, 0,
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt02_shape",
    .hit = "isk_bt02_hit",
    .preBattle = &N(beforeBattle_80223E90),
    .postBattle = &N(afterBattle_80223EF4),
    .foregroundModelList = N(foregroundModelList_80223F04),
};
