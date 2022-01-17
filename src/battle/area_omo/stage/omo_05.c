#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_omo_omo_05

EvtScript N(beforeBattle_8022F4D0) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(SetGroupEnabled, 24, 0)
    EVT_CALL(SetGroupEnabled, 28, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8022F534) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_8022F544)[] = {
    0x00000027, 0x00000026, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "omo_tex",
    .shape = "omo_bt05_shape",
    .hit = "omo_bt05_hit",
    .bg = "omo_bg",
    .preBattle = N(beforeBattle_8022F4D0),
    .postBattle = N(afterBattle_8022F534),
    .foregroundModelList = N(foregroundModelList_8022F544),
};
