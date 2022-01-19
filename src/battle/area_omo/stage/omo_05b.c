#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_omo_omo_05b

EvtScript N(beforeBattle_8022F580) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(SetGroupEnabled, 35, 0)
    EVT_CALL(SetGroupEnabled, 45, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8022F5E4) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8022F5F4)[] = {
    0x0000001B, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "omo_tex",
    .shape = "omo_bt05_shape",
    .hit = "omo_bt05_hit",
    .bg = "omo_bg",
    .preBattle = N(beforeBattle_8022F580),
    .postBattle = N(afterBattle_8022F5E4),
    .foregroundModelList = N(foregroundModelList_8022F5F4),
};
