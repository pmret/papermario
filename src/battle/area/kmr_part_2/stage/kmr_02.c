#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_2_kmr_02

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
    .texture = "kmr_tex",
    .shape = "kmr_bt02_shape",
    .bg = "kmr_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
