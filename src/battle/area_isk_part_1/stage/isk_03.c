#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_1_isk_03

EvtSource N(beforeBattle_80223A40) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(afterBattle_80223A7C) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt03_shape",
    .hit = "isk_bt03_hit",
    .bg = "sbk3_bg",
    .preBattle = N(beforeBattle_80223A40),
    .postBattle = N(afterBattle_80223A7C),
};
