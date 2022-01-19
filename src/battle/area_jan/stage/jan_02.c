#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_jan_jan_02

EvtScript N(beforeBattle_80228290) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_802282CC) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_802282DC)[] = {
    0x00000005, 0x00000006, 0x00000007, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "jan_tex",
    .shape = "jan_bt02_shape",
    .hit = "jan_bt02_hit",
    .bg = "yos_bg",
    .preBattle = N(beforeBattle_80228290),
    .postBattle = N(afterBattle_802282CC),
    .foregroundModelList = N(foregroundModelList_802282DC),
};
