#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_dgb_dgb_05

EvtScript N(beforeBattle_8021B1D0) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8021B1F0) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "dgb_tex",
    .shape = "dgb_bt05_shape",
    .hit = "dgb_bt05_hit",
    .preBattle = &N(beforeBattle_8021B1D0),
    .postBattle = &N(afterBattle_8021B1F0),
};
