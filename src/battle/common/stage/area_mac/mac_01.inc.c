#include "battle/battle.h"
#include "mapfs/mac_bt01_shape.h"

#define NAMESPACE A(mac_01)

#include "battle/common/stage/lib/WaterEffects.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Thread
        Set(LVar0, MODEL_nami4)
        Exec(N(EVS_AnimateWaveModel))
        Wait(5)
        Set(LVar0, MODEL_nami3)
        Exec(N(EVS_AnimateWaveModel))
        Wait(5)
        Set(LVar0, MODEL_nami2)
        Exec(N(EVS_AnimateWaveModel))
        Wait(5)
        Set(LVar0, MODEL_nami1)
        Exec(N(EVS_AnimateWaveModel))
    EndThread
    Set(LVar0, MODEL_o391)
    Exec(N(EVS_AnimateFishModel))
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

Stage NAMESPACE = {
    .texture = "mac_tex",
    .shape = "mac_bt01_shape",
    .hit = "mac_bt01_hit",
    .bg = "nok_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};
