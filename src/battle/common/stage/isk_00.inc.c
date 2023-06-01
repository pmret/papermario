#include "battle/battle.h"

#define NAMESPACE A(isk_00)

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
    .texture = "isk_tex",
    .shape = "isk_bt00_shape", //@bug this does not exist!
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
