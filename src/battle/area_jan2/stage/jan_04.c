#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_jan2_jan_04

EvtScript N(beforeBattle_8021F490) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(SetGroupEnabled, 65, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8021F4E0) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8021F4F0)[] = {
    0x00000025, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "jan_tex",
    .shape = "jan_bt04_shape",
    .hit = "jan_bt04_hit",
    .bg = "jan_bg",
    .preBattle = &N(beforeBattle_8021F490),
    .postBattle = &N(afterBattle_8021F4E0),
    .foregroundModelList = N(foregroundModelList_8021F4F0),
};
