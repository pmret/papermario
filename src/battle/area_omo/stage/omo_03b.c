#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_omo_omo_03b

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "omo_tex",
    .shape = "omo_bt03_shape",
    .hit = "omo_bt03_hit",
    .bg = "omo_bg",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
};
