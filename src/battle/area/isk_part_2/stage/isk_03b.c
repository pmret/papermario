#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_2_isk_03b

EvtScript N(beforeBattle_802200B0) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_802200EC) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt03_shape",
    .hit = "isk_bt03_hit",
    .preBattle = &N(beforeBattle_802200B0),
    .postBattle = &N(afterBattle_802200EC),
};
