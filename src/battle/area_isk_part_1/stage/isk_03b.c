#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_1_isk_03b

EvtSource N(beforeBattle_80223D10) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(afterBattle_80223D4C) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt03_shape",
    .hit = "isk_bt03_hit",
    .preBattle = N(beforeBattle_80223D10),
    .postBattle = N(afterBattle_80223D4C),
};
