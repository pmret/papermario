#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_1_kmr_02

EvtScript N(beforeBattle_8021FDA0) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8021FDC0) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "kmr_tex",
    .shape = "kmr_bt02_shape",
    .bg = "kmr_bg",
    .preBattle = &N(beforeBattle_8021FDA0),
    .postBattle = &N(afterBattle_8021FDC0),
};
