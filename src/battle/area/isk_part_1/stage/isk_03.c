#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_1_isk_03

EvtScript N(beforeBattle_80223A40) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80223A7C) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt03_shape",
    .hit = "isk_bt03_hit",
    .bg = "sbk3_bg",
    .preBattle = &N(beforeBattle_80223A40),
    .postBattle = &N(afterBattle_80223A7C),
};
