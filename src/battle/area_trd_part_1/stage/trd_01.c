#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_trd_part_1_trd_01

EvtSource N(beforeBattle_80222AE0) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(afterBattle_80222B1C) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "trd_tex",
    .shape = "trd_bt01_shape",
    .hit = "trd_bt01_hit",
    .preBattle = N(beforeBattle_80222AE0),
    .postBattle = N(afterBattle_80222B1C),
};
