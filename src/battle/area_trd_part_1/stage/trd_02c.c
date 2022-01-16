#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_trd_part_1_trd_02c

EvtScript N(beforeBattle_80224BF0) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(EnableModel, 26, 0)
    EVT_CALL(EnableModel, 2, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80224C54) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80224C64)[] = {
    0x00000016, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "trd_tex",
    .shape = "trd_bt02_shape",
    .hit = "trd_bt02_hit",
    .preBattle = N(beforeBattle_80224BF0),
    .postBattle = N(afterBattle_80224C54),
    .foregroundModelList = N(foregroundModelList_80224C64),
};
