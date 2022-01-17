#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_jan2_jan_04b

EvtScript N(beforeBattle_8021F520) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(SetGroupEnabled, 33, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8021F570) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8021F580)[] = {
    0x00000025, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "jan_tex",
    .shape = "jan_bt04_shape",
    .hit = "jan_bt04_hit",
    .bg = "jan_bg",
    .preBattle = N(beforeBattle_8021F520),
    .postBattle = N(afterBattle_8021F570),
    .foregroundModelList = N(foregroundModelList_8021F580),
};
