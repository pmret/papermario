#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_trd_part_1_trd_00

EvtScript N(beforeBattle_80224B70) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80224BAC) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80224BBC)[] = {
    0x00000009, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "trd_tex",
    .shape = "trd_bt00_shape",
    .hit = "trd_bt00_hit",
    .preBattle = &N(beforeBattle_80224B70),
    .postBattle = &N(afterBattle_80224BAC),
    .foregroundModelList = N(foregroundModelList_80224BBC),
};
