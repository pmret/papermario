#include "battle/battle.h"
#include "mapfs/kgr_bt01_shape.h"

#define NAMESPACE A(kgr_01)

#include "battle/common/stage/lib/WaterEffects.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_THREAD
        EVT_SET(LVar0, MODEL_bin1)
        EVT_EXEC(N(EVS_AnimateFlotsam))
        EVT_WAIT(4)
        EVT_SET(LVar0, MODEL_bin2)
        EVT_EXEC(N(EVS_AnimateFlotsam))
        EVT_WAIT(4)
        EVT_SET(LVar0, MODEL_bin3)
        EVT_EXEC(N(EVS_AnimateFlotsam))
        EVT_WAIT(4)
        EVT_SET(LVar0, MODEL_bin4)
        EVT_EXEC(N(EVS_AnimateFlotsam))
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, MODEL_hako1)
        EVT_EXEC(N(EVS_AnimateFlotsam))
        EVT_WAIT(4)
        EVT_SET(LVar0, MODEL_hako2)
        EVT_EXEC(N(EVS_AnimateFlotsam))
        EVT_WAIT(4)
        EVT_SET(LVar0, MODEL_hako4)
        EVT_EXEC(N(EVS_AnimateFlotsam))
        EVT_WAIT(4)
        EVT_SET(LVar0, MODEL_hako5)
        EVT_EXEC(N(EVS_AnimateFlotsam))
        EVT_WAIT(4)
        EVT_SET(LVar0, MODEL_hako6)
        EVT_EXEC(N(EVS_AnimateFlotsam))
    EVT_END_THREAD
    EVT_SET(LVar0, MODEL_fune2)
    EVT_EXEC(N(EVS_AnimateFlotsam))
    EVT_SET(LVar0, MODEL_fune1)
    EVT_EXEC(N(EVS_AnimateFlotsam))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    MODEL_hone,
    MODEL_hako4,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "kgr_tex",
    .shape = "kgr_bt01_shape",
    .hit = "kgr_bt01_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
