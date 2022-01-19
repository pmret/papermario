#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_jan2_jan_02

EvtScript N(beforeBattle_8021F2C0) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8021F2FC) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8021F30C)[] = {
    0x00000005, 0x00000006, 0x00000007, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "jan_tex",
    .shape = "jan_bt02_shape",
    .hit = "jan_bt02_hit",
    .bg = "yos_bg",
    .preBattle = N(beforeBattle_8021F2C0),
    .postBattle = N(afterBattle_8021F2FC),
    .foregroundModelList = N(foregroundModelList_8021F30C),
};
