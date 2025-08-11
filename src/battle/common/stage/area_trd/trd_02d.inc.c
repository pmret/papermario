#include "battle/battle.h"
#include "mapfs/trd_bt02_shape.h"

#define NAMESPACE A(trd_02d)

#include "battle/common/stage/lib/BeachEffects.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Call(EnableModel, MODEL_mizu, false)
    Call(EnableModel, MODEL_mizu2, false)
    Call(EnableModel, MODEL_o298, false)
    Call(EnableModel, MODEL_o297, false)
    Call(EnableModel, MODEL_kiwa, false)
    Call(EnableModel, MODEL_tyuu, false)
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
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
