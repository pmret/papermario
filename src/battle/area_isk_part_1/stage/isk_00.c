#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_1_isk_00

EvtSource N(beforeBattle_802238B0) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(afterBattle_802238EC) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt00_shape",
    .preBattle = N(beforeBattle_802238B0),
    .postBattle = N(afterBattle_802238EC),
};
