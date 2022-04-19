#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_trd_part_2_trd_00

EvtScript N(beforeBattle_802313E0) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8023141C) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8023142C)[] = {
    0x00000009, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "trd_tex",
    .shape = "trd_bt00_shape",
    .hit = "trd_bt00_hit",
    .preBattle = &N(beforeBattle_802313E0),
    .postBattle = &N(afterBattle_8023141C),
    .foregroundModelList = N(foregroundModelList_8023142C),
};
