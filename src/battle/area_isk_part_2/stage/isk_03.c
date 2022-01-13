#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_2_isk_03

EvtSource N(beforeBattle_80220030) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(afterBattle_8022006C) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt03_shape",
    .hit = "isk_bt03_hit",
    .bg = "sbk3_bg",
    .preBattle = N(beforeBattle_80220030),
    .postBattle = N(afterBattle_8022006C),
};
