#include "common.h"
#include "battle/battle.h"
#include "mapfs/isk_bt02_shape.h"

#define NAMESPACE b_area_isk_part_1_isk_02b

EvtScript N(beforeBattle_80223D90) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(EnableModel, MODEL_o365, FALSE)
    EVT_CALL(EnableModel, MODEL_o366, FALSE)
    EVT_CALL(EnableModel, MODEL_o367, FALSE)
    EVT_CALL(EnableModel, MODEL_o389, FALSE)
    EVT_CALL(EnableModel, MODEL_o390, FALSE)
    EVT_CALL(EnableModel, MODEL_o391, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80223E44) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80223E54)[] = {
    MODEL_o398, MODEL_o397, MODEL_o399, 0,
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt02_shape",
    .hit = "isk_bt02_hit",
    .preBattle = &N(beforeBattle_80223D90),
    .postBattle = &N(afterBattle_80223E44),
    .foregroundModelList = N(foregroundModelList_80223E54),
};
