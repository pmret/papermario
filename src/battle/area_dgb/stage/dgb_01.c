#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_dgb_dgb_01

EvtScript N(beforeBattle_8021B050) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8021B070) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "dgb_tex",
    .shape = "dgb_bt01_shape",
    .hit = "dgb_bt01_hit",
    .preBattle = &N(beforeBattle_8021B050),
    .postBattle = &N(afterBattle_8021B070),
};
