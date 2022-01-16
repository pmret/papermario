#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_2_isk_02c

EvtScript N(beforeBattle_8021FF80) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(EnableModel, 14, 0)
    EVT_CALL(EnableModel, 11, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8021FFE4) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8021FFF4)[] = {
    0x0000001F, 0x0000001E, 0x00000021, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt02_shape",
    .hit = "isk_bt02_hit",
    .preBattle = N(beforeBattle_8021FF80),
    .postBattle = N(afterBattle_8021FFE4),
    .foregroundModelList = N(foregroundModelList_8021FFF4),
};
