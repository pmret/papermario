#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_jan_jan_03

EvtScript N(beforeBattle_80228320) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(SetGroupEnabled, 22, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80228370) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80228380)[] = {
    0x00000040, 0x0000003F, 0x0000003E, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "jan_tex",
    .shape = "jan_bt03_shape",
    .hit = "jan_bt03_hit",
    .bg = "jan_bg",
    .preBattle = &N(beforeBattle_80228320),
    .postBattle = &N(afterBattle_80228370),
    .foregroundModelList = N(foregroundModelList_80228380),
};
