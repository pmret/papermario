#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_dig_dig_05

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "dgb_tex",
    .shape = "dgb_bt05_shape",
    .hit = "dgb_bt05_hit",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
};
