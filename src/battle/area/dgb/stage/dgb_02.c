#include "common.h"
#include "battle/battle.h"
#include "mapfs/dgb_bt02_shape.h"

#define NAMESPACE b_area_dgb_dgb_02

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "dgb_tex",
    .shape = "dgb_bt02_shape",
    .hit = "dgb_bt02_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
