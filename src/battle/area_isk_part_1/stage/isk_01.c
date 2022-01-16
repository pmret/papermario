#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_1_isk_01

EvtScript N(beforeBattle_80223930) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8022396C) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt01_shape",
    .hit = "isk_bt01_hit",
    .preBattle = N(beforeBattle_80223930),
    .postBattle = N(afterBattle_8022396C),
};
