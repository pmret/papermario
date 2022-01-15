#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_1_isk_02

EvtSource N(beforeBattle_802239B0) = {
    EVT_CALL(SetSpriteShading, 786432)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(afterBattle_802239EC) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_802239FC)[] = {
    0x0000001F, 0x0000001E, 0x00000021, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt02_shape",
    .hit = "isk_bt02_hit",
    .preBattle = N(beforeBattle_802239B0),
    .postBattle = N(afterBattle_802239EC),
    .foregroundModelList = N(foregroundModelList_802239FC),
};
