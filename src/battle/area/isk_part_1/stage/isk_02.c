#include "common.h"
#include "battle/battle.h"
#include "mapfs/isk_bt02_shape.h"

#define NAMESPACE b_area_isk_part_1_isk_02

EvtScript N(beforeBattle_802239B0) = {
    EVT_CALL(SetSpriteShading, SHADING_BTL_ISK)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_802239EC) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_802239FC)[] = {
    MODEL_o398, MODEL_o397, MODEL_o399, 0,
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt02_shape",
    .hit = "isk_bt02_hit",
    .preBattle = &N(beforeBattle_802239B0),
    .postBattle = &N(afterBattle_802239EC),
    .foregroundModelList = N(foregroundModelList_802239FC),
};
