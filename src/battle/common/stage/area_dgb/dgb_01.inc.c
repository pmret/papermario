#include "battle/battle.h"
#include "mapfs/dgb_bt01_shape.h"

#define NAMESPACE A(dgb_01)

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

Stage NAMESPACE = {
    .texture = "dgb_tex",
    .shape = "dgb_bt01_shape",
    .hit = "dgb_bt01_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
