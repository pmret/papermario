#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_dgb_dgb_03

EvtScript N(beforeBattle_8021B110) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8021B130) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "dgb_tex",
    .shape = "dgb_bt03_shape",
    .hit = "dgb_bt03_hit",
    .preBattle = &N(beforeBattle_8021B110),
    .postBattle = &N(afterBattle_8021B130),
};
