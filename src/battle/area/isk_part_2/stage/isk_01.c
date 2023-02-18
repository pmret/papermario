#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_isk_part_2_isk_01

EvtScript N(beforeBattle_8021FD70) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8021FDAC) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "isk_tex",
    .shape = "isk_bt01_shape",
    .hit = "isk_bt01_hit",
    .preBattle = &N(beforeBattle_8021FD70),
    .postBattle = &N(afterBattle_8021FDAC),
};
