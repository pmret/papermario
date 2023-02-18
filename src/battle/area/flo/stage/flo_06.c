#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_flo_flo_06

#include "common/MakeSun.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_EXEC_WAIT(N(MakeSun))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "flo_tex",
    .shape = "flo_bt06_shape",
    .hit = "flo_bt06_hit",
    .bg = "fla_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
