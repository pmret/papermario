#include "battle/battle.h"
#include "mapfs/trd_bt05_shape.h"

#define NAMESPACE A(trd_05b)

#include "battle/common/stage/lib/BeachEffects.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(EnableModel, MODEL_kai, FALSE)
    EVT_CALL(EnableModel, MODEL_kusari1, FALSE)
    EVT_CALL(EnableModel, MODEL_mizu1, FALSE)
    EVT_CALL(EnableModel, MODEL_mizu2, FALSE)
    EVT_CALL(EnableModel, MODEL_mizu3, FALSE)
    EVT_CALL(EnableModel, MODEL_ori, FALSE)
    EVT_CALL(EnableModel, MODEL_saku1, FALSE)
    EVT_CALL(EnableModel, MODEL_saku2, FALSE)
    EVT_CALL(EnableModel, MODEL_mizu4, FALSE)
    EVT_CALL(EnableModel, MODEL_o318, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "trd_tex",
    .shape = "trd_bt05_shape",
    .hit = "trd_bt05_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
