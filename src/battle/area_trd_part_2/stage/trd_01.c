#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_trd_part_2_trd_01

EvtScript N(beforeBattle_80231460) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8023149C) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "trd_tex",
    .shape = "trd_bt01_shape",
    .hit = "trd_bt01_hit",
    .preBattle = &N(beforeBattle_80231460),
    .postBattle = &N(afterBattle_8023149C),
};
