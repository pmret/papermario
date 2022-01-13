#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_2_isk_00

EvtSource N(beforeBattle_8021FCF0) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtSource N(afterBattle_8021FD2C) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt00_shape",
    .preBattle = N(beforeBattle_8021FCF0),
    .postBattle = N(afterBattle_8021FD2C),
};
