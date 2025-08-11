#include "battle/battle.h"
#include "mapfs/trd_bt05_shape.h"

#define NAMESPACE A(trd_05b)

#include "battle/common/stage/lib/BeachEffects.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Call(EnableModel, MODEL_kai, false)
    Call(EnableModel, MODEL_kusari1, false)
    Call(EnableModel, MODEL_mizu1, false)
    Call(EnableModel, MODEL_mizu2, false)
    Call(EnableModel, MODEL_mizu3, false)
    Call(EnableModel, MODEL_ori, false)
    Call(EnableModel, MODEL_saku1, false)
    Call(EnableModel, MODEL_saku2, false)
    Call(EnableModel, MODEL_mizu4, false)
    Call(EnableModel, MODEL_o318, false)
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

Stage NAMESPACE = {
    .texture = "trd_tex",
    .shape = "trd_bt05_shape",
    .hit = "trd_bt05_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
