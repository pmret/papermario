#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_flo2_flo_05

#include "common/MakeSun.inc.c"

EvtScript N(beforeBattle) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
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
