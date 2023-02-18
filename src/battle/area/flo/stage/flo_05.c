#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_flo_flo_05

#include "common/MakeSun.inc.c"

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_EXEC_WAIT(N(MakeSun))
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "flo_tex",
    .shape = "flo_bt05_shape",
    .hit = "flo_bt05_hit",
    .bg = "fla_bg",
    .preBattle = &N(beforeBattle),
    .postBattle = &N(afterBattle),
};
