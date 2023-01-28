#include "common.h"
#include "battle/battle.h"
#include "mapfs/isk_bt02_shape.h"

#define NAMESPACE b_area_isk_part_2_isk_02b

EvtScript N(beforeBattle_8021FE80) = {
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

EvtScript N(afterBattle_8021FF34) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8021FF44)[] = {
    MODEL_o398, MODEL_o397, MODEL_o399, 0,
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt02_shape",
    .hit = "isk_bt02_hit",
    .preBattle = &N(beforeBattle_8021FE80),
    .postBattle = &N(afterBattle_8021FF34),
    .foregroundModelList = N(foregroundModelList_8021FF44),
};
