#include "common.h"
#include "battle/battle.h"
#include "mapfs/isk_bt02_shape.h"

#define NAMESPACE b_area_isk_part_2_isk_02c

EvtScript N(beforeBattle_8021FF80) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(EnableModel, MODEL_kai2, FALSE)
    EVT_CALL(EnableModel, MODEL_kai1, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8021FFE4) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8021FFF4)[] = {
    MODEL_o398, MODEL_o397, MODEL_o399, 0,
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt02_shape",
    .hit = "isk_bt02_hit",
    .preBattle = &N(beforeBattle_8021FF80),
    .postBattle = &N(afterBattle_8021FFE4),
    .foregroundModelList = N(foregroundModelList_8021FFF4),
};
