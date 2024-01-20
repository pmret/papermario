#include "battle/battle.h"
#include "mapfs/trd_bt05_shape.h"

#define NAMESPACE A(trd_05c)

#include "battle/common/stage/lib/BeachEffects.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Call(EnableModel, MODEL_yuka3, FALSE)
    Call(EnableModel, MODEL_hako, FALSE)
    Call(EnableModel, MODEL_ori, FALSE)
    Call(EnableModel, MODEL_saku1, FALSE)
    Call(EnableModel, MODEL_saku2, FALSE)
    Call(EnableModel, MODEL_mizu4, FALSE)
    Set(LVar0, MODEL_o318)
    Exec(N(EVS_AnimateWave))
    Thread
        Set(LVar0, MODEL_mizu3)
        Exec(N(EVS_AnimateWave))
        Wait(5)
        Set(LVar0, MODEL_mizu2)
        Exec(N(EVS_AnimateWave))
        Wait(5)
        Set(LVar0, MODEL_mizu1)
        Exec(N(EVS_AnimateWave))
    EndThread
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
