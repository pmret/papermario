#include "battle/battle.h"
#include "mapfs/tik_bt04_shape.h"

#define NAMESPACE A(tik_04)

#include "battle/common/stage/lib/WaterEffects.inc.c"

EvtScript N(EVS_PreBattle) = {
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    Thread
        Set(LVar0, MODEL_mizu2)
        Exec(N(EVS_AnimateWaveModel))
        Wait(5)
        Set(LVar0, MODEL_mizu3)
        Exec(N(EVS_AnimateWaveModel))
        Wait(5)
        Set(LVar0, MODEL_mizu4)
        Exec(N(EVS_AnimateWaveModel))
    EndThread
    Thread
        Wait(5)
        Set(LVar0, MODEL_o357)
        Set(LVar1, 145)
        Exec(N(EVS_AnimateDrifting))
        Set(LVar0, MODEL_o361)
        Set(LVar1, 145)
        Exec(N(EVS_AnimateDrifting))
    EndThread
    Set(LVar0, MODEL_o358)
    Set(LVar1, 60)
    Exec(N(EVS_AnimateDrifting))
    Set(LVar0, MODEL_o360)
    Set(LVar1, 60)
    Exec(N(EVS_AnimateDrifting))
    Return
    End
};

EvtScript N(EVS_PostBattle) = {
    Return
    End
};

Stage NAMESPACE = {
    .texture = "tik_tex",
    .shape = "tik_bt04_shape",
    .hit = "tik_bt04_hit",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
};


