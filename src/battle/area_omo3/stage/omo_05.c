#include "common.h"
#include "battle/battle.h"
#include "mapfs/omo_bt05_shape.h"

#define NAMESPACE b_area_omo3_omo_05

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(SetGroupEnabled, 24, 0)
    EVT_CALL(SetGroupEnabled, 28, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList)[] = {
    MODEL_itigo, MODEL_kisya, 0,
};

Stage NAMESPACE = {
    .texture = "omo_tex",
    .shape = "omo_bt05_shape",
    .hit = "omo_bt05_hit",
    .bg = "omo_bg",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
    .foregroundModelList = N(foregroundModelList),
};
