#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_dgb_dgb_02

EvtScript N(beforeBattle_8021B0B0) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8021B0D0) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "dgb_tex",
    .shape = "dgb_bt02_shape",
    .hit = "dgb_bt02_hit",
    .preBattle = N(beforeBattle_8021B0B0),
    .postBattle = N(afterBattle_8021B0D0),
};
