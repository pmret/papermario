#include "common.h"
#include "battle/battle.h"
#include "mapfs/mim_bt01_shape.h"

#define NAMESPACE b_area_mim_mim_01

#include "common/UnkFogFunc2.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(N(UnkFogFunc2))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "mim_tex",
    .shape = "mim_bt01_shape",
    .hit = "mim_bt01_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
