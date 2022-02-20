#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_omo_omo_03b

EvtScript N(beforeBattle_8022DCB0) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8022DCEC) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "omo_tex",
    .shape = "omo_bt03_shape",
    .hit = "omo_bt03_hit",
    .bg = "omo_bg",
    .preBattle = N(beforeBattle_8022DCB0),
    .postBattle = N(afterBattle_8022DCEC),
};
