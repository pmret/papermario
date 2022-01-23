#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_1_isk_02c

EvtScript N(beforeBattle_80223E90) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(EnableModel, 14, 0)
    EVT_CALL(EnableModel, 11, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80223EF4) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80223F04)[] = {
    0x0000001F, 0x0000001E, 0x00000021, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt02_shape",
    .hit = "isk_bt02_hit",
    .preBattle = N(beforeBattle_80223E90),
    .postBattle = N(afterBattle_80223EF4),
    .foregroundModelList = N(foregroundModelList_80223F04),
};
