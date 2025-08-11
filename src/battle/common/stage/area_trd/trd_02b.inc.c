#include "battle/battle.h"
#include "mapfs/trd_bt02_shape.h"

#define NAMESPACE A(trd_02b)

#include "battle/common/stage/lib/BeachEffects.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Call(EnableModel, MODEL_saku, false)
    Call(EnableModel, MODEL_kiwa, false)
    Call(EnableModel, MODEL_tyuu, false)
    Thread
        Set(LVar0, MODEL_mizu)
        Exec(N(EVS_AnimateWave))
        Wait(5)
        Set(LVar0, MODEL_mizu2)
        Exec(N(EVS_AnimateWave))
        Wait(5)
        Set(LVar0, MODEL_o298)
        Exec(N(EVS_AnimateWave))
        Wait(5)
        Set(LVar0, MODEL_o297)
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
    .shape = "trd_bt02_shape",
    .hit = "trd_bt02_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
