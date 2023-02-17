#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_kmr_part_2_kmr_02

EvtScript N(beforeBattle_80224700) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80224720) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "kmr_tex",
    .shape = "kmr_bt02_shape",
    .bg = "kmr_bg",
    .preBattle = &N(beforeBattle_80224700),
    .postBattle = &N(afterBattle_80224720),
};
