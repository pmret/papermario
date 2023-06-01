#include "battle/battle.h"
#include "mapfs/trd_bt02_shape.h"

#define NAMESPACE A(trd_02)

#include "battle/common/stage/lib/BeachEffects.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_CALL(EnableModel, MODEL_kabe2_2, FALSE)
    EVT_THREAD
        EVT_SET(LVar0, MODEL_mizu)
        EVT_EXEC(N(EVS_AnimateWave))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_mizu2)
        EVT_EXEC(N(EVS_AnimateWave))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_o298)
        EVT_EXEC(N(EVS_AnimateWave))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_o297)
        EVT_EXEC(N(EVS_AnimateWave))
    EVT_END_THREAD
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
