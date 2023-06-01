#include "battle/battle.h"
#include "mapfs/trd_bt02_shape.h"

#define NAMESPACE A(trd_02d)

#include "battle/common/stage/lib/BeachEffects.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(EnableModel, MODEL_mizu, FALSE)
    EVT_CALL(EnableModel, MODEL_mizu2, FALSE)
    EVT_CALL(EnableModel, MODEL_o298, FALSE)
    EVT_CALL(EnableModel, MODEL_o297, FALSE)
    EVT_CALL(EnableModel, MODEL_kiwa, FALSE)
    EVT_CALL(EnableModel, MODEL_tyuu, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    MODEL_saku,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "trd_tex",
    .shape = "trd_bt02_shape",
    .hit = "trd_bt02_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
