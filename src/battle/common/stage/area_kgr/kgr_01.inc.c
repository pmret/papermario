#include "battle/battle.h"
#include "mapfs/kgr_bt01_shape.h"

#define NAMESPACE A(kgr_01)

#include "battle/common/stage/lib/WaterEffects.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Thread
        Set(LVar0, MODEL_bin1)
        Exec(N(EVS_AnimateFlotsam))
        Wait(4)
        Set(LVar0, MODEL_bin2)
        Exec(N(EVS_AnimateFlotsam))
        Wait(4)
        Set(LVar0, MODEL_bin3)
        Exec(N(EVS_AnimateFlotsam))
        Wait(4)
        Set(LVar0, MODEL_bin4)
        Exec(N(EVS_AnimateFlotsam))
    EndThread
    Thread
        Set(LVar0, MODEL_hako1)
        Exec(N(EVS_AnimateFlotsam))
        Wait(4)
        Set(LVar0, MODEL_hako2)
        Exec(N(EVS_AnimateFlotsam))
        Wait(4)
        Set(LVar0, MODEL_hako4)
        Exec(N(EVS_AnimateFlotsam))
        Wait(4)
        Set(LVar0, MODEL_hako5)
        Exec(N(EVS_AnimateFlotsam))
        Wait(4)
        Set(LVar0, MODEL_hako6)
        Exec(N(EVS_AnimateFlotsam))
    EndThread
    Set(LVar0, MODEL_fune2)
    Exec(N(EVS_AnimateFlotsam))
    Set(LVar0, MODEL_fune1)
    Exec(N(EVS_AnimateFlotsam))
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
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
