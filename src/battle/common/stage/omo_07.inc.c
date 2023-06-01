#include "battle/battle.h"

#define NAMESPACE A(omo_07)

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "omo_tex",
    .shape = "omo_bt07_shape",
    .hit = "omo_bt07_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
